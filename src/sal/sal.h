#ifndef SAL_H
#define SAL_H

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
 #include "microstrain.h"
 #include "maestro.h"
 #include "os5000.h"
 #include "camera.h"
 #include <QTime>

class SAL: public Module
{
	Q_OBJECT
	public:
		SAL();
		/**
		 * This module subscribes to:.
		 * Command - Not needed?
		 * TargetOptions - ?
		 */
		QStringList subscriptions(){
			QStringList sub;
			//sub << "Command";
			//sub << "TargetOptions";
			sub << "DeadReckon.Heading";
			sub << "Orientation.Heading";
			sub << "Maestro.Depth_Raw";
			return sub;
		}

	private slots:
		void step();	//calls setData(id string, driver->getData());
		void init();
		void dataIn(VDatum datum);
		
	private:
		OS5000* os5000;		//connect in constructor
		Maestro* maestro;	//this too
		Microstrain* microstrain;	//old, will need to be included in step()
		Camera* forwardCamera;
		Camera* downCamera;
		CameraParams* forwardParams;
		CameraParams* downParams;
		bool headingStable;
		bool atHeading;
		bool prevAtHeading;
		int desiredHeading;
		void checkStability(VDatum datum);
		void updateDepth(VDatum datum);
		QTime headingTime;
		int depthArray[50];		//Stores the last fify rawDepths. Done as an atempt to remove some noise *exparimental*
		int depthTracker;
		float depthBaseline;
		float depthMultiplier;
		int depthArraySize;

		// for sim
		int heading;
		
		//...
};


#endif

