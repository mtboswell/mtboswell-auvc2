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
		
		enum CMDS {MOVE, GOTO, TRACK, ALIGN, APPROACH, RETREAT, HOLD, SURFACE};
	public slots:
		void setCmd(QString cmd);

	signals:
		void statusChanged();
	private slots:
		void runStep();
};
