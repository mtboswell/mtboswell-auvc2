#ifndef ACTOR_H
#define ACTOR_H

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
		enum ActorMode {OPENLOOPMOVING, CLOSEDLOOPMOVING, TRACKING, SURFACING};
		enum targetDir {FORWARD, DOWN};
		
	public slots:

		void setCmd(QString cmd);

		void move(heading, depth, fwd, strafe, timeout = inf);
		void deadReckon(axis, distance);
		void track(object, down/fwd, bool maintainHeading, align=long/short, int approachSpeed);
		void surface();

	signals:
		void statusChanged();
		void finished();

	private slots:
		void runStep();

	private:
		ActCmd currentCMD;
		targetObj *currentOBJ;
};
