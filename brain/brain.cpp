/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.222
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Sat Feb 20 16:27:51 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Sat Feb 20 16:27:51 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/Chart' */
#define brain_IN_Autonomous            (1)
#define brain_IN_Buoy                  (1)
#define brain_IN_ChooseState           (2)
#define brain_IN_ControlledRC          (2)
#define brain_IN_Done                  (1)
#define brain_IN_FindBuoy              (3)
#define brain_IN_Finish                (4)
#define brain_IN_FollowOnePath         (5)
#define brain_IN_GetDirections         (2)
#define brain_IN_Initialize            (1)
#define brain_IN_MoveOverPath          (3)
#define brain_IN_NotRunning            (1)
#define brain_IN_OnePath               (2)
#define brain_IN_Running               (2)
#define brain_IN_Start                 (6)
#define brain_IN_ValidationGate        (7)

/* Block signals (auto storage) */
BlockIO_brain brain_B;

/* Block states (auto storage) */
D_Work_brain brain_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_brain brain_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_brain brain_Y;

/* Real-time model */
RT_MODEL_brain brain_M_;
RT_MODEL_brain *brain_M = &brain_M_;

/* Forward declaration for local functions */
static void brain_refp1_cos(real_T eml_x[19200]);
static void brain_max_o(const real_T eml_varargin_1[80], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max(const real_T eml_varargin_1[120], real_T *eml_maxval,
                      real_T *eml_indx);
static void brain_c10_brain(void);

/* Forward declaration for local functions */
static void brain_max_f(const real_T eml_varargin_1[51660], real_T eml_maxval
  [180], real_T eml_indx[180]);
static void brain_max_fn(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);

/* Forward declaration for local functions */
static void brain_refp1_cos_g(real_T eml_x[19200]);
static void brain_max_go(const real_T eml_varargin_1[160], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max_g(const real_T eml_varargin_1[120], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c5_brain(void);

/* Forward declaration for local functions */
static void brain_enter_internal_OnePath(void);
static void brain_max_h(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT);
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong);
static void brain_max_k(const real_T eml_varargin_1[71820], real_T eml_maxval
  [180], real_T eml_indx[180]);
static real_T brain_CountClose(real_T sf_Close1, real_T sf_countIN);
static void brain_OnePath(void);
static void bra_exit_internal_FollowOnePath(void);
static void brain_exit_internal_Autonomous(void);
static void brain_Autonomous(void);
boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  boolean_T y;
  y = sMultiWordCmp(u1, u2, n) < 0 ? true : false;
  return y;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T u2i;
  uint32_T su1;
  int32_T i;
  int32_T cmp;
  su1 = u1[n - 1] & 2147483648U;
  if (((u2[n - 1] & 2147483648U) ^ su1) != 0U) {
    cmp = su1 != 0U ? -1 : 1;
  } else {
    cmp = 0;
    i = n;
    while ((cmp == 0) && (i > 0)) {
      i = i - 1;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        cmp = su1 > u2i ? 1 : -1;
      }
    }
  }

  y = cmp;
  return y;
}

void MultiWordSignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[])
{
  int32_T n1m1;
  int32_T i;
  uint32_T mask;
  uint32_T ys;
  int32_T loop_ub;
  n1m1 = n1 - 1;
  loop_ub = n1m1 - 1;
  for (i = 0; i <= loop_ub; i = i + 1) {
    y[i] = u1[i];
  }

  mask = 1U << ((32U - n2) - 1U);
  ys = (u1[n1m1] & mask) != 0U ? MAX_uint32_T : 0U;
  mask = (mask << 1U) - 1U;
  y[n1m1] = (u1[n1m1] & mask) | (~mask & ys);
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T loop_ub;
  y[0] = u;
  loop_ub = n - 1;
  for (i = 1; i <= loop_ub; i = i + 1) {
    y[i] = 0U;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  uint32_T yi;
  int32_T i;
  int32_T loop_ub;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  loop_ub = n - 1;
  for (i = 1; i <= loop_ub; i = i + 1) {
    y[i] = yi;
  }
}

/* Output and update for action system:
 *   '<S60>/FoundTrack'
 *   '<S29>/FoundBuoy'
 */
void brain_FoundTrack(real_T *rtd_Image_d)
{
  /* DataStoreWrite: '<S61>/Data Store Write' incorporates:
   *  Constant: '<S61>/Constant'
   */
  (*rtd_Image_d) = 1.0;
}

/* Output and update for action system:
 *   '<S60>/NoTrack'
 *   '<S29>/NoBuoy'
 */
void brain_NoTrack(real_T *rtd_Image_d)
{
  /* DataStoreWrite: '<S64>/Data Store Write' incorporates:
   *  Constant: '<S64>/Constant'
   */
  (*rtd_Image_d) = 0.0;
}

/* Disable for action system:
 *   '<S14>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S10>/BigError S1'
 *   '<S16>/BigError S1'
 */
void brain_BigErrorS1_Disable(rtB_BigErrorS1_brain *localB)
{
  /* Disable for Outport: '<S66>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S14>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S10>/BigError S1'
 *   '<S16>/BigError S1'
 */
void brain_BigErrorS1(real_T rtu_In1, rtB_BigErrorS1_brain *localB)
{
  /* Sum: '<S66>/Add' incorporates:
   *  Constant: '<S66>/Constant'
   */
  localB->Add = rtu_In1 - 360.0;

  /* Constant: '<S66>/Constant1' */
  localB->Constant1 = 1.0;
}

/* Disable for action system:
 *   '<S14>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S10>/BigNegativeError S2'
 *   '<S16>/BigNegativeError S2'
 */
void brai_BigNegativeErrorS2_Disable(rtB_BigNegativeErrorS2_brain *localB)
{
  /* Disable for Outport: '<S67>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S14>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S10>/BigNegativeError S2'
 *   '<S16>/BigNegativeError S2'
 */
void brain_BigNegativeErrorS2(real_T rtu_In1, rtB_BigNegativeErrorS2_brain
  *localB)
{
  /* Sum: '<S67>/Add' incorporates:
   *  Constant: '<S67>/Constant'
   */
  localB->Add = rtu_In1 + 360.0;

  /* Constant: '<S67>/Constant1' */
  localB->Constant1 = 2.0;
}

/* Function for Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
static void brain_max_o(const real_T eml_varargin_1[80], real_T *eml_maxval,
  real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 81)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 81; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
static void brain_max(const real_T eml_varargin_1[120], real_T *eml_maxval,
                      real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 121)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 121; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
static void brain_c10_brain(void)
{
  int8_T eml_BWleft[9600];
  int8_T eml_BWright[9600];
  real_T eml_valueH;
  real_T eml_indexH;
  int32_T eml_x;
  real_T eml_hoistedExpr[19200];
  real_T eml_hoistedExpr_0[120];
  real_T eml_hoistedExpr_1[80];
  real_T eml_hoistedExpr_2[120];
  real_T eml_hoistedExpr_3[80];
  int32_T eml_x_0;
  int32_T tmp;

  /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S43>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S43>:1:8' */
  /* '<S43>:1:10' */
  /* '<S43>:1:11' */
  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    eml_BWleft[eml_x_0] = 0;
    eml_BWright[eml_x_0] = 0;
  }

  /* '<S43>:1:14' */
  /* '<S43>:1:16' */
  for (eml_x_0 = 0; eml_x_0 < 160; eml_x_0++) {
    for (tmp = 0; tmp < 120; tmp++) {
      eml_hoistedExpr[tmp + 120 * eml_x_0] = brain_B.SFunction_o26[120 * eml_x_0
        + tmp] * 6.2831853071795862E+00 - 3.1415926535897931E-01;
    }
  }

  brain_refp1_cos(eml_hoistedExpr);
  for (eml_x_0 = 0; eml_x_0 < 19200; eml_x_0++) {
    eml_hoistedExpr[eml_x_0] = (eml_hoistedExpr[eml_x_0] + 1.0) / 2.0;
  }

  /*  Left half */
  for (eml_x = 0; eml_x < 80; eml_x++) {
    /* '<S43>:1:19' */
    /* '<S43>:1:20' */
    memcpy((void *)&eml_hoistedExpr_0[0], (void *)&eml_hoistedExpr[120 * eml_x],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_0, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o26[(((int32_T)eml_indexH - 1)
          + 120 * eml_x) + 19200] > 0.3)) {
      /* '<S43>:1:21' */
      /* '<S43>:1:22' */
      eml_BWleft[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S43>:1:26' */
    /* '<S43>:1:27' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_1[eml_x_0] = eml_hoistedExpr[120 * eml_x_0 + eml_x];
    }

    brain_max_o(eml_hoistedExpr_1, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o26[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S43>:1:28' */
      /* '<S43>:1:29' */
      eml_BWleft[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  /*  Right half */
  for (eml_x = 81; eml_x < 161; eml_x++) {
    /* '<S43>:1:34' */
    /* '<S43>:1:35' */
    eml_x_0 = eml_x - 1;
    memcpy((void *)&eml_hoistedExpr_2[0], (void *)&eml_hoistedExpr[120 * eml_x_0],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_2, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o26[((eml_x - 1) * 120 +
          ((int32_T)eml_indexH - 1)) + 19200] > 0.3)) {
      /* '<S43>:1:36' */
      /* '<S43>:1:37' */
      eml_BWright[((int32_T)eml_indexH - 1) + 120 * (eml_x - 81)] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S43>:1:41' */
    /* '<S43>:1:42' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_3[eml_x_0] = eml_hoistedExpr[(80 + eml_x_0) * 120 + eml_x];
    }

    brain_max_o(eml_hoistedExpr_3, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o26[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S43>:1:43' */
      /* '<S43>:1:44' */
      eml_BWright[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    brain_B.BWleft[eml_x_0] = (real_T)eml_BWleft[eml_x_0];
    brain_B.BWright[eml_x_0] = (real_T)eml_BWright[eml_x_0];
  }
}

/* Output and update for atomic system: '<S42>/Get Brightest Pixel Per Column and Row' */
void GetBrightestPixelPerColumnandRo(void)
{
  /* Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
  brain_c10_brain();
}

/* Function for Embedded MATLAB: '<S45>/IsLinePresent' */
static void brain_max_f(const real_T eml_varargin_1[51660], real_T eml_maxval
  [180], real_T eml_indx[180])
{
  int16_T eml_b_indx[180];
  int32_T eml_ix;
  int32_T eml_iy;
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_i;
  int32_T eml_b_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  for (eml_ix = 0; eml_ix < 180; eml_ix++) {
    eml_b_indx[eml_ix] = 1;
  }

  eml_ix = 0;
  eml_iy = 0;
  for (eml_i = 0; eml_i < 180; eml_i++) {
    eml_ix++;
    eml_mtmp = eml_varargin_1[eml_ix - 1];
    eml_itmp = 1;
    eml_b_ix = eml_ix;
    eml_guard = false;
    if (rtIsNaN(eml_mtmp)) {
      eml_searchingForNonNaN = true;
      eml_k = 2;
      eml_exitg = 0;
      while (((uint32_T)eml_exitg == 0U) && (eml_k < 288)) {
        eml_b_ix++;
        if (!rtIsNaN(eml_varargin_1[eml_b_ix - 1])) {
          eml_mtmp = eml_varargin_1[eml_b_ix - 1];
          eml_itmp = eml_k;
          eml_searchingForNonNaN = false;
          eml_exitg = 1;
        } else {
          eml_k++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = true;
      }
    } else {
      eml_guard = true;
    }

    if (eml_guard) {
      for (eml_k = eml_itmp + 1; eml_k < 288; eml_k++) {
        eml_b_ix++;
        if (eml_varargin_1[eml_b_ix - 1] > eml_mtmp) {
          eml_mtmp = eml_varargin_1[eml_b_ix - 1];
          eml_itmp = eml_k;
        }
      }
    }

    eml_iy++;
    eml_maxval[eml_iy - 1] = eml_mtmp;
    eml_b_indx[eml_iy - 1] = (int16_T)eml_itmp;
    eml_ix += 286;
  }

  for (eml_ix = 0; eml_ix < 180; eml_ix++) {
    eml_indx[eml_ix] = (real_T)eml_b_indx[eml_ix];
  }
}

/* Function for Embedded MATLAB: '<S45>/IsLinePresent' */
static void brain_max_fn(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 181)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 181; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S45>/IsLinePresent' */
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  static real_T eml_HoughTable[51660];
  int32_T eml_index;
  int32_T eml_count;
  real_T eml_maxValues[180];
  real_T eml_RhoIndices[180];
  real_T eml_b;
  real_T eml_c;
  real_T eml_ThetaIndex_idx;
  real_T eml_RhoIndex_idx;
  real_T eml_ThetaIndex_idx_0;
  real_T eml_RhoIndex_idx_0;
  memcpy((void *)&eml_HoughTable[0], (void *)&rtu_HoughTable[0], 51660U * sizeof
         (real_T));

  /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent': '<S47>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S47>:1:5' */
  /* '<S47>:1:7' */
  /* '<S47>:1:9' */
  /* '<S47>:1:10' */
  /* '<S47>:1:11' */
  /* '<S47>:1:12' */
  /* '<S47>:1:13' */
  localB->Rho[0] = -999.0;
  localB->Theta[0] = -999.0;
  localB->maxVotes[0] = -999.0;
  localB->Rho[1] = -999.0;
  localB->Theta[1] = -999.0;
  localB->maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S47>:1:15' */
  /* '<S47>:1:17' */
  brain_max_f(&rtu_HoughTable[0], eml_maxValues, eml_RhoIndices);

  /* '<S47>:1:18' */
  brain_max_fn(eml_maxValues, &eml_b, &eml_c);

  /* '<S47>:1:18' */
  localB->maxVotes[0] = eml_b;

  /* '<S47>:1:18' */
  eml_ThetaIndex_idx = eml_c;

  /* '<S47>:1:19' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_c - 1];
  if (localB->maxVotes[0] >= 15.0) {
    /* '<S47>:1:21' */
    /* '<S47>:1:22' */
    eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 287 * ((int32_T)eml_c - 1)]
      = 0.0;

    /* '<S47>:1:24' */
    eml_index = 2;

    /* '<S47>:1:25' */
    eml_count = 0;
    while ((eml_index <= 2) && (eml_count < 12)) {
      /* '<S47>:1:26' */
      /* '<S47>:1:27' */
      eml_count++;

      /* '<S47>:1:28' */
      brain_max_f(eml_HoughTable, eml_maxValues, eml_RhoIndices);

      /* '<S47>:1:29' */
      brain_max_fn(eml_maxValues, &eml_b, &eml_c);

      /* '<S47>:1:29' */
      localB->maxVotes[1] = eml_b;

      /* '<S47>:1:29' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S47>:1:30' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S47>:1:32' */
      eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 287 * ((int32_T)eml_c -
        1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S47>:1:34' */
        /* '<S47>:1:35' */
        eml_index = 3;
      }
    }

    /* '<S47>:1:40' */
    if (localB->maxVotes[0] > 15.0) {
      /* '<S47>:1:41' */
      /* '<S47>:1:42' */
      localB->Theta[0] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx - 1];

      /* '<S47>:1:43' */
      localB->Rho[0] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx - 1];
      if ((localB->Theta[0] > 0.0) && (localB->Rho[0] < 0.0)) {
        /* '<S47>:1:44' */
        /* '<S47>:1:45' */
        localB->Rho[0] = localB->Rho[0] * -1.0;
      }
    }

    /* '<S47>:1:40' */
    if (localB->maxVotes[1] > 15.0) {
      /* '<S47>:1:41' */
      /* '<S47>:1:42' */
      localB->Theta[1] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx_0 - 1];

      /* '<S47>:1:43' */
      localB->Rho[1] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx_0 - 1];
      if ((localB->Theta[1] > 0.0) && (localB->Rho[1] < 0.0)) {
        /* '<S47>:1:44' */
        /* '<S47>:1:45' */
        localB->Rho[1] = localB->Rho[1] * -1.0;
      }
    }
  }
}

