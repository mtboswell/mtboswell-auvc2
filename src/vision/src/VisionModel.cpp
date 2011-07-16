/*
 * File: VisionModel.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.1591
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sat Jul 16 10:14:56 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sat Jul 16 10:14:57 2011
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

/* Forward declaration for local functions */
static void VisionModel_conv2_g(const real_T arg1[19200], const real_T arg2[9],
  real_T c[18644]);

/* Forward declaration for local functions */
static real_T VisionModel_sum_e(const real_T x[7]);
static void VisionModel_Outputs_e(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8);
static void VisionModel_refp1_round_e(real_T *x);
static real_T VisionModel_sum(const real_T x[7]);
static real_T VisionModel_mod(real_T x, real_T y);
static real_T VisionModel_norm(const real_T x[2]);
static real_T VisionModel_sum_k(const real_T x[3]);
static void VisionModel_Outputs(const boolean_T U0[19200], int32_T Y0[50],
  real_T Y1[100], int32_T Y2[200], real_T Y3[50], real_T Y4[50], real_T Y5[50],
  real_T Y6[50], real_T Y7[50], uint8_T *Y8);
static void VisionModel_refp1_round(real_T *x);
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

/*
 * Output and update for action system:
 *    '<S5>/validation_gate'
 *    '<S5>/path_detector'
 *    '<S5>/buoy_detector'
 *    '<S5>/torpedo'
 *    '<S5>/L_detector'
 *    '<S5>/drop_mech'
 */
void VisionModel_validation_gate(rtB_validation_gate_VisionModel *localB,
  rtP_validation_gate_VisionModel *localP)
{
  int32_T i;

  /* Constant: '<S44>/ColorFilter1' */
  for (i = 0; i < 7; i++) {
    localB->ColorFilter1[i] = localP->ColorFilter1_Value[i];
  }

  /* Constant: '<S44>/OutputSegmentedImage1' */
  localB->OutputSegmentedImage1 = localP->OutputSegmentedImage1_Value;
}

/* Function for Embedded MATLAB: '<S18>/Low Pass Filter' */
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
 *    '<S18>/Low Pass Filter'
 *    '<S18>/Low Pass Filter1'
 *    '<S18>/Low Pass Filter2'
 */
void VisionModel_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_VisionModel *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S18>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Blob_Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S20>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S20>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S20>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S20>:1:19' */
  /* '<S20>:1:21' */
  /* '<S20>:1:23' */
  Gsum = 0.0;

  /* '<S20>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S20>:1:24' */
    /* '<S20>:1:25' */
    /* '<S20>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S20>:1:27' */
    Gsum += G[i + 1];

    /* '<S20>:1:25' */
    /* '<S20>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S20>:1:27' */
    Gsum += G[i + 4];

    /* '<S20>:1:25' */
    /* '<S20>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S20>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S20>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S20>:1:33' */
  VisionModel_conv2(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S20>:1:37' */
  for (i = 0; i < 118; i++) {
    localB->Iout[160 * (1 + i)] = localB->Itemp[158 * i];
  }

  /*  bottom */
  /* '<S20>:1:39' */
  for (i = 0; i < 118; i++) {
    localB->Iout[159 + 160 * (1 + i)] = localB->Itemp[158 * i + 157];
  }

  /*  left */
  /* '<S20>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 158U * sizeof
         (real_T));

  /*  right */
  /* '<S20>:1:43' */
  memcpy((void *)(&localB->Iout[19041]), (void *)(&localB->Itemp[18486]), 158U *
         sizeof(real_T));

  /*  center */
  /* '<S20>:1:45' */
  for (i = 0; i < 118; i++) {
    memcpy((void *)(&localB->Iout[1 + 160 * (1 + i)]), (void *)(&localB->Itemp
            [158 * i]), 158U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S20>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S20>:1:49' */
  localB->Iout[18880] = localB->Itemp[18328];
  localB->Iout[19040] = localB->Itemp[18486];

  /*  bottom left corner */
  /* '<S20>:1:51' */
  localB->Iout[158] = localB->Itemp[156];
  localB->Iout[159] = localB->Itemp[157];

  /*  bottom right corner */
  /* '<S20>:1:53' */
  localB->Iout[19038] = localB->Itemp[18484];
  localB->Iout[19039] = localB->Itemp[18485];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/*
 * Output and update for atomic system:
 *    '<S19>/Reference Color Selection'
 *    '<S31>/Reference Color Selection'
 */
void VisionM_ReferenceColorSelection(const real_T rtu_L[4800], const real_T
  rtu_a[4800], const real_T rtu_b[4800], real_T rtu_Dist_Thresh,
  rtB_ReferenceColorSelection_Vis *localB)
{
  int32_T num_colors;
  int32_T flag;
  int32_T i;
  int32_T j;
  uint32_T k;
  real_T min_dist;
  int32_T index;
  real_T dist;
  real_T ref_color_L_avg[50];
  real_T ref_color_a_avg[50];
  real_T ref_color_b_avg[50];
  real_T color_count[50];

  /* Embedded MATLAB: '<S19>/Reference Color Selection' */
  /* Embedded MATLAB Function 'Blob_Analysis/IterativeSegmentation/Segmentation/Reference Color Selection': '<S24>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S24>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S24>:1:14' */
  /* '<S24>:1:15' */
  memset((void *)(&localB->ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S24>:1:16' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0U, 4800U * sizeof(uint32_T));

  /* '<S24>:1:17' */
  num_colors = 1;

  /*  Define first reference color to be colr */
  /* '<S24>:1:23' */
  localB->ref_colors[0] = rtu_L[2369];
  localB->ref_colors[50] = rtu_a[2369];
  localB->ref_colors[100] = rtu_b[2369];

  /* '<S24>:1:25' */
  flag = 0;

  /* '<S24>:1:26' */
  i = 1;

  /* '<S24>:1:27' */
  j = 1;
  while (i <= 60) {
    /* '<S24>:1:28' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S24>:1:29' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S24>:1:30' */
        /* '<S24>:1:31' */
        k = 1U;

        /* '<S24>:1:32' */
        min_dist = 1000.0;

        /* '<S24>:1:33' */
        index = 1;
        while (k <= (uint32_T)num_colors) {
          /* '<S24>:1:34' */
          /* '<S24>:1:35' */
          dist = sqrt((rt_pow_snf(localB->ref_colors[(int32_T)k + 49] - rtu_a[(j
            - 1) * 60 + (i - 1)], 2.0) * 1.5 + rt_pow_snf(localB->ref_colors
            [(int32_T)k - 1] - rtu_L[(j - 1) * 60 + (i - 1)], 2.0)) + rt_pow_snf
                      (localB->ref_colors[(int32_T)k + 99] - rtu_b[(j - 1) * 60
                       + (i - 1)], 2.0) * 1.5);
          if (min_dist > dist) {
            /* '<S24>:1:36' */
            /* '<S24>:1:37' */
            min_dist = dist;

            /* '<S24>:1:38' */
            index = (int32_T)k;
          }

          /* '<S24>:1:40' */
          k++;
        }

        if ((min_dist > rtu_Dist_Thresh) && (num_colors < 50)) {
          /* '<S24>:1:45' */
          /* '<S24>:1:46' */
          localB->ref_colors[num_colors] = rtu_L[(j - 1) * 60 + (i - 1)];
          localB->ref_colors[num_colors + 50] = rtu_a[(j - 1) * 60 + (i - 1)];
          localB->ref_colors[num_colors + 100] = rtu_b[(j - 1) * 60 + (i - 1)];

          /* '<S24>:1:47' */
          num_colors++;

          /* '<S24>:1:48' */
          flag = 1;

          /* '<S24>:1:49' */
          i = 0;

          /* '<S24>:1:50' */
          j = 0;
        } else {
          /* '<S24>:1:52' */
          localB->LabelMatrix[(i - 1) + 60 * (j - 1)] = (uint32_T)index;
        }

        /* '<S24>:1:54' */
        j++;
      }

      /* '<S24>:1:56' */
      j = 1;

      /* '<S24>:1:57' */
      i++;
    }

    /* '<S24>:1:59' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S24>:1:63' */
  /* '<S24>:1:64' */
  /* '<S24>:1:65' */
  /* '<S24>:1:66' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S24>:1:67' */
  for (flag = 0; flag < 60; flag++) {
    /* '<S24>:1:67' */
    /* '<S24>:1:68' */
    for (i = 0; i < 80; i++) {
      /* '<S24>:1:68' */
      /* '<S24>:1:69' */
      /* '<S24>:1:70' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix[flag + 60 * i] - 1] =
        ref_color_L_avg[(int32_T)localB->LabelMatrix[60 * i + flag] - 1] +
        rtu_L[60 * i + flag];

      /* '<S24>:1:71' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix[flag + 60 * i] - 1] =
        ref_color_a_avg[(int32_T)localB->LabelMatrix[60 * i + flag] - 1] +
        rtu_a[60 * i + flag];

      /* '<S24>:1:72' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix[flag + 60 * i] - 1] =
        ref_color_b_avg[(int32_T)localB->LabelMatrix[60 * i + flag] - 1] +
        rtu_b[60 * i + flag];

      /* '<S24>:1:73' */
      color_count[(int32_T)localB->LabelMatrix[flag + 60 * i] - 1] =
        color_count[(int32_T)localB->LabelMatrix[60 * i + flag] - 1] + 1.0;
    }
  }

  /* '<S24>:1:76' */
  /* '<S24>:1:77' */
  /* '<S24>:1:78' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S24>:1:80' */
  for (k = 1U; k <= (uint32_T)num_colors; k++) {
    /* '<S24>:1:80' */
    /* '<S24>:1:81' */
    localB->ref_colors[(int32_T)k - 1] = ref_color_L_avg[(int32_T)k - 1];

    /* '<S24>:1:82' */
    localB->ref_colors[(int32_T)k + 49] = ref_color_a_avg[(int32_T)k - 1];

    /* '<S24>:1:83' */
    localB->ref_colors[(int32_T)k + 99] = ref_color_b_avg[(int32_T)k - 1];
  }

  localB->num_colors = (real_T)num_colors;
}

/* Function for Embedded MATLAB: '<S30>/Low Pass Filter' */
static void VisionModel_conv2_g(const real_T arg1[19200], const real_T arg2[9],
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
  for (jc = 0; jc < 158; jc++) {
    j = jc + 3;
    jp = j + 1;
    ja = jp - 3;
    for (ic = 0; ic < 118; ic++) {
      i = ic + 3;
      ip = i + 1;
      ia = ip - 3;
      s = 0.0;
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
 *    '<S30>/Low Pass Filter'
 *    '<S30>/Low Pass Filter1'
 *    '<S30>/Low Pass Filter2'
 */
void VisionModel_LowPassFilter_f(const real_T rtu_I[19200],
  rtB_LowPassFilter_VisionModel_h *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;

  /* Embedded MATLAB: '<S30>/Low Pass Filter' */
  /* Embedded MATLAB Function 'Blob_Analysis1/IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S32>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S32>:1:11' */
  memset((void *)(&localB->Iout[0]), 0, 19200U * sizeof(real_T));

  /* '<S32>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S32>:1:19' */
  /* '<S32>:1:21' */
  /* '<S32>:1:23' */
  Gsum = 0.0;

  /* '<S32>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S32>:1:24' */
    /* '<S32>:1:25' */
    /* '<S32>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S32>:1:27' */
    Gsum += G[i + 1];

    /* '<S32>:1:25' */
    /* '<S32>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S32>:1:27' */
    Gsum += G[i + 4];

    /* '<S32>:1:25' */
    /* '<S32>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S32>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S32>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S32>:1:33' */
  VisionModel_conv2_g(&rtu_I[0], G, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S32>:1:37' */
  for (i = 0; i < 158; i++) {
    localB->Iout[120 * (1 + i)] = localB->Itemp[118 * i];
  }

  /*  bottom */
  /* '<S32>:1:39' */
  for (i = 0; i < 158; i++) {
    localB->Iout[119 + 120 * (1 + i)] = localB->Itemp[118 * i + 117];
  }

  /*  left */
  /* '<S32>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 118U * sizeof
         (real_T));

  /*  right */
  /* '<S32>:1:43' */
  memcpy((void *)(&localB->Iout[19081]), (void *)(&localB->Itemp[18526]), 118U *
         sizeof(real_T));

  /*  center */
  /* '<S32>:1:45' */
  for (i = 0; i < 158; i++) {
    memcpy((void *)(&localB->Iout[1 + 120 * (1 + i)]), (void *)(&localB->Itemp
            [118 * i]), 118U * sizeof(real_T));
  }

  /*  top left corner */
  /* '<S32>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S32>:1:49' */
  localB->Iout[18960] = localB->Itemp[18408];
  localB->Iout[19080] = localB->Itemp[18526];

  /*  bottom left corner */
  /* '<S32>:1:51' */
  localB->Iout[118] = localB->Itemp[116];
  localB->Iout[119] = localB->Itemp[117];

  /*  bottom right corner */
  /* '<S32>:1:53' */
  localB->Iout[19078] = localB->Itemp[18524];
  localB->Iout[19079] = localB->Itemp[18525];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
}

/*
 * Output and update for atomic system:
 *    '<S61>/Transform Coordinates3'
 *    '<S54>/Transform Coordinates3'
 *    '<S49>/Transform Coordinates3'
 *    '<S58>/Transform Coordinates3'
 *    '<S46>/Transform Coordinates3'
 */
void VisionMod_TransformCoordinates3(real_T rtu_which_camera, real_T rtu_x_in,
  real_T rtu_y_in, real_T rtu_z_in, const real_T rtu_Camera_Dimensions[2],
  rtB_TransformCoordinates3_Visio *localB)
{
  /* Embedded MATLAB: '<S61>/Transform Coordinates3' */
  /* Embedded MATLAB Function 'validation_gate/If Action Subsystem/Transform Coordinates3': '<S62>:1' */
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
  /* '<S62>:1:20' */
  /* '<S62>:1:21' */
  if (rtu_which_camera == 0.0) {
    /* '<S62>:1:22' */
    /* '<S62>:1:23' */
    localB->points[0] = floor(rtu_Camera_Dimensions[0] / 2.0) + rtu_z_in;
    localB->points[1] = floor(rtu_Camera_Dimensions[1] / 2.0) + rtu_y_in;
  } else {
    /* '<S62>:1:26' */
    localB->points[0] = floor(rtu_Camera_Dimensions[0] / 2.0) - rtu_x_in;
    localB->points[1] = floor(rtu_Camera_Dimensions[1] / 2.0) + rtu_y_in;
  }
}

/*
 * Output and update for action system:
 *    '<S9>/If Action Subsystem'
 *    '<S13>/If Action Subsystem'
 *    '<S8>/If Action Subsystem'
 */
void VisionModel_IfActionSubsystem(const real_T rtu_R_in[19200], real_T
  rtu_which_camera, real_T rtu_x_in, real_T rtu_y_in, real_T rtu_z_in, const
  real_T rtu_Camera_Dimensions[2], rtB_IfActionSubsystem_VisionMod *localB,
  rtP_IfActionSubsystem_VisionMod *localP)
{
  int32_T idxROI;
  int32_T row;
  int32_T col;
  int32_T size;
  int32_T in;
  int32_T idxPix;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T OutCode;
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;
  real_T tmp;

  /* Embedded MATLAB: '<S49>/Transform Coordinates3' */
  VisionMod_TransformCoordinates3(rtu_which_camera, rtu_x_in, rtu_y_in, rtu_z_in,
    rtu_Camera_Dimensions, &localB->sf_TransformCoordinates3);

  /* S-Function (svipdrawmarkers): '<S49>/Draw Target' */
  /* Copy the image from input to output. */
  for (i = 0; i < 19200; i++) {
    localB->DrawTarget_o1[i] = rtu_R_in[i];
    localB->DrawTarget_o2[i] = rtu_R_in[i];
    localB->DrawTarget_o3[i] = rtu_R_in[i];
  }

  /* Draw all X marks. */
  tmp = localP->DrawTarget_RTP_SIZE;
  if ((localP->DrawTarget_RTP_SIZE < 4.503599627370496E+15) &&
      (localP->DrawTarget_RTP_SIZE > -4.503599627370496E+15)) {
    tmp = floor(localP->DrawTarget_RTP_SIZE + 0.5);
  }

  size = (int32_T)tmp;
  for (idxROI = 0; idxROI < 2; idxROI += 2) {
    tmp = localB->sf_TransformCoordinates3.points[idxROI];
    if ((localB->sf_TransformCoordinates3.points[idxROI] < 4.503599627370496E+15)
        && (localB->sf_TransformCoordinates3.points[idxROI] >
            -4.503599627370496E+15)) {
      tmp = floor(localB->sf_TransformCoordinates3.points[idxROI] + 0.5);
    }

    row = (int32_T)tmp;
    tmp = localB->sf_TransformCoordinates3.points[idxROI + 1];
    if ((localB->sf_TransformCoordinates3.points[idxROI + 1] <
         4.503599627370496E+15) && (localB->
         sf_TransformCoordinates3.points[idxROI + 1] > -4.503599627370496E+15))
    {
      tmp = floor(localB->sf_TransformCoordinates3.points[idxROI + 1] + 0.5);
    }

    col = (int32_T)tmp;
    line_idx = row - size;
    line_idx_0 = col - size;
    line_idx_1 = row + size;
    line_idx_2 = col + size;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_4 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_5 = line_idx_1;
    line_idx_6 = line_idx_2;
    while (!done) {
      in = 0;
      OutCode = 0;

      /* Determine viewport violations. */
      if (line_idx_4 < 0) {
        in = 4;
      } else {
        if (line_idx_4 > 159) {
          in = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_5 > 159) {
          OutCode = 8;
        }
      }

      if (line_idx_3 < 0) {
        in = (int32_T)((uint32_T)in | 1U);
      } else {
        if (line_idx_3 > 119) {
          in = (int32_T)((uint32_T)in | 2U);
        }
      }

      if (line_idx_6 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_6 > 119) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (!((uint32_T)in | (uint32_T)OutCode)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)in & (uint32_T)OutCode) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)in != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_4 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = line_idx_5 - line_idx_4;
        idxPix = line_idx_6 - line_idx_3;
        if ((uint32_T)in & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else if ((uint32_T)in & 8U) {
          /* Violated RMax. */
          in = (159 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited = TRUE;
        } else if ((uint32_T)in & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (119 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_5 = line_idx_1;
          line_idx_6 = line_idx_2;
        }

        i = line_idx_5 - line_idx_4;
        idxPix = line_idx_6 - line_idx_3;
        if ((uint32_T)OutCode & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_5) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode & 8U) {
          /* Violated RMax. */
          in = (159 - line_idx_5) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_6) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (119 - line_idx_6) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_6 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 160 + line_idx_4;
      for (in = line_idx_4; in <= line_idx_5; in++) {
        localB->DrawTarget_o1[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[0];
        localB->DrawTarget_o2[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[1];
        localB->DrawTarget_o3[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[2];
        idxPix += 161;
      }
    }

    line_idx = row - size;
    line_idx_0 = col + size;
    line_idx_1 = row + size;
    line_idx_2 = col - size;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_4 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_5 = line_idx_1;
    line_idx_6 = line_idx_2;
    while (!done) {
      in = 0;
      OutCode = 0;

      /* Determine viewport violations. */
      if (line_idx_4 < 0) {
        in = 4;
      } else {
        if (line_idx_4 > 159) {
          in = 8;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_5 > 159) {
          OutCode = 8;
        }
      }

      if (line_idx_3 < 0) {
        in = (int32_T)((uint32_T)in | 1U);
      } else {
        if (line_idx_3 > 119) {
          in = (int32_T)((uint32_T)in | 2U);
        }
      }

      if (line_idx_6 < 0) {
        OutCode = (int32_T)((uint32_T)OutCode | 1U);
      } else {
        if (line_idx_6 > 119) {
          OutCode = (int32_T)((uint32_T)OutCode | 2U);
        }
      }

      if (!((uint32_T)in | (uint32_T)OutCode)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)in & (uint32_T)OutCode) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)in != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_4 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = line_idx_5 - line_idx_4;
        idxPix = line_idx_6 - line_idx_3;
        if ((uint32_T)in & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else if ((uint32_T)in & 8U) {
          /* Violated RMax. */
          in = (159 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited = TRUE;
        } else if ((uint32_T)in & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (119 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_5 = line_idx_1;
          line_idx_6 = line_idx_2;
        }

        i = line_idx_5 - line_idx_4;
        idxPix = line_idx_6 - line_idx_3;
        if ((uint32_T)OutCode & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_5) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode & 8U) {
          /* Violated RMax. */
          in = (159 - line_idx_5) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        } else if ((uint32_T)OutCode & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_6) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (119 - line_idx_6) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_6 = 119;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 160 + line_idx_4;
      for (in = line_idx_4; in <= line_idx_5; in++) {
        localB->DrawTarget_o1[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[0];
        localB->DrawTarget_o2[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[1];
        localB->DrawTarget_o3[idxPix] = localP->DrawTarget_RTP_FILLCOLOR[2];
        idxPix += -159;
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S4>/Blob Extraction' */
static real_T VisionModel_sum_e(const real_T x[7])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 2; k < 8; k++) {
    y += x[k - 1];
  }

  return y;
}

/* Function for Embedded MATLAB: '<S4>/Blob Extraction' */
static void VisionModel_Outputs_e(const boolean_T U0[19200], int32_T Y0[50],
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
  memset((void *)(&VisionModel_DWork.PAD_DW[0]), (int32_T)0U, 123U * sizeof
         (uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (maxc = 0; maxc < 120; maxc++) {
      VisionModel_DWork.PAD_DW[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    VisionModel_DWork.PAD_DW[idx] = 0U;
    idx++;
    VisionModel_DWork.PAD_DW[idx] = 0U;
    idx++;
  }

  memset((void *)(&VisionModel_DWork.PAD_DW[idx]), (int32_T)0U, 121U * sizeof
         (uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    maxc = 1;
    idx = loop * 122;
    for (maxr = 0; maxr < 120; maxr++) {
      k = (uint32_T)(idx + maxc);
      start_pixIdx = pixIdx;
      if (VisionModel_DWork.PAD_DW[k] == 255) {
        VisionModel_DWork.PAD_DW[k] = currentLabel;
        VisionModel_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)(loop - 1);
        VisionModel_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)(maxc - 1);
        pixIdx++;
        VisionModel_DWork.NUM_PIX_DW[currentLabel - 1] = 1U;
        VisionModel_DWork.STACK_DW[stackIdx] = k;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          k = VisionModel_DWork.STACK_DW[stackIdx];
          for (j = 0; j < 8; j++) {
            walkerIdx = k + (uint32_T)VisionModel_DWork.WALKER_RTP[j];
            if (VisionModel_DWork.PAD_DW[walkerIdx] == 255) {
              VisionModel_DWork.PAD_DW[walkerIdx] = currentLabel;
              VisionModel_DWork.N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 122U) - 1);
              VisionModel_DWork.M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx %
                122U - 1U);
              pixIdx++;
              VisionModel_DWork.NUM_PIX_DW[currentLabel - 1] =
                VisionModel_DWork.NUM_PIX_DW[currentLabel - 1] + 1U;
              VisionModel_DWork.STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (VisionModel_DWork.NUM_PIX_DW[currentLabel - 1] <
            VisionModel_DWork.MINAREA_RTP) {
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
    Y0[c_i] = (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i];
    loop = 0;
    n = 0;
    for (j = 0; j < (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i]; j++) {
      loop += VisionModel_DWork.N_PIXLIST_DW[j + pixListNinc];
      n += VisionModel_DWork.M_PIXLIST_DW[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)VisionModel_DWork.NUM_PIX_DW[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)VisionModel_DWork.NUM_PIX_DW[c_i];
    Y1[c_i << 1] = centroid_idx;
    Y1[(c_i << 1) + 1] = centroid_idx_0;
    n = 160;
    idx = 120;
    maxc = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i]; j++) {
      loop = j + pixListNinc;
      if (VisionModel_DWork.N_PIXLIST_DW[loop] < n) {
        n = VisionModel_DWork.N_PIXLIST_DW[loop];
      }

      if (VisionModel_DWork.N_PIXLIST_DW[loop] > maxc) {
        maxc = VisionModel_DWork.N_PIXLIST_DW[loop];
      }

      loop = j + pixListMinc;
      if (VisionModel_DWork.M_PIXLIST_DW[loop] < idx) {
        idx = VisionModel_DWork.M_PIXLIST_DW[loop];
      }

      if (VisionModel_DWork.M_PIXLIST_DW[loop] > maxr) {
        maxr = VisionModel_DWork.M_PIXLIST_DW[loop];
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
    for (k = 0U; (int32_T)k < (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i]; k++) {
      uxy = (real_T)VisionModel_DWork.N_PIXLIST_DW[pixListNinc + (int32_T)k] -
        centroid_idx_0;
      common = (real_T)VisionModel_DWork.M_PIXLIST_DW[pixListMinc + (int32_T)k]
        - centroid_idx;
      xs += uxy * uxy;
      ys += common * common;
      xys += uxy * (-common);
    }

    centroid_idx = xs / (real_T)VisionModel_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    centroid_idx_0 = ys / (real_T)VisionModel_DWork.NUM_PIX_DW[c_i] +
      0.083333333333333329;
    uxy = xys / (real_T)VisionModel_DWork.NUM_PIX_DW[c_i];
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
    Y7[c_i] = (real_T)VisionModel_DWork.NUM_PIX_DW[c_i] / (real_T)(maxr * j);
    pixListMinc += (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)VisionModel_DWork.NUM_PIX_DW[c_i];
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y0[loop] = VisionModel_DWork.F0_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y1[loop] = VisionModel_DWork.F1_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 2); loop < 200; loop++) {
    Y2[loop] = VisionModel_DWork.F2_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y3[loop] = VisionModel_DWork.F3_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y4[loop] = VisionModel_DWork.F4_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y5[loop] = VisionModel_DWork.F5_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y6[loop] = VisionModel_DWork.F6_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y7[loop] = VisionModel_DWork.F7_RTP;
  }
}

/* Function for Embedded MATLAB: '<S4>/Blob Extraction' */
static void VisionModel_refp1_round_e(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/* Function for Embedded MATLAB: '<S3>/Blob Extraction' */
static real_T VisionModel_sum(const real_T x[7])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 2; k < 8; k++) {
    y += x[k - 1];
  }

  return y;
}

/* Function for Embedded MATLAB: '<S8>/Identify L-Obstacle' */
static real_T VisionModel_mod(real_T x, real_T y)
{
  real_T r;
  real_T b_x;
  if (y == 0.0) {
    return x;
  } else if (y == floor(y)) {
    return x - floor(x / y) * y;
  } else {
    r = x / y;
    if (r < 0.0) {
      b_x = ceil(r - 0.5);
    } else {
      b_x = floor(r + 0.5);
    }

    if (fabs(r - b_x) <= 2.2204460492503131E-16 * fabs(r)) {
      return 0.0;
    } else {
      return (r - floor(r)) * y;
    }
  }
}

/* Function for Embedded MATLAB: '<S14>/Identify Validation Gate' */
static real_T VisionModel_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 0.0;
  firstNonZero = TRUE;
  if (x[0] != 0.0) {
    scale = fabs(x[0]);
    y = 1.0;
    firstNonZero = FALSE;
  }

  if (x[1] != 0.0) {
    absxk = fabs(x[1]);
    if (firstNonZero) {
      scale = absxk;
      y = 1.0;
    } else if (scale < absxk) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for Embedded MATLAB: '<S14>/Identify Validation Gate' */
static real_T VisionModel_sum_k(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

/* Function for Embedded MATLAB: '<S3>/Blob Extraction' */
static void VisionModel_Outputs(const boolean_T U0[19200], int32_T Y0[50],
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
  memset((void *)(&VisionModel_DWork.PAD_DW_m[0]), (int32_T)0U, 163U * sizeof
         (uint8_T));
  currentLabel = 1U;
  loop = 0;
  idx = 163;
  for (n = 0; n < 120; n++) {
    for (maxc = 0; maxc < 160; maxc++) {
      VisionModel_DWork.PAD_DW_m[idx] = (uint8_T)(U0[loop] ? 255 : 0);
      loop++;
      idx++;
    }

    VisionModel_DWork.PAD_DW_m[idx] = 0U;
    idx++;
    VisionModel_DWork.PAD_DW_m[idx] = 0U;
    idx++;
  }

  memset((void *)(&VisionModel_DWork.PAD_DW_m[idx]), (int32_T)0U, 161U * sizeof
         (uint8_T));
  loop = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 120; n++) {
    maxc = 1;
    idx = loop * 162;
    for (maxr = 0; maxr < 160; maxr++) {
      k = (uint32_T)(idx + maxc);
      start_pixIdx = pixIdx;
      if (VisionModel_DWork.PAD_DW_m[k] == 255) {
        VisionModel_DWork.PAD_DW_m[k] = currentLabel;
        VisionModel_DWork.N_PIXLIST_DW_l[pixIdx] = (int16_T)(loop - 1);
        VisionModel_DWork.M_PIXLIST_DW_i[pixIdx] = (int16_T)(maxc - 1);
        pixIdx++;
        VisionModel_DWork.NUM_PIX_DW_f[currentLabel - 1] = 1U;
        VisionModel_DWork.STACK_DW_a[stackIdx] = k;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          k = VisionModel_DWork.STACK_DW_a[stackIdx];
          for (j = 0; j < 8; j++) {
            walkerIdx = k + (uint32_T)VisionModel_DWork.WALKER_RTP_f[j];
            if (VisionModel_DWork.PAD_DW_m[walkerIdx] == 255) {
              VisionModel_DWork.PAD_DW_m[walkerIdx] = currentLabel;
              VisionModel_DWork.N_PIXLIST_DW_l[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 162U) - 1);
              VisionModel_DWork.M_PIXLIST_DW_i[pixIdx] = (int16_T)(walkerIdx %
                162U - 1U);
              pixIdx++;
              VisionModel_DWork.NUM_PIX_DW_f[currentLabel - 1] =
                VisionModel_DWork.NUM_PIX_DW_f[currentLabel - 1] + 1U;
              VisionModel_DWork.STACK_DW_a[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (VisionModel_DWork.NUM_PIX_DW_f[currentLabel - 1] <
            VisionModel_DWork.MINAREA_RTP_h) {
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
    Y0[c_i] = (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
    loop = 0;
    n = 0;
    for (j = 0; j < (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i]; j++) {
      loop += VisionModel_DWork.N_PIXLIST_DW_l[j + pixListNinc];
      n += VisionModel_DWork.M_PIXLIST_DW_i[j + pixListMinc];
    }

    centroid_idx = (real_T)n / (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
    centroid_idx_0 = (real_T)loop / (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
    Y1[c_i << 1] = centroid_idx;
    Y1[(c_i << 1) + 1] = centroid_idx_0;
    n = 120;
    idx = 160;
    maxc = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i]; j++) {
      loop = j + pixListNinc;
      if (VisionModel_DWork.N_PIXLIST_DW_l[loop] < n) {
        n = VisionModel_DWork.N_PIXLIST_DW_l[loop];
      }

      if (VisionModel_DWork.N_PIXLIST_DW_l[loop] > maxc) {
        maxc = VisionModel_DWork.N_PIXLIST_DW_l[loop];
      }

      loop = j + pixListMinc;
      if (VisionModel_DWork.M_PIXLIST_DW_i[loop] < idx) {
        idx = VisionModel_DWork.M_PIXLIST_DW_i[loop];
      }

      if (VisionModel_DWork.M_PIXLIST_DW_i[loop] > maxr) {
        maxr = VisionModel_DWork.M_PIXLIST_DW_i[loop];
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
    for (k = 0U; (int32_T)k < (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i]; k++)
    {
      uxy = (real_T)VisionModel_DWork.N_PIXLIST_DW_l[pixListNinc + (int32_T)k] -
        centroid_idx_0;
      common = (real_T)VisionModel_DWork.M_PIXLIST_DW_i[pixListMinc + (int32_T)k]
        - centroid_idx;
      xs += uxy * uxy;
      ys += common * common;
      xys += uxy * (-common);
    }

    centroid_idx = xs / (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i] +
      0.083333333333333329;
    centroid_idx_0 = ys / (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i] +
      0.083333333333333329;
    uxy = xys / (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
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
    Y7[c_i] = (real_T)VisionModel_DWork.NUM_PIX_DW_f[c_i] / (real_T)(maxr * j);
    pixListMinc += (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
    pixListNinc += (int32_T)VisionModel_DWork.NUM_PIX_DW_f[c_i];
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y0[loop] = VisionModel_DWork.F0_RTP_a;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y1[loop] = VisionModel_DWork.F1_RTP_m;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 2); loop < 200; loop++) {
    Y2[loop] = VisionModel_DWork.F2_RTP_m;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y3[loop] = VisionModel_DWork.F3_RTP_k;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y4[loop] = VisionModel_DWork.F4_RTP_j;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y5[loop] = VisionModel_DWork.F5_RTP_p;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y6[loop] = VisionModel_DWork.F6_RTP_k;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y7[loop] = VisionModel_DWork.F7_RTP_j;
  }
}

/* Function for Embedded MATLAB: '<S3>/Blob Extraction' */
static void VisionModel_refp1_round(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/* Model step function */
void VisionModel_step(void)
{
  int32_T blob_area[50];
  int32_T blob_bbox[200];
  real_T blob_count;
  int8_T blob_color[50];
  real_T ColorFilter[7];
  int32_T find_white;
  int32_T find_black;
  real_T L_white;
  real_T L_black;
  real_T color_areas[50];
  real_T positive_area;
  real_T maxL;
  real_T minL;
  boolean_T condition;
  int32_T current_color;
  int32_T condition_0;
  real_T ii;
  real_T jj;
  int32_T col;
  uint8_T c_i;
  int32_T TArea[50];
  real_T TCentroid[100];
  int32_T TBBox[200];
  real_T TMinorAxis[50];
  real_T TOrientation[50];
  real_T TEccent[50];
  real_T TExtent[50];
  uint8_T TNumBlobs;
  boolean_T exitg;
  boolean_T exitg_0;
  boolean_T guard;
  uint8_T rbinv[6];
  real_T tavgv[6];
  real_T vbinv[6];
  uint8_T rbinh[6];
  real_T ravgh[6];
  real_T tavgh[6];
  real_T vbinh[6];
  real_T u[2];
  int32_T idxROI;
  int32_T idxStart;
  real_T path_locations[6];
  real_T found[3];
  real_T value[3];
  real_T matr[9];
  int8_T b_j_index[3];
  real_T rho[200];
  real_T theta[200];
  int16_T i_index[200];
  uint8_T j_index[200];
  real_T theta_hold[200];
  real_T r;
  real_T c;
  boolean_T c_0;
  real_T rtb_Add1;
  real_T EdgeDetection_GV_SQUARED_DW[9];
  real_T EdgeDetection_GH_SQUARED_DW[9];
  real_T EdgeDetection_GRAD_SUM_DW[9];
  int32_T numElem;
  int32_T imgIdxLR;
  int32_T imgCol;
  real_T Resize2_LineBuffer_o[160];
  real_T Resize2_LineBuffer[120];
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  real_T rtb_theta_gate_idx;
  real_T rtb_path_headings_idx;
  real_T rtb_path_headings_idx_0;
  real_T rtb_path_headings_idx_1;
  real_T i_gate_idx;
  uint8_T tmp;
  int8_T b_j_index_0;
  static int8_T tmp_0[14] = { 0, 0, 0, 0, 0, 0, 0, 56, 30, -10, -13, 30, -40, 9
  };

  static int8_T tmp_1[14] = { 0, 0, 0, 0, 0, 0, 25, MAX_int8_T, MAX_int8_T, -18,
    70, -40, 50, -82 };

  for (i = 0; i < 19200; i++) {
    /* Product: '<S7>/Divide' incorporates:
     *  Inport: '<Root>/R_forward_in'
     *  Inport: '<Root>/Scale_Forward_R'
     */
    VisionModel_B.Divide5[i] = VisionModel_U.R_forward_in[i] *
      VisionModel_U.Scale_Forward_R;

    /* Product: '<S7>/Divide1' incorporates:
     *  Inport: '<Root>/G_forward_in'
     *  Inport: '<Root>/Scale_Forward_G'
     */
    VisionModel_B.Divide4[i] = VisionModel_U.G_forward_in[i] *
      VisionModel_U.Scale_Forward_G;

    /* Product: '<S7>/Divide2' incorporates:
     *  Inport: '<Root>/B_forward_in'
     *  Inport: '<Root>/Scale_Forward_B'
     */
    VisionModel_B.Divide3[i] = VisionModel_U.B_forward_in[i] *
      VisionModel_U.Scale_Forward_B;
  }

  /* S-Function (svipcolorconv): '<S7>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (VisionModel_B.Divide5[i] > VisionModel_B.Divide4[i]) {
      if (VisionModel_B.Divide4[i] < VisionModel_B.Divide3[i]) {
        ii = VisionModel_B.Divide4[i];
      } else {
        ii = VisionModel_B.Divide3[i];
      }

      if (VisionModel_B.Divide5[i] > VisionModel_B.Divide3[i]) {
        maxL = VisionModel_B.Divide5[i];
      } else {
        maxL = VisionModel_B.Divide3[i];
      }
    } else {
      if (VisionModel_B.Divide5[i] < VisionModel_B.Divide3[i]) {
        ii = VisionModel_B.Divide5[i];
      } else {
        ii = VisionModel_B.Divide3[i];
      }

      if (VisionModel_B.Divide4[i] > VisionModel_B.Divide3[i]) {
        maxL = VisionModel_B.Divide4[i];
      } else {
        maxL = VisionModel_B.Divide3[i];
      }
    }

    ii = maxL - ii;
    if (maxL != 0.0) {
      c = ii / maxL;
    } else {
      c = 0.0;
    }

    if (ii != 0.0) {
      if (VisionModel_B.Divide5[i] == maxL) {
        jj = (VisionModel_B.Divide4[i] - VisionModel_B.Divide3[i]) / ii;
      } else if (VisionModel_B.Divide4[i] == maxL) {
        jj = (VisionModel_B.Divide3[i] - VisionModel_B.Divide5[i]) / ii + 2.0;
      } else {
        jj = (VisionModel_B.Divide5[i] - VisionModel_B.Divide4[i]) / ii + 4.0;
      }

      jj /= 6.0;
      if (jj < 0.0) {
        jj++;
      }
    } else {
      jj = 0.0;
    }

    /* assign the results */
    VisionModel_B.ColorSpaceConversion1_o1_m[i] = jj;
    VisionModel_B.ColorSpaceConversion1_o2_e[i] = c;
    VisionModel_B.ColorSpaceConversion1_o3_jm[i] = maxL;
  }

  for (i = 0; i < 19200; i++) {
    /* Product: '<S7>/Divide3' incorporates:
     *  Inport: '<Root>/Scale_Forward_H'
     */
    VisionModel_B.Divide3[i] = VisionModel_B.ColorSpaceConversion1_o1_m[i] *
      VisionModel_U.Scale_Forward_H;

    /* Product: '<S7>/Divide4' incorporates:
     *  Inport: '<Root>/Scale_Forward_S'
     */
    VisionModel_B.Divide4[i] = VisionModel_B.ColorSpaceConversion1_o2_e[i] *
      VisionModel_U.Scale_Forward_S;

    /* Product: '<S7>/Divide5' incorporates:
     *  Inport: '<Root>/Scale_Forward_V'
     */
    VisionModel_B.Divide5[i] = VisionModel_B.ColorSpaceConversion1_o3_jm[i] *
      VisionModel_U.Scale_Forward_V;
  }

  /* S-Function (svipcolorconv): '<S7>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  jj = 0.0;
  c = 0.0;
  ii = 0.0;
  for (i = 0; i < 19200; i++) {
    maxL = 6.0 * VisionModel_B.Divide3[i];
    i_gate_idx = (real_T)(uint32_T)(maxL - 1.3322676295501878E-15);
    maxL -= i_gate_idx;
    minL = 1.0 - VisionModel_B.Divide4[i];
    r = 1.0 - VisionModel_B.Divide4[i] * maxL;
    maxL = VisionModel_B.Divide4[i] * maxL + minL;
    if (i_gate_idx == 0.0) {
      jj = 1.0;
      c = maxL;
      ii = minL;
    } else if (i_gate_idx == 1.0) {
      jj = r;
      c = 1.0;
      ii = minL;
    } else if (i_gate_idx == 2.0) {
      jj = minL;
      c = 1.0;
      ii = maxL;
    } else if (i_gate_idx == 3.0) {
      jj = minL;
      c = r;
      ii = 1.0;
    } else if (i_gate_idx == 4.0) {
      jj = maxL;
      c = minL;
      ii = 1.0;
    } else {
      if (i_gate_idx == 5.0) {
        jj = 1.0;
        c = minL;
        ii = r;
      }
    }

    if (jj > c) {
      maxL = jj;
    } else {
      maxL = c;
    }

    if (!(maxL > ii)) {
      maxL = ii;
    }

    maxL = VisionModel_B.Divide5[i] / maxL;

    /* assign the results */
    VisionModel_B.ColorSpaceConversion2_o1[i] = maxL * jj;
    VisionModel_B.ColorSpaceConversion2_o2[i] = maxL * c;
    VisionModel_B.ColorSpaceConversion2_o3[i] = maxL * ii;
  }

  /* Outputs for atomic SubSystem: '<Root>/ColorSelect' */

  /* If: '<S5>/If3' incorporates:
   *  ActionPort: '<S39>/Action Port'
   *  ActionPort: '<S40>/Action Port'
   *  ActionPort: '<S41>/Action Port'
   *  ActionPort: '<S42>/Action Port'
   *  ActionPort: '<S43>/Action Port'
   *  ActionPort: '<S44>/Action Port'
   *  Inport: '<Root>/ModeSelect'
   *  SubSystem: '<S5>/L_detector'
   *  SubSystem: '<S5>/buoy_detector'
   *  SubSystem: '<S5>/drop_mech'
   *  SubSystem: '<S5>/path_detector'
   *  SubSystem: '<S5>/torpedo'
   *  SubSystem: '<S5>/validation_gate'
   */
  if (VisionModel_U.ModeSelect == 1.0) {
    VisionModel_validation_gate(&VisionModel_B.validation_gate_p,
      (rtP_validation_gate_VisionModel *) &VisionModel_P.validation_gate_p);
  } else if (VisionModel_U.ModeSelect == 2.0) {
    VisionModel_validation_gate(&VisionModel_B.path_detector_c,
      (rtP_validation_gate_VisionModel *) &VisionModel_P.path_detector_c);
  } else if (VisionModel_U.ModeSelect == 3.0) {
    VisionModel_validation_gate(&VisionModel_B.buoy_detector_h,
      (rtP_validation_gate_VisionModel *) &VisionModel_P.buoy_detector_h);
  } else if (VisionModel_U.ModeSelect == 4.0) {
    VisionModel_validation_gate(&VisionModel_B.torpedo_l,
      (rtP_validation_gate_VisionModel *) &VisionModel_P.torpedo_l);
  } else if (VisionModel_U.ModeSelect == 5.0) {
    VisionModel_validation_gate(&VisionModel_B.L_detector_i,
      (rtP_validation_gate_VisionModel *) &VisionModel_P.L_detector_i);
  } else {
    if (VisionModel_U.ModeSelect == 6.0) {
      VisionModel_validation_gate(&VisionModel_B.drop_mech_b,
        (rtP_validation_gate_VisionModel *) &VisionModel_P.drop_mech_b);
    }
  }

  /* Sum: '<S5>/Add1' */
  rtb_Add1 = ((((VisionModel_B.validation_gate_p.OutputSegmentedImage1 +
                 VisionModel_B.path_detector_c.OutputSegmentedImage1) +
                VisionModel_B.buoy_detector_h.OutputSegmentedImage1) +
               VisionModel_B.torpedo_l.OutputSegmentedImage1) +
              VisionModel_B.L_detector_i.OutputSegmentedImage1) +
    VisionModel_B.drop_mech_b.OutputSegmentedImage1;

  /* Sum: '<S5>/Add22' */
  for (i = 0; i < 7; i++) {
    VisionModel_B.Add22[i] = ((((VisionModel_B.validation_gate_p.ColorFilter1[i]
      + VisionModel_B.path_detector_c.ColorFilter1[i]) +
      VisionModel_B.buoy_detector_h.ColorFilter1[i]) +
      VisionModel_B.torpedo_l.ColorFilter1[i]) +
      VisionModel_B.L_detector_i.ColorFilter1[i]) +
      VisionModel_B.drop_mech_b.ColorFilter1[i];
  }

  /* end of Outputs for SubSystem: '<Root>/ColorSelect' */

  /* Embedded MATLAB: '<Root>/make_color_range' incorporates:
   *  Inport: '<Root>/black_al'
   *  Inport: '<Root>/black_au'
   *  Inport: '<Root>/black_bl'
   *  Inport: '<Root>/black_bu'
   *  Inport: '<Root>/blue_al'
   *  Inport: '<Root>/blue_au'
   *  Inport: '<Root>/blue_bl'
   *  Inport: '<Root>/blue_bu'
   *  Inport: '<Root>/green_al'
   *  Inport: '<Root>/green_au'
   *  Inport: '<Root>/green_bl'
   *  Inport: '<Root>/green_bu'
   *  Inport: '<Root>/orange_al'
   *  Inport: '<Root>/orange_au'
   *  Inport: '<Root>/orange_bl'
   *  Inport: '<Root>/orange_bu'
   *  Inport: '<Root>/red_al'
   *  Inport: '<Root>/red_au'
   *  Inport: '<Root>/red_bl'
   *  Inport: '<Root>/red_bu'
   *  Inport: '<Root>/white_al'
   *  Inport: '<Root>/white_au'
   *  Inport: '<Root>/white_bl'
   *  Inport: '<Root>/white_bu'
   *  Inport: '<Root>/yellow_al'
   *  Inport: '<Root>/yellow_au'
   *  Inport: '<Root>/yellow_bl'
   *  Inport: '<Root>/yellow_bu'
   */
  /* Embedded MATLAB Function 'make_color_range': '<S11>:1' */
  /*  This function forms two compact matrices which pass all color range */
  /*    information to other functions in the model */
  /*  Initialize */
  /* '<S11>:1:8' */
  /* '<S11>:1:9' */
  for (i = 0; i < 14; i++) {
    VisionModel_B.a_range[i] = 0.0;
    VisionModel_B.b_range[i] = 0.0;
  }

  /*  Assign values to color range matrices */
  /* '<S11>:1:13' */
  VisionModel_B.a_range[0] = VisionModel_U.white_al;

  /* '<S11>:1:14' */
  VisionModel_B.a_range[1] = VisionModel_U.white_au;

  /* '<S11>:1:15' */
  VisionModel_B.b_range[0] = VisionModel_U.white_bl;

  /* '<S11>:1:16' */
  VisionModel_B.b_range[1] = VisionModel_U.white_bu;

  /* '<S11>:1:18' */
  VisionModel_B.a_range[2] = VisionModel_U.black_al;

  /* '<S11>:1:19' */
  VisionModel_B.a_range[3] = VisionModel_U.black_au;

  /* '<S11>:1:20' */
  VisionModel_B.b_range[2] = VisionModel_U.black_bl;

  /* '<S11>:1:21' */
  VisionModel_B.b_range[3] = VisionModel_U.black_bu;

  /* '<S11>:1:23' */
  VisionModel_B.a_range[4] = VisionModel_U.blue_al;

  /* '<S11>:1:24' */
  VisionModel_B.a_range[5] = VisionModel_U.blue_au;

  /* '<S11>:1:25' */
  VisionModel_B.b_range[4] = VisionModel_U.blue_bl;

  /* '<S11>:1:26' */
  VisionModel_B.b_range[5] = VisionModel_U.blue_bu;

  /* '<S11>:1:28' */
  VisionModel_B.a_range[6] = VisionModel_U.red_al;

  /* '<S11>:1:29' */
  VisionModel_B.a_range[7] = VisionModel_U.red_au;

  /* '<S11>:1:30' */
  VisionModel_B.b_range[6] = VisionModel_U.red_bl;

  /* '<S11>:1:31' */
  VisionModel_B.b_range[7] = VisionModel_U.red_bu;

  /* '<S11>:1:33' */
  VisionModel_B.a_range[8] = VisionModel_U.orange_al;

  /* '<S11>:1:34' */
  VisionModel_B.a_range[9] = VisionModel_U.orange_au;

  /* '<S11>:1:35' */
  VisionModel_B.b_range[8] = VisionModel_U.orange_bl;

  /* '<S11>:1:36' */
  VisionModel_B.b_range[9] = VisionModel_U.orange_bu;

  /* '<S11>:1:38' */
  VisionModel_B.a_range[10] = VisionModel_U.yellow_al;

  /* '<S11>:1:39' */
  VisionModel_B.a_range[11] = VisionModel_U.yellow_au;

  /* '<S11>:1:40' */
  VisionModel_B.b_range[10] = VisionModel_U.yellow_bl;

  /* '<S11>:1:41' */
  VisionModel_B.b_range[11] = VisionModel_U.yellow_bu;

  /* '<S11>:1:43' */
  VisionModel_B.a_range[12] = VisionModel_U.green_al;

  /* '<S11>:1:44' */
  VisionModel_B.a_range[13] = VisionModel_U.green_au;

  /* '<S11>:1:45' */
  VisionModel_B.b_range[12] = VisionModel_U.green_bl;

  /* '<S11>:1:46' */
  VisionModel_B.b_range[13] = VisionModel_U.green_bu;
  for (i = 0; i < 19200; i++) {
    /* Product: '<S6>/Divide' incorporates:
     *  Inport: '<Root>/R_down_in'
     *  Inport: '<Root>/Scale_Down_R'
     */
    VisionModel_B.Divide5[i] = VisionModel_U.R_down_in[i] *
      VisionModel_U.Scale_Down_R;

    /* Product: '<S6>/Divide1' incorporates:
     *  Inport: '<Root>/G_down_in'
     *  Inport: '<Root>/Scale_Down_G'
     */
    VisionModel_B.Divide4[i] = VisionModel_U.G_down_in[i] *
      VisionModel_U.Scale_Down_G;

    /* Product: '<S6>/Divide2' incorporates:
     *  Inport: '<Root>/B_down_in'
     *  Inport: '<Root>/Scale_Down_B'
     */
    VisionModel_B.Divide3[i] = VisionModel_U.B_down_in[i] *
      VisionModel_U.Scale_Down_B;
  }

  /* S-Function (svipcolorconv): '<S6>/Color Space  Conversion3' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (VisionModel_B.Divide5[i] > VisionModel_B.Divide4[i]) {
      if (VisionModel_B.Divide4[i] < VisionModel_B.Divide3[i]) {
        ii = VisionModel_B.Divide4[i];
      } else {
        ii = VisionModel_B.Divide3[i];
      }

      if (VisionModel_B.Divide5[i] > VisionModel_B.Divide3[i]) {
        maxL = VisionModel_B.Divide5[i];
      } else {
        maxL = VisionModel_B.Divide3[i];
      }
    } else {
      if (VisionModel_B.Divide5[i] < VisionModel_B.Divide3[i]) {
        ii = VisionModel_B.Divide5[i];
      } else {
        ii = VisionModel_B.Divide3[i];
      }

      if (VisionModel_B.Divide4[i] > VisionModel_B.Divide3[i]) {
        maxL = VisionModel_B.Divide4[i];
      } else {
        maxL = VisionModel_B.Divide3[i];
      }
    }

    ii = maxL - ii;
    if (maxL != 0.0) {
      c = ii / maxL;
    } else {
      c = 0.0;
    }

    if (ii != 0.0) {
      if (VisionModel_B.Divide5[i] == maxL) {
        jj = (VisionModel_B.Divide4[i] - VisionModel_B.Divide3[i]) / ii;
      } else if (VisionModel_B.Divide4[i] == maxL) {
        jj = (VisionModel_B.Divide3[i] - VisionModel_B.Divide5[i]) / ii + 2.0;
      } else {
        jj = (VisionModel_B.Divide5[i] - VisionModel_B.Divide4[i]) / ii + 4.0;
      }

      jj /= 6.0;
      if (jj < 0.0) {
        jj++;
      }
    } else {
      jj = 0.0;
    }

    /* assign the results */
    VisionModel_B.ColorSpaceConversion3_o1[i] = jj;
    VisionModel_B.ColorSpaceConversion3_o2[i] = c;
    VisionModel_B.ColorSpaceConversion3_o3[i] = maxL;
  }

  for (i = 0; i < 19200; i++) {
    /* Product: '<S6>/Divide3' incorporates:
     *  Inport: '<Root>/Scale_Down_H'
     */
    VisionModel_B.Divide3[i] = VisionModel_B.ColorSpaceConversion3_o1[i] *
      VisionModel_U.Scale_Down_H;

    /* Product: '<S6>/Divide4' incorporates:
     *  Inport: '<Root>/Scale_Down_S'
     */
    VisionModel_B.Divide4[i] = VisionModel_B.ColorSpaceConversion3_o2[i] *
      VisionModel_U.Scale_Down_S;

    /* Product: '<S6>/Divide5' incorporates:
     *  Inport: '<Root>/Scale_Down_V'
     */
    VisionModel_B.Divide5[i] = VisionModel_B.ColorSpaceConversion3_o3[i] *
      VisionModel_U.Scale_Down_V;
  }

  /* S-Function (svipcolorconv): '<S6>/Color Space  Conversion4' */
  /* temporary variables for in-place operation */
  jj = 0.0;
  c = 0.0;
  ii = 0.0;
  for (i = 0; i < 19200; i++) {
    maxL = 6.0 * VisionModel_B.Divide3[i];
    i_gate_idx = (real_T)(uint32_T)(maxL - 1.3322676295501878E-15);
    maxL -= i_gate_idx;
    minL = 1.0 - VisionModel_B.Divide4[i];
    r = 1.0 - VisionModel_B.Divide4[i] * maxL;
    maxL = VisionModel_B.Divide4[i] * maxL + minL;
    if (i_gate_idx == 0.0) {
      jj = 1.0;
      c = maxL;
      ii = minL;
    } else if (i_gate_idx == 1.0) {
      jj = r;
      c = 1.0;
      ii = minL;
    } else if (i_gate_idx == 2.0) {
      jj = minL;
      c = 1.0;
      ii = maxL;
    } else if (i_gate_idx == 3.0) {
      jj = minL;
      c = r;
      ii = 1.0;
    } else if (i_gate_idx == 4.0) {
      jj = maxL;
      c = minL;
      ii = 1.0;
    } else {
      if (i_gate_idx == 5.0) {
        jj = 1.0;
        c = minL;
        ii = r;
      }
    }

    if (jj > c) {
      maxL = jj;
    } else {
      maxL = c;
    }

    if (!(maxL > ii)) {
      maxL = ii;
    }

    maxL = VisionModel_B.Divide5[i] / maxL;

    /* assign the results */
    VisionModel_B.ColorSpaceConversion4_o1[i] = maxL * jj;
    VisionModel_B.ColorSpaceConversion4_o2[i] = maxL * c;
    VisionModel_B.ColorSpaceConversion4_o3[i] = maxL * ii;
  }

  /* Embedded MATLAB: '<Root>/Blob Extraction2' */
  /* Embedded MATLAB Function 'Blob Extraction2': '<S2>:1' */
  /*  7-15-11 */
  /*  This function exists solely to solve an untraceable parsing error in the */
  /*    Simulink compiler. This error has to do with having two Blob Analysis */
  /*    function blocks in the same model. */
  /* '<S2>:1:8' */
  for (i = 0; i < 7; i++) {
    VisionModel_B.ColorFilter_out[i] = VisionModel_B.Add22[i];
  }

  /* ColorFilter_out = [ColorFilter_in, a_range', b_range']; */

  /* If: '<Root>/If1' incorporates:
   *  ActionPort: '<S3>/Action Port'
   *  ActionPort: '<S4>/Action Port'
   *  Inport: '<Root>/ModeSelect'
   *  SubSystem: '<Root>/Blob_Analysis'
   *  SubSystem: '<Root>/Blob_Analysis1'
   */
  if ((VisionModel_U.ModeSelect == 1.0) || (VisionModel_U.ModeSelect == 3.0) ||
      (VisionModel_U.ModeSelect == 4.0) || (VisionModel_U.ModeSelect == 5.0)) {
    /* Embedded MATLAB: '<S18>/Low Pass Filter' */
    VisionModel_LowPassFilter(VisionModel_B.ColorSpaceConversion2_o1,
      &VisionModel_B.sf_LowPassFilter);

    /* Embedded MATLAB: '<S18>/Low Pass Filter1' */
    VisionModel_LowPassFilter(VisionModel_B.ColorSpaceConversion2_o2,
      &VisionModel_B.sf_LowPassFilter1);

    /* Embedded MATLAB: '<S18>/Low Pass Filter2' */
    VisionModel_LowPassFilter(VisionModel_B.ColorSpaceConversion2_o3,
      &VisionModel_B.sf_LowPassFilter2);

    /* S-Function (svipcolorconv): '<S16>/Color Space  Conversion1' */
    /* temporary variables for in-place operation */
    /* Convert to XYZ */
    /* temporary variables for in-place operation */
    for (i = 0; i < 19200; i++) {
      /* First, linearize (de-gamma) the RGB values; the operation is */
      /* equivalent to running the gamma correction block with break */
      /* point of 0.00304 and gamma of 2.4; it's built into this */
      /* conversion for convenience */
      if (VisionModel_B.sf_LowPassFilter.Iout[i] <= 0.039286085583733095) {
        minL = VisionModel_B.sf_LowPassFilter.Iout[i] / 12.923054468333255;
      } else {
        minL = (VisionModel_B.sf_LowPassFilter.Iout[i] + 0.055000519817226347) /
          1.0550005198172263;
        minL = rt_pow_snf(minL, 2.4);
      }

      if (VisionModel_B.sf_LowPassFilter1.Iout[i] <= 0.039286085583733095) {
        maxL = VisionModel_B.sf_LowPassFilter1.Iout[i] / 12.923054468333255;
      } else {
        maxL = (VisionModel_B.sf_LowPassFilter1.Iout[i] + 0.055000519817226347) /
          1.0550005198172263;
        maxL = rt_pow_snf(maxL, 2.4);
      }

      if (VisionModel_B.sf_LowPassFilter2.Iout[i] <= 0.039286085583733095) {
        ii = VisionModel_B.sf_LowPassFilter2.Iout[i] / 12.923054468333255;
      } else {
        ii = (VisionModel_B.sf_LowPassFilter2.Iout[i] + 0.055000519817226347) /
          1.0550005198172263;
        ii = rt_pow_snf(ii, 2.4);
      }

      /* The coefficients for this conversion were derived from ITU-R */
      /* BT.709 reference primaries for sRGB and CIE standard illuminant */
      /* D65, 2 degree observer */
      jj = (0.41239079926596 * minL + 0.35758433938388 * maxL) +
        0.18048078840183 * ii;
      c = (0.21263900587151 * minL + 0.71516867876776 * maxL) + 0.07219231536073
        * ii;
      ii = (0.01933081871559 * minL + 0.11919477979463 * maxL) +
        0.95053215224966 * ii;

      /* Make sure that the output is in [0..1] range; clip if necessary */
      if (jj > 1.0) {
        jj = 1.0;
      } else {
        if (jj < 0.0) {
          jj = 0.0;
        }
      }

      if (c > 1.0) {
        c = 1.0;
      } else {
        if (c < 0.0) {
          c = 0.0;
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
      VisionModel_B.ColorSpaceConversion1_o1_i[i] = jj;
      VisionModel_B.ColorSpaceConversion1_o2_g[i] = c;
      VisionModel_B.ColorSpaceConversion1_o3_j[i] = ii;
    }

    /* Convert from XYZ to L*a*b* */
    for (i = 0; i < 19200; i++) {
      ii = VisionModel_B.ColorSpaceConversion1_o1_i[i] / 0.9641986557609;
      jj = VisionModel_B.ColorSpaceConversion1_o3_j[i] / 0.82511648322104;

      /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
      if (ii > 0.0088564516790356311) {
        minL = rt_pow_snf(ii, 0.33333333333333331);
      } else {
        minL = 7.7870370370370372 * ii + 0.13793103448275862;
      }

      if (VisionModel_B.ColorSpaceConversion1_o2_g[i] > 0.0088564516790356311) {
        maxL = rt_pow_snf(VisionModel_B.ColorSpaceConversion1_o2_g[i],
                          0.33333333333333331);
      } else {
        maxL = 7.7870370370370372 * VisionModel_B.ColorSpaceConversion1_o2_g[i]
          + 0.13793103448275862;
      }

      if (jj > 0.0088564516790356311) {
        ii = rt_pow_snf(jj, 0.33333333333333331);
      } else {
        ii = 7.7870370370370372 * jj + 0.13793103448275862;
      }

      /* assign the results */
      VisionModel_B.ColorSpaceConversion1_o1_i[i] = 116.0 * maxL - 16.0;
      VisionModel_B.ColorSpaceConversion1_o2_g[i] = (minL - maxL) * 500.0;
      VisionModel_B.ColorSpaceConversion1_o3_j[i] = (maxL - ii) * 200.0;
    }

    /* S-Function (svipresize): '<S25>/Resize' */
    /* use pre-computed weights and index table to perform interpolation */
    condition_0 = 0;
    for (col = 0; col < 160; col++) {
      find_black = col;
      for (numElem = 0; numElem < 80; numElem++) {
        find_white = numElem + 80;
        ii =
          VisionModel_B.ColorSpaceConversion1_o1_i[VisionModel_ConstP.pooled12[numElem]
          * 160 + col] * VisionModel_ConstP.pooled4[numElem] +
          VisionModel_B.ColorSpaceConversion1_o1_i[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        find_white += 80;
        ii +=
          VisionModel_B.ColorSpaceConversion1_o1_i[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        VisionModel_DWork.Resize_IntBuffer_l[find_black] = ii;
        find_black += 160;
      }
    }

    for (numElem = 0; numElem < 80; numElem++) {
      memcpy((void *)&Resize2_LineBuffer_o[0], (void *)
             (&VisionModel_DWork.Resize_IntBuffer_l[numElem * 160]), 160U *
             sizeof(real_T));
      for (col = 0; col < 60; col++) {
        find_white = col;
        ii = 0.0;
        for (imgCol = 0; imgCol < 6; imgCol++) {
          ii += Resize2_LineBuffer_o[VisionModel_ConstP.pooled11[find_white]] *
            VisionModel_ConstP.pooled3[find_white];
          find_white += 60;
        }

        VisionModel_B.Resize_e[condition_0] = ii;
        condition_0++;
      }
    }

    /* S-Function (svipresize): '<S25>/Resize1' */
    /* use pre-computed weights and index table to perform interpolation */
    condition_0 = 0;
    for (col = 0; col < 160; col++) {
      find_black = col;
      for (numElem = 0; numElem < 80; numElem++) {
        find_white = numElem + 80;
        ii =
          VisionModel_B.ColorSpaceConversion1_o2_g[VisionModel_ConstP.pooled12[numElem]
          * 160 + col] * VisionModel_ConstP.pooled4[numElem] +
          VisionModel_B.ColorSpaceConversion1_o2_g[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        find_white += 80;
        ii +=
          VisionModel_B.ColorSpaceConversion1_o2_g[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        VisionModel_DWork.Resize1_IntBuffer_j[find_black] = ii;
        find_black += 160;
      }
    }

    for (numElem = 0; numElem < 80; numElem++) {
      memcpy((void *)&Resize2_LineBuffer_o[0], (void *)
             (&VisionModel_DWork.Resize1_IntBuffer_j[numElem * 160]), 160U *
             sizeof(real_T));
      for (col = 0; col < 60; col++) {
        find_white = col;
        ii = 0.0;
        for (imgCol = 0; imgCol < 6; imgCol++) {
          ii += Resize2_LineBuffer_o[VisionModel_ConstP.pooled11[find_white]] *
            VisionModel_ConstP.pooled3[find_white];
          find_white += 60;
        }

        VisionModel_B.Resize1_l[condition_0] = ii;
        condition_0++;
      }
    }

    /* S-Function (svipresize): '<S25>/Resize2' */
    /* use pre-computed weights and index table to perform interpolation */
    condition_0 = 0;
    for (col = 0; col < 160; col++) {
      find_black = col;
      for (numElem = 0; numElem < 80; numElem++) {
        find_white = numElem + 80;
        ii =
          VisionModel_B.ColorSpaceConversion1_o3_j[VisionModel_ConstP.pooled12[numElem]
          * 160 + col] * VisionModel_ConstP.pooled4[numElem] +
          VisionModel_B.ColorSpaceConversion1_o3_j[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        find_white += 80;
        ii +=
          VisionModel_B.ColorSpaceConversion1_o3_j[VisionModel_ConstP.pooled12[find_white]
          * 160 + col] * VisionModel_ConstP.pooled4[find_white];
        VisionModel_DWork.Resize2_IntBuffer_p[find_black] = ii;
        find_black += 160;
      }
    }

    for (numElem = 0; numElem < 80; numElem++) {
      memcpy((void *)&Resize2_LineBuffer_o[0], (void *)
             (&VisionModel_DWork.Resize2_IntBuffer_p[numElem * 160]), 160U *
             sizeof(real_T));
      for (col = 0; col < 60; col++) {
        find_white = col;
        ii = 0.0;
        for (imgCol = 0; imgCol < 6; imgCol++) {
          ii += Resize2_LineBuffer_o[VisionModel_ConstP.pooled11[find_white]] *
            VisionModel_ConstP.pooled3[find_white];
          find_white += 60;
        }

        VisionModel_B.Resize2_l[condition_0] = ii;
        condition_0++;
      }
    }

    /* Embedded MATLAB: '<S19>/Reference Color Selection' */
    VisionM_ReferenceColorSelection(VisionModel_B.Resize_e,
      VisionModel_B.Resize1_l, VisionModel_B.Resize2_l,
      VisionModel_P.Iter_Segment_Thresh_Value,
      &VisionModel_B.sf_ReferenceColorSelection);

    /* Embedded MATLAB: '<S19>/LabSegmentation' */
    /* Embedded MATLAB Function 'Blob_Analysis/IterativeSegmentation/Segmentation/LabSegmentation': '<S23>:1' */
    /*  This function generates the label matrix */
    /* '<S23>:1:5' */
    memset((void *)(&VisionModel_B.LabelMatrix_n[0]), 0, 19200U * sizeof(real_T));

    /* '<S23>:1:7' */
    for (i = 0; i < 160; i++) {
      /* '<S23>:1:7' */
      /* '<S23>:1:8' */
      for (numElem = 0; numElem < 120; numElem++) {
        /* '<S23>:1:8' */
        /* '<S23>:1:9' */
        ii = 1000.0;

        /* '<S23>:1:10' */
        jj = 1.0;

        /* '<S23>:1:11' */
        for (i_gate_idx = 1.0; i_gate_idx <=
             VisionModel_B.sf_ReferenceColorSelection.num_colors; i_gate_idx++)
        {
          /* '<S23>:1:11' */
          /* '<S23>:1:12' */
          minL = sqrt((rt_pow_snf
                       (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                        [(int32_T)i_gate_idx - 1] -
                        VisionModel_B.ColorSpaceConversion1_o1_i[160 * numElem +
                        i], 2.0) + rt_pow_snf
                       (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                        [(int32_T)i_gate_idx + 49] -
                        VisionModel_B.ColorSpaceConversion1_o2_g[160 * numElem +
                        i], 2.0)) + rt_pow_snf
                      (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                       [(int32_T)i_gate_idx + 99] -
                       VisionModel_B.ColorSpaceConversion1_o3_j[160 * numElem +
                       i], 2.0));
          if (minL < ii) {
            /* '<S23>:1:13' */
            /* '<S23>:1:14' */
            ii = minL;

            /* '<S23>:1:15' */
            jj = i_gate_idx;
          }
        }

        /* '<S23>:1:18' */
        VisionModel_B.LabelMatrix_n[i + 160 * numElem] = jj;
      }
    }

    /* Embedded MATLAB: '<S3>/Blob Extraction' */
    c = VisionModel_B.sf_ReferenceColorSelection.num_colors;

    /* Embedded MATLAB Function 'Blob_Analysis/Blob Extraction': '<S15>:1' */
    /*  This function calculates blob information for each color component after */
    /*    iterative segmentation */
    /*  Output */
    /*    blob_color = 1xN vector of color indices (global color scheme) */
    /*  Initialize */
    /* '<S15>:1:11' */
    /* '<S15>:1:16' */
    /* '<S15>:1:17' */
    for (i = 0; i < 19200; i++) {
      VisionModel_B.LogicMatrix[i] = FALSE;
      VisionModel_B.bw_image_m[i] = 0;
    }

    /* '<S15>:1:19' */
    memset((void *)(&VisionModel_B.blob_hues_g[0]), 0, 150U * sizeof(real_T));

    /* '<S15>:1:20' */
    for (i = 0; i < 50; i++) {
      blob_area[i] = -1;
    }

    /* '<S15>:1:21' */
    memset((void *)&blob_bbox[0], 0, 200U * sizeof(int32_T));

    /* '<S15>:1:22' */
    /* '<S15>:1:23' */
    for (i = 0; i < 50; i++) {
      VisionModel_B.blob_major_axis_e[i] = 0.0;
      VisionModel_B.blob_minor_axis_i[i] = 0.0;
    }

    /* '<S15>:1:24' */
    memset((void *)(&VisionModel_B.blob_centroids_m[0]), 0, 100U * sizeof(real_T));

    /* '<S15>:1:25' */
    /* '<S15>:1:26' */
    /* '<S15>:1:27' */
    /* '<S15>:1:28' */
    blob_count = 0.0;

    /* '<S15>:1:30' */
    /* '<S15>:1:33' */
    /* '<S15>:1:35' */
    /*  Determine L_white and L_black as needed */
    /* '<S15>:1:39' */
    find_white = 0;

    /* '<S15>:1:40' */
    find_black = 0;

    /* '<S15>:1:41' */
    L_white = 101.0;

    /* '<S15>:1:42' */
    L_black = -1.0;

    /* '<S15>:1:43' */
    for (i = 0; i < 50; i++) {
      VisionModel_B.blob_eccentricity_h[i] = 0.0;
      VisionModel_B.blob_extent_k[i] = 0.0;
      VisionModel_B.blob_orientation_g[i] = 0.0;
      blob_color[i] = 0;
      color_areas[i] = 0.0;
    }

    if (VisionModel_B.Add22[0] + VisionModel_B.Add22[1] > 0.0) {
      /* '<S15>:1:45' */
      /* '<S15>:1:46' */
      for (imgIdxLR = 0; imgIdxLR < 160; imgIdxLR++) {
        /* '<S15>:1:46' */
        /* '<S15>:1:47' */
        for (col = 0; col < 120; col++) {
          /* '<S15>:1:47' */
          /* '<S15>:1:48' */
          color_areas[(int32_T)VisionModel_B.LabelMatrix_n[imgIdxLR + 160 * col]
            - 1] = color_areas[(int32_T)VisionModel_B.LabelMatrix_n[160 * col +
            imgIdxLR] - 1] + 1.0;
        }
      }
    }

    if (VisionModel_B.Add22[0] == 1.0) {
      /* '<S15>:1:53' */
      /*  Determine the brightest colors, but allow a maximum area */
      /*    ratio of the image to be "white" */
      /* '<S15>:1:57' */
      find_white = 1;

      /* '<S15>:1:59' */
      positive_area = 0.0;

      /* '<S15>:1:60' */
      r = 1.0;
      condition = FALSE;
      while (((uint32_T)condition == 0U) && (r <=
              VisionModel_B.sf_ReferenceColorSelection.num_colors)) {
        /* '<S15>:1:60' */
        /* '<S15>:1:62' */
        maxL = -1.0;

        /* '<S15>:1:63' */
        ii = -1.0;

        /* '<S15>:1:64' */
        for (i_gate_idx = 1.0; i_gate_idx <=
             VisionModel_B.sf_ReferenceColorSelection.num_colors; i_gate_idx++)
        {
          /* '<S15>:1:64' */
          /* '<S15>:1:65' */
          if ((VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
               i_gate_idx - 1] > maxL) &&
              (VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
               i_gate_idx - 1] < L_white)) {
            /* '<S15>:1:66' */
            /* '<S15>:1:67' */
            maxL = VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
              i_gate_idx - 1];

            /* '<S15>:1:68' */
            ii = i_gate_idx;
          }
        }

        /* '<S15>:1:72' */
        positive_area += color_areas[(int32_T)ii - 1];
        if ((positive_area / 19200.0 >= 0.1) && (r > 1.0)) {
          /* '<S15>:1:73' */
          condition = TRUE;
        } else {
          /* '<S15>:1:77' */
          L_white = maxL;
          r++;
        }
      }
    }

    if (VisionModel_B.Add22[1] == 1.0) {
      /* '<S15>:1:82' */
      /*  Determine the darkest colors, but allow a maximum area */
      /*    ratio of the image to be "black" */
      /* '<S15>:1:86' */
      find_black = 1;

      /* '<S15>:1:88' */
      for (condition_0 = 0; condition_0 < 160; condition_0++) {
        /* '<S15>:1:88' */
        /* '<S15>:1:89' */
        for (current_color = 0; current_color < 120; current_color++) {
          /* '<S15>:1:89' */
          /* '<S15>:1:90' */
          color_areas[(int32_T)VisionModel_B.LabelMatrix_n[condition_0 + 160 *
            current_color] - 1] = color_areas[(int32_T)
            VisionModel_B.LabelMatrix_n[160 * current_color + condition_0] - 1]
            + 1.0;
        }
      }

      /* '<S15>:1:94' */
      positive_area = 0.0;

      /* '<S15>:1:95' */
      maxL = 1.0;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (maxL <=
              VisionModel_B.sf_ReferenceColorSelection.num_colors)) {
        /* '<S15>:1:95' */
        /* '<S15>:1:97' */
        minL = 101.0;

        /* '<S15>:1:98' */
        ii = -1.0;

        /* '<S15>:1:99' */
        for (jj = 1.0; jj <= VisionModel_B.sf_ReferenceColorSelection.num_colors;
             jj++) {
          /* '<S15>:1:99' */
          /* '<S15>:1:100' */
          if ((VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)jj -
               1] < minL) &&
              (VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)jj -
               1] > L_black)) {
            /* '<S15>:1:101' */
            /* '<S15>:1:102' */
            minL = VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
              jj - 1];

            /* '<S15>:1:103' */
            ii = jj;
          }
        }

        /* '<S15>:1:107' */
        positive_area += color_areas[(int32_T)ii - 1];
        if ((positive_area / 19200.0 >= 0.1) && (maxL > 1.0)) {
          /* '<S15>:1:108' */
          exitg_0 = TRUE;
        } else {
          /* '<S15>:1:112' */
          L_black = minL;
          maxL++;
        }
      }
    }

    /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
    /*  identified blob */
    /*  Calculate geometric information about the blobs */
    /*  */
    /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
    /*    locations for which color values are k, and zeros everywhere else */
    /*  */
    /*  Explanation */
    /*    condition1 == 1 causes the k'th color to be analyzed by blob analysis, */
    /*      as well as be included in the black-and-white image */
    /*    condition1 == 0 disallows both of these items and simply ignores color */
    /*      k */
    /*    condition0 == 1 ensures that condition1 is true for all k */
    /*    condition0 == 0 enforces a filter which allows only the colors */
    /*      specified in the ColorFilter vector */
    /* '<S15>:1:143' */
    condition = (VisionModel_sum(&VisionModel_B.Add22[0]) == 0.0);

    /* '<S15>:1:144' */
    current_color = 0;

    /* '<S15>:1:145' */
    for (maxL = 1.0; maxL <= c; maxL++) {
      /* '<S15>:1:145' */
      /*  Decide whether or not to perform blob analysis */
      /* '<S15>:1:148' */
      condition_0 = 0;
      if (condition) {
        /* '<S15>:1:149' */
        /* '<S15>:1:150' */
        condition_0 = 1;
      } else {
        /* '<S15>:1:152' */
        /* '<S15>:1:153' */
        /* '<S15>:1:154' */
        i = 1;
        exitg = FALSE;
        while (((uint32_T)exitg == 0U) && (i <= 7)) {
          /* '<S15>:1:154' */
          /*  Skip colors that have not been specified */
          guard = FALSE;
          if (VisionModel_B.Add22[i - 1] == 0.0) {
            /* '<S15>:1:157' */
            guard = TRUE;
          } else if ((find_white == 1) &&
                     (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL - 1] >= L_white)) {
            /* '<S15>:1:161' */
            /*  Handle "white" differently than other colors */
            /* '<S15>:1:162' */
            condition_0 = 1;

            /* '<S15>:1:163' */
            current_color = 1;
            exitg = TRUE;
          } else if ((find_black == 1) &&
                     (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL - 1] <= L_black)) {
            /* '<S15>:1:165' */
            /*  Handle "black" differently than other colors */
            /* '<S15>:1:166' */
            condition_0 = 1;

            /* '<S15>:1:167' */
            current_color = 2;
            exitg = TRUE;
          } else if ((VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL + 49] >= VisionModel_B.a_range[((i - 1) <<
                       1)]) &&
                     (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL + 49] <= VisionModel_B.a_range[((i - 1) <<
                       1) + 1]) &&
                     (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL + 99] >= VisionModel_B.b_range[((i - 1) <<
                       1)]) &&
                     (VisionModel_B.sf_ReferenceColorSelection.ref_colors
                      [(int32_T)maxL + 99] <= VisionModel_B.b_range[((i - 1) <<
                       1) + 1])) {
            /* '<S15>:1:169' */
            /* '<S15>:1:170' */
            condition_0 = 1;

            /* '<S15>:1:171' */
            current_color = i;
            exitg = TRUE;
          } else {
            guard = TRUE;
          }

          if (guard) {
            i++;
          }
        }
      }

      /*  Blob analysis */
      if (condition_0 == 1) {
        /* '<S15>:1:179' */
        /* '<S15>:1:181' */
        for (imgCol = 0; imgCol < 160; imgCol++) {
          /* '<S15>:1:181' */
          /* '<S15>:1:182' */
          for (numElem = 0; numElem < 120; numElem++) {
            /* '<S15>:1:182' */
            if (VisionModel_B.LabelMatrix_n[160 * numElem + imgCol] != maxL) {
              /* '<S15>:1:183' */
              /* '<S15>:1:184' */
              VisionModel_B.LogicMatrix[imgCol + 160 * numElem] = FALSE;
            } else {
              /* '<S15>:1:186' */
              VisionModel_B.LogicMatrix[imgCol + 160 * numElem] = TRUE;

              /* '<S15>:1:187' */
              VisionModel_B.bw_image_m[imgCol + 160 * numElem] = 1;
            }
          }
        }

        VisionModel_Outputs(&VisionModel_B.LogicMatrix[0], TArea, TCentroid,
                            TBBox, color_areas, TMinorAxis, TOrientation,
                            TEccent, TExtent, &TNumBlobs);

        /* '<S15>:1:194' */
        for (c_i = 1U; c_i <= TNumBlobs; c_i = (uint8_T)((uint32_T)c_i + 1U)) {
          /* '<S15>:1:194' */
          i_gate_idx = floor((blob_count + (real_T)TNumBlobs) + 0.5);
          if (i_gate_idx < 256.0) {
            tmp = (uint8_T)i_gate_idx;
          } else {
            tmp = MAX_uint8_T;
          }

          if (tmp <= 50) {
            /* '<S15>:1:195' */
            /* '<S15>:1:197' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_centroids_m[((tmp - 1) << 1)] = TCentroid[(c_i -
              1) << 1];

            /* '<S15>:1:198' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_centroids_m[1 + ((tmp - 1) << 1)] = TCentroid
              [((c_i - 1) << 1) + 1];

            /* '<S15>:1:200' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            ii = VisionModel_B.blob_centroids_m[((tmp - 1) << 1)];
            VisionModel_refp1_round(&ii);

            /* '<S15>:1:201' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            jj = VisionModel_B.blob_centroids_m[((tmp - 1) << 1) + 1];
            VisionModel_refp1_round(&jj);

            /* '<S15>:1:203' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_hues_g[3 * (tmp - 1)] =
              VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
              VisionModel_B.LabelMatrix_n[((int32_T)jj - 1) * 160 + ((int32_T)ii
              - 1)] - 1];

            /* '<S15>:1:204' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_hues_g[1 + 3 * (tmp - 1)] =
              VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
              VisionModel_B.LabelMatrix_n[((int32_T)jj - 1) * 160 + ((int32_T)ii
              - 1)] + 49];

            /* '<S15>:1:205' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_hues_g[2 + 3 * (tmp - 1)] =
              VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
              VisionModel_B.LabelMatrix_n[((int32_T)jj - 1) * 160 + ((int32_T)ii
              - 1)] + 99];

            /* '<S15>:1:207' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            blob_area[tmp - 1] = TArea[c_i - 1];

            /* '<S15>:1:208' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            blob_bbox[tmp - 1] = TBBox[c_i - 1];

            /* '<S15>:1:209' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_major_axis_e[tmp - 1] = color_areas[c_i - 1];

            /* '<S15>:1:210' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_minor_axis_i[tmp - 1] = TMinorAxis[c_i - 1];

            /* '<S15>:1:211' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_eccentricity_h[tmp - 1] = TEccent[c_i - 1];

            /* '<S15>:1:212' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_extent_k[tmp - 1] = TExtent[c_i - 1];

            /* '<S15>:1:213' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            VisionModel_B.blob_orientation_g[tmp - 1] = TOrientation[c_i - 1];

            /* '<S15>:1:215' */
            i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            blob_color[tmp - 1] = (int8_T)current_color;
          }
        }

        /* '<S15>:1:220' */
        blob_count += (real_T)TNumBlobs;
      }
    }

    for (i = 0; i < 50; i++) {
      VisionModel_B.blob_area_p[i] = (real_T)blob_area[i];
    }

    for (i = 0; i < 200; i++) {
      VisionModel_B.blob_bbox_o[i] = (real_T)blob_bbox[i];
    }

    VisionModel_B.blob_count_c = blob_count;
    for (i = 0; i < 50; i++) {
      VisionModel_B.blob_color_i[i] = (real_T)blob_color[i];
    }

    for (i = 0; i < 19200; i++) {
      VisionModel_B.bw_image_e[i] = (real_T)VisionModel_B.bw_image_m[i];
    }

    /* If: '<S3>/If' incorporates:
     *  ActionPort: '<S17>/Action Port'
     *  SubSystem: '<S3>/Segmented Image'
     */
    if (rtb_Add1 > 0.0) {
      /* Embedded MATLAB: '<S17>/Display Image' */
      /* Embedded MATLAB Function 'Blob_Analysis/Segmented Image/Display Image': '<S26>:1' */
      /*  Initialize */
      /* '<S26>:1:6' */
      /* '<S26>:1:7' */
      /* '<S26>:1:8' */
      /*  Allow only colors in specified range */
      /* '<S26>:1:12' */
      for (condition_0 = 0; condition_0 < 160; condition_0++) {
        /* '<S26>:1:12' */
        /* '<S26>:1:13' */
        for (current_color = 0; current_color < 120; current_color++) {
          /* '<S26>:1:13' */
          /* '<S26>:1:15' */
          VisionModel_B.Divide5[condition_0 + 160 * current_color] =
            VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
            VisionModel_B.LabelMatrix_n[160 * current_color + condition_0] - 1];

          /* '<S26>:1:16' */
          VisionModel_B.Divide4[condition_0 + 160 * current_color] =
            VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
            VisionModel_B.LabelMatrix_n[160 * current_color + condition_0] + 49];

          /* '<S26>:1:17' */
          VisionModel_B.Divide3[condition_0 + 160 * current_color] =
            VisionModel_B.sf_ReferenceColorSelection.ref_colors[(int32_T)
            VisionModel_B.LabelMatrix_n[160 * current_color + condition_0] + 99];
        }
      }

      /* S-Function (svipcolorconv): '<S17>/Color Space  Conversion' */
      /* temporary variables for in-place operation */
      /* First convert to XYZ */
      for (i = 0; i < 19200; i++) {
        c = (VisionModel_B.Divide5[i] + 16.0) / 116.0;
        jj = VisionModel_B.Divide4[i] / 500.0 + c;
        ii = VisionModel_B.Divide3[i] / -200.0 + c;
        if (jj <= 0.20689655172413793) {
          jj -= 0.13793103448275862;
          jj /= 7.7870370370370372;
        } else {
          jj = rt_pow_snf(jj, 3.0);
        }

        if (c <= 0.20689655172413793) {
          c -= 0.13793103448275862;
          c /= 7.7870370370370372;
        } else {
          c = rt_pow_snf(c, 3.0);
        }

        if (ii <= 0.20689655172413793) {
          ii -= 0.13793103448275862;
          ii /= 7.7870370370370372;
        } else {
          ii = rt_pow_snf(ii, 3.0);
        }

        jj *= 0.9504;
        ii *= 1.0889;

        /* assign the results */
        VisionModel_Y.R_forward_out1[i] = jj;
        VisionModel_Y.G_forward_out1[i] = c;
        VisionModel_B.ColorSpaceConversion_o3[i] = ii;
      }

      /* Go from XYZ to sRGB; do it in place on the output buffer */
      /* temporary variables for in-place operation */
      for (i = 0; i < 19200; i++) {
        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        jj = (3.24096994190451 * VisionModel_Y.R_forward_out1[i] +
              -1.53738317757009 * VisionModel_Y.G_forward_out1[i]) +
          -0.49861076029299 * VisionModel_B.ColorSpaceConversion_o3[i];
        c = (-0.96924363628087 * VisionModel_Y.R_forward_out1[i] +
             1.87596750150771 * VisionModel_Y.G_forward_out1[i]) +
          0.04155505740718 * VisionModel_B.ColorSpaceConversion_o3[i];
        ii = (0.055630079697 * VisionModel_Y.R_forward_out1[i] +
              -0.20397695888899 * VisionModel_Y.G_forward_out1[i]) +
          1.05697151424288 * VisionModel_B.ColorSpaceConversion_o3[i];

        /* Apply gamma correction to get R'G'B' */
        if (jj <= 0.00304) {
          jj *= 12.923054468333255;
        } else {
          jj = 1.0550005198172263 * rt_pow_snf(jj, 0.41666666666666669) -
            0.055000519817226347;
        }

        if (c <= 0.00304) {
          c *= 12.923054468333255;
        } else {
          c = 1.0550005198172263 * rt_pow_snf(c, 0.41666666666666669) -
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

        if (c > 1.0) {
          c = 1.0;
        } else {
          if (c < 0.0) {
            c = 0.0;
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
        VisionModel_Y.R_forward_out1[i] = jj;
        VisionModel_Y.G_forward_out1[i] = c;
        VisionModel_B.ColorSpaceConversion_o3[i] = ii;
      }
    }
  } else {
    if ((VisionModel_U.ModeSelect == 2.0) || (VisionModel_U.ModeSelect == 6.0))
    {
      /* Embedded MATLAB: '<S30>/Low Pass Filter' */
      VisionModel_LowPassFilter_f(VisionModel_B.ColorSpaceConversion4_o1,
        &VisionModel_B.sf_LowPassFilter_f);

      /* Embedded MATLAB: '<S30>/Low Pass Filter1' */
      VisionModel_LowPassFilter_f(VisionModel_B.ColorSpaceConversion4_o2,
        &VisionModel_B.sf_LowPassFilter1_e);

      /* Embedded MATLAB: '<S30>/Low Pass Filter2' */
      VisionModel_LowPassFilter_f(VisionModel_B.ColorSpaceConversion4_o3,
        &VisionModel_B.sf_LowPassFilter2_n);

      /* S-Function (svipcolorconv): '<S28>/Color Space  Conversion1' */
      /* temporary variables for in-place operation */
      /* Convert to XYZ */
      /* temporary variables for in-place operation */
      for (i = 0; i < 19200; i++) {
        /* First, linearize (de-gamma) the RGB values; the operation is */
        /* equivalent to running the gamma correction block with break */
        /* point of 0.00304 and gamma of 2.4; it's built into this */
        /* conversion for convenience */
        if (VisionModel_B.sf_LowPassFilter_f.Iout[i] <= 0.039286085583733095) {
          minL = VisionModel_B.sf_LowPassFilter_f.Iout[i] / 12.923054468333255;
        } else {
          minL = (VisionModel_B.sf_LowPassFilter_f.Iout[i] +
                  0.055000519817226347) / 1.0550005198172263;
          minL = rt_pow_snf(minL, 2.4);
        }

        if (VisionModel_B.sf_LowPassFilter1_e.Iout[i] <= 0.039286085583733095) {
          maxL = VisionModel_B.sf_LowPassFilter1_e.Iout[i] / 12.923054468333255;
        } else {
          maxL = (VisionModel_B.sf_LowPassFilter1_e.Iout[i] +
                  0.055000519817226347) / 1.0550005198172263;
          maxL = rt_pow_snf(maxL, 2.4);
        }

        if (VisionModel_B.sf_LowPassFilter2_n.Iout[i] <= 0.039286085583733095) {
          ii = VisionModel_B.sf_LowPassFilter2_n.Iout[i] / 12.923054468333255;
        } else {
          ii = (VisionModel_B.sf_LowPassFilter2_n.Iout[i] + 0.055000519817226347)
            / 1.0550005198172263;
          ii = rt_pow_snf(ii, 2.4);
        }

        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        jj = (0.41239079926596 * minL + 0.35758433938388 * maxL) +
          0.18048078840183 * ii;
        c = (0.21263900587151 * minL + 0.71516867876776 * maxL) +
          0.07219231536073 * ii;
        ii = (0.01933081871559 * minL + 0.11919477979463 * maxL) +
          0.95053215224966 * ii;

        /* Make sure that the output is in [0..1] range; clip if necessary */
        if (jj > 1.0) {
          jj = 1.0;
        } else {
          if (jj < 0.0) {
            jj = 0.0;
          }
        }

        if (c > 1.0) {
          c = 1.0;
        } else {
          if (c < 0.0) {
            c = 0.0;
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
        VisionModel_B.ColorSpaceConversion1_o1[i] = jj;
        VisionModel_B.ColorSpaceConversion1_o2[i] = c;
        VisionModel_B.ColorSpaceConversion1_o3[i] = ii;
      }

      /* Convert from XYZ to L*a*b* */
      for (i = 0; i < 19200; i++) {
        ii = VisionModel_B.ColorSpaceConversion1_o1[i] / 0.9641986557609;
        jj = VisionModel_B.ColorSpaceConversion1_o3[i] / 0.82511648322104;

        /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
        if (ii > 0.0088564516790356311) {
          minL = rt_pow_snf(ii, 0.33333333333333331);
        } else {
          minL = 7.7870370370370372 * ii + 0.13793103448275862;
        }

        if (VisionModel_B.ColorSpaceConversion1_o2[i] > 0.0088564516790356311) {
          maxL = rt_pow_snf(VisionModel_B.ColorSpaceConversion1_o2[i],
                            0.33333333333333331);
        } else {
          maxL = 7.7870370370370372 * VisionModel_B.ColorSpaceConversion1_o2[i]
            + 0.13793103448275862;
        }

        if (jj > 0.0088564516790356311) {
          ii = rt_pow_snf(jj, 0.33333333333333331);
        } else {
          ii = 7.7870370370370372 * jj + 0.13793103448275862;
        }

        /* assign the results */
        VisionModel_B.ColorSpaceConversion1_o1[i] = 116.0 * maxL - 16.0;
        VisionModel_B.ColorSpaceConversion1_o2[i] = (minL - maxL) * 500.0;
        VisionModel_B.ColorSpaceConversion1_o3[i] = (maxL - ii) * 200.0;
      }

      /* S-Function (svipresize): '<S37>/Resize' */
      /* use pre-computed weights and index table to perform interpolation */
      condition_0 = 0;
      for (col = 0; col < 120; col++) {
        find_black = col;
        for (numElem = 0; numElem < 80; numElem++) {
          find_white = numElem + 80;
          ii =
            VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled14[numElem]
            * 120 + col] * VisionModel_ConstP.pooled6[numElem] +
            VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o1[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          VisionModel_DWork.Resize_IntBuffer[find_black] = ii;
          find_black += 120;
        }
      }

      for (numElem = 0; numElem < 80; numElem++) {
        memcpy((void *)&Resize2_LineBuffer[0], (void *)
               (&VisionModel_DWork.Resize_IntBuffer[numElem * 120]), 120U *
               sizeof(real_T));
        for (col = 0; col < 60; col++) {
          find_white = col + 60;
          ii = Resize2_LineBuffer[VisionModel_ConstP.pooled13[col]] *
            VisionModel_ConstP.pooled5[col] +
            Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          VisionModel_B.Resize[condition_0] = ii;
          condition_0++;
        }
      }

      /* S-Function (svipresize): '<S37>/Resize1' */
      /* use pre-computed weights and index table to perform interpolation */
      condition_0 = 0;
      for (col = 0; col < 120; col++) {
        find_black = col;
        for (numElem = 0; numElem < 80; numElem++) {
          find_white = numElem + 80;
          ii =
            VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled14[numElem]
            * 120 + col] * VisionModel_ConstP.pooled6[numElem] +
            VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o2[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          VisionModel_DWork.Resize1_IntBuffer[find_black] = ii;
          find_black += 120;
        }
      }

      for (numElem = 0; numElem < 80; numElem++) {
        memcpy((void *)&Resize2_LineBuffer[0], (void *)
               (&VisionModel_DWork.Resize1_IntBuffer[numElem * 120]), 120U *
               sizeof(real_T));
        for (col = 0; col < 60; col++) {
          find_white = col + 60;
          ii = Resize2_LineBuffer[VisionModel_ConstP.pooled13[col]] *
            VisionModel_ConstP.pooled5[col] +
            Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          VisionModel_B.Resize1[condition_0] = ii;
          condition_0++;
        }
      }

      /* S-Function (svipresize): '<S37>/Resize2' */
      /* use pre-computed weights and index table to perform interpolation */
      condition_0 = 0;
      for (col = 0; col < 120; col++) {
        find_black = col;
        for (numElem = 0; numElem < 80; numElem++) {
          find_white = numElem + 80;
          ii =
            VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled14[numElem]
            * 120 + col] * VisionModel_ConstP.pooled6[numElem] +
            VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          find_white += 80;
          ii +=
            VisionModel_B.ColorSpaceConversion1_o3[VisionModel_ConstP.pooled14[find_white]
            * 120 + col] * VisionModel_ConstP.pooled6[find_white];
          VisionModel_DWork.Resize2_IntBuffer[find_black] = ii;
          find_black += 120;
        }
      }

      for (numElem = 0; numElem < 80; numElem++) {
        memcpy((void *)&Resize2_LineBuffer[0], (void *)
               (&VisionModel_DWork.Resize2_IntBuffer[numElem * 120]), 120U *
               sizeof(real_T));
        for (col = 0; col < 60; col++) {
          find_white = col + 60;
          ii = Resize2_LineBuffer[VisionModel_ConstP.pooled13[col]] *
            VisionModel_ConstP.pooled5[col] +
            Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          find_white += 60;
          ii += Resize2_LineBuffer[VisionModel_ConstP.pooled13[find_white]] *
            VisionModel_ConstP.pooled5[find_white];
          VisionModel_B.Resize2[condition_0] = ii;
          condition_0++;
        }
      }

      /* Embedded MATLAB: '<S31>/Reference Color Selection' */
      VisionM_ReferenceColorSelection(VisionModel_B.Resize,
        VisionModel_B.Resize1, VisionModel_B.Resize2,
        VisionModel_P.Iter_Segment_Thresh_Value_c,
        &VisionModel_B.sf_ReferenceColorSelection_e);

      /* Embedded MATLAB: '<S31>/LabSegmentation' */
      /* Embedded MATLAB Function 'Blob_Analysis1/IterativeSegmentation/Segmentation/LabSegmentation': '<S35>:1' */
      /*  This function generates the label matrix */
      /* '<S35>:1:5' */
      memset((void *)(&VisionModel_B.LabelMatrix[0]), 0, 19200U * sizeof(real_T));

      /* '<S35>:1:7' */
      for (i = 0; i < 120; i++) {
        /* '<S35>:1:7' */
        /* '<S35>:1:8' */
        for (numElem = 0; numElem < 160; numElem++) {
          /* '<S35>:1:8' */
          /* '<S35>:1:9' */
          ii = 1000.0;

          /* '<S35>:1:10' */
          jj = 1.0;

          /* '<S35>:1:11' */
          for (i_gate_idx = 1.0; i_gate_idx <=
               VisionModel_B.sf_ReferenceColorSelection_e.num_colors; i_gate_idx
               ++) {
            /* '<S35>:1:11' */
            /* '<S35>:1:12' */
            minL = sqrt((rt_pow_snf
                         (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                          [(int32_T)i_gate_idx - 1] -
                          VisionModel_B.ColorSpaceConversion1_o1[120 * numElem +
                          i], 2.0) + rt_pow_snf
                         (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                          [(int32_T)i_gate_idx + 49] -
                          VisionModel_B.ColorSpaceConversion1_o2[120 * numElem +
                          i], 2.0)) + rt_pow_snf
                        (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                         [(int32_T)i_gate_idx + 99] -
                         VisionModel_B.ColorSpaceConversion1_o3[120 * numElem +
                         i], 2.0));
            if (minL < ii) {
              /* '<S35>:1:13' */
              /* '<S35>:1:14' */
              ii = minL;

              /* '<S35>:1:15' */
              jj = i_gate_idx;
            }
          }

          /* '<S35>:1:18' */
          VisionModel_B.LabelMatrix[i + 120 * numElem] = jj;
        }
      }

      /* Embedded MATLAB: '<S4>/Blob Extraction' */
      c = VisionModel_B.sf_ReferenceColorSelection_e.num_colors;

      /* Embedded MATLAB Function 'Blob_Analysis1/Blob Extraction': '<S27>:1' */
      /*  This function calculates blob information for each color component after */
      /*    iterative segmentation */
      /*  Output */
      /*    blob_color = 1xN vector of color indices (global color scheme) */
      /*  Initialize */
      /* { */
      /* a_range =[0     0     0    25   127    70    50; */
      /*      0     0     0   127   -18   -40   -82]; */
      /*  */
      /* b_range =[0     0     0     0    30   -13   -40; */
      /*      0     0     0    56   -10    30     9]; */
      /* } */
      /* ColorFilter = ColorFilter_in; */
      /* '<S27>:1:26' */
      /* '<S27>:1:32' */
      for (i = 0; i < 7; i++) {
        ColorFilter[i] = VisionModel_B.ColorFilter_out[i];
      }

      /* '<S27>:1:33' */
      /* '<S27>:1:34' */
      /* '<S27>:1:36' */
      /* '<S27>:1:41' */
      /* '<S27>:1:42' */
      for (i = 0; i < 19200; i++) {
        VisionModel_B.LogicMatrix[i] = FALSE;
        VisionModel_B.bw_image_m[i] = 0;
      }

      /* '<S27>:1:44' */
      memset((void *)(&VisionModel_B.blob_hues[0]), 0, 150U * sizeof(real_T));

      /* '<S27>:1:45' */
      for (i = 0; i < 50; i++) {
        blob_area[i] = -1;
      }

      /* '<S27>:1:46' */
      memset((void *)&blob_bbox[0], 0, 200U * sizeof(int32_T));

      /* '<S27>:1:47' */
      /* '<S27>:1:48' */
      for (i = 0; i < 50; i++) {
        VisionModel_B.blob_major_axis[i] = 0.0;
        VisionModel_B.blob_minor_axis[i] = 0.0;
      }

      /* '<S27>:1:49' */
      memset((void *)(&VisionModel_B.blob_centroids[0]), 0, 100U * sizeof(real_T));

      /* '<S27>:1:50' */
      /* '<S27>:1:51' */
      /* '<S27>:1:52' */
      /* '<S27>:1:53' */
      blob_count = 0.0;

      /* '<S27>:1:55' */
      /* '<S27>:1:58' */
      /* '<S27>:1:60' */
      /*  Determine L_white and L_black as needed */
      /* '<S27>:1:64' */
      find_white = 0;

      /* '<S27>:1:65' */
      find_black = 0;

      /* '<S27>:1:66' */
      L_white = 101.0;

      /* '<S27>:1:67' */
      L_black = -1.0;

      /* '<S27>:1:68' */
      for (i = 0; i < 50; i++) {
        VisionModel_B.blob_eccentricity[i] = 0.0;
        VisionModel_B.blob_extent[i] = 0.0;
        VisionModel_B.blob_orientation[i] = 0.0;
        blob_color[i] = 0;
        color_areas[i] = 0.0;
      }

      if (VisionModel_B.ColorFilter_out[0] + VisionModel_B.ColorFilter_out[1] >
          0.0) {
        /* '<S27>:1:70' */
        /* '<S27>:1:71' */
        for (imgIdxLR = 0; imgIdxLR < 120; imgIdxLR++) {
          /* '<S27>:1:71' */
          /* '<S27>:1:72' */
          for (col = 0; col < 160; col++) {
            /* '<S27>:1:72' */
            /* '<S27>:1:73' */
            color_areas[(int32_T)VisionModel_B.LabelMatrix[imgIdxLR + 120 * col]
              - 1] = color_areas[(int32_T)VisionModel_B.LabelMatrix[120 * col +
              imgIdxLR] - 1] + 1.0;
          }
        }
      }

      if (VisionModel_B.ColorFilter_out[0] == 1.0) {
        /* '<S27>:1:78' */
        /*  Determine the brightest colors, but allow a maximum area */
        /*    ratio of the image to be "white" */
        /* '<S27>:1:82' */
        find_white = 1;

        /* '<S27>:1:84' */
        positive_area = 0.0;

        /* '<S27>:1:85' */
        r = 1.0;
        condition = FALSE;
        while (((uint32_T)condition == 0U) && (r <=
                VisionModel_B.sf_ReferenceColorSelection_e.num_colors)) {
          /* '<S27>:1:85' */
          /* '<S27>:1:87' */
          maxL = -1.0;

          /* '<S27>:1:88' */
          ii = -1.0;

          /* '<S27>:1:89' */
          for (i_gate_idx = 1.0; i_gate_idx <=
               VisionModel_B.sf_ReferenceColorSelection_e.num_colors; i_gate_idx
               ++) {
            /* '<S27>:1:89' */
            /* '<S27>:1:90' */
            if ((VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                 i_gate_idx - 1] > maxL) &&
                (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                 i_gate_idx - 1] < L_white)) {
              /* '<S27>:1:91' */
              /* '<S27>:1:92' */
              maxL = VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                [(int32_T)i_gate_idx - 1];

              /* '<S27>:1:93' */
              ii = i_gate_idx;
            }
          }

          /* '<S27>:1:97' */
          positive_area += color_areas[(int32_T)ii - 1];
          if ((positive_area / 19200.0 >= 0.1) && (r > 1.0)) {
            /* '<S27>:1:98' */
            condition = TRUE;
          } else {
            /* '<S27>:1:102' */
            L_white = maxL;
            r++;
          }
        }
      }

      if (VisionModel_B.ColorFilter_out[1] == 1.0) {
        /* '<S27>:1:107' */
        /*  Determine the darkest colors, but allow a maximum area */
        /*    ratio of the image to be "black" */
        /* '<S27>:1:111' */
        find_black = 1;

        /* '<S27>:1:113' */
        for (condition_0 = 0; condition_0 < 120; condition_0++) {
          /* '<S27>:1:113' */
          /* '<S27>:1:114' */
          for (current_color = 0; current_color < 160; current_color++) {
            /* '<S27>:1:114' */
            /* '<S27>:1:115' */
            color_areas[(int32_T)VisionModel_B.LabelMatrix[condition_0 + 120 *
              current_color] - 1] = color_areas[(int32_T)
              VisionModel_B.LabelMatrix[120 * current_color + condition_0] - 1]
              + 1.0;
          }
        }

        /* '<S27>:1:119' */
        positive_area = 0.0;

        /* '<S27>:1:120' */
        maxL = 1.0;
        exitg_0 = FALSE;
        while (((uint32_T)exitg_0 == 0U) && (maxL <=
                VisionModel_B.sf_ReferenceColorSelection_e.num_colors)) {
          /* '<S27>:1:120' */
          /* '<S27>:1:122' */
          minL = 101.0;

          /* '<S27>:1:123' */
          ii = -1.0;

          /* '<S27>:1:124' */
          for (jj = 1.0; jj <=
               VisionModel_B.sf_ReferenceColorSelection_e.num_colors; jj++) {
            /* '<S27>:1:124' */
            /* '<S27>:1:125' */
            if ((VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                 jj - 1] < minL) &&
                (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                 jj - 1] > L_black)) {
              /* '<S27>:1:126' */
              /* '<S27>:1:127' */
              minL = VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                [(int32_T)jj - 1];

              /* '<S27>:1:128' */
              ii = jj;
            }
          }

          /* '<S27>:1:132' */
          positive_area += color_areas[(int32_T)ii - 1];
          if ((positive_area / 19200.0 >= 0.1) && (maxL > 1.0)) {
            /* '<S27>:1:133' */
            exitg_0 = TRUE;
          } else {
            /* '<S27>:1:137' */
            L_black = minL;
            maxL++;
          }
        }
      }

      /*  Input hblob, a matrix containing [Area, blob_centroids, Eccentricity] for each */
      /*  identified blob */
      /*  Calculate geometric information about the blobs */
      /*  */
      /*  LogicMatrix is a binary version of LabelMatrix, with ones at all */
      /*    locations for which color values are k, and zeros everywhere else */
      /*  */
      /*  Explanation */
      /*    condition1 == 1 causes the k'th color to be analyzed by blob analysis, */
      /*      as well as be included in the black-and-white image */
      /*    condition1 == 0 disallows both of these items and simply ignores color */
      /*      k */
      /*    condition0 == 1 ensures that condition1 is true for all k */
      /*    condition0 == 0 enforces a filter which allows only the colors */
      /*      specified in the ColorFilter vector */
      /* '<S27>:1:168' */
      condition = (VisionModel_sum_e(&VisionModel_B.ColorFilter_out[0]) == 0.0);

      /* '<S27>:1:169' */
      current_color = 0;

      /* '<S27>:1:170' */
      for (maxL = 1.0; maxL <= c; maxL++) {
        /* '<S27>:1:170' */
        /*  Decide whether or not to perform blob analysis */
        /* '<S27>:1:173' */
        condition_0 = 0;
        if (condition) {
          /* '<S27>:1:174' */
          /* '<S27>:1:175' */
          condition_0 = 1;
        } else {
          /* '<S27>:1:177' */
          /* '<S27>:1:178' */
          /* '<S27>:1:179' */
          i = 1;
          exitg = FALSE;
          while (((uint32_T)exitg == 0U) && (i <= 7)) {
            /* '<S27>:1:179' */
            /*  Skip colors that have not been specified */
            guard = FALSE;
            if (ColorFilter[i - 1] == 0.0) {
              /* '<S27>:1:182' */
              guard = TRUE;
            } else if ((find_white == 1) &&
                       (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL - 1] >= L_white)) {
              /* '<S27>:1:186' */
              /*  Handle "white" differently than other colors */
              /* '<S27>:1:187' */
              condition_0 = 1;

              /* '<S27>:1:188' */
              current_color = 1;
              exitg = TRUE;
            } else if ((find_black == 1) &&
                       (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL - 1] <= L_black)) {
              /* '<S27>:1:190' */
              /*  Handle "black" differently than other colors */
              /* '<S27>:1:191' */
              condition_0 = 1;

              /* '<S27>:1:192' */
              current_color = 2;
              exitg = TRUE;
            } else if ((VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL + 49] >= (real_T)tmp_1[(i - 1) << 1]) &&
                       (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL + 49] <= (real_T)tmp_1[((i - 1) << 1) + 1])
                       &&
                       (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL + 99] >= (real_T)tmp_0[(i - 1) << 1]) &&
                       (VisionModel_B.sf_ReferenceColorSelection_e.ref_colors
                        [(int32_T)maxL + 99] <= (real_T)tmp_0[((i - 1) << 1) + 1]))
            {
              /* '<S27>:1:194' */
              /* '<S27>:1:195' */
              condition_0 = 1;

              /* '<S27>:1:196' */
              current_color = i;
              exitg = TRUE;
            } else {
              guard = TRUE;
            }

            if (guard) {
              i++;
            }
          }
        }

        /*  Blob analysis */
        if (condition_0 == 1) {
          /* '<S27>:1:204' */
          /* '<S27>:1:206' */
          for (imgCol = 0; imgCol < 120; imgCol++) {
            /* '<S27>:1:206' */
            /* '<S27>:1:207' */
            for (numElem = 0; numElem < 160; numElem++) {
              /* '<S27>:1:207' */
              if (VisionModel_B.LabelMatrix[120 * numElem + imgCol] != maxL) {
                /* '<S27>:1:208' */
                /* '<S27>:1:209' */
                VisionModel_B.LogicMatrix[imgCol + 120 * numElem] = FALSE;
              } else {
                /* '<S27>:1:211' */
                VisionModel_B.LogicMatrix[imgCol + 120 * numElem] = TRUE;

                /* '<S27>:1:212' */
                VisionModel_B.bw_image_m[imgCol + 120 * numElem] = 1;
              }
            }
          }

          VisionModel_Outputs_e(&VisionModel_B.LogicMatrix[0], TArea, TCentroid,
                                TBBox, color_areas, TMinorAxis, TOrientation,
                                TEccent, TExtent, &TNumBlobs);

          /* '<S27>:1:219' */
          for (c_i = 1U; c_i <= TNumBlobs; c_i = (uint8_T)((uint32_T)c_i + 1U))
          {
            /* '<S27>:1:219' */
            i_gate_idx = floor((blob_count + (real_T)TNumBlobs) + 0.5);
            if (i_gate_idx < 256.0) {
              tmp = (uint8_T)i_gate_idx;
            } else {
              tmp = MAX_uint8_T;
            }

            if (tmp <= 50) {
              /* '<S27>:1:220' */
              /* '<S27>:1:222' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_centroids[((tmp - 1) << 1)] = TCentroid[(c_i -
                1) << 1];

              /* '<S27>:1:223' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_centroids[1 + ((tmp - 1) << 1)] = TCentroid
                [((c_i - 1) << 1) + 1];

              /* '<S27>:1:225' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              ii = VisionModel_B.blob_centroids[((tmp - 1) << 1)];
              VisionModel_refp1_round_e(&ii);

              /* '<S27>:1:226' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              jj = VisionModel_B.blob_centroids[((tmp - 1) << 1) + 1];
              VisionModel_refp1_round_e(&jj);

              /* '<S27>:1:228' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_hues[3 * (tmp - 1)] =
                VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                VisionModel_B.LabelMatrix[((int32_T)jj - 1) * 120 + ((int32_T)ii
                - 1)] - 1];

              /* '<S27>:1:229' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_hues[1 + 3 * (tmp - 1)] =
                VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                VisionModel_B.LabelMatrix[((int32_T)jj - 1) * 120 + ((int32_T)ii
                - 1)] + 49];

              /* '<S27>:1:230' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_hues[2 + 3 * (tmp - 1)] =
                VisionModel_B.sf_ReferenceColorSelection_e.ref_colors[(int32_T)
                VisionModel_B.LabelMatrix[((int32_T)jj - 1) * 120 + ((int32_T)ii
                - 1)] + 99];

              /* '<S27>:1:232' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              blob_area[tmp - 1] = TArea[c_i - 1];

              /* '<S27>:1:233' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              blob_bbox[tmp - 1] = TBBox[c_i - 1];

              /* '<S27>:1:234' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_major_axis[tmp - 1] = color_areas[c_i - 1];

              /* '<S27>:1:235' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_minor_axis[tmp - 1] = TMinorAxis[c_i - 1];

              /* '<S27>:1:236' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_eccentricity[tmp - 1] = TEccent[c_i - 1];

              /* '<S27>:1:237' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_extent[tmp - 1] = TExtent[c_i - 1];

              /* '<S27>:1:238' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              VisionModel_B.blob_orientation[tmp - 1] = TOrientation[c_i - 1];

              /* '<S27>:1:240' */
              i_gate_idx = floor((blob_count + (real_T)c_i) + 0.5);
              if (i_gate_idx < 256.0) {
                tmp = (uint8_T)i_gate_idx;
              } else {
                tmp = MAX_uint8_T;
              }

              blob_color[tmp - 1] = (int8_T)current_color;
            }
          }

          /* '<S27>:1:245' */
          blob_count += (real_T)TNumBlobs;
        }
      }

      for (i = 0; i < 50; i++) {
        VisionModel_B.blob_area[i] = (real_T)blob_area[i];
      }

      for (i = 0; i < 200; i++) {
        VisionModel_B.blob_bbox[i] = (real_T)blob_bbox[i];
      }

      VisionModel_B.blob_count = blob_count;
      for (i = 0; i < 50; i++) {
        VisionModel_B.blob_color[i] = (real_T)blob_color[i];
      }

      for (i = 0; i < 9; i++) {
        VisionModel_B.bw_image[i] = (real_T)VisionModel_B.bw_image_m[i];
      }
    }
  }

  /* If: '<Root>/If2' incorporates:
   *  ActionPort: '<S10>/Action Port'
   *  ActionPort: '<S12>/Action Port'
   *  ActionPort: '<S13>/Action Port'
   *  ActionPort: '<S14>/Action Port'
   *  ActionPort: '<S8>/Action Port'
   *  ActionPort: '<S9>/Action Port'
   *  Inport: '<Root>/ModeSelect'
   *  SubSystem: '<Root>/L_detector'
   *  SubSystem: '<Root>/buoy_detector'
   *  SubSystem: '<Root>/drop_mech'
   *  SubSystem: '<Root>/path_detector'
   *  SubSystem: '<Root>/torpedo'
   *  SubSystem: '<Root>/validation_gate'
   */
  if (VisionModel_U.ModeSelect == 1.0) {
    /* S-Function (svipedge): '<S14>/Edge Detection' */
    for (imgCol = 1; imgCol < 119; imgCol++) {
      for (current_color = 1; current_color < 159; current_color++) {
        ii = 0.0;
        jj = 0.0;
        condition_0 = imgCol * 160 + current_color;
        for (col = 0; col < 6; col++) {
          ii += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection_VO_DW_l[col]] *
            VisionModel_ConstP.pooled7[col];
          jj += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection_HO_DW_p[col]] *
            VisionModel_ConstP.pooled8[col];
        }

        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = ii * ii;
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = jj * jj;
      }
    }

    for (imgCol = 1; imgCol < 119; imgCol++) {
      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      condition_0 = imgCol * 160;
      current_color = imgCol * 160 + 159;
      for (col = 0; col < 6; col++) {
        ii += VisionModel_B.bw_image_e[condition_0 +
          VisionModel_DWork.EdgeDetection_HOU_DW_k[col]] *
          VisionModel_ConstP.pooled8[col];
        jj += VisionModel_B.bw_image_e[current_color +
          VisionModel_DWork.EdgeDetection_HOD_DW_i[col]] *
          VisionModel_ConstP.pooled8[col];
        minL += VisionModel_B.bw_image_e[condition_0 +
          VisionModel_DWork.EdgeDetection_VOU_DW_l[col]] *
          VisionModel_ConstP.pooled7[col];
        maxL += VisionModel_B.bw_image_e[current_color +
          VisionModel_DWork.EdgeDetection_VOD_DW_p[col]] *
          VisionModel_ConstP.pooled7[col];
      }

      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = minL * minL;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = ii * ii;
      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[current_color] = maxL *
        maxL;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[current_color] = jj * jj;
    }

    for (current_color = 1; current_color < 159; current_color++) {
      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      condition_0 = 19040 + current_color;
      for (col = 0; col < 6; col++) {
        ii += VisionModel_B.bw_image_e[current_color +
          VisionModel_DWork.EdgeDetection_VOL_DW_k[col]] *
          VisionModel_ConstP.pooled7[col];
        jj += VisionModel_B.bw_image_e[condition_0 +
          VisionModel_DWork.EdgeDetection_VOR_DW_f[col]] *
          VisionModel_ConstP.pooled7[col];
        minL += VisionModel_B.bw_image_e[current_color +
          VisionModel_DWork.EdgeDetection_HOL_DW_g[col]] *
          VisionModel_ConstP.pooled8[col];
        maxL += VisionModel_B.bw_image_e[condition_0 +
          VisionModel_DWork.EdgeDetection_HOR_DW_b[col]] *
          VisionModel_ConstP.pooled8[col];
      }

      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[current_color] = ii * ii;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[current_color] = minL *
        minL;
      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = jj * jj;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = maxL * maxL;
    }

    ii = 0.0;
    jj = 0.0;
    minL = 0.0;
    maxL = 0.0;
    for (col = 0; col < 6; col++) {
      ii +=
        VisionModel_B.bw_image_e[VisionModel_DWork.EdgeDetection_VOUL_DW_k[col]]
        * VisionModel_ConstP.pooled7[col];
      jj +=
        VisionModel_B.bw_image_e[VisionModel_DWork.EdgeDetection_HOUL_DW_k[col]]
        * VisionModel_ConstP.pooled8[col];
      minL += VisionModel_B.bw_image_e[159 +
        VisionModel_DWork.EdgeDetection_VOLL_DW_j[col]] *
        VisionModel_ConstP.pooled7[col];
      maxL += VisionModel_B.bw_image_e[159 +
        VisionModel_DWork.EdgeDetection_HOLL_DW_f[col]] *
        VisionModel_ConstP.pooled8[col];
    }

    VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[0] = ii * ii;
    VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[0] = jj * jj;
    VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[159] = minL * minL;
    VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[159] = maxL * maxL;
    ii = 0.0;
    jj = 0.0;
    minL = 0.0;
    maxL = 0.0;
    for (col = 0; col < 6; col++) {
      ii += VisionModel_B.bw_image_e[19040 +
        VisionModel_DWork.EdgeDetection_VOUR_DW_b[col]] *
        VisionModel_ConstP.pooled7[col];
      jj += VisionModel_B.bw_image_e[19040 +
        VisionModel_DWork.EdgeDetection_HOUR_DW_a[col]] *
        VisionModel_ConstP.pooled8[col];
      minL += VisionModel_B.bw_image_e[19199 +
        VisionModel_DWork.EdgeDetection_VOLR_DW_b[col]] *
        VisionModel_ConstP.pooled7[col];
      maxL += VisionModel_B.bw_image_e[19199 +
        VisionModel_DWork.EdgeDetection_HOLR_DW_a[col]] *
        VisionModel_ConstP.pooled8[col];
    }

    VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[19040] = ii * ii;
    VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[19040] = jj * jj;
    VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[19199] = minL * minL;
    VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[19199] = maxL * maxL;
    jj = 0.0;
    for (col = 0; col < 19200; col++) {
      VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] =
        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col];
      VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] =
        VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] +
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col];
      jj += VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] *
        VisionModel_DWork.EdgeDetection_MEAN_FACTOR_DW_j;
    }

    ii = VisionModel_P.EdgeDetection_THRESH_TUNING_RTP * jj;
    for (imgCol = 0; imgCol < 120; imgCol++) {
      for (current_color = 0; current_color < 160; current_color++) {
        col = imgCol * 160 + current_color;
        VisionModel_B.EdgeDetection_k[col] =
          ((VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] > ii) &&
           (((VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col] >=
              VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col]) && (imgCol !=
              0 ? VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col - 160] <=
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] : TRUE) &&
             (imgCol != 119 ? VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] >
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col + 160] : TRUE)) ||
            ((VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col] >=
              VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col]) &&
             (current_color != 0 ?
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col - 1] <=
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] : TRUE) &&
             (current_color != 159 ?
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] >
              VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col + 1] : TRUE))));
      }
    }

    /* S-Function (sviphough): '<S14>/Hough Transform1' */
    MWVIP_Hough_D(&VisionModel_B.EdgeDetection_k[0],
                  &VisionModel_B.HoughTransform1_o1_b[0],
                  &VisionModel_ConstP.pooled9[0], &VisionModel_ConstP.pooled10,
                  160, 120, 399, 91);

    /* Embedded MATLAB: '<S14>/Identify Validation Gate' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S14>/Constant2'
     *  Constant: '<S14>/Forward_Fov'
     */
    memcpy((void *)(&VisionModel_B.hough_table[0]), (void *)
           (&VisionModel_B.HoughTransform1_o1_b[0]), 71820U * sizeof(real_T));

    /* Embedded MATLAB Function 'validation_gate/Identify Validation Gate': '<S60>:1' */
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
    /* '<S60>:1:30' */
    /* rows = Forward_Camera_Dimensions(1); */
    /* cols = Forward_Camera_Dimensions(2); */
    /* rows = 120; */
    /* cols = 160; */
    /*  eps_rho must be at least as big as the gate leg diameter (units of */
    /*    pixels) */
    /* '<S60>:1:42' */
    /*  eps_theta is used to distinguish lines as "horizontal" or "vertical"; */
    /*    units are radians */
    /* '<S60>:1:45' */
    /*  These vectors contain the final three lines that compose the validation gate */
    /* '<S60>:1:49' */
    /* '<S60>:1:50' */
    rtb_path_headings_idx_1 = 0.0;
    L_black = 0.0;
    rtb_path_headings_idx_0 = 0.0;
    positive_area = 0.0;
    rtb_path_headings_idx = 0.0;
    rtb_theta_gate_idx = 0.0;

    /*  These vectors contain intermediate line information; as lines are */
    /*    eliminated from these vectors, their values are set to zero */
    /* '<S60>:1:54' */
    /* '<S60>:1:55' */
    /*  Identify the most popular max_num_lines lines */
    /* '<S60>:1:62' */
    /* '<S60>:1:63' */
    for (i = 0; i < 200; i++) {
      i_index[i] = 1;
      j_index[i] = 1U;
    }

    /* '<S60>:1:65' */
    for (col = 0; col < 200; col++) {
      /* '<S60>:1:66' */
      /* '<S60>:1:68' */
      ii = 0.0;

      /* '<S60>:1:69' */
      for (i = 0; i < 399; i++) {
        /* '<S60>:1:69' */
        /* '<S60>:1:70' */
        for (numElem = 0; numElem < 180; numElem++) {
          /* '<S60>:1:70' */
          if (VisionModel_B.hough_table[399 * numElem + i] > ii) {
            /* '<S60>:1:71' */
            /* '<S60>:1:72' */
            i_index[col] = (int16_T)(i + 1);

            /* '<S60>:1:73' */
            j_index[col] = (uint8_T)(numElem + 1);

            /* '<S60>:1:74' */
            ii = VisionModel_B.hough_table[399 * numElem + i];
          }
        }
      }

      /* '<S60>:1:79' */
      rho[col] = VisionModel_B.HoughTransform1_o3_i[i_index[col] - 1];

      /* '<S60>:1:80' */
      theta[col] = VisionModel_B.HoughTransform1_o2_i[j_index[col] - 1];

      /* '<S60>:1:81' */
      VisionModel_B.hough_table[(i_index[col] - 1) + 399 * (j_index[col] - 1)] =
        0.0;

      /* '<S60>:1:82' */
    }

    /*  Effectively generate a small Hough table which contains only values of */
    /*    interest for the validation gate application */
    /* '<S60>:1:90' */
    /*  Rho bins for vertical lines */
    /*  Number of rho bins for vertical lines */
    /* '<S60>:1:92' */
    /*  Average rho values for each bin (note that the average value will generally differ slightly than the bin value) */
    /* '<S60>:1:93' */
    /*  Average theta values for each bin */
    /* '<S60>:1:94' */
    /*  Votes bins for vertical lines */
    /* '<S60>:1:96' */
    /* '<S60>:1:98' */
    /* '<S60>:1:99' */
    /* '<S60>:1:100' */
    for (i = 0; i < 6; i++) {
      rbinv[i] = (uint8_T)(i << 5);
      path_locations[i] = 0.0;
      tavgv[i] = 0.0;
      vbinv[i] = 0.0;
      rbinh[i] = (uint8_T)(i << 5);
      ravgh[i] = 0.0;
      tavgh[i] = 0.0;
      vbinh[i] = 0.0;
    }

    /*  Allow vertical lines along the left side of the image */
    /* '<S60>:1:103' */
    rbinv[0] = 1U;

    /* '<S60>:1:104' */
    rbinh[0] = 1U;

    /* '<S60>:1:106' */
    for (imgCol = 0; imgCol < 200; imgCol++) {
      /* '<S60>:1:106' */
      /*  Consider only lines that are either vertical or horizontal, within */
      /*    tolerance */
      if ((fabs(theta[imgCol] - 1.5707963267948966) <= 0.17453292519943295) ||
          (fabs(theta[imgCol] + 1.5707963267948966) <= 0.17453292519943295)) {
        /* '<S60>:1:110' */
        condition = TRUE;
      } else {
        /* '<S60>:1:110' */
        condition = FALSE;
      }

      /*  Horizontal line */
      /* '<S60>:1:111' */
      /*  Vertical line */
      guard = FALSE;
      if (fabs(theta[imgCol]) <= 0.17453292519943295) {
        /* '<S60>:1:113' */
        if ((rho[imgCol] == 0.0) && (theta[imgCol] == 0.0)) {
          /* '<S60>:1:113' */
          c_0 = TRUE;
        } else {
          /* '<S60>:1:113' */
          c_0 = FALSE;
        }

        if (!c_0) {
          /* '<S60>:1:113' */
          /*  Analyze vertical lines (ignore lines exactly along the left side of the image) */
          /* '<S60>:1:115' */
          condition_0 = 1;
          exitg_0 = FALSE;
          while (((uint32_T)exitg_0 == 0U) && (condition_0 <= 6)) {
            /* '<S60>:1:115' */
            /*  Place each rho value into a bin */
            if (fabs(rho[imgCol] - (real_T)rbinv[condition_0 - 1]) <= 16.0) {
              /* '<S60>:1:118' */
              /* '<S60>:1:119' */
              path_locations[condition_0 - 1] = path_locations[condition_0 - 1]
                + rho[imgCol];

              /* '<S60>:1:120' */
              tavgv[condition_0 - 1] = tavgv[condition_0 - 1] + theta[imgCol];

              /* '<S60>:1:121' */
              vbinv[condition_0 - 1] = vbinv[condition_0 - 1] + 1.0;
              exitg_0 = TRUE;
            } else {
              condition_0++;
            }
          }
        } else {
          guard = TRUE;
        }
      } else {
        guard = TRUE;
      }

      if (guard && condition) {
        /* '<S60>:1:110' */
        /*  Analyze horizontal lines */
        if (theta[imgCol] < 0.0) {
          /* '<S60>:1:129' */
          /* '<S60>:1:130' */
          theta[imgCol] = theta[imgCol] + 3.1415926535897931;

          /* '<S60>:1:131' */
          rho[imgCol] = -rho[imgCol];
        }

        /* '<S60>:1:134' */
        condition_0 = 1;
        exitg = FALSE;
        while (((uint32_T)exitg == 0U) && (condition_0 <= 6)) {
          /* '<S60>:1:134' */
          /*  Place each rho value into a bin */
          if (fabs(rho[imgCol] - (real_T)rbinh[condition_0 - 1]) <= 16.0) {
            /* '<S60>:1:137' */
            /* '<S60>:1:138' */
            ravgh[condition_0 - 1] = ravgh[condition_0 - 1] + rho[imgCol];

            /* '<S60>:1:139' */
            tavgh[condition_0 - 1] = tavgh[condition_0 - 1] + theta[imgCol];

            /* '<S60>:1:140' */
            vbinh[condition_0 - 1] = vbinh[condition_0 - 1] + 1.0;
            exitg = TRUE;
          } else {
            condition_0++;
          }
        }
      }
    }

    /*  Average the values in ravg and tavg for horizontal and vertical lines */
    /* '<S60>:1:150' */
    /* '<S60>:1:159' */
    for (condition_0 = 0; condition_0 < 6; condition_0++) {
      /* '<S60>:1:150' */
      if (vbinv[condition_0] == 0.0) {
        /* '<S60>:1:151' */
        /* '<S60>:1:152' */
        i_gate_idx = 0.0;

        /* '<S60>:1:153' */
        rtb_Add1 = 0.0;
      } else {
        /* '<S60>:1:155' */
        i_gate_idx = path_locations[condition_0] / vbinv[condition_0];

        /* '<S60>:1:156' */
        rtb_Add1 = tavgv[condition_0] / vbinv[condition_0];
      }

      /* '<S60>:1:159' */
      if (vbinh[condition_0] == 0.0) {
        /* '<S60>:1:160' */
        /* '<S60>:1:161' */
        blob_count = 0.0;

        /* '<S60>:1:162' */
        L_white = 0.0;
      } else {
        /* '<S60>:1:164' */
        blob_count = ravgh[condition_0] / vbinh[condition_0];

        /* '<S60>:1:165' */
        L_white = tavgh[condition_0] / vbinh[condition_0];
      }

      path_locations[condition_0] = i_gate_idx;
      tavgv[condition_0] = rtb_Add1;
      ravgh[condition_0] = blob_count;
      tavgh[condition_0] = L_white;
    }

    /* % Extract three lines that fit the criteria for being the validation gate */
    /* '<S60>:1:171' */
    ii = 10000.0;

    /* '<S60>:1:172' */
    jj = -10000.0;

    /* '<S60>:1:173' */
    for (condition_0 = 0; condition_0 < 6; condition_0++) {
      /* '<S60>:1:173' */
      /*  Extract the left-most vertical line */
      if ((path_locations[condition_0] < ii) && (path_locations[condition_0] !=
           0.0)) {
        /* '<S60>:1:176' */
        /* '<S60>:1:177' */
        ii = path_locations[condition_0];

        /* '<S60>:1:178' */
        rtb_path_headings_idx_1 = path_locations[condition_0];

        /* '<S60>:1:179' */
        L_black = tavgv[condition_0];
      }

      /*  Extract the right-most vertical line */
      if ((path_locations[condition_0] > jj) && (path_locations[condition_0] !=
           0.0)) {
        /* '<S60>:1:183' */
        /* '<S60>:1:184' */
        jj = path_locations[condition_0];

        /* '<S60>:1:185' */
        rtb_path_headings_idx = path_locations[condition_0];

        /* '<S60>:1:186' */
        rtb_theta_gate_idx = tavgv[condition_0];
      }
    }

    /*  Check that the distance between the vertical lines is much greater than */
    /*    the minimum expected distance, eps_rho */
    if (fabs(rtb_path_headings_idx - rtb_path_headings_idx_1) < 32.0) {
      /* '<S60>:1:193' */
      /* '<S60>:1:194' */
      rtb_path_headings_idx_1 = 0.0;

      /* '<S60>:1:195' */
      rtb_path_headings_idx = 0.0;

      /* '<S60>:1:196' */
      L_black = 0.0;

      /* '<S60>:1:197' */
      rtb_theta_gate_idx = 0.0;
    }

    /* rmin = 10000; */
    /* '<S60>:1:201' */
    ii = 0.0;

    /* '<S60>:1:202' */
    for (condition_0 = 0; condition_0 < 6; condition_0++) {
      /* '<S60>:1:202' */
      /*  Extract the horizontal line with the most votes */
      if ((vbinh[condition_0] > ii) && (ravgh[condition_0] != 0.0)) {
        /* '<S60>:1:205' */
        /* '<S60>:1:206' */
        ii = vbinh[condition_0];

        /* '<S60>:1:207' */
        rtb_path_headings_idx_0 = ravgh[condition_0];

        /* '<S60>:1:208' */
        positive_area = tavgh[condition_0];
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
    /* '<S60>:1:222' */
    ii = (rtb_path_headings_idx_1 / cos(L_black) - rtb_path_headings_idx_0 / cos
          (positive_area)) * (1.0 / (tan(L_black) - tan(positive_area)));

    /* '<S60>:1:223' */
    jj = (rtb_path_headings_idx_1 - ii * sin(L_black)) * (1.0 / cos(L_black));

    /* '<S60>:1:225' */
    r = (rtb_path_headings_idx_0 / cos(positive_area) - rtb_path_headings_idx /
         cos(rtb_theta_gate_idx)) * (1.0 / (tan(positive_area) - tan
      (rtb_theta_gate_idx)));

    /* '<S60>:1:226' */
    c = (rtb_path_headings_idx_0 - r * sin(positive_area)) * (1.0 / cos
      (positive_area));

    /* '<S60>:1:228' */
    /* '<S60>:1:229' */
    /*  Compute gate width */
    /* '<S60>:1:232' */
    /*  Form unit vector pointing downward, parallel to gate posts */
    /* '<S60>:1:235' */
    /* '<S60>:1:236' */
    u[0] = 1.0;
    u[1] = tan((((positive_area - 1.5707963267948966) + L_black) +
                rtb_theta_gate_idx) / 3.0);

    /* '<S60>:1:237' */
    maxL = VisionModel_norm(u);
    u[0] = 1.0 / maxL;
    u[1] = u[1] / maxL;

    /*  Compute target location */
    /* '<S60>:1:240' */
    maxL = sqrt(rt_pow_snf(r - ii, 2.0) + rt_pow_snf(c - jj, 2.0)) *
      (VisionModel_P.Constant1_Value * VisionModel_P.Constant2_Value);

    /* '<S60>:1:241' */
    /* '<S60>:1:242' */
    /*  Determine if a gate is present (very simple, potentially inaccurate) */
    value[0] = (real_T)(rtb_path_headings_idx_1 == 0.0) + (real_T)(L_black ==
      0.0);
    value[1] = (real_T)(rtb_path_headings_idx_0 == 0.0) + (real_T)(positive_area
      == 0.0);
    value[2] = (real_T)(rtb_path_headings_idx == 0.0) + (real_T)
      (rtb_theta_gate_idx == 0.0);
    if (VisionModel_sum_k(value) > 0.0) {
      /* '<S60>:1:245' */
      /* '<S60>:1:247' */
      condition_0 = 0;

      /* '<S60>:1:248' */
      VisionModel_B.target_z_o = 0.0;

      /* '<S60>:1:249' */
      ii = 0.0;

      /* '<S60>:1:250' */
      VisionModel_B.target_yaw_o = 0.0;
    } else {
      /* '<S60>:1:254' */
      condition_0 = 1;

      /*  Transform target r, c to global coordinate system */
      /* '<S60>:1:257' */
      VisionModel_B.target_z_o = ((ii + r) / 2.0 + maxL * u[0]) - 80.0;

      /* '<S60>:1:258' */
      ii = ((jj + c) / 2.0 + maxL * u[1]) - 60.0;

      /* '<S60>:1:259' */
      VisionModel_B.target_yaw_o = ii / 120.0 * VisionModel_P.Forward_Fov_Value;
    }

    VisionModel_B.target_y_c = ii;
    VisionModel_B.gate_found = (real_T)condition_0;

    /* If: '<S14>/If1' incorporates:
     *  ActionPort: '<S61>/Action Port'
     *  Inport: '<Root>/OutputImage'
     *  SubSystem: '<S14>/If Action Subsystem'
     */
    if (VisionModel_U.OutputImage > 0.0) {
      /* Embedded MATLAB: '<S61>/Transform Coordinates3' */
      VisionMod_TransformCoordinates3(VisionModel_P.which_camera_Value, 0.0,
        VisionModel_B.target_y_c, VisionModel_B.target_z_o,
        VisionModel_P.Forward_Camera_Dimensions1_Valu,
        &VisionModel_B.sf_TransformCoordinates3);

      /* S-Function (svipdrawmarkers): '<S61>/Draw Target' */
      /* Copy the image from input to output. */
      for (i = 0; i < 19200; i++) {
        VisionModel_B.Divide5[i] = VisionModel_B.bw_image_e[i];
        VisionModel_B.Divide4[i] = VisionModel_B.bw_image_e[i];
        VisionModel_B.Divide3[i] = VisionModel_B.bw_image_e[i];
      }

      /* Draw all X marks. */
      i_gate_idx = VisionModel_P.DrawTarget_RTP_SIZE;
      if ((VisionModel_P.DrawTarget_RTP_SIZE < 4.503599627370496E+15) &&
          (VisionModel_P.DrawTarget_RTP_SIZE > -4.503599627370496E+15)) {
        i_gate_idx = floor(VisionModel_P.DrawTarget_RTP_SIZE + 0.5);
      }

      imgCol = (int32_T)i_gate_idx;
      for (idxROI = 0; idxROI < 2; idxROI += 2) {
        i_gate_idx = VisionModel_B.sf_TransformCoordinates3.points[idxROI];
        if ((VisionModel_B.sf_TransformCoordinates3.points[idxROI] <
             4.503599627370496E+15) &&
            (VisionModel_B.sf_TransformCoordinates3.points[idxROI] >
             -4.503599627370496E+15)) {
          i_gate_idx = floor
            (VisionModel_B.sf_TransformCoordinates3.points[idxROI] + 0.5);
        }

        imgIdxLR = (int32_T)i_gate_idx;
        i_gate_idx = VisionModel_B.sf_TransformCoordinates3.points[idxROI + 1];
        if ((VisionModel_B.sf_TransformCoordinates3.points[idxROI + 1] <
             4.503599627370496E+15) &&
            (VisionModel_B.sf_TransformCoordinates3.points[idxROI + 1] >
             -4.503599627370496E+15)) {
          i_gate_idx = floor
            (VisionModel_B.sf_TransformCoordinates3.points[idxROI + 1] + 0.5);
        }

        col = (int32_T)i_gate_idx;
        line_idx_5 = imgIdxLR - imgCol;
        line_idx_3 = col - imgCol;
        line_idx_1 = imgIdxLR + imgCol;
        line_idx = col + imgCol;
        condition = FALSE;

        /* Find the visible portion of a line. */
        exitg_0 = FALSE;
        exitg = FALSE;
        c_0 = FALSE;
        numElem = line_idx_5;
        line_idx_4 = line_idx_3;
        line_idx_2 = line_idx_1;
        line_idx_0 = line_idx;
        while (!c_0) {
          i = 0;
          find_white = 0;

          /* Determine viewport violations. */
          if (numElem < 0) {
            i = 4;
          } else {
            if (numElem > 159) {
              i = 8;
            }
          }

          if (line_idx_2 < 0) {
            find_white = 4;
          } else {
            if (line_idx_2 > 159) {
              find_white = 8;
            }
          }

          if (line_idx_4 < 0) {
            i = (int32_T)((uint32_T)i | 1U);
          } else {
            if (line_idx_4 > 119) {
              i = (int32_T)((uint32_T)i | 2U);
            }
          }

          if (line_idx_0 < 0) {
            find_white = (int32_T)((uint32_T)find_white | 1U);
          } else {
            if (line_idx_0 > 119) {
              find_white = (int32_T)((uint32_T)find_white | 2U);
            }
          }

          if (!((uint32_T)i | (uint32_T)find_white)) {
            /* Line falls completely within bounds. */
            c_0 = TRUE;
            condition = TRUE;
          } else if ((uint32_T)i & (uint32_T)find_white) {
            /* Line falls completely out of bounds. */
            c_0 = TRUE;
            condition = FALSE;
          } else if ((uint32_T)i != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (exitg_0) {
              numElem = line_idx_5;
              line_idx_4 = line_idx_3;
            }

            condition_0 = line_idx_2 - numElem;
            current_color = line_idx_0 - line_idx_4;
            if ((uint32_T)i & 4U) {
              /* Violated RMin. */
              find_white = (0 - numElem) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_4 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              numElem = 0;
              exitg_0 = TRUE;
            } else if ((uint32_T)i & 8U) {
              /* Violated RMax. */
              find_white = (159 - numElem) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_4 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              numElem = 159;
              exitg_0 = TRUE;
            } else if ((uint32_T)i & 1U) {
              /* Violated CMin. */
              find_white = (0 - line_idx_4) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                numElem += (div_s32_floor(find_white << 1U, current_color) + 1) >>
                  1;
              } else {
                numElem += -((div_s32_floor((-find_white) << 1U, current_color)
                              + 1) >> 1);
              }

              line_idx_4 = 0;
              exitg_0 = TRUE;
            } else {
              /* Violated CMax. */
              find_white = (119 - line_idx_4) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                numElem += (div_s32_floor(find_white << 1U, current_color) + 1) >>
                  1;
              } else {
                numElem += -((div_s32_floor((-find_white) << 1U, current_color)
                              + 1) >> 1);
              }

              line_idx_4 = 119;
              exitg_0 = TRUE;
            }
          } else {
            /* Clip the 2nd point. */
            if (exitg) {
              line_idx_2 = line_idx_1;
              line_idx_0 = line_idx;
            }

            condition_0 = line_idx_2 - numElem;
            current_color = line_idx_0 - line_idx_4;
            if ((uint32_T)find_white & 4U) {
              /* Violated RMin. */
              find_white = (0 - line_idx_2) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_0 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_0 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              line_idx_2 = 0;
              exitg = TRUE;
            } else if ((uint32_T)find_white & 8U) {
              /* Violated RMax. */
              find_white = (159 - line_idx_2) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_0 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_0 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              line_idx_2 = 159;
              exitg = TRUE;
            } else if ((uint32_T)find_white & 1U) {
              /* Violated CMin. */
              find_white = (0 - line_idx_0) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                line_idx_2 += (div_s32_floor(find_white << 1U, current_color) +
                               1) >> 1;
              } else {
                line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                  current_color) + 1) >> 1);
              }

              line_idx_0 = 0;
              exitg = TRUE;
            } else {
              /* Violated CMax. */
              find_white = (119 - line_idx_0) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                line_idx_2 += (div_s32_floor(find_white << 1U, current_color) +
                               1) >> 1;
              } else {
                line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                  current_color) + 1) >> 1);
              }

              line_idx_0 = 119;
              exitg = TRUE;
            }
          }
        }

        if (condition) {
          current_color = line_idx_4 * 160 + numElem;
          while (numElem <= line_idx_2) {
            VisionModel_B.Divide5[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[0];
            VisionModel_B.Divide4[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[1];
            VisionModel_B.Divide3[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[2];
            current_color += 161;
            numElem++;
          }
        }

        line_idx_5 = imgIdxLR - imgCol;
        line_idx_3 = col + imgCol;
        line_idx_1 = imgIdxLR + imgCol;
        line_idx = col - imgCol;
        condition = FALSE;

        /* Find the visible portion of a line. */
        exitg_0 = FALSE;
        exitg = FALSE;
        c_0 = FALSE;
        numElem = line_idx_5;
        line_idx_4 = line_idx_3;
        line_idx_2 = line_idx_1;
        line_idx_0 = line_idx;
        while (!c_0) {
          i = 0;
          find_white = 0;

          /* Determine viewport violations. */
          if (numElem < 0) {
            i = 4;
          } else {
            if (numElem > 159) {
              i = 8;
            }
          }

          if (line_idx_2 < 0) {
            find_white = 4;
          } else {
            if (line_idx_2 > 159) {
              find_white = 8;
            }
          }

          if (line_idx_4 < 0) {
            i = (int32_T)((uint32_T)i | 1U);
          } else {
            if (line_idx_4 > 119) {
              i = (int32_T)((uint32_T)i | 2U);
            }
          }

          if (line_idx_0 < 0) {
            find_white = (int32_T)((uint32_T)find_white | 1U);
          } else {
            if (line_idx_0 > 119) {
              find_white = (int32_T)((uint32_T)find_white | 2U);
            }
          }

          if (!((uint32_T)i | (uint32_T)find_white)) {
            /* Line falls completely within bounds. */
            c_0 = TRUE;
            condition = TRUE;
          } else if ((uint32_T)i & (uint32_T)find_white) {
            /* Line falls completely out of bounds. */
            c_0 = TRUE;
            condition = FALSE;
          } else if ((uint32_T)i != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (exitg_0) {
              numElem = line_idx_5;
              line_idx_4 = line_idx_3;
            }

            condition_0 = line_idx_2 - numElem;
            current_color = line_idx_0 - line_idx_4;
            if ((uint32_T)i & 4U) {
              /* Violated RMin. */
              find_white = (0 - numElem) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_4 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              numElem = 0;
              exitg_0 = TRUE;
            } else if ((uint32_T)i & 8U) {
              /* Violated RMax. */
              find_white = (159 - numElem) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_4 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_4 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              numElem = 159;
              exitg_0 = TRUE;
            } else if ((uint32_T)i & 1U) {
              /* Violated CMin. */
              find_white = (0 - line_idx_4) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                numElem += (div_s32_floor(find_white << 1U, current_color) + 1) >>
                  1;
              } else {
                numElem += -((div_s32_floor((-find_white) << 1U, current_color)
                              + 1) >> 1);
              }

              line_idx_4 = 0;
              exitg_0 = TRUE;
            } else {
              /* Violated CMax. */
              find_white = (119 - line_idx_4) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                numElem += (div_s32_floor(find_white << 1U, current_color) + 1) >>
                  1;
              } else {
                numElem += -((div_s32_floor((-find_white) << 1U, current_color)
                              + 1) >> 1);
              }

              line_idx_4 = 119;
              exitg_0 = TRUE;
            }
          } else {
            /* Clip the 2nd point. */
            if (exitg) {
              line_idx_2 = line_idx_1;
              line_idx_0 = line_idx;
            }

            condition_0 = line_idx_2 - numElem;
            current_color = line_idx_0 - line_idx_4;
            if ((uint32_T)find_white & 4U) {
              /* Violated RMin. */
              find_white = (0 - line_idx_2) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_0 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_0 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              line_idx_2 = 0;
              exitg = TRUE;
            } else if ((uint32_T)find_white & 8U) {
              /* Violated RMax. */
              find_white = (159 - line_idx_2) * current_color;
              if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white < 0)
                   && (condition_0 < 0))) {
                line_idx_0 += (div_s32_floor(find_white << 1U, condition_0) + 1)
                  >> 1;
              } else {
                line_idx_0 += -((div_s32_floor((-find_white) << 1U, condition_0)
                                 + 1) >> 1);
              }

              line_idx_2 = 159;
              exitg = TRUE;
            } else if ((uint32_T)find_white & 1U) {
              /* Violated CMin. */
              find_white = (0 - line_idx_0) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                line_idx_2 += (div_s32_floor(find_white << 1U, current_color) +
                               1) >> 1;
              } else {
                line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                  current_color) + 1) >> 1);
              }

              line_idx_0 = 0;
              exitg = TRUE;
            } else {
              /* Violated CMax. */
              find_white = (119 - line_idx_0) * condition_0;
              if (((find_white >= 0) && (current_color >= 0)) || ((find_white <
                    0) && (current_color < 0))) {
                line_idx_2 += (div_s32_floor(find_white << 1U, current_color) +
                               1) >> 1;
              } else {
                line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                  current_color) + 1) >> 1);
              }

              line_idx_0 = 119;
              exitg = TRUE;
            }
          }
        }

        if (condition) {
          current_color = line_idx_4 * 160 + numElem;
          while (numElem <= line_idx_2) {
            VisionModel_B.Divide5[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[0];
            VisionModel_B.Divide4[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[1];
            VisionModel_B.Divide3[current_color] =
              VisionModel_P.DrawTarget_RTP_FILLCOLOR[2];
            current_color += -159;
            numElem++;
          }
        }
      }

      /* S-Function (sviphoughlines): '<S61>/Hough Lines' */
      numElem = 0;
      ii = (rtb_path_headings_idx_1 + 2.2204460492503131E-16) / (cos(L_black) +
        2.2204460492503131E-16);

      /* part-1: top horizontal axis */
      jj = floor(ii + 0.5);
      if ((jj >= 0.0) && (jj <= 119.0)) {
        VisionModel_B.HoughLines[0] = 0;
        VisionModel_B.HoughLines[1] = (int32_T)floor((real_T)(int32_T)jj + 0.5);
        numElem = 1;
      }

      minL = (rtb_path_headings_idx_1 + 2.2204460492503131E-16) / (sin(L_black)
        + 2.2204460492503131E-16);

      /* part-2: left vertical axis */
      jj = floor(minL + 0.5);
      if ((jj >= 0.0) && (jj <= 159.0)) {
        VisionModel_B.HoughLines[(numElem << 1)] = (int32_T)floor((real_T)
          (int32_T)jj + 0.5);
        VisionModel_B.HoughLines[1 + (numElem << 1)] = 0;
        numElem++;
      }

      /* part-3: Right vertical axis */
      if (numElem < 2) {
        jj = floor((ii - 119.0) * (minL / ii) + 0.5);
        if ((jj >= 0.0) && (jj <= 159.0)) {
          VisionModel_B.HoughLines[(numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          VisionModel_B.HoughLines[1 + (numElem << 1)] = 119;
          numElem++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (numElem < 2) {
        jj = floor((ii - ii / minL * 159.0) + 0.5);
        if ((jj >= 0.0) && (jj <= 119.0)) {
          VisionModel_B.HoughLines[(numElem << 1)] = 159;
          VisionModel_B.HoughLines[1 + (numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          numElem++;
        }
      }

      if (numElem < 2) {
        VisionModel_B.HoughLines[0] = -1;
        VisionModel_B.HoughLines[1] = -1;
        VisionModel_B.HoughLines[2] = -1;
        VisionModel_B.HoughLines[3] = -1;
      }

      numElem = 0;
      ii = (rtb_path_headings_idx_0 + 2.2204460492503131E-16) / (cos
        (positive_area) + 2.2204460492503131E-16);

      /* part-1: top horizontal axis */
      jj = floor(ii + 0.5);
      if ((jj >= 0.0) && (jj <= 119.0)) {
        VisionModel_B.HoughLines[4] = 0;
        VisionModel_B.HoughLines[5] = (int32_T)floor((real_T)(int32_T)jj + 0.5);
        numElem = 1;
      }

      minL = (rtb_path_headings_idx_0 + 2.2204460492503131E-16) / (sin
        (positive_area) + 2.2204460492503131E-16);

      /* part-2: left vertical axis */
      jj = floor(minL + 0.5);
      if ((jj >= 0.0) && (jj <= 159.0)) {
        VisionModel_B.HoughLines[4 + (numElem << 1)] = (int32_T)floor((real_T)
          (int32_T)jj + 0.5);
        VisionModel_B.HoughLines[5 + (numElem << 1)] = 0;
        numElem++;
      }

      /* part-3: Right vertical axis */
      if (numElem < 2) {
        jj = floor((ii - 119.0) * (minL / ii) + 0.5);
        if ((jj >= 0.0) && (jj <= 159.0)) {
          VisionModel_B.HoughLines[4 + (numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          VisionModel_B.HoughLines[5 + (numElem << 1)] = 119;
          numElem++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (numElem < 2) {
        jj = floor((ii - ii / minL * 159.0) + 0.5);
        if ((jj >= 0.0) && (jj <= 119.0)) {
          VisionModel_B.HoughLines[4 + (numElem << 1)] = 159;
          VisionModel_B.HoughLines[5 + (numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          numElem++;
        }
      }

      if (numElem < 2) {
        VisionModel_B.HoughLines[4] = -1;
        VisionModel_B.HoughLines[5] = -1;
        VisionModel_B.HoughLines[6] = -1;
        VisionModel_B.HoughLines[7] = -1;
      }

      numElem = 0;
      ii = (rtb_path_headings_idx + 2.2204460492503131E-16) / (cos
        (rtb_theta_gate_idx) + 2.2204460492503131E-16);

      /* part-1: top horizontal axis */
      jj = floor(ii + 0.5);
      if ((jj >= 0.0) && (jj <= 119.0)) {
        VisionModel_B.HoughLines[8] = 0;
        VisionModel_B.HoughLines[9] = (int32_T)floor((real_T)(int32_T)jj + 0.5);
        numElem = 1;
      }

      minL = (rtb_path_headings_idx + 2.2204460492503131E-16) / (sin
        (rtb_theta_gate_idx) + 2.2204460492503131E-16);

      /* part-2: left vertical axis */
      jj = floor(minL + 0.5);
      if ((jj >= 0.0) && (jj <= 159.0)) {
        VisionModel_B.HoughLines[8 + (numElem << 1)] = (int32_T)floor((real_T)
          (int32_T)jj + 0.5);
        VisionModel_B.HoughLines[9 + (numElem << 1)] = 0;
        numElem++;
      }

      /* part-3: Right vertical axis */
      if (numElem < 2) {
        jj = floor((ii - 119.0) * (minL / ii) + 0.5);
        if ((jj >= 0.0) && (jj <= 159.0)) {
          VisionModel_B.HoughLines[8 + (numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          VisionModel_B.HoughLines[9 + (numElem << 1)] = 119;
          numElem++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (numElem < 2) {
        jj = floor((ii - ii / minL * 159.0) + 0.5);
        if ((jj >= 0.0) && (jj <= 119.0)) {
          VisionModel_B.HoughLines[8 + (numElem << 1)] = 159;
          VisionModel_B.HoughLines[9 + (numElem << 1)] = (int32_T)floor((real_T)
            (int32_T)jj + 0.5);
          numElem++;
        }
      }

      if (numElem < 2) {
        VisionModel_B.HoughLines[8] = -1;
        VisionModel_B.HoughLines[9] = -1;
        VisionModel_B.HoughLines[10] = -1;
        VisionModel_B.HoughLines[11] = -1;
      }

      /* S-Function (svipdrawshapes): '<S61>/Draw Shapes' */
      /* Copy the image from input to output. */
      for (i = 0; i < 19200; i++) {
        VisionModel_B.DrawShapes_o1[i] = VisionModel_B.Divide5[i];
        VisionModel_B.DrawShapes_o2[i] = VisionModel_B.Divide4[i];
        VisionModel_B.DrawShapes_o3[i] = VisionModel_B.Divide3[i];
      }

      idxStart = 0;
      for (idxROI = 0; idxROI < 3; idxROI++) {
        for (i = 0; i < 1; i = 1) {
          line_idx_5 = VisionModel_B.HoughLines[idxStart];
          line_idx_3 = VisionModel_B.HoughLines[idxStart + 1];
          line_idx_1 = VisionModel_B.HoughLines[idxStart + 2];
          line_idx = VisionModel_B.HoughLines[idxStart + 3];
          if ((VisionModel_B.HoughLines[idxStart + 2] !=
               VisionModel_B.HoughLines[idxStart]) ||
              (VisionModel_B.HoughLines[idxStart + 1] !=
               VisionModel_B.HoughLines[idxStart + 3])) {
            condition = FALSE;

            /* Find the visible portion of a line. */
            exitg_0 = FALSE;
            exitg = FALSE;
            c_0 = FALSE;
            find_black = VisionModel_B.HoughLines[idxStart];
            line_idx_4 = VisionModel_B.HoughLines[idxStart + 1];
            line_idx_2 = VisionModel_B.HoughLines[idxStart + 2];
            line_idx_0 = VisionModel_B.HoughLines[idxStart + 3];
            while (!c_0) {
              i = 0;
              find_white = 0;

              /* Determine viewport violations. */
              if (find_black < 0) {
                i = 4;
              } else {
                if (find_black > 159) {
                  i = 8;
                }
              }

              if (line_idx_2 < 0) {
                find_white = 4;
              } else {
                if (line_idx_2 > 159) {
                  find_white = 8;
                }
              }

              if (line_idx_4 < 0) {
                i = (int32_T)((uint32_T)i | 1U);
              } else {
                if (line_idx_4 > 119) {
                  i = (int32_T)((uint32_T)i | 2U);
                }
              }

              if (line_idx_0 < 0) {
                find_white = (int32_T)((uint32_T)find_white | 1U);
              } else {
                if (line_idx_0 > 119) {
                  find_white = (int32_T)((uint32_T)find_white | 2U);
                }
              }

              if (!((uint32_T)i | (uint32_T)find_white)) {
                /* Line falls completely within bounds. */
                c_0 = TRUE;
                condition = TRUE;
              } else if ((uint32_T)i & (uint32_T)find_white) {
                /* Line falls completely out of bounds. */
                c_0 = TRUE;
                condition = FALSE;
              } else if ((uint32_T)i != 0U) {
                /* Clip 1st point; if it's in-bounds, clip 2nd point. */
                if (exitg_0) {
                  find_black = line_idx_5;
                  line_idx_4 = line_idx_3;
                }

                condition_0 = line_idx_2 - find_black;
                current_color = line_idx_0 - line_idx_4;
                if ((uint32_T)i & 4U) {
                  /* Violated RMin. */
                  find_white = (0 - find_black) * current_color;
                  if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white <
                        0) && (condition_0 < 0))) {
                    line_idx_4 += (div_s32_floor(find_white << 1U, condition_0)
                                   + 1) >> 1;
                  } else {
                    line_idx_4 += -((div_s32_floor((-find_white) << 1U,
                      condition_0) + 1) >> 1);
                  }

                  find_black = 0;
                  exitg_0 = TRUE;
                } else if ((uint32_T)i & 8U) {
                  /* Violated RMax. */
                  find_white = (159 - find_black) * current_color;
                  if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white <
                        0) && (condition_0 < 0))) {
                    line_idx_4 += (div_s32_floor(find_white << 1U, condition_0)
                                   + 1) >> 1;
                  } else {
                    line_idx_4 += -((div_s32_floor((-find_white) << 1U,
                      condition_0) + 1) >> 1);
                  }

                  find_black = 159;
                  exitg_0 = TRUE;
                } else if ((uint32_T)i & 1U) {
                  /* Violated CMin. */
                  find_white = (0 - line_idx_4) * condition_0;
                  if (((find_white >= 0) && (current_color >= 0)) ||
                      ((find_white < 0) && (current_color < 0))) {
                    find_black += (div_s32_floor(find_white << 1U, current_color)
                                   + 1) >> 1;
                  } else {
                    find_black += -((div_s32_floor((-find_white) << 1U,
                      current_color) + 1) >> 1);
                  }

                  line_idx_4 = 0;
                  exitg_0 = TRUE;
                } else {
                  /* Violated CMax. */
                  find_white = (119 - line_idx_4) * condition_0;
                  if (((find_white >= 0) && (current_color >= 0)) ||
                      ((find_white < 0) && (current_color < 0))) {
                    find_black += (div_s32_floor(find_white << 1U, current_color)
                                   + 1) >> 1;
                  } else {
                    find_black += -((div_s32_floor((-find_white) << 1U,
                      current_color) + 1) >> 1);
                  }

                  line_idx_4 = 119;
                  exitg_0 = TRUE;
                }
              } else {
                /* Clip the 2nd point. */
                if (exitg) {
                  line_idx_2 = line_idx_1;
                  line_idx_0 = line_idx;
                }

                condition_0 = line_idx_2 - find_black;
                current_color = line_idx_0 - line_idx_4;
                if ((uint32_T)find_white & 4U) {
                  /* Violated RMin. */
                  find_white = (0 - line_idx_2) * current_color;
                  if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white <
                        0) && (condition_0 < 0))) {
                    line_idx_0 += (div_s32_floor(find_white << 1U, condition_0)
                                   + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-find_white) << 1U,
                      condition_0) + 1) >> 1);
                  }

                  line_idx_2 = 0;
                  exitg = TRUE;
                } else if ((uint32_T)find_white & 8U) {
                  /* Violated RMax. */
                  find_white = (159 - line_idx_2) * current_color;
                  if (((find_white >= 0) && (condition_0 >= 0)) || ((find_white <
                        0) && (condition_0 < 0))) {
                    line_idx_0 += (div_s32_floor(find_white << 1U, condition_0)
                                   + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-find_white) << 1U,
                      condition_0) + 1) >> 1);
                  }

                  line_idx_2 = 159;
                  exitg = TRUE;
                } else if ((uint32_T)find_white & 1U) {
                  /* Violated CMin. */
                  find_white = (0 - line_idx_0) * condition_0;
                  if (((find_white >= 0) && (current_color >= 0)) ||
                      ((find_white < 0) && (current_color < 0))) {
                    line_idx_2 += (div_s32_floor(find_white << 1U, current_color)
                                   + 1) >> 1;
                  } else {
                    line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                      current_color) + 1) >> 1);
                  }

                  line_idx_0 = 0;
                  exitg = TRUE;
                } else {
                  /* Violated CMax. */
                  find_white = (119 - line_idx_0) * condition_0;
                  if (((find_white >= 0) && (current_color >= 0)) ||
                      ((find_white < 0) && (current_color < 0))) {
                    line_idx_2 += (div_s32_floor(find_white << 1U, current_color)
                                   + 1) >> 1;
                  } else {
                    line_idx_2 += -((div_s32_floor((-find_white) << 1U,
                      current_color) + 1) >> 1);
                  }

                  line_idx_0 = 119;
                  exitg = TRUE;
                }
              }
            }

            if (condition) {
              /* Draw a line using Bresenham algorithm. */
              /* Initialize the Bresenham algorithm. */
              if (line_idx_2 >= find_black) {
                current_color = line_idx_2 - find_black;
              } else {
                current_color = find_black - line_idx_2;
              }

              if (line_idx_0 >= line_idx_4) {
                condition_0 = line_idx_0 - line_idx_4;
              } else {
                condition_0 = line_idx_4 - line_idx_0;
              }

              if (current_color > condition_0) {
                col = 1;
                current_color = 160;
              } else {
                col = 160;
                current_color = 1;
                condition_0 = find_black;
                find_black = line_idx_4;
                line_idx_4 = condition_0;
                condition_0 = line_idx_2;
                line_idx_2 = line_idx_0;
                line_idx_0 = condition_0;
              }

              if (find_black > line_idx_2) {
                condition_0 = find_black;
                find_black = line_idx_2;
                line_idx_2 = condition_0;
                condition_0 = line_idx_4;
                line_idx_4 = line_idx_0;
                line_idx_0 = condition_0;
              }

              imgCol = line_idx_2 - find_black;
              if (line_idx_4 <= line_idx_0) {
                condition_0 = 1;
                find_white = line_idx_0 - line_idx_4;
              } else {
                condition_0 = -1;
                find_white = line_idx_4 - line_idx_0;
              }

              numElem = -((imgCol + 1) >> 1);
              imgIdxLR = find_black * col + line_idx_4 * current_color;
              condition_0 = condition_0 * current_color + col;
              for (condition = (find_black <= line_idx_2); condition; condition =
                   (find_black <= line_idx_2)) {
                VisionModel_B.DrawShapes_o1[imgIdxLR] =
                  VisionModel_ConstP.DrawShapes_RTP_FILLCO[0];
                VisionModel_B.DrawShapes_o2[imgIdxLR] =
                  VisionModel_ConstP.DrawShapes_RTP_FILLCO[1];
                VisionModel_B.DrawShapes_o3[imgIdxLR] =
                  VisionModel_ConstP.DrawShapes_RTP_FILLCO[2];

                /* Compute the next location using Bresenham algorithm. */
                /* Move to the next pixel location. */
                numElem += find_white;
                if (numElem >= 0) {
                  numElem -= imgCol;
                  imgIdxLR += condition_0;
                } else {
                  imgIdxLR += col;
                }

                find_black++;
              }
            }
          }

          idxStart += 2;
        }

        idxStart += 2;
      }
    }

    /* Constant: '<S14>/Constant3' */
    VisionModel_B.Constant3 = VisionModel_P.Constant3_Value;
  } else if (VisionModel_U.ModeSelect == 2.0) {
    /* S-Function (svipedge): '<S12>/Edge Detection' */
    for (imgCol = 1; imgCol < 2; imgCol = 2) {
      for (current_color = 1; current_color < 2; current_color = 2) {
        ii = 0.0;
        jj = 0.0;
        for (col = 0; col < 6; col++) {
          ii += VisionModel_B.bw_image[4 +
            VisionModel_DWork.EdgeDetection_VO_DW[col]] *
            VisionModel_ConstP.pooled7[col];
          jj += VisionModel_B.bw_image[4 +
            VisionModel_DWork.EdgeDetection_HO_DW[col]] *
            VisionModel_ConstP.pooled8[col];
        }

        EdgeDetection_GV_SQUARED_DW[4] = ii * ii;
        EdgeDetection_GH_SQUARED_DW[4] = jj * jj;
      }
    }

    for (imgCol = 1; imgCol < 2; imgCol = 2) {
      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      for (col = 0; col < 6; col++) {
        ii += VisionModel_B.bw_image[3 +
          VisionModel_DWork.EdgeDetection_HOU_DW[col]] *
          VisionModel_ConstP.pooled8[col];
        jj += VisionModel_B.bw_image[5 +
          VisionModel_DWork.EdgeDetection_HOD_DW[col]] *
          VisionModel_ConstP.pooled8[col];
        minL += VisionModel_B.bw_image[3 +
          VisionModel_DWork.EdgeDetection_VOU_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        maxL += VisionModel_B.bw_image[5 +
          VisionModel_DWork.EdgeDetection_VOD_DW[col]] *
          VisionModel_ConstP.pooled7[col];
      }

      EdgeDetection_GV_SQUARED_DW[3] = minL * minL;
      EdgeDetection_GH_SQUARED_DW[3] = ii * ii;
      EdgeDetection_GV_SQUARED_DW[5] = maxL * maxL;
      EdgeDetection_GH_SQUARED_DW[5] = jj * jj;
    }

    for (current_color = 1; current_color < 2; current_color = 2) {
      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      for (col = 0; col < 6; col++) {
        ii += VisionModel_B.bw_image[1 +
          VisionModel_DWork.EdgeDetection_VOL_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        jj += VisionModel_B.bw_image[7 +
          VisionModel_DWork.EdgeDetection_VOR_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        minL += VisionModel_B.bw_image[1 +
          VisionModel_DWork.EdgeDetection_HOL_DW[col]] *
          VisionModel_ConstP.pooled8[col];
        maxL += VisionModel_B.bw_image[7 +
          VisionModel_DWork.EdgeDetection_HOR_DW[col]] *
          VisionModel_ConstP.pooled8[col];
      }

      EdgeDetection_GV_SQUARED_DW[1] = ii * ii;
      EdgeDetection_GH_SQUARED_DW[1] = minL * minL;
      EdgeDetection_GV_SQUARED_DW[7] = jj * jj;
      EdgeDetection_GH_SQUARED_DW[7] = maxL * maxL;
    }

    ii = 0.0;
    jj = 0.0;
    minL = 0.0;
    maxL = 0.0;
    for (col = 0; col < 6; col++) {
      ii += VisionModel_B.bw_image[VisionModel_DWork.EdgeDetection_VOUL_DW[col]]
        * VisionModel_ConstP.pooled7[col];
      jj += VisionModel_B.bw_image[VisionModel_DWork.EdgeDetection_HOUL_DW[col]]
        * VisionModel_ConstP.pooled8[col];
      minL += VisionModel_B.bw_image[2 +
        VisionModel_DWork.EdgeDetection_VOLL_DW[col]] *
        VisionModel_ConstP.pooled7[col];
      maxL += VisionModel_B.bw_image[2 +
        VisionModel_DWork.EdgeDetection_HOLL_DW[col]] *
        VisionModel_ConstP.pooled8[col];
    }

    EdgeDetection_GV_SQUARED_DW[0] = ii * ii;
    EdgeDetection_GH_SQUARED_DW[0] = jj * jj;
    EdgeDetection_GV_SQUARED_DW[2] = minL * minL;
    EdgeDetection_GH_SQUARED_DW[2] = maxL * maxL;
    ii = 0.0;
    jj = 0.0;
    minL = 0.0;
    maxL = 0.0;
    for (col = 0; col < 6; col++) {
      ii += VisionModel_B.bw_image[6 +
        VisionModel_DWork.EdgeDetection_VOUR_DW[col]] *
        VisionModel_ConstP.pooled7[col];
      jj += VisionModel_B.bw_image[6 +
        VisionModel_DWork.EdgeDetection_HOUR_DW[col]] *
        VisionModel_ConstP.pooled8[col];
      minL += VisionModel_B.bw_image[8 +
        VisionModel_DWork.EdgeDetection_VOLR_DW[col]] *
        VisionModel_ConstP.pooled7[col];
      maxL += VisionModel_B.bw_image[8 +
        VisionModel_DWork.EdgeDetection_HOLR_DW[col]] *
        VisionModel_ConstP.pooled8[col];
    }

    EdgeDetection_GV_SQUARED_DW[6] = ii * ii;
    EdgeDetection_GH_SQUARED_DW[6] = jj * jj;
    EdgeDetection_GV_SQUARED_DW[8] = minL * minL;
    EdgeDetection_GH_SQUARED_DW[8] = maxL * maxL;
    jj = 0.0;
    for (col = 0; col < 9; col++) {
      EdgeDetection_GRAD_SUM_DW[col] = EdgeDetection_GV_SQUARED_DW[col];
      EdgeDetection_GRAD_SUM_DW[col] = EdgeDetection_GRAD_SUM_DW[col] +
        EdgeDetection_GH_SQUARED_DW[col];
      jj += EdgeDetection_GRAD_SUM_DW[col] *
        VisionModel_DWork.EdgeDetection_MEAN_FACTOR_DW;
    }

    ii = VisionModel_P.EdgeDetection_THRESH_TUNING_R_h * jj;
    for (imgCol = 0; imgCol < 3; imgCol++) {
      col = imgCol * 3;
      VisionModel_B.EdgeDetection[col] = ((EdgeDetection_GRAD_SUM_DW[col] > ii) &&
        (((EdgeDetection_GV_SQUARED_DW[col] >= EdgeDetection_GH_SQUARED_DW[col])
          && (imgCol != 0 ? EdgeDetection_GRAD_SUM_DW[col - 3] <=
              EdgeDetection_GRAD_SUM_DW[col] : TRUE) && (imgCol != 2 ?
        EdgeDetection_GRAD_SUM_DW[col] > EdgeDetection_GRAD_SUM_DW[col + 3] :
        TRUE)) || ((EdgeDetection_GH_SQUARED_DW[col] >=
                    EdgeDetection_GV_SQUARED_DW[col]) &&
                   (EdgeDetection_GRAD_SUM_DW[col] >
                    EdgeDetection_GRAD_SUM_DW[col + 1]))));
      col = imgCol * 3 + 1;
      VisionModel_B.EdgeDetection[col] = ((EdgeDetection_GRAD_SUM_DW[col] > ii) &&
        (((EdgeDetection_GV_SQUARED_DW[col] >= EdgeDetection_GH_SQUARED_DW[col])
          && (imgCol != 0 ? EdgeDetection_GRAD_SUM_DW[col - 3] <=
              EdgeDetection_GRAD_SUM_DW[col] : TRUE) && (imgCol != 2 ?
        EdgeDetection_GRAD_SUM_DW[col] > EdgeDetection_GRAD_SUM_DW[col + 3] :
        TRUE)) || ((EdgeDetection_GH_SQUARED_DW[col] >=
                    EdgeDetection_GV_SQUARED_DW[col]) &&
                   (EdgeDetection_GRAD_SUM_DW[col - 1] <=
                    EdgeDetection_GRAD_SUM_DW[col]) &&
                   (EdgeDetection_GRAD_SUM_DW[col] >
                    EdgeDetection_GRAD_SUM_DW[col + 1]))));
      col = imgCol * 3 + 2;
      VisionModel_B.EdgeDetection[col] = ((EdgeDetection_GRAD_SUM_DW[col] > ii) &&
        (((EdgeDetection_GV_SQUARED_DW[col] >= EdgeDetection_GH_SQUARED_DW[col])
          && (imgCol != 0 ? EdgeDetection_GRAD_SUM_DW[col - 3] <=
              EdgeDetection_GRAD_SUM_DW[col] : TRUE) && (imgCol != 2 ?
        EdgeDetection_GRAD_SUM_DW[col] > EdgeDetection_GRAD_SUM_DW[col + 3] :
        TRUE)) || ((EdgeDetection_GH_SQUARED_DW[col] >=
                    EdgeDetection_GV_SQUARED_DW[col]) &&
                   (EdgeDetection_GRAD_SUM_DW[col - 1] <=
                    EdgeDetection_GRAD_SUM_DW[col]))));
    }

    /* S-Function (sviphough): '<S12>/Hough Transform1' */
    MWVIP_Hough_D(&VisionModel_B.EdgeDetection[0],
                  &VisionModel_B.HoughTransform1_o1[0],
                  &VisionModel_ConstP.pooled9[0],
                  &VisionModel_ConstP.HoughTransform1_FIRSTRHO_R, 3, 3, 7, 91);

    /* Embedded MATLAB: '<S12>/Identify Path Elements' incorporates:
     *  Constant: '<S12>/Forward_Camera_Dimensions'
     */
    memcpy((void *)(&VisionModel_B.hough_table_c[0]), (void *)
           (&VisionModel_B.HoughTransform1_o1[0]), 1260U * sizeof(real_T));
    memcpy((void *)&color_areas[0], (void *)(&VisionModel_B.blob_orientation[0]),
           50U * sizeof(real_T));

    /* Embedded MATLAB Function 'path_detector/Identify Path Elements': '<S52>:1' */
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
    /* '<S52>:1:29' */
    /* '<S52>:1:30' */
    /* '<S52>:1:31' */
    positive_area = VisionModel_P.Forward_Camera_Dimensions_Val_i[0] *
      VisionModel_P.Forward_Camera_Dimensions_Val_i[1];

    /*  Tolerance within which two lines are coincident */
    /* '<S52>:1:34' */
    /*  Tolerence within which two slopes are equal (radians) */
    /* '<S52>:1:35' */
    /*  Ratio of blob area to image area considered to imply the blob is actually background noise */
    /* '<S52>:1:37' */
    /* '<S52>:1:38' */
    /* '<S52>:1:39' */
    memset((void *)&rho[0], 0, 200U * sizeof(real_T));

    /*  theta_hold is a copy of theta which gets destroyed */
    /* '<S52>:1:41' */
    /* '<S52>:1:42' */
    /* '<S52>:1:44' */
    rtb_path_headings_idx_1 = 1000.0;
    rtb_path_headings_idx_0 = 1000.0;
    rtb_path_headings_idx = 1000.0;

    /*  1000 is an invalid angle */
    /* '<S52>:1:45' */
    for (i = 0; i < 6; i++) {
      path_locations[i] = 0.0;
    }

    /* '<S52>:1:46' */
    VisionModel_B.path_found = 0.0;

    /* path_found_vector = zeros(1,max_num_paths); */
    /*  Identify the most likely max_num_lines lines */
    /* '<S52>:1:51' */
    col = 1;
    condition = FALSE;
    while (((uint32_T)condition == 0U) && (col <= 200)) {
      /* '<S52>:1:51' */
      /* '<S52>:1:53' */
      ii = 0.0;

      /* '<S52>:1:54' */
      current_color = 1;

      /* '<S52>:1:55' */
      condition_0 = 1;

      /* '<S52>:1:56' */
      for (i = 0; i < 7; i++) {
        /* '<S52>:1:56' */
        /* '<S52>:1:57' */
        for (numElem = 0; numElem < 180; numElem++) {
          /* '<S52>:1:57' */
          if (VisionModel_B.hough_table_c[7 * numElem + i] > ii) {
            /* '<S52>:1:58' */
            /* '<S52>:1:59' */
            current_color = i + 1;

            /* '<S52>:1:60' */
            condition_0 = numElem + 1;

            /* '<S52>:1:61' */
            ii = VisionModel_B.hough_table_c[7 * numElem + i];
          }
        }
      }

      if (ii == 0.0) {
        /* '<S52>:1:66' */
        condition = TRUE;
      } else {
        /* '<S52>:1:70' */
        /* '<S52>:1:71' */
        /* '<S52>:1:72' */
        rho[col - 1] = VisionModel_B.HoughTransform1_o2[condition_0 - 1];

        /* '<S52>:1:73' */
        VisionModel_B.hough_table_c[(current_color - 1) + 7 * (condition_0 - 1)]
          = 0.0;
        col++;
      }
    }

    /*  Correct orientations to vehicle coordinates */
    /* '<S52>:1:79' */
    for (maxL = 1.0; maxL <= VisionModel_B.blob_count; maxL++) {
      /* '<S52>:1:79' */
      /*  theta_hold: */
      /*    -is between [-pi/2, +pi/2] */
      /*  blob_orientation: */
      /*    -is potentially outside this range */
      /*    -needs to be corrected by pi/2 to get relative heading */
      /*     blob_orientation(j) = (pi/2) - blob_orientation(j); */
      /* '<S52>:1:87' */
      minL = (3.1415926535897931 - color_areas[(int32_T)maxL - 1]) /
        3.1415926535897931;
      if (minL < 0.0) {
        ii = ceil(minL - 0.5);
      } else {
        ii = floor(minL + 0.5);
      }

      if (fabs(minL - ii) <= 2.2204460492503131E-16 * fabs(minL)) {
        minL = 0.0;
      } else {
        minL = (minL - floor(minL)) * 3.1415926535897931;
      }

      color_areas[(int32_T)maxL - 1] = minL - 1.5707963267948966;

      /*     if(blob_orientation(j) > pi/2) */
      /*         blob_orientation(j) = blob_orientation(j) - pi; */
      /*     elseif(blob_orientation(j) < -pi/2) */
      /*         blob_orientation(j) = blob_orientation(j) + pi; */
      /*     end */
    }

    /*  Compare most popular lines with blob orientations */
    /* '<S52>:1:97' */
    /* '<S52>:1:98' */
    /* '<S52>:1:100' */
    current_color = 0;

    /* '<S52>:1:101' */
    imgCol = 1;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (imgCol <= 200)) {
      /* '<S52>:1:101' */
      /* '<S52>:1:102' */
      ii = 1.0;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (ii <= VisionModel_B.blob_count)) {
        /* '<S52>:1:102' */
        /*  Search for a match between one blob and one line */
        if ((fabs(rho[imgCol - 1] - color_areas[(int32_T)ii - 1]) <=
             0.17453292519943295) && (VisionModel_B.blob_area[(int32_T)ii - 1] /
             positive_area <= 0.8) && (rho[imgCol - 1] != 1000.0) &&
            (color_areas[(int32_T)ii - 1] != 1000.0)) {
          /* '<S52>:1:105' */
          /* '<S52>:1:106' */
          rtb_path_headings_idx_1 = rho[imgCol - 1];

          /*                 path_found_vector(p) =  */
          /* '<S52>:1:108' */
          path_locations[0] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U)];

          /* '<S52>:1:109' */
          path_locations[1] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U) + 1];

          /*  */
          /* '<S52>:1:114' */
          /* '<S52>:1:115' */
          /* '<S52>:1:116' */
          /* / */
          /* '<S52>:1:120' */
          rho[imgCol - 1] = 1000.0;

          /*  Invalid angle; do not want this line to be selected again */
          /* '<S52>:1:121' */
          color_areas[(int32_T)ii - 1] = 1000.0;

          /* '<S52>:1:122' */
          current_color = 1;
          exitg_0 = TRUE;
        } else {
          ii++;
        }
      }

      if (current_color == 1) {
        /* '<S52>:1:128' */
        exitg = TRUE;
      } else {
        imgCol++;
      }
    }

    /* '<S52>:1:98' */
    /* '<S52>:1:100' */
    current_color = 0;

    /* '<S52>:1:101' */
    imgCol = 1;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (imgCol <= 200)) {
      /* '<S52>:1:101' */
      /* '<S52>:1:102' */
      ii = 1.0;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (ii <= VisionModel_B.blob_count)) {
        /* '<S52>:1:102' */
        /*  Search for a match between one blob and one line */
        if ((fabs(rho[imgCol - 1] - color_areas[(int32_T)ii - 1]) <=
             0.17453292519943295) && (VisionModel_B.blob_area[(int32_T)ii - 1] /
             positive_area <= 0.8) && (rho[imgCol - 1] != 1000.0) &&
            (color_areas[(int32_T)ii - 1] != 1000.0)) {
          /* '<S52>:1:105' */
          /* '<S52>:1:106' */
          rtb_path_headings_idx_0 = rho[imgCol - 1];

          /*                 path_found_vector(p) =  */
          /* '<S52>:1:108' */
          path_locations[2] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U)];

          /* '<S52>:1:109' */
          path_locations[3] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U) + 1];

          /*  */
          /* '<S52>:1:114' */
          /* '<S52>:1:115' */
          /* '<S52>:1:116' */
          /* / */
          /* '<S52>:1:120' */
          rho[imgCol - 1] = 1000.0;

          /*  Invalid angle; do not want this line to be selected again */
          /* '<S52>:1:121' */
          color_areas[(int32_T)ii - 1] = 1000.0;

          /* '<S52>:1:122' */
          current_color = 1;
          exitg_0 = TRUE;
        } else {
          ii++;
        }
      }

      if (current_color == 1) {
        /* '<S52>:1:128' */
        exitg = TRUE;
      } else {
        imgCol++;
      }
    }

    /* '<S52>:1:98' */
    /* '<S52>:1:100' */
    current_color = 0;

    /* '<S52>:1:101' */
    imgCol = 1;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (imgCol <= 200)) {
      /* '<S52>:1:101' */
      /* '<S52>:1:102' */
      ii = 1.0;
      exitg_0 = FALSE;
      while (((uint32_T)exitg_0 == 0U) && (ii <= VisionModel_B.blob_count)) {
        /* '<S52>:1:102' */
        /*  Search for a match between one blob and one line */
        if ((fabs(rho[imgCol - 1] - color_areas[(int32_T)ii - 1]) <=
             0.17453292519943295) && (VisionModel_B.blob_area[(int32_T)ii - 1] /
             positive_area <= 0.8) && (rho[imgCol - 1] != 1000.0) &&
            (color_areas[(int32_T)ii - 1] != 1000.0)) {
          /* '<S52>:1:105' */
          /* '<S52>:1:106' */
          rtb_path_headings_idx = rho[imgCol - 1];

          /*                 path_found_vector(p) =  */
          /* '<S52>:1:108' */
          path_locations[4] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U)];

          /* '<S52>:1:109' */
          path_locations[5] = VisionModel_B.blob_centroids[(((int32_T)ii - 1) <<
            1U) + 1];

          /*  */
          /* '<S52>:1:114' */
          /* '<S52>:1:115' */
          /* '<S52>:1:116' */
          /* / */
          /* '<S52>:1:120' */
          rho[imgCol - 1] = 1000.0;

          /*  Invalid angle; do not want this line to be selected again */
          /* '<S52>:1:121' */
          color_areas[(int32_T)ii - 1] = 1000.0;

          /* '<S52>:1:122' */
          current_color = 1;
          exitg_0 = TRUE;
        } else {
          ii++;
        }
      }

      if (current_color == 1) {
        /* '<S52>:1:128' */
        exitg = TRUE;
      } else {
        imgCol++;
      }
    }

    /*  Order path_headings to reflect actual path locations (left to right in */
    /*    image) */
    /* '<S52>:1:138' */
    /* '<S52>:1:139' */
    /* '<S52>:1:140' */
    value[0] = VisionModel_P.Forward_Camera_Dimensions_Val_i[1];
    b_j_index[0] = 1;
    found[0] = 0.0;
    value[1] = VisionModel_P.Forward_Camera_Dimensions_Val_i[1];
    b_j_index[1] = 1;
    found[1] = 0.0;
    value[2] = VisionModel_P.Forward_Camera_Dimensions_Val_i[1];
    b_j_index[2] = 1;
    found[2] = 0.0;

    /* '<S52>:1:142' */
    for (condition_0 = 0; condition_0 < 3; condition_0++) {
      b_j_index_0 = b_j_index[condition_0];

      /* '<S52>:1:142' */
      /* '<S52>:1:143' */
      i_gate_idx = value[condition_0];

      /* '<S52>:1:143' */
      if ((path_locations[1] < value[condition_0]) && (found[0] == 0.0)) {
        /* '<S52>:1:144' */
        /* '<S52>:1:145' */
        i_gate_idx = path_locations[1];

        /* '<S52>:1:146' */
        b_j_index_0 = 1;
      }

      /* '<S52>:1:143' */
      if ((path_locations[3] < i_gate_idx) && (found[1] == 0.0)) {
        /* '<S52>:1:144' */
        /* '<S52>:1:145' */
        i_gate_idx = path_locations[3];

        /* '<S52>:1:146' */
        b_j_index_0 = 2;
      }

      /* '<S52>:1:143' */
      if ((path_locations[5] < i_gate_idx) && (found[2] == 0.0)) {
        /* '<S52>:1:144' */
        /* '<S52>:1:145' */
        /* '<S52>:1:146' */
        b_j_index_0 = 3;
      }

      /* '<S52>:1:149' */
      found[b_j_index_0 - 1] = 1.0;
      b_j_index[condition_0] = b_j_index_0;
    }

    /* '<S52>:1:152' */
    matr[0] = rtb_path_headings_idx_1;
    matr[3] = rtb_path_headings_idx_0;
    matr[6] = rtb_path_headings_idx;
    for (i = 0; i < 3; i++) {
      matr[1 + 3 * i] = path_locations[i << 1];
      matr[2 + 3 * i] = path_locations[(i << 1) + 1];
    }

    /* '<S52>:1:153' */
    /* '<S52>:1:154' */
    /* '<S52>:1:153' */
    /* '<S52>:1:154' */
    /* '<S52>:1:153' */
    /* '<S52>:1:154' */
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
    /* '<S52>:1:226' */
    /* '<S52>:1:227' */

    /* Embedded MATLAB: '<S12>/Identify Path Elements1' incorporates:
     *  Inport: '<Root>/DesiredPathDirection'
     */
    /* Embedded MATLAB Function 'path_detector/Identify Path Elements1': '<S53>:1' */
    /*  Input */
    /*    which_path = indicates which direction to take; left (1) right (2) or */
    /*      straight (0) */
    /*  Return the relative heading of the path element pointing "left" or */
    /*    "right" */
    if (VisionModel_U.DesiredPathDirection == 1.0) {
      /* '<S53>:1:10' */
      /*  Take leftmost path */
      /* '<S53>:1:12' */
      ii = 1000.0;

      /* '<S53>:1:13' */
      if ((matr[(b_j_index[0] - 1) * 3] < 1000.0) && (matr[(b_j_index[0] - 1) *
           3] != 1000.0)) {
        /* '<S53>:1:14' */
        /* '<S53>:1:15' */
        ii = matr[(b_j_index[0] - 1) * 3];
      }

      /* '<S53>:1:13' */
      if ((matr[(b_j_index[1] - 1) * 3] < ii) && (matr[(b_j_index[1] - 1) * 3]
           != 1000.0)) {
        /* '<S53>:1:14' */
        /* '<S53>:1:15' */
        ii = matr[(b_j_index[1] - 1) * 3];
      }

      /* '<S53>:1:13' */
      if ((matr[(b_j_index[2] - 1) * 3] < ii) && (matr[(b_j_index[2] - 1) * 3]
           != 1000.0)) {
        /* '<S53>:1:14' */
        /* '<S53>:1:15' */
        ii = matr[(b_j_index[2] - 1) * 3];
      }

      /* '<S53>:1:18' */
      ii = ii * 180.0 / 3.1415926535897931;

      /*     target_yaw = min(path_headings)*180/pi; */
    } else if (VisionModel_U.DesiredPathDirection == 2.0) {
      /* '<S53>:1:21' */
      /*  Take rightmost path */
      /* '<S53>:1:23' */
      ii = -1000.0;

      /* '<S53>:1:24' */
      if ((matr[(b_j_index[0] - 1) * 3] > -1000.0) && (matr[(b_j_index[0] - 1) *
           3] != 1000.0)) {
        /* '<S53>:1:25' */
        /* '<S53>:1:26' */
        ii = matr[(b_j_index[0] - 1) * 3];
      }

      /* '<S53>:1:24' */
      if ((matr[(b_j_index[1] - 1) * 3] > ii) && (matr[(b_j_index[1] - 1) * 3]
           != 1000.0)) {
        /* '<S53>:1:25' */
        /* '<S53>:1:26' */
        ii = matr[(b_j_index[1] - 1) * 3];
      }

      /* '<S53>:1:24' */
      if ((matr[(b_j_index[2] - 1) * 3] > ii) && (matr[(b_j_index[2] - 1) * 3]
           != 1000.0)) {
        /* '<S53>:1:25' */
        /* '<S53>:1:26' */
        ii = matr[(b_j_index[2] - 1) * 3];
      }

      /* '<S53>:1:29' */
      ii = ii * 180.0 / 3.1415926535897931;

      /*     target_yaw = max(path_headings)*180/pi; */
    } else {
      /*  Continue straight */
      /* '<S53>:1:34' */
      ii = 0.0;
    }

    /* '<S53>:1:37' */
    VisionModel_B.target_x = 0.0;

    /* '<S53>:1:38' */
    VisionModel_B.target_y_i = 0.0;

    /* '<S53>:1:39' */
    VisionModel_B.path_state = 0.0;

    /* Sum: '<S12>/Add18' incorporates:
     *  Inport: '<Root>/DeadReckonHeading'
     */
    VisionModel_B.Add18 = ii + VisionModel_U.DeadReckonHeading;

    /* If: '<S12>/If1' incorporates:
     *  ActionPort: '<S54>/Action Port'
     *  Inport: '<Root>/OutputImage'
     *  SubSystem: '<S12>/If Action Subsystem'
     */
    if (VisionModel_U.OutputImage > 0.0) {
      /* Embedded MATLAB: '<S54>/Transform Coordinates3' */
      VisionMod_TransformCoordinates3(VisionModel_P.which_camera_Value_h,
        VisionModel_B.target_x, VisionModel_B.target_y_i, 0.0,
        VisionModel_P.Down_Camera_Dimensions_Value,
        &VisionModel_B.sf_TransformCoordinates3_b);
    }

    /* Constant: '<S12>/ColorFilter1' */
    VisionModel_B.ColorFilter1 = VisionModel_P.ColorFilter1_Value;
  } else if (VisionModel_U.ModeSelect == 3.0) {
    /* Embedded MATLAB: '<S9>/Shape_Analysis' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant3'
     */
    /* Embedded MATLAB Function 'buoy_detector/Shape_Analysis': '<S50>:1' */
    /*  This function takes in vectors representing blobs present in the image, */
    /*    and returns information about how many and what kind of buoys are */
    /*    present. Buoys are identified by shape only. */
    /*  */
    /*  Input */
    /*    blob_hues = Nx3 vector of hues of blobs in image (values are Lab */
    /*      components) */
    /*    blob_centroids = Nx2 matrix of x-y pairs of blob centroid locations */
    /*    blob_eccentricity = Nx1 vector of blob eccentricites */
    /*    blob_extent = Nx1 vector of blob extents */
    /*    blob_count = integer number of blobs in image */
    /*  */
    /*    Min_Hue,Max_Hue = Nx1 limits on valid buoy hues; hue is between 0 and 1 */
    /*    Min_Eccent,Max_Eccent = scalar limits on buoy eccentricity */
    /*    Min_Extent,Max_Extent = scalar limits on buoy extent */
    /*  */
    /*    Buoy_Count_Max = maximum number of buoys that will be analyzed */
    /*  */
    /*  Output */
    /*    buoy_hues = Nx1 vector of buoy colors */
    /*    buoy_centroids = Nx2 matrix of x-y pairs of buoy centroid locations */
    /*    buoy_count = integer number of buoys found in image */
    /*    buoy_colors = 1xN vector of buoy colors identified by blob analysis */
    /*  Initialize */
    /* '<S50>:1:30' */
    for (i = 0; i < 100; i++) {
      VisionModel_B.buoy_centroids[i] = -500.0;
    }

    /*  Initialize to points clearly not located in image */
    /* '<S50>:1:31' */
    blob_count = 0.0;

    /* '<S50>:1:32' */
    memset((void *)&color_areas[0], 0, 50U * sizeof(real_T));

    /*  Loop through blobs, and extract information about blobs shaped like buoys */
    /* '<S50>:1:36' */
    for (ii = 1.0; ii <= VisionModel_B.blob_count_c; ii++) {
      /* '<S50>:1:36' */
      /*  Store buoy information if geometric conditions are met */
      /*    Conditions: 1) Blob eccentricity is within specified range */
      /*                2) Blob extent is within specified range */
      if ((VisionModel_B.blob_eccentricity_h[(int32_T)ii - 1] >=
           VisionModel_P.Constant_Value) && (VisionModel_B.blob_eccentricity_h
           [(int32_T)ii - 1] <= VisionModel_P.Constant1_Value_f) &&
          (VisionModel_B.blob_extent_k[(int32_T)ii - 1] >=
           VisionModel_P.Constant2_Value_h) && (VisionModel_B.blob_extent_k
           [(int32_T)ii - 1] <= VisionModel_P.Constant3_Value_i)) {
        /* '<S50>:1:41' */
        /* '<S50>:1:43' */
        blob_count++;

        /* '<S50>:1:49' */
        VisionModel_B.buoy_centroids[(((int32_T)blob_count - 1) << 1U)] =
          VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U)];

        /* '<S50>:1:50' */
        VisionModel_B.buoy_centroids[1 + (((int32_T)blob_count - 1) << 1U)] =
          VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1];

        /*         buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
        /*         buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
        /* '<S50>:1:54' */
        color_areas[(int32_T)blob_count - 1] = VisionModel_B.blob_color_i
          [(int32_T)ii - 1];
      }
    }

    /*  If no buoy is identified, then loosen the shape restrictions and try again */
    if (blob_count == 0.0) {
      /* '<S50>:1:62' */
      /* '<S50>:1:64' */
      maxL = (VisionModel_P.Constant1_Value_f - VisionModel_P.Constant_Value) *
        0.6;

      /* '<S50>:1:65' */
      ii = (VisionModel_P.Constant1_Value_f + VisionModel_P.Constant_Value) *
        0.6;

      /* '<S50>:1:66' */
      minL = (VisionModel_P.Constant3_Value_i - VisionModel_P.Constant2_Value_h)
        * 0.5;

      /* '<S50>:1:67' */
      jj = (VisionModel_P.Constant3_Value_i + VisionModel_P.Constant2_Value_h) *
        0.5;

      /* '<S50>:1:68' */
      r = ii - maxL;

      /* '<S50>:1:69' */
      positive_area = ii + maxL;

      /* '<S50>:1:70' */
      c = jj - minL;

      /* '<S50>:1:71' */
      maxL = jj + minL;

      /* '<S50>:1:72' */
      for (ii = 1.0; ii <= VisionModel_B.blob_count_c; ii++) {
        /* '<S50>:1:72' */
        /*  Store buoy information if geometric conditions are met */
        /*    Conditions: 1) Blob eccentricity is within specified range */
        /*                2) Blob extent is within specified range */
        if ((VisionModel_B.blob_eccentricity_h[(int32_T)ii - 1] >= r) &&
            (VisionModel_B.blob_eccentricity_h[(int32_T)ii - 1] <= positive_area)
            && (VisionModel_B.blob_extent_k[(int32_T)ii - 1] >= c) &&
            (VisionModel_B.blob_extent_k[(int32_T)ii - 1] <= maxL)) {
          /* '<S50>:1:77' */
          /* '<S50>:1:79' */
          blob_count++;

          /* '<S50>:1:86' */
          VisionModel_B.buoy_centroids[(((int32_T)blob_count - 1) << 1U)] =
            VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U)];

          /* '<S50>:1:87' */
          VisionModel_B.buoy_centroids[1 + (((int32_T)blob_count - 1) << 1U)] =
            VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1];

          /* buoy_centroids(buoy_count,1) = blob_centroids(i,1); */
          /* buoy_centroids(buoy_count,2) = blob_centroids(i,2); */
          /* '<S50>:1:91' */
          color_areas[(int32_T)blob_count - 1] = VisionModel_B.blob_color_i
            [(int32_T)ii - 1];
        }
      }
    }

    /* Embedded MATLAB: '<S9>/Choose_Buoy' incorporates:
     *  Constant: '<S9>/Forward_Camera_Dimensions1'
     *  Constant: '<S9>/Forward_Camera_Dimensions3'
     *  Inport: '<Root>/DesiredBuoyColor'
     */
    /* Embedded MATLAB Function 'buoy_detector/Choose_Buoy': '<S48>:1' */
    /*  This function takes in vectors representing buoys present in the image, */
    /*    and decides which buoy to target. */
    /*  */
    /*  Input */
    /*    buoy_hues = Nx3 matrix of Lab components for each buoy */
    /*    buoy_centroids = 2xN matrix of x-y pairs of buoy centroids */
    /*    buoy_count = number of buoys identified in the image */
    /*    buoy_colors = 1xN vector of buoy color indices */
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
    /*    maintain_heading = instructs MotionController to strafe xor turn: */
    /*                     = 0 -> Turn toward target (use targetYaw) */
    /*                     = 1 -> Strafe to target (use targetY) */
    /*    targetY, targetZ = position of buoy in absolute coordinates */
    /*    targetYaw = relative, lateral angular displacement of buoy from */
    /*      straight ahead (in degrees) */
    /*    target_detected = informs the script that a buoy is being tracked */
    /*  Initialize */
    /* '<S48>:1:35' */
    VisionModel_B.target_select_f = 1.0;

    /* '<S48>:1:36' */
    /* '<S48>:1:37' */
    jj = 0.0;

    /* '<S48>:1:38' */
    VisionModel_B.targetZ = 0.0;

    /* '<S48>:1:39' */
    VisionModel_B.targetYaw = 0.0;

    /* '<S48>:1:40' */
    condition_0 = 0;

    /* '<S48>:1:41' */
    /* '<S48>:1:42' */
    /* { */
    /*  Classify each buoy by color */
    /* for i = 1:buoy_count */
    /*      */
    /*     a = buoy_hues(i, 2); */
    /*     b = buoy_hues(i, 3); */
    /*      */
    /*     % Note that colors 1 and 2 are black and white, resp. and do not have */
    /*     %   useful ranges in the a and b color components */
    /*     for col = 3:max_num_colors */
    /*         if( a >= a_range(1,col) && a <= a_range(2,col) && b >= b_range(1,col) && b <= b_range(2,col) ) */
    /*             buoy_colors(i) = col; */
    /*             break; */
    /*         end */
    /*     end */
    /*      */
    /* end */
    /* } */
    /*  Examine buoys from left to right; if one has the correct color, then */
    /*    target it; else do not recognize a target */
    /* '<S48>:1:68' */
    ii = 1.0;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (ii <= blob_count)) {
      /* '<S48>:1:68' */
      if (color_areas[(int32_T)ii - 1] == VisionModel_U.DesiredBuoyColor) {
        /* '<S48>:1:69' */
        /* '<S48>:1:70' */
        jj = VisionModel_B.buoy_centroids[(((int32_T)ii - 1) << 1U) + 1] - floor
          (VisionModel_P.Forward_Camera_Dimensions1_Va_f[1] / 2.0);

        /* '<S48>:1:71' */
        VisionModel_B.targetZ = VisionModel_B.buoy_centroids[(((int32_T)ii - 1) <<
          1U)] - floor(VisionModel_P.Forward_Camera_Dimensions1_Va_f[0] / 2.0);

        /* '<S48>:1:72' */
        VisionModel_B.targetYaw = jj /
          VisionModel_P.Forward_Camera_Dimensions1_Va_f[1] *
          VisionModel_P.Forward_Camera_Dimensions3_Valu;

        /* '<S48>:1:73' */
        condition_0 = 1;
        exitg = TRUE;
      } else {
        ii++;
      }
    }

    /*  If no buoy was targeted, then pick one of the remaining buoys to target */
    if (condition_0 == 0) {
      /* '<S48>:1:81' */
      /* '<S48>:1:82' */
      jj = VisionModel_B.buoy_centroids[1] - floor
        (VisionModel_P.Forward_Camera_Dimensions1_Va_f[1] / 2.0);

      /* '<S48>:1:83' */
      VisionModel_B.targetZ = VisionModel_B.buoy_centroids[0] - floor
        (VisionModel_P.Forward_Camera_Dimensions1_Va_f[0] / 2.0);

      /* '<S48>:1:84' */
      VisionModel_B.targetYaw = jj /
        VisionModel_P.Forward_Camera_Dimensions1_Va_f[1] *
        VisionModel_P.Forward_Camera_Dimensions3_Valu;
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
    VisionModel_B.targetY = jj;
    VisionModel_B.target_detected_d = (real_T)condition_0;

    /* If: '<S9>/If1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     *  Inport: '<Root>/OutputImage'
     *  SubSystem: '<S9>/If Action Subsystem'
     */
    if (VisionModel_U.OutputImage > 0.0) {
      VisionModel_IfActionSubsystem(VisionModel_B.bw_image_e,
        VisionModel_P.which_camera_Value_k, 0.0, VisionModel_B.targetY,
        VisionModel_B.targetZ, VisionModel_P.Forward_Camera_Dimensions2_Valu,
        &VisionModel_B.IfActionSubsystem_h, (rtP_IfActionSubsystem_VisionMod *)
        &VisionModel_P.IfActionSubsystem_h);
    }
  } else if (VisionModel_U.ModeSelect == 4.0) {
    /* Embedded MATLAB: '<S13>/Analyze LabelMatrix for Targets' */
    /* Embedded MATLAB Function 'torpedo/Analyze LabelMatrix for Targets': '<S56>:1' */
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
    /* '<S56>:1:30' */
    /* '<S56>:1:31' */
    /* { */
    /*  */
    /*  Initialize */
    /* persistent successive_valid_image_count; */
    /* buoy_count = double(0); */
    /*  */
    /* debug */
    /* successive_valid_image_count = 0; */
    /* Buoy_Count_Max = 50; */
    /*  */
    /* /debug */
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

    /* Embedded MATLAB: '<S13>/Decide which target to follow' */
    /* Embedded MATLAB Function 'torpedo/Decide which target to follow': '<S57>:1' */
    /*  Decide which target to shoot at, based on which color is wanted. */
    /*  */
    /*  Input */
    /*  */
    /*  Output */
    /*  */
    /*  Initialize */
    /*  */
    /* '<S57>:1:14' */
    VisionModel_B.target_select_j = 1.0;

    /* '<S57>:1:15' */
    /* '<S57>:1:16' */
    VisionModel_B.target_y_m = 0.0;

    /* '<S57>:1:17' */
    VisionModel_B.target_z_d = 0.0;

    /* '<S57>:1:18' */
    VisionModel_B.target_yaw_k = 0.0;

    /* '<S57>:1:19' */
    VisionModel_B.target_detected_e = 0.0;

    /* '<S57>:1:20' */
    VisionModel_B.fire_authorization = 0.0;

    /* If: '<S13>/If1' incorporates:
     *  ActionPort: '<S58>/Action Port'
     *  Inport: '<Root>/OutputImage'
     *  SubSystem: '<S13>/If Action Subsystem'
     */
    if (VisionModel_U.OutputImage > 0.0) {
      VisionModel_IfActionSubsystem(VisionModel_B.bw_image_e,
        VisionModel_P.which_camera_Value_j, 0.0, VisionModel_B.target_y_m,
        VisionModel_B.target_z_d, VisionModel_P.Forward_Camera_Dimensions2_Va_d,
        &VisionModel_B.IfActionSubsystem_l, (rtP_IfActionSubsystem_VisionMod *)
        &VisionModel_P.IfActionSubsystem_l);
    }
  } else {
    if (VisionModel_U.ModeSelect == 5.0) {
      /* S-Function (svipedge): '<S8>/Edge Detection1' */
      for (imgCol = 1; imgCol < 119; imgCol++) {
        for (current_color = 1; current_color < 159; current_color++) {
          ii = 0.0;
          jj = 0.0;
          condition_0 = imgCol * 160 + current_color;
          for (col = 0; col < 6; col++) {
            ii += VisionModel_B.bw_image_e[condition_0 +
              VisionModel_DWork.EdgeDetection1_VO_DW[col]] *
              VisionModel_ConstP.pooled7[col];
            jj += VisionModel_B.bw_image_e[condition_0 +
              VisionModel_DWork.EdgeDetection1_HO_DW[col]] *
              VisionModel_ConstP.pooled8[col];
          }

          VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = ii * ii;
          VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = jj * jj;
        }
      }

      for (imgCol = 1; imgCol < 119; imgCol++) {
        ii = 0.0;
        jj = 0.0;
        minL = 0.0;
        maxL = 0.0;
        condition_0 = imgCol * 160;
        current_color = imgCol * 160 + 159;
        for (col = 0; col < 6; col++) {
          ii += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection1_HOU_DW[col]] *
            VisionModel_ConstP.pooled8[col];
          jj += VisionModel_B.bw_image_e[current_color +
            VisionModel_DWork.EdgeDetection1_HOD_DW[col]] *
            VisionModel_ConstP.pooled8[col];
          minL += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection1_VOU_DW[col]] *
            VisionModel_ConstP.pooled7[col];
          maxL += VisionModel_B.bw_image_e[current_color +
            VisionModel_DWork.EdgeDetection1_VOD_DW[col]] *
            VisionModel_ConstP.pooled7[col];
        }

        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = minL *
          minL;
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = ii * ii;
        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[current_color] = maxL *
          maxL;
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[current_color] = jj * jj;
      }

      for (current_color = 1; current_color < 159; current_color++) {
        ii = 0.0;
        jj = 0.0;
        minL = 0.0;
        maxL = 0.0;
        condition_0 = 19040 + current_color;
        for (col = 0; col < 6; col++) {
          ii += VisionModel_B.bw_image_e[current_color +
            VisionModel_DWork.EdgeDetection1_VOL_DW[col]] *
            VisionModel_ConstP.pooled7[col];
          jj += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection1_VOR_DW[col]] *
            VisionModel_ConstP.pooled7[col];
          minL += VisionModel_B.bw_image_e[current_color +
            VisionModel_DWork.EdgeDetection1_HOL_DW[col]] *
            VisionModel_ConstP.pooled8[col];
          maxL += VisionModel_B.bw_image_e[condition_0 +
            VisionModel_DWork.EdgeDetection1_HOR_DW[col]] *
            VisionModel_ConstP.pooled8[col];
        }

        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[current_color] = ii * ii;
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[current_color] = minL *
          minL;
        VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[condition_0] = jj * jj;
        VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[condition_0] = maxL *
          maxL;
      }

      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      for (col = 0; col < 6; col++) {
        ii +=
          VisionModel_B.bw_image_e[VisionModel_DWork.EdgeDetection1_VOUL_DW[col]]
          * VisionModel_ConstP.pooled7[col];
        jj +=
          VisionModel_B.bw_image_e[VisionModel_DWork.EdgeDetection1_HOUL_DW[col]]
          * VisionModel_ConstP.pooled8[col];
        minL += VisionModel_B.bw_image_e[159 +
          VisionModel_DWork.EdgeDetection1_VOLL_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        maxL += VisionModel_B.bw_image_e[159 +
          VisionModel_DWork.EdgeDetection1_HOLL_DW[col]] *
          VisionModel_ConstP.pooled8[col];
      }

      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[0] = ii * ii;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[0] = jj * jj;
      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[159] = minL * minL;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[159] = maxL * maxL;
      ii = 0.0;
      jj = 0.0;
      minL = 0.0;
      maxL = 0.0;
      for (col = 0; col < 6; col++) {
        ii += VisionModel_B.bw_image_e[19040 +
          VisionModel_DWork.EdgeDetection1_VOUR_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        jj += VisionModel_B.bw_image_e[19040 +
          VisionModel_DWork.EdgeDetection1_HOUR_DW[col]] *
          VisionModel_ConstP.pooled8[col];
        minL += VisionModel_B.bw_image_e[19199 +
          VisionModel_DWork.EdgeDetection1_VOLR_DW[col]] *
          VisionModel_ConstP.pooled7[col];
        maxL += VisionModel_B.bw_image_e[19199 +
          VisionModel_DWork.EdgeDetection1_HOLR_DW[col]] *
          VisionModel_ConstP.pooled8[col];
      }

      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[19040] = ii * ii;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[19040] = jj * jj;
      VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[19199] = minL * minL;
      VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[19199] = maxL * maxL;
      jj = 0.0;
      for (col = 0; col < 19200; col++) {
        VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] =
          VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col];
        VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] =
          VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] +
          VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col];
        jj += VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] *
          VisionModel_DWork.EdgeDetection1_MEAN_FACTOR_DW;
      }

      ii = VisionModel_P.EdgeDetection1_THRESH_TUNING_RT * jj;
      for (imgCol = 0; imgCol < 120; imgCol++) {
        for (current_color = 0; current_color < 160; current_color++) {
          col = imgCol * 160 + current_color;
          VisionModel_B.EdgeDetection1[col] =
            ((VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] > ii) &&
             (((VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col] >=
                VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col]) && (imgCol
                != 0 ? VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col - 160] <=
                VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] : TRUE) &&
               (imgCol != 119 ? VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col]
                > VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col + 160] : TRUE))
              || ((VisionModel_DWork.EdgeDetection1_GH_SQUARED_DW[col] >=
                   VisionModel_DWork.EdgeDetection1_GV_SQUARED_DW[col]) &&
                  (current_color != 0 ?
                   VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col - 1] <=
                   VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] : TRUE) &&
                  (current_color != 159 ?
                   VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col] >
                   VisionModel_DWork.EdgeDetection1_GRAD_SUM_DW[col + 1] : TRUE))));
        }
      }

      /* S-Function (sviphough): '<S8>/Hough Transform2' */
      MWVIP_Hough_D(&VisionModel_B.EdgeDetection1[0],
                    &VisionModel_B.HoughTransform2_o1[0],
                    &VisionModel_ConstP.pooled9[0], &VisionModel_ConstP.pooled10,
                    160, 120, 399, 91);

      /* Embedded MATLAB: '<S8>/Identify L-Obstacle' incorporates:
       *  Constant: '<S8>/Constant1'
       *  Constant: '<S8>/Constant2'
       *  Constant: '<S8>/Constant5'
       *  Constant: '<S8>/Forward_Camera_Dimensions'
       */
      memcpy((void *)(&VisionModel_B.hough_table[0]), (void *)
             (&VisionModel_B.HoughTransform2_o1[0]), 71820U * sizeof(real_T));
      memcpy((void *)&color_areas[0], (void *)
             (&VisionModel_B.blob_orientation_g[0]), 50U * sizeof(real_T));

      /* Embedded MATLAB Function 'L_detector/Identify L-Obstacle': '<S45>:1' */
      /* { */
      /*  */
      /* 1. Iteratively segment image */
      /* 2. Obtain information about all blobs in image */
      /* 3. Generate a bw image by filtering colors (thresholding) */
      /*  */
      /* 3.5. Identify one appropriate horizontal and one appropriate vertical blob */
      /*  */
      /* 4. Perform edge detection then Hough transform to bw image */
      /* 5. Identify the most popular lines (any orientation) that are: */
      /*      a) Nearly colinear with blobs, and */
      /*      b) At approximately 90 degrees from each other */
      /*  */
      /* 6. Target appropriately */
      /*  */
      /* } */
      /*  This function attempts to identfiy the L-shaped obstacle, and returns */
      /*    targeting information, and a true/false target_detected parameter. */
      /*  Initialize */
      /* '<S45>:1:28' */
      VisionModel_B.target_select = 1.0;

      /* '<S45>:1:30' */
      /*  Only the (max_num_lines) with the most votes will be considered as */
      /*    candidates for the gate */
      /* '<S45>:1:41' */
      /* '<S45>:1:42' */
      /* '<S45>:1:44' */
      positive_area = VisionModel_P.Forward_Camera_Dimensions_Val_h[0] *
        VisionModel_P.Forward_Camera_Dimensions_Val_h[1];

      /* '<S45>:1:45' */
      /*  Ratio of blob area to image area considered to imply the blob is actually background noise */
      /*  eps_rho must be at least as big as the gate leg diameter (units of */
      /*    pixels) */
      /* '<S45>:1:49' */
      minL = ((VisionModel_P.Forward_Camera_Dimensions_Val_h[0] >=
               VisionModel_P.Forward_Camera_Dimensions_Val_h[1]) || rtIsNaN
              (VisionModel_P.Forward_Camera_Dimensions_Val_h[1]) ?
              VisionModel_P.Forward_Camera_Dimensions_Val_h[0] :
              VisionModel_P.Forward_Camera_Dimensions_Val_h[1]) * 0.1;

      /*  eps_theta is used to distinguish lines as "horizontal" or "vertical"; */
      /*    units are radians */
      /* '<S45>:1:52' */
      /*  These vectors contain the final two lines that compose the L-obstacle */
      /*  These vectors contain intermediate line information; as lines are */
      /*    eliminated from these vectors, their values are set to zero */
      /*  Note that rho_in and theta_in are referred to by hough_table; they do not */
      /*    constitute (rho,theta) pairs without hough_table. rho and theta, */
      /*    however, do constitute (rho,theta) pairs. */
      /* '<S45>:1:63' */
      /* '<S45>:1:64' */
      /*  Identify the most popular max_num_lines lines */
      /* '<S45>:1:68' */
      /* '<S45>:1:69' */
      for (i = 0; i < 200; i++) {
        i_index[i] = 1;
        j_index[i] = 1U;
      }

      /* '<S45>:1:71' */
      for (col = 0; col < 200; col++) {
        /* '<S45>:1:71' */
        /* '<S45>:1:73' */
        ii = 0.0;

        /* '<S45>:1:74' */
        for (i = 0; i < 399; i++) {
          /* '<S45>:1:74' */
          /* '<S45>:1:75' */
          for (numElem = 0; numElem < 180; numElem++) {
            /* '<S45>:1:75' */
            if (VisionModel_B.hough_table[399 * numElem + i] > ii) {
              /* '<S45>:1:76' */
              /* '<S45>:1:77' */
              i_index[col] = (int16_T)(i + 1);

              /* '<S45>:1:78' */
              j_index[col] = (uint8_T)(numElem + 1);

              /* '<S45>:1:79' */
              ii = VisionModel_B.hough_table[399 * numElem + i];
            }
          }
        }

        /* '<S45>:1:84' */
        rho[col] = VisionModel_B.HoughTransform2_o3[i_index[col] - 1];

        /* '<S45>:1:85' */
        theta[col] = VisionModel_B.HoughTransform2_o2[j_index[col] - 1];

        /* '<S45>:1:86' */
        VisionModel_B.hough_table[(i_index[col] - 1) + 399 * (j_index[col] - 1)]
          = 0.0;
      }

      /*  Correct orientations to vehicle coordinates */
      /* '<S45>:1:92' */
      for (maxL = 1.0; maxL <= VisionModel_B.blob_count_c; maxL++) {
        /* '<S45>:1:92' */
        /*  theta_hold: */
        /*    -is between [-pi/2, +pi/2] */
        /*  blob_orientation: */
        /*    -is potentially outside this range */
        /*    -needs to be corrected by pi/2 to get relative heading */
        /* '<S45>:1:98' */
        color_areas[(int32_T)maxL - 1] = VisionModel_mod(3.1415926535897931 -
          color_areas[(int32_T)maxL - 1], 3.1415926535897931) -
          1.5707963267948966;
      }

      /*  Determine the most popular lines which are nearly colinear to blobs */
      /* '<S45>:1:103' */
      memcpy((void *)&theta_hold[0], (void *)&theta[0], 200U * sizeof(real_T));

      /* '<S45>:1:104' */
      i = 0;
      i_gate_idx = 0.0;
      find_white = 0;
      rtb_Add1 = 0.0;

      /*  Indices for line and blob, respectively */
      /* '<S45>:1:105' */
      /* '<S45>:1:107' */
      current_color = 0;

      /* '<S45>:1:108' */
      imgCol = 1;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (imgCol <= 200)) {
        /* '<S45>:1:108' */
        /* '<S45>:1:109' */
        ii = 1.0;
        exitg_0 = FALSE;
        while (((uint32_T)exitg_0 == 0U) && (ii <= VisionModel_B.blob_count_c))
        {
          /* '<S45>:1:109' */
          /*  Search for a match between one blob and one line */
          /* '<S45>:1:112' */
          /* '<S45>:1:113' */
          if ((theta_hold[imgCol - 1] != 1000.0) && (color_areas[(int32_T)ii - 1]
               != 1000.0)) {
            /* '<S45>:1:114' */
            c_0 = TRUE;
          } else {
            /* '<S45>:1:114' */
            c_0 = FALSE;
          }

          /* '<S45>:1:115' */
          /* '<S45>:1:116' */
          /* '<S45>:1:117' */
          jj = VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1] *
            sin(theta[imgCol - 1]) + (rho[imgCol - 1] * cos(theta[imgCol - 1]) -
            VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U)]);

          /* '<S45>:1:118' */
          /* '<S45>:1:119' */
          /* '<S45>:1:120' */
          if ((fabs(theta_hold[imgCol - 1] - color_areas[(int32_T)ii - 1]) <=
               0.17453292519943295) && (VisionModel_B.blob_area_p[(int32_T)ii -
               1] / positive_area <= 0.8) && c_0 && (sqrt(rt_pow_snf(((-(1.0 /
                    tan(theta[imgCol - 1]))) * jj + rho[imgCol - 1] / sin
                  (theta[imgCol - 1])) - VisionModel_B.blob_centroids_m
                 [(((int32_T)ii - 1) << 1U)], 2.0) + rt_pow_snf(jj -
                 VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1],
                 2.0)) <= minL)) {
            /* '<S45>:1:121' */
            /* '<S45>:1:114' */
            /* '<S45>:1:121' */
            /* '<S45>:1:123' */
            /*  Determine the first gate element */
            /* '<S45>:1:126' */
            i = imgCol;

            /* '<S45>:1:127' */
            i_gate_idx = ii;

            /* '<S45>:1:141' */
            theta_hold[imgCol - 1] = 1000.0;

            /*  Invalid angle; do not want this line to be selected again */
            /* '<S45>:1:142' */
            color_areas[(int32_T)ii - 1] = 1000.0;

            /* '<S45>:1:143' */
            current_color = 1;
            exitg_0 = TRUE;
          } else {
            ii++;
          }
        }

        if (current_color == 1) {
          /* '<S45>:1:149' */
          exitg = TRUE;
        } else {
          imgCol++;
        }
      }

      /* '<S45>:1:105' */
      /* '<S45>:1:107' */
      current_color = 0;

      /* '<S45>:1:108' */
      imgCol = 1;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (imgCol <= 200)) {
        /* '<S45>:1:108' */
        /* '<S45>:1:109' */
        ii = 1.0;
        exitg_0 = FALSE;
        while (((uint32_T)exitg_0 == 0U) && (ii <= VisionModel_B.blob_count_c))
        {
          /* '<S45>:1:109' */
          /*  Search for a match between one blob and one line */
          /* '<S45>:1:112' */
          /* '<S45>:1:113' */
          if ((theta_hold[imgCol - 1] != 1000.0) && (color_areas[(int32_T)ii - 1]
               != 1000.0)) {
            /* '<S45>:1:114' */
            c_0 = TRUE;
          } else {
            /* '<S45>:1:114' */
            c_0 = FALSE;
          }

          /* '<S45>:1:115' */
          /* '<S45>:1:116' */
          /* '<S45>:1:117' */
          jj = VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1] *
            sin(theta[imgCol - 1]) + (rho[imgCol - 1] * cos(theta[imgCol - 1]) -
            VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U)]);

          /* '<S45>:1:118' */
          /* '<S45>:1:119' */
          /* '<S45>:1:120' */
          if ((fabs(theta_hold[imgCol - 1] - color_areas[(int32_T)ii - 1]) <=
               0.17453292519943295) && (VisionModel_B.blob_area_p[(int32_T)ii -
               1] / positive_area <= 0.8) && c_0 && (sqrt(rt_pow_snf(((-(1.0 /
                    tan(theta[imgCol - 1]))) * jj + rho[imgCol - 1] / sin
                  (theta[imgCol - 1])) - VisionModel_B.blob_centroids_m
                 [(((int32_T)ii - 1) << 1U)], 2.0) + rt_pow_snf(jj -
                 VisionModel_B.blob_centroids_m[(((int32_T)ii - 1) << 1U) + 1],
                 2.0)) <= minL)) {
            /* '<S45>:1:121' */
            /* '<S45>:1:114' */
            /* '<S45>:1:121' */
            /*  Assume the first gate element was found correctly; */
            /*    check that all other gate elements are at right */
            /*    angles to the first */
            if (fabs(1.5707963267948966 - fabs(theta_hold[imgCol - 1] -
                  theta_hold[i - 1])) <= 0.17453292519943295) {
              /* '<S45>:1:134' */
              /* '<S45>:1:135' */
              find_white = imgCol;

              /* '<S45>:1:136' */
              rtb_Add1 = ii;
            }

            /* '<S45>:1:141' */
            theta_hold[imgCol - 1] = 1000.0;

            /*  Invalid angle; do not want this line to be selected again */
            /* '<S45>:1:142' */
            color_areas[(int32_T)ii - 1] = 1000.0;

            /* '<S45>:1:143' */
            current_color = 1;
            exitg_0 = TRUE;
          } else {
            ii++;
          }
        }

        if (current_color == 1) {
          /* '<S45>:1:149' */
          exitg = TRUE;
        } else {
          imgCol++;
        }
      }

      if ((i == 0) && (i_gate_idx == 0.0)) {
        /* '<S45>:1:157' */
        condition = TRUE;
      } else {
        /* '<S45>:1:157' */
        condition = FALSE;
      }

      if (!condition) {
        /* '<S45>:1:157' */
        /*  Sort elements of i_gate to place the vertical element in the first */
        /*    position, horizontal element in second position */
        /* '<S45>:1:161' */
        /* '<S45>:1:162' */
        ii = i_gate_idx;
        if (fabs(theta[i - 1]) > fabs(theta[find_white - 1])) {
          /* '<S45>:1:163' */
          /* '<S45>:1:164' */
          /* '<S45>:1:165' */
          i_gate_idx = rtb_Add1;

          /* '<S45>:1:167' */
          /* '<S45>:1:168' */
          rtb_Add1 = ii;
        }

        /*  Assign appropriate gate information */
        /* '<S45>:1:173' */
        /*  Compute targeting information */
        /*  Determine side lengths and distances for target */
        /* '<S45>:1:181' */
        /* '<S45>:1:182' */
        /* '<S45>:1:183' */
        ii = VisionModel_B.blob_major_axis_e[(int32_T)i_gate_idx - 1] *
          VisionModel_P.Constant1_Value_i;

        /* '<S45>:1:184' */
        minL = VisionModel_B.blob_major_axis_e[(int32_T)rtb_Add1 - 1] *
          VisionModel_P.Constant5_Value;

        /* '<S45>:1:186' */
        /* '<S45>:1:187' */
        /* '<S45>:1:188' */
        positive_area = 1.5707963267948966 - color_areas[(int32_T)i_gate_idx - 1];

        /* '<S45>:1:189' */
        jj = 1.5707963267948966 - color_areas[(int32_T)rtb_Add1 - 1];

        /* '<S45>:1:191' */
        /* '<S45>:1:192' */
        /* '<S45>:1:193' */
        /* '<S45>:1:194' */
        /* '<S45>:1:196' */
        maxL = VisionModel_B.blob_centroids_m[(((int32_T)i_gate_idx - 1) << 1U)
          + 1] * sin(positive_area) + VisionModel_B.blob_centroids_m[(((int32_T)
          i_gate_idx - 1) << 1U)] * cos(positive_area);

        /* '<S45>:1:197' */
        /* '<S45>:1:199' */
        r = (maxL * sin(jj) - (VisionModel_B.blob_centroids_m[(((int32_T)
                rtb_Add1 - 1) << 1U) + 1] * sin(jj) +
              VisionModel_B.blob_centroids_m[(((int32_T)rtb_Add1 - 1) << 1U)] *
              cos(jj)) * sin(positive_area)) * (1.0 / (cos(positive_area) * sin
          (jj) - cos(jj) * sin(positive_area)));

        /* '<S45>:1:200' */
        c = (-(1.0 / tan(positive_area))) * r + maxL / sin(positive_area);

        /* r3 = (1/( sin(phi1)*cos(phi2) - sin(phi2)*cos(phi1) ))*( c2 - c1 + sin(pih1)*cos(phi2)*r1 - sin(phi2)*cos(phi1)*r2 ); */
        /* c3 = r3*tan(phi1) + c1 - r1*tan(phi1); */
        /* '<S45>:1:204' */
        /* '<S45>:1:205' */
        /* '<S45>:1:207' */
        /* '<S45>:1:208' */
        /* '<S45>:1:213' */
        maxL = (sin(color_areas[(int32_T)i_gate_idx - 1]) * ii + c) * sin
          (positive_area) + (r - cos(color_areas[(int32_T)i_gate_idx - 1]) * ii)
          * cos(positive_area);

        /* '<S45>:1:214' */
        /* '<S45>:1:216' */
        ii = (maxL * sin(jj) - ((cos(color_areas[(int32_T)rtb_Add1 - 1]) * minL
                + c) * sin(jj) + (sin(color_areas[(int32_T)rtb_Add1 - 1]) * minL
                + r) * cos(jj)) * sin(positive_area)) * (1.0 / (cos
          (positive_area) * sin(jj) - cos(jj) * sin(positive_area)));

        /* '<S45>:1:217' */
        /*  Transform target r, c to global coordinate system */
        /* '<S45>:1:222' */
        VisionModel_B.target_z = ii - floor
          (VisionModel_P.Forward_Camera_Dimensions_Val_h[0] / 2.0);

        /* '<S45>:1:223' */
        ii = ((-(1.0 / tan(positive_area))) * ii + maxL / sin(positive_area)) -
          floor(VisionModel_P.Forward_Camera_Dimensions_Val_h[1] / 2.0);

        /* '<S45>:1:225' */
        VisionModel_B.target_yaw = ii /
          VisionModel_P.Forward_Camera_Dimensions_Val_h[1] *
          VisionModel_P.Constant2_Value_f;

        /* '<S45>:1:226' */
        VisionModel_B.target_detected = 0.0;
      } else {
        /* '<S45>:1:230' */
        ii = 0.0;

        /* '<S45>:1:231' */
        VisionModel_B.target_z = 0.0;

        /* '<S45>:1:232' */
        VisionModel_B.target_yaw = 0.0;

        /* '<S45>:1:233' */
        VisionModel_B.target_detected = 0.0;
      }

      VisionModel_B.target_y = ii;

      /* If: '<S8>/If1' incorporates:
       *  ActionPort: '<S46>/Action Port'
       *  Inport: '<Root>/OutputImage'
       *  SubSystem: '<S8>/If Action Subsystem'
       */
      if (VisionModel_U.OutputImage > 0.0) {
        VisionModel_IfActionSubsystem(VisionModel_B.bw_image_e,
          VisionModel_P.which_camera_Value_hj, 0.0, VisionModel_B.target_y,
          VisionModel_B.target_z, VisionModel_P.Forward_Camera_Dimensions2_Va_e,
          &VisionModel_B.IfActionSubsystem_mw, (rtP_IfActionSubsystem_VisionMod *)
          &VisionModel_P.IfActionSubsystem_mw);
      }
    }
  }

  for (i = 0; i < 19200; i++) {
    /* Outport: '<Root>/R_forward_out' incorporates:
     *  Sum: '<Root>/Add22'
     */
    VisionModel_Y.R_forward_out[i] = ((VisionModel_B.DrawShapes_o1[i] +
      VisionModel_B.IfActionSubsystem_h.DrawTarget_o1[i]) +
      VisionModel_B.IfActionSubsystem_l.DrawTarget_o1[i]) +
      VisionModel_B.IfActionSubsystem_mw.DrawTarget_o1[i];

    /* Outport: '<Root>/G_forward_out' incorporates:
     *  Sum: '<Root>/Add23'
     */
    VisionModel_Y.G_forward_out[i] = ((VisionModel_B.DrawShapes_o2[i] +
      VisionModel_B.IfActionSubsystem_h.DrawTarget_o2[i]) +
      VisionModel_B.IfActionSubsystem_l.DrawTarget_o2[i]) +
      VisionModel_B.IfActionSubsystem_mw.DrawTarget_o2[i];

    /* Outport: '<Root>/B_forward_out' incorporates:
     *  Sum: '<Root>/Add24'
     */
    VisionModel_Y.B_forward_out[i] = ((VisionModel_B.DrawShapes_o3[i] +
      VisionModel_B.IfActionSubsystem_h.DrawTarget_o3[i]) +
      VisionModel_B.IfActionSubsystem_l.DrawTarget_o3[i]) +
      VisionModel_B.IfActionSubsystem_mw.DrawTarget_o3[i];
  }

  for (i = 0; i < 9; i++) {
    /* Outport: '<Root>/R_down_out' */
    VisionModel_Y.R_down_out[i] = VisionModel_B.bw_image[i];

    /* Outport: '<Root>/G_down_out' */
    VisionModel_Y.G_down_out[i] = VisionModel_B.bw_image[i];

    /* Outport: '<Root>/B_down_out' */
    VisionModel_Y.B_down_out[i] = VisionModel_B.bw_image[i];
  }

  /* Outport: '<Root>/TargetSelect' incorporates:
   *  Sum: '<Root>/Add'
   */
  VisionModel_Y.TargetSelect = (((VisionModel_B.Constant3 +
    VisionModel_B.ColorFilter1) + VisionModel_B.target_select_f) +
    VisionModel_B.target_select_j) + VisionModel_B.target_select;

  /* Outport: '<Root>/TargetX' incorporates:
   *  Sum: '<Root>/Add3'
   */
  VisionModel_Y.TargetX = VisionModel_B.target_x;

  /* Outport: '<Root>/TargetY' incorporates:
   *  Sum: '<Root>/Add4'
   */
  VisionModel_Y.TargetY = (((VisionModel_B.target_y_c + VisionModel_B.target_y_i)
    + VisionModel_B.targetY) + VisionModel_B.target_y_m) +
    VisionModel_B.target_y;

  /* Outport: '<Root>/TargetZ' incorporates:
   *  Sum: '<Root>/Add5'
   */
  VisionModel_Y.TargetZ = ((VisionModel_B.target_z_o + VisionModel_B.targetZ) +
    VisionModel_B.target_z_d) + VisionModel_B.target_z;

  /* Outport: '<Root>/TargetYaw' incorporates:
   *  Sum: '<Root>/Add6'
   */
  VisionModel_Y.TargetYaw = (((VisionModel_B.target_yaw_o + VisionModel_B.Add18)
    + VisionModel_B.targetYaw) + VisionModel_B.target_yaw_k) +
    VisionModel_B.target_yaw;

  /* Outport: '<Root>/TargetDetected' incorporates:
   *  Sum: '<Root>/Add18'
   */
  VisionModel_Y.TargetDetected = (((VisionModel_B.gate_found +
    VisionModel_B.path_found) + VisionModel_B.target_detected_d) +
    VisionModel_B.target_detected_e) + VisionModel_B.target_detected;

  /* Outport: '<Root>/PathState' incorporates:
   *  Sum: '<Root>/Add19'
   */
  VisionModel_Y.PathState = VisionModel_B.path_state;

  /* Outport: '<Root>/BuoyColors' */
  memcpy((void *)(&VisionModel_Y.BuoyColors[0]), (void *)
         (&VisionModel_B.buoy_centroids[0]), 100U * sizeof(real_T));

  /* Outport: '<Root>/FireAuthorization' incorporates:
   *  Sum: '<Root>/Add21'
   */
  VisionModel_Y.FireAuthorization = VisionModel_B.fire_authorization;

  /* Outport: '<Root>/TargetType' */
  VisionModel_Y.TargetType = 0.0;

  /* Outport: '<Root>/TargetSize' */
  memcpy((void *)(&VisionModel_Y.TargetSize[0]), (void *)
         (&VisionModel_B.bw_image[0]), 9U * sizeof(real_T));

  /* Outport: '<Root>/B_forward_out1' */
  memcpy((void *)(&VisionModel_Y.B_forward_out1[0]), (void *)
         (&VisionModel_B.a_range[0]), 14U * sizeof(real_T));

  /* Embedded MATLAB: '<Root>/Blob Extraction1' */
  /* Embedded MATLAB Function 'Blob Extraction1': '<S1>:1' */
  /*  7-15-11 */
  /*  This function exists solely to solve an untraceable parsing error in the */
  /*    Simulink compiler. This error has to do with having two Blob Analysis */
  /*    function blocks in the same model. */
  /* '<S1>:1:8' */

  /* Outport: '<Root>/DesiredTargetX' incorporates:
   *  Constant: '<Root>/Constant'
   */
  VisionModel_Y.DesiredTargetX = VisionModel_P.Constant_Value_o;

  /* Outport: '<Root>/DesiredTargetY' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  VisionModel_Y.DesiredTargetY = VisionModel_P.Constant1_Value_k;

  /* Outport: '<Root>/DesiredTargetZ' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  VisionModel_Y.DesiredTargetZ = VisionModel_P.Constant2_Value_fh;

  /* Outport: '<Root>/DesiredTargetYaw' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  VisionModel_Y.DesiredTargetYaw = VisionModel_P.Constant3_Value_iy;
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

  {
    VisionModel_B.HoughTransform2_o2[0] = -1.5707963267948966;
    VisionModel_B.HoughTransform2_o2[1] = -1.5533430342749532;
    VisionModel_B.HoughTransform2_o2[2] = -1.53588974175501;
    VisionModel_B.HoughTransform2_o2[3] = -1.5184364492350666;
    VisionModel_B.HoughTransform2_o2[4] = -1.5009831567151235;
    VisionModel_B.HoughTransform2_o2[5] = -1.4835298641951802;
    VisionModel_B.HoughTransform2_o2[6] = -1.4660765716752369;
    VisionModel_B.HoughTransform2_o2[7] = -1.4486232791552935;
    VisionModel_B.HoughTransform2_o2[8] = -1.4311699866353502;
    VisionModel_B.HoughTransform2_o2[9] = -1.4137166941154069;
    VisionModel_B.HoughTransform2_o2[10] = -1.3962634015954636;
    VisionModel_B.HoughTransform2_o2[11] = -1.3788101090755203;
    VisionModel_B.HoughTransform2_o2[12] = -1.3613568165555769;
    VisionModel_B.HoughTransform2_o2[13] = -1.3439035240356338;
    VisionModel_B.HoughTransform2_o2[14] = -1.3264502315156905;
    VisionModel_B.HoughTransform2_o2[15] = -1.3089969389957472;
    VisionModel_B.HoughTransform2_o2[16] = -1.2915436464758039;
    VisionModel_B.HoughTransform2_o2[17] = -1.2740903539558606;
    VisionModel_B.HoughTransform2_o2[18] = -1.2566370614359172;
    VisionModel_B.HoughTransform2_o2[19] = -1.2391837689159739;
    VisionModel_B.HoughTransform2_o2[20] = -1.2217304763960306;
    VisionModel_B.HoughTransform2_o2[21] = -1.2042771838760873;
    VisionModel_B.HoughTransform2_o2[22] = -1.1868238913561442;
    VisionModel_B.HoughTransform2_o2[23] = -1.1693705988362009;
    VisionModel_B.HoughTransform2_o2[24] = -1.1519173063162575;
    VisionModel_B.HoughTransform2_o2[25] = -1.1344640137963142;
    VisionModel_B.HoughTransform2_o2[26] = -1.1170107212763709;
    VisionModel_B.HoughTransform2_o2[27] = -1.0995574287564276;
    VisionModel_B.HoughTransform2_o2[28] = -1.0821041362364843;
    VisionModel_B.HoughTransform2_o2[29] = -1.064650843716541;
    VisionModel_B.HoughTransform2_o2[30] = -1.0471975511965976;
    VisionModel_B.HoughTransform2_o2[31] = -1.0297442586766545;
    VisionModel_B.HoughTransform2_o2[32] = -1.0122909661567112;
    VisionModel_B.HoughTransform2_o2[33] = -0.99483767363676789;
    VisionModel_B.HoughTransform2_o2[34] = -0.97738438111682457;
    VisionModel_B.HoughTransform2_o2[35] = -0.95993108859688125;
    VisionModel_B.HoughTransform2_o2[36] = -0.94247779607693793;
    VisionModel_B.HoughTransform2_o2[37] = -0.92502450355699462;
    VisionModel_B.HoughTransform2_o2[38] = -0.90757121103705141;
    VisionModel_B.HoughTransform2_o2[39] = -0.89011791851710809;
    VisionModel_B.HoughTransform2_o2[40] = -0.87266462599716477;
    VisionModel_B.HoughTransform2_o2[41] = -0.85521133347722145;
    VisionModel_B.HoughTransform2_o2[42] = -0.83775804095727824;
    VisionModel_B.HoughTransform2_o2[43] = -0.82030474843733492;
    VisionModel_B.HoughTransform2_o2[44] = -0.8028514559173916;
    VisionModel_B.HoughTransform2_o2[45] = -0.78539816339744828;
    VisionModel_B.HoughTransform2_o2[46] = -0.767944870877505;
    VisionModel_B.HoughTransform2_o2[47] = -0.75049157835756175;
    VisionModel_B.HoughTransform2_o2[48] = -0.73303828583761843;
    VisionModel_B.HoughTransform2_o2[49] = -0.71558499331767511;
    VisionModel_B.HoughTransform2_o2[50] = -0.69813170079773179;
    VisionModel_B.HoughTransform2_o2[51] = -0.68067840827778847;
    VisionModel_B.HoughTransform2_o2[52] = -0.66322511575784526;
    VisionModel_B.HoughTransform2_o2[53] = -0.64577182323790194;
    VisionModel_B.HoughTransform2_o2[54] = -0.62831853071795862;
    VisionModel_B.HoughTransform2_o2[55] = -0.6108652381980153;
    VisionModel_B.HoughTransform2_o2[56] = -0.59341194567807209;
    VisionModel_B.HoughTransform2_o2[57] = -0.57595865315812877;
    VisionModel_B.HoughTransform2_o2[58] = -0.55850536063818546;
    VisionModel_B.HoughTransform2_o2[59] = -0.54105206811824214;
    VisionModel_B.HoughTransform2_o2[60] = -0.52359877559829882;
    VisionModel_B.HoughTransform2_o2[61] = -0.50614548307835561;
    VisionModel_B.HoughTransform2_o2[62] = -0.48869219055841229;
    VisionModel_B.HoughTransform2_o2[63] = -0.47123889803846897;
    VisionModel_B.HoughTransform2_o2[64] = -0.4537856055185257;
    VisionModel_B.HoughTransform2_o2[65] = -0.43633231299858238;
    VisionModel_B.HoughTransform2_o2[66] = -0.41887902047863912;
    VisionModel_B.HoughTransform2_o2[67] = -0.4014257279586958;
    VisionModel_B.HoughTransform2_o2[68] = -0.38397243543875248;
    VisionModel_B.HoughTransform2_o2[69] = -0.36651914291880922;
    VisionModel_B.HoughTransform2_o2[70] = -0.3490658503988659;
    VisionModel_B.HoughTransform2_o2[71] = -0.33161255787892263;
    VisionModel_B.HoughTransform2_o2[72] = -0.31415926535897931;
    VisionModel_B.HoughTransform2_o2[73] = -0.29670597283903605;
    VisionModel_B.HoughTransform2_o2[74] = -0.27925268031909273;
    VisionModel_B.HoughTransform2_o2[75] = -0.26179938779914941;
    VisionModel_B.HoughTransform2_o2[76] = -0.24434609527920614;
    VisionModel_B.HoughTransform2_o2[77] = -0.22689280275926285;
    VisionModel_B.HoughTransform2_o2[78] = -0.20943951023931956;
    VisionModel_B.HoughTransform2_o2[79] = -0.19198621771937624;
    VisionModel_B.HoughTransform2_o2[80] = -0.17453292519943295;
    VisionModel_B.HoughTransform2_o2[81] = -0.15707963267948966;
    VisionModel_B.HoughTransform2_o2[82] = -0.13962634015954636;
    VisionModel_B.HoughTransform2_o2[83] = -0.12217304763960307;
    VisionModel_B.HoughTransform2_o2[84] = -0.10471975511965978;
    VisionModel_B.HoughTransform2_o2[85] = -0.087266462599716474;
    VisionModel_B.HoughTransform2_o2[86] = -0.069813170079773182;
    VisionModel_B.HoughTransform2_o2[87] = -0.05235987755982989;
    VisionModel_B.HoughTransform2_o2[88] = -0.034906585039886591;
    VisionModel_B.HoughTransform2_o2[89] = -0.017453292519943295;
    VisionModel_B.HoughTransform2_o2[90] = 0.0;
    VisionModel_B.HoughTransform2_o2[91] = 0.017453292519943295;
    VisionModel_B.HoughTransform2_o2[92] = 0.034906585039886591;
    VisionModel_B.HoughTransform2_o2[93] = 0.05235987755982989;
    VisionModel_B.HoughTransform2_o2[94] = 0.069813170079773182;
    VisionModel_B.HoughTransform2_o2[95] = 0.087266462599716474;
    VisionModel_B.HoughTransform2_o2[96] = 0.10471975511965978;
    VisionModel_B.HoughTransform2_o2[97] = 0.12217304763960307;
    VisionModel_B.HoughTransform2_o2[98] = 0.13962634015954636;
    VisionModel_B.HoughTransform2_o2[99] = 0.15707963267948966;
    VisionModel_B.HoughTransform2_o2[100] = 0.17453292519943295;
    VisionModel_B.HoughTransform2_o2[101] = 0.19198621771937624;
    VisionModel_B.HoughTransform2_o2[102] = 0.20943951023931956;
    VisionModel_B.HoughTransform2_o2[103] = 0.22689280275926285;
    VisionModel_B.HoughTransform2_o2[104] = 0.24434609527920614;
    VisionModel_B.HoughTransform2_o2[105] = 0.26179938779914941;
    VisionModel_B.HoughTransform2_o2[106] = 0.27925268031909273;
    VisionModel_B.HoughTransform2_o2[107] = 0.29670597283903605;
    VisionModel_B.HoughTransform2_o2[108] = 0.31415926535897931;
    VisionModel_B.HoughTransform2_o2[109] = 0.33161255787892263;
    VisionModel_B.HoughTransform2_o2[110] = 0.3490658503988659;
    VisionModel_B.HoughTransform2_o2[111] = 0.36651914291880922;
    VisionModel_B.HoughTransform2_o2[112] = 0.38397243543875248;
    VisionModel_B.HoughTransform2_o2[113] = 0.4014257279586958;
    VisionModel_B.HoughTransform2_o2[114] = 0.41887902047863912;
    VisionModel_B.HoughTransform2_o2[115] = 0.43633231299858238;
    VisionModel_B.HoughTransform2_o2[116] = 0.4537856055185257;
    VisionModel_B.HoughTransform2_o2[117] = 0.47123889803846897;
    VisionModel_B.HoughTransform2_o2[118] = 0.48869219055841229;
    VisionModel_B.HoughTransform2_o2[119] = 0.50614548307835561;
    VisionModel_B.HoughTransform2_o2[120] = 0.52359877559829882;
    VisionModel_B.HoughTransform2_o2[121] = 0.54105206811824214;
    VisionModel_B.HoughTransform2_o2[122] = 0.55850536063818546;
    VisionModel_B.HoughTransform2_o2[123] = 0.57595865315812877;
    VisionModel_B.HoughTransform2_o2[124] = 0.59341194567807209;
    VisionModel_B.HoughTransform2_o2[125] = 0.6108652381980153;
    VisionModel_B.HoughTransform2_o2[126] = 0.62831853071795862;
    VisionModel_B.HoughTransform2_o2[127] = 0.64577182323790194;
    VisionModel_B.HoughTransform2_o2[128] = 0.66322511575784526;
    VisionModel_B.HoughTransform2_o2[129] = 0.68067840827778847;
    VisionModel_B.HoughTransform2_o2[130] = 0.69813170079773179;
    VisionModel_B.HoughTransform2_o2[131] = 0.71558499331767511;
    VisionModel_B.HoughTransform2_o2[132] = 0.73303828583761843;
    VisionModel_B.HoughTransform2_o2[133] = 0.75049157835756175;
    VisionModel_B.HoughTransform2_o2[134] = 0.767944870877505;
    VisionModel_B.HoughTransform2_o2[135] = 0.78539816339744828;
    VisionModel_B.HoughTransform2_o2[136] = 0.8028514559173916;
    VisionModel_B.HoughTransform2_o2[137] = 0.82030474843733492;
    VisionModel_B.HoughTransform2_o2[138] = 0.83775804095727824;
    VisionModel_B.HoughTransform2_o2[139] = 0.85521133347722145;
    VisionModel_B.HoughTransform2_o2[140] = 0.87266462599716477;
    VisionModel_B.HoughTransform2_o2[141] = 0.89011791851710809;
    VisionModel_B.HoughTransform2_o2[142] = 0.90757121103705141;
    VisionModel_B.HoughTransform2_o2[143] = 0.92502450355699462;
    VisionModel_B.HoughTransform2_o2[144] = 0.94247779607693793;
    VisionModel_B.HoughTransform2_o2[145] = 0.95993108859688125;
    VisionModel_B.HoughTransform2_o2[146] = 0.97738438111682457;
    VisionModel_B.HoughTransform2_o2[147] = 0.99483767363676789;
    VisionModel_B.HoughTransform2_o2[148] = 1.0122909661567112;
    VisionModel_B.HoughTransform2_o2[149] = 1.0297442586766545;
    VisionModel_B.HoughTransform2_o2[150] = 1.0471975511965976;
    VisionModel_B.HoughTransform2_o2[151] = 1.064650843716541;
    VisionModel_B.HoughTransform2_o2[152] = 1.0821041362364843;
    VisionModel_B.HoughTransform2_o2[153] = 1.0995574287564276;
    VisionModel_B.HoughTransform2_o2[154] = 1.1170107212763709;
    VisionModel_B.HoughTransform2_o2[155] = 1.1344640137963142;
    VisionModel_B.HoughTransform2_o2[156] = 1.1519173063162575;
    VisionModel_B.HoughTransform2_o2[157] = 1.1693705988362009;
    VisionModel_B.HoughTransform2_o2[158] = 1.1868238913561442;
    VisionModel_B.HoughTransform2_o2[159] = 1.2042771838760873;
    VisionModel_B.HoughTransform2_o2[160] = 1.2217304763960306;
    VisionModel_B.HoughTransform2_o2[161] = 1.2391837689159739;
    VisionModel_B.HoughTransform2_o2[162] = 1.2566370614359172;
    VisionModel_B.HoughTransform2_o2[163] = 1.2740903539558606;
    VisionModel_B.HoughTransform2_o2[164] = 1.2915436464758039;
    VisionModel_B.HoughTransform2_o2[165] = 1.3089969389957472;
    VisionModel_B.HoughTransform2_o2[166] = 1.3264502315156905;
    VisionModel_B.HoughTransform2_o2[167] = 1.3439035240356338;
    VisionModel_B.HoughTransform2_o2[168] = 1.3613568165555769;
    VisionModel_B.HoughTransform2_o2[169] = 1.3788101090755203;
    VisionModel_B.HoughTransform2_o2[170] = 1.3962634015954636;
    VisionModel_B.HoughTransform2_o2[171] = 1.4137166941154069;
    VisionModel_B.HoughTransform2_o2[172] = 1.4311699866353502;
    VisionModel_B.HoughTransform2_o2[173] = 1.4486232791552935;
    VisionModel_B.HoughTransform2_o2[174] = 1.4660765716752369;
    VisionModel_B.HoughTransform2_o2[175] = 1.4835298641951802;
    VisionModel_B.HoughTransform2_o2[176] = 1.5009831567151235;
    VisionModel_B.HoughTransform2_o2[177] = 1.5184364492350666;
    VisionModel_B.HoughTransform2_o2[178] = 1.53588974175501;
    VisionModel_B.HoughTransform2_o2[179] = 1.5533430342749532;
    VisionModel_B.HoughTransform2_o3[0] = -199.0;
    VisionModel_B.HoughTransform2_o3[1] = -198.0;
    VisionModel_B.HoughTransform2_o3[2] = -197.0;
    VisionModel_B.HoughTransform2_o3[3] = -196.0;
    VisionModel_B.HoughTransform2_o3[4] = -195.0;
    VisionModel_B.HoughTransform2_o3[5] = -194.0;
    VisionModel_B.HoughTransform2_o3[6] = -193.0;
    VisionModel_B.HoughTransform2_o3[7] = -192.0;
    VisionModel_B.HoughTransform2_o3[8] = -191.0;
    VisionModel_B.HoughTransform2_o3[9] = -190.0;
    VisionModel_B.HoughTransform2_o3[10] = -189.0;
    VisionModel_B.HoughTransform2_o3[11] = -188.0;
    VisionModel_B.HoughTransform2_o3[12] = -187.0;
    VisionModel_B.HoughTransform2_o3[13] = -186.0;
    VisionModel_B.HoughTransform2_o3[14] = -185.0;
    VisionModel_B.HoughTransform2_o3[15] = -184.0;
    VisionModel_B.HoughTransform2_o3[16] = -183.0;
    VisionModel_B.HoughTransform2_o3[17] = -182.0;
    VisionModel_B.HoughTransform2_o3[18] = -181.0;
    VisionModel_B.HoughTransform2_o3[19] = -180.0;
    VisionModel_B.HoughTransform2_o3[20] = -179.0;
    VisionModel_B.HoughTransform2_o3[21] = -178.0;
    VisionModel_B.HoughTransform2_o3[22] = -177.0;
    VisionModel_B.HoughTransform2_o3[23] = -176.0;
    VisionModel_B.HoughTransform2_o3[24] = -175.0;
    VisionModel_B.HoughTransform2_o3[25] = -174.0;
    VisionModel_B.HoughTransform2_o3[26] = -173.0;
    VisionModel_B.HoughTransform2_o3[27] = -172.0;
    VisionModel_B.HoughTransform2_o3[28] = -171.0;
    VisionModel_B.HoughTransform2_o3[29] = -170.0;
    VisionModel_B.HoughTransform2_o3[30] = -169.0;
    VisionModel_B.HoughTransform2_o3[31] = -168.0;
    VisionModel_B.HoughTransform2_o3[32] = -167.0;
    VisionModel_B.HoughTransform2_o3[33] = -166.0;
    VisionModel_B.HoughTransform2_o3[34] = -165.0;
    VisionModel_B.HoughTransform2_o3[35] = -164.0;
    VisionModel_B.HoughTransform2_o3[36] = -163.0;
    VisionModel_B.HoughTransform2_o3[37] = -162.0;
    VisionModel_B.HoughTransform2_o3[38] = -161.0;
    VisionModel_B.HoughTransform2_o3[39] = -160.0;
    VisionModel_B.HoughTransform2_o3[40] = -159.0;
    VisionModel_B.HoughTransform2_o3[41] = -158.0;
    VisionModel_B.HoughTransform2_o3[42] = -157.0;
    VisionModel_B.HoughTransform2_o3[43] = -156.0;
    VisionModel_B.HoughTransform2_o3[44] = -155.0;
    VisionModel_B.HoughTransform2_o3[45] = -154.0;
    VisionModel_B.HoughTransform2_o3[46] = -153.0;
    VisionModel_B.HoughTransform2_o3[47] = -152.0;
    VisionModel_B.HoughTransform2_o3[48] = -151.0;
    VisionModel_B.HoughTransform2_o3[49] = -150.0;
    VisionModel_B.HoughTransform2_o3[50] = -149.0;
    VisionModel_B.HoughTransform2_o3[51] = -148.0;
    VisionModel_B.HoughTransform2_o3[52] = -147.0;
    VisionModel_B.HoughTransform2_o3[53] = -146.0;
    VisionModel_B.HoughTransform2_o3[54] = -145.0;
    VisionModel_B.HoughTransform2_o3[55] = -144.0;
    VisionModel_B.HoughTransform2_o3[56] = -143.0;
    VisionModel_B.HoughTransform2_o3[57] = -142.0;
    VisionModel_B.HoughTransform2_o3[58] = -141.0;
    VisionModel_B.HoughTransform2_o3[59] = -140.0;
    VisionModel_B.HoughTransform2_o3[60] = -139.0;
    VisionModel_B.HoughTransform2_o3[61] = -138.0;
    VisionModel_B.HoughTransform2_o3[62] = -137.0;
    VisionModel_B.HoughTransform2_o3[63] = -136.0;
    VisionModel_B.HoughTransform2_o3[64] = -135.0;
    VisionModel_B.HoughTransform2_o3[65] = -134.0;
    VisionModel_B.HoughTransform2_o3[66] = -133.0;
    VisionModel_B.HoughTransform2_o3[67] = -132.0;
    VisionModel_B.HoughTransform2_o3[68] = -131.0;
    VisionModel_B.HoughTransform2_o3[69] = -130.0;
    VisionModel_B.HoughTransform2_o3[70] = -129.0;
    VisionModel_B.HoughTransform2_o3[71] = -128.0;
    VisionModel_B.HoughTransform2_o3[72] = -127.0;
    VisionModel_B.HoughTransform2_o3[73] = -126.0;
    VisionModel_B.HoughTransform2_o3[74] = -125.0;
    VisionModel_B.HoughTransform2_o3[75] = -124.0;
    VisionModel_B.HoughTransform2_o3[76] = -123.0;
    VisionModel_B.HoughTransform2_o3[77] = -122.0;
    VisionModel_B.HoughTransform2_o3[78] = -121.0;
    VisionModel_B.HoughTransform2_o3[79] = -120.0;
    VisionModel_B.HoughTransform2_o3[80] = -119.0;
    VisionModel_B.HoughTransform2_o3[81] = -118.0;
    VisionModel_B.HoughTransform2_o3[82] = -117.0;
    VisionModel_B.HoughTransform2_o3[83] = -116.0;
    VisionModel_B.HoughTransform2_o3[84] = -115.0;
    VisionModel_B.HoughTransform2_o3[85] = -114.0;
    VisionModel_B.HoughTransform2_o3[86] = -113.0;
    VisionModel_B.HoughTransform2_o3[87] = -112.0;
    VisionModel_B.HoughTransform2_o3[88] = -111.0;
    VisionModel_B.HoughTransform2_o3[89] = -110.0;
    VisionModel_B.HoughTransform2_o3[90] = -109.0;
    VisionModel_B.HoughTransform2_o3[91] = -108.0;
    VisionModel_B.HoughTransform2_o3[92] = -107.0;
    VisionModel_B.HoughTransform2_o3[93] = -106.0;
    VisionModel_B.HoughTransform2_o3[94] = -105.0;
    VisionModel_B.HoughTransform2_o3[95] = -104.0;
    VisionModel_B.HoughTransform2_o3[96] = -103.0;
    VisionModel_B.HoughTransform2_o3[97] = -102.0;
    VisionModel_B.HoughTransform2_o3[98] = -101.0;
    VisionModel_B.HoughTransform2_o3[99] = -100.0;
    VisionModel_B.HoughTransform2_o3[100] = -99.0;
    VisionModel_B.HoughTransform2_o3[101] = -98.0;
    VisionModel_B.HoughTransform2_o3[102] = -97.0;
    VisionModel_B.HoughTransform2_o3[103] = -96.0;
    VisionModel_B.HoughTransform2_o3[104] = -95.0;
    VisionModel_B.HoughTransform2_o3[105] = -94.0;
    VisionModel_B.HoughTransform2_o3[106] = -93.0;
    VisionModel_B.HoughTransform2_o3[107] = -92.0;
    VisionModel_B.HoughTransform2_o3[108] = -91.0;
    VisionModel_B.HoughTransform2_o3[109] = -90.0;
    VisionModel_B.HoughTransform2_o3[110] = -89.0;
    VisionModel_B.HoughTransform2_o3[111] = -88.0;
    VisionModel_B.HoughTransform2_o3[112] = -87.0;
    VisionModel_B.HoughTransform2_o3[113] = -86.0;
    VisionModel_B.HoughTransform2_o3[114] = -85.0;
    VisionModel_B.HoughTransform2_o3[115] = -84.0;
    VisionModel_B.HoughTransform2_o3[116] = -83.0;
    VisionModel_B.HoughTransform2_o3[117] = -82.0;
    VisionModel_B.HoughTransform2_o3[118] = -81.0;
    VisionModel_B.HoughTransform2_o3[119] = -80.0;
    VisionModel_B.HoughTransform2_o3[120] = -79.0;
    VisionModel_B.HoughTransform2_o3[121] = -78.0;
    VisionModel_B.HoughTransform2_o3[122] = -77.0;
    VisionModel_B.HoughTransform2_o3[123] = -76.0;
    VisionModel_B.HoughTransform2_o3[124] = -75.0;
    VisionModel_B.HoughTransform2_o3[125] = -74.0;
    VisionModel_B.HoughTransform2_o3[126] = -73.0;
    VisionModel_B.HoughTransform2_o3[127] = -72.0;
    VisionModel_B.HoughTransform2_o3[128] = -71.0;
    VisionModel_B.HoughTransform2_o3[129] = -70.0;
    VisionModel_B.HoughTransform2_o3[130] = -69.0;
    VisionModel_B.HoughTransform2_o3[131] = -68.0;
    VisionModel_B.HoughTransform2_o3[132] = -67.0;
    VisionModel_B.HoughTransform2_o3[133] = -66.0;
    VisionModel_B.HoughTransform2_o3[134] = -65.0;
    VisionModel_B.HoughTransform2_o3[135] = -64.0;
    VisionModel_B.HoughTransform2_o3[136] = -63.0;
    VisionModel_B.HoughTransform2_o3[137] = -62.0;
    VisionModel_B.HoughTransform2_o3[138] = -61.0;
    VisionModel_B.HoughTransform2_o3[139] = -60.0;
    VisionModel_B.HoughTransform2_o3[140] = -59.0;
    VisionModel_B.HoughTransform2_o3[141] = -58.0;
    VisionModel_B.HoughTransform2_o3[142] = -57.0;
    VisionModel_B.HoughTransform2_o3[143] = -56.0;
    VisionModel_B.HoughTransform2_o3[144] = -55.0;
    VisionModel_B.HoughTransform2_o3[145] = -54.0;
    VisionModel_B.HoughTransform2_o3[146] = -53.0;
    VisionModel_B.HoughTransform2_o3[147] = -52.0;
    VisionModel_B.HoughTransform2_o3[148] = -51.0;
    VisionModel_B.HoughTransform2_o3[149] = -50.0;
    VisionModel_B.HoughTransform2_o3[150] = -49.0;
    VisionModel_B.HoughTransform2_o3[151] = -48.0;
    VisionModel_B.HoughTransform2_o3[152] = -47.0;
    VisionModel_B.HoughTransform2_o3[153] = -46.0;
    VisionModel_B.HoughTransform2_o3[154] = -45.0;
    VisionModel_B.HoughTransform2_o3[155] = -44.0;
    VisionModel_B.HoughTransform2_o3[156] = -43.0;
    VisionModel_B.HoughTransform2_o3[157] = -42.0;
    VisionModel_B.HoughTransform2_o3[158] = -41.0;
    VisionModel_B.HoughTransform2_o3[159] = -40.0;
    VisionModel_B.HoughTransform2_o3[160] = -39.0;
    VisionModel_B.HoughTransform2_o3[161] = -38.0;
    VisionModel_B.HoughTransform2_o3[162] = -37.0;
    VisionModel_B.HoughTransform2_o3[163] = -36.0;
    VisionModel_B.HoughTransform2_o3[164] = -35.0;
    VisionModel_B.HoughTransform2_o3[165] = -34.0;
    VisionModel_B.HoughTransform2_o3[166] = -33.0;
    VisionModel_B.HoughTransform2_o3[167] = -32.0;
    VisionModel_B.HoughTransform2_o3[168] = -31.0;
    VisionModel_B.HoughTransform2_o3[169] = -30.0;
    VisionModel_B.HoughTransform2_o3[170] = -29.0;
    VisionModel_B.HoughTransform2_o3[171] = -28.0;
    VisionModel_B.HoughTransform2_o3[172] = -27.0;
    VisionModel_B.HoughTransform2_o3[173] = -26.0;
    VisionModel_B.HoughTransform2_o3[174] = -25.0;
    VisionModel_B.HoughTransform2_o3[175] = -24.0;
    VisionModel_B.HoughTransform2_o3[176] = -23.0;
    VisionModel_B.HoughTransform2_o3[177] = -22.0;
    VisionModel_B.HoughTransform2_o3[178] = -21.0;
    VisionModel_B.HoughTransform2_o3[179] = -20.0;
    VisionModel_B.HoughTransform2_o3[180] = -19.0;
    VisionModel_B.HoughTransform2_o3[181] = -18.0;
    VisionModel_B.HoughTransform2_o3[182] = -17.0;
    VisionModel_B.HoughTransform2_o3[183] = -16.0;
    VisionModel_B.HoughTransform2_o3[184] = -15.0;
    VisionModel_B.HoughTransform2_o3[185] = -14.0;
    VisionModel_B.HoughTransform2_o3[186] = -13.0;
    VisionModel_B.HoughTransform2_o3[187] = -12.0;
    VisionModel_B.HoughTransform2_o3[188] = -11.0;
    VisionModel_B.HoughTransform2_o3[189] = -10.0;
    VisionModel_B.HoughTransform2_o3[190] = -9.0;
    VisionModel_B.HoughTransform2_o3[191] = -8.0;
    VisionModel_B.HoughTransform2_o3[192] = -7.0;
    VisionModel_B.HoughTransform2_o3[193] = -6.0;
    VisionModel_B.HoughTransform2_o3[194] = -5.0;
    VisionModel_B.HoughTransform2_o3[195] = -4.0;
    VisionModel_B.HoughTransform2_o3[196] = -3.0;
    VisionModel_B.HoughTransform2_o3[197] = -2.0;
    VisionModel_B.HoughTransform2_o3[198] = -1.0;
    VisionModel_B.HoughTransform2_o3[199] = 0.0;
    VisionModel_B.HoughTransform2_o3[200] = 1.0;
    VisionModel_B.HoughTransform2_o3[201] = 2.0;
    VisionModel_B.HoughTransform2_o3[202] = 3.0;
    VisionModel_B.HoughTransform2_o3[203] = 4.0;
    VisionModel_B.HoughTransform2_o3[204] = 5.0;
    VisionModel_B.HoughTransform2_o3[205] = 6.0;
    VisionModel_B.HoughTransform2_o3[206] = 7.0;
    VisionModel_B.HoughTransform2_o3[207] = 8.0;
    VisionModel_B.HoughTransform2_o3[208] = 9.0;
    VisionModel_B.HoughTransform2_o3[209] = 10.0;
    VisionModel_B.HoughTransform2_o3[210] = 11.0;
    VisionModel_B.HoughTransform2_o3[211] = 12.0;
    VisionModel_B.HoughTransform2_o3[212] = 13.0;
    VisionModel_B.HoughTransform2_o3[213] = 14.0;
    VisionModel_B.HoughTransform2_o3[214] = 15.0;
    VisionModel_B.HoughTransform2_o3[215] = 16.0;
    VisionModel_B.HoughTransform2_o3[216] = 17.0;
    VisionModel_B.HoughTransform2_o3[217] = 18.0;
    VisionModel_B.HoughTransform2_o3[218] = 19.0;
    VisionModel_B.HoughTransform2_o3[219] = 20.0;
    VisionModel_B.HoughTransform2_o3[220] = 21.0;
    VisionModel_B.HoughTransform2_o3[221] = 22.0;
    VisionModel_B.HoughTransform2_o3[222] = 23.0;
    VisionModel_B.HoughTransform2_o3[223] = 24.0;
    VisionModel_B.HoughTransform2_o3[224] = 25.0;
    VisionModel_B.HoughTransform2_o3[225] = 26.0;
    VisionModel_B.HoughTransform2_o3[226] = 27.0;
    VisionModel_B.HoughTransform2_o3[227] = 28.0;
    VisionModel_B.HoughTransform2_o3[228] = 29.0;
    VisionModel_B.HoughTransform2_o3[229] = 30.0;
    VisionModel_B.HoughTransform2_o3[230] = 31.0;
    VisionModel_B.HoughTransform2_o3[231] = 32.0;
    VisionModel_B.HoughTransform2_o3[232] = 33.0;
    VisionModel_B.HoughTransform2_o3[233] = 34.0;
    VisionModel_B.HoughTransform2_o3[234] = 35.0;
    VisionModel_B.HoughTransform2_o3[235] = 36.0;
    VisionModel_B.HoughTransform2_o3[236] = 37.0;
    VisionModel_B.HoughTransform2_o3[237] = 38.0;
    VisionModel_B.HoughTransform2_o3[238] = 39.0;
    VisionModel_B.HoughTransform2_o3[239] = 40.0;
    VisionModel_B.HoughTransform2_o3[240] = 41.0;
    VisionModel_B.HoughTransform2_o3[241] = 42.0;
    VisionModel_B.HoughTransform2_o3[242] = 43.0;
    VisionModel_B.HoughTransform2_o3[243] = 44.0;
    VisionModel_B.HoughTransform2_o3[244] = 45.0;
    VisionModel_B.HoughTransform2_o3[245] = 46.0;
    VisionModel_B.HoughTransform2_o3[246] = 47.0;
    VisionModel_B.HoughTransform2_o3[247] = 48.0;
    VisionModel_B.HoughTransform2_o3[248] = 49.0;
    VisionModel_B.HoughTransform2_o3[249] = 50.0;
    VisionModel_B.HoughTransform2_o3[250] = 51.0;
    VisionModel_B.HoughTransform2_o3[251] = 52.0;
    VisionModel_B.HoughTransform2_o3[252] = 53.0;
    VisionModel_B.HoughTransform2_o3[253] = 54.0;
    VisionModel_B.HoughTransform2_o3[254] = 55.0;
    VisionModel_B.HoughTransform2_o3[255] = 56.0;
    VisionModel_B.HoughTransform2_o3[256] = 57.0;
    VisionModel_B.HoughTransform2_o3[257] = 58.0;
    VisionModel_B.HoughTransform2_o3[258] = 59.0;
    VisionModel_B.HoughTransform2_o3[259] = 60.0;
    VisionModel_B.HoughTransform2_o3[260] = 61.0;
    VisionModel_B.HoughTransform2_o3[261] = 62.0;
    VisionModel_B.HoughTransform2_o3[262] = 63.0;
    VisionModel_B.HoughTransform2_o3[263] = 64.0;
    VisionModel_B.HoughTransform2_o3[264] = 65.0;
    VisionModel_B.HoughTransform2_o3[265] = 66.0;
    VisionModel_B.HoughTransform2_o3[266] = 67.0;
    VisionModel_B.HoughTransform2_o3[267] = 68.0;
    VisionModel_B.HoughTransform2_o3[268] = 69.0;
    VisionModel_B.HoughTransform2_o3[269] = 70.0;
    VisionModel_B.HoughTransform2_o3[270] = 71.0;
    VisionModel_B.HoughTransform2_o3[271] = 72.0;
    VisionModel_B.HoughTransform2_o3[272] = 73.0;
    VisionModel_B.HoughTransform2_o3[273] = 74.0;
    VisionModel_B.HoughTransform2_o3[274] = 75.0;
    VisionModel_B.HoughTransform2_o3[275] = 76.0;
    VisionModel_B.HoughTransform2_o3[276] = 77.0;
    VisionModel_B.HoughTransform2_o3[277] = 78.0;
    VisionModel_B.HoughTransform2_o3[278] = 79.0;
    VisionModel_B.HoughTransform2_o3[279] = 80.0;
    VisionModel_B.HoughTransform2_o3[280] = 81.0;
    VisionModel_B.HoughTransform2_o3[281] = 82.0;
    VisionModel_B.HoughTransform2_o3[282] = 83.0;
    VisionModel_B.HoughTransform2_o3[283] = 84.0;
    VisionModel_B.HoughTransform2_o3[284] = 85.0;
    VisionModel_B.HoughTransform2_o3[285] = 86.0;
    VisionModel_B.HoughTransform2_o3[286] = 87.0;
    VisionModel_B.HoughTransform2_o3[287] = 88.0;
    VisionModel_B.HoughTransform2_o3[288] = 89.0;
    VisionModel_B.HoughTransform2_o3[289] = 90.0;
    VisionModel_B.HoughTransform2_o3[290] = 91.0;
    VisionModel_B.HoughTransform2_o3[291] = 92.0;
    VisionModel_B.HoughTransform2_o3[292] = 93.0;
    VisionModel_B.HoughTransform2_o3[293] = 94.0;
    VisionModel_B.HoughTransform2_o3[294] = 95.0;
    VisionModel_B.HoughTransform2_o3[295] = 96.0;
    VisionModel_B.HoughTransform2_o3[296] = 97.0;
    VisionModel_B.HoughTransform2_o3[297] = 98.0;
    VisionModel_B.HoughTransform2_o3[298] = 99.0;
    VisionModel_B.HoughTransform2_o3[299] = 100.0;
    VisionModel_B.HoughTransform2_o3[300] = 101.0;
    VisionModel_B.HoughTransform2_o3[301] = 102.0;
    VisionModel_B.HoughTransform2_o3[302] = 103.0;
    VisionModel_B.HoughTransform2_o3[303] = 104.0;
    VisionModel_B.HoughTransform2_o3[304] = 105.0;
    VisionModel_B.HoughTransform2_o3[305] = 106.0;
    VisionModel_B.HoughTransform2_o3[306] = 107.0;
    VisionModel_B.HoughTransform2_o3[307] = 108.0;
    VisionModel_B.HoughTransform2_o3[308] = 109.0;
    VisionModel_B.HoughTransform2_o3[309] = 110.0;
    VisionModel_B.HoughTransform2_o3[310] = 111.0;
    VisionModel_B.HoughTransform2_o3[311] = 112.0;
    VisionModel_B.HoughTransform2_o3[312] = 113.0;
    VisionModel_B.HoughTransform2_o3[313] = 114.0;
    VisionModel_B.HoughTransform2_o3[314] = 115.0;
    VisionModel_B.HoughTransform2_o3[315] = 116.0;
    VisionModel_B.HoughTransform2_o3[316] = 117.0;
    VisionModel_B.HoughTransform2_o3[317] = 118.0;
    VisionModel_B.HoughTransform2_o3[318] = 119.0;
    VisionModel_B.HoughTransform2_o3[319] = 120.0;
    VisionModel_B.HoughTransform2_o3[320] = 121.0;
    VisionModel_B.HoughTransform2_o3[321] = 122.0;
    VisionModel_B.HoughTransform2_o3[322] = 123.0;
    VisionModel_B.HoughTransform2_o3[323] = 124.0;
    VisionModel_B.HoughTransform2_o3[324] = 125.0;
    VisionModel_B.HoughTransform2_o3[325] = 126.0;
    VisionModel_B.HoughTransform2_o3[326] = 127.0;
    VisionModel_B.HoughTransform2_o3[327] = 128.0;
    VisionModel_B.HoughTransform2_o3[328] = 129.0;
    VisionModel_B.HoughTransform2_o3[329] = 130.0;
    VisionModel_B.HoughTransform2_o3[330] = 131.0;
    VisionModel_B.HoughTransform2_o3[331] = 132.0;
    VisionModel_B.HoughTransform2_o3[332] = 133.0;
    VisionModel_B.HoughTransform2_o3[333] = 134.0;
    VisionModel_B.HoughTransform2_o3[334] = 135.0;
    VisionModel_B.HoughTransform2_o3[335] = 136.0;
    VisionModel_B.HoughTransform2_o3[336] = 137.0;
    VisionModel_B.HoughTransform2_o3[337] = 138.0;
    VisionModel_B.HoughTransform2_o3[338] = 139.0;
    VisionModel_B.HoughTransform2_o3[339] = 140.0;
    VisionModel_B.HoughTransform2_o3[340] = 141.0;
    VisionModel_B.HoughTransform2_o3[341] = 142.0;
    VisionModel_B.HoughTransform2_o3[342] = 143.0;
    VisionModel_B.HoughTransform2_o3[343] = 144.0;
    VisionModel_B.HoughTransform2_o3[344] = 145.0;
    VisionModel_B.HoughTransform2_o3[345] = 146.0;
    VisionModel_B.HoughTransform2_o3[346] = 147.0;
    VisionModel_B.HoughTransform2_o3[347] = 148.0;
    VisionModel_B.HoughTransform2_o3[348] = 149.0;
    VisionModel_B.HoughTransform2_o3[349] = 150.0;
    VisionModel_B.HoughTransform2_o3[350] = 151.0;
    VisionModel_B.HoughTransform2_o3[351] = 152.0;
    VisionModel_B.HoughTransform2_o3[352] = 153.0;
    VisionModel_B.HoughTransform2_o3[353] = 154.0;
    VisionModel_B.HoughTransform2_o3[354] = 155.0;
    VisionModel_B.HoughTransform2_o3[355] = 156.0;
    VisionModel_B.HoughTransform2_o3[356] = 157.0;
    VisionModel_B.HoughTransform2_o3[357] = 158.0;
    VisionModel_B.HoughTransform2_o3[358] = 159.0;
    VisionModel_B.HoughTransform2_o3[359] = 160.0;
    VisionModel_B.HoughTransform2_o3[360] = 161.0;
    VisionModel_B.HoughTransform2_o3[361] = 162.0;
    VisionModel_B.HoughTransform2_o3[362] = 163.0;
    VisionModel_B.HoughTransform2_o3[363] = 164.0;
    VisionModel_B.HoughTransform2_o3[364] = 165.0;
    VisionModel_B.HoughTransform2_o3[365] = 166.0;
    VisionModel_B.HoughTransform2_o3[366] = 167.0;
    VisionModel_B.HoughTransform2_o3[367] = 168.0;
    VisionModel_B.HoughTransform2_o3[368] = 169.0;
    VisionModel_B.HoughTransform2_o3[369] = 170.0;
    VisionModel_B.HoughTransform2_o3[370] = 171.0;
    VisionModel_B.HoughTransform2_o3[371] = 172.0;
    VisionModel_B.HoughTransform2_o3[372] = 173.0;
    VisionModel_B.HoughTransform2_o3[373] = 174.0;
    VisionModel_B.HoughTransform2_o3[374] = 175.0;
    VisionModel_B.HoughTransform2_o3[375] = 176.0;
    VisionModel_B.HoughTransform2_o3[376] = 177.0;
    VisionModel_B.HoughTransform2_o3[377] = 178.0;
    VisionModel_B.HoughTransform2_o3[378] = 179.0;
    VisionModel_B.HoughTransform2_o3[379] = 180.0;
    VisionModel_B.HoughTransform2_o3[380] = 181.0;
    VisionModel_B.HoughTransform2_o3[381] = 182.0;
    VisionModel_B.HoughTransform2_o3[382] = 183.0;
    VisionModel_B.HoughTransform2_o3[383] = 184.0;
    VisionModel_B.HoughTransform2_o3[384] = 185.0;
    VisionModel_B.HoughTransform2_o3[385] = 186.0;
    VisionModel_B.HoughTransform2_o3[386] = 187.0;
    VisionModel_B.HoughTransform2_o3[387] = 188.0;
    VisionModel_B.HoughTransform2_o3[388] = 189.0;
    VisionModel_B.HoughTransform2_o3[389] = 190.0;
    VisionModel_B.HoughTransform2_o3[390] = 191.0;
    VisionModel_B.HoughTransform2_o3[391] = 192.0;
    VisionModel_B.HoughTransform2_o3[392] = 193.0;
    VisionModel_B.HoughTransform2_o3[393] = 194.0;
    VisionModel_B.HoughTransform2_o3[394] = 195.0;
    VisionModel_B.HoughTransform2_o3[395] = 196.0;
    VisionModel_B.HoughTransform2_o3[396] = 197.0;
    VisionModel_B.HoughTransform2_o3[397] = 198.0;
    VisionModel_B.HoughTransform2_o3[398] = 199.0;
    VisionModel_B.HoughTransform1_o2[0] = -1.5707963267948966;
    VisionModel_B.HoughTransform1_o2[1] = -1.5533430342749532;
    VisionModel_B.HoughTransform1_o2[2] = -1.53588974175501;
    VisionModel_B.HoughTransform1_o2[3] = -1.5184364492350666;
    VisionModel_B.HoughTransform1_o2[4] = -1.5009831567151235;
    VisionModel_B.HoughTransform1_o2[5] = -1.4835298641951802;
    VisionModel_B.HoughTransform1_o2[6] = -1.4660765716752369;
    VisionModel_B.HoughTransform1_o2[7] = -1.4486232791552935;
    VisionModel_B.HoughTransform1_o2[8] = -1.4311699866353502;
    VisionModel_B.HoughTransform1_o2[9] = -1.4137166941154069;
    VisionModel_B.HoughTransform1_o2[10] = -1.3962634015954636;
    VisionModel_B.HoughTransform1_o2[11] = -1.3788101090755203;
    VisionModel_B.HoughTransform1_o2[12] = -1.3613568165555769;
    VisionModel_B.HoughTransform1_o2[13] = -1.3439035240356338;
    VisionModel_B.HoughTransform1_o2[14] = -1.3264502315156905;
    VisionModel_B.HoughTransform1_o2[15] = -1.3089969389957472;
    VisionModel_B.HoughTransform1_o2[16] = -1.2915436464758039;
    VisionModel_B.HoughTransform1_o2[17] = -1.2740903539558606;
    VisionModel_B.HoughTransform1_o2[18] = -1.2566370614359172;
    VisionModel_B.HoughTransform1_o2[19] = -1.2391837689159739;
    VisionModel_B.HoughTransform1_o2[20] = -1.2217304763960306;
    VisionModel_B.HoughTransform1_o2[21] = -1.2042771838760873;
    VisionModel_B.HoughTransform1_o2[22] = -1.1868238913561442;
    VisionModel_B.HoughTransform1_o2[23] = -1.1693705988362009;
    VisionModel_B.HoughTransform1_o2[24] = -1.1519173063162575;
    VisionModel_B.HoughTransform1_o2[25] = -1.1344640137963142;
    VisionModel_B.HoughTransform1_o2[26] = -1.1170107212763709;
    VisionModel_B.HoughTransform1_o2[27] = -1.0995574287564276;
    VisionModel_B.HoughTransform1_o2[28] = -1.0821041362364843;
    VisionModel_B.HoughTransform1_o2[29] = -1.064650843716541;
    VisionModel_B.HoughTransform1_o2[30] = -1.0471975511965976;
    VisionModel_B.HoughTransform1_o2[31] = -1.0297442586766545;
    VisionModel_B.HoughTransform1_o2[32] = -1.0122909661567112;
    VisionModel_B.HoughTransform1_o2[33] = -0.99483767363676789;
    VisionModel_B.HoughTransform1_o2[34] = -0.97738438111682457;
    VisionModel_B.HoughTransform1_o2[35] = -0.95993108859688125;
    VisionModel_B.HoughTransform1_o2[36] = -0.94247779607693793;
    VisionModel_B.HoughTransform1_o2[37] = -0.92502450355699462;
    VisionModel_B.HoughTransform1_o2[38] = -0.90757121103705141;
    VisionModel_B.HoughTransform1_o2[39] = -0.89011791851710809;
    VisionModel_B.HoughTransform1_o2[40] = -0.87266462599716477;
    VisionModel_B.HoughTransform1_o2[41] = -0.85521133347722145;
    VisionModel_B.HoughTransform1_o2[42] = -0.83775804095727824;
    VisionModel_B.HoughTransform1_o2[43] = -0.82030474843733492;
    VisionModel_B.HoughTransform1_o2[44] = -0.8028514559173916;
    VisionModel_B.HoughTransform1_o2[45] = -0.78539816339744828;
    VisionModel_B.HoughTransform1_o2[46] = -0.767944870877505;
    VisionModel_B.HoughTransform1_o2[47] = -0.75049157835756175;
    VisionModel_B.HoughTransform1_o2[48] = -0.73303828583761843;
    VisionModel_B.HoughTransform1_o2[49] = -0.71558499331767511;
    VisionModel_B.HoughTransform1_o2[50] = -0.69813170079773179;
    VisionModel_B.HoughTransform1_o2[51] = -0.68067840827778847;
    VisionModel_B.HoughTransform1_o2[52] = -0.66322511575784526;
    VisionModel_B.HoughTransform1_o2[53] = -0.64577182323790194;
    VisionModel_B.HoughTransform1_o2[54] = -0.62831853071795862;
    VisionModel_B.HoughTransform1_o2[55] = -0.6108652381980153;
    VisionModel_B.HoughTransform1_o2[56] = -0.59341194567807209;
    VisionModel_B.HoughTransform1_o2[57] = -0.57595865315812877;
    VisionModel_B.HoughTransform1_o2[58] = -0.55850536063818546;
    VisionModel_B.HoughTransform1_o2[59] = -0.54105206811824214;
    VisionModel_B.HoughTransform1_o2[60] = -0.52359877559829882;
    VisionModel_B.HoughTransform1_o2[61] = -0.50614548307835561;
    VisionModel_B.HoughTransform1_o2[62] = -0.48869219055841229;
    VisionModel_B.HoughTransform1_o2[63] = -0.47123889803846897;
    VisionModel_B.HoughTransform1_o2[64] = -0.4537856055185257;
    VisionModel_B.HoughTransform1_o2[65] = -0.43633231299858238;
    VisionModel_B.HoughTransform1_o2[66] = -0.41887902047863912;
    VisionModel_B.HoughTransform1_o2[67] = -0.4014257279586958;
    VisionModel_B.HoughTransform1_o2[68] = -0.38397243543875248;
    VisionModel_B.HoughTransform1_o2[69] = -0.36651914291880922;
    VisionModel_B.HoughTransform1_o2[70] = -0.3490658503988659;
    VisionModel_B.HoughTransform1_o2[71] = -0.33161255787892263;
    VisionModel_B.HoughTransform1_o2[72] = -0.31415926535897931;
    VisionModel_B.HoughTransform1_o2[73] = -0.29670597283903605;
    VisionModel_B.HoughTransform1_o2[74] = -0.27925268031909273;
    VisionModel_B.HoughTransform1_o2[75] = -0.26179938779914941;
    VisionModel_B.HoughTransform1_o2[76] = -0.24434609527920614;
    VisionModel_B.HoughTransform1_o2[77] = -0.22689280275926285;
    VisionModel_B.HoughTransform1_o2[78] = -0.20943951023931956;
    VisionModel_B.HoughTransform1_o2[79] = -0.19198621771937624;
    VisionModel_B.HoughTransform1_o2[80] = -0.17453292519943295;
    VisionModel_B.HoughTransform1_o2[81] = -0.15707963267948966;
    VisionModel_B.HoughTransform1_o2[82] = -0.13962634015954636;
    VisionModel_B.HoughTransform1_o2[83] = -0.12217304763960307;
    VisionModel_B.HoughTransform1_o2[84] = -0.10471975511965978;
    VisionModel_B.HoughTransform1_o2[85] = -0.087266462599716474;
    VisionModel_B.HoughTransform1_o2[86] = -0.069813170079773182;
    VisionModel_B.HoughTransform1_o2[87] = -0.05235987755982989;
    VisionModel_B.HoughTransform1_o2[88] = -0.034906585039886591;
    VisionModel_B.HoughTransform1_o2[89] = -0.017453292519943295;
    VisionModel_B.HoughTransform1_o2[90] = 0.0;
    VisionModel_B.HoughTransform1_o2[91] = 0.017453292519943295;
    VisionModel_B.HoughTransform1_o2[92] = 0.034906585039886591;
    VisionModel_B.HoughTransform1_o2[93] = 0.05235987755982989;
    VisionModel_B.HoughTransform1_o2[94] = 0.069813170079773182;
    VisionModel_B.HoughTransform1_o2[95] = 0.087266462599716474;
    VisionModel_B.HoughTransform1_o2[96] = 0.10471975511965978;
    VisionModel_B.HoughTransform1_o2[97] = 0.12217304763960307;
    VisionModel_B.HoughTransform1_o2[98] = 0.13962634015954636;
    VisionModel_B.HoughTransform1_o2[99] = 0.15707963267948966;
    VisionModel_B.HoughTransform1_o2[100] = 0.17453292519943295;
    VisionModel_B.HoughTransform1_o2[101] = 0.19198621771937624;
    VisionModel_B.HoughTransform1_o2[102] = 0.20943951023931956;
    VisionModel_B.HoughTransform1_o2[103] = 0.22689280275926285;
    VisionModel_B.HoughTransform1_o2[104] = 0.24434609527920614;
    VisionModel_B.HoughTransform1_o2[105] = 0.26179938779914941;
    VisionModel_B.HoughTransform1_o2[106] = 0.27925268031909273;
    VisionModel_B.HoughTransform1_o2[107] = 0.29670597283903605;
    VisionModel_B.HoughTransform1_o2[108] = 0.31415926535897931;
    VisionModel_B.HoughTransform1_o2[109] = 0.33161255787892263;
    VisionModel_B.HoughTransform1_o2[110] = 0.3490658503988659;
    VisionModel_B.HoughTransform1_o2[111] = 0.36651914291880922;
    VisionModel_B.HoughTransform1_o2[112] = 0.38397243543875248;
    VisionModel_B.HoughTransform1_o2[113] = 0.4014257279586958;
    VisionModel_B.HoughTransform1_o2[114] = 0.41887902047863912;
    VisionModel_B.HoughTransform1_o2[115] = 0.43633231299858238;
    VisionModel_B.HoughTransform1_o2[116] = 0.4537856055185257;
    VisionModel_B.HoughTransform1_o2[117] = 0.47123889803846897;
    VisionModel_B.HoughTransform1_o2[118] = 0.48869219055841229;
    VisionModel_B.HoughTransform1_o2[119] = 0.50614548307835561;
    VisionModel_B.HoughTransform1_o2[120] = 0.52359877559829882;
    VisionModel_B.HoughTransform1_o2[121] = 0.54105206811824214;
    VisionModel_B.HoughTransform1_o2[122] = 0.55850536063818546;
    VisionModel_B.HoughTransform1_o2[123] = 0.57595865315812877;
    VisionModel_B.HoughTransform1_o2[124] = 0.59341194567807209;
    VisionModel_B.HoughTransform1_o2[125] = 0.6108652381980153;
    VisionModel_B.HoughTransform1_o2[126] = 0.62831853071795862;
    VisionModel_B.HoughTransform1_o2[127] = 0.64577182323790194;
    VisionModel_B.HoughTransform1_o2[128] = 0.66322511575784526;
    VisionModel_B.HoughTransform1_o2[129] = 0.68067840827778847;
    VisionModel_B.HoughTransform1_o2[130] = 0.69813170079773179;
    VisionModel_B.HoughTransform1_o2[131] = 0.71558499331767511;
    VisionModel_B.HoughTransform1_o2[132] = 0.73303828583761843;
    VisionModel_B.HoughTransform1_o2[133] = 0.75049157835756175;
    VisionModel_B.HoughTransform1_o2[134] = 0.767944870877505;
    VisionModel_B.HoughTransform1_o2[135] = 0.78539816339744828;
    VisionModel_B.HoughTransform1_o2[136] = 0.8028514559173916;
    VisionModel_B.HoughTransform1_o2[137] = 0.82030474843733492;
    VisionModel_B.HoughTransform1_o2[138] = 0.83775804095727824;
    VisionModel_B.HoughTransform1_o2[139] = 0.85521133347722145;
    VisionModel_B.HoughTransform1_o2[140] = 0.87266462599716477;
    VisionModel_B.HoughTransform1_o2[141] = 0.89011791851710809;
    VisionModel_B.HoughTransform1_o2[142] = 0.90757121103705141;
    VisionModel_B.HoughTransform1_o2[143] = 0.92502450355699462;
    VisionModel_B.HoughTransform1_o2[144] = 0.94247779607693793;
    VisionModel_B.HoughTransform1_o2[145] = 0.95993108859688125;
    VisionModel_B.HoughTransform1_o2[146] = 0.97738438111682457;
    VisionModel_B.HoughTransform1_o2[147] = 0.99483767363676789;
    VisionModel_B.HoughTransform1_o2[148] = 1.0122909661567112;
    VisionModel_B.HoughTransform1_o2[149] = 1.0297442586766545;
    VisionModel_B.HoughTransform1_o2[150] = 1.0471975511965976;
    VisionModel_B.HoughTransform1_o2[151] = 1.064650843716541;
    VisionModel_B.HoughTransform1_o2[152] = 1.0821041362364843;
    VisionModel_B.HoughTransform1_o2[153] = 1.0995574287564276;
    VisionModel_B.HoughTransform1_o2[154] = 1.1170107212763709;
    VisionModel_B.HoughTransform1_o2[155] = 1.1344640137963142;
    VisionModel_B.HoughTransform1_o2[156] = 1.1519173063162575;
    VisionModel_B.HoughTransform1_o2[157] = 1.1693705988362009;
    VisionModel_B.HoughTransform1_o2[158] = 1.1868238913561442;
    VisionModel_B.HoughTransform1_o2[159] = 1.2042771838760873;
    VisionModel_B.HoughTransform1_o2[160] = 1.2217304763960306;
    VisionModel_B.HoughTransform1_o2[161] = 1.2391837689159739;
    VisionModel_B.HoughTransform1_o2[162] = 1.2566370614359172;
    VisionModel_B.HoughTransform1_o2[163] = 1.2740903539558606;
    VisionModel_B.HoughTransform1_o2[164] = 1.2915436464758039;
    VisionModel_B.HoughTransform1_o2[165] = 1.3089969389957472;
    VisionModel_B.HoughTransform1_o2[166] = 1.3264502315156905;
    VisionModel_B.HoughTransform1_o2[167] = 1.3439035240356338;
    VisionModel_B.HoughTransform1_o2[168] = 1.3613568165555769;
    VisionModel_B.HoughTransform1_o2[169] = 1.3788101090755203;
    VisionModel_B.HoughTransform1_o2[170] = 1.3962634015954636;
    VisionModel_B.HoughTransform1_o2[171] = 1.4137166941154069;
    VisionModel_B.HoughTransform1_o2[172] = 1.4311699866353502;
    VisionModel_B.HoughTransform1_o2[173] = 1.4486232791552935;
    VisionModel_B.HoughTransform1_o2[174] = 1.4660765716752369;
    VisionModel_B.HoughTransform1_o2[175] = 1.4835298641951802;
    VisionModel_B.HoughTransform1_o2[176] = 1.5009831567151235;
    VisionModel_B.HoughTransform1_o2[177] = 1.5184364492350666;
    VisionModel_B.HoughTransform1_o2[178] = 1.53588974175501;
    VisionModel_B.HoughTransform1_o2[179] = 1.5533430342749532;
    VisionModel_B.HoughTransform1_o2_i[0] = -1.5707963267948966;
    VisionModel_B.HoughTransform1_o2_i[1] = -1.5533430342749532;
    VisionModel_B.HoughTransform1_o2_i[2] = -1.53588974175501;
    VisionModel_B.HoughTransform1_o2_i[3] = -1.5184364492350666;
    VisionModel_B.HoughTransform1_o2_i[4] = -1.5009831567151235;
    VisionModel_B.HoughTransform1_o2_i[5] = -1.4835298641951802;
    VisionModel_B.HoughTransform1_o2_i[6] = -1.4660765716752369;
    VisionModel_B.HoughTransform1_o2_i[7] = -1.4486232791552935;
    VisionModel_B.HoughTransform1_o2_i[8] = -1.4311699866353502;
    VisionModel_B.HoughTransform1_o2_i[9] = -1.4137166941154069;
    VisionModel_B.HoughTransform1_o2_i[10] = -1.3962634015954636;
    VisionModel_B.HoughTransform1_o2_i[11] = -1.3788101090755203;
    VisionModel_B.HoughTransform1_o2_i[12] = -1.3613568165555769;
    VisionModel_B.HoughTransform1_o2_i[13] = -1.3439035240356338;
    VisionModel_B.HoughTransform1_o2_i[14] = -1.3264502315156905;
    VisionModel_B.HoughTransform1_o2_i[15] = -1.3089969389957472;
    VisionModel_B.HoughTransform1_o2_i[16] = -1.2915436464758039;
    VisionModel_B.HoughTransform1_o2_i[17] = -1.2740903539558606;
    VisionModel_B.HoughTransform1_o2_i[18] = -1.2566370614359172;
    VisionModel_B.HoughTransform1_o2_i[19] = -1.2391837689159739;
    VisionModel_B.HoughTransform1_o2_i[20] = -1.2217304763960306;
    VisionModel_B.HoughTransform1_o2_i[21] = -1.2042771838760873;
    VisionModel_B.HoughTransform1_o2_i[22] = -1.1868238913561442;
    VisionModel_B.HoughTransform1_o2_i[23] = -1.1693705988362009;
    VisionModel_B.HoughTransform1_o2_i[24] = -1.1519173063162575;
    VisionModel_B.HoughTransform1_o2_i[25] = -1.1344640137963142;
    VisionModel_B.HoughTransform1_o2_i[26] = -1.1170107212763709;
    VisionModel_B.HoughTransform1_o2_i[27] = -1.0995574287564276;
    VisionModel_B.HoughTransform1_o2_i[28] = -1.0821041362364843;
    VisionModel_B.HoughTransform1_o2_i[29] = -1.064650843716541;
    VisionModel_B.HoughTransform1_o2_i[30] = -1.0471975511965976;
    VisionModel_B.HoughTransform1_o2_i[31] = -1.0297442586766545;
    VisionModel_B.HoughTransform1_o2_i[32] = -1.0122909661567112;
    VisionModel_B.HoughTransform1_o2_i[33] = -0.99483767363676789;
    VisionModel_B.HoughTransform1_o2_i[34] = -0.97738438111682457;
    VisionModel_B.HoughTransform1_o2_i[35] = -0.95993108859688125;
    VisionModel_B.HoughTransform1_o2_i[36] = -0.94247779607693793;
    VisionModel_B.HoughTransform1_o2_i[37] = -0.92502450355699462;
    VisionModel_B.HoughTransform1_o2_i[38] = -0.90757121103705141;
    VisionModel_B.HoughTransform1_o2_i[39] = -0.89011791851710809;
    VisionModel_B.HoughTransform1_o2_i[40] = -0.87266462599716477;
    VisionModel_B.HoughTransform1_o2_i[41] = -0.85521133347722145;
    VisionModel_B.HoughTransform1_o2_i[42] = -0.83775804095727824;
    VisionModel_B.HoughTransform1_o2_i[43] = -0.82030474843733492;
    VisionModel_B.HoughTransform1_o2_i[44] = -0.8028514559173916;
    VisionModel_B.HoughTransform1_o2_i[45] = -0.78539816339744828;
    VisionModel_B.HoughTransform1_o2_i[46] = -0.767944870877505;
    VisionModel_B.HoughTransform1_o2_i[47] = -0.75049157835756175;
    VisionModel_B.HoughTransform1_o2_i[48] = -0.73303828583761843;
    VisionModel_B.HoughTransform1_o2_i[49] = -0.71558499331767511;
    VisionModel_B.HoughTransform1_o2_i[50] = -0.69813170079773179;
    VisionModel_B.HoughTransform1_o2_i[51] = -0.68067840827778847;
    VisionModel_B.HoughTransform1_o2_i[52] = -0.66322511575784526;
    VisionModel_B.HoughTransform1_o2_i[53] = -0.64577182323790194;
    VisionModel_B.HoughTransform1_o2_i[54] = -0.62831853071795862;
    VisionModel_B.HoughTransform1_o2_i[55] = -0.6108652381980153;
    VisionModel_B.HoughTransform1_o2_i[56] = -0.59341194567807209;
    VisionModel_B.HoughTransform1_o2_i[57] = -0.57595865315812877;
    VisionModel_B.HoughTransform1_o2_i[58] = -0.55850536063818546;
    VisionModel_B.HoughTransform1_o2_i[59] = -0.54105206811824214;
    VisionModel_B.HoughTransform1_o2_i[60] = -0.52359877559829882;
    VisionModel_B.HoughTransform1_o2_i[61] = -0.50614548307835561;
    VisionModel_B.HoughTransform1_o2_i[62] = -0.48869219055841229;
    VisionModel_B.HoughTransform1_o2_i[63] = -0.47123889803846897;
    VisionModel_B.HoughTransform1_o2_i[64] = -0.4537856055185257;
    VisionModel_B.HoughTransform1_o2_i[65] = -0.43633231299858238;
    VisionModel_B.HoughTransform1_o2_i[66] = -0.41887902047863912;
    VisionModel_B.HoughTransform1_o2_i[67] = -0.4014257279586958;
    VisionModel_B.HoughTransform1_o2_i[68] = -0.38397243543875248;
    VisionModel_B.HoughTransform1_o2_i[69] = -0.36651914291880922;
    VisionModel_B.HoughTransform1_o2_i[70] = -0.3490658503988659;
    VisionModel_B.HoughTransform1_o2_i[71] = -0.33161255787892263;
    VisionModel_B.HoughTransform1_o2_i[72] = -0.31415926535897931;
    VisionModel_B.HoughTransform1_o2_i[73] = -0.29670597283903605;
    VisionModel_B.HoughTransform1_o2_i[74] = -0.27925268031909273;
    VisionModel_B.HoughTransform1_o2_i[75] = -0.26179938779914941;
    VisionModel_B.HoughTransform1_o2_i[76] = -0.24434609527920614;
    VisionModel_B.HoughTransform1_o2_i[77] = -0.22689280275926285;
    VisionModel_B.HoughTransform1_o2_i[78] = -0.20943951023931956;
    VisionModel_B.HoughTransform1_o2_i[79] = -0.19198621771937624;
    VisionModel_B.HoughTransform1_o2_i[80] = -0.17453292519943295;
    VisionModel_B.HoughTransform1_o2_i[81] = -0.15707963267948966;
    VisionModel_B.HoughTransform1_o2_i[82] = -0.13962634015954636;
    VisionModel_B.HoughTransform1_o2_i[83] = -0.12217304763960307;
    VisionModel_B.HoughTransform1_o2_i[84] = -0.10471975511965978;
    VisionModel_B.HoughTransform1_o2_i[85] = -0.087266462599716474;
    VisionModel_B.HoughTransform1_o2_i[86] = -0.069813170079773182;
    VisionModel_B.HoughTransform1_o2_i[87] = -0.05235987755982989;
    VisionModel_B.HoughTransform1_o2_i[88] = -0.034906585039886591;
    VisionModel_B.HoughTransform1_o2_i[89] = -0.017453292519943295;
    VisionModel_B.HoughTransform1_o2_i[90] = 0.0;
    VisionModel_B.HoughTransform1_o2_i[91] = 0.017453292519943295;
    VisionModel_B.HoughTransform1_o2_i[92] = 0.034906585039886591;
    VisionModel_B.HoughTransform1_o2_i[93] = 0.05235987755982989;
    VisionModel_B.HoughTransform1_o2_i[94] = 0.069813170079773182;
    VisionModel_B.HoughTransform1_o2_i[95] = 0.087266462599716474;
    VisionModel_B.HoughTransform1_o2_i[96] = 0.10471975511965978;
    VisionModel_B.HoughTransform1_o2_i[97] = 0.12217304763960307;
    VisionModel_B.HoughTransform1_o2_i[98] = 0.13962634015954636;
    VisionModel_B.HoughTransform1_o2_i[99] = 0.15707963267948966;
    VisionModel_B.HoughTransform1_o2_i[100] = 0.17453292519943295;
    VisionModel_B.HoughTransform1_o2_i[101] = 0.19198621771937624;
    VisionModel_B.HoughTransform1_o2_i[102] = 0.20943951023931956;
    VisionModel_B.HoughTransform1_o2_i[103] = 0.22689280275926285;
    VisionModel_B.HoughTransform1_o2_i[104] = 0.24434609527920614;
    VisionModel_B.HoughTransform1_o2_i[105] = 0.26179938779914941;
    VisionModel_B.HoughTransform1_o2_i[106] = 0.27925268031909273;
    VisionModel_B.HoughTransform1_o2_i[107] = 0.29670597283903605;
    VisionModel_B.HoughTransform1_o2_i[108] = 0.31415926535897931;
    VisionModel_B.HoughTransform1_o2_i[109] = 0.33161255787892263;
    VisionModel_B.HoughTransform1_o2_i[110] = 0.3490658503988659;
    VisionModel_B.HoughTransform1_o2_i[111] = 0.36651914291880922;
    VisionModel_B.HoughTransform1_o2_i[112] = 0.38397243543875248;
    VisionModel_B.HoughTransform1_o2_i[113] = 0.4014257279586958;
    VisionModel_B.HoughTransform1_o2_i[114] = 0.41887902047863912;
    VisionModel_B.HoughTransform1_o2_i[115] = 0.43633231299858238;
    VisionModel_B.HoughTransform1_o2_i[116] = 0.4537856055185257;
    VisionModel_B.HoughTransform1_o2_i[117] = 0.47123889803846897;
    VisionModel_B.HoughTransform1_o2_i[118] = 0.48869219055841229;
    VisionModel_B.HoughTransform1_o2_i[119] = 0.50614548307835561;
    VisionModel_B.HoughTransform1_o2_i[120] = 0.52359877559829882;
    VisionModel_B.HoughTransform1_o2_i[121] = 0.54105206811824214;
    VisionModel_B.HoughTransform1_o2_i[122] = 0.55850536063818546;
    VisionModel_B.HoughTransform1_o2_i[123] = 0.57595865315812877;
    VisionModel_B.HoughTransform1_o2_i[124] = 0.59341194567807209;
    VisionModel_B.HoughTransform1_o2_i[125] = 0.6108652381980153;
    VisionModel_B.HoughTransform1_o2_i[126] = 0.62831853071795862;
    VisionModel_B.HoughTransform1_o2_i[127] = 0.64577182323790194;
    VisionModel_B.HoughTransform1_o2_i[128] = 0.66322511575784526;
    VisionModel_B.HoughTransform1_o2_i[129] = 0.68067840827778847;
    VisionModel_B.HoughTransform1_o2_i[130] = 0.69813170079773179;
    VisionModel_B.HoughTransform1_o2_i[131] = 0.71558499331767511;
    VisionModel_B.HoughTransform1_o2_i[132] = 0.73303828583761843;
    VisionModel_B.HoughTransform1_o2_i[133] = 0.75049157835756175;
    VisionModel_B.HoughTransform1_o2_i[134] = 0.767944870877505;
    VisionModel_B.HoughTransform1_o2_i[135] = 0.78539816339744828;
    VisionModel_B.HoughTransform1_o2_i[136] = 0.8028514559173916;
    VisionModel_B.HoughTransform1_o2_i[137] = 0.82030474843733492;
    VisionModel_B.HoughTransform1_o2_i[138] = 0.83775804095727824;
    VisionModel_B.HoughTransform1_o2_i[139] = 0.85521133347722145;
    VisionModel_B.HoughTransform1_o2_i[140] = 0.87266462599716477;
    VisionModel_B.HoughTransform1_o2_i[141] = 0.89011791851710809;
    VisionModel_B.HoughTransform1_o2_i[142] = 0.90757121103705141;
    VisionModel_B.HoughTransform1_o2_i[143] = 0.92502450355699462;
    VisionModel_B.HoughTransform1_o2_i[144] = 0.94247779607693793;
    VisionModel_B.HoughTransform1_o2_i[145] = 0.95993108859688125;
    VisionModel_B.HoughTransform1_o2_i[146] = 0.97738438111682457;
    VisionModel_B.HoughTransform1_o2_i[147] = 0.99483767363676789;
    VisionModel_B.HoughTransform1_o2_i[148] = 1.0122909661567112;
    VisionModel_B.HoughTransform1_o2_i[149] = 1.0297442586766545;
    VisionModel_B.HoughTransform1_o2_i[150] = 1.0471975511965976;
    VisionModel_B.HoughTransform1_o2_i[151] = 1.064650843716541;
    VisionModel_B.HoughTransform1_o2_i[152] = 1.0821041362364843;
    VisionModel_B.HoughTransform1_o2_i[153] = 1.0995574287564276;
    VisionModel_B.HoughTransform1_o2_i[154] = 1.1170107212763709;
    VisionModel_B.HoughTransform1_o2_i[155] = 1.1344640137963142;
    VisionModel_B.HoughTransform1_o2_i[156] = 1.1519173063162575;
    VisionModel_B.HoughTransform1_o2_i[157] = 1.1693705988362009;
    VisionModel_B.HoughTransform1_o2_i[158] = 1.1868238913561442;
    VisionModel_B.HoughTransform1_o2_i[159] = 1.2042771838760873;
    VisionModel_B.HoughTransform1_o2_i[160] = 1.2217304763960306;
    VisionModel_B.HoughTransform1_o2_i[161] = 1.2391837689159739;
    VisionModel_B.HoughTransform1_o2_i[162] = 1.2566370614359172;
    VisionModel_B.HoughTransform1_o2_i[163] = 1.2740903539558606;
    VisionModel_B.HoughTransform1_o2_i[164] = 1.2915436464758039;
    VisionModel_B.HoughTransform1_o2_i[165] = 1.3089969389957472;
    VisionModel_B.HoughTransform1_o2_i[166] = 1.3264502315156905;
    VisionModel_B.HoughTransform1_o2_i[167] = 1.3439035240356338;
    VisionModel_B.HoughTransform1_o2_i[168] = 1.3613568165555769;
    VisionModel_B.HoughTransform1_o2_i[169] = 1.3788101090755203;
    VisionModel_B.HoughTransform1_o2_i[170] = 1.3962634015954636;
    VisionModel_B.HoughTransform1_o2_i[171] = 1.4137166941154069;
    VisionModel_B.HoughTransform1_o2_i[172] = 1.4311699866353502;
    VisionModel_B.HoughTransform1_o2_i[173] = 1.4486232791552935;
    VisionModel_B.HoughTransform1_o2_i[174] = 1.4660765716752369;
    VisionModel_B.HoughTransform1_o2_i[175] = 1.4835298641951802;
    VisionModel_B.HoughTransform1_o2_i[176] = 1.5009831567151235;
    VisionModel_B.HoughTransform1_o2_i[177] = 1.5184364492350666;
    VisionModel_B.HoughTransform1_o2_i[178] = 1.53588974175501;
    VisionModel_B.HoughTransform1_o2_i[179] = 1.5533430342749532;
    VisionModel_B.HoughTransform1_o3_i[0] = -199.0;
    VisionModel_B.HoughTransform1_o3_i[1] = -198.0;
    VisionModel_B.HoughTransform1_o3_i[2] = -197.0;
    VisionModel_B.HoughTransform1_o3_i[3] = -196.0;
    VisionModel_B.HoughTransform1_o3_i[4] = -195.0;
    VisionModel_B.HoughTransform1_o3_i[5] = -194.0;
    VisionModel_B.HoughTransform1_o3_i[6] = -193.0;
    VisionModel_B.HoughTransform1_o3_i[7] = -192.0;
    VisionModel_B.HoughTransform1_o3_i[8] = -191.0;
    VisionModel_B.HoughTransform1_o3_i[9] = -190.0;
    VisionModel_B.HoughTransform1_o3_i[10] = -189.0;
    VisionModel_B.HoughTransform1_o3_i[11] = -188.0;
    VisionModel_B.HoughTransform1_o3_i[12] = -187.0;
    VisionModel_B.HoughTransform1_o3_i[13] = -186.0;
    VisionModel_B.HoughTransform1_o3_i[14] = -185.0;
    VisionModel_B.HoughTransform1_o3_i[15] = -184.0;
    VisionModel_B.HoughTransform1_o3_i[16] = -183.0;
    VisionModel_B.HoughTransform1_o3_i[17] = -182.0;
    VisionModel_B.HoughTransform1_o3_i[18] = -181.0;
    VisionModel_B.HoughTransform1_o3_i[19] = -180.0;
    VisionModel_B.HoughTransform1_o3_i[20] = -179.0;
    VisionModel_B.HoughTransform1_o3_i[21] = -178.0;
    VisionModel_B.HoughTransform1_o3_i[22] = -177.0;
    VisionModel_B.HoughTransform1_o3_i[23] = -176.0;
    VisionModel_B.HoughTransform1_o3_i[24] = -175.0;
    VisionModel_B.HoughTransform1_o3_i[25] = -174.0;
    VisionModel_B.HoughTransform1_o3_i[26] = -173.0;
    VisionModel_B.HoughTransform1_o3_i[27] = -172.0;
    VisionModel_B.HoughTransform1_o3_i[28] = -171.0;
    VisionModel_B.HoughTransform1_o3_i[29] = -170.0;
    VisionModel_B.HoughTransform1_o3_i[30] = -169.0;
    VisionModel_B.HoughTransform1_o3_i[31] = -168.0;
    VisionModel_B.HoughTransform1_o3_i[32] = -167.0;
    VisionModel_B.HoughTransform1_o3_i[33] = -166.0;
    VisionModel_B.HoughTransform1_o3_i[34] = -165.0;
    VisionModel_B.HoughTransform1_o3_i[35] = -164.0;
    VisionModel_B.HoughTransform1_o3_i[36] = -163.0;
    VisionModel_B.HoughTransform1_o3_i[37] = -162.0;
    VisionModel_B.HoughTransform1_o3_i[38] = -161.0;
    VisionModel_B.HoughTransform1_o3_i[39] = -160.0;
    VisionModel_B.HoughTransform1_o3_i[40] = -159.0;
    VisionModel_B.HoughTransform1_o3_i[41] = -158.0;
    VisionModel_B.HoughTransform1_o3_i[42] = -157.0;
    VisionModel_B.HoughTransform1_o3_i[43] = -156.0;
    VisionModel_B.HoughTransform1_o3_i[44] = -155.0;
    VisionModel_B.HoughTransform1_o3_i[45] = -154.0;
    VisionModel_B.HoughTransform1_o3_i[46] = -153.0;
    VisionModel_B.HoughTransform1_o3_i[47] = -152.0;
    VisionModel_B.HoughTransform1_o3_i[48] = -151.0;
    VisionModel_B.HoughTransform1_o3_i[49] = -150.0;
    VisionModel_B.HoughTransform1_o3_i[50] = -149.0;
    VisionModel_B.HoughTransform1_o3_i[51] = -148.0;
    VisionModel_B.HoughTransform1_o3_i[52] = -147.0;
    VisionModel_B.HoughTransform1_o3_i[53] = -146.0;
    VisionModel_B.HoughTransform1_o3_i[54] = -145.0;
    VisionModel_B.HoughTransform1_o3_i[55] = -144.0;
    VisionModel_B.HoughTransform1_o3_i[56] = -143.0;
    VisionModel_B.HoughTransform1_o3_i[57] = -142.0;
    VisionModel_B.HoughTransform1_o3_i[58] = -141.0;
    VisionModel_B.HoughTransform1_o3_i[59] = -140.0;
    VisionModel_B.HoughTransform1_o3_i[60] = -139.0;
    VisionModel_B.HoughTransform1_o3_i[61] = -138.0;
    VisionModel_B.HoughTransform1_o3_i[62] = -137.0;
    VisionModel_B.HoughTransform1_o3_i[63] = -136.0;
    VisionModel_B.HoughTransform1_o3_i[64] = -135.0;
    VisionModel_B.HoughTransform1_o3_i[65] = -134.0;
    VisionModel_B.HoughTransform1_o3_i[66] = -133.0;
    VisionModel_B.HoughTransform1_o3_i[67] = -132.0;
    VisionModel_B.HoughTransform1_o3_i[68] = -131.0;
    VisionModel_B.HoughTransform1_o3_i[69] = -130.0;
    VisionModel_B.HoughTransform1_o3_i[70] = -129.0;
    VisionModel_B.HoughTransform1_o3_i[71] = -128.0;
    VisionModel_B.HoughTransform1_o3_i[72] = -127.0;
    VisionModel_B.HoughTransform1_o3_i[73] = -126.0;
    VisionModel_B.HoughTransform1_o3_i[74] = -125.0;
    VisionModel_B.HoughTransform1_o3_i[75] = -124.0;
    VisionModel_B.HoughTransform1_o3_i[76] = -123.0;
    VisionModel_B.HoughTransform1_o3_i[77] = -122.0;
    VisionModel_B.HoughTransform1_o3_i[78] = -121.0;
    VisionModel_B.HoughTransform1_o3_i[79] = -120.0;
    VisionModel_B.HoughTransform1_o3_i[80] = -119.0;
    VisionModel_B.HoughTransform1_o3_i[81] = -118.0;
    VisionModel_B.HoughTransform1_o3_i[82] = -117.0;
    VisionModel_B.HoughTransform1_o3_i[83] = -116.0;
    VisionModel_B.HoughTransform1_o3_i[84] = -115.0;
    VisionModel_B.HoughTransform1_o3_i[85] = -114.0;
    VisionModel_B.HoughTransform1_o3_i[86] = -113.0;
    VisionModel_B.HoughTransform1_o3_i[87] = -112.0;
    VisionModel_B.HoughTransform1_o3_i[88] = -111.0;
    VisionModel_B.HoughTransform1_o3_i[89] = -110.0;
    VisionModel_B.HoughTransform1_o3_i[90] = -109.0;
    VisionModel_B.HoughTransform1_o3_i[91] = -108.0;
    VisionModel_B.HoughTransform1_o3_i[92] = -107.0;
    VisionModel_B.HoughTransform1_o3_i[93] = -106.0;
    VisionModel_B.HoughTransform1_o3_i[94] = -105.0;
    VisionModel_B.HoughTransform1_o3_i[95] = -104.0;
    VisionModel_B.HoughTransform1_o3_i[96] = -103.0;
    VisionModel_B.HoughTransform1_o3_i[97] = -102.0;
    VisionModel_B.HoughTransform1_o3_i[98] = -101.0;
    VisionModel_B.HoughTransform1_o3_i[99] = -100.0;
    VisionModel_B.HoughTransform1_o3_i[100] = -99.0;
    VisionModel_B.HoughTransform1_o3_i[101] = -98.0;
    VisionModel_B.HoughTransform1_o3_i[102] = -97.0;
    VisionModel_B.HoughTransform1_o3_i[103] = -96.0;
    VisionModel_B.HoughTransform1_o3_i[104] = -95.0;
    VisionModel_B.HoughTransform1_o3_i[105] = -94.0;
    VisionModel_B.HoughTransform1_o3_i[106] = -93.0;
    VisionModel_B.HoughTransform1_o3_i[107] = -92.0;
    VisionModel_B.HoughTransform1_o3_i[108] = -91.0;
    VisionModel_B.HoughTransform1_o3_i[109] = -90.0;
    VisionModel_B.HoughTransform1_o3_i[110] = -89.0;
    VisionModel_B.HoughTransform1_o3_i[111] = -88.0;
    VisionModel_B.HoughTransform1_o3_i[112] = -87.0;
    VisionModel_B.HoughTransform1_o3_i[113] = -86.0;
    VisionModel_B.HoughTransform1_o3_i[114] = -85.0;
    VisionModel_B.HoughTransform1_o3_i[115] = -84.0;
    VisionModel_B.HoughTransform1_o3_i[116] = -83.0;
    VisionModel_B.HoughTransform1_o3_i[117] = -82.0;
    VisionModel_B.HoughTransform1_o3_i[118] = -81.0;
    VisionModel_B.HoughTransform1_o3_i[119] = -80.0;
    VisionModel_B.HoughTransform1_o3_i[120] = -79.0;
    VisionModel_B.HoughTransform1_o3_i[121] = -78.0;
    VisionModel_B.HoughTransform1_o3_i[122] = -77.0;
    VisionModel_B.HoughTransform1_o3_i[123] = -76.0;
    VisionModel_B.HoughTransform1_o3_i[124] = -75.0;
    VisionModel_B.HoughTransform1_o3_i[125] = -74.0;
    VisionModel_B.HoughTransform1_o3_i[126] = -73.0;
    VisionModel_B.HoughTransform1_o3_i[127] = -72.0;
    VisionModel_B.HoughTransform1_o3_i[128] = -71.0;
    VisionModel_B.HoughTransform1_o3_i[129] = -70.0;
    VisionModel_B.HoughTransform1_o3_i[130] = -69.0;
    VisionModel_B.HoughTransform1_o3_i[131] = -68.0;
    VisionModel_B.HoughTransform1_o3_i[132] = -67.0;
    VisionModel_B.HoughTransform1_o3_i[133] = -66.0;
    VisionModel_B.HoughTransform1_o3_i[134] = -65.0;
    VisionModel_B.HoughTransform1_o3_i[135] = -64.0;
    VisionModel_B.HoughTransform1_o3_i[136] = -63.0;
    VisionModel_B.HoughTransform1_o3_i[137] = -62.0;
    VisionModel_B.HoughTransform1_o3_i[138] = -61.0;
    VisionModel_B.HoughTransform1_o3_i[139] = -60.0;
    VisionModel_B.HoughTransform1_o3_i[140] = -59.0;
    VisionModel_B.HoughTransform1_o3_i[141] = -58.0;
    VisionModel_B.HoughTransform1_o3_i[142] = -57.0;
    VisionModel_B.HoughTransform1_o3_i[143] = -56.0;
    VisionModel_B.HoughTransform1_o3_i[144] = -55.0;
    VisionModel_B.HoughTransform1_o3_i[145] = -54.0;
    VisionModel_B.HoughTransform1_o3_i[146] = -53.0;
    VisionModel_B.HoughTransform1_o3_i[147] = -52.0;
    VisionModel_B.HoughTransform1_o3_i[148] = -51.0;
    VisionModel_B.HoughTransform1_o3_i[149] = -50.0;
    VisionModel_B.HoughTransform1_o3_i[150] = -49.0;
    VisionModel_B.HoughTransform1_o3_i[151] = -48.0;
    VisionModel_B.HoughTransform1_o3_i[152] = -47.0;
    VisionModel_B.HoughTransform1_o3_i[153] = -46.0;
    VisionModel_B.HoughTransform1_o3_i[154] = -45.0;
    VisionModel_B.HoughTransform1_o3_i[155] = -44.0;
    VisionModel_B.HoughTransform1_o3_i[156] = -43.0;
    VisionModel_B.HoughTransform1_o3_i[157] = -42.0;
    VisionModel_B.HoughTransform1_o3_i[158] = -41.0;
    VisionModel_B.HoughTransform1_o3_i[159] = -40.0;
    VisionModel_B.HoughTransform1_o3_i[160] = -39.0;
    VisionModel_B.HoughTransform1_o3_i[161] = -38.0;
    VisionModel_B.HoughTransform1_o3_i[162] = -37.0;
    VisionModel_B.HoughTransform1_o3_i[163] = -36.0;
    VisionModel_B.HoughTransform1_o3_i[164] = -35.0;
    VisionModel_B.HoughTransform1_o3_i[165] = -34.0;
    VisionModel_B.HoughTransform1_o3_i[166] = -33.0;
    VisionModel_B.HoughTransform1_o3_i[167] = -32.0;
    VisionModel_B.HoughTransform1_o3_i[168] = -31.0;
    VisionModel_B.HoughTransform1_o3_i[169] = -30.0;
    VisionModel_B.HoughTransform1_o3_i[170] = -29.0;
    VisionModel_B.HoughTransform1_o3_i[171] = -28.0;
    VisionModel_B.HoughTransform1_o3_i[172] = -27.0;
    VisionModel_B.HoughTransform1_o3_i[173] = -26.0;
    VisionModel_B.HoughTransform1_o3_i[174] = -25.0;
    VisionModel_B.HoughTransform1_o3_i[175] = -24.0;
    VisionModel_B.HoughTransform1_o3_i[176] = -23.0;
    VisionModel_B.HoughTransform1_o3_i[177] = -22.0;
    VisionModel_B.HoughTransform1_o3_i[178] = -21.0;
    VisionModel_B.HoughTransform1_o3_i[179] = -20.0;
    VisionModel_B.HoughTransform1_o3_i[180] = -19.0;
    VisionModel_B.HoughTransform1_o3_i[181] = -18.0;
    VisionModel_B.HoughTransform1_o3_i[182] = -17.0;
    VisionModel_B.HoughTransform1_o3_i[183] = -16.0;
    VisionModel_B.HoughTransform1_o3_i[184] = -15.0;
    VisionModel_B.HoughTransform1_o3_i[185] = -14.0;
    VisionModel_B.HoughTransform1_o3_i[186] = -13.0;
    VisionModel_B.HoughTransform1_o3_i[187] = -12.0;
    VisionModel_B.HoughTransform1_o3_i[188] = -11.0;
    VisionModel_B.HoughTransform1_o3_i[189] = -10.0;
    VisionModel_B.HoughTransform1_o3_i[190] = -9.0;
    VisionModel_B.HoughTransform1_o3_i[191] = -8.0;
    VisionModel_B.HoughTransform1_o3_i[192] = -7.0;
    VisionModel_B.HoughTransform1_o3_i[193] = -6.0;
    VisionModel_B.HoughTransform1_o3_i[194] = -5.0;
    VisionModel_B.HoughTransform1_o3_i[195] = -4.0;
    VisionModel_B.HoughTransform1_o3_i[196] = -3.0;
    VisionModel_B.HoughTransform1_o3_i[197] = -2.0;
    VisionModel_B.HoughTransform1_o3_i[198] = -1.0;
    VisionModel_B.HoughTransform1_o3_i[199] = 0.0;
    VisionModel_B.HoughTransform1_o3_i[200] = 1.0;
    VisionModel_B.HoughTransform1_o3_i[201] = 2.0;
    VisionModel_B.HoughTransform1_o3_i[202] = 3.0;
    VisionModel_B.HoughTransform1_o3_i[203] = 4.0;
    VisionModel_B.HoughTransform1_o3_i[204] = 5.0;
    VisionModel_B.HoughTransform1_o3_i[205] = 6.0;
    VisionModel_B.HoughTransform1_o3_i[206] = 7.0;
    VisionModel_B.HoughTransform1_o3_i[207] = 8.0;
    VisionModel_B.HoughTransform1_o3_i[208] = 9.0;
    VisionModel_B.HoughTransform1_o3_i[209] = 10.0;
    VisionModel_B.HoughTransform1_o3_i[210] = 11.0;
    VisionModel_B.HoughTransform1_o3_i[211] = 12.0;
    VisionModel_B.HoughTransform1_o3_i[212] = 13.0;
    VisionModel_B.HoughTransform1_o3_i[213] = 14.0;
    VisionModel_B.HoughTransform1_o3_i[214] = 15.0;
    VisionModel_B.HoughTransform1_o3_i[215] = 16.0;
    VisionModel_B.HoughTransform1_o3_i[216] = 17.0;
    VisionModel_B.HoughTransform1_o3_i[217] = 18.0;
    VisionModel_B.HoughTransform1_o3_i[218] = 19.0;
    VisionModel_B.HoughTransform1_o3_i[219] = 20.0;
    VisionModel_B.HoughTransform1_o3_i[220] = 21.0;
    VisionModel_B.HoughTransform1_o3_i[221] = 22.0;
    VisionModel_B.HoughTransform1_o3_i[222] = 23.0;
    VisionModel_B.HoughTransform1_o3_i[223] = 24.0;
    VisionModel_B.HoughTransform1_o3_i[224] = 25.0;
    VisionModel_B.HoughTransform1_o3_i[225] = 26.0;
    VisionModel_B.HoughTransform1_o3_i[226] = 27.0;
    VisionModel_B.HoughTransform1_o3_i[227] = 28.0;
    VisionModel_B.HoughTransform1_o3_i[228] = 29.0;
    VisionModel_B.HoughTransform1_o3_i[229] = 30.0;
    VisionModel_B.HoughTransform1_o3_i[230] = 31.0;
    VisionModel_B.HoughTransform1_o3_i[231] = 32.0;
    VisionModel_B.HoughTransform1_o3_i[232] = 33.0;
    VisionModel_B.HoughTransform1_o3_i[233] = 34.0;
    VisionModel_B.HoughTransform1_o3_i[234] = 35.0;
    VisionModel_B.HoughTransform1_o3_i[235] = 36.0;
    VisionModel_B.HoughTransform1_o3_i[236] = 37.0;
    VisionModel_B.HoughTransform1_o3_i[237] = 38.0;
    VisionModel_B.HoughTransform1_o3_i[238] = 39.0;
    VisionModel_B.HoughTransform1_o3_i[239] = 40.0;
    VisionModel_B.HoughTransform1_o3_i[240] = 41.0;
    VisionModel_B.HoughTransform1_o3_i[241] = 42.0;
    VisionModel_B.HoughTransform1_o3_i[242] = 43.0;
    VisionModel_B.HoughTransform1_o3_i[243] = 44.0;
    VisionModel_B.HoughTransform1_o3_i[244] = 45.0;
    VisionModel_B.HoughTransform1_o3_i[245] = 46.0;
    VisionModel_B.HoughTransform1_o3_i[246] = 47.0;
    VisionModel_B.HoughTransform1_o3_i[247] = 48.0;
    VisionModel_B.HoughTransform1_o3_i[248] = 49.0;
    VisionModel_B.HoughTransform1_o3_i[249] = 50.0;
    VisionModel_B.HoughTransform1_o3_i[250] = 51.0;
    VisionModel_B.HoughTransform1_o3_i[251] = 52.0;
    VisionModel_B.HoughTransform1_o3_i[252] = 53.0;
    VisionModel_B.HoughTransform1_o3_i[253] = 54.0;
    VisionModel_B.HoughTransform1_o3_i[254] = 55.0;
    VisionModel_B.HoughTransform1_o3_i[255] = 56.0;
    VisionModel_B.HoughTransform1_o3_i[256] = 57.0;
    VisionModel_B.HoughTransform1_o3_i[257] = 58.0;
    VisionModel_B.HoughTransform1_o3_i[258] = 59.0;
    VisionModel_B.HoughTransform1_o3_i[259] = 60.0;
    VisionModel_B.HoughTransform1_o3_i[260] = 61.0;
    VisionModel_B.HoughTransform1_o3_i[261] = 62.0;
    VisionModel_B.HoughTransform1_o3_i[262] = 63.0;
    VisionModel_B.HoughTransform1_o3_i[263] = 64.0;
    VisionModel_B.HoughTransform1_o3_i[264] = 65.0;
    VisionModel_B.HoughTransform1_o3_i[265] = 66.0;
    VisionModel_B.HoughTransform1_o3_i[266] = 67.0;
    VisionModel_B.HoughTransform1_o3_i[267] = 68.0;
    VisionModel_B.HoughTransform1_o3_i[268] = 69.0;
    VisionModel_B.HoughTransform1_o3_i[269] = 70.0;
    VisionModel_B.HoughTransform1_o3_i[270] = 71.0;
    VisionModel_B.HoughTransform1_o3_i[271] = 72.0;
    VisionModel_B.HoughTransform1_o3_i[272] = 73.0;
    VisionModel_B.HoughTransform1_o3_i[273] = 74.0;
    VisionModel_B.HoughTransform1_o3_i[274] = 75.0;
    VisionModel_B.HoughTransform1_o3_i[275] = 76.0;
    VisionModel_B.HoughTransform1_o3_i[276] = 77.0;
    VisionModel_B.HoughTransform1_o3_i[277] = 78.0;
    VisionModel_B.HoughTransform1_o3_i[278] = 79.0;
    VisionModel_B.HoughTransform1_o3_i[279] = 80.0;
    VisionModel_B.HoughTransform1_o3_i[280] = 81.0;
    VisionModel_B.HoughTransform1_o3_i[281] = 82.0;
    VisionModel_B.HoughTransform1_o3_i[282] = 83.0;
    VisionModel_B.HoughTransform1_o3_i[283] = 84.0;
    VisionModel_B.HoughTransform1_o3_i[284] = 85.0;
    VisionModel_B.HoughTransform1_o3_i[285] = 86.0;
    VisionModel_B.HoughTransform1_o3_i[286] = 87.0;
    VisionModel_B.HoughTransform1_o3_i[287] = 88.0;
    VisionModel_B.HoughTransform1_o3_i[288] = 89.0;
    VisionModel_B.HoughTransform1_o3_i[289] = 90.0;
    VisionModel_B.HoughTransform1_o3_i[290] = 91.0;
    VisionModel_B.HoughTransform1_o3_i[291] = 92.0;
    VisionModel_B.HoughTransform1_o3_i[292] = 93.0;
    VisionModel_B.HoughTransform1_o3_i[293] = 94.0;
    VisionModel_B.HoughTransform1_o3_i[294] = 95.0;
    VisionModel_B.HoughTransform1_o3_i[295] = 96.0;
    VisionModel_B.HoughTransform1_o3_i[296] = 97.0;
    VisionModel_B.HoughTransform1_o3_i[297] = 98.0;
    VisionModel_B.HoughTransform1_o3_i[298] = 99.0;
    VisionModel_B.HoughTransform1_o3_i[299] = 100.0;
    VisionModel_B.HoughTransform1_o3_i[300] = 101.0;
    VisionModel_B.HoughTransform1_o3_i[301] = 102.0;
    VisionModel_B.HoughTransform1_o3_i[302] = 103.0;
    VisionModel_B.HoughTransform1_o3_i[303] = 104.0;
    VisionModel_B.HoughTransform1_o3_i[304] = 105.0;
    VisionModel_B.HoughTransform1_o3_i[305] = 106.0;
    VisionModel_B.HoughTransform1_o3_i[306] = 107.0;
    VisionModel_B.HoughTransform1_o3_i[307] = 108.0;
    VisionModel_B.HoughTransform1_o3_i[308] = 109.0;
    VisionModel_B.HoughTransform1_o3_i[309] = 110.0;
    VisionModel_B.HoughTransform1_o3_i[310] = 111.0;
    VisionModel_B.HoughTransform1_o3_i[311] = 112.0;
    VisionModel_B.HoughTransform1_o3_i[312] = 113.0;
    VisionModel_B.HoughTransform1_o3_i[313] = 114.0;
    VisionModel_B.HoughTransform1_o3_i[314] = 115.0;
    VisionModel_B.HoughTransform1_o3_i[315] = 116.0;
    VisionModel_B.HoughTransform1_o3_i[316] = 117.0;
    VisionModel_B.HoughTransform1_o3_i[317] = 118.0;
    VisionModel_B.HoughTransform1_o3_i[318] = 119.0;
    VisionModel_B.HoughTransform1_o3_i[319] = 120.0;
    VisionModel_B.HoughTransform1_o3_i[320] = 121.0;
    VisionModel_B.HoughTransform1_o3_i[321] = 122.0;
    VisionModel_B.HoughTransform1_o3_i[322] = 123.0;
    VisionModel_B.HoughTransform1_o3_i[323] = 124.0;
    VisionModel_B.HoughTransform1_o3_i[324] = 125.0;
    VisionModel_B.HoughTransform1_o3_i[325] = 126.0;
    VisionModel_B.HoughTransform1_o3_i[326] = 127.0;
    VisionModel_B.HoughTransform1_o3_i[327] = 128.0;
    VisionModel_B.HoughTransform1_o3_i[328] = 129.0;
    VisionModel_B.HoughTransform1_o3_i[329] = 130.0;
    VisionModel_B.HoughTransform1_o3_i[330] = 131.0;
    VisionModel_B.HoughTransform1_o3_i[331] = 132.0;
    VisionModel_B.HoughTransform1_o3_i[332] = 133.0;
    VisionModel_B.HoughTransform1_o3_i[333] = 134.0;
    VisionModel_B.HoughTransform1_o3_i[334] = 135.0;
    VisionModel_B.HoughTransform1_o3_i[335] = 136.0;
    VisionModel_B.HoughTransform1_o3_i[336] = 137.0;
    VisionModel_B.HoughTransform1_o3_i[337] = 138.0;
    VisionModel_B.HoughTransform1_o3_i[338] = 139.0;
    VisionModel_B.HoughTransform1_o3_i[339] = 140.0;
    VisionModel_B.HoughTransform1_o3_i[340] = 141.0;
    VisionModel_B.HoughTransform1_o3_i[341] = 142.0;
    VisionModel_B.HoughTransform1_o3_i[342] = 143.0;
    VisionModel_B.HoughTransform1_o3_i[343] = 144.0;
    VisionModel_B.HoughTransform1_o3_i[344] = 145.0;
    VisionModel_B.HoughTransform1_o3_i[345] = 146.0;
    VisionModel_B.HoughTransform1_o3_i[346] = 147.0;
    VisionModel_B.HoughTransform1_o3_i[347] = 148.0;
    VisionModel_B.HoughTransform1_o3_i[348] = 149.0;
    VisionModel_B.HoughTransform1_o3_i[349] = 150.0;
    VisionModel_B.HoughTransform1_o3_i[350] = 151.0;
    VisionModel_B.HoughTransform1_o3_i[351] = 152.0;
    VisionModel_B.HoughTransform1_o3_i[352] = 153.0;
    VisionModel_B.HoughTransform1_o3_i[353] = 154.0;
    VisionModel_B.HoughTransform1_o3_i[354] = 155.0;
    VisionModel_B.HoughTransform1_o3_i[355] = 156.0;
    VisionModel_B.HoughTransform1_o3_i[356] = 157.0;
    VisionModel_B.HoughTransform1_o3_i[357] = 158.0;
    VisionModel_B.HoughTransform1_o3_i[358] = 159.0;
    VisionModel_B.HoughTransform1_o3_i[359] = 160.0;
    VisionModel_B.HoughTransform1_o3_i[360] = 161.0;
    VisionModel_B.HoughTransform1_o3_i[361] = 162.0;
    VisionModel_B.HoughTransform1_o3_i[362] = 163.0;
    VisionModel_B.HoughTransform1_o3_i[363] = 164.0;
    VisionModel_B.HoughTransform1_o3_i[364] = 165.0;
    VisionModel_B.HoughTransform1_o3_i[365] = 166.0;
    VisionModel_B.HoughTransform1_o3_i[366] = 167.0;
    VisionModel_B.HoughTransform1_o3_i[367] = 168.0;
    VisionModel_B.HoughTransform1_o3_i[368] = 169.0;
    VisionModel_B.HoughTransform1_o3_i[369] = 170.0;
    VisionModel_B.HoughTransform1_o3_i[370] = 171.0;
    VisionModel_B.HoughTransform1_o3_i[371] = 172.0;
    VisionModel_B.HoughTransform1_o3_i[372] = 173.0;
    VisionModel_B.HoughTransform1_o3_i[373] = 174.0;
    VisionModel_B.HoughTransform1_o3_i[374] = 175.0;
    VisionModel_B.HoughTransform1_o3_i[375] = 176.0;
    VisionModel_B.HoughTransform1_o3_i[376] = 177.0;
    VisionModel_B.HoughTransform1_o3_i[377] = 178.0;
    VisionModel_B.HoughTransform1_o3_i[378] = 179.0;
    VisionModel_B.HoughTransform1_o3_i[379] = 180.0;
    VisionModel_B.HoughTransform1_o3_i[380] = 181.0;
    VisionModel_B.HoughTransform1_o3_i[381] = 182.0;
    VisionModel_B.HoughTransform1_o3_i[382] = 183.0;
    VisionModel_B.HoughTransform1_o3_i[383] = 184.0;
    VisionModel_B.HoughTransform1_o3_i[384] = 185.0;
    VisionModel_B.HoughTransform1_o3_i[385] = 186.0;
    VisionModel_B.HoughTransform1_o3_i[386] = 187.0;
    VisionModel_B.HoughTransform1_o3_i[387] = 188.0;
    VisionModel_B.HoughTransform1_o3_i[388] = 189.0;
    VisionModel_B.HoughTransform1_o3_i[389] = 190.0;
    VisionModel_B.HoughTransform1_o3_i[390] = 191.0;
    VisionModel_B.HoughTransform1_o3_i[391] = 192.0;
    VisionModel_B.HoughTransform1_o3_i[392] = 193.0;
    VisionModel_B.HoughTransform1_o3_i[393] = 194.0;
    VisionModel_B.HoughTransform1_o3_i[394] = 195.0;
    VisionModel_B.HoughTransform1_o3_i[395] = 196.0;
    VisionModel_B.HoughTransform1_o3_i[396] = 197.0;
    VisionModel_B.HoughTransform1_o3_i[397] = 198.0;
    VisionModel_B.HoughTransform1_o3_i[398] = 199.0;
  }

  /* states (dwork) */
  (void) memset((void *)&VisionModel_DWork, 0,
                sizeof(D_Work_VisionModel));

  /* external inputs */
  (void) memset((void *)&VisionModel_U, 0,
                sizeof(ExternalInputs_VisionModel));

  /* external outputs */
  (void) memset((void *)&VisionModel_Y, 0,
                sizeof(ExternalOutputs_VisionModel));

  {
    int32_T i;
    static int16_T tmp[8] = { -1, 161, 162, 163, 1, -161, -162, -163 };

    static int8_T tmp_0[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

    /* Start for ifaction SubSystem: '<Root>/Blob_Analysis' */

    /* InitializeConditions for Embedded MATLAB: '<S3>/Blob Extraction' */
    VisionModel_DWork.F0_RTP_a = -1;
    VisionModel_DWork.F1_RTP_m = -1.0;
    VisionModel_DWork.F2_RTP_m = -1;
    VisionModel_DWork.F3_RTP_k = -1.0;
    VisionModel_DWork.F4_RTP_j = -1.0;
    VisionModel_DWork.F5_RTP_p = -1.0;
    VisionModel_DWork.F6_RTP_k = -1.0;
    VisionModel_DWork.F7_RTP_j = -1.0;
    VisionModel_DWork.MINAREA_RTP_h = 5U;

    /* end of Start for SubSystem: '<Root>/Blob_Analysis' */

    /* Start for ifaction SubSystem: '<Root>/Blob_Analysis1' */

    /* InitializeConditions for Embedded MATLAB: '<S4>/Blob Extraction' */
    for (i = 0; i < 8; i++) {
      VisionModel_DWork.WALKER_RTP_f[i] = tmp[i];
      VisionModel_DWork.WALKER_RTP[i] = tmp_0[i];
    }

    VisionModel_DWork.F0_RTP = -1;
    VisionModel_DWork.F1_RTP = -1.0;
    VisionModel_DWork.F2_RTP = -1;
    VisionModel_DWork.F3_RTP = -1.0;
    VisionModel_DWork.F4_RTP = -1.0;
    VisionModel_DWork.F5_RTP = -1.0;
    VisionModel_DWork.F6_RTP = -1.0;
    VisionModel_DWork.F7_RTP = -1.0;
    VisionModel_DWork.MINAREA_RTP = 5U;

    /* end of Start for SubSystem: '<Root>/Blob_Analysis1' */

    /* Start for ifaction SubSystem: '<Root>/validation_gate' */

    /* InitializeConditions for S-Function (svipedge): '<S14>/Edge Detection' */
    VisionModel_DWork.EdgeDetection_MEAN_FACTOR_DW_j = 5.2083333333333337E-5;

    /* end of Start for SubSystem: '<Root>/validation_gate' */

    /* Start for ifaction SubSystem: '<Root>/L_detector' */

    /* InitializeConditions for S-Function (svipedge): '<S8>/Edge Detection1' */
    VisionModel_DWork.EdgeDetection1_MEAN_FACTOR_DW = 5.2083333333333337E-5;

    /* end of Start for SubSystem: '<Root>/L_detector' */

    /* Start for ifaction SubSystem: '<Root>/path_detector' */

    /* InitializeConditions for S-Function (svipedge): '<S12>/Edge Detection' */
    VisionModel_DWork.EdgeDetection_MEAN_FACTOR_DW = 0.1111111111111111;
    for (i = 0; i < 6; i++) {
      VisionModel_DWork.EdgeDetection_VO_DW_l[i] = VisionModel_ConstP.pooled15[i]
        * 160 + VisionModel_ConstP.pooled16[i];
      if (VisionModel_ConstP.pooled16[i] > 0) {
        VisionModel_DWork.EdgeDetection_VOU_DW_l[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOD_DW_p[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      } else {
        VisionModel_DWork.EdgeDetection_VOU_DW_l[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection_VOD_DW_p[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
      }

      if (VisionModel_ConstP.pooled15[i] > 0) {
        VisionModel_DWork.EdgeDetection_VOL_DW_k[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOR_DW_f[i] =
          VisionModel_ConstP.pooled16[i];
      } else {
        VisionModel_DWork.EdgeDetection_VOL_DW_k[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOR_DW_f[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection_VOUL_DW_k[i] = 0;
        VisionModel_DWork.EdgeDetection_VOLR_DW_b[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLL_DW_j[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUR_DW_b[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] < 0)) {
        VisionModel_DWork.EdgeDetection_VOLL_DW_j[i] = 0;
        VisionModel_DWork.EdgeDetection_VOUR_DW_b[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUL_DW_k[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLR_DW_b[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection_VOUR_DW_b[i] = 0;
        VisionModel_DWork.EdgeDetection_VOLL_DW_j[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUL_DW_k[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection_VOLR_DW_b[i] =
          VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] >= 0)) {
        VisionModel_DWork.EdgeDetection_VOLR_DW_b[i] = 0;
        VisionModel_DWork.EdgeDetection_VOUL_DW_k[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLL_DW_j[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection_VOUR_DW_b[i] =
          VisionModel_ConstP.pooled16[i];
      }

      VisionModel_DWork.EdgeDetection_HO_DW_p[i] = VisionModel_ConstP.pooled17[i]
        * 160 + VisionModel_ConstP.pooled18[i];
      if (VisionModel_ConstP.pooled18[i] > 0) {
        VisionModel_DWork.EdgeDetection_HOU_DW_k[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOD_DW_i[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      } else {
        VisionModel_DWork.EdgeDetection_HOU_DW_k[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection_HOD_DW_i[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
      }

      if (VisionModel_ConstP.pooled17[i] > 0) {
        VisionModel_DWork.EdgeDetection_HOL_DW_g[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOR_DW_b[i] =
          VisionModel_ConstP.pooled18[i];
      } else {
        VisionModel_DWork.EdgeDetection_HOL_DW_g[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOR_DW_b[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection_HOUL_DW_k[i] = 0;
        VisionModel_DWork.EdgeDetection_HOLR_DW_a[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLL_DW_f[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUR_DW_a[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] < 0)) {
        VisionModel_DWork.EdgeDetection_HOLL_DW_f[i] = 0;
        VisionModel_DWork.EdgeDetection_HOUR_DW_a[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUL_DW_k[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLR_DW_a[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection_HOUR_DW_a[i] = 0;
        VisionModel_DWork.EdgeDetection_HOLL_DW_f[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUL_DW_k[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection_HOLR_DW_a[i] =
          VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] >= 0)) {
        VisionModel_DWork.EdgeDetection_HOLR_DW_a[i] = 0;
        VisionModel_DWork.EdgeDetection_HOUL_DW_k[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLL_DW_f[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection_HOUR_DW_a[i] =
          VisionModel_ConstP.pooled18[i];
      }

      VisionModel_DWork.EdgeDetection1_VO_DW[i] = VisionModel_ConstP.pooled15[i]
        * 160 + VisionModel_ConstP.pooled16[i];
      if (VisionModel_ConstP.pooled16[i] > 0) {
        VisionModel_DWork.EdgeDetection1_VOU_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOD_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      } else {
        VisionModel_DWork.EdgeDetection1_VOU_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection1_VOD_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
      }

      if (VisionModel_ConstP.pooled15[i] > 0) {
        VisionModel_DWork.EdgeDetection1_VOL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      } else {
        VisionModel_DWork.EdgeDetection1_VOL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection1_VOUL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_VOLR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOLL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOUR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] < 0)) {
        VisionModel_DWork.EdgeDetection1_VOLL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_VOUR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOUL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOLR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection1_VOUR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_VOLL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOUL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection1_VOLR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] >= 0)) {
        VisionModel_DWork.EdgeDetection1_VOLR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_VOUL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection1_VOLL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 160;
        VisionModel_DWork.EdgeDetection1_VOUR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      }

      VisionModel_DWork.EdgeDetection1_HO_DW[i] = VisionModel_ConstP.pooled17[i]
        * 160 + VisionModel_ConstP.pooled18[i];
      if (VisionModel_ConstP.pooled18[i] > 0) {
        VisionModel_DWork.EdgeDetection1_HOU_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOD_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      } else {
        VisionModel_DWork.EdgeDetection1_HOU_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection1_HOD_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
      }

      if (VisionModel_ConstP.pooled17[i] > 0) {
        VisionModel_DWork.EdgeDetection1_HOL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      } else {
        VisionModel_DWork.EdgeDetection1_HOL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection1_HOUL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_HOLR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOLL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOUR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] < 0)) {
        VisionModel_DWork.EdgeDetection1_HOLL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_HOUR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOUL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOLR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection1_HOUR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_HOLL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOUL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection1_HOLR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] >= 0)) {
        VisionModel_DWork.EdgeDetection1_HOLR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection1_HOUL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection1_HOLL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 160;
        VisionModel_DWork.EdgeDetection1_HOUR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      }

      VisionModel_DWork.EdgeDetection_VO_DW[i] = VisionModel_ConstP.pooled15[i] *
        3 + VisionModel_ConstP.pooled16[i];
      if (VisionModel_ConstP.pooled16[i] > 0) {
        VisionModel_DWork.EdgeDetection_VOU_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOD_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
      } else {
        VisionModel_DWork.EdgeDetection_VOU_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
        VisionModel_DWork.EdgeDetection_VOD_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
      }

      if (VisionModel_ConstP.pooled15[i] > 0) {
        VisionModel_DWork.EdgeDetection_VOL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      } else {
        VisionModel_DWork.EdgeDetection_VOL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection_VOUL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_VOLR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] < 0)) {
        VisionModel_DWork.EdgeDetection_VOLL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_VOUR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUL_DW[i] =
          VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLR_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
      }

      if ((VisionModel_ConstP.pooled16[i] < 0) && (VisionModel_ConstP.pooled15[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection_VOUR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_VOLL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOUL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
        VisionModel_DWork.EdgeDetection_VOLR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      }

      if ((VisionModel_ConstP.pooled16[i] >= 0) &&
          (VisionModel_ConstP.pooled15[i] >= 0)) {
        VisionModel_DWork.EdgeDetection_VOLR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_VOUL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3 + VisionModel_ConstP.pooled16[i];
        VisionModel_DWork.EdgeDetection_VOLL_DW[i] =
          VisionModel_ConstP.pooled15[i] * 3;
        VisionModel_DWork.EdgeDetection_VOUR_DW[i] =
          VisionModel_ConstP.pooled16[i];
      }

      VisionModel_DWork.EdgeDetection_HO_DW[i] = VisionModel_ConstP.pooled17[i] *
        3 + VisionModel_ConstP.pooled18[i];
      if (VisionModel_ConstP.pooled18[i] > 0) {
        VisionModel_DWork.EdgeDetection_HOU_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOD_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
      } else {
        VisionModel_DWork.EdgeDetection_HOU_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
        VisionModel_DWork.EdgeDetection_HOD_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
      }

      if (VisionModel_ConstP.pooled17[i] > 0) {
        VisionModel_DWork.EdgeDetection_HOL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      } else {
        VisionModel_DWork.EdgeDetection_HOL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           < 0)) {
        VisionModel_DWork.EdgeDetection_HOUL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_HOLR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] < 0)) {
        VisionModel_DWork.EdgeDetection_HOLL_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_HOUR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUL_DW[i] =
          VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLR_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
      }

      if ((VisionModel_ConstP.pooled18[i] < 0) && (VisionModel_ConstP.pooled17[i]
           >= 0)) {
        VisionModel_DWork.EdgeDetection_HOUR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_HOLL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOUL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
        VisionModel_DWork.EdgeDetection_HOLR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      }

      if ((VisionModel_ConstP.pooled18[i] >= 0) &&
          (VisionModel_ConstP.pooled17[i] >= 0)) {
        VisionModel_DWork.EdgeDetection_HOLR_DW[i] = 0;
        VisionModel_DWork.EdgeDetection_HOUL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3 + VisionModel_ConstP.pooled18[i];
        VisionModel_DWork.EdgeDetection_HOLL_DW[i] =
          VisionModel_ConstP.pooled17[i] * 3;
        VisionModel_DWork.EdgeDetection_HOUR_DW[i] =
          VisionModel_ConstP.pooled18[i];
      }
    }

    /* end of Start for SubSystem: '<Root>/path_detector' */
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
