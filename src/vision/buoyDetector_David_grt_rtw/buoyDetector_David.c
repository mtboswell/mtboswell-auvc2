/*
 * buoyDetector_David.c
 *
 * Real-Time Workshop code generation for Simulink model "buoyDetector_David.mdl".
 *
 * Model version              : 1.381
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C source code generated on : Tue May 24 20:20:11 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buoyDetector_David.h"
#include "buoyDetector_David_private.h"

/* Block signals (auto storage) */
BlockIO_buoyDetector_David buoyDetector_David_B;

/* Block states (auto storage) */
D_Work_buoyDetector_David buoyDetector_David_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_buoyDetector_Da buoyDetector_David_Y;

/* Real-time model */
RT_MODEL_buoyDetector_David buoyDetector_David_M_;
RT_MODEL_buoyDetector_David *buoyDetector_David_M = &buoyDetector_David_M_;

/* Forward declaration for local functions */
static void buoyDetector_David_conv2(const real32_T arg1[19200], const real32_T
  arg2[9], real32_T c[18644]);

/* Forward declaration for local functions */
static void buoyDetector_David_Outputs(const boolean_T U0[19200], real_T Y0[100],
  real_T Y1[50], real_T Y2[50], uint8_T *Y3);
static void buoyDetector_David_refp1_round(real_T *x);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  uint32_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator = absNumerator % absDenominator;
      if (absNumerator > (uint32_T)0) {
        tempAbsQuotient = tempAbsQuotient + (uint32_T)1;
      }
    }

    quotient = quotientNeedsNegation ? (int32_T)(-((int32_T)tempAbsQuotient)) :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/* Function for Embedded MATLAB: '<S9>/Low Pass Filter' */