/* Output and update for atomic system:
 *   '<S45>/IsLinePresent'
 *   '<S46>/IsLinePresent'
 */
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  /* Embedded MATLAB: '<S45>/IsLinePresent' */
  brain_c11_brain(rtu_HoughTable, rtu_ThetaValues, rtu_RhoValues, localB);
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos_g(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_max_go(const real_T eml_varargin_1[160], real_T *eml_maxval,
  real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 161)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 161; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_max_g(const real_T eml_varargin_1[120], real_T *eml_maxval,
  real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 121)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 121; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_c5_brain(void)
{
  int8_T eml_BooleanImage[19200];
  real_T eml_valueH;
  real_T eml_indexH;
  int32_T eml_x;
  real_T eml_hoistedExpr[19200];
  real_T eml_hoistedExpr_0[120];
  real_T eml_hoistedExpr_1[160];
  int32_T tmp;

  /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S56>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S56>:1:7' */
  memset(&eml_BooleanImage[0], (uint32_T)0, 19200U * sizeof(int8_T));

  /* '<S56>:1:10' */
  /* '<S56>:1:12' */
  for (tmp = 0; tmp < 160; tmp++) {
    for (eml_x = 0; eml_x < 120; eml_x++) {
      eml_hoistedExpr[eml_x + 120 * tmp] = brain_B.SFunction_o30[120 * tmp +
        eml_x] * 6.2831853071795862E+00 - 3.1415926535897931E-01;
    }
  }

  brain_refp1_cos_g(eml_hoistedExpr);
  for (tmp = 0; tmp < 19200; tmp++) {
    eml_hoistedExpr[tmp] = (eml_hoistedExpr[tmp] + 1.0) / 2.0;
  }

  for (eml_x = 0; eml_x < 160; eml_x++) {
    /* '<S56>:1:14' */
    /* '<S56>:1:15' */
    memcpy((void *)&eml_hoistedExpr_0[0], (void *)&eml_hoistedExpr[120 * eml_x],
           120U * sizeof(real_T));
    brain_max_g(eml_hoistedExpr_0, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o30[(((int32_T)eml_indexH - 1)
          + 120 * eml_x) + 19200] > 0.3)) {
      /* '<S56>:1:16' */
      /* '<S56>:1:17' */
      eml_BooleanImage[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S56>:1:21' */
    /* '<S56>:1:22' */
    for (tmp = 0; tmp < 160; tmp++) {
      eml_hoistedExpr_1[tmp] = eml_hoistedExpr[120 * tmp + eml_x];
    }

    brain_max_go(eml_hoistedExpr_1, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o30[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S56>:1:23' */
      /* '<S56>:1:24' */
      eml_BooleanImage[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (tmp = 0; tmp < 19200; tmp++) {
    brain_B.BooleanImage[tmp] = (real_T)eml_BooleanImage[tmp];
  }
}

/* Output and update for atomic system: '<S55>/Get Brightest Pixel Per Column and Row' */
void GetBrightestPixelPerColumnand_e(void)
{
  /* Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
  brain_c5_brain();
}

/* Initial conditions for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOne_Init(RT_MODEL_brain *brain_M,
  rtDW_RunningAutonomousFollowOne *localDW)
{
  localDW->RunningAutonomousFollowOnePat_j = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOnePathO(real32_T rtu_DesiredDepth1, real32_T
  rtu_CurrentDepth1, RT_MODEL_brain *brain_M, rtB_RunningAutonomousFollowOneP
  *localB, rtDW_RunningAutonomousFollowOne *localDW)
{
  /* local block i/o variables */
  real_T rtb_TSamp_b;
  real_T rtb_Sum_e;

  {
    real_T rtb_Add;
    real_T rtb_DepthProportionalGain_p;
    int8_T tmp;
    localDW->RunningAutonomousFollowOnePat_h = brain_M->Timing.clockTick0 -
      localDW->RunningAutonomousFollowOnePat_j;
    localDW->RunningAutonomousFollowOnePat_j = brain_M->Timing.clockTick0;

    /* Sum: '<S9>/Add' */
    rtb_Add = (real_T)rtu_DesiredDepth1 - (real_T)rtu_CurrentDepth1;

    /* Gain: '<S49>/Depth Proportional Gain' */
    rtb_DepthProportionalGain_p = brain_P.Depth_Kp * rtb_Add;

    /* Gain: '<S49>/Depth Derivative Gain' */
    rtb_Sum_e = brain_P.Depth_Kd * rtb_Add;

    /* S-Function (sfix_tsampmath): '<S50>/TSamp' */

    /* Sample Time Math Block: '<S50>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_b = rtb_Sum_e / (((localDW->RunningAutonomousFollowOnePat_h * 0.2))*
                               (1.0));

    /* DiscreteIntegrator: '<S49>/Depth Discrete-Time Integrator' */
    rtb_Sum_e = localDW->DepthDiscreteTimeIntegrator_DST;

    /* Sum: '<S49>/Sum' incorporates:
     *  Sum: '<S50>/Diff'
     *  UnitDelay: '<S50>/UD'
     */
    rtb_Sum_e += (rtb_TSamp_b - localDW->UD_DSTATE) +
      rtb_DepthProportionalGain_p;

    /* DataTypeConversion: '<S9>/Double To Int8' */
    rtb_DepthProportionalGain_p = floor(rtb_Sum_e);
    if (rtb_DepthProportionalGain_p < 128.0) {
      if (rtb_DepthProportionalGain_p >= -128.0) {
        tmp = (int8_T)rtb_DepthProportionalGain_p;
      } else {
        tmp = MIN_int8_T;
      }
    } else {
      tmp = MAX_int8_T;
    }

    localB->DoubleToInt8 = tmp;

    /* Update for UnitDelay: '<S50>/UD' */
    localDW->UD_DSTATE = rtb_TSamp_b;

    /* Update for DiscreteIntegrator: '<S49>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S49>/Depth Integral Gain'
     */
    localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      localDW->RunningAutonomousFollowOnePat_h * (brain_P.Depth_Ki * rtb_Add) +
      localDW->DepthDiscreteTimeIntegrator_DST;
    if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
        localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }
  }
}

/* Output and update for function-call system: '<Root>/Chart' */
void RunningAutonomousFollowOnePathM(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_RunningAutonomousFollowOn_c
  *localB)
{
  {
    int32_T i;

    /* Embedded MATLAB: '<S6>/PutHSVImageTogether' */
    /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S41>:1' */
    /*  This function simply makes an HSV image a single multidimensional */
    /*  signal */
    /* '<S41>:1:7' */
    memset(&localB->HSVImage1[0], (uint32_T)0.0, 57600U * sizeof(real_T));

    /* '<S41>:1:9' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[120 * i]), (void *)(&rtu_H1[120 * i]),
             120U * sizeof(real_T));
    }

    /* '<S41>:1:10' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[19200 + 120 * i]), (void *)(&rtu_S1[120
              * i]), 120U * sizeof(real_T));
    }

    /* '<S41>:1:11' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[38400 + 120 * i]), (void *)(&rtu_V1[120
              * i]), 120U * sizeof(real_T));
    }
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_enter_internal_OnePath(void)
{
  /* Transition: '<S1>:331' */
  /* Entry 'GetDirections': '<S1>:332' */
  brain_DWork.is_OnePath = (uint8_T)brain_IN_GetDirections;
  brain_DWork.countTo = 0.0;
  brain_DWork.countAlong = 0.0;
  brain_DWork.outliersTo = 0.0;
  brain_DWork.outliersAlong = 0.0;
  brain_B.Left = 0;
  brain_B.Right = 0;
}

/* Function for Embedded MATLAB: '<S8>/GetHeadingToPath' */
static void brain_max_h(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx)
{
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  *eml_maxval = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = false;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = true;
    eml_k = 2;
    eml_exitg = 0;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 5)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = false;
        eml_exitg = 1;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = true;
    }
  } else {
    eml_guard = true;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 5; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > *eml_maxval) {
        *eml_maxval = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_indx = (real_T)eml_itmp;
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT)
{
  /* Embedded MATLAB Function 'GetAvgDesHeading': '<S1>:342' */
  /*  This function calculates the average desired heading determined by the */
  /*  path software */
  /* '<S1>:342:7' */
  sf_AvgDesHeading[0] = 0.0;
  sf_AvgDesHeading[1] = 0.0;

  /* '<S1>:342:8' */
  *sf_OutliersOUT = sf_OutliersIN;
  if ((sf_CountIn == 0.0) && (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S1>:342:10' */
    /* '<S1>:342:11' */
    sf_AvgDesHeading[0] = sf_DesiredHeading1[0];
    sf_AvgDesHeading[1] = sf_DesiredHeading1[1];

    /* '<S1>:342:12' */
    *sf_CountOut = 1.0;
  } else if ((fabs(sf_DesiredHeading1[0] - sf_AvgDHeading[0]) < 5.0) &&
             (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S1>:342:13' */
    /* '<S1>:342:14' */
    *sf_CountOut = sf_CountIn + 1.0;

    /* '<S1>:342:15' */
    sf_AvgDesHeading[0] = (sf_CountIn * sf_AvgDHeading[0] + sf_DesiredHeading1[0])
      / *sf_CountOut;
  } else {
    /* '<S1>:342:17' */
    *sf_OutliersOUT = sf_OutliersIN + 1.0;

    /* '<S1>:342:18' */
    sf_AvgDesHeading[0] = sf_AvgDHeading[0];

    /* '<S1>:342:19' */
    *sf_CountOut = sf_CountIn;
  }

  if (sf_AvgDHeading[1] != -999.0) {
    /* '<S1>:342:24' */
    if ((fabs(sf_DesiredHeading1[1] - sf_AvgDHeading[1]) < 5.0) &&
        (sf_DesiredHeading1[1] != -999.0)) {
      /* '<S1>:342:25' */
      /* '<S1>:342:26' */
      sf_AvgDesHeading[1] = (sf_CountIn * sf_AvgDHeading[1] +
        sf_DesiredHeading1[1]) / *sf_CountOut;
    } else {
      /* '<S1>:342:28' */
      sf_AvgDesHeading[1] = sf_AvgDHeading[1];
    }

    if (*sf_OutliersOUT > 5.0) {
      /* '<S1>:342:31' */
      /* '<S1>:342:32' */
      sf_AvgDesHeading[1] = 0.0;
    }
  }

  if (*sf_OutliersOUT > 5.0) {
    /* '<S1>:342:38' */
    /* '<S1>:342:39' */
    sf_AvgDesHeading[0] = 0.0;
    sf_AvgDesHeading[1] = 0.0;

    /* '<S1>:342:40' */
    *sf_CountOut = 0.0;

    /* '<S1>:342:41' */
    *sf_OutliersOUT = 0.0;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong)
{
  real_T sf_DeltaTheta;
  int32_T sf_RightPathIndex;

  /* Embedded MATLAB Function 'ChoosePath': '<S1>:337' */
  /*  This function will determine which of the two found paths are pointing */
  /*  right and which is pointing left. This function will then return the  */
  /*  headings associated with the path to the right (There should only be one */
  /*  path and therefore that one will be returned) */
  if (sf_AvgDesHeadingAlongPath[1] != -999.0) {
    /* '<S1>:337:15' */
    /* '<S1>:337:16' */
    sf_DeltaTheta = sf_AvgDesHeadingAlongPath[1] - sf_AvgDesHeadingAlongPath[0];
    if (sf_DeltaTheta > 180.0) {
      /* '<S1>:337:18' */
      /* '<S1>:337:19' */
      sf_DeltaTheta -= 360.0;
    } else {
      if (sf_DeltaTheta < -180.0) {
        /* '<S1>:337:20' */
        /* '<S1>:337:21' */
        sf_DeltaTheta += 360.0;
      }
    }

    if (sf_DeltaTheta > 0.0) {
      /* '<S1>:337:24' */
      /* '<S1>:337:25' */
      sf_RightPathIndex = 2;
    } else {
      /* '<S1>:337:29' */
      sf_RightPathIndex = 1;
    }

    /*  Choose the RightPath */
    /* '<S1>:337:33' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[sf_RightPathIndex - 1];

    /* '<S1>:337:34' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[sf_RightPathIndex - 1];
  } else {
    /* '<S1>:337:38' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[0];

    /* '<S1>:337:39' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[0];
  }
}

/* Function for Embedded MATLAB: '<S57>/IsLinePresent' */
static void brain_max_k(const real_T eml_varargin_1[71820], real_T eml_maxval
  [180], real_T eml_indx[180])
{
  int16_T eml_b_indx[180];
  int32_T eml_ix;
  int32_T eml_iy;
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_i;
  int32_T eml_b_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  int32_T eml_exitg;
  for (eml_ix = 0; eml_ix < 180; eml_ix++) {
    eml_b_indx[eml_ix] = 1;
  }

  eml_ix = 0;
  eml_iy = 0;
  for (eml_i = 0; eml_i < 180; eml_i++) {
    eml_ix++;
    eml_mtmp = eml_varargin_1[eml_ix - 1];
    eml_itmp = 1;
    eml_b_ix = eml_ix;
    eml_guard = false;
    if (rtIsNaN(eml_mtmp)) {
      eml_searchingForNonNaN = true;
      eml_k = 2;
      eml_exitg = 0;
      while (((uint32_T)eml_exitg == 0U) && (eml_k < 400)) {
        eml_b_ix++;
        if (!rtIsNaN(eml_varargin_1[eml_b_ix - 1])) {
          eml_mtmp = eml_varargin_1[eml_b_ix - 1];
          eml_itmp = eml_k;
          eml_searchingForNonNaN = false;
          eml_exitg = 1;
        } else {
          eml_k++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = true;
      }
    } else {
      eml_guard = true;
    }

    if (eml_guard) {
      for (eml_k = eml_itmp + 1; eml_k < 400; eml_k++) {
        eml_b_ix++;
        if (eml_varargin_1[eml_b_ix - 1] > eml_mtmp) {
          eml_mtmp = eml_varargin_1[eml_b_ix - 1];
          eml_itmp = eml_k;
        }
      }
    }

    eml_iy++;
    eml_maxval[eml_iy - 1] = eml_mtmp;
    eml_b_indx[eml_iy - 1] = (int16_T)eml_itmp;
    eml_ix += 398;
  }

  for (eml_ix = 0; eml_ix < 180; eml_ix++) {
    eml_indx[eml_ix] = (real_T)eml_b_indx[eml_ix];
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static real_T brain_CountClose(real_T sf_Close1, real_T sf_countIN)
{
  /* Embedded MATLAB Function 'CountClose': '<S1>:360' */
  /*  This function will count the number of times the software claims */
  /*  that the AUV is close to the line formed by the path */
  if (sf_Close1 == 1.0) {
    /* '<S1>:360:5' */
    /* '<S1>:360:6' */
    return sf_countIN + 1.0;
  } else {
    /* '<S1>:360:8' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_OnePath(void)
{
  /* local block i/o variables */
  real_T rtb_Add1_g;
  real_T rtb_TSamp_k;
  real_T rtb_Theta[2];
  real_T rtb_Rho[2];
  real_T rtb_TmpHiddenBufferAtSFunctionI[4];
  real_T rtb_TmpHiddenBufferAtSFunctio_l[4];
  real_T rtb_Add4_p;
  static real_T sf_HSVImage[57600];
  real_T eml_maxValues[180];
  real_T eml_RhoIndices[180];
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  real_T eml_Votes[4];
  real_T eml_maxIndex[2];
  real_T eml_b;
  real_T eml_c;
  int8_T rtPrevAction;
  int8_T rtAction;
  int32_T i;
  static real_T tmp[71820];
  int16_T eml_ThetaIndex_idx;
  int32_T eml_exitg;

  /* During 'OnePath': '<S1>:328' */
  switch (brain_DWork.is_OnePath) {
   case brain_IN_Done:
    break;

   case brain_IN_GetDirections:
    /* During 'GetDirections': '<S1>:332' */
    if (brain_DWork.countTo >= 4.0) {
      /* Transition: '<S1>:329' */
      /* Exit 'GetDirections': '<S1>:332' */
      brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                       &brain_DWork.AvgDesiredHeadingAlongPath[0],
                       &brain_B.DesiredHeading, &brain_DWork.HeadingAlongPath);

      /* Entry 'MoveOverPath': '<S1>:356' */
      brain_DWork.is_OnePath = (uint8_T)brain_IN_MoveOverPath;
      brain_DWork.count = 0.0;
    } else {
      /* Simulink Function 'MakeHSVImage': '<S1>:380' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o38[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o39[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o40[i] = (real_T)brain_B.Resize2[i];
      }

      RunningAutonomousFollowOnePathM(brain_B.SFunction_o38,
        brain_B.SFunction_o39, brain_B.SFunction_o40,
        &brain_B.RunningAutonomousFollowOnePat_i);

      /* Simulink Function 'GetBrightestPixel_VerticalSplit': '<S1>:333' */
      memcpy((void *)&brain_B.SFunction_o26[0], (void *)
             &brain_B.RunningAutonomousFollowOnePat_i.HSVImage1[0], 57600U *
             sizeof(real_T));

      /* Embedded MATLAB: '<S42>/Get Brightest Pixel Per Column and Row' */
      GetBrightestPixelPerColumnandRo();
      for (i = 0; i < 9600; i++) {
        /* DataTypeConversion: '<S42>/Data Type Conversion' */
        brain_B.BWleft_i[i] = (brain_B.BWleft[i] != 0.0);

        /* DataTypeConversion: '<S42>/Data Type Conversion1' */
        brain_B.BWright_e[i] = (brain_B.BWright[i] != 0.0);
      }

      /* Simulink Function 'GetHeadings': '<S1>:350' */
      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o27[i] = (brain_B.BWleft_i[i] != 0);
      }

      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o28[i] = (brain_B.BWright_e[i] != 0);
      }

      brain_B.SFunction_o29 = brain_U.CurrentHeading;

      /* S-Function (sviphough): '<S45>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o27[0], &brain_B.HoughTransform_o1_i[0],
                    &brain_ConstP.pooled11[0], &brain_ConstP.pooled12, 120, 80,
                    287, 91);

      /* Embedded MATLAB: '<S45>/IsLinePresent' */
      brain_IsLinePresent(brain_B.HoughTransform_o1_i,
                          brain_B.HoughTransform_o2_e,
                          brain_B.HoughTransform_o3_n, &brain_B.sf_IsLinePresent);

      /* S-Function (sviphough): '<S46>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o28[0], &brain_B.HoughTransform_o1_d[0],
                    &brain_ConstP.pooled11[0], &brain_ConstP.pooled12, 120, 80,
                    287, 91);

      /* Embedded MATLAB: '<S46>/IsLinePresent' */
      brain_IsLinePresent(brain_B.HoughTransform_o1_d,
                          brain_B.HoughTransform_o2_m,
                          brain_B.HoughTransform_o3_k,
                          &brain_B.sf_IsLinePresent_j);

      /* SignalConversion: '<S44>/TmpHiddenBufferAt SFunction Inport1' */
      rtb_TmpHiddenBufferAtSFunctionI[0] = brain_B.sf_IsLinePresent.Theta[0];
      rtb_TmpHiddenBufferAtSFunctionI[1] = brain_B.sf_IsLinePresent.Theta[1];

      /* SignalConversion: '<S44>/TmpHiddenBufferAt SFunction Inport3' */
      rtb_TmpHiddenBufferAtSFunctionI[2] = brain_B.sf_IsLinePresent_j.Theta[0];
      rtb_TmpHiddenBufferAtSFunctio_l[0] = brain_B.sf_IsLinePresent.maxVotes[0];
      rtb_TmpHiddenBufferAtSFunctionI[3] = brain_B.sf_IsLinePresent_j.Theta[1];
      rtb_TmpHiddenBufferAtSFunctio_l[1] = brain_B.sf_IsLinePresent.maxVotes[1];
      rtb_TmpHiddenBufferAtSFunctio_l[2] = brain_B.sf_IsLinePresent_j.maxVotes[0];
      rtb_TmpHiddenBufferAtSFunctio_l[3] = brain_B.sf_IsLinePresent_j.maxVotes[1];

      /* Embedded MATLAB: '<S8>/GetHeadingToPath' */
      eml_Votes[0] = rtb_TmpHiddenBufferAtSFunctio_l[0];
      eml_Votes[1] = rtb_TmpHiddenBufferAtSFunctio_l[1];
      eml_Votes[2] = rtb_TmpHiddenBufferAtSFunctio_l[2];
      eml_Votes[3] = rtb_TmpHiddenBufferAtSFunctio_l[3];

      /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath': '<S44>:1' */
      /*  This function calculates the heading to the path from Theta and Rho */
      /* '<S44>:1:4' */
      /* '<S44>:1:6' */
      /* '<S44>:1:7' */
      /* '<S44>:1:8' */
      brain_B.ToPathHeading[0] = -999.0;
      brain_B.AlongPathHeading[0] = -999.0;
      eml_maxIndex[0] = -999.0;
      brain_B.ToPathHeading[1] = -999.0;
      brain_B.AlongPathHeading[1] = -999.0;
      eml_maxIndex[1] = -999.0;

      /* '<S44>:1:11' */
      brain_max_h(rtb_TmpHiddenBufferAtSFunctio_l, &eml_b, &eml_c);

      /* '<S44>:1:11' */
      eml_maxIndex[0] = eml_c;

      /* '<S44>:1:12' */
      eml_Votes[(int32_T)eml_maxIndex[0] - 1] = 0.0;

      /* '<S44>:1:13' */
      /* '<S44>:1:15' */
      /* '<S44>:1:16' */
      /* '<S44>:1:17' */
      brain_max_h(eml_Votes, &eml_b, &eml_c);

      /* '<S44>:1:17' */
      eml_maxIndex[1] = eml_c;

      /* '<S44>:1:18' */
      /* '<S44>:1:21' */
      if (eml_maxIndex[0] <= 2.0) {
        /* '<S44>:1:22' */
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[0] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[0] - 1] < 1.5707963267948966E+00)) {
          /* '<S44>:1:23' */
          /* '<S44>:1:24' */
          brain_B.ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29) - 90.0;

          /* '<S44>:1:25' */
          brain_B.AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29;
        }
      } else {
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[0] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[0] - 1] < 1.5707963267948966E+00)) {
          /* '<S44>:1:28' */
          /* '<S44>:1:29' */
          brain_B.ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29) + 90.0;

          /* '<S44>:1:30' */
          brain_B.AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29;
        }
      }

      /* '<S44>:1:35' */
      if (brain_B.ToPathHeading[0] != -999.0) {
        /* '<S44>:1:36' */
        if (brain_B.ToPathHeading[0] < 0.0) {
          /* '<S44>:1:37' */
          /* '<S44>:1:38' */
          brain_B.ToPathHeading[0] = brain_B.ToPathHeading[0] + 360.0;
        } else {
          if (brain_B.ToPathHeading[0] > 360.0) {
            /* '<S44>:1:39' */
            /* '<S44>:1:40' */
            brain_B.ToPathHeading[0] = brain_B.ToPathHeading[0] - 360.0;
          }
        }

        if (brain_B.AlongPathHeading[0] < 0.0) {
          /* '<S44>:1:43' */
          /* '<S44>:1:44' */
          brain_B.AlongPathHeading[0] = brain_B.AlongPathHeading[0] + 360.0;
        } else {
          if (brain_B.AlongPathHeading[0] > 360.0) {
            /* '<S44>:1:45' */
            /* '<S44>:1:46' */
            brain_B.AlongPathHeading[0] = brain_B.AlongPathHeading[0] - 360.0;
          }
        }
      }

      /* '<S44>:1:21' */
      if (eml_maxIndex[1] <= 2.0) {
        /* '<S44>:1:22' */
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[1] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[1] - 1] < 1.5707963267948966E+00)) {
          /* '<S44>:1:23' */
          /* '<S44>:1:24' */
          brain_B.ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29) - 90.0;

          /* '<S44>:1:25' */
          brain_B.AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29;
        }
      } else {
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[1] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[1] - 1] < 1.5707963267948966E+00)) {
          /* '<S44>:1:28' */
          /* '<S44>:1:29' */
          brain_B.ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29) + 90.0;

          /* '<S44>:1:30' */
          brain_B.AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o29;
        }
      }

      /* '<S44>:1:35' */
      if (brain_B.ToPathHeading[1] != -999.0) {
        /* '<S44>:1:36' */
        if (brain_B.ToPathHeading[1] < 0.0) {
          /* '<S44>:1:37' */
          /* '<S44>:1:38' */
          brain_B.ToPathHeading[1] = brain_B.ToPathHeading[1] + 360.0;
        } else {
          if (brain_B.ToPathHeading[1] > 360.0) {
            /* '<S44>:1:39' */
            /* '<S44>:1:40' */
            brain_B.ToPathHeading[1] = brain_B.ToPathHeading[1] - 360.0;
          }
        }

        if (brain_B.AlongPathHeading[1] < 0.0) {
          /* '<S44>:1:43' */
          /* '<S44>:1:44' */
          brain_B.AlongPathHeading[1] = brain_B.AlongPathHeading[1] + 360.0;
        } else {
          if (brain_B.AlongPathHeading[1] > 360.0) {
            /* '<S44>:1:45' */
            /* '<S44>:1:46' */
            brain_B.AlongPathHeading[1] = brain_B.AlongPathHeading[1] - 360.0;
          }
        }
      }

      brain_GetAvgDesHeading(&brain_B.ToPathHeading[0],
        &brain_DWork.AvgDesiredHeadingToPath[0], brain_DWork.countTo,
        brain_DWork.outliersTo, eml_maxIndex, &eml_b, &eml_c);
      brain_DWork.AvgDesiredHeadingToPath[0] = eml_maxIndex[0];
      brain_DWork.AvgDesiredHeadingToPath[1] = eml_maxIndex[1];
      brain_DWork.countTo = eml_b;
      brain_DWork.outliersTo = eml_c;
      brain_GetAvgDesHeading(&brain_B.AlongPathHeading[0],
        &brain_DWork.AvgDesiredHeadingAlongPath[0], brain_DWork.countAlong,
        brain_DWork.outliersAlong, eml_maxIndex, &eml_b, &eml_c);
      brain_DWork.AvgDesiredHeadingAlongPath[0] = eml_maxIndex[0];
      brain_DWork.AvgDesiredHeadingAlongPath[1] = eml_maxIndex[1];
      brain_DWork.countAlong = eml_b;
      brain_DWork.outliersAlong = eml_c;

      /* Simulink Function 'MaintainDepth': '<S1>:370' */
      brain_B.SFunction_o34 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o35 = (real32_T)brain_B.DesiredDepth;
      RunningAutonomousFollowOnePathO(brain_B.SFunction_o35,
        brain_B.SFunction_o34, brain_M, &brain_B.RunningAutonomousFollowOnePa_mg,
        &brain_DWork.RunningAutonomousFollowOnePa_mg);
      brain_B.Vertical = brain_B.RunningAutonomousFollowOnePa_mg.DoubleToInt8;
    }
    break;

   case brain_IN_MoveOverPath:
    /* During 'MoveOverPath': '<S1>:356' */
    if (brain_DWork.count >= 2.0) {
      /* Transition: '<S1>:330' */
      /* Exit 'MoveOverPath': '<S1>:356' */
      brain_B.DesiredHeading = brain_DWork.HeadingAlongPath;

      /* Entry 'Done': '<S1>:369' */
      brain_DWork.is_OnePath = (uint8_T)brain_IN_Done;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'MakeHSVImage': '<S1>:380' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o38[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o39[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o40[i] = (real_T)brain_B.Resize2[i];
      }

      RunningAutonomousFollowOnePathM(brain_B.SFunction_o38,
        brain_B.SFunction_o39, brain_B.SFunction_o40,
        &brain_B.RunningAutonomousFollowOnePat_i);
      memcpy((void *)&sf_HSVImage[0], (void *)
             &brain_B.RunningAutonomousFollowOnePat_i.HSVImage1[0], 57600U *
             sizeof(real_T));

      /* Simulink Function 'MaintainDepth': '<S1>:370' */
      brain_B.SFunction_o34 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o35 = (real32_T)brain_B.DesiredDepth;
      RunningAutonomousFollowOnePathO(brain_B.SFunction_o35,
        brain_B.SFunction_o34, brain_M, &brain_B.RunningAutonomousFollowOnePa_mg,
        &brain_DWork.RunningAutonomousFollowOnePa_mg);
      brain_B.Vertical = brain_B.RunningAutonomousFollowOnePa_mg.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S1>:374' */
      brain_B.SFunction_o36 = brain_B.DesiredHeading;
      brain_B.SFunction_o37 = brain_U.CurrentHeading;
      brain_DWork.RunningAutonomousFollowOnePat_a = brain_M->Timing.clockTick0 -
        brain_DWork.RunningAutonomousFollowOnePat_m;
      brain_DWork.RunningAutonomousFollowOnePat_m = brain_M->Timing.clockTick0;

      /* Sum: '<S10>/Add1' */
      rtb_Add1_g = brain_B.SFunction_o36 - brain_B.SFunction_o37;

      /* If: '<S10>/If' incorporates:
       *  ActionPort: '<S51>/Action Port'
       *  ActionPort: '<S52>/Action Port'
       *  SubSystem: '<S10>/BigError S1'
       *  SubSystem: '<S10>/BigNegativeError S2'
       */
      rtPrevAction = brain_DWork.If_ActiveSubsystem_l;
      rtAction = -1;
      if (rtb_Add1_g > 180.0) {
        rtAction = 0;
      } else {
        if (rtb_Add1_g < -180.0) {
          rtAction = 1;
        }
      }

      brain_DWork.If_ActiveSubsystem_l = rtAction;
      if (rtPrevAction != rtAction) {
        switch (rtPrevAction) {
         case 0:
          brain_BigErrorS1_Disable(&brain_B.BigErrorS1_m);
          break;

         case 1:
          brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_n);
          break;
        }
      }

      switch (rtAction) {
       case 0:
        brain_BigErrorS1(rtb_Add1_g, &brain_B.BigErrorS1_m);
        break;

       case 1:
        brain_BigNegativeErrorS2(rtb_Add1_g, &brain_B.BigNegativeErrorS2_n);
        break;
      }

      /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Sum: '<S10>/Add2'
       */
      switch ((int32_T)((1.0 + brain_B.BigErrorS1_m.Constant1) +
                        brain_B.BigNegativeErrorS2_n.Constant1)) {
       case 1:
        eml_b = rtb_Add1_g;
        break;

       case 2:
        eml_b = brain_B.BigErrorS1_m.Add;
        break;

       default:
        eml_b = brain_B.BigNegativeErrorS2_n.Add;
        break;
      }

      /* Gain: '<S53>/Heading Proportional Gain' */
      eml_c = brain_P.Heading_Kp * eml_b;

      /* Gain: '<S53>/Heading Derivative Gain' */
      rtb_Add4_p = brain_P.Heading_Kd * eml_b;

      /* S-Function (sfix_tsampmath): '<S54>/TSamp' */

      /* Sample Time Math Block: '<S54>/TSamp'
       *
       * y = u * K     where     K = 1 / ( w * Ts )
       *
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * ElapsedTime Data Type:  Floating Point real_T
       */
      rtb_TSamp_k = rtb_Add4_p / (((brain_DWork.RunningAutonomousFollowOnePat_a *
        0.2))*(1.0));

      /* DiscreteIntegrator: '<S53>/Heading Discrete-Time Integrator' */
      rtb_Add4_p = brain_DWork.HeadingDiscreteTimeIntegrator_h;

      /* Sum: '<S53>/Sum' incorporates:
       *  Sum: '<S54>/Diff'
       *  UnitDelay: '<S54>/UD'
       */
      rtb_Add4_p += (rtb_TSamp_k - brain_DWork.UD_DSTATE_f) + eml_c;

      /* Product: '<S10>/Multiply' incorporates:
       *  Constant: '<S10>/Constant'
       */
      eml_c = -rtb_Add4_p;
      if (rtIsNaN(eml_c) || rtIsInf(eml_c)) {
        eml_c = 0.0;
      } else {
        eml_c = fmod(floor(eml_c), 256.0);
      }

      /* Sum: '<S10>/Add4' incorporates:
       *  Constant: '<S10>/Heading_Forward_Velocity'
       */
      rtb_Add4_p += brain_P.Heading_Forward_Velocity;

      /* DataTypeConversion: '<S10>/DoubleToint1' incorporates:
       *  Constant: '<S10>/Heading_Forward_Velocity1'
       *  Sum: '<S10>/Add3'
       */
      eml_c = (real_T)(eml_c < 0.0 ? (int8_T)(-((int8_T)(uint8_T)(-eml_c))) :
                       (int8_T)(uint8_T)eml_c) +
        brain_P.Heading_Forward_Velocity;
      eml_c = floor(eml_c);
      if (eml_c < 128.0) {
        if (eml_c >= -128.0) {
          rtPrevAction = (int8_T)eml_c;
        } else {
          rtPrevAction = MIN_int8_T;
        }
      } else {
        rtPrevAction = MAX_int8_T;
      }

      brain_B.DoubleToint1_c = rtPrevAction;

      /* DataTypeConversion: '<S10>/DoubleToint8' */
      eml_c = floor(rtb_Add4_p);
      if (eml_c < 128.0) {
        if (eml_c >= -128.0) {
          rtPrevAction = (int8_T)eml_c;
        } else {
          rtPrevAction = MIN_int8_T;
        }
      } else {
        rtPrevAction = MAX_int8_T;
      }

      brain_B.DoubleToint8_l = rtPrevAction;

      /* Update for UnitDelay: '<S54>/UD' */
      brain_DWork.UD_DSTATE_f = rtb_TSamp_k;

      /* Update for DiscreteIntegrator: '<S53>/Heading Discrete-Time Integrator' incorporates:
       *  Gain: '<S53>/Heading Integral Gain'
       */
      brain_DWork.HeadingDiscreteTimeIntegrator_h = 0.2 * (real_T)
        brain_DWork.RunningAutonomousFollowOnePat_a * (brain_P.Heading_Ki *
        eml_b) + brain_DWork.HeadingDiscreteTimeIntegrator_h;
      if (brain_DWork.HeadingDiscreteTimeIntegrator_h >= 15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_h = 15.0;
      } else {
        if (brain_DWork.HeadingDiscreteTimeIntegrator_h <= -15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_h = -15.0;
        }
      }

      brain_B.Left = brain_B.DoubleToint8_l;
      brain_B.Right = brain_B.DoubleToint1_c;

      /* Simulink Function 'GetBrightestPixel': '<S1>:357' */
      memcpy((void *)&brain_B.SFunction_o30[0], (void *)&sf_HSVImage[0], 57600U *
             sizeof(real_T));

      /* Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
      GetBrightestPixelPerColumnand_e();

      /* DataTypeConversion: '<S55>/Data Type Conversion' */
      for (i = 0; i < 19200; i++) {
        brain_B.DataTypeConversion_h[i] = (brain_B.BooleanImage[i] != 0.0);
      }

      /* Simulink Function 'IsAUVonPathLine': '<S1>:364' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o31[i] = (brain_B.DataTypeConversion_h[i] != 0);
      }

      brain_B.SFunction_o32 = brain_DWork.HeadingAlongPath;
      brain_B.SFunction_o33 = brain_U.CurrentHeading;

      /* S-Function (sviphough): '<S57>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o31[0], &brain_B.HoughTransform_o1[0],
                    &brain_ConstP.pooled11[0],
                    &brain_ConstP.HoughTransform_FIRSTRHO_RT, 120, 160, 399, 91);

      /* Embedded MATLAB: '<S57>/IsLinePresent' */
      /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff/IsLinePresent': '<S59>:1' */
      /*  This function takes a Hough/hash table as input and  determines if a line */
      /*  is present and if so what its Rho and Theta are. */
      /* '<S59>:1:6' */
      /* '<S59>:1:8' */
      /* '<S59>:1:9' */
      /* '<S59>:1:10' */
      /* '<S59>:1:11' */
      /* '<S59>:1:12' */
      rtb_Rho[0] = -999.0;
      rtb_Theta[0] = -999.0;
      eml_maxIndex[0] = -999.0;
      rtb_Rho[1] = -999.0;
      rtb_Theta[1] = -999.0;
      eml_maxIndex[1] = -999.0;

      /* '<S59>:1:15' */
      memcpy((void *)&tmp[0], (void *)&brain_B.HoughTransform_o1[0], 71820U *
             sizeof(real_T));
      brain_max_k(tmp, eml_maxValues, eml_RhoIndices);

      /* '<S59>:1:16' */
      eml_b = eml_maxValues[0];
      i = 1;
      eml_ix = 1;
      eml_guard = false;
      if (rtIsNaN(eml_maxValues[0])) {
        eml_searchingForNonNaN = true;
        eml_k = 2;
        eml_exitg = 0;
        while (((uint32_T)eml_exitg == 0U) && (eml_k < 181)) {
          eml_ix++;
          if (!rtIsNaN(eml_maxValues[eml_ix - 1])) {
            eml_b = eml_maxValues[eml_ix - 1];
            i = eml_k;
            eml_searchingForNonNaN = false;
            eml_exitg = 1;
          } else {
            eml_k++;
          }
        }

        if (!eml_searchingForNonNaN) {
          eml_guard = true;
        }
      } else {
        eml_guard = true;
      }

      if (eml_guard) {
        for (eml_k = i + 1; eml_k < 181; eml_k++) {
          eml_ix++;
          if (eml_maxValues[eml_ix - 1] > eml_b) {
            eml_b = eml_maxValues[eml_ix - 1];
            i = eml_k;
          }
        }
      }

      /* '<S59>:1:16' */
      eml_maxIndex[0] = eml_b;

      /* '<S59>:1:16' */
      eml_ThetaIndex_idx = (int16_T)i;

      /* '<S59>:1:17' */
      /* '<S59>:1:19' */
      if (eml_maxIndex[0] > 15.0) {
        /* '<S59>:1:21' */
        /* '<S59>:1:32' */
        if (eml_maxIndex[0] > 15.0) {
          /* '<S59>:1:33' */
          /* '<S59>:1:34' */
          rtb_Theta[0] = brain_B.HoughTransform_o2[eml_ThetaIndex_idx - 1];

          /* '<S59>:1:35' */
          rtb_Rho[0] = brain_B.HoughTransform_o3[(int32_T)
            eml_RhoIndices[eml_ThetaIndex_idx - 1] - 1];
          if ((rtb_Theta[0] > 0.0) && (rtb_Rho[0] < 0.0)) {
            /* '<S59>:1:36' */
            /* '<S59>:1:37' */
            rtb_Rho[0] *= -1.0;
          }
        }

        /* '<S59>:1:32' */
      }

      /* Video and Image Processing Blockset Hough Lines (sviphoughlines) - '<S12>/Hough Lines' - Output */
      MWVIP_HoughLines_D(
                         rtb_Theta,
                         rtb_Rho,
                         brain_B.HoughLines,
                         2,
                         120,
                         160
                         );

      /* Embedded MATLAB: '<S12>/IsLineNearCenter' */
      /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/IsLineNearCenter': '<S58>:1' */
      /*  Given 2 points, determine if the line has a point near the center of */
      /*  the image */
      /* '<S58>:1:8' */
      /* '<S58>:1:10' */
      eml_b = -999.0;

      /* '<S58>:1:12' */
      if (rtb_Theta[0] != -999.0) {
        /* '<S58>:1:13' */
        /* '<S58>:1:14' */
        eml_c = rtb_Theta[0] * 180.0 / 3.1415926535897931E+00 +
          brain_B.SFunction_o33;
        if (eml_c > 360.0) {
          /* '<S58>:1:15' */
          /* '<S58>:1:16' */
          eml_c -= 360.0;
        } else {
          if (eml_c < 0.0) {
            /* '<S58>:1:17' */
            /* '<S58>:1:18' */
            eml_c += 360.0;
          }
        }

        if (fabs(eml_c - brain_B.SFunction_o32) < 10.0) {
          /* '<S58>:1:21' */
          /* '<S58>:1:22' */
          /* '<S58>:1:23' */
          /* '<S58>:1:24' */
          /* '<S58>:1:25' */
          /*  y=mx+b */
          /*  x=(y-b)/m */
          /* '<S58>:1:29' */
          eml_exitg = brain_B.HoughLines[3] - brain_B.HoughLines[1];
          if ((brain_B.HoughLines[3] < 0) && (brain_B.HoughLines[1] >= 0) &&
              (eml_exitg >= 0)) {
            eml_exitg = MIN_int32_T;
          } else {
            if ((brain_B.HoughLines[3] >= 0) && (brain_B.HoughLines[1] < 0) &&
                (eml_exitg < 0)) {
              eml_exitg = MAX_int32_T;
            }
          }

          if (eml_exitg == 0) {
            /* '<S58>:1:30' */
            /* '<S58>:1:31' */
            eml_exitg = 1;
          }

          /* '<S58>:1:33' */
          i = brain_B.HoughLines[2] - brain_B.HoughLines[0];
          if ((brain_B.HoughLines[2] < 0) && (brain_B.HoughLines[0] >= 0) && (i >=
               0)) {
            i = MIN_int32_T;
          } else {
            if ((brain_B.HoughLines[2] >= 0) && (brain_B.HoughLines[0] < 0) &&
                (i < 0)) {
              i = MAX_int32_T;
            }
          }

          eml_b = (real_T)i / (real_T)eml_exitg;

          /* '<S58>:1:34' */
          /* '<S58>:1:36' */
          /* '<S58>:1:38' */
          eml_b = (((real_T)brain_B.HoughLines[2] - eml_b * (real_T)
                    brain_B.HoughLines[3]) + eml_b * 80.0) - 60.0;
        }
      }

      /* '<S58>:1:12' */
      if (rtb_Theta[1] != -999.0) {
        /* '<S58>:1:13' */
        /* '<S58>:1:14' */
        eml_c = rtb_Theta[1] * 180.0 / 3.1415926535897931E+00 +
          brain_B.SFunction_o33;
        if (eml_c > 360.0) {
          /* '<S58>:1:15' */
          /* '<S58>:1:16' */
          eml_c -= 360.0;
        } else {
          if (eml_c < 0.0) {
            /* '<S58>:1:17' */
            /* '<S58>:1:18' */
            eml_c += 360.0;
          }
        }

        if (fabs(eml_c - brain_B.SFunction_o32) < 10.0) {
          /* '<S58>:1:21' */
          /* '<S58>:1:22' */
          /* '<S58>:1:23' */
          /* '<S58>:1:24' */
          /* '<S58>:1:25' */
          /*  y=mx+b */
          /*  x=(y-b)/m */
          /* '<S58>:1:29' */
          eml_exitg = brain_B.HoughLines[7] - brain_B.HoughLines[5];
          if ((brain_B.HoughLines[7] < 0) && (brain_B.HoughLines[5] >= 0) &&
              (eml_exitg >= 0)) {
            eml_exitg = MIN_int32_T;
          } else {
            if ((brain_B.HoughLines[7] >= 0) && (brain_B.HoughLines[5] < 0) &&
                (eml_exitg < 0)) {
              eml_exitg = MAX_int32_T;
            }
          }

          if (eml_exitg == 0) {
            /* '<S58>:1:30' */
            /* '<S58>:1:31' */
            eml_exitg = 1;
          }

          /* '<S58>:1:33' */
          i = brain_B.HoughLines[6] - brain_B.HoughLines[4];
          if ((brain_B.HoughLines[6] < 0) && (brain_B.HoughLines[4] >= 0) && (i >=
               0)) {
            i = MIN_int32_T;
          } else {
            if ((brain_B.HoughLines[6] >= 0) && (brain_B.HoughLines[4] < 0) &&
                (i < 0)) {
              i = MAX_int32_T;
            }
          }

          eml_b = (real_T)i / (real_T)eml_exitg;

          /* '<S58>:1:34' */
          /* '<S58>:1:36' */
          /* '<S58>:1:38' */
          eml_b = (((real_T)brain_B.HoughLines[6] - eml_b * (real_T)
                    brain_B.HoughLines[7]) + eml_b * 80.0) - 60.0;
        }
      }

      if ((eml_b < 50.0) && (eml_b > -50.0)) {
        /* '<S58>:1:43' */
        /* '<S58>:1:44' */
        brain_B.Close = 1.0;
      } else {
        /* '<S58>:1:46' */
        brain_B.Close = 0.0;
      }

      brain_DWork.count = brain_CountClose(brain_B.Close, brain_DWork.count);
    }
    break;

   default:
    brain_enter_internal_OnePath();
    break;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void bra_exit_internal_FollowOnePath(void)
{
  if (brain_DWork.is_FollowOnePath == brain_IN_OnePath) {
    switch (brain_DWork.is_OnePath) {
     case brain_IN_GetDirections:
      /* Exit 'GetDirections': '<S1>:332' */
      brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                       &brain_DWork.AvgDesiredHeadingAlongPath[0],
                       &brain_B.DesiredHeading, &brain_DWork.HeadingAlongPath);
      brain_DWork.is_OnePath = (uint8_T)0;
      break;

     case brain_IN_MoveOverPath:
      /* Exit 'MoveOverPath': '<S1>:356' */
      brain_B.DesiredHeading = brain_DWork.HeadingAlongPath;
      brain_DWork.is_OnePath = (uint8_T)0;
      break;

     default:
      /* Exit 'Done': '<S1>:369' */
      break;
    }

    /* Exit 'OnePath': '<S1>:328' */

    /* Disable for If: '<S10>/If' */
    brain_DWork.If_ActiveSubsystem_l = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_m);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_n);

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_m);

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_n);

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */
    brain_DWork.is_FollowOnePath = (uint8_T)0;
  } else {
    /* Exit 'Initialize': '<S1>:379' */
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_exit_internal_Autonomous(void)
{
  switch (brain_DWork.is_Autonomous) {
   case brain_IN_Buoy:
    /* Exit 'Buoy': '<S1>:58' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_FindBuoy:
    /* Exit 'FindBuoy': '<S1>:239' */

    /* Disable for If: '<S5>/If' */
    brain_DWork.If_ActiveSubsystem_m = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

    /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);

    /* end of Disable for SubSystem: '<S5>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

    /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_FollowOnePath:
    bra_exit_internal_FollowOnePath();

    /* Exit 'FollowOnePath': '<S1>:325' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_Start:
    /* Exit 'Start': '<S1>:153' */
    brain_B.DesiredHeading = brain_U.CurrentHeading;
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_ValidationGate:
    /* Exit 'ValidationGate': '<S1>:1' */

    /* Disable for If: '<S14>/If' */
    brain_DWork.If_ActiveSubsystem_c = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

    /* end of Disable for SubSystem: '<S14>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   default:
    /* Exit 'ChooseState': '<S1>:299' */
    /* Exit 'Finish': '<S1>:151' */
    break;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_Autonomous(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp_o;
  real_T rtb_Add1_a;
  real_T rtb_TSamp_p;
  real_T rtb_BuoyBlobAnalysis_o2[20];
  real_T rtb_XBuoyProportionalGain;
  real_T rtb_TSamp_d;
  real_T rtb_YBuoyProportionalGain;
  real_T rtb_TSamp_pt;
  real_T rtb_TSamp_a;
  real_T rtb_Add1_n;
  real_T rtb_TSamp_i;
  real_T rtb_MultiportSwitch_d;
  real_T rtb_Sum;
  real_T rtb_MultiportSwitch_l;
  real_T rtb_Add4_pv;
  real_T rtb_Error;
  real_T rtb_Add4_g;
  real32_T rtb_BlobAnalysis_o1;
  real32_T rtb_BlobAnalysis_o2;
  int32_T rtb_BuoyBlobAnalysis_o1[10];

  /* local scratch DWork variables */
  real_T MedianFilterH_WorkVector[27];
  real_T MedianFilterS_WorkVector[27];
  real_T sf_Obstacle;
  int8_T rtAction;
  uint32_T BlobAnalysis_NUM_PIX_DW;
  real32_T ys;
  real32_T xys;
  real32_T uyy;
  int32_T padRows;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  int32_T i;
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  int32_T i_0;
  real32_T centroid_idx;
  real32_T centroid_idx_0;
  int8_T rtb_DataTypeConversion_0;
  int64m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;

  /* During 'Autonomous': '<S1>:289' */
  if (brain_U.RC == 1) {
    /* Transition: '<S1>:438' */
    brain_exit_internal_Autonomous();

    /* Exit 'Autonomous': '<S1>:289' */
    /* Entry 'ControlledRC': '<S1>:408' */
    brain_DWork.is_Running = (uint8_T)brain_IN_ControlledRC;
  } else {
    switch (brain_DWork.is_Autonomous) {
     case brain_IN_Buoy:
      /* During 'Buoy': '<S1>:58' */
      if ((brain_DWork.countarea > 2.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:197' */
        /* Exit 'Buoy': '<S1>:58' */
        /* Entry 'Finish': '<S1>:151' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_Finish;
        brain_B.State = 6U;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Vertical = 0;
      } else if ((brain_U.DesiredState != 5) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:321' */
        /* Exit 'Buoy': '<S1>:58' */
        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else {
        /* Simulink Function 'Buoy': '<S1>:60' */
        for (i_0 = 0; i_0 < 19200; i_0++) {
          brain_B.SFunction_o18[i_0] = (real_T)brain_B.Resize[i_0];
          brain_B.SFunction_o19[i_0] = (real_T)brain_B.Resize1[i_0];
        }

        brain_DWork.RunningAutonomousBuoyBuoy_ELAPS = brain_M->Timing.clockTick0
          - brain_DWork.RunningAutonomousBuoyBuoy_PREV_;
        brain_DWork.RunningAutonomousBuoyBuoy_PREV_ = brain_M->Timing.clockTick0;

        /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S22>/Median Filter H' */
        {
          /* Do appropriate padding of input matrix with a constant value */
          int_T i,j;
          const byte_T *u = (const byte_T *)brain_B.SFunction_o18;
          const int_T bytesPerInpCol = sizeof(real_T)* 120;
          real_T *y = (real_T *)&brain_DWork.MedianFilterH_PaddedInput[0];
          real_T padValue = 0.0;

          /* Pad at the top-left, left and bottom-left part of the input matrix */
          for (i = 0; i < 2; i++) {
            for (j = 0; j < 124; j++) {
              *y++ = padValue;
            }
          }

          for (i = 2; i<162; i++) {
            /* Pad at the top of the input matrix */
            for (j = 0; j < 2; j++) {
              *y++ = padValue;
            }

            /* Copy input matrix in the output buffer */
            {
              byte_T *y1 = (byte_T *)y;
              memcpy(y1,u,bytesPerInpCol);
              y += 120;
              u += bytesPerInpCol;
            }

            /* Pad at the bottom of the input matrix */
            for (j = 122; j < 124; j++) {
              *y++ = padValue;
            }
          }

          /* Pad at the top-right, right and bottom-right part of the input matrix */
          for (i = 162; i< 164; i++) {
            for (j = 0; j < 124; j++) {
              *y++ = padValue;
            }
          }
        }

        {
          const real_T *inputA = &brain_DWork.MedianFilterH_PaddedInput[0];
          real_T *y = brain_B.MedianFilterS;
          real_T *inAC = &MedianFilterH_WorkVector[0];
          int_T i,j,m,n;
          for (i = 0; i < 160; i++) {
            int_T rowOffset = 124*(4+i);
            for (j = 0; j < 120; j++) {
              int_T indxA = rowOffset + j;
              int_T ctr = 0;
              for (m = 0; m < 5; m++) {
                for (n = 0; n < 5; n++) {
                  inAC[ctr++] = inputA[indxA++];
                }

                indxA -= 129;
              }

              {
                int_T left, right;
                left = 0, right = 24;
                while (right > (left+1)) {
                  /* Use median-of-three method to select the partitioning key. */
                  /* This method makes worst-case behavior much less likely and */
                  /* avoids the needs for sentinel values outside the array. */
                  /* First we sort the first, middle, and last element of the */
                  /* partition. */
                  int_T mid = (left + right) >> 1;
                  int_T ii, jj;
                  if (inAC[left] > inAC[mid]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[mid];
                    inAC[mid] = inAC[26];
                  }

                  if (inAC[left] > inAC[right]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[right];
                    inAC[right] = inAC[26];
                  }

                  if (inAC[mid] > inAC[right]) {
                    inAC[26] = inAC[mid];
                    inAC[mid] = inAC[right];
                    inAC[right] = inAC[26];
                  }

                  /* Now swap the middle value with the next-to-last value. */
                  inAC[26] = inAC[mid];
                  inAC[mid] = inAC[right - 1];
                  inAC[right - 1] = inAC[26];

                  /* Use the median of the three values as the partitioning key */
                  inAC[25] = inAC[right - 1];

                  /* Start the partitioning scan.  Note that because we sorted */
                  /* the left and right values, we can start the comparisons */
                  /* with (left+1) and (right-2).  This is how we avoid the */
                  /* need for sentinel values. */
                  ii = left;
                  jj = right - 1;
                  for (;;) {
                    while (inAC[++ii] < inAC[25]) ;
                    if (ii > 24)
                      ii = 24;
                    while (inAC[--jj] > inAC[25]) ;
                    if (jj < 0)
                      jj = 0;
                    if (ii >= jj)
                      break;           /* pointers crossed; end scan */

                    /* swap values at end of current interval */
                    inAC[26] = inAC[ii];
                    inAC[ii] = inAC[jj];
                    inAC[jj] = inAC[26];
                  }

                  /* One last swap needed at end of scan */
                  inAC[26] = inAC[ii];
                  inAC[ii] = inAC[right-1];
                  inAC[right-1] = inAC[26];

                  /* Select the left or right subpartition depending on */
                  /* the value of order. */
                  if (ii >= 12)
                    right = ii-1;
                  if (ii <= 12)
                    left = ii+1;
                }

                if ((right-left) == 1) {
                  /* Last partition has two elements that may not be sorted. */
                  if (inAC[left] > inAC[right]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[right];
                    inAC[right] = inAC[26];
                  }
                }

                *y++ = inAC[12];
              }
            }
          }
        }

        for (i_0 = 0; i_0 < 19200; i_0++) {
          /* RelationalOperator: '<S17>/Compare' incorporates:
           *  Constant: '<S17>/Constant'
           */
          brain_B.LogicalOperator[i_0] = (brain_B.MedianFilterS[i_0] >
            brain_P.Buoy_HueHigher);

          /* RelationalOperator: '<S18>/Compare' incorporates:
           *  Constant: '<S18>/Constant'
           */
          brain_B.Compare_d[i_0] = (brain_B.MedianFilterS[i_0] <=
            brain_P.Buoy_HueLower);

          /* Logic: '<S3>/Logical Operator' */
          brain_B.LogicalOperator[i_0] = (brain_B.LogicalOperator[i_0] ||
            brain_B.Compare_d[i_0]);
        }

        /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S22>/Median Filter S' */
        {
          /* Do appropriate padding of input matrix with a constant value */
          int_T i,j;
          const byte_T *u = (const byte_T *)brain_B.SFunction_o19;
          const int_T bytesPerInpCol = sizeof(real_T)* 120;
          real_T *y = (real_T *)&brain_DWork.MedianFilterH_PaddedInput[0];
          real_T padValue = 0.0;

          /* Pad at the top-left, left and bottom-left part of the input matrix */
          for (i = 0; i < 2; i++) {
            for (j = 0; j < 124; j++) {
              *y++ = padValue;
            }
          }

          for (i = 2; i<162; i++) {
            /* Pad at the top of the input matrix */
            for (j = 0; j < 2; j++) {
              *y++ = padValue;
            }

            /* Copy input matrix in the output buffer */
            {
              byte_T *y1 = (byte_T *)y;
              memcpy(y1,u,bytesPerInpCol);
              y += 120;
              u += bytesPerInpCol;
            }

            /* Pad at the bottom of the input matrix */
            for (j = 122; j < 124; j++) {
              *y++ = padValue;
            }
          }

          /* Pad at the top-right, right and bottom-right part of the input matrix */
          for (i = 162; i< 164; i++) {
            for (j = 0; j < 124; j++) {
              *y++ = padValue;
            }
          }
        }

        {
          const real_T *inputA = &brain_DWork.MedianFilterH_PaddedInput[0];
          real_T *y = brain_B.MedianFilterS;
          real_T *inAC = &MedianFilterS_WorkVector[0];
          int_T i,j,m,n;
          for (i = 0; i < 160; i++) {
            int_T rowOffset = 124*(4+i);
            for (j = 0; j < 120; j++) {
              int_T indxA = rowOffset + j;
              int_T ctr = 0;
              for (m = 0; m < 5; m++) {
                for (n = 0; n < 5; n++) {
                  inAC[ctr++] = inputA[indxA++];
                }

                indxA -= 129;
              }

              {
                int_T left, right;
                left = 0, right = 24;
                while (right > (left+1)) {
                  /* Use median-of-three method to select the partitioning key. */
                  /* This method makes worst-case behavior much less likely and */
                  /* avoids the needs for sentinel values outside the array. */
                  /* First we sort the first, middle, and last element of the */
                  /* partition. */
                  int_T mid = (left + right) >> 1;
                  int_T ii, jj;
                  if (inAC[left] > inAC[mid]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[mid];
                    inAC[mid] = inAC[26];
                  }

                  if (inAC[left] > inAC[right]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[right];
                    inAC[right] = inAC[26];
                  }

                  if (inAC[mid] > inAC[right]) {
                    inAC[26] = inAC[mid];
                    inAC[mid] = inAC[right];
                    inAC[right] = inAC[26];
                  }

                  /* Now swap the middle value with the next-to-last value. */
                  inAC[26] = inAC[mid];
                  inAC[mid] = inAC[right - 1];
                  inAC[right - 1] = inAC[26];

                  /* Use the median of the three values as the partitioning key */
                  inAC[25] = inAC[right - 1];

                  /* Start the partitioning scan.  Note that because we sorted */
                  /* the left and right values, we can start the comparisons */
                  /* with (left+1) and (right-2).  This is how we avoid the */
                  /* need for sentinel values. */
                  ii = left;
                  jj = right - 1;
                  for (;;) {
                    while (inAC[++ii] < inAC[25]) ;
                    if (ii > 24)
                      ii = 24;
                    while (inAC[--jj] > inAC[25]) ;
                    if (jj < 0)
                      jj = 0;
                    if (ii >= jj)
                      break;           /* pointers crossed; end scan */

                    /* swap values at end of current interval */
                    inAC[26] = inAC[ii];
                    inAC[ii] = inAC[jj];
                    inAC[jj] = inAC[26];
                  }

                  /* One last swap needed at end of scan */
                  inAC[26] = inAC[ii];
                  inAC[ii] = inAC[right-1];
                  inAC[right-1] = inAC[26];

                  /* Select the left or right subpartition depending on */
                  /* the value of order. */
                  if (ii >= 12)
                    right = ii-1;
                  if (ii <= 12)
                    left = ii+1;
                }

                if ((right-left) == 1) {
                  /* Last partition has two elements that may not be sorted. */
                  if (inAC[left] > inAC[right]) {
                    inAC[26] = inAC[left];
                    inAC[left] = inAC[right];
                    inAC[right] = inAC[26];
                  }
                }

                *y++ = inAC[12];
              }
            }
          }
        }

        for (i_0 = 0; i_0 < 19200; i_0++) {
          /* RelationalOperator: '<S19>/Compare' incorporates:
           *  Constant: '<S19>/Constant'
           */
          brain_B.Compare_d[i_0] = (brain_B.MedianFilterS[i_0] >=
            brain_P.Buoy_Saturation);

          /* Logic: '<S3>/Logical Operator1' */
          brain_B.BW[i_0] = (brain_B.LogicalOperator[i_0] &&
                             brain_B.Compare_d[i_0]);
        }

        /* S-Function (svipblob): '<S3>/Buoy Blob Analysis' */
        maxNumBlobsReached = false;
        for (i_0 = 0; i_0 < 123; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
        }

        currentLabel = 1U;
        i_0 = 0;
        idx = 123;
        for (n = 0; n < 160; n++) {
          for (n_0 = 0; n_0 < 120; n_0++) {
            brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.BW[i_0] ?
              255 : 0);
            i_0++;
            idx++;
          }

          brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
          idx++;
          brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
          idx++;
        }

        for (i_0 = 0; i_0 < 121; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0 + idx] = 0U;
        }

        n = 1;
        stackIdx = 0U;
        pixIdx = 0U;
        for (n_0 = 0; n_0 < 160; n_0++) {
          ms = 1;
          j = n * 122;
          for (idx = 0; idx < 120; idx++) {
            numBlobs = (uint32_T)(j + ms);
            start_pixIdx = pixIdx;
            if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
              brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
              brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
              brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
              brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                for (i = 0; i < 8; i++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled18[i];
                  if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                    brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                      ((int16_T)(walkerIdx / 122U) - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                      (walkerIdx % 122U - 1U);
                    pixIdx++;
                    BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                      BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
                    brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
                   brain_P.Min_Blob_Size) ||
                  (BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] >
                   brain_P.Max_Blob_Size)) {
                currentLabel--;
                pixIdx = start_pixIdx;
              }

              if (currentLabel == 10) {
                maxNumBlobsReached = true;
                n_0 = 160;
                idx = 120;
              }

              if (idx < 120) {
                currentLabel++;
              }
            }

            ms++;
          }

          n++;
        }

        numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel : (uint8_T)
                              (currentLabel - 1));
        i_0 = 0;
        n_0 = 0;
        for (idx = 0; idx < (int32_T)numBlobs; idx++) {
          rtb_BuoyBlobAnalysis_o1[idx] = (int32_T)
            BuoyBlobAnalysis_NUM_PIX_DW[idx];
          n = 0;
          ms = 0;
          for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx]; j++) {
            n += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n_0];
            ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i_0];
          }

          rtb_BuoyBlobAnalysis_o2[idx << 1] = (real_T)ms / (real_T)
            BuoyBlobAnalysis_NUM_PIX_DW[idx];
          rtb_BuoyBlobAnalysis_o2[(idx << 1) + 1] = (real_T)n / (real_T)
            BuoyBlobAnalysis_NUM_PIX_DW[idx];
          i_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
          n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
        }

        for (i_0 = (int32_T)numBlobs; i_0 < 10; i_0++) {
          rtb_BuoyBlobAnalysis_o1[i_0] = -1;
        }

        for (i_0 = (int32_T)numBlobs << 1; i_0 < 20; i_0++) {
          rtb_BuoyBlobAnalysis_o2[i_0] = -1.0;
        }

        /* Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
        /* Embedded MATLAB Function 'Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function': '<S20>:1' */
        /*  This function will choose and return data about the largest blob given a  */
        /*  set of blobs */
        if ((rtb_BuoyBlobAnalysis_o2[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2[1] ==
             -1.0)) {
          /* '<S20>:1:5' */
          /* '<S20>:1:7' */
          brain_B.BlobCentroidX = 80.0;

          /* '<S20>:1:8' */
          brain_B.BlobCentroidY = 60.0;

          /* '<S20>:1:9' */
          brain_B.BlobArea = -1.0;
        } else {
          /* '<S20>:1:11' */
          i_0 = rtb_BuoyBlobAnalysis_o1[0];
          n = 1;
          n_0 = 1;
          for (idx = 2; idx < 11; idx++) {
            n_0++;
            if (rtb_BuoyBlobAnalysis_o1[n_0 - 1] > i_0) {
              i_0 = rtb_BuoyBlobAnalysis_o1[n_0 - 1];
              n = idx;
            }
          }

          /* '<S20>:1:11' */
          brain_B.BlobArea = (real_T)i_0;

          /* '<S20>:1:12' */
          brain_B.BlobCentroidX = rtb_BuoyBlobAnalysis_o2[((n - 1) << 1) + 1];

          /* '<S20>:1:13' */
          brain_B.BlobCentroidY = rtb_BuoyBlobAnalysis_o2[(n - 1) << 1];
        }

        /* Embedded MATLAB: '<S3>/Embedded MATLAB Function1' */
        /* Embedded MATLAB Function 'Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function1': '<S21>:1' */
        /*  This function finds the center of an image */
        /* '<S21>:1:6' */
        /* '<S21>:1:7' */

        /* Sum: '<S23>/Subtract' */
        rtb_Sum = 80.0 - brain_B.BlobCentroidX;

        /* Gain: '<S25>/X-Buoy Proportional Gain' */
        rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Kp * rtb_Sum;

        /* Gain: '<S25>/X-Buoy Derivative Gain' */
        rtb_Error = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum;

        /* S-Function (sfix_tsampmath): '<S26>/TSamp' */

        /* Sample Time Math Block: '<S26>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_d = rtb_Error / (((brain_DWork.RunningAutonomousBuoyBuoy_ELAPS
          * 0.2))*(1.0));

        /* DiscreteIntegrator: '<S25>/X-Buoy Discrete-Time Integrator' */
        rtb_Error = brain_DWork.XBuoyDiscreteTimeIntegrator_DST;

        /* Sum: '<S25>/Sum' incorporates:
         *  Sum: '<S26>/Diff'
         *  UnitDelay: '<S26>/UD'
         */
        rtb_Error += (rtb_TSamp_d - brain_DWork.UD_DSTATE_gx) +
          rtb_XBuoyProportionalGain;

        /* DataTypeConversion: '<S23>/Data Type Conversion' */
        rtb_YBuoyProportionalGain = floor(rtb_Error);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        /* Sum: '<S23>/Add' incorporates:
         *  Constant: '<S23>/Vision_Forward_Velocity'
         */
        brain_B.Add = brain_P.Vision_Forward_Velocity + (real_T)
          rtb_DataTypeConversion_0;

        /* Product: '<S23>/Multiply' incorporates:
         *  Constant: '<S23>/Constant'
         */
        rtb_Error = (real_T)rtb_DataTypeConversion_0 * -1.0;

        /* Sum: '<S23>/Add1' incorporates:
         *  Constant: '<S23>/Vision_Forward_Velocity2'
         */
        brain_B.Add1 = rtb_Error + brain_P.Vision_Forward_Velocity;

        /* Gain: '<S25>/X-Buoy Integral Gain' */
        rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Ki * rtb_Sum;

        /* Sum: '<S24>/Subtract' */
        rtb_Error = 60.0 - brain_B.BlobCentroidY;

        /* Gain: '<S27>/Y-Buoy Proportional Gain' */
        rtb_YBuoyProportionalGain = brain_P.Cam_Forward_YPosition_Kp * rtb_Error;

        /* Gain: '<S27>/Y-Buoy Derivative Gain' */
        rtb_Sum = brain_P.Cam_Forward_YPosition_Kd * rtb_Error;

        /* S-Function (sfix_tsampmath): '<S28>/TSamp' */

        /* Sample Time Math Block: '<S28>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_pt = rtb_Sum / (((brain_DWork.RunningAutonomousBuoyBuoy_ELAPS *
          0.2))*(1.0));

        /* DiscreteIntegrator: '<S27>/Y-Buoy Discrete-Time Integrator' */
        rtb_Sum = brain_DWork.YBuoyDiscreteTimeIntegrator_DST;

        /* Sum: '<S27>/Sum' incorporates:
         *  Sum: '<S28>/Diff'
         *  UnitDelay: '<S28>/UD'
         */
        rtb_Sum += (rtb_TSamp_pt - brain_DWork.UD_DSTATE_p) +
          rtb_YBuoyProportionalGain;

        /* DataTypeConversion: '<S24>/Data Type Conversion' */
        rtb_YBuoyProportionalGain = floor(rtb_Sum);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DataTypeConversion = rtb_DataTypeConversion_0;

        /* Update for UnitDelay: '<S26>/UD' */
        brain_DWork.UD_DSTATE_gx = rtb_TSamp_d;

        /* Update for DiscreteIntegrator: '<S25>/X-Buoy Discrete-Time Integrator' */
        brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.RunningAutonomousBuoyBuoy_ELAPS *
          rtb_XBuoyProportionalGain +
          brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
        if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
          brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 15.0;
        } else {
          if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
            brain_DWork.XBuoyDiscreteTimeIntegrator_DST = -15.0;
          }
        }

        /* Update for UnitDelay: '<S28>/UD' */
        brain_DWork.UD_DSTATE_p = rtb_TSamp_pt;

        /* Update for DiscreteIntegrator: '<S27>/Y-Buoy Discrete-Time Integrator' incorporates:
         *  Gain: '<S27>/Y-Buoy Integral Gain'
         */
        brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.RunningAutonomousBuoyBuoy_ELAPS *
          (brain_P.Cam_Forward_YPosition_Ki * rtb_Error) +
          brain_DWork.YBuoyDiscreteTimeIntegrator_DST;
        if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
          brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 15.0;
        } else {
          if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
            brain_DWork.YBuoyDiscreteTimeIntegrator_DST = -15.0;
          }
        }

        brain_B.Right = (int8_T)brain_B.Add;
        brain_B.Left = (int8_T)brain_B.Add1;
        brain_B.Vertical = brain_B.DataTypeConversion;
        brain_B.BuoyCentroidX = brain_B.BlobCentroidY;
        brain_B.BuoyCentroidY = brain_B.BlobCentroidX;

        /* Embedded MATLAB Function 'countareas': '<S1>:83' */
        /*  This function acts to count the number of consecutive times a particular */
        /*  area is recognized by the recognition software */
        if ((int32_T)brain_B.BlobArea > 8500) {
          /* '<S1>:83:6' */
          /* '<S1>:83:7' */
          brain_DWork.countarea = brain_DWork.countarea + 1.0;
        } else {
          /* '<S1>:83:9' */
          brain_DWork.countarea = 0.0;
        }
      }
      break;

     case brain_IN_ChooseState:
      /* During 'ChooseState': '<S1>:299' */
      if ((brain_U.DesiredState == 1) || (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:301' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'Start': '<S1>:153' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_Start;
        brain_DWork.OldHeading = 0.0;
        brain_DWork.DesiredHeadingCount = 0.0;
        brain_B.BuoyCentroidX = 0.0;
        brain_B.BuoyCentroidY = 0.0;
        brain_B.CameraPosition = 2;
        brain_B.State = 1U;
      } else if (brain_U.DesiredState == 2) {
        /* Transition: '<S1>:303' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'ValidationGate': '<S1>:1' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ValidationGate;
        brain_DWork.RunningAutonomousValidationGa_h = brain_M->Timing.clockTick0;

        /* InitializeConditions for UnitDelay: '<S70>/UD' */
        brain_DWork.UD_DSTATE_i = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S68>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_D_a = 0.0;

        /* InitializeConditions for UnitDelay: '<S71>/UD' */
        brain_DWork.UD_DSTATE_k = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S69>/Heading Discrete-Time Integrator' */
        brain_DWork.HeadingDiscreteTimeIntegrator_m = 0.0;
        brain_DWork.OldObstacle = 0.0;
        brain_DWork.count = 0.0;
        brain_DWork.TrackCount = 0.0;
        brain_B.State = 2U;
      } else if (brain_U.DesiredState == 4) {
        /* Transition: '<S1>:320' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'FindBuoy': '<S1>:239' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_FindBuoy;
        brain_DWork.RunningAutonomousFindBuoyStra_g = brain_M->Timing.clockTick0;

        /* InitializeConditions for UnitDelay: '<S39>/UD' */
        brain_DWork.UD_DSTATE_g = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S37>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

        /* InitializeConditions for UnitDelay: '<S40>/UD' */
        brain_DWork.UD_DSTATE_l = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S38>/Heading Discrete-Time Integrator' */
        brain_DWork.HeadingDiscreteTimeIntegrator_g = 0.0;
        brain_DWork.OldObstacle = 0.0;
        brain_DWork.count = 0.0;
        brain_B.CameraPosition = 0;
        brain_B.State = 4U;
        brain_DWork.BuoyCount = 0.0;
      } else if (brain_U.DesiredState == 3) {
        /* Transition: '<S1>:318' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'FollowOnePath': '<S1>:325' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_FollowOnePath;

        /* Transition: '<S1>:326' */
        /* Entry 'Initialize': '<S1>:379' */
        brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
        brain_B.DesiredDepth = 5.0;
        brain_B.DesiredHeading = 0.0;
        brain_DWork.Done = 0.0;
        brain_B.State = 3U;

        /* Simulink Function 'MakeHSVImage': '<S1>:380' */
        for (i_0 = 0; i_0 < 19200; i_0++) {
          brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize[i_0];
          brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize1[i_0];
          brain_B.SFunction_o40[i_0] = (real_T)brain_B.Resize2[i_0];
        }

        RunningAutonomousFollowOnePathM(brain_B.SFunction_o38,
          brain_B.SFunction_o39, brain_B.SFunction_o40,
          &brain_B.RunningAutonomousFollowOnePat_i);
      } else {
        if (brain_U.DesiredState == 5) {
          /* Transition: '<S1>:322' */
          /* Exit 'ChooseState': '<S1>:299' */
          /* Entry 'Buoy': '<S1>:58' */
          brain_DWork.is_Autonomous = (uint8_T)brain_IN_Buoy;
          brain_DWork.countarea = 0.0;
          brain_B.State = 5U;
        }
      }
      break;

     case brain_IN_FindBuoy:
      /* During 'FindBuoy': '<S1>:239' */
      if ((brain_DWork.BuoyCount > 2.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:241' */
        /* Exit 'FindBuoy': '<S1>:239' */

        /* Disable for If: '<S5>/If' */
        brain_DWork.If_ActiveSubsystem_m = -1;
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

        /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);

        /* end of Disable for SubSystem: '<S5>/BigError S1' */

        /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

        /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */

        /* Entry 'Buoy': '<S1>:58' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_Buoy;
        brain_DWork.countarea = 0.0;
        brain_B.State = 5U;
      } else if ((brain_U.DesiredState != 4) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:319' */
        /* Exit 'FindBuoy': '<S1>:239' */

        /* Disable for If: '<S5>/If' */
        brain_DWork.If_ActiveSubsystem_m = -1;
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

        /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);

        /* end of Disable for SubSystem: '<S5>/BigError S1' */

        /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

        /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */

        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else {
        /* Simulink Function 'LookforBuoy': '<S1>:250' */

        /* DataStoreRead: '<S4>/Data Store Read' */
        brain_B.DataStoreRead = brain_DWork.Image;
        for (i_0 = 0; i_0 < 19200; i_0++) {
          brain_B.SFunction_o24[i_0] = (real_T)brain_B.Resize[i_0];
          brain_B.SFunction_o25[i_0] = (real_T)brain_B.Resize1[i_0];

          /* RelationalOperator: '<S31>/Compare' incorporates:
           *  Constant: '<S31>/Constant'
           */
          brain_B.BW_p[i_0] = (brain_B.SFunction_o24[i_0] <
                               brain_P.Buoy_HueLower);

          /* RelationalOperator: '<S30>/Compare' incorporates:
           *  Constant: '<S30>/Constant'
           */
          brain_B.Compare[i_0] = (brain_B.SFunction_o24[i_0] >
            brain_P.Buoy_HueHigher);

          /* Logic: '<S29>/Logical Operator' */
          brain_B.BW_p[i_0] = (brain_B.BW_p[i_0] || brain_B.Compare[i_0]);

          /* RelationalOperator: '<S34>/Compare' incorporates:
           *  Constant: '<S34>/Constant'
           */
          brain_B.Compare[i_0] = (brain_B.SFunction_o25[i_0] >
            brain_P.Buoy_Saturation);

          /* Logic: '<S29>/Logical Operator1' */
          brain_B.BW_p[i_0] = (brain_B.BW_p[i_0] && brain_B.Compare[i_0]);
        }

        /* S-Function (svipblob): '<S29>/Blob Analysis' */
        maxNumBlobsReached = false;
        for (i_0 = 0; i_0 < 123; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
        }

        currentLabel = 1U;
        i_0 = 0;
        ms = 123;
        for (n = 0; n < 160; n++) {
          for (n_0 = 0; n_0 < 120; n_0++) {
            brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)(brain_B.BW_p[i_0] ?
              255 : 0);
            i_0++;
            ms++;
          }

          brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
          ms++;
          brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
          ms++;
        }

        for (i_0 = 0; i_0 < 121; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0 + ms] = 0U;
        }

        n = 1;
        stackIdx = 0U;
        pixIdx = 0U;
        for (ms = 0; ms < 160; ms++) {
          j = 1;
          idx = n * 122;
          for (n_0 = 0; n_0 < 120; n_0++) {
            numBlobs = (uint32_T)(idx + j);
            start_pixIdx = pixIdx;
            if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
              brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
              brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
              brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(j - 1);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW = 1U;
              brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                for (i = 0; i < 8; i++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled18[i];
                  if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                    brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                      ((int16_T)(walkerIdx / 122U) - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                      (walkerIdx % 122U - 1U);
                    pixIdx++;
                    BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW + 1U;
                    brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BlobAnalysis_NUM_PIX_DW < brain_P.Min_Blob_Size) ||
                  (BlobAnalysis_NUM_PIX_DW > brain_P.Max_Blob_Size)) {
                currentLabel--;
                pixIdx = start_pixIdx;
              }

              if (currentLabel == 1) {
                maxNumBlobsReached = true;
                ms = 160;
                n_0 = 120;
              }

              if (n_0 < 120) {
                currentLabel++;
              }
            }

            j++;
          }

          n++;
        }

        numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel : (uint8_T)
                              (currentLabel - 1));
        n_0 = 0;
        i = 0;
        for (padRows = 0; padRows < (int32_T)numBlobs; padRows++) {
          i_0 = 0;
          n = 0;
          for (padCols = 0; padCols < (int32_T)BlobAnalysis_NUM_PIX_DW; padCols
               ++) {
            i_0 += brain_DWork.BlobAnalysis_N_PIXLIST_DW[padCols + i];
            n += brain_DWork.BlobAnalysis_M_PIXLIST_DW[padCols + n_0];
          }

          centroid_idx = (real32_T)n / (real32_T)BlobAnalysis_NUM_PIX_DW;
          centroid_idx_0 = (real32_T)i_0 / (real32_T)BlobAnalysis_NUM_PIX_DW;
          n = 160;
          ms = 120;
          j = 0;
          idx = 0;
          for (padCols = 0; padCols < (int32_T)BlobAnalysis_NUM_PIX_DW; padCols
               ++) {
            i_0 = padCols + i;
            if (brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_0] < n) {
              n = (int32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_0];
            }

            if (brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_0] > j) {
              j = (int32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_0];
            }

            i_0 = padCols + n_0;
            if (brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0] < ms) {
              ms = (int32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0];
            }

            if (brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0] > idx) {
              idx = (int32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0];
            }
          }

          rtb_BlobAnalysis_o1 = 0.0F;
          ys = 0.0F;
          xys = 0.0F;
          walkerIdx = 0U;
          while (1) {
            uLong2MultiWord(walkerIdx, &tmp_0.chunks[0U], 2);
            MultiWordSignedWrap(&tmp_0.chunks[0U], 2, (uint32_T)31, &tmp.chunks
                                [0U]);
            sLong2MultiWord((int32_T)BlobAnalysis_NUM_PIX_DW, &tmp_1.chunks[0U],
                            2);
            MultiWordSignedWrap(&tmp_1.chunks[0U], 2, (uint32_T)31,
                                &tmp_0.chunks[0U]);
            if (!sMultiWordLt(&tmp.chunks[0U], &tmp_0.chunks[0U], 2)) {
              break;
            }

            rtb_BlobAnalysis_o2 = (real32_T)
              brain_DWork.BlobAnalysis_N_PIXLIST_DW[i + walkerIdx] -
              centroid_idx_0;
            uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[n_0 +
              walkerIdx] - centroid_idx;
            rtb_BlobAnalysis_o1 += rtb_BlobAnalysis_o2 * rtb_BlobAnalysis_o2;
            ys += uyy * uyy;
            xys += rtb_BlobAnalysis_o2 * (-uyy);
            walkerIdx++;
          }

          centroid_idx = rtb_BlobAnalysis_o1 / (real32_T)BlobAnalysis_NUM_PIX_DW
            + 8.333333582E-02F;
          uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
          rtb_BlobAnalysis_o1 = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
          rtb_BlobAnalysis_o1 = (real32_T)sqrt((centroid_idx - uyy) *
            (centroid_idx - uyy) + rtb_BlobAnalysis_o1 * rtb_BlobAnalysis_o1 *
            4.0F);
          rtb_BlobAnalysis_o2 = ((centroid_idx + uyy) + rtb_BlobAnalysis_o1) *
            8.0F;
          rtb_BlobAnalysis_o1 = (real32_T)sqrt(rtb_BlobAnalysis_o2 -
            ((centroid_idx + uyy) - rtb_BlobAnalysis_o1) * 8.0F) / (real32_T)
            sqrt(rtb_BlobAnalysis_o2);
          rtb_BlobAnalysis_o2 = (real32_T)BlobAnalysis_NUM_PIX_DW / (real32_T)
            (((idx + 1) - ms) * ((j + 1) - n));
          n_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
          i += (int32_T)BlobAnalysis_NUM_PIX_DW;
        }

        for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
          rtb_BlobAnalysis_o1 = -1.0F;
        }

        for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
          rtb_BlobAnalysis_o2 = -1.0F;
        }

        /* If: '<S29>/If' incorporates:
         *  ActionPort: '<S32>/Action Port'
         *  ActionPort: '<S33>/Action Port'
         *  SubSystem: '<S29>/FoundBuoy'
         *  SubSystem: '<S29>/NoBuoy'
         */
        if ((rtb_BlobAnalysis_o1 > 0.0F) && (rtb_BlobAnalysis_o1 <
             6.499999762E-01F) && (rtb_BlobAnalysis_o2 > 6.999999881E-01F) &&
            (rtb_BlobAnalysis_o2 < 8.999999762E-01F)) {
          brain_FoundTrack(&brain_DWork.Image);
        } else {
          brain_NoTrack(&brain_DWork.Image);
        }

        sf_Obstacle = brain_B.DataStoreRead;

        /* Embedded MATLAB Function 'countimages': '<S1>:254' */
        /*  This function acts to count the number of consecutive times a particular */
        /*  image is recognized by the recognition software */
        if ((brain_B.DataStoreRead != 0.0) && (brain_B.DataStoreRead ==
             brain_DWork.OldObstacle)) {
          /* '<S1>:254:6' */
          /* '<S1>:254:7' */
          brain_DWork.BuoyCount = brain_DWork.count + 1.0;
        } else {
          /* '<S1>:254:9' */
          brain_DWork.BuoyCount = 0.0;
        }

        /* Simulink Function 'StraightLevelControl': '<S1>:242' */
        brain_B.SFunction_o20 = (real32_T)brain_U.CurrentDepth;
        brain_B.SFunction_o21 = (real32_T)brain_B.DesiredDepth;
        brain_B.SFunction_o22 = brain_B.DesiredHeading;
        brain_B.SFunction_o23 = brain_U.CurrentHeading;
        if (brain_DWork.RunningAutonomousFindBuoyStr_gx) {
          brain_DWork.RunningAutonomousFindBuoyStraig = 0U;
          brain_DWork.RunningAutonomousFindBuoyStr_gx = false;
        } else {
          brain_DWork.RunningAutonomousFindBuoyStraig =
            brain_M->Timing.clockTick0 -
            brain_DWork.RunningAutonomousFindBuoyStra_g;
        }

        brain_DWork.RunningAutonomousFindBuoyStra_g = brain_M->Timing.clockTick0;

        /* Sum: '<S5>/Add' */
        rtb_Add4_pv = (real_T)brain_B.SFunction_o21 - (real_T)
          brain_B.SFunction_o20;

        /* Gain: '<S37>/Depth Proportional Gain' */
        rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Add4_pv;

        /* Gain: '<S37>/Depth Derivative Gain' */
        rtb_MultiportSwitch_d = brain_P.Depth_Kd * rtb_Add4_pv;

        /* S-Function (sfix_tsampmath): '<S39>/TSamp' */

        /* Sample Time Math Block: '<S39>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_o = rtb_MultiportSwitch_d /
          (((brain_DWork.RunningAutonomousFindBuoyStraig * 0.2))*(1.0));

        /* DiscreteIntegrator: '<S37>/Depth Discrete-Time Integrator' */
        rtb_MultiportSwitch_d = brain_DWork.DepthDiscreteTimeIntegrator_DST;

        /* Sum: '<S37>/Sum' incorporates:
         *  Sum: '<S39>/Diff'
         *  UnitDelay: '<S39>/UD'
         */
        rtb_MultiportSwitch_d += (rtb_TSamp_o - brain_DWork.UD_DSTATE_g) +
          rtb_XBuoyProportionalGain;

        /* DataTypeConversion: '<S5>/Double To Int8' */
        rtb_YBuoyProportionalGain = floor(rtb_MultiportSwitch_d);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToInt8 = rtb_DataTypeConversion_0;

        /* Gain: '<S37>/Depth Integral Gain' */
        rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Add4_pv;

        /* Sum: '<S5>/Add1' */
        rtb_Add1_a = brain_B.SFunction_o22 - brain_B.SFunction_o23;

        /* If: '<S5>/If' incorporates:
         *  ActionPort: '<S35>/Action Port'
         *  ActionPort: '<S36>/Action Port'
         *  SubSystem: '<S5>/BigError S1'
         *  SubSystem: '<S5>/BigNegativeError S2'
         */
        rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem_m;
        rtAction = -1;
        if (rtb_Add1_a > 180.0) {
          rtAction = 0;
        } else {
          if (rtb_Add1_a < -180.0) {
            rtAction = 1;
          }
        }

        brain_DWork.If_ActiveSubsystem_m = rtAction;
        if (rtb_DataTypeConversion_0 != rtAction) {
          switch (rtb_DataTypeConversion_0) {
           case 0:
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1_b);
            break;

           case 1:
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);
            break;
          }
        }

        switch (rtAction) {
         case 0:
          brain_BigErrorS1(rtb_Add1_a, &brain_B.BigErrorS1_b);
          break;

         case 1:
          brain_BigNegativeErrorS2(rtb_Add1_a, &brain_B.BigNegativeErrorS2_h);
          break;
        }

        /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
         *  Constant: '<S5>/Constant1'
         *  Sum: '<S5>/Add2'
         */
        switch ((int32_T)((1.0 + brain_B.BigErrorS1_b.Constant1) +
                          brain_B.BigNegativeErrorS2_h.Constant1)) {
         case 1:
          rtb_MultiportSwitch_d = rtb_Add1_a;
          break;

         case 2:
          rtb_MultiportSwitch_d = brain_B.BigErrorS1_b.Add;
          break;

         default:
          rtb_MultiportSwitch_d = brain_B.BigNegativeErrorS2_h.Add;
          break;
        }

        /* Gain: '<S38>/Heading Proportional Gain' */
        rtb_YBuoyProportionalGain = brain_P.Heading_Kp * rtb_MultiportSwitch_d;

        /* Gain: '<S38>/Heading Derivative Gain' */
        rtb_Add4_pv = brain_P.Heading_Kd * rtb_MultiportSwitch_d;

        /* S-Function (sfix_tsampmath): '<S40>/TSamp' */

        /* Sample Time Math Block: '<S40>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_p = rtb_Add4_pv /
          (((brain_DWork.RunningAutonomousFindBuoyStraig * 0.2))*(1.0));

        /* DiscreteIntegrator: '<S38>/Heading Discrete-Time Integrator' */
        rtb_Add4_pv = brain_DWork.HeadingDiscreteTimeIntegrator_g;

        /* Sum: '<S38>/Sum' incorporates:
         *  Sum: '<S40>/Diff'
         *  UnitDelay: '<S40>/UD'
         */
        rtb_Add4_pv += (rtb_TSamp_p - brain_DWork.UD_DSTATE_l) +
          rtb_YBuoyProportionalGain;

        /* Product: '<S5>/Multiply' incorporates:
         *  Constant: '<S5>/Constant'
         */
        rtb_YBuoyProportionalGain = -rtb_Add4_pv;
        if (rtIsNaN(rtb_YBuoyProportionalGain) || rtIsInf
            (rtb_YBuoyProportionalGain)) {
          rtb_YBuoyProportionalGain = 0.0;
        } else {
          rtb_YBuoyProportionalGain = fmod(floor(rtb_YBuoyProportionalGain),
            256.0);
        }

        /* Sum: '<S5>/Add4' incorporates:
         *  Constant: '<S5>/Heading Forward Velocity'
         */
        rtb_Add4_pv += brain_P.Heading_Forward_Velocity;

        /* DataTypeConversion: '<S5>/DoubleToint1' incorporates:
         *  Constant: '<S5>/Heading Forward Velocity2'
         *  Sum: '<S5>/Add3'
         */
        rtb_YBuoyProportionalGain = (real_T)(rtb_YBuoyProportionalGain < 0.0 ?
          (int8_T)(-((int8_T)(uint8_T)(-rtb_YBuoyProportionalGain))) : (int8_T)
          (uint8_T)rtb_YBuoyProportionalGain) + brain_P.Heading_Forward_Velocity;
        rtb_YBuoyProportionalGain = floor(rtb_YBuoyProportionalGain);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToint1_l = rtb_DataTypeConversion_0;

        /* DataTypeConversion: '<S5>/DoubleToint8' */
        rtb_YBuoyProportionalGain = floor(rtb_Add4_pv);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToint8_c = rtb_DataTypeConversion_0;

        /* Update for UnitDelay: '<S39>/UD' */
        brain_DWork.UD_DSTATE_g = rtb_TSamp_o;

        /* Update for DiscreteIntegrator: '<S37>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.RunningAutonomousFindBuoyStraig *
          rtb_XBuoyProportionalGain +
          brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        /* Update for UnitDelay: '<S40>/UD' */
        brain_DWork.UD_DSTATE_l = rtb_TSamp_p;

        /* Update for DiscreteIntegrator: '<S38>/Heading Discrete-Time Integrator' incorporates:
         *  Gain: '<S38>/Heading Integral Gain'
         */
        brain_DWork.HeadingDiscreteTimeIntegrator_g = 0.2 * (real_T)
          brain_DWork.RunningAutonomousFindBuoyStraig * (brain_P.Heading_Ki *
          rtb_MultiportSwitch_d) + brain_DWork.HeadingDiscreteTimeIntegrator_g;
        if (brain_DWork.HeadingDiscreteTimeIntegrator_g >= 15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_g = 15.0;
        } else {
          if (brain_DWork.HeadingDiscreteTimeIntegrator_g <= -15.0) {
            brain_DWork.HeadingDiscreteTimeIntegrator_g = -15.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
        brain_B.Left = brain_B.DoubleToint8_c;
        brain_B.Right = brain_B.DoubleToint1_l;
        brain_DWork.OldObstacle = sf_Obstacle;
        brain_DWork.count = brain_DWork.BuoyCount;
      }
      break;

     case brain_IN_Finish:
      break;

     case brain_IN_FollowOnePath:
      /* During 'FollowOnePath': '<S1>:325' */
      if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:240' */
        bra_exit_internal_FollowOnePath();

        /* Exit 'FollowOnePath': '<S1>:325' */
        /* Entry 'FindBuoy': '<S1>:239' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_FindBuoy;
        brain_DWork.RunningAutonomousFindBuoyStra_g = brain_M->Timing.clockTick0;

        /* InitializeConditions for UnitDelay: '<S39>/UD' */
        brain_DWork.UD_DSTATE_g = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S37>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

        /* InitializeConditions for UnitDelay: '<S40>/UD' */
        brain_DWork.UD_DSTATE_l = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S38>/Heading Discrete-Time Integrator' */
        brain_DWork.HeadingDiscreteTimeIntegrator_g = 0.0;
        brain_DWork.OldObstacle = 0.0;
        brain_DWork.count = 0.0;
        brain_B.CameraPosition = 0;
        brain_B.State = 4U;
        brain_DWork.BuoyCount = 0.0;
      } else if ((brain_U.DesiredState != 3) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:304' */
        bra_exit_internal_FollowOnePath();

        /* Exit 'FollowOnePath': '<S1>:325' */
        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else {
        switch (brain_DWork.is_FollowOnePath) {
         case brain_IN_Initialize:
          /* During 'Initialize': '<S1>:379' */
          /* Transition: '<S1>:327' */
          /* Exit 'Initialize': '<S1>:379' */
          /* Entry 'OnePath': '<S1>:328' */
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_OnePath;

          /* Transition: '<S1>:331' */
          /* Entry 'GetDirections': '<S1>:332' */
          brain_DWork.is_OnePath = (uint8_T)brain_IN_GetDirections;
          brain_DWork.countTo = 0.0;
          brain_DWork.countAlong = 0.0;
          brain_DWork.outliersTo = 0.0;
          brain_DWork.outliersAlong = 0.0;
          brain_B.Left = 0;
          brain_B.Right = 0;
          break;

         case brain_IN_OnePath:
          brain_OnePath();
          break;

         default:
          /* Transition: '<S1>:326' */
          /* Entry 'Initialize': '<S1>:379' */
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
          brain_B.DesiredDepth = 5.0;
          brain_B.DesiredHeading = 0.0;
          brain_DWork.Done = 0.0;
          brain_B.State = 3U;

          /* Simulink Function 'MakeHSVImage': '<S1>:380' */
          for (i_0 = 0; i_0 < 19200; i_0++) {
            brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize[i_0];
            brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize1[i_0];
            brain_B.SFunction_o40[i_0] = (real_T)brain_B.Resize2[i_0];
          }

          RunningAutonomousFollowOnePathM(brain_B.SFunction_o38,
            brain_B.SFunction_o39, brain_B.SFunction_o40,
            &brain_B.RunningAutonomousFollowOnePat_i);
          break;
        }
      }
      break;

     case brain_IN_Start:
      /* During 'Start': '<S1>:153' */
      if ((brain_DWork.DesiredHeadingCount >= 3.0) && (brain_U.DesiredState == 0))
      {
        /* Transition: '<S1>:162' */
        /* Exit 'Start': '<S1>:153' */
        brain_B.DesiredHeading = brain_U.CurrentHeading;

        /* Entry 'ValidationGate': '<S1>:1' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ValidationGate;
        brain_DWork.RunningAutonomousValidationGa_h = brain_M->Timing.clockTick0;

        /* InitializeConditions for UnitDelay: '<S70>/UD' */
        brain_DWork.UD_DSTATE_i = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S68>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_D_a = 0.0;

        /* InitializeConditions for UnitDelay: '<S71>/UD' */
        brain_DWork.UD_DSTATE_k = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S69>/Heading Discrete-Time Integrator' */
        brain_DWork.HeadingDiscreteTimeIntegrator_m = 0.0;
        brain_DWork.OldObstacle = 0.0;
        brain_DWork.count = 0.0;
        brain_DWork.TrackCount = 0.0;
        brain_B.State = 2U;
      } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:300' */
        /* Exit 'Start': '<S1>:153' */
        brain_B.DesiredHeading = brain_U.CurrentHeading;

        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else {
        /* Embedded MATLAB Function 'InitialHeadingCount': '<S1>:154' */
        /* '<S1>:154:3' */
        if ((brain_U.CurrentHeading > brain_DWork.OldHeading - 2.0) &&
            (brain_U.CurrentHeading < brain_DWork.OldHeading + 2.0)) {
          /* '<S1>:154:5' */
          /* '<S1>:154:6' */
          brain_DWork.DesiredHeadingCount = brain_DWork.DesiredHeadingCount +
            1.0;
        } else {
          /* '<S1>:154:8' */
          brain_DWork.DesiredHeadingCount = 0.0;
        }

        /* '<S1>:154:10' */
        brain_DWork.OldHeading = brain_U.CurrentHeading;
        brain_B.DesiredDepth = 5.0;
      }
      break;

     case brain_IN_ValidationGate:
      /* During 'ValidationGate': '<S1>:1' */
      if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:302' */
        /* Exit 'ValidationGate': '<S1>:1' */

        /* Disable for If: '<S14>/If' */
        brain_DWork.If_ActiveSubsystem_c = -1;
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

        /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

        /* end of Disable for SubSystem: '<S14>/BigError S1' */

        /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

        /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */

        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else if ((brain_DWork.TrackCount > 2.0) && (brain_U.DesiredState == 0))
      {
        /* Transition: '<S1>:199' */
        /* Exit 'ValidationGate': '<S1>:1' */

        /* Disable for If: '<S14>/If' */
        brain_DWork.If_ActiveSubsystem_c = -1;
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

        /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
        brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

        /* end of Disable for SubSystem: '<S14>/BigError S1' */

        /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
        brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

        /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */

        /* Entry 'FollowOnePath': '<S1>:325' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_FollowOnePath;

        /* Transition: '<S1>:326' */
        /* Entry 'Initialize': '<S1>:379' */
        brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
        brain_B.DesiredDepth = 5.0;
        brain_B.DesiredHeading = 0.0;
        brain_DWork.Done = 0.0;
        brain_B.State = 3U;

        /* Simulink Function 'MakeHSVImage': '<S1>:380' */
        for (i_0 = 0; i_0 < 19200; i_0++) {
          brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize[i_0];
          brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize1[i_0];
          brain_B.SFunction_o40[i_0] = (real_T)brain_B.Resize2[i_0];
        }

        RunningAutonomousFollowOnePathM(brain_B.SFunction_o38,
          brain_B.SFunction_o39, brain_B.SFunction_o40,
          &brain_B.RunningAutonomousFollowOnePat_i);
      } else {
        /* Simulink Function 'LookforTrack': '<S1>:4' */

        /* DataStoreRead: '<S13>/Data Store Read' */
        brain_B.DataStoreRead_b = brain_DWork.Image_d;
        for (i_0 = 0; i_0 < 19200; i_0++) {
          brain_B.SFunction_o12[i_0] = (real_T)brain_B.Resize[i_0];
          brain_B.SFunction_o13[i_0] = (real_T)brain_B.Resize1[i_0];

          /* RelationalOperator: '<S63>/Compare' incorporates:
           *  Constant: '<S63>/Constant'
           */
          brain_B.BW_a[i_0] = (brain_B.SFunction_o12[i_0] <
                               brain_P.Track_HueLower);

          /* RelationalOperator: '<S62>/Compare' incorporates:
           *  Constant: '<S62>/Constant'
           */
          brain_B.Compare_e[i_0] = (brain_B.SFunction_o12[i_0] >
            brain_P.Track_HueHigher);

          /* Logic: '<S60>/Logical Operator' */
          brain_B.BW_a[i_0] = (brain_B.BW_a[i_0] || brain_B.Compare_e[i_0]);

          /* RelationalOperator: '<S65>/Compare' incorporates:
           *  Constant: '<S65>/Constant'
           */
          brain_B.Compare_e[i_0] = (brain_B.SFunction_o13[i_0] >
            brain_P.Track_Saturation);

          /* Logic: '<S60>/Logical Operator1' */
          brain_B.BW_a[i_0] = (brain_B.BW_a[i_0] && brain_B.Compare_e[i_0]);
        }

        /* S-Function (svipblob): '<S60>/Blob Analysis' */
        maxNumBlobsReached = false;
        for (i_0 = 0; i_0 < 123; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
        }

        currentLabel = 1U;
        i_0 = 0;
        ms = 123;
        for (n = 0; n < 160; n++) {
          for (n_0 = 0; n_0 < 120; n_0++) {
            brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)(brain_B.BW_a[i_0] ?
              255 : 0);
            i_0++;
            ms++;
          }

          brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
          ms++;
          brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
          ms++;
        }

        for (i_0 = 0; i_0 < 121; i_0++) {
          brain_DWork.BlobAnalysis_PAD_DW[i_0 + ms] = 0U;
        }

        n = 1;
        stackIdx = 0U;
        pixIdx = 0U;
        for (ms = 0; ms < 160; ms++) {
          j = 1;
          idx = n * 122;
          for (n_0 = 0; n_0 < 120; n_0++) {
            numBlobs = (uint32_T)(idx + j);
            start_pixIdx = pixIdx;
            if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
              brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
              brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
              brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(j - 1);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW = 1U;
              brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                for (i = 0; i < 8; i++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled18[i];
                  if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                    brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                      ((int16_T)(walkerIdx / 122U) - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                      (walkerIdx % 122U - 1U);
                    pixIdx++;
                    BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW + 1U;
                    brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BlobAnalysis_NUM_PIX_DW < brain_P.Min_Blob_Size) ||
                  (BlobAnalysis_NUM_PIX_DW > brain_P.Max_Blob_Size)) {
                currentLabel--;
                pixIdx = start_pixIdx;
              }

              if (currentLabel == 1) {
                maxNumBlobsReached = true;
                ms = 160;
                n_0 = 120;
              }

              if (n_0 < 120) {
                currentLabel++;
              }
            }

            j++;
          }

          n++;
        }

        numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel : (uint8_T)
                              (currentLabel - 1));
        i_0 = 0;
        n = 0;
        for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
          idx = 0;
          ms = 0;
          for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
            idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
            ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i_0];
          }

          centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW;
          centroid_idx_0 = (real32_T)idx / (real32_T)BlobAnalysis_NUM_PIX_DW;
          rtb_BlobAnalysis_o1 = 0.0F;
          ys = 0.0F;
          xys = 0.0F;
          walkerIdx = 0U;
          while (1) {
            uLong2MultiWord(walkerIdx, &tmp_2.chunks[0U], 2);
            MultiWordSignedWrap(&tmp_2.chunks[0U], 2, (uint32_T)31,
                                &tmp_1.chunks[0U]);
            sLong2MultiWord((int32_T)BlobAnalysis_NUM_PIX_DW, &tmp_3.chunks[0U],
                            2);
            MultiWordSignedWrap(&tmp_3.chunks[0U], 2, (uint32_T)31,
                                &tmp_2.chunks[0U]);
            if (!sMultiWordLt(&tmp_1.chunks[0U], &tmp_2.chunks[0U], 2)) {
              break;
            }

            rtb_BlobAnalysis_o2 = (real32_T)
              brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + walkerIdx] -
              centroid_idx_0;
            uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0 +
              walkerIdx] - centroid_idx;
            rtb_BlobAnalysis_o1 += rtb_BlobAnalysis_o2 * rtb_BlobAnalysis_o2;
            ys += uyy * uyy;
            xys += rtb_BlobAnalysis_o2 * (-uyy);
            walkerIdx++;
          }

          uyy = rtb_BlobAnalysis_o1 / (real32_T)BlobAnalysis_NUM_PIX_DW +
            8.333333582E-02F;
          ys = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
          rtb_BlobAnalysis_o1 = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
          rtb_BlobAnalysis_o1 = (real32_T)sqrt((uyy - ys) * (uyy - ys) +
            rtb_BlobAnalysis_o1 * rtb_BlobAnalysis_o1 * 4.0F);
          rtb_BlobAnalysis_o2 = ((uyy + ys) + rtb_BlobAnalysis_o1) * 8.0F;
          rtb_BlobAnalysis_o1 = (real32_T)sqrt(rtb_BlobAnalysis_o2 - ((uyy + ys)
            - rtb_BlobAnalysis_o1) * 8.0F) / (real32_T)sqrt(rtb_BlobAnalysis_o2);
          i_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
          n += (int32_T)BlobAnalysis_NUM_PIX_DW;
        }

        for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
          rtb_BlobAnalysis_o1 = -1.0F;
        }

        /* If: '<S60>/If' incorporates:
         *  ActionPort: '<S61>/Action Port'
         *  ActionPort: '<S64>/Action Port'
         *  SubSystem: '<S60>/FoundTrack'
         *  SubSystem: '<S60>/NoTrack'
         */
        if (rtb_BlobAnalysis_o1 > 8.999999762E-01F) {
          brain_FoundTrack(&brain_DWork.Image_d);
        } else {
          brain_NoTrack(&brain_DWork.Image_d);
        }

        sf_Obstacle = brain_B.DataStoreRead_b;

        /* Embedded MATLAB Function 'countimages': '<S1>:15' */
        /*  This function acts to count the number of consecutive times a particular */
        /*  image is recognized by the recognition software */
        if ((brain_B.DataStoreRead_b != 0.0) && (brain_B.DataStoreRead_b ==
             brain_DWork.OldObstacle)) {
          /* '<S1>:15:6' */
          /* '<S1>:15:7' */
          brain_DWork.TrackCount = brain_DWork.count + 1.0;
        } else {
          /* '<S1>:15:9' */
          brain_DWork.TrackCount = 0.0;
        }

        /* Simulink Function 'StraightLevelControl': '<S1>:28' */
        brain_B.SFunction_o14 = (real32_T)brain_U.CurrentDepth;
        brain_B.SFunction_o15 = (real32_T)brain_B.DesiredDepth;
        brain_B.SFunction_o16 = brain_B.DesiredHeading;
        brain_B.SFunction_o17 = brain_U.CurrentHeading;
        if (brain_DWork.RunningAutonomousValidationGa_n) {
          brain_DWork.RunningAutonomousValidationGate = 0U;
          brain_DWork.RunningAutonomousValidationGa_n = false;
        } else {
          brain_DWork.RunningAutonomousValidationGate =
            brain_M->Timing.clockTick0 -
            brain_DWork.RunningAutonomousValidationGa_h;
        }

        brain_DWork.RunningAutonomousValidationGa_h = brain_M->Timing.clockTick0;

        /* Sum: '<S14>/Add' */
        rtb_Add4_g = (real_T)brain_B.SFunction_o15 - (real_T)
          brain_B.SFunction_o14;

        /* Gain: '<S68>/Depth Proportional Gain' */
        rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Add4_g;

        /* Gain: '<S68>/Depth Derivative Gain' */
        rtb_MultiportSwitch_l = brain_P.Depth_Kd * rtb_Add4_g;

        /* S-Function (sfix_tsampmath): '<S70>/TSamp' */

        /* Sample Time Math Block: '<S70>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_a = rtb_MultiportSwitch_l /
          (((brain_DWork.RunningAutonomousValidationGate * 0.2))*(1.0));

        /* DiscreteIntegrator: '<S68>/Depth Discrete-Time Integrator' */
        rtb_MultiportSwitch_l = brain_DWork.DepthDiscreteTimeIntegrator_D_a;

        /* Sum: '<S68>/Sum' incorporates:
         *  Sum: '<S70>/Diff'
         *  UnitDelay: '<S70>/UD'
         */
        rtb_MultiportSwitch_l += (rtb_TSamp_a - brain_DWork.UD_DSTATE_i) +
          rtb_XBuoyProportionalGain;

        /* DataTypeConversion: '<S14>/Double To Int8' */
        rtb_YBuoyProportionalGain = floor(rtb_MultiportSwitch_l);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToInt8_l = rtb_DataTypeConversion_0;

        /* Gain: '<S68>/Depth Integral Gain' */
        rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Add4_g;

        /* Sum: '<S14>/Add1' */
        rtb_Add1_n = brain_B.SFunction_o16 - brain_B.SFunction_o17;

        /* If: '<S14>/If' incorporates:
         *  ActionPort: '<S66>/Action Port'
         *  ActionPort: '<S67>/Action Port'
         *  SubSystem: '<S14>/BigError S1'
         *  SubSystem: '<S14>/BigNegativeError S2'
         */
        rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem_c;
        rtAction = -1;
        if (rtb_Add1_n > 180.0) {
          rtAction = 0;
        } else {
          if (rtb_Add1_n < -180.0) {
            rtAction = 1;
          }
        }

        brain_DWork.If_ActiveSubsystem_c = rtAction;
        if (rtb_DataTypeConversion_0 != rtAction) {
          switch (rtb_DataTypeConversion_0) {
           case 0:
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
            break;

           case 1:
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);
            break;
          }
        }

        switch (rtAction) {
         case 0:
          brain_BigErrorS1(rtb_Add1_n, &brain_B.BigErrorS1);
          break;

         case 1:
          brain_BigNegativeErrorS2(rtb_Add1_n, &brain_B.BigNegativeErrorS2);
          break;
        }

        /* MultiPortSwitch: '<S14>/Multiport Switch' incorporates:
         *  Constant: '<S14>/Constant1'
         *  Sum: '<S14>/Add2'
         */
        switch ((int32_T)((1.0 + brain_B.BigErrorS1.Constant1) +
                          brain_B.BigNegativeErrorS2.Constant1)) {
         case 1:
          rtb_MultiportSwitch_l = rtb_Add1_n;
          break;

         case 2:
          rtb_MultiportSwitch_l = brain_B.BigErrorS1.Add;
          break;

         default:
          rtb_MultiportSwitch_l = brain_B.BigNegativeErrorS2.Add;
          break;
        }

        /* Gain: '<S69>/Heading Proportional Gain' */
        rtb_YBuoyProportionalGain = brain_P.Heading_Kp * rtb_MultiportSwitch_l;

        /* Gain: '<S69>/Heading Derivative Gain' */
        rtb_Add4_g = brain_P.Heading_Kd * rtb_MultiportSwitch_l;

        /* S-Function (sfix_tsampmath): '<S71>/TSamp' */

        /* Sample Time Math Block: '<S71>/TSamp'
         *
         * y = u * K     where     K = 1 / ( w * Ts )
         *
         * Input0  Data Type:  Floating Point real_T
         * Output0 Data Type:  Floating Point real_T
         * ElapsedTime Data Type:  Floating Point real_T
         */
        rtb_TSamp_i = rtb_Add4_g /
          (((brain_DWork.RunningAutonomousValidationGate * 0.2))*(1.0));

        /* DiscreteIntegrator: '<S69>/Heading Discrete-Time Integrator' */
        rtb_Add4_g = brain_DWork.HeadingDiscreteTimeIntegrator_m;

        /* Sum: '<S69>/Sum' incorporates:
         *  Sum: '<S71>/Diff'
         *  UnitDelay: '<S71>/UD'
         */
        rtb_Add4_g += (rtb_TSamp_i - brain_DWork.UD_DSTATE_k) +
          rtb_YBuoyProportionalGain;

        /* Product: '<S14>/Multiply' incorporates:
         *  Constant: '<S14>/Constant'
         */
        rtb_YBuoyProportionalGain = -rtb_Add4_g;
        if (rtIsNaN(rtb_YBuoyProportionalGain) || rtIsInf
            (rtb_YBuoyProportionalGain)) {
          rtb_YBuoyProportionalGain = 0.0;
        } else {
          rtb_YBuoyProportionalGain = fmod(floor(rtb_YBuoyProportionalGain),
            256.0);
        }

        /* Sum: '<S14>/Add4' incorporates:
         *  Constant: '<S14>/Heading_Forward_Velocity'
         */
        rtb_Add4_g += brain_P.Heading_Forward_Velocity;

        /* DataTypeConversion: '<S14>/DoubleToint1' incorporates:
         *  Constant: '<S14>/Heading_Forward_Velocity1'
         *  Sum: '<S14>/Add3'
         */
        rtb_YBuoyProportionalGain = (real_T)(rtb_YBuoyProportionalGain < 0.0 ?
          (int8_T)(-((int8_T)(uint8_T)(-rtb_YBuoyProportionalGain))) : (int8_T)
          (uint8_T)rtb_YBuoyProportionalGain) + brain_P.Heading_Forward_Velocity;
        rtb_YBuoyProportionalGain = floor(rtb_YBuoyProportionalGain);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToint1_j = rtb_DataTypeConversion_0;

        /* DataTypeConversion: '<S14>/DoubleToint8' */
        rtb_YBuoyProportionalGain = floor(rtb_Add4_g);
        if (rtb_YBuoyProportionalGain < 128.0) {
          if (rtb_YBuoyProportionalGain >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        brain_B.DoubleToint8_i = rtb_DataTypeConversion_0;

        /* Update for UnitDelay: '<S70>/UD' */
        brain_DWork.UD_DSTATE_i = rtb_TSamp_a;

        /* Update for DiscreteIntegrator: '<S68>/Depth Discrete-Time Integrator' */
        brain_DWork.DepthDiscreteTimeIntegrator_D_a = 0.2 * (real_T)
          brain_DWork.RunningAutonomousValidationGate *
          rtb_XBuoyProportionalGain +
          brain_DWork.DepthDiscreteTimeIntegrator_D_a;
        if (brain_DWork.DepthDiscreteTimeIntegrator_D_a >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_D_a = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_D_a <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_D_a = -10.0;
          }
        }

        /* Update for UnitDelay: '<S71>/UD' */
        brain_DWork.UD_DSTATE_k = rtb_TSamp_i;

        /* Update for DiscreteIntegrator: '<S69>/Heading Discrete-Time Integrator' incorporates:
         *  Gain: '<S69>/Heading Integral Gain'
         */
        brain_DWork.HeadingDiscreteTimeIntegrator_m = 0.2 * (real_T)
          brain_DWork.RunningAutonomousValidationGate * (brain_P.Heading_Ki *
          rtb_MultiportSwitch_l) + brain_DWork.HeadingDiscreteTimeIntegrator_m;
        if (brain_DWork.HeadingDiscreteTimeIntegrator_m >= 15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_m = 15.0;
        } else {
          if (brain_DWork.HeadingDiscreteTimeIntegrator_m <= -15.0) {
            brain_DWork.HeadingDiscreteTimeIntegrator_m = -15.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8_l;
        brain_B.Left = brain_B.DoubleToint8_i;
        brain_B.Right = brain_B.DoubleToint1_j;
        brain_DWork.OldObstacle = sf_Obstacle;
        brain_DWork.count = brain_DWork.TrackCount;
      }
      break;

     default:
      /* Transition: '<S1>:161' */
      /* Entry 'Start': '<S1>:153' */
      brain_DWork.is_Autonomous = (uint8_T)brain_IN_Start;
      brain_DWork.OldHeading = 0.0;
      brain_DWork.DesiredHeadingCount = 0.0;
      brain_B.BuoyCentroidX = 0.0;
      brain_B.BuoyCentroidY = 0.0;
      brain_B.CameraPosition = 2;
      brain_B.State = 1U;
      break;
    }
  }
}

