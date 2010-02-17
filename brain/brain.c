/*
 * File: brain.c
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.197
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Wed Feb 17 18:15:29 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Wed Feb 17 18:15:30 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/Chart' */
#define brain_IN_Buoy                  (1)
#define brain_IN_ChooseState           (2)
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
static void brain_max_a(const real_T eml_varargin_1[80], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max(const real_T eml_varargin_1[120], real_T *eml_maxval,
                      real_T *eml_indx);
static void brain_c10_brain(void);

/* Forward declaration for local functions */
static void brain_max_f(const real_T eml_varargin_1[51660], real_T eml_maxval
  [180], real_T eml_indx[180]);
static void brain_max_ff(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);

/* Forward declaration for local functions */
static void brain_refp1_cos_k(real_T eml_x[19200]);
static void brain_max_k2(const real_T eml_varargin_1[160], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max_k(const real_T eml_varargin_1[120], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c5_brain(void);

/* Forward declaration for local functions */
static void brain_enter_internal_c1_brain(void);
static void brain_NotRunning(void);
static real_T brain_countareas(real_T sf_Size, real_T sf_count1);
static void brain_enter_internal_OnePath(void);
static void brain_max_h(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT);
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong);
static void brain_max_i(const real_T eml_varargin_1[71820], real_T eml_maxval
  [180], real_T eml_indx[180]);
static real_T brain_CountClose(real_T sf_Close1, real_T sf_countIN);
static void brain_OnePath(void);
static void bra_exit_internal_FollowOnePath(void);
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
 *   '<S58>/FoundTrack'
 *   '<S27>/FoundBuoy'
 */
void brain_FoundTrack(real_T *rtd_Image_c)
{
  /* DataStoreWrite: '<S59>/Data Store Write' incorporates:
   *  Constant: '<S59>/Constant'
   */
  (*rtd_Image_c) = 1.0;
}

/* Output and update for action system:
 *   '<S58>/NoTrack'
 *   '<S27>/NoBuoy'
 */
void brain_NoTrack(real_T *rtd_Image_c)
{
  /* DataStoreWrite: '<S62>/Data Store Write' incorporates:
   *  Constant: '<S62>/Constant'
   */
  (*rtd_Image_c) = 0.0;
}

/* Disable for action system:
 *   '<S14>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S10>/BigError S1'
 */
void brain_BigErrorS1_Disable(rtB_BigErrorS1_brain *localB)
{
  /* Disable for Outport: '<S64>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S14>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S10>/BigError S1'
 */
void brain_BigErrorS1(real_T rtu_In1, rtB_BigErrorS1_brain *localB)
{
  /* Sum: '<S64>/Add' incorporates:
   *  Constant: '<S64>/Constant'
   */
  localB->Add = rtu_In1 - 360.0;

  /* Constant: '<S64>/Constant1' */
  localB->Constant1 = 1.0;
}

/* Disable for action system:
 *   '<S14>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S10>/BigNegativeError S2'
 */
void brai_BigNegativeErrorS2_Disable(rtB_BigNegativeErrorS2_brain *localB)
{
  /* Disable for Outport: '<S65>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S14>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S10>/BigNegativeError S2'
 */
void brain_BigNegativeErrorS2(real_T rtu_In1, rtB_BigNegativeErrorS2_brain
  *localB)
{
  /* Sum: '<S65>/Add' incorporates:
   *  Constant: '<S65>/Constant'
   */
  localB->Add = rtu_In1 + 360.0;

  /* Constant: '<S65>/Constant1' */
  localB->Constant1 = 2.0;
}

/* Function for Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
static void brain_max_a(const real_T eml_varargin_1[80], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
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

/* Function for Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
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

  /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S41>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S41>:1:8' */
  /* '<S41>:1:10' */
  /* '<S41>:1:11' */
  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    eml_BWleft[eml_x_0] = 0;
    eml_BWright[eml_x_0] = 0;
  }

  /* '<S41>:1:14' */
  /* '<S41>:1:16' */
  for (eml_x_0 = 0; eml_x_0 < 160; eml_x_0++) {
    for (tmp = 0; tmp < 120; tmp++) {
      eml_hoistedExpr[tmp + 120 * eml_x_0] = brain_B.SFunction_o25[120 * eml_x_0
        + tmp] * 6.2831853071795862E+00 - 3.1415926535897931E-01;
    }
  }

  brain_refp1_cos(eml_hoistedExpr);
  for (eml_x_0 = 0; eml_x_0 < 19200; eml_x_0++) {
    eml_hoistedExpr[eml_x_0] = (eml_hoistedExpr[eml_x_0] + 1.0) / 2.0;
  }

  /*  Left half */
  for (eml_x = 0; eml_x < 80; eml_x++) {
    /* '<S41>:1:19' */
    /* '<S41>:1:20' */
    memcpy((void *)&eml_hoistedExpr_0[0], (void *)&eml_hoistedExpr[120 * eml_x],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_0, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o25[(((int32_T)eml_indexH - 1)
          + 120 * eml_x) + 19200] > 0.3)) {
      /* '<S41>:1:21' */
      /* '<S41>:1:22' */
      eml_BWleft[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S41>:1:26' */
    /* '<S41>:1:27' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_1[eml_x_0] = eml_hoistedExpr[120 * eml_x_0 + eml_x];
    }

    brain_max_a(eml_hoistedExpr_1, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o25[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S41>:1:28' */
      /* '<S41>:1:29' */
      eml_BWleft[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  /*  Right half */
  for (eml_x = 81; eml_x < 161; eml_x++) {
    /* '<S41>:1:34' */
    /* '<S41>:1:35' */
    eml_x_0 = eml_x - 1;
    memcpy((void *)&eml_hoistedExpr_2[0], (void *)&eml_hoistedExpr[120 * eml_x_0],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_2, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o25[((eml_x - 1) * 120 +
          ((int32_T)eml_indexH - 1)) + 19200] > 0.3)) {
      /* '<S41>:1:36' */
      /* '<S41>:1:37' */
      eml_BWright[((int32_T)eml_indexH - 1) + 120 * (eml_x - 81)] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S41>:1:41' */
    /* '<S41>:1:42' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_3[eml_x_0] = eml_hoistedExpr[(80 + eml_x_0) * 120 + eml_x];
    }

    brain_max_a(eml_hoistedExpr_3, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o25[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S41>:1:43' */
      /* '<S41>:1:44' */
      eml_BWright[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    brain_B.BWleft[eml_x_0] = (real_T)eml_BWleft[eml_x_0];
    brain_B.BWright[eml_x_0] = (real_T)eml_BWright[eml_x_0];
  }
}

/* Output and update for atomic system: '<S40>/Get Brightest Pixel Per Column and Row' */
void GetBrightestPixelPerColumnandRo(void)
{
  /* Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
  brain_c10_brain();
}

/* Function for Embedded MATLAB: '<S43>/IsLinePresent' */
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

/* Function for Embedded MATLAB: '<S43>/IsLinePresent' */
static void brain_max_ff(const real_T eml_varargin_1[180], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S43>/IsLinePresent' */
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

  /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent': '<S45>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S45>:1:5' */
  /* '<S45>:1:7' */
  /* '<S45>:1:9' */
  /* '<S45>:1:10' */
  /* '<S45>:1:11' */
  /* '<S45>:1:12' */
  /* '<S45>:1:13' */
  localB->Rho[0] = -999.0;
  localB->Theta[0] = -999.0;
  localB->maxVotes[0] = -999.0;
  localB->Rho[1] = -999.0;
  localB->Theta[1] = -999.0;
  localB->maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S45>:1:15' */
  /* '<S45>:1:17' */
  brain_max_f(&rtu_HoughTable[0], eml_maxValues, eml_RhoIndices);

  /* '<S45>:1:18' */
  brain_max_ff(eml_maxValues, &eml_b, &eml_c);

  /* '<S45>:1:18' */
  localB->maxVotes[0] = eml_b;

  /* '<S45>:1:18' */
  eml_ThetaIndex_idx = eml_c;

  /* '<S45>:1:19' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_c - 1];
  if (localB->maxVotes[0] >= 15.0) {
    /* '<S45>:1:21' */
    /* '<S45>:1:22' */
    eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 287 * ((int32_T)eml_c - 1)]
      = 0.0;

    /* '<S45>:1:24' */
    eml_index = 2;

    /* '<S45>:1:25' */
    eml_count = 0;
    while ((eml_index <= 2) && (eml_count < 12)) {
      /* '<S45>:1:26' */
      /* '<S45>:1:27' */
      eml_count++;

      /* '<S45>:1:28' */
      brain_max_f(eml_HoughTable, eml_maxValues, eml_RhoIndices);

      /* '<S45>:1:29' */
      brain_max_ff(eml_maxValues, &eml_b, &eml_c);

      /* '<S45>:1:29' */
      localB->maxVotes[1] = eml_b;

      /* '<S45>:1:29' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S45>:1:30' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S45>:1:32' */
      eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 287 * ((int32_T)eml_c -
        1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S45>:1:34' */
        /* '<S45>:1:35' */
        eml_index = 3;
      }
    }

    /* '<S45>:1:40' */
    if (localB->maxVotes[0] > 15.0) {
      /* '<S45>:1:41' */
      /* '<S45>:1:42' */
      localB->Theta[0] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx - 1];

      /* '<S45>:1:43' */
      localB->Rho[0] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx - 1];
      if ((localB->Theta[0] > 0.0) && (localB->Rho[0] < 0.0)) {
        /* '<S45>:1:44' */
        /* '<S45>:1:45' */
        localB->Rho[0] = localB->Rho[0] * -1.0;
      }
    }

    /* '<S45>:1:40' */
    if (localB->maxVotes[1] > 15.0) {
      /* '<S45>:1:41' */
      /* '<S45>:1:42' */
      localB->Theta[1] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx_0 - 1];

      /* '<S45>:1:43' */
      localB->Rho[1] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx_0 - 1];
      if ((localB->Theta[1] > 0.0) && (localB->Rho[1] < 0.0)) {
        /* '<S45>:1:44' */
        /* '<S45>:1:45' */
        localB->Rho[1] = localB->Rho[1] * -1.0;
      }
    }
  }
}

/* Output and update for atomic system:
 *   '<S43>/IsLinePresent'
 *   '<S44>/IsLinePresent'
 */
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  /* Embedded MATLAB: '<S43>/IsLinePresent' */
  brain_c11_brain(rtu_HoughTable, rtu_ThetaValues, rtu_RhoValues, localB);
}

