--      debug.lua
--
--      @author Carlo del Mundo <cdel@vt.edu>
--      @date 6-2-2011
--		Debug script for some state variables that are not being set in Controllers

state =
{
	Name = "Pseudo";
	Command = "DeadReckon";
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "InitParameters";
		t1_time = "5000";	-- ms
	};
};
addState(state);

state =
{
	Name = "InitParameters";
	Command = "DeadReckon";

	Options =
	{
		count = 7;
		o1_label = "TargetData.Found";
		o1_value = False;		-- ERROR... can't handle booleans yet

		o2_label = "TargetData.Position.X";
		o2_value = 1;

		o3_label = "TargetData.Position.Y";
		o3_value = 1;

		o4_label = "TargetData.Position.Z";
		o4_value = 1;

		o5_label = "TargetOptions.TargetSelect";
		o5_value = "Forward";

		o6_label = "TargetData.Position.Bearing";
		o6_value = 2;

		o7_label = "TargetOptions.MaintainHeading";
		o7_value = 180;
	};
	
	TimerTransitions =
	{
		count = 0;
		
		t1_to = "TargetStuff";
		t1_time = "10000";	-- ms
	};
};
addState(state);
