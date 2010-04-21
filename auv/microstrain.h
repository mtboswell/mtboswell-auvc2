#ifndef MICROSTRAIN_H_
#define MICROSTRSIN_H_

typedef struct
 {
	 int command, tmticks, chksum;
	 double magDecl;					// local magnetic declination
	 double roll, pitch, yaw;		// orientation
	 double rollrate, pitchrate, yawrate;	// angular rates
	 double rollacc, pitchacc, yawacc;		// accelerations
	 int update; //1 if not yet given to the user, 0 if already given
 } imu_data;

/**
 * Class Microstrain handles all communication to a microstrain 3dm-gx1
 * IMU.  It will perform hard iron calibration with user interaction
 * through the standard input stream and will query the imu for both
 * temperature and gyro-stabilized angles, rates and accelerations.
 */
class Microstrain : public QThread
{
	Q_OBJECT
	public:
		Microstrain(const char* dev);
		~Microstrain();


		imu_data getData();

		/**
		 * setMagDecl(double decl) - sets the magnetic declination
		 * @param decl is the new magnetic declination to use
		 */
		void setMagDecl(double decl);

		bool calibrate();

	private:
		void process(const char* data, int len);

		QextSerialPort* port;

		void initStatus();

		imu_data status, tmpStatus;

		int DecodeIMUData(const char *data, int len);
		int ExtractIMUVars(const char *, imu_data &);
};

#endif /*IMU_H_*/
