/* Header file for camera input glue by Ben Guzzardi <bguzz@vt.edu> for  *
 * the Virginia Tech Autonomous Underwater Vehicle Team                  *
 *************************************************************************/

#ifndef __CAMREAD_H
#define __CAMREAD_H

/* Basic flow: 
   1) call camread_open() with the path to the video device and desired
      frame dimensions. w and h should both be even.
   2) Once camread_open() returns, you should create a camframe struct and
      allocate your Y, Cb, and Cr planes (we request YCbCr 4:2:0 from the
      camera, so Y should be WxH and Cb and Cr should both be W/2xH/2 bytes.
   3) You can then call camread_getframe() to get a copy of the most recent
      frame from the camera.
   4) Call camread_close() to stop the capture thread and release resources.
*/

struct camframe {
    void *y, *cb, *cr;
};

//* Example: camread_open("/dev/video0", 640, 480); */
int camread_open(char const* campath, int w, int h);

/* Copies most recent frame grabbed from the camera into your buffers, if it's
   new. If there hasn't been a frame grabbed since the last call, this returns
   zero and does nothing.
   
   Example: camread_getframe(myframe);
   
   Returns the number of frames read by the camera since the last call
   to camread_getframe. In other words, it's the number of dropped frames
   plus one. If it returns zero, there was no new frame since the last call
   and so frame is unchanged. */
int camread_getframe(struct camframe frame);

/* Performs a manual white balance, and disables auto white-balancing.
   Returns 1 if successful, 0 if command fails. */
int white_balance();

/* No arguments, blocks until a frame is available */
int camread_waitframe();

/* No arguments, stops capture, joins the worker thread, and frees buffers. */
int camread_close();

/* Copy an unsigned char array, swapping rows and columns */
void SwappyCopy(unsigned char* target, unsigned char* src, int w, int h);


#endif /* #ifndef __CAMREAD_H */

