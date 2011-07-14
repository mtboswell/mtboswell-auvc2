--	trueValidation.lua
--
--	@author Carlo del Mundo <cdel@vt.edu>
--	@date 6-13-2011	
-- Maestro.start

state =
{
	Name = "trueValidation";
	Command = "DeadReckon";

	Options = 
	{
		count = 3;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 0;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 0;
		
		o3_label = "DeadReckon.Depth";
		o3_value = 3;
	};

	TriggerTransitions = 
	{
		count = 1;
		
		t1_label = "Maestro.Start";
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
		count = 3;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 1;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 1;
		
		o3_label = "DeadReckon.ForwardSpeed";
		o3_value = 25;
		
--		o4_label = "DeadReckon.MaintainHeading";
--		o4_value = 1;
	};
	
	TimerTransitions =
	{
		count = 1;		
		t1_to = "Stop";
		t1_time = 20000;
	};
};
addState(state);

state =
{
	Name = "Stop";
	Command = "DeadReckon";
	Options =
	{
		count = 5;
		
      o1_label = "Parameter.Thruster.LeftFwd.Gain";
      o1_value = 0;
            
      o2_label = "Parameter.Thruster.RightFwd.Gain";
      o2_value = 0;
                        
		o3_label = "DeadReckon.ForwardSpeed";
		o3_value = 0;
		
--		o4_label = "TargetOptions.MaintainHeading";
--		o4_value = 0;
		
		o5_label = "DeadReckon.Depth";
		o5_value = -2;
	};
};
addState(state);
