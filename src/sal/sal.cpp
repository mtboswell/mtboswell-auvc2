
#ifndef SAL_CPP_
#define SAL_CPP_

#include "sal.h"

SAL::SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):Module(configIn, stateIn, parent)
{
	//config = configIn;
	//os5000 = new OS5000("");			//takes in serial port name as a string
	//microstrain = new Microstrain("/dev/ttyS0");	//takes in dev


	//QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	//QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));


}


void SAL::step()
{
	//	setData(string id, driver->getData());

	if(boolValue("Simulate")){
		qDebug() << "Simulating Heading" << heading;
		setData("Orientation.Heading", heading = (heading+1)%360);
	}
}

void SAL::init(){
	qDebug() << "Starting SAL";
	setData("Module.SAL", 1);
	//camera->start();
	qDebug("SAL thread id: %d", (int) QThread::currentThreadId());
	



	if(boolValue("Simulate")){
		qDebug() << "Init Simulating Heading";
		stepTimer->start(500);
		heading = 0;
	}else{
		//maestro = new Maestro(this);
		//QObject::connect(maestro, SIGNAL(dataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
		
		//initiate forward camera
		forwardParams = new CameraParams;
		forwardParams->x = (config)["Camera.Forward.x"].toInt();
		forwardParams->y = (config)["Camera.Forward.y"].toInt();
		forwardParams->fps = (config)["Camera.Forward.fps"].toInt();
		forwardParams->pixelclock = (config)["Camera.Forward.pixelclock"].toInt();
		forwardParams->identity = (config)["Camera.Forward.identity"].toInt();
		forwardParams->serial = (config)["Camera.Forward.serial"];
		forwardParams->port = (config)["Camera.Forward.port"].toInt();
		forwardParams->address = (config)["Camera.Forward.address"];

		forwardCamera = new Camera(forwardParams, this);
		QObject::connect(forwardCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
		
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

		downCamera = new Camera(downParams, this);
		QObject::connect(downCamera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
	}

}

#endif
