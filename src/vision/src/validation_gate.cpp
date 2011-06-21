/*
 * File: validation_gate.cpp
 *
 * Real-Time Workshop code generated for Simulink model validation_gate.
 *
 * Model version                        : 1.1174
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun 21 01:40:54 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun 21 01:40:54 2011
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
 *    '<S5>/Low Pass Filter'
 *    '<S5>/Low Pass Filter1'
 *    '<S5>/Low Pass Filter2'
 */
void validation_gate_LowPassFilter(const real_T rtu_I[307200],
  rtB_LowPassFilter_validation_ga *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S5>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S7>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S7>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 307200U * sizeof(real_T));

  /* '<S7>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S7>:1:19' */
  /* '<S7>:1:21' */
  /* '<S7>:1:23' */
  Gsum = 0.0;

  /* '<S7>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S7>:1:24' */
    /* '<S7>:1:25' */
    /* '<S7>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S7>:1:27' */
    Gsum += G[i + 1];

    /* '<S7>:1:25' */
    /* '<S7>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S7>:1:27' */
    Gsum += G[i + 4];

    /* '<S7>:1:25' */
    /* '<S7>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S7>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S7>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S7>:1:33' */
  kfknaaaaecjemohd_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S7>:1:37' */
  for (i = 0; i < 478; i++) {
    localB->Iout[640 * (1 + i)] = localB->Itemp[638 * i];
  }

  /*  bottom */
  /* '<S7>:1:39' */
  for (i = 0; i < 478; i++) {
    localB->Iout[639 + 640 * (1 + i)] = localB->Itemp[638 * i + 637];
  }

  /*  left */
  /* '<S7>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 638U * sizeof
         (real_T));

  /*  right */
  /* '<S7>:1:43' */
  memcpy((void *)(&localB->Iout[306561]), (void *)(&localB->Itemp[304326]), 638U
         * sizeof(real_T));

  /*  center */
  /* '<S7>:1:45' */
  for (i = 0; i < 478; i++) {
    memcpy((void *)(&localB->Iout[1 + 640 * (1 + i)]), (void *)(&localB->Itemp
            [638 * i]), 638U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S7>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S7>:1:49' */
  localB->Iout[305920] = localB->Itemp[303688];
  localB->Iout[306560] = localB->Itemp[304326];

  /*  bottom left corner */
  /* '<S7>:1:51' */
  localB->Iout[638] = localB->Itemp[636];
  localB->Iout[639] = localB->Itemp[637];

  /*  bottom right corner */
  /* '<S7>:1:53' */
  localB->Iout[306558] = localB->Itemp[304324];
  localB->Iout[306559] = localB->Itemp[304325];
  localB->Iout[307198] = localB->Itemp[304962];
  localB->Iout[307199] = localB->Itemp[304963];
}

/* Initial conditions for referenced model: 'validation_gate' */
void mr_validation_gate_Init(rtDW_mr_validation_gate *localDW)
{
  int32_T nonZeroIdx;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 3.2552083333333335E-6;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
      validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
      validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    if (validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640 +
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 640;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        validation_gate_ConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }
}

/* Output and update for referenced model: 'validation_gate' */
void mr_validation_gate(const real_T rtu_R_forward_in[307200], const real_T
  rtu_G_forward_in[307200], const real_T rtu_B_forward_in[307200], real_T
  *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, rtB_mr_validation_gate *localB, rtDW_mr_validation_gate
  *localDW)
{
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
  int16_T rbinv[6];
  real_T ravgv[6];
  real_T tavgv[6];
  real_T vbinv[6];
  int16_T rbinh[6];
  real_T ravgh[6];
  real_T tavgh[6];
  real_T vbinh[6];
  boolean_T b;
  boolean_T c;
  boolean_T guard;
  int32_T imgCol;
  real_T accumOne;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  int32_T imgIdx_d;
  real_T rtb_num_colors;
  real_T rtb_ref_colors[150];
  int32_T i;
  real_T rho_gate[3];
  real_T theta_gate_idx;
  real_T rho_gate_idx;
  real_T theta_gate_idx_0;
  real_T rho_gate_idx_0;
  real_T theta_gate_idx_1;
  real_T rho_gate_idx_1;
  int32_T gate_i_idx;

  /* Constant: '<Root>/Constant3' */
  (*rty_TargetSelect) = 1.0;

  /* Constant: '<Root>/Constant4' */
  (*rty_TargetFound) = 1.0;

  /* Constant: '<Root>/Constant5' */
  (*rty_MaintainHeading) = 1.0;

  /* Embedded MATLAB: '<S5>/Low Pass Filter' */
  validation_gate_LowPassFilter(rtu_R_forward_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S5>/Low Pass Filter1' */
  validation_gate_LowPassFilter(rtu_G_forward_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S5>/Low Pass Filter2' */
  validation_gate_LowPassFilter(rtu_B_forward_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (imgIdx_d = 0; imgIdx_d < 307200; imgIdx_d++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[imgIdx_d] <= 0.039286085583733095) {
      accumOne = localB->sf_LowPassFilter.Iout[imgIdx_d] / 12.923054468333255;
    } else {
      accumOne = rt_pow_snf((localB->sf_LowPassFilter.Iout[imgIdx_d] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter1.Iout[imgIdx_d] <= 0.039286085583733095) {
      accumTwo = localB->sf_LowPassFilter1.Iout[imgIdx_d] / 12.923054468333255;
    } else {
      accumTwo = rt_pow_snf((localB->sf_LowPassFilter1.Iout[imgIdx_d] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter2.Iout[imgIdx_d] <= 0.039286085583733095) {
      accumThree = localB->sf_LowPassFilter2.Iout[imgIdx_d] / 12.923054468333255;
    } else {
      accumThree = rt_pow_snf((localB->sf_LowPassFilter2.Iout[imgIdx_d] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    accumFour = (0.41239079926596 * accumOne + 0.35758433938388 * accumTwo) +
      0.18048078840183 * accumThree;
    rtb_num_colors = (0.21263900587151 * accumOne + 0.71516867876776 * accumTwo)
      + 0.07219231536073 * accumThree;
    accumOne = (0.01933081871559 * accumOne + 0.11919477979463 * accumTwo) +
      0.95053215224966 * accumThree;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (accumFour > 1.0) {
      accumFour = 1.0;
    } else {
      if (accumFour < 0.0) {
        accumFour = 0.0;
      }
    }

    if (rtb_num_colors > 1.0) {
      rtb_num_colors = 1.0;
    } else {
      if (rtb_num_colors < 0.0) {
        rtb_num_colors = 0.0;
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
    localB->ColorSpaceConversion1_o1[imgIdx_d] = accumFour;
    localB->ColorSpaceConversion1_o2[imgIdx_d] = rtb_num_colors;
    localB->ColorSpaceConversion1_o3[imgIdx_d] = accumOne;
  }

  /* Convert from XYZ to L*a*b* */
  for (imgIdx_d = 0; imgIdx_d < 307200; imgIdx_d++) {
    accumOne = localB->ColorSpaceConversion1_o1[imgIdx_d] / 0.9641986557609;
    accumThree = localB->ColorSpaceConversion1_o3[imgIdx_d] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (accumOne > 0.0088564516790356311) {
      accumFour = rt_pow_snf(accumOne, 0.33333333333333331);
    } else {
      accumFour = 7.7870370370370372 * accumOne + 0.13793103448275862;
    }

    if (localB->ColorSpaceConversion1_o2[imgIdx_d] > 0.0088564516790356311) {
      accumTwo = rt_pow_snf(localB->ColorSpaceConversion1_o2[imgIdx_d],
                            0.33333333333333331);
    } else {
      accumTwo = 7.7870370370370372 * localB->ColorSpaceConversion1_o2[imgIdx_d]
        + 0.13793103448275862;
    }

    if (accumThree > 0.0088564516790356311) {
      accumOne = rt_pow_snf(accumThree, 0.33333333333333331);
    } else {
      accumOne = 7.7870370370370372 * accumThree + 0.13793103448275862;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdx_d] = 116.0 * accumTwo - 16.0;
    localB->ColorSpaceConversion1_o2[imgIdx_d] = (accumFour - accumTwo) * 500.0;
    localB->ColorSpaceConversion1_o3[imgIdx_d] = (accumTwo - accumOne) * 200.0;
  }

  /* S-Function (svipresize): '<S12>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 640; m++) {
    gate_i_idx = m;
    for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
      i = imgIdx_d;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 12; imgCol++) {
        accumOne += localB->
          ColorSpaceConversion1_o1[validation_gate_ConstP.pooled5[i] * 640 + m] *
          validation_gate_ConstP.pooled3[i];
        i += 80;
      }

      localDW->Resize_IntBuffer[gate_i_idx] = accumOne;
      gate_i_idx += 640;
    }
  }

  for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
    memcpy((void *)(&localDW->Resize2_LineBuffer[0]), (void *)
           (&localDW->Resize_IntBuffer[imgIdx_d * 640]), 640U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 22; imgCol++) {
        accumOne += localDW->Resize2_LineBuffer[validation_gate_ConstP.pooled4[i]]
          * validation_gate_ConstP.pooled2[i];
        i += 60;
      }

      localB->Resize[j] = accumOne;
      j++;
    }
  }

  /* S-Function (svipresize): '<S12>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 640; m++) {
    gate_i_idx = m;
    for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
      i = imgIdx_d;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 12; imgCol++) {
        accumOne += localB->
          ColorSpaceConversion1_o2[validation_gate_ConstP.pooled5[i] * 640 + m] *
          validation_gate_ConstP.pooled3[i];
        i += 80;
      }

      localDW->Resize1_IntBuffer[gate_i_idx] = accumOne;
      gate_i_idx += 640;
    }
  }

  for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
    memcpy((void *)(&localDW->Resize2_LineBuffer[0]), (void *)
           (&localDW->Resize1_IntBuffer[imgIdx_d * 640]), 640U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 22; imgCol++) {
        accumOne += localDW->Resize2_LineBuffer[validation_gate_ConstP.pooled4[i]]
          * validation_gate_ConstP.pooled2[i];
        i += 60;
      }

      localB->Resize1[j] = accumOne;
      j++;
    }
  }

  /* S-Function (svipresize): '<S12>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (m = 0; m < 640; m++) {
    gate_i_idx = m;
    for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
      i = imgIdx_d;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 12; imgCol++) {
        accumOne += localB->
          ColorSpaceConversion1_o3[validation_gate_ConstP.pooled5[i] * 640 + m] *
          validation_gate_ConstP.pooled3[i];
        i += 80;
      }

      localDW->Resize2_IntBuffer[gate_i_idx] = accumOne;
      gate_i_idx += 640;
    }
  }

  for (imgIdx_d = 0; imgIdx_d < 80; imgIdx_d++) {
    memcpy((void *)(&localDW->Resize2_LineBuffer[0]), (void *)
           (&localDW->Resize2_IntBuffer[imgIdx_d * 640]), 640U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      i = m;
      accumOne = 0.0;
      for (imgCol = 0; imgCol < 22; imgCol++) {
        accumOne += localDW->Resize2_LineBuffer[validation_gate_ConstP.pooled4[i]]
          * validation_gate_ConstP.pooled2[i];
        i += 60;
      }

      localB->Resize2[j] = accumOne;
      j++;
    }
  }

  /* Embedded MATLAB: '<S6>/Reference Color Selection' incorporates:
   *  Constant: '<S6>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/Reference Color Selection': '<S11>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S11>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S11>:1:14' */
  /* '<S11>:1:15' */
  memset((void *)&rtb_ref_colors[0], 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S11>:1:16' */
  memset((void *)(&localB->LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S11>:1:17' */
  imgCol = 1;

  /*  Define first reference color to be colr */
  /* '<S11>:1:23' */
  rtb_ref_colors[0] = localB->Resize[2369];
  rtb_ref_colors[50] = localB->Resize1[2369];
  rtb_ref_colors[100] = localB->Resize2[2369];

  /* '<S11>:1:25' */
  flag = 0;

  /* '<S11>:1:26' */
  imgIdx_d = 1;

  /* '<S11>:1:27' */
  j = 1;
  while (imgIdx_d <= 60) {
    /* '<S11>:1:28' */
    /*  perform initial segmentation */
    while ((imgIdx_d <= 60) && (flag == 0)) {
      /* '<S11>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S11>:1:30' */
        /* '<S11>:1:31' */
        accumThree = 1.0;

        /* '<S11>:1:32' */
        accumOne = 1000.0;

        /* '<S11>:1:33' */
        accumTwo = 1.0;
        while ((uint32_T)accumThree <= (uint32_T)imgCol) {
          /* '<S11>:1:34' */
          /* '<S11>:1:35' */
          accumFour = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)accumThree + 49]
            - localB->Resize1[(j - 1) * 60 + (imgIdx_d - 1)], 2.0) * 1.5 +
                            rt_pow_snf(rtb_ref_colors[(int32_T)accumThree - 1] -
            localB->Resize[(j - 1) * 60 + (imgIdx_d - 1)], 2.0)) + rt_pow_snf
                           (rtb_ref_colors[(int32_T)accumThree + 99] -
                            localB->Resize2[(j - 1) * 60 + (imgIdx_d - 1)], 2.0)
                           * 1.5);
          if (accumOne > accumFour) {
            /* '<S11>:1:36' */
            /* '<S11>:1:37' */
            accumOne = accumFour;

            /* '<S11>:1:38' */
            accumTwo = accumThree;
          }

          /* '<S11>:1:40' */
          accumThree++;
        }

        if ((accumOne > 60.0) && (imgCol < 50)) {
          /* '<S11>:1:45' */
          /* '<S11>:1:46' */
          rtb_ref_colors[imgCol] = localB->Resize[(j - 1) * 60 + (imgIdx_d - 1)];
          rtb_ref_colors[imgCol + 50] = localB->Resize1[(j - 1) * 60 + (imgIdx_d
            - 1)];
          rtb_ref_colors[imgCol + 100] = localB->Resize2[(j - 1) * 60 +
            (imgIdx_d - 1)];

          /* '<S11>:1:47' */
          imgCol++;

          /* '<S11>:1:48' */
          flag = 1;

          /* '<S11>:1:49' */
          imgIdx_d = 0;

          /* '<S11>:1:50' */
          j = 0;
        } else {
          /* '<S11>:1:52' */
          localB->LabelMatrix_m[(imgIdx_d - 1) + 60 * (j - 1)] = (uint32_T)
            accumTwo;
        }

        /* '<S11>:1:54' */
        j++;
      }

      /* '<S11>:1:56' */
      j = 1;

      /* '<S11>:1:57' */
      imgIdx_d++;
    }

    /* '<S11>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S11>:1:63' */
  /* '<S11>:1:64' */
  /* '<S11>:1:65' */
  /* '<S11>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S11>:1:67' */
  for (imgIdx_d = 0; imgIdx_d < 60; imgIdx_d++) {
    /* '<S11>:1:67' */
    /* '<S11>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S11>:1:68' */
      /* '<S11>:1:69' */
      /* '<S11>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix_m[imgIdx_d + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdx_d] - 1]
        + localB->Resize[60 * flag + imgIdx_d];

      /* '<S11>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix_m[imgIdx_d + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdx_d] - 1]
        + localB->Resize1[60 * flag + imgIdx_d];

      /* '<S11>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix_m[imgIdx_d + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdx_d] - 1]
        + localB->Resize2[60 * flag + imgIdx_d];

      /* '<S11>:1:73' */
      color_count[(int32_T)localB->LabelMatrix_m[imgIdx_d + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix_m[60 * flag + imgIdx_d] - 1] +
        1.0;
    }
  }

  /* '<S11>:1:76' */
  /* '<S11>:1:77' */
  /* '<S11>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S11>:1:80' */
  for (accumOne = 1.0; (uint32_T)accumOne <= (uint32_T)imgCol; accumOne++) {
    /* '<S11>:1:80' */
    /* '<S11>:1:81' */
    rtb_ref_colors[(int32_T)accumOne - 1] = ref_color_L_avg[(int32_T)accumOne -
      1];

    /* '<S11>:1:82' */
    rtb_ref_colors[(int32_T)accumOne + 49] = ref_color_a_avg[(int32_T)accumOne -
      1];

    /* '<S11>:1:83' */
    rtb_ref_colors[(int32_T)accumOne + 99] = ref_color_b_avg[(int32_T)accumOne -
      1];
  }

  rtb_num_colors = (real_T)imgCol;

  /* Embedded MATLAB: '<S6>/LabSegmentation' */
  /* Embedded MATLAB Function 'Convert to BW/IterativeSegmentation/Segmentation/LabSegmentation': '<S10>:1' */
  /*  This function generates the label matrix */
  /* '<S10>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0U, 307200U * sizeof
         (uint32_T));

  /* '<S10>:1:12' */
  for (imgIdx_d = 0; imgIdx_d < 640; imgIdx_d++) {
    /* '<S10>:1:12' */
    /* '<S10>:1:13' */
    for (j = 0; j < 480; j++) {
      /* '<S10>:1:13' */
      /* '<S10>:1:14' */
      accumOne = 1000.0;

      /* '<S10>:1:15' */
      accumTwo = 1.0;

      /* '<S10>:1:16' */
      for (accumThree = 1.0; accumThree <= rtb_num_colors; accumThree++) {
        /* '<S10>:1:16' */
        /* '<S10>:1:17' */
        accumFour = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)accumThree - 1] -
          localB->ColorSpaceConversion1_o1[640 * j + imgIdx_d], 2.0) +
                          rt_pow_snf(rtb_ref_colors[(int32_T)accumThree + 49] -
          localB->ColorSpaceConversion1_o2[640 * j + imgIdx_d], 2.0)) +
                         rt_pow_snf(rtb_ref_colors[(int32_T)accumThree + 99] -
          localB->ColorSpaceConversion1_o3[640 * j + imgIdx_d], 2.0));
        if (accumFour < accumOne) {
          /* '<S10>:1:18' */
          /* '<S10>:1:19' */
          accumOne = accumFour;

          /* '<S10>:1:20' */
          accumTwo = accumThree;
        }
      }

      /* '<S10>:1:23' */
      localB->LabelMatrix[imgIdx_d + 640 * j] = (uint32_T)accumTwo;
    }
  }

  /* '<S10>:1:27' */

  /* Embedded MATLAB: '<S1>/Identify Validation Gate2' */
  memcpy((void *)&ref_colors[0], (void *)&rtb_ref_colors[0], 150U * sizeof
         (real_T));

  /* Embedded MATLAB Function 'Convert to BW/Identify Validation Gate2': '<S3>:1' */
  /*  Initialize */
  /* '<S3>:1:8' */
  memset((void *)(&localB->intensity_image[0]), (int32_T)0, 307200U * sizeof
         (int8_T));

  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  maxL[0] = 0.0;
  i = 1;
  maxL[1] = 0.0;
  gate_i_idx = 1;

  /*  Identify max_num_cols colors with the brightest L color components */
  /* '<S3>:1:14' */
  /* '<S3>:1:16' */
  for (accumOne = 1.0; accumOne <= rtb_num_colors; accumOne++) {
    /* '<S3>:1:16' */
    if (ref_colors[(int32_T)accumOne - 1] > maxL[0]) {
      /* '<S3>:1:17' */
      /* '<S3>:1:18' */
      i = (int32_T)accumOne;

      /* '<S3>:1:19' */
      maxL[0] = ref_colors[(int32_T)accumOne - 1];
    }
  }

  /* '<S3>:1:23' */
  ref_colors[i - 1] = -1.0;

  /* '<S3>:1:14' */
  /* '<S3>:1:16' */
  for (accumOne = 1.0; accumOne <= rtb_num_colors; accumOne++) {
    /* '<S3>:1:16' */
    if (ref_colors[(int32_T)accumOne - 1] > maxL[1]) {
      /* '<S3>:1:17' */
      /* '<S3>:1:18' */
      gate_i_idx = (int32_T)accumOne;

      /* '<S3>:1:19' */
      maxL[1] = ref_colors[(int32_T)accumOne - 1];
    }
  }

  /* '<S3>:1:23' */
  /*  Ignore all non-white values */
  /* '<S3>:1:29' */
  for (flag = 0; flag < 640; flag++) {
    /* '<S3>:1:29' */
    /* '<S3>:1:30' */
    for (imgIdx_d = 0; imgIdx_d < 480; imgIdx_d++) {
      /* '<S3>:1:30' */
      /* '<S3>:1:32' */
      if ((int32_T)localB->LabelMatrix[640 * imgIdx_d + flag] == i) {
        /* '<S3>:1:33' */
        /* '<S3>:1:34' */
        localB->intensity_image[flag + 640 * imgIdx_d] = 1;
      }

      /* '<S3>:1:32' */
      if ((int32_T)localB->LabelMatrix[640 * imgIdx_d + flag] == gate_i_idx) {
        /* '<S3>:1:33' */
        /* '<S3>:1:34' */
        localB->intensity_image[flag + 640 * imgIdx_d] = 1;
      }
    }
  }

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 1; imgCol < 479; imgCol++) {
    for (j = 1; j < 639; j++) {
      accumOne = 0.0;
      accumTwo = 0.0;
      flag = imgCol * 640 + j;
      for (m = 0; m < 6; m++) {
        accumOne += (real_T)localB->intensity_image[flag +
          localDW->EdgeDetection_VO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += (real_T)localB->intensity_image[flag +
          localDW->EdgeDetection_HO_DW[m]] *
          validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumOne * accumOne;
      localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumTwo * accumTwo;
    }
  }

  for (imgCol = 1; imgCol < 479; imgCol++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    flag = imgCol * 640;
    imgIdx_d = imgCol * 640 + 639;
    for (m = 0; m < 6; m++) {
      accumOne += (real_T)localB->intensity_image[flag +
        localDW->EdgeDetection_HOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += (real_T)localB->intensity_image[imgIdx_d +
        localDW->EdgeDetection_HOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += (real_T)localB->intensity_image[flag +
        localDW->EdgeDetection_VOU_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += (real_T)localB->intensity_image[imgIdx_d +
        localDW->EdgeDetection_VOD_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumThree * accumThree;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumOne * accumOne;
    localDW->EdgeDetection_GV_SQUARED_DW[imgIdx_d] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[imgIdx_d] = accumTwo * accumTwo;
  }

  for (j = 1; j < 639; j++) {
    accumOne = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    flag = 306560 + j;
    for (m = 0; m < 6; m++) {
      accumOne += (real_T)localB->intensity_image[j +
        localDW->EdgeDetection_VOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += (real_T)localB->intensity_image[flag +
        localDW->EdgeDetection_VOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += (real_T)localB->intensity_image[j +
        localDW->EdgeDetection_HOL_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += (real_T)localB->intensity_image[flag +
        localDW->EdgeDetection_HOR_DW[m]] *
        validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[j] = accumOne * accumOne;
    localDW->EdgeDetection_GH_SQUARED_DW[j] = accumThree * accumThree;
    localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumTwo * accumTwo;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumFour * accumFour;
  }

  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += (real_T)localB->intensity_image[localDW->EdgeDetection_VOUL_DW[m]]
      * validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += (real_T)localB->intensity_image[localDW->EdgeDetection_HOUL_DW[m]]
      * validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += (real_T)localB->intensity_image[639 +
      localDW->EdgeDetection_VOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += (real_T)localB->intensity_image[639 +
      localDW->EdgeDetection_HOLL_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[639] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[639] = accumFour * accumFour;
  accumOne = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    accumOne += (real_T)localB->intensity_image[306560 +
      localDW->EdgeDetection_VOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += (real_T)localB->intensity_image[306560 +
      localDW->EdgeDetection_HOUR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += (real_T)localB->intensity_image[307199 +
      localDW->EdgeDetection_VOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += (real_T)localB->intensity_image[307199 +
      localDW->EdgeDetection_HOLR_DW[m]] *
      validation_gate_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[306560] = accumOne * accumOne;
  localDW->EdgeDetection_GH_SQUARED_DW[306560] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[307199] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[307199] = accumFour * accumFour;
  accumTwo = 0.0;
  for (m = 0; m < 307200; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->EdgeDetection_GRAD_SUM_DW[m]
      + localDW->EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += localDW->EdgeDetection_GRAD_SUM_DW[m] *
      localDW->EdgeDetection_MEAN_FACTOR_DW;
  }

  accumOne = 3.0 * accumTwo;
  for (imgCol = 0; imgCol < 480; imgCol++) {
    for (j = 0; j < 640; j++) {
      m = imgCol * 640 + j;
      localB->EdgeDetection[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] >
        accumOne) && (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (imgCol != 0
        ? localDW->EdgeDetection_GRAD_SUM_DW[m - 640] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (imgCol != 479 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 640] : TRUE)) ||
                      ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (j != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (j != 639 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&localB->EdgeDetection[0], &localB->HoughTransform1_o1[0],
                &validation_gate_ConstP.HoughTransform1_SINE[0],
                &validation_gate_ConstP.HoughTransform1_FIRSTRHO_R, 640, 480,
                1599, 91);

  /* Embedded MATLAB: '<Root>/Identify Validation Gate' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  memcpy((void *)(&localB->hough_table[0]), (void *)(&localB->
          HoughTransform1_o1[0]), 287820U * sizeof(real_T));

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
  for (i = 0; i < 200; i++) {
    i_index[i] = 1;
    j_index[i] = 1U;
  }

  /* '<S2>:1:61' */
  for (m = 0; m < 200; m++) {
    /* '<S2>:1:62' */
    /* '<S2>:1:64' */
    accumOne = 0.0;

    /* '<S2>:1:65' */
    for (imgIdx_d = 0; imgIdx_d < 1599; imgIdx_d++) {
      /* '<S2>:1:65' */
      /* '<S2>:1:66' */
      for (j = 0; j < 180; j++) {
        /* '<S2>:1:66' */
        if (localB->hough_table[1599 * j + imgIdx_d] > accumOne) {
          /* '<S2>:1:67' */
          /* '<S2>:1:68' */
          i_index[m] = (int16_T)(imgIdx_d + 1);

          /* '<S2>:1:69' */
          j_index[m] = (uint8_T)(j + 1);

          /* '<S2>:1:70' */
          accumOne = localB->hough_table[1599 * j + imgIdx_d];
        }
      }
    }

    /* '<S2>:1:75' */
    rho[m] = localB->HoughTransform1_o3[i_index[m] - 1];

    /* '<S2>:1:76' */
    theta[m] = localB->HoughTransform1_o2[j_index[m] - 1];

    /* '<S2>:1:77' */
    localB->hough_table[(i_index[m] - 1) + 1599 * (j_index[m] - 1)] = 0.0;

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
  for (i = 0; i < 6; i++) {
    rbinv[i] = (int16_T)(i << 7);
    ravgv[i] = 0.0;
    tavgv[i] = 0.0;
    vbinv[i] = 0.0;
    rbinh[i] = (int16_T)(i << 7);
    ravgh[i] = 0.0;
    tavgh[i] = 0.0;
    vbinh[i] = 0.0;
  }

  /*  Allow vertical lines along the left side of the image */
  /* '<S2>:1:99' */
  rbinv[0] = 1;

  /* '<S2>:1:100' */
  rbinh[0] = 1;

  /* '<S2>:1:102' */
  for (imgIdx_d = 0; imgIdx_d < 200; imgIdx_d++) {
    /* '<S2>:1:102' */
    /*  Consider only lines that are either vertical or horizontal, within */
    /*    tolerance */
    if ((fabs(theta[imgIdx_d] - 1.5707963267948966) <= 0.17453292519943295) ||
        (fabs(theta[imgIdx_d] + 1.5707963267948966) <= 0.17453292519943295)) {
      /* '<S2>:1:106' */
      b = TRUE;
    } else {
      /* '<S2>:1:106' */
      b = FALSE;
    }

    /*  Horizontal line */
    /* '<S2>:1:107' */
    /*  Vertical line */
    guard = FALSE;
    if (fabs(theta[imgIdx_d]) <= 0.17453292519943295) {
      /* '<S2>:1:109' */
      if ((rho[imgIdx_d] == 0.0) && (theta[imgIdx_d] == 0.0)) {
        /* '<S2>:1:109' */
        c = TRUE;
      } else {
        /* '<S2>:1:109' */
        c = FALSE;
      }

      if (!c) {
        /* '<S2>:1:109' */
        /*  Analyze vertical lines (ignore lines exactly along the left side of the image) */
        /* '<S2>:1:111' */
        flag = 1;
        c = FALSE;
        while (((uint32_T)c == 0U) && (flag <= 6)) {
          /* '<S2>:1:111' */
          /*  Place each rho value into a bin */
          if (fabs(rho[imgIdx_d] - (real_T)rbinv[flag - 1]) <= 64.0) {
            /* '<S2>:1:114' */
            /* '<S2>:1:115' */
            ravgv[flag - 1] = ravgv[flag - 1] + rho[imgIdx_d];

            /* '<S2>:1:116' */
            tavgv[flag - 1] = tavgv[flag - 1] + theta[imgIdx_d];

            /* '<S2>:1:117' */
            vbinv[flag - 1] = vbinv[flag - 1] + 1.0;
            c = TRUE;
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

    if (guard && b) {
      /* '<S2>:1:106' */
      /*  Analyze horizontal lines */
      if (theta[imgIdx_d] < 0.0) {
        /* '<S2>:1:125' */
        /* '<S2>:1:126' */
        theta[imgIdx_d] = theta[imgIdx_d] + 3.1415926535897931;

        /* '<S2>:1:127' */
        rho[imgIdx_d] = -rho[imgIdx_d];
      }

      /* '<S2>:1:130' */
      flag = 1;
      c = FALSE;
      while (((uint32_T)c == 0U) && (flag <= 6)) {
        /* '<S2>:1:130' */
        /*  Place each rho value into a bin */
        if (fabs(rho[imgIdx_d] - (real_T)rbinh[flag - 1]) <= 64.0) {
          /* '<S2>:1:133' */
          /* '<S2>:1:134' */
          ravgh[flag - 1] = ravgh[flag - 1] + rho[imgIdx_d];

          /* '<S2>:1:135' */
          tavgh[flag - 1] = tavgh[flag - 1] + theta[imgIdx_d];

          /* '<S2>:1:136' */
          vbinh[flag - 1] = vbinh[flag - 1] + 1.0;
          c = TRUE;
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
      accumOne = 0.0;

      /* '<S2>:1:149' */
      rtb_num_colors = 0.0;
    } else {
      /* '<S2>:1:151' */
      accumOne = ravgv[flag] / vbinv[flag];

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

    ravgv[flag] = accumOne;
    tavgv[flag] = rtb_num_colors;
    ravgh[flag] = accumTwo;
    tavgh[flag] = accumThree;
  }

  /* % Extract three lines that fit the criteria for being the validation gate */
  /* '<S2>:1:167' */
  accumOne = 10000.0;

  /* '<S2>:1:168' */
  accumTwo = -10000.0;

  /* '<S2>:1:169' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:169' */
    /*  Extract the left-most vertical line */
    if ((ravgv[flag] < accumOne) && (ravgv[flag] != 0.0)) {
      /* '<S2>:1:172' */
      /* '<S2>:1:173' */
      accumOne = ravgv[flag];

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
  if (fabs(rho_gate_idx - rho_gate_idx_1) < 128.0) {
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
  accumOne = 0.0;

  /* '<S2>:1:198' */
  for (flag = 0; flag < 6; flag++) {
    /* '<S2>:1:198' */
    /*  Extract the horizontal line with the most votes */
    if ((vbinh[flag] > accumOne) && (ravgh[flag] != 0.0)) {
      /* '<S2>:1:201' */
      /* '<S2>:1:202' */
      accumOne = vbinh[flag];

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
  accumTwo = (rho_gate_idx_1 / cos(theta_gate_idx_1) - rho_gate_idx_0 / cos
              (theta_gate_idx_0)) * (1.0 / (tan(theta_gate_idx_1) - tan
    (theta_gate_idx_0)));

  /* '<S2>:1:219' */
  accumThree = (rho_gate_idx_1 - accumTwo * sin(theta_gate_idx_1)) * (1.0 / cos
    (theta_gate_idx_1));

  /* '<S2>:1:221' */
  accumFour = (rho_gate_idx_0 / cos(theta_gate_idx_0) - rho_gate_idx / cos
               (theta_gate_idx)) * (1.0 / (tan(theta_gate_idx_0) - tan
    (theta_gate_idx)));

  /* '<S2>:1:222' */
  rtb_num_colors = (rho_gate_idx_0 - accumFour * sin(theta_gate_idx_0)) * (1.0 /
    cos(theta_gate_idx_0));

  /* '<S2>:1:224' */
  /* '<S2>:1:225' */
  /*  Compute gate width */
  /* '<S2>:1:228' */
  /*  Form unit vector pointing downward, parallel to gate posts */
  /* '<S2>:1:231' */
  /* '<S2>:1:232' */
  maxL[0] = 1.0;
  maxL[1] = tan((((theta_gate_idx_0 - 1.5707963267948966) + theta_gate_idx_1) +
                 theta_gate_idx) / 3.0);

  /* '<S2>:1:233' */
  accumOne = opphmoppiecjmglf_norm(maxL);
  maxL[0] = 1.0 / accumOne;
  maxL[1] = maxL[1] / accumOne;

  /*  Compute target location */
  /* '<S2>:1:236' */
  accumOne = sqrt(rt_pow_snf(accumFour - accumTwo, 2.0) + rt_pow_snf
                  (rtb_num_colors - accumThree, 2.0)) * 0.282;

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
    (*rty_TargetZ) = ((accumTwo + accumFour) / 2.0 + accumOne * maxL[0]) - 320.0;

    /* '<S2>:1:253' */
    (*rty_TargetY) = ((accumThree + rtb_num_colors) / 2.0 + accumOne * maxL[1])
      - 240.0;
  }

  (*rty_TargetDetected) = (real_T)flag;

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
    localB->HoughTransform1_o3[0] = -799.0;
    localB->HoughTransform1_o3[1] = -798.0;
    localB->HoughTransform1_o3[2] = -797.0;
    localB->HoughTransform1_o3[3] = -796.0;
    localB->HoughTransform1_o3[4] = -795.0;
    localB->HoughTransform1_o3[5] = -794.0;
    localB->HoughTransform1_o3[6] = -793.0;
    localB->HoughTransform1_o3[7] = -792.0;
    localB->HoughTransform1_o3[8] = -791.0;
    localB->HoughTransform1_o3[9] = -790.0;
    localB->HoughTransform1_o3[10] = -789.0;
    localB->HoughTransform1_o3[11] = -788.0;
    localB->HoughTransform1_o3[12] = -787.0;
    localB->HoughTransform1_o3[13] = -786.0;
    localB->HoughTransform1_o3[14] = -785.0;
    localB->HoughTransform1_o3[15] = -784.0;
    localB->HoughTransform1_o3[16] = -783.0;
    localB->HoughTransform1_o3[17] = -782.0;
    localB->HoughTransform1_o3[18] = -781.0;
    localB->HoughTransform1_o3[19] = -780.0;
    localB->HoughTransform1_o3[20] = -779.0;
    localB->HoughTransform1_o3[21] = -778.0;
    localB->HoughTransform1_o3[22] = -777.0;
    localB->HoughTransform1_o3[23] = -776.0;
    localB->HoughTransform1_o3[24] = -775.0;
    localB->HoughTransform1_o3[25] = -774.0;
    localB->HoughTransform1_o3[26] = -773.0;
    localB->HoughTransform1_o3[27] = -772.0;
    localB->HoughTransform1_o3[28] = -771.0;
    localB->HoughTransform1_o3[29] = -770.0;
    localB->HoughTransform1_o3[30] = -769.0;
    localB->HoughTransform1_o3[31] = -768.0;
    localB->HoughTransform1_o3[32] = -767.0;
    localB->HoughTransform1_o3[33] = -766.0;
    localB->HoughTransform1_o3[34] = -765.0;
    localB->HoughTransform1_o3[35] = -764.0;
    localB->HoughTransform1_o3[36] = -763.0;
    localB->HoughTransform1_o3[37] = -762.0;
    localB->HoughTransform1_o3[38] = -761.0;
    localB->HoughTransform1_o3[39] = -760.0;
    localB->HoughTransform1_o3[40] = -759.0;
    localB->HoughTransform1_o3[41] = -758.0;
    localB->HoughTransform1_o3[42] = -757.0;
    localB->HoughTransform1_o3[43] = -756.0;
    localB->HoughTransform1_o3[44] = -755.0;
    localB->HoughTransform1_o3[45] = -754.0;
    localB->HoughTransform1_o3[46] = -753.0;
    localB->HoughTransform1_o3[47] = -752.0;
    localB->HoughTransform1_o3[48] = -751.0;
    localB->HoughTransform1_o3[49] = -750.0;
    localB->HoughTransform1_o3[50] = -749.0;
    localB->HoughTransform1_o3[51] = -748.0;
    localB->HoughTransform1_o3[52] = -747.0;
    localB->HoughTransform1_o3[53] = -746.0;
    localB->HoughTransform1_o3[54] = -745.0;
    localB->HoughTransform1_o3[55] = -744.0;
    localB->HoughTransform1_o3[56] = -743.0;
    localB->HoughTransform1_o3[57] = -742.0;
    localB->HoughTransform1_o3[58] = -741.0;
    localB->HoughTransform1_o3[59] = -740.0;
    localB->HoughTransform1_o3[60] = -739.0;
    localB->HoughTransform1_o3[61] = -738.0;
    localB->HoughTransform1_o3[62] = -737.0;
    localB->HoughTransform1_o3[63] = -736.0;
    localB->HoughTransform1_o3[64] = -735.0;
    localB->HoughTransform1_o3[65] = -734.0;
    localB->HoughTransform1_o3[66] = -733.0;
    localB->HoughTransform1_o3[67] = -732.0;
    localB->HoughTransform1_o3[68] = -731.0;
    localB->HoughTransform1_o3[69] = -730.0;
    localB->HoughTransform1_o3[70] = -729.0;
    localB->HoughTransform1_o3[71] = -728.0;
    localB->HoughTransform1_o3[72] = -727.0;
    localB->HoughTransform1_o3[73] = -726.0;
    localB->HoughTransform1_o3[74] = -725.0;
    localB->HoughTransform1_o3[75] = -724.0;
    localB->HoughTransform1_o3[76] = -723.0;
    localB->HoughTransform1_o3[77] = -722.0;
    localB->HoughTransform1_o3[78] = -721.0;
    localB->HoughTransform1_o3[79] = -720.0;
    localB->HoughTransform1_o3[80] = -719.0;
    localB->HoughTransform1_o3[81] = -718.0;
    localB->HoughTransform1_o3[82] = -717.0;
    localB->HoughTransform1_o3[83] = -716.0;
    localB->HoughTransform1_o3[84] = -715.0;
    localB->HoughTransform1_o3[85] = -714.0;
    localB->HoughTransform1_o3[86] = -713.0;
    localB->HoughTransform1_o3[87] = -712.0;
    localB->HoughTransform1_o3[88] = -711.0;
    localB->HoughTransform1_o3[89] = -710.0;
    localB->HoughTransform1_o3[90] = -709.0;
    localB->HoughTransform1_o3[91] = -708.0;
    localB->HoughTransform1_o3[92] = -707.0;
    localB->HoughTransform1_o3[93] = -706.0;
    localB->HoughTransform1_o3[94] = -705.0;
    localB->HoughTransform1_o3[95] = -704.0;
    localB->HoughTransform1_o3[96] = -703.0;
    localB->HoughTransform1_o3[97] = -702.0;
    localB->HoughTransform1_o3[98] = -701.0;
    localB->HoughTransform1_o3[99] = -700.0;
    localB->HoughTransform1_o3[100] = -699.0;
    localB->HoughTransform1_o3[101] = -698.0;
    localB->HoughTransform1_o3[102] = -697.0;
    localB->HoughTransform1_o3[103] = -696.0;
    localB->HoughTransform1_o3[104] = -695.0;
    localB->HoughTransform1_o3[105] = -694.0;
    localB->HoughTransform1_o3[106] = -693.0;
    localB->HoughTransform1_o3[107] = -692.0;
    localB->HoughTransform1_o3[108] = -691.0;
    localB->HoughTransform1_o3[109] = -690.0;
    localB->HoughTransform1_o3[110] = -689.0;
    localB->HoughTransform1_o3[111] = -688.0;
    localB->HoughTransform1_o3[112] = -687.0;
    localB->HoughTransform1_o3[113] = -686.0;
    localB->HoughTransform1_o3[114] = -685.0;
    localB->HoughTransform1_o3[115] = -684.0;
    localB->HoughTransform1_o3[116] = -683.0;
    localB->HoughTransform1_o3[117] = -682.0;
    localB->HoughTransform1_o3[118] = -681.0;
    localB->HoughTransform1_o3[119] = -680.0;
    localB->HoughTransform1_o3[120] = -679.0;
    localB->HoughTransform1_o3[121] = -678.0;
    localB->HoughTransform1_o3[122] = -677.0;
    localB->HoughTransform1_o3[123] = -676.0;
    localB->HoughTransform1_o3[124] = -675.0;
    localB->HoughTransform1_o3[125] = -674.0;
    localB->HoughTransform1_o3[126] = -673.0;
    localB->HoughTransform1_o3[127] = -672.0;
    localB->HoughTransform1_o3[128] = -671.0;
    localB->HoughTransform1_o3[129] = -670.0;
    localB->HoughTransform1_o3[130] = -669.0;
    localB->HoughTransform1_o3[131] = -668.0;
    localB->HoughTransform1_o3[132] = -667.0;
    localB->HoughTransform1_o3[133] = -666.0;
    localB->HoughTransform1_o3[134] = -665.0;
    localB->HoughTransform1_o3[135] = -664.0;
    localB->HoughTransform1_o3[136] = -663.0;
    localB->HoughTransform1_o3[137] = -662.0;
    localB->HoughTransform1_o3[138] = -661.0;
    localB->HoughTransform1_o3[139] = -660.0;
    localB->HoughTransform1_o3[140] = -659.0;
    localB->HoughTransform1_o3[141] = -658.0;
    localB->HoughTransform1_o3[142] = -657.0;
    localB->HoughTransform1_o3[143] = -656.0;
    localB->HoughTransform1_o3[144] = -655.0;
    localB->HoughTransform1_o3[145] = -654.0;
    localB->HoughTransform1_o3[146] = -653.0;
    localB->HoughTransform1_o3[147] = -652.0;
    localB->HoughTransform1_o3[148] = -651.0;
    localB->HoughTransform1_o3[149] = -650.0;
    localB->HoughTransform1_o3[150] = -649.0;
    localB->HoughTransform1_o3[151] = -648.0;
    localB->HoughTransform1_o3[152] = -647.0;
    localB->HoughTransform1_o3[153] = -646.0;
    localB->HoughTransform1_o3[154] = -645.0;
    localB->HoughTransform1_o3[155] = -644.0;
    localB->HoughTransform1_o3[156] = -643.0;
    localB->HoughTransform1_o3[157] = -642.0;
    localB->HoughTransform1_o3[158] = -641.0;
    localB->HoughTransform1_o3[159] = -640.0;
    localB->HoughTransform1_o3[160] = -639.0;
    localB->HoughTransform1_o3[161] = -638.0;
    localB->HoughTransform1_o3[162] = -637.0;
    localB->HoughTransform1_o3[163] = -636.0;
    localB->HoughTransform1_o3[164] = -635.0;
    localB->HoughTransform1_o3[165] = -634.0;
    localB->HoughTransform1_o3[166] = -633.0;
    localB->HoughTransform1_o3[167] = -632.0;
    localB->HoughTransform1_o3[168] = -631.0;
    localB->HoughTransform1_o3[169] = -630.0;
    localB->HoughTransform1_o3[170] = -629.0;
    localB->HoughTransform1_o3[171] = -628.0;
    localB->HoughTransform1_o3[172] = -627.0;
    localB->HoughTransform1_o3[173] = -626.0;
    localB->HoughTransform1_o3[174] = -625.0;
    localB->HoughTransform1_o3[175] = -624.0;
    localB->HoughTransform1_o3[176] = -623.0;
    localB->HoughTransform1_o3[177] = -622.0;
    localB->HoughTransform1_o3[178] = -621.0;
    localB->HoughTransform1_o3[179] = -620.0;
    localB->HoughTransform1_o3[180] = -619.0;
    localB->HoughTransform1_o3[181] = -618.0;
    localB->HoughTransform1_o3[182] = -617.0;
    localB->HoughTransform1_o3[183] = -616.0;
    localB->HoughTransform1_o3[184] = -615.0;
    localB->HoughTransform1_o3[185] = -614.0;
    localB->HoughTransform1_o3[186] = -613.0;
    localB->HoughTransform1_o3[187] = -612.0;
    localB->HoughTransform1_o3[188] = -611.0;
    localB->HoughTransform1_o3[189] = -610.0;
    localB->HoughTransform1_o3[190] = -609.0;
    localB->HoughTransform1_o3[191] = -608.0;
    localB->HoughTransform1_o3[192] = -607.0;
    localB->HoughTransform1_o3[193] = -606.0;
    localB->HoughTransform1_o3[194] = -605.0;
    localB->HoughTransform1_o3[195] = -604.0;
    localB->HoughTransform1_o3[196] = -603.0;
    localB->HoughTransform1_o3[197] = -602.0;
    localB->HoughTransform1_o3[198] = -601.0;
    localB->HoughTransform1_o3[199] = -600.0;
    localB->HoughTransform1_o3[200] = -599.0;
    localB->HoughTransform1_o3[201] = -598.0;
    localB->HoughTransform1_o3[202] = -597.0;
    localB->HoughTransform1_o3[203] = -596.0;
    localB->HoughTransform1_o3[204] = -595.0;
    localB->HoughTransform1_o3[205] = -594.0;
    localB->HoughTransform1_o3[206] = -593.0;
    localB->HoughTransform1_o3[207] = -592.0;
    localB->HoughTransform1_o3[208] = -591.0;
    localB->HoughTransform1_o3[209] = -590.0;
    localB->HoughTransform1_o3[210] = -589.0;
    localB->HoughTransform1_o3[211] = -588.0;
    localB->HoughTransform1_o3[212] = -587.0;
    localB->HoughTransform1_o3[213] = -586.0;
    localB->HoughTransform1_o3[214] = -585.0;
    localB->HoughTransform1_o3[215] = -584.0;
    localB->HoughTransform1_o3[216] = -583.0;
    localB->HoughTransform1_o3[217] = -582.0;
    localB->HoughTransform1_o3[218] = -581.0;
    localB->HoughTransform1_o3[219] = -580.0;
    localB->HoughTransform1_o3[220] = -579.0;
    localB->HoughTransform1_o3[221] = -578.0;
    localB->HoughTransform1_o3[222] = -577.0;
    localB->HoughTransform1_o3[223] = -576.0;
    localB->HoughTransform1_o3[224] = -575.0;
    localB->HoughTransform1_o3[225] = -574.0;
    localB->HoughTransform1_o3[226] = -573.0;
    localB->HoughTransform1_o3[227] = -572.0;
    localB->HoughTransform1_o3[228] = -571.0;
    localB->HoughTransform1_o3[229] = -570.0;
    localB->HoughTransform1_o3[230] = -569.0;
    localB->HoughTransform1_o3[231] = -568.0;
    localB->HoughTransform1_o3[232] = -567.0;
    localB->HoughTransform1_o3[233] = -566.0;
    localB->HoughTransform1_o3[234] = -565.0;
    localB->HoughTransform1_o3[235] = -564.0;
    localB->HoughTransform1_o3[236] = -563.0;
    localB->HoughTransform1_o3[237] = -562.0;
    localB->HoughTransform1_o3[238] = -561.0;
    localB->HoughTransform1_o3[239] = -560.0;
    localB->HoughTransform1_o3[240] = -559.0;
    localB->HoughTransform1_o3[241] = -558.0;
    localB->HoughTransform1_o3[242] = -557.0;
    localB->HoughTransform1_o3[243] = -556.0;
    localB->HoughTransform1_o3[244] = -555.0;
    localB->HoughTransform1_o3[245] = -554.0;
    localB->HoughTransform1_o3[246] = -553.0;
    localB->HoughTransform1_o3[247] = -552.0;
    localB->HoughTransform1_o3[248] = -551.0;
    localB->HoughTransform1_o3[249] = -550.0;
    localB->HoughTransform1_o3[250] = -549.0;
    localB->HoughTransform1_o3[251] = -548.0;
    localB->HoughTransform1_o3[252] = -547.0;
    localB->HoughTransform1_o3[253] = -546.0;
    localB->HoughTransform1_o3[254] = -545.0;
    localB->HoughTransform1_o3[255] = -544.0;
    localB->HoughTransform1_o3[256] = -543.0;
    localB->HoughTransform1_o3[257] = -542.0;
    localB->HoughTransform1_o3[258] = -541.0;
    localB->HoughTransform1_o3[259] = -540.0;
    localB->HoughTransform1_o3[260] = -539.0;
    localB->HoughTransform1_o3[261] = -538.0;
    localB->HoughTransform1_o3[262] = -537.0;
    localB->HoughTransform1_o3[263] = -536.0;
    localB->HoughTransform1_o3[264] = -535.0;
    localB->HoughTransform1_o3[265] = -534.0;
    localB->HoughTransform1_o3[266] = -533.0;
    localB->HoughTransform1_o3[267] = -532.0;
    localB->HoughTransform1_o3[268] = -531.0;
    localB->HoughTransform1_o3[269] = -530.0;
    localB->HoughTransform1_o3[270] = -529.0;
    localB->HoughTransform1_o3[271] = -528.0;
    localB->HoughTransform1_o3[272] = -527.0;
    localB->HoughTransform1_o3[273] = -526.0;
    localB->HoughTransform1_o3[274] = -525.0;
    localB->HoughTransform1_o3[275] = -524.0;
    localB->HoughTransform1_o3[276] = -523.0;
    localB->HoughTransform1_o3[277] = -522.0;
    localB->HoughTransform1_o3[278] = -521.0;
    localB->HoughTransform1_o3[279] = -520.0;
    localB->HoughTransform1_o3[280] = -519.0;
    localB->HoughTransform1_o3[281] = -518.0;
    localB->HoughTransform1_o3[282] = -517.0;
    localB->HoughTransform1_o3[283] = -516.0;
    localB->HoughTransform1_o3[284] = -515.0;
    localB->HoughTransform1_o3[285] = -514.0;
    localB->HoughTransform1_o3[286] = -513.0;
    localB->HoughTransform1_o3[287] = -512.0;
    localB->HoughTransform1_o3[288] = -511.0;
    localB->HoughTransform1_o3[289] = -510.0;
    localB->HoughTransform1_o3[290] = -509.0;
    localB->HoughTransform1_o3[291] = -508.0;
    localB->HoughTransform1_o3[292] = -507.0;
    localB->HoughTransform1_o3[293] = -506.0;
    localB->HoughTransform1_o3[294] = -505.0;
    localB->HoughTransform1_o3[295] = -504.0;
    localB->HoughTransform1_o3[296] = -503.0;
    localB->HoughTransform1_o3[297] = -502.0;
    localB->HoughTransform1_o3[298] = -501.0;
    localB->HoughTransform1_o3[299] = -500.0;
    localB->HoughTransform1_o3[300] = -499.0;
    localB->HoughTransform1_o3[301] = -498.0;
    localB->HoughTransform1_o3[302] = -497.0;
    localB->HoughTransform1_o3[303] = -496.0;
    localB->HoughTransform1_o3[304] = -495.0;
    localB->HoughTransform1_o3[305] = -494.0;
    localB->HoughTransform1_o3[306] = -493.0;
    localB->HoughTransform1_o3[307] = -492.0;
    localB->HoughTransform1_o3[308] = -491.0;
    localB->HoughTransform1_o3[309] = -490.0;
    localB->HoughTransform1_o3[310] = -489.0;
    localB->HoughTransform1_o3[311] = -488.0;
    localB->HoughTransform1_o3[312] = -487.0;
    localB->HoughTransform1_o3[313] = -486.0;
    localB->HoughTransform1_o3[314] = -485.0;
    localB->HoughTransform1_o3[315] = -484.0;
    localB->HoughTransform1_o3[316] = -483.0;
    localB->HoughTransform1_o3[317] = -482.0;
    localB->HoughTransform1_o3[318] = -481.0;
    localB->HoughTransform1_o3[319] = -480.0;
    localB->HoughTransform1_o3[320] = -479.0;
    localB->HoughTransform1_o3[321] = -478.0;
    localB->HoughTransform1_o3[322] = -477.0;
    localB->HoughTransform1_o3[323] = -476.0;
    localB->HoughTransform1_o3[324] = -475.0;
    localB->HoughTransform1_o3[325] = -474.0;
    localB->HoughTransform1_o3[326] = -473.0;
    localB->HoughTransform1_o3[327] = -472.0;
    localB->HoughTransform1_o3[328] = -471.0;
    localB->HoughTransform1_o3[329] = -470.0;
    localB->HoughTransform1_o3[330] = -469.0;
    localB->HoughTransform1_o3[331] = -468.0;
    localB->HoughTransform1_o3[332] = -467.0;
    localB->HoughTransform1_o3[333] = -466.0;
    localB->HoughTransform1_o3[334] = -465.0;
    localB->HoughTransform1_o3[335] = -464.0;
    localB->HoughTransform1_o3[336] = -463.0;
    localB->HoughTransform1_o3[337] = -462.0;
    localB->HoughTransform1_o3[338] = -461.0;
    localB->HoughTransform1_o3[339] = -460.0;
    localB->HoughTransform1_o3[340] = -459.0;
    localB->HoughTransform1_o3[341] = -458.0;
    localB->HoughTransform1_o3[342] = -457.0;
    localB->HoughTransform1_o3[343] = -456.0;
    localB->HoughTransform1_o3[344] = -455.0;
    localB->HoughTransform1_o3[345] = -454.0;
    localB->HoughTransform1_o3[346] = -453.0;
    localB->HoughTransform1_o3[347] = -452.0;
    localB->HoughTransform1_o3[348] = -451.0;
    localB->HoughTransform1_o3[349] = -450.0;
    localB->HoughTransform1_o3[350] = -449.0;
    localB->HoughTransform1_o3[351] = -448.0;
    localB->HoughTransform1_o3[352] = -447.0;
    localB->HoughTransform1_o3[353] = -446.0;
    localB->HoughTransform1_o3[354] = -445.0;
    localB->HoughTransform1_o3[355] = -444.0;
    localB->HoughTransform1_o3[356] = -443.0;
    localB->HoughTransform1_o3[357] = -442.0;
    localB->HoughTransform1_o3[358] = -441.0;
    localB->HoughTransform1_o3[359] = -440.0;
    localB->HoughTransform1_o3[360] = -439.0;
    localB->HoughTransform1_o3[361] = -438.0;
    localB->HoughTransform1_o3[362] = -437.0;
    localB->HoughTransform1_o3[363] = -436.0;
    localB->HoughTransform1_o3[364] = -435.0;
    localB->HoughTransform1_o3[365] = -434.0;
    localB->HoughTransform1_o3[366] = -433.0;
    localB->HoughTransform1_o3[367] = -432.0;
    localB->HoughTransform1_o3[368] = -431.0;
    localB->HoughTransform1_o3[369] = -430.0;
    localB->HoughTransform1_o3[370] = -429.0;
    localB->HoughTransform1_o3[371] = -428.0;
    localB->HoughTransform1_o3[372] = -427.0;
    localB->HoughTransform1_o3[373] = -426.0;
    localB->HoughTransform1_o3[374] = -425.0;
    localB->HoughTransform1_o3[375] = -424.0;
    localB->HoughTransform1_o3[376] = -423.0;
    localB->HoughTransform1_o3[377] = -422.0;
    localB->HoughTransform1_o3[378] = -421.0;
    localB->HoughTransform1_o3[379] = -420.0;
    localB->HoughTransform1_o3[380] = -419.0;
    localB->HoughTransform1_o3[381] = -418.0;
    localB->HoughTransform1_o3[382] = -417.0;
    localB->HoughTransform1_o3[383] = -416.0;
    localB->HoughTransform1_o3[384] = -415.0;
    localB->HoughTransform1_o3[385] = -414.0;
    localB->HoughTransform1_o3[386] = -413.0;
    localB->HoughTransform1_o3[387] = -412.0;
    localB->HoughTransform1_o3[388] = -411.0;
    localB->HoughTransform1_o3[389] = -410.0;
    localB->HoughTransform1_o3[390] = -409.0;
    localB->HoughTransform1_o3[391] = -408.0;
    localB->HoughTransform1_o3[392] = -407.0;
    localB->HoughTransform1_o3[393] = -406.0;
    localB->HoughTransform1_o3[394] = -405.0;
    localB->HoughTransform1_o3[395] = -404.0;
    localB->HoughTransform1_o3[396] = -403.0;
    localB->HoughTransform1_o3[397] = -402.0;
    localB->HoughTransform1_o3[398] = -401.0;
    localB->HoughTransform1_o3[399] = -400.0;
    localB->HoughTransform1_o3[400] = -399.0;
    localB->HoughTransform1_o3[401] = -398.0;
    localB->HoughTransform1_o3[402] = -397.0;
    localB->HoughTransform1_o3[403] = -396.0;
    localB->HoughTransform1_o3[404] = -395.0;
    localB->HoughTransform1_o3[405] = -394.0;
    localB->HoughTransform1_o3[406] = -393.0;
    localB->HoughTransform1_o3[407] = -392.0;
    localB->HoughTransform1_o3[408] = -391.0;
    localB->HoughTransform1_o3[409] = -390.0;
    localB->HoughTransform1_o3[410] = -389.0;
    localB->HoughTransform1_o3[411] = -388.0;
    localB->HoughTransform1_o3[412] = -387.0;
    localB->HoughTransform1_o3[413] = -386.0;
    localB->HoughTransform1_o3[414] = -385.0;
    localB->HoughTransform1_o3[415] = -384.0;
    localB->HoughTransform1_o3[416] = -383.0;
    localB->HoughTransform1_o3[417] = -382.0;
    localB->HoughTransform1_o3[418] = -381.0;
    localB->HoughTransform1_o3[419] = -380.0;
    localB->HoughTransform1_o3[420] = -379.0;
    localB->HoughTransform1_o3[421] = -378.0;
    localB->HoughTransform1_o3[422] = -377.0;
    localB->HoughTransform1_o3[423] = -376.0;
    localB->HoughTransform1_o3[424] = -375.0;
    localB->HoughTransform1_o3[425] = -374.0;
    localB->HoughTransform1_o3[426] = -373.0;
    localB->HoughTransform1_o3[427] = -372.0;
    localB->HoughTransform1_o3[428] = -371.0;
    localB->HoughTransform1_o3[429] = -370.0;
    localB->HoughTransform1_o3[430] = -369.0;
    localB->HoughTransform1_o3[431] = -368.0;
    localB->HoughTransform1_o3[432] = -367.0;
    localB->HoughTransform1_o3[433] = -366.0;
    localB->HoughTransform1_o3[434] = -365.0;
    localB->HoughTransform1_o3[435] = -364.0;
    localB->HoughTransform1_o3[436] = -363.0;
    localB->HoughTransform1_o3[437] = -362.0;
    localB->HoughTransform1_o3[438] = -361.0;
    localB->HoughTransform1_o3[439] = -360.0;
    localB->HoughTransform1_o3[440] = -359.0;
    localB->HoughTransform1_o3[441] = -358.0;
    localB->HoughTransform1_o3[442] = -357.0;
    localB->HoughTransform1_o3[443] = -356.0;
    localB->HoughTransform1_o3[444] = -355.0;
    localB->HoughTransform1_o3[445] = -354.0;
    localB->HoughTransform1_o3[446] = -353.0;
    localB->HoughTransform1_o3[447] = -352.0;
    localB->HoughTransform1_o3[448] = -351.0;
    localB->HoughTransform1_o3[449] = -350.0;
    localB->HoughTransform1_o3[450] = -349.0;
    localB->HoughTransform1_o3[451] = -348.0;
    localB->HoughTransform1_o3[452] = -347.0;
    localB->HoughTransform1_o3[453] = -346.0;
    localB->HoughTransform1_o3[454] = -345.0;
    localB->HoughTransform1_o3[455] = -344.0;
    localB->HoughTransform1_o3[456] = -343.0;
    localB->HoughTransform1_o3[457] = -342.0;
    localB->HoughTransform1_o3[458] = -341.0;
    localB->HoughTransform1_o3[459] = -340.0;
    localB->HoughTransform1_o3[460] = -339.0;
    localB->HoughTransform1_o3[461] = -338.0;
    localB->HoughTransform1_o3[462] = -337.0;
    localB->HoughTransform1_o3[463] = -336.0;
    localB->HoughTransform1_o3[464] = -335.0;
    localB->HoughTransform1_o3[465] = -334.0;
    localB->HoughTransform1_o3[466] = -333.0;
    localB->HoughTransform1_o3[467] = -332.0;
    localB->HoughTransform1_o3[468] = -331.0;
    localB->HoughTransform1_o3[469] = -330.0;
    localB->HoughTransform1_o3[470] = -329.0;
    localB->HoughTransform1_o3[471] = -328.0;
    localB->HoughTransform1_o3[472] = -327.0;
    localB->HoughTransform1_o3[473] = -326.0;
    localB->HoughTransform1_o3[474] = -325.0;
    localB->HoughTransform1_o3[475] = -324.0;
    localB->HoughTransform1_o3[476] = -323.0;
    localB->HoughTransform1_o3[477] = -322.0;
    localB->HoughTransform1_o3[478] = -321.0;
    localB->HoughTransform1_o3[479] = -320.0;
    localB->HoughTransform1_o3[480] = -319.0;
    localB->HoughTransform1_o3[481] = -318.0;
    localB->HoughTransform1_o3[482] = -317.0;
    localB->HoughTransform1_o3[483] = -316.0;
    localB->HoughTransform1_o3[484] = -315.0;
    localB->HoughTransform1_o3[485] = -314.0;
    localB->HoughTransform1_o3[486] = -313.0;
    localB->HoughTransform1_o3[487] = -312.0;
    localB->HoughTransform1_o3[488] = -311.0;
    localB->HoughTransform1_o3[489] = -310.0;
    localB->HoughTransform1_o3[490] = -309.0;
    localB->HoughTransform1_o3[491] = -308.0;
    localB->HoughTransform1_o3[492] = -307.0;
    localB->HoughTransform1_o3[493] = -306.0;
    localB->HoughTransform1_o3[494] = -305.0;
    localB->HoughTransform1_o3[495] = -304.0;
    localB->HoughTransform1_o3[496] = -303.0;
    localB->HoughTransform1_o3[497] = -302.0;
    localB->HoughTransform1_o3[498] = -301.0;
    localB->HoughTransform1_o3[499] = -300.0;
    localB->HoughTransform1_o3[500] = -299.0;
    localB->HoughTransform1_o3[501] = -298.0;
    localB->HoughTransform1_o3[502] = -297.0;
    localB->HoughTransform1_o3[503] = -296.0;
    localB->HoughTransform1_o3[504] = -295.0;
    localB->HoughTransform1_o3[505] = -294.0;
    localB->HoughTransform1_o3[506] = -293.0;
    localB->HoughTransform1_o3[507] = -292.0;
    localB->HoughTransform1_o3[508] = -291.0;
    localB->HoughTransform1_o3[509] = -290.0;
    localB->HoughTransform1_o3[510] = -289.0;
    localB->HoughTransform1_o3[511] = -288.0;
    localB->HoughTransform1_o3[512] = -287.0;
    localB->HoughTransform1_o3[513] = -286.0;
    localB->HoughTransform1_o3[514] = -285.0;
    localB->HoughTransform1_o3[515] = -284.0;
    localB->HoughTransform1_o3[516] = -283.0;
    localB->HoughTransform1_o3[517] = -282.0;
    localB->HoughTransform1_o3[518] = -281.0;
    localB->HoughTransform1_o3[519] = -280.0;
    localB->HoughTransform1_o3[520] = -279.0;
    localB->HoughTransform1_o3[521] = -278.0;
    localB->HoughTransform1_o3[522] = -277.0;
    localB->HoughTransform1_o3[523] = -276.0;
    localB->HoughTransform1_o3[524] = -275.0;
    localB->HoughTransform1_o3[525] = -274.0;
    localB->HoughTransform1_o3[526] = -273.0;
    localB->HoughTransform1_o3[527] = -272.0;
    localB->HoughTransform1_o3[528] = -271.0;
    localB->HoughTransform1_o3[529] = -270.0;
    localB->HoughTransform1_o3[530] = -269.0;
    localB->HoughTransform1_o3[531] = -268.0;
    localB->HoughTransform1_o3[532] = -267.0;
    localB->HoughTransform1_o3[533] = -266.0;
    localB->HoughTransform1_o3[534] = -265.0;
    localB->HoughTransform1_o3[535] = -264.0;
    localB->HoughTransform1_o3[536] = -263.0;
    localB->HoughTransform1_o3[537] = -262.0;
    localB->HoughTransform1_o3[538] = -261.0;
    localB->HoughTransform1_o3[539] = -260.0;
    localB->HoughTransform1_o3[540] = -259.0;
    localB->HoughTransform1_o3[541] = -258.0;
    localB->HoughTransform1_o3[542] = -257.0;
    localB->HoughTransform1_o3[543] = -256.0;
    localB->HoughTransform1_o3[544] = -255.0;
    localB->HoughTransform1_o3[545] = -254.0;
    localB->HoughTransform1_o3[546] = -253.0;
    localB->HoughTransform1_o3[547] = -252.0;
    localB->HoughTransform1_o3[548] = -251.0;
    localB->HoughTransform1_o3[549] = -250.0;
    localB->HoughTransform1_o3[550] = -249.0;
    localB->HoughTransform1_o3[551] = -248.0;
    localB->HoughTransform1_o3[552] = -247.0;
    localB->HoughTransform1_o3[553] = -246.0;
    localB->HoughTransform1_o3[554] = -245.0;
    localB->HoughTransform1_o3[555] = -244.0;
    localB->HoughTransform1_o3[556] = -243.0;
    localB->HoughTransform1_o3[557] = -242.0;
    localB->HoughTransform1_o3[558] = -241.0;
    localB->HoughTransform1_o3[559] = -240.0;
    localB->HoughTransform1_o3[560] = -239.0;
    localB->HoughTransform1_o3[561] = -238.0;
    localB->HoughTransform1_o3[562] = -237.0;
    localB->HoughTransform1_o3[563] = -236.0;
    localB->HoughTransform1_o3[564] = -235.0;
    localB->HoughTransform1_o3[565] = -234.0;
    localB->HoughTransform1_o3[566] = -233.0;
    localB->HoughTransform1_o3[567] = -232.0;
    localB->HoughTransform1_o3[568] = -231.0;
    localB->HoughTransform1_o3[569] = -230.0;
    localB->HoughTransform1_o3[570] = -229.0;
    localB->HoughTransform1_o3[571] = -228.0;
    localB->HoughTransform1_o3[572] = -227.0;
    localB->HoughTransform1_o3[573] = -226.0;
    localB->HoughTransform1_o3[574] = -225.0;
    localB->HoughTransform1_o3[575] = -224.0;
    localB->HoughTransform1_o3[576] = -223.0;
    localB->HoughTransform1_o3[577] = -222.0;
    localB->HoughTransform1_o3[578] = -221.0;
    localB->HoughTransform1_o3[579] = -220.0;
    localB->HoughTransform1_o3[580] = -219.0;
    localB->HoughTransform1_o3[581] = -218.0;
    localB->HoughTransform1_o3[582] = -217.0;
    localB->HoughTransform1_o3[583] = -216.0;
    localB->HoughTransform1_o3[584] = -215.0;
    localB->HoughTransform1_o3[585] = -214.0;
    localB->HoughTransform1_o3[586] = -213.0;
    localB->HoughTransform1_o3[587] = -212.0;
    localB->HoughTransform1_o3[588] = -211.0;
    localB->HoughTransform1_o3[589] = -210.0;
    localB->HoughTransform1_o3[590] = -209.0;
    localB->HoughTransform1_o3[591] = -208.0;
    localB->HoughTransform1_o3[592] = -207.0;
    localB->HoughTransform1_o3[593] = -206.0;
    localB->HoughTransform1_o3[594] = -205.0;
    localB->HoughTransform1_o3[595] = -204.0;
    localB->HoughTransform1_o3[596] = -203.0;
    localB->HoughTransform1_o3[597] = -202.0;
    localB->HoughTransform1_o3[598] = -201.0;
    localB->HoughTransform1_o3[599] = -200.0;
    localB->HoughTransform1_o3[600] = -199.0;
    localB->HoughTransform1_o3[601] = -198.0;
    localB->HoughTransform1_o3[602] = -197.0;
    localB->HoughTransform1_o3[603] = -196.0;
    localB->HoughTransform1_o3[604] = -195.0;
    localB->HoughTransform1_o3[605] = -194.0;
    localB->HoughTransform1_o3[606] = -193.0;
    localB->HoughTransform1_o3[607] = -192.0;
    localB->HoughTransform1_o3[608] = -191.0;
    localB->HoughTransform1_o3[609] = -190.0;
    localB->HoughTransform1_o3[610] = -189.0;
    localB->HoughTransform1_o3[611] = -188.0;
    localB->HoughTransform1_o3[612] = -187.0;
    localB->HoughTransform1_o3[613] = -186.0;
    localB->HoughTransform1_o3[614] = -185.0;
    localB->HoughTransform1_o3[615] = -184.0;
    localB->HoughTransform1_o3[616] = -183.0;
    localB->HoughTransform1_o3[617] = -182.0;
    localB->HoughTransform1_o3[618] = -181.0;
    localB->HoughTransform1_o3[619] = -180.0;
    localB->HoughTransform1_o3[620] = -179.0;
    localB->HoughTransform1_o3[621] = -178.0;
    localB->HoughTransform1_o3[622] = -177.0;
    localB->HoughTransform1_o3[623] = -176.0;
    localB->HoughTransform1_o3[624] = -175.0;
    localB->HoughTransform1_o3[625] = -174.0;
    localB->HoughTransform1_o3[626] = -173.0;
    localB->HoughTransform1_o3[627] = -172.0;
    localB->HoughTransform1_o3[628] = -171.0;
    localB->HoughTransform1_o3[629] = -170.0;
    localB->HoughTransform1_o3[630] = -169.0;
    localB->HoughTransform1_o3[631] = -168.0;
    localB->HoughTransform1_o3[632] = -167.0;
    localB->HoughTransform1_o3[633] = -166.0;
    localB->HoughTransform1_o3[634] = -165.0;
    localB->HoughTransform1_o3[635] = -164.0;
    localB->HoughTransform1_o3[636] = -163.0;
    localB->HoughTransform1_o3[637] = -162.0;
    localB->HoughTransform1_o3[638] = -161.0;
    localB->HoughTransform1_o3[639] = -160.0;
    localB->HoughTransform1_o3[640] = -159.0;
    localB->HoughTransform1_o3[641] = -158.0;
    localB->HoughTransform1_o3[642] = -157.0;
    localB->HoughTransform1_o3[643] = -156.0;
    localB->HoughTransform1_o3[644] = -155.0;
    localB->HoughTransform1_o3[645] = -154.0;
    localB->HoughTransform1_o3[646] = -153.0;
    localB->HoughTransform1_o3[647] = -152.0;
    localB->HoughTransform1_o3[648] = -151.0;
    localB->HoughTransform1_o3[649] = -150.0;
    localB->HoughTransform1_o3[650] = -149.0;
    localB->HoughTransform1_o3[651] = -148.0;
    localB->HoughTransform1_o3[652] = -147.0;
    localB->HoughTransform1_o3[653] = -146.0;
    localB->HoughTransform1_o3[654] = -145.0;
    localB->HoughTransform1_o3[655] = -144.0;
    localB->HoughTransform1_o3[656] = -143.0;
    localB->HoughTransform1_o3[657] = -142.0;
    localB->HoughTransform1_o3[658] = -141.0;
    localB->HoughTransform1_o3[659] = -140.0;
    localB->HoughTransform1_o3[660] = -139.0;
    localB->HoughTransform1_o3[661] = -138.0;
    localB->HoughTransform1_o3[662] = -137.0;
    localB->HoughTransform1_o3[663] = -136.0;
    localB->HoughTransform1_o3[664] = -135.0;
    localB->HoughTransform1_o3[665] = -134.0;
    localB->HoughTransform1_o3[666] = -133.0;
    localB->HoughTransform1_o3[667] = -132.0;
    localB->HoughTransform1_o3[668] = -131.0;
    localB->HoughTransform1_o3[669] = -130.0;
    localB->HoughTransform1_o3[670] = -129.0;
    localB->HoughTransform1_o3[671] = -128.0;
    localB->HoughTransform1_o3[672] = -127.0;
    localB->HoughTransform1_o3[673] = -126.0;
    localB->HoughTransform1_o3[674] = -125.0;
    localB->HoughTransform1_o3[675] = -124.0;
    localB->HoughTransform1_o3[676] = -123.0;
    localB->HoughTransform1_o3[677] = -122.0;
    localB->HoughTransform1_o3[678] = -121.0;
    localB->HoughTransform1_o3[679] = -120.0;
    localB->HoughTransform1_o3[680] = -119.0;
    localB->HoughTransform1_o3[681] = -118.0;
    localB->HoughTransform1_o3[682] = -117.0;
    localB->HoughTransform1_o3[683] = -116.0;
    localB->HoughTransform1_o3[684] = -115.0;
    localB->HoughTransform1_o3[685] = -114.0;
    localB->HoughTransform1_o3[686] = -113.0;
    localB->HoughTransform1_o3[687] = -112.0;
    localB->HoughTransform1_o3[688] = -111.0;
    localB->HoughTransform1_o3[689] = -110.0;
    localB->HoughTransform1_o3[690] = -109.0;
    localB->HoughTransform1_o3[691] = -108.0;
    localB->HoughTransform1_o3[692] = -107.0;
    localB->HoughTransform1_o3[693] = -106.0;
    localB->HoughTransform1_o3[694] = -105.0;
    localB->HoughTransform1_o3[695] = -104.0;
    localB->HoughTransform1_o3[696] = -103.0;
    localB->HoughTransform1_o3[697] = -102.0;
    localB->HoughTransform1_o3[698] = -101.0;
    localB->HoughTransform1_o3[699] = -100.0;
    localB->HoughTransform1_o3[700] = -99.0;
    localB->HoughTransform1_o3[701] = -98.0;
    localB->HoughTransform1_o3[702] = -97.0;
    localB->HoughTransform1_o3[703] = -96.0;
    localB->HoughTransform1_o3[704] = -95.0;
    localB->HoughTransform1_o3[705] = -94.0;
    localB->HoughTransform1_o3[706] = -93.0;
    localB->HoughTransform1_o3[707] = -92.0;
    localB->HoughTransform1_o3[708] = -91.0;
    localB->HoughTransform1_o3[709] = -90.0;
    localB->HoughTransform1_o3[710] = -89.0;
    localB->HoughTransform1_o3[711] = -88.0;
    localB->HoughTransform1_o3[712] = -87.0;
    localB->HoughTransform1_o3[713] = -86.0;
    localB->HoughTransform1_o3[714] = -85.0;
    localB->HoughTransform1_o3[715] = -84.0;
    localB->HoughTransform1_o3[716] = -83.0;
    localB->HoughTransform1_o3[717] = -82.0;
    localB->HoughTransform1_o3[718] = -81.0;
    localB->HoughTransform1_o3[719] = -80.0;
    localB->HoughTransform1_o3[720] = -79.0;
    localB->HoughTransform1_o3[721] = -78.0;
    localB->HoughTransform1_o3[722] = -77.0;
    localB->HoughTransform1_o3[723] = -76.0;
    localB->HoughTransform1_o3[724] = -75.0;
    localB->HoughTransform1_o3[725] = -74.0;
    localB->HoughTransform1_o3[726] = -73.0;
    localB->HoughTransform1_o3[727] = -72.0;
    localB->HoughTransform1_o3[728] = -71.0;
    localB->HoughTransform1_o3[729] = -70.0;
    localB->HoughTransform1_o3[730] = -69.0;
    localB->HoughTransform1_o3[731] = -68.0;
    localB->HoughTransform1_o3[732] = -67.0;
    localB->HoughTransform1_o3[733] = -66.0;
    localB->HoughTransform1_o3[734] = -65.0;
    localB->HoughTransform1_o3[735] = -64.0;
    localB->HoughTransform1_o3[736] = -63.0;
    localB->HoughTransform1_o3[737] = -62.0;
    localB->HoughTransform1_o3[738] = -61.0;
    localB->HoughTransform1_o3[739] = -60.0;
    localB->HoughTransform1_o3[740] = -59.0;
    localB->HoughTransform1_o3[741] = -58.0;
    localB->HoughTransform1_o3[742] = -57.0;
    localB->HoughTransform1_o3[743] = -56.0;
    localB->HoughTransform1_o3[744] = -55.0;
    localB->HoughTransform1_o3[745] = -54.0;
    localB->HoughTransform1_o3[746] = -53.0;
    localB->HoughTransform1_o3[747] = -52.0;
    localB->HoughTransform1_o3[748] = -51.0;
    localB->HoughTransform1_o3[749] = -50.0;
    localB->HoughTransform1_o3[750] = -49.0;
    localB->HoughTransform1_o3[751] = -48.0;
    localB->HoughTransform1_o3[752] = -47.0;
    localB->HoughTransform1_o3[753] = -46.0;
    localB->HoughTransform1_o3[754] = -45.0;
    localB->HoughTransform1_o3[755] = -44.0;
    localB->HoughTransform1_o3[756] = -43.0;
    localB->HoughTransform1_o3[757] = -42.0;
    localB->HoughTransform1_o3[758] = -41.0;
    localB->HoughTransform1_o3[759] = -40.0;
    localB->HoughTransform1_o3[760] = -39.0;
    localB->HoughTransform1_o3[761] = -38.0;
    localB->HoughTransform1_o3[762] = -37.0;
    localB->HoughTransform1_o3[763] = -36.0;
    localB->HoughTransform1_o3[764] = -35.0;
    localB->HoughTransform1_o3[765] = -34.0;
    localB->HoughTransform1_o3[766] = -33.0;
    localB->HoughTransform1_o3[767] = -32.0;
    localB->HoughTransform1_o3[768] = -31.0;
    localB->HoughTransform1_o3[769] = -30.0;
    localB->HoughTransform1_o3[770] = -29.0;
    localB->HoughTransform1_o3[771] = -28.0;
    localB->HoughTransform1_o3[772] = -27.0;
    localB->HoughTransform1_o3[773] = -26.0;
    localB->HoughTransform1_o3[774] = -25.0;
    localB->HoughTransform1_o3[775] = -24.0;
    localB->HoughTransform1_o3[776] = -23.0;
    localB->HoughTransform1_o3[777] = -22.0;
    localB->HoughTransform1_o3[778] = -21.0;
    localB->HoughTransform1_o3[779] = -20.0;
    localB->HoughTransform1_o3[780] = -19.0;
    localB->HoughTransform1_o3[781] = -18.0;
    localB->HoughTransform1_o3[782] = -17.0;
    localB->HoughTransform1_o3[783] = -16.0;
    localB->HoughTransform1_o3[784] = -15.0;
    localB->HoughTransform1_o3[785] = -14.0;
    localB->HoughTransform1_o3[786] = -13.0;
    localB->HoughTransform1_o3[787] = -12.0;
    localB->HoughTransform1_o3[788] = -11.0;
    localB->HoughTransform1_o3[789] = -10.0;
    localB->HoughTransform1_o3[790] = -9.0;
    localB->HoughTransform1_o3[791] = -8.0;
    localB->HoughTransform1_o3[792] = -7.0;
    localB->HoughTransform1_o3[793] = -6.0;
    localB->HoughTransform1_o3[794] = -5.0;
    localB->HoughTransform1_o3[795] = -4.0;
    localB->HoughTransform1_o3[796] = -3.0;
    localB->HoughTransform1_o3[797] = -2.0;
    localB->HoughTransform1_o3[798] = -1.0;
    localB->HoughTransform1_o3[799] = 0.0;
    localB->HoughTransform1_o3[800] = 1.0;
    localB->HoughTransform1_o3[801] = 2.0;
    localB->HoughTransform1_o3[802] = 3.0;
    localB->HoughTransform1_o3[803] = 4.0;
    localB->HoughTransform1_o3[804] = 5.0;
    localB->HoughTransform1_o3[805] = 6.0;
    localB->HoughTransform1_o3[806] = 7.0;
    localB->HoughTransform1_o3[807] = 8.0;
    localB->HoughTransform1_o3[808] = 9.0;
    localB->HoughTransform1_o3[809] = 10.0;
    localB->HoughTransform1_o3[810] = 11.0;
    localB->HoughTransform1_o3[811] = 12.0;
    localB->HoughTransform1_o3[812] = 13.0;
    localB->HoughTransform1_o3[813] = 14.0;
    localB->HoughTransform1_o3[814] = 15.0;
    localB->HoughTransform1_o3[815] = 16.0;
    localB->HoughTransform1_o3[816] = 17.0;
    localB->HoughTransform1_o3[817] = 18.0;
    localB->HoughTransform1_o3[818] = 19.0;
    localB->HoughTransform1_o3[819] = 20.0;
    localB->HoughTransform1_o3[820] = 21.0;
    localB->HoughTransform1_o3[821] = 22.0;
    localB->HoughTransform1_o3[822] = 23.0;
    localB->HoughTransform1_o3[823] = 24.0;
    localB->HoughTransform1_o3[824] = 25.0;
    localB->HoughTransform1_o3[825] = 26.0;
    localB->HoughTransform1_o3[826] = 27.0;
    localB->HoughTransform1_o3[827] = 28.0;
    localB->HoughTransform1_o3[828] = 29.0;
    localB->HoughTransform1_o3[829] = 30.0;
    localB->HoughTransform1_o3[830] = 31.0;
    localB->HoughTransform1_o3[831] = 32.0;
    localB->HoughTransform1_o3[832] = 33.0;
    localB->HoughTransform1_o3[833] = 34.0;
    localB->HoughTransform1_o3[834] = 35.0;
    localB->HoughTransform1_o3[835] = 36.0;
    localB->HoughTransform1_o3[836] = 37.0;
    localB->HoughTransform1_o3[837] = 38.0;
    localB->HoughTransform1_o3[838] = 39.0;
    localB->HoughTransform1_o3[839] = 40.0;
    localB->HoughTransform1_o3[840] = 41.0;
    localB->HoughTransform1_o3[841] = 42.0;
    localB->HoughTransform1_o3[842] = 43.0;
    localB->HoughTransform1_o3[843] = 44.0;
    localB->HoughTransform1_o3[844] = 45.0;
    localB->HoughTransform1_o3[845] = 46.0;
    localB->HoughTransform1_o3[846] = 47.0;
    localB->HoughTransform1_o3[847] = 48.0;
    localB->HoughTransform1_o3[848] = 49.0;
    localB->HoughTransform1_o3[849] = 50.0;
    localB->HoughTransform1_o3[850] = 51.0;
    localB->HoughTransform1_o3[851] = 52.0;
    localB->HoughTransform1_o3[852] = 53.0;
    localB->HoughTransform1_o3[853] = 54.0;
    localB->HoughTransform1_o3[854] = 55.0;
    localB->HoughTransform1_o3[855] = 56.0;
    localB->HoughTransform1_o3[856] = 57.0;
    localB->HoughTransform1_o3[857] = 58.0;
    localB->HoughTransform1_o3[858] = 59.0;
    localB->HoughTransform1_o3[859] = 60.0;
    localB->HoughTransform1_o3[860] = 61.0;
    localB->HoughTransform1_o3[861] = 62.0;
    localB->HoughTransform1_o3[862] = 63.0;
    localB->HoughTransform1_o3[863] = 64.0;
    localB->HoughTransform1_o3[864] = 65.0;
    localB->HoughTransform1_o3[865] = 66.0;
    localB->HoughTransform1_o3[866] = 67.0;
    localB->HoughTransform1_o3[867] = 68.0;
    localB->HoughTransform1_o3[868] = 69.0;
    localB->HoughTransform1_o3[869] = 70.0;
    localB->HoughTransform1_o3[870] = 71.0;
    localB->HoughTransform1_o3[871] = 72.0;
    localB->HoughTransform1_o3[872] = 73.0;
    localB->HoughTransform1_o3[873] = 74.0;
    localB->HoughTransform1_o3[874] = 75.0;
    localB->HoughTransform1_o3[875] = 76.0;
    localB->HoughTransform1_o3[876] = 77.0;
    localB->HoughTransform1_o3[877] = 78.0;
    localB->HoughTransform1_o3[878] = 79.0;
    localB->HoughTransform1_o3[879] = 80.0;
    localB->HoughTransform1_o3[880] = 81.0;
    localB->HoughTransform1_o3[881] = 82.0;
    localB->HoughTransform1_o3[882] = 83.0;
    localB->HoughTransform1_o3[883] = 84.0;
    localB->HoughTransform1_o3[884] = 85.0;
    localB->HoughTransform1_o3[885] = 86.0;
    localB->HoughTransform1_o3[886] = 87.0;
    localB->HoughTransform1_o3[887] = 88.0;
    localB->HoughTransform1_o3[888] = 89.0;
    localB->HoughTransform1_o3[889] = 90.0;
    localB->HoughTransform1_o3[890] = 91.0;
    localB->HoughTransform1_o3[891] = 92.0;
    localB->HoughTransform1_o3[892] = 93.0;
    localB->HoughTransform1_o3[893] = 94.0;
    localB->HoughTransform1_o3[894] = 95.0;
    localB->HoughTransform1_o3[895] = 96.0;
    localB->HoughTransform1_o3[896] = 97.0;
    localB->HoughTransform1_o3[897] = 98.0;
    localB->HoughTransform1_o3[898] = 99.0;
    localB->HoughTransform1_o3[899] = 100.0;
    localB->HoughTransform1_o3[900] = 101.0;
    localB->HoughTransform1_o3[901] = 102.0;
    localB->HoughTransform1_o3[902] = 103.0;
    localB->HoughTransform1_o3[903] = 104.0;
    localB->HoughTransform1_o3[904] = 105.0;
    localB->HoughTransform1_o3[905] = 106.0;
    localB->HoughTransform1_o3[906] = 107.0;
    localB->HoughTransform1_o3[907] = 108.0;
    localB->HoughTransform1_o3[908] = 109.0;
    localB->HoughTransform1_o3[909] = 110.0;
    localB->HoughTransform1_o3[910] = 111.0;
    localB->HoughTransform1_o3[911] = 112.0;
    localB->HoughTransform1_o3[912] = 113.0;
    localB->HoughTransform1_o3[913] = 114.0;
    localB->HoughTransform1_o3[914] = 115.0;
    localB->HoughTransform1_o3[915] = 116.0;
    localB->HoughTransform1_o3[916] = 117.0;
    localB->HoughTransform1_o3[917] = 118.0;
    localB->HoughTransform1_o3[918] = 119.0;
    localB->HoughTransform1_o3[919] = 120.0;
    localB->HoughTransform1_o3[920] = 121.0;
    localB->HoughTransform1_o3[921] = 122.0;
    localB->HoughTransform1_o3[922] = 123.0;
    localB->HoughTransform1_o3[923] = 124.0;
    localB->HoughTransform1_o3[924] = 125.0;
    localB->HoughTransform1_o3[925] = 126.0;
    localB->HoughTransform1_o3[926] = 127.0;
    localB->HoughTransform1_o3[927] = 128.0;
    localB->HoughTransform1_o3[928] = 129.0;
    localB->HoughTransform1_o3[929] = 130.0;
    localB->HoughTransform1_o3[930] = 131.0;
    localB->HoughTransform1_o3[931] = 132.0;
    localB->HoughTransform1_o3[932] = 133.0;
    localB->HoughTransform1_o3[933] = 134.0;
    localB->HoughTransform1_o3[934] = 135.0;
    localB->HoughTransform1_o3[935] = 136.0;
    localB->HoughTransform1_o3[936] = 137.0;
    localB->HoughTransform1_o3[937] = 138.0;
    localB->HoughTransform1_o3[938] = 139.0;
    localB->HoughTransform1_o3[939] = 140.0;
    localB->HoughTransform1_o3[940] = 141.0;
    localB->HoughTransform1_o3[941] = 142.0;
    localB->HoughTransform1_o3[942] = 143.0;
    localB->HoughTransform1_o3[943] = 144.0;
    localB->HoughTransform1_o3[944] = 145.0;
    localB->HoughTransform1_o3[945] = 146.0;
    localB->HoughTransform1_o3[946] = 147.0;
    localB->HoughTransform1_o3[947] = 148.0;
    localB->HoughTransform1_o3[948] = 149.0;
    localB->HoughTransform1_o3[949] = 150.0;
    localB->HoughTransform1_o3[950] = 151.0;
    localB->HoughTransform1_o3[951] = 152.0;
    localB->HoughTransform1_o3[952] = 153.0;
    localB->HoughTransform1_o3[953] = 154.0;
    localB->HoughTransform1_o3[954] = 155.0;
    localB->HoughTransform1_o3[955] = 156.0;
    localB->HoughTransform1_o3[956] = 157.0;
    localB->HoughTransform1_o3[957] = 158.0;
    localB->HoughTransform1_o3[958] = 159.0;
    localB->HoughTransform1_o3[959] = 160.0;
    localB->HoughTransform1_o3[960] = 161.0;
    localB->HoughTransform1_o3[961] = 162.0;
    localB->HoughTransform1_o3[962] = 163.0;
    localB->HoughTransform1_o3[963] = 164.0;
    localB->HoughTransform1_o3[964] = 165.0;
    localB->HoughTransform1_o3[965] = 166.0;
    localB->HoughTransform1_o3[966] = 167.0;
    localB->HoughTransform1_o3[967] = 168.0;
    localB->HoughTransform1_o3[968] = 169.0;
    localB->HoughTransform1_o3[969] = 170.0;
    localB->HoughTransform1_o3[970] = 171.0;
    localB->HoughTransform1_o3[971] = 172.0;
    localB->HoughTransform1_o3[972] = 173.0;
    localB->HoughTransform1_o3[973] = 174.0;
    localB->HoughTransform1_o3[974] = 175.0;
    localB->HoughTransform1_o3[975] = 176.0;
    localB->HoughTransform1_o3[976] = 177.0;
    localB->HoughTransform1_o3[977] = 178.0;
    localB->HoughTransform1_o3[978] = 179.0;
    localB->HoughTransform1_o3[979] = 180.0;
    localB->HoughTransform1_o3[980] = 181.0;
    localB->HoughTransform1_o3[981] = 182.0;
    localB->HoughTransform1_o3[982] = 183.0;
    localB->HoughTransform1_o3[983] = 184.0;
    localB->HoughTransform1_o3[984] = 185.0;
    localB->HoughTransform1_o3[985] = 186.0;
    localB->HoughTransform1_o3[986] = 187.0;
    localB->HoughTransform1_o3[987] = 188.0;
    localB->HoughTransform1_o3[988] = 189.0;
    localB->HoughTransform1_o3[989] = 190.0;
    localB->HoughTransform1_o3[990] = 191.0;
    localB->HoughTransform1_o3[991] = 192.0;
    localB->HoughTransform1_o3[992] = 193.0;
    localB->HoughTransform1_o3[993] = 194.0;
    localB->HoughTransform1_o3[994] = 195.0;
    localB->HoughTransform1_o3[995] = 196.0;
    localB->HoughTransform1_o3[996] = 197.0;
    localB->HoughTransform1_o3[997] = 198.0;
    localB->HoughTransform1_o3[998] = 199.0;
    localB->HoughTransform1_o3[999] = 200.0;
    localB->HoughTransform1_o3[1000] = 201.0;
    localB->HoughTransform1_o3[1001] = 202.0;
    localB->HoughTransform1_o3[1002] = 203.0;
    localB->HoughTransform1_o3[1003] = 204.0;
    localB->HoughTransform1_o3[1004] = 205.0;
    localB->HoughTransform1_o3[1005] = 206.0;
    localB->HoughTransform1_o3[1006] = 207.0;
    localB->HoughTransform1_o3[1007] = 208.0;
    localB->HoughTransform1_o3[1008] = 209.0;
    localB->HoughTransform1_o3[1009] = 210.0;
    localB->HoughTransform1_o3[1010] = 211.0;
    localB->HoughTransform1_o3[1011] = 212.0;
    localB->HoughTransform1_o3[1012] = 213.0;
    localB->HoughTransform1_o3[1013] = 214.0;
    localB->HoughTransform1_o3[1014] = 215.0;
    localB->HoughTransform1_o3[1015] = 216.0;
    localB->HoughTransform1_o3[1016] = 217.0;
    localB->HoughTransform1_o3[1017] = 218.0;
    localB->HoughTransform1_o3[1018] = 219.0;
    localB->HoughTransform1_o3[1019] = 220.0;
    localB->HoughTransform1_o3[1020] = 221.0;
    localB->HoughTransform1_o3[1021] = 222.0;
    localB->HoughTransform1_o3[1022] = 223.0;
    localB->HoughTransform1_o3[1023] = 224.0;
    localB->HoughTransform1_o3[1024] = 225.0;
    localB->HoughTransform1_o3[1025] = 226.0;
    localB->HoughTransform1_o3[1026] = 227.0;
    localB->HoughTransform1_o3[1027] = 228.0;
    localB->HoughTransform1_o3[1028] = 229.0;
    localB->HoughTransform1_o3[1029] = 230.0;
    localB->HoughTransform1_o3[1030] = 231.0;
    localB->HoughTransform1_o3[1031] = 232.0;
    localB->HoughTransform1_o3[1032] = 233.0;
    localB->HoughTransform1_o3[1033] = 234.0;
    localB->HoughTransform1_o3[1034] = 235.0;
    localB->HoughTransform1_o3[1035] = 236.0;
    localB->HoughTransform1_o3[1036] = 237.0;
    localB->HoughTransform1_o3[1037] = 238.0;
    localB->HoughTransform1_o3[1038] = 239.0;
    localB->HoughTransform1_o3[1039] = 240.0;
    localB->HoughTransform1_o3[1040] = 241.0;
    localB->HoughTransform1_o3[1041] = 242.0;
    localB->HoughTransform1_o3[1042] = 243.0;
    localB->HoughTransform1_o3[1043] = 244.0;
    localB->HoughTransform1_o3[1044] = 245.0;
    localB->HoughTransform1_o3[1045] = 246.0;
    localB->HoughTransform1_o3[1046] = 247.0;
    localB->HoughTransform1_o3[1047] = 248.0;
    localB->HoughTransform1_o3[1048] = 249.0;
    localB->HoughTransform1_o3[1049] = 250.0;
    localB->HoughTransform1_o3[1050] = 251.0;
    localB->HoughTransform1_o3[1051] = 252.0;
    localB->HoughTransform1_o3[1052] = 253.0;
    localB->HoughTransform1_o3[1053] = 254.0;
    localB->HoughTransform1_o3[1054] = 255.0;
    localB->HoughTransform1_o3[1055] = 256.0;
    localB->HoughTransform1_o3[1056] = 257.0;
    localB->HoughTransform1_o3[1057] = 258.0;
    localB->HoughTransform1_o3[1058] = 259.0;
    localB->HoughTransform1_o3[1059] = 260.0;
    localB->HoughTransform1_o3[1060] = 261.0;
    localB->HoughTransform1_o3[1061] = 262.0;
    localB->HoughTransform1_o3[1062] = 263.0;
    localB->HoughTransform1_o3[1063] = 264.0;
    localB->HoughTransform1_o3[1064] = 265.0;
    localB->HoughTransform1_o3[1065] = 266.0;
    localB->HoughTransform1_o3[1066] = 267.0;
    localB->HoughTransform1_o3[1067] = 268.0;
    localB->HoughTransform1_o3[1068] = 269.0;
    localB->HoughTransform1_o3[1069] = 270.0;
    localB->HoughTransform1_o3[1070] = 271.0;
    localB->HoughTransform1_o3[1071] = 272.0;
    localB->HoughTransform1_o3[1072] = 273.0;
    localB->HoughTransform1_o3[1073] = 274.0;
    localB->HoughTransform1_o3[1074] = 275.0;
    localB->HoughTransform1_o3[1075] = 276.0;
    localB->HoughTransform1_o3[1076] = 277.0;
    localB->HoughTransform1_o3[1077] = 278.0;
    localB->HoughTransform1_o3[1078] = 279.0;
    localB->HoughTransform1_o3[1079] = 280.0;
    localB->HoughTransform1_o3[1080] = 281.0;
    localB->HoughTransform1_o3[1081] = 282.0;
    localB->HoughTransform1_o3[1082] = 283.0;
    localB->HoughTransform1_o3[1083] = 284.0;
    localB->HoughTransform1_o3[1084] = 285.0;
    localB->HoughTransform1_o3[1085] = 286.0;
    localB->HoughTransform1_o3[1086] = 287.0;
    localB->HoughTransform1_o3[1087] = 288.0;
    localB->HoughTransform1_o3[1088] = 289.0;
    localB->HoughTransform1_o3[1089] = 290.0;
    localB->HoughTransform1_o3[1090] = 291.0;
    localB->HoughTransform1_o3[1091] = 292.0;
    localB->HoughTransform1_o3[1092] = 293.0;
    localB->HoughTransform1_o3[1093] = 294.0;
    localB->HoughTransform1_o3[1094] = 295.0;
    localB->HoughTransform1_o3[1095] = 296.0;
    localB->HoughTransform1_o3[1096] = 297.0;
    localB->HoughTransform1_o3[1097] = 298.0;
    localB->HoughTransform1_o3[1098] = 299.0;
    localB->HoughTransform1_o3[1099] = 300.0;
    localB->HoughTransform1_o3[1100] = 301.0;
    localB->HoughTransform1_o3[1101] = 302.0;
    localB->HoughTransform1_o3[1102] = 303.0;
    localB->HoughTransform1_o3[1103] = 304.0;
    localB->HoughTransform1_o3[1104] = 305.0;
    localB->HoughTransform1_o3[1105] = 306.0;
    localB->HoughTransform1_o3[1106] = 307.0;
    localB->HoughTransform1_o3[1107] = 308.0;
    localB->HoughTransform1_o3[1108] = 309.0;
    localB->HoughTransform1_o3[1109] = 310.0;
    localB->HoughTransform1_o3[1110] = 311.0;
    localB->HoughTransform1_o3[1111] = 312.0;
    localB->HoughTransform1_o3[1112] = 313.0;
    localB->HoughTransform1_o3[1113] = 314.0;
    localB->HoughTransform1_o3[1114] = 315.0;
    localB->HoughTransform1_o3[1115] = 316.0;
    localB->HoughTransform1_o3[1116] = 317.0;
    localB->HoughTransform1_o3[1117] = 318.0;
    localB->HoughTransform1_o3[1118] = 319.0;
    localB->HoughTransform1_o3[1119] = 320.0;
    localB->HoughTransform1_o3[1120] = 321.0;
    localB->HoughTransform1_o3[1121] = 322.0;
    localB->HoughTransform1_o3[1122] = 323.0;
    localB->HoughTransform1_o3[1123] = 324.0;
    localB->HoughTransform1_o3[1124] = 325.0;
    localB->HoughTransform1_o3[1125] = 326.0;
    localB->HoughTransform1_o3[1126] = 327.0;
    localB->HoughTransform1_o3[1127] = 328.0;
    localB->HoughTransform1_o3[1128] = 329.0;
    localB->HoughTransform1_o3[1129] = 330.0;
    localB->HoughTransform1_o3[1130] = 331.0;
    localB->HoughTransform1_o3[1131] = 332.0;
    localB->HoughTransform1_o3[1132] = 333.0;
    localB->HoughTransform1_o3[1133] = 334.0;
    localB->HoughTransform1_o3[1134] = 335.0;
    localB->HoughTransform1_o3[1135] = 336.0;
    localB->HoughTransform1_o3[1136] = 337.0;
    localB->HoughTransform1_o3[1137] = 338.0;
    localB->HoughTransform1_o3[1138] = 339.0;
    localB->HoughTransform1_o3[1139] = 340.0;
    localB->HoughTransform1_o3[1140] = 341.0;
    localB->HoughTransform1_o3[1141] = 342.0;
    localB->HoughTransform1_o3[1142] = 343.0;
    localB->HoughTransform1_o3[1143] = 344.0;
    localB->HoughTransform1_o3[1144] = 345.0;
    localB->HoughTransform1_o3[1145] = 346.0;
    localB->HoughTransform1_o3[1146] = 347.0;
    localB->HoughTransform1_o3[1147] = 348.0;
    localB->HoughTransform1_o3[1148] = 349.0;
    localB->HoughTransform1_o3[1149] = 350.0;
    localB->HoughTransform1_o3[1150] = 351.0;
    localB->HoughTransform1_o3[1151] = 352.0;
    localB->HoughTransform1_o3[1152] = 353.0;
    localB->HoughTransform1_o3[1153] = 354.0;
    localB->HoughTransform1_o3[1154] = 355.0;
    localB->HoughTransform1_o3[1155] = 356.0;
    localB->HoughTransform1_o3[1156] = 357.0;
    localB->HoughTransform1_o3[1157] = 358.0;
    localB->HoughTransform1_o3[1158] = 359.0;
    localB->HoughTransform1_o3[1159] = 360.0;
    localB->HoughTransform1_o3[1160] = 361.0;
    localB->HoughTransform1_o3[1161] = 362.0;
    localB->HoughTransform1_o3[1162] = 363.0;
    localB->HoughTransform1_o3[1163] = 364.0;
    localB->HoughTransform1_o3[1164] = 365.0;
    localB->HoughTransform1_o3[1165] = 366.0;
    localB->HoughTransform1_o3[1166] = 367.0;
    localB->HoughTransform1_o3[1167] = 368.0;
    localB->HoughTransform1_o3[1168] = 369.0;
    localB->HoughTransform1_o3[1169] = 370.0;
    localB->HoughTransform1_o3[1170] = 371.0;
    localB->HoughTransform1_o3[1171] = 372.0;
    localB->HoughTransform1_o3[1172] = 373.0;
    localB->HoughTransform1_o3[1173] = 374.0;
    localB->HoughTransform1_o3[1174] = 375.0;
    localB->HoughTransform1_o3[1175] = 376.0;
    localB->HoughTransform1_o3[1176] = 377.0;
    localB->HoughTransform1_o3[1177] = 378.0;
    localB->HoughTransform1_o3[1178] = 379.0;
    localB->HoughTransform1_o3[1179] = 380.0;
    localB->HoughTransform1_o3[1180] = 381.0;
    localB->HoughTransform1_o3[1181] = 382.0;
    localB->HoughTransform1_o3[1182] = 383.0;
    localB->HoughTransform1_o3[1183] = 384.0;
    localB->HoughTransform1_o3[1184] = 385.0;
    localB->HoughTransform1_o3[1185] = 386.0;
    localB->HoughTransform1_o3[1186] = 387.0;
    localB->HoughTransform1_o3[1187] = 388.0;
    localB->HoughTransform1_o3[1188] = 389.0;
    localB->HoughTransform1_o3[1189] = 390.0;
    localB->HoughTransform1_o3[1190] = 391.0;
    localB->HoughTransform1_o3[1191] = 392.0;
    localB->HoughTransform1_o3[1192] = 393.0;
    localB->HoughTransform1_o3[1193] = 394.0;
    localB->HoughTransform1_o3[1194] = 395.0;
    localB->HoughTransform1_o3[1195] = 396.0;
    localB->HoughTransform1_o3[1196] = 397.0;
    localB->HoughTransform1_o3[1197] = 398.0;
    localB->HoughTransform1_o3[1198] = 399.0;
    localB->HoughTransform1_o3[1199] = 400.0;
    localB->HoughTransform1_o3[1200] = 401.0;
    localB->HoughTransform1_o3[1201] = 402.0;
    localB->HoughTransform1_o3[1202] = 403.0;
    localB->HoughTransform1_o3[1203] = 404.0;
    localB->HoughTransform1_o3[1204] = 405.0;
    localB->HoughTransform1_o3[1205] = 406.0;
    localB->HoughTransform1_o3[1206] = 407.0;
    localB->HoughTransform1_o3[1207] = 408.0;
    localB->HoughTransform1_o3[1208] = 409.0;
    localB->HoughTransform1_o3[1209] = 410.0;
    localB->HoughTransform1_o3[1210] = 411.0;
    localB->HoughTransform1_o3[1211] = 412.0;
    localB->HoughTransform1_o3[1212] = 413.0;
    localB->HoughTransform1_o3[1213] = 414.0;
    localB->HoughTransform1_o3[1214] = 415.0;
    localB->HoughTransform1_o3[1215] = 416.0;
    localB->HoughTransform1_o3[1216] = 417.0;
    localB->HoughTransform1_o3[1217] = 418.0;
    localB->HoughTransform1_o3[1218] = 419.0;
    localB->HoughTransform1_o3[1219] = 420.0;
    localB->HoughTransform1_o3[1220] = 421.0;
    localB->HoughTransform1_o3[1221] = 422.0;
    localB->HoughTransform1_o3[1222] = 423.0;
    localB->HoughTransform1_o3[1223] = 424.0;
    localB->HoughTransform1_o3[1224] = 425.0;
    localB->HoughTransform1_o3[1225] = 426.0;
    localB->HoughTransform1_o3[1226] = 427.0;
    localB->HoughTransform1_o3[1227] = 428.0;
    localB->HoughTransform1_o3[1228] = 429.0;
    localB->HoughTransform1_o3[1229] = 430.0;
    localB->HoughTransform1_o3[1230] = 431.0;
    localB->HoughTransform1_o3[1231] = 432.0;
    localB->HoughTransform1_o3[1232] = 433.0;
    localB->HoughTransform1_o3[1233] = 434.0;
    localB->HoughTransform1_o3[1234] = 435.0;
    localB->HoughTransform1_o3[1235] = 436.0;
    localB->HoughTransform1_o3[1236] = 437.0;
    localB->HoughTransform1_o3[1237] = 438.0;
    localB->HoughTransform1_o3[1238] = 439.0;
    localB->HoughTransform1_o3[1239] = 440.0;
    localB->HoughTransform1_o3[1240] = 441.0;
    localB->HoughTransform1_o3[1241] = 442.0;
    localB->HoughTransform1_o3[1242] = 443.0;
    localB->HoughTransform1_o3[1243] = 444.0;
    localB->HoughTransform1_o3[1244] = 445.0;
    localB->HoughTransform1_o3[1245] = 446.0;
    localB->HoughTransform1_o3[1246] = 447.0;
    localB->HoughTransform1_o3[1247] = 448.0;
    localB->HoughTransform1_o3[1248] = 449.0;
    localB->HoughTransform1_o3[1249] = 450.0;
    localB->HoughTransform1_o3[1250] = 451.0;
    localB->HoughTransform1_o3[1251] = 452.0;
    localB->HoughTransform1_o3[1252] = 453.0;
    localB->HoughTransform1_o3[1253] = 454.0;
    localB->HoughTransform1_o3[1254] = 455.0;
    localB->HoughTransform1_o3[1255] = 456.0;
    localB->HoughTransform1_o3[1256] = 457.0;
    localB->HoughTransform1_o3[1257] = 458.0;
    localB->HoughTransform1_o3[1258] = 459.0;
    localB->HoughTransform1_o3[1259] = 460.0;
    localB->HoughTransform1_o3[1260] = 461.0;
    localB->HoughTransform1_o3[1261] = 462.0;
    localB->HoughTransform1_o3[1262] = 463.0;
    localB->HoughTransform1_o3[1263] = 464.0;
    localB->HoughTransform1_o3[1264] = 465.0;
    localB->HoughTransform1_o3[1265] = 466.0;
    localB->HoughTransform1_o3[1266] = 467.0;
    localB->HoughTransform1_o3[1267] = 468.0;
    localB->HoughTransform1_o3[1268] = 469.0;
    localB->HoughTransform1_o3[1269] = 470.0;
    localB->HoughTransform1_o3[1270] = 471.0;
    localB->HoughTransform1_o3[1271] = 472.0;
    localB->HoughTransform1_o3[1272] = 473.0;
    localB->HoughTransform1_o3[1273] = 474.0;
    localB->HoughTransform1_o3[1274] = 475.0;
    localB->HoughTransform1_o3[1275] = 476.0;
    localB->HoughTransform1_o3[1276] = 477.0;
    localB->HoughTransform1_o3[1277] = 478.0;
    localB->HoughTransform1_o3[1278] = 479.0;
    localB->HoughTransform1_o3[1279] = 480.0;
    localB->HoughTransform1_o3[1280] = 481.0;
    localB->HoughTransform1_o3[1281] = 482.0;
    localB->HoughTransform1_o3[1282] = 483.0;
    localB->HoughTransform1_o3[1283] = 484.0;
    localB->HoughTransform1_o3[1284] = 485.0;
    localB->HoughTransform1_o3[1285] = 486.0;
    localB->HoughTransform1_o3[1286] = 487.0;
    localB->HoughTransform1_o3[1287] = 488.0;
    localB->HoughTransform1_o3[1288] = 489.0;
    localB->HoughTransform1_o3[1289] = 490.0;
    localB->HoughTransform1_o3[1290] = 491.0;
    localB->HoughTransform1_o3[1291] = 492.0;
    localB->HoughTransform1_o3[1292] = 493.0;
    localB->HoughTransform1_o3[1293] = 494.0;
    localB->HoughTransform1_o3[1294] = 495.0;
    localB->HoughTransform1_o3[1295] = 496.0;
    localB->HoughTransform1_o3[1296] = 497.0;
    localB->HoughTransform1_o3[1297] = 498.0;
    localB->HoughTransform1_o3[1298] = 499.0;
    localB->HoughTransform1_o3[1299] = 500.0;
    localB->HoughTransform1_o3[1300] = 501.0;
    localB->HoughTransform1_o3[1301] = 502.0;
    localB->HoughTransform1_o3[1302] = 503.0;
    localB->HoughTransform1_o3[1303] = 504.0;
    localB->HoughTransform1_o3[1304] = 505.0;
    localB->HoughTransform1_o3[1305] = 506.0;
    localB->HoughTransform1_o3[1306] = 507.0;
    localB->HoughTransform1_o3[1307] = 508.0;
    localB->HoughTransform1_o3[1308] = 509.0;
    localB->HoughTransform1_o3[1309] = 510.0;
    localB->HoughTransform1_o3[1310] = 511.0;
    localB->HoughTransform1_o3[1311] = 512.0;
    localB->HoughTransform1_o3[1312] = 513.0;
    localB->HoughTransform1_o3[1313] = 514.0;
    localB->HoughTransform1_o3[1314] = 515.0;
    localB->HoughTransform1_o3[1315] = 516.0;
    localB->HoughTransform1_o3[1316] = 517.0;
    localB->HoughTransform1_o3[1317] = 518.0;
    localB->HoughTransform1_o3[1318] = 519.0;
    localB->HoughTransform1_o3[1319] = 520.0;
    localB->HoughTransform1_o3[1320] = 521.0;
    localB->HoughTransform1_o3[1321] = 522.0;
    localB->HoughTransform1_o3[1322] = 523.0;
    localB->HoughTransform1_o3[1323] = 524.0;
    localB->HoughTransform1_o3[1324] = 525.0;
    localB->HoughTransform1_o3[1325] = 526.0;
    localB->HoughTransform1_o3[1326] = 527.0;
    localB->HoughTransform1_o3[1327] = 528.0;
    localB->HoughTransform1_o3[1328] = 529.0;
    localB->HoughTransform1_o3[1329] = 530.0;
    localB->HoughTransform1_o3[1330] = 531.0;
    localB->HoughTransform1_o3[1331] = 532.0;
    localB->HoughTransform1_o3[1332] = 533.0;
    localB->HoughTransform1_o3[1333] = 534.0;
    localB->HoughTransform1_o3[1334] = 535.0;
    localB->HoughTransform1_o3[1335] = 536.0;
    localB->HoughTransform1_o3[1336] = 537.0;
    localB->HoughTransform1_o3[1337] = 538.0;
    localB->HoughTransform1_o3[1338] = 539.0;
    localB->HoughTransform1_o3[1339] = 540.0;
    localB->HoughTransform1_o3[1340] = 541.0;
    localB->HoughTransform1_o3[1341] = 542.0;
    localB->HoughTransform1_o3[1342] = 543.0;
    localB->HoughTransform1_o3[1343] = 544.0;
    localB->HoughTransform1_o3[1344] = 545.0;
    localB->HoughTransform1_o3[1345] = 546.0;
    localB->HoughTransform1_o3[1346] = 547.0;
    localB->HoughTransform1_o3[1347] = 548.0;
    localB->HoughTransform1_o3[1348] = 549.0;
    localB->HoughTransform1_o3[1349] = 550.0;
    localB->HoughTransform1_o3[1350] = 551.0;
    localB->HoughTransform1_o3[1351] = 552.0;
    localB->HoughTransform1_o3[1352] = 553.0;
    localB->HoughTransform1_o3[1353] = 554.0;
    localB->HoughTransform1_o3[1354] = 555.0;
    localB->HoughTransform1_o3[1355] = 556.0;
    localB->HoughTransform1_o3[1356] = 557.0;
    localB->HoughTransform1_o3[1357] = 558.0;
    localB->HoughTransform1_o3[1358] = 559.0;
    localB->HoughTransform1_o3[1359] = 560.0;
    localB->HoughTransform1_o3[1360] = 561.0;
    localB->HoughTransform1_o3[1361] = 562.0;
    localB->HoughTransform1_o3[1362] = 563.0;
    localB->HoughTransform1_o3[1363] = 564.0;
    localB->HoughTransform1_o3[1364] = 565.0;
    localB->HoughTransform1_o3[1365] = 566.0;
    localB->HoughTransform1_o3[1366] = 567.0;
    localB->HoughTransform1_o3[1367] = 568.0;
    localB->HoughTransform1_o3[1368] = 569.0;
    localB->HoughTransform1_o3[1369] = 570.0;
    localB->HoughTransform1_o3[1370] = 571.0;
    localB->HoughTransform1_o3[1371] = 572.0;
    localB->HoughTransform1_o3[1372] = 573.0;
    localB->HoughTransform1_o3[1373] = 574.0;
    localB->HoughTransform1_o3[1374] = 575.0;
    localB->HoughTransform1_o3[1375] = 576.0;
    localB->HoughTransform1_o3[1376] = 577.0;
    localB->HoughTransform1_o3[1377] = 578.0;
    localB->HoughTransform1_o3[1378] = 579.0;
    localB->HoughTransform1_o3[1379] = 580.0;
    localB->HoughTransform1_o3[1380] = 581.0;
    localB->HoughTransform1_o3[1381] = 582.0;
    localB->HoughTransform1_o3[1382] = 583.0;
    localB->HoughTransform1_o3[1383] = 584.0;
    localB->HoughTransform1_o3[1384] = 585.0;
    localB->HoughTransform1_o3[1385] = 586.0;
    localB->HoughTransform1_o3[1386] = 587.0;
    localB->HoughTransform1_o3[1387] = 588.0;
    localB->HoughTransform1_o3[1388] = 589.0;
    localB->HoughTransform1_o3[1389] = 590.0;
    localB->HoughTransform1_o3[1390] = 591.0;
    localB->HoughTransform1_o3[1391] = 592.0;
    localB->HoughTransform1_o3[1392] = 593.0;
    localB->HoughTransform1_o3[1393] = 594.0;
    localB->HoughTransform1_o3[1394] = 595.0;
    localB->HoughTransform1_o3[1395] = 596.0;
    localB->HoughTransform1_o3[1396] = 597.0;
    localB->HoughTransform1_o3[1397] = 598.0;
    localB->HoughTransform1_o3[1398] = 599.0;
    localB->HoughTransform1_o3[1399] = 600.0;
    localB->HoughTransform1_o3[1400] = 601.0;
    localB->HoughTransform1_o3[1401] = 602.0;
    localB->HoughTransform1_o3[1402] = 603.0;
    localB->HoughTransform1_o3[1403] = 604.0;
    localB->HoughTransform1_o3[1404] = 605.0;
    localB->HoughTransform1_o3[1405] = 606.0;
    localB->HoughTransform1_o3[1406] = 607.0;
    localB->HoughTransform1_o3[1407] = 608.0;
    localB->HoughTransform1_o3[1408] = 609.0;
    localB->HoughTransform1_o3[1409] = 610.0;
    localB->HoughTransform1_o3[1410] = 611.0;
    localB->HoughTransform1_o3[1411] = 612.0;
    localB->HoughTransform1_o3[1412] = 613.0;
    localB->HoughTransform1_o3[1413] = 614.0;
    localB->HoughTransform1_o3[1414] = 615.0;
    localB->HoughTransform1_o3[1415] = 616.0;
    localB->HoughTransform1_o3[1416] = 617.0;
    localB->HoughTransform1_o3[1417] = 618.0;
    localB->HoughTransform1_o3[1418] = 619.0;
    localB->HoughTransform1_o3[1419] = 620.0;
    localB->HoughTransform1_o3[1420] = 621.0;
    localB->HoughTransform1_o3[1421] = 622.0;
    localB->HoughTransform1_o3[1422] = 623.0;
    localB->HoughTransform1_o3[1423] = 624.0;
    localB->HoughTransform1_o3[1424] = 625.0;
    localB->HoughTransform1_o3[1425] = 626.0;
    localB->HoughTransform1_o3[1426] = 627.0;
    localB->HoughTransform1_o3[1427] = 628.0;
    localB->HoughTransform1_o3[1428] = 629.0;
    localB->HoughTransform1_o3[1429] = 630.0;
    localB->HoughTransform1_o3[1430] = 631.0;
    localB->HoughTransform1_o3[1431] = 632.0;
    localB->HoughTransform1_o3[1432] = 633.0;
    localB->HoughTransform1_o3[1433] = 634.0;
    localB->HoughTransform1_o3[1434] = 635.0;
    localB->HoughTransform1_o3[1435] = 636.0;
    localB->HoughTransform1_o3[1436] = 637.0;
    localB->HoughTransform1_o3[1437] = 638.0;
    localB->HoughTransform1_o3[1438] = 639.0;
    localB->HoughTransform1_o3[1439] = 640.0;
    localB->HoughTransform1_o3[1440] = 641.0;
    localB->HoughTransform1_o3[1441] = 642.0;
    localB->HoughTransform1_o3[1442] = 643.0;
    localB->HoughTransform1_o3[1443] = 644.0;
    localB->HoughTransform1_o3[1444] = 645.0;
    localB->HoughTransform1_o3[1445] = 646.0;
    localB->HoughTransform1_o3[1446] = 647.0;
    localB->HoughTransform1_o3[1447] = 648.0;
    localB->HoughTransform1_o3[1448] = 649.0;
    localB->HoughTransform1_o3[1449] = 650.0;
    localB->HoughTransform1_o3[1450] = 651.0;
    localB->HoughTransform1_o3[1451] = 652.0;
    localB->HoughTransform1_o3[1452] = 653.0;
    localB->HoughTransform1_o3[1453] = 654.0;
    localB->HoughTransform1_o3[1454] = 655.0;
    localB->HoughTransform1_o3[1455] = 656.0;
    localB->HoughTransform1_o3[1456] = 657.0;
    localB->HoughTransform1_o3[1457] = 658.0;
    localB->HoughTransform1_o3[1458] = 659.0;
    localB->HoughTransform1_o3[1459] = 660.0;
    localB->HoughTransform1_o3[1460] = 661.0;
    localB->HoughTransform1_o3[1461] = 662.0;
    localB->HoughTransform1_o3[1462] = 663.0;
    localB->HoughTransform1_o3[1463] = 664.0;
    localB->HoughTransform1_o3[1464] = 665.0;
    localB->HoughTransform1_o3[1465] = 666.0;
    localB->HoughTransform1_o3[1466] = 667.0;
    localB->HoughTransform1_o3[1467] = 668.0;
    localB->HoughTransform1_o3[1468] = 669.0;
    localB->HoughTransform1_o3[1469] = 670.0;
    localB->HoughTransform1_o3[1470] = 671.0;
    localB->HoughTransform1_o3[1471] = 672.0;
    localB->HoughTransform1_o3[1472] = 673.0;
    localB->HoughTransform1_o3[1473] = 674.0;
    localB->HoughTransform1_o3[1474] = 675.0;
    localB->HoughTransform1_o3[1475] = 676.0;
    localB->HoughTransform1_o3[1476] = 677.0;
    localB->HoughTransform1_o3[1477] = 678.0;
    localB->HoughTransform1_o3[1478] = 679.0;
    localB->HoughTransform1_o3[1479] = 680.0;
    localB->HoughTransform1_o3[1480] = 681.0;
    localB->HoughTransform1_o3[1481] = 682.0;
    localB->HoughTransform1_o3[1482] = 683.0;
    localB->HoughTransform1_o3[1483] = 684.0;
    localB->HoughTransform1_o3[1484] = 685.0;
    localB->HoughTransform1_o3[1485] = 686.0;
    localB->HoughTransform1_o3[1486] = 687.0;
    localB->HoughTransform1_o3[1487] = 688.0;
    localB->HoughTransform1_o3[1488] = 689.0;
    localB->HoughTransform1_o3[1489] = 690.0;
    localB->HoughTransform1_o3[1490] = 691.0;
    localB->HoughTransform1_o3[1491] = 692.0;
    localB->HoughTransform1_o3[1492] = 693.0;
    localB->HoughTransform1_o3[1493] = 694.0;
    localB->HoughTransform1_o3[1494] = 695.0;
    localB->HoughTransform1_o3[1495] = 696.0;
    localB->HoughTransform1_o3[1496] = 697.0;
    localB->HoughTransform1_o3[1497] = 698.0;
    localB->HoughTransform1_o3[1498] = 699.0;
    localB->HoughTransform1_o3[1499] = 700.0;
    localB->HoughTransform1_o3[1500] = 701.0;
    localB->HoughTransform1_o3[1501] = 702.0;
    localB->HoughTransform1_o3[1502] = 703.0;
    localB->HoughTransform1_o3[1503] = 704.0;
    localB->HoughTransform1_o3[1504] = 705.0;
    localB->HoughTransform1_o3[1505] = 706.0;
    localB->HoughTransform1_o3[1506] = 707.0;
    localB->HoughTransform1_o3[1507] = 708.0;
    localB->HoughTransform1_o3[1508] = 709.0;
    localB->HoughTransform1_o3[1509] = 710.0;
    localB->HoughTransform1_o3[1510] = 711.0;
    localB->HoughTransform1_o3[1511] = 712.0;
    localB->HoughTransform1_o3[1512] = 713.0;
    localB->HoughTransform1_o3[1513] = 714.0;
    localB->HoughTransform1_o3[1514] = 715.0;
    localB->HoughTransform1_o3[1515] = 716.0;
    localB->HoughTransform1_o3[1516] = 717.0;
    localB->HoughTransform1_o3[1517] = 718.0;
    localB->HoughTransform1_o3[1518] = 719.0;
    localB->HoughTransform1_o3[1519] = 720.0;
    localB->HoughTransform1_o3[1520] = 721.0;
    localB->HoughTransform1_o3[1521] = 722.0;
    localB->HoughTransform1_o3[1522] = 723.0;
    localB->HoughTransform1_o3[1523] = 724.0;
    localB->HoughTransform1_o3[1524] = 725.0;
    localB->HoughTransform1_o3[1525] = 726.0;
    localB->HoughTransform1_o3[1526] = 727.0;
    localB->HoughTransform1_o3[1527] = 728.0;
    localB->HoughTransform1_o3[1528] = 729.0;
    localB->HoughTransform1_o3[1529] = 730.0;
    localB->HoughTransform1_o3[1530] = 731.0;
    localB->HoughTransform1_o3[1531] = 732.0;
    localB->HoughTransform1_o3[1532] = 733.0;
    localB->HoughTransform1_o3[1533] = 734.0;
    localB->HoughTransform1_o3[1534] = 735.0;
    localB->HoughTransform1_o3[1535] = 736.0;
    localB->HoughTransform1_o3[1536] = 737.0;
    localB->HoughTransform1_o3[1537] = 738.0;
    localB->HoughTransform1_o3[1538] = 739.0;
    localB->HoughTransform1_o3[1539] = 740.0;
    localB->HoughTransform1_o3[1540] = 741.0;
    localB->HoughTransform1_o3[1541] = 742.0;
    localB->HoughTransform1_o3[1542] = 743.0;
    localB->HoughTransform1_o3[1543] = 744.0;
    localB->HoughTransform1_o3[1544] = 745.0;
    localB->HoughTransform1_o3[1545] = 746.0;
    localB->HoughTransform1_o3[1546] = 747.0;
    localB->HoughTransform1_o3[1547] = 748.0;
    localB->HoughTransform1_o3[1548] = 749.0;
    localB->HoughTransform1_o3[1549] = 750.0;
    localB->HoughTransform1_o3[1550] = 751.0;
    localB->HoughTransform1_o3[1551] = 752.0;
    localB->HoughTransform1_o3[1552] = 753.0;
    localB->HoughTransform1_o3[1553] = 754.0;
    localB->HoughTransform1_o3[1554] = 755.0;
    localB->HoughTransform1_o3[1555] = 756.0;
    localB->HoughTransform1_o3[1556] = 757.0;
    localB->HoughTransform1_o3[1557] = 758.0;
    localB->HoughTransform1_o3[1558] = 759.0;
    localB->HoughTransform1_o3[1559] = 760.0;
    localB->HoughTransform1_o3[1560] = 761.0;
    localB->HoughTransform1_o3[1561] = 762.0;
    localB->HoughTransform1_o3[1562] = 763.0;
    localB->HoughTransform1_o3[1563] = 764.0;
    localB->HoughTransform1_o3[1564] = 765.0;
    localB->HoughTransform1_o3[1565] = 766.0;
    localB->HoughTransform1_o3[1566] = 767.0;
    localB->HoughTransform1_o3[1567] = 768.0;
    localB->HoughTransform1_o3[1568] = 769.0;
    localB->HoughTransform1_o3[1569] = 770.0;
    localB->HoughTransform1_o3[1570] = 771.0;
    localB->HoughTransform1_o3[1571] = 772.0;
    localB->HoughTransform1_o3[1572] = 773.0;
    localB->HoughTransform1_o3[1573] = 774.0;
    localB->HoughTransform1_o3[1574] = 775.0;
    localB->HoughTransform1_o3[1575] = 776.0;
    localB->HoughTransform1_o3[1576] = 777.0;
    localB->HoughTransform1_o3[1577] = 778.0;
    localB->HoughTransform1_o3[1578] = 779.0;
    localB->HoughTransform1_o3[1579] = 780.0;
    localB->HoughTransform1_o3[1580] = 781.0;
    localB->HoughTransform1_o3[1581] = 782.0;
    localB->HoughTransform1_o3[1582] = 783.0;
    localB->HoughTransform1_o3[1583] = 784.0;
    localB->HoughTransform1_o3[1584] = 785.0;
    localB->HoughTransform1_o3[1585] = 786.0;
    localB->HoughTransform1_o3[1586] = 787.0;
    localB->HoughTransform1_o3[1587] = 788.0;
    localB->HoughTransform1_o3[1588] = 789.0;
    localB->HoughTransform1_o3[1589] = 790.0;
    localB->HoughTransform1_o3[1590] = 791.0;
    localB->HoughTransform1_o3[1591] = 792.0;
    localB->HoughTransform1_o3[1592] = 793.0;
    localB->HoughTransform1_o3[1593] = 794.0;
    localB->HoughTransform1_o3[1594] = 795.0;
    localB->HoughTransform1_o3[1595] = 796.0;
    localB->HoughTransform1_o3[1596] = 797.0;
    localB->HoughTransform1_o3[1597] = 798.0;
    localB->HoughTransform1_o3[1598] = 799.0;
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
