/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/kfknaaaaecjemohd_conv2.cpp
 *
 * Real-Time Workshop code generated for Simulink model torpedo.
 *
 * Model version                        : 1.63
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Mon Jun 20 23:28:21 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Mon Jun 20 23:28:22 2011
 */

#include "rtwtypes.h"
#include "rtw_shared_utils.h"

/* Function for Embedded MATLAB: '<S4>/Low Pass Filter' */
void kfknaaaaecjemohd_conv2(const real_T arg1[307200], const real_T arg2[9],
  real_T c[304964])
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
  for (jc = 0; jc < 478; jc++) {
    j = jc + 3;
    jp = j + 1;
    ja = jp - 3;
    for (ic = 0; ic < 638; ic++) {
      i = ic + 3;
      ip = i + 1;
      ia = ip - 3;
      s = 0.0;
      for (ja_0 = ja; ja_0 <= j; ja_0++) {
        jb = jp - ja_0;
        for (ia_0 = ia; ia_0 <= i; ia_0++) {
          s += arg1[(ja_0 - 1) * 640 + (ia_0 - 1)] * arg2[((ip - ia_0) - 1) +
            (jb - 1) * 3];
        }
      }

      c[ic + 638 * jc] = s;
    }
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
