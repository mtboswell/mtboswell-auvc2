#ifndef OS5000_H
#define OS5000_H

#include "serialdevice.h"
#include <QRegExp>
#include <QDebug>

class OS5000 : public SerialDevice
{
	Q_OBJECT
	public:
		OS5000(const QString & serialPort);

		double heading();
		double pitch();
		double roll();

	public slots:
		
		void calibrate();

	signals:
		void compassData(double currentHeading, double currentPitch, double currentRoll);
		void status(QString msg);
		void error(QString msg);
		void startingCalibration();
		void calibrationComplete();

	private slots:
		void processData(QByteArray data);

	private:
		double m_heading, m_pitch, m_roll, m_temp;


};

#endif
