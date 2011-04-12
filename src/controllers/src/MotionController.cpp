/*
 * File: MotionController.cpp
 *
 * Real-Time Workshop code generated for Simulink model MotionController.
 *
 * Model version                        : 1.79
 * Real-Time Workshop file version      : 7.6.1  (R2010bSP1)  28-Jan-2011
 * Real-Time Workshop file generated on : Sat Apr  2 13:41:47 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sat Apr  2 13:41:47 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotionController.h"
#include "MotionController_private.h"

/* Block signals (auto storage) */
BlockIO_MotionController MotionController_B;

/* Block states (auto storage) */
D_Work_MotionController MotionController_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_MotionController MotionController_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_MotionControlle MotionController_Y;

/* Real-time model */
RT_MODEL_MotionController MotionController_M_;
RT_MODEL_MotionController *MotionController_M = &MotionController_M_;

/*
 * Initial conditions for enable system:
 *    '<S28>/Down X Controller'
 *    '<S28>/Down Y Controller'
 */
void MotionCont_DownXController_Init(rtDW_DownXController_MotionCont *localDW)
{
  /* InitializeConditions for UnitDelay: '<S33>/UD' */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S28>/Down X Controller'
 *    '<S28>/Down Y Controller'
 */
void MotionC_DownXController_Disable(real_T *rty_Output,
  rtDW_DownXController_MotionCont *localDW)
{
  /* Disable for Outport: '<S30>/Output' */
  (*rty_Output) = 0.0;
  localDW->DownXController_MODE = FALSE;
}

/*
 * Start for enable system:
 *    '<S28>/Down X Controller'
 *    '<S28>/Down Y Controller'
 */
void MotionCon_DownXController_Start(rtDW_DownXController_MotionCont *localDW)
{
  MotionCont_DownXController_Init(localDW);
}

/*
 * Output and update for enable system:
 *    '<S28>/Down X Controller'
 *    '<S28>/Down Y Controller'
 */
void MotionControlle_DownXController(real_T rtu_0, real_T rtu_Measured, real_T
  rtu_Setpoint, real_T *rty_Output, rtDW_DownXController_MotionCont *localDW,
  real_T rtp_Kd, real_T rtp_Ki, real_T rtp_Kp)
{
  real_T rtb_Error_n;
  real_T rtb_TSamp_ac;
  if (rtu_0 > 0.0) {
    if (!localDW->DownXController_MODE) {
      MotionCont_DownXController_Init(localDW);
      localDW->DownXController_MODE = TRUE;
    }

    /* Sum: '<S30>/Subtract' */
    rtb_Error_n = rtu_Setpoint - rtu_Measured;

    /* SampleTimeMath: '<S33>/TSamp' incorporates:
     *  Gain: '<S30>/Derivative Gain'
     *
     * About '<S33>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_ac = rtp_Kd * rtb_Error_n * 50.0;

    /* Sum: '<S30>/Sum' incorporates:
     *  DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
     *  Gain: '<S30>/Proportional Gain'
     *  Sum: '<S33>/Diff'
     *  UnitDelay: '<S33>/UD'
     */
    (*rty_Output) = (rtp_Kp * rtb_Error_n + (rtb_TSamp_ac - localDW->UD_DSTATE))
      + localDW->DiscreteTimeIntegrator_DSTATE;

    /* Update for UnitDelay: '<S33>/UD' */
    localDW->UD_DSTATE = rtb_TSamp_ac;

    /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S30>/Integral Gain'
     */
    localDW->DiscreteTimeIntegrator_DSTATE = rtp_Ki * rtb_Error_n * 0.02 +
      localDW->DiscreteTimeIntegrator_DSTATE;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= 15.0) {
      localDW->DiscreteTimeIntegrator_DSTATE = 15.0;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE <= -15.0) {
        localDW->DiscreteTimeIntegrator_DSTATE = -15.0;
      }
    }
  } else {
    if ((int32_T)localDW->DownXController_MODE) {
      MotionC_DownXController_Disable(rty_Output, localDW);
    }
  }
}

/*
 * Initial conditions for enable system:
 *    '<S28>/Down Yaw Controller'
 *    '<S29>/PID Controller with Enable1'
 *    '<S29>/PID Controller with Enable2'
 */
