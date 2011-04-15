state =
{
	Name = "DriveForward";
	Command = "Target";
	Options =
	{
		count = 2;
		
		o1_label = "Target.DesiredHeading";
		o1_value = 5;
		
		o2_label = "Target.Type";
		o2_value = "Buoy";
	};
	
	Transitions =
	{
		count = 2;
		
		t1_label = "Target.Hit";
		t1_operator = "<";
		t1_value = 23;
		
		t2_label = "Target.Lost";
		t2_operator = ">=";
		t2_value = 55;
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
		
		o1_label = "Target.DesiredHeading22222";
		o1_value = 2.3;
		
		o2_label = "Target.Type";
		o2_value = "Buoy";
	};
	
	Transitions =
	{
		count = 2;
		
		t1_label = "Target.LOL";
		t1_operator = "<";
		t1_value = 5;
		
		t2_label = "Target.IDK";
		t2_operator = "<";
		t2_value = 3;
	};
};
addState(state);
