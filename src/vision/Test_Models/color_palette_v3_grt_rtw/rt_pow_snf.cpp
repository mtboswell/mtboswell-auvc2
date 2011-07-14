/*
 * rt_pow_snf.cpp
 *
 * Real-Time Workshop code generation for Simulink model "color_palette_v3.mdl".
 *
 * Model version              : 1.871
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Mon Jun 27 12:45:58 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
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
