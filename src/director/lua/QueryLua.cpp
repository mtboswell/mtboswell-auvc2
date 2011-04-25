#include <iostream>
#include <sstream>
#include <string>
#include <QDebug>
#include "QueryLua.h"

const char * headerscript = 
{
	"states = {}"
	
	"function addState(_state)\n"
		"states[#states + 1] = _state\n"
	"end\n"
	
	"function numStates()\n"
		"return #states\n"
	"end\n"
	
	"function returnState(_idx)\n"
		"return states[_idx]\n"
	"end\n"
};

QueryLua::QueryLua()
{
	pmLuaState = luaL_newstate();
	luaL_openlibs(pmLuaState);

	if (luaL_loadbuffer(pmLuaState, headerscript, strlen(headerscript), "header script") || lua_pcall(pmLuaState, 0, 0, 0))	
		std::cerr << "ERROR" << lua_tostring(pmLuaState, -1);
}

QueryLua::~QueryLua()
{
	lua_close(pmLuaState);
}

bool QueryLua::loadBuffer(char * buffer)
{
	if (luaL_loadbuffer(pmLuaState, buffer, strlen(buffer), "buffer") || lua_pcall(pmLuaState, 0, 0, 0))
	{
		// Error
		std::cerr << "ERROR" << lua_tostring(pmLuaState, -1);
		return false;
	}
}

bool QueryLua::init (const char *filename)
{
	try
	{
		if (luaL_loadfile(pmLuaState, filename) || lua_pcall(pmLuaState, 0, 0, 0))
			throw(0);
	}
	catch (int i)
	{
		switch(i)
		{
			case 0:
				std::cerr << "Error: " << lua_tostring(pmLuaState, -1) << std::endl;
				return false;
		}
	}
}

// assuming that stack has the correct table, e.g.: states[index]
QList<TriggerTransition> QueryLua::getTriggerTransition(int index)
{
	QList<TriggerTransition> list;
	lua_pushstring(pmLuaState, "TriggerTransitions");	// after: states[index].TriggerTransitions
	lua_gettable(pmLuaState, -2);
	if (!lua_istable(pmLuaState, -1))
        {
            std::cerr << "WARNING. A table was not returned from the states[index].TriggerTransitions table!" << std::endl;
            lua_pop(pmLuaState, 1);
            return list;
        }
		
	lua_pushstring(pmLuaState, "count"); // states[index].TriggerTransitions.count
	lua_gettable(pmLuaState, -2); 
        int count = 0;
	if (!lua_isnumber(pmLuaState, -1))
            std::cerr << "WARNING. An integer was not returned from the states[index].TriggerTransitions table for 'count'" << std::endl;
        else
            count = (int)(lua_tointeger(pmLuaState, -1));
	lua_pop(pmLuaState, 1);

	for (int i = 1; i <= count; ++i)
	{
		TriggerTransition t;
		
		std::stringstream ss;
		ss << "t" << i << "_label";
		lua_pushstring(pmLuaState, ss.str().c_str());
		lua_gettable(pmLuaState, -2);
		if (!lua_isstring(pmLuaState, -1))
                    std::cerr << "WARNING. A string was not returned from the states[index].TriggerTransitions.t<index>_label" << std::endl;
                else
                    t.label = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
		std::stringstream ss2;
		ss2 << "t" << i << "_operator";
		lua_pushstring(pmLuaState, ss2.str().c_str());
		lua_gettable(pmLuaState, -2);
		if (!lua_isstring(pmLuaState, -1))
                    std::cerr << "ERROR. A string was not returned from the states[index].TriggerTransitions.t<index>_label" << std::endl;
                else
                    t.cOperator = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
		std::stringstream ss3;
		ss3 << "t" << i << "_value";
		lua_pushstring(pmLuaState, ss3.str().c_str());
		lua_gettable(pmLuaState, -2);

		// the return can be either a number, or String
		if (!(lua_isstring(pmLuaState, -1) || lua_isnumber(pmLuaState, -1)))
			std::cerr << "ERROR. Expecting a number or string, but did not get it for states[Index].TriggerTransitions.t<index>_value" << std::endl;
		else if (lua_isnumber(pmLuaState, -1))
			t.value = lua_tonumber(pmLuaState, -1);
		else if (lua_isstring(pmLuaState, -1))
			t.value = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
		std::stringstream ss4;
		ss4 << "t" << i << "_to";
		lua_pushstring(pmLuaState, ss4.str().c_str());
		lua_gettable(pmLuaState, -2);
		
		if (!lua_isstring(pmLuaState, -1))
			std::cerr << "ERROR. Expecting a string, but did not get it for states[index].Transition.t<index>_to" << std::endl;
		else
			t.to = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
                std::stringstream ss5;
                ss5 << "t" << i << "_timeEnable";
                lua_pushstring(pmLuaState, ss5.str().c_str());
                lua_gettable(pmLuaState, -2);

                if (!lua_isnumber(pmLuaState, -1))
                        std::cerr << "WARNING. Expecting a number, but did not get it for states[index].Transition.t<index>_timeEnable" << std::endl;
                else
                        t.timeEnable = lua_tonumber(pmLuaState, -1);
                lua_pop(pmLuaState, 1);

		list.push_back(t);
	}

	lua_pop(pmLuaState, 1); // states[index]
	return list;	
}