void MotionCo_DownYawController_Init(rtDW_DownYawController_MotionCo *localDW)
{
  /* InitializeConditions for UnitDelay: '<S35>/UD' */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S28>/Down Yaw Controller'
 *    '<S29>/PID Controller with Enable1'
 *    '<S29>/PID Controller with Enable2'
 */
void Motio_DownYawController_Disable(real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW)
{
  /* Disable for Outport: '<S32>/Output' */
  (*rty_Output) = 0.0;
  localDW->DownYawController_MODE = FALSE;
}

/*
 * Start for enable system:
 *    '<S28>/Down Yaw Controller'
 *    '<S29>/PID Controller with Enable1'
 *    '<S29>/PID Controller with Enable2'
 */
void MotionC_DownYawController_Start(rtDW_DownYawController_MotionCo *localDW)
{
  MotionCo_DownYawController_Init(localDW);
}

/*
 * Output and update for enable system:
 *    '<S28>/Down Yaw Controller'
 *    '<S29>/PID Controller with Enable1'
 *    '<S29>/PID Controller with Enable2'
 */
void MotionControl_DownYawController(boolean_T rtu_0, real_T rtu_Measured,
  real_T rtu_Setpoint, real_T *rty_Output, rtDW_DownYawController_MotionCo
  *localDW, real_T rtp_Kd, real_T rtp_Ki, real_T rtp_Kp)
{
  real_T rtb_Error_g;
  real_T rtb_TSamp_a0;
  if (rtu_0) {
    if (!localDW->DownYawController_MODE) {
      MotionCo_DownYawController_Init(localDW);
      localDW->DownYawController_MODE = TRUE;
    }

    /* Sum: '<S32>/Subtract' */
    rtb_Error_g = rtu_Setpoint - rtu_Measured;

    /* SampleTimeMath: '<S35>/TSamp' incorporates:
     *  Gain: '<S32>/Derivative Gain'
     *
     * About '<S35>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_a0 = rtp_Kd * rtb_Error_g * 50.0;

    /* Sum: '<S32>/Sum' incorporates:
     *  DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
     *  Gain: '<S32>/Proportional Gain'
     *  Sum: '<S35>/Diff'
     *  UnitDelay: '<S35>/UD'
     */
    (*rty_Output) = (rtp_Kp * rtb_Error_g + (rtb_TSamp_a0 - localDW->UD_DSTATE))
      + localDW->DiscreteTimeIntegrator_DSTATE;

    /* Update for UnitDelay: '<S35>/UD' */
    localDW->UD_DSTATE = rtb_TSamp_a0;

    /* Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S32>/Integral Gain'
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

/* Model step function */
void MotionController_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator2;
  real_T rtb_Add3;
  real_T rtb_YAxisDragCompensationLimite;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_YAccelerometerIntegralGain;
  real_T rtb_MergeDesiredYawRate;
  uint8_T rtb_Compare;
  uint8_T rtb_Compare_e;
  uint8_T rtb_Compare_d;
  real_T rtb_Error;
  real_T rtb_TSamp_h;

  /* Outputs for enable SubSystem: '<Root>/Targeting Controllers' incorporates:
   *  EnablePort: '<S3>/Enable'
   *  Inport: '<Root>/TargetSelect'
   */
  if (MotionController_U.TargetSelect > 0.0) {
    if (!MotionController_DWork.TargetingControllers_MODE) {
      MotionController_DWork.TargetingControllers_MODE = TRUE;
    }

    /* If: '<S3>/If' incorporates:
     *  ActionPort: '<S24>/Action Port'
     *  Inport: '<Root>/TargetFound'
     *  SubSystem: '<S3>/Track Target'
     */
    rtPrevAction = MotionController_DWork.If_ActiveSubsystem_b;
    if (MotionController_U.TargetFound > 0.0) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    MotionController_DWork.If_ActiveSubsystem_b = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for enable SubSystem: '<S28>/Down X Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge,
        &MotionController_DWork.DownXController);

      /* end of Disable for SubSystem: '<S28>/Down X Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Y Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.DownYController);

      /* end of Disable for SubSystem: '<S28>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.DownYawController);

      /* end of Disable for SubSystem: '<S28>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for Outport: '<S36>/Output' */
      MotionController_B.Merge3 = 0.0;
      MotionController_DWork.PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable1' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.PIDControllerwithEnable1);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable2' */
    }

    if (rtAction == 0) {
      /* RelationalOperator: '<S25>/Compare' incorporates:
       *  Constant: '<S25>/Constant'
       *  Inport: '<Root>/TargetSelect'
       */
      rtb_Compare = (MotionController_U.TargetSelect == 1.0);

      /* RelationalOperator: '<S26>/Compare' incorporates:
       *  Constant: '<S26>/Constant'
       *  Inport: '<Root>/TargetSelect'
       */
      rtb_Compare_e = (MotionController_U.TargetSelect == 2.0);

      /* RelationalOperator: '<S27>/Compare' incorporates:
       *  Constant: '<S27>/Constant'
       *  Inport: '<Root>/MaintainHeading'
       */
      rtb_Compare_d = (MotionController_U.MaintainHeading <= 0);

      /* Outputs for enable SubSystem: '<S28>/Down X Controller' incorporates:
       *  EnablePort: '<S30>/Enable'
       */
      MotionControlle_DownXController(MotionController_U.TargetSelect,
        MotionController_U.TargetX, MotionController_U.DesiredTargetX,
        &MotionController_B.Merge, &MotionController_DWork.DownXController,
        MotionController_P.Target_Down_X_Kd, MotionController_P.Target_Down_X_Ki,
        MotionController_P.Target_Down_X_Kp);

      /* end of Outputs for SubSystem: '<S28>/Down X Controller' */

      /* Outputs for enable SubSystem: '<S28>/Down Y Controller' */
      MotionControlle_DownXController(MotionController_U.TargetSelect,
        MotionController_U.TargetY, MotionController_U.DesiredTargetY,
        &MotionController_B.Merge2, &MotionController_DWork.DownYController,
        MotionController_P.Target_Down_Y_Kd, MotionController_P.Target_Down_Y_Ki,
        MotionController_P.Target_Down_Y_Kp);

      /* end of Outputs for SubSystem: '<S28>/Down Y Controller' */

      /* Logic: '<S24>/Logical Operator1' */
      rtb_LogicalOperator1 = ((rtb_Compare_e != 0) && (rtb_Compare_d != 0));

      /* Outputs for enable SubSystem: '<S28>/Down Yaw Controller' incorporates:
       *  EnablePort: '<S32>/Enable'
       */
      MotionControl_DownYawController(rtb_LogicalOperator1,
        MotionController_U.TargetYaw, MotionController_U.DesiredTargetYaw,
        &MotionController_B.Merge1, &MotionController_DWork.DownYawController,
        MotionController_P.Target_Down_Yaw_Kd,
        MotionController_P.Target_Down_Yaw_Ki,
        MotionController_P.Target_Down_Yaw_Kp);

      /* end of Outputs for SubSystem: '<S28>/Down Yaw Controller' */

      /* Outputs for enable SubSystem: '<S29>/PID Controller with Enable' incorporates:
       *  EnablePort: '<S36>/Enable'
       */
      if (rtb_Compare > 0) {
        if (!MotionController_DWork.PIDControllerwithEnable_MODE) {
          /* InitializeConditions for UnitDelay: '<S39>/UD' */
          MotionController_DWork.UD_DSTATE_j = 0.0;

          /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
          MotionController_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
          MotionController_DWork.PIDControllerwithEnable_MODE = TRUE;
        }

        /* Sum: '<S36>/Subtract' incorporates:
         *  Inport: '<Root>/DesiredTargetZ'
         *  Inport: '<Root>/TargetZ'
         */
        rtb_Error = MotionController_U.DesiredTargetZ -
          MotionController_U.TargetZ;

        /* SampleTimeMath: '<S39>/TSamp' incorporates:
         *  Gain: '<S36>/Derivative Gain'
         *
         * About '<S39>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_h = MotionController_P.Target_Forward_Z_Kd * rtb_Error * 50.0;

        /* Sum: '<S36>/Sum' incorporates:
         *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
         *  Gain: '<S36>/Proportional Gain'
         *  Sum: '<S39>/Diff'
         *  UnitDelay: '<S39>/UD'
         */
        MotionController_B.Merge3 = (MotionController_P.Target_Forward_Z_Kp *
          rtb_Error + (rtb_TSamp_h - MotionController_DWork.UD_DSTATE_j)) +
          MotionController_DWork.DiscreteTimeIntegrator_DSTATE;

        /* Update for UnitDelay: '<S39>/UD' */
        MotionController_DWork.UD_DSTATE_j = rtb_TSamp_h;

        /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
         *  Gain: '<S36>/Integral Gain'
         */
        MotionController_DWork.DiscreteTimeIntegrator_DSTATE =
          MotionController_P.Target_Forward_Z_Ki * rtb_Error * 0.02 +
          MotionController_DWork.DiscreteTimeIntegrator_DSTATE;
        if (MotionController_DWork.DiscreteTimeIntegrator_DSTATE >= 15.0) {
          MotionController_DWork.DiscreteTimeIntegrator_DSTATE = 15.0;
        } else {
          if (MotionController_DWork.DiscreteTimeIntegrator_DSTATE <= -15.0) {
            MotionController_DWork.DiscreteTimeIntegrator_DSTATE = -15.0;
          }
        }
      } else {
        if ((int32_T)MotionController_DWork.PIDControllerwithEnable_MODE) {
          /* Disable for Outport: '<S36>/Output' */
          MotionController_B.Merge3 = 0.0;
          MotionController_DWork.PIDControllerwithEnable_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S29>/PID Controller with Enable' */

      /* Logic: '<S24>/Logical Operator' */
      rtb_LogicalOperator = ((rtb_Compare != 0) && (rtb_Compare_d != 0));

      /* Outputs for enable SubSystem: '<S29>/PID Controller with Enable1' */
      MotionControl_DownYawController(rtb_LogicalOperator,
        MotionController_U.TargetYaw, MotionController_U.DesiredTargetYaw,
        &MotionController_B.Merge1,
        &MotionController_DWork.PIDControllerwithEnable1,
        MotionController_P.Target_Forward_Yaw_Kd,
        MotionController_P.Target_Forward_Yaw_Ki,
        MotionController_P.Target_Forward_Yaw_Kp);

      /* end of Outputs for SubSystem: '<S29>/PID Controller with Enable1' */

      /* Logic: '<S24>/Logical Operator2' incorporates:
       *  Inport: '<Root>/MaintainHeading'
       */
      rtb_LogicalOperator2 = ((rtb_Compare != 0) &&
        (MotionController_U.MaintainHeading != 0));

      /* Outputs for enable SubSystem: '<S29>/PID Controller with Enable2' */
      MotionControl_DownYawController(rtb_LogicalOperator2,
        MotionController_U.TargetY, MotionController_U.DesiredTargetY,
        &MotionController_B.Merge2,
        &MotionController_DWork.PIDControllerwithEnable2,
        MotionController_P.Target_Forward_Y_Kd,
        MotionController_P.Target_Forward_Y_Ki,
        MotionController_P.Target_Forward_Y_Kp);

      /* end of Outputs for SubSystem: '<S29>/PID Controller with Enable2' */
    }
  } else {
    if ((int32_T)MotionController_DWork.TargetingControllers_MODE) {
      /* Disable for If: '<S3>/If' */
      MotionController_DWork.If_ActiveSubsystem_b = -1;

      /* Disable for enable SubSystem: '<S28>/Down X Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge,
        &MotionController_DWork.DownXController);

      /* end of Disable for SubSystem: '<S28>/Down X Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Y Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.DownYController);

      /* end of Disable for SubSystem: '<S28>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.DownYawController);

      /* end of Disable for SubSystem: '<S28>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for Outport: '<S36>/Output' */
      MotionController_B.Merge3 = 0.0;
      MotionController_DWork.PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable1' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.PIDControllerwithEnable1);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable2' */

      /* Disable for ifaction SubSystem: '<S3>/Track Target' */

      /* Disable for enable SubSystem: '<S28>/Down X Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge,
        &MotionController_DWork.DownXController);

      /* end of Disable for SubSystem: '<S28>/Down X Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Y Controller' */
      MotionC_DownXController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.DownYController);

      /* end of Disable for SubSystem: '<S28>/Down Y Controller' */

      /* Disable for enable SubSystem: '<S28>/Down Yaw Controller' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.DownYawController);

      /* end of Disable for SubSystem: '<S28>/Down Yaw Controller' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for Outport: '<S36>/Output' */
      MotionController_B.Merge3 = 0.0;
      MotionController_DWork.PIDControllerwithEnable_MODE = FALSE;

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable1' */
      Motio_DownYawController_Disable(&MotionController_B.Merge1,
        &MotionController_DWork.PIDControllerwithEnable1);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable1' */

      /* Disable for enable SubSystem: '<S29>/PID Controller with Enable2' */
      Motio_DownYawController_Disable(&MotionController_B.Merge2,
        &MotionController_DWork.PIDControllerwithEnable2);

      /* end of Disable for SubSystem: '<S29>/PID Controller with Enable2' */

      /* end of Disable for SubSystem: '<S3>/Track Target' */

      /* Disable for Outport: '<S3>/DesiredXVelocity' */
      MotionController_B.Merge = 0.0;

      /* Disable for Outport: '<S3>/DesiredYVelocity' */
      MotionController_B.Merge2 = 0.0;

      /* Disable for Outport: '<S3>/DesiredZVelocity' */
      MotionController_B.Merge3 = 0.0;

      /* Disable for Outport: '<S3>/DesiredYawRate' */
      MotionController_B.Merge1 = 0.0;
      MotionController_DWork.TargetingControllers_MODE = FALSE;
    }
  }

  /* end of Outputs for SubSystem: '<Root>/Targeting Controllers' */

  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/DesiredXVelocity'
   */
  rtb_Add3 = MotionController_B.Merge + MotionController_U.DesiredXVelocity;

  /* Sum: '<S5>/Subtract' incorporates:
   *  Inport: '<Root>/DesiredYaw'
   *  Inport: '<Root>/MeasuredYaw'
   */
  rtb_Error = MotionController_U.DesiredYaw - MotionController_U.MeasuredYaw;

  /* If: '<S5>/If' incorporates:
   *  Abs: '<S5>/Abs'
   *  ActionPort: '<S7>/Action Port'
   *  ActionPort: '<S8>/Action Port'
   *  SubSystem: '<S5>/Maintain Desired Yaw'
   *  SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity'
   */
  rtPrevAction = MotionController_DWork.If_ActiveSubsystem;
  if (fabs(rtb_Error) > 3.0) {
    rtAction = 0;
  } else {
    rtAction = 1;
  }

  MotionController_DWork.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S10>/If' */
    MotionController_DWork.If_ActiveSubsystem_l = -1;

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */

    /* Disable for Outport: '<S14>/Out2' */
    MotionController_B.Constant1_e = 0.0;

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */

    /* Disable for Outport: '<S15>/Out2' */
    MotionController_B.Constant1 = 0.0;

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */
  }

  switch (rtAction) {
   case 0:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for UnitDelay: '<S16>/UD' */
      MotionController_DWork.UD_DSTATE_jj = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' */
      MotionController_DWork.HeadingDiscreteTimeIntegrator_l = 0.0;
    }

    /* If: '<S10>/If' incorporates:
     *  ActionPort: '<S14>/Action Port'
     *  ActionPort: '<S15>/Action Port'
     *  SubSystem: '<S10>/BigError S1'
     *  SubSystem: '<S10>/BigNegativeError S2'
     */
    rtPrevAction = MotionController_DWork.If_ActiveSubsystem_l;
    rtAction = -1;
    if (rtb_Error > 180.0) {
      rtAction = 0;
    } else {
      if (rtb_Error < -180.0) {
        rtAction = 1;
      }
    }

    MotionController_DWork.If_ActiveSubsystem_l = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for Outport: '<S14>/Out2' */
        MotionController_B.Constant1_e = 0.0;
        break;

       case 1:
        /* Disable for Outport: '<S15>/Out2' */
        MotionController_B.Constant1 = 0.0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Sum: '<S14>/Add' incorporates:
       *  Constant: '<S14>/Constant'
       */
      MotionController_B.Add_l = rtb_Error - 360.0;

      /* Constant: '<S14>/Constant1' */
      MotionController_B.Constant1_e = 1.0;
      break;

     case 1:
      /* Sum: '<S15>/Add' incorporates:
       *  Constant: '<S15>/Constant'
       */
      MotionController_B.Add = rtb_Error + 360.0;

      /* Constant: '<S15>/Constant1' */
      MotionController_B.Constant1 = 2.0;
      break;
    }

    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Sum: '<S10>/Add2'
     */
    switch ((int32_T)((1.0 + MotionController_B.Constant1_e) +
                      MotionController_B.Constant1)) {
     case 1:
      break;

     case 2:
      rtb_Error = MotionController_B.Add_l;
      break;

     default:
      rtb_Error = MotionController_B.Add;
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
    rtb_Error = (1.0 / (exp(0.022222222222222223 * rtb_Error * -2.0) + 1.0) *
                 2.0 - 1.0) * 45.0;

    /* SampleTimeMath: '<S16>/TSamp' incorporates:
     *  Gain: '<S11>/Heading Derivative Gain'
     *
     * About '<S16>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_h = MotionController_P.Compass_Yaw_Kd * rtb_Error * 50.0;

    /* Sum: '<S11>/Sum' incorporates:
     *  DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator'
     *  Gain: '<S11>/Heading Proportional Gain'
     *  Sum: '<S16>/Diff'
     *  UnitDelay: '<S16>/UD'
     */
    rtb_MergeDesiredYawRate = (MotionController_P.Compass_Yaw_Kp * rtb_Error +
      (rtb_TSamp_h - MotionController_DWork.UD_DSTATE_jj)) +
      MotionController_DWork.HeadingDiscreteTimeIntegrator_l;

    /* Update for UnitDelay: '<S16>/UD' */
    MotionController_DWork.UD_DSTATE_jj = rtb_TSamp_h;

    /* Update for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S11>/Heading Integral Gain'
     */
    MotionController_DWork.HeadingDiscreteTimeIntegrator_l =
      MotionController_P.Compass_Yaw_Ki * rtb_Error * 0.02 +
      MotionController_DWork.HeadingDiscreteTimeIntegrator_l;
    if (MotionController_DWork.HeadingDiscreteTimeIntegrator_l >= 15.0) {
      MotionController_DWork.HeadingDiscreteTimeIntegrator_l = 15.0;
    } else {
      if (MotionController_DWork.HeadingDiscreteTimeIntegrator_l <= -15.0) {
        MotionController_DWork.HeadingDiscreteTimeIntegrator_l = -15.0;
      }
    }
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for UnitDelay: '<S20>/UD' */
      MotionController_DWork.UD_DSTATE_jn = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' */
      MotionController_DWork.HeadingDiscreteTimeIntegrator_D = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.0;

      /* InitializeConditions for UnitDelay: '<S19>/UD' */
      MotionController_DWork.UD_DSTATE_i = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
      MotionController_DWork.DepthDiscreteTimeIntegrator_D_a = 0.0;
    }

    /* SampleTimeMath: '<S20>/TSamp' incorporates:
     *  Gain: '<S18>/YawRate Derivative Gain'
     *  Inport: '<Root>/MeasuredYawRate'
     *
     * About '<S20>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Error = MotionController_P.IMU_YawRate_Kd *
      MotionController_U.MeasuredYawRate * 50.0;

    /* Sum: '<S18>/Sum' incorporates:
     *  DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator'
     *  Gain: '<S18>/YawRate Proportional Gain'
     *  Inport: '<Root>/MeasuredYawRate'
     *  Sum: '<S20>/Diff'
     *  UnitDelay: '<S20>/UD'
     */
    rtb_MergeDesiredYawRate = (MotionController_P.IMU_YawRate_Kp *
      MotionController_U.MeasuredYawRate + (rtb_Error -
      MotionController_DWork.UD_DSTATE_jn)) +
      MotionController_DWork.HeadingDiscreteTimeIntegrator_D;

    /* SampleTimeMath: '<S19>/TSamp' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     *  Gain: '<S17>/Y-Accelerometer Derivative Gain'
     *
     * About '<S19>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_h = MotionController_P.IMU_YVel_Kd *
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d * 50.0;

    /* Sum: '<S17>/Sum' incorporates:
     *  DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     *  Gain: '<S17>/Y-Accelerometer Proportional Gain'
     *  Sum: '<S19>/Diff'
     *  UnitDelay: '<S19>/UD'
     */
    MotionController_B.MergeDesiredYVelocity = (MotionController_P.IMU_YVel_Kp *
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d + (rtb_TSamp_h -
      MotionController_DWork.UD_DSTATE_i)) +
      MotionController_DWork.DepthDiscreteTimeIntegrator_D_a;

    /* Gain: '<S17>/Y-Accelerometer Integral Gain' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    rtb_YAccelerometerIntegralGain = MotionController_P.IMU_YVel_Ki *
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d;

    /* Update for UnitDelay: '<S20>/UD' */
    MotionController_DWork.UD_DSTATE_jn = rtb_Error;

    /* Update for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S18>/YawRate Integral Gain'
     *  Update for Inport: '<Root>/MeasuredYawRate'
     */
    MotionController_DWork.HeadingDiscreteTimeIntegrator_D =
      MotionController_P.IMU_YawRate_Ki * MotionController_U.MeasuredYawRate *
      0.02 + MotionController_DWork.HeadingDiscreteTimeIntegrator_D;
    if (MotionController_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
      MotionController_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
    } else {
      if (MotionController_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
        MotionController_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
      }
    }

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
     *  Update for Inport: '<Root>/MeasuredYAccel'
     */
    MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.02 *
      MotionController_U.MeasuredYAccel +
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d;
    if (MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d >= 10.0) {
      MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d = 10.0;
    } else {
      if (MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d <= -10.0) {
        MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d = -10.0;
      }
    }

    /* Update for UnitDelay: '<S19>/UD' */
    MotionController_DWork.UD_DSTATE_i = rtb_TSamp_h;

    /* Update for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
    MotionController_DWork.DepthDiscreteTimeIntegrator_D_a = 0.02 *
      rtb_YAccelerometerIntegralGain +
      MotionController_DWork.DepthDiscreteTimeIntegrator_D_a;
    if (MotionController_DWork.DepthDiscreteTimeIntegrator_D_a >= 10.0) {
      MotionController_DWork.DepthDiscreteTimeIntegrator_D_a = 10.0;
    } else {
      if (MotionController_DWork.DepthDiscreteTimeIntegrator_D_a <= -10.0) {
        MotionController_DWork.DepthDiscreteTimeIntegrator_D_a = -10.0;
      }
    }
    break;
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/TargetSelect'
   */
  if (MotionController_U.TargetSelect != 0.0) {
    rtb_YAccelerometerIntegralGain = 0.0;
  } else {
    rtb_YAccelerometerIntegralGain = rtb_MergeDesiredYawRate;
  }

  /* Sum: '<Root>/Add1' */
  rtb_YAccelerometerIntegralGain += MotionController_B.Merge1;

  /* Sum: '<S4>/Add' */
  rtb_YAxisDragCompensationLimite = rtb_Add3 + rtb_YAccelerometerIntegralGain;

  /* Outport: '<Root>/LeftFwd' incorporates:
   *  Gain: '<S43>/Gain'
   *  Gain: '<S43>/Gain1'
   *  Gain: '<S4>/LeftFwd Thruster  Normalize'
   *  Signum: '<S43>/Sign'
   *  Sum: '<S43>/Sum'
   */
  MotionController_Y.LeftFwd = ((100.0 -
    MotionController_P.Thruster_Friction_Zero) / 100.0 *
    rtb_YAxisDragCompensationLimite + (rtb_YAxisDragCompensationLimite < 0.0 ?
    -1.0 : rtb_YAxisDragCompensationLimite > 0.0 ? 1.0 :
    rtb_YAxisDragCompensationLimite == 0.0 ? 0.0 :
    rtb_YAxisDragCompensationLimite) * MotionController_P.Thruster_Friction_Zero)
    * (MotionController_P.Thruster_LeftFwd_Gain / 100.0);

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtb_Add3 += -rtb_YAccelerometerIntegralGain;

  /* Outport: '<Root>/RightFwd' incorporates:
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Gain: '<S4>/RightFwd Thruster Normalize'
   *  Signum: '<S45>/Sign'
   *  Sum: '<S45>/Sum'
   */
  MotionController_Y.RightFwd = ((100.0 -
    MotionController_P.Thruster_Friction_Zero) / 100.0 * rtb_Add3 + (rtb_Add3 <
    0.0 ? -1.0 : rtb_Add3 > 0.0 ? 1.0 : rtb_Add3 == 0.0 ? 0.0 : rtb_Add3) *
    MotionController_P.Thruster_Friction_Zero) *
    (MotionController_P.Thruster_RightFwd_Gain / 100.0);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/TargetSelect'
   */
  if (MotionController_U.TargetSelect != 0.0) {
    rtb_YAxisDragCompensationLimite = rtb_MergeDesiredYawRate;
  } else {
    rtb_YAxisDragCompensationLimite = 0.0;
  }

  /* Saturate: '<S4>/YAxis Drag Compensation Limiter' incorporates:
   *  Gain: '<S2>/Gain'
   *  Sum: '<Root>/Add2'
   *  Sum: '<S2>/Add'
   */
  rtb_TSamp_h = ((-rtb_YAxisDragCompensationLimite) +
                 MotionController_B.MergeDesiredYVelocity) +
    MotionController_B.Merge2;
  rtb_YAxisDragCompensationLimite = rtb_TSamp_h >= 100.0 ? 100.0 : rtb_TSamp_h <=
    -100.0 ? -100.0 : rtb_TSamp_h;

  /* Sum: '<S6>/Add' incorporates:
   *  Inport: '<Root>/DesiredZ'
   *  Inport: '<Root>/MeasuredZ'
   */
  rtb_YAccelerometerIntegralGain = MotionController_U.DesiredZ -
    MotionController_U.MeasuredZ;

  /* SampleTimeMath: '<S22>/TSamp' incorporates:
   *  Gain: '<S21>/Depth Derivative Gain'
   *
   * About '<S22>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Error = MotionController_P.Depth_Kd * rtb_YAccelerometerIntegralGain *
    50.0;

  /* Saturate: '<S4>/Buoyancy  Compensation Limiter' incorporates:
   *  DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator'
   *  Gain: '<S21>/Depth Proportional Gain'
   *  Sum: '<Root>/Add3'
   *  Sum: '<S21>/Sum'
   *  Sum: '<S22>/Diff'
   *  UnitDelay: '<S22>/UD'
   */
  rtb_TSamp_h = ((MotionController_P.Depth_Kp * rtb_YAccelerometerIntegralGain +
                  (rtb_Error - MotionController_DWork.UD_DSTATE)) +
                 MotionController_DWork.DepthDiscreteTimeIntegrator_DST) +
    MotionController_B.Merge3;
  rtb_Add3 = rtb_TSamp_h >= 100.0 ? 100.0 : rtb_TSamp_h <=
    MotionController_P.ZVelocity_Neg_Max ? MotionController_P.ZVelocity_Neg_Max :
    rtb_TSamp_h;

  /* Sum: '<S4>/Add2' */
  rtb_TSamp_h = rtb_YAxisDragCompensationLimite + rtb_Add3;

  /* Outport: '<Root>/LeftAngled' incorporates:
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Gain: '<S4>/LeftAngled Thruster Normalize'
   *  Signum: '<S42>/Sign'
   *  Sum: '<S42>/Sum'
   */
  MotionController_Y.LeftAngled = ((100.0 -
    MotionController_P.Thruster_Friction_Zero) / 100.0 * rtb_TSamp_h +
    (rtb_TSamp_h < 0.0 ? -1.0 : rtb_TSamp_h > 0.0 ? 1.0 : rtb_TSamp_h == 0.0 ?
     0.0 : rtb_TSamp_h) * MotionController_P.Thruster_Friction_Zero) *
    (MotionController_P.Thruster_LeftAngled_Gain / 100.0);

  /* Sum: '<S4>/Add3' incorporates:
   *  Gain: '<S4>/Gain1'
   */
  rtb_Add3 += -rtb_YAxisDragCompensationLimite;

  /* Outport: '<Root>/RightAngled' incorporates:
   *  Gain: '<S44>/Gain'
   *  Gain: '<S44>/Gain1'
   *  Gain: '<S4>/RightAngled Thruster Normalize'
   *  Signum: '<S44>/Sign'
   *  Sum: '<S44>/Sum'
   */
  MotionController_Y.RightAngled = ((100.0 -
    MotionController_P.Thruster_Friction_Zero) / 100.0 * rtb_Add3 + (rtb_Add3 <
    0.0 ? -1.0 : rtb_Add3 > 0.0 ? 1.0 : rtb_Add3 == 0.0 ? 0.0 : rtb_Add3) *
    MotionController_P.Thruster_Friction_Zero) *
    (MotionController_P.Thruster_RightAngled_Gain / 100.0);

  /* Update for UnitDelay: '<S22>/UD' */
  MotionController_DWork.UD_DSTATE = rtb_Error;

  /* Update for DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator' incorporates:
   *  Gain: '<S21>/Depth Integral Gain'
   */
  MotionController_DWork.DepthDiscreteTimeIntegrator_DST =
    MotionController_P.Depth_Ki * rtb_YAccelerometerIntegralGain * 0.02 +
    MotionController_DWork.DepthDiscreteTimeIntegrator_DST;
  if (MotionController_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
    MotionController_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
  } else {
    if (MotionController_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
      MotionController_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
    }
  }
}

