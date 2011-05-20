#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "vdatum.h"
#include "simulinkmodule.h"
#include "src/MotionController.h"
#include <QDebug>
#include <QVector4D>

/**
 * Controllers Module.
 */
class Controllers : public SimulinkModule 
{
	Q_OBJECT;
	public:
		Controllers();
		QStringList subscriptions(){
			QStringList sub;
			//sub << ""; // subscribe to all
			sub << "Mode";
			return sub;
		}
	public slots:

	//	void setCmd(QString cmd);

	//	void setThrusters(int thrusterSpeeds[]);
	//	void move(heading, depth, fwd, strafe, timeout = inf);
	//	void track(object, down/fwd, bool maintainHeading, align=long/short, int approachSpeed);
	//	void surface();
		void dataIn(VDatum message);

	signals:
		void statusChanged();
		void finished();

	private slots:
		void init();
		/**
		 * Module step function.
		 * Since this is a SimulinkModule, all of the work is done in this funciton.
		 */
		void step();

	private:
	/*
		ControllersMode currentCMD;

		// directRC
		QList<char> thrusterSpeeds;
		// move
		double desiredYaw,
			desiredZ,
			desiredXVel,
			desiredYVel;
		QTime timeout;
		// tracking
		QString targetID;
		targetDir targetDirection;
		bool maintainHeading;
		double approachSpeed;
		double alignAngle;
		*/
		bool stopped;
};

#endif
