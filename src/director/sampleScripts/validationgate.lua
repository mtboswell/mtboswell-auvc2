state =
{
	Name = "Init";
	Command = "Stop";
	Options =
	{
		count = 1;
		o1_label = "Mode";
		o1_value = "Stop";
	};
	
	TriggerTransitions =
	{
		count = 1;
		
		t1_label = "Mode";
		t1_operator = "==";
		t1_value = "RC";
		t1_to = "Stabilize";
	};
};
addState(state);

state =
{
	Name = "Stabilize";
	Command = "DeadReckon";
	Options =
	{
		count = 2;
		
		o1_label = "DeadReckon.Heading";
		o1_value = 30;
		o2_label = "DeadReckon.Depth";
		o2_value = 0;
		o3_label = "TargetOptions.MaintainHeading";
		o3_value = 1;

	};
	
	TriggerTransitions =
	{
		count = 1;
		
		t1_label = "Orientation.Stable";
		t1_operator = "==";
		t1_value = true;
		t1_to = "GoForGate";
	};
	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "Init";
		t1_time = "10000";	-- ms
	};
};
addState(state);

state =
{
	Name = "GoForGate";
	Command = "DeadReckon";

	Options = 
	{
		count = 1;
		
		o1_label = "DeadRecon.ForwardSpeed";
		o1_value = 30;
	};	
	TimerTransitions =
	{
		count = 1;
		
		t1_to = "StopAtGate";
		t1_time = "10000";	-- ms
	};
};
addState(state);

state = 
{
	Name = "StopAtGate";
	Command = "DeadReckon";
	
	Options = 
	{
		count = 1;
		
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 0;
	};
};
addState(state);

