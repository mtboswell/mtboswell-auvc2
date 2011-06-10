/*
 * File: buoy_detector.cpp
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.714
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:26:37 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:26:37 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buoy_detector.h"
#include "buoy_detector_private.h"

/* Forward declaration for local functions */
static void buoy_detector_Outputs(const boolean_T U0[19200], real_T Y0[100],
  real_T Y1[50], real_T Y2[50], uint8_T *Y3, rtDW_mr_buoy_detector *localDW);

/*
 * Output and update for atomic system:
 *    '<S4>/Low Pass Filter'
 *    '<S4>/Low Pass Filter1'
 *    '<S4>/Low Pass Filter2'
 */
void buoy_detector_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_buoy_detector *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S4>/Low Pass Filter' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S6>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S6>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S6>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S6>:1:19' */
  /* '<S6>:1:21' */
  /* '<S6>:1:23' */
  Gsum = 0.0;

  /* '<S6>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S6>:1:24' */
    /* '<S6>:1:25' */
    /* '<S6>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S6>:1:27' */
    Gsum += G[i + 1];

    /* '<S6>:1:25' */
    /* '<S6>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S6>:1:27' */
    Gsum += G[i + 4];

    /* '<S6>:1:25' */
    /* '<S6>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S6>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S6>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S6>:1:33' */
  fknoophdhdjeohdj_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S6>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S6>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S6>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S6>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S6>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S6>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S6>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S6>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S6>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Function for Embedded MATLAB: '<S2>/Blob Extraction' */
