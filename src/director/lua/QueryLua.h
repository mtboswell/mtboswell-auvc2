#include <lua.hpp>
#include <QList>
#include <QString>
#include <QChar>
#include <QVariant>

// defines a Transition object
struct Transition
{
	QString label;
	QString	cOperator;	// comparison operator
	QVariant value;	
};

// defines an Options object
struct Option
{
	QString label;
	QVariant value;
};

struct State
{
	QString stateName;
	QString command;
	QList<Option>	options;
	QList<Transition> transitions;
};

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
