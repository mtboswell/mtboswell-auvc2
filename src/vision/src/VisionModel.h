/*
 * File: VisionModel.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.358
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:51:44 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:51:44 2011
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
  real_T TmpSignalConversionAttorped[19200];
  real_T TmpSignalConversionAttorp_b[19200];
  real_T TmpSignalConversionAttorp_d[19200];
} BlockIO_VisionModel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  rtMdlrefDWork_mr_drop_mech drop_mechmdl_DWORK1;/* '<S2>/drop_mech.mdl' */
  rtMdlrefDWork_mr_drop_mech L_detectormdl_DWORK1;/* '<S3>/L_detector.mdl' */
  rtMdlrefDWork_mr_torpedo torpedomdl_DWORK1;/* '<S6>/torpedo.mdl' */
  rtMdlrefDWork_mr_buoy_detector path_detectormdl_DWORK1;/* '<S1>/path_detector.mdl' */
  rtMdlrefDWork_mr_path_detector path_detectormdl_DWORK1_p;/* '<S5>/path_detector.mdl' */
  rtMdlrefDWork_mr_validation_gat validation_gatemdl_DWORK1;/* '<S7>/validation_gate.mdl' */
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
  real_T DefaultTaretShape;            /* '<Root>/DefaultTaretShape' */
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
} ExternalOutputs_VisionModel;

/* Parameters (auto storage) */
struct Parameters_VisionModel_ {
  real_T Constant_Value;               /* Expression: 90
                                        * Referenced by: '<Root>/Constant'
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
  extern void VisionModel_terminate(void);

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
 * '<S2>'   : VisionModel/Drop Mechanism Target
 * '<S3>'   : VisionModel/L-Obstacle Detection
 * '<S4>'   : VisionModel/No longer needed function
 * '<S5>'   : VisionModel/Path Following
 * '<S6>'   : VisionModel/Torpedo Target Detection
 * '<S7>'   : VisionModel/Validation Gate
 */
#endif                                 /* RTW_HEADER_VisionModel_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
