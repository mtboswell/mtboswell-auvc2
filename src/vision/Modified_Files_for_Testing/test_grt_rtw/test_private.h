/*
 * test_private.h
 *
 * Real-Time Workshop code generation for Simulink model "test.mdl".
 *
 * Model version              : 1.36
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Fri Jun 03 07:34:21 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_test_private_h_
#define RTW_HEADER_test_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
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

extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 /* RTW_HEADER_test_private_h_ */
