
#ifndef SAL_CPP_
#define SAL_CPP_

#include "sal.h"

/**
The SAL (Software Abstraction Layer) is a module.  It is created and launched by the ModuleHub in main.cpp.
Basically it creates all the devices in init() and then waits for them to emit DataReady(VDatum) signals, which means
that they have input that the SAL needs to put in the stateData.  This is the middle man.
**/
SAL::SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):Module(configIn, stateIn, parent)
{
	
	//All of this should be commented out.  Drivers for the various devices that run for the SAL must be created in the
	//init() function below or the SIGNALS they emit are not handled in this thread (the SALS thread) but in the main thread
	//instead.  This makes these signals being processed interfere with things that are supposed to be being processed in the main
	//thread, such as the GUI.
	
	
	//config = configIn;
	//os5000 = new OS5000("");			//takes in serial port name as a string
	//microstrain = new Microstrain("/dev/ttyS0");	//takes in dev


	//QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	//QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));


}

//This function is implemented on a timer that is created in the Module parent class.
//It doesn't really need to do anything right now but it updates the compass values so the
//robot things its spinning in circles.
void SAL::step()
{
	//	setData(string id, driver->getData());

	if(boolValue("Simulate")){
		qDebug() << "Simulating Heading" << heading;
		setData("Orientation.Heading", heading = (heading+1)%360);
	}
}

//This function creates all the devices that gather input robotron3000 (aka mako)
//This function is implicitly called after the constructor (by its QThread grandparent)
//and at the end of this function app.exec() is called (implicitly. Or it may acutally not
//be called in this function but for all intensive purposes its called after this.) 
//which is what makes this just start listening for all the signals.
void SAL::init(){
	qDebug() << "Starting SAL";
	setData("Module.SAL", 1);
	//camera->start();
	qDebug("SAL thread id: %d", (int) QThread::currentThreadId());
	


	//only acutally do this stuff if ../agent -s was not called with the "-s" being key
	if(boolValue("Simulate")){
		qDebug() << "Init Simulating Heading";
		//this is the timer that makes the step function get called every 500 milliseconds
		stepTimer->start(500);
		heading = 0;
	}else{
	
		//Connect the microstrain and the os5000 to the system

		//os5000 = new OS5000("");			//takes in serial port name as a string
		microstrain = new Microstrain("/dev/ttyS0");	//takes in dev
		
		
		//QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
		QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
	
		//The maestro is created here and its dataReady SIGNAL (which is called when it has new sensor
		//data) is connceted to the setData SLOT of the SAL which is in charge of forwarding that data to the
		//stateData.  At this point I feel I should note that there are actually two versions of setData
		//Both take a VDatum which is what needs to go to StateData but the Maestro actually outputs a list of
		//VDatums instead of a single one.  Thats because there are lots of things plugged into the maestro so
		//there is a seperate VDatum in the list for each one. :) random right?
		//maestro = new Maestro(this);
		//QObject::connect(maestro, SIGNAL(dataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
		
		//initiate forward camera
		//forwardParams is a CameraParams struct (defined in camera.h) and btw if you don't know what a struct
		//is you should probably go google it.  The struct is filled with the parameters defined in .auvrc file.
		forwardParams = new CameraParams;
		forwardParams->x = (config)["Camera.Forward.x"].toInt();
		forwardParams->y = (config)["Camera.Forward.y"].toInt();
		forwardParams->fps = (config)["Camera.Forward.fps"].toInt();
		forwardParams->pixelclock = (config)["Camera.Forward.pixelclock"].toInt();
		forwardParams->identity = (config)["Camera.Forward.identity"].toInt();
		forwardParams->serial = (config)["Camera.Forward.serial"];
		forwardParams->port = (config)["Camera.Forward.port"].toInt();
		forwardParams->address = (config)["Camera.Forward.address"];
		forwardParams->quality = (config)["Camera.Forward.quality"].toInt();
		
		//here the camera is created and passed the paramaters and is connected up
		forwardCamera = new Camera(forwardParams, this);
		QObject::connect(forwardCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
		
		//now we do the same for camera number 2!
		//initiate downward camera
		downParams = new CameraParams;
		downParams->x = (config)["Camera.Down.x"].toInt();
		downParams->y = (config)["Camera.Down.y"].toInt();
		downParams->fps = (config)["Camera.Down.fps"].toInt();
		downParams->pixelclock = (config)["Camera.Down.pixelclock"].toInt();
		downParams->identity = (config)["Camera.Down.identity"].toInt();
		downParams->serial = (config)["Camera.Down.serial"];
		downParams->port = (config)["Camera.Down.port"].toInt();
		downParams->address = (config)["Camera.Down.address"];
		downParams->quality = (config)["Camera.Down.quality"].toInt();

		downCamera = new Camera(downParams, this);
		QObject::connect(downCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
	}

}

#endif
