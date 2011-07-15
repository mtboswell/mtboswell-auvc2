#ifndef IMU_DATA
#define IMU_DATA

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

#endif
