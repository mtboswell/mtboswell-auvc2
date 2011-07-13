
#ifndef SAL_CPP_
#define SAL_CPP_

#include "cameraSAL.h"

/**
The SAL (Software Abstraction Layer) is a module.  It is created and launched by the ModuleHub in main.cpp.
Basically it creates all the devices in init() and then waits for them to emit DataReady(VDatum) signals, which means
that they have input that the SAL needs to put in the stateData.  This is the middle man.
**/
CameraSAL::CameraSAL():Module()
{
	cameraCreated = false;
	//All of this should be commented out.  Drivers for the various devices that run for the SAL must be created in the
	//init() function below or the SIGNALS they emit are not handled in this thread (the SALS thread) but in the main thread
	//instead.  This makes these signals being processed interfere with things that are supposed to be being processed in the main
	//thread, such as the GUI.
	
	
	//os5000 = new OS5000("");			//takes in serial port name as a string
	//microstrain = new Microstrain("/dev/ttyS0");	//takes in dev


	//QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	//QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));


}

//This function is implemented on a timer that is created in the Module parent class.
//It doesn't really need to do anything right now but it updates the compass values so the
//robot thinks its spinning in circles.
void CameraSAL::step()
{
	//	setData(string id, driver->getData());
}

//This function creates all the devices that gather input robotron3000 (aka mako)
//This function is implicitly called after the constructor (by its QThread grandparent)
//and at the end of this function app.exec() is called (implicitly. Or it may acutally not
//be called in this function but for all intensive purposes its called after this.) 
//which is what makes this just start listening for all the signals.
void CameraSAL::init(){
	qDebug() << "Starting CameraSAL";
	setData("Module.CameraSAL", 1);
	//camera->start();
	qDebug("CameraSAL thread id: %d", (int) QThread::currentThreadId());
	if(boolValue("Simulate")){
		//Uses the last images from the camera and sets them to state data
		QImage* forwardImage = new QImage("2.bmp");
		QImage* downwardImage = new QImage("3.bmp");
		QTransform transform;
		transform.rotate(270);
		*forwardImage = forwardImage->transformed(transform);
		QImage* forward2Image = new QImage(120, 160, QImage::Format_RGB32);
		*forward2Image = forwardImage->scaledToHeight(160);
		QImage* downward2Image = new QImage(160, 120, QImage::Format_RGB32);
		*downward2Image = downwardImage->scaledToHeight(120);
		
		VDatum datum;
		datum.id = "Camera.Forward.Frame";
		datum.value = *forward2Image;
		datum.timestamp = QTime::currentTime();
		setData(datum);

		VDatum datum2;
		datum2.id = "Camera.Downward.Frame";
		datum2.value = *downward2Image;
		datum2.timestamp = QTime::currentTime();
		setData(datum2);
	}
	else {
		//initiate forward camera
		//forwardParams is a CameraParams struct (defined in camera.h) and btw if you don't know what a struct
		//is you should probably go google it.  The struct is filled with the parameters defined in .auvrc file.
		forwardParams = new CameraParams;
		forwardParams->x = config("Camera.Forward.x").toInt();
		forwardParams->y = config("Camera.Forward.y").toInt();
		forwardParams->fps = config("Camera.Forward.fps").toInt();
		forwardParams->pixelclock = config("Camera.Forward.pixelclock").toInt();
		forwardParams->identity = config("Camera.Forward.identity").toInt();
		forwardParams->serial = config("Camera.Forward.serial");
		forwardParams->port = config("Camera.Forward.port").toInt();
		forwardParams->address = config("Camera.Forward.address");
		forwardParams->quality = config("Camera.Forward.quality").toInt();
		forwardParams->debug = debug;
		
		//here the camera is created and passed the paramaters and is connected up
		forwardCamera = new Camera(forwardParams, this);
		QObject::connect(forwardCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
		
		//now we do the same for camera number 2!
		//initiate downward camera
		downParams = new CameraParams;
		downParams->x = config("Camera.Down.x").toInt();
		downParams->y = config("Camera.Down.y").toInt();
		downParams->fps = config("Camera.Down.fps").toInt();
		downParams->pixelclock = config("Camera.Down.pixelclock").toInt();
		downParams->identity = config("Camera.Down.identity").toInt();
		downParams->serial = config("Camera.Down.serial");
		downParams->port = config("Camera.Down.port").toInt();
		downParams->address = config("Camera.Down.address");
		downParams->quality = config("Camera.Down.quality").toInt();
		downParams->debug = debug;
	
		downCamera = new Camera(downParams, this);
		QObject::connect(downCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
		cameraCreated = true;
		qDebug() << "LOOK HERE THE CAMERA INIT FUNCTION FINISHED!";
	}
}

void CameraSAL::dataIn(VDatum datum) {
	qDebug() << "CameraSAL DataIn() Called";
	qDebug() << datum.id << " " << cameraCreated;
	if (datum.id == "Parameter.Vision.ModeSelect" && cameraCreated) {
		qDebug() << "Camera Mode set to " << datum.value.toInt();
		switch (datum.value.toInt()) {
			case 0: downCamera->toggleCamera(true);  forwardCamera->toggleCamera(true); break;
			case 1: downCamera->toggleCamera(false); forwardCamera->toggleCamera(true); break;
			case 2: downCamera->toggleCamera(true);  forwardCamera->toggleCamera(false);  break;
			case 3: downCamera->toggleCamera(false); forwardCamera->toggleCamera(true); break;
			case 4: downCamera->toggleCamera(false); forwardCamera->toggleCamera(false); break;
			default: break;
		}
	}
	if(datum.id == "Camera.Front.Pixelclock" && cameraCreated) {
		qDebug() << "This far";
		forwardCamera->updateClock(datum.value.toInt());
	}
	if( datum.id == "Camera.Down.Pixelclock" && cameraCreated) { 
		downCamera->updateClock(datum.value.toInt());
	}
	qDebug() << "Finished DataIn()";
}



#endif
