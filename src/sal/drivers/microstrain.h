#ifndef MICROSTRAIN_H_
#define MICROSTRAIN_H_

#include "qextserialport.h"
#include "vdatum.h"
#include <QThread>
#include <QString>
#include <QByteArray>
#include <QDebug>


/**
 * Data container to contain data from an AHRS, such as the Microstrain 3DM-GX1.
 */
typedef struct
 {
	 int command, tmticks, chksum;
	 /**
	  * Local magnetic declination
	  */
	 double magDecl;					// local magnetic declination
	 /**
	  * Roll angle of the vehicle
	  */
	 double roll;
	 /**
	  * Pitch angle of the vehicle
	  */
	 double pitch;
	 /**
	  * Yaw, or Heading, measured from North (0).
	  */
	 double yaw;		// orientation
	 /**
	  * Angular rate of rotation around the roll axis
	  */
	 double rollrate;
	 /**
	  * Angular rate of rotation around the pitch axis
	  */
	 double pitchrate;
	 /**
	  * Angular rate of rotation around the yaw axis
	  */
	 double yawrate;	// angular rates
	 /**
	  * Acceleration along the roll axis
	  */
	 double rollacc;
	 /**
	  * Acceleration along the pitch axis
	  */
	 double pitchacc;
	 /**
	  * Acceleration along the yaw axis
	  */
	 double yawacc;		// accelerations
	 int update; //1 if not yet given to the user, 0 if already given
 } imu_data;


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
