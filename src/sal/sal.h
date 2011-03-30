#ifndef SAL_H
#define SAL_H

/*
 * Data available to this module (inputs):

	 Command ("Target", "DeadReckon") 
	 TargetOptions.TargetSelect ("Forward", "Down")
	 TargetOptions.Approach (bool)
	 TargetOptions.MaintainHeading (bool)
	 DeadReckon.Depth (double)
	 DeadReckon.ForwardSpeed (double)
	 DeadReckon.Heading  (double)

 *
 * Data this module needs to provide (outputs):
 * 

	 TargetData.Found (bool)		vision
	 TargetData.Position.X (double)		vision
	 TargetData.Position.Y (double)		vision	
	 TargetData.Position.Z (double)		vision
	 TargetData.Position.Bearing (double)	vision/sonar	
	 Position.Depth (double)		maestro->depth
	 Motion.Accel.Y (double)		MicroStrain or OS5000
	 Motion.YawRate (double)		MicroStrain or gyros
	 Orientation.Heading (double)		MicroStrain or OS5000

 */

 #include "module.h"
 #include "microstrain.h"
 #include "maestro.h"
 #include "os5000.h"
 #include "camera.h"

class SAL: public Module
{
	Q_OBJECT
	public:
		SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		QStringList subscriptions(){
			QStringList sub;
			//sub << "";
			return sub;
		}
	protected slots:
//		void dataIn(VDatum datum);
	private slots:
		void step();	//look in module.h
			//setData(id string, driver->getData());
	private:
		OS5000* os5000;		//connect in constructor
		Maestro* maestro;	//this too
		Microstrain* microstrain;	//old, will need to be included in step()
		Camera* camera;
		
		//...
};


#endif

