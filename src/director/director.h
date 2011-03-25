#ifndef SAL_H
#define SAL_H

/*
 * Data this module needs to provide:
 * 
	 Command
	 TargetOptions.TargetSelect
	 TargetOptions.Approach
	 TargetOptions.MaintainHeading
	 DeadReckon.Depth
	 DeadReckon.ForwardSpeed
	 DeadReckon.Heading 

	 TargetData.Found
	 TargetData.Position.X
	 TargetData.Position.Y
	 TargetData.Position.Z
	 TargetData.Position.Bearing
	 Position.Depth
	 Motion.Accel.Y
	 Motion.YawRate
	 Orientation.Heading

 */

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
};


#endif