/* Model initialize function */
void MotionController_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(MotionController_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &MotionController_B), 0,
                sizeof(BlockIO_MotionController));

  /* states (dwork) */
  (void) memset((void *)&MotionController_DWork, 0,
                sizeof(D_Work_MotionController));

  /* external inputs */
  (void) memset((void *)&MotionController_U, 0,
                sizeof(ExternalInputs_MotionController));

  /* external outputs */
  (void) memset((void *)&MotionController_Y, 0,
                sizeof(ExternalOutputs_MotionControlle));

  /* Start for enable SubSystem: '<Root>/Targeting Controllers' */

  /* Start for If: '<S3>/If' */
  MotionController_DWork.If_ActiveSubsystem_b = -1;

  /* Start for ifaction SubSystem: '<S3>/Track Target' */

  /* Start for enable SubSystem: '<S28>/Down X Controller' */
  MotionCon_DownXController_Start(&MotionController_DWork.DownXController);

  /* end of Start for SubSystem: '<S28>/Down X Controller' */

  /* Start for enable SubSystem: '<S28>/Down Y Controller' */
  MotionCon_DownXController_Start(&MotionController_DWork.DownYController);

  /* end of Start for SubSystem: '<S28>/Down Y Controller' */

  /* Start for enable SubSystem: '<S28>/Down Yaw Controller' */
  MotionC_DownYawController_Start(&MotionController_DWork.DownYawController);

  /* end of Start for SubSystem: '<S28>/Down Yaw Controller' */

  /* Start for enable SubSystem: '<S29>/PID Controller with Enable' */

  /* InitializeConditions for UnitDelay: '<S39>/UD' */
  MotionController_DWork.UD_DSTATE_j = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  MotionController_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;

  /* end of Start for SubSystem: '<S29>/PID Controller with Enable' */

  /* Start for enable SubSystem: '<S29>/PID Controller with Enable1' */
  MotionC_DownYawController_Start
    (&MotionController_DWork.PIDControllerwithEnable1);

  /* end of Start for SubSystem: '<S29>/PID Controller with Enable1' */

  /* Start for enable SubSystem: '<S29>/PID Controller with Enable2' */
  MotionC_DownYawController_Start
    (&MotionController_DWork.PIDControllerwithEnable2);

  /* end of Start for SubSystem: '<S29>/PID Controller with Enable2' */

  /* end of Start for SubSystem: '<S3>/Track Target' */

  /* end of Start for SubSystem: '<Root>/Targeting Controllers' */

  /* Start for If: '<S5>/If' */
  MotionController_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S5>/Maintain Desired Yaw' */

  /* Start for If: '<S10>/If' */
  MotionController_DWork.If_ActiveSubsystem_l = -1;

  /* InitializeConditions for UnitDelay: '<S16>/UD' */
  MotionController_DWork.UD_DSTATE_jj = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Heading Discrete-Time Integrator' */
  MotionController_DWork.HeadingDiscreteTimeIntegrator_l = 0.0;

  /* end of Start for SubSystem: '<S5>/Maintain Desired Yaw' */

  /* Start for ifaction SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity' */

  /* InitializeConditions for UnitDelay: '<S20>/UD' */
  MotionController_DWork.UD_DSTATE_jn = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Heading Discrete-Time Integrator' */
  MotionController_DWork.HeadingDiscreteTimeIntegrator_D = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  MotionController_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.0;

  /* InitializeConditions for UnitDelay: '<S19>/UD' */
  MotionController_DWork.UD_DSTATE_i = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Depth Discrete-Time Integrator' */
  MotionController_DWork.DepthDiscreteTimeIntegrator_D_a = 0.0;

  /* end of Start for SubSystem: '<S5>/Maintain Zero YawRate and Zero YVelocity' */

  /* Constant: '<S5>/Not Controlled  Y Value' */
  MotionController_B.MergeDesiredYVelocity = 0.0;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
