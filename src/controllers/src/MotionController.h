/*
 * File: MotionController.h
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

#ifndef RTW_HEADER_MotionController_h_
#define RTW_HEADER_MotionController_h_
#ifndef MotionController_COMMON_INCLUDES_
# define MotionController_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* MotionController_COMMON_INCLUDES_ */

#include "MotionController_types.h"

/* Block states (auto storage) for system '<S40>/Down Yaw Controller' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S47>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S44>/Discrete-Time Integrator' */
  boolean_T DownYawController_MODE;    /* '<S40>/Down Yaw Controller' */
} rtDW_DownYawController_MotionCo;

/* Block signals for model 'MotionController' */
typedef struct {
  real_T MergeDesiredYVelocity;        /* '<S5>/Merge DesiredYVelocity' */
  real_T Merge;                        /* '<S3>/Merge' */
  real_T Merge1;                       /* '<S3>/Merge1' */
  real_T Merge2;                       /* '<S3>/Merge2' */
  real_T Merge3;                       /* '<S3>/Merge3' */
  real_T Add;                          /* '<S15>/Add' */
  real_T Constant1;                    /* '<S15>/Constant1' */
  real_T Add_l;                        /* '<S14>/Add' */
  real_T Constant1_e;                  /* '<S14>/Constant1' */
} rtB_mr_MotionController;

/* Block states (auto storage) for model 'MotionController' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S22>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S21>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_d;                  /* '<S52>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S49>/Discrete-Time Integrator' */
  real_T UD_DSTATE_j;                  /* '<S51>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S48>/Discrete-Time Integrator' */
  real_T UD_DSTATE_je;                 /* '<S46>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_bx;/* '<S43>/Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S45>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S42>/Discrete-Time Integrator' */
  real_T UD_DSTATE_jn;                 /* '<S20>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S18>/Heading Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S8>/Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S19>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_a;/* '<S17>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_jj;                 /* '<S16>/UD' */
  real_T HeadingDiscreteTimeIntegrator_l;/* '<S11>/Heading Discrete-Time Integrator' */
  real_T Memory_PreviousInput;         /* '<S29>/Memory' */
  real_T A;                            /* '<S28>/Data Store Memory' */
  real_T Memory_PreviousInput_f;       /* '<S33>/Memory' */
  real_T A_l;                          /* '<S32>/Data Store Memory' */
  int8_T If_ActiveSubsystem;           /* '<S5>/If' */
  int8_T If_ActiveSubsystem_b;         /* '<S3>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S10>/If' */
  boolean_T TargetingControllers_MODE; /* '<Root>/Targeting Controllers' */
  boolean_T DownXController_MODE;      /* '<S40>/Down X Controller' */
  boolean_T DownYController_MODE;      /* '<S40>/Down Y Controller' */
  boolean_T PIDControllerwithEnable_MODE;/* '<S41>/PID Controller with Enable' */
  boolean_T PIDControllerwithEnable1_MODE;/* '<S41>/PID Controller with Enable1' */
  rtDW_DownYawController_MotionCo PIDControllerwithEnable2;/* '<S41>/PID Controller with Enable2' */
  rtDW_DownYawController_MotionCo DownYawController;/* '<S40>/Down Yaw Controller' */
} rtDW_mr_MotionController;

/* Real-time Model Data Structure */
struct RT_MODEL_MotionController {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_MotionController rtb;
  rtDW_mr_MotionController rtdw;
  RT_MODEL_MotionController rtm;
} rtMdlrefDWork_mr_MotionControll;

/* Model reference registration function */
extern void mr_MotionController_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MotionController *const MotionController_M, rtB_mr_MotionController
  *localB, rtDW_mr_MotionController *localDW);
extern void MotionCo_DownYawController_Init(rtDW_DownYawController_MotionCo
  *localDW);
extern void MotionC_DownYawController_Start(rtDW_DownYawController_MotionCo
  *localDW);
extern void Motio_DownYawController_Disable(real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW);
extern void MotionControl_DownYawController(boolean_T rtu_0, const real_T
  *rtu_Measured, const real_T *rtu_Setpoint, real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW, real_T rtp_Kd, real_T rtp_Ki, real_T
  rtp_Kp);
extern void mr_MotionController_Start(rtB_mr_MotionController *localB,
  rtDW_mr_MotionController *localDW);
extern void mr_MotionController_Disable(rtB_mr_MotionController *localB,
  rtDW_mr_MotionController *localDW);
