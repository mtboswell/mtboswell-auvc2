#include <lua.hpp>
#include <QList>
#include <QString>
#include <QChar>
#include <QVariant>

// defines a Transition object
struct Transition
{
        QString label;          // e.g.:    "Orientation.Heading"
	QString	cOperator;	// comparison operator
        QVariant value;         // e.g.:    3, 2.3, "Buoy"
        QString to;             // e.g.:    "STOPState"
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
	QList<Transition> transitions;
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
		bool init(char *);
		QList<Transition> getTransition(int index);
		QList<Option> getOption(int index);
		State getState(int index);
		QList<State> queryStates();

	protected:
		lua_State *pmLuaState;
};
