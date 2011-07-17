/*
 * File: VisionModel.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.163
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sun Jul 17 03:26:09 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sun Jul 17 03:26:09 2011
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
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_pow_snf.h"
#endif                                 /* VisionModel_COMMON_INCLUDES_ */

#include "VisionModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S2>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S2>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_VisionModel;

/* Block signals (auto storage) */
typedef struct {
  real_T ColorSpaceConversion1_o1[19200];/* '<Root>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<Root>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<Root>/Color Space  Conversion1' */
  real_T L[19200];                     /* '<Root>/Display Image' */
  real_T a[19200];                     /* '<Root>/Display Image' */
  real_T b[19200];                     /* '<Root>/Display Image' */
  uint32_T LabelMatrix[19200];         /* '<S3>/LabSegmentation' */
  real_T Resize[4800];                 /* '<S10>/Resize' */
  real_T Resize1[4800];                /* '<S10>/Resize1' */
  real_T Resize2[4800];                /* '<S10>/Resize2' */
  uint32_T LabelMatrix_m[4800];
  rtB_LowPassFilter_VisionModel sf_LowPassFilter2;/* '<S2>/Low Pass Filter2' */
  rtB_LowPassFilter_VisionModel sf_LowPassFilter1;/* '<S2>/Low Pass Filter1' */
  rtB_LowPassFilter_VisionModel sf_LowPassFilter;/* '<S2>/Low Pass Filter' */
} BlockIO_VisionModel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<Root>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1[19200];/* '<Root>/Color Space  Conversion' */
  real_T Resize_IntBuffer[12800];      /* '<S10>/Resize' */
  real_T Resize1_IntBuffer[12800];     /* '<S10>/Resize1' */
  real_T Resize2_IntBuffer[12800];     /* '<S10>/Resize2' */
} D_Work_VisionModel;

