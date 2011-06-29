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
			qDebug() << "\t" << "#" << j;			
			qDebug() << "Option Label" << o.label;
			qDebug() << "Option Value" << o.value;
		}
		
		for (int k = 0; k < s.triggerTransitions.size(); ++k)
		{
			TriggerTransition t = s.triggerTransitions.at(k);
			qDebug() << "\t" << "#" << k;
			qDebug() << "Trigger Trans. Label" << t.label;
			qDebug() << "Trigger Trans. Operator" << t.cOperator;
			qDebug() << "Trigger Trans. Value" << t.value;
			qDebug() << "Trigger Trans. To" << t.to;
			qDebug() << "Trigger Trans. timeEnable" << t.timeEnable;
		}
	
		for (int l = 0; l < s.timerTransitions.size(); ++l)
		{
			qDebug() << "\t" << "#" << l;
			TimerTransition t = s.timerTransitions.at(l);
			qDebug() << "Timer Trans. To" << t.to;
			qDebug() << "Timer Trans. Time" << t.time;
		}
		
		qDebug();
	}
}

