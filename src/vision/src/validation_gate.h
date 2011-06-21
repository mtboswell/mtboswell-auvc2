/*
 * File: validation_gate.h
 *
 * Real-Time Workshop code generated for Simulink model validation_gate.
 *
 * Model version                        : 1.1174
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun 21 01:40:54 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun 21 01:40:54 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_validation_gate_h_
#define RTW_HEADER_validation_gate_h_
#ifndef validation_gate_COMMON_INCLUDES_
# define validation_gate_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rtw_shared_utils.h"
#include "rt_nonfinite.h"
#include "rt_pow_snf.h"
#endif                                 /* validation_gate_COMMON_INCLUDES_ */

#include "validation_gate_types.h"

/* Block signals for system '<S5>/Low Pass Filter' */
typedef struct {
  real_T Iout[307200];                 /* '<S5>/Low Pass Filter' */
  real_T Itemp[304964];
} rtB_LowPassFilter_validation_ga;

/* Block signals for model 'validation_gate' */
typedef struct {
  real_T ColorSpaceConversion1_o1[307200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[307200];/* '<S4>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[307200];/* '<S4>/Color Space  Conversion1' */
  real_T hough_table[287820];
  uint32_T LabelMatrix[307200];        /* '<S6>/LabSegmentation' */
  int8_T intensity_image[307200];      /* '<S1>/Identify Validation Gate2' */
  real_T Resize[4800];                 /* '<S12>/Resize' */
  real_T Resize1[4800];                /* '<S12>/Resize1' */
  real_T Resize2[4800];                /* '<S12>/Resize2' */
  real_T HoughTransform1_o1[287820];   /* '<Root>/Hough Transform1' */
  uint32_T LabelMatrix_m[4800];
  real_T HoughTransform1_o2[180];      /* '<Root>/Hough Transform1' */
  real_T HoughTransform1_o3[1599];     /* '<Root>/Hough Transform1' */
  boolean_T EdgeDetection[307200];     /* '<Root>/Edge Detection' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter2;/* '<S5>/Low Pass Filter2' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter1;/* '<S5>/Low Pass Filter1' */
  rtB_LowPassFilter_validation_ga sf_LowPassFilter;/* '<S5>/Low Pass Filter' */
} rtB_mr_validation_gate;

/* Block states (auto storage) for model 'validation_gate' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[307200];/* '<S4>/Color Space  Conversion1' */
  real_T EdgeDetection_GV_SQUARED_DW[307200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GH_SQUARED_DW[307200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GRAD_SUM_DW[307200];/* '<Root>/Edge Detection' */
  real_T Resize_IntBuffer[51200];      /* '<S12>/Resize' */
  real_T Resize1_IntBuffer[51200];     /* '<S12>/Resize1' */
  real_T Resize2_IntBuffer[51200];     /* '<S12>/Resize2' */
  real_T Resize2_LineBuffer[640];      /* '<S12>/Resize2' */
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
} rtDW_mr_validation_gate;

/* Real-time Model Data Structure */
struct RT_MODEL_validation_gate {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_validation_gate rtb;
  rtDW_mr_validation_gate rtdw;
  RT_MODEL_validation_gate rtm;
} rtMdlrefDWork_mr_validation_gat;

/* Exported functions */

/* Exported functions */

/* Model reference registration function */
extern void mr_validation_gate_initialize(const char_T **rt_errorStatus,
  RT_MODEL_validation_gate *const validation_gate_M, rtB_mr_validation_gate
  *localB, rtDW_mr_validation_gate *localDW);
extern void validation_gate_LowPassFilter(const real_T rtu_I[307200],
  rtB_LowPassFilter_validation_ga *localB);
extern void mr_validation_gate_Init(rtDW_mr_validation_gate *localDW);
extern void mr_validation_gate(const real_T rtu_R_forward_in[307200], const
  real_T rtu_G_forward_in[307200], const real_T rtu_B_forward_in[307200], real_T
  *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, rtB_mr_validation_gate *localB, rtDW_mr_validation_gate
  *localDW);

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
 * '<Root>' : validation_gate
 * '<S1>'   : validation_gate/Convert to BW
 * '<S2>'   : validation_gate/Identify Validation Gate
 * '<S3>'   : validation_gate/Convert to BW/Identify Validation Gate2
 * '<S4>'   : validation_gate/Convert to BW/IterativeSegmentation
 * '<S5>'   : validation_gate/Convert to BW/IterativeSegmentation/Low Pass Filter
 * '<S6>'   : validation_gate/Convert to BW/IterativeSegmentation/Segmentation
 * '<S7>'   : validation_gate/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S8>'   : validation_gate/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S9>'   : validation_gate/Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S10>'  : validation_gate/Convert to BW/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S11>'  : validation_gate/Convert to BW/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S12>'  : validation_gate/Convert to BW/IterativeSegmentation/Segmentation/Resize
 */
#endif                                 /* RTW_HEADER_validation_gate_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
