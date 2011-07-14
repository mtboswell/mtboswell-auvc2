/*
 * File: MotionController.cpp
 *
 * Real-Time Workshop code generated for Simulink model MotionController.
 *
 * Model version                        : 1.136
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jul 14 00:26:35 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jul 14 00:26:35 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotionController.h"
#include "MotionController_private.h"

/*
 * Initial conditions for enable system:
 *    '<S40>/Down Yaw Controller'
 *    '<S41>/PID Controller with Enable2'
 */
void MotionCo_DownYawController_Init(rtDW_DownYawController_MotionCo *localDW)
{
  /* InitializeConditions for UnitDelay: '<S47>/UD' */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S40>/Down Yaw Controller'
 *    '<S41>/PID Controller with Enable2'
 */
void Motio_DownYawController_Disable(real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW)
{
  /* Disable for Outport: '<S44>/Output' */
  (*rty_Output) = 0.0;
  localDW->DownYawController_MODE = FALSE;
}

/*
 * Start for enable system:
 *    '<S40>/Down Yaw Controller'
 *    '<S41>/PID Controller with Enable2'
 */
void MotionC_DownYawController_Start(rtDW_DownYawController_MotionCo *localDW)
{
  MotionCo_DownYawController_Init(localDW);
}

/*
 * Output and update for enable system:
 *    '<S40>/Down Yaw Controller'
 *    '<S41>/PID Controller with Enable2'
 */
void MotionControl_DownYawController(boolean_T rtu_0, const real_T *rtu_Measured,
  const real_T *rtu_Setpoint, real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW, real_T rtp_Kd, real_T rtp_Ki, real_T
  rtp_Kp)
{
  real_T rtb_Error_g;
  real_T rtb_TSamp_a0;
  if (rtu_0) {
    if (!localDW->DownYawController_MODE) {
      MotionCo_DownYawController_Init(localDW);
      localDW->DownYawController_MODE = TRUE;
    }

    /* Sum: '<S44>/Subtract' */
    rtb_Error_g = (*rtu_Setpoint) - (*rtu_Measured);

    /* SampleTimeMath: '<S47>/TSamp' incorporates:
     *  Gain: '<S44>/Derivative Gain'
     *
     * About '<S47>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_a0 = rtp_Kd * rtb_Error_g * 50.0;

    /* Sum: '<S44>/Sum' incorporates:
     *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
     *  Gain: '<S44>/Proportional Gain'
     *  Sum: '<S47>/Diff'
     *  UnitDelay: '<S47>/UD'
     */
    (*rty_Output) = (rtp_Kp * rtb_Error_g + (rtb_TSamp_a0 - localDW->UD_DSTATE))
      + localDW->DiscreteTimeIntegrator_DSTATE;

    /* Update for UnitDelay: '<S47>/UD' */
    localDW->UD_DSTATE = rtb_TSamp_a0;

    /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S44>/Integral Gain'
     */
    localDW->DiscreteTimeIntegrator_DSTATE = rtp_Ki * rtb_Error_g * 0.02 +
      localDW->DiscreteTimeIntegrator_DSTATE;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= 15.0) {
      localDW->DiscreteTimeIntegrator_DSTATE = 15.0;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <= -15.0) {
        localDW->DiscreteTimeIntegrator_DSTATE = -15.0;
      }
    }
  } else {
    if ((int32_T)localDW->DownYawController_MODE) {
      Motio_DownYawController_Disable(rty_Output, localDW);
    }
  }
}

/* Disable for referenced model: 'MotionController' */
void mr_MotionController_Disable(rtB_mr_MotionController *localB,
  rtDW_mr_MotionController *localDW)
{
  /* Disable for enable SubSystem: '<Root>/Targeting Controllers' */

  /* Disable for If: '<S3>/If' */
  localDW->If_ActiveSubsystem_b = -1;

  /* Disable for enable SubSystem: '<S40>/Down X Controller' */

  /* Disable for Outport: '<S42>/Output' */
  localB->Merge = 0.0;
  localDW->DownXController_MODE = FALSE;

  /* end of Disable for SubSystem: '<S40>/Down X Controller' */

  /* Disable for enable SubSystem: '<S40>/Down Y Controller' */

  /* Disable for Outport: '<S43>/Output' */
  localB->Merge2 = 0.0;
  localDW->DownYController_MODE = FALSE;

  /* end of Disable for SubSystem: '<S40>/Down Y Controller' */

  /* Disable for enable SubSystem: '<S40>/Down Yaw Controller' */
  Motio_DownYawController_Disable(&localB->Merge1, &localDW->DownYawController);

  /* end of Disable for SubSystem: '<S40>/Down Yaw Controller' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable' */

  /* Disable for Outport: '<S48>/Output' */
  localB->Merge3 = 0.0;
  localDW->PIDControllerwithEnable_MODE = FALSE;

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable1' */

  /* Disable for Outport: '<S49>/Output' */
  localB->Merge1 = 0.0;
  localDW->PIDControllerwithEnable1_MODE = FALSE;

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable1' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable2' */
  Motio_DownYawController_Disable(&localB->Merge2,
    &localDW->PIDControllerwithEnable2);

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable2' */

  /* Disable for ifaction SubSystem: '<S3>/Track Target' */

  /* Disable for enable SubSystem: '<S40>/Down X Controller' */

  /* Disable for Outport: '<S42>/Output' */
  localB->Merge = 0.0;
  localDW->DownXController_MODE = FALSE;

  /* end of Disable for SubSystem: '<S40>/Down X Controller' */

  /* Disable for enable SubSystem: '<S40>/Down Y Controller' */

  /* Disable for Outport: '<S43>/Output' */
  localB->Merge2 = 0.0;
  localDW->DownYController_MODE = FALSE;

  /* end of Disable for SubSystem: '<S40>/Down Y Controller' */

  /* Disable for enable SubSystem: '<S40>/Down Yaw Controller' */
  Motio_DownYawController_Disable(&localB->Merge1, &localDW->DownYawController);

  /* end of Disable for SubSystem: '<S40>/Down Yaw Controller' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable' */

  /* Disable for Outport: '<S48>/Output' */
  localB->Merge3 = 0.0;
  localDW->PIDControllerwithEnable_MODE = FALSE;

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable1' */

  /* Disable for Outport: '<S49>/Output' */
  localB->Merge1 = 0.0;
  localDW->PIDControllerwithEnable1_MODE = FALSE;

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable1' */

  /* Disable for enable SubSystem: '<S41>/PID Controller with Enable2' */
  Motio_DownYawController_Disable(&localB->Merge2,
    &localDW->PIDControllerwithEnable2);

  /* end of Disable for SubSystem: '<S41>/PID Controller with Enable2' */

  /* end of Disable for SubSystem: '<S3>/Track Target' */

  /* Disable for Outport: '<S3>/DesiredXVelocity' */
  localB->Merge = 0.0;

  /* Disable for Outport: '<S3>/DesiredYVelocity' */
  localB->Merge2 = 0.0;

  /* Disable for Outport: '<S3>/DesiredZVelocity' */
  localB->Merge3 = 0.0;

  /* Disable for Outport: '<S3>/DesiredYawRate' */
  localB->Merge1 = 0.0;
  localDW->TargetingControllers_MODE = FALSE;

  /* end of Disable for SubSystem: '<Root>/Targeting Controllers' */

  /* Disable for If: '<S5>/If' */
  localDW->If_ActiveSubsystem = -1;

  /* Disable for ifaction SubSystem: '<S5>/Maintain Desired Yaw' */

  /* Disable for If: '<S10>/If' */
  localDW->If_ActiveSubsystem_l = -1;

  /* Disable for ifaction SubSystem: '<S10>/BigError S1' */

  /* Disable for Outport: '<S14>/Out2' */
  localB->Constant1_e = 0.0;

  /* end of Disable for SubSystem: '<S10>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */

  /* Disable for Outport: '<S15>/Out2' */
  localB->Constant1 = 0.0;

  /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */

  /* end of Disable for SubSystem: '<S5>/Maintain Desired Yaw' */
}

