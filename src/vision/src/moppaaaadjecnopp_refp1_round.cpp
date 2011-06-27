/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/moppaaaadjecnopp_refp1_round.cpp
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.645
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:47:27 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:47:28 2011
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"
#include <math.h>

/* Function for Embedded MATLAB: '<S2>/Blob Extraction' */
void moppaaaadjecnopp_refp1_round(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