/* Initial conditions for atomic system: '<Root>/Chart' */
void brain_Chart_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/Chart' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.Buoy.Buoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FindBuoy.LookforBuoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FindBuoy.StraightLevelControl'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.ValidationGate.StraightLevelControl'
   *  InitializeConditions for SubSystem: '<S1>/Running.ControlledRC.MaintainDepth'
   *  InitializeConditions for SubSystem: '<S1>/Running.ControlledRC.MaintainHeading'
   */
  brain_DWork.is_Running = 0U;
  brain_DWork.is_Autonomous = 0U;
  brain_DWork.is_FollowOnePath = 0U;
  brain_DWork.is_OnePath = 0U;
  brain_DWork.is_active_c1_brain = 0U;
  brain_DWork.is_c1_brain = 0U;
  brain_DWork.count = 0.0;
  brain_DWork.OldObstacle = 0.0;
  brain_DWork.countarea = 0.0;
  brain_DWork.DesiredHeadingCount = 0.0;
  brain_DWork.OldHeading = 0.0;
  brain_DWork.TrackCount = 0.0;
  brain_DWork.BuoyCount = 0.0;
  brain_DWork.AvgDesiredHeadingAlongPath[0] = 0.0;
  brain_DWork.AvgDesiredHeadingToPath[0] = 0.0;
  brain_DWork.AvgDesiredHeadingAlongPath[1] = 0.0;
  brain_DWork.AvgDesiredHeadingToPath[1] = 0.0;
  brain_DWork.HeadingAlongPath = 0.0;
  brain_DWork.countAlong = 0.0;
  brain_DWork.countTo = 0.0;
  brain_DWork.outliersAlong = 0.0;
  brain_DWork.outliersTo = 0.0;
  brain_DWork.Done = 0.0;
  brain_B.Right = 0;
  brain_B.Left = 0;
  brain_B.Strafe = 0;
  brain_B.Vertical = 0;
  brain_B.DesiredDepth = 0.0;
  brain_B.DesiredHeading = 0.0;
  brain_B.CameraPosition = 0;
  brain_B.BuoyCentroidX = 0.0;
  brain_B.BuoyCentroidY = 0.0;
  brain_B.State = 0U;
  brain_DWork.RunningAutonomousValidationGa_h = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S70>/UD' */
  brain_DWork.UD_DSTATE_i = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_D_a = 0.0;

  /* InitializeConditions for UnitDelay: '<S71>/UD' */
  brain_DWork.UD_DSTATE_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrator_m = 0.0;
  brain_DWork.RunningAutonomousBuoyBuoy_PREV_ = brain_M->Timing.clockTick0;
  brain_DWork.RunningAutonomousFindBuoyStra_g = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S39>/UD' */
  brain_DWork.UD_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

  /* InitializeConditions for UnitDelay: '<S40>/UD' */
  brain_DWork.UD_DSTATE_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrator_g = 0.0;
  RunningAutonomousFollowOne_Init(brain_M,
    &brain_DWork.RunningAutonomousFollowOnePa_mg);
  brain_DWork.RunningAutonomousFollowOnePat_m = brain_M->Timing.clockTick0;
  brain_DWork.RunningControlledRCMaintainHe_i = brain_M->Timing.clockTick0;
  RunningAutonomousFollowOne_Init(brain_M,
    &brain_DWork.RunningControlledRCMaintainDept);
}

