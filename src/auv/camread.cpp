#include "camread.h"
#include "ports.h"
#include <linux/videodev2.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <QDebug>


static int width;
static int height;

static int camfd = 0;
static struct camframe lastframe;
static struct camframe nextframe;
static pthread_t worker = 0;
static pthread_mutex_t framelock;
static pthread_mutex_t camlock;
static int video_already_open = 0; /* TODO: Semaphore? */
volatile int frameready = 0;
char camerapath[50];
struct v4l2_format fmt;

int video_paused;

static int logfd = 0;
//static int vidfd = 0;

/* Really read count bytes from a file descriptor.
   This'll hang if those bytes never show up. */
int tenacious_read(int fd, void* buf, int count) {
    int i = 0;
    int err = 0;
    while (count) {
        err = read(fd, (char*)buf+i, count);
        if (err < 0)
            return err;
        else if (err == 0)
            usleep(10000); /* Wait for some bytes to show up */
        i += err;
        count -= err;
    }
    return i;
}

void * camread_thread(void* in) {
    struct camframe tmp;
    assert(video_already_open); // Started worker without go flag!
    while (video_already_open) {
	//qDebug() << "Doing Camera stuff";
	if(video_paused || !(camfd > 0)) sleep(1);
	else{
		//qDebug() << "Reading from camera";
		pthread_mutex_lock(&camlock);
		/* Read a frame into the next buffer */
		tenacious_read(camfd, nextframe.y, width * height);
		tenacious_read(camfd, nextframe.cb, width * height / 4);
		tenacious_read(camfd, nextframe.cr, width * height / 4);
		pthread_mutex_unlock(&camlock);


		//qDebug() << "Prepping frame for copy";
		/* Lock the buffers and swap */
		//fprintf(stderr, "lock frame...");
		pthread_mutex_lock(&framelock);
		tmp = nextframe;
		nextframe = lastframe;
		lastframe = tmp;
		frameready++;
		//fprintf(stderr, "unlock frame...");
		pthread_mutex_unlock(&framelock);
		//qDebug() << "frame available";
	}
    }
    return 0;
}

int camread_getframe(struct camframe frame, bool record_video) {
    int err;
    /* We can't get a frame if the capture thread isn't running. */
    if(!video_already_open) return -1;
	if(video_paused) return -1;
	//qDebug() << "Waiting for frame...";
    while(!frameready)
        usleep(1000);
    if (frameready) {
	//qDebug() << "Got video frame";
        /* Just lock long enough to copy the frame */
        pthread_mutex_lock(&framelock);
        memcpy(frame.y, lastframe.y, width*height);
        memcpy(frame.cb, lastframe.cb, width*height/4);
        memcpy(frame.cr, lastframe.cr, width*height/4);

        err = frameready;
        frameready = 0;
        pthread_mutex_unlock(&framelock);
        
//	write(vidfd, lastframe.y, width*height);
//	write(vidfd, lastframe.cb, width*height/4);
//	write(vidfd, lastframe.cr, width*height/4);
    	if(record_video) {
			write(logfd, lastframe.y, width*height);
			write(logfd, lastframe.cb, width*height/4);
			write(logfd, lastframe.cr, width*height/4);
    	}
/*  Code to get jpeg from QImage from brain:
        QImage videoFrame = QImage(640,480,QImage::Format_RGB32); // 4 = QImage::Format_RGB32
        // Get full color video
        // copy frame from signal to pixmap
        int x = 639;
        int y = 480;
        unsigned int videoPixel;
        for(int i = 307199; i >= 0; --i){
                y--;
                videoPixel = (0xFF000000) | ((((int)brain_B.RGBVid_R[i]) << 16)&0x00FF0000) | ((((int)brain_B.RGBVid_G[i]) << 8)&0x0000FF00) | (((int)brain_B.RGBVid_B[i])&0x000000FF);
                videoFrame.setPixel(x, y, videoPixel);
                if(y <= 0){
                        x--;
                        y = 480;
                }
        }
	//QImageWriter jpegOut = QImageWriter("vid.jpeg", "jpeg");
	//jpegOut.write(videoFrame);	
	videoFrame.save("vid.jpeg", "jpeg");
*/
        
        /* Return the number of frames captured since the last call.
           NOTE: Only the most recent frame is returned. */
        return err;
    }
    return 0;
}

