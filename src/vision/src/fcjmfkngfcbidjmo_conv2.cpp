/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/fcjmfkngfcbidjmo_conv2.cpp
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

/* Function for Embedded MATLAB: '<S4>/Low Pass Filter' */
void fcjmfkngfcbidjmo_conv2(const real_T arg1[19200], const real_T arg2[9],
  real_T c[18644])
{
  int32_T j;
  int32_T jp;
  int32_T ja;
  int32_T i;
  int32_T ip;
  int32_T ia;
  real_T s;
  int32_T jb;
  int32_T jc;
  int32_T ic;
  int32_T ja_0;
  int32_T ia_0;
  for (jc = 0; jc < 158; jc++) {
    j = jc + 3;
    jp = j + 1;
    ja = jp - 3;
    for (ic = 0; ic < 118; ic++) {
      i = ic + 3;
      ip = i + 1;
      ia = ip - 3;
      s = 0.0;
      for (ja_0 = ja; ja_0 <= j; ja_0++) {
        jb = jp - ja_0;
        for (ia_0 = ia; ia_0 <= i; ia_0++) {
          s += arg1[(ja_0 - 1) * 120 + (ia_0 - 1)] * arg2[((ip - ia_0) - 1) +
            (jb - 1) * 3];
        }
      }

      c[ic + 118 * jc] = s;
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
