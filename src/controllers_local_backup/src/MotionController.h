/*
 * File: MotionController.h
 *
 * Real-Time Workshop code generated for Simulink model MotionController.
 *
 * Model version                        : 1.82
 * Real-Time Workshop file version      : 7.6.1  (R2010bSP1)  28-Jan-2011
 * Real-Time Workshop file generated on : Wed May 18 14:32:40 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Wed May 18 14:32:41 2011
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
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* MotionController_COMMON_INCLUDES_ */

#include "MotionController_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<S28>/Down X Controller' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S33>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S30>/Discrete-Time Integrator' */
  boolean_T DownXController_MODE;      /* '<S28>/Down X Controller' */
} rtDW_DownXController_MotionCont;

/* Block states (auto storage) for system '<S28>/Down Yaw Controller' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S35>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S32>/Discrete-Time Integrator' */
  boolean_T DownYawController_MODE;    /* '<S28>/Down Yaw Controller' */
} rtDW_DownYawController_MotionCo;

/* Block signals (auto storage) */
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
} BlockIO_MotionController;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S22>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S21>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_j;                  /* '<S39>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S36>/Discrete-Time Integrator' */
  real_T UD_DSTATE_jn;                 /* '<S20>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S18>/Heading Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S8>/Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S19>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_a;/* '<S17>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_jj;                 /* '<S16>/UD' */
  real_T HeadingDiscreteTimeIntegrator_l;/* '<S11>/Heading Discrete-Time Integrator' */
  int8_T If_ActiveSubsystem;           /* '<S5>/If' */
  int8_T If_ActiveSubsystem_b;         /* '<S3>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S10>/If' */
  boolean_T TargetingControllers_MODE; /* '<Root>/Targeting Controllers' */
  boolean_T PIDControllerwithEnable_MODE;/* '<S29>/PID Controller with Enable' */
  rtDW_DownYawController_MotionCo PIDControllerwithEnable2;/* '<S29>/PID Controller with Enable2' */
  rtDW_DownYawController_MotionCo PIDControllerwithEnable1;/* '<S29>/PID Controller with Enable1' */
  rtDW_DownYawController_MotionCo DownYawController;/* '<S28>/Down Yaw Controller' */
  rtDW_DownXController_MotionCont DownYController;/* '<S28>/Down Y Controller' */
  rtDW_DownXController_MotionCont DownXController;/* '<S28>/Down X Controller' */
} D_Work_MotionController;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T TargetSelect;                 /* '<Root>/TargetSelect' */
  real_T TargetFound;                  /* '<Root>/TargetFound' */
  uint8_T MaintainHeading;             /* '<Root>/MaintainHeading' */
  real_T TargetX;                      /* '<Root>/TargetX' */
  real_T TargetY;                      /* '<Root>/TargetY' */
  real_T TargetZ;                      /* '<Root>/TargetZ' */
  real_T TargetYaw;                    /* '<Root>/TargetYaw' */
  real_T DesiredTargetX;               /* '<Root>/DesiredTargetX' */
  real_T DesiredTargetY;               /* '<Root>/DesiredTargetY' */
  real_T DesiredTargetZ;               /* '<Root>/DesiredTargetZ' */
  real_T DesiredTargetYaw;             /* '<Root>/DesiredTargetYaw' */
  real_T MeasuredZ;                    /* '<Root>/MeasuredZ' */
  real_T MeasuredYAccel;               /* '<Root>/MeasuredYAccel' */
  real_T MeasuredYaw;                  /* '<Root>/MeasuredYaw' */
  real_T MeasuredYawRate;              /* '<Root>/MeasuredYawRate' */
  real_T DesiredZ;                     /* '<Root>/DesiredZ' */
  real_T DesiredXVelocity;             /* '<Root>/DesiredXVelocity' */
  real_T DesiredYaw;                   /* '<Root>/DesiredYaw' */
} ExternalInputs_MotionController;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T LeftFwd;                      /* '<Root>/LeftFwd' */
  real_T RightFwd;                     /* '<Root>/RightFwd' */
  real_T LeftAngled;                   /* '<Root>/LeftAngled' */
  real_T RightAngled;                  /* '<Root>/RightAngled' */
} ExternalOutputs_MotionControlle;