/* Start for referenced model: 'MotionController' */
void mr_MotionController_Start(rtB_mr_MotionController *localB,
  rtDW_mr_MotionController *localDW)
{
  /* Start for enable SubSystem: '<Root>/Targeting Controllers' */

  /* Start for If: '<S3>/If' */
  localDW->If_ActiveSubsystem_b = -1;

  /* Start for ifaction SubSystem: '<S3>/Track Target' */

  /* Start for enable SubSystem: '<S40>/Down X Controller' */

  /* InitializeConditions for UnitDelay: '<S45>/UD' */
  localDW->UD_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0;

  /* end of Start for SubSystem: '<S40>/Down X Controller' */

  /* Start for enable SubSystem: '<S40>/Down Y Controller' */

  /* InitializeConditions for UnitDelay: '<S46>/UD' */
  localDW->UD_DSTATE_je = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTAT_bx = 0.0;

  /* end of Start for SubSystem: '<S40>/Down Y Controller' */

  /* Start for enable SubSystem: '<S40>/Down Yaw Controller' */
  MotionC_DownYawController_Start(&localDW->DownYawController);

  /* end of Start for SubSystem: '<S40>/Down Yaw Controller' */

  /* Start for enable SubSystem: '<S41>/PID Controller with Enable' */

  /* InitializeConditions for UnitDelay: '<S51>/UD' */
  localDW->UD_DSTATE_j = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_b = 0.0;

  /* end of Start for SubSystem: '<S41>/PID Controller with Enable' */

  /* Start for enable SubSystem: '<S41>/PID Controller with Enable1' */

  /* InitializeConditions for UnitDelay: '<S52>/UD' */
  localDW->UD_DSTATE_d = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;

  /* end of Start for SubSystem: '<S41>/PID Controller with Enable1' */

  /* Start for enable SubSystem: '<S41>/PID Controller with Enable2' */
  MotionC_DownYawController_Start(&localDW->PIDControllerwithEnable2);

  /* end of Start for SubSystem: '<S41>/PID Controller with Enable2' */

  /* end of Start for SubSystem: '<S3>/Track Target' */

  /* end of Start for SubSystem: '<Root>/Targeting Controllers' */

  /* Start for If: '<S5>/If' */
  localDW->If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S5>/Maintain Desired Yaw' */

  /* Start for If: '<S10>/If' */
  localDW->If_ActiveSubsystem_l = -1;

  /* InitializeConditions for UnitDelay: '<S16>/UD' */
  localDW->UD_DSTATE_jj = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' */
  localDW->HeadingDiscreteTimeIntegrator_l = 0.0;

  /* end of Start for SubSystem: '<S5>/Maintain Desired Yaw' */

  /* Start for ifaction SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity' */

  /* InitializeConditions for UnitDelay: '<S20>/UD' */
  localDW->UD_DSTATE_jn = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' */
  localDW->HeadingDiscreteTimeIntegrator_D = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0;

  /* InitializeConditions for UnitDelay: '<S19>/UD' */
  localDW->UD_DSTATE_i = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
  localDW->DepthDiscreteTimeIntegrator_D_a = 0.0;

  /* end of Start for SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity' */

  /* Constant: '<S5>/Not Controlled  Y Value' */
  localB->MergeDesiredYVelocity = 0.0;
}

