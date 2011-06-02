--	circle.lua
--
--      @author Carlo del Mundo <cdel@vt.edu>
--      @date 6-2-2011
--		The robot will attempt to travel in a circle by incrementing heading every 5 seconds by 15 degrees

state =
{
	Name = "Init";
	Command = "DeadReckon";
	Options =
	{
		count = 2;
		o1_label = "DeadReckon.Depth";
		o1_value = 0;

		o2_label ="DeadReckon.ForwardSpeed";
		o2_value = 10;
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Circle";
		t1_time = "5000";	-- ms
	};
};
addState(state);

state =
{
	Name = "Circle";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.MaintainHeading";
		o1_value = 15;
		o1_mode = 1;	-- RELATIVE mode
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Circle";
		t1_time = "5000";	-- ms
	};
};
addState(state);
