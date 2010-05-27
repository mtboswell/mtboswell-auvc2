/*
 * File: brain_private.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.364
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu May 27 18:36:36 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu May 27 18:36:36 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives:
 *    1. Debugging
 *    2. Safety precaution
 *    3. Traceability
 *    4. Execution efficiency
 *    5. ROM efficiency
 *    6. RAM efficiency
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
extern void StateFlowFunctionsFollowOnePath(const real_T rtu_H1[19200], const
  real_T rtu_S1[19200], const real_T rtu_V1[19200],
  rtB_StateFlowFunctionsFollowOne *localB);
extern void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);
extern void StateFlowFunctionsFollowOnePa_h(const boolean_T rtu_BWleft1[9600],
  const boolean_T rtu_BWright1[9600], real_T rtu_CurrentHeading1,
  rtB_StateFlowFunctionsFollowO_o *localB);
extern void StateFlowFunctionsValidationGat(const real_T rtu_H[19200], const
  real_T rtu_S[19200], rtB_StateFlowFunctionsValidatio *localB,
  rtDW_StateFlowFunctionsValidati *localDW);

#endif                                 /* RTW_HEADER_brain_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
