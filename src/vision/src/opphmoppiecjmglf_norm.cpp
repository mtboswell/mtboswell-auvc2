/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/opphmoppiecjmglf_norm.cpp
 *
 * Real-Time Workshop code generated for Simulink model validation_gate_v4.
 *
 * Model version                        : 1.1120
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:27:34 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:27:34 2011
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"
#include <math.h>

/* Function for Embedded MATLAB: '<Root>/Identify Validation Gate' */
real_T opphmoppiecjmglf_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 0.0;
  firstNonZero = TRUE;
  if (x[0] != 0.0) {
    scale = fabs(x[0]);
    y = 1.0;
    firstNonZero = FALSE;
  }

  if (x[1] != 0.0) {
    absxk = fabs(x[1]);
    if (firstNonZero) {
      scale = absxk;
      y = 1.0;
    } else if (scale < absxk) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
