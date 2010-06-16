#ifndef OS5000_H
#define OS5000_H

#include "serialdevice.h"

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
		void data(double currentHeading, double currentPitch, double currentRoll);

	private slots:
		void processData(QByteArray data);

	private:
		double m_heading, m_pitch, m_roll;

};

#endif
