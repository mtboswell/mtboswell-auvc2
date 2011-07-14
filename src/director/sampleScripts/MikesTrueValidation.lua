--	MikeTrueValidation.lua
--
--	@author Michael Valeiras
--  adapted from Carlos trueValidation.lau
--	@date 7-13-2011

state =
{
	Name = "trueValidation";
	Command = "DeadReckon";

	Options = 
	{
		count = 7;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 0;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 0;

		o3_label = "Parameter.Thruster.RightAngled.Gain";
		o3_value = 0;

		o4_label = "Parameter.Thruster.LeftAngled.Gain";
		o4_value = 0;

		o5_label = "DeadReckon.Depth";
		o5_value = -3;

		o6_label = "TargetOptions.MaintainHeading";
		o6_value = 1;

		o7_label = "Parameter.Depth.Kp";
		o7_value = 10;
	};

	TriggerTransitions = 
	{
		count = 1;
		
		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_to = "preForward";
		t1_operator = "==";
	};
};
addState(state);

state =
{
	Name = "forward";
	Command = "DeadReckon";
	Options =
	{
		count = 7;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 1.2;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 1;
		
		o3_label = "Parameter.Thruster.LeftAngled.Gain";
		o3_value = 1.5;

		o4_label = "Parameter.Thruster.RightAngled.Gain";
		o4_value = 1;

		o5_label = "Parameter.Thruster.Friction.Zero";
		o5_value = 20;

		o6_label = "DeadReckon.ForwardSpeed";
		o6_value = 8;
		
		o7_label = "DeadReckon.MaintainHeading";
		o7_value = 1;
	};
	
	TriggerTransitions = 
	{
		count = 1;
		
		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_operator = "==";
		t1_to = "reset"
	}
};
addState(state);

state =
{
	Name = "Stop";
	Command = "DeadReckon";
	Options =
	{
		count = 4;
		
      o1_label = "Parameter.Thruster.LeftFwd.Gain";
      o1_value = 0;
            
      o2_label = "Parameter.Thruster.RightFwd.Gain";
      o2_value = 0;
                        
		o3_label = "DeadReckon.ForwardSpeed";
		o3_value = 0;
		
		o4_label = "TargetOptions.MaintainHeading";
		o4_value = 0;
		
		o4_label = "DeadReckon.Depth";
		o4_value = -2;
	};
};
addState(state);

state =
{
	Name = "reset";
	Command = "DeadReckon";
	Options =
	{
		count = 4;

		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 0;
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 0;
		o3_label = "Parameter.Thruster.RightAngled.Gain";
		o3_value = 0;
		o4_label = "Parameter.Thruster.LeftAngled.Gain";
		o4_value = 0;

	};

	TriggerTransitions =
	{
		count = 1;

		t1_label = "Maestro.Start";
		t1_value = 0;
		t1_operator = "==";
		t1_to = "trueValidation"
	};
};
addState(state);

state = 
{
		Name = "preForward";
		Command = "DeadReckon";
		TriggerTransitions = 
		{
			count = 1;

			t1_label = "Maestro.Start";
			t1_value = 0;
			t1_operator = "==";
			t1_to = "forward";
		};
};
addState(state);
