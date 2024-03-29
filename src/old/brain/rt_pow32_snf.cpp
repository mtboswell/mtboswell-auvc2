/*
 * File: rt_pow32_snf.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.736
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Fri Oct  1 02:40:39 2010
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Fri Oct  1 02:40:43 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_pow32_snf.h"
#include "rt_nonfinite.h"
#include <math.h>

extern "C" {
  /*
   * Calls single-precision version of POW, with guard against domain error
   * and guards against non-finites
   */
  real32_T rt_pow32_snf(const real32_T xr, const real32_T yr)
  {
    real32_T ret, axr, ayr;
    if (rtIsNaNF(xr) || rtIsNaNF(yr)) {
      ret = (rtNaNF);
    } else {
      axr = (real32_T)fabs(xr);
      ayr = (real32_T)fabs(yr);
      if (rtIsInfF(ayr)) {
        if (axr == 1.0F) {
          ret = (rtNaNF);
        } else if (axr > 1.0F) {
          if (yr > 0.0F) {
            ret = (rtInfF);
          } else {
            ret = 0.0F;
          }
        } else {
          if (yr > 0.0F) {
            ret = 0.0F;
          } else {
            ret = (rtInfF);
          }
        }
      } else {
        if (ayr == 0.0F) {
          ret = 1.0F;
        } else if (ayr == 1.0F) {
          if (yr > 0.0F) {
            ret = xr;
          } else {
            ret = 1.0F/xr;
          }
        } else if (yr == 2.0F) {
          ret = xr*xr;
        } else if (yr == 0.5F && xr >= 0.0F) {
          ret = (real32_T)sqrt(xr);
        } else if ((xr < 0.0F) && (yr > (real32_T)floor(yr))) {
          ret = (rtNaNF);
        } else {
          ret = (real32_T)pow(xr, yr);
        }
      }
    }

    return ret;
  }                                    /* end rt_pow32_snf */
}
/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
