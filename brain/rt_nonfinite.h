/*
 * File: rt_nonfinite.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.349
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Apr 13 17:34:15 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Apr 13 17:34:16 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_
#include <stddef.h>
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_rt_nonfinite_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */