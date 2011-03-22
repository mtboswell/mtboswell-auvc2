#include "os5000.h"
#include "../state.h"
#include <QDebug>
#include <QString>
#include <QTime>

OS5000::OS5000(const QString & serialPort): SerialDevice(serialPort, BAUD19200, true) {
	setIncomingDelimiter("$");
	setIncomingMaxLength(200);
	qDebug() << "spawning os5000";
}

//is this function needed? --RS
HALdata* OS5000::produceHALData(double roll, double pitch, double yaw){
// something goes here that produces the HAL data
}

/*
physicalState* OS5000::returnPhysicalState(double yaw, double pitch, double yaw){
    physicalState pState = new physicalState();
    pState.rotPos = roll();
    pState.rotRate = pitch();
    pState.rotAcc = yaw();
    pState.coordinates = GLOBAL; //or LOCAL not sure
    pState.linAcc = 0; // not sure how to get this value
    pState.linPos = 0; // or this value
    pState.linRate = 0; // or this value
}
*/

double OS5000::yaw(){return m_yaw;}
double OS5000::pitch(){return m_pitch;}
double OS5000::roll(){return m_roll;}

void OS5000::processData(QByteArray data){
	qDebug() << "processing os5000 data";
	QRegExp fmt("C(\\d{1,3}\.\\d)P(-?\\d{1,2}\.\\d)R(-?\\d{1,2}\.\\d)T(-?\\d{1,2}\.\\d)\\*(\\w{2})\\r\\n");
	qDebug() << data;
	if(fmt.exactMatch(data)){
                double yaw = fmt.cap(1).toDouble();
		double pitch = fmt.cap(2).toDouble();
		double roll = fmt.cap(3).toDouble();
                //double temp = fmt.cap(4).toDouble();
		char checksum = data.at(-1);
		// calculate checksum here
		char sum = 0;
		foreach(char byte, data){
			if(sum == 0) sum = byte;
			else sum = sum ^ byte;
		}
		if(sum == checksum){
                        struct sensorValue* yawSV = new sensorValue;
                        yawSV->datumID = "yaw";
                        yawSV->sensorID = "os5000";
                        yawSV->timestamp = QTime::currentTime();
                        yawSV->value = yaw;

                        struct sensorValue* pitchSV = new sensorValue;
                        pitchSV->datumID = "pitch";
                        pitchSV->sensorID = "os5000";
                        pitchSV->timestamp = QTime::currentTime();
                        pitchSV->value = pitch;

                        struct sensorValue* rollSV = new sensorValue;
                        rollSV->datumID = "roll";
                        rollSV->sensorID = "os5000";
                        rollSV->timestamp = QTime::currentTime();
                        rollSV->value = roll;

                        QList<sensorValue> *compassData = new QList<sensorValue>;
                        (*compassData).append( (*yawSV) );
                        (*compassData).append( (*pitchSV) );
                        (*compassData).append( (*rollSV) );
                        emit compassDataReady( (*compassData) );
                        //m_yaw = yaw;
                        //m_pitch = pitch;
                        //m_roll = roll;
                        //m_temp = temp;
                        //emit compassData(yaw, pitch, roll);
		}else qDebug() << "Checksum Error";
	}
	else qDebug() << "os5000 format error";	

}


void OS5000::calibrate(){
	// check that the platform is level
	if(abs(m_pitch) > 1 || abs(m_roll) > 1){
		emit error("Vehicle not level");
		return;
	}
	emit status("Starting Compass Calibration");
	emit startingCalibration();

	// send cmd
	sendQuery(QByteArray(1, (char)0x1B) + QByteArray("C"), QByteArray("........."));

	emit status("Slowly rotate the vehicle in a full circle, while keeping it level.");

	// wait 30s
	sleep(30);

	// send stop cmd
	sendData(" ");

	emit status("Compass Calibration Complete");
	emit calibrationComplete();
}
