
#ifndef SAL_CPP_
#define SAL_CPP_

#include "sal.h"

SAL::SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):Module(configIn, stateIn, parent)
{
	//os5000 = new OS5000("");			//takes in serial port name as a string
	//microstrain = new Microstrain("");	//takes in dev
	//camera = new Camera();


	//QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	//QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
	//QObject::connect(camera, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));


}


void SAL::step()
{
//	setData(string id, driver->getData());

	if(value("Simulate") == "true"){
		//qDebug() << "Simulating Heading";
		setData("Orientation.Heading", heading = (heading+1)%360);
	}
}

void SAL::init(){
	qDebug() << "Starting SAL";
	setData("Module.SAL", 1);
	//camera->start();
	qDebug("SAL thread id: %d", (int) QThread::currentThreadId());

	if(value("Simulate") == "true"){
		qDebug() << "Init Simulating Heading";
		stepTimer->start(1000);
		heading = 0;
	}else{
		maestro = new Maestro(this);
		QObject::connect(maestro, SIGNAL(dataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	}

}

#endif
