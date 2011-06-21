/*
 * File: path_detector.h
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.220
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Mon Jun 20 23:28:01 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Mon Jun 20 23:28:01 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_path_detector_h_
#define RTW_HEADER_path_detector_h_
#ifndef path_detector_COMMON_INCLUDES_
# define path_detector_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#endif                                 /* path_detector_COMMON_INCLUDES_ */

#include "path_detector_types.h"

/* Block signals for model 'path_detector' */
typedef struct {
  real_T ColorSpaceConversion1_o3[307200];/* '<Root>/Color Space  Conversion1' */
  real_T HoughTransform1_o1[287820];   /* '<Root>/Hough Transform1' */
  real_T ColorSpaceConversion1_o1[307200];/* '<Root>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[307200];/* '<Root>/Color Space  Conversion1' */
  boolean_T EdgeDetection[307200];     /* '<Root>/Edge Detection' */
} rtB_mr_path_detector;

/* Block states (auto storage) for model 'path_detector' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[307200];/* '<Root>/Color Space  Conversion1' */
  real_T EdgeDetection_GV_SQUARED_DW[307200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GH_SQUARED_DW[307200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GRAD_SUM_DW[307200];/* '<Root>/Edge Detection' */
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
} rtDW_mr_path_detector;

/* Invariant block signals for model 'path_detector' */
typedef const struct tag_rtC_mr_path_detector {
  real_T TmpSignalConversionAtDesire;
  real_T TmpSignalConversionAtDesi_i;
  real_T TmpSignalConversionAtPathDe;
  real_T TmpSignalConversionAtPathSt;
} rtC_mr_path_detector;

/* Real-time Model Data Structure */
struct RT_MODEL_path_detector {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_path_detector rtb;
  rtDW_mr_path_detector rtdw;
  RT_MODEL_path_detector rtm;
} rtMdlrefDWork_mr_path_detector;

/* Model reference registration function */
extern void mr_path_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_path_detector *const path_detector_M, rtB_mr_path_detector *localB,
  rtDW_mr_path_detector *localDW);
extern void mr_path_detector_Init(rtDW_mr_path_detector *localDW);
extern void mr_path_detector(const real_T rtu_R_in[307200], const real_T
  rtu_G_in[307200], const real_T rtu_B_in[307200], rtB_mr_path_detector *localB,
  rtDW_mr_path_detector *localDW);

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
 * '<Root>' : path_detector
 * '<S1>'   : path_detector/CheckConditions
 * '<S2>'   : path_detector/Embedded MATLAB Function
 * '<S3>'   : path_detector/Embedded MATLAB Function1
 * '<S4>'   : path_detector/Embedded MATLAB Function2
 * '<S5>'   : path_detector/Embedded MATLAB Function3
 * '<S6>'   : path_detector/Embedded MATLAB Function4
 * '<S7>'   : path_detector/Identify Path Elements
 */
#endif                                 /* RTW_HEADER_path_detector_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
