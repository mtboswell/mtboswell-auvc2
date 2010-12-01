#ifndef ACTOR_H
#define ACTOR_H

#include "../simulinkmodule.h"
#include "src/MotionController.h"
#include "mechanisms.h"

class Actor : public SimulinkModule 
{
	Q_OBJECT;
	public:
		Actor(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0);
		enum ActorMode {OPENLOOPMOVING, CLOSEDLOOPMOVING, TRACKING, SURFACING};
		enum ActorStatus {};
		
	public slots:

		void move(heading, depth, fwd, strafe, timeout = inf);
		void goTo(position = here);
		void track(object, down/fwd, bool maintainHeading, align=long/short, int approachSpeed);
		void surface();

	signals:
		void statusChanged();
	private slots:
		void runStep();

	private:
		ActCmd currentCMD;
		targetObj *currentOBJ;
};
