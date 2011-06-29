/*
 * File: VisionModel.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.470
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun 28 18:13:43 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun 28 18:13:43 2011
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
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* VisionModel_COMMON_INCLUDES_ */

#include "VisionModel_types.h"

/* Child system includes */
#include "validation_gate.h"
#include "path_detector.h"
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
  real_T buoy_detectormdl_o1;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o2;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o3;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o4;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o5;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o6;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o7;          /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o9[19200];   /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o10[19200];  /* '<S1>/buoy_detector.mdl' */
  real_T buoy_detectormdl_o11[19200];  /* '<S1>/buoy_detector.mdl' */
  real_T validation_gatemdl_o1;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o2;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o3;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o4;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o5;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o6;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o7;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o8;        /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o9[19200]; /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o10[19200];/* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o11[19200];/* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o15[71820];/* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o16;       /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o17[150];  /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o18[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o19[200];  /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o20[100];  /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o21[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o22[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o23[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o25[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o26[50];   /* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o1_n;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o2_l;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o3_m;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o4_i;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o5_n;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o6_l;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o7_f;      /* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o8_d[19200];/* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o9_i[19200];/* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o10_n[19200];/* '<S9>/validation_gate.mdl' */
  real_T ColorSpaceConversion1_o1[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion3_o1[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o2[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o3[19200];/* '<S2>/Color Space  Conversion3' */
  real_T validation_gatemdl_o14[19200];/* '<S6>/validation_gate.mdl' */
  real_T validation_gatemdl_o12[19200];/* '<S9>/validation_gate.mdl' */
  real_T validation_gatemdl_o15_m[19200];/* '<S9>/validation_gate.mdl' */
  real_T R_out[19200];                 /* '<Root>/Transform Coordinates1' */
  real_T G_out[19200];                 /* '<Root>/Transform Coordinates1' */
  real_T B_out[19200];                 /* '<Root>/Transform Coordinates1' */
  boolean_T validation_gatemdl_o16_h[19200];/* '<S9>/validation_gate.mdl' */
} BlockIO_VisionModel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion2_DWORK1[19200];/* '<S4>/Color Space  Conversion2' */
  real_T ColorSpaceConversion3_DWORK1[19200];/* '<S2>/Color Space  Conversion3' */
  real_T ColorSpaceConversion4_DWORK1[19200];/* '<S2>/Color Space  Conversion4' */
  rtMdlrefDWork_mr_buoy_detector buoy_detectormdl_DWORK1;/* '<S1>/buoy_detector.mdl' */
  rtMdlrefDWork_mr_path_detector validation_gatemdl_DWORK1;/* '<S6>/validation_gate.mdl' */
  rtMdlrefDWork_mr_validation_gat validation_gatemdl_DWORK1_a;/* '<S9>/validation_gate.mdl' */
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
  real_T TargetDetected;               /* '<Root>/TargetDetected' */
  real_T PathState;                    /* '<Root>/PathState' */
  real_T BuoyColors;                   /* '<Root>/BuoyColors' */
  real_T FireAuthorization;            /* '<Root>/FireAuthorization' */
  real_T R_forward_out[19200];         /* '<Root>/R_forward_out' */
  real_T G_forward_out[19200];         /* '<Root>/G_forward_out' */
  real_T B_forward_out[19200];         /* '<Root>/B_forward_out' */
  real_T R_down_out[19200];            /* '<Root>/R_down_out' */
  real_T G_down_out[19200];            /* '<Root>/G_down_out' */
  real_T B_down_out[19200];            /* '<Root>/B_down_out' */
  real_T Iter_Segment_Thresh;          /* '<Root>/Iter_Segment_Thresh' */
  real_T theta[71820];                 /* '<Root>/theta' */
  real_T LabelMatrix[19200];           /* '<Root>/LabelMatrix' */
  real_T num_colors;                   /* '<Root>/num_colors' */
  real_T ref_colors[150];              /* '<Root>/ref_colors' */
  real_T bw_image[19200];              /* '<Root>/bw_image' */
  real_T edge_image[19200];            /* '<Root>/edge_image' */
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
  real_T Constant2_Value;              /* Expression: Iter_Segment_Thresh
                                        * Referenced by: '<Root>/Constant2'
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
 * '<S8>'   : VisionModel/Transform Coordinates1
 * '<S9>'   : VisionModel/Validation Gate
 */
#endif                                 /* RTW_HEADER_VisionModel_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
