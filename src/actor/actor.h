#ifndef ACTOR_H
#define ACTOR_H

#include "../simulinkmodule.h"
#include "src/MotionController.h"

class Actor : public SimulinkModule 
{
	Q_OBJECT;
	public:
	Actor(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0);
	private slots:
		void runStep();
};
