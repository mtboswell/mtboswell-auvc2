/*
 * File: rt_pow_snf.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.731
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Sun Jul 18 10:42:41 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Sun Jul 18 10:42:41 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_pow_snf.h"
#include "rt_nonfinite.h"
#include <math.h>

extern "C" {
  /*
   * Calls double-precision version of POW, with guard against domain error
   * and guards against non-finites
   */
  real_T rt_pow_snf(const real_T xr, const real_T yr)
  {
    real_T ret, axr, ayr;
    if (rtIsNaN(xr) || rtIsNaN(yr)) {
      ret = (rtNaN);
    } else {
      axr = fabs(xr);
      ayr = fabs(yr);
      if (rtIsInf(ayr)) {
        if (axr == 1.0) {
          ret = (rtNaN);
        } else if (axr > 1.0) {
          if (yr > 0.0) {
            ret = (rtInf);
          } else {
            ret = 0.0;
          }
        } else {
          if (yr > 0.0) {
            ret = 0.0;
          } else {
            ret = (rtInf);
          }
        }
      } else {
        if (ayr == 0.0) {
          ret = 1.0;
        } else if (ayr == 1.0) {
          if (yr > 0.0) {
            ret = xr;
          } else {
            ret = 1.0/xr;
          }
        } else if (yr == 2.0) {
          ret = xr*xr;
        } else if (yr == 0.5 && xr >= 0.0) {
          ret = sqrt(xr);
        } else if ((xr < 0.0) && (yr > floor(yr))) {
          ret = (rtNaN);
        } else {
          ret = pow(xr, yr);
        }
      }
    }

    return ret;
  }                                    /* end rt_pow_snf */
}
/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
