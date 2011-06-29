--	gateScript.lua -- advanced
--
--	@author Carlo del Mundo <cdel@vt.edu>
--	@date 6-2-2011
	
state =
{
	Name = "gateScriptAdvanced";
	Command = "DeadReckon";

	TriggerTransitions = 
	{
		count = 1;

		t1_label = "Vision.Output.TargetDetected";
		t1_value = 1;
		t1_to = "Forward";
		t1_operator = "==";
	};
};
addState(state);

state =
{
	Name = "Forward";
	Command = "DeadReckon";
	Options =
	{
		count = 2;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = -35;
		
		o2_label = "TargetOptions.MaintainHeading";
		o2_value = "1";
	};
	
	TriggerTransitions =
	{
		count = 1;
		
		t1_label= "Vision.Output.TargetDetected";
		t1_value = 0;
		t1_to = "FindAndIncrementHeading";
		t1_operator = "==";
	};
};
addState(state);

state =
{
	Name = "FindAndIncrementHeading";
	Command = "DeadReckon";
	Options =
	{
		count = 3;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 0;
		
		o2_label = "TargetOptions.MaintainHeading";
		o2_value = 0;
		
		o3_label = "DeadReckon.Heading";
		o3_value = 15;	-- increment by 15 degrees
		o3_mode = 1;	-- increment mode
		o3_timeEnable = 3000;	-- 3 seconds
	};

	TriggerTransitions = 
	{
		count = 1;
		t1_label = "Vision.Output.TargetDetected";
		t1_value = 1;
		t1_to = "Forward";
		t1_operator = "==";
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "FindAndIncrementHeading";
		t1_time = 5000;	-- every 5 seconds
	};
};
addState(state);