/* Invariant block signals (auto storage) */
typedef const struct tag_ConstBlockIO_VisionModel {
  real_T Add;                          /* '<Root>/Add' */
  real_T Add3;                         /* '<Root>/Add3' */
  real_T Add4;                         /* '<Root>/Add4' */
  real_T Add5;                         /* '<Root>/Add5' */
  real_T Add6;                         /* '<Root>/Add6' */
  real_T Add18;                        /* '<Root>/Add18' */
  real_T Add19;                        /* '<Root>/Add19' */
  real_T Add21;                        /* '<Root>/Add21' */
} ConstBlockIO_VisionModel;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/Resize'
   *   '<S10>/Resize1'
   *   '<S10>/Resize2'
   */
  real_T pooled1[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/Resize'
   *   '<S10>/Resize1'
   *   '<S10>/Resize2'
   */
  real_T pooled2[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/Resize'
   *   '<S10>/Resize1'
   *   '<S10>/Resize2'
   */
  int32_T pooled4[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/Resize'
   *   '<S10>/Resize1'
   *   '<S10>/Resize2'
   */
  int32_T pooled5[240];
} ConstParam_VisionModel;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T R_forward_in[19200];          /* '<Root>/R_forward_in' */
  real_T G_forward_in[19200];          /* '<Root>/G_forward_in' */
  real_T B_forward_in[19200];          /* '<Root>/B_forward_in' */
  real_T R_down_in[19200];             /* '<Root>/R_down_in' */
  real_T G_down_in[19200];             /* '<Root>/G_down_in' */
  real_T B_down_in[19200];             /* '<Root>/B_down_in' */
  real_T ModeSelect;                   /* '<Root>/ModeSelect' */
  real_T OutputImage;                  /* '<Root>/OutputImage' */
  real_T DesiredPathDirection;         /* '<Root>/DesiredPathDirection' */
  real_T DesiredBuoyColor;             /* '<Root>/DesiredBuoyColor' */
  real_T DesiredTorpedoColor;          /* '<Root>/DesiredTorpedoColor' */
  real_T white_al;                     /* '<Root>/white_al' */
  real_T white_au;                     /* '<Root>/white_au' */
  real_T white_bl;                     /* '<Root>/white_bl' */
  real_T white_bu;                     /* '<Root>/white_bu' */
  real_T black_al;                     /* '<Root>/black_al' */
  real_T black_au;                     /* '<Root>/black_au' */
  real_T black_bl;                     /* '<Root>/black_bl' */
  real_T black_bu;                     /* '<Root>/black_bu' */
  real_T blue_al;                      /* '<Root>/blue_al' */
  real_T blue_au;                      /* '<Root>/blue_au' */
  real_T blue_bl;                      /* '<Root>/blue_bl' */
  real_T blue_bu;                      /* '<Root>/blue_bu' */
  real_T red_al;                       /* '<Root>/red_al' */
  real_T red_au;                       /* '<Root>/red_au' */
  real_T red_bl;                       /* '<Root>/red_bl' */
  real_T red_bu;                       /* '<Root>/red_bu' */
  real_T orange_al;                    /* '<Root>/orange_al' */
  real_T orange_au;                    /* '<Root>/orange_au' */
  real_T orange_bl;                    /* '<Root>/orange_bl' */
  real_T orange_bu;                    /* '<Root>/orange_bu' */
  real_T yellow_al;                    /* '<Root>/yellow_al' */
  real_T yellow_au;                    /* '<Root>/yellow_au' */
  real_T yellow_bl;                    /* '<Root>/yellow_bl' */
  real_T yellow_bu;                    /* '<Root>/yellow_bu' */
  real_T green_al;                     /* '<Root>/green_al' */
  real_T green_au;                     /* '<Root>/green_au' */
  real_T green_bl;                     /* '<Root>/green_bl' */
  real_T green_bu;                     /* '<Root>/green_bu' */
  real_T black_override;               /* '<Root>/black_override' */
  real_T white_override;               /* '<Root>/white_override' */
  real_T blue_override;                /* '<Root>/blue_override' */
  real_T red_override;                 /* '<Root>/red_override' */
  real_T orange_override;              /* '<Root>/orange_override' */
  real_T yellow_override;              /* '<Root>/yellow_override' */
  real_T green_override;               /* '<Root>/green_override' */
  real_T Scale_Forward_R;              /* '<Root>/Scale_Forward_R' */
  real_T Scale_Forward_G;              /* '<Root>/Scale_Forward_G' */
  real_T Scale_Forward_B;              /* '<Root>/Scale_Forward_B' */
  real_T Scale_Forward_H;              /* '<Root>/Scale_Forward_H' */
  real_T Scale_Forward_S;              /* '<Root>/Scale_Forward_S' */
  real_T Scale_Forward_V;              /* '<Root>/Scale_Forward_V' */
  real_T Scale_Down_R;                 /* '<Root>/Scale_Down_R' */
  real_T Scale_Down_G;                 /* '<Root>/Scale_Down_G' */
  real_T Scale_Down_B;                 /* '<Root>/Scale_Down_B' */
  real_T Scale_Down_H;                 /* '<Root>/Scale_Down_H' */
  real_T Scale_Down_S;                 /* '<Root>/Scale_Down_S' */
  real_T Scale_Down_V;                 /* '<Root>/Scale_Down_V' */
  real_T DeadReckonHeading;            /* '<Root>/DeadReckonHeading' */
} ExternalInputs_VisionModel;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T R_forward_out[19200];         /* '<Root>/R_forward_out' */
  real_T G_forward_out[19200];         /* '<Root>/G_forward_out' */
  real_T B_forward_out[19200];         /* '<Root>/B_forward_out' */
  real_T R_down_out;                   /* '<Root>/R_down_out' */
  real_T G_down_out;                   /* '<Root>/G_down_out' */
  real_T B_down_out;                   /* '<Root>/B_down_out' */
  real_T TargetSelect;                 /* '<Root>/TargetSelect' */
  real_T TargetX;                      /* '<Root>/TargetX' */
  real_T TargetY;                      /* '<Root>/TargetY' */
  real_T TargetZ;                      /* '<Root>/TargetZ' */
  real_T TargetYaw;                    /* '<Root>/TargetYaw' */
  real_T DesiredTargetX;               /* '<Root>/DesiredTargetX' */
  real_T DesiredTargetY;               /* '<Root>/DesiredTargetY' */
  real_T DesiredTargetZ;               /* '<Root>/DesiredTargetZ' */
  real_T DesiredTargetYaw;             /* '<Root>/DesiredTargetYaw' */
  real_T TargetDetected;               /* '<Root>/TargetDetected' */
  real_T PathState;                    /* '<Root>/PathState' */
  real_T BuoyColors;                   /* '<Root>/BuoyColors' */
  real_T FireAuthorization;            /* '<Root>/FireAuthorization' */
  real_T TargetType;                   /* '<Root>/TargetType' */
  real_T TargetSize;                   /* '<Root>/TargetSize' */
} ExternalOutputs_VisionModel;

/* Real-time Model Data Structure */
struct RT_MODEL_VisionModel {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_VisionModel VisionModel_B;

/* Block states (auto storage) */
extern D_Work_VisionModel VisionModel_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_VisionModel VisionModel_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_VisionModel VisionModel_Y;
extern const ConstBlockIO_VisionModel VisionModel_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstParam_VisionModel VisionModel_ConstP;

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
 * '<S1>'   : VisionModel/Display Image
 * '<S2>'   : VisionModel/Low Pass Filter
 * '<S3>'   : VisionModel/Segmentation
 * '<S4>'   : VisionModel/make_color_range
 * '<S5>'   : VisionModel/Low Pass Filter/Low Pass Filter
 * '<S6>'   : VisionModel/Low Pass Filter/Low Pass Filter1
 * '<S7>'   : VisionModel/Low Pass Filter/Low Pass Filter2
 * '<S8>'   : VisionModel/Segmentation/LabSegmentation
 * '<S9>'   : VisionModel/Segmentation/Reference Color Selection
 * '<S10>'  : VisionModel/Segmentation/Resize
 */
#endif                                 /* RTW_HEADER_VisionModel_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
