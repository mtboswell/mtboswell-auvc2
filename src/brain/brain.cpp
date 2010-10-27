/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.736
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Fri Oct  1 02:40:39 2010
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Fri Oct  1 02:40:43 2010
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
#define brain_IN_CalcIMUInfo           (1U)
#define brain_IN_CalcTare              (2U)
#define brain_IN_CheckAxisRatio        (1U)
#define brain_IN_ChooseState           (3U)
#define brain_IN_CompareAxisRatio      (1U)
#define brain_IN_Compass               (1U)
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
#define brain_IN_IMU                   (2U)
#define brain_IN_IncreaseAxisRatio     (5U)
#define brain_IN_JumpHedge             (8U)
#define brain_IN_LocatePinger          (12U)
#define brain_IN_LocatePinger_m        (9U)
#define brain_IN_MakeSure              (3U)
#define brain_IN_Move                  (2U)
#define brain_IN_Move_m                (3U)
#define brain_IN_NO_ACTIVE_CHILD       (0U)
#define brain_IN_Next                  (1U)
#define brain_IN_NotRunning            (10U)
#define brain_IN_NotRunning_m          (1U)
#define brain_IN_OnePath               (1U)
#define brain_IN_PerformTare           (2U)
#define brain_IN_PositionOver          (3U)
#define brain_IN_RecognizeHedge        (6U)
#define brain_IN_RecognizePath         (2U)
#define brain_IN_Running               (2U)
#define brain_IN_SecondDirections      (4U)
#define brain_IN_Start                 (11U)
#define brain_IN_StartFinished         (2U)
#define brain_IN_Start_m               (13U)
#define brain_IN_Stop                  (3U)
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
static void brain_min(const real_T varargin_1[10], real_T *minval, real_T *indx);

/* Forward declaration for local functions */
static void brain_Outputs(const boolean_T U0[19200], real_T Y0[100], real_T Y1
  [50], real_T Y2[50], uint8_T *Y3, rtDW_StateFlowFunctionsBuoysFin *localDW);

/* Forward declaration for local functions */
static void brain_conv2(const real32_T arg1[19200], const real32_T arg2[9],
  real32_T c[18644]);

/* Forward declaration for local functions */
static void brain_Outputs_f(const boolean_T U0[19200], int32_T Y0[50], real_T
  Y1[100], real_T Y2[50], real_T Y3[50], uint8_T *Y4,
  rtDW_StateFlowFunctionsBuoysF_e *localDW);

/* Forward declaration for local functions */
static void brain_max(const real_T varargin_1[10], real_T *maxval, real_T *indx);

/* Forward declaration for local functions */
static void brain_enter_internal_CalcTare(void);
static void brain_StateEstimator(void);
static void brain_Autonomous(void);
static void brain_enter_internal_Buoys(void);
static real_T brain_countareas(real_T Size, real_T count1);
static real_T brain_Turn45Degrees(real_T CHeading, real_T TurnD);
static void brain_FindSecondBuoy(void);
static void bra_exit_internal_ApproachBuoys(void);
static void brain_ApproachBuoys(void);
static real_T brain_countimages(real_T Image1, real_T OldImage, real_T count1);
static void brain_exit_internal_Buoys(void);
static void brain_Buoys(void);
static void brain_max_o(const real_T varargin_1[71820], real_T maxval[180],
  real_T indx[180]);
static void brain_max_oh(const real_T varargin_1[180], real_T *maxval, real_T
  *indx);
static void brain_refp1_round(real_T *x);
static void brain_max_h(const real_T varargin_1[2], real_T *maxval, real_T *indx);
static void brain_OnePath(void);
static void brain_RecognizePath(void);
static void brain_GetInCorrectState(void);
static real_T brain_GetStrafeDirection(real_T AxisDif);
static void exit_internal_GetInitialDirecti(void);
static void brai_enter_atomic_ApproachHedge(void);
static void brain_GetInitialDirection(void);
static void brain_IncreaseAxisRatio(void);
static void brain_RecognizeHedge(void);
static void brain_exit_internal_JumpHedge(void);
static void brain_exit_atomic_JumpHedge(void);
static void brain_JumpHedge(void);
static void brain_LocatePinger(void);
static real_T brain_countimages_m(real_T Image, real_T OldImage, real_T count1);
static void brain_ValidationGate(void);
static void brain_StateFlowFunctions(void);
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
 *    '<S29>/Embedded MATLAB Function1'
 *    '<S22>/Embedded MATLAB Function1'
 */
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB)
{
  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function1': '<S47>:1' */
  /*  This function finds the center of an image */
  /* '<S47>:1:6' */
  /* '<S47>:1:7' */
  localB->XCenter = 80.0;
  localB->YCenter = 60.0;
}

/* Function for Embedded MATLAB: '<S10>/Embedded MATLAB Function' */
static void brain_min(const real_T varargin_1[10], real_T *minval, real_T *indx)
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (k < 11)) {
      ix++;
      if (!rtIsNaN(varargin_1[ix - 1])) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
        searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        k++;
      }
    }

    if (!searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (k = itmp + 1; k < 11; k++) {
      ix++;
      if (varargin_1[ix - 1] < mtmp) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
      }
    }
  }

  *minval = mtmp;
  *indx = (real_T)itmp;
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
  real_T cc;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  real_T min_dist;
  real_T Dist[10];
  int8_T rtb_index_h;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  real_T xys;
  uint32_T k;
  real_T uxx;
  real_T rtb_TmpSignalConversionAtDrawMa[2];
  real_T rtb_Error;
  real_T rtb_TSamp_l;
  real_T rtb_TSamp_c;
  int32_T rtb_BuoyBlobAnalysis_o1_m[10];
  real_T rtb_BuoyBlobAnalysis_o2_a[20];
  real_T rtb_BuoyBlobAnalysis_o3_l[10];
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  localDW->StateFlowFunctionsBuoysApproa_a = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsBuoysApproa_m;
  localDW->StateFlowFunctionsBuoysApproa_m = brain_M->Timing.clockTick0;

  /* S-Function (svipcolorconv): '<S52>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  uxx = 0.0;
  cc = 0.0;
  xys = 0.0;
  min_dist = 6.0 * rtu_B_Hue;
  rtb_TSamp_c = (real_T)(uint32_T)(min_dist - 1.3322676295501878E-15);
  min_dist -= rtb_TSamp_c;
  rtb_TSamp_l = 1.0 - rtu_B_Sat;
  rtb_Error = 1.0 - rtu_B_Sat * min_dist;
  min_dist = rtu_B_Sat * min_dist + rtb_TSamp_l;
  if (rtb_TSamp_c == 0.0) {
    uxx = 1.0;
    cc = min_dist;
    xys = rtb_TSamp_l;
  } else if (rtb_TSamp_c == 1.0) {
    uxx = rtb_Error;
    cc = 1.0;
    xys = rtb_TSamp_l;
  } else if (rtb_TSamp_c == 2.0) {
    uxx = rtb_TSamp_l;
    cc = 1.0;
    xys = min_dist;
  } else if (rtb_TSamp_c == 3.0) {
    uxx = rtb_TSamp_l;
    cc = rtb_Error;
    xys = 1.0;
  } else if (rtb_TSamp_c == 4.0) {
    uxx = min_dist;
    cc = rtb_TSamp_l;
    xys = 1.0;
  } else {
    if (rtb_TSamp_c == 5.0) {
      uxx = 1.0;
      cc = rtb_TSamp_l;
      xys = rtb_Error;
    }
  }

  if (uxx > cc) {
    min_dist = uxx;
  } else {
    min_dist = cc;
  }

  if (!(min_dist > xys)) {
    min_dist = xys;
  }

  min_dist = rtu_B_Value / min_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o1 = min_dist * uxx;
  localB->ColorSpaceConversion_o2 = min_dist * cc;
  localB->ColorSpaceConversion_o3 = min_dist * xys;

  /* S-Function (svipcolorconv): '<S52>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 0.039286085583733095) {
    min_dist = localB->ColorSpaceConversion_o1 / 12.923054468333255;
  } else {
    min_dist = rt_pow_snf((localB->ColorSpaceConversion_o1 +
      0.055000519817226347) / 1.0550005198172263, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 0.039286085583733095) {
    rtb_TSamp_l = localB->ColorSpaceConversion_o2 / 12.923054468333255;
  } else {
    rtb_TSamp_l = rt_pow_snf((localB->ColorSpaceConversion_o2 +
      0.055000519817226347) / 1.0550005198172263, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 0.039286085583733095) {
    rtb_Error = localB->ColorSpaceConversion_o3 / 12.923054468333255;
  } else {
    rtb_Error = rt_pow_snf((localB->ColorSpaceConversion_o3 +
      0.055000519817226347) / 1.0550005198172263, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  uxx = (0.41239079926596 * min_dist + 0.35758433938388 * rtb_TSamp_l) +
    0.18048078840183 * rtb_Error;
  cc = (0.21263900587151 * min_dist + 0.71516867876776 * rtb_TSamp_l) +
    0.07219231536073 * rtb_Error;
  xys = (0.01933081871559 * min_dist + 0.11919477979463 * rtb_TSamp_l) +
    0.95053215224966 * rtb_Error;

  /* Make sure that the output is in [0..1] range; clip if necessary */
  if (uxx > 1.0) {
    uxx = 1.0;
  } else {
    if (uxx < 0.0) {
      uxx = 0.0;
    }
  }

  if (cc > 1.0) {
    cc = 1.0;
  } else {
    if (cc < 0.0) {
      cc = 0.0;
    }
  }

  if (xys > 1.0) {
    xys = 1.0;
  } else {
    if (xys < 0.0) {
      xys = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = uxx;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = xys;

  /* Convert from XYZ to L*a*b* */
  min_dist = localB->ColorSpaceConversion1_o1 / 0.9641986557609;
  rtb_Error = localB->ColorSpaceConversion1_o3 / 0.82511648322104;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (min_dist > 0.0088564516790356311) {
    rtb_TSamp_c = rt_pow_snf(min_dist, 0.33333333333333331);
  } else {
    rtb_TSamp_c = 7.7870370370370372 * min_dist + 0.13793103448275862;
  }

  if (localB->ColorSpaceConversion1_o2 > 0.0088564516790356311) {
    rtb_TSamp_l = rt_pow_snf(localB->ColorSpaceConversion1_o2,
      0.33333333333333331);
  } else {
    rtb_TSamp_l = 7.7870370370370372 * localB->ColorSpaceConversion1_o2 +
      0.13793103448275862;
  }

  if (rtb_Error > 0.0088564516790356311) {
    min_dist = rt_pow_snf(rtb_Error, 0.33333333333333331);
  } else {
    min_dist = 7.7870370370370372 * rtb_Error + 0.13793103448275862;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * rtb_TSamp_l - 16.0;
  localB->ColorSpaceConversion1_o2 = (rtb_TSamp_c - rtb_TSamp_l) * 500.0;
  localB->ColorSpaceConversion1_o3 = (rtb_TSamp_l - min_dist) * 200.0;

  /* Embedded MATLAB: '<S48>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Choose Closest Color': '<S51>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S51>:1:5' */
  min_dist = 1000.0;

  /* '<S51>:1:11' */
  rtb_index_h = 1;

  /* '<S51>:1:12' */
  for (rtb_TSamp_l = 1.0; rtb_TSamp_l <= rtu_Num_Colors; rtb_TSamp_l++) {
    /* '<S51>:1:12' */
    /* '<S51>:1:13' */
    rtb_Error = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o2 -
      rtu_Ref_Colors[(int32_T)rtb_TSamp_l + 49], 2.0) * 1.5 + rt_pow_snf
                      (localB->ColorSpaceConversion1_o1 - rtu_Ref_Colors
                       [(int32_T)rtb_TSamp_l - 1], 2.0)) + rt_pow_snf
                     (localB->ColorSpaceConversion1_o3 - rtu_Ref_Colors[(int32_T)
                      rtb_TSamp_l + 99], 2.0) * 1.5);
    if (rtb_Error < min_dist) {
      /* '<S51>:1:14' */
      /* '<S51>:1:15' */
      min_dist = rtb_Error;

      /* '<S51>:1:16' */
      uxx = floor(rtb_TSamp_l + 0.5);
      if (uxx < 128.0) {
        rtb_index_h = (int8_T)uxx;
      } else {
        rtb_index_h = MAX_int8_T;
      }
    }
  }

  /* RelationalOperator: '<S48>/Relational Operator' */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (rtu_LabMatrix[i] == (real_T)rtb_index_h);
  }

  /* S-Function (svipblob): '<S10>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (loop = 0; loop < 123; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (padCols = 0; padCols < 120; padCols++) {
      localDW->BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 : 0);
      i++;
      idx++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
    localDW->BuoyBlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
  }

  for (loop = 0; loop < 121; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    ms = 1;
    j = nn * 122;
    for (padCols = 0; padCols < 120; padCols++) {
      numBlobs = (uint32_T)(j + ms);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (i = 0; i < 8; i++) {
            k = numBlobs + (uint32_T)brain_ConstP.pooled27[i];
            if (localDW->BuoyBlobAnalysis_PAD_DW[k] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[k] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(k / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
              localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = k;
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
          n = 160;
          padCols = 120;
        }

        if (padCols < 120) {
          currentLabel++;
        }
      }

      ms++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  loop = 0;
  idx = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    rtb_BuoyBlobAnalysis_o1_m[i] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    nn = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i]; j++) {
      nn += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + idx];
      ms += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + loop];
    }

    rtb_TmpSignalConversionAtDrawMa[0] = (real_T)ms / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_TmpSignalConversionAtDrawMa[1] = (real_T)nn / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_BuoyBlobAnalysis_o2_a[i << 1] = rtb_TmpSignalConversionAtDrawMa[0];
    rtb_BuoyBlobAnalysis_o2_a[(i << 1) + 1] = rtb_TmpSignalConversionAtDrawMa[1];
    min_dist = 0.0;
    rtb_TSamp_c = 0.0;
    xys = 0.0;
    for (k = 0U; k < (uint32_T)(int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i]; k++) {
      rtb_TSamp_l = (real_T)localDW->BuoyBlobAnalysis_N_PIXLIST_DW[idx +
        (int32_T)k] - rtb_TmpSignalConversionAtDrawMa[1];
      rtb_Error = (real_T)localDW->BuoyBlobAnalysis_M_PIXLIST_DW[loop + (int32_T)
        k] - rtb_TmpSignalConversionAtDrawMa[0];
      min_dist += rtb_TSamp_l * rtb_TSamp_l;
      rtb_TSamp_c += rtb_Error * rtb_Error;
      xys += rtb_TSamp_l * (-rtb_Error);
    }

    uxx = min_dist / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[i] +
      0.083333333333333329;
    rtb_Error = rtb_TSamp_c / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[i] +
      0.083333333333333329;
    min_dist = xys / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    min_dist = sqrt((uxx - rtb_Error) * (uxx - rtb_Error) + min_dist * min_dist *
                    4.0);
    rtb_TSamp_l = ((uxx + rtb_Error) + min_dist) * 8.0;
    rtb_BuoyBlobAnalysis_o3_l[i] = sqrt(rtb_TSamp_l - ((uxx + rtb_Error) -
      min_dist) * 8.0) / sqrt(rtb_TSamp_l);
    loop += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    idx += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
  }

  for (loop = (int32_T)numBlobs; loop < 10; loop++) {
    rtb_BuoyBlobAnalysis_o1_m[loop] = -1;
  }

  for (loop = (int32_T)(numBlobs << 1); loop < 20; loop++) {
    rtb_BuoyBlobAnalysis_o2_a[loop] = -1.0;
  }

  for (loop = (int32_T)numBlobs; loop < 10; loop++) {
    rtb_BuoyBlobAnalysis_o3_l[loop] = -1.0;
  }

  /* S-Function (svipscalenconvert): '<S10>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = localB->BW[i] ? 1.0 : 0.0;
  }

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function': '<S46>:1' */
  /*  This function will choose and return data about the blob most similar to */
  /*  the desired set of characteristics given a set of blobs */
  /*  Determine closest blob to desired Eccentricity */
  /* '<S46>:1:8' */
  for (i = 0; i < 10; i++) {
    Dist[i] = fabs(rtb_BuoyBlobAnalysis_o3_l[i] - brain_P.Buoy_Min_Eccentricity);
  }

  if ((rtb_BuoyBlobAnalysis_o2_a[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_a[1] ==
       -1.0)) {
    /* '<S46>:1:10' */
    /* '<S46>:1:12' */
    localB->BlobCentroidX = 80.0;

    /* '<S46>:1:13' */
    localB->BlobCentroidY = 60.0;

    /* '<S46>:1:14' */
    localB->BlobArea = -1.0;
  } else {
    brain_min(Dist, &min_dist, &rtb_TSamp_l);

    /* '<S46>:1:17' */
    Dist[(int32_T)rtb_TSamp_l - 1] = 2.0;
    brain_min(Dist, &rtb_Error, &rtb_TSamp_c);
    if (rtb_Error < min_dist * 1.5) {
      /* '<S46>:1:20' */
      if (rtb_BuoyBlobAnalysis_o2_a[(((int32_T)rtb_TSamp_l - 1) << 1U) + 1] >=
          rtb_BuoyBlobAnalysis_o2_a[(((int32_T)rtb_TSamp_c - 1) << 1U) + 1]) {
        /* '<S46>:1:21' */
        /* '<S46>:1:22' */
        localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)rtb_TSamp_l
          - 1) << 1U) + 1];

        /* '<S46>:1:23' */
        localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)rtb_TSamp_l
          - 1) << 1U];

        /* '<S46>:1:24' */
        localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)
          rtb_TSamp_l - 1];
      } else {
        /* '<S46>:1:26' */
        localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)rtb_TSamp_c
          - 1) << 1U) + 1];

        /* '<S46>:1:27' */
        localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)rtb_TSamp_c
          - 1) << 1U];

        /* '<S46>:1:28' */
        localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)
          rtb_TSamp_c - 1];
      }
    } else {
      /* '<S46>:1:31' */
      localB->BlobCentroidX = rtb_BuoyBlobAnalysis_o2_a[(((int32_T)rtb_TSamp_l -
        1) << 1U) + 1];

      /* '<S46>:1:32' */
      localB->BlobCentroidY = rtb_BuoyBlobAnalysis_o2_a[((int32_T)rtb_TSamp_l -
        1) << 1U];

      /* '<S46>:1:33' */
      localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[(int32_T)rtb_TSamp_l
        - 1];
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
  for (n = 0; n < 2; n += 2) {
    uxx = rtb_TmpSignalConversionAtDrawMa[n];
    if ((rtb_TmpSignalConversionAtDrawMa[n] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDrawMa[n] > -4.503599627370496E+15)) {
      uxx = floor(rtb_TmpSignalConversionAtDrawMa[n] + 0.5);
    }

    padCols = (int32_T)uxx;
    uxx = rtb_TmpSignalConversionAtDrawMa[n + 1];
    if ((rtb_TmpSignalConversionAtDrawMa[n + 1] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDrawMa[n + 1] > -4.503599627370496E+15)) {
      uxx = floor(rtb_TmpSignalConversionAtDrawMa[n + 1] + 0.5);
    }

    i = (int32_T)uxx;
    idx = padCols - 7;
    line_idx_1 = i - 7;
    line_idx_0 = padCols + 7;
    line_idx = i + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    j = idx;
    line_idx_4 = line_idx_1;
    line_idx_3 = line_idx_0;
    line_idx_2 = line_idx;
    while (!done) {
      numBlobs = 0U;
      k = 0U;

      /* Determine viewport violations. */
      if (j < 0) {
        numBlobs = 4U;
      } else {
        if (j > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_3 < 0) {
        k = 4U;
      } else {
        if (line_idx_3 > 119) {
          k = 8U;
        }
      }

      if (line_idx_4 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_4 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_2 < 0) {
        k |= 1U;
      } else {
        if (line_idx_2 > 159) {
          k |= 2U;
        }
      }

      if (!(numBlobs | k)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & k) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          j = idx;
          line_idx_4 = line_idx_1;
        }

        loop = line_idx_3 - j;
        nn = line_idx_2 - line_idx_4;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          ms = (0 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          ms = (119 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_3 = line_idx_0;
          line_idx_2 = line_idx;
        }

        loop = line_idx_3 - j;
        nn = line_idx_2 - line_idx_4;
        if (k & 4U) {
          /* Violated RMin. */
          ms = (0 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else if (k & 8U) {
          /* Violated RMax. */
          ms = (119 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        } else if (k & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ms = line_idx_4 * 120 + j;
      while (j <= line_idx_3) {
        localB->DrawMarkers[ms] = 0.5;
        ms += 121;
        j++;
      }
    }

    idx = padCols - 7;
    line_idx_1 = i + 7;
    line_idx_0 = padCols + 7;
    line_idx = i - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    j = idx;
    line_idx_4 = line_idx_1;
    line_idx_3 = line_idx_0;
    line_idx_2 = line_idx;
    while (!done) {
      numBlobs = 0U;
      k = 0U;

      /* Determine viewport violations. */
      if (j < 0) {
        numBlobs = 4U;
      } else {
        if (j > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_3 < 0) {
        k = 4U;
      } else {
        if (line_idx_3 > 119) {
          k = 8U;
        }
      }

      if (line_idx_4 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_4 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_2 < 0) {
        k |= 1U;
      } else {
        if (line_idx_2 > 159) {
          k |= 2U;
        }
      }

      if (!(numBlobs | k)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & k) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          j = idx;
          line_idx_4 = line_idx_1;
        }

        loop = line_idx_3 - j;
        nn = line_idx_2 - line_idx_4;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          ms = (0 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          ms = (119 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_3 = line_idx_0;
          line_idx_2 = line_idx;
        }

        loop = line_idx_3 - j;
        nn = line_idx_2 - line_idx_4;
        if (k & 4U) {
          /* Violated RMin. */
          ms = (0 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else if (k & 8U) {
          /* Violated RMax. */
          ms = (119 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        } else if (k & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ms = line_idx_4 * 120 + j;
      while (j <= line_idx_3) {
        localB->DrawMarkers[ms] = 0.5;
        ms += -119;
        j++;
      }
    }
  }

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S49>/Subtract' */
  min_dist = localB->sf_EmbeddedMATLABFunction1.XCenter - localB->BlobCentroidX;

  /* SampleTimeMath: '<S54>/TSamp' incorporates:
   *  Gain: '<S53>/X-Buoy Derivative Gain'
   *
   * About '<S54>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_l = brain_P.Cam_Forward_XPosition_Kd * min_dist / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S49>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S53>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S53>/X-Buoy Proportional Gain'
   *  Sum: '<S53>/Sum'
   *  Sum: '<S54>/Diff'
   *  UnitDelay: '<S54>/UD'
   *
   * Block description for '<S54>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S54>/UD':
   *
   *  Store in Global RAM
   */
  uxx = floor((brain_P.Cam_Forward_XPosition_Kp * min_dist + (rtb_TSamp_l -
    localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST);
  if (uxx < 128.0) {
    if (uxx >= -128.0) {
      rtb_index_h = (int8_T)uxx;
    } else {
      rtb_index_h = MIN_int8_T;
    }
  } else {
    rtb_index_h = MAX_int8_T;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Constant: '<S49>/Vision_Forward_Velocity'
   */
  localB->Add = brain_P.Vision_Forward_Velocity + (real_T)rtb_index_h;

  /* Sum: '<S49>/Add1' incorporates:
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Vision_Forward_Velocity2'
   *  Product: '<S49>/Multiply'
   */
  localB->Add1 = (real_T)rtb_index_h * -1.0 + brain_P.Vision_Forward_Velocity;

  /* Sum: '<S50>/Subtract' */
  rtb_Error = localB->BlobCentroidY - localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* SampleTimeMath: '<S56>/TSamp' incorporates:
   *  Gain: '<S55>/Y-Buoy Derivative Gain'
   *
   * About '<S56>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_c = brain_P.Cam_Forward_YPosition_Kd * rtb_Error / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S50>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S55>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S55>/Y-Buoy Proportional Gain'
   *  Sum: '<S55>/Sum'
   *  Sum: '<S56>/Diff'
   *  UnitDelay: '<S56>/UD'
   *
   * Block description for '<S56>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S56>/UD':
   *
   *  Store in Global RAM
   */
  uxx = floor((brain_P.Cam_Forward_YPosition_Kp * rtb_Error + (rtb_TSamp_c -
    localDW->UD_DSTATE_n)) + localDW->YBuoyDiscreteTimeIntegrator_DST);
  if (uxx < 128.0) {
    if (uxx >= -128.0) {
      localB->DataTypeConversion = (int8_T)uxx;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else {
    localB->DataTypeConversion = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S54>/UD'
   * Block description for '<S54>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_l;

  /* Update for DiscreteIntegrator: '<S53>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S53>/X-Buoy Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * (brain_P.Cam_Forward_XPosition_Ki
    * min_dist) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S56>/UD'
   * Block description for '<S56>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_n = rtb_TSamp_c;

  /* Update for DiscreteIntegrator: '<S55>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S55>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * (brain_P.Cam_Forward_YPosition_Ki
    * rtb_Error) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Function for Embedded MATLAB: '<S15>/Blob Extraction' */
static void brain_Outputs(const boolean_T U0[19200], real_T Y0[100], real_T Y1
  [50], real_T Y2[50], uint8_T *Y3, rtDW_StateFlowFunctionsBuoysFin *localDW)
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
          for (pixListMinc = 0; pixListMinc < 8; pixListMinc++) {
            walkerIdx = k + (uint32_T)localDW->WALKER_RTP[pixListMinc];
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
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T idxPix_0;
  uint8_T TotalNum;
  real_T k;
  uint8_T b_i;
  real_T TEccent[50];
  real_T TExtent[50];
  uint8_T TNumBlobs;
  real_T count;
  real_T rtb_BuoyCent[100];
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  int32_T line_idx_6;

  /* Embedded MATLAB: '<S15>/Blob Extraction' */
  count = rtu_num_colors;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/Blob Extraction': '<S64>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S64>:1:7' */
  for (i = 0; i < 19200; i++) {
    localB->LogicMatrix[i] = FALSE;
  }

  /* '<S64>:1:9' */
  /* '<S64>:1:12' */
  memset((void *)(&localB->Centroid[0]), 0, 100U * sizeof(real_T));

  /* '<S64>:1:13' */
  /* '<S64>:1:14' */
  for (i = 0; i < 50; i++) {
    localB->Eccent[i] = 0.0;
    localB->Extent[i] = 0.0;
  }

  /* '<S64>:1:16' */
  TotalNum = 0U;

  /* '<S64>:1:26' */
  for (k = 1.0; k <= count; k++) {
    /* '<S64>:1:26' */
    /* '<S64>:1:27' */
    for (i = 0; i < 120; i++) {
      /* '<S64>:1:27' */
      /* '<S64>:1:28' */
      for (idxPix = 0; idxPix < 160; idxPix++) {
        /* '<S64>:1:28' */
        if (rtu_LabMatrix[120 * idxPix + i] != k) {
          /* '<S64>:1:29' */
          /* '<S64>:1:30' */
          localB->LogicMatrix[i + 120 * idxPix] = FALSE;
        } else {
          /* '<S64>:1:32' */
          localB->LogicMatrix[i + 120 * idxPix] = TRUE;
        }
      }
    }

    brain_Outputs(&localB->LogicMatrix[0], rtb_BuoyCent, TEccent, TExtent,
                  &TNumBlobs, localDW);
    idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)TNumBlobs);
    if ((uint32_T)idxPix_0 > 255U) {
      idxPix_0 = 255;
    }

    if (idxPix_0 < 50) {
      /* '<S64>:1:38' */
      /* '<S64>:1:39' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S64>:1:39' */
        /* '<S64>:1:40' */
        idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)idxPix_0 > 255U) {
          idxPix_0 = 255;
        }

        localB->Centroid[idxPix_0 - 1] = rtb_BuoyCent[(b_i - 1) << 1];

        /* '<S64>:1:41' */
        idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)idxPix_0 > 255U) {
          idxPix_0 = 255;
        }

        localB->Centroid[idxPix_0 + 49] = rtb_BuoyCent[((b_i - 1) << 1) + 1];

        /* '<S64>:1:42' */
        idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)idxPix_0 > 255U) {
          idxPix_0 = 255;
        }

        localB->Eccent[idxPix_0 - 1] = TEccent[b_i - 1];

        /* '<S64>:1:43' */
        idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)idxPix_0 > 255U) {
          idxPix_0 = 255;
        }

        localB->Extent[idxPix_0 - 1] = TExtent[b_i - 1];
      }

      /* '<S64>:1:45' */
      idxPix_0 = (int32_T)((uint32_T)TotalNum + (uint32_T)TNumBlobs);
      if ((uint32_T)idxPix_0 > 255U) {
        idxPix_0 = 255;
      }

      TotalNum = (uint8_T)idxPix_0;
    }
  }

  localB->TotalNum = TotalNum;

  /* Embedded MATLAB: '<S15>/IF Buoy Conditions' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant2'
   *  Constant: '<S15>/Constant3'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/IF Buoy Conditions': '<S65>:1' */
  /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
  /*  if there is a buoy present in the current image */
  /* '<S65>:1:5' */
  localB->Image = 0.0;

  /* '<S65>:1:6' */
  count = 0.0;

  /* '<S65>:1:7' */
  for (i = 0; i < 100; i++) {
    rtb_BuoyCent[i] = 1.0;
  }

  /* '<S65>:1:9' */
  for (TotalNum = 1U; TotalNum <= localB->TotalNum; TotalNum = (uint8_T)
       ((uint32_T)TotalNum + 1U)) {
    /* '<S65>:1:9' */
    if ((localB->Eccent[TotalNum - 1] > brain_P.Buoy_Min_Eccentricity) &&
        (localB->Eccent[TotalNum - 1] < brain_P.Buoy_Max_Eccentricity) &&
        (localB->Extent[TotalNum - 1] > brain_P.Buoy_Min_Extent) &&
        (localB->Extent[TotalNum - 1] < brain_P.Buoy_Max_Extent)) {
      /* '<S65>:1:10' */
      /* '<S65>:1:11' */
      count++;

      /* '<S65>:1:12' */
      rtb_BuoyCent[((int32_T)count - 1) << 1U] = localB->Centroid[TotalNum - 1];

      /* '<S65>:1:13' */
      rtb_BuoyCent[1 + (((int32_T)count - 1) << 1U)] = localB->Centroid[TotalNum
        + 49];
    }
  }

  if (count >= 3.0) {
    /* '<S65>:1:17' */
    /* '<S65>:1:18' */
    localB->Image = 1.0;
  }

  /* S-Function (svipdrawmarkers): '<S15>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)(&rtu_RGBin[0]), 57600U *
         sizeof(real_T));

  /* Draw all X marks. */
  for (idxROI = 0; idxROI < 100; idxROI += 2) {
    count = rtb_BuoyCent[idxROI];
    if ((rtb_BuoyCent[idxROI] < 4.503599627370496E+15) && (rtb_BuoyCent[idxROI] >
         -4.503599627370496E+15)) {
      count = floor(rtb_BuoyCent[idxROI] + 0.5);
    }

    row = (int32_T)count;
    count = rtb_BuoyCent[idxROI + 1];
    if ((rtb_BuoyCent[idxROI + 1] < 4.503599627370496E+15) &&
        (rtb_BuoyCent[idxROI + 1] > -4.503599627370496E+15)) {
      count = floor(rtb_BuoyCent[idxROI + 1] + 0.5);
    }

    col = (int32_T)count;
    line_idx = row - 7;
    line_idx_0 = col - 7;
    line_idx_1 = row + 7;
    line_idx_2 = col + 7;
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
      idxPix_0 = 0;
      in = 0;

      /* Determine viewport violations. */
      if (line_idx_4 < 0) {
        idxPix_0 = 4;
      } else {
        if (line_idx_4 > 119) {
          idxPix_0 = 8;
        }
      }

      if (line_idx_5 < 0) {
        in = 4;
      } else {
        if (line_idx_5 > 119) {
          in = 8;
        }
      }

      if (line_idx_3 < 0) {
        idxPix_0 = (int32_T)((uint32_T)idxPix_0 | 1U);
      } else {
        if (line_idx_3 > 159) {
          idxPix_0 = (int32_T)((uint32_T)idxPix_0 | 2U);
        }
      }

      if (line_idx_6 < 0) {
        in = (int32_T)((uint32_T)in | 1U);
      } else {
        if (line_idx_6 > 159) {
          in = (int32_T)((uint32_T)in | 2U);
        }
      }

      if (!((uint32_T)idxPix_0 | (uint32_T)in)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)idxPix_0 & (uint32_T)in) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)idxPix_0 != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_4 = line_idx;
          line_idx_3 = line_idx_0;
        }

        idxPix = line_idx_5 - line_idx_4;
        i = line_idx_6 - line_idx_3;
        if ((uint32_T)idxPix_0 & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_4) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else if ((uint32_T)idxPix_0 & 8U) {
          /* Violated RMax. */
          in = (119 - line_idx_4) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited = TRUE;
        } else if ((uint32_T)idxPix_0 & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_3) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
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

        idxPix = line_idx_5 - line_idx_4;
        i = line_idx_6 - line_idx_3;
        if ((uint32_T)in & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)in & 8U) {
          /* Violated RMax. */
          in = (119 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)in & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_6) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_6) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 120 + line_idx_4;
      for (in = line_idx_4; in <= line_idx_5; in++) {
        localB->DrawMarkers[idxPix] = 0.0;
        idxPix_0 = idxPix + 19200;
        localB->DrawMarkers[idxPix_0] = 0.0;
        idxPix_0 += 19200;
        localB->DrawMarkers[idxPix_0] = 0.0;
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
    line_idx_4 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_5 = line_idx_1;
    line_idx_6 = line_idx_2;
    while (!done) {
      idxPix_0 = 0;
      in = 0;

      /* Determine viewport violations. */
      if (line_idx_4 < 0) {
        idxPix_0 = 4;
      } else {
        if (line_idx_4 > 119) {
          idxPix_0 = 8;
        }
      }

      if (line_idx_5 < 0) {
        in = 4;
      } else {
        if (line_idx_5 > 119) {
          in = 8;
        }
      }

      if (line_idx_3 < 0) {
        idxPix_0 = (int32_T)((uint32_T)idxPix_0 | 1U);
      } else {
        if (line_idx_3 > 159) {
          idxPix_0 = (int32_T)((uint32_T)idxPix_0 | 2U);
        }
      }

      if (line_idx_6 < 0) {
        in = (int32_T)((uint32_T)in | 1U);
      } else {
        if (line_idx_6 > 159) {
          in = (int32_T)((uint32_T)in | 2U);
        }
      }

      if (!((uint32_T)idxPix_0 | (uint32_T)in)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        isInBound = TRUE;
      } else if ((uint32_T)idxPix_0 & (uint32_T)in) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        isInBound = FALSE;
      } else if ((uint32_T)idxPix_0 != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_4 = line_idx;
          line_idx_3 = line_idx_0;
        }

        idxPix = line_idx_5 - line_idx_4;
        i = line_idx_6 - line_idx_3;
        if ((uint32_T)idxPix_0 & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_4) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited = TRUE;
        } else if ((uint32_T)idxPix_0 & 8U) {
          /* Violated RMax. */
          in = (119 - line_idx_4) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_3 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited = TRUE;
        } else if ((uint32_T)idxPix_0 & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_3) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_3) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_4 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
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

        idxPix = line_idx_5 - line_idx_4;
        i = line_idx_6 - line_idx_3;
        if ((uint32_T)in & 4U) {
          /* Violated RMin. */
          in = (0 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else if ((uint32_T)in & 8U) {
          /* Violated RMax. */
          in = (119 - line_idx_5) * i;
          if (((in >= 0) && (idxPix >= 0)) || ((in < 0) && (idxPix < 0))) {
            line_idx_6 += (div_s32_floor(in << 1U, idxPix) + 1) >> 1;
          } else {
            line_idx_6 += -((div_s32_floor((-in) << 1U, idxPix) + 1) >> 1);
          }

          line_idx_5 = 119;
          visited_0 = TRUE;
        } else if ((uint32_T)in & 1U) {
          /* Violated CMin. */
          in = (0 - line_idx_6) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          in = (159 - line_idx_6) * idxPix;
          if (((in >= 0) && (i >= 0)) || ((in < 0) && (i < 0))) {
            line_idx_5 += (div_s32_floor(in << 1U, i) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-in) << 1U, i) + 1) >> 1);
          }

          line_idx_6 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (isInBound) {
      idxPix = line_idx_3 * 120 + line_idx_4;
      for (in = line_idx_4; in <= line_idx_5; in++) {
        localB->DrawMarkers[idxPix] = 0.0;
        idxPix_0 = idxPix + 19200;
        localB->DrawMarkers[idxPix_0] = 0.0;
        idxPix_0 += 19200;
        localB->DrawMarkers[idxPix_0] = 0.0;
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
  int32_T i;
  int32_T j;

  /* Embedded MATLAB: '<S18>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function': '<S74>:1' */
  /*  This function puts together the segmented imaged such that it can be shown */
  /* '<S74>:1:5' */
  /* '<S74>:1:6' */
  /* '<S74>:1:7' */
  /* '<S74>:1:9' */
  for (i = 0; i < 120; i++) {
    /* '<S74>:1:9' */
    /* '<S74>:1:10' */
    for (j = 0; j < 160; j++) {
      /* '<S74>:1:10' */
      /* '<S74>:1:11' */
      localB->L[i + 120 * j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120 * j + i]
        - 1];

      /* '<S74>:1:12' */
      localB->a[i + 120 * j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120 * j + i]
        + 49];

      /* '<S74>:1:13' */
      localB->b[i + 120 * j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120 * j + i]
        + 99];
    }
  }

  /* S-Function (svipcolorconv): '<S18>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (i = 0; i < 19200; i++) {
    cc_0 = (localB->L[i] + 16.0) / 116.0;
    cc = localB->a[i] / 500.0 + cc_0;
    cc_1 = localB->b[i] / -200.0 + cc_0;
    if (cc <= 0.20689655172413793) {
      cc -= 0.13793103448275862;
      cc /= 7.7870370370370372;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (cc_0 <= 0.20689655172413793) {
      cc_0 -= 0.13793103448275862;
      cc_0 /= 7.7870370370370372;
    } else {
      cc_0 = rt_pow_snf(cc_0, 3.0);
    }

    if (cc_1 <= 0.20689655172413793) {
      cc_1 -= 0.13793103448275862;
      cc_1 /= 7.7870370370370372;
    } else {
      cc_1 = rt_pow_snf(cc_1, 3.0);
    }

    cc *= 0.9641986557609;
    cc_1 *= 0.82511648322104;

    /* assign the results */
    localB->ColorSpaceConversion_o1[i] = cc;
    localB->ColorSpaceConversion_o2[i] = cc_0;
    localB->ColorSpaceConversion_o3[i] = cc_1;
  }

  /* Go from XYZ to sRGB; do it in place on the output buffer */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    cc = (3.24096994190451 * localB->ColorSpaceConversion_o1[i] +
          -1.53738317757009 * localB->ColorSpaceConversion_o2[i]) +
      -0.49861076029299 * localB->ColorSpaceConversion_o3[i];
    cc_0 = (-0.96924363628087 * localB->ColorSpaceConversion_o1[i] +
            1.87596750150771 * localB->ColorSpaceConversion_o2[i]) +
      0.04155505740718 * localB->ColorSpaceConversion_o3[i];
    cc_1 = (0.055630079697 * localB->ColorSpaceConversion_o1[i] +
            -0.20397695888899 * localB->ColorSpaceConversion_o2[i]) +
      1.05697151424288 * localB->ColorSpaceConversion_o3[i];

    /* Apply gamma correction to get R'G'B' */
    if (cc <= 0.00304) {
      cc *= 12.923054468333255;
    } else {
      cc = 1.0550005198172263 * rt_pow_snf(cc, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (cc_0 <= 0.00304) {
      cc_0 *= 12.923054468333255;
    } else {
      cc_0 = 1.0550005198172263 * rt_pow_snf(cc_0, 0.41666666666666669) -
        0.055000519817226347;
    }

    if (cc_1 <= 0.00304) {
      cc_1 *= 12.923054468333255;
    } else {
      cc_1 = 1.0550005198172263 * rt_pow_snf(cc_1, 0.41666666666666669) -
        0.055000519817226347;
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
    localB->ColorSpaceConversion_o1[i] = cc;
    localB->ColorSpaceConversion_o2[i] = cc_0;
    localB->ColorSpaceConversion_o3[i] = cc_1;
  }

  /* Embedded MATLAB: '<S18>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function1': '<S75>:1' */
  /*  This function combines the separate color signals into a single 3-D signal */
  /* '<S75>:1:6' */
  memset((void *)(&localB->RGB[0]), 0, 57600U * sizeof(real_T));

  /* '<S75>:1:8' */
  for (i = 0; i < 120; i++) {
    /* '<S75>:1:8' */
    /* '<S75>:1:9' */
    for (j = 0; j < 160; j++) {
      /* '<S75>:1:9' */
      /* '<S75>:1:10' */
      localB->RGB[i + 120 * j] = localB->ColorSpaceConversion_o1[120 * j + i];

      /* '<S75>:1:11' */
      localB->RGB[19200 + (i + 120 * j)] = localB->ColorSpaceConversion_o2[120 *
        j + i];

      /* '<S75>:1:12' */
      localB->RGB[38400 + (i + 120 * j)] = localB->ColorSpaceConversion_o3[120 *
        j + i];
    }
  }
}

/* Function for Embedded MATLAB: '<S66>/Low Pass Filter' */
static void brain_conv2(const real32_T arg1[19200], const real32_T arg2[9],
  real32_T c[18644])
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
 *    '<S66>/Low Pass Filter'
 *    '<S66>/Low Pass Filter1'
 *    '<S66>/Low Pass Filter2'
 *    '<S125>/Low Pass Filter'
 *    '<S125>/Low Pass Filter1'
 *    '<S125>/Low Pass Filter2'
 */
void brain_LowPassFilter(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB)
{
  real_T G[9];
  real_T Gsum;
  int32_T i;
  real32_T G_0[9];

  /* Embedded MATLAB: '<S66>/Low Pass Filter' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S68>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S68>:1:11' */
  memset((void *)(&localB->Iout[0]), (int32_T)0.0F, 19200U * sizeof(real32_T));

  /* '<S68>:1:17' */
  memset((void *)&G[0], 0, 9U * sizeof(real_T));

  /* '<S68>:1:19' */
  /* '<S68>:1:21' */
  /* '<S68>:1:23' */
  Gsum = 0.0;

  /* '<S68>:1:24' */
  for (i = -1; i < 2; i++) {
    /* '<S68>:1:24' */
    /* '<S68>:1:25' */
    /* '<S68>:1:26' */
    G[i + 1] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S68>:1:27' */
    Gsum += G[i + 1];

    /* '<S68>:1:25' */
    /* '<S68>:1:26' */
    G[i + 4] = exp((real_T)(-(i * i)) / 4.0000000000000009);

    /* '<S68>:1:27' */
    Gsum += G[i + 4];

    /* '<S68>:1:25' */
    /* '<S68>:1:26' */
    G[i + 7] = exp((-((real_T)(i * i) + 1.0)) / 4.0000000000000009);

    /* '<S68>:1:27' */
    Gsum += G[i + 7];
  }

  /* '<S68>:1:31' */
  for (i = 0; i < 9; i++) {
    G[i] = G[i] / Gsum;
  }

  /* '<S68>:1:33' */
  for (i = 0; i < 19200; i++) {
    localB->fv0[i] = (real32_T)rtu_I[i];
  }

  for (i = 0; i < 9; i++) {
    G_0[i] = (real32_T)G[i];
  }

  brain_conv2(&localB->fv0[0], G_0, &localB->Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S68>:1:37' */
  for (i = 0; i < 158; i++) {
    localB->Iout[120 * (1 + i)] = localB->Itemp[118 * i];
  }

  /*  bottom */
  /* '<S68>:1:39' */
  for (i = 0; i < 158; i++) {
    localB->Iout[119 + 120 * (1 + i)] = localB->Itemp[118 * i + 117];
  }

  /*  left */
  /* '<S68>:1:41' */
  memcpy((void *)(&localB->Iout[1]), (void *)(&localB->Itemp[0]), 118U * sizeof
         (real32_T));

  /*  right */
  /* '<S68>:1:43' */
  memcpy((void *)(&localB->Iout[19081]), (void *)(&localB->Itemp[18526]), 118U *
         sizeof(real32_T));

  /*  center */
  /* '<S68>:1:45' */
  for (i = 0; i < 158; i++) {
    memcpy((void *)(&localB->Iout[1 + 120 * (1 + i)]), (void *)(&localB->Itemp
            [118 * i]), 118U * sizeof(real32_T));
  }

  /*  top left corner */
  /* '<S68>:1:47' */
  localB->Iout[0] = localB->Itemp[0];

  /*  top right corner */
  /* '<S68>:1:49' */
  localB->Iout[18960] = localB->Itemp[18408];
  localB->Iout[19080] = localB->Itemp[18526];

  /*  bottom left corner */
  /* '<S68>:1:51' */
  localB->Iout[118] = localB->Itemp[116];
  localB->Iout[119] = localB->Itemp[117];

  /*  bottom right corner */
  /* '<S68>:1:53' */
  localB->Iout[19078] = localB->Itemp[18524];
  localB->Iout[19079] = localB->Itemp[18525];
  localB->Iout[19198] = localB->Itemp[18642];
  localB->Iout[19199] = localB->Itemp[18643];
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
  real_T n;
  real32_T cc_2;
  real32_T Yr;
  real32_T Zr;
  real32_T Xf;
  int32_T indx;
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
  real_T k;
  real32_T Resize2_LineBuffer[120];

  /* S-Function (svipcolorconv): '<S17>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    min_dist = 6.0 * rtu_H[i];
    k = (real_T)(uint32_T)(min_dist - 1.3322676295501878E-15);
    min_dist -= k;
    index = 1.0 - rtu_S[i];
    n = 1.0 - rtu_S[i] * min_dist;
    min_dist = rtu_S[i] * min_dist + index;
    if (k == 0.0) {
      cc = 1.0;
      cc_0 = min_dist;
      cc_1 = index;
    } else if (k == 1.0) {
      cc = n;
      cc_0 = 1.0;
      cc_1 = index;
    } else if (k == 2.0) {
      cc = index;
      cc_0 = 1.0;
      cc_1 = min_dist;
    } else if (k == 3.0) {
      cc = index;
      cc_0 = n;
      cc_1 = 1.0;
    } else if (k == 4.0) {
      cc = min_dist;
      cc_0 = index;
      cc_1 = 1.0;
    } else {
      if (k == 5.0) {
        cc = 1.0;
        cc_0 = index;
        cc_1 = n;
      }
    }

    if (cc > cc_0) {
      min_dist = cc;
    } else {
      min_dist = cc_0;
    }

    if (!(min_dist > cc_1)) {
      min_dist = cc_1;
    }

    min_dist = rtu_V[i] / min_dist;

    /* assign the results */
    localB->ColorSpaceConversion_o1[i] = min_dist * cc;
    localB->ColorSpaceConversion_o2[i] = min_dist * cc_0;
    localB->ColorSpaceConversion_o3[i] = min_dist * cc_1;
  }

  /* Embedded MATLAB: '<S66>/Low Pass Filter' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o1, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S66>/Low Pass Filter1' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o2,
                      &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S66>/Low Pass Filter2' */
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
    if (localB->sf_LowPassFilter.Iout[i] <= 0.0392860845F) {
      dist = localB->sf_LowPassFilter.Iout[i] / 12.9230547F;
    } else {
      dist = rt_pow32_snf((localB->sf_LowPassFilter.Iout[i] + 0.0550005212F) /
                          1.05500054F, 2.4F);
    }

    if (localB->sf_LowPassFilter1.Iout[i] <= 0.0392860845F) {
      Yr = localB->sf_LowPassFilter1.Iout[i] / 12.9230547F;
    } else {
      Yr = rt_pow32_snf((localB->sf_LowPassFilter1.Iout[i] + 0.0550005212F) /
                        1.05500054F, 2.4F);
    }

    if (localB->sf_LowPassFilter2.Iout[i] <= 0.0392860845F) {
      Zr = localB->sf_LowPassFilter2.Iout[i] / 12.9230547F;
    } else {
      Zr = rt_pow32_snf((localB->sf_LowPassFilter2.Iout[i] + 0.0550005212F) /
                        1.05500054F, 2.4F);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    Xf = (0.412390798F * dist + 0.357584327F * Yr) + 0.180480793F * Zr;
    cc_2 = (0.212639F * dist + 0.715168655F * Yr) + 0.0721923187F * Zr;
    dist = (0.0193308182F * dist + 0.119194783F * Yr) + 0.950532138F * Zr;

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

    if (dist > 1.0F) {
      dist = 1.0F;
    } else {
      if (dist < 0.0F) {
        dist = 0.0F;
      }
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = Xf;
    localB->ColorSpaceConversion1_o2[i] = cc_2;
    localB->ColorSpaceConversion1_o3[i] = dist;
  }

  /* Convert from XYZ to L*a*b* */
  for (i = 0; i < 19200; i++) {
    dist = localB->ColorSpaceConversion1_o1[i] / 0.964198649F;
    Zr = localB->ColorSpaceConversion1_o3[i] / 0.825116456F;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (dist > 0.00885645207F) {
      Xf = rt_pow32_snf(dist, 0.333333343F);
    } else {
      Xf = 7.7870369F * dist + 0.137931034F;
    }

    if (localB->ColorSpaceConversion1_o2[i] > 0.00885645207F) {
      Yr = rt_pow32_snf(localB->ColorSpaceConversion1_o2[i], 0.333333343F);
    } else {
      Yr = 7.7870369F * localB->ColorSpaceConversion1_o2[i] + 0.137931034F;
    }

    if (Zr > 0.00885645207F) {
      dist = rt_pow32_snf(Zr, 0.333333343F);
    } else {
      dist = 7.7870369F * Zr + 0.137931034F;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = 116.0F * Yr - 16.0F;
    localB->ColorSpaceConversion1_o2[i] = (Xf - Yr) * 500.0F;
    localB->ColorSpaceConversion1_o3[i] = (Yr - dist) * 200.0F;
  }

  /* S-Function (svipresize): '<S73>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 120; j++) {
    indx = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      i = num_colors + 80;
      dist = localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[num_colors] *
        120 + j] * brain_ConstP.pooled23[num_colors] +
        localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[i] * 120 + j] *
        brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      localDW->Resize_IntBuffer[indx] = dist;
      indx += 120;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize_IntBuffer[num_colors * 120]), 120U * sizeof(real32_T));
    for (j = 0; j < 60; j++) {
      i = j + 60;
      dist = Resize2_LineBuffer[brain_ConstP.pooled29[j]] *
        brain_ConstP.pooled22[j] + Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      localB->Resize[flag] = dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S73>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 120; j++) {
    indx = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      i = num_colors + 80;
      dist = localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[num_colors] *
        120 + j] * brain_ConstP.pooled23[num_colors] +
        localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[i] * 120 + j] *
        brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      localDW->Resize1_IntBuffer[indx] = dist;
      indx += 120;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[num_colors * 120]), 120U * sizeof(real32_T));
    for (j = 0; j < 60; j++) {
      i = j + 60;
      dist = Resize2_LineBuffer[brain_ConstP.pooled29[j]] *
        brain_ConstP.pooled22[j] + Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      localB->Resize1[flag] = dist;
      flag++;
    }
  }

  /* S-Function (svipresize): '<S73>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  flag = 0;
  for (j = 0; j < 120; j++) {
    indx = j;
    for (num_colors = 0; num_colors < 80; num_colors++) {
      i = num_colors + 80;
      dist = localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[num_colors] *
        120 + j] * brain_ConstP.pooled23[num_colors] +
        localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[i] * 120 + j] *
        brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      i += 80;
      dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled30[i] * 120 +
        j] * brain_ConstP.pooled23[i];
      localDW->Resize2_IntBuffer[indx] = dist;
      indx += 120;
    }
  }

  for (num_colors = 0; num_colors < 80; num_colors++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[num_colors * 120]), 120U * sizeof(real32_T));
    for (j = 0; j < 60; j++) {
      i = j + 60;
      dist = Resize2_LineBuffer[brain_ConstP.pooled29[j]] *
        brain_ConstP.pooled22[j] + Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      i += 60;
      dist += Resize2_LineBuffer[brain_ConstP.pooled29[i]] *
        brain_ConstP.pooled22[i];
      localB->Resize2[flag] = dist;
      flag++;
    }
  }

  /* Embedded MATLAB: '<S67>/Reference Color Selection' incorporates:
   *  Constant: '<S67>/Dist_Thresh'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Reference Color Selection': '<S72>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S72>:1:6' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /*  coefficients determining distance calculation */
  /* '<S72>:1:14' */
  /* '<S72>:1:15' */
  memset((void *)(&localB->ref_colors[0]), 0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S72>:1:16' */
  memset((void *)(&localB->LabelMatrix_m[0]), (int32_T)0U, 4800U * sizeof
         (uint32_T));

  /* '<S72>:1:17' */
  num_colors = 1;

  /* '<S72>:1:22' */
  localB->ref_colors[0] = localB->Resize[2369];
  localB->ref_colors[50] = localB->Resize1[2369];
  localB->ref_colors[100] = localB->Resize2[2369];

  /* '<S72>:1:24' */
  flag = 0;

  /* '<S72>:1:25' */
  i = 1;

  /* '<S72>:1:26' */
  j = 1;
  while (i <= 60) {
    /* '<S72>:1:27' */
    /*  perform initial segmentation */
    while ((i <= 60) && (flag == 0)) {
      /* '<S72>:1:28' */
      while ((j <= 80) && (flag == 0)) {
        /* '<S72>:1:29' */
        /* '<S72>:1:30' */
        k = 1.0;

        /* '<S72>:1:31' */
        min_dist = 1000.0;

        /* '<S72>:1:32' */
        index = 1.0;
        while ((uint32_T)k <= (uint32_T)num_colors) {
          /* '<S72>:1:33' */
          /* '<S72>:1:34' */
          dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->ref_colors
            [(int32_T)k + 49] - localB->Resize1[(j - 1) * 60 + (i - 1)], 2.0F) *
            1.5F + rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)k - 1] -
                                localB->Resize[(j - 1) * 60 + (i - 1)], 2.0F)) +
                                rt_pow32_snf((real32_T)localB->ref_colors
            [(int32_T)k + 99] - localB->Resize2[(j - 1) * 60 + (i - 1)], 2.0F) *
                                1.5F);
          if (min_dist > (real_T)dist) {
            /* '<S72>:1:35' */
            /* '<S72>:1:36' */
            min_dist = dist;

            /* '<S72>:1:37' */
            index = k;
          }

          /* '<S72>:1:39' */
          k++;
        }

        if ((min_dist > brain_P.Iter_Segment_Thresh) && (num_colors < 50)) {
          /* '<S72>:1:44' */
          /* '<S72>:1:45' */
          localB->ref_colors[num_colors] = localB->Resize[(j - 1) * 60 + (i - 1)];
          localB->ref_colors[num_colors + 50] = localB->Resize1[(j - 1) * 60 +
            (i - 1)];
          localB->ref_colors[num_colors + 100] = localB->Resize2[(j - 1) * 60 +
            (i - 1)];

          /* '<S72>:1:46' */
          num_colors++;

          /* '<S72>:1:47' */
          flag = 1;

          /* '<S72>:1:48' */
          i = 0;

          /* '<S72>:1:49' */
          j = 0;
        } else {
          /* '<S72>:1:51' */
          localB->LabelMatrix_m[(i - 1) + 60 * (j - 1)] = (uint32_T)index;
        }

        /* '<S72>:1:53' */
        j++;
      }

      /* '<S72>:1:55' */
      j = 1;

      /* '<S72>:1:56' */
      i++;
    }

    /* '<S72>:1:58' */
    flag = 0;
  }

  /*  Go through image once more to get more accurate values for the different regions */
  /* '<S72>:1:62' */
  /* '<S72>:1:63' */
  /* '<S72>:1:64' */
  /* '<S72>:1:65' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = 0.0;
    ref_color_a_avg[i] = 0.0;
    ref_color_b_avg[i] = 0.0;
    color_count[i] = 0.0;
  }

  /* '<S72>:1:66' */
  for (i = 0; i < 60; i++) {
    /* '<S72>:1:66' */
    /* '<S72>:1:67' */
    for (flag = 0; flag < 80; flag++) {
      /* '<S72>:1:67' */
      /* '<S72>:1:68' */
      /* '<S72>:1:69' */
      ref_color_L_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        (real32_T)ref_color_L_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i]
        - 1] + localB->Resize[60 * flag + i];

      /* '<S72>:1:70' */
      ref_color_a_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        (real32_T)ref_color_a_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i]
        - 1] + localB->Resize1[60 * flag + i];

      /* '<S72>:1:71' */
      ref_color_b_avg[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        (real32_T)ref_color_b_avg[(int32_T)localB->LabelMatrix_m[60 * flag + i]
        - 1] + localB->Resize2[60 * flag + i];

      /* '<S72>:1:72' */
      color_count[(int32_T)localB->LabelMatrix_m[i + 60 * flag] - 1] =
        color_count[(int32_T)localB->LabelMatrix_m[60 * flag + i] - 1] + 1.0;
    }
  }

  /* '<S72>:1:75' */
  /* '<S72>:1:76' */
  /* '<S72>:1:77' */
  for (i = 0; i < 50; i++) {
    ref_color_L_avg[i] = ref_color_L_avg[i] / color_count[i];
    ref_color_a_avg[i] = ref_color_a_avg[i] / color_count[i];
    ref_color_b_avg[i] = ref_color_b_avg[i] / color_count[i];
  }

  /* '<S72>:1:79' */
  for (min_dist = 1.0; (uint32_T)min_dist <= (uint32_T)num_colors; min_dist++) {
    /* '<S72>:1:79' */
    /* '<S72>:1:80' */
    localB->ref_colors[(int32_T)min_dist - 1] = ref_color_L_avg[(int32_T)
      min_dist - 1];

    /* '<S72>:1:81' */
    localB->ref_colors[(int32_T)min_dist + 49] = ref_color_a_avg[(int32_T)
      min_dist - 1];

    /* '<S72>:1:82' */
    localB->ref_colors[(int32_T)min_dist + 99] = ref_color_b_avg[(int32_T)
      min_dist - 1];
  }

  localB->num_colors = (real_T)num_colors;

  /* Embedded MATLAB: '<S67>/LabSegmentation' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/LabSegmentation': '<S71>:1' */
  /*  This function generates the label matrix */
  /* '<S71>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), 0, 19200U * sizeof(real_T));

  /* '<S71>:1:12' */
  for (i = 0; i < 120; i++) {
    /* '<S71>:1:12' */
    /* '<S71>:1:13' */
    for (j = 0; j < 160; j++) {
      /* '<S71>:1:13' */
      /* '<S71>:1:14' */
      min_dist = 1000.0;

      /* '<S71>:1:15' */
      index = 1.0;

      /* '<S71>:1:16' */
      for (k = 1.0; k <= localB->num_colors; k++) {
        /* '<S71>:1:16' */
        /* '<S71>:1:17' */
        dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->ref_colors
          [(int32_T)k - 1] - localB->ColorSpaceConversion1_o1[120 * j + i], 2.0F)
          + rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)k + 49] -
                         localB->ColorSpaceConversion1_o2[120 * j + i], 2.0F)) +
                              rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)
          k + 99] - localB->ColorSpaceConversion1_o3[120 * j + i], 2.0F));
        if ((real_T)dist < min_dist) {
          /* '<S71>:1:18' */
          /* '<S71>:1:19' */
          min_dist = dist;

          /* '<S71>:1:20' */
          index = k;
        }
      }

      /* '<S71>:1:23' */
      localB->LabelMatrix[i + 120 * j] = index;
    }
  }

  /* '<S71>:1:27' */
}

/* Function for Embedded MATLAB: '<S14>/Blob Extraction' */
static void brain_Outputs_f(const boolean_T U0[19200], int32_T Y0[50], real_T
  Y1[100], real_T Y2[50], real_T Y3[50], uint8_T *Y4,
  rtDW_StateFlowFunctionsBuoysF_e *localDW)
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
          for (pixListMinc = 0; pixListMinc < 8; pixListMinc++) {
            walkerIdx = k + (uint32_T)localDW->WALKER_RTP[pixListMinc];
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
  *Y4 = (uint8_T)numBlobs;
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
    Y2[c_i] = sqrt(majorAxis - ((centroid_idx + uyy) - xs) * 8.0) / sqrt
      (majorAxis);
    Y3[c_i] = (real_T)localDW->NUM_PIX_DW[c_i] / (real_T)(((maxr + 1) - idx) *
      ((maxc + 1) - n));
    pixListMinc += (int32_T)localDW->NUM_PIX_DW[c_i];
    pixListNinc += (int32_T)localDW->NUM_PIX_DW[c_i];
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y0[loop] = localDW->F0_RTP;
  }

  for (loop = (int32_T)((uint32_T)numBlobs << 1); loop < 100; loop++) {
    Y1[loop] = localDW->F1_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y2[loop] = localDW->F2_RTP;
  }

  for (loop = numBlobs; loop < 50; loop++) {
    Y3[loop] = localDW->F3_RTP;
  }
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
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysFindBu_l(const real_T rtu_LabelMatrix[19200], real_T
  rtu_num_colors, const real_T rtu_ref_colors[150],
  rtB_StateFlowFunctionsBuoysFi_d *localB, rtDW_StateFlowFunctionsBuoysF_e
  *localDW)
{
  real_T num_colors;
  uint8_T TotalNum;
  real_T k;
  uint8_T b_i;
  int32_T TArea[50];
  uint8_T TNumBlobs;
  real_T colors[150];
  real_T centX[50];
  real_T centY[50];
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k_0;
  int32_T b_k;
  boolean_T guard;
  boolean_T exitg;
  real_T rtb_Centroid_Out[100];
  int32_T i;

  /* Embedded MATLAB: '<S14>/Blob Extraction' */
  num_colors = rtu_num_colors;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Blob Extraction': '<S61>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S61>:1:7' */
  for (i = 0; i < 19200; i++) {
    localB->LogicMatrix[i] = FALSE;
  }

  /* '<S61>:1:9' */
  /* '<S61>:1:12' */
  memset((void *)(&localB->Area[0]), 0, 50U * sizeof(real_T));

  /* '<S61>:1:13' */
  memset((void *)(&localB->Centroid[0]), 0, 100U * sizeof(real_T));

  /* '<S61>:1:14' */
  /* '<S61>:1:15' */
  for (i = 0; i < 50; i++) {
    localB->Eccent[i] = 0.0;
    localB->Extent[i] = 0.0;
  }

  /* '<S61>:1:17' */
  TotalNum = 0U;

  /* '<S61>:1:27' */
  for (k = 1.0; k <= num_colors; k++) {
    /* '<S61>:1:27' */
    /* '<S61>:1:28' */
    for (k_0 = 0; k_0 < 120; k_0++) {
      /* '<S61>:1:28' */
      /* '<S61>:1:29' */
      for (b_k = 0; b_k < 160; b_k++) {
        /* '<S61>:1:29' */
        if (rtu_LabelMatrix[120 * b_k + k_0] != k) {
          /* '<S61>:1:30' */
          /* '<S61>:1:31' */
          localB->LogicMatrix[k_0 + 120 * b_k] = FALSE;
        } else {
          /* '<S61>:1:33' */
          localB->LogicMatrix[k_0 + 120 * b_k] = TRUE;
        }
      }
    }

    brain_Outputs_f(&localB->LogicMatrix[0], TArea, rtb_Centroid_Out, centX,
                    centY, &TNumBlobs, localDW);
    i = (int32_T)((uint32_T)TNumBlobs + (uint32_T)TotalNum);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    if (i < 50) {
      /* '<S61>:1:39' */
      /* '<S61>:1:40' */
      for (b_i = 1U; b_i <= TNumBlobs; b_i = (uint8_T)((uint32_T)b_i + 1U)) {
        /* '<S61>:1:40' */
        /* '<S61>:1:41' */
        i = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        localB->Area[i - 1] = (real_T)TArea[b_i - 1];

        /* '<S61>:1:42' */
        i = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        localB->Centroid[i - 1] = rtb_Centroid_Out[(b_i - 1) << 1];

        /* '<S61>:1:43' */
        i = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        localB->Centroid[i + 49] = rtb_Centroid_Out[((b_i - 1) << 1) + 1];

        /* '<S61>:1:44' */
        i = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        localB->Eccent[i - 1] = centX[b_i - 1];

        /* '<S61>:1:45' */
        i = (int32_T)((uint32_T)TotalNum + (uint32_T)b_i);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        localB->Extent[i - 1] = centY[b_i - 1];
      }

      /* '<S61>:1:47' */
      i = (int32_T)((uint32_T)TotalNum + (uint32_T)TNumBlobs);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      TotalNum = (uint8_T)i;
    }
  }

  localB->TotalNum = TotalNum;

  /* Embedded MATLAB: '<S14>/IF Buoy Conditions' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Constant3'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions': '<S62>:1' */
  /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
  /*  the cenroids of the most circular objects in the image */
  /* '<S62>:1:5' */
  num_colors = 0.0;

  /* '<S62>:1:6' */
  memset((void *)&rtb_Centroid_Out[0], 0, 100U * sizeof(real_T));

  /* '<S62>:1:9' */
  for (TotalNum = 1U; TotalNum <= localB->TotalNum; TotalNum = (uint8_T)
       ((uint32_T)TotalNum + 1U)) {
    /* '<S62>:1:9' */
    if ((localB->Eccent[TotalNum - 1] > brain_P.Buoy_Min_Eccentricity) &&
        (localB->Eccent[TotalNum - 1] < brain_P.Buoy_Max_Eccentricity) &&
        (localB->Extent[TotalNum - 1] > brain_P.Buoy_Min_Extent) &&
        (localB->Extent[TotalNum - 1] < brain_P.Buoy_Max_Extent)) {
      /* '<S62>:1:10' */
      /* '<S62>:1:11' */
      num_colors++;

      /* '<S62>:1:12' */
      rtb_Centroid_Out[(int32_T)num_colors - 1] = localB->Centroid[TotalNum - 1];

      /* '<S62>:1:13' */
      rtb_Centroid_Out[(int32_T)num_colors + 49] = localB->Centroid[TotalNum +
        49];
    }
  }

  localB->count = num_colors;

  /* Embedded MATLAB: '<S14>/Say Which Buoy Is Which' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which': '<S63>:1' */
  /*  This function determines which buoy is in which location, left, middle, */
  /*  or right. */
  /* '<S63>:1:6' */
  memset((void *)&colors[0], 0, 150U * sizeof(real_T));

  /* '<S63>:1:7' */
  /* '<S63>:1:8' */
  for (i = 0; i < 50; i++) {
    centX[i] = 0.0;
    centY[i] = 0.0;
  }

  /* '<S63>:1:10' */
  memset((void *)(&localB->blobs[0]), 0, 200U * sizeof(real_T));

  /* '<S63>:1:12' */
  for (num_colors = 1.0; num_colors <= localB->count; num_colors++) {
    /* '<S63>:1:12' */
    /* '<S63>:1:13' */
    centX[(int32_T)num_colors - 1] = floor(rtb_Centroid_Out[(int32_T)num_colors
      + 49]);

    /* '<S63>:1:14' */
    centY[(int32_T)num_colors - 1] = floor(rtb_Centroid_Out[(int32_T)num_colors
      - 1]);
    if (centX[(int32_T)num_colors - 1] < 1.0) {
      /* '<S63>:1:15' */
      /* '<S63>:1:16' */
      centX[(int32_T)num_colors - 1] = 1.0;
    }

    if (centY[(int32_T)num_colors - 1] < 1.0) {
      /* '<S63>:1:18' */
      /* '<S63>:1:19' */
      centY[(int32_T)num_colors - 1] = 1.0;
    }

    /* '<S63>:1:22' */
    /* '<S63>:1:24' */
    i = (int32_T)num_colors - 1;
    colors[i] = rtu_ref_colors[(int32_T)rtu_LabelMatrix[((int32_T)centX[(int32_T)
      num_colors - 1] - 1) * 120 + ((int32_T)centY[(int32_T)num_colors - 1] - 1)]
      - 1];
    colors[i + 50] = rtu_ref_colors[(int32_T)rtu_LabelMatrix[((int32_T)centX
      [(int32_T)num_colors - 1] - 1) * 120 + ((int32_T)centY[(int32_T)num_colors
      - 1] - 1)] + 49];
    colors[i + 100] = rtu_ref_colors[(int32_T)rtu_LabelMatrix[((int32_T)centX
      [(int32_T)num_colors - 1] - 1) * 120 + ((int32_T)centY[(int32_T)num_colors
      - 1] - 1)] + 99];
  }

  /*  Putting blobs in order from left to right */
  /* '<S63>:1:28' */
  for (num_colors = 1.0; num_colors <= localB->count; num_colors++) {
    /* '<S63>:1:28' */
    k = centX[0];
    i = 1;
    ix = 1;
    guard = FALSE;
    if (rtIsNaN(centX[0])) {
      searchingForNonNaN = TRUE;
      k_0 = 2;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (k_0 < 51)) {
        ix++;
        if (!rtIsNaN(centX[ix - 1])) {
          k = centX[ix - 1];
          i = k_0;
          searchingForNonNaN = FALSE;
          exitg = TRUE;
        } else {
          k_0++;
        }
      }

      if (!searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (b_k = i + 1; b_k < 51; b_k++) {
        ix++;
        if (centX[ix - 1] < k) {
          k = centX[ix - 1];
          i = b_k;
        }
      }
    }

    /* '<S63>:1:30' */
    localB->blobs[(int32_T)num_colors - 1] = colors[i - 1];

    /* '<S63>:1:31' */
    localB->blobs[(int32_T)num_colors + 49] = colors[i + 49];

    /* '<S63>:1:32' */
    localB->blobs[(int32_T)num_colors + 99] = colors[i + 99];

    /* '<S63>:1:33' */
    localB->blobs[(int32_T)num_colors + 149] = localB->Area[i - 1];

    /* '<S63>:1:34' */
    centX[i - 1] = 1000.0;
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
  /* Disable for If: '<S39>/If' */
  localDW->If_ActiveSubsystem = -1;

  /* Disable for ifaction SubSystem: '<S39>/BigError S1' */

  /* Disable for Outport: '<S138>/Out2' */
  localB->Constant1_e = 0.0;

  /* end of Disable for SubSystem: '<S39>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S39>/BigNegativeError S2' */

  /* Disable for Outport: '<S139>/Out2' */
  localB->Constant1 = 0.0;

  /* end of Disable for SubSystem: '<S39>/BigNegativeError S2' */
}

/* Start for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsMaintai_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW)
{
  /* Start for If: '<S39>/If' */
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

  /* Sum: '<S39>/Add1' */
  rtb_Add1 = rtu_DesiredHeading1 - rtu_CurrentHeading1;

  /* If: '<S39>/If' incorporates:
   *  ActionPort: '<S138>/Action Port'
   *  ActionPort: '<S139>/Action Port'
   *  SubSystem: '<S39>/BigError S1'
   *  SubSystem: '<S39>/BigNegativeError S2'
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
      /* Disable for Outport: '<S138>/Out2' */
      localB->Constant1_e = 0.0;
      break;

     case 1:
      /* Disable for Outport: '<S139>/Out2' */
      localB->Constant1 = 0.0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Sum: '<S138>/Add' incorporates:
     *  Constant: '<S138>/Constant'
     */
    localB->Add_o = rtb_Add1 - 360.0;

    /* Constant: '<S138>/Constant1' */
    localB->Constant1_e = 1.0;
    break;

   case 1:
    /* Sum: '<S139>/Add' incorporates:
     *  Constant: '<S139>/Constant'
     */
    localB->Add = rtb_Add1 + 360.0;

    /* Constant: '<S139>/Constant1' */
    localB->Constant1 = 2.0;
    break;
  }

  /* MultiPortSwitch: '<S39>/Multiport Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Sum: '<S39>/Add2'
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

  /* SampleTimeMath: '<S141>/TSamp' incorporates:
   *  Gain: '<S140>/Heading Derivative Gain'
   *
   * About '<S141>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_j = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
    localDW->StateFlowFunctionsMaintainHea_e * 0.2);

  /* Sum: '<S140>/Sum' incorporates:
   *  DiscreteIntegrator: '<S140>/Heading Discrete-Time Integrator'
   *  Gain: '<S140>/Heading Proportional Gain'
   *  Sum: '<S141>/Diff'
   *  UnitDelay: '<S141>/UD'
   *
   * Block description for '<S141>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S141>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_j - localDW->UD_DSTATE))
    + localDW->HeadingDiscreteTimeIntegrator_D;

  /* Product: '<S39>/Multiply' incorporates:
   *  Constant: '<S39>/Constant'
   */
  tmp = -rtb_Add4;
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(floor(tmp), 256.0);
  }

  /* Sum: '<S39>/Add4' */
  rtb_Add4 += rtu_ForwardVelocity1;

  /* DataTypeConversion: '<S39>/DoubleToint1' incorporates:
   *  Sum: '<S39>/Add3'
   */
  tmp = (real_T)(int8_T)(tmp < 0.0 ? (int8_T)(-((int8_T)(uint8_T)(-tmp))) :
    (int8_T)(uint8_T)tmp) + rtu_ForwardVelocity1;
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

  /* DataTypeConversion: '<S39>/DoubleToint8' */
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

  /* Update for UnitDelay: '<S141>/UD'
   * Block description for '<S141>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_j;

  /* Update for DiscreteIntegrator: '<S140>/Heading Discrete-Time Integrator' incorporates:
   *  Gain: '<S140>/Heading Integral Gain'
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
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T m;
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

  /* Logic: '<S142>/Logical Operator1' incorporates:
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Constant: '<S146>/Constant'
   *  Logic: '<S142>/Logical Operator'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S146>/Compare'
   */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (((rtu_H[i] < brain_P.Track_HueLower) || (rtu_H[i] >
      brain_P.Track_HueHigher)) && (rtu_S[i] > brain_P.Track_Saturation));
  }

  /* S-Function (svipblob): '<S142>/Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (loop = 0; loop < 123; loop++) {
    localDW->BlobAnalysis_PAD_DW[loop] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (loop = 0; loop < 160; loop++) {
    for (m = 0; m < 120; m++) {
      localDW->BlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 : 0);
      i++;
      idx++;
    }

    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
    localDW->BlobAnalysis_PAD_DW[idx] = 0U;
    idx++;
  }

  for (loop = 0; loop < 121; loop++) {
    localDW->BlobAnalysis_PAD_DW[loop + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (loop = 0; loop < 160; loop++) {
    ms = 1;
    j = nn * 122;
    for (m = 0; m < 120; m++) {
      numBlobs = (uint32_T)(j + ms);
      start_pixIdx = pixIdx;
      if (localDW->BlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
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
          loop = 160;
          m = 120;
        }

        if (m < 120) {
          currentLabel++;
        }
      }

      ms++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  loop = 0;
  idx = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    nn = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
      nn += localDW->BlobAnalysis_N_PIXLIST_DW[j + idx];
      ms += localDW->BlobAnalysis_M_PIXLIST_DW[j + loop];
    }

    centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW;
    centroid_idx_0 = (real32_T)nn / (real32_T)BlobAnalysis_NUM_PIX_DW;
    rtb_BlobAnalysis = 0.0F;
    ys = 0.0F;
    xys = 0.0F;
    for (k = 0U; k < (uint32_T)(int32_T)BlobAnalysis_NUM_PIX_DW; k++) {
      majorAxis = (real32_T)localDW->BlobAnalysis_N_PIXLIST_DW[idx + (int32_T)k]
        - centroid_idx_0;
      uyy = (real32_T)localDW->BlobAnalysis_M_PIXLIST_DW[loop + (int32_T)k] -
        centroid_idx;
      rtb_BlobAnalysis += majorAxis * majorAxis;
      ys += uyy * uyy;
      xys += majorAxis * (-uyy);
    }

    centroid_idx = rtb_BlobAnalysis / (real32_T)BlobAnalysis_NUM_PIX_DW +
      0.0833333358F;
    uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 0.0833333358F;
    rtb_BlobAnalysis = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
    rtb_BlobAnalysis = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx - uyy)
      + rtb_BlobAnalysis * rtb_BlobAnalysis * 4.0F);
    majorAxis = ((centroid_idx + uyy) + rtb_BlobAnalysis) * 8.0F;
    rtb_BlobAnalysis = (real32_T)sqrt(majorAxis - ((centroid_idx + uyy) -
      rtb_BlobAnalysis) * 8.0F) / (real32_T)sqrt(majorAxis);
    loop += (int32_T)BlobAnalysis_NUM_PIX_DW;
    idx += (int32_T)BlobAnalysis_NUM_PIX_DW;
  }

  for (loop = (int32_T)numBlobs; loop < 1; loop = 1) {
    rtb_BlobAnalysis = -1.0F;
  }

  /* Embedded MATLAB: '<S142>/CheckConditions' incorporates:
   *  Constant: '<S142>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions': '<S143>:1' */
  /*  This function checks the conditions to decide if a track is present */
  if ((real_T)rtb_BlobAnalysis > brain_P.Track_Min_Eccentricity) {
    /* '<S143>:1:4' */
    /* '<S143>:1:5' */
    localB->Image = 1.0;
  } else {
    /* '<S143>:1:7' */
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

  /* SampleTimeMath: '<S79>/TSamp' incorporates:
   *  Gain: '<S78>/CamDownStrafe-X Derivative Gain'
   *
   * About '<S79>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_p = brain_P.Cam_Down_Strafe_XPos_Kd * rtu_HeadingAlong / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_j * 0.2);

  /* Embedded MATLAB: '<S20>/Embedded MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<S78>/Depth Discrete-Time Integrator'
   *  Gain: '<S78>/CamDownStrafe-X Proportional Gain'
   *  Gain: '<S78>/Gain'
   *  Sum: '<S78>/Sum'
   *  Sum: '<S79>/Diff'
   *  UnitDelay: '<S79>/UD'
   *
   * Block description for '<S79>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S79>/UD':
   *
   *  Store in Global RAM
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/Embedded MATLAB Function': '<S77>:1' */
  /*  This function makes sure the path was seen and if not, the only sends the */
  /*  forward command to the thrusters */
  if (rtu_HeadingAlong == -999.0) {
    /* '<S77>:1:5' */
    /* '<S77>:1:6' */
    rtb_Strafe = 0.0;
  } else {
    /* '<S77>:1:8' */
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

  /* Update for UnitDelay: '<S79>/UD'
   * Block description for '<S79>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_p;

  /* Update for DiscreteIntegrator: '<S78>/Depth Discrete-Time Integrator' incorporates:
   *  Gain: '<S78>/CamDownStrafe-X Integral Gain'
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
static void brain_max(const real_T varargin_1[10], real_T *maxval, real_T *indx)
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (k < 11)) {
      ix++;
      if (!rtIsNaN(varargin_1[ix - 1])) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
        searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        k++;
      }
    }

    if (!searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (k = itmp + 1; k < 11; k++) {
      ix++;
      if (varargin_1[ix - 1] > mtmp) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
      }
    }
  }

  *maxval = mtmp;
  *indx = (real_T)itmp;
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
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T Area[10];
  int32_T i;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  real_T rtb_TmpSignalConversionAtDraw_f[2];
  real_T rtb_Sum_c;
  real_T rtb_Error_m;
  real_T rtb_TSamp_ct;
  real_T rtb_TSamp_o;
  int32_T rtb_BuoyBlobAnalysis_o1_l[10];
  real_T rtb_BuoyBlobAnalysis_o2_h[20];
  real_T rtb_BuoyBlobAnalysis_o1_l_0[10];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
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
  for (loop = 0; loop < 123; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (padCols = 0; padCols < 120; padCols++) {
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

  for (loop = 0; loop < 121; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    ms = 1;
    j = nn * 122;
    for (padCols = 0; padCols < 120; padCols++) {
      numBlobs = (uint32_T)(j + ms);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
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
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
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
          n = 160;
          padCols = 120;
        }

        if (padCols < 120) {
          currentLabel++;
        }
      }

      ms++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  loop = 0;
  idx = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    rtb_BuoyBlobAnalysis_o1_l[i] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    nn = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i]; j++) {
      nn += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + idx];
      ms += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + loop];
    }

    rtb_TmpSignalConversionAtDraw_f[0] = (real_T)ms / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_TmpSignalConversionAtDraw_f[1] = (real_T)nn / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_BuoyBlobAnalysis_o2_h[i << 1] = rtb_TmpSignalConversionAtDraw_f[0];
    rtb_BuoyBlobAnalysis_o2_h[(i << 1) + 1] = rtb_TmpSignalConversionAtDraw_f[1];
    loop += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    idx += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
  }

  for (loop = (int32_T)numBlobs; loop < 10; loop++) {
    rtb_BuoyBlobAnalysis_o1_l[loop] = -1;
  }

  for (loop = (int32_T)(numBlobs << 1); loop < 20; loop++) {
    rtb_BuoyBlobAnalysis_o2_h[loop] = -1.0;
  }

  /* Embedded MATLAB: '<S23>/Embedded MATLAB Function' */
  for (i = 0; i < 10; i++) {
    Area[i] = rtb_BuoyBlobAnalysis_o1_l[i];
  }

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function': '<S91>:1' */
  /*  This function will choose and return data about the largest/left blob  */
  /*  given a set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_h[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_h[1] ==
       -1.0)) {
    /* '<S91>:1:5' */
    /* '<S91>:1:7' */
    rtb_Error_m = 80.0;

    /* '<S91>:1:8' */
    rtb_TSamp_o = 60.0;
  } else {
    for (i = 0; i < 10; i++) {
      rtb_BuoyBlobAnalysis_o1_l_0[i] = (real_T)rtb_BuoyBlobAnalysis_o1_l[i];
    }

    brain_max(rtb_BuoyBlobAnalysis_o1_l_0, &rtb_Error_m, &rtb_Sum_c);

    /* '<S91>:1:12' */
    Area[(int32_T)rtb_Sum_c - 1] = 0;
    for (i = 0; i < 10; i++) {
      rtb_BuoyBlobAnalysis_o1_l_0[i] = (real_T)Area[i];
    }

    brain_max(rtb_BuoyBlobAnalysis_o1_l_0, &rtb_TSamp_o, &rtb_TSamp_ct);
    if (rtb_Error_m < rtb_TSamp_o * 1.25) {
      /* '<S91>:1:15' */
      if (rtb_BuoyBlobAnalysis_o2_h[(((int32_T)rtb_Sum_c - 1) << 1U) + 1] >
          rtb_BuoyBlobAnalysis_o2_h[(((int32_T)rtb_TSamp_ct - 1) << 1U) + 1]) {
        /* '<S91>:1:16' */
        /* '<S91>:1:17' */
        rtb_Error_m = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)rtb_TSamp_ct - 1) <<
          1U) + 1];

        /* '<S91>:1:18' */
        rtb_TSamp_o = rtb_BuoyBlobAnalysis_o2_h[((int32_T)rtb_TSamp_ct - 1) <<
          1U];
      } else {
        /* '<S91>:1:20' */
        rtb_Error_m = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)rtb_Sum_c - 1) << 1U)
          + 1];

        /* '<S91>:1:21' */
        rtb_TSamp_o = rtb_BuoyBlobAnalysis_o2_h[((int32_T)rtb_Sum_c - 1) << 1U];
      }
    } else {
      /* '<S91>:1:24' */
      rtb_Error_m = rtb_BuoyBlobAnalysis_o2_h[(((int32_T)rtb_Sum_c - 1) << 1U) +
        1];

      /* '<S91>:1:25' */
      rtb_TSamp_o = rtb_BuoyBlobAnalysis_o2_h[((int32_T)rtb_Sum_c - 1) << 1U];
    }
  }

  /* SignalConversion: '<S23>/TmpSignal ConversionAtDraw MarkersInport2' */
  rtb_TmpSignalConversionAtDraw_f[0] = rtb_TSamp_o;
  rtb_TmpSignalConversionAtDraw_f[1] = rtb_Error_m;

  /* S-Function (svipdrawmarkers): '<S23>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)(&rtu_BW[0]), 19200U *
         sizeof(real_T));

  /* Draw all X marks. */
  for (n = 0; n < 2; n += 2) {
    tmp = rtb_TmpSignalConversionAtDraw_f[n];
    if ((rtb_TmpSignalConversionAtDraw_f[n] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDraw_f[n] > -4.503599627370496E+15)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_f[n] + 0.5);
    }

    padCols = (int32_T)tmp;
    tmp = rtb_TmpSignalConversionAtDraw_f[n + 1];
    if ((rtb_TmpSignalConversionAtDraw_f[n + 1] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDraw_f[n + 1] > -4.503599627370496E+15)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_f[n + 1] + 0.5);
    }

    i = (int32_T)tmp;
    idx = padCols - 7;
    line_idx = i - 7;
    line_idx_0 = padCols + 7;
    line_idx_1 = i + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    j = idx;
    line_idx_2 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_4 = line_idx_1;
    while (!done) {
      numBlobs = 0U;
      walkerIdx = 0U;

      /* Determine viewport violations. */
      if (j < 0) {
        numBlobs = 4U;
      } else {
        if (j > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_3 < 0) {
        walkerIdx = 4U;
      } else {
        if (line_idx_3 > 119) {
          walkerIdx = 8U;
        }
      }

      if (line_idx_2 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_2 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_4 < 0) {
        walkerIdx |= 1U;
      } else {
        if (line_idx_4 > 159) {
          walkerIdx |= 2U;
        }
      }

      if (!(numBlobs | walkerIdx)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & walkerIdx) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          j = idx;
          line_idx_2 = line_idx;
        }

        loop = line_idx_3 - j;
        nn = line_idx_4 - line_idx_2;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          ms = (0 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          ms = (119 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_3 = line_idx_0;
          line_idx_4 = line_idx_1;
        }

        loop = line_idx_3 - j;
        nn = line_idx_4 - line_idx_2;
        if (walkerIdx & 4U) {
          /* Violated RMin. */
          ms = (0 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else if (walkerIdx & 8U) {
          /* Violated RMax. */
          ms = (119 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        } else if (walkerIdx & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ms = line_idx_2 * 120 + j;
      while (j <= line_idx_3) {
        localB->DrawMarkers[ms] = 0.75;
        ms += 121;
        j++;
      }
    }

    idx = padCols - 7;
    line_idx = i + 7;
    line_idx_0 = padCols + 7;
    line_idx_1 = i - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    j = idx;
    line_idx_2 = line_idx;
    line_idx_3 = line_idx_0;
    line_idx_4 = line_idx_1;
    while (!done) {
      numBlobs = 0U;
      walkerIdx = 0U;

      /* Determine viewport violations. */
      if (j < 0) {
        numBlobs = 4U;
      } else {
        if (j > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_3 < 0) {
        walkerIdx = 4U;
      } else {
        if (line_idx_3 > 119) {
          walkerIdx = 8U;
        }
      }

      if (line_idx_2 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_2 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_4 < 0) {
        walkerIdx |= 1U;
      } else {
        if (line_idx_4 > 159) {
          walkerIdx |= 2U;
        }
      }

      if (!(numBlobs | walkerIdx)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & walkerIdx) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          j = idx;
          line_idx_2 = line_idx;
        }

        loop = line_idx_3 - j;
        nn = line_idx_4 - line_idx_2;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          ms = (0 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          ms = (119 - j) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_2 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          j = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_2) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            j += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            j += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_3 = line_idx_0;
          line_idx_4 = line_idx_1;
        }

        loop = line_idx_3 - j;
        nn = line_idx_4 - line_idx_2;
        if (walkerIdx & 4U) {
          /* Violated RMin. */
          ms = (0 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited_0 = TRUE;
        } else if (walkerIdx & 8U) {
          /* Violated RMax. */
          ms = (119 - line_idx_3) * nn;
          if (((ms >= 0) && (loop >= 0)) || ((ms < 0) && (loop < 0))) {
            line_idx_4 += (div_s32_floor(ms << 1U, loop) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-ms) << 1U, loop) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited_0 = TRUE;
        } else if (walkerIdx & 1U) {
          /* Violated CMin. */
          ms = (0 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          ms = (159 - line_idx_4) * loop;
          if (((ms >= 0) && (nn >= 0)) || ((ms < 0) && (nn < 0))) {
            line_idx_3 += (div_s32_floor(ms << 1U, nn) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-ms) << 1U, nn) + 1) >> 1);
          }

          line_idx_4 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      ms = line_idx_2 * 120 + j;
      while (j <= line_idx_3) {
        localB->DrawMarkers[ms] = 0.75;
        ms += -119;
        j++;
      }
    }
  }

  /* Embedded MATLAB: '<S23>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S23>/Subtract' */
  localB->Subtract = rtb_Error_m - localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* Sum: '<S23>/Subtract1' */
  localB->Subtract1 = rtb_TSamp_o - localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* Sum: '<S93>/Subtract' */
  rtb_Sum_c = localB->sf_EmbeddedMATLABFunction1.XCenter - rtb_Error_m;

  /* SampleTimeMath: '<S96>/TSamp' incorporates:
   *  Gain: '<S95>/CamDown Strafe XPos Derivative Gain'
   *
   * About '<S96>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_ct = brain_P.Cam_Down_Strafe_XPos_Kd * rtb_Sum_c / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S93>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S95>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S95>/CamDown Strafe XPos Proportional Gain'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S96>/Diff'
   *  UnitDelay: '<S96>/UD'
   *
   * Block description for '<S96>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S96>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_Strafe_XPos_Kp * rtb_Sum_c + (rtb_TSamp_ct -
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

  /* Sum: '<S94>/Subtract' */
  rtb_Error_m = localB->sf_EmbeddedMATLABFunction1.YCenter - rtb_TSamp_o;

  /* SampleTimeMath: '<S98>/TSamp' incorporates:
   *  Gain: '<S97>/Y-Buoy Derivative Gain'
   *
   * About '<S98>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_o = brain_P.Cam_Down_YPos_Kd * rtb_Error_m / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S94>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S97>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S97>/Y-Buoy Proportional Gain'
   *  Sum: '<S97>/Sum'
   *  Sum: '<S98>/Diff'
   *  UnitDelay: '<S98>/UD'
   *
   * Block description for '<S98>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S98>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_YPos_Kp * rtb_Error_m + (rtb_TSamp_o -
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

  /* Update for UnitDelay: '<S96>/UD'
   * Block description for '<S96>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_ct;

  /* Update for DiscreteIntegrator: '<S95>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S95>/CamDown Strafe XPos Integral Gain'
   */
  localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_Strafe_XPos_Ki *
    rtb_Sum_c) + localDW->XBuoyDiscreteTimeIntegrator_DST;
  if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }

  /* Update for UnitDelay: '<S98>/UD'
   * Block description for '<S98>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_n = rtb_TSamp_o;

  /* Update for DiscreteIntegrator: '<S97>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S97>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_YPos_Ki *
    rtb_Error_m) + localDW->YBuoyDiscreteTimeIntegrator_DST;
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
  real_T min_dist;
  real_T dist;
  real_T i;
  int8_T rtb_index_j;
  int32_T i_0;

  /* S-Function (svipcolorconv): '<S124>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  min_dist = 6.0 * rtu_B_Hue;
  Xf = (real_T)(uint32_T)(min_dist - 1.3322676295501878E-15);
  min_dist -= Xf;
  i = 1.0 - rtu_B_Sat;
  dist = 1.0 - rtu_B_Sat * min_dist;
  min_dist = rtu_B_Sat * min_dist + i;
  if (Xf == 0.0) {
    cc = 1.0;
    cc_0 = min_dist;
    cc_1 = i;
  } else if (Xf == 1.0) {
    cc = dist;
    cc_0 = 1.0;
    cc_1 = i;
  } else if (Xf == 2.0) {
    cc = i;
    cc_0 = 1.0;
    cc_1 = min_dist;
  } else if (Xf == 3.0) {
    cc = i;
    cc_0 = dist;
    cc_1 = 1.0;
  } else if (Xf == 4.0) {
    cc = min_dist;
    cc_0 = i;
    cc_1 = 1.0;
  } else {
    if (Xf == 5.0) {
      cc = 1.0;
      cc_0 = i;
      cc_1 = dist;
    }
  }

  if (cc > cc_0) {
    min_dist = cc;
  } else {
    min_dist = cc_0;
  }

  if (!(min_dist > cc_1)) {
    min_dist = cc_1;
  }

  min_dist = rtu_B_Value / min_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o1 = min_dist * cc;
  localB->ColorSpaceConversion_o2 = min_dist * cc_0;
  localB->ColorSpaceConversion_o3 = min_dist * cc_1;

  /* S-Function (svipcolorconv): '<S124>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 0.039286085583733095) {
    min_dist = localB->ColorSpaceConversion_o1 / 12.923054468333255;
  } else {
    min_dist = (localB->ColorSpaceConversion_o1 + 0.055000519817226347) /
      1.0550005198172263;
    min_dist = rt_pow_snf(min_dist, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 0.039286085583733095) {
    i = localB->ColorSpaceConversion_o2 / 12.923054468333255;
  } else {
    i = (localB->ColorSpaceConversion_o2 + 0.055000519817226347) /
      1.0550005198172263;
    i = rt_pow_snf(i, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 0.039286085583733095) {
    dist = localB->ColorSpaceConversion_o3 / 12.923054468333255;
  } else {
    dist = (localB->ColorSpaceConversion_o3 + 0.055000519817226347) /
      1.0550005198172263;
    dist = rt_pow_snf(dist, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  cc = (0.41239079926596 * min_dist + 0.35758433938388 * i) + 0.18048078840183 *
    dist;
  cc_0 = (0.21263900587151 * min_dist + 0.71516867876776 * i) + 0.07219231536073
    * dist;
  cc_1 = (0.01933081871559 * min_dist + 0.11919477979463 * i) + 0.95053215224966
    * dist;

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
  localB->ColorSpaceConversion1_o1 = cc;
  localB->ColorSpaceConversion1_o2 = cc_0;
  localB->ColorSpaceConversion1_o3 = cc_1;

  /* Convert from XYZ to L*a*b* */
  min_dist = localB->ColorSpaceConversion1_o1 / 0.9641986557609;
  dist = localB->ColorSpaceConversion1_o3 / 0.82511648322104;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (min_dist > 0.0088564516790356311) {
    Xf = rt_pow_snf(min_dist, 0.33333333333333331);
  } else {
    Xf = 7.7870370370370372 * min_dist + 0.13793103448275862;
  }

  if (localB->ColorSpaceConversion1_o2 > 0.0088564516790356311) {
    i = rt_pow_snf(localB->ColorSpaceConversion1_o2, 0.33333333333333331);
  } else {
    i = 7.7870370370370372 * localB->ColorSpaceConversion1_o2 +
      0.13793103448275862;
  }

  if (dist > 0.0088564516790356311) {
    min_dist = rt_pow_snf(dist, 0.33333333333333331);
  } else {
    min_dist = 7.7870370370370372 * dist + 0.13793103448275862;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * i - 16.0;
  localB->ColorSpaceConversion1_o2 = (Xf - i) * 500.0;
  localB->ColorSpaceConversion1_o3 = (i - min_dist) * 200.0;

  /* Embedded MATLAB: '<S122>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation/Threshold The Image/Choose Closest Color': '<S123>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S123>:1:5' */
  min_dist = 1000.0;

  /* '<S123>:1:6' */
  /* '<S123>:1:12' */
  rtb_index_j = 1;

  /* '<S123>:1:13' */
  for (i = 1.0; i <= rtu_Num_Colors; i++) {
    /* '<S123>:1:13' */
    /* '<S123>:1:14' */
    dist = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o2 - rtu_Ref_Colors
      [(int32_T)i + 49], 2.0) * 1.5 + rt_pow_snf
                 (localB->ColorSpaceConversion1_o1 - rtu_Ref_Colors[(int32_T)i -
                  1], 2.0)) + rt_pow_snf(localB->ColorSpaceConversion1_o3 -
      rtu_Ref_Colors[(int32_T)i + 99], 2.0) * 1.5);
    if (dist < min_dist) {
      /* '<S123>:1:15' */
      /* '<S123>:1:16' */
      min_dist = dist;

      /* '<S123>:1:17' */
      cc = floor(i + 0.5);
      if (cc < 128.0) {
        rtb_index_j = (int8_T)cc;
      } else {
        rtb_index_j = MAX_int8_T;
      }
    }
  }

  if (min_dist > 100.0) {
    /* '<S123>:1:21' */
    /* '<S123>:1:22' */
    cc = rtu_Num_Colors + 1.0;
    cc = (int32_T)(cc < 0.0) ? ceil(cc - 0.5) : floor(cc + 0.5);
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

  /* RelationalOperator: '<S122>/Relational Operator' */
  for (i_0 = 0; i_0 < 19200; i_0++) {
    localB->BW[i_0] = (rtu_LabMatrix[i_0] == (real_T)rtb_index_j);
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

  /* Start for S-Function (svipmorphop): '<S29>/Dilation' */
  idxNHood = 0;
  idxOffsets = 0;
  curNumNonZ = 0;
  for (n = 0; n < 2; n++) {
    for (m = 0; m < 2; m++) {
      if (brain_ConstP.pooled36[idxNHood]) {
        localDW->Dilation_DILATE_OFF_DW[idxOffsets] = n * 123 + m;
        curNumNonZ++;
        idxOffsets++;
      }

      idxNHood++;
    }
  }

  localDW->Dilation_NUMNONZ_DW = curNumNonZ;

  /* Start for S-Function (svipmorphop): '<S29>/Erosion' */
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
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  int32_T i;
  int32_T inIdx;
  int32_T centerM;
  int32_T centerN;
  int32_T n;
  int32_T startR;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T m;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  real_T rtb_TmpSignalConversionAtDraw_p[2];
  real_T rtb_Sum_cg;
  real_T rtb_Error_p;
  real_T rtb_TSamp_n;
  real_T rtb_TSamp_e;
  int32_T rtb_BuoyBlobAnalysis_o1_c[10];
  real_T rtb_BuoyBlobAnalysis_o2_c[20];
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
  int32_T line_idx_5;
  real_T tmp;
  int8_T rtb_DataTypeConversion_m_0;
  localDW->StateFlowFunctionsJumpHedgeCa_c = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsJumpHedgeCa_l;
  localDW->StateFlowFunctionsJumpHedgeCa_l = brain_M->Timing.clockTick0;

  /* S-Function (svipscalenconvert): '<S29>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipmorphop): '<S29>/Dilation' */
  for (i = 0; i < 20049; i++) {
    localDW->Dilation_ONE_PAD_IMG_DW[i] = FALSE;
  }

  for (inIdx = 0; inIdx < 19200; inIdx++) {
    if (localB->ImageDataTypeConversion[inIdx]) {
      centerM = inIdx / 120;
      centerM = (inIdx - centerM * 120) + centerM * 123;
      for (i = 0; i < localDW->Dilation_NUMNONZ_DW; i++) {
        localDW->Dilation_ONE_PAD_IMG_DW[centerM +
          localDW->Dilation_DILATE_OFF_DW[i]] = TRUE;
      }
    }
  }

  inIdx = 0;
  centerM = 0;
  for (n = 0; n < 160; n++) {
    for (m = 0; m < 120; m++) {
      localB->Dilation[centerM] = localDW->Dilation_ONE_PAD_IMG_DW[inIdx];
      centerM++;
      inIdx++;
    }

    inIdx += 3;
  }

  /* S-Function (svipmorphop): '<S29>/Erosion' */
  centerM = 0;
  centerN = 0;
  for (inIdx = 0; inIdx < 127; inIdx++) {
    localDW->Erosion_ONE_PAD_IMG_DW[centerM] = TRUE;
    centerM++;
  }

  for (i = 0; i < 160; i++) {
    localDW->Erosion_ONE_PAD_IMG_DW[centerM] = TRUE;
    centerM++;
    memcpy((void *)(&localDW->Erosion_ONE_PAD_IMG_DW[centerM]), (void *)
           (&localB->Dilation[centerN]), 120U * sizeof(boolean_T));
    centerM += 120;
    centerN += 120;
    for (inIdx = 121; inIdx < 127; inIdx++) {
      localDW->Erosion_ONE_PAD_IMG_DW[centerM] = TRUE;
      centerM++;
    }
  }

  for (i = 161; i < 167; i++) {
    for (inIdx = 0; inIdx < 127; inIdx++) {
      localDW->Erosion_ONE_PAD_IMG_DW[centerM] = TRUE;
      centerM++;
    }
  }

  for (i = 0; i < 21209; i++) {
    localDW->Erosion_TWO_PAD_IMG_DW[i] = TRUE;
  }

  centerN = 0;
  for (n = 0; n < 167; n++) {
    for (m = 0; m < 124; m++) {
      localDW->Erosion_TWO_PAD_IMG_DW[1 + centerN] = TRUE;
      for (i = 0; i < localDW->Erosion_NUMNONZ_DW[0]; i++) {
        if (!localDW->Erosion_ONE_PAD_IMG_DW[centerN +
            localDW->Erosion_ERODE_OFF_DW[i]]) {
          localDW->Erosion_TWO_PAD_IMG_DW[1 + centerN] = FALSE;
          i = localDW->Erosion_NUMNONZ_DW[0];
        }
      }

      centerN++;
    }

    centerN += 3;
  }

  inIdx = 1;
  centerM = 0;
  for (n = 0; n < 160; n++) {
    for (m = 1; m < 121; m++) {
      localB->Erosion[centerM] = TRUE;
      for (i = 0; i < localDW->Erosion_NUMNONZ_DW[1]; i++) {
        if (!localDW->Erosion_TWO_PAD_IMG_DW[localDW->Erosion_ERODE_OFF_DW[i +
            localDW->Erosion_NUMNONZ_DW[0]] + inIdx]) {
          localB->Erosion[centerM] = FALSE;
          i = localDW->Erosion_NUMNONZ_DW[1];
        }
      }

      inIdx++;
      centerM++;
    }

    inIdx += 7;
  }

  /* S-Function (svipblob): '<S29>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (centerM = 0; centerM < 123; centerM++) {
    localDW->BuoyBlobAnalysis_PAD_DW[centerM] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  centerN = 123;
  for (n = 0; n < 160; n++) {
    for (m = 0; m < 120; m++) {
      localDW->BuoyBlobAnalysis_PAD_DW[centerN] = (uint8_T)(localB->Erosion[i] ?
        255 : 0);
      i++;
      centerN++;
    }

    localDW->BuoyBlobAnalysis_PAD_DW[centerN] = 0U;
    centerN++;
    localDW->BuoyBlobAnalysis_PAD_DW[centerN] = 0U;
    centerN++;
  }

  for (centerM = 0; centerM < 121; centerM++) {
    localDW->BuoyBlobAnalysis_PAD_DW[centerM + centerN] = 0U;
  }

  centerN = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    inIdx = 1;
    startR = centerN * 122;
    for (m = 0; m < 120; m++) {
      numBlobs = (uint32_T)(startR + inIdx);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(centerN - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(inIdx - 1);
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
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
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
          n = 160;
          m = 120;
        }

        if (m < 120) {
          currentLabel++;
        }
      }

      inIdx++;
    }

    centerN++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  centerM = 0;
  centerN = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    rtb_BuoyBlobAnalysis_o1_c[i] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    n = 0;
    startR = 0;
    for (inIdx = 0; inIdx < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i]; inIdx++) {
      n += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[inIdx + centerN];
      startR += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[inIdx + centerM];
    }

    rtb_TmpSignalConversionAtDraw_p[0] = (real_T)startR / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_TmpSignalConversionAtDraw_p[1] = (real_T)n / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_BuoyBlobAnalysis_o2_c[i << 1] = rtb_TmpSignalConversionAtDraw_p[0];
    rtb_BuoyBlobAnalysis_o2_c[(i << 1) + 1] = rtb_TmpSignalConversionAtDraw_p[1];
    centerM += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    centerN += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
  }

  for (centerM = (int32_T)numBlobs; centerM < 10; centerM++) {
    rtb_BuoyBlobAnalysis_o1_c[centerM] = -1;
  }

  for (centerM = (int32_T)(numBlobs << 1); centerM < 20; centerM++) {
    rtb_BuoyBlobAnalysis_o2_c[centerM] = -1.0;
  }

  /* S-Function (svipscalenconvert): '<S29>/Image Data Type Conversion1' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion1[i] = localB->Erosion[i] ? 1.0 : 0.0;
  }

  /* Embedded MATLAB: '<S29>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Embedded MATLAB Function': '<S113>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_c[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_c[1] ==
       -1.0)) {
    /* '<S113>:1:5' */
    /* '<S113>:1:7' */
    rtb_Error_p = 80.0;

    /* '<S113>:1:8' */
    rtb_TSamp_e = 60.0;

    /* '<S113>:1:9' */
  } else {
    centerN = rtb_BuoyBlobAnalysis_o1_c[0];
    n = 1;
    startR = 1;
    for (centerM = 2; centerM < 11; centerM++) {
      startR++;
      if (rtb_BuoyBlobAnalysis_o1_c[startR - 1] > centerN) {
        centerN = rtb_BuoyBlobAnalysis_o1_c[startR - 1];
        n = centerM;
      }
    }

    /* '<S113>:1:11' */
    /* '<S113>:1:12' */
    rtb_Error_p = rtb_BuoyBlobAnalysis_o2_c[((n - 1) << 1) + 1];

    /* '<S113>:1:13' */
    rtb_TSamp_e = rtb_BuoyBlobAnalysis_o2_c[(n - 1) << 1];
  }

  /* SignalConversion: '<S29>/TmpSignal ConversionAtDraw MarkersInport2' */
  rtb_TmpSignalConversionAtDraw_p[0] = rtb_TSamp_e;
  rtb_TmpSignalConversionAtDraw_p[1] = rtb_Error_p;

  /* S-Function (svipdrawmarkers): '<S29>/Draw Markers' */
  /* Copy the image from input to output. */
  memcpy((void *)(&localB->DrawMarkers[0]), (void *)
         (&localB->ImageDataTypeConversion1[0]), 19200U * sizeof(real_T));

  /* Draw all X marks. */
  for (m = 0; m < 2; m += 2) {
    tmp = rtb_TmpSignalConversionAtDraw_p[m];
    if ((rtb_TmpSignalConversionAtDraw_p[m] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDraw_p[m] > -4.503599627370496E+15)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_p[m] + 0.5);
    }

    n = (int32_T)tmp;
    tmp = rtb_TmpSignalConversionAtDraw_p[m + 1];
    if ((rtb_TmpSignalConversionAtDraw_p[m + 1] < 4.503599627370496E+15) &&
        (rtb_TmpSignalConversionAtDraw_p[m + 1] > -4.503599627370496E+15)) {
      tmp = floor(rtb_TmpSignalConversionAtDraw_p[m + 1] + 0.5);
    }

    i = (int32_T)tmp;
    inIdx = n - 7;
    line_idx = i - 7;
    line_idx_0 = n + 7;
    line_idx_1 = i + 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_3 = inIdx;
    line_idx_2 = line_idx;
    line_idx_4 = line_idx_0;
    line_idx_5 = line_idx_1;
    while (!done) {
      numBlobs = 0U;
      walkerIdx = 0U;

      /* Determine viewport violations. */
      if (line_idx_3 < 0) {
        numBlobs = 4U;
      } else {
        if (line_idx_3 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_4 < 0) {
        walkerIdx = 4U;
      } else {
        if (line_idx_4 > 119) {
          walkerIdx = 8U;
        }
      }

      if (line_idx_2 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_2 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_5 < 0) {
        walkerIdx |= 1U;
      } else {
        if (line_idx_5 > 159) {
          walkerIdx |= 2U;
        }
      }

      if (!(numBlobs | walkerIdx)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & walkerIdx) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_3 = inIdx;
          line_idx_2 = line_idx;
        }

        centerM = line_idx_4 - line_idx_3;
        centerN = line_idx_5 - line_idx_2;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          startR = (0 - line_idx_3) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_2 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          startR = (119 - line_idx_3) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_2 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          startR = (0 - line_idx_2) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_3 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          startR = (159 - line_idx_2) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_3 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_4 = line_idx_0;
          line_idx_5 = line_idx_1;
        }

        centerM = line_idx_4 - line_idx_3;
        centerN = line_idx_5 - line_idx_2;
        if (walkerIdx & 4U) {
          /* Violated RMin. */
          startR = (0 - line_idx_4) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_5 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if (walkerIdx & 8U) {
          /* Violated RMax. */
          startR = (119 - line_idx_4) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_5 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if (walkerIdx & 1U) {
          /* Violated CMin. */
          startR = (0 - line_idx_5) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_4 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          startR = (159 - line_idx_5) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_4 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      centerN = line_idx_2 * 120 + line_idx_3;
      for (startR = line_idx_3; startR <= line_idx_4; startR++) {
        localB->DrawMarkers[centerN] = 0.5;
        centerN += 121;
      }
    }

    inIdx = n - 7;
    line_idx = i + 7;
    line_idx_0 = n + 7;
    line_idx_1 = i - 7;
    maxNumBlobsReached = FALSE;

    /* Find the visible portion of a line. */
    visited = FALSE;
    visited_0 = FALSE;
    done = FALSE;
    line_idx_3 = inIdx;
    line_idx_2 = line_idx;
    line_idx_4 = line_idx_0;
    line_idx_5 = line_idx_1;
    while (!done) {
      numBlobs = 0U;
      walkerIdx = 0U;

      /* Determine viewport violations. */
      if (line_idx_3 < 0) {
        numBlobs = 4U;
      } else {
        if (line_idx_3 > 119) {
          numBlobs = 8U;
        }
      }

      if (line_idx_4 < 0) {
        walkerIdx = 4U;
      } else {
        if (line_idx_4 > 119) {
          walkerIdx = 8U;
        }
      }

      if (line_idx_2 < 0) {
        numBlobs |= 1U;
      } else {
        if (line_idx_2 > 159) {
          numBlobs |= 2U;
        }
      }

      if (line_idx_5 < 0) {
        walkerIdx |= 1U;
      } else {
        if (line_idx_5 > 159) {
          walkerIdx |= 2U;
        }
      }

      if (!(numBlobs | walkerIdx)) {
        /* Line falls completely within bounds. */
        done = TRUE;
        maxNumBlobsReached = TRUE;
      } else if (numBlobs & walkerIdx) {
        /* Line falls completely out of bounds. */
        done = TRUE;
        maxNumBlobsReached = FALSE;
      } else if (numBlobs != 0U) {
        /* Clip 1st point; if it's in-bounds, clip 2nd point. */
        if (visited) {
          line_idx_3 = inIdx;
          line_idx_2 = line_idx;
        }

        centerM = line_idx_4 - line_idx_3;
        centerN = line_idx_5 - line_idx_2;
        if (numBlobs & 4U) {
          /* Violated RMin. */
          startR = (0 - line_idx_3) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_2 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_3 = 0;
          visited = TRUE;
        } else if (numBlobs & 8U) {
          /* Violated RMax. */
          startR = (119 - line_idx_3) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_2 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_2 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_3 = 119;
          visited = TRUE;
        } else if (numBlobs & 1U) {
          /* Violated CMin. */
          startR = (0 - line_idx_2) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_3 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_2 = 0;
          visited = TRUE;
        } else {
          /* Violated CMax. */
          startR = (159 - line_idx_2) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_3 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_3 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_2 = 159;
          visited = TRUE;
        }
      } else {
        /* Clip the 2nd point. */
        if (visited_0) {
          line_idx_4 = line_idx_0;
          line_idx_5 = line_idx_1;
        }

        centerM = line_idx_4 - line_idx_3;
        centerN = line_idx_5 - line_idx_2;
        if (walkerIdx & 4U) {
          /* Violated RMin. */
          startR = (0 - line_idx_4) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_5 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_4 = 0;
          visited_0 = TRUE;
        } else if (walkerIdx & 8U) {
          /* Violated RMax. */
          startR = (119 - line_idx_4) * centerN;
          if (((startR >= 0) && (centerM >= 0)) || ((startR < 0) && (centerM < 0)))
          {
            line_idx_5 += (div_s32_floor(startR << 1U, centerM) + 1) >> 1;
          } else {
            line_idx_5 += -((div_s32_floor((-startR) << 1U, centerM) + 1) >> 1);
          }

          line_idx_4 = 119;
          visited_0 = TRUE;
        } else if (walkerIdx & 1U) {
          /* Violated CMin. */
          startR = (0 - line_idx_5) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_4 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_5 = 0;
          visited_0 = TRUE;
        } else {
          /* Violated CMax. */
          startR = (159 - line_idx_5) * centerM;
          if (((startR >= 0) && (centerN >= 0)) || ((startR < 0) && (centerN < 0)))
          {
            line_idx_4 += (div_s32_floor(startR << 1U, centerN) + 1) >> 1;
          } else {
            line_idx_4 += -((div_s32_floor((-startR) << 1U, centerN) + 1) >> 1);
          }

          line_idx_5 = 159;
          visited_0 = TRUE;
        }
      }
    }

    if (maxNumBlobsReached) {
      centerN = line_idx_2 * 120 + line_idx_3;
      for (startR = line_idx_3; startR <= line_idx_4; startR++) {
        localB->DrawMarkers[centerN] = 0.5;
        centerN += -119;
      }
    }
  }

  /* Embedded MATLAB: '<S29>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S115>/Subtract' */
  rtb_Sum_cg = localB->sf_EmbeddedMATLABFunction1.XCenter - rtb_Error_p;

  /* SampleTimeMath: '<S118>/TSamp' incorporates:
   *  Gain: '<S117>/X-Buoy Derivative Gain'
   *
   * About '<S118>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_n = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum_cg / ((real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * 0.2);

  /* DataTypeConversion: '<S115>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S117>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S117>/X-Buoy Proportional Gain'
   *  Sum: '<S117>/Sum'
   *  Sum: '<S118>/Diff'
   *  UnitDelay: '<S118>/UD'
   *
   * Block description for '<S118>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S118>/UD':
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

  /* Sum: '<S115>/Add' */
  localB->Add = rtu_ForwardVelocity + (real_T)rtb_DataTypeConversion_m_0;

  /* Sum: '<S115>/Add1' incorporates:
   *  Constant: '<S115>/Constant'
   *  Product: '<S115>/Multiply'
   */
  localB->Add1 = (real_T)rtb_DataTypeConversion_m_0 * -1.0 + rtu_ForwardVelocity;

  /* Sum: '<S116>/Subtract' */
  rtb_Error_p = rtb_TSamp_e - localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* SampleTimeMath: '<S120>/TSamp' incorporates:
   *  Gain: '<S119>/Y-Buoy Derivative Gain'
   *
   * About '<S120>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_e = brain_P.Cam_Forward_YPosition_Kd * rtb_Error_p / ((real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * 0.2);

  /* DataTypeConversion: '<S116>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S119>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S119>/Y-Buoy Proportional Gain'
   *  Sum: '<S119>/Sum'
   *  Sum: '<S120>/Diff'
   *  UnitDelay: '<S120>/UD'
   *
   * Block description for '<S120>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S120>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Forward_YPosition_Kp * rtb_Error_p + (rtb_TSamp_e -
          localDW->UD_DSTATE_a)) + localDW->YBuoyDiscreteTimeIntegrator_DST;
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

  /* Update for UnitDelay: '<S118>/UD'
   * Block description for '<S118>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_n;

  /* Update for DiscreteIntegrator: '<S117>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S117>/X-Buoy Integral Gain'
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

  /* Update for UnitDelay: '<S120>/UD'
   * Block description for '<S120>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_a = rtb_TSamp_e;

  /* Update for DiscreteIntegrator: '<S119>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S119>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsJumpHedgeCa_c * (brain_P.Cam_Forward_YPosition_Ki
    * rtb_Error_p) + localDW->YBuoyDiscreteTimeIntegrator_DST;
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
  int32_T ix;
  int32_T i;
  int32_T padRows;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T BlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T j;
  int32_T rtb_BlobAnalysis_o1[10];
  int32_T rtb_BlobAnalysis_o2[40];

  /* S-Function (svipscalenconvert): '<S30>/Image Data Type Conversion' */
  for (i = 0; i < 19200; i++) {
    localB->ImageDataTypeConversion[i] = ((rtu_BW[i] == 0.0 ? 0 : 1) != 0);
  }

  /* S-Function (svipblob): '<S30>/Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (loop = 0; loop < 123; loop++) {
    localDW->BlobAnalysis_PAD_DW[loop] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (j = 0; j < 120; j++) {
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

  for (loop = 0; loop < 121; loop++) {
    localDW->BlobAnalysis_PAD_DW[loop + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (n = 0; n < 160; n++) {
    ix = 1;
    idx = nn * 122;
    for (j = 0; j < 120; j++) {
      numBlobs = (uint32_T)(idx + ix);
      if (localDW->BlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
        localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ix - 1);
        pixIdx++;
        BlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BlobAnalysis_STACK_DW[stackIdx];
          for (i = 0; i < 8; i++) {
            walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled27[i];
            if (localDW->BlobAnalysis_PAD_DW[walkerIdx] == 255) {
              localDW->BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
              localDW->BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)((int16_T)
                (walkerIdx / 122U) - 1);
              localDW->BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(walkerIdx %
                122U - 1U);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                BlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
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

      ix++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  padRows = 0;
  padCols = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    rtb_BlobAnalysis_o1[i] = (int32_T)BlobAnalysis_NUM_PIX_DW[i];
    ix = 160;
    idx = 120;
    nn = 0;
    n = 0;
    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW[i]; j++) {
      loop = j + padCols;
      if (localDW->BlobAnalysis_N_PIXLIST_DW[loop] < ix) {
        ix = localDW->BlobAnalysis_N_PIXLIST_DW[loop];
      }

      if (localDW->BlobAnalysis_N_PIXLIST_DW[loop] > nn) {
        nn = localDW->BlobAnalysis_N_PIXLIST_DW[loop];
      }

      loop = j + padRows;
      if (localDW->BlobAnalysis_M_PIXLIST_DW[loop] < idx) {
        idx = localDW->BlobAnalysis_M_PIXLIST_DW[loop];
      }

      if (localDW->BlobAnalysis_M_PIXLIST_DW[loop] > n) {
        n = localDW->BlobAnalysis_M_PIXLIST_DW[loop];
      }
    }

    loop = i << 2;
    rtb_BlobAnalysis_o2[loop] = idx;
    rtb_BlobAnalysis_o2[loop + 1] = ix;
    rtb_BlobAnalysis_o2[loop + 2] = (n + 1) - idx;
    rtb_BlobAnalysis_o2[loop + 3] = (nn + 1) - ix;
    padRows += (int32_T)BlobAnalysis_NUM_PIX_DW[i];
    padCols += (int32_T)BlobAnalysis_NUM_PIX_DW[i];
  }

  for (loop = (int32_T)numBlobs; loop < 10; loop++) {
    rtb_BlobAnalysis_o1[loop] = -1;
  }

  for (loop = (int32_T)(numBlobs << 2); loop < 40; loop++) {
    rtb_BlobAnalysis_o2[loop] = -1;
  }

  /* Embedded MATLAB: '<S30>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.GetAxisRatio/Embedded MATLAB Function': '<S121>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if (rtb_BlobAnalysis_o2[0] == -1) {
    /* '<S121>:1:5' */
    /* '<S121>:1:7' */
    localB->AxisRatio = 0.0;

    /* '<S121>:1:8' */
  } else {
    idx = rtb_BlobAnalysis_o1[0];
    nn = 1;
    ix = 1;
    for (loop = 2; loop < 11; loop++) {
      ix++;
      if (rtb_BlobAnalysis_o1[ix - 1] > idx) {
        idx = rtb_BlobAnalysis_o1[ix - 1];
        nn = loop;
      }
    }

    /* '<S121>:1:10' */
    /* '<S121>:1:11' */
    localB->AxisRatio = (real_T)rtb_BlobAnalysis_o2[((nn - 1) << 2) + 3] /
      (real_T)rtb_BlobAnalysis_o2[((nn - 1) << 2) + 2];
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateManagementRunningAutonomou(real_T rtu_State1,
  rtB_StateManagementRunningAuton *localB)
{
  /* Embedded MATLAB: '<S42>/Checking to see if state will be performed' incorporates:
   *  Constant: '<S42>/Mission Plan'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateManagement.Running.Autonomous.Perform/Checking to see if state will be performed': '<S147>:1' */
  /*  This function checks to see if the current state should be executed */
  if (brain_P.MissionPlan[(int32_T)rtu_State1 - 1] != 0.0) {
    /* '<S147>:1:4' */
    /* '<S147>:1:5' */
    localB->Done1 = 0.0;
  } else {
    /* '<S147>:1:7' */
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
  int32_T i;
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T nn;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T m;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T ns;
  int32_T j;
  real_T rtb_Sum_l;
  real_T rtb_Error_i;
  real_T rtb_TSamp_m;
  real_T rtb_TSamp_c4;
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
  for (loop = 0; loop < 123; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (loop = 0; loop < 160; loop++) {
    for (m = 0; m < 120; m++) {
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

  for (loop = 0; loop < 121; loop++) {
    localDW->BuoyBlobAnalysis_PAD_DW[loop + idx] = 0U;
  }

  nn = 1;
  stackIdx = 0U;
  pixIdx = 0U;
  for (loop = 0; loop < 160; loop++) {
    ns = 1;
    j = nn * 122;
    for (m = 0; m < 120; m++) {
      numBlobs = (uint32_T)(j + ns);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(nn - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ns - 1);
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
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] =
                BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] + 1U;
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
          loop = 160;
          m = 120;
        }

        if (m < 120) {
          currentLabel++;
        }
      }

      ns++;
    }

    nn++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  loop = 0;
  nn = 0;
  for (i = 0; i < (int32_T)numBlobs; i++) {
    rtb_BuoyBlobAnalysis_o1_o[i] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    ns = 0;
    idx = 0;
    for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i]; j++) {
      ns += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + nn];
      idx += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + loop];
    }

    rtb_BuoyBlobAnalysis_o2_ci[i << 1] = (real_T)idx / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    rtb_BuoyBlobAnalysis_o2_ci[(i << 1) + 1] = (real_T)ns / (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[i];
    loop += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
    nn += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
  }

  for (loop = (int32_T)numBlobs; loop < 10; loop++) {
    rtb_BuoyBlobAnalysis_o1_o[loop] = -1;
  }

  for (loop = (int32_T)(numBlobs << 1); loop < 20; loop++) {
    rtb_BuoyBlobAnalysis_o2_ci[loop] = -1.0;
  }

  /* Embedded MATLAB: '<S22>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CamDown_CenterOver_Yaw/Embedded MATLAB Function': '<S83>:1' */
  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  if ((rtb_BuoyBlobAnalysis_o2_ci[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_ci[1] ==
       -1.0)) {
    /* '<S83>:1:5' */
    /* '<S83>:1:7' */
    rtb_Error_i = 80.0;

    /* '<S83>:1:8' */
    rtb_TSamp_c4 = 60.0;
  } else {
    nn = rtb_BuoyBlobAnalysis_o1_o[0];
    ns = 1;
    idx = 1;
    for (loop = 2; loop < 11; loop++) {
      idx++;
      if (rtb_BuoyBlobAnalysis_o1_o[idx - 1] > nn) {
        nn = rtb_BuoyBlobAnalysis_o1_o[idx - 1];
        ns = loop;
      }
    }

    /* '<S83>:1:12' */
    rtb_Error_i = rtb_BuoyBlobAnalysis_o2_ci[((ns - 1) << 1) + 1];

    /* '<S83>:1:13' */
    rtb_TSamp_c4 = rtb_BuoyBlobAnalysis_o2_ci[(ns - 1) << 1];
  }

  /* Embedded MATLAB: '<S22>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S22>/Subtract' */
  localB->Subtract = rtb_Error_i - localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* Sum: '<S22>/Subtract1' */
  localB->Subtract1 = rtb_TSamp_c4 - localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* Sum: '<S85>/Subtract' */
  rtb_Sum_l = rtb_Error_i - localB->sf_EmbeddedMATLABFunction1.XCenter;

  /* SampleTimeMath: '<S88>/TSamp' incorporates:
   *  Gain: '<S87>/X-Buoy Derivative Gain'
   *
   * About '<S88>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_m = brain_P.Cam_Down_Yaw_XPos_Kd * rtb_Sum_l / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S85>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S87>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S87>/X-Buoy Proportional Gain'
   *  Sum: '<S87>/Sum'
   *  Sum: '<S88>/Diff'
   *  UnitDelay: '<S88>/UD'
   *
   * Block description for '<S88>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S88>/UD':
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

  /* DataTypeConversion: '<S85>/Data Type Conversion1' incorporates:
   *  Gain: '<S85>/Gain'
   */
  tmp_0 = (int16_T)(-128 * localB->DataTypeConversion >> 7);
  if (tmp_0 > 127) {
    tmp_0 = 127;
  }

  localB->DataTypeConversion1 = (int8_T)tmp_0;

  /* Sum: '<S86>/Subtract' */
  rtb_Error_i = localB->sf_EmbeddedMATLABFunction1.YCenter - rtb_TSamp_c4;

  /* SampleTimeMath: '<S90>/TSamp' incorporates:
   *  Gain: '<S89>/Y-Blob Derivative Gain'
   *
   * About '<S90>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_c4 = brain_P.Cam_Down_YPos_Kd * rtb_Error_i / ((real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * 0.2);

  /* DataTypeConversion: '<S86>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S89>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S89>/Y-Blob Proportional Gain'
   *  Sum: '<S89>/Sum'
   *  Sum: '<S90>/Diff'
   *  UnitDelay: '<S90>/UD'
   *
   * Block description for '<S90>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S90>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Cam_Down_YPos_Kp * rtb_Error_i + (rtb_TSamp_c4 -
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

  /* Update for UnitDelay: '<S88>/UD'
   * Block description for '<S88>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_m;

  /* Update for DiscreteIntegrator: '<S87>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S87>/X-Buoy Integral Gain'
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

  /* Update for UnitDelay: '<S90>/UD'
   * Block description for '<S90>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_o = rtb_TSamp_c4;

  /* Update for DiscreteIntegrator: '<S89>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S89>/Y-Blob Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsFollowOnePa_g * (brain_P.Cam_Down_YPos_Ki *
    rtb_Error_i) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsGoStraig_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsGoStraig *localDW)
{
  localDW->StateFlowFunctionsGoStraight_PR = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void br_StateFlowFunctionsGoStraight(real_T rtu_YawRate, real_T
  rtu_ForwardVelocity1, real_T rtu_Y_Accel, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsGoStraigh *localB, rtDW_StateFlowFunctionsGoStraig
  *localDW)
{
  real_T rtb_Add4_b;
  real_T rtb_TSamp_h;
  real_T rtb_Gain_kd;
  localDW->StateFlowFunctionsGoStraight_EL = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsGoStraight_PR;
  localDW->StateFlowFunctionsGoStraight_PR = brain_M->Timing.clockTick0;

  /* SampleTimeMath: '<S111>/TSamp' incorporates:
   *  Gain: '<S109>/YawRate Derivative Gain'
   *
   * About '<S111>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_h = brain_P.IMU_YawRate_Kd * rtu_YawRate / ((real_T)
    localDW->StateFlowFunctionsGoStraight_EL * 0.2);

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S109>/Heading Discrete-Time Integrator'
   *  Gain: '<S109>/YawRate Proportional Gain'
   *  Sum: '<S111>/Diff'
   *  UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add4_b = (brain_P.IMU_YawRate_Kp * rtu_YawRate + (rtb_TSamp_h -
    localDW->UD_DSTATE)) + localDW->HeadingDiscreteTimeIntegrator_D;

  /* Gain: '<S27>/Gain' */
  rtb_Gain_kd = -rtb_Add4_b;

  /* Sum: '<S27>/Add4' */
  rtb_Add4_b += rtu_ForwardVelocity1;

  /* DataTypeConversion: '<S27>/DoubleToint1' incorporates:
   *  Sum: '<S27>/Add3'
   */
  rtb_Gain_kd += rtu_ForwardVelocity1;
  rtb_Gain_kd = floor(rtb_Gain_kd);
  if (rtb_Gain_kd < 128.0) {
    if (rtb_Gain_kd >= -128.0) {
      localB->DoubleToint1 = (int8_T)rtb_Gain_kd;
    } else {
      localB->DoubleToint1 = MIN_int8_T;
    }
  } else {
    localB->DoubleToint1 = MAX_int8_T;
  }

  /* DataTypeConversion: '<S27>/DoubleToint8' */
  rtb_Gain_kd = floor(rtb_Add4_b);
  if (rtb_Gain_kd < 128.0) {
    if (rtb_Gain_kd >= -128.0) {
      localB->DoubleToint8 = (int8_T)rtb_Gain_kd;
    } else {
      localB->DoubleToint8 = MIN_int8_T;
    }
  } else {
    localB->DoubleToint8 = MAX_int8_T;
  }

  /* SampleTimeMath: '<S110>/TSamp' incorporates:
   *  Gain: '<S108>/Y-Accelerometer Derivative Gain'
   *
   * About '<S110>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Add4_b = brain_P.IMU_YVel_Kd * rtu_Y_Accel / ((real_T)
    localDW->StateFlowFunctionsGoStraight_EL * 0.2);

  /* DataTypeConversion: '<S27>/DoubleToint2' incorporates:
   *  DiscreteIntegrator: '<S108>/Depth Discrete-Time Integrator'
   *  Gain: '<S108>/Y-Accelerometer Proportional Gain'
   *  Sum: '<S108>/Sum'
   *  Sum: '<S110>/Diff'
   *  UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Gain_kd = (brain_P.IMU_YVel_Kp * rtu_Y_Accel + (rtb_Add4_b -
    localDW->UD_DSTATE_l)) + localDW->DepthDiscreteTimeIntegrator_DST;
  rtb_Gain_kd = floor(rtb_Gain_kd);
  if (rtb_Gain_kd < 128.0) {
    if (rtb_Gain_kd >= -128.0) {
      localB->DoubleToint2 = (int8_T)rtb_Gain_kd;
    } else {
      localB->DoubleToint2 = MIN_int8_T;
    }
  } else {
    localB->DoubleToint2 = MAX_int8_T;
  }

  /* Update for UnitDelay: '<S111>/UD'
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_h;

  /* Update for DiscreteIntegrator: '<S109>/Heading Discrete-Time Integrator' incorporates:
   *  Gain: '<S109>/YawRate Integral Gain'
   */
  localDW->HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
    localDW->StateFlowFunctionsGoStraight_EL * (brain_P.IMU_YawRate_Ki *
    rtu_YawRate) + localDW->HeadingDiscreteTimeIntegrator_D;
  if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
    localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
  } else {
    if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
    }
  }

  /* Update for UnitDelay: '<S110>/UD'
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_l = rtb_Add4_b;

  /* Update for DiscreteIntegrator: '<S108>/Depth Discrete-Time Integrator' incorporates:
   *  Gain: '<S108>/Y-Accelerometer Integral Gain'
   */
  localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsGoStraight_EL * (brain_P.IMU_YVel_Ki *
    rtu_Y_Accel) + localDW->DepthDiscreteTimeIntegrator_DST;
  if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
    localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
  } else {
    if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_CalcTare(void)
{
  /* Transition: '<S7>:2003' */
  /* Entry 'Stop': '<S7>:2007' */
  brain_DWork.is_CalcTare = brain_IN_Stop;
  brain_B.Left = 0;
  brain_B.Right = 0;
  brain_B.Strafe = 0;
  brain_B.Vertical = 0;
  brain_DWork.stepcount = 0.0;
  brain_DWork.TarYaw = brain_U.CurrentHeading;
  brain_DWork.TarYawRate = brain_U.YawRate;
  brain_DWork.TarPitch = brain_U.PitchEuler;
  brain_DWork.TarPitchRate = brain_U.PitchRate;
  brain_DWork.TarRoll = brain_U.RollEuler;
  brain_DWork.TarRollRate = brain_U.RollRate;
  brain_DWork.OldYaw = 0.0;
  brain_DWork.OldYawRate = 0.0;
  brain_DWork.OldPitch = 0.0;
  brain_DWork.OldRoll = 0.0;
  brain_DWork.OldXVel = 0.0;
  brain_DWork.OldYVel = 0.0;
  brain_DWork.OldZVel = 0.0;
  brain_DWork.OldX = 0.0;
  brain_DWork.OldY = 0.0;
  brain_DWork.OldZ = 0.0;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_StateEstimator(void)
{
  int32_T T;
  real_T Accel[3];
  real_T YawRate_Model;
  real_T DeltaT;
  real_T PitchRate;
  real_T RollRate;
  real_T tmp[9];
  real_T unnamed_idx;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;

  /* During 'StateEstimator': '<S7>:1998' */
  switch (brain_DWork.is_StateEstimator) {
   case brain_IN_CalcIMUInfo:
    /* During 'CalcIMUInfo': '<S7>:2009' */
    if (brain_U.Tare > 0.5) {
      /* Transition: '<S7>:2000' */
      /* Exit 'CalcIMUInfo': '<S7>:2009' */
      /* Entry 'CalcTare': '<S7>:2002' */
      brain_DWork.is_StateEstimator = brain_IN_CalcTare;
      brain_DWork.TareDone = 0.0;
      brain_enter_internal_CalcTare();
    } else {
      /* Embedded MATLAB Function 'CheckDeltaT': '<S7>:2026' */
      /*  Make sure deltaT isn't zero breaking everything */
      if (brain_U.DeltaT < 0.1) {
        /* '<S7>:2026:4' */
        /* '<S7>:2026:5' */
        DeltaT = 0.01;
      } else {
        /* '<S7>:2026:7' */
        DeltaT = brain_U.DeltaT / 1000.0;
      }

      PitchRate = brain_U.PitchRate - brain_DWork.TarPitchRate;
      RollRate = brain_U.RollRate - brain_DWork.TarRollRate;

      /* Embedded MATLAB Function 'AUV_Yaw_Model': '<S7>:2045' */
      /*  This uses a math model of the auv to calculate the yaw rate and yaw of */
      /*  the AUV */
      /* '<S7>:2045:7' */
      T = brain_B.Left - brain_B.Right;

      /* '<S7>:2045:9' */
      /* '<S7>:2045:10' */
      /* '<S7>:2045:12' */
      YawRate_Model = (((0.0012 * rt_pow_snf((real_T)T, 2.0) + 0.6913 * (real_T)
                         T) + 0.8157) - brain_DWork.OldYawRate) / ((0.0006 *
        rt_pow_snf((real_T)T, 2.0) + 0.0865 * (real_T)T) + 5.6421) * 3.0 *
        DeltaT + brain_DWork.OldYawRate;
      if ((fabs(brain_DWork.OldYawRate) < 1.2) && (fabs((real_T)T) < 5.0)) {
        /* '<S7>:2045:14' */
        /* '<S7>:2045:15' */
        YawRate_Model = 0.0;
      }

      /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
      /*  This function combines information from two sources */
      /* '<S7>:2039:4' */
      /* '<S7>:2039:5' */
      /* '<S7>:2039:7' */
      brain_B.YawRate_Out = (brain_U.YawRate - brain_DWork.TarYawRate) *
        0.59322033898305082 + 0.40677966101694918 * YawRate_Model;
      brain_DWork.OldYawRate = brain_B.YawRate_Out;
      brain_B.PitchRate_Out = PitchRate;
      brain_B.RollRate_Out = RollRate;

      /* Embedded MATLAB Function 'Integrate3': '<S7>:2015' */
      /*  This function calculates the euler angles using an IMU approach */
      /* '<S7>:2015:4' */
      /* '<S7>:2015:5' */
      /* '<S7>:2015:6' */
      brain_B.Yaw = brain_B.YawRate_Out * DeltaT + brain_DWork.OldYaw;
      brain_DWork.OldYaw = brain_B.Yaw;

      /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
      /*  This function combines information from two sources */
      /* '<S7>:2039:4' */
      /* '<S7>:2039:5' */
      /* '<S7>:2039:7' */
      brain_B.Pitch = (PitchRate * DeltaT + brain_DWork.OldPitch) *
        0.5714285714285714 + (brain_U.PitchEuler - brain_DWork.TarPitch) *
        0.4285714285714286;
      brain_DWork.OldPitch = brain_B.Pitch;

      /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
      /*  This function combines information from two sources */
      /* '<S7>:2039:4' */
      /* '<S7>:2039:5' */
      /* '<S7>:2039:7' */
      brain_B.Roll = (RollRate * DeltaT + brain_DWork.OldRoll) *
        0.5714285714285714 + (brain_U.RollEuler - brain_DWork.TarRoll) *
        0.4285714285714286;
      brain_DWork.OldRoll = brain_B.Roll;

      /* Embedded MATLAB Function 'GoToEarthCFrame': '<S7>:2029' */
      /*  This function uses a rotation matrix to put the accelerations on the */
      /*  earth based axis using the assumption that the yaw is zero. This gives */
      /*  the roll and pitch an effect on the accelerations so the strafe thruster */
      /*  maintains its position in the xy-plane */
      /* '<S7>:2029:9' */
      PitchRate = brain_B.Yaw * 3.1415926535897931 / 180.0;

      /* '<S7>:2029:10' */
      RollRate = brain_B.Pitch * 3.1415926535897931 / 180.0;

      /* '<S7>:2029:11' */
      YawRate_Model = brain_B.Roll * 3.1415926535897931 / 180.0;

      /* '<S7>:2029:12' */
      /*  Rotation matrix */
      /* '<S7>:2029:15' */
      /* '<S7>:2029:19' */
      unnamed_idx = (brain_U.RollAccelB - brain_DWork.TRA) / 0.3048;
      unnamed_idx_0 = (brain_U.PitchAccelB - brain_DWork.TPA) / 0.3048;
      unnamed_idx_1 = (brain_U.YawAccelB - brain_DWork.TYA) / 0.3048;
      tmp[0] = cos(PitchRate) * cos(RollRate);
      tmp[1] = sin(PitchRate) * cos(RollRate);
      tmp[2] = -sin(RollRate);
      tmp[3] = cos(PitchRate) * sin(RollRate) * sin(YawRate_Model) - sin
        (PitchRate) * cos(YawRate_Model);
      tmp[4] = sin(PitchRate) * sin(RollRate) * sin(YawRate_Model) + cos
        (PitchRate) * cos(YawRate_Model);
      tmp[5] = cos(RollRate) * sin(YawRate_Model);
      tmp[6] = cos(PitchRate) * sin(RollRate) * cos(YawRate_Model) + sin
        (PitchRate) * sin(YawRate_Model);
      tmp[7] = sin(PitchRate) * sin(YawRate_Model) * cos(RollRate) - cos
        (PitchRate) * sin(YawRate_Model);
      tmp[8] = cos(RollRate) * cos(YawRate_Model);
      for (T = 0; T < 3; T++) {
        Accel[T] = tmp[T + 6] * unnamed_idx_1 + (tmp[T + 3] * unnamed_idx_0 +
          tmp[T] * unnamed_idx);
      }

      /* '<S7>:2029:21' */
      /* '<S7>:2029:22' */
      /* '<S7>:2029:23' */
      brain_B.Roll_Accel = Accel[0];
      brain_B.Pitch_Accel = Accel[1];
      brain_B.Yaw_Accel = Accel[2];

      /* Embedded MATLAB Function 'Integrate3': '<S7>:2015' */
      /*  This function calculates the euler angles using an IMU approach */
      /* '<S7>:2015:4' */
      /* '<S7>:2015:5' */
      /* '<S7>:2015:6' */
      brain_B.XVel = brain_B.Roll_Accel * DeltaT + brain_DWork.OldXVel;
      brain_B.YVel = brain_B.Pitch_Accel * DeltaT + brain_DWork.OldYVel;
      brain_B.ZVel = brain_B.Yaw_Accel * DeltaT + brain_DWork.OldZVel;
      brain_DWork.OldXVel = brain_B.XVel;
      brain_DWork.OldYVel = brain_B.YVel;
      brain_DWork.OldZVel = brain_B.ZVel;

      /* Embedded MATLAB Function 'Integrate3': '<S7>:2015' */
      /*  This function calculates the euler angles using an IMU approach */
      /* '<S7>:2015:4' */
      /* '<S7>:2015:5' */
      /* '<S7>:2015:6' */
      brain_B.X = brain_B.XVel * DeltaT + brain_DWork.OldX;
      brain_B.Y = brain_B.YVel * DeltaT + brain_DWork.OldY;
      brain_B.Z = brain_B.ZVel * DeltaT + brain_DWork.OldZ;
    }
    break;

   case brain_IN_CalcTare:
    /* During 'CalcTare': '<S7>:2002' */
    if (brain_DWork.TareDone > 0.5) {
      /* Transition: '<S7>:2001' */
      /* Exit 'Next': '<S7>:2008' */
      brain_DWork.is_CalcTare = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'PerformTare': '<S7>:2006' */
      /* Exit 'Stop': '<S7>:2007' */
      /* Exit 'CalcTare': '<S7>:2002' */
      /* Entry 'CalcIMUInfo': '<S7>:2009' */
      brain_DWork.is_StateEstimator = brain_IN_CalcIMUInfo;
    } else {
      switch (brain_DWork.is_CalcTare) {
       case brain_IN_Next:
        break;

       case brain_IN_PerformTare:
        /* During 'PerformTare': '<S7>:2006' */
        /* Transition: '<S7>:2005' */
        /* Exit 'PerformTare': '<S7>:2006' */
        /* Entry 'Next': '<S7>:2008' */
        brain_DWork.is_CalcTare = brain_IN_Next;
        brain_DWork.TareDone = 1.0;
        break;

       case brain_IN_Stop:
        /* During 'Stop': '<S7>:2007' */
        if (brain_DWork.stepcount >= 10.0) {
          /* Transition: '<S7>:2004' */
          /* Exit 'Stop': '<S7>:2007' */
          /* Entry 'PerformTare': '<S7>:2006' */
          brain_DWork.is_CalcTare = brain_IN_PerformTare;

          /* Embedded MATLAB Function 'CheckDeltaT': '<S7>:2026' */
          /*  Make sure deltaT isn't zero breaking everything */
          if (brain_U.DeltaT < 0.1) {
            /* '<S7>:2026:4' */
            /* '<S7>:2026:5' */
            DeltaT = 0.01;
          } else {
            /* '<S7>:2026:7' */
            DeltaT = brain_U.DeltaT / 1000.0;
          }

          /* Embedded MATLAB Function 'AUV_Yaw_Model': '<S7>:2045' */
          /*  This uses a math model of the auv to calculate the yaw rate and yaw of */
          /*  the AUV */
          /* '<S7>:2045:7' */
          T = brain_B.Left - brain_B.Right;

          /* '<S7>:2045:9' */
          /* '<S7>:2045:10' */
          /* '<S7>:2045:12' */
          YawRate_Model = (((0.0012 * rt_pow_snf((real_T)T, 2.0) + 0.6913 *
                             (real_T)T) + 0.8157) - brain_DWork.OldYawRate) /
            ((0.0006 * rt_pow_snf((real_T)T, 2.0) + 0.0865 * (real_T)T) + 5.6421)
            * 3.0 * DeltaT + brain_DWork.OldYawRate;
          if ((fabs(brain_DWork.OldYawRate) < 1.2) && (fabs((real_T)T) < 5.0)) {
            /* '<S7>:2045:14' */
            /* '<S7>:2045:15' */
            YawRate_Model = 0.0;
          }

          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          brain_B.YawRate_Out = (brain_U.YawRate - brain_DWork.TarYawRate) *
            0.59322033898305082 + 0.40677966101694918 * YawRate_Model;
          brain_DWork.OldYawRate = brain_B.YawRate_Out;

          /* Embedded MATLAB Function 'Integrate3': '<S7>:2015' */
          /*  This function calculates the euler angles using an IMU approach */
          /* '<S7>:2015:4' */
          /* '<S7>:2015:5' */
          /* '<S7>:2015:6' */
          brain_B.Yaw = brain_B.YawRate_Out * DeltaT + brain_DWork.OldYaw;
          brain_DWork.OldYaw = brain_B.Yaw;

          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          brain_B.Pitch = ((brain_U.PitchRate - brain_DWork.TarPitchRate) *
                           DeltaT + brain_DWork.OldPitch) * 0.5714285714285714 +
            (brain_U.PitchEuler - brain_DWork.TarPitch) * 0.4285714285714286;
          brain_DWork.OldPitch = brain_B.Pitch;

          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          /* Embedded MATLAB Function 'Integrate3': '<S7>:2015' */
          /*  This function calculates the euler angles using an IMU approach */
          /* '<S7>:2015:4' */
          /* '<S7>:2015:5' */
          /* '<S7>:2015:6' */
          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          brain_B.Yaw = (brain_U.YawRate * DeltaT + brain_DWork.OldYaw) *
            0.5714285714285714 + 0.4285714285714286 * brain_U.CurrentHeading;
          brain_DWork.OldYaw = brain_B.Yaw;

          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          brain_B.Pitch = (brain_U.PitchRate * DeltaT + brain_DWork.OldPitch) *
            0.5714285714285714 + 0.4285714285714286 * brain_U.PitchEuler;
          brain_DWork.OldPitch = brain_B.Pitch;

          /* Embedded MATLAB Function 'combinevalues': '<S7>:2039' */
          /*  This function combines information from two sources */
          /* '<S7>:2039:4' */
          /* '<S7>:2039:5' */
          /* '<S7>:2039:7' */
          brain_B.Roll = (brain_U.RollRate * DeltaT + brain_DWork.OldRoll) *
            0.5714285714285714 + 0.4285714285714286 * brain_U.RollEuler;
          brain_DWork.OldRoll = brain_B.Roll;
          brain_DWork.TRA = brain_U.RollAccelB;
          brain_DWork.TPA = brain_U.PitchAccelB;
          brain_DWork.TYA = brain_U.YawAccelB;
        } else {
          brain_DWork.stepcount = brain_DWork.stepcount + 1.0;
        }
        break;

       default:
        brain_enter_internal_CalcTare();
        break;
      }
    }
    break;

   default:
    /* Transition: '<S7>:1999' */
    /* Entry 'CalcTare': '<S7>:2002' */
    brain_DWork.is_StateEstimator = brain_IN_CalcTare;
    brain_DWork.TareDone = 0.0;
    brain_enter_internal_CalcTare();
    break;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:949' */
        /* Exit 'Breach': '<S7>:1744' */
        /* Entry 'Finish': '<S7>:1064' */
        brain_DWork.is_Autonomous = brain_IN_Finish;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1743' */
        /* Exit 'DropMechanism': '<S7>:1722' */
        /* Entry 'FollowOnePath4': '<S7>:1732' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath4;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1702' */
        /* Exit 'FollowOnePath2': '<S7>:1142' */
        /* Entry 'Hedge1': '<S7>:1701' */
        brain_DWork.is_Autonomous = brain_IN_Hedge1;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1723' */
        /* Exit 'FollowOnePath3': '<S7>:1718' */
        /* Entry 'DropMechanism': '<S7>:1722' */
        brain_DWork.is_Autonomous = brain_IN_DropMechanism;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1738' */
        /* Exit 'FollowOnePath4': '<S7>:1732' */
        /* Entry 'Hedge2': '<S7>:1735' */
        brain_DWork.is_Autonomous = brain_IN_Hedge2;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1719' */
        /* Exit 'Hedge1': '<S7>:1701' */
        /* Entry 'FollowOnePath3': '<S7>:1718' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath3;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1742' */
        /* Exit 'Hedge2': '<S7>:1735' */
        /* Entry 'LocatePinger': '<S7>:1739' */
        brain_DWork.is_Autonomous = brain_IN_LocatePinger;
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
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:1747' */
        /* Exit 'LocatePinger': '<S7>:1739' */
        /* Entry 'Breach': '<S7>:1744' */
        brain_DWork.is_Autonomous = brain_IN_Breach;
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
        brain_DWork.Done = 0.0;
      } else {
        brain_DWork.OperationalState = 1;
      }
      break;

     case brain_IN_ValidationGate_m:
      /* During 'ValidationGate': '<S7>:1121' */
      if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S7>:955' */
        /* Exit 'ValidationGate': '<S7>:1121' */
        /* Entry 'ChooseState': '<S7>:1134' */
        brain_DWork.is_Autonomous = brain_IN_ChooseState;
        brain_DWork.Done = 0.0;
      } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S7>:947' */
        /* Exit 'ValidationGate': '<S7>:1121' */
        /* Entry 'FollowOnePath1': '<S7>:1065' */
        brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
        brain_B.State = 3;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      } else {
        brain_DWork.OperationalState = 2;
      }
      break;

     default:
      /* Transition: '<S7>:946' */
      /* Entry 'Start': '<S7>:1019' */
      brain_DWork.is_Autonomous = brain_IN_Start_m;
      brain_B.State = 1;

      /* Simulink Function 'Perform': '<S7>:1834' */
      brain_B.State1 = (real_T)brain_B.State;
      StateManagementRunningAutonomou(brain_B.State1,
        &brain_B.StateManagementRunningAutonom_j);
      brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_Buoys(void)
{
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
  brain_B.SubState = 1.0;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countareas(real_T Size, real_T count1)
{
  /* Embedded MATLAB Function 'countareas': '<S7>:1366' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  area is recognized by the recognition software */
  if (Size > 16000.0) {
    /* '<S7>:1366:6' */
    /* '<S7>:1366:7' */
    return count1 + 1.0;
  } else {
    /* '<S7>:1366:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_Turn45Degrees(real_T CHeading, real_T TurnD)
{
  real_T DHeading;

  /* Embedded MATLAB Function 'Turn45Degrees': '<S7>:1333' */
  /*  This function changes the current heading by 45 degrees in the correct */
  /*  direction to see the next buoy */
  /* '<S7>:1333:5' */
  DHeading = TurnD * 45.0 + CHeading;
  if (DHeading > 360.0) {
    /* '<S7>:1333:7' */
    /* '<S7>:1333:8' */
    DHeading -= 360.0;
  } else {
    if (DHeading < 0.0) {
      /* '<S7>:1333:9' */
      /* '<S7>:1333:10' */
      DHeading += 360.0;
    }
  }

  return DHeading;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_FindSecondBuoy(void)
{
  real_T cc;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  uint8_T i;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int8_T rtb_index;
  int32_T padRows;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  int32_T loop;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW_c[10];
  uint32_T numBlobs;
  int32_T pixListMinc;
  int32_T minr;
  int32_T maxc;
  real_T ys;
  real_T xys;
  uint32_T k;
  real_T uxx;
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

  /* During 'FindSecondBuoy': '<S7>:1317' */
  if (brain_DWork.Image == 1.0) {
    /* Transition: '<S7>:1315' */
    /* Exit 'FindSecondBuoy': '<S7>:1317' */
    /* Entry 'ApproachSecondBuoy': '<S7>:1316' */
    brain_DWork.is_ApproachBuoys = brain_IN_ApproachSecondBuoy;
    brain_B.SubState = 4.0;
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

    /* Sum: '<S38>/Add' */
    rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

    /* SampleTimeMath: '<S137>/TSamp' incorporates:
     *  Gain: '<S136>/Depth Derivative Gain'
     *
     * About '<S137>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

    /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
     *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
     *  Gain: '<S136>/Depth Proportional Gain'
     *  Sum: '<S136>/Sum'
     *  Sum: '<S137>/Diff'
     *  UnitDelay: '<S137>/UD'
     *
     * Block description for '<S137>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S137>/UD':
     *
     *  Store in Global RAM
     */
    uxx = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp - brain_DWork.UD_DSTATE)) +
      brain_DWork.DepthDiscreteTimeIntegrator_DST;
    uxx = floor(uxx);
    if (uxx < 128.0) {
      if (uxx >= -128.0) {
        brain_B.DoubleToInt8 = (int8_T)uxx;
      } else {
        brain_B.DoubleToInt8 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToInt8 = MAX_int8_T;
    }

    /* Update for UnitDelay: '<S137>/UD'
     * Block description for '<S137>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE = rtb_TSamp;

    /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S136>/Depth Integral Gain'
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
    memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
           (&brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0]), 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
    memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
           (&brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0]), 150U *
           sizeof(real_T));

    /* Simulink Function 'SecondBuoy': '<S7>:1318' */
    memcpy((void *)(&brain_B.LabMatrix_b[0]), (void *)(&brain_DWork.LabelMatrix
            [0]), 19200U * sizeof(real_T));
    memcpy((void *)(&brain_B.Ref_Colors_d[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    brain_B.Num_Colors_p = brain_DWork.num_colors;
    brain_B.B_Hue_c = brain_DWork.BuoyHue;
    brain_B.B_Sat_g = brain_DWork.BuoySaturation;
    brain_B.B_Value_p = brain_DWork.BuoyValue;

    /* S-Function (svipcolorconv): '<S60>/Color Space  Conversion' */
    /* temporary variables for in-place operation */
    uxx = 0.0;
    cc = 0.0;
    xys = 0.0;
    rtb_Add = 6.0 * brain_B.B_Hue_c;
    uyy = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-15);
    rtb_Add -= uyy;
    rtb_TSamp = 1.0 - brain_B.B_Sat_g;
    ys = 1.0 - brain_B.B_Sat_g * rtb_Add;
    rtb_Add = brain_B.B_Sat_g * rtb_Add + rtb_TSamp;
    if (uyy == 0.0) {
      uxx = 1.0;
      cc = rtb_Add;
      xys = rtb_TSamp;
    } else if (uyy == 1.0) {
      uxx = ys;
      cc = 1.0;
      xys = rtb_TSamp;
    } else if (uyy == 2.0) {
      uxx = rtb_TSamp;
      cc = 1.0;
      xys = rtb_Add;
    } else if (uyy == 3.0) {
      uxx = rtb_TSamp;
      cc = ys;
      xys = 1.0;
    } else if (uyy == 4.0) {
      uxx = rtb_Add;
      cc = rtb_TSamp;
      xys = 1.0;
    } else {
      if (uyy == 5.0) {
        uxx = 1.0;
        cc = rtb_TSamp;
        xys = ys;
      }
    }

    if (uxx > cc) {
      rtb_Add = uxx;
    } else {
      rtb_Add = cc;
    }

    if (!(rtb_Add > xys)) {
      rtb_Add = xys;
    }

    rtb_Add = brain_B.B_Value_p / rtb_Add;

    /* assign the results */
    brain_B.ColorSpaceConversion_o1 = rtb_Add * uxx;
    brain_B.ColorSpaceConversion_o2 = rtb_Add * cc;
    brain_B.ColorSpaceConversion_o3 = rtb_Add * xys;

    /* S-Function (svipcolorconv): '<S60>/Color Space  Conversion1' */
    /* temporary variables for in-place operation */
    /* Convert to XYZ */
    /* temporary variables for in-place operation */
    /* First, linearize (de-gamma) the RGB values; the operation is */
    /* equivalent to running the gamma correction block with break */
    /* point of 0.00304 and gamma of 2.4; it's built into this */
    /* conversion for convenience */
    if (brain_B.ColorSpaceConversion_o1 <= 0.039286085583733095) {
      rtb_Add = brain_B.ColorSpaceConversion_o1 / 12.923054468333255;
    } else {
      rtb_Add = (brain_B.ColorSpaceConversion_o1 + 0.055000519817226347) /
        1.0550005198172263;
      rtb_Add = rt_pow_snf(rtb_Add, 2.4);
    }

    if (brain_B.ColorSpaceConversion_o2 <= 0.039286085583733095) {
      rtb_TSamp = brain_B.ColorSpaceConversion_o2 / 12.923054468333255;
    } else {
      rtb_TSamp = (brain_B.ColorSpaceConversion_o2 + 0.055000519817226347) /
        1.0550005198172263;
      rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
    }

    if (brain_B.ColorSpaceConversion_o3 <= 0.039286085583733095) {
      uyy = brain_B.ColorSpaceConversion_o3 / 12.923054468333255;
    } else {
      uyy = (brain_B.ColorSpaceConversion_o3 + 0.055000519817226347) /
        1.0550005198172263;
      uyy = rt_pow_snf(uyy, 2.4);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    uxx = (0.41239079926596 * rtb_Add + 0.35758433938388 * rtb_TSamp) +
      0.18048078840183 * uyy;
    cc = (0.21263900587151 * rtb_Add + 0.71516867876776 * rtb_TSamp) +
      0.07219231536073 * uyy;
    xys = (0.01933081871559 * rtb_Add + 0.11919477979463 * rtb_TSamp) +
      0.95053215224966 * uyy;

    /* Make sure that the output is in [0..1] range; clip if necessary */
    if (uxx > 1.0) {
      uxx = 1.0;
    } else {
      if (uxx < 0.0) {
        uxx = 0.0;
      }
    }

    if (cc > 1.0) {
      cc = 1.0;
    } else {
      if (cc < 0.0) {
        cc = 0.0;
      }
    }

    if (xys > 1.0) {
      xys = 1.0;
    } else {
      if (xys < 0.0) {
        xys = 0.0;
      }
    }

    /* assign the results */
    brain_B.ColorSpaceConversion1_o1_d = uxx;
    brain_B.ColorSpaceConversion1_o2_k = cc;
    brain_B.ColorSpaceConversion1_o3_e = xys;

    /* Convert from XYZ to L*a*b* */
    rtb_Add = brain_B.ColorSpaceConversion1_o1_d / 0.9641986557609;
    uyy = brain_B.ColorSpaceConversion1_o3_e / 0.82511648322104;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (rtb_Add > 0.0088564516790356311) {
      ys = rt_pow_snf(rtb_Add, 0.33333333333333331);
    } else {
      ys = 7.7870370370370372 * rtb_Add + 0.13793103448275862;
    }

    if (brain_B.ColorSpaceConversion1_o2_k > 0.0088564516790356311) {
      rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_k,
        0.33333333333333331);
    } else {
      rtb_TSamp = 7.7870370370370372 * brain_B.ColorSpaceConversion1_o2_k +
        0.13793103448275862;
    }

    if (uyy > 0.0088564516790356311) {
      rtb_Add = rt_pow_snf(uyy, 0.33333333333333331);
    } else {
      rtb_Add = 7.7870370370370372 * uyy + 0.13793103448275862;
    }

    /* assign the results */
    brain_B.ColorSpaceConversion1_o1_d = 116.0 * rtb_TSamp - 16.0;
    brain_B.ColorSpaceConversion1_o2_k = (ys - rtb_TSamp) * 500.0;
    brain_B.ColorSpaceConversion1_o3_e = (rtb_TSamp - rtb_Add) * 200.0;

    /* Embedded MATLAB: '<S58>/Choose Closest Color' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Choose Closest Color': '<S59>:1' */
    /*  This function chooses the appropriate color option from the reference colors */
    /*  and set of desired L,a,b values */
    /* '<S59>:1:5' */
    /* '<S59>:1:7' */
    rtb_Add = 1000.0;

    /* '<S59>:1:8' */
    uxx = brain_B.Num_Colors_p + 1.0;
    uxx = (int32_T)(uxx < 0.0) ? ceil(uxx - 0.5) : floor(uxx + 0.5);
    if (uxx < 128.0) {
      if (uxx >= -128.0) {
        rtb_index = (int8_T)uxx;
      } else {
        rtb_index = MIN_int8_T;
      }
    } else {
      rtb_index = MAX_int8_T;
    }

    /* '<S59>:1:11' */
    for (rtb_TSamp = 1.0; rtb_TSamp <= brain_B.Num_Colors_p; rtb_TSamp++) {
      /* '<S59>:1:11' */
      /* '<S59>:1:12' */
      uyy = sqrt((rt_pow_snf(brain_B.ColorSpaceConversion1_o1_d -
        brain_B.Ref_Colors_d[(int32_T)rtb_TSamp - 1], 2.0) * 2.0 + rt_pow_snf
                  (brain_B.ColorSpaceConversion1_o2_k - brain_B.Ref_Colors_d
                   [(int32_T)rtb_TSamp + 49], 2.0)) + rt_pow_snf
                 (brain_B.ColorSpaceConversion1_o3_e - brain_B.Ref_Colors_d
                  [(int32_T)rtb_TSamp + 99], 2.0));
      if ((uyy < rtb_Add) && (uyy < 70.0)) {
        /* '<S59>:1:13' */
        /*  L: 0 - 100,a: -100 - 100 , b: -100 - 100 */
        /* '<S59>:1:14' */
        rtb_Add = uyy;

        /*  max min_dist = 346 if L dist is doubled */
        /* '<S59>:1:15' */
        uxx = floor(rtb_TSamp + 0.5);
        if (uxx < 128.0) {
          rtb_index = (int8_T)uxx;
        } else {
          rtb_index = MAX_int8_T;
        }

        /*  max min_dist = 300 if L dist is not doubled */
      }
    }

    /* RelationalOperator: '<S58>/Relational Operator' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BW_fi[i_0] = (brain_B.LabMatrix_b[i_0] == (real_T)rtb_index);
    }

    /* S-Function (svipblob): '<S13>/Buoy Blob Analysis' */
    maxNumBlobsReached = FALSE;
    for (loop = 0; loop < 123; loop++) {
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[loop] = 0U;
    }

    currentLabel = 1U;
    i_0 = 0;
    idx = 123;
    for (n = 0; n < 160; n++) {
      for (pixListMinc = 0; pixListMinc < 120; pixListMinc++) {
        brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = (uint8_T)(brain_B.BW_fi[i_0]
          ? 255 : 0);
        i_0++;
        idx++;
      }

      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = 0U;
      idx++;
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[idx] = 0U;
      idx++;
    }

    for (loop = 0; loop < 121; loop++) {
      brain_DWork.BuoyBlobAnalysis_PAD_DW_h[loop + idx] = 0U;
    }

    idx = 1;
    stackIdx = 0U;
    pixIdx = 0U;
    for (n = 0; n < 160; n++) {
      minr = 1;
      maxc = idx * 122;
      for (pixListMinc = 0; pixListMinc < 120; pixListMinc++) {
        numBlobs = (uint32_T)(maxc + minr);
        start_pixIdx = pixIdx;
        if (brain_DWork.BuoyBlobAnalysis_PAD_DW_h[numBlobs] == 255) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_h[numBlobs] = currentLabel;
          brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[pixIdx] = (int16_T)(idx -
            1);
          brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixIdx] = (int16_T)(minr -
            1);
          pixIdx++;
          BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] = 1U;
          brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx] = numBlobs;
          stackIdx++;
          while (stackIdx) {
            stackIdx--;
            numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx];
            for (i_0 = 0; i_0 < 8; i_0++) {
              k = numBlobs + (uint32_T)brain_ConstP.pooled27[i_0];
              if (brain_DWork.BuoyBlobAnalysis_PAD_DW_h[k] == 255) {
                brain_DWork.BuoyBlobAnalysis_PAD_DW_h[k] = currentLabel;
                brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[pixIdx] = (int16_T)
                  ((int16_T)(k / 122U) - 1);
                brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixIdx] = (int16_T)
                  (k % 122U - 1U);
                pixIdx++;
                BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] =
                  BuoyBlobAnalysis_NUM_PIX_DW_c[currentLabel - 1] + 1U;
                brain_DWork.BuoyBlobAnalysis_STACK_DW_g[stackIdx] = k;
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
            n = 160;
            pixListMinc = 120;
          }

          if (pixListMinc < 120) {
            currentLabel++;
          }
        }

        minr++;
      }

      idx++;
    }

    numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
    currentLabel = (uint8_T)numBlobs;
    pixListMinc = 0;
    padRows = 0;
    for (i_0 = 0; i_0 < (int32_T)numBlobs; i_0++) {
      loop = 0;
      idx = 0;
      for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
           padCols++) {
        loop += brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[padCols + padRows];
        idx += brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[padCols + pixListMinc];
      }

      rtb_BlobPos[0] = (real_T)idx / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_BlobPos[1] = (real_T)loop / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_BuoyBlobAnalysis_o1[i_0 << 1] = rtb_BlobPos[0];
      rtb_BuoyBlobAnalysis_o1[(i_0 << 1) + 1] = rtb_BlobPos[1];
      idx = 160;
      minr = 120;
      maxc = 0;
      n = 0;
      for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
           padCols++) {
        loop = padCols + padRows;
        if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[loop] < idx) {
          idx = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[loop];
        }

        if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[loop] > maxc) {
          maxc = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[loop];
        }

        loop = padCols + pixListMinc;
        if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[loop] < minr) {
          minr = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[loop];
        }

        if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[loop] > n) {
          n = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[loop];
        }
      }

      rtb_Add = 0.0;
      ys = 0.0;
      xys = 0.0;
      for (k = 0U; k < (uint32_T)(int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0]; k
           ++) {
        rtb_TSamp = (real_T)brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_k[padRows
          + (int32_T)k] - rtb_BlobPos[1];
        uyy = (real_T)brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_m[pixListMinc +
          (int32_T)k] - rtb_BlobPos[0];
        rtb_Add += rtb_TSamp * rtb_TSamp;
        ys += uyy * uyy;
        xys += rtb_TSamp * (-uyy);
      }

      uxx = rtb_Add / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] +
        0.083333333333333329;
      uyy = ys / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] +
        0.083333333333333329;
      rtb_Add = xys / (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      rtb_Add = sqrt((uxx - uyy) * (uxx - uyy) + rtb_Add * rtb_Add * 4.0);
      rtb_TSamp = ((uxx + uyy) + rtb_Add) * 8.0;
      rtb_BuoyBlobAnalysis_o2[i_0] = sqrt(rtb_TSamp - ((uxx + uyy) - rtb_Add) *
        8.0) / sqrt(rtb_TSamp);
      rtb_BuoyBlobAnalysis_o3[i_0] = (real_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0] /
        (real_T)(((n + 1) - minr) * ((maxc + 1) - idx));
      pixListMinc += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
      padRows += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_c[i_0];
    }

    for (loop = (int32_T)(numBlobs << 1); loop < 20; loop++) {
      rtb_BuoyBlobAnalysis_o1[loop] = -1.0;
    }

    for (loop = (int32_T)numBlobs; loop < 10; loop++) {
      rtb_BuoyBlobAnalysis_o2[loop] = -1.0;
    }

    for (loop = (int32_T)numBlobs; loop < 10; loop++) {
      rtb_BuoyBlobAnalysis_o3[loop] = -1.0;
    }

    /* S-Function (svipscalenconvert): '<S13>/Image Data Type Conversion' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.ImageDataTypeConversion[i_0] = brain_B.BW_fi[i_0] ? 1.0 : 0.0;
    }

    /* Embedded MATLAB: '<S13>/IF Buoy Conditions' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant3'
     *  Constant: '<S13>/Constant4'
     */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/IF Buoy Conditions': '<S57>:1' */
    /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
    /*  if there is a buoy present in the current image */
    /* '<S57>:1:5' */
    brain_B.Image_g = 0.0;

    /* '<S57>:1:7' */
    rtb_BlobPos[0] = 1.0;
    rtb_BlobPos[1] = 1.0;

    /* '<S57>:1:9' */
    for (i = 1U; i <= currentLabel; i = (uint8_T)((uint32_T)i + 1U)) {
      /* '<S57>:1:9' */
      if ((rtb_BuoyBlobAnalysis_o2[i - 1] > brain_P.Buoy_Min_Eccentricity) &&
          (rtb_BuoyBlobAnalysis_o2[i - 1] < brain_P.Buoy_Max_Eccentricity) &&
          (rtb_BuoyBlobAnalysis_o3[i - 1] > brain_P.Buoy_Min_Extent) &&
          (rtb_BuoyBlobAnalysis_o3[i - 1] < brain_P.Buoy_Max_Extent)) {
        /* '<S57>:1:10' */
        /* '<S57>:1:11' */
        brain_B.Image_g = 1.0;

        /* '<S57>:1:12' */
        rtb_BlobPos[0] = rtb_BuoyBlobAnalysis_o1[(i - 1) << 1];

        /* '<S57>:1:13' */
        rtb_BlobPos[1] = rtb_BuoyBlobAnalysis_o1[((i - 1) << 1) + 1];
      }
    }

    /* S-Function (svipdrawmarkers): '<S13>/Draw Markers' */
    /* Copy the image from input to output. */
    memcpy((void *)(&brain_B.DrawMarkers[0]), (void *)
           (&brain_B.ImageDataTypeConversion[0]), 19200U * sizeof(real_T));

    /* Draw all X marks. */
    for (pixListMinc = 0; pixListMinc < 2; pixListMinc += 2) {
      uxx = rtb_BlobPos[pixListMinc];
      if ((rtb_BlobPos[pixListMinc] < 4.503599627370496E+15) &&
          (rtb_BlobPos[pixListMinc] > -4.503599627370496E+15)) {
        uxx = floor(rtb_BlobPos[pixListMinc] + 0.5);
      }

      i_0 = (int32_T)uxx;
      uxx = rtb_BlobPos[pixListMinc + 1];
      if ((rtb_BlobPos[pixListMinc + 1] < 4.503599627370496E+15) &&
          (rtb_BlobPos[pixListMinc + 1] > -4.503599627370496E+15)) {
        uxx = floor(rtb_BlobPos[pixListMinc + 1] + 0.5);
      }

      n = (int32_T)uxx;
      padRows = i_0 - 7;
      padCols = n - 7;
      maxc = i_0 + 7;
      line_idx = n + 7;
      maxNumBlobsReached = FALSE;

      /* Find the visible portion of a line. */
      visited = FALSE;
      visited_0 = FALSE;
      done = FALSE;
      line_idx_3 = padRows;
      line_idx_2 = padCols;
      line_idx_1 = maxc;
      line_idx_0 = line_idx;
      while (!done) {
        numBlobs = 0U;
        k = 0U;

        /* Determine viewport violations. */
        if (line_idx_3 < 0) {
          numBlobs = 4U;
        } else {
          if (line_idx_3 > 119) {
            numBlobs = 8U;
          }
        }

        if (line_idx_1 < 0) {
          k = 4U;
        } else {
          if (line_idx_1 > 119) {
            k = 8U;
          }
        }

        if (line_idx_2 < 0) {
          numBlobs |= 1U;
        } else {
          if (line_idx_2 > 159) {
            numBlobs |= 2U;
          }
        }

        if (line_idx_0 < 0) {
          k |= 1U;
        } else {
          if (line_idx_0 > 159) {
            k |= 2U;
          }
        }

        if (!(numBlobs | k)) {
          /* Line falls completely within bounds. */
          done = TRUE;
          maxNumBlobsReached = TRUE;
        } else if (numBlobs & k) {
          /* Line falls completely out of bounds. */
          done = TRUE;
          maxNumBlobsReached = FALSE;
        } else if (numBlobs != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited) {
            line_idx_3 = padRows;
            line_idx_2 = padCols;
          }

          loop = line_idx_1 - line_idx_3;
          idx = line_idx_0 - line_idx_2;
          if (numBlobs & 4U) {
            /* Violated RMin. */
            minr = (0 - line_idx_3) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_2 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_2 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_3 = 0;
            visited = TRUE;
          } else if (numBlobs & 8U) {
            /* Violated RMax. */
            minr = (119 - line_idx_3) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_2 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_2 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_3 = 119;
            visited = TRUE;
          } else if (numBlobs & 1U) {
            /* Violated CMin. */
            minr = (0 - line_idx_2) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_3 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_2 = 0;
            visited = TRUE;
          } else {
            /* Violated CMax. */
            minr = (159 - line_idx_2) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_3 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_2 = 159;
            visited = TRUE;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited_0) {
            line_idx_1 = maxc;
            line_idx_0 = line_idx;
          }

          loop = line_idx_1 - line_idx_3;
          idx = line_idx_0 - line_idx_2;
          if (k & 4U) {
            /* Violated RMin. */
            minr = (0 - line_idx_1) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_0 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_1 = 0;
            visited_0 = TRUE;
          } else if (k & 8U) {
            /* Violated RMax. */
            minr = (119 - line_idx_1) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_0 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_1 = 119;
            visited_0 = TRUE;
          } else if (k & 1U) {
            /* Violated CMin. */
            minr = (0 - line_idx_0) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_1 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_0 = 0;
            visited_0 = TRUE;
          } else {
            /* Violated CMax. */
            minr = (159 - line_idx_0) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_1 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_0 = 159;
            visited_0 = TRUE;
          }
        }
      }

      if (maxNumBlobsReached) {
        idx = line_idx_2 * 120 + line_idx_3;
        for (minr = line_idx_3; minr <= line_idx_1; minr++) {
          brain_B.DrawMarkers[idx] = 0.75;
          idx += 121;
        }
      }

      padRows = i_0 - 7;
      padCols = n + 7;
      maxc = i_0 + 7;
      line_idx = n - 7;
      maxNumBlobsReached = FALSE;

      /* Find the visible portion of a line. */
      visited = FALSE;
      visited_0 = FALSE;
      done = FALSE;
      line_idx_3 = padRows;
      line_idx_2 = padCols;
      line_idx_1 = maxc;
      line_idx_0 = line_idx;
      while (!done) {
        numBlobs = 0U;
        k = 0U;

        /* Determine viewport violations. */
        if (line_idx_3 < 0) {
          numBlobs = 4U;
        } else {
          if (line_idx_3 > 119) {
            numBlobs = 8U;
          }
        }

        if (line_idx_1 < 0) {
          k = 4U;
        } else {
          if (line_idx_1 > 119) {
            k = 8U;
          }
        }

        if (line_idx_2 < 0) {
          numBlobs |= 1U;
        } else {
          if (line_idx_2 > 159) {
            numBlobs |= 2U;
          }
        }

        if (line_idx_0 < 0) {
          k |= 1U;
        } else {
          if (line_idx_0 > 159) {
            k |= 2U;
          }
        }

        if (!(numBlobs | k)) {
          /* Line falls completely within bounds. */
          done = TRUE;
          maxNumBlobsReached = TRUE;
        } else if (numBlobs & k) {
          /* Line falls completely out of bounds. */
          done = TRUE;
          maxNumBlobsReached = FALSE;
        } else if (numBlobs != 0U) {
          /* Clip 1st point; if it's in-bounds, clip 2nd point. */
          if (visited) {
            line_idx_3 = padRows;
            line_idx_2 = padCols;
          }

          loop = line_idx_1 - line_idx_3;
          idx = line_idx_0 - line_idx_2;
          if (numBlobs & 4U) {
            /* Violated RMin. */
            minr = (0 - line_idx_3) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_2 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_2 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_3 = 0;
            visited = TRUE;
          } else if (numBlobs & 8U) {
            /* Violated RMax. */
            minr = (119 - line_idx_3) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_2 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_2 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_3 = 119;
            visited = TRUE;
          } else if (numBlobs & 1U) {
            /* Violated CMin. */
            minr = (0 - line_idx_2) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_3 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_2 = 0;
            visited = TRUE;
          } else {
            /* Violated CMax. */
            minr = (159 - line_idx_2) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_3 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_3 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_2 = 159;
            visited = TRUE;
          }
        } else {
          /* Clip the 2nd point. */
          if (visited_0) {
            line_idx_1 = maxc;
            line_idx_0 = line_idx;
          }

          loop = line_idx_1 - line_idx_3;
          idx = line_idx_0 - line_idx_2;
          if (k & 4U) {
            /* Violated RMin. */
            minr = (0 - line_idx_1) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_0 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_1 = 0;
            visited_0 = TRUE;
          } else if (k & 8U) {
            /* Violated RMax. */
            minr = (119 - line_idx_1) * idx;
            if (((minr >= 0) && (loop >= 0)) || ((minr < 0) && (loop < 0))) {
              line_idx_0 += (div_s32_floor(minr << 1U, loop) + 1) >> 1;
            } else {
              line_idx_0 += -((div_s32_floor((-minr) << 1U, loop) + 1) >> 1);
            }

            line_idx_1 = 119;
            visited_0 = TRUE;
          } else if (k & 1U) {
            /* Violated CMin. */
            minr = (0 - line_idx_0) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_1 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_0 = 0;
            visited_0 = TRUE;
          } else {
            /* Violated CMax. */
            minr = (159 - line_idx_0) * loop;
            if (((minr >= 0) && (idx >= 0)) || ((minr < 0) && (idx < 0))) {
              line_idx_1 += (div_s32_floor(minr << 1U, idx) + 1) >> 1;
            } else {
              line_idx_1 += -((div_s32_floor((-minr) << 1U, idx) + 1) >> 1);
            }

            line_idx_0 = 159;
            visited_0 = TRUE;
          }
        }
      }

      if (maxNumBlobsReached) {
        idx = line_idx_2 * 120 + line_idx_3;
        for (minr = line_idx_3; minr <= line_idx_1; minr++) {
          brain_B.DrawMarkers[idx] = 0.75;
          idx += -119;
        }
      }
    }

    brain_DWork.Image = brain_B.Image_g;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
    for (i_0 = 0; i_0 < 19200; i_0++) {
      brain_B.BWout[i_0] = brain_B.DrawMarkers[i_0];
      brain_B.LabMatrix_o[i_0] = brain_DWork.LabelMatrix[i_0];
    }

    memcpy((void *)(&brain_B.Ref_Colors_j[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_o, brain_B.Ref_Colors_j,
      &brain_B.StateFlowFunctionsBuoysShowSe_o);
    memcpy((void *)(&brain_B.RGBout[0]), (void *)
           (&brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0]), 57600U * sizeof
           (real_T));
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void bra_exit_internal_ApproachBuoys(void)
{
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
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ApproachBuoys(void)
{
  real_T cc;
  real_T min_dist;
  real_T min_dist_0;
  real_T FirstD[50];
  real_T SecondD[50];
  real_T count;
  real_T count_0;
  real_T Index;
  real_T Index_0;
  int32_T i;

  /* During 'ApproachBuoys': '<S7>:1312' */
  if ((brain_DWork.count2ndarea > 2.0) || (brain_DWork.TurnDirection <= -999.0))
  {
    /* Transition: '<S7>:1455' */
    bra_exit_internal_ApproachBuoys();

    /* Exit 'ApproachBuoys': '<S7>:1312' */
    /* Entry 'BuoyDone': '<S7>:1453' */
    brain_DWork.is_Buoys = brain_IN_BuoyDone;
    brain_B.SubState = 5.0;
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
        brain_B.SubState = 3.0;
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
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'Buoy': '<S7>:1495' */
        memcpy((void *)(&brain_B.LabMatrix[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
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
          brain_B.LabMatrix_o[i] = brain_DWork.LabelMatrix[i];
        }

        memcpy((void *)(&brain_B.Ref_Colors_j[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_o,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsBuoysShowSe_o);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0]), 57600U *
               sizeof(real_T));
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
      memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
             (&brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0]), 19200U *
             sizeof(real_T));
      brain_DWork.num_colors =
        brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
      memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
             (&brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0]), 150U *
             sizeof(real_T));

      /* Simulink Function 'Buoy': '<S7>:1495' */
      memcpy((void *)(&brain_B.LabMatrix[0]), (void *)(&brain_DWork.LabelMatrix
              [0]), 19200U * sizeof(real_T));
      memcpy((void *)(&brain_B.Ref_Colors[0]), (void *)(&brain_DWork.ref_colors
              [0]), 150U * sizeof(real_T));
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
        brain_B.LabMatrix_o[i] = brain_DWork.LabelMatrix[i];
      }

      memcpy((void *)(&brain_B.Ref_Colors_j[0]), (void *)
             (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_o, brain_B.Ref_Colors_j,
        &brain_B.StateFlowFunctionsBuoysShowSe_o);
      memcpy((void *)(&brain_B.RGBout[0]), (void *)
             (&brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0]), 57600U * sizeof
             (real_T));
      break;

     case brain_IN_FindSecondBuoy:
      brain_FindSecondBuoy();
      break;

     default:
      /* Transition: '<S7>:1313' */
      /* Entry 'ApproachFirstBuoy': '<S7>:1341' */
      brain_DWork.is_ApproachBuoys = brain_IN_ApproachFirstBuoy;
      brain_B.SubState = 2.0;

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
      memcpy((void *)(&brain_B.buoys[0]), (void *)(&brain_DWork.BuoyBlobs[0]),
             200U * sizeof(real_T));
      brain_B.num_blobs = brain_DWork.num_blobs;

      /* S-Function (svipcolorconv): '<S43>/Color Space  Conversion' incorporates:
       *  Constant: '<S43>/Constant'
       *  Constant: '<S43>/Constant1'
       *  Constant: '<S43>/Constant2'
       */
      /* temporary variables for in-place operation */
      count_0 = 0.0;
      cc = 0.0;
      count = 0.0;
      Index_0 = 6.0 * brain_P.Buoy1_Hue;
      min_dist_0 = (real_T)(uint32_T)(Index_0 - 1.3322676295501878E-15);
      Index_0 -= min_dist_0;
      Index = 1.0 - brain_P.Buoy1_Saturation;
      min_dist = 1.0 - brain_P.Buoy1_Saturation * Index_0;
      Index_0 = brain_P.Buoy1_Saturation * Index_0 + Index;
      if (min_dist_0 == 0.0) {
        count_0 = 1.0;
        cc = Index_0;
        count = Index;
      } else if (min_dist_0 == 1.0) {
        count_0 = min_dist;
        cc = 1.0;
        count = Index;
      } else if (min_dist_0 == 2.0) {
        count_0 = Index;
        cc = 1.0;
        count = Index_0;
      } else if (min_dist_0 == 3.0) {
        count_0 = Index;
        cc = min_dist;
        count = 1.0;
      } else if (min_dist_0 == 4.0) {
        count_0 = Index_0;
        cc = Index;
        count = 1.0;
      } else {
        if (min_dist_0 == 5.0) {
          count_0 = 1.0;
          cc = Index;
          count = min_dist;
        }
      }

      if (count_0 > cc) {
        Index_0 = count_0;
      } else {
        Index_0 = cc;
      }

      if (!(Index_0 > count)) {
        Index_0 = count;
      }

      Index_0 = brain_P.Buoy1_Value / Index_0;

      /* assign the results */
      brain_B.ColorSpaceConversion_o3_c = Index_0 * count_0;
      brain_B.ColorSpaceConversion_o2_o = Index_0 * cc;
      brain_B.ColorSpaceConversion_o1_g = Index_0 * count;

      /* S-Function (svipcolorconv): '<S43>/Color Space  Conversion1' */
      /* temporary variables for in-place operation */
      /* Convert to XYZ */
      /* temporary variables for in-place operation */
      /* First, linearize (de-gamma) the RGB values; the operation is */
      /* equivalent to running the gamma correction block with break */
      /* point of 0.00304 and gamma of 2.4; it's built into this */
      /* conversion for convenience */
      if (brain_B.ColorSpaceConversion_o3_c <= 0.039286085583733095) {
        Index_0 = brain_B.ColorSpaceConversion_o3_c / 12.923054468333255;
      } else {
        Index_0 = (brain_B.ColorSpaceConversion_o3_c + 0.055000519817226347) /
          1.0550005198172263;
        Index_0 = rt_pow_snf(Index_0, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o2_o <= 0.039286085583733095) {
        min_dist = brain_B.ColorSpaceConversion_o2_o / 12.923054468333255;
      } else {
        min_dist = (brain_B.ColorSpaceConversion_o2_o + 0.055000519817226347) /
          1.0550005198172263;
        min_dist = rt_pow_snf(min_dist, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o1_g <= 0.039286085583733095) {
        Index = brain_B.ColorSpaceConversion_o1_g / 12.923054468333255;
      } else {
        Index = (brain_B.ColorSpaceConversion_o1_g + 0.055000519817226347) /
          1.0550005198172263;
        Index = rt_pow_snf(Index, 2.4);
      }

      /* The coefficients for this conversion were derived from ITU-R */
      /* BT.709 reference primaries for sRGB and CIE standard illuminant */
      /* D65, 2 degree observer */
      count_0 = (0.41239079926596 * Index_0 + 0.35758433938388 * min_dist) +
        0.18048078840183 * Index;
      cc = (0.21263900587151 * Index_0 + 0.71516867876776 * min_dist) +
        0.07219231536073 * Index;
      count = (0.01933081871559 * Index_0 + 0.11919477979463 * min_dist) +
        0.95053215224966 * Index;

      /* Make sure that the output is in [0..1] range; clip if necessary */
      if (count_0 > 1.0) {
        count_0 = 1.0;
      } else {
        if (count_0 < 0.0) {
          count_0 = 0.0;
        }
      }

      if (cc > 1.0) {
        cc = 1.0;
      } else {
        if (cc < 0.0) {
          cc = 0.0;
        }
      }

      if (count > 1.0) {
        count = 1.0;
      } else {
        if (count < 0.0) {
          count = 0.0;
        }
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1 = count_0;
      brain_B.ColorSpaceConversion1_o2 = cc;
      brain_B.ColorSpaceConversion1_o3 = count;

      /* Convert from XYZ to L*a*b* */
      Index_0 = brain_B.ColorSpaceConversion1_o1 / 0.9641986557609;
      Index = brain_B.ColorSpaceConversion1_o3 / 0.82511648322104;

      /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
      if (Index_0 > 0.0088564516790356311) {
        min_dist_0 = rt_pow_snf(Index_0, 0.33333333333333331);
      } else {
        min_dist_0 = 7.7870370370370372 * Index_0 + 0.13793103448275862;
      }

      if (brain_B.ColorSpaceConversion1_o2 > 0.0088564516790356311) {
        min_dist = rt_pow_snf(brain_B.ColorSpaceConversion1_o2,
                              0.33333333333333331);
      } else {
        min_dist = 7.7870370370370372 * brain_B.ColorSpaceConversion1_o2 +
          0.13793103448275862;
      }

      if (Index > 0.0088564516790356311) {
        Index_0 = rt_pow_snf(Index, 0.33333333333333331);
      } else {
        Index_0 = 7.7870370370370372 * Index + 0.13793103448275862;
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1 = 116.0 * min_dist - 16.0;
      brain_B.ColorSpaceConversion1_o2 = (min_dist_0 - min_dist) * 500.0;
      brain_B.ColorSpaceConversion1_o3 = (min_dist - Index_0) * 200.0;

      /* S-Function (svipcolorconv): '<S45>/Color Space  Conversion' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S45>/Constant1'
       *  Constant: '<S45>/Constant2'
       */
      /* temporary variables for in-place operation */
      count_0 = 0.0;
      cc = 0.0;
      count = 0.0;
      Index_0 = 6.0 * brain_P.Buoy2_Hue;
      min_dist_0 = (real_T)(uint32_T)(Index_0 - 1.3322676295501878E-15);
      Index_0 -= min_dist_0;
      Index = 1.0 - brain_P.Buoy2_Saturation;
      min_dist = 1.0 - brain_P.Buoy2_Saturation * Index_0;
      Index_0 = brain_P.Buoy2_Saturation * Index_0 + Index;
      if (min_dist_0 == 0.0) {
        count_0 = 1.0;
        cc = Index_0;
        count = Index;
      } else if (min_dist_0 == 1.0) {
        count_0 = min_dist;
        cc = 1.0;
        count = Index;
      } else if (min_dist_0 == 2.0) {
        count_0 = Index;
        cc = 1.0;
        count = Index_0;
      } else if (min_dist_0 == 3.0) {
        count_0 = Index;
        cc = min_dist;
        count = 1.0;
      } else if (min_dist_0 == 4.0) {
        count_0 = Index_0;
        cc = Index;
        count = 1.0;
      } else {
        if (min_dist_0 == 5.0) {
          count_0 = 1.0;
          cc = Index;
          count = min_dist;
        }
      }

      if (count_0 > cc) {
        Index_0 = count_0;
      } else {
        Index_0 = cc;
      }

      if (!(Index_0 > count)) {
        Index_0 = count;
      }

      Index_0 = brain_P.Buoy2_Value / Index_0;

      /* assign the results */
      brain_B.ColorSpaceConversion_o1_g = Index_0 * count_0;
      brain_B.ColorSpaceConversion_o2_o = Index_0 * cc;
      brain_B.ColorSpaceConversion_o3_c = Index_0 * count;

      /* S-Function (svipcolorconv): '<S45>/Color Space  Conversion1' */
      /* temporary variables for in-place operation */
      /* Convert to XYZ */
      /* temporary variables for in-place operation */
      /* First, linearize (de-gamma) the RGB values; the operation is */
      /* equivalent to running the gamma correction block with break */
      /* point of 0.00304 and gamma of 2.4; it's built into this */
      /* conversion for convenience */
      if (brain_B.ColorSpaceConversion_o1_g <= 0.039286085583733095) {
        Index_0 = brain_B.ColorSpaceConversion_o1_g / 12.923054468333255;
      } else {
        Index_0 = (brain_B.ColorSpaceConversion_o1_g + 0.055000519817226347) /
          1.0550005198172263;
        Index_0 = rt_pow_snf(Index_0, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o2_o <= 0.039286085583733095) {
        min_dist = brain_B.ColorSpaceConversion_o2_o / 12.923054468333255;
      } else {
        min_dist = (brain_B.ColorSpaceConversion_o2_o + 0.055000519817226347) /
          1.0550005198172263;
        min_dist = rt_pow_snf(min_dist, 2.4);
      }

      if (brain_B.ColorSpaceConversion_o3_c <= 0.039286085583733095) {
        Index = brain_B.ColorSpaceConversion_o3_c / 12.923054468333255;
      } else {
        Index = (brain_B.ColorSpaceConversion_o3_c + 0.055000519817226347) /
          1.0550005198172263;
        Index = rt_pow_snf(Index, 2.4);
      }

      /* The coefficients for this conversion were derived from ITU-R */
      /* BT.709 reference primaries for sRGB and CIE standard illuminant */
      /* D65, 2 degree observer */
      count_0 = (0.41239079926596 * Index_0 + 0.35758433938388 * min_dist) +
        0.18048078840183 * Index;
      cc = (0.21263900587151 * Index_0 + 0.71516867876776 * min_dist) +
        0.07219231536073 * Index;
      count = (0.01933081871559 * Index_0 + 0.11919477979463 * min_dist) +
        0.95053215224966 * Index;

      /* Make sure that the output is in [0..1] range; clip if necessary */
      if (count_0 > 1.0) {
        count_0 = 1.0;
      } else {
        if (count_0 < 0.0) {
          count_0 = 0.0;
        }
      }

      if (cc > 1.0) {
        cc = 1.0;
      } else {
        if (cc < 0.0) {
          cc = 0.0;
        }
      }

      if (count > 1.0) {
        count = 1.0;
      } else {
        if (count < 0.0) {
          count = 0.0;
        }
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1_n = count_0;
      brain_B.ColorSpaceConversion1_o2_i = cc;
      brain_B.ColorSpaceConversion1_o3_m = count;

      /* Convert from XYZ to L*a*b* */
      Index_0 = brain_B.ColorSpaceConversion1_o1_n / 0.9641986557609;
      Index = brain_B.ColorSpaceConversion1_o3_m / 0.82511648322104;

      /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
      if (Index_0 > 0.0088564516790356311) {
        min_dist_0 = rt_pow_snf(Index_0, 0.33333333333333331);
      } else {
        min_dist_0 = 7.7870370370370372 * Index_0 + 0.13793103448275862;
      }

      if (brain_B.ColorSpaceConversion1_o2_i > 0.0088564516790356311) {
        min_dist = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_i,
                              0.33333333333333331);
      } else {
        min_dist = 7.7870370370370372 * brain_B.ColorSpaceConversion1_o2_i +
          0.13793103448275862;
      }

      if (Index > 0.0088564516790356311) {
        Index_0 = rt_pow_snf(Index, 0.33333333333333331);
      } else {
        Index_0 = 7.7870370370370372 * Index + 0.13793103448275862;
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1_n = 116.0 * min_dist - 16.0;
      brain_B.ColorSpaceConversion1_o2_i = (min_dist_0 - min_dist) * 500.0;
      brain_B.ColorSpaceConversion1_o3_m = (min_dist - Index_0) * 200.0;

      /* Embedded MATLAB: '<S9>/GetBestColorMatch' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch': '<S44>:1' */
      /*  This function determines which buoys are the best match for the desired colors */
      /*  Buoys = zeros(3,3); */
      /*  Buoys = [L;M;R]; */
      /* '<S44>:1:6' */
      min_dist = 1000.0;

      /* '<S44>:1:7' */
      min_dist_0 = 1000.0;

      /* '<S44>:1:8' */
      /* '<S44>:1:9' */
      for (i = 0; i < 50; i++) {
        FirstD[i] = 2.0;
        SecondD[i] = 2.0;
      }

      /* '<S44>:1:11' */
      count = 0.0;

      /* '<S44>:1:12' */
      count_0 = 0.0;

      /* '<S44>:1:14' */
      for (Index = 1.0; Index <= brain_B.num_blobs; Index++) {
        /* '<S44>:1:14' */
        /* '<S44>:1:15' */
        Index_0 = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)Index - 1] -
          brain_B.ColorSpaceConversion1_o1, 2.0) + rt_pow_snf(brain_B.buoys
          [(int32_T)Index + 49] - brain_B.ColorSpaceConversion1_o2, 2.0)) +
                       rt_pow_snf(brain_B.buoys[(int32_T)Index + 99] -
          brain_B.ColorSpaceConversion1_o3, 2.0));
        if (Index_0 <= min_dist) {
          /* '<S44>:1:16' */
          /* '<S44>:1:17' */
          count++;

          /* '<S44>:1:18' */
          min_dist = Index_0;

          /* '<S44>:1:19' */
          FirstD[(int32_T)count - 1] = Index;
        }

        /* '<S44>:1:21' */
        Index_0 = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)Index - 1] -
          brain_B.ColorSpaceConversion1_o1_n, 2.0) + rt_pow_snf(brain_B.buoys
          [(int32_T)Index + 49] - brain_B.ColorSpaceConversion1_o2_i, 2.0)) +
                       rt_pow_snf(brain_B.buoys[(int32_T)Index + 99] -
          brain_B.ColorSpaceConversion1_o3_m, 2.0));
        if (Index_0 < min_dist_0) {
          /* '<S44>:1:22' */
          /* '<S44>:1:23' */
          count_0++;

          /* '<S44>:1:24' */
          min_dist_0 = Index_0;

          /* '<S44>:1:25' */
          SecondD[(int32_T)count_0 - 1] = Index;
        }
      }

      /* '<S44>:1:29' */
      Index = 2.0;

      /* '<S44>:1:30' */
      /* '<S44>:1:31' */
      for (Index_0 = 1.0; Index_0 <= count; Index_0++) {
        /* '<S44>:1:31' */
        /* '<S44>:1:32' */
        if (brain_B.buoys[(int32_T)FirstD[(int32_T)Index_0 - 1] + 149] > 0.0) {
          /* '<S44>:1:33' */
          /* '<S44>:1:34' */
          Index = FirstD[(int32_T)Index_0 - 1];
        }
      }

      /* '<S44>:1:39' */
      Index_0 = 2.0;

      /* '<S44>:1:40' */
      /* '<S44>:1:41' */
      for (min_dist = 1.0; min_dist <= count_0; min_dist++) {
        /* '<S44>:1:41' */
        /* '<S44>:1:42' */
        if (brain_B.buoys[(int32_T)SecondD[(int32_T)min_dist - 1] + 149] > 0.0)
        {
          /* '<S44>:1:43' */
          /* '<S44>:1:44' */
          Index_0 = SecondD[(int32_T)min_dist - 1];
        }
      }

      if (Index > Index_0) {
        /* '<S44>:1:49' */
        /* '<S44>:1:50' */
        brain_B.Direction1 = 1.0;

        /* '<S44>:1:51' */
        brain_B.Direction2 = 3.0;
      } else if (Index == Index_0) {
        /* '<S44>:1:52' */
        /* '<S44>:1:53' */
        brain_B.Direction1 = 2.0;

        /* '<S44>:1:54' */
        brain_B.Direction2 = 2.0;
      } else {
        /* '<S44>:1:56' */
        brain_B.Direction1 = 3.0;

        /* '<S44>:1:57' */
        brain_B.Direction2 = 1.0;
      }
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages(real_T Image1, real_T OldImage, real_T count1)
{
  UNUSED_PARAMETER(OldImage);

  /* Embedded MATLAB Function 'countimages': '<S7>:1300' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  image is recognized by the recognition software */
  if (Image1 == 1.0) {
    /* '<S7>:1300:6' */
    /* '<S7>:1300:7' */
    return count1 + 1.0;
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
    memcpy((void *)(&brain_B.LabelMatrix[0]), (void *)(&brain_DWork.LabelMatrix
            [0]), 19200U * sizeof(real_T));
    memcpy((void *)(&brain_B.ref_colors[0]), (void *)(&brain_DWork.ref_colors[0]),
           150U * sizeof(real_T));
    brain_B.num_colors_k = brain_DWork.num_colors;
    StateFlowFunctionsBuoysFindBu_l(brain_B.LabelMatrix, brain_B.num_colors_k,
      brain_B.ref_colors, &brain_B.StateFlowFunctionsBuoysFindB_ls,
      &brain_DWork.StateFlowFunctionsBuoysFindB_ls);
    memcpy((void *)(&brain_DWork.BuoyBlobs[0]), (void *)
           (&brain_B.StateFlowFunctionsBuoysFindB_ls.blobs[0]), 200U * sizeof
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
  real_T min_dist;
  real_T FirstD[50];
  real_T SecondD[50];
  real_T count;
  real_T count_0;
  real_T Index;
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
    brain_B.SubState = 0.0;
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
        memcpy((void *)(&brain_B.LabelMatrix[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.ref_colors[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.num_colors_k = brain_DWork.num_colors;
        StateFlowFunctionsBuoysFindBu_l(brain_B.LabelMatrix,
          brain_B.num_colors_k, brain_B.ref_colors,
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
        brain_B.SubState = 2.0;

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

        /* S-Function (svipcolorconv): '<S43>/Color Space  Conversion' incorporates:
         *  Constant: '<S43>/Constant'
         *  Constant: '<S43>/Constant1'
         *  Constant: '<S43>/Constant2'
         */
        /* temporary variables for in-place operation */
        count_0 = 0.0;
        cc = 0.0;
        count = 0.0;
        rtb_Add = 6.0 * brain_P.Buoy1_Hue;
        min_dist = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-15);
        rtb_Add -= min_dist;
        rtb_TSamp = 1.0 - brain_P.Buoy1_Saturation;
        Index = 1.0 - brain_P.Buoy1_Saturation * rtb_Add;
        rtb_Add = brain_P.Buoy1_Saturation * rtb_Add + rtb_TSamp;
        if (min_dist == 0.0) {
          count_0 = 1.0;
          cc = rtb_Add;
          count = rtb_TSamp;
        } else if (min_dist == 1.0) {
          count_0 = Index;
          cc = 1.0;
          count = rtb_TSamp;
        } else if (min_dist == 2.0) {
          count_0 = rtb_TSamp;
          cc = 1.0;
          count = rtb_Add;
        } else if (min_dist == 3.0) {
          count_0 = rtb_TSamp;
          cc = Index;
          count = 1.0;
        } else if (min_dist == 4.0) {
          count_0 = rtb_Add;
          cc = rtb_TSamp;
          count = 1.0;
        } else {
          if (min_dist == 5.0) {
            count_0 = 1.0;
            cc = rtb_TSamp;
            count = Index;
          }
        }

        if (count_0 > cc) {
          rtb_Add = count_0;
        } else {
          rtb_Add = cc;
        }

        if (!(rtb_Add > count)) {
          rtb_Add = count;
        }

        rtb_Add = brain_P.Buoy1_Value / rtb_Add;

        /* assign the results */
        brain_B.ColorSpaceConversion_o3_c = rtb_Add * count_0;
        brain_B.ColorSpaceConversion_o2_o = rtb_Add * cc;
        brain_B.ColorSpaceConversion_o1_g = rtb_Add * count;

        /* S-Function (svipcolorconv): '<S43>/Color Space  Conversion1' */
        /* temporary variables for in-place operation */
        /* Convert to XYZ */
        /* temporary variables for in-place operation */
        /* First, linearize (de-gamma) the RGB values; the operation is */
        /* equivalent to running the gamma correction block with break */
        /* point of 0.00304 and gamma of 2.4; it's built into this */
        /* conversion for convenience */
        if (brain_B.ColorSpaceConversion_o3_c <= 0.039286085583733095) {
          rtb_Add = brain_B.ColorSpaceConversion_o3_c / 12.923054468333255;
        } else {
          rtb_Add = (brain_B.ColorSpaceConversion_o3_c + 0.055000519817226347) /
            1.0550005198172263;
          rtb_Add = rt_pow_snf(rtb_Add, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o2_o <= 0.039286085583733095) {
          rtb_TSamp = brain_B.ColorSpaceConversion_o2_o / 12.923054468333255;
        } else {
          rtb_TSamp = (brain_B.ColorSpaceConversion_o2_o + 0.055000519817226347)
            / 1.0550005198172263;
          rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o1_g <= 0.039286085583733095) {
          Index = brain_B.ColorSpaceConversion_o1_g / 12.923054468333255;
        } else {
          Index = (brain_B.ColorSpaceConversion_o1_g + 0.055000519817226347) /
            1.0550005198172263;
          Index = rt_pow_snf(Index, 2.4);
        }

        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        count_0 = (0.41239079926596 * rtb_Add + 0.35758433938388 * rtb_TSamp) +
          0.18048078840183 * Index;
        cc = (0.21263900587151 * rtb_Add + 0.71516867876776 * rtb_TSamp) +
          0.07219231536073 * Index;
        count = (0.01933081871559 * rtb_Add + 0.11919477979463 * rtb_TSamp) +
          0.95053215224966 * Index;

        /* Make sure that the output is in [0..1] range; clip if necessary */
        if (count_0 > 1.0) {
          count_0 = 1.0;
        } else {
          if (count_0 < 0.0) {
            count_0 = 0.0;
          }
        }

        if (cc > 1.0) {
          cc = 1.0;
        } else {
          if (cc < 0.0) {
            cc = 0.0;
          }
        }

        if (count > 1.0) {
          count = 1.0;
        } else {
          if (count < 0.0) {
            count = 0.0;
          }
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1 = count_0;
        brain_B.ColorSpaceConversion1_o2 = cc;
        brain_B.ColorSpaceConversion1_o3 = count;

        /* Convert from XYZ to L*a*b* */
        rtb_Add = brain_B.ColorSpaceConversion1_o1 / 0.9641986557609;
        Index = brain_B.ColorSpaceConversion1_o3 / 0.82511648322104;

        /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
        if (rtb_Add > 0.0088564516790356311) {
          min_dist = rt_pow_snf(rtb_Add, 0.33333333333333331);
        } else {
          min_dist = 7.7870370370370372 * rtb_Add + 0.13793103448275862;
        }

        if (brain_B.ColorSpaceConversion1_o2 > 0.0088564516790356311) {
          rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2,
            0.33333333333333331);
        } else {
          rtb_TSamp = 7.7870370370370372 * brain_B.ColorSpaceConversion1_o2 +
            0.13793103448275862;
        }

        if (Index > 0.0088564516790356311) {
          rtb_Add = rt_pow_snf(Index, 0.33333333333333331);
        } else {
          rtb_Add = 7.7870370370370372 * Index + 0.13793103448275862;
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1 = 116.0 * rtb_TSamp - 16.0;
        brain_B.ColorSpaceConversion1_o2 = (min_dist - rtb_TSamp) * 500.0;
        brain_B.ColorSpaceConversion1_o3 = (rtb_TSamp - rtb_Add) * 200.0;

        /* S-Function (svipcolorconv): '<S45>/Color Space  Conversion' incorporates:
         *  Constant: '<S45>/Constant'
         *  Constant: '<S45>/Constant1'
         *  Constant: '<S45>/Constant2'
         */
        /* temporary variables for in-place operation */
        count_0 = 0.0;
        cc = 0.0;
        count = 0.0;
        rtb_Add = 6.0 * brain_P.Buoy2_Hue;
        min_dist = (real_T)(uint32_T)(rtb_Add - 1.3322676295501878E-15);
        rtb_Add -= min_dist;
        rtb_TSamp = 1.0 - brain_P.Buoy2_Saturation;
        Index = 1.0 - brain_P.Buoy2_Saturation * rtb_Add;
        rtb_Add = brain_P.Buoy2_Saturation * rtb_Add + rtb_TSamp;
        if (min_dist == 0.0) {
          count_0 = 1.0;
          cc = rtb_Add;
          count = rtb_TSamp;
        } else if (min_dist == 1.0) {
          count_0 = Index;
          cc = 1.0;
          count = rtb_TSamp;
        } else if (min_dist == 2.0) {
          count_0 = rtb_TSamp;
          cc = 1.0;
          count = rtb_Add;
        } else if (min_dist == 3.0) {
          count_0 = rtb_TSamp;
          cc = Index;
          count = 1.0;
        } else if (min_dist == 4.0) {
          count_0 = rtb_Add;
          cc = rtb_TSamp;
          count = 1.0;
        } else {
          if (min_dist == 5.0) {
            count_0 = 1.0;
            cc = rtb_TSamp;
            count = Index;
          }
        }

        if (count_0 > cc) {
          rtb_Add = count_0;
        } else {
          rtb_Add = cc;
        }

        if (!(rtb_Add > count)) {
          rtb_Add = count;
        }

        rtb_Add = brain_P.Buoy2_Value / rtb_Add;

        /* assign the results */
        brain_B.ColorSpaceConversion_o1_g = rtb_Add * count_0;
        brain_B.ColorSpaceConversion_o2_o = rtb_Add * cc;
        brain_B.ColorSpaceConversion_o3_c = rtb_Add * count;

        /* S-Function (svipcolorconv): '<S45>/Color Space  Conversion1' */
        /* temporary variables for in-place operation */
        /* Convert to XYZ */
        /* temporary variables for in-place operation */
        /* First, linearize (de-gamma) the RGB values; the operation is */
        /* equivalent to running the gamma correction block with break */
        /* point of 0.00304 and gamma of 2.4; it's built into this */
        /* conversion for convenience */
        if (brain_B.ColorSpaceConversion_o1_g <= 0.039286085583733095) {
          rtb_Add = brain_B.ColorSpaceConversion_o1_g / 12.923054468333255;
        } else {
          rtb_Add = (brain_B.ColorSpaceConversion_o1_g + 0.055000519817226347) /
            1.0550005198172263;
          rtb_Add = rt_pow_snf(rtb_Add, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o2_o <= 0.039286085583733095) {
          rtb_TSamp = brain_B.ColorSpaceConversion_o2_o / 12.923054468333255;
        } else {
          rtb_TSamp = (brain_B.ColorSpaceConversion_o2_o + 0.055000519817226347)
            / 1.0550005198172263;
          rtb_TSamp = rt_pow_snf(rtb_TSamp, 2.4);
        }

        if (brain_B.ColorSpaceConversion_o3_c <= 0.039286085583733095) {
          Index = brain_B.ColorSpaceConversion_o3_c / 12.923054468333255;
        } else {
          Index = (brain_B.ColorSpaceConversion_o3_c + 0.055000519817226347) /
            1.0550005198172263;
          Index = rt_pow_snf(Index, 2.4);
        }

        /* The coefficients for this conversion were derived from ITU-R */
        /* BT.709 reference primaries for sRGB and CIE standard illuminant */
        /* D65, 2 degree observer */
        count_0 = (0.41239079926596 * rtb_Add + 0.35758433938388 * rtb_TSamp) +
          0.18048078840183 * Index;
        cc = (0.21263900587151 * rtb_Add + 0.71516867876776 * rtb_TSamp) +
          0.07219231536073 * Index;
        count = (0.01933081871559 * rtb_Add + 0.11919477979463 * rtb_TSamp) +
          0.95053215224966 * Index;

        /* Make sure that the output is in [0..1] range; clip if necessary */
        if (count_0 > 1.0) {
          count_0 = 1.0;
        } else {
          if (count_0 < 0.0) {
            count_0 = 0.0;
          }
        }

        if (cc > 1.0) {
          cc = 1.0;
        } else {
          if (cc < 0.0) {
            cc = 0.0;
          }
        }

        if (count > 1.0) {
          count = 1.0;
        } else {
          if (count < 0.0) {
            count = 0.0;
          }
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1_n = count_0;
        brain_B.ColorSpaceConversion1_o2_i = cc;
        brain_B.ColorSpaceConversion1_o3_m = count;

        /* Convert from XYZ to L*a*b* */
        rtb_Add = brain_B.ColorSpaceConversion1_o1_n / 0.9641986557609;
        Index = brain_B.ColorSpaceConversion1_o3_m / 0.82511648322104;

        /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
        if (rtb_Add > 0.0088564516790356311) {
          min_dist = rt_pow_snf(rtb_Add, 0.33333333333333331);
        } else {
          min_dist = 7.7870370370370372 * rtb_Add + 0.13793103448275862;
        }

        if (brain_B.ColorSpaceConversion1_o2_i > 0.0088564516790356311) {
          rtb_TSamp = rt_pow_snf(brain_B.ColorSpaceConversion1_o2_i,
            0.33333333333333331);
        } else {
          rtb_TSamp = 7.7870370370370372 * brain_B.ColorSpaceConversion1_o2_i +
            0.13793103448275862;
        }

        if (Index > 0.0088564516790356311) {
          rtb_Add = rt_pow_snf(Index, 0.33333333333333331);
        } else {
          rtb_Add = 7.7870370370370372 * Index + 0.13793103448275862;
        }

        /* assign the results */
        brain_B.ColorSpaceConversion1_o1_n = 116.0 * rtb_TSamp - 16.0;
        brain_B.ColorSpaceConversion1_o2_i = (min_dist - rtb_TSamp) * 500.0;
        brain_B.ColorSpaceConversion1_o3_m = (rtb_TSamp - rtb_Add) * 200.0;

        /* Embedded MATLAB: '<S9>/GetBestColorMatch' */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch': '<S44>:1' */
        /*  This function determines which buoys are the best match for the desired colors */
        /*  Buoys = zeros(3,3); */
        /*  Buoys = [L;M;R]; */
        /* '<S44>:1:6' */
        rtb_TSamp = 1000.0;

        /* '<S44>:1:7' */
        min_dist = 1000.0;

        /* '<S44>:1:8' */
        /* '<S44>:1:9' */
        for (i = 0; i < 50; i++) {
          FirstD[i] = 2.0;
          SecondD[i] = 2.0;
        }

        /* '<S44>:1:11' */
        count = 0.0;

        /* '<S44>:1:12' */
        count_0 = 0.0;

        /* '<S44>:1:14' */
        for (Index = 1.0; Index <= brain_B.num_blobs; Index++) {
          /* '<S44>:1:14' */
          /* '<S44>:1:15' */
          rtb_Add = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)Index - 1] -
            brain_B.ColorSpaceConversion1_o1, 2.0) + rt_pow_snf(brain_B.buoys
            [(int32_T)Index + 49] - brain_B.ColorSpaceConversion1_o2, 2.0)) +
                         rt_pow_snf(brain_B.buoys[(int32_T)Index + 99] -
            brain_B.ColorSpaceConversion1_o3, 2.0));
          if (rtb_Add <= rtb_TSamp) {
            /* '<S44>:1:16' */
            /* '<S44>:1:17' */
            count++;

            /* '<S44>:1:18' */
            rtb_TSamp = rtb_Add;

            /* '<S44>:1:19' */
            FirstD[(int32_T)count - 1] = Index;
          }

          /* '<S44>:1:21' */
          rtb_Add = sqrt((rt_pow_snf(brain_B.buoys[(int32_T)Index - 1] -
            brain_B.ColorSpaceConversion1_o1_n, 2.0) + rt_pow_snf(brain_B.buoys
                           [(int32_T)Index + 49] -
            brain_B.ColorSpaceConversion1_o2_i, 2.0)) + rt_pow_snf
                         (brain_B.buoys[(int32_T)Index + 99] -
                          brain_B.ColorSpaceConversion1_o3_m, 2.0));
          if (rtb_Add < min_dist) {
            /* '<S44>:1:22' */
            /* '<S44>:1:23' */
            count_0++;

            /* '<S44>:1:24' */
            min_dist = rtb_Add;

            /* '<S44>:1:25' */
            SecondD[(int32_T)count_0 - 1] = Index;
          }
        }

        /* '<S44>:1:29' */
        Index = 2.0;

        /* '<S44>:1:30' */
        /* '<S44>:1:31' */
        for (rtb_Add = 1.0; rtb_Add <= count; rtb_Add++) {
          /* '<S44>:1:31' */
          /* '<S44>:1:32' */
          if (brain_B.buoys[(int32_T)FirstD[(int32_T)rtb_Add - 1] + 149] > 0.0)
          {
            /* '<S44>:1:33' */
            /* '<S44>:1:34' */
            Index = FirstD[(int32_T)rtb_Add - 1];
          }
        }

        /* '<S44>:1:39' */
        rtb_Add = 2.0;

        /* '<S44>:1:40' */
        /* '<S44>:1:41' */
        for (rtb_TSamp = 1.0; rtb_TSamp <= count_0; rtb_TSamp++) {
          /* '<S44>:1:41' */
          /* '<S44>:1:42' */
          if (brain_B.buoys[(int32_T)SecondD[(int32_T)rtb_TSamp - 1] + 149] >
              0.0) {
            /* '<S44>:1:43' */
            /* '<S44>:1:44' */
            rtb_Add = SecondD[(int32_T)rtb_TSamp - 1];
          }
        }

        if (Index > rtb_Add) {
          /* '<S44>:1:49' */
          /* '<S44>:1:50' */
          brain_B.Direction1 = 1.0;

          /* '<S44>:1:51' */
          brain_B.Direction2 = 3.0;
        } else if (Index == rtb_Add) {
          /* '<S44>:1:52' */
          /* '<S44>:1:53' */
          brain_B.Direction1 = 2.0;

          /* '<S44>:1:54' */
          brain_B.Direction2 = 2.0;
        } else {
          /* '<S44>:1:56' */
          brain_B.Direction1 = 3.0;

          /* '<S44>:1:57' */
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
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
        memcpy((void *)(&brain_B.LabMatrix_o[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_j[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_o,
          brain_B.Ref_Colors_j, &brain_B.StateFlowFunctionsBuoysShowSe_o);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0]), 57600U *
               sizeof(real_T));

        /* Simulink Function 'LookforBuoys': '<S7>:1491' */
        memcpy((void *)(&brain_B.LabMatrix_k[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        brain_B.num_colors = brain_DWork.num_colors;
        memcpy((void *)(&brain_B.RGBin[0]), (void *)(&brain_B.RGBout[0]), 57600U
               * sizeof(real_T));
        StateFlowFunctionsBuoysFindBuoy(brain_B.RGBin, brain_B.LabMatrix_k,
          brain_B.num_colors, &brain_B.StateFlowFunctionsBuoysFindB_ln,
          &brain_DWork.StateFlowFunctionsBuoysFindB_ln);
        brain_DWork.Obstacle = (brain_B.StateFlowFunctionsBuoysFindB_ln.Image !=
          0.0);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsBuoysFindB_ln.DrawMarkers[0]), 57600U
               * sizeof(real_T));
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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        count_0 = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp -
                    brain_DWork.UD_DSTATE)) +
          brain_DWork.DepthDiscreteTimeIntegrator_DST;
        count_0 = floor(count_0);
        if (count_0 < 128.0) {
          if (count_0 >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)count_0;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
      brain_enter_internal_Buoys();
      break;
    }
  }
}

/* Function for Embedded MATLAB: '<S81>/IsLinePresent' */
static void brain_max_o(const real_T varargin_1[71820], real_T maxval[180],
  real_T indx[180])
{
  int16_T b_indx[180];
  int32_T ix;
  int32_T iy;
  real_T mtmp;
  int32_T itmp;
  int32_T b_ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  int32_T i;
  for (i = 0; i < 180; i++) {
    b_indx[i] = 1;
  }

  ix = 0;
  iy = 0;
  for (i = 0; i < 180; i++) {
    ix++;
    mtmp = varargin_1[ix - 1];
    itmp = 1;
    b_ix = ix;
    guard = FALSE;
    if (rtIsNaN(varargin_1[ix - 1])) {
      searchingForNonNaN = TRUE;
      k = 2;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (k < 400)) {
        b_ix++;
        if (!rtIsNaN(varargin_1[b_ix - 1])) {
          mtmp = varargin_1[b_ix - 1];
          itmp = k;
          searchingForNonNaN = FALSE;
          exitg = TRUE;
        } else {
          k++;
        }
      }

      if (!searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (k = itmp + 1; k < 400; k++) {
        b_ix++;
        if (varargin_1[b_ix - 1] > mtmp) {
          mtmp = varargin_1[b_ix - 1];
          itmp = k;
        }
      }
    }

    iy++;
    maxval[iy - 1] = mtmp;
    b_indx[iy - 1] = (int16_T)itmp;
    ix += 398;
  }

  for (i = 0; i < 180; i++) {
    indx[i] = (real_T)b_indx[i];
  }
}

/* Function for Embedded MATLAB: '<S81>/IsLinePresent' */
static void brain_max_oh(const real_T varargin_1[180], real_T *maxval, real_T
  *indx)
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (k < 181)) {
      ix++;
      if (!rtIsNaN(varargin_1[ix - 1])) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
        searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        k++;
      }
    }

    if (!searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (k = itmp + 1; k < 181; k++) {
      ix++;
      if (varargin_1[ix - 1] > mtmp) {
        mtmp = varargin_1[ix - 1];
        itmp = k;
      }
    }
  }

  *maxval = mtmp;
  *indx = (real_T)itmp;
}

/* Function for Embedded MATLAB: '<S81>/IsLinePresent' */
static void brain_refp1_round(real_T *x)
{
  if (*x < 0.0) {
    *x = ceil(*x - 0.5);
  } else {
    *x = floor(*x + 0.5);
  }
}

/* Function for Embedded MATLAB: '<S21>/GetHeadingToPath' */
static void brain_max_h(const real_T varargin_1[2], real_T *maxval, real_T *indx)
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    ix = 2;
    if (!rtIsNaN(varargin_1[1])) {
      mtmp = varargin_1[1];
      itmp = 2;
      searchingForNonNaN = FALSE;
    }

    if (!searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (k = itmp + 1; k < 3; k = 3) {
      ix++;
      if (varargin_1[ix - 1] > mtmp) {
        mtmp = varargin_1[ix - 1];
        itmp = 2;
      }
    }
  }

  *maxval = mtmp;
  *indx = (real_T)itmp;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_OnePath(void)
{
  int32_T idxROI;
  int32_T idxStart;
  boolean_T isInBound;
  boolean_T visited;
  boolean_T visited_0;
  boolean_T done;
  real_T index_moment;
  real_T sum_maxValues;
  real_T maxValues[180];
  real_T RhoIndices[180];
  int32_T ky;
  int32_T ku;
  int32_T idxAdj;
  int32_T n;
  int32_T startC;
  int32_T inIdx;
  int32_T outIdx;
  real_T rtb_Theta[2];
  real_T rtb_maxVotes[2];
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  real_T ThetaIndex_idx;
  real_T RhoIndex_idx;
  real_T ThetaIndex_idx_0;
  real_T RhoIndex_idx_0;
  real_T rtb_Rho_idx;
  real_T rtb_Rho_idx_0;

  /* During 'OnePath': '<S7>:1549' */
  switch (brain_DWork.is_OnePath) {
   case brain_IN_AlignWithPath:
    /* During 'AlignWithPath': '<S7>:1559' */
    if (fabs(brain_DWork.HeadingAlongPath) <= 4.0) {
      /* Transition: '<S7>:1551' */
      /* Exit 'AlignWithPath': '<S7>:1559' */
      /* Entry 'Done': '<S7>:1553' */
      brain_DWork.is_OnePath = brain_IN_Done;
      brain_B.SubState = 4.0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;
      brain_B.DesiredHeading = brain_U.CurrentHeading +
        brain_DWork.HeadingAlongPath;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'HSVSegmentation': '<S7>:1568' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_h[i] = brain_B.Resize[i];
        brain_B.S_c[i] = brain_B.Resize1[i];

        /* Logic: '<S99>/Logical Operator1' incorporates:
         *  Constant: '<S100>/Constant'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S102>/Constant'
         *  Logic: '<S99>/Logical Operator'
         *  RelationalOperator: '<S100>/Compare'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S102>/Compare'
         */
        brain_B.BW_m[i] = (((brain_B.H_h[i] < brain_P.Track_HueLower) ||
                            (brain_B.H_h[i] > brain_P.Track_HueHigher)) &&
                           (brain_B.S_c[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipmorphop): '<S99>/Erosion' */
      ky = 0;
      ku = 0;
      for (startC = 0; startC < 127; startC++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
      }

      for (i = 0; i < 160; i++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
        memcpy((void *)(&brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky]), (void *)
               (&brain_B.BW_m[ku]), 120U * sizeof(boolean_T));
        ky += 120;
        ku += 120;
        for (startC = 121; startC < 127; startC++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 161; i < 167; i++) {
        for (startC = 0; startC < 127; startC++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 0; i < 21209; i++) {
        brain_DWork.Erosion_TWO_PAD_IMG_DW_h[i] = TRUE;
      }

      ku = 0;
      for (n = 0; n < 167; n++) {
        for (startC = 0; startC < 124; startC++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = TRUE;
          for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_f[0]; i++) {
            if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ku +
                brain_DWork.Erosion_ERODE_OFF_DW_l[i]]) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = FALSE;
              i = brain_DWork.Erosion_NUMNONZ_DW_f[0];
            }
          }

          ku++;
        }

        ku += 3;
      }

      inIdx = 1;
      outIdx = 0;
      for (n = 0; n < 160; n++) {
        for (startC = 1; startC < 121; startC++) {
          brain_B.Erosion_m[outIdx] = TRUE;
          for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_f[1]; i++) {
            if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_h[brain_DWork.Erosion_ERODE_OFF_DW_l
                [i + brain_DWork.Erosion_NUMNONZ_DW_f[0]] + inIdx]) {
              brain_B.Erosion_m[outIdx] = FALSE;
              i = brain_DWork.Erosion_NUMNONZ_DW_f[1];
            }
          }

          inIdx++;
          outIdx++;
        }

        inIdx += 7;
      }

      /* Simulink Function 'GetHeadings': '<S7>:1565' */
      for (i = 0; i < 19200; i++) {
        /* DataTypeConversion: '<S99>/Data Type Conversion' */
        brain_B.DataTypeConversion[i] = brain_B.Erosion_m[i];
        brain_B.BWout[i] = (real_T)brain_B.DataTypeConversion[i];
        brain_B.BW[i] = brain_B.BWout[i];
      }

      /* S-Function (svipscalenconvert): '<S21>/Image Data Type Conversion' */
      for (i = 0; i < 19200; i++) {
        brain_B.ImageDataTypeConversion_p[i] = ((brain_B.BW[i] == 0.0 ? 0 : 1)
          != 0);
      }

      /* S-Function (sviphough): '<S81>/Hough Transform' */
      MWVIP_Hough_D(&brain_B.ImageDataTypeConversion_p[0],
                    &brain_B.HoughTransform_o1_n[0], &brain_ConstP.pooled18[0],
                    &brain_ConstP.pooled19, 120, 160, 399, 91);

      /* Embedded MATLAB: '<S81>/IsLinePresent' */
      memcpy((void *)(&brain_B.HoughTable[0]), (void *)
             (&brain_B.HoughTransform_o1_n[0]), 71820U * sizeof(real_T));

      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff/IsLinePresent': '<S82>:1' */
      /*  This function takes a Hough/hash table as input and  determines if a line */
      /*  is present and if so what its Rho and Theta are. */
      /* '<S82>:1:5' */
      /* '<S82>:1:7' */
      /* '<S82>:1:9' */
      /* '<S82>:1:10' */
      /* '<S82>:1:11' */
      /* '<S82>:1:12' */
      /* '<S82>:1:13' */
      rtb_Rho_idx = -999.0;
      rtb_Theta[0] = -999.0;
      rtb_maxVotes[0] = -999.0;
      rtb_Rho_idx_0 = -999.0;
      rtb_Theta[1] = -999.0;
      rtb_maxVotes[1] = -999.0;
      ThetaIndex_idx_0 = -999.0;
      RhoIndex_idx_0 = -999.0;

      /* '<S82>:1:17' */
      memcpy((void *)(&brain_B.dv0[0]), (void *)(&brain_B.HoughTransform_o1_n[0]),
             71820U * sizeof(real_T));
      brain_max_o(&brain_B.dv0[0], maxValues, RhoIndices);
      brain_max_oh(maxValues, &index_moment, &sum_maxValues);

      /* '<S82>:1:20' */
      rtb_maxVotes[0] = index_moment;

      /* '<S82>:1:20' */
      /* '<S82>:1:21' */
      index_moment = 0.0;

      /* '<S82>:1:22' */
      sum_maxValues = 0.0;

      /* '<S82>:1:23' */
      for (i = 0; i < 180; i++) {
        /* '<S82>:1:23' */
        if (rtb_maxVotes[0] - maxValues[i] < 0.15 * rtb_maxVotes[0]) {
          /* '<S82>:1:24' */
          /* '<S82>:1:25' */
          index_moment += ((real_T)i + 1.0) * maxValues[i];

          /* '<S82>:1:26' */
          sum_maxValues += maxValues[i];
        }
      }

      if (sum_maxValues > 0.0) {
        /* '<S82>:1:29' */
        /* '<S82>:1:30' */
        index_moment /= sum_maxValues;
        brain_refp1_round(&index_moment);
      } else {
        /* '<S82>:1:32' */
        index_moment = 1.0;
      }

      /* '<S82>:1:35' */
      ThetaIndex_idx = index_moment;

      /* '<S82>:1:36' */
      rtb_maxVotes[0] = maxValues[(int32_T)index_moment - 1];

      /* '<S82>:1:38' */
      RhoIndex_idx = RhoIndices[(int32_T)index_moment - 1];
      if (rtb_maxVotes[0] >= 15.0) {
        /* '<S82>:1:40' */
        /* '<S82>:1:41' */
        brain_B.HoughTable[((int32_T)RhoIndices[(int32_T)index_moment - 1] - 1)
          + 399 * ((int32_T)index_moment - 1)] = 0.0;

        /* '<S82>:1:43' */
        ky = 2;

        /* '<S82>:1:44' */
        inIdx = 0;
        while ((ky <= 2) && (inIdx < 12)) {
          /* '<S82>:1:45' */
          /* '<S82>:1:46' */
          inIdx++;
          brain_max_o(&brain_B.HoughTable[0], maxValues, RhoIndices);
          brain_max_oh(maxValues, &index_moment, &sum_maxValues);

          /* '<S82>:1:48' */
          rtb_maxVotes[1] = index_moment;

          /* '<S82>:1:48' */
          ThetaIndex_idx_0 = sum_maxValues;

          /* '<S82>:1:49' */
          RhoIndex_idx_0 = RhoIndices[(int32_T)sum_maxValues - 1];

          /* '<S82>:1:51' */
          brain_B.HoughTable[((int32_T)RhoIndices[(int32_T)sum_maxValues - 1] -
                              1) + 399 * ((int32_T)sum_maxValues - 1)] = 0.0;
          if ((fabs(RhoIndices[(int32_T)sum_maxValues - 1] - RhoIndex_idx) >
               20.0) || (fabs(sum_maxValues - ThetaIndex_idx) > 30.0)) {
            /* '<S82>:1:53' */
            /* '<S82>:1:54' */
            ky = 3;
          }
        }

        /* '<S82>:1:59' */
        if (rtb_maxVotes[0] > 15.0) {
          /* '<S82>:1:60' */
          /* '<S82>:1:61' */
          rtb_Theta[0] = brain_B.HoughTransform_o2_e[(int32_T)ThetaIndex_idx - 1];

          /* '<S82>:1:62' */
          rtb_Rho_idx = brain_B.HoughTransform_o3_n[(int32_T)RhoIndex_idx - 1];
          if ((rtb_Theta[0] > 0.0) && (brain_B.HoughTransform_o3_n[(int32_T)
               RhoIndex_idx - 1] < 0.0)) {
            /* '<S82>:1:63' */
            /* '<S82>:1:64' */
            rtb_Rho_idx = brain_B.HoughTransform_o3_n[(int32_T)RhoIndex_idx - 1]
              * -1.0;
          }
        }

        /* '<S82>:1:59' */
        if (rtb_maxVotes[1] > 15.0) {
          /* '<S82>:1:60' */
          /* '<S82>:1:61' */
          rtb_Theta[1] = brain_B.HoughTransform_o2_e[(int32_T)ThetaIndex_idx_0 -
            1];

          /* '<S82>:1:62' */
          rtb_Rho_idx_0 = brain_B.HoughTransform_o3_n[(int32_T)RhoIndex_idx_0 -
            1];
          if ((rtb_Theta[1] > 0.0) && (brain_B.HoughTransform_o3_n[(int32_T)
               RhoIndex_idx_0 - 1] < 0.0)) {
            /* '<S82>:1:63' */
            /* '<S82>:1:64' */
            rtb_Rho_idx_0 = brain_B.HoughTransform_o3_n[(int32_T)RhoIndex_idx_0
              - 1] * -1.0;
          }
        }
      }

      /* S-Function (sviphoughlines): '<S21>/Hough Lines' */
      inIdx = 0;
      index_moment = (rtb_Rho_idx + 2.2204460492503131E-16) / (cos(rtb_Theta[0])
        + 2.2204460492503131E-16);

      /* part-1: top horizontal axis */
      sum_maxValues = floor(index_moment + 0.5);
      if ((sum_maxValues >= 0.0) && (sum_maxValues <= 159.0)) {
        brain_B.HoughLines_a[0] = 0;
        brain_B.HoughLines_a[1] = (int32_T)floor((real_T)(int32_T)sum_maxValues
          + 0.5);
        inIdx = 1;
      }

      RhoIndex_idx_0 = (rtb_Rho_idx + 2.2204460492503131E-16) / (sin(rtb_Theta[0])
        + 2.2204460492503131E-16);

      /* part-2: left vertical axis */
      sum_maxValues = floor(RhoIndex_idx_0 + 0.5);
      if ((sum_maxValues >= 0.0) && (sum_maxValues <= 119.0)) {
        brain_B.HoughLines_a[(inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
          sum_maxValues + 0.5);
        brain_B.HoughLines_a[1 + (inIdx << 1)] = 0;
        inIdx++;
      }

      /* part-3: Right vertical axis */
      if (inIdx < 2) {
        sum_maxValues = floor((index_moment - 159.0) * (RhoIndex_idx_0 /
          index_moment) + 0.5);
        if ((sum_maxValues >= 0.0) && (sum_maxValues <= 119.0)) {
          brain_B.HoughLines_a[(inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
            sum_maxValues + 0.5);
          brain_B.HoughLines_a[1 + (inIdx << 1)] = 159;
          inIdx++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (inIdx < 2) {
        sum_maxValues = floor((index_moment - index_moment / RhoIndex_idx_0 *
          119.0) + 0.5);
        if ((sum_maxValues >= 0.0) && (sum_maxValues <= 159.0)) {
          brain_B.HoughLines_a[(inIdx << 1)] = 119;
          brain_B.HoughLines_a[1 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)sum_maxValues + 0.5);
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
      index_moment = (rtb_Rho_idx_0 + 2.2204460492503131E-16) / (cos(rtb_Theta[1])
        + 2.2204460492503131E-16);

      /* part-1: top horizontal axis */
      sum_maxValues = floor(index_moment + 0.5);
      if ((sum_maxValues >= 0.0) && (sum_maxValues <= 159.0)) {
        brain_B.HoughLines_a[4] = 0;
        brain_B.HoughLines_a[5] = (int32_T)floor((real_T)(int32_T)sum_maxValues
          + 0.5);
        inIdx = 1;
      }

      RhoIndex_idx_0 = (rtb_Rho_idx_0 + 2.2204460492503131E-16) / (sin
        (rtb_Theta[1]) + 2.2204460492503131E-16);

      /* part-2: left vertical axis */
      sum_maxValues = floor(RhoIndex_idx_0 + 0.5);
      if ((sum_maxValues >= 0.0) && (sum_maxValues <= 119.0)) {
        brain_B.HoughLines_a[4 + (inIdx << 1)] = (int32_T)floor((real_T)(int32_T)
          sum_maxValues + 0.5);
        brain_B.HoughLines_a[5 + (inIdx << 1)] = 0;
        inIdx++;
      }

      /* part-3: Right vertical axis */
      if (inIdx < 2) {
        sum_maxValues = floor((index_moment - 159.0) * (RhoIndex_idx_0 /
          index_moment) + 0.5);
        if ((sum_maxValues >= 0.0) && (sum_maxValues <= 119.0)) {
          brain_B.HoughLines_a[4 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)sum_maxValues + 0.5);
          brain_B.HoughLines_a[5 + (inIdx << 1)] = 159;
          inIdx++;
        }
      }

      /* part-4: bottom horizontal axis */
      if (inIdx < 2) {
        sum_maxValues = floor((index_moment - index_moment / RhoIndex_idx_0 *
          119.0) + 0.5);
        if ((sum_maxValues >= 0.0) && (sum_maxValues <= 159.0)) {
          brain_B.HoughLines_a[4 + (inIdx << 1)] = 119;
          brain_B.HoughLines_a[5 + (inIdx << 1)] = (int32_T)floor((real_T)
            (int32_T)sum_maxValues + 0.5);
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
      memcpy((void *)(&brain_B.DrawShapes_m[0]), (void *)(&brain_B.BW[0]),
             19200U * sizeof(real_T));
      idxStart = 0;
      for (idxROI = 0; idxROI < 2; idxROI++) {
        for (startC = 0; startC < 1; startC = 1) {
          inIdx = brain_B.HoughLines_a[idxStart];
          i = brain_B.HoughLines_a[idxStart + 1];
          line_idx_2 = brain_B.HoughLines_a[idxStart + 2];
          line_idx_3 = brain_B.HoughLines_a[idxStart + 3];
          if ((brain_B.HoughLines_a[idxStart + 2] !=
               brain_B.HoughLines_a[idxStart]) || (brain_B.HoughLines_a[idxStart
               + 1] != brain_B.HoughLines_a[idxStart + 3])) {
            isInBound = FALSE;

            /* Find the visible portion of a line. */
            visited = FALSE;
            visited_0 = FALSE;
            done = FALSE;
            idxAdj = brain_B.HoughLines_a[idxStart];
            line_idx = brain_B.HoughLines_a[idxStart + 1];
            line_idx_1 = brain_B.HoughLines_a[idxStart + 2];
            line_idx_0 = brain_B.HoughLines_a[idxStart + 3];
            while (!done) {
              n = 0;
              outIdx = 0;

              /* Determine viewport violations. */
              if (idxAdj < 0) {
                n = 4;
              } else {
                if (idxAdj > 119) {
                  n = 8;
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
                n = (int32_T)((uint32_T)n | 1U);
              } else {
                if (line_idx > 159) {
                  n = (int32_T)((uint32_T)n | 2U);
                }
              }

              if (line_idx_0 < 0) {
                outIdx = (int32_T)((uint32_T)outIdx | 1U);
              } else {
                if (line_idx_0 > 159) {
                  outIdx = (int32_T)((uint32_T)outIdx | 2U);
                }
              }

              if (!((uint32_T)n | (uint32_T)outIdx)) {
                /* Line falls completely within bounds. */
                done = TRUE;
                isInBound = TRUE;
              } else if ((uint32_T)n & (uint32_T)outIdx) {
                /* Line falls completely out of bounds. */
                done = TRUE;
                isInBound = FALSE;
              } else if ((uint32_T)n != 0U) {
                /* Clip 1st point; if it's in-bounds, clip 2nd point. */
                if (visited) {
                  idxAdj = inIdx;
                  line_idx = i;
                }

                ky = line_idx_1 - idxAdj;
                ku = line_idx_0 - line_idx;
                if ((uint32_T)n & 4U) {
                  /* Violated RMin. */
                  startC = (0 - idxAdj) * ku;
                  if (((startC >= 0) && (ky >= 0)) || ((startC < 0) && (ky < 0)))
                  {
                    line_idx += (div_s32_floor(startC << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx += -((div_s32_floor((-startC) << 1U, ky) + 1) >> 1);
                  }

                  idxAdj = 0;
                  visited = TRUE;
                } else if ((uint32_T)n & 8U) {
                  /* Violated RMax. */
                  startC = (119 - idxAdj) * ku;
                  if (((startC >= 0) && (ky >= 0)) || ((startC < 0) && (ky < 0)))
                  {
                    line_idx += (div_s32_floor(startC << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx += -((div_s32_floor((-startC) << 1U, ky) + 1) >> 1);
                  }

                  idxAdj = 119;
                  visited = TRUE;
                } else if ((uint32_T)n & 1U) {
                  /* Violated CMin. */
                  startC = (0 - line_idx) * ky;
                  if (((startC >= 0) && (ku >= 0)) || ((startC < 0) && (ku < 0)))
                  {
                    idxAdj += (div_s32_floor(startC << 1U, ku) + 1) >> 1;
                  } else {
                    idxAdj += -((div_s32_floor((-startC) << 1U, ku) + 1) >> 1);
                  }

                  line_idx = 0;
                  visited = TRUE;
                } else {
                  /* Violated CMax. */
                  startC = (159 - line_idx) * ky;
                  if (((startC >= 0) && (ku >= 0)) || ((startC < 0) && (ku < 0)))
                  {
                    idxAdj += (div_s32_floor(startC << 1U, ku) + 1) >> 1;
                  } else {
                    idxAdj += -((div_s32_floor((-startC) << 1U, ku) + 1) >> 1);
                  }

                  line_idx = 159;
                  visited = TRUE;
                }
              } else {
                /* Clip the 2nd point. */
                if (visited_0) {
                  line_idx_1 = line_idx_2;
                  line_idx_0 = line_idx_3;
                }

                ky = line_idx_1 - idxAdj;
                ku = line_idx_0 - line_idx;
                if ((uint32_T)outIdx & 4U) {
                  /* Violated RMin. */
                  startC = (0 - line_idx_1) * ku;
                  if (((startC >= 0) && (ky >= 0)) || ((startC < 0) && (ky < 0)))
                  {
                    line_idx_0 += (div_s32_floor(startC << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-startC) << 1U, ky) + 1) >>
                                    1);
                  }

                  line_idx_1 = 0;
                  visited_0 = TRUE;
                } else if ((uint32_T)outIdx & 8U) {
                  /* Violated RMax. */
                  startC = (119 - line_idx_1) * ku;
                  if (((startC >= 0) && (ky >= 0)) || ((startC < 0) && (ky < 0)))
                  {
                    line_idx_0 += (div_s32_floor(startC << 1U, ky) + 1) >> 1;
                  } else {
                    line_idx_0 += -((div_s32_floor((-startC) << 1U, ky) + 1) >>
                                    1);
                  }

                  line_idx_1 = 119;
                  visited_0 = TRUE;
                } else if ((uint32_T)outIdx & 1U) {
                  /* Violated CMin. */
                  startC = (0 - line_idx_0) * ky;
                  if (((startC >= 0) && (ku >= 0)) || ((startC < 0) && (ku < 0)))
                  {
                    line_idx_1 += (div_s32_floor(startC << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_1 += -((div_s32_floor((-startC) << 1U, ku) + 1) >>
                                    1);
                  }

                  line_idx_0 = 0;
                  visited_0 = TRUE;
                } else {
                  /* Violated CMax. */
                  startC = (159 - line_idx_0) * ky;
                  if (((startC >= 0) && (ku >= 0)) || ((startC < 0) && (ku < 0)))
                  {
                    line_idx_1 += (div_s32_floor(startC << 1U, ku) + 1) >> 1;
                  } else {
                    line_idx_1 += -((div_s32_floor((-startC) << 1U, ku) + 1) >>
                                    1);
                  }

                  line_idx_0 = 159;
                  visited_0 = TRUE;
                }
              }
            }

            if (isInBound) {
              /* Draw a line using Bresenham algorithm. */
              /* Initialize the Bresenham algorithm. */
              if (line_idx_1 >= idxAdj) {
                ky = line_idx_1 - idxAdj;
              } else {
                ky = idxAdj - line_idx_1;
              }

              if (line_idx_0 >= line_idx) {
                ku = line_idx_0 - line_idx;
              } else {
                ku = line_idx - line_idx_0;
              }

              if (ky > ku) {
                i = 1;
                ku = 120;
              } else {
                i = 120;
                ku = 1;
                ky = idxAdj;
                idxAdj = line_idx;
                line_idx = ky;
                ky = line_idx_1;
                line_idx_1 = line_idx_0;
                line_idx_0 = ky;
              }

              if (idxAdj > line_idx_1) {
                ky = idxAdj;
                idxAdj = line_idx_1;
                line_idx_1 = ky;
                ky = line_idx;
                line_idx = line_idx_0;
                line_idx_0 = ky;
              }

              inIdx = line_idx_1 - idxAdj;
              if (line_idx <= line_idx_0) {
                ky = 1;
                outIdx = line_idx_0 - line_idx;
              } else {
                ky = -1;
                outIdx = line_idx - line_idx_0;
              }

              n = -((inIdx + 1) >> 1);
              startC = idxAdj * i + line_idx * ku;
              ky = ky * ku + i;
              for (isInBound = (idxAdj <= line_idx_1); isInBound; isInBound =
                   (idxAdj <= line_idx_1)) {
                brain_B.DrawShapes_m[startC] = 0.75;

                /* Compute the next location using Bresenham algorithm. */
                /* Move to the next pixel location. */
                n += outIdx;
                if (n >= 0) {
                  n -= inIdx;
                  startC += ky;
                } else {
                  startC += i;
                }

                idxAdj++;
              }
            }
          }

          idxStart += 2;
        }

        idxStart += 2;
      }

      /* Embedded MATLAB: '<S21>/GetHeadingToPath' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/GetHeadingToPath': '<S80>:1' */
      /*  This function calculates the heading to the path from Theta and Rho */
      /* '<S80>:1:4' */
      /* '<S80>:1:6' */
      brain_B.AlongPathHeading = -999.0;
      brain_max_h(rtb_maxVotes, &index_moment, &sum_maxValues);

      /* '<S80>:1:10' */
      /* '<S80>:1:11' */
      /* '<S80>:1:12' */
      if ((rtb_Theta[(int32_T)sum_maxValues - 1] > -1.5707963267948966) &&
          (rtb_Theta[(int32_T)sum_maxValues - 1] < 1.5707963267948966)) {
        /* '<S80>:1:21' */
        /* '<S80>:1:22' */
        brain_B.AlongPathHeading = rtb_Theta[(int32_T)sum_maxValues - 1] * 180.0
          / 3.1415926535897931;
      }

      brain_DWork.HeadingAlongPath = brain_B.AlongPathHeading;

      /* Simulink Function 'CamDown_CenterOver_Yaw': '<S7>:1841' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = brain_B.DrawShapes_m[i];
        brain_B.BW_i[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsFollowOnePa_e(brain_B.BW_i, brain_M,
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

      /* Sum: '<S38>/Add' */
      index_moment = (real_T)brain_B.DesiredDepth1 - (real_T)
        brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S137>/TSamp' incorporates:
       *  Gain: '<S136>/Depth Derivative Gain'
       *
       * About '<S137>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      sum_maxValues = brain_P.Depth_Kd * index_moment / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
       *  Gain: '<S136>/Depth Proportional Gain'
       *  Sum: '<S136>/Sum'
       *  Sum: '<S137>/Diff'
       *  UnitDelay: '<S137>/UD'
       *
       * Block description for '<S137>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S137>/UD':
       *
       *  Store in Global RAM
       */
      rtb_Rho_idx = (brain_P.Depth_Kp * index_moment + (sum_maxValues -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      rtb_Rho_idx = floor(rtb_Rho_idx);
      if (rtb_Rho_idx < 128.0) {
        if (rtb_Rho_idx >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)rtb_Rho_idx;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S137>/UD'
       * Block description for '<S137>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = sum_maxValues;

      /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S136>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        index_moment) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
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
      brain_B.SubState = 3.0;
      brain_DWork.HeadingAlongPath = 10.0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;
    } else {
      /* Simulink Function 'HSVSegmentation': '<S7>:1568' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_h[i] = brain_B.Resize[i];
        brain_B.S_c[i] = brain_B.Resize1[i];

        /* Logic: '<S99>/Logical Operator1' incorporates:
         *  Constant: '<S100>/Constant'
         *  Constant: '<S101>/Constant'
         *  Constant: '<S102>/Constant'
         *  Logic: '<S99>/Logical Operator'
         *  RelationalOperator: '<S100>/Compare'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S102>/Compare'
         */
        brain_B.BW_m[i] = (((brain_B.H_h[i] < brain_P.Track_HueLower) ||
                            (brain_B.H_h[i] > brain_P.Track_HueHigher)) &&
                           (brain_B.S_c[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipmorphop): '<S99>/Erosion' */
      ky = 0;
      ku = 0;
      for (startC = 0; startC < 127; startC++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
      }

      for (i = 0; i < 160; i++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
        ky++;
        memcpy((void *)(&brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky]), (void *)
               (&brain_B.BW_m[ku]), 120U * sizeof(boolean_T));
        ky += 120;
        ku += 120;
        for (startC = 121; startC < 127; startC++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 161; i < 167; i++) {
        for (startC = 0; startC < 127; startC++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ky] = TRUE;
          ky++;
        }
      }

      for (i = 0; i < 21209; i++) {
        brain_DWork.Erosion_TWO_PAD_IMG_DW_h[i] = TRUE;
      }

      ku = 0;
      for (n = 0; n < 167; n++) {
        for (startC = 0; startC < 124; startC++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = TRUE;
          for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_f[0]; i++) {
            if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_k[ku +
                brain_DWork.Erosion_ERODE_OFF_DW_l[i]]) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW_h[1 + ku] = FALSE;
              i = brain_DWork.Erosion_NUMNONZ_DW_f[0];
            }
          }

          ku++;
        }

        ku += 3;
      }

      inIdx = 1;
      outIdx = 0;
      for (n = 0; n < 160; n++) {
        for (startC = 1; startC < 121; startC++) {
          brain_B.Erosion_m[outIdx] = TRUE;
          for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_f[1]; i++) {
            if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_h[brain_DWork.Erosion_ERODE_OFF_DW_l
                [i + brain_DWork.Erosion_NUMNONZ_DW_f[0]] + inIdx]) {
              brain_B.Erosion_m[outIdx] = FALSE;
              i = brain_DWork.Erosion_NUMNONZ_DW_f[1];
            }
          }

          inIdx++;
          outIdx++;
        }

        inIdx += 7;
      }

      /* Simulink Function 'CamDown_CenterOver_Yaw': '<S7>:1841' */
      for (i = 0; i < 19200; i++) {
        /* DataTypeConversion: '<S99>/Data Type Conversion' */
        brain_B.DataTypeConversion[i] = brain_B.Erosion_m[i];
        brain_B.BWout[i] = (real_T)brain_B.DataTypeConversion[i];
        brain_B.BW_i[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsFollowOnePa_e(brain_B.BW_i, brain_M,
        &brain_B.StateFlowFunctionsFollowOneP_ey,
        &brain_DWork.StateFlowFunctionsFollowOneP_ey);
      brain_B.Left = brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion;
      brain_B.Right =
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion1;
      brain_DWork.Forward = (real_T)
        brain_B.StateFlowFunctionsFollowOneP_ey.DataTypeConversion_m;
      RhoIndex_idx_0 = brain_B.StateFlowFunctionsFollowOneP_ey.Subtract1;
      ThetaIndex_idx_0 = brain_B.StateFlowFunctionsFollowOneP_ey.Subtract;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S38>/Add' */
      index_moment = (real_T)brain_B.DesiredDepth1 - (real_T)
        brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S137>/TSamp' incorporates:
       *  Gain: '<S136>/Depth Derivative Gain'
       *
       * About '<S137>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      sum_maxValues = brain_P.Depth_Kd * index_moment / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
       *  Gain: '<S136>/Depth Proportional Gain'
       *  Sum: '<S136>/Sum'
       *  Sum: '<S137>/Diff'
       *  UnitDelay: '<S137>/UD'
       *
       * Block description for '<S137>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S137>/UD':
       *
       *  Store in Global RAM
       */
      rtb_Rho_idx = (brain_P.Depth_Kp * index_moment + (sum_maxValues -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      rtb_Rho_idx = floor(rtb_Rho_idx);
      if (rtb_Rho_idx < 128.0) {
        if (rtb_Rho_idx >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)rtb_Rho_idx;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S137>/UD'
       * Block description for '<S137>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = sum_maxValues;

      /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S136>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        index_moment) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
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
      brain_DWork.Error = fabs(RhoIndex_idx_0) + fabs(ThetaIndex_idx_0);
    }
    break;

   default:
    /* Transition: '<S7>:1552' */
    /* Entry 'PositionOver': '<S7>:1554' */
    brain_DWork.is_OnePath = brain_IN_PositionOver;
    brain_B.SubState = 2.0;
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
    brain_B.SubState = 2.0;
    brain_DWork.Error = 500.0;
  } else {
    /* Simulink Function 'LookforTrack': '<S7>:1584' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_f[i] = brain_B.Resize[i];
      brain_B.S_ah[i] = brain_B.Resize1[i];
    }

    StateFlowFunctionsValidationGat(brain_B.H_f, brain_B.S_ah,
      &brain_B.StateFlowFunctionsFollowOnePa_l,
      &brain_DWork.StateFlowFunctionsFollowOnePa_l);
    brain_DWork.Obstacle = (brain_B.StateFlowFunctionsFollowOnePa_l.Image != 0.0);
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsFollowOnePa_l.BW[i];
    }

    switch (brain_DWork.is_RecognizePath) {
     case brain_IN_TurnLeft:
      /* During 'TurnLeft': '<S7>:1583' */
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 5U) {
        /* Transition: '<S7>:1580' */
        /* Exit 'TurnLeft': '<S7>:1583' */
        /* Entry 'TurnRight': '<S7>:1582' */
        brain_DWork.is_RecognizePath = brain_IN_TurnRight;
        brain_DWork.temporalCounter_i1 = 0U;
      } else {
        brain_B.DesiredHeading = brain_U.CurrentHeading - 15.0;

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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
      if ((uint32_T)brain_DWork.temporalCounter_i1 >= 5U) {
        /* Transition: '<S7>:1581' */
        /* Exit 'TurnRight': '<S7>:1582' */
        /* Entry 'TurnLeft': '<S7>:1583' */
        brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
        brain_DWork.temporalCounter_i1 = 0U;
      } else {
        brain_B.DesiredHeading = brain_U.CurrentHeading + 15.0;

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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
      brain_DWork.temporalCounter_i1 = 0U;
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
    brain_B.SubState = 1.0;

    /* Simulink Function 'GetHedgeValues': '<S7>:1638' */

    /* Constant: '<S34>/Hedge Hue' */
    brain_B.HedgeHue = brain_P.Hedge_Hue;

    /* Constant: '<S34>/Hedge Saturation' */
    brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

    /* Constant: '<S34>/Hedge Value' */
    brain_B.HedgeValue = brain_P.Hedge_Value;
    brain_DWork.H_Hue = brain_B.HedgeHue;
    brain_DWork.H_Sat = brain_B.HedgeSaturation;
    brain_DWork.H_Value = brain_B.HedgeValue;

    /* Simulink Function 'GetForwardVelocity': '<S7>:1697' */

    /* Constant: '<S31>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Vision_Forward_Velocity;
    brain_DWork.Forward = brain_B.HeadingForwardVelocity;
  } else if (brain_DWork.OperationalState == -1) {
    /* Transition: '<S7>:1267' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'ControlledRC': '<S7>:1260' */
    brain_DWork.is_StateFlowFunctions = brain_IN_ControlledRC;
    brain_B.State = -1;

    /* Transition: '<S7>:1875' */
    /* Entry 'Compass': '<S7>:1872' */
    brain_DWork.is_ControlledRC = brain_IN_Compass;
    brain_B.SubState = 1.0;
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
    brain_B.SubState = 1.0;

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
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S76>:1' */
    /*  This function simply makes an HSV image a single multidimensional */
    /*  signal */
    /* '<S76>:1:7' */
    memset((void *)(&brain_B.HSVImage1[0]), 0, 57600U * sizeof(real_T));

    /* '<S76>:1:9' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&brain_B.HSVImage1[120 * i]), (void *)(&brain_B.H1[120 * i]),
             120U * sizeof(real_T));
    }

    /* '<S76>:1:10' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&brain_B.HSVImage1[19200 + 120 * i]), (void *)
             (&brain_B.S1[120 * i]), 120U * sizeof(real_T));
    }

    /* '<S76>:1:11' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&brain_B.HSVImage1[38400 + 120 * i]), (void *)
             (&brain_B.V1[120 * i]), 120U * sizeof(real_T));
    }

    /* Transition: '<S7>:1547' */
    /* Entry 'RecognizePath': '<S7>:1578' */
    brain_DWork.is_FollowOnePath = brain_IN_RecognizePath;
    brain_B.SubState = 1.0;

    /* Transition: '<S7>:1579' */
    /* Entry 'TurnLeft': '<S7>:1583' */
    brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
    brain_DWork.temporalCounter_i1 = 0U;
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
    brain_B.SubState = 1.0;
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
static real_T brain_GetStrafeDirection(real_T AxisDif)
{
  real_T StrafeDir1;

  /* Embedded MATLAB Function 'GetStrafeDirection': '<S7>:1630' */
  /*  This function determines the direction the AUV should be strafing based */
  /*  on the initial major axis length change when strafing right */
  if (AxisDif < 0.0) {
    /* '<S7>:1630:5' */
    /* '<S7>:1630:6' */
    StrafeDir1 = -1.0;
  } else {
    /* '<S7>:1630:8' */
    StrafeDir1 = 1.0;
  }

  /*  StrafeDir = -1 corresponds to strafing left */
  /*  StrafeDir = 1 corresponds to strafing right */
  return StrafeDir1;
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
static void brai_enter_atomic_ApproachHedge(void)
{
  /* Entry 'ApproachHedge': '<S7>:1613' */
  brain_DWork.is_JumpHedge = brain_IN_ApproachHedge;
  brain_B.SubState = 4.0;
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
    brain_DWork.is_JumpHedge = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    brai_enter_atomic_ApproachHedge();
  } else if (brain_DWork.MoveOn == 1.0) {
    /* Transition: '<S7>:1610' */
    exit_internal_GetInitialDirecti();

    /* Exit 'GetInitialDirection': '<S7>:1623' */
    /* Entry 'IncreaseAxisRatio': '<S7>:1617' */
    brain_DWork.is_JumpHedge = brain_IN_IncreaseAxisRatio;
    brain_B.SubState = 3.0;

    /* Transition: '<S7>:1618' */
    /* Entry 'Move': '<S7>:1621' */
    brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
    brain_DWork.count = 0.0;
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
          brain_B.S_j[i] = brain_B.Resize1[i];
          brain_B.V_j[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.Num_Colors_k = brain_DWork.num_colors;
        brain_B.B_Hue_i = brain_DWork.H_Hue;
        brain_B.B_Sat_c = brain_DWork.H_Sat;
        brain_B.B_Value_n = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
          brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
          brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_p[i] = brain_B.BWout[i];
        }

        StateFlowFunctionsJumpHedgeGetA(brain_B.BW_p,
          &brain_B.StateFlowFunctionsJumpHedgeGe_k,
          &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
        brain_DWork.NewAxisRatio =
          brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;
        brain_DWork.StrafeDir = brain_GetStrafeDirection
          (brain_DWork.NewAxisRatio - brain_DWork.OldAxisRatio);
        brain_DWork.MoveOn = 1.0;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i,
          brain_B.Ref_Colors_m, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U *
               sizeof(real_T));
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_j[i] = brain_B.Resize1[i];
          brain_B.V_j[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.Num_Colors_k = brain_DWork.num_colors;
        brain_B.B_Hue_i = brain_DWork.H_Hue;
        brain_B.B_Sat_c = brain_DWork.H_Sat;
        brain_B.B_Value_n = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
          brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
          brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_l[i] = brain_B.BWout[i];
        }

        brain_B.ForwardVelocity = 0.0;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_l, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;
        brain_B.Strafe = (int8_T)(40.0 * brain_DWork.StrafeDir);

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i,
          brain_B.Ref_Colors_m, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U *
               sizeof(real_T));
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
        brain_B.S_j[i] = brain_B.Resize1[i];
        brain_B.V_j[i] = brain_B.Resize2[i];
      }

      StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
        &brain_B.StateFlowFunctionsJumpHedgeIter,
        &brain_DWork.StateFlowFunctionsJumpHedgeIter);
      memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
             (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U *
             sizeof(real_T));
      brain_DWork.num_colors =
        brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
      memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
             (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
             sizeof(real_T));

      /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
      memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
             (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
      memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
             (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
      brain_B.Num_Colors_k = brain_DWork.num_colors;
      brain_B.B_Hue_i = brain_DWork.H_Hue;
      brain_B.B_Sat_c = brain_DWork.H_Sat;
      brain_B.B_Value_n = brain_DWork.H_Value;
      StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
        brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
        brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

      /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
        brain_B.BW_p[i] = brain_B.BWout[i];
      }

      StateFlowFunctionsJumpHedgeGetA(brain_B.BW_p,
        &brain_B.StateFlowFunctionsJumpHedgeGe_k,
        &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
      brain_DWork.OldAxisRatio =
        brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;

      /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
      memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
             (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
      memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
             (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i, brain_B.Ref_Colors_m,
        &brain_B.StateFlowFunctionsJumpHedgeShow);
      memcpy((void *)(&brain_B.RGBout[0]), (void *)
             (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U * sizeof
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
    brain_B.SubState = 4.0;
  } else {
    switch (brain_DWork.is_IncreaseAxisRatio) {
     case brain_IN_CheckAxisRatio:
      /* During 'CheckAxisRatio': '<S7>:1622' */
      /* Transition: '<S7>:1620' */
      /* Exit 'CheckAxisRatio': '<S7>:1622' */
      /* Entry 'Move': '<S7>:1621' */
      brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
      brain_DWork.count = 0.0;
      break;

     case brain_IN_Move:
      /* During 'Move': '<S7>:1621' */
      if (brain_DWork.count >= 15.0) {
        /* Transition: '<S7>:1619' */
        /* Exit 'Move': '<S7>:1621' */
        brain_B.Strafe = 0;
        brain_B.Left = 0;
        brain_B.Right = 0;

        /* Entry 'CheckAxisRatio': '<S7>:1622' */
        brain_DWork.is_IncreaseAxisRatio = brain_IN_CheckAxisRatio;

        /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
        memcpy((void *)(&brain_B.BW_p[0]), (void *)(&brain_B.BWout[0]), 19200U *
               sizeof(real_T));
        StateFlowFunctionsJumpHedgeGetA(brain_B.BW_p,
          &brain_B.StateFlowFunctionsJumpHedgeGe_k,
          &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
        brain_DWork.NewAxisRatio =
          brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_j[i] = brain_B.Resize1[i];
          brain_B.V_j[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.Num_Colors_k = brain_DWork.num_colors;
        brain_B.B_Hue_i = brain_DWork.H_Hue;
        brain_B.B_Sat_c = brain_DWork.H_Sat;
        brain_B.B_Value_n = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
          brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
          brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_l[i] = brain_B.BWout[i];
        }

        brain_B.ForwardVelocity = 0.0;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_l, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;
        brain_B.Strafe = (int8_T)(40.0 * brain_DWork.StrafeDir);
        brain_DWork.count = brain_DWork.count + 1.0;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i,
          brain_B.Ref_Colors_m, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U *
               sizeof(real_T));
      }
      break;

     default:
      /* Transition: '<S7>:1618' */
      /* Entry 'Move': '<S7>:1621' */
      brain_DWork.is_IncreaseAxisRatio = brain_IN_Move;
      brain_DWork.count = 0.0;
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
  real_T max_votes;
  real_T top_vote;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T ky;
  int32_T ku;
  int32_T idxAdj;
  int32_T n;
  int32_T m;
  int32_T i;
  int32_T line_idx;
  int32_T line_idx_0;
  int32_T line_idx_1;
  int32_T line_idx_2;
  int32_T line_idx_3;
  int32_T line_idx_4;
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
    brain_B.SubState = 2.0;

    /* Transition: '<S7>:1624' */
    /* Entry 'GetMajorAxis': '<S7>:1627' */
    brain_DWork.is_GetInitialDirection = brain_IN_GetMajorAxis;
    brain_DWork.MoveOn = 0.0;
    brain_DWork.OldAxisRatio = 0.5;
    brain_DWork.StrafeDir = 1.0;

    /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_p[i] = brain_B.Resize[i];
      brain_B.S_j[i] = brain_B.Resize1[i];
      brain_B.V_j[i] = brain_B.Resize2[i];
    }

    StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
      &brain_B.StateFlowFunctionsJumpHedgeIter,
      &brain_DWork.StateFlowFunctionsJumpHedgeIter);
    memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
    memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
           sizeof(real_T));

    /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
    memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)(&brain_DWork.LabelMatrix
            [0]), 19200U * sizeof(real_T));
    memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    brain_B.Num_Colors_k = brain_DWork.num_colors;
    brain_B.B_Hue_i = brain_DWork.H_Hue;
    brain_B.B_Sat_c = brain_DWork.H_Sat;
    brain_B.B_Value_n = brain_DWork.H_Value;
    StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
      brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
      brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

    /* Simulink Function 'GetAxisRatio': '<S7>:1665' */
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
      brain_B.BW_p[i] = brain_B.BWout[i];
    }

    StateFlowFunctionsJumpHedgeGetA(brain_B.BW_p,
      &brain_B.StateFlowFunctionsJumpHedgeGe_k,
      &brain_DWork.StateFlowFunctionsJumpHedgeGe_k);
    brain_DWork.OldAxisRatio = brain_B.StateFlowFunctionsJumpHedgeGe_k.AxisRatio;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
    memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)(&brain_DWork.LabelMatrix
            [0]), 19200U * sizeof(real_T));
    memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i, brain_B.Ref_Colors_m,
      &brain_B.StateFlowFunctionsJumpHedgeShow);
    memcpy((void *)(&brain_B.RGBout[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U * sizeof
           (real_T));
  } else {
    /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_p[i] = brain_B.Resize[i];
      brain_B.S_j[i] = brain_B.Resize1[i];
      brain_B.V_j[i] = brain_B.Resize2[i];
    }

    StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
      &brain_B.StateFlowFunctionsJumpHedgeIter,
      &brain_DWork.StateFlowFunctionsJumpHedgeIter);
    memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U *
           sizeof(real_T));
    brain_DWork.num_colors = brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
    memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
           sizeof(real_T));

    /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
    memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)(&brain_DWork.LabelMatrix
            [0]), 19200U * sizeof(real_T));
    memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    brain_B.Num_Colors_k = brain_DWork.num_colors;
    brain_B.B_Hue_i = brain_DWork.H_Hue;
    brain_B.B_Sat_c = brain_DWork.H_Sat;
    brain_B.B_Value_n = brain_DWork.H_Value;
    StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
      brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
      brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
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

    /* Sum: '<S38>/Add' */
    rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

    /* SampleTimeMath: '<S137>/TSamp' incorporates:
     *  Gain: '<S136>/Depth Derivative Gain'
     *
     * About '<S137>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

    /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
     *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
     *  Gain: '<S136>/Depth Proportional Gain'
     *  Sum: '<S136>/Sum'
     *  Sum: '<S137>/Diff'
     *  UnitDelay: '<S137>/UD'
     *
     * Block description for '<S137>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S137>/UD':
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

    /* Update for UnitDelay: '<S137>/UD'
     * Block description for '<S137>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE = rtb_TSamp;

    /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S136>/Depth Integral Gain'
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
    for (i = 0; i < 19200; i++) {
      brain_B.BW_fn[i] = brain_B.BWout[i];

      /* S-Function (svipscalenconvert): '<S35>/Image Data Type Conversion' */
      brain_B.ImageDataTypeConversion_e[i] = ((brain_B.BW_fn[i] == 0.0 ? 0 : 1)
        != 0);
    }

    /* S-Function (svipmorphop): '<S35>/Erosion' */
    ky = 0;
    ku = 0;
    for (n = 0; n < 123; n++) {
      brain_DWork.Erosion_ONE_PAD_IMG_DW[ky] = TRUE;
      ky++;
    }

    for (i = 0; i < 160; i++) {
      memcpy((void *)(&brain_DWork.Erosion_ONE_PAD_IMG_DW[ky]), (void *)
             (&brain_B.ImageDataTypeConversion_e[ku]), 120U * sizeof(boolean_T));
      ky += 120;
      ku += 120;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[ky] = TRUE;
      ky++;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[ky] = TRUE;
      ky++;
      brain_DWork.Erosion_ONE_PAD_IMG_DW[ky] = TRUE;
      ky++;
    }

    for (i = 161; i < 165; i++) {
      for (n = 0; n < 123; n++) {
        brain_DWork.Erosion_ONE_PAD_IMG_DW[ky] = TRUE;
        ky++;
      }
    }

    ky = 0;
    ku = 0;
    for (n = 0; n < 160; n++) {
      for (m = 0; m < 120; m++) {
        brain_B.Erosion_g[ku] = TRUE;
        for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW; i++) {
          if (!brain_DWork.Erosion_ONE_PAD_IMG_DW[ky +
              brain_DWork.Erosion_ERODE_OFF_DW[i]]) {
            brain_B.Erosion_g[ku] = FALSE;
            i = brain_DWork.Erosion_NUMNONZ_DW;
          }
        }

        ky++;
        ku++;
      }

      ky += 3;
    }

    /* S-Function (sviphough): '<S35>/Hough Transform' */
    MWVIP_Hough_D(&brain_B.Erosion_g[0], &brain_B.HoughTransform_o1[0],
                  &brain_ConstP.pooled18[0], &brain_ConstP.pooled19, 120, 160,
                  399, 91);

    /* Embedded MATLAB: '<S35>/Are 3 Lines Present' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge/Are 3 Lines Present': '<S133>:1' */
    /*  This function is meant to see if there are 3 lines which approximate a */
    /*  'hedge' in the current frame */
    /* '<S133>:1:5' */
    /* '<S133>:1:6' */
    rtb_R_idx_1 = 0.0;
    rtb_T_idx_1 = 0.0;
    rtb_R_idx_0 = 0.0;
    rtb_T_idx_0 = 0.0;
    rtb_R_idx = 0.0;
    rtb_T_idx = 0.0;

    /*  Find the two vetical lines */
    /* '<S133>:1:12' */
    rtb_Add = 0.0;

    /* '<S133>:1:13' */
    rtb_TSamp = 0.0;

    /* '<S133>:1:14' */
    ky = 1;

    /* '<S133>:1:16' */
    ku = 1;

    /* '<S133>:1:17' */
    idxAdj = 1;

    /* '<S133>:1:19' */
    for (i = 0; i < 399; i++) {
      /* '<S133>:1:19' */
      /* '<S133>:1:20' */
      for (n = 85; n < 96; n++) {
        /* '<S133>:1:20' */
        if (brain_B.HoughTransform_o1[(n - 1) * 399 + i] > rtb_Add) {
          /* '<S133>:1:21' */
          if (fabs(brain_B.HoughTransform_o3[ky - 1] -
                   brain_B.HoughTransform_o3[i]) > 20.0) {
            /* '<S133>:1:22' */
            /* '<S133>:1:23' */
            rtb_TSamp = brain_B.HoughTransform_o1[(idxAdj - 1) * 399 + (ky - 1)];

            /* '<S133>:1:25' */
            idxAdj = ku;

            /* '<S133>:1:26' */
            rtb_R_idx_0 = rtb_R_idx_1;

            /* '<S133>:1:27' */
            rtb_T_idx_0 = rtb_T_idx_1;
          }

          /* '<S133>:1:29' */
          rtb_Add = brain_B.HoughTransform_o1[(n - 1) * 399 + i];

          /* '<S133>:1:30' */
          ky = i + 1;

          /* '<S133>:1:31' */
          ku = n;

          /* '<S133>:1:32' */
          rtb_R_idx_1 = brain_B.HoughTransform_o3[i];

          /* '<S133>:1:33' */
          rtb_T_idx_1 = brain_B.HoughTransform_o2[n - 1];
        } else {
          if ((brain_B.HoughTransform_o1[(n - 1) * 399 + i] > rtb_TSamp) &&
              (fabs(brain_B.HoughTransform_o3[ky - 1] -
                    brain_B.HoughTransform_o3[i]) > 20.0)) {
            /* '<S133>:1:34' */
            /* '<S133>:1:35' */
            rtb_TSamp = brain_B.HoughTransform_o1[(n - 1) * 399 + i];

            /* '<S133>:1:37' */
            idxAdj = n;

            /* '<S133>:1:38' */
            rtb_R_idx_0 = brain_B.HoughTransform_o3[i];

            /* '<S133>:1:39' */
            rtb_T_idx_0 = brain_B.HoughTransform_o2[n - 1];
          }
        }
      }
    }

    /*  Find the horizontal line */
    /* '<S133>:1:45' */
    max_votes = 0.0;

    /* '<S133>:1:47' */
    for (ku = 0; ku < 399; ku++) {
      /* '<S133>:1:47' */
      /* '<S133>:1:48' */
      for (ky = 0; ky < 10; ky++) {
        /* '<S133>:1:48' */
        if (brain_B.HoughTransform_o1[399 * ky + ku] > max_votes) {
          /* '<S133>:1:49' */
          /* '<S133>:1:50' */
          max_votes = brain_B.HoughTransform_o1[399 * ky + ku];

          /* '<S133>:1:52' */
          rtb_R_idx = brain_B.HoughTransform_o3[ku];

          /* '<S133>:1:53' */
          rtb_T_idx = brain_B.HoughTransform_o2[ky];
        }
      }

      /* '<S133>:1:56' */
      for (ky = 170; ky < 181; ky++) {
        /* '<S133>:1:56' */
        if (brain_B.HoughTransform_o1[(ky - 1) * 399 + ku] > max_votes) {
          /* '<S133>:1:57' */
          /* '<S133>:1:58' */
          max_votes = brain_B.HoughTransform_o1[(ky - 1) * 399 + ku];

          /* '<S133>:1:60' */
          rtb_R_idx = brain_B.HoughTransform_o3[ku];

          /* '<S133>:1:61' */
          rtb_T_idx = brain_B.HoughTransform_o2[ky - 1];
        }
      }
    }

    /*  Find the most prominent line */
    /* '<S133>:1:67' */
    top_vote = 0.0;

    /* '<S133>:1:70' */
    for (ky = 0; ky < 399; ky++) {
      /* '<S133>:1:70' */
      /* '<S133>:1:71' */
      for (ku = 0; ku < 180; ku++) {
        /* '<S133>:1:71' */
        if (brain_B.HoughTransform_o1[399 * ku + ky] > top_vote) {
          /* '<S133>:1:72' */
          /* '<S133>:1:73' */
          top_vote = brain_B.HoughTransform_o1[399 * ku + ky];
        }
      }
    }

    /* '<S133>:1:80' */
    brain_B.Image = 0.0;
    if ((top_vote * 0.75 < max_votes) && (top_vote * 0.3 < rtb_Add) && (top_vote
         * 0.3 < rtb_TSamp)) {
      /* '<S133>:1:81' */
      /* '<S133>:1:82' */
      brain_B.Image = 1.0;
    }

    /* S-Function (sviphoughlines): '<S35>/Hough Lines' */
    idxAdj = 0;
    rtb_Add = (rtb_R_idx_1 + 2.2204460492503131E-16) / (cos(rtb_T_idx_1) +
      2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[0] = 0;
      brain_B.HoughLines[1] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      idxAdj = 1;
    }

    max_votes = (rtb_R_idx_1 + 2.2204460492503131E-16) / (sin(rtb_T_idx_1) +
      2.2204460492503131E-16);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[(idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
        rtb_TSamp + 0.5);
      brain_B.HoughLines[1 + (idxAdj << 1)] = 0;
      idxAdj++;
    }

    /* part-3: Right vertical axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[(idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        brain_B.HoughLines[1 + (idxAdj << 1)] = 159;
        idxAdj++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[(idxAdj << 1)] = 119;
        brain_B.HoughLines[1 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        idxAdj++;
      }
    }

    if (idxAdj < 2) {
      brain_B.HoughLines[0] = -1;
      brain_B.HoughLines[1] = -1;
      brain_B.HoughLines[2] = -1;
      brain_B.HoughLines[3] = -1;
    }

    idxAdj = 0;
    rtb_Add = (rtb_R_idx_0 + 2.2204460492503131E-16) / (cos(rtb_T_idx_0) +
      2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[4] = 0;
      brain_B.HoughLines[5] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      idxAdj = 1;
    }

    max_votes = (rtb_R_idx_0 + 2.2204460492503131E-16) / (sin(rtb_T_idx_0) +
      2.2204460492503131E-16);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[4 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
        rtb_TSamp + 0.5);
      brain_B.HoughLines[5 + (idxAdj << 1)] = 0;
      idxAdj++;
    }

    /* part-3: Right vertical axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[4 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        brain_B.HoughLines[5 + (idxAdj << 1)] = 159;
        idxAdj++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[4 + (idxAdj << 1)] = 119;
        brain_B.HoughLines[5 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        idxAdj++;
      }
    }

    if (idxAdj < 2) {
      brain_B.HoughLines[4] = -1;
      brain_B.HoughLines[5] = -1;
      brain_B.HoughLines[6] = -1;
      brain_B.HoughLines[7] = -1;
    }

    idxAdj = 0;
    rtb_Add = (rtb_R_idx + 2.2204460492503131E-16) / (cos(rtb_T_idx) +
      2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    rtb_TSamp = floor(rtb_Add + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
      brain_B.HoughLines[8] = 0;
      brain_B.HoughLines[9] = (int32_T)floor((real_T)(int32_T)rtb_TSamp + 0.5);
      idxAdj = 1;
    }

    max_votes = (rtb_R_idx + 2.2204460492503131E-16) / (sin(rtb_T_idx) +
      2.2204460492503131E-16);

    /* part-2: left vertical axis */
    rtb_TSamp = floor(max_votes + 0.5);
    if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
      brain_B.HoughLines[8 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
        rtb_TSamp + 0.5);
      brain_B.HoughLines[9 + (idxAdj << 1)] = 0;
      idxAdj++;
    }

    /* part-3: Right vertical axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - 159.0) * (max_votes / rtb_Add) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 119.0)) {
        brain_B.HoughLines[8 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        brain_B.HoughLines[9 + (idxAdj << 1)] = 159;
        idxAdj++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (idxAdj < 2) {
      rtb_TSamp = floor((rtb_Add - rtb_Add / max_votes * 119.0) + 0.5);
      if ((rtb_TSamp >= 0.0) && (rtb_TSamp <= 159.0)) {
        brain_B.HoughLines[8 + (idxAdj << 1)] = 119;
        brain_B.HoughLines[9 + (idxAdj << 1)] = (int32_T)floor((real_T)(int32_T)
          rtb_TSamp + 0.5);
        idxAdj++;
      }
    }

    if (idxAdj < 2) {
      brain_B.HoughLines[8] = -1;
      brain_B.HoughLines[9] = -1;
      brain_B.HoughLines[10] = -1;
      brain_B.HoughLines[11] = -1;
    }

    /* S-Function (svipdrawshapes): '<S35>/Draw Shapes' */
    /* Copy the image from input to output. */
    memcpy((void *)(&brain_B.DrawShapes[0]), (void *)(&brain_B.BW_fn[0]), 19200U
           * sizeof(real_T));
    idxStart = 0;
    for (idxROI = 0; idxROI < 3; idxROI++) {
      for (idxAdj = 0; idxAdj < 1; idxAdj = 1) {
        line_idx_2 = brain_B.HoughLines[idxStart];
        n = brain_B.HoughLines[idxStart + 1];
        line_idx_3 = brain_B.HoughLines[idxStart + 2];
        line_idx_4 = brain_B.HoughLines[idxStart + 3];
        if ((brain_B.HoughLines[idxStart + 2] != brain_B.HoughLines[idxStart]) ||
            (brain_B.HoughLines[idxStart + 1] != brain_B.HoughLines[idxStart + 3]))
        {
          isInBound = FALSE;

          /* Find the visible portion of a line. */
          visited = FALSE;
          visited_0 = FALSE;
          done = FALSE;
          i = brain_B.HoughLines[idxStart];
          line_idx = brain_B.HoughLines[idxStart + 1];
          line_idx_1 = brain_B.HoughLines[idxStart + 2];
          line_idx_0 = brain_B.HoughLines[idxStart + 3];
          while (!done) {
            m = 0;
            err = 0;

            /* Determine viewport violations. */
            if (i < 0) {
              m = 4;
            } else {
              if (i > 119) {
                m = 8;
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
              m = (int32_T)((uint32_T)m | 1U);
            } else {
              if (line_idx > 159) {
                m = (int32_T)((uint32_T)m | 2U);
              }
            }

            if (line_idx_0 < 0) {
              err = (int32_T)((uint32_T)err | 1U);
            } else {
              if (line_idx_0 > 159) {
                err = (int32_T)((uint32_T)err | 2U);
              }
            }

            if (!((uint32_T)m | (uint32_T)err)) {
              /* Line falls completely within bounds. */
              done = TRUE;
              isInBound = TRUE;
            } else if ((uint32_T)m & (uint32_T)err) {
              /* Line falls completely out of bounds. */
              done = TRUE;
              isInBound = FALSE;
            } else if ((uint32_T)m != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited) {
                i = line_idx_2;
                line_idx = n;
              }

              ky = line_idx_1 - i;
              ku = line_idx_0 - line_idx;
              if ((uint32_T)m & 4U) {
                /* Violated RMin. */
                idxAdj = (0 - i) * ku;
                if (((idxAdj >= 0) && (ky >= 0)) || ((idxAdj < 0) && (ky < 0)))
                {
                  line_idx += (div_s32_floor(idxAdj << 1U, ky) + 1) >> 1;
                } else {
                  line_idx += -((div_s32_floor((-idxAdj) << 1U, ky) + 1) >> 1);
                }

                i = 0;
                visited = TRUE;
              } else if ((uint32_T)m & 8U) {
                /* Violated RMax. */
                idxAdj = (119 - i) * ku;
                if (((idxAdj >= 0) && (ky >= 0)) || ((idxAdj < 0) && (ky < 0)))
                {
                  line_idx += (div_s32_floor(idxAdj << 1U, ky) + 1) >> 1;
                } else {
                  line_idx += -((div_s32_floor((-idxAdj) << 1U, ky) + 1) >> 1);
                }

                i = 119;
                visited = TRUE;
              } else if ((uint32_T)m & 1U) {
                /* Violated CMin. */
                idxAdj = (0 - line_idx) * ky;
                if (((idxAdj >= 0) && (ku >= 0)) || ((idxAdj < 0) && (ku < 0)))
                {
                  i += (div_s32_floor(idxAdj << 1U, ku) + 1) >> 1;
                } else {
                  i += -((div_s32_floor((-idxAdj) << 1U, ku) + 1) >> 1);
                }

                line_idx = 0;
                visited = TRUE;
              } else {
                /* Violated CMax. */
                idxAdj = (159 - line_idx) * ky;
                if (((idxAdj >= 0) && (ku >= 0)) || ((idxAdj < 0) && (ku < 0)))
                {
                  i += (div_s32_floor(idxAdj << 1U, ku) + 1) >> 1;
                } else {
                  i += -((div_s32_floor((-idxAdj) << 1U, ku) + 1) >> 1);
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

              ky = line_idx_1 - i;
              ku = line_idx_0 - line_idx;
              if ((uint32_T)err & 4U) {
                /* Violated RMin. */
                idxAdj = (0 - line_idx_1) * ku;
                if (((idxAdj >= 0) && (ky >= 0)) || ((idxAdj < 0) && (ky < 0)))
                {
                  line_idx_0 += (div_s32_floor(idxAdj << 1U, ky) + 1) >> 1;
                } else {
                  line_idx_0 += -((div_s32_floor((-idxAdj) << 1U, ky) + 1) >> 1);
                }

                line_idx_1 = 0;
                visited_0 = TRUE;
              } else if ((uint32_T)err & 8U) {
                /* Violated RMax. */
                idxAdj = (119 - line_idx_1) * ku;
                if (((idxAdj >= 0) && (ky >= 0)) || ((idxAdj < 0) && (ky < 0)))
                {
                  line_idx_0 += (div_s32_floor(idxAdj << 1U, ky) + 1) >> 1;
                } else {
                  line_idx_0 += -((div_s32_floor((-idxAdj) << 1U, ky) + 1) >> 1);
                }

                line_idx_1 = 119;
                visited_0 = TRUE;
              } else if ((uint32_T)err & 1U) {
                /* Violated CMin. */
                idxAdj = (0 - line_idx_0) * ky;
                if (((idxAdj >= 0) && (ku >= 0)) || ((idxAdj < 0) && (ku < 0)))
                {
                  line_idx_1 += (div_s32_floor(idxAdj << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_1 += -((div_s32_floor((-idxAdj) << 1U, ku) + 1) >> 1);
                }

                line_idx_0 = 0;
                visited_0 = TRUE;
              } else {
                /* Violated CMax. */
                idxAdj = (159 - line_idx_0) * ky;
                if (((idxAdj >= 0) && (ku >= 0)) || ((idxAdj < 0) && (ku < 0)))
                {
                  line_idx_1 += (div_s32_floor(idxAdj << 1U, ku) + 1) >> 1;
                } else {
                  line_idx_1 += -((div_s32_floor((-idxAdj) << 1U, ku) + 1) >> 1);
                }

                line_idx_0 = 159;
                visited_0 = TRUE;
              }
            }
          }

          if (isInBound) {
            /* Draw a line using Bresenham algorithm. */
            /* Initialize the Bresenham algorithm. */
            if (line_idx_1 >= i) {
              ky = line_idx_1 - i;
            } else {
              ky = i - line_idx_1;
            }

            if (line_idx_0 >= line_idx) {
              ku = line_idx_0 - line_idx;
            } else {
              ku = line_idx - line_idx_0;
            }

            if (ky > ku) {
              line_idx_2 = 1;
              ku = 120;
            } else {
              line_idx_2 = 120;
              ku = 1;
              ky = i;
              i = line_idx;
              line_idx = ky;
              ky = line_idx_1;
              line_idx_1 = line_idx_0;
              line_idx_0 = ky;
            }

            if (i > line_idx_1) {
              ky = i;
              i = line_idx_1;
              line_idx_1 = ky;
              ky = line_idx;
              line_idx = line_idx_0;
              line_idx_0 = ky;
            }

            n = line_idx_1 - i;
            if (line_idx <= line_idx_0) {
              ky = 1;
              m = line_idx_0 - line_idx;
            } else {
              ky = -1;
              m = line_idx - line_idx_0;
            }

            err = -((n + 1) >> 1);
            idxAdj = i * line_idx_2 + line_idx * ku;
            ky = ky * ku + line_idx_2;
            for (isInBound = (i <= line_idx_1); isInBound; isInBound = (i <=
                  line_idx_1)) {
              brain_B.DrawShapes[idxAdj] = 0.8;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              err += m;
              if (err >= 0) {
                err -= n;
                idxAdj += ky;
              } else {
                idxAdj += line_idx_2;
              }

              i++;
            }
          }
        }

        idxStart += 2;
      }

      idxStart += 2;
    }

    brain_DWork.Image = brain_B.Image;

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = brain_B.DrawShapes[i];
      brain_B.LabMatrix_i[i] = brain_DWork.LabelMatrix[i];
    }

    memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)(&brain_DWork.ref_colors
            [0]), 150U * sizeof(real_T));
    StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i, brain_B.Ref_Colors_m,
      &brain_B.StateFlowFunctionsJumpHedgeShow);
    memcpy((void *)(&brain_B.RGBout[0]), (void *)
           (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U * sizeof
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
  int32_T inIdx;
  int32_T centerM;
  int32_T centerN;
  int32_T n;
  int32_T startR;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  int32_T m;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW;
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T rtb_BuoyBlobAnalysis;
  real_T rtb_Add;
  real_T rtb_TSamp;
  int32_T i;
  real_T tmp;

  /* During 'JumpHedge': '<S7>:1605' */
  if (brain_DWork.OperationalState != 5) {
    /* Transition: '<S7>:1688' */
    brain_exit_internal_JumpHedge();
    brain_exit_atomic_JumpHedge();

    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
    brain_B.SubState = 0.0;
  } else {
    switch (brain_DWork.is_JumpHedge) {
     case brain_IN_ApproachHedge:
      /* During 'ApproachHedge': '<S7>:1613' */
      if (brain_DWork.Area > 4000) {
        /* Transition: '<S7>:1611' */
        /* Exit 'ApproachHedge': '<S7>:1613' */
        /* Entry 'GoThroughHedge': '<S7>:1648' */
        brain_DWork.is_JumpHedge = brain_IN_GoThroughHedge;
        brain_B.SubState = 5.0;
        brain_B.DesiredHeading = brain_U.CurrentHeading;
        brain_B.DesiredDepth = brain_U.CurrentDepth - 2.0;
        brain_B.Strafe = 0;
        brain_DWork.count = 0.0;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_j[i] = brain_B.Resize1[i];
          brain_B.V_j[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.Num_Colors_k = brain_DWork.num_colors;
        brain_B.B_Hue_i = brain_DWork.H_Hue;
        brain_B.B_Sat_c = brain_DWork.H_Sat;
        brain_B.B_Value_n = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
          brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
          brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);

        /* Simulink Function 'CameraForward_CenterOnBlobYaw': '<S7>:1658' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
          brain_B.BW_l[i] = brain_B.BWout[i];
        }

        brain_B.ForwardVelocity = brain_DWork.Forward;
        StateFlowFunctionsJumpHedgeCame(brain_B.BW_l, brain_B.ForwardVelocity,
          brain_M, &brain_B.StateFlowFunctionsJumpHedgeCa_p,
          &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);
        brain_B.Left = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add1;
        brain_B.Right = (int8_T)brain_B.StateFlowFunctionsJumpHedgeCa_p.Add;
        brain_B.Vertical =
          brain_B.StateFlowFunctionsJumpHedgeCa_p.DataTypeConversion;

        /* Simulink Function 'GetArea': '<S7>:1614' */
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] =
            brain_B.StateFlowFunctionsJumpHedgeCa_p.DrawMarkers[i];
          brain_B.BW_g[i] = brain_B.BWout[i];

          /* S-Function (svipscalenconvert): '<S28>/Image Data Type Conversion' */
          brain_B.ImageDataTypeConversion_d[i] = ((brain_B.BW_g[i] == 0.0 ? 0 :
            1) != 0);
        }

        /* S-Function (svipmorphop): '<S28>/Dilation' */
        for (i = 0; i < 20049; i++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW[i] = FALSE;
        }

        for (inIdx = 0; inIdx < 19200; inIdx++) {
          if (brain_B.ImageDataTypeConversion_d[inIdx]) {
            centerM = inIdx / 120;
            centerM = (inIdx - centerM * 120) + centerM * 123;
            for (i = 0; i < brain_DWork.Dilation_NUMNONZ_DW; i++) {
              brain_DWork.Dilation_ONE_PAD_IMG_DW[centerM +
                brain_DWork.Dilation_DILATE_OFF_DW[i]] = TRUE;
            }
          }
        }

        inIdx = 0;
        centerM = 0;
        for (n = 0; n < 160; n++) {
          for (m = 0; m < 120; m++) {
            brain_B.Dilation[centerM] =
              brain_DWork.Dilation_ONE_PAD_IMG_DW[inIdx];
            centerM++;
            inIdx++;
          }

          inIdx += 3;
        }

        /* S-Function (svipmorphop): '<S28>/Erosion' */
        centerM = 0;
        centerN = 0;
        for (startR = 0; startR < 127; startR++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerM] = TRUE;
          centerM++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerM] = TRUE;
          centerM++;
          memcpy((void *)(&brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerM]), (void
                  *)(&brain_B.Dilation[centerN]), 120U * sizeof(boolean_T));
          centerM += 120;
          centerN += 120;
          for (startR = 121; startR < 127; startR++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerM] = TRUE;
            centerM++;
          }
        }

        for (i = 161; i < 167; i++) {
          for (startR = 0; startR < 127; startR++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerM] = TRUE;
            centerM++;
          }
        }

        for (i = 0; i < 21209; i++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW[i] = TRUE;
        }

        centerN = 0;
        for (n = 0; n < 167; n++) {
          for (m = 0; m < 124; m++) {
            brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + centerN] = TRUE;
            for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_j[0]; i++) {
              if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_a[centerN +
                  brain_DWork.Erosion_ERODE_OFF_DW_i[i]]) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + centerN] = FALSE;
                i = brain_DWork.Erosion_NUMNONZ_DW_j[0];
              }
            }

            centerN++;
          }

          centerN += 3;
        }

        inIdx = 1;
        centerM = 0;
        for (n = 0; n < 160; n++) {
          for (m = 1; m < 121; m++) {
            brain_B.Erosion[centerM] = TRUE;
            for (i = 0; i < brain_DWork.Erosion_NUMNONZ_DW_j[1]; i++) {
              if (!brain_DWork.Erosion_TWO_PAD_IMG_DW[brain_DWork.Erosion_ERODE_OFF_DW_i
                  [i + brain_DWork.Erosion_NUMNONZ_DW_j[0]] + inIdx]) {
                brain_B.Erosion[centerM] = FALSE;
                i = brain_DWork.Erosion_NUMNONZ_DW_j[1];
              }
            }

            inIdx++;
            centerM++;
          }

          inIdx += 7;
        }

        /* S-Function (svipblob): '<S28>/Buoy Blob Analysis' */
        maxNumBlobsReached = FALSE;
        for (centerM = 0; centerM < 123; centerM++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[centerM] = 0U;
        }

        currentLabel = 1U;
        i = 0;
        centerN = 123;
        for (n = 0; n < 160; n++) {
          for (m = 0; m < 120; m++) {
            brain_DWork.BuoyBlobAnalysis_PAD_DW[centerN] = (uint8_T)
              (brain_B.Erosion[i] ? 255 : 0);
            i++;
            centerN++;
          }

          brain_DWork.BuoyBlobAnalysis_PAD_DW[centerN] = 0U;
          centerN++;
          brain_DWork.BuoyBlobAnalysis_PAD_DW[centerN] = 0U;
          centerN++;
        }

        for (centerM = 0; centerM < 121; centerM++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[centerM + centerN] = 0U;
        }

        centerN = 1;
        stackIdx = 0U;
        for (n = 0; n < 160; n++) {
          startR = 1;
          inIdx = centerN * 122;
          for (m = 0; m < 120; m++) {
            numBlobs = (uint32_T)(inIdx + startR);
            if (brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
              brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
              BuoyBlobAnalysis_NUM_PIX_DW = 1U;
              brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx];
                for (i = 0; i < 8; i++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled27[i];
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
                n = 160;
                m = 120;
              }

              if (m < 120) {
                currentLabel++;
              }
            }

            startR++;
          }

          centerN++;
        }

        numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel -
          1);
        for (i = 0; i < (int32_T)numBlobs; i++) {
          rtb_BuoyBlobAnalysis = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW;
        }

        for (centerM = (int32_T)numBlobs; centerM < 1; centerM = 1) {
          rtb_BuoyBlobAnalysis = -1;
        }

        /* Embedded MATLAB: '<S28>/Embedded MATLAB Function' */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea/Embedded MATLAB Function': '<S112>:1' */
        /*  This function will choose and return data about the largest blob given a  */
        /*  set of blobs */
        if (rtb_BuoyBlobAnalysis == -1) {
          /* '<S112>:1:5' */
          /* '<S112>:1:7' */
          brain_B.BlobArea = -1.0;
        } else {
          /* '<S112>:1:9' */
          brain_B.BlobArea = (real_T)rtb_BuoyBlobAnalysis;
        }

        brain_DWork.Area = (int32_T)brain_B.BlobArea;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i,
          brain_B.Ref_Colors_m, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U *
               sizeof(real_T));
      }
      break;

     case brain_IN_Finished:
      break;

     case brain_IN_GetInitialDirection:
      brain_GetInitialDirection();
      break;

     case brain_IN_GoThroughHedge:
      /* During 'GoThroughHedge': '<S7>:1648' */
      if (brain_DWork.count >= 20.0) {
        /* Transition: '<S7>:1612' */
        /* Exit 'GoThroughHedge': '<S7>:1648' */
        /* Entry 'Finished': '<S7>:1657' */
        brain_DWork.is_JumpHedge = brain_IN_Finished;
        brain_B.SubState = 6.0;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Strafe = 0;
        brain_DWork.Done = 1.0;
      } else {
        /* Simulink Function 'IterativeSegmentation': '<S7>:1680' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_p[i] = brain_B.Resize[i];
          brain_B.S_j[i] = brain_B.Resize1[i];
          brain_B.V_j[i] = brain_B.Resize2[i];
        }

        StateFlowFunctionsBuoysIterativ(brain_B.H_p, brain_B.S_j, brain_B.V_j,
          &brain_B.StateFlowFunctionsJumpHedgeIter,
          &brain_DWork.StateFlowFunctionsJumpHedgeIter);
        memcpy((void *)(&brain_DWork.LabelMatrix[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.LabelMatrix[0]), 19200U
               * sizeof(real_T));
        brain_DWork.num_colors =
          brain_B.StateFlowFunctionsJumpHedgeIter.num_colors;
        memcpy((void *)(&brain_DWork.ref_colors[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeIter.ref_colors[0]), 150U *
               sizeof(real_T));

        /* Simulink Function 'IndividualSegmentation': '<S7>:1672' */
        memcpy((void *)(&brain_B.LabMatrix_e[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_o[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        brain_B.Num_Colors_k = brain_DWork.num_colors;
        brain_B.B_Hue_i = brain_DWork.H_Hue;
        brain_B.B_Sat_c = brain_DWork.H_Sat;
        brain_B.B_Value_n = brain_DWork.H_Value;
        StateFlowFunctionsJumpHedgeIndi(brain_B.B_Hue_i, brain_B.B_Sat_c,
          brain_B.B_Value_n, brain_B.LabMatrix_e, brain_B.Ref_Colors_o,
          brain_B.Num_Colors_k, &brain_B.StateFlowFunctionsJumpHedgeIn_m);
        for (i = 0; i < 19200; i++) {
          brain_B.BWout[i] = (real_T)
            brain_B.StateFlowFunctionsJumpHedgeIn_m.BW[i];
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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
        brain_DWork.count = brain_DWork.count + 1.0;

        /* Simulink Function 'ShowSegmentedImage': '<S7>:1649' */
        memcpy((void *)(&brain_B.LabMatrix_i[0]), (void *)
               (&brain_DWork.LabelMatrix[0]), 19200U * sizeof(real_T));
        memcpy((void *)(&brain_B.Ref_Colors_m[0]), (void *)
               (&brain_DWork.ref_colors[0]), 150U * sizeof(real_T));
        StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_i,
          brain_B.Ref_Colors_m, &brain_B.StateFlowFunctionsJumpHedgeShow);
        memcpy((void *)(&brain_B.RGBout[0]), (void *)
               (&brain_B.StateFlowFunctionsJumpHedgeShow.RGB[0]), 57600U *
               sizeof(real_T));
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
      brain_B.SubState = 1.0;

      /* Simulink Function 'GetHedgeValues': '<S7>:1638' */

      /* Constant: '<S34>/Hedge Hue' */
      brain_B.HedgeHue = brain_P.Hedge_Hue;

      /* Constant: '<S34>/Hedge Saturation' */
      brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

      /* Constant: '<S34>/Hedge Value' */
      brain_B.HedgeValue = brain_P.Hedge_Value;
      brain_DWork.H_Hue = brain_B.HedgeHue;
      brain_DWork.H_Sat = brain_B.HedgeSaturation;
      brain_DWork.H_Value = brain_B.HedgeValue;

      /* Simulink Function 'GetForwardVelocity': '<S7>:1697' */

      /* Constant: '<S31>/Heading Forward Velocity' */
      brain_B.HeadingForwardVelocity = brain_P.Vision_Forward_Velocity;
      brain_DWork.Forward = brain_B.HeadingForwardVelocity;
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_LocatePinger(void)
{
  real_T differences[16];
  real_T Headings[4];
  int32_T index;
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
    brain_B.SubState = 0.0;
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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
          Headings[0] = 0.0;
          Headings[1] = 0.0;
          Headings[2] = 0.0;
          Headings[3] = 0.0;

          /* '<S7>:1798:9' */
          Headings[0] = brain_DWork.Heading1;

          /* '<S7>:1798:10' */
          Headings[1] = brain_DWork.Heading2;

          /* '<S7>:1798:11' */
          Headings[2] = brain_DWork.Heading3;

          /* '<S7>:1798:12' */
          Headings[3] = brain_DWork.Heading4;

          /* '<S7>:1798:14' */
          for (index = 0; index < 4; index++) {
            /* '<S7>:1798:14' */
            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            differences[index] = fabs(Headings[index] - Headings[0]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            differences[index + 4] = fabs(Headings[index] - Headings[1]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            differences[index + 8] = fabs(Headings[index] - Headings[2]);

            /* '<S7>:1798:15' */
            /* '<S7>:1798:16' */
            differences[index + 12] = fabs(Headings[index] - Headings[3]);
          }

          /* '<S7>:1798:20' */
          index = 1;

          /* '<S7>:1798:21' */
          rtb_Add = 1000.0;

          /* '<S7>:1798:22' */
          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (differences[8] < 1000.0) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = differences[8];

            /* '<S7>:1798:27' */
            index = 1;
          }

          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (differences[12] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = differences[12];

            /* '<S7>:1798:27' */
            index = 1;
          }

          /* '<S7>:1798:22' */
          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (differences[9] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = differences[9];

            /* '<S7>:1798:27' */
            index = 2;
          }

          /* '<S7>:1798:23' */
          /* '<S7>:1798:24' */
          if (differences[13] < rtb_Add) {
            /* '<S7>:1798:25' */
            /* '<S7>:1798:26' */
            rtb_Add = differences[13];

            /* '<S7>:1798:27' */
            index = 2;
          }

          if (rtb_Add < 5.0) {
            /* '<S7>:1798:33' */
            /* '<S7>:1798:34' */
            brain_B.DesiredHeading = Headings[index - 1];
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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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
static real_T brain_countimages_m(real_T Image, real_T OldImage, real_T count1)
{
  /* Embedded MATLAB Function 'countimages': '<S7>:1159' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  image is recognized by the recognition software */
  if ((Image != 0.0) && (Image == OldImage)) {
    /* '<S7>:1159:6' */
    /* '<S7>:1159:7' */
    return count1 + 1.0;
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
    brain_B.SubState = 0.0;
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
        brain_B.SubState = 2.0;
      } else {
        /* Simulink Function 'LookforTrack': '<S7>:1154' */
        for (i = 0; i < 19200; i++) {
          brain_B.H_o[i] = brain_B.Resize[i];
          brain_B.S_a[i] = brain_B.Resize1[i];
        }

        StateFlowFunctionsValidationGat(brain_B.H_o, brain_B.S_a,
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

        /* Constant: '<S40>/Heading Forward Velocity' */
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

        /* Sum: '<S38>/Add' */
        rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S137>/TSamp' incorporates:
         *  Gain: '<S136>/Depth Derivative Gain'
         *
         * About '<S137>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
         *  Gain: '<S136>/Depth Proportional Gain'
         *  Sum: '<S136>/Sum'
         *  Sum: '<S137>/Diff'
         *  UnitDelay: '<S137>/UD'
         *
         * Block description for '<S137>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S137>/UD':
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

        /* Update for UnitDelay: '<S137>/UD'
         * Block description for '<S137>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = rtb_TSamp;

        /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S136>/Depth Integral Gain'
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

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_StateFlowFunctions(void)
{
  real_T rtb_Add;
  real_T rtb_TSamp;
  real_T tmp;

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
      brain_B.SubState = 0.0;
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
      /* Exit 'Compass': '<S7>:1872' */
      brain_DWork.is_ControlledRC = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'IMU': '<S7>:1873' */
      /* Exit 'ControlledRC': '<S7>:1260' */
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;

      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      brain_B.SubState = 0.0;
    } else {
      switch (brain_DWork.is_ControlledRC) {
       case brain_IN_Compass:
        /* During 'Compass': '<S7>:1872' */
        if (brain_U.RC_Source != 0.0) {
          /* Transition: '<S7>:1876' */
          /* Exit 'Compass': '<S7>:1872' */
          /* Entry 'IMU': '<S7>:1873' */
          brain_DWork.is_ControlledRC = brain_IN_IMU;
          brain_B.SubState = 2.0;
        } else {
          /* Simulink Function 'MaintainDepth': '<S7>:926' */
          brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
          brain_B.DesiredDepth1 = (real32_T)brain_U.RC_Depth;
          brain_DWork.StateFlowFunctionsMaintainDepth =
            brain_M->Timing.clockTick0 -
            brain_DWork.StateFlowFunctionsMaintainDep_k;
          brain_DWork.StateFlowFunctionsMaintainDep_k =
            brain_M->Timing.clockTick0;

          /* Sum: '<S38>/Add' */
          rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)
            brain_B.CurrentDepth1;

          /* SampleTimeMath: '<S137>/TSamp' incorporates:
           *  Gain: '<S136>/Depth Derivative Gain'
           *
           * About '<S137>/TSamp':
           *  y = u * K where K = 1 / ( w * Ts )
           */
          rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
            brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

          /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
           *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
           *  Gain: '<S136>/Depth Proportional Gain'
           *  Sum: '<S136>/Sum'
           *  Sum: '<S137>/Diff'
           *  UnitDelay: '<S137>/UD'
           *
           * Block description for '<S137>/Diff':
           *
           *  Add in CPU
           *
           * Block description for '<S137>/UD':
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

          /* Update for UnitDelay: '<S137>/UD'
           * Block description for '<S137>/UD':
           *
           *  Store in Global RAM
           */
          brain_DWork.UD_DSTATE = rtb_TSamp;

          /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
           *  Gain: '<S136>/Depth Integral Gain'
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

       case brain_IN_IMU:
        /* During 'IMU': '<S7>:1873' */
        if (brain_U.RC_Source == 0.0) {
          /* Transition: '<S7>:1877' */
          /* Exit 'IMU': '<S7>:1873' */
          /* Entry 'Compass': '<S7>:1872' */
          brain_DWork.is_ControlledRC = brain_IN_Compass;
          brain_B.SubState = 1.0;
        } else {
          /* Simulink Function 'MaintainDepth': '<S7>:926' */
          brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
          brain_B.DesiredDepth1 = (real32_T)brain_U.RC_Depth;
          brain_DWork.StateFlowFunctionsMaintainDepth =
            brain_M->Timing.clockTick0 -
            brain_DWork.StateFlowFunctionsMaintainDep_k;
          brain_DWork.StateFlowFunctionsMaintainDep_k =
            brain_M->Timing.clockTick0;

          /* Sum: '<S38>/Add' */
          rtb_Add = (real_T)brain_B.DesiredDepth1 - (real_T)
            brain_B.CurrentDepth1;

          /* SampleTimeMath: '<S137>/TSamp' incorporates:
           *  Gain: '<S136>/Depth Derivative Gain'
           *
           * About '<S137>/TSamp':
           *  y = u * K where K = 1 / ( w * Ts )
           */
          rtb_TSamp = brain_P.Depth_Kd * rtb_Add / ((real_T)
            brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

          /* DataTypeConversion: '<S38>/Double To Int8' incorporates:
           *  DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator'
           *  Gain: '<S136>/Depth Proportional Gain'
           *  Sum: '<S136>/Sum'
           *  Sum: '<S137>/Diff'
           *  UnitDelay: '<S137>/UD'
           *
           * Block description for '<S137>/Diff':
           *
           *  Add in CPU
           *
           * Block description for '<S137>/UD':
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

          /* Update for UnitDelay: '<S137>/UD'
           * Block description for '<S137>/UD':
           *
           *  Store in Global RAM
           */
          brain_DWork.UD_DSTATE = rtb_TSamp;

          /* Update for DiscreteIntegrator: '<S136>/Depth Discrete-Time Integrator' incorporates:
           *  Gain: '<S136>/Depth Integral Gain'
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

          /* Simulink Function 'GoStraight': '<S7>:1860' */
          brain_B.YawRate = brain_B.YawRate_Out;
          brain_B.ForwardVelocity1_b = brain_B.YVel;
          brain_B.Y_Accel = brain_U.RC_ForwardVelocity;
          br_StateFlowFunctionsGoStraight(brain_B.YawRate,
            brain_B.ForwardVelocity1_b, brain_B.Y_Accel, brain_M,
            &brain_B.StateFlowFunctionsGoStraight,
            &brain_DWork.StateFlowFunctionsGoStraight);
          brain_B.Left = brain_B.StateFlowFunctionsGoStraight.DoubleToint8;
          brain_B.Right = brain_B.StateFlowFunctionsGoStraight.DoubleToint1;
          brain_B.Strafe = brain_B.StateFlowFunctionsGoStraight.DoubleToint2;
        }
        break;

       default:
        /* Transition: '<S7>:1875' */
        /* Entry 'Compass': '<S7>:1872' */
        brain_DWork.is_ControlledRC = brain_IN_Compass;
        brain_B.SubState = 1.0;
        break;
      }
    }
    break;

   case brain_IN_DropMechanism:
    /* During 'DropMechanism': '<S7>:1728' */
    if (brain_DWork.OperationalState != 6) {
      /* Transition: '<S7>:1730' */
      /* Exit 'DropMechanism': '<S7>:1728' */
      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      brain_B.SubState = 0.0;
    }
    break;

   case brain_IN_Finish:
    /* During 'Finish': '<S7>:1259' */
    if (brain_DWork.OperationalState != 9) {
      /* Transition: '<S7>:1282' */
      /* Exit 'Finish': '<S7>:1259' */
      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      brain_B.SubState = 0.0;
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
      brain_B.SubState = 0.0;
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
        brain_B.SubState = 1.0;

        /* Transition: '<S7>:1579' */
        /* Entry 'TurnLeft': '<S7>:1583' */
        brain_DWork.is_RecognizePath = brain_IN_TurnLeft;
        brain_DWork.temporalCounter_i1 = 0U;
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
      brain_B.SubState = 0.0;
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
      brain_B.SubState = 0.0;
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
            brain_DWork.DesiredHeadingCount = brain_DWork.DesiredHeadingCount +
              1.0;
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
    brain_B.SubState = 0.0;
    break;
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
  int32_T m;
  real32_T sum;
  int32_T k;
  int32_T outStep;
  int32_T inStep;
  int32_T n;
  int32_T o;
  real32_T Resize2_LineBuffer[480];

  /* S-Function (svipchromresamp): '<S5>/Chroma Resampling' incorporates:
   *  Inport: '<Root>/B'
   *  Inport: '<Root>/G'
   */
  outStep = 0;
  inStep = 0;
  for (n = 0; n < 320; n++) {
    o = inStep;
    for (m = 0; m < 240; m++) {
      k = m << 1;
      brain_B.ChromaResampling_o1[outStep + k] = brain_U.G[o];
      brain_B.ChromaResampling_o1[(outStep + k) + 1] = brain_U.G[o];
      k += 480;
      brain_B.ChromaResampling_o1[outStep + k] = brain_U.G[o];
      brain_B.ChromaResampling_o1[(outStep + k) + 1] = brain_U.G[o];
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
      brain_B.ChromaResampling_o2[outStep + k] = brain_U.B[o];
      brain_B.ChromaResampling_o2[(outStep + k) + 1] = brain_U.B[o];
      k += 480;
      brain_B.ChromaResampling_o2[outStep + k] = brain_U.B[o];
      brain_B.ChromaResampling_o2[(outStep + k) + 1] = brain_U.B[o];
      o++;
    }

    inStep += 240;
    outStep += 960;
  }

  /* S-Function (svipcolorconv): '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' incorporates:
   *  Inport: '<Root>/R'
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
    yDiff = (uint32_T)brain_U.R[outStep] - 16U;

    /* Red; 8192 in this equations is 0.5*2^14 or 2^13; adding 0.5  */
    /* before truncation will result in rounding */
    pos = (yDiff * 19077U + (uint32_T)brain_B.ChromaResampling_o2[outStep] *
           26149U) + 8192U;
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
    neg = (uint32_T)brain_B.ChromaResampling_o1[outStep] * 6419U + (uint32_T)
      brain_B.ChromaResampling_o2[outStep] * 13320U;
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
    pos = (yDiff * 19077U + (uint32_T)brain_B.ChromaResampling_o1[outStep] *
           33050U) + 8192U;
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
  for (m = 0; m < 480; m++) {
    outStep = m;
    for (n = 0; n < 160; n++) {
      o = n;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o1[brain_ConstP.pooled34[o] *
          480 + m] * brain_ConstP.pooled26[o];
        o += 160;
      }

      brain_DWork.Resize_IntBuffer[outStep] = sum;
      outStep += 480;
    }
  }

  for (n = 0; n < 160; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize_IntBuffer[n * 480]), 480U * sizeof(real32_T));
    for (m = 0; m < 120; m++) {
      o = m;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[o]] *
          brain_ConstP.pooled25[o];
        o += 120;
      }

      brain_B.Resize[inStep] = sum;
      inStep++;
    }
  }

  /* S-Function (svipresize): '<S5>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  inStep = 0;
  for (m = 0; m < 480; m++) {
    outStep = m;
    for (n = 0; n < 160; n++) {
      o = n;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o2[brain_ConstP.pooled34[o] *
          480 + m] * brain_ConstP.pooled26[o];
        o += 160;
      }

      brain_DWork.Resize1_IntBuffer[outStep] = sum;
      outStep += 480;
    }
  }

  for (n = 0; n < 160; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize1_IntBuffer[n * 480]), 480U * sizeof(real32_T));
    for (m = 0; m < 120; m++) {
      o = m;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[o]] *
          brain_ConstP.pooled25[o];
        o += 120;
      }

      brain_B.Resize1[inStep] = sum;
      inStep++;
    }
  }

  /* S-Function (svipresize): '<S5>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  inStep = 0;
  for (m = 0; m < 480; m++) {
    outStep = m;
    for (n = 0; n < 160; n++) {
      o = n;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += brain_B.RGBtoHSVColorSpaceConversion_o3[brain_ConstP.pooled34[o] *
          480 + m] * brain_ConstP.pooled26[o];
        o += 160;
      }

      brain_DWork.Resize2_IntBuffer[outStep] = sum;
      outStep += 480;
    }
  }

  for (n = 0; n < 160; n++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)
           (&brain_DWork.Resize2_IntBuffer[n * 480]), 480U * sizeof(real32_T));
    for (m = 0; m < 120; m++) {
      o = m;
      sum = 0.0F;
      for (k = 0; k < 8; k++) {
        sum += Resize2_LineBuffer[brain_ConstP.pooled33[o]] *
          brain_ConstP.pooled25[o];
        o += 120;
      }

      brain_B.Resize2[inStep] = sum;
      inStep++;
    }
  }

  /* Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Inport: '<Root>/RC'
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
   *  SubSystem: '<S7>/StateFlowFunctions.GoStraight'
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

    /* Entry 'StateEstimator': '<S7>:1998' */
    brain_DWork.is_active_StateEstimator = 1U;

    /* Transition: '<S7>:1999' */
    /* Entry 'CalcTare': '<S7>:2002' */
    brain_DWork.is_StateEstimator = brain_IN_CalcTare;
    brain_DWork.TareDone = 0.0;
    brain_enter_internal_CalcTare();

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
    brain_B.SubState = 0.0;
  } else {
    brain_StateEstimator();

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

        /* Transition: '<S7>:946' */
        /* Entry 'Start': '<S7>:1019' */
        brain_DWork.is_Autonomous = brain_IN_Start_m;
        brain_B.State = 1;

        /* Simulink Function 'Perform': '<S7>:1834' */
        brain_B.State1 = (real_T)brain_B.State;
        StateManagementRunningAutonomou(brain_B.State1,
          &brain_B.StateManagementRunningAutonom_j);
        brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
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
          brain_DWork.is_Running = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

          /* Exit 'ControlledRC': '<S7>:944' */
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

            /* Transition: '<S7>:946' */
            /* Entry 'Start': '<S7>:1019' */
            brain_DWork.is_Autonomous = brain_IN_Start_m;
            brain_B.State = 1;

            /* Simulink Function 'Perform': '<S7>:1834' */
            brain_B.State1 = (real_T)brain_B.State;
            StateManagementRunningAutonomou(brain_B.State1,
              &brain_B.StateManagementRunningAutonom_j);
            brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
          } else {
            brain_DWork.OperationalState = -1;
          }
          break;

         default:
          /* Transition: '<S7>:941' */
          /* Entry 'Autonomous': '<S7>:945' */
          brain_DWork.is_Running = brain_IN_Autonomous;

          /* Transition: '<S7>:946' */
          /* Entry 'Start': '<S7>:1019' */
          brain_DWork.is_Autonomous = brain_IN_Start_m;
          brain_B.State = 1;

          /* Simulink Function 'Perform': '<S7>:1834' */
          brain_B.State1 = (real_T)brain_B.State;
          StateManagementRunningAutonomou(brain_B.State1,
            &brain_B.StateManagementRunningAutonom_j);
          brain_DWork.Done = brain_B.StateManagementRunningAutonom_j.Done1;
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

    brain_StateFlowFunctions();
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

  /* Outport: '<Root>/Pitch' */
  brain_Y.Pitch = brain_B.Pitch;

  /* Outport: '<Root>/Roll' */
  brain_Y.Roll = brain_B.Roll;

  /* Outport: '<Root>/Yaw' */
  brain_Y.Yaw = brain_B.Yaw;

  /* Outport: '<Root>/XPos' */
  brain_Y.XPos = brain_B.X;

  /* Outport: '<Root>/YPos' */
  brain_Y.YPos = brain_B.Y;

  /* Outport: '<Root>/ZPos' */
  brain_Y.ZPos = brain_B.Z;

  /* Outport: '<Root>/XVel' */
  brain_Y.XVel = brain_B.XVel;

  /* Outport: '<Root>/YVel' */
  brain_Y.YVel = brain_B.YVel;

  /* Outport: '<Root>/ZVel' */
  brain_Y.ZVel = brain_B.ZVel;

  /* Outport: '<Root>/Pitch_Accel' */
  brain_Y.Pitch_Accel = brain_B.Pitch_Accel;

  /* Outport: '<Root>/Roll_Accel' */
  brain_Y.Roll_Accel = brain_B.Roll_Accel;

  /* Outport: '<Root>/Yaw_Accel' */
  brain_Y.Yaw_Accel = brain_B.Yaw_Accel;

  /* Outport: '<Root>/PitchRate_Out' */
  brain_Y.PitchRate_Out = brain_B.PitchRate_Out;

  /* Outport: '<Root>/RollRate_Out' */
  brain_Y.RollRate_Out = brain_B.RollRate_Out;

  /* Outport: '<Root>/YawRate_Out' */
  brain_Y.YawRate_Out = brain_B.YawRate_Out;

  /* Outport: '<Root>/SubState' */
  brain_Y.SubState = brain_B.SubState;

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
    brain_B.HoughTransform_o2[0] = -1.5707963267948966;
    brain_B.HoughTransform_o2[1] = -1.5533430342749532;
    brain_B.HoughTransform_o2[2] = -1.53588974175501;
    brain_B.HoughTransform_o2[3] = -1.5184364492350666;
    brain_B.HoughTransform_o2[4] = -1.5009831567151235;
    brain_B.HoughTransform_o2[5] = -1.4835298641951802;
    brain_B.HoughTransform_o2[6] = -1.4660765716752369;
    brain_B.HoughTransform_o2[7] = -1.4486232791552935;
    brain_B.HoughTransform_o2[8] = -1.4311699866353502;
    brain_B.HoughTransform_o2[9] = -1.4137166941154069;
    brain_B.HoughTransform_o2[10] = -1.3962634015954636;
    brain_B.HoughTransform_o2[11] = -1.3788101090755203;
    brain_B.HoughTransform_o2[12] = -1.3613568165555769;
    brain_B.HoughTransform_o2[13] = -1.3439035240356338;
    brain_B.HoughTransform_o2[14] = -1.3264502315156905;
    brain_B.HoughTransform_o2[15] = -1.3089969389957472;
    brain_B.HoughTransform_o2[16] = -1.2915436464758039;
    brain_B.HoughTransform_o2[17] = -1.2740903539558606;
    brain_B.HoughTransform_o2[18] = -1.2566370614359172;
    brain_B.HoughTransform_o2[19] = -1.2391837689159739;
    brain_B.HoughTransform_o2[20] = -1.2217304763960306;
    brain_B.HoughTransform_o2[21] = -1.2042771838760873;
    brain_B.HoughTransform_o2[22] = -1.1868238913561442;
    brain_B.HoughTransform_o2[23] = -1.1693705988362009;
    brain_B.HoughTransform_o2[24] = -1.1519173063162575;
    brain_B.HoughTransform_o2[25] = -1.1344640137963142;
    brain_B.HoughTransform_o2[26] = -1.1170107212763709;
    brain_B.HoughTransform_o2[27] = -1.0995574287564276;
    brain_B.HoughTransform_o2[28] = -1.0821041362364843;
    brain_B.HoughTransform_o2[29] = -1.064650843716541;
    brain_B.HoughTransform_o2[30] = -1.0471975511965976;
    brain_B.HoughTransform_o2[31] = -1.0297442586766545;
    brain_B.HoughTransform_o2[32] = -1.0122909661567112;
    brain_B.HoughTransform_o2[33] = -0.99483767363676789;
    brain_B.HoughTransform_o2[34] = -0.97738438111682457;
    brain_B.HoughTransform_o2[35] = -0.95993108859688125;
    brain_B.HoughTransform_o2[36] = -0.94247779607693793;
    brain_B.HoughTransform_o2[37] = -0.92502450355699462;
    brain_B.HoughTransform_o2[38] = -0.90757121103705141;
    brain_B.HoughTransform_o2[39] = -0.89011791851710809;
    brain_B.HoughTransform_o2[40] = -0.87266462599716477;
    brain_B.HoughTransform_o2[41] = -0.85521133347722145;
    brain_B.HoughTransform_o2[42] = -0.83775804095727824;
    brain_B.HoughTransform_o2[43] = -0.82030474843733492;
    brain_B.HoughTransform_o2[44] = -0.8028514559173916;
    brain_B.HoughTransform_o2[45] = -0.78539816339744828;
    brain_B.HoughTransform_o2[46] = -0.767944870877505;
    brain_B.HoughTransform_o2[47] = -0.75049157835756175;
    brain_B.HoughTransform_o2[48] = -0.73303828583761843;
    brain_B.HoughTransform_o2[49] = -0.71558499331767511;
    brain_B.HoughTransform_o2[50] = -0.69813170079773179;
    brain_B.HoughTransform_o2[51] = -0.68067840827778847;
    brain_B.HoughTransform_o2[52] = -0.66322511575784526;
    brain_B.HoughTransform_o2[53] = -0.64577182323790194;
    brain_B.HoughTransform_o2[54] = -0.62831853071795862;
    brain_B.HoughTransform_o2[55] = -0.6108652381980153;
    brain_B.HoughTransform_o2[56] = -0.59341194567807209;
    brain_B.HoughTransform_o2[57] = -0.57595865315812877;
    brain_B.HoughTransform_o2[58] = -0.55850536063818546;
    brain_B.HoughTransform_o2[59] = -0.54105206811824214;
    brain_B.HoughTransform_o2[60] = -0.52359877559829882;
    brain_B.HoughTransform_o2[61] = -0.50614548307835561;
    brain_B.HoughTransform_o2[62] = -0.48869219055841229;
    brain_B.HoughTransform_o2[63] = -0.47123889803846897;
    brain_B.HoughTransform_o2[64] = -0.4537856055185257;
    brain_B.HoughTransform_o2[65] = -0.43633231299858238;
    brain_B.HoughTransform_o2[66] = -0.41887902047863912;
    brain_B.HoughTransform_o2[67] = -0.4014257279586958;
    brain_B.HoughTransform_o2[68] = -0.38397243543875248;
    brain_B.HoughTransform_o2[69] = -0.36651914291880922;
    brain_B.HoughTransform_o2[70] = -0.3490658503988659;
    brain_B.HoughTransform_o2[71] = -0.33161255787892263;
    brain_B.HoughTransform_o2[72] = -0.31415926535897931;
    brain_B.HoughTransform_o2[73] = -0.29670597283903605;
    brain_B.HoughTransform_o2[74] = -0.27925268031909273;
    brain_B.HoughTransform_o2[75] = -0.26179938779914941;
    brain_B.HoughTransform_o2[76] = -0.24434609527920614;
    brain_B.HoughTransform_o2[77] = -0.22689280275926285;
    brain_B.HoughTransform_o2[78] = -0.20943951023931956;
    brain_B.HoughTransform_o2[79] = -0.19198621771937624;
    brain_B.HoughTransform_o2[80] = -0.17453292519943295;
    brain_B.HoughTransform_o2[81] = -0.15707963267948966;
    brain_B.HoughTransform_o2[82] = -0.13962634015954636;
    brain_B.HoughTransform_o2[83] = -0.12217304763960307;
    brain_B.HoughTransform_o2[84] = -0.10471975511965978;
    brain_B.HoughTransform_o2[85] = -0.087266462599716474;
    brain_B.HoughTransform_o2[86] = -0.069813170079773182;
    brain_B.HoughTransform_o2[87] = -0.05235987755982989;
    brain_B.HoughTransform_o2[88] = -0.034906585039886591;
    brain_B.HoughTransform_o2[89] = -0.017453292519943295;
    brain_B.HoughTransform_o2[90] = 0.0;
    brain_B.HoughTransform_o2[91] = 0.017453292519943295;
    brain_B.HoughTransform_o2[92] = 0.034906585039886591;
    brain_B.HoughTransform_o2[93] = 0.05235987755982989;
    brain_B.HoughTransform_o2[94] = 0.069813170079773182;
    brain_B.HoughTransform_o2[95] = 0.087266462599716474;
    brain_B.HoughTransform_o2[96] = 0.10471975511965978;
    brain_B.HoughTransform_o2[97] = 0.12217304763960307;
    brain_B.HoughTransform_o2[98] = 0.13962634015954636;
    brain_B.HoughTransform_o2[99] = 0.15707963267948966;
    brain_B.HoughTransform_o2[100] = 0.17453292519943295;
    brain_B.HoughTransform_o2[101] = 0.19198621771937624;
    brain_B.HoughTransform_o2[102] = 0.20943951023931956;
    brain_B.HoughTransform_o2[103] = 0.22689280275926285;
    brain_B.HoughTransform_o2[104] = 0.24434609527920614;
    brain_B.HoughTransform_o2[105] = 0.26179938779914941;
    brain_B.HoughTransform_o2[106] = 0.27925268031909273;
    brain_B.HoughTransform_o2[107] = 0.29670597283903605;
    brain_B.HoughTransform_o2[108] = 0.31415926535897931;
    brain_B.HoughTransform_o2[109] = 0.33161255787892263;
    brain_B.HoughTransform_o2[110] = 0.3490658503988659;
    brain_B.HoughTransform_o2[111] = 0.36651914291880922;
    brain_B.HoughTransform_o2[112] = 0.38397243543875248;
    brain_B.HoughTransform_o2[113] = 0.4014257279586958;
    brain_B.HoughTransform_o2[114] = 0.41887902047863912;
    brain_B.HoughTransform_o2[115] = 0.43633231299858238;
    brain_B.HoughTransform_o2[116] = 0.4537856055185257;
    brain_B.HoughTransform_o2[117] = 0.47123889803846897;
    brain_B.HoughTransform_o2[118] = 0.48869219055841229;
    brain_B.HoughTransform_o2[119] = 0.50614548307835561;
    brain_B.HoughTransform_o2[120] = 0.52359877559829882;
    brain_B.HoughTransform_o2[121] = 0.54105206811824214;
    brain_B.HoughTransform_o2[122] = 0.55850536063818546;
    brain_B.HoughTransform_o2[123] = 0.57595865315812877;
    brain_B.HoughTransform_o2[124] = 0.59341194567807209;
    brain_B.HoughTransform_o2[125] = 0.6108652381980153;
    brain_B.HoughTransform_o2[126] = 0.62831853071795862;
    brain_B.HoughTransform_o2[127] = 0.64577182323790194;
    brain_B.HoughTransform_o2[128] = 0.66322511575784526;
    brain_B.HoughTransform_o2[129] = 0.68067840827778847;
    brain_B.HoughTransform_o2[130] = 0.69813170079773179;
    brain_B.HoughTransform_o2[131] = 0.71558499331767511;
    brain_B.HoughTransform_o2[132] = 0.73303828583761843;
    brain_B.HoughTransform_o2[133] = 0.75049157835756175;
    brain_B.HoughTransform_o2[134] = 0.767944870877505;
    brain_B.HoughTransform_o2[135] = 0.78539816339744828;
    brain_B.HoughTransform_o2[136] = 0.8028514559173916;
    brain_B.HoughTransform_o2[137] = 0.82030474843733492;
    brain_B.HoughTransform_o2[138] = 0.83775804095727824;
    brain_B.HoughTransform_o2[139] = 0.85521133347722145;
    brain_B.HoughTransform_o2[140] = 0.87266462599716477;
    brain_B.HoughTransform_o2[141] = 0.89011791851710809;
    brain_B.HoughTransform_o2[142] = 0.90757121103705141;
    brain_B.HoughTransform_o2[143] = 0.92502450355699462;
    brain_B.HoughTransform_o2[144] = 0.94247779607693793;
    brain_B.HoughTransform_o2[145] = 0.95993108859688125;
    brain_B.HoughTransform_o2[146] = 0.97738438111682457;
    brain_B.HoughTransform_o2[147] = 0.99483767363676789;
    brain_B.HoughTransform_o2[148] = 1.0122909661567112;
    brain_B.HoughTransform_o2[149] = 1.0297442586766545;
    brain_B.HoughTransform_o2[150] = 1.0471975511965976;
    brain_B.HoughTransform_o2[151] = 1.064650843716541;
    brain_B.HoughTransform_o2[152] = 1.0821041362364843;
    brain_B.HoughTransform_o2[153] = 1.0995574287564276;
    brain_B.HoughTransform_o2[154] = 1.1170107212763709;
    brain_B.HoughTransform_o2[155] = 1.1344640137963142;
    brain_B.HoughTransform_o2[156] = 1.1519173063162575;
    brain_B.HoughTransform_o2[157] = 1.1693705988362009;
    brain_B.HoughTransform_o2[158] = 1.1868238913561442;
    brain_B.HoughTransform_o2[159] = 1.2042771838760873;
    brain_B.HoughTransform_o2[160] = 1.2217304763960306;
    brain_B.HoughTransform_o2[161] = 1.2391837689159739;
    brain_B.HoughTransform_o2[162] = 1.2566370614359172;
    brain_B.HoughTransform_o2[163] = 1.2740903539558606;
    brain_B.HoughTransform_o2[164] = 1.2915436464758039;
    brain_B.HoughTransform_o2[165] = 1.3089969389957472;
    brain_B.HoughTransform_o2[166] = 1.3264502315156905;
    brain_B.HoughTransform_o2[167] = 1.3439035240356338;
    brain_B.HoughTransform_o2[168] = 1.3613568165555769;
    brain_B.HoughTransform_o2[169] = 1.3788101090755203;
    brain_B.HoughTransform_o2[170] = 1.3962634015954636;
    brain_B.HoughTransform_o2[171] = 1.4137166941154069;
    brain_B.HoughTransform_o2[172] = 1.4311699866353502;
    brain_B.HoughTransform_o2[173] = 1.4486232791552935;
    brain_B.HoughTransform_o2[174] = 1.4660765716752369;
    brain_B.HoughTransform_o2[175] = 1.4835298641951802;
    brain_B.HoughTransform_o2[176] = 1.5009831567151235;
    brain_B.HoughTransform_o2[177] = 1.5184364492350666;
    brain_B.HoughTransform_o2[178] = 1.53588974175501;
    brain_B.HoughTransform_o2[179] = 1.5533430342749532;
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
    brain_B.HoughTransform_o2_e[0] = -1.5707963267948966;
    brain_B.HoughTransform_o2_e[1] = -1.5533430342749532;
    brain_B.HoughTransform_o2_e[2] = -1.53588974175501;
    brain_B.HoughTransform_o2_e[3] = -1.5184364492350666;
    brain_B.HoughTransform_o2_e[4] = -1.5009831567151235;
    brain_B.HoughTransform_o2_e[5] = -1.4835298641951802;
    brain_B.HoughTransform_o2_e[6] = -1.4660765716752369;
    brain_B.HoughTransform_o2_e[7] = -1.4486232791552935;
    brain_B.HoughTransform_o2_e[8] = -1.4311699866353502;
    brain_B.HoughTransform_o2_e[9] = -1.4137166941154069;
    brain_B.HoughTransform_o2_e[10] = -1.3962634015954636;
    brain_B.HoughTransform_o2_e[11] = -1.3788101090755203;
    brain_B.HoughTransform_o2_e[12] = -1.3613568165555769;
    brain_B.HoughTransform_o2_e[13] = -1.3439035240356338;
    brain_B.HoughTransform_o2_e[14] = -1.3264502315156905;
    brain_B.HoughTransform_o2_e[15] = -1.3089969389957472;
    brain_B.HoughTransform_o2_e[16] = -1.2915436464758039;
    brain_B.HoughTransform_o2_e[17] = -1.2740903539558606;
    brain_B.HoughTransform_o2_e[18] = -1.2566370614359172;
    brain_B.HoughTransform_o2_e[19] = -1.2391837689159739;
    brain_B.HoughTransform_o2_e[20] = -1.2217304763960306;
    brain_B.HoughTransform_o2_e[21] = -1.2042771838760873;
    brain_B.HoughTransform_o2_e[22] = -1.1868238913561442;
    brain_B.HoughTransform_o2_e[23] = -1.1693705988362009;
    brain_B.HoughTransform_o2_e[24] = -1.1519173063162575;
    brain_B.HoughTransform_o2_e[25] = -1.1344640137963142;
    brain_B.HoughTransform_o2_e[26] = -1.1170107212763709;
    brain_B.HoughTransform_o2_e[27] = -1.0995574287564276;
    brain_B.HoughTransform_o2_e[28] = -1.0821041362364843;
    brain_B.HoughTransform_o2_e[29] = -1.064650843716541;
    brain_B.HoughTransform_o2_e[30] = -1.0471975511965976;
    brain_B.HoughTransform_o2_e[31] = -1.0297442586766545;
    brain_B.HoughTransform_o2_e[32] = -1.0122909661567112;
    brain_B.HoughTransform_o2_e[33] = -0.99483767363676789;
    brain_B.HoughTransform_o2_e[34] = -0.97738438111682457;
    brain_B.HoughTransform_o2_e[35] = -0.95993108859688125;
    brain_B.HoughTransform_o2_e[36] = -0.94247779607693793;
    brain_B.HoughTransform_o2_e[37] = -0.92502450355699462;
    brain_B.HoughTransform_o2_e[38] = -0.90757121103705141;
    brain_B.HoughTransform_o2_e[39] = -0.89011791851710809;
    brain_B.HoughTransform_o2_e[40] = -0.87266462599716477;
    brain_B.HoughTransform_o2_e[41] = -0.85521133347722145;
    brain_B.HoughTransform_o2_e[42] = -0.83775804095727824;
    brain_B.HoughTransform_o2_e[43] = -0.82030474843733492;
    brain_B.HoughTransform_o2_e[44] = -0.8028514559173916;
    brain_B.HoughTransform_o2_e[45] = -0.78539816339744828;
    brain_B.HoughTransform_o2_e[46] = -0.767944870877505;
    brain_B.HoughTransform_o2_e[47] = -0.75049157835756175;
    brain_B.HoughTransform_o2_e[48] = -0.73303828583761843;
    brain_B.HoughTransform_o2_e[49] = -0.71558499331767511;
    brain_B.HoughTransform_o2_e[50] = -0.69813170079773179;
    brain_B.HoughTransform_o2_e[51] = -0.68067840827778847;
    brain_B.HoughTransform_o2_e[52] = -0.66322511575784526;
    brain_B.HoughTransform_o2_e[53] = -0.64577182323790194;
    brain_B.HoughTransform_o2_e[54] = -0.62831853071795862;
    brain_B.HoughTransform_o2_e[55] = -0.6108652381980153;
    brain_B.HoughTransform_o2_e[56] = -0.59341194567807209;
    brain_B.HoughTransform_o2_e[57] = -0.57595865315812877;
    brain_B.HoughTransform_o2_e[58] = -0.55850536063818546;
    brain_B.HoughTransform_o2_e[59] = -0.54105206811824214;
    brain_B.HoughTransform_o2_e[60] = -0.52359877559829882;
    brain_B.HoughTransform_o2_e[61] = -0.50614548307835561;
    brain_B.HoughTransform_o2_e[62] = -0.48869219055841229;
    brain_B.HoughTransform_o2_e[63] = -0.47123889803846897;
    brain_B.HoughTransform_o2_e[64] = -0.4537856055185257;
    brain_B.HoughTransform_o2_e[65] = -0.43633231299858238;
    brain_B.HoughTransform_o2_e[66] = -0.41887902047863912;
    brain_B.HoughTransform_o2_e[67] = -0.4014257279586958;
    brain_B.HoughTransform_o2_e[68] = -0.38397243543875248;
    brain_B.HoughTransform_o2_e[69] = -0.36651914291880922;
    brain_B.HoughTransform_o2_e[70] = -0.3490658503988659;
    brain_B.HoughTransform_o2_e[71] = -0.33161255787892263;
    brain_B.HoughTransform_o2_e[72] = -0.31415926535897931;
    brain_B.HoughTransform_o2_e[73] = -0.29670597283903605;
    brain_B.HoughTransform_o2_e[74] = -0.27925268031909273;
    brain_B.HoughTransform_o2_e[75] = -0.26179938779914941;
    brain_B.HoughTransform_o2_e[76] = -0.24434609527920614;
    brain_B.HoughTransform_o2_e[77] = -0.22689280275926285;
    brain_B.HoughTransform_o2_e[78] = -0.20943951023931956;
    brain_B.HoughTransform_o2_e[79] = -0.19198621771937624;
    brain_B.HoughTransform_o2_e[80] = -0.17453292519943295;
    brain_B.HoughTransform_o2_e[81] = -0.15707963267948966;
    brain_B.HoughTransform_o2_e[82] = -0.13962634015954636;
    brain_B.HoughTransform_o2_e[83] = -0.12217304763960307;
    brain_B.HoughTransform_o2_e[84] = -0.10471975511965978;
    brain_B.HoughTransform_o2_e[85] = -0.087266462599716474;
    brain_B.HoughTransform_o2_e[86] = -0.069813170079773182;
    brain_B.HoughTransform_o2_e[87] = -0.05235987755982989;
    brain_B.HoughTransform_o2_e[88] = -0.034906585039886591;
    brain_B.HoughTransform_o2_e[89] = -0.017453292519943295;
    brain_B.HoughTransform_o2_e[90] = 0.0;
    brain_B.HoughTransform_o2_e[91] = 0.017453292519943295;
    brain_B.HoughTransform_o2_e[92] = 0.034906585039886591;
    brain_B.HoughTransform_o2_e[93] = 0.05235987755982989;
    brain_B.HoughTransform_o2_e[94] = 0.069813170079773182;
    brain_B.HoughTransform_o2_e[95] = 0.087266462599716474;
    brain_B.HoughTransform_o2_e[96] = 0.10471975511965978;
    brain_B.HoughTransform_o2_e[97] = 0.12217304763960307;
    brain_B.HoughTransform_o2_e[98] = 0.13962634015954636;
    brain_B.HoughTransform_o2_e[99] = 0.15707963267948966;
    brain_B.HoughTransform_o2_e[100] = 0.17453292519943295;
    brain_B.HoughTransform_o2_e[101] = 0.19198621771937624;
    brain_B.HoughTransform_o2_e[102] = 0.20943951023931956;
    brain_B.HoughTransform_o2_e[103] = 0.22689280275926285;
    brain_B.HoughTransform_o2_e[104] = 0.24434609527920614;
    brain_B.HoughTransform_o2_e[105] = 0.26179938779914941;
    brain_B.HoughTransform_o2_e[106] = 0.27925268031909273;
    brain_B.HoughTransform_o2_e[107] = 0.29670597283903605;
    brain_B.HoughTransform_o2_e[108] = 0.31415926535897931;
    brain_B.HoughTransform_o2_e[109] = 0.33161255787892263;
    brain_B.HoughTransform_o2_e[110] = 0.3490658503988659;
    brain_B.HoughTransform_o2_e[111] = 0.36651914291880922;
    brain_B.HoughTransform_o2_e[112] = 0.38397243543875248;
    brain_B.HoughTransform_o2_e[113] = 0.4014257279586958;
    brain_B.HoughTransform_o2_e[114] = 0.41887902047863912;
    brain_B.HoughTransform_o2_e[115] = 0.43633231299858238;
    brain_B.HoughTransform_o2_e[116] = 0.4537856055185257;
    brain_B.HoughTransform_o2_e[117] = 0.47123889803846897;
    brain_B.HoughTransform_o2_e[118] = 0.48869219055841229;
    brain_B.HoughTransform_o2_e[119] = 0.50614548307835561;
    brain_B.HoughTransform_o2_e[120] = 0.52359877559829882;
    brain_B.HoughTransform_o2_e[121] = 0.54105206811824214;
    brain_B.HoughTransform_o2_e[122] = 0.55850536063818546;
    brain_B.HoughTransform_o2_e[123] = 0.57595865315812877;
    brain_B.HoughTransform_o2_e[124] = 0.59341194567807209;
    brain_B.HoughTransform_o2_e[125] = 0.6108652381980153;
    brain_B.HoughTransform_o2_e[126] = 0.62831853071795862;
    brain_B.HoughTransform_o2_e[127] = 0.64577182323790194;
    brain_B.HoughTransform_o2_e[128] = 0.66322511575784526;
    brain_B.HoughTransform_o2_e[129] = 0.68067840827778847;
    brain_B.HoughTransform_o2_e[130] = 0.69813170079773179;
    brain_B.HoughTransform_o2_e[131] = 0.71558499331767511;
    brain_B.HoughTransform_o2_e[132] = 0.73303828583761843;
    brain_B.HoughTransform_o2_e[133] = 0.75049157835756175;
    brain_B.HoughTransform_o2_e[134] = 0.767944870877505;
    brain_B.HoughTransform_o2_e[135] = 0.78539816339744828;
    brain_B.HoughTransform_o2_e[136] = 0.8028514559173916;
    brain_B.HoughTransform_o2_e[137] = 0.82030474843733492;
    brain_B.HoughTransform_o2_e[138] = 0.83775804095727824;
    brain_B.HoughTransform_o2_e[139] = 0.85521133347722145;
    brain_B.HoughTransform_o2_e[140] = 0.87266462599716477;
    brain_B.HoughTransform_o2_e[141] = 0.89011791851710809;
    brain_B.HoughTransform_o2_e[142] = 0.90757121103705141;
    brain_B.HoughTransform_o2_e[143] = 0.92502450355699462;
    brain_B.HoughTransform_o2_e[144] = 0.94247779607693793;
    brain_B.HoughTransform_o2_e[145] = 0.95993108859688125;
    brain_B.HoughTransform_o2_e[146] = 0.97738438111682457;
    brain_B.HoughTransform_o2_e[147] = 0.99483767363676789;
    brain_B.HoughTransform_o2_e[148] = 1.0122909661567112;
    brain_B.HoughTransform_o2_e[149] = 1.0297442586766545;
    brain_B.HoughTransform_o2_e[150] = 1.0471975511965976;
    brain_B.HoughTransform_o2_e[151] = 1.064650843716541;
    brain_B.HoughTransform_o2_e[152] = 1.0821041362364843;
    brain_B.HoughTransform_o2_e[153] = 1.0995574287564276;
    brain_B.HoughTransform_o2_e[154] = 1.1170107212763709;
    brain_B.HoughTransform_o2_e[155] = 1.1344640137963142;
    brain_B.HoughTransform_o2_e[156] = 1.1519173063162575;
    brain_B.HoughTransform_o2_e[157] = 1.1693705988362009;
    brain_B.HoughTransform_o2_e[158] = 1.1868238913561442;
    brain_B.HoughTransform_o2_e[159] = 1.2042771838760873;
    brain_B.HoughTransform_o2_e[160] = 1.2217304763960306;
    brain_B.HoughTransform_o2_e[161] = 1.2391837689159739;
    brain_B.HoughTransform_o2_e[162] = 1.2566370614359172;
    brain_B.HoughTransform_o2_e[163] = 1.2740903539558606;
    brain_B.HoughTransform_o2_e[164] = 1.2915436464758039;
    brain_B.HoughTransform_o2_e[165] = 1.3089969389957472;
    brain_B.HoughTransform_o2_e[166] = 1.3264502315156905;
    brain_B.HoughTransform_o2_e[167] = 1.3439035240356338;
    brain_B.HoughTransform_o2_e[168] = 1.3613568165555769;
    brain_B.HoughTransform_o2_e[169] = 1.3788101090755203;
    brain_B.HoughTransform_o2_e[170] = 1.3962634015954636;
    brain_B.HoughTransform_o2_e[171] = 1.4137166941154069;
    brain_B.HoughTransform_o2_e[172] = 1.4311699866353502;
    brain_B.HoughTransform_o2_e[173] = 1.4486232791552935;
    brain_B.HoughTransform_o2_e[174] = 1.4660765716752369;
    brain_B.HoughTransform_o2_e[175] = 1.4835298641951802;
    brain_B.HoughTransform_o2_e[176] = 1.5009831567151235;
    brain_B.HoughTransform_o2_e[177] = 1.5184364492350666;
    brain_B.HoughTransform_o2_e[178] = 1.53588974175501;
    brain_B.HoughTransform_o2_e[179] = 1.5533430342749532;
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
     *  Start for SubSystem: '<S7>/StateFlowFunctions.GoStraight'
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

    /* Start for Constant: '<S40>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity_o = brain_P.Heading_Forward_Velocity;

    /* Start for Constant: '<S26>/Constant' */
    brain_B.Constant = brain_P.Track_Desired_Depth;

    /* Start for S-Function (svipmorphop): '<S99>/Erosion' */
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

    /* Start for S-Function (svipmorphop): '<S28>/Dilation' */
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 2; n++) {
      for (m = 0; m < 2; m++) {
        if (brain_ConstP.pooled36[idxNHood]) {
          brain_DWork.Dilation_DILATE_OFF_DW[idxOffsets] = n * 123 + m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW = curNumNonZ;

    /* Start for S-Function (svipmorphop): '<S28>/Erosion' */
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

    /* Start for S-Function (svipmorphop): '<S35>/Erosion' */
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

    /* Start for Constant: '<S34>/Hedge Hue' */
    brain_B.HedgeHue = brain_P.Hedge_Hue;

    /* Start for Constant: '<S34>/Hedge Saturation' */
    brain_B.HedgeSaturation = brain_P.Hedge_Saturation;

    /* Start for Constant: '<S34>/Hedge Value' */
    brain_B.HedgeValue = brain_P.Hedge_Value;
    StateFlowFunctionsJumpH_a_Start(brain_M,
      &brain_DWork.StateFlowFunctionsJumpHedgeCa_p);

    /* Start for Constant: '<S31>/Heading Forward Velocity' */
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
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.GoStraight'
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
  brain_DWork.is_active_StateEstimator = 0U;
  brain_DWork.is_StateEstimator = 0U;
  brain_DWork.is_CalcTare = 0U;
  brain_DWork.is_active_StateFlowFunctions = 0U;
  brain_DWork.is_StateFlowFunctions = 0U;
  brain_DWork.is_Breach = 0U;
  brain_DWork.is_Buoys = 0U;
  brain_DWork.is_ApproachBuoys = 0U;
  brain_DWork.is_ControlledRC = 0U;
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
  memset((void *)(&brain_DWork.LabelMatrix[0]), 0, 19200U * sizeof(real_T));
  brain_DWork.TurnDirection = 0.0;
  brain_DWork.count2ndarea = 0.0;
  brain_DWork.num_colors = 0.0;
  memset((void *)(&brain_DWork.ref_colors[0]), 0, 150U * sizeof(real_T));
  brain_DWork.num_blobs = 0.0;
  memset((void *)(&brain_DWork.BuoyBlobs[0]), 0, 200U * sizeof(real_T));
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
  brain_DWork.OldPitch = 0.0;
  brain_DWork.OldRoll = 0.0;
  brain_DWork.OldX = 0.0;
  brain_DWork.OldXVel = 0.0;
  brain_DWork.OldY = 0.0;
  brain_DWork.OldYVel = 0.0;
  brain_DWork.OldYaw = 0.0;
  brain_DWork.OldYawRate = 0.0;
  brain_DWork.OldZ = 0.0;
  brain_DWork.OldZVel = 0.0;
  brain_DWork.TPA = 0.0;
  brain_DWork.TRA = 0.0;
  brain_DWork.TYA = 0.0;
  brain_DWork.stepcount = 0.0;
  brain_DWork.TarPitch = 0.0;
  brain_DWork.TarPitchRate = 0.0;
  brain_DWork.TarRoll = 0.0;
  brain_DWork.TarRollRate = 0.0;
  brain_DWork.TarYaw = 0.0;
  brain_DWork.TarYawRate = 0.0;
  brain_DWork.TareDone = 0.0;
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
  memset((void *)(&brain_B.BWout[0]), 0, 19200U * sizeof(real_T));
  memset((void *)(&brain_B.RGBout[0]), 0, 57600U * sizeof(real_T));
  brain_B.Pitch = 0.0;
  brain_B.Roll = 0.0;
  brain_B.Yaw = 0.0;
  brain_B.X = 0.0;
  brain_B.Y = 0.0;
  brain_B.Z = 0.0;
  brain_B.XVel = 0.0;
  brain_B.YVel = 0.0;
  brain_B.ZVel = 0.0;
  brain_B.Pitch_Accel = 0.0;
  brain_B.Roll_Accel = 0.0;
  brain_B.Yaw_Accel = 0.0;
  brain_B.PitchRate_Out = 0.0;
  brain_B.RollRate_Out = 0.0;
  brain_B.YawRate_Out = 0.0;
  brain_B.SubState = 0.0;
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
  StateFlowFunctionsGoStraig_Init(brain_M,
    &brain_DWork.StateFlowFunctionsGoStraight);

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
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.GoStraight'
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
