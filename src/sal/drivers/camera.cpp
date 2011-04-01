#include "camera.h"
#include <QDebug>
#include <QString>
#include <QTime>

/*
 * What works:
 * 	-Camera initialization
 * 	-slot caputreFrame captures a frame
 * 
 * To do:
 * 	-fix hardcoded framerate and other settings
 * 	-polling of above settings from stateData
 * 	-set stateData with new frames (semi-implemented, untestested)
 *  -testing for 2 similtanious cameras needs to be done
 * 	-some other small things I can't think of
 */

Camera::Camera(QObject* parent)
{
	
	//fps = framesPerSecond;
	byteStorage = (char*) malloc(752 * 480 * 32);
	
	//initialization for QudpSocket and QImageWriter
	videoSocket = new QUdpSocket();
	videoSocket->connectToHost(QHostAddress::LocalHost,5566);
	qDebug() << videoSocket->state() << " o " << videoSocket->error();
	videoOut = new QImageWriter(videoSocket, "jpeg");
	videoOut->setQuality(70);
	
	// stepTimer is used to poll stateData for changes in camera settings (unimplemented)
	//stepTimer->setInterval(3000)
	init();
	
}

// getImage() captures a single frame from the camera and saves it to
// hard disk under image.bmp (currently). Then loads it to a QImage.
void Camera::step()
{
	qDebug() << "capturing frame";
	if( is_FreezeVideo( m_hCam, IS_WAIT ) != IS_SUCCESS )
	{	
		qDebug() << "ERROR: is_FreezeVideo(...) in function UEyeDriver::getImage()";
	}
	else {
		if( is_SaveImage(m_hCam, "image.bmp") != IS_SUCCESS)
		{
			qDebug() << "ERROR: is_SaveImage(...) in fucntion UEyeDriver::getImage()";
		}
		else 
		{
			qDebug("Image Captured in thread %d", (int) QThread::currentThreadId());
			
			
			
			//loads the image from the disk TODO: replace this with direct loading from DIB
			//if (!image.loadFromData(byteStorage, 752*480*32, 0))
			//	{
			//		qDebug() << "Image failed to load";
			//	}
				
			// Let the system know a new frame is ready and emit it with
			// the signal as a QImage
		}
		if ( is_CopyImageMem(m_hCam, m_pcImageMemory, m_lMemoryID, byteStorage) != IS_SUCCESS) {
			qDebug() << "ERROR: is_CopyImageMem in function UEyeDriver::getImage()";
		}
		else {
			imageArray = QByteArray(byteStorage);
			qimage = new QImage("image.bmp");	//dynamic pointer to the qimage
			if (qimage->isNull()) {
				qDebug() << "image failed to load";
			}
			qpixmap = QPixmap::fromImage(*qimage);	//qpixmap data to be sent to dash
			//emit qPixmapReady(qpixmap);
			//emit qImageReady(*qimage);  //old way. now we create a VDatum and send it along
			//VDatum datum; out for testing
			//datum.id = "Image"; out for testing
			//datum.value = *qimage; out for testing
			
			//write out to the UDP port
			videoOut->write(*qimage);
			//emit dataReady(datum); out for testing
			qimage->~QImage();

		}
	}
}

// Initializes the camera and creates an event loop to handle events.
void Camera::init()
{
	
	qDebug("Camera thread id: %d", (int) QThread::currentThreadId());
	
	// Set the size of the image in pixels
	// TODO: make configurable in the config file instead of hardcoded
	m_nSizeX = 752;
	m_nSizeY = 480;
	m_nBitsPerPixel = 32;
	//m_hCam = 0 -> tells driver to use first avaliable camera
	m_hCam = 0;
	
	//connect and activate the camera
	INT nRet = is_InitCamera(&m_hCam, NULL);
	if (nRet != IS_SUCCESS)
	{
		qDebug() << "Failed to initialize camera";
	}
	else  //This step in initalization only happens on a succesful connection
	{
		
		qDebug() << "Camera initialized";
		
		//Set the color mode (see uEye Manual)
		//is_SetColorMode(m_hCam, IS_CM_RGBA8_PACKED);
		is_SetColorMode(m_hCam, IS_SET_CM_RGB32);
		
		//allocate memory for a single image and activate that memory
		is_AllocImageMem(m_hCam, m_nSizeX, m_nSizeY, m_nBitsPerPixel, &m_pcImageMemory, &m_lMemoryID);
		is_SetImageMem (m_hCam, m_pcImageMemory, m_lMemoryID);
		is_SetPixelClock(m_hCam, 10);
		
		
		
		// This code was to test the original settings for the position,
		// height and width: the AOI defaults
		// The default position was (0,0) width = 752, height = 480
		// The function is_SetAOI() is a replacement of is_SetImageSize
		//localx = 3;
		//localy = 3;
		//localx2 = 3;
		//localy2 = 3;
		//is_SetAOI(m_hCam, IS_GET_IMAGE_AOI, &localx, &localy, &localx2, &localy2);
		//qDebug() << "SetAOI Output: ";
		//qDebug() << localx;
		//qDebug() << localy;
		//qDebug() << localx2;
		//qDebug() << localy2;
		
		
		
		// This function sets the display mode to save images to memory
		// Direct Display Mode (the alternative is not supported in
		// Linux)
		
		is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
	}
	
}

