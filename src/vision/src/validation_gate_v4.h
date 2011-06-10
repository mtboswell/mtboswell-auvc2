/*
 * File: validation_gate_v4.h
 *
 * Real-Time Workshop code generated for Simulink model validation_gate_v4.
 *
 * Model version                        : 1.1120
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:27:34 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:27:34 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_validation_gate_v4_h_
#define RTW_HEADER_validation_gate_v4_h_
#ifndef validation_gate_v4_COMMON_INCLUDES_
# define validation_gate_v4_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rtw_shared_utils.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_pow_snf.h"
#endif                                 /* validation_gate_v4_COMMON_INCLUDES_ */

#include "validation_gate_v4_types.h"

/* Block signals for system '<S8>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S8>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_validation_ga;

/* Block signals for model 'validation_gate_v4' */
typedef struct {
  real_T hough_table[71820];
  real_T ColorSpaceConversion1_o1[19200];/* '<S7>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S7>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S7>/Color Space  Conversion1' */
  real_T LabelMatrix[19200];           /* '<S9>/LabSegmentation' */
  uint32_T y[19200];
  real_T Resize[4800];                 /* '<S15>/Resize' */
  real_T Resize1[4800];                /* '<S15>/Resize1' */
  real_T Resize2[4800];                /* '<S15>/Resize2' */
  real_T HoughTransform1_o1[71820];    /* '<Root>/Hough Transform1' */
  uint32_T LabelMatrix_m[4800];
  real_T HoughTransform1_o2[180];      /* '<Root>/Hough Transform1' */
  real_T HoughTransform1_o3[399];      /* '<Root>/Hough Transform1' */
  boolean_T EdgeDetection[19200];      /* '<Root>/Edge Detection' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter2;/* '<S8>/Low Pass Filter2' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter1;/* '<S8>/Low Pass Filter1' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter;/* '<S8>/Low Pass Filter' */
} rtB_mr_validation_gate_v4;

/* Block states (auto storage) for model 'validation_gate_v4' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S7>/Color Space  Conversion1' */
  real_T EdgeDetection_GV_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GH_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GRAD_SUM_DW[19200];/* '<Root>/Edge Detection' */
  real_T Resize_IntBuffer[12800];      /* '<S15>/Resize' */
  real_T Resize1_IntBuffer[12800];     /* '<S15>/Resize1' */
  real_T Resize2_IntBuffer[12800];     /* '<S15>/Resize2' */
  real_T EdgeDetection_MEAN_FACTOR_DW; /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<Root>/Edge Detection' */
} rtDW_mr_validation_gate_v4;

/* Real-time Model Data Structure */
struct RT_MODEL_validation_gate_v4 {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_validation_gate_v4 rtb;
  rtDW_mr_validation_gate_v4 rtdw;
  RT_MODEL_validation_gate_v4 rtm;
} rtMdlrefDWork_mr_validation_gat;

/* Exported functions */

/* Exported functions */

/* Model reference registration function */
extern void mr_validation_gate_v_initialize(const char_T **rt_errorStatus,
  RT_MODEL_validation_gate_v4 *const validation_gate_v4_M,
  rtB_mr_validation_gate_v4 *localB, rtDW_mr_validation_gate_v4 *localDW);
extern void validation_gate_v_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_validation_ga *localB);
extern void mr_validation_gate_v4_Init(rtDW_mr_validation_gate_v4 *localDW);
extern void mr_validation_gate_v4(const real_T rtu_R_forward_in[19200], const
  real_T rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, rtB_mr_validation_gate_v4 *localB,
  rtDW_mr_validation_gate_v4 *localDW);

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
 * '<Root>' : validation_gate_v4
 * '<S1>'   : validation_gate_v4/Convert to BW
 * '<S2>'   : validation_gate_v4/Identify Validation Gate
 * '<S3>'   : validation_gate_v4/Convert to BW/Hue Higher Comparison
 * '<S4>'   : validation_gate_v4/Convert to BW/Hue Lower Comparison
 * '<S5>'   : validation_gate_v4/Convert to BW/Identify Validation Gate1
 * '<S6>'   : validation_gate_v4/Convert to BW/Identify Validation Gate2
 * '<S7>'   : validation_gate_v4/Convert to BW/IterativeSegmentation
 * '<S8>'   : validation_gate_v4/Convert to BW/IterativeSegmentation/Low Pass Filter
 * '<S9>'   : validation_gate_v4/Convert to BW/IterativeSegmentation/Segmentation
 * '<S10>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S11>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S12>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S13>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S14>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S15>'  : validation_gate_v4/Convert to BW/IterativeSegmentation/Segmentation/Resize
 */
#endif                                 /* RTW_HEADER_validation_gate_v4_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
