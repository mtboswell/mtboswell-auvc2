/*
 * File: VisionModel.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.163
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sun Jul 17 03:26:09 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sun Jul 17 03:26:09 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VisionModel.h"
#include "VisionModel_private.h"

/* Block signals (auto storage) */
BlockIO_VisionModel VisionModel_B;

/* Block states (auto storage) */
D_Work_VisionModel VisionModel_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_VisionModel VisionModel_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_VisionModel VisionModel_Y;

/* Real-time model */
RT_MODEL_VisionModel VisionModel_M_;
RT_MODEL_VisionModel *VisionModel_M = &VisionModel_M_;

/* Forward declaration for local functions */
static void VisionModel_conv2(const real_T arg1[19200], const real_T arg2[9],
  real_T c[18644]);

/* Function for Embedded MATLAB: '<S2>/Low Pass Filter' */
static void VisionModel_conv2(const real_T arg1[19200], const real_T arg2[9],
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
 *    '<S2>/Low Pass Filter'
 *    '<S2>/Low Pass Filter1'
 *    '<S2>/Low Pass Filter2'
 */
void VisionModel_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_VisionModel *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S2>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Low Pass Filter/Low Pass Filter': '<S5>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S5>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S5>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S5>:1:19' */
  /* '<S5>:1:21' */
  /* '<S5>:1:23' */
  Gsum = 0.0;

  /* '<S5>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S5>:1:24' */
    /* '<S5>:1:25' */
    /* '<S5>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S5>:1:27' */
    Gsum += G[i + 1];

    /* '<S5>:1:25' */
    /* '<S5>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S5>:1:27' */
    Gsum += G[i + 4];

    /* '<S5>:1:25' */
    /* '<S5>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S5>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S5>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S5>:1:33' */
  VisionModel_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S5>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S5>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S5>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S5>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S5>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S5>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S5>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S5>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S5>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/* Model step function */
void VisionModel_step(void)
{
  int32_T i;
  int32_T ictr;
  real_T cc;
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
  real_T Resize2_LineBuffer[160];
  real_T rtb_num_colors;
  real_T rtb_ref_colors[150];

  /* Embedded MATLAB: '<S2>/Low Pass Filter' */
  VisionModel_LowPassFilter(&VisionModel_U.R_forward_in[0],
    &VisionModel_B.sf_LowPassFilter);

  /* Embedded MATLAB: '<S2>/Low Pass Filter1' */
  VisionModel_LowPassFilter(&VisionModel_U.G_forward_in[0],
    &VisionModel_B.sf_LowPassFilter1);

  /* Embedded MATLAB: '<S2>/Low Pass Filter2' */
  VisionModel_LowPassFilter(&VisionModel_U.B_forward_in[0],
    &VisionModel_B.sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (VisionModel_B.sf_LowPassFilter.Iout[i] <= 0.039286085583733095) {
      rtb_num_colors = VisionModel_B.sf_LowPassFilter.Iout[i] /
        12.923054468333255;
    } else {
      rtb_num_colors = rt_pow_snf((VisionModel_B.sf_LowPassFilter.Iout[i] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (VisionModel_B.sf_LowPassFilter1.Iout[i] <= 0.039286085583733095) {
      min_dist = VisionModel_B.sf_LowPassFilter1.Iout[i] / 12.923054468333255;
    } else {
      min_dist = rt_pow_snf((VisionModel_B.sf_LowPassFilter1.Iout[i] +
        0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    if (VisionModel_B.sf_LowPassFilter2.Iout[i] <= 0.039286085583733095) {
      index = VisionModel_B.sf_LowPassFilter2.Iout[i] / 12.923054468333255;
    } else {
      index = rt_pow_snf((VisionModel_B.sf_LowPassFilter2.Iout[i] +
                          0.055000519817226347) / 1.0550005198172263, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    cc = (0.41239079926596 * rtb_num_colors + 0.35758433938388 * min_dist) +
      0.18048078840183 * index;
    dist = (0.21263900587151 * rtb_num_colors + 0.71516867876776 * min_dist) +
      0.07219231536073 * index;
    rtb_num_colors = (0.01933081871559 * rtb_num_colors + 0.11919477979463 *
                      min_dist) + 0.95053215224966 * index;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (dist > 1.0) {
      dist = 1.0;
    } else {
      if (dist < 0.0) {
        dist = 0.0;
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
    VisionModel_B.ColorSpaceConversion1_o1[i] = cc;
    VisionModel_B.ColorSpaceConversion1_o2[i] = dist;
    VisionModel_B.ColorSpaceConversion1_o3[i] = rtb_num_colors;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    rtb_num_colors = VisionModel_B.ColorSpaceConversion1_o1[i] / 0.9641986557609;
    index = VisionModel_B.ColorSpaceConversion1_o3[i] / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (rtb_num_colors > 0.0088564516790356311) {
      cc = rt_pow_snf(rtb_num_colors, 0.33333333333333331);
    } else {
      cc = 7.7870370370370372 * rtb_num_colors + 0.13793103448275862;
    }

    if (VisionModel_B.ColorSpaceConversion1_o2[i] > 0.0088564516790356311) {
      min_dist = rt_pow_snf(VisionModel_B.ColorSpaceConversion1_o2[i],
                            0.33333333333333331);
    } else {
      min_dist = 7.7870370370370372 * VisionModel_B.ColorSpaceConversion1_o2[i]
        + 0.13793103448275862;
    }

    if (index > 0.0088564516790356311) {
      rtb_num_colors = rt_pow_snf(index, 0.33333333333333331);
    } else {
      rtb_num_colors = 7.7870370370370372 * index + 0.13793103448275862;
    }

    /* assign the results */
    VisionModel_B.ColorSpaceConversion1_o1[i] = 116.0 * min_dist - 16.0;
    VisionModel_B.ColorSpaceConversion1_o2[i] = (cc - min_dist) * 500.0;
    VisionModel_B.ColorSpaceConversion1_o3[i] = (min_dist - rtb_num_colors) *
      200.0;
  }

  /* S-Function (svipresize): '<S10>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      rtb_num_colors =
        VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled5[num_colors]
        * 160 + j] * VisionModel_ConstP.pooled2[num_colors] +
        VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      ictr += 80;
      rtb_num_colors +=
        VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      VisionModel_DWork.Resize_IntBuffer[i] = rtb_num_colors;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&VisionModel_DWork.Resize_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      rtb_num_colors = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_num_colors += Resize2_LineBuffer[VisionModel_ConstP.pooled4[ictr]] *
          VisionModel_ConstP.pooled1[ictr];
        ictr += 60;
      }

      VisionModel_B.Resize[flag] = rtb_num_colors;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S10>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      rtb_num_colors =
        VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled5[num_colors]
        * 160 + j] * VisionModel_ConstP.pooled2[num_colors] +
        VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      ictr += 80;
      rtb_num_colors +=
        VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      VisionModel_DWork.Resize1_IntBuffer[i] = rtb_num_colors;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&VisionModel_DWork.Resize1_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      rtb_num_colors = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_num_colors += Resize2_LineBuffer[VisionModel_ConstP.pooled4[ictr]] *
          VisionModel_ConstP.pooled1[ictr];
        ictr += 60;
      }

      VisionModel_B.Resize1[flag] = rtb_num_colors;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S10>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 160; j++) {
    i = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      ictr = num_colors + 80;
      rtb_num_colors =
        VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled5[num_colors]
        * 160 + j] * VisionModel_ConstP.pooled2[num_colors] +
        VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      ictr += 80;
      rtb_num_colors +=
        VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled5[ictr] *
        160 + j] * VisionModel_ConstP.pooled2[ictr];
      VisionModel_DWork.Resize2_IntBuffer[i] = rtb_num_colors;
      i += 160;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&VisionModel_DWork.Resize2_IntBuffer[num_colors * 160]), 160U *
           sizeof(real_T));
    for (j = 0; j < 60; j++) {
      ictr = j;
      rtb_num_colors = 0.0;
      for (i = 0; i < 6; i++) {
        rtb_num_colors += Resize2_LineBuffer[VisionModel_ConstP.pooled4[ictr]] *
          VisionModel_ConstP.pooled1[ictr];
        ictr += 60;
      }

      VisionModel_B.Resize2[flag] = rtb_num_colors;
      flag++;
    }
  }

  /* Embedded MATLAB: '<S3>/Reference Color Selection' incorporates:
   *  Constant: '<S3>/iterSegmentThresh'
   */
  /* Embedded MATLAB Function 'Segmentation/Reference Color Selection': '<S9>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S9>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S9>:1:14' */
  /* '<S9>:1:15' */
  memset((void *)&rtb_ref_colors[0], 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S9>:1:16' */
  memset((void *)(&VisionModel_B.LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S9>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S9>:1:23' */
  rtb_ref_colors[0] = VisionModel_B.Resize[2369];
  rtb_ref_colors[50] = VisionModel_B.Resize1[2369];
  rtb_ref_colors[100] = VisionModel_B.Resize2[2369];

  /* '<S9>:1:25' */
  flag = 0;

  /* '<S9>:1:26' */
  i = 1;

  /* '<S9>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S9>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S9>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S9>:1:30' */
        /* '<S9>:1:31' */
        cc = 1.0;

        /* '<S9>:1:32' */
        min_dist = 1000.0;

        /* '<S9>:1:33' */
        index = 1.0;
        while ((uint32_T)cc <= (uint32_T)num_colors) {
          /* '<S9>:1:34' */
          /* '<S9>:1:35' */
          dist = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)cc + 49] -
            VisionModel_B.Resize1[(j - 1) * 60 + (i - 1)], 2.0) * 1.5 +
                       rt_pow_snf(rtb_ref_colors[(int32_T)cc - 1] -
            VisionModel_B.Resize[(j - 1) * 60 + (i - 1)], 2.0)) + rt_pow_snf
                      (rtb_ref_colors[(int32_T)cc + 99] - VisionModel_B.Resize2
                       [(j - 1) * 60 + (i - 1)], 2.0) * 1.5);
          if (min_dist > dist) {
            /* '<S9>:1:36' */
            /* '<S9>:1:37' */
            min_dist = dist;

            /* '<S9>:1:38' */
            index = cc;
          }

          /* '<S9>:1:40' */
          cc++;
        }

        if ((min_dist > 35.0) && (num_colors < 50)) {
          /* '<S9>:1:45' */
          /* '<S9>:1:46' */
          rtb_ref_colors[num_colors] = VisionModel_B.Resize[(j - 1) * 60 + (i -
            1)];
          rtb_ref_colors[num_colors + 50] = VisionModel_B.Resize1[(j - 1) * 60 +
            (i - 1)];
          rtb_ref_colors[num_colors + 100] = VisionModel_B.Resize2[(j - 1) * 60
            + (i - 1)];

          /* '<S9>:1:47' */
          num_colors++;

          /* '<S9>:1:48' */
          flag = 1;

          /* '<S9>:1:49' */
          i = 0;

          /* '<S9>:1:50' */
          j = 0;
        } else {
          /* '<S9>:1:52' */
          VisionModel_B.LabelMatrix_m[(i - 1) + 60 * (j - 1)] = (uint32_T)index;
        }

        /* '<S9>:1:54' */
        j++;
      }

      /* '<S9>:1:56' */
      j = 1;

      /* '<S9>:1:57' */
      i++;
    }

    /* '<S9>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S9>:1:63' */
  /* '<S9>:1:64' */
  /* '<S9>:1:65' */
  /* '<S9>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S9>:1:67' */
  for (flag = 0; flag < 60; flag++) {
    /* '<S9>:1:67' */
    /* '<S9>:1:68' */
    for (i = 0; i < 80; i++) {
      /* '<S9>:1:68' */
      /* '<S9>:1:69' */
      /* '<S9>:1:70' */
      ref_color_L_avg[(int32_T)VisionModel_B.LabelMatrix_m[flag + 60 * i] - 1] =
        ref_color_L_avg[(int32_T)VisionModel_B.LabelMatrix_m[60 * i + flag] - 1]
        + VisionModel_B.Resize[60 * i + flag];

      /* '<S9>:1:71' */
      ref_color_a_avg[(int32_T)VisionModel_B.LabelMatrix_m[flag + 60 * i] - 1] =
        ref_color_a_avg[(int32_T)VisionModel_B.LabelMatrix_m[60 * i + flag] - 1]
        + VisionModel_B.Resize1[60 * i + flag];

      /* '<S9>:1:72' */
      ref_color_b_avg[(int32_T)VisionModel_B.LabelMatrix_m[flag + 60 * i] - 1] =
        ref_color_b_avg[(int32_T)VisionModel_B.LabelMatrix_m[60 * i + flag] - 1]
        + VisionModel_B.Resize2[60 * i + flag];

      /* '<S9>:1:73' */
      color_count[(int32_T)VisionModel_B.LabelMatrix_m[flag + 60 * i] - 1] =
        color_count[(int32_T)VisionModel_B.LabelMatrix_m[60 * i + flag] - 1] +
        1.0;
    }
  }

  /* '<S9>:1:76' */
  /* '<S9>:1:77' */
  /* '<S9>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S9>:1:80' */
  for (rtb_num_colors = 1.0; (uint32_T)rtb_num_colors <= (uint32_T)num_colors;
       rtb_num_colors++) {
    /* '<S9>:1:80' */
    /* '<S9>:1:81' */
    rtb_ref_colors[(int32_T)rtb_num_colors - 1] = ref_color_L_avg[(int32_T)
      rtb_num_colors - 1];

    /* '<S9>:1:82' */
    rtb_ref_colors[(int32_T)rtb_num_colors + 49] = ref_color_a_avg[(int32_T)
      rtb_num_colors - 1];

    /* '<S9>:1:83' */
    rtb_ref_colors[(int32_T)rtb_num_colors + 99] = ref_color_b_avg[(int32_T)
      rtb_num_colors - 1];
  }

  rtb_num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<S3>/LabSegmentation' */
  /* Embedded MATLAB Function 'Segmentation/LabSegmentation': '<S8>:1' */
  /*  This function generates the label matrix */
  /* '<S8>:1:5' */
  memset((void *)(&VisionModel_B.LabelMatrix[0]), (int32_T)0U, 19200U * sizeof
         (uint32_T));

  /* '<S8>:1:7' */
  for (i = 0; i < 160; i++) {
    /* '<S8>:1:7' */
    /* '<S8>:1:8' */
    for (j = 0; j < 120; j++) {
      /* '<S8>:1:8' */
      /* '<S8>:1:9' */
      min_dist = 1000.0;

      /* '<S8>:1:10' */
      index = 1.0;

      /* '<S8>:1:11' */
      for (cc = 1.0; cc <= rtb_num_colors; cc++) {
        /* '<S8>:1:11' */
        /* '<S8>:1:12' */
        dist = sqrt((rt_pow_snf(rtb_ref_colors[(int32_T)cc - 1] -
          VisionModel_B.ColorSpaceConversion1_o1[160 * j + i], 2.0) + rt_pow_snf
                     (rtb_ref_colors[(int32_T)cc + 49] -
                      VisionModel_B.ColorSpaceConversion1_o2[160 * j + i], 2.0))
                    + rt_pow_snf(rtb_ref_colors[(int32_T)cc + 99] -
          VisionModel_B.ColorSpaceConversion1_o3[160 * j + i], 2.0));
        if (dist < min_dist) {
          /* '<S8>:1:13' */
          /* '<S8>:1:14' */
          min_dist = dist;

          /* '<S8>:1:15' */
          index = cc;
        }
      }

      /* '<S8>:1:18' */
      VisionModel_B.LabelMatrix[i + 160 * j] = (uint32_T)index;
    }
  }

  /* Embedded MATLAB: '<Root>/Display Image' */
  /* Embedded MATLAB Function 'Display Image': '<S1>:1' */
  /*  Initialize */
  /* '<S1>:1:6' */
  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /*  Allow only colors in specified range */
  /* '<S1>:1:12' */
  for (flag = 0; flag < 160; flag++) {
    /* '<S1>:1:12' */
    /* '<S1>:1:13' */
    for (i = 0; i < 120; i++) {
      /* '<S1>:1:13' */
      /* '<S1>:1:15' */
      VisionModel_B.L[flag + 160 * i] = rtb_ref_colors[(int32_T)
        VisionModel_B.LabelMatrix[160 * i + flag] - 1];

      /* '<S1>:1:16' */
      VisionModel_B.a[flag + 160 * i] = rtb_ref_colors[(int32_T)
        VisionModel_B.LabelMatrix[160 * i + flag] + 49];

      /* '<S1>:1:17' */
      VisionModel_B.b[flag + 160 * i] = rtb_ref_colors[(int32_T)
        VisionModel_B.LabelMatrix[160 * i + flag] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 19200; i++) {
    dist = (VisionModel_B.L[i] + 16.0) / 116.0;
    cc = VisionModel_B.a[i] / 500.0 + dist;
    rtb_num_colors = VisionModel_B.b[i] / -200.0 + dist;
    if (cc <= 0.20689655172413793) {
      cc -= 0.13793103448275862;
      cc /= 7.7870370370370372;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (dist <= 0.20689655172413793) {
      dist -= 0.13793103448275862;
      dist /= 7.7870370370370372;
    } else {
      dist = rt_pow_snf(dist, 3.0);
    }

    if (rtb_num_colors <= 0.20689655172413793) {
      rtb_num_colors -= 0.13793103448275862;
      rtb_num_colors /= 7.7870370370370372;
    } else {
      rtb_num_colors = rt_pow_snf(rtb_num_colors, 3.0);
    }

    cc *= 0.9504;
    rtb_num_colors *= 1.0889;

    /* assign the results */
    VisionModel_Y.R_forward_out[i] = cc;
    VisionModel_Y.G_forward_out[i] = dist;
    VisionModel_Y.B_forward_out[i] = rtb_num_colors;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    cc = (3.24096994190451 * VisionModel_Y.R_forward_out[i] + -1.53738317757009 *
          VisionModel_Y.G_forward_out[i]) + -0.49861076029299 *
      VisionModel_Y.B_forward_out[i];
    dist = (-0.96924363628087 * VisionModel_Y.R_forward_out[i] +
            1.87596750150771 * VisionModel_Y.G_forward_out[i]) +
      0.04155505740718 * VisionModel_Y.B_forward_out[i];
    rtb_num_colors = (0.055630079697 * VisionModel_Y.R_forward_out[i] +
                      -0.20397695888899 * VisionModel_Y.G_forward_out[i]) +
      1.05697151424288 * VisionModel_Y.B_forward_out[i];

    /* Apply gamma correction to get R'G'B' */
    if (cc <= 0.00304) {
      cc *= 12.923054468333255;
    } else {
      cc = 1.0550005198172263 * rt_pow_snf(cc, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (dist <= 0.00304) {
      dist *= 12.923054468333255;
    } else {
      dist = 1.0550005198172263 * rt_pow_snf(dist, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (rtb_num_colors <= 0.00304) {
      rtb_num_colors *= 12.923054468333255;
    } else {
      rtb_num_colors = 1.0550005198172263 * rt_pow_snf(rtb_num_colors,
        0.41666666666666669) - 0.055000519817226347;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (dist > 1.0) {
      dist = 1.0;
    } else {
      if (dist < 0.0) {
        dist = 0.0;
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
    VisionModel_Y.R_forward_out[i] = cc;
    VisionModel_Y.G_forward_out[i] = dist;
    VisionModel_Y.B_forward_out[i] = rtb_num_colors;
  }

  /* Embedded MATLAB: '<Root>/make_color_range' */
  /* Embedded MATLAB Function 'make_color_range': '<S4>:1' */
  /*  This function forms two compact matrices which pass all color range */
  /*    information to other functions in the model */
  /*  Initialize */
  /* '<S4>:1:8' */
  /* '<S4>:1:9' */
  /*  Assign values to color range matrices */
  /* '<S4>:1:13' */
  /* '<S4>:1:14' */
  /* '<S4>:1:15' */
  /* '<S4>:1:16' */
  /* '<S4>:1:18' */
  /* '<S4>:1:19' */
  /* '<S4>:1:20' */
  /* '<S4>:1:21' */
  /* '<S4>:1:23' */
  /* '<S4>:1:24' */
  /* '<S4>:1:25' */
  /* '<S4>:1:26' */
  /* '<S4>:1:28' */
  /* '<S4>:1:29' */
  /* '<S4>:1:30' */
  /* '<S4>:1:31' */
  /* '<S4>:1:33' */
  /* '<S4>:1:34' */
  /* '<S4>:1:35' */
  /* '<S4>:1:36' */
  /* '<S4>:1:38' */
  /* '<S4>:1:39' */
  /* '<S4>:1:40' */
  /* '<S4>:1:41' */
  /* '<S4>:1:43' */
  /* '<S4>:1:44' */
  /* '<S4>:1:45' */
  /* '<S4>:1:46' */
}

/* Model initialize function */
void VisionModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(VisionModel_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &VisionModel_B), 0,
                sizeof(BlockIO_VisionModel));

  /* states (dwork) */
  (void) memset((void *)&VisionModel_DWork, 0,
                sizeof(D_Work_VisionModel));

  /* external inputs */
  (void) memset((void *)&VisionModel_U, 0,
                sizeof(ExternalInputs_VisionModel));

  /* external outputs */
  (void) memset((void *)&VisionModel_Y, 0,
                sizeof(ExternalOutputs_VisionModel));

  /* Outport: '<Root>/R_down_out' */
  VisionModel_Y.R_down_out = 0.0;

  /* Outport: '<Root>/G_down_out' */
  VisionModel_Y.G_down_out = 0.0;

  /* Outport: '<Root>/B_down_out' */
  VisionModel_Y.B_down_out = 0.0;

  /* Outport: '<Root>/TargetSelect' */
  VisionModel_Y.TargetSelect = VisionModel_ConstB.Add;

  /* Outport: '<Root>/TargetX' */
  VisionModel_Y.TargetX = VisionModel_ConstB.Add3;

  /* Outport: '<Root>/TargetY' */
  VisionModel_Y.TargetY = VisionModel_ConstB.Add4;

  /* Outport: '<Root>/TargetZ' */
  VisionModel_Y.TargetZ = VisionModel_ConstB.Add5;

  /* Outport: '<Root>/TargetYaw' */
  VisionModel_Y.TargetYaw = VisionModel_ConstB.Add6;

  /* Outport: '<Root>/DesiredTargetX' incorporates:
   *  Constant: '<Root>/Constant'
   */
  VisionModel_Y.DesiredTargetX = 0.0;

  /* Outport: '<Root>/DesiredTargetY' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  VisionModel_Y.DesiredTargetY = 0.0;

  /* Outport: '<Root>/DesiredTargetZ' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  VisionModel_Y.DesiredTargetZ = 0.0;

  /* Outport: '<Root>/DesiredTargetYaw' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  VisionModel_Y.DesiredTargetYaw = 0.0;

  /* Outport: '<Root>/TargetDetected' */
  VisionModel_Y.TargetDetected = VisionModel_ConstB.Add18;

  /* Outport: '<Root>/PathState' */
  VisionModel_Y.PathState = VisionModel_ConstB.Add19;

  /* Outport: '<Root>/BuoyColors' */
  VisionModel_Y.BuoyColors = 0.0;

  /* Outport: '<Root>/FireAuthorization' */
  VisionModel_Y.FireAuthorization = VisionModel_ConstB.Add21;

  /* Outport: '<Root>/TargetType' */
  VisionModel_Y.TargetType = 0.0;

  /* Outport: '<Root>/TargetSize' */
  VisionModel_Y.TargetSize = 0.0;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
