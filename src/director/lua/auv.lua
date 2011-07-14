state =
{
	Name = "State1";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		
		o1_label = "Orientation.Heading";
		o1_value = 0;
	};
	
	TriggerTransitions =
	{
		count = 1;
		
		t1_label = "Orientation.Heading";
		t1_operator = ">";
		t1_value = 23;
		t1_to = "State2";
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
		
		t1_to = "State3";
		t1_time = "10000";	-- ms
	};
};
addState(state);

state =
{
	Name = "State3";
	Command = "DeadReckon";

	Options = 
	{
		count = 1;
		
		o1_label = "Orientation.Heading";
		o1_value = 180;
	};	
};
addState(state);

state = 
{
	Name = "State4";
	Command = "DeadReckon";
	
	Options = 
	{
		count = 1;
		
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 30;
	};
};
addState(state);

state =
{
	Name = "State5";
	Command = "DeadReckon";
	
	Options = 
	{
		count = 1;
		
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 0;
	};
};
addState(state);