int camread_waitframe() {
    if(!video_already_open) return 0; /*otherwise we wait forever*/
	if(video_paused) return -1;
    while (!frameready)
        usleep(1000);
    return 0;
}

int camread_open(char const* campath, int w, int h, bool stdformat) {
    assert(sizeof(unsigned char) == 1); /* TODO: Work anyway. */
    if(video_already_open)
	return 0; /* TODO: Concurrent captures */

	strcpy(camerapath, campath);
    
    pthread_attr_t at;
    
    /* Remember frame sizes */
    width = w;
    height = h;
    
    logfd = open("recorded_video.yuv", O_WRONLY | O_APPEND | O_CREAT,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
/*    vidfd = open("video_passthru", O_WRONLY | O_APPEND,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
*/
    /* Set up the V4L2 format structure */
    memset(&fmt, 0, sizeof(struct v4l2_format));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; /* Always capture */
    fmt.fmt.pix.width = width;
    fmt.fmt.pix.height = height;
    if(!stdformat) fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420; /* Always YCbCr 4:2:0 */
    else fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV422P; /* Except when it's YUYV/YUV-4:2:2 */
    //else fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; /* Except when it's YUYV/YUV-4:2:2 */
    
    fmt.fmt.pix.field = V4L2_FIELD_NONE; /* Not interlaced */
    
    pthread_mutex_init(&framelock, NULL);
    
    /* Allocate + blank the buffers */
    lastframe.y = calloc(width * height, sizeof(unsigned char));
    lastframe.cb = calloc(width * height / 4, sizeof(unsigned char));
    lastframe.cr = calloc(width * height / 4, sizeof(unsigned char));
    nextframe.y = calloc(width * height, sizeof(unsigned char));
    nextframe.cb = calloc(width * height / 4, sizeof(unsigned char));
    nextframe.cr = calloc(width * height / 4, sizeof(unsigned char));
    
    pthread_attr_init(&at); /* Defaults? Sure. */
    
    /* Open the camera */
    fprintf(stderr, "Opening video device...");
    camfd = open(campath, O_RDONLY);
    if(!(camfd > 0)) return 0;
    fprintf(stderr, "done\n");
    /* Set the image format */
    fprintf(stderr, "Setting image format...");
    if(!(ioctl(camfd, VIDIOC_S_FMT, &fmt) >= 0)) return 0;
    fprintf(stderr, "done\n");
    
    /* We're running */
    video_already_open = 1;
	video_paused = 0;
    
    /* Create the thread */
    //fprintf(stderr, "Create thread...");
    pthread_create(&worker, &at, &camread_thread, 0);
    
    /* Dump the first two frames so my buffer fills */
    //fprintf(stderr, "Dump garbage...");
    while (frameready<2) ;
    pthread_mutex_lock(&framelock);
    frameready = 0;
    pthread_mutex_unlock(&framelock);
    while(!frameready) ;
    
    /* TODO: This is uninformative. */
    return 1;
}

int camread_close() {
    int err = 0;
    if(!video_already_open) return 0; /* Can't close an already closed capture */
    
    /* We're done, tell the worker to stop */
    video_already_open = 0;
    frameready = 0;
    err = pthread_join(worker, NULL); /* Wait for the worker to stop */
    /* Clean up */
    close(camfd);
    close(logfd);
    pthread_mutex_destroy(&framelock);
    free(lastframe.y);
    free(lastframe.cb);
    free(lastframe.cr);
    free(nextframe.y);
    free(nextframe.cb);
    free(nextframe.cr);
    
    return err;
}

void SwappyCopy(unsigned char* target, unsigned char* src, int w, int h) {
    int i, j;
    for (i = 0; i < w; ++i)
        for (j = 0; j < h; ++j)
            *(target+h*i+j) = *(src+w*j+i);
}

/* Returns 1 if white-balace successful, 0 otherwise */
/*
int white_balance(){
	struct v4l2_queryctrl queryctrl;
	struct v4l2_control control;

	memset (&queryctrl, 0, sizeof (queryctrl));
	queryctrl.id = V4L2_CID_DO_WHITE_BALANCE;

	if (-1 == ioctl (camfd, VIDIOC_QUERYCTRL, &queryctrl)) {
		printf ("V4L2_CID_DO_WHITE_BALANCE is not supported\n");
		return 0;
	} else if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED) {
		printf ("V4L2_CID_DO_WHITE_BALANCE is not supported\n");
		return 0;
	} else {
		memset (&control, 0, sizeof (control));
		control.id = V4L2_CID_DO_WHITE_BALANCE;
		control.value = 1;

		if (-1 == ioctl (camfd, VIDIOC_S_CTRL, &control)) {
			return 0;
		}
	}
	return 1;
}
*/

int camread_pause() {
    int err = 0;
    if(!video_already_open) return 0; /* Can't close an already closed capture */
    video_paused = 1;
	pthread_mutex_lock(&camlock);
    
    /* We're waiting, tell the worker to stop */
    frameready = 0;
    /* Release camera */
    return close(camfd) == 0;
}

int camread_unpause() {
	if(!video_already_open) return -1; /* Can't unpause a closed capture */
	camfd = open(camerapath, O_RDONLY);
	if(!(camfd > 0)) return -2;
	if(!(ioctl(camfd, VIDIOC_S_FMT, &fmt) >= 0)) return -3;
	pthread_mutex_unlock(&camlock);
	video_paused = 0;
	/* Dump the first two frames so my buffer fills */
	//fprintf(stderr, "Dump garbage...");
/*
	while (frameready<2) ;
	pthread_mutex_lock(&framelock);
	frameready = 0;
	pthread_mutex_unlock(&framelock);
	while(!frameready) ;
*/
	return 1;
}

int camread_switchcam(char const* campath){
	camread_pause();
	strcpy(camerapath, campath);
	return camread_unpause();
}

// decodes a YUYV frame into matlab and QImage formats
int camread_decode_YUYV_frame(char* input, rgbframe* matlabOut, QImage* out){

	// format is YUYV or YUV4:2:2 or YCbYCr

	w = width*2;
	h = height;

	int i, j;
	int rgbPixel1, rgbPixel2;
	for (i = 0; i < h; ++i){
		for (j = 0; j < w; j+=4){
			x = j/2;
			y = i;
			char Y1 = input[i*w+j];
			char U = input[i*w+j+1];
			char Y2 = input[i*w+j+2];
			char V = input[i*w+j+3];
			
			char B1 = 1.164(Y1 - 16) + 2.018(U - 128)
			char G1 = 1.164(Y1 - 16) - 0.813(V - 128) - 0.391(U - 128)
			char R1 = 1.164(Y1 - 16) + 1.596(V - 128)
			char B2 = 1.164(Y2 - 16) + 2.018(U - 128)
			char G2 = 1.164(Y2 - 16) - 0.813(V - 128) - 0.391(U - 128)
			char R2 = 1.164(Y2 - 16) + 1.596(V - 128)

			matlabOut.R[x*h+y] = R1;
			matlabOut.R[x*(h+1)+y] = R2;
			matlabOut.G[x*h+y] = G1;
			matlabOut.G[x*(h+1)+y] = G2;
			matlabOut.B[x*h+y] = B1;
			matlabOut.B[x*(h+1)+y] = B2;

			rgbPixel1 = (0xFF000000) | ((((int)R1) << 16)&0x00FF0000) | ((((int)G1) << 8)&0x0000FF00) | (((int)B1)&0x000000FF);
			rgbPixel2 = (0xFF000000) | ((((int)R2) << 16)&0x00FF0000) | ((((int)G2) << 8)&0x0000FF00) | (((int)B2)&0x000000FF);
			out->setPixel(x, y, rgbPixel1);
			out->setPixel(x+1, y, rgbPixel2);
		}
	}
	return 1;
}
