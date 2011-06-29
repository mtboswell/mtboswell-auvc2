--      diveRise.lua           
--
--      @author Carlo del Mundo <cdel@vt.edu>
--      @date 6-2-2011
--      This script will make the robot dive to 8 feet for 10 seconds
--      then, the robot will surface to 0 feet for 10 seconds
--              The robot will continue in a circular manner

state =
{
	Name = "Rise";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.Depth";
		o1_value = 0;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Dive";
		t1_time = "10000";	-- ms
	};
};
addState(state);

state =
{
	Name = "Dive";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.Depth";
		o1_value = 8;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Rise";
		t1_time = "10000";	-- ms
	};
};
addState(state);
