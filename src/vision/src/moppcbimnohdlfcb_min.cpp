/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/moppcbimnohdlfcb_min.cpp
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
#include "rt_nonfinite.h"

/* Function for Embedded MATLAB: '<S2>/Analyze LabelMatrix for Buoys' */
void moppcbimnohdlfcb_min(const real_T varargin_1[150], real_T minval[50])
{
  int32_T ix;
  int32_T iy;
  real_T mtmp;
  int32_T itmp;
  int32_T j;
  int32_T b_ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  ix = 0;
  iy = 0;
  for (j = 0; j < 50; j++) {
    ix++;
    mtmp = varargin_1[ix - 1];
    itmp = 1;
    b_ix = ix;
    guard = FALSE;
    if (rtIsNaN(varargin_1[ix - 1])) {
      searchingForNonNaN = TRUE;
      k = 2;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (k < 4)) {
        b_ix += 50;
        if (!rtIsNaN(varargin_1[b_ix - 1])) {
          mtmp = varargin_1[b_ix - 1];
          itmp = k;
          searchingForNonNaN = FALSE;
          exitg = TRUE;
        } else {
          k++;
        }
      }

      if (!searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (itmp++; itmp < 4; itmp++) {
        b_ix += 50;
        if (varargin_1[b_ix - 1] < mtmp) {
          mtmp = varargin_1[b_ix - 1];
        }
      }
    }

    iy++;
    minval[iy - 1] = mtmp;
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
