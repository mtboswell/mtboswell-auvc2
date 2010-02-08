/*
 * File: rt_nonfinite.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.170
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Mon Feb  8 16:40:57 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Mon Feb  8 16:40:57 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#define NumBitsPerChar                 8

extern "C" {
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;

  /* Function: rt_InitInfAndNaN ==================================================
   * Abstract:
   *	Initialize the rtInf, rtMinusInf, and rtNaN needed by the
   *	generated code. NaN is initialized as non-signaling. Assumes IEEE.
   */
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  /* Function: rtIsInf ==================================================
   * Abstract:
   *	Test if value is infinite
   */
  boolean_T rtIsInf(real_T value)
  {
    return ((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  /* Function: rtIsInfF =================================================
   * Abstract:
   *	Test if single-precision value is infinite
   */
  boolean_T rtIsInfF(real32_T value)
  {
    return(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  /* Function: rtIsNaN ==================================================
   * Abstract:
   *	Test if value is not a number
   */
  boolean_T rtIsNaN(real_T value)
  {
    return((value!=value) ? 1U : 0U);
  }

  /* Function: rtIsNaNF =================================================
   * Abstract:
   *	Test if single-precision value is not a number
   */
  boolean_T rtIsNaNF(real32_T value)
  {
    return((value!=value) ? 1U : 0U);
  }
}
#undef NumBitsPerChar

/* end rt_nonfinite.c */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
