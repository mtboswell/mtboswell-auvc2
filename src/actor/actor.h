#ifndef ACTOR_H
#define ACTOR_H

#include "../sid.h"
#include "../simulinkmodule.h"
#include "src/MotionController.h"
#include "mechanisms.h"
#include "hal.h"
#include "sal.h"
#include "aal.h"

/**
 * Actor Module.
 * Inputs:
 * 	Command
 *	Command Options:
 *		motion
 			heading, depth, fwd, strafe
 *		position
 			axis (x,y,z), distance
 *		target
 			targetID$
			direction?
			maintainHeading?
			align?
			approachSpeed#
 * Outputs: 
 *	Thruster outputs
 */
class Actor : public SimulinkModule 
{
	Q_OBJECT;
	public:
		Actor(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0);
		bool ActorFinished;
		enum ActorMode {DIRECTRC, MOVING, TRACKING, SURFACING};
		enum targetDir {FORWARD, DOWN};
		
		// targetFlags
		int TargetDown = 0x01;
		int TargetNotForward = 0x01;
		// These are the same
		int MaintainHeading = 0x02;
		int UseStrafe = 0x02;
		
	public slots:

		void setCmd(QString cmd);

		void setThrusters(int thrusterSpeeds[]);
		void move(heading, depth, fwd, strafe, timeout = inf);
		void track(object, down/fwd, bool maintainHeading, align=long/short, int approachSpeed);
		void surface();

	signals:
		void statusChanged();
		void finished();

	private slots:
		void runStep();
		void messageIn(SID message);

	private:
		ActorMode currentCMD;

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
};