/* Start for atomic system: '<Root>/Chart' */
void brain_Chart_Start(void)
{
  /* Start for Stateflow: '<Root>/Chart' incorporates:
   *  Start for SubSystem: '<S1>/Running.Autonomous.Buoy.Buoy'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FindBuoy.LookforBuoy'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FindBuoy.StraightLevelControl'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
   *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
   *  Start for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  Start for SubSystem: '<S1>/Running.Autonomous.ValidationGate.StraightLevelControl'
   *  Start for SubSystem: '<S1>/Running.ControlledRC.MaintainDepth'
   *  Start for SubSystem: '<S1>/Running.ControlledRC.MaintainHeading'
   */

  /* Start for If: '<S14>/If' */
  brain_DWork.If_ActiveSubsystem_c = -1;

  /* Start for If: '<S5>/If' */
  brain_DWork.If_ActiveSubsystem_m = -1;

  /* Start for If: '<S10>/If' */
  brain_DWork.If_ActiveSubsystem_l = -1;

  /* Start for If: '<S16>/If' */
  brain_DWork.If_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<Root>/Chart' */
void brain_Chart(void)
{
  /* local block i/o variables */
  real_T rtb_Add1;
  real_T rtb_TSamp;
  real_T rtb_Add4;

  {
    int8_T rtPrevAction;
    int8_T rtAction;
    real_T rtb_MultiportSwitch;
    real_T rtb_HeadingProportionalGain;

    /* Stateflow: '<Root>/Chart' incorporates:
     *  Inport: '<Root>/CurrentDepth'
     *  Inport: '<Root>/CurrentHeading'
     *  Inport: '<Root>/RC'
     *  Inport: '<Root>/RC_Depth'
     *  Inport: '<Root>/RC_ForwardVelocity'
     *  Inport: '<Root>/RC_Heading'
     *  Inport: '<Root>/RC_Strafe'
     *  Inport: '<Root>/Status'
     *  SubSystem: '<S1>/Running.Autonomous.Buoy.Buoy'
     *  SubSystem: '<S1>/Running.Autonomous.FindBuoy.LookforBuoy'
     *  SubSystem: '<S1>/Running.Autonomous.FindBuoy.StraightLevelControl'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
     *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
     *  SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
     *  SubSystem: '<S1>/Running.Autonomous.ValidationGate.StraightLevelControl'
     *  SubSystem: '<S1>/Running.ControlledRC.MaintainDepth'
     *  SubSystem: '<S1>/Running.ControlledRC.MaintainHeading'
     */
    /* Gateway: Chart */
    /* During: Chart */
    if (brain_DWork.is_active_c1_brain == 0) {
      /* Entry: Chart */
      brain_DWork.is_active_c1_brain = 1U;

      /* Transition: '<S1>:295' */
      /* Entry 'NotRunning': '<S1>:291' */
      brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Vertical = 0;
    } else {
      switch (brain_DWork.is_c1_brain) {
       case brain_IN_NotRunning:
        /* During 'NotRunning': '<S1>:291' */
        if (brain_U.Status == 1) {
          /* Transition: '<S1>:293' */
          /* Exit 'NotRunning': '<S1>:291' */
          /* Entry 'Running': '<S1>:435' */
          brain_DWork.is_c1_brain = (uint8_T)brain_IN_Running;

          /* Transition: '<S1>:436' */
          /* Entry 'Autonomous': '<S1>:289' */
          brain_DWork.is_Running = (uint8_T)brain_IN_Autonomous;

          /* Transition: '<S1>:161' */
          /* Entry 'Start': '<S1>:153' */
          brain_DWork.is_Autonomous = (uint8_T)brain_IN_Start;
          brain_DWork.OldHeading = 0.0;
          brain_DWork.DesiredHeadingCount = 0.0;
          brain_B.BuoyCentroidX = 0.0;
          brain_B.BuoyCentroidY = 0.0;
          brain_B.CameraPosition = 2;
          brain_B.State = 1U;
        }
        break;

       case brain_IN_Running:
        /* During 'Running': '<S1>:435' */
        if (brain_U.Status == 0) {
          /* Transition: '<S1>:292' */
          switch (brain_DWork.is_Running) {
           case brain_IN_Autonomous:
            brain_exit_internal_Autonomous();

            /* Exit 'Autonomous': '<S1>:289' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           case brain_IN_ControlledRC:
            /* Exit 'ControlledRC': '<S1>:408' */

            /* Disable for If: '<S16>/If' */
            brain_DWork.If_ActiveSubsystem = -1;
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1_a);
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

            /* Disable for ifaction SubSystem: '<S16>/BigError S1' */
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1_a);

            /* end of Disable for SubSystem: '<S16>/BigError S1' */

            /* Disable for ifaction SubSystem: '<S16>/BigNegativeError S2' */
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

            /* end of Disable for SubSystem: '<S16>/BigNegativeError S2' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           default:
            brain_DWork.is_Running = (uint8_T)0;
            break;
          }

          /* Exit 'Running': '<S1>:435' */
          /* Entry 'NotRunning': '<S1>:291' */
          brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
          brain_B.Left = 0;
          brain_B.Right = 0;
          brain_B.Vertical = 0;
        } else {
          switch (brain_DWork.is_Running) {
           case brain_IN_Autonomous:
            brain_Autonomous();
            break;

           case brain_IN_ControlledRC:
            /* During 'ControlledRC': '<S1>:408' */
            if (brain_U.RC == 0) {
              /* Transition: '<S1>:439' */
              /* Exit 'ControlledRC': '<S1>:408' */

              /* Disable for If: '<S16>/If' */
              brain_DWork.If_ActiveSubsystem = -1;
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_a);
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

              /* Disable for ifaction SubSystem: '<S16>/BigError S1' */
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_a);

              /* end of Disable for SubSystem: '<S16>/BigError S1' */

              /* Disable for ifaction SubSystem: '<S16>/BigNegativeError S2' */
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

              /* end of Disable for SubSystem: '<S16>/BigNegativeError S2' */

              /* Entry 'Autonomous': '<S1>:289' */
              brain_DWork.is_Running = (uint8_T)brain_IN_Autonomous;

              /* Transition: '<S1>:161' */
              /* Entry 'Start': '<S1>:153' */
              brain_DWork.is_Autonomous = (uint8_T)brain_IN_Start;
              brain_DWork.OldHeading = 0.0;
              brain_DWork.DesiredHeadingCount = 0.0;
              brain_B.BuoyCentroidX = 0.0;
              brain_B.BuoyCentroidY = 0.0;
              brain_B.CameraPosition = 2;
              brain_B.State = 1U;
            } else {
              /* Simulink Function 'MaintainDepth': '<S1>:424' */
              brain_B.SFunction_o44 = (real32_T)brain_U.CurrentDepth;
              brain_B.SFunction_o45 = (real32_T)brain_U.RC_Depth;
              RunningAutonomousFollowOnePathO(brain_B.SFunction_o45,
                brain_B.SFunction_o44, brain_M,
                &brain_B.RunningControlledRCMaintainDept,
                &brain_DWork.RunningControlledRCMaintainDept);
              brain_B.Vertical =
                brain_B.RunningControlledRCMaintainDept.DoubleToInt8;

              /* Simulink Function 'MaintainHeading': '<S1>:428' */
              brain_B.SFunction_o41 = brain_U.RC_Heading;
              brain_B.SFunction_o42 = brain_U.CurrentHeading;
              brain_B.SFunction_o43 = brain_U.RC_ForwardVelocity;
              brain_DWork.RunningControlledRCMaintainHead =
                brain_M->Timing.clockTick0 -
                brain_DWork.RunningControlledRCMaintainHe_i;
              brain_DWork.RunningControlledRCMaintainHe_i =
                brain_M->Timing.clockTick0;

              /* Sum: '<S16>/Add1' */
              rtb_Add1 = brain_B.SFunction_o41 - brain_B.SFunction_o42;

              /* If: '<S16>/If' incorporates:
               *  ActionPort: '<S74>/Action Port'
               *  ActionPort: '<S75>/Action Port'
               *  SubSystem: '<S16>/BigError S1'
               *  SubSystem: '<S16>/BigNegativeError S2'
               */
              rtPrevAction = brain_DWork.If_ActiveSubsystem;
              rtAction = -1;
              if (rtb_Add1 > 180.0) {
                rtAction = 0;
              } else {
                if (rtb_Add1 < -180.0) {
                  rtAction = 1;
                }
              }

              brain_DWork.If_ActiveSubsystem = rtAction;
              if (rtPrevAction != rtAction) {
                switch (rtPrevAction) {
                 case 0:
                  brain_BigErrorS1_Disable(&brain_B.BigErrorS1_a);
                  break;

                 case 1:
                  brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);
                  break;
                }
              }

              switch (rtAction) {
               case 0:
                brain_BigErrorS1(rtb_Add1, &brain_B.BigErrorS1_a);
                break;

               case 1:
                brain_BigNegativeErrorS2(rtb_Add1, &brain_B.BigNegativeErrorS2_a);
                break;
              }

              /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
               *  Constant: '<S16>/Constant1'
               *  Sum: '<S16>/Add2'
               */
              switch ((int32_T)((1.0 + brain_B.BigErrorS1_a.Constant1) +
                                brain_B.BigNegativeErrorS2_a.Constant1)) {
               case 1:
                rtb_MultiportSwitch = rtb_Add1;
                break;

               case 2:
                rtb_MultiportSwitch = brain_B.BigErrorS1_a.Add;
                break;

               default:
                rtb_MultiportSwitch = brain_B.BigNegativeErrorS2_a.Add;
                break;
              }

              /* Gain: '<S76>/Heading Proportional Gain' */
              rtb_HeadingProportionalGain = brain_P.Heading_Kp *
                rtb_MultiportSwitch;

              /* Gain: '<S76>/Heading Derivative Gain' */
              rtb_Add4 = brain_P.Heading_Kd * rtb_MultiportSwitch;

              /* S-Function (sfix_tsampmath): '<S77>/TSamp' */

              /* Sample Time Math Block: '<S77>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp = rtb_Add4 /
                (((brain_DWork.RunningControlledRCMaintainHead * 0.2))*(1.0));

              /* DiscreteIntegrator: '<S76>/Heading Discrete-Time Integrator' */
              rtb_Add4 = brain_DWork.HeadingDiscreteTimeIntegrator_D;

              /* Sum: '<S76>/Sum' incorporates:
               *  Sum: '<S77>/Diff'
               *  UnitDelay: '<S77>/UD'
               */
              rtb_Add4 += (rtb_TSamp - brain_DWork.UD_DSTATE) +
                rtb_HeadingProportionalGain;

              /* Product: '<S16>/Multiply' incorporates:
               *  Constant: '<S16>/Constant'
               */
              rtb_HeadingProportionalGain = -rtb_Add4;
              if (rtIsNaN(rtb_HeadingProportionalGain) || rtIsInf
                  (rtb_HeadingProportionalGain)) {
                rtb_HeadingProportionalGain = 0.0;
              } else {
                rtb_HeadingProportionalGain = fmod(floor
                  (rtb_HeadingProportionalGain), 256.0);
              }

              /* Sum: '<S16>/Add4' */
              rtb_Add4 += brain_B.SFunction_o43;

              /* DataTypeConversion: '<S16>/DoubleToint1' incorporates:
               *  Sum: '<S16>/Add3'
               */
              rtb_HeadingProportionalGain = (real_T)(rtb_HeadingProportionalGain
                < 0.0 ? (int8_T)(-((int8_T)(uint8_T)
                                   (-rtb_HeadingProportionalGain))) : (int8_T)
                (uint8_T)rtb_HeadingProportionalGain) + brain_B.SFunction_o43;
              rtb_HeadingProportionalGain = floor(rtb_HeadingProportionalGain);
              if (rtb_HeadingProportionalGain < 128.0) {
                if (rtb_HeadingProportionalGain >= -128.0) {
                  rtPrevAction = (int8_T)rtb_HeadingProportionalGain;
                } else {
                  rtPrevAction = MIN_int8_T;
                }
              } else {
                rtPrevAction = MAX_int8_T;
              }

              brain_B.DoubleToint1 = rtPrevAction;

              /* DataTypeConversion: '<S16>/DoubleToint8' */
              rtb_HeadingProportionalGain = floor(rtb_Add4);
              if (rtb_HeadingProportionalGain < 128.0) {
                if (rtb_HeadingProportionalGain >= -128.0) {
                  rtPrevAction = (int8_T)rtb_HeadingProportionalGain;
                } else {
                  rtPrevAction = MIN_int8_T;
                }
              } else {
                rtPrevAction = MAX_int8_T;
              }

              brain_B.DoubleToint8 = rtPrevAction;

              /* Update for UnitDelay: '<S77>/UD' */
              brain_DWork.UD_DSTATE = rtb_TSamp;

              /* Update for DiscreteIntegrator: '<S76>/Heading Discrete-Time Integrator' incorporates:
               *  Gain: '<S76>/Heading Integral Gain'
               */
              brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
                brain_DWork.RunningControlledRCMaintainHead *
                (brain_P.Heading_Ki * rtb_MultiportSwitch) +
                brain_DWork.HeadingDiscreteTimeIntegrator_D;
              if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
                brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
              } else {
                if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
                  brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
                }
              }

              brain_B.Left = brain_B.DoubleToint8;
              brain_B.Right = brain_B.DoubleToint1;
              brain_B.Strafe = (int8_T)brain_U.RC_Strafe;
            }
            break;

           default:
            /* Transition: '<S1>:436' */
            /* Entry 'Autonomous': '<S1>:289' */
            brain_DWork.is_Running = (uint8_T)brain_IN_Autonomous;

            /* Transition: '<S1>:161' */
            /* Entry 'Start': '<S1>:153' */
            brain_DWork.is_Autonomous = (uint8_T)brain_IN_Start;
            brain_DWork.OldHeading = 0.0;
            brain_DWork.DesiredHeadingCount = 0.0;
            brain_B.BuoyCentroidX = 0.0;
            brain_B.BuoyCentroidY = 0.0;
            brain_B.CameraPosition = 2;
            brain_B.State = 1U;
            break;
          }
        }
        break;

       default:
        /* Transition: '<S1>:295' */
        /* Entry 'NotRunning': '<S1>:291' */
        brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Vertical = 0;
        break;
      }
    }
  }
}

