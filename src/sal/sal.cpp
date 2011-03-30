
#ifndef SAL_CPP_
#define SAL_CPP_

#include "sal.h"

SAL::SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):Module(configIn, stateIn, parent)
{
	os5000 = new OS5000();			//takes in serial port name as a string
	microstrain = new Microstrain();	//takes in dev


	QObject::connect(os5000, SIGNAL(compassDataReady(QList<VDatum>)), this, SLOT(setData(QList<VDatum>)));
	QObject::connect(microstrain, SIGNAL(dataReady(VDatum)), this, SLOT(setData(VDatum)));
	//add maestro signal here

}


void SAL::step()
{
//	setData(string id, driver->getData());

}

#endif
