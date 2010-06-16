#include "os5000.h"
#include <QDebug>

OS5000::OS5000(const QString & serialPort): SerialDevice(serialPort, BAUD19200) {
	setIncomingDelimiter("$");
	setIncomingMaxLength(200);
}

void OS5000::processData(QByteArray data){
	QRegEx fmt("C([-][\\d\\.]+)P([-][\\d\\.]+)R([-][\\d\\.]+)T([-][\\d\\.]+)[.]*\\*([A-F0-9]{2})");
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
			emit data(heading, pitch, roll);
		}
	}

}


void OS5000::calibrate(){
	// check that the platform is level
	if(abs(pitch) > 1 || abs(roll) > 1){
		emit error("Vehicle not level");
		return;
	}
	emit status("Starting Compass Calibration");
	emit startingCalibration();

	// send cmd
	sendQuery(QByteArray(0x1B) + 'C', ".........");

	emit status("Slowly rotate the vehicle in a full circle, while keeping it level.");

	// wait 30s
	sleep(30);

	// send stop cmd
	sendData(" ");

	emit status("Compass Calibration Complete");
	emit calibrationComplete();
}
