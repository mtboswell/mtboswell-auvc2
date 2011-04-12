#include "camera.h"
#include <QDebug>
#include <QString>
#include <QTime>

Camera::Camera(CameraParams* paramsIn, QObject* parent)
{
	
	params = paramsIn;
	
	//fps = framesPerSecond;
	byteStorage = (char*) malloc((params->x) * (params->y) * 32);
	
	//initialization for QudpSocket and QImageWriter
	videoSocket = new QUdpSocket();
	videoSocket->connectToHost(QHostAddress::LocalHost, params->port);
	videoOut = new QImageWriter(videoSocket, "jpeg");
	videoOut->setQuality(70);
	
	saveName[1] = '.';
	saveName[2] = 'b';
	saveName[3] = 'm';
	saveName[4] = 'p';
	saveName[5] = '\0';
	
	if (params->identity == 2) {
		saveName[0] = '2';
	}
	else {
		saveName[0] = '3';
	}
	
	
	// stepTimer is used to poll stateData for changes in camera settings (unimplemented)
	//stepTimer->setInterval(3000)
	if (init()) {
		//start the timer to capture frames
		timer = new QTimer(this);
		timer->start(1000/(params->fps));
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(step()));
	}
	
}

// getImage() captures a single frame from the camera and saves it to
// hard disk under image.bmp (currently). Then loads it to a QImage.
void Camera::step()
{
	qDebug() << "capturing frame";
	if( is_FreezeVideo( m_hCam, IS_WAIT ) != IS_SUCCESS )
	{	
		qDebug() << "ERROR: is_FreezeVideo on camera" << params->identity;
	}
	else {
		if( is_SaveImage(m_hCam, saveName) != IS_SUCCESS)
		{
			qDebug() << "ERROR: is_SaveImage(...) in fucntion UEyeDriver::getImage()";
		}
		else 
		{
			qDebug("Image Captured in with camID %d", params->identity);
			
			
			
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
			if (params->identity == 0) {
				qimage = new QImage(saveName);
			}
				//dynamic pointer to the qimage
			if (qimage->isNull()) {
				qDebug() << "image failed to load";
			}
			//qpixmap = QPixmap::fromImage(*qimage);	//qpixmap data to be sent to dash
			//emit qPixmapReady(qpixmap);
			//emit qImageReady(*qimage);  //old way. now we create a VDatum and send it along
			VDatum datum; //out for testing
			if (params->identity == 2) {
				datum.id = "Camera.Forward.Frame";
			}
			else {
				datum.id = "Camera.Downward.Frame";
			}
			datum.value = *qimage;
			datum.timestamp = QTime::currentTime();
			
			emit dataReady(datum);

			//write out to the UDP port
			videoOut->write(*qimage);
			qimage->~QImage();

		}
	}
}

// Initializes the camera and creates an event loop to handle events.
bool Camera::init()
{
		
	// Set the size of the image in pixels
	// TODO: make configurable in the config file instead of hardcoded
	m_nSizeX = params->x;
	m_nSizeY = params->y;
	m_nBitsPerPixel = 32;
	//m_hCam = 0; //-> tells driver to use first avaliable camera
	m_hCam = params->identity;
	
	//connect and activate the camera
	INT nRet = is_InitCamera(&m_hCam, NULL);
	if (nRet != IS_SUCCESS)
	{
		qDebug() << "Failed to initialize camera";
		return false;
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
		is_SetPixelClock(m_hCam, params->pixelclock);
		
		
		
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
		return true;
	}
	
}