/* Function for Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos_k(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
static void brain_max_k2(const real_T eml_varargin_1[160], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
static void brain_max_k(const real_T eml_varargin_1[120], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
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

  /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S54>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S54>:1:7' */
  memset(&eml_BooleanImage[0], (uint32_T)0, 19200U * sizeof(int8_T));

  /* '<S54>:1:10' */
  /* '<S54>:1:12' */
  for (tmp = 0; tmp < 160; tmp++) {
    for (eml_x = 0; eml_x < 120; eml_x++) {
      eml_hoistedExpr[eml_x + 120 * tmp] = brain_B.SFunction_o29[120 * tmp +
        eml_x] * 6.2831853071795862E+00 - 3.1415926535897931E-01;
    }
  }

  brain_refp1_cos_k(eml_hoistedExpr);
  for (tmp = 0; tmp < 19200; tmp++) {
    eml_hoistedExpr[tmp] = (eml_hoistedExpr[tmp] + 1.0) / 2.0;
  }

  for (eml_x = 0; eml_x < 160; eml_x++) {
    /* '<S54>:1:14' */
    /* '<S54>:1:15' */
    memcpy((void *)&eml_hoistedExpr_0[0], (void *)&eml_hoistedExpr[120 * eml_x],
           120U * sizeof(real_T));
    brain_max_k(eml_hoistedExpr_0, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o29[(((int32_T)eml_indexH - 1)
          + 120 * eml_x) + 19200] > 0.3)) {
      /* '<S54>:1:16' */
      /* '<S54>:1:17' */
      eml_BooleanImage[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S54>:1:21' */
    /* '<S54>:1:22' */
    for (tmp = 0; tmp < 160; tmp++) {
      eml_hoistedExpr_1[tmp] = eml_hoistedExpr[120 * tmp + eml_x];
    }

    brain_max_k2(eml_hoistedExpr_1, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (brain_B.SFunction_o29[(((int32_T)eml_indexH - 1) *
          120 + eml_x) + 19200] > 0.3)) {
      /* '<S54>:1:23' */
      /* '<S54>:1:24' */
      eml_BooleanImage[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (tmp = 0; tmp < 19200; tmp++) {
    brain_B.BooleanImage[tmp] = (real_T)eml_BooleanImage[tmp];
  }
}

/* Output and update for atomic system: '<S53>/Get Brightest Pixel Per Column and Row' */
void GetBrightestPixelPerColumnand_d(void)
{
  /* Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
  brain_c5_brain();
}

/* Initial conditions for function-call system: '<Root>/Chart' */
void RunningFollowOnePathOnePat_Init(RT_MODEL_brain *brain_M,
  rtDW_RunningFollowOnePathOnePat *localDW)
{
  localDW->RunningFollowOnePathOnePathMa_c = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/Chart' */
void RunningFollowOnePathOnePathMain(real32_T rtu_DesiredDepth1, real32_T
  rtu_CurrentDepth1, RT_MODEL_brain *brain_M, rtB_RunningFollowOnePathOnePath
  *localB, rtDW_RunningFollowOnePathOnePat *localDW)
{
  /* local block i/o variables */
  real_T rtb_TSamp_k;
  real_T rtb_Sum_f;

  {
    real_T rtb_Add;
    real_T rtb_DepthProportionalGain_b;
    int8_T tmp;
    localDW->RunningFollowOnePathOnePathMa_k = brain_M->Timing.clockTick0 -
      localDW->RunningFollowOnePathOnePathMa_c;
    localDW->RunningFollowOnePathOnePathMa_c = brain_M->Timing.clockTick0;

    /* Sum: '<S9>/Add' */
    rtb_Add = (real_T)rtu_DesiredDepth1 - (real_T)rtu_CurrentDepth1;

    /* Gain: '<S47>/Depth Proportional Gain' */
    rtb_DepthProportionalGain_b = brain_P.Depth_Kp * rtb_Add;

    /* Gain: '<S47>/Depth Derivative Gain' */
    rtb_Sum_f = brain_P.Depth_Kd * rtb_Add;

    /* S-Function (sfix_tsampmath): '<S48>/TSamp' */

    /* Sample Time Math Block: '<S48>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_k = rtb_Sum_f / (((localDW->RunningFollowOnePathOnePathMa_k * 0.02))*
                               (1.0));

    /* DiscreteIntegrator: '<S47>/Depth Discrete-Time Integrator' */
    rtb_Sum_f = localDW->DepthDiscreteTimeIntegrator_DST;

    /* Sum: '<S47>/Sum' incorporates:
     *  Sum: '<S48>/Diff'
     *  UnitDelay: '<S48>/UD'
     */
    rtb_Sum_f += (rtb_TSamp_k - localDW->UD_DSTATE) +
      rtb_DepthProportionalGain_b;

    /* DataTypeConversion: '<S9>/Double To Int8' */
    rtb_DepthProportionalGain_b = floor(rtb_Sum_f);
    if (rtb_DepthProportionalGain_b < 128.0) {
      if (rtb_DepthProportionalGain_b >= -128.0) {
        tmp = (int8_T)rtb_DepthProportionalGain_b;
      } else {
        tmp = MIN_int8_T;
      }
    } else {
      tmp = MAX_int8_T;
    }

    localB->DoubleToInt8 = tmp;

    /* Update for UnitDelay: '<S48>/UD' */
    localDW->UD_DSTATE = rtb_TSamp_k;

    /* Update for DiscreteIntegrator: '<S47>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S47>/Depth Integral Gain'
     */
    localDW->DepthDiscreteTimeIntegrator_DST = 0.02 * (real_T)
      localDW->RunningFollowOnePathOnePathMa_k * (brain_P.Depth_Ki * rtb_Add) +
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
void RunningFollowOnePathMakeHSVImag(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_RunningFollowOnePathMakeHSV
  *localB)
{
  {
    int32_T i;

    /* Embedded MATLAB: '<S6>/PutHSVImageTogether' */
    /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S39>:1' */
    /*  This function simply makes an HSV image a single multidimensional */
    /*  signal */
    /* '<S39>:1:7' */
    memset(&localB->HSVImage1[0], (uint32_T)0.0, 57600U * sizeof(real_T));

    /* '<S39>:1:9' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[120 * i]), (void *)(&rtu_H1[120 * i]),
             120U * sizeof(real_T));
    }

    /* '<S39>:1:10' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[19200 + 120 * i]), (void *)(&rtu_S1[120
              * i]), 120U * sizeof(real_T));
    }

    /* '<S39>:1:11' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[38400 + 120 * i]), (void *)(&rtu_V1[120
              * i]), 120U * sizeof(real_T));
    }
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_enter_internal_c1_brain(void)
{
  /* Transition: '<S1>:295' */
  /* Entry 'NotRunning': '<S1>:291' */
  brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
  brain_B.Left = 0;
  brain_B.Right = 0;
  brain_B.Vertical = 0;
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_NotRunning(void)
{
  /* During 'NotRunning': '<S1>:291' */
  if (brain_U.Status == 1) {
    /* Transition: '<S1>:293' */
    /* Exit 'NotRunning': '<S1>:291' */
    /* Entry 'Running': '<S1>:289' */
    brain_DWork.is_c1_brain = (uint8_T)brain_IN_Running;

    /* Transition: '<S1>:161' */
    /* Entry 'Start': '<S1>:153' */
    brain_DWork.is_Running = (uint8_T)brain_IN_Start;
    brain_DWork.OldHeading = 0.0;
    brain_DWork.DesiredHeadingCount = 0.0;
    brain_B.BuoyCentroidX = 0.0;
    brain_B.BuoyCentroidY = 0.0;
    brain_B.CameraPosition = 2;
    brain_B.State = 1U;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static real_T brain_countareas(real_T sf_Size, real_T sf_count1)
{
  /* Embedded MATLAB Function 'countareas': '<S1>:83' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  area is recognized by the recognition software */
  if (sf_Size > 8500.0) {
    /* '<S1>:83:6' */
    /* '<S1>:83:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S1>:83:9' */
    return 0.0;
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

/* Function for Embedded MATLAB: '<S55>/IsLinePresent' */
static void brain_max_i(const real_T eml_varargin_1[71820], real_T eml_maxval
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
  real_T rtb_Add1;
  real_T rtb_TSamp;
  real_T rtb_Theta[2];
  real_T rtb_Rho[2];
  real_T rtb_TmpHiddenBufferAtSFunctionI[4];
  real_T rtb_TmpHiddenBufferAtSFunctio_j[4];
  real_T rtb_Add4;
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
        brain_B.SFunction_o37[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o38[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o39[i] = (real_T)brain_B.Resize2[i];
      }

      RunningFollowOnePathMakeHSVImag(brain_B.SFunction_o37,
        brain_B.SFunction_o38, brain_B.SFunction_o39,
        &brain_B.RunningFollowOnePathMakeHSVIm_f);

      /* Simulink Function 'GetBrightestPixel_VerticalSplit': '<S1>:333' */
      memcpy((void *)&brain_B.SFunction_o25[0], (void *)
             &brain_B.RunningFollowOnePathMakeHSVIm_f.HSVImage1[0], 57600U *
             sizeof(real_T));

      /* Embedded MATLAB: '<S40>/Get Brightest Pixel Per Column and Row' */
      GetBrightestPixelPerColumnandRo();
      for (i = 0; i < 9600; i++) {
        /* DataTypeConversion: '<S40>/Data Type Conversion' */
        brain_B.DataTypeConversion_f[i] = (brain_B.BWleft[i] != 0.0);

        /* DataTypeConversion: '<S40>/Data Type Conversion1' */
        brain_B.DataTypeConversion1[i] = (brain_B.BWright[i] != 0.0);
      }

      /* Simulink Function 'GetHeadings': '<S1>:350' */
      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o26[i] = (brain_B.DataTypeConversion_f[i] != 0);
      }

      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o27[i] = (brain_B.DataTypeConversion1[i] != 0);
      }

      brain_B.SFunction_o28 = brain_U.CurrentHeading;

      /* S-Function (sviphough): '<S43>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o26[0], &brain_B.HoughTransform_o1_d[0],
                    &brain_ConstP.pooled11[0], &brain_ConstP.pooled12, 120, 80,
                    287, 91);

      /* Embedded MATLAB: '<S43>/IsLinePresent' */
      brain_IsLinePresent(brain_B.HoughTransform_o1_d,
                          brain_B.HoughTransform_o2_j,
                          brain_B.HoughTransform_o3_d, &brain_B.sf_IsLinePresent);

      /* S-Function (sviphough): '<S44>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o27[0], &brain_B.HoughTransform_o1_dv[0],
                    &brain_ConstP.pooled11[0], &brain_ConstP.pooled12, 120, 80,
                    287, 91);

      /* Embedded MATLAB: '<S44>/IsLinePresent' */
      brain_IsLinePresent(brain_B.HoughTransform_o1_dv,
                          brain_B.HoughTransform_o2_h,
                          brain_B.HoughTransform_o3_j,
                          &brain_B.sf_IsLinePresent_l);

      /* SignalConversion: '<S42>/TmpHiddenBufferAt SFunction Inport1' */
      rtb_TmpHiddenBufferAtSFunctionI[0] = brain_B.sf_IsLinePresent.Theta[0];
      rtb_TmpHiddenBufferAtSFunctionI[1] = brain_B.sf_IsLinePresent.Theta[1];

      /* SignalConversion: '<S42>/TmpHiddenBufferAt SFunction Inport3' */
      rtb_TmpHiddenBufferAtSFunctionI[2] = brain_B.sf_IsLinePresent_l.Theta[0];
      rtb_TmpHiddenBufferAtSFunctio_j[0] = brain_B.sf_IsLinePresent.maxVotes[0];
      rtb_TmpHiddenBufferAtSFunctionI[3] = brain_B.sf_IsLinePresent_l.Theta[1];
      rtb_TmpHiddenBufferAtSFunctio_j[1] = brain_B.sf_IsLinePresent.maxVotes[1];
      rtb_TmpHiddenBufferAtSFunctio_j[2] = brain_B.sf_IsLinePresent_l.maxVotes[0];
      rtb_TmpHiddenBufferAtSFunctio_j[3] = brain_B.sf_IsLinePresent_l.maxVotes[1];

      /* Embedded MATLAB: '<S8>/GetHeadingToPath' */
      eml_Votes[0] = rtb_TmpHiddenBufferAtSFunctio_j[0];
      eml_Votes[1] = rtb_TmpHiddenBufferAtSFunctio_j[1];
      eml_Votes[2] = rtb_TmpHiddenBufferAtSFunctio_j[2];
      eml_Votes[3] = rtb_TmpHiddenBufferAtSFunctio_j[3];

      /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath': '<S42>:1' */
      /*  This function calculates the heading to the path from Theta and Rho */
      /* '<S42>:1:4' */
      /* '<S42>:1:6' */
      /* '<S42>:1:7' */
      /* '<S42>:1:8' */
      brain_B.ToPathHeading[0] = -999.0;
      brain_B.AlongPathHeading[0] = -999.0;
      eml_maxIndex[0] = -999.0;
      brain_B.ToPathHeading[1] = -999.0;
      brain_B.AlongPathHeading[1] = -999.0;
      eml_maxIndex[1] = -999.0;

      /* '<S42>:1:11' */
      brain_max_h(rtb_TmpHiddenBufferAtSFunctio_j, &eml_b, &eml_c);

      /* '<S42>:1:11' */
      eml_maxIndex[0] = eml_c;

      /* '<S42>:1:12' */
      eml_Votes[(int32_T)eml_maxIndex[0] - 1] = 0.0;

      /* '<S42>:1:13' */
      /* '<S42>:1:15' */
      /* '<S42>:1:16' */
      /* '<S42>:1:17' */
      brain_max_h(eml_Votes, &eml_b, &eml_c);

      /* '<S42>:1:17' */
      eml_maxIndex[1] = eml_c;

      /* '<S42>:1:18' */
      /* '<S42>:1:21' */
      if (eml_maxIndex[0] <= 2.0) {
        /* '<S42>:1:22' */
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[0] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[0] - 1] < 1.5707963267948966E+00)) {
          /* '<S42>:1:23' */
          /* '<S42>:1:24' */
          brain_B.ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28) - 90.0;

          /* '<S42>:1:25' */
          brain_B.AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28;
        }
      } else {
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[0] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[0] - 1] < 1.5707963267948966E+00)) {
          /* '<S42>:1:28' */
          /* '<S42>:1:29' */
          brain_B.ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28) + 90.0;

          /* '<S42>:1:30' */
          brain_B.AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[0] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28;
        }
      }

      /* '<S42>:1:35' */
      if (brain_B.ToPathHeading[0] != -999.0) {
        /* '<S42>:1:36' */
        if (brain_B.ToPathHeading[0] < 0.0) {
          /* '<S42>:1:37' */
          /* '<S42>:1:38' */
          brain_B.ToPathHeading[0] = brain_B.ToPathHeading[0] + 360.0;
        } else {
          if (brain_B.ToPathHeading[0] > 360.0) {
            /* '<S42>:1:39' */
            /* '<S42>:1:40' */
            brain_B.ToPathHeading[0] = brain_B.ToPathHeading[0] - 360.0;
          }
        }

        if (brain_B.AlongPathHeading[0] < 0.0) {
          /* '<S42>:1:43' */
          /* '<S42>:1:44' */
          brain_B.AlongPathHeading[0] = brain_B.AlongPathHeading[0] + 360.0;
        } else {
          if (brain_B.AlongPathHeading[0] > 360.0) {
            /* '<S42>:1:45' */
            /* '<S42>:1:46' */
            brain_B.AlongPathHeading[0] = brain_B.AlongPathHeading[0] - 360.0;
          }
        }
      }

      /* '<S42>:1:21' */
      if (eml_maxIndex[1] <= 2.0) {
        /* '<S42>:1:22' */
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[1] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[1] - 1] < 1.5707963267948966E+00)) {
          /* '<S42>:1:23' */
          /* '<S42>:1:24' */
          brain_B.ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28) - 90.0;

          /* '<S42>:1:25' */
          brain_B.AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28;
        }
      } else {
        if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex[1] - 1] >
             -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI
             [(int32_T)eml_maxIndex[1] - 1] < 1.5707963267948966E+00)) {
          /* '<S42>:1:28' */
          /* '<S42>:1:29' */
          brain_B.ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28) + 90.0;

          /* '<S42>:1:30' */
          brain_B.AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
            eml_maxIndex[1] - 1] * 180.0 / 3.1415926535897931E+00 +
            brain_B.SFunction_o28;
        }
      }

      /* '<S42>:1:35' */
      if (brain_B.ToPathHeading[1] != -999.0) {
        /* '<S42>:1:36' */
        if (brain_B.ToPathHeading[1] < 0.0) {
          /* '<S42>:1:37' */
          /* '<S42>:1:38' */
          brain_B.ToPathHeading[1] = brain_B.ToPathHeading[1] + 360.0;
        } else {
          if (brain_B.ToPathHeading[1] > 360.0) {
            /* '<S42>:1:39' */
            /* '<S42>:1:40' */
            brain_B.ToPathHeading[1] = brain_B.ToPathHeading[1] - 360.0;
          }
        }

        if (brain_B.AlongPathHeading[1] < 0.0) {
          /* '<S42>:1:43' */
          /* '<S42>:1:44' */
          brain_B.AlongPathHeading[1] = brain_B.AlongPathHeading[1] + 360.0;
        } else {
          if (brain_B.AlongPathHeading[1] > 360.0) {
            /* '<S42>:1:45' */
            /* '<S42>:1:46' */
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
      brain_B.SFunction_o33 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o34 = (real32_T)brain_B.DesiredDepth;
      RunningFollowOnePathOnePathMain(brain_B.SFunction_o34,
        brain_B.SFunction_o33, brain_M, &brain_B.RunningFollowOnePathOnePathMa_m,
        &brain_DWork.RunningFollowOnePathOnePathMa_m);
      brain_B.Vertical = brain_B.RunningFollowOnePathOnePathMa_m.DoubleToInt8;
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
        brain_B.SFunction_o37[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o38[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o39[i] = (real_T)brain_B.Resize2[i];
      }

      RunningFollowOnePathMakeHSVImag(brain_B.SFunction_o37,
        brain_B.SFunction_o38, brain_B.SFunction_o39,
        &brain_B.RunningFollowOnePathMakeHSVIm_f);
      memcpy((void *)&sf_HSVImage[0], (void *)
             &brain_B.RunningFollowOnePathMakeHSVIm_f.HSVImage1[0], 57600U *
             sizeof(real_T));

      /* Simulink Function 'MaintainDepth': '<S1>:370' */
      brain_B.SFunction_o33 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o34 = (real32_T)brain_B.DesiredDepth;
      RunningFollowOnePathOnePathMain(brain_B.SFunction_o34,
        brain_B.SFunction_o33, brain_M, &brain_B.RunningFollowOnePathOnePathMa_m,
        &brain_DWork.RunningFollowOnePathOnePathMa_m);
      brain_B.Vertical = brain_B.RunningFollowOnePathOnePathMa_m.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S1>:374' */
      brain_B.SFunction_o35 = brain_B.DesiredHeading;
      brain_B.SFunction_o36 = brain_U.CurrentHeading;
      brain_DWork.RunningFollowOnePathOnePathMa_b = brain_M->Timing.clockTick0 -
        brain_DWork.RunningFollowOnePathOnePathMa_e;
      brain_DWork.RunningFollowOnePathOnePathMa_e = brain_M->Timing.clockTick0;

      /* Sum: '<S10>/Add1' */
      rtb_Add1 = brain_B.SFunction_o35 - brain_B.SFunction_o36;

      /* If: '<S10>/If' incorporates:
       *  ActionPort: '<S49>/Action Port'
       *  ActionPort: '<S50>/Action Port'
       *  SubSystem: '<S10>/BigError S1'
       *  SubSystem: '<S10>/BigNegativeError S2'
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
          brain_BigErrorS1_Disable(&brain_B.BigErrorS1_e);
          break;

         case 1:
          brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);
          break;
        }
      }

      switch (rtAction) {
       case 0:
        brain_BigErrorS1(rtb_Add1, &brain_B.BigErrorS1_e);
        break;

       case 1:
        brain_BigNegativeErrorS2(rtb_Add1, &brain_B.BigNegativeErrorS2_a);
        break;
      }

      /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Sum: '<S10>/Add2'
       */
      switch ((int32_T)((1.0 + brain_B.BigErrorS1_e.Constant1) +
                        brain_B.BigNegativeErrorS2_a.Constant1)) {
       case 1:
        eml_b = rtb_Add1;
        break;

       case 2:
        eml_b = brain_B.BigErrorS1_e.Add;
        break;

       default:
        eml_b = brain_B.BigNegativeErrorS2_a.Add;
        break;
      }

      /* Gain: '<S51>/Heading Proportional Gain' */
      eml_c = brain_P.Heading_Kp * eml_b;

      /* Gain: '<S51>/Heading Derivative Gain' */
      rtb_Add4 = brain_P.Heading_Kd * eml_b;

      /* S-Function (sfix_tsampmath): '<S52>/TSamp' */

      /* Sample Time Math Block: '<S52>/TSamp'
       *
       * y = u * K     where     K = 1 / ( w * Ts )
       *
       * Input0  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * ElapsedTime Data Type:  Floating Point real_T
       */
      rtb_TSamp = rtb_Add4 / (((brain_DWork.RunningFollowOnePathOnePathMa_b *
        0.02))*(1.0));

      /* DiscreteIntegrator: '<S51>/Heading Discrete-Time Integrator' */
      rtb_Add4 = brain_DWork.HeadingDiscreteTimeIntegrator_D;

      /* Sum: '<S51>/Sum' incorporates:
       *  Sum: '<S52>/Diff'
       *  UnitDelay: '<S52>/UD'
       */
      rtb_Add4 += (rtb_TSamp - brain_DWork.UD_DSTATE) + eml_c;

      /* Product: '<S10>/Multiply' incorporates:
       *  Constant: '<S10>/Constant'
       */
      eml_c = -rtb_Add4;
      if (rtIsNaN(eml_c) || rtIsInf(eml_c)) {
        eml_c = 0.0;
      } else {
        eml_c = fmod(floor(eml_c), 256.0);
      }

      /* Sum: '<S10>/Add4' incorporates:
       *  Constant: '<S10>/Heading_Forward_Velocity'
       */
      rtb_Add4 += brain_P.Heading_Forward_Velocity;

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

      brain_B.DoubleToint1 = rtPrevAction;

      /* DataTypeConversion: '<S10>/DoubleToint8' */
      eml_c = floor(rtb_Add4);
      if (eml_c < 128.0) {
        if (eml_c >= -128.0) {
          rtPrevAction = (int8_T)eml_c;
        } else {
          rtPrevAction = MIN_int8_T;
        }
      } else {
        rtPrevAction = MAX_int8_T;
      }

      brain_B.DoubleToint8 = rtPrevAction;

      /* Update for UnitDelay: '<S52>/UD' */
      brain_DWork.UD_DSTATE = rtb_TSamp;

      /* Update for DiscreteIntegrator: '<S51>/Heading Discrete-Time Integrator' incorporates:
       *  Gain: '<S51>/Heading Integral Gain'
       */
      brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.02 * (real_T)
        brain_DWork.RunningFollowOnePathOnePathMa_b * (brain_P.Heading_Ki *
        eml_b) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
      if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
      } else {
        if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
        }
      }

      brain_B.Left = brain_B.DoubleToint8;
      brain_B.Right = brain_B.DoubleToint1;

      /* Simulink Function 'GetBrightestPixel': '<S1>:357' */
      memcpy((void *)&brain_B.SFunction_o29[0], (void *)&sf_HSVImage[0], 57600U *
             sizeof(real_T));

      /* Embedded MATLAB: '<S53>/Get Brightest Pixel Per Column and Row' */
      GetBrightestPixelPerColumnand_d();

      /* DataTypeConversion: '<S53>/Data Type Conversion' */
      for (i = 0; i < 19200; i++) {
        brain_B.DataTypeConversion_a[i] = (brain_B.BooleanImage[i] != 0.0);
      }

      /* Simulink Function 'IsAUVonPathLine': '<S1>:364' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o30[i] = (brain_B.DataTypeConversion_a[i] != 0);
      }

      brain_B.SFunction_o31 = brain_DWork.HeadingAlongPath;
      brain_B.SFunction_o32 = brain_U.CurrentHeading;

      /* S-Function (sviphough): '<S55>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.SFunction_o30[0], &brain_B.HoughTransform_o1[0],
                    &brain_ConstP.pooled11[0],
                    &brain_ConstP.HoughTransform_FIRSTRHO_RT, 120, 160, 399, 91);

      /* Embedded MATLAB: '<S55>/IsLinePresent' */
      /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff/IsLinePresent': '<S57>:1' */
      /*  This function takes a Hough/hash table as input and  determines if a line */
      /*  is present and if so what its Rho and Theta are. */
      /* '<S57>:1:6' */
      /* '<S57>:1:8' */
      /* '<S57>:1:9' */
      /* '<S57>:1:10' */
      /* '<S57>:1:11' */
      /* '<S57>:1:12' */
      rtb_Rho[0] = -999.0;
      rtb_Theta[0] = -999.0;
      eml_maxIndex[0] = -999.0;
      rtb_Rho[1] = -999.0;
      rtb_Theta[1] = -999.0;
      eml_maxIndex[1] = -999.0;

      /* '<S57>:1:15' */
      memcpy((void *)&tmp[0], (void *)&brain_B.HoughTransform_o1[0], 71820U *
             sizeof(real_T));
      brain_max_i(tmp, eml_maxValues, eml_RhoIndices);

      /* '<S57>:1:16' */
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

      /* '<S57>:1:16' */
      eml_maxIndex[0] = eml_b;

      /* '<S57>:1:16' */
      eml_ThetaIndex_idx = (int16_T)i;

      /* '<S57>:1:17' */
      /* '<S57>:1:19' */
      if (eml_maxIndex[0] > 15.0) {
        /* '<S57>:1:21' */
        /* '<S57>:1:32' */
        if (eml_maxIndex[0] > 15.0) {
          /* '<S57>:1:33' */
          /* '<S57>:1:34' */
          rtb_Theta[0] = brain_B.HoughTransform_o2[eml_ThetaIndex_idx - 1];

          /* '<S57>:1:35' */
          rtb_Rho[0] = brain_B.HoughTransform_o3[(int32_T)
            eml_RhoIndices[eml_ThetaIndex_idx - 1] - 1];
          if ((rtb_Theta[0] > 0.0) && (rtb_Rho[0] < 0.0)) {
            /* '<S57>:1:36' */
            /* '<S57>:1:37' */
            rtb_Rho[0] *= -1.0;
          }
        }

        /* '<S57>:1:32' */
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
      /* Embedded MATLAB Function 'Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/IsLineNearCenter': '<S56>:1' */
      /*  Given 2 points, determine if the line has a point near the center of */
      /*  the image */
      /* '<S56>:1:8' */
      /* '<S56>:1:10' */
      eml_b = -999.0;

      /* '<S56>:1:12' */
      if (rtb_Theta[0] != -999.0) {
        /* '<S56>:1:13' */
        /* '<S56>:1:14' */
        eml_c = rtb_Theta[0] * 180.0 / 3.1415926535897931E+00 +
          brain_B.SFunction_o32;
        if (eml_c > 360.0) {
          /* '<S56>:1:15' */
          /* '<S56>:1:16' */
          eml_c -= 360.0;
        } else {
          if (eml_c < 0.0) {
            /* '<S56>:1:17' */
            /* '<S56>:1:18' */
            eml_c += 360.0;
          }
        }

        if (fabs(eml_c - brain_B.SFunction_o31) < 10.0) {
          /* '<S56>:1:21' */
          /* '<S56>:1:22' */
          /* '<S56>:1:23' */
          /* '<S56>:1:24' */
          /* '<S56>:1:25' */
          /*  y=mx+b */
          /*  x=(y-b)/m */
          /* '<S56>:1:29' */
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
            /* '<S56>:1:30' */
            /* '<S56>:1:31' */
            eml_exitg = 1;
          }

          /* '<S56>:1:33' */
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

          /* '<S56>:1:34' */
          /* '<S56>:1:36' */
          /* '<S56>:1:38' */
          eml_b = (((real_T)brain_B.HoughLines[2] - eml_b * (real_T)
                    brain_B.HoughLines[3]) + eml_b * 80.0) - 60.0;
        }
      }

      /* '<S56>:1:12' */
      if (rtb_Theta[1] != -999.0) {
        /* '<S56>:1:13' */
        /* '<S56>:1:14' */
        eml_c = rtb_Theta[1] * 180.0 / 3.1415926535897931E+00 +
          brain_B.SFunction_o32;
        if (eml_c > 360.0) {
          /* '<S56>:1:15' */
          /* '<S56>:1:16' */
          eml_c -= 360.0;
        } else {
          if (eml_c < 0.0) {
            /* '<S56>:1:17' */
            /* '<S56>:1:18' */
            eml_c += 360.0;
          }
        }

        if (fabs(eml_c - brain_B.SFunction_o31) < 10.0) {
          /* '<S56>:1:21' */
          /* '<S56>:1:22' */
          /* '<S56>:1:23' */
          /* '<S56>:1:24' */
          /* '<S56>:1:25' */
          /*  y=mx+b */
          /*  x=(y-b)/m */
          /* '<S56>:1:29' */
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
            /* '<S56>:1:30' */
            /* '<S56>:1:31' */
            eml_exitg = 1;
          }

          /* '<S56>:1:33' */
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

          /* '<S56>:1:34' */
          /* '<S56>:1:36' */
          /* '<S56>:1:38' */
          eml_b = (((real_T)brain_B.HoughLines[6] - eml_b * (real_T)
                    brain_B.HoughLines[7]) + eml_b * 80.0) - 60.0;
        }
      }

      if ((eml_b < 50.0) && (eml_b > -50.0)) {
        /* '<S56>:1:43' */
        /* '<S56>:1:44' */
        brain_B.Close = 1.0;
      } else {
        /* '<S56>:1:46' */
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
    brain_DWork.If_ActiveSubsystem = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_e);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_e);

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_a);

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */
    brain_DWork.is_FollowOnePath = (uint8_T)0;
  } else {
    /* Exit 'Initialize': '<S1>:379' */
  }
}

