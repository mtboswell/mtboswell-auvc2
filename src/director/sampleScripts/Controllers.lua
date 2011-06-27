--	Params.lua
--
--	@author Carlo del Mundo <cdel@vt.edu>
--	@date 6-2-2011
--	Initializes all variables in the Parameters section
	
state =
{
	Name = "InitParams";
	Command = "DeadReckon";
	Options =
	{
		count = 41;
		o1_label = "Parameter.Compass.Yaw.Kp";
		o1_value = 1;

		o2_label = "Parameter.Compass.Yaw.Ki";
		o2_value = 0;

		o3_label = "Parameter.Compass.Yaw.Kd";
		o3_value = 0;

		o4_label = "Parameter.Depth.Kp";
		o4_value = 1;

		o5_label = "Parameter.Depth.Ki";
		o5_value = 0;

		o6_label = "Parameter.Depth.Kd";
		o6_value = 0;

		o7_label = "Parameter.IMU.YVel.Kp";
		o7_value = 1;

		o8_label = "Parameter.IMU.YVel.Ki";
		o8_value = 0;

		o9_label = "Parameter.IMU.YVel.Kd";
		o9_value = 0;

		o10_label = "Parameter.IMU.YawRate.Kp";
		o10_value = 1;

		o11_label = "Parameter.IMU.YawRate.Ki";
		o11_value = 0;

		o12_label = "Parameter.IMU.YawRate.Kd";
		o12_value = 0;

		o13_label = "Parameter.Target.Down.X.Kp";
		o13_value = 1;

		o14_label = "Parameter.Target.Down.X.Ki";
		o14_value = 0;

		o15_label = "Parameter.Target.Down.X.Kd";
		o15_value = 0;

		o16_label = "Parameter.Target.Down.Y.Kp";
		o16_value = 1;

		o17_label = "Parameter.Target.Down.Y.Ki";
		o17_value = 0;

		o18_label = "Parameter.Target.Down.Y.Kd";
		o18_value = 0;

		o19_label = "Parameter.Target.Down.Yaw.Kp";
		o19_value = 1;

		o20_label = "Parameter.Target.Down.Yaw.Ki";
		o20_value = 0;

		o21_label = "Parameter.Target.Down.Yaw.Kd";
		o21_value = 0;

		o22_label = "Parameter.Target.Forward.Y.Kp";
		o22_value = 1;

		o23_label = "Parameter.Target.Forward.Y.Ki";
		o23_value = 0;

		o24_label = "Parameter.Target.Forward.Y.Kd";
		o24_value = 0;

		o25_label = "Parameter.Target.Forward.Yaw.Kp";
		o25_value = 1;

		o26_label = "Parameter.Target.Forward.Yaw.Ki";
		o26_value = 0;

		o27_label = "Parameter.Target.Forward.Yaw.Kd";
		o27_value = 0;

		o28_label = "Parameter.Target.Forward.Z.Kp";
		o28_value = 1;

		o29_label = "Parameter.Target.Forward.Z.Ki";
		o29_value = 0;

		o30_label = "Parameter.Target.Forward.Z.Kd";
		o30_value = 0;
		
		o31_label = "Parameter.Thruster.Friction.Zero";
		o31_value = 15;
		
		o32_label = "Thrusters.LeftAngled.Gain";
		o32_value = 1;
		
		o33_label = "Thrusters.LeftFwd.Gain";
		o33_value = 1;
		
		o34_label = "Thrusters.RightAngled.Gain";
		o34_value = 1;
		
		o35_label = "Thrusters.RightFwd.Gain";
		o35_value = 1;
		
		o36_label = "Parameter.ZVelocity.Neg.Max";
		o36_value = -30;
		
		o37_label = "TargetOptions.TargetSelect";
		o37_value = 1;
		
		o38_label = "TargetData.Position.X";
		o38_value = 0;
		
		o39_label = "TargetData.Position.Y";
		o39_value = 100;
		
		o40_label = "TargetData.Position.Z";
		o40_value = 0;
		
		o41_label = "TargetData.Found";
		o41_value = 1;
	};
};
addState(state);
