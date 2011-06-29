/*
 * torpedo_private.h
 *
 * Real-Time Workshop code generation for Simulink model "torpedo.mdl".
 *
 * Model version              : 1.59
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Tue Jun  7 01:45:26 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_torpedo_private_h_
#define RTW_HEADER_torpedo_private_h_
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
   *   '<S11>/Resize'
   *   '<S11>/Resize1'
   *   '<S11>/Resize2'
   */
  real_T pooled1[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S11>/Resize'
   *   '<S11>/Resize1'
   *   '<S11>/Resize2'
   */
  real_T pooled2[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S11>/Resize'
   *   '<S11>/Resize1'
   *   '<S11>/Resize2'
   */
  int32_T pooled3[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S11>/Resize'
   *   '<S11>/Resize1'
   *   '<S11>/Resize2'
   */
  int32_T pooled4[320];
} ConstParam_torpedo;

/* Constant parameters (auto storage) */
extern const ConstParam_torpedo torpedo_ConstP;
extern rtC_mr_torpedo torpedo_ConstB;

#endif                                 /* RTW_HEADER_torpedo_private_h_ */
