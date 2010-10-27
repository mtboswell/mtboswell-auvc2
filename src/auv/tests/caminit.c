#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "ports.h"
#include "calibration.h"
#include "caminit.h"

int caminit() {
    int cam;
    struct v4l2_format fmt;

    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = CAMERA_FRAME_WIDTH;
    fmt.fmt.pix.height = CAMERA_FRAME_HEIGHT;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV420;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;

    cam = open(CAMERAPORT, O_RDWR);

    if(!cam) {
        fprintf(stderr,"caminit.h: Unable to open camera!\n");
        return -1;
    }
    if (ioctl(cam,VIDIOC_S_FMT,&fmt) < 0) {
        fprintf(stderr,"caminit.h: ioctl to set frame size failed!\n");
        close(cam);
        return -1;
    }

    close(cam);
    
    return 0;
}