/* Initial conditions for atomic system: '<Root>/Chart' */
void brain_Chart_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/Chart' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Running.Buoy.Buoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainDepth'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainHeading'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
   *  InitializeConditions for SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
   *  InitializeConditions for SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
   */
  brain_DWork.is_Running = 0U;
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
  brain_B.Vertical = 0;
  brain_B.DesiredDepth = 0.0;
  brain_B.DesiredHeading = 0.0;
  brain_B.CameraPosition = 0;
  brain_B.BuoyCentroidX = 0.0;
  brain_B.BuoyCentroidY = 0.0;
  brain_B.State = 0U;
  brain_DWork.RunningValidationGateStraight_g = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S68>/UD' */
  brain_DWork.UD_DSTATE_n = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

  /* InitializeConditions for UnitDelay: '<S69>/UD' */
  brain_DWork.UD_DSTATE_b = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
  brain_DWork.RunningBuoyBuoy_PREV_T = brain_M->Timing.clockTick0;
  brain_DWork.RunningFindBuoyStraightLevelC_j = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S37>/UD' */
  brain_DWork.UD_DSTATE_e = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

  /* InitializeConditions for UnitDelay: '<S38>/UD' */
  brain_DWork.UD_DSTATE_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
  RunningFollowOnePathOnePat_Init(brain_M,
    &brain_DWork.RunningFollowOnePathOnePathMa_m);
  brain_DWork.RunningFollowOnePathOnePathMa_e = brain_M->Timing.clockTick0;
}

