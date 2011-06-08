/*
 * File: validation_gate.cpp
 *
 * Real-Time Workshop code generated for Simulink model validation_gate.
 *
 * Model version                        : 1.816
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:51:38 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:51:38 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "validation_gate.h"
#include "validation_gate_private.h"

/* Initial conditions for referenced model: 'validation_gate' */
void mr_validation_gate_Init(rtDW_mr_validation_gate *localDW)
{
  int32_T nonZeroIdx;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
      validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
      validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 120;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }
}

/* Output and update for referenced model: 'validation_gate' */
void mr_validation_gate(const real_T rtu_R_forward_in[19200], const real_T
  rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_TargetDetected, rtB_mr_validation_gate *localB, rtDW_mr_validation_gate
  *localDW)
{
  real_T rho[10];
  real_T theta[10];
  int16_T i_index[10];
  uint8_T j_index[10];
  boolean_T exitg;
  boolean_T guard;
  int32_T imgCol;
  int32_T imgRow;
  real_T accumOne;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  int32_T imgIdx_r;
  real_T rtb_theta_out[3];

  /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  for (imgIdx_r = 0; imgIdx_r < 19200; imgIdx_r++) {
    /* First get the min and max of the RGB triplet */
    if (rtu_R_forward_in[imgIdx_r] > rtu_G_forward_in[imgIdx_r]) {
      if (rtu_G_forward_in[imgIdx_r] < rtu_B_forward_in[imgIdx_r]) {
        accumOne = rtu_G_forward_in[imgIdx_r];
      } else {
        accumOne = rtu_B_forward_in[imgIdx_r];
      }

      if (rtu_R_forward_in[imgIdx_r] > rtu_B_forward_in[imgIdx_r]) {
        accumThree = rtu_R_forward_in[imgIdx_r];
      } else {
        accumThree = rtu_B_forward_in[imgIdx_r];
      }
    } else {
      if (rtu_R_forward_in[imgIdx_r] < rtu_B_forward_in[imgIdx_r]) {
        accumOne = rtu_R_forward_in[imgIdx_r];
      } else {
        accumOne = rtu_B_forward_in[imgIdx_r];
      }

      if (rtu_G_forward_in[imgIdx_r] > rtu_B_forward_in[imgIdx_r]) {
        accumThree = rtu_G_forward_in[imgIdx_r];
      } else {
        accumThree = rtu_B_forward_in[imgIdx_r];
      }
    }

    accumOne = accumThree - accumOne;
    if (accumThree != 0.0) {
      accumTwo = accumOne / accumThree;
    } else {
      accumTwo = 0.0;
    }

    if (accumOne != 0.0) {
      if (rtu_R_forward_in[imgIdx_r] == accumThree) {
        accumOne = (rtu_G_forward_in[imgIdx_r] - rtu_B_forward_in[imgIdx_r]) /
          accumOne;
      } else if (rtu_G_forward_in[imgIdx_r] == accumThree) {
        accumOne = (rtu_B_forward_in[imgIdx_r] - rtu_R_forward_in[imgIdx_r]) /
          accumOne + 2.0;
      } else {
        accumOne = (rtu_R_forward_in[imgIdx_r] - rtu_G_forward_in[imgIdx_r]) /
          accumOne + 4.0;
      }

      accumOne /= 6.0;
      if (accumOne < 0.0) {
        accumOne++;
      }
    } else {
      accumOne = 0.0;
    }

    /* assign the results */
    localB->ColorSpaceConversion2_o1[imgIdx_r] = accumOne;
    localB->ColorSpaceConversion2_o2[imgIdx_r] = accumTwo;
    localB->ColorSpaceConversion2_o3[imgIdx_r] = accumThree;
  }

  /* Embedded MATLAB: '<S1>/Identify Validation Gate1' */
  /* Embedded MATLAB Function 'Convert to BW/Identify Validation Gate1': '<S5>:1' */
  /*  This function attempts to identfiy the validation gate, and returns line */
  /*    information, targeting information, and a true/false gate_found */
  /*    parameter. */
  /*  */
  /*  5-29-11 */
  /*  */
  /*  Input */
  /*  */
  /*    target_height = fraction of goal post height to aim AUV at */
  /*    gate_aspect_ratio = used to infer unknown points with little extra */
  /*      processing (height/width of large T-shape) */
  /*  */
  /*  Output */
  /*  */
  /*  Notes: */
  /*    The hough_table is destroyed in this function (acceptable if */
  /*      hough_table is not an output) */
  /*    Process: */
  /*      1. Identify primary, relatively "long" lines */
  /*      2.  */
  /*  Initialize */
  /*  Fraction of max(rows,cols) of image within which a */
  /*                          peak is assumed to reside; this helps reduce */
  /*                          incorrect line extraction */
  /* '<S5>:1:29' */
  /*  Considers this many popular lines as candidates */
  /* '<S5>:1:34' */
  /*  Tolerence within which two slopes are equal (radians) */
  /* '<S5>:1:36' */
  /* '<S5>:1:37' */
  /* '<S5>:1:38' */
  /* '<S5>:1:39' */
  /*  Apply appropriate threshold */
  /* '<S5>:1:44' */
  /*  Identify the most likely max_num_lines lines */
  /* '<S5>:1:48' */
  /* '<S5>:1:49' */
  /* '<S5>:1:51' */
  /*  Extract the three most popular lines that fit the geometric criteria for */
  /*    the goalpost */
  /* '<S5>:1:75' */
  /* '<S5>:1:76' */
  /* '<S5>:1:78' */
  /* rho_radius = 10; */
  /* theta_radius = 5*pi/180; */
  /* '<S5>:1:83' */
  /*  Determine whether or not the top three lines constitute the goal post */
  /*    Note that the Simulink block feeding this function keeps theta between */
  /*    +/- pi/2 */
  /*  Determine targeting information (default to center of viewing area if no */
  /*    gate found) */

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 1; imgCol < 159; imgCol++) {
    for (imgRow = 1; imgRow < 119; imgRow++) {
      accumOne = 0.0;
      accumTwo = 0.0;
      imgIdx_r = imgCol * 120 + imgRow;
      for (m = 0; m < 6; m++) {
        accumOne += localB->ColorSpaceConversion2_o3[imgIdx_r +
          localDW->EdgeDetection_VO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += localB->ColorSpaceConversion2_o3[imgIdx_r +
          localDW->EdgeDetection_HO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumOne * accumOne;
      localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumTwo * accumTwo;
    }
  }

  for (imgCol = 1; imgCol < 159; imgCol++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    imgRow = imgCol * 120;
    imgIdx_r = imgCol * 120 + 119;
    for (m = 0; m < 6; m++) {
      accumOne += localB->ColorSpaceConversion2_o3[imgRow +
        localDW->EdgeDetection_HOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += localB->ColorSpaceConversion2_o3[imgIdx_r +
        localDW->EdgeDetection_HOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += localB->ColorSpaceConversion2_o3[imgRow +
        localDW->EdgeDetection_VOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += localB->ColorSpaceConversion2_o3[imgIdx_r +
        localDW->EdgeDetection_VOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = accumThree * accumThree;
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = accumOne * accumOne;
    localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumTwo * accumTwo;
  }

  for (imgRow = 1; imgRow < 119; imgRow++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    imgIdx_r = 19080 + imgRow;
    for (m = 0; m < 6; m++) {
      accumOne += localB->ColorSpaceConversion2_o3[imgRow +
        localDW->EdgeDetection_VOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += localB->ColorSpaceConversion2_o3[imgIdx_r +
        localDW->EdgeDetection_VOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += localB->ColorSpaceConversion2_o3[imgRow +
        localDW->EdgeDetection_HOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += localB->ColorSpaceConversion2_o3[imgIdx_r +
        localDW->EdgeDetection_HOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = accumOne * accumOne;
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = accumThree * accumThree;
    localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_r] = accumTwo * accumTwo;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_r] = accumFour * accumFour;
  }

  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += localB->ColorSpaceConversion2_o3[localDW->
      EdgeDetection_VOUL_DW[m]] * validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->ColorSpaceConversion2_o3[localDW->
      EdgeDetection_HOUL_DW[m]] * validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->ColorSpaceConversion2_o3[119 +
      localDW->EdgeDetection_VOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->ColorSpaceConversion2_o3[119 +
      localDW->EdgeDetection_HOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[119] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[119] = accumFour * accumFour;
  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += localB->ColorSpaceConversion2_o3[19080 +
      localDW->EdgeDetection_VOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->ColorSpaceConversion2_o3[19080 +
      localDW->EdgeDetection_HOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->ColorSpaceConversion2_o3[19199 +
      localDW->EdgeDetection_VOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->ColorSpaceConversion2_o3[19199 +
      localDW->EdgeDetection_HOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[19080] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[19080] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[19199] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[19199] = accumFour * accumFour;
  accumTwo = 0.0;
  for (m = 0; m < 19200; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->EdgeDetection_GRAD_SUM_DW[m]
      + localDW->EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += localDW->EdgeDetection_GRAD_SUM_DW[m] *
      localDW->EdgeDetection_MEAN_FACTOR_DW;
  }

  accumOne = 3.0 * accumTwo;
  for (imgCol = 0; imgCol < 160; imgCol++) {
    for (imgRow = 0; imgRow < 120; imgRow++) {
      m = imgCol * 120 + imgRow;
      localB->EdgeDetection[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] >
        accumOne) && (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (imgCol != 0
        ? localDW->EdgeDetection_GRAD_SUM_DW[m - 120] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgCol != 159 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 120] : TRUE)) ||
                      ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (imgRow != 0
        ? localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgRow != 119 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&localB->EdgeDetection[0], &localB->HoughTransform1_o1[0],
                &validation_gate_ConstP.HoughTransform1_SINE[0],
                &validation_gate_ConstP.HoughTransform1_FIRSTRHO_R, 120, 160,
                399, 91);

  /* Embedded MATLAB: '<Root>/Identify Validation Gate' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  /* Embedded MATLAB Function 'Identify Validation Gate': '<S2>:1' */
  /*  This function attempts to identfiy the validation gate, and returns line */
  /*    information, targeting information, and a true/false gate_found */
  /*    parameter. */
  /*  */
  /*  5-29-11 */
  /*  */
  /*  Input */
  /*  */
  /*    target_height = fraction of goal post height to aim AUV at */
  /*    gate_aspect_ratio = used to infer unknown points with little extra */
  /*      processing (height/width of large T-shape) */
  /*  */
  /*  Output */
  /*  */
  /*  Notes: */
  /*    The hough_table is destroyed in this function (acceptable if */
  /*      hough_table is not an output) */
  /*    Process: */
  /*      1. Identify primary, relatively "long" lines */
  /*      2.  */
  /*  Initialize */
  /*  Fraction of max(rows,cols) of image within which a */
  /*                          peak is assumed to reside; this helps reduce */
  /*                          incorrect line extraction */
  /* '<S2>:1:29' */
  /*  Considers this many popular lines as candidates */
  /* '<S2>:1:34' */
  /*  Tolerence within which two slopes are equal (radians) */
  /* '<S2>:1:36' */
  /* '<S2>:1:37' */
  rtb_theta_out[0] = 0.0;
  rtb_theta_out[1] = 0.0;
  rtb_theta_out[2] = 0.0;

  /* '<S2>:1:38' */
  /* '<S2>:1:39' */
  /*  Apply appropriate threshold */
  /* '<S2>:1:44' */
  for (imgIdx_r = 0; imgIdx_r < 71820; imgIdx_r++) {
    localB->hough_table[imgIdx_r] = (real_T)(localB->HoughTransform1_o1[imgIdx_r]
      > 25.0) * localB->HoughTransform1_o1[imgIdx_r];
  }

  /*  Identify the most likely max_num_lines lines */
  /* '<S2>:1:48' */
  /* '<S2>:1:49' */
  for (imgIdx_r = 0; imgIdx_r < 10; imgIdx_r++) {
    i_index[imgIdx_r] = 1;
    j_index[imgIdx_r] = 1U;
  }

  /* '<S2>:1:51' */
  for (m = 0; m < 10; m++) {
    /* '<S2>:1:52' */
    /* '<S2>:1:54' */
    accumOne = 0.0;

    /* '<S2>:1:55' */
    for (imgIdx_r = 0; imgIdx_r < 399; imgIdx_r++) {
      /* '<S2>:1:55' */
      /* '<S2>:1:56' */
      for (imgRow = 0; imgRow < 180; imgRow++) {
        /* '<S2>:1:56' */
        if (localB->hough_table[399 * imgRow + imgIdx_r] > accumOne) {
          /* '<S2>:1:57' */
          /* '<S2>:1:58' */
          i_index[m] = (int16_T)(imgIdx_r + 1);

          /* '<S2>:1:59' */
          j_index[m] = (uint8_T)(imgRow + 1);

          /* '<S2>:1:60' */
          accumOne = localB->hough_table[399 * imgRow + imgIdx_r];
        }
      }
    }

    /* '<S2>:1:65' */
    rho[m] = localB->HoughTransform1_o3[i_index[m] - 1];

    /* '<S2>:1:66' */
    theta[m] = localB->HoughTransform1_o2[j_index[m] - 1];

    /* '<S2>:1:67' */
    localB->hough_table[(i_index[m] - 1) + 399 * (j_index[m] - 1)] = 0.0;

    /* '<S2>:1:68' */
  }

  /*  Extract the three most popular lines that fit the geometric criteria for */
  /*    the goalpost */
  /* '<S2>:1:75' */
  /* '<S2>:1:76' */
  rtb_theta_out[0] = theta[0];

  /* '<S2>:1:78' */
  m = 2;

  /* rho_radius = 10; */
  /* theta_radius = 5*pi/180; */
  /* '<S2>:1:83' */
  imgIdx_r = 2;
  exitg = FALSE;
  while (((uint32_T)exitg == 0U) && (imgIdx_r <= 10)) {
    /* '<S2>:1:83' */
    /*  If rho, theta do not match within tolerance, then store as the next */
    /*    line */
    /*     if( ( (rho(m) - rho(1))/rho_radius)^2 + ( (theta(m) - theta(1))/theta_radius)^2 > 1 ) */
    guard = FALSE;
    if (fabs(rho[imgIdx_r - 1] - rho[imgIdx_r - 2]) >= 30.0) {
      /* '<S2>:1:88' */
      /* '<S2>:1:89' */
      /* '<S2>:1:90' */
      rtb_theta_out[m - 1] = theta[imgIdx_r - 1];

      /* '<S2>:1:91' */
      m++;
      if (m > 3) {
        /* '<S2>:1:92' */
        exitg = TRUE;
      } else {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      imgIdx_r++;
    }
  }

  /*  Determine whether or not the top three lines constitute the goal post */
  /*    Note that the Simulink block feeding this function keeps theta between */
  /*    +/- pi/2 */
  if ((fabs(rtb_theta_out[0] - rtb_theta_out[1]) < 0.17453292519943295) &&
      ((((rtb_theta_out[0] >= rtb_theta_out[2]) || rtIsNaN(rtb_theta_out[2]) ?
         rtb_theta_out[0] : rtb_theta_out[2]) - ((rtb_theta_out[0] <=
          rtb_theta_out[2]) || rtIsNaN(rtb_theta_out[2]) ? rtb_theta_out[0] :
         rtb_theta_out[2])) - 1.5707963267948966 < 0.17453292519943295)) {
    /* '<S2>:1:103' */
    /* '<S2>:1:104' */
    imgIdx_r = 1;

    /* '<S2>:1:105' */
    /* '<S2>:1:106' */
    /* '<S2>:1:107' */
    /* '<S2>:1:108' */
    /* '<S2>:1:109' */
  } else if ((fabs(rtb_theta_out[0] - rtb_theta_out[2]) < 0.17453292519943295) &&
             ((((rtb_theta_out[0] >= rtb_theta_out[1]) || rtIsNaN(rtb_theta_out
      [1]) ? rtb_theta_out[0] : rtb_theta_out[1]) - ((rtb_theta_out[0] <=
      rtb_theta_out[1]) || rtIsNaN(rtb_theta_out[1]) ? rtb_theta_out[0] :
                rtb_theta_out[1])) - 1.5707963267948966 < 0.17453292519943295))
  {
    /* '<S2>:1:111' */
    /* '<S2>:1:112' */
    imgIdx_r = 1;

    /* '<S2>:1:113' */
    /* '<S2>:1:114' */
    /* '<S2>:1:115' */
    /* '<S2>:1:116' */
    /* '<S2>:1:117' */
  } else if ((fabs(rtb_theta_out[1] - rtb_theta_out[2]) < 0.17453292519943295) &&
             ((((rtb_theta_out[0] >= rtb_theta_out[1]) || rtIsNaN(rtb_theta_out
      [1]) ? rtb_theta_out[0] : rtb_theta_out[1]) - ((rtb_theta_out[0] <=
      rtb_theta_out[1]) || rtIsNaN(rtb_theta_out[1]) ? rtb_theta_out[0] :
                rtb_theta_out[1])) - 1.5707963267948966 < 0.17453292519943295))
  {
    /* '<S2>:1:119' */
    /* '<S2>:1:120' */
    imgIdx_r = 1;

    /* '<S2>:1:121' */
    /* '<S2>:1:122' */
    /* '<S2>:1:123' */
    /* '<S2>:1:124' */
    /* '<S2>:1:125' */
  } else {
    /* '<S2>:1:128' */
    imgIdx_r = 0;

    /* '<S2>:1:129' */
    /* '<S2>:1:131' */
    /* '<S2>:1:132' */
    /* '<S2>:1:133' */
    /* '<S2>:1:134' */
  }

  /*  Determine targeting information (default to center of viewing area if no */
  /*    gate found) */
  (*rty_TargetDetected) = (real_T)imgIdx_r;
}

/* Model initialize function */
void mr_validation_gate_initialize(const char_T **rt_errorStatus,
  RT_MODEL_validation_gate *const validation_gate_M, rtB_mr_validation_gate
  *localB, rtDW_mr_validation_gate *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(validation_gate_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_validation_gate));

  {
    localB->HoughTransform1_o2[0] = -1.5707963267948966;
    localB->HoughTransform1_o2[1] = -1.5533430342749532;
    localB->HoughTransform1_o2[2] = -1.53588974175501;
    localB->HoughTransform1_o2[3] = -1.5184364492350666;
    localB->HoughTransform1_o2[4] = -1.5009831567151235;
    localB->HoughTransform1_o2[5] = -1.4835298641951802;
    localB->HoughTransform1_o2[6] = -1.4660765716752369;
    localB->HoughTransform1_o2[7] = -1.4486232791552935;
    localB->HoughTransform1_o2[8] = -1.4311699866353502;
    localB->HoughTransform1_o2[9] = -1.4137166941154069;
    localB->HoughTransform1_o2[10] = -1.3962634015954636;
    localB->HoughTransform1_o2[11] = -1.3788101090755203;
    localB->HoughTransform1_o2[12] = -1.3613568165555769;
    localB->HoughTransform1_o2[13] = -1.3439035240356338;
    localB->HoughTransform1_o2[14] = -1.3264502315156905;
    localB->HoughTransform1_o2[15] = -1.3089969389957472;
    localB->HoughTransform1_o2[16] = -1.2915436464758039;
    localB->HoughTransform1_o2[17] = -1.2740903539558606;
    localB->HoughTransform1_o2[18] = -1.2566370614359172;
    localB->HoughTransform1_o2[19] = -1.2391837689159739;
    localB->HoughTransform1_o2[20] = -1.2217304763960306;
    localB->HoughTransform1_o2[21] = -1.2042771838760873;
    localB->HoughTransform1_o2[22] = -1.1868238913561442;
    localB->HoughTransform1_o2[23] = -1.1693705988362009;
    localB->HoughTransform1_o2[24] = -1.1519173063162575;
    localB->HoughTransform1_o2[25] = -1.1344640137963142;
    localB->HoughTransform1_o2[26] = -1.1170107212763709;
    localB->HoughTransform1_o2[27] = -1.0995574287564276;
    localB->HoughTransform1_o2[28] = -1.0821041362364843;
    localB->HoughTransform1_o2[29] = -1.064650843716541;
    localB->HoughTransform1_o2[30] = -1.0471975511965976;
    localB->HoughTransform1_o2[31] = -1.0297442586766545;
    localB->HoughTransform1_o2[32] = -1.0122909661567112;
    localB->HoughTransform1_o2[33] = -0.99483767363676789;
    localB->HoughTransform1_o2[34] = -0.97738438111682457;
    localB->HoughTransform1_o2[35] = -0.95993108859688125;
    localB->HoughTransform1_o2[36] = -0.94247779607693793;
    localB->HoughTransform1_o2[37] = -0.92502450355699462;
    localB->HoughTransform1_o2[38] = -0.90757121103705141;
    localB->HoughTransform1_o2[39] = -0.89011791851710809;
    localB->HoughTransform1_o2[40] = -0.87266462599716477;
    localB->HoughTransform1_o2[41] = -0.85521133347722145;
    localB->HoughTransform1_o2[42] = -0.83775804095727824;
    localB->HoughTransform1_o2[43] = -0.82030474843733492;
    localB->HoughTransform1_o2[44] = -0.8028514559173916;
    localB->HoughTransform1_o2[45] = -0.78539816339744828;
    localB->HoughTransform1_o2[46] = -0.767944870877505;
    localB->HoughTransform1_o2[47] = -0.75049157835756175;
    localB->HoughTransform1_o2[48] = -0.73303828583761843;
    localB->HoughTransform1_o2[49] = -0.71558499331767511;
    localB->HoughTransform1_o2[50] = -0.69813170079773179;
    localB->HoughTransform1_o2[51] = -0.68067840827778847;
    localB->HoughTransform1_o2[52] = -0.66322511575784526;
    localB->HoughTransform1_o2[53] = -0.64577182323790194;
    localB->HoughTransform1_o2[54] = -0.62831853071795862;
    localB->HoughTransform1_o2[55] = -0.6108652381980153;
    localB->HoughTransform1_o2[56] = -0.59341194567807209;
    localB->HoughTransform1_o2[57] = -0.57595865315812877;
    localB->HoughTransform1_o2[58] = -0.55850536063818546;
    localB->HoughTransform1_o2[59] = -0.54105206811824214;
    localB->HoughTransform1_o2[60] = -0.52359877559829882;
    localB->HoughTransform1_o2[61] = -0.50614548307835561;
    localB->HoughTransform1_o2[62] = -0.48869219055841229;
    localB->HoughTransform1_o2[63] = -0.47123889803846897;
    localB->HoughTransform1_o2[64] = -0.4537856055185257;
    localB->HoughTransform1_o2[65] = -0.43633231299858238;
    localB->HoughTransform1_o2[66] = -0.41887902047863912;
    localB->HoughTransform1_o2[67] = -0.4014257279586958;
    localB->HoughTransform1_o2[68] = -0.38397243543875248;
    localB->HoughTransform1_o2[69] = -0.36651914291880922;
    localB->HoughTransform1_o2[70] = -0.3490658503988659;
    localB->HoughTransform1_o2[71] = -0.33161255787892263;
    localB->HoughTransform1_o2[72] = -0.31415926535897931;
    localB->HoughTransform1_o2[73] = -0.29670597283903605;
    localB->HoughTransform1_o2[74] = -0.27925268031909273;
    localB->HoughTransform1_o2[75] = -0.26179938779914941;
    localB->HoughTransform1_o2[76] = -0.24434609527920614;
    localB->HoughTransform1_o2[77] = -0.22689280275926285;
    localB->HoughTransform1_o2[78] = -0.20943951023931956;
    localB->HoughTransform1_o2[79] = -0.19198621771937624;
    localB->HoughTransform1_o2[80] = -0.17453292519943295;
    localB->HoughTransform1_o2[81] = -0.15707963267948966;
    localB->HoughTransform1_o2[82] = -0.13962634015954636;
    localB->HoughTransform1_o2[83] = -0.12217304763960307;
    localB->HoughTransform1_o2[84] = -0.10471975511965978;
    localB->HoughTransform1_o2[85] = -0.087266462599716474;
    localB->HoughTransform1_o2[86] = -0.069813170079773182;
    localB->HoughTransform1_o2[87] = -0.05235987755982989;
    localB->HoughTransform1_o2[88] = -0.034906585039886591;
    localB->HoughTransform1_o2[89] = -0.017453292519943295;
    localB->HoughTransform1_o2[90] = 0.0;
    localB->HoughTransform1_o2[91] = 0.017453292519943295;
    localB->HoughTransform1_o2[92] = 0.034906585039886591;
    localB->HoughTransform1_o2[93] = 0.05235987755982989;
    localB->HoughTransform1_o2[94] = 0.069813170079773182;
    localB->HoughTransform1_o2[95] = 0.087266462599716474;
    localB->HoughTransform1_o2[96] = 0.10471975511965978;
    localB->HoughTransform1_o2[97] = 0.12217304763960307;
    localB->HoughTransform1_o2[98] = 0.13962634015954636;
    localB->HoughTransform1_o2[99] = 0.15707963267948966;
    localB->HoughTransform1_o2[100] = 0.17453292519943295;
    localB->HoughTransform1_o2[101] = 0.19198621771937624;
    localB->HoughTransform1_o2[102] = 0.20943951023931956;
    localB->HoughTransform1_o2[103] = 0.22689280275926285;
    localB->HoughTransform1_o2[104] = 0.24434609527920614;
    localB->HoughTransform1_o2[105] = 0.26179938779914941;
    localB->HoughTransform1_o2[106] = 0.27925268031909273;
    localB->HoughTransform1_o2[107] = 0.29670597283903605;
    localB->HoughTransform1_o2[108] = 0.31415926535897931;
    localB->HoughTransform1_o2[109] = 0.33161255787892263;
    localB->HoughTransform1_o2[110] = 0.3490658503988659;
    localB->HoughTransform1_o2[111] = 0.36651914291880922;
    localB->HoughTransform1_o2[112] = 0.38397243543875248;
    localB->HoughTransform1_o2[113] = 0.4014257279586958;
    localB->HoughTransform1_o2[114] = 0.41887902047863912;
    localB->HoughTransform1_o2[115] = 0.43633231299858238;
    localB->HoughTransform1_o2[116] = 0.4537856055185257;
    localB->HoughTransform1_o2[117] = 0.47123889803846897;
    localB->HoughTransform1_o2[118] = 0.48869219055841229;
    localB->HoughTransform1_o2[119] = 0.50614548307835561;
    localB->HoughTransform1_o2[120] = 0.52359877559829882;
    localB->HoughTransform1_o2[121] = 0.54105206811824214;
    localB->HoughTransform1_o2[122] = 0.55850536063818546;
    localB->HoughTransform1_o2[123] = 0.57595865315812877;
    localB->HoughTransform1_o2[124] = 0.59341194567807209;
    localB->HoughTransform1_o2[125] = 0.6108652381980153;
    localB->HoughTransform1_o2[126] = 0.62831853071795862;
    localB->HoughTransform1_o2[127] = 0.64577182323790194;
    localB->HoughTransform1_o2[128] = 0.66322511575784526;
    localB->HoughTransform1_o2[129] = 0.68067840827778847;
    localB->HoughTransform1_o2[130] = 0.69813170079773179;
    localB->HoughTransform1_o2[131] = 0.71558499331767511;
    localB->HoughTransform1_o2[132] = 0.73303828583761843;
    localB->HoughTransform1_o2[133] = 0.75049157835756175;
    localB->HoughTransform1_o2[134] = 0.767944870877505;
    localB->HoughTransform1_o2[135] = 0.78539816339744828;
    localB->HoughTransform1_o2[136] = 0.8028514559173916;
    localB->HoughTransform1_o2[137] = 0.82030474843733492;
    localB->HoughTransform1_o2[138] = 0.83775804095727824;
    localB->HoughTransform1_o2[139] = 0.85521133347722145;
    localB->HoughTransform1_o2[140] = 0.87266462599716477;
    localB->HoughTransform1_o2[141] = 0.89011791851710809;
    localB->HoughTransform1_o2[142] = 0.90757121103705141;
    localB->HoughTransform1_o2[143] = 0.92502450355699462;
    localB->HoughTransform1_o2[144] = 0.94247779607693793;
    localB->HoughTransform1_o2[145] = 0.95993108859688125;
    localB->HoughTransform1_o2[146] = 0.97738438111682457;
    localB->HoughTransform1_o2[147] = 0.99483767363676789;
    localB->HoughTransform1_o2[148] = 1.0122909661567112;
    localB->HoughTransform1_o2[149] = 1.0297442586766545;
    localB->HoughTransform1_o2[150] = 1.0471975511965976;
    localB->HoughTransform1_o2[151] = 1.064650843716541;
    localB->HoughTransform1_o2[152] = 1.0821041362364843;
    localB->HoughTransform1_o2[153] = 1.0995574287564276;
    localB->HoughTransform1_o2[154] = 1.1170107212763709;
    localB->HoughTransform1_o2[155] = 1.1344640137963142;
    localB->HoughTransform1_o2[156] = 1.1519173063162575;
    localB->HoughTransform1_o2[157] = 1.1693705988362009;
    localB->HoughTransform1_o2[158] = 1.1868238913561442;
    localB->HoughTransform1_o2[159] = 1.2042771838760873;
    localB->HoughTransform1_o2[160] = 1.2217304763960306;
    localB->HoughTransform1_o2[161] = 1.2391837689159739;
    localB->HoughTransform1_o2[162] = 1.2566370614359172;
    localB->HoughTransform1_o2[163] = 1.2740903539558606;
    localB->HoughTransform1_o2[164] = 1.2915436464758039;
    localB->HoughTransform1_o2[165] = 1.3089969389957472;
    localB->HoughTransform1_o2[166] = 1.3264502315156905;
    localB->HoughTransform1_o2[167] = 1.3439035240356338;
    localB->HoughTransform1_o2[168] = 1.3613568165555769;
    localB->HoughTransform1_o2[169] = 1.3788101090755203;
    localB->HoughTransform1_o2[170] = 1.3962634015954636;
    localB->HoughTransform1_o2[171] = 1.4137166941154069;
    localB->HoughTransform1_o2[172] = 1.4311699866353502;
    localB->HoughTransform1_o2[173] = 1.4486232791552935;
    localB->HoughTransform1_o2[174] = 1.4660765716752369;
    localB->HoughTransform1_o2[175] = 1.4835298641951802;
    localB->HoughTransform1_o2[176] = 1.5009831567151235;
    localB->HoughTransform1_o2[177] = 1.5184364492350666;
    localB->HoughTransform1_o2[178] = 1.53588974175501;
    localB->HoughTransform1_o2[179] = 1.5533430342749532;
    localB->HoughTransform1_o3[0] = -199.0;
    localB->HoughTransform1_o3[1] = -198.0;
    localB->HoughTransform1_o3[2] = -197.0;
    localB->HoughTransform1_o3[3] = -196.0;
    localB->HoughTransform1_o3[4] = -195.0;
    localB->HoughTransform1_o3[5] = -194.0;
    localB->HoughTransform1_o3[6] = -193.0;
    localB->HoughTransform1_o3[7] = -192.0;
    localB->HoughTransform1_o3[8] = -191.0;
    localB->HoughTransform1_o3[9] = -190.0;
    localB->HoughTransform1_o3[10] = -189.0;
    localB->HoughTransform1_o3[11] = -188.0;
    localB->HoughTransform1_o3[12] = -187.0;
    localB->HoughTransform1_o3[13] = -186.0;
    localB->HoughTransform1_o3[14] = -185.0;
    localB->HoughTransform1_o3[15] = -184.0;
    localB->HoughTransform1_o3[16] = -183.0;
    localB->HoughTransform1_o3[17] = -182.0;
    localB->HoughTransform1_o3[18] = -181.0;
    localB->HoughTransform1_o3[19] = -180.0;
    localB->HoughTransform1_o3[20] = -179.0;
    localB->HoughTransform1_o3[21] = -178.0;
    localB->HoughTransform1_o3[22] = -177.0;
    localB->HoughTransform1_o3[23] = -176.0;
    localB->HoughTransform1_o3[24] = -175.0;
    localB->HoughTransform1_o3[25] = -174.0;
    localB->HoughTransform1_o3[26] = -173.0;
    localB->HoughTransform1_o3[27] = -172.0;
    localB->HoughTransform1_o3[28] = -171.0;
    localB->HoughTransform1_o3[29] = -170.0;
    localB->HoughTransform1_o3[30] = -169.0;
    localB->HoughTransform1_o3[31] = -168.0;
    localB->HoughTransform1_o3[32] = -167.0;
    localB->HoughTransform1_o3[33] = -166.0;
    localB->HoughTransform1_o3[34] = -165.0;
    localB->HoughTransform1_o3[35] = -164.0;
    localB->HoughTransform1_o3[36] = -163.0;
    localB->HoughTransform1_o3[37] = -162.0;
    localB->HoughTransform1_o3[38] = -161.0;
    localB->HoughTransform1_o3[39] = -160.0;
    localB->HoughTransform1_o3[40] = -159.0;
    localB->HoughTransform1_o3[41] = -158.0;
    localB->HoughTransform1_o3[42] = -157.0;
    localB->HoughTransform1_o3[43] = -156.0;
    localB->HoughTransform1_o3[44] = -155.0;
    localB->HoughTransform1_o3[45] = -154.0;
    localB->HoughTransform1_o3[46] = -153.0;
    localB->HoughTransform1_o3[47] = -152.0;
    localB->HoughTransform1_o3[48] = -151.0;
    localB->HoughTransform1_o3[49] = -150.0;
    localB->HoughTransform1_o3[50] = -149.0;
    localB->HoughTransform1_o3[51] = -148.0;
    localB->HoughTransform1_o3[52] = -147.0;
    localB->HoughTransform1_o3[53] = -146.0;
    localB->HoughTransform1_o3[54] = -145.0;
    localB->HoughTransform1_o3[55] = -144.0;
    localB->HoughTransform1_o3[56] = -143.0;
    localB->HoughTransform1_o3[57] = -142.0;
    localB->HoughTransform1_o3[58] = -141.0;
    localB->HoughTransform1_o3[59] = -140.0;
    localB->HoughTransform1_o3[60] = -139.0;
    localB->HoughTransform1_o3[61] = -138.0;
    localB->HoughTransform1_o3[62] = -137.0;
    localB->HoughTransform1_o3[63] = -136.0;
    localB->HoughTransform1_o3[64] = -135.0;
    localB->HoughTransform1_o3[65] = -134.0;
    localB->HoughTransform1_o3[66] = -133.0;
    localB->HoughTransform1_o3[67] = -132.0;
    localB->HoughTransform1_o3[68] = -131.0;
    localB->HoughTransform1_o3[69] = -130.0;
    localB->HoughTransform1_o3[70] = -129.0;
    localB->HoughTransform1_o3[71] = -128.0;
    localB->HoughTransform1_o3[72] = -127.0;
    localB->HoughTransform1_o3[73] = -126.0;
    localB->HoughTransform1_o3[74] = -125.0;
    localB->HoughTransform1_o3[75] = -124.0;
    localB->HoughTransform1_o3[76] = -123.0;
    localB->HoughTransform1_o3[77] = -122.0;
    localB->HoughTransform1_o3[78] = -121.0;
    localB->HoughTransform1_o3[79] = -120.0;
    localB->HoughTransform1_o3[80] = -119.0;
    localB->HoughTransform1_o3[81] = -118.0;
    localB->HoughTransform1_o3[82] = -117.0;
    localB->HoughTransform1_o3[83] = -116.0;
    localB->HoughTransform1_o3[84] = -115.0;
    localB->HoughTransform1_o3[85] = -114.0;
    localB->HoughTransform1_o3[86] = -113.0;
    localB->HoughTransform1_o3[87] = -112.0;
    localB->HoughTransform1_o3[88] = -111.0;
    localB->HoughTransform1_o3[89] = -110.0;
    localB->HoughTransform1_o3[90] = -109.0;
    localB->HoughTransform1_o3[91] = -108.0;
    localB->HoughTransform1_o3[92] = -107.0;
    localB->HoughTransform1_o3[93] = -106.0;
    localB->HoughTransform1_o3[94] = -105.0;
    localB->HoughTransform1_o3[95] = -104.0;
    localB->HoughTransform1_o3[96] = -103.0;
    localB->HoughTransform1_o3[97] = -102.0;
    localB->HoughTransform1_o3[98] = -101.0;
    localB->HoughTransform1_o3[99] = -100.0;
    localB->HoughTransform1_o3[100] = -99.0;
    localB->HoughTransform1_o3[101] = -98.0;
    localB->HoughTransform1_o3[102] = -97.0;
    localB->HoughTransform1_o3[103] = -96.0;
    localB->HoughTransform1_o3[104] = -95.0;
    localB->HoughTransform1_o3[105] = -94.0;
    localB->HoughTransform1_o3[106] = -93.0;
    localB->HoughTransform1_o3[107] = -92.0;
    localB->HoughTransform1_o3[108] = -91.0;
    localB->HoughTransform1_o3[109] = -90.0;
    localB->HoughTransform1_o3[110] = -89.0;
    localB->HoughTransform1_o3[111] = -88.0;
    localB->HoughTransform1_o3[112] = -87.0;
    localB->HoughTransform1_o3[113] = -86.0;
    localB->HoughTransform1_o3[114] = -85.0;
    localB->HoughTransform1_o3[115] = -84.0;
    localB->HoughTransform1_o3[116] = -83.0;
    localB->HoughTransform1_o3[117] = -82.0;
    localB->HoughTransform1_o3[118] = -81.0;
    localB->HoughTransform1_o3[119] = -80.0;
    localB->HoughTransform1_o3[120] = -79.0;
    localB->HoughTransform1_o3[121] = -78.0;
    localB->HoughTransform1_o3[122] = -77.0;
    localB->HoughTransform1_o3[123] = -76.0;
    localB->HoughTransform1_o3[124] = -75.0;
    localB->HoughTransform1_o3[125] = -74.0;
    localB->HoughTransform1_o3[126] = -73.0;
    localB->HoughTransform1_o3[127] = -72.0;
    localB->HoughTransform1_o3[128] = -71.0;
    localB->HoughTransform1_o3[129] = -70.0;
    localB->HoughTransform1_o3[130] = -69.0;
    localB->HoughTransform1_o3[131] = -68.0;
    localB->HoughTransform1_o3[132] = -67.0;
    localB->HoughTransform1_o3[133] = -66.0;
    localB->HoughTransform1_o3[134] = -65.0;
    localB->HoughTransform1_o3[135] = -64.0;
    localB->HoughTransform1_o3[136] = -63.0;
    localB->HoughTransform1_o3[137] = -62.0;
    localB->HoughTransform1_o3[138] = -61.0;
    localB->HoughTransform1_o3[139] = -60.0;
    localB->HoughTransform1_o3[140] = -59.0;
    localB->HoughTransform1_o3[141] = -58.0;
    localB->HoughTransform1_o3[142] = -57.0;
    localB->HoughTransform1_o3[143] = -56.0;
    localB->HoughTransform1_o3[144] = -55.0;
    localB->HoughTransform1_o3[145] = -54.0;
    localB->HoughTransform1_o3[146] = -53.0;
    localB->HoughTransform1_o3[147] = -52.0;
    localB->HoughTransform1_o3[148] = -51.0;
    localB->HoughTransform1_o3[149] = -50.0;
    localB->HoughTransform1_o3[150] = -49.0;
    localB->HoughTransform1_o3[151] = -48.0;
    localB->HoughTransform1_o3[152] = -47.0;
    localB->HoughTransform1_o3[153] = -46.0;
    localB->HoughTransform1_o3[154] = -45.0;
    localB->HoughTransform1_o3[155] = -44.0;
    localB->HoughTransform1_o3[156] = -43.0;
    localB->HoughTransform1_o3[157] = -42.0;
    localB->HoughTransform1_o3[158] = -41.0;
    localB->HoughTransform1_o3[159] = -40.0;
    localB->HoughTransform1_o3[160] = -39.0;
    localB->HoughTransform1_o3[161] = -38.0;
    localB->HoughTransform1_o3[162] = -37.0;
    localB->HoughTransform1_o3[163] = -36.0;
    localB->HoughTransform1_o3[164] = -35.0;
    localB->HoughTransform1_o3[165] = -34.0;
    localB->HoughTransform1_o3[166] = -33.0;
    localB->HoughTransform1_o3[167] = -32.0;
    localB->HoughTransform1_o3[168] = -31.0;
    localB->HoughTransform1_o3[169] = -30.0;
    localB->HoughTransform1_o3[170] = -29.0;
    localB->HoughTransform1_o3[171] = -28.0;
    localB->HoughTransform1_o3[172] = -27.0;
    localB->HoughTransform1_o3[173] = -26.0;
    localB->HoughTransform1_o3[174] = -25.0;
    localB->HoughTransform1_o3[175] = -24.0;
    localB->HoughTransform1_o3[176] = -23.0;
    localB->HoughTransform1_o3[177] = -22.0;
    localB->HoughTransform1_o3[178] = -21.0;
    localB->HoughTransform1_o3[179] = -20.0;
    localB->HoughTransform1_o3[180] = -19.0;
    localB->HoughTransform1_o3[181] = -18.0;
    localB->HoughTransform1_o3[182] = -17.0;
    localB->HoughTransform1_o3[183] = -16.0;
    localB->HoughTransform1_o3[184] = -15.0;
    localB->HoughTransform1_o3[185] = -14.0;
    localB->HoughTransform1_o3[186] = -13.0;
    localB->HoughTransform1_o3[187] = -12.0;
    localB->HoughTransform1_o3[188] = -11.0;
    localB->HoughTransform1_o3[189] = -10.0;
    localB->HoughTransform1_o3[190] = -9.0;
    localB->HoughTransform1_o3[191] = -8.0;
    localB->HoughTransform1_o3[192] = -7.0;
    localB->HoughTransform1_o3[193] = -6.0;
    localB->HoughTransform1_o3[194] = -5.0;
    localB->HoughTransform1_o3[195] = -4.0;
    localB->HoughTransform1_o3[196] = -3.0;
    localB->HoughTransform1_o3[197] = -2.0;
    localB->HoughTransform1_o3[198] = -1.0;
    localB->HoughTransform1_o3[199] = 0.0;
    localB->HoughTransform1_o3[200] = 1.0;
    localB->HoughTransform1_o3[201] = 2.0;
    localB->HoughTransform1_o3[202] = 3.0;
    localB->HoughTransform1_o3[203] = 4.0;
    localB->HoughTransform1_o3[204] = 5.0;
    localB->HoughTransform1_o3[205] = 6.0;
    localB->HoughTransform1_o3[206] = 7.0;
    localB->HoughTransform1_o3[207] = 8.0;
    localB->HoughTransform1_o3[208] = 9.0;
    localB->HoughTransform1_o3[209] = 10.0;
    localB->HoughTransform1_o3[210] = 11.0;
    localB->HoughTransform1_o3[211] = 12.0;
    localB->HoughTransform1_o3[212] = 13.0;
    localB->HoughTransform1_o3[213] = 14.0;
    localB->HoughTransform1_o3[214] = 15.0;
    localB->HoughTransform1_o3[215] = 16.0;
    localB->HoughTransform1_o3[216] = 17.0;
    localB->HoughTransform1_o3[217] = 18.0;
    localB->HoughTransform1_o3[218] = 19.0;
    localB->HoughTransform1_o3[219] = 20.0;
    localB->HoughTransform1_o3[220] = 21.0;
    localB->HoughTransform1_o3[221] = 22.0;
    localB->HoughTransform1_o3[222] = 23.0;
    localB->HoughTransform1_o3[223] = 24.0;
    localB->HoughTransform1_o3[224] = 25.0;
    localB->HoughTransform1_o3[225] = 26.0;
    localB->HoughTransform1_o3[226] = 27.0;
    localB->HoughTransform1_o3[227] = 28.0;
    localB->HoughTransform1_o3[228] = 29.0;
    localB->HoughTransform1_o3[229] = 30.0;
    localB->HoughTransform1_o3[230] = 31.0;
    localB->HoughTransform1_o3[231] = 32.0;
    localB->HoughTransform1_o3[232] = 33.0;
    localB->HoughTransform1_o3[233] = 34.0;
    localB->HoughTransform1_o3[234] = 35.0;
    localB->HoughTransform1_o3[235] = 36.0;
    localB->HoughTransform1_o3[236] = 37.0;
    localB->HoughTransform1_o3[237] = 38.0;
    localB->HoughTransform1_o3[238] = 39.0;
    localB->HoughTransform1_o3[239] = 40.0;
    localB->HoughTransform1_o3[240] = 41.0;
    localB->HoughTransform1_o3[241] = 42.0;
    localB->HoughTransform1_o3[242] = 43.0;
    localB->HoughTransform1_o3[243] = 44.0;
    localB->HoughTransform1_o3[244] = 45.0;
    localB->HoughTransform1_o3[245] = 46.0;
    localB->HoughTransform1_o3[246] = 47.0;
    localB->HoughTransform1_o3[247] = 48.0;
    localB->HoughTransform1_o3[248] = 49.0;
    localB->HoughTransform1_o3[249] = 50.0;
    localB->HoughTransform1_o3[250] = 51.0;
    localB->HoughTransform1_o3[251] = 52.0;
    localB->HoughTransform1_o3[252] = 53.0;
    localB->HoughTransform1_o3[253] = 54.0;
    localB->HoughTransform1_o3[254] = 55.0;
    localB->HoughTransform1_o3[255] = 56.0;
    localB->HoughTransform1_o3[256] = 57.0;
    localB->HoughTransform1_o3[257] = 58.0;
    localB->HoughTransform1_o3[258] = 59.0;
    localB->HoughTransform1_o3[259] = 60.0;
    localB->HoughTransform1_o3[260] = 61.0;
    localB->HoughTransform1_o3[261] = 62.0;
    localB->HoughTransform1_o3[262] = 63.0;
    localB->HoughTransform1_o3[263] = 64.0;
    localB->HoughTransform1_o3[264] = 65.0;
    localB->HoughTransform1_o3[265] = 66.0;
    localB->HoughTransform1_o3[266] = 67.0;
    localB->HoughTransform1_o3[267] = 68.0;
    localB->HoughTransform1_o3[268] = 69.0;
    localB->HoughTransform1_o3[269] = 70.0;
    localB->HoughTransform1_o3[270] = 71.0;
    localB->HoughTransform1_o3[271] = 72.0;
    localB->HoughTransform1_o3[272] = 73.0;
    localB->HoughTransform1_o3[273] = 74.0;
    localB->HoughTransform1_o3[274] = 75.0;
    localB->HoughTransform1_o3[275] = 76.0;
    localB->HoughTransform1_o3[276] = 77.0;
    localB->HoughTransform1_o3[277] = 78.0;
    localB->HoughTransform1_o3[278] = 79.0;
    localB->HoughTransform1_o3[279] = 80.0;
    localB->HoughTransform1_o3[280] = 81.0;
    localB->HoughTransform1_o3[281] = 82.0;
    localB->HoughTransform1_o3[282] = 83.0;
    localB->HoughTransform1_o3[283] = 84.0;
    localB->HoughTransform1_o3[284] = 85.0;
    localB->HoughTransform1_o3[285] = 86.0;
    localB->HoughTransform1_o3[286] = 87.0;
    localB->HoughTransform1_o3[287] = 88.0;
    localB->HoughTransform1_o3[288] = 89.0;
    localB->HoughTransform1_o3[289] = 90.0;
    localB->HoughTransform1_o3[290] = 91.0;
    localB->HoughTransform1_o3[291] = 92.0;
    localB->HoughTransform1_o3[292] = 93.0;
    localB->HoughTransform1_o3[293] = 94.0;
    localB->HoughTransform1_o3[294] = 95.0;
    localB->HoughTransform1_o3[295] = 96.0;
    localB->HoughTransform1_o3[296] = 97.0;
    localB->HoughTransform1_o3[297] = 98.0;
    localB->HoughTransform1_o3[298] = 99.0;
    localB->HoughTransform1_o3[299] = 100.0;
    localB->HoughTransform1_o3[300] = 101.0;
    localB->HoughTransform1_o3[301] = 102.0;
    localB->HoughTransform1_o3[302] = 103.0;
    localB->HoughTransform1_o3[303] = 104.0;
    localB->HoughTransform1_o3[304] = 105.0;
    localB->HoughTransform1_o3[305] = 106.0;
    localB->HoughTransform1_o3[306] = 107.0;
    localB->HoughTransform1_o3[307] = 108.0;
    localB->HoughTransform1_o3[308] = 109.0;
    localB->HoughTransform1_o3[309] = 110.0;
    localB->HoughTransform1_o3[310] = 111.0;
    localB->HoughTransform1_o3[311] = 112.0;
    localB->HoughTransform1_o3[312] = 113.0;
    localB->HoughTransform1_o3[313] = 114.0;
    localB->HoughTransform1_o3[314] = 115.0;
    localB->HoughTransform1_o3[315] = 116.0;
    localB->HoughTransform1_o3[316] = 117.0;
    localB->HoughTransform1_o3[317] = 118.0;
    localB->HoughTransform1_o3[318] = 119.0;
    localB->HoughTransform1_o3[319] = 120.0;
    localB->HoughTransform1_o3[320] = 121.0;
    localB->HoughTransform1_o3[321] = 122.0;
    localB->HoughTransform1_o3[322] = 123.0;
    localB->HoughTransform1_o3[323] = 124.0;
    localB->HoughTransform1_o3[324] = 125.0;
    localB->HoughTransform1_o3[325] = 126.0;
    localB->HoughTransform1_o3[326] = 127.0;
    localB->HoughTransform1_o3[327] = 128.0;
    localB->HoughTransform1_o3[328] = 129.0;
    localB->HoughTransform1_o3[329] = 130.0;
    localB->HoughTransform1_o3[330] = 131.0;
    localB->HoughTransform1_o3[331] = 132.0;
    localB->HoughTransform1_o3[332] = 133.0;
    localB->HoughTransform1_o3[333] = 134.0;
    localB->HoughTransform1_o3[334] = 135.0;
    localB->HoughTransform1_o3[335] = 136.0;
    localB->HoughTransform1_o3[336] = 137.0;
    localB->HoughTransform1_o3[337] = 138.0;
    localB->HoughTransform1_o3[338] = 139.0;
    localB->HoughTransform1_o3[339] = 140.0;
    localB->HoughTransform1_o3[340] = 141.0;
    localB->HoughTransform1_o3[341] = 142.0;
    localB->HoughTransform1_o3[342] = 143.0;
    localB->HoughTransform1_o3[343] = 144.0;
    localB->HoughTransform1_o3[344] = 145.0;
    localB->HoughTransform1_o3[345] = 146.0;
    localB->HoughTransform1_o3[346] = 147.0;
    localB->HoughTransform1_o3[347] = 148.0;
    localB->HoughTransform1_o3[348] = 149.0;
    localB->HoughTransform1_o3[349] = 150.0;
    localB->HoughTransform1_o3[350] = 151.0;
    localB->HoughTransform1_o3[351] = 152.0;
    localB->HoughTransform1_o3[352] = 153.0;
    localB->HoughTransform1_o3[353] = 154.0;
    localB->HoughTransform1_o3[354] = 155.0;
    localB->HoughTransform1_o3[355] = 156.0;
    localB->HoughTransform1_o3[356] = 157.0;
    localB->HoughTransform1_o3[357] = 158.0;
    localB->HoughTransform1_o3[358] = 159.0;
    localB->HoughTransform1_o3[359] = 160.0;
    localB->HoughTransform1_o3[360] = 161.0;
    localB->HoughTransform1_o3[361] = 162.0;
    localB->HoughTransform1_o3[362] = 163.0;
    localB->HoughTransform1_o3[363] = 164.0;
    localB->HoughTransform1_o3[364] = 165.0;
    localB->HoughTransform1_o3[365] = 166.0;
    localB->HoughTransform1_o3[366] = 167.0;
    localB->HoughTransform1_o3[367] = 168.0;
    localB->HoughTransform1_o3[368] = 169.0;
    localB->HoughTransform1_o3[369] = 170.0;
    localB->HoughTransform1_o3[370] = 171.0;
    localB->HoughTransform1_o3[371] = 172.0;
    localB->HoughTransform1_o3[372] = 173.0;
    localB->HoughTransform1_o3[373] = 174.0;
    localB->HoughTransform1_o3[374] = 175.0;
    localB->HoughTransform1_o3[375] = 176.0;
    localB->HoughTransform1_o3[376] = 177.0;
    localB->HoughTransform1_o3[377] = 178.0;
    localB->HoughTransform1_o3[378] = 179.0;
    localB->HoughTransform1_o3[379] = 180.0;
    localB->HoughTransform1_o3[380] = 181.0;
    localB->HoughTransform1_o3[381] = 182.0;
    localB->HoughTransform1_o3[382] = 183.0;
    localB->HoughTransform1_o3[383] = 184.0;
    localB->HoughTransform1_o3[384] = 185.0;
    localB->HoughTransform1_o3[385] = 186.0;
    localB->HoughTransform1_o3[386] = 187.0;
    localB->HoughTransform1_o3[387] = 188.0;
    localB->HoughTransform1_o3[388] = 189.0;
    localB->HoughTransform1_o3[389] = 190.0;
    localB->HoughTransform1_o3[390] = 191.0;
    localB->HoughTransform1_o3[391] = 192.0;
    localB->HoughTransform1_o3[392] = 193.0;
    localB->HoughTransform1_o3[393] = 194.0;
    localB->HoughTransform1_o3[394] = 195.0;
    localB->HoughTransform1_o3[395] = 196.0;
    localB->HoughTransform1_o3[396] = 197.0;
    localB->HoughTransform1_o3[397] = 198.0;
    localB->HoughTransform1_o3[398] = 199.0;
  }

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(rtDW_mr_validation_gate));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
