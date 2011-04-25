#include <lua.hpp>
#include <QList>
#include <QString>
#include <QChar>
#include <QVariant>

// defines a TriggerTransition object
struct TriggerTransition
{
        QString label;          // e.g.:    "Orientation.Heading"
	QString	cOperator;	// comparison operator
        QVariant value;         // e.g.:    3, 2.3, "Buoy"
        QString to;             // e.g.:    "STOPState"

        int timeEnable;         //  the time (in milliseconds) it takes for this Transition object to be valid.
                                    // 0 - the Transition object is valid for all t
                                    // e.g.: if timeEnable = 5000, for t > 5 seconds, the Transition Object
                                    // is legal (and therefore, we may transition if the condition is triggered)

        TriggerTransition()    // default constructor
        {
            label = "";
            cOperator = "";
            value = "";
            to = "";
            timeEnable = 0;
        }
};

// defines a TimerTransition object
struct TimerTransition
{
        QString to;             // e.g.:    "STOPState"
        int time;

        TimerTransition()
        {
            to = "";
            time = 0;
        }
};

// defines an Options object
struct Option
{
        QString label;          // e.g.:    "Target.DesiredHeading"
        QVariant value;         // e.g.:    3, 2.3, "Buoy"
};

struct State
{
        QString stateName;      // e.g.:    "STOPState"
        QString command;        // e.g.:    "Target"
	QList<Option>	options;
	QList<TriggerTransition> triggerTransitions;
	QList<TimerTransition> timerTransitions;
};

/*  QueryLua
 *
 *  The QueryLua class parses the .lua file into a readable form in C++.
 *  This ensures 'compile-once' capabilities.  You are free to edit the auv.lua
 *  and the changes will be reflected when you run the program again.
 */
class QueryLua
{
	public:
		QueryLua();
		~QueryLua();
		void loadFile();
		bool loadBuffer(char *);
		bool init(const char *);
		QList<TriggerTransition> getTriggerTransition(int index);
                QList<TimerTransition> getTimerTransition(int index);
		QList<Option> getOption(int index);
		State getState(int index);
		QList<State> queryStates();
		void printStack();
	protected:
		lua_State *pmLuaState;
};
