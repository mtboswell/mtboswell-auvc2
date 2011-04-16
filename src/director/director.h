#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "../state/treemodel/treemodel.h"
#include "../state/state.h"
#include "../module/module.h"
#include "lua/QueryLua.h"
#include "lua.hpp"

/*  @author Carlo del Mundo @date 4-15-2011
 *  The director determines the AUV's state by listening to AUV data and making decisions
 *  based on its current state (VDatum).  State change can also be invoked by built-in timers.
 */
class director : public Module
{
	Q_OBJECT
	public:
                director(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
                QStringList subscriptions()
                {
			QStringList sub;
                        sub << "Orientation.Heading";
			return sub;
		}
                void process();
                void loadStateFile();   // parses the auv.lua file

                // getter functions -- for convenience
                const State& getState(QString stateName);
                const QList<Transition>& getTransitions(QString stateName);
                const QList<Option>& getOptions(QString stateName);

	protected slots:
                void dataIn(VDatum datum);
                void init();
                void step();

                bool    hasTransition(VDatum datum);
                QString nextTransition();
                void setStateData(QString stateName);    // calls setData() with parameters based on stateName's Option objects

	private slots:

        private:
                QString currentState;
                QList<State> states;    // contains all possible states, as delineated in the auv.lua file

                QString transitionTo;   // a QString that represents the name of a state, updated in hasTransition()
};

#endif

