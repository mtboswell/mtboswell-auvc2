/*
 * File: VisionModel.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.381
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Mon Jun 20 21:35:26 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Mon Jun 20 21:35:26 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VisionModel_h_
#define RTW_HEADER_VisionModel_h_
#ifndef VisionModel_COMMON_INCLUDES_
# define VisionModel_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* VisionModel_COMMON_INCLUDES_ */

#include "VisionModel_types.h"

/* Child system includes */
#include "validation_gate.h"
#include "torpedo.h"
#include "path_detector.h"
#include "drop_mech.h"
#include "buoy_detector.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T ColorSpaceConversion2_o1[19200];/* '<S4>/Color Space  Conversion2' */
  real_T ColorSpaceConversion2_o2[19200];/* '<S4>/Color Space  Conversion2' */
  real_T ColorSpaceConversion2_o3[19200];/* '<S4>/Color Space  Conversion2' */
  real_T ColorSpaceConversion4_o1[19200];/* '<S2>/Color Space  Conversion4' */
  real_T ColorSpaceConversion4_o2[19200];/* '<S2>/Color Space  Conversion4' */
  real_T ColorSpaceConversion4_o3[19200];/* '<S2>/Color Space  Conversion4' */
  real_T validation_gatemdl_o1;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o2;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o3;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o4;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o5;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o6;        /* '<S8>/validation_gate.mdl' */
  real_T validation_gatemdl_o7;        /* '<S8>/validation_gate.mdl' */
  real_T ColorSpaceConversion1_o1[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion3_o1[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o2[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o3[19200];/* '<S2>/Color Space  Conversion3' */
  real_T TmpSignalConversionAttorp_d[19200];
  real_T TmpSignalConversionAttorp_b[19200];
  real_T TmpSignalConversionAttorped[19200];
  real_T Gain5[19200];                 /* '<S4>/Gain5' */
  real_T Gain4[19200];                 /* '<S4>/Gain4' */
  real_T Gain3[19200];                 /* '<S4>/Gain3' */
} BlockIO_VisionModel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion2_DWORK1[19200];/* '<S4>/Color Space  Conversion2' */
  real_T ColorSpaceConversion3_DWORK1[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion4_DWORK1[19200];/* '<S2>/Color Space  Conversion4' */
  rtMdlrefDWork_mr_drop_mech drop_mechmdl_DWORK1;/* '<S3>/drop_mech.mdl' */
  rtMdlrefDWork_mr_drop_mech L_detectormdl_DWORK1;/* '<S5>/L_detector.mdl' */
  rtMdlrefDWork_mr_torpedo torpedomdl_DWORK1;/* '<S7>/torpedo.mdl' */
  rtMdlrefDWork_mr_buoy_detector buoy_detectormdl_DWORK1;/* '<S1>/buoy_detector.mdl' */
  rtMdlrefDWork_mr_path_detector path_detectormdl_DWORK1;/* '<S6>/path_detector.mdl' */
  rtMdlrefDWork_mr_validation_gat validation_gatemdl_DWORK1;/* '<S8>/validation_gate.mdl' */
} D_Work_VisionModel;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T R_forward_in[19200];          /* '<Root>/R_forward_in' */
  real_T G_forward_in[19200];          /* '<Root>/G_forward_in' */
  real_T B_forward_in[19200];          /* '<Root>/B_forward_in' */
  real_T R_down_in[19200];             /* '<Root>/R_down_in' */
  real_T G_down_in[19200];             /* '<Root>/G_down_in' */
  real_T B_down_in[19200];             /* '<Root>/B_down_in' */
  real_T ModeSelect;                   /* '<Root>/ModeSelect' */
  real_T DesiredPathDirection;         /* '<Root>/DesiredPathDirection' */
  real_T DesiredBuoyColor;             /* '<Root>/DesiredBuoyColor' */
  real_T DesiredTorpedoColor;          /* '<Root>/DesiredTorpedoColor' */
  real_T ProceedToSecondTarget;        /* '<Root>/ProceedToSecondTarget' */
  real_T DefaultTargetShape;           /* '<Root>/DefaultTargetShape' */
  real_T DefaultTargetColor;           /* '<Root>/DefaultTargetColor' */
} ExternalInputs_VisionModel;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T TargetSelect;                 /* '<Root>/TargetSelect' */
  real_T TargetFound;                  /* '<Root>/TargetFound' */
  real_T MaintainHeading;              /* '<Root>/MaintainHeading' */
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
  real_T TargetDetected;               /* '<Root>/TargetDetected' */
  real_T PathState;                    /* '<Root>/PathState' */
  real_T BuoyColors;                   /* '<Root>/BuoyColors' */
  real_T FireAuthorization;            /* '<Root>/FireAuthorization' */
} ExternalOutputs_VisionModel;

/* Parameters (auto storage) */
struct Parameters_VisionModel_ {
  real_T Gain_Gain;                    /* Expression: Scale_Forward_R
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: Scale_Forward_G
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: Scale_Forward_B
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: Scale_Forward_H
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: Scale_Forward_S
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: Scale_Forward_V
                                        * Referenced by: '<S4>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: Scale_Down_R
                                        * Referenced by: '<S2>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: Scale_Down_G
                                        * Referenced by: '<S2>/Gain7'
                                        */
  real_T Gain8_Gain;                   /* Expression: Scale_Down_B
                                        * Referenced by: '<S2>/Gain8'
                                        */
  real_T Gain9_Gain;                   /* Expression: Scale_Down_H
                                        * Referenced by: '<S2>/Gain9'
                                        */
  real_T Gain10_Gain;                  /* Expression: Scale_Down_S
                                        * Referenced by: '<S2>/Gain10'
                                        */
  real_T Gain11_Gain;                  /* Expression: Scale_Down_V
                                        * Referenced by: '<S2>/Gain11'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_VisionModel {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_VisionModel VisionModel_P;

/* Block signals (auto storage) */
extern BlockIO_VisionModel VisionModel_B;

/* Block states (auto storage) */
extern D_Work_VisionModel VisionModel_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_VisionModel VisionModel_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_VisionModel VisionModel_Y;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void VisionModel_initialize(void);
  extern void VisionModel_step(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_VisionModel *VisionModel_M;

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
 * '<Root>' : VisionModel
 * '<S1>'   : VisionModel/Buoy Detection
 * '<S2>'   : VisionModel/Down Filter
 * '<S3>'   : VisionModel/Drop Mechanism Target
 * '<S4>'   : VisionModel/Forward Filter
 * '<S5>'   : VisionModel/L-Obstacle Detection
 * '<S6>'   : VisionModel/Path Following
 * '<S7>'   : VisionModel/Torpedo Target Detection
 * '<S8>'   : VisionModel/Validation Gate
 */
#endif                                 /* RTW_HEADER_VisionModel_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */