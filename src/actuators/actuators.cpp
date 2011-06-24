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
	if(debug) pololu->setMotorSpeed(1, 64);
	forwardON = true;
	angledON = true;
}

void Actuators::dataIn(VDatum datum){
	if(datum.id == "Thrusters") {	
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
	if (datum.id == "ThrustersON.Forward") {
		if (debug) qDebug() << "ThrustersON.Forward is set to " << datum.value.toBool();
		forwardON = datum.value.toBool();
		if(!forwardON) {
			if (debug) qDebug() << "Setting forward Thrusters to 0";
			pololu->setMotorSpeed(0, 0);
			pololu->setMotorSpeed(3, 0);
		}
	}
	else if (datum.id == "ThrustersON.Angled") {
		angledON = datum.value.toBool();
		if(!angledON) {
			pololu->setMotorSpeed(1, 0);
			pololu->setMotorSpeed(2, 0);
		}
	}
	else if (datum.id == "Vision.FireAuthorization") {
		qDebug() << "FIRE!";
		fireTorpedo(datum.value.toInt(), true);
	}
}


// set thruster speeds
void Actuators::setThrusters(double thrusterSpeeds[4]){
	//if(!value("ThrusterPower.State") || value("status") != "RUNNING") return;
	if(debug) qDebug() << "Setting thrusters to" << thrusterSpeeds[0] << thrusterSpeeds[1] << thrusterSpeeds[2] << thrusterSpeeds[3];

	if(debug) qDebug("Conversing with TReXs");
	for(int i = 0; i < 4; i++){
		if (((i == 0 || i == 3) && forwardON) || ((i == 1 || i == 2) && angledON)) {
			if(debug) qDebug() << "Setting Thruster" << i << "to" << thrusterSpeeds[i];
			pololu->setMotorSpeed(i, thrusterSpeeds[i]*127);
		}
	}
}

void Actuators::fireTorpedo(int torp, bool fire) {
	QByteArray data;
	data.append(0x80);
	data.append(0x01);
	data.append(0x02);

	if (torp = 1) {
		data.append(0x00);
	}
	else {
		data.append(0x01);
	}
	if (fire) {
		data.append(0x7F);
	}
	else {
		data.append(0x01);
	}
	pololu->writeSolCmd(data);
}
#endif
