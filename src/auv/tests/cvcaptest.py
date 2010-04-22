# Open the camera and a window, then capture+display frames
# until killed with Ctrl+C

import opencv
import opencv.highgui

opencv.highgui.cvStartWindowThread()
opencv.highgui.cvNamedWindow("win")

cap = opencv.highgui.cvCreateCameraCapture(0)
opencv.highgui.cvSetCaptureProperty(cap, opencv.highgui.CV_CAP_PROP_FRAME_WIDTH, 640)
opencv.highgui.cvSetCaptureProperty(cap, opencv.highgui.CV_CAP_PROP_FRAME_HEIGHT, 480)

while 1:
    success = opencv.highgui.cvGrabFrame(cap)
    if success:
        img = opencv.highgui.cvRetrieveFrame(cap)
        opencv.highgui.cvShowImage("win",img)

