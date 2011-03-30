#ifndef MICROSTRAIN_H_
#define MICROSTRAIN_H_

#include "imudata.h"
#include "qextserialport.h"
#include "vdatum.h"
#include <QThread>
#include <QString>
#include <QByteArray>
#include <QDebug>

/**
 * Handles all communication to a microstrain 3dm-gx1
 * IMU.  It will perform hard iron calibration with user interaction
 * through the standard input stream and will query the imu for both
 * temperature and gyro-stabilized angles, rates and accelerations.
 */
class Microstrain : public QThread
{
	Q_OBJECT
	public:
		/**
		 * Constructor
		 * @param dev is the serial port connected to the AHRS
		 */
		Microstrain(const QString & dev);
		~Microstrain();

		/**
		 * Retrieves the latest set of data values.
		 * Data is returned in the form of an imu_data struct.
		 */
		imu_data getData();

		/**
		 * Sets the magnetic declination.
		 * @param decl is the new magnetic declination to use
		 */
		void setMagDecl(double decl);

		/**
		 * Enters AHRS calibration mode.
		 * This provides an interactive mode for hard-iron calibration of the 
		 * magnetonometer in the AHRS.
		 */
		bool calibrate();
	signals:
		/**
		 * Unimplemented.
		 * @param data is the latest AHRS data
		 */
		//void imuDataReady(imu_data data);
		void dataReady(VDatum);

	private slots:
		void onReadyRead();
		void process(QByteArray & data);

	private:
		QextSerialPort* port;

		void initStatus();

		imu_data status;

		int packetCount, corruptedCount;
		
		QByteArray* buf;

};

#endif /*MICROSTRAIN_H_*/
