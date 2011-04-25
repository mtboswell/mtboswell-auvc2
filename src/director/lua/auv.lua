state =
{
	Name = "DriveForward";
	Command = "Target";
	Options =
	{
		count = 2;
		
		o1_label = "Target.DesiredHeading";
		o1_value = 333;
		
		o2_label = "Target.Type";
		o2_value = "Buoy";
	};
	
	TriggerTransitions =
	{
		count = 2;
		
		t1_label = "Orientation.Heading";
		t1_operator = "<";
		t1_value = 23;
		t1_to = "SomeOtherState";
		
		t2_label = "Target.Lost";
		t2_operator = ">=";
		t2_value = 55;
		t2_to = "STOP";
	};

	TimerTransitions =
	{
		count = 2;
		
		t1_to = "SomeOtherState";
		t1_time = 3200;
		
		t2_to = "STOP";
		t2_time = 1422;
	};
};
addState(state);

state =
{
	Name = "SomeOtherState";
	Command = "Target";
	Options =
	{
		count = 2;
		
		o1_label = "Targed.DesiredHeading";
		o1_value = 999;
		
		o2_label = "Target.Type";
		o2_value = "Buoy";
	};
	
	TriggerTransitions =
	{
		count = 2;
		
		t1_label = "Orientation.Heading";
		t1_operator = "<";
		t1_value = 5;
		t1_to = "DriveForward";
		t1_timeEnable = 10000;	-- 10 seconds
		
		t2_label = "Target.IDK";
		t2_operator = "<";
		t2_value = 3;
		t2_to = "STOP";
	};
};
addState(state);
