/*
 * File: buoy_detector_private.h
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.1194
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Wed Jun 22 00:56:52 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Wed Jun 22 00:56:52 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_buoy_detector_private_h_
#define RTW_HEADER_buoy_detector_private_h_
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
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Resize'
   *   '<S13>/Resize1'
   *   '<S13>/Resize2'
   */
  real_T pooled2[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Resize'
   *   '<S13>/Resize1'
   *   '<S13>/Resize2'
   */
  real_T pooled3[240];

  /* Expression: a_range
   * Referenced by: '<Root>/Constant'
   */
  real_T Constant_Value[14];

  /* Expression: b_range
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant1_Value_i[14];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Resize'
   *   '<S13>/Resize1'
   *   '<S13>/Resize2'
   */
  int32_T pooled5[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S13>/Resize'
   *   '<S13>/Resize1'
   *   '<S13>/Resize2'
   */
  int32_T pooled6[240];
} ConstParam_buoy_detector;

/* Constant parameters (auto storage) */
extern const ConstParam_buoy_detector buoy_detector_ConstP;

#endif                                 /* RTW_HEADER_buoy_detector_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
