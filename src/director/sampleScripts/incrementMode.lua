--	This lua file demonstrates how one can increment an AUVT state variable such as Orientation.Heading
-- This script will transition between State1 and State2 every 5 seconds.  For every transition to State1, 
-- 	the Orientation.Heading state variable is incremented by 60 degrees.

--	Note: the key part is the _mode variable under the Options structure
--		A _mode of 1 means RELATIVE --- add the current running value
--		A _mode of 0 means ABSOLUTE (default) --- always overwrite the existing value

state =
{
	Name = "State1";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		
		o1_label = "Orientation.Heading";
		o1_value = 60;
		o1_mode = 1;	-- RELATIVE mode (as in: we increment Orientation.Heading by 60)
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "State2";
		t1_time = 5000;
	};
};
addState(state);

state =
{
	Name = "State2";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 30;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "State1";
		t1_time = "5000";	-- ms
	};
};
addState(state);