extern void mr_MotionController(const real_T *rtu_TargetSelect, const real_T
  *rtu_TargetFound, const uint8_T *rtu_MaintainHeading, const real_T
  *rtu_TargetX, const real_T *rtu_TargetY, const real_T *rtu_TargetZ, const
  real_T *rtu_TargetYaw, const real_T *rtu_DesiredTargetX, const real_T
  *rtu_DesiredTargetY, const real_T *rtu_DesiredTargetZ, const real_T
  *rtu_DesiredTargetYaw, const real_T *rtu_MeasuredZ, const real_T
  *rtu_MeasuredYAccel, const real_T *rtu_MeasuredYaw, const real_T
  *rtu_MeasuredYawRate, const real_T *rtu_DesiredZ, const real_T
  *rtu_DesiredXVelocity, const real_T *rtu_DesiredYaw, real_T *rty_LeftFwd,
  real_T *rty_RightFwd, real_T *rty_LeftAngled, real_T *rty_RightAngled,
  rtB_mr_MotionController *localB, rtDW_mr_MotionController *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : MotionController
 * '<S1>'   : MotionController/Model Info
 * '<S2>'   : MotionController/Non-Targeting Controllers
 * '<S3>'   : MotionController/Targeting Controllers
 * '<S4>'   : MotionController/Thruster Arrangement
 * '<S5>'   : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller
 * '<S6>'   : MotionController/Non-Targeting Controllers/Maintain Desired Z
 * '<S7>'   : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw
 * '<S8>'   : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Zero YawRate and Zero YVelocity
 * '<S9>'   : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shaping
 * '<S10>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shifting and Range Checking
 * '<S11>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/PID Controller Heading
 * '<S12>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shaping/DocBlock
 * '<S13>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shaping/tansig1
 * '<S14>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shifting and Range Checking/BigError S1
 * '<S15>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/Error Shifting and Range Checking/BigNegativeError S2
 * '<S16>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Desired Yaw/PID Controller Heading/Heading Discrete Derivative
 * '<S17>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Zero YawRate and Zero YVelocity/PID Controller Relative Heading
 * '<S18>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Zero YawRate and Zero YVelocity/PID Controller YawRate
 * '<S19>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Zero YawRate and Zero YVelocity/PID Controller Relative Heading/Depth Discrete Derivative
 * '<S20>'  : MotionController/Non-Targeting Controllers/Heading and Straight Line Controller/Maintain Zero YawRate and Zero YVelocity/PID Controller YawRate/Heading Discrete Derivative
 * '<S21>'  : MotionController/Non-Targeting Controllers/Maintain Desired Z /PID Controller Depth S3
 * '<S22>'  : MotionController/Non-Targeting Controllers/Maintain Desired Z /PID Controller Depth S3/Depth Discrete Derivative
 * '<S23>'  : MotionController/Targeting Controllers/Search for  Target
 * '<S24>'  : MotionController/Targeting Controllers/Track Target
 * '<S25>'  : MotionController/Targeting Controllers/Search for  Target/Find Downward Target
 * '<S26>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target
 * '<S27>'  : MotionController/Targeting Controllers/Search for  Target/Find Downward Target/Embedded MATLAB Function
 * '<S28>'  : MotionController/Targeting Controllers/Search for  Target/Find Downward Target/Subsystem
 * '<S29>'  : MotionController/Targeting Controllers/Search for  Target/Find Downward Target/Subsystem/Subsystem
 * '<S30>'  : MotionController/Targeting Controllers/Search for  Target/Find Downward Target/Subsystem/Subsystem/If Action Subsystem
 * '<S31>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Embedded MATLAB Function
 * '<S32>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Subsystem
 * '<S33>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Subsystem/Subsystem
 * '<S34>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Subsystem/Subsystem/If Action Subsystem
 * '<S35>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Subsystem/Subsystem/If Action Subsystem1
 * '<S36>'  : MotionController/Targeting Controllers/Search for  Target/Find Forward Target/Subsystem/Subsystem/If Action Subsystem2
 * '<S37>'  : MotionController/Targeting Controllers/Track Target/Compare To Constant
 * '<S38>'  : MotionController/Targeting Controllers/Track Target/Compare To Constant1
 * '<S39>'  : MotionController/Targeting Controllers/Track Target/Compare To Zero
 * '<S40>'  : MotionController/Targeting Controllers/Track Target/Down Target
 * '<S41>'  : MotionController/Targeting Controllers/Track Target/Forward Target
 * '<S42>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down X Controller
 * '<S43>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Y Controller
 * '<S44>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Yaw Controller
 * '<S45>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down X Controller/Discrete Derivative
 * '<S46>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Y Controller/Discrete Derivative
 * '<S47>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Yaw Controller/Discrete Derivative
 * '<S48>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable
 * '<S49>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable1
 * '<S50>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable2
 * '<S51>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable/Discrete Derivative
 * '<S52>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable1/Discrete Derivative
 * '<S53>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable2/Discrete Derivative
 * '<S54>'  : MotionController/Thruster Arrangement/LeftAngled Friction Compensation
 * '<S55>'  : MotionController/Thruster Arrangement/LeftFwd Friction Compensation
 * '<S56>'  : MotionController/Thruster Arrangement/RightAngled Friction Compensation
 * '<S57>'  : MotionController/Thruster Arrangement/RightFwd Friction Compensation
 */
#endif                                 /* RTW_HEADER_MotionController_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
