/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/nglnaimoglfkkfkf_power.cpp
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.714
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:26:37 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:26:37 2011
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"
#include "rt_pow_snf.h"

/* Function for Embedded MATLAB: '<S2>/Analyze LabelMatrix for Buoys' */
void nglnaimoglfkkfkf_power(const real_T a[50], real_T b, real_T y[50])
{
  int32_T k;
  for (k = 0; k < 50; k++) {
    y[k] = rt_pow_snf(a[k], b);
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