static void buoyDetector_David_conv2(const real32_T arg1[19200], const real32_T
  arg2[9], real32_T c[18644])
{
  int32_T j;
  int32_T jp;
  int32_T ja;
  int32_T i;
  int32_T ip;
  int32_T ia;
  real32_T s;
  int32_T jb;
  int32_T jc;
  int32_T ic;
  int32_T ja_0;
  int32_T ia_0;
  for (jc = 0; jc < 158; jc++) {
    j = jc + 3;
    jp = j + 1;
    ja = jp - 3;
    for (ic = 0; ic < 118; ic++) {
      i = ic + 3;
      ip = i + 1;
      ia = ip - 3;
      s = 0.0F;
      for (ja_0 = ja; ja_0 <= j; ja_0++) {
        jb = jp - ja_0;
        for (ia_0 = ia; ia_0 <= i; ia_0++) {
          s += arg1[(ja_0 - 1) * 120 + (ia_0 - 1)] * arg2[((ip - ia_0) - 1) +
            (jb - 1) * 3];
        }
      }

      c[ic + 118 * jc] = s;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S9>/Low Pass Filter'
 *    '<S9>/Low Pass Filter1'
 *    '<S9>/Low Pass Filter2'
 */
void buoyDetector_Davi_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_buoyDetector_ *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;
  real32_T G_0[9];

  /* Embedded MATLAB: '<S9>/Low Pass Filter' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S11>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S11>:1:11' */
  memset((void *)(&localB->Iout[0]), (int32_T)0.0F, 19200U * sizeof(real32_T));

  /* '<S11>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S11>:1:19' */
  /* '<S11>:1:21' */
  /* '<S11>:1:23' */
  Gsum = 0.0;

  /* '<S11>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S11>:1:24' */
    /* '<S11>:1:25' */
    /* '<S11>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S11>:1:27' */
    Gsum += G[i + 1];

    /* '<S11>:1:25' */
    /* '<S11>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S11>:1:27' */
    Gsum += G[i + 4];

    /* '<S11>:1:25' */
    /* '<S11>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S11>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S11>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S11>:1:33' */
  for (i = 0; i < 19200; i++) {
    localB->fv0[i] = (real32_T)rtu_I[i];
  }

  for (i = 0; i < 9; i++) {
    G_0[i] = (real32_T)G[i];
  }

  buoyDetector_David_conv2(&localB->fv0[0], G_0, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S11>:1:37' */
  for (i = 0; i < 158; i++) {
    localB->Iout[120 * (1 + i)] = localB->Itemp[118 * i];
  }

  /*  bottom */
  /* '<S11>:1:39' */
  for (i = 0; i < 158; i++) {
    localB->Iout[119 + 120 * (1 + i)] = localB->Itemp[118 * i + 117];
  }

  /*  left */
  /* '<S11>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 118U * sizeof
         (real32_T));

  /*  right */
  /* '<S11>:1:43' */
  memcpy((void *)(&localB->Iout[19081]), (void *)(&localB->Itemp[18526]), 118U *
         sizeof(real32_T));

  /*  center */
  /* '<S11>:1:45' */
  for (i = 0; i < 158; i++) {
    memcpy((void *)(&localB->Iout[1 + 120 * (1 + i)]), (void *)(&localB->Itemp
            [118 * i]), 118U * sizeof(real32_T));
  }

  /*  top left corner */
  /* '<S11>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S11>:1:49' */
  localB->Iout[18960] = localB->Itemp[18408];
  localB->Iout[19080] = localB->Itemp[18526];

  /*  bottom left corner */
  /* '<S11>:1:51' */
  localB->Iout[118] = localB->Itemp[116];
  localB->Iout[119] = localB->Itemp[117];

  /*  bottom right corner */
  /* '<S11>:1:53' */
  localB->Iout[19078] = localB->Itemp[18524];
  localB->Iout[19079] = localB->Itemp[18525];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Function for Embedded MATLAB: '<S4>/Blob Extraction' */
static void buoyDetector_David_Outputs(const boolean_T U0[19200], real_T Y0[100],
  real_T Y1[50], real_T Y2[50], uint8_T *Y3)
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
  memset((void *)(&buoyDetector_David_DWork.PAD_DW[0]), (int32_T)0U, 123U *
         sizeof(uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (maxc = 0; maxc < 120; maxc++) {
      buoyDetector_David_DWork.PAD_DW[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    buoyDetector_David_DWork.PAD_DW[idx] = 0U;
    idx++;
    buoyDetector_David_DWork.PAD_DW[idx] = 0U;
    idx++;
  }

  memset((void *)(&buoyDetector_David_DWork.PAD_DW[idx]), (int32_T)0U, 121U *
         sizeof(uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    maxc = 1;
    idx = loop * 122;
    for (maxr = 0; maxr < 120; maxr++) {
      k = (uint32_T)(idx + maxc);
      start_pixIdx = pixIdx;
      if (buoyDetector_David_DWork.PAD_DW[k] == 255) {
        buoyDetector_David_DWork.PAD_DW[k] = currentLabel;
        buoyDetector_David_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)(loop - 1);
        buoyDetector_David_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)(maxc - 1);
        pixIdx++;
        buoyDetector_David_DWork.NUM_PIX_DW[currentLabel - 1] = 1U;
        buoyDetector_David_DWork.STACK_DW[stackIdx] = k;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          k = buoyDetector_David_DWork.STACK_DW[stackIdx];
          for (pixListMinc = 0; pixListMinc < 8; pixListMinc++) {
            walkerIdx = k + (uint32_T)
              buoyDetector_David_DWork.WALKER_RTP[pixListMinc];
            if (buoyDetector_David_DWork.PAD_DW[walkerIdx] == 255) {
              buoyDetector_David_DWork.PAD_DW[walkerIdx] = currentLabel;
              buoyDetector_David_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 122U) - 1);
              buoyDetector_David_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)
                (walkerIdx % 122U - 1U);
              pixIdx++;
              buoyDetector_David_DWork.NUM_PIX_DW[currentLabel - 1] =
                buoyDetector_David_DWork.NUM_PIX_DW[currentLabel - 1] + 1U;
              buoyDetector_David_DWork.STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (buoyDetector_David_DWork.NUM_PIX_DW[currentLabel - 1] <
            buoyDetector_David_DWork.MINAREA_RTP) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 50) {
          maxNumBlobsReached = TRUE;
          n = 160;
          maxr = 120;
        }

        if (maxr < 120) {
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
    for (j = 0; j < (int32_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i]; j++) {
      loop += buoyDetector_David_DWork.N_PIXLIST_DW[j + pixListNinc];
      n += buoyDetector_David_DWork.M_PIXLIST_DW[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)
      buoyDetector_David_DWork.NUM_PIX_DW[c_i];
    Y0[c_i << 1] = centroid_idx;
    Y0[(c_i << 1) + 1] = centroid_idx_0;
    n = 160;
    idx = 120;
    maxc = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i]; j++) {
      loop = j + pixListNinc;
      if (buoyDetector_David_DWork.N_PIXLIST_DW[loop] < n) {
        n = buoyDetector_David_DWork.N_PIXLIST_DW[loop];
      }

      if (buoyDetector_David_DWork.N_PIXLIST_DW[loop] > maxc) {
        maxc = buoyDetector_David_DWork.N_PIXLIST_DW[loop];
      }

      loop = j + pixListMinc;
      if (buoyDetector_David_DWork.M_PIXLIST_DW[loop] < idx) {
        idx = buoyDetector_David_DWork.M_PIXLIST_DW[loop];
      }

      if (buoyDetector_David_DWork.M_PIXLIST_DW[loop] > maxr) {
        maxr = buoyDetector_David_DWork.M_PIXLIST_DW[loop];
      }
    }

    xs = 0.0;
    ys = 0.0;
    xys = 0.0;
    for (k = 0U; (int32_T)k < (int32_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i];
         k++) {
      majorAxis = (real_T)buoyDetector_David_DWork.N_PIXLIST_DW[pixListNinc +
        (int32_T)k] - centroid_idx_0;
      uyy = (real_T)buoyDetector_David_DWork.M_PIXLIST_DW[pixListMinc + (int32_T)
        k] - centroid_idx;
      xs += majorAxis * majorAxis;
      ys += uyy * uyy;
      xys += majorAxis * (-uyy);
    }

    centroid_idx = xs / (real_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    uyy = ys / (real_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    xs = xys / (real_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i];
    xs = sqrt((centroid_idx - uyy) * (centroid_idx - uyy) + xs * xs * 4.0);
    majorAxis = ((centroid_idx + uyy) + xs) * 8.0;
    Y1[c_i] = sqrt(majorAxis - ((centroid_idx + uyy) - xs) * 8.0) / sqrt
      (majorAxis);
    Y2[c_i] = (real_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i] / (real_T)(((maxr
      + 1) - idx) * ((maxc + 1) - n));
    pixListMinc += (int32_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)buoyDetector_David_DWork.NUM_PIX_DW[c_i];
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y0[loop] = buoyDetector_David_DWork.F0_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y1[loop] = buoyDetector_David_DWork.F1_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y2[loop] = buoyDetector_David_DWork.F2_RTP;
  }
}

/* Function for Embedded MATLAB: '<S4>/Blob Extraction' */
static void buoyDetector_David_refp1_round(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/* Model output function */
static void buoyDetector_David_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_buoy_id[50];
  real_T rtb_buoy_count;
  real_T rtb_buoy_hues[50];
  real_T rtb_buoy_centroids[100];
  int32_T i;
  real32_T cc;
  real32_T Yr;
  real32_T Zr;
  real32_T Xf;
  int32_T idxROI;
  int32_T row;
  int32_T col;
  int32_T size;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T OutCode;
  int32_T num_colors;
  int32_T flag;
  int32_T j;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];
  real_T min_dist;
  real_T index;
  real32_T dist;
  real_T num_colors_0;
  real_T k;
  uint8_T b_i;
  real_T TCentroid[100];
  uint8_T TNumBlobs;
  real_T c;
  real_T rtb_SuccessiveValidImageCount;
  real32_T Resize2_LineBuffer[120];
  real_T rtb_buoy_centroids_mod[100];
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

  /* Memory: '<Root>/Successive Valid Image Count' */
  rtb_SuccessiveValidImageCount =
    buoyDetector_David_DWork.SuccessiveValidImageCount_Previ;

  /* Embedded MATLAB: '<S9>/Low Pass Filter' */
  buoyDetector_Davi_LowPassFilter(buoyDetector_David_P.Constant1_Value,
    &buoyDetector_David_B.sf_LowPassFilter);

  /* Embedded MATLAB: '<S9>/Low Pass Filter1' */
  buoyDetector_Davi_LowPassFilter(buoyDetector_David_P.Constant2_Value,
    &buoyDetector_David_B.sf_LowPassFilter1);

  /* Embedded MATLAB: '<S9>/Low Pass Filter2' */
  buoyDetector_Davi_LowPassFilter(buoyDetector_David_P.Constant3_Value,
    &buoyDetector_David_B.sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (buoyDetector_David_B.sf_LowPassFilter.Iout[i] <= 0.0392860845F) {
      dist = buoyDetector_David_B.sf_LowPassFilter.Iout[i] / 12.9230547F;
    } else {
      dist = rt_pow32_snf((buoyDetector_David_B.sf_LowPassFilter.Iout[i] +
                           0.0550005212F) / 1.05500054F, 2.4F);
    }

    if (buoyDetector_David_B.sf_LowPassFilter1.Iout[i] <= 0.0392860845F) {
      Yr = buoyDetector_David_B.sf_LowPassFilter1.Iout[i] / 12.9230547F;
    } else {
      Yr = rt_pow32_snf((buoyDetector_David_B.sf_LowPassFilter1.Iout[i] +
                         0.0550005212F) / 1.05500054F, 2.4F);
    }

    if (buoyDetector_David_B.sf_LowPassFilter2.Iout[i] <= 0.0392860845F) {
      Zr = buoyDetector_David_B.sf_LowPassFilter2.Iout[i] / 12.9230547F;
    } else {
      Zr = rt_pow32_snf((buoyDetector_David_B.sf_LowPassFilter2.Iout[i] +
                         0.0550005212F) / 1.05500054F, 2.4F);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    Xf = (0.412390798F * dist + 0.357584327F * Yr) + 0.180480793F * Zr;
    cc = (0.212639F * dist + 0.715168655F * Yr) + 0.0721923187F * Zr;
    dist = (0.0193308182F * dist + 0.119194783F * Yr) + 0.950532138F * Zr;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (Xf > 1.0F) {
      Xf = 1.0F;
    } else {
      if (Xf < 0.0F) {
        Xf = 0.0F;
      }
    }

    if (cc > 1.0F) {
      cc = 1.0F;
    } else {
      if (cc < 0.0F) {
        cc = 0.0F;
      }
    }

    if (dist > 1.0F) {
      dist = 1.0F;
    } else {
      if (dist < 0.0F) {
        dist = 0.0F;
      }
    }

    /* assign the results */
    buoyDetector_David_B.ColorSpaceConversion1_o1[i] = Xf;
    buoyDetector_David_B.ColorSpaceConversion1_o2[i] = cc;
    buoyDetector_David_B.ColorSpaceConversion1_o3[i] = dist;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    dist = buoyDetector_David_B.ColorSpaceConversion1_o1[i] / 0.964198649F;
    Zr = buoyDetector_David_B.ColorSpaceConversion1_o3[i] / 0.825116456F;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (dist > 0.00885645207F) {
      Xf = rt_pow32_snf(dist, 0.333333343F);
    } else {
      Xf = 7.7870369F * dist + 0.137931034F;
    }

    if (buoyDetector_David_B.ColorSpaceConversion1_o2[i] > 0.00885645207F) {
      Yr = rt_pow32_snf(buoyDetector_David_B.ColorSpaceConversion1_o2[i],
                        0.333333343F);
    } else {
      Yr = 7.7870369F * buoyDetector_David_B.ColorSpaceConversion1_o2[i] +
        0.137931034F;
    }

    if (Zr > 0.00885645207F) {
      dist = rt_pow32_snf(Zr, 0.333333343F);
    } else {
      dist = 7.7870369F * Zr + 0.137931034F;
    }

    /* assign the results */
    buoyDetector_David_B.ColorSpaceConversion1_o1[i] = 116.0F * Yr - 16.0F;
    buoyDetector_David_B.ColorSpaceConversion1_o2[i] = (Xf - Yr) * 500.0F;
    buoyDetector_David_B.ColorSpaceConversion1_o3[i] = (Yr - dist) * 200.0F;
  }

  /* S-Function (svipresize): '<S16>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 120; num_colors++) {
    OutCode = num_colors;
    for (i = 0; i < 80; i++) {
      line_idx_2 = i + 80;
      dist =
        buoyDetector_David_B.ColorSpaceConversion1_o1[buoyDetector_David_ConstP.pooled4
        [i] * 120 + num_colors] * buoyDetector_David_ConstP.pooled2[i] +
        buoyDetector_David_B.ColorSpaceConversion1_o1[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o1[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o1[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      buoyDetector_David_DWork.Resize_IntBuffer[OutCode] = dist;
      OutCode += 120;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&buoyDetector_David_DWork.Resize_IntBuffer[i * 120]), 120U * sizeof
           (real32_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      line_idx_2 = num_colors + 60;
      dist = Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[num_colors]] *
        buoyDetector_David_ConstP.pooled1[num_colors] +
        Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      buoyDetector_David_B.Resize[j] = dist;
      j++;
    }
  }

  /* S-Function (svipresize): '<S16>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 120; num_colors++) {
    OutCode = num_colors;
    for (i = 0; i < 80; i++) {
      line_idx_2 = i + 80;
      dist =
        buoyDetector_David_B.ColorSpaceConversion1_o2[buoyDetector_David_ConstP.pooled4
        [i] * 120 + num_colors] * buoyDetector_David_ConstP.pooled2[i] +
        buoyDetector_David_B.ColorSpaceConversion1_o2[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o2[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o2[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      buoyDetector_David_DWork.Resize1_IntBuffer[OutCode] = dist;
      OutCode += 120;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&buoyDetector_David_DWork.Resize1_IntBuffer[i * 120]), 120U * sizeof
           (real32_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      line_idx_2 = num_colors + 60;
      dist = Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[num_colors]] *
        buoyDetector_David_ConstP.pooled1[num_colors] +
        Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      buoyDetector_David_B.Resize1[j] = dist;
      j++;
    }
  }

  /* S-Function (svipresize): '<S16>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  j = 0;
  for (num_colors = 0; num_colors < 120; num_colors++) {
    OutCode = num_colors;
    for (i = 0; i < 80; i++) {
      line_idx_2 = i + 80;
      dist =
        buoyDetector_David_B.ColorSpaceConversion1_o3[buoyDetector_David_ConstP.pooled4
        [i] * 120 + num_colors] * buoyDetector_David_ConstP.pooled2[i] +
        buoyDetector_David_B.ColorSpaceConversion1_o3[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o3[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      line_idx_2 += 80;
      dist +=
        buoyDetector_David_B.ColorSpaceConversion1_o3[buoyDetector_David_ConstP.pooled4
        [line_idx_2] * 120 + num_colors] *
        buoyDetector_David_ConstP.pooled2[line_idx_2];
      buoyDetector_David_DWork.Resize2_IntBuffer[OutCode] = dist;
      OutCode += 120;
    }
  }

  for (i = 0; i < 80; i++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&buoyDetector_David_DWork.Resize2_IntBuffer[i * 120]), 120U * sizeof
           (real32_T));
    for (num_colors = 0; num_colors < 60; num_colors++) {
      line_idx_2 = num_colors + 60;
      dist = Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[num_colors]] *
        buoyDetector_David_ConstP.pooled1[num_colors] +
        Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      line_idx_2 += 60;
      dist += Resize2_LineBuffer[buoyDetector_David_ConstP.pooled3[line_idx_2]] *
        buoyDetector_David_ConstP.pooled1[line_idx_2];
      buoyDetector_David_B.Resize2[j] = dist;
      j++;
    }
  }

  /* Embedded MATLAB: '<S10>/Reference Color Selection' incorporates:
   *  Constant: '<S10>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/Reference Color Selection': '<S15>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S15>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S15>:1:14' */
  /* '<S15>:1:15' */
  memset((void *)(&buoyDetector_David_B.ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S15>:1:16' */
  memset((void *)(&buoyDetector_David_B.LabelMatrix_c[0]), (int32_T)0U, 4800U *
         sizeof(uint32_T));

  /* '<S15>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S15>:1:23' */
  buoyDetector_David_B.ref_colors[0] = buoyDetector_David_B.Resize[2369];
  buoyDetector_David_B.ref_colors[50] = buoyDetector_David_B.Resize1[2369];
  buoyDetector_David_B.ref_colors[100] = buoyDetector_David_B.Resize2[2369];

  /* '<S15>:1:25' */
  flag = 0;

  /* '<S15>:1:26' */
  i = 1;

  /* '<S15>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S15>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S15>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S15>:1:30' */
        /* '<S15>:1:31' */
        k = 1.0;

        /* '<S15>:1:32' */
        min_dist = 1000.0;

        /* '<S15>:1:33' */
        index = 1.0;
        while ((uint32_T)k <= (uint32_T)num_colors) {
          /* '<S15>:1:34' */
          /* '<S15>:1:35' */
          dist = (real32_T)sqrt((rt_pow32_snf((real32_T)
            buoyDetector_David_B.ref_colors[(int32_T)k + 49] -
            buoyDetector_David_B.Resize1[(j - 1) * 60 + (i - 1)], 2.0F) * 1.5F +
            rt_pow32_snf((real32_T)buoyDetector_David_B.ref_colors[(int32_T)k -
                         1] - buoyDetector_David_B.Resize[(j - 1) * 60 + (i - 1)],
                         2.0F)) + rt_pow32_snf((real32_T)
            buoyDetector_David_B.ref_colors[(int32_T)k + 99] -
            buoyDetector_David_B.Resize2[(j - 1) * 60 + (i - 1)], 2.0F) * 1.5F);
          if (min_dist > (real_T)dist) {
            /* '<S15>:1:36' */
            /* '<S15>:1:37' */
            min_dist = dist;

            /* '<S15>:1:38' */
            index = k;
          }

          /* '<S15>:1:40' */
          k++;
        }

        if ((min_dist > buoyDetector_David_P.Dist_Thresh_Value) && (num_colors <
             50)) {
          /* '<S15>:1:45' */
          /* '<S15>:1:46' */
          buoyDetector_David_B.ref_colors[num_colors] =
            buoyDetector_David_B.Resize[(j - 1) * 60 + (i - 1)];
          buoyDetector_David_B.ref_colors[num_colors + 50] =
            buoyDetector_David_B.Resize1[(j - 1) * 60 + (i - 1)];
          buoyDetector_David_B.ref_colors[num_colors + 100] =
            buoyDetector_David_B.Resize2[(j - 1) * 60 + (i - 1)];

          /* '<S15>:1:47' */
          num_colors++;

          /* '<S15>:1:48' */
          flag = 1;

          /* '<S15>:1:49' */
          i = 0;

          /* '<S15>:1:50' */
          j = 0;
        } else {
          /* '<S15>:1:52' */
          buoyDetector_David_B.LabelMatrix_c[(i - 1) + 60 * (j - 1)] = (uint32_T)
            index;
        }

        /* '<S15>:1:54' */
        j++;
      }

      /* '<S15>:1:56' */
      j = 1;

      /* '<S15>:1:57' */
      i++;
    }

    /* '<S15>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S15>:1:63' */
  /* '<S15>:1:64' */
  /* '<S15>:1:65' */
  /* '<S15>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S15>:1:67' */
  for (flag = 0; flag < 60; flag++) {
    /* '<S15>:1:67' */
    /* '<S15>:1:68' */
    for (j = 0; j < 80; j++) {
      /* '<S15>:1:68' */
      /* '<S15>:1:69' */
      /* '<S15>:1:70' */
      ref_color_L_avg[(int32_T)buoyDetector_David_B.LabelMatrix_c[flag + 60 * j]
        - 1] = (real32_T)ref_color_L_avg[(int32_T)
        buoyDetector_David_B.LabelMatrix_c[60 * j + flag] - 1] +
        buoyDetector_David_B.Resize[60 * j + flag];

      /* '<S15>:1:71' */
      ref_color_a_avg[(int32_T)buoyDetector_David_B.LabelMatrix_c[flag + 60 * j]
        - 1] = (real32_T)ref_color_a_avg[(int32_T)
        buoyDetector_David_B.LabelMatrix_c[60 * j + flag] - 1] +
        buoyDetector_David_B.Resize1[60 * j + flag];

      /* '<S15>:1:72' */
      ref_color_b_avg[(int32_T)buoyDetector_David_B.LabelMatrix_c[flag + 60 * j]
        - 1] = (real32_T)ref_color_b_avg[(int32_T)
        buoyDetector_David_B.LabelMatrix_c[60 * j + flag] - 1] +
        buoyDetector_David_B.Resize2[60 * j + flag];

      /* '<S15>:1:73' */
      color_count[(int32_T)buoyDetector_David_B.LabelMatrix_c[flag + 60 * j] - 1]
        = color_count[(int32_T)buoyDetector_David_B.LabelMatrix_c[60 * j + flag]
        - 1] + 1.0;
    }
  }

  /* '<S15>:1:76' */
  /* '<S15>:1:77' */
  /* '<S15>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S15>:1:80' */
  for (min_dist = 1.0; (uint32_T)min_dist <= (uint32_T)num_colors; min_dist++) {
    /* '<S15>:1:80' */
    /* '<S15>:1:81' */
    buoyDetector_David_B.ref_colors[(int32_T)min_dist - 1] = ref_color_L_avg
      [(int32_T)min_dist - 1];

    /* '<S15>:1:82' */
    buoyDetector_David_B.ref_colors[(int32_T)min_dist + 49] = ref_color_a_avg
      [(int32_T)min_dist - 1];

    /* '<S15>:1:83' */
    buoyDetector_David_B.ref_colors[(int32_T)min_dist + 99] = ref_color_b_avg
      [(int32_T)min_dist - 1];
  }

  buoyDetector_David_B.num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<S10>/LabSegmentation' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Segmentation/LabSegmentation': '<S14>:1' */
  /*  This function generates the label matrix */
  /* '<S14>:1:10' */
  memset((void *)(&buoyDetector_David_B.LabelMatrix[0]), 0, 19200U * sizeof
         (real_T));

  /* '<S14>:1:12' */
  for (i = 0; i < 120; i++) {
    /* '<S14>:1:12' */
    /* '<S14>:1:13' */
    for (j = 0; j < 160; j++) {
      /* '<S14>:1:13' */
      /* '<S14>:1:14' */
      min_dist = 1000.0;

      /* '<S14>:1:15' */
      index = 1.0;

      /* '<S14>:1:16' */
      for (k = 1.0; k <= buoyDetector_David_B.num_colors; k++) {
        /* '<S14>:1:16' */
        /* '<S14>:1:17' */
        dist = (real32_T)sqrt((rt_pow32_snf((real32_T)
          buoyDetector_David_B.ref_colors[(int32_T)k - 1] -
          buoyDetector_David_B.ColorSpaceConversion1_o1[120 * j + i], 2.0F) +
          rt_pow32_snf((real32_T)buoyDetector_David_B.ref_colors[(int32_T)k + 49]
                       - buoyDetector_David_B.ColorSpaceConversion1_o2[120 * j +
                       i], 2.0F)) + rt_pow32_snf((real32_T)
          buoyDetector_David_B.ref_colors[(int32_T)k + 99] -
          buoyDetector_David_B.ColorSpaceConversion1_o3[120 * j + i], 2.0F));
        if ((real_T)dist < min_dist) {
          /* '<S14>:1:18' */
          /* '<S14>:1:19' */
          min_dist = dist;

          /* '<S14>:1:20' */
          index = k;
        }
      }

      /* '<S14>:1:23' */
      buoyDetector_David_B.LabelMatrix[i + 120 * j] = index;
    }
  }

  /* '<S14>:1:27' */

  /* Embedded MATLAB: '<S4>/Blob Extraction' */
  num_colors_0 = buoyDetector_David_B.num_colors;

  /* Embedded MATLAB Function 'Look for Buoys/Blob Extraction': '<S18>:1' */
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
  /* '<S18>:1:21' */
  for (i = 0; i < 19200; i++) {
    buoyDetector_David_B.LogicMatrix[i] = FALSE;
  }

  /* '<S18>:1:23' */
  /* '<S18>:1:26' */
  memset((void *)(&buoyDetector_David_B.blob_hues[0]), 0, 150U * sizeof(real_T));

  /* '<S18>:1:27' */
  memset((void *)(&buoyDetector_David_B.blob_centroids[0]), 0, 100U * sizeof
         (real_T));

  /* '<S18>:1:28' */
  /* '<S18>:1:29' */
  for (i = 0; i < 50; i++) {
    buoyDetector_David_B.blob_eccentricity[i] = 0.0;
    buoyDetector_David_B.blob_extent[i] = 0.0;
  }

  /* '<S18>:1:31' */
  min_dist = 0.0;

  /* uint8(0); */
  /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
  /*  identified blob */
  /* % Calculate geometric information about the blobs */
  /*  */
  /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
  /*    locations for which color values are k, and zeros everywhere else */
  /* '<S18>:1:47' */
  for (k = 1.0; k <= num_colors_0; k++) {
    /* '<S18>:1:47' */
    /* '<S18>:1:48' */
    for (i = 0; i < 120; i++) {
      /* '<S18>:1:48' */
      /* '<S18>:1:49' */
      for (j = 0; j < 160; j++) {
        /* '<S18>:1:49' */
        if (buoyDetector_David_B.LabelMatrix[120 * j + i] != k) {
          /* '<S18>:1:50' */
          /* '<S18>:1:51' */
          buoyDetector_David_B.LogicMatrix[i + 120 * j] = FALSE;
        } else {
          /* '<S18>:1:53' */
          buoyDetector_David_B.LogicMatrix[i + 120 * j] = TRUE;
        }
      }
    }

    buoyDetector_David_Outputs(&buoyDetector_David_B.LogicMatrix[0], TCentroid,
      ref_color_L_avg, ref_color_a_avg, &TNumBlobs);
    tmp_0 = floor((min_dist + (real_T)TNumBlobs) + 0.5);
    if (tmp_0 < 256.0) {
      tmp = (uint8_T)tmp_0;
    } else {
      tmp = MAX_uint8_T;
    }

    if (tmp < 50) {
      /* '<S18>:1:59' */
      /* '<S18>:1:60' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S18>:1:60' */
        /* '<S18>:1:62' */
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        buoyDetector_David_B.blob_centroids[tmp - 1] = TCentroid[(b_i - 1) << 1];

        /* '<S18>:1:63' */
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        buoyDetector_David_B.blob_centroids[tmp + 49] = TCentroid[((b_i - 1) <<
          1) + 1];

        /* '<S18>:1:64' */
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        buoyDetector_David_B.blob_eccentricity[tmp - 1] = ref_color_L_avg[b_i -
          1];

        /* '<S18>:1:65' */
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        buoyDetector_David_B.blob_extent[tmp - 1] = ref_color_a_avg[b_i - 1];

        /* '<S18>:1:67' */
        /* '<S18>:1:68' */
        /* '<S18>:1:69' */
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        index = buoyDetector_David_B.blob_centroids[tmp - 1];
        buoyDetector_David_refp1_round(&index);
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        c = buoyDetector_David_B.blob_centroids[tmp + 49];
        buoyDetector_David_refp1_round(&c);
        tmp_0 = floor((min_dist + (real_T)b_i) + 0.5);
        if (tmp_0 < 256.0) {
          tmp = (uint8_T)tmp_0;
        } else {
          tmp = MAX_uint8_T;
        }

        buoyDetector_David_B.blob_hues[tmp - 1] =
          buoyDetector_David_B.ref_colors[(int32_T)
          buoyDetector_David_B.LabelMatrix[((int32_T)c - 1) * 120 + ((int32_T)
          index - 1)] - 1];
      }

      /* '<S18>:1:72' */
      min_dist++;

      /* TNumBlobs; */
    }
  }

  buoyDetector_David_B.blob_count = min_dist;

  /* Embedded MATLAB: '<S4>/Analyze LabelMatrix for Buoys' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   */
  /* Embedded MATLAB Function 'Look for Buoys/Analyze LabelMatrix for Buoys': '<S17>:1' */
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
  /* persistent successive_valid_image_count; */
  /* '<S17>:1:33' */
  min_dist = 0.0;

  /* debug */
  /* successive_valid_image_count = 0; */
  /* /debug */
  /* '<S17>:1:41' */
  memset((void *)&rtb_buoy_hues[0], 0, 50U * sizeof(real_T));

  /* '<S17>:1:42' */
  for (i = 0; i < 100; i++) {
    rtb_buoy_centroids[i] = -500.0;
  }

  /*  Initialize to points clearly not located in image */
  /* '<S17>:1:44' */
  for (i = 0; i < 50; i++) {
    rtb_buoy_id[i] = -1.0;
  }

  /* '<S17>:1:45' */
  /* '<S17>:1:47' */
  /* '<S17>:1:48' */
  /*  Loop through blobs, and analyze and extract buoy information */
  /* '<S17>:1:51' */
  for (index = 1.0; index <= buoyDetector_David_B.blob_count; index++) {
    /* '<S17>:1:51' */
    /*  Convert Lab to XYZ */
    /*  Convert XYZ to RGB */
    /*  Convert RGB to HSV */
    /*  RGB from 0 to 255 */
    /*  Min. value of RGB */
    /*  Max. value of RGB */
    /*  Delta RGB value */
    /*  Store buoy information if blob conditions are met */
    /*    Conditions: 1) Blob eccentricity is within specified range */
    /*                2) Blob extent is within specified range */
    /*                3) Blob hue is within specified range for several buoy */
    /*                  types */
    if ((buoyDetector_David_B.blob_eccentricity[(int32_T)index - 1] >=
         buoyDetector_David_P.Constant_Value) &&
        (buoyDetector_David_B.blob_eccentricity[(int32_T)index - 1] <=
         buoyDetector_David_P.Constant1_Value_o) &&
        (buoyDetector_David_B.blob_extent[(int32_T)index - 1] >=
         buoyDetector_David_P.Constant2_Value_k) &&
        (buoyDetector_David_B.blob_extent[(int32_T)index - 1] <=
         buoyDetector_David_P.Constant3_Value_b)) {
      /* '<S17>:1:107' */
      /* if( (blob_hues(i)>=Buoy1_Hue-Buoy_Hue_HalfRange) && (blob_hues(i)<=Buoy1_Hue+Buoy_Hue_HalfRange) ) */
      /* '<S17>:1:110' */
      min_dist++;

      /* '<S17>:1:111' */
      rtb_buoy_hues[(int32_T)min_dist - 1] = buoyDetector_David_B.blob_hues
        [(int32_T)index - 1];

      /* '<S17>:1:112' */
      rtb_buoy_id[(int32_T)min_dist - 1] = 1.0;

      /* '<S17>:1:113' */
      rtb_buoy_centroids[(int32_T)min_dist - 1] =
        buoyDetector_David_B.blob_centroids[(int32_T)index - 1];

      /* '<S17>:1:114' */
      rtb_buoy_centroids[(int32_T)min_dist + 49] =
        buoyDetector_David_B.blob_centroids[(int32_T)index + 49];

      /* end */
      if ((buoyDetector_David_B.blob_hues[(int32_T)index - 1] >= 70.0) &&
          (buoyDetector_David_B.blob_hues[(int32_T)index - 1] <= 90.0)) {
        /* '<S17>:1:116' */
        /* '<S17>:1:117' */
        min_dist++;

        /* '<S17>:1:118' */
        rtb_buoy_hues[(int32_T)min_dist - 1] = buoyDetector_David_B.blob_hues
          [(int32_T)index - 1];

        /* '<S17>:1:119' */
        rtb_buoy_id[(int32_T)min_dist - 1] = 2.0;

        /* '<S17>:1:120' */
        rtb_buoy_centroids[(int32_T)min_dist - 1] =
          buoyDetector_David_B.blob_centroids[(int32_T)index - 1];

        /* '<S17>:1:121' */
        rtb_buoy_centroids[(int32_T)min_dist + 49] =
          buoyDetector_David_B.blob_centroids[(int32_T)index + 49];
      }

      if ((buoyDetector_David_B.blob_hues[(int32_T)index - 1] >= 5.0) &&
          (buoyDetector_David_B.blob_hues[(int32_T)index - 1] <= 25.0)) {
        /* '<S17>:1:123' */
        /* '<S17>:1:124' */
        min_dist++;

        /* '<S17>:1:125' */
        rtb_buoy_hues[(int32_T)min_dist - 1] = buoyDetector_David_B.blob_hues
          [(int32_T)index - 1];

        /* '<S17>:1:126' */
        rtb_buoy_id[(int32_T)min_dist - 1] = 3.0;

        /* '<S17>:1:127' */
        rtb_buoy_centroids[(int32_T)min_dist - 1] =
          buoyDetector_David_B.blob_centroids[(int32_T)index - 1];

        /* '<S17>:1:128' */
        rtb_buoy_centroids[(int32_T)min_dist + 49] =
          buoyDetector_David_B.blob_centroids[(int32_T)index + 49];
      }
    }
  }

  if (min_dist >= buoyDetector_David_P.Constant4_Value) {
    /* '<S17>:1:134' */
    /* '<S17>:1:135' */
    buoyDetector_David_B.successive_valid_image_count_ou =
      rtb_SuccessiveValidImageCount + 1.0;
  } else {
    /* '<S17>:1:137' */
    buoyDetector_David_B.successive_valid_image_count_ou = 0.0;
  }

  /*  Resize output arrays */
  /* buoy_hues = buoy_hues(1:buoy_count); */
  /* buoy_centroids = buoy_centroids(1:buoy_count,:); */
  /* buoy_id = ; */
  rtb_buoy_count = min_dist;

  /* Outport: '<Root>/Number of Buoys' */
  buoyDetector_David_Y.NumberofBuoys = rtb_buoy_count;

  /* Embedded MATLAB: '<S1>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'Display Analyzed Image/Embedded MATLAB Function': '<S6>:1' */
  /*  This function puts together the segmented imaged such that it can be shown */
  /* '<S6>:1:5' */
  /* '<S6>:1:6' */
  /* '<S6>:1:7' */
  /* '<S6>:1:9' */
  for (i = 0; i < 120; i++) {
    /* '<S6>:1:9' */
    /* '<S6>:1:10' */
    for (j = 0; j < 160; j++) {
      /* '<S6>:1:10' */
      /* '<S6>:1:11' */
      buoyDetector_David_B.L[i + 120 * j] = buoyDetector_David_B.ref_colors
        [(int32_T)buoyDetector_David_B.LabelMatrix[120 * j + i] - 1];

      /* '<S6>:1:12' */
      buoyDetector_David_B.a[i + 120 * j] = buoyDetector_David_B.ref_colors
        [(int32_T)buoyDetector_David_B.LabelMatrix[120 * j + i] + 49];

      /* '<S6>:1:13' */
      buoyDetector_David_B.b[i + 120 * j] = buoyDetector_David_B.ref_colors
        [(int32_T)buoyDetector_David_B.LabelMatrix[120 * j + i] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 19200; i++) {
    index = (buoyDetector_David_B.L[i] + 16.0) / 116.0;
    min_dist = buoyDetector_David_B.a[i] / 500.0 + index;
    num_colors_0 = buoyDetector_David_B.b[i] / -200.0 + index;
    if (min_dist <= 0.20689655172413793) {
      min_dist -= 0.13793103448275862;
      min_dist /= 7.7870370370370372;
    } else {
      min_dist = rt_pow_snf(min_dist, 3.0);
    }

    if (index <= 0.20689655172413793) {
      index -= 0.13793103448275862;
      index /= 7.7870370370370372;
    } else {
      index = rt_pow_snf(index, 3.0);
    }

    if (num_colors_0 <= 0.20689655172413793) {
      num_colors_0 -= 0.13793103448275862;
      num_colors_0 /= 7.7870370370370372;
    } else {
      num_colors_0 = rt_pow_snf(num_colors_0, 3.0);
    }

    min_dist *= 0.9641986557609;
    num_colors_0 *= 0.82511648322104;

    /* assign the results */
    buoyDetector_David_B.ColorSpaceConversion_o1[i] = min_dist;
    buoyDetector_David_B.ColorSpaceConversion_o2[i] = index;
    buoyDetector_David_B.ColorSpaceConversion_o3[i] = num_colors_0;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    min_dist = (3.24096994190451 *
                buoyDetector_David_B.ColorSpaceConversion_o1[i] +
                -1.53738317757009 *
                buoyDetector_David_B.ColorSpaceConversion_o2[i]) +
      -0.49861076029299 * buoyDetector_David_B.ColorSpaceConversion_o3[i];
    index = (-0.96924363628087 * buoyDetector_David_B.ColorSpaceConversion_o1[i]
             + 1.87596750150771 * buoyDetector_David_B.ColorSpaceConversion_o2[i])
      + 0.04155505740718 * buoyDetector_David_B.ColorSpaceConversion_o3[i];
    num_colors_0 = (0.055630079697 *
                    buoyDetector_David_B.ColorSpaceConversion_o1[i] +
                    -0.20397695888899 *
                    buoyDetector_David_B.ColorSpaceConversion_o2[i]) +
      1.05697151424288 * buoyDetector_David_B.ColorSpaceConversion_o3[i];

    /* Apply gamma correction to get R'G'B' */
    if (min_dist <= 0.00304) {
      min_dist *= 12.923054468333255;
    } else {
      min_dist = 1.0550005198172263 * rt_pow_snf(min_dist, 0.41666666666666669)
        - 0.055000519817226347;
    }

    if (index <= 0.00304) {
      index *= 12.923054468333255;
    } else {
      index = 1.0550005198172263 * rt_pow_snf(index, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (num_colors_0 <= 0.00304) {
      num_colors_0 *= 12.923054468333255;
    } else {
      num_colors_0 = 1.0550005198172263 * rt_pow_snf(num_colors_0,
        0.41666666666666669) - 0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (min_dist > 1.0) {
      min_dist = 1.0;
    } else {
      if (min_dist < 0.0) {
        min_dist = 0.0;
      }
    }

    if (index > 1.0) {
      index = 1.0;
    } else {
      if (index < 0.0) {
        index = 0.0;
      }
    }

    if (num_colors_0 > 1.0) {
      num_colors_0 = 1.0;
    } else {
      if (num_colors_0 < 0.0) {
        num_colors_0 = 0.0;
      }
    }

    /* assign the results */
    buoyDetector_David_B.ColorSpaceConversion_o1[i] = min_dist;
    buoyDetector_David_B.ColorSpaceConversion_o2[i] = index;
    buoyDetector_David_B.ColorSpaceConversion_o3[i] = num_colors_0;
  }

  /* Embedded MATLAB: '<S1>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'Display Analyzed Image/Embedded MATLAB Function1': '<S7>:1' */
  /*  This function combines the separate color signals into a single 3-D signal */
  /* '<S7>:1:6' */
  memset((void *)(&buoyDetector_David_B.RGB_m[0]), 0, 57600U * sizeof(real_T));

  /* '<S7>:1:8' */
  for (i = 0; i < 120; i++) {
    /* '<S7>:1:8' */
    /* '<S7>:1:9' */
    for (j = 0; j < 160; j++) {
      /* '<S7>:1:9' */
      /* '<S7>:1:10' */
      buoyDetector_David_B.RGB_m[i + 120 * j] =
        buoyDetector_David_B.ColorSpaceConversion_o1[120 * j + i];

      /* '<S7>:1:11' */
      buoyDetector_David_B.RGB_m[19200 + (i + 120 * j)] =
        buoyDetector_David_B.ColorSpaceConversion_o2[120 * j + i];

      /* '<S7>:1:12' */
      buoyDetector_David_B.RGB_m[38400 + (i + 120 * j)] =
        buoyDetector_David_B.ColorSpaceConversion_o3[120 * j + i];
    }
  }

  /* Embedded MATLAB: '<S1>/Convert Array' */
  /* Embedded MATLAB Function 'Display Analyzed Image/Convert Array': '<S5>:1' */
  /*  Convert buoy_centroids from 2xN to Nx2 matrix. This is necessary for the */
  /*  Draw Markers block. */
  /*  */
  /*  Input */
  /*    buoy_centroids = Nx2 matrix of buoy centroid locations */
  /*  */
  /*  Output */
  /*    buoy_centroids_mod = 2xN matrix of buoy centroid locations */
  /* '<S5>:1:12' */
  for (i = 0; i < 50; i++) {
    rtb_buoy_centroids_mod[i << 1] = rtb_buoy_centroids[i];
    rtb_buoy_centroids_mod[1 + (i << 1)] = rtb_buoy_centroids[i + 50];
  }

  /* S-Function (svipdrawmarkers): '<S1>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&buoyDetector_David_B.DrawMarkers[0]), (void *)
         (&buoyDetector_David_B.RGB_m[0]), 57600U * sizeof(real_T));

  /* Draw all X marks. */
  tmp_0 = buoyDetector_David_P.DrawMarkers_RTP_SIZE;
  if ((buoyDetector_David_P.DrawMarkers_RTP_SIZE < 4.503599627370496E+15) &&
      (buoyDetector_David_P.DrawMarkers_RTP_SIZE > -4.503599627370496E+15)) {
    tmp_0 = floor(buoyDetector_David_P.DrawMarkers_RTP_SIZE + 0.5);
  }

  size = (int32_T)tmp_0;
  for (idxROI = 0; idxROI < 100; idxROI += 2) {
    tmp_0 = rtb_buoy_centroids_mod[idxROI];
    if ((rtb_buoy_centroids_mod[idxROI] < 4.503599627370496E+15) &&
        (rtb_buoy_centroids_mod[idxROI] > -4.503599627370496E+15)) {
      tmp_0 = floor(rtb_buoy_centroids_mod[idxROI] + 0.5);
    }

    row = (int32_T)tmp_0;
    tmp_0 = rtb_buoy_centroids_mod[idxROI + 1];
    if ((rtb_buoy_centroids_mod[idxROI + 1] < 4.503599627370496E+15) &&
        (rtb_buoy_centroids_mod[idxROI + 1] > -4.503599627370496E+15)) {
      tmp_0 = floor(rtb_buoy_centroids_mod[idxROI + 1] + 0.5);
    }

    col = (int32_T)tmp_0;
    line_idx_2 = row - size;
    line_idx_1 = col - size;
    line_idx_0 = row + size;
    line_idx = col + size;
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
      OutCode = 0;
      i = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_6 > 119) {
          OutCode = 8;
        }
      }

      if (line_idx_4 < 0) {
        i = 4;
      } else {
        if (line_idx_4 > 119) {
          i = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_5 > 159) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (line_idx_3 < 0) {
        i = (int32_T)((uint32_T)i | 1U);
      } else {
        if (line_idx_3 > 159) {
          i = (int32_T)((uint32_T)i | 2U);
        }
      }

      if (!((uint32_T)OutCode | (uint32_T)i)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)OutCode & (uint32_T)i) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
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
          num_colors = (119 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 119;
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
          num_colors = (159 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 159;
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
        if ((uint32_T)i & 4U) {
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
        } else if ((uint32_T)i & 8U) {
          /* Violated RMax. */
          num_colors = (119 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)i & 1U) {
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
          num_colors = (159 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      j = line_idx_5 * 120 + line_idx_6;
      for (num_colors = line_idx_6; num_colors <= line_idx_4; num_colors++) {
        buoyDetector_David_B.DrawMarkers[j] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[0];
        line_idx_2 = j + 19200;
        buoyDetector_David_B.DrawMarkers[line_idx_2] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[1];
        line_idx_2 += 19200;
        buoyDetector_David_B.DrawMarkers[line_idx_2] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[2];
        j += 121;
      }
    }

    line_idx_2 = row - size;
    line_idx_1 = col + size;
    line_idx_0 = row + size;
    line_idx = col - size;
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
      OutCode = 0;
      i = 0;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_6 > 119) {
          OutCode = 8;
        }
      }

      if (line_idx_4 < 0) {
        i = 4;
      } else {
        if (line_idx_4 > 119) {
          i = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_5 > 159) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (line_idx_3 < 0) {
        i = (int32_T)((uint32_T)i | 1U);
      } else {
        if (line_idx_3 > 159) {
          i = (int32_T)((uint32_T)i | 2U);
        }
      }

      if (!((uint32_T)OutCode | (uint32_T)i)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)OutCode & (uint32_T)i) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
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
          num_colors = (119 - line_idx_6) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_5 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_6 = 119;
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
          num_colors = (159 - line_idx_5) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_6 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_5 = 159;
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
        if ((uint32_T)i & 4U) {
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
        } else if ((uint32_T)i & 8U) {
          /* Violated RMax. */
          num_colors = (119 - line_idx_4) * j;
          if (((num_colors >= 0) && (flag >= 0)) || ((num_colors < 0) && (flag <
                0))) {
            line_idx_3 += (div_s32_floor(num_colors << 1U, flag) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-num_colors) << 1U, flag) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)i & 1U) {
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
          num_colors = (159 - line_idx_3) * flag;
          if (((num_colors >= 0) && (j >= 0)) || ((num_colors < 0) && (j < 0)))
          {
            line_idx_4 += (div_s32_floor(num_colors << 1U, j) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-num_colors) << 1U, j) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      j = line_idx_5 * 120 + line_idx_6;
      for (num_colors = line_idx_6; num_colors <= line_idx_4; num_colors++) {
        buoyDetector_David_B.DrawMarkers[j] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[0];
        line_idx_2 = j + 19200;
        buoyDetector_David_B.DrawMarkers[line_idx_2] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[1];
        line_idx_2 += 19200;
        buoyDetector_David_B.DrawMarkers[line_idx_2] =
          buoyDetector_David_P.DrawMarkers_RTP_FILLCOLOR[2];
        j += -119;
      }
    }
  }

  /* Embedded MATLAB: '<S3>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'IterativeSegmentation/Embedded MATLAB Function1': '<S8>:1' */
  /*  This function combines the separate color signals into a single 3-D signal */
  /* '<S8>:1:6' */
  memset((void *)(&buoyDetector_David_B.RGB[0]), 0, 57600U * sizeof(real_T));

  /* '<S8>:1:8' */
  for (i = 0; i < 120; i++) {
    /* '<S8>:1:8' */
    /* '<S8>:1:9' */
    for (j = 0; j < 160; j++) {
      /* '<S8>:1:9' */
      /* '<S8>:1:10' */
      buoyDetector_David_B.RGB[i + 120 * j] =
        buoyDetector_David_B.sf_LowPassFilter.Iout[120 * j + i];

      /* '<S8>:1:11' */
      buoyDetector_David_B.RGB[19200 + (i + 120 * j)] =
        buoyDetector_David_B.sf_LowPassFilter1.Iout[120 * j + i];

      /* '<S8>:1:12' */
      buoyDetector_David_B.RGB[38400 + (i + 120 * j)] =
        buoyDetector_David_B.sf_LowPassFilter2.Iout[120 * j + i];
    }
  }

  /* ToWorkspace: '<Root>/To Workspace' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace_PWORK.LoggedData),
                  buoyDetector_David_B.LabelMatrix, 0);

  /* ToWorkspace: '<Root>/To Workspace1' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace1_PWORK.LoggedData),
                  &buoyDetector_David_B.num_colors, 0);

  /* ToWorkspace: '<Root>/To Workspace2' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace2_PWORK.LoggedData),
                  buoyDetector_David_B.ref_colors, 0);

  /* ToWorkspace: '<Root>/To Workspace3' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace3_PWORK.LoggedData),
                  &buoyDetector_David_B.successive_valid_image_count_ou, 0);

  /* ToWorkspace: '<Root>/To Workspace4' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace4_PWORK.LoggedData),
                  &rtb_buoy_count, 0);

  /* ToWorkspace: '<Root>/To Workspace5' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace5_PWORK.LoggedData),
                  rtb_buoy_hues, 0);

  /* ToWorkspace: '<Root>/To Workspace6' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace6_PWORK.LoggedData),
                  rtb_buoy_centroids, 0);

  /* ToWorkspace: '<Root>/To Workspace7' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace7_PWORK.LoggedData),
                  rtb_buoy_id, 0);

  /* ToWorkspace: '<S4>/To Workspace1' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace1_PWORK_f.LoggedData),
                  buoyDetector_David_B.blob_hues, 0);

  /* ToWorkspace: '<S4>/To Workspace2' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace2_PWORK_i.LoggedData),
                  buoyDetector_David_B.blob_centroids, 0);

  /* ToWorkspace: '<S4>/To Workspace3' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace3_PWORK_p.LoggedData),
                  buoyDetector_David_B.blob_eccentricity, 0);

  /* ToWorkspace: '<S4>/To Workspace4' */
  rt_UpdateLogVar((LogVar *)(LogVar*)
                  (buoyDetector_David_DWork.ToWorkspace4_PWORK_e.LoggedData),
                  buoyDetector_David_B.blob_extent, 0);

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void buoyDetector_David_update(int_T tid)
{
  /* Update for Memory: '<Root>/Successive Valid Image Count' */
  buoyDetector_David_DWork.SuccessiveValidImageCount_Previ =
    buoyDetector_David_B.successive_valid_image_count_ou;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++buoyDetector_David_M->Timing.clockTick0)) {
    ++buoyDetector_David_M->Timing.clockTickH0;
  }

  buoyDetector_David_M->Timing.t[0] = buoyDetector_David_M->Timing.clockTick0 *
    buoyDetector_David_M->Timing.stepSize0 +
    buoyDetector_David_M->Timing.clockTickH0 *
    buoyDetector_David_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void buoyDetector_David_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)buoyDetector_David_M, 0,
                sizeof(RT_MODEL_buoyDetector_David));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = buoyDetector_David_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    buoyDetector_David_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    buoyDetector_David_M->Timing.sampleTimes =
      (&buoyDetector_David_M->Timing.sampleTimesArray[0]);
    buoyDetector_David_M->Timing.offsetTimes =
      (&buoyDetector_David_M->Timing.offsetTimesArray[0]);

    /* task periods */
    buoyDetector_David_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    buoyDetector_David_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(buoyDetector_David_M, &buoyDetector_David_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = buoyDetector_David_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    buoyDetector_David_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(buoyDetector_David_M, -1);
  buoyDetector_David_M->Timing.stepSize0 = 0.033333333333333333;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    buoyDetector_David_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(buoyDetector_David_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(buoyDetector_David_M->rtwLogInfo, (NULL));
    rtliSetLogT(buoyDetector_David_M->rtwLogInfo, "tout");
    rtliSetLogX(buoyDetector_David_M->rtwLogInfo, "");
    rtliSetLogXFinal(buoyDetector_David_M->rtwLogInfo, "");
    rtliSetSigLog(buoyDetector_David_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(buoyDetector_David_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(buoyDetector_David_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(buoyDetector_David_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(buoyDetector_David_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &buoyDetector_David_Y.NumberofBuoys
      };

      rtliSetLogYSignalPtrs(buoyDetector_David_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "buoyDetector_David/Number of Buoys" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(buoyDetector_David_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(buoyDetector_David_M->rtwLogInfo, "yout");
  }

  buoyDetector_David_M->solverInfoPtr = (&buoyDetector_David_M->solverInfo);
  buoyDetector_David_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&buoyDetector_David_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&buoyDetector_David_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  buoyDetector_David_M->ModelData.blockIO = ((void *) &buoyDetector_David_B);
  (void) memset(((void *) &buoyDetector_David_B), 0,
                sizeof(BlockIO_buoyDetector_David));

  /* parameters */
  buoyDetector_David_M->ModelData.defaultParam = ((real_T *)
    &buoyDetector_David_P);

  /* states (dwork) */
  buoyDetector_David_M->Work.dwork = ((void *) &buoyDetector_David_DWork);
  (void) memset((void *)&buoyDetector_David_DWork, 0,
                sizeof(D_Work_buoyDetector_David));

  /* external outputs */
  buoyDetector_David_M->ModelData.outputs = (&buoyDetector_David_Y);
  buoyDetector_David_Y.NumberofBuoys = 0.0;
}

/* Model terminate function */
void buoyDetector_David_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  buoyDetector_David_output(tid);
}

void MdlUpdate(int_T tid)
{
  buoyDetector_David_update(tid);
}

void MdlInitializeSizes(void)
{
  buoyDetector_David_M->Sizes.numContStates = (0);/* Number of continuous states */
  buoyDetector_David_M->Sizes.numY = (1);/* Number of model outputs */
  buoyDetector_David_M->Sizes.numU = (0);/* Number of model inputs */
  buoyDetector_David_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  buoyDetector_David_M->Sizes.numSampTimes = (1);/* Number of sample times */
  buoyDetector_David_M->Sizes.numBlocks = (53);/* Number of blocks */
  buoyDetector_David_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  buoyDetector_David_M->Sizes.numBlockPrms = (57612);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;
    static int8_T tmp[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

    /* InitializeConditions for Memory: '<Root>/Successive Valid Image Count' */
    buoyDetector_David_DWork.SuccessiveValidImageCount_Previ =
      buoyDetector_David_P.SuccessiveValidImageCount_X0;

    /* InitializeConditions for Embedded MATLAB: '<S4>/Blob Extraction' */
    for (i = 0; i < 8; i++) {
      buoyDetector_David_DWork.WALKER_RTP[i] = tmp[i];
    }

    buoyDetector_David_DWork.F0_RTP = -1.0;
    buoyDetector_David_DWork.F1_RTP = -1.0;
    buoyDetector_David_DWork.F2_RTP = -1.0;
    buoyDetector_David_DWork.MINAREA_RTP = 5U;
  }
}

void MdlStart(void)
{
  /* Start for ToWorkspace: '<Root>/To Workspace' */
  {
    int_T dimensions[2] = { 120, 160 };

    buoyDetector_David_DWork.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "LabelMatrix",
      SS_DOUBLE,
      0,
      0,
      0,
      19200,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 1 };

    buoyDetector_David_DWork.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "num_colors",
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
    if (buoyDetector_David_DWork.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace2' */
  {
    int_T dimensions[2] = { 50, 3 };

    buoyDetector_David_DWork.ToWorkspace2_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "ref_colors",
      SS_DOUBLE,
      0,
      0,
      0,
      150,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace3' */
  {
    int_T dimensions[1] = { 1 };

    buoyDetector_David_DWork.ToWorkspace3_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "successive_valid_image_count",
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
    if (buoyDetector_David_DWork.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace4' */
  {
    int_T dimensions[1] = { 1 };

    buoyDetector_David_DWork.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "buoy_count",
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
    if (buoyDetector_David_DWork.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace5' */
  {
    int_T dimensions[1] = { 50 };

    buoyDetector_David_DWork.ToWorkspace5_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "buoy_hues",
      SS_DOUBLE,
      0,
      0,
      0,
      50,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace6' */
  {
    int_T dimensions[2] = { 50, 2 };

    buoyDetector_David_DWork.ToWorkspace6_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "buoy_centroids",
      SS_DOUBLE,
      0,
      0,
      0,
      100,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace6_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<Root>/To Workspace7' */
  {
    int_T dimensions[1] = { 50 };

    buoyDetector_David_DWork.ToWorkspace7_PWORK.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "buoy_id",
      SS_DOUBLE,
      0,
      0,
      0,
      50,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace7_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S4>/To Workspace1' */
  {
    int_T dimensions[2] = { 50, 3 };

    buoyDetector_David_DWork.ToWorkspace1_PWORK_f.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "blob_hues",
      SS_DOUBLE,
      0,
      0,
      0,
      150,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace1_PWORK_f.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S4>/To Workspace2' */
  {
    int_T dimensions[2] = { 50, 2 };

    buoyDetector_David_DWork.ToWorkspace2_PWORK_i.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "blob_centroids",
      SS_DOUBLE,
      0,
      0,
      0,
      100,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace2_PWORK_i.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S4>/To Workspace3' */
  {
    int_T dimensions[1] = { 50 };

    buoyDetector_David_DWork.ToWorkspace3_PWORK_p.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "blob_eccentricity",
      SS_DOUBLE,
      0,
      0,
      0,
      50,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace3_PWORK_p.LoggedData == (NULL))
      return;
  }

  /* Start for ToWorkspace: '<S4>/To Workspace4' */
  {
    int_T dimensions[1] = { 50 };

    buoyDetector_David_DWork.ToWorkspace4_PWORK_e.LoggedData = rt_CreateLogVar(
      buoyDetector_David_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(buoyDetector_David_M),
      buoyDetector_David_M->Timing.stepSize0,
      (&rtmGetErrorStatus(buoyDetector_David_M)),
      "blob_extent",
      SS_DOUBLE,
      0,
      0,
      0,
      50,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      0,
      1,
      0.033333333333333333,
      1);
    if (buoyDetector_David_DWork.ToWorkspace4_PWORK_e.LoggedData == (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  buoyDetector_David_terminate();
}

RT_MODEL_buoyDetector_David *buoyDetector_David(void)
{
  buoyDetector_David_initialize(1);
  return buoyDetector_David_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
