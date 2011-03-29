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

 #include "drivers/microstrain.h"
 #include "drivers/maestro.h"
 #include "drivers/os5000.h"

class SAL: public Module
{
	Q_OBJECT
	public:
		SAL(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		QStringList subscriptions(){
			QStringList sub;
			sub << "";
			return sub;
		}
	protected slots:
//		void dataIn(VDatum datum);
	private slots:
	private:
		OS5000* os5000;
		Maestro* maestro;
		//...
};


#endif

