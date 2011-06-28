/*
 * color_palette_v3.cpp
 *
 * Real-Time Workshop code generation for Simulink model "color_palette_v3.mdl".
 *
 * Model version              : 1.871
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Mon Jun 27 12:45:58 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "color_palette_v3.h"
#include "color_palette_v3_private.h"

/* Block signals (auto storage) */
BlockIO_color_palette_v3 color_palette_v3_B;

/* Block states (auto storage) */
D_Work_color_palette_v3 color_palette_v3_DWork;

/* Real-time model */
RT_MODEL_color_palette_v3 color_palette_v3_M_;
RT_MODEL_color_palette_v3 *color_palette_v3_M = &color_palette_v3_M_;

/* Forward declaration for local functions */
static void color_palette_v3_conv2(const real_T arg1[19200], const real_T arg2[9],
  real_T c[18644]);

/* Forward declaration for local functions */
static void color_palette_v3_Outputs(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8);
static void color_palette_v3_refp1_round(real_T *x);

/* Function for Embedded MATLAB: '<S10>/Low Pass Filter' */
static void color_palette_v3_conv2(const real_T arg1[19200], const real_T arg2[9],
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
  for (jc = 0; jc < 118; jc++) {
    j = jc + 3;
    jp = j + 1;
    ja = jp - 3;
    for (ic = 0; ic < 158; ic++) {
      i = ic + 3;
      ip = i + 1;
      ia = ip - 3;
      s = 0.0;
      for (ja_0 = ja; ja_0 <= j; ja_0++) {
        jb = jp - ja_0;
        for (ia_0 = ia; ia_0 <= i; ia_0++) {
          s += arg1[(ja_0 - 1) * 160 + (ia_0 - 1)] * arg2[((ip - ia_0) - 1) +
            (jb - 1) * 3];
        }
      }

      c[ic + 158 * jc] = s;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S10>/Low Pass Filter'
 *    '<S10>/Low Pass Filter1'
 *    '<S10>/Low Pass Filter2'
 */
void color_palette_v3_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_color_palette *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S10>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S12>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S12>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S12>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S12>:1:19' */
  /* '<S12>:1:21' */
  /* '<S12>:1:23' */
  Gsum = 0.0;

  /* '<S12>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S12>:1:24' */
    /* '<S12>:1:25' */
    /* '<S12>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S12>:1:27' */
    Gsum += G[i + 1];

    /* '<S12>:1:25' */
    /* '<S12>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S12>:1:27' */
    Gsum += G[i + 4];

    /* '<S12>:1:25' */
    /* '<S12>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S12>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S12>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S12>:1:33' */
  color_palette_v3_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S12>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S12>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S12>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S12>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S12>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S12>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S12>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S12>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S12>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Function for Embedded MATLAB: '<S1>/Blob Extraction' */
static void color_palette_v3_Outputs(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8)
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
  real_T uxy;
  real_T common;
  real_T minorAxis;
  real_T majorAxisLen;
  real_T centroid_idx;
  real_T centroid_idx_0;

  /* System object Outputs function: video.BlobAnalysis */
  maxNumBlobsReached = FALSE;
  memset((void *)(&color_palette_v3_DWork.PAD_DW[0]), (int32_T)0U, 163U * sizeof
         (uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 163;
  for (n = 0; n < 120; n++) {
    for (maxc = 0; maxc < 160; maxc++) {
      color_palette_v3_DWork.PAD_DW[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    color_palette_v3_DWork.PAD_DW[idx] = 0U;
    idx++;
    color_palette_v3_DWork.PAD_DW[idx] = 0U;
    idx++;
  }

  memset((void *)(&color_palette_v3_DWork.PAD_DW[idx]), (int32_T)0U, 161U *
         sizeof(uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 120; n++) {
    maxc = 1;
    idx = loop * 162;
    for (maxr = 0; maxr < 160; maxr++) {
      k = (uint32_T)(idx + maxc);
      start_pixIdx = pixIdx;
      if (color_palette_v3_DWork.PAD_DW[k] == 255) {
        color_palette_v3_DWork.PAD_DW[k] = currentLabel;
        color_palette_v3_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)(loop - 1);
        color_palette_v3_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)(maxc - 1);
        pixIdx++;
        color_palette_v3_DWork.NUM_PIX_DW[currentLabel - 1] = 1U;
        color_palette_v3_DWork.STACK_DW[stackIdx] = k;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          k = color_palette_v3_DWork.STACK_DW[stackIdx];
          for (j = 0; j < 8; j++) {
            walkerIdx = k + (uint32_T)color_palette_v3_DWork.WALKER_RTP[j];
            if (color_palette_v3_DWork.PAD_DW[walkerIdx] == 255) {
              color_palette_v3_DWork.PAD_DW[walkerIdx] = currentLabel;
              color_palette_v3_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 162U) - 1);
              color_palette_v3_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx %
                162U - 1U);
              pixIdx++;
              color_palette_v3_DWork.NUM_PIX_DW[currentLabel - 1] =
                color_palette_v3_DWork.NUM_PIX_DW[currentLabel - 1] + 1U;
              color_palette_v3_DWork.STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (color_palette_v3_DWork.NUM_PIX_DW[currentLabel - 1] <
            color_palette_v3_DWork.MINAREA_RTP) {
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
  *Y8 = (uint8_T)numBlobs;
  pixListMinc = 0;
  pixListNinc = 0;
  for (c_i = 0; c_i < numBlobs; c_i++) {
    Y0[c_i] = (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i];
    loop = 0;
    n = 0;
    for (j = 0; j < (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i]; j++) {
      loop += color_palette_v3_DWork.N_PIXLIST_DW[j + pixListNinc];
      n += color_palette_v3_DWork.M_PIXLIST_DW[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)color_palette_v3_DWork.NUM_PIX_DW[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)
      color_palette_v3_DWork.NUM_PIX_DW[c_i];
    Y1[c_i << 1] = centroid_idx;
    Y1[(c_i << 1) + 1] = centroid_idx_0;
    n = 120;
    idx = 160;
    maxc = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i]; j++) {
      loop = j + pixListNinc;
      if (color_palette_v3_DWork.N_PIXLIST_DW[loop] < n) {
        n = color_palette_v3_DWork.N_PIXLIST_DW[loop];
      }

      if (color_palette_v3_DWork.N_PIXLIST_DW[loop] > maxc) {
        maxc = color_palette_v3_DWork.N_PIXLIST_DW[loop];
      }

      loop = j + pixListMinc;
      if (color_palette_v3_DWork.M_PIXLIST_DW[loop] < idx) {
        idx = color_palette_v3_DWork.M_PIXLIST_DW[loop];
      }

      if (color_palette_v3_DWork.M_PIXLIST_DW[loop] > maxr) {
        maxr = color_palette_v3_DWork.M_PIXLIST_DW[loop];
      }
    }

    maxr = (maxr + 1) - idx;
    j = (maxc + 1) - n;
    loop = c_i << 2;
    Y2[loop] = idx;
    Y2[loop + 1] = n;
    Y2[loop + 2] = maxr;
    Y2[loop + 3] = j;
    xs = 0.0;
    ys = 0.0;
    xys = 0.0;
    for (k = 0U; (int32_T)k < (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i]; k
         ++) {
      uxy = (real_T)color_palette_v3_DWork.N_PIXLIST_DW[pixListNinc + (int32_T)k]
        - centroid_idx_0;
      common = (real_T)color_palette_v3_DWork.M_PIXLIST_DW[pixListMinc +
        (int32_T)k] - centroid_idx;
      xs += uxy * uxy;
      ys += common * common;
      xys += uxy * (-common);
    }

    centroid_idx = xs / (real_T)color_palette_v3_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    centroid_idx_0 = ys / (real_T)color_palette_v3_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    uxy = xys / (real_T)color_palette_v3_DWork.NUM_PIX_DW[c_i];
    common = sqrt((centroid_idx - centroid_idx_0) * (centroid_idx -
      centroid_idx_0) + uxy * uxy * 4.0);
    xs = ((centroid_idx + centroid_idx_0) + common) * 8.0;
    minorAxis = ((centroid_idx + centroid_idx_0) - common) * 8.0;
    majorAxisLen = sqrt(xs);
    ys = sqrt(xs - minorAxis) / majorAxisLen;
    if (centroid_idx_0 > centroid_idx) {
      xys = (centroid_idx_0 - centroid_idx) + common;
      xs = 2.0 * uxy;
    } else {
      xys = 2.0 * uxy;
      xs = (centroid_idx - centroid_idx_0) + common;
    }

    minorAxis = sqrt(minorAxis);
    Y3[c_i] = majorAxisLen;
    Y4[c_i] = minorAxis;
    Y5[c_i] = atan(xys / (xs + 2.2204460492503131E-16));
    Y6[c_i] = ys;
    Y7[c_i] = (real_T)color_palette_v3_DWork.NUM_PIX_DW[c_i] / (real_T)(maxr * j);
    pixListMinc += (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)color_palette_v3_DWork.NUM_PIX_DW[c_i];
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y0[loop] = color_palette_v3_DWork.F0_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y1[loop] = color_palette_v3_DWork.F1_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 2); loop < 200; loop++) {
    Y2[loop] = color_palette_v3_DWork.F2_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y3[loop] = color_palette_v3_DWork.F3_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y4[loop] = color_palette_v3_DWork.F4_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y5[loop] = color_palette_v3_DWork.F5_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y6[loop] = color_palette_v3_DWork.F6_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y7[loop] = color_palette_v3_DWork.F7_RTP;
  }
}

/* Function for Embedded MATLAB: '<S1>/Blob Extraction' */
static void color_palette_v3_refp1_round(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/* Model output function */
static void color_palette_v3_output(int_T tid)
{
  real_T cc;
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
  real_T dist;
  real_T ii;
  real_T jj;
  real_T k;
  uint8_T b_i;
  int32_T TArea[50];
  real_T TCentroid[100];
  int32_T TBBox[200];
  real_T TExtent[50];
  uint8_T TNumBlobs;
  real_T Resize2_LineBuffer[160];
  int32_T i;
  uint8_T tmp;
  for (i = 0; i < 19200; i++) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    color_palette_v3_B.Gain5[i] = color_palette_v3_P.Gain_Gain *
      color_palette_v3_P.Constant1_Value[i];

    /* Gain: '<S4>/Gain1' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    color_palette_v3_B.Gain4[i] = color_palette_v3_P.Gain1_Gain *
      color_palette_v3_P.Constant2_Value[i];

    /* Gain: '<S4>/Gain2' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    color_palette_v3_B.Gain3[i] = color_palette_v3_P.Gain2_Gain *
      color_palette_v3_P.Constant3_Value[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (color_palette_v3_B.Gain5[i] > color_palette_v3_B.Gain4[i]) {
      if (color_palette_v3_B.Gain4[i] < color_palette_v3_B.Gain3[i]) {
        min_dist = color_palette_v3_B.Gain4[i];
      } else {
        min_dist = color_palette_v3_B.Gain3[i];
      }

      if (color_palette_v3_B.Gain5[i] > color_palette_v3_B.Gain3[i]) {
        index = color_palette_v3_B.Gain5[i];
      } else {
        index = color_palette_v3_B.Gain3[i];
      }
    } else {
      if (color_palette_v3_B.Gain5[i] < color_palette_v3_B.Gain3[i]) {
        min_dist = color_palette_v3_B.Gain5[i];
      } else {
        min_dist = color_palette_v3_B.Gain3[i];
      }

      if (color_palette_v3_B.Gain4[i] > color_palette_v3_B.Gain3[i]) {
        index = color_palette_v3_B.Gain4[i];
      } else {
        index = color_palette_v3_B.Gain3[i];
      }
    }

    min_dist = index - min_dist;
    if (index != 0.0) {
      cc = min_dist / index;
    } else {
      cc = 0.0;
    }

    if (min_dist != 0.0) {
      if (color_palette_v3_B.Gain5[i] == index) {
        jj = (color_palette_v3_B.Gain4[i] - color_palette_v3_B.Gain3[i]) /
          min_dist;
      } else if (color_palette_v3_B.Gain4[i] == index) {
        jj = (color_palette_v3_B.Gain3[i] - color_palette_v3_B.Gain5[i]) /
          min_dist + 2.0;
      } else {
        jj = (color_palette_v3_B.Gain5[i] - color_palette_v3_B.Gain4[i]) /
          min_dist + 4.0;
      }

      jj /= 6.0;
      if (jj < 0.0) {
        jj++;
      }
    } else {
      jj = 0.0;
    }

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion1_o1_o[i] = jj;
    color_palette_v3_B.ColorSpaceConversion1_o2_k[i] = cc;
    color_palette_v3_B.ColorSpaceConversion1_o3_m[i] = index;
  }

  for (i = 0; i < 19200; i++) {
    /* Gain: '<S4>/Gain3' */
    color_palette_v3_B.Gain3[i] = color_palette_v3_P.Gain3_Gain *
      color_palette_v3_B.ColorSpaceConversion1_o1_o[i];

    /* Gain: '<S4>/Gain4' */
    color_palette_v3_B.Gain4[i] = color_palette_v3_P.Gain4_Gain *
      color_palette_v3_B.ColorSpaceConversion1_o2_k[i];

    /* Gain: '<S4>/Gain5' */
    color_palette_v3_B.Gain5[i] = color_palette_v3_P.Gain5_Gain *
      color_palette_v3_B.ColorSpaceConversion1_o3_m[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  jj = 0.0;
  cc = 0.0;
  ii = 0.0;
  for (i = 0; i < 19200; i++) {
    min_dist = 6.0 * color_palette_v3_B.Gain3[i];
    k = (real_T)(uint32_T)(min_dist - 1.3322676295501878E-15);
    min_dist -= k;
    index = 1.0 - color_palette_v3_B.Gain4[i];
    dist = 1.0 - color_palette_v3_B.Gain4[i] * min_dist;
    min_dist = color_palette_v3_B.Gain4[i] * min_dist + index;
    if (k == 0.0) {
      jj = 1.0;
      cc = min_dist;
      ii = index;
    } else if (k == 1.0) {
      jj = dist;
      cc = 1.0;
      ii = index;
    } else if (k == 2.0) {
      jj = index;
      cc = 1.0;
      ii = min_dist;
    } else if (k == 3.0) {
      jj = index;
      cc = dist;
      ii = 1.0;
    } else if (k == 4.0) {
      jj = min_dist;
      cc = index;
      ii = 1.0;
    } else {
      if (k == 5.0) {
        jj = 1.0;
        cc = index;
        ii = dist;
      }
    }

    if (jj > cc) {
      index = jj;
    } else {
      index = cc;
    }

    if (!(index > ii)) {
      index = ii;
    }

    min_dist = color_palette_v3_B.Gain5[i] / index;

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion2_o1[i] = min_dist * jj;
    color_palette_v3_B.ColorSpaceConversion2_o2[i] = min_dist * cc;
    color_palette_v3_B.ColorSpaceConversion2_o3[i] = min_dist * ii;
  }

  /* Embedded MATLAB: '<S10>/Low Pass Filter' */
  color_palette_v3_LowPassFilter(color_palette_v3_B.ColorSpaceConversion2_o1,
    &color_palette_v3_B.sf_LowPassFilter);

  /* Embedded MATLAB: '<S10>/Low Pass Filter1' */
  color_palette_v3_LowPassFilter(color_palette_v3_B.ColorSpaceConversion2_o2,
    &color_palette_v3_B.sf_LowPassFilter1);

  /* Embedded MATLAB: '<S10>/Low Pass Filter2' */
  color_palette_v3_LowPassFilter(color_palette_v3_B.ColorSpaceConversion2_o3,
    &color_palette_v3_B.sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S9>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (color_palette_v3_B.sf_LowPassFilter.Iout[i] <= 0.039286085583733095) {
      min_dist = color_palette_v3_B.sf_LowPassFilter.Iout[i] /
        12.923054468333255;
    } else {
      min_dist = rt_pow_snf((color_palette_v3_B.sf_LowPassFilter.Iout[i] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (color_palette_v3_B.sf_LowPassFilter1.Iout[i] <= 0.039286085583733095) {
      index = color_palette_v3_B.sf_LowPassFilter1.Iout[i] / 12.923054468333255;
    } else {
      index = rt_pow_snf((color_palette_v3_B.sf_LowPassFilter1.Iout[i] +
                          0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (color_palette_v3_B.sf_LowPassFilter2.Iout[i] <= 0.039286085583733095) {
      dist = color_palette_v3_B.sf_LowPassFilter2.Iout[i] / 12.923054468333255;
    } else {
      dist = rt_pow_snf((color_palette_v3_B.sf_LowPassFilter2.Iout[i] +
                         0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    jj = (0.41239079926596 * min_dist + 0.35758433938388 * index) +
      0.18048078840183 * dist;
    cc = (0.21263900587151 * min_dist + 0.71516867876776 * index) +
      0.07219231536073 * dist;
    ii = (0.01933081871559 * min_dist + 0.11919477979463 * index) +
      0.95053215224966 * dist;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (jj > 1.0) {
      jj = 1.0;
    } else {
      if (jj < 0.0) {
        jj = 0.0;
      }
    }

    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (ii > 1.0) {
      ii = 1.0;
    } else {
      if (ii < 0.0) {
        ii = 0.0;
      }
    }

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion1_o1[i] = jj;
    color_palette_v3_B.ColorSpaceConversion1_o2[i] = cc;
    color_palette_v3_B.ColorSpaceConversion1_o3[i] = ii;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    min_dist = color_palette_v3_B.ColorSpaceConversion1_o1[i] / 0.9641986557609;
    dist = color_palette_v3_B.ColorSpaceConversion1_o3[i] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (min_dist > 0.0088564516790356311) {
      ii = rt_pow_snf(min_dist, 0.33333333333333331);
    } else {
      ii = 7.7870370370370372 * min_dist + 0.13793103448275862;
    }

    if (color_palette_v3_B.ColorSpaceConversion1_o2[i] > 0.0088564516790356311)
    {
      index = rt_pow_snf(color_palette_v3_B.ColorSpaceConversion1_o2[i],
                         0.33333333333333331);
    } else {
      index = 7.7870370370370372 * color_palette_v3_B.ColorSpaceConversion1_o2[i]
        + 0.13793103448275862;
    }

    if (dist > 0.0088564516790356311) {
      min_dist = rt_pow_snf(dist, 0.33333333333333331);
    } else {
      min_dist = 7.7870370370370372 * dist + 0.13793103448275862;
    }

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion1_o1[i] = 116.0 * index - 16.0;
    color_palette_v3_B.ColorSpaceConversion1_o2[i] = (ii - index) * 500.0;
    color_palette_v3_B.ColorSpaceConversion1_o3[i] = (index - min_dist) * 200.0;
  }

  /* S-Function (svipresize): '<S17>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist =
        color_palette_v3_B.ColorSpaceConversion1_o1[color_palette_v3_ConstP.pooled6
        [num_colors] * 160 + j] * color_palette_v3_ConstP.pooled3[num_colors] +
        color_palette_v3_B.ColorSpaceConversion1_o1[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist +=
        color_palette_v3_B.ColorSpaceConversion1_o1[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      color_palette_v3_DWork.Resize_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&color_palette_v3_DWork.Resize_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[color_palette_v3_ConstP.pooled5[ictr]] *
          color_palette_v3_ConstP.pooled2[ictr];
        ictr += 60;
      }

      color_palette_v3_B.Resize[flag] = min_dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S17>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist =
        color_palette_v3_B.ColorSpaceConversion1_o2[color_palette_v3_ConstP.pooled6
        [num_colors] * 160 + j] * color_palette_v3_ConstP.pooled3[num_colors] +
        color_palette_v3_B.ColorSpaceConversion1_o2[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist +=
        color_palette_v3_B.ColorSpaceConversion1_o2[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      color_palette_v3_DWork.Resize1_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&color_palette_v3_DWork.Resize1_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[color_palette_v3_ConstP.pooled5[ictr]] *
          color_palette_v3_ConstP.pooled2[ictr];
        ictr += 60;
      }

      color_palette_v3_B.Resize1[flag] = min_dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S17>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      min_dist =
        color_palette_v3_B.ColorSpaceConversion1_o3[color_palette_v3_ConstP.pooled6
        [num_colors] * 160 + j] * color_palette_v3_ConstP.pooled3[num_colors] +
        color_palette_v3_B.ColorSpaceConversion1_o3[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      ictr += 80;
      min_dist +=
        color_palette_v3_B.ColorSpaceConversion1_o3[color_palette_v3_ConstP.pooled6
        [ictr] * 160 + j] * color_palette_v3_ConstP.pooled3[ictr];
      color_palette_v3_DWork.Resize2_IntBuffer[i] = min_dist;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&color_palette_v3_DWork.Resize2_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      min_dist = 0.0;
      for (i = 0; i < 6; i++) {
        min_dist += Resize2_LineBuffer[color_palette_v3_ConstP.pooled5[ictr]] *
          color_palette_v3_ConstP.pooled2[ictr];
        ictr += 60;
      }

      color_palette_v3_B.Resize2[flag] = min_dist;
      flag++;
    }
  }

  /* Embedded MATLAB: '<S11>/Reference Color Selection' incorporates:
   *  Constant: '<S11>/ModeSelect4'
   */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Segmentation/Reference Color Selection': '<S16>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S16>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S16>:1:14' */
  /* '<S16>:1:15' */
  memset((void *)(&color_palette_v3_B.ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S16>:1:16' */
  memset((void *)(&color_palette_v3_B.LabelMatrix_m[0]), (int32_T)0U, 4800U *
         sizeof(uint32_T));

  /* '<S16>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S16>:1:23' */
  color_palette_v3_B.ref_colors[0] = color_palette_v3_B.Resize[2369];
  color_palette_v3_B.ref_colors[50] = color_palette_v3_B.Resize1[2369];
  color_palette_v3_B.ref_colors[100] = color_palette_v3_B.Resize2[2369];

  /* '<S16>:1:25' */
  flag = 0;

  /* '<S16>:1:26' */
  i = 1;

  /* '<S16>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S16>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S16>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S16>:1:30' */
        /* '<S16>:1:31' */
        k = 1.0;

        /* '<S16>:1:32' */
        min_dist = 1000.0;

        /* '<S16>:1:33' */
        index = 1.0;
        while ((uint32_T)k <= (uint32_T)num_colors) {
          /* '<S16>:1:34' */
          /* '<S16>:1:35' */
          dist = sqrt((rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k + 49]
            - color_palette_v3_B.Resize1[(j - 1) * 60 + (i - 1)], 2.0) * 1.5 +
                       rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k - 1]
            - color_palette_v3_B.Resize[(j - 1) * 60 + (i - 1)], 2.0)) +
                      rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k + 99]
            - color_palette_v3_B.Resize2[(j - 1) * 60 + (i - 1)], 2.0) * 1.5);
          if (min_dist > dist) {
            /* '<S16>:1:36' */
            /* '<S16>:1:37' */
            min_dist = dist;

            /* '<S16>:1:38' */
            index = k;
          }

          /* '<S16>:1:40' */
          k++;
        }

        if ((min_dist > color_palette_v3_P.ModeSelect4_Value) && (num_colors <
             50)) {
          /* '<S16>:1:45' */
          /* '<S16>:1:46' */
          color_palette_v3_B.ref_colors[num_colors] = color_palette_v3_B.Resize
            [(j - 1) * 60 + (i - 1)];
          color_palette_v3_B.ref_colors[num_colors + 50] =
            color_palette_v3_B.Resize1[(j - 1) * 60 + (i - 1)];
          color_palette_v3_B.ref_colors[num_colors + 100] =
            color_palette_v3_B.Resize2[(j - 1) * 60 + (i - 1)];

          /* '<S16>:1:47' */
          num_colors++;

          /* '<S16>:1:48' */
          flag = 1;

          /* '<S16>:1:49' */
          i = 0;

          /* '<S16>:1:50' */
          j = 0;
        } else {
          /* '<S16>:1:52' */
          color_palette_v3_B.LabelMatrix_m[(i - 1) + 60 * (j - 1)] = (uint32_T)
            index;
        }

        /* '<S16>:1:54' */
        j++;
      }

      /* '<S16>:1:56' */
      j = 1;

      /* '<S16>:1:57' */
      i++;
    }

    /* '<S16>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S16>:1:63' */
  /* '<S16>:1:64' */
  /* '<S16>:1:65' */
  /* '<S16>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S16>:1:67' */
  for (flag = 0; flag < 60; flag++) {
    /* '<S16>:1:67' */
    /* '<S16>:1:68' */
    for (i = 0; i < 80; i++) {
      /* '<S16>:1:68' */
      /* '<S16>:1:69' */
      /* '<S16>:1:70' */
      ref_color_L_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[flag + 60 * i] -
        1] = ref_color_L_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[60 * i +
        flag] - 1] + color_palette_v3_B.Resize[60 * i + flag];

      /* '<S16>:1:71' */
      ref_color_a_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[flag + 60 * i] -
        1] = ref_color_a_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[60 * i +
        flag] - 1] + color_palette_v3_B.Resize1[60 * i + flag];

      /* '<S16>:1:72' */
      ref_color_b_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[flag + 60 * i] -
        1] = ref_color_b_avg[(int32_T)color_palette_v3_B.LabelMatrix_m[60 * i +
        flag] - 1] + color_palette_v3_B.Resize2[60 * i + flag];

      /* '<S16>:1:73' */
      color_count[(int32_T)color_palette_v3_B.LabelMatrix_m[flag + 60 * i] - 1] =
        color_count[(int32_T)color_palette_v3_B.LabelMatrix_m[60 * i + flag] - 1]
        + 1.0;
    }
  }

  /* '<S16>:1:76' */
  /* '<S16>:1:77' */
  /* '<S16>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S16>:1:80' */
  for (min_dist = 1.0; (uint32_T)min_dist <= (uint32_T)num_colors; min_dist++) {
    /* '<S16>:1:80' */
    /* '<S16>:1:81' */
    color_palette_v3_B.ref_colors[(int32_T)min_dist - 1] = ref_color_L_avg
      [(int32_T)min_dist - 1];

    /* '<S16>:1:82' */
    color_palette_v3_B.ref_colors[(int32_T)min_dist + 49] = ref_color_a_avg
      [(int32_T)min_dist - 1];

    /* '<S16>:1:83' */
    color_palette_v3_B.ref_colors[(int32_T)min_dist + 99] = ref_color_b_avg
      [(int32_T)min_dist - 1];
  }

  color_palette_v3_B.num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<Root>/Display colors' incorporates:
   *  Constant: '<Root>/L'
   *  Constant: '<Root>/a_range'
   *  Constant: '<Root>/b_range'
   *  Constant: '<Root>/refColorSelect'
   */
  /* Embedded MATLAB Function 'Display colors': '<S2>:1' */
  /*  Initialize */
  /* '<S2>:1:8' */
  /* '<S2>:1:9' */
  /* '<S2>:1:10' */
  /*  Display the valid color range gradient */
  /* '<S2>:1:14' */
  for (flag = 0; flag < 200; flag++) {
    /* '<S2>:1:14' */
    /* '<S2>:1:15' */
    for (i = 0; i < 200; i++) {
      /* '<S2>:1:15' */
      /* '<S2>:1:17' */
      color_palette_v3_B.L[flag + 200 * i] = color_palette_v3_P.L_Value;

      /* '<S2>:1:18' */
      color_palette_v3_B.a[flag + 200 * i] = (color_palette_v3_P.a_range_Value[1]
        - color_palette_v3_P.a_range_Value[0]) * ((real_T)flag / 199.0) +
        color_palette_v3_P.a_range_Value[0];

      /* '<S2>:1:19' */
      color_palette_v3_B.b[flag + 200 * i] = (color_palette_v3_P.b_range_Value[1]
        - color_palette_v3_P.b_range_Value[0]) * ((real_T)i / 199.0) +
        color_palette_v3_P.b_range_Value[0];
    }
  }

  /*  Place a box in the center of the viewing area with the refColorSelect'th */
  /*    color in ref_colors */
  /* '<S2>:1:27' */
  for (flag = 90; flag < 111; flag++) {
    /* '<S2>:1:27' */
    /* '<S2>:1:28' */
    for (i = 90; i < 111; i++) {
      /* '<S2>:1:28' */
      /* '<S2>:1:29' */
      color_palette_v3_B.L[(flag - 1) + 200 * (i - 1)] =
        color_palette_v3_B.ref_colors[(int32_T)
        color_palette_v3_P.refColorSelect_Value - 1];

      /* '<S2>:1:30' */
      color_palette_v3_B.a[(flag - 1) + 200 * (i - 1)] =
        color_palette_v3_B.ref_colors[(int32_T)
        color_palette_v3_P.refColorSelect_Value + 49];

      /* '<S2>:1:31' */
      color_palette_v3_B.b[(flag - 1) + 200 * (i - 1)] =
        color_palette_v3_B.ref_colors[(int32_T)
        color_palette_v3_P.refColorSelect_Value + 99];
    }
  }

  /*  Display the L, a, b components of the selected color */
  /* '<S2>:1:37' */
  /* '<S2>:1:38' */
  /* '<S2>:1:39' */

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 40000; i++) {
    cc = (color_palette_v3_B.L[i] + 16.0) / 116.0;
    jj = color_palette_v3_B.a[i] / 500.0 + cc;
    ii = color_palette_v3_B.b[i] / -200.0 + cc;
    if (jj <= 0.20689655172413793) {
      jj -= 0.13793103448275862;
      jj /= 7.7870370370370372;
    } else {
      jj = rt_pow_snf(jj, 3.0);
    }

    if (cc <= 0.20689655172413793) {
      cc -= 0.13793103448275862;
      cc /= 7.7870370370370372;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (ii <= 0.20689655172413793) {
      ii -= 0.13793103448275862;
      ii /= 7.7870370370370372;
    } else {
      ii = rt_pow_snf(ii, 3.0);
    }

    jj *= 0.9641986557609;
    ii *= 0.82511648322104;

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion1_o1_i[i] = jj;
    color_palette_v3_B.ColorSpaceConversion1_o2_m[i] = cc;
    color_palette_v3_B.ColorSpaceConversion1_o3_d[i] = ii;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 40000; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    jj = (3.24096994190451 * color_palette_v3_B.ColorSpaceConversion1_o1_i[i] +
          -1.53738317757009 * color_palette_v3_B.ColorSpaceConversion1_o2_m[i])
      + -0.49861076029299 * color_palette_v3_B.ColorSpaceConversion1_o3_d[i];
    cc = (-0.96924363628087 * color_palette_v3_B.ColorSpaceConversion1_o1_i[i] +
          1.87596750150771 * color_palette_v3_B.ColorSpaceConversion1_o2_m[i]) +
      0.04155505740718 * color_palette_v3_B.ColorSpaceConversion1_o3_d[i];
    ii = (0.055630079697 * color_palette_v3_B.ColorSpaceConversion1_o1_i[i] +
          -0.20397695888899 * color_palette_v3_B.ColorSpaceConversion1_o2_m[i])
      + 1.05697151424288 * color_palette_v3_B.ColorSpaceConversion1_o3_d[i];

    /* Apply gamma correction to get R'G'B' */
    if (jj <= 0.00304) {
      jj *= 12.923054468333255;
    } else {
      jj = 1.0550005198172263 * rt_pow_snf(jj, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (cc <= 0.00304) {
      cc *= 12.923054468333255;
    } else {
      cc = 1.0550005198172263 * rt_pow_snf(cc, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (ii <= 0.00304) {
      ii *= 12.923054468333255;
    } else {
      ii = 1.0550005198172263 * rt_pow_snf(ii, 0.41666666666666669) -
        0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (jj > 1.0) {
      jj = 1.0;
    } else {
      if (jj < 0.0) {
        jj = 0.0;
      }
    }

    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (ii > 1.0) {
      ii = 1.0;
    } else {
      if (ii < 0.0) {
        ii = 0.0;
      }
    }

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion1_o1_i[i] = jj;
    color_palette_v3_B.ColorSpaceConversion1_o2_m[i] = cc;
    color_palette_v3_B.ColorSpaceConversion1_o3_d[i] = ii;
  }

  /* Embedded MATLAB: '<S11>/LabSegmentation' */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Segmentation/LabSegmentation': '<S15>:1' */
  /*  This function generates the label matrix */
  /* '<S15>:1:10' */
  memset((void *)(&color_palette_v3_B.LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S15>:1:12' */
  for (i = 0; i < 160; i++) {
    /* '<S15>:1:12' */
    /* '<S15>:1:13' */
    for (j = 0; j < 120; j++) {
      /* '<S15>:1:13' */
      /* '<S15>:1:14' */
      min_dist = 1000.0;

      /* '<S15>:1:15' */
      index = 1.0;

      /* '<S15>:1:16' */
      for (k = 1.0; k <= color_palette_v3_B.num_colors; k++) {
        /* '<S15>:1:16' */
        /* '<S15>:1:17' */
        dist = sqrt((rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k - 1] -
          color_palette_v3_B.ColorSpaceConversion1_o1[160 * j + i], 2.0) +
                     rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k + 49] -
          color_palette_v3_B.ColorSpaceConversion1_o2[160 * j + i], 2.0)) +
                    rt_pow_snf(color_palette_v3_B.ref_colors[(int32_T)k + 99] -
          color_palette_v3_B.ColorSpaceConversion1_o3[160 * j + i], 2.0));
        if (dist < min_dist) {
          /* '<S15>:1:18' */
          /* '<S15>:1:19' */
          min_dist = dist;

          /* '<S15>:1:20' */
          index = k;
        }
      }

      /* '<S15>:1:23' */
      color_palette_v3_B.LabelMatrix[i + 160 * j] = index;
    }
  }

  /* '<S15>:1:27' */

  /* Embedded MATLAB: '<S1>/Filter Image1' */
  /* Embedded MATLAB Function 'Blob Analysis/Filter Image1': '<S8>:1' */
  /*  Initialize */
  /* '<S8>:1:6' */
  /* '<S8>:1:7' */
  /* '<S8>:1:8' */
  /*  Allow only colors in specified range */
  /* '<S8>:1:12' */
  for (flag = 0; flag < 160; flag++) {
    /* '<S8>:1:12' */
    /* '<S8>:1:13' */
    for (i = 0; i < 120; i++) {
      /* '<S8>:1:13' */
      /* '<S8>:1:15' */
      color_palette_v3_B.Gain5[flag + 160 * i] = color_palette_v3_B.ref_colors
        [(int32_T)color_palette_v3_B.LabelMatrix[160 * i + flag] - 1];

      /* '<S8>:1:16' */
      color_palette_v3_B.Gain4[flag + 160 * i] = color_palette_v3_B.ref_colors
        [(int32_T)color_palette_v3_B.LabelMatrix[160 * i + flag] + 49];

      /* '<S8>:1:17' */
      color_palette_v3_B.Gain3[flag + 160 * i] = color_palette_v3_B.ref_colors
        [(int32_T)color_palette_v3_B.LabelMatrix[160 * i + flag] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 19200; i++) {
    cc = (color_palette_v3_B.Gain5[i] + 16.0) / 116.0;
    jj = color_palette_v3_B.Gain4[i] / 500.0 + cc;
    ii = color_palette_v3_B.Gain3[i] / -200.0 + cc;
    if (jj <= 0.20689655172413793) {
      jj -= 0.13793103448275862;
      jj /= 7.7870370370370372;
    } else {
      jj = rt_pow_snf(jj, 3.0);
    }

    if (cc <= 0.20689655172413793) {
      cc -= 0.13793103448275862;
      cc /= 7.7870370370370372;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (ii <= 0.20689655172413793) {
      ii -= 0.13793103448275862;
      ii /= 7.7870370370370372;
    } else {
      ii = rt_pow_snf(ii, 3.0);
    }

    jj *= 0.9641986557609;
    ii *= 0.82511648322104;

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion2_o1_m[i] = jj;
    color_palette_v3_B.ColorSpaceConversion2_o2_e[i] = cc;
    color_palette_v3_B.ColorSpaceConversion2_o3_f[i] = ii;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    jj = (3.24096994190451 * color_palette_v3_B.ColorSpaceConversion2_o1_m[i] +
          -1.53738317757009 * color_palette_v3_B.ColorSpaceConversion2_o2_e[i])
      + -0.49861076029299 * color_palette_v3_B.ColorSpaceConversion2_o3_f[i];
    cc = (-0.96924363628087 * color_palette_v3_B.ColorSpaceConversion2_o1_m[i] +
          1.87596750150771 * color_palette_v3_B.ColorSpaceConversion2_o2_e[i]) +
      0.04155505740718 * color_palette_v3_B.ColorSpaceConversion2_o3_f[i];
    ii = (0.055630079697 * color_palette_v3_B.ColorSpaceConversion2_o1_m[i] +
          -0.20397695888899 * color_palette_v3_B.ColorSpaceConversion2_o2_e[i])
      + 1.05697151424288 * color_palette_v3_B.ColorSpaceConversion2_o3_f[i];

    /* Apply gamma correction to get R'G'B' */
    if (jj <= 0.00304) {
      jj *= 12.923054468333255;
    } else {
      jj = 1.0550005198172263 * rt_pow_snf(jj, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (cc <= 0.00304) {
      cc *= 12.923054468333255;
    } else {
      cc = 1.0550005198172263 * rt_pow_snf(cc, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (ii <= 0.00304) {
      ii *= 12.923054468333255;
    } else {
      ii = 1.0550005198172263 * rt_pow_snf(ii, 0.41666666666666669) -
        0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (jj > 1.0) {
      jj = 1.0;
    } else {
      if (jj < 0.0) {
        jj = 0.0;
      }
    }

    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (ii > 1.0) {
      ii = 1.0;
    } else {
      if (ii < 0.0) {
        ii = 0.0;
      }
    }

    /* assign the results */
    color_palette_v3_B.ColorSpaceConversion2_o1_m[i] = jj;
    color_palette_v3_B.ColorSpaceConversion2_o2_e[i] = cc;
    color_palette_v3_B.ColorSpaceConversion2_o3_f[i] = ii;
  }

  /* Embedded MATLAB: '<S1>/Blob Extraction' incorporates:
   *  Constant: '<Root>/ColorFilter'
   *  Constant: '<S1>/ModeSelect3'
   *  Constant: '<S1>/ModeSelect4'
   */
  min_dist = color_palette_v3_B.num_colors;
  index = color_palette_v3_P.ColorFilter_Value;

  /* Embedded MATLAB Function 'Blob Analysis/Blob Extraction': '<S6>:1' */
  /*  This function extracts  */
  /*  Input */
  /*     */
  /*  Initialize */
  /* '<S6>:1:8' */
  /* '<S6>:1:12' */
  for (i = 0; i < 19200; i++) {
    color_palette_v3_B.LogicMatrix[i] = FALSE;
  }

  /* '<S6>:1:14' */
  dist = 0.0;

  /* '<S6>:1:15' */
  memset((void *)(&color_palette_v3_B.blob_hues[0]), 0, 150U * sizeof(real_T));

  /* '<S6>:1:17' */
  for (i = 0; i < 50; i++) {
    color_palette_v3_B.blob_area[i] = -1.0;
  }

  /* '<S6>:1:18' */
  memset((void *)(&color_palette_v3_B.blob_bbox[0]), 0, 200U * sizeof(real_T));

  /* '<S6>:1:19' */
  /* '<S6>:1:20' */
  for (i = 0; i < 50; i++) {
    color_palette_v3_B.blob_major_axis[i] = 0.0;
    color_palette_v3_B.blob_minor_axis[i] = 0.0;
  }

  /* '<S6>:1:21' */
  memset((void *)(&color_palette_v3_B.blob_centroids[0]), 0, 100U * sizeof
         (real_T));

  /* '<S6>:1:22' */
  /* '<S6>:1:23' */
  /* '<S6>:1:24' */
  for (i = 0; i < 50; i++) {
    color_palette_v3_B.blob_eccentricity[i] = 0.0;
    color_palette_v3_B.blob_extent[i] = 0.0;
    color_palette_v3_B.blob_orientation[i] = 0.0;
  }

  /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
  /*  identified blob */
  /*  Calculate geometric information about the blobs */
  /*  */
  /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
  /*    locations for which color values are k, and zeros everywhere else */
  /* '<S6>:1:43' */
  for (k = 1.0; k <= min_dist; k++) {
    /* '<S6>:1:43' */
    /* '<S6>:1:45' */
    /* '<S6>:1:46' */
    if ((index == 1.0) && (color_palette_v3_B.ref_colors[(int32_T)k + 49] >=
                           color_palette_v3_P.ModeSelect3_Value[8]) &&
        (color_palette_v3_B.ref_colors[(int32_T)k + 49] <=
         color_palette_v3_P.ModeSelect3_Value[9]) &&
        (color_palette_v3_B.ref_colors[(int32_T)k + 99] >=
         color_palette_v3_P.ModeSelect4_Value_m[8]) &&
        (color_palette_v3_B.ref_colors[(int32_T)k + 99] <=
         color_palette_v3_P.ModeSelect4_Value_m[9])) {
      /* '<S6>:1:48' */
      /* '<S6>:1:50' */
      for (i = 0; i < 160; i++) {
        /* '<S6>:1:50' */
        /* '<S6>:1:51' */
        for (j = 0; j < 120; j++) {
          /* '<S6>:1:51' */
          if (color_palette_v3_B.LabelMatrix[160 * j + i] != k) {
            /* '<S6>:1:52' */
            /* '<S6>:1:53' */
            color_palette_v3_B.LogicMatrix[i + 160 * j] = FALSE;
          } else {
            /* '<S6>:1:55' */
            color_palette_v3_B.LogicMatrix[i + 160 * j] = TRUE;
          }
        }
      }

      color_palette_v3_Outputs(&color_palette_v3_B.LogicMatrix[0], TArea,
        TCentroid, TBBox, ref_color_L_avg, ref_color_a_avg, ref_color_b_avg,
        color_count, TExtent, &TNumBlobs);

      /* '<S6>:1:62' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S6>:1:62' */
        cc = floor((dist + (real_T)TNumBlobs) + 0.5);
        if (cc < 256.0) {
          tmp = (uint8_T)cc;
        } else {
          tmp = MAX_uint8_T;
        }

        if (tmp <= 50) {
          /* '<S6>:1:63' */
          /* '<S6>:1:65' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_centroids[((tmp - 1) << 1)] = TCentroid[(b_i -
            1) << 1];

          /* '<S6>:1:66' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_centroids[1 + ((tmp - 1) << 1)] = TCentroid
            [((b_i - 1) << 1) + 1];

          /* '<S6>:1:68' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          ii = color_palette_v3_B.blob_centroids[((tmp - 1) << 1)];
          color_palette_v3_refp1_round(&ii);

          /* '<S6>:1:69' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          jj = color_palette_v3_B.blob_centroids[((tmp - 1) << 1) + 1];
          color_palette_v3_refp1_round(&jj);

          /* '<S6>:1:71' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_hues[3 * (tmp - 1)] =
            color_palette_v3_B.ref_colors[(int32_T)
            color_palette_v3_B.LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)
            ii - 1)] - 1];

          /* '<S6>:1:72' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_hues[1 + 3 * (tmp - 1)] =
            color_palette_v3_B.ref_colors[(int32_T)
            color_palette_v3_B.LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)
            ii - 1)] + 49];

          /* '<S6>:1:73' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_hues[2 + 3 * (tmp - 1)] =
            color_palette_v3_B.ref_colors[(int32_T)
            color_palette_v3_B.LabelMatrix[((int32_T)jj - 1) * 160 + ((int32_T)
            ii - 1)] + 99];

          /* '<S6>:1:75' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_area[tmp - 1] = (real_T)TArea[b_i - 1];

          /* '<S6>:1:76' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_bbox[tmp - 1] = (real_T)TBBox[b_i - 1];

          /* '<S6>:1:77' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_major_axis[tmp - 1] = ref_color_L_avg[b_i - 1];

          /* '<S6>:1:78' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_minor_axis[tmp - 1] = ref_color_a_avg[b_i - 1];

          /* '<S6>:1:79' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_eccentricity[tmp - 1] = color_count[b_i - 1];

          /* '<S6>:1:80' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_extent[tmp - 1] = TExtent[b_i - 1];

          /* '<S6>:1:81' */
          cc = floor((dist + (real_T)b_i) + 0.5);
          if (cc < 256.0) {
            tmp = (uint8_T)cc;
          } else {
            tmp = MAX_uint8_T;
          }

          color_palette_v3_B.blob_orientation[tmp - 1] = ref_color_b_avg[b_i - 1];
        }
      }

      /* '<S6>:1:86' */
      dist += (real_T)TNumBlobs;
    }
  }

  color_palette_v3_B.blob_count = dist;

  /* Embedded MATLAB: '<S1>/Filter Image' incorporates:
   *  Constant: '<S1>/ModeSelect1'
   *  Constant: '<S1>/ModeSelect2'
   */
  /* Embedded MATLAB Function 'Blob Analysis/Filter Image': '<S7>:1' */
  /*  Initialize */
  /* '<S7>:1:6' */
  /*  Allow only colors in specified range */
  /* '<S7>:1:10' */

  /* ToWorkspace: '<Root>/To Workspace' incorporates:
   *  Constant: '<Root>/Iter_Segment_Thresh'
   */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (color_palette_v3_DWork.ToWorkspace_PWORK.LoggedData),
                  &color_palette_v3_P.Iter_Segment_Thresh_Value, 0);

  /* ToWorkspace: '<Root>/To Workspace1' incorporates:
   *  Constant: '<Root>/Iter_Segment_Thresh1'
   */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (color_palette_v3_DWork.ToWorkspace1_PWORK.LoggedData),
                  &color_palette_v3_P.Iter_Segment_Thresh1_Value, 0);

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void color_palette_v3_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++color_palette_v3_M->Timing.clockTick0)) {
    ++color_palette_v3_M->Timing.clockTickH0;
  }

  color_palette_v3_M->Timing.t[0] = color_palette_v3_M->Timing.clockTick0 *
    color_palette_v3_M->Timing.stepSize0 +
    color_palette_v3_M->Timing.clockTickH0 *
    color_palette_v3_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void color_palette_v3_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)color_palette_v3_M, 0,
                sizeof(RT_MODEL_color_palette_v3));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = color_palette_v3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    color_palette_v3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    color_palette_v3_M->Timing.sampleTimes =
      (&color_palette_v3_M->Timing.sampleTimesArray[0]);
    color_palette_v3_M->Timing.offsetTimes =
      (&color_palette_v3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    color_palette_v3_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    color_palette_v3_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(color_palette_v3_M, &color_palette_v3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = color_palette_v3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    color_palette_v3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(color_palette_v3_M, 0.0);
  color_palette_v3_M->Timing.stepSize0 = 0.033333333333333333;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    color_palette_v3_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(color_palette_v3_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(color_palette_v3_M->rtwLogInfo, (NULL));
    rtliSetLogT(color_palette_v3_M->rtwLogInfo, "tout");
    rtliSetLogX(color_palette_v3_M->rtwLogInfo, "");
    rtliSetLogXFinal(color_palette_v3_M->rtwLogInfo, "");
    rtliSetSigLog(color_palette_v3_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(color_palette_v3_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(color_palette_v3_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(color_palette_v3_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(color_palette_v3_M->rtwLogInfo, 1);
    rtliSetLogY(color_palette_v3_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(color_palette_v3_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(color_palette_v3_M->rtwLogInfo, (NULL));
  }

  color_palette_v3_M->solverInfoPtr = (&color_palette_v3_M->solverInfo);
  color_palette_v3_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&color_palette_v3_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&color_palette_v3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  color_palette_v3_M->ModelData.blockIO = ((void *) &color_palette_v3_B);
  (void) memset(((void *) &color_palette_v3_B), 0,
                sizeof(BlockIO_color_palette_v3));

  /* parameters */
  color_palette_v3_M->ModelData.defaultParam = ((real_T *)&color_palette_v3_P);

  /* states (dwork) */
  color_palette_v3_M->Work.dwork = ((void *) &color_palette_v3_DWork);
  (void) memset((void *)&color_palette_v3_DWork, 0,
                sizeof(D_Work_color_palette_v3));
}

/* Model terminate function */
void color_palette_v3_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
extern "C" void MdlOutputs(int_T tid)
{
  color_palette_v3_output(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  color_palette_v3_update(tid);
}

extern "C" void MdlInitializeSizes(void)
{
  color_palette_v3_M->Sizes.numContStates = (0);/* Number of continuous states */
  color_palette_v3_M->Sizes.numY = (0);/* Number of model outputs */
  color_palette_v3_M->Sizes.numU = (0);/* Number of model inputs */
  color_palette_v3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  color_palette_v3_M->Sizes.numSampTimes = (1);/* Number of sample times */
  color_palette_v3_M->Sizes.numBlocks = (49);/* Number of blocks */
  color_palette_v3_M->Sizes.numBlockIO = (34);/* Number of block outputs */
  color_palette_v3_M->Sizes.numBlockPrms = (57672);/* Sum of parameter "widths" */
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
  {
    int32_T i;
    static int16_T tmp[8] = { -1, 161, 162, 163, 1, -161, -162, -163 };

    /* InitializeConditions for Embedded MATLAB: '<S1>/Blob Extraction' */
    for (i = 0; i < 8; i++) {
      color_palette_v3_DWork.WALKER_RTP[i] = tmp[i];
    }

    color_palette_v3_DWork.F0_RTP = -1;
    color_palette_v3_DWork.F1_RTP = -1.0;
    color_palette_v3_DWork.F2_RTP = -1;
    color_palette_v3_DWork.F3_RTP = -1.0;
    color_palette_v3_DWork.F4_RTP = -1.0;
    color_palette_v3_DWork.F5_RTP = -1.0;
    color_palette_v3_DWork.F6_RTP = -1.0;
    color_palette_v3_DWork.F7_RTP = -1.0;
    color_palette_v3_DWork.MINAREA_RTP = 5U;
  }
}

extern "C" void MdlStart(void)
{
  /* Start for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[1] = { 1 };

    color_palette_v3_DWork.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      color_palette_v3_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(color_palette_v3_M),
      color_palette_v3_M->Timing.stepSize0,
      (&rtmGetErrorStatus(color_palette_v3_M)),
      "Iter_Segment_Thresh",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (color_palette_v3_DWork.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 1 };

    color_palette_v3_DWork.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      color_palette_v3_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(color_palette_v3_M),
      color_palette_v3_M->Timing.stepSize0,
      (&rtmGetErrorStatus(color_palette_v3_M)),
      "Scale_Forward_R",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (color_palette_v3_DWork.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  MdlInitialize();
}

extern "C" void MdlTerminate(void)
{
  color_palette_v3_terminate();
}

extern "C" RT_MODEL_color_palette_v3 *color_palette_v3(void)
{
  color_palette_v3_initialize(1);
  return color_palette_v3_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
