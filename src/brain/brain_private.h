/*
 * File: brain_private.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.544
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Sun Jul  4 13:35:43 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Sun Jul  4 13:35:46 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_private_h_
#define RTW_HEADER_brain_private_h_
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

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra
  *localB);
extern void StateFlowFunctionsBuoysApp_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysApp *localDW);
extern void StateFlowFunctionsBuoysApproach(real_T rtu_B_Hue, real_T rtu_B_Sat,
  real_T rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T
  rtu_Ref_Colors[150], real_T rtu_Num_Colors, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsBuoysAppr *localB, rtDW_StateFlowFunctionsBuoysApp
  *localDW);
extern void StateFlowFunctionsBuoysFin_Init(rtDW_StateFlowFunctionsBuoysFin
  *localDW);
extern void StateFlowFunctionsBuoysFindBuoy(const real_T rtu_LabMatrix[19200],
  real_T rtu_num_colors, rtB_StateFlowFunctionsBuoysFind *localB,
  rtDW_StateFlowFunctionsBuoysFin *localDW);
extern void brain_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_brain *localB);
extern void StateFlowFunctionsBuoysIterativ(const real_T rtu_H[19200], const
  real_T rtu_S[19200], const real_T rtu_V[19200],
  rtB_StateFlowFunctionsBuoysIter *localB, rtDW_StateFlowFunctionsBuoysIte
  *localDW);
extern void StateFlowFunctionsMaintain_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaintai_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaint_Disable(rtB_StateFlowFunctionsMaintainH
  *localB, rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaintainHeadi(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *const
  brain_M, rtB_StateFlowFunctionsMaintainH *localB,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsFollowOnePath(const real_T rtu_H1[19200], const
  real_T rtu_S1[19200], const real_T rtu_V1[19200],
  rtB_StateFlowFunctionsFollowOne *localB);
extern void StateFlowFunctionsFollow_h_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollow_g *localDW);
extern void StateFlowFunctionsFollowOnePa_i(const real_T rtu_BW[19200],
  RT_MODEL_brain *const brain_M, rtB_StateFlowFunctionsFollowO_k *localB,
  rtDW_StateFlowFunctionsFollow_g *localDW);
extern void StateFlowFunctionsFollow_j_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollow_b *localDW);
extern void StateFlowFunctionsFollowOnePa_k(real_T rtu_HeadingAlong, real_T
  rtu_Forward1, RT_MODEL_brain *const brain_M, rtB_StateFlowFunctionsFollowO_p
  *localB, rtDW_StateFlowFunctionsFollow_b *localDW);

#endif                                 /* RTW_HEADER_brain_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
