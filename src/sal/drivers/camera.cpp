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
 
 
 * I intended to get back to this and make it fully robust
 * as soon as the Maestro is up and running
 */

Camera(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0):Module(configIn, stateIn, parent)
{
	
	fps = framesPerSecond;
	byteStorage = (char*) malloc(752 * 480 * 32);
	
	// stepTimer is used to poll stateData for changes in camera settings (unimplemented)
	stepTimer->setInterval(3000)
	
	
	// The camera thread is not launched here.
	// It is launched in the main thread with all the other modules
	
}

// Initializes the camera and creates an event loop to handle events.
void ::run()
{
	
	qDebug("Camera thread id: %d", (int) QThread::currentThreadId());
	//Camera init
	m_nSizeX = 752;
	m_nSizeY = 480;
	m_nBitsPerPixel = 32;
	//m_hCam = 0 -> tells driver to use first avaliable camera
	m_hCam = 0;
	INT nRet = is_InitCamera(&m_hCam, NULL);
	if (nRet != IS_SUCCESS)
	{
		qDebug() << "Failed to initialize camera";
	}
	else
	{
		//When the camera is properly initialized, this block 
		qDebug() << "Camera initialized";
		
		//Set the color mode (see uEye Manual)
		//is_SetColorMode(m_hCam, IS_CM_RGBA8_PACKED);
		is_SetColorMode(m_hCam, IS_SET_CM_RGB32);
		
		//allocate memory for a single image and activate that memory
		is_AllocImageMem(m_hCam, m_nSizeX, m_nSizeY, m_nBitsPerPixel, &m_pcImageMemory, &m_lMemoryID);
		is_SetImageMem (m_hCam, m_pcImageMemory, m_lMemoryID);
		
		
		
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
		// Linux
		
		is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
		
		// start a timer to capture camera frames
		QTimer *frameTimer = new QTimer(this);
		connect(frameTimer, SIGNAL(timeout()), this, SLOT(captureImage()));
		frameTimer->start(1000 / fps);
		
		this->exec();
		qDebug() << "uEye camera thread terminating";
		
	}
	
}

// getImage() captures a single frame from the camera and saves it to
// hard disk under image.bmp (currently). Then loads it to a QImage.
void UEyeDriver::captureImage()
{

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
			qimage = new QImage("image.bmp");
			if (qimage->isNull()) {
				qDebug() << "image failed to load";
			}
			qpixmap = QPixmap::fromImage(*qimage);
			emit qPixmapReady(qpixmap);
			emit qImageReady(*qimage);
			qimage->~QImage();

		}
	}
}