static void buoy_detector_Outputs(const boolean_T U0[19200], real_T Y0[100],
  real_T Y1[50], real_T Y2[50], uint8_T *Y3, rtDW_mr_buoy_detector *localDW)
{
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T walkerIdx;
  int32_T numBlobs;
  int32_T pixListMinc;
  int32_T pixListNinc;
  int32_T c_i;
  int32_T j;
  int32_T maxc;
  int32_T maxr;
  real_T xs;
  real_T ys;
  real_T xys;
  uint32_T k;
  real_T uyy;
  real_T majorAxis;
  real_T centroid_idx;
  real_T centroid_idx_0;

  /* System object Outputs function: video.BlobAnalysis */
  maxNumBlobsReached = FALSE;
  memset((void *)(&localDW->PAD_DW[0]), (int32_T)0U, 163U * sizeof(uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 163;
  for (n = 0; n < 120; n++) {
    for (maxc = 0; maxc < 160; maxc++) {
      localDW->PAD_DW[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    localDW->PAD_DW[idx] = 0U;
    idx++;
    localDW->PAD_DW[idx] = 0U;
    idx++;
  }

  memset((void *)(&localDW->PAD_DW[idx]), (int32_T)0U, 161U * sizeof(uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 120; n++) {
    maxc = 1;
    idx = loop * 162;
    for (maxr = 0; maxr < 160; maxr++) {
      k = (uint32_T)(idx + maxc);
      start_pixIdx = pixIdx;
      if (localDW->PAD_DW[k] == 255) {
        localDW->PAD_DW[k] = currentLabel;
        localDW->N_PIXLIST_DW[pixIdx] = (int16_T)(loop - 1);
        localDW->M_PIXLIST_DW[pixIdx] = (int16_T)(maxc - 1);
        pixIdx++;
        localDW->NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->STACK_DW[stackIdx] = k;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          k = localDW->STACK_DW[stackIdx];
          for (pixListMinc = 0; pixListMinc < 8; pixListMinc++) {
            walkerIdx = k + (uint32_T)localDW->WALKER_RTP[pixListMinc];
            if (localDW->PAD_DW[walkerIdx] == 255) {
              localDW->PAD_DW[walkerIdx] = currentLabel;
              localDW->N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)(walkerIdx /
                162U) - 1);
              localDW->M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx % 162U - 1U);
              pixIdx++;
              localDW->NUM_PIX_DW[currentLabel - 1] = localDW->
                NUM_PIX_DW[currentLabel - 1] + 1U;
              localDW->STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (localDW->NUM_PIX_DW[currentLabel - 1] < localDW->MINAREA_RTP) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 50) {
          maxNumBlobsReached = TRUE;
          n = 120;
          maxr = 160;
        }

        if (maxr < 160) {
          currentLabel++;
        }
      }

      maxc++;
    }

    loop++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  *Y3 = (uint8_T)numBlobs;
  pixListMinc = 0;
  pixListNinc = 0;
  for (c_i = 0; c_i < numBlobs; c_i++) {
    loop = 0;
    n = 0;
    for (j = 0; j < (int32_T)localDW->NUM_PIX_DW[c_i]; j++) {
      loop += localDW->N_PIXLIST_DW[j + pixListNinc];
      n += localDW->M_PIXLIST_DW[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)localDW->NUM_PIX_DW[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)localDW->NUM_PIX_DW[c_i];
    Y0[c_i << 1] = centroid_idx;
    Y0[(c_i << 1) + 1] = centroid_idx_0;
    n = 120;
    idx = 160;
    maxc = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)localDW->NUM_PIX_DW[c_i]; j++) {
      loop = j + pixListNinc;
      if (localDW->N_PIXLIST_DW[loop] < n) {
        n = localDW->N_PIXLIST_DW[loop];
      }

      if (localDW->N_PIXLIST_DW[loop] > maxc) {
        maxc = localDW->N_PIXLIST_DW[loop];
      }

      loop = j + pixListMinc;
      if (localDW->M_PIXLIST_DW[loop] < idx) {
        idx = localDW->M_PIXLIST_DW[loop];
      }

      if (localDW->M_PIXLIST_DW[loop] > maxr) {
        maxr = localDW->M_PIXLIST_DW[loop];
      }
    }

    xs = 0.0;
    ys = 0.0;
    xys = 0.0;
    for (k = 0U; (int32_T)k < (int32_T)localDW->NUM_PIX_DW[c_i]; k++) {
      majorAxis = (real_T)localDW->N_PIXLIST_DW[pixListNinc + (int32_T)k] -
        centroid_idx_0;
      uyy = (real_T)localDW->M_PIXLIST_DW[pixListMinc + (int32_T)k] -
        centroid_idx;
      xs += majorAxis * majorAxis;
      ys += uyy * uyy;
      xys += majorAxis * (-uyy);
    }

    centroid_idx = xs / (real_T)localDW->NUM_PIX_DW[c_i] + 0.083333333333333329;
    uyy = ys / (real_T)localDW->NUM_PIX_DW[c_i] + 0.083333333333333329;
    xs = xys / (real_T)localDW->NUM_PIX_DW[c_i];
    xs = sqrt((centroid_idx - uyy) * (centroid_idx - uyy) + xs * xs * 4.0);
    majorAxis = ((centroid_idx + uyy) + xs) * 8.0;
    Y1[c_i] = sqrt(majorAxis - ((centroid_idx + uyy) - xs) * 8.0) / sqrt
      (majorAxis);
    Y2[c_i] = (real_T)localDW->NUM_PIX_DW[c_i] / (real_T)(((maxr + 1) - idx) *
      ((maxc + 1) - n));
    pixListMinc += (int32_T)localDW->NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)localDW->NUM_PIX_DW[c_i];
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y0[loop] = localDW->F0_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y1[loop] = localDW->F1_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y2[loop] = localDW->F2_RTP;
  }
}

/* Initial conditions for referenced model: 'buoy_detector' */
void mr_buoy_detector_Init(rtDW_mr_buoy_detector *localDW)
{
  int32_T i;
  static int16_T tmp[8] = { -1, 161, 162, 163, 1, -161, -162, -163 };

  /* InitializeConditions for Embedded MATLAB: '<S2>/Blob Extraction' */
  for (i = 0; i < 8; i++) {
    localDW->WALKER_RTP[i] = tmp[i];
  }

  localDW->F0_RTP = -1.0;
  localDW->F1_RTP = -1.0;
  localDW->F2_RTP = -1.0;
  localDW->MINAREA_RTP = 5U;
}

/* Output and update for referenced model: 'buoy_detector' */
void mr_buoy_detector(const real_T rtu_R_forward_in[19200], const real_T
                      rtu_G_forward_in[19200], const real_T rtu_B_forward_in
                      [19200], const real_T *rtu_WhichColor, real_T
                      *rty_TargetSelect, real_T *rty_TargetFound, real_T
                      *rty_MaintainHeading, real_T *rty_TargetY, real_T
                      *rty_TargetZ, real_T *rty_TargetYaw, real_T
                      *rty_TargetDetected, real_T rty_BuoyColors[50],
                      rtB_mr_buoy_detector *localB, rtDW_mr_buoy_detector
                      *localDW)
{
  int32_T i;
  int32_T ictr;
  int32_T num_colors;
  int32_T flag;
  int32_T j;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];
  real_T min_dist;
  real_T index;
  real_T ii;
  real_T jj;
  real_T k;
  uint8_T b_i;
  uint8_T TNumBlobs;
  real_T var_X[50];
  real_T var_R[50];
  real_T var_G[50];
  real_T Resize2_LineBuffer[160];
  real_T rtb_buoy_centroids[100];
  boolean_T ref_color_L_avg_0[50];
  real_T var_R_0[150];
  real_T var_R_1[150];
  real_T tmp[50];
  real_T ref_color_L_avg_1;
  uint8_T tmp_0;
  real_T tmp_1[50];

  /* Embedded MATLAB: '<S4>/Low Pass Filter' */
  buoy_detector_LowPassFilter(rtu_R_forward_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S4>/Low Pass Filter1' */
  buoy_detector_LowPassFilter(rtu_G_forward_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S4>/Low Pass Filter2' */
  buoy_detector_LowPassFilter(rtu_B_forward_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[i] <= 0.039286085583733095) {
      min_dist = localB->sf_LowPassFilter.Iout[i] / 12.923054468333255;
    } else {
      min_dist = rt_pow_snf((localB->sf_LowPassFilter.Iout[i] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter1.Iout[i] <= 0.039286085583733095) {
      index = localB->sf_LowPassFilter1.Iout[i] / 12.923054468333255;
    } else {
      index = rt_pow_snf((localB->sf_LowPassFilter1.Iout[i] +
                          0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter2.Iout[i] <= 0.039286085583733095) {
      ii = localB->sf_LowPassFilter2.Iout[i] / 12.923054468333255;
    } else {
      ii = rt_pow_snf((localB->sf_LowPassFilter2.Iout[i] + 0.055000519817226347)
                      / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    jj = (0.41239079926596 * min_dist + 0.35758433938388 * index) +
      0.18048078840183 * ii;
    k = (0.21263900587151 * min_dist + 0.71516867876776 * index) +
      0.07219231536073 * ii;
    min_dist = (0.01933081871559 * min_dist + 0.11919477979463 * index) +
      0.95053215224966 * ii;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (jj > 1.0) {
      jj = 1.0;
    } else {
      if (jj < 0.0) {
        jj = 0.0;
      }
    }

    if (k > 1.0) {
      k = 1.0;
    } else {
      if (k < 0.0) {
        k = 0.0;
      }
    }

    if (min_dist > 1.0) {
      min_dist = 1.0;
    } else {
      if (min_dist < 0.0) {
        min_dist = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = jj;
    localB->ColorSpaceConversion1_o2[i] = k;
    localB->ColorSpaceConversion1_o3[i] = min_dist;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    min_dist = localB->ColorSpaceConversion1_o1[i] / 0.9641986557609;
    ii = localB->ColorSpaceConversion1_o3[i] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (min_dist > 0.0088564516790356311) {
      jj = rt_pow_snf(min_dist, 0.33333333333333331);
    } else {
      jj = 7.7870370370370372 * min_dist + 0.13793103448275862;
    }

    if (localB->ColorSpaceConversion1_o2[i] > 0.0088564516790356311) {
      index = rt_pow_snf(localB->ColorSpaceConversion1_o2[i],
                         0.33333333333333331);
    } else {
      index = 7.7870370370370372 * localB->ColorSpaceConversion1_o2[i] +
        0.13793103448275862;
    }

    if (ii > 0.0088564516790356311) {
      min_dist = rt_pow_snf(ii, 0.33333333333333331);
    } else {
      min_dist = 7.7870370370370372 * ii + 0.13793103448275862;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = 116.0 * index - 16.0;
    localB->ColorSpaceConversion1_o2[i] = (jj - index) * 500.0;
    localB->ColorSpaceConversion1_o3[i] = (index - min_dist) * 200.0;
  }

  /* S-Function (svipresize): '<S11>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist = localB->
        ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled5[num_colors] * 160
        + j] * buoy_detector_ConstP.pooled3[num_colors] +
        localB->ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled5[ictr] *
        160 + j] * buoy_detector_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist += localB->
        ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled5[ictr] * 160 + j] *
        buoy_detector_ConstP.pooled3[ictr];
      localDW->Resize_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize_IntBuffer[num_colors * 160]), 160U * sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled4[ictr]] *
          buoy_detector_ConstP.pooled2[ictr];
        ictr += 60;
      }

      localB->Resize[flag] = min_dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S11>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist = localB->
        ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled5[num_colors] * 160
        + j] * buoy_detector_ConstP.pooled3[num_colors] +
        localB->ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled5[ictr] *
        160 + j] * buoy_detector_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist += localB->
        ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled5[ictr] * 160 + j] *
        buoy_detector_ConstP.pooled3[ictr];
      localDW->Resize1_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[num_colors * 160]), 160U * sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled4[ictr]] *
          buoy_detector_ConstP.pooled2[ictr];
        ictr += 60;
      }

      localB->Resize1[flag] = min_dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S11>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist = localB->
        ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled5[num_colors] * 160
        + j] * buoy_detector_ConstP.pooled3[num_colors] +
        localB->ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled5[ictr] *
        160 + j] * buoy_detector_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist += localB->
        ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled5[ictr] * 160 + j] *
        buoy_detector_ConstP.pooled3[ictr];
      localDW->Resize2_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[num_colors * 160]), 160U * sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled4[ictr]] *
          buoy_detector_ConstP.pooled2[ictr];
        ictr += 60;
      }

      localB->Resize2[flag] = min_dist;
      flag++;
    }
  }

  /* Embedded MATLAB: '<S5>/Reference Color Selection' incorporates:
   *  Constant: '<S5>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/Reference Color Selection': '<S10>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S10>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S10>:1:14' */
  /* '<S10>:1:15' */
  memset((void *)(&localB->ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S10>:1:16' */
  memset((void *)(&localB->LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S10>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S10>:1:23' */
  localB->ref_colors[0] = localB->Resize[2369];
  localB->ref_colors[50] = localB->Resize1[2369];
  localB->ref_colors[100] = localB->Resize2[2369];

  /* '<S10>:1:25' */
  flag = 0;

  /* '<S10>:1:26' */
  i = 1;

  /* '<S10>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S10>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S10>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S10>:1:30' */
        /* '<S10>:1:31' */
        k = 1.0;

        /* '<S10>:1:32' */
        min_dist = 1000.0;

        /* '<S10>:1:33' */
        index = 1.0;
        while ((uint32_T)k <= (uint32_T)num_colors) {
          /* '<S10>:1:34' */
          /* '<S10>:1:35' */
          ii = sqrt((rt_pow_snf(localB->ref_colors[(int32_T)k + 49] -
                                localB->Resize1[(j - 1) * 60 + (i - 1)], 2.0) *
                     1.5 + rt_pow_snf(localB->ref_colors[(int32_T)k - 1] -
                      localB->Resize[(j - 1) * 60 + (i - 1)], 2.0)) + rt_pow_snf
                    (localB->ref_colors[(int32_T)k + 99] - localB->Resize2[(j -
                      1) * 60 + (i - 1)], 2.0) * 1.5);
          if (min_dist > ii) {
            /* '<S10>:1:36' */
            /* '<S10>:1:37' */
            min_dist = ii;

            /* '<S10>:1:38' */
            index = k;
          }

          /* '<S10>:1:40' */
          k++;
        }

        if ((min_dist > 25.0) && (num_colors < 50)) {
          /* '<S10>:1:45' */
          /* '<S10>:1:46' */
          localB->ref_colors[num_colors] = localB->Resize[(j - 1) * 60 + (i - 1)];
          localB->ref_colors[num_colors + 50] = localB->Resize1[(j - 1) * 60 +
            (i - 1)];
          localB->ref_colors[num_colors + 100] = localB->Resize2[(j - 1) * 60 +
            (i - 1)];

          /* '<S10>:1:47' */
          num_colors++;

          /* '<S10>:1:48' */
          flag = 1;

          /* '<S10>:1:49' */
          i = 0;

          /* '<S10>:1:50' */
          j = 0;
        } else {
          /* '<S10>:1:52' */
          localB->LabelMatrix_m[(i - 1) + 60 * (j - 1)] = (uint32_T)index;
        }

        /* '<S10>:1:54' */
        j++;
      }

      /* '<S10>:1:56' */
      j = 1;

      /* '<S10>:1:57' */
      i++;
    }

    /* '<S10>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S10>:1:63' */
  /* '<S10>:1:64' */
  /* '<S10>:1:65' */
  /* '<S10>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S10>:1:67' */
  for (i = 0; i < 60; i++) {
    /* '<S10>:1:67' */
    /* '<S10>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S10>:1:68' */
      /* '<S10>:1:69' */
      /* '<S10>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i] - 1] +
        localB->Resize[60 * flag + i];

      /* '<S10>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i] - 1] +
        localB->Resize1[60 * flag + i];

      /* '<S10>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i] - 1] +
        localB->Resize2[60 * flag + i];

      /* '<S10>:1:73' */
      color_count[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix_m[60 * flag + i] - 1] + 1.0;
    }
  }

  /* '<S10>:1:76' */
  /* '<S10>:1:77' */
  /* '<S10>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S10>:1:80' */
  for (min_dist = 1.0; (uint32_T)min_dist <= (uint32_T)num_colors; min_dist++) {
    /* '<S10>:1:80' */
    /* '<S10>:1:81' */
    localB->ref_colors[(int32_T)min_dist - 1] = ref_color_L_avg[(int32_T)
      min_dist - 1];

    /* '<S10>:1:82' */
    localB->ref_colors[(int32_T)min_dist + 49] = ref_color_a_avg[(int32_T)
      min_dist - 1];

    /* '<S10>:1:83' */
    localB->ref_colors[(int32_T)min_dist + 99] = ref_color_b_avg[(int32_T)
      min_dist - 1];
  }

  localB->num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<S5>/LabSegmentation' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/LabSegmentation': '<S9>:1' */
  /*  This function generates the label matrix */
  /* '<S9>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S9>:1:12' */
  for (i = 0; i < 160; i++) {
    /* '<S9>:1:12' */
    /* '<S9>:1:13' */
    for (j = 0; j < 120; j++) {
      /* '<S9>:1:13' */
      /* '<S9>:1:14' */
      min_dist = 1000.0;

      /* '<S9>:1:15' */
      index = 1.0;

      /* '<S9>:1:16' */
      for (k = 1.0; k <= localB->num_colors; k++) {
        /* '<S9>:1:16' */
        /* '<S9>:1:17' */
        ii = sqrt((rt_pow_snf(localB->ref_colors[(int32_T)k - 1] -
                              localB->ColorSpaceConversion1_o1[160 * j + i], 2.0)
                   + rt_pow_snf(localB->ref_colors[(int32_T)k + 49] -
                    localB->ColorSpaceConversion1_o2[160 * j + i], 2.0)) +
                  rt_pow_snf(localB->ref_colors[(int32_T)k + 99] -
                             localB->ColorSpaceConversion1_o3[160 * j + i], 2.0));
        if (ii < min_dist) {
          /* '<S9>:1:18' */
          /* '<S9>:1:19' */
          min_dist = ii;

          /* '<S9>:1:20' */
          index = k;
        }
      }

      /* '<S9>:1:23' */
      localB->LabelMatrix[i + 160 * j] = index;
    }
  }

  /* '<S9>:1:27' */

  /* Embedded MATLAB: '<S2>/Blob Extraction' */
  min_dist = localB->num_colors;

  /* Embedded MATLAB Function 'Look for Buoys/Blob Extraction': '<S13>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /*  */
  /*  Input */
  /*    LabelMatrix = 2-D matrix of integer values, each of which represents a */
  /*      color; location in matrix corresponds to pixel location in image */
  /*    num_colors = integer number of colors present in LabelMatrix */
  /*  */
  /*  Output */
  /*    blob_count = integer number of blobs in image */
  /*    blob_hues = Nx1 vector of hues of blobs in image */
  /*    blob_centroids = Nx2 matrix of x-y pairs of blob centroid locations */
  /*    blob_eccentricity = Nx1 vector of blob eccentricites */
  /*    blob_extent = Nx1 vector of blob extents */
  /*  Initialize */
  /* '<S13>:1:21' */
  for (i = 0; i < 19200; i++) {
    localB->LogicMatrix[i] = FALSE;
  }

  /* '<S13>:1:23' */
  /* '<S13>:1:26' */
  memset((void *)(&localB->blob_hues[0]), 0, 150U * sizeof(real_T));

  /* '<S13>:1:27' */
  memset((void *)(&localB->blob_centroids[0]), 0, 100U * sizeof(real_T));

  /* '<S13>:1:28' */
  /* '<S13>:1:29' */
  for (i = 0; i < 50; i++) {
    localB->blob_eccentricity[i] = 0.0;
    localB->blob_extent[i] = 0.0;
  }

  /* '<S13>:1:31' */
  index = 0.0;

  /* uint8(0); */
  /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
  /*  identified blob */
  /* % Calculate geometric information about the blobs */
  /*  */
  /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
  /*    locations for which color values are k, and zeros everywhere else */
  /* '<S13>:1:47' */
  for (k = 1.0; k <= min_dist; k++) {
    /* '<S13>:1:47' */
    /* '<S13>:1:48' */
    for (i = 0; i < 160; i++) {
      /* '<S13>:1:48' */
      /* '<S13>:1:49' */
      for (j = 0; j < 120; j++) {
        /* '<S13>:1:49' */
        if (localB->LabelMatrix[160 * j + i] != k) {
          /* '<S13>:1:50' */
          /* '<S13>:1:51' */
          localB->LogicMatrix[i + 160 * j] = FALSE;
        } else {
          /* '<S13>:1:53' */
          localB->LogicMatrix[i + 160 * j] = TRUE;
        }
      }
    }

    buoy_detector_Outputs(&localB->LogicMatrix[0], rtb_buoy_centroids,
                          ref_color_a_avg, color_count, &TNumBlobs, localDW);
    ref_color_L_avg_1 = floor((index + (real_T)TNumBlobs) + 0.5);
    if (ref_color_L_avg_1 < 256.0) {
      tmp_0 = (uint8_T)ref_color_L_avg_1;
    } else {
      tmp_0 = MAX_uint8_T;
    }

    if (tmp_0 < 50) {
      /* '<S13>:1:59' */
      /* '<S13>:1:60' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S13>:1:60' */
        /* '<S13>:1:62' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_centroids[tmp_0 - 1] = rtb_buoy_centroids[(b_i - 1) << 1];

        /* '<S13>:1:63' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_centroids[tmp_0 + 49] = rtb_buoy_centroids[((b_i - 1) << 1)
          + 1];

        /* '<S13>:1:64' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_eccentricity[tmp_0 - 1] = ref_color_a_avg[b_i - 1];

        /* '<S13>:1:65' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_extent[tmp_0 - 1] = color_count[b_i - 1];

        /* '<S13>:1:67' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        ii = localB->blob_centroids[tmp_0 - 1];
        moppaaaadjecnopp_refp1_round(&ii);

        /* '<S13>:1:68' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        jj = localB->blob_centroids[tmp_0 + 49];
        moppaaaadjecnopp_refp1_round(&jj);

        /* '<S13>:1:69' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_hues[tmp_0 - 1] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] - 1];

        /* '<S13>:1:70' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_hues[tmp_0 + 49] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] + 49];

        /* '<S13>:1:71' */
        ref_color_L_avg_1 = floor((index + (real_T)b_i) + 0.5);
        if (ref_color_L_avg_1 < 256.0) {
          tmp_0 = (uint8_T)ref_color_L_avg_1;
        } else {
          tmp_0 = MAX_uint8_T;
        }

        localB->blob_hues[tmp_0 + 99] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] + 99];
      }

      /* '<S13>:1:74' */
      index++;

      /* TNumBlobs; */
    }
  }

  localB->blob_count = index;

  /* Embedded MATLAB: '<S2>/Analyze LabelMatrix for Buoys' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   */
  /* Embedded MATLAB Function 'Look for Buoys/Analyze LabelMatrix for Buoys': '<S12>:1' */
  /*  This function takes in vectors representing blobs present in the image, */
  /*    and returns information about how many and what kind of buoys are */
  /*    present. */
  /*  */
  /*  Input */
  /*    blob_count = integer number of blobs in image */
  /*    blob_hues = Nx1 vector of hues of blobs in image */
  /*    blob_centroids = Nx2 matrix of x-y pairs of blob centroid locations */
  /*    blob_eccentricity = Nx1 vector of blob eccentricites */
  /*    blob_extent = Nx1 vector of blob extents */
  /*  */
  /*    Buoy_Count_Min = integer; minimum number of buoys searched for in an */
  /*      image (mission/controls needs requires this option) */
  /*    Buoy_Count_Max = maximum number of buoys allowed per image; arbitrary */
  /*      limit */
  /*    Min_Hue,Max_Hue = Nx1 limits on valid buoy hues; hue is between 0 and 1 */
  /*    Min_Eccent,Max_Eccent = scalar limits on buoy eccentricity */
  /*    Min_Extent,Max_Extent = scalar limits on buoy extent */
  /*  */
  /*  Output */
  /*    successive_valid_image_count = integer value of the number of times an */
  /*      image with more than Min_Num_Buoys is processed; persistant between */
  /*      function calls, so that the number of successive images containing */
  /*      at least Min_Num_Buoys buoys is tracked */
  /*    buoy_count = integer number of buoys in image */
  /*    buoy_hues = Nx1 vector of buoy colors */
  /*    buoy_centroids = Nx2 matrix of x-y pairs of buoy centroid locations */
  /*  Initialize */
  /* '<S12>:1:32' */
  min_dist = 0.0;

  /* '<S12>:1:37' */
  /* '<S12>:1:38' */
  for (i = 0; i < 100; i++) {
    rtb_buoy_centroids[i] = -500.0;
  }

  /*  Initialize to points clearly not located in image */
  /* '<S12>:1:39' */
  /* '<S12>:1:42' */
  /* '<S12>:1:43' */
  /* { */
  /* Buoy_Hue_HalfRange = 10; */
  /* Buoy1_Hue = 30; */
  /* Buoy2_Hue = 80; */
  /* Buoy3_Hue = 15; */
  /* } */
  /*  Convert all colors to HSV */
  /* '<S12>:1:55' */
  /* refcolors(LabelMatrix(1,1,1)); */
  /* '<S12>:1:56' */
  /* '<S12>:1:57' */
  /* '<S12>:1:59' */
  /* '<S12>:1:60' */
  /* '<S12>:1:61' */
  /* '<S12>:1:63' */
  for (i = 0; i < 50; i++) {
    ref_color_b_avg[i] = -1.0;
    tmp[i] = localB->blob_hues[i] / 10.0;
  }

  nglnaimoglfkkfkf_power(tmp, 2.0, color_count);

  /* '<S12>:1:64' */
  /* '<S12>:1:65' */
  /*  Convert XYZ to RGB */
  /* '<S12>:1:68' */
  /* X from 0 to  95.047      (Observer = 2 degrees, Illuminant = D65) */
  /* '<S12>:1:69' */
  /* Y from 0 to 100.000 */
  /* '<S12>:1:70' */
  /* Z from 0 to 108.883 */
  /* '<S12>:1:72' */
  /* '<S12>:1:73' */
  /* '<S12>:1:74' */
  for (i = 0; i < 50; i++) {
    index = (localB->blob_hues[50 + i] / 17.5 * (localB->blob_hues[i] / 10.0) +
             color_count[i]) / 1.02 / 100.0;
    ref_color_L_avg_1 = color_count[i] / 100.0;
    k = (-(localB->blob_hues[100 + i] / 7.0 * (localB->blob_hues[i] / 10.0) -
           color_count[i])) / 0.847 / 100.0;
    var_R[i] = (index * 3.2406 + ref_color_L_avg_1 * -1.5372) + k * -0.4986;
    var_G[i] = (index * -0.9689 + ref_color_L_avg_1 * 1.8758) + k * 0.0415;
    index = (index * 0.0557 + ref_color_L_avg_1 * -0.204) + k * 1.057;
    var_X[i] = index;
  }

  /* '<S12>:1:76' */
  nglnaimoglfkkfkf_power(var_R, 0.41666666666666669, tmp);

  /* '<S12>:1:77' */
  nglnaimoglfkkfkf_power(var_G, 0.41666666666666669, color_count);

  /* '<S12>:1:78' */
  nglnaimoglfkkfkf_power(var_X, 0.41666666666666669, ref_color_a_avg);

  /* '<S12>:1:80' */
  /* '<S12>:1:81' */
  /* '<S12>:1:82' */
  /*  Convert RGB to HSV */
  /* '<S12>:1:85' */
  /*  RGB from 0 to 255 */
  /* '<S12>:1:86' */
  /* '<S12>:1:87' */
  /* '<S12>:1:89' */
  /*  Min. value of RGB */
  /* '<S12>:1:90' */
  for (i = 0; i < 50; i++) {
    index = ((1.055 * tmp[i] - 0.055) * (real_T)(var_R[i] > 0.0031308) + (real_T)
             (var_R[i] <= 0.0031308) * (12.92 * var_R[i])) * 255.0 / 255.0;
    var_R_1[i] = index;
    var_G[i] = ((1.055 * color_count[i] - 0.055) * (real_T)(var_G[i] > 0.0031308)
                + (real_T)(var_G[i] <= 12.92 * var_G[i]) * (real_T)(var_G[i] <=
      0.0031308)) * 255.0 / 255.0;
    var_X[i] = ((1.055 * ref_color_a_avg[i] - 0.055) * (real_T)(var_X[i] >
      0.0031308) + (real_T)(var_X[i] <= 0.0031308) * (12.92 * var_X[i])) * 255.0
      / 255.0;
    var_R[i] = index;
  }

  memcpy((void *)&var_R_1[50], (void *)&var_G[0], 50U * sizeof(real_T));
  for (i = 0; i < 50; i++) {
    var_R_1[i + 100] = var_X[i];
    var_R_0[i] = var_R[i];
  }

  lfcbdbaaaaimmohl_max(var_R_1, color_count);

  /*  Max. value of RGB */
  /* '<S12>:1:91' */
  memcpy((void *)&var_R_0[50], (void *)&var_G[0], 50U * sizeof(real_T));
  memcpy((void *)&var_R_0[100], (void *)&var_X[0], 50U * sizeof(real_T));
  moppcbimnohdlfcb_min(var_R_0, tmp);

  /*  Delta RGB value */
  /*     H = (del_Max != 0).*(  ); */
  /*     S = (del_Max != 0).*( del_Max./var_Max ); */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg_1 = color_count[i] - tmp[i];
    ref_color_L_avg_0[i] = (ref_color_L_avg_1 == 0.0);
    ref_color_L_avg[i] = ref_color_L_avg_1;
  }

  dbaidbaafkfkbimo_abs(ref_color_L_avg_0, tmp_1);
  if (eknobiekkfcbppph_max(tmp_1) != 0.0) {
    /*  This is a gray, no chroma... */
    /* '<S12>:1:98' */
    memset((void *)&var_R[0], 0, 50U * sizeof(real_T));

    /*  HSV results from 0 to 1 */
  } else {
    /*  Chromatic data... */
    /* '<S12>:1:103' */
    /* '<S12>:1:104' */
    /* '<S12>:1:105' */
    /* '<S12>:1:108' */
    /* '<S12>:1:109' */
    for (i = 0; i < 50; i++) {
      index = ((color_count[i] - var_R[i]) / 6.0 + ref_color_L_avg[i] / 2.0) /
        ref_color_L_avg[i];
      k = ((color_count[i] - var_G[i]) / 6.0 + ref_color_L_avg[i] / 2.0) /
        ref_color_L_avg[i];
      ref_color_L_avg_1 = ((color_count[i] - var_X[i]) / 6.0 + ref_color_L_avg[i]
                           / 2.0) / ref_color_L_avg[i];
      index = (((0.33333333333333331 + index) - ref_color_L_avg_1) * (real_T)
               (var_G[i] == color_count[i]) + (real_T)(var_R[i] == color_count[i])
               * (ref_color_L_avg_1 - k)) + ((0.66666666666666663 + k) - index) *
        (real_T)(var_X[i] == color_count[i]);
      index = (real_T)(index < 0.0) * (index + 1.0) + (real_T)(index > 1.0) *
        (index - 1.0);
      var_R[i] = index;
    }
  }

  /*  Loop through blobs, and analyze and extract buoy information */
  /* '<S12>:1:118' */
  for (index = 1.0; index <= localB->blob_count; index++) {
    /* '<S12>:1:118' */
    /*  Store buoy information if blob conditions are met */
    /*    Conditions: 1) Blob eccentricity is within specified range */
    /*                2) Blob extent is within specified range */
    /*                3) Blob hue is within specified range for several buoy */
    /*                  types */
    /*  Consider blob geometry */
    if ((localB->blob_eccentricity[(int32_T)index - 1] >= 0.0) &&
        (localB->blob_eccentricity[(int32_T)index - 1] <= 1.2) &&
        (localB->blob_extent[(int32_T)index - 1] >= 0.1) && (localB->
         blob_extent[(int32_T)index - 1] <= 0.9)) {
      /* '<S12>:1:127' */
      /*  Determine buoy colors (hues) */
      /* '<S12>:1:130' */
      /* '<S12>:1:131' */
      /* '<S12>:1:133' */
      rtb_buoy_centroids[(int32_T)min_dist - 1] = localB->blob_centroids
        [(int32_T)index - 1];

      /* '<S12>:1:134' */
      rtb_buoy_centroids[(int32_T)min_dist + 49] = localB->blob_centroids
        [(int32_T)index + 49];

      /*  Classify buoy hue as a pre-defined color */
      /*    0 -> Unknown or not a valid buoy */
      /*    1 -> Red */
      /*    2 -> Green */
      /*    3 -> Blue */
      /*    4 -> Yellow */
      /* '<S12>:1:142' */
      ref_color_b_avg[(int32_T)min_dist - 1] = -1.0;
      if ((var_R[(int32_T)index - 1] >= -0.15) && (var_R[(int32_T)index - 1] <=
           0.15)) {
        /* '<S12>:1:143' */
        /* '<S12>:1:144' */
        ref_color_b_avg[(int32_T)min_dist - 1] = 1.0;
      } else if ((var_R[(int32_T)index - 1] >= 0.18000000000000002) && (var_R
                  [(int32_T)index - 1] <= 0.48)) {
        /* '<S12>:1:145' */
        /* '<S12>:1:146' */
        ref_color_b_avg[(int32_T)min_dist - 1] = 2.0;
      } else if ((var_R[(int32_T)index - 1] >= 0.51) && (var_R[(int32_T)index -
                  1] <= 0.81)) {
        /* '<S12>:1:147' */
        /* '<S12>:1:148' */
        ref_color_b_avg[(int32_T)min_dist - 1] = 3.0;
      } else {
        if ((var_R[(int32_T)index - 1] >= 0.020000000000000018) && (var_R
             [(int32_T)index - 1] <= 0.32)) {
          /* '<S12>:1:149' */
          /* '<S12>:1:150' */
          ref_color_b_avg[(int32_T)min_dist - 1] = 4.0;
        }
      }

      /* '<S12>:1:153' */
      min_dist++;

      /*         %{ */
      /*         % Consider blob color */
      /*         if( (blob_hues(i)>=Buoy1_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy1_Hue+Buoy_Hue_HalfRange) ) */
      /*         %if( (blob_hues(i)>=Buoy1_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy1_Hue+Buoy_Hue_HalfRange) ) */
      /*  */
      /*             buoy_id(buoy_count) = 1; */
      /*              */
      /*             buoy_count = buoy_count + 1; */
      /*              */
      /*             buoy_hues(buoy_count,1) = blob_hues(i,1); */
      /*             buoy_hues(buoy_count,2) = blob_hues(i,2); */
      /*             buoy_hues(buoy_count,3) = blob_hues(i,3); */
      /*              */
      /*             buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
      /*             buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
      /*         end */
      /*  */
      /*         %} */
      /*         %{ */
      /*         if( (blob_hues(i)>=Buoy2_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy2_Hue+Buoy_Hue_HalfRange) ) */
      /*             buoy_count = buoy_count + 1; */
      /*             buoy_hues(buoy_count) = blob_hues(i); */
      /*             buoy_id(buoy_count) = 2; */
      /*             buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
      /*             buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
      /*         end */
      /*         if( (blob_hues(i)>=Buoy3_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy3_Hue+Buoy_Hue_HalfRange) ) */
      /*             buoy_count = buoy_count + 1; */
      /*             buoy_hues(buoy_count) = blob_hues(i); */
      /*             buoy_id(buoy_count) = 3; */
      /*             buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
      /*             buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
      /*         end */
      /*         %} */
    }
  }

  /*  Resize output arrays */
  /* buoy_hues = buoy_hues(1:buoy_count); */
  /* buoy_centroids = buoy_centroids(1:buoy_count,:); */
  /* buoy_id = ; */

  /* Embedded MATLAB: '<Root>/Target appropriate buoy' */
  /* Embedded MATLAB Function 'Target appropriate buoy': '<S3>:1' */
  /*  Initialize */
  /* buoy_count_max = BuoyCountMax; */
  /* '<S3>:1:8' */
  (*rty_TargetSelect) = 1.0;

  /* '<S3>:1:9' */
  (*rty_TargetFound) = 1.0;

  /* '<S3>:1:10' */
  (*rty_MaintainHeading) = 1.0;

  /* '<S3>:1:11' */
  (*rty_TargetY) = 0.0;

  /* '<S3>:1:12' */
  (*rty_TargetZ) = 0.0;

  /* '<S3>:1:13' */
  (*rty_TargetYaw) = 0.0;

  /* '<S3>:1:14' */
  (*rty_TargetDetected) = 0.0;

  /* '<S3>:1:15' */
  memcpy((void *)(&rty_BuoyColors[0]), (void *)&ref_color_b_avg[0], 50U * sizeof
         (real_T));

  /*  Loop through all identified buoys */
  /* '<S3>:1:19' */
  for (i = 0; i < 10; i++) {
    /* '<S3>:1:19' */
    if (ref_color_b_avg[i] == (*rtu_WhichColor)) {
      /* '<S3>:1:20' */
      /* '<S3>:1:21' */
      (*rty_TargetDetected) = 1.0;

      /* '<S3>:1:22' */
      (*rty_TargetY) = rtb_buoy_centroids[i] - 80.0;

      /* '<S3>:1:23' */
      (*rty_TargetZ) = rtb_buoy_centroids[50 + i] - 60.0;
    }
  }
}

/* Model initialize function */
void mr_buoy_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_buoy_detector *const buoy_detector_M, rtB_mr_buoy_detector *localB,
  rtDW_mr_buoy_detector *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(buoy_detector_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_buoy_detector));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(rtDW_mr_buoy_detector));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
