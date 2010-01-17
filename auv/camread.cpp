#include "camread.h"
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

#define CAMREAD_LOG_STREAM 1

static int width;
static int height;

static int camfd = 0;
static struct camframe lastframe;
static struct camframe nextframe;
static pthread_t worker = 0;
static pthread_mutex_t framelock;
static int video_already_open = 0; /* TODO: Semaphore? */
volatile int frameready = 0;

#ifdef CAMREAD_LOG_STREAM
static int logfd = 0;
#endif

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
        /* Read a frame into the next buffer */
        tenacious_read(camfd, nextframe.y, width * height);
        tenacious_read(camfd, nextframe.cb, width * height / 4);
        tenacious_read(camfd, nextframe.cr, width * height / 4);
        
        /* Lock the buffers and swap */
        //fprintf(stderr, "lock frame...");
        pthread_mutex_lock(&framelock);
        tmp = nextframe;
        nextframe = lastframe;
        lastframe = tmp;
        frameready++;
        //fprintf(stderr, "unlock frame...");
        pthread_mutex_unlock(&framelock);
    }
    return 0;
}

int camread_getframe(struct camframe frame) {
    int err;
    /* We can't get a frame if the capture thread isn't running. */
    assert(video_already_open);
    while(!frameready)
        usleep(1000);
    if (frameready) {
        /* Just lock long enough to copy the frame */
        pthread_mutex_lock(&framelock);
        memcpy(frame.y, lastframe.y, width*height);
        memcpy(frame.cb, lastframe.cb, width*height/4);
        memcpy(frame.cr, lastframe.cr, width*height/4);
#ifdef CAMREAD_LOG_STREAM
	write(logfd, lastframe.y, width*height);
	write(logfd, lastframe.cb, width*height/4);
	write(logfd, lastframe.cr, width*height/4);
#endif
        err = frameready;
        frameready = 0;
        pthread_mutex_unlock(&framelock);
        
        /* Return the number of frames captured since the last call.
           NOTE: Only the most recent frame is returned. */
        return err;
    }
    return 0;
}

int camread_waitframe() {
    assert(video_already_open); /*otherwise we wait forever*/
    while (!frameready)
        usleep(1000);
    return 0;
}

int camread_open(char const* campath, int w, int h) {
    assert(sizeof(unsigned char) == 1); /* TODO: Work anyway. */
    assert(!video_already_open); /* TODO: Concurrent captures */
    
    pthread_attr_t at;
    struct v4l2_format fmt;
    
    /* Remember frame sizes */
    width = w;
    height = h;
    
#ifdef CAMREAD_LOG_STREAM
    logfd = open("camread_log.yuv", O_WRONLY | O_APPEND | O_CREAT,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#endif

    /* Set up the V4L2 format structure */
    memset(&fmt, 0, sizeof(struct v4l2_format));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; /* Always capture */
    fmt.fmt.pix.width = width;
    fmt.fmt.pix.height = height;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420; /* Always YCbCr 4:2:0 */
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
    //fprintf(stderr, "Opening video device...");
    camfd = open(campath, O_RDONLY, 0);
    assert(camfd > 0);
    //fprintf(stderr, "done\n");
    /* Set the image format */
    //fprintf(stderr, "Setting image format...");
    assert(ioctl(camfd, VIDIOC_S_FMT, &fmt) >= 0);
    //fprintf(stderr, "done\n");
    
    /* We're running */
    video_already_open = 1;
    
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
    return 0;
}

int camread_close() {
    int err = 0;
    assert(video_already_open); /* Can't close an already closed capture */
    
    /* We're done, tell the worker to stop */
    video_already_open = 0;
    frameready = 0;
    err = pthread_join(worker, NULL); /* Wait for the worker to stop */
    /* Clean up */
    close(camfd);
#ifdef CAMERA_LOG_STREAM
    close(logfd);
#endif
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

