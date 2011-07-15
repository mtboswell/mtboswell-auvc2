--	mikesCompetitionScript.lua
--
--	@author Michael Valeiras
--	@date 7-15-2011	
-- Maestro.start
-- Make sure you change the starting heading to face the gate
-- Note to self: What is the name of the Vision output state with the absolute heading for bouy
-- One of the flexible parts of this script is the time to go forward for the gate until backing up searching for path
--Please note the TODO's down below for things that can be improved
--When you get a chance, update the vision input iter_segment_thrush=35
state =
{
	Name = "standby";
	Command = "DeadReckon";

	--this state must reinitalize every options variable in the script
	Options = 
	{
		count = 31;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 0;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 0;
		
		o3_label = "Parameter.Thruster.LeftAngled.Gain";
		o3_value = 0;
		
		o4_label = "Parameter.Thruster.RightAngled.Gain";
		o4_value = 0;
		
		o5_label = "DeadReckon.Depth";
		o5_value = 0;

		o6_label = "TargetOptions.MaintainHeading";
		o6_value = 0;

		o7_label = "Parameter.Depth.Kp";
		o7_value = 8;

		o8_label = "DeadReckon.Heading";
		o8_value = 255;  --264; -- this needs to be changed to face the gate

		o9_label = "DeadReckon.ForwardSpeed";
		o9_value = 0;

		o10_label = "Parameter.Vision.ModeSelect";
		o10_value = 0;

		o12_label = "Parameter.Vision.blue.al";
		o12_value = 0;

		o13_label = "Parameter.Vision.blue.au";
		o13_value = 0;

		o14_label = "Parameter.Vision.blue.bl";
		o14_value = 0;

		o15_label = "Parameter.Vision.blue.bl";
		o15_value = 0;

		o16_label = "Parameter.Vision.red.al";
		o16_value = 25;

		o17_label = "Parameter.Vision.red.au";
		o17_value = 127;

		o18_label = "Parameter.Vision.red.bl";
		o18_value = 0;

		o19_label = "Parameter.Vision.red.bu";
		o19_value = 127;	

		o20_label = "Parameter.Vision.orange.al";
		o20_value = -18;
		o21_label = "Parameter.Vision.orange.au";
		o21_value = 30;
		o22_label = "Parameter.Vision.orange.bl";
		o22_value = -10;
		o23_label = "Parameter.Vision.orange.bu";
		o23_value = 70;
		o24_label = "Parameter.Vision.yellow.al";
		o24_value = -40;
		o25_label = "Parameter.Vision.yellow.au";
		o25_value = -13;
		o26_label = "Parameter.Vision.yellow.bl";
		o26_value = 30;
		o27_label = "Parameter.Vision.yellow.bu";
		o27_value = 50;
		o28_label = "Parameter.Vision.green.al";
		o28_value = -82;
		o29_label = "Parameter.Vision.green.au";
		o29_value = -40;
		o30_label = "Parameter.Vision.green.bl";
		o30_value = 9;
		o31_label = "Parameter.Vision.green.bu";
		o31_value = 56;

	};
	TriggerTransitions = 
	{
		count = 1;
		
		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_to = "start";
		t1_operator = "==";

	};
};
addState(state);

--this is the intermediate state between standby and validationGateForward to prevent over pressing the start button
state =
{
	Name = "start";
	Command = "DeadReckon";
	TriggerTransitions =
	{
		count = 1;

		t1_label = "Maestro.Start";
		t1_value = 0;
		t1_to = "validationGateForward";
		t1_operator = "==";
	};
};
addState(state);


--this is the first active state of the AUV and represents the AUV going towards and through the gate
state =
{
	Name = "validationGateForward";
	Command = "DeadReckon";
	Options =
	{
		count = 6;
		
		o1_label = "Parameter.Thruster.LeftFwd.Gain";
		o1_value = 1.1;
		
		o2_label = "Parameter.Thruster.RightFwd.Gain";
		o2_value = 1.08;
		
		o3_label = "Parameter.Thruster.LeftAngled.Gain";
		o3_value = 1.34;

		o4_label = "Parameter.Thruster.RightAngled.Gain";
		o4_value = 1.05;

		o5_label = "Parameter.Thruster.Friction.Zero";
		o5_value = 10;

		o6_label = "DeadReckon.ForwardSpeed";
		o6_value = 35;

		--Causes the AUV to look for a path while it drives
		o7_label = "Parameter.Vision.ModeSelect";
		o7_value = 2;
	
	};
	
	TriggerTransitions =
	{
		--if the start button is pushed than reset
		count = 2;
		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_to = "reset";
		t1_operator = "==";

		--found the path under validation gate. so Add Vision.Output.TargetYaw to Orientation.Heading
		t2_label = "Vision.Output.TargetDetected";
		t2_value = 1;
		t2_to = "turnToBouy";
		t2_operator = "==";

	};

	--this can be used later in case the AUV thinks it has gone too far
--	TimerTransitions =
--	{
--		count = 1;		
--		t1_to = "Stop";
--		t1_time = 38000;
--	};
};
addState(state);

--This state stops the robot from moving forward and asks it to align with the bouy path (until a stable heading)
state =
{
	Name = "turnToBouy";
	Command = "DeadReckon";
	Options = 
	{
		count = 3;

		o1_label = "DeadReckon.ForwardSpeed";
		o1_value = 0;

		o2_label = "Parameter.Vision.ModeSelect";
		o2_value = 0;

		o3_label = "DeadReckon.Heading";
		--Right now you just guess at an aboslute Heading!
		o3_value = 100;  -- TODO: This is the output of the bouy vision model. Its called AbsouleYawSomething and to calculate it you need to add the current heading to the calculated difference by bouy task.

	};

	--get out of this state when the AUV is at the requested stable heading or when the reset button is pushed or after 4 seconds
	TriggerTransitions = 
	{
		count = 2;

		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_to = "reset";
		t1_operator = "==";

		t2_label = "Orientation.Stable";
		t2_value = 1;
		t2_to = "toBouyTask";
		t2_operator = "==";

	};

	TimerTransitions = 
	{
		count = 1;		
		t1_to = "toBouyTask";
		t1_time = 5000;
	};
};
addState(state);

--This is the intermediate state between any state standyby when the green button is pushed
state =
{
	Name = "reset"; 
	Command = "DeadReckon";
	TriggerTransitions =
	{
		count = 1;
		t1_label = "Maestro.Start";
		t1_value = 0;
		t1_to = "standby";
		t1_operator = "==";

	};
};
addState(state);

state = 
{
	Name = "toBouyTask";
	Command = "DeadReckon";
	Options = 
	{
		count = 1;

		t1_label = "DeadReckon.ForwardSpeed";
		t1_value = 35; 
	};

	TriggerTransitions =
	{
		count = 1;

		t1_label = "Maestro.Start";
		t1_value = 1;
		t1_to = "reset";
		t1_operator = "==";

	};

};
addState(state);