/* Model step function */
void brain_step(void)
{
  /* local scratch DWork variables */
  real32_T Resize_LineBuffer[480];
  real32_T Resize1_LineBuffer[480];
  real32_T Resize2_LineBuffer[480];

  {
    uint32_T cc;
    uint32_T cc_0;
    uint32_T pos;
    uint32_T neg;
    uint32_T yDiff;
    real32_T cc_1;
    real32_T min;
    real32_T max;
    int32_T outStep;
    int32_T inStep;
    int32_T n;
    int32_T o;
    int32_T m;
    int32_T k;

    /* S-Function (svipchromresamp): '<S2>/Chroma Resampling' incorporates:
     *  Inport: '<Root>/Cb'
     *  Inport: '<Root>/Cr'
     */
    outStep = 0;
    inStep = 0;
    for (n = 0; n < 320; n++) {
      o = inStep;
      for (m = 0; m < 240; m++) {
        k = m << 1;
        brain_B.RGBVid_R[outStep + k] = brain_U.Cb[o];
        brain_B.RGBVid_R[(outStep + k) + 1] = brain_U.Cb[o];
        k += 480;
        brain_B.RGBVid_R[outStep + k] = brain_U.Cb[o];
        brain_B.RGBVid_R[(outStep + k) + 1] = brain_U.Cb[o];
        o++;
      }

      inStep += 240;
      outStep += 960;
    }

    outStep = 0;
    inStep = 0;
    for (n = 0; n < 320; n++) {
      o = inStep;
      for (m = 0; m < 240; m++) {
        k = m << 1;
        brain_B.RGBVid_G[outStep + k] = brain_U.Cr[o];
        brain_B.RGBVid_G[(outStep + k) + 1] = brain_U.Cr[o];
        k += 480;
        brain_B.RGBVid_G[outStep + k] = brain_U.Cr[o];
        brain_B.RGBVid_G[(outStep + k) + 1] = brain_U.Cr[o];
        o++;
      }

      inStep += 240;
      outStep += 960;
    }

    /* S-Function (svipcolorconv): '<S2>/Y-Cb-Cr to RGB Color Space  Conversion' incorporates:
     *  Inport: '<Root>/Y'
     */
    /* Precompute constants */
    for (outStep = 0; outStep < 307200; outStep++) {
      /* Convert YcbCr to RGB; apply coefficients and offsets */
      /* derived from the ITU BT.601-5 recommendation; all of the */
      /* coefficients and offsets are scaled (by 2^14) such that */
      /* the conversion can be done using integer arithmetic; this */
      /* routine relies on the user supplying the data in proper */
      /* ranges: Y [16..235], Cb & Cr [16..240] */
      /* Note that all of the operations are grouped in such a way */
      /* that the arithmetic can be done using unsigned integers */
      /* Given that Y is in the proper range, yDiff should */
      /* always be positive */
      yDiff = (uint32_T)brain_U.Y[outStep] - 16U;

      /* Red; 8192 in this equations is 0.5*2^14 or 2^13; adding 0.5  */
      /* before truncation will result in rounding */
      pos = (yDiff * 19077U + (uint32_T)(brain_B.RGBVid_G[outStep] * 26149)) +
        8192U;
      if (pos > 3347072U) {
        cc = pos - 3347072U;
      } else {
        cc = 0U;
      }

      cc >>= 14;

      /* limit to avoid wrapping */
      if (cc > 255U) {
        cc = 255U;
      }

      /* Compute green channel */
      pos = yDiff * 19077U + 2534784U;
      neg = (uint32_T)(brain_B.RGBVid_R[outStep] * 6419 +
                       brain_B.RGBVid_G[outStep] * 13320);
      if (pos > neg) {
        cc_0 = pos - neg;
      } else {
        cc_0 = 0U;
      }

      /* scale back */
      cc_0 >>= 14;
      if (cc_0 > 255U) {
        cc_0 = 255U;
      }

      /* Compute blue channel */
      pos = (yDiff * 19077U + (uint32_T)(brain_B.RGBVid_R[outStep] * 33050)) +
        8192U;
      if (pos > 4230400U) {
        neg = pos - 4230400U;
      } else {
        neg = 0U;
      }

      /* scale back */
      neg >>= 14;
      if (neg > 255U) {
        neg = 255U;
      }

      /* assign back the results */
      brain_B.RGBVid_R[outStep] = (uint8_T)cc;
      brain_B.RGBVid_G[outStep] = (uint8_T)cc_0;
      brain_B.RGBVid_B[outStep] = (uint8_T)neg;
    }

    for (outStep = 0; outStep < 307200; outStep++) {
      /* S-Function (svipscalenconvert): '<S2>/Red Data Type Conversion' */
      brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = (real32_T)
        brain_B.RGBVid_R[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Green Data Type Conversion1' */
      brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = (real32_T)
        brain_B.RGBVid_G[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Blue Data Type Conversion2' */
      brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = (real32_T)
        brain_B.RGBVid_B[outStep] / 255.0F;
    }

    /* S-Function (svipcolorconv): '<S2>/RGB to HSV Color Space  Conversion' */
    /* temporary variables for in-place operation */
    for (outStep = 0; outStep < 307200; outStep++) {
      /* First get the min and max of the RGB triplet */
      if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] >
          brain_B.RGBtoHSVColorSpaceConversion_o2[outStep]) {
        if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] <
            brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
          min = brain_B.RGBtoHSVColorSpaceConversion_o2[outStep];
        } else {
          min = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
        }

        if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] >
            brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
          max = brain_B.RGBtoHSVColorSpaceConversion_o1[outStep];
        } else {
          max = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
        }
      } else {
        if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] <
            brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
          min = brain_B.RGBtoHSVColorSpaceConversion_o1[outStep];
        } else {
          min = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
        }

        if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] >
            brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
          max = brain_B.RGBtoHSVColorSpaceConversion_o2[outStep];
        } else {
          max = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
        }
      }

      min = max - min;
      if (max != 0.0F) {
        cc_1 = min / max;
      } else {
        cc_1 = 0.0F;
      }

      if (min != 0.0F) {
        if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] == max) {
          min = (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] -
                 brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) / min;
        } else if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] == max) {
          min = (brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] -
                 brain_B.RGBtoHSVColorSpaceConversion_o1[outStep]) / min + 2.0F;
        } else {
          min = (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] -
                 brain_B.RGBtoHSVColorSpaceConversion_o2[outStep]) / min + 4.0F;
        }

        min /= 6.0F;
        if (min < 0.0F) {
          min++;
        }
      } else {
        min = 0.0F;
      }

      /* assign the results */
      brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = min;
      brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = cc_1;
      brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = max;
    }

    /* Video Processing Blockset 2D Resize (svipresize) - '<S2>/Resize' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o1;
      real32_T *out = brain_B.Resize;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled17[0];
      const real32_T *pW = &brain_ConstP.pooled14[0];
      int_T row, col, k, ctr = 0;
      for (row = 0; row < 480; row++) {
        int_T indx = row;
        for (col = 0; col < 160; col++) {
          int_T ictr = col;
          real32_T sum = 0.0F;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += in[row+offset*480] * pW[ictr];
            ictr += 160;
          }

          intBuf[indx] = sum;
          indx += 480;
        }
      }

      pW = &brain_ConstP.pooled13[0];
      pI = &brain_ConstP.pooled16[0];
      for (col = 0; col < 160; col++) {
        real32_T *inB = intBuf + col*480;
        real32_T *lineBuf = &Resize_LineBuffer[0];
        memcpy(lineBuf, inB, 480*sizeof(real32_T));
        for (row = 0; row < 120; row++) {
          real32_T sum = 0.0F;
          int_T ictr = row;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += lineBuf[offset] * pW[ictr];
            ictr += 120;
          }

          out[ctr++] = sum;
        }
      }
    }

    /* Video Processing Blockset 2D Resize (svipresize) - '<S2>/Resize1' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o2;
      real32_T *out = brain_B.Resize1;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled17[0];
      const real32_T *pW = &brain_ConstP.pooled14[0];
      int_T row, col, k, ctr = 0;
      for (row = 0; row < 480; row++) {
        int_T indx = row;
        for (col = 0; col < 160; col++) {
          int_T ictr = col;
          real32_T sum = 0.0F;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += in[row+offset*480] * pW[ictr];
            ictr += 160;
          }

          intBuf[indx] = sum;
          indx += 480;
        }
      }

      pW = &brain_ConstP.pooled13[0];
      pI = &brain_ConstP.pooled16[0];
      for (col = 0; col < 160; col++) {
        real32_T *inB = intBuf + col*480;
        real32_T *lineBuf = &Resize1_LineBuffer[0];
        memcpy(lineBuf, inB, 480*sizeof(real32_T));
        for (row = 0; row < 120; row++) {
          real32_T sum = 0.0F;
          int_T ictr = row;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += lineBuf[offset] * pW[ictr];
            ictr += 120;
          }

          out[ctr++] = sum;
        }
      }
    }

    /* Video Processing Blockset 2D Resize (svipresize) - '<S2>/Resize2' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o3;
      real32_T *out = brain_B.Resize2;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled17[0];
      const real32_T *pW = &brain_ConstP.pooled14[0];
      int_T row, col, k, ctr = 0;
      for (row = 0; row < 480; row++) {
        int_T indx = row;
        for (col = 0; col < 160; col++) {
          int_T ictr = col;
          real32_T sum = 0.0F;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += in[row+offset*480] * pW[ictr];
            ictr += 160;
          }

          intBuf[indx] = sum;
          indx += 480;
        }
      }

      pW = &brain_ConstP.pooled13[0];
      pI = &brain_ConstP.pooled16[0];
      for (col = 0; col < 160; col++) {
        real32_T *inB = intBuf + col*480;
        real32_T *lineBuf = &Resize2_LineBuffer[0];
        memcpy(lineBuf, inB, 480*sizeof(real32_T));
        for (row = 0; row < 120; row++) {
          real32_T sum = 0.0F;
          int_T ictr = row;
          for (k = 0; k < 8; k++) {
            int_T offset = pI[ictr];
            sum += lineBuf[offset] * pW[ictr];
            ictr += 120;
          }

          out[ctr++] = sum;
        }
      }
    }

    /* Stateflow: '<Root>/Chart' */
    brain_Chart();

    /* Outport: '<Root>/CameraPosition' */
    brain_Y.CameraPosition = brain_B.CameraPosition;

    /* Outport: '<Root>/BuoyCentroidX' */
    brain_Y.BuoyCentroidX = brain_B.BuoyCentroidX;

    /* Outport: '<Root>/BuoyCentroidY' */
    brain_Y.BuoyCentroidY = brain_B.BuoyCentroidY;

    /* Outport: '<Root>/Thrusters' */
    brain_Y.Thrusters[0] = brain_B.Right;
    brain_Y.Thrusters[1] = brain_B.Left;
    brain_Y.Thrusters[2] = brain_B.Strafe;
    brain_Y.Thrusters[3] = brain_B.Vertical;

    /* Outport: '<Root>/State' */
    brain_Y.State = brain_B.State;

    /* Outport: '<Root>/DesiredDepth' */
    brain_Y.DesiredDepth = brain_B.DesiredDepth;

    /* Outport: '<Root>/DesiredHeading' */
    brain_Y.DesiredHeading = brain_B.DesiredHeading;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  brain_M->Timing.clockTick0++;
}