/* Parameters (auto storage) */
struct Parameters_MotionController_ {
  real_T Compass_Yaw_Kd;               /* Variable: Compass_Yaw_Kd
                                        * Referenced by: '<S11>/Heading Derivative Gain'
                                        */
  real_T Compass_Yaw_Ki;               /* Variable: Compass_Yaw_Ki
                                        * Referenced by: '<S11>/Heading Integral Gain'
                                        */
  real_T Compass_Yaw_Kp;               /* Variable: Compass_Yaw_Kp
                                        * Referenced by: '<S11>/Heading Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by: '<S21>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by: '<S21>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by: '<S21>/Depth Proportional Gain'
                                        */
  real_T IMU_YVel_Kd;                  /* Variable: IMU_YVel_Kd
                                        * Referenced by: '<S17>/Y-Accelerometer Derivative Gain'
                                        */
  real_T IMU_YVel_Ki;                  /* Variable: IMU_YVel_Ki
                                        * Referenced by: '<S17>/Y-Accelerometer Integral Gain'
                                        */
  real_T IMU_YVel_Kp;                  /* Variable: IMU_YVel_Kp
                                        * Referenced by: '<S17>/Y-Accelerometer Proportional Gain'
                                        */
  real_T IMU_YawRate_Kd;               /* Variable: IMU_YawRate_Kd
                                        * Referenced by: '<S18>/YawRate Derivative Gain'
                                        */
  real_T IMU_YawRate_Ki;               /* Variable: IMU_YawRate_Ki
                                        * Referenced by: '<S18>/YawRate Integral Gain'
                                        */
  real_T IMU_YawRate_Kp;               /* Variable: IMU_YawRate_Kp
                                        * Referenced by: '<S18>/YawRate Proportional Gain'
                                        */
  real_T Target_Down_X_Kd;             /* Variable: Target_Down_X_Kd
                                        * Referenced by: '<S28>/Down X Controller'
                                        */
  real_T Target_Down_X_Ki;             /* Variable: Target_Down_X_Ki
                                        * Referenced by: '<S28>/Down X Controller'
                                        */
  real_T Target_Down_X_Kp;             /* Variable: Target_Down_X_Kp
                                        * Referenced by: '<S28>/Down X Controller'
                                        */
  real_T Target_Down_Y_Kd;             /* Variable: Target_Down_Y_Kd
                                        * Referenced by: '<S28>/Down Y Controller'
                                        */
  real_T Target_Down_Y_Ki;             /* Variable: Target_Down_Y_Ki
                                        * Referenced by: '<S28>/Down Y Controller'
                                        */
  real_T Target_Down_Y_Kp;             /* Variable: Target_Down_Y_Kp
                                        * Referenced by: '<S28>/Down Y Controller'
                                        */
  real_T Target_Down_Yaw_Kd;           /* Variable: Target_Down_Yaw_Kd
                                        * Referenced by: '<S28>/Down Yaw Controller'
                                        */
  real_T Target_Down_Yaw_Ki;           /* Variable: Target_Down_Yaw_Ki
                                        * Referenced by: '<S28>/Down Yaw Controller'
                                        */
  real_T Target_Down_Yaw_Kp;           /* Variable: Target_Down_Yaw_Kp
                                        * Referenced by: '<S28>/Down Yaw Controller'
                                        */
  real_T Target_Forward_Y_Kd;          /* Variable: Target_Forward_Y_Kd
                                        * Referenced by: '<S29>/PID Controller with Enable2'
                                        */
  real_T Target_Forward_Y_Ki;          /* Variable: Target_Forward_Y_Ki
                                        * Referenced by: '<S29>/PID Controller with Enable2'
                                        */
  real_T Target_Forward_Y_Kp;          /* Variable: Target_Forward_Y_Kp
                                        * Referenced by: '<S29>/PID Controller with Enable2'
                                        */
  real_T Target_Forward_Yaw_Kd;        /* Variable: Target_Forward_Yaw_Kd
                                        * Referenced by: '<S29>/PID Controller with Enable1'
                                        */
  real_T Target_Forward_Yaw_Ki;        /* Variable: Target_Forward_Yaw_Ki
                                        * Referenced by: '<S29>/PID Controller with Enable1'
                                        */
  real_T Target_Forward_Yaw_Kp;        /* Variable: Target_Forward_Yaw_Kp
                                        * Referenced by: '<S29>/PID Controller with Enable1'
                                        */
  real_T Target_Forward_Z_Kd;          /* Variable: Target_Forward_Z_Kd
                                        * Referenced by: '<S36>/Derivative Gain'
                                        */
  real_T Target_Forward_Z_Ki;          /* Variable: Target_Forward_Z_Ki
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T Target_Forward_Z_Kp;          /* Variable: Target_Forward_Z_Kp
                                        * Referenced by: '<S36>/Proportional Gain'
                                        */
  real_T Thruster_Friction_Zero;       /* Variable: Thruster_Friction_Zero
                                        * Referenced by:
                                        *   '<S42>/Gain'
                                        *   '<S42>/Gain1'
                                        *   '<S43>/Gain'
                                        *   '<S43>/Gain1'
                                        *   '<S44>/Gain'
                                        *   '<S44>/Gain1'
                                        *   '<S45>/Gain'
                                        *   '<S45>/Gain1'
                                        */
  real_T Thruster_LeftAngled_Gain;     /* Variable: Thruster_LeftAngled_Gain
                                        * Referenced by: '<S4>/LeftAngled Thruster Normalize'
                                        */
  real_T Thruster_LeftFwd_Gain;        /* Variable: Thruster_LeftFwd_Gain
                                        * Referenced by: '<S4>/LeftFwd Thruster  Normalize'
                                        */
  real_T Thruster_RightAngled_Gain;    /* Variable: Thruster_RightAngled_Gain
                                        * Referenced by: '<S4>/RightAngled Thruster Normalize'
                                        */
  real_T Thruster_RightFwd_Gain;       /* Variable: Thruster_RightFwd_Gain
                                        * Referenced by: '<S4>/RightFwd Thruster Normalize'
                                        */
  real_T ZVelocity_Neg_Max;            /* Variable: ZVelocity_Neg_Max
                                        * Referenced by: '<S4>/Buoyancy  Compensation Limiter'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_MotionController {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_MotionController MotionController_P;

/* Block signals (auto storage) */
extern BlockIO_MotionController MotionController_B;

/* Block states (auto storage) */
extern D_Work_MotionController MotionController_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_MotionController MotionController_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_MotionControlle MotionController_Y;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void MotionController_initialize(void);
  extern void MotionController_step(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_MotionController *MotionController_M;

#ifdef __cplusplus

}
#endif

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
 * '<S25>'  : MotionController/Targeting Controllers/Track Target/Compare To Constant
 * '<S26>'  : MotionController/Targeting Controllers/Track Target/Compare To Constant1
 * '<S27>'  : MotionController/Targeting Controllers/Track Target/Compare To Zero
 * '<S28>'  : MotionController/Targeting Controllers/Track Target/Down Target
 * '<S29>'  : MotionController/Targeting Controllers/Track Target/Forward Target
 * '<S30>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down X Controller
 * '<S31>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Y Controller
 * '<S32>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Yaw Controller
 * '<S33>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down X Controller/Discrete Derivative
 * '<S34>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Y Controller/Discrete Derivative
 * '<S35>'  : MotionController/Targeting Controllers/Track Target/Down Target/Down Yaw Controller/Discrete Derivative
 * '<S36>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable
 * '<S37>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable1
 * '<S38>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable2
 * '<S39>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable/Discrete Derivative
 * '<S40>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable1/Discrete Derivative
 * '<S41>'  : MotionController/Targeting Controllers/Track Target/Forward Target/PID Controller with Enable2/Discrete Derivative
 * '<S42>'  : MotionController/Thruster Arrangement/LeftAngled Friction Compensation
 * '<S43>'  : MotionController/Thruster Arrangement/LeftFwd Friction Compensation
 * '<S44>'  : MotionController/Thruster Arrangement/RightAngled Friction Compensation
 * '<S45>'  : MotionController/Thruster Arrangement/RightFwd Friction Compensation
 */
#endif                                 /* RTW_HEADER_MotionController_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
