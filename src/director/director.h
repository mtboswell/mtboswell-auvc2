#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "../state/treemodel/treemodel.h"
#include "../state/state.h"
#include "../module/module.h"
#include "stateImpl/BaseState.h"
#include "stateImpl/DefaultState.h"

class BaseState;
class DefaultState;

/*
 *  The director determines the AUV's state by listening to AUV data and making decisions
 *  based on its current state.  State change can also be invoked by built-in timers.
 */
class director : public Module
{
	Q_OBJECT
	public:
                director(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
                QStringList subscriptions()
                {
			QStringList sub;
			sub << "";
			return sub;
		}
                void process();
                void changeState(BaseState *);
                void run();
	protected slots:
                void dataIn(VDatum datum);


	private slots:

        private:
                BaseState *currentState;
};


#endif

