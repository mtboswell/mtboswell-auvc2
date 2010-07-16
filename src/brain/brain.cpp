/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.658
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Fri Jul 16 12:40:52 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Fri Jul 16 12:40:53 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/StateFlow Functions' */
#define brain_IN_AlignWithPath         (1U)
#define brain_IN_ApproachBuoys         (1U)
#define brain_IN_ApproachFirstBuoy     (1U)
#define brain_IN_ApproachHedge         (1U)
#define brain_IN_ApproachSecondBuoy    (2U)
#define brain_IN_Autonomous            (1U)
#define brain_IN_Breach                (1U)
#define brain_IN_Buoy                  (2U)
#define brain_IN_BuoyDone              (2U)
#define brain_IN_Buoys                 (2U)
#define brain_IN_CheckAxisRatio        (1U)
#define brain_IN_ChooseState           (3U)
#define brain_IN_CompareAxisRatio      (1U)
#define brain_IN_ControlledRC          (3U)
#define brain_IN_ControlledRC_m        (2U)
#define brain_IN_Done                  (2U)
#define brain_IN_Done_m                (1U)
#define brain_IN_DropMechanism         (4U)
#define brain_IN_FindBuoys             (3U)
#define brain_IN_FindSecondBuoy        (3U)
#define brain_IN_Finish                (5U)
#define brain_IN_Finished              (2U)
#define brain_IN_Finished_m            (1U)
#define brain_IN_FirstDirections       (1U)
#define brain_IN_FollowOnePath         (6U)
#define brain_IN_FollowOnePath1        (6U)
#define brain_IN_FollowOnePath2        (7U)
#define brain_IN_FollowOnePath3        (8U)
#define brain_IN_FollowOnePath4        (9U)
#define brain_IN_GateDone              (1U)
#define brain_IN_GetActualDirection    (2U)
#define brain_IN_GetHeadings           (1U)
#define brain_IN_GetInCorrectState     (7U)
#define brain_IN_GetInitialDirection   (3U)
#define brain_IN_GetMajorAxis          (2U)
#define brain_IN_GetPingerHeading      (2U)
#define brain_IN_GoThoughGate          (2U)
#define brain_IN_GoThroughHedge        (4U)
#define brain_IN_GoToNext              (3U)
#define brain_IN_GoUpNCheck            (2U)
#define brain_IN_Hedge1                (10U)
#define brain_IN_Hedge2                (11U)
#define brain_IN_IncreaseAxisRatio     (5U)
#define brain_IN_JumpHedge             (8U)
#define brain_IN_LocatePinger          (12U)
#define brain_IN_LocatePinger_m        (9U)
#define brain_IN_MakeSure              (3U)
#define brain_IN_Move                  (2U)
#define brain_IN_Move_m                (3U)
#define brain_IN_NO_ACTIVE_CHILD       (0U)
#define brain_IN_NotRunning            (10U)
#define brain_IN_NotRunning_m          (1U)
#define brain_IN_OnePath               (1U)
#define brain_IN_PositionOver          (3U)
#define brain_IN_RecognizeHedge        (6U)
#define brain_IN_RecognizePath         (2U)
#define brain_IN_Running               (2U)
#define brain_IN_SecondDirections      (4U)
#define brain_IN_Start                 (11U)
#define brain_IN_StartFinished         (2U)
#define brain_IN_Start_m               (13U)
#define brain_IN_Turn30Degrees         (5U)
#define brain_IN_TurnLeft              (1U)
#define brain_IN_TurnRight             (2U)
#define brain_IN_ValidationGate        (12U)
#define brain_IN_ValidationGate_m      (14U)

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
static void brain_min(const real_T eml_varargin_1[10], real_T *eml_minval,
                      real_T *eml_indx);

/* Forward declaration for local functions */
static void brain_Outputs(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3,
  rtDW_StateFlowFunctionsBuoysFin *localDW);
static void brain_c3_brain(const real_T rtu_LabMatrix[19200], real_T
  rtu_num_colors, rtB_StateFlowFunctionsBuoysFind *localB,
  rtDW_StateFlowFunctionsBuoysFin *localDW);

/* Forward declaration for local functions */
static void brain_conv2(const real32_T eml_arg1[19200], const real32_T eml_arg2
  [9], real32_T eml_c[18644]);
static void brain_c14_brain(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB);

/* Forward declaration for local functions */
static void brain_c28_brain(rtB_StateFlowFunctionsBuoysIter *localB);

/* Forward declaration for local functions */
static void brain_Outputs_f(const boolean_T eml_U0[19200], int32_T eml_Y0[50],
  real_T eml_Y1[100], real_T eml_Y2[50], real_T eml_Y3[50], uint8_T *eml_Y4,
  rtDW_StateFlowFunctionsBuoysF_e *localDW);
static void brain_c5_brain(const real_T rtu_LabelMatrix[19200], real_T
  rtu_num_colors, rtB_StateFlowFunctionsBuoysFi_d *localB,
  rtDW_StateFlowFunctionsBuoysF_e *localDW);

/* Forward declaration for local functions */
static void brain_max(const real_T eml_varargin_1[10], real_T *eml_maxval,
                      real_T *eml_indx);

/* Forward declaration for local functions */
static void brain_enter_internal_Autonomous(void);
static void brain_ValidationGate_m(void);
static void brain_Autonomous(void);
static real_T brain_countareas(real_T sf_Size, real_T sf_count1);
static real_T brain_Turn45Degrees(real_T sf_CHeading, real_T sf_TurnD);
static void brain_FindSecondBuoy(void);
static void brain_ApproachBuoys(void);
static real_T brain_countimages(real_T sf_Image1, real_T sf_OldImage, real_T
  sf_count1);
static void brain_exit_internal_Buoys(void);
static void brain_Buoys(void);
static void brain_max_l(const real_T eml_varargin_1[71820], real_T eml_maxval
  [180], real_T eml_indx[180]);
static void brain_max_lw(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_refp1_round(real_T *eml_x);
static void brain_c30_brain(void);
static void brain_max_h(const real_T eml_varargin_1[2], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_OnePath(void);
static void brain_RecognizePath(void);
static void brain_GetInCorrectState(void);
static real_T brain_GetStrafeDirection(real_T sf_AxisDif);
static void exit_internal_GetInitialDirecti(void);
static void brain_GetInitialDirection(void);
static void brain_IncreaseAxisRatio(void);
static void brain_RecognizeHedge(void);
static void brain_exit_internal_JumpHedge(void);
static void brain_exit_atomic_JumpHedge(void);
static void brain_JumpHedge(void);
static void brain_LocatePinger(void);
static real_T brain_countimages_m(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1);
static void brain_ValidationGate(void);
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
 * Output and update for atomic system:
 *    '<S10>/Embedded MATLAB Function1'
 *    '<S23>/Embedded MATLAB Function1'
 *    '<S28>/Embedded MATLAB Function1'
 *    '<S22>/Embedded MATLAB Function1'
 */
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB)
{
  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function1': '<S46>:1' */
  /*  This function finds the center of an image */
  /* '<S46>:1:6' */
  /* '<S46>:1:7' */
  localB->XCenter = 80.0;
  localB->YCenter = 60.0;
}

/* Function for Embedded MATLAB: '<S10>/Embedded MATLAB Function' */
static void brain_min(const real_T eml_varargin_1[10], real_T *eml_minval,
                      real_T *eml_indx)
{
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  boolean_T eml_exitg;
  eml_mtmp = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = FALSE;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = TRUE;
    eml_k = 2;
    eml_exitg = FALSE;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 11)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = FALSE;
        eml_exitg = TRUE;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = TRUE;
    }
  } else {
    eml_guard = TRUE;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 11; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] < eml_mtmp) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_minval = eml_mtmp;
  *eml_indx = (real_T)eml_itmp;
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApp_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysApp *localDW)
{
  localDW->StateFlowFunctionsBuoysApproa_m = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApproach(real_T rtu_B_Hue, real_T rtu_B_Sat, real_T
  rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T rtu_Ref_Colors
  [150], real_T rtu_Num_Colors, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsBuoysAppr *localB, rtDW_StateFlowFunctionsBuoysApp
  *localDW)
{
  int32_T i;
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  int32_T idxROI;
  int32_T row;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  uint32_T OutCode;
  real_T eml_min_dist;
  real_T eml_i;
  real_T eml_Dist[10];
  real_T eml_MinDist;
  real_T eml_index;
  int8_T rtb_index_h;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T numBlobs;
  real_T rtb_TmpSignalConversionAtDrawMa[2];
  int32_T rtb_BuoyBlobAnalysis_o1_m[10];
  real_T rtb_BuoyBlobAnalysis_o2_a[20];
  real_T rtb_BuoyBlobAnalysis_o3_l[10];
  int32_T i_0;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;
  localDW->StateFlowFunctionsBuoysApproa_a = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsBuoysApproa_m;
  localDW->StateFlowFunctionsBuoysApproa_m = brain_M->Timing.clockTick0;

  /* S-Function (svipcolorconv): '<S51>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_min_dist = 6.0 * rtu_B_Hue;
  eml_index = (real_T)(uint32_T)(eml_min_dist - 1.3322676295501878E-015);
  eml_min_dist -= eml_index;
  eml_i = 1.0 - rtu_B_Sat;
  eml_MinDist = 1.0 - rtu_B_Sat * eml_min_dist;
  eml_min_dist = rtu_B_Sat * eml_min_dist + eml_i;
  if (eml_index == 0.0) {
    cc = 1.0;
    cc_0 = eml_min_dist;
    cc_1 = eml_i;
  } else if (eml_index == 1.0) {
    cc = eml_MinDist;
    cc_0 = 1.0;
    cc_1 = eml_i;
  } else if (eml_index == 2.0) {
    cc = eml_i;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (eml_index == 3.0) {
    cc = eml_i;
    cc_0 = eml_MinDist;
    cc_1 = 1.0;
  } else if (eml_index == 4.0) {
    cc = eml_min_dist;
    cc_0 = eml_i;
    cc_1 = 1.0;
  } else {
    if (eml_index == 5.0) {
      cc = 1.0;
      cc_0 = eml_i;
      cc_1 = eml_MinDist;
    }
  }

  if (cc > cc_0) {
    eml_min_dist = cc;
  } else {
    eml_min_dist = cc_0;
  }

  if (!(eml_min_dist > cc_1)) {
    eml_min_dist = cc_1;
  }

  eml_min_dist = rtu_B_Value / eml_min_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o1 = eml_min_dist * cc;
  localB->ColorSpaceConversion_o2 = eml_min_dist * cc_0;
  localB->ColorSpaceConversion_o3 = eml_min_dist * cc_1;

  /* S-Function (svipcolorconv): '<S51>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-002) {
    eml_min_dist = localB->ColorSpaceConversion_o1 / 1.2923054468333254E+001;
  } else {
    eml_min_dist = rt_pow_snf((localB->ColorSpaceConversion_o1 +
      5.5000519817226361E-002) / 1.0550005198172263E+000, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-002) {
    eml_i = localB->ColorSpaceConversion_o2 / 1.2923054468333254E+001;
  } else {
    eml_i = rt_pow_snf((localB->ColorSpaceConversion_o2 +
                        5.5000519817226361E-002) / 1.0550005198172263E+000, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-002) {
    eml_MinDist = localB->ColorSpaceConversion_o3 / 1.2923054468333254E+001;
  } else {
    eml_MinDist = rt_pow_snf((localB->ColorSpaceConversion_o3 +
      5.5000519817226361E-002) / 1.0550005198172263E+000, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  eml_index = (4.1239079926596001E-001 * eml_min_dist + 3.5758433938388001E-001 *
               eml_i) + 1.8048078840182999E-001 * eml_MinDist;
  cc = (2.1263900587151000E-001 * eml_min_dist + 7.1516867876776002E-001 * eml_i)
    + 7.2192315360729994E-002 * eml_MinDist;
  eml_min_dist = (1.9330818715590000E-002 * eml_min_dist +
                  1.1919477979463000E-001 * eml_i) + 9.5053215224966003E-001 *
    eml_MinDist;

  /* Make sure that the output is in [0..1] range; clip if necessary */
  if (eml_index > 1.0) {
    eml_index = 1.0;
  } else {
    if (eml_index < 0.0) {
      eml_index = 0.0;
    }
  }

  if (cc > 1.0) {
    cc = 1.0;
  } else {
    if (cc < 0.0) {
      cc = 0.0;
    }
  }

  if (eml_min_dist > 1.0) {
    eml_min_dist = 1.0;
  } else {
    if (eml_min_dist < 0.0) {
      eml_min_dist = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = eml_index;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = eml_min_dist;

  /* Convert from XYZ to L*a*b* */
  eml_min_dist = localB->ColorSpaceConversion1_o1 / 9.6419865576090003E-001;
  eml_MinDist = localB->ColorSpaceConversion1_o3 / 8.2511648322104003E-001;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_min_dist > 8.8564516790356311E-003) {
    eml_index = rt_pow_snf(eml_min_dist, 3.3333333333333331E-001);
  } else {
    eml_index = 7.7870370370370372E+000 * eml_min_dist + 1.3793103448275862E-001;
  }

  if (localB->ColorSpaceConversion1_o2 > 8.8564516790356311E-003) {
    eml_i = rt_pow_snf(localB->ColorSpaceConversion1_o2, 3.3333333333333331E-001);
  } else {
    eml_i = 7.7870370370370372E+000 * localB->ColorSpaceConversion1_o2 +
      1.3793103448275862E-001;
  }

  if (eml_MinDist > 8.8564516790356311E-003) {
    eml_min_dist = rt_pow_snf(eml_MinDist, 3.3333333333333331E-001);
  } else {
    eml_min_dist = 7.7870370370370372E+000 * eml_MinDist +
      1.3793103448275862E-001;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * eml_i - 16.0;
  localB->ColorSpaceConversion1_o2 = (eml_index - eml_i) * 500.0;
  localB->ColorSpaceConversion1_o3 = (eml_i - eml_min_dist) * 200.0;

  /* Embedded MATLAB: '<S47>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Choose Closest Color': '<S50>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S50>:1:5' */
  eml_min_dist = 1000.0;

  /* '<S50>:1:11' */
  rtb_index_h = 1;

  /* '<S50>:1:12' */
  for (eml_i = 1.0; eml_i <= rtu_Num_Colors; eml_i++) {
    /* '<S50>:1:12' */
    /* '<S50>:1:13' */
    eml_MinDist = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o2 -
      rtu_Ref_Colors[(int32_T)eml_i + 49], 2.0) * 1.5 + rt_pow_snf
                        (localB->ColorSpaceConversion1_o1 - rtu_Ref_Colors
                         [(int32_T)eml_i - 1], 2.0)) + rt_pow_snf
                       (localB->ColorSpaceConversion1_o3 - rtu_Ref_Colors
                        [(int32_T)eml_i + 99], 2.0) * 1.5);
    if (eml_MinDist < eml_min_dist) {
      /* '<S50>:1:14' */
      /* '<S50>:1:15' */
      eml_min_dist = eml_MinDist;

      /* '<S50>:1:16' */
      cc = floor(eml_i + 0.5);
      if (cc < 128.0) {
        rtb_index_h = (int8_T)cc;
      } else {
        rtb_index_h = MAX_int8_T;
      }
    }
  }

  /* RelationalOperator: '<S47>/Relational Operator' */
  for (i_0 = 0; i_0 < 19200; i_0++) {
    localB->BW[i_0] = (rtu_LabMatrix[i_0] == (real_T)rtb_index_h);
  }

  /* S-Function (svipblob): '<S10>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  line_idx_6 = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[line_idx_6] = (uint8_T)(localB->BW[i] ?
        255 : 0);
      i++;
      line_idx_6++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[line_idx_6] = 0U;
    line_idx_6++;
    localDW->BuoyBlobAnalysis_PAD_DW[line_idx_6] = 0U;
    line_idx_6++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i + line_idx_6] = 0U;
  }

  n = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n_0 = 0; n_0 < 160; n_0++) {
    line_idx_6 = 1;
    i_0 = n * 122;
    for (line_idx_5 = 0; line_idx_5 < 120; line_idx_5++) {
      numBlobs = (uint32_T)(i_0 + line_idx_6);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(line_idx_6 -
          1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (row = 0; row < 8; row++) {
            OutCode = numBlobs + (uint32_T)brain_ConstP.pooled27[row];
            if (localDW->BuoyBlobAnalysis_PAD_DW[OutCode] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[OutCode] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(OutCode / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(OutCode
                % 122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = OutCode;
              stackIdx++;
            }
          }
        }

        if ((BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
             brain_P.Min_Blob_Size) || (BuoyBlobAnalysis_NUM_PIX_DW[currentLabel
             - 1] > brain_P.Max_Blob_Size)) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = TRUE;
          n_0 = 160;
          line_idx_5 = 120;
        }

        if (line_idx_5 < 120) {
          currentLabel++;
        }
      }

      line_idx_6++;
    }

    n++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  i = 0;
  n = 0;
  for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
    rtb_BuoyBlobAnalysis_o1_m[n_0] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    line_idx_6 = 0;
    i_0 = 0;
    for (line_idx_5 = 0; line_idx_5 < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
         line_idx_5++) {
      line_idx_6 += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[line_idx_5 + n];
      i_0 += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[line_idx_5 + i];
    }

    rtb_TmpSignalConversionAtDrawMa[0] = (real_T)i_0 / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    rtb_TmpSignalConversionAtDrawMa[1] = (real_T)line_idx_6 / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    rtb_BuoyBlobAnalysis_o2_a[n_0 << 1] = rtb_TmpSignalConversionAtDrawMa[0];
    rtb_BuoyBlobAnalysis_o2_a[(n_0 << 1) + 1] = rtb_TmpSignalConversionAtDrawMa
      [1];
    eml_min_dist = 0.0;
    eml_index = 0.0;
    cc = 0.0;
    for (OutCode = 0U; OutCode < (uint32_T)(int32_T)
         BuoyBlobAnalysis_NUM_PIX_DW[n_0]; OutCode++) {
      eml_i = (real_T)localDW->BuoyBlobAnalysis_N_PIXLIST_DW[n + OutCode] -
        rtb_TmpSignalConversionAtDrawMa[1];
      eml_MinDist = (real_T)localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i + OutCode]
        - rtb_TmpSignalConversionAtDrawMa[0];
      eml_min_dist += eml_i * eml_i;
      eml_index += eml_MinDist * eml_MinDist;
      cc += eml_i * (-eml_MinDist);
    }

    cc_0 = eml_min_dist / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0] +
      8.3333333333333329E-002;
    eml_MinDist = eml_index / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0] +
      8.3333333333333329E-002;
    eml_min_dist = cc / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    eml_min_dist = sqrt((cc_0 - eml_MinDist) * (cc_0 - eml_MinDist) +
                        eml_min_dist * eml_min_dist * 4.0);
    eml_i = ((cc_0 + eml_MinDist) + eml_min_dist) * 8.0;
    rtb_BuoyBlobAnalysis_o3_l[n_0] = sqrt(eml_i - ((cc_0 + eml_MinDist) -
      eml_min_dist) * 8.0) / sqrt(eml_i);
    i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    n += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_m[i] = -1;
  }

  for (i = (int32_T)numBlobs << 1; i < 20; i++) {
    rtb_BuoyBlobAnalysis_o2_a[i] = -1.0;
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o3_l[i] = -1.0;
  }

  /* S-Function (svipscalenconvert): '<S10>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = localB->BW[i] ? 1.0 : 0.0;
  }

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function': '<S45>:1' */
  /*  This function will choose and return data about the blob most similar to */
  /*  the desired set of characteristics given a set of blobs */
  /*  Determine closest blob to desired Eccentricity */
  /* '<S45>:1:8' */
  for (i_0 = 0; i_0 < 10; i_0++) {
    eml_Dist[i_0] = fabs(rtb_BuoyBlobAnalysis_o3_l[i_0] -
                         brain_P.Buoy_Min_Eccentricity);
  }

  if ((rtb_BuoyBlobAnalysis_o2_a[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_a[1] ==
       -1.0)) {
    /* '<S45>:1:10' */
    /* '<S45>:1:12' */
    localB->BlobCentroidX = 80.0;

    /* '<S45>:1:13' */
    localB->BlobCentroidY = 60.0;

    /* '<S45>:1:14' */
    localB->BlobArea = -1.0;
  } else {
    brain_min(eml_Dist, &eml_min_dist, &eml_i);

    /* '<S45>:1:17' */
    eml_Dist[(int32_T)eml_i - 1] = 2.0;
    brain_min(eml_Dist, &eml_MinDist, &eml_index);
    if (eml_MinDist < eml_min_dist * 1.5) {
      /* '<S45>:1:20' */
      if (rtb_BuoyBlobAnalysis_o1_m[(int32_T)eml_i - 1] >=
          rtb_BuoyBlobAnalysis_o1_m[(int32_T)eml_index - 1]) {
        /* '<S45>:1:21' */
        /* '<S45>:1:22' */
        localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)eml_i - 1) <<
          1U) + 1];

        /* '<S45>:1:23' */
        localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)eml_i - 1) <<
          1U];

        /* '<S45>:1:24' */
        localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)eml_i - 1];
      } else {
        /* '<S45>:1:26' */
        localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)eml_index -
          1) << 1U) + 1];

        /* '<S45>:1:27' */
        localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)eml_index -
          1) << 1U];

        /* '<S45>:1:28' */
        localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)eml_index
          - 1];
      }
    } else {
      /* '<S45>:1:31' */
      localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)eml_i - 1) <<
        1U) + 1];

      /* '<S45>:1:32' */
      localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)eml_i - 1) <<
        1U];

      /* '<S45>:1:33' */
      localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)eml_i - 1];
    }
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtDraw MarkersInport2' */
  rtb_TmpSignalConversionAtDrawMa[0] = localB->BlobCentroidY;
  rtb_TmpSignalConversionAtDrawMa[1] = localB->BlobCentroidX;

  /* S-Function (svipdrawmarkers): '<S10>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)
         (&localB->ImageDataTypeConversion[0]), 19200U * sizeof(real_T));

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 2; idxROI += 2) {
    cc = rtb_TmpSignalConversionAtDrawMa[idxROI];
    if ((rtb_TmpSignalConversionAtDrawMa[idxROI] < 4.5035996273704960E+015) &&
        (rtb_TmpSignalConversionAtDrawMa[idxROI] > -4.5035996273704960E+015)) {
      cc = floor(rtb_TmpSignalConversionAtDrawMa[idxROI] + 0.5);
    }

    row = (int32_T)cc;
    cc = rtb_TmpSignalConversionAtDrawMa[idxROI + 1];
    if ((cc < 4.5035996273704960E+015) && (cc > -4.5035996273704960E+015)) {
      cc = floor(cc + 0.5);
    }

    i_0 = (int32_T)cc;
    line_idx_2 = row - 7;
    line_idx_1 = i_0 - 7;
    line_idx_0 = row + 7;
    line_idx = i_0 + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_6 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (line_idx_6 < 0) {
        numBlobs = 4U;
      } else {
        if (line_idx_6 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_4 < 0) {
        OutCode = 4U;
      } else {
        if (line_idx_4 > 119) {
          OutCode = 8U;
        }
      }

      if (line_idx_5 < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (line_idx_5 > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (line_idx_3 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (line_idx_3 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_6 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        i = line_idx_4 - line_idx_6;
        n = line_idx_3 - line_idx_5;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_6) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_6) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_5) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_5) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
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

        i = line_idx_4 - line_idx_6;
        n = line_idx_3 - line_idx_5;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      n = line_idx_5 * 120 + line_idx_6;
      while (line_idx_6 <= line_idx_4) {
        localB->DrawMarkers[n] = 0.5;
        n += 121;
        line_idx_6++;
      }
    }

    line_idx_2 = row - 7;
    line_idx_1 = i_0 + 7;
    line_idx_0 = row + 7;
    line_idx = i_0 - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    i_0 = line_idx_2;
    line_idx_5 = line_idx_1;
    line_idx_4 = line_idx_0;
    line_idx_3 = line_idx;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (i_0 < 0) {
        numBlobs = 4U;
      } else {
        if (i_0 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_4 < 0) {
        OutCode = 4U;
      } else {
        if (line_idx_4 > 119) {
          OutCode = 8U;
        }
      }

      if (line_idx_5 < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (line_idx_5 > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (line_idx_3 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (line_idx_3 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          i_0 = line_idx_2;
          line_idx_5 = line_idx_1;
        }

        i = line_idx_4 - i_0;
        n = line_idx_3 - line_idx_5;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          n_0 = (0 - i_0) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          i_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          n_0 = (119 - i_0) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          i_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_5) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            i_0 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_5) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            i_0 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
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

        i = line_idx_4 - i_0;
        n = line_idx_3 - line_idx_5;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      n = line_idx_5 * 120 + i_0;
      for (n_0 = i_0; n_0 <= line_idx_4; n_0++) {
        localB->DrawMarkers[n] = 0.5;
        n += -119;
      }
    }
  }

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S48>/Subtract' */
  eml_min_dist = localB->sf_EmbeddedMATLABFunction1.XCenter -
    localB->BlobCentroidX;

  /* SampleTimeMath: '<S53>/TSamp' incorporates:
   *  Gain: '<S52>/X-Buoy Derivative Gain'
   *
   * About '<S53>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_i = brain_P.Cam_Forward_XPosition_Kd * eml_min_dist / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S48>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S52>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S52>/X-Buoy Proportional Gain'
   *  Sum: '<S52>/Sum'
   *  Sum: '<S53>/Diff'
   *  UnitDelay: '<S53>/UD'
   *
   * Block description for '<S53>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  cc = floor((brain_P.Cam_Forward_XPosition_Kp * eml_min_dist + (eml_i -
    localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST);
  if (cc < 128.0) {
    if (cc >= -128.0) {
      rtb_index_h = (int8_T)cc;
    } else {
      rtb_index_h = MIN_int8_T;
    }
  } else {
    rtb_index_h = MAX_int8_T;
  }

  /* Sum: '<S48>/Add' incorporates:
   *  Constant: '<S48>/Vision_Forward_Velocity'
   */
  localB->Add = brain_P.Vision_Forward_Velocity + (real_T)rtb_index_h;

  /* Sum: '<S48>/Add1' incorporates:
   *  Constant: '<S48>/Constant'
   *  Constant: '<S48>/Vision_Forward_Velocity2'
   *  Product: '<S48>/Multiply'
   */
  localB->Add1 = (real_T)rtb_index_h * -1.0 + brain_P.Vision_Forward_Velocity;

  /* Sum: '<S49>/Subtract' */
  eml_MinDist = localB->BlobCentroidY -
    localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* SampleTimeMath: '<S55>/TSamp' incorporates:
   *  Gain: '<S54>/Y-Buoy Derivative Gain'
   *
   * About '<S55>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_index = brain_P.Cam_Forward_YPosition_Kd * eml_MinDist / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S49>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S54>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S54>/Y-Buoy Proportional Gain'
   *  Sum: '<S54>/Sum'
   *  Sum: '<S55>/Diff'
   *  UnitDelay: '<S55>/UD'
   *
   * Block description for '<S55>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  cc = floor((brain_P.Cam_Forward_YPosition_Kp * eml_MinDist + (eml_index -
    localDW->UD_DSTATE_n)) + localDW->YBuoyDiscreteTimeIntegrator_DST);
  if (cc < 128.0) {
    if (cc >= -128.0) {
      localB->DataTypeConversion = (int8_T)cc;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S53>/UD'
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = eml_i;

  /* Update for DiscreteIntegrator: '<S52>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S52>/X-Buoy Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * (brain_P.Cam_Forward_XPosition_Ki
    * eml_min_dist) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S55>/UD'
   * Block description for '<S55>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_n = eml_index;

  /* Update for DiscreteIntegrator: '<S54>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S54>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * (brain_P.Cam_Forward_YPosition_Ki
    * eml_MinDist) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Function for Embedded MATLAB: '<S15>/Blob Extraction' */
static void brain_Outputs(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3,
  rtDW_StateFlowFunctionsBuoysFin *localDW)
{
  boolean_T eml_maxNumBlobsReached;
  int32_T eml_loop;
  uint8_T eml_currentLabel;
  int32_T eml_idx;
  int32_T eml_n;
  uint32_T eml_stackIdx;
  uint32_T eml_pixIdx;
  uint32_T eml_start_pixIdx;
  uint32_T eml_walkerIdx;
  int32_T eml_numBlobs;
  int32_T eml_pixListMinc;
  int32_T eml_pixListNinc;
  int32_T eml_c_i;
  int32_T eml_j;
  int32_T eml_maxc;
  int32_T eml_maxr;
  real_T eml_xs;
  real_T eml_ys;
  real_T eml_xys;
  uint32_T eml_k;
  real_T eml_uyy;
  real_T eml_majorAxis;
  real_T eml_centroid_idx;
  real_T eml_centroid_idx_0;

  /* System object Outputs function: video.BlobAnalysis */
  eml_maxNumBlobsReached = FALSE;
  memset((void *)&localDW->PAD_DW[0], (int32_T)0U, 123U * sizeof(uint8_T));
  eml_currentLabel = 1U;
  eml_loop = 0;
  eml_idx = 123;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    for (eml_maxc = 0; eml_maxc < 120; eml_maxc++) {
      localDW->PAD_DW[eml_idx] = (uint8_T)(eml_U0[eml_loop] ? 255 : 0);
      eml_loop++;
      eml_idx++;
    }

    localDW->PAD_DW[eml_idx] = 0U;
    eml_idx++;
    localDW->PAD_DW[eml_idx] = 0U;
    eml_idx++;
  }

  memset((void *)&localDW->PAD_DW[eml_idx], (int32_T)0U, 121U * sizeof(uint8_T));
  eml_loop = 1;
  eml_stackIdx = 0U;
  eml_pixIdx = 0U;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    eml_maxc = 1;
    eml_idx = eml_loop * 122;
    for (eml_maxr = 0; eml_maxr < 120; eml_maxr++) {
      eml_k = (uint32_T)(eml_idx + eml_maxc);
      eml_start_pixIdx = eml_pixIdx;
      if (localDW->PAD_DW[eml_k] == 255) {
        localDW->PAD_DW[eml_k] = eml_currentLabel;
        localDW->N_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_loop - 1);
        localDW->M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_maxc - 1);
        eml_pixIdx++;
        localDW->NUM_PIX_DW[eml_currentLabel - 1] = 1U;
        localDW->STACK_DW[eml_stackIdx] = eml_k;
        eml_stackIdx++;
        while (eml_stackIdx) {
          eml_stackIdx--;
          eml_k = localDW->STACK_DW[eml_stackIdx];
          for (eml_pixListMinc = 0; eml_pixListMinc < 8; eml_pixListMinc++) {
            eml_walkerIdx = eml_k + (uint32_T)localDW->
              WALKER_RTP[eml_pixListMinc];
            if (localDW->PAD_DW[eml_walkerIdx] == 255) {
              localDW->PAD_DW[eml_walkerIdx] = eml_currentLabel;
              localDW->N_PIXLIST_DW[eml_pixIdx] = (int16_T)((int16_T)
                (eml_walkerIdx / 122U) - 1);
              localDW->M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_walkerIdx % 122U
                - 1U);
              eml_pixIdx++;
              localDW->NUM_PIX_DW[eml_currentLabel - 1] = localDW->
                NUM_PIX_DW[eml_currentLabel - 1] + 1U;
              localDW->STACK_DW[eml_stackIdx] = eml_walkerIdx;
              eml_stackIdx++;
            }
          }
        }

        if (localDW->NUM_PIX_DW[eml_currentLabel - 1] < localDW->MINAREA_RTP) {
          eml_currentLabel--;
          eml_pixIdx = eml_start_pixIdx;
        }

        if (eml_currentLabel == 50) {
          eml_maxNumBlobsReached = TRUE;
          eml_n = 160;
          eml_maxr = 120;
        }

        if (eml_maxr < 120) {
          eml_currentLabel++;
        }
      }

      eml_maxc++;
    }

    eml_loop++;
  }

  eml_numBlobs = eml_maxNumBlobsReached ? eml_currentLabel : (uint8_T)
    (eml_currentLabel - 1);
  *eml_Y3 = (uint8_T)eml_numBlobs;
  eml_pixListMinc = 0;
  eml_pixListNinc = 0;
  for (eml_c_i = 0; eml_c_i < eml_numBlobs; eml_c_i++) {
    eml_loop = 0;
    eml_n = 0;
    for (eml_j = 0; eml_j < (int32_T)localDW->NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop += localDW->N_PIXLIST_DW[eml_j + eml_pixListNinc];
      eml_n += localDW->M_PIXLIST_DW[eml_j + eml_pixListMinc];
    }

    eml_centroid_idx = (real_T)eml_n / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_centroid_idx_0 = (real_T)eml_loop / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_Y0[eml_c_i << 1] = eml_centroid_idx;
    eml_Y0[(eml_c_i << 1) + 1] = eml_centroid_idx_0;
    eml_n = 160;
    eml_idx = 120;
    eml_maxc = 0;
    eml_maxr = 0;
    for (eml_j = 0; eml_j < (int32_T)localDW->NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop = eml_j + eml_pixListNinc;
      if (localDW->N_PIXLIST_DW[eml_loop] < eml_n) {
        eml_n = localDW->N_PIXLIST_DW[eml_loop];
      }

      if (localDW->N_PIXLIST_DW[eml_loop] > eml_maxc) {
        eml_maxc = localDW->N_PIXLIST_DW[eml_loop];
      }

      eml_loop = eml_j + eml_pixListMinc;
      if (localDW->M_PIXLIST_DW[eml_loop] < eml_idx) {
        eml_idx = localDW->M_PIXLIST_DW[eml_loop];
      }

      if (localDW->M_PIXLIST_DW[eml_loop] > eml_maxr) {
        eml_maxr = localDW->M_PIXLIST_DW[eml_loop];
      }
    }

    eml_xs = 0.0;
    eml_ys = 0.0;
    eml_xys = 0.0;
    for (eml_k = 0U; eml_k < (uint32_T)(int32_T)localDW->NUM_PIX_DW[eml_c_i];
         eml_k++) {
      eml_majorAxis = (real_T)localDW->N_PIXLIST_DW[eml_pixListNinc + eml_k] -
        eml_centroid_idx_0;
      eml_uyy = (real_T)localDW->M_PIXLIST_DW[eml_pixListMinc + eml_k] -
        eml_centroid_idx;
      eml_xs += eml_majorAxis * eml_majorAxis;
      eml_ys += eml_uyy * eml_uyy;
      eml_xys += eml_majorAxis * (-eml_uyy);
    }

    eml_centroid_idx = eml_xs / (real_T)localDW->NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-002;
    eml_uyy = eml_ys / (real_T)localDW->NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-002;
    eml_xs = eml_xys / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_xs = sqrt((eml_centroid_idx - eml_uyy) * (eml_centroid_idx - eml_uyy) +
                  eml_xs * eml_xs * 4.0);
    eml_majorAxis = ((eml_centroid_idx + eml_uyy) + eml_xs) * 8.0;
    eml_Y1[eml_c_i] = sqrt(eml_majorAxis - ((eml_centroid_idx + eml_uyy) -
      eml_xs) * 8.0) / sqrt(eml_majorAxis);
    eml_Y2[eml_c_i] = (real_T)localDW->NUM_PIX_DW[eml_c_i] / (real_T)(((eml_maxr
      + 1) - eml_idx) * ((eml_maxc + 1) - eml_n));
    eml_pixListMinc += (int32_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_pixListNinc += (int32_T)localDW->NUM_PIX_DW[eml_c_i];
  }

  for (eml_loop = eml_numBlobs << 1; eml_loop < 100; eml_loop++) {
    eml_Y0[eml_loop] = localDW->F0_RTP;
  }

  for (eml_loop = eml_numBlobs; eml_loop < 50; eml_loop++) {
    eml_Y1[eml_loop] = localDW->F1_RTP;
  }

  while (eml_numBlobs < 50) {
    eml_Y2[eml_numBlobs] = localDW->F2_RTP;
    eml_numBlobs++;
  }
}

/* Function for Embedded MATLAB: '<S15>/Blob Extraction' */
static void brain_c3_brain(const real_T rtu_LabMatrix[19200], real_T
  rtu_num_colors, rtB_StateFlowFunctionsBuoysFind *localB,
  rtDW_StateFlowFunctionsBuoysFin *localDW)
{
  real_T eml_num_colors;
  uint8_T eml_TotalNum;
  real_T eml_k;
  int32_T eml_j;
  uint8_T eml_b_i;
  real_T eml_TCentroid[100];
  real_T eml_TEccent[50];
  real_T eml_TExtent[50];
  uint8_T eml_TNumBlobs;
  int32_T i;
  uint8_T tmp;
  eml_num_colors = rtu_num_colors;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/Blob Extraction': '<S63>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S63>:1:7' */
  for (i = 0; i < 19200; i++) {
    localB->eml_LogicMatrix[i] = FALSE;
  }

  /* '<S63>:1:9' */
  /* '<S63>:1:12' */
  memset((void *)&localB->Centroid[0], (int32_T)0.0, 100U * sizeof(real_T));

  /* '<S63>:1:13' */
  /* '<S63>:1:14' */
  for (i = 0; i < 50; i++) {
    localB->Eccent[i] = 0.0;
    localB->Extent[i] = 0.0;
  }

  /* '<S63>:1:16' */
  eml_TotalNum = 0U;

  /* '<S63>:1:26' */
  for (eml_k = 1.0; eml_k <= eml_num_colors; eml_k++) {
    /* '<S63>:1:26' */
    /* '<S63>:1:27' */
    for (i = 0; i < 120; i++) {
      /* '<S63>:1:27' */
      /* '<S63>:1:28' */
      for (eml_j = 0; eml_j < 160; eml_j++) {
        /* '<S63>:1:28' */
        if (rtu_LabMatrix[120 * eml_j + i] != eml_k) {
          /* '<S63>:1:29' */
          /* '<S63>:1:30' */
          localB->eml_LogicMatrix[i + 120 * eml_j] = FALSE;
        } else {
          /* '<S63>:1:32' */
          localB->eml_LogicMatrix[i + 120 * eml_j] = TRUE;
        }
      }
    }

    brain_Outputs(&localB->eml_LogicMatrix[0], eml_TCentroid, eml_TEccent,
                  eml_TExtent, &eml_TNumBlobs, localDW);
    i = eml_TotalNum + eml_TNumBlobs;
    if ((uint32_T)i > 255U) {
      tmp = MAX_uint8_T;
    } else {
      tmp = (uint8_T)i;
    }

    if (tmp < 50) {
      /* '<S63>:1:38' */
      /* '<S63>:1:39' */
      for (eml_b_i = 1U; eml_b_i <= eml_TNumBlobs; eml_b_i = (uint8_T)(uint32_T)
           (eml_b_i + 1)) {
        /* '<S63>:1:39' */
        /* '<S63>:1:40' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Centroid[tmp - 1] = eml_TCentroid[(eml_b_i - 1) << 1];

        /* '<S63>:1:41' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Centroid[tmp + 49] = eml_TCentroid[((eml_b_i - 1) << 1) + 1];

        /* '<S63>:1:42' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Eccent[tmp - 1] = eml_TEccent[eml_b_i - 1];

        /* '<S63>:1:43' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Extent[tmp - 1] = eml_TExtent[eml_b_i - 1];
      }

      /* '<S63>:1:45' */
      i = eml_TotalNum + eml_TNumBlobs;
      if ((uint32_T)i > 255U) {
        eml_TotalNum = MAX_uint8_T;
      } else {
        eml_TotalNum = (uint8_T)i;
      }
    }
  }

  localB->TotalNum = eml_TotalNum;
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysFin_Init(rtDW_StateFlowFunctionsBuoysFin *localDW)
{
  int32_T i;
  static int8_T tmp[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

  /* InitializeConditions for Embedded MATLAB: '<S15>/Blob Extraction' */
  for (i = 0; i < 8; i++) {
    localDW->WALKER_RTP[i] = tmp[i];
  }

  localDW->F0_RTP = -1.0;
  localDW->F1_RTP = -1.0;
  localDW->F2_RTP = -1.0;
  localDW->MINAREA_RTP = 5U;
  localDW->hblob = TRUE;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysFindBuoy(const real_T rtu_RGBin[57600], const real_T
  rtu_LabMatrix[19200], real_T rtu_num_colors, rtB_StateFlowFunctionsBuoysFind
  *localB, rtDW_StateFlowFunctionsBuoysFin *localDW)
{
  int32_T idxROI;
  int32_T row;
  int32_T col;
  int32_T in;
  int32_T idxPix;
  boolean_T isInBound;
  int32_T i;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T OutCode;
  real_T eml_count;
  uint8_T eml_i;
  real_T rtb_BuoyCent[100];
  int32_T i_0;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;

  /* Embedded MATLAB: '<S15>/Blob Extraction' */
  brain_c3_brain(rtu_LabMatrix, rtu_num_colors, localB, localDW);

  /* Embedded MATLAB: '<S15>/IF Buoy Conditions' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S15>/Constant3'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/IF Buoy Conditions': '<S64>:1' */
  /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
  /*  if there is a buoy present in the current image */
  /* '<S64>:1:5' */
  localB->Image = 0.0;

  /* '<S64>:1:6' */
  eml_count = 0.0;

  /* '<S64>:1:7' */
  for (i_0 = 0; i_0 < 100; i_0++) {
    rtb_BuoyCent[i_0] = 1.0;
  }

  /* '<S64>:1:9' */
  for (eml_i = 1U; eml_i <= localB->TotalNum; eml_i = (uint8_T)(uint32_T)(eml_i
        + 1)) {
    /* '<S64>:1:9' */
    if ((localB->Eccent[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
        (localB->Eccent[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
        (localB->Extent[eml_i - 1] > brain_P.Buoy_Min_Extent) && (localB->
         Extent[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
      /* '<S64>:1:10' */
      /* '<S64>:1:11' */
      eml_count++;

      /* '<S64>:1:12' */
      rtb_BuoyCent[((int32_T)eml_count - 1) << 1U] = localB->Centroid[eml_i - 1];

      /* '<S64>:1:13' */
      rtb_BuoyCent[1 + (((int32_T)eml_count - 1) << 1U)] = localB->
        Centroid[eml_i + 49];
    }
  }

  if (eml_count >= 3.0) {
    /* '<S64>:1:17' */
    /* '<S64>:1:18' */
    localB->Image = 1.0;
  }

  /* S-Function (svipdrawmarkers): '<S15>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)(&rtu_RGBin[0]), 57600U *
         sizeof(real_T));

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 100; idxROI += 2) {
    eml_count = rtb_BuoyCent[idxROI];
    if ((rtb_BuoyCent[idxROI] < 4.5035996273704960E+015) && (rtb_BuoyCent[idxROI]
         > -4.5035996273704960E+015)) {
      eml_count = floor(rtb_BuoyCent[idxROI] + 0.5);
    }

    row = (int32_T)eml_count;
    eml_count = rtb_BuoyCent[idxROI + 1];
    if ((eml_count < 4.5035996273704960E+015) && (eml_count >
         -4.5035996273704960E+015)) {
      eml_count = floor(eml_count + 0.5);
    }

    col = (int32_T)eml_count;
    line_idx = row - 7;
    line_idx_0 = col - 7;
    line_idx_1 = row + 7;
    line_idx_2 = col + 7;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    i_0 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_4 = line_idx_1;
    line_idx_5 = line_idx_2;
    while (!done) {
      in = 0;
      OutCode = 0;

      /* Determine viewport violations. */
      if (i_0 < 0) {
        in = 4;
      } else {
        if (i_0 > 119) {
          in = 8;
        }
      }

      if (line_idx_4 < 0) {
        OutCode = 4;
      } else {
        if (line_idx_4 > 119) {
          OutCode = 8;
        }
      }

      if (line_idx_3 < 0) {
        in |= 1;
      } else {
        if (line_idx_3 > 159) {
          in |= 2;
        }
      }

      if (line_idx_5 < 0) {
        OutCode |= 1;
      } else {
        if (line_idx_5 > 159) {
          OutCode |= 2;
        }
      }

      if (!((uint32_T)(in | OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)(in & OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)in != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          i_0 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = line_idx_4 - i_0;
        idxPix = line_idx_5 - line_idx_3;
        if ((uint32_T)(in & 4)) {
          /* Violated RMin. */
          in = (0 - i_0) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          i_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)(in & 8)) {
          /* Violated RMax. */
          in = (119 - i_0) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          i_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)(in & 1)) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            i_0 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            i_0 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_4 = line_idx_1;
          line_idx_5 = line_idx_2;
        }

        i = line_idx_4 - i_0;
        idxPix = line_idx_5 - line_idx_3;
        if ((uint32_T)(OutCode & 4)) {
          /* Violated RMin. */
          in = (0 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)(OutCode & 8)) {
          /* Violated RMax. */
          in = (119 - line_idx_4) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)(OutCode & 1)) {
          /* Violated CMin. */
          in = (0 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 120 + i_0;
      for (in = i_0; in <= line_idx_4; in++) {
        localB->DrawMarkers[idxPix] = 0.0;
        i_0 = idxPix + 19200;
        localB->DrawMarkers[i_0] = 0.0;
        i_0 += 19200;
        localB->DrawMarkers[i_0] = 0.0;
        idxPix += 121;
      }
    }

    line_idx = row - 7;
    line_idx_0 = col + 7;
    line_idx_1 = row + 7;
    line_idx_2 = col - 7;
    isInBound = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    i_0 = line_idx;
    line_idx_3 = line_idx_0;
    row = line_idx_1;
    line_idx_5 = line_idx_2;
    while (!done) {
      in = 0;
      OutCode = 0;

      /* Determine viewport violations. */
      if (i_0 < 0) {
        in = 4;
      } else {
        if (i_0 > 119) {
          in = 8;
        }
      }

      if (row < 0) {
        OutCode = 4;
      } else {
        if (row > 119) {
          OutCode = 8;
        }
      }

      if (line_idx_3 < 0) {
        in |= 1;
      } else {
        if (line_idx_3 > 159) {
          in |= 2;
        }
      }

      if (line_idx_5 < 0) {
        OutCode |= 1;
      } else {
        if (line_idx_5 > 159) {
          OutCode |= 2;
        }
      }

      if (!((uint32_T)(in | OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)(in & OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)in != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          i_0 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = row - i_0;
        idxPix = line_idx_5 - line_idx_3;
        if ((uint32_T)(in & 4)) {
          /* Violated RMin. */
          in = (0 - i_0) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          i_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)(in & 8)) {
          /* Violated RMax. */
          in = (119 - i_0) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          i_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)(in & 1)) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            i_0 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_3) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            i_0 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          row = line_idx_1;
          line_idx_5 = line_idx_2;
        }

        i = row - i_0;
        idxPix = line_idx_5 - line_idx_3;
        if ((uint32_T)(OutCode & 4)) {
          /* Violated RMin. */
          in = (0 - row) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          row = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)(OutCode & 8)) {
          /* Violated RMax. */
          in = (119 - row) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          row = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)(OutCode & 1)) {
          /* Violated CMin. */
          in = (0 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            row += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            row += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            row += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            row += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 120 + i_0;
      for (in = i_0; in <= row; in++) {
        localB->DrawMarkers[idxPix] = 0.0;
        i_0 = idxPix + 19200;
        localB->DrawMarkers[i_0] = 0.0;
        i_0 += 19200;
        localB->DrawMarkers[i_0] = 0.0;
        idxPix += -119;
      }
    }
  }
}

/*
 * Output and update for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysShowSegm(const real_T rtu_LabMatrix[19200], const
  real_T rtu_Ref_Colors[150], rtB_StateFlowFunctionsBuoysShow *localB)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  int32_T eml_i;
  int32_T eml_j;

  /* Embedded MATLAB: '<S18>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function': '<S73>:1' */
  /*  This function puts together the segmented imaged such that it can be shown */
  /* '<S73>:1:5' */
  /* '<S73>:1:6' */
  /* '<S73>:1:7' */
  /* '<S73>:1:9' */
  for (eml_i = 0; eml_i < 120; eml_i++) {
    /* '<S73>:1:9' */
    /* '<S73>:1:10' */
    for (eml_j = 0; eml_j < 160; eml_j++) {
      /* '<S73>:1:10' */
      /* '<S73>:1:11' */
      localB->L[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] - 1];

      /* '<S73>:1:12' */
      localB->a[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] + 49];

      /* '<S73>:1:13' */
      localB->b[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<S18>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (eml_i = 0; eml_i < 19200; eml_i++) {
    cc = (localB->L[eml_i] + 16.0) / 116.0;
    cc_0 = localB->a[eml_i] / 500.0 + cc;
    cc_1 = localB->b[eml_i] / -200.0 + cc;
    if (cc_0 <= 2.0689655172413793E-001) {
      cc_0 -= 1.3793103448275862E-001;
      cc_0 /= 7.7870370370370372E+000;
    } else {
      cc_0 = rt_pow_snf(cc_0, 3.0);
    }

    if (cc <= 2.0689655172413793E-001) {
      cc -= 1.3793103448275862E-001;
      cc /= 7.7870370370370372E+000;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (cc_1 <= 2.0689655172413793E-001) {
      cc_1 -= 1.3793103448275862E-001;
      cc_1 /= 7.7870370370370372E+000;
    } else {
      cc_1 = rt_pow_snf(cc_1, 3.0);
    }

    cc_0 *= 9.6419865576090003E-001;
    cc_1 *= 8.2511648322104003E-001;

    /* assign the results */
    localB->ColorSpaceConversion_o1[eml_i] = cc_0;
    localB->ColorSpaceConversion_o2[eml_i] = cc;
    localB->ColorSpaceConversion_o3[eml_i] = cc_1;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (eml_i = 0; eml_i < 19200; eml_i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    cc = (3.2409699419045102E+000 * localB->ColorSpaceConversion_o1[eml_i] +
          -1.5373831775700899E+000 * localB->ColorSpaceConversion_o2[eml_i]) +
      -4.9861076029299001E-001 * localB->ColorSpaceConversion_o3[eml_i];
    cc_0 = (-9.6924363628086996E-001 * localB->ColorSpaceConversion_o1[eml_i] +
            1.8759675015077100E+000 * localB->ColorSpaceConversion_o2[eml_i]) +
      4.1555057407179997E-002 * localB->ColorSpaceConversion_o3[eml_i];
    cc_1 = (5.5630079696999998E-002 * localB->ColorSpaceConversion_o1[eml_i] +
            -2.0397695888899001E-001 * localB->ColorSpaceConversion_o2[eml_i]) +
      1.0569715142428799E+000 * localB->ColorSpaceConversion_o3[eml_i];

    /* Apply gamma correction to get R'G'B' */
    if (cc <= 0.00304) {
      cc *= 1.2923054468333254E+001;
    } else {
      cc = 1.0550005198172263E+000 * rt_pow_snf(cc, 4.1666666666666669E-001) -
        5.5000519817226361E-002;
    }

    if (cc_0 <= 0.00304) {
      cc_0 *= 1.2923054468333254E+001;
    } else {
      cc_0 = 1.0550005198172263E+000 * rt_pow_snf(cc_0, 4.1666666666666669E-001)
        - 5.5000519817226361E-002;
    }

    if (cc_1 <= 0.00304) {
      cc_1 *= 1.2923054468333254E+001;
    } else {
      cc_1 = 1.0550005198172263E+000 * rt_pow_snf(cc_1, 4.1666666666666669E-001)
        - 5.5000519817226361E-002;
    }

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (cc_0 > 1.0) {
      cc_0 = 1.0;
    } else {
      if (cc_0 < 0.0) {
        cc_0 = 0.0;
      }
    }

    if (cc_1 > 1.0) {
      cc_1 = 1.0;
    } else {
      if (cc_1 < 0.0) {
        cc_1 = 0.0;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion_o1[eml_i] = cc;
    localB->ColorSpaceConversion_o2[eml_i] = cc_0;
    localB->ColorSpaceConversion_o3[eml_i] = cc_1;
  }

  /* Embedded MATLAB: '<S18>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function1': '<S74>:1' */
  /*  This function combines the separate color signals into a single 3-D signal */
  /* '<S74>:1:6' */
  memset((void *)(&localB->RGB[0]), (int32_T)0.0, 57600U * sizeof(real_T));

  /* '<S74>:1:8' */
  for (eml_i = 0; eml_i < 120; eml_i++) {
    /* '<S74>:1:8' */
    /* '<S74>:1:9' */
    for (eml_j = 0; eml_j < 160; eml_j++) {
      /* '<S74>:1:9' */
      /* '<S74>:1:10' */
      localB->RGB[eml_i + 120 * eml_j] = localB->ColorSpaceConversion_o1[120 *
        eml_j + eml_i];

      /* '<S74>:1:11' */
      localB->RGB[19200 + (eml_i + 120 * eml_j)] =
        localB->ColorSpaceConversion_o2[120 * eml_j + eml_i];

      /* '<S74>:1:12' */
      localB->RGB[38400 + (eml_i + 120 * eml_j)] =
        localB->ColorSpaceConversion_o3[120 * eml_j + eml_i];
    }
  }
}

/* Function for Embedded MATLAB: '<S65>/Low Pass Filter' */
static void brain_conv2(const real32_T eml_arg1[19200], const real32_T eml_arg2
  [9], real32_T eml_c[18644])
{
  int32_T eml_j;
  int32_T eml_jp;
  int32_T eml_ja;
  int32_T eml_i;
  int32_T eml_ip;
  int32_T eml_ia;
  real32_T eml_s;
  int32_T eml_jb;
  int32_T eml_jc;
  int32_T eml_ic;
  int32_T eml_ja_0;
  int32_T eml_ia_0;
  for (eml_jc = 0; eml_jc < 158; eml_jc++) {
    eml_j = eml_jc + 3;
    eml_jp = eml_j + 1;
    eml_ja = eml_jp - 3;
    for (eml_ic = 0; eml_ic < 118; eml_ic++) {
      eml_i = eml_ic + 3;
      eml_ip = eml_i + 1;
      eml_ia = eml_ip - 3;
      eml_s = 0.0F;
      for (eml_ja_0 = eml_ja; eml_ja_0 <= eml_j; eml_ja_0++) {
        eml_jb = eml_jp - eml_ja_0;
        for (eml_ia_0 = eml_ia; eml_ia_0 <= eml_i; eml_ia_0++) {
          eml_s += eml_arg1[(eml_ja_0 - 1) * 120 + (eml_ia_0 - 1)] * eml_arg2
            [((eml_ip - eml_ia_0) - 1) + (eml_jb - 1) * 3];
        }
      }

      eml_c[eml_ic + 118 * eml_jc] = eml_s;
    }
  }
}

/* Function for Embedded MATLAB: '<S65>/Low Pass Filter' */
static void brain_c14_brain(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB)
{
  real_T eml_G[9];
  real_T eml_Gsum;
  int32_T eml_i;
  real32_T eml_G_0[9];

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S67>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S67>:1:11' */
  memset((void *)&localB->Iout[0], (int32_T)0.0F, 19200U * sizeof(real32_T));

  /* '<S67>:1:17' */
  memset((void *)&eml_G[0], (int32_T)0.0, 9U * sizeof(real_T));

  /* '<S67>:1:19' */
  /* '<S67>:1:21' */
  /* '<S67>:1:23' */
  eml_Gsum = 0.0;

  /* '<S67>:1:24' */
  for (eml_i = -1; eml_i < 2; eml_i++) {
    /* '<S67>:1:24' */
    /* '<S67>:1:25' */
    /* '<S67>:1:26' */
    eml_G[eml_i + 1] = exp((-((real_T)(eml_i * eml_i) + 1.0)) /
      4.0000000000000009E+000);

    /* '<S67>:1:27' */
    eml_Gsum += eml_G[eml_i + 1];

    /* '<S67>:1:25' */
    /* '<S67>:1:26' */
    eml_G[eml_i + 4] = exp((real_T)(-(eml_i * eml_i)) / 4.0000000000000009E+000);

    /* '<S67>:1:27' */
    eml_Gsum += eml_G[eml_i + 4];

    /* '<S67>:1:25' */
    /* '<S67>:1:26' */
    eml_G[eml_i + 7] = exp((-((real_T)(eml_i * eml_i) + 1.0)) /
      4.0000000000000009E+000);

    /* '<S67>:1:27' */
    eml_Gsum += eml_G[eml_i + 7];
  }

  /* '<S67>:1:31' */
  for (eml_i = 0; eml_i < 9; eml_i++) {
    eml_G[eml_i] /= eml_Gsum;
  }

  /* '<S67>:1:33' */
  for (eml_i = 0; eml_i < 19200; eml_i++) {
    localB->fv0[eml_i] = (real32_T)rtu_I[eml_i];
  }

  for (eml_i = 0; eml_i < 9; eml_i++) {
    eml_G_0[eml_i] = (real32_T)eml_G[eml_i];
  }

  brain_conv2(&localB->fv0[0], eml_G_0, &localB->eml_Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S67>:1:37' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    localB->Iout[120 * (1 + eml_i)] = localB->eml_Itemp[118 * eml_i];
  }

  /*  bottom */
  /* '<S67>:1:39' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    localB->Iout[119 + 120 * (1 + eml_i)] = localB->eml_Itemp[118 * eml_i + 117];
  }

  /*  left */
  /* '<S67>:1:41' */
  memcpy((void *)&localB->Iout[1], (void *)&localB->eml_Itemp[0], 118U * sizeof
         (real32_T));

  /*  right */
  /* '<S67>:1:43' */
  memcpy((void *)&localB->Iout[19081], (void *)&localB->eml_Itemp[18526], 118U *
         sizeof(real32_T));

  /*  center */
  /* '<S67>:1:45' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    memcpy((void *)&localB->Iout[1 + 120 * (1 + eml_i)], (void *)
           &localB->eml_Itemp[118 * eml_i], 118U * sizeof(real32_T));
  }

  /*  top left corner */
  /* '<S67>:1:47' */
  localB->Iout[0] = localB->eml_Itemp[0];

  /*  top right corner */
  /* '<S67>:1:49' */
  localB->Iout[18960] = localB->eml_Itemp[18408];
  localB->Iout[19080] = localB->eml_Itemp[18526];

  /*  bottom left corner */
  /* '<S67>:1:51' */
  localB->Iout[118] = localB->eml_Itemp[116];
  localB->Iout[119] = localB->eml_Itemp[117];

  /*  bottom right corner */
  /* '<S67>:1:53' */
  localB->Iout[19078] = localB->eml_Itemp[18524];
  localB->Iout[19079] = localB->eml_Itemp[18525];
  localB->Iout[19198] = localB->eml_Itemp[18642];
  localB->Iout[19199] = localB->eml_Itemp[18643];
}

/*
 * Output and update for atomic system:
 *    '<S65>/Low Pass Filter'
 *    '<S65>/Low Pass Filter1'
 *    '<S65>/Low Pass Filter2'
 *    '<S120>/Low Pass Filter'
 *    '<S120>/Low Pass Filter1'
 *    '<S120>/Low Pass Filter2'
 */
void brain_LowPassFilter(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB)
{
  /* Embedded MATLAB: '<S65>/Low Pass Filter' */
  brain_c14_brain(rtu_I, localB);
}

/* Function for Embedded MATLAB: '<S66>/Reference Color Selection' */
static void brain_c28_brain(rtB_StateFlowFunctionsBuoysIter *localB)
{
  int32_T eml_num_colors;
  int32_T eml_i;
  int32_T eml_j;
  real_T eml_min_dist;
  int32_T eml_index;
  real32_T eml_dist;
  real_T eml_ref_color_L_avg[50];
  real_T eml_ref_color_a_avg[50];
  real_T eml_ref_color_b_avg[50];
  real_T eml_color_count[50];
  uint32_T eml_c_i;
  int32_T i;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Reference Color Selection': '<S71>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S71>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S71>:1:14' */
  /* '<S71>:1:15' */
  memset((void *)&localB->ref_colors[0], (int32_T)0.0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S71>:1:16' */
  memset((void *)&localB->eml_LabelMatrix[0], (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S71>:1:17' */
  eml_num_colors = 1;

  /* '<S71>:1:22' */
  localB->ref_colors[0] = localB->Resize[2369];
  localB->ref_colors[50] = localB->Resize1[2369];
  localB->ref_colors[100] = localB->Resize2[2369];

  /* '<S71>:1:24' */
  i = 0;

  /* '<S71>:1:25' */
  eml_i = 1;

  /* '<S71>:1:26' */
  eml_j = 1;
  while (eml_i <= 60) {
    /* '<S71>:1:27' */
    /*  perform initial segmentation */
    while ((eml_i <= 60) && (i == 0)) {
      /* '<S71>:1:28' */
      while ((eml_j <= 80) && (i == 0)) {
        /* '<S71>:1:29' */
        /* '<S71>:1:30' */
        eml_c_i = 1U;

        /* '<S71>:1:31' */
        eml_min_dist = 1000.0;

        /* '<S71>:1:32' */
        eml_index = 1;
        while (eml_c_i <= (uint32_T)eml_num_colors) {
          /* '<S71>:1:33' */
          /* '<S71>:1:34' */
          eml_dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->
            ref_colors[eml_c_i + 49] - localB->Resize1[(eml_j - 1) * 60 + (eml_i
            - 1)], 2.0F) * 1.5F + rt_pow32_snf((real32_T)localB->
            ref_colors[eml_c_i - 1] - localB->Resize[(eml_j - 1) * 60 + (eml_i -
            1)], 2.0F)) + rt_pow32_snf((real32_T)localB->ref_colors[eml_c_i + 99]
            - localB->Resize2[(eml_j - 1) * 60 + (eml_i - 1)], 2.0F) * 1.5F);
          if (eml_min_dist > (real_T)eml_dist) {
            /* '<S71>:1:35' */
            /* '<S71>:1:36' */
            eml_min_dist = eml_dist;

            /* '<S71>:1:37' */
            eml_index = (int32_T)eml_c_i;
          }

          /* '<S71>:1:39' */
          eml_c_i++;
        }

        if ((eml_min_dist > brain_P.Iter_Segment_Thresh) && (eml_num_colors < 50))
        {
          /* '<S71>:1:44' */
          /* '<S71>:1:45' */
          localB->ref_colors[eml_num_colors] = localB->Resize[(eml_j - 1) * 60 +
            (eml_i - 1)];
          localB->ref_colors[eml_num_colors + 50] = localB->Resize1[(eml_j - 1) *
            60 + (eml_i - 1)];
          localB->ref_colors[eml_num_colors + 100] = localB->Resize2[(eml_j - 1)
            * 60 + (eml_i - 1)];

          /* '<S71>:1:46' */
          eml_num_colors++;

          /* '<S71>:1:47' */
          i = 1;

          /* '<S71>:1:48' */
          eml_i = 0;

          /* '<S71>:1:49' */
          eml_j = 0;
        } else {
          /* '<S71>:1:51' */
          localB->eml_LabelMatrix[(eml_i - 1) + 60 * (eml_j - 1)] = (uint32_T)
            eml_index;
        }

        /* '<S71>:1:53' */
        eml_j++;
      }

      /* '<S71>:1:55' */
      eml_j = 1;

      /* '<S71>:1:56' */
      eml_i++;
    }

    /* '<S71>:1:58' */
    i = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S71>:1:62' */
  /* '<S71>:1:63' */
  /* '<S71>:1:64' */
  /* '<S71>:1:65' */
  for (i = 0; i < 50; i++) {
    eml_ref_color_L_avg[i] = 0.0;
    eml_ref_color_a_avg[i] = 0.0;
    eml_ref_color_b_avg[i] = 0.0;
    eml_color_count[i] = 0.0;
  }

  /* '<S71>:1:66' */
  for (i = 0; i < 60; i++) {
    /* '<S71>:1:66' */
    /* '<S71>:1:67' */
    for (eml_i = 0; eml_i < 80; eml_i++) {
      /* '<S71>:1:67' */
      /* '<S71>:1:68' */
      /* '<S71>:1:69' */
      eml_ref_color_L_avg[(int32_T)localB->eml_LabelMatrix[i + 60 * eml_i] - 1] =
        (real32_T)eml_ref_color_L_avg[(int32_T)localB->eml_LabelMatrix[60 *
        eml_i + i] - 1] + localB->Resize[60 * eml_i + i];

      /* '<S71>:1:70' */
      eml_ref_color_a_avg[(int32_T)localB->eml_LabelMatrix[i + 60 * eml_i] - 1] =
        (real32_T)eml_ref_color_a_avg[(int32_T)localB->eml_LabelMatrix[60 *
        eml_i + i] - 1] + localB->Resize1[60 * eml_i + i];

      /* '<S71>:1:71' */
      eml_ref_color_b_avg[(int32_T)localB->eml_LabelMatrix[i + 60 * eml_i] - 1] =
        (real32_T)eml_ref_color_b_avg[(int32_T)localB->eml_LabelMatrix[60 *
        eml_i + i] - 1] + localB->Resize2[60 * eml_i + i];

      /* '<S71>:1:72' */
      eml_color_count[(int32_T)localB->eml_LabelMatrix[i + 60 * eml_i] - 1] =
        eml_color_count[(int32_T)localB->eml_LabelMatrix[60 * eml_i + i] - 1] +
        1.0;
    }
  }

  /* '<S71>:1:75' */
  /* '<S71>:1:76' */
  /* '<S71>:1:77' */
  for (i = 0; i < 50; i++) {
    eml_ref_color_L_avg[i] /= eml_color_count[i];
    eml_ref_color_a_avg[i] /= eml_color_count[i];
    eml_ref_color_b_avg[i] /= eml_color_count[i];
  }

  /* '<S71>:1:79' */
  for (eml_c_i = 1U; eml_c_i <= (uint32_T)eml_num_colors; eml_c_i++) {
    /* '<S71>:1:79' */
    /* '<S71>:1:80' */
    localB->ref_colors[eml_c_i - 1] = eml_ref_color_L_avg[(int32_T)eml_c_i - 1];

    /* '<S71>:1:81' */
    localB->ref_colors[eml_c_i + 49] = eml_ref_color_a_avg[(int32_T)eml_c_i - 1];

    /* '<S71>:1:82' */
    localB->ref_colors[eml_c_i + 99] = eml_ref_color_b_avg[(int32_T)eml_c_i - 1];
  }

  localB->num_colors = (real_T)eml_num_colors;
}

/*
 * Output and update for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysIterativ(const real_T rtu_H[19200], const real_T
  rtu_S[19200], const real_T rtu_V[19200], rtB_StateFlowFunctionsBuoysIter
  *localB, rtDW_StateFlowFunctionsBuoysIte *localDW)
{
  int32_T i;
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  uint32_T k;
  real32_T cc_2;
  real32_T Yr;
  real32_T Zr;
  real32_T Xf;
  int32_T n;
  int32_T ictr;
  int32_T indx;
  real_T eml_min_dist;
  real_T eml_index;
  real32_T eml_dist;
  int32_T eml_j;
  real_T eml_k;
  real32_T Resize2_LineBuffer[120];

  /* S-Function (svipcolorconv): '<S17>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    eml_min_dist = 6.0 * rtu_H[i];
    k = (uint32_T)(eml_min_dist - 1.3322676295501878E-015);
    eml_min_dist -= (real_T)k;
    eml_index = 1.0 - rtu_S[i];
    eml_k = 1.0 - rtu_S[i] * eml_min_dist;
    eml_min_dist = rtu_S[i] * eml_min_dist + eml_index;
    if (k == 0U) {
      cc = 1.0;
      cc_0 = eml_min_dist;
      cc_1 = eml_index;
    } else if (k == 1U) {
      cc = eml_k;
      cc_0 = 1.0;
      cc_1 = eml_index;
    } else if (k == 2U) {
      cc = eml_index;
      cc_0 = 1.0;
      cc_1 = eml_min_dist;
    } else if (k == 3U) {
      cc = eml_index;
      cc_0 = eml_k;
      cc_1 = 1.0;
    } else if (k == 4U) {
      cc = eml_min_dist;
      cc_0 = eml_index;
      cc_1 = 1.0;
    } else {
      if (k == 5U) {
        cc = 1.0;
        cc_0 = eml_index;
        cc_1 = eml_k;
      }
    }

    if (cc > cc_0) {
      eml_min_dist = cc;
    } else {
      eml_min_dist = cc_0;
    }

    if (!(eml_min_dist > cc_1)) {
      eml_min_dist = cc_1;
    }

    eml_min_dist = rtu_V[i] / eml_min_dist;

    /* assign the results */
    localB->ColorSpaceConversion_o1[i] = eml_min_dist * cc;
    localB->ColorSpaceConversion_o2[i] = eml_min_dist * cc_0;
    localB->ColorSpaceConversion_o3[i] = eml_min_dist * cc_1;
  }

  /* Embedded MATLAB: '<S65>/Low Pass Filter' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o1, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S65>/Low Pass Filter1' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o2,
                      &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S65>/Low Pass Filter2' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o3,
                      &localB->sf_LowPassFilter2);

  /* S-Function (svipcolorconv): '<S17>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (localB->sf_LowPassFilter.Iout[i] <= 3.928608447E-002F) {
      Zr = localB->sf_LowPassFilter.Iout[i] / 1.292305470E+001F;
    } else {
      Zr = rt_pow32_snf((localB->sf_LowPassFilter.Iout[i] + 5.500052124E-002F) /
                        1.055000544E+000F, 2.400000095E+000F);
    }

    if (localB->sf_LowPassFilter1.Iout[i] <= 3.928608447E-002F) {
      eml_dist = localB->sf_LowPassFilter1.Iout[i] / 1.292305470E+001F;
    } else {
      eml_dist = rt_pow32_snf((localB->sf_LowPassFilter1.Iout[i] +
        5.500052124E-002F) / 1.055000544E+000F, 2.400000095E+000F);
    }

    if (localB->sf_LowPassFilter2.Iout[i] <= 3.928608447E-002F) {
      Yr = localB->sf_LowPassFilter2.Iout[i] / 1.292305470E+001F;
    } else {
      Yr = rt_pow32_snf((localB->sf_LowPassFilter2.Iout[i] + 5.500052124E-002F) /
                        1.055000544E+000F, 2.400000095E+000F);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    Xf = (4.123907983E-001F * Zr + 3.575843275E-001F * eml_dist) +
      1.804807931E-001F * Yr;
    cc_2 = (2.126390040E-001F * Zr + 7.151686549E-001F * eml_dist) +
      7.219231874E-002F * Yr;
    eml_dist = (1.933081821E-002F * Zr + 1.191947833E-001F * eml_dist) +
      9.505321383E-001F * Yr;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (Xf > 1.0F) {
      Xf = 1.0F;
    } else {
      if (Xf < 0.0F) {
        Xf = 0.0F;
      }
    }

    if (cc_2 > 1.0F) {
      cc_2 = 1.0F;
    } else {
      if (cc_2 < 0.0F) {
        cc_2 = 0.0F;
      }
    }

    if (eml_dist > 1.0F) {
      eml_dist = 1.0F;
    } else {
      if (eml_dist < 0.0F) {
        eml_dist = 0.0F;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = Xf;
    localB->ColorSpaceConversion1_o2[i] = cc_2;
    localB->ColorSpaceConversion1_o3[i] = eml_dist;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    eml_dist = localB->ColorSpaceConversion1_o1[i] / 9.641986489E-001F;
    Zr = localB->ColorSpaceConversion1_o3[i] / 8.251164556E-001F;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (eml_dist > 8.856452070E-003F) {
      Xf = rt_pow32_snf(eml_dist, 3.333333433E-001F);
    } else {
      Xf = 7.787036896E+000F * eml_dist + 1.379310340E-001F;
    }

    if (localB->ColorSpaceConversion1_o2[i] > 8.856452070E-003F) {
      Yr = rt_pow32_snf(localB->ColorSpaceConversion1_o2[i], 3.333333433E-001F);
    } else {
      Yr = 7.787036896E+000F * localB->ColorSpaceConversion1_o2[i] +
        1.379310340E-001F;
    }

    if (Zr > 8.856452070E-003F) {
      eml_dist = rt_pow32_snf(Zr, 3.333333433E-001F);
    } else {
      eml_dist = 7.787036896E+000F * Zr + 1.379310340E-001F;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = 116.0F * Yr - 16.0F;
    localB->ColorSpaceConversion1_o2[i] = (Xf - Yr) * 500.0F;
    localB->ColorSpaceConversion1_o3[i] = (Yr - eml_dist) * 200.0F;
  }

  /* S-Function (svipresize): '<S72>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_j = 0;
  for (i = 0; i < 120; i++) {
    indx = i;
    for (n = 0; n < 80; n++) {
      ictr = n + 80;
      eml_dist = localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[n] * 120
        + i] * brain_ConstP.pooled23[n] + localB->
        ColorSpaceConversion1_o1[brain_ConstP.pooled30[ictr] * 120 + i] *
        brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      localDW->Resize_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (n = 0; n < 80; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->Resize_IntBuffer[n
            * 120]), 120U * sizeof(real32_T));
    for (i = 0; i < 60; i++) {
      ictr = i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i] + Resize2_LineBuffer[brain_ConstP.pooled29[ictr]]
        * brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      localB->Resize[eml_j] = eml_dist;
      eml_j++;
    }
  }

  /* S-Function (svipresize): '<S72>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_j = 0;
  for (i = 0; i < 120; i++) {
    indx = i;
    for (n = 0; n < 80; n++) {
      ictr = n + 80;
      eml_dist = localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[n] * 120
        + i] * brain_ConstP.pooled23[n] + localB->
        ColorSpaceConversion1_o2[brain_ConstP.pooled30[ictr] * 120 + i] *
        brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      localDW->Resize1_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (n = 0; n < 80; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[n * 120]), 120U * sizeof(real32_T));
    for (i = 0; i < 60; i++) {
      ictr = i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i] + Resize2_LineBuffer[brain_ConstP.pooled29[ictr]]
        * brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      localB->Resize1[eml_j] = eml_dist;
      eml_j++;
    }
  }

  /* S-Function (svipresize): '<S72>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_j = 0;
  for (i = 0; i < 120; i++) {
    indx = i;
    for (n = 0; n < 80; n++) {
      ictr = n + 80;
      eml_dist = localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[n] * 120
        + i] * brain_ConstP.pooled23[n] + localB->
        ColorSpaceConversion1_o3[brain_ConstP.pooled30[ictr] * 120 + i] *
        brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      ictr += 80;
      eml_dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[ictr] *
        120 + i] * brain_ConstP.pooled23[ictr];
      localDW->Resize2_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (n = 0; n < 80; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[n * 120]), 120U * sizeof(real32_T));
    for (i = 0; i < 60; i++) {
      ictr = i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i] + Resize2_LineBuffer[brain_ConstP.pooled29[ictr]]
        * brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      ictr += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled29[ictr]] *
        brain_ConstP.pooled22[ictr];
      localB->Resize2[eml_j] = eml_dist;
      eml_j++;
    }
  }

  /* Embedded MATLAB: '<S66>/Reference Color Selection' */
  brain_c28_brain(localB);

  /* Embedded MATLAB: '<S66>/LabSegmentation' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/LabSegmentation': '<S70>:1' */
  /*  This function generates the label matrix */
  /* '<S70>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0.0, 19200U * sizeof(real_T));

  /* '<S70>:1:12' */
  for (i = 0; i < 120; i++) {
    /* '<S70>:1:12' */
    /* '<S70>:1:13' */
    for (eml_j = 0; eml_j < 160; eml_j++) {
      /* '<S70>:1:13' */
      /* '<S70>:1:14' */
      eml_min_dist = 1000.0;

      /* '<S70>:1:15' */
      eml_index = 1.0;

      /* '<S70>:1:16' */
      for (eml_k = 1.0; eml_k <= localB->num_colors; eml_k++) {
        /* '<S70>:1:16' */
        /* '<S70>:1:17' */
        eml_dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->ref_colors
          [(int32_T)eml_k - 1] - localB->ColorSpaceConversion1_o1[120 * eml_j +
          i], 2.0F) + rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)eml_k +
          49] - localB->ColorSpaceConversion1_o2[120 * eml_j + i], 2.0F)) +
          rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)eml_k + 99] -
                       localB->ColorSpaceConversion1_o3[120 * eml_j + i], 2.0F));
        if ((real_T)eml_dist < eml_min_dist) {
          /* '<S70>:1:18' */
          /* '<S70>:1:19' */
          eml_min_dist = eml_dist;

          /* '<S70>:1:20' */
          eml_index = eml_k;
        }
      }

      /* '<S70>:1:23' */
      localB->LabelMatrix[i + 120 * eml_j] = eml_index;
    }
  }

  /* '<S70>:1:27' */
}

/* Function for Embedded MATLAB: '<S14>/Blob Extraction' */
static void brain_Outputs_f(const boolean_T eml_U0[19200], int32_T eml_Y0[50],
  real_T eml_Y1[100], real_T eml_Y2[50], real_T eml_Y3[50], uint8_T *eml_Y4,
  rtDW_StateFlowFunctionsBuoysF_e *localDW)
{
  boolean_T eml_maxNumBlobsReached;
  int32_T eml_loop;
  uint8_T eml_currentLabel;
  int32_T eml_idx;
  int32_T eml_n;
  uint32_T eml_stackIdx;
  uint32_T eml_pixIdx;
  uint32_T eml_start_pixIdx;
  uint32_T eml_walkerIdx;
  int32_T eml_numBlobs;
  int32_T eml_pixListMinc;
  int32_T eml_pixListNinc;
  int32_T eml_c_i;
  int32_T eml_j;
  int32_T eml_maxc;
  int32_T eml_maxr;
  real_T eml_xs;
  real_T eml_ys;
  real_T eml_xys;
  uint32_T eml_k;
  real_T eml_uyy;
  real_T eml_majorAxis;
  real_T eml_centroid_idx;
  real_T eml_centroid_idx_0;

  /* System object Outputs function: video.BlobAnalysis */
  eml_maxNumBlobsReached = FALSE;
  memset((void *)&localDW->PAD_DW[0], (int32_T)0U, 123U * sizeof(uint8_T));
  eml_currentLabel = 1U;
  eml_loop = 0;
  eml_idx = 123;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    for (eml_maxc = 0; eml_maxc < 120; eml_maxc++) {
      localDW->PAD_DW[eml_idx] = (uint8_T)(eml_U0[eml_loop] ? 255 : 0);
      eml_loop++;
      eml_idx++;
    }

    localDW->PAD_DW[eml_idx] = 0U;
    eml_idx++;
    localDW->PAD_DW[eml_idx] = 0U;
    eml_idx++;
  }

  memset((void *)&localDW->PAD_DW[eml_idx], (int32_T)0U, 121U * sizeof(uint8_T));
  eml_loop = 1;
  eml_stackIdx = 0U;
  eml_pixIdx = 0U;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    eml_maxc = 1;
    eml_idx = eml_loop * 122;
    for (eml_maxr = 0; eml_maxr < 120; eml_maxr++) {
      eml_k = (uint32_T)(eml_idx + eml_maxc);
      eml_start_pixIdx = eml_pixIdx;
      if (localDW->PAD_DW[eml_k] == 255) {
        localDW->PAD_DW[eml_k] = eml_currentLabel;
        localDW->N_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_loop - 1);
        localDW->M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_maxc - 1);
        eml_pixIdx++;
        localDW->NUM_PIX_DW[eml_currentLabel - 1] = 1U;
        localDW->STACK_DW[eml_stackIdx] = eml_k;
        eml_stackIdx++;
        while (eml_stackIdx) {
          eml_stackIdx--;
          eml_k = localDW->STACK_DW[eml_stackIdx];
          for (eml_pixListMinc = 0; eml_pixListMinc < 8; eml_pixListMinc++) {
            eml_walkerIdx = eml_k + (uint32_T)localDW->
              WALKER_RTP[eml_pixListMinc];
            if (localDW->PAD_DW[eml_walkerIdx] == 255) {
              localDW->PAD_DW[eml_walkerIdx] = eml_currentLabel;
              localDW->N_PIXLIST_DW[eml_pixIdx] = (int16_T)((int16_T)
                (eml_walkerIdx / 122U) - 1);
              localDW->M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_walkerIdx % 122U
                - 1U);
              eml_pixIdx++;
              localDW->NUM_PIX_DW[eml_currentLabel - 1] = localDW->
                NUM_PIX_DW[eml_currentLabel - 1] + 1U;
              localDW->STACK_DW[eml_stackIdx] = eml_walkerIdx;
              eml_stackIdx++;
            }
          }
        }

        if (localDW->NUM_PIX_DW[eml_currentLabel - 1] < localDW->MINAREA_RTP) {
          eml_currentLabel--;
          eml_pixIdx = eml_start_pixIdx;
        }

        if (eml_currentLabel == 50) {
          eml_maxNumBlobsReached = TRUE;
          eml_n = 160;
          eml_maxr = 120;
        }

        if (eml_maxr < 120) {
          eml_currentLabel++;
        }
      }

      eml_maxc++;
    }

    eml_loop++;
  }

  eml_numBlobs = eml_maxNumBlobsReached ? eml_currentLabel : (uint8_T)
    (eml_currentLabel - 1);
  *eml_Y4 = (uint8_T)eml_numBlobs;
  eml_pixListMinc = 0;
  eml_pixListNinc = 0;
  for (eml_c_i = 0; eml_c_i < eml_numBlobs; eml_c_i++) {
    eml_Y0[eml_c_i] = (int32_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_loop = 0;
    eml_n = 0;
    for (eml_j = 0; eml_j < (int32_T)localDW->NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop += localDW->N_PIXLIST_DW[eml_j + eml_pixListNinc];
      eml_n += localDW->M_PIXLIST_DW[eml_j + eml_pixListMinc];
    }

    eml_centroid_idx = (real_T)eml_n / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_centroid_idx_0 = (real_T)eml_loop / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_Y1[eml_c_i << 1] = eml_centroid_idx;
    eml_Y1[(eml_c_i << 1) + 1] = eml_centroid_idx_0;
    eml_n = 160;
    eml_idx = 120;
    eml_maxc = 0;
    eml_maxr = 0;
    for (eml_j = 0; eml_j < (int32_T)localDW->NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop = eml_j + eml_pixListNinc;
      if (localDW->N_PIXLIST_DW[eml_loop] < eml_n) {
        eml_n = localDW->N_PIXLIST_DW[eml_loop];
      }

      if (localDW->N_PIXLIST_DW[eml_loop] > eml_maxc) {
        eml_maxc = localDW->N_PIXLIST_DW[eml_loop];
      }

      eml_loop = eml_j + eml_pixListMinc;
      if (localDW->M_PIXLIST_DW[eml_loop] < eml_idx) {
        eml_idx = localDW->M_PIXLIST_DW[eml_loop];
      }

      if (localDW->M_PIXLIST_DW[eml_loop] > eml_maxr) {
        eml_maxr = localDW->M_PIXLIST_DW[eml_loop];
      }
    }

    eml_xs = 0.0;
    eml_ys = 0.0;
    eml_xys = 0.0;
    for (eml_k = 0U; eml_k < (uint32_T)(int32_T)localDW->NUM_PIX_DW[eml_c_i];
         eml_k++) {
      eml_majorAxis = (real_T)localDW->N_PIXLIST_DW[eml_pixListNinc + eml_k] -
        eml_centroid_idx_0;
      eml_uyy = (real_T)localDW->M_PIXLIST_DW[eml_pixListMinc + eml_k] -
        eml_centroid_idx;
      eml_xs += eml_majorAxis * eml_majorAxis;
      eml_ys += eml_uyy * eml_uyy;
      eml_xys += eml_majorAxis * (-eml_uyy);
    }

    eml_centroid_idx = eml_xs / (real_T)localDW->NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-002;
    eml_uyy = eml_ys / (real_T)localDW->NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-002;
    eml_xs = eml_xys / (real_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_xs = sqrt((eml_centroid_idx - eml_uyy) * (eml_centroid_idx - eml_uyy) +
                  eml_xs * eml_xs * 4.0);
    eml_majorAxis = ((eml_centroid_idx + eml_uyy) + eml_xs) * 8.0;
    eml_Y2[eml_c_i] = sqrt(eml_majorAxis - ((eml_centroid_idx + eml_uyy) -
      eml_xs) * 8.0) / sqrt(eml_majorAxis);
    eml_Y3[eml_c_i] = (real_T)localDW->NUM_PIX_DW[eml_c_i] / (real_T)(((eml_maxr
      + 1) - eml_idx) * ((eml_maxc + 1) - eml_n));
    eml_pixListMinc += (int32_T)localDW->NUM_PIX_DW[eml_c_i];
    eml_pixListNinc += (int32_T)localDW->NUM_PIX_DW[eml_c_i];
  }

  for (eml_loop = eml_numBlobs; eml_loop < 50; eml_loop++) {
    eml_Y0[eml_loop] = localDW->F0_RTP;
  }

  for (eml_loop = eml_numBlobs << 1; eml_loop < 100; eml_loop++) {
    eml_Y1[eml_loop] = localDW->F1_RTP;
  }

  for (eml_loop = eml_numBlobs; eml_loop < 50; eml_loop++) {
    eml_Y2[eml_loop] = localDW->F2_RTP;
  }

  while (eml_numBlobs < 50) {
    eml_Y3[eml_numBlobs] = localDW->F3_RTP;
    eml_numBlobs++;
  }
}

/* Function for Embedded MATLAB: '<S14>/Blob Extraction' */
static void brain_c5_brain(const real_T rtu_LabelMatrix[19200], real_T
  rtu_num_colors, rtB_StateFlowFunctionsBuoysFi_d *localB,
  rtDW_StateFlowFunctionsBuoysF_e *localDW)
{
  real_T eml_num_colors;
  uint8_T eml_TotalNum;
  real_T eml_k;
  int32_T eml_j;
  uint8_T eml_b_i;
  int32_T eml_TArea[50];
  real_T eml_TCentroid[100];
  real_T eml_TEccent[50];
  real_T eml_TExtent[50];
  uint8_T eml_TNumBlobs;
  int32_T i;
  uint8_T tmp;
  eml_num_colors = rtu_num_colors;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Blob Extraction': '<S60>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S60>:1:7' */
  for (i = 0; i < 19200; i++) {
    localB->eml_LogicMatrix[i] = FALSE;
  }

  /* '<S60>:1:9' */
  /* '<S60>:1:12' */
  memset((void *)&localB->Area[0], (int32_T)0.0, 50U * sizeof(real_T));

  /* '<S60>:1:13' */
  memset((void *)&localB->Centroid[0], (int32_T)0.0, 100U * sizeof(real_T));

  /* '<S60>:1:14' */
  /* '<S60>:1:15' */
  for (i = 0; i < 50; i++) {
    localB->Eccent[i] = 0.0;
    localB->Extent[i] = 0.0;
  }

  /* '<S60>:1:17' */
  eml_TotalNum = 0U;

  /* '<S60>:1:27' */
  for (eml_k = 1.0; eml_k <= eml_num_colors; eml_k++) {
    /* '<S60>:1:27' */
    /* '<S60>:1:28' */
    for (i = 0; i < 120; i++) {
      /* '<S60>:1:28' */
      /* '<S60>:1:29' */
      for (eml_j = 0; eml_j < 160; eml_j++) {
        /* '<S60>:1:29' */
        if (rtu_LabelMatrix[120 * eml_j + i] != eml_k) {
          /* '<S60>:1:30' */
          /* '<S60>:1:31' */
          localB->eml_LogicMatrix[i + 120 * eml_j] = FALSE;
        } else {
          /* '<S60>:1:33' */
          localB->eml_LogicMatrix[i + 120 * eml_j] = TRUE;
        }
      }
    }

    brain_Outputs_f(&localB->eml_LogicMatrix[0], eml_TArea, eml_TCentroid,
                    eml_TEccent, eml_TExtent, &eml_TNumBlobs, localDW);
    i = eml_TNumBlobs + eml_TotalNum;
    if ((uint32_T)i > 255U) {
      tmp = MAX_uint8_T;
    } else {
      tmp = (uint8_T)i;
    }

    if (tmp < 50) {
      /* '<S60>:1:39' */
      /* '<S60>:1:40' */
      for (eml_b_i = 1U; eml_b_i <= eml_TNumBlobs; eml_b_i = (uint8_T)(uint32_T)
           (eml_b_i + 1)) {
        /* '<S60>:1:40' */
        /* '<S60>:1:41' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Area[tmp - 1] = (real_T)eml_TArea[eml_b_i - 1];

        /* '<S60>:1:42' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Centroid[tmp - 1] = eml_TCentroid[(eml_b_i - 1) << 1];

        /* '<S60>:1:43' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Centroid[tmp + 49] = eml_TCentroid[((eml_b_i - 1) << 1) + 1];

        /* '<S60>:1:44' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Eccent[tmp - 1] = eml_TEccent[eml_b_i - 1];

        /* '<S60>:1:45' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        localB->Extent[tmp - 1] = eml_TExtent[eml_b_i - 1];
      }

      /* '<S60>:1:47' */
      i = eml_TotalNum + eml_TNumBlobs;
      if ((uint32_T)i > 255U) {
        eml_TotalNum = MAX_uint8_T;
      } else {
        eml_TotalNum = (uint8_T)i;
      }
    }
  }

  localB->TotalNum = eml_TotalNum;
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysF_e_Init(rtDW_StateFlowFunctionsBuoysF_e *localDW)
{
  int32_T i;
  static int8_T tmp[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

  /* InitializeConditions for Embedded MATLAB: '<S14>/Blob Extraction' */
  for (i = 0; i < 8; i++) {
    localDW->WALKER_RTP[i] = tmp[i];
  }

  localDW->F0_RTP = -1;
  localDW->F1_RTP = -1.0;
  localDW->F2_RTP = -1.0;
  localDW->F3_RTP = -1.0;
  localDW->MINAREA_RTP = 10U;
  localDW->hblob = TRUE;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysFindBu_l(const real_T rtu_LabelMatrix[19200], real_T
  rtu_num_colors, const real_T rtu_ref_colors[150],
  rtB_StateFlowFunctionsBuoysFi_d *localB, rtDW_StateFlowFunctionsBuoysF_e
  *localDW)
{
  real_T eml_count;
  uint8_T eml_i;
  real_T eml_colors[150];
  real_T eml_centX[50];
  real_T eml_centY[50];
  real_T eml_mtmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  boolean_T eml_exitg;
  real_T rtb_Centroid_Out[100];
  int32_T i;

  /* Embedded MATLAB: '<S14>/Blob Extraction' */
  brain_c5_brain(rtu_LabelMatrix, rtu_num_colors, localB, localDW);

  /* Embedded MATLAB: '<S14>/IF Buoy Conditions' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Constant3'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions': '<S61>:1' */
  /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
  /*  the cenroids of the most circular objects in the image */
  /* '<S61>:1:5' */
  eml_count = 0.0;

  /* '<S61>:1:6' */
  memset((void *)&rtb_Centroid_Out[0], (int32_T)0.0, 100U * sizeof(real_T));

  /* '<S61>:1:9' */
  for (eml_i = 1U; eml_i <= localB->TotalNum; eml_i = (uint8_T)(uint32_T)(eml_i
        + 1)) {
    /* '<S61>:1:9' */
    if ((localB->Eccent[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
        (localB->Eccent[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
        (localB->Extent[eml_i - 1] > brain_P.Buoy_Min_Extent) && (localB->
         Extent[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
      /* '<S61>:1:10' */
      /* '<S61>:1:11' */
      eml_count++;

      /* '<S61>:1:12' */
      rtb_Centroid_Out[(int32_T)eml_count - 1] = localB->Centroid[eml_i - 1];

      /* '<S61>:1:13' */
      rtb_Centroid_Out[(int32_T)eml_count + 49] = localB->Centroid[eml_i + 49];
    }
  }

  localB->count = eml_count;

  /* Embedded MATLAB: '<S14>/Say Which Buoy Is Which' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which': '<S62>:1' */
  /*  This function determines which buoy is in which location, left, middle, */
  /*  or right. */
  /* '<S62>:1:6' */
  memset((void *)&eml_colors[0], (int32_T)0.0, 150U * sizeof(real_T));

  /* '<S62>:1:7' */
  /* '<S62>:1:8' */
  for (i = 0; i < 50; i++) {
    eml_centX[i] = 0.0;
    eml_centY[i] = 0.0;
  }

  /* '<S62>:1:10' */
  memset((void *)(&localB->blobs[0]), (int32_T)0.0, 200U * sizeof(real_T));

  /* '<S62>:1:12' */
  for (eml_count = 1.0; eml_count <= localB->count; eml_count++) {
    /* '<S62>:1:12' */
    /* '<S62>:1:13' */
    eml_centX[(int32_T)eml_count - 1] = floor(rtb_Centroid_Out[(int32_T)
      eml_count + 49]);

    /* '<S62>:1:14' */
    eml_centY[(int32_T)eml_count - 1] = floor(rtb_Centroid_Out[(int32_T)
      eml_count - 1]);
    if (eml_centX[(int32_T)eml_count - 1] < 1.0) {
      /* '<S62>:1:15' */
      /* '<S62>:1:16' */
      eml_centX[(int32_T)eml_count - 1] = 1.0;
    }

    if (eml_centY[(int32_T)eml_count - 1] < 1.0) {
      /* '<S62>:1:18' */
      /* '<S62>:1:19' */
      eml_centY[(int32_T)eml_count - 1] = 1.0;
    }

    /* '<S62>:1:22' */
    eml_mtmp = rtu_LabelMatrix[((int32_T)eml_centX[(int32_T)eml_count - 1] - 1) *
      120 + ((int32_T)eml_centY[(int32_T)eml_count - 1] - 1)];

    /* '<S62>:1:24' */
    i = (int32_T)eml_count - 1;
    eml_colors[i] = rtu_ref_colors[(int32_T)eml_mtmp - 1];
    eml_colors[i + 50] = rtu_ref_colors[(int32_T)eml_mtmp + 49];
    eml_colors[i + 100] = rtu_ref_colors[(int32_T)eml_mtmp + 99];
  }

  /*  Putting blobs in order from left to right */
  /* '<S62>:1:28' */
  for (eml_count = 1.0; eml_count <= localB->count; eml_count++) {
    /* '<S62>:1:28' */
    eml_mtmp = eml_centX[0];
    i = 1;
    eml_ix = 1;
    eml_guard = FALSE;
    if (rtIsNaN(eml_centX[0])) {
      eml_searchingForNonNaN = TRUE;
      eml_k = 2;
      eml_exitg = FALSE;
      while (((uint32_T)eml_exitg == 0U) && (eml_k < 51)) {
        eml_ix++;
        if (!rtIsNaN(eml_centX[eml_ix - 1])) {
          eml_mtmp = eml_centX[eml_ix - 1];
          i = eml_k;
          eml_searchingForNonNaN = FALSE;
          eml_exitg = TRUE;
        } else {
          eml_k++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = TRUE;
      }
    } else {
      eml_guard = TRUE;
    }

    if (eml_guard) {
      for (eml_k = i + 1; eml_k < 51; eml_k++) {
        eml_ix++;
        if (eml_centX[eml_ix - 1] < eml_mtmp) {
          eml_mtmp = eml_centX[eml_ix - 1];
          i = eml_k;
        }
      }
    }

    /* '<S62>:1:30' */
    localB->blobs[(int32_T)eml_count - 1] = eml_colors[i - 1];

    /* '<S62>:1:31' */
    localB->blobs[(int32_T)eml_count + 49] = eml_colors[i + 49];

    /* '<S62>:1:32' */
    localB->blobs[(int32_T)eml_count + 99] = eml_colors[i + 99];

    /* '<S62>:1:33' */
    localB->blobs[(int32_T)eml_count + 149] = localB->Area[i - 1];

    /* '<S62>:1:34' */
    eml_centX[i - 1] = 1000.0;
  }
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsMaintain_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW)
{
  localDW->StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;
}

/* Disable for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsMaint_Disable(rtB_StateFlowFunctionsMaintainH *localB,
  rtDW_StateFlowFunctionsMaintain *localDW)
{
  /* Disable for If: '<S38>/If' */
  localDW->If_ActiveSubsystem = -1;

  /* Disable for ifaction SubSystem: '<S38>/BigError S1' */

  /* Disable for Outport: '<S133>/Out2' */
  localB->Constant1_e = 0.0;

  /* end of Disable for SubSystem: '<S38>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S38>/BigNegativeError S2' */

  /* Disable for Outport: '<S134>/Out2' */
  localB->Constant1 = 0.0;

  /* end of Disable for SubSystem: '<S38>/BigNegativeError S2' */
}

/* Start for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsMaintai_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW)
{
  /* Start for If: '<S38>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsMaintainHeadi(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *const
  brain_M, rtB_StateFlowFunctionsMaintainH *localB,
  rtDW_StateFlowFunctionsMaintain *localDW)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Add1;
  real_T rtb_Add4;
  real_T rtb_TSamp_j;
  real_T tmp;
  localDW->StateFlowFunctionsMaintainHea_e = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsMaintainHea_m;
  localDW->StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

  /* Sum: '<S38>/Add1' */
  rtb_Add1 = rtu_DesiredHeading1 - rtu_CurrentHeading1;

  /* If: '<S38>/If' incorporates:
   *  ActionPort: '<S133>/Action Port'
   *  ActionPort: '<S134>/Action Port'
   *  SubSystem: '<S38>/BigError S1'
   *  SubSystem: '<S38>/BigNegativeError S2'
   */
  rtPrevAction = localDW->If_ActiveSubsystem;
  rtAction = -1;
  if (rtb_Add1 > 180.0) {
    rtAction = 0;
  } else {
    if (rtb_Add1 < -180.0) {
      rtAction = 1;
    }
  }

  localDW->If_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      /* Disable for Outport: '<S133>/Out2' */
      localB->Constant1_e = 0.0;
      break;

     case 1:
      /* Disable for Outport: '<S134>/Out2' */
      localB->Constant1 = 0.0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Sum: '<S133>/Add' incorporates:
     *  Constant: '<S133>/Constant'
     */
    localB->Add_o = rtb_Add1 - 360.0;

    /* Constant: '<S133>/Constant1' */
    localB->Constant1_e = 1.0;
    break;

   case 1:
    /* Sum: '<S134>/Add' incorporates:
     *  Constant: '<S134>/Constant'
     */
    localB->Add = rtb_Add1 + 360.0;

    /* Constant: '<S134>/Constant1' */
    localB->Constant1 = 2.0;
    break;
  }

  /* MultiPortSwitch: '<S38>/Multiport Switch' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Sum: '<S38>/Add2'
   */
  switch ((int32_T)((1.0 + localB->Constant1_e) + localB->Constant1)) {
   case 1:
    break;

   case 2:
    rtb_Add1 = localB->Add_o;
    break;

   default:
    rtb_Add1 = localB->Add;
    break;
  }

  /* SampleTimeMath: '<S136>/TSamp' incorporates:
   *  Gain: '<S135>/Heading Derivative Gain'
   *
   * About '<S136>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
    localDW->StateFlowFunctionsMaintainHea_e * 0.2);

  /* Sum: '<S135>/Sum' incorporates:
   *  DiscreteIntegrator: '<S135>/Heading Discrete-Time Integrator'
   *  Gain: '<S135>/Heading Proportional Gain'
   *  Sum: '<S136>/Diff'
   *  UnitDelay: '<S136>/UD'
   *
   * Block description for '<S136>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S136>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_j - localDW->UD_DSTATE))
    + localDW->HeadingDiscreteTimeIntegrator_D;

  /* Product: '<S38>/Multiply' incorporates:
   *  Constant: '<S38>/Constant'
   */
  tmp = -rtb_Add4;
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(floor(tmp), 256.0);
  }

  /* Sum: '<S38>/Add4' */
  rtb_Add4 += rtu_ForwardVelocity1;

  /* DataTypeConversion: '<S38>/DoubleToint1' incorporates:
   *  Sum: '<S38>/Add3'
   */
  tmp = (real_T)(int8_T)(tmp < 0.0 ? (int32_T)(int8_T)(-((int8_T)(uint8_T)(-tmp)))
    : (int32_T)(int8_T)(uint8_T)tmp) + rtu_ForwardVelocity1;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DoubleToint1 = (int8_T)tmp;
    } else {
      localB->DoubleToint1 = MIN_int8_T;
    }
  } else {
    localB->DoubleToint1 = MAX_int8_T;
  }

  /* DataTypeConversion: '<S38>/DoubleToint8' */
  tmp = floor(rtb_Add4);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DoubleToint8 = (int8_T)tmp;
    } else {
      localB->DoubleToint8 = MIN_int8_T;
    }
  } else {
    localB->DoubleToint8 = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S136>/UD'
   * Block description for '<S136>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_j;

  /* Update for DiscreteIntegrator: '<S135>/Heading Discrete-Time Integrator' incorporates:
   *  Gain: '<S135>/Heading Integral Gain'
   */
  localDW->HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
    localDW->StateFlowFunctionsMaintainHea_e * (brain_P.Heading_Ki * rtb_Add1) +
    localDW->HeadingDiscreteTimeIntegrator_D;
  if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
    localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
  } else {
    if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
    }
  }
}

/* Start for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoys_b_Start(rtB_StateFlowFunctionsBuoysAp_b *localB)
{
  /* Start for Constant: '<S11>/Constant' */
  localB->Constant = brain_P.Buoy2_Hue;

  /* Start for Constant: '<S11>/Constant2' */
  localB->Constant2 = brain_P.Buoy2_Saturation;

  /* Start for Constant: '<S11>/Constant1' */
  localB->Constant1 = brain_P.Buoy2_Value;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApproa_h(rtB_StateFlowFunctionsBuoysAp_b *localB)
{
  /* Constant: '<S11>/Constant' */
  localB->Constant = brain_P.Buoy2_Hue;

  /* Constant: '<S11>/Constant2' */
  localB->Constant2 = brain_P.Buoy2_Saturation;

  /* Constant: '<S11>/Constant1' */
  localB->Constant1 = brain_P.Buoy2_Value;
}

/*
 * Output and update for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsValidationGat(const real_T rtu_H[19200], const real_T
  rtu_S[19200], rtB_StateFlowFunctionsValidatio *localB,
  rtDW_StateFlowFunctionsValidati *localDW)
{
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BlobAnalysis_NUM_PIX_DW;
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  real32_T ys;
  real32_T xys;
  uint32_T k;
  real32_T uyy;
  real32_T majorAxis;
  real32_T rtb_BlobAnalysis;
  int32_T i;
  real32_T centroid_idx;
  real32_T centroid_idx_0;

  /* Logic: '<S137>/Logical Operator1' incorporates:
   *  Constant: '<S139>/Constant'
   *  Constant: '<S140>/Constant'
   *  Constant: '<S141>/Constant'
   *  Logic: '<S137>/Logical Operator'
   *  RelationalOperator: '<S139>/Compare'
   *  RelationalOperator: '<S140>/Compare'
   *  RelationalOperator: '<S141>/Compare'
   */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (((rtu_H[i] < brain_P.Track_HueLower) || (rtu_H[i] >
      brain_P.Track_HueHigher)) && (rtu_S[i] > brain_P.Track_Saturation));
  }

  /* S-Function (svipblob): '<S137>/Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 : 0);
      i++;
      idx++;
    }

    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BlobAnalysis_PAD_DW[i + idx] = 0U;
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
      if (localDW->BlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
        pixIdx++;
        BlobAnalysis_NUM_PIX_DW = 1U;
        localDW->BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BlobAnalysis_STACK_DW[stackIdx];
          for (i = 0; i < 8; i++) {
            k = numBlobs + (uint32_T)brain_ConstP.pooled27[i];
            if (localDW->BlobAnalysis_PAD_DW[k] == 255) {
              localDW->BlobAnalysis_PAD_DW[k] = currentLabel;
              localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)(k
                / 122U) - 1);
              localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k % 122U -
                1U);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW++;
              localDW->BlobAnalysis_STACK_DW[stackIdx] = k;
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
          maxNumBlobsReached = TRUE;
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

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  i = 0;
  n = 0;
  for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
    idx = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
      idx += localDW->BlobAnalysis_N_PIXLIST_DW[j + n];
      ms += localDW->BlobAnalysis_M_PIXLIST_DW[j + i];
    }

    centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW;
    centroid_idx_0 = (real32_T)idx / (real32_T)BlobAnalysis_NUM_PIX_DW;
    rtb_BlobAnalysis = 0.0F;
    ys = 0.0F;
    xys = 0.0F;
    for (k = 0U; k < (uint32_T)(int32_T)BlobAnalysis_NUM_PIX_DW; k++) {
      majorAxis = (real32_T)localDW->BlobAnalysis_N_PIXLIST_DW[n + k] -
        centroid_idx_0;
      uyy = (real32_T)localDW->BlobAnalysis_M_PIXLIST_DW[i + k] - centroid_idx;
      rtb_BlobAnalysis += majorAxis * majorAxis;
      ys += uyy * uyy;
      xys += majorAxis * (-uyy);
    }

    centroid_idx = rtb_BlobAnalysis / (real32_T)BlobAnalysis_NUM_PIX_DW +
      8.333333582E-002F;
    uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-002F;
    rtb_BlobAnalysis = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
    rtb_BlobAnalysis = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx - uyy)
      + rtb_BlobAnalysis * rtb_BlobAnalysis * 4.0F);
    majorAxis = ((centroid_idx + uyy) + rtb_BlobAnalysis) * 8.0F;
    rtb_BlobAnalysis = (real32_T)sqrt(majorAxis - ((centroid_idx + uyy) -
      rtb_BlobAnalysis) * 8.0F) / (real32_T)sqrt(majorAxis);
    i += (int32_T)BlobAnalysis_NUM_PIX_DW;
    n += (int32_T)BlobAnalysis_NUM_PIX_DW;
  }

  for (i = (int32_T)numBlobs; i < 1; i = 1) {
    rtb_BlobAnalysis = -1.0F;
  }

  /* Embedded MATLAB: '<S137>/CheckConditions' incorporates:
   *  Constant: '<S137>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions': '<S138>:1' */
  /*  This function checks the conditions to decide if a track is present */
  if ((real_T)rtb_BlobAnalysis > brain_P.Track_Min_Eccentricity) {
    /* '<S138>:1:4' */
    /* '<S138>:1:5' */
    localB->Image = 1.0;
  } else {
    /* '<S138>:1:7' */
    localB->Image = 0.0;
  }
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOn_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollowOn *localDW)
{
  localDW->StateFlowFunctionsFollowOneP_iz = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePath(real_T rtu_HeadingAlong, RT_MODEL_brain *
  const brain_M, rtB_StateFlowFunctionsFollowOne *localB,
  rtDW_StateFlowFunctionsFollowOn *localDW)
{
  real_T rtb_TSamp_p;
  real_T rtb_Strafe;
  int8_T tmp;
  localDW->StateFlowFunctionsFollowOnePa_j = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsFollowOneP_iz;
  localDW->StateFlowFunctionsFollowOneP_iz = brain_M->Timing.clockTick0;

  /* SampleTimeMath: '<S78>/TSamp' incorporates:
   *  Gain: '<S77>/CamDownStrafe-X Derivative Gain'
   *
   * About '<S78>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_p = brain_P.Cam_Down_Strafe_XPos_Kd * rtu_HeadingAlong / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_j * 0.2);

  /* Embedded MATLAB: '<S20>/Embedded MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<S77>/Depth Discrete-Time Integrator'
   *  Gain: '<S77>/CamDownStrafe-X Proportional Gain'
   *  Gain: '<S77>/Gain'
   *  Sum: '<S77>/Sum'
   *  Sum: '<S78>/Diff'
   *  UnitDelay: '<S78>/UD'
   *
   * Block description for '<S78>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S78>/UD':
   *
   *  Store in Global RAM
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/Embedded MATLAB Function': '<S76>:1' */
  /*  This function makes sure the path was seen and if not, the only sends the */
  /*  forward command to the thrusters */
  if (rtu_HeadingAlong == -999.0) {
    /* '<S76>:1:5' */
    /* '<S76>:1:6' */
    rtb_Strafe = 0.0;
  } else {
    /* '<S76>:1:8' */
    rtb_Strafe = ((brain_P.Cam_Down_Strafe_XPos_Kp * rtu_HeadingAlong
                   + (rtb_TSamp_p - localDW->UD_DSTATE)) +
                  localDW->DepthDiscreteTimeIntegrator_DST) * -1.0;
  }

  /* Gain: '<S20>/Gain' incorporates:
   *  DataTypeConversion: '<S20>/Double To Int8'
   */
  rtb_Strafe = floor(rtb_Strafe);
  if (rtb_Strafe < 128.0) {
    if (rtb_Strafe >= -128.0) {
      tmp = (int8_T)rtb_Strafe;
    } else {
      tmp = MIN_int8_T;
    }
  } else {
    tmp = MAX_int8_T;
  }

  localB->Gain = (int16_T)(-128 * tmp);

  /* Update for UnitDelay: '<S78>/UD'
   * Block description for '<S78>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_p;

  /* Update for DiscreteIntegrator: '<S77>/Depth Discrete-Time Integrator' incorporates:
   *  Gain: '<S77>/CamDownStrafe-X Integral Gain'
   */
  localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_j * (brain_P.Cam_Down_Strafe_XPos_Ki *
    rtu_HeadingAlong) + localDW->DepthDiscreteTimeIntegrator_DST;
  if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
    localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
  } else {
    if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
    }
  }
}

/* Function for Embedded MATLAB: '<S23>/Embedded MATLAB Function' */
static void brain_max(const real_T eml_varargin_1[10], real_T *eml_maxval,
                      real_T *eml_indx)
{
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  boolean_T eml_exitg;
  eml_mtmp = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = FALSE;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = TRUE;
    eml_k = 2;
    eml_exitg = FALSE;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 11)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = FALSE;
        eml_exitg = TRUE;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = TRUE;
    }
  } else {
    eml_guard = TRUE;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 11; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > eml_mtmp) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_maxval = eml_mtmp;
  *eml_indx = (real_T)eml_itmp;
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollow_h_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollow_g *localDW)
{
  localDW->StateFlowFunctionsFollowOnePa_l = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePa_i(const real_T rtu_BW[19200], RT_MODEL_brain *
  const brain_M, rtB_StateFlowFunctionsFollowO_k *localB,
  rtDW_StateFlowFunctionsFollow_g *localDW)
{
  int32_T idxROI;
  int32_T row;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  uint32_T OutCode;
  int32_T eml_Area[10];
  real_T eml_BlobArea;
  real_T eml_index;
  real_T eml_BlobArea_0;
  real_T eml_index_0;
  int32_T i;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T numBlobs;
  real_T rtb_TmpSignalConversionAtDraw_f[2];
  int32_T rtb_BuoyBlobAnalysis_o1_l[10];
  real_T rtb_BuoyBlobAnalysis_o2_h[20];
  int32_T i_0;
  real_T rtb_BuoyBlobAnalysis_o1_l_0[10];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;
  real_T tmp;
  localDW->StateFlowFunctionsFollowOnePa_g = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsFollowOnePa_l;
  localDW->StateFlowFunctionsFollowOnePa_l = brain_M->Timing.clockTick0;

  /* S-Function (svipscalenconvert): '<S23>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipblob): '<S23>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  line_idx_4 = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[line_idx_4] = (uint8_T)
        (localB->ImageDataTypeConversion[i] ? 255 : 0);
      i++;
      line_idx_4++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[line_idx_4] = 0U;
    line_idx_4++;
    localDW->BuoyBlobAnalysis_PAD_DW[line_idx_4] = 0U;
    line_idx_4++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i + line_idx_4] = 0U;
  }

  n = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n_0 = 0; n_0 < 160; n_0++) {
    line_idx_4 = 1;
    i_0 = n * 122;
    for (line_idx_3 = 0; line_idx_3 < 120; line_idx_3++) {
      numBlobs = (uint32_T)(i_0 + line_idx_4);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(line_idx_4 -
          1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (row = 0; row < 8; row++) {
            OutCode = numBlobs + (uint32_T)brain_ConstP.pooled27[row];
            if (localDW->BuoyBlobAnalysis_PAD_DW[OutCode] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[OutCode] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(OutCode / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(OutCode
                % 122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = OutCode;
              stackIdx++;
            }
          }
        }

        if ((BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
             brain_P.Min_Blob_Size) || (BuoyBlobAnalysis_NUM_PIX_DW[currentLabel
             - 1] > brain_P.Max_Blob_Size)) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = TRUE;
          n_0 = 160;
          line_idx_3 = 120;
        }

        if (line_idx_3 < 120) {
          currentLabel++;
        }
      }

      line_idx_4++;
    }

    n++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  i = 0;
  n = 0;
  for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
    rtb_BuoyBlobAnalysis_o1_l[n_0] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    line_idx_4 = 0;
    i_0 = 0;
    for (line_idx_3 = 0; line_idx_3 < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
         line_idx_3++) {
      line_idx_4 += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[line_idx_3 + n];
      i_0 += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[line_idx_3 + i];
    }

    rtb_TmpSignalConversionAtDraw_f[0] = (real_T)i_0 / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    rtb_TmpSignalConversionAtDraw_f[1] = (real_T)line_idx_4 / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    rtb_BuoyBlobAnalysis_o2_h[n_0 << 1] = rtb_TmpSignalConversionAtDraw_f[0];
    rtb_BuoyBlobAnalysis_o2_h[(n_0 << 1) + 1] = rtb_TmpSignalConversionAtDraw_f
      [1];
    i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
    n += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n_0];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_l[i] = -1;
  }

  for (i = (int32_T)numBlobs << 1; i < 20; i++) {
    rtb_BuoyBlobAnalysis_o2_h[i] = -1.0;
  }

  /* Embedded MATLAB: '<S23>/Embedded MATLAB Function' */
  for (i_0 = 0; i_0 < 10; i_0++) {
    eml_Area[i_0] = rtb_BuoyBlobAnalysis_o1_l[i_0];
  }

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function': '<S90>:1' */
  /*  This function will choose and return data about the largest/left blob  */
  /*  given a set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_h[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_h[1] ==
       -1.0)) {
    /* '<S90>:1:5' */
    /* '<S90>:1:7' */
    eml_BlobArea = 80.0;

    /* '<S90>:1:8' */
    eml_BlobArea_0 = 60.0;
  } else {
    for (i_0 = 0; i_0 < 10; i_0++) {
      rtb_BuoyBlobAnalysis_o1_l_0[i_0] = (real_T)rtb_BuoyBlobAnalysis_o1_l[i_0];
    }

    brain_max(rtb_BuoyBlobAnalysis_o1_l_0, &eml_BlobArea, &eml_index);

    /* '<S90>:1:12' */
    eml_Area[(int32_T)eml_index - 1] = 0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      rtb_BuoyBlobAnalysis_o1_l_0[i_0] = (real_T)eml_Area[i_0];
    }

    brain_max(rtb_BuoyBlobAnalysis_o1_l_0, &eml_BlobArea_0, &eml_index_0);
    if (eml_BlobArea < eml_BlobArea_0 * 1.25) {
      /* '<S90>:1:15' */
      if (rtb_BuoyBlobAnalysis_o2_h[(((int32_T)eml_index - 1) << 1U) + 1] >
          rtb_BuoyBlobAnalysis_o2_h[(((int32_T)eml_index_0 - 1) << 1U) + 1]) {
        /* '<S90>:1:16' */
        /* '<S90>:1:17' */
        eml_BlobArea = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)eml_index_0 - 1) <<
          1U) + 1];

        /* '<S90>:1:18' */
        eml_BlobArea_0 = rtb_BuoyBlobAnalysis_o2_h[((int32_T)eml_index_0 - 1) <<
          1U];
      } else {
        /* '<S90>:1:20' */
        eml_BlobArea = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)eml_index - 1) << 1U)
          + 1];

        /* '<S90>:1:21' */
        eml_BlobArea_0 = rtb_BuoyBlobAnalysis_o2_h[((int32_T)eml_index - 1) <<
          1U];
      }
    } else {
      /* '<S90>:1:24' */
      eml_BlobArea = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)eml_index - 1) << 1U)
        + 1];

      /* '<S90>:1:25' */
      eml_BlobArea_0 = rtb_BuoyBlobAnalysis_o2_h[((int32_T)eml_index - 1) << 1U];
    }
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtDraw MarkersInport2' */
  rtb_TmpSignalConversionAtDraw_f[0] = eml_BlobArea_0;
  rtb_TmpSignalConversionAtDraw_f[1] = eml_BlobArea;

  /* S-Function (svipdrawmarkers): '<S23>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)(&rtu_BW[0]), 19200U *
         sizeof(real_T));

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 2; idxROI += 2) {
    tmp = rtb_TmpSignalConversionAtDraw_f[idxROI];
    if ((rtb_TmpSignalConversionAtDraw_f[idxROI] < 4.5035996273704960E+015) &&
        (rtb_TmpSignalConversionAtDraw_f[idxROI] > -4.5035996273704960E+015)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_f[idxROI] + 0.5);
    }

    row = (int32_T)tmp;
    tmp = rtb_TmpSignalConversionAtDraw_f[idxROI + 1];
    if ((tmp < 4.5035996273704960E+015) && (tmp > -4.5035996273704960E+015)) {
      tmp = floor(tmp + 0.5);
    }

    i_0 = (int32_T)tmp;
    line_idx = row - 7;
    line_idx_0 = i_0 - 7;
    line_idx_1 = row + 7;
    line_idx_2 = i_0 + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_4 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_5 = line_idx_1;
    line_idx_6 = line_idx_2;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (line_idx_4 < 0) {
        numBlobs = 4U;
      } else {
        if (line_idx_4 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = 4U;
      } else {
        if (line_idx_5 > 119) {
          OutCode = 8U;
        }
      }

      if (line_idx_3 < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (line_idx_3 > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (line_idx_6 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (line_idx_6 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_4 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = line_idx_5 - line_idx_4;
        n = line_idx_6 - line_idx_3;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_4) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_4 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_5 = line_idx_1;
          line_idx_6 = line_idx_2;
        }

        i = line_idx_5 - line_idx_4;
        n = line_idx_6 - line_idx_3;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_5) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_5) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_6) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_6) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      n = line_idx_3 * 120 + line_idx_4;
      while (line_idx_4 <= line_idx_5) {
        localB->DrawMarkers[n] = 0.75;
        n += 121;
        line_idx_4++;
      }
    }

    line_idx = row - 7;
    line_idx_0 = i_0 + 7;
    line_idx_1 = row + 7;
    line_idx_2 = i_0 - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    i_0 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_5 = line_idx_1;
    line_idx_6 = line_idx_2;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (i_0 < 0) {
        numBlobs = 4U;
      } else {
        if (i_0 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_5 < 0) {
        OutCode = 4U;
      } else {
        if (line_idx_5 > 119) {
          OutCode = 8U;
        }
      }

      if (line_idx_3 < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (line_idx_3 > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (line_idx_6 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (line_idx_6 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          i_0 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = line_idx_5 - i_0;
        n = line_idx_6 - line_idx_3;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          n_0 = (0 - i_0) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          i_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          n_0 = (119 - i_0) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          i_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            i_0 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_3) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            i_0 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            i_0 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_5 = line_idx_1;
          line_idx_6 = line_idx_2;
        }

        i = line_idx_5 - i_0;
        n = line_idx_6 - line_idx_3;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          n_0 = (0 - line_idx_5) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          n_0 = (119 - line_idx_5) * n;
          if (((n_0 >= 0) && (i >= 0)) || ((n_0 < 0) && (i < 0))) {
            line_idx_6 += (div_s32_floor(n_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-n_0) << 1U, i) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          n_0 = (0 - line_idx_6) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          n_0 = (159 - line_idx_6) * i;
          if (((n_0 >= 0) && (n >= 0)) || ((n_0 < 0) && (n < 0))) {
            line_idx_5 += (div_s32_floor(n_0 << 1U, n) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-n_0) << 1U, n) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      n = line_idx_3 * 120 + i_0;
      for (n_0 = i_0; n_0 <= line_idx_5; n_0++) {
        localB->DrawMarkers[n] = 0.75;
        n += -119;
      }
    }
  }

  /* Embedded MATLAB: '<S23>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S23>/Subtract' */
  localB->Subtract = eml_BlobArea - localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* Sum: '<S23>/Subtract1' */
  localB->Subtract1 = eml_BlobArea_0 -
    localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* Sum: '<S92>/Subtract' */
  eml_index = localB->sf_EmbeddedMATLABFunction1.XCenter - eml_BlobArea;

  /* SampleTimeMath: '<S95>/TSamp' incorporates:
   *  Gain: '<S94>/CamDown Strafe XPos Derivative Gain'
   *
   * About '<S95>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_index_0 = brain_P.Cam_Down_Strafe_XPos_Kd * eml_index / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S92>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S94>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S94>/CamDown Strafe XPos Proportional Gain'
   *  Sum: '<S94>/Sum'
   *  Sum: '<S95>/Diff'
   *  UnitDelay: '<S95>/UD'
   *
   * Block description for '<S95>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S95>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_Strafe_XPos_Kp * eml_index + (eml_index_0 -
          localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DataTypeConversion = (int8_T)tmp;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion = MAX_int8_T;
  }

  /* Sum: '<S93>/Subtract' */
  eml_BlobArea = localB->sf_EmbeddedMATLABFunction1.YCenter - eml_BlobArea_0;

  /* SampleTimeMath: '<S97>/TSamp' incorporates:
   *  Gain: '<S96>/Y-Buoy Derivative Gain'
   *
   * About '<S97>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_BlobArea_0 = brain_P.Cam_Down_YPos_Kd * eml_BlobArea / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S93>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S96>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S96>/Y-Buoy Proportional Gain'
   *  Sum: '<S96>/Sum'
   *  Sum: '<S97>/Diff'
   *  UnitDelay: '<S97>/UD'
   *
   * Block description for '<S97>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S97>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_YPos_Kp * eml_BlobArea + (eml_BlobArea_0 -
          localDW->UD_DSTATE_n)) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DataTypeConversion_f = (int8_T)tmp;
    } else {
      localB->DataTypeConversion_f = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion_f = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S95>/UD'
   * Block description for '<S95>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = eml_index_0;

  /* Update for DiscreteIntegrator: '<S94>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S94>/CamDown Strafe XPos Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_Strafe_XPos_Ki *
    eml_index) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S97>/UD'
   * Block description for '<S97>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_n = eml_BlobArea_0;

  /* Update for DiscreteIntegrator: '<S96>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S96>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_YPos_Ki *
    eml_BlobArea) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsJumpHedgeIndi(real_T rtu_B_Hue, real_T rtu_B_Sat, real_T
  rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T rtu_Ref_Colors
  [150], real_T rtu_Num_Colors, rtB_StateFlowFunctionsJumpHedge *localB)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T Xf;
  real_T eml_min_dist;
  real_T eml_dist;
  real_T eml_i;
  int8_T rtb_index_j;
  int32_T i;

  /* S-Function (svipcolorconv): '<S119>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_min_dist = 6.0 * rtu_B_Hue;
  Xf = (real_T)(uint32_T)(eml_min_dist - 1.3322676295501878E-015);
  eml_min_dist -= Xf;
  eml_i = 1.0 - rtu_B_Sat;
  eml_dist = 1.0 - rtu_B_Sat * eml_min_dist;
  eml_min_dist = rtu_B_Sat * eml_min_dist + eml_i;
  if (Xf == 0.0) {
    cc = 1.0;
    cc_0 = eml_min_dist;
    cc_1 = eml_i;
  } else if (Xf == 1.0) {
    cc = eml_dist;
    cc_0 = 1.0;
    cc_1 = eml_i;
  } else if (Xf == 2.0) {
    cc = eml_i;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (Xf == 3.0) {
    cc = eml_i;
    cc_0 = eml_dist;
    cc_1 = 1.0;
  } else if (Xf == 4.0) {
    cc = eml_min_dist;
    cc_0 = eml_i;
    cc_1 = 1.0;
  } else {
    if (Xf == 5.0) {
      cc = 1.0;
      cc_0 = eml_i;
      cc_1 = eml_dist;
    }
  }

  if (cc > cc_0) {
    eml_min_dist = cc;
  } else {
    eml_min_dist = cc_0;
  }

  if (!(eml_min_dist > cc_1)) {
    eml_min_dist = cc_1;
  }

  eml_min_dist = rtu_B_Value / eml_min_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o1 = eml_min_dist * cc;
  localB->ColorSpaceConversion_o2 = eml_min_dist * cc_0;
  localB->ColorSpaceConversion_o3 = eml_min_dist * cc_1;

  /* S-Function (svipcolorconv): '<S119>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-002) {
    eml_min_dist = localB->ColorSpaceConversion_o1 / 1.2923054468333254E+001;
  } else {
    eml_min_dist = (localB->ColorSpaceConversion_o1 + 5.5000519817226361E-002) /
      1.0550005198172263E+000;
    eml_min_dist = rt_pow_snf(eml_min_dist, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-002) {
    eml_i = localB->ColorSpaceConversion_o2 / 1.2923054468333254E+001;
  } else {
    eml_i = (localB->ColorSpaceConversion_o2 + 5.5000519817226361E-002) /
      1.0550005198172263E+000;
    eml_i = rt_pow_snf(eml_i, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-002) {
    eml_dist = localB->ColorSpaceConversion_o3 / 1.2923054468333254E+001;
  } else {
    eml_dist = (localB->ColorSpaceConversion_o3 + 5.5000519817226361E-002) /
      1.0550005198172263E+000;
    eml_dist = rt_pow_snf(eml_dist, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  Xf = (4.1239079926596001E-001 * eml_min_dist + 3.5758433938388001E-001 * eml_i)
    + 1.8048078840182999E-001 * eml_dist;
  cc = (2.1263900587151000E-001 * eml_min_dist + 7.1516867876776002E-001 * eml_i)
    + 7.2192315360729994E-002 * eml_dist;
  eml_min_dist = (1.9330818715590000E-002 * eml_min_dist +
                  1.1919477979463000E-001 * eml_i) + 9.5053215224966003E-001 *
    eml_dist;

  /* Make sure that the output is in [0..1] range; clip if necessary */
  if (Xf > 1.0) {
    Xf = 1.0;
  } else {
    if (Xf < 0.0) {
      Xf = 0.0;
    }
  }

  if (cc > 1.0) {
    cc = 1.0;
  } else {
    if (cc < 0.0) {
      cc = 0.0;
    }
  }

  if (eml_min_dist > 1.0) {
    eml_min_dist = 1.0;
  } else {
    if (eml_min_dist < 0.0) {
      eml_min_dist = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = Xf;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = eml_min_dist;

  /* Convert from XYZ to L*a*b* */
  eml_min_dist = localB->ColorSpaceConversion1_o1 / 9.6419865576090003E-001;
  eml_dist = localB->ColorSpaceConversion1_o3 / 8.2511648322104003E-001;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_min_dist > 8.8564516790356311E-003) {
    Xf = rt_pow_snf(eml_min_dist, 3.3333333333333331E-001);
  } else {
    Xf = 7.7870370370370372E+000 * eml_min_dist + 1.3793103448275862E-001;
  }

  if (localB->ColorSpaceConversion1_o2 > 8.8564516790356311E-003) {
    eml_i = rt_pow_snf(localB->ColorSpaceConversion1_o2, 3.3333333333333331E-001);
  } else {
    eml_i = 7.7870370370370372E+000 * localB->ColorSpaceConversion1_o2 +
      1.3793103448275862E-001;
  }

  if (eml_dist > 8.8564516790356311E-003) {
    eml_min_dist = rt_pow_snf(eml_dist, 3.3333333333333331E-001);
  } else {
    eml_min_dist = 7.7870370370370372E+000 * eml_dist + 1.3793103448275862E-001;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * eml_i - 16.0;
  localB->ColorSpaceConversion1_o2 = (Xf - eml_i) * 500.0;
  localB->ColorSpaceConversion1_o3 = (eml_i - eml_min_dist) * 200.0;

  /* Embedded MATLAB: '<S117>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation/Threshold The Image/Choose Closest Color': '<S118>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S118>:1:5' */
  eml_min_dist = 1000.0;

  /* '<S118>:1:6' */
  /* '<S118>:1:12' */
  rtb_index_j = 1;

  /* '<S118>:1:13' */
  for (eml_i = 1.0; eml_i <= rtu_Num_Colors; eml_i++) {
    /* '<S118>:1:13' */
    /* '<S118>:1:14' */
    eml_dist = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o2 -
      rtu_Ref_Colors[(int32_T)eml_i + 49], 2.0) * 1.5 + rt_pow_snf
                     (localB->ColorSpaceConversion1_o1 - rtu_Ref_Colors[(int32_T)
                      eml_i - 1], 2.0)) + rt_pow_snf
                    (localB->ColorSpaceConversion1_o3 - rtu_Ref_Colors[(int32_T)
                     eml_i + 99], 2.0) * 1.5);
    if (eml_dist < eml_min_dist) {
      /* '<S118>:1:15' */
      /* '<S118>:1:16' */
      eml_min_dist = eml_dist;

      /* '<S118>:1:17' */
      cc = floor(eml_i + 0.5);
      if (cc < 128.0) {
        rtb_index_j = (int8_T)cc;
      } else {
        rtb_index_j = MAX_int8_T;
      }
    }
  }

  if (eml_min_dist > 100.0) {
    /* '<S118>:1:21' */
    /* '<S118>:1:22' */
    cc = rtu_Num_Colors + 1.0;
    cc = cc < 0.0 ? ceil(cc - 0.5) : floor(cc + 0.5);
    if (cc < 128.0) {
      if (cc >= -128.0) {
        rtb_index_j = (int8_T)cc;
      } else {
        rtb_index_j = MIN_int8_T;
      }
    } else {
      rtb_index_j = MAX_int8_T;
    }
  }

  /* RelationalOperator: '<S117>/Relational Operator' */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (rtu_LabMatrix[i] == (real_T)rtb_index_j);
  }
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsJumpHe_k_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsJumpHe_e *localDW)
{
  localDW->StateFlowFunctionsJumpHedgeCa_l = brain_M->Timing.clockTick0;
}

/* Start for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsJumpH_a_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsJumpHe_e *localDW)
{
  int32_T idxNHood;
  int32_T idxOffsets;
  int32_T curNumNonZ;
  int32_T n;
  int32_T m;

  /* Start for S-Function (svipmorphop): '<S28>/Dilation' */
  idxOffsets = 0;
  curNumNonZ = 0;
  idxNHood = 4;
  for (m = 0; m < 2; m++) {
    for (n = 0; n < 2; n++) {
      idxNHood--;
      if (brain_ConstP.pooled36[idxNHood]) {
        localDW->Dilation_DILATE_OFF_DW[idxOffsets] = m * 123 + n;
        curNumNonZ++;
        idxOffsets++;
      }
    }
  }

  localDW->Dilation_NUMNONZ_DW = curNumNonZ;

  /* Start for S-Function (svipmorphop): '<S28>/Erosion' */
  idxNHood = 0;
  idxOffsets = 0;
  curNumNonZ = 0;
  for (n = 0; n < 1; n = 1) {
    for (m = 0; m < 4; m++) {
      if (brain_ConstP.pooled35[idxNHood]) {
        localDW->Erosion_ERODE_OFF_DW[idxOffsets] = m;
        curNumNonZ++;
        idxOffsets++;
      }

      idxNHood++;
    }
  }

  localDW->Erosion_NUMNONZ_DW[0] = curNumNonZ;
  curNumNonZ = 0;
  for (n = 0; n < 4; n++) {
    for (m = 0; m < 1; m = 1) {
      if (brain_ConstP.pooled35[idxNHood]) {
        localDW->Erosion_ERODE_OFF_DW[idxOffsets] = n * 127;
        curNumNonZ++;
        idxOffsets++;
      }

      idxNHood++;
    }
  }

  localDW->Erosion_NUMNONZ_DW[1] = curNumNonZ;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsJumpHedgeCame(const real_T rtu_BW[19200], real_T
  rtu_ForwardVelocity, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsJumpHed_b *localB, rtDW_StateFlowFunctionsJumpHe_e
  *localDW)
{
  int32_T idxROI;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  uint32_T OutCode;
  real_T eml_BlobCentroidX;
  real_T eml_BlobCentroidY;
  int32_T i;
  int32_T ku;
  int32_T i_0;
  int32_T n;
  int32_T i_1;
  int32_T idxAdj;
  int32_T n_0;
  int32_T outIdx;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T numBlobs;
  real_T rtb_TmpSignalConversionAtDraw_p[2];
  real_T rtb_Sum_cg;
  real_T rtb_TSamp_n;
  int32_T rtb_BuoyBlobAnalysis_o1_c[10];
  real_T rtb_BuoyBlobAnalysis_o2_c[20];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  real_T tmp;
  int8_T rtb_DataTypeConversion_m_0;
  localDW->StateFlowFunctionsJumpHedgeCa_c = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsJumpHedgeCa_l;
  localDW->StateFlowFunctionsJumpHedgeCa_l = brain_M->Timing.clockTick0;

  /* S-Function (svipscalenconvert): '<S28>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipmorphop): '<S28>/Dilation' */
  i = 0;
  ku = 0;
  for (n = 0; n < 123; n++) {
    localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
    i++;
  }

  for (i_0 = 0; i_0 < 160; i_0++) {
    localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
    i++;
    memcpy((void *)(&localDW->Dilation_ONE_PAD_IMG_DW[i]), (void *)
           (&localB->ImageDataTypeConversion[ku]), 120U * sizeof(boolean_T));
    i += 120;
    ku += 120;
    localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
    i++;
    localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
    i++;
  }

  for (i_0 = 161; i_0 < 163; i_0++) {
    for (n = 0; n < 123; n++) {
      localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
      i++;
    }
  }

  i = 0;
  ku = 0;
  for (n = 0; n < 160; n++) {
    for (i_1 = 0; i_1 < 120; i_1++) {
      localB->Dilation[ku] = FALSE;
      for (outIdx = 0; outIdx < localDW->Dilation_NUMNONZ_DW; outIdx++) {
        if (localDW->Dilation_ONE_PAD_IMG_DW[i + localDW->
            Dilation_DILATE_OFF_DW[outIdx]]) {
          localB->Dilation[ku] = TRUE;
          outIdx = localDW->Dilation_NUMNONZ_DW;
        }
      }

      i++;
      ku++;
    }

    i += 3;
  }

  /* S-Function (svipmorphop): '<S28>/Erosion' */
  i = 0;
  ku = 0;
  for (n = 0; n < 127; n++) {
    localDW->Erosion_ONE_PAD_IMG_DW[i] = TRUE;
    i++;
  }

  for (i_0 = 0; i_0 < 160; i_0++) {
    localDW->Erosion_ONE_PAD_IMG_DW[i] = TRUE;
    i++;
    memcpy((void *)(&localDW->Erosion_ONE_PAD_IMG_DW[i]), (void *)
           (&localB->Dilation[ku]), 120U * sizeof(boolean_T));
    i += 120;
    ku += 120;
    for (n = 121; n < 127; n++) {
      localDW->Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
    }
  }

  for (i_0 = 161; i_0 < 167; i_0++) {
    for (n = 0; n < 127; n++) {
      localDW->Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
    }
  }

  for (i_1 = 0; i_1 < 21209; i_1++) {
    localDW->Erosion_TWO_PAD_IMG_DW[i_1] = TRUE;
  }

  ku = 0;
  for (n_0 = 0; n_0 < 167; n_0++) {
    for (line_idx_3 = 0; line_idx_3 < 124; line_idx_3++) {
      localDW->Erosion_TWO_PAD_IMG_DW[1 + ku] = TRUE;
      for (i_1 = 0; i_1 < localDW->Erosion_NUMNONZ_DW[0]; i_1++) {
        if (!localDW->Erosion_ONE_PAD_IMG_DW[ku + localDW->
            Erosion_ERODE_OFF_DW[i_1]]) {
          localDW->Erosion_TWO_PAD_IMG_DW[1 + ku] = FALSE;
          i_1 = localDW->Erosion_NUMNONZ_DW[0];
        }
      }

      ku++;
    }

    ku += 3;
  }

  n = 1;
  outIdx = 0;
  for (n_0 = 0; n_0 < 160; n_0++) {
    for (line_idx_3 = 1; line_idx_3 < 121; line_idx_3++) {
      localB->Erosion[outIdx] = TRUE;
      for (i_1 = 0; i_1 < localDW->Erosion_NUMNONZ_DW[1]; i_1++) {
        if (!localDW->Erosion_TWO_PAD_IMG_DW[localDW->Erosion_ERODE_OFF_DW[i_1 +
            localDW->Erosion_NUMNONZ_DW[0]] + n]) {
          localB->Erosion[outIdx] = FALSE;
          i_1 = localDW->Erosion_NUMNONZ_DW[1];
        }
      }

      n++;
      outIdx++;
    }

    n += 7;
  }

  /* S-Function (svipblob): '<S28>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  n = 123;
  for (ku = 0; ku < 160; ku++) {
    for (i_0 = 0; i_0 < 120; i_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[n] = (uint8_T)(localB->Erosion[i] ? 255 :
        0);
      i++;
      n++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[n] = 0U;
    n++;
    localDW->BuoyBlobAnalysis_PAD_DW[n] = 0U;
    n++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i + n] = 0U;
  }

  ku = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (i_0 = 0; i_0 < 160; i_0++) {
    n = 1;
    i_1 = ku * 122;
    for (outIdx = 0; outIdx < 120; outIdx++) {
      numBlobs = (uint32_T)(i_1 + n);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(ku - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (idxAdj = 0; idxAdj < 8; idxAdj++) {
            OutCode = numBlobs + (uint32_T)brain_ConstP.pooled27[idxAdj];
            if (localDW->BuoyBlobAnalysis_PAD_DW[OutCode] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[OutCode] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(OutCode / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(OutCode
                % 122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = OutCode;
              stackIdx++;
            }
          }
        }

        if ((BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
             brain_P.Min_Blob_Size) || (BuoyBlobAnalysis_NUM_PIX_DW[currentLabel
             - 1] > brain_P.Max_Blob_Size)) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = TRUE;
          i_0 = 160;
          outIdx = 120;
        }

        if (outIdx < 120) {
          currentLabel++;
        }
      }

      n++;
    }

    ku++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  i = 0;
  ku = 0;
  for (i_0 = 0; i_0 < (int32_T)numBlobs; i_0++) {
    rtb_BuoyBlobAnalysis_o1_c[i_0] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i_0];
    n = 0;
    i_1 = 0;
    for (outIdx = 0; outIdx < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i_0]; outIdx
         ++) {
      n += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[outIdx + ku];
      i_1 += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[outIdx + i];
    }

    rtb_TmpSignalConversionAtDraw_p[0] = (real_T)i_1 / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i_0];
    rtb_TmpSignalConversionAtDraw_p[1] = (real_T)n / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i_0];
    rtb_BuoyBlobAnalysis_o2_c[i_0 << 1] = rtb_TmpSignalConversionAtDraw_p[0];
    rtb_BuoyBlobAnalysis_o2_c[(i_0 << 1) + 1] = rtb_TmpSignalConversionAtDraw_p
      [1];
    i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i_0];
    ku += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i_0];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_c[i] = -1;
  }

  for (i = (int32_T)numBlobs << 1; i < 20; i++) {
    rtb_BuoyBlobAnalysis_o2_c[i] = -1.0;
  }

  /* S-Function (svipscalenconvert): '<S28>/Image Data Type Conversion1' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion1[i] = localB->Erosion[i] ? 1.0 : 0.0;
  }

  /* Embedded MATLAB: '<S28>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Embedded MATLAB Function': '<S108>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_c[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_c[1] ==
       -1.0)) {
    /* '<S108>:1:5' */
    /* '<S108>:1:7' */
    eml_BlobCentroidX = 80.0;

    /* '<S108>:1:8' */
    eml_BlobCentroidY = 60.0;

    /* '<S108>:1:9' */
  } else {
    i = rtb_BuoyBlobAnalysis_o1_c[0];
    ku = 1;
    i_0 = 1;
    for (n = 2; n < 11; n++) {
      i_0++;
      if (rtb_BuoyBlobAnalysis_o1_c[i_0 - 1] > i) {
        i = rtb_BuoyBlobAnalysis_o1_c[i_0 - 1];
        ku = n;
      }
    }

    /* '<S108>:1:11' */
    /* '<S108>:1:12' */
    eml_BlobCentroidX = rtb_BuoyBlobAnalysis_o2_c[((ku - 1) << 1) + 1];

    /* '<S108>:1:13' */
    eml_BlobCentroidY = rtb_BuoyBlobAnalysis_o2_c[(ku - 1) << 1];
  }

  /* SignalConversion: '<S28>/TmpSignal ConversionAtDraw MarkersInport2' */
  rtb_TmpSignalConversionAtDraw_p[0] = eml_BlobCentroidY;
  rtb_TmpSignalConversionAtDraw_p[1] = eml_BlobCentroidX;

  /* S-Function (svipdrawmarkers): '<S28>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)
         (&localB->ImageDataTypeConversion1[0]), 19200U * sizeof(real_T));

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 2; idxROI += 2) {
    tmp = rtb_TmpSignalConversionAtDraw_p[idxROI];
    if ((rtb_TmpSignalConversionAtDraw_p[idxROI] < 4.5035996273704960E+015) &&
        (rtb_TmpSignalConversionAtDraw_p[idxROI] > -4.5035996273704960E+015)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_p[idxROI] + 0.5);
    }

    outIdx = (int32_T)tmp;
    tmp = rtb_TmpSignalConversionAtDraw_p[idxROI + 1];
    if ((tmp < 4.5035996273704960E+015) && (tmp > -4.5035996273704960E+015)) {
      tmp = floor(tmp + 0.5);
    }

    idxAdj = (int32_T)tmp;
    line_idx = outIdx - 7;
    line_idx_0 = idxAdj - 7;
    line_idx_1 = outIdx + 7;
    line_idx_2 = idxAdj + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    n_0 = line_idx;
    n = line_idx_0;
    i_1 = line_idx_1;
    line_idx_3 = line_idx_2;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (n_0 < 0) {
        numBlobs = 4U;
      } else {
        if (n_0 > 119) {
          numBlobs = 8U;
        }
      }

      if (i_1 < 0) {
        OutCode = 4U;
      } else {
        if (i_1 > 119) {
          OutCode = 8U;
        }
      }

      if (n < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (n > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (line_idx_3 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (line_idx_3 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          n_0 = line_idx;
          n = line_idx_0;
        }

        i = i_1 - n_0;
        ku = line_idx_3 - n;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          i_0 = (0 - n_0) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            n += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            n += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          i_0 = (119 - n_0) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            n += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            n += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          i_0 = (0 - n) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n_0 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n_0 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          n = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          i_0 = (159 - n) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n_0 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n_0 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          n = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          i_1 = line_idx_1;
          line_idx_3 = line_idx_2;
        }

        i = i_1 - n_0;
        ku = line_idx_3 - n;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          i_0 = (0 - i_1) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          i_1 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          i_0 = (119 - i_1) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          i_1 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          i_0 = (0 - line_idx_3) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            i_1 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            i_1 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          i_0 = (159 - line_idx_3) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            i_1 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            i_1 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ku = n * 120 + n_0;
      for (i_0 = n_0; i_0 <= i_1; i_0++) {
        localB->DrawMarkers[ku] = 0.5;
        ku += 121;
      }
    }

    line_idx = outIdx - 7;
    line_idx_0 = idxAdj + 7;
    line_idx_1 = outIdx + 7;
    line_idx_2 = idxAdj - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    n_0 = line_idx;
    line_idx_3 = line_idx_0;
    n = line_idx_1;
    i_1 = line_idx_2;
    while (!done) {
      numBlobs = 0U;
      OutCode = 0U;

      /* Determine viewport violations. */
      if (n_0 < 0) {
        numBlobs = 4U;
      } else {
        if (n_0 > 119) {
          numBlobs = 8U;
        }
      }

      if (n < 0) {
        OutCode = 4U;
      } else {
        if (n > 119) {
          OutCode = 8U;
        }
      }

      if (line_idx_3 < 0) {
        numBlobs = (uint32_T)((int32_T)numBlobs | 1);
      } else {
        if (line_idx_3 > 159) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 2);
        }
      }

      if (i_1 < 0) {
        OutCode = (uint32_T)((int32_T)OutCode | 1);
      } else {
        if (i_1 > 159) {
          OutCode = (uint32_T)((int32_T)OutCode | 2);
        }
      }

      if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          n_0 = line_idx;
          line_idx_3 = line_idx_0;
        }

        i = n - n_0;
        ku = i_1 - line_idx_3;
        if ((uint32_T)((int32_T)numBlobs & 4)) {
          /* Violated RMin. */
          i_0 = (0 - n_0) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n_0 = 0;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 8)) {
          /* Violated RMax. */
          i_0 = (119 - n_0) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            line_idx_3 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n_0 = 119;
          visited = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & 1)) {
          /* Violated CMin. */
          i_0 = (0 - line_idx_3) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n_0 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n_0 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          i_0 = (159 - line_idx_3) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n_0 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n_0 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          line_idx_3 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          n = line_idx_1;
          i_1 = line_idx_2;
        }

        i = n - n_0;
        ku = i_1 - line_idx_3;
        if ((uint32_T)((int32_T)OutCode & 4)) {
          /* Violated RMin. */
          i_0 = (0 - n) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            i_1 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            i_1 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 8)) {
          /* Violated RMax. */
          i_0 = (119 - n) * ku;
          if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
            i_1 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
          } else {
            i_1 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
          }

          n = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)((int32_T)OutCode & 1)) {
          /* Violated CMin. */
          i_0 = (0 - i_1) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          i_1 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          i_0 = (159 - i_1) * i;
          if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
            n += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
          } else {
            n += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
          }

          i_1 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ku = line_idx_3 * 120 + n_0;
      for (i_0 = n_0; i_0 <= n; i_0++) {
        localB->DrawMarkers[ku] = 0.5;
        ku += -119;
      }
    }
  }

  /* Embedded MATLAB: '<S28>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S110>/Subtract' */
  rtb_Sum_cg = localB->sf_EmbeddedMATLABFunction1.XCenter - eml_BlobCentroidX;

  /* SampleTimeMath: '<S113>/TSamp' incorporates:
   *  Gain: '<S112>/X-Buoy Derivative Gain'
   *
   * About '<S113>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_n = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum_cg / ((real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * 0.2);

  /* DataTypeConversion: '<S110>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S112>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S112>/X-Buoy Proportional Gain'
   *  Sum: '<S112>/Sum'
   *  Sum: '<S113>/Diff'
   *  UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Forward_XPosition_Kp * rtb_Sum_cg + (rtb_TSamp_n -
          localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      rtb_DataTypeConversion_m_0 = (int8_T)tmp;
    } else {
      rtb_DataTypeConversion_m_0 = MIN_int8_T;
    }
  } else {
    rtb_DataTypeConversion_m_0 = MAX_int8_T;
  }

  /* Sum: '<S110>/Add' */
  localB->Add = rtu_ForwardVelocity + (real_T)rtb_DataTypeConversion_m_0;

  /* Sum: '<S110>/Add1' incorporates:
   *  Constant: '<S110>/Constant'
   *  Product: '<S110>/Multiply'
   */
  localB->Add1 = (real_T)rtb_DataTypeConversion_m_0 * -1.0 + rtu_ForwardVelocity;

  /* Sum: '<S111>/Subtract' */
  eml_BlobCentroidX = eml_BlobCentroidY -
    localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* SampleTimeMath: '<S115>/TSamp' incorporates:
   *  Gain: '<S114>/Y-Buoy Derivative Gain'
   *
   * About '<S115>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_BlobCentroidY = brain_P.Cam_Forward_YPosition_Kd * eml_BlobCentroidX /
    ((real_T)localDW->StateFlowFunctionsJumpHedgeCa_c * 0.2);

  /* DataTypeConversion: '<S111>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S114>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S114>/Y-Buoy Proportional Gain'
   *  Sum: '<S114>/Sum'
   *  Sum: '<S115>/Diff'
   *  UnitDelay: '<S115>/UD'
   *
   * Block description for '<S115>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Forward_YPosition_Kp * eml_BlobCentroidX +
         (eml_BlobCentroidY - localDW->UD_DSTATE_a)) +
    localDW->YBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DataTypeConversion = (int8_T)tmp;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S113>/UD'
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_n;

  /* Update for DiscreteIntegrator: '<S112>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S112>/X-Buoy Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * (brain_P.Cam_Forward_XPosition_Ki
    * rtb_Sum_cg) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S115>/UD'
   * Block description for '<S115>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_a = eml_BlobCentroidY;

  /* Update for DiscreteIntegrator: '<S114>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S114>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * (brain_P.Cam_Forward_YPosition_Ki
    * eml_BlobCentroidX) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsJumpHedgeGetA(const real_T rtu_BW[19200],
  rtB_StateFlowFunctionsJumpHed_m *localB, rtDW_StateFlowFunctionsJumpHe_j
  *localDW)
{
  int32_T i;
  int32_T padRows;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T BlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T pixListMinc;
  int32_T maxr;
  int32_T j;
  int32_T rtb_BlobAnalysis_o1[10];
  int32_T rtb_BlobAnalysis_o2[40];

  /* S-Function (svipscalenconvert): '<S29>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipblob): '<S29>/Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (nn = 0; nn < 120; nn++) {
      localDW->BlobAnalysis_PAD_DW[idx] = (uint8_T)
        (localB->ImageDataTypeConversion[i] ? 255 : 0);
      i++;
      idx++;
    }

    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BlobAnalysis_PAD_DW[i + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    idx = 1;
    maxr = nn * 122;
    for (j = 0; j < 120; j++) {
      numBlobs = (uint32_T)(maxr + idx);
      if (localDW->BlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
        localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(idx - 1);
        pixIdx++;
        BlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BlobAnalysis_STACK_DW[stackIdx];
          for (pixListMinc = 0; pixListMinc < 8; pixListMinc++) {
            walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled27[pixListMinc];
            if (localDW->BlobAnalysis_PAD_DW[walkerIdx] == 255) {
              localDW->BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
              localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 122U) - 1);
              localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx %
                122U - 1U);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              localDW->BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = TRUE;
          n = 160;
          j = 120;
        }

        if (j < 120) {
          currentLabel++;
        }
      }

      idx++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  pixListMinc = 0;
  padRows = 0;
  for (padCols = 0; padCols < (int32_T)numBlobs; padCols++) {
    rtb_BlobAnalysis_o1[padCols] = (int32_T)BlobAnalysis_NUM_PIX_DW[padCols];
    n = 160;
    idx = 120;
    nn = 0;
    maxr = 0;
    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW[padCols]; j++) {
      i = j + padRows;
      if (localDW->BlobAnalysis_N_PIXLIST_DW[i] < n) {
        n = localDW->BlobAnalysis_N_PIXLIST_DW[i];
      }

      if (localDW->BlobAnalysis_N_PIXLIST_DW[i] > nn) {
        nn = localDW->BlobAnalysis_N_PIXLIST_DW[i];
      }

      i = j + pixListMinc;
      if (localDW->BlobAnalysis_M_PIXLIST_DW[i] < idx) {
        idx = localDW->BlobAnalysis_M_PIXLIST_DW[i];
      }

      if (localDW->BlobAnalysis_M_PIXLIST_DW[i] > maxr) {
        maxr = localDW->BlobAnalysis_M_PIXLIST_DW[i];
      }
    }

    i = padCols << 2;
    rtb_BlobAnalysis_o2[i] = idx;
    rtb_BlobAnalysis_o2[i + 1] = n;
    rtb_BlobAnalysis_o2[i + 2] = (maxr + 1) - idx;
    rtb_BlobAnalysis_o2[i + 3] = (nn + 1) - n;
    pixListMinc += (int32_T)BlobAnalysis_NUM_PIX_DW[padCols];
    padRows += (int32_T)BlobAnalysis_NUM_PIX_DW[padCols];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BlobAnalysis_o1[i] = -1;
  }

  for (i = (int32_T)numBlobs << 2; i < 40; i++) {
    rtb_BlobAnalysis_o2[i] = -1;
  }

  /* Embedded MATLAB: '<S29>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.GetAxisRatio/Embedded MATLAB Function': '<S116>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if (rtb_BlobAnalysis_o2[0] == -1) {
    /* '<S116>:1:5' */
    /* '<S116>:1:7' */
    localB->AxisRatio = 0.0;

    /* '<S116>:1:8' */
  } else {
    i = rtb_BlobAnalysis_o1[0];
    n = 1;
    nn = 1;
    for (idx = 2; idx < 11; idx++) {
      nn++;
      if (rtb_BlobAnalysis_o1[nn - 1] > i) {
        i = rtb_BlobAnalysis_o1[nn - 1];
        n = idx;
      }
    }

    /* '<S116>:1:10' */
    /* '<S116>:1:11' */
    localB->AxisRatio = (real_T)rtb_BlobAnalysis_o2[((n - 1) << 2) + 3] /
      (real_T)rtb_BlobAnalysis_o2[((n - 1) << 2) + 2];
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateManagementRunningAutonomou(real_T rtu_State1,
  rtB_StateManagementRunningAuton *localB)
{
  /* Embedded MATLAB: '<S41>/Checking to see if state will be performed' incorporates:
   *  Constant: '<S41>/Mission Plan'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateManagement.Running.Autonomous.Perform/Checking to see if state will be performed': '<S142>:1' */
  /*  This function checks to see if the current state should be executed */
  if (brain_P.MissionPlan[(int32_T)rtu_State1 - 1] != 0.0) {
    /* '<S142>:1:4' */
    /* '<S142>:1:5' */
    localB->Done1 = 0.0;
  } else {
    /* '<S142>:1:7' */
    localB->Done1 = 1.0;
  }
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollow_i_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollo_gn *localDW)
{
  localDW->StateFlowFunctionsFollowOnePa_m = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePa_e(const real_T rtu_BW[19200], RT_MODEL_brain *
  const brain_M, rtB_StateFlowFunctionsFollowO_f *localB,
  rtDW_StateFlowFunctionsFollo_gn *localDW)
{
  real_T eml_BlobCentroidX;
  real_T eml_BlobCentroidY;
  int32_T i;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  real_T rtb_Sum_l;
  real_T rtb_TSamp_m;
  int32_T rtb_BuoyBlobAnalysis_o1_o[10];
  real_T rtb_BuoyBlobAnalysis_o2_ci[20];
  real_T tmp;
  int16_T tmp_0;
  localDW->StateFlowFunctionsFollowOnePa_g = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsFollowOnePa_m;
  localDW->StateFlowFunctionsFollowOnePa_m = brain_M->Timing.clockTick0;

  /* S-Function (svipscalenconvert): '<S22>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipblob): '<S22>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)
        (localB->ImageDataTypeConversion[i] ? 255 : 0);
      i++;
      idx++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
    localDW->BuoyBlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
  }

  for (i = 0; i < 121; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i + idx] = 0U;
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
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (i = 0; i < 8; i++) {
            walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled27[i];
            if (localDW->BuoyBlobAnalysis_PAD_DW[walkerIdx] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(walkerIdx / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                (walkerIdx % 122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if ((BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
             brain_P.Min_Blob_Size) || (BuoyBlobAnalysis_NUM_PIX_DW[currentLabel
             - 1] > brain_P.Max_Blob_Size)) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 10) {
          maxNumBlobsReached = TRUE;
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

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  i = 0;
  n_0 = 0;
  for (idx = 0; idx < (int32_T)numBlobs; idx++) {
    rtb_BuoyBlobAnalysis_o1_o[idx] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
    n = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx]; j++) {
      n += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + n_0];
      ms += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + i];
    }

    rtb_BuoyBlobAnalysis_o2_ci[idx << 1] = (real_T)ms / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[idx];
    rtb_BuoyBlobAnalysis_o2_ci[(idx << 1) + 1] = (real_T)n / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[idx];
    i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
    n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_o[i] = -1;
  }

  for (i = (int32_T)numBlobs << 1; i < 20; i++) {
    rtb_BuoyBlobAnalysis_o2_ci[i] = -1.0;
  }

  /* Embedded MATLAB: '<S22>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw/Embedded MATLAB Function': '<S82>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_ci[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_ci[1] ==
       -1.0)) {
    /* '<S82>:1:5' */
    /* '<S82>:1:7' */
    eml_BlobCentroidX = 80.0;

    /* '<S82>:1:8' */
    eml_BlobCentroidY = 60.0;
  } else {
    i = rtb_BuoyBlobAnalysis_o1_o[0];
    n = 1;
    n_0 = 1;
    for (idx = 2; idx < 11; idx++) {
      n_0++;
      if (rtb_BuoyBlobAnalysis_o1_o[n_0 - 1] > i) {
        i = rtb_BuoyBlobAnalysis_o1_o[n_0 - 1];
        n = idx;
      }
    }

    /* '<S82>:1:12' */
    eml_BlobCentroidX = rtb_BuoyBlobAnalysis_o2_ci[((n - 1) << 1) + 1];

    /* '<S82>:1:13' */
    eml_BlobCentroidY = rtb_BuoyBlobAnalysis_o2_ci[(n - 1) << 1];
  }

  /* Embedded MATLAB: '<S22>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S22>/Subtract' */
  localB->Subtract = eml_BlobCentroidX -
    localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* Sum: '<S22>/Subtract1' */
  localB->Subtract1 = eml_BlobCentroidY -
    localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* Sum: '<S84>/Subtract' */
  rtb_Sum_l = eml_BlobCentroidX - localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* SampleTimeMath: '<S87>/TSamp' incorporates:
   *  Gain: '<S86>/X-Buoy Derivative Gain'
   *
   * About '<S87>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_m = brain_P.Cam_Down_Yaw_XPos_Kd * rtb_Sum_l / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S84>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S86>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S86>/X-Buoy Proportional Gain'
   *  Sum: '<S86>/Sum'
   *  Sum: '<S87>/Diff'
   *  UnitDelay: '<S87>/UD'
   *
   * Block description for '<S87>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S87>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_Yaw_XPos_Kp * rtb_Sum_l + (rtb_TSamp_m -
          localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DataTypeConversion = (int8_T)tmp;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion = MAX_int8_T;
  }

  /* DataTypeConversion: '<S84>/Data Type Conversion1' incorporates:
   *  Gain: '<S84>/Gain'
   */
  tmp_0 = (int16_T)(-128 * localB->DataTypeConversion >> 7);
  if (tmp_0 > 127) {
    localB->DataTypeConversion1 = MAX_int8_T;
  } else {
    localB->DataTypeConversion1 = (int8_T)tmp_0;
  }

  /* Sum: '<S85>/Subtract' */
  eml_BlobCentroidX = localB->sf_EmbeddedMATLABFunction1.YCenter -
    eml_BlobCentroidY;

  /* SampleTimeMath: '<S89>/TSamp' incorporates:
   *  Gain: '<S88>/Y-Blob Derivative Gain'
   *
   * About '<S89>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_BlobCentroidY = brain_P.Cam_Down_YPos_Kd * eml_BlobCentroidX / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S85>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S88>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S88>/Y-Blob Proportional Gain'
   *  Sum: '<S88>/Sum'
   *  Sum: '<S89>/Diff'
   *  UnitDelay: '<S89>/UD'
   *
   * Block description for '<S89>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S89>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_YPos_Kp * eml_BlobCentroidX + (eml_BlobCentroidY -
          localDW->UD_DSTATE_o)) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DataTypeConversion_m = (int8_T)tmp;
    } else {
      localB->DataTypeConversion_m = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion_m = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S87>/UD'
   * Block description for '<S87>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_m;

  /* Update for DiscreteIntegrator: '<S86>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S86>/X-Buoy Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_Yaw_XPos_Ki *
    rtb_Sum_l) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S89>/UD'
   * Block description for '<S89>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_o = eml_BlobCentroidY;

  /* Update for DiscreteIntegrator: '<S88>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S88>/Y-Blob Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_YPos_Ki *
    eml_BlobCentroidX) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_Autonomous(void)
{
  switch (brain_DWork.was_Autonomous) {
   case brain_IN_Breach:
    /* Entry 'Breach': '<S7>:1744' */
    brain_DWork.is_Autonomous = brain_IN_Breach;
    brain_DWork.was_Autonomous = brain_IN_Breach;
    brain_B.State = 12;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_Buoy:
    /* Entry 'Buoy': '<S7>:1025' */
    brain_DWork.is_Autonomous = brain_IN_Buoy;
    brain_DWork.was_Autonomous = brain_IN_Buoy;
    brain_B.State = 4;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_ChooseState:
    /* Entry 'ChooseState': '<S7>:1134' */
    brain_DWork.is_Autonomous = brain_IN_ChooseState;
    brain_DWork.was_Autonomous = brain_IN_ChooseState;
    brain_DWork.Done = 0.0;
    break;

   case brain_IN_DropMechanism:
    /* Entry 'DropMechanism': '<S7>:1722' */
    brain_DWork.is_Autonomous = brain_IN_DropMechanism;
    brain_DWork.was_Autonomous = brain_IN_DropMechanism;
    brain_B.State = 8;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_Finish:
    /* Entry 'Finish': '<S7>:1064' */
    brain_DWork.is_Autonomous = brain_IN_Finish;
    brain_DWork.was_Autonomous = brain_IN_Finish;
    brain_B.State = 13;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_FollowOnePath1:
    /* Entry 'FollowOnePath1': '<S7>:1065' */
    brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
    brain_DWork.was_Autonomous = brain_IN_FollowOnePath1;
    brain_B.State = 3;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_FollowOnePath2:
    /* Entry 'FollowOnePath2': '<S7>:1142' */
    brain_DWork.is_Autonomous = brain_IN_FollowOnePath2;
    brain_DWork.was_Autonomous = brain_IN_FollowOnePath2;
    brain_B.State = 5;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_FollowOnePath3:
    /* Entry 'FollowOnePath3': '<S7>:1718' */
    brain_DWork.is_Autonomous = brain_IN_FollowOnePath3;
    brain_DWork.was_Autonomous = brain_IN_FollowOnePath3;
    brain_B.State = 7;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_FollowOnePath4:
    /* Entry 'FollowOnePath4': '<S7>:1732' */
    brain_DWork.is_Autonomous = brain_IN_FollowOnePath4;
    brain_DWork.was_Autonomous = brain_IN_FollowOnePath4;
    brain_B.State = 9;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_Hedge1:
    /* Entry 'Hedge1': '<S7>:1701' */
    brain_DWork.is_Autonomous = brain_IN_Hedge1;
    brain_DWork.was_Autonomous = brain_IN_Hedge1;
    brain_B.State = 6;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_Hedge2:
    /* Entry 'Hedge2': '<S7>:1735' */
    brain_DWork.is_Autonomous = brain_IN_Hedge2;
    brain_DWork.was_Autonomous = brain_IN_Hedge2;
    brain_B.State = 10;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_LocatePinger:
    /* Entry 'LocatePinger': '<S7>:1739' */
    brain_DWork.is_Autonomous = brain_IN_LocatePinger;
    brain_DWork.was_Autonomous = brain_IN_LocatePinger;
    brain_B.State = 11;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_Start_m:
    /* Entry 'Start': '<S7>:1019' */
    brain_DWork.is_Autonomous = brain_IN_Start_m;
    brain_DWork.was_Autonomous = brain_IN_Start_m;
    brain_B.State = 1;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   case brain_IN_ValidationGate_m:
    /* Entry 'ValidationGate': '<S7>:1121' */
    brain_DWork.is_Autonomous = brain_IN_ValidationGate_m;
    brain_DWork.was_Autonomous = brain_IN_ValidationGate_m;
    brain_B.State = 2;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;

   default:
    /* Transition: '<S7>:946' */
    /* Entry 'Start': '<S7>:1019' */
    brain_DWork.is_Autonomous = brain_IN_Start_m;
    brain_DWork.was_Autonomous = brain_IN_Start_m;
    brain_B.State = 1;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ValidationGate_m(void)
{
  /* During 'ValidationGate': '<S7>:1121' */
  if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
    /* Transition: '<S7>:955' */
    /* Exit 'ValidationGate': '<S7>:1121' */
    /* Entry 'ChooseState': '<S7>:1134' */
    brain_DWork.is_Autonomous = brain_IN_ChooseState;
    brain_DWork.was_Autonomous = brain_IN_ChooseState;
    brain_DWork.Done = 0.0;
  } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
    /* Transition: '<S7>:947' */
    /* Exit 'ValidationGate': '<S7>:1121' */
    /* Entry 'FollowOnePath1': '<S7>:1065' */
    brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
    brain_DWork.was_Autonomous = brain_IN_FollowOnePath1;
    brain_B.State = 3;

    /* Simulink Function 'Perform': '<S7>:1834' */
    brain_B.State1 = (real_T)brain_B.State;
    StateManagementRunningAutonomou(brain_B.State1,
      &brain_B.StateManagementRunningAutonom_j);
    brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
  } else {
    brain_DWork.OperationalState = 2;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_Autonomous(void)
{
  /* During 'Autonomous': '<S7>:945' */
  if ((int32_T)brain_U.RC == 1) {
    /* Transition: '<S7>:942' */
    /* Exit 'Breach': '<S7>:1744' */
    brain_DWork.is_Autonomous = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'Buoy': '<S7>:1025' */
    /* Exit 'ChooseState': '<S7>:1134' */
    /* Exit 'DropMechanism': '<S7>:1722' */
    /* Exit 'Finish': '<S7>:1064' */
    /* Exit 'FollowOnePath1': '<S7>:1065' */
    /* Exit 'FollowOnePath2': '<S7>:1142' */
    /* Exit 'FollowOnePath3': '<S7>:1718' */
    /* Exit 'FollowOnePath4': '<S7>:1732' */
    /* Exit 'Hedge1': '<S7>:1701' */
    /* Exit 'Hedge2': '<S7>:1735' */
    /* Exit 'LocatePinger': '<S7>:1739' */
    /* Exit 'Start': '<S7>:1019' */
    /* Exit 'ValidationGate': '<S7>:1121' */
    /* Exit 'Autonomous': '<S7>:945' */
    /* Entry 'ControlledRC': '<S7>:944' */
    brain_DWork.is_Running = brain_IN_ControlledRC_m;
  } else {
    switch (brain_DWork.is_Autonomous) {
     case brain_IN_Breach:
      /* During 'Breach': '<S7>:1744' */
      if ((brain_U.DesiredState != 0) && (brain_U.DesiredState != 12)) {
        /* Transition: '<S7>:1745' */
        /* Exit 'Breach': '<S7>:1744' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:949' */
        /* Exit 'Breach': '<S7>:1744' */
        /* Entry 'Finish': '<S7>:1064' */
        brain_DWork.is_Autonomous = brain_IN_Finish;
        brain_DWork.was_Autonomous = brain_IN_Finish;
        brain_B.State = 13;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 8;
      }
      break;

     case brain_IN_Buoy:
      /* During 'Buoy': '<S7>:1025' */
      if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:950' */
        /* Exit 'Buoy': '<S7>:1025' */
        /* Entry 'FollowOnePath2': '<S7>:1142' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath2;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath2;
        brain_B.State = 5;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if ((brain_U.DesiredState != 4) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:959' */
        /* Exit 'Buoy': '<S7>:1025' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else {
        brain_DWork.OperationalState = 4;
      }
      break;

     case brain_IN_ChooseState:
      /* During 'ChooseState': '<S7>:1134' */
      if ((brain_U.DesiredState == 1) || (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:960' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'Start': '<S7>:1019' */
        brain_DWork.is_Autonomous = brain_IN_Start_m;
        brain_DWork.was_Autonomous = brain_IN_Start_m;
        brain_B.State = 1;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 6) {
        /* Transition: '<S7>:1705' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'Hedge1': '<S7>:1701' */
        brain_DWork.is_Autonomous = brain_IN_Hedge1;
        brain_DWork.was_Autonomous = brain_IN_Hedge1;
        brain_B.State = 6;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 2) {
        /* Transition: '<S7>:954' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'ValidationGate': '<S7>:1121' */
        brain_DWork.is_Autonomous = brain_IN_ValidationGate_m;
        brain_DWork.was_Autonomous = brain_IN_ValidationGate_m;
        brain_B.State = 2;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 4) {
        /* Transition: '<S7>:958' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'Buoy': '<S7>:1025' */
        brain_DWork.is_Autonomous = brain_IN_Buoy;
        brain_DWork.was_Autonomous = brain_IN_Buoy;
        brain_B.State = 4;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 11) {
        /* Transition: '<S7>:1741' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'LocatePinger': '<S7>:1739' */
        brain_DWork.is_Autonomous = brain_IN_LocatePinger;
        brain_DWork.was_Autonomous = brain_IN_LocatePinger;
        brain_B.State = 11;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 3) {
        /* Transition: '<S7>:956' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'FollowOnePath1': '<S7>:1065' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath1;
        brain_B.State = 3;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 5) {
        /* Transition: '<S7>:952' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'FollowOnePath2': '<S7>:1142' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath2;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath2;
        brain_B.State = 5;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 7) {
        /* Transition: '<S7>:1721' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'FollowOnePath3': '<S7>:1718' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath3;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath3;
        brain_B.State = 7;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 8) {
        /* Transition: '<S7>:1725' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'DropMechanism': '<S7>:1722' */
        brain_DWork.is_Autonomous = brain_IN_DropMechanism;
        brain_DWork.was_Autonomous = brain_IN_DropMechanism;
        brain_B.State = 8;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 9) {
        /* Transition: '<S7>:1734' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'FollowOnePath4': '<S7>:1732' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath4;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath4;
        brain_B.State = 9;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if (brain_U.DesiredState == 10) {
        /* Transition: '<S7>:1737' */
        /* Exit 'ChooseState': '<S7>:1134' */
        /* Entry 'Hedge2': '<S7>:1735' */
        brain_DWork.is_Autonomous = brain_IN_Hedge2;
        brain_DWork.was_Autonomous = brain_IN_Hedge2;
        brain_B.State = 10;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        if (brain_U.DesiredState == 12) {
          /* Transition: '<S7>:1746' */
          /* Exit 'ChooseState': '<S7>:1134' */
          /* Entry 'Breach': '<S7>:1744' */
          brain_DWork.is_Autonomous = brain_IN_Breach;
          brain_DWork.was_Autonomous = brain_IN_Breach;
          brain_B.State = 12;

          /* Simulink Function 'Perform': '<S7>:1834' */
          brain_B.State1 = (real_T)brain_B.State;
          StateManagementRunningAutonomou(brain_B.State1,
            &brain_B.StateManagementRunningAutonom_j);
          brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
        }
      }
      break;

     case brain_IN_DropMechanism:
      /* During 'DropMechanism': '<S7>:1722' */
      if ((brain_U.DesiredState != 8) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:1724' */
        /* Exit 'DropMechanism': '<S7>:1722' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1743' */
        /* Exit 'DropMechanism': '<S7>:1722' */
        /* Entry 'FollowOnePath4': '<S7>:1732' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath4;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath4;
        brain_B.State = 9;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 6;
      }
      break;

     case brain_IN_Finish:
      /* During 'Finish': '<S7>:1064' */
      if (brain_U.DesiredState != 7) {
        /* Transition: '<S7>:962' */
        /* Exit 'Finish': '<S7>:1064' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else {
        brain_DWork.OperationalState = 9;
      }
      break;

     case brain_IN_FollowOnePath1:
      /* During 'FollowOnePath1': '<S7>:1065' */
      if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:951' */
        /* Exit 'FollowOnePath1': '<S7>:1065' */
        /* Entry 'Buoy': '<S7>:1025' */
        brain_DWork.is_Autonomous = brain_IN_Buoy;
        brain_DWork.was_Autonomous = brain_IN_Buoy;
        brain_B.State = 4;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if ((brain_U.DesiredState != 3) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:957' */
        /* Exit 'FollowOnePath1': '<S7>:1065' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else {
        brain_DWork.OperationalState = 3;
      }
      break;

     case brain_IN_FollowOnePath2:
      /* During 'FollowOnePath2': '<S7>:1142' */
      if ((brain_U.DesiredState != 5) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:953' */
        /* Exit 'FollowOnePath2': '<S7>:1142' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1702' */
        /* Exit 'FollowOnePath2': '<S7>:1142' */
        /* Entry 'Hedge1': '<S7>:1701' */
        brain_DWork.is_Autonomous = brain_IN_Hedge1;
        brain_DWork.was_Autonomous = brain_IN_Hedge1;
        brain_B.State = 6;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 3;
      }
      break;

     case brain_IN_FollowOnePath3:
      /* During 'FollowOnePath3': '<S7>:1718' */
      if ((brain_U.DesiredState != 7) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:1720' */
        /* Exit 'FollowOnePath3': '<S7>:1718' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1723' */
        /* Exit 'FollowOnePath3': '<S7>:1718' */
        /* Entry 'DropMechanism': '<S7>:1722' */
        brain_DWork.is_Autonomous = brain_IN_DropMechanism;
        brain_DWork.was_Autonomous = brain_IN_DropMechanism;
        brain_B.State = 8;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 3;
      }
      break;

     case brain_IN_FollowOnePath4:
      /* During 'FollowOnePath4': '<S7>:1732' */
      if ((brain_U.DesiredState != 0) && (brain_U.DesiredState != 9)) {
        /* Transition: '<S7>:1733' */
        /* Exit 'FollowOnePath4': '<S7>:1732' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1738' */
        /* Exit 'FollowOnePath4': '<S7>:1732' */
        /* Entry 'Hedge2': '<S7>:1735' */
        brain_DWork.is_Autonomous = brain_IN_Hedge2;
        brain_DWork.was_Autonomous = brain_IN_Hedge2;
        brain_B.State = 10;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 3;
      }
      break;

     case brain_IN_Hedge1:
      /* During 'Hedge1': '<S7>:1701' */
      if ((brain_U.DesiredState != 6) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:1704' */
        /* Exit 'Hedge1': '<S7>:1701' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1719' */
        /* Exit 'Hedge1': '<S7>:1701' */
        /* Entry 'FollowOnePath3': '<S7>:1718' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath3;
        brain_DWork.was_Autonomous = brain_IN_FollowOnePath3;
        brain_B.State = 7;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 5;
      }
      break;

     case brain_IN_Hedge2:
      /* During 'Hedge2': '<S7>:1735' */
      if ((brain_U.DesiredState != 0) && (brain_U.DesiredState != 10)) {
        /* Transition: '<S7>:1736' */
        /* Exit 'Hedge2': '<S7>:1735' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1742' */
        /* Exit 'Hedge2': '<S7>:1735' */
        /* Entry 'LocatePinger': '<S7>:1739' */
        brain_DWork.is_Autonomous = brain_IN_LocatePinger;
        brain_DWork.was_Autonomous = brain_IN_LocatePinger;
        brain_B.State = 11;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 5;
      }
      break;

     case brain_IN_LocatePinger:
      /* During 'LocatePinger': '<S7>:1739' */
      if ((brain_U.DesiredState != 0) && (brain_U.DesiredState != 11)) {
        /* Transition: '<S7>:1740' */
        /* Exit 'LocatePinger': '<S7>:1739' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1747' */
        /* Exit 'LocatePinger': '<S7>:1739' */
        /* Entry 'Breach': '<S7>:1744' */
        brain_DWork.is_Autonomous = brain_IN_Breach;
        brain_DWork.was_Autonomous = brain_IN_Breach;
        brain_B.State = 12;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 7;
      }
      break;

     case brain_IN_Start_m:
      /* During 'Start': '<S7>:1019' */
      if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:948' */
        /* Exit 'Start': '<S7>:1019' */
        /* Entry 'ValidationGate': '<S7>:1121' */
        brain_DWork.is_Autonomous = brain_IN_ValidationGate_m;
        brain_DWork.was_Autonomous = brain_IN_ValidationGate_m;
        brain_B.State = 2;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:961' */
        /* Exit 'Start': '<S7>:1019' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.was_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else {
        brain_DWork.OperationalState = 1;
      }
      break;

     case brain_IN_ValidationGate_m:
      brain_ValidationGate_m();
      break;

     default:
      brain_enter_internal_Autonomous();
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countareas(real_T sf_Size, real_T sf_count1)
{
  /* Embedded MATLAB Function 'countareas': '<S7>:1366' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  area is recognized by the recognition software */
  if (sf_Size > 16000.0) {
    /* '<S7>:1366:6' */
    /* '<S7>:1366:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S7>:1366:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_Turn45Degrees(real_T sf_CHeading, real_T sf_TurnD)
{
  real_T sf_DHeading;

  /* Embedded MATLAB Function 'Turn45Degrees': '<S7>:1333' */
  /*  This function changes the current heading by 45 degrees in the correct */
  /*  direction to see the next buoy */
  /* '<S7>:1333:5' */
  sf_DHeading = sf_TurnD * 45.0 + sf_CHeading;
  if (sf_DHeading > 360.0) {
    /* '<S7>:1333:7' */
    /* '<S7>:1333:8' */
    sf_DHeading -= 360.0;
  } else {
    if (sf_DHeading < 0.0) {
      /* '<S7>:1333:9' */
      /* '<S7>:1333:10' */
      sf_DHeading += 360.0;
    }
  }

  return sf_DHeading;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_FindSecondBuoy(void)
{
  int32_T i;
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  int32_T idxROI;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T in;
  uint32_T OutCode;
  uint8_T eml_i;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int8_T rtb_index;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW_c[10];
  uint32_T numBlobs;
  int32_T pixListMinc;
  int32_T pixListNinc;
  real_T ys;
  real_T uyy;
  real_T rtb_BlobPos[2];
  real_T rtb_BuoyBlobAnalysis_o1[20];
  real_T rtb_BuoyBlobAnalysis_o2[10];
  real_T rtb_BuoyBlobAnalysis_o3[10];
  int32_T i_0;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;

  /* During 'FindSecondBuoy': '<S7>:1317' */
  if (brain_DWork.Image == 1.0) {
    /* Transition: '<S7>:1315' */
    /* Exit 'FindSecondBuoy': '<S7>:1317' */
    /* Entry 'ApproachSecondBuoy': '<S7>:1316' */
    brain_DWork.is_ApproachBuoys = brain_IN_ApproachSecondBuoy;
    brain_B.Strafe = 0;
  } else {
    /* Simulink Function 'MaintainHeading': '<S7>:918' */
    brain_B.DesiredHeading1 = brain_B.DesiredHeading;
    brain_B.CurrentHeading1 = brain_U.CurrentHeading;
    brain_B.ForwardVelocity1 = 0.0;
    StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
      brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
      &brain_B.StateFlowFunctionsMaintainHea_d,
      &brain_DWork.StateFlowFunctionsMaintainHea_d);
    brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
    brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

    /* Simulink Function 'MaintainDepth': '<S7>:926' */
    brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
    brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
    brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
      brain_DWork.StateFlowFunctionsMaintainDep_k;
    brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

    /* Sum: '<S37>/Add' */
    rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

    /* SampleTimeMath: '<S132>/TSamp' incorporates:
     *  Gain: '<S131>/Depth Derivative Gain'
     *
     * About '<S132>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

    /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
     *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
     *  Gain: '<S131>/Depth Proportional Gain'
     *  Sum: '<S131>/Sum'
     *  Sum: '<S132>/Diff'
     *  UnitDelay: '<S132>/UD'
     *
     * Block description for '<S132>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S132>/UD':
     *
     *  Store in Global RAM
     */
    cc = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE)) +
      brain_DWork.DepthDiscreteTimeIntegrator_DST;
    cc = floor(cc);
    if (cc < 128.0) {
      if (cc >= -128.0) {
        brain_B.DoubleToInt8 = (int8_T)cc;
      } else {
        brain_B.DoubleToInt8 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToInt8 = MAX_int8_T;
    }

    /* Update for UnitDelay: '<S132>/UD'
     * Block description for '<S132>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE = rtb_TSamp;

    /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S131>/Depth Integral Gain'
     */
    brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki * rtb_Add)
      + brain_DWork.DepthDiscreteTimeIntegrator_DST;
    if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }

    brain_B.Vertical = brain_B.DoubleToInt8;

    /* Simulink Function 'GetStrafe': '<S7>:1331' */

    /* Constant: '<S12>/Constant' */
    brain_B.Constant_p = brain_P.Buoy_Strafe;
    brain_B.Strafe = (int8_T)brain_B.Constant_p;
    brain_B.Strafe = (int8_T)(brain_DWork.TurnDirection * (real_T)brain_B.Strafe);

    /* Simulink Function 'IterativeSegmentation': '<S7>:1483' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.H[i_0] = brain_B.Resize[i_0];
      brain_B.S[i_0] = brain_B.Resize1[i_0];
      brain_B.V[i_0] = brain_B.Resize2[i_0];
    }

    StateFlowFunctionsBuoysIterativ(brain_B.H, brain_B.S, brain_B.V,
      &brain_B.StateFlowFunctionsBuoysIterat_g,
      &brain_DWork.StateFlowFunctionsBuoysIterat_g);
    memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
           &brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0], 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
    memcpy((void *)&brain_DWork.ref_colors[0], (void *)
           &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U * sizeof
           (real_T));

    /* Simulink Function 'SecondBuoy': '<S7>:1318' */
    memcpy((void *)&brain_B.LabMatrix_b3[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.Ref_Colors_a[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.Num_Colors_b = brain_DWork.num_colors;
    brain_B.B_Hue_c = brain_DWork.BuoyHue;
    brain_B.B_Sat_k = brain_DWork.BuoySaturation;
    brain_B.B_Value_c = brain_DWork.BuoyValue;

    /* S-Function (svipcolorconv): '<S59>/Color Space  Conversion' */
    /* temporary variables for in-place operation */
    cc = 0.0;
    cc_0 = 0.0;
    cc_1 = 0.0;
    rtb_Add = 6.0 * brain_B.B_Hue_c;
    uyy = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-015);
    rtb_Add -= uyy;
    rtb_TSamp = 1.0 - brain_B.B_Sat_k;
    ys = 1.0 - brain_B.B_Sat_k * rtb_Add;
    rtb_Add = brain_B.B_Sat_k * rtb_Add + rtb_TSamp;
    if (uyy == 0.0) {
      cc = 1.0;
      cc_0 = rtb_Add;
      cc_1 = rtb_TSamp;
    } else if (uyy == 1.0) {
      cc = ys;
      cc_0 = 1.0;
      cc_1 = rtb_TSamp;
    } else if (uyy == 2.0) {
      cc = rtb_TSamp;
      cc_0 = 1.0;
      cc_1 = rtb_Add;
    } else if (uyy == 3.0) {
      cc = rtb_TSamp;
      cc_0 = ys;
      cc_1 = 1.0;
    } else if (uyy == 4.0) {
      cc = rtb_Add;
      cc_0 = rtb_TSamp;
      cc_1 = 1.0;
    } else {
      if (uyy == 5.0) {
        cc = 1.0;
        cc_0 = rtb_TSamp;
        cc_1 = ys;
      }
    }

    if (cc > cc_0) {
      rtb_Add = cc;
    } else {
      rtb_Add = cc_0;
    }

    if (!(rtb_Add > cc_1)) {
      rtb_Add = cc_1;
    }

    rtb_Add = brain_B.B_Value_c / rtb_Add;

    /* assign the results */
    brain_B.ColorSpaceConversion_o1 = rtb_Add * cc;
    brain_B.ColorSpaceConversion_o2 = rtb_Add * cc_0;
    brain_B.ColorSpaceConversion_o3 = rtb_Add * cc_1;

    /* S-Function (svipcolorconv): '<S59>/Color Space  Conversion1' */
    /* temporary variables for in-place operation */
    /* Convert to XYZ */
    /* temporary variables for in-place operation */
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (brain_B.ColorSpaceConversion_o1 <= 3.9286085583733095E-002) {
      rtb_Add = brain_B.ColorSpaceConversion_o1 / 1.2923054468333254E+001;
    } else {
      rtb_Add = (brain_B.ColorSpaceConversion_o1 + 5.5000519817226361E-002) /
        1.0550005198172263E+000;
      rtb_Add = rt_pow_snf(rtb_Add, 2.4);
    }

    if (brain_B.ColorSpaceConversion_o2 <= 3.9286085583733095E-002) {
      rtb_TSamp = brain_B.ColorSpaceConversion_o2 / 1.2923054468333254E+001;
    } else {
      rtb_TSamp = (brain_B.ColorSpaceConversion_o2 + 5.5000519817226361E-002) /
        1.0550005198172263E+000;
      rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
    }

    if (brain_B.ColorSpaceConversion_o3 <= 3.9286085583733095E-002) {
      uyy = brain_B.ColorSpaceConversion_o3 / 1.2923054468333254E+001;
    } else {
      uyy = (brain_B.ColorSpaceConversion_o3 + 5.5000519817226361E-002) /
        1.0550005198172263E+000;
      uyy = rt_pow_snf(uyy, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    ys = (4.1239079926596001E-001 * rtb_Add + 3.5758433938388001E-001 *
          rtb_TSamp) + 1.8048078840182999E-001 * uyy;
    cc = (2.1263900587151000E-001 * rtb_Add + 7.1516867876776002E-001 *
          rtb_TSamp) + 7.2192315360729994E-002 * uyy;
    rtb_Add = (1.9330818715590000E-002 * rtb_Add + 1.1919477979463000E-001 *
               rtb_TSamp) + 9.5053215224966003E-001 * uyy;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (ys > 1.0) {
      ys = 1.0;
    } else {
      if (ys < 0.0) {
        ys = 0.0;
      }
    }

    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (rtb_Add > 1.0) {
      rtb_Add = 1.0;
    } else {
      if (rtb_Add < 0.0) {
        rtb_Add = 0.0;
      }
    }

    /* assign the results */
    brain_B.ColorSpaceConversion1_o1_d = ys;
    brain_B.ColorSpaceConversion1_o2_k = cc;
    brain_B.ColorSpaceConversion1_o3_e = rtb_Add;

    /* Convert from XYZ to L*a*b* */
    rtb_Add = brain_B.ColorSpaceConversion1_o1_d / 9.6419865576090003E-001;
    uyy = brain_B.ColorSpaceConversion1_o3_e / 8.2511648322104003E-001;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (rtb_Add > 8.8564516790356311E-003) {
      ys = rt_pow_snf(rtb_Add, 3.3333333333333331E-001);
    } else {
      ys = 7.7870370370370372E+000 * rtb_Add + 1.3793103448275862E-001;
    }

    if (brain_B.ColorSpaceConversion1_o2_k > 8.8564516790356311E-003) {
      rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_k,
        3.3333333333333331E-001);
    } else {
      rtb_TSamp = 7.7870370370370372E+000 * brain_B.ColorSpaceConversion1_o2_k +
        1.3793103448275862E-001;
    }

    if (uyy > 8.8564516790356311E-003) {
      rtb_Add = rt_pow_snf(uyy, 3.3333333333333331E-001);
    } else {
      rtb_Add = 7.7870370370370372E+000 * uyy + 1.3793103448275862E-001;
    }

    /* assign the results */
    brain_B.ColorSpaceConversion1_o1_d = 116.0 * rtb_TSamp - 16.0;
    brain_B.ColorSpaceConversion1_o2_k = (ys - rtb_TSamp) * 500.0;
    brain_B.ColorSpaceConversion1_o3_e = (rtb_TSamp - rtb_Add) * 200.0;

    /* Embedded MATLAB: '<S57>/Choose Closest Color' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Choose Closest Color': '<S58>:1' */
    /*  This function chooses the appropriate color option from the reference colors */
    /*  and set of desired L,a,b values */
    /* '<S58>:1:5' */
    /* '<S58>:1:7' */
    rtb_Add = 1000.0;

    /* '<S58>:1:8' */
    cc = brain_B.Num_Colors_b + 1.0;
    cc = cc < 0.0 ? ceil(cc - 0.5) : floor(cc + 0.5);
    if (cc < 128.0) {
      if (cc >= -128.0) {
        rtb_index = (int8_T)cc;
      } else {
        rtb_index = MIN_int8_T;
      }
    } else {
      rtb_index = MAX_int8_T;
    }

    /* '<S58>:1:11' */
    for (rtb_TSamp = 1.0; rtb_TSamp <= brain_B.Num_Colors_b; rtb_TSamp++) {
      /* '<S58>:1:11' */
      /* '<S58>:1:12' */
      uyy = sqrt((rt_pow_snf(brain_B.ColorSpaceConversion1_o1_d -
        brain_B.Ref_Colors_a[(int32_T)rtb_TSamp - 1], 2.0) * 2.0 + rt_pow_snf
                  (brain_B.ColorSpaceConversion1_o2_k - brain_B.Ref_Colors_a
                   [(int32_T)rtb_TSamp + 49], 2.0)) + rt_pow_snf
                 (brain_B.ColorSpaceConversion1_o3_e - brain_B.Ref_Colors_a
                  [(int32_T)rtb_TSamp + 99], 2.0));
      if ((uyy < rtb_Add) && (uyy < 70.0)) {
        /* '<S58>:1:13' */
        /*  L: 0 - 100,a: -100 - 100 , b: -100 - 100 */
        /* '<S58>:1:14' */
        rtb_Add = uyy;

        /*  max min_dist = 346 if L dist is doubled */
        /* '<S58>:1:15' */
        cc = floor(rtb_TSamp + 0.5);
        if (cc < 128.0) {
          rtb_index = (int8_T)cc;
        } else {
          rtb_index = MAX_int8_T;
        }

        /*  max min_dist = 300 if L dist is not doubled */
      }
    }

    /* RelationalOperator: '<S57>/Relational Operator' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BW_fi[i_0] = (brain_B.LabMatrix_b3[i_0] == (real_T)rtb_index);
    }

    /* S-Function (svipblob): '<S13>/Buoy Blob Analysis' */
    maxNumBlobsReached = FALSE;
    for (i = 0; i < 123; i++) {
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[i] = 0U;
    }

    currentLabel = 1U;
    i = 0;
    idx = 123;
    for (n = 0; n < 160; n++) {
      for (in = 0; in < 120; in++) {
        brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = (uint8_T)(brain_B.BW_fi[i] ?
          255 : 0);
        i++;
        idx++;
      }

      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = 0U;
      idx++;
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = 0U;
      idx++;
    }

    for (i = 0; i < 121; i++) {
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[i + idx] = 0U;
    }

    n = 1;
    stackIdx = 0U;
    pixIdx = 0U;
    for (idx = 0; idx < 160; idx++) {
      in = 1;
      line_idx_4 = n * 122;
      for (pixListMinc = 0; pixListMinc < 120; pixListMinc++) {
        numBlobs = (uint32_T)(line_idx_4 + in);
        start_pixIdx = pixIdx;
        if (brain_DWork.BuoyBlobAnalysis_PAD_DW_h[numBlobs] == 255) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_h[numBlobs] = currentLabel;
          brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[pixIdx] = (int16_T)(n - 1);
          brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixIdx] = (int16_T)(in - 1);
          pixIdx++;
          BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] = 1U;
          brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx] = numBlobs;
          stackIdx++;
          while (stackIdx) {
            stackIdx--;
            numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx];
            for (pixListNinc = 0; pixListNinc < 8; pixListNinc++) {
              OutCode = numBlobs + (uint32_T)brain_ConstP.pooled27[pixListNinc];
              if (brain_DWork.BuoyBlobAnalysis_PAD_DW_h[OutCode] == 255) {
                brain_DWork.BuoyBlobAnalysis_PAD_DW_h[OutCode] = currentLabel;
                brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[pixIdx] = (int16_T)
                  ((int16_T)(OutCode / 122U) - 1);
                brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixIdx] = (int16_T)
                  (OutCode % 122U - 1U);
                pixIdx++;
                BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1]++;
                brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx] = OutCode;
                stackIdx++;
              }
            }
          }

          if ((BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] <
               brain_P.Min_Blob_Size) ||
              (BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] >
               brain_P.Max_Blob_Size)) {
            currentLabel--;
            pixIdx = start_pixIdx;
          }

          if (currentLabel == 10) {
            maxNumBlobsReached = TRUE;
            idx = 160;
            pixListMinc = 120;
          }

          if (pixListMinc < 120) {
            currentLabel++;
          }
        }

        in++;
      }

      n++;
    }

    numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
    currentLabel = (uint8_T)numBlobs;
    pixListMinc = 0;
    pixListNinc = 0;
    for (i_0 = 0; i_0 < (int32_T)numBlobs; i_0++) {
      i = 0;
      n = 0;
      for (line_idx_5 = 0; line_idx_5 < (int32_T)
           BuoyBlobAnalysis_NUM_PIX_DW_c[i_0]; line_idx_5++) {
        i += brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[line_idx_5 +
          pixListNinc];
        n += brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[line_idx_5 +
          pixListMinc];
      }

      rtb_BlobPos[0] = (real_T)n / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_BlobPos[1] = (real_T)i / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_BuoyBlobAnalysis_o1[i_0 << 1] = rtb_BlobPos[0];
      rtb_BuoyBlobAnalysis_o1[(i_0 << 1) + 1] = rtb_BlobPos[1];
      n = 160;
      idx = 120;
      in = 0;
      line_idx_4 = 0;
      for (line_idx_5 = 0; line_idx_5 < (int32_T)
           BuoyBlobAnalysis_NUM_PIX_DW_c[i_0]; line_idx_5++) {
        i = line_idx_5 + pixListNinc;
        if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[i] < n) {
          n = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[i];
        }

        if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[i] > in) {
          in = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[i];
        }

        i = line_idx_5 + pixListMinc;
        if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[i] < idx) {
          idx = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[i];
        }

        if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[i] > line_idx_4) {
          line_idx_4 = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[i];
        }
      }

      rtb_Add = 0.0;
      ys = 0.0;
      cc = 0.0;
      for (OutCode = 0U; OutCode < (uint32_T)(int32_T)
           BuoyBlobAnalysis_NUM_PIX_DW_c[i_0]; OutCode++) {
        rtb_TSamp = (real_T)
          brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[pixListNinc + OutCode] -
          rtb_BlobPos[1];
        uyy = (real_T)brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixListMinc +
          OutCode] - rtb_BlobPos[0];
        rtb_Add += rtb_TSamp * rtb_TSamp;
        ys += uyy * uyy;
        cc += rtb_TSamp * (-uyy);
      }

      cc_0 = rtb_Add / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] +
        8.3333333333333329E-002;
      uyy = ys / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] +
        8.3333333333333329E-002;
      rtb_Add = cc / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_Add = sqrt((cc_0 - uyy) * (cc_0 - uyy) + rtb_Add * rtb_Add * 4.0);
      rtb_TSamp = ((cc_0 + uyy) + rtb_Add) * 8.0;
      rtb_BuoyBlobAnalysis_o2[i_0] = sqrt(rtb_TSamp - ((cc_0 + uyy) - rtb_Add) *
        8.0) / sqrt(rtb_TSamp);
      rtb_BuoyBlobAnalysis_o3[i_0] = (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] /
        (real_T)(((line_idx_4 + 1) - idx) * ((in + 1) - n));
      pixListMinc += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      pixListNinc += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
    }

    for (i = (int32_T)numBlobs << 1; i < 20; i++) {
      rtb_BuoyBlobAnalysis_o1[i] = -1.0;
    }

    for (i = (int32_T)numBlobs; i < 10; i++) {
      rtb_BuoyBlobAnalysis_o2[i] = -1.0;
    }

    for (i = (int32_T)numBlobs; i < 10; i++) {
      rtb_BuoyBlobAnalysis_o3[i] = -1.0;
    }

    /* S-Function (svipscalenconvert): '<S13>/Image Data Type Conversion' */
    for (i = 0; i < 19200; i++) {
      brain_B.ImageDataTypeConversion[i] = brain_B.BW_fi[i] ? 1.0 : 0.0;
    }

    /* Embedded MATLAB: '<S13>/IF Buoy Conditions' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant3'
     *  Constant: '<S13>/Constant4'
     */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/IF Buoy Conditions': '<S56>:1' */
    /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
    /*  if there is a buoy present in the current image */
    /* '<S56>:1:5' */
    brain_B.Image_g = 0.0;

    /* '<S56>:1:7' */
    rtb_BlobPos[0] = 1.0;
    rtb_BlobPos[1] = 1.0;

    /* '<S56>:1:9' */
    for (eml_i = 1U; eml_i <= currentLabel; eml_i = (uint8_T)(uint32_T)(eml_i +
          1)) {
      /* '<S56>:1:9' */
      if ((rtb_BuoyBlobAnalysis_o2[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
          (rtb_BuoyBlobAnalysis_o2[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
          (rtb_BuoyBlobAnalysis_o3[eml_i - 1] > brain_P.Buoy_Min_Extent) &&
          (rtb_BuoyBlobAnalysis_o3[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
        /* '<S56>:1:10' */
        /* '<S56>:1:11' */
        brain_B.Image_g = 1.0;

        /* '<S56>:1:12' */
        rtb_BlobPos[0] = rtb_BuoyBlobAnalysis_o1[(eml_i - 1) << 1];

        /* '<S56>:1:13' */
        rtb_BlobPos[1] = rtb_BuoyBlobAnalysis_o1[((eml_i - 1) << 1) + 1];
      }
    }

    /* S-Function (svipdrawmarkers): '<S13>/Draw Markers' */
    /* Copy the image from input to output. */
    memcpy((void *)&brain_B.DrawMarkers[0], (void *)
           &brain_B.ImageDataTypeConversion[0], 19200U * sizeof(real_T));

    /* Draw all X marks. */
    for (idxROI = 0; idxROI < 2; idxROI += 2) {
      cc = rtb_BlobPos[idxROI];
      if ((rtb_BlobPos[idxROI] < 4.5035996273704960E+015) && (rtb_BlobPos[idxROI]
           > -4.5035996273704960E+015)) {
        cc = floor(rtb_BlobPos[idxROI] + 0.5);
      }

      pixListMinc = (int32_T)cc;
      cc = rtb_BlobPos[idxROI + 1];
      if ((cc < 4.5035996273704960E+015) && (cc > -4.5035996273704960E+015)) {
        cc = floor(cc + 0.5);
      }

      pixListNinc = (int32_T)cc;
      line_idx_2 = pixListMinc - 7;
      line_idx_1 = pixListNinc - 7;
      line_idx_0 = pixListMinc + 7;
      line_idx = pixListNinc + 7;
      maxNumBlobsReached = FALSE;

      /* Find the visible portion of a line. */
      visited = FALSE;
      visited_0 = FALSE;
      done = FALSE;
      i_0 = line_idx_2;
      line_idx_5 = line_idx_1;
      line_idx_4 = line_idx_0;
      line_idx_3 = line_idx;
      while (!done) {
        numBlobs = 0U;
        OutCode = 0U;

        /* Determine viewport violations. */
        if (i_0 < 0) {
          numBlobs = 4U;
        } else {
          if (i_0 > 119) {
            numBlobs = 8U;
          }
        }

        if (line_idx_4 < 0) {
          OutCode = 4U;
        } else {
          if (line_idx_4 > 119) {
            OutCode = 8U;
          }
        }

        if (line_idx_5 < 0) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 1);
        } else {
          if (line_idx_5 > 159) {
            numBlobs = (uint32_T)((int32_T)numBlobs | 2);
          }
        }

        if (line_idx_3 < 0) {
          OutCode = (uint32_T)((int32_T)OutCode | 1);
        } else {
          if (line_idx_3 > 159) {
            OutCode = (uint32_T)((int32_T)OutCode | 2);
          }
        }

        if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
          /* Line falls completely within bounds. */
          done = TRUE;
          maxNumBlobsReached = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
          /* Line falls completely out of bounds. */
          done = TRUE;
          maxNumBlobsReached = FALSE;
        } else if (numBlobs != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited) {
            i_0 = line_idx_2;
            line_idx_5 = line_idx_1;
          }

          i = line_idx_4 - i_0;
          n = line_idx_3 - line_idx_5;
          if ((uint32_T)((int32_T)numBlobs & 4)) {
            /* Violated RMin. */
            idx = (0 - i_0) * n;
            if (((idx >= 0) && (i >= 0)) || ((idx < 0) && (i < 0))) {
              line_idx_5 += (div_s32_floor(idx << 1U, i) + 1) >> 1;
            } else {
              line_idx_5 += -((div_s32_floor((-idx) << 1U, i) + 1) >> 1);
            }

            i_0 = 0;
            visited = TRUE;
          } else if ((uint32_T)((int32_T)numBlobs & 8)) {
            /* Violated RMax. */
            idx = (119 - i_0) * n;
            if (((idx >= 0) && (i >= 0)) || ((idx < 0) && (i < 0))) {
              line_idx_5 += (div_s32_floor(idx << 1U, i) + 1) >> 1;
            } else {
              line_idx_5 += -((div_s32_floor((-idx) << 1U, i) + 1) >> 1);
            }

            i_0 = 119;
            visited = TRUE;
          } else if ((uint32_T)((int32_T)numBlobs & 1)) {
            /* Violated CMin. */
            idx = (0 - line_idx_5) * i;
            if (((idx >= 0) && (n >= 0)) || ((idx < 0) && (n < 0))) {
              i_0 += (div_s32_floor(idx << 1U, n) + 1) >> 1;
            } else {
              i_0 += -((div_s32_floor((-idx) << 1U, n) + 1) >> 1);
            }

            line_idx_5 = 0;
            visited = TRUE;
          } else {
            /* Violated CMax. */
            idx = (159 - line_idx_5) * i;
            if (((idx >= 0) && (n >= 0)) || ((idx < 0) && (n < 0))) {
              i_0 += (div_s32_floor(idx << 1U, n) + 1) >> 1;
            } else {
              i_0 += -((div_s32_floor((-idx) << 1U, n) + 1) >> 1);
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

          i = line_idx_4 - i_0;
          n = line_idx_3 - line_idx_5;
          if ((uint32_T)((int32_T)OutCode & 4)) {
            /* Violated RMin. */
            idx = (0 - line_idx_4) * n;
            if (((idx >= 0) && (i >= 0)) || ((idx < 0) && (i < 0))) {
              line_idx_3 += (div_s32_floor(idx << 1U, i) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-idx) << 1U, i) + 1) >> 1);
            }

            line_idx_4 = 0;
            visited_0 = TRUE;
          } else if ((uint32_T)((int32_T)OutCode & 8)) {
            /* Violated RMax. */
            idx = (119 - line_idx_4) * n;
            if (((idx >= 0) && (i >= 0)) || ((idx < 0) && (i < 0))) {
              line_idx_3 += (div_s32_floor(idx << 1U, i) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-idx) << 1U, i) + 1) >> 1);
            }

            line_idx_4 = 119;
            visited_0 = TRUE;
          } else if ((uint32_T)((int32_T)OutCode & 1)) {
            /* Violated CMin. */
            idx = (0 - line_idx_3) * i;
            if (((idx >= 0) && (n >= 0)) || ((idx < 0) && (n < 0))) {
              line_idx_4 += (div_s32_floor(idx << 1U, n) + 1) >> 1;
            } else {
              line_idx_4 += -((div_s32_floor((-idx) << 1U, n) + 1) >> 1);
            }

            line_idx_3 = 0;
            visited_0 = TRUE;
          } else {
            /* Violated CMax. */
            idx = (159 - line_idx_3) * i;
            if (((idx >= 0) && (n >= 0)) || ((idx < 0) && (n < 0))) {
              line_idx_4 += (div_s32_floor(idx << 1U, n) + 1) >> 1;
            } else {
              line_idx_4 += -((div_s32_floor((-idx) << 1U, n) + 1) >> 1);
            }

            line_idx_3 = 159;
            visited_0 = TRUE;
          }
        }
      }

      if (maxNumBlobsReached) {
        n = line_idx_5 * 120 + i_0;
        for (idx = i_0; idx <= line_idx_4; idx++) {
          brain_B.DrawMarkers[n] = 0.75;
          n += 121;
        }
      }

      line_idx_2 = pixListMinc - 7;
      line_idx_1 = pixListNinc + 7;
      line_idx_0 = pixListMinc + 7;
      line_idx = pixListNinc - 7;
      maxNumBlobsReached = FALSE;

      /* Find the visible portion of a line. */
      visited = FALSE;
      visited_0 = FALSE;
      done = FALSE;
      i_0 = line_idx_2;
      line_idx_5 = line_idx_1;
      line_idx_4 = line_idx_0;
      line_idx_3 = line_idx;
      while (!done) {
        numBlobs = 0U;
        OutCode = 0U;

        /* Determine viewport violations. */
        if (i_0 < 0) {
          numBlobs = 4U;
        } else {
          if (i_0 > 119) {
            numBlobs = 8U;
          }
        }

        if (line_idx_4 < 0) {
          OutCode = 4U;
        } else {
          if (line_idx_4 > 119) {
            OutCode = 8U;
          }
        }

        if (line_idx_5 < 0) {
          numBlobs = (uint32_T)((int32_T)numBlobs | 1);
        } else {
          if (line_idx_5 > 159) {
            numBlobs = (uint32_T)((int32_T)numBlobs | 2);
          }
        }

        if (line_idx_3 < 0) {
          OutCode = (uint32_T)((int32_T)OutCode | 1);
        } else {
          if (line_idx_3 > 159) {
            OutCode = (uint32_T)((int32_T)OutCode | 2);
          }
        }

        if (!((uint32_T)((int32_T)numBlobs | (int32_T)OutCode))) {
          /* Line falls completely within bounds. */
          done = TRUE;
          maxNumBlobsReached = TRUE;
        } else if ((uint32_T)((int32_T)numBlobs & (int32_T)OutCode)) {
          /* Line falls completely out of bounds. */
          done = TRUE;
          maxNumBlobsReached = FALSE;
        } else if (numBlobs != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited) {
            i_0 = line_idx_2;
            line_idx_5 = line_idx_1;
          }

          i = line_idx_4 - i_0;
          n = line_idx_3 - line_idx_5;
          if ((uint32_T)((int32_T)numBlobs & 4)) {
            /* Violated RMin. */
            in = (0 - i_0) * n;
            if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
              line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
            } else {
              line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
            }

            i_0 = 0;
            visited = TRUE;
          } else if ((uint32_T)((int32_T)numBlobs & 8)) {
            /* Violated RMax. */
            in = (119 - i_0) * n;
            if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
              line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
            } else {
              line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
            }

            i_0 = 119;
            visited = TRUE;
          } else if ((uint32_T)((int32_T)numBlobs & 1)) {
            /* Violated CMin. */
            in = (0 - line_idx_5) * i;
            if (((in >= 0) && (n >= 0)) || ((in < 0) && (n < 0))) {
              i_0 += (div_s32_floor(in << 1U, n) + 1) >> 1;
            } else {
              i_0 += -((div_s32_floor((-in) << 1U, n) + 1) >> 1);
            }

            line_idx_5 = 0;
            visited = TRUE;
          } else {
            /* Violated CMax. */
            in = (159 - line_idx_5) * i;
            if (((in >= 0) && (n >= 0)) || ((in < 0) && (n < 0))) {
              i_0 += (div_s32_floor(in << 1U, n) + 1) >> 1;
            } else {
              i_0 += -((div_s32_floor((-in) << 1U, n) + 1) >> 1);
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

          i = line_idx_4 - i_0;
          n = line_idx_3 - line_idx_5;
          if ((uint32_T)((int32_T)OutCode & 4)) {
            /* Violated RMin. */
            in = (0 - line_idx_4) * n;
            if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
              line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
            }

            line_idx_4 = 0;
            visited_0 = TRUE;
          } else if ((uint32_T)((int32_T)OutCode & 8)) {
            /* Violated RMax. */
            in = (119 - line_idx_4) * n;
            if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
              line_idx_3 += (div_s32_floor(in << 1U, i) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
            }

            line_idx_4 = 119;
            visited_0 = TRUE;
          } else if ((uint32_T)((int32_T)OutCode & 1)) {
            /* Violated CMin. */
            in = (0 - line_idx_3) * i;
            if (((in >= 0) && (n >= 0)) || ((in < 0) && (n < 0))) {
              line_idx_4 += (div_s32_floor(in << 1U, n) + 1) >> 1;
            } else {
              line_idx_4 += -((div_s32_floor((-in) << 1U, n) + 1) >> 1);
            }

            line_idx_3 = 0;
            visited_0 = TRUE;
          } else {
            /* Violated CMax. */
            in = (159 - line_idx_3) * i;
            if (((in >= 0) && (n >= 0)) || ((in < 0) && (n < 0))) {
              line_idx_4 += (div_s32_floor(in << 1U, n) + 1) >> 1;
            } else {
              line_idx_4 += -((div_s32_floor((-in) << 1U, n) + 1) >> 1);
            }

            line_idx_3 = 159;
            visited_0 = TRUE;
          }
        }
      }

      if (maxNumBlobsReached) {
        n = line_idx_5 * 120 + i_0;
        for (in = i_0; in <= line_idx_4; in++) {
          brain_B.DrawMarkers[n] = 0.75;
          n += -119;
        }
      }
    }

    brain_DWork.Image = brain_B.Image_g;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BWout[i_0] = brain_B.DrawMarkers[i_0];
      brain_B.LabMatrix_d[i_0] = brain_DWork.LabelMatrix[i_0];
    }

    memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d, brain_B.Ref_Colors_b,
      &brain_B.StateFlowFunctionsBuoysShowSe_o);
    memcpy((void *)&brain_B.RGBout[0], (void *)
           &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
           (real_T));
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ApproachBuoys(void)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T eml_min_dist;
  real_T eml_min_dist_0;
  real_T eml_FirstD[50];
  real_T eml_SecondD[50];
  real_T eml_count;
  real_T eml_b_i;
  int32_T i;

  /* During 'ApproachBuoys': '<S7>:1312' */
  if ((brain_DWork.count2ndarea > 2.0) || (brain_DWork.TurnDirection <= -999.0))
  {
    /* Transition: '<S7>:1455' */
    switch (brain_DWork.is_ApproachBuoys) {
     case brain_IN_ApproachFirstBuoy:
      /* Exit 'ApproachFirstBuoy': '<S7>:1341' */
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     case brain_IN_FindSecondBuoy:
      /* Exit 'FindSecondBuoy': '<S7>:1317' */
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     default:
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'ApproachSecondBuoy': '<S7>:1316' */
      break;
    }

    /* Exit 'ApproachBuoys': '<S7>:1312' */
    /* Entry 'BuoyDone': '<S7>:1453' */
    brain_DWork.is_Buoys = brain_IN_BuoyDone;
    brain_DWork.Done = 1.0;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Strafe = 0;
  } else {
    switch (brain_DWork.is_ApproachBuoys) {
     case brain_IN_ApproachFirstBuoy:
      /* During 'ApproachFirstBuoy': '<S7>:1341' */
      if (brain_DWork.countarea > 2.0) {
        /* Transition: '<S7>:1314' */
        /* Exit 'ApproachFirstBuoy': '<S7>:1341' */
        /* Entry 'FindSecondBuoy': '<S7>:1317' */
        brain_DWork.is_ApproachBuoys = brain_IN_FindSecondBuoy;
        brain_DWork.TurnDirection = -1.0;
        brain_B.DesiredHeading = brain_Turn45Degrees(brain_U.CurrentHeading,
          brain_DWork.TurnDirection);
        brain_B.DesiredDepth = brain_U.CurrentDepth;

        /* Simulink Function 'GetSecondBuoyStats': '<S7>:1327' */
        StateFlowFunctionsBuoysApproa_h(&brain_B.StateFlowFunctionsBuoysAppro_hj);
        brain_DWork.BuoyHue = brain_B.StateFlowFunctionsBuoysAppro_hj.Constant;
        brain_DWork.BuoySaturation =
          brain_B.StateFlowFunctionsBuoysAppro_hj.Constant2;
        brain_DWork.BuoyValue =
          brain_B.StateFlowFunctionsBuoysAppro_hj.Constant1;
        brain_DWork.Image = 0.0;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1483' */
        for (i = 0; i < 19200; i++) {
          brain_B.H[i] = brain_B.Resize[i];
          brain_B.S[i] = brain_B.Resize1[i];
          brain_B.V[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H, brain_B.S, brain_B.V,
          &brain_B.StateFlowFunctionsBuoysIterat_g,
          &brain_DWork.StateFlowFunctionsBuoysIterat_g);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'Buoy': '<S7>:1495' */
        memcpy((void *)&brain_B.LabMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
               19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors[0], (void *)&brain_DWork.ref_colors[0],
               150U * sizeof(real_T));
        brain_B.Num_Colors = brain_DWork.num_colors;
        brain_B.B_Hue = brain_DWork.BuoyHue;
        brain_B.B_Sat = brain_DWork.BuoySaturation;
        brain_B.B_Value = brain_DWork.BuoyValue;
        StateFlowFunctionsBuoysApproach(brain_B.B_Hue, brain_B.B_Sat,
          brain_B.B_Value, brain_B.LabMatrix, brain_B.Ref_Colors,
          brain_B.Num_Colors, brain_M, &brain_B.StateFlowFunctionsBuoysApproa_l,
          &brain_DWork.StateFlowFunctionsBuoysApproa_l);
        brain_DWork.Area = (int32_T)
          brain_B.StateFlowFunctionsBuoysApproa_l.BlobArea;
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsBuoysApproa_l.Add;
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsBuoysApproa_l.Add1;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsBuoysApproa_l.DataTypeConversion;
        brain_B.BuoyCentroidX =
          brain_B.StateFlowFunctionsBuoysApproa_l.BlobCentroidY;
        brain_B.BuoyCentroidY =
          brain_B.StateFlowFunctionsBuoysApproa_l.BlobCentroidX;
        brain_DWork.countarea = brain_countareas((real_T)brain_DWork.Area,
          brain_DWork.countarea);

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] =
            brain_B.StateFlowFunctionsBuoysApproa_l.DrawMarkers[i];
          brain_B.LabMatrix_d[i] = brain_DWork.LabelMatrix[i];
        }

        memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d,
          brain_B.Ref_Colors_b, &brain_B.StateFlowFunctionsBuoysShowSe_o);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
               (real_T));
      }
      break;

     case brain_IN_ApproachSecondBuoy:
      /* During 'ApproachSecondBuoy': '<S7>:1316' */
      /* Simulink Function 'IterativeSegmentation': '<S7>:1483' */
      for (i = 0; i < 19200; i++) {
        brain_B.H[i] = brain_B.Resize[i];
        brain_B.S[i] = brain_B.Resize1[i];
        brain_B.V[i] = brain_B.Resize2[i];
      }

      StateFlowFunctionsBuoysIterativ(brain_B.H, brain_B.S, brain_B.V,
        &brain_B.StateFlowFunctionsBuoysIterat_g,
        &brain_DWork.StateFlowFunctionsBuoysIterat_g);
      memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
             &brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0], 19200U *
             sizeof(real_T));
      brain_DWork.num_colors =
        brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
      memcpy((void *)&brain_DWork.ref_colors[0], (void *)
             &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U *
             sizeof(real_T));

      /* Simulink Function 'Buoy': '<S7>:1495' */
      memcpy((void *)&brain_B.LabMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
             19200U * sizeof(real_T));
      memcpy((void *)&brain_B.Ref_Colors[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      brain_B.Num_Colors = brain_DWork.num_colors;
      brain_B.B_Hue = brain_DWork.BuoyHue;
      brain_B.B_Sat = brain_DWork.BuoySaturation;
      brain_B.B_Value = brain_DWork.BuoyValue;
      StateFlowFunctionsBuoysApproach(brain_B.B_Hue, brain_B.B_Sat,
        brain_B.B_Value, brain_B.LabMatrix, brain_B.Ref_Colors,
        brain_B.Num_Colors, brain_M, &brain_B.StateFlowFunctionsBuoysApproa_l,
        &brain_DWork.StateFlowFunctionsBuoysApproa_l);
      brain_DWork.Area = (int32_T)
        brain_B.StateFlowFunctionsBuoysApproa_l.BlobArea;
      brain_B.Right = (int8_T)brain_B.StateFlowFunctionsBuoysApproa_l.Add;
      brain_B.Left = (int8_T)brain_B.StateFlowFunctionsBuoysApproa_l.Add1;
      brain_B.Vertical =
        brain_B.StateFlowFunctionsBuoysApproa_l.DataTypeConversion;
      brain_B.BuoyCentroidX =
        brain_B.StateFlowFunctionsBuoysApproa_l.BlobCentroidY;
      brain_B.BuoyCentroidY =
        brain_B.StateFlowFunctionsBuoysApproa_l.BlobCentroidX;
      brain_DWork.count2ndarea = brain_countareas((real_T)brain_DWork.Area,
        brain_DWork.count2ndarea);

      /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = brain_B.StateFlowFunctionsBuoysApproa_l.DrawMarkers[i];
        brain_B.LabMatrix_d[i] = brain_DWork.LabelMatrix[i];
      }

      memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d, brain_B.Ref_Colors_b,
        &brain_B.StateFlowFunctionsBuoysShowSe_o);
      memcpy((void *)&brain_B.RGBout[0], (void *)
             &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
             (real_T));
      break;

     case brain_IN_FindSecondBuoy:
      brain_FindSecondBuoy();
      break;

     default:
      /* Transition: '<S7>:1313' */
      /* Entry 'ApproachFirstBuoy': '<S7>:1341' */
      brain_DWork.is_ApproachBuoys = brain_IN_ApproachFirstBuoy;

      /* Simulink Function 'GetFirstBuoyStats': '<S7>:1342' */

      /* Constant: '<S8>/Constant' */
      brain_B.Constant_k = brain_P.Buoy1_Hue;

      /* Constant: '<S8>/Constant2' */
      brain_B.Constant2 = brain_P.Buoy1_Saturation;

      /* Constant: '<S8>/Constant1' */
      brain_B.Constant1 = brain_P.Buoy1_Value;
      brain_DWork.BuoyHue = brain_B.Constant_k;
      brain_DWork.BuoySaturation = brain_B.Constant2;
      brain_DWork.BuoyValue = brain_B.Constant1;

      /* Simulink Function 'WhichBuoysToApproach': '<S7>:1514' */
      memcpy((void *)&brain_B.buoys[0], (void *)&brain_DWork.BuoyBlobs[0], 200U *
             sizeof(real_T));
      brain_B.num_blobs = brain_DWork.num_blobs;

      /* S-Function (svipcolorconv): '<S42>/Color Space  Conversion' incorporates:
       *  Constant: '<S42>/Constant'
       *  Constant: '<S42>/Constant1'
       *  Constant: '<S42>/Constant2'
       */
      /* temporary variables for in-place operation */
      cc = 0.0;
      cc_0 = 0.0;
      cc_1 = 0.0;
      eml_b_i = 6.0 * brain_P.Buoy1_Hue;
      eml_min_dist_0 = (real_T)(uint32_T)(eml_b_i - 1.3322676295501878E-015);
      eml_b_i -= eml_min_dist_0;
      eml_count = 1.0 - brain_P.Buoy1_Saturation;
      eml_min_dist = 1.0 - brain_P.Buoy1_Saturation * eml_b_i;
      eml_b_i = brain_P.Buoy1_Saturation * eml_b_i + eml_count;
      if (eml_min_dist_0 == 0.0) {
        cc = 1.0;
        cc_0 = eml_b_i;
        cc_1 = eml_count;
      } else if (eml_min_dist_0 == 1.0) {
        cc = eml_min_dist;
        cc_0 = 1.0;
        cc_1 = eml_count;
      } else if (eml_min_dist_0 == 2.0) {
        cc = eml_count;
        cc_0 = 1.0;
        cc_1 = eml_b_i;
      } else if (eml_min_dist_0 == 3.0) {
        cc = eml_count;
        cc_0 = eml_min_dist;
        cc_1 = 1.0;
      } else if (eml_min_dist_0 == 4.0) {
        cc = eml_b_i;
        cc_0 = eml_count;
        cc_1 = 1.0;
      } else {
        if (eml_min_dist_0 == 5.0) {
          cc = 1.0;
          cc_0 = eml_count;
          cc_1 = eml_min_dist;
        }
      }

      if (cc > cc_0) {
        eml_b_i = cc;
      } else {
        eml_b_i = cc_0;
      }

      if (!(eml_b_i > cc_1)) {
        eml_b_i = cc_1;
      }

      eml_b_i = brain_P.Buoy1_Value / eml_b_i;

      /* assign the results */
      brain_B.ColorSpaceConversion_o3_c = eml_b_i * cc;
      brain_B.ColorSpaceConversion_o2_o = eml_b_i * cc_0;
      brain_B.ColorSpaceConversion_o1_g = eml_b_i * cc_1;

      /* S-Function (svipcolorconv): '<S42>/Color Space  Conversion1' */
      /* temporary variables for in-place operation */
      /* Convert to XYZ */
      /* temporary variables for in-place operation */
      /* First, linearize (de-gamma) the RGB values; the operation is */
      /* equivalent to running the gamma correction block with break */
      /* point of 0.00304 and gamma of 2.4; it's built into this */
      /* conversion for convenience */
      if (brain_B.ColorSpaceConversion_o3_c <= 3.9286085583733095E-002) {
        eml_b_i = brain_B.ColorSpaceConversion_o3_c / 1.2923054468333254E+001;
      } else {
        eml_b_i = (brain_B.ColorSpaceConversion_o3_c + 5.5000519817226361E-002) /
          1.0550005198172263E+000;
        eml_b_i = rt_pow_snf(eml_b_i, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o2_o <= 3.9286085583733095E-002) {
        eml_min_dist = brain_B.ColorSpaceConversion_o2_o /
          1.2923054468333254E+001;
      } else {
        eml_min_dist = (brain_B.ColorSpaceConversion_o2_o +
                        5.5000519817226361E-002) / 1.0550005198172263E+000;
        eml_min_dist = rt_pow_snf(eml_min_dist, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o1_g <= 3.9286085583733095E-002) {
        cc = brain_B.ColorSpaceConversion_o1_g / 1.2923054468333254E+001;
      } else {
        cc = (brain_B.ColorSpaceConversion_o1_g + 5.5000519817226361E-002) /
          1.0550005198172263E+000;
        cc = rt_pow_snf(cc, 2.4);
      }

      /* The coefficients for this conversion were derived from ITU-R */
      /* BT.709 reference primaries for sRGB and CIE standard illuminant */
      /* D65, 2 degree observer */
      eml_min_dist_0 = (4.1239079926596001E-001 * eml_b_i +
                        3.5758433938388001E-001 * eml_min_dist) +
        1.8048078840182999E-001 * cc;
      eml_count = (2.1263900587151000E-001 * eml_b_i + 7.1516867876776002E-001 *
                   eml_min_dist) + 7.2192315360729994E-002 * cc;
      eml_b_i = (1.9330818715590000E-002 * eml_b_i + 1.1919477979463000E-001 *
                 eml_min_dist) + 9.5053215224966003E-001 * cc;

      /* Make sure that the output is in [0..1] range; clip if necessary */
      if (eml_min_dist_0 > 1.0) {
        eml_min_dist_0 = 1.0;
      } else {
        if (eml_min_dist_0 < 0.0) {
          eml_min_dist_0 = 0.0;
        }
      }

      if (eml_count > 1.0) {
        eml_count = 1.0;
      } else {
        if (eml_count < 0.0) {
          eml_count = 0.0;
        }
      }

      if (eml_b_i > 1.0) {
        eml_b_i = 1.0;
      } else {
        if (eml_b_i < 0.0) {
          eml_b_i = 0.0;
        }
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1 = eml_min_dist_0;
      brain_B.ColorSpaceConversion1_o2 = eml_count;
      brain_B.ColorSpaceConversion1_o3 = eml_b_i;

      /* Convert from XYZ to L*a*b* */
      eml_b_i = brain_B.ColorSpaceConversion1_o1 / 9.6419865576090003E-001;
      cc = brain_B.ColorSpaceConversion1_o3 / 8.2511648322104003E-001;

      /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
      if (eml_b_i > 8.8564516790356311E-003) {
        eml_min_dist_0 = rt_pow_snf(eml_b_i, 3.3333333333333331E-001);
      } else {
        eml_min_dist_0 = 7.7870370370370372E+000 * eml_b_i +
          1.3793103448275862E-001;
      }

      if (brain_B.ColorSpaceConversion1_o2 > 8.8564516790356311E-003) {
        eml_min_dist = rt_pow_snf(brain_B.ColorSpaceConversion1_o2,
          3.3333333333333331E-001);
      } else {
        eml_min_dist = 7.7870370370370372E+000 *
          brain_B.ColorSpaceConversion1_o2 + 1.3793103448275862E-001;
      }

      if (cc > 8.8564516790356311E-003) {
        eml_b_i = rt_pow_snf(cc, 3.3333333333333331E-001);
      } else {
        eml_b_i = 7.7870370370370372E+000 * cc + 1.3793103448275862E-001;
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1 = 116.0 * eml_min_dist - 16.0;
      brain_B.ColorSpaceConversion1_o2 = (eml_min_dist_0 - eml_min_dist) * 500.0;
      brain_B.ColorSpaceConversion1_o3 = (eml_min_dist - eml_b_i) * 200.0;

      /* S-Function (svipcolorconv): '<S44>/Color Space  Conversion' incorporates:
       *  Constant: '<S44>/Constant'
       *  Constant: '<S44>/Constant1'
       *  Constant: '<S44>/Constant2'
       */
      /* temporary variables for in-place operation */
      cc = 0.0;
      cc_0 = 0.0;
      cc_1 = 0.0;
      eml_b_i = 6.0 * brain_P.Buoy2_Hue;
      eml_min_dist_0 = (real_T)(uint32_T)(eml_b_i - 1.3322676295501878E-015);
      eml_b_i -= eml_min_dist_0;
      eml_count = 1.0 - brain_P.Buoy2_Saturation;
      eml_min_dist = 1.0 - brain_P.Buoy2_Saturation * eml_b_i;
      eml_b_i = brain_P.Buoy2_Saturation * eml_b_i + eml_count;
      if (eml_min_dist_0 == 0.0) {
        cc = 1.0;
        cc_0 = eml_b_i;
        cc_1 = eml_count;
      } else if (eml_min_dist_0 == 1.0) {
        cc = eml_min_dist;
        cc_0 = 1.0;
        cc_1 = eml_count;
      } else if (eml_min_dist_0 == 2.0) {
        cc = eml_count;
        cc_0 = 1.0;
        cc_1 = eml_b_i;
      } else if (eml_min_dist_0 == 3.0) {
        cc = eml_count;
        cc_0 = eml_min_dist;
        cc_1 = 1.0;
      } else if (eml_min_dist_0 == 4.0) {
        cc = eml_b_i;
        cc_0 = eml_count;
        cc_1 = 1.0;
      } else {
        if (eml_min_dist_0 == 5.0) {
          cc = 1.0;
          cc_0 = eml_count;
          cc_1 = eml_min_dist;
        }
      }

      if (cc > cc_0) {
        eml_b_i = cc;
      } else {
        eml_b_i = cc_0;
      }

      if (!(eml_b_i > cc_1)) {
        eml_b_i = cc_1;
      }

      eml_b_i = brain_P.Buoy2_Value / eml_b_i;

      /* assign the results */
      brain_B.ColorSpaceConversion_o1_g = eml_b_i * cc;
      brain_B.ColorSpaceConversion_o2_o = eml_b_i * cc_0;
      brain_B.ColorSpaceConversion_o3_c = eml_b_i * cc_1;

      /* S-Function (svipcolorconv): '<S44>/Color Space  Conversion1' */
      /* temporary variables for in-place operation */
      /* Convert to XYZ */
      /* temporary variables for in-place operation */
      /* First, linearize (de-gamma) the RGB values; the operation is */
      /* equivalent to running the gamma correction block with break */
      /* point of 0.00304 and gamma of 2.4; it's built into this */
      /* conversion for convenience */
      if (brain_B.ColorSpaceConversion_o1_g <= 3.9286085583733095E-002) {
        eml_b_i = brain_B.ColorSpaceConversion_o1_g / 1.2923054468333254E+001;
      } else {
        eml_b_i = (brain_B.ColorSpaceConversion_o1_g + 5.5000519817226361E-002) /
          1.0550005198172263E+000;
        eml_b_i = rt_pow_snf(eml_b_i, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o2_o <= 3.9286085583733095E-002) {
        eml_min_dist = brain_B.ColorSpaceConversion_o2_o /
          1.2923054468333254E+001;
      } else {
        eml_min_dist = (brain_B.ColorSpaceConversion_o2_o +
                        5.5000519817226361E-002) / 1.0550005198172263E+000;
        eml_min_dist = rt_pow_snf(eml_min_dist, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o3_c <= 3.9286085583733095E-002) {
        cc = brain_B.ColorSpaceConversion_o3_c / 1.2923054468333254E+001;
      } else {
        cc = (brain_B.ColorSpaceConversion_o3_c + 5.5000519817226361E-002) /
          1.0550005198172263E+000;
        cc = rt_pow_snf(cc, 2.4);
      }

      /* The coefficients for this conversion were derived from ITU-R */
      /* BT.709 reference primaries for sRGB and CIE standard illuminant */
      /* D65, 2 degree observer */
      eml_min_dist_0 = (4.1239079926596001E-001 * eml_b_i +
                        3.5758433938388001E-001 * eml_min_dist) +
        1.8048078840182999E-001 * cc;
      eml_count = (2.1263900587151000E-001 * eml_b_i + 7.1516867876776002E-001 *
                   eml_min_dist) + 7.2192315360729994E-002 * cc;
      eml_b_i = (1.9330818715590000E-002 * eml_b_i + 1.1919477979463000E-001 *
                 eml_min_dist) + 9.5053215224966003E-001 * cc;

      /* Make sure that the output is in [0..1] range; clip if necessary */
      if (eml_min_dist_0 > 1.0) {
        eml_min_dist_0 = 1.0;
      } else {
        if (eml_min_dist_0 < 0.0) {
          eml_min_dist_0 = 0.0;
        }
      }

      if (eml_count > 1.0) {
        eml_count = 1.0;
      } else {
        if (eml_count < 0.0) {
          eml_count = 0.0;
        }
      }

      if (eml_b_i > 1.0) {
        eml_b_i = 1.0;
      } else {
        if (eml_b_i < 0.0) {
          eml_b_i = 0.0;
        }
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1_n = eml_min_dist_0;
      brain_B.ColorSpaceConversion1_o2_i = eml_count;
      brain_B.ColorSpaceConversion1_o3_m = eml_b_i;

      /* Convert from XYZ to L*a*b* */
      eml_b_i = brain_B.ColorSpaceConversion1_o1_n / 9.6419865576090003E-001;
      cc = brain_B.ColorSpaceConversion1_o3_m / 8.2511648322104003E-001;

      /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
      if (eml_b_i > 8.8564516790356311E-003) {
        eml_min_dist_0 = rt_pow_snf(eml_b_i, 3.3333333333333331E-001);
      } else {
        eml_min_dist_0 = 7.7870370370370372E+000 * eml_b_i +
          1.3793103448275862E-001;
      }

      if (brain_B.ColorSpaceConversion1_o2_i > 8.8564516790356311E-003) {
        eml_min_dist = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_i,
          3.3333333333333331E-001);
      } else {
        eml_min_dist = 7.7870370370370372E+000 *
          brain_B.ColorSpaceConversion1_o2_i + 1.3793103448275862E-001;
      }

      if (cc > 8.8564516790356311E-003) {
        eml_b_i = rt_pow_snf(cc, 3.3333333333333331E-001);
      } else {
        eml_b_i = 7.7870370370370372E+000 * cc + 1.3793103448275862E-001;
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1_n = 116.0 * eml_min_dist - 16.0;
      brain_B.ColorSpaceConversion1_o2_i = (eml_min_dist_0 - eml_min_dist) *
        500.0;
      brain_B.ColorSpaceConversion1_o3_m = (eml_min_dist - eml_b_i) * 200.0;

      /* Embedded MATLAB: '<S9>/GetBestColorMatch' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch': '<S43>:1' */
      /*  This function determines which buoys are the best match for the desired colors */
      /*  Buoys = zeros(3,3); */
      /*  Buoys = [L;M;R]; */
      /* '<S43>:1:6' */
      eml_min_dist = 1000.0;

      /* '<S43>:1:7' */
      eml_min_dist_0 = 1000.0;

      /* '<S43>:1:8' */
      /* '<S43>:1:9' */
      for (i = 0; i < 50; i++) {
        eml_FirstD[i] = 2.0;
        eml_SecondD[i] = 2.0;
      }

      /* '<S43>:1:11' */
      eml_count = 0.0;

      /* '<S43>:1:12' */
      cc_0 = 0.0;

      /* '<S43>:1:14' */
      for (cc = 1.0; cc <= brain_B.num_blobs; cc++) {
        /* '<S43>:1:14' */
        /* '<S43>:1:15' */
        eml_b_i = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)cc - 1] -
          brain_B.ColorSpaceConversion1_o1, 2.0) + rt_pow_snf(brain_B.buoys
          [(int32_T)cc + 49] - brain_B.ColorSpaceConversion1_o2, 2.0)) +
                       rt_pow_snf(brain_B.buoys[(int32_T)cc + 99] -
          brain_B.ColorSpaceConversion1_o3, 2.0));
        if (eml_b_i <= eml_min_dist) {
          /* '<S43>:1:16' */
          /* '<S43>:1:17' */
          eml_count++;

          /* '<S43>:1:18' */
          eml_min_dist = eml_b_i;

          /* '<S43>:1:19' */
          eml_FirstD[(int32_T)eml_count - 1] = cc;
        }

        /* '<S43>:1:21' */
        eml_b_i = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)cc - 1] -
          brain_B.ColorSpaceConversion1_o1_n, 2.0) + rt_pow_snf(brain_B.buoys
          [(int32_T)cc + 49] - brain_B.ColorSpaceConversion1_o2_i, 2.0)) +
                       rt_pow_snf(brain_B.buoys[(int32_T)cc + 99] -
          brain_B.ColorSpaceConversion1_o3_m, 2.0));
        if (eml_b_i < eml_min_dist_0) {
          /* '<S43>:1:22' */
          /* '<S43>:1:23' */
          cc_0++;

          /* '<S43>:1:24' */
          eml_min_dist_0 = eml_b_i;

          /* '<S43>:1:25' */
          eml_SecondD[(int32_T)cc_0 - 1] = cc;
        }
      }

      /* '<S43>:1:29' */
      cc = 2.0;

      /* '<S43>:1:30' */
      /* '<S43>:1:31' */
      for (eml_b_i = 1.0; eml_b_i <= eml_count; eml_b_i++) {
        /* '<S43>:1:31' */
        /* '<S43>:1:32' */
        if (brain_B.buoys[(int32_T)eml_FirstD[(int32_T)eml_b_i - 1] + 149] > 0.0)
        {
          /* '<S43>:1:33' */
          /* '<S43>:1:34' */
          cc = eml_FirstD[(int32_T)eml_b_i - 1];
        }
      }

      /* '<S43>:1:39' */
      eml_b_i = 2.0;

      /* '<S43>:1:40' */
      /* '<S43>:1:41' */
      for (eml_min_dist = 1.0; eml_min_dist <= cc_0; eml_min_dist++) {
        /* '<S43>:1:41' */
        /* '<S43>:1:42' */
        if (brain_B.buoys[(int32_T)eml_SecondD[(int32_T)eml_min_dist - 1] + 149]
            > 0.0) {
          /* '<S43>:1:43' */
          /* '<S43>:1:44' */
          eml_b_i = eml_SecondD[(int32_T)eml_min_dist - 1];
        }
      }

      if (cc > eml_b_i) {
        /* '<S43>:1:49' */
        /* '<S43>:1:50' */
        brain_B.Direction1 = 1.0;

        /* '<S43>:1:51' */
        brain_B.Direction2 = 3.0;
      } else if (cc == eml_b_i) {
        /* '<S43>:1:52' */
        /* '<S43>:1:53' */
        brain_B.Direction1 = 2.0;

        /* '<S43>:1:54' */
        brain_B.Direction2 = 2.0;
      } else {
        /* '<S43>:1:56' */
        brain_B.Direction1 = 3.0;

        /* '<S43>:1:57' */
        brain_B.Direction2 = 1.0;
      }
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages(real_T sf_Image1, real_T sf_OldImage, real_T
  sf_count1)
{
  UNUSED_PARAMETER(sf_OldImage);

  /* Embedded MATLAB Function 'countimages': '<S7>:1300' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  image is recognized by the recognition software */
  if (sf_Image1 == 1.0) {
    /* '<S7>:1300:6' */
    /* '<S7>:1300:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S7>:1300:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_exit_internal_Buoys(void)
{
  switch (brain_DWork.is_Buoys) {
   case brain_IN_ApproachBuoys:
    switch (brain_DWork.is_ApproachBuoys) {
     case brain_IN_ApproachFirstBuoy:
      /* Exit 'ApproachFirstBuoy': '<S7>:1341' */
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     case brain_IN_FindSecondBuoy:
      /* Exit 'FindSecondBuoy': '<S7>:1317' */
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     default:
      brain_DWork.is_ApproachBuoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'ApproachSecondBuoy': '<S7>:1316' */
      break;
    }

    /* Exit 'ApproachBuoys': '<S7>:1312' */
    brain_DWork.is_Buoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   case brain_IN_FindBuoys:
    /* Exit 'FindBuoys': '<S7>:1295' */
    /* Simulink Function 'GetBuoyColors': '<S7>:1521' */
    memcpy((void *)&brain_B.LabelMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.ref_colors[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.num_colors_e = brain_DWork.num_colors;
    StateFlowFunctionsBuoysFindBu_l(brain_B.LabelMatrix, brain_B.num_colors_e,
      brain_B.ref_colors, &brain_B.StateFlowFunctionsBuoysFindB_ls,
      &brain_DWork.StateFlowFunctionsBuoysFindB_ls);
    memcpy((void *)&brain_DWork.BuoyBlobs[0], (void *)
           &brain_B.StateFlowFunctionsBuoysFindB_ls.blobs[0], 200U * sizeof
           (real_T));
    brain_DWork.num_blobs = brain_B.StateFlowFunctionsBuoysFindB_ls.count;
    brain_DWork.is_Buoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   default:
    brain_DWork.is_Buoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'BuoyDone': '<S7>:1453' */
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_Buoys(void)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T eml_min_dist;
  real_T eml_FirstD[50];
  real_T eml_SecondD[50];
  real_T eml_count;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i;

  /* During 'Buoys': '<S7>:1290' */
  if (brain_DWork.OperationalState != 4) {
    /* Transition: '<S7>:1279' */
    brain_exit_internal_Buoys();

    /* Exit 'Buoys': '<S7>:1290' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    switch (brain_DWork.is_Buoys) {
     case brain_IN_ApproachBuoys:
      brain_ApproachBuoys();
      break;

     case brain_IN_BuoyDone:
      break;

     case brain_IN_FindBuoys:
      /* During 'FindBuoys': '<S7>:1295' */
      if (brain_DWork.BuoyCount > 2.0) {
        /* Transition: '<S7>:1292' */
        /* Exit 'FindBuoys': '<S7>:1295' */
        /* Simulink Function 'GetBuoyColors': '<S7>:1521' */
        memcpy((void *)&brain_B.LabelMatrix[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.ref_colors[0], (void *)&brain_DWork.ref_colors[0],
               150U * sizeof(real_T));
        brain_B.num_colors_e = brain_DWork.num_colors;
        StateFlowFunctionsBuoysFindBu_l(brain_B.LabelMatrix,
          brain_B.num_colors_e, brain_B.ref_colors,
          &brain_B.StateFlowFunctionsBuoysFindB_ls,
          &brain_DWork.StateFlowFunctionsBuoysFindB_ls);
        brain_DWork.num_blobs = brain_B.StateFlowFunctionsBuoysFindB_ls.count;

        /* Entry 'ApproachBuoys': '<S7>:1312' */
        brain_DWork.is_Buoys = brain_IN_ApproachBuoys;
        brain_DWork.countarea = 0.0;
        brain_DWork.count2ndarea = 0.0;
        brain_DWork.TurnDirection = 0.0;

        /* Transition: '<S7>:1313' */
        /* Entry 'ApproachFirstBuoy': '<S7>:1341' */
        brain_DWork.is_ApproachBuoys = brain_IN_ApproachFirstBuoy;

        /* Simulink Function 'GetFirstBuoyStats': '<S7>:1342' */

        /* Constant: '<S8>/Constant' */
        brain_B.Constant_k = brain_P.Buoy1_Hue;

        /* Constant: '<S8>/Constant2' */
        brain_B.Constant2 = brain_P.Buoy1_Saturation;

        /* Constant: '<S8>/Constant1' */
        brain_B.Constant1 = brain_P.Buoy1_Value;
        brain_DWork.BuoyHue = brain_B.Constant_k;
        brain_DWork.BuoySaturation = brain_B.Constant2;
        brain_DWork.BuoyValue = brain_B.Constant1;

        /* Simulink Function 'WhichBuoysToApproach': '<S7>:1514' */
        for (i = 0; i < 200; i++) {
          brain_DWork.BuoyBlobs[i] =
            brain_B.StateFlowFunctionsBuoysFindB_ls.blobs[i];
          brain_B.buoys[i] = brain_DWork.BuoyBlobs[i];
        }

        brain_B.num_blobs = brain_DWork.num_blobs;

        /* S-Function (svipcolorconv): '<S42>/Color Space  Conversion' incorporates:
         *  Constant: '<S42>/Constant'
         *  Constant: '<S42>/Constant1'
         *  Constant: '<S42>/Constant2'
         */
        /* temporary variables for in-place operation */
        cc = 0.0;
        cc_0 = 0.0;
        cc_1 = 0.0;
        rtb_Add = 6.0 * brain_P.Buoy1_Hue;
        eml_min_dist = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-015);
        rtb_Add -= eml_min_dist;
        rtb_TSamp = 1.0 - brain_P.Buoy1_Saturation;
        eml_count = 1.0 - brain_P.Buoy1_Saturation * rtb_Add;
        rtb_Add = brain_P.Buoy1_Saturation * rtb_Add + rtb_TSamp;
        if (eml_min_dist == 0.0) {
          cc = 1.0;
          cc_0 = rtb_Add;
          cc_1 = rtb_TSamp;
        } else if (eml_min_dist == 1.0) {
          cc = eml_count;
          cc_0 = 1.0;
          cc_1 = rtb_TSamp;
        } else if (eml_min_dist == 2.0) {
          cc = rtb_TSamp;
          cc_0 = 1.0;
          cc_1 = rtb_Add;
        } else if (eml_min_dist == 3.0) {
          cc = rtb_TSamp;
          cc_0 = eml_count;
          cc_1 = 1.0;
        } else if (eml_min_dist == 4.0) {
          cc = rtb_Add;
          cc_0 = rtb_TSamp;
          cc_1 = 1.0;
        } else {
          if (eml_min_dist == 5.0) {
            cc = 1.0;
            cc_0 = rtb_TSamp;
            cc_1 = eml_count;
          }
        }

        if (cc > cc_0) {
          rtb_Add = cc;
        } else {
          rtb_Add = cc_0;
        }

        if (!(rtb_Add > cc_1)) {
          rtb_Add = cc_1;
        }

        rtb_Add = brain_P.Buoy1_Value / rtb_Add;

        /* assign the results */
        brain_B.ColorSpaceConversion_o3_c = rtb_Add * cc;
        brain_B.ColorSpaceConversion_o2_o = rtb_Add * cc_0;
        brain_B.ColorSpaceConversion_o1_g = rtb_Add * cc_1;

        /* S-Function (svipcolorconv): '<S42>/Color Space  Conversion1' */
        /* temporary variables for in-place operation */
        /* Convert to XYZ */
        /* temporary variables for in-place operation */
        /* First, linearize (de-gamma) the RGB values; the operation is */
        /* equivalent to running the gamma correction block with break */
        /* point of 0.00304 and gamma of 2.4; it's built into this */
        /* conversion for convenience */
        if (brain_B.ColorSpaceConversion_o3_c <= 3.9286085583733095E-002) {
          rtb_Add = brain_B.ColorSpaceConversion_o3_c / 1.2923054468333254E+001;
        } else {
          rtb_Add = (brain_B.ColorSpaceConversion_o3_c + 5.5000519817226361E-002)
            / 1.0550005198172263E+000;
          rtb_Add = rt_pow_snf(rtb_Add, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o2_o <= 3.9286085583733095E-002) {
          rtb_TSamp = brain_B.ColorSpaceConversion_o2_o /
            1.2923054468333254E+001;
        } else {
          rtb_TSamp = (brain_B.ColorSpaceConversion_o2_o +
                       5.5000519817226361E-002) / 1.0550005198172263E+000;
          rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o1_g <= 3.9286085583733095E-002) {
          cc = brain_B.ColorSpaceConversion_o1_g / 1.2923054468333254E+001;
        } else {
          cc = (brain_B.ColorSpaceConversion_o1_g + 5.5000519817226361E-002) /
            1.0550005198172263E+000;
          cc = rt_pow_snf(cc, 2.4);
        }

        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        eml_min_dist = (4.1239079926596001E-001 * rtb_Add +
                        3.5758433938388001E-001 * rtb_TSamp) +
          1.8048078840182999E-001 * cc;
        eml_count = (2.1263900587151000E-001 * rtb_Add + 7.1516867876776002E-001
                     * rtb_TSamp) + 7.2192315360729994E-002 * cc;
        rtb_Add = (1.9330818715590000E-002 * rtb_Add + 1.1919477979463000E-001 *
                   rtb_TSamp) + 9.5053215224966003E-001 * cc;

        /* Make sure that the output is in [0..1] range; clip if necessary */
        if (eml_min_dist > 1.0) {
          eml_min_dist = 1.0;
        } else {
          if (eml_min_dist < 0.0) {
            eml_min_dist = 0.0;
          }
        }

        if (eml_count > 1.0) {
          eml_count = 1.0;
        } else {
          if (eml_count < 0.0) {
            eml_count = 0.0;
          }
        }

        if (rtb_Add > 1.0) {
          rtb_Add = 1.0;
        } else {
          if (rtb_Add < 0.0) {
            rtb_Add = 0.0;
          }
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1 = eml_min_dist;
        brain_B.ColorSpaceConversion1_o2 = eml_count;
        brain_B.ColorSpaceConversion1_o3 = rtb_Add;

        /* Convert from XYZ to L*a*b* */
        rtb_Add = brain_B.ColorSpaceConversion1_o1 / 9.6419865576090003E-001;
        cc = brain_B.ColorSpaceConversion1_o3 / 8.2511648322104003E-001;

        /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
        if (rtb_Add > 8.8564516790356311E-003) {
          eml_min_dist = rt_pow_snf(rtb_Add, 3.3333333333333331E-001);
        } else {
          eml_min_dist = 7.7870370370370372E+000 * rtb_Add +
            1.3793103448275862E-001;
        }

        if (brain_B.ColorSpaceConversion1_o2 > 8.8564516790356311E-003) {
          rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2,
            3.3333333333333331E-001);
        } else {
          rtb_TSamp = 7.7870370370370372E+000 * brain_B.ColorSpaceConversion1_o2
            + 1.3793103448275862E-001;
        }

        if (cc > 8.8564516790356311E-003) {
          rtb_Add = rt_pow_snf(cc, 3.3333333333333331E-001);
        } else {
          rtb_Add = 7.7870370370370372E+000 * cc + 1.3793103448275862E-001;
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1 = 116.0 * rtb_TSamp - 16.0;
        brain_B.ColorSpaceConversion1_o2 = (eml_min_dist - rtb_TSamp) * 500.0;
        brain_B.ColorSpaceConversion1_o3 = (rtb_TSamp - rtb_Add) * 200.0;

        /* S-Function (svipcolorconv): '<S44>/Color Space  Conversion' incorporates:
         *  Constant: '<S44>/Constant'
         *  Constant: '<S44>/Constant1'
         *  Constant: '<S44>/Constant2'
         */
        /* temporary variables for in-place operation */
        cc = 0.0;
        cc_0 = 0.0;
        cc_1 = 0.0;
        rtb_Add = 6.0 * brain_P.Buoy2_Hue;
        eml_min_dist = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-015);
        rtb_Add -= eml_min_dist;
        rtb_TSamp = 1.0 - brain_P.Buoy2_Saturation;
        eml_count = 1.0 - brain_P.Buoy2_Saturation * rtb_Add;
        rtb_Add = brain_P.Buoy2_Saturation * rtb_Add + rtb_TSamp;
        if (eml_min_dist == 0.0) {
          cc = 1.0;
          cc_0 = rtb_Add;
          cc_1 = rtb_TSamp;
        } else if (eml_min_dist == 1.0) {
          cc = eml_count;
          cc_0 = 1.0;
          cc_1 = rtb_TSamp;
        } else if (eml_min_dist == 2.0) {
          cc = rtb_TSamp;
          cc_0 = 1.0;
          cc_1 = rtb_Add;
        } else if (eml_min_dist == 3.0) {
          cc = rtb_TSamp;
          cc_0 = eml_count;
          cc_1 = 1.0;
        } else if (eml_min_dist == 4.0) {
          cc = rtb_Add;
          cc_0 = rtb_TSamp;
          cc_1 = 1.0;
        } else {
          if (eml_min_dist == 5.0) {
            cc = 1.0;
            cc_0 = rtb_TSamp;
            cc_1 = eml_count;
          }
        }

        if (cc > cc_0) {
          rtb_Add = cc;
        } else {
          rtb_Add = cc_0;
        }

        if (!(rtb_Add > cc_1)) {
          rtb_Add = cc_1;
        }

        rtb_Add = brain_P.Buoy2_Value / rtb_Add;

        /* assign the results */
        brain_B.ColorSpaceConversion_o1_g = rtb_Add * cc;
        brain_B.ColorSpaceConversion_o2_o = rtb_Add * cc_0;
        brain_B.ColorSpaceConversion_o3_c = rtb_Add * cc_1;

        /* S-Function (svipcolorconv): '<S44>/Color Space  Conversion1' */
        /* temporary variables for in-place operation */
        /* Convert to XYZ */
        /* temporary variables for in-place operation */
        /* First, linearize (de-gamma) the RGB values; the operation is */
        /* equivalent to running the gamma correction block with break */
        /* point of 0.00304 and gamma of 2.4; it's built into this */
        /* conversion for convenience */
        if (brain_B.ColorSpaceConversion_o1_g <= 3.9286085583733095E-002) {
          rtb_Add = brain_B.ColorSpaceConversion_o1_g / 1.2923054468333254E+001;
        } else {
          rtb_Add = (brain_B.ColorSpaceConversion_o1_g + 5.5000519817226361E-002)
            / 1.0550005198172263E+000;
          rtb_Add = rt_pow_snf(rtb_Add, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o2_o <= 3.9286085583733095E-002) {
          rtb_TSamp = brain_B.ColorSpaceConversion_o2_o /
            1.2923054468333254E+001;
        } else {
          rtb_TSamp = (brain_B.ColorSpaceConversion_o2_o +
                       5.5000519817226361E-002) / 1.0550005198172263E+000;
          rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o3_c <= 3.9286085583733095E-002) {
          cc = brain_B.ColorSpaceConversion_o3_c / 1.2923054468333254E+001;
        } else {
          cc = (brain_B.ColorSpaceConversion_o3_c + 5.5000519817226361E-002) /
            1.0550005198172263E+000;
          cc = rt_pow_snf(cc, 2.4);
        }

        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        eml_min_dist = (4.1239079926596001E-001 * rtb_Add +
                        3.5758433938388001E-001 * rtb_TSamp) +
          1.8048078840182999E-001 * cc;
        eml_count = (2.1263900587151000E-001 * rtb_Add + 7.1516867876776002E-001
                     * rtb_TSamp) + 7.2192315360729994E-002 * cc;
        rtb_Add = (1.9330818715590000E-002 * rtb_Add + 1.1919477979463000E-001 *
                   rtb_TSamp) + 9.5053215224966003E-001 * cc;

        /* Make sure that the output is in [0..1] range; clip if necessary */
        if (eml_min_dist > 1.0) {
          eml_min_dist = 1.0;
        } else {
          if (eml_min_dist < 0.0) {
            eml_min_dist = 0.0;
          }
        }

        if (eml_count > 1.0) {
          eml_count = 1.0;
        } else {
          if (eml_count < 0.0) {
            eml_count = 0.0;
          }
        }

        if (rtb_Add > 1.0) {
          rtb_Add = 1.0;
        } else {
          if (rtb_Add < 0.0) {
            rtb_Add = 0.0;
          }
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1_n = eml_min_dist;
        brain_B.ColorSpaceConversion1_o2_i = eml_count;
        brain_B.ColorSpaceConversion1_o3_m = rtb_Add;

        /* Convert from XYZ to L*a*b* */
        rtb_Add = brain_B.ColorSpaceConversion1_o1_n / 9.6419865576090003E-001;
        cc = brain_B.ColorSpaceConversion1_o3_m / 8.2511648322104003E-001;

        /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
        if (rtb_Add > 8.8564516790356311E-003) {
          eml_min_dist = rt_pow_snf(rtb_Add, 3.3333333333333331E-001);
        } else {
          eml_min_dist = 7.7870370370370372E+000 * rtb_Add +
            1.3793103448275862E-001;
        }

        if (brain_B.ColorSpaceConversion1_o2_i > 8.8564516790356311E-003) {
          rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_i,
            3.3333333333333331E-001);
        } else {
          rtb_TSamp = 7.7870370370370372E+000 *
            brain_B.ColorSpaceConversion1_o2_i + 1.3793103448275862E-001;
        }

        if (cc > 8.8564516790356311E-003) {
          rtb_Add = rt_pow_snf(cc, 3.3333333333333331E-001);
        } else {
          rtb_Add = 7.7870370370370372E+000 * cc + 1.3793103448275862E-001;
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1_n = 116.0 * rtb_TSamp - 16.0;
        brain_B.ColorSpaceConversion1_o2_i = (eml_min_dist - rtb_TSamp) * 500.0;
        brain_B.ColorSpaceConversion1_o3_m = (rtb_TSamp - rtb_Add) * 200.0;

        /* Embedded MATLAB: '<S9>/GetBestColorMatch' */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch': '<S43>:1' */
        /*  This function determines which buoys are the best match for the desired colors */
        /*  Buoys = zeros(3,3); */
        /*  Buoys = [L;M;R]; */
        /* '<S43>:1:6' */
        rtb_TSamp = 1000.0;

        /* '<S43>:1:7' */
        eml_min_dist = 1000.0;

        /* '<S43>:1:8' */
        /* '<S43>:1:9' */
        for (i = 0; i < 50; i++) {
          eml_FirstD[i] = 2.0;
          eml_SecondD[i] = 2.0;
        }

        /* '<S43>:1:11' */
        eml_count = 0.0;

        /* '<S43>:1:12' */
        cc_0 = 0.0;

        /* '<S43>:1:14' */
        for (cc = 1.0; cc <= brain_B.num_blobs; cc++) {
          /* '<S43>:1:14' */
          /* '<S43>:1:15' */
          rtb_Add = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)cc - 1] -
            brain_B.ColorSpaceConversion1_o1, 2.0) + rt_pow_snf(brain_B.buoys
            [(int32_T)cc + 49] - brain_B.ColorSpaceConversion1_o2, 2.0)) +
                         rt_pow_snf(brain_B.buoys[(int32_T)cc + 99] -
            brain_B.ColorSpaceConversion1_o3, 2.0));
          if (rtb_Add <= rtb_TSamp) {
            /* '<S43>:1:16' */
            /* '<S43>:1:17' */
            eml_count++;

            /* '<S43>:1:18' */
            rtb_TSamp = rtb_Add;

            /* '<S43>:1:19' */
            eml_FirstD[(int32_T)eml_count - 1] = cc;
          }

          /* '<S43>:1:21' */
          rtb_Add = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)cc - 1] -
            brain_B.ColorSpaceConversion1_o1_n, 2.0) + rt_pow_snf(brain_B.buoys
                           [(int32_T)cc + 49] -
            brain_B.ColorSpaceConversion1_o2_i, 2.0)) + rt_pow_snf
                         (brain_B.buoys[(int32_T)cc + 99] -
                          brain_B.ColorSpaceConversion1_o3_m, 2.0));
          if (rtb_Add < eml_min_dist) {
            /* '<S43>:1:22' */
            /* '<S43>:1:23' */
            cc_0++;

            /* '<S43>:1:24' */
            eml_min_dist = rtb_Add;

            /* '<S43>:1:25' */
            eml_SecondD[(int32_T)cc_0 - 1] = cc;
          }
        }

        /* '<S43>:1:29' */
        cc = 2.0;

        /* '<S43>:1:30' */
        /* '<S43>:1:31' */
        for (rtb_Add = 1.0; rtb_Add <= eml_count; rtb_Add++) {
          /* '<S43>:1:31' */
          /* '<S43>:1:32' */
          if (brain_B.buoys[(int32_T)eml_FirstD[(int32_T)rtb_Add - 1] + 149] >
              0.0) {
            /* '<S43>:1:33' */
            /* '<S43>:1:34' */
            cc = eml_FirstD[(int32_T)rtb_Add - 1];
          }
        }

        /* '<S43>:1:39' */
        rtb_Add = 2.0;

        /* '<S43>:1:40' */
        /* '<S43>:1:41' */
        for (rtb_TSamp = 1.0; rtb_TSamp <= cc_0; rtb_TSamp++) {
          /* '<S43>:1:41' */
          /* '<S43>:1:42' */
          if (brain_B.buoys[(int32_T)eml_SecondD[(int32_T)rtb_TSamp - 1] + 149] >
              0.0) {
            /* '<S43>:1:43' */
            /* '<S43>:1:44' */
            rtb_Add = eml_SecondD[(int32_T)rtb_TSamp - 1];
          }
        }

        if (cc > rtb_Add) {
          /* '<S43>:1:49' */
          /* '<S43>:1:50' */
          brain_B.Direction1 = 1.0;

          /* '<S43>:1:51' */
          brain_B.Direction2 = 3.0;
        } else if (cc == rtb_Add) {
          /* '<S43>:1:52' */
          /* '<S43>:1:53' */
          brain_B.Direction1 = 2.0;

          /* '<S43>:1:54' */
          brain_B.Direction2 = 2.0;
        } else {
          /* '<S43>:1:56' */
          brain_B.Direction1 = 3.0;

          /* '<S43>:1:57' */
          brain_B.Direction2 = 1.0;
        }
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1483' */
        for (i = 0; i < 19200; i++) {
          brain_B.H[i] = brain_B.Resize[i];
          brain_B.S[i] = brain_B.Resize1[i];
          brain_B.V[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H, brain_B.S, brain_B.V,
          &brain_B.StateFlowFunctionsBuoysIterat_g,
          &brain_DWork.StateFlowFunctionsBuoysIterat_g);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
        memcpy((void *)&brain_B.LabMatrix_d[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d,
          brain_B.Ref_Colors_b, &brain_B.StateFlowFunctionsBuoysShowSe_o);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
               (real_T));

        /* Simulink Function 'LookforBuoys': '<S7>:1491' */
        memcpy((void *)&brain_B.LabMatrix_b[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        brain_B.num_colors = brain_DWork.num_colors;
        memcpy((void *)&brain_B.RGBin[0], (void *)&brain_B.RGBout[0], 57600U *
               sizeof(real_T));
        StateFlowFunctionsBuoysFindBuoy(brain_B.RGBin, brain_B.LabMatrix_b,
          brain_B.num_colors, &brain_B.StateFlowFunctionsBuoysFindB_ln,
          &brain_DWork.StateFlowFunctionsBuoysFindB_ln);
        brain_DWork.Obstacle = (brain_B.StateFlowFunctionsBuoysFindB_ln.Image !=
          0.0);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsBuoysFindB_ln.DrawMarkers[0], 57600U *
               sizeof(real_T));
        brain_DWork.BuoyCount = brain_countimages((real_T)brain_DWork.Obstacle,
          (real_T)brain_DWork.OldObstacle, brain_DWork.BuoyCount);

        /* Simulink Function 'GetBuoyForwardVelocity': '<S7>:1293' */

        /* Constant: '<S16>/Constant' */
        brain_B.Constant_l = brain_P.Heading_Forward_Velocity;
        brain_DWork.Forward = brain_B.Constant_l;

        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_DWork.Forward;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        cc = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        cc = floor(cc);
        if (cc < 128.0) {
          if (cc >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)cc;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
        brain_DWork.OldObstacle = brain_DWork.Obstacle;
      }
      break;

     default:
      /* Transition: '<S7>:1291' */
      /* Entry 'FindBuoys': '<S7>:1295' */
      brain_DWork.is_Buoys = brain_IN_FindBuoys;
      brain_DWork.Obstacle = FALSE;
      brain_DWork.OldObstacle = FALSE;
      brain_B.CameraPosition = 0;
      brain_DWork.BuoyCount = 0.0;

      /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

      /* Constant: '<S26>/Constant' */
      brain_B.Constant = brain_P.Track_Desired_Depth;
      brain_B.DesiredDepth = brain_B.Constant;
      break;
    }
  }
}

/* Function for Embedded MATLAB: '<S80>/IsLinePresent' */
static void brain_max_l(const real_T eml_varargin_1[71820], real_T eml_maxval
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
  boolean_T eml_exitg;
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
    eml_guard = FALSE;
    if (rtIsNaN(eml_mtmp)) {
      eml_searchingForNonNaN = TRUE;
      eml_k = 2;
      eml_exitg = FALSE;
      while (((uint32_T)eml_exitg == 0U) && (eml_k < 400)) {
        eml_b_ix++;
        if (!rtIsNaN(eml_varargin_1[eml_b_ix - 1])) {
          eml_mtmp = eml_varargin_1[eml_b_ix - 1];
          eml_itmp = eml_k;
          eml_searchingForNonNaN = FALSE;
          eml_exitg = TRUE;
        } else {
          eml_k++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = TRUE;
      }
    } else {
      eml_guard = TRUE;
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

/* Function for Embedded MATLAB: '<S80>/IsLinePresent' */
static void brain_max_lw(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx)
{
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  boolean_T eml_exitg;
  eml_mtmp = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = FALSE;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = TRUE;
    eml_k = 2;
    eml_exitg = FALSE;
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 181)) {
      eml_ix++;
      if (!rtIsNaN(eml_varargin_1[eml_ix - 1])) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
        eml_searchingForNonNaN = FALSE;
        eml_exitg = TRUE;
      } else {
        eml_k++;
      }
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = TRUE;
    }
  } else {
    eml_guard = TRUE;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 181; eml_k++) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > eml_mtmp) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = eml_k;
      }
    }
  }

  *eml_maxval = eml_mtmp;
  *eml_indx = (real_T)eml_itmp;
}

/* Function for Embedded MATLAB: '<S80>/IsLinePresent' */
static void brain_refp1_round(real_T *eml_x)
{
  if (*eml_x < 0.0) {
    *eml_x = ceil(*eml_x - 0.5);
  } else {
    *eml_x = floor(*eml_x + 0.5);
  }
}

/* Function for Embedded MATLAB: '<S80>/IsLinePresent' */
static void brain_c30_brain(void)
{
  int32_T eml_count;
  real_T eml_maxValues[180];
  real_T eml_RhoIndices[180];
  real_T eml_b;
  real_T eml_c;
  int32_T eml_i;
  real_T eml_ThetaIndex_idx;
  real_T eml_RhoIndex_idx;
  real_T eml_ThetaIndex_idx_0;
  real_T eml_RhoIndex_idx_0;
  memcpy((void *)&brain_B.eml_HoughTable[0], (void *)
         &brain_B.HoughTransform_o1_n[0], 71820U * sizeof(real_T));

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff/IsLinePresent': '<S81>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S81>:1:5' */
  /* '<S81>:1:7' */
  /* '<S81>:1:9' */
  /* '<S81>:1:10' */
  /* '<S81>:1:11' */
  /* '<S81>:1:12' */
  /* '<S81>:1:13' */
  brain_B.Rho[0] = -999.0;
  brain_B.Theta[0] = -999.0;
  brain_B.maxVotes[0] = -999.0;
  brain_B.Rho[1] = -999.0;
  brain_B.Theta[1] = -999.0;
  brain_B.maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S81>:1:17' */
  brain_max_l(&brain_B.HoughTransform_o1_n[0], eml_maxValues, eml_RhoIndices);
  brain_max_lw(eml_maxValues, &eml_b, &eml_c);

  /* '<S81>:1:20' */
  brain_B.maxVotes[0] = eml_b;

  /* '<S81>:1:20' */
  /* '<S81>:1:21' */
  eml_b = 0.0;

  /* '<S81>:1:22' */
  eml_c = 0.0;

  /* '<S81>:1:23' */
  for (eml_i = 0; eml_i < 180; eml_i++) {
    /* '<S81>:1:23' */
    if (brain_B.maxVotes[0] - eml_maxValues[eml_i] < 0.15 * brain_B.maxVotes[0])
    {
      /* '<S81>:1:24' */
      /* '<S81>:1:25' */
      eml_b += ((real_T)eml_i + 1.0) * eml_maxValues[eml_i];

      /* '<S81>:1:26' */
      eml_c += eml_maxValues[eml_i];
    }
  }

  if (eml_c > 0.0) {
    /* '<S81>:1:29' */
    /* '<S81>:1:30' */
    eml_b /= eml_c;
    brain_refp1_round(&eml_b);
  } else {
    /* '<S81>:1:32' */
    eml_b = 1.0;
  }

  /* '<S81>:1:35' */
  eml_ThetaIndex_idx = eml_b;

  /* '<S81>:1:36' */
  brain_B.maxVotes[0] = eml_maxValues[(int32_T)eml_b - 1];

  /* '<S81>:1:38' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_b - 1];
  if (brain_B.maxVotes[0] >= 15.0) {
    /* '<S81>:1:40' */
    /* '<S81>:1:41' */
    brain_B.eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 399 * ((int32_T)
      eml_b - 1)] = 0.0;

    /* '<S81>:1:43' */
    eml_i = 2;

    /* '<S81>:1:44' */
    eml_count = 0;
    while ((eml_i <= 2) && (eml_count < 12)) {
      /* '<S81>:1:45' */
      /* '<S81>:1:46' */
      eml_count++;
      brain_max_l(&brain_B.eml_HoughTable[0], eml_maxValues, eml_RhoIndices);
      brain_max_lw(eml_maxValues, &eml_b, &eml_c);

      /* '<S81>:1:48' */
      brain_B.maxVotes[1] = eml_b;

      /* '<S81>:1:48' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S81>:1:49' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S81>:1:51' */
      brain_B.eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 399 * ((int32_T)
        eml_c - 1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S81>:1:53' */
        /* '<S81>:1:54' */
        eml_i = 3;
      }
    }

    /* '<S81>:1:59' */
    if (brain_B.maxVotes[0] > 15.0) {
      /* '<S81>:1:60' */
      /* '<S81>:1:61' */
      brain_B.Theta[0] = brain_B.HoughTransform_o2_e[(int32_T)eml_ThetaIndex_idx
        - 1];

      /* '<S81>:1:62' */
      brain_B.Rho[0] = brain_B.HoughTransform_o3_n[(int32_T)eml_RhoIndex_idx - 1];
      if ((brain_B.Theta[0] > 0.0) && (brain_B.Rho[0] < 0.0)) {
        /* '<S81>:1:63' */
        /* '<S81>:1:64' */
        brain_B.Rho[0] = brain_B.Rho[0] * -1.0;
      }
    }

    /* '<S81>:1:59' */
    if (brain_B.maxVotes[1] > 15.0) {
      /* '<S81>:1:60' */
      /* '<S81>:1:61' */
      brain_B.Theta[1] = brain_B.HoughTransform_o2_e[(int32_T)
        eml_ThetaIndex_idx_0 - 1];

      /* '<S81>:1:62' */
      brain_B.Rho[1] = brain_B.HoughTransform_o3_n[(int32_T)eml_RhoIndex_idx_0 -
        1];
      if ((brain_B.Theta[1] > 0.0) && (brain_B.Rho[1] < 0.0)) {
        /* '<S81>:1:63' */
        /* '<S81>:1:64' */
        brain_B.Rho[1] = brain_B.Rho[1] * -1.0;
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S21>/GetHeadingToPath' */
static void brain_max_h(const real_T eml_varargin_1[2], real_T *eml_maxval,
  real_T *eml_indx)
{
  real_T eml_mtmp;
  int32_T eml_itmp;
  int32_T eml_ix;
  boolean_T eml_searchingForNonNaN;
  int32_T eml_k;
  boolean_T eml_guard;
  eml_mtmp = eml_varargin_1[0];
  eml_itmp = 1;
  eml_ix = 1;
  eml_guard = FALSE;
  if (rtIsNaN(eml_varargin_1[0])) {
    eml_searchingForNonNaN = TRUE;
    eml_ix = 2;
    if (!rtIsNaN(eml_varargin_1[1])) {
      eml_mtmp = eml_varargin_1[1];
      eml_itmp = 2;
      eml_searchingForNonNaN = FALSE;
    }

    if (!eml_searchingForNonNaN) {
      eml_guard = TRUE;
    }
  } else {
    eml_guard = TRUE;
  }

  if (eml_guard) {
    for (eml_k = eml_itmp + 1; eml_k < 3; eml_k = 3) {
      eml_ix++;
      if (eml_varargin_1[eml_ix - 1] > eml_mtmp) {
        eml_mtmp = eml_varargin_1[eml_ix - 1];
        eml_itmp = 2;
      }
    }
  }

  *eml_maxval = eml_mtmp;
  *eml_indx = (real_T)eml_itmp;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_OnePath(void)
{
  real_T sf_ErrorY;
  real_T y;
  int32_T idxROI;
  int32_T idxStart;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  real_T eml_b;
  real_T eml_c;
  int32_T ky;
  int32_T ku;
  int32_T inIdx;
  int32_T outIdx;
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  real_T tmp;

  /* During 'OnePath': '<S7>:1549' */
  switch (brain_DWork.is_OnePath) {
   case brain_IN_AlignWithPath:
    /* During 'AlignWithPath': '<S7>:1559' */
    if (fabs(brain_DWork.HeadingAlongPath) <= 4.0) {
      /* Transition: '<S7>:1551' */
      /* Exit 'AlignWithPath': '<S7>:1559' */
      /* Entry 'Done': '<S7>:1553' */
      brain_DWork.is_OnePath = brain_IN_Done;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;
      brain_B.DesiredHeading = brain_U.CurrentHeading +
        brain_DWork.HeadingAlongPath;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'HSVSegmentation': '<S7>:1568' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_g[i] = brain_B.Resize[i];
        brain_B.S_d[i] = brain_B.Resize1[i];

        /* Logic: '<S98>/Logical Operator1' incorporates:
         *  Constant: '<S100>/Constant'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S99>/Constant'
         *  Logic: '<S98>/Logical Operator'
         *  RelationalOperator: '<S100>/Compare'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S99>/Compare'
         */
        brain_B.BW_m[i] = (((brain_B.H_g[i] < brain_P.Track_HueLower) ||
                            (brain_B.H_g[i] > brain_P.Track_HueHigher)) &&
                           (brain_B.S_d[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipmorphop): '<S98>/Erosion' */
      ky = 0;
      ku = 0;
      for (inIdx = 0; inIdx < 127; inIdx++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
      }

      for (i = 0; i < 160; i++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
        memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky], (void *)
               &brain_B.BW_m[ku], 120U * sizeof(boolean_T));
        ky += 120;
        ku += 120;
        for (inIdx = 121; inIdx < 127; inIdx++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 161; i < 167; i++) {
        for (inIdx = 0; inIdx < 127; inIdx++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (line_idx_5 = 0; line_idx_5 < 21209; line_idx_5++) {
        brain_DWork.Erosion_TWO_PAD_IMG_DW_h[line_idx_5] = TRUE;
      }

      ku = 0;
      for (i = 0; i < 167; i++) {
        for (line_idx_3 = 0; line_idx_3 < 124; line_idx_3++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = TRUE;
          for (line_idx_5 = 0; line_idx_5 < brain_DWork.Erosion_NUMNONZ_DW_f[0];
               line_idx_5++) {
            if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ku +
                brain_DWork.Erosion_ERODE_OFF_DW_l[line_idx_5]]) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = FALSE;
              line_idx_5 = brain_DWork.Erosion_NUMNONZ_DW_f[0];
            }
          }

          ku++;
        }

        ku += 3;
      }

      inIdx = 1;
      outIdx = 0;
      for (i = 0; i < 160; i++) {
        for (line_idx_3 = 1; line_idx_3 < 121; line_idx_3++) {
          brain_B.Erosion_m[outIdx] = TRUE;
          for (line_idx_5 = 0; line_idx_5 < brain_DWork.Erosion_NUMNONZ_DW_f[1];
               line_idx_5++) {
            if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_h[brain_DWork.Erosion_ERODE_OFF_DW_l
                [line_idx_5 + brain_DWork.Erosion_NUMNONZ_DW_f[0]] + inIdx]) {
              brain_B.Erosion_m[outIdx] = FALSE;
              line_idx_5 = brain_DWork.Erosion_NUMNONZ_DW_f[1];
            }
          }

          inIdx++;
          outIdx++;
        }

        inIdx += 7;
      }

      /* Simulink Function 'GetHeadings': '<S7>:1565' */
      for (i = 0; i < 19200; i++) {
        /* DataTypeConversion: '<S98>/Data Type Conversion' */
        brain_B.DataTypeConversion[i] = brain_B.Erosion_m[i];
        brain_B.BWout[i] = (real_T)brain_B.DataTypeConversion[i];
        brain_B.BW[i] = brain_B.BWout[i];
      }

      /* S-Function (svipscalenconvert): '<S21>/Image Data Type Conversion' */
      for (ky = 0; ky < 19200; ky++) {
        brain_B.ImageDataTypeConversion_p[ky] = ((brain_B.BW[ky] == 0.0 ? 0 : 1)
          != 0);
      }

      /* S-Function (sviphough): '<S80>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.ImageDataTypeConversion_p[0],
                    &brain_B.HoughTransform_o1_n[0], &brain_ConstP.pooled18[0],
                    &brain_ConstP.pooled19, 120, 160, 399, 91);

      /* Embedded MATLAB: '<S80>/IsLinePresent' */
      brain_c30_brain();

      /* S-Function (sviphoughlines): '<S21>/Hough Lines' */
      inIdx = 0;
      eml_b = (brain_B.Rho[0] + 2.2204460492503131E-016) / (cos(brain_B.Theta[0])
        + 2.2204460492503131E-016);

      /* part-1: top horizontal axis */
      eml_c = floor(eml_b + 0.5);
      if ((eml_c >= 0.0) && (eml_c <= 159.0)) {
        brain_B.HoughLines_a[0] = 0;
        brain_B.HoughLines_a[1] = (int32_T)floor((real_T)(int32_T)eml_c + 0.5);
        inIdx = 1;
      }

      y = (brain_B.Rho[0] + 2.2204460492503131E-016) / (sin(brain_B.Theta[0]) +
        2.2204460492503131E-016);

      /* part-2: left vertical axis */
      eml_c = floor(y + 0.5);
      if ((eml_c >= 0.0) && (eml_c <= 119.0)) {
        brain_B.HoughLines_a[(inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
          eml_c + 0.5);
        brain_B.HoughLines_a[1 + (inIdx << 1)] = 0;
        inIdx++;
      }

      /* part-3: Right vertical axis */
      if (inIdx < 2) {
        eml_c = floor((eml_b - 159.0) * (y / eml_b) + 0.5);
        if ((eml_c >= 0.0) && (eml_c <= 119.0)) {
          brain_B.HoughLines_a[(inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
            eml_c + 0.5);
          brain_B.HoughLines_a[1 + (inIdx << 1)] = 159;
          inIdx++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (inIdx < 2) {
        eml_c = floor((eml_b - eml_b / y * 119.0) + 0.5);
        if ((eml_c >= 0.0) && (eml_c <= 159.0)) {
          brain_B.HoughLines_a[(inIdx << 1)] = 119;
          brain_B.HoughLines_a[1 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)eml_c + 0.5);
          inIdx++;
        }
      }

      if (inIdx < 2) {
        brain_B.HoughLines_a[0] = -1;
        brain_B.HoughLines_a[1] = -1;
        brain_B.HoughLines_a[2] = -1;
        brain_B.HoughLines_a[3] = -1;
      }

      inIdx = 0;
      eml_b = (brain_B.Rho[1] + 2.2204460492503131E-016) / (cos(brain_B.Theta[1])
        + 2.2204460492503131E-016);

      /* part-1: top horizontal axis */
      eml_c = floor(eml_b + 0.5);
      if ((eml_c >= 0.0) && (eml_c <= 159.0)) {
        brain_B.HoughLines_a[4] = 0;
        brain_B.HoughLines_a[5] = (int32_T)floor((real_T)(int32_T)eml_c + 0.5);
        inIdx = 1;
      }

      y = (brain_B.Rho[1] + 2.2204460492503131E-016) / (sin(brain_B.Theta[1]) +
        2.2204460492503131E-016);

      /* part-2: left vertical axis */
      eml_c = floor(y + 0.5);
      if ((eml_c >= 0.0) && (eml_c <= 119.0)) {
        brain_B.HoughLines_a[4 + (inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
          eml_c + 0.5);
        brain_B.HoughLines_a[5 + (inIdx << 1)] = 0;
        inIdx++;
      }

      /* part-3: Right vertical axis */
      if (inIdx < 2) {
        eml_c = floor((eml_b - 159.0) * (y / eml_b) + 0.5);
        if ((eml_c >= 0.0) && (eml_c <= 119.0)) {
          brain_B.HoughLines_a[4 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)eml_c + 0.5);
          brain_B.HoughLines_a[5 + (inIdx << 1)] = 159;
          inIdx++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (inIdx < 2) {
        eml_c = floor((eml_b - eml_b / y * 119.0) + 0.5);
        if ((eml_c >= 0.0) && (eml_c <= 159.0)) {
          brain_B.HoughLines_a[4 + (inIdx << 1)] = 119;
          brain_B.HoughLines_a[5 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)eml_c + 0.5);
          inIdx++;
        }
      }

      if (inIdx < 2) {
        brain_B.HoughLines_a[4] = -1;
        brain_B.HoughLines_a[5] = -1;
        brain_B.HoughLines_a[6] = -1;
        brain_B.HoughLines_a[7] = -1;
      }

      /* S-Function (svipdrawshapes): '<S21>/Draw Shapes' */
      /* Copy the image from input to output. */
      memcpy((void *)&brain_B.DrawShapes_m[0], (void *)&brain_B.BW[0], 19200U *
             sizeof(real_T));
      idxStart = 0;
      for (idxROI = 0; idxROI < 2; idxROI++) {
        for (i = 0; i < 1; i = 1) {
          line_idx_2 = brain_B.HoughLines_a[idxStart];
          line_idx_3 = brain_B.HoughLines_a[idxStart + 1];
          inIdx = brain_B.HoughLines_a[idxStart + 2];
          line_idx_4 = brain_B.HoughLines_a[idxStart + 3];
          if ((brain_B.HoughLines_a[idxStart] != inIdx) || (line_idx_3 !=
               line_idx_4)) {
            isInBound = FALSE;

            /* Find the visible portion of a line. */
            visited = FALSE;
            visited_0 = FALSE;
            done = FALSE;
            line_idx_5 = brain_B.HoughLines_a[idxStart];
            line_idx = line_idx_3;
            line_idx_1 = inIdx;
            line_idx_0 = line_idx_4;
            while (!done) {
              i = 0;
              outIdx = 0;

              /* Determine viewport violations. */
              if (line_idx_5 < 0) {
                i = 4;
              } else {
                if (line_idx_5 > 119) {
                  i = 8;
                }
              }

              if (line_idx_1 < 0) {
                outIdx = 4;
              } else {
                if (line_idx_1 > 119) {
                  outIdx = 8;
                }
              }

              if (line_idx < 0) {
                i |= 1;
              } else {
                if (line_idx > 159) {
                  i |= 2;
                }
              }

              if (line_idx_0 < 0) {
                outIdx |= 1;
              } else {
                if (line_idx_0 > 159) {
                  outIdx |= 2;
                }
              }

              if (!((uint32_T)(i | outIdx))) {
                /* Line falls completely within bounds. */
                done = TRUE;
                isInBound = TRUE;
              } else if ((uint32_T)(i & outIdx)) {
                /* Line falls completely out of bounds. */
                done = TRUE;
                isInBound = FALSE;
              } else if ((uint32_T)i != 0U) {
                /* Clip 1st point; if it's in-bounds, clip 2nd point. */
                if (visited) {
                  line_idx_5 = line_idx_2;
                  line_idx = line_idx_3;
                }

                ky = line_idx_1 - line_idx_5;
                ku = line_idx_0 - line_idx;
                if ((uint32_T)(i & 4)) {
                  /* Violated RMin. */
                  i = (0 - line_idx_5) * ku;
                  if (((i >= 0) && (ky >= 0)) || ((i < 0) && (ky < 0))) {
                    line_idx += (div_s32_floor(i << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx += -((div_s32_floor((-i) << 1U, ky) + 1) >> 1);
                  }

                  line_idx_5 = 0;
                  visited = TRUE;
                } else if ((uint32_T)(i & 8)) {
                  /* Violated RMax. */
                  i = (119 - line_idx_5) * ku;
                  if (((i >= 0) && (ky >= 0)) || ((i < 0) && (ky < 0))) {
                    line_idx += (div_s32_floor(i << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx += -((div_s32_floor((-i) << 1U, ky) + 1) >> 1);
                  }

                  line_idx_5 = 119;
                  visited = TRUE;
                } else if ((uint32_T)(i & 1)) {
                  /* Violated CMin. */
                  i = (0 - line_idx) * ky;
                  if (((i >= 0) && (ku >= 0)) || ((i < 0) && (ku < 0))) {
                    line_idx_5 += (div_s32_floor(i << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_5 += -((div_s32_floor((-i) << 1U, ku) + 1) >> 1);
                  }

                  line_idx = 0;
                  visited = TRUE;
                } else {
                  /* Violated CMax. */
                  i = (159 - line_idx) * ky;
                  if (((i >= 0) && (ku >= 0)) || ((i < 0) && (ku < 0))) {
                    line_idx_5 += (div_s32_floor(i << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_5 += -((div_s32_floor((-i) << 1U, ku) + 1) >> 1);
                  }

                  line_idx = 159;
                  visited = TRUE;
                }
              } else {
                /* Clip the 2nd point. */
                if (visited_0) {
                  line_idx_1 = inIdx;
                  line_idx_0 = line_idx_4;
                }

                ky = line_idx_1 - line_idx_5;
                ku = line_idx_0 - line_idx;
                if ((uint32_T)(outIdx & 4)) {
                  /* Violated RMin. */
                  i = (0 - line_idx_1) * ku;
                  if (((i >= 0) && (ky >= 0)) || ((i < 0) && (ky < 0))) {
                    line_idx_0 += (div_s32_floor(i << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-i) << 1U, ky) + 1) >> 1);
                  }

                  line_idx_1 = 0;
                  visited_0 = TRUE;
                } else if ((uint32_T)(outIdx & 8)) {
                  /* Violated RMax. */
                  i = (119 - line_idx_1) * ku;
                  if (((i >= 0) && (ky >= 0)) || ((i < 0) && (ky < 0))) {
                    line_idx_0 += (div_s32_floor(i << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-i) << 1U, ky) + 1) >> 1);
                  }

                  line_idx_1 = 119;
                  visited_0 = TRUE;
                } else if ((uint32_T)(outIdx & 1)) {
                  /* Violated CMin. */
                  i = (0 - line_idx_0) * ky;
                  if (((i >= 0) && (ku >= 0)) || ((i < 0) && (ku < 0))) {
                    line_idx_1 += (div_s32_floor(i << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_1 += -((div_s32_floor((-i) << 1U, ku) + 1) >> 1);
                  }

                  line_idx_0 = 0;
                  visited_0 = TRUE;
                } else {
                  /* Violated CMax. */
                  i = (159 - line_idx_0) * ky;
                  if (((i >= 0) && (ku >= 0)) || ((i < 0) && (ku < 0))) {
                    line_idx_1 += (div_s32_floor(i << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_1 += -((div_s32_floor((-i) << 1U, ku) + 1) >> 1);
                  }

                  line_idx_0 = 159;
                  visited_0 = TRUE;
                }
              }
            }

            if (isInBound) {
              /* Draw a line using Bresenham algorithm. */
              /* Initialize the Bresenham algorithm. */
              if (line_idx_1 >= line_idx_5) {
                ky = line_idx_1 - line_idx_5;
              } else {
                ky = line_idx_5 - line_idx_1;
              }

              if (line_idx_0 >= line_idx) {
                ku = line_idx_0 - line_idx;
              } else {
                ku = line_idx - line_idx_0;
              }

              if (ky > ku) {
                line_idx_3 = 1;
                ku = 120;
              } else {
                line_idx_3 = 120;
                ku = 1;
                ky = line_idx_5;
                line_idx_5 = line_idx;
                line_idx = ky;
                ky = line_idx_1;
                line_idx_1 = line_idx_0;
                line_idx_0 = ky;
              }

              if (line_idx_5 > line_idx_1) {
                ky = line_idx_5;
                line_idx_5 = line_idx_1;
                line_idx_1 = ky;
                ky = line_idx;
                line_idx = line_idx_0;
                line_idx_0 = ky;
              }

              inIdx = line_idx_1 - line_idx_5;
              if (line_idx <= line_idx_0) {
                ky = 1;
                outIdx = line_idx_0 - line_idx;
              } else {
                ky = -1;
                outIdx = line_idx - line_idx_0;
              }

              line_idx_2 = -((inIdx + 1) >> 1);
              i = line_idx_5 * line_idx_3 + line_idx * ku;
              ky = ky * ku + line_idx_3;
              for (isInBound = (line_idx_5 <= line_idx_1); isInBound; isInBound =
                   (line_idx_5 <= line_idx_1)) {
                brain_B.DrawShapes_m[i] = 0.75;

                /* Compute the next location using Bresenham algorithm. */
                /* Move to the next pixel location. */
                line_idx_2 += outIdx;
                if (line_idx_2 >= 0) {
                  line_idx_2 -= inIdx;
                  i += ky;
                } else {
                  i += line_idx_3;
                }

                line_idx_5++;
              }
            }
          }

          idxStart += 2;
        }

        idxStart += 2;
      }

      /* Embedded MATLAB: '<S21>/GetHeadingToPath' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/GetHeadingToPath': '<S79>:1' */
      /*  This function calculates the heading to the path from Theta and Rho */
      /* '<S79>:1:4' */
      /* '<S79>:1:6' */
      brain_B.AlongPathHeading = -999.0;
      brain_max_h(&brain_B.maxVotes[0], &eml_b, &eml_c);

      /* '<S79>:1:10' */
      /* '<S79>:1:11' */
      /* '<S79>:1:12' */
      if ((brain_B.Theta[(int32_T)eml_c - 1] > -1.5707963267948966E+000) &&
          (brain_B.Theta[(int32_T)eml_c - 1] < 1.5707963267948966E+000)) {
        /* '<S79>:1:21' */
        /* '<S79>:1:22' */
        brain_B.AlongPathHeading = brain_B.Theta[(int32_T)eml_c - 1] * 180.0 /
          3.1415926535897931E+000;
      }

      brain_DWork.HeadingAlongPath = brain_B.AlongPathHeading;

      /* Simulink Function 'CamDown_CenterOver_Yaw': '<S7>:1841' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = brain_B.DrawShapes_m[i];
        brain_B.BW_f[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsFollowOnePa_e(brain_B.BW_f, brain_M,
        &brain_B.StateFlowFunctionsFollowOneP_ey,
        &brain_DWork.StateFlowFunctionsFollowOneP_ey);
      brain_B.Left = brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion;
      brain_B.Right =
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion1;
      brain_DWork.Forward = (real_T)
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion_m;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S37>/Add' */
      eml_b = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S132>/TSamp' incorporates:
       *  Gain: '<S131>/Depth Derivative Gain'
       *
       * About '<S132>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_c = brain_P.Depth_Kd * eml_b / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
       *  Gain: '<S131>/Depth Proportional Gain'
       *  Sum: '<S131>/Sum'
       *  Sum: '<S132>/Diff'
       *  UnitDelay: '<S132>/UD'
       *
       * Block description for '<S132>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S132>/UD':
       *
       *  Store in Global RAM
       */
      tmp = (brain_P.Depth_Kp * eml_b + (eml_c - brain_DWork.UD_DSTATE)) +
        brain_DWork.DepthDiscreteTimeIntegrator_DST;
      tmp = floor(tmp);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S132>/UD'
       * Block description for '<S132>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = eml_c;

      /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S131>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki * eml_b)
        + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
      } else {
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
        }
      }

      brain_B.Vertical = brain_B.DoubleToInt8;

      /* Simulink Function 'Align': '<S7>:1560' */
      brain_B.HeadingAlong = brain_DWork.HeadingAlongPath;
      StateFlowFunctionsFollowOnePath(brain_B.HeadingAlong, brain_M,
        &brain_B.StateFlowFunctionsFollowOnePa_k,
        &brain_DWork.StateFlowFunctionsFollowOnePa_k);
      brain_B.Strafe = (int8_T)(int16_T)
        (brain_B.StateFlowFunctionsFollowOnePa_k.Gain >> 7);
      brain_B.Left = (int8_T)((real_T)brain_B.Left + brain_DWork.Forward);
      brain_B.Right = (int8_T)((real_T)brain_B.Right + brain_DWork.Forward);
    }
    break;

   case brain_IN_Done:
    break;

   case brain_IN_PositionOver:
    /* During 'PositionOver': '<S7>:1554' */
    if (brain_DWork.Error < 10.0) {
      /* Transition: '<S7>:1550' */
      /* Exit 'PositionOver': '<S7>:1554' */
      /* Entry 'AlignWithPath': '<S7>:1559' */
      brain_DWork.is_OnePath = brain_IN_AlignWithPath;
      brain_DWork.HeadingAlongPath = 10.0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;
    } else {
      /* Simulink Function 'HSVSegmentation': '<S7>:1568' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_g[i] = brain_B.Resize[i];
        brain_B.S_d[i] = brain_B.Resize1[i];

        /* Logic: '<S98>/Logical Operator1' incorporates:
         *  Constant: '<S100>/Constant'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S99>/Constant'
         *  Logic: '<S98>/Logical Operator'
         *  RelationalOperator: '<S100>/Compare'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S99>/Compare'
         */
        brain_B.BW_m[i] = (((brain_B.H_g[i] < brain_P.Track_HueLower) ||
                            (brain_B.H_g[i] > brain_P.Track_HueHigher)) &&
                           (brain_B.S_d[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipmorphop): '<S98>/Erosion' */
      ky = 0;
      ku = 0;
      for (inIdx = 0; inIdx < 127; inIdx++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
      }

      for (i = 0; i < 160; i++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
        memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky], (void *)
               &brain_B.BW_m[ku], 120U * sizeof(boolean_T));
        ky += 120;
        ku += 120;
        for (inIdx = 121; inIdx < 127; inIdx++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 161; i < 167; i++) {
        for (inIdx = 0; inIdx < 127; inIdx++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (line_idx_5 = 0; line_idx_5 < 21209; line_idx_5++) {
        brain_DWork.Erosion_TWO_PAD_IMG_DW_h[line_idx_5] = TRUE;
      }

      ku = 0;
      for (i = 0; i < 167; i++) {
        for (line_idx_3 = 0; line_idx_3 < 124; line_idx_3++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = TRUE;
          for (line_idx_5 = 0; line_idx_5 < brain_DWork.Erosion_NUMNONZ_DW_f[0];
               line_idx_5++) {
            if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ku +
                brain_DWork.Erosion_ERODE_OFF_DW_l[line_idx_5]]) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = FALSE;
              line_idx_5 = brain_DWork.Erosion_NUMNONZ_DW_f[0];
            }
          }

          ku++;
        }

        ku += 3;
      }

      inIdx = 1;
      outIdx = 0;
      for (i = 0; i < 160; i++) {
        for (line_idx_3 = 1; line_idx_3 < 121; line_idx_3++) {
          brain_B.Erosion_m[outIdx] = TRUE;
          for (line_idx_5 = 0; line_idx_5 < brain_DWork.Erosion_NUMNONZ_DW_f[1];
               line_idx_5++) {
            if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_h[brain_DWork.Erosion_ERODE_OFF_DW_l
                [line_idx_5 + brain_DWork.Erosion_NUMNONZ_DW_f[0]] + inIdx]) {
              brain_B.Erosion_m[outIdx] = FALSE;
              line_idx_5 = brain_DWork.Erosion_NUMNONZ_DW_f[1];
            }
          }

          inIdx++;
          outIdx++;
        }

        inIdx += 7;
      }

      /* Simulink Function 'CamDown_CenterOver_Yaw': '<S7>:1841' */
      for (i = 0; i < 19200; i++) {
        /* DataTypeConversion: '<S98>/Data Type Conversion' */
        brain_B.DataTypeConversion[i] = brain_B.Erosion_m[i];
        brain_B.BWout[i] = (real_T)brain_B.DataTypeConversion[i];
        brain_B.BW_f[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsFollowOnePa_e(brain_B.BW_f, brain_M,
        &brain_B.StateFlowFunctionsFollowOneP_ey,
        &brain_DWork.StateFlowFunctionsFollowOneP_ey);
      brain_B.Left = brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion;
      brain_B.Right =
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion1;
      brain_DWork.Forward = (real_T)
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion_m;
      y = brain_B.StateFlowFunctionsFollowOneP_ey.Subtract1;
      sf_ErrorY = brain_B.StateFlowFunctionsFollowOneP_ey.Subtract;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S37>/Add' */
      eml_b = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S132>/TSamp' incorporates:
       *  Gain: '<S131>/Depth Derivative Gain'
       *
       * About '<S132>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_c = brain_P.Depth_Kd * eml_b / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
       *  Gain: '<S131>/Depth Proportional Gain'
       *  Sum: '<S131>/Sum'
       *  Sum: '<S132>/Diff'
       *  UnitDelay: '<S132>/UD'
       *
       * Block description for '<S132>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S132>/UD':
       *
       *  Store in Global RAM
       */
      tmp = (brain_P.Depth_Kp * eml_b + (eml_c - brain_DWork.UD_DSTATE)) +
        brain_DWork.DepthDiscreteTimeIntegrator_DST;
      tmp = floor(tmp);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S132>/UD'
       * Block description for '<S132>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = eml_c;

      /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S131>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki * eml_b)
        + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
      } else {
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
        }
      }

      brain_B.Vertical = brain_B.DoubleToInt8;
      brain_B.Left = (int8_T)((real_T)brain_B.Left + brain_DWork.Forward);
      brain_B.Right = (int8_T)((real_T)brain_B.Right + brain_DWork.Forward);

      /* Embedded MATLAB Function 'CalcError': '<S7>:1555' */
      /*  This function calculates the error between the center of the screen and  */
      /*  the centroid of the orange/red blob */
      /* '<S7>:1555:5' */
      brain_DWork.Error = fabs(y) + fabs(sf_ErrorY);
    }
    break;

   default:
    /* Transition: '<S7>:1552' */
    /* Entry 'PositionOver': '<S7>:1554' */
    brain_DWork.is_OnePath = brain_IN_PositionOver;
    brain_DWork.Error = 500.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_RecognizePath(void)
{
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i;
  real_T tmp;

  /* During 'RecognizePath': '<S7>:1578' */
  if ((int32_T)brain_DWork.Obstacle == 1) {
    /* Transition: '<S7>:1548' */
    /* Exit 'TurnLeft': '<S7>:1583' */
    brain_DWork.is_RecognizePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'TurnRight': '<S7>:1582' */
    /* Exit 'RecognizePath': '<S7>:1578' */
    /* Entry 'OnePath': '<S7>:1549' */
    brain_DWork.is_FollowOnePath = brain_IN_OnePath;

    /* Transition: '<S7>:1552' */
    /* Entry 'PositionOver': '<S7>:1554' */
    brain_DWork.is_OnePath = brain_IN_PositionOver;
    brain_DWork.Error = 500.0;
  } else {
    /* Simulink Function 'LookforTrack': '<S7>:1584' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_d[i] = brain_B.Resize[i];
      brain_B.S_i[i] = brain_B.Resize1[i];
    }

    StateFlowFunctionsValidationGat(brain_B.H_d, brain_B.S_i,
      &brain_B.StateFlowFunctionsFollowOnePa_l,
      &brain_DWork.StateFlowFunctionsFollowOnePa_l);
    brain_DWork.Obstacle = (brain_B.StateFlowFunctionsFollowOnePa_l.Image != 0.0);
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsFollowOnePa_l.BW[i];
    }

    switch (brain_DWork.is_RecognizePath) {
     case brain_IN_TurnLeft:
      /* During 'TurnLeft': '<S7>:1583' */
      if (fabs(brain_U.CurrentHeading - brain_B.DesiredHeading) < 5.0) {
        /* Transition: '<S7>:1580' */
        /* Exit 'TurnLeft': '<S7>:1583' */
        /* Entry 'TurnRight': '<S7>:1582' */
        brain_DWork.is_RecognizePath = brain_IN_TurnRight;
        brain_B.DesiredHeading = brain_U.CurrentHeading + 30.0;
      } else {
        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = 0.0;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
      }
      break;

     case brain_IN_TurnRight:
      /* During 'TurnRight': '<S7>:1582' */
      if (fabs(brain_U.CurrentHeading - brain_B.DesiredHeading) < 5.0) {
        /* Transition: '<S7>:1581' */
        /* Exit 'TurnRight': '<S7>:1582' */
        /* Entry 'TurnLeft': '<S7>:1583' */
        brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
        brain_B.DesiredHeading = brain_U.CurrentHeading - 15.0;
      } else {
        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = 0.0;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
      }
      break;

     default:
      /* Transition: '<S7>:1579' */
      /* Entry 'TurnLeft': '<S7>:1583' */
      brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
      brain_B.DesiredHeading = brain_U.CurrentHeading - 15.0;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_GetInCorrectState(void)
{
  int32_T i;

  /* During 'GetInCorrectState': '<S7>:1263' */
  if (brain_DWork.OperationalState == -2) {
    /* Transition: '<S7>:1266' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'NotRunning': '<S7>:727' */
    brain_DWork.is_StateFlowFunctions = brain_IN_NotRunning;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
    brain_B.Strafe = 0;
    brain_B.State = -2;
  } else if (brain_DWork.OperationalState == 5) {
    /* Transition: '<S7>:1687' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'JumpHedge': '<S7>:1605' */
    brain_DWork.is_StateFlowFunctions = brain_IN_JumpHedge;
    brain_DWork.Area = 1000;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Strafe = 0;
    brain_DWork.Done = 0.0;
    brain_DWork.Image = 0.0;

    /* Transition: '<S7>:1607' */
    /* Entry 'RecognizeHedge': '<S7>:1633' */
    brain_DWork.is_JumpHedge = brain_IN_RecognizeHedge;

    /* Simulink Function 'GetHedgeValues': '<S7>:1638' */

    /* Constant: '<S33>/Hedge Hue' */
    brain_B.HedgeHue = brain_P.Hedge_Hue;

    /* Constant: '<S33>/Hedge Saturation' */
    brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

    /* Constant: '<S33>/Hedge Value' */
    brain_B.HedgeValue = brain_P.Hedge_Value;
    brain_DWork.H_Hue = brain_B.HedgeHue;
    brain_DWork.H_Sat = brain_B.HedgeSaturation;
    brain_DWork.H_Value = brain_B.HedgeValue;

    /* Simulink Function 'GetForwardVelocity': '<S7>:1697' */

    /* Constant: '<S30>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Vision_Forward_Velocity;
    brain_DWork.Forward = brain_B.HeadingForwardVelocity;
  } else if (brain_DWork.OperationalState == -1) {
    /* Transition: '<S7>:1267' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'ControlledRC': '<S7>:1260' */
    brain_DWork.is_StateFlowFunctions = brain_IN_ControlledRC;
    brain_B.State = -1;
  } else if (brain_DWork.OperationalState == 1) {
    /* Transition: '<S7>:1271' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'Start': '<S7>:1145' */
    brain_DWork.is_StateFlowFunctions = brain_IN_Start;
    brain_DWork.OldHeading = 0.0;
    brain_DWork.DesiredHeadingCount = 0.0;
    brain_B.BuoyCentroidX = 0.0;
    brain_B.BuoyCentroidY = 0.0;
    brain_B.CameraPosition = 2;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
    brain_B.Strafe = 0;

    /* Transition: '<S7>:1529' */
    /* Entry 'GetHeadings': '<S7>:1528' */
    brain_DWork.is_Start = brain_IN_GetHeadings;
  } else if (brain_DWork.OperationalState == 2) {
    /* Transition: '<S7>:1274' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'ValidationGate': '<S7>:1151' */
    brain_DWork.is_StateFlowFunctions = brain_IN_ValidationGate;
    brain_DWork.Obstacle = FALSE;
    brain_DWork.OldObstacle = FALSE;
    brain_DWork.count = 0.0;
    brain_DWork.TrackCount = 0.0;
    brain_B.CameraPosition = 2;

    /* Transition: '<S7>:1476' */
    /* Entry 'GoThoughGate': '<S7>:1462' */
    brain_DWork.is_ValidationGate = brain_IN_GoThoughGate;
  } else if (brain_DWork.OperationalState == 9) {
    /* Transition: '<S7>:1281' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'Finish': '<S7>:1259' */
    brain_DWork.is_StateFlowFunctions = brain_IN_Finish;
    brain_B.State = 6;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
    brain_B.Strafe = 0;
  } else if (brain_DWork.OperationalState == 3) {
    /* Transition: '<S7>:1277' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'FollowOnePath': '<S7>:1546' */
    brain_DWork.is_StateFlowFunctions = brain_IN_FollowOnePath;

    /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

    /* Constant: '<S26>/Constant' */
    brain_B.Constant = brain_P.Track_Desired_Depth;
    brain_B.DesiredDepth = brain_B.Constant;
    brain_B.DesiredHeading = brain_U.CurrentHeading;
    brain_B.CameraPosition = 2;
    brain_DWork.Obstacle = FALSE;

    /* Simulink Function 'MakeHSVImage': '<S7>:1589' */
    for (i = 0; i < 19200; i++) {
      brain_B.H1[i] = brain_B.Resize[i];
      brain_B.S1[i] = brain_B.Resize1[i];
      brain_B.V1[i] = brain_B.Resize2[i];
    }

    /* Embedded MATLAB: '<S19>/PutHSVImageTogether' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S75>:1' */
    /*  This function simply makes an HSV image a single multidimensional */
    /*  signal */
    /* '<S75>:1:7' */
    memset((void *)&brain_B.HSVImage1[0], (int32_T)0.0, 57600U * sizeof(real_T));

    /* '<S75>:1:9' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)&brain_B.HSVImage1[120 * i], (void *)&brain_B.H1[120 * i],
             120U * sizeof(real_T));
    }

    /* '<S75>:1:10' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)&brain_B.HSVImage1[19200 + 120 * i], (void *)&brain_B.S1
             [120 * i], 120U * sizeof(real_T));
    }

    /* '<S75>:1:11' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)&brain_B.HSVImage1[38400 + 120 * i], (void *)&brain_B.V1
             [120 * i], 120U * sizeof(real_T));
    }

    /* Transition: '<S7>:1547' */
    /* Entry 'RecognizePath': '<S7>:1578' */
    brain_DWork.is_FollowOnePath = brain_IN_RecognizePath;

    /* Transition: '<S7>:1579' */
    /* Entry 'TurnLeft': '<S7>:1583' */
    brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
    brain_B.DesiredHeading = brain_U.CurrentHeading - 15.0;
  } else if (brain_DWork.OperationalState == 4) {
    /* Transition: '<S7>:1280' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'Buoys': '<S7>:1290' */
    brain_DWork.is_StateFlowFunctions = brain_IN_Buoys;

    /* Transition: '<S7>:1291' */
    /* Entry 'FindBuoys': '<S7>:1295' */
    brain_DWork.is_Buoys = brain_IN_FindBuoys;
    brain_DWork.Obstacle = FALSE;
    brain_DWork.OldObstacle = FALSE;
    brain_B.CameraPosition = 0;
    brain_DWork.BuoyCount = 0.0;

    /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

    /* Constant: '<S26>/Constant' */
    brain_B.Constant = brain_P.Track_Desired_Depth;
    brain_B.DesiredDepth = brain_B.Constant;
  } else if (brain_DWork.OperationalState == 6) {
    /* Transition: '<S7>:1731' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'DropMechanism': '<S7>:1728' */
    brain_DWork.is_StateFlowFunctions = brain_IN_DropMechanism;
    brain_DWork.Done = 1.0;
  } else if (brain_DWork.OperationalState == 7) {
    /* Transition: '<S7>:1750' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'LocatePinger': '<S7>:1749' */
    brain_DWork.is_StateFlowFunctions = brain_IN_LocatePinger_m;
    brain_DWork.Done = 1.0;
    brain_DWork.MoveOn = 0.0;

    /* Transition: '<S7>:1822' */
    /* Entry 'GetPingerHeading': '<S7>:1786' */
    brain_DWork.is_LocatePinger = brain_IN_GetPingerHeading;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_DWork.OldDesiredHeading = brain_B.DesiredHeading;

    /* Transition: '<S7>:1826' */
    /* Entry 'FirstDirections': '<S7>:1788' */
    brain_DWork.is_GetPingerHeading = brain_IN_FirstDirections;

    /* Simulink Function 'GetHeadings': '<S7>:1809' */
    brain_DWork.Heading1 = 0.0;
    brain_DWork.Heading2 = 0.0;
  } else {
    if (brain_DWork.OperationalState == 8) {
      /* Transition: '<S7>:1755' */
      /* Exit 'GetInCorrectState': '<S7>:1263' */
      /* Entry 'Breach': '<S7>:1752' */
      brain_DWork.is_StateFlowFunctions = brain_IN_Breach;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Vertical = -127;
      brain_B.Strafe = 0;

      /* Transition: '<S7>:1766' */
      /* Entry 'GoUpNCheck': '<S7>:1765' */
      brain_DWork.is_Breach = brain_IN_GoUpNCheck;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_GetStrafeDirection(real_T sf_AxisDif)
{
  real_T sf_StrafeDir1;

  /* Embedded MATLAB Function 'GetStrafeDirection': '<S7>:1630' */
  /*  This function determines the direction the AUV should be strafing based */
  /*  on the initial major axis length change when strafing right */
  if (sf_AxisDif < 0.0) {
    /* '<S7>:1630:5' */
    /* '<S7>:1630:6' */
    sf_StrafeDir1 = -1.0;
  } else {
    /* '<S7>:1630:8' */
    sf_StrafeDir1 = 1.0;
  }

  /*  StrafeDir = -1 corresponds to strafing left */
  /*  StrafeDir = 1 corresponds to strafing right */
  return sf_StrafeDir1;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void exit_internal_GetInitialDirecti(void)
{
  if (brain_DWork.is_GetInitialDirection == brain_IN_Move_m) {
    /* Exit 'Move': '<S7>:1628' */
    brain_B.Strafe = 0;
    brain_DWork.is_GetInitialDirection = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
  } else {
    brain_DWork.is_GetInitialDirection = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'CompareAxisRatio': '<S7>:1629' */
    /* Exit 'GetMajorAxis': '<S7>:1627' */
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_GetInitialDirection(void)
{
  int32_T i;

  /* During 'GetInitialDirection': '<S7>:1623' */
  if ((brain_DWork.OldAxisRatio > 1.0) || (brain_DWork.NewAxisRatio > 1.0)) {
    /* Transition: '<S7>:1606' */
    exit_internal_GetInitialDirecti();

    /* Exit 'GetInitialDirection': '<S7>:1623' */
    /* Entry 'ApproachHedge': '<S7>:1613' */
    brain_DWork.is_JumpHedge = brain_IN_ApproachHedge;
  } else if (brain_DWork.MoveOn == 1.0) {
    /* Transition: '<S7>:1610' */
    exit_internal_GetInitialDirecti();

    /* Exit 'GetInitialDirection': '<S7>:1623' */
    /* Entry 'IncreaseAxisRatio': '<S7>:1617' */
    brain_DWork.is_JumpHedge = brain_IN_IncreaseAxisRatio;

    /* Transition: '<S7>:1618' */
    /* Entry 'Move': '<S7>:1621' */
    brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
    brain_DWork.temporalCounter_i1 = 0U;
  } else {
    switch (brain_DWork.is_GetInitialDirection) {
     case brain_IN_CompareAxisRatio:
      break;

     case brain_IN_GetMajorAxis:
      /* During 'GetMajorAxis': '<S7>:1627' */
      /* Transition: '<S7>:1626' */
      /* Exit 'GetMajorAxis': '<S7>:1627' */
      /* Entry 'Move': '<S7>:1628' */
      brain_DWork.is_GetInitialDirection = brain_IN_Move_m;
      brain_DWork.temporalCounter_i1 = 0U;
      break;

     case brain_IN_Move_m:
      /* During 'Move': '<S7>:1628' */
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 10U) {
        /* Transition: '<S7>:1625' */
        /* Exit 'Move': '<S7>:1628' */
        brain_B.Strafe = 0;

        /* Entry 'CompareAxisRatio': '<S7>:1629' */
        brain_DWork.is_GetInitialDirection = brain_IN_CompareAxisRatio;

        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_o[i] = brain_B.Resize1[i];
          brain_B.V_o[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)&brain_B.LabMatrix_i[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        brain_B.Num_Colors_p = brain_DWork.num_colors;
        brain_B.B_Hue_m = brain_DWork.H_Hue;
        brain_B.B_Sat_e = brain_DWork.H_Sat;
        brain_B.B_Value_cu = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
          brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
          brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_g[i] = brain_B.BWout[i];
        }

        StateFlowFunctionsJumpHedgeGetA(brain_B.BW_g,
          &brain_B.StateFlowFunctionsJumpHedgeGe_k,
          &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
        brain_DWork.NewAxisRatio =
          brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;
        brain_DWork.StrafeDir = brain_GetStrafeDirection
          (brain_DWork.NewAxisRatio - brain_DWork.OldAxisRatio);
        brain_DWork.MoveOn = 1.0;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)&brain_B.LabMatrix_m[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
               (real_T));
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_o[i] = brain_B.Resize1[i];
          brain_B.V_o[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)&brain_B.LabMatrix_i[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        brain_B.Num_Colors_p = brain_DWork.num_colors;
        brain_B.B_Hue_m = brain_DWork.H_Hue;
        brain_B.B_Sat_e = brain_DWork.H_Sat;
        brain_B.B_Value_cu = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
          brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
          brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_d[i] = brain_B.BWout[i];
        }

        brain_B.ForwardVelocity = 0.0;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_d, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;
        brain_B.Strafe = (int8_T)(40.0 * brain_DWork.StrafeDir);

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)&brain_B.LabMatrix_m[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
               (real_T));
      }
      break;

     default:
      /* Transition: '<S7>:1624' */
      /* Entry 'GetMajorAxis': '<S7>:1627' */
      brain_DWork.is_GetInitialDirection = brain_IN_GetMajorAxis;
      brain_DWork.MoveOn = 0.0;
      brain_DWork.OldAxisRatio = 0.5;
      brain_DWork.StrafeDir = 1.0;

      /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_p[i] = brain_B.Resize[i];
        brain_B.S_o[i] = brain_B.Resize1[i];
        brain_B.V_o[i] = brain_B.Resize2[i];
      }

      StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
        &brain_B.StateFlowFunctionsJumpHedgeIter,
        &brain_DWork.StateFlowFunctionsJumpHedgeIter);
      memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
             &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
             sizeof(real_T));
      brain_DWork.num_colors =
        brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
      memcpy((void *)&brain_DWork.ref_colors[0], (void *)
             &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
             sizeof(real_T));

      /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
      memcpy((void *)&brain_B.LabMatrix_i[0], (void *)&brain_DWork.LabelMatrix[0],
             19200U * sizeof(real_T));
      memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      brain_B.Num_Colors_p = brain_DWork.num_colors;
      brain_B.B_Hue_m = brain_DWork.H_Hue;
      brain_B.B_Sat_e = brain_DWork.H_Sat;
      brain_B.B_Value_cu = brain_DWork.H_Value;
      StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
        brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
        brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

      /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
        brain_B.BW_g[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsJumpHedgeGetA(brain_B.BW_g,
        &brain_B.StateFlowFunctionsJumpHedgeGe_k,
        &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
      brain_DWork.OldAxisRatio =
        brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;

      /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
      memcpy((void *)&brain_B.LabMatrix_m[0], (void *)&brain_DWork.LabelMatrix[0],
             19200U * sizeof(real_T));
      memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m, brain_B.Ref_Colors_j,
        &brain_B.StateFlowFunctionsJumpHedgeShow);
      memcpy((void *)&brain_B.RGBout[0], (void *)
             &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
             (real_T));
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_IncreaseAxisRatio(void)
{
  int32_T i;

  /* During 'IncreaseAxisRatio': '<S7>:1617' */
  if (brain_DWork.NewAxisRatio > 1.0) {
    /* Transition: '<S7>:1609' */
    if (brain_DWork.is_IncreaseAxisRatio == brain_IN_Move) {
      /* Exit 'Move': '<S7>:1621' */
      brain_B.Strafe = 0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.is_IncreaseAxisRatio = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    } else {
      brain_DWork.is_IncreaseAxisRatio = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'CheckAxisRatio': '<S7>:1622' */
    }

    /* Exit 'IncreaseAxisRatio': '<S7>:1617' */
    brain_B.Strafe = 0;
    brain_B.Left = 0;
    brain_B.Right = 0;

    /* Entry 'ApproachHedge': '<S7>:1613' */
    brain_DWork.is_JumpHedge = brain_IN_ApproachHedge;
  } else {
    switch (brain_DWork.is_IncreaseAxisRatio) {
     case brain_IN_CheckAxisRatio:
      /* During 'CheckAxisRatio': '<S7>:1622' */
      /* Transition: '<S7>:1620' */
      /* Exit 'CheckAxisRatio': '<S7>:1622' */
      /* Entry 'Move': '<S7>:1621' */
      brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
      brain_DWork.temporalCounter_i1 = 0U;
      break;

     case brain_IN_Move:
      /* During 'Move': '<S7>:1621' */
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 5U) {
        /* Transition: '<S7>:1619' */
        /* Exit 'Move': '<S7>:1621' */
        brain_B.Strafe = 0;
        brain_B.Left = 0;
        brain_B.Right = 0;

        /* Entry 'CheckAxisRatio': '<S7>:1622' */
        brain_DWork.is_IncreaseAxisRatio = brain_IN_CheckAxisRatio;

        /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
        memcpy((void *)&brain_B.BW_g[0], (void *)&brain_B.BWout[0], 19200U *
               sizeof(real_T));
        StateFlowFunctionsJumpHedgeGetA(brain_B.BW_g,
          &brain_B.StateFlowFunctionsJumpHedgeGe_k,
          &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
        brain_DWork.NewAxisRatio =
          brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_o[i] = brain_B.Resize1[i];
          brain_B.V_o[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)&brain_B.LabMatrix_i[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        brain_B.Num_Colors_p = brain_DWork.num_colors;
        brain_B.B_Hue_m = brain_DWork.H_Hue;
        brain_B.B_Sat_e = brain_DWork.H_Sat;
        brain_B.B_Value_cu = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
          brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
          brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_d[i] = brain_B.BWout[i];
        }

        brain_B.ForwardVelocity = 0.0;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_d, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;
        brain_B.Strafe = (int8_T)(40.0 * brain_DWork.StrafeDir);

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)&brain_B.LabMatrix_m[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
               (real_T));
      }
      break;

     default:
      /* Transition: '<S7>:1618' */
      /* Entry 'Move': '<S7>:1621' */
      brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
      brain_DWork.temporalCounter_i1 = 0U;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_RecognizeHedge(void)
{
  int32_T idxROI;
  int32_T idxStart;
  int32_T err;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  real_T eml_max_votes;
  real_T eml_top_vote;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i;
  int32_T ku;
  int32_T n;
  int32_T i_0;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  real_T rtb_R_idx;
  real_T rtb_T_idx;
  real_T rtb_R_idx_0;
  real_T rtb_T_idx_0;
  real_T rtb_R_idx_1;
  real_T rtb_T_idx_1;

  /* During 'RecognizeHedge': '<S7>:1633' */
  if (brain_DWork.Image == 1.0) {
    /* Transition: '<S7>:1608' */
    /* Exit 'RecognizeHedge': '<S7>:1633' */
    /* Entry 'GetInitialDirection': '<S7>:1623' */
    brain_DWork.is_JumpHedge = brain_IN_GetInitialDirection;

    /* Transition: '<S7>:1624' */
    /* Entry 'GetMajorAxis': '<S7>:1627' */
    brain_DWork.is_GetInitialDirection = brain_IN_GetMajorAxis;
    brain_DWork.MoveOn = 0.0;
    brain_DWork.OldAxisRatio = 0.5;
    brain_DWork.StrafeDir = 1.0;

    /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.H_p[i_0] = brain_B.Resize[i_0];
      brain_B.S_o[i_0] = brain_B.Resize1[i_0];
      brain_B.V_o[i_0] = brain_B.Resize2[i_0];
    }

    StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
      &brain_B.StateFlowFunctionsJumpHedgeIter,
      &brain_DWork.StateFlowFunctionsJumpHedgeIter);
    memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
    memcpy((void *)&brain_DWork.ref_colors[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U * sizeof
           (real_T));

    /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
    memcpy((void *)&brain_B.LabMatrix_i[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.Num_Colors_p = brain_DWork.num_colors;
    brain_B.B_Hue_m = brain_DWork.H_Hue;
    brain_B.B_Sat_e = brain_DWork.H_Sat;
    brain_B.B_Value_cu = brain_DWork.H_Value;
    StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
      brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
      brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

    /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BWout[i_0] = (real_T)
        brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i_0];
      brain_B.BW_g[i_0] = brain_B.BWout[i_0];
    }

    StateFlowFunctionsJumpHedgeGetA(brain_B.BW_g,
      &brain_B.StateFlowFunctionsJumpHedgeGe_k,
      &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
    brain_DWork.OldAxisRatio = brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
    memcpy((void *)&brain_B.LabMatrix_m[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m, brain_B.Ref_Colors_j,
      &brain_B.StateFlowFunctionsJumpHedgeShow);
    memcpy((void *)&brain_B.RGBout[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
           (real_T));
  } else {
    /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.H_p[i_0] = brain_B.Resize[i_0];
      brain_B.S_o[i_0] = brain_B.Resize1[i_0];
      brain_B.V_o[i_0] = brain_B.Resize2[i_0];
    }

    StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
      &brain_B.StateFlowFunctionsJumpHedgeIter,
      &brain_DWork.StateFlowFunctionsJumpHedgeIter);
    memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
    memcpy((void *)&brain_DWork.ref_colors[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U * sizeof
           (real_T));

    /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
    memcpy((void *)&brain_B.LabMatrix_i[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.Num_Colors_p = brain_DWork.num_colors;
    brain_B.B_Hue_m = brain_DWork.H_Hue;
    brain_B.B_Sat_e = brain_DWork.H_Sat;
    brain_B.B_Value_cu = brain_DWork.H_Value;
    StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
      brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
      brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BWout[i_0] = (real_T)
        brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i_0];
    }

    /* Simulink Function 'MaintainHeading': '<S7>:918' */
    brain_B.DesiredHeading1 = brain_B.DesiredHeading;
    brain_B.CurrentHeading1 = brain_U.CurrentHeading;
    brain_B.ForwardVelocity1 = brain_DWork.Forward;
    StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
      brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
      &brain_B.StateFlowFunctionsMaintainHea_d,
      &brain_DWork.StateFlowFunctionsMaintainHea_d);
    brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
    brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

    /* Simulink Function 'MaintainDepth': '<S7>:926' */
    brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
    brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
    brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
      brain_DWork.StateFlowFunctionsMaintainDep_k;
    brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

    /* Sum: '<S37>/Add' */
    rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

    /* SampleTimeMath: '<S132>/TSamp' incorporates:
     *  Gain: '<S131>/Depth Derivative Gain'
     *
     * About '<S132>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

    /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
     *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
     *  Gain: '<S131>/Depth Proportional Gain'
     *  Sum: '<S131>/Sum'
     *  Sum: '<S132>/Diff'
     *  UnitDelay: '<S132>/UD'
     *
     * Block description for '<S132>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S132>/UD':
     *
     *  Store in Global RAM
     */
    rtb_R_idx_1 = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp -
      brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
    rtb_R_idx_1 = floor(rtb_R_idx_1);
    if (rtb_R_idx_1 < 128.0) {
      if (rtb_R_idx_1 >= -128.0) {
        brain_B.DoubleToInt8 = (int8_T)rtb_R_idx_1;
      } else {
        brain_B.DoubleToInt8 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToInt8 = MAX_int8_T;
    }

    /* Update for UnitDelay: '<S132>/UD'
     * Block description for '<S132>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE = rtb_TSamp;

    /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S131>/Depth Integral Gain'
     */
    brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki * rtb_Add)
      + brain_DWork.DepthDiscreteTimeIntegrator_DST;
    if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }

    brain_B.Vertical = brain_B.DoubleToInt8;

    /* Simulink Function 'LookForHedge': '<S7>:1634' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BW_l[i_0] = brain_B.BWout[i_0];

      /* S-Function (svipscalenconvert): '<S34>/Image Data Type Conversion' */
      brain_B.ImageDataTypeConversion_e[i_0] = ((brain_B.BW_l[i_0] == 0.0 ? 0 :
        1) != 0);
    }

    /* S-Function (svipmorphop): '<S34>/Erosion' */
    i = 0;
    ku = 0;
    for (n = 0; n < 123; n++) {
      brain_DWork.Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
    }

    for (i_0 = 0; i_0 < 160; i_0++) {
      memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW[i], (void *)
             &brain_B.ImageDataTypeConversion_e[ku], 120U * sizeof(boolean_T));
      i += 120;
      ku += 120;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[i] = TRUE;
      i++;
    }

    for (i_0 = 161; i_0 < 165; i_0++) {
      for (n = 0; n < 123; n++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW[i] = TRUE;
        i++;
      }
    }

    i = 0;
    ku = 0;
    for (n = 0; n < 160; n++) {
      for (line_idx_3 = 0; line_idx_3 < 120; line_idx_3++) {
        brain_B.Erosion_g[ku] = TRUE;
        for (line_idx_5 = 0; line_idx_5 < brain_DWork.Erosion_NUMNONZ_DW;
             line_idx_5++) {
          if (!brain_DWork.Erosion_ONE_PAD_IMG_DW[i +
              brain_DWork.Erosion_ERODE_OFF_DW[line_idx_5]]) {
            brain_B.Erosion_g[ku] = FALSE;
            line_idx_5 = brain_DWork.Erosion_NUMNONZ_DW;
          }
        }

        i++;
        ku++;
      }

      i += 3;
    }

    /* S-Function (sviphough): '<S34>/Hough Transform' */
    MWVIP_Hough_D(&brain_B.Erosion_g[0], &brain_B.HoughTransform_o1[0],
                  &brain_ConstP.pooled18[0], &brain_ConstP.pooled19, 120, 160,
                  399, 91);

    /* Embedded MATLAB: '<S34>/Are 3 Lines Present' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge/Are 3 Lines Present': '<S128>:1' */
    /*  This function is meant to see if there are 3 lines which approximate a */
    /*  'hedge' in the current frame */
    /* '<S128>:1:5' */
    /* '<S128>:1:6' */
    rtb_R_idx_1 = 0.0;
    rtb_T_idx_1 = 0.0;
    rtb_R_idx_0 = 0.0;
    rtb_T_idx_0 = 0.0;
    rtb_R_idx = 0.0;
    rtb_T_idx = 0.0;

    /*  Find the two vetical lines */
    /* '<S128>:1:12' */
    rtb_Add = 0.0;

    /* '<S128>:1:13' */
    rtb_TSamp = 0.0;

    /* '<S128>:1:14' */
    i = 1;

    /* '<S128>:1:16' */
    ku = 1;

    /* '<S128>:1:17' */
    i_0 = 1;

    /* '<S128>:1:19' */
    for (n = 0; n < 399; n++) {
      /* '<S128>:1:19' */
      /* '<S128>:1:20' */
      for (line_idx_3 = 85; line_idx_3 < 96; line_idx_3++) {
        /* '<S128>:1:20' */
        if (brain_B.HoughTransform_o1[(line_idx_3 - 1) * 399 + n] > rtb_Add) {
          /* '<S128>:1:21' */
          if (fabs(brain_B.HoughTransform_o3[i - 1] -
                   brain_B.HoughTransform_o3[n]) > 20.0) {
            /* '<S128>:1:22' */
            /* '<S128>:1:23' */
            rtb_TSamp = brain_B.HoughTransform_o1[(i_0 - 1) * 399 + (i - 1)];

            /* '<S128>:1:25' */
            i_0 = ku;

            /* '<S128>:1:26' */
            rtb_R_idx_0 = rtb_R_idx_1;

            /* '<S128>:1:27' */
            rtb_T_idx_0 = rtb_T_idx_1;
          }

          /* '<S128>:1:29' */
          rtb_Add = brain_B.HoughTransform_o1[(line_idx_3 - 1) * 399 + n];

          /* '<S128>:1:30' */
          i = n + 1;

          /* '<S128>:1:31' */
          ku = line_idx_3;

          /* '<S128>:1:32' */
          rtb_R_idx_1 = brain_B.HoughTransform_o3[n];

          /* '<S128>:1:33' */
          rtb_T_idx_1 = brain_B.HoughTransform_o2[line_idx_3 - 1];
        } else {
          if ((brain_B.HoughTransform_o1[(line_idx_3 - 1) * 399 + n] > rtb_TSamp)
              && (fabs(brain_B.HoughTransform_o3[i - 1] -
                       brain_B.HoughTransform_o3[n]) > 20.0)) {
            /* '<S128>:1:34' */
            /* '<S128>:1:35' */
            rtb_TSamp = brain_B.HoughTransform_o1[(line_idx_3 - 1) * 399 + n];

            /* '<S128>:1:37' */
            i_0 = line_idx_3;

            /* '<S128>:1:38' */
            rtb_R_idx_0 = brain_B.HoughTransform_o3[n];

            /* '<S128>:1:39' */
            rtb_T_idx_0 = brain_B.HoughTransform_o2[line_idx_3 - 1];
          }
        }
      }
    }

    /*  Find the horizontal line */
    /* '<S128>:1:45' */
    eml_max_votes = 0.0;

    /* '<S128>:1:47' */
    for (ku = 0; ku < 399; ku++) {
      /* '<S128>:1:47' */
      /* '<S128>:1:48' */
      for (i = 0; i < 10; i++) {
        /* '<S128>:1:48' */
        if (brain_B.HoughTransform_o1[399 * i + ku] > eml_max_votes) {
          /* '<S128>:1:49' */
          /* '<S128>:1:50' */
          eml_max_votes = brain_B.HoughTransform_o1[399 * i + ku];

          /* '<S128>:1:52' */
          rtb_R_idx = brain_B.HoughTransform_o3[ku];

          /* '<S128>:1:53' */
          rtb_T_idx = brain_B.HoughTransform_o2[i];
        }
      }

      /* '<S128>:1:56' */
      for (i = 170; i < 181; i++) {
        /* '<S128>:1:56' */
        if (brain_B.HoughTransform_o1[(i - 1) * 399 + ku] > eml_max_votes) {
          /* '<S128>:1:57' */
          /* '<S128>:1:58' */
          eml_max_votes = brain_B.HoughTransform_o1[(i - 1) * 399 + ku];

          /* '<S128>:1:60' */
          rtb_R_idx = brain_B.HoughTransform_o3[ku];

          /* '<S128>:1:61' */
          rtb_T_idx = brain_B.HoughTransform_o2[i - 1];
        }
      }
    }

    /*  Find the most prominent line */
    /* '<S128>:1:67' */
    eml_top_vote = 0.0;

    /* '<S128>:1:70' */
    for (i = 0; i < 399; i++) {
      /* '<S128>:1:70' */
      /* '<S128>:1:71' */
      for (ku = 0; ku < 180; ku++) {
        /* '<S128>:1:71' */
        if (brain_B.HoughTransform_o1[399 * ku + i] > eml_top_vote) {
          /* '<S128>:1:72' */
          /* '<S128>:1:73' */
          eml_top_vote = brain_B.HoughTransform_o1[399 * ku + i];
        }
      }
    }

    /* '<S128>:1:80' */
    brain_B.Image = 0.0;
    if ((eml_top_vote * 0.75 < eml_max_votes) && (eml_top_vote * 0.3 < rtb_Add) &&
        (eml_top_vote * 0.3 < rtb_TSamp)) {
      /* '<S128>:1:81' */
      /* '<S128>:1:82' */
      brain_B.Image = 1.0;
    }

    /* S-Function (sviphoughlines): '<S34>/Hough Lines' */
    n = 0;
    rtb_Add = (rtb_R_idx_1 + 2.2204460492503131E-016) / (cos(rtb_T_idx_1) +
      2.2204460492503131E-016);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[0] = 0;
      brain_B.HoughLines[1] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      n = 1;
    }

    eml_max_votes = (rtb_R_idx_1 + 2.2204460492503131E-016) / (sin(rtb_T_idx_1)
      + 2.2204460492503131E-016);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(eml_max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[(n << 1)] = (int32_T)floor((real_T)(int32_T)rtb_TSamp +
        0.5);
      brain_B.HoughLines[1 + (n << 1)] = 0;
      n++;
    }

    /* part-3: Right vertical axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (eml_max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[(n << 1)] = (int32_T)floor((real_T)(int32_T)rtb_TSamp
          + 0.5);
        brain_B.HoughLines[1 + (n << 1)] = 159;
        n++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / eml_max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[(n << 1)] = 119;
        brain_B.HoughLines[1 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        n++;
      }
    }

    if (n < 2) {
      brain_B.HoughLines[0] = -1;
      brain_B.HoughLines[1] = -1;
      brain_B.HoughLines[2] = -1;
      brain_B.HoughLines[3] = -1;
    }

    n = 0;
    rtb_Add = (rtb_R_idx_0 + 2.2204460492503131E-016) / (cos(rtb_T_idx_0) +
      2.2204460492503131E-016);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[4] = 0;
      brain_B.HoughLines[5] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      n = 1;
    }

    eml_max_votes = (rtb_R_idx_0 + 2.2204460492503131E-016) / (sin(rtb_T_idx_0)
      + 2.2204460492503131E-016);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(eml_max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[4 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
        rtb_TSamp + 0.5);
      brain_B.HoughLines[5 + (n << 1)] = 0;
      n++;
    }

    /* part-3: Right vertical axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (eml_max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[4 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        brain_B.HoughLines[5 + (n << 1)] = 159;
        n++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / eml_max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[4 + (n << 1)] = 119;
        brain_B.HoughLines[5 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        n++;
      }
    }

    if (n < 2) {
      brain_B.HoughLines[4] = -1;
      brain_B.HoughLines[5] = -1;
      brain_B.HoughLines[6] = -1;
      brain_B.HoughLines[7] = -1;
    }

    n = 0;
    rtb_Add = (rtb_R_idx + 2.2204460492503131E-016) / (cos(rtb_T_idx) +
      2.2204460492503131E-016);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[8] = 0;
      brain_B.HoughLines[9] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      n = 1;
    }

    eml_max_votes = (rtb_R_idx + 2.2204460492503131E-016) / (sin(rtb_T_idx) +
      2.2204460492503131E-016);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(eml_max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[8 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
        rtb_TSamp + 0.5);
      brain_B.HoughLines[9 + (n << 1)] = 0;
      n++;
    }

    /* part-3: Right vertical axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (eml_max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[8 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        brain_B.HoughLines[9 + (n << 1)] = 159;
        n++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (n < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / eml_max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[8 + (n << 1)] = 119;
        brain_B.HoughLines[9 + (n << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        n++;
      }
    }

    if (n < 2) {
      brain_B.HoughLines[8] = -1;
      brain_B.HoughLines[9] = -1;
      brain_B.HoughLines[10] = -1;
      brain_B.HoughLines[11] = -1;
    }

    /* S-Function (svipdrawshapes): '<S34>/Draw Shapes' */
    /* Copy the image from input to output. */
    memcpy((void *)&brain_B.DrawShapes[0], (void *)&brain_B.BW_l[0], 19200U *
           sizeof(real_T));
    idxStart = 0;
    for (idxROI = 0; idxROI < 3; idxROI++) {
      for (i_0 = 0; i_0 < 1; i_0 = 1) {
        n = brain_B.HoughLines[idxStart];
        line_idx_2 = brain_B.HoughLines[idxStart + 1];
        line_idx_3 = brain_B.HoughLines[idxStart + 2];
        line_idx_4 = brain_B.HoughLines[idxStart + 3];
        if ((brain_B.HoughLines[idxStart] != line_idx_3) || (line_idx_2 !=
             line_idx_4)) {
          isInBound = FALSE;

          /* Find the visible portion of a line. */
          visited = FALSE;
          visited_0 = FALSE;
          done = FALSE;
          line_idx_5 = brain_B.HoughLines[idxStart];
          line_idx = line_idx_2;
          line_idx_1 = line_idx_3;
          line_idx_0 = line_idx_4;
          while (!done) {
            i_0 = 0;
            err = 0;

            /* Determine viewport violations. */
            if (line_idx_5 < 0) {
              i_0 = 4;
            } else {
              if (line_idx_5 > 119) {
                i_0 = 8;
              }
            }

            if (line_idx_1 < 0) {
              err = 4;
            } else {
              if (line_idx_1 > 119) {
                err = 8;
              }
            }

            if (line_idx < 0) {
              i_0 |= 1;
            } else {
              if (line_idx > 159) {
                i_0 |= 2;
              }
            }

            if (line_idx_0 < 0) {
              err |= 1;
            } else {
              if (line_idx_0 > 159) {
                err |= 2;
              }
            }

            if (!((uint32_T)(i_0 | err))) {
              /* Line falls completely within bounds. */
              done = TRUE;
              isInBound = TRUE;
            } else if ((uint32_T)(i_0 & err)) {
              /* Line falls completely out of bounds. */
              done = TRUE;
              isInBound = FALSE;
            } else if ((uint32_T)i_0 != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited) {
                line_idx_5 = n;
                line_idx = line_idx_2;
              }

              i = line_idx_1 - line_idx_5;
              ku = line_idx_0 - line_idx;
              if ((uint32_T)(i_0 & 4)) {
                /* Violated RMin. */
                i_0 = (0 - line_idx_5) * ku;
                if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
                  line_idx += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
                } else {
                  line_idx += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
                }

                line_idx_5 = 0;
                visited = TRUE;
              } else if ((uint32_T)(i_0 & 8)) {
                /* Violated RMax. */
                i_0 = (119 - line_idx_5) * ku;
                if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
                  line_idx += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
                } else {
                  line_idx += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
                }

                line_idx_5 = 119;
                visited = TRUE;
              } else if ((uint32_T)(i_0 & 1)) {
                /* Violated CMin. */
                i_0 = (0 - line_idx) * i;
                if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
                  line_idx_5 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_5 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
                }

                line_idx = 0;
                visited = TRUE;
              } else {
                /* Violated CMax. */
                i_0 = (159 - line_idx) * i;
                if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
                  line_idx_5 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_5 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
                }

                line_idx = 159;
                visited = TRUE;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited_0) {
                line_idx_1 = line_idx_3;
                line_idx_0 = line_idx_4;
              }

              i = line_idx_1 - line_idx_5;
              ku = line_idx_0 - line_idx;
              if ((uint32_T)(err & 4)) {
                /* Violated RMin. */
                i_0 = (0 - line_idx_1) * ku;
                if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
                  line_idx_0 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
                } else {
                  line_idx_0 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
                }

                line_idx_1 = 0;
                visited_0 = TRUE;
              } else if ((uint32_T)(err & 8)) {
                /* Violated RMax. */
                i_0 = (119 - line_idx_1) * ku;
                if (((i_0 >= 0) && (i >= 0)) || ((i_0 < 0) && (i < 0))) {
                  line_idx_0 += (div_s32_floor(i_0 << 1U, i) + 1) >> 1;
                } else {
                  line_idx_0 += -((div_s32_floor((-i_0) << 1U, i) + 1) >> 1);
                }

                line_idx_1 = 119;
                visited_0 = TRUE;
              } else if ((uint32_T)(err & 1)) {
                /* Violated CMin. */
                i_0 = (0 - line_idx_0) * i;
                if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
                  line_idx_1 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_1 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
                }

                line_idx_0 = 0;
                visited_0 = TRUE;
              } else {
                /* Violated CMax. */
                i_0 = (159 - line_idx_0) * i;
                if (((i_0 >= 0) && (ku >= 0)) || ((i_0 < 0) && (ku < 0))) {
                  line_idx_1 += (div_s32_floor(i_0 << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_1 += -((div_s32_floor((-i_0) << 1U, ku) + 1) >> 1);
                }

                line_idx_0 = 159;
                visited_0 = TRUE;
              }
            }
          }

          if (isInBound) {
            /* Draw a line using Bresenham algorithm. */
            /* Initialize the Bresenham algorithm. */
            if (line_idx_1 >= line_idx_5) {
              i = line_idx_1 - line_idx_5;
            } else {
              i = line_idx_5 - line_idx_1;
            }

            if (line_idx_0 >= line_idx) {
              ku = line_idx_0 - line_idx;
            } else {
              ku = line_idx - line_idx_0;
            }

            if (i > ku) {
              line_idx_2 = 1;
              ku = 120;
            } else {
              line_idx_2 = 120;
              ku = 1;
              i = line_idx_5;
              line_idx_5 = line_idx;
              line_idx = i;
              i = line_idx_1;
              line_idx_1 = line_idx_0;
              line_idx_0 = i;
            }

            if (line_idx_5 > line_idx_1) {
              i = line_idx_5;
              line_idx_5 = line_idx_1;
              line_idx_1 = i;
              i = line_idx;
              line_idx = line_idx_0;
              line_idx_0 = i;
            }

            line_idx_3 = line_idx_1 - line_idx_5;
            if (line_idx <= line_idx_0) {
              i = 1;
              n = line_idx_0 - line_idx;
            } else {
              i = -1;
              n = line_idx - line_idx_0;
            }

            err = -((line_idx_3 + 1) >> 1);
            i_0 = line_idx_5 * line_idx_2 + line_idx * ku;
            i = i * ku + line_idx_2;
            for (isInBound = (line_idx_5 <= line_idx_1); isInBound; isInBound =
                 (line_idx_5 <= line_idx_1)) {
              brain_B.DrawShapes[i_0] = 0.8;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              err += n;
              if (err >= 0) {
                err -= line_idx_3;
                i_0 += i;
              } else {
                i_0 += line_idx_2;
              }

              line_idx_5++;
            }
          }
        }

        idxStart += 2;
      }

      idxStart += 2;
    }

    brain_DWork.Image = brain_B.Image;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BWout[i_0] = brain_B.DrawShapes[i_0];
      brain_B.LabMatrix_m[i_0] = brain_DWork.LabelMatrix[i_0];
    }

    memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m, brain_B.Ref_Colors_j,
      &brain_B.StateFlowFunctionsJumpHedgeShow);
    memcpy((void *)&brain_B.RGBout[0], (void *)
           &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
           (real_T));
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_exit_internal_JumpHedge(void)
{
  switch (brain_DWork.is_JumpHedge) {
   case brain_IN_ApproachHedge:
    /* Exit 'ApproachHedge': '<S7>:1613' */
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   case brain_IN_GetInitialDirection:
    if (brain_DWork.is_GetInitialDirection == brain_IN_Move_m) {
      /* Exit 'Move': '<S7>:1628' */
      brain_B.Strafe = 0;
      brain_DWork.is_GetInitialDirection = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    } else {
      brain_DWork.is_GetInitialDirection = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'CompareAxisRatio': '<S7>:1629' */
      /* Exit 'GetMajorAxis': '<S7>:1627' */
    }

    /* Exit 'GetInitialDirection': '<S7>:1623' */
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   case brain_IN_IncreaseAxisRatio:
    if (brain_DWork.is_IncreaseAxisRatio == brain_IN_Move) {
      /* Exit 'Move': '<S7>:1621' */
      brain_B.Strafe = 0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.is_IncreaseAxisRatio = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    } else {
      brain_DWork.is_IncreaseAxisRatio = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'CheckAxisRatio': '<S7>:1622' */
    }

    /* Exit 'IncreaseAxisRatio': '<S7>:1617' */
    brain_B.Strafe = 0;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   case brain_IN_RecognizeHedge:
    /* Exit 'RecognizeHedge': '<S7>:1633' */
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   default:
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'Finished': '<S7>:1657' */
    /* Exit 'GoThroughHedge': '<S7>:1648' */
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_exit_atomic_JumpHedge(void)
{
  /* Exit 'JumpHedge': '<S7>:1605' */
  brain_DWork.is_StateFlowFunctions = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_JumpHedge(void)
{
  int32_T ku;
  int32_T i;
  int32_T n;
  int32_T i_0;
  int32_T outIdx;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW;
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T rtb_BuoyBlobAnalysis;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i_1;
  real_T tmp;

  /* During 'JumpHedge': '<S7>:1605' */
  if (brain_DWork.OperationalState != 5) {
    /* Transition: '<S7>:1688' */
    brain_exit_internal_JumpHedge();
    brain_exit_atomic_JumpHedge();

    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    switch (brain_DWork.is_JumpHedge) {
     case brain_IN_ApproachHedge:
      /* During 'ApproachHedge': '<S7>:1613' */
      if (brain_DWork.Area > 4000) {
        /* Transition: '<S7>:1611' */
        /* Exit 'ApproachHedge': '<S7>:1613' */
        /* Entry 'GoThroughHedge': '<S7>:1648' */
        brain_DWork.is_JumpHedge = brain_IN_GoThroughHedge;
        brain_DWork.temporalCounter_i1 = 0U;
        brain_B.DesiredHeading = brain_U.CurrentHeading;
        brain_B.DesiredDepth = brain_U.CurrentDepth - 2.0;
        brain_B.Strafe = 0;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.H_p[i_1] = brain_B.Resize[i_1];
          brain_B.S_o[i_1] = brain_B.Resize1[i_1];
          brain_B.V_o[i_1] = brain_B.Resize2[i_1];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)&brain_B.LabMatrix_i[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        brain_B.Num_Colors_p = brain_DWork.num_colors;
        brain_B.B_Hue_m = brain_DWork.H_Hue;
        brain_B.B_Sat_e = brain_DWork.H_Sat;
        brain_B.B_Value_cu = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
          brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
          brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BWout[i_1] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i_1];
          brain_B.BW_d[i_1] = brain_B.BWout[i_1];
        }

        brain_B.ForwardVelocity = brain_DWork.Forward;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_d, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;

        /* Simulink Function 'GetArea': '<S7>:1614' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BWout[i_1] =
            brain_B.StateFlowFunctionsJumpHedgeCa_p.DrawMarkers[i_1];
          brain_B.BW_e[i_1] = brain_B.BWout[i_1];

          /* S-Function (svipscalenconvert): '<S27>/Image Data Type Conversion' */
          brain_B.ImageDataTypeConversion_d[i_1] = ((brain_B.BW_e[i_1] == 0.0 ?
            0 : 1) != 0);
        }

        /* S-Function (svipmorphop): '<S27>/Dilation' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 123; n++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1] = FALSE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1] = FALSE;
          i_1++;
          memcpy((void *)&brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1], (void *)
                 &brain_B.ImageDataTypeConversion_d[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1] = FALSE;
          i_1++;
          brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1] = FALSE;
          i_1++;
        }

        for (i = 161; i < 163; i++) {
          for (n = 0; n < 123; n++) {
            brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1] = FALSE;
            i_1++;
          }
        }

        i_1 = 0;
        ku = 0;
        for (n = 0; n < 160; n++) {
          for (outIdx = 0; outIdx < 120; outIdx++) {
            brain_B.Dilation[ku] = FALSE;
            for (i_0 = 0; i_0 < brain_DWork.Dilation_NUMNONZ_DW; i_0++) {
              if (brain_DWork.Dilation_ONE_PAD_IMG_DW[i_1 +
                  brain_DWork.Dilation_DILATE_OFF_DW[i_0]]) {
                brain_B.Dilation[ku] = TRUE;
                i_0 = brain_DWork.Dilation_NUMNONZ_DW;
              }
            }

            i_1++;
            ku++;
          }

          i_1 += 3;
        }

        /* S-Function (svipmorphop): '<S27>/Erosion' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 127; n++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_a[i_1] = TRUE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_a[i_1] = TRUE;
          i_1++;
          memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW_a[i_1], (void *)
                 &brain_B.Dilation[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          for (n = 121; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_a[i_1] = TRUE;
            i_1++;
          }
        }

        for (i = 161; i < 167; i++) {
          for (n = 0; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_a[i_1] = TRUE;
            i_1++;
          }
        }

        for (i_0 = 0; i_0 < 21209; i_0++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW[i_0] = TRUE;
        }

        ku = 0;
        for (i_1 = 0; i_1 < 167; i_1++) {
          for (i = 0; i < 124; i++) {
            brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = TRUE;
            for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_j[0]; i_0++) {
              if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_a[ku +
                  brain_DWork.Erosion_ERODE_OFF_DW_i[i_0]]) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = FALSE;
                i_0 = brain_DWork.Erosion_NUMNONZ_DW_j[0];
              }
            }

            ku++;
          }

          ku += 3;
        }

        n = 1;
        outIdx = 0;
        for (i_1 = 0; i_1 < 160; i_1++) {
          for (i = 1; i < 121; i++) {
            brain_B.Erosion[outIdx] = TRUE;
            for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_j[1]; i_0++) {
              if (!brain_DWork.Erosion_TWO_PAD_IMG_DW[brain_DWork.Erosion_ERODE_OFF_DW_i
                  [i_0 + brain_DWork.Erosion_NUMNONZ_DW_j[0]] + n]) {
                brain_B.Erosion[outIdx] = FALSE;
                i_0 = brain_DWork.Erosion_NUMNONZ_DW_j[1];
              }
            }

            n++;
            outIdx++;
          }

          n += 7;
        }

        /* S-Function (svipblob): '<S27>/Buoy Blob Analysis' */
        maxNumBlobsReached = FALSE;
        for (i_1 = 0; i_1 < 123; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[i_1] = 0U;
        }

        currentLabel = 1U;
        i_1 = 0;
        n = 123;
        for (ku = 0; ku < 160; ku++) {
          for (i = 0; i < 120; i++) {
            brain_DWork.BuoyBlobAnalysis_PAD_DW[n] = (uint8_T)
              (brain_B.Erosion[i_1] ? 255 : 0);
            i_1++;
            n++;
          }

          brain_DWork.BuoyBlobAnalysis_PAD_DW[n] = 0U;
          n++;
          brain_DWork.BuoyBlobAnalysis_PAD_DW[n] = 0U;
          n++;
        }

        for (i_1 = 0; i_1 < 121; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[i_1 + n] = 0U;
        }

        ku = 1;
        stackIdx = 0U;
        for (i = 0; i < 160; i++) {
          n = 1;
          i_0 = ku * 122;
          for (outIdx = 0; outIdx < 120; outIdx++) {
            numBlobs = (uint32_T)(i_0 + n);
            if (brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
              brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
              BuoyBlobAnalysis_NUM_PIX_DW = 1U;
              brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx];
                for (i_1 = 0; i_1 < 8; i_1++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled27[i_1];
                  if (brain_DWork.BuoyBlobAnalysis_PAD_DW[walkerIdx] == 255) {
                    brain_DWork.BuoyBlobAnalysis_PAD_DW[walkerIdx] =
                      currentLabel;
                    BuoyBlobAnalysis_NUM_PIX_DW++;
                    brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BuoyBlobAnalysis_NUM_PIX_DW < brain_P.Min_Blob_Size) ||
                  (BuoyBlobAnalysis_NUM_PIX_DW > brain_P.Max_Blob_Size)) {
                currentLabel--;
              }

              if (currentLabel == 1) {
                maxNumBlobsReached = TRUE;
                i = 160;
                outIdx = 120;
              }

              if (outIdx < 120) {
                currentLabel++;
              }
            }

            n++;
          }

          ku++;
        }

        numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel -
          1);
        for (i_1 = 0; i_1 < (int32_T)numBlobs; i_1++) {
          rtb_BuoyBlobAnalysis = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW;
        }

        for (i_1 = (int32_T)numBlobs; i_1 < 1; i_1 = 1) {
          rtb_BuoyBlobAnalysis = -1;
        }

        /* Embedded MATLAB: '<S27>/Embedded MATLAB Function' */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea/Embedded MATLAB Function': '<S107>:1' */
        /*  This function will choose and return data about the largest blob given a  */
        /*  set of blobs */
        if (rtb_BuoyBlobAnalysis == -1) {
          /* '<S107>:1:5' */
          /* '<S107>:1:7' */
          brain_B.BlobArea = -1.0;
        } else {
          /* '<S107>:1:9' */
          brain_B.BlobArea = (real_T)rtb_BuoyBlobAnalysis;
        }

        brain_DWork.Area = (int32_T)brain_B.BlobArea;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)&brain_B.LabMatrix_m[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
               (real_T));
      }
      break;

     case brain_IN_Finished:
      break;

     case brain_IN_GetInitialDirection:
      brain_GetInitialDirection();
      break;

     case brain_IN_GoThroughHedge:
      /* During 'GoThroughHedge': '<S7>:1648' */
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 25U) {
        /* Transition: '<S7>:1612' */
        /* Exit 'GoThroughHedge': '<S7>:1648' */
        /* Entry 'Finished': '<S7>:1657' */
        brain_DWork.is_JumpHedge = brain_IN_Finished;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Strafe = 0;
        brain_DWork.Done = 1.0;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.H_p[i_1] = brain_B.Resize[i_1];
          brain_B.S_o[i_1] = brain_B.Resize1[i_1];
          brain_B.V_o[i_1] = brain_B.Resize2[i_1];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_o, brain_B.V_o,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0], 19200U *
               sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)&brain_DWork.ref_colors[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0], 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)&brain_B.LabMatrix_i[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_i[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        brain_B.Num_Colors_p = brain_DWork.num_colors;
        brain_B.B_Hue_m = brain_DWork.H_Hue;
        brain_B.B_Sat_e = brain_DWork.H_Sat;
        brain_B.B_Value_cu = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_m, brain_B.B_Sat_e,
          brain_B.B_Value_cu, brain_B.LabMatrix_i, brain_B.Ref_Colors_i,
          brain_B.Num_Colors_p, &brain_B.StateFlowFunctionsJumpHedgeIn_m);
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BWout[i_1] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i_1];
        }

        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_DWork.Forward;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)&brain_B.LabMatrix_m[0], (void *)
               &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
        memcpy((void *)&brain_B.Ref_Colors_j[0], (void *)
               &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_m,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)&brain_B.RGBout[0], (void *)
               &brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0], 57600U * sizeof
               (real_T));
      }
      break;

     case brain_IN_IncreaseAxisRatio:
      brain_IncreaseAxisRatio();
      break;

     case brain_IN_RecognizeHedge:
      brain_RecognizeHedge();
      break;

     default:
      /* Transition: '<S7>:1607' */
      /* Entry 'RecognizeHedge': '<S7>:1633' */
      brain_DWork.is_JumpHedge = brain_IN_RecognizeHedge;

      /* Simulink Function 'GetHedgeValues': '<S7>:1638' */

      /* Constant: '<S33>/Hedge Hue' */
      brain_B.HedgeHue = brain_P.Hedge_Hue;

      /* Constant: '<S33>/Hedge Saturation' */
      brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

      /* Constant: '<S33>/Hedge Value' */
      brain_B.HedgeValue = brain_P.Hedge_Value;
      brain_DWork.H_Hue = brain_B.HedgeHue;
      brain_DWork.H_Sat = brain_B.HedgeSaturation;
      brain_DWork.H_Value = brain_B.HedgeValue;

      /* Simulink Function 'GetForwardVelocity': '<S7>:1697' */

      /* Constant: '<S30>/Heading Forward Velocity' */
      brain_B.HeadingForwardVelocity = brain_P.Vision_Forward_Velocity;
      brain_DWork.Forward = brain_B.HeadingForwardVelocity;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_LocatePinger(void)
{
  real_T sf_differences[16];
  real_T sf_Headings[4];
  int32_T sf_i;
  real_T rtb_Add;
  real_T rtb_TSamp;
  real_T tmp;

  /* During 'LocatePinger': '<S7>:1749' */
  if (brain_DWork.OperationalState != 7) {
    /* Transition: '<S7>:1751' */
    if (brain_DWork.is_LocatePinger == brain_IN_GetPingerHeading) {
      /* Exit 'FirstDirections': '<S7>:1788' */
      brain_DWork.is_GetPingerHeading = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'GetActualDirection': '<S7>:1796' */
      /* Exit 'GoToNext': '<S7>:1807' */
      /* Exit 'SecondDirections': '<S7>:1789' */
      /* Exit 'Turn30Degrees': '<S7>:1790' */
      /* Exit 'GetPingerHeading': '<S7>:1786' */
      brain_DWork.is_LocatePinger = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    } else {
      brain_DWork.is_LocatePinger = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'Finished': '<S7>:1779' */
      /* Exit 'Move': '<S7>:1787' */
    }

    /* Exit 'LocatePinger': '<S7>:1749' */
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;

    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    switch (brain_DWork.is_LocatePinger) {
     case brain_IN_Finished_m:
      /* During 'Finished': '<S7>:1779' */
      /* Transition: '<S7>:1823' */
      /* Exit 'Finished': '<S7>:1779' */
      /* Entry 'Move': '<S7>:1787' */
      brain_DWork.is_LocatePinger = brain_IN_Move_m;
      brain_DWork.temporalCounter_i1 = 0U;
      break;

     case brain_IN_GetPingerHeading:
      /* During 'GetPingerHeading': '<S7>:1786' */
      if (brain_DWork.MoveOn != 0.0) {
        /* Transition: '<S7>:1812' */
        /* Exit 'FirstDirections': '<S7>:1788' */
        brain_DWork.is_GetPingerHeading = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

        /* Exit 'GetActualDirection': '<S7>:1796' */
        /* Exit 'GoToNext': '<S7>:1807' */
        /* Exit 'SecondDirections': '<S7>:1789' */
        /* Exit 'Turn30Degrees': '<S7>:1790' */
        /* Exit 'GetPingerHeading': '<S7>:1786' */
        /* Entry 'Finished': '<S7>:1779' */
        brain_DWork.is_LocatePinger = brain_IN_Finished_m;

        /* Embedded MATLAB Function 'changemeasure': '<S7>:1781' */
        /*  This function determines if the heading changes a large enough amount to  */
        /*  imply that the auv is above the pinger */
        /* '<S7>:1781:5' */
        brain_DWork.Done = 0.0;

        /* '<S7>:1781:7' */
        if (fabs(brain_B.DesiredHeading - brain_DWork.OldDesiredHeading) > 60.0)
        {
          /* '<S7>:1781:9' */
          /* '<S7>:1781:10' */
          brain_DWork.Done = 1.0;
        }
      } else {
        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
        switch (brain_DWork.is_GetPingerHeading) {
         case brain_IN_FirstDirections:
          /* During 'FirstDirections': '<S7>:1788' */
          /* Transition: '<S7>:1794' */
          /* Exit 'FirstDirections': '<S7>:1788' */
          /* Entry 'Turn30Degrees': '<S7>:1790' */
          brain_DWork.is_GetPingerHeading = brain_IN_Turn30Degrees;

          /* Embedded MATLAB Function 'Turn30': '<S7>:1791' */
          /*  This function determines the heading to turn 30 degrees to the right */
          /* '<S7>:1791:4' */
          brain_B.DesiredHeading = brain_U.CurrentHeading + 30.0;
          if (brain_B.DesiredHeading >= 360.0) {
            /* '<S7>:1791:6' */
            /* '<S7>:1791:7' */
            brain_B.DesiredHeading = brain_B.DesiredHeading - 360.0;
          }
          break;

         case brain_IN_GetActualDirection:
          /* During 'GetActualDirection': '<S7>:1796' */
          if (brain_B.DesiredHeading == -1.0) {
            /* Transition: '<S7>:1804' */
            /* Exit 'GetActualDirection': '<S7>:1796' */
            /* Entry 'FirstDirections': '<S7>:1788' */
            brain_DWork.is_GetPingerHeading = brain_IN_FirstDirections;

            /* Simulink Function 'GetHeadings': '<S7>:1809' */
            brain_DWork.Heading1 = 0.0;
            brain_DWork.Heading2 = 0.0;
          } else {
            if (brain_B.DesiredHeading != -1.0) {
              /* Transition: '<S7>:1808' */
              /* Exit 'GetActualDirection': '<S7>:1796' */
              /* Entry 'GoToNext': '<S7>:1807' */
              brain_DWork.is_GetPingerHeading = brain_IN_GoToNext;
              brain_DWork.MoveOn = 1.0;
            }
          }
          break;

         case brain_IN_GoToNext:
          break;

         case brain_IN_SecondDirections:
          /* During 'SecondDirections': '<S7>:1789' */
          /* Transition: '<S7>:1797' */
          /* Exit 'SecondDirections': '<S7>:1789' */
          /* Entry 'GetActualDirection': '<S7>:1796' */
          brain_DWork.is_GetPingerHeading = brain_IN_GetActualDirection;

          /* Embedded MATLAB Function 'ProperHeading': '<S7>:1798' */
          /*  This function finds the two headings that match, giving the actual */
          /*  heading to the pinger */
          /* '<S7>:1798:5' */
          /* '<S7>:1798:7' */
          sf_Headings[0] = 0.0;
          sf_Headings[1] = 0.0;
          sf_Headings[2] = 0.0;
          sf_Headings[3] = 0.0;

          /* '<S7>:1798:9' */
          sf_Headings[0] = brain_DWork.Heading1;

          /* '<S7>:1798:10' */
          sf_Headings[1] = brain_DWork.Heading2;

          /* '<S7>:1798:11' */
          sf_Headings[2] = brain_DWork.Heading3;

          /* '<S7>:1798:12' */
          sf_Headings[3] = brain_DWork.Heading4;

          /* '<S7>:1798:14' */
          for (sf_i = 0; sf_i < 4; sf_i++) {
            /* '<S7>:1798:14' */
            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            sf_differences[sf_i] = fabs(sf_Headings[sf_i] - sf_Headings[0]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            sf_differences[sf_i + 4] = fabs(sf_Headings[sf_i] - sf_Headings[1]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            sf_differences[sf_i + 8] = fabs(sf_Headings[sf_i] - sf_Headings[2]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            sf_differences[sf_i + 12] = fabs(sf_Headings[sf_i] - sf_Headings[3]);
          }

          /* '<S7>:1798:20' */
          sf_i = 1;

          /* '<S7>:1798:21' */
          rtb_Add = 1000.0;

          /* '<S7>:1798:22' */
          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (sf_differences[8] < 1000.0) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = sf_differences[8];

            /* '<S7>:1798:27' */
            sf_i = 1;
          }

          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (sf_differences[12] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = sf_differences[12];

            /* '<S7>:1798:27' */
            sf_i = 1;
          }

          /* '<S7>:1798:22' */
          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (sf_differences[9] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = sf_differences[9];

            /* '<S7>:1798:27' */
            sf_i = 2;
          }

          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (sf_differences[13] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = sf_differences[13];

            /* '<S7>:1798:27' */
            sf_i = 2;
          }

          if (rtb_Add < 5.0) {
            /* '<S7>:1798:33' */
            /* '<S7>:1798:34' */
            brain_B.DesiredHeading = sf_Headings[sf_i - 1];
          } else {
            /* '<S7>:1798:36' */
            brain_B.DesiredHeading = -1.0;
          }
          break;

         case brain_IN_Turn30Degrees:
          /* During 'Turn30Degrees': '<S7>:1790' */
          if (fabs(brain_U.CurrentHeading - brain_B.DesiredHeading) < 5.0) {
            /* Transition: '<S7>:1795' */
            /* Exit 'Turn30Degrees': '<S7>:1790' */
            /* Entry 'SecondDirections': '<S7>:1789' */
            brain_DWork.is_GetPingerHeading = brain_IN_SecondDirections;
            brain_B.Left = 0;
            brain_B.Right = 0;

            /* Simulink Function 'GetHeadings': '<S7>:1809' */
            brain_DWork.Heading3 = 0.0;
            brain_DWork.Heading4 = 0.0;
          } else {
            /* Simulink Function 'MaintainHeading': '<S7>:918' */
            brain_B.DesiredHeading1 = brain_B.DesiredHeading;
            brain_B.CurrentHeading1 = brain_U.CurrentDepth;
            brain_B.ForwardVelocity1 = 0.0;
            StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
              brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
              &brain_B.StateFlowFunctionsMaintainHea_d,
              &brain_DWork.StateFlowFunctionsMaintainHea_d);
            brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
            brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;
          }
          break;

         default:
          /* Transition: '<S7>:1826' */
          /* Entry 'FirstDirections': '<S7>:1788' */
          brain_DWork.is_GetPingerHeading = brain_IN_FirstDirections;

          /* Simulink Function 'GetHeadings': '<S7>:1809' */
          brain_DWork.Heading1 = 0.0;
          brain_DWork.Heading2 = 0.0;
          break;
        }
      }
      break;

     case brain_IN_Move_m:
      /* During 'Move': '<S7>:1787' */
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 15U) {
        /* Transition: '<S7>:1815' */
        /* Exit 'Move': '<S7>:1787' */
        /* Entry 'GetPingerHeading': '<S7>:1786' */
        brain_DWork.is_LocatePinger = brain_IN_GetPingerHeading;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_DWork.OldDesiredHeading = brain_B.DesiredHeading;

        /* Transition: '<S7>:1826' */
        /* Entry 'FirstDirections': '<S7>:1788' */
        brain_DWork.is_GetPingerHeading = brain_IN_FirstDirections;

        /* Simulink Function 'GetHeadings': '<S7>:1809' */
        brain_DWork.Heading1 = 0.0;
        brain_DWork.Heading2 = 0.0;
      } else {
        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_DWork.Forward;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
      }
      break;

     default:
      /* Transition: '<S7>:1822' */
      /* Entry 'GetPingerHeading': '<S7>:1786' */
      brain_DWork.is_LocatePinger = brain_IN_GetPingerHeading;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.OldDesiredHeading = brain_B.DesiredHeading;

      /* Transition: '<S7>:1826' */
      /* Entry 'FirstDirections': '<S7>:1788' */
      brain_DWork.is_GetPingerHeading = brain_IN_FirstDirections;

      /* Simulink Function 'GetHeadings': '<S7>:1809' */
      brain_DWork.Heading1 = 0.0;
      brain_DWork.Heading2 = 0.0;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages_m(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1)
{
  /* Embedded MATLAB Function 'countimages': '<S7>:1159' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  image is recognized by the recognition software */
  if ((sf_Image != 0.0) && (sf_Image == sf_OldImage)) {
    /* '<S7>:1159:6' */
    /* '<S7>:1159:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S7>:1159:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ValidationGate(void)
{
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i;
  real_T tmp;

  /* During 'ValidationGate': '<S7>:1151' */
  if (brain_DWork.OperationalState != 2) {
    /* Transition: '<S7>:1275' */
    /* Exit 'GateDone': '<S7>:1459' */
    brain_DWork.is_ValidationGate = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

    /* Exit 'GoThoughGate': '<S7>:1462' */
    /* Exit 'ValidationGate': '<S7>:1151' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    switch (brain_DWork.is_ValidationGate) {
     case brain_IN_GateDone:
      break;

     case brain_IN_GoThoughGate:
      /* During 'GoThoughGate': '<S7>:1462' */
      if (brain_DWork.TrackCount > 2.0) {
        /* Transition: '<S7>:1463' */
        /* Exit 'GoThoughGate': '<S7>:1462' */
        /* Entry 'GateDone': '<S7>:1459' */
        brain_DWork.is_ValidationGate = brain_IN_GateDone;
        brain_DWork.Done = 1.0;
      } else {
        /* Simulink Function 'LookforTrack': '<S7>:1154' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_c[i] = brain_B.Resize[i];
          brain_B.S_n[i] = brain_B.Resize1[i];
        }

        StateFlowFunctionsValidationGat(brain_B.H_c, brain_B.S_n,
          &brain_B.StateFlowFunctionsValidationG_a,
          &brain_DWork.StateFlowFunctionsValidationG_a);
        brain_DWork.Obstacle = (brain_B.StateFlowFunctionsValidationG_a.Image !=
          0.0);
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsValidationG_a.BW[i];
        }

        brain_DWork.TrackCount = brain_countimages_m((real_T)
          brain_DWork.Obstacle, (real_T)brain_DWork.OldObstacle,
          brain_DWork.count);

        /* Simulink Function 'GetValidationGateForwardVelocity': '<S7>:1152' */

        /* Constant: '<S39>/Heading Forward Velocity' */
        brain_B.HeadingForwardVelocity_o = brain_P.Heading_Forward_Velocity;
        brain_DWork.Forward = brain_B.HeadingForwardVelocity_o;

        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_DWork.Forward;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
        brain_DWork.OldObstacle = brain_DWork.Obstacle;
        brain_DWork.count = brain_DWork.TrackCount;
      }
      break;

     default:
      /* Transition: '<S7>:1476' */
      /* Entry 'GoThoughGate': '<S7>:1462' */
      brain_DWork.is_ValidationGate = brain_IN_GoThoughGate;
      break;
    }
  }
}

/* Model step function */
void brain_step(void)
{
  uint32_T cc;
  uint32_T cc_0;
  uint32_T pos;
  uint32_T neg;
  uint32_T yDiff;
  real32_T cc_1;
  real32_T max;
  real32_T sum;
  int32_T indx;
  int32_T outStep;
  int32_T inStep;
  int32_T n;
  int32_T outStep_0;
  int32_T inStep_0;
  int32_T n_0;
  real32_T Resize2_LineBuffer[480];
  real_T rtb_Add;
  real_T rtb_TSamp;
  real_T tmp;

  /* S-Function (svipchromresamp): '<S5>/Chroma Resampling' incorporates:
   *  Inport: '<Root>/Cb'
   *  Inport: '<Root>/Cr'
   */
  outStep = 0;
  inStep = 0;
  for (n = 0; n < 320; n++) {
    indx = inStep;
    for (outStep_0 = 0; outStep_0 < 240; outStep_0++) {
      inStep_0 = outStep_0 << 1;
      brain_B.ChromaResampling_o1[outStep + inStep_0] = brain_U.Cb[indx];
      brain_B.ChromaResampling_o1[(outStep + inStep_0) + 1] = brain_U.Cb[indx];
      inStep_0 += 480;
      brain_B.ChromaResampling_o1[outStep + inStep_0] = brain_U.Cb[indx];
      brain_B.ChromaResampling_o1[(outStep + inStep_0) + 1] = brain_U.Cb[indx];
      indx++;
    }

    inStep += 240;
    outStep += 960;
  }

  outStep_0 = 0;
  inStep_0 = 0;
  for (n_0 = 0; n_0 < 320; n_0++) {
    indx = inStep_0;
    for (outStep = 0; outStep < 240; outStep++) {
      inStep = outStep << 1;
      brain_B.ChromaResampling_o2[outStep_0 + inStep] = brain_U.Cr[indx];
      brain_B.ChromaResampling_o2[(outStep_0 + inStep) + 1] = brain_U.Cr[indx];
      inStep += 480;
      brain_B.ChromaResampling_o2[outStep_0 + inStep] = brain_U.Cr[indx];
      brain_B.ChromaResampling_o2[(outStep_0 + inStep) + 1] = brain_U.Cr[indx];
      indx++;
    }

    inStep_0 += 240;
    outStep_0 += 960;
  }

  /* S-Function (svipcolorconv): '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' incorporates:
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
    pos = (yDiff * 19077U + (uint32_T)(brain_B.ChromaResampling_o2[outStep] *
            26149)) + 8192U;
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
    neg = (uint32_T)(brain_B.ChromaResampling_o1[outStep] * 6419 +
                     brain_B.ChromaResampling_o2[outStep] * 13320);
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
    pos = (yDiff * 19077U + (uint32_T)(brain_B.ChromaResampling_o1[outStep] *
            33050)) + 8192U;
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
    /* S-Function (svipscalenconvert): '<S5>/Red Data Type Conversion' */
    brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = (real32_T)
      brain_B.RGBVid_R[outStep] / 255.0F;

    /* S-Function (svipscalenconvert): '<S5>/Green Data Type Conversion1' */
    brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = (real32_T)
      brain_B.RGBVid_G[outStep] / 255.0F;

    /* S-Function (svipscalenconvert): '<S5>/Blue Data Type Conversion2' */
    brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = (real32_T)
      brain_B.RGBVid_B[outStep] / 255.0F;
  }

  /* S-Function (svipcolorconv): '<S5>/RGB to HSV Color Space  Conversion' */
  /* temporary variables for in-place operation */
  for (outStep = 0; outStep < 307200; outStep++) {
    /* First get the min and max of the RGB triplet */
    if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] >
        brain_B.RGBtoHSVColorSpaceConversion_o2[outStep]) {
      if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] <
          brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
        sum = brain_B.RGBtoHSVColorSpaceConversion_o2[outStep];
      } else {
        sum = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
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
        sum = brain_B.RGBtoHSVColorSpaceConversion_o1[outStep];
      } else {
        sum = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
      }

      if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] >
          brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) {
        max = brain_B.RGBtoHSVColorSpaceConversion_o2[outStep];
      } else {
        max = brain_B.RGBtoHSVColorSpaceConversion_o3[outStep];
      }
    }

    sum = max - sum;
    if (max != 0.0F) {
      cc_1 = sum / max;
    } else {
      cc_1 = 0.0F;
    }

    if (sum != 0.0F) {
      if (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] == max) {
        sum = (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] -
               brain_B.RGBtoHSVColorSpaceConversion_o3[outStep]) / sum;
      } else if (brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] == max) {
        sum = (brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] -
               brain_B.RGBtoHSVColorSpaceConversion_o1[outStep]) / sum + 2.0F;
      } else {
        sum = (brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] -
               brain_B.RGBtoHSVColorSpaceConversion_o2[outStep]) / sum + 4.0F;
      }

      sum /= 6.0F;
      if (sum < 0.0F) {
        sum++;
      }
    } else {
      sum = 0.0F;
    }

    /* assign the results */
    brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = sum;
    brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = cc_1;
    brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = max;
  }

  /* S-Function (svipresize): '<S5>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  inStep = 0;
  for (n = 0; n < 480; n++) {
    indx = n;
    for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
      n_0 = outStep_0;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o1[brain_ConstP.pooled34[n_0]
          * 480 + n] * brain_ConstP.pooled26[n_0];
        n_0 += 160;
      }

      brain_DWork.Resize_IntBuffer[indx] = sum;
      indx += 480;
    }
  }

  for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize_IntBuffer[outStep_0 * 480]), 480U * sizeof
           (real32_T));
    for (n = 0; n < 120; n++) {
      n_0 = n;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[n_0]] *
          brain_ConstP.pooled25[n_0];
        n_0 += 120;
      }

      brain_B.Resize[inStep] = sum;
      inStep++;
    }
  }

  /* S-Function (svipresize): '<S5>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  inStep = 0;
  for (n = 0; n < 480; n++) {
    indx = n;
    for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
      n_0 = outStep_0;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o2[brain_ConstP.pooled34[n_0]
          * 480 + n] * brain_ConstP.pooled26[n_0];
        n_0 += 160;
      }

      brain_DWork.Resize1_IntBuffer[indx] = sum;
      indx += 480;
    }
  }

  for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize1_IntBuffer[outStep_0 * 480]), 480U * sizeof
           (real32_T));
    for (n = 0; n < 120; n++) {
      n_0 = n;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[n_0]] *
          brain_ConstP.pooled25[n_0];
        n_0 += 120;
      }

      brain_B.Resize1[inStep] = sum;
      inStep++;
    }
  }

  /* S-Function (svipresize): '<S5>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  inStep = 0;
  for (n = 0; n < 480; n++) {
    indx = n;
    for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
      n_0 = outStep_0;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o3[brain_ConstP.pooled34[n_0]
          * 480 + n] * brain_ConstP.pooled26[n_0];
        n_0 += 160;
      }

      brain_DWork.Resize2_IntBuffer[indx] = sum;
      indx += 480;
    }
  }

  for (outStep_0 = 0; outStep_0 < 160; outStep_0++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize2_IntBuffer[outStep_0 * 480]), 480U * sizeof
           (real32_T));
    for (n = 0; n < 120; n++) {
      n_0 = n;
      sum = 0.0F;
      for (inStep_0 = 0; inStep_0 < 8; inStep_0++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[n_0]] *
          brain_ConstP.pooled25[n_0];
        n_0 += 120;
      }

      brain_B.Resize2[inStep] = sum;
      inStep++;
    }
  }

  /* Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Inport: '<Root>/CurrentDepth'
   *  Inport: '<Root>/CurrentHeading'
   *  Inport: '<Root>/RC'
   *  Inport: '<Root>/RC_Depth'
   *  Inport: '<Root>/RC_ForwardVelocity'
   *  Inport: '<Root>/RC_Heading'
   *  Inport: '<Root>/RC_Strafe'
   *  Inport: '<Root>/Status'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.GetBuoyForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack'
   *  SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.GetHedgeValues'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge'
   *  SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage'
   *  SubSystem: '<S7>/StateFlowFunctions.LocatePinger.GetPingerHeading.GetHeadings'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   *  SubSystem: '<S7>/StateManagement.Running.Autonomous.Perform'
   */
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.elapsedTicks = brain_DWork.presentTicks -
    brain_DWork.previousTicks;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
  if ((uint32_T)brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks <= 31U)
  {
    brain_DWork.temporalCounter_i1 = (uint8_T)((uint32_T)
      brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks);
  } else {
    brain_DWork.temporalCounter_i1 = 31U;
  }

  /* Gateway: StateFlow Functions */
  /* During: StateFlow Functions */
  if (brain_DWork.is_active_c1_brain == 0) {
    /* Entry: StateFlow Functions */
    brain_DWork.is_active_c1_brain = 1U;

    /* Entry 'StateManagement': '<S7>:725' */
    brain_DWork.is_active_StateManagement = 1U;

    /* Transition: '<S7>:1138' */
    /* Entry 'NotRunning': '<S7>:1135' */
    brain_DWork.is_StateManagement = brain_IN_NotRunning_m;
    brain_DWork.Done = 0.0;

    /* Entry 'StateFlowFunctions': '<S7>:726' */
    brain_DWork.is_active_StateFlowFunctions = 1U;

    /* Transition: '<S7>:1264' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    /* During 'StateManagement': '<S7>:725' */
    switch (brain_DWork.is_StateManagement) {
     case brain_IN_NotRunning_m:
      /* During 'NotRunning': '<S7>:1135' */
      if (brain_U.Status == 1) {
        /* Transition: '<S7>:1136' */
        /* Exit 'NotRunning': '<S7>:1135' */
        /* Entry 'Running': '<S7>:940' */
        brain_DWork.is_StateManagement = brain_IN_Running;

        /* Transition: '<S7>:941' */
        /* Entry 'Autonomous': '<S7>:945' */
        brain_DWork.is_Running = brain_IN_Autonomous;
        brain_enter_internal_Autonomous();
      } else {
        brain_DWork.OperationalState = -2;
      }
      break;

     case brain_IN_Running:
      /* During 'Running': '<S7>:940' */
      if (brain_U.Status != 1) {
        /* Transition: '<S7>:1137' */
        if (brain_DWork.is_Running == brain_IN_Autonomous) {
          /* Exit 'Breach': '<S7>:1744' */
          brain_DWork.is_Autonomous = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

          /* Exit 'Buoy': '<S7>:1025' */
          /* Exit 'ChooseState': '<S7>:1134' */
          /* Exit 'DropMechanism': '<S7>:1722' */
          /* Exit 'Finish': '<S7>:1064' */
          /* Exit 'FollowOnePath1': '<S7>:1065' */
          /* Exit 'FollowOnePath2': '<S7>:1142' */
          /* Exit 'FollowOnePath3': '<S7>:1718' */
          /* Exit 'FollowOnePath4': '<S7>:1732' */
          /* Exit 'Hedge1': '<S7>:1701' */
          /* Exit 'Hedge2': '<S7>:1735' */
          /* Exit 'LocatePinger': '<S7>:1739' */
          /* Exit 'Start': '<S7>:1019' */
          /* Exit 'ValidationGate': '<S7>:1121' */
          /* Exit 'Autonomous': '<S7>:945' */
          brain_DWork.is_Running = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
        } else {
          /* Exit 'ControlledRC': '<S7>:944' */
          brain_DWork.is_Running = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
        }

        /* Exit 'Running': '<S7>:940' */
        /* Entry 'NotRunning': '<S7>:1135' */
        brain_DWork.is_StateManagement = brain_IN_NotRunning_m;
        brain_DWork.Done = 0.0;
      } else {
        switch (brain_DWork.is_Running) {
         case brain_IN_Autonomous:
          brain_Autonomous();
          break;

         case brain_IN_ControlledRC_m:
          /* During 'ControlledRC': '<S7>:944' */
          if ((int32_T)brain_U.RC == 0) {
            /* Transition: '<S7>:943' */
            /* Exit 'ControlledRC': '<S7>:944' */
            /* Entry 'Autonomous': '<S7>:945' */
            brain_DWork.is_Running = brain_IN_Autonomous;
            brain_enter_internal_Autonomous();
          } else {
            brain_DWork.OperationalState = -1;
          }
          break;

         default:
          /* Transition: '<S7>:941' */
          /* Entry 'Autonomous': '<S7>:945' */
          brain_DWork.is_Running = brain_IN_Autonomous;
          brain_enter_internal_Autonomous();
          break;
        }
      }
      break;

     default:
      /* Transition: '<S7>:1138' */
      /* Entry 'NotRunning': '<S7>:1135' */
      brain_DWork.is_StateManagement = brain_IN_NotRunning_m;
      brain_DWork.Done = 0.0;
      break;
    }

    /* During 'StateFlowFunctions': '<S7>:726' */
    switch (brain_DWork.is_StateFlowFunctions) {
     case brain_IN_Breach:
      /* During 'Breach': '<S7>:1752' */
      if (brain_DWork.OperationalState != 8) {
        /* Transition: '<S7>:1756' */
        /* Exit 'Done': '<S7>:1768' */
        brain_DWork.is_Breach = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

        /* Exit 'GoUpNCheck': '<S7>:1765' */
        /* Exit 'MakeSure': '<S7>:1767' */
        /* Exit 'Breach': '<S7>:1752' */
        brain_B.Vertical = 0;

        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      } else {
        switch (brain_DWork.is_Breach) {
         case brain_IN_Done_m:
          break;

         case brain_IN_GoUpNCheck:
          /* During 'GoUpNCheck': '<S7>:1765' */
          if (brain_U.CurrentDepth < 0.5) {
            /* Transition: '<S7>:1769' */
            /* Exit 'GoUpNCheck': '<S7>:1765' */
            /* Entry 'MakeSure': '<S7>:1767' */
            brain_DWork.is_Breach = brain_IN_MakeSure;
            brain_DWork.temporalCounter_i1 = 0U;
          }
          break;

         case brain_IN_MakeSure:
          /* During 'MakeSure': '<S7>:1767' */
          if ((uint32_T)brain_DWork.temporalCounter_i1 >= 15U) {
            /* Transition: '<S7>:1770' */
            /* Exit 'MakeSure': '<S7>:1767' */
            /* Entry 'Done': '<S7>:1768' */
            brain_DWork.is_Breach = brain_IN_Done_m;
            brain_DWork.Done = 1.0;
          }
          break;

         default:
          /* Transition: '<S7>:1766' */
          /* Entry 'GoUpNCheck': '<S7>:1765' */
          brain_DWork.is_Breach = brain_IN_GoUpNCheck;
          break;
        }
      }
      break;

     case brain_IN_Buoys:
      brain_Buoys();
      break;

     case brain_IN_ControlledRC:
      /* During 'ControlledRC': '<S7>:1260' */
      if (brain_DWork.OperationalState != -1) {
        /* Transition: '<S7>:1268' */
        /* Exit 'ControlledRC': '<S7>:1260' */
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Strafe = 0;

        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      } else {
        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_U.RC_Depth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S37>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S132>/TSamp' incorporates:
         *  Gain: '<S131>/Depth Derivative Gain'
         *
         * About '<S132>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S37>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator'
         *  Gain: '<S131>/Depth Proportional Gain'
         *  Sum: '<S131>/Sum'
         *  Sum: '<S132>/Diff'
         *  UnitDelay: '<S132>/UD'
         *
         * Block description for '<S132>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE))
          + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        tmp = floor(tmp);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)tmp;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S132>/UD'
         * Block description for '<S132>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S131>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S131>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          rtb_Add) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;

        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_U.RC_Heading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_U.RC_ForwardVelocity;
        StateFlowFunctionsMaintainHeadi(brain_B.DesiredHeading1,
          brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
          &brain_B.StateFlowFunctionsMaintainHea_d,
          &brain_DWork.StateFlowFunctionsMaintainHea_d);
        brain_B.Left = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint8;
        brain_B.Right = brain_B.StateFlowFunctionsMaintainHea_d.DoubleToint1;
        brain_B.Strafe = (int8_T)brain_U.RC_Strafe;
      }
      break;

     case brain_IN_DropMechanism:
      /* During 'DropMechanism': '<S7>:1728' */
      if (brain_DWork.OperationalState != 6) {
        /* Transition: '<S7>:1730' */
        /* Exit 'DropMechanism': '<S7>:1728' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      }
      break;

     case brain_IN_Finish:
      /* During 'Finish': '<S7>:1259' */
      if (brain_DWork.OperationalState != 9) {
        /* Transition: '<S7>:1282' */
        /* Exit 'Finish': '<S7>:1259' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      }
      break;

     case brain_IN_FollowOnePath:
      /* During 'FollowOnePath': '<S7>:1546' */
      if (brain_DWork.OperationalState != 3) {
        /* Transition: '<S7>:1276' */
        switch (brain_DWork.is_FollowOnePath) {
         case brain_IN_OnePath:
          if (brain_DWork.is_OnePath == brain_IN_AlignWithPath) {
            /* Exit 'AlignWithPath': '<S7>:1559' */
            brain_DWork.is_OnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
          } else {
            brain_DWork.is_OnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

            /* Exit 'Done': '<S7>:1553' */
            /* Exit 'PositionOver': '<S7>:1554' */
          }

          /* Exit 'OnePath': '<S7>:1549' */
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
          break;

         case brain_IN_RecognizePath:
          /* Exit 'TurnLeft': '<S7>:1583' */
          brain_DWork.is_RecognizePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

          /* Exit 'TurnRight': '<S7>:1582' */
          /* Exit 'RecognizePath': '<S7>:1578' */
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
          break;

         default:
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
          break;
        }

        /* Exit 'FollowOnePath': '<S7>:1546' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      } else {
        switch (brain_DWork.is_FollowOnePath) {
         case brain_IN_OnePath:
          brain_OnePath();
          break;

         case brain_IN_RecognizePath:
          brain_RecognizePath();
          break;

         default:
          /* Transition: '<S7>:1547' */
          /* Entry 'RecognizePath': '<S7>:1578' */
          brain_DWork.is_FollowOnePath = brain_IN_RecognizePath;

          /* Transition: '<S7>:1579' */
          /* Entry 'TurnLeft': '<S7>:1583' */
          brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
          brain_B.DesiredHeading = brain_U.CurrentHeading - 15.0;
          break;
        }
      }
      break;

     case brain_IN_GetInCorrectState:
      brain_GetInCorrectState();
      break;

     case brain_IN_JumpHedge:
      brain_JumpHedge();
      break;

     case brain_IN_LocatePinger_m:
      brain_LocatePinger();
      break;

     case brain_IN_NotRunning:
      /* During 'NotRunning': '<S7>:727' */
      if (brain_DWork.OperationalState != -2) {
        /* Transition: '<S7>:1265' */
        /* Exit 'NotRunning': '<S7>:727' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      }
      break;

     case brain_IN_Start:
      /* During 'Start': '<S7>:1145' */
      if (brain_DWork.OperationalState != 1) {
        /* Transition: '<S7>:1270' */
        if (brain_DWork.is_Start == brain_IN_GetHeadings) {
          /* Exit 'GetHeadings': '<S7>:1528' */
          brain_B.DesiredHeading = brain_U.CurrentHeading;
          brain_DWork.is_Start = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
        } else {
          brain_DWork.is_Start = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

          /* Exit 'StartFinished': '<S7>:1530' */
        }

        /* Exit 'Start': '<S7>:1145' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      } else {
        switch (brain_DWork.is_Start) {
         case brain_IN_GetHeadings:
          /* During 'GetHeadings': '<S7>:1528' */
          if (brain_DWork.DesiredHeadingCount >= 3.0) {
            /* Transition: '<S7>:1531' */
            /* Exit 'GetHeadings': '<S7>:1528' */
            brain_B.DesiredHeading = brain_U.CurrentHeading;

            /* Entry 'StartFinished': '<S7>:1530' */
            brain_DWork.is_Start = brain_IN_StartFinished;
            brain_DWork.Done = 1.0;
          } else {
            /* Embedded MATLAB Function 'InitialHeadingCount': '<S7>:1146' */
            /* '<S7>:1146:3' */
            if ((brain_U.CurrentHeading > brain_DWork.OldHeading - 2.0) &&
                (brain_U.CurrentHeading < brain_DWork.OldHeading + 2.0)) {
              /* '<S7>:1146:5' */
              /* '<S7>:1146:6' */
              brain_DWork.DesiredHeadingCount = brain_DWork.DesiredHeadingCount
                + 1.0;
            } else {
              /* '<S7>:1146:8' */
              brain_DWork.DesiredHeadingCount = 0.0;
            }

            /* '<S7>:1146:10' */
            brain_DWork.OldHeading = brain_U.CurrentHeading;

            /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

            /* Constant: '<S26>/Constant' */
            brain_B.Constant = brain_P.Track_Desired_Depth;
            brain_B.DesiredDepth = brain_B.Constant;
          }
          break;

         case brain_IN_StartFinished:
          break;

         default:
          /* Transition: '<S7>:1529' */
          /* Entry 'GetHeadings': '<S7>:1528' */
          brain_DWork.is_Start = brain_IN_GetHeadings;
          break;
        }
      }
      break;

     case brain_IN_ValidationGate:
      brain_ValidationGate();
      break;

     default:
      /* Transition: '<S7>:1264' */
      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      break;
    }
  }

  /* Outport: '<Root>/CameraPosition' */
  brain_Y.CameraPosition = brain_B.CameraPosition;

  /* Outport: '<Root>/BuoyCentroidX' */
  brain_Y.BuoyCentroidX = brain_B.BuoyCentroidX;

  /* Outport: '<Root>/BuoyCentroidY' */
  brain_Y.BuoyCentroidY = brain_B.BuoyCentroidY;

  /* Embedded MATLAB: '<Root>/Normalize Thrusters to 1' */
  /* Embedded MATLAB Function 'Normalize Thrusters to 1': '<S6>:1' */
  /*  This function changes the thrusters from int8's to doubles and puts them */
  /*  on a scale from -1 to 1 */
  /* '<S6>:1:5' */

  /* Outport: '<Root>/Thrusters' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAt SFunction Inport1'
   */
  brain_Y.Thrusters[0] = (real_T)brain_B.Left / 128.0;
  brain_Y.Thrusters[1] = (real_T)brain_B.Right / 128.0;
  brain_Y.Thrusters[2] = (real_T)brain_B.Strafe / 128.0;
  brain_Y.Thrusters[3] = (real_T)brain_B.Vertical / 128.0;

  /* Outport: '<Root>/State' */
  brain_Y.State = brain_B.State;

  /* Outport: '<Root>/DesiredDepth' */
  brain_Y.DesiredDepth = brain_B.DesiredDepth;

  /* Outport: '<Root>/DesiredHeading' */
  brain_Y.DesiredHeading = brain_B.DesiredHeading;

  /* Outport: '<Root>/BWout' */
  memcpy((void *)(&brain_Y.BWout[0]), (void *)(&brain_B.BWout[0]), 19200U *
         sizeof(real_T));

  /* Outport: '<Root>/RGBout' */
  memcpy((void *)(&brain_Y.RGBout[0]), (void *)(&brain_B.RGBout[0]), 57600U *
         sizeof(real_T));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
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
  (void) memset((void *)brain_M, 0,
                sizeof(RT_MODEL_brain));

  /* block I/O */
  (void) memset(((void *) &brain_B), 0,
                sizeof(BlockIO_brain));

  {
    brain_B.HoughTransform_o2[0] = -1.5707963267948966E+000;
    brain_B.HoughTransform_o2[1] = -1.5533430342749532E+000;
    brain_B.HoughTransform_o2[2] = -1.5358897417550099E+000;
    brain_B.HoughTransform_o2[3] = -1.5184364492350666E+000;
    brain_B.HoughTransform_o2[4] = -1.5009831567151235E+000;
    brain_B.HoughTransform_o2[5] = -1.4835298641951802E+000;
    brain_B.HoughTransform_o2[6] = -1.4660765716752369E+000;
    brain_B.HoughTransform_o2[7] = -1.4486232791552935E+000;
    brain_B.HoughTransform_o2[8] = -1.4311699866353502E+000;
    brain_B.HoughTransform_o2[9] = -1.4137166941154069E+000;
    brain_B.HoughTransform_o2[10] = -1.3962634015954636E+000;
    brain_B.HoughTransform_o2[11] = -1.3788101090755203E+000;
    brain_B.HoughTransform_o2[12] = -1.3613568165555769E+000;
    brain_B.HoughTransform_o2[13] = -1.3439035240356338E+000;
    brain_B.HoughTransform_o2[14] = -1.3264502315156905E+000;
    brain_B.HoughTransform_o2[15] = -1.3089969389957472E+000;
    brain_B.HoughTransform_o2[16] = -1.2915436464758039E+000;
    brain_B.HoughTransform_o2[17] = -1.2740903539558606E+000;
    brain_B.HoughTransform_o2[18] = -1.2566370614359172E+000;
    brain_B.HoughTransform_o2[19] = -1.2391837689159739E+000;
    brain_B.HoughTransform_o2[20] = -1.2217304763960306E+000;
    brain_B.HoughTransform_o2[21] = -1.2042771838760873E+000;
    brain_B.HoughTransform_o2[22] = -1.1868238913561442E+000;
    brain_B.HoughTransform_o2[23] = -1.1693705988362009E+000;
    brain_B.HoughTransform_o2[24] = -1.1519173063162575E+000;
    brain_B.HoughTransform_o2[25] = -1.1344640137963142E+000;
    brain_B.HoughTransform_o2[26] = -1.1170107212763709E+000;
    brain_B.HoughTransform_o2[27] = -1.0995574287564276E+000;
    brain_B.HoughTransform_o2[28] = -1.0821041362364843E+000;
    brain_B.HoughTransform_o2[29] = -1.0646508437165410E+000;
    brain_B.HoughTransform_o2[30] = -1.0471975511965976E+000;
    brain_B.HoughTransform_o2[31] = -1.0297442586766545E+000;
    brain_B.HoughTransform_o2[32] = -1.0122909661567112E+000;
    brain_B.HoughTransform_o2[33] = -9.9483767363676789E-001;
    brain_B.HoughTransform_o2[34] = -9.7738438111682457E-001;
    brain_B.HoughTransform_o2[35] = -9.5993108859688125E-001;
    brain_B.HoughTransform_o2[36] = -9.4247779607693793E-001;
    brain_B.HoughTransform_o2[37] = -9.2502450355699462E-001;
    brain_B.HoughTransform_o2[38] = -9.0757121103705141E-001;
    brain_B.HoughTransform_o2[39] = -8.9011791851710809E-001;
    brain_B.HoughTransform_o2[40] = -8.7266462599716477E-001;
    brain_B.HoughTransform_o2[41] = -8.5521133347722145E-001;
    brain_B.HoughTransform_o2[42] = -8.3775804095727824E-001;
    brain_B.HoughTransform_o2[43] = -8.2030474843733492E-001;
    brain_B.HoughTransform_o2[44] = -8.0285145591739160E-001;
    brain_B.HoughTransform_o2[45] = -7.8539816339744828E-001;
    brain_B.HoughTransform_o2[46] = -7.6794487087750496E-001;
    brain_B.HoughTransform_o2[47] = -7.5049157835756175E-001;
    brain_B.HoughTransform_o2[48] = -7.3303828583761843E-001;
    brain_B.HoughTransform_o2[49] = -7.1558499331767511E-001;
    brain_B.HoughTransform_o2[50] = -6.9813170079773179E-001;
    brain_B.HoughTransform_o2[51] = -6.8067840827778847E-001;
    brain_B.HoughTransform_o2[52] = -6.6322511575784526E-001;
    brain_B.HoughTransform_o2[53] = -6.4577182323790194E-001;
    brain_B.HoughTransform_o2[54] = -6.2831853071795862E-001;
    brain_B.HoughTransform_o2[55] = -6.1086523819801530E-001;
    brain_B.HoughTransform_o2[56] = -5.9341194567807209E-001;
    brain_B.HoughTransform_o2[57] = -5.7595865315812877E-001;
    brain_B.HoughTransform_o2[58] = -5.5850536063818546E-001;
    brain_B.HoughTransform_o2[59] = -5.4105206811824214E-001;
    brain_B.HoughTransform_o2[60] = -5.2359877559829882E-001;
    brain_B.HoughTransform_o2[61] = -5.0614548307835561E-001;
    brain_B.HoughTransform_o2[62] = -4.8869219055841229E-001;
    brain_B.HoughTransform_o2[63] = -4.7123889803846897E-001;
    brain_B.HoughTransform_o2[64] = -4.5378560551852570E-001;
    brain_B.HoughTransform_o2[65] = -4.3633231299858238E-001;
    brain_B.HoughTransform_o2[66] = -4.1887902047863912E-001;
    brain_B.HoughTransform_o2[67] = -4.0142572795869580E-001;
    brain_B.HoughTransform_o2[68] = -3.8397243543875248E-001;
    brain_B.HoughTransform_o2[69] = -3.6651914291880922E-001;
    brain_B.HoughTransform_o2[70] = -3.4906585039886590E-001;
    brain_B.HoughTransform_o2[71] = -3.3161255787892263E-001;
    brain_B.HoughTransform_o2[72] = -3.1415926535897931E-001;
    brain_B.HoughTransform_o2[73] = -2.9670597283903605E-001;
    brain_B.HoughTransform_o2[74] = -2.7925268031909273E-001;
    brain_B.HoughTransform_o2[75] = -2.6179938779914941E-001;
    brain_B.HoughTransform_o2[76] = -2.4434609527920614E-001;
    brain_B.HoughTransform_o2[77] = -2.2689280275926285E-001;
    brain_B.HoughTransform_o2[78] = -2.0943951023931956E-001;
    brain_B.HoughTransform_o2[79] = -1.9198621771937624E-001;
    brain_B.HoughTransform_o2[80] = -1.7453292519943295E-001;
    brain_B.HoughTransform_o2[81] = -1.5707963267948966E-001;
    brain_B.HoughTransform_o2[82] = -1.3962634015954636E-001;
    brain_B.HoughTransform_o2[83] = -1.2217304763960307E-001;
    brain_B.HoughTransform_o2[84] = -1.0471975511965978E-001;
    brain_B.HoughTransform_o2[85] = -8.7266462599716474E-002;
    brain_B.HoughTransform_o2[86] = -6.9813170079773182E-002;
    brain_B.HoughTransform_o2[87] = -5.2359877559829890E-002;
    brain_B.HoughTransform_o2[88] = -3.4906585039886591E-002;
    brain_B.HoughTransform_o2[89] = -1.7453292519943295E-002;
    brain_B.HoughTransform_o2[90] = 0.0;
    brain_B.HoughTransform_o2[91] = 1.7453292519943295E-002;
    brain_B.HoughTransform_o2[92] = 3.4906585039886591E-002;
    brain_B.HoughTransform_o2[93] = 5.2359877559829890E-002;
    brain_B.HoughTransform_o2[94] = 6.9813170079773182E-002;
    brain_B.HoughTransform_o2[95] = 8.7266462599716474E-002;
    brain_B.HoughTransform_o2[96] = 1.0471975511965978E-001;
    brain_B.HoughTransform_o2[97] = 1.2217304763960307E-001;
    brain_B.HoughTransform_o2[98] = 1.3962634015954636E-001;
    brain_B.HoughTransform_o2[99] = 1.5707963267948966E-001;
    brain_B.HoughTransform_o2[100] = 1.7453292519943295E-001;
    brain_B.HoughTransform_o2[101] = 1.9198621771937624E-001;
    brain_B.HoughTransform_o2[102] = 2.0943951023931956E-001;
    brain_B.HoughTransform_o2[103] = 2.2689280275926285E-001;
    brain_B.HoughTransform_o2[104] = 2.4434609527920614E-001;
    brain_B.HoughTransform_o2[105] = 2.6179938779914941E-001;
    brain_B.HoughTransform_o2[106] = 2.7925268031909273E-001;
    brain_B.HoughTransform_o2[107] = 2.9670597283903605E-001;
    brain_B.HoughTransform_o2[108] = 3.1415926535897931E-001;
    brain_B.HoughTransform_o2[109] = 3.3161255787892263E-001;
    brain_B.HoughTransform_o2[110] = 3.4906585039886590E-001;
    brain_B.HoughTransform_o2[111] = 3.6651914291880922E-001;
    brain_B.HoughTransform_o2[112] = 3.8397243543875248E-001;
    brain_B.HoughTransform_o2[113] = 4.0142572795869580E-001;
    brain_B.HoughTransform_o2[114] = 4.1887902047863912E-001;
    brain_B.HoughTransform_o2[115] = 4.3633231299858238E-001;
    brain_B.HoughTransform_o2[116] = 4.5378560551852570E-001;
    brain_B.HoughTransform_o2[117] = 4.7123889803846897E-001;
    brain_B.HoughTransform_o2[118] = 4.8869219055841229E-001;
    brain_B.HoughTransform_o2[119] = 5.0614548307835561E-001;
    brain_B.HoughTransform_o2[120] = 5.2359877559829882E-001;
    brain_B.HoughTransform_o2[121] = 5.4105206811824214E-001;
    brain_B.HoughTransform_o2[122] = 5.5850536063818546E-001;
    brain_B.HoughTransform_o2[123] = 5.7595865315812877E-001;
    brain_B.HoughTransform_o2[124] = 5.9341194567807209E-001;
    brain_B.HoughTransform_o2[125] = 6.1086523819801530E-001;
    brain_B.HoughTransform_o2[126] = 6.2831853071795862E-001;
    brain_B.HoughTransform_o2[127] = 6.4577182323790194E-001;
    brain_B.HoughTransform_o2[128] = 6.6322511575784526E-001;
    brain_B.HoughTransform_o2[129] = 6.8067840827778847E-001;
    brain_B.HoughTransform_o2[130] = 6.9813170079773179E-001;
    brain_B.HoughTransform_o2[131] = 7.1558499331767511E-001;
    brain_B.HoughTransform_o2[132] = 7.3303828583761843E-001;
    brain_B.HoughTransform_o2[133] = 7.5049157835756175E-001;
    brain_B.HoughTransform_o2[134] = 7.6794487087750496E-001;
    brain_B.HoughTransform_o2[135] = 7.8539816339744828E-001;
    brain_B.HoughTransform_o2[136] = 8.0285145591739160E-001;
    brain_B.HoughTransform_o2[137] = 8.2030474843733492E-001;
    brain_B.HoughTransform_o2[138] = 8.3775804095727824E-001;
    brain_B.HoughTransform_o2[139] = 8.5521133347722145E-001;
    brain_B.HoughTransform_o2[140] = 8.7266462599716477E-001;
    brain_B.HoughTransform_o2[141] = 8.9011791851710809E-001;
    brain_B.HoughTransform_o2[142] = 9.0757121103705141E-001;
    brain_B.HoughTransform_o2[143] = 9.2502450355699462E-001;
    brain_B.HoughTransform_o2[144] = 9.4247779607693793E-001;
    brain_B.HoughTransform_o2[145] = 9.5993108859688125E-001;
    brain_B.HoughTransform_o2[146] = 9.7738438111682457E-001;
    brain_B.HoughTransform_o2[147] = 9.9483767363676789E-001;
    brain_B.HoughTransform_o2[148] = 1.0122909661567112E+000;
    brain_B.HoughTransform_o2[149] = 1.0297442586766545E+000;
    brain_B.HoughTransform_o2[150] = 1.0471975511965976E+000;
    brain_B.HoughTransform_o2[151] = 1.0646508437165410E+000;
    brain_B.HoughTransform_o2[152] = 1.0821041362364843E+000;
    brain_B.HoughTransform_o2[153] = 1.0995574287564276E+000;
    brain_B.HoughTransform_o2[154] = 1.1170107212763709E+000;
    brain_B.HoughTransform_o2[155] = 1.1344640137963142E+000;
    brain_B.HoughTransform_o2[156] = 1.1519173063162575E+000;
    brain_B.HoughTransform_o2[157] = 1.1693705988362009E+000;
    brain_B.HoughTransform_o2[158] = 1.1868238913561442E+000;
    brain_B.HoughTransform_o2[159] = 1.2042771838760873E+000;
    brain_B.HoughTransform_o2[160] = 1.2217304763960306E+000;
    brain_B.HoughTransform_o2[161] = 1.2391837689159739E+000;
    brain_B.HoughTransform_o2[162] = 1.2566370614359172E+000;
    brain_B.HoughTransform_o2[163] = 1.2740903539558606E+000;
    brain_B.HoughTransform_o2[164] = 1.2915436464758039E+000;
    brain_B.HoughTransform_o2[165] = 1.3089969389957472E+000;
    brain_B.HoughTransform_o2[166] = 1.3264502315156905E+000;
    brain_B.HoughTransform_o2[167] = 1.3439035240356338E+000;
    brain_B.HoughTransform_o2[168] = 1.3613568165555769E+000;
    brain_B.HoughTransform_o2[169] = 1.3788101090755203E+000;
    brain_B.HoughTransform_o2[170] = 1.3962634015954636E+000;
    brain_B.HoughTransform_o2[171] = 1.4137166941154069E+000;
    brain_B.HoughTransform_o2[172] = 1.4311699866353502E+000;
    brain_B.HoughTransform_o2[173] = 1.4486232791552935E+000;
    brain_B.HoughTransform_o2[174] = 1.4660765716752369E+000;
    brain_B.HoughTransform_o2[175] = 1.4835298641951802E+000;
    brain_B.HoughTransform_o2[176] = 1.5009831567151235E+000;
    brain_B.HoughTransform_o2[177] = 1.5184364492350666E+000;
    brain_B.HoughTransform_o2[178] = 1.5358897417550099E+000;
    brain_B.HoughTransform_o2[179] = 1.5533430342749532E+000;
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
    brain_B.HoughTransform_o2_e[0] = -1.5707963267948966E+000;
    brain_B.HoughTransform_o2_e[1] = -1.5533430342749532E+000;
    brain_B.HoughTransform_o2_e[2] = -1.5358897417550099E+000;
    brain_B.HoughTransform_o2_e[3] = -1.5184364492350666E+000;
    brain_B.HoughTransform_o2_e[4] = -1.5009831567151235E+000;
    brain_B.HoughTransform_o2_e[5] = -1.4835298641951802E+000;
    brain_B.HoughTransform_o2_e[6] = -1.4660765716752369E+000;
    brain_B.HoughTransform_o2_e[7] = -1.4486232791552935E+000;
    brain_B.HoughTransform_o2_e[8] = -1.4311699866353502E+000;
    brain_B.HoughTransform_o2_e[9] = -1.4137166941154069E+000;
    brain_B.HoughTransform_o2_e[10] = -1.3962634015954636E+000;
    brain_B.HoughTransform_o2_e[11] = -1.3788101090755203E+000;
    brain_B.HoughTransform_o2_e[12] = -1.3613568165555769E+000;
    brain_B.HoughTransform_o2_e[13] = -1.3439035240356338E+000;
    brain_B.HoughTransform_o2_e[14] = -1.3264502315156905E+000;
    brain_B.HoughTransform_o2_e[15] = -1.3089969389957472E+000;
    brain_B.HoughTransform_o2_e[16] = -1.2915436464758039E+000;
    brain_B.HoughTransform_o2_e[17] = -1.2740903539558606E+000;
    brain_B.HoughTransform_o2_e[18] = -1.2566370614359172E+000;
    brain_B.HoughTransform_o2_e[19] = -1.2391837689159739E+000;
    brain_B.HoughTransform_o2_e[20] = -1.2217304763960306E+000;
    brain_B.HoughTransform_o2_e[21] = -1.2042771838760873E+000;
    brain_B.HoughTransform_o2_e[22] = -1.1868238913561442E+000;
    brain_B.HoughTransform_o2_e[23] = -1.1693705988362009E+000;
    brain_B.HoughTransform_o2_e[24] = -1.1519173063162575E+000;
    brain_B.HoughTransform_o2_e[25] = -1.1344640137963142E+000;
    brain_B.HoughTransform_o2_e[26] = -1.1170107212763709E+000;
    brain_B.HoughTransform_o2_e[27] = -1.0995574287564276E+000;
    brain_B.HoughTransform_o2_e[28] = -1.0821041362364843E+000;
    brain_B.HoughTransform_o2_e[29] = -1.0646508437165410E+000;
    brain_B.HoughTransform_o2_e[30] = -1.0471975511965976E+000;
    brain_B.HoughTransform_o2_e[31] = -1.0297442586766545E+000;
    brain_B.HoughTransform_o2_e[32] = -1.0122909661567112E+000;
    brain_B.HoughTransform_o2_e[33] = -9.9483767363676789E-001;
    brain_B.HoughTransform_o2_e[34] = -9.7738438111682457E-001;
    brain_B.HoughTransform_o2_e[35] = -9.5993108859688125E-001;
    brain_B.HoughTransform_o2_e[36] = -9.4247779607693793E-001;
    brain_B.HoughTransform_o2_e[37] = -9.2502450355699462E-001;
    brain_B.HoughTransform_o2_e[38] = -9.0757121103705141E-001;
    brain_B.HoughTransform_o2_e[39] = -8.9011791851710809E-001;
    brain_B.HoughTransform_o2_e[40] = -8.7266462599716477E-001;
    brain_B.HoughTransform_o2_e[41] = -8.5521133347722145E-001;
    brain_B.HoughTransform_o2_e[42] = -8.3775804095727824E-001;
    brain_B.HoughTransform_o2_e[43] = -8.2030474843733492E-001;
    brain_B.HoughTransform_o2_e[44] = -8.0285145591739160E-001;
    brain_B.HoughTransform_o2_e[45] = -7.8539816339744828E-001;
    brain_B.HoughTransform_o2_e[46] = -7.6794487087750496E-001;
    brain_B.HoughTransform_o2_e[47] = -7.5049157835756175E-001;
    brain_B.HoughTransform_o2_e[48] = -7.3303828583761843E-001;
    brain_B.HoughTransform_o2_e[49] = -7.1558499331767511E-001;
    brain_B.HoughTransform_o2_e[50] = -6.9813170079773179E-001;
    brain_B.HoughTransform_o2_e[51] = -6.8067840827778847E-001;
    brain_B.HoughTransform_o2_e[52] = -6.6322511575784526E-001;
    brain_B.HoughTransform_o2_e[53] = -6.4577182323790194E-001;
    brain_B.HoughTransform_o2_e[54] = -6.2831853071795862E-001;
    brain_B.HoughTransform_o2_e[55] = -6.1086523819801530E-001;
    brain_B.HoughTransform_o2_e[56] = -5.9341194567807209E-001;
    brain_B.HoughTransform_o2_e[57] = -5.7595865315812877E-001;
    brain_B.HoughTransform_o2_e[58] = -5.5850536063818546E-001;
    brain_B.HoughTransform_o2_e[59] = -5.4105206811824214E-001;
    brain_B.HoughTransform_o2_e[60] = -5.2359877559829882E-001;
    brain_B.HoughTransform_o2_e[61] = -5.0614548307835561E-001;
    brain_B.HoughTransform_o2_e[62] = -4.8869219055841229E-001;
    brain_B.HoughTransform_o2_e[63] = -4.7123889803846897E-001;
    brain_B.HoughTransform_o2_e[64] = -4.5378560551852570E-001;
    brain_B.HoughTransform_o2_e[65] = -4.3633231299858238E-001;
    brain_B.HoughTransform_o2_e[66] = -4.1887902047863912E-001;
    brain_B.HoughTransform_o2_e[67] = -4.0142572795869580E-001;
    brain_B.HoughTransform_o2_e[68] = -3.8397243543875248E-001;
    brain_B.HoughTransform_o2_e[69] = -3.6651914291880922E-001;
    brain_B.HoughTransform_o2_e[70] = -3.4906585039886590E-001;
    brain_B.HoughTransform_o2_e[71] = -3.3161255787892263E-001;
    brain_B.HoughTransform_o2_e[72] = -3.1415926535897931E-001;
    brain_B.HoughTransform_o2_e[73] = -2.9670597283903605E-001;
    brain_B.HoughTransform_o2_e[74] = -2.7925268031909273E-001;
    brain_B.HoughTransform_o2_e[75] = -2.6179938779914941E-001;
    brain_B.HoughTransform_o2_e[76] = -2.4434609527920614E-001;
    brain_B.HoughTransform_o2_e[77] = -2.2689280275926285E-001;
    brain_B.HoughTransform_o2_e[78] = -2.0943951023931956E-001;
    brain_B.HoughTransform_o2_e[79] = -1.9198621771937624E-001;
    brain_B.HoughTransform_o2_e[80] = -1.7453292519943295E-001;
    brain_B.HoughTransform_o2_e[81] = -1.5707963267948966E-001;
    brain_B.HoughTransform_o2_e[82] = -1.3962634015954636E-001;
    brain_B.HoughTransform_o2_e[83] = -1.2217304763960307E-001;
    brain_B.HoughTransform_o2_e[84] = -1.0471975511965978E-001;
    brain_B.HoughTransform_o2_e[85] = -8.7266462599716474E-002;
    brain_B.HoughTransform_o2_e[86] = -6.9813170079773182E-002;
    brain_B.HoughTransform_o2_e[87] = -5.2359877559829890E-002;
    brain_B.HoughTransform_o2_e[88] = -3.4906585039886591E-002;
    brain_B.HoughTransform_o2_e[89] = -1.7453292519943295E-002;
    brain_B.HoughTransform_o2_e[90] = 0.0;
    brain_B.HoughTransform_o2_e[91] = 1.7453292519943295E-002;
    brain_B.HoughTransform_o2_e[92] = 3.4906585039886591E-002;
    brain_B.HoughTransform_o2_e[93] = 5.2359877559829890E-002;
    brain_B.HoughTransform_o2_e[94] = 6.9813170079773182E-002;
    brain_B.HoughTransform_o2_e[95] = 8.7266462599716474E-002;
    brain_B.HoughTransform_o2_e[96] = 1.0471975511965978E-001;
    brain_B.HoughTransform_o2_e[97] = 1.2217304763960307E-001;
    brain_B.HoughTransform_o2_e[98] = 1.3962634015954636E-001;
    brain_B.HoughTransform_o2_e[99] = 1.5707963267948966E-001;
    brain_B.HoughTransform_o2_e[100] = 1.7453292519943295E-001;
    brain_B.HoughTransform_o2_e[101] = 1.9198621771937624E-001;
    brain_B.HoughTransform_o2_e[102] = 2.0943951023931956E-001;
    brain_B.HoughTransform_o2_e[103] = 2.2689280275926285E-001;
    brain_B.HoughTransform_o2_e[104] = 2.4434609527920614E-001;
    brain_B.HoughTransform_o2_e[105] = 2.6179938779914941E-001;
    brain_B.HoughTransform_o2_e[106] = 2.7925268031909273E-001;
    brain_B.HoughTransform_o2_e[107] = 2.9670597283903605E-001;
    brain_B.HoughTransform_o2_e[108] = 3.1415926535897931E-001;
    brain_B.HoughTransform_o2_e[109] = 3.3161255787892263E-001;
    brain_B.HoughTransform_o2_e[110] = 3.4906585039886590E-001;
    brain_B.HoughTransform_o2_e[111] = 3.6651914291880922E-001;
    brain_B.HoughTransform_o2_e[112] = 3.8397243543875248E-001;
    brain_B.HoughTransform_o2_e[113] = 4.0142572795869580E-001;
    brain_B.HoughTransform_o2_e[114] = 4.1887902047863912E-001;
    brain_B.HoughTransform_o2_e[115] = 4.3633231299858238E-001;
    brain_B.HoughTransform_o2_e[116] = 4.5378560551852570E-001;
    brain_B.HoughTransform_o2_e[117] = 4.7123889803846897E-001;
    brain_B.HoughTransform_o2_e[118] = 4.8869219055841229E-001;
    brain_B.HoughTransform_o2_e[119] = 5.0614548307835561E-001;
    brain_B.HoughTransform_o2_e[120] = 5.2359877559829882E-001;
    brain_B.HoughTransform_o2_e[121] = 5.4105206811824214E-001;
    brain_B.HoughTransform_o2_e[122] = 5.5850536063818546E-001;
    brain_B.HoughTransform_o2_e[123] = 5.7595865315812877E-001;
    brain_B.HoughTransform_o2_e[124] = 5.9341194567807209E-001;
    brain_B.HoughTransform_o2_e[125] = 6.1086523819801530E-001;
    brain_B.HoughTransform_o2_e[126] = 6.2831853071795862E-001;
    brain_B.HoughTransform_o2_e[127] = 6.4577182323790194E-001;
    brain_B.HoughTransform_o2_e[128] = 6.6322511575784526E-001;
    brain_B.HoughTransform_o2_e[129] = 6.8067840827778847E-001;
    brain_B.HoughTransform_o2_e[130] = 6.9813170079773179E-001;
    brain_B.HoughTransform_o2_e[131] = 7.1558499331767511E-001;
    brain_B.HoughTransform_o2_e[132] = 7.3303828583761843E-001;
    brain_B.HoughTransform_o2_e[133] = 7.5049157835756175E-001;
    brain_B.HoughTransform_o2_e[134] = 7.6794487087750496E-001;
    brain_B.HoughTransform_o2_e[135] = 7.8539816339744828E-001;
    brain_B.HoughTransform_o2_e[136] = 8.0285145591739160E-001;
    brain_B.HoughTransform_o2_e[137] = 8.2030474843733492E-001;
    brain_B.HoughTransform_o2_e[138] = 8.3775804095727824E-001;
    brain_B.HoughTransform_o2_e[139] = 8.5521133347722145E-001;
    brain_B.HoughTransform_o2_e[140] = 8.7266462599716477E-001;
    brain_B.HoughTransform_o2_e[141] = 8.9011791851710809E-001;
    brain_B.HoughTransform_o2_e[142] = 9.0757121103705141E-001;
    brain_B.HoughTransform_o2_e[143] = 9.2502450355699462E-001;
    brain_B.HoughTransform_o2_e[144] = 9.4247779607693793E-001;
    brain_B.HoughTransform_o2_e[145] = 9.5993108859688125E-001;
    brain_B.HoughTransform_o2_e[146] = 9.7738438111682457E-001;
    brain_B.HoughTransform_o2_e[147] = 9.9483767363676789E-001;
    brain_B.HoughTransform_o2_e[148] = 1.0122909661567112E+000;
    brain_B.HoughTransform_o2_e[149] = 1.0297442586766545E+000;
    brain_B.HoughTransform_o2_e[150] = 1.0471975511965976E+000;
    brain_B.HoughTransform_o2_e[151] = 1.0646508437165410E+000;
    brain_B.HoughTransform_o2_e[152] = 1.0821041362364843E+000;
    brain_B.HoughTransform_o2_e[153] = 1.0995574287564276E+000;
    brain_B.HoughTransform_o2_e[154] = 1.1170107212763709E+000;
    brain_B.HoughTransform_o2_e[155] = 1.1344640137963142E+000;
    brain_B.HoughTransform_o2_e[156] = 1.1519173063162575E+000;
    brain_B.HoughTransform_o2_e[157] = 1.1693705988362009E+000;
    brain_B.HoughTransform_o2_e[158] = 1.1868238913561442E+000;
    brain_B.HoughTransform_o2_e[159] = 1.2042771838760873E+000;
    brain_B.HoughTransform_o2_e[160] = 1.2217304763960306E+000;
    brain_B.HoughTransform_o2_e[161] = 1.2391837689159739E+000;
    brain_B.HoughTransform_o2_e[162] = 1.2566370614359172E+000;
    brain_B.HoughTransform_o2_e[163] = 1.2740903539558606E+000;
    brain_B.HoughTransform_o2_e[164] = 1.2915436464758039E+000;
    brain_B.HoughTransform_o2_e[165] = 1.3089969389957472E+000;
    brain_B.HoughTransform_o2_e[166] = 1.3264502315156905E+000;
    brain_B.HoughTransform_o2_e[167] = 1.3439035240356338E+000;
    brain_B.HoughTransform_o2_e[168] = 1.3613568165555769E+000;
    brain_B.HoughTransform_o2_e[169] = 1.3788101090755203E+000;
    brain_B.HoughTransform_o2_e[170] = 1.3962634015954636E+000;
    brain_B.HoughTransform_o2_e[171] = 1.4137166941154069E+000;
    brain_B.HoughTransform_o2_e[172] = 1.4311699866353502E+000;
    brain_B.HoughTransform_o2_e[173] = 1.4486232791552935E+000;
    brain_B.HoughTransform_o2_e[174] = 1.4660765716752369E+000;
    brain_B.HoughTransform_o2_e[175] = 1.4835298641951802E+000;
    brain_B.HoughTransform_o2_e[176] = 1.5009831567151235E+000;
    brain_B.HoughTransform_o2_e[177] = 1.5184364492350666E+000;
    brain_B.HoughTransform_o2_e[178] = 1.5358897417550099E+000;
    brain_B.HoughTransform_o2_e[179] = 1.5533430342749532E+000;
    brain_B.HoughTransform_o3_n[0] = -199.0;
    brain_B.HoughTransform_o3_n[1] = -198.0;
    brain_B.HoughTransform_o3_n[2] = -197.0;
    brain_B.HoughTransform_o3_n[3] = -196.0;
    brain_B.HoughTransform_o3_n[4] = -195.0;
    brain_B.HoughTransform_o3_n[5] = -194.0;
    brain_B.HoughTransform_o3_n[6] = -193.0;
    brain_B.HoughTransform_o3_n[7] = -192.0;
    brain_B.HoughTransform_o3_n[8] = -191.0;
    brain_B.HoughTransform_o3_n[9] = -190.0;
    brain_B.HoughTransform_o3_n[10] = -189.0;
    brain_B.HoughTransform_o3_n[11] = -188.0;
    brain_B.HoughTransform_o3_n[12] = -187.0;
    brain_B.HoughTransform_o3_n[13] = -186.0;
    brain_B.HoughTransform_o3_n[14] = -185.0;
    brain_B.HoughTransform_o3_n[15] = -184.0;
    brain_B.HoughTransform_o3_n[16] = -183.0;
    brain_B.HoughTransform_o3_n[17] = -182.0;
    brain_B.HoughTransform_o3_n[18] = -181.0;
    brain_B.HoughTransform_o3_n[19] = -180.0;
    brain_B.HoughTransform_o3_n[20] = -179.0;
    brain_B.HoughTransform_o3_n[21] = -178.0;
    brain_B.HoughTransform_o3_n[22] = -177.0;
    brain_B.HoughTransform_o3_n[23] = -176.0;
    brain_B.HoughTransform_o3_n[24] = -175.0;
    brain_B.HoughTransform_o3_n[25] = -174.0;
    brain_B.HoughTransform_o3_n[26] = -173.0;
    brain_B.HoughTransform_o3_n[27] = -172.0;
    brain_B.HoughTransform_o3_n[28] = -171.0;
    brain_B.HoughTransform_o3_n[29] = -170.0;
    brain_B.HoughTransform_o3_n[30] = -169.0;
    brain_B.HoughTransform_o3_n[31] = -168.0;
    brain_B.HoughTransform_o3_n[32] = -167.0;
    brain_B.HoughTransform_o3_n[33] = -166.0;
    brain_B.HoughTransform_o3_n[34] = -165.0;
    brain_B.HoughTransform_o3_n[35] = -164.0;
    brain_B.HoughTransform_o3_n[36] = -163.0;
    brain_B.HoughTransform_o3_n[37] = -162.0;
    brain_B.HoughTransform_o3_n[38] = -161.0;
    brain_B.HoughTransform_o3_n[39] = -160.0;
    brain_B.HoughTransform_o3_n[40] = -159.0;
    brain_B.HoughTransform_o3_n[41] = -158.0;
    brain_B.HoughTransform_o3_n[42] = -157.0;
    brain_B.HoughTransform_o3_n[43] = -156.0;
    brain_B.HoughTransform_o3_n[44] = -155.0;
    brain_B.HoughTransform_o3_n[45] = -154.0;
    brain_B.HoughTransform_o3_n[46] = -153.0;
    brain_B.HoughTransform_o3_n[47] = -152.0;
    brain_B.HoughTransform_o3_n[48] = -151.0;
    brain_B.HoughTransform_o3_n[49] = -150.0;
    brain_B.HoughTransform_o3_n[50] = -149.0;
    brain_B.HoughTransform_o3_n[51] = -148.0;
    brain_B.HoughTransform_o3_n[52] = -147.0;
    brain_B.HoughTransform_o3_n[53] = -146.0;
    brain_B.HoughTransform_o3_n[54] = -145.0;
    brain_B.HoughTransform_o3_n[55] = -144.0;
    brain_B.HoughTransform_o3_n[56] = -143.0;
    brain_B.HoughTransform_o3_n[57] = -142.0;
    brain_B.HoughTransform_o3_n[58] = -141.0;
    brain_B.HoughTransform_o3_n[59] = -140.0;
    brain_B.HoughTransform_o3_n[60] = -139.0;
    brain_B.HoughTransform_o3_n[61] = -138.0;
    brain_B.HoughTransform_o3_n[62] = -137.0;
    brain_B.HoughTransform_o3_n[63] = -136.0;
    brain_B.HoughTransform_o3_n[64] = -135.0;
    brain_B.HoughTransform_o3_n[65] = -134.0;
    brain_B.HoughTransform_o3_n[66] = -133.0;
    brain_B.HoughTransform_o3_n[67] = -132.0;
    brain_B.HoughTransform_o3_n[68] = -131.0;
    brain_B.HoughTransform_o3_n[69] = -130.0;
    brain_B.HoughTransform_o3_n[70] = -129.0;
    brain_B.HoughTransform_o3_n[71] = -128.0;
    brain_B.HoughTransform_o3_n[72] = -127.0;
    brain_B.HoughTransform_o3_n[73] = -126.0;
    brain_B.HoughTransform_o3_n[74] = -125.0;
    brain_B.HoughTransform_o3_n[75] = -124.0;
    brain_B.HoughTransform_o3_n[76] = -123.0;
    brain_B.HoughTransform_o3_n[77] = -122.0;
    brain_B.HoughTransform_o3_n[78] = -121.0;
    brain_B.HoughTransform_o3_n[79] = -120.0;
    brain_B.HoughTransform_o3_n[80] = -119.0;
    brain_B.HoughTransform_o3_n[81] = -118.0;
    brain_B.HoughTransform_o3_n[82] = -117.0;
    brain_B.HoughTransform_o3_n[83] = -116.0;
    brain_B.HoughTransform_o3_n[84] = -115.0;
    brain_B.HoughTransform_o3_n[85] = -114.0;
    brain_B.HoughTransform_o3_n[86] = -113.0;
    brain_B.HoughTransform_o3_n[87] = -112.0;
    brain_B.HoughTransform_o3_n[88] = -111.0;
    brain_B.HoughTransform_o3_n[89] = -110.0;
    brain_B.HoughTransform_o3_n[90] = -109.0;
    brain_B.HoughTransform_o3_n[91] = -108.0;
    brain_B.HoughTransform_o3_n[92] = -107.0;
    brain_B.HoughTransform_o3_n[93] = -106.0;
    brain_B.HoughTransform_o3_n[94] = -105.0;
    brain_B.HoughTransform_o3_n[95] = -104.0;
    brain_B.HoughTransform_o3_n[96] = -103.0;
    brain_B.HoughTransform_o3_n[97] = -102.0;
    brain_B.HoughTransform_o3_n[98] = -101.0;
    brain_B.HoughTransform_o3_n[99] = -100.0;
    brain_B.HoughTransform_o3_n[100] = -99.0;
    brain_B.HoughTransform_o3_n[101] = -98.0;
    brain_B.HoughTransform_o3_n[102] = -97.0;
    brain_B.HoughTransform_o3_n[103] = -96.0;
    brain_B.HoughTransform_o3_n[104] = -95.0;
    brain_B.HoughTransform_o3_n[105] = -94.0;
    brain_B.HoughTransform_o3_n[106] = -93.0;
    brain_B.HoughTransform_o3_n[107] = -92.0;
    brain_B.HoughTransform_o3_n[108] = -91.0;
    brain_B.HoughTransform_o3_n[109] = -90.0;
    brain_B.HoughTransform_o3_n[110] = -89.0;
    brain_B.HoughTransform_o3_n[111] = -88.0;
    brain_B.HoughTransform_o3_n[112] = -87.0;
    brain_B.HoughTransform_o3_n[113] = -86.0;
    brain_B.HoughTransform_o3_n[114] = -85.0;
    brain_B.HoughTransform_o3_n[115] = -84.0;
    brain_B.HoughTransform_o3_n[116] = -83.0;
    brain_B.HoughTransform_o3_n[117] = -82.0;
    brain_B.HoughTransform_o3_n[118] = -81.0;
    brain_B.HoughTransform_o3_n[119] = -80.0;
    brain_B.HoughTransform_o3_n[120] = -79.0;
    brain_B.HoughTransform_o3_n[121] = -78.0;
    brain_B.HoughTransform_o3_n[122] = -77.0;
    brain_B.HoughTransform_o3_n[123] = -76.0;
    brain_B.HoughTransform_o3_n[124] = -75.0;
    brain_B.HoughTransform_o3_n[125] = -74.0;
    brain_B.HoughTransform_o3_n[126] = -73.0;
    brain_B.HoughTransform_o3_n[127] = -72.0;
    brain_B.HoughTransform_o3_n[128] = -71.0;
    brain_B.HoughTransform_o3_n[129] = -70.0;
    brain_B.HoughTransform_o3_n[130] = -69.0;
    brain_B.HoughTransform_o3_n[131] = -68.0;
    brain_B.HoughTransform_o3_n[132] = -67.0;
    brain_B.HoughTransform_o3_n[133] = -66.0;
    brain_B.HoughTransform_o3_n[134] = -65.0;
    brain_B.HoughTransform_o3_n[135] = -64.0;
    brain_B.HoughTransform_o3_n[136] = -63.0;
    brain_B.HoughTransform_o3_n[137] = -62.0;
    brain_B.HoughTransform_o3_n[138] = -61.0;
    brain_B.HoughTransform_o3_n[139] = -60.0;
    brain_B.HoughTransform_o3_n[140] = -59.0;
    brain_B.HoughTransform_o3_n[141] = -58.0;
    brain_B.HoughTransform_o3_n[142] = -57.0;
    brain_B.HoughTransform_o3_n[143] = -56.0;
    brain_B.HoughTransform_o3_n[144] = -55.0;
    brain_B.HoughTransform_o3_n[145] = -54.0;
    brain_B.HoughTransform_o3_n[146] = -53.0;
    brain_B.HoughTransform_o3_n[147] = -52.0;
    brain_B.HoughTransform_o3_n[148] = -51.0;
    brain_B.HoughTransform_o3_n[149] = -50.0;
    brain_B.HoughTransform_o3_n[150] = -49.0;
    brain_B.HoughTransform_o3_n[151] = -48.0;
    brain_B.HoughTransform_o3_n[152] = -47.0;
    brain_B.HoughTransform_o3_n[153] = -46.0;
    brain_B.HoughTransform_o3_n[154] = -45.0;
    brain_B.HoughTransform_o3_n[155] = -44.0;
    brain_B.HoughTransform_o3_n[156] = -43.0;
    brain_B.HoughTransform_o3_n[157] = -42.0;
    brain_B.HoughTransform_o3_n[158] = -41.0;
    brain_B.HoughTransform_o3_n[159] = -40.0;
    brain_B.HoughTransform_o3_n[160] = -39.0;
    brain_B.HoughTransform_o3_n[161] = -38.0;
    brain_B.HoughTransform_o3_n[162] = -37.0;
    brain_B.HoughTransform_o3_n[163] = -36.0;
    brain_B.HoughTransform_o3_n[164] = -35.0;
    brain_B.HoughTransform_o3_n[165] = -34.0;
    brain_B.HoughTransform_o3_n[166] = -33.0;
    brain_B.HoughTransform_o3_n[167] = -32.0;
    brain_B.HoughTransform_o3_n[168] = -31.0;
    brain_B.HoughTransform_o3_n[169] = -30.0;
    brain_B.HoughTransform_o3_n[170] = -29.0;
    brain_B.HoughTransform_o3_n[171] = -28.0;
    brain_B.HoughTransform_o3_n[172] = -27.0;
    brain_B.HoughTransform_o3_n[173] = -26.0;
    brain_B.HoughTransform_o3_n[174] = -25.0;
    brain_B.HoughTransform_o3_n[175] = -24.0;
    brain_B.HoughTransform_o3_n[176] = -23.0;
    brain_B.HoughTransform_o3_n[177] = -22.0;
    brain_B.HoughTransform_o3_n[178] = -21.0;
    brain_B.HoughTransform_o3_n[179] = -20.0;
    brain_B.HoughTransform_o3_n[180] = -19.0;
    brain_B.HoughTransform_o3_n[181] = -18.0;
    brain_B.HoughTransform_o3_n[182] = -17.0;
    brain_B.HoughTransform_o3_n[183] = -16.0;
    brain_B.HoughTransform_o3_n[184] = -15.0;
    brain_B.HoughTransform_o3_n[185] = -14.0;
    brain_B.HoughTransform_o3_n[186] = -13.0;
    brain_B.HoughTransform_o3_n[187] = -12.0;
    brain_B.HoughTransform_o3_n[188] = -11.0;
    brain_B.HoughTransform_o3_n[189] = -10.0;
    brain_B.HoughTransform_o3_n[190] = -9.0;
    brain_B.HoughTransform_o3_n[191] = -8.0;
    brain_B.HoughTransform_o3_n[192] = -7.0;
    brain_B.HoughTransform_o3_n[193] = -6.0;
    brain_B.HoughTransform_o3_n[194] = -5.0;
    brain_B.HoughTransform_o3_n[195] = -4.0;
    brain_B.HoughTransform_o3_n[196] = -3.0;
    brain_B.HoughTransform_o3_n[197] = -2.0;
    brain_B.HoughTransform_o3_n[198] = -1.0;
    brain_B.HoughTransform_o3_n[199] = 0.0;
    brain_B.HoughTransform_o3_n[200] = 1.0;
    brain_B.HoughTransform_o3_n[201] = 2.0;
    brain_B.HoughTransform_o3_n[202] = 3.0;
    brain_B.HoughTransform_o3_n[203] = 4.0;
    brain_B.HoughTransform_o3_n[204] = 5.0;
    brain_B.HoughTransform_o3_n[205] = 6.0;
    brain_B.HoughTransform_o3_n[206] = 7.0;
    brain_B.HoughTransform_o3_n[207] = 8.0;
    brain_B.HoughTransform_o3_n[208] = 9.0;
    brain_B.HoughTransform_o3_n[209] = 10.0;
    brain_B.HoughTransform_o3_n[210] = 11.0;
    brain_B.HoughTransform_o3_n[211] = 12.0;
    brain_B.HoughTransform_o3_n[212] = 13.0;
    brain_B.HoughTransform_o3_n[213] = 14.0;
    brain_B.HoughTransform_o3_n[214] = 15.0;
    brain_B.HoughTransform_o3_n[215] = 16.0;
    brain_B.HoughTransform_o3_n[216] = 17.0;
    brain_B.HoughTransform_o3_n[217] = 18.0;
    brain_B.HoughTransform_o3_n[218] = 19.0;
    brain_B.HoughTransform_o3_n[219] = 20.0;
    brain_B.HoughTransform_o3_n[220] = 21.0;
    brain_B.HoughTransform_o3_n[221] = 22.0;
    brain_B.HoughTransform_o3_n[222] = 23.0;
    brain_B.HoughTransform_o3_n[223] = 24.0;
    brain_B.HoughTransform_o3_n[224] = 25.0;
    brain_B.HoughTransform_o3_n[225] = 26.0;
    brain_B.HoughTransform_o3_n[226] = 27.0;
    brain_B.HoughTransform_o3_n[227] = 28.0;
    brain_B.HoughTransform_o3_n[228] = 29.0;
    brain_B.HoughTransform_o3_n[229] = 30.0;
    brain_B.HoughTransform_o3_n[230] = 31.0;
    brain_B.HoughTransform_o3_n[231] = 32.0;
    brain_B.HoughTransform_o3_n[232] = 33.0;
    brain_B.HoughTransform_o3_n[233] = 34.0;
    brain_B.HoughTransform_o3_n[234] = 35.0;
    brain_B.HoughTransform_o3_n[235] = 36.0;
    brain_B.HoughTransform_o3_n[236] = 37.0;
    brain_B.HoughTransform_o3_n[237] = 38.0;
    brain_B.HoughTransform_o3_n[238] = 39.0;
    brain_B.HoughTransform_o3_n[239] = 40.0;
    brain_B.HoughTransform_o3_n[240] = 41.0;
    brain_B.HoughTransform_o3_n[241] = 42.0;
    brain_B.HoughTransform_o3_n[242] = 43.0;
    brain_B.HoughTransform_o3_n[243] = 44.0;
    brain_B.HoughTransform_o3_n[244] = 45.0;
    brain_B.HoughTransform_o3_n[245] = 46.0;
    brain_B.HoughTransform_o3_n[246] = 47.0;
    brain_B.HoughTransform_o3_n[247] = 48.0;
    brain_B.HoughTransform_o3_n[248] = 49.0;
    brain_B.HoughTransform_o3_n[249] = 50.0;
    brain_B.HoughTransform_o3_n[250] = 51.0;
    brain_B.HoughTransform_o3_n[251] = 52.0;
    brain_B.HoughTransform_o3_n[252] = 53.0;
    brain_B.HoughTransform_o3_n[253] = 54.0;
    brain_B.HoughTransform_o3_n[254] = 55.0;
    brain_B.HoughTransform_o3_n[255] = 56.0;
    brain_B.HoughTransform_o3_n[256] = 57.0;
    brain_B.HoughTransform_o3_n[257] = 58.0;
    brain_B.HoughTransform_o3_n[258] = 59.0;
    brain_B.HoughTransform_o3_n[259] = 60.0;
    brain_B.HoughTransform_o3_n[260] = 61.0;
    brain_B.HoughTransform_o3_n[261] = 62.0;
    brain_B.HoughTransform_o3_n[262] = 63.0;
    brain_B.HoughTransform_o3_n[263] = 64.0;
    brain_B.HoughTransform_o3_n[264] = 65.0;
    brain_B.HoughTransform_o3_n[265] = 66.0;
    brain_B.HoughTransform_o3_n[266] = 67.0;
    brain_B.HoughTransform_o3_n[267] = 68.0;
    brain_B.HoughTransform_o3_n[268] = 69.0;
    brain_B.HoughTransform_o3_n[269] = 70.0;
    brain_B.HoughTransform_o3_n[270] = 71.0;
    brain_B.HoughTransform_o3_n[271] = 72.0;
    brain_B.HoughTransform_o3_n[272] = 73.0;
    brain_B.HoughTransform_o3_n[273] = 74.0;
    brain_B.HoughTransform_o3_n[274] = 75.0;
    brain_B.HoughTransform_o3_n[275] = 76.0;
    brain_B.HoughTransform_o3_n[276] = 77.0;
    brain_B.HoughTransform_o3_n[277] = 78.0;
    brain_B.HoughTransform_o3_n[278] = 79.0;
    brain_B.HoughTransform_o3_n[279] = 80.0;
    brain_B.HoughTransform_o3_n[280] = 81.0;
    brain_B.HoughTransform_o3_n[281] = 82.0;
    brain_B.HoughTransform_o3_n[282] = 83.0;
    brain_B.HoughTransform_o3_n[283] = 84.0;
    brain_B.HoughTransform_o3_n[284] = 85.0;
    brain_B.HoughTransform_o3_n[285] = 86.0;
    brain_B.HoughTransform_o3_n[286] = 87.0;
    brain_B.HoughTransform_o3_n[287] = 88.0;
    brain_B.HoughTransform_o3_n[288] = 89.0;
    brain_B.HoughTransform_o3_n[289] = 90.0;
    brain_B.HoughTransform_o3_n[290] = 91.0;
    brain_B.HoughTransform_o3_n[291] = 92.0;
    brain_B.HoughTransform_o3_n[292] = 93.0;
    brain_B.HoughTransform_o3_n[293] = 94.0;
    brain_B.HoughTransform_o3_n[294] = 95.0;
    brain_B.HoughTransform_o3_n[295] = 96.0;
    brain_B.HoughTransform_o3_n[296] = 97.0;
    brain_B.HoughTransform_o3_n[297] = 98.0;
    brain_B.HoughTransform_o3_n[298] = 99.0;
    brain_B.HoughTransform_o3_n[299] = 100.0;
    brain_B.HoughTransform_o3_n[300] = 101.0;
    brain_B.HoughTransform_o3_n[301] = 102.0;
    brain_B.HoughTransform_o3_n[302] = 103.0;
    brain_B.HoughTransform_o3_n[303] = 104.0;
    brain_B.HoughTransform_o3_n[304] = 105.0;
    brain_B.HoughTransform_o3_n[305] = 106.0;
    brain_B.HoughTransform_o3_n[306] = 107.0;
    brain_B.HoughTransform_o3_n[307] = 108.0;
    brain_B.HoughTransform_o3_n[308] = 109.0;
    brain_B.HoughTransform_o3_n[309] = 110.0;
    brain_B.HoughTransform_o3_n[310] = 111.0;
    brain_B.HoughTransform_o3_n[311] = 112.0;
    brain_B.HoughTransform_o3_n[312] = 113.0;
    brain_B.HoughTransform_o3_n[313] = 114.0;
    brain_B.HoughTransform_o3_n[314] = 115.0;
    brain_B.HoughTransform_o3_n[315] = 116.0;
    brain_B.HoughTransform_o3_n[316] = 117.0;
    brain_B.HoughTransform_o3_n[317] = 118.0;
    brain_B.HoughTransform_o3_n[318] = 119.0;
    brain_B.HoughTransform_o3_n[319] = 120.0;
    brain_B.HoughTransform_o3_n[320] = 121.0;
    brain_B.HoughTransform_o3_n[321] = 122.0;
    brain_B.HoughTransform_o3_n[322] = 123.0;
    brain_B.HoughTransform_o3_n[323] = 124.0;
    brain_B.HoughTransform_o3_n[324] = 125.0;
    brain_B.HoughTransform_o3_n[325] = 126.0;
    brain_B.HoughTransform_o3_n[326] = 127.0;
    brain_B.HoughTransform_o3_n[327] = 128.0;
    brain_B.HoughTransform_o3_n[328] = 129.0;
    brain_B.HoughTransform_o3_n[329] = 130.0;
    brain_B.HoughTransform_o3_n[330] = 131.0;
    brain_B.HoughTransform_o3_n[331] = 132.0;
    brain_B.HoughTransform_o3_n[332] = 133.0;
    brain_B.HoughTransform_o3_n[333] = 134.0;
    brain_B.HoughTransform_o3_n[334] = 135.0;
    brain_B.HoughTransform_o3_n[335] = 136.0;
    brain_B.HoughTransform_o3_n[336] = 137.0;
    brain_B.HoughTransform_o3_n[337] = 138.0;
    brain_B.HoughTransform_o3_n[338] = 139.0;
    brain_B.HoughTransform_o3_n[339] = 140.0;
    brain_B.HoughTransform_o3_n[340] = 141.0;
    brain_B.HoughTransform_o3_n[341] = 142.0;
    brain_B.HoughTransform_o3_n[342] = 143.0;
    brain_B.HoughTransform_o3_n[343] = 144.0;
    brain_B.HoughTransform_o3_n[344] = 145.0;
    brain_B.HoughTransform_o3_n[345] = 146.0;
    brain_B.HoughTransform_o3_n[346] = 147.0;
    brain_B.HoughTransform_o3_n[347] = 148.0;
    brain_B.HoughTransform_o3_n[348] = 149.0;
    brain_B.HoughTransform_o3_n[349] = 150.0;
    brain_B.HoughTransform_o3_n[350] = 151.0;
    brain_B.HoughTransform_o3_n[351] = 152.0;
    brain_B.HoughTransform_o3_n[352] = 153.0;
    brain_B.HoughTransform_o3_n[353] = 154.0;
    brain_B.HoughTransform_o3_n[354] = 155.0;
    brain_B.HoughTransform_o3_n[355] = 156.0;
    brain_B.HoughTransform_o3_n[356] = 157.0;
    brain_B.HoughTransform_o3_n[357] = 158.0;
    brain_B.HoughTransform_o3_n[358] = 159.0;
    brain_B.HoughTransform_o3_n[359] = 160.0;
    brain_B.HoughTransform_o3_n[360] = 161.0;
    brain_B.HoughTransform_o3_n[361] = 162.0;
    brain_B.HoughTransform_o3_n[362] = 163.0;
    brain_B.HoughTransform_o3_n[363] = 164.0;
    brain_B.HoughTransform_o3_n[364] = 165.0;
    brain_B.HoughTransform_o3_n[365] = 166.0;
    brain_B.HoughTransform_o3_n[366] = 167.0;
    brain_B.HoughTransform_o3_n[367] = 168.0;
    brain_B.HoughTransform_o3_n[368] = 169.0;
    brain_B.HoughTransform_o3_n[369] = 170.0;
    brain_B.HoughTransform_o3_n[370] = 171.0;
    brain_B.HoughTransform_o3_n[371] = 172.0;
    brain_B.HoughTransform_o3_n[372] = 173.0;
    brain_B.HoughTransform_o3_n[373] = 174.0;
    brain_B.HoughTransform_o3_n[374] = 175.0;
    brain_B.HoughTransform_o3_n[375] = 176.0;
    brain_B.HoughTransform_o3_n[376] = 177.0;
    brain_B.HoughTransform_o3_n[377] = 178.0;
    brain_B.HoughTransform_o3_n[378] = 179.0;
    brain_B.HoughTransform_o3_n[379] = 180.0;
    brain_B.HoughTransform_o3_n[380] = 181.0;
    brain_B.HoughTransform_o3_n[381] = 182.0;
    brain_B.HoughTransform_o3_n[382] = 183.0;
    brain_B.HoughTransform_o3_n[383] = 184.0;
    brain_B.HoughTransform_o3_n[384] = 185.0;
    brain_B.HoughTransform_o3_n[385] = 186.0;
    brain_B.HoughTransform_o3_n[386] = 187.0;
    brain_B.HoughTransform_o3_n[387] = 188.0;
    brain_B.HoughTransform_o3_n[388] = 189.0;
    brain_B.HoughTransform_o3_n[389] = 190.0;
    brain_B.HoughTransform_o3_n[390] = 191.0;
    brain_B.HoughTransform_o3_n[391] = 192.0;
    brain_B.HoughTransform_o3_n[392] = 193.0;
    brain_B.HoughTransform_o3_n[393] = 194.0;
    brain_B.HoughTransform_o3_n[394] = 195.0;
    brain_B.HoughTransform_o3_n[395] = 196.0;
    brain_B.HoughTransform_o3_n[396] = 197.0;
    brain_B.HoughTransform_o3_n[397] = 198.0;
    brain_B.HoughTransform_o3_n[398] = 199.0;
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

  {
    int32_T idxNHood;
    int32_T idxOffsets;
    int32_T curNumNonZ;
    int32_T n;
    int32_T m;

    /* Start for Stateflow: '<Root>/StateFlow Functions' incorporates:
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.GetBuoyForwardVelocity'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetForwardVelocity'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.GetHedgeValues'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.LocatePinger.GetPingerHeading.GetHeadings'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
     *  Start for SubSystem: '<S7>/StateManagement.Running.Autonomous.Perform'
     */

    /* Start for Constant: '<S8>/Constant' */
    brain_B.Constant_k = brain_P.Buoy1_Hue;

    /* Start for Constant: '<S8>/Constant2' */
    brain_B.Constant2 = brain_P.Buoy1_Saturation;

    /* Start for Constant: '<S8>/Constant1' */
    brain_B.Constant1 = brain_P.Buoy1_Value;
    StateFlowFunctionsMaintai_Start(brain_M,
      &brain_DWork.StateFlowFunctionsMaintainHea_d);
    StateFlowFunctionsBuoys_b_Start(&brain_B.StateFlowFunctionsBuoysAppro_hj);

    /* Start for Constant: '<S16>/Constant' */
    brain_B.Constant_l = brain_P.Heading_Forward_Velocity;

    /* Start for Constant: '<S12>/Constant' */
    brain_B.Constant_p = brain_P.Buoy_Strafe;

    /* Start for Constant: '<S39>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity_o = brain_P.Heading_Forward_Velocity;

    /* Start for Constant: '<S26>/Constant' */
    brain_B.Constant = brain_P.Track_Desired_Depth;

    /* Start for S-Function (svipmorphop): '<S98>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 1; n = 1) {
      for (m = 0; m < 4; m++) {
        if (brain_ConstP.pooled35[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_l[idxOffsets] = m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_f[0] = curNumNonZ;
    curNumNonZ = 0;
    for (n = 0; n < 4; n++) {
      for (m = 0; m < 1; m = 1) {
        if (brain_ConstP.pooled35[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_l[idxOffsets] = n * 127;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_f[1] = curNumNonZ;

    /* Start for S-Function (svipmorphop): '<S27>/Dilation' */
    idxOffsets = 0;
    curNumNonZ = 0;
    idxNHood = 4;
    for (m = 0; m < 2; m++) {
      for (n = 0; n < 2; n++) {
        idxNHood--;
        if (brain_ConstP.pooled36[idxNHood]) {
          brain_DWork.Dilation_DILATE_OFF_DW[idxOffsets] = m * 123 + n;
          curNumNonZ++;
          idxOffsets++;
        }
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW = curNumNonZ;

    /* Start for S-Function (svipmorphop): '<S27>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 1; n = 1) {
      for (m = 0; m < 4; m++) {
        if (brain_ConstP.pooled35[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_i[idxOffsets] = m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_j[0] = curNumNonZ;
    curNumNonZ = 0;
    for (n = 0; n < 4; n++) {
      for (m = 0; m < 1; m = 1) {
        if (brain_ConstP.pooled35[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_i[idxOffsets] = n * 127;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_j[1] = curNumNonZ;

    /* Start for S-Function (svipmorphop): '<S34>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 3; n++) {
      for (m = 0; m < 2; m++) {
        if (brain_ConstP.Erosion_NHOOD_RTP[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW[idxOffsets] = n * 123 + m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW = curNumNonZ;

    /* Start for Constant: '<S33>/Hedge Hue' */
    brain_B.HedgeHue = brain_P.Hedge_Hue;

    /* Start for Constant: '<S33>/Hedge Saturation' */
    brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

    /* Start for Constant: '<S33>/Hedge Value' */
    brain_B.HedgeValue = brain_P.Hedge_Value;
    StateFlowFunctionsJumpH_a_Start(brain_M,
      &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);

    /* Start for Constant: '<S30>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Vision_Forward_Velocity;
  }

  /* InitializeConditions for Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.GetBuoyForwardVelocity'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetForwardVelocity'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.GetHedgeValues'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.LocatePinger.GetPingerHeading.GetHeadings'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   *  InitializeConditions for SubSystem: '<S7>/StateManagement.Running.Autonomous.Perform'
   */
  brain_DWork.is_active_StateFlowFunctions = 0U;
  brain_DWork.is_StateFlowFunctions = 0U;
  brain_DWork.is_Breach = 0U;
  brain_DWork.is_Buoys = 0U;
  brain_DWork.is_ApproachBuoys = 0U;
  brain_DWork.is_FollowOnePath = 0U;
  brain_DWork.is_OnePath = 0U;
  brain_DWork.is_RecognizePath = 0U;
  brain_DWork.is_JumpHedge = 0U;
  brain_DWork.is_GetInitialDirection = 0U;
  brain_DWork.is_IncreaseAxisRatio = 0U;
  brain_DWork.is_LocatePinger = 0U;
  brain_DWork.is_GetPingerHeading = 0U;
  brain_DWork.is_Start = 0U;
  brain_DWork.is_ValidationGate = 0U;
  brain_DWork.is_active_StateManagement = 0U;
  brain_DWork.is_StateManagement = 0U;
  brain_DWork.is_Running = 0U;
  brain_DWork.is_Autonomous = 0U;
  brain_DWork.was_Autonomous = 0U;
  brain_DWork.is_active_c1_brain = 0U;
  brain_DWork.count = 0.0;
  brain_DWork.Obstacle = FALSE;
  brain_DWork.OldObstacle = FALSE;
  brain_DWork.Area = 0;
  brain_DWork.countarea = 0.0;
  brain_DWork.DesiredHeadingCount = 0.0;
  brain_DWork.OldHeading = 0.0;
  brain_DWork.TrackCount = 0.0;
  brain_DWork.BuoyCount = 0.0;
  brain_DWork.HeadingAlongPath = 0.0;
  brain_DWork.Done = 0.0;
  brain_DWork.Error = 0.0;
  brain_DWork.Forward = 0.0;
  brain_DWork.OperationalState = 0;
  brain_DWork.BuoyHue = 0.0;
  brain_DWork.BuoySaturation = 0.0;
  brain_DWork.BuoyValue = 0.0;
  brain_DWork.Image = 0.0;
  memset((void *)(&brain_DWork.LabelMatrix[0]), (int32_T)0.0, 19200U * sizeof
         (real_T));
  brain_DWork.TurnDirection = 0.0;
  brain_DWork.count2ndarea = 0.0;
  brain_DWork.num_colors = 0.0;
  memset((void *)(&brain_DWork.ref_colors[0]), (int32_T)0.0, 150U * sizeof
         (real_T));
  brain_DWork.num_blobs = 0.0;
  memset((void *)(&brain_DWork.BuoyBlobs[0]), (int32_T)0.0, 200U * sizeof(real_T));
  brain_DWork.H_Hue = 0.0;
  brain_DWork.H_Sat = 0.0;
  brain_DWork.H_Value = 0.0;
  brain_DWork.MoveOn = 0.0;
  brain_DWork.NewAxisRatio = 0.0;
  brain_DWork.OldAxisRatio = 0.0;
  brain_DWork.StrafeDir = 0.0;
  brain_DWork.Heading1 = 0.0;
  brain_DWork.Heading2 = 0.0;
  brain_DWork.Heading3 = 0.0;
  brain_DWork.Heading4 = 0.0;
  brain_DWork.OldDesiredHeading = 0.0;
  brain_B.Left = 0;
  brain_B.Right = 0;
  brain_B.Strafe = 0;
  brain_B.Vertical = 0;
  brain_B.DesiredDepth = 0.0;
  brain_B.DesiredHeading = 0.0;
  brain_B.CameraPosition = 0;
  brain_B.BuoyCentroidX = 0.0;
  brain_B.BuoyCentroidY = 0.0;
  brain_B.State = 0;
  memset((void *)(&brain_B.BWout[0]), (int32_T)0.0, 19200U * sizeof(real_T));
  memset((void *)(&brain_B.RGBout[0]), (int32_T)0.0, 57600U * sizeof(real_T));
  brain_DWork.presentTicks = 0U;
  brain_DWork.elapsedTicks = 0U;
  brain_DWork.previousTicks = 0U;
  StateFlowFunctionsBuoysApp_Init(brain_M,
    &brain_DWork.StateFlowFunctionsBuoysApproa_l);
  StateFlowFunctionsBuoysFin_Init(&brain_DWork.StateFlowFunctionsBuoysFindB_ln);
  StateFlowFunctionsBuoysF_e_Init(&brain_DWork.StateFlowFunctionsBuoysFindB_ls);
  StateFlowFunctionsMaintain_Init(brain_M,
    &brain_DWork.StateFlowFunctionsMaintainHea_d);
  brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;
  StateFlowFunctionsFollowOn_Init(brain_M,
    &brain_DWork.StateFlowFunctionsFollowOnePa_k);
  StateFlowFunctionsFollow_h_Init(brain_M,
    &brain_DWork.StateFlowFunctionsFollowOneP_iq);
  StateFlowFunctionsJumpHe_k_Init(brain_M,
    &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
  StateFlowFunctionsFollow_i_Init(brain_M,
    &brain_DWork.StateFlowFunctionsFollowOneP_ey);

  /* Enable for Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.GetBuoyForwardVelocity'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.GetForwardVelocity'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.GetHedgeValues'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.LocatePinger.GetPingerHeading.GetHeadings'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   *  Enable for SubSystem: '<S7>/StateManagement.Running.Autonomous.Perform'
   */
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
