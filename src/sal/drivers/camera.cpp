#include "camera.h"
#include <QDebug>
#include <QString>
#include <QTime>

/**
*  Camera drivers
*  author: Mike Valeiras
*  
*  Camera driver the constuctors takes a CameraParams struct to tell the camera all the stuff you
*  can alter in the .auvrc file (search for that file).  And the parent which should be the SAL.
*  The SAL as the parent means that any slots that get called (Camera::step mainly).  The constuctor
*  sets everything up.  Look at the comments in the code for more details.
*
*  A lot of the function calls here are part of the uEye camera drivers.  Basically any function that
*  starts with "is_".  I provided a basic explination of most of the functions but to learn more I would
*  reccomend reading the uEye documentation.  It can be found online at the ids website. (I think.
*  Otherwise I would download the drivers, install them and then look in the readme to find the local
*  copy of the documentation.)
*
**/
Camera::Camera(CameraParams* paramsIn, QObject* parent)
{
	
	params = paramsIn;
	//An array of bytes to store the image.  Size is determined by picture x * y and 32 bits per pixel
	byteStorage = (char*) malloc((params->x) * (params->y) * 32);
	debug = params->debug;
	
	//Create a qudpsocket videosocket.  Images are sent out over this socket by the QImageWriter to 
	//be read by the dashboard on another computer (if params.address is that computers ip) or localhost
	videoSocket = new QUdpSocket();
	videoSocket->connectToHost(QHostAddress(params->address), params->port);
	videoOut = new QImageWriter(videoSocket, "jpeg");
	videoOut->setQuality(params->quality);
	
	//This is the extention of the image file that is saved on the hard drive so you can always access the last
	//taken image by the camera on the last exection.  A juvinille way to write a string I know but what the hell.
	saveName[1] = '.';
	saveName[2] = 'b';
	saveName[3] = 'm';
	saveName[4] = 'p';
	saveName[5] = '\0';
	
	//this writes the first part of the string so that the 2 different cameras use two different images.
	if (params->identity == 2) {
		saveName[0] = '2';
	}
	else {
		saveName[0] = '3';
	}
	
	
	// The init function down there actually turns on the camera.  If the camera is turned on correctly then it
	// returns true and the timer is started.  The timer is set to go off at a rate based on the fps in the params
	// struct.  The connect makes it so each time the timer expires it emits the timeout signal and the step function
	// is called.
	if (init()) {
		//start the timer to capture frames
		timer = new QTimer(this);
		timer->start(1000/(params->fps));
		QObject::connect(timer, SIGNAL(timeout()), this, SLOT(step()));
	}
	
}

// This function captures a single frame of the camera.  It writes the image to the udp socket from the constructor which
// sends it to the dashboard and emits a dataReady signal which the SAL is connected too.  When the SAL picks up the signal
// it updates StateData with the latest camera image.
void Camera::step()
{
	if(debug) qDebug() << "capturing frame";
	//this function captures the frame and stores it onto the active memory created in init()
	if( is_FreezeVideo( m_hCam, IS_WAIT ) != IS_SUCCESS )
	{	
		qDebug() << "ERROR: is_FreezeVideo on camera" << params->identity;
	}
	else {
		// This image saves the image to the harddrive under the name *.bmp
		if( is_SaveImage(m_hCam, saveName) != IS_SUCCESS)
		{
			qDebug() << "ERROR: is_SaveImage(...) in fucntion UEyeDriver::getImage()";
		}
		else 
		{
			//if we have gotten this far now we make the QImage.
			if(debug) qDebug("Image Captured in with camID %d", params->identity);
			
		}
		// moves the image from the active camera memory to the array made in the constructor.
		// this actually may not be neccessay anymore but I'm leaving it in for now just so
		// I dont have to fuck with it and because I am going to try to use it later for more
		// efficient cameras.
		if ( is_CopyImageMem(m_hCam, m_pcImageMemory, m_lMemoryID, byteStorage) != IS_SUCCESS) {
			qDebug() << "ERROR: is_CopyImageMem in function UEyeDriver::getImage()";
		}
		else {
			//also possibly not neccessary
			imageArray = QByteArray(byteStorage);
			//creates a QImage by reading the image saved on the hard drive. I am super not proud
			//of this one but I was having a shit ton of problems doing it properly so I hacked this
			//method together out of frustration and it works fine.  May change in the future (hopefully) 
			qimage = new QImage(saveName);
			//check to see if image loaded
			if (qimage->isNull()) {
				qDebug() << "image failed to load";
			}
			
			//this creates a VDatum (a struct defined somewhere just search for it.  Its what things are stored
			//as in stateData). The VDatum is emitted with the DataReady signal which the SAL hears and updates stateData.
			//So basically this part down here is just filling a VDatum struct with all the info it needs.
			VDatum datum;
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

// Initializes the camera so it can take stills.  Most of this I took from example code provided 
// by the uEye people so see their fairly awesome implementation if you want to learn more.
bool Camera::init()
{
		
	// Set the size of the image in pixels
	m_nSizeX = params->x;
	m_nSizeY = params->y;
	
	m_nBitsPerPixel = 32;
	//m_hCam = 0; //-> tells driver to use first avaliable camera
	//m_hCam = 2 or 3 use the camera with that ID
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
		is_SetImageMem(m_hCam, m_pcImageMemory, m_lMemoryID);
		//the pixelclock is realated to some complex usb transfer rate thing. Basically if it is too high
		//(which it is by default) then the camera fails to take every picture in the is_FreezeFrame method.
		is_SetPixelClock(m_hCam, params->pixelclock);
		
		// This function sets the display mode to save images to memory
		// Direct Display Mode (the alternative is not supported in
		// Linux)
		is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
		return true;
	}
	
}