// assuming the stack has the correct table, e.g.: states[index]
QList<TimerTransition> QueryLua::getTimerTransition(int index)
{
        QList<TimerTransition> list;
		  lua_pushstring(pmLuaState, "TimerTransitions");	// after: states[index].TimerTransition
        lua_gettable(pmLuaState, -2);
        if (!lua_istable(pmLuaState, -1))
        {
              std::cerr << "WARNING. A table was not returned from the states[index].TimerTransition table!" << std::endl;
              lua_pop(pmLuaState, 1);
              return list; 	// if an entry in the .lua file was not found, we return an empty list
        }
 
        int count = 0;
        lua_pushstring(pmLuaState, "count");
        lua_gettable(pmLuaState, -2);
        if (!lua_isnumber(pmLuaState, -1))
            std::cerr << "WARNING. An integer was not returned from the states[index].TimerTransition table for 'count'" << std::endl;
        else
            count = (int)(lua_tointeger(pmLuaState, -1));
        lua_pop(pmLuaState, 1);

        for (int i = 1; i <= count; ++i)
        {
                TimerTransition t;

                std::stringstream ss4;
                ss4 << "t" << i << "_to";
                lua_pushstring(pmLuaState, ss4.str().c_str());
                lua_gettable(pmLuaState, -2);

                if (!lua_isstring(pmLuaState, -1))
                        std::cerr << "ERROR. Expecting a string, but did not get it for states[index].TimerTransition.t<index>_to" << std::endl;
                else
                        t.to = lua_tostring(pmLuaState, -1);
                lua_pop(pmLuaState, 1);

                std::stringstream ss5;
                ss5 << "t" << i << "_time";
                lua_pushstring(pmLuaState, ss5.str().c_str());
                lua_gettable(pmLuaState, -2);

                if (!lua_isnumber(pmLuaState, -1))
                        std::cerr << "ERROR. Expecting a number, but did not get it for states[index].Transition.t<index>_timeEnable" << std::endl;
                else
                        t.time = lua_tonumber(pmLuaState, -1);
                lua_pop(pmLuaState, 1);

                list.push_back(t);
        }

        lua_pop(pmLuaState, 1); // states[index]

        return list;
}

