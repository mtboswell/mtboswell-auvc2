--	forwardBack.lua
--
--	@author Carlo del Mundo <cdel@vt.edu>
--	@date 6-2-2011
--	This script will make the robot travel with ForwardSpeed = 10 for 10 seconds
--	then, the robot will travel with ForwardSpeed = -10 for 10 seconds
--		The robot will continue in a circular manner
	
state =
{
	Name = "Forward";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 10;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Backward";
		t1_time = "10000";	-- ms
	};
};
addState(state);

state =
{
	Name = "Backward";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = -10;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Forward";
		t1_time = "10000";	-- ms
	};
};
addState(state);
