/*
 * File: buoy_detector.cpp
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.1194
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Wed Jun 22 00:56:52 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Wed Jun 22 00:56:52 2011
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
 *    '<S6>/Low Pass Filter'
 *    '<S6>/Low Pass Filter1'
 *    '<S6>/Low Pass Filter2'
 */
void buoy_detector_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_buoy_detector *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S6>/Low Pass Filter' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S8>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S8>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S8>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S8>:1:19' */
  /* '<S8>:1:21' */
  /* '<S8>:1:23' */
  Gsum = 0.0;

  /* '<S8>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S8>:1:24' */
    /* '<S8>:1:25' */
    /* '<S8>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S8>:1:27' */
    Gsum += G[i + 1];

    /* '<S8>:1:25' */
    /* '<S8>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S8>:1:27' */
    Gsum += G[i + 4];

    /* '<S8>:1:25' */
    /* '<S8>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S8>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S8>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S8>:1:33' */
  fknoophdhdjeohdj_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S8>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S8>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S8>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S8>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S8>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S8>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S8>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S8>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S8>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Function for Embedded MATLAB: '<S3>/Blob Extraction' */
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

  /* InitializeConditions for Embedded MATLAB: '<S3>/Blob Extraction' */
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
                      *rty_TargetDetected, real_T rty_BuoyColors[50], real_T
                      rty_R[19200], real_T rty_G[19200], real_T rty_B[19200],
                      rtB_mr_buoy_detector *localB, rtDW_mr_buoy_detector
                      *localDW)
{
  int32_T i;
  int32_T idxROI;
  int32_T col;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T OutCode;
  int32_T OutCode_0;
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
  int8_T buoy_colors[50];
  boolean_T exitg;
  real_T Resize2_LineBuffer[160];
  real_T rtb_VectorConcatenate[2];
  real_T rtb_buoy_hues[150];
  real_T rtb_buoy_centroids[100];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;
  uint8_T tmp;
  real_T tmp_0;

  /* Embedded MATLAB: '<S6>/Low Pass Filter' */
  buoy_detector_LowPassFilter(rtu_R_forward_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S6>/Low Pass Filter1' */
  buoy_detector_LowPassFilter(rtu_G_forward_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S6>/Low Pass Filter2' */
  buoy_detector_LowPassFilter(rtu_B_forward_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion1' */
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

  /* S-Function (svipresize): '<S13>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 160; num_colors++) {
    idxROI = num_colors;
    for (i = 0; i < 80; i++) {
      OutCode_0 = i + 80;
      min_dist = localB->ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled6[i]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[i] +
        localB->ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled6[OutCode_0]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      OutCode_0 += 80;
      min_dist += localB->
        ColorSpaceConversion1_o1[buoy_detector_ConstP.pooled6[OutCode_0] * 160 +
        num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      localDW->Resize_IntBuffer[idxROI] = min_dist;
      idxROI += 160;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->Resize_IntBuffer[i
            * 160]), 160U * sizeof(real_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      OutCode_0 = num_colors;
      min_dist = 0.0;
      for (OutCode = 0; OutCode < 6; OutCode++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled5[OutCode_0]] *
          buoy_detector_ConstP.pooled2[OutCode_0];
        OutCode_0 += 60;
      }

      localB->Resize[j] = min_dist;
      j++;
    }
  }

  /* S-Function (svipresize): '<S13>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 160; num_colors++) {
    idxROI = num_colors;
    for (i = 0; i < 80; i++) {
      OutCode_0 = i + 80;
      min_dist = localB->ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled6[i]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[i] +
        localB->ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled6[OutCode_0]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      OutCode_0 += 80;
      min_dist += localB->
        ColorSpaceConversion1_o2[buoy_detector_ConstP.pooled6[OutCode_0] * 160 +
        num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      localDW->Resize1_IntBuffer[idxROI] = min_dist;
      idxROI += 160;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[i * 160]), 160U * sizeof(real_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      OutCode_0 = num_colors;
      min_dist = 0.0;
      for (OutCode = 0; OutCode < 6; OutCode++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled5[OutCode_0]] *
          buoy_detector_ConstP.pooled2[OutCode_0];
        OutCode_0 += 60;
      }

      localB->Resize1[j] = min_dist;
      j++;
    }
  }

  /* S-Function (svipresize): '<S13>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 160; num_colors++) {
    idxROI = num_colors;
    for (i = 0; i < 80; i++) {
      OutCode_0 = i + 80;
      min_dist = localB->ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled6[i]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[i] +
        localB->ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled6[OutCode_0]
        * 160 + num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      OutCode_0 += 80;
      min_dist += localB->
        ColorSpaceConversion1_o3[buoy_detector_ConstP.pooled6[OutCode_0] * 160 +
        num_colors] * buoy_detector_ConstP.pooled3[OutCode_0];
      localDW->Resize2_IntBuffer[idxROI] = min_dist;
      idxROI += 160;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[i * 160]), 160U * sizeof(real_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      OutCode_0 = num_colors;
      min_dist = 0.0;
      for (OutCode = 0; OutCode < 6; OutCode++) {
        min_dist += Resize2_LineBuffer[buoy_detector_ConstP.pooled5[OutCode_0]] *
          buoy_detector_ConstP.pooled2[OutCode_0];
        OutCode_0 += 60;
      }

      localB->Resize2[j] = min_dist;
      j++;
    }
  }

  /* Embedded MATLAB: '<S7>/Reference Color Selection' incorporates:
   *  Constant: '<S7>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/Reference Color Selection': '<S12>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S12>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S12>:1:14' */
  /* '<S12>:1:15' */
  memset((void *)(&localB->ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S12>:1:16' */
  memset((void *)(&localB->LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S12>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S12>:1:23' */
  localB->ref_colors[0] = localB->Resize[2369];
  localB->ref_colors[50] = localB->Resize1[2369];
  localB->ref_colors[100] = localB->Resize2[2369];

  /* '<S12>:1:25' */
  flag = 0;

  /* '<S12>:1:26' */
  i = 1;

  /* '<S12>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S12>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S12>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S12>:1:30' */
        /* '<S12>:1:31' */
        k = 1.0;

        /* '<S12>:1:32' */
        min_dist = 1000.0;

        /* '<S12>:1:33' */
        index = 1.0;
        while ((uint32_T)k <= (uint32_T)num_colors) {
          /* '<S12>:1:34' */
          /* '<S12>:1:35' */
          ii = sqrt((rt_pow_snf(localB->ref_colors[(int32_T)k + 49] -
                                localB->Resize1[(j - 1) * 60 + (i - 1)], 2.0) *
                     1.5 + rt_pow_snf(localB->ref_colors[(int32_T)k - 1] -
                      localB->Resize[(j - 1) * 60 + (i - 1)], 2.0)) + rt_pow_snf
                    (localB->ref_colors[(int32_T)k + 99] - localB->Resize2[(j -
                      1) * 60 + (i - 1)], 2.0) * 1.5);
          if (min_dist > ii) {
            /* '<S12>:1:36' */
            /* '<S12>:1:37' */
            min_dist = ii;

            /* '<S12>:1:38' */
            index = k;
          }

          /* '<S12>:1:40' */
          k++;
        }

        if ((min_dist > 30.0) && (num_colors < 50)) {
          /* '<S12>:1:45' */
          /* '<S12>:1:46' */
          localB->ref_colors[num_colors] = localB->Resize[(j - 1) * 60 + (i - 1)];
          localB->ref_colors[num_colors + 50] = localB->Resize1[(j - 1) * 60 +
            (i - 1)];
          localB->ref_colors[num_colors + 100] = localB->Resize2[(j - 1) * 60 +
            (i - 1)];

          /* '<S12>:1:47' */
          num_colors++;

          /* '<S12>:1:48' */
          flag = 1;

          /* '<S12>:1:49' */
          i = 0;

          /* '<S12>:1:50' */
          j = 0;
        } else {
          /* '<S12>:1:52' */
          localB->LabelMatrix_m[(i - 1) + 60 * (j - 1)] = (uint32_T)index;
        }

        /* '<S12>:1:54' */
        j++;
      }

      /* '<S12>:1:56' */
      j = 1;

      /* '<S12>:1:57' */
      i++;
    }

    /* '<S12>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S12>:1:63' */
  /* '<S12>:1:64' */
  /* '<S12>:1:65' */
  /* '<S12>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S12>:1:67' */
  for (j = 0; j < 60; j++) {
    /* '<S12>:1:67' */
    /* '<S12>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S12>:1:68' */
      /* '<S12>:1:69' */
      /* '<S12>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix_m[j + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix_m[60 * flag + j] - 1] +
        localB->Resize[60 * flag + j];

      /* '<S12>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix_m[j + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix_m[60 * flag + j] - 1] +
        localB->Resize1[60 * flag + j];

      /* '<S12>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix_m[j + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix_m[60 * flag + j] - 1] +
        localB->Resize2[60 * flag + j];

      /* '<S12>:1:73' */
      color_count[(int32_T)localB->LabelMatrix_m[j + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix_m[60 * flag + j] - 1] + 1.0;
    }
  }

  /* '<S12>:1:76' */
  /* '<S12>:1:77' */
  /* '<S12>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S12>:1:80' */
  for (min_dist = 1.0; (uint32_T)min_dist <= (uint32_T)num_colors; min_dist++) {
    /* '<S12>:1:80' */
    /* '<S12>:1:81' */
    localB->ref_colors[(int32_T)min_dist - 1] = ref_color_L_avg[(int32_T)
      min_dist - 1];

    /* '<S12>:1:82' */
    localB->ref_colors[(int32_T)min_dist + 49] = ref_color_a_avg[(int32_T)
      min_dist - 1];

    /* '<S12>:1:83' */
    localB->ref_colors[(int32_T)min_dist + 99] = ref_color_b_avg[(int32_T)
      min_dist - 1];
  }

  localB->num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<S7>/LabSegmentation' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/LabSegmentation': '<S11>:1' */
  /*  This function generates the label matrix */
  /* '<S11>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S11>:1:12' */
  for (i = 0; i < 160; i++) {
    /* '<S11>:1:12' */
    /* '<S11>:1:13' */
    for (j = 0; j < 120; j++) {
      /* '<S11>:1:13' */
      /* '<S11>:1:14' */
      min_dist = 1000.0;

      /* '<S11>:1:15' */
      index = 1.0;

      /* '<S11>:1:16' */
      for (k = 1.0; k <= localB->num_colors; k++) {
        /* '<S11>:1:16' */
        /* '<S11>:1:17' */
        ii = sqrt((rt_pow_snf(localB->ref_colors[(int32_T)k - 1] -
                              localB->ColorSpaceConversion1_o1[160 * j + i], 2.0)
                   + rt_pow_snf(localB->ref_colors[(int32_T)k + 49] -
                    localB->ColorSpaceConversion1_o2[160 * j + i], 2.0)) +
                  rt_pow_snf(localB->ref_colors[(int32_T)k + 99] -
                             localB->ColorSpaceConversion1_o3[160 * j + i], 2.0));
        if (ii < min_dist) {
          /* '<S11>:1:18' */
          /* '<S11>:1:19' */
          min_dist = ii;

          /* '<S11>:1:20' */
          index = k;
        }
      }

      /* '<S11>:1:23' */
      localB->LabelMatrix[i + 160 * j] = index;
    }
  }

  /* '<S11>:1:27' */

  /* Embedded MATLAB: '<S3>/Blob Extraction' */
  min_dist = localB->num_colors;

  /* Embedded MATLAB Function 'Look for Buoys/Blob Extraction': '<S14>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /*  */
  /*  Input */
  /*    LabelMatrix = 2-D matrix of integer values, each of which represents a */
  /*      color; location in matrix corresponds to pixel location in image */
  /*    ref_colors = Nx3 color table containing Lab components */
  /*    num_colors = integer number of colors present in LabelMatrix */
  /*    Buoy_Count_Max = maximum number of blobs that will be analyzed */
  /*  */
  /*  Output */
  /*    blob_count = integer number of blobs in image */
  /*    blob_hues = Nx3 vector of hues of blobs in image */
  /*    blob_centroids = Nx2 matrix of x-y pairs of blob centroid locations */
  /*    blob_eccentricity = Nx1 vector of blob eccentricites */
  /*    blob_extent = Nx1 vector of blob extents */
  /*  Initialize */
  /* '<S14>:1:22' */
  /* '<S14>:1:24' */
  for (i = 0; i < 19200; i++) {
    localB->LogicMatrix[i] = FALSE;
  }

  /* '<S14>:1:28' */
  memset((void *)(&localB->blob_hues[0]), 0, 150U * sizeof(real_T));

  /* '<S14>:1:29' */
  memset((void *)(&localB->blob_centroids[0]), 0, 100U * sizeof(real_T));

  /* '<S14>:1:30' */
  /* '<S14>:1:31' */
  for (i = 0; i < 50; i++) {
    localB->blob_eccentricity[i] = 0.0;
    localB->blob_extent[i] = 0.0;
  }

  /* '<S14>:1:33' */
  index = 0.0;

  /* uint8(0); */
  /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
  /*  identified blob */
  /* % Calculate geometric information about the blobs */
  /*  */
  /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
  /*    locations for which color values are k, and zeros everywhere else */
  /* '<S14>:1:49' */
  for (k = 1.0; k <= min_dist; k++) {
    /* '<S14>:1:49' */
    /* '<S14>:1:50' */
    for (i = 0; i < 160; i++) {
      /* '<S14>:1:50' */
      /* '<S14>:1:51' */
      for (j = 0; j < 120; j++) {
        /* '<S14>:1:51' */
        if (localB->LabelMatrix[160 * j + i] != k) {
          /* '<S14>:1:52' */
          /* '<S14>:1:53' */
          localB->LogicMatrix[i + 160 * j] = FALSE;
        } else {
          /* '<S14>:1:55' */
          localB->LogicMatrix[i + 160 * j] = TRUE;
        }
      }
    }

    buoy_detector_Outputs(&localB->LogicMatrix[0], rtb_buoy_centroids,
                          ref_color_L_avg, ref_color_a_avg, &TNumBlobs, localDW);
    tmp_0 = floor((index + (real_T)TNumBlobs) + 0.5);
    if (tmp_0 < 256.0) {
      tmp = (uint8_T)tmp_0;
    } else {
      tmp = MAX_uint8_T;
    }

    if (tmp < 50) {
      /* '<S14>:1:61' */
      /* '<S14>:1:62' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S14>:1:62' */
        /* '<S14>:1:64' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_centroids[tmp - 1] = rtb_buoy_centroids[(b_i - 1) << 1];

        /* '<S14>:1:65' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_centroids[tmp + 49] = rtb_buoy_centroids[((b_i - 1) << 1) +
          1];

        /* '<S14>:1:66' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_eccentricity[tmp - 1] = ref_color_L_avg[b_i - 1];

        /* '<S14>:1:67' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_extent[tmp - 1] = ref_color_a_avg[b_i - 1];

        /* '<S14>:1:69' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        ii = localB->blob_centroids[tmp - 1];
        moppaaaadjecnopp_refp1_round(&ii);

        /* '<S14>:1:70' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        jj = localB->blob_centroids[tmp + 49];
        moppaaaadjecnopp_refp1_round(&jj);

        /* '<S14>:1:71' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_hues[tmp - 1] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] - 1];

        /* '<S14>:1:72' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_hues[tmp + 49] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] + 49];

        /* '<S14>:1:73' */
        tmp_0 = floor((index + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        localB->blob_hues[tmp + 99] = localB->ref_colors[(int32_T)
          localB->LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)ii - 1)] + 99];
      }

      /* '<S14>:1:76' */
      index++;

      /* TNumBlobs; */
    }
  }

  localB->blob_count = index;

  /* Embedded MATLAB: '<S3>/Shape Analysis' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   */
  /* Embedded MATLAB Function 'Look for Buoys/Shape Analysis': '<S16>:1' */
  /*  This function takes in vectors representing blobs present in the image, */
  /*    and returns information about how many and what kind of buoys are */
  /*    present. Buoys are identified by shape only. */
  /*  */
  /*  Input */
  /*    ref_colors = Nx3 color table containing Lab components */
  /*    blob_count = integer number of blobs in image */
  /*    blob_hues = Nx3 vector of hues of blobs in image (values are Lab */
  /*      components) */
  /*    blob_centroids = Nx2 matrix of x-y pairs of blob centroid locations */
  /*    blob_eccentricity = Nx1 vector of blob eccentricites */
  /*    blob_extent = Nx1 vector of blob extents */
  /*  */
  /*    Min_Hue,Max_Hue = Nx1 limits on valid buoy hues; hue is between 0 and 1 */
  /*    Min_Eccent,Max_Eccent = scalar limits on buoy eccentricity */
  /*    Min_Extent,Max_Extent = scalar limits on buoy extent */
  /*  */
  /*    Buoy_Count_Max = maximum number of buoys that will be analyzed */
  /*  */
  /*  Output */
  /*    buoy_count = integer number of buoys found in image */
  /*    buoy_hues = Nx1 vector of buoy colors */
  /*    buoy_centroids = Nx2 matrix of x-y pairs of buoy centroid locations */
  /*  Initialize */
  /* '<S16>:1:28' */
  index = 0.0;

  /* '<S16>:1:30' */
  memset((void *)&rtb_buoy_hues[0], 0, 150U * sizeof(real_T));

  /* '<S16>:1:31' */
  for (i = 0; i < 100; i++) {
    rtb_buoy_centroids[i] = -500.0;
  }

  /*  Initialize to points clearly not located in image */
  /*  Loop through blobs, and extract information about blobs shaped like buoys */
  /* '<S16>:1:35' */
  for (min_dist = 1.0; min_dist <= localB->blob_count; min_dist++) {
    /* '<S16>:1:35' */
    /*  Store buoy information if geometric conditions are met */
    /*    Conditions: 1) Blob eccentricity is within specified range */
    /*                2) Blob extent is within specified range */
    if ((localB->blob_eccentricity[(int32_T)min_dist - 1] >= 0.0) &&
        (localB->blob_eccentricity[(int32_T)min_dist - 1] <= 1.2) &&
        (localB->blob_extent[(int32_T)min_dist - 1] >= 0.6) &&
        (localB->blob_extent[(int32_T)min_dist - 1] <= 0.9)) {
      /* '<S16>:1:40' */
      /* '<S16>:1:42' */
      index++;

      /* '<S16>:1:44' */
      rtb_buoy_hues[(int32_T)index - 1] = localB->blob_hues[(int32_T)min_dist -
        1];

      /* '<S16>:1:45' */
      rtb_buoy_hues[(int32_T)index + 49] = localB->blob_hues[(int32_T)min_dist +
        49];

      /* '<S16>:1:46' */
      rtb_buoy_hues[(int32_T)index + 99] = localB->blob_hues[(int32_T)min_dist +
        99];

      /* '<S16>:1:48' */
      rtb_buoy_centroids[(int32_T)index - 1] = localB->blob_centroids[(int32_T)
        min_dist - 1];

      /* '<S16>:1:49' */
      rtb_buoy_centroids[(int32_T)index + 49] = localB->blob_centroids[(int32_T)
        min_dist + 49];
    }
  }

  /*  Resize output arrays */
  /* buoy_hues = buoy_hues(1:buoy_count); */
  /* buoy_centroids = buoy_centroids(1:buoy_count,:); */
  /* buoy_id = ; */

  /* Embedded MATLAB: '<Root>/Choose Buoy' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  /* Embedded MATLAB Function 'Choose Buoy': '<S1>:1' */
  /*  This function takes in vectors representing buoys present in the image, */
  /*    and decides which buoy to target. */
  /*  */
  /*  Input */
  /*    buoy_count = number of buoys identified in the image */
  /*    buoy_hues = Nx3 matrix of Lab components for each buoy */
  /*    buoy_centroids = Nx2 matrix of x-y pairs of buoy centroids */
  /*    ref_colors = Nx3 color table containing Lab components */
  /*    a_range, b_range = 2xN matrix of lower/upper bounds on a, b for each */
  /*      color */
  /*    which_color = which buoy color should be targeted; integer value */
  /*      represents: */
  /*                1 -> White */
  /*                2 -> Black */
  /*                3 -> Blue */
  /*                4 -> Red */
  /*                5 -> Orange */
  /*                6 -> Yellow */
  /*                7 -> Green */
  /*  */
  /*  Output */
  /*    target_select = input to MotionController.mdl, which selects which */
  /*      camera to use */
  /*    target_found = informs MotionController that a target is being tracked */
  /*    maintain_heading = instructs MotionController to strafe xor turn: */
  /*                     = 0 -> Turn toward target (use targetYaw) */
  /*                     = 1 -> Strafe to target (use targetY) */
  /*    targetY, targetZ = position of buoy in absolute coordinates */
  /*    targetYaw = relative, lateral angular displacement of buoy from */
  /*      straight ahead (in degrees) */
  /*    target_detected = informs the script that a buoy is being tracked */
  /*    buoy_colors = vector of integers representing which color each buoy is, */
  /*      from left to right (same color scheme as which_color) */
  /*  Initialize */
  /* '<S1>:1:40' */
  (*rty_TargetSelect) = 1.0;

  /* '<S1>:1:41' */
  (*rty_TargetFound) = 1.0;

  /* '<S1>:1:42' */
  (*rty_MaintainHeading) = 0.0;

  /* '<S1>:1:43' */
  (*rty_TargetY) = 0.0;

  /* '<S1>:1:44' */
  (*rty_TargetZ) = 0.0;

  /* '<S1>:1:45' */
  (*rty_TargetYaw) = 0.0;

  /* '<S1>:1:46' */
  (*rty_TargetDetected) = 0.0;

  /* '<S1>:1:47' */
  for (i = 0; i < 50; i++) {
    buoy_colors[i] = 0;
  }

  /* '<S1>:1:48' */
  /* '<S1>:1:49' */
  /*  Classify each buoy by color */
  /* '<S1>:1:53' */
  for (min_dist = 1.0; min_dist <= index; min_dist++) {
    /* '<S1>:1:53' */
    /* '<S1>:1:55' */
    /* '<S1>:1:56' */
    /* '<S1>:1:58' */
    col = 1;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (col <= 7)) {
      /* '<S1>:1:58' */
      if ((rtb_buoy_hues[(int32_T)min_dist + 49] >=
           buoy_detector_ConstP.Constant_Value[((col - 1) << 1)]) &&
          (rtb_buoy_hues[(int32_T)min_dist + 49] <=
           buoy_detector_ConstP.Constant_Value[((col - 1) << 1) + 1]) &&
          (rtb_buoy_hues[(int32_T)min_dist + 99] >=
           buoy_detector_ConstP.Constant1_Value_i[((col - 1) << 1)]) &&
          (rtb_buoy_hues[(int32_T)min_dist + 99] <=
           buoy_detector_ConstP.Constant1_Value_i[((col - 1) << 1) + 1])) {
        /* '<S1>:1:59' */
        /* '<S1>:1:60' */
        buoy_colors[(int32_T)min_dist - 1] = (int8_T)col;
        exitg = TRUE;
      } else {
        col++;
      }
    }
  }

  /*  Examine buoys from left to right; if one has the correct color, then */
  /*    target it; else do not recognize a target */
  /* '<S1>:1:70' */
  min_dist = 1.0;
  exitg = FALSE;
  while (((uint32_T)exitg == 0U) && (min_dist <= index)) {
    /* '<S1>:1:70' */
    if ((real_T)buoy_colors[(int32_T)min_dist - 1] == (*rtu_WhichColor)) {
      /* '<S1>:1:71' */
      /* '<S1>:1:72' */
      (*rty_TargetY) = rtb_buoy_centroids[(int32_T)min_dist + 49] - 60.0;

      /* '<S1>:1:73' */
      (*rty_TargetZ) = rtb_buoy_centroids[(int32_T)min_dist - 1] - 80.0;

      /* '<S1>:1:74' */
      /* '<S1>:1:75' */
      exitg = TRUE;
    } else {
      min_dist++;
    }
  }

  /* { */
  /*  */
  /* buoy_hues = double(zeros(Buoy_Count_Max,1)); */
  /* buoy_centroids = double(-500.*ones(Buoy_Count_Max,2));  % Initialize to points clearly not located in image */
  /*  */
  /* buoy_id = double(-1.*ones(Buoy_Count_Max,1)); */
  /* Buoy_Hue_HalfRange = 10; */
  /* Buoy1_Hue = 30; */
  /* Buoy2_Hue = 80; */
  /* Buoy3_Hue = 15; */
  /*  */
  /*  Loop through blobs, and analyze and extract buoy information */
  /* for i = 1:blob_count */
  /*      */
  /*     % Convert Lab to XYZ */
  /*     R = buoy_hues(i); */
  /*     G = buoy_hues(i); */
  /*     B = buoy_hues(i); */
  /*      */
  /*     L = blob_hues(:,1); %refcolors(LabelMatrix(1,1,1)); */
  /*     a = blob_hues(:,2); */
  /*     b = blob_hues(:,3); */
  /*      */
  /*     var_Y = L./10; */
  /*     var_X = ( a./17.5 ).*( L./10 ); */
  /*     var_Z = ( b./7 ).*( L./10 ); */
  /*      */
  /*     Y = var_Y.^2; */
  /*     X = ( var_X + Y )./1.02; */
  /*     Z = -( var_Z - Y )./0.847; */
  /*      */
  /*     % Convert XYZ to RGB */
  /*     var_X = X./100;        %X from 0 to  95.047      (Observer = 2 degrees, Illuminant = D65) */
  /*     var_Y = Y./100;        %Y from 0 to 100.000 */
  /*     var_Z = Z./100;        %Z from 0 to 108.883 */
  /*      */
  /*     var_R = var_X.*3.2406 + var_Y.*(-1.5372) + var_Z.* -0.4986; */
  /*     var_G = var_X .* -0.9689 + var_Y .*  1.8758 + var_Z.*  0.0415; */
  /*     var_B = var_X .*  0.0557 + var_Y .* -0.2040 + var_Z .*  1.0570; */
  /*      */
  /*     var_R = ( var_R > 0.0031308 ).*( 1.055.*( var_R.^( 1./2.4 ) ) - 0.055 ) + ( var_R <= 0.0031308 ).*(12.92.*var_R); */
  /*     var_G = ( var_G > 0.0031308 ).*( 1.055.*( var_G.^( 1./2.4 ) ) - 0.055 ) + ( var_G <= 0.0031308 ).*( var_G <= 12.92.*var_G ); */
  /*     var_B = ( var_B > 0.0031308 ).*( 1.055 .* ( var_B .^ ( 1 ./ 2.4 ) ) - 0.055 ) + ( var_B <= 0.0031308 ).*( 12.92 .* var_B ); */
  /*      */
  /*     R = var_R .* 255; */
  /*     G = var_G .* 255; */
  /*     B = var_B .* 255; */
  /*      */
  /*     % Convert RGB to HSV */
  /*     var_R = ( R ./ 255 );  % RGB from 0 to 255 */
  /*     var_G = ( G ./ 255 ); */
  /*     var_B = ( B ./ 255 ); */
  /*      */
  /*     var_Min = min( [var_R, var_G, var_B], [], 2 );  % Min. value of RGB */
  /*     var_Max = max( [var_R, var_G, var_B], [], 2 );  % Max. value of RGB */
  /*     del_Max = var_Max - var_Min;  % Delta RGB value */
  /*      */
  /*     V = var_Max; */
  /*      */
  /*     H = (del_Max != 0).*(  ); */
  /*     S = (del_Max != 0).*( del_Max./var_Max ); */
  /*     if ( max(abs(del_Max == 0)) );  % This is a gray, no chroma... */
  /*         H = zeros(size(var_R));  % HSV results from 0 to 1 */
  /*         S = zeros(size(var_R)); */
  /*     else  % Chromatic data... */
  /*          */
  /*         S = del_Max ./ var_Max; */
  /*          */
  /*         del_R = ( ( ( var_Max - var_R ) ./ 6 ) + ( del_Max ./ 2 ) ) ./ del_Max; */
  /*         del_G = ( ( ( var_Max - var_G ) ./ 6 ) + ( del_Max ./ 2 ) ) ./ del_Max; */
  /*         del_B = ( ( ( var_Max - var_B ) ./ 6 ) + ( del_Max ./ 2 ) ) ./ del_Max; */
  /*          */
  /*         H = ( var_R == var_Max ).*( del_B - del_G ) + ( var_G == var_Max ).*( ( 1 ./ 3 ) + del_R - del_B ) + ( var_B == var_Max ).*( ( 2 ./ 3 ) + del_G - del_R ); */
  /*         H = ( H < 0 ).*( H + 1 ) + ( H > 1 ).*( H - 1 ); */
  /*          */
  /* {         */
  /*         if( var_R == var_Max ) */
  /*             H = del_B - del_G; */
  /*         elseif( var_G == var_Max ) */
  /*             H = ( 1 ./ 3 ) + del_R - del_B; */
  /*         elseif( var_B == var_Max ) */
  /*             H = ( 2 ./ 3 ) + del_G - del_R; */
  /*         else */
  /*             H = 0; */
  /*         end */
  /*          */
  /*         if( H < 0 ) */
  /*             H = H + 1; */
  /*         end */
  /*         if( H > 1 ) */
  /*             H = H - 1; */
  /*         end */
  /* }         */
  /*     end */
  /*      */
  /*     % Store buoy information if blob conditions are met */
  /*     %   Conditions: 1) Blob eccentricity is within specified range */
  /*     %               2) Blob extent is within specified range */
  /*     %               3) Blob hue is within specified range for several buoy */
  /*     %                 types */
  /*     if( (blob_eccentricity(i)>=Min_Eccent) && (blob_eccentricity(i)<=Max_Eccent) && (blob_extent(i)>=Min_Extent) && (blob_extent(i)<=Max_Extent) ) */
  /*          */
  /*         %if( (blob_hues(i)>=Buoy1_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy1_Hue+Buoy_Hue_HalfRange) ) */
  /*             buoy_count = buoy_count + 1; */
  /*             buoy_hues(buoy_count) = blob_hues(i); */
  /*             buoy_id(buoy_count) = 1; */
  /*             buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
  /*             buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
  /*         %end */
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
  /*     end */
  /*      */
  /* end */
  /*  */
  /*  Resize output arrays */
  /* buoy_hues = buoy_hues(1:buoy_count); */
  /* buoy_centroids = buoy_centroids(1:buoy_count,:); */
  /* buoy_id = ; */
  /*  */
  /* } */
  for (i = 0; i < 50; i++) {
    rty_BuoyColors[i] = (real_T)buoy_colors[i];
  }

  /* Embedded MATLAB: '<Root>/Transform Coordinates1' */
  /* Embedded MATLAB Function 'Transform Coordinates1': '<S4>:1' */
  /* '<S4>:1:9' */
  /* '<S4>:1:10' */
  /* '<S4>:1:11' */
  /* '<S4>:1:13' */
  for (j = 0; j < 160; j++) {
    /* '<S4>:1:13' */
    /* '<S4>:1:14' */
    for (flag = 0; flag < 120; flag++) {
      /* '<S4>:1:14' */
      /* '<S4>:1:15' */
      localB->L[j + 160 * flag] = localB->ref_colors[(int32_T)
        localB->LabelMatrix[160 * flag + j] - 1];

      /* '<S4>:1:16' */
      localB->a[j + 160 * flag] = localB->ref_colors[(int32_T)
        localB->LabelMatrix[160 * flag + j] + 49];

      /* '<S4>:1:17' */
      localB->b[j + 160 * flag] = localB->ref_colors[(int32_T)
        localB->LabelMatrix[160 * flag + j] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 19200; i++) {
    k = (localB->L[i] + 16.0) / 116.0;
    jj = localB->a[i] / 500.0 + k;
    min_dist = localB->b[i] / -200.0 + k;
    if (jj <= 0.20689655172413793) {
      jj -= 0.13793103448275862;
      jj /= 7.7870370370370372;
    } else {
      jj = rt_pow_snf(jj, 3.0);
    }

    if (k <= 0.20689655172413793) {
      k -= 0.13793103448275862;
      k /= 7.7870370370370372;
    } else {
      k = rt_pow_snf(k, 3.0);
    }

    if (min_dist <= 0.20689655172413793) {
      min_dist -= 0.13793103448275862;
      min_dist /= 7.7870370370370372;
    } else {
      min_dist = rt_pow_snf(min_dist, 3.0);
    }

    jj *= 0.9641986557609;
    min_dist *= 0.82511648322104;

    /* assign the results */
    localB->ColorSpaceConversion1_o1_e[i] = jj;
    localB->ColorSpaceConversion1_o2_d[i] = k;
    localB->ColorSpaceConversion1_o3_n[i] = min_dist;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    jj = (3.24096994190451 * localB->ColorSpaceConversion1_o1_e[i] +
          -1.53738317757009 * localB->ColorSpaceConversion1_o2_d[i]) +
      -0.49861076029299 * localB->ColorSpaceConversion1_o3_n[i];
    k = (-0.96924363628087 * localB->ColorSpaceConversion1_o1_e[i] +
         1.87596750150771 * localB->ColorSpaceConversion1_o2_d[i]) +
      0.04155505740718 * localB->ColorSpaceConversion1_o3_n[i];
    min_dist = (0.055630079697 * localB->ColorSpaceConversion1_o1_e[i] +
                -0.20397695888899 * localB->ColorSpaceConversion1_o2_d[i]) +
      1.05697151424288 * localB->ColorSpaceConversion1_o3_n[i];

    /* Apply gamma correction to get R'G'B' */
    if (jj <= 0.00304) {
      jj *= 12.923054468333255;
    } else {
      jj = 1.0550005198172263 * rt_pow_snf(jj, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (k <= 0.00304) {
      k *= 12.923054468333255;
    } else {
      k = 1.0550005198172263 * rt_pow_snf(k, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (min_dist <= 0.00304) {
      min_dist *= 12.923054468333255;
    } else {
      min_dist = 1.0550005198172263 * rt_pow_snf(min_dist, 0.41666666666666669)
        - 0.055000519817226347;
    }

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
    localB->ColorSpaceConversion1_o1_e[i] = jj;
    localB->ColorSpaceConversion1_o2_d[i] = k;
    localB->ColorSpaceConversion1_o3_n[i] = min_dist;
  }

  /* Embedded MATLAB: '<Root>/Transform Coordinates3' incorporates:
   *  Constant: '<Root>/ModeSelect1'
   */
  /* Embedded MATLAB Function 'Transform Coordinates3': '<S5>:1' */
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
  /* '<S5>:1:21' */
  /* '<S5>:1:22' */
  rtb_VectorConcatenate[0] = (*rty_TargetZ) + 80.0;

  /* '<S5>:1:23' */
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
    rty_R[i] = localB->ColorSpaceConversion1_o1_e[i];
    rty_G[i] = localB->ColorSpaceConversion1_o2_d[i];
    rty_B[i] = localB->ColorSpaceConversion1_o3_n[i];
  }

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 2; idxROI += 2) {
    tmp_0 = rtb_VectorConcatenate[idxROI];
    if ((rtb_VectorConcatenate[idxROI] < 4.503599627370496E+15) &&
        (rtb_VectorConcatenate[idxROI] > -4.503599627370496E+15)) {
      tmp_0 = floor(rtb_VectorConcatenate[idxROI] + 0.5);
    }

    i = (int32_T)tmp_0;
    tmp_0 = rtb_VectorConcatenate[idxROI + 1];
    if ((rtb_VectorConcatenate[idxROI + 1] < 4.503599627370496E+15) &&
        (rtb_VectorConcatenate[idxROI + 1] > -4.503599627370496E+15)) {
      tmp_0 = floor(rtb_VectorConcatenate[idxROI + 1] + 0.5);
    }

    col = (int32_T)tmp_0;
    line_idx_2 = i - 7;
    line_idx_1 = col - 7;
    line_idx_0 = i + 7;
    line_idx = col + 7;
    exitg = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_6 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      OutCode = 0;
      OutCode_0 = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_6 > 159) {
          OutCode = 8;
        }
      }

      if (line_idx_4 < 0) {
        OutCode_0 = 4;
      } else {
        if (line_idx_4 > 159) {
          OutCode_0 = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_5 > 119) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (line_idx_3 < 0) {
        OutCode_0 = (int32_T)((uint32_T)OutCode_0 | 1U);
      } else {
        if (line_idx_3 > 119) {
          OutCode_0 = (int32_T)((uint32_T)OutCode_0 | 2U);
        }
      }

      if (!((uint32_T)OutCode | (uint32_T)OutCode_0)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        exitg = TRUE;
      } else if ((uint32_T)OutCode & (uint32_T)OutCode_0) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        exitg = FALSE;
      } else if ((uint32_T)OutCode != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_6 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)OutCode & 4U) {
          /* Violated RMin. */
          num_colors = (0 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited = TRUE;
        } else if ((uint32_T)OutCode & 8U) {
          /* Violated RMax. */
          num_colors = (159 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited = TRUE;
        } else if ((uint32_T)OutCode & 1U) {
          /* Violated CMin. */
          num_colors = (0 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          num_colors = (119 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
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
        if ((uint32_T)OutCode_0 & 4U) {
          /* Violated RMin. */
          num_colors = (0 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode_0 & 8U) {
          /* Violated RMax. */
          num_colors = (159 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode_0 & 1U) {
          /* Violated CMin. */
          num_colors = (0 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          num_colors = (119 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (exitg) {
      j = line_idx_5 * 160 + line_idx_6;
      for (num_colors = line_idx_6; num_colors <= line_idx_4; num_colors++) {
        rty_R[j] = 0.0;
        rty_G[j] = 0.0;
        rty_B[j] = 0.0;
        j += 161;
      }
    }

    line_idx_2 = i - 7;
    line_idx_1 = col + 7;
    line_idx_0 = i + 7;
    line_idx = col - 7;
    exitg = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_6 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      OutCode = 0;
      OutCode_0 = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_6 > 159) {
          OutCode = 8;
        }
      }

      if (line_idx_4 < 0) {
        OutCode_0 = 4;
      } else {
        if (line_idx_4 > 159) {
          OutCode_0 = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_5 > 119) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (line_idx_3 < 0) {
        OutCode_0 = (int32_T)((uint32_T)OutCode_0 | 1U);
      } else {
        if (line_idx_3 > 119) {
          OutCode_0 = (int32_T)((uint32_T)OutCode_0 | 2U);
        }
      }

      if (!((uint32_T)OutCode | (uint32_T)OutCode_0)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        exitg = TRUE;
      } else if ((uint32_T)OutCode & (uint32_T)OutCode_0) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        exitg = FALSE;
      } else if ((uint32_T)OutCode != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_6 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        flag = line_idx_4 - line_idx_6;
        j = line_idx_3 - line_idx_5;
        if ((uint32_T)OutCode & 4U) {
          /* Violated RMin. */
          num_colors = (0 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited = TRUE;
        } else if ((uint32_T)OutCode & 8U) {
          /* Violated RMax. */
          num_colors = (159 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited = TRUE;
        } else if ((uint32_T)OutCode & 1U) {
          /* Violated CMin. */
          num_colors = (0 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          num_colors = (119 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
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
        if ((uint32_T)OutCode_0 & 4U) {
          /* Violated RMin. */
          num_colors = (0 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode_0 & 8U) {
          /* Violated RMax. */
          num_colors = (159 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode_0 & 1U) {
          /* Violated CMin. */
          num_colors = (0 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          num_colors = (119 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (exitg) {
      j = line_idx_5 * 160 + line_idx_6;
      for (num_colors = line_idx_6; num_colors <= line_idx_4; num_colors++) {
        rty_R[j] = 0.0;
        rty_G[j] = 0.0;
        rty_B[j] = 0.0;
        j += -159;
      }
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
