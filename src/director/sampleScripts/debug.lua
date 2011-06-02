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
		count = 15;
		o1_label = "TargetData.Found";
		o1_value = true;	

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
		
		o8_label = "TargetOptions.Approach";
		o8_value = true;
		
		o9_label = "Orientation.Heading";
		o9_value = 90;
		
		o10_label = "Motion.YawRate";
		o10_value = 0;
		
		o11_label = "Position.Depth";
		o11_value = 0;
		
		o12_label = "Motion.Accel.Y";
		o12_value = 0;
		
		o13_label = "DeadReckon.Depth";
		o13_value = 0;
		
		o14_label = "DeadReckon.ForwardSpeed";
		o14_value = 0;
		
		o15_label = "DeadReckon.Heading";
		o15_value = 10;	
	};
	
	TimerTransitions =
	{
		count = 0;
		
		t1_to = "TargetStuff";
		t1_time = "10000";	-- ms
	};
};
addState(state);
