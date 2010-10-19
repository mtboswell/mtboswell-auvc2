#include "os5000.h"
#include <QDebug>
#include <QString>

OS5000::OS5000(const QString & serialPort): SerialDevice(serialPort, BAUD19200, true) {
	setIncomingDelimiter("$");
	setIncomingMaxLength(200);
	qDebug() << "spawning os5000";
}

double OS5000::heading(){return m_heading;}
double OS5000::pitch(){return m_pitch;}
double OS5000::roll(){return m_roll;}

void OS5000::processData(QByteArray data){
	qDebug() << "processing os5000 data";
	QRegExp fmt("C(\\d{1,3}\.\\d)P(-?\\d{1,2}\.\\d)R(-?\\d{1,2}\.\\d)T(-?\\d{1,2}\.\\d)\\*(\\w{2})\\r\\n");
	qDebug() << data;
	if(fmt.exactMatch(data)){
		double heading = fmt.cap(1).toDouble();
		double pitch = fmt.cap(2).toDouble();
		double roll = fmt.cap(3).toDouble();
		double temp = fmt.cap(4).toDouble();
		char checksum = data.at(-1);
		// calculate checksum here
		char sum = 0;
		foreach(char byte, data){
			if(sum == 0) sum = byte;
			else sum = sum ^ byte;
		}
		if(sum == checksum){
			emit compassData(heading, pitch, roll);
			m_heading = heading;
			m_pitch = pitch;
			m_roll = roll;
			m_temp = temp;
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
