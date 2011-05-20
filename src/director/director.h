#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QSignalMapper>
#include "../state/treemodel/treemodel.h"
#include "../state/state.h"
#include "../module/module.h"
#include "lua/QueryLua.h"
#include "lua.hpp"

/*  @author Carlo del Mundo
 *  @date   4-21-2011
 *
 *  The director determines the AUV's state by listening to AUV data and making decisions
 *  based on its current state.  State change can also be invoked by built-in timers.
 *
 *  All possible legal states are defined in a file called: "auv.lua".  Director parses the file
 *  using the Lua interpreter.  You must have Lua 5.1 or higher installed in your distribution
 *  for this module to work properly.
 */
class director : public Module
{
	Q_OBJECT
	public:
                director();
                ~director();
                QStringList subscriptions() // add entries here depending on what values you want to listen to
                {
			QStringList sub;
                        sub << "Orientation.Heading";
			return sub;
		}
                void process();
                void loadStateFile();   // parses the auv.lua file

                // getter functions -- for convenience
                const State& getState(QString stateName);

                const QList<TriggerTransition>& getTriggerTransitions(QString stateName);
                const QList<TimerTransition>& getTimerTransitions(QString stateName);
                const QList<Option>& getOptions(QString stateName);
                const int determineLongestTimeEnable(QString stateName);

                // determines if Transition conditions are triggered, and sets the new state, if possible
                bool    hasTransition(VDatum datum);
                QString nextTransition();

                // determines if certain Transitions are legal (based on the object's timeEnable variable)
                void startTriggerTimers(QString currentState);
                void startAutoTimers(QString currentState);
                void updateEnableList(QString stateName);

	protected slots:
                void dataIn(VDatum datum);
                void init();
                void step();

                // QTimer signals connect to this slot
                void enableTransition(int t);
                void setStateData(QString stateName);    // calls setData() with parameters based on stateName's Option objects

	private slots:

        private:
                QString currentState;
                QList<State> states;    // contains all possible states, as delineated in the auv.lua file
                QString transitionTo;   // a QString that represents the name of a state, updated in hasTransition()

                QList<QTimer*> triggerTimers;      // timers to determine if a Transition object is valid
                QList<QTimer*> autoTimers;      // timers that transition to a state after a set number of seconds
                QSignalMapper signalMapper; // for timers to pass the Transition objects
                QList<bool> enableList;   // parallel array to determine if a Transition object is enabled
};

#endif