// assuming that stack has the correct table, e.g.: states[index]
QList<Option> QueryLua::getOption(int index)
{
	QList<Option> list;
//	printStack();
	lua_pushstring(pmLuaState, "Options"); 	// after: states[index].Options
	lua_gettable(pmLuaState, -2);	// should return a table
	if (!lua_istable(pmLuaState, -1))
        {
            std:: cerr << "WARNING. A table was not returned when querying states[index].Options" << std::endl;
				lua_pop(pmLuaState, 1);
            return list;
        }

	lua_pushstring(pmLuaState, "count");	// after: states[Index].Options.count
	lua_gettable(pmLuaState, -2);
        int count = 0;
	if (!lua_isnumber(pmLuaState, -1))
            std::cerr << "ERROR. An integer was not returned from the states[Index].Options table for 'count'" << std::endl;
        else
            count = (int)(lua_tointeger(pmLuaState, -1));
	lua_pop(pmLuaState, 1);

	for (int i = 1; i <= count; ++i)
	{
		Option o;
		
		std::stringstream ss;
		ss << "o" << i << "_label";
		lua_pushstring(pmLuaState, ss.str().c_str()); 		// after: states[Index].Options.o<index>_label
		lua_gettable(pmLuaState, -2);
		if (!lua_isstring(pmLuaState, -1))
                    std::cerr << "ERROR. A string was not returned from the states[Index].Options.o<index>_label" << std::endl;
		else
                    o.label = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
		std::stringstream ss2;
		ss2 << "o" << i << "_value";
		lua_pushstring(pmLuaState, ss2.str().c_str()); 		// after: states[Index].Options.o<index>_value
		lua_gettable(pmLuaState, -2);
		
		// the return can be either a number, or String
		if (!(lua_isstring(pmLuaState, -1) || lua_isnumber(pmLuaState, -1)))
			std::cerr << "ERROR. Expecting a number or string, but did not get it for states[Index].Options.o<index>_value" << std::endl;
		else if (lua_isnumber(pmLuaState, -1))
			o.value = lua_tonumber(pmLuaState, -1);
		else if (lua_isstring(pmLuaState, -1))
			o.value = lua_tostring(pmLuaState, -1);
		lua_pop(pmLuaState, 1);
		
		list.push_back(o);
	}
	
	lua_pop(pmLuaState, 1);	
//	printStack();
	return list;
}

void QueryLua::printStack()
{
	qDebug();
	qDebug() << "Index at 1: isNone?" << lua_isnone(pmLuaState, 1);
	qDebug() << "Index at 2: isNone?" << lua_isnone(pmLuaState, 2);
	qDebug() << "Index at 3: isNone?" << lua_isnone(pmLuaState, 3);
	qDebug() << "Index at 4: isNone?" << lua_isnone(pmLuaState, 4);
	qDebug() << "Index at 5: isNone?" << lua_isnone(pmLuaState, 5);
	qDebug();
}

// returns a state entry given index
State QueryLua::getState(int index)
{
	State s;

	lua_getglobal(pmLuaState, "states");	// bottom of stack -- StackIndex = 1
	lua_pushinteger(pmLuaState, index);	
	lua_gettable(pmLuaState, -2);				// states[index]	-- StackIndex = 2

	lua_pushstring(pmLuaState, "Name");	// after: states[index].Name
	lua_gettable(pmLuaState, -2);
	if (!lua_isstring(pmLuaState, -1))
		std::cerr << "ERROR. A string was not returned from the table" << std::endl;
	else
		s.stateName = lua_tostring(pmLuaState, -1);
	lua_pop(pmLuaState, 1);
	
	lua_pushstring(pmLuaState, "Command"); 	// after: states[index].Command
	lua_gettable(pmLuaState, -2);
	if (!lua_isstring(pmLuaState, -1))
		std::cerr << "ERROR. A string was not returned for Command" << std::endl;
	else
		s.command = lua_tostring(pmLuaState, -1);
	lua_pop(pmLuaState, 1);


	s.options = getOption(index);
	s.triggerTransitions = getTriggerTransition(index);
	s.timerTransitions = getTimerTransition(index);

	lua_pop(pmLuaState, 1);	// after: states
	lua_pop(pmLuaState, 1);	//	after: empty
	return s;
}

// returns all states in a QList<State>
QList<State> QueryLua::queryStates()
{
	QList<State> list;
   int totalStates;
   
   lua_getglobal(pmLuaState, "numStates");
   lua_pcall(pmLuaState, 0, 1, 0);  // call function
         
   if (!lua_isnumber(pmLuaState, -1))
		std::cerr << "ERROR. A number was not returned for numStates" << std::endl;
   totalStates = (int)lua_tonumber(pmLuaState, -1);
   lua_pop(pmLuaState, 1); // stack should be clean now
    
	for (int i = 1; i <= totalStates; ++i)
	{
            list.push_back(getState(i));
	}
  	
  	return list;
}
