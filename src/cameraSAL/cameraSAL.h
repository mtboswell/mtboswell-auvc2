#ifndef CameraSAL_H
#define CameraSAL_H

/**
 * SAL Module.
 * Data available to this module (inputs):
 *
 * From Director:
 *	 Command ("Target", "DeadReckon") 
 *	 TargetOptions.TargetSelect ("Forward", "Down")
 * 	 TargetOptions.Approach (bool)
 *	 TargetOptions.MaintainHeading (bool)
 *	 DeadReckon.Depth (double)
 *	 DeadReckon.ForwardSpeed (double)
 *	 DeadReckon.Heading  (double)
 *
 * This module does not necessarily use any of the above
 *
 *
 * Data this module needs to provide (outputs):
 * 
 * To controllers:
 *	 TargetData.Found (bool)		vision
 *	 TargetData.Position.X (double)		vision
 *	 TargetData.Position.Y (double)		vision	
 *	 TargetData.Position.Z (double)		vision
 *	 TargetData.Position.Bearing (double)	vision/sonar	
 *	 Position.Depth (double)		maestro->depth
 *	 Motion.Accel.Y (double)		MicroStrain or OS5000
 *	 Motion.YawRate (double)		MicroStrain or gyros
 *	 Orientation.Heading (double)		MicroStrain or OS5000
 *
 */

 #include "module.h"
 #include "vdatum.h"
 #include "camera.h"
 #include <QTime>

class CameraSAL: public Module
{
	Q_OBJECT
	public:
		CameraSAL();
		/**
		 * This module subscribes to:.
		 * Command - Not needed?
		 * TargetOptions - ?
		 */
		QStringList subscriptions(){
			QStringList sub;
			//sub << "Command";
			//sub << "TargetOptions";
			sub << "Parameter.Vision.ModeSelect";
			return sub;
		}

	private slots:
		void step();	//calls setData(id string, driver->getData());
		void init();
		void dataIn(VDatum datum);
		
	private:
		Camera* forwardCamera;
		Camera* downCamera;
		CameraParams* forwardParams;
		CameraParams* downParams;
		bool cameraCreated;
		//...
};


#endif

