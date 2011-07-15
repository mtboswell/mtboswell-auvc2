--	gateScript.lua
--
--	@author Carlo del Mundo <cdel@vt.edu>
--	@date 6-2-2011
	
state =
{
	Name = "gateScript";
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
		count = 1;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = -35;
	};
	
	TriggerTransitions =
	{
		count = 1;
		
		t1_label= "Vision.Output.TargetDetected";
		t1_value = 0;
		t1_to = "Listen";
		t1_operator = "==";
	};
};
addState(state);

state =
{
	Name = "Listen";
	Command = "DeadReckon";
	Options =
	{
		count = 1;
		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 0;
	};

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
