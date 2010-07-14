#include "os5000.h"
#include <QDebug>

OS5000::OS5000(const QString & serialPort): SerialDevice(serialPort, BAUD19200, true) {
	setIncomingDelimiter("$");
	setIncomingMaxLength(200);
}

double OS5000::heading(){return m_heading;}
double OS5000::pitch(){return m_pitch;}
double OS5000::roll(){return m_roll;}

void OS5000::processData(QByteArray data){
	//if(config["Debug"] == "true") 
	//	qDebug() << "Decoding compass data";
	data = data.trimmed();
	QRegExp fmt("C([-]*[\\d\\.]+)P([-]*[\\d\\.]+)R([-]*[\\d\\.]+)T([-]*[\\d\\.]+)\\*([A-F0-9]{2})");
	// Sample:
	// C2.7P-0.9R64.9T30.4*38
	if(fmt.exactMatch(data)){
		double heading = fmt.cap(1).toDouble();
		//qDebug() << "Decoded heading: " << QString::number(heading);
		double pitch = fmt.cap(2).toDouble();
		double roll = fmt.cap(3).toDouble();
		double temp = fmt.cap(4).toDouble();
		bool ok;
		char checksum = data.right(2).toInt(&ok, 16);
		// calculate checksum here
		char sum = 0;
		foreach(char byte, data){
			if(byte == '*') break;
			if(sum == 0) sum = byte;
			else sum = sum ^ byte;
		}
		if(sum == checksum){
			//qDebug() << "Correct Checksum!";
			emit compassData(heading, pitch, roll);
			m_heading = heading;
			m_pitch = pitch;
			m_roll = roll;
			m_temp = temp;
		}else{
			qDebug() << "Invalid compass data!";
			//qDebug() << "Data:" << data;
			//qDebug() << "Calculated:" << sum << "Expected:" << checksum;
		}
			
	}else{
		qDebug() << "Garbage compass data: " << data;
	}

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
