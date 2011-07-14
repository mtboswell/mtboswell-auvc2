/*
 * File: MotionController_data.cpp
 *
 * Real-Time Workshop code generated for Simulink model MotionController.
 *
 * Model version                        : 1.138
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jul 14 10:22:07 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jul 14 10:22:07 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotionController.h"
#include "MotionController_private.h"

/* Block parameters (auto storage) */
Parameters_MotionController MotionController_P = {
  0.0,                                 /* Variable: Compass_Yaw_Kd
                                        * Referenced by: '<S11>/Heading Derivative Gain'
                                        */
  0.0,                                 /* Variable: Compass_Yaw_Ki
                                        * Referenced by: '<S11>/Heading Integral Gain'
                                        */
  1.0,                                 /* Variable: Compass_Yaw_Kp
                                        * Referenced by: '<S11>/Heading Proportional Gain'
                                        */
  0.0,                                 /* Variable: Depth_Kd
                                        * Referenced by: '<S21>/Depth Derivative Gain'
                                        */
  0.0,                                 /* Variable: Depth_Ki
                                        * Referenced by: '<S21>/Depth Integral Gain'
                                        */
  1.0,                                 /* Variable: Depth_Kp
                                        * Referenced by: '<S21>/Depth Proportional Gain'
                                        */
  0.0,                                 /* Variable: IMU_YVel_Kd
                                        * Referenced by: '<S17>/Y-Accelerometer Derivative Gain'
                                        */
  0.0,                                 /* Variable: IMU_YVel_Ki
                                        * Referenced by: '<S17>/Y-Accelerometer Integral Gain'
                                        */
  1.0,                                 /* Variable: IMU_YVel_Kp
                                        * Referenced by: '<S17>/Y-Accelerometer Proportional Gain'
                                        */
  0.0,                                 /* Variable: IMU_YawRate_Kd
                                        * Referenced by: '<S18>/YawRate Derivative Gain'
                                        */
  0.0,                                 /* Variable: IMU_YawRate_Ki
                                        * Referenced by: '<S18>/YawRate Integral Gain'
                                        */
  1.0,                                 /* Variable: IMU_YawRate_Kp
                                        * Referenced by: '<S18>/YawRate Proportional Gain'
                                        */
  0.0,                                 /* Variable: Target_Down_X_Kd
                                        * Referenced by: '<S40>/Down X Controller'
                                        */
  0.0,                                 /* Variable: Target_Down_X_Ki
                                        * Referenced by: '<S40>/Down X Controller'
                                        */
  1.0,                                 /* Variable: Target_Down_X_Kp
                                        * Referenced by: '<S40>/Down X Controller'
                                        */
  0.0,                                 /* Variable: Target_Down_Y_Kd
                                        * Referenced by: '<S40>/Down Y Controller'
                                        */
  0.0,                                 /* Variable: Target_Down_Y_Ki
                                        * Referenced by: '<S40>/Down Y Controller'
                                        */
  1.0,                                 /* Variable: Target_Down_Y_Kp
                                        * Referenced by: '<S40>/Down Y Controller'
                                        */
  0.0,                                 /* Variable: Target_Down_Yaw_Kd
                                        * Referenced by: '<S40>/Down Yaw Controller'
                                        */
  0.0,                                 /* Variable: Target_Down_Yaw_Ki
                                        * Referenced by: '<S40>/Down Yaw Controller'
                                        */
  1.0,                                 /* Variable: Target_Down_Yaw_Kp
                                        * Referenced by: '<S40>/Down Yaw Controller'
                                        */
  0.0,                                 /* Variable: Target_Forward_Y_Kd
                                        * Referenced by: '<S41>/PID Controller with Enable2'
                                        */
  0.0,                                 /* Variable: Target_Forward_Y_Ki
                                        * Referenced by: '<S41>/PID Controller with Enable2'
                                        */
  1.0,                                 /* Variable: Target_Forward_Y_Kp
                                        * Referenced by: '<S41>/PID Controller with Enable2'
                                        */
  0.0,                                 /* Variable: Target_Forward_Yaw_Kd
                                        * Referenced by: '<S41>/PID Controller with Enable1'
                                        */
  0.0,                                 /* Variable: Target_Forward_Yaw_Ki
                                        * Referenced by: '<S41>/PID Controller with Enable1'
                                        */
  1.0,                                 /* Variable: Target_Forward_Yaw_Kp
                                        * Referenced by: '<S41>/PID Controller with Enable1'
                                        */
  0.0,                                 /* Variable: Target_Forward_Z_Kd
                                        * Referenced by: '<S48>/Derivative Gain'
                                        */
  0.0,                                 /* Variable: Target_Forward_Z_Ki
                                        * Referenced by: '<S48>/Integral Gain'
                                        */
  1.0,                                 /* Variable: Target_Forward_Z_Kp
                                        * Referenced by: '<S48>/Proportional Gain'
                                        */
  15.0,                                /* Variable: Thruster_Friction_Zero
                                        * Referenced by:
                                        *   '<S54>/Gain'
                                        *   '<S54>/Gain1'
                                        *   '<S55>/Gain'
                                        *   '<S55>/Gain1'
                                        *   '<S56>/Gain'
                                        *   '<S56>/Gain1'
                                        *   '<S57>/Gain'
                                        *   '<S57>/Gain1'
                                        */
  1.01,                                /* Variable: Thruster_LeftAngled_Gain
                                        * Referenced by: '<S4>/LeftAngled Thruster Normalize'
                                        */
  1.01,                                /* Variable: Thruster_LeftFwd_Gain
                                        * Referenced by: '<S4>/LeftFwd Thruster  Normalize'
                                        */
  1.01,                                /* Variable: Thruster_RightAngled_Gain
                                        * Referenced by: '<S4>/RightAngled Thruster Normalize'
                                        */
  1.01,                                /* Variable: Thruster_RightFwd_Gain
                                        * Referenced by: '<S4>/RightFwd Thruster Normalize'
                                        */
  -30.0                                /* Variable: ZVelocity_Neg_Max
                                        * Referenced by: '<S4>/Buoyancy  Compensation Limiter'
                                        */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
