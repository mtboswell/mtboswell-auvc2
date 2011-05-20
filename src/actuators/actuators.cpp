#ifndef Actuators_CPP_
#define Actuators_CPP_

#include "actuators.h"
#include <QDebug>

Actuators::Actuators():Module(){
}

void Actuators::step(){
}

void Actuators::init(){
	pololu = new Pololu("/dev/ttyACM1", debug);
	setData("Module.Actuators", 1);
	if(debug) qDebug("Actuators thread id: %d", (int) QThread::currentThreadId());
	if(debug) qDebug() << "Set motor 1 to 64";
	pololu->setMotorSpeed(1, 64);
}

void Actuators::dataIn(VDatum datum){
	if(datum.id != "Thrusters") return;	
	if(datum.value == oldData.value) return;
	oldData = datum;

	if(debug) qDebug() << "Actuators got data:" << datum.id;

	double thrusters[4];
	thrusters[0] = datum.value.value<QVector4D>().w();
	thrusters[1] = datum.value.value<QVector4D>().x();
	thrusters[2] = datum.value.value<QVector4D>().y();
	thrusters[3] = datum.value.value<QVector4D>().z();
	setThrusters(thrusters);
}


// set thruster speeds
void Actuators::setThrusters(double thrusterSpeeds[4]){
	//if(!value("ThrusterPower.State") || value("status") != "RUNNING") return;
	if(debug) qDebug() << "Setting thrusters to" << thrusterSpeeds[0] << thrusterSpeeds[1] << thrusterSpeeds[2] << thrusterSpeeds[3];

	if(debug) qDebug("Conversing with TReXs");
	for(int i = 0; i < 4; i++){
		if(debug) qDebug() << "Setting Thruster" << i << "to" << thrusterSpeeds[i];
		pololu->setMotorSpeed(i, thrusterSpeeds[i]*127);
	}
}

#endif
