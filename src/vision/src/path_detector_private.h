/*
 * File: path_detector_private.h
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.220
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:26:52 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:26:52 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_path_detector_private_h_
#define RTW_HEADER_path_detector_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  real_T EdgeDetection_VC_RTP[6];

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  real_T EdgeDetection_HC_RTP[6];

  /* Computed Parameter: HoughTransform1_SINE
   * Referenced by: '<Root>/Hough Transform1'
   */
  real_T HoughTransform1_SINE[91];

  /* Computed Parameter: HoughTransform1_FIRSTRHO_R
   * Referenced by: '<Root>/Hough Transform1'
   */
  real_T HoughTransform1_FIRSTRHO_R;

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_VRO_RTP[6];

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_VCO_RTP[6];

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_HRO_RTP[6];

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_HCO_RTP[6];
} ConstParam_path_detector;

/* Constant parameters (auto storage) */
extern const ConstParam_path_detector path_detector_ConstP;
extern rtC_mr_path_detector path_detector_ConstB;

#endif                                 /* RTW_HEADER_path_detector_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
