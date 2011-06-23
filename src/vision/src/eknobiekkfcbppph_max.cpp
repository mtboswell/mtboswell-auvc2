/*
 * File: /home/auvt/auvc/src/vision/Final_Models/slprj/ert/_sharedutils/eknobiekkfcbppph_max.cpp
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
real_T eknobiekkfcbppph_max(const real_T varargin_1[50])
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (k < 51)) {
      ix++;
      if (!rtIsNaN(varargin_1[ix - 1])) {
        mtmp = varargin_1[ix - 1];
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
    for (itmp++; itmp < 51; itmp++) {
      ix++;
      if (varargin_1[ix - 1] > mtmp) {
        mtmp = varargin_1[ix - 1];
      }
    }
  }

  return mtmp;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
