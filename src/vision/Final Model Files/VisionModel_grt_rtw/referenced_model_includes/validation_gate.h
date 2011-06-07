/*
 * Real-Time Workshop code generation for Simulink model 'validation_gate'
 * For more details, see corresponding source file validation_gate.c
 *
 */
#ifndef RTW_HEADER_validation_gate_h_
#define RTW_HEADER_validation_gate_h_
#ifndef validation_gate_COMMON_INCLUDES_
# define validation_gate_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "viphough_rt.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* validation_gate_COMMON_INCLUDES_ */

#include "validation_gate_types.h"

/* Block signals for model 'validation_gate' */
typedef struct {
  real_T hough_table[71820];
  real_T ColorSpaceConversion2_o3[19200];/* '<S1>/Color Space  Conversion2' */
  real_T HoughTransform1_o1[71820];    /* '<Root>/Hough Transform1' */
  real_T HoughTransform1_o2[180];      /* '<Root>/Hough Transform1' */
  real_T HoughTransform1_o3[399];      /* '<Root>/Hough Transform1' */
  real_T ColorSpaceConversion2_o1[19200];/* '<S1>/Color Space  Conversion2' */
  real_T ColorSpaceConversion2_o2[19200];/* '<S1>/Color Space  Conversion2' */
  boolean_T EdgeDetection[19200];      /* '<Root>/Edge Detection' */
} rtB_mr_validation_gate;

/* Block states (auto storage) for model 'validation_gate' */
typedef struct {
  real_T ColorSpaceConversion2_DWORK1[19200];/* '<S1>/Color Space  Conversion2' */
  real_T EdgeDetection_GV_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GH_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GRAD_SUM_DW[19200];/* '<Root>/Edge Detection' */
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

/* Invariant block signals for model 'validation_gate' */
typedef const struct tag_rtC_mr_validation_gate {
  real_T TmpSignalConversionAtTarget;
  real_T TmpSignalConversionAtTarg_f;
  real_T TmpSignalConversionAtMainta;
  real_T TmpSignalConversionAtTarg_g;
  real_T TmpSignalConversionAtTarg_h;
  real_T TmpSignalConversionAtTarg_i;
} rtC_mr_validation_gate;

/* Real-time Model Data Structure */
struct RT_MODEL_validation_gate {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_validation_gate rtb;
  rtDW_mr_validation_gate rtdw;
  RT_MODEL_validation_gate rtm;
} rtMdlrefDWork_mr_validation_gat;

/* Model reference registration function */
extern void mr_validation_gate_initialize(boolean_T firstTime, const char_T
  **rt_errorStatus, RT_MODEL_validation_gate *const validation_gate_M,
  rtB_mr_validation_gate *localB, rtDW_mr_validation_gate *localDW);
extern void mr_validation_gate_Init(rtDW_mr_validation_gate *localDW);
extern void mr_validation_gate(const real_T rtu_R_forward_in[19200], const
  real_T rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
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
 * '<S3>'   : validation_gate/Convert to BW/Hue Higher Comparison
 * '<S4>'   : validation_gate/Convert to BW/Hue Lower Comparison
 * '<S5>'   : validation_gate/Convert to BW/Identify Validation Gate1
 */
#endif                                 /* RTW_HEADER_validation_gate_h_ */
