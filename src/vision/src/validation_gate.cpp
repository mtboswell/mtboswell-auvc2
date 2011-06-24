/*
 * File: validation_gate.cpp
 *
 * Real-Time Workshop code generated for Simulink model validation_gate.
 *
 * Model version                        : 1.1222
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Wed Jun 22 20:43:38 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Wed Jun 22 20:43:39 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "validation_gate.h"
#include "validation_gate_private.h"

/*
 * Output and update for atomic system:
 *    '<S7>/Low Pass Filter'
 *    '<S7>/Low Pass Filter1'
 *    '<S7>/Low Pass Filter2'
 */
void validation_gate_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_validation_ga *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S7>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S9>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S9>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S9>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S9>:1:19' */
  /* '<S9>:1:21' */
  /* '<S9>:1:23' */
  Gsum = 0.0;

  /* '<S9>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S9>:1:24' */
    /* '<S9>:1:25' */
    /* '<S9>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S9>:1:27' */
    Gsum += G[i + 1];

    /* '<S9>:1:25' */
    /* '<S9>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S9>:1:27' */
    Gsum += G[i + 4];

    /* '<S9>:1:25' */
    /* '<S9>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S9>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S9>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S9>:1:33' */
  fknoophdhdjeohdj_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S9>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S9>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S9>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S9>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S9>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S9>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S9>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S9>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S9>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Initial conditions for referenced model: 'validation_gate' */
void mr_validation_gate_Init(rtDW_mr_validation_gate *localDW)
{
  int32_T nonZeroIdx;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
      validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
      validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }
}