/* Model initialize function */
extern "C"
  void brain_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)brain_M,0,
                sizeof(RT_MODEL_brain));

  /* block I/O */
  (void) memset(((void *) &brain_B),0,
                sizeof(BlockIO_brain));

  {
    brain_B.HoughTransform_o2[0] = -1.5707963267948966E+00;
    brain_B.HoughTransform_o2[1] = -1.5533430342749532E+00;
    brain_B.HoughTransform_o2[2] = -1.5358897417550099E+00;
    brain_B.HoughTransform_o2[3] = -1.5184364492350666E+00;
    brain_B.HoughTransform_o2[4] = -1.5009831567151235E+00;
    brain_B.HoughTransform_o2[5] = -1.4835298641951802E+00;
    brain_B.HoughTransform_o2[6] = -1.4660765716752369E+00;
    brain_B.HoughTransform_o2[7] = -1.4486232791552935E+00;
    brain_B.HoughTransform_o2[8] = -1.4311699866353502E+00;
    brain_B.HoughTransform_o2[9] = -1.4137166941154069E+00;
    brain_B.HoughTransform_o2[10] = -1.3962634015954636E+00;
    brain_B.HoughTransform_o2[11] = -1.3788101090755203E+00;
    brain_B.HoughTransform_o2[12] = -1.3613568165555769E+00;
    brain_B.HoughTransform_o2[13] = -1.3439035240356338E+00;
    brain_B.HoughTransform_o2[14] = -1.3264502315156905E+00;
    brain_B.HoughTransform_o2[15] = -1.3089969389957472E+00;
    brain_B.HoughTransform_o2[16] = -1.2915436464758039E+00;
    brain_B.HoughTransform_o2[17] = -1.2740903539558606E+00;
    brain_B.HoughTransform_o2[18] = -1.2566370614359172E+00;
    brain_B.HoughTransform_o2[19] = -1.2391837689159739E+00;
    brain_B.HoughTransform_o2[20] = -1.2217304763960306E+00;
    brain_B.HoughTransform_o2[21] = -1.2042771838760873E+00;
    brain_B.HoughTransform_o2[22] = -1.1868238913561442E+00;
    brain_B.HoughTransform_o2[23] = -1.1693705988362009E+00;
    brain_B.HoughTransform_o2[24] = -1.1519173063162575E+00;
    brain_B.HoughTransform_o2[25] = -1.1344640137963142E+00;
    brain_B.HoughTransform_o2[26] = -1.1170107212763709E+00;
    brain_B.HoughTransform_o2[27] = -1.0995574287564276E+00;
    brain_B.HoughTransform_o2[28] = -1.0821041362364843E+00;
    brain_B.HoughTransform_o2[29] = -1.0646508437165410E+00;
    brain_B.HoughTransform_o2[30] = -1.0471975511965976E+00;
    brain_B.HoughTransform_o2[31] = -1.0297442586766545E+00;
    brain_B.HoughTransform_o2[32] = -1.0122909661567112E+00;
    brain_B.HoughTransform_o2[33] = -9.9483767363676789E-01;
    brain_B.HoughTransform_o2[34] = -9.7738438111682457E-01;
    brain_B.HoughTransform_o2[35] = -9.5993108859688125E-01;
    brain_B.HoughTransform_o2[36] = -9.4247779607693793E-01;
    brain_B.HoughTransform_o2[37] = -9.2502450355699462E-01;
    brain_B.HoughTransform_o2[38] = -9.0757121103705141E-01;
    brain_B.HoughTransform_o2[39] = -8.9011791851710809E-01;
    brain_B.HoughTransform_o2[40] = -8.7266462599716477E-01;
    brain_B.HoughTransform_o2[41] = -8.5521133347722145E-01;
    brain_B.HoughTransform_o2[42] = -8.3775804095727824E-01;
    brain_B.HoughTransform_o2[43] = -8.2030474843733492E-01;
    brain_B.HoughTransform_o2[44] = -8.0285145591739160E-01;
    brain_B.HoughTransform_o2[45] = -7.8539816339744828E-01;
    brain_B.HoughTransform_o2[46] = -7.6794487087750496E-01;
    brain_B.HoughTransform_o2[47] = -7.5049157835756175E-01;
    brain_B.HoughTransform_o2[48] = -7.3303828583761843E-01;
    brain_B.HoughTransform_o2[49] = -7.1558499331767511E-01;
    brain_B.HoughTransform_o2[50] = -6.9813170079773179E-01;
    brain_B.HoughTransform_o2[51] = -6.8067840827778847E-01;
    brain_B.HoughTransform_o2[52] = -6.6322511575784526E-01;
    brain_B.HoughTransform_o2[53] = -6.4577182323790194E-01;
    brain_B.HoughTransform_o2[54] = -6.2831853071795862E-01;
    brain_B.HoughTransform_o2[55] = -6.1086523819801530E-01;
    brain_B.HoughTransform_o2[56] = -5.9341194567807209E-01;
    brain_B.HoughTransform_o2[57] = -5.7595865315812877E-01;
    brain_B.HoughTransform_o2[58] = -5.5850536063818546E-01;
    brain_B.HoughTransform_o2[59] = -5.4105206811824214E-01;
    brain_B.HoughTransform_o2[60] = -5.2359877559829882E-01;
    brain_B.HoughTransform_o2[61] = -5.0614548307835561E-01;
    brain_B.HoughTransform_o2[62] = -4.8869219055841229E-01;
    brain_B.HoughTransform_o2[63] = -4.7123889803846897E-01;
    brain_B.HoughTransform_o2[64] = -4.5378560551852570E-01;
    brain_B.HoughTransform_o2[65] = -4.3633231299858238E-01;
    brain_B.HoughTransform_o2[66] = -4.1887902047863912E-01;
    brain_B.HoughTransform_o2[67] = -4.0142572795869580E-01;
    brain_B.HoughTransform_o2[68] = -3.8397243543875248E-01;
    brain_B.HoughTransform_o2[69] = -3.6651914291880922E-01;
    brain_B.HoughTransform_o2[70] = -3.4906585039886590E-01;
    brain_B.HoughTransform_o2[71] = -3.3161255787892263E-01;
    brain_B.HoughTransform_o2[72] = -3.1415926535897931E-01;
    brain_B.HoughTransform_o2[73] = -2.9670597283903605E-01;
    brain_B.HoughTransform_o2[74] = -2.7925268031909273E-01;
    brain_B.HoughTransform_o2[75] = -2.6179938779914941E-01;
    brain_B.HoughTransform_o2[76] = -2.4434609527920614E-01;
    brain_B.HoughTransform_o2[77] = -2.2689280275926285E-01;
    brain_B.HoughTransform_o2[78] = -2.0943951023931956E-01;
    brain_B.HoughTransform_o2[79] = -1.9198621771937624E-01;
    brain_B.HoughTransform_o2[80] = -1.7453292519943295E-01;
    brain_B.HoughTransform_o2[81] = -1.5707963267948966E-01;
    brain_B.HoughTransform_o2[82] = -1.3962634015954636E-01;
    brain_B.HoughTransform_o2[83] = -1.2217304763960307E-01;
    brain_B.HoughTransform_o2[84] = -1.0471975511965978E-01;
    brain_B.HoughTransform_o2[85] = -8.7266462599716474E-02;
    brain_B.HoughTransform_o2[86] = -6.9813170079773182E-02;
    brain_B.HoughTransform_o2[87] = -5.2359877559829890E-02;
    brain_B.HoughTransform_o2[88] = -3.4906585039886591E-02;
    brain_B.HoughTransform_o2[89] = -1.7453292519943295E-02;
    brain_B.HoughTransform_o2[90] = 0.0;
    brain_B.HoughTransform_o2[91] = 1.7453292519943295E-02;
    brain_B.HoughTransform_o2[92] = 3.4906585039886591E-02;
    brain_B.HoughTransform_o2[93] = 5.2359877559829890E-02;
    brain_B.HoughTransform_o2[94] = 6.9813170079773182E-02;
    brain_B.HoughTransform_o2[95] = 8.7266462599716474E-02;
    brain_B.HoughTransform_o2[96] = 1.0471975511965978E-01;
    brain_B.HoughTransform_o2[97] = 1.2217304763960307E-01;
    brain_B.HoughTransform_o2[98] = 1.3962634015954636E-01;
    brain_B.HoughTransform_o2[99] = 1.5707963267948966E-01;
    brain_B.HoughTransform_o2[100] = 1.7453292519943295E-01;
    brain_B.HoughTransform_o2[101] = 1.9198621771937624E-01;
    brain_B.HoughTransform_o2[102] = 2.0943951023931956E-01;
    brain_B.HoughTransform_o2[103] = 2.2689280275926285E-01;
    brain_B.HoughTransform_o2[104] = 2.4434609527920614E-01;
    brain_B.HoughTransform_o2[105] = 2.6179938779914941E-01;
    brain_B.HoughTransform_o2[106] = 2.7925268031909273E-01;
    brain_B.HoughTransform_o2[107] = 2.9670597283903605E-01;
    brain_B.HoughTransform_o2[108] = 3.1415926535897931E-01;
    brain_B.HoughTransform_o2[109] = 3.3161255787892263E-01;
    brain_B.HoughTransform_o2[110] = 3.4906585039886590E-01;
    brain_B.HoughTransform_o2[111] = 3.6651914291880922E-01;
    brain_B.HoughTransform_o2[112] = 3.8397243543875248E-01;
    brain_B.HoughTransform_o2[113] = 4.0142572795869580E-01;
    brain_B.HoughTransform_o2[114] = 4.1887902047863912E-01;
    brain_B.HoughTransform_o2[115] = 4.3633231299858238E-01;
    brain_B.HoughTransform_o2[116] = 4.5378560551852570E-01;
    brain_B.HoughTransform_o2[117] = 4.7123889803846897E-01;
    brain_B.HoughTransform_o2[118] = 4.8869219055841229E-01;
    brain_B.HoughTransform_o2[119] = 5.0614548307835561E-01;
    brain_B.HoughTransform_o2[120] = 5.2359877559829882E-01;
    brain_B.HoughTransform_o2[121] = 5.4105206811824214E-01;
    brain_B.HoughTransform_o2[122] = 5.5850536063818546E-01;
    brain_B.HoughTransform_o2[123] = 5.7595865315812877E-01;
    brain_B.HoughTransform_o2[124] = 5.9341194567807209E-01;
    brain_B.HoughTransform_o2[125] = 6.1086523819801530E-01;
    brain_B.HoughTransform_o2[126] = 6.2831853071795862E-01;
    brain_B.HoughTransform_o2[127] = 6.4577182323790194E-01;
    brain_B.HoughTransform_o2[128] = 6.6322511575784526E-01;
    brain_B.HoughTransform_o2[129] = 6.8067840827778847E-01;
    brain_B.HoughTransform_o2[130] = 6.9813170079773179E-01;
    brain_B.HoughTransform_o2[131] = 7.1558499331767511E-01;
    brain_B.HoughTransform_o2[132] = 7.3303828583761843E-01;
    brain_B.HoughTransform_o2[133] = 7.5049157835756175E-01;
    brain_B.HoughTransform_o2[134] = 7.6794487087750496E-01;
    brain_B.HoughTransform_o2[135] = 7.8539816339744828E-01;
    brain_B.HoughTransform_o2[136] = 8.0285145591739160E-01;
    brain_B.HoughTransform_o2[137] = 8.2030474843733492E-01;
    brain_B.HoughTransform_o2[138] = 8.3775804095727824E-01;
    brain_B.HoughTransform_o2[139] = 8.5521133347722145E-01;
    brain_B.HoughTransform_o2[140] = 8.7266462599716477E-01;
    brain_B.HoughTransform_o2[141] = 8.9011791851710809E-01;
    brain_B.HoughTransform_o2[142] = 9.0757121103705141E-01;
    brain_B.HoughTransform_o2[143] = 9.2502450355699462E-01;
    brain_B.HoughTransform_o2[144] = 9.4247779607693793E-01;
    brain_B.HoughTransform_o2[145] = 9.5993108859688125E-01;
    brain_B.HoughTransform_o2[146] = 9.7738438111682457E-01;
    brain_B.HoughTransform_o2[147] = 9.9483767363676789E-01;
    brain_B.HoughTransform_o2[148] = 1.0122909661567112E+00;
    brain_B.HoughTransform_o2[149] = 1.0297442586766545E+00;
    brain_B.HoughTransform_o2[150] = 1.0471975511965976E+00;
    brain_B.HoughTransform_o2[151] = 1.0646508437165410E+00;
    brain_B.HoughTransform_o2[152] = 1.0821041362364843E+00;
    brain_B.HoughTransform_o2[153] = 1.0995574287564276E+00;
    brain_B.HoughTransform_o2[154] = 1.1170107212763709E+00;
    brain_B.HoughTransform_o2[155] = 1.1344640137963142E+00;
    brain_B.HoughTransform_o2[156] = 1.1519173063162575E+00;
    brain_B.HoughTransform_o2[157] = 1.1693705988362009E+00;
    brain_B.HoughTransform_o2[158] = 1.1868238913561442E+00;
    brain_B.HoughTransform_o2[159] = 1.2042771838760873E+00;
    brain_B.HoughTransform_o2[160] = 1.2217304763960306E+00;
    brain_B.HoughTransform_o2[161] = 1.2391837689159739E+00;
    brain_B.HoughTransform_o2[162] = 1.2566370614359172E+00;
    brain_B.HoughTransform_o2[163] = 1.2740903539558606E+00;
    brain_B.HoughTransform_o2[164] = 1.2915436464758039E+00;
    brain_B.HoughTransform_o2[165] = 1.3089969389957472E+00;
    brain_B.HoughTransform_o2[166] = 1.3264502315156905E+00;
    brain_B.HoughTransform_o2[167] = 1.3439035240356338E+00;
    brain_B.HoughTransform_o2[168] = 1.3613568165555769E+00;
    brain_B.HoughTransform_o2[169] = 1.3788101090755203E+00;
    brain_B.HoughTransform_o2[170] = 1.3962634015954636E+00;
    brain_B.HoughTransform_o2[171] = 1.4137166941154069E+00;
    brain_B.HoughTransform_o2[172] = 1.4311699866353502E+00;
    brain_B.HoughTransform_o2[173] = 1.4486232791552935E+00;
    brain_B.HoughTransform_o2[174] = 1.4660765716752369E+00;
    brain_B.HoughTransform_o2[175] = 1.4835298641951802E+00;
    brain_B.HoughTransform_o2[176] = 1.5009831567151235E+00;
    brain_B.HoughTransform_o2[177] = 1.5184364492350666E+00;
    brain_B.HoughTransform_o2[178] = 1.5358897417550099E+00;
    brain_B.HoughTransform_o2[179] = 1.5533430342749532E+00;
    brain_B.HoughTransform_o3[0] = -199.0;
    brain_B.HoughTransform_o3[1] = -198.0;
    brain_B.HoughTransform_o3[2] = -197.0;
    brain_B.HoughTransform_o3[3] = -196.0;
    brain_B.HoughTransform_o3[4] = -195.0;
    brain_B.HoughTransform_o3[5] = -194.0;
    brain_B.HoughTransform_o3[6] = -193.0;
    brain_B.HoughTransform_o3[7] = -192.0;
    brain_B.HoughTransform_o3[8] = -191.0;
    brain_B.HoughTransform_o3[9] = -190.0;
    brain_B.HoughTransform_o3[10] = -189.0;
    brain_B.HoughTransform_o3[11] = -188.0;
    brain_B.HoughTransform_o3[12] = -187.0;
    brain_B.HoughTransform_o3[13] = -186.0;
    brain_B.HoughTransform_o3[14] = -185.0;
    brain_B.HoughTransform_o3[15] = -184.0;
    brain_B.HoughTransform_o3[16] = -183.0;
    brain_B.HoughTransform_o3[17] = -182.0;
    brain_B.HoughTransform_o3[18] = -181.0;
    brain_B.HoughTransform_o3[19] = -180.0;
    brain_B.HoughTransform_o3[20] = -179.0;
    brain_B.HoughTransform_o3[21] = -178.0;
    brain_B.HoughTransform_o3[22] = -177.0;
    brain_B.HoughTransform_o3[23] = -176.0;
    brain_B.HoughTransform_o3[24] = -175.0;
    brain_B.HoughTransform_o3[25] = -174.0;
    brain_B.HoughTransform_o3[26] = -173.0;
    brain_B.HoughTransform_o3[27] = -172.0;
    brain_B.HoughTransform_o3[28] = -171.0;
    brain_B.HoughTransform_o3[29] = -170.0;
    brain_B.HoughTransform_o3[30] = -169.0;
    brain_B.HoughTransform_o3[31] = -168.0;
    brain_B.HoughTransform_o3[32] = -167.0;
    brain_B.HoughTransform_o3[33] = -166.0;
    brain_B.HoughTransform_o3[34] = -165.0;
    brain_B.HoughTransform_o3[35] = -164.0;
    brain_B.HoughTransform_o3[36] = -163.0;
    brain_B.HoughTransform_o3[37] = -162.0;
    brain_B.HoughTransform_o3[38] = -161.0;
    brain_B.HoughTransform_o3[39] = -160.0;
    brain_B.HoughTransform_o3[40] = -159.0;
    brain_B.HoughTransform_o3[41] = -158.0;
    brain_B.HoughTransform_o3[42] = -157.0;
    brain_B.HoughTransform_o3[43] = -156.0;
    brain_B.HoughTransform_o3[44] = -155.0;
    brain_B.HoughTransform_o3[45] = -154.0;
    brain_B.HoughTransform_o3[46] = -153.0;
    brain_B.HoughTransform_o3[47] = -152.0;
    brain_B.HoughTransform_o3[48] = -151.0;
    brain_B.HoughTransform_o3[49] = -150.0;
    brain_B.HoughTransform_o3[50] = -149.0;
    brain_B.HoughTransform_o3[51] = -148.0;
    brain_B.HoughTransform_o3[52] = -147.0;
    brain_B.HoughTransform_o3[53] = -146.0;
    brain_B.HoughTransform_o3[54] = -145.0;
    brain_B.HoughTransform_o3[55] = -144.0;
    brain_B.HoughTransform_o3[56] = -143.0;
    brain_B.HoughTransform_o3[57] = -142.0;
    brain_B.HoughTransform_o3[58] = -141.0;
    brain_B.HoughTransform_o3[59] = -140.0;
    brain_B.HoughTransform_o3[60] = -139.0;
    brain_B.HoughTransform_o3[61] = -138.0;
    brain_B.HoughTransform_o3[62] = -137.0;
    brain_B.HoughTransform_o3[63] = -136.0;
    brain_B.HoughTransform_o3[64] = -135.0;
    brain_B.HoughTransform_o3[65] = -134.0;
    brain_B.HoughTransform_o3[66] = -133.0;
    brain_B.HoughTransform_o3[67] = -132.0;
    brain_B.HoughTransform_o3[68] = -131.0;
    brain_B.HoughTransform_o3[69] = -130.0;
    brain_B.HoughTransform_o3[70] = -129.0;
    brain_B.HoughTransform_o3[71] = -128.0;
    brain_B.HoughTransform_o3[72] = -127.0;
    brain_B.HoughTransform_o3[73] = -126.0;
    brain_B.HoughTransform_o3[74] = -125.0;
    brain_B.HoughTransform_o3[75] = -124.0;
    brain_B.HoughTransform_o3[76] = -123.0;
    brain_B.HoughTransform_o3[77] = -122.0;
    brain_B.HoughTransform_o3[78] = -121.0;
    brain_B.HoughTransform_o3[79] = -120.0;
    brain_B.HoughTransform_o3[80] = -119.0;
    brain_B.HoughTransform_o3[81] = -118.0;
    brain_B.HoughTransform_o3[82] = -117.0;
    brain_B.HoughTransform_o3[83] = -116.0;
    brain_B.HoughTransform_o3[84] = -115.0;
    brain_B.HoughTransform_o3[85] = -114.0;
    brain_B.HoughTransform_o3[86] = -113.0;
    brain_B.HoughTransform_o3[87] = -112.0;
    brain_B.HoughTransform_o3[88] = -111.0;
    brain_B.HoughTransform_o3[89] = -110.0;
    brain_B.HoughTransform_o3[90] = -109.0;
    brain_B.HoughTransform_o3[91] = -108.0;
    brain_B.HoughTransform_o3[92] = -107.0;
    brain_B.HoughTransform_o3[93] = -106.0;
    brain_B.HoughTransform_o3[94] = -105.0;
    brain_B.HoughTransform_o3[95] = -104.0;
    brain_B.HoughTransform_o3[96] = -103.0;
    brain_B.HoughTransform_o3[97] = -102.0;
    brain_B.HoughTransform_o3[98] = -101.0;
    brain_B.HoughTransform_o3[99] = -100.0;
    brain_B.HoughTransform_o3[100] = -99.0;
    brain_B.HoughTransform_o3[101] = -98.0;
    brain_B.HoughTransform_o3[102] = -97.0;
    brain_B.HoughTransform_o3[103] = -96.0;
    brain_B.HoughTransform_o3[104] = -95.0;
    brain_B.HoughTransform_o3[105] = -94.0;
    brain_B.HoughTransform_o3[106] = -93.0;
    brain_B.HoughTransform_o3[107] = -92.0;
    brain_B.HoughTransform_o3[108] = -91.0;
    brain_B.HoughTransform_o3[109] = -90.0;
    brain_B.HoughTransform_o3[110] = -89.0;
    brain_B.HoughTransform_o3[111] = -88.0;
    brain_B.HoughTransform_o3[112] = -87.0;
    brain_B.HoughTransform_o3[113] = -86.0;
    brain_B.HoughTransform_o3[114] = -85.0;
    brain_B.HoughTransform_o3[115] = -84.0;
    brain_B.HoughTransform_o3[116] = -83.0;
    brain_B.HoughTransform_o3[117] = -82.0;
    brain_B.HoughTransform_o3[118] = -81.0;
    brain_B.HoughTransform_o3[119] = -80.0;
    brain_B.HoughTransform_o3[120] = -79.0;
    brain_B.HoughTransform_o3[121] = -78.0;
    brain_B.HoughTransform_o3[122] = -77.0;
    brain_B.HoughTransform_o3[123] = -76.0;
    brain_B.HoughTransform_o3[124] = -75.0;
    brain_B.HoughTransform_o3[125] = -74.0;
    brain_B.HoughTransform_o3[126] = -73.0;
    brain_B.HoughTransform_o3[127] = -72.0;
    brain_B.HoughTransform_o3[128] = -71.0;
    brain_B.HoughTransform_o3[129] = -70.0;
    brain_B.HoughTransform_o3[130] = -69.0;
    brain_B.HoughTransform_o3[131] = -68.0;
    brain_B.HoughTransform_o3[132] = -67.0;
    brain_B.HoughTransform_o3[133] = -66.0;
    brain_B.HoughTransform_o3[134] = -65.0;
    brain_B.HoughTransform_o3[135] = -64.0;
    brain_B.HoughTransform_o3[136] = -63.0;
    brain_B.HoughTransform_o3[137] = -62.0;
    brain_B.HoughTransform_o3[138] = -61.0;
    brain_B.HoughTransform_o3[139] = -60.0;
    brain_B.HoughTransform_o3[140] = -59.0;
    brain_B.HoughTransform_o3[141] = -58.0;
    brain_B.HoughTransform_o3[142] = -57.0;
    brain_B.HoughTransform_o3[143] = -56.0;
    brain_B.HoughTransform_o3[144] = -55.0;
    brain_B.HoughTransform_o3[145] = -54.0;
    brain_B.HoughTransform_o3[146] = -53.0;
    brain_B.HoughTransform_o3[147] = -52.0;
    brain_B.HoughTransform_o3[148] = -51.0;
    brain_B.HoughTransform_o3[149] = -50.0;
    brain_B.HoughTransform_o3[150] = -49.0;
    brain_B.HoughTransform_o3[151] = -48.0;
    brain_B.HoughTransform_o3[152] = -47.0;
    brain_B.HoughTransform_o3[153] = -46.0;
    brain_B.HoughTransform_o3[154] = -45.0;
    brain_B.HoughTransform_o3[155] = -44.0;
    brain_B.HoughTransform_o3[156] = -43.0;
    brain_B.HoughTransform_o3[157] = -42.0;
    brain_B.HoughTransform_o3[158] = -41.0;
    brain_B.HoughTransform_o3[159] = -40.0;
    brain_B.HoughTransform_o3[160] = -39.0;
    brain_B.HoughTransform_o3[161] = -38.0;
    brain_B.HoughTransform_o3[162] = -37.0;
    brain_B.HoughTransform_o3[163] = -36.0;
    brain_B.HoughTransform_o3[164] = -35.0;
    brain_B.HoughTransform_o3[165] = -34.0;
    brain_B.HoughTransform_o3[166] = -33.0;
    brain_B.HoughTransform_o3[167] = -32.0;
    brain_B.HoughTransform_o3[168] = -31.0;
    brain_B.HoughTransform_o3[169] = -30.0;
    brain_B.HoughTransform_o3[170] = -29.0;
    brain_B.HoughTransform_o3[171] = -28.0;
    brain_B.HoughTransform_o3[172] = -27.0;
    brain_B.HoughTransform_o3[173] = -26.0;
    brain_B.HoughTransform_o3[174] = -25.0;
    brain_B.HoughTransform_o3[175] = -24.0;
    brain_B.HoughTransform_o3[176] = -23.0;
    brain_B.HoughTransform_o3[177] = -22.0;
    brain_B.HoughTransform_o3[178] = -21.0;
    brain_B.HoughTransform_o3[179] = -20.0;
    brain_B.HoughTransform_o3[180] = -19.0;
    brain_B.HoughTransform_o3[181] = -18.0;
    brain_B.HoughTransform_o3[182] = -17.0;
    brain_B.HoughTransform_o3[183] = -16.0;
    brain_B.HoughTransform_o3[184] = -15.0;
    brain_B.HoughTransform_o3[185] = -14.0;
    brain_B.HoughTransform_o3[186] = -13.0;
    brain_B.HoughTransform_o3[187] = -12.0;
    brain_B.HoughTransform_o3[188] = -11.0;
    brain_B.HoughTransform_o3[189] = -10.0;
    brain_B.HoughTransform_o3[190] = -9.0;
    brain_B.HoughTransform_o3[191] = -8.0;
    brain_B.HoughTransform_o3[192] = -7.0;
    brain_B.HoughTransform_o3[193] = -6.0;
    brain_B.HoughTransform_o3[194] = -5.0;
    brain_B.HoughTransform_o3[195] = -4.0;
    brain_B.HoughTransform_o3[196] = -3.0;
    brain_B.HoughTransform_o3[197] = -2.0;
    brain_B.HoughTransform_o3[198] = -1.0;
    brain_B.HoughTransform_o3[199] = 0.0;
    brain_B.HoughTransform_o3[200] = 1.0;
    brain_B.HoughTransform_o3[201] = 2.0;
    brain_B.HoughTransform_o3[202] = 3.0;
    brain_B.HoughTransform_o3[203] = 4.0;
    brain_B.HoughTransform_o3[204] = 5.0;
    brain_B.HoughTransform_o3[205] = 6.0;
    brain_B.HoughTransform_o3[206] = 7.0;
    brain_B.HoughTransform_o3[207] = 8.0;
    brain_B.HoughTransform_o3[208] = 9.0;
    brain_B.HoughTransform_o3[209] = 10.0;
    brain_B.HoughTransform_o3[210] = 11.0;
    brain_B.HoughTransform_o3[211] = 12.0;
    brain_B.HoughTransform_o3[212] = 13.0;
    brain_B.HoughTransform_o3[213] = 14.0;
    brain_B.HoughTransform_o3[214] = 15.0;
    brain_B.HoughTransform_o3[215] = 16.0;
    brain_B.HoughTransform_o3[216] = 17.0;
    brain_B.HoughTransform_o3[217] = 18.0;
    brain_B.HoughTransform_o3[218] = 19.0;
    brain_B.HoughTransform_o3[219] = 20.0;
    brain_B.HoughTransform_o3[220] = 21.0;
    brain_B.HoughTransform_o3[221] = 22.0;
    brain_B.HoughTransform_o3[222] = 23.0;
    brain_B.HoughTransform_o3[223] = 24.0;
    brain_B.HoughTransform_o3[224] = 25.0;
    brain_B.HoughTransform_o3[225] = 26.0;
    brain_B.HoughTransform_o3[226] = 27.0;
    brain_B.HoughTransform_o3[227] = 28.0;
    brain_B.HoughTransform_o3[228] = 29.0;
    brain_B.HoughTransform_o3[229] = 30.0;
    brain_B.HoughTransform_o3[230] = 31.0;
    brain_B.HoughTransform_o3[231] = 32.0;
    brain_B.HoughTransform_o3[232] = 33.0;
    brain_B.HoughTransform_o3[233] = 34.0;
    brain_B.HoughTransform_o3[234] = 35.0;
    brain_B.HoughTransform_o3[235] = 36.0;
    brain_B.HoughTransform_o3[236] = 37.0;
    brain_B.HoughTransform_o3[237] = 38.0;
    brain_B.HoughTransform_o3[238] = 39.0;
    brain_B.HoughTransform_o3[239] = 40.0;
    brain_B.HoughTransform_o3[240] = 41.0;
    brain_B.HoughTransform_o3[241] = 42.0;
    brain_B.HoughTransform_o3[242] = 43.0;
    brain_B.HoughTransform_o3[243] = 44.0;
    brain_B.HoughTransform_o3[244] = 45.0;
    brain_B.HoughTransform_o3[245] = 46.0;
    brain_B.HoughTransform_o3[246] = 47.0;
    brain_B.HoughTransform_o3[247] = 48.0;
    brain_B.HoughTransform_o3[248] = 49.0;
    brain_B.HoughTransform_o3[249] = 50.0;
    brain_B.HoughTransform_o3[250] = 51.0;
    brain_B.HoughTransform_o3[251] = 52.0;
    brain_B.HoughTransform_o3[252] = 53.0;
    brain_B.HoughTransform_o3[253] = 54.0;
    brain_B.HoughTransform_o3[254] = 55.0;
    brain_B.HoughTransform_o3[255] = 56.0;
    brain_B.HoughTransform_o3[256] = 57.0;
    brain_B.HoughTransform_o3[257] = 58.0;
    brain_B.HoughTransform_o3[258] = 59.0;
    brain_B.HoughTransform_o3[259] = 60.0;
    brain_B.HoughTransform_o3[260] = 61.0;
    brain_B.HoughTransform_o3[261] = 62.0;
    brain_B.HoughTransform_o3[262] = 63.0;
    brain_B.HoughTransform_o3[263] = 64.0;
    brain_B.HoughTransform_o3[264] = 65.0;
    brain_B.HoughTransform_o3[265] = 66.0;
    brain_B.HoughTransform_o3[266] = 67.0;
    brain_B.HoughTransform_o3[267] = 68.0;
    brain_B.HoughTransform_o3[268] = 69.0;
    brain_B.HoughTransform_o3[269] = 70.0;
    brain_B.HoughTransform_o3[270] = 71.0;
    brain_B.HoughTransform_o3[271] = 72.0;
    brain_B.HoughTransform_o3[272] = 73.0;
    brain_B.HoughTransform_o3[273] = 74.0;
    brain_B.HoughTransform_o3[274] = 75.0;
    brain_B.HoughTransform_o3[275] = 76.0;
    brain_B.HoughTransform_o3[276] = 77.0;
    brain_B.HoughTransform_o3[277] = 78.0;
    brain_B.HoughTransform_o3[278] = 79.0;
    brain_B.HoughTransform_o3[279] = 80.0;
    brain_B.HoughTransform_o3[280] = 81.0;
    brain_B.HoughTransform_o3[281] = 82.0;
    brain_B.HoughTransform_o3[282] = 83.0;
    brain_B.HoughTransform_o3[283] = 84.0;
    brain_B.HoughTransform_o3[284] = 85.0;
    brain_B.HoughTransform_o3[285] = 86.0;
    brain_B.HoughTransform_o3[286] = 87.0;
    brain_B.HoughTransform_o3[287] = 88.0;
    brain_B.HoughTransform_o3[288] = 89.0;
    brain_B.HoughTransform_o3[289] = 90.0;
    brain_B.HoughTransform_o3[290] = 91.0;
    brain_B.HoughTransform_o3[291] = 92.0;
    brain_B.HoughTransform_o3[292] = 93.0;
    brain_B.HoughTransform_o3[293] = 94.0;
    brain_B.HoughTransform_o3[294] = 95.0;
    brain_B.HoughTransform_o3[295] = 96.0;
    brain_B.HoughTransform_o3[296] = 97.0;
    brain_B.HoughTransform_o3[297] = 98.0;
    brain_B.HoughTransform_o3[298] = 99.0;
    brain_B.HoughTransform_o3[299] = 100.0;
    brain_B.HoughTransform_o3[300] = 101.0;
    brain_B.HoughTransform_o3[301] = 102.0;
    brain_B.HoughTransform_o3[302] = 103.0;
    brain_B.HoughTransform_o3[303] = 104.0;
    brain_B.HoughTransform_o3[304] = 105.0;
    brain_B.HoughTransform_o3[305] = 106.0;
    brain_B.HoughTransform_o3[306] = 107.0;
    brain_B.HoughTransform_o3[307] = 108.0;
    brain_B.HoughTransform_o3[308] = 109.0;
    brain_B.HoughTransform_o3[309] = 110.0;
    brain_B.HoughTransform_o3[310] = 111.0;
    brain_B.HoughTransform_o3[311] = 112.0;
    brain_B.HoughTransform_o3[312] = 113.0;
    brain_B.HoughTransform_o3[313] = 114.0;
    brain_B.HoughTransform_o3[314] = 115.0;
    brain_B.HoughTransform_o3[315] = 116.0;
    brain_B.HoughTransform_o3[316] = 117.0;
    brain_B.HoughTransform_o3[317] = 118.0;
    brain_B.HoughTransform_o3[318] = 119.0;
    brain_B.HoughTransform_o3[319] = 120.0;
    brain_B.HoughTransform_o3[320] = 121.0;
    brain_B.HoughTransform_o3[321] = 122.0;
    brain_B.HoughTransform_o3[322] = 123.0;
    brain_B.HoughTransform_o3[323] = 124.0;
    brain_B.HoughTransform_o3[324] = 125.0;
    brain_B.HoughTransform_o3[325] = 126.0;
    brain_B.HoughTransform_o3[326] = 127.0;
    brain_B.HoughTransform_o3[327] = 128.0;
    brain_B.HoughTransform_o3[328] = 129.0;
    brain_B.HoughTransform_o3[329] = 130.0;
    brain_B.HoughTransform_o3[330] = 131.0;
    brain_B.HoughTransform_o3[331] = 132.0;
    brain_B.HoughTransform_o3[332] = 133.0;
    brain_B.HoughTransform_o3[333] = 134.0;
    brain_B.HoughTransform_o3[334] = 135.0;
    brain_B.HoughTransform_o3[335] = 136.0;
    brain_B.HoughTransform_o3[336] = 137.0;
    brain_B.HoughTransform_o3[337] = 138.0;
    brain_B.HoughTransform_o3[338] = 139.0;
    brain_B.HoughTransform_o3[339] = 140.0;
    brain_B.HoughTransform_o3[340] = 141.0;
    brain_B.HoughTransform_o3[341] = 142.0;
    brain_B.HoughTransform_o3[342] = 143.0;
    brain_B.HoughTransform_o3[343] = 144.0;
    brain_B.HoughTransform_o3[344] = 145.0;
    brain_B.HoughTransform_o3[345] = 146.0;
    brain_B.HoughTransform_o3[346] = 147.0;
    brain_B.HoughTransform_o3[347] = 148.0;
    brain_B.HoughTransform_o3[348] = 149.0;
    brain_B.HoughTransform_o3[349] = 150.0;
    brain_B.HoughTransform_o3[350] = 151.0;
    brain_B.HoughTransform_o3[351] = 152.0;
    brain_B.HoughTransform_o3[352] = 153.0;
    brain_B.HoughTransform_o3[353] = 154.0;
    brain_B.HoughTransform_o3[354] = 155.0;
    brain_B.HoughTransform_o3[355] = 156.0;
    brain_B.HoughTransform_o3[356] = 157.0;
    brain_B.HoughTransform_o3[357] = 158.0;
    brain_B.HoughTransform_o3[358] = 159.0;
    brain_B.HoughTransform_o3[359] = 160.0;
    brain_B.HoughTransform_o3[360] = 161.0;
    brain_B.HoughTransform_o3[361] = 162.0;
    brain_B.HoughTransform_o3[362] = 163.0;
    brain_B.HoughTransform_o3[363] = 164.0;
    brain_B.HoughTransform_o3[364] = 165.0;
    brain_B.HoughTransform_o3[365] = 166.0;
    brain_B.HoughTransform_o3[366] = 167.0;
    brain_B.HoughTransform_o3[367] = 168.0;
    brain_B.HoughTransform_o3[368] = 169.0;
    brain_B.HoughTransform_o3[369] = 170.0;
    brain_B.HoughTransform_o3[370] = 171.0;
    brain_B.HoughTransform_o3[371] = 172.0;
    brain_B.HoughTransform_o3[372] = 173.0;
    brain_B.HoughTransform_o3[373] = 174.0;
    brain_B.HoughTransform_o3[374] = 175.0;
    brain_B.HoughTransform_o3[375] = 176.0;
    brain_B.HoughTransform_o3[376] = 177.0;
    brain_B.HoughTransform_o3[377] = 178.0;
    brain_B.HoughTransform_o3[378] = 179.0;
    brain_B.HoughTransform_o3[379] = 180.0;
    brain_B.HoughTransform_o3[380] = 181.0;
    brain_B.HoughTransform_o3[381] = 182.0;
    brain_B.HoughTransform_o3[382] = 183.0;
    brain_B.HoughTransform_o3[383] = 184.0;
    brain_B.HoughTransform_o3[384] = 185.0;
    brain_B.HoughTransform_o3[385] = 186.0;
    brain_B.HoughTransform_o3[386] = 187.0;
    brain_B.HoughTransform_o3[387] = 188.0;
    brain_B.HoughTransform_o3[388] = 189.0;
    brain_B.HoughTransform_o3[389] = 190.0;
    brain_B.HoughTransform_o3[390] = 191.0;
    brain_B.HoughTransform_o3[391] = 192.0;
    brain_B.HoughTransform_o3[392] = 193.0;
    brain_B.HoughTransform_o3[393] = 194.0;
    brain_B.HoughTransform_o3[394] = 195.0;
    brain_B.HoughTransform_o3[395] = 196.0;
    brain_B.HoughTransform_o3[396] = 197.0;
    brain_B.HoughTransform_o3[397] = 198.0;
    brain_B.HoughTransform_o3[398] = 199.0;
    brain_B.HoughTransform_o2_e[0] = -1.5707963267948966E+00;
    brain_B.HoughTransform_o2_e[1] = -1.5533430342749532E+00;
    brain_B.HoughTransform_o2_e[2] = -1.5358897417550099E+00;
    brain_B.HoughTransform_o2_e[3] = -1.5184364492350666E+00;
    brain_B.HoughTransform_o2_e[4] = -1.5009831567151235E+00;
    brain_B.HoughTransform_o2_e[5] = -1.4835298641951802E+00;
    brain_B.HoughTransform_o2_e[6] = -1.4660765716752369E+00;
    brain_B.HoughTransform_o2_e[7] = -1.4486232791552935E+00;
    brain_B.HoughTransform_o2_e[8] = -1.4311699866353502E+00;
    brain_B.HoughTransform_o2_e[9] = -1.4137166941154069E+00;
    brain_B.HoughTransform_o2_e[10] = -1.3962634015954636E+00;
    brain_B.HoughTransform_o2_e[11] = -1.3788101090755203E+00;
    brain_B.HoughTransform_o2_e[12] = -1.3613568165555769E+00;
    brain_B.HoughTransform_o2_e[13] = -1.3439035240356338E+00;
    brain_B.HoughTransform_o2_e[14] = -1.3264502315156905E+00;
    brain_B.HoughTransform_o2_e[15] = -1.3089969389957472E+00;
    brain_B.HoughTransform_o2_e[16] = -1.2915436464758039E+00;
    brain_B.HoughTransform_o2_e[17] = -1.2740903539558606E+00;
    brain_B.HoughTransform_o2_e[18] = -1.2566370614359172E+00;
    brain_B.HoughTransform_o2_e[19] = -1.2391837689159739E+00;
    brain_B.HoughTransform_o2_e[20] = -1.2217304763960306E+00;
    brain_B.HoughTransform_o2_e[21] = -1.2042771838760873E+00;
    brain_B.HoughTransform_o2_e[22] = -1.1868238913561442E+00;
    brain_B.HoughTransform_o2_e[23] = -1.1693705988362009E+00;
    brain_B.HoughTransform_o2_e[24] = -1.1519173063162575E+00;
    brain_B.HoughTransform_o2_e[25] = -1.1344640137963142E+00;
    brain_B.HoughTransform_o2_e[26] = -1.1170107212763709E+00;
    brain_B.HoughTransform_o2_e[27] = -1.0995574287564276E+00;
    brain_B.HoughTransform_o2_e[28] = -1.0821041362364843E+00;
    brain_B.HoughTransform_o2_e[29] = -1.0646508437165410E+00;
    brain_B.HoughTransform_o2_e[30] = -1.0471975511965976E+00;
    brain_B.HoughTransform_o2_e[31] = -1.0297442586766545E+00;
    brain_B.HoughTransform_o2_e[32] = -1.0122909661567112E+00;
    brain_B.HoughTransform_o2_e[33] = -9.9483767363676789E-01;
    brain_B.HoughTransform_o2_e[34] = -9.7738438111682457E-01;
    brain_B.HoughTransform_o2_e[35] = -9.5993108859688125E-01;
    brain_B.HoughTransform_o2_e[36] = -9.4247779607693793E-01;
    brain_B.HoughTransform_o2_e[37] = -9.2502450355699462E-01;
    brain_B.HoughTransform_o2_e[38] = -9.0757121103705141E-01;
    brain_B.HoughTransform_o2_e[39] = -8.9011791851710809E-01;
    brain_B.HoughTransform_o2_e[40] = -8.7266462599716477E-01;
    brain_B.HoughTransform_o2_e[41] = -8.5521133347722145E-01;
    brain_B.HoughTransform_o2_e[42] = -8.3775804095727824E-01;
    brain_B.HoughTransform_o2_e[43] = -8.2030474843733492E-01;
    brain_B.HoughTransform_o2_e[44] = -8.0285145591739160E-01;
    brain_B.HoughTransform_o2_e[45] = -7.8539816339744828E-01;
    brain_B.HoughTransform_o2_e[46] = -7.6794487087750496E-01;
    brain_B.HoughTransform_o2_e[47] = -7.5049157835756175E-01;
    brain_B.HoughTransform_o2_e[48] = -7.3303828583761843E-01;
    brain_B.HoughTransform_o2_e[49] = -7.1558499331767511E-01;
    brain_B.HoughTransform_o2_e[50] = -6.9813170079773179E-01;
    brain_B.HoughTransform_o2_e[51] = -6.8067840827778847E-01;
    brain_B.HoughTransform_o2_e[52] = -6.6322511575784526E-01;
    brain_B.HoughTransform_o2_e[53] = -6.4577182323790194E-01;
    brain_B.HoughTransform_o2_e[54] = -6.2831853071795862E-01;
    brain_B.HoughTransform_o2_e[55] = -6.1086523819801530E-01;
    brain_B.HoughTransform_o2_e[56] = -5.9341194567807209E-01;
    brain_B.HoughTransform_o2_e[57] = -5.7595865315812877E-01;
    brain_B.HoughTransform_o2_e[58] = -5.5850536063818546E-01;
    brain_B.HoughTransform_o2_e[59] = -5.4105206811824214E-01;
    brain_B.HoughTransform_o2_e[60] = -5.2359877559829882E-01;
    brain_B.HoughTransform_o2_e[61] = -5.0614548307835561E-01;
    brain_B.HoughTransform_o2_e[62] = -4.8869219055841229E-01;
    brain_B.HoughTransform_o2_e[63] = -4.7123889803846897E-01;
    brain_B.HoughTransform_o2_e[64] = -4.5378560551852570E-01;
    brain_B.HoughTransform_o2_e[65] = -4.3633231299858238E-01;
    brain_B.HoughTransform_o2_e[66] = -4.1887902047863912E-01;
    brain_B.HoughTransform_o2_e[67] = -4.0142572795869580E-01;
    brain_B.HoughTransform_o2_e[68] = -3.8397243543875248E-01;
    brain_B.HoughTransform_o2_e[69] = -3.6651914291880922E-01;
    brain_B.HoughTransform_o2_e[70] = -3.4906585039886590E-01;
    brain_B.HoughTransform_o2_e[71] = -3.3161255787892263E-01;
    brain_B.HoughTransform_o2_e[72] = -3.1415926535897931E-01;
    brain_B.HoughTransform_o2_e[73] = -2.9670597283903605E-01;
    brain_B.HoughTransform_o2_e[74] = -2.7925268031909273E-01;
    brain_B.HoughTransform_o2_e[75] = -2.6179938779914941E-01;
    brain_B.HoughTransform_o2_e[76] = -2.4434609527920614E-01;
    brain_B.HoughTransform_o2_e[77] = -2.2689280275926285E-01;
    brain_B.HoughTransform_o2_e[78] = -2.0943951023931956E-01;
    brain_B.HoughTransform_o2_e[79] = -1.9198621771937624E-01;
    brain_B.HoughTransform_o2_e[80] = -1.7453292519943295E-01;
    brain_B.HoughTransform_o2_e[81] = -1.5707963267948966E-01;
    brain_B.HoughTransform_o2_e[82] = -1.3962634015954636E-01;
    brain_B.HoughTransform_o2_e[83] = -1.2217304763960307E-01;
    brain_B.HoughTransform_o2_e[84] = -1.0471975511965978E-01;
    brain_B.HoughTransform_o2_e[85] = -8.7266462599716474E-02;
    brain_B.HoughTransform_o2_e[86] = -6.9813170079773182E-02;
    brain_B.HoughTransform_o2_e[87] = -5.2359877559829890E-02;
    brain_B.HoughTransform_o2_e[88] = -3.4906585039886591E-02;
    brain_B.HoughTransform_o2_e[89] = -1.7453292519943295E-02;
    brain_B.HoughTransform_o2_e[90] = 0.0;
    brain_B.HoughTransform_o2_e[91] = 1.7453292519943295E-02;
    brain_B.HoughTransform_o2_e[92] = 3.4906585039886591E-02;
    brain_B.HoughTransform_o2_e[93] = 5.2359877559829890E-02;
    brain_B.HoughTransform_o2_e[94] = 6.9813170079773182E-02;
    brain_B.HoughTransform_o2_e[95] = 8.7266462599716474E-02;
    brain_B.HoughTransform_o2_e[96] = 1.0471975511965978E-01;
    brain_B.HoughTransform_o2_e[97] = 1.2217304763960307E-01;
    brain_B.HoughTransform_o2_e[98] = 1.3962634015954636E-01;
    brain_B.HoughTransform_o2_e[99] = 1.5707963267948966E-01;
    brain_B.HoughTransform_o2_e[100] = 1.7453292519943295E-01;
    brain_B.HoughTransform_o2_e[101] = 1.9198621771937624E-01;
    brain_B.HoughTransform_o2_e[102] = 2.0943951023931956E-01;
    brain_B.HoughTransform_o2_e[103] = 2.2689280275926285E-01;
    brain_B.HoughTransform_o2_e[104] = 2.4434609527920614E-01;
    brain_B.HoughTransform_o2_e[105] = 2.6179938779914941E-01;
    brain_B.HoughTransform_o2_e[106] = 2.7925268031909273E-01;
    brain_B.HoughTransform_o2_e[107] = 2.9670597283903605E-01;
    brain_B.HoughTransform_o2_e[108] = 3.1415926535897931E-01;
    brain_B.HoughTransform_o2_e[109] = 3.3161255787892263E-01;
    brain_B.HoughTransform_o2_e[110] = 3.4906585039886590E-01;
    brain_B.HoughTransform_o2_e[111] = 3.6651914291880922E-01;
    brain_B.HoughTransform_o2_e[112] = 3.8397243543875248E-01;
    brain_B.HoughTransform_o2_e[113] = 4.0142572795869580E-01;
    brain_B.HoughTransform_o2_e[114] = 4.1887902047863912E-01;
    brain_B.HoughTransform_o2_e[115] = 4.3633231299858238E-01;
    brain_B.HoughTransform_o2_e[116] = 4.5378560551852570E-01;
    brain_B.HoughTransform_o2_e[117] = 4.7123889803846897E-01;
    brain_B.HoughTransform_o2_e[118] = 4.8869219055841229E-01;
    brain_B.HoughTransform_o2_e[119] = 5.0614548307835561E-01;
    brain_B.HoughTransform_o2_e[120] = 5.2359877559829882E-01;
    brain_B.HoughTransform_o2_e[121] = 5.4105206811824214E-01;
    brain_B.HoughTransform_o2_e[122] = 5.5850536063818546E-01;
    brain_B.HoughTransform_o2_e[123] = 5.7595865315812877E-01;
    brain_B.HoughTransform_o2_e[124] = 5.9341194567807209E-01;
    brain_B.HoughTransform_o2_e[125] = 6.1086523819801530E-01;
    brain_B.HoughTransform_o2_e[126] = 6.2831853071795862E-01;
    brain_B.HoughTransform_o2_e[127] = 6.4577182323790194E-01;
    brain_B.HoughTransform_o2_e[128] = 6.6322511575784526E-01;
    brain_B.HoughTransform_o2_e[129] = 6.8067840827778847E-01;
    brain_B.HoughTransform_o2_e[130] = 6.9813170079773179E-01;
    brain_B.HoughTransform_o2_e[131] = 7.1558499331767511E-01;
    brain_B.HoughTransform_o2_e[132] = 7.3303828583761843E-01;
    brain_B.HoughTransform_o2_e[133] = 7.5049157835756175E-01;
    brain_B.HoughTransform_o2_e[134] = 7.6794487087750496E-01;
    brain_B.HoughTransform_o2_e[135] = 7.8539816339744828E-01;
    brain_B.HoughTransform_o2_e[136] = 8.0285145591739160E-01;
    brain_B.HoughTransform_o2_e[137] = 8.2030474843733492E-01;
    brain_B.HoughTransform_o2_e[138] = 8.3775804095727824E-01;
    brain_B.HoughTransform_o2_e[139] = 8.5521133347722145E-01;
    brain_B.HoughTransform_o2_e[140] = 8.7266462599716477E-01;
    brain_B.HoughTransform_o2_e[141] = 8.9011791851710809E-01;
    brain_B.HoughTransform_o2_e[142] = 9.0757121103705141E-01;
    brain_B.HoughTransform_o2_e[143] = 9.2502450355699462E-01;
    brain_B.HoughTransform_o2_e[144] = 9.4247779607693793E-01;
    brain_B.HoughTransform_o2_e[145] = 9.5993108859688125E-01;
    brain_B.HoughTransform_o2_e[146] = 9.7738438111682457E-01;
    brain_B.HoughTransform_o2_e[147] = 9.9483767363676789E-01;
    brain_B.HoughTransform_o2_e[148] = 1.0122909661567112E+00;
    brain_B.HoughTransform_o2_e[149] = 1.0297442586766545E+00;
    brain_B.HoughTransform_o2_e[150] = 1.0471975511965976E+00;
    brain_B.HoughTransform_o2_e[151] = 1.0646508437165410E+00;
    brain_B.HoughTransform_o2_e[152] = 1.0821041362364843E+00;
    brain_B.HoughTransform_o2_e[153] = 1.0995574287564276E+00;
    brain_B.HoughTransform_o2_e[154] = 1.1170107212763709E+00;
    brain_B.HoughTransform_o2_e[155] = 1.1344640137963142E+00;
    brain_B.HoughTransform_o2_e[156] = 1.1519173063162575E+00;
    brain_B.HoughTransform_o2_e[157] = 1.1693705988362009E+00;
    brain_B.HoughTransform_o2_e[158] = 1.1868238913561442E+00;
    brain_B.HoughTransform_o2_e[159] = 1.2042771838760873E+00;
    brain_B.HoughTransform_o2_e[160] = 1.2217304763960306E+00;
    brain_B.HoughTransform_o2_e[161] = 1.2391837689159739E+00;
    brain_B.HoughTransform_o2_e[162] = 1.2566370614359172E+00;
    brain_B.HoughTransform_o2_e[163] = 1.2740903539558606E+00;
    brain_B.HoughTransform_o2_e[164] = 1.2915436464758039E+00;
    brain_B.HoughTransform_o2_e[165] = 1.3089969389957472E+00;
    brain_B.HoughTransform_o2_e[166] = 1.3264502315156905E+00;
    brain_B.HoughTransform_o2_e[167] = 1.3439035240356338E+00;
    brain_B.HoughTransform_o2_e[168] = 1.3613568165555769E+00;
    brain_B.HoughTransform_o2_e[169] = 1.3788101090755203E+00;
    brain_B.HoughTransform_o2_e[170] = 1.3962634015954636E+00;
    brain_B.HoughTransform_o2_e[171] = 1.4137166941154069E+00;
    brain_B.HoughTransform_o2_e[172] = 1.4311699866353502E+00;
    brain_B.HoughTransform_o2_e[173] = 1.4486232791552935E+00;
    brain_B.HoughTransform_o2_e[174] = 1.4660765716752369E+00;
    brain_B.HoughTransform_o2_e[175] = 1.4835298641951802E+00;
    brain_B.HoughTransform_o2_e[176] = 1.5009831567151235E+00;
    brain_B.HoughTransform_o2_e[177] = 1.5184364492350666E+00;
    brain_B.HoughTransform_o2_e[178] = 1.5358897417550099E+00;
    brain_B.HoughTransform_o2_e[179] = 1.5533430342749532E+00;
    brain_B.HoughTransform_o3_n[0] = -143.0;
    brain_B.HoughTransform_o3_n[1] = -142.0;
    brain_B.HoughTransform_o3_n[2] = -141.0;
    brain_B.HoughTransform_o3_n[3] = -140.0;
    brain_B.HoughTransform_o3_n[4] = -139.0;
    brain_B.HoughTransform_o3_n[5] = -138.0;
    brain_B.HoughTransform_o3_n[6] = -137.0;
    brain_B.HoughTransform_o3_n[7] = -136.0;
    brain_B.HoughTransform_o3_n[8] = -135.0;
    brain_B.HoughTransform_o3_n[9] = -134.0;
    brain_B.HoughTransform_o3_n[10] = -133.0;
    brain_B.HoughTransform_o3_n[11] = -132.0;
    brain_B.HoughTransform_o3_n[12] = -131.0;
    brain_B.HoughTransform_o3_n[13] = -130.0;
    brain_B.HoughTransform_o3_n[14] = -129.0;
    brain_B.HoughTransform_o3_n[15] = -128.0;
    brain_B.HoughTransform_o3_n[16] = -127.0;
    brain_B.HoughTransform_o3_n[17] = -126.0;
    brain_B.HoughTransform_o3_n[18] = -125.0;
    brain_B.HoughTransform_o3_n[19] = -124.0;
    brain_B.HoughTransform_o3_n[20] = -123.0;
    brain_B.HoughTransform_o3_n[21] = -122.0;
    brain_B.HoughTransform_o3_n[22] = -121.0;
    brain_B.HoughTransform_o3_n[23] = -120.0;
    brain_B.HoughTransform_o3_n[24] = -119.0;
    brain_B.HoughTransform_o3_n[25] = -118.0;
    brain_B.HoughTransform_o3_n[26] = -117.0;
    brain_B.HoughTransform_o3_n[27] = -116.0;
    brain_B.HoughTransform_o3_n[28] = -115.0;
    brain_B.HoughTransform_o3_n[29] = -114.0;
    brain_B.HoughTransform_o3_n[30] = -113.0;
    brain_B.HoughTransform_o3_n[31] = -112.0;
    brain_B.HoughTransform_o3_n[32] = -111.0;
    brain_B.HoughTransform_o3_n[33] = -110.0;
    brain_B.HoughTransform_o3_n[34] = -109.0;
    brain_B.HoughTransform_o3_n[35] = -108.0;
    brain_B.HoughTransform_o3_n[36] = -107.0;
    brain_B.HoughTransform_o3_n[37] = -106.0;
    brain_B.HoughTransform_o3_n[38] = -105.0;
    brain_B.HoughTransform_o3_n[39] = -104.0;
    brain_B.HoughTransform_o3_n[40] = -103.0;
    brain_B.HoughTransform_o3_n[41] = -102.0;
    brain_B.HoughTransform_o3_n[42] = -101.0;
    brain_B.HoughTransform_o3_n[43] = -100.0;
    brain_B.HoughTransform_o3_n[44] = -99.0;
    brain_B.HoughTransform_o3_n[45] = -98.0;
    brain_B.HoughTransform_o3_n[46] = -97.0;
    brain_B.HoughTransform_o3_n[47] = -96.0;
    brain_B.HoughTransform_o3_n[48] = -95.0;
    brain_B.HoughTransform_o3_n[49] = -94.0;
    brain_B.HoughTransform_o3_n[50] = -93.0;
    brain_B.HoughTransform_o3_n[51] = -92.0;
    brain_B.HoughTransform_o3_n[52] = -91.0;
    brain_B.HoughTransform_o3_n[53] = -90.0;
    brain_B.HoughTransform_o3_n[54] = -89.0;
    brain_B.HoughTransform_o3_n[55] = -88.0;
    brain_B.HoughTransform_o3_n[56] = -87.0;
    brain_B.HoughTransform_o3_n[57] = -86.0;
    brain_B.HoughTransform_o3_n[58] = -85.0;
    brain_B.HoughTransform_o3_n[59] = -84.0;
    brain_B.HoughTransform_o3_n[60] = -83.0;
    brain_B.HoughTransform_o3_n[61] = -82.0;
    brain_B.HoughTransform_o3_n[62] = -81.0;
    brain_B.HoughTransform_o3_n[63] = -80.0;
    brain_B.HoughTransform_o3_n[64] = -79.0;
    brain_B.HoughTransform_o3_n[65] = -78.0;
    brain_B.HoughTransform_o3_n[66] = -77.0;
    brain_B.HoughTransform_o3_n[67] = -76.0;
    brain_B.HoughTransform_o3_n[68] = -75.0;
    brain_B.HoughTransform_o3_n[69] = -74.0;
    brain_B.HoughTransform_o3_n[70] = -73.0;
    brain_B.HoughTransform_o3_n[71] = -72.0;
    brain_B.HoughTransform_o3_n[72] = -71.0;
    brain_B.HoughTransform_o3_n[73] = -70.0;
    brain_B.HoughTransform_o3_n[74] = -69.0;
    brain_B.HoughTransform_o3_n[75] = -68.0;
    brain_B.HoughTransform_o3_n[76] = -67.0;
    brain_B.HoughTransform_o3_n[77] = -66.0;
    brain_B.HoughTransform_o3_n[78] = -65.0;
    brain_B.HoughTransform_o3_n[79] = -64.0;
    brain_B.HoughTransform_o3_n[80] = -63.0;
    brain_B.HoughTransform_o3_n[81] = -62.0;
    brain_B.HoughTransform_o3_n[82] = -61.0;
    brain_B.HoughTransform_o3_n[83] = -60.0;
    brain_B.HoughTransform_o3_n[84] = -59.0;
    brain_B.HoughTransform_o3_n[85] = -58.0;
    brain_B.HoughTransform_o3_n[86] = -57.0;
    brain_B.HoughTransform_o3_n[87] = -56.0;
    brain_B.HoughTransform_o3_n[88] = -55.0;
    brain_B.HoughTransform_o3_n[89] = -54.0;
    brain_B.HoughTransform_o3_n[90] = -53.0;
    brain_B.HoughTransform_o3_n[91] = -52.0;
    brain_B.HoughTransform_o3_n[92] = -51.0;
    brain_B.HoughTransform_o3_n[93] = -50.0;
    brain_B.HoughTransform_o3_n[94] = -49.0;
    brain_B.HoughTransform_o3_n[95] = -48.0;
    brain_B.HoughTransform_o3_n[96] = -47.0;
    brain_B.HoughTransform_o3_n[97] = -46.0;
    brain_B.HoughTransform_o3_n[98] = -45.0;
    brain_B.HoughTransform_o3_n[99] = -44.0;
    brain_B.HoughTransform_o3_n[100] = -43.0;
    brain_B.HoughTransform_o3_n[101] = -42.0;
    brain_B.HoughTransform_o3_n[102] = -41.0;
    brain_B.HoughTransform_o3_n[103] = -40.0;
    brain_B.HoughTransform_o3_n[104] = -39.0;
    brain_B.HoughTransform_o3_n[105] = -38.0;
    brain_B.HoughTransform_o3_n[106] = -37.0;
    brain_B.HoughTransform_o3_n[107] = -36.0;
    brain_B.HoughTransform_o3_n[108] = -35.0;
    brain_B.HoughTransform_o3_n[109] = -34.0;
    brain_B.HoughTransform_o3_n[110] = -33.0;
    brain_B.HoughTransform_o3_n[111] = -32.0;
    brain_B.HoughTransform_o3_n[112] = -31.0;
    brain_B.HoughTransform_o3_n[113] = -30.0;
    brain_B.HoughTransform_o3_n[114] = -29.0;
    brain_B.HoughTransform_o3_n[115] = -28.0;
    brain_B.HoughTransform_o3_n[116] = -27.0;
    brain_B.HoughTransform_o3_n[117] = -26.0;
    brain_B.HoughTransform_o3_n[118] = -25.0;
    brain_B.HoughTransform_o3_n[119] = -24.0;
    brain_B.HoughTransform_o3_n[120] = -23.0;
    brain_B.HoughTransform_o3_n[121] = -22.0;
    brain_B.HoughTransform_o3_n[122] = -21.0;
    brain_B.HoughTransform_o3_n[123] = -20.0;
    brain_B.HoughTransform_o3_n[124] = -19.0;
    brain_B.HoughTransform_o3_n[125] = -18.0;
    brain_B.HoughTransform_o3_n[126] = -17.0;
    brain_B.HoughTransform_o3_n[127] = -16.0;
    brain_B.HoughTransform_o3_n[128] = -15.0;
    brain_B.HoughTransform_o3_n[129] = -14.0;
    brain_B.HoughTransform_o3_n[130] = -13.0;
    brain_B.HoughTransform_o3_n[131] = -12.0;
    brain_B.HoughTransform_o3_n[132] = -11.0;
    brain_B.HoughTransform_o3_n[133] = -10.0;
    brain_B.HoughTransform_o3_n[134] = -9.0;
    brain_B.HoughTransform_o3_n[135] = -8.0;
    brain_B.HoughTransform_o3_n[136] = -7.0;
    brain_B.HoughTransform_o3_n[137] = -6.0;
    brain_B.HoughTransform_o3_n[138] = -5.0;
    brain_B.HoughTransform_o3_n[139] = -4.0;
    brain_B.HoughTransform_o3_n[140] = -3.0;
    brain_B.HoughTransform_o3_n[141] = -2.0;
    brain_B.HoughTransform_o3_n[142] = -1.0;
    brain_B.HoughTransform_o3_n[143] = 0.0;
    brain_B.HoughTransform_o3_n[144] = 1.0;
    brain_B.HoughTransform_o3_n[145] = 2.0;
    brain_B.HoughTransform_o3_n[146] = 3.0;
    brain_B.HoughTransform_o3_n[147] = 4.0;
    brain_B.HoughTransform_o3_n[148] = 5.0;
    brain_B.HoughTransform_o3_n[149] = 6.0;
    brain_B.HoughTransform_o3_n[150] = 7.0;
    brain_B.HoughTransform_o3_n[151] = 8.0;
    brain_B.HoughTransform_o3_n[152] = 9.0;
    brain_B.HoughTransform_o3_n[153] = 10.0;
    brain_B.HoughTransform_o3_n[154] = 11.0;
    brain_B.HoughTransform_o3_n[155] = 12.0;
    brain_B.HoughTransform_o3_n[156] = 13.0;
    brain_B.HoughTransform_o3_n[157] = 14.0;
    brain_B.HoughTransform_o3_n[158] = 15.0;
    brain_B.HoughTransform_o3_n[159] = 16.0;
    brain_B.HoughTransform_o3_n[160] = 17.0;
    brain_B.HoughTransform_o3_n[161] = 18.0;
    brain_B.HoughTransform_o3_n[162] = 19.0;
    brain_B.HoughTransform_o3_n[163] = 20.0;
    brain_B.HoughTransform_o3_n[164] = 21.0;
    brain_B.HoughTransform_o3_n[165] = 22.0;
    brain_B.HoughTransform_o3_n[166] = 23.0;
    brain_B.HoughTransform_o3_n[167] = 24.0;
    brain_B.HoughTransform_o3_n[168] = 25.0;
    brain_B.HoughTransform_o3_n[169] = 26.0;
    brain_B.HoughTransform_o3_n[170] = 27.0;
    brain_B.HoughTransform_o3_n[171] = 28.0;
    brain_B.HoughTransform_o3_n[172] = 29.0;
    brain_B.HoughTransform_o3_n[173] = 30.0;
    brain_B.HoughTransform_o3_n[174] = 31.0;
    brain_B.HoughTransform_o3_n[175] = 32.0;
    brain_B.HoughTransform_o3_n[176] = 33.0;
    brain_B.HoughTransform_o3_n[177] = 34.0;
    brain_B.HoughTransform_o3_n[178] = 35.0;
    brain_B.HoughTransform_o3_n[179] = 36.0;
    brain_B.HoughTransform_o3_n[180] = 37.0;
    brain_B.HoughTransform_o3_n[181] = 38.0;
    brain_B.HoughTransform_o3_n[182] = 39.0;
    brain_B.HoughTransform_o3_n[183] = 40.0;
    brain_B.HoughTransform_o3_n[184] = 41.0;
    brain_B.HoughTransform_o3_n[185] = 42.0;
    brain_B.HoughTransform_o3_n[186] = 43.0;
    brain_B.HoughTransform_o3_n[187] = 44.0;
    brain_B.HoughTransform_o3_n[188] = 45.0;
    brain_B.HoughTransform_o3_n[189] = 46.0;
    brain_B.HoughTransform_o3_n[190] = 47.0;
    brain_B.HoughTransform_o3_n[191] = 48.0;
    brain_B.HoughTransform_o3_n[192] = 49.0;
    brain_B.HoughTransform_o3_n[193] = 50.0;
    brain_B.HoughTransform_o3_n[194] = 51.0;
    brain_B.HoughTransform_o3_n[195] = 52.0;
    brain_B.HoughTransform_o3_n[196] = 53.0;
    brain_B.HoughTransform_o3_n[197] = 54.0;
    brain_B.HoughTransform_o3_n[198] = 55.0;
    brain_B.HoughTransform_o3_n[199] = 56.0;
    brain_B.HoughTransform_o3_n[200] = 57.0;
    brain_B.HoughTransform_o3_n[201] = 58.0;
    brain_B.HoughTransform_o3_n[202] = 59.0;
    brain_B.HoughTransform_o3_n[203] = 60.0;
    brain_B.HoughTransform_o3_n[204] = 61.0;
    brain_B.HoughTransform_o3_n[205] = 62.0;
    brain_B.HoughTransform_o3_n[206] = 63.0;
    brain_B.HoughTransform_o3_n[207] = 64.0;
    brain_B.HoughTransform_o3_n[208] = 65.0;
    brain_B.HoughTransform_o3_n[209] = 66.0;
    brain_B.HoughTransform_o3_n[210] = 67.0;
    brain_B.HoughTransform_o3_n[211] = 68.0;
    brain_B.HoughTransform_o3_n[212] = 69.0;
    brain_B.HoughTransform_o3_n[213] = 70.0;
    brain_B.HoughTransform_o3_n[214] = 71.0;
    brain_B.HoughTransform_o3_n[215] = 72.0;
    brain_B.HoughTransform_o3_n[216] = 73.0;
    brain_B.HoughTransform_o3_n[217] = 74.0;
    brain_B.HoughTransform_o3_n[218] = 75.0;
    brain_B.HoughTransform_o3_n[219] = 76.0;
    brain_B.HoughTransform_o3_n[220] = 77.0;
    brain_B.HoughTransform_o3_n[221] = 78.0;
    brain_B.HoughTransform_o3_n[222] = 79.0;
    brain_B.HoughTransform_o3_n[223] = 80.0;
    brain_B.HoughTransform_o3_n[224] = 81.0;
    brain_B.HoughTransform_o3_n[225] = 82.0;
    brain_B.HoughTransform_o3_n[226] = 83.0;
    brain_B.HoughTransform_o3_n[227] = 84.0;
    brain_B.HoughTransform_o3_n[228] = 85.0;
    brain_B.HoughTransform_o3_n[229] = 86.0;
    brain_B.HoughTransform_o3_n[230] = 87.0;
    brain_B.HoughTransform_o3_n[231] = 88.0;
    brain_B.HoughTransform_o3_n[232] = 89.0;
    brain_B.HoughTransform_o3_n[233] = 90.0;
    brain_B.HoughTransform_o3_n[234] = 91.0;
    brain_B.HoughTransform_o3_n[235] = 92.0;
    brain_B.HoughTransform_o3_n[236] = 93.0;
    brain_B.HoughTransform_o3_n[237] = 94.0;
    brain_B.HoughTransform_o3_n[238] = 95.0;
    brain_B.HoughTransform_o3_n[239] = 96.0;
    brain_B.HoughTransform_o3_n[240] = 97.0;
    brain_B.HoughTransform_o3_n[241] = 98.0;
    brain_B.HoughTransform_o3_n[242] = 99.0;
    brain_B.HoughTransform_o3_n[243] = 100.0;
    brain_B.HoughTransform_o3_n[244] = 101.0;
    brain_B.HoughTransform_o3_n[245] = 102.0;
    brain_B.HoughTransform_o3_n[246] = 103.0;
    brain_B.HoughTransform_o3_n[247] = 104.0;
    brain_B.HoughTransform_o3_n[248] = 105.0;
    brain_B.HoughTransform_o3_n[249] = 106.0;
    brain_B.HoughTransform_o3_n[250] = 107.0;
    brain_B.HoughTransform_o3_n[251] = 108.0;
    brain_B.HoughTransform_o3_n[252] = 109.0;
    brain_B.HoughTransform_o3_n[253] = 110.0;
    brain_B.HoughTransform_o3_n[254] = 111.0;
    brain_B.HoughTransform_o3_n[255] = 112.0;
    brain_B.HoughTransform_o3_n[256] = 113.0;
    brain_B.HoughTransform_o3_n[257] = 114.0;
    brain_B.HoughTransform_o3_n[258] = 115.0;
    brain_B.HoughTransform_o3_n[259] = 116.0;
    brain_B.HoughTransform_o3_n[260] = 117.0;
    brain_B.HoughTransform_o3_n[261] = 118.0;
    brain_B.HoughTransform_o3_n[262] = 119.0;
    brain_B.HoughTransform_o3_n[263] = 120.0;
    brain_B.HoughTransform_o3_n[264] = 121.0;
    brain_B.HoughTransform_o3_n[265] = 122.0;
    brain_B.HoughTransform_o3_n[266] = 123.0;
    brain_B.HoughTransform_o3_n[267] = 124.0;
    brain_B.HoughTransform_o3_n[268] = 125.0;
    brain_B.HoughTransform_o3_n[269] = 126.0;
    brain_B.HoughTransform_o3_n[270] = 127.0;
    brain_B.HoughTransform_o3_n[271] = 128.0;
    brain_B.HoughTransform_o3_n[272] = 129.0;
    brain_B.HoughTransform_o3_n[273] = 130.0;
    brain_B.HoughTransform_o3_n[274] = 131.0;
    brain_B.HoughTransform_o3_n[275] = 132.0;
    brain_B.HoughTransform_o3_n[276] = 133.0;
    brain_B.HoughTransform_o3_n[277] = 134.0;
    brain_B.HoughTransform_o3_n[278] = 135.0;
    brain_B.HoughTransform_o3_n[279] = 136.0;
    brain_B.HoughTransform_o3_n[280] = 137.0;
    brain_B.HoughTransform_o3_n[281] = 138.0;
    brain_B.HoughTransform_o3_n[282] = 139.0;
    brain_B.HoughTransform_o3_n[283] = 140.0;
    brain_B.HoughTransform_o3_n[284] = 141.0;
    brain_B.HoughTransform_o3_n[285] = 142.0;
    brain_B.HoughTransform_o3_n[286] = 143.0;
    brain_B.HoughTransform_o2_m[0] = -1.5707963267948966E+00;
    brain_B.HoughTransform_o2_m[1] = -1.5533430342749532E+00;
    brain_B.HoughTransform_o2_m[2] = -1.5358897417550099E+00;
    brain_B.HoughTransform_o2_m[3] = -1.5184364492350666E+00;
    brain_B.HoughTransform_o2_m[4] = -1.5009831567151235E+00;
    brain_B.HoughTransform_o2_m[5] = -1.4835298641951802E+00;
    brain_B.HoughTransform_o2_m[6] = -1.4660765716752369E+00;
    brain_B.HoughTransform_o2_m[7] = -1.4486232791552935E+00;
    brain_B.HoughTransform_o2_m[8] = -1.4311699866353502E+00;
    brain_B.HoughTransform_o2_m[9] = -1.4137166941154069E+00;
    brain_B.HoughTransform_o2_m[10] = -1.3962634015954636E+00;
    brain_B.HoughTransform_o2_m[11] = -1.3788101090755203E+00;
    brain_B.HoughTransform_o2_m[12] = -1.3613568165555769E+00;
    brain_B.HoughTransform_o2_m[13] = -1.3439035240356338E+00;
    brain_B.HoughTransform_o2_m[14] = -1.3264502315156905E+00;
    brain_B.HoughTransform_o2_m[15] = -1.3089969389957472E+00;
    brain_B.HoughTransform_o2_m[16] = -1.2915436464758039E+00;
    brain_B.HoughTransform_o2_m[17] = -1.2740903539558606E+00;
    brain_B.HoughTransform_o2_m[18] = -1.2566370614359172E+00;
    brain_B.HoughTransform_o2_m[19] = -1.2391837689159739E+00;
    brain_B.HoughTransform_o2_m[20] = -1.2217304763960306E+00;
    brain_B.HoughTransform_o2_m[21] = -1.2042771838760873E+00;
    brain_B.HoughTransform_o2_m[22] = -1.1868238913561442E+00;
    brain_B.HoughTransform_o2_m[23] = -1.1693705988362009E+00;
    brain_B.HoughTransform_o2_m[24] = -1.1519173063162575E+00;
    brain_B.HoughTransform_o2_m[25] = -1.1344640137963142E+00;
    brain_B.HoughTransform_o2_m[26] = -1.1170107212763709E+00;
    brain_B.HoughTransform_o2_m[27] = -1.0995574287564276E+00;
    brain_B.HoughTransform_o2_m[28] = -1.0821041362364843E+00;
    brain_B.HoughTransform_o2_m[29] = -1.0646508437165410E+00;
    brain_B.HoughTransform_o2_m[30] = -1.0471975511965976E+00;
    brain_B.HoughTransform_o2_m[31] = -1.0297442586766545E+00;
    brain_B.HoughTransform_o2_m[32] = -1.0122909661567112E+00;
    brain_B.HoughTransform_o2_m[33] = -9.9483767363676789E-01;
    brain_B.HoughTransform_o2_m[34] = -9.7738438111682457E-01;
    brain_B.HoughTransform_o2_m[35] = -9.5993108859688125E-01;
    brain_B.HoughTransform_o2_m[36] = -9.4247779607693793E-01;
    brain_B.HoughTransform_o2_m[37] = -9.2502450355699462E-01;
    brain_B.HoughTransform_o2_m[38] = -9.0757121103705141E-01;
    brain_B.HoughTransform_o2_m[39] = -8.9011791851710809E-01;
    brain_B.HoughTransform_o2_m[40] = -8.7266462599716477E-01;
    brain_B.HoughTransform_o2_m[41] = -8.5521133347722145E-01;
    brain_B.HoughTransform_o2_m[42] = -8.3775804095727824E-01;
    brain_B.HoughTransform_o2_m[43] = -8.2030474843733492E-01;
    brain_B.HoughTransform_o2_m[44] = -8.0285145591739160E-01;
    brain_B.HoughTransform_o2_m[45] = -7.8539816339744828E-01;
    brain_B.HoughTransform_o2_m[46] = -7.6794487087750496E-01;
    brain_B.HoughTransform_o2_m[47] = -7.5049157835756175E-01;
    brain_B.HoughTransform_o2_m[48] = -7.3303828583761843E-01;
    brain_B.HoughTransform_o2_m[49] = -7.1558499331767511E-01;
    brain_B.HoughTransform_o2_m[50] = -6.9813170079773179E-01;
    brain_B.HoughTransform_o2_m[51] = -6.8067840827778847E-01;
    brain_B.HoughTransform_o2_m[52] = -6.6322511575784526E-01;
    brain_B.HoughTransform_o2_m[53] = -6.4577182323790194E-01;
    brain_B.HoughTransform_o2_m[54] = -6.2831853071795862E-01;
    brain_B.HoughTransform_o2_m[55] = -6.1086523819801530E-01;
    brain_B.HoughTransform_o2_m[56] = -5.9341194567807209E-01;
    brain_B.HoughTransform_o2_m[57] = -5.7595865315812877E-01;
    brain_B.HoughTransform_o2_m[58] = -5.5850536063818546E-01;
    brain_B.HoughTransform_o2_m[59] = -5.4105206811824214E-01;
    brain_B.HoughTransform_o2_m[60] = -5.2359877559829882E-01;
    brain_B.HoughTransform_o2_m[61] = -5.0614548307835561E-01;
    brain_B.HoughTransform_o2_m[62] = -4.8869219055841229E-01;
    brain_B.HoughTransform_o2_m[63] = -4.7123889803846897E-01;
    brain_B.HoughTransform_o2_m[64] = -4.5378560551852570E-01;
    brain_B.HoughTransform_o2_m[65] = -4.3633231299858238E-01;
    brain_B.HoughTransform_o2_m[66] = -4.1887902047863912E-01;
    brain_B.HoughTransform_o2_m[67] = -4.0142572795869580E-01;
    brain_B.HoughTransform_o2_m[68] = -3.8397243543875248E-01;
    brain_B.HoughTransform_o2_m[69] = -3.6651914291880922E-01;
    brain_B.HoughTransform_o2_m[70] = -3.4906585039886590E-01;
    brain_B.HoughTransform_o2_m[71] = -3.3161255787892263E-01;
    brain_B.HoughTransform_o2_m[72] = -3.1415926535897931E-01;
    brain_B.HoughTransform_o2_m[73] = -2.9670597283903605E-01;
    brain_B.HoughTransform_o2_m[74] = -2.7925268031909273E-01;
    brain_B.HoughTransform_o2_m[75] = -2.6179938779914941E-01;
    brain_B.HoughTransform_o2_m[76] = -2.4434609527920614E-01;
    brain_B.HoughTransform_o2_m[77] = -2.2689280275926285E-01;
    brain_B.HoughTransform_o2_m[78] = -2.0943951023931956E-01;
    brain_B.HoughTransform_o2_m[79] = -1.9198621771937624E-01;
    brain_B.HoughTransform_o2_m[80] = -1.7453292519943295E-01;
    brain_B.HoughTransform_o2_m[81] = -1.5707963267948966E-01;
    brain_B.HoughTransform_o2_m[82] = -1.3962634015954636E-01;
    brain_B.HoughTransform_o2_m[83] = -1.2217304763960307E-01;
    brain_B.HoughTransform_o2_m[84] = -1.0471975511965978E-01;
    brain_B.HoughTransform_o2_m[85] = -8.7266462599716474E-02;
    brain_B.HoughTransform_o2_m[86] = -6.9813170079773182E-02;
    brain_B.HoughTransform_o2_m[87] = -5.2359877559829890E-02;
    brain_B.HoughTransform_o2_m[88] = -3.4906585039886591E-02;
    brain_B.HoughTransform_o2_m[89] = -1.7453292519943295E-02;
    brain_B.HoughTransform_o2_m[90] = 0.0;
    brain_B.HoughTransform_o2_m[91] = 1.7453292519943295E-02;
    brain_B.HoughTransform_o2_m[92] = 3.4906585039886591E-02;
    brain_B.HoughTransform_o2_m[93] = 5.2359877559829890E-02;
    brain_B.HoughTransform_o2_m[94] = 6.9813170079773182E-02;
    brain_B.HoughTransform_o2_m[95] = 8.7266462599716474E-02;
    brain_B.HoughTransform_o2_m[96] = 1.0471975511965978E-01;
    brain_B.HoughTransform_o2_m[97] = 1.2217304763960307E-01;
    brain_B.HoughTransform_o2_m[98] = 1.3962634015954636E-01;
    brain_B.HoughTransform_o2_m[99] = 1.5707963267948966E-01;
    brain_B.HoughTransform_o2_m[100] = 1.7453292519943295E-01;
    brain_B.HoughTransform_o2_m[101] = 1.9198621771937624E-01;
    brain_B.HoughTransform_o2_m[102] = 2.0943951023931956E-01;
    brain_B.HoughTransform_o2_m[103] = 2.2689280275926285E-01;
    brain_B.HoughTransform_o2_m[104] = 2.4434609527920614E-01;
    brain_B.HoughTransform_o2_m[105] = 2.6179938779914941E-01;
    brain_B.HoughTransform_o2_m[106] = 2.7925268031909273E-01;
    brain_B.HoughTransform_o2_m[107] = 2.9670597283903605E-01;
    brain_B.HoughTransform_o2_m[108] = 3.1415926535897931E-01;
    brain_B.HoughTransform_o2_m[109] = 3.3161255787892263E-01;
    brain_B.HoughTransform_o2_m[110] = 3.4906585039886590E-01;
    brain_B.HoughTransform_o2_m[111] = 3.6651914291880922E-01;
    brain_B.HoughTransform_o2_m[112] = 3.8397243543875248E-01;
    brain_B.HoughTransform_o2_m[113] = 4.0142572795869580E-01;
    brain_B.HoughTransform_o2_m[114] = 4.1887902047863912E-01;
    brain_B.HoughTransform_o2_m[115] = 4.3633231299858238E-01;
    brain_B.HoughTransform_o2_m[116] = 4.5378560551852570E-01;
    brain_B.HoughTransform_o2_m[117] = 4.7123889803846897E-01;
    brain_B.HoughTransform_o2_m[118] = 4.8869219055841229E-01;
    brain_B.HoughTransform_o2_m[119] = 5.0614548307835561E-01;
    brain_B.HoughTransform_o2_m[120] = 5.2359877559829882E-01;
    brain_B.HoughTransform_o2_m[121] = 5.4105206811824214E-01;
    brain_B.HoughTransform_o2_m[122] = 5.5850536063818546E-01;
    brain_B.HoughTransform_o2_m[123] = 5.7595865315812877E-01;
    brain_B.HoughTransform_o2_m[124] = 5.9341194567807209E-01;
    brain_B.HoughTransform_o2_m[125] = 6.1086523819801530E-01;
    brain_B.HoughTransform_o2_m[126] = 6.2831853071795862E-01;
    brain_B.HoughTransform_o2_m[127] = 6.4577182323790194E-01;
    brain_B.HoughTransform_o2_m[128] = 6.6322511575784526E-01;
    brain_B.HoughTransform_o2_m[129] = 6.8067840827778847E-01;
    brain_B.HoughTransform_o2_m[130] = 6.9813170079773179E-01;
    brain_B.HoughTransform_o2_m[131] = 7.1558499331767511E-01;
    brain_B.HoughTransform_o2_m[132] = 7.3303828583761843E-01;
    brain_B.HoughTransform_o2_m[133] = 7.5049157835756175E-01;
    brain_B.HoughTransform_o2_m[134] = 7.6794487087750496E-01;
    brain_B.HoughTransform_o2_m[135] = 7.8539816339744828E-01;
    brain_B.HoughTransform_o2_m[136] = 8.0285145591739160E-01;
    brain_B.HoughTransform_o2_m[137] = 8.2030474843733492E-01;
    brain_B.HoughTransform_o2_m[138] = 8.3775804095727824E-01;
    brain_B.HoughTransform_o2_m[139] = 8.5521133347722145E-01;
    brain_B.HoughTransform_o2_m[140] = 8.7266462599716477E-01;
    brain_B.HoughTransform_o2_m[141] = 8.9011791851710809E-01;
    brain_B.HoughTransform_o2_m[142] = 9.0757121103705141E-01;
    brain_B.HoughTransform_o2_m[143] = 9.2502450355699462E-01;
    brain_B.HoughTransform_o2_m[144] = 9.4247779607693793E-01;
    brain_B.HoughTransform_o2_m[145] = 9.5993108859688125E-01;
    brain_B.HoughTransform_o2_m[146] = 9.7738438111682457E-01;
    brain_B.HoughTransform_o2_m[147] = 9.9483767363676789E-01;
    brain_B.HoughTransform_o2_m[148] = 1.0122909661567112E+00;
    brain_B.HoughTransform_o2_m[149] = 1.0297442586766545E+00;
    brain_B.HoughTransform_o2_m[150] = 1.0471975511965976E+00;
    brain_B.HoughTransform_o2_m[151] = 1.0646508437165410E+00;
    brain_B.HoughTransform_o2_m[152] = 1.0821041362364843E+00;
    brain_B.HoughTransform_o2_m[153] = 1.0995574287564276E+00;
    brain_B.HoughTransform_o2_m[154] = 1.1170107212763709E+00;
    brain_B.HoughTransform_o2_m[155] = 1.1344640137963142E+00;
    brain_B.HoughTransform_o2_m[156] = 1.1519173063162575E+00;
    brain_B.HoughTransform_o2_m[157] = 1.1693705988362009E+00;
    brain_B.HoughTransform_o2_m[158] = 1.1868238913561442E+00;
    brain_B.HoughTransform_o2_m[159] = 1.2042771838760873E+00;
    brain_B.HoughTransform_o2_m[160] = 1.2217304763960306E+00;
    brain_B.HoughTransform_o2_m[161] = 1.2391837689159739E+00;
    brain_B.HoughTransform_o2_m[162] = 1.2566370614359172E+00;
    brain_B.HoughTransform_o2_m[163] = 1.2740903539558606E+00;
    brain_B.HoughTransform_o2_m[164] = 1.2915436464758039E+00;
    brain_B.HoughTransform_o2_m[165] = 1.3089969389957472E+00;
    brain_B.HoughTransform_o2_m[166] = 1.3264502315156905E+00;
    brain_B.HoughTransform_o2_m[167] = 1.3439035240356338E+00;
    brain_B.HoughTransform_o2_m[168] = 1.3613568165555769E+00;
    brain_B.HoughTransform_o2_m[169] = 1.3788101090755203E+00;
    brain_B.HoughTransform_o2_m[170] = 1.3962634015954636E+00;
    brain_B.HoughTransform_o2_m[171] = 1.4137166941154069E+00;
    brain_B.HoughTransform_o2_m[172] = 1.4311699866353502E+00;
    brain_B.HoughTransform_o2_m[173] = 1.4486232791552935E+00;
    brain_B.HoughTransform_o2_m[174] = 1.4660765716752369E+00;
    brain_B.HoughTransform_o2_m[175] = 1.4835298641951802E+00;
    brain_B.HoughTransform_o2_m[176] = 1.5009831567151235E+00;
    brain_B.HoughTransform_o2_m[177] = 1.5184364492350666E+00;
    brain_B.HoughTransform_o2_m[178] = 1.5358897417550099E+00;
    brain_B.HoughTransform_o2_m[179] = 1.5533430342749532E+00;
    brain_B.HoughTransform_o3_k[0] = -143.0;
    brain_B.HoughTransform_o3_k[1] = -142.0;
    brain_B.HoughTransform_o3_k[2] = -141.0;
    brain_B.HoughTransform_o3_k[3] = -140.0;
    brain_B.HoughTransform_o3_k[4] = -139.0;
    brain_B.HoughTransform_o3_k[5] = -138.0;
    brain_B.HoughTransform_o3_k[6] = -137.0;
    brain_B.HoughTransform_o3_k[7] = -136.0;
    brain_B.HoughTransform_o3_k[8] = -135.0;
    brain_B.HoughTransform_o3_k[9] = -134.0;
    brain_B.HoughTransform_o3_k[10] = -133.0;
    brain_B.HoughTransform_o3_k[11] = -132.0;
    brain_B.HoughTransform_o3_k[12] = -131.0;
    brain_B.HoughTransform_o3_k[13] = -130.0;
    brain_B.HoughTransform_o3_k[14] = -129.0;
    brain_B.HoughTransform_o3_k[15] = -128.0;
    brain_B.HoughTransform_o3_k[16] = -127.0;
    brain_B.HoughTransform_o3_k[17] = -126.0;
    brain_B.HoughTransform_o3_k[18] = -125.0;
    brain_B.HoughTransform_o3_k[19] = -124.0;
    brain_B.HoughTransform_o3_k[20] = -123.0;
    brain_B.HoughTransform_o3_k[21] = -122.0;
    brain_B.HoughTransform_o3_k[22] = -121.0;
    brain_B.HoughTransform_o3_k[23] = -120.0;
    brain_B.HoughTransform_o3_k[24] = -119.0;
    brain_B.HoughTransform_o3_k[25] = -118.0;
    brain_B.HoughTransform_o3_k[26] = -117.0;
    brain_B.HoughTransform_o3_k[27] = -116.0;
    brain_B.HoughTransform_o3_k[28] = -115.0;
    brain_B.HoughTransform_o3_k[29] = -114.0;
    brain_B.HoughTransform_o3_k[30] = -113.0;
    brain_B.HoughTransform_o3_k[31] = -112.0;
    brain_B.HoughTransform_o3_k[32] = -111.0;
    brain_B.HoughTransform_o3_k[33] = -110.0;
    brain_B.HoughTransform_o3_k[34] = -109.0;
    brain_B.HoughTransform_o3_k[35] = -108.0;
    brain_B.HoughTransform_o3_k[36] = -107.0;
    brain_B.HoughTransform_o3_k[37] = -106.0;
    brain_B.HoughTransform_o3_k[38] = -105.0;
    brain_B.HoughTransform_o3_k[39] = -104.0;
    brain_B.HoughTransform_o3_k[40] = -103.0;
    brain_B.HoughTransform_o3_k[41] = -102.0;
    brain_B.HoughTransform_o3_k[42] = -101.0;
    brain_B.HoughTransform_o3_k[43] = -100.0;
    brain_B.HoughTransform_o3_k[44] = -99.0;
    brain_B.HoughTransform_o3_k[45] = -98.0;
    brain_B.HoughTransform_o3_k[46] = -97.0;
    brain_B.HoughTransform_o3_k[47] = -96.0;
    brain_B.HoughTransform_o3_k[48] = -95.0;
    brain_B.HoughTransform_o3_k[49] = -94.0;
    brain_B.HoughTransform_o3_k[50] = -93.0;
    brain_B.HoughTransform_o3_k[51] = -92.0;
    brain_B.HoughTransform_o3_k[52] = -91.0;
    brain_B.HoughTransform_o3_k[53] = -90.0;
    brain_B.HoughTransform_o3_k[54] = -89.0;
    brain_B.HoughTransform_o3_k[55] = -88.0;
    brain_B.HoughTransform_o3_k[56] = -87.0;
    brain_B.HoughTransform_o3_k[57] = -86.0;
    brain_B.HoughTransform_o3_k[58] = -85.0;
    brain_B.HoughTransform_o3_k[59] = -84.0;
    brain_B.HoughTransform_o3_k[60] = -83.0;
    brain_B.HoughTransform_o3_k[61] = -82.0;
    brain_B.HoughTransform_o3_k[62] = -81.0;
    brain_B.HoughTransform_o3_k[63] = -80.0;
    brain_B.HoughTransform_o3_k[64] = -79.0;
    brain_B.HoughTransform_o3_k[65] = -78.0;
    brain_B.HoughTransform_o3_k[66] = -77.0;
    brain_B.HoughTransform_o3_k[67] = -76.0;
    brain_B.HoughTransform_o3_k[68] = -75.0;
    brain_B.HoughTransform_o3_k[69] = -74.0;
    brain_B.HoughTransform_o3_k[70] = -73.0;
    brain_B.HoughTransform_o3_k[71] = -72.0;
    brain_B.HoughTransform_o3_k[72] = -71.0;
    brain_B.HoughTransform_o3_k[73] = -70.0;
    brain_B.HoughTransform_o3_k[74] = -69.0;
    brain_B.HoughTransform_o3_k[75] = -68.0;
    brain_B.HoughTransform_o3_k[76] = -67.0;
    brain_B.HoughTransform_o3_k[77] = -66.0;
    brain_B.HoughTransform_o3_k[78] = -65.0;
    brain_B.HoughTransform_o3_k[79] = -64.0;
    brain_B.HoughTransform_o3_k[80] = -63.0;
    brain_B.HoughTransform_o3_k[81] = -62.0;
    brain_B.HoughTransform_o3_k[82] = -61.0;
    brain_B.HoughTransform_o3_k[83] = -60.0;
    brain_B.HoughTransform_o3_k[84] = -59.0;
    brain_B.HoughTransform_o3_k[85] = -58.0;
    brain_B.HoughTransform_o3_k[86] = -57.0;
    brain_B.HoughTransform_o3_k[87] = -56.0;
    brain_B.HoughTransform_o3_k[88] = -55.0;
    brain_B.HoughTransform_o3_k[89] = -54.0;
    brain_B.HoughTransform_o3_k[90] = -53.0;
    brain_B.HoughTransform_o3_k[91] = -52.0;
    brain_B.HoughTransform_o3_k[92] = -51.0;
    brain_B.HoughTransform_o3_k[93] = -50.0;
    brain_B.HoughTransform_o3_k[94] = -49.0;
    brain_B.HoughTransform_o3_k[95] = -48.0;
    brain_B.HoughTransform_o3_k[96] = -47.0;
    brain_B.HoughTransform_o3_k[97] = -46.0;
    brain_B.HoughTransform_o3_k[98] = -45.0;
    brain_B.HoughTransform_o3_k[99] = -44.0;
    brain_B.HoughTransform_o3_k[100] = -43.0;
    brain_B.HoughTransform_o3_k[101] = -42.0;
    brain_B.HoughTransform_o3_k[102] = -41.0;
    brain_B.HoughTransform_o3_k[103] = -40.0;
    brain_B.HoughTransform_o3_k[104] = -39.0;
    brain_B.HoughTransform_o3_k[105] = -38.0;
    brain_B.HoughTransform_o3_k[106] = -37.0;
    brain_B.HoughTransform_o3_k[107] = -36.0;
    brain_B.HoughTransform_o3_k[108] = -35.0;
    brain_B.HoughTransform_o3_k[109] = -34.0;
    brain_B.HoughTransform_o3_k[110] = -33.0;
    brain_B.HoughTransform_o3_k[111] = -32.0;
    brain_B.HoughTransform_o3_k[112] = -31.0;
    brain_B.HoughTransform_o3_k[113] = -30.0;
    brain_B.HoughTransform_o3_k[114] = -29.0;
    brain_B.HoughTransform_o3_k[115] = -28.0;
    brain_B.HoughTransform_o3_k[116] = -27.0;
    brain_B.HoughTransform_o3_k[117] = -26.0;
    brain_B.HoughTransform_o3_k[118] = -25.0;
    brain_B.HoughTransform_o3_k[119] = -24.0;
    brain_B.HoughTransform_o3_k[120] = -23.0;
    brain_B.HoughTransform_o3_k[121] = -22.0;
    brain_B.HoughTransform_o3_k[122] = -21.0;
    brain_B.HoughTransform_o3_k[123] = -20.0;
    brain_B.HoughTransform_o3_k[124] = -19.0;
    brain_B.HoughTransform_o3_k[125] = -18.0;
    brain_B.HoughTransform_o3_k[126] = -17.0;
    brain_B.HoughTransform_o3_k[127] = -16.0;
    brain_B.HoughTransform_o3_k[128] = -15.0;
    brain_B.HoughTransform_o3_k[129] = -14.0;
    brain_B.HoughTransform_o3_k[130] = -13.0;
    brain_B.HoughTransform_o3_k[131] = -12.0;
    brain_B.HoughTransform_o3_k[132] = -11.0;
    brain_B.HoughTransform_o3_k[133] = -10.0;
    brain_B.HoughTransform_o3_k[134] = -9.0;
    brain_B.HoughTransform_o3_k[135] = -8.0;
    brain_B.HoughTransform_o3_k[136] = -7.0;
    brain_B.HoughTransform_o3_k[137] = -6.0;
    brain_B.HoughTransform_o3_k[138] = -5.0;
    brain_B.HoughTransform_o3_k[139] = -4.0;
    brain_B.HoughTransform_o3_k[140] = -3.0;
    brain_B.HoughTransform_o3_k[141] = -2.0;
    brain_B.HoughTransform_o3_k[142] = -1.0;
    brain_B.HoughTransform_o3_k[143] = 0.0;
    brain_B.HoughTransform_o3_k[144] = 1.0;
    brain_B.HoughTransform_o3_k[145] = 2.0;
    brain_B.HoughTransform_o3_k[146] = 3.0;
    brain_B.HoughTransform_o3_k[147] = 4.0;
    brain_B.HoughTransform_o3_k[148] = 5.0;
    brain_B.HoughTransform_o3_k[149] = 6.0;
    brain_B.HoughTransform_o3_k[150] = 7.0;
    brain_B.HoughTransform_o3_k[151] = 8.0;
    brain_B.HoughTransform_o3_k[152] = 9.0;
    brain_B.HoughTransform_o3_k[153] = 10.0;
    brain_B.HoughTransform_o3_k[154] = 11.0;
    brain_B.HoughTransform_o3_k[155] = 12.0;
    brain_B.HoughTransform_o3_k[156] = 13.0;
    brain_B.HoughTransform_o3_k[157] = 14.0;
    brain_B.HoughTransform_o3_k[158] = 15.0;
    brain_B.HoughTransform_o3_k[159] = 16.0;
    brain_B.HoughTransform_o3_k[160] = 17.0;
    brain_B.HoughTransform_o3_k[161] = 18.0;
    brain_B.HoughTransform_o3_k[162] = 19.0;
    brain_B.HoughTransform_o3_k[163] = 20.0;
    brain_B.HoughTransform_o3_k[164] = 21.0;
    brain_B.HoughTransform_o3_k[165] = 22.0;
    brain_B.HoughTransform_o3_k[166] = 23.0;
    brain_B.HoughTransform_o3_k[167] = 24.0;
    brain_B.HoughTransform_o3_k[168] = 25.0;
    brain_B.HoughTransform_o3_k[169] = 26.0;
    brain_B.HoughTransform_o3_k[170] = 27.0;
    brain_B.HoughTransform_o3_k[171] = 28.0;
    brain_B.HoughTransform_o3_k[172] = 29.0;
    brain_B.HoughTransform_o3_k[173] = 30.0;
    brain_B.HoughTransform_o3_k[174] = 31.0;
    brain_B.HoughTransform_o3_k[175] = 32.0;
    brain_B.HoughTransform_o3_k[176] = 33.0;
    brain_B.HoughTransform_o3_k[177] = 34.0;
    brain_B.HoughTransform_o3_k[178] = 35.0;
    brain_B.HoughTransform_o3_k[179] = 36.0;
    brain_B.HoughTransform_o3_k[180] = 37.0;
    brain_B.HoughTransform_o3_k[181] = 38.0;
    brain_B.HoughTransform_o3_k[182] = 39.0;
    brain_B.HoughTransform_o3_k[183] = 40.0;
    brain_B.HoughTransform_o3_k[184] = 41.0;
    brain_B.HoughTransform_o3_k[185] = 42.0;
    brain_B.HoughTransform_o3_k[186] = 43.0;
    brain_B.HoughTransform_o3_k[187] = 44.0;
    brain_B.HoughTransform_o3_k[188] = 45.0;
    brain_B.HoughTransform_o3_k[189] = 46.0;
    brain_B.HoughTransform_o3_k[190] = 47.0;
    brain_B.HoughTransform_o3_k[191] = 48.0;
    brain_B.HoughTransform_o3_k[192] = 49.0;
    brain_B.HoughTransform_o3_k[193] = 50.0;
    brain_B.HoughTransform_o3_k[194] = 51.0;
    brain_B.HoughTransform_o3_k[195] = 52.0;
    brain_B.HoughTransform_o3_k[196] = 53.0;
    brain_B.HoughTransform_o3_k[197] = 54.0;
    brain_B.HoughTransform_o3_k[198] = 55.0;
    brain_B.HoughTransform_o3_k[199] = 56.0;
    brain_B.HoughTransform_o3_k[200] = 57.0;
    brain_B.HoughTransform_o3_k[201] = 58.0;
    brain_B.HoughTransform_o3_k[202] = 59.0;
    brain_B.HoughTransform_o3_k[203] = 60.0;
    brain_B.HoughTransform_o3_k[204] = 61.0;
    brain_B.HoughTransform_o3_k[205] = 62.0;
    brain_B.HoughTransform_o3_k[206] = 63.0;
    brain_B.HoughTransform_o3_k[207] = 64.0;
    brain_B.HoughTransform_o3_k[208] = 65.0;
    brain_B.HoughTransform_o3_k[209] = 66.0;
    brain_B.HoughTransform_o3_k[210] = 67.0;
    brain_B.HoughTransform_o3_k[211] = 68.0;
    brain_B.HoughTransform_o3_k[212] = 69.0;
    brain_B.HoughTransform_o3_k[213] = 70.0;
    brain_B.HoughTransform_o3_k[214] = 71.0;
    brain_B.HoughTransform_o3_k[215] = 72.0;
    brain_B.HoughTransform_o3_k[216] = 73.0;
    brain_B.HoughTransform_o3_k[217] = 74.0;
    brain_B.HoughTransform_o3_k[218] = 75.0;
    brain_B.HoughTransform_o3_k[219] = 76.0;
    brain_B.HoughTransform_o3_k[220] = 77.0;
    brain_B.HoughTransform_o3_k[221] = 78.0;
    brain_B.HoughTransform_o3_k[222] = 79.0;
    brain_B.HoughTransform_o3_k[223] = 80.0;
    brain_B.HoughTransform_o3_k[224] = 81.0;
    brain_B.HoughTransform_o3_k[225] = 82.0;
    brain_B.HoughTransform_o3_k[226] = 83.0;
    brain_B.HoughTransform_o3_k[227] = 84.0;
    brain_B.HoughTransform_o3_k[228] = 85.0;
    brain_B.HoughTransform_o3_k[229] = 86.0;
    brain_B.HoughTransform_o3_k[230] = 87.0;
    brain_B.HoughTransform_o3_k[231] = 88.0;
    brain_B.HoughTransform_o3_k[232] = 89.0;
    brain_B.HoughTransform_o3_k[233] = 90.0;
    brain_B.HoughTransform_o3_k[234] = 91.0;
    brain_B.HoughTransform_o3_k[235] = 92.0;
    brain_B.HoughTransform_o3_k[236] = 93.0;
    brain_B.HoughTransform_o3_k[237] = 94.0;
    brain_B.HoughTransform_o3_k[238] = 95.0;
    brain_B.HoughTransform_o3_k[239] = 96.0;
    brain_B.HoughTransform_o3_k[240] = 97.0;
    brain_B.HoughTransform_o3_k[241] = 98.0;
    brain_B.HoughTransform_o3_k[242] = 99.0;
    brain_B.HoughTransform_o3_k[243] = 100.0;
    brain_B.HoughTransform_o3_k[244] = 101.0;
    brain_B.HoughTransform_o3_k[245] = 102.0;
    brain_B.HoughTransform_o3_k[246] = 103.0;
    brain_B.HoughTransform_o3_k[247] = 104.0;
    brain_B.HoughTransform_o3_k[248] = 105.0;
    brain_B.HoughTransform_o3_k[249] = 106.0;
    brain_B.HoughTransform_o3_k[250] = 107.0;
    brain_B.HoughTransform_o3_k[251] = 108.0;
    brain_B.HoughTransform_o3_k[252] = 109.0;
    brain_B.HoughTransform_o3_k[253] = 110.0;
    brain_B.HoughTransform_o3_k[254] = 111.0;
    brain_B.HoughTransform_o3_k[255] = 112.0;
    brain_B.HoughTransform_o3_k[256] = 113.0;
    brain_B.HoughTransform_o3_k[257] = 114.0;
    brain_B.HoughTransform_o3_k[258] = 115.0;
    brain_B.HoughTransform_o3_k[259] = 116.0;
    brain_B.HoughTransform_o3_k[260] = 117.0;
    brain_B.HoughTransform_o3_k[261] = 118.0;
    brain_B.HoughTransform_o3_k[262] = 119.0;
    brain_B.HoughTransform_o3_k[263] = 120.0;
    brain_B.HoughTransform_o3_k[264] = 121.0;
    brain_B.HoughTransform_o3_k[265] = 122.0;
    brain_B.HoughTransform_o3_k[266] = 123.0;
    brain_B.HoughTransform_o3_k[267] = 124.0;
    brain_B.HoughTransform_o3_k[268] = 125.0;
    brain_B.HoughTransform_o3_k[269] = 126.0;
    brain_B.HoughTransform_o3_k[270] = 127.0;
    brain_B.HoughTransform_o3_k[271] = 128.0;
    brain_B.HoughTransform_o3_k[272] = 129.0;
    brain_B.HoughTransform_o3_k[273] = 130.0;
    brain_B.HoughTransform_o3_k[274] = 131.0;
    brain_B.HoughTransform_o3_k[275] = 132.0;
    brain_B.HoughTransform_o3_k[276] = 133.0;
    brain_B.HoughTransform_o3_k[277] = 134.0;
    brain_B.HoughTransform_o3_k[278] = 135.0;
    brain_B.HoughTransform_o3_k[279] = 136.0;
    brain_B.HoughTransform_o3_k[280] = 137.0;
    brain_B.HoughTransform_o3_k[281] = 138.0;
    brain_B.HoughTransform_o3_k[282] = 139.0;
    brain_B.HoughTransform_o3_k[283] = 140.0;
    brain_B.HoughTransform_o3_k[284] = 141.0;
    brain_B.HoughTransform_o3_k[285] = 142.0;
    brain_B.HoughTransform_o3_k[286] = 143.0;
  }

  /* states (dwork) */
  (void) memset((void *)&brain_DWork, 0,
                sizeof(D_Work_brain));

  /* external inputs */
  (void) memset((void *)&brain_U, 0,
                sizeof(ExternalInputs_brain));

  /* external outputs */
  (void) memset((void *)&brain_Y, 0,
                sizeof(ExternalOutputs_brain));

  /* Start for Stateflow: '<Root>/Chart' */
  brain_Chart_Start();

  /* InitializeConditions for Stateflow: '<Root>/Chart' */
  brain_Chart_Init();
}

/* Model terminate function */
extern "C"
  void brain_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