/* Start for atomic system: '<Root>/Chart' */
void brain_Chart_Start(void)
{
  /* Start for Stateflow: '<Root>/Chart' incorporates:
   *  Start for SubSystem: '<S1>/Running.Buoy.Buoy'
   *  Start for SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
   *  Start for SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.MakeHSVImage'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainDepth'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainHeading'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
   *  Start for SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
   *  Start for SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
   *  Start for SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
   */

  /* Start for If: '<S14>/If' */
  brain_DWork.If_ActiveSubsystem_o = -1;

  /* Start for If: '<S5>/If' */
  brain_DWork.If_ActiveSubsystem_h = -1;

  /* Start for If: '<S10>/If' */
  brain_DWork.If_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<Root>/Chart' */
void brain_Chart(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp_e;
  real_T rtb_Add1_j;
  real_T rtb_TSamp_i;
  real_T rtb_TSamp_g;
  real_T rtb_TSamp_iq;
  real_T rtb_TSamp_n;
  real_T rtb_Add1_m;
  real_T rtb_TSamp_c;
  real_T rtb_MultiportSwitch_k;
  real_T rtb_Sum;
  real_T rtb_MultiportSwitch_o;
  real_T rtb_Add4_h;
  real_T rtb_Error;
  real_T rtb_Add4_g;

  /* local scratch DWork variables */
  real_T MedianFilterRed_WorkVector[27];
  real_T MedianFilterGreen_WorkVector[27];

  {
    real_T sf_Obstacle;
    int8_T rtAction;
    uint32_T BlobAnalysis_NUM_PIX_DW;
    real32_T ys;
    real32_T xys;
    real32_T uyy;
    real32_T rtb_BlobAnalysis_o1;
    real32_T rtb_BlobAnalysis_o2;
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
    real_T rtb_XBuoyProportionalGain;
    real_T rtb_YBuoyProportionalGain;
    int32_T rtb_BuoyBlobAnalysis_o1[10];
    real_T rtb_BuoyBlobAnalysis_o2[20];
    int32_T i_0;
    real32_T centroid_idx;
    real32_T centroid_idx_0;
    int8_T rtb_DataTypeConversion_0;
    int64m_T tmp;
    int64m_T tmp_0;
    int64m_T tmp_1;
    int64m_T tmp_2;
    int64m_T tmp_3;

    /* Stateflow: '<Root>/Chart' incorporates:
     *  Inport: '<Root>/CurrentDepth'
     *  Inport: '<Root>/CurrentHeading'
     *  Inport: '<Root>/DesiredState'
     *  Inport: '<Root>/Status'
     *  SubSystem: '<S1>/Running.Buoy.Buoy'
     *  SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
     *  SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
     *  SubSystem: '<S1>/Running.FollowOnePath.MakeHSVImage'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.GetDirections.GetHeadings'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainDepth'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.MaintainHeading'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel'
     *  SubSystem: '<S1>/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine'
     *  SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
     *  SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
     */
    /* Gateway: Chart */
    /* During: Chart */
    if (brain_DWork.is_active_c1_brain == 0) {
      /* Entry: Chart */
      brain_DWork.is_active_c1_brain = 1U;
      brain_enter_internal_c1_brain();
    } else {
      switch (brain_DWork.is_c1_brain) {
       case brain_IN_NotRunning:
        brain_NotRunning();
        break;

       case brain_IN_Running:
        /* During 'Running': '<S1>:289' */
        if (brain_U.Status != 1) {
          /* Transition: '<S1>:292' */
          switch (brain_DWork.is_Running) {
           case brain_IN_Buoy:
            /* Exit 'Buoy': '<S1>:58' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           case brain_IN_FindBuoy:
            /* Exit 'FindBuoy': '<S1>:239' */

            /* Disable for If: '<S5>/If' */
            brain_DWork.If_ActiveSubsystem_h = -1;
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

            /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);

            /* end of Disable for SubSystem: '<S5>/BigError S1' */

            /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

            /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           case brain_IN_FollowOnePath:
            bra_exit_internal_FollowOnePath();

            /* Exit 'FollowOnePath': '<S1>:325' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           case brain_IN_Start:
            /* Exit 'Start': '<S1>:153' */
            brain_B.DesiredHeading = brain_U.CurrentHeading;
            brain_DWork.is_Running = (uint8_T)0;
            break;

           case brain_IN_ValidationGate:
            /* Exit 'ValidationGate': '<S1>:1' */

            /* Disable for If: '<S14>/If' */
            brain_DWork.If_ActiveSubsystem_o = -1;
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

            /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
            brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

            /* end of Disable for SubSystem: '<S14>/BigError S1' */

            /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
            brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

            /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */
            brain_DWork.is_Running = (uint8_T)0;
            break;

           default:
            /* Exit 'ChooseState': '<S1>:299' */
            /* Exit 'Finish': '<S1>:151' */
            break;
          }

          /* Exit 'Running': '<S1>:289' */
          /* Entry 'NotRunning': '<S1>:291' */
          brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
          brain_B.Left = 0;
          brain_B.Right = 0;
          brain_B.Vertical = 0;
        } else {
          switch (brain_DWork.is_Running) {
           case brain_IN_Buoy:
            /* During 'Buoy': '<S1>:58' */
            if ((brain_DWork.countarea > 2.0) && (brain_U.DesiredState == 0)) {
              /* Transition: '<S1>:197' */
              /* Exit 'Buoy': '<S1>:58' */
              /* Entry 'Finish': '<S1>:151' */
              brain_DWork.is_Running = (uint8_T)brain_IN_Finish;
              brain_B.State = 6U;
              brain_B.Left = 0;
              brain_B.Right = 0;
              brain_B.Vertical = 0;
            } else if ((brain_U.DesiredState != 5) && (brain_U.DesiredState != 0))
            {
              /* Transition: '<S1>:321' */
              /* Exit 'Buoy': '<S1>:58' */
              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
            } else {
              /* Simulink Function 'Buoy': '<S1>:60' */
              for (i_0 = 0; i_0 < 19200; i_0++) {
                brain_B.SFunction_o17[i_0] = (real_T)brain_B.Resize[i_0];
                brain_B.SFunction_o18[i_0] = (real_T)brain_B.Resize1[i_0];
              }

              brain_DWork.RunningBuoyBuoy_ELAPS_T = brain_M->Timing.clockTick0 -
                brain_DWork.RunningBuoyBuoy_PREV_T;
              brain_DWork.RunningBuoyBuoy_PREV_T = brain_M->Timing.clockTick0;

              /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S20>/Median Filter Red' */
              {
                /* Do appropriate padding of input matrix with a constant value */
                int_T i,j;
                const byte_T *u = (const byte_T *)brain_B.SFunction_o17;
                const int_T bytesPerInpCol = sizeof(real_T)* 120;
                real_T *y = (real_T *)&brain_DWork.MedianFilterRed_PaddedInput[0];
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
                const real_T *inputA = &brain_DWork.MedianFilterRed_PaddedInput
                  [0];
                real_T *y = brain_B.MedianFilterGreen;
                real_T *inAC = &MedianFilterRed_WorkVector[0];
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
                            break;     /* pointers crossed; end scan */

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
                /* RelationalOperator: '<S15>/Compare' incorporates:
                 *  Constant: '<S15>/Constant'
                 */
                brain_B.LogicalOperator[i_0] = (brain_B.MedianFilterGreen[i_0] >
                  brain_P.Buoy_HueHigher);

                /* RelationalOperator: '<S16>/Compare' incorporates:
                 *  Constant: '<S16>/Constant'
                 */
                brain_B.Compare_e[i_0] = (brain_B.MedianFilterGreen[i_0] <=
                  brain_P.Buoy_HueLower);

                /* Logic: '<S3>/Logical Operator' */
                brain_B.LogicalOperator[i_0] = (brain_B.LogicalOperator[i_0] ||
                  brain_B.Compare_e[i_0]);
              }

              /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S20>/Median Filter Green' */
              {
                /* Do appropriate padding of input matrix with a constant value */
                int_T i,j;
                const byte_T *u = (const byte_T *)brain_B.SFunction_o18;
                const int_T bytesPerInpCol = sizeof(real_T)* 120;
                real_T *y = (real_T *)&brain_DWork.MedianFilterRed_PaddedInput[0];
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
                const real_T *inputA = &brain_DWork.MedianFilterRed_PaddedInput
                  [0];
                real_T *y = brain_B.MedianFilterGreen;
                real_T *inAC = &MedianFilterGreen_WorkVector[0];
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
                            break;     /* pointers crossed; end scan */

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
                brain_B.Compare_e[i_0] = (brain_B.MedianFilterGreen[i_0] >=
                  brain_P.Buoy_Saturation);

                /* Logic: '<S3>/Logical Operator1' */
                brain_B.LogicalOperator1[i_0] = (brain_B.LogicalOperator[i_0] &&
                  brain_B.Compare_e[i_0]);
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
                  brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)
                    (brain_B.LogicalOperator1[i_0] ? 255 : 0);
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
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n
                      - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms
                      - 1);
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
                          brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                            currentLabel;
                          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                            (int16_T)((int16_T)(walkerIdx / 122U) - 1);
                          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                            (int16_T)(walkerIdx % 122U - 1U);
                          pixIdx++;
                          BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                            BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
                          brain_DWork.BlobAnalysis_STACK_DW[stackIdx] =
                            walkerIdx;
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
                for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx]; j++)
                {
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
              /* Embedded MATLAB Function 'Chart/Running.Buoy.Buoy/Embedded MATLAB Function': '<S18>:1' */
              /*  This function will choose and return data about the largest blob given a  */
              /*  set of blobs */
              if ((rtb_BuoyBlobAnalysis_o2[0] == -1.0) &&
                  (rtb_BuoyBlobAnalysis_o2[1] == -1.0)) {
                /* '<S18>:1:5' */
                /* '<S18>:1:7' */
                brain_B.BlobCentroidX = 80.0;

                /* '<S18>:1:8' */
                brain_B.BlobCentroidY = 60.0;

                /* '<S18>:1:9' */
                brain_B.BlobArea = -1.0;
              } else {
                /* '<S18>:1:11' */
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

                /* '<S18>:1:11' */
                brain_B.BlobArea = (real_T)i_0;

                /* '<S18>:1:12' */
                brain_B.BlobCentroidX = rtb_BuoyBlobAnalysis_o2[n + 1];

                /* '<S18>:1:13' */
                brain_B.BlobCentroidY = rtb_BuoyBlobAnalysis_o2[n - 1];
              }

              /* Embedded MATLAB: '<S3>/Embedded MATLAB Function1' */
              /* Embedded MATLAB Function 'Chart/Running.Buoy.Buoy/Embedded MATLAB Function1': '<S19>:1' */
              /*  This function finds the center of an image */
              /* '<S19>:1:6' */
              /* '<S19>:1:7' */

              /* Sum: '<S21>/Subtract' */
              rtb_Sum = 80.0 - brain_B.BlobCentroidX;

              /* Gain: '<S23>/X-Buoy Proportional Gain' */
              rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Kp *
                rtb_Sum;

              /* Gain: '<S23>/X-Buoy Derivative Gain' */
              rtb_Error = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum;

              /* S-Function (sfix_tsampmath): '<S24>/TSamp' */

              /* Sample Time Math Block: '<S24>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_g = rtb_Error / (((brain_DWork.RunningBuoyBuoy_ELAPS_T *
                0.02))*(1.0));

              /* DiscreteIntegrator: '<S23>/X-Buoy Discrete-Time Integrator' */
              rtb_Error = brain_DWork.XBuoyDiscreteTimeIntegrator_DST;

              /* Sum: '<S23>/Sum' incorporates:
               *  Sum: '<S24>/Diff'
               *  UnitDelay: '<S24>/UD'
               */
              rtb_Error += (rtb_TSamp_g - brain_DWork.UD_DSTATE_h) +
                rtb_XBuoyProportionalGain;

              /* DataTypeConversion: '<S21>/Data Type Conversion' */
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

              /* Sum: '<S21>/Add' incorporates:
               *  Constant: '<S21>/Vision_Forward_Velocity'
               */
              brain_B.Add = brain_P.Vision_Forward_Velocity + (real_T)
                rtb_DataTypeConversion_0;

              /* Product: '<S21>/Multiply' incorporates:
               *  Constant: '<S21>/Constant'
               */
              rtb_Error = (real_T)rtb_DataTypeConversion_0 * -1.0;

              /* Sum: '<S21>/Add1' incorporates:
               *  Constant: '<S21>/Vision_Forward_Velocity2'
               */
              brain_B.Add1 = rtb_Error + brain_P.Vision_Forward_Velocity;

              /* Gain: '<S23>/X-Buoy Integral Gain' */
              rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Ki *
                rtb_Sum;

              /* Sum: '<S22>/Subtract' */
              rtb_Error = 60.0 - brain_B.BlobCentroidY;

              /* Gain: '<S25>/Y-Buoy Proportional Gain' */
              rtb_YBuoyProportionalGain = brain_P.Cam_Forward_YPosition_Kp *
                rtb_Error;

              /* Gain: '<S25>/Y-Buoy Derivative Gain' */
              rtb_Sum = brain_P.Cam_Forward_YPosition_Kd * rtb_Error;

              /* S-Function (sfix_tsampmath): '<S26>/TSamp' */

              /* Sample Time Math Block: '<S26>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_iq = rtb_Sum / (((brain_DWork.RunningBuoyBuoy_ELAPS_T
                * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S25>/Y-Buoy Discrete-Time Integrator' */
              rtb_Sum = brain_DWork.YBuoyDiscreteTimeIntegrator_DST;

              /* Sum: '<S25>/Sum' incorporates:
               *  Sum: '<S26>/Diff'
               *  UnitDelay: '<S26>/UD'
               */
              rtb_Sum += (rtb_TSamp_iq - brain_DWork.UD_DSTATE_d) +
                rtb_YBuoyProportionalGain;

              /* DataTypeConversion: '<S22>/Data Type Conversion' */
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

              /* Update for UnitDelay: '<S24>/UD' */
              brain_DWork.UD_DSTATE_h = rtb_TSamp_g;

              /* Update for DiscreteIntegrator: '<S23>/X-Buoy Discrete-Time Integrator' */
              brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 0.02 * (real_T)
                brain_DWork.RunningBuoyBuoy_ELAPS_T * rtb_XBuoyProportionalGain
                + brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
              if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
                brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 15.0;
              } else {
                if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
                  brain_DWork.XBuoyDiscreteTimeIntegrator_DST = -15.0;
                }
              }

              /* Update for UnitDelay: '<S26>/UD' */
              brain_DWork.UD_DSTATE_d = rtb_TSamp_iq;

              /* Update for DiscreteIntegrator: '<S25>/Y-Buoy Discrete-Time Integrator' incorporates:
               *  Gain: '<S25>/Y-Buoy Integral Gain'
               */
              brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 0.02 * (real_T)
                brain_DWork.RunningBuoyBuoy_ELAPS_T
                * (brain_P.Cam_Forward_YPosition_Ki * rtb_Error) +
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
              brain_DWork.countarea = brain_countareas((real_T)(int32_T)
                brain_B.BlobArea, brain_DWork.countarea);
            }
            break;

           case brain_IN_ChooseState:
            /* During 'ChooseState': '<S1>:299' */
            if ((brain_U.DesiredState == 1) || (brain_U.DesiredState == 0)) {
              /* Transition: '<S1>:301' */
              /* Exit 'ChooseState': '<S1>:299' */
              /* Entry 'Start': '<S1>:153' */
              brain_DWork.is_Running = (uint8_T)brain_IN_Start;
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
              brain_DWork.is_Running = (uint8_T)brain_IN_ValidationGate;
              brain_DWork.RunningValidationGateStraight_g =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S68>/UD' */
              brain_DWork.UD_DSTATE_n = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S66>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

              /* InitializeConditions for UnitDelay: '<S69>/UD' */
              brain_DWork.UD_DSTATE_b = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S67>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_DWork.TrackCount = 0.0;
              brain_B.State = 2U;
            } else if (brain_U.DesiredState == 4) {
              /* Transition: '<S1>:320' */
              /* Exit 'ChooseState': '<S1>:299' */
              /* Entry 'FindBuoy': '<S1>:239' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FindBuoy;
              brain_DWork.RunningFindBuoyStraightLevelC_j =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S37>/UD' */
              brain_DWork.UD_DSTATE_e = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S35>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

              /* InitializeConditions for UnitDelay: '<S38>/UD' */
              brain_DWork.UD_DSTATE_l = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S36>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_B.CameraPosition = 0;
              brain_B.State = 4U;
              brain_DWork.BuoyCount = 0.0;
            } else if (brain_U.DesiredState == 3) {
              /* Transition: '<S1>:318' */
              /* Exit 'ChooseState': '<S1>:299' */
              /* Entry 'FollowOnePath': '<S1>:325' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FollowOnePath;

              /* Transition: '<S1>:326' */
              /* Entry 'Initialize': '<S1>:379' */
              brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
              brain_B.DesiredDepth = 5.0;
              brain_B.DesiredHeading = 0.0;
              brain_DWork.Done = 0.0;

              /* Simulink Function 'MakeHSVImage': '<S1>:380' */
              for (i_0 = 0; i_0 < 19200; i_0++) {
                brain_B.SFunction_o37[i_0] = (real_T)brain_B.Resize[i_0];
                brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize1[i_0];
                brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize2[i_0];
              }

              RunningFollowOnePathMakeHSVImag(brain_B.SFunction_o37,
                brain_B.SFunction_o38, brain_B.SFunction_o39,
                &brain_B.RunningFollowOnePathMakeHSVIm_f);
            } else {
              if (brain_U.DesiredState == 5) {
                /* Transition: '<S1>:322' */
                /* Exit 'ChooseState': '<S1>:299' */
                /* Entry 'Buoy': '<S1>:58' */
                brain_DWork.is_Running = (uint8_T)brain_IN_Buoy;
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
              brain_DWork.If_ActiveSubsystem_h = -1;
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

              /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);

              /* end of Disable for SubSystem: '<S5>/BigError S1' */

              /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

              /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */

              /* Entry 'Buoy': '<S1>:58' */
              brain_DWork.is_Running = (uint8_T)brain_IN_Buoy;
              brain_DWork.countarea = 0.0;
              brain_B.State = 5U;
            } else if ((brain_U.DesiredState != 4) && (brain_U.DesiredState != 0))
            {
              /* Transition: '<S1>:319' */
              /* Exit 'FindBuoy': '<S1>:239' */

              /* Disable for If: '<S5>/If' */
              brain_DWork.If_ActiveSubsystem_h = -1;
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

              /* Disable for ifaction SubSystem: '<S5>/BigError S1' */
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);

              /* end of Disable for SubSystem: '<S5>/BigError S1' */

              /* Disable for ifaction SubSystem: '<S5>/BigNegativeError S2' */
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);

              /* end of Disable for SubSystem: '<S5>/BigNegativeError S2' */

              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
            } else {
              /* Simulink Function 'LookforBuoy': '<S1>:250' */

              /* DataStoreRead: '<S4>/Data Store Read' */
              brain_B.DataStoreRead = brain_DWork.Image;
              for (i_0 = 0; i_0 < 19200; i_0++) {
                brain_B.SFunction_o23[i_0] = (real_T)brain_B.Resize[i_0];
                brain_B.SFunction_o24[i_0] = (real_T)brain_B.Resize1[i_0];

                /* RelationalOperator: '<S29>/Compare' incorporates:
                 *  Constant: '<S29>/Constant'
                 */
                brain_B.LogicalOperator1_k[i_0] = (brain_B.SFunction_o23[i_0] <
                  brain_P.Buoy_HueLower);

                /* RelationalOperator: '<S28>/Compare' incorporates:
                 *  Constant: '<S28>/Constant'
                 */
                brain_B.Compare[i_0] = (brain_B.SFunction_o23[i_0] >
                  brain_P.Buoy_HueHigher);

                /* Logic: '<S27>/Logical Operator' */
                brain_B.LogicalOperator1_k[i_0] =
                  (brain_B.LogicalOperator1_k[i_0] || brain_B.Compare[i_0]);

                /* RelationalOperator: '<S32>/Compare' incorporates:
                 *  Constant: '<S32>/Constant'
                 */
                brain_B.Compare[i_0] = (brain_B.SFunction_o24[i_0] >
                  brain_P.Buoy_Saturation);

                /* Logic: '<S27>/Logical Operator1' */
                brain_B.LogicalOperator1_k[i_0] =
                  (brain_B.LogicalOperator1_k[i_0] && brain_B.Compare[i_0]);
              }

              /* S-Function (svipblob): '<S27>/Blob Analysis' */
              maxNumBlobsReached = false;
              for (i_0 = 0; i_0 < 123; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              }

              currentLabel = 1U;
              i_0 = 0;
              ms = 123;
              for (n = 0; n < 160; n++) {
                for (n_0 = 0; n_0 < 120; n_0++) {
                  brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)
                    (brain_B.LogicalOperator1_k[i_0] ? 255 : 0);
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
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n
                      - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(j
                      - 1);
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
                          brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                            currentLabel;
                          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                            (int16_T)((int16_T)(walkerIdx / 122U) - 1);
                          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                            (int16_T)(walkerIdx % 122U - 1U);
                          pixIdx++;
                          BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW + 1U;
                          brain_DWork.BlobAnalysis_STACK_DW[stackIdx] =
                            walkerIdx;
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
                for (padCols = 0; padCols < (int32_T)BlobAnalysis_NUM_PIX_DW;
                     padCols++) {
                  i_0 += brain_DWork.BlobAnalysis_N_PIXLIST_DW[padCols + i];
                  n += brain_DWork.BlobAnalysis_M_PIXLIST_DW[padCols + n_0];
                }

                centroid_idx = (real32_T)n / (real32_T)BlobAnalysis_NUM_PIX_DW;
                centroid_idx_0 = (real32_T)i_0 / (real32_T)
                  BlobAnalysis_NUM_PIX_DW;
                n = 160;
                ms = 120;
                j = 0;
                idx = 0;
                for (padCols = 0; padCols < (int32_T)BlobAnalysis_NUM_PIX_DW;
                     padCols++) {
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
                  MultiWordSignedWrap(&tmp_0.chunks[0U], 2, (uint32_T)31,
                                      &tmp.chunks[0U]);
                  sLong2MultiWord((int32_T)BlobAnalysis_NUM_PIX_DW,
                                  &tmp_1.chunks[0U], 2);
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
                  rtb_BlobAnalysis_o1 += rtb_BlobAnalysis_o2 *
                    rtb_BlobAnalysis_o2;
                  ys += uyy * uyy;
                  xys += rtb_BlobAnalysis_o2 * (-uyy);
                  walkerIdx++;
                }

                centroid_idx = rtb_BlobAnalysis_o1 / (real32_T)
                  BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
                uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
                rtb_BlobAnalysis_o1 = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
                rtb_BlobAnalysis_o1 = (real32_T)sqrt((centroid_idx - uyy) *
                  (centroid_idx - uyy) + rtb_BlobAnalysis_o1 *
                  rtb_BlobAnalysis_o1 * 4.0F);
                rtb_BlobAnalysis_o2 = ((centroid_idx + uyy) +
                  rtb_BlobAnalysis_o1) * 8.0F;
                rtb_BlobAnalysis_o1 = (real32_T)sqrt(rtb_BlobAnalysis_o2 -
                  ((centroid_idx + uyy) - rtb_BlobAnalysis_o1) * 8.0F) /
                  (real32_T)sqrt(rtb_BlobAnalysis_o2);
                rtb_BlobAnalysis_o2 = (real32_T)BlobAnalysis_NUM_PIX_DW /
                  (real32_T)(((idx + 1) - ms) * ((j + 1) - n));
                n_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
                i += (int32_T)BlobAnalysis_NUM_PIX_DW;
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                rtb_BlobAnalysis_o1 = -1.0F;
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                rtb_BlobAnalysis_o2 = -1.0F;
              }

              /* If: '<S27>/If' incorporates:
               *  ActionPort: '<S30>/Action Port'
               *  ActionPort: '<S31>/Action Port'
               *  SubSystem: '<S27>/FoundBuoy'
               *  SubSystem: '<S27>/NoBuoy'
               */
              if ((rtb_BlobAnalysis_o1 > 0.0F) && (rtb_BlobAnalysis_o1 <
                   6.499999762E-01F) && (rtb_BlobAnalysis_o2 > 6.999999881E-01F)
                  && (rtb_BlobAnalysis_o2 < 8.999999762E-01F)) {
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
              brain_B.SFunction_o19 = (real32_T)brain_U.CurrentDepth;
              brain_B.SFunction_o20 = (real32_T)brain_B.DesiredDepth;
              brain_B.SFunction_o21 = brain_B.DesiredHeading;
              brain_B.SFunction_o22 = brain_U.CurrentHeading;
              if (brain_DWork.RunningFindBuoyStraightLevelC_n) {
                brain_DWork.RunningFindBuoyStraightLevelCon = 0U;
                brain_DWork.RunningFindBuoyStraightLevelC_n = false;
              } else {
                brain_DWork.RunningFindBuoyStraightLevelCon =
                  brain_M->Timing.clockTick0 -
                  brain_DWork.RunningFindBuoyStraightLevelC_j;
              }

              brain_DWork.RunningFindBuoyStraightLevelC_j =
                brain_M->Timing.clockTick0;

              /* Sum: '<S5>/Add' */
              rtb_Add4_h = (real_T)brain_B.SFunction_o20 - (real_T)
                brain_B.SFunction_o19;

              /* Gain: '<S35>/Depth Proportional Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Add4_h;

              /* Gain: '<S35>/Depth Derivative Gain' */
              rtb_MultiportSwitch_k = brain_P.Depth_Kd * rtb_Add4_h;

              /* S-Function (sfix_tsampmath): '<S37>/TSamp' */

              /* Sample Time Math Block: '<S37>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_e = rtb_MultiportSwitch_k /
                (((brain_DWork.RunningFindBuoyStraightLevelCon * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S35>/Depth Discrete-Time Integrator' */
              rtb_MultiportSwitch_k =
                brain_DWork.DepthDiscreteTimeIntegrator_DST;

              /* Sum: '<S35>/Sum' incorporates:
               *  Sum: '<S37>/Diff'
               *  UnitDelay: '<S37>/UD'
               */
              rtb_MultiportSwitch_k += (rtb_TSamp_e - brain_DWork.UD_DSTATE_e) +
                rtb_XBuoyProportionalGain;

              /* DataTypeConversion: '<S5>/Double To Int8' */
              rtb_YBuoyProportionalGain = floor(rtb_MultiportSwitch_k);
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

              /* Gain: '<S35>/Depth Integral Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Add4_h;

              /* Sum: '<S5>/Add1' */
              rtb_Add1_j = brain_B.SFunction_o21 - brain_B.SFunction_o22;

              /* If: '<S5>/If' incorporates:
               *  ActionPort: '<S33>/Action Port'
               *  ActionPort: '<S34>/Action Port'
               *  SubSystem: '<S5>/BigError S1'
               *  SubSystem: '<S5>/BigNegativeError S2'
               */
              rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem_h;
              rtAction = -1;
              if (rtb_Add1_j > 180.0) {
                rtAction = 0;
              } else {
                if (rtb_Add1_j < -180.0) {
                  rtAction = 1;
                }
              }

              brain_DWork.If_ActiveSubsystem_h = rtAction;
              if (rtb_DataTypeConversion_0 != rtAction) {
                switch (rtb_DataTypeConversion_0) {
                 case 0:
                  brain_BigErrorS1_Disable(&brain_B.BigErrorS1_f);
                  break;

                 case 1:
                  brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_h);
                  break;
                }
              }

              switch (rtAction) {
               case 0:
                brain_BigErrorS1(rtb_Add1_j, &brain_B.BigErrorS1_f);
                break;

               case 1:
                brain_BigNegativeErrorS2(rtb_Add1_j,
                  &brain_B.BigNegativeErrorS2_h);
                break;
              }

              /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
               *  Constant: '<S5>/Constant1'
               *  Sum: '<S5>/Add2'
               */
              switch ((int32_T)((1.0 + brain_B.BigErrorS1_f.Constant1) +
                                brain_B.BigNegativeErrorS2_h.Constant1)) {
               case 1:
                rtb_MultiportSwitch_k = rtb_Add1_j;
                break;

               case 2:
                rtb_MultiportSwitch_k = brain_B.BigErrorS1_f.Add;
                break;

               default:
                rtb_MultiportSwitch_k = brain_B.BigNegativeErrorS2_h.Add;
                break;
              }

              /* Gain: '<S36>/Heading Proportional Gain' */
              rtb_YBuoyProportionalGain = brain_P.Heading_Kp *
                rtb_MultiportSwitch_k;

              /* Gain: '<S36>/Heading Derivative Gain' */
              rtb_Add4_h = brain_P.Heading_Kd * rtb_MultiportSwitch_k;

              /* S-Function (sfix_tsampmath): '<S38>/TSamp' */

              /* Sample Time Math Block: '<S38>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_i = rtb_Add4_h /
                (((brain_DWork.RunningFindBuoyStraightLevelCon * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S36>/Heading Discrete-Time Integrator' */
              rtb_Add4_h = brain_DWork.HeadingDiscreteTimeIntegrator_d;

              /* Sum: '<S36>/Sum' incorporates:
               *  Sum: '<S38>/Diff'
               *  UnitDelay: '<S38>/UD'
               */
              rtb_Add4_h += (rtb_TSamp_i - brain_DWork.UD_DSTATE_l) +
                rtb_YBuoyProportionalGain;

              /* Product: '<S5>/Multiply' incorporates:
               *  Constant: '<S5>/Constant'
               */
              rtb_YBuoyProportionalGain = -rtb_Add4_h;
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
              rtb_Add4_h += brain_P.Heading_Forward_Velocity;

              /* DataTypeConversion: '<S5>/DoubleToint1' incorporates:
               *  Constant: '<S5>/Heading Forward Velocity2'
               *  Sum: '<S5>/Add3'
               */
              rtb_YBuoyProportionalGain = (real_T)(rtb_YBuoyProportionalGain <
                0.0 ? (int8_T)(-((int8_T)(uint8_T)(-rtb_YBuoyProportionalGain)))
                : (int8_T)(uint8_T)rtb_YBuoyProportionalGain) +
                brain_P.Heading_Forward_Velocity;
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

              /* DataTypeConversion: '<S5>/DoubleToint8' */
              rtb_YBuoyProportionalGain = floor(rtb_Add4_h);
              if (rtb_YBuoyProportionalGain < 128.0) {
                if (rtb_YBuoyProportionalGain >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DoubleToint8_p = rtb_DataTypeConversion_0;

              /* Update for UnitDelay: '<S37>/UD' */
              brain_DWork.UD_DSTATE_e = rtb_TSamp_e;

              /* Update for DiscreteIntegrator: '<S35>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.02 * (real_T)
                brain_DWork.RunningFindBuoyStraightLevelCon *
                rtb_XBuoyProportionalGain +
                brain_DWork.DepthDiscreteTimeIntegrator_DST;
              if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
                brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
              } else {
                if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
                  brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
                }
              }

              /* Update for UnitDelay: '<S38>/UD' */
              brain_DWork.UD_DSTATE_l = rtb_TSamp_i;

              /* Update for DiscreteIntegrator: '<S36>/Heading Discrete-Time Integrator' incorporates:
               *  Gain: '<S36>/Heading Integral Gain'
               */
              brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.02 * (real_T)
                brain_DWork.RunningFindBuoyStraightLevelCon *
                (brain_P.Heading_Ki * rtb_MultiportSwitch_k) +
                brain_DWork.HeadingDiscreteTimeIntegrator_d;
              if (brain_DWork.HeadingDiscreteTimeIntegrator_d >= 15.0) {
                brain_DWork.HeadingDiscreteTimeIntegrator_d = 15.0;
              } else {
                if (brain_DWork.HeadingDiscreteTimeIntegrator_d <= -15.0) {
                  brain_DWork.HeadingDiscreteTimeIntegrator_d = -15.0;
                }
              }

              brain_B.Vertical = brain_B.DoubleToInt8;
              brain_B.Left = brain_B.DoubleToint8_p;
              brain_B.Right = brain_B.DoubleToint1_j;
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
              brain_DWork.is_Running = (uint8_T)brain_IN_FindBuoy;
              brain_DWork.RunningFindBuoyStraightLevelC_j =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S37>/UD' */
              brain_DWork.UD_DSTATE_e = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S35>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

              /* InitializeConditions for UnitDelay: '<S38>/UD' */
              brain_DWork.UD_DSTATE_l = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S36>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_B.CameraPosition = 0;
              brain_B.State = 4U;
              brain_DWork.BuoyCount = 0.0;
            } else if ((brain_U.DesiredState != 3) && (brain_U.DesiredState != 0))
            {
              /* Transition: '<S1>:304' */
              bra_exit_internal_FollowOnePath();

              /* Exit 'FollowOnePath': '<S1>:325' */
              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
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

                /* Simulink Function 'MakeHSVImage': '<S1>:380' */
                for (i_0 = 0; i_0 < 19200; i_0++) {
                  brain_B.SFunction_o37[i_0] = (real_T)brain_B.Resize[i_0];
                  brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize1[i_0];
                  brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize2[i_0];
                }

                RunningFollowOnePathMakeHSVImag(brain_B.SFunction_o37,
                  brain_B.SFunction_o38, brain_B.SFunction_o39,
                  &brain_B.RunningFollowOnePathMakeHSVIm_f);
                break;
              }
            }
            break;

           case brain_IN_Start:
            /* During 'Start': '<S1>:153' */
            if ((brain_DWork.DesiredHeadingCount >= 3.0) &&
                (brain_U.DesiredState == 0)) {
              /* Transition: '<S1>:162' */
              /* Exit 'Start': '<S1>:153' */
              brain_B.DesiredHeading = brain_U.CurrentHeading;

              /* Entry 'ValidationGate': '<S1>:1' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ValidationGate;
              brain_DWork.RunningValidationGateStraight_g =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S68>/UD' */
              brain_DWork.UD_DSTATE_n = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S66>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

              /* InitializeConditions for UnitDelay: '<S69>/UD' */
              brain_DWork.UD_DSTATE_b = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S67>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_DWork.TrackCount = 0.0;
              brain_B.State = 2U;
            } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState != 0))
            {
              /* Transition: '<S1>:300' */
              /* Exit 'Start': '<S1>:153' */
              brain_B.DesiredHeading = brain_U.CurrentHeading;

              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
            } else {
              /* Embedded MATLAB Function 'InitialHeadingCount': '<S1>:154' */
              /* '<S1>:154:3' */
              if ((brain_U.CurrentHeading > brain_DWork.OldHeading - 2.0) &&
                  (brain_U.CurrentHeading < brain_DWork.OldHeading + 2.0)) {
                /* '<S1>:154:5' */
                /* '<S1>:154:6' */
                brain_DWork.DesiredHeadingCount =
                  brain_DWork.DesiredHeadingCount + 1.0;
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
              brain_DWork.If_ActiveSubsystem_o = -1;
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

              /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

              /* end of Disable for SubSystem: '<S14>/BigError S1' */

              /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

              /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */

              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
            } else if ((brain_DWork.TrackCount > 2.0) && (brain_U.DesiredState ==
                        0)) {
              /* Transition: '<S1>:199' */
              /* Exit 'ValidationGate': '<S1>:1' */

              /* Disable for If: '<S14>/If' */
              brain_DWork.If_ActiveSubsystem_o = -1;
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

              /* Disable for ifaction SubSystem: '<S14>/BigError S1' */
              brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

              /* end of Disable for SubSystem: '<S14>/BigError S1' */

              /* Disable for ifaction SubSystem: '<S14>/BigNegativeError S2' */
              brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

              /* end of Disable for SubSystem: '<S14>/BigNegativeError S2' */

              /* Entry 'FollowOnePath': '<S1>:325' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FollowOnePath;

              /* Transition: '<S1>:326' */
              /* Entry 'Initialize': '<S1>:379' */
              brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
              brain_B.DesiredDepth = 5.0;
              brain_B.DesiredHeading = 0.0;
              brain_DWork.Done = 0.0;

              /* Simulink Function 'MakeHSVImage': '<S1>:380' */
              for (i_0 = 0; i_0 < 19200; i_0++) {
                brain_B.SFunction_o37[i_0] = (real_T)brain_B.Resize[i_0];
                brain_B.SFunction_o38[i_0] = (real_T)brain_B.Resize1[i_0];
                brain_B.SFunction_o39[i_0] = (real_T)brain_B.Resize2[i_0];
              }

              RunningFollowOnePathMakeHSVImag(brain_B.SFunction_o37,
                brain_B.SFunction_o38, brain_B.SFunction_o39,
                &brain_B.RunningFollowOnePathMakeHSVIm_f);
            } else {
              /* Simulink Function 'LookforTrack': '<S1>:4' */

              /* DataStoreRead: '<S13>/Data Store Read' */
              brain_B.DataStoreRead_l = brain_DWork.Image_c;
              for (i_0 = 0; i_0 < 19200; i_0++) {
                brain_B.SFunction_o11[i_0] = (real_T)brain_B.Resize[i_0];
                brain_B.SFunction_o12[i_0] = (real_T)brain_B.Resize1[i_0];

                /* RelationalOperator: '<S61>/Compare' incorporates:
                 *  Constant: '<S61>/Constant'
                 */
                brain_B.LogicalOperator1_e[i_0] = (brain_B.SFunction_o11[i_0] <
                  brain_P.Track_HueLower);

                /* RelationalOperator: '<S60>/Compare' incorporates:
                 *  Constant: '<S60>/Constant'
                 */
                brain_B.Compare_c[i_0] = (brain_B.SFunction_o11[i_0] >
                  brain_P.Track_HueHigher);

                /* Logic: '<S58>/Logical Operator' */
                brain_B.LogicalOperator1_e[i_0] =
                  (brain_B.LogicalOperator1_e[i_0] || brain_B.Compare_c[i_0]);

                /* RelationalOperator: '<S63>/Compare' incorporates:
                 *  Constant: '<S63>/Constant'
                 */
                brain_B.Compare_c[i_0] = (brain_B.SFunction_o12[i_0] >
                  brain_P.Track_Saturation);

                /* Logic: '<S58>/Logical Operator1' */
                brain_B.LogicalOperator1_e[i_0] =
                  (brain_B.LogicalOperator1_e[i_0] && brain_B.Compare_c[i_0]);
              }

              /* S-Function (svipblob): '<S58>/Blob Analysis' */
              maxNumBlobsReached = false;
              for (i_0 = 0; i_0 < 123; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              }

              currentLabel = 1U;
              i_0 = 0;
              ms = 123;
              for (n = 0; n < 160; n++) {
                for (n_0 = 0; n_0 < 120; n_0++) {
                  brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)
                    (brain_B.LogicalOperator1_e[i_0] ? 255 : 0);
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
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n
                      - 1);
                    brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(j
                      - 1);
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
                          brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                            currentLabel;
                          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                            (int16_T)((int16_T)(walkerIdx / 122U) - 1);
                          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                            (int16_T)(walkerIdx % 122U - 1U);
                          pixIdx++;
                          BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW + 1U;
                          brain_DWork.BlobAnalysis_STACK_DW[stackIdx] =
                            walkerIdx;
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
                centroid_idx_0 = (real32_T)idx / (real32_T)
                  BlobAnalysis_NUM_PIX_DW;
                rtb_BlobAnalysis_o1 = 0.0F;
                ys = 0.0F;
                xys = 0.0F;
                walkerIdx = 0U;
                while (1) {
                  uLong2MultiWord(walkerIdx, &tmp_2.chunks[0U], 2);
                  MultiWordSignedWrap(&tmp_2.chunks[0U], 2, (uint32_T)31,
                                      &tmp_1.chunks[0U]);
                  sLong2MultiWord((int32_T)BlobAnalysis_NUM_PIX_DW,
                                  &tmp_3.chunks[0U], 2);
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
                  rtb_BlobAnalysis_o1 += rtb_BlobAnalysis_o2 *
                    rtb_BlobAnalysis_o2;
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
                rtb_BlobAnalysis_o1 = (real32_T)sqrt(rtb_BlobAnalysis_o2 - ((uyy
                  + ys) - rtb_BlobAnalysis_o1) * 8.0F) / (real32_T)sqrt
                  (rtb_BlobAnalysis_o2);
                i_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
                n += (int32_T)BlobAnalysis_NUM_PIX_DW;
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                rtb_BlobAnalysis_o1 = -1.0F;
              }

              /* If: '<S58>/If' incorporates:
               *  ActionPort: '<S59>/Action Port'
               *  ActionPort: '<S62>/Action Port'
               *  SubSystem: '<S58>/FoundTrack'
               *  SubSystem: '<S58>/NoTrack'
               */
              if (rtb_BlobAnalysis_o1 > 8.999999762E-01F) {
                brain_FoundTrack(&brain_DWork.Image_c);
              } else {
                brain_NoTrack(&brain_DWork.Image_c);
              }

              sf_Obstacle = brain_B.DataStoreRead_l;

              /* Embedded MATLAB Function 'countimages': '<S1>:15' */
              /*  This function acts to count the number of consecutive times a particular */
              /*  image is recognized by the recognition software */
              if ((brain_B.DataStoreRead_l != 0.0) && (brain_B.DataStoreRead_l ==
                   brain_DWork.OldObstacle)) {
                /* '<S1>:15:6' */
                /* '<S1>:15:7' */
                brain_DWork.TrackCount = brain_DWork.count + 1.0;
              } else {
                /* '<S1>:15:9' */
                brain_DWork.TrackCount = 0.0;
              }

              /* Simulink Function 'StraightLevelControl': '<S1>:28' */
              brain_B.SFunction_o13 = (real32_T)brain_U.CurrentDepth;
              brain_B.SFunction_o14 = (real32_T)brain_B.DesiredDepth;
              brain_B.SFunction_o15 = brain_B.DesiredHeading;
              brain_B.SFunction_o16 = brain_U.CurrentHeading;
              if (brain_DWork.RunningValidationGateStraight_n) {
                brain_DWork.RunningValidationGateStraightLe = 0U;
                brain_DWork.RunningValidationGateStraight_n = false;
              } else {
                brain_DWork.RunningValidationGateStraightLe =
                  brain_M->Timing.clockTick0 -
                  brain_DWork.RunningValidationGateStraight_g;
              }

              brain_DWork.RunningValidationGateStraight_g =
                brain_M->Timing.clockTick0;

              /* Sum: '<S14>/Add' */
              rtb_Add4_g = (real_T)brain_B.SFunction_o14 - (real_T)
                brain_B.SFunction_o13;

              /* Gain: '<S66>/Depth Proportional Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Add4_g;

              /* Gain: '<S66>/Depth Derivative Gain' */
              rtb_MultiportSwitch_o = brain_P.Depth_Kd * rtb_Add4_g;

              /* S-Function (sfix_tsampmath): '<S68>/TSamp' */

              /* Sample Time Math Block: '<S68>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_n = rtb_MultiportSwitch_o /
                (((brain_DWork.RunningValidationGateStraightLe * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S66>/Depth Discrete-Time Integrator' */
              rtb_MultiportSwitch_o =
                brain_DWork.DepthDiscreteTimeIntegrator_D_e;

              /* Sum: '<S66>/Sum' incorporates:
               *  Sum: '<S68>/Diff'
               *  UnitDelay: '<S68>/UD'
               */
              rtb_MultiportSwitch_o += (rtb_TSamp_n - brain_DWork.UD_DSTATE_n) +
                rtb_XBuoyProportionalGain;

              /* DataTypeConversion: '<S14>/Double To Int8' */
              rtb_YBuoyProportionalGain = floor(rtb_MultiportSwitch_o);
              if (rtb_YBuoyProportionalGain < 128.0) {
                if (rtb_YBuoyProportionalGain >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)rtb_YBuoyProportionalGain;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DoubleToInt8_c = rtb_DataTypeConversion_0;

              /* Gain: '<S66>/Depth Integral Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Add4_g;

              /* Sum: '<S14>/Add1' */
              rtb_Add1_m = brain_B.SFunction_o15 - brain_B.SFunction_o16;

              /* If: '<S14>/If' incorporates:
               *  ActionPort: '<S64>/Action Port'
               *  ActionPort: '<S65>/Action Port'
               *  SubSystem: '<S14>/BigError S1'
               *  SubSystem: '<S14>/BigNegativeError S2'
               */
              rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem_o;
              rtAction = -1;
              if (rtb_Add1_m > 180.0) {
                rtAction = 0;
              } else {
                if (rtb_Add1_m < -180.0) {
                  rtAction = 1;
                }
              }

              brain_DWork.If_ActiveSubsystem_o = rtAction;
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
                brain_BigErrorS1(rtb_Add1_m, &brain_B.BigErrorS1);
                break;

               case 1:
                brain_BigNegativeErrorS2(rtb_Add1_m, &brain_B.BigNegativeErrorS2);
                break;
              }

              /* MultiPortSwitch: '<S14>/Multiport Switch' incorporates:
               *  Constant: '<S14>/Constant1'
               *  Sum: '<S14>/Add2'
               */
              switch ((int32_T)((1.0 + brain_B.BigErrorS1.Constant1) +
                                brain_B.BigNegativeErrorS2.Constant1)) {
               case 1:
                rtb_MultiportSwitch_o = rtb_Add1_m;
                break;

               case 2:
                rtb_MultiportSwitch_o = brain_B.BigErrorS1.Add;
                break;

               default:
                rtb_MultiportSwitch_o = brain_B.BigNegativeErrorS2.Add;
                break;
              }

              /* Gain: '<S67>/Heading Proportional Gain' */
              rtb_YBuoyProportionalGain = brain_P.Heading_Kp *
                rtb_MultiportSwitch_o;

              /* Gain: '<S67>/Heading Derivative Gain' */
              rtb_Add4_g = brain_P.Heading_Kd * rtb_MultiportSwitch_o;

              /* S-Function (sfix_tsampmath): '<S69>/TSamp' */

              /* Sample Time Math Block: '<S69>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_c = rtb_Add4_g /
                (((brain_DWork.RunningValidationGateStraightLe * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S67>/Heading Discrete-Time Integrator' */
              rtb_Add4_g = brain_DWork.HeadingDiscreteTimeIntegrato_dv;

              /* Sum: '<S67>/Sum' incorporates:
               *  Sum: '<S69>/Diff'
               *  UnitDelay: '<S69>/UD'
               */
              rtb_Add4_g += (rtb_TSamp_c - brain_DWork.UD_DSTATE_b) +
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
              rtb_YBuoyProportionalGain = (real_T)(rtb_YBuoyProportionalGain <
                0.0 ? (int8_T)(-((int8_T)(uint8_T)(-rtb_YBuoyProportionalGain)))
                : (int8_T)(uint8_T)rtb_YBuoyProportionalGain) +
                brain_P.Heading_Forward_Velocity;
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

              brain_B.DoubleToint1_c = rtb_DataTypeConversion_0;

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

              brain_B.DoubleToint8_b = rtb_DataTypeConversion_0;

              /* Update for UnitDelay: '<S68>/UD' */
              brain_DWork.UD_DSTATE_n = rtb_TSamp_n;

              /* Update for DiscreteIntegrator: '<S66>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.02 * (real_T)
                brain_DWork.RunningValidationGateStraightLe *
                rtb_XBuoyProportionalGain +
                brain_DWork.DepthDiscreteTimeIntegrator_D_e;
              if (brain_DWork.DepthDiscreteTimeIntegrator_D_e >= 10.0) {
                brain_DWork.DepthDiscreteTimeIntegrator_D_e = 10.0;
              } else {
                if (brain_DWork.DepthDiscreteTimeIntegrator_D_e <= -10.0) {
                  brain_DWork.DepthDiscreteTimeIntegrator_D_e = -10.0;
                }
              }

              /* Update for UnitDelay: '<S69>/UD' */
              brain_DWork.UD_DSTATE_b = rtb_TSamp_c;

              /* Update for DiscreteIntegrator: '<S67>/Heading Discrete-Time Integrator' incorporates:
               *  Gain: '<S67>/Heading Integral Gain'
               */
              brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.02 * (real_T)
                brain_DWork.RunningValidationGateStraightLe *
                (brain_P.Heading_Ki * rtb_MultiportSwitch_o) +
                brain_DWork.HeadingDiscreteTimeIntegrato_dv;
              if (brain_DWork.HeadingDiscreteTimeIntegrato_dv >= 15.0) {
                brain_DWork.HeadingDiscreteTimeIntegrato_dv = 15.0;
              } else {
                if (brain_DWork.HeadingDiscreteTimeIntegrato_dv <= -15.0) {
                  brain_DWork.HeadingDiscreteTimeIntegrato_dv = -15.0;
                }
              }

              brain_B.Vertical = brain_B.DoubleToInt8_c;
              brain_B.Left = brain_B.DoubleToint8_b;
              brain_B.Right = brain_B.DoubleToint1_c;
              brain_DWork.OldObstacle = sf_Obstacle;
              brain_DWork.count = brain_DWork.TrackCount;
            }
            break;

           default:
            /* Transition: '<S1>:161' */
            /* Entry 'Start': '<S1>:153' */
            brain_DWork.is_Running = (uint8_T)brain_IN_Start;
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
        brain_enter_internal_c1_brain();
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
        brain_B.vidR[outStep + k] = brain_U.Cb[o];
        brain_B.vidR[(outStep + k) + 1] = brain_U.Cb[o];
        k += 480;
        brain_B.vidR[outStep + k] = brain_U.Cb[o];
        brain_B.vidR[(outStep + k) + 1] = brain_U.Cb[o];
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
        brain_B.vidG[outStep + k] = brain_U.Cr[o];
        brain_B.vidG[(outStep + k) + 1] = brain_U.Cr[o];
        k += 480;
        brain_B.vidG[outStep + k] = brain_U.Cr[o];
        brain_B.vidG[(outStep + k) + 1] = brain_U.Cr[o];
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
      pos = (yDiff * 19077U + (uint32_T)(brain_B.vidG[outStep] * 26149)) + 8192U;
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
      neg = (uint32_T)(brain_B.vidR[outStep] * 6419 + brain_B.vidG[outStep] *
                       13320);
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
      pos = (yDiff * 19077U + (uint32_T)(brain_B.vidR[outStep] * 33050)) + 8192U;
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
      brain_B.vidR[outStep] = (uint8_T)cc;
      brain_B.vidG[outStep] = (uint8_T)cc_0;
      brain_B.vidB[outStep] = (uint8_T)neg;
    }

    for (outStep = 0; outStep < 307200; outStep++) {
      /* S-Function (svipscalenconvert): '<S2>/Red Data Type Conversion' */
      brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = (real32_T)
        brain_B.vidR[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Green Data Type Conversion1' */
      brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = (real32_T)
        brain_B.vidG[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Blue Data Type Conversion2' */
      brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = (real32_T)
        brain_B.vidB[outStep] / 255.0F;
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
    brain_Y.Thrusters[0] = brain_B.Left;
    brain_Y.Thrusters[1] = brain_B.Right;
    brain_Y.Thrusters[2] = brain_B.Vertical;

    /* Outport: '<Root>/State' */
    brain_Y.State = brain_B.State;

    /* Outport: '<Root>/DesiredDepth' */
    brain_Y.DesiredDepth = brain_B.DesiredDepth;

    /* Outport: '<Root>/DesiredHeading' */
    brain_Y.DesiredHeading = brain_B.DesiredHeading;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  brain_M->Timing.clockTick0++;
}

/* Model initialize function */
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
    brain_B.HoughTransform_o2_j[0] = -1.5707963267948966E+00;
    brain_B.HoughTransform_o2_j[1] = -1.5533430342749532E+00;
    brain_B.HoughTransform_o2_j[2] = -1.5358897417550099E+00;
    brain_B.HoughTransform_o2_j[3] = -1.5184364492350666E+00;
    brain_B.HoughTransform_o2_j[4] = -1.5009831567151235E+00;
    brain_B.HoughTransform_o2_j[5] = -1.4835298641951802E+00;
    brain_B.HoughTransform_o2_j[6] = -1.4660765716752369E+00;
    brain_B.HoughTransform_o2_j[7] = -1.4486232791552935E+00;
    brain_B.HoughTransform_o2_j[8] = -1.4311699866353502E+00;
    brain_B.HoughTransform_o2_j[9] = -1.4137166941154069E+00;
    brain_B.HoughTransform_o2_j[10] = -1.3962634015954636E+00;
    brain_B.HoughTransform_o2_j[11] = -1.3788101090755203E+00;
    brain_B.HoughTransform_o2_j[12] = -1.3613568165555769E+00;
    brain_B.HoughTransform_o2_j[13] = -1.3439035240356338E+00;
    brain_B.HoughTransform_o2_j[14] = -1.3264502315156905E+00;
    brain_B.HoughTransform_o2_j[15] = -1.3089969389957472E+00;
    brain_B.HoughTransform_o2_j[16] = -1.2915436464758039E+00;
    brain_B.HoughTransform_o2_j[17] = -1.2740903539558606E+00;
    brain_B.HoughTransform_o2_j[18] = -1.2566370614359172E+00;
    brain_B.HoughTransform_o2_j[19] = -1.2391837689159739E+00;
    brain_B.HoughTransform_o2_j[20] = -1.2217304763960306E+00;
    brain_B.HoughTransform_o2_j[21] = -1.2042771838760873E+00;
    brain_B.HoughTransform_o2_j[22] = -1.1868238913561442E+00;
    brain_B.HoughTransform_o2_j[23] = -1.1693705988362009E+00;
    brain_B.HoughTransform_o2_j[24] = -1.1519173063162575E+00;
    brain_B.HoughTransform_o2_j[25] = -1.1344640137963142E+00;
    brain_B.HoughTransform_o2_j[26] = -1.1170107212763709E+00;
    brain_B.HoughTransform_o2_j[27] = -1.0995574287564276E+00;
    brain_B.HoughTransform_o2_j[28] = -1.0821041362364843E+00;
    brain_B.HoughTransform_o2_j[29] = -1.0646508437165410E+00;
    brain_B.HoughTransform_o2_j[30] = -1.0471975511965976E+00;
    brain_B.HoughTransform_o2_j[31] = -1.0297442586766545E+00;
    brain_B.HoughTransform_o2_j[32] = -1.0122909661567112E+00;
    brain_B.HoughTransform_o2_j[33] = -9.9483767363676789E-01;
    brain_B.HoughTransform_o2_j[34] = -9.7738438111682457E-01;
    brain_B.HoughTransform_o2_j[35] = -9.5993108859688125E-01;
    brain_B.HoughTransform_o2_j[36] = -9.4247779607693793E-01;
    brain_B.HoughTransform_o2_j[37] = -9.2502450355699462E-01;
    brain_B.HoughTransform_o2_j[38] = -9.0757121103705141E-01;
    brain_B.HoughTransform_o2_j[39] = -8.9011791851710809E-01;
    brain_B.HoughTransform_o2_j[40] = -8.7266462599716477E-01;
    brain_B.HoughTransform_o2_j[41] = -8.5521133347722145E-01;
    brain_B.HoughTransform_o2_j[42] = -8.3775804095727824E-01;
    brain_B.HoughTransform_o2_j[43] = -8.2030474843733492E-01;
    brain_B.HoughTransform_o2_j[44] = -8.0285145591739160E-01;
    brain_B.HoughTransform_o2_j[45] = -7.8539816339744828E-01;
    brain_B.HoughTransform_o2_j[46] = -7.6794487087750496E-01;
    brain_B.HoughTransform_o2_j[47] = -7.5049157835756175E-01;
    brain_B.HoughTransform_o2_j[48] = -7.3303828583761843E-01;
    brain_B.HoughTransform_o2_j[49] = -7.1558499331767511E-01;
    brain_B.HoughTransform_o2_j[50] = -6.9813170079773179E-01;
    brain_B.HoughTransform_o2_j[51] = -6.8067840827778847E-01;
    brain_B.HoughTransform_o2_j[52] = -6.6322511575784526E-01;
    brain_B.HoughTransform_o2_j[53] = -6.4577182323790194E-01;
    brain_B.HoughTransform_o2_j[54] = -6.2831853071795862E-01;
    brain_B.HoughTransform_o2_j[55] = -6.1086523819801530E-01;
    brain_B.HoughTransform_o2_j[56] = -5.9341194567807209E-01;
    brain_B.HoughTransform_o2_j[57] = -5.7595865315812877E-01;
    brain_B.HoughTransform_o2_j[58] = -5.5850536063818546E-01;
    brain_B.HoughTransform_o2_j[59] = -5.4105206811824214E-01;
    brain_B.HoughTransform_o2_j[60] = -5.2359877559829882E-01;
    brain_B.HoughTransform_o2_j[61] = -5.0614548307835561E-01;
    brain_B.HoughTransform_o2_j[62] = -4.8869219055841229E-01;
    brain_B.HoughTransform_o2_j[63] = -4.7123889803846897E-01;
    brain_B.HoughTransform_o2_j[64] = -4.5378560551852570E-01;
    brain_B.HoughTransform_o2_j[65] = -4.3633231299858238E-01;
    brain_B.HoughTransform_o2_j[66] = -4.1887902047863912E-01;
    brain_B.HoughTransform_o2_j[67] = -4.0142572795869580E-01;
    brain_B.HoughTransform_o2_j[68] = -3.8397243543875248E-01;
    brain_B.HoughTransform_o2_j[69] = -3.6651914291880922E-01;
    brain_B.HoughTransform_o2_j[70] = -3.4906585039886590E-01;
    brain_B.HoughTransform_o2_j[71] = -3.3161255787892263E-01;
    brain_B.HoughTransform_o2_j[72] = -3.1415926535897931E-01;
    brain_B.HoughTransform_o2_j[73] = -2.9670597283903605E-01;
    brain_B.HoughTransform_o2_j[74] = -2.7925268031909273E-01;
    brain_B.HoughTransform_o2_j[75] = -2.6179938779914941E-01;
    brain_B.HoughTransform_o2_j[76] = -2.4434609527920614E-01;
    brain_B.HoughTransform_o2_j[77] = -2.2689280275926285E-01;
    brain_B.HoughTransform_o2_j[78] = -2.0943951023931956E-01;
    brain_B.HoughTransform_o2_j[79] = -1.9198621771937624E-01;
    brain_B.HoughTransform_o2_j[80] = -1.7453292519943295E-01;
    brain_B.HoughTransform_o2_j[81] = -1.5707963267948966E-01;
    brain_B.HoughTransform_o2_j[82] = -1.3962634015954636E-01;
    brain_B.HoughTransform_o2_j[83] = -1.2217304763960307E-01;
    brain_B.HoughTransform_o2_j[84] = -1.0471975511965978E-01;
    brain_B.HoughTransform_o2_j[85] = -8.7266462599716474E-02;
    brain_B.HoughTransform_o2_j[86] = -6.9813170079773182E-02;
    brain_B.HoughTransform_o2_j[87] = -5.2359877559829890E-02;
    brain_B.HoughTransform_o2_j[88] = -3.4906585039886591E-02;
    brain_B.HoughTransform_o2_j[89] = -1.7453292519943295E-02;
    brain_B.HoughTransform_o2_j[90] = 0.0;
    brain_B.HoughTransform_o2_j[91] = 1.7453292519943295E-02;
    brain_B.HoughTransform_o2_j[92] = 3.4906585039886591E-02;
    brain_B.HoughTransform_o2_j[93] = 5.2359877559829890E-02;
    brain_B.HoughTransform_o2_j[94] = 6.9813170079773182E-02;
    brain_B.HoughTransform_o2_j[95] = 8.7266462599716474E-02;
    brain_B.HoughTransform_o2_j[96] = 1.0471975511965978E-01;
    brain_B.HoughTransform_o2_j[97] = 1.2217304763960307E-01;
    brain_B.HoughTransform_o2_j[98] = 1.3962634015954636E-01;
    brain_B.HoughTransform_o2_j[99] = 1.5707963267948966E-01;
    brain_B.HoughTransform_o2_j[100] = 1.7453292519943295E-01;
    brain_B.HoughTransform_o2_j[101] = 1.9198621771937624E-01;
    brain_B.HoughTransform_o2_j[102] = 2.0943951023931956E-01;
    brain_B.HoughTransform_o2_j[103] = 2.2689280275926285E-01;
    brain_B.HoughTransform_o2_j[104] = 2.4434609527920614E-01;
    brain_B.HoughTransform_o2_j[105] = 2.6179938779914941E-01;
    brain_B.HoughTransform_o2_j[106] = 2.7925268031909273E-01;
    brain_B.HoughTransform_o2_j[107] = 2.9670597283903605E-01;
    brain_B.HoughTransform_o2_j[108] = 3.1415926535897931E-01;
    brain_B.HoughTransform_o2_j[109] = 3.3161255787892263E-01;
    brain_B.HoughTransform_o2_j[110] = 3.4906585039886590E-01;
    brain_B.HoughTransform_o2_j[111] = 3.6651914291880922E-01;
    brain_B.HoughTransform_o2_j[112] = 3.8397243543875248E-01;
    brain_B.HoughTransform_o2_j[113] = 4.0142572795869580E-01;
    brain_B.HoughTransform_o2_j[114] = 4.1887902047863912E-01;
    brain_B.HoughTransform_o2_j[115] = 4.3633231299858238E-01;
    brain_B.HoughTransform_o2_j[116] = 4.5378560551852570E-01;
    brain_B.HoughTransform_o2_j[117] = 4.7123889803846897E-01;
    brain_B.HoughTransform_o2_j[118] = 4.8869219055841229E-01;
    brain_B.HoughTransform_o2_j[119] = 5.0614548307835561E-01;
    brain_B.HoughTransform_o2_j[120] = 5.2359877559829882E-01;
    brain_B.HoughTransform_o2_j[121] = 5.4105206811824214E-01;
    brain_B.HoughTransform_o2_j[122] = 5.5850536063818546E-01;
    brain_B.HoughTransform_o2_j[123] = 5.7595865315812877E-01;
    brain_B.HoughTransform_o2_j[124] = 5.9341194567807209E-01;
    brain_B.HoughTransform_o2_j[125] = 6.1086523819801530E-01;
    brain_B.HoughTransform_o2_j[126] = 6.2831853071795862E-01;
    brain_B.HoughTransform_o2_j[127] = 6.4577182323790194E-01;
    brain_B.HoughTransform_o2_j[128] = 6.6322511575784526E-01;
    brain_B.HoughTransform_o2_j[129] = 6.8067840827778847E-01;
    brain_B.HoughTransform_o2_j[130] = 6.9813170079773179E-01;
    brain_B.HoughTransform_o2_j[131] = 7.1558499331767511E-01;
    brain_B.HoughTransform_o2_j[132] = 7.3303828583761843E-01;
    brain_B.HoughTransform_o2_j[133] = 7.5049157835756175E-01;
    brain_B.HoughTransform_o2_j[134] = 7.6794487087750496E-01;
    brain_B.HoughTransform_o2_j[135] = 7.8539816339744828E-01;
    brain_B.HoughTransform_o2_j[136] = 8.0285145591739160E-01;
    brain_B.HoughTransform_o2_j[137] = 8.2030474843733492E-01;
    brain_B.HoughTransform_o2_j[138] = 8.3775804095727824E-01;
    brain_B.HoughTransform_o2_j[139] = 8.5521133347722145E-01;
    brain_B.HoughTransform_o2_j[140] = 8.7266462599716477E-01;
    brain_B.HoughTransform_o2_j[141] = 8.9011791851710809E-01;
    brain_B.HoughTransform_o2_j[142] = 9.0757121103705141E-01;
    brain_B.HoughTransform_o2_j[143] = 9.2502450355699462E-01;
    brain_B.HoughTransform_o2_j[144] = 9.4247779607693793E-01;
    brain_B.HoughTransform_o2_j[145] = 9.5993108859688125E-01;
    brain_B.HoughTransform_o2_j[146] = 9.7738438111682457E-01;
    brain_B.HoughTransform_o2_j[147] = 9.9483767363676789E-01;
    brain_B.HoughTransform_o2_j[148] = 1.0122909661567112E+00;
    brain_B.HoughTransform_o2_j[149] = 1.0297442586766545E+00;
    brain_B.HoughTransform_o2_j[150] = 1.0471975511965976E+00;
    brain_B.HoughTransform_o2_j[151] = 1.0646508437165410E+00;
    brain_B.HoughTransform_o2_j[152] = 1.0821041362364843E+00;
    brain_B.HoughTransform_o2_j[153] = 1.0995574287564276E+00;
    brain_B.HoughTransform_o2_j[154] = 1.1170107212763709E+00;
    brain_B.HoughTransform_o2_j[155] = 1.1344640137963142E+00;
    brain_B.HoughTransform_o2_j[156] = 1.1519173063162575E+00;
    brain_B.HoughTransform_o2_j[157] = 1.1693705988362009E+00;
    brain_B.HoughTransform_o2_j[158] = 1.1868238913561442E+00;
    brain_B.HoughTransform_o2_j[159] = 1.2042771838760873E+00;
    brain_B.HoughTransform_o2_j[160] = 1.2217304763960306E+00;
    brain_B.HoughTransform_o2_j[161] = 1.2391837689159739E+00;
    brain_B.HoughTransform_o2_j[162] = 1.2566370614359172E+00;
    brain_B.HoughTransform_o2_j[163] = 1.2740903539558606E+00;
    brain_B.HoughTransform_o2_j[164] = 1.2915436464758039E+00;
    brain_B.HoughTransform_o2_j[165] = 1.3089969389957472E+00;
    brain_B.HoughTransform_o2_j[166] = 1.3264502315156905E+00;
    brain_B.HoughTransform_o2_j[167] = 1.3439035240356338E+00;
    brain_B.HoughTransform_o2_j[168] = 1.3613568165555769E+00;
    brain_B.HoughTransform_o2_j[169] = 1.3788101090755203E+00;
    brain_B.HoughTransform_o2_j[170] = 1.3962634015954636E+00;
    brain_B.HoughTransform_o2_j[171] = 1.4137166941154069E+00;
    brain_B.HoughTransform_o2_j[172] = 1.4311699866353502E+00;
    brain_B.HoughTransform_o2_j[173] = 1.4486232791552935E+00;
    brain_B.HoughTransform_o2_j[174] = 1.4660765716752369E+00;
    brain_B.HoughTransform_o2_j[175] = 1.4835298641951802E+00;
    brain_B.HoughTransform_o2_j[176] = 1.5009831567151235E+00;
    brain_B.HoughTransform_o2_j[177] = 1.5184364492350666E+00;
    brain_B.HoughTransform_o2_j[178] = 1.5358897417550099E+00;
    brain_B.HoughTransform_o2_j[179] = 1.5533430342749532E+00;
    brain_B.HoughTransform_o3_d[0] = -143.0;
    brain_B.HoughTransform_o3_d[1] = -142.0;
    brain_B.HoughTransform_o3_d[2] = -141.0;
    brain_B.HoughTransform_o3_d[3] = -140.0;
    brain_B.HoughTransform_o3_d[4] = -139.0;
    brain_B.HoughTransform_o3_d[5] = -138.0;
    brain_B.HoughTransform_o3_d[6] = -137.0;
    brain_B.HoughTransform_o3_d[7] = -136.0;
    brain_B.HoughTransform_o3_d[8] = -135.0;
    brain_B.HoughTransform_o3_d[9] = -134.0;
    brain_B.HoughTransform_o3_d[10] = -133.0;
    brain_B.HoughTransform_o3_d[11] = -132.0;
    brain_B.HoughTransform_o3_d[12] = -131.0;
    brain_B.HoughTransform_o3_d[13] = -130.0;
    brain_B.HoughTransform_o3_d[14] = -129.0;
    brain_B.HoughTransform_o3_d[15] = -128.0;
    brain_B.HoughTransform_o3_d[16] = -127.0;
    brain_B.HoughTransform_o3_d[17] = -126.0;
    brain_B.HoughTransform_o3_d[18] = -125.0;
    brain_B.HoughTransform_o3_d[19] = -124.0;
    brain_B.HoughTransform_o3_d[20] = -123.0;
    brain_B.HoughTransform_o3_d[21] = -122.0;
    brain_B.HoughTransform_o3_d[22] = -121.0;
    brain_B.HoughTransform_o3_d[23] = -120.0;
    brain_B.HoughTransform_o3_d[24] = -119.0;
    brain_B.HoughTransform_o3_d[25] = -118.0;
    brain_B.HoughTransform_o3_d[26] = -117.0;
    brain_B.HoughTransform_o3_d[27] = -116.0;
    brain_B.HoughTransform_o3_d[28] = -115.0;
    brain_B.HoughTransform_o3_d[29] = -114.0;
    brain_B.HoughTransform_o3_d[30] = -113.0;
    brain_B.HoughTransform_o3_d[31] = -112.0;
    brain_B.HoughTransform_o3_d[32] = -111.0;
    brain_B.HoughTransform_o3_d[33] = -110.0;
    brain_B.HoughTransform_o3_d[34] = -109.0;
    brain_B.HoughTransform_o3_d[35] = -108.0;
    brain_B.HoughTransform_o3_d[36] = -107.0;
    brain_B.HoughTransform_o3_d[37] = -106.0;
    brain_B.HoughTransform_o3_d[38] = -105.0;
    brain_B.HoughTransform_o3_d[39] = -104.0;
    brain_B.HoughTransform_o3_d[40] = -103.0;
    brain_B.HoughTransform_o3_d[41] = -102.0;
    brain_B.HoughTransform_o3_d[42] = -101.0;
    brain_B.HoughTransform_o3_d[43] = -100.0;
    brain_B.HoughTransform_o3_d[44] = -99.0;
    brain_B.HoughTransform_o3_d[45] = -98.0;
    brain_B.HoughTransform_o3_d[46] = -97.0;
    brain_B.HoughTransform_o3_d[47] = -96.0;
    brain_B.HoughTransform_o3_d[48] = -95.0;
    brain_B.HoughTransform_o3_d[49] = -94.0;
    brain_B.HoughTransform_o3_d[50] = -93.0;
    brain_B.HoughTransform_o3_d[51] = -92.0;
    brain_B.HoughTransform_o3_d[52] = -91.0;
    brain_B.HoughTransform_o3_d[53] = -90.0;
    brain_B.HoughTransform_o3_d[54] = -89.0;
    brain_B.HoughTransform_o3_d[55] = -88.0;
    brain_B.HoughTransform_o3_d[56] = -87.0;
    brain_B.HoughTransform_o3_d[57] = -86.0;
    brain_B.HoughTransform_o3_d[58] = -85.0;
    brain_B.HoughTransform_o3_d[59] = -84.0;
    brain_B.HoughTransform_o3_d[60] = -83.0;
    brain_B.HoughTransform_o3_d[61] = -82.0;
    brain_B.HoughTransform_o3_d[62] = -81.0;
    brain_B.HoughTransform_o3_d[63] = -80.0;
    brain_B.HoughTransform_o3_d[64] = -79.0;
    brain_B.HoughTransform_o3_d[65] = -78.0;
    brain_B.HoughTransform_o3_d[66] = -77.0;
    brain_B.HoughTransform_o3_d[67] = -76.0;
    brain_B.HoughTransform_o3_d[68] = -75.0;
    brain_B.HoughTransform_o3_d[69] = -74.0;
    brain_B.HoughTransform_o3_d[70] = -73.0;
    brain_B.HoughTransform_o3_d[71] = -72.0;
    brain_B.HoughTransform_o3_d[72] = -71.0;
    brain_B.HoughTransform_o3_d[73] = -70.0;
    brain_B.HoughTransform_o3_d[74] = -69.0;
    brain_B.HoughTransform_o3_d[75] = -68.0;
    brain_B.HoughTransform_o3_d[76] = -67.0;
    brain_B.HoughTransform_o3_d[77] = -66.0;
    brain_B.HoughTransform_o3_d[78] = -65.0;
    brain_B.HoughTransform_o3_d[79] = -64.0;
    brain_B.HoughTransform_o3_d[80] = -63.0;
    brain_B.HoughTransform_o3_d[81] = -62.0;
    brain_B.HoughTransform_o3_d[82] = -61.0;
    brain_B.HoughTransform_o3_d[83] = -60.0;
    brain_B.HoughTransform_o3_d[84] = -59.0;
    brain_B.HoughTransform_o3_d[85] = -58.0;
    brain_B.HoughTransform_o3_d[86] = -57.0;
    brain_B.HoughTransform_o3_d[87] = -56.0;
    brain_B.HoughTransform_o3_d[88] = -55.0;
    brain_B.HoughTransform_o3_d[89] = -54.0;
    brain_B.HoughTransform_o3_d[90] = -53.0;
    brain_B.HoughTransform_o3_d[91] = -52.0;
    brain_B.HoughTransform_o3_d[92] = -51.0;
    brain_B.HoughTransform_o3_d[93] = -50.0;
    brain_B.HoughTransform_o3_d[94] = -49.0;
    brain_B.HoughTransform_o3_d[95] = -48.0;
    brain_B.HoughTransform_o3_d[96] = -47.0;
    brain_B.HoughTransform_o3_d[97] = -46.0;
    brain_B.HoughTransform_o3_d[98] = -45.0;
    brain_B.HoughTransform_o3_d[99] = -44.0;
    brain_B.HoughTransform_o3_d[100] = -43.0;
    brain_B.HoughTransform_o3_d[101] = -42.0;
    brain_B.HoughTransform_o3_d[102] = -41.0;
    brain_B.HoughTransform_o3_d[103] = -40.0;
    brain_B.HoughTransform_o3_d[104] = -39.0;
    brain_B.HoughTransform_o3_d[105] = -38.0;
    brain_B.HoughTransform_o3_d[106] = -37.0;
    brain_B.HoughTransform_o3_d[107] = -36.0;
    brain_B.HoughTransform_o3_d[108] = -35.0;
    brain_B.HoughTransform_o3_d[109] = -34.0;
    brain_B.HoughTransform_o3_d[110] = -33.0;
    brain_B.HoughTransform_o3_d[111] = -32.0;
    brain_B.HoughTransform_o3_d[112] = -31.0;
    brain_B.HoughTransform_o3_d[113] = -30.0;
    brain_B.HoughTransform_o3_d[114] = -29.0;
    brain_B.HoughTransform_o3_d[115] = -28.0;
    brain_B.HoughTransform_o3_d[116] = -27.0;
    brain_B.HoughTransform_o3_d[117] = -26.0;
    brain_B.HoughTransform_o3_d[118] = -25.0;
    brain_B.HoughTransform_o3_d[119] = -24.0;
    brain_B.HoughTransform_o3_d[120] = -23.0;
    brain_B.HoughTransform_o3_d[121] = -22.0;
    brain_B.HoughTransform_o3_d[122] = -21.0;
    brain_B.HoughTransform_o3_d[123] = -20.0;
    brain_B.HoughTransform_o3_d[124] = -19.0;
    brain_B.HoughTransform_o3_d[125] = -18.0;
    brain_B.HoughTransform_o3_d[126] = -17.0;
    brain_B.HoughTransform_o3_d[127] = -16.0;
    brain_B.HoughTransform_o3_d[128] = -15.0;
    brain_B.HoughTransform_o3_d[129] = -14.0;
    brain_B.HoughTransform_o3_d[130] = -13.0;
    brain_B.HoughTransform_o3_d[131] = -12.0;
    brain_B.HoughTransform_o3_d[132] = -11.0;
    brain_B.HoughTransform_o3_d[133] = -10.0;
    brain_B.HoughTransform_o3_d[134] = -9.0;
    brain_B.HoughTransform_o3_d[135] = -8.0;
    brain_B.HoughTransform_o3_d[136] = -7.0;
    brain_B.HoughTransform_o3_d[137] = -6.0;
    brain_B.HoughTransform_o3_d[138] = -5.0;
    brain_B.HoughTransform_o3_d[139] = -4.0;
    brain_B.HoughTransform_o3_d[140] = -3.0;
    brain_B.HoughTransform_o3_d[141] = -2.0;
    brain_B.HoughTransform_o3_d[142] = -1.0;
    brain_B.HoughTransform_o3_d[143] = 0.0;
    brain_B.HoughTransform_o3_d[144] = 1.0;
    brain_B.HoughTransform_o3_d[145] = 2.0;
    brain_B.HoughTransform_o3_d[146] = 3.0;
    brain_B.HoughTransform_o3_d[147] = 4.0;
    brain_B.HoughTransform_o3_d[148] = 5.0;
    brain_B.HoughTransform_o3_d[149] = 6.0;
    brain_B.HoughTransform_o3_d[150] = 7.0;
    brain_B.HoughTransform_o3_d[151] = 8.0;
    brain_B.HoughTransform_o3_d[152] = 9.0;
    brain_B.HoughTransform_o3_d[153] = 10.0;
    brain_B.HoughTransform_o3_d[154] = 11.0;
    brain_B.HoughTransform_o3_d[155] = 12.0;
    brain_B.HoughTransform_o3_d[156] = 13.0;
    brain_B.HoughTransform_o3_d[157] = 14.0;
    brain_B.HoughTransform_o3_d[158] = 15.0;
    brain_B.HoughTransform_o3_d[159] = 16.0;
    brain_B.HoughTransform_o3_d[160] = 17.0;
    brain_B.HoughTransform_o3_d[161] = 18.0;
    brain_B.HoughTransform_o3_d[162] = 19.0;
    brain_B.HoughTransform_o3_d[163] = 20.0;
    brain_B.HoughTransform_o3_d[164] = 21.0;
    brain_B.HoughTransform_o3_d[165] = 22.0;
    brain_B.HoughTransform_o3_d[166] = 23.0;
    brain_B.HoughTransform_o3_d[167] = 24.0;
    brain_B.HoughTransform_o3_d[168] = 25.0;
    brain_B.HoughTransform_o3_d[169] = 26.0;
    brain_B.HoughTransform_o3_d[170] = 27.0;
    brain_B.HoughTransform_o3_d[171] = 28.0;
    brain_B.HoughTransform_o3_d[172] = 29.0;
    brain_B.HoughTransform_o3_d[173] = 30.0;
    brain_B.HoughTransform_o3_d[174] = 31.0;
    brain_B.HoughTransform_o3_d[175] = 32.0;
    brain_B.HoughTransform_o3_d[176] = 33.0;
    brain_B.HoughTransform_o3_d[177] = 34.0;
    brain_B.HoughTransform_o3_d[178] = 35.0;
    brain_B.HoughTransform_o3_d[179] = 36.0;
    brain_B.HoughTransform_o3_d[180] = 37.0;
    brain_B.HoughTransform_o3_d[181] = 38.0;
    brain_B.HoughTransform_o3_d[182] = 39.0;
    brain_B.HoughTransform_o3_d[183] = 40.0;
    brain_B.HoughTransform_o3_d[184] = 41.0;
    brain_B.HoughTransform_o3_d[185] = 42.0;
    brain_B.HoughTransform_o3_d[186] = 43.0;
    brain_B.HoughTransform_o3_d[187] = 44.0;
    brain_B.HoughTransform_o3_d[188] = 45.0;
    brain_B.HoughTransform_o3_d[189] = 46.0;
    brain_B.HoughTransform_o3_d[190] = 47.0;
    brain_B.HoughTransform_o3_d[191] = 48.0;
    brain_B.HoughTransform_o3_d[192] = 49.0;
    brain_B.HoughTransform_o3_d[193] = 50.0;
    brain_B.HoughTransform_o3_d[194] = 51.0;
    brain_B.HoughTransform_o3_d[195] = 52.0;
    brain_B.HoughTransform_o3_d[196] = 53.0;
    brain_B.HoughTransform_o3_d[197] = 54.0;
    brain_B.HoughTransform_o3_d[198] = 55.0;
    brain_B.HoughTransform_o3_d[199] = 56.0;
    brain_B.HoughTransform_o3_d[200] = 57.0;
    brain_B.HoughTransform_o3_d[201] = 58.0;
    brain_B.HoughTransform_o3_d[202] = 59.0;
    brain_B.HoughTransform_o3_d[203] = 60.0;
    brain_B.HoughTransform_o3_d[204] = 61.0;
    brain_B.HoughTransform_o3_d[205] = 62.0;
    brain_B.HoughTransform_o3_d[206] = 63.0;
    brain_B.HoughTransform_o3_d[207] = 64.0;
    brain_B.HoughTransform_o3_d[208] = 65.0;
    brain_B.HoughTransform_o3_d[209] = 66.0;
    brain_B.HoughTransform_o3_d[210] = 67.0;
    brain_B.HoughTransform_o3_d[211] = 68.0;
    brain_B.HoughTransform_o3_d[212] = 69.0;
    brain_B.HoughTransform_o3_d[213] = 70.0;
    brain_B.HoughTransform_o3_d[214] = 71.0;
    brain_B.HoughTransform_o3_d[215] = 72.0;
    brain_B.HoughTransform_o3_d[216] = 73.0;
    brain_B.HoughTransform_o3_d[217] = 74.0;
    brain_B.HoughTransform_o3_d[218] = 75.0;
    brain_B.HoughTransform_o3_d[219] = 76.0;
    brain_B.HoughTransform_o3_d[220] = 77.0;
    brain_B.HoughTransform_o3_d[221] = 78.0;
    brain_B.HoughTransform_o3_d[222] = 79.0;
    brain_B.HoughTransform_o3_d[223] = 80.0;
    brain_B.HoughTransform_o3_d[224] = 81.0;
    brain_B.HoughTransform_o3_d[225] = 82.0;
    brain_B.HoughTransform_o3_d[226] = 83.0;
    brain_B.HoughTransform_o3_d[227] = 84.0;
    brain_B.HoughTransform_o3_d[228] = 85.0;
    brain_B.HoughTransform_o3_d[229] = 86.0;
    brain_B.HoughTransform_o3_d[230] = 87.0;
    brain_B.HoughTransform_o3_d[231] = 88.0;
    brain_B.HoughTransform_o3_d[232] = 89.0;
    brain_B.HoughTransform_o3_d[233] = 90.0;
    brain_B.HoughTransform_o3_d[234] = 91.0;
    brain_B.HoughTransform_o3_d[235] = 92.0;
    brain_B.HoughTransform_o3_d[236] = 93.0;
    brain_B.HoughTransform_o3_d[237] = 94.0;
    brain_B.HoughTransform_o3_d[238] = 95.0;
    brain_B.HoughTransform_o3_d[239] = 96.0;
    brain_B.HoughTransform_o3_d[240] = 97.0;
    brain_B.HoughTransform_o3_d[241] = 98.0;
    brain_B.HoughTransform_o3_d[242] = 99.0;
    brain_B.HoughTransform_o3_d[243] = 100.0;
    brain_B.HoughTransform_o3_d[244] = 101.0;
    brain_B.HoughTransform_o3_d[245] = 102.0;
    brain_B.HoughTransform_o3_d[246] = 103.0;
    brain_B.HoughTransform_o3_d[247] = 104.0;
    brain_B.HoughTransform_o3_d[248] = 105.0;
    brain_B.HoughTransform_o3_d[249] = 106.0;
    brain_B.HoughTransform_o3_d[250] = 107.0;
    brain_B.HoughTransform_o3_d[251] = 108.0;
    brain_B.HoughTransform_o3_d[252] = 109.0;
    brain_B.HoughTransform_o3_d[253] = 110.0;
    brain_B.HoughTransform_o3_d[254] = 111.0;
    brain_B.HoughTransform_o3_d[255] = 112.0;
    brain_B.HoughTransform_o3_d[256] = 113.0;
    brain_B.HoughTransform_o3_d[257] = 114.0;
    brain_B.HoughTransform_o3_d[258] = 115.0;
    brain_B.HoughTransform_o3_d[259] = 116.0;
    brain_B.HoughTransform_o3_d[260] = 117.0;
    brain_B.HoughTransform_o3_d[261] = 118.0;
    brain_B.HoughTransform_o3_d[262] = 119.0;
    brain_B.HoughTransform_o3_d[263] = 120.0;
    brain_B.HoughTransform_o3_d[264] = 121.0;
    brain_B.HoughTransform_o3_d[265] = 122.0;
    brain_B.HoughTransform_o3_d[266] = 123.0;
    brain_B.HoughTransform_o3_d[267] = 124.0;
    brain_B.HoughTransform_o3_d[268] = 125.0;
    brain_B.HoughTransform_o3_d[269] = 126.0;
    brain_B.HoughTransform_o3_d[270] = 127.0;
    brain_B.HoughTransform_o3_d[271] = 128.0;
    brain_B.HoughTransform_o3_d[272] = 129.0;
    brain_B.HoughTransform_o3_d[273] = 130.0;
    brain_B.HoughTransform_o3_d[274] = 131.0;
    brain_B.HoughTransform_o3_d[275] = 132.0;
    brain_B.HoughTransform_o3_d[276] = 133.0;
    brain_B.HoughTransform_o3_d[277] = 134.0;
    brain_B.HoughTransform_o3_d[278] = 135.0;
    brain_B.HoughTransform_o3_d[279] = 136.0;
    brain_B.HoughTransform_o3_d[280] = 137.0;
    brain_B.HoughTransform_o3_d[281] = 138.0;
    brain_B.HoughTransform_o3_d[282] = 139.0;
    brain_B.HoughTransform_o3_d[283] = 140.0;
    brain_B.HoughTransform_o3_d[284] = 141.0;
    brain_B.HoughTransform_o3_d[285] = 142.0;
    brain_B.HoughTransform_o3_d[286] = 143.0;
    brain_B.HoughTransform_o2_h[0] = -1.5707963267948966E+00;
    brain_B.HoughTransform_o2_h[1] = -1.5533430342749532E+00;
    brain_B.HoughTransform_o2_h[2] = -1.5358897417550099E+00;
    brain_B.HoughTransform_o2_h[3] = -1.5184364492350666E+00;
    brain_B.HoughTransform_o2_h[4] = -1.5009831567151235E+00;
    brain_B.HoughTransform_o2_h[5] = -1.4835298641951802E+00;
    brain_B.HoughTransform_o2_h[6] = -1.4660765716752369E+00;
    brain_B.HoughTransform_o2_h[7] = -1.4486232791552935E+00;
    brain_B.HoughTransform_o2_h[8] = -1.4311699866353502E+00;
    brain_B.HoughTransform_o2_h[9] = -1.4137166941154069E+00;
    brain_B.HoughTransform_o2_h[10] = -1.3962634015954636E+00;
    brain_B.HoughTransform_o2_h[11] = -1.3788101090755203E+00;
    brain_B.HoughTransform_o2_h[12] = -1.3613568165555769E+00;
    brain_B.HoughTransform_o2_h[13] = -1.3439035240356338E+00;
    brain_B.HoughTransform_o2_h[14] = -1.3264502315156905E+00;
    brain_B.HoughTransform_o2_h[15] = -1.3089969389957472E+00;
    brain_B.HoughTransform_o2_h[16] = -1.2915436464758039E+00;
    brain_B.HoughTransform_o2_h[17] = -1.2740903539558606E+00;
    brain_B.HoughTransform_o2_h[18] = -1.2566370614359172E+00;
    brain_B.HoughTransform_o2_h[19] = -1.2391837689159739E+00;
    brain_B.HoughTransform_o2_h[20] = -1.2217304763960306E+00;
    brain_B.HoughTransform_o2_h[21] = -1.2042771838760873E+00;
    brain_B.HoughTransform_o2_h[22] = -1.1868238913561442E+00;
    brain_B.HoughTransform_o2_h[23] = -1.1693705988362009E+00;
    brain_B.HoughTransform_o2_h[24] = -1.1519173063162575E+00;
    brain_B.HoughTransform_o2_h[25] = -1.1344640137963142E+00;
    brain_B.HoughTransform_o2_h[26] = -1.1170107212763709E+00;
    brain_B.HoughTransform_o2_h[27] = -1.0995574287564276E+00;
    brain_B.HoughTransform_o2_h[28] = -1.0821041362364843E+00;
    brain_B.HoughTransform_o2_h[29] = -1.0646508437165410E+00;
    brain_B.HoughTransform_o2_h[30] = -1.0471975511965976E+00;
    brain_B.HoughTransform_o2_h[31] = -1.0297442586766545E+00;
    brain_B.HoughTransform_o2_h[32] = -1.0122909661567112E+00;
    brain_B.HoughTransform_o2_h[33] = -9.9483767363676789E-01;
    brain_B.HoughTransform_o2_h[34] = -9.7738438111682457E-01;
    brain_B.HoughTransform_o2_h[35] = -9.5993108859688125E-01;
    brain_B.HoughTransform_o2_h[36] = -9.4247779607693793E-01;
    brain_B.HoughTransform_o2_h[37] = -9.2502450355699462E-01;
    brain_B.HoughTransform_o2_h[38] = -9.0757121103705141E-01;
    brain_B.HoughTransform_o2_h[39] = -8.9011791851710809E-01;
    brain_B.HoughTransform_o2_h[40] = -8.7266462599716477E-01;
    brain_B.HoughTransform_o2_h[41] = -8.5521133347722145E-01;
    brain_B.HoughTransform_o2_h[42] = -8.3775804095727824E-01;
    brain_B.HoughTransform_o2_h[43] = -8.2030474843733492E-01;
    brain_B.HoughTransform_o2_h[44] = -8.0285145591739160E-01;
    brain_B.HoughTransform_o2_h[45] = -7.8539816339744828E-01;
    brain_B.HoughTransform_o2_h[46] = -7.6794487087750496E-01;
    brain_B.HoughTransform_o2_h[47] = -7.5049157835756175E-01;
    brain_B.HoughTransform_o2_h[48] = -7.3303828583761843E-01;
    brain_B.HoughTransform_o2_h[49] = -7.1558499331767511E-01;
    brain_B.HoughTransform_o2_h[50] = -6.9813170079773179E-01;
    brain_B.HoughTransform_o2_h[51] = -6.8067840827778847E-01;
    brain_B.HoughTransform_o2_h[52] = -6.6322511575784526E-01;
    brain_B.HoughTransform_o2_h[53] = -6.4577182323790194E-01;
    brain_B.HoughTransform_o2_h[54] = -6.2831853071795862E-01;
    brain_B.HoughTransform_o2_h[55] = -6.1086523819801530E-01;
    brain_B.HoughTransform_o2_h[56] = -5.9341194567807209E-01;
    brain_B.HoughTransform_o2_h[57] = -5.7595865315812877E-01;
    brain_B.HoughTransform_o2_h[58] = -5.5850536063818546E-01;
    brain_B.HoughTransform_o2_h[59] = -5.4105206811824214E-01;
    brain_B.HoughTransform_o2_h[60] = -5.2359877559829882E-01;
    brain_B.HoughTransform_o2_h[61] = -5.0614548307835561E-01;
    brain_B.HoughTransform_o2_h[62] = -4.8869219055841229E-01;
    brain_B.HoughTransform_o2_h[63] = -4.7123889803846897E-01;
    brain_B.HoughTransform_o2_h[64] = -4.5378560551852570E-01;
    brain_B.HoughTransform_o2_h[65] = -4.3633231299858238E-01;
    brain_B.HoughTransform_o2_h[66] = -4.1887902047863912E-01;
    brain_B.HoughTransform_o2_h[67] = -4.0142572795869580E-01;
    brain_B.HoughTransform_o2_h[68] = -3.8397243543875248E-01;
    brain_B.HoughTransform_o2_h[69] = -3.6651914291880922E-01;
    brain_B.HoughTransform_o2_h[70] = -3.4906585039886590E-01;
    brain_B.HoughTransform_o2_h[71] = -3.3161255787892263E-01;
    brain_B.HoughTransform_o2_h[72] = -3.1415926535897931E-01;
    brain_B.HoughTransform_o2_h[73] = -2.9670597283903605E-01;
    brain_B.HoughTransform_o2_h[74] = -2.7925268031909273E-01;
    brain_B.HoughTransform_o2_h[75] = -2.6179938779914941E-01;
    brain_B.HoughTransform_o2_h[76] = -2.4434609527920614E-01;
    brain_B.HoughTransform_o2_h[77] = -2.2689280275926285E-01;
    brain_B.HoughTransform_o2_h[78] = -2.0943951023931956E-01;
    brain_B.HoughTransform_o2_h[79] = -1.9198621771937624E-01;
    brain_B.HoughTransform_o2_h[80] = -1.7453292519943295E-01;
    brain_B.HoughTransform_o2_h[81] = -1.5707963267948966E-01;
    brain_B.HoughTransform_o2_h[82] = -1.3962634015954636E-01;
    brain_B.HoughTransform_o2_h[83] = -1.2217304763960307E-01;
    brain_B.HoughTransform_o2_h[84] = -1.0471975511965978E-01;
    brain_B.HoughTransform_o2_h[85] = -8.7266462599716474E-02;
    brain_B.HoughTransform_o2_h[86] = -6.9813170079773182E-02;
    brain_B.HoughTransform_o2_h[87] = -5.2359877559829890E-02;
    brain_B.HoughTransform_o2_h[88] = -3.4906585039886591E-02;
    brain_B.HoughTransform_o2_h[89] = -1.7453292519943295E-02;
    brain_B.HoughTransform_o2_h[90] = 0.0;
    brain_B.HoughTransform_o2_h[91] = 1.7453292519943295E-02;
    brain_B.HoughTransform_o2_h[92] = 3.4906585039886591E-02;
    brain_B.HoughTransform_o2_h[93] = 5.2359877559829890E-02;
    brain_B.HoughTransform_o2_h[94] = 6.9813170079773182E-02;
    brain_B.HoughTransform_o2_h[95] = 8.7266462599716474E-02;
    brain_B.HoughTransform_o2_h[96] = 1.0471975511965978E-01;
    brain_B.HoughTransform_o2_h[97] = 1.2217304763960307E-01;
    brain_B.HoughTransform_o2_h[98] = 1.3962634015954636E-01;
    brain_B.HoughTransform_o2_h[99] = 1.5707963267948966E-01;
    brain_B.HoughTransform_o2_h[100] = 1.7453292519943295E-01;
    brain_B.HoughTransform_o2_h[101] = 1.9198621771937624E-01;
    brain_B.HoughTransform_o2_h[102] = 2.0943951023931956E-01;
    brain_B.HoughTransform_o2_h[103] = 2.2689280275926285E-01;
    brain_B.HoughTransform_o2_h[104] = 2.4434609527920614E-01;
    brain_B.HoughTransform_o2_h[105] = 2.6179938779914941E-01;
    brain_B.HoughTransform_o2_h[106] = 2.7925268031909273E-01;
    brain_B.HoughTransform_o2_h[107] = 2.9670597283903605E-01;
    brain_B.HoughTransform_o2_h[108] = 3.1415926535897931E-01;
    brain_B.HoughTransform_o2_h[109] = 3.3161255787892263E-01;
    brain_B.HoughTransform_o2_h[110] = 3.4906585039886590E-01;
    brain_B.HoughTransform_o2_h[111] = 3.6651914291880922E-01;
    brain_B.HoughTransform_o2_h[112] = 3.8397243543875248E-01;
    brain_B.HoughTransform_o2_h[113] = 4.0142572795869580E-01;
    brain_B.HoughTransform_o2_h[114] = 4.1887902047863912E-01;
    brain_B.HoughTransform_o2_h[115] = 4.3633231299858238E-01;
    brain_B.HoughTransform_o2_h[116] = 4.5378560551852570E-01;
    brain_B.HoughTransform_o2_h[117] = 4.7123889803846897E-01;
    brain_B.HoughTransform_o2_h[118] = 4.8869219055841229E-01;
    brain_B.HoughTransform_o2_h[119] = 5.0614548307835561E-01;
    brain_B.HoughTransform_o2_h[120] = 5.2359877559829882E-01;
    brain_B.HoughTransform_o2_h[121] = 5.4105206811824214E-01;
    brain_B.HoughTransform_o2_h[122] = 5.5850536063818546E-01;
    brain_B.HoughTransform_o2_h[123] = 5.7595865315812877E-01;
    brain_B.HoughTransform_o2_h[124] = 5.9341194567807209E-01;
    brain_B.HoughTransform_o2_h[125] = 6.1086523819801530E-01;
    brain_B.HoughTransform_o2_h[126] = 6.2831853071795862E-01;
    brain_B.HoughTransform_o2_h[127] = 6.4577182323790194E-01;
    brain_B.HoughTransform_o2_h[128] = 6.6322511575784526E-01;
    brain_B.HoughTransform_o2_h[129] = 6.8067840827778847E-01;
    brain_B.HoughTransform_o2_h[130] = 6.9813170079773179E-01;
    brain_B.HoughTransform_o2_h[131] = 7.1558499331767511E-01;
    brain_B.HoughTransform_o2_h[132] = 7.3303828583761843E-01;
    brain_B.HoughTransform_o2_h[133] = 7.5049157835756175E-01;
    brain_B.HoughTransform_o2_h[134] = 7.6794487087750496E-01;
    brain_B.HoughTransform_o2_h[135] = 7.8539816339744828E-01;
    brain_B.HoughTransform_o2_h[136] = 8.0285145591739160E-01;
    brain_B.HoughTransform_o2_h[137] = 8.2030474843733492E-01;
    brain_B.HoughTransform_o2_h[138] = 8.3775804095727824E-01;
    brain_B.HoughTransform_o2_h[139] = 8.5521133347722145E-01;
    brain_B.HoughTransform_o2_h[140] = 8.7266462599716477E-01;
    brain_B.HoughTransform_o2_h[141] = 8.9011791851710809E-01;
    brain_B.HoughTransform_o2_h[142] = 9.0757121103705141E-01;
    brain_B.HoughTransform_o2_h[143] = 9.2502450355699462E-01;
    brain_B.HoughTransform_o2_h[144] = 9.4247779607693793E-01;
    brain_B.HoughTransform_o2_h[145] = 9.5993108859688125E-01;
    brain_B.HoughTransform_o2_h[146] = 9.7738438111682457E-01;
    brain_B.HoughTransform_o2_h[147] = 9.9483767363676789E-01;
    brain_B.HoughTransform_o2_h[148] = 1.0122909661567112E+00;
    brain_B.HoughTransform_o2_h[149] = 1.0297442586766545E+00;
    brain_B.HoughTransform_o2_h[150] = 1.0471975511965976E+00;
    brain_B.HoughTransform_o2_h[151] = 1.0646508437165410E+00;
    brain_B.HoughTransform_o2_h[152] = 1.0821041362364843E+00;
    brain_B.HoughTransform_o2_h[153] = 1.0995574287564276E+00;
    brain_B.HoughTransform_o2_h[154] = 1.1170107212763709E+00;
    brain_B.HoughTransform_o2_h[155] = 1.1344640137963142E+00;
    brain_B.HoughTransform_o2_h[156] = 1.1519173063162575E+00;
    brain_B.HoughTransform_o2_h[157] = 1.1693705988362009E+00;
    brain_B.HoughTransform_o2_h[158] = 1.1868238913561442E+00;
    brain_B.HoughTransform_o2_h[159] = 1.2042771838760873E+00;
    brain_B.HoughTransform_o2_h[160] = 1.2217304763960306E+00;
    brain_B.HoughTransform_o2_h[161] = 1.2391837689159739E+00;
    brain_B.HoughTransform_o2_h[162] = 1.2566370614359172E+00;
    brain_B.HoughTransform_o2_h[163] = 1.2740903539558606E+00;
    brain_B.HoughTransform_o2_h[164] = 1.2915436464758039E+00;
    brain_B.HoughTransform_o2_h[165] = 1.3089969389957472E+00;
    brain_B.HoughTransform_o2_h[166] = 1.3264502315156905E+00;
    brain_B.HoughTransform_o2_h[167] = 1.3439035240356338E+00;
    brain_B.HoughTransform_o2_h[168] = 1.3613568165555769E+00;
    brain_B.HoughTransform_o2_h[169] = 1.3788101090755203E+00;
    brain_B.HoughTransform_o2_h[170] = 1.3962634015954636E+00;
    brain_B.HoughTransform_o2_h[171] = 1.4137166941154069E+00;
    brain_B.HoughTransform_o2_h[172] = 1.4311699866353502E+00;
    brain_B.HoughTransform_o2_h[173] = 1.4486232791552935E+00;
    brain_B.HoughTransform_o2_h[174] = 1.4660765716752369E+00;
    brain_B.HoughTransform_o2_h[175] = 1.4835298641951802E+00;
    brain_B.HoughTransform_o2_h[176] = 1.5009831567151235E+00;
    brain_B.HoughTransform_o2_h[177] = 1.5184364492350666E+00;
    brain_B.HoughTransform_o2_h[178] = 1.5358897417550099E+00;
    brain_B.HoughTransform_o2_h[179] = 1.5533430342749532E+00;
    brain_B.HoughTransform_o3_j[0] = -143.0;
    brain_B.HoughTransform_o3_j[1] = -142.0;
    brain_B.HoughTransform_o3_j[2] = -141.0;
    brain_B.HoughTransform_o3_j[3] = -140.0;
    brain_B.HoughTransform_o3_j[4] = -139.0;
    brain_B.HoughTransform_o3_j[5] = -138.0;
    brain_B.HoughTransform_o3_j[6] = -137.0;
    brain_B.HoughTransform_o3_j[7] = -136.0;
    brain_B.HoughTransform_o3_j[8] = -135.0;
    brain_B.HoughTransform_o3_j[9] = -134.0;
    brain_B.HoughTransform_o3_j[10] = -133.0;
    brain_B.HoughTransform_o3_j[11] = -132.0;
    brain_B.HoughTransform_o3_j[12] = -131.0;
    brain_B.HoughTransform_o3_j[13] = -130.0;
    brain_B.HoughTransform_o3_j[14] = -129.0;
    brain_B.HoughTransform_o3_j[15] = -128.0;
    brain_B.HoughTransform_o3_j[16] = -127.0;
    brain_B.HoughTransform_o3_j[17] = -126.0;
    brain_B.HoughTransform_o3_j[18] = -125.0;
    brain_B.HoughTransform_o3_j[19] = -124.0;
    brain_B.HoughTransform_o3_j[20] = -123.0;
    brain_B.HoughTransform_o3_j[21] = -122.0;
    brain_B.HoughTransform_o3_j[22] = -121.0;
    brain_B.HoughTransform_o3_j[23] = -120.0;
    brain_B.HoughTransform_o3_j[24] = -119.0;
    brain_B.HoughTransform_o3_j[25] = -118.0;
    brain_B.HoughTransform_o3_j[26] = -117.0;
    brain_B.HoughTransform_o3_j[27] = -116.0;
    brain_B.HoughTransform_o3_j[28] = -115.0;
    brain_B.HoughTransform_o3_j[29] = -114.0;
    brain_B.HoughTransform_o3_j[30] = -113.0;
    brain_B.HoughTransform_o3_j[31] = -112.0;
    brain_B.HoughTransform_o3_j[32] = -111.0;
    brain_B.HoughTransform_o3_j[33] = -110.0;
    brain_B.HoughTransform_o3_j[34] = -109.0;
    brain_B.HoughTransform_o3_j[35] = -108.0;
    brain_B.HoughTransform_o3_j[36] = -107.0;
    brain_B.HoughTransform_o3_j[37] = -106.0;
    brain_B.HoughTransform_o3_j[38] = -105.0;
    brain_B.HoughTransform_o3_j[39] = -104.0;
    brain_B.HoughTransform_o3_j[40] = -103.0;
    brain_B.HoughTransform_o3_j[41] = -102.0;
    brain_B.HoughTransform_o3_j[42] = -101.0;
    brain_B.HoughTransform_o3_j[43] = -100.0;
    brain_B.HoughTransform_o3_j[44] = -99.0;
    brain_B.HoughTransform_o3_j[45] = -98.0;
    brain_B.HoughTransform_o3_j[46] = -97.0;
    brain_B.HoughTransform_o3_j[47] = -96.0;
    brain_B.HoughTransform_o3_j[48] = -95.0;
    brain_B.HoughTransform_o3_j[49] = -94.0;
    brain_B.HoughTransform_o3_j[50] = -93.0;
    brain_B.HoughTransform_o3_j[51] = -92.0;
    brain_B.HoughTransform_o3_j[52] = -91.0;
    brain_B.HoughTransform_o3_j[53] = -90.0;
    brain_B.HoughTransform_o3_j[54] = -89.0;
    brain_B.HoughTransform_o3_j[55] = -88.0;
    brain_B.HoughTransform_o3_j[56] = -87.0;
    brain_B.HoughTransform_o3_j[57] = -86.0;
    brain_B.HoughTransform_o3_j[58] = -85.0;
    brain_B.HoughTransform_o3_j[59] = -84.0;
    brain_B.HoughTransform_o3_j[60] = -83.0;
    brain_B.HoughTransform_o3_j[61] = -82.0;
    brain_B.HoughTransform_o3_j[62] = -81.0;
    brain_B.HoughTransform_o3_j[63] = -80.0;
    brain_B.HoughTransform_o3_j[64] = -79.0;
    brain_B.HoughTransform_o3_j[65] = -78.0;
    brain_B.HoughTransform_o3_j[66] = -77.0;
    brain_B.HoughTransform_o3_j[67] = -76.0;
    brain_B.HoughTransform_o3_j[68] = -75.0;
    brain_B.HoughTransform_o3_j[69] = -74.0;
    brain_B.HoughTransform_o3_j[70] = -73.0;
    brain_B.HoughTransform_o3_j[71] = -72.0;
    brain_B.HoughTransform_o3_j[72] = -71.0;
    brain_B.HoughTransform_o3_j[73] = -70.0;
    brain_B.HoughTransform_o3_j[74] = -69.0;
    brain_B.HoughTransform_o3_j[75] = -68.0;
    brain_B.HoughTransform_o3_j[76] = -67.0;
    brain_B.HoughTransform_o3_j[77] = -66.0;
    brain_B.HoughTransform_o3_j[78] = -65.0;
    brain_B.HoughTransform_o3_j[79] = -64.0;
    brain_B.HoughTransform_o3_j[80] = -63.0;
    brain_B.HoughTransform_o3_j[81] = -62.0;
    brain_B.HoughTransform_o3_j[82] = -61.0;
    brain_B.HoughTransform_o3_j[83] = -60.0;
    brain_B.HoughTransform_o3_j[84] = -59.0;
    brain_B.HoughTransform_o3_j[85] = -58.0;
    brain_B.HoughTransform_o3_j[86] = -57.0;
    brain_B.HoughTransform_o3_j[87] = -56.0;
    brain_B.HoughTransform_o3_j[88] = -55.0;
    brain_B.HoughTransform_o3_j[89] = -54.0;
    brain_B.HoughTransform_o3_j[90] = -53.0;
    brain_B.HoughTransform_o3_j[91] = -52.0;
    brain_B.HoughTransform_o3_j[92] = -51.0;
    brain_B.HoughTransform_o3_j[93] = -50.0;
    brain_B.HoughTransform_o3_j[94] = -49.0;
    brain_B.HoughTransform_o3_j[95] = -48.0;
    brain_B.HoughTransform_o3_j[96] = -47.0;
    brain_B.HoughTransform_o3_j[97] = -46.0;
    brain_B.HoughTransform_o3_j[98] = -45.0;
    brain_B.HoughTransform_o3_j[99] = -44.0;
    brain_B.HoughTransform_o3_j[100] = -43.0;
    brain_B.HoughTransform_o3_j[101] = -42.0;
    brain_B.HoughTransform_o3_j[102] = -41.0;
    brain_B.HoughTransform_o3_j[103] = -40.0;
    brain_B.HoughTransform_o3_j[104] = -39.0;
    brain_B.HoughTransform_o3_j[105] = -38.0;
    brain_B.HoughTransform_o3_j[106] = -37.0;
    brain_B.HoughTransform_o3_j[107] = -36.0;
    brain_B.HoughTransform_o3_j[108] = -35.0;
    brain_B.HoughTransform_o3_j[109] = -34.0;
    brain_B.HoughTransform_o3_j[110] = -33.0;
    brain_B.HoughTransform_o3_j[111] = -32.0;
    brain_B.HoughTransform_o3_j[112] = -31.0;
    brain_B.HoughTransform_o3_j[113] = -30.0;
    brain_B.HoughTransform_o3_j[114] = -29.0;
    brain_B.HoughTransform_o3_j[115] = -28.0;
    brain_B.HoughTransform_o3_j[116] = -27.0;
    brain_B.HoughTransform_o3_j[117] = -26.0;
    brain_B.HoughTransform_o3_j[118] = -25.0;
    brain_B.HoughTransform_o3_j[119] = -24.0;
    brain_B.HoughTransform_o3_j[120] = -23.0;
    brain_B.HoughTransform_o3_j[121] = -22.0;
    brain_B.HoughTransform_o3_j[122] = -21.0;
    brain_B.HoughTransform_o3_j[123] = -20.0;
    brain_B.HoughTransform_o3_j[124] = -19.0;
    brain_B.HoughTransform_o3_j[125] = -18.0;
    brain_B.HoughTransform_o3_j[126] = -17.0;
    brain_B.HoughTransform_o3_j[127] = -16.0;
    brain_B.HoughTransform_o3_j[128] = -15.0;
    brain_B.HoughTransform_o3_j[129] = -14.0;
    brain_B.HoughTransform_o3_j[130] = -13.0;
    brain_B.HoughTransform_o3_j[131] = -12.0;
    brain_B.HoughTransform_o3_j[132] = -11.0;
    brain_B.HoughTransform_o3_j[133] = -10.0;
    brain_B.HoughTransform_o3_j[134] = -9.0;
    brain_B.HoughTransform_o3_j[135] = -8.0;
    brain_B.HoughTransform_o3_j[136] = -7.0;
    brain_B.HoughTransform_o3_j[137] = -6.0;
    brain_B.HoughTransform_o3_j[138] = -5.0;
    brain_B.HoughTransform_o3_j[139] = -4.0;
    brain_B.HoughTransform_o3_j[140] = -3.0;
    brain_B.HoughTransform_o3_j[141] = -2.0;
    brain_B.HoughTransform_o3_j[142] = -1.0;
    brain_B.HoughTransform_o3_j[143] = 0.0;
    brain_B.HoughTransform_o3_j[144] = 1.0;
    brain_B.HoughTransform_o3_j[145] = 2.0;
    brain_B.HoughTransform_o3_j[146] = 3.0;
    brain_B.HoughTransform_o3_j[147] = 4.0;
    brain_B.HoughTransform_o3_j[148] = 5.0;
    brain_B.HoughTransform_o3_j[149] = 6.0;
    brain_B.HoughTransform_o3_j[150] = 7.0;
    brain_B.HoughTransform_o3_j[151] = 8.0;
    brain_B.HoughTransform_o3_j[152] = 9.0;
    brain_B.HoughTransform_o3_j[153] = 10.0;
    brain_B.HoughTransform_o3_j[154] = 11.0;
    brain_B.HoughTransform_o3_j[155] = 12.0;
    brain_B.HoughTransform_o3_j[156] = 13.0;
    brain_B.HoughTransform_o3_j[157] = 14.0;
    brain_B.HoughTransform_o3_j[158] = 15.0;
    brain_B.HoughTransform_o3_j[159] = 16.0;
    brain_B.HoughTransform_o3_j[160] = 17.0;
    brain_B.HoughTransform_o3_j[161] = 18.0;
    brain_B.HoughTransform_o3_j[162] = 19.0;
    brain_B.HoughTransform_o3_j[163] = 20.0;
    brain_B.HoughTransform_o3_j[164] = 21.0;
    brain_B.HoughTransform_o3_j[165] = 22.0;
    brain_B.HoughTransform_o3_j[166] = 23.0;
    brain_B.HoughTransform_o3_j[167] = 24.0;
    brain_B.HoughTransform_o3_j[168] = 25.0;
    brain_B.HoughTransform_o3_j[169] = 26.0;
    brain_B.HoughTransform_o3_j[170] = 27.0;
    brain_B.HoughTransform_o3_j[171] = 28.0;
    brain_B.HoughTransform_o3_j[172] = 29.0;
    brain_B.HoughTransform_o3_j[173] = 30.0;
    brain_B.HoughTransform_o3_j[174] = 31.0;
    brain_B.HoughTransform_o3_j[175] = 32.0;
    brain_B.HoughTransform_o3_j[176] = 33.0;
    brain_B.HoughTransform_o3_j[177] = 34.0;
    brain_B.HoughTransform_o3_j[178] = 35.0;
    brain_B.HoughTransform_o3_j[179] = 36.0;
    brain_B.HoughTransform_o3_j[180] = 37.0;
    brain_B.HoughTransform_o3_j[181] = 38.0;
    brain_B.HoughTransform_o3_j[182] = 39.0;
    brain_B.HoughTransform_o3_j[183] = 40.0;
    brain_B.HoughTransform_o3_j[184] = 41.0;
    brain_B.HoughTransform_o3_j[185] = 42.0;
    brain_B.HoughTransform_o3_j[186] = 43.0;
    brain_B.HoughTransform_o3_j[187] = 44.0;
    brain_B.HoughTransform_o3_j[188] = 45.0;
    brain_B.HoughTransform_o3_j[189] = 46.0;
    brain_B.HoughTransform_o3_j[190] = 47.0;
    brain_B.HoughTransform_o3_j[191] = 48.0;
    brain_B.HoughTransform_o3_j[192] = 49.0;
    brain_B.HoughTransform_o3_j[193] = 50.0;
    brain_B.HoughTransform_o3_j[194] = 51.0;
    brain_B.HoughTransform_o3_j[195] = 52.0;
    brain_B.HoughTransform_o3_j[196] = 53.0;
    brain_B.HoughTransform_o3_j[197] = 54.0;
    brain_B.HoughTransform_o3_j[198] = 55.0;
    brain_B.HoughTransform_o3_j[199] = 56.0;
    brain_B.HoughTransform_o3_j[200] = 57.0;
    brain_B.HoughTransform_o3_j[201] = 58.0;
    brain_B.HoughTransform_o3_j[202] = 59.0;
    brain_B.HoughTransform_o3_j[203] = 60.0;
    brain_B.HoughTransform_o3_j[204] = 61.0;
    brain_B.HoughTransform_o3_j[205] = 62.0;
    brain_B.HoughTransform_o3_j[206] = 63.0;
    brain_B.HoughTransform_o3_j[207] = 64.0;
    brain_B.HoughTransform_o3_j[208] = 65.0;
    brain_B.HoughTransform_o3_j[209] = 66.0;
    brain_B.HoughTransform_o3_j[210] = 67.0;
    brain_B.HoughTransform_o3_j[211] = 68.0;
    brain_B.HoughTransform_o3_j[212] = 69.0;
    brain_B.HoughTransform_o3_j[213] = 70.0;
    brain_B.HoughTransform_o3_j[214] = 71.0;
    brain_B.HoughTransform_o3_j[215] = 72.0;
    brain_B.HoughTransform_o3_j[216] = 73.0;
    brain_B.HoughTransform_o3_j[217] = 74.0;
    brain_B.HoughTransform_o3_j[218] = 75.0;
    brain_B.HoughTransform_o3_j[219] = 76.0;
    brain_B.HoughTransform_o3_j[220] = 77.0;
    brain_B.HoughTransform_o3_j[221] = 78.0;
    brain_B.HoughTransform_o3_j[222] = 79.0;
    brain_B.HoughTransform_o3_j[223] = 80.0;
    brain_B.HoughTransform_o3_j[224] = 81.0;
    brain_B.HoughTransform_o3_j[225] = 82.0;
    brain_B.HoughTransform_o3_j[226] = 83.0;
    brain_B.HoughTransform_o3_j[227] = 84.0;
    brain_B.HoughTransform_o3_j[228] = 85.0;
    brain_B.HoughTransform_o3_j[229] = 86.0;
    brain_B.HoughTransform_o3_j[230] = 87.0;
    brain_B.HoughTransform_o3_j[231] = 88.0;
    brain_B.HoughTransform_o3_j[232] = 89.0;
    brain_B.HoughTransform_o3_j[233] = 90.0;
    brain_B.HoughTransform_o3_j[234] = 91.0;
    brain_B.HoughTransform_o3_j[235] = 92.0;
    brain_B.HoughTransform_o3_j[236] = 93.0;
    brain_B.HoughTransform_o3_j[237] = 94.0;
    brain_B.HoughTransform_o3_j[238] = 95.0;
    brain_B.HoughTransform_o3_j[239] = 96.0;
    brain_B.HoughTransform_o3_j[240] = 97.0;
    brain_B.HoughTransform_o3_j[241] = 98.0;
    brain_B.HoughTransform_o3_j[242] = 99.0;
    brain_B.HoughTransform_o3_j[243] = 100.0;
    brain_B.HoughTransform_o3_j[244] = 101.0;
    brain_B.HoughTransform_o3_j[245] = 102.0;
    brain_B.HoughTransform_o3_j[246] = 103.0;
    brain_B.HoughTransform_o3_j[247] = 104.0;
    brain_B.HoughTransform_o3_j[248] = 105.0;
    brain_B.HoughTransform_o3_j[249] = 106.0;
    brain_B.HoughTransform_o3_j[250] = 107.0;
    brain_B.HoughTransform_o3_j[251] = 108.0;
    brain_B.HoughTransform_o3_j[252] = 109.0;
    brain_B.HoughTransform_o3_j[253] = 110.0;
    brain_B.HoughTransform_o3_j[254] = 111.0;
    brain_B.HoughTransform_o3_j[255] = 112.0;
    brain_B.HoughTransform_o3_j[256] = 113.0;
    brain_B.HoughTransform_o3_j[257] = 114.0;
    brain_B.HoughTransform_o3_j[258] = 115.0;
    brain_B.HoughTransform_o3_j[259] = 116.0;
    brain_B.HoughTransform_o3_j[260] = 117.0;
    brain_B.HoughTransform_o3_j[261] = 118.0;
    brain_B.HoughTransform_o3_j[262] = 119.0;
    brain_B.HoughTransform_o3_j[263] = 120.0;
    brain_B.HoughTransform_o3_j[264] = 121.0;
    brain_B.HoughTransform_o3_j[265] = 122.0;
    brain_B.HoughTransform_o3_j[266] = 123.0;
    brain_B.HoughTransform_o3_j[267] = 124.0;
    brain_B.HoughTransform_o3_j[268] = 125.0;
    brain_B.HoughTransform_o3_j[269] = 126.0;
    brain_B.HoughTransform_o3_j[270] = 127.0;
    brain_B.HoughTransform_o3_j[271] = 128.0;
    brain_B.HoughTransform_o3_j[272] = 129.0;
    brain_B.HoughTransform_o3_j[273] = 130.0;
    brain_B.HoughTransform_o3_j[274] = 131.0;
    brain_B.HoughTransform_o3_j[275] = 132.0;
    brain_B.HoughTransform_o3_j[276] = 133.0;
    brain_B.HoughTransform_o3_j[277] = 134.0;
    brain_B.HoughTransform_o3_j[278] = 135.0;
    brain_B.HoughTransform_o3_j[279] = 136.0;
    brain_B.HoughTransform_o3_j[280] = 137.0;
    brain_B.HoughTransform_o3_j[281] = 138.0;
    brain_B.HoughTransform_o3_j[282] = 139.0;
    brain_B.HoughTransform_o3_j[283] = 140.0;
    brain_B.HoughTransform_o3_j[284] = 141.0;
    brain_B.HoughTransform_o3_j[285] = 142.0;
    brain_B.HoughTransform_o3_j[286] = 143.0;
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
void brain_terminate(void)
{
  /* (no terminate code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