/* Output and update for referenced model: 'validation_gate' */
void mr_validation_gate(const real_T rtu_R_forward_in[19200], const real_T
  rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, real_T rty_R[19200], real_T rty_G[19200], real_T rty_B
  [19200], real_T rty_theta[71820], real_T rty_LabelMatrix[19200], real_T
  *rty_num_colors, real_T rty_ref_colors[150], real_T rty_bw_image[19200],
  boolean_T rty_edge_image[19200], rtB_mr_validation_gate *localB,
  rtDW_mr_validation_gate *localDW)
{
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T flag;
  int32_T j;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];
  real_T ref_colors[150];
  real_T maxL[2];
  real_T rho[200];
  real_T theta[200];
  int16_T i_index[200];
  uint8_T j_index[200];
  uint8_T rbinv[6];
  real_T ravgv[6];
  real_T tavgv[6];
  real_T vbinv[6];
  uint8_T rbinh[6];
  real_T ravgh[6];
  real_T tavgh[6];
  real_T vbinh[6];
  real_T c;
  int32_T imgIdxLL;
  int32_T imgIdxUR;
  int32_T imgIdxLR;
  int32_T imgCol;
  real_T accumOne;
  int32_T m;
  real_T accumFour;
  real_T Resize2_LineBuffer[160];
  real_T rtb_VectorConcatenate[2];
  int32_T i;
  real_T rho_gate[3];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;
  real_T theta_gate_idx;
  real_T rho_gate_idx;
  real_T theta_gate_idx_0;
  real_T rho_gate_idx_0;
  real_T theta_gate_idx_1;
  real_T rho_gate_idx_1;
  real_T gate_i_idx;
  real_T gate_i_idx_0;

  /* Constant: '<Root>/Constant3' */
  (*rty_TargetSelect) = 1.0;

  /* Constant: '<Root>/Constant4' */
  (*rty_TargetFound) = 1.0;

  /* Constant: '<Root>/Constant5' */
  (*rty_MaintainHeading) = 1.0;

  /* Embedded MATLAB: '<S7>/Low Pass Filter' */
  validation_gate_LowPassFilter(rtu_R_forward_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S7>/Low Pass Filter1' */
  validation_gate_LowPassFilter(rtu_G_forward_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S7>/Low Pass Filter2' */
  validation_gate_LowPassFilter(rtu_B_forward_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S6>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[imgIdxUR] <= 0.039286085583733095) {
      accumOne = localB->sf_LowPassFilter.Iout[imgIdxUR] / 12.923054468333255;
    } else {
      accumOne = rt_pow_snf((localB->sf_LowPassFilter.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter1.Iout[imgIdxUR] <= 0.039286085583733095) {
      gate_i_idx_0 = localB->sf_LowPassFilter1.Iout[imgIdxUR] /
        12.923054468333255;
    } else {
      gate_i_idx_0 = rt_pow_snf((localB->sf_LowPassFilter1.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter2.Iout[imgIdxUR] <= 0.039286085583733095) {
      gate_i_idx = localB->sf_LowPassFilter2.Iout[imgIdxUR] / 12.923054468333255;
    } else {
      gate_i_idx = rt_pow_snf((localB->sf_LowPassFilter2.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    accumFour = (0.41239079926596 * accumOne + 0.35758433938388 * gate_i_idx_0)
      + 0.18048078840183 * gate_i_idx;
    c = (0.21263900587151 * accumOne + 0.71516867876776 * gate_i_idx_0) +
      0.07219231536073 * gate_i_idx;
    accumOne = (0.01933081871559 * accumOne + 0.11919477979463 * gate_i_idx_0) +
      0.95053215224966 * gate_i_idx;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (accumFour > 1.0) {
      accumFour = 1.0;
    } else {
      if (accumFour < 0.0) {
        accumFour = 0.0;
      }
    }

    if (c > 1.0) {
      c = 1.0;
    } else {
      if (c < 0.0) {
        c = 0.0;
      }
    }

    if (accumOne > 1.0) {
      accumOne = 1.0;
    } else {
      if (accumOne < 0.0) {
        accumOne = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxUR] = accumFour;
    localB->ColorSpaceConversion1_o2[imgIdxUR] = c;
    localB->ColorSpaceConversion1_o3[imgIdxUR] = accumOne;
  }

  /* Convert from XYZ to L*a*b* */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    accumOne = localB->ColorSpaceConversion1_o1[imgIdxUR] / 0.9641986557609;
    gate_i_idx = localB->ColorSpaceConversion1_o3[imgIdxUR] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (accumOne > 0.0088564516790356311) {
      accumFour = rt_pow_snf(accumOne, 0.33333333333333331);
    } else {
      accumFour = 7.7870370370370372 * accumOne + 0.13793103448275862;
    }

    if (localB->ColorSpaceConversion1_o2[imgIdxUR] > 0.0088564516790356311) {
      gate_i_idx_0 = rt_pow_snf(localB->ColorSpaceConversion1_o2[imgIdxUR],
        0.33333333333333331);
    } else {
      gate_i_idx_0 = 7.7870370370370372 * localB->
        ColorSpaceConversion1_o2[imgIdxUR] + 0.13793103448275862;
    }

    if (gate_i_idx > 0.0088564516790356311) {
      accumOne = rt_pow_snf(gate_i_idx, 0.33333333333333331);
    } else {
      accumOne = 7.7870370370370372 * gate_i_idx + 0.13793103448275862;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxUR] = 116.0 * gate_i_idx_0 - 16.0;
    localB->ColorSpaceConversion1_o2[imgIdxUR] = (accumFour - gate_i_idx_0) *
      500.0;
    localB->ColorSpaceConversion1_o3[imgIdxUR] = (gate_i_idx_0 - accumOne) *
      200.0;
  }

  /* S-Function (svipresize): '<S14>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  imgIdxUR = 0;
  for (m = 0; m < 160; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      i = j + 80;
      accumOne = localB->
        ColorSpaceConversion1_o1[validation_gate_ConstP.pooled8[j] * 160 + m] *
        validation_gate_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o1[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      i += 80;
      accumOne += localB->
        ColorSpaceConversion1_o1[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      localDW->Resize_IntBuffer[imgIdxLL] = accumOne;
      imgIdxLL += 160;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->Resize_IntBuffer[j
            * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 6; imgCol++) {
        accumOne += Resize2_LineBuffer[validation_gate_ConstP.pooled7[i]] *
          validation_gate_ConstP.pooled3[i];
        i += 60;
      }

      localB->Resize[imgIdxUR] = accumOne;
      imgIdxUR++;
    }
  }

  /* S-Function (svipresize): '<S14>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  imgIdxUR = 0;
  for (m = 0; m < 160; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      i = j + 80;
      accumOne = localB->
        ColorSpaceConversion1_o2[validation_gate_ConstP.pooled8[j] * 160 + m] *
        validation_gate_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o2[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      i += 80;
      accumOne += localB->
        ColorSpaceConversion1_o2[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      localDW->Resize1_IntBuffer[imgIdxLL] = accumOne;
      imgIdxLL += 160;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[j * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 6; imgCol++) {
        accumOne += Resize2_LineBuffer[validation_gate_ConstP.pooled7[i]] *
          validation_gate_ConstP.pooled3[i];
        i += 60;
      }

      localB->Resize1[imgIdxUR] = accumOne;
      imgIdxUR++;
    }
  }

  /* S-Function (svipresize): '<S14>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  imgIdxUR = 0;
  for (m = 0; m < 160; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      i = j + 80;
      accumOne = localB->
        ColorSpaceConversion1_o3[validation_gate_ConstP.pooled8[j] * 160 + m] *
        validation_gate_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o3[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      i += 80;
      accumOne += localB->
        ColorSpaceConversion1_o3[validation_gate_ConstP.pooled8[i] * 160 + m] *
        validation_gate_ConstP.pooled4[i];
      localDW->Resize2_IntBuffer[imgIdxLL] = accumOne;
      imgIdxLL += 160;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[j * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 6; imgCol++) {
        accumOne += Resize2_LineBuffer[validation_gate_ConstP.pooled7[i]] *
          validation_gate_ConstP.pooled3[i];
        i += 60;
      }

      localB->Resize2[imgIdxUR] = accumOne;
      imgIdxUR++;
    }
  }

  /* Embedded MATLAB: '<S8>/Reference Color Selection' incorporates:
   *  Constant: '<S8>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/Reference Color Selection': '<S13>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S13>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S13>:1:14' */
  /* '<S13>:1:15' */
  memset((void *)(&rty_ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S13>:1:16' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0U, 4800U * sizeof(uint32_T));

  /* '<S13>:1:17' */
  imgCol = 1;

  /*  Define first reference color to be colr */
  /* '<S13>:1:23' */
  rty_ref_colors[0] = localB->Resize[2369];
  rty_ref_colors[50] = localB->Resize1[2369];
  rty_ref_colors[100] = localB->Resize2[2369];

  /* '<S13>:1:25' */
  flag = 0;

  /* '<S13>:1:26' */
  imgIdxUR = 1;

  /* '<S13>:1:27' */
  j = 1;
  while (imgIdxUR <= 60) {
    /* '<S13>:1:28' */
    /*  perform initial segmentation */
    while ((imgIdxUR <= 60) && (flag == 0)) {
      /* '<S13>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S13>:1:30' */
        /* '<S13>:1:31' */
        gate_i_idx = 1.0;

        /* '<S13>:1:32' */
        accumOne = 1000.0;

        /* '<S13>:1:33' */
        gate_i_idx_0 = 1.0;
        while ((uint32_T)gate_i_idx <= (uint32_T)imgCol) {
          /* '<S13>:1:34' */
          /* '<S13>:1:35' */
          accumFour = sqrt((rt_pow_snf(rty_ref_colors[(int32_T)gate_i_idx + 49]
            - localB->Resize1[(j - 1) * 60 + (imgIdxUR - 1)], 2.0) * 1.5 +
                            rt_pow_snf(rty_ref_colors[(int32_T)gate_i_idx - 1] -
            localB->Resize[(j - 1) * 60 + (imgIdxUR - 1)], 2.0)) + rt_pow_snf
                           (rty_ref_colors[(int32_T)gate_i_idx + 99] -
                            localB->Resize2[(j - 1) * 60 + (imgIdxUR - 1)], 2.0)
                           * 1.5);
          if (accumOne > accumFour) {
            /* '<S13>:1:36' */
            /* '<S13>:1:37' */
            accumOne = accumFour;

            /* '<S13>:1:38' */
            gate_i_idx_0 = gate_i_idx;
          }

          /* '<S13>:1:40' */
          gate_i_idx++;
        }

        if ((accumOne > 20.0) && (imgCol < 50)) {
          /* '<S13>:1:45' */
          /* '<S13>:1:46' */
          rty_ref_colors[imgCol] = localB->Resize[(j - 1) * 60 + (imgIdxUR - 1)];
          rty_ref_colors[imgCol + 50] = localB->Resize1[(j - 1) * 60 + (imgIdxUR
            - 1)];
          rty_ref_colors[imgCol + 100] = localB->Resize2[(j - 1) * 60 +
            (imgIdxUR - 1)];

          /* '<S13>:1:47' */
          imgCol++;

          /* '<S13>:1:48' */
          flag = 1;

          /* '<S13>:1:49' */
          imgIdxUR = 0;

          /* '<S13>:1:50' */
          j = 0;
        } else {
          /* '<S13>:1:52' */
          localB->LabelMatrix[(imgIdxUR - 1) + 60 * (j - 1)] = (uint32_T)
            gate_i_idx_0;
        }

        /* '<S13>:1:54' */
        j++;
      }

      /* '<S13>:1:56' */
      j = 1;

      /* '<S13>:1:57' */
      imgIdxUR++;
    }

    /* '<S13>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S13>:1:63' */
  /* '<S13>:1:64' */
  /* '<S13>:1:65' */
  /* '<S13>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S13>:1:67' */
  for (imgIdxUR = 0; imgIdxUR < 60; imgIdxUR++) {
    /* '<S13>:1:67' */
    /* '<S13>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S13>:1:68' */
      /* '<S13>:1:69' */
      /* '<S13>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix[imgIdxUR + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix[60 * flag + imgIdxUR] - 1]
        + localB->Resize[60 * flag + imgIdxUR];

      /* '<S13>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix[imgIdxUR + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix[60 * flag + imgIdxUR] - 1]
        + localB->Resize1[60 * flag + imgIdxUR];

      /* '<S13>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix[imgIdxUR + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix[60 * flag + imgIdxUR] - 1]
        + localB->Resize2[60 * flag + imgIdxUR];

      /* '<S13>:1:73' */
      color_count[(int32_T)localB->LabelMatrix[imgIdxUR + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix[60 * flag + imgIdxUR] - 1] +
        1.0;
    }
  }

  /* '<S13>:1:76' */
  /* '<S13>:1:77' */
  /* '<S13>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S13>:1:80' */
  for (accumOne = 1.0; (uint32_T)accumOne <= (uint32_T)imgCol; accumOne++) {
    /* '<S13>:1:80' */
    /* '<S13>:1:81' */
    rty_ref_colors[(int32_T)accumOne - 1] = ref_color_L_avg[(int32_T)accumOne -
      1];

    /* '<S13>:1:82' */
    rty_ref_colors[(int32_T)accumOne + 49] = ref_color_a_avg[(int32_T)accumOne -
      1];

    /* '<S13>:1:83' */
    rty_ref_colors[(int32_T)accumOne + 99] = ref_color_b_avg[(int32_T)accumOne -
      1];
  }

  (*rty_num_colors) = (real_T)imgCol;

  /* Embedded MATLAB: '<S8>/LabSegmentation' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/LabSegmentation': '<S12>:1' */
  /*  This function generates the label matrix */
  /* '<S12>:1:10' */
  memset((void *)(&rty_LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S12>:1:12' */
  for (imgIdxUR = 0; imgIdxUR < 160; imgIdxUR++) {
    /* '<S12>:1:12' */
    /* '<S12>:1:13' */
    for (j = 0; j < 120; j++) {
      /* '<S12>:1:13' */
      /* '<S12>:1:14' */
      accumOne = 1000.0;

      /* '<S12>:1:15' */
      gate_i_idx_0 = 1.0;

      /* '<S12>:1:16' */
      for (gate_i_idx = 1.0; gate_i_idx <= (*rty_num_colors); gate_i_idx++) {
        /* '<S12>:1:16' */
        /* '<S12>:1:17' */
        accumFour = sqrt((rt_pow_snf(rty_ref_colors[(int32_T)gate_i_idx - 1] -
          localB->ColorSpaceConversion1_o1[160 * j + imgIdxUR], 2.0) +
                          rt_pow_snf(rty_ref_colors[(int32_T)gate_i_idx + 49] -
          localB->ColorSpaceConversion1_o2[160 * j + imgIdxUR], 2.0)) +
                         rt_pow_snf(rty_ref_colors[(int32_T)gate_i_idx + 99] -
          localB->ColorSpaceConversion1_o3[160 * j + imgIdxUR], 2.0));
        if (accumFour < accumOne) {
          /* '<S12>:1:18' */
          /* '<S12>:1:19' */
          accumOne = accumFour;

          /* '<S12>:1:20' */
          gate_i_idx_0 = gate_i_idx;
        }
      }

      /* '<S12>:1:23' */
      rty_LabelMatrix[imgIdxUR + 160 * j] = gate_i_idx_0;
    }
  }

  /* '<S12>:1:27' */

  /* Embedded MATLAB: '<Root>/Transform Coordinates1' */
  /* Embedded MATLAB Function 'Transform Coordinates1': '<S3>:1' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:11' */
  /* '<S3>:1:13' */
  for (flag = 0; flag < 160; flag++) {
    /* '<S3>:1:13' */
    /* '<S3>:1:14' */
    for (j = 0; j < 120; j++) {
      /* '<S3>:1:14' */
      /* '<S3>:1:15' */
      localB->L[flag + 160 * j] = rty_ref_colors[(int32_T)rty_LabelMatrix[160 *
        j + flag] - 1];

      /* '<S3>:1:16' */
      localB->a[flag + 160 * j] = rty_ref_colors[(int32_T)rty_LabelMatrix[160 *
        j + flag] + 49];

      /* '<S3>:1:17' */
      localB->b[flag + 160 * j] = rty_ref_colors[(int32_T)rty_LabelMatrix[160 *
        j + flag] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    c = (localB->L[imgIdxUR] + 16.0) / 116.0;
    accumFour = localB->a[imgIdxUR] / 500.0 + c;
    accumOne = localB->b[imgIdxUR] / -200.0 + c;
    if (accumFour <= 0.20689655172413793) {
      accumFour -= 0.13793103448275862;
      accumFour /= 7.7870370370370372;
    } else {
      accumFour = rt_pow_snf(accumFour, 3.0);
    }

    if (c <= 0.20689655172413793) {
      c -= 0.13793103448275862;
      c /= 7.7870370370370372;
    } else {
      c = rt_pow_snf(c, 3.0);
    }

    if (accumOne <= 0.20689655172413793) {
      accumOne -= 0.13793103448275862;
      accumOne /= 7.7870370370370372;
    } else {
      accumOne = rt_pow_snf(accumOne, 3.0);
    }

    accumFour *= 0.9641986557609;
    accumOne *= 0.82511648322104;

    /* assign the results */
    localB->ColorSpaceConversion1_o1_l[imgIdxUR] = accumFour;
    localB->ColorSpaceConversion1_o2_d[imgIdxUR] = c;
    localB->ColorSpaceConversion1_o3_k[imgIdxUR] = accumOne;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    accumFour = (3.24096994190451 * localB->ColorSpaceConversion1_o1_l[imgIdxUR]
                 + -1.53738317757009 * localB->
                 ColorSpaceConversion1_o2_d[imgIdxUR]) + -0.49861076029299 *
      localB->ColorSpaceConversion1_o3_k[imgIdxUR];
    c = (-0.96924363628087 * localB->ColorSpaceConversion1_o1_l[imgIdxUR] +
         1.87596750150771 * localB->ColorSpaceConversion1_o2_d[imgIdxUR]) +
      0.04155505740718 * localB->ColorSpaceConversion1_o3_k[imgIdxUR];
    accumOne = (0.055630079697 * localB->ColorSpaceConversion1_o1_l[imgIdxUR] +
                -0.20397695888899 * localB->ColorSpaceConversion1_o2_d[imgIdxUR])
      + 1.05697151424288 * localB->ColorSpaceConversion1_o3_k[imgIdxUR];

    /* Apply gamma correction to get R'G'B' */
    if (accumFour <= 0.00304) {
      accumFour *= 12.923054468333255;
    } else {
      accumFour = 1.0550005198172263 * rt_pow_snf(accumFour, 0.41666666666666669)
        - 0.055000519817226347;
    }

    if (c <= 0.00304) {
      c *= 12.923054468333255;
    } else {
      c = 1.0550005198172263 * rt_pow_snf(c, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (accumOne <= 0.00304) {
      accumOne *= 12.923054468333255;
    } else {
      accumOne = 1.0550005198172263 * rt_pow_snf(accumOne, 0.41666666666666669)
        - 0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (accumFour > 1.0) {
      accumFour = 1.0;
    } else {
      if (accumFour < 0.0) {
        accumFour = 0.0;
      }
    }

    if (c > 1.0) {
      c = 1.0;
    } else {
      if (c < 0.0) {
        c = 0.0;
      }
    }

    if (accumOne > 1.0) {
      accumOne = 1.0;
    } else {
      if (accumOne < 0.0) {
        accumOne = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1_l[imgIdxUR] = accumFour;
    localB->ColorSpaceConversion1_o2_d[imgIdxUR] = c;
    localB->ColorSpaceConversion1_o3_k[imgIdxUR] = accumOne;
  }

  /* Embedded MATLAB: '<S1>/Identify Validation Gate2' */
  memcpy((void *)&ref_colors[0], (void *)(&rty_ref_colors[0]), 150U * sizeof
         (real_T));

  /* Embedded MATLAB Function 'Convert to BW/Identify Validation Gate2': '<S5>:1' */
  /*  Initialize */
  /* [rows, cols] = size(LabelMatrix); */
  /* rows = Forward_Camera_Dimensions(1); */
  /* cols = Forward_Camera_Dimensions(2); */
  /* '<S5>:1:13' */
  memset((void *)(&rty_bw_image[0]), 0, 19200U * sizeof(real_T));

  /* intensity_image = zeros(160 120); */
  /* '<S5>:1:17' */
  /* '<S5>:1:18' */
  maxL[0] = 0.0;
  gate_i_idx_0 = 1.0;
  maxL[1] = 0.0;
  gate_i_idx = 1.0;

  /*  Identify max_num_cols colors with the brightest L color components */
  /* '<S5>:1:22' */
  /* '<S5>:1:24' */
  for (accumOne = 1.0; accumOne <= (*rty_num_colors); accumOne++) {
    /* '<S5>:1:24' */
    if (ref_colors[(int32_T)accumOne - 1] > maxL[0]) {
      /* '<S5>:1:25' */
      /* '<S5>:1:26' */
      gate_i_idx_0 = accumOne;

      /* '<S5>:1:27' */
      maxL[0] = ref_colors[(int32_T)accumOne - 1];
    }
  }

  /* '<S5>:1:31' */
  ref_colors[(int32_T)gate_i_idx_0 - 1] = -1.0;

  /* '<S5>:1:22' */
  /* '<S5>:1:24' */
  for (accumOne = 1.0; accumOne <= (*rty_num_colors); accumOne++) {
    /* '<S5>:1:24' */
    if (ref_colors[(int32_T)accumOne - 1] > maxL[1]) {
      /* '<S5>:1:25' */
      /* '<S5>:1:26' */
      gate_i_idx = accumOne;

      /* '<S5>:1:27' */
      maxL[1] = ref_colors[(int32_T)accumOne - 1];
    }
  }

  /* '<S5>:1:31' */
  /*  Ignore all non-white values */
  /* '<S5>:1:37' */
  for (flag = 0; flag < 160; flag++) {
    /* '<S5>:1:37' */
    /* '<S5>:1:38' */
    for (j = 0; j < 120; j++) {
      /* '<S5>:1:38' */
      /* '<S5>:1:40' */
      if (rty_LabelMatrix[160 * j + flag] == gate_i_idx_0) {
        /* '<S5>:1:41' */
        /* '<S5>:1:42' */
        rty_bw_image[flag + 160 * j] = 1.0;
      }

      /* '<S5>:1:40' */
      if (rty_LabelMatrix[160 * j + flag] == gate_i_idx) {
        /* '<S5>:1:41' */
        /* '<S5>:1:42' */
        rty_bw_image[flag + 160 * j] = 1.0;
      }
    }
  }

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 1; imgCol < 119; imgCol++) {
    for (j = 1; j < 159; j++) {
      accumOne = 0.0;
      gate_i_idx_0 = 0.0;
      flag = imgCol * 160 + j;
      for (m = 0; m < 6; m++) {
        accumOne += rty_bw_image[flag + localDW->EdgeDetection_VO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_VC_RTP[m];
        gate_i_idx_0 += rty_bw_image[flag + localDW->EdgeDetection_HO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumOne * accumOne;
      localDW->EdgeDetection_GH_SQUARED_DW[flag] = gate_i_idx_0 * gate_i_idx_0;
    }
  }

  for (imgCol = 1; imgCol < 119; imgCol++) {
    accumOne = 0.0;
    gate_i_idx_0 = 0.0;
    gate_i_idx = 0.0;
    accumFour = 0.0;
    flag = imgCol * 160;
    j = imgCol * 160 + 159;
    for (m = 0; m < 6; m++) {
      accumOne += rty_bw_image[flag + localDW->EdgeDetection_HOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      gate_i_idx_0 += rty_bw_image[j + localDW->EdgeDetection_HOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      gate_i_idx += rty_bw_image[flag + localDW->EdgeDetection_VOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += rty_bw_image[j + localDW->EdgeDetection_VOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[flag] = gate_i_idx * gate_i_idx;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumOne * accumOne;
    localDW->EdgeDetection_GV_SQUARED_DW[j] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[j] = gate_i_idx_0 * gate_i_idx_0;
  }

  for (j = 1; j < 159; j++) {
    accumOne = 0.0;
    gate_i_idx_0 = 0.0;
    gate_i_idx = 0.0;
    accumFour = 0.0;
    flag = 19040 + j;
    for (m = 0; m < 6; m++) {
      accumOne += rty_bw_image[j + localDW->EdgeDetection_VOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      gate_i_idx_0 += rty_bw_image[flag + localDW->EdgeDetection_VOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      gate_i_idx += rty_bw_image[j + localDW->EdgeDetection_HOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += rty_bw_image[flag + localDW->EdgeDetection_HOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[j] = accumOne * accumOne;
    localDW->EdgeDetection_GH_SQUARED_DW[j] = gate_i_idx * gate_i_idx;
    localDW->EdgeDetection_GV_SQUARED_DW[flag] = gate_i_idx_0 * gate_i_idx_0;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumFour * accumFour;
  }

  accumOne = 0.0;
  gate_i_idx_0 = 0.0;
  gate_i_idx = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += rty_bw_image[localDW->EdgeDetection_VOUL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    gate_i_idx_0 += rty_bw_image[localDW->EdgeDetection_HOUL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    gate_i_idx += rty_bw_image[159 + localDW->EdgeDetection_VOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += rty_bw_image[159 + localDW->EdgeDetection_HOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = gate_i_idx_0 * gate_i_idx_0;
  localDW->EdgeDetection_GV_SQUARED_DW[159] = gate_i_idx * gate_i_idx;
  localDW->EdgeDetection_GH_SQUARED_DW[159] = accumFour * accumFour;
  accumOne = 0.0;
  gate_i_idx_0 = 0.0;
  gate_i_idx = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += rty_bw_image[19040 + localDW->EdgeDetection_VOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    gate_i_idx_0 += rty_bw_image[19040 + localDW->EdgeDetection_HOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    gate_i_idx += rty_bw_image[19199 + localDW->EdgeDetection_VOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += rty_bw_image[19199 + localDW->EdgeDetection_HOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[19040] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[19040] = gate_i_idx_0 * gate_i_idx_0;
  localDW->EdgeDetection_GV_SQUARED_DW[19199] = gate_i_idx * gate_i_idx;
  localDW->EdgeDetection_GH_SQUARED_DW[19199] = accumFour * accumFour;
  gate_i_idx_0 = 0.0;
  for (m = 0; m < 19200; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->EdgeDetection_GRAD_SUM_DW[m]
      + localDW->EdgeDetection_GH_SQUARED_DW[m];
    gate_i_idx_0 += localDW->EdgeDetection_GRAD_SUM_DW[m] *
      localDW->EdgeDetection_MEAN_FACTOR_DW;
  }

  accumOne = 3.0 * gate_i_idx_0;
  for (imgCol = 0; imgCol < 120; imgCol++) {
    for (j = 0; j < 160; j++) {
      m = imgCol * 160 + j;
      rty_edge_image[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] > accumOne) &&
                           (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (imgCol != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 160] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgCol != 119 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 160] : TRUE)) ||
                            ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (j != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (j != 159 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&rty_edge_image[0], &localB->HoughTransform1_o1[0],
                &validation_gate_ConstP.HoughTransform1_SINE[0],
                &validation_gate_ConstP.HoughTransform1_FIRSTRHO_R, 160, 120,
                399, 91);

  /* Embedded MATLAB: '<Root>/Identify Validation Gate' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  memcpy((void *)(&rty_theta[0]), (void *)(&localB->HoughTransform1_o1[0]),
         71820U * sizeof(real_T));

  /* Embedded MATLAB Function 'Identify Validation Gate': '<S2>:1' */
  /*  This function attempts to identfiy the validation gate, and returns */
  /*    targeting information, and a true/false gate_found parameter. */
  /*  */
  /*  5-29-11 */
  /*  */
  /*  Input */
  /*  */
  /*    target_height = fraction of goal post height to aim AUV at */
  /*    gate_aspect_ratio = used to infer unknown points with little extra */
  /*      processing (height/width of large goalpost-shape) */
  /*  */
  /*  Output */
  /*  */
  /*  Notes: */
  /*    The hough_table is destroyed in this function (acceptable if */
  /*      hough_table is not an output) */
  /*    Process: */
  /*      1. Identify primary, relatively "long" lines */
  /*      2.  */
  /* % Initialize */
  /*  Only the (max_num_lines) with the most votes will be considered as */
  /*    candidates for the validation gate */
  /* '<S2>:1:30' */
  /* [rows, cols] = size(bw_image_in); */
  /* rows = Forward_Camera_Dimensions(1); */
  /* cols = Forward_Camera_Dimensions(2); */
  /*  eps_rho must be at least as big as the gate leg diameter (units of */
  /*    pixels) */
  /* '<S2>:1:42' */
  /*  eps_theta is used to distinguish lines as "horizontal" or "vertical"; */
  /*    units are radians */
  /* '<S2>:1:45' */
  /*  These vectors contain the final three lines that compose the validation gate */
  /* '<S2>:1:49' */
  /* '<S2>:1:50' */
  rho_gate_idx_1 = 0.0;
  theta_gate_idx_1 = 0.0;
  rho_gate_idx_0 = 0.0;
  theta_gate_idx_0 = 0.0;
  rho_gate_idx = 0.0;
  theta_gate_idx = 0.0;

  /*  These vectors contain intermediate line information; as lines are */
  /*    eliminated from these vectors, their values are set to zero */
  /* '<S2>:1:54' */
  /* '<S2>:1:55' */
  /*  Identify the most popular max_num_lines lines */
  /* '<S2>:1:62' */
  /* '<S2>:1:63' */
  for (i = 0; i < 200; i++) {
    i_index[i] = 1;
    j_index[i] = 1U;
  }

  /* '<S2>:1:65' */
  for (m = 0; m < 200; m++) {
    /* '<S2>:1:66' */
    /* '<S2>:1:68' */
    accumOne = 0.0;

    /* '<S2>:1:69' */
    for (imgIdxUR = 0; imgIdxUR < 399; imgIdxUR++) {
      /* '<S2>:1:69' */
      /* '<S2>:1:70' */
      for (j = 0; j < 180; j++) {
        /* '<S2>:1:70' */
        if (rty_theta[399 * j + imgIdxUR] > accumOne) {
          /* '<S2>:1:71' */
          /* '<S2>:1:72' */
          i_index[m] = (int16_T)(imgIdxUR + 1);

          /* '<S2>:1:73' */
          j_index[m] = (uint8_T)(j + 1);

          /* '<S2>:1:74' */
          accumOne = rty_theta[399 * j + imgIdxUR];
        }
      }
    }

    /* '<S2>:1:79' */
    rho[m] = localB->HoughTransform1_o3[i_index[m] - 1];

    /* '<S2>:1:80' */
    theta[m] = localB->HoughTransform1_o2[j_index[m] - 1];

    /* '<S2>:1:81' */
    rty_theta[(i_index[m] - 1) + 399 * (j_index[m] - 1)] = 0.0;

    /* '<S2>:1:82' */
  }

  /*  Effectively generate a small Hough table which contains only values of */
  /*    interest for the validation gate application */
  /* '<S2>:1:90' */
  /*  Rho bins for vertical lines */
  /*  Number of rho bins for vertical lines */
  /* '<S2>:1:92' */
  /*  Average rho values for each bin (note that the average value will generally differ slightly than the bin value) */
  /* '<S2>:1:93' */
  /*  Average theta values for each bin */
  /* '<S2>:1:94' */
  /*  Votes bins for vertical lines */
  /* '<S2>:1:96' */
  /* '<S2>:1:98' */
  /* '<S2>:1:99' */
  /* '<S2>:1:100' */
  for (i = 0; i < 6; i++) {
    rbinv[i] = (uint8_T)(i << 5);
    ravgv[i] = 0.0;
    tavgv[i] = 0.0;
    vbinv[i] = 0.0;
    rbinh[i] = (uint8_T)(i << 5);
    ravgh[i] = 0.0;
    tavgh[i] = 0.0;
    vbinh[i] = 0.0;
  }

  /*  Allow vertical lines along the left side of the image */
  /* '<S2>:1:103' */
  rbinv[0] = 1U;

  /* '<S2>:1:104' */
  rbinh[0] = 1U;

  /* '<S2>:1:106' */
  for (imgIdxUR = 0; imgIdxUR < 200; imgIdxUR++) {
    /* '<S2>:1:106' */
    /*  Consider only lines that are either vertical or horizontal, within */
    /*    tolerance */
    if ((fabs(theta[imgIdxUR] - 1.5707963267948966) <= 0.17453292519943295) ||
        (fabs(theta[imgIdxUR] + 1.5707963267948966) <= 0.17453292519943295)) {
      /* '<S2>:1:110' */
      visited = TRUE;
    } else {
      /* '<S2>:1:110' */
      visited = FALSE;
    }

    /*  Horizontal line */
    /* '<S2>:1:111' */
    /*  Vertical line */
    visited_0 = FALSE;
    if (fabs(theta[imgIdxUR]) <= 0.17453292519943295) {
      /* '<S2>:1:113' */
      if ((rho[imgIdxUR] == 0.0) && (theta[imgIdxUR] == 0.0)) {
        /* '<S2>:1:113' */
        isInBound = TRUE;
      } else {
        /* '<S2>:1:113' */
        isInBound = FALSE;
      }

      if (!isInBound) {
        /* '<S2>:1:113' */
        /*  Analyze vertical lines (ignore lines exactly along the left side of the image) */
        /* '<S2>:1:115' */
        flag = 1;
        isInBound = FALSE;
        while (((uint32_T)isInBound == 0U) && (flag <= 6)) {
          /* '<S2>:1:115' */
          /*  Place each rho value into a bin */
          if (fabs(rho[imgIdxUR] - (real_T)rbinv[flag - 1]) <= 16.0) {
            /* '<S2>:1:118' */
            /* '<S2>:1:119' */
            ravgv[flag - 1] = ravgv[flag - 1] + rho[imgIdxUR];

            /* '<S2>:1:120' */
            tavgv[flag - 1] = tavgv[flag - 1] + theta[imgIdxUR];

            /* '<S2>:1:121' */
            vbinv[flag - 1] = vbinv[flag - 1] + 1.0;
            isInBound = TRUE;
          } else {
            flag++;
          }
        }
      } else {
        visited_0 = TRUE;
      }
    } else {
      visited_0 = TRUE;
    }

    if (visited_0 && visited) {
      /* '<S2>:1:110' */
      /*  Analyze horizontal lines */
      if (theta[imgIdxUR] < 0.0) {
        /* '<S2>:1:129' */
        /* '<S2>:1:130' */
        theta[imgIdxUR] = theta[imgIdxUR] + 3.1415926535897931;

        /* '<S2>:1:131' */
        rho[imgIdxUR] = -rho[imgIdxUR];
      }

      /* '<S2>:1:134' */
      flag = 1;
      isInBound = FALSE;
      while (((uint32_T)isInBound == 0U) && (flag <= 6)) {
        /* '<S2>:1:134' */
        /*  Place each rho value into a bin */
        if (fabs(rho[imgIdxUR] - (real_T)rbinh[flag - 1]) <= 16.0) {
          /* '<S2>:1:137' */
          /* '<S2>:1:138' */
          ravgh[flag - 1] = ravgh[flag - 1] + rho[imgIdxUR];

          /* '<S2>:1:139' */
          tavgh[flag - 1] = tavgh[flag - 1] + theta[imgIdxUR];

          /* '<S2>:1:140' */
          vbinh[flag - 1] = vbinh[flag - 1] + 1.0;
          isInBound = TRUE;
        } else {
          flag++;
        }
      }
    }
  }

  /*  Average the values in ravg and tavg for horizontal and vertical lines */
  /* '<S2>:1:150' */
  /* '<S2>:1:159' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:150' */
    if (vbinv[flag] == 0.0) {
      /* '<S2>:1:151' */
      /* '<S2>:1:152' */
      gate_i_idx_0 = 0.0;

      /* '<S2>:1:153' */
      gate_i_idx = 0.0;
    } else {
      /* '<S2>:1:155' */
      gate_i_idx_0 = ravgv[flag] / vbinv[flag];

      /* '<S2>:1:156' */
      gate_i_idx = tavgv[flag] / vbinv[flag];
    }

    /* '<S2>:1:159' */
    if (vbinh[flag] == 0.0) {
      /* '<S2>:1:160' */
      /* '<S2>:1:161' */
      accumFour = 0.0;

      /* '<S2>:1:162' */
      c = 0.0;
    } else {
      /* '<S2>:1:164' */
      accumFour = ravgh[flag] / vbinh[flag];

      /* '<S2>:1:165' */
      c = tavgh[flag] / vbinh[flag];
    }

    ravgv[flag] = gate_i_idx_0;
    tavgv[flag] = gate_i_idx;
    ravgh[flag] = accumFour;
    tavgh[flag] = c;
  }

  /* % Extract three lines that fit the criteria for being the validation gate */
  /* '<S2>:1:171' */
  accumOne = 10000.0;

  /* '<S2>:1:172' */
  gate_i_idx_0 = -10000.0;

  /* '<S2>:1:173' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:173' */
    /*  Extract the left-most vertical line */
    if ((ravgv[flag] < accumOne) && (ravgv[flag] != 0.0)) {
      /* '<S2>:1:176' */
      /* '<S2>:1:177' */
      accumOne = ravgv[flag];

      /* '<S2>:1:178' */
      rho_gate_idx_1 = ravgv[flag];

      /* '<S2>:1:179' */
      theta_gate_idx_1 = tavgv[flag];
    }

    /*  Extract the right-most vertical line */
    if ((ravgv[flag] > gate_i_idx_0) && (ravgv[flag] != 0.0)) {
      /* '<S2>:1:183' */
      /* '<S2>:1:184' */
      gate_i_idx_0 = ravgv[flag];

      /* '<S2>:1:185' */
      rho_gate_idx = ravgv[flag];

      /* '<S2>:1:186' */
      theta_gate_idx = tavgv[flag];
    }
  }

  /*  Check that the distance between the vertical lines is much greater than */
  /*    the minimum expected distance, eps_rho */
  if (fabs(rho_gate_idx - rho_gate_idx_1) < 32.0) {
    /* '<S2>:1:193' */
    /* '<S2>:1:194' */
    rho_gate_idx_1 = 0.0;

    /* '<S2>:1:195' */
    rho_gate_idx = 0.0;

    /* '<S2>:1:196' */
    theta_gate_idx_1 = 0.0;

    /* '<S2>:1:197' */
    theta_gate_idx = 0.0;
  }

  /* rmin = 10000; */
  /* '<S2>:1:201' */
  accumOne = 0.0;

  /* '<S2>:1:202' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:202' */
    /*  Extract the horizontal line with the most votes */
    if ((vbinh[flag] > accumOne) && (ravgh[flag] != 0.0)) {
      /* '<S2>:1:205' */
      /* '<S2>:1:206' */
      accumOne = vbinh[flag];

      /* '<S2>:1:207' */
      rho_gate_idx_0 = ravgh[flag];

      /* '<S2>:1:208' */
      theta_gate_idx_0 = tavgh[flag];
    }

    /*     % Extract the horizontal line that is highest up in the image */
    /*     if( ravgh(b) < rmin && ravgh(b) ~= 0 ) */
    /*         rmin = ravgh(b); */
    /*         rho_gate(2) = ravgh(b); */
    /*         theta_gate(2) = tavgh(b); */
    /*     end */
  }

  /* % Compute targeting information */
  /*  Compute intersections */
  /* '<S2>:1:222' */
  gate_i_idx_0 = (rho_gate_idx_1 / cos(theta_gate_idx_1) - rho_gate_idx_0 / cos
                  (theta_gate_idx_0)) * (1.0 / (tan(theta_gate_idx_1) - tan
    (theta_gate_idx_0)));

  /* '<S2>:1:223' */
  gate_i_idx = (rho_gate_idx_1 - gate_i_idx_0 * sin(theta_gate_idx_1)) * (1.0 /
    cos(theta_gate_idx_1));

  /* '<S2>:1:225' */
  accumFour = (rho_gate_idx_0 / cos(theta_gate_idx_0) - rho_gate_idx / cos
               (theta_gate_idx)) * (1.0 / (tan(theta_gate_idx_0) - tan
    (theta_gate_idx)));

  /* '<S2>:1:226' */
  c = (rho_gate_idx_0 - accumFour * sin(theta_gate_idx_0)) * (1.0 / cos
    (theta_gate_idx_0));

  /* '<S2>:1:228' */
  /* '<S2>:1:229' */
  /*  Compute gate width */
  /* '<S2>:1:232' */
  /*  Form unit vector pointing downward, parallel to gate posts */
  /* '<S2>:1:235' */
  /* '<S2>:1:236' */
  maxL[0] = 1.0;
  maxL[1] = tan((((theta_gate_idx_0 - 1.5707963267948966) + theta_gate_idx_1) +
                 theta_gate_idx) / 3.0);

  /* '<S2>:1:237' */
  accumOne = opphmoppiecjmglf_norm(maxL);
  maxL[0] = 1.0 / accumOne;
  maxL[1] = maxL[1] / accumOne;

  /*  Compute target location */
  /* '<S2>:1:240' */
  accumOne = sqrt(rt_pow_snf(accumFour - gate_i_idx_0, 2.0) + rt_pow_snf(c -
    gate_i_idx, 2.0)) * 0.282;

  /* '<S2>:1:241' */
  /* '<S2>:1:242' */
  /*  Determine if a gate is present (very simple, potentially inaccurate) */
  rho_gate[0] = (real_T)(rho_gate_idx_1 == 0.0) + (real_T)(theta_gate_idx_1 ==
    0.0);
  rho_gate[1] = (real_T)(rho_gate_idx_0 == 0.0) + (real_T)(theta_gate_idx_0 ==
    0.0);
  rho_gate[2] = (real_T)(rho_gate_idx == 0.0) + (real_T)(theta_gate_idx == 0.0);
  if (aaieaaiejmopnglf_sum(rho_gate) > 0.0) {
    /* '<S2>:1:245' */
    /* '<S2>:1:247' */
    flag = 0;

    /* '<S2>:1:248' */
    (*rty_TargetZ) = 0.0;

    /* '<S2>:1:249' */
    (*rty_TargetY) = 0.0;
  } else {
    /* '<S2>:1:253' */
    flag = 1;

    /*  Transform target r, c to global coordinate system */
    /* '<S2>:1:256' */
    (*rty_TargetZ) = ((gate_i_idx_0 + accumFour) / 2.0 + accumOne * maxL[0]) -
      80.0;

    /* '<S2>:1:257' */
    (*rty_TargetY) = ((gate_i_idx + c) / 2.0 + accumOne * maxL[1]) - 60.0;
  }

  /* '<S2>:1:261' */
  (*rty_TargetDetected) = (real_T)flag;

  /* Embedded MATLAB: '<Root>/Transform Coordinates3' incorporates:
   *  Constant: '<Root>/ModeSelect1'
   */
  /* Embedded MATLAB Function 'Transform Coordinates3': '<S4>:1' */
  /*  This function, "transform Global to Local coordinates," transforms */
  /*    global coordinates that are sent to the controller into local */
  /*    coordinates that can be displayed over images. */
  /*  */
  /*  5-29-11 */
  /*  */
  /*  Input */
  /*    x_in, y_in, z_in = vectors of points in global (vehicle-centered) */
  /*      coordinate system */
  /*    bw_image_in = a 2-D array of pixel values (used only to extract image */
  /*      size) */
  /*    which_camera = selects which camera for relative coordinates */
  /*                 = 0 -> Forward camera */
  /*                 = 1 -> Down camera */
  /*  */
  /*  Output */
  /*    r_out, c_out = row, column pairs in local coordinate system */
  /* '<S4>:1:21' */
  /* '<S4>:1:22' */
  rtb_VectorConcatenate[0] = (*rty_TargetZ) + 80.0;

  /* '<S4>:1:23' */
  rtb_VectorConcatenate[1] = (*rty_TargetY) + 60.0;

  /* { */
  /* if( which_camera == 0 ) */
  /*     r_out = int32( z_in + floor(rows/2) ); */
  /*     c_out = int32( y_in + floor(cols/2) ); */
  /* else */
  /*     r_out = int32( floor(rows/2) - x_in ); */
  /*     c_out = int32( y_in + floor(cols/2) ); */
  /* end */
  /* } */

  /* S-Function (svipdrawmarkers): '<Root>/Draw Target' */
  /* Copy the image from input to output. */
  for (i = 0; i < 19200; i++) {
    rty_R[i] = localB->ColorSpaceConversion1_o1_l[i];
    rty_G[i] = localB->ColorSpaceConversion1_o2_d[i];
    rty_B[i] = localB->ColorSpaceConversion1_o3_k[i];
  }

  /* Draw all X marks. */
  for (imgIdxLL = 0; imgIdxLL < 2; imgIdxLL += 2) {
    gate_i_idx_0 = rtb_VectorConcatenate[imgIdxLL];
    if ((rtb_VectorConcatenate[imgIdxLL] < 4.503599627370496E+15) &&
        (rtb_VectorConcatenate[imgIdxLL] > -4.503599627370496E+15)) {
      gate_i_idx_0 = floor(rtb_VectorConcatenate[imgIdxLL] + 0.5);
    }

    imgIdxLR = (int32_T)gate_i_idx_0;
    gate_i_idx_0 = rtb_VectorConcatenate[imgIdxLL + 1];
    if ((rtb_VectorConcatenate[imgIdxLL + 1] < 4.503599627370496E+15) &&
        (rtb_VectorConcatenate[imgIdxLL + 1] > -4.503599627370496E+15)) {
      gate_i_idx_0 = floor(rtb_VectorConcatenate[imgIdxLL + 1] + 0.5);
    }

    m = (int32_T)gate_i_idx_0;
    line_idx_2 = imgIdxLR - 7;
    line_idx_1 = m - 7;
    line_idx_0 = imgIdxLR + 7;
    line_idx = m + 7;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_6 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      i = 0;
      imgCol = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        i = 4;
      } else {
        if (line_idx_6 > 159) {
          i = 8;
        }
      }

      if (line_idx_4 < 0) {
        imgCol = 4;
      } else {
        if (line_idx_4 > 159) {
          imgCol = 8;
        }
      }

      if (line_idx_5 < 0) {
        i = (int32_T)((uint32_T)i | 1U);
      } else {
        if (line_idx_5 > 119) {
          i = (int32_T)((uint32_T)i | 2U);
        }
      }

      if (line_idx_3 < 0) {
        imgCol = (int32_T)((uint32_T)imgCol | 1U);
      } else {
        if (line_idx_3 > 119) {
          imgCol = (int32_T)((uint32_T)imgCol | 2U);
        }
      }

      if (!((uint32_T)i | (uint32_T)imgCol)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)i & (uint32_T)imgCol) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)i != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_6 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)i & 4U) {
          /* Violated RMin. */
          imgIdxUR = (0 - line_idx_6) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_5 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited = TRUE;
        } else if ((uint32_T)i & 8U) {
          /* Violated RMax. */
          imgIdxUR = (159 - line_idx_6) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_5 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited = TRUE;
        } else if ((uint32_T)i & 1U) {
          /* Violated CMin. */
          imgIdxUR = (0 - line_idx_5) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_6 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          imgIdxUR = (119 - line_idx_5) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_6 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_4 = line_idx_0;
          line_idx_3 = line_idx;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)imgCol & 4U) {
          /* Violated RMin. */
          imgIdxUR = (0 - line_idx_4) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_3 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)imgCol & 8U) {
          /* Violated RMax. */
          imgIdxUR = (159 - line_idx_4) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_3 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)imgCol & 1U) {
          /* Violated CMin. */
          imgIdxUR = (0 - line_idx_3) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_4 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          imgIdxUR = (119 - line_idx_3) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_4 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      j = line_idx_5 * 160 + line_idx_6;
      for (imgIdxUR = line_idx_6; imgIdxUR <= line_idx_4; imgIdxUR++) {
        rty_R[j] = 0.0;
        rty_G[j] = 0.0;
        rty_B[j] = 0.0;
        j += 161;
      }
    }

    line_idx_2 = imgIdxLR - 7;
    line_idx_1 = m + 7;
    line_idx_0 = imgIdxLR + 7;
    line_idx = m - 7;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_6 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      i = 0;
      imgCol = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        i = 4;
      } else {
        if (line_idx_6 > 159) {
          i = 8;
        }
      }

      if (line_idx_4 < 0) {
        imgCol = 4;
      } else {
        if (line_idx_4 > 159) {
          imgCol = 8;
        }
      }

      if (line_idx_5 < 0) {
        i = (int32_T)((uint32_T)i | 1U);
      } else {
        if (line_idx_5 > 119) {
          i = (int32_T)((uint32_T)i | 2U);
        }
      }

      if (line_idx_3 < 0) {
        imgCol = (int32_T)((uint32_T)imgCol | 1U);
      } else {
        if (line_idx_3 > 119) {
          imgCol = (int32_T)((uint32_T)imgCol | 2U);
        }
      }

      if (!((uint32_T)i | (uint32_T)imgCol)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)i & (uint32_T)imgCol) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)i != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_6 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)i & 4U) {
          /* Violated RMin. */
          imgIdxUR = (0 - line_idx_6) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_5 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited = TRUE;
        } else if ((uint32_T)i & 8U) {
          /* Violated RMax. */
          imgIdxUR = (159 - line_idx_6) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_5 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited = TRUE;
        } else if ((uint32_T)i & 1U) {
          /* Violated CMin. */
          imgIdxUR = (0 - line_idx_5) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_6 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          imgIdxUR = (119 - line_idx_5) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_6 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_4 = line_idx_0;
          line_idx_3 = line_idx;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)imgCol & 4U) {
          /* Violated RMin. */
          imgIdxUR = (0 - line_idx_4) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_3 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)imgCol & 8U) {
          /* Violated RMax. */
          imgIdxUR = (159 - line_idx_4) * j;
          if (((imgIdxUR >= 0) && (flag >= 0)) || ((imgIdxUR < 0) && (flag < 0)))
          {
            line_idx_3 += (div_s32_floor(imgIdxUR << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-imgIdxUR) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)imgCol & 1U) {
          /* Violated CMin. */
          imgIdxUR = (0 - line_idx_3) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_4 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          imgIdxUR = (119 - line_idx_3) * flag;
          if (((imgIdxUR >= 0) && (j >= 0)) || ((imgIdxUR < 0) && (j < 0))) {
            line_idx_4 += (div_s32_floor(imgIdxUR << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-imgIdxUR) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      j = line_idx_5 * 160 + line_idx_6;
      for (imgIdxUR = line_idx_6; imgIdxUR <= line_idx_4; imgIdxUR++) {
        rty_R[j] = 0.0;
        rty_G[j] = 0.0;
        rty_B[j] = 0.0;
        j += -159;
      }
    }
  }

  /* Constant: '<Root>/Constant6' */
  (*rty_TargetYaw) = 0.0;
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