/* Output and update for referenced model: 'MotionController' */
void mr_MotionController(const real_T *rtu_TargetSelect, const real_T
  *rtu_TargetFound, const uint8_T *rtu_MaintainHeading, const real_T
  *rtu_TargetX, const real_T *rtu_TargetY, const real_T *rtu_TargetZ, const
  real_T *rtu_TargetYaw, const real_T *rtu_DesiredTargetX, const real_T
  *rtu_DesiredTargetY, const real_T *rtu_DesiredTargetZ, const real_T
  *rtu_DesiredTargetYaw, const real_T *rtu_MeasuredZ, const real_T
  *rtu_MeasuredYAccel, const real_T *rtu_MeasuredYaw, const real_T
  *rtu_MeasuredYawRate, const real_T *rtu_DesiredZ, const real_T
  *rtu_DesiredXVelocity, const real_T *rtu_DesiredYaw, real_T *rty_LeftFwd,
  real_T *rty_RightFwd, real_T *rty_LeftAngled, real_T *rty_RightAngled,
  rtB_mr_MotionController *localB, rtDW_mr_MotionController *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2;
  real_T rtb_TSamp;
  real_T rtb_DepthIntegralGain;
  real_T rtb_Add1;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_YAccelerometerIntegralGain;
  real_T rtb_MergeDesiredYawRate;
  uint8_T rtb_Compare;
  uint8_T rtb_Compare_d;
  real_T rtb_Error_n;
  real_T rtb_TSamp_ac;

  /* Outputs for enable SubSystem: '<Root>/Targeting Controllers' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if ((*rtu_TargetSelect) > 0.0) {
    if (!localDW->TargetingControllers_MODE) {
      localDW->TargetingControllers_MODE = TRUE;
    }

    /* If: '<S3>/If' incorporates:
     *  ActionPort: '<S23>/Action Port'
     *  ActionPort: '<S24>/Action Port'
     *  SubSystem: '<S3>/Search for  Target'
     *  SubSystem: '<S3>/Track Target'
     */
    rtPrevAction = localDW->If_ActiveSubsystem_b;
    if ((*rtu_TargetFound) > 0.0) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    localDW->If_ActiveSubsystem_b = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for enable SubSystem: '<S40>/Down X Controller' */

      /* Disable for Outport: '<S42>/Output' */
      localB->Merge = 0.0;
      localDW->DownXController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down X Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Y Controller' */

      /* Disable for Outport: '<S43>/Output' */
      localB->Merge2 = 0.0;
      localDW->DownYController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&localB->Merge1,
        &localDW->DownYawController);

      /* end of Disable for SubSystem: '<S40>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for Outport: '<S48>/Output' */
      localB->Merge3 = 0.0;
      localDW->PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for Outport: '<S49>/Output' */
      localB->Merge1 = 0.0;
      localDW->PIDControllerwithEnable1_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&localB->Merge2,
        &localDW->PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable2' */
    }

    switch (rtAction) {
     case 0:
      /* RelationalOperator: '<S37>/Compare' incorporates:
       *  Constant: '<S37>/Constant'
       */
      rtb_Compare = ((*rtu_TargetSelect) == 1.0);

      /* RelationalOperator: '<S39>/Compare' incorporates:
       *  Constant: '<S39>/Constant'
       */
      rtb_Compare_d = ((*rtu_MaintainHeading) <= 0);

      /* Outputs for enable SubSystem: '<S40>/Down X Controller' incorporates:
       *  EnablePort: '<S42>/Enable'
       */
      if ((*rtu_TargetSelect) > 0.0) {
        if (!localDW->DownXController_MODE) {
          /* InitializeConditions for UnitDelay: '<S45>/UD' */
          localDW->UD_DSTATE_p = 0.0;

          /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
          localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0;
          localDW->DownXController_MODE = TRUE;
        }

        /* Sum: '<S42>/Subtract' incorporates:
         *  Gain: '<S40>/Gain1'
         */
        rtb_Error_n = (*rtu_DesiredTargetX) - (-(*rtu_TargetX));

        /* SampleTimeMath: '<S45>/TSamp' incorporates:
         *  Gain: '<S42>/Derivative Gain'
         *
         * About '<S45>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_ac = 0.0 * rtb_Error_n * 50.0;

        /* Sum: '<S42>/Sum' incorporates:
         *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
         *  Gain: '<S42>/Proportional Gain'
         *  Sum: '<S45>/Diff'
         *  UnitDelay: '<S45>/UD'
         */
        localB->Merge = ((rtb_TSamp_ac - localDW->UD_DSTATE_p) + rtb_Error_n) +
          localDW->DiscreteTimeIntegrator_DSTATE_i;

        /* Update for UnitDelay: '<S45>/UD' */
        localDW->UD_DSTATE_p = rtb_TSamp_ac;

        /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
         *  Gain: '<S42>/Integral Gain'
         */
        localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0 * rtb_Error_n * 0.02 +
          localDW->DiscreteTimeIntegrator_DSTATE_i;
        if (localDW->DiscreteTimeIntegrator_DSTATE_i >= 15.0) {
          localDW->DiscreteTimeIntegrator_DSTATE_i = 15.0;
        } else {
          if (localDW->DiscreteTimeIntegrator_DSTATE_i <= -15.0) {
            localDW->DiscreteTimeIntegrator_DSTATE_i = -15.0;
          }
        }
      } else {
        if ((int32_T)localDW->DownXController_MODE) {
          /* Disable for Outport: '<S42>/Output' */
          localB->Merge = 0.0;
          localDW->DownXController_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S40>/Down X Controller' */

      /* Outputs for enable SubSystem: '<S40>/Down Y Controller' incorporates:
       *  EnablePort: '<S43>/Enable'
       */
      if ((*rtu_TargetSelect) > 0.0) {
        if (!localDW->DownYController_MODE) {
          /* InitializeConditions for UnitDelay: '<S46>/UD' */
          localDW->UD_DSTATE_je = 0.0;

          /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
          localDW->DiscreteTimeIntegrator_DSTAT_bx = 0.0;
          localDW->DownYController_MODE = TRUE;
        }

        /* Sum: '<S43>/Subtract' */
        rtb_Error_n = (*rtu_DesiredTargetY) - (*rtu_TargetY);

        /* SampleTimeMath: '<S46>/TSamp' incorporates:
         *  Gain: '<S43>/Derivative Gain'
         *
         * About '<S46>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_ac = 0.0 * rtb_Error_n * 50.0;

        /* Sum: '<S43>/Sum' incorporates:
         *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
         *  Gain: '<S43>/Proportional Gain'
         *  Sum: '<S46>/Diff'
         *  UnitDelay: '<S46>/UD'
         */
        localB->Merge2 = ((rtb_TSamp_ac - localDW->UD_DSTATE_je) + rtb_Error_n)
          + localDW->DiscreteTimeIntegrator_DSTAT_bx;

        /* Update for UnitDelay: '<S46>/UD' */
        localDW->UD_DSTATE_je = rtb_TSamp_ac;

        /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
         *  Gain: '<S43>/Integral Gain'
         */
        localDW->DiscreteTimeIntegrator_DSTAT_bx = 0.0 * rtb_Error_n * 0.02 +
          localDW->DiscreteTimeIntegrator_DSTAT_bx;
        if (localDW->DiscreteTimeIntegrator_DSTAT_bx >= 15.0) {
          localDW->DiscreteTimeIntegrator_DSTAT_bx = 15.0;
        } else {
          if (localDW->DiscreteTimeIntegrator_DSTAT_bx <= -15.0) {
            localDW->DiscreteTimeIntegrator_DSTAT_bx = -15.0;
          }
        }
      } else {
        if ((int32_T)localDW->DownYController_MODE) {
          /* Disable for Outport: '<S43>/Output' */
          localB->Merge2 = 0.0;
          localDW->DownYController_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S40>/Down Y Controller' */

      /* Logic: '<S24>/Logical Operator1' incorporates:
       *  Constant: '<S38>/Constant'
       *  RelationalOperator: '<S38>/Compare'
       */
      rtb_LogicalOperator1 = (((*rtu_TargetSelect) == 2.0) && (rtb_Compare_d !=
        0));

      /* Outputs for enable SubSystem: '<S40>/Down Yaw Controller' incorporates:
       *  EnablePort: '<S44>/Enable'
       */
      MotionControl_DownYawController(rtb_LogicalOperator1, &(*rtu_TargetYaw),
                                      &(*rtu_DesiredTargetYaw), &localB->Merge1,
        &localDW->DownYawController, 0.0, 0.0, 1.0);

      /* end of Outputs for SubSystem: '<S40>/Down Yaw Controller' */

      /* Outputs for enable SubSystem: '<S41>/PID Controller with Enable' incorporates:
       *  EnablePort: '<S48>/Enable'
       */
      if (rtb_Compare > 0) {
        if (!localDW->PIDControllerwithEnable_MODE) {
          /* InitializeConditions for UnitDelay: '<S51>/UD' */
          localDW->UD_DSTATE_j = 0.0;

          /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
          localDW->DiscreteTimeIntegrator_DSTATE_b = 0.0;
          localDW->PIDControllerwithEnable_MODE = TRUE;
        }

        /* Sum: '<S48>/Subtract' */
        rtb_Error_n = (*rtu_DesiredTargetZ) - (*rtu_TargetZ);

        /* SampleTimeMath: '<S51>/TSamp' incorporates:
         *  Gain: '<S48>/Derivative Gain'
         *
         * About '<S51>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_ac = 0.0 * rtb_Error_n * 50.0;

        /* Sum: '<S48>/Sum' incorporates:
         *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
         *  Gain: '<S48>/Proportional Gain'
         *  Sum: '<S51>/Diff'
         *  UnitDelay: '<S51>/UD'
         */
        localB->Merge3 = ((rtb_TSamp_ac - localDW->UD_DSTATE_j) + rtb_Error_n) +
          localDW->DiscreteTimeIntegrator_DSTATE_b;

        /* Update for UnitDelay: '<S51>/UD' */
        localDW->UD_DSTATE_j = rtb_TSamp_ac;

        /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
         *  Gain: '<S48>/Integral Gain'
         */
        localDW->DiscreteTimeIntegrator_DSTATE_b = 0.0 * rtb_Error_n * 0.02 +
          localDW->DiscreteTimeIntegrator_DSTATE_b;
        if (localDW->DiscreteTimeIntegrator_DSTATE_b >= 15.0) {
          localDW->DiscreteTimeIntegrator_DSTATE_b = 15.0;
        } else {
          if (localDW->DiscreteTimeIntegrator_DSTATE_b <= -15.0) {
            localDW->DiscreteTimeIntegrator_DSTATE_b = -15.0;
          }
        }
      } else {
        if ((int32_T)localDW->PIDControllerwithEnable_MODE) {
          /* Disable for Outport: '<S48>/Output' */
          localB->Merge3 = 0.0;
          localDW->PIDControllerwithEnable_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S41>/PID Controller with Enable' */

      /* Outputs for enable SubSystem: '<S41>/PID Controller with Enable1' incorporates:
       *  EnablePort: '<S49>/Enable'
       *  Logic: '<S24>/Logical Operator'
       */
      if ((rtb_Compare != 0) && (rtb_Compare_d != 0)) {
        if (!localDW->PIDControllerwithEnable1_MODE) {
          /* InitializeConditions for UnitDelay: '<S52>/UD' */
          localDW->UD_DSTATE_d = 0.0;

          /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
          localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
          localDW->PIDControllerwithEnable1_MODE = TRUE;
        }

        /* Sum: '<S49>/Subtract' incorporates:
         *  Gain: '<S41>/Gain'
         */
        rtb_Error_n = (*rtu_DesiredTargetYaw) - (-(*rtu_TargetYaw));

        /* SampleTimeMath: '<S52>/TSamp' incorporates:
         *  Gain: '<S49>/Derivative Gain'
         *
         * About '<S52>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_ac = 0.0 * rtb_Error_n * 50.0;

        /* Sum: '<S49>/Sum' incorporates:
         *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
         *  Gain: '<S49>/Proportional Gain'
         *  Sum: '<S52>/Diff'
         *  UnitDelay: '<S52>/UD'
         */
        localB->Merge1 = ((rtb_TSamp_ac - localDW->UD_DSTATE_d) + rtb_Error_n) +
          localDW->DiscreteTimeIntegrator_DSTATE;

        /* Update for UnitDelay: '<S52>/UD' */
        localDW->UD_DSTATE_d = rtb_TSamp_ac;

        /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
         *  Gain: '<S49>/Integral Gain'
         */
        localDW->DiscreteTimeIntegrator_DSTATE = 0.0 * rtb_Error_n * 0.02 +
          localDW->DiscreteTimeIntegrator_DSTATE;
        if (localDW->DiscreteTimeIntegrator_DSTATE >= 15.0) {
          localDW->DiscreteTimeIntegrator_DSTATE = 15.0;
        } else {
          if (localDW->DiscreteTimeIntegrator_DSTATE <= -15.0) {
            localDW->DiscreteTimeIntegrator_DSTATE = -15.0;
          }
        }
      } else {
        if ((int32_T)localDW->PIDControllerwithEnable1_MODE) {
          /* Disable for Outport: '<S49>/Output' */
          localB->Merge1 = 0.0;
          localDW->PIDControllerwithEnable1_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S41>/PID Controller with Enable1' */

      /* Logic: '<S24>/Logical Operator2' */
      rtb_LogicalOperator2 = ((rtb_Compare != 0) && ((*rtu_MaintainHeading) != 0));

      /* Outputs for enable SubSystem: '<S41>/PID Controller with Enable2' */
      MotionControl_DownYawController(rtb_LogicalOperator2, &(*rtu_TargetY),
        &(*rtu_DesiredTargetY), &localB->Merge2,
        &localDW->PIDControllerwithEnable2, 0.0, 0.0, 1.0);

      /* end of Outputs for SubSystem: '<S41>/PID Controller with Enable2' */
      break;

     case 1:
      /* If: '<S23>/If' incorporates:
       *  ActionPort: '<S25>/Action Port'
       *  ActionPort: '<S26>/Action Port'
       *  SubSystem: '<S23>/Find Downward Target'
       *  SubSystem: '<S23>/Find Forward Target'
       */
      if ((*rtu_TargetSelect) == 1.0) {
        /* Embedded MATLAB: '<S26>/Embedded MATLAB Function' incorporates:
         *  DataStoreRead: '<S32>/Data Store Read'
         */
        /* Embedded MATLAB Function 'Targeting Controllers/Search for  Target/Find Forward Target/Embedded MATLAB Function': '<S31>:1' */
        /* '<S31>:1:4' */
        /* limit how far it turns to 45 degrees */
        if (fabs((*rtu_MeasuredYaw) - localDW->A_l) <= 45.0) {
          /* '<S31>:1:8' */
          /* '<S31>:1:9' */
          localB->Merge1 = 5.0;

          /*  assuming degrees per second */
        } else {
          /* '<S31>:1:11' */
          localB->Merge1 = -5.0;
        }

        /* '<S31>:1:14' */
        localB->Merge = 0.0;

        /* '<S31>:1:15' */
        localB->Merge2 = 0.0;

        /* If: '<S33>/If1' incorporates:
         *  ActionPort: '<S35>/Action Port'
         *  ActionPort: '<S36>/Action Port'
         *  SubSystem: '<S33>/If Action Subsystem1'
         *  SubSystem: '<S33>/If Action Subsystem2'
         */
        if (0.0 > 0.0) {
          /* Constant: '<S35>/Constant' */
          rtb_Error_n = 0.0;
        } else {
          /* Inport: '<S36>/In1' incorporates:
           *  Memory: '<S33>/Memory'
           */
          rtb_Error_n = localDW->Memory_PreviousInput_f;
        }

        /* If: '<S33>/If' incorporates:
         *  ActionPort: '<S34>/Action Port'
         *  Logic: '<S33>/Logical Operator'
         *  SubSystem: '<S33>/If Action Subsystem'
         */
        if ((rtb_Error_n != 0.0) ^ ((*rtu_MeasuredYaw) != 0.0)) {
          /* DataStoreWrite: '<S34>/Data Store Write' */
          localDW->A_l = (*rtu_MeasuredYaw);
        }

        /* Update for Memory: '<S33>/Memory' */
        localDW->Memory_PreviousInput_f = (*rtu_MeasuredYaw);
      } else {
        /* Embedded MATLAB: '<S25>/Embedded MATLAB Function' incorporates:
         *  DataStoreRead: '<S28>/Data Store Read'
         */
        /* Embedded MATLAB Function 'Targeting Controllers/Search for  Target/Find Downward Target/Embedded MATLAB Function': '<S27>:1' */
        /* first move right, then back, then left, then forward */
        /* hoping to complete a square */
        /* intentions are to not turn the vehicle around (spinning in a  */
        /*   circle could cause the vehicle to follow a path in the wrong */
        /*   direction) */
        if (localDW->A <= 4.0) {
          /* '<S27>:1:11' */
          /* '<S27>:1:12' */
          localB->Merge = 0.0;

          /* '<S27>:1:13' */
          localB->Merge2 = 25.0;

          /* units? assuming percent power */
        } else if (localDW->A <= 9.0) {
          /* '<S27>:1:14' */
          /* '<S27>:1:15' */
          localB->Merge = -25.0;

          /* '<S27>:1:16' */
          localB->Merge2 = 0.0;
        } else if (localDW->A <= 14.0) {
          /* '<S27>:1:17' */
          /* '<S27>:1:18' */
          localB->Merge = 0.0;

          /* '<S27>:1:19' */
          localB->Merge2 = -25.0;
        } else if (localDW->A <= 19.0) {
          /* '<S27>:1:20' */
          /* '<S27>:1:21' */
          localB->Merge = 25.0;

          /* '<S27>:1:22' */
          localB->Merge2 = 0.0;
        } else {
          /* '<S27>:1:26' */
          localB->Merge = 0.0;

          /* '<S27>:1:27' */
          localB->Merge2 = 0.0;
        }

        /* If: '<S29>/If' incorporates:
         *  ActionPort: '<S30>/Action Port'
         *  Logic: '<S29>/Logical Operator'
         *  Memory: '<S29>/Memory'
         *  SubSystem: '<S29>/If Action Subsystem'
         */
        if ((localDW->Memory_PreviousInput != 0.0) ^ (0.0 != 0.0)) {
          /* DataStoreWrite: '<S30>/Data Store Write' incorporates:
           *  Constant: '<S30>/Constant'
           */
          localDW->A = 0.0;
        }

        /* Constant: '<S25>/Constant' */
        localB->Merge1 = 0.0;

        /* Update for Memory: '<S29>/Memory' */
        localDW->Memory_PreviousInput = 0.0;
      }

      /* Constant: '<S23>/Constant' */
      localB->Merge3 = 0.0;
      break;
    }
  } else {
    if ((int32_T)localDW->TargetingControllers_MODE) {
      /* Disable for If: '<S3>/If' */
      localDW->If_ActiveSubsystem_b = -1;

      /* Disable for enable SubSystem: '<S40>/Down X Controller' */

      /* Disable for Outport: '<S42>/Output' */
      localB->Merge = 0.0;
      localDW->DownXController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down X Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Y Controller' */

      /* Disable for Outport: '<S43>/Output' */
      localB->Merge2 = 0.0;
      localDW->DownYController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&localB->Merge1,
        &localDW->DownYawController);

      /* end of Disable for SubSystem: '<S40>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for Outport: '<S48>/Output' */
      localB->Merge3 = 0.0;
      localDW->PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for Outport: '<S49>/Output' */
      localB->Merge1 = 0.0;
      localDW->PIDControllerwithEnable1_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&localB->Merge2,
        &localDW->PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable2' */

      /* Disable for ifaction SubSystem: '<S3>/Track Target' */

      /* Disable for enable SubSystem: '<S40>/Down X Controller' */

      /* Disable for Outport: '<S42>/Output' */
      localB->Merge = 0.0;
      localDW->DownXController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down X Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Y Controller' */

      /* Disable for Outport: '<S43>/Output' */
      localB->Merge2 = 0.0;
      localDW->DownYController_MODE = FALSE;

      /* end of Disable for SubSystem: '<S40>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S40>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&localB->Merge1,
        &localDW->DownYawController);

      /* end of Disable for SubSystem: '<S40>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for Outport: '<S48>/Output' */
      localB->Merge3 = 0.0;
      localDW->PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for Outport: '<S49>/Output' */
      localB->Merge1 = 0.0;
      localDW->PIDControllerwithEnable1_MODE = FALSE;

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S41>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&localB->Merge2,
        &localDW->PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S41>/PID Controller with Enable2' */

      /* end of Disable for SubSystem: '<S3>/Track Target' */

      /* Disable for Outport: '<S3>/DesiredXVelocity' */
      localB->Merge = 0.0;

      /* Disable for Outport: '<S3>/DesiredYVelocity' */
      localB->Merge2 = 0.0;

      /* Disable for Outport: '<S3>/DesiredZVelocity' */
      localB->Merge3 = 0.0;

      /* Disable for Outport: '<S3>/DesiredYawRate' */
      localB->Merge1 = 0.0;
      localDW->TargetingControllers_MODE = FALSE;
    }
  }

  /* end of Outputs for SubSystem: '<Root>/Targeting Controllers' */

  /* Sum: '<Root>/Add' */
  rtb_Add1 = localB->Merge + (*rtu_DesiredXVelocity);

  /* Sum: '<S5>/Subtract' */
  rtb_Error_n = (*rtu_DesiredYaw) - (*rtu_MeasuredYaw);

  /* If: '<S5>/If' incorporates:
   *  ActionPort: '<S7>/Action Port'
   *  ActionPort: '<S8>/Action Port'
   *  SubSystem: '<S5>/Maintain Desired Yaw'
   *  SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity'
   */
  rtPrevAction = localDW->If_ActiveSubsystem;
  if ((*rtu_MaintainHeading) == 0) {
    rtAction = 0;
  } else {
    rtAction = 1;
  }

  localDW->If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S10>/If' */
    localDW->If_ActiveSubsystem_l = -1;

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */

    /* Disable for Outport: '<S14>/Out2' */
    localB->Constant1_e = 0.0;

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */

    /* Disable for Outport: '<S15>/Out2' */
    localB->Constant1 = 0.0;

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for UnitDelay: '<S16>/UD' */
      localDW->UD_DSTATE_jj = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' */
      localDW->HeadingDiscreteTimeIntegrator_l = 0.0;
    }

    /* If: '<S10>/If' incorporates:
     *  ActionPort: '<S14>/Action Port'
     *  ActionPort: '<S15>/Action Port'
     *  SubSystem: '<S10>/BigError S1'
     *  SubSystem: '<S10>/BigNegativeError S2'
     */
    rtPrevAction = localDW->If_ActiveSubsystem_l;
    rtAction = -1;
    if (rtb_Error_n > 180.0) {
      rtAction = 0;
    } else {
      if (rtb_Error_n < -180.0) {
        rtAction = 1;
      }
    }

    localDW->If_ActiveSubsystem_l = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S14>/Out2' */
        localB->Constant1_e = 0.0;
        break;

       case 1:
        /* Disable for Outport: '<S15>/Out2' */
        localB->Constant1 = 0.0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Sum: '<S14>/Add' incorporates:
       *  Constant: '<S14>/Constant'
       */
      localB->Add_l = rtb_Error_n - 360.0;

      /* Constant: '<S14>/Constant1' */
      localB->Constant1_e = 1.0;
      break;

     case 1:
      /* Sum: '<S15>/Add' incorporates:
       *  Constant: '<S15>/Constant'
       */
      localB->Add = rtb_Error_n + 360.0;

      /* Constant: '<S15>/Constant1' */
      localB->Constant1 = 2.0;
      break;
    }

    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Sum: '<S10>/Add2'
     */
    switch ((int32_T)((1.0 + localB->Constant1_e) + localB->Constant1)) {
     case 1:
      break;

     case 2:
      rtb_Error_n = localB->Add_l;
      break;

     default:
      rtb_Error_n = localB->Add;
      break;
    }

    /* Gain: '<S9>/Saturation Angle' incorporates:
     *  Constant: '<S13>/one'
     *  Constant: '<S13>/one1'
     *  Gain: '<S13>/Gain'
     *  Gain: '<S13>/Gain1'
     *  Gain: '<S9>/1//Saturation Angle'
     *  Math: '<S13>/Exp'
     *  Math: '<S13>/Reciprocal'
     *  Sum: '<S13>/Sum'
     *  Sum: '<S13>/Sum1'
     *
     * About '<S13>/Exp':
     *  Operator: exp
     *
     * About '<S13>/Reciprocal':
     *  Operator: reciprocal
     */
    rtb_Error_n = (1.0 / (exp(0.022222222222222223 * rtb_Error_n * -2.0) + 1.0) *
                   2.0 - 1.0) * 45.0;

    /* SampleTimeMath: '<S16>/TSamp' incorporates:
     *  Gain: '<S11>/Heading Derivative Gain'
     *
     * About '<S16>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_ac = 0.0 * rtb_Error_n * 50.0;

    /* Sum: '<S11>/Sum' incorporates:
     *  DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator'
     *  Sum: '<S16>/Diff'
     *  UnitDelay: '<S16>/UD'
     */
    rtb_MergeDesiredYawRate = ((rtb_TSamp_ac - localDW->UD_DSTATE_jj) +
      rtb_Error_n) + localDW->HeadingDiscreteTimeIntegrator_l;

    /* Update for UnitDelay: '<S16>/UD' */
    localDW->UD_DSTATE_jj = rtb_TSamp_ac;

    /* Update for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S11>/Heading Integral Gain'
     */
    localDW->HeadingDiscreteTimeIntegrator_l = 0.0 * rtb_Error_n * 0.02 +
      localDW->HeadingDiscreteTimeIntegrator_l;
    if (localDW->HeadingDiscreteTimeIntegrator_l >= 15.0) {
      localDW->HeadingDiscreteTimeIntegrator_l = 15.0;
    } else {
      if (localDW->HeadingDiscreteTimeIntegrator_l <= -15.0) {
        localDW->HeadingDiscreteTimeIntegrator_l = -15.0;
      }
    }
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for UnitDelay: '<S20>/UD' */
      localDW->UD_DSTATE_jn = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' */
      localDW->HeadingDiscreteTimeIntegrator_D = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
      localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0;

      /* InitializeConditions for UnitDelay: '<S19>/UD' */
      localDW->UD_DSTATE_i = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
      localDW->DepthDiscreteTimeIntegrator_D_a = 0.0;
    }

    /* SampleTimeMath: '<S20>/TSamp' incorporates:
     *  Gain: '<S18>/YawRate Derivative Gain'
     *
     * About '<S20>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Error_n = 0.0 * (*rtu_MeasuredYawRate) * 50.0;

    /* Sum: '<S18>/Sum' incorporates:
     *  DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator'
     *  Sum: '<S20>/Diff'
     *  UnitDelay: '<S20>/UD'
     */
    rtb_MergeDesiredYawRate = ((rtb_Error_n - localDW->UD_DSTATE_jn) +
      (*rtu_MeasuredYawRate)) + localDW->HeadingDiscreteTimeIntegrator_D;

    /* SampleTimeMath: '<S19>/TSamp' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     *  Gain: '<S17>/Y-Accelerometer Derivative Gain'
     *
     * About '<S19>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_ac = 0.0 * localDW->DiscreteTimeIntegrator_DSTATE_d * 50.0;

    /* Sum: '<S17>/Sum' incorporates:
     *  DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     *  Sum: '<S19>/Diff'
     *  UnitDelay: '<S19>/UD'
     */
    localB->MergeDesiredYVelocity = ((rtb_TSamp_ac - localDW->UD_DSTATE_i) +
      localDW->DiscreteTimeIntegrator_DSTATE_d) +
      localDW->DepthDiscreteTimeIntegrator_D_a;

    /* Gain: '<S17>/Y-Accelerometer Integral Gain' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    rtb_YAccelerometerIntegralGain = 0.0 *
      localDW->DiscreteTimeIntegrator_DSTATE_d;

    /* Update for UnitDelay: '<S20>/UD' */
    localDW->UD_DSTATE_jn = rtb_Error_n;

    /* Update for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S18>/YawRate Integral Gain'
     */
    localDW->HeadingDiscreteTimeIntegrator_D = 0.0 * (*rtu_MeasuredYawRate) *
      0.02 + localDW->HeadingDiscreteTimeIntegrator_D;
    if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
    } else {
      if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
        localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
      }
    }

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE_d = 0.02 * (*rtu_MeasuredYAccel) +
      localDW->DiscreteTimeIntegrator_DSTATE_d;
    if (localDW->DiscreteTimeIntegrator_DSTATE_d >= 10.0) {
      localDW->DiscreteTimeIntegrator_DSTATE_d = 10.0;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE_d <= -10.0) {
        localDW->DiscreteTimeIntegrator_DSTATE_d = -10.0;
      }
    }

    /* Update for UnitDelay: '<S19>/UD' */
    localDW->UD_DSTATE_i = rtb_TSamp_ac;

    /* Update for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
    localDW->DepthDiscreteTimeIntegrator_D_a = 0.02 *
      rtb_YAccelerometerIntegralGain + localDW->DepthDiscreteTimeIntegrator_D_a;
    if (localDW->DepthDiscreteTimeIntegrator_D_a >= 10.0) {
      localDW->DepthDiscreteTimeIntegrator_D_a = 10.0;
    } else {
      if (localDW->DepthDiscreteTimeIntegrator_D_a <= -10.0) {
        localDW->DepthDiscreteTimeIntegrator_D_a = -10.0;
      }
    }
    break;
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  if ((*rtu_TargetSelect) != 0.0) {
    rtb_Error_n = 0.0;
  } else {
    rtb_Error_n = rtb_MergeDesiredYawRate;
  }

  /* Sum: '<Root>/Add1' */
  rtb_Error_n += localB->Merge1;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (!((*rtu_TargetSelect) != 0.0)) {
    rtb_MergeDesiredYawRate = 0.0;
  }

  /* Sum: '<S6>/Add' */
  rtb_YAccelerometerIntegralGain = (*rtu_DesiredZ) - (*rtu_MeasuredZ);

  /* Gain: '<S21>/Depth Proportional Gain' */
  rtb_TSamp_ac = 6.0 * rtb_YAccelerometerIntegralGain;

  /* SampleTimeMath: '<S22>/TSamp' incorporates:
   *  Gain: '<S21>/Depth Derivative Gain'
   *
   * About '<S22>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = 0.0 * rtb_YAccelerometerIntegralGain * 50.0;

  /* Gain: '<S21>/Depth Integral Gain' */
  rtb_DepthIntegralGain = 0.0 * rtb_YAccelerometerIntegralGain;

  /* Sum: '<S4>/Add' */
  rtb_YAccelerometerIntegralGain = rtb_Add1 + rtb_Error_n;

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtb_Add1 += -rtb_Error_n;

  /* Gain: '<S4>/LeftFwd Thruster  Normalize' incorporates:
   *  Gain: '<S55>/Gain'
   *  Gain: '<S55>/Gain1'
   *  Signum: '<S55>/Sign'
   *  Sum: '<S55>/Sum'
   */
  (*rty_LeftFwd) = ((rtb_YAccelerometerIntegralGain < 0.0 ? -1.0 :
                     rtb_YAccelerometerIntegralGain > 0.0 ? 1.0 :
                     rtb_YAccelerometerIntegralGain == 0.0 ? 0.0 :
                     rtb_YAccelerometerIntegralGain) * 15.0 + 0.85 *
                    rtb_YAccelerometerIntegralGain) * 0.01;

  /* Gain: '<S4>/RightFwd Thruster Normalize' incorporates:
   *  Gain: '<S57>/Gain'
   *  Gain: '<S57>/Gain1'
   *  Signum: '<S57>/Sign'
   *  Sum: '<S57>/Sum'
   */
  (*rty_RightFwd) = ((rtb_Add1 < 0.0 ? -1.0 : rtb_Add1 > 0.0 ? 1.0 : rtb_Add1 ==
                      0.0 ? 0.0 : rtb_Add1) * 15.0 + 0.85 * rtb_Add1) * 0.01;

  /* Saturate: '<S4>/YAxis Drag Compensation Limiter' incorporates:
   *  Gain: '<S2>/Gain'
   *  Sum: '<Root>/Add2'
   *  Sum: '<S2>/Add'
   */
  rtb_Error_n = ((-rtb_MergeDesiredYawRate) + localB->MergeDesiredYVelocity) +
    localB->Merge2;
  rtb_MergeDesiredYawRate = rtb_Error_n >= 100.0 ? 100.0 : rtb_Error_n <= -100.0
    ? -100.0 : rtb_Error_n;

  /* Saturate: '<S4>/Buoyancy  Compensation Limiter' incorporates:
   *  DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator'
   *  Sum: '<Root>/Add3'
   *  Sum: '<S21>/Sum'
   *  Sum: '<S22>/Diff'
   *  UnitDelay: '<S22>/UD'
   */
  rtb_Error_n = (((rtb_TSamp - localDW->UD_DSTATE) + rtb_TSamp_ac) +
                 localDW->DepthDiscreteTimeIntegrator_DST) + localB->Merge3;
  rtb_Error_n = rtb_Error_n >= 100.0 ? 100.0 : rtb_Error_n <= -30.0 ? -30.0 :
    rtb_Error_n;

  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/Gain1'
   */
  rtb_YAccelerometerIntegralGain = (-rtb_MergeDesiredYawRate) + rtb_Error_n;

  /* Sum: '<S4>/Add3' */
  rtb_MergeDesiredYawRate += rtb_Error_n;

  /* Gain: '<S4>/LeftAngled Thruster Normalize' incorporates:
   *  Gain: '<S54>/Gain'
   *  Gain: '<S54>/Gain1'
   *  Signum: '<S54>/Sign'
   *  Sum: '<S54>/Sum'
   */
  (*rty_LeftAngled) = ((rtb_YAccelerometerIntegralGain < 0.0 ? -1.0 :
                        rtb_YAccelerometerIntegralGain > 0.0 ? 1.0 :
                        rtb_YAccelerometerIntegralGain == 0.0 ? 0.0 :
                        rtb_YAccelerometerIntegralGain) * 15.0 + 0.85 *
                       rtb_YAccelerometerIntegralGain) * 0.01;

  /* Gain: '<S4>/RightAngled Thruster Normalize' incorporates:
   *  Gain: '<S56>/Gain'
   *  Gain: '<S56>/Gain1'
   *  Signum: '<S56>/Sign'
   *  Sum: '<S56>/Sum'
   */
  (*rty_RightAngled) = ((rtb_MergeDesiredYawRate < 0.0 ? -1.0 :
    rtb_MergeDesiredYawRate > 0.0 ? 1.0 : rtb_MergeDesiredYawRate == 0.0 ? 0.0 :
    rtb_MergeDesiredYawRate) * 15.0 + 0.85 * rtb_MergeDesiredYawRate) * 0.01;

  /* Update for UnitDelay: '<S22>/UD' */
  localDW->UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator' */
  localDW->DepthDiscreteTimeIntegrator_DST = 0.02 * rtb_DepthIntegralGain +
    localDW->DepthDiscreteTimeIntegrator_DST;
  if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
    localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
  } else {
    if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
    }
  }
}

/* Model initialize function */
void mr_MotionController_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MotionController *const MotionController_M, rtB_mr_MotionController
  *localB, rtDW_mr_MotionController *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(MotionController_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_MotionController));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(rtDW_mr_MotionController));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
