/*
 * File: validation_gate_v4.cpp
 *
 * Real-Time Workshop code generated for Simulink model validation_gate_v4.
 *
 * Model version                        : 1.1120
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:27:34 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:27:34 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "validation_gate_v4.h"
#include "validation_gate_v4_private.h"

/*
 * Output and update for atomic system:
 *    '<S8>/Low Pass Filter'
 *    '<S8>/Low Pass Filter1'
 *    '<S8>/Low Pass Filter2'
 */
void validation_gate_v_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_validation_ga *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S8>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S10>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S10>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S10>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S10>:1:19' */
  /* '<S10>:1:21' */
  /* '<S10>:1:23' */
  Gsum = 0.0;

  /* '<S10>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S10>:1:24' */
    /* '<S10>:1:25' */
    /* '<S10>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S10>:1:27' */
    Gsum += G[i + 1];

    /* '<S10>:1:25' */
    /* '<S10>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S10>:1:27' */
    Gsum += G[i + 4];

    /* '<S10>:1:25' */
    /* '<S10>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S10>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S10>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S10>:1:33' */
  fknoophdhdjeohdj_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S10>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S10>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S10>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S10>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S10>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S10>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S10>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S10>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S10>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Initial conditions for referenced model: 'validation_gate_v4' */
void mr_validation_gate_v4_Init(rtDW_mr_validation_gate_v4 *localDW)
{
  int32_T nonZeroIdx;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
      validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    if (validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
      validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    if (validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160 +
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 160;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_v4_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }
}

/* Output and update for referenced model: 'validation_gate_v4' */
void mr_validation_gate_v4(const real_T rtu_R_forward_in[19200], const real_T
  rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, rtB_mr_validation_gate_v4 *localB,
  rtDW_mr_validation_gate_v4 *localDW)
{
  int32_T flag;
  int32_T j;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];
  uint32_T maxval[120];
  int32_T iy;
  boolean_T searchingForNonNaN;
  boolean_T b_searchingForNonNaN;
  boolean_T guard;
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
  real_T u[2];
  int32_T imgIdxLL;
  int32_T imgIdxUR;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  real_T Resize2_LineBuffer[160];
  real_T rtb_num_colors;
  real_T rtb_ref_colors[150];
  real_T rho_gate[3];
  real_T ravgv_0;
  real_T theta_gate_idx;
  real_T rho_gate_idx;
  real_T theta_gate_idx_0;
  real_T rho_gate_idx_0;
  real_T theta_gate_idx_1;
  real_T rho_gate_idx_1;

  /* Constant: '<Root>/Constant3' */
  (*rty_TargetSelect) = 1.0;

  /* Constant: '<Root>/Constant4' */
  (*rty_TargetFound) = 1.0;

  /* Constant: '<Root>/Constant5' */
  (*rty_MaintainHeading) = 1.0;

  /* Embedded MATLAB: '<S8>/Low Pass Filter' */
  validation_gate_v_LowPassFilter(rtu_R_forward_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S8>/Low Pass Filter1' */
  validation_gate_v_LowPassFilter(rtu_G_forward_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S8>/Low Pass Filter2' */
  validation_gate_v_LowPassFilter(rtu_B_forward_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S7>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[imgIdxUR] <= 0.039286085583733095) {
      accumTwo = localB->sf_LowPassFilter.Iout[imgIdxUR] / 12.923054468333255;
    } else {
      accumTwo = rt_pow_snf((localB->sf_LowPassFilter.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter1.Iout[imgIdxUR] <= 0.039286085583733095) {
      accumThree = localB->sf_LowPassFilter1.Iout[imgIdxUR] / 12.923054468333255;
    } else {
      accumThree = rt_pow_snf((localB->sf_LowPassFilter1.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter2.Iout[imgIdxUR] <= 0.039286085583733095) {
      accumFour = localB->sf_LowPassFilter2.Iout[imgIdxUR] / 12.923054468333255;
    } else {
      accumFour = rt_pow_snf((localB->sf_LowPassFilter2.Iout[imgIdxUR] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    c = (0.41239079926596 * accumTwo + 0.35758433938388 * accumThree) +
      0.18048078840183 * accumFour;
    ravgv_0 = (0.21263900587151 * accumTwo + 0.71516867876776 * accumThree) +
      0.07219231536073 * accumFour;
    rtb_num_colors = (0.01933081871559 * accumTwo + 0.11919477979463 *
                      accumThree) + 0.95053215224966 * accumFour;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (c > 1.0) {
      c = 1.0;
    } else {
      if (c < 0.0) {
        c = 0.0;
      }
    }

    if (ravgv_0 > 1.0) {
      ravgv_0 = 1.0;
    } else {
      if (ravgv_0 < 0.0) {
        ravgv_0 = 0.0;
      }
    }

    if (rtb_num_colors > 1.0) {
      rtb_num_colors = 1.0;
    } else {
      if (rtb_num_colors < 0.0) {
        rtb_num_colors = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxUR] = c;
    localB->ColorSpaceConversion1_o2[imgIdxUR] = ravgv_0;
    localB->ColorSpaceConversion1_o3[imgIdxUR] = rtb_num_colors;
  }

  /* Convert from XYZ to L*a*b* */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    rtb_num_colors = localB->ColorSpaceConversion1_o1[imgIdxUR] /
      0.9641986557609;
    accumThree = localB->ColorSpaceConversion1_o3[imgIdxUR] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (rtb_num_colors > 0.0088564516790356311) {
      accumFour = rt_pow_snf(rtb_num_colors, 0.33333333333333331);
    } else {
      accumFour = 7.7870370370370372 * rtb_num_colors + 0.13793103448275862;
    }

    if (localB->ColorSpaceConversion1_o2[imgIdxUR] > 0.0088564516790356311) {
      accumTwo = rt_pow_snf(localB->ColorSpaceConversion1_o2[imgIdxUR],
                            0.33333333333333331);
    } else {
      accumTwo = 7.7870370370370372 * localB->ColorSpaceConversion1_o2[imgIdxUR]
        + 0.13793103448275862;
    }

    if (accumThree > 0.0088564516790356311) {
      rtb_num_colors = rt_pow_snf(accumThree, 0.33333333333333331);
    } else {
      rtb_num_colors = 7.7870370370370372 * accumThree + 0.13793103448275862;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxUR] = 116.0 * accumTwo - 16.0;
    localB->ColorSpaceConversion1_o2[imgIdxUR] = (accumFour - accumTwo) * 500.0;
    localB->ColorSpaceConversion1_o3[imgIdxUR] = (accumTwo - rtb_num_colors) *
      200.0;
  }

  /* S-Function (svipresize): '<S15>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 160; m++) {
    imgIdxUR = m;
    for (iy = 0; iy < 80; iy++) {
      imgIdxLL = iy + 80;
      rtb_num_colors = localB->
        ColorSpaceConversion1_o1[validation_gate_v4_ConstP.pooled5[iy] * 160 + m]
        * validation_gate_v4_ConstP.pooled3[iy] +
        localB->
        ColorSpaceConversion1_o1[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      imgIdxLL += 80;
      rtb_num_colors += localB->
        ColorSpaceConversion1_o1[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      localDW->Resize_IntBuffer[imgIdxUR] = rtb_num_colors;
      imgIdxUR += 160;
    }
  }

  for (iy = 0; iy < 80; iy++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize_IntBuffer[iy * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      imgIdxLL = m;
      rtb_num_colors = 0.0;
      for (imgIdxUR = 0; imgIdxUR < 6; imgIdxUR++) {
        rtb_num_colors +=
          Resize2_LineBuffer[validation_gate_v4_ConstP.pooled4[imgIdxLL]] *
          validation_gate_v4_ConstP.pooled2[imgIdxLL];
        imgIdxLL += 60;
      }

      localB->Resize[j] = rtb_num_colors;
      j++;
    }
  }

  /* S-Function (svipresize): '<S15>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 160; m++) {
    imgIdxUR = m;
    for (iy = 0; iy < 80; iy++) {
      imgIdxLL = iy + 80;
      rtb_num_colors = localB->
        ColorSpaceConversion1_o2[validation_gate_v4_ConstP.pooled5[iy] * 160 + m]
        * validation_gate_v4_ConstP.pooled3[iy] +
        localB->
        ColorSpaceConversion1_o2[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      imgIdxLL += 80;
      rtb_num_colors += localB->
        ColorSpaceConversion1_o2[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      localDW->Resize1_IntBuffer[imgIdxUR] = rtb_num_colors;
      imgIdxUR += 160;
    }
  }

  for (iy = 0; iy < 80; iy++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[iy * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      imgIdxLL = m;
      rtb_num_colors = 0.0;
      for (imgIdxUR = 0; imgIdxUR < 6; imgIdxUR++) {
        rtb_num_colors +=
          Resize2_LineBuffer[validation_gate_v4_ConstP.pooled4[imgIdxLL]] *
          validation_gate_v4_ConstP.pooled2[imgIdxLL];
        imgIdxLL += 60;
      }

      localB->Resize1[j] = rtb_num_colors;
      j++;
    }
  }

  /* S-Function (svipresize): '<S15>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 160; m++) {
    imgIdxUR = m;
    for (iy = 0; iy < 80; iy++) {
      imgIdxLL = iy + 80;
      rtb_num_colors = localB->
        ColorSpaceConversion1_o3[validation_gate_v4_ConstP.pooled5[iy] * 160 + m]
        * validation_gate_v4_ConstP.pooled3[iy] +
        localB->
        ColorSpaceConversion1_o3[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      imgIdxLL += 80;
      rtb_num_colors += localB->
        ColorSpaceConversion1_o3[validation_gate_v4_ConstP.pooled5[imgIdxLL] *
        160 + m] * validation_gate_v4_ConstP.pooled3[imgIdxLL];
      localDW->Resize2_IntBuffer[imgIdxUR] = rtb_num_colors;
      imgIdxUR += 160;
    }
  }

  for (iy = 0; iy < 80; iy++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[iy * 160]), 160U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      imgIdxLL = m;
      rtb_num_colors = 0.0;
      for (imgIdxUR = 0; imgIdxUR < 6; imgIdxUR++) {
        rtb_num_colors +=
          Resize2_LineBuffer[validation_gate_v4_ConstP.pooled4[imgIdxLL]] *
          validation_gate_v4_ConstP.pooled2[imgIdxLL];
        imgIdxLL += 60;
      }

      localB->Resize2[j] = rtb_num_colors;
      j++;
    }
  }

  /* Embedded MATLAB: '<S9>/Reference Color Selection' incorporates:
   *  Constant: '<S9>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/Reference Color Selection': '<S14>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S14>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S14>:1:14' */
  /* '<S14>:1:15' */
  memset((void *)&rtb_ref_colors[0], 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S14>:1:16' */
  memset((void *)(&localB->LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S14>:1:17' */
  iy = 1;

  /*  Define first reference color to be colr */
  /* '<S14>:1:23' */
  rtb_ref_colors[0] = localB->Resize[2369];
  rtb_ref_colors[50] = localB->Resize1[2369];
  rtb_ref_colors[100] = localB->Resize2[2369];

  /* '<S14>:1:25' */
  flag = 0;

  /* '<S14>:1:26' */
  imgIdxUR = 1;

  /* '<S14>:1:27' */
  j = 1;
  while (imgIdxUR <= 60) {
    /* '<S14>:1:28' */
    /*  perform initial segmentation */
    while ((imgIdxUR <= 60) && (flag == 0)) {
      /* '<S14>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S14>:1:30' */
        /* '<S14>:1:31' */
        accumFour = 1.0;

        /* '<S14>:1:32' */
        accumTwo = 1000.0;

        /* '<S14>:1:33' */
        accumThree = 1.0;
        while ((uint32_T)accumFour <= (uint32_T)iy) {
          /* '<S14>:1:34' */
          /* '<S14>:1:35' */
          c = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)accumFour + 49] -
                               localB->Resize1[(j - 1) * 60 + (imgIdxUR - 1)],
                               2.0) * 1.5 + rt_pow_snf(rtb_ref_colors[(int32_T)
                     accumFour - 1] - localB->Resize[(j - 1) * 60 + (imgIdxUR -
                      1)], 2.0)) + rt_pow_snf(rtb_ref_colors[(int32_T)accumFour
                    + 99] - localB->Resize2[(j - 1) * 60 + (imgIdxUR - 1)], 2.0)
                   * 1.5);
          if (accumTwo > c) {
            /* '<S14>:1:36' */
            /* '<S14>:1:37' */
            accumTwo = c;

            /* '<S14>:1:38' */
            accumThree = accumFour;
          }

          /* '<S14>:1:40' */
          accumFour++;
        }

        if ((accumTwo > 25.0) && (iy < 50)) {
          /* '<S14>:1:45' */
          /* '<S14>:1:46' */
          rtb_ref_colors[iy] = localB->Resize[(j - 1) * 60 + (imgIdxUR - 1)];
          rtb_ref_colors[iy + 50] = localB->Resize1[(j - 1) * 60 + (imgIdxUR - 1)];
          rtb_ref_colors[iy + 100] = localB->Resize2[(j - 1) * 60 + (imgIdxUR -
            1)];

          /* '<S14>:1:47' */
          iy++;

          /* '<S14>:1:48' */
          flag = 1;

          /* '<S14>:1:49' */
          imgIdxUR = 0;

          /* '<S14>:1:50' */
          j = 0;
        } else {
          /* '<S14>:1:52' */
          localB->LabelMatrix_m[(imgIdxUR - 1) + 60 * (j - 1)] = (uint32_T)
            accumThree;
        }

        /* '<S14>:1:54' */
        j++;
      }

      /* '<S14>:1:56' */
      j = 1;

      /* '<S14>:1:57' */
      imgIdxUR++;
    }

    /* '<S14>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S14>:1:63' */
  /* '<S14>:1:64' */
  /* '<S14>:1:65' */
  /* '<S14>:1:66' */
  for (imgIdxUR = 0; imgIdxUR < 50; imgIdxUR++) {
    ref_color_L_avg[imgIdxUR] = 0.0;
    ref_color_a_avg[imgIdxUR] = 0.0;
    ref_color_b_avg[imgIdxUR] = 0.0;
    color_count[imgIdxUR] = 0.0;
  }

  /* '<S14>:1:67' */
  for (imgIdxUR = 0; imgIdxUR < 60; imgIdxUR++) {
    /* '<S14>:1:67' */
    /* '<S14>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S14>:1:68' */
      /* '<S14>:1:69' */
      /* '<S14>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix_m[imgIdxUR + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdxUR] - 1]
        + localB->Resize[60 * flag + imgIdxUR];

      /* '<S14>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix_m[imgIdxUR + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdxUR] - 1]
        + localB->Resize1[60 * flag + imgIdxUR];

      /* '<S14>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix_m[imgIdxUR + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdxUR] - 1]
        + localB->Resize2[60 * flag + imgIdxUR];

      /* '<S14>:1:73' */
      color_count[(int32_T)localB->LabelMatrix_m[imgIdxUR + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdxUR] - 1] +
        1.0;
    }
  }

  /* '<S14>:1:76' */
  /* '<S14>:1:77' */
  /* '<S14>:1:78' */
  for (imgIdxUR = 0; imgIdxUR < 50; imgIdxUR++) {
    ref_color_L_avg[imgIdxUR] = ref_color_L_avg[imgIdxUR] / color_count[imgIdxUR];
    ref_color_a_avg[imgIdxUR] = ref_color_a_avg[imgIdxUR] / color_count[imgIdxUR];
    ref_color_b_avg[imgIdxUR] = ref_color_b_avg[imgIdxUR] / color_count[imgIdxUR];
  }

  /* '<S14>:1:80' */
  for (rtb_num_colors = 1.0; (uint32_T)rtb_num_colors <= (uint32_T)iy;
       rtb_num_colors++) {
    /* '<S14>:1:80' */
    /* '<S14>:1:81' */
    rtb_ref_colors[(int32_T)rtb_num_colors - 1] = ref_color_L_avg[(int32_T)
      rtb_num_colors - 1];

    /* '<S14>:1:82' */
    rtb_ref_colors[(int32_T)rtb_num_colors + 49] = ref_color_a_avg[(int32_T)
      rtb_num_colors - 1];

    /* '<S14>:1:83' */
    rtb_ref_colors[(int32_T)rtb_num_colors + 99] = ref_color_b_avg[(int32_T)
      rtb_num_colors - 1];
  }

  rtb_num_colors = (real_T)iy;

  /* Embedded MATLAB: '<S9>/LabSegmentation' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/LabSegmentation': '<S13>:1' */
  /*  This function generates the label matrix */
  /* '<S13>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S13>:1:12' */
  for (imgIdxUR = 0; imgIdxUR < 160; imgIdxUR++) {
    /* '<S13>:1:12' */
    /* '<S13>:1:13' */
    for (j = 0; j < 120; j++) {
      /* '<S13>:1:13' */
      /* '<S13>:1:14' */
      accumTwo = 1000.0;

      /* '<S13>:1:15' */
      accumThree = 1.0;

      /* '<S13>:1:16' */
      for (accumFour = 1.0; accumFour <= rtb_num_colors; accumFour++) {
        /* '<S13>:1:16' */
        /* '<S13>:1:17' */
        c = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)accumFour - 1] -
                             localB->ColorSpaceConversion1_o1[160 * j + imgIdxUR],
                             2.0) + rt_pow_snf(rtb_ref_colors[(int32_T)accumFour
                   + 49] - localB->ColorSpaceConversion1_o2[160 * j + imgIdxUR],
                   2.0)) + rt_pow_snf(rtb_ref_colors[(int32_T)accumFour + 99] -
                  localB->ColorSpaceConversion1_o3[160 * j + imgIdxUR], 2.0));
        if (c < accumTwo) {
          /* '<S13>:1:18' */
          /* '<S13>:1:19' */
          accumTwo = c;

          /* '<S13>:1:20' */
          accumThree = accumFour;
        }
      }

      /* '<S13>:1:23' */
      localB->LabelMatrix[imgIdxUR + 160 * j] = accumThree;
    }
  }

  /* '<S13>:1:27' */

  /* Embedded MATLAB: '<S1>/Identify Validation Gate2' */
  /* Embedded MATLAB Function 'Convert to BW/Identify Validation Gate2': '<S6>:1' */
  /* '<S6>:1:5' */
  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    localB->y[imgIdxUR] = (uint32_T)localB->LabelMatrix[imgIdxUR];
  }

  j = 0;
  iy = 0;
  for (imgIdxUR = 0; imgIdxUR < 120; imgIdxUR++) {
    j++;
    rtb_num_colors = (real_T)localB->y[j - 1];
    imgIdxLL = j;
    for (flag = 2; flag < 161; flag++) {
      imgIdxLL++;
      if ((int32_T)localB->y[imgIdxLL - 1] > (int32_T)rtb_num_colors) {
        rtb_num_colors = (real_T)localB->y[imgIdxLL - 1];
      }
    }

    iy++;
    maxval[iy - 1] = (uint32_T)rtb_num_colors;
    j += 159;
  }

  rtb_num_colors = (real_T)maxval[0];
  imgIdxUR = 1;
  for (flag = 2; flag < 121; flag++) {
    imgIdxUR++;
    if ((int32_T)maxval[imgIdxUR - 1] > (int32_T)rtb_num_colors) {
      rtb_num_colors = (real_T)maxval[imgIdxUR - 1];
    }
  }

  for (imgIdxUR = 0; imgIdxUR < 19200; imgIdxUR++) {
    localB->LabelMatrix[imgIdxUR] = localB->LabelMatrix[imgIdxUR] /
      rtb_num_colors;
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
  for (j = 1; j < 119; j++) {
    for (imgIdxUR = 1; imgIdxUR < 159; imgIdxUR++) {
      rtb_num_colors = 0.0;
      accumTwo = 0.0;
      flag = j * 160 + imgIdxUR;
      for (m = 0; m < 6; m++) {
        rtb_num_colors += localB->LabelMatrix[flag +
          localDW->EdgeDetection_VO_DW[m]] *
          validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += localB->LabelMatrix[flag + localDW->EdgeDetection_HO_DW[m]] *
          validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[flag] = rtb_num_colors *
        rtb_num_colors;
      localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumTwo * accumTwo;
    }
  }

  for (j = 1; j < 119; j++) {
    rtb_num_colors = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    flag = j * 160;
    imgIdxUR = j * 160 + 159;
    for (m = 0; m < 6; m++) {
      rtb_num_colors += localB->LabelMatrix[flag + localDW->
        EdgeDetection_HOU_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += localB->LabelMatrix[imgIdxUR + localDW->EdgeDetection_HOD_DW[m]]
        * validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += localB->LabelMatrix[flag + localDW->EdgeDetection_VOU_DW[m]]
        * validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += localB->LabelMatrix[imgIdxUR + localDW->
        EdgeDetection_VOD_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumThree * accumThree;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = rtb_num_colors * rtb_num_colors;
    localDW->EdgeDetection_GV_SQUARED_DW[imgIdxUR] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdxUR] = accumTwo * accumTwo;
  }

  for (imgIdxUR = 1; imgIdxUR < 159; imgIdxUR++) {
    rtb_num_colors = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    flag = 19040 + imgIdxUR;
    for (m = 0; m < 6; m++) {
      rtb_num_colors += localB->LabelMatrix[imgIdxUR +
        localDW->EdgeDetection_VOL_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += localB->LabelMatrix[flag + localDW->EdgeDetection_VOR_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += localB->LabelMatrix[imgIdxUR + localDW->
        EdgeDetection_HOL_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += localB->LabelMatrix[flag + localDW->EdgeDetection_HOR_DW[m]] *
        validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgIdxUR] = rtb_num_colors *
      rtb_num_colors;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdxUR] = accumThree * accumThree;
    localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumTwo * accumTwo;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumFour * accumFour;
  }

  rtb_num_colors = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    rtb_num_colors += localB->LabelMatrix[localDW->EdgeDetection_VOUL_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->LabelMatrix[localDW->EdgeDetection_HOUL_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->LabelMatrix[159 + localDW->EdgeDetection_VOLL_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->LabelMatrix[159 + localDW->EdgeDetection_HOLL_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = rtb_num_colors * rtb_num_colors;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[159] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[159] = accumFour * accumFour;
  rtb_num_colors = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    rtb_num_colors += localB->LabelMatrix[19040 + localDW->
      EdgeDetection_VOUR_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->LabelMatrix[19040 + localDW->EdgeDetection_HOUR_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->LabelMatrix[19199 + localDW->EdgeDetection_VOLR_DW[m]]
      * validation_gate_v4_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->LabelMatrix[19199 + localDW->EdgeDetection_HOLR_DW[m]] *
      validation_gate_v4_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[19040] = rtb_num_colors * rtb_num_colors;
  localDW->EdgeDetection_GH_SQUARED_DW[19040] = accumTwo * accumTwo;
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

  rtb_num_colors = 3.0 * accumTwo;
  for (j = 0; j < 120; j++) {
    for (imgIdxUR = 0; imgIdxUR < 160; imgIdxUR++) {
      m = j * 160 + imgIdxUR;
      localB->EdgeDetection[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] >
        rtb_num_colors) && (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (j != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 160] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (j != 119 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 160] : TRUE)) ||
                            ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (imgIdxUR != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgIdxUR != 159 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&localB->EdgeDetection[0], &localB->HoughTransform1_o1[0],
                &validation_gate_v4_ConstP.HoughTransform1_SINE[0],
                &validation_gate_v4_ConstP.HoughTransform1_FIRSTRHO_R, 160, 120,
                399, 91);

  /* Embedded MATLAB: '<Root>/Identify Validation Gate' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  memcpy((void *)(&localB->hough_table[0]), (void *)(&localB->
          HoughTransform1_o1[0]), 71820U * sizeof(real_T));

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
  /*  eps_rho must be at least as big as the gate leg diameter (units of */
  /*    pixels) */
  /* '<S2>:1:38' */
  /*  eps_theta is used to distinguish lines as "horizontal" or "vertical"; */
  /*    units are radians */
  /* '<S2>:1:41' */
  /*  These vectors contain the final three lines that compose the validation gate */
  /* '<S2>:1:45' */
  /* '<S2>:1:46' */
  rho_gate_idx_1 = 0.0;
  theta_gate_idx_1 = 0.0;
  rho_gate_idx_0 = 0.0;
  theta_gate_idx_0 = 0.0;
  rho_gate_idx = 0.0;
  theta_gate_idx = 0.0;

  /*  These vectors contain intermediate line information; as lines are */
  /*    eliminated from these vectors, their values are set to zero */
  /* '<S2>:1:50' */
  /* '<S2>:1:51' */
  /*  Identify the most popular max_num_lines lines */
  /* '<S2>:1:58' */
  /* '<S2>:1:59' */
  for (imgIdxUR = 0; imgIdxUR < 200; imgIdxUR++) {
    i_index[imgIdxUR] = 1;
    j_index[imgIdxUR] = 1U;
  }

  /* '<S2>:1:61' */
  for (m = 0; m < 200; m++) {
    /* '<S2>:1:62' */
    /* '<S2>:1:64' */
    rtb_num_colors = 0.0;

    /* '<S2>:1:65' */
    for (imgIdxUR = 0; imgIdxUR < 399; imgIdxUR++) {
      /* '<S2>:1:65' */
      /* '<S2>:1:66' */
      for (j = 0; j < 180; j++) {
        /* '<S2>:1:66' */
        if (localB->hough_table[399 * j + imgIdxUR] > rtb_num_colors) {
          /* '<S2>:1:67' */
          /* '<S2>:1:68' */
          i_index[m] = (int16_T)(imgIdxUR + 1);

          /* '<S2>:1:69' */
          j_index[m] = (uint8_T)(j + 1);

          /* '<S2>:1:70' */
          rtb_num_colors = localB->hough_table[399 * j + imgIdxUR];
        }
      }
    }

    /* '<S2>:1:75' */
    rho[m] = localB->HoughTransform1_o3[i_index[m] - 1];

    /* '<S2>:1:76' */
    theta[m] = localB->HoughTransform1_o2[j_index[m] - 1];

    /* '<S2>:1:77' */
    localB->hough_table[(i_index[m] - 1) + 399 * (j_index[m] - 1)] = 0.0;

    /* '<S2>:1:78' */
  }

  /*  Effectively generate a small Hough table which contains only values of */
  /*    interest for the validation gate application */
  /* '<S2>:1:86' */
  /*  Rho bins for vertical lines */
  /*  Number of rho bins for vertical lines */
  /* '<S2>:1:88' */
  /*  Average rho values for each bin (note that the average value will generally differ slightly than the bin value) */
  /* '<S2>:1:89' */
  /*  Average theta values for each bin */
  /* '<S2>:1:90' */
  /*  Votes bins for vertical lines */
  /* '<S2>:1:92' */
  /* '<S2>:1:94' */
  /* '<S2>:1:95' */
  /* '<S2>:1:96' */
  for (imgIdxUR = 0; imgIdxUR < 6; imgIdxUR++) {
    rbinv[imgIdxUR] = (uint8_T)(imgIdxUR << 5);
    ravgv[imgIdxUR] = 0.0;
    tavgv[imgIdxUR] = 0.0;
    vbinv[imgIdxUR] = 0.0;
    rbinh[imgIdxUR] = (uint8_T)(imgIdxUR << 5);
    ravgh[imgIdxUR] = 0.0;
    tavgh[imgIdxUR] = 0.0;
    vbinh[imgIdxUR] = 0.0;
  }

  /*  Allow vertical lines along the left side of the image */
  /* '<S2>:1:99' */
  rbinv[0] = 1U;

  /* '<S2>:1:100' */
  rbinh[0] = 1U;

  /* '<S2>:1:102' */
  for (imgIdxUR = 0; imgIdxUR < 200; imgIdxUR++) {
    /* '<S2>:1:102' */
    /*  Consider only lines that are either vertical or horizontal, within */
    /*    tolerance */
    if ((fabs(theta[imgIdxUR] - 1.5707963267948966) <= 0.17453292519943295) ||
        (fabs(theta[imgIdxUR] + 1.5707963267948966) <= 0.17453292519943295)) {
      /* '<S2>:1:106' */
      searchingForNonNaN = TRUE;
    } else {
      /* '<S2>:1:106' */
      searchingForNonNaN = FALSE;
    }

    /*  Horizontal line */
    /* '<S2>:1:107' */
    /*  Vertical line */
    guard = FALSE;
    if (fabs(theta[imgIdxUR]) <= 0.17453292519943295) {
      /* '<S2>:1:109' */
      if ((rho[imgIdxUR] == 0.0) && (theta[imgIdxUR] == 0.0)) {
        /* '<S2>:1:109' */
        b_searchingForNonNaN = TRUE;
      } else {
        /* '<S2>:1:109' */
        b_searchingForNonNaN = FALSE;
      }

      if (!b_searchingForNonNaN) {
        /* '<S2>:1:109' */
        /*  Analyze vertical lines (ignore lines exactly along the left side of the image) */
        /* '<S2>:1:111' */
        flag = 1;
        b_searchingForNonNaN = FALSE;
        while (((uint32_T)b_searchingForNonNaN == 0U) && (flag <= 6)) {
          /* '<S2>:1:111' */
          /*  Place each rho value into a bin */
          if (fabs(rho[imgIdxUR] - (real_T)rbinv[flag - 1]) <= 16.0) {
            /* '<S2>:1:114' */
            /* '<S2>:1:115' */
            ravgv[flag - 1] = ravgv[flag - 1] + rho[imgIdxUR];

            /* '<S2>:1:116' */
            tavgv[flag - 1] = tavgv[flag - 1] + theta[imgIdxUR];

            /* '<S2>:1:117' */
            vbinv[flag - 1] = vbinv[flag - 1] + 1.0;
            b_searchingForNonNaN = TRUE;
          } else {
            flag++;
          }
        }
      } else {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard && searchingForNonNaN) {
      /* '<S2>:1:106' */
      /*  Analyze horizontal lines */
      if (theta[imgIdxUR] < 0.0) {
        /* '<S2>:1:125' */
        /* '<S2>:1:126' */
        theta[imgIdxUR] = theta[imgIdxUR] + 3.1415926535897931;

        /* '<S2>:1:127' */
        rho[imgIdxUR] = -rho[imgIdxUR];
      }

      /* '<S2>:1:130' */
      flag = 1;
      searchingForNonNaN = FALSE;
      while (((uint32_T)searchingForNonNaN == 0U) && (flag <= 6)) {
        /* '<S2>:1:130' */
        /*  Place each rho value into a bin */
        if (fabs(rho[imgIdxUR] - (real_T)rbinh[flag - 1]) <= 16.0) {
          /* '<S2>:1:133' */
          /* '<S2>:1:134' */
          ravgh[flag - 1] = ravgh[flag - 1] + rho[imgIdxUR];

          /* '<S2>:1:135' */
          tavgh[flag - 1] = tavgh[flag - 1] + theta[imgIdxUR];

          /* '<S2>:1:136' */
          vbinh[flag - 1] = vbinh[flag - 1] + 1.0;
          searchingForNonNaN = TRUE;
        } else {
          flag++;
        }
      }
    }
  }

  /*  Average the values in ravg and tavg for horizontal and vertical lines */
  /* '<S2>:1:146' */
  /* '<S2>:1:155' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:146' */
    if (vbinv[flag] == 0.0) {
      /* '<S2>:1:147' */
      /* '<S2>:1:148' */
      ravgv_0 = 0.0;

      /* '<S2>:1:149' */
      rtb_num_colors = 0.0;
    } else {
      /* '<S2>:1:151' */
      ravgv_0 = ravgv[flag] / vbinv[flag];

      /* '<S2>:1:152' */
      rtb_num_colors = tavgv[flag] / vbinv[flag];
    }

    /* '<S2>:1:155' */
    if (vbinh[flag] == 0.0) {
      /* '<S2>:1:156' */
      /* '<S2>:1:157' */
      accumTwo = 0.0;

      /* '<S2>:1:158' */
      accumThree = 0.0;
    } else {
      /* '<S2>:1:160' */
      accumTwo = ravgh[flag] / vbinh[flag];

      /* '<S2>:1:161' */
      accumThree = tavgh[flag] / vbinh[flag];
    }

    ravgv[flag] = ravgv_0;
    tavgv[flag] = rtb_num_colors;
    ravgh[flag] = accumTwo;
    tavgh[flag] = accumThree;
  }

  /* % Extract three lines that fit the criteria for being the validation gate */
  /* '<S2>:1:167' */
  rtb_num_colors = 10000.0;

  /* '<S2>:1:168' */
  accumTwo = -10000.0;

  /* '<S2>:1:169' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:169' */
    /*  Extract the left-most vertical line */
    if ((ravgv[flag] < rtb_num_colors) && (ravgv[flag] != 0.0)) {
      /* '<S2>:1:172' */
      /* '<S2>:1:173' */
      rtb_num_colors = ravgv[flag];

      /* '<S2>:1:174' */
      rho_gate_idx_1 = ravgv[flag];

      /* '<S2>:1:175' */
      theta_gate_idx_1 = tavgv[flag];
    }

    /*  Extract the right-most vertical line */
    if ((ravgv[flag] > accumTwo) && (ravgv[flag] != 0.0)) {
      /* '<S2>:1:179' */
      /* '<S2>:1:180' */
      accumTwo = ravgv[flag];

      /* '<S2>:1:181' */
      rho_gate_idx = ravgv[flag];

      /* '<S2>:1:182' */
      theta_gate_idx = tavgv[flag];
    }
  }

  /*  Check that the distance between the vertical lines is much greater than */
  /*    the minimum expected distance, eps_rho */
  if (fabs(rho_gate_idx - rho_gate_idx_1) < 32.0) {
    /* '<S2>:1:189' */
    /* '<S2>:1:190' */
    rho_gate_idx_1 = 0.0;

    /* '<S2>:1:191' */
    rho_gate_idx = 0.0;

    /* '<S2>:1:192' */
    theta_gate_idx_1 = 0.0;

    /* '<S2>:1:193' */
    theta_gate_idx = 0.0;
  }

  /* rmin = 10000; */
  /* '<S2>:1:197' */
  rtb_num_colors = 0.0;

  /* '<S2>:1:198' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:198' */
    /*  Extract the horizontal line with the most votes */
    if ((vbinh[flag] > rtb_num_colors) && (ravgh[flag] != 0.0)) {
      /* '<S2>:1:201' */
      /* '<S2>:1:202' */
      rtb_num_colors = vbinh[flag];

      /* '<S2>:1:203' */
      rho_gate_idx_0 = ravgh[flag];

      /* '<S2>:1:204' */
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
  /* '<S2>:1:218' */
  accumThree = (rho_gate_idx_1 / cos(theta_gate_idx_1) - rho_gate_idx_0 / cos
                (theta_gate_idx_0)) * (1.0 / (tan(theta_gate_idx_1) - tan
    (theta_gate_idx_0)));

  /* '<S2>:1:219' */
  accumFour = (rho_gate_idx_1 - accumThree * sin(theta_gate_idx_1)) * (1.0 / cos
    (theta_gate_idx_1));

  /* '<S2>:1:221' */
  rtb_num_colors = (rho_gate_idx_0 / cos(theta_gate_idx_0) - rho_gate_idx / cos
                    (theta_gate_idx)) * (1.0 / (tan(theta_gate_idx_0) - tan
    (theta_gate_idx)));

  /* '<S2>:1:222' */
  c = (rho_gate_idx_0 - rtb_num_colors * sin(theta_gate_idx_0)) * (1.0 / cos
    (theta_gate_idx_0));

  /* '<S2>:1:224' */
  /* '<S2>:1:225' */
  /*  Compute gate width */
  /* '<S2>:1:228' */
  /*  Form unit vector pointing downward, parallel to gate posts */
  /* '<S2>:1:231' */
  /* '<S2>:1:232' */
  u[0] = 1.0;
  u[1] = tan((((theta_gate_idx_0 - 1.5707963267948966) + theta_gate_idx_1) +
              theta_gate_idx) / 3.0);

  /* '<S2>:1:233' */
  accumTwo = opphmoppiecjmglf_norm(u);
  u[0] = 1.0 / accumTwo;
  u[1] = u[1] / accumTwo;

  /*  Compute target location */
  /* '<S2>:1:236' */
  accumTwo = sqrt(rt_pow_snf(rtb_num_colors - accumThree, 2.0) + rt_pow_snf(c -
    accumFour, 2.0)) * 0.282;

  /* '<S2>:1:237' */
  /* '<S2>:1:238' */
  /*  Determine if a gate is present (very simple, potentially inaccurate) */
  rho_gate[0] = (real_T)(rho_gate_idx_1 == 0.0) + (real_T)(theta_gate_idx_1 ==
    0.0);
  rho_gate[1] = (real_T)(rho_gate_idx_0 == 0.0) + (real_T)(theta_gate_idx_0 ==
    0.0);
  rho_gate[2] = (real_T)(rho_gate_idx == 0.0) + (real_T)(theta_gate_idx == 0.0);
  if (aaieaaiejmopnglf_sum(rho_gate) > 0.0) {
    /* '<S2>:1:241' */
    /* '<S2>:1:243' */
    flag = 0;

    /* '<S2>:1:244' */
    (*rty_TargetZ) = 0.0;

    /* '<S2>:1:245' */
    (*rty_TargetY) = 0.0;
  } else {
    /* '<S2>:1:249' */
    flag = 1;

    /*  Transform target r, c to global coordinate system */
    /* '<S2>:1:252' */
    (*rty_TargetZ) = ((accumThree + rtb_num_colors) / 2.0 + accumTwo * u[0]) -
      80.0;

    /* '<S2>:1:253' */
    (*rty_TargetY) = ((accumFour + c) / 2.0 + accumTwo * u[1]) - 60.0;
  }

  (*rty_TargetDetected) = (real_T)flag;

  /* Constant: '<Root>/Constant6' */
  (*rty_TargetYaw) = 0.0;
}

/* Model initialize function */
void mr_validation_gate_v_initialize(const char_T **rt_errorStatus,
  RT_MODEL_validation_gate_v4 *const validation_gate_v4_M,
  rtB_mr_validation_gate_v4 *localB, rtDW_mr_validation_gate_v4 *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(validation_gate_v4_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_validation_gate_v4));

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
                sizeof(rtDW_mr_validation_gate_v4));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
