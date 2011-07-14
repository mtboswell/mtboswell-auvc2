/*
 * File: path_detector.cpp
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.365
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun 28 18:13:07 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun 28 18:13:08 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "path_detector.h"
#include "path_detector_private.h"

/* Forward declaration for local functions */
static void path_detector_Outputs(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8, rtDW_mr_path_detector *localDW);

/*
 * Output and update for atomic system:
 *    '<S8>/Low Pass Filter'
 *    '<S8>/Low Pass Filter1'
 *    '<S8>/Low Pass Filter2'
 */
void path_detector_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_path_detector *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S8>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S10>:1' */
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
  fcjmfkngfcbidjmo_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S10>:1:37' */
  for (i = 0; i < 158; i++) {
    localB->Iout[120 * (1 + i)] = localB->Itemp[118 * i];
  }

  /*  bottom */
  /* '<S10>:1:39' */
  for (i = 0; i < 158; i++) {
    localB->Iout[119 + 120 * (1 + i)] = localB->Itemp[118 * i + 117];
  }

  /*  left */
  /* '<S10>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 118U * sizeof
         (real_T));

  /*  right */
  /* '<S10>:1:43' */
  memcpy((void *)(&localB->Iout[19081]), (void *)(&localB->Itemp[18526]), 118U *
         sizeof(real_T));

  /*  center */
  /* '<S10>:1:45' */
  for (i = 0; i < 158; i++) {
    memcpy((void *)(&localB->Iout[1 + 120 * (1 + i)]), (void *)(&localB->Itemp
            [118 * i]), 118U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S10>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S10>:1:49' */
  localB->Iout[18960] = localB->Itemp[18408];
  localB->Iout[19080] = localB->Itemp[18526];

  /*  bottom left corner */
  /* '<S10>:1:51' */
  localB->Iout[118] = localB->Itemp[116];
  localB->Iout[119] = localB->Itemp[117];

  /*  bottom right corner */
  /* '<S10>:1:53' */
  localB->Iout[19078] = localB->Itemp[18524];
  localB->Iout[19079] = localB->Itemp[18525];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Function for Embedded MATLAB: '<S1>/Blob Extraction' */
static void path_detector_Outputs(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8, rtDW_mr_path_detector *localDW)
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
  memset((void *)(&localDW->PAD_DW[0]), (int32_T)0U, 123U * sizeof(uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (maxc = 0; maxc < 120; maxc++) {
      localDW->PAD_DW[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    localDW->PAD_DW[idx] = 0U;
    idx++;
    localDW->PAD_DW[idx] = 0U;
    idx++;
  }

  memset((void *)(&localDW->PAD_DW[idx]), (int32_T)0U, 121U * sizeof(uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    maxc = 1;
    idx = loop * 122;
    for (maxr = 0; maxr < 120; maxr++) {
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
          for (j = 0; j < 8; j++) {
            walkerIdx = k + (uint32_T)localDW->WALKER_RTP[j];
            if (localDW->PAD_DW[walkerIdx] == 255) {
              localDW->PAD_DW[walkerIdx] = currentLabel;
              localDW->N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)(walkerIdx /
                122U) - 1);
              localDW->M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx % 122U - 1U);
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
  *Y8 = (uint8_T)numBlobs;
  pixListMinc = 0;
  pixListNinc = 0;
  for (c_i = 0; c_i < numBlobs; c_i++) {
    Y0[c_i] = (int32_T)localDW->NUM_PIX_DW[c_i];
    loop = 0;
    n = 0;
    for (j = 0; j < (int32_T)localDW->NUM_PIX_DW[c_i]; j++) {
      loop += localDW->N_PIXLIST_DW[j + pixListNinc];
      n += localDW->M_PIXLIST_DW[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)localDW->NUM_PIX_DW[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)localDW->NUM_PIX_DW[c_i];
    Y1[c_i << 1] = centroid_idx;
    Y1[(c_i << 1) + 1] = centroid_idx_0;
    n = 160;
    idx = 120;
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
    for (k = 0U; (int32_T)k < (int32_T)localDW->NUM_PIX_DW[c_i]; k++) {
      uxy = (real_T)localDW->N_PIXLIST_DW[pixListNinc + (int32_T)k] -
        centroid_idx_0;
      common = (real_T)localDW->M_PIXLIST_DW[pixListMinc + (int32_T)k] -
        centroid_idx;
      xs += uxy * uxy;
      ys += common * common;
      xys += uxy * (-common);
    }

    centroid_idx = xs / (real_T)localDW->NUM_PIX_DW[c_i] + 0.083333333333333329;
    centroid_idx_0 = ys / (real_T)localDW->NUM_PIX_DW[c_i] +
      0.083333333333333329;
    uxy = xys / (real_T)localDW->NUM_PIX_DW[c_i];
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
    Y7[c_i] = (real_T)localDW->NUM_PIX_DW[c_i] / (real_T)(maxr * j);
    pixListMinc += (int32_T)localDW->NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)localDW->NUM_PIX_DW[c_i];
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y0[loop] = localDW->F0_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y1[loop] = localDW->F1_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 2); loop < 200; loop++) {
    Y2[loop] = localDW->F2_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y3[loop] = localDW->F3_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y4[loop] = localDW->F4_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y5[loop] = localDW->F5_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y6[loop] = localDW->F6_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y7[loop] = localDW->F7_RTP;
  }
}

/* Initial conditions for referenced model: 'path_detector' */
void mr_path_detector_Init(rtDW_mr_path_detector *localDW)
{
  int32_T i;
  static int8_T tmp[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

  /* InitializeConditions for Embedded MATLAB: '<S1>/Blob Extraction' */
  for (i = 0; i < 8; i++) {
    localDW->WALKER_RTP[i] = tmp[i];
  }

  localDW->F0_RTP = -1;
  localDW->F1_RTP = -1.0;
  localDW->F2_RTP = -1;
  localDW->F3_RTP = -1.0;
  localDW->F4_RTP = -1.0;
  localDW->F5_RTP = -1.0;
  localDW->F6_RTP = -1.0;
  localDW->F7_RTP = -1.0;
  localDW->MINAREA_RTP = 5U;

  /* InitializeConditions for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 5.2083333333333337E-5;
  for (i = 0; i < 6; i++) {
    localDW->EdgeDetection_VO_DW[i] =
      path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
      path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    if (path_detector_ConstP.EdgeDetection_VCO_RTP[i] > 0) {
      localDW->EdgeDetection_VOU_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOD_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
    } else {
      localDW->EdgeDetection_VOU_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
      localDW->EdgeDetection_VOD_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    }

    if (path_detector_ConstP.EdgeDetection_VRO_RTP[i] > 0) {
      localDW->EdgeDetection_VOL_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOR_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    } else {
      localDW->EdgeDetection_VOL_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOR_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[i] < 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[i] < 0)) {
      localDW->EdgeDetection_VOUL_DW[i] = 0;
      localDW->EdgeDetection_VOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[i] >= 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[i] < 0)) {
      localDW->EdgeDetection_VOLL_DW[i] = 0;
      localDW->EdgeDetection_VOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[i] < 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[i] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[i] = 0;
      localDW->EdgeDetection_VOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
      localDW->EdgeDetection_VOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    }

    if ((path_detector_ConstP.EdgeDetection_VCO_RTP[i] >= 0) &&
        (path_detector_ConstP.EdgeDetection_VRO_RTP[i] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[i] = 0;
      localDW->EdgeDetection_VOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
      localDW->EdgeDetection_VOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_VRO_RTP[i] * 120;
      localDW->EdgeDetection_VOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_VCO_RTP[i];
    }

    localDW->EdgeDetection_HO_DW[i] =
      path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
      path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    if (path_detector_ConstP.EdgeDetection_HCO_RTP[i] > 0) {
      localDW->EdgeDetection_HOU_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOD_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
    } else {
      localDW->EdgeDetection_HOU_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
      localDW->EdgeDetection_HOD_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    }

    if (path_detector_ConstP.EdgeDetection_HRO_RTP[i] > 0) {
      localDW->EdgeDetection_HOL_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOR_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    } else {
      localDW->EdgeDetection_HOL_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOR_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[i] < 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[i] < 0)) {
      localDW->EdgeDetection_HOUL_DW[i] = 0;
      localDW->EdgeDetection_HOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[i] >= 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[i] < 0)) {
      localDW->EdgeDetection_HOLL_DW[i] = 0;
      localDW->EdgeDetection_HOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[i] < 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[i] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[i] = 0;
      localDW->EdgeDetection_HOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
      localDW->EdgeDetection_HOLR_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    }

    if ((path_detector_ConstP.EdgeDetection_HCO_RTP[i] >= 0) &&
        (path_detector_ConstP.EdgeDetection_HRO_RTP[i] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[i] = 0;
      localDW->EdgeDetection_HOUL_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120 +
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
      localDW->EdgeDetection_HOLL_DW[i] =
        path_detector_ConstP.EdgeDetection_HRO_RTP[i] * 120;
      localDW->EdgeDetection_HOUR_DW[i] =
        path_detector_ConstP.EdgeDetection_HCO_RTP[i];
    }
  }
}

/* Output and update for referenced model: 'path_detector' */
void mr_path_detector(const real_T rtu_R_in[19200], const real_T rtu_G_in[19200],
                      const real_T rtu_B_in[19200], const real_T *rtu_WhichPath,
                      real_T *rty_TargetSelect, real_T *rty_TargetFound, real_T *
                      rty_MaintainHeading, real_T *rty_TargetX, real_T
                      *rty_TargetY, real_T *rty_TargetYaw, real_T
                      *rty_TargetDetected, real_T *rty_PathState, real_T rty_R
                      [19200], real_T rty_G[19200], real_T rty_B[19200], real_T
                      rty_bw_image[19200], real_T rty_edge_image[19200], real_T
                      rty_line_image[19200], real_T rty_hough_table[71820],
                      real_T *rty_BlobCount, real_T rty_BlobHues[150], real_T
                      rty_Area[50], real_T rty_BBox[200], real_T rty_Centroid
                      [100], real_T rty_Eccentricity[50], real_T rty_Extent[50],
                      real_T rty_Orientation[50], real_T rty_path_headings[3],
                      real_T rty_MajorAxis[50], real_T rty_MinorAxis[50], real_T
                      rty_ref_colors[150], real_T rty_theta[200], real_T
                      rty_rho[200], real_T rty_debug_orientation[50], real_T
                      rty_LabelMatrix[19200], real_T *rty_num_colors,
                      rtB_mr_path_detector *localB, rtDW_mr_path_detector
                      *localDW)
{
  int32_T idxROI;
  int32_T idxStart;
  int32_T flag;
  int32_T j;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];
  real_T b_lower;
  real_T k;
  uint8_T b_i;
  int32_T TArea[50];
  real_T TCentroid[100];
  int32_T TBBox[200];
  real_T TExtent[50];
  uint8_T TNumBlobs;
  real_T maxValue;
  real_T maxval[160];
  int32_T iy;
  boolean_T searchingForNonNaN;
  boolean_T b_searchingForNonNaN;
  boolean_T guard;
  boolean_T exitg;
  boolean_T exitg_0;
  real_T theta[200];
  real_T path_locations[6];
  int8_T found[3];
  real_T value[3];
  real_T matr[9];
  int8_T b_j_index[3];
  int32_T b_found;
  int32_T imgIdxLL;
  int32_T imgIdxUR;
  real_T accumTwo;
  int32_T m;
  real_T accumThree;
  real_T accumFour;
  real_T Resize2_LineBuffer[120];
  int32_T rtb_DataTypeConversion5[100];
  real_T rtb_theta_out[200];
  real_T rtb_rho_out[200];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  uint8_T tmp;
  int8_T b_j_index_0;

  /* Constant: '<Root>/ColorFilter1' */
  (*rty_TargetSelect) = 2.0;

  /* Constant: '<Root>/ColorFilter2' */
  (*rty_TargetFound) = 1.0;

  /* Constant: '<Root>/ColorFilter3' */
  (*rty_MaintainHeading) = 1.0;

  /* Embedded MATLAB: '<S8>/Low Pass Filter' */
  path_detector_LowPassFilter(rtu_R_in, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S8>/Low Pass Filter1' */
  path_detector_LowPassFilter(rtu_G_in, &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S8>/Low Pass Filter2' */
  path_detector_LowPassFilter(rtu_B_in, &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S7>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (imgIdxLL = 0; imgIdxLL < 19200; imgIdxLL++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[imgIdxLL] <= 0.039286085583733095) {
      b_lower = localB->sf_LowPassFilter.Iout[imgIdxLL] / 12.923054468333255;
    } else {
      b_lower = rt_pow_snf((localB->sf_LowPassFilter.Iout[imgIdxLL] +
                            0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter1.Iout[imgIdxLL] <= 0.039286085583733095) {
      maxValue = localB->sf_LowPassFilter1.Iout[imgIdxLL] / 12.923054468333255;
    } else {
      maxValue = rt_pow_snf((localB->sf_LowPassFilter1.Iout[imgIdxLL] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (localB->sf_LowPassFilter2.Iout[imgIdxLL] <= 0.039286085583733095) {
      accumTwo = localB->sf_LowPassFilter2.Iout[imgIdxLL] / 12.923054468333255;
    } else {
      accumTwo = rt_pow_snf((localB->sf_LowPassFilter2.Iout[imgIdxLL] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    accumThree = (0.41239079926596 * b_lower + 0.35758433938388 * maxValue) +
      0.18048078840183 * accumTwo;
    accumFour = (0.21263900587151 * b_lower + 0.71516867876776 * maxValue) +
      0.07219231536073 * accumTwo;
    maxValue = (0.01933081871559 * b_lower + 0.11919477979463 * maxValue) +
      0.95053215224966 * accumTwo;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (accumThree > 1.0) {
      accumThree = 1.0;
    } else {
      if (accumThree < 0.0) {
        accumThree = 0.0;
      }
    }

    if (accumFour > 1.0) {
      accumFour = 1.0;
    } else {
      if (accumFour < 0.0) {
        accumFour = 0.0;
      }
    }

    if (maxValue > 1.0) {
      maxValue = 1.0;
    } else {
      if (maxValue < 0.0) {
        maxValue = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxLL] = accumThree;
    localB->ColorSpaceConversion1_o2[imgIdxLL] = accumFour;
    localB->ColorSpaceConversion1_o3[imgIdxLL] = maxValue;
  }

  /* Convert from XYZ to L*a*b* */
  for (imgIdxLL = 0; imgIdxLL < 19200; imgIdxLL++) {
    maxValue = localB->ColorSpaceConversion1_o1[imgIdxLL] / 0.9641986557609;
    accumThree = localB->ColorSpaceConversion1_o3[imgIdxLL] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (maxValue > 0.0088564516790356311) {
      accumFour = rt_pow_snf(maxValue, 0.33333333333333331);
    } else {
      accumFour = 7.7870370370370372 * maxValue + 0.13793103448275862;
    }

    if (localB->ColorSpaceConversion1_o2[imgIdxLL] > 0.0088564516790356311) {
      accumTwo = rt_pow_snf(localB->ColorSpaceConversion1_o2[imgIdxLL],
                            0.33333333333333331);
    } else {
      accumTwo = 7.7870370370370372 * localB->ColorSpaceConversion1_o2[imgIdxLL]
        + 0.13793103448275862;
    }

    if (accumThree > 0.0088564516790356311) {
      maxValue = rt_pow_snf(accumThree, 0.33333333333333331);
    } else {
      maxValue = 7.7870370370370372 * accumThree + 0.13793103448275862;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[imgIdxLL] = 116.0 * accumTwo - 16.0;
    localB->ColorSpaceConversion1_o2[imgIdxLL] = (accumFour - accumTwo) * 500.0;
    localB->ColorSpaceConversion1_o3[imgIdxLL] = (accumTwo - maxValue) * 200.0;
  }

  /* S-Function (svipresize): '<S15>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (m = 0; m < 120; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      iy = j + 80;
      maxValue = localB->
        ColorSpaceConversion1_o1[path_detector_ConstP.pooled10[j] * 120 + m] *
        path_detector_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o1[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o1[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o1[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      localDW->Resize_IntBuffer[imgIdxLL] = maxValue;
      imgIdxLL += 120;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->Resize_IntBuffer[j
            * 120]), 120U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      iy = m + 60;
      maxValue = Resize2_LineBuffer[path_detector_ConstP.pooled9[m]] *
        path_detector_ConstP.pooled3[m] +
        Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      localB->Resize[flag] = maxValue;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S15>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (m = 0; m < 120; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      iy = j + 80;
      maxValue = localB->
        ColorSpaceConversion1_o2[path_detector_ConstP.pooled10[j] * 120 + m] *
        path_detector_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o2[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o2[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o2[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      localDW->Resize1_IntBuffer[imgIdxLL] = maxValue;
      imgIdxLL += 120;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[j * 120]), 120U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      iy = m + 60;
      maxValue = Resize2_LineBuffer[path_detector_ConstP.pooled9[m]] *
        path_detector_ConstP.pooled3[m] +
        Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      localB->Resize1[flag] = maxValue;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S15>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (m = 0; m < 120; m++) {
    imgIdxLL = m;
    for (j = 0; j < 80; j++) {
      iy = j + 80;
      maxValue = localB->
        ColorSpaceConversion1_o3[path_detector_ConstP.pooled10[j] * 120 + m] *
        path_detector_ConstP.pooled4[j] + localB->
        ColorSpaceConversion1_o3[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o3[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      iy += 80;
      maxValue += localB->
        ColorSpaceConversion1_o3[path_detector_ConstP.pooled10[iy] * 120 + m] *
        path_detector_ConstP.pooled4[iy];
      localDW->Resize2_IntBuffer[imgIdxLL] = maxValue;
      imgIdxLL += 120;
    }
  }

  for (j = 0; j < 80; j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[j * 120]), 120U * sizeof(real_T));
    for (m = 0; m < 60; m++) {
      iy = m + 60;
      maxValue = Resize2_LineBuffer[path_detector_ConstP.pooled9[m]] *
        path_detector_ConstP.pooled3[m] +
        Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      iy += 60;
      maxValue += Resize2_LineBuffer[path_detector_ConstP.pooled9[iy]] *
        path_detector_ConstP.pooled3[iy];
      localB->Resize2[flag] = maxValue;
      flag++;
    }
  }

  /* Embedded MATLAB: '<S9>/Reference Color Selection' incorporates:
   *  Constant: '<S9>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Segmentation/Reference Color Selection': '<S14>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S14>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S14>:1:14' */
  /* '<S14>:1:15' */
  memset((void *)(&rty_ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S14>:1:16' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0U, 4800U * sizeof(uint32_T));

  /* '<S14>:1:17' */
  b_found = 1;

  /*  Define first reference color to be colr */
  /* '<S14>:1:23' */
  rty_ref_colors[0] = localB->Resize[2369];
  rty_ref_colors[50] = localB->Resize1[2369];
  rty_ref_colors[100] = localB->Resize2[2369];

  /* '<S14>:1:25' */
  flag = 0;

  /* '<S14>:1:26' */
  imgIdxLL = 1;

  /* '<S14>:1:27' */
  j = 1;
  while (imgIdxLL <= 60) {
    /* '<S14>:1:28' */
    /*  perform initial segmentation */
    while ((imgIdxLL <= 60) && (flag == 0)) {
      /* '<S14>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S14>:1:30' */
        /* '<S14>:1:31' */
        k = 1.0;

        /* '<S14>:1:32' */
        maxValue = 1000.0;

        /* '<S14>:1:33' */
        accumTwo = 1.0;
        while ((uint32_T)k <= (uint32_T)b_found) {
          /* '<S14>:1:34' */
          /* '<S14>:1:35' */
          accumThree = sqrt((rt_pow_snf(rty_ref_colors[(int32_T)k + 49] -
            localB->Resize1[(j - 1) * 60 + (imgIdxLL - 1)], 2.0) * 1.5 +
                             rt_pow_snf(rty_ref_colors[(int32_T)k - 1] -
            localB->Resize[(j - 1) * 60 + (imgIdxLL - 1)], 2.0)) + rt_pow_snf
                            (rty_ref_colors[(int32_T)k + 99] - localB->Resize2
                             [(j - 1) * 60 + (imgIdxLL - 1)], 2.0) * 1.5);
          if (maxValue > accumThree) {
            /* '<S14>:1:36' */
            /* '<S14>:1:37' */
            maxValue = accumThree;

            /* '<S14>:1:38' */
            accumTwo = k;
          }

          /* '<S14>:1:40' */
          k++;
        }

        if ((maxValue > 30.0) && (b_found < 50)) {
          /* '<S14>:1:45' */
          /* '<S14>:1:46' */
          rty_ref_colors[b_found] = localB->Resize[(j - 1) * 60 + (imgIdxLL - 1)];
          rty_ref_colors[b_found + 50] = localB->Resize1[(j - 1) * 60 +
            (imgIdxLL - 1)];
          rty_ref_colors[b_found + 100] = localB->Resize2[(j - 1) * 60 +
            (imgIdxLL - 1)];

          /* '<S14>:1:47' */
          b_found++;

          /* '<S14>:1:48' */
          flag = 1;

          /* '<S14>:1:49' */
          imgIdxLL = 0;

          /* '<S14>:1:50' */
          j = 0;
        } else {
          /* '<S14>:1:52' */
          localB->LabelMatrix[(imgIdxLL - 1) + 60 * (j - 1)] = (uint32_T)
            accumTwo;
        }

        /* '<S14>:1:54' */
        j++;
      }

      /* '<S14>:1:56' */
      j = 1;

      /* '<S14>:1:57' */
      imgIdxLL++;
    }

    /* '<S14>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S14>:1:63' */
  /* '<S14>:1:64' */
  /* '<S14>:1:65' */
  /* '<S14>:1:66' */
  for (m = 0; m < 50; m++) {
    ref_color_L_avg[m] = 0.0;
    ref_color_a_avg[m] = 0.0;
    ref_color_b_avg[m] = 0.0;
    color_count[m] = 0.0;
  }

  /* '<S14>:1:67' */
  for (j = 0; j < 60; j++) {
    /* '<S14>:1:67' */
    /* '<S14>:1:68' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S14>:1:68' */
      /* '<S14>:1:69' */
      /* '<S14>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix[j + 60 * flag] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix[60 * flag + j] - 1] +
        localB->Resize[60 * flag + j];

      /* '<S14>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix[j + 60 * flag] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix[60 * flag + j] - 1] +
        localB->Resize1[60 * flag + j];

      /* '<S14>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix[j + 60 * flag] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix[60 * flag + j] - 1] +
        localB->Resize2[60 * flag + j];

      /* '<S14>:1:73' */
      color_count[(int32_T)localB->LabelMatrix[j + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix[60 * flag + j] - 1] + 1.0;
    }
  }

  /* '<S14>:1:76' */
  /* '<S14>:1:77' */
  /* '<S14>:1:78' */
  for (m = 0; m < 50; m++) {
    ref_color_L_avg[m] = ref_color_L_avg[m] / color_count[m];
    ref_color_a_avg[m] = ref_color_a_avg[m] / color_count[m];
    ref_color_b_avg[m] = ref_color_b_avg[m] / color_count[m];
  }

  /* '<S14>:1:80' */
  for (maxValue = 1.0; (uint32_T)maxValue <= (uint32_T)b_found; maxValue++) {
    /* '<S14>:1:80' */
    /* '<S14>:1:81' */
    rty_ref_colors[(int32_T)maxValue - 1] = ref_color_L_avg[(int32_T)maxValue -
      1];

    /* '<S14>:1:82' */
    rty_ref_colors[(int32_T)maxValue + 49] = ref_color_a_avg[(int32_T)maxValue -
      1];

    /* '<S14>:1:83' */
    rty_ref_colors[(int32_T)maxValue + 99] = ref_color_b_avg[(int32_T)maxValue -
      1];
  }

  (*rty_num_colors) = (real_T)b_found;

  /* Embedded MATLAB: '<S9>/LabSegmentation' */
  /* Embedded MATLAB Function 'Blob Analysis/IterativeSegmentation/Segmentation/LabSegmentation': '<S13>:1' */
  /*  This function generates the label matrix */
  /* '<S13>:1:10' */
  memset((void *)(&rty_LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S13>:1:12' */
  for (imgIdxLL = 0; imgIdxLL < 120; imgIdxLL++) {
    /* '<S13>:1:12' */
    /* '<S13>:1:13' */
    for (j = 0; j < 160; j++) {
      /* '<S13>:1:13' */
      /* '<S13>:1:14' */
      maxValue = 1000.0;

      /* '<S13>:1:15' */
      accumTwo = 1.0;

      /* '<S13>:1:16' */
      for (k = 1.0; k <= (*rty_num_colors); k++) {
        /* '<S13>:1:16' */
        /* '<S13>:1:17' */
        accumThree = sqrt((rt_pow_snf(rty_ref_colors[(int32_T)k - 1] -
          localB->ColorSpaceConversion1_o1[120 * j + imgIdxLL], 2.0) +
                           rt_pow_snf(rty_ref_colors[(int32_T)k + 49] -
          localB->ColorSpaceConversion1_o2[120 * j + imgIdxLL], 2.0)) +
                          rt_pow_snf(rty_ref_colors[(int32_T)k + 99] -
          localB->ColorSpaceConversion1_o3[120 * j + imgIdxLL], 2.0));
        if (accumThree < maxValue) {
          /* '<S13>:1:18' */
          /* '<S13>:1:19' */
          maxValue = accumThree;

          /* '<S13>:1:20' */
          accumTwo = k;
        }
      }

      /* '<S13>:1:23' */
      rty_LabelMatrix[imgIdxLL + 120 * j] = accumTwo;
    }
  }

  /* '<S13>:1:27' */

  /* Embedded MATLAB: '<S1>/Blob Extraction' incorporates:
   *  Constant: '<Root>/ColorFilter'
   *  Constant: '<S1>/ModeSelect3'
   *  Constant: '<S1>/ModeSelect4'
   *  Constant: '<S1>/ModeSelect5'
   *  Constant: '<S1>/ModeSelect6'
   */
  maxValue = (*rty_num_colors);

  /* Embedded MATLAB Function 'Blob Analysis/Blob Extraction': '<S4>:1' */
  /*  a_range, b_range) */
  /*  This function extracts  */
  /*  Input */
  /*     */
  /*  Initialize */
  /* '<S4>:1:8' */
  /* '<S4>:1:12' */
  for (m = 0; m < 19200; m++) {
    localB->LogicMatrix[m] = FALSE;
  }

  /* '<S4>:1:14' */
  accumFour = 0.0;

  /* '<S4>:1:15' */
  memset((void *)(&rty_BlobHues[0]), 0, 150U * sizeof(real_T));

  /* '<S4>:1:17' */
  for (m = 0; m < 50; m++) {
    rty_Area[m] = -1.0;
  }

  /* '<S4>:1:18' */
  memset((void *)(&rty_BBox[0]), 0, 200U * sizeof(real_T));

  /* '<S4>:1:19' */
  /* '<S4>:1:20' */
  for (m = 0; m < 50; m++) {
    rty_MajorAxis[m] = 0.0;
    rty_MinorAxis[m] = 0.0;
  }

  /* '<S4>:1:21' */
  memset((void *)(&rty_Centroid[0]), 0, 100U * sizeof(real_T));

  /* '<S4>:1:22' */
  /* '<S4>:1:23' */
  /* '<S4>:1:24' */
  for (m = 0; m < 50; m++) {
    rty_Eccentricity[m] = 0.0;
    rty_Extent[m] = 0.0;
    rty_Orientation[m] = 0.0;
  }

  /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
  /*  identified blob */
  /*  Calculate geometric information about the blobs */
  /*  */
  /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
  /*    locations for which color values are k, and zeros everywhere else */
  /* '<S4>:1:43' */
  for (k = 1.0; k <= maxValue; k++) {
    /* '<S4>:1:43' */
    /* '<S4>:1:45' */
    /* '<S4>:1:46' */
    /* '<S4>:1:48' */
    /* '<S4>:1:49' */
    /* '<S4>:1:59' */
    /* '<S4>:1:61' */
    for (imgIdxLL = 0; imgIdxLL < 120; imgIdxLL++) {
      /* '<S4>:1:61' */
      /* '<S4>:1:62' */
      for (j = 0; j < 160; j++) {
        /* '<S4>:1:62' */
        if (rty_LabelMatrix[120 * j + imgIdxLL] != k) {
          /* '<S4>:1:63' */
          /* '<S4>:1:64' */
          localB->LogicMatrix[imgIdxLL + 120 * j] = FALSE;
        } else {
          /* '<S4>:1:66' */
          localB->LogicMatrix[imgIdxLL + 120 * j] = TRUE;
        }
      }
    }

    path_detector_Outputs(&localB->LogicMatrix[0], TArea, TCentroid, TBBox,
                          ref_color_L_avg, ref_color_a_avg, ref_color_b_avg,
                          color_count, TExtent, &TNumBlobs, localDW);

    /* '<S4>:1:73' */
    for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
      /* '<S4>:1:73' */
      b_lower = floor((accumFour + (real_T)TNumBlobs) + 0.5);
      if (b_lower < 256.0) {
        tmp = (uint8_T)b_lower;
      } else {
        tmp = MAX_uint8_T;
      }

      if (tmp <= 50) {
        /* '<S4>:1:74' */
        /* '<S4>:1:76' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Centroid[((tmp - 1) << 1)] = TCentroid[(b_i - 1) << 1];

        /* '<S4>:1:77' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Centroid[1 + ((tmp - 1) << 1)] = TCentroid[((b_i - 1) << 1) + 1];

        /* '<S4>:1:79' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        accumTwo = rty_Centroid[((tmp - 1) << 1)];
        moppaaaadjecnopp_refp1_round(&accumTwo);

        /* '<S4>:1:80' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        accumThree = rty_Centroid[((tmp - 1) << 1) + 1];
        moppaaaadjecnopp_refp1_round(&accumThree);

        /* '<S4>:1:82' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_BlobHues[3 * (tmp - 1)] = rty_ref_colors[(int32_T)rty_LabelMatrix
          [((int32_T)accumThree - 1) * 120 + ((int32_T)accumTwo - 1)] - 1];

        /* '<S4>:1:83' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_BlobHues[1 + 3 * (tmp - 1)] = rty_ref_colors[(int32_T)
          rty_LabelMatrix[((int32_T)accumThree - 1) * 120 + ((int32_T)accumTwo -
          1)] + 49];

        /* '<S4>:1:84' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_BlobHues[2 + 3 * (tmp - 1)] = rty_ref_colors[(int32_T)
          rty_LabelMatrix[((int32_T)accumThree - 1) * 120 + ((int32_T)accumTwo -
          1)] + 99];

        /* '<S4>:1:86' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Area[tmp - 1] = (real_T)TArea[b_i - 1];

        /* '<S4>:1:87' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_BBox[tmp - 1] = (real_T)TBBox[b_i - 1];

        /* '<S4>:1:88' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_MajorAxis[tmp - 1] = ref_color_L_avg[b_i - 1];

        /* '<S4>:1:89' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_MinorAxis[tmp - 1] = ref_color_a_avg[b_i - 1];

        /* '<S4>:1:90' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Eccentricity[tmp - 1] = color_count[b_i - 1];

        /* '<S4>:1:91' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Extent[tmp - 1] = TExtent[b_i - 1];

        /* '<S4>:1:92' */
        b_lower = floor((accumFour + (real_T)b_i) + 0.5);
        if (b_lower < 256.0) {
          tmp = (uint8_T)b_lower;
        } else {
          tmp = MAX_uint8_T;
        }

        rty_Orientation[tmp - 1] = ref_color_b_avg[b_i - 1];
      }
    }

    /* '<S4>:1:97' */
    accumFour += (real_T)TNumBlobs;
  }

  (*rty_BlobCount) = accumFour;

  /* Embedded MATLAB: '<S1>/Filter Image' incorporates:
   *  Constant: '<Root>/ColorFilter'
   *  Constant: '<S1>/ModeSelect1'
   *  Constant: '<S1>/ModeSelect2'
   *  Constant: '<S1>/ModeSelect7'
   *  Constant: '<S1>/ModeSelect8'
   */
  /* Embedded MATLAB Function 'Blob Analysis/Filter Image': '<S5>:1' */
  /*  a_range, b_range) */
  /*  Initialize */
  /* '<S5>:1:6' */
  /*  Generate a bw image using color indices */
  /* '<S5>:1:29' */
  flag = 0;
  iy = 0;
  for (imgIdxLL = 0; imgIdxLL < 160; imgIdxLL++) {
    flag++;
    maxValue = rty_LabelMatrix[flag - 1];
    b_found = 1;
    j = flag;
    guard = FALSE;
    if (rtIsNaN(rty_LabelMatrix[flag - 1])) {
      searchingForNonNaN = TRUE;
      imgIdxUR = 2;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (imgIdxUR < 121)) {
        j++;
        if (!rtIsNaN(rty_LabelMatrix[j - 1])) {
          maxValue = rty_LabelMatrix[j - 1];
          b_found = imgIdxUR;
          searchingForNonNaN = FALSE;
          exitg_0 = TRUE;
        } else {
          imgIdxUR++;
        }
      }

      if (!searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (b_found++; b_found < 121; b_found++) {
        j++;
        if (rty_LabelMatrix[j - 1] > maxValue) {
          maxValue = rty_LabelMatrix[j - 1];
        }
      }
    }

    iy++;
    maxval[iy - 1] = maxValue;
    flag += 119;
  }

  maxValue = maxval[0];
  b_found = 1;
  j = 1;
  guard = FALSE;
  if (rtIsNaN(maxval[0])) {
    b_searchingForNonNaN = TRUE;
    flag = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (flag < 161)) {
      j++;
      if (!rtIsNaN(maxval[j - 1])) {
        maxValue = maxval[j - 1];
        b_found = flag;
        b_searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        flag++;
      }
    }

    if (!b_searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (flag = b_found + 1; flag < 161; flag++) {
      j++;
      if (maxval[j - 1] > maxValue) {
        maxValue = maxval[j - 1];
      }
    }
  }

  if (maxValue == 0.0) {
    /* '<S5>:1:30' */
    /* '<S5>:1:31' */
    maxValue = 1.0;
  }

  /* '<S5>:1:33' */
  for (flag = 0; flag < 120; flag++) {
    /* '<S5>:1:33' */
    /* '<S5>:1:34' */
    for (b_found = 0; b_found < 160; b_found++) {
      /* '<S5>:1:34' */
      /* '<S5>:1:35' */
      localB->bw_image[flag + 120 * b_found] = rty_LabelMatrix[120 * b_found +
        flag] / maxValue;
    }
  }

  /* Embedded MATLAB: '<S1>/Filter Image1' */
  /* Embedded MATLAB Function 'Blob Analysis/Filter Image1': '<S6>:1' */
  /*  Initialize */
  /* '<S6>:1:7' */
  /* '<S6>:1:8' */
  /* '<S6>:1:9' */
  /*  Allow only colors in specified range */
  /* '<S6>:1:13' */
  for (flag = 0; flag < 120; flag++) {
    /* '<S6>:1:13' */
    /* '<S6>:1:14' */
    for (b_found = 0; b_found < 160; b_found++) {
      /* '<S6>:1:14' */
      /* '<S6>:1:16' */
      localB->L[flag + 120 * b_found] = rty_ref_colors[(int32_T)rty_LabelMatrix
        [120 * b_found + flag] - 1];

      /* '<S6>:1:17' */
      localB->a[flag + 120 * b_found] = rty_ref_colors[(int32_T)rty_LabelMatrix
        [120 * b_found + flag] + 49];

      /* '<S6>:1:18' */
      localB->b[flag + 120 * b_found] = rty_ref_colors[(int32_T)rty_LabelMatrix
        [120 * b_found + flag] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion3' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (imgIdxLL = 0; imgIdxLL < 19200; imgIdxLL++) {
    accumFour = (localB->L[imgIdxLL] + 16.0) / 116.0;
    accumThree = localB->a[imgIdxLL] / 500.0 + accumFour;
    maxValue = localB->b[imgIdxLL] / -200.0 + accumFour;
    if (accumThree <= 0.20689655172413793) {
      accumThree -= 0.13793103448275862;
      accumThree /= 7.7870370370370372;
    } else {
      accumThree = rt_pow_snf(accumThree, 3.0);
    }

    if (accumFour <= 0.20689655172413793) {
      accumFour -= 0.13793103448275862;
      accumFour /= 7.7870370370370372;
    } else {
      accumFour = rt_pow_snf(accumFour, 3.0);
    }

    if (maxValue <= 0.20689655172413793) {
      maxValue -= 0.13793103448275862;
      maxValue /= 7.7870370370370372;
    } else {
      maxValue = rt_pow_snf(maxValue, 3.0);
    }

    accumThree *= 0.9641986557609;
    maxValue *= 0.82511648322104;

    /* assign the results */
    localB->ColorSpaceConversion3_o1[imgIdxLL] = accumThree;
    localB->ColorSpaceConversion3_o2[imgIdxLL] = accumFour;
    localB->ColorSpaceConversion3_o3[imgIdxLL] = maxValue;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (imgIdxLL = 0; imgIdxLL < 19200; imgIdxLL++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    accumThree = (3.24096994190451 * localB->ColorSpaceConversion3_o1[imgIdxLL]
                  + -1.53738317757009 * localB->
                  ColorSpaceConversion3_o2[imgIdxLL]) + -0.49861076029299 *
      localB->ColorSpaceConversion3_o3[imgIdxLL];
    accumFour = (-0.96924363628087 * localB->ColorSpaceConversion3_o1[imgIdxLL]
                 + 1.87596750150771 * localB->ColorSpaceConversion3_o2[imgIdxLL])
      + 0.04155505740718 * localB->ColorSpaceConversion3_o3[imgIdxLL];
    maxValue = (0.055630079697 * localB->ColorSpaceConversion3_o1[imgIdxLL] +
                -0.20397695888899 * localB->ColorSpaceConversion3_o2[imgIdxLL])
      + 1.05697151424288 * localB->ColorSpaceConversion3_o3[imgIdxLL];

    /* Apply gamma correction to get R'G'B' */
    if (accumThree <= 0.00304) {
      accumThree *= 12.923054468333255;
    } else {
      accumThree = 1.0550005198172263 * rt_pow_snf(accumThree,
        0.41666666666666669) - 0.055000519817226347;
    }

    if (accumFour <= 0.00304) {
      accumFour *= 12.923054468333255;
    } else {
      accumFour = 1.0550005198172263 * rt_pow_snf(accumFour, 0.41666666666666669)
        - 0.055000519817226347;
    }

    if (maxValue <= 0.00304) {
      maxValue *= 12.923054468333255;
    } else {
      maxValue = 1.0550005198172263 * rt_pow_snf(maxValue, 0.41666666666666669)
        - 0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (accumThree > 1.0) {
      accumThree = 1.0;
    } else {
      if (accumThree < 0.0) {
        accumThree = 0.0;
      }
    }

    if (accumFour > 1.0) {
      accumFour = 1.0;
    } else {
      if (accumFour < 0.0) {
        accumFour = 0.0;
      }
    }

    if (maxValue > 1.0) {
      maxValue = 1.0;
    } else {
      if (maxValue < 0.0) {
        maxValue = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion3_o1[imgIdxLL] = accumThree;
    localB->ColorSpaceConversion3_o2[imgIdxLL] = accumFour;
    localB->ColorSpaceConversion3_o3[imgIdxLL] = maxValue;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  memcpy((void *)(&rty_bw_image[0]), (void *)(&localB->bw_image[0]), 19200U *
         sizeof(real_T));

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (j = 1; j < 159; j++) {
    for (flag = 1; flag < 119; flag++) {
      maxValue = 0.0;
      accumTwo = 0.0;
      b_found = j * 120 + flag;
      for (m = 0; m < 6; m++) {
        maxValue += localB->bw_image[b_found + localDW->EdgeDetection_VO_DW[m]] *
          path_detector_ConstP.EdgeDetection_VC_RTP[m];
        accumTwo += localB->bw_image[b_found + localDW->EdgeDetection_HO_DW[m]] *
          path_detector_ConstP.EdgeDetection_HC_RTP[m];
      }

      localDW->EdgeDetection_GV_SQUARED_DW[b_found] = maxValue * maxValue;
      localDW->EdgeDetection_GH_SQUARED_DW[b_found] = accumTwo * accumTwo;
    }
  }

  for (j = 1; j < 159; j++) {
    maxValue = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    b_found = j * 120;
    flag = j * 120 + 119;
    for (m = 0; m < 6; m++) {
      maxValue += localB->bw_image[b_found + localDW->EdgeDetection_HOU_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumTwo += localB->bw_image[flag + localDW->EdgeDetection_HOD_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumThree += localB->bw_image[b_found + localDW->EdgeDetection_VOU_DW[m]]
        * path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumFour += localB->bw_image[flag + localDW->EdgeDetection_VOD_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[b_found] = accumThree * accumThree;
    localDW->EdgeDetection_GH_SQUARED_DW[b_found] = maxValue * maxValue;
    localDW->EdgeDetection_GV_SQUARED_DW[flag] = accumFour * accumFour;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumTwo * accumTwo;
  }

  for (flag = 1; flag < 119; flag++) {
    maxValue = 0.0;
    accumTwo = 0.0;
    accumThree = 0.0;
    accumFour = 0.0;
    b_found = 19080 + flag;
    for (m = 0; m < 6; m++) {
      maxValue += localB->bw_image[flag + localDW->EdgeDetection_VOL_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumTwo += localB->bw_image[b_found + localDW->EdgeDetection_VOR_DW[m]] *
        path_detector_ConstP.EdgeDetection_VC_RTP[m];
      accumThree += localB->bw_image[flag + localDW->EdgeDetection_HOL_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
      accumFour += localB->bw_image[b_found + localDW->EdgeDetection_HOR_DW[m]] *
        path_detector_ConstP.EdgeDetection_HC_RTP[m];
    }

    localDW->EdgeDetection_GV_SQUARED_DW[flag] = maxValue * maxValue;
    localDW->EdgeDetection_GH_SQUARED_DW[flag] = accumThree * accumThree;
    localDW->EdgeDetection_GV_SQUARED_DW[b_found] = accumTwo * accumTwo;
    localDW->EdgeDetection_GH_SQUARED_DW[b_found] = accumFour * accumFour;
  }

  maxValue = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    maxValue += localB->bw_image[localDW->EdgeDetection_VOUL_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->bw_image[localDW->EdgeDetection_HOUL_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->bw_image[119 + localDW->EdgeDetection_VOLL_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->bw_image[119 + localDW->EdgeDetection_HOLL_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = maxValue * maxValue;
  localDW->EdgeDetection_GH_SQUARED_DW[0] = accumTwo * accumTwo;
  localDW->EdgeDetection_GV_SQUARED_DW[119] = accumThree * accumThree;
  localDW->EdgeDetection_GH_SQUARED_DW[119] = accumFour * accumFour;
  maxValue = 0.0;
  accumTwo = 0.0;
  accumThree = 0.0;
  accumFour = 0.0;
  for (m = 0; m < 6; m++) {
    maxValue += localB->bw_image[19080 + localDW->EdgeDetection_VOUR_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumTwo += localB->bw_image[19080 + localDW->EdgeDetection_HOUR_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
    accumThree += localB->bw_image[19199 + localDW->EdgeDetection_VOLR_DW[m]] *
      path_detector_ConstP.EdgeDetection_VC_RTP[m];
    accumFour += localB->bw_image[19199 + localDW->EdgeDetection_HOLR_DW[m]] *
      path_detector_ConstP.EdgeDetection_HC_RTP[m];
  }

  localDW->EdgeDetection_GV_SQUARED_DW[19080] = maxValue * maxValue;
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

  maxValue = 3.0 * accumTwo;
  for (j = 0; j < 160; j++) {
    for (flag = 0; flag < 120; flag++) {
      m = j * 120 + flag;
      localB->EdgeDetection[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] >
        maxValue) && (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GH_SQUARED_DW[m]) && (j != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 120] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (j != 159 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 120] : TRUE)) ||
                      ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GV_SQUARED_DW[m]) && (flag != 0 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
        localDW->EdgeDetection_GRAD_SUM_DW[m] : TRUE) && (flag != 119 ?
        localDW->EdgeDetection_GRAD_SUM_DW[m] >
        localDW->EdgeDetection_GRAD_SUM_DW[m + 1] : TRUE))));
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  for (m = 0; m < 19200; m++) {
    rty_edge_image[m] = (real_T)localB->EdgeDetection[m];
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  for (m = 0; m < 100; m++) {
    if (rtIsNaN(rty_Centroid[m]) || rtIsInf(rty_Centroid[m])) {
      b_lower = 0.0;
    } else {
      b_lower = fmod(floor(rty_Centroid[m]), 4.294967296E+9);
    }

    rtb_DataTypeConversion5[m] = b_lower < 0.0 ? -((int32_T)(uint32_T)(-b_lower))
      : (int32_T)(uint32_T)b_lower;
  }

  /* S-Function (sviphough): '<Root>/Hough Transform1' */
  MWVIP_Hough_D(&localB->EdgeDetection[0], &rty_hough_table[0],
                &path_detector_ConstP.HoughTransform1_SINE[0],
                &path_detector_ConstP.HoughTransform1_FIRSTRHO_R, 120, 160, 399,
                91);

  /* Embedded MATLAB: '<Root>/Identify Path Elements' incorporates:
   *  Constant: '<Root>/Down_Camera_Dimensions'
   */
  memcpy((void *)(&localB->hough_table[0]), (void *)(&rty_hough_table[0]),
         71820U * sizeof(real_T));
  memcpy((void *)(&rty_debug_orientation[0]), (void *)(&rty_Orientation[0]), 50U
         * sizeof(real_T));

  /* Embedded MATLAB Function 'Identify Path Elements': '<S2>:1' */
  /*  This function attempts to identfiy path elements, and returns lines, */
  /*    information about the paths that are present, and a true/false */
  /*    path_found parameter. */
  /*  */
  /*  5-30-11 */
  /*  */
  /*  Input */
  /*  */
  /*  Output */
  /*   path_headings = vector of path orientations in terms of headings */
  /*     relative to the auv (degrees) */
  /*   rho, theta = vectors containing lines determined by Hough Transform, */
  /*     ordered by number of votes */
  /*  */
  /*  Notes: */
  /*    The hough_table is destroyed in this function (acceptable if */
  /*      hough_table is not an output) */
  /*    blob_orientation is destroyed */
  /*  Initialize */
  /*  Considers this many popular lines as candidates */
  /* '<S2>:1:29' */
  /* '<S2>:1:30' */
  /* '<S2>:1:31' */
  /*  Tolerance within which two lines are coincident */
  /* '<S2>:1:34' */
  /*  Tolerence within which two slopes are equal (radians) */
  /* '<S2>:1:35' */
  /*  Ratio of blob area to image area considered to imply the blob is actually background noise */
  /* '<S2>:1:37' */
  /* '<S2>:1:38' */
  /* '<S2>:1:39' */
  /*  theta_hold is a copy of theta which gets destroyed */
  /* '<S2>:1:41' */
  /* '<S2>:1:42' */
  for (m = 0; m < 200; m++) {
    rty_rho[m] = 0.0;
    theta[m] = 0.0;
    rty_theta[m] = 0.0;
    rtb_rho_out[m] = 0.0;
    rtb_theta_out[m] = 0.0;
  }

  /* '<S2>:1:44' */
  rty_path_headings[0] = 0.0;
  rty_path_headings[1] = 0.0;
  rty_path_headings[2] = 0.0;

  /* '<S2>:1:45' */
  for (m = 0; m < 6; m++) {
    path_locations[m] = 0.0;
  }

  /* '<S2>:1:46' */
  (*rty_TargetDetected) = 0.0;

  /* path_found_vector = zeros(1,max_num_paths); */
  /*  Identify the most likely max_num_lines lines */
  /* '<S2>:1:51' */
  m = 1;
  guard = FALSE;
  while (((uint32_T)guard == 0U) && (m <= 200)) {
    /* '<S2>:1:51' */
    /* '<S2>:1:53' */
    maxValue = 0.0;

    /* '<S2>:1:54' */
    b_found = 1;

    /* '<S2>:1:55' */
    flag = 1;

    /* '<S2>:1:56' */
    for (imgIdxLL = 0; imgIdxLL < 399; imgIdxLL++) {
      /* '<S2>:1:56' */
      /* '<S2>:1:57' */
      for (j = 0; j < 180; j++) {
        /* '<S2>:1:57' */
        if (localB->hough_table[399 * j + imgIdxLL] > maxValue) {
          /* '<S2>:1:58' */
          /* '<S2>:1:59' */
          b_found = imgIdxLL + 1;

          /* '<S2>:1:60' */
          flag = j + 1;

          /* '<S2>:1:61' */
          maxValue = localB->hough_table[399 * j + imgIdxLL];
        }
      }
    }

    if (maxValue == 0.0) {
      /* '<S2>:1:66' */
      guard = TRUE;
    } else {
      /* '<S2>:1:70' */
      rty_rho[m - 1] = localB->HoughTransform1_o3[b_found - 1];

      /* '<S2>:1:71' */
      theta[m - 1] = localB->HoughTransform1_o2[flag - 1];

      /* '<S2>:1:72' */
      rty_theta[m - 1] = localB->HoughTransform1_o2[flag - 1];

      /* '<S2>:1:73' */
      localB->hough_table[(b_found - 1) + 399 * (flag - 1)] = 0.0;
      m++;
    }
  }

  /*  Correct orientations to vehicle coordinates */
  /* '<S2>:1:79' */
  for (maxValue = 1.0; maxValue <= (*rty_BlobCount); maxValue++) {
    /* '<S2>:1:79' */
    /*  theta_hold: */
    /*    -is between [-pi/2, +pi/2] */
    /*  blob_orientation: */
    /*    -is potentially outside this range */
    /*    -needs to be corrected by pi/2 to get relative heading */
    /*     blob_orientation(j) = (pi/2) - blob_orientation(j); */
    /* '<S2>:1:87' */
    b_lower = (3.1415926535897931 - rty_debug_orientation[(int32_T)maxValue - 1])
      / 3.1415926535897931;
    if (b_lower < 0.0) {
      accumTwo = ceil(b_lower - 0.5);
    } else {
      accumTwo = floor(b_lower + 0.5);
    }

    if (fabs(b_lower - accumTwo) <= 2.2204460492503131E-16 * fabs(b_lower)) {
      b_lower = 0.0;
    } else {
      b_lower = (b_lower - floor(b_lower)) * 3.1415926535897931;
    }

    rty_debug_orientation[(int32_T)maxValue - 1] = b_lower - 1.5707963267948966;

    /*     if(blob_orientation(j) > pi/2) */
    /*         blob_orientation(j) = blob_orientation(j) - pi; */
    /*     elseif(blob_orientation(j) < -pi/2) */
    /*         blob_orientation(j) = blob_orientation(j) + pi; */
    /*     end */
  }

  /*  Compare most popular lines with blob orientations */
  /* '<S2>:1:97' */
  maxValue = 1.0;

  /* '<S2>:1:98' */
  /* '<S2>:1:100' */
  b_found = 0;

  /* '<S2>:1:101' */
  j = 1;
  exitg = FALSE;
  while (((uint32_T)exitg == 0U) && (j <= 200)) {
    /* '<S2>:1:101' */
    /* '<S2>:1:102' */
    accumTwo = 1.0;
    exitg_0 = FALSE;
    while (((uint32_T)exitg_0 == 0U) && (accumTwo <= (*rty_BlobCount))) {
      /* '<S2>:1:102' */
      /*  Search for a match between one blob and one line */
      if ((fabs(rty_theta[j - 1] - rty_debug_orientation[(int32_T)accumTwo - 1])
           <= 0.17453292519943295) && (rty_Area[(int32_T)accumTwo - 1] / 19200.0
           <= 0.8) && (rty_theta[j - 1] != 1000.0) && (rty_debug_orientation
           [(int32_T)accumTwo - 1] != 1000.0)) {
        /* '<S2>:1:105' */
        /* '<S2>:1:106' */
        rty_path_headings[0] = rty_theta[j - 1];

        /* '<S2>:1:107' */
        path_locations[0] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U)];

        /* '<S2>:1:108' */
        path_locations[1] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U) + 1];

        /*  */
        /* '<S2>:1:113' */
        rtb_rho_out[(int32_T)maxValue - 1] = rty_rho[j - 1];

        /* '<S2>:1:114' */
        rtb_theta_out[(int32_T)maxValue - 1] = theta[j - 1];

        /* '<S2>:1:115' */
        maxValue++;

        /* / */
        /* '<S2>:1:119' */
        rty_theta[j - 1] = 1000.0;

        /*  Invalid angle; do not want this line to be selected again */
        /* '<S2>:1:120' */
        rty_debug_orientation[(int32_T)accumTwo - 1] = 1000.0;

        /* '<S2>:1:121' */
        b_found = 1;
        exitg_0 = TRUE;
      } else {
        accumTwo++;
      }
    }

    if (b_found == 1) {
      /* '<S2>:1:127' */
      exitg = TRUE;
    } else {
      j++;
    }
  }

  /* '<S2>:1:98' */
  /* '<S2>:1:100' */
  b_found = 0;

  /* '<S2>:1:101' */
  j = 1;
  exitg = FALSE;
  while (((uint32_T)exitg == 0U) && (j <= 200)) {
    /* '<S2>:1:101' */
    /* '<S2>:1:102' */
    accumTwo = 1.0;
    exitg_0 = FALSE;
    while (((uint32_T)exitg_0 == 0U) && (accumTwo <= (*rty_BlobCount))) {
      /* '<S2>:1:102' */
      /*  Search for a match between one blob and one line */
      if ((fabs(rty_theta[j - 1] - rty_debug_orientation[(int32_T)accumTwo - 1])
           <= 0.17453292519943295) && (rty_Area[(int32_T)accumTwo - 1] / 19200.0
           <= 0.8) && (rty_theta[j - 1] != 1000.0) && (rty_debug_orientation
           [(int32_T)accumTwo - 1] != 1000.0)) {
        /* '<S2>:1:105' */
        /* '<S2>:1:106' */
        rty_path_headings[1] = rty_theta[j - 1];

        /* '<S2>:1:107' */
        path_locations[2] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U)];

        /* '<S2>:1:108' */
        path_locations[3] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U) + 1];

        /*  */
        /* '<S2>:1:113' */
        rtb_rho_out[(int32_T)maxValue - 1] = rty_rho[j - 1];

        /* '<S2>:1:114' */
        rtb_theta_out[(int32_T)maxValue - 1] = theta[j - 1];

        /* '<S2>:1:115' */
        maxValue++;

        /* / */
        /* '<S2>:1:119' */
        rty_theta[j - 1] = 1000.0;

        /*  Invalid angle; do not want this line to be selected again */
        /* '<S2>:1:120' */
        rty_debug_orientation[(int32_T)accumTwo - 1] = 1000.0;

        /* '<S2>:1:121' */
        b_found = 1;
        exitg_0 = TRUE;
      } else {
        accumTwo++;
      }
    }

    if (b_found == 1) {
      /* '<S2>:1:127' */
      exitg = TRUE;
    } else {
      j++;
    }
  }

  /* '<S2>:1:98' */
  /* '<S2>:1:100' */
  b_found = 0;

  /* '<S2>:1:101' */
  j = 1;
  exitg = FALSE;
  while (((uint32_T)exitg == 0U) && (j <= 200)) {
    /* '<S2>:1:101' */
    /* '<S2>:1:102' */
    accumTwo = 1.0;
    exitg_0 = FALSE;
    while (((uint32_T)exitg_0 == 0U) && (accumTwo <= (*rty_BlobCount))) {
      /* '<S2>:1:102' */
      /*  Search for a match between one blob and one line */
      if ((fabs(rty_theta[j - 1] - rty_debug_orientation[(int32_T)accumTwo - 1])
           <= 0.17453292519943295) && (rty_Area[(int32_T)accumTwo - 1] / 19200.0
           <= 0.8) && (rty_theta[j - 1] != 1000.0) && (rty_debug_orientation
           [(int32_T)accumTwo - 1] != 1000.0)) {
        /* '<S2>:1:105' */
        /* '<S2>:1:106' */
        rty_path_headings[2] = rty_theta[j - 1];

        /* '<S2>:1:107' */
        path_locations[4] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U)];

        /* '<S2>:1:108' */
        path_locations[5] = rty_Centroid[(((int32_T)accumTwo - 1) << 1U) + 1];

        /*  */
        /* '<S2>:1:113' */
        rtb_rho_out[(int32_T)maxValue - 1] = rty_rho[j - 1];

        /* '<S2>:1:114' */
        rtb_theta_out[(int32_T)maxValue - 1] = theta[j - 1];

        /* '<S2>:1:115' */
        maxValue++;

        /* / */
        /* '<S2>:1:119' */
        rty_theta[j - 1] = 1000.0;

        /*  Invalid angle; do not want this line to be selected again */
        /* '<S2>:1:120' */
        rty_debug_orientation[(int32_T)accumTwo - 1] = 1000.0;

        /* '<S2>:1:121' */
        b_found = 1;
        exitg_0 = TRUE;
      } else {
        accumTwo++;
      }
    }

    if (b_found == 1) {
      /* '<S2>:1:127' */
      exitg = TRUE;
    } else {
      j++;
    }
  }

  /*  Order path_headings to reflect actual path locations (left to right in */
  /*    image) */
  /* '<S2>:1:137' */
  /* '<S2>:1:138' */
  /* '<S2>:1:139' */
  value[0] = 160.0;
  b_j_index[0] = 1;
  found[0] = 0;
  value[1] = 160.0;
  b_j_index[1] = 1;
  found[1] = 0;
  value[2] = 160.0;
  b_j_index[2] = 1;
  found[2] = 0;

  /* '<S2>:1:141' */
  for (flag = 0; flag < 3; flag++) {
    b_j_index_0 = b_j_index[flag];

    /* '<S2>:1:141' */
    /* '<S2>:1:142' */
    accumFour = value[flag];

    /* '<S2>:1:142' */
    if ((path_locations[1] < value[flag]) && (found[0] == 0)) {
      /* '<S2>:1:143' */
      /* '<S2>:1:144' */
      accumFour = path_locations[1];

      /* '<S2>:1:145' */
      b_j_index_0 = 1;
    }

    /* '<S2>:1:142' */
    if ((path_locations[3] < accumFour) && (found[1] == 0)) {
      /* '<S2>:1:143' */
      /* '<S2>:1:144' */
      accumFour = path_locations[3];

      /* '<S2>:1:145' */
      b_j_index_0 = 2;
    }

    /* '<S2>:1:142' */
    if ((path_locations[5] < accumFour) && (found[2] == 0)) {
      /* '<S2>:1:143' */
      /* '<S2>:1:144' */
      /* '<S2>:1:145' */
      b_j_index_0 = 3;
    }

    /* '<S2>:1:148' */
    found[b_j_index_0 - 1] = 1;
    b_j_index[flag] = b_j_index_0;
  }

  /* '<S2>:1:151' */
  matr[0] = rty_path_headings[0];
  matr[3] = rty_path_headings[1];
  matr[6] = rty_path_headings[2];
  for (m = 0; m < 3; m++) {
    matr[1 + 3 * m] = path_locations[m << 1];
    matr[2 + 3 * m] = path_locations[(m << 1) + 1];
  }

  /* '<S2>:1:152' */
  /* '<S2>:1:153' */
  rty_path_headings[0] = matr[(b_j_index[0] - 1) * 3];

  /* '<S2>:1:152' */
  /* '<S2>:1:153' */
  rty_path_headings[1] = matr[(b_j_index[1] - 1) * 3];

  /* '<S2>:1:152' */
  /* '<S2>:1:153' */
  rty_path_headings[2] = matr[(b_j_index[2] - 1) * 3];

  /*  old code \/ \/ */
  /*  Determine which way the 'Y' shape is pointing */
  /* path_headings = sort(path_headings, 2, 'ascend'); */
  /* heading_diff = abs([ path_headings(2) - path_headings(1), path_headings(3) - path_headings(2), path_headings(1) - path_headings(3)]); */
  /* if(heading_diff(1) < heading_diff(2) && heading_diff(1) < heading_diff(3)) */
  /*     y_heading = path_headings(3); */
  /* elseif(heading_diff(2) < heading_diff(1) && heading_diff(2) < heading_diff(3)) */
  /*     y_heading = path_headings(1); */
  /* elseif(heading_diff(3) < heading_diff(1) && heading_diff(3) < heading_diff(2)) */
  /*     y_heading = path_headings(2); */
  /* else */
  /*     y_heading = 0; */
  /* end */
  /*  Determine a good approximation of the median lines (ignore effectively */
  /*    duplicate lines) */
  /* { */
  /* rho(1) = rho(1); */
  /* theta(1) = theta(1); */
  /*  */
  /* m = 2; */
  /* for i = 2:max_num_lines */
  /*      */
  /*     % If rho, theta do not match within tolerance, then store as the next */
  /*     %   line */
  /*     if( abs(rho(i) - rho(i-1)) >= 30 ) */
  /*         rho_out(m) = rho(i); */
  /*         theta_out(m) = theta(i); */
  /*         m = m + 1; */
  /*         if( m > 3 ) */
  /*             break; */
  /*         end */
  /*     end */
  /*      */
  /* end */
  /*  */
  /*  Select the most popular lines assuming that they correspond to the path */
  /*    edges */
  /* } */
  /* '<S2>:1:225' */
  /* '<S2>:1:226' */

  /* S-Function (sviphoughlines): '<Root>/Hough Lines2' */
  for (imgIdxLL = 0; imgIdxLL < 200; imgIdxLL++) {
    j = 0;
    iy = imgIdxLL << 2;
    maxValue = (rtb_rho_out[imgIdxLL] + 2.2204460492503131E-16) / (cos
      (rtb_theta_out[imgIdxLL]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    accumTwo = floor(maxValue + 0.5);
    if ((accumTwo >= 0.0) && (accumTwo <= 159.0)) {
      localB->HoughLines2[iy] = 0;
      localB->HoughLines2[iy + 1] = (int32_T)floor((real_T)(int32_T)accumTwo +
        0.5);
      j = 1;
    }

    accumThree = (rtb_rho_out[imgIdxLL] + 2.2204460492503131E-16) / (sin
      (rtb_theta_out[imgIdxLL]) + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    accumTwo = floor(accumThree + 0.5);
    if ((accumTwo >= 0.0) && (accumTwo <= 119.0)) {
      localB->HoughLines2[iy + (j << 1)] = (int32_T)floor((real_T)(int32_T)
        accumTwo + 0.5);
      localB->HoughLines2[(iy + 1) + (j << 1)] = 0;
      j++;
    }

    /* part-3: Right vertical axis */
    if (j < 2) {
      accumTwo = floor((maxValue - 159.0) * (accumThree / maxValue) + 0.5);
      if ((accumTwo >= 0.0) && (accumTwo <= 119.0)) {
        localB->HoughLines2[iy + (j << 1)] = (int32_T)floor((real_T)(int32_T)
          accumTwo + 0.5);
        localB->HoughLines2[(iy + 1) + (j << 1)] = 159;
        j++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (j < 2) {
      accumTwo = floor((maxValue - maxValue / accumThree * 119.0) + 0.5);
      if ((accumTwo >= 0.0) && (accumTwo <= 159.0)) {
        localB->HoughLines2[iy + (j << 1)] = 119;
        localB->HoughLines2[(iy + 1) + (j << 1)] = (int32_T)floor((real_T)
          (int32_T)accumTwo + 0.5);
        j++;
      }
    }

    if (j < 2) {
      localB->HoughLines2[iy] = -1;
      localB->HoughLines2[iy + 1] = -1;
      localB->HoughLines2[iy + 2] = -1;
      localB->HoughLines2[iy + 3] = -1;
    }
  }

  /* S-Function (svipdrawshapes): '<Root>/Draw Shapes1' */
  /* Copy the image from input to output. */
  memcpy((void *)(&rty_line_image[0]), (void *)(&localB->bw_image[0]), 19200U *
         sizeof(real_T));
  idxStart = 0;
  for (idxROI = 0; idxROI < 200; idxROI++) {
    for (m = 0; m < 1; m = 1) {
      line_idx = localB->HoughLines2[idxStart];
      line_idx_0 = localB->HoughLines2[idxStart + 1];
      line_idx_1 = localB->HoughLines2[idxStart + 2];
      line_idx_2 = localB->HoughLines2[idxStart + 3];
      if ((localB->HoughLines2[idxStart + 2] != localB->HoughLines2[idxStart]) ||
          (localB->HoughLines2[idxStart + 1] != localB->HoughLines2[idxStart + 3]))
      {
        guard = FALSE;

        /* Find the visible portion of a line. */
        b_searchingForNonNaN = FALSE;
        exitg = FALSE;
        searchingForNonNaN = FALSE;
        imgIdxLL = localB->HoughLines2[idxStart];
        line_idx_3 = localB->HoughLines2[idxStart + 1];
        line_idx_4 = localB->HoughLines2[idxStart + 2];
        line_idx_5 = localB->HoughLines2[idxStart + 3];
        while (!searchingForNonNaN) {
          m = 0;
          iy = 0;

          /* Determine viewport violations. */
          if (imgIdxLL < 0) {
            m = 4;
          } else {
            if (imgIdxLL > 119) {
              m = 8;
            }
          }

          if (line_idx_4 < 0) {
            iy = 4;
          } else {
            if (line_idx_4 > 119) {
              iy = 8;
            }
          }

          if (line_idx_3 < 0) {
            m = (int32_T)((uint32_T)m | 1U);
          } else {
            if (line_idx_3 > 159) {
              m = (int32_T)((uint32_T)m | 2U);
            }
          }

          if (line_idx_5 < 0) {
            iy = (int32_T)((uint32_T)iy | 1U);
          } else {
            if (line_idx_5 > 159) {
              iy = (int32_T)((uint32_T)iy | 2U);
            }
          }

          if (!((uint32_T)m | (uint32_T)iy)) {
            /* Line falls completely within bounds. */
            searchingForNonNaN = TRUE;
            guard = TRUE;
          } else if ((uint32_T)m & (uint32_T)iy) {
            /* Line falls completely out of bounds. */
            searchingForNonNaN = TRUE;
            guard = FALSE;
          } else if ((uint32_T)m != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (b_searchingForNonNaN) {
              imgIdxLL = line_idx;
              line_idx_3 = line_idx_0;
            }

            b_found = line_idx_4 - imgIdxLL;
            flag = line_idx_5 - line_idx_3;
            if ((uint32_T)m & 4U) {
              /* Violated RMin. */
              j = (0 - imgIdxLL) * flag;
              if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
                line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
              } else {
                line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
              }

              imgIdxLL = 0;
              b_searchingForNonNaN = TRUE;
            } else if ((uint32_T)m & 8U) {
              /* Violated RMax. */
              j = (119 - imgIdxLL) * flag;
              if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
                line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
              } else {
                line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
              }

              imgIdxLL = 119;
              b_searchingForNonNaN = TRUE;
            } else if ((uint32_T)m & 1U) {
              /* Violated CMin. */
              j = (0 - line_idx_3) * b_found;
              if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
                imgIdxLL += (div_s32_floor(j << 1U, flag) + 1) >> 1;
              } else {
                imgIdxLL += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
              }

              line_idx_3 = 0;
              b_searchingForNonNaN = TRUE;
            } else {
              /* Violated CMax. */
              j = (159 - line_idx_3) * b_found;
              if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
                imgIdxLL += (div_s32_floor(j << 1U, flag) + 1) >> 1;
              } else {
                imgIdxLL += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
              }

              line_idx_3 = 159;
              b_searchingForNonNaN = TRUE;
            }
          } else {
            /* Clip the 2nd point. */
            if (exitg) {
              line_idx_4 = line_idx_1;
              line_idx_5 = line_idx_2;
            }

            b_found = line_idx_4 - imgIdxLL;
            flag = line_idx_5 - line_idx_3;
            if ((uint32_T)iy & 4U) {
              /* Violated RMin. */
              j = (0 - line_idx_4) * flag;
              if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
                line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
              } else {
                line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
              }

              line_idx_4 = 0;
              exitg = TRUE;
            } else if ((uint32_T)iy & 8U) {
              /* Violated RMax. */
              j = (119 - line_idx_4) * flag;
              if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
                line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
              } else {
                line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
              }

              line_idx_4 = 119;
              exitg = TRUE;
            } else if ((uint32_T)iy & 1U) {
              /* Violated CMin. */
              j = (0 - line_idx_5) * b_found;
              if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
                line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
              }

              line_idx_5 = 0;
              exitg = TRUE;
            } else {
              /* Violated CMax. */
              j = (159 - line_idx_5) * b_found;
              if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
                line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
              }

              line_idx_5 = 159;
              exitg = TRUE;
            }
          }
        }

        if (guard) {
          /* Draw a line using Bresenham algorithm. */
          /* Initialize the Bresenham algorithm. */
          if (line_idx_4 >= imgIdxLL) {
            b_found = line_idx_4 - imgIdxLL;
          } else {
            b_found = imgIdxLL - line_idx_4;
          }

          if (line_idx_5 >= line_idx_3) {
            flag = line_idx_5 - line_idx_3;
          } else {
            flag = line_idx_3 - line_idx_5;
          }

          if (b_found > flag) {
            line_idx = 1;
            flag = 120;
          } else {
            line_idx = 120;
            flag = 1;
            b_found = imgIdxLL;
            imgIdxLL = line_idx_3;
            line_idx_3 = b_found;
            b_found = line_idx_4;
            line_idx_4 = line_idx_5;
            line_idx_5 = b_found;
          }

          if (imgIdxLL > line_idx_4) {
            b_found = imgIdxLL;
            imgIdxLL = line_idx_4;
            line_idx_4 = b_found;
            b_found = line_idx_3;
            line_idx_3 = line_idx_5;
            line_idx_5 = b_found;
          }

          j = line_idx_4 - imgIdxLL;
          if (line_idx_3 <= line_idx_5) {
            b_found = 1;
            iy = line_idx_5 - line_idx_3;
          } else {
            b_found = -1;
            iy = line_idx_3 - line_idx_5;
          }

          imgIdxUR = -((j + 1) >> 1);
          m = imgIdxLL * line_idx + line_idx_3 * flag;
          b_found = b_found * flag + line_idx;
          for (guard = (imgIdxLL <= line_idx_4); guard; guard = (imgIdxLL <=
                line_idx_4)) {
            rty_line_image[m] = 0.2;

            /* Compute the next location using Bresenham algorithm. */
            /* Move to the next pixel location. */
            imgIdxUR += iy;
            if (imgIdxUR >= 0) {
              imgIdxUR -= j;
              m += b_found;
            } else {
              m += line_idx;
            }

            imgIdxLL++;
          }
        }
      }

      idxStart += 2;
    }

    idxStart += 2;
  }

  /* S-Function (svipdrawmarkers): '<Root>/Draw Target1' */
  /* Copy the image from input to output. */
  for (m = 0; m < 19200; m++) {
    rty_R[m] = localB->ColorSpaceConversion3_o1[m];
    rty_G[m] = localB->ColorSpaceConversion3_o2[m];
    rty_B[m] = localB->ColorSpaceConversion3_o3[m];
  }

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 100; idxROI += 2) {
    line_idx = rtb_DataTypeConversion5[idxROI] - 7;
    line_idx_0 = rtb_DataTypeConversion5[idxROI + 1] - 7;
    line_idx_1 = rtb_DataTypeConversion5[idxROI] + 7;
    line_idx_2 = rtb_DataTypeConversion5[idxROI + 1] + 7;
    guard = FALSE;

    /* Find the visible portion of a line. */
    b_searchingForNonNaN = FALSE;
    exitg = FALSE;
    searchingForNonNaN = FALSE;
    imgIdxUR = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_4 = line_idx_1;
    line_idx_5 = line_idx_2;
    while (!searchingForNonNaN) {
      m = 0;
      iy = 0;

      /* Determine viewport violations. */
      if (imgIdxUR < 0) {
        m = 4;
      } else {
        if (imgIdxUR > 119) {
          m = 8;
        }
      }

      if (line_idx_4 < 0) {
        iy = 4;
      } else {
        if (line_idx_4 > 119) {
          iy = 8;
        }
      }

      if (line_idx_3 < 0) {
        m = (int32_T)((uint32_T)m | 1U);
      } else {
        if (line_idx_3 > 159) {
          m = (int32_T)((uint32_T)m | 2U);
        }
      }

      if (line_idx_5 < 0) {
        iy = (int32_T)((uint32_T)iy | 1U);
      } else {
        if (line_idx_5 > 159) {
          iy = (int32_T)((uint32_T)iy | 2U);
        }
      }

      if (!((uint32_T)m | (uint32_T)iy)) {
        /* Line falls completely within bounds. */
        searchingForNonNaN = TRUE;
        guard = TRUE;
      } else if ((uint32_T)m & (uint32_T)iy) {
        /* Line falls completely out of bounds. */
        searchingForNonNaN = TRUE;
        guard = FALSE;
      } else if ((uint32_T)m != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (b_searchingForNonNaN) {
          imgIdxUR = line_idx;
          line_idx_3 = line_idx_0;
        }

        b_found = line_idx_4 - imgIdxUR;
        flag = line_idx_5 - line_idx_3;
        if ((uint32_T)m & 4U) {
          /* Violated RMin. */
          j = (0 - imgIdxUR) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          imgIdxUR = 0;
          b_searchingForNonNaN = TRUE;
        } else if ((uint32_T)m & 8U) {
          /* Violated RMax. */
          j = (119 - imgIdxUR) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          imgIdxUR = 119;
          b_searchingForNonNaN = TRUE;
        } else if ((uint32_T)m & 1U) {
          /* Violated CMin. */
          j = (0 - line_idx_3) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            imgIdxUR += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            imgIdxUR += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_3 = 0;
          b_searchingForNonNaN = TRUE;
        } else {
          /* Violated CMax. */
          j = (159 - line_idx_3) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            imgIdxUR += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            imgIdxUR += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_3 = 159;
          b_searchingForNonNaN = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (exitg) {
          line_idx_4 = line_idx_1;
          line_idx_5 = line_idx_2;
        }

        b_found = line_idx_4 - imgIdxUR;
        flag = line_idx_5 - line_idx_3;
        if ((uint32_T)iy & 4U) {
          /* Violated RMin. */
          j = (0 - line_idx_4) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          line_idx_4 = 0;
          exitg = TRUE;
        } else if ((uint32_T)iy & 8U) {
          /* Violated RMax. */
          j = (119 - line_idx_4) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          line_idx_4 = 119;
          exitg = TRUE;
        } else if ((uint32_T)iy & 1U) {
          /* Violated CMin. */
          j = (0 - line_idx_5) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_5 = 0;
          exitg = TRUE;
        } else {
          /* Violated CMax. */
          j = (159 - line_idx_5) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_5 = 159;
          exitg = TRUE;
        }
      }
    }

    if (guard) {
      m = line_idx_3 * 120 + imgIdxUR;
      for (flag = imgIdxUR; flag <= line_idx_4; flag++) {
        rty_R[m] = 0.0;
        rty_G[m] = 0.0;
        rty_B[m] = 0.0;
        m += 121;
      }
    }

    line_idx = rtb_DataTypeConversion5[idxROI] - 7;
    line_idx_0 = rtb_DataTypeConversion5[idxROI + 1] + 7;
    line_idx_1 = rtb_DataTypeConversion5[idxROI] + 7;
    line_idx_2 = rtb_DataTypeConversion5[idxROI + 1] - 7;
    guard = FALSE;

    /* Find the visible portion of a line. */
    b_searchingForNonNaN = FALSE;
    exitg = FALSE;
    searchingForNonNaN = FALSE;
    imgIdxUR = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_4 = line_idx_1;
    line_idx_5 = line_idx_2;
    while (!searchingForNonNaN) {
      m = 0;
      iy = 0;

      /* Determine viewport violations. */
      if (imgIdxUR < 0) {
        m = 4;
      } else {
        if (imgIdxUR > 119) {
          m = 8;
        }
      }

      if (line_idx_4 < 0) {
        iy = 4;
      } else {
        if (line_idx_4 > 119) {
          iy = 8;
        }
      }

      if (line_idx_3 < 0) {
        m = (int32_T)((uint32_T)m | 1U);
      } else {
        if (line_idx_3 > 159) {
          m = (int32_T)((uint32_T)m | 2U);
        }
      }

      if (line_idx_5 < 0) {
        iy = (int32_T)((uint32_T)iy | 1U);
      } else {
        if (line_idx_5 > 159) {
          iy = (int32_T)((uint32_T)iy | 2U);
        }
      }

      if (!((uint32_T)m | (uint32_T)iy)) {
        /* Line falls completely within bounds. */
        searchingForNonNaN = TRUE;
        guard = TRUE;
      } else if ((uint32_T)m & (uint32_T)iy) {
        /* Line falls completely out of bounds. */
        searchingForNonNaN = TRUE;
        guard = FALSE;
      } else if ((uint32_T)m != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (b_searchingForNonNaN) {
          imgIdxUR = line_idx;
          line_idx_3 = line_idx_0;
        }

        b_found = line_idx_4 - imgIdxUR;
        flag = line_idx_5 - line_idx_3;
        if ((uint32_T)m & 4U) {
          /* Violated RMin. */
          j = (0 - imgIdxUR) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          imgIdxUR = 0;
          b_searchingForNonNaN = TRUE;
        } else if ((uint32_T)m & 8U) {
          /* Violated RMax. */
          j = (119 - imgIdxUR) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_3 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          imgIdxUR = 119;
          b_searchingForNonNaN = TRUE;
        } else if ((uint32_T)m & 1U) {
          /* Violated CMin. */
          j = (0 - line_idx_3) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            imgIdxUR += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            imgIdxUR += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_3 = 0;
          b_searchingForNonNaN = TRUE;
        } else {
          /* Violated CMax. */
          j = (159 - line_idx_3) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            imgIdxUR += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            imgIdxUR += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_3 = 159;
          b_searchingForNonNaN = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (exitg) {
          line_idx_4 = line_idx_1;
          line_idx_5 = line_idx_2;
        }

        b_found = line_idx_4 - imgIdxUR;
        flag = line_idx_5 - line_idx_3;
        if ((uint32_T)iy & 4U) {
          /* Violated RMin. */
          j = (0 - line_idx_4) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          line_idx_4 = 0;
          exitg = TRUE;
        } else if ((uint32_T)iy & 8U) {
          /* Violated RMax. */
          j = (119 - line_idx_4) * flag;
          if (((j >= 0) && (b_found >= 0)) || ((j < 0) && (b_found < 0))) {
            line_idx_5 += (div_s32_floor(j << 1U, b_found) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-j) << 1U, b_found) + 1) >> 1);
          }

          line_idx_4 = 119;
          exitg = TRUE;
        } else if ((uint32_T)iy & 1U) {
          /* Violated CMin. */
          j = (0 - line_idx_5) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_5 = 0;
          exitg = TRUE;
        } else {
          /* Violated CMax. */
          j = (159 - line_idx_5) * b_found;
          if (((j >= 0) && (flag >= 0)) || ((j < 0) && (flag < 0))) {
            line_idx_4 += (div_s32_floor(j << 1U, flag) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-j) << 1U, flag) + 1) >> 1);
          }

          line_idx_5 = 159;
          exitg = TRUE;
        }
      }
    }

    if (guard) {
      m = line_idx_3 * 120 + imgIdxUR;
      for (flag = imgIdxUR; flag <= line_idx_4; flag++) {
        rty_R[m] = 0.0;
        rty_G[m] = 0.0;
        rty_B[m] = 0.0;
        m += -119;
      }
    }
  }

  /* Embedded MATLAB: '<Root>/Identify Path Elements1' */
  /* Embedded MATLAB Function 'Identify Path Elements1': '<S3>:1' */
  /*  Input */
  /*    which_path = indicates which direction to take; left (1) right (2) or */
  /*      straight (0) */
  /*  Return the relative heading of the path element pointing "left" or */
  /*    "right" */
  if ((*rtu_WhichPath) == 1.0) {
    /* '<S3>:1:10' */
    /*  Take left path */
    /* '<S3>:1:12' */
    maxValue = rty_path_headings[0];
    b_found = 1;
    j = 1;
    guard = FALSE;
    if (rtIsNaN(rty_path_headings[0])) {
      b_searchingForNonNaN = TRUE;
      flag = 2;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (flag < 4)) {
        j++;
        if (!rtIsNaN(rty_path_headings[j - 1])) {
          maxValue = rty_path_headings[j - 1];
          b_found = flag;
          b_searchingForNonNaN = FALSE;
          exitg_0 = TRUE;
        } else {
          flag++;
        }
      }

      if (!b_searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (flag = b_found + 1; flag < 4; flag++) {
        j++;
        if (rty_path_headings[j - 1] < maxValue) {
          maxValue = rty_path_headings[j - 1];
        }
      }
    }

    (*rty_TargetYaw) = maxValue * 180.0 / 3.1415926535897931;
  } else if ((*rtu_WhichPath) == 2.0) {
    /* '<S3>:1:13' */
    /*  Take right path */
    /* '<S3>:1:15' */
    maxValue = rty_path_headings[0];
    b_found = 1;
    flag = 1;
    guard = FALSE;
    if (rtIsNaN(rty_path_headings[0])) {
      searchingForNonNaN = TRUE;
      imgIdxUR = 2;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (imgIdxUR < 4)) {
        flag++;
        if (!rtIsNaN(rty_path_headings[flag - 1])) {
          maxValue = rty_path_headings[flag - 1];
          b_found = imgIdxUR;
          searchingForNonNaN = FALSE;
          exitg = TRUE;
        } else {
          imgIdxUR++;
        }
      }

      if (!searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (b_found++; b_found < 4; b_found++) {
        flag++;
        if (rty_path_headings[flag - 1] > maxValue) {
          maxValue = rty_path_headings[flag - 1];
        }
      }
    }

    (*rty_TargetYaw) = maxValue * 180.0 / 3.1415926535897931;
  } else {
    /*  Continue straight */
    /* '<S3>:1:18' */
    (*rty_TargetYaw) = 0.0;
  }

  /* '<S3>:1:21' */
  (*rty_TargetX) = 0.0;

  /* '<S3>:1:22' */
  (*rty_TargetY) = 0.0;

  /* '<S3>:1:23' */
  (*rty_PathState) = 0.0;
}

/* Model initialize function */
void mr_path_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_path_detector *const path_detector_M, rtB_mr_path_detector *localB,
  rtDW_mr_path_detector *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(path_detector_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(rtB_mr_path_detector));

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
                sizeof(rtDW_mr_path_detector));
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
