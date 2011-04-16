/*	STANDALONE DRIVER TO TEST IF THE LUA C PROGRAM IS PARSING THE CORRECT VALUES
 *
 */

#include "QueryLua.h"
#include <iostream>
#include <QDebug>

using namespace std;

int main () 
{
	QueryLua *ql = new QueryLua;

	char filename[256] = "auv.lua";
	ql->init(filename);
	QList<State> states = ql->queryStates();
	
	
	// Print out contents of structs
	for (int i = 0; i < states.size(); ++i)
	{
		State s = states.at(i);

		qDebug() << "\nState Name" << s.stateName;
		qDebug() << "Command" << s.command;
		
		for (int j = 0; j < s.options.size(); ++j)
		{
			Option o = s.options.at(j);			
			qDebug() << "Option Label" << o.label;
			qDebug() << "Option Value" << o.value;
		}
		
		for (int k = 0; k < s.transitions.size(); ++k)
		{
			Transition t = s.transitions.at(k);
			qDebug() << "Trans. Label" << t.label;
			qDebug() << "Trans. Operator" << t.cOperator;
			qDebug() << "Trans. Value" << t.value;
			qDebug() << "Trans. To" << t.to;
		}
		
		qDebug();
	}
}

