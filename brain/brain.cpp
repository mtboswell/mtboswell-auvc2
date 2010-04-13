/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.317
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Apr 13 14:33:46 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Apr 13 14:33:46 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/Chart' */
#define brain_IN_ApproachBuoy          (1)
#define brain_IN_Autonomous            (1)
#define brain_IN_BackupAndMoveUp       (1)
#define brain_IN_Buoy                  (1)
#define brain_IN_CenterOver            (1)
#define brain_IN_ChooseState           (2)
#define brain_IN_ControlledRC          (2)
#define brain_IN_Done                  (2)
#define brain_IN_FindBuoy              (2)
#define brain_IN_Finish                (3)
#define brain_IN_FinishedwithBuoy      (2)
#define brain_IN_FollowOnePath         (4)
#define brain_IN_FollowOnePath1        (5)
#define brain_IN_GetDirections         (3)
#define brain_IN_GoAroundBuoy          (3)
#define brain_IN_Initialize            (1)
#define brain_IN_MoveForward           (3)
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
static void brain_max_g(const real_T eml_varargin_1[80], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max(const real_T eml_varargin_1[120], real_T *eml_maxval,
                      real_T *eml_indx);
static void brain_c10_brain(const real_T rtu_HSVImage[57600],
  rtB_GetBrightestPixelPerColumna *localB);

/* Forward declaration for local functions */
static void brain_max_n(const real_T eml_varargin_1[51660], real_T eml_maxval
  [180], real_T eml_indx[180]);
static void brain_max_nh(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);

/* Forward declaration for local functions */
static void brain_max_b(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx);

/* Forward declaration for local functions */
static void brain_enter_internal_OnePath(void);
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT);
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong);
static void brain_OnePath(void);
static void bra_exit_internal_FollowOnePath(void);
static void brain_enter_internal_OnePath_m(void);
static void brain_GetAvgDesHeading_m(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT);
static void brain_ChoosePath_m(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong);
static void brain_OnePath_m(void);
static void br_exit_internal_FollowOnePath1(void);
static void brain_FollowOnePath1(void);
static real_T brain_InitialHeadingCount(real_T sf_CurrentHeading1, real_T
  sf_OldHeading1, real_T sf_count1);
static void brain_ValidationGate(void);
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

/* Output and update for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOnePathM(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_RunningAutonomousFollowOneP
  *localB)
{
  {
    int32_T i;

    /* Embedded MATLAB: '<S11>/PutHSVImageTogether' */
    /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S43>:1' */
    /*  This function simply makes an HSV image a single multidimensional */
    /*  signal */
    /* '<S43>:1:7' */
    memset(&localB->HSVImage1[0], (uint32_T)0.0, 57600U * sizeof(real_T));

    /* '<S43>:1:9' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[120 * i]), (void *)(&rtu_H1[120 * i]),
             120U * sizeof(real_T));
    }

    /* '<S43>:1:10' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[19200 + 120 * i]), (void *)(&rtu_S1[120
              * i]), 120U * sizeof(real_T));
    }

    /* '<S43>:1:11' */
    for (i = 0; i < 160; i++) {
      memcpy((void *)(&localB->HSVImage1[38400 + 120 * i]), (void *)(&rtu_V1[120
              * i]), 120U * sizeof(real_T));
    }
  }
}

/* Output and update for atomic system:
 *   '<S9>/Embedded MATLAB Function1'
 *   '<S12>/Embedded MATLAB Function1'
 *   '<S16>/Embedded MATLAB Function1'
 */
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB)
{
  /* Embedded MATLAB: '<S9>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1': '<S31>:1' */
  /*  This function finds the center of an image */
  /* '<S31>:1:6' */
  localB->XCenter = 80.0;

  /* '<S31>:1:7' */
  localB->YCenter = 60.0;
}

/* Disable for action system:
 *   '<S8>/BigError S1'
 *   '<S20>/BigError S1'
 */
void brain_BigErrorS1_Disable(rtB_BigErrorS1_brain *localB)
{
  /* Disable for Outport: '<S23>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S8>/BigError S1'
 *   '<S20>/BigError S1'
 */
void brain_BigErrorS1(real_T rtu_In1, rtB_BigErrorS1_brain *localB)
{
  /* Sum: '<S23>/Add' incorporates:
   *  Constant: '<S23>/Constant'
   */
  localB->Add = rtu_In1 - 360.0;

  /* Constant: '<S23>/Constant1' */
  localB->Constant1 = 1.0;
}

/* Disable for action system:
 *   '<S8>/BigNegativeError S2'
 *   '<S20>/BigNegativeError S2'
 */
void brai_BigNegativeErrorS2_Disable(rtB_BigNegativeErrorS2_brain *localB)
{
  /* Disable for Outport: '<S24>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S8>/BigNegativeError S2'
 *   '<S20>/BigNegativeError S2'
 */
void brain_BigNegativeErrorS2(real_T rtu_In1, rtB_BigNegativeErrorS2_brain
  *localB)
{
  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/Constant'
   */
  localB->Add = rtu_In1 + 360.0;

  /* Constant: '<S24>/Constant1' */
  localB->Constant1 = 2.0;
}

/* Initial conditions for function-call system: '<Root>/Chart' */
void brain_MaintainHeading_Init(RT_MODEL_brain *brain_M,
  rtDW_MaintainHeading_brain *localDW)
{
  localDW->MaintainHeading_PREV_T = brain_M->Timing.clockTick0;
}

/* Disable for function-call system: '<Root>/Chart' */
void brain_MaintainHeading_Disable(rtB_MaintainHeading_brain *localB,
  rtDW_MaintainHeading_brain *localDW)
{
  /* Disable for If: '<S8>/If' */
  localDW->If_ActiveSubsystem = -1;
  brain_BigErrorS1_Disable(&localB->BigErrorS1);
  brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);

  /* Disable for ifaction SubSystem: '<S8>/BigError S1' */
  brain_BigErrorS1_Disable(&localB->BigErrorS1);

  /* end of Disable for SubSystem: '<S8>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S8>/BigNegativeError S2' */
  brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);

  /* end of Disable for SubSystem: '<S8>/BigNegativeError S2' */
}

/* Start for function-call system: '<Root>/Chart' */
void brain_MaintainHeading_Start(RT_MODEL_brain *brain_M,
  rtDW_MaintainHeading_brain *localDW)
{
  /* Start for If: '<S8>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/* Output and update for function-call system: '<Root>/Chart' */
void brain_MaintainHeading(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *brain_M,
  rtB_MaintainHeading_brain *localB, rtDW_MaintainHeading_brain *localDW)
{
  /* local block i/o variables */
  real_T rtb_Add1;
  real_T rtb_TSamp_g;
  real_T rtb_Add4;

  {
    int8_T rtPrevAction;
    int8_T rtAction;
    real_T rtb_MultiportSwitch;
    real_T rtb_HeadingProportionalGain;
    localDW->MaintainHeading_ELAPS_T = brain_M->Timing.clockTick0 -
      localDW->MaintainHeading_PREV_T;
    localDW->MaintainHeading_PREV_T = brain_M->Timing.clockTick0;

    /* Sum: '<S8>/Add1' */
    rtb_Add1 = rtu_DesiredHeading1 - rtu_CurrentHeading1;

    /* If: '<S8>/If' incorporates:
     *  ActionPort: '<S23>/Action Port'
     *  ActionPort: '<S24>/Action Port'
     *  SubSystem: '<S8>/BigError S1'
     *  SubSystem: '<S8>/BigNegativeError S2'
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
        brain_BigErrorS1_Disable(&localB->BigErrorS1);
        break;

       case 1:
        brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);
        break;
      }
    }

    switch (rtAction) {
     case 0:
      brain_BigErrorS1(rtb_Add1, &localB->BigErrorS1);
      break;

     case 1:
      brain_BigNegativeErrorS2(rtb_Add1, &localB->BigNegativeErrorS2);
      break;
    }

    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Sum: '<S8>/Add2'
     */
    switch ((int32_T)((1.0 + localB->BigErrorS1.Constant1) +
                      localB->BigNegativeErrorS2.Constant1)) {
     case 1:
      rtb_MultiportSwitch = rtb_Add1;
      break;

     case 2:
      rtb_MultiportSwitch = localB->BigErrorS1.Add;
      break;

     default:
      rtb_MultiportSwitch = localB->BigNegativeErrorS2.Add;
      break;
    }

    /* Gain: '<S25>/Heading Proportional Gain' */
    rtb_HeadingProportionalGain = brain_P.StraightLevelControl.Heading_Kp *
      rtb_MultiportSwitch;

    /* Gain: '<S25>/Heading Derivative Gain' */
    rtb_Add4 = brain_P.StraightLevelControl.Heading_Kd * rtb_MultiportSwitch;

    /* S-Function (sfix_tsampmath): '<S26>/TSamp' */

    /* Sample Time Math Block: '<S26>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_g = rtb_Add4 / (((localDW->MaintainHeading_ELAPS_T * 0.2))*(1.0));

    /* DiscreteIntegrator: '<S25>/Heading Discrete-Time Integrator' */
    rtb_Add4 = localDW->HeadingDiscreteTimeIntegrator_D;

    /* Sum: '<S25>/Sum' incorporates:
     *  Sum: '<S26>/Diff'
     *  UnitDelay: '<S26>/UD'
     *
     * Block description for '<S26>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S26>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Add4 += (rtb_TSamp_g - localDW->UD_DSTATE) + rtb_HeadingProportionalGain;

    /* Product: '<S8>/Multiply' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_HeadingProportionalGain = -rtb_Add4;
    if (rtIsNaN(rtb_HeadingProportionalGain) || rtIsInf
        (rtb_HeadingProportionalGain)) {
      rtb_HeadingProportionalGain = 0.0;
    } else {
      rtb_HeadingProportionalGain = fmod(floor(rtb_HeadingProportionalGain),
        256.0);
    }

    /* Sum: '<S8>/Add4' */
    rtb_Add4 += rtu_ForwardVelocity1;

    /* DataTypeConversion: '<S8>/DoubleToint1' incorporates:
     *  Sum: '<S8>/Add3'
     */
    rtb_HeadingProportionalGain = floor((real_T)(rtb_HeadingProportionalGain <
      0.0 ? (int8_T)(-((int8_T)(uint8_T)(-rtb_HeadingProportionalGain))) :
      (int8_T)(uint8_T)rtb_HeadingProportionalGain) + rtu_ForwardVelocity1);
    if (rtb_HeadingProportionalGain < 128.0) {
      if (rtb_HeadingProportionalGain >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    localB->DoubleToint1 = rtPrevAction;

    /* DataTypeConversion: '<S8>/DoubleToint8' */
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

    localB->DoubleToint8 = rtPrevAction;

    /* Update for UnitDelay: '<S26>/UD'
     * Block description for '<S26>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE = rtb_TSamp_g;

    /* Update for DiscreteIntegrator: '<S25>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S25>/Heading Integral Gain'
     */
    localDW->HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
      localDW->MaintainHeading_ELAPS_T
      * (brain_P.StraightLevelControl.Heading_Ki * rtb_MultiportSwitch) +
      localDW->HeadingDiscreteTimeIntegrator_D;
    if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
    } else {
      if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
        localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_max_g(const real_T eml_varargin_1[80], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
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

/* Function for Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
static void brain_c10_brain(const real_T rtu_HSVImage[57600],
  rtB_GetBrightestPixelPerColumna *localB)
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

  /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S56>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S56>:1:8' */
  /* '<S56>:1:10' */
  /* '<S56>:1:11' */
  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    eml_BWleft[eml_x_0] = 0;
    eml_BWright[eml_x_0] = 0;
  }

  /* '<S56>:1:14' */
  /* '<S56>:1:16' */
  for (eml_x_0 = 0; eml_x_0 < 160; eml_x_0++) {
    for (tmp = 0; tmp < 120; tmp++) {
      eml_hoistedExpr[tmp + 120 * eml_x_0] = rtu_HSVImage[120 * eml_x_0 + tmp] *
        6.2831853071795862E+00 - 3.1415926535897931E-01;
    }
  }

  brain_refp1_cos(eml_hoistedExpr);
  for (eml_x_0 = 0; eml_x_0 < 19200; eml_x_0++) {
    eml_hoistedExpr[eml_x_0] = (eml_hoistedExpr[eml_x_0] + 1.0) / 2.0;
  }

  /*  Left half */
  for (eml_x = 0; eml_x < 80; eml_x++) {
    /* '<S56>:1:19' */
    /* '<S56>:1:20' */
    memcpy((void *)&eml_hoistedExpr_0[0], (void *)&eml_hoistedExpr[120 * eml_x],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_0, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (rtu_HSVImage[(((int32_T)eml_indexH - 1) + 120 *
          eml_x) + 19200] > 0.3)) {
      /* '<S56>:1:21' */
      /* '<S56>:1:22' */
      eml_BWleft[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S56>:1:26' */
    /* '<S56>:1:27' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_1[eml_x_0] = eml_hoistedExpr[120 * eml_x_0 + eml_x];
    }

    brain_max_g(eml_hoistedExpr_1, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (rtu_HSVImage[(((int32_T)eml_indexH - 1) * 120 +
          eml_x) + 19200] > 0.3)) {
      /* '<S56>:1:28' */
      /* '<S56>:1:29' */
      eml_BWleft[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  /*  Right half */
  for (eml_x = 81; eml_x < 161; eml_x++) {
    /* '<S56>:1:34' */
    /* '<S56>:1:35' */
    eml_x_0 = eml_x - 1;
    memcpy((void *)&eml_hoistedExpr_2[0], (void *)&eml_hoistedExpr[120 * eml_x_0],
           120U * sizeof(real_T));
    brain_max(eml_hoistedExpr_2, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (rtu_HSVImage[((eml_x - 1) * 120 + ((int32_T)
           eml_indexH - 1)) + 19200] > 0.3)) {
      /* '<S56>:1:36' */
      /* '<S56>:1:37' */
      eml_BWright[((int32_T)eml_indexH - 1) + 120 * (eml_x - 81)] = 1;
    }
  }

  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S56>:1:41' */
    /* '<S56>:1:42' */
    for (eml_x_0 = 0; eml_x_0 < 80; eml_x_0++) {
      eml_hoistedExpr_3[eml_x_0] = eml_hoistedExpr[(80 + eml_x_0) * 120 + eml_x];
    }

    brain_max_g(eml_hoistedExpr_3, &eml_valueH, &eml_indexH);
    if ((eml_valueH > 0.5) && (rtu_HSVImage[(((int32_T)eml_indexH - 1) * 120 +
          eml_x) + 19200] > 0.3)) {
      /* '<S56>:1:43' */
      /* '<S56>:1:44' */
      eml_BWright[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (eml_x_0 = 0; eml_x_0 < 9600; eml_x_0++) {
    localB->BWleft[eml_x_0] = (real_T)eml_BWleft[eml_x_0];
    localB->BWright[eml_x_0] = (real_T)eml_BWright[eml_x_0];
  }
}

/* Output and update for atomic system:
 *   '<S55>/Get Brightest Pixel Per Column and Row'
 *   '<S74>/Get Brightest Pixel Per Column and Row'
 */
void GetBrightestPixelPerColumnandRo(const real_T rtu_HSVImage[57600],
  rtB_GetBrightestPixelPerColumna *localB)
{
  /* Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
  brain_c10_brain(rtu_HSVImage, localB);
}

/* Output and update for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOnePathO(const real_T rtu_HSV1[57600],
  rtB_RunningAutonomousFollowOn_b *localB)
{
  {
    int32_T i;

    /* Embedded MATLAB: '<S55>/Get Brightest Pixel Per Column and Row' */
    GetBrightestPixelPerColumnandRo(rtu_HSV1,
      &localB->sf_GetBrightestPixelPerColumnan);
    for (i = 0; i < 9600; i++) {
      /* DataTypeConversion: '<S55>/Data Type Conversion' */
      localB->BWleft[i] = (localB->sf_GetBrightestPixelPerColumnan.BWleft[i] !=
                           0.0);

      /* DataTypeConversion: '<S55>/Data Type Conversion1' */
      localB->BWright[i] = (localB->sf_GetBrightestPixelPerColumnan.BWright[i]
                            != 0.0);
    }
  }
}

/* Function for Embedded MATLAB: '<S58>/IsLinePresent' */
static void brain_max_n(const real_T eml_varargin_1[51660], real_T eml_maxval
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

/* Function for Embedded MATLAB: '<S58>/IsLinePresent' */
static void brain_max_nh(const real_T eml_varargin_1[180], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S58>/IsLinePresent' */
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

  /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent': '<S60>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S60>:1:5' */
  /* '<S60>:1:7' */
  /* '<S60>:1:9' */
  /* '<S60>:1:10' */
  /* '<S60>:1:11' */
  /* '<S60>:1:12' */
  /* '<S60>:1:13' */
  localB->Rho[0] = -999.0;
  localB->Theta[0] = -999.0;
  localB->maxVotes[0] = -999.0;
  localB->Rho[1] = -999.0;
  localB->Theta[1] = -999.0;
  localB->maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S60>:1:15' */
  /* '<S60>:1:17' */
  brain_max_n(&rtu_HoughTable[0], eml_maxValues, eml_RhoIndices);

  /* '<S60>:1:18' */
  brain_max_nh(eml_maxValues, &eml_b, &eml_c);

  /* '<S60>:1:18' */
  localB->maxVotes[0] = eml_b;

  /* '<S60>:1:18' */
  eml_ThetaIndex_idx = eml_c;

  /* '<S60>:1:19' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_c - 1];
  if (localB->maxVotes[0] >= 15.0) {
    /* '<S60>:1:21' */
    /* '<S60>:1:22' */
    eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 287 * ((int32_T)eml_c - 1)]
      = 0.0;

    /* '<S60>:1:24' */
    eml_index = 2;

    /* '<S60>:1:25' */
    eml_count = 0;
    while ((eml_index <= 2) && (eml_count < 12)) {
      /* '<S60>:1:26' */
      /* '<S60>:1:27' */
      eml_count++;

      /* '<S60>:1:28' */
      brain_max_n(eml_HoughTable, eml_maxValues, eml_RhoIndices);

      /* '<S60>:1:29' */
      brain_max_nh(eml_maxValues, &eml_b, &eml_c);

      /* '<S60>:1:29' */
      localB->maxVotes[1] = eml_b;

      /* '<S60>:1:29' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S60>:1:30' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S60>:1:32' */
      eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 287 * ((int32_T)eml_c -
        1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S60>:1:34' */
        /* '<S60>:1:35' */
        eml_index = 3;
      }
    }

    /* '<S60>:1:40' */
    if (localB->maxVotes[0] > 15.0) {
      /* '<S60>:1:41' */
      /* '<S60>:1:42' */
      localB->Theta[0] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx - 1];

      /* '<S60>:1:43' */
      localB->Rho[0] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx - 1];
      if ((localB->Theta[0] > 0.0) && (localB->Rho[0] < 0.0)) {
        /* '<S60>:1:44' */
        /* '<S60>:1:45' */
        localB->Rho[0] = localB->Rho[0] * -1.0;
      }
    }

    /* '<S60>:1:40' */
    if (localB->maxVotes[1] > 15.0) {
      /* '<S60>:1:41' */
      /* '<S60>:1:42' */
      localB->Theta[1] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx_0 - 1];

      /* '<S60>:1:43' */
      localB->Rho[1] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx_0 - 1];
      if ((localB->Theta[1] > 0.0) && (localB->Rho[1] < 0.0)) {
        /* '<S60>:1:44' */
        /* '<S60>:1:45' */
        localB->Rho[1] = localB->Rho[1] * -1.0;
      }
    }
  }
}

/* Output and update for atomic system:
 *   '<S58>/IsLinePresent'
 *   '<S59>/IsLinePresent'
 *   '<S77>/IsLinePresent'
 *   '<S78>/IsLinePresent'
 */
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  /* Embedded MATLAB: '<S58>/IsLinePresent' */
  brain_c11_brain(rtu_HoughTable, rtu_ThetaValues, rtu_RhoValues, localB);
}

/* Function for Embedded MATLAB: '<S14>/GetHeadingToPath' */
static void brain_max_b(const real_T eml_varargin_1[4], real_T *eml_maxval,
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

/* Output and update for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOnePat_o(const boolean_T rtu_BWleft1[9600], const
  boolean_T rtu_BWright1[9600], real_T rtu_CurrentHeading1,
  rtB_RunningAutonomousFollowOn_o *localB)
{
  {
    real_T eml_Votes[4];
    real_T eml_b;
    real_T eml_c;
    real_T rtb_TmpHiddenBufferAtSFunctionI[4];
    real_T rtb_TmpHiddenBufferAtSFunctio_l[4];
    real_T eml_maxIndex_idx;

    /* S-Function (sviphough): '<S58>/Hough Transform' */
    MWVIP_Hough_D(&rtu_BWleft1[0], &localB->HoughTransform_o1[0],
                  &brain_ConstP.pooled12[0], &brain_ConstP.pooled13, 120, 80,
                  287, 91);

    /* Embedded MATLAB: '<S58>/IsLinePresent' */
    brain_IsLinePresent(localB->HoughTransform_o1, localB->HoughTransform_o2,
                        localB->HoughTransform_o3, &localB->sf_IsLinePresent);

    /* S-Function (sviphough): '<S59>/Hough Transform' */
    MWVIP_Hough_D(&rtu_BWright1[0], &localB->HoughTransform_o1_d[0],
                  &brain_ConstP.pooled12[0], &brain_ConstP.pooled13, 120, 80,
                  287, 91);

    /* Embedded MATLAB: '<S59>/IsLinePresent' */
    brain_IsLinePresent(localB->HoughTransform_o1_d, localB->HoughTransform_o2_m,
                        localB->HoughTransform_o3_k, &localB->sf_IsLinePresent_j);

    /* SignalConversion: '<S57>/TmpHiddenBufferAt SFunction Inport1' */
    rtb_TmpHiddenBufferAtSFunctionI[0] = localB->sf_IsLinePresent.Theta[0];
    rtb_TmpHiddenBufferAtSFunctionI[1] = localB->sf_IsLinePresent.Theta[1];

    /* SignalConversion: '<S57>/TmpHiddenBufferAt SFunction Inport3' */
    rtb_TmpHiddenBufferAtSFunctionI[2] = localB->sf_IsLinePresent_j.Theta[0];
    rtb_TmpHiddenBufferAtSFunctio_l[0] = localB->sf_IsLinePresent.maxVotes[0];
    rtb_TmpHiddenBufferAtSFunctionI[3] = localB->sf_IsLinePresent_j.Theta[1];
    rtb_TmpHiddenBufferAtSFunctio_l[1] = localB->sf_IsLinePresent.maxVotes[1];
    rtb_TmpHiddenBufferAtSFunctio_l[2] = localB->sf_IsLinePresent_j.maxVotes[0];
    rtb_TmpHiddenBufferAtSFunctio_l[3] = localB->sf_IsLinePresent_j.maxVotes[1];

    /* Embedded MATLAB: '<S14>/GetHeadingToPath' */
    eml_Votes[0] = rtb_TmpHiddenBufferAtSFunctio_l[0];
    eml_Votes[1] = rtb_TmpHiddenBufferAtSFunctio_l[1];
    eml_Votes[2] = rtb_TmpHiddenBufferAtSFunctio_l[2];
    eml_Votes[3] = rtb_TmpHiddenBufferAtSFunctio_l[3];

    /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath': '<S57>:1' */
    /*  This function calculates the heading to the path from Theta and Rho */
    /* '<S57>:1:4' */
    /* '<S57>:1:6' */
    /* '<S57>:1:7' */
    /* '<S57>:1:8' */
    localB->ToPathHeading[0] = -999.0;
    localB->AlongPathHeading[0] = -999.0;
    localB->ToPathHeading[1] = -999.0;
    localB->AlongPathHeading[1] = -999.0;

    /* '<S57>:1:11' */
    brain_max_b(rtb_TmpHiddenBufferAtSFunctio_l, &eml_b, &eml_c);

    /* '<S57>:1:11' */
    eml_maxIndex_idx = eml_c;

    /* '<S57>:1:12' */
    eml_Votes[(int32_T)eml_c - 1] = 0.0;

    /* '<S57>:1:13' */
    /* '<S57>:1:15' */
    /* '<S57>:1:16' */
    /* '<S57>:1:17' */
    brain_max_b(eml_Votes, &eml_b, &eml_c);

    /* '<S57>:1:17' */
    /* '<S57>:1:18' */
    /* '<S57>:1:21' */
    if (eml_maxIndex_idx <= 2.0) {
      /* '<S57>:1:22' */
      if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex_idx - 1] >
           -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
           eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
        /* '<S57>:1:23' */
        /* '<S57>:1:24' */
        localB->ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
          rtu_CurrentHeading1) - 90.0;

        /* '<S57>:1:25' */
        localB->AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
          rtu_CurrentHeading1;
      }
    } else {
      if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_maxIndex_idx - 1] >
           -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
           eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
        /* '<S57>:1:28' */
        /* '<S57>:1:29' */
        localB->ToPathHeading[0] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
          rtu_CurrentHeading1) + 90.0;

        /* '<S57>:1:30' */
        localB->AlongPathHeading[0] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
          rtu_CurrentHeading1;
      }
    }

    /* '<S57>:1:35' */
    if (localB->ToPathHeading[0] != -999.0) {
      /* '<S57>:1:36' */
      if (localB->ToPathHeading[0] < 0.0) {
        /* '<S57>:1:37' */
        /* '<S57>:1:38' */
        localB->ToPathHeading[0] = localB->ToPathHeading[0] + 360.0;
      } else {
        if (localB->ToPathHeading[0] > 360.0) {
          /* '<S57>:1:39' */
          /* '<S57>:1:40' */
          localB->ToPathHeading[0] = localB->ToPathHeading[0] - 360.0;
        }
      }

      if (localB->AlongPathHeading[0] < 0.0) {
        /* '<S57>:1:43' */
        /* '<S57>:1:44' */
        localB->AlongPathHeading[0] = localB->AlongPathHeading[0] + 360.0;
      } else {
        if (localB->AlongPathHeading[0] > 360.0) {
          /* '<S57>:1:45' */
          /* '<S57>:1:46' */
          localB->AlongPathHeading[0] = localB->AlongPathHeading[0] - 360.0;
        }
      }
    }

    /* '<S57>:1:21' */
    if (eml_c <= 2.0) {
      /* '<S57>:1:22' */
      if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_c - 1] >
           -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
           eml_c - 1] < 1.5707963267948966E+00)) {
        /* '<S57>:1:23' */
        /* '<S57>:1:24' */
        localB->ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) -
          90.0;

        /* '<S57>:1:25' */
        localB->AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
      }
    } else {
      if ((rtb_TmpHiddenBufferAtSFunctionI[(int32_T)eml_c - 1] >
           -1.5707963267948966E+00) && (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
           eml_c - 1] < 1.5707963267948966E+00)) {
        /* '<S57>:1:28' */
        /* '<S57>:1:29' */
        localB->ToPathHeading[1] = (rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) +
          90.0;

        /* '<S57>:1:30' */
        localB->AlongPathHeading[1] = rtb_TmpHiddenBufferAtSFunctionI[(int32_T)
          eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
      }
    }

    /* '<S57>:1:35' */
    if (localB->ToPathHeading[1] != -999.0) {
      /* '<S57>:1:36' */
      if (localB->ToPathHeading[1] < 0.0) {
        /* '<S57>:1:37' */
        /* '<S57>:1:38' */
        localB->ToPathHeading[1] = localB->ToPathHeading[1] + 360.0;
      } else {
        if (localB->ToPathHeading[1] > 360.0) {
          /* '<S57>:1:39' */
          /* '<S57>:1:40' */
          localB->ToPathHeading[1] = localB->ToPathHeading[1] - 360.0;
        }
      }

      if (localB->AlongPathHeading[1] < 0.0) {
        /* '<S57>:1:43' */
        /* '<S57>:1:44' */
        localB->AlongPathHeading[1] = localB->AlongPathHeading[1] + 360.0;
      } else {
        if (localB->AlongPathHeading[1] > 360.0) {
          /* '<S57>:1:45' */
          /* '<S57>:1:46' */
          localB->AlongPathHeading[1] = localB->AlongPathHeading[1] - 360.0;
        }
      }
    }
  }
}

/* Initial conditions for function-call system: '<Root>/Chart' */
void brain_StraightLevelControl_Init(RT_MODEL_brain *brain_M,
  rtDW_StraightLevelControl_brain *localDW)
{
  localDW->StraightLevelControl_PREV_T = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S91>/UD'
   * Block description for '<S91>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Depth Discrete-Time Integrator' */
  localDW->DepthDiscreteTimeIntegrator_DST = 0.0;

  /* InitializeConditions for UnitDelay: '<S92>/UD'
   * Block description for '<S92>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_e = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S90>/Heading Discrete-Time Integrator' */
  localDW->HeadingDiscreteTimeIntegrator_D = 0.0;
}

/* Disable for function-call system: '<Root>/Chart' */
void br_StraightLevelControl_Disable(rtB_StraightLevelControl_brain *localB,
  rtDW_StraightLevelControl_brain *localDW)
{
  /* Disable for If: '<S20>/If' */
  localDW->If_ActiveSubsystem = -1;
  brain_BigErrorS1_Disable(&localB->BigErrorS1);
  brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);

  /* Disable for ifaction SubSystem: '<S20>/BigError S1' */
  brain_BigErrorS1_Disable(&localB->BigErrorS1);

  /* end of Disable for SubSystem: '<S20>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S20>/BigNegativeError S2' */
  brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);

  /* end of Disable for SubSystem: '<S20>/BigNegativeError S2' */
}

/* Start for function-call system: '<Root>/Chart' */
void brai_StraightLevelControl_Start(RT_MODEL_brain *brain_M,
  rtDW_StraightLevelControl_brain *localDW)
{
  /* Start for If: '<S20>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/* Output and update for function-call system: '<Root>/Chart' */
void brain_StraightLevelControl(real32_T rtu_DesiredDepth, real32_T
  rtu_CurrentDepth, real_T rtu_DesiredHeading, real_T rtu_CurrentHeading,
  RT_MODEL_brain *brain_M, rtB_StraightLevelControl_brain *localB,
  rtDW_StraightLevelControl_brain *localDW, rtP_StraightLevelControl_brain
  *localP)
{
  /* local block i/o variables */
  real_T rtb_TSamp_b;
  real_T rtb_Add1_g;
  real_T rtb_TSamp_l;
  real_T rtb_MultiportSwitch_j;
  real_T rtb_Add4_f;

  {
    real_T rtb_DepthProportionalGain;
    int8_T rtPrevAction;
    int8_T rtAction;
    real_T rtb_HeadingProportionalGain_g;
    if (localDW->StraightLevelControl_RESET_ELAP) {
      localDW->StraightLevelControl_ELAPS_T = 0U;
      localDW->StraightLevelControl_RESET_ELAP = false;
    } else {
      localDW->StraightLevelControl_ELAPS_T = brain_M->Timing.clockTick0 -
        localDW->StraightLevelControl_PREV_T;
    }

    localDW->StraightLevelControl_PREV_T = brain_M->Timing.clockTick0;

    /* Sum: '<S20>/Add' */
    rtb_Add4_f = (real_T)rtu_DesiredDepth - (real_T)rtu_CurrentDepth;

    /* Gain: '<S89>/Depth Proportional Gain' */
    rtb_DepthProportionalGain = localP->Depth_Kp * rtb_Add4_f;

    /* Gain: '<S89>/Depth Derivative Gain' */
    rtb_MultiportSwitch_j = localP->Depth_Kd * rtb_Add4_f;

    /* S-Function (sfix_tsampmath): '<S91>/TSamp' */

    /* Sample Time Math Block: '<S91>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_b = rtb_MultiportSwitch_j /
      (((localDW->StraightLevelControl_ELAPS_T * 0.2))*(1.0));

    /* DiscreteIntegrator: '<S89>/Depth Discrete-Time Integrator' */
    rtb_MultiportSwitch_j = localDW->DepthDiscreteTimeIntegrator_DST;

    /* Sum: '<S89>/Sum' incorporates:
     *  Sum: '<S91>/Diff'
     *  UnitDelay: '<S91>/UD'
     *
     * Block description for '<S91>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S91>/UD':
     *
     *  Store in Global RAM
     */
    rtb_MultiportSwitch_j += (rtb_TSamp_b - localDW->UD_DSTATE) +
      rtb_DepthProportionalGain;

    /* DataTypeConversion: '<S20>/Double To Int8' */
    rtb_HeadingProportionalGain_g = floor(rtb_MultiportSwitch_j);
    if (rtb_HeadingProportionalGain_g < 128.0) {
      if (rtb_HeadingProportionalGain_g >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_g;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    localB->DoubleToInt8 = rtPrevAction;

    /* Gain: '<S89>/Depth Integral Gain' */
    rtb_DepthProportionalGain = localP->Depth_Ki * rtb_Add4_f;

    /* Sum: '<S20>/Add1' */
    rtb_Add1_g = rtu_DesiredHeading - rtu_CurrentHeading;

    /* If: '<S20>/If' incorporates:
     *  ActionPort: '<S87>/Action Port'
     *  ActionPort: '<S88>/Action Port'
     *  SubSystem: '<S20>/BigError S1'
     *  SubSystem: '<S20>/BigNegativeError S2'
     */
    rtPrevAction = localDW->If_ActiveSubsystem;
    rtAction = -1;
    if (rtb_Add1_g > 180.0) {
      rtAction = 0;
    } else {
      if (rtb_Add1_g < -180.0) {
        rtAction = 1;
      }
    }

    localDW->If_ActiveSubsystem = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
       case 0:
        brain_BigErrorS1_Disable(&localB->BigErrorS1);
        break;

       case 1:
        brai_BigNegativeErrorS2_Disable(&localB->BigNegativeErrorS2);
        break;
      }
    }

    switch (rtAction) {
     case 0:
      brain_BigErrorS1(rtb_Add1_g, &localB->BigErrorS1);
      break;

     case 1:
      brain_BigNegativeErrorS2(rtb_Add1_g, &localB->BigNegativeErrorS2);
      break;
    }

    /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
     *  Constant: '<S20>/Constant1'
     *  Sum: '<S20>/Add2'
     */
    switch ((int32_T)((1.0 + localB->BigErrorS1.Constant1) +
                      localB->BigNegativeErrorS2.Constant1)) {
     case 1:
      rtb_MultiportSwitch_j = rtb_Add1_g;
      break;

     case 2:
      rtb_MultiportSwitch_j = localB->BigErrorS1.Add;
      break;

     default:
      rtb_MultiportSwitch_j = localB->BigNegativeErrorS2.Add;
      break;
    }

    /* Gain: '<S90>/Heading Proportional Gain' */
    rtb_HeadingProportionalGain_g = localP->Heading_Kp * rtb_MultiportSwitch_j;

    /* Gain: '<S90>/Heading Derivative Gain' */
    rtb_Add4_f = localP->Heading_Kd * rtb_MultiportSwitch_j;

    /* S-Function (sfix_tsampmath): '<S92>/TSamp' */

    /* Sample Time Math Block: '<S92>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_l = rtb_Add4_f / (((localDW->StraightLevelControl_ELAPS_T * 0.2))*
                                (1.0));

    /* DiscreteIntegrator: '<S90>/Heading Discrete-Time Integrator' */
    rtb_Add4_f = localDW->HeadingDiscreteTimeIntegrator_D;

    /* Sum: '<S90>/Sum' incorporates:
     *  Sum: '<S92>/Diff'
     *  UnitDelay: '<S92>/UD'
     *
     * Block description for '<S92>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S92>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Add4_f += (rtb_TSamp_l - localDW->UD_DSTATE_e) +
      rtb_HeadingProportionalGain_g;

    /* Product: '<S20>/Multiply' incorporates:
     *  Constant: '<S20>/Constant'
     */
    rtb_HeadingProportionalGain_g = -rtb_Add4_f;
    if (rtIsNaN(rtb_HeadingProportionalGain_g) || rtIsInf
        (rtb_HeadingProportionalGain_g)) {
      rtb_HeadingProportionalGain_g = 0.0;
    } else {
      rtb_HeadingProportionalGain_g = fmod(floor(rtb_HeadingProportionalGain_g),
        256.0);
    }

    /* Sum: '<S20>/Add4' incorporates:
     *  Constant: '<S20>/Heading_Forward_Velocity'
     */
    rtb_Add4_f += localP->Heading_Forward_Velocity;

    /* DataTypeConversion: '<S20>/DoubleToint1' incorporates:
     *  Constant: '<S20>/Heading_Forward_Velocity1'
     *  Sum: '<S20>/Add3'
     */
    rtb_HeadingProportionalGain_g = (real_T)(rtb_HeadingProportionalGain_g < 0.0
      ? (int8_T)(-((int8_T)(uint8_T)(-rtb_HeadingProportionalGain_g))) : (int8_T)
      (uint8_T)rtb_HeadingProportionalGain_g) + localP->Heading_Forward_Velocity;
    rtb_HeadingProportionalGain_g = floor(rtb_HeadingProportionalGain_g);
    if (rtb_HeadingProportionalGain_g < 128.0) {
      if (rtb_HeadingProportionalGain_g >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_g;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    localB->DoubleToint1 = rtPrevAction;

    /* DataTypeConversion: '<S20>/DoubleToint8' */
    rtb_HeadingProportionalGain_g = floor(rtb_Add4_f);
    if (rtb_HeadingProportionalGain_g < 128.0) {
      if (rtb_HeadingProportionalGain_g >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_g;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    localB->DoubleToint8 = rtPrevAction;

    /* Update for UnitDelay: '<S91>/UD'
     * Block description for '<S91>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE = rtb_TSamp_b;

    /* Update for DiscreteIntegrator: '<S89>/Depth Discrete-Time Integrator' */
    localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      localDW->StraightLevelControl_ELAPS_T * rtb_DepthProportionalGain +
      localDW->DepthDiscreteTimeIntegrator_DST;
    if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
        localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }

    /* Update for UnitDelay: '<S92>/UD'
     * Block description for '<S92>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE_e = rtb_TSamp_l;

    /* Update for DiscreteIntegrator: '<S90>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S90>/Heading Integral Gain'
     */
    localDW->HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
      localDW->StraightLevelControl_ELAPS_T * (localP->Heading_Ki *
      rtb_MultiportSwitch_j) + localDW->HeadingDiscreteTimeIntegrator_D;
    if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
    } else {
      if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
        localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
      }
    }
  }
}

/* Initial conditions for function-call system: '<Root>/Chart' */
void brain_MaintainDepth_Init(RT_MODEL_brain *brain_M, rtDW_MaintainDepth_brain *
  localDW)
{
  localDW->MaintainDepth_PREV_T = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/Chart' */
void brain_MaintainDepth(real32_T rtu_DesiredDepth1, real32_T rtu_CurrentDepth1,
  RT_MODEL_brain *brain_M, rtB_MaintainDepth_brain *localB,
  rtDW_MaintainDepth_brain *localDW)
{
  /* local block i/o variables */
  real_T rtb_TSamp_ly;
  real_T rtb_Sum_a;

  {
    real_T rtb_Add;
    real_T rtb_DepthProportionalGain_e;
    int8_T tmp;
    localDW->MaintainDepth_ELAPS_T = brain_M->Timing.clockTick0 -
      localDW->MaintainDepth_PREV_T;
    localDW->MaintainDepth_PREV_T = brain_M->Timing.clockTick0;

    /* Sum: '<S7>/Add' */
    rtb_Add = (real_T)rtu_DesiredDepth1 - (real_T)rtu_CurrentDepth1;

    /* Gain: '<S21>/Depth Proportional Gain' */
    rtb_DepthProportionalGain_e = brain_P.StraightLevelControl.Depth_Kp *
      rtb_Add;

    /* Gain: '<S21>/Depth Derivative Gain' */
    rtb_Sum_a = brain_P.StraightLevelControl.Depth_Kd * rtb_Add;

    /* S-Function (sfix_tsampmath): '<S22>/TSamp' */

    /* Sample Time Math Block: '<S22>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_ly = rtb_Sum_a / (((localDW->MaintainDepth_ELAPS_T * 0.2))*(1.0));

    /* DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator' */
    rtb_Sum_a = localDW->DepthDiscreteTimeIntegrator_DST;

    /* Sum: '<S21>/Sum' incorporates:
     *  Sum: '<S22>/Diff'
     *  UnitDelay: '<S22>/UD'
     *
     * Block description for '<S22>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S22>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Sum_a += (rtb_TSamp_ly - localDW->UD_DSTATE) +
      rtb_DepthProportionalGain_e;

    /* DataTypeConversion: '<S7>/Double To Int8' */
    rtb_DepthProportionalGain_e = floor(rtb_Sum_a);
    if (rtb_DepthProportionalGain_e < 128.0) {
      if (rtb_DepthProportionalGain_e >= -128.0) {
        tmp = (int8_T)rtb_DepthProportionalGain_e;
      } else {
        tmp = MIN_int8_T;
      }
    } else {
      tmp = MAX_int8_T;
    }

    localB->DoubleToInt8 = tmp;

    /* Update for UnitDelay: '<S22>/UD'
     * Block description for '<S22>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE = rtb_TSamp_ly;

    /* Update for DiscreteIntegrator: '<S21>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S21>/Depth Integral Gain'
     */
    localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      localDW->MaintainDepth_ELAPS_T * (brain_P.StraightLevelControl.Depth_Ki *
      rtb_Add) + localDW->DepthDiscreteTimeIntegrator_DST;
    if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
        localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }
  }
}

/* Initial conditions for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowO_l_Init(RT_MODEL_brain *brain_M,
  rtDW_RunningAutonomousFollowO_p *localDW)
{
  localDW->RunningAutonomousFollowOnePat_e = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system:
 *   '<Root>/Chart'
 *   '<Root>/Chart'
 */
void RunningAutonomousFollowOnePa_oc(const real_T rtu_H[19200], const real_T
  rtu_S[19200], RT_MODEL_brain *brain_M, rtB_RunningAutonomousFollowO_bx *localB,
  rtDW_RunningAutonomousFollowO_p *localDW)
{
  /* local block i/o variables */
  real_T rtb_TSamp_gc;
  real_T rtb_TSamp_o;
  real_T rtb_Sum_m;
  real_T rtb_Error_b;

  {
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
    real_T rtb_BlobCentroidX;
    real_T rtb_BlobCentroidY;
    real_T rtb_XBuoyIntegralGain_d;
    int32_T rtb_BuoyBlobAnalysis_o1_m[10];
    real_T rtb_BuoyBlobAnalysis_o2_c[20];
    int32_T i;
    int8_T tmp;
    localDW->RunningAutonomousFollowOnePat_a = brain_M->Timing.clockTick0 -
      localDW->RunningAutonomousFollowOnePat_e;
    localDW->RunningAutonomousFollowOnePat_e = brain_M->Timing.clockTick0;
    for (i = 0; i < 19200; i++) {
      /* RelationalOperator: '<S44>/Compare' incorporates:
       *  Constant: '<S44>/Constant'
       */
      localB->LogicalOperator[i] = (rtu_H[i] > brain_P.Track_HueHigher);

      /* RelationalOperator: '<S45>/Compare' incorporates:
       *  Constant: '<S45>/Constant'
       */
      localB->Compare[i] = (rtu_H[i] <= brain_P.Track_HueLower);

      /* Logic: '<S12>/Logical Operator' */
      localB->LogicalOperator[i] = (localB->LogicalOperator[i] ||
        localB->Compare[i]);

      /* RelationalOperator: '<S46>/Compare' incorporates:
       *  Constant: '<S46>/Constant'
       */
      localB->Compare[i] = (rtu_S[i] > brain_P.Track_Saturation);

      /* Logic: '<S12>/Logical Operator1' */
      localB->BW[i] = (localB->LogicalOperator[i] && localB->Compare[i]);
    }

    /* S-Function (svipblob): '<S12>/Buoy Blob Analysis' */
    maxNumBlobsReached = false;
    for (i = 0; i < 123; i++) {
      localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
    }

    currentLabel = 1U;
    i = 0;
    idx = 123;
    for (n = 0; n < 160; n++) {
      for (n_0 = 0; n_0 < 120; n_0++) {
        localDW->BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 :
          0);
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
              walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled21[i];
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
    i = 0;
    n_0 = 0;
    for (idx = 0; idx < (int32_T)numBlobs; idx++) {
      rtb_BuoyBlobAnalysis_o1_m[idx] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
      n = 0;
      ms = 0;
      for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx]; j++) {
        n += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + n_0];
        ms += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + i];
      }

      rtb_BuoyBlobAnalysis_o2_c[idx << 1] = (real_T)ms / (real_T)
        BuoyBlobAnalysis_NUM_PIX_DW[idx];
      rtb_BuoyBlobAnalysis_o2_c[(idx << 1) + 1] = (real_T)n / (real_T)
        BuoyBlobAnalysis_NUM_PIX_DW[idx];
      i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
      n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
    }

    for (i = (int32_T)numBlobs; i < 10; i++) {
      rtb_BuoyBlobAnalysis_o1_m[i] = -1;
    }

    for (i = (int32_T)numBlobs << 1; i < 20; i++) {
      rtb_BuoyBlobAnalysis_o2_c[i] = -1.0;
    }

    /* Embedded MATLAB: '<S12>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function': '<S47>:1' */
    /*  This function will choose and return data about the largest blob given a  */
    /*  set of blobs */
    if ((rtb_BuoyBlobAnalysis_o2_c[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_c[1] ==
         -1.0)) {
      /* '<S47>:1:5' */
      /* '<S47>:1:7' */
      rtb_BlobCentroidX = 80.0;

      /* '<S47>:1:8' */
      rtb_BlobCentroidY = 60.0;
    } else {
      /* '<S47>:1:11' */
      i = rtb_BuoyBlobAnalysis_o1_m[0];
      n = 1;
      n_0 = 1;
      for (idx = 2; idx < 11; idx++) {
        n_0++;
        if (rtb_BuoyBlobAnalysis_o1_m[n_0 - 1] > i) {
          i = rtb_BuoyBlobAnalysis_o1_m[n_0 - 1];
          n = idx;
        }
      }

      /* '<S47>:1:12' */
      rtb_BlobCentroidX = rtb_BuoyBlobAnalysis_o2_c[((n - 1) << 1) + 1];

      /* '<S47>:1:13' */
      rtb_BlobCentroidY = rtb_BuoyBlobAnalysis_o2_c[(n - 1) << 1];
    }

    /* Embedded MATLAB: '<S12>/Embedded MATLAB Function1' */
    brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

    /* Sum: '<S12>/Subtract' */
    localB->Subtract = rtb_BlobCentroidX -
      localB->sf_EmbeddedMATLABFunction1.XCenter;

    /* Sum: '<S12>/Subtract1' */
    localB->Subtract1 = rtb_BlobCentroidY -
      localB->sf_EmbeddedMATLABFunction1.YCenter;

    /* Sum: '<S49>/Subtract' */
    rtb_Sum_m = rtb_BlobCentroidX - localB->sf_EmbeddedMATLABFunction1.XCenter;

    /* Gain: '<S51>/X-Buoy Proportional Gain' */
    rtb_BlobCentroidX = brain_P.Cam_Down_XPos_Kp * rtb_Sum_m;

    /* Gain: '<S51>/X-Buoy Derivative Gain' */
    rtb_Error_b = brain_P.Cam_Down_XPos_Kd * rtb_Sum_m;

    /* S-Function (sfix_tsampmath): '<S52>/TSamp' */

    /* Sample Time Math Block: '<S52>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_gc = rtb_Error_b / (((localDW->RunningAutonomousFollowOnePat_a *
      0.2))*(1.0));

    /* DiscreteIntegrator: '<S51>/X-Buoy Discrete-Time Integrator' */
    rtb_Error_b = localDW->XBuoyDiscreteTimeIntegrator_DST;

    /* Sum: '<S51>/Sum' incorporates:
     *  Sum: '<S52>/Diff'
     *  UnitDelay: '<S52>/UD'
     *
     * Block description for '<S52>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S52>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Error_b += (rtb_TSamp_gc - localDW->UD_DSTATE) + rtb_BlobCentroidX;

    /* DataTypeConversion: '<S49>/Data Type Conversion' */
    rtb_BlobCentroidX = floor(rtb_Error_b);
    if (rtb_BlobCentroidX < 128.0) {
      if (rtb_BlobCentroidX >= -128.0) {
        tmp = (int8_T)rtb_BlobCentroidX;
      } else {
        tmp = MIN_int8_T;
      }
    } else {
      tmp = MAX_int8_T;
    }

    localB->DataTypeConversion = tmp;

    /* Gain: '<S51>/X-Buoy Integral Gain' */
    rtb_XBuoyIntegralGain_d = brain_P.Cam_Down_XPos_Ki * rtb_Sum_m;

    /* Sum: '<S50>/Subtract' */
    rtb_Error_b = localB->sf_EmbeddedMATLABFunction1.YCenter - rtb_BlobCentroidY;

    /* Gain: '<S53>/Y-Buoy Proportional Gain' */
    rtb_BlobCentroidX = brain_P.Cam_Down_YPos_Kp * rtb_Error_b;

    /* Gain: '<S53>/Y-Buoy Derivative Gain' */
    rtb_Sum_m = brain_P.Cam_Down_YPos_Kd * rtb_Error_b;

    /* S-Function (sfix_tsampmath): '<S54>/TSamp' */

    /* Sample Time Math Block: '<S54>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_o = rtb_Sum_m / (((localDW->RunningAutonomousFollowOnePat_a * 0.2))*
                               (1.0));

    /* DiscreteIntegrator: '<S53>/Y-Buoy Discrete-Time Integrator' */
    rtb_Sum_m = localDW->YBuoyDiscreteTimeIntegrator_DST;

    /* Sum: '<S53>/Sum' incorporates:
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
    rtb_Sum_m += (rtb_TSamp_o - localDW->UD_DSTATE_b) + rtb_BlobCentroidX;

    /* DataTypeConversion: '<S50>/Data Type Conversion' */
    rtb_BlobCentroidX = floor(rtb_Sum_m);
    if (rtb_BlobCentroidX < 128.0) {
      if (rtb_BlobCentroidX >= -128.0) {
        tmp = (int8_T)rtb_BlobCentroidX;
      } else {
        tmp = MIN_int8_T;
      }
    } else {
      tmp = MAX_int8_T;
    }

    localB->DataTypeConversion_b = tmp;

    /* Update for UnitDelay: '<S52>/UD'
     * Block description for '<S52>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE = rtb_TSamp_gc;

    /* Update for DiscreteIntegrator: '<S51>/X-Buoy Discrete-Time Integrator' */
    localDW->XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      localDW->RunningAutonomousFollowOnePat_a * rtb_XBuoyIntegralGain_d +
      localDW->XBuoyDiscreteTimeIntegrator_DST;
    if (localDW->XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
      localDW->XBuoyDiscreteTimeIntegrator_DST = 15.0;
    } else {
      if (localDW->XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
        localDW->XBuoyDiscreteTimeIntegrator_DST = -15.0;
      }
    }

    /* Update for UnitDelay: '<S54>/UD'
     * Block description for '<S54>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE_b = rtb_TSamp_o;

    /* Update for DiscreteIntegrator: '<S53>/Y-Buoy Discrete-Time Integrator' incorporates:
     *  Gain: '<S53>/Y-Buoy Integral Gain'
     */
    localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      localDW->RunningAutonomousFollowOnePat_a * (brain_P.Cam_Down_YPos_Ki *
      rtb_Error_b) + localDW->YBuoyDiscreteTimeIntegrator_DST;
    if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
    } else {
      if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
        localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
      }
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

/* Function for Stateflow: '<Root>/Chart' */
static void brain_OnePath(void)
{
  real_T sf_AvgDesHeading[2];
  real_T sf_ErrorX;
  real_T sf_ErrorY;
  int32_T i;

  /* During 'OnePath': '<S1>:328' */
  switch (brain_DWork.is_OnePath) {
   case brain_IN_CenterOver:
    /* During 'CenterOver': '<S1>:484' */
    if (brain_DWork.Error < 10.0) {
      /* Transition: '<S1>:485' */
      /* Exit 'CenterOver': '<S1>:484' */
      /* Entry 'Done': '<S1>:369' */
      brain_DWork.is_OnePath = (uint8_T)brain_IN_Done;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'CenterOver': '<S1>:491' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o34[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o35[i] = (real_T)brain_B.Resize1[i];
      }

      RunningAutonomousFollowOnePa_oc(brain_B.SFunction_o34,
        brain_B.SFunction_o35, brain_M, &brain_B.RunningAutonomousFollowOneP_oc4,
        &brain_DWork.RunningAutonomousFollowOneP_oc4);
      brain_B.Strafe =
        brain_B.RunningAutonomousFollowOneP_oc4.DataTypeConversion;
      i = (int32_T)brain_B.RunningAutonomousFollowOneP_oc4.DataTypeConversion_b;
      sf_ErrorX = brain_B.RunningAutonomousFollowOneP_oc4.Subtract1;
      sf_ErrorY = brain_B.RunningAutonomousFollowOneP_oc4.Subtract;

      /* Simulink Function 'MaintainDepth': '<S1>:464' */
      brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o33 = (real32_T)brain_B.DesiredDepth;
      brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32, brain_M,
                          &brain_B.MaintainDepth, &brain_DWork.MaintainDepth);
      brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S1>:458' */
      brain_B.SFunction_o19 = brain_B.DesiredHeading;
      brain_B.SFunction_o20 = brain_U.CurrentHeading;
      brain_B.SFunction_o21 = (real_T)i;
      brain_MaintainHeading(brain_B.SFunction_o19, brain_B.SFunction_o20,
                            brain_B.SFunction_o21, brain_M,
                            &brain_B.MaintainHeading,
                            &brain_DWork.MaintainHeading);
      brain_B.Left = brain_B.MaintainHeading.DoubleToint8;
      brain_B.Right = brain_B.MaintainHeading.DoubleToint1;

      /* Embedded MATLAB Function 'CalcError': '<S1>:512' */
      /*  This function calculates the error between the center of the screen and  */
      /*  the centroid of the orange/red blob */
      /* '<S1>:512:5' */
      brain_DWork.Error = fabs(sf_ErrorX - sf_ErrorY);
    }
    break;

   case brain_IN_Done:
    break;

   case brain_IN_GetDirections:
    /* During 'GetDirections': '<S1>:332' */
    if (brain_DWork.countTo >= 4.0) {
      /* Transition: '<S1>:329' */
      /* Exit 'GetDirections': '<S1>:332' */
      brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                       &brain_DWork.AvgDesiredHeadingAlongPath[0], &sf_ErrorX,
                       &brain_B.DesiredHeading);

      /* Entry 'CenterOver': '<S1>:484' */
      brain_DWork.is_OnePath = (uint8_T)brain_IN_CenterOver;
      brain_DWork.Error = 500.0;
    } else {
      /* Simulink Function 'MakeHSVImage': '<S1>:380' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o14[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o15[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o16[i] = (real_T)brain_B.Resize2[i];
      }

      RunningAutonomousFollowOnePathM(brain_B.SFunction_o14,
        brain_B.SFunction_o15, brain_B.SFunction_o16,
        &brain_B.RunningAutonomousFollowOnePat_i);

      /* Simulink Function 'GetBrightestPixel_VerticalSplit': '<S1>:333' */
      memcpy((void *)&brain_B.SFunction_o24[0], (void *)
             &brain_B.RunningAutonomousFollowOnePat_i.HSVImage1[0], 57600U *
             sizeof(real_T));
      RunningAutonomousFollowOnePathO(brain_B.SFunction_o24,
        &brain_B.RunningAutonomousFollowOnePat_m);

      /* Simulink Function 'GetHeadings': '<S1>:350' */
      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o25[i] =
          (brain_B.RunningAutonomousFollowOnePat_m.BWleft[i] != 0);
        brain_B.SFunction_o26[i] =
          (brain_B.RunningAutonomousFollowOnePat_m.BWright[i] != 0);
      }

      brain_B.SFunction_o27 = brain_U.CurrentHeading;
      RunningAutonomousFollowOnePat_o(brain_B.SFunction_o25,
        brain_B.SFunction_o26, brain_B.SFunction_o27,
        &brain_B.RunningAutonomousFollowOnePa_ot);
      brain_GetAvgDesHeading
        (&brain_B.RunningAutonomousFollowOnePa_ot.ToPathHeading[0],
         &brain_DWork.AvgDesiredHeadingToPath[0], brain_DWork.countTo,
         brain_DWork.outliersTo, sf_AvgDesHeading, &sf_ErrorX, &sf_ErrorY);
      brain_DWork.AvgDesiredHeadingToPath[0] = sf_AvgDesHeading[0];
      brain_DWork.AvgDesiredHeadingToPath[1] = sf_AvgDesHeading[1];
      brain_DWork.countTo = sf_ErrorX;
      brain_DWork.outliersTo = sf_ErrorY;
      brain_GetAvgDesHeading
        (&brain_B.RunningAutonomousFollowOnePa_ot.AlongPathHeading[0],
         &brain_DWork.AvgDesiredHeadingAlongPath[0], brain_DWork.countAlong,
         brain_DWork.outliersAlong, sf_AvgDesHeading, &sf_ErrorX, &sf_ErrorY);
      brain_DWork.AvgDesiredHeadingAlongPath[0] = sf_AvgDesHeading[0];
      brain_DWork.AvgDesiredHeadingAlongPath[1] = sf_AvgDesHeading[1];
      brain_DWork.countAlong = sf_ErrorX;
      brain_DWork.outliersAlong = sf_ErrorY;

      /* Simulink Function 'MaintainDepth': '<S1>:464' */
      brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o33 = (real32_T)brain_B.DesiredDepth;
      brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32, brain_M,
                          &brain_B.MaintainDepth, &brain_DWork.MaintainDepth);
      brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;
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
  real_T sf_Desired_HeadingTo;
  if (brain_DWork.is_FollowOnePath == brain_IN_OnePath) {
    switch (brain_DWork.is_OnePath) {
     case brain_IN_CenterOver:
      /* Exit 'CenterOver': '<S1>:484' */
      brain_DWork.is_OnePath = (uint8_T)0;
      break;

     case brain_IN_GetDirections:
      /* Exit 'GetDirections': '<S1>:332' */
      brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                       &brain_DWork.AvgDesiredHeadingAlongPath[0],
                       &sf_Desired_HeadingTo, &brain_B.DesiredHeading);
      brain_DWork.is_OnePath = (uint8_T)0;
      break;

     default:
      /* Exit 'Done': '<S1>:369' */
      break;
    }

    /* Exit 'OnePath': '<S1>:328' */
    brain_DWork.is_FollowOnePath = (uint8_T)0;
  } else {
    /* Exit 'Initialize': '<S1>:379' */
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_enter_internal_OnePath_m(void)
{
  /* Transition: '<S1>:534' */
  /* Entry 'GetDirections': '<S1>:548' */
  brain_DWork.is_OnePath_b = (uint8_T)brain_IN_GetDirections;
  brain_DWork.countTo = 0.0;
  brain_DWork.countAlong = 0.0;
  brain_DWork.outliersTo = 0.0;
  brain_DWork.outliersAlong = 0.0;
  brain_B.Left = 0;
  brain_B.Right = 0;
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_GetAvgDesHeading_m(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT)
{
  /* Embedded MATLAB Function 'GetAvgDesHeading': '<S1>:558' */
  /*  This function calculates the average desired heading determined by the */
  /*  path software */
  /* '<S1>:558:7' */
  sf_AvgDesHeading[0] = 0.0;
  sf_AvgDesHeading[1] = 0.0;

  /* '<S1>:558:8' */
  *sf_OutliersOUT = sf_OutliersIN;
  if ((sf_CountIn == 0.0) && (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S1>:558:10' */
    /* '<S1>:558:11' */
    sf_AvgDesHeading[0] = sf_DesiredHeading1[0];
    sf_AvgDesHeading[1] = sf_DesiredHeading1[1];

    /* '<S1>:558:12' */
    *sf_CountOut = 1.0;
  } else if ((fabs(sf_DesiredHeading1[0] - sf_AvgDHeading[0]) < 5.0) &&
             (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S1>:558:13' */
    /* '<S1>:558:14' */
    *sf_CountOut = sf_CountIn + 1.0;

    /* '<S1>:558:15' */
    sf_AvgDesHeading[0] = (sf_CountIn * sf_AvgDHeading[0] + sf_DesiredHeading1[0])
      / *sf_CountOut;
  } else {
    /* '<S1>:558:17' */
    *sf_OutliersOUT = sf_OutliersIN + 1.0;

    /* '<S1>:558:18' */
    sf_AvgDesHeading[0] = sf_AvgDHeading[0];

    /* '<S1>:558:19' */
    *sf_CountOut = sf_CountIn;
  }

  if (sf_AvgDHeading[1] != -999.0) {
    /* '<S1>:558:24' */
    if ((fabs(sf_DesiredHeading1[1] - sf_AvgDHeading[1]) < 5.0) &&
        (sf_DesiredHeading1[1] != -999.0)) {
      /* '<S1>:558:25' */
      /* '<S1>:558:26' */
      sf_AvgDesHeading[1] = (sf_CountIn * sf_AvgDHeading[1] +
        sf_DesiredHeading1[1]) / *sf_CountOut;
    } else {
      /* '<S1>:558:28' */
      sf_AvgDesHeading[1] = sf_AvgDHeading[1];
    }

    if (*sf_OutliersOUT > 5.0) {
      /* '<S1>:558:31' */
      /* '<S1>:558:32' */
      sf_AvgDesHeading[1] = 0.0;
    }
  }

  if (*sf_OutliersOUT > 5.0) {
    /* '<S1>:558:38' */
    /* '<S1>:558:39' */
    sf_AvgDesHeading[0] = 0.0;
    sf_AvgDesHeading[1] = 0.0;

    /* '<S1>:558:40' */
    *sf_CountOut = 0.0;

    /* '<S1>:558:41' */
    *sf_OutliersOUT = 0.0;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_ChoosePath_m(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong)
{
  real_T sf_DeltaTheta;
  int32_T sf_RightPathIndex;

  /* Embedded MATLAB Function 'ChoosePath': '<S1>:553' */
  /*  This function will determine which of the two found paths are pointing */
  /*  right and which is pointing left. This function will then return the  */
  /*  headings associated with the path to the right (There should only be one */
  /*  path and therefore that one will be returned) */
  if (sf_AvgDesHeadingAlongPath[1] != -999.0) {
    /* '<S1>:553:15' */
    /* '<S1>:553:16' */
    sf_DeltaTheta = sf_AvgDesHeadingAlongPath[1] - sf_AvgDesHeadingAlongPath[0];
    if (sf_DeltaTheta > 180.0) {
      /* '<S1>:553:18' */
      /* '<S1>:553:19' */
      sf_DeltaTheta -= 360.0;
    } else {
      if (sf_DeltaTheta < -180.0) {
        /* '<S1>:553:20' */
        /* '<S1>:553:21' */
        sf_DeltaTheta += 360.0;
      }
    }

    if (sf_DeltaTheta > 0.0) {
      /* '<S1>:553:24' */
      /* '<S1>:553:25' */
      sf_RightPathIndex = 2;
    } else {
      /* '<S1>:553:29' */
      sf_RightPathIndex = 1;
    }

    /*  Choose the RightPath */
    /* '<S1>:553:33' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[sf_RightPathIndex - 1];

    /* '<S1>:553:34' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[sf_RightPathIndex - 1];
  } else {
    /* '<S1>:553:38' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[0];

    /* '<S1>:553:39' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[0];
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_OnePath_m(void)
{
  real_T sf_AvgDesHeading[2];
  real_T sf_ErrorX;
  real_T sf_ErrorY;
  int32_T i;

  /* During 'OnePath': '<S1>:531' */
  switch (brain_DWork.is_OnePath_b) {
   case brain_IN_CenterOver:
    /* During 'CenterOver': '<S1>:536' */
    if (brain_DWork.Error < 10.0) {
      /* Transition: '<S1>:533' */
      /* Exit 'CenterOver': '<S1>:536' */
      /* Entry 'Done': '<S1>:535' */
      brain_DWork.is_OnePath_b = (uint8_T)brain_IN_Done;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'CenterOver': '<S1>:541' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o36[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o37[i] = (real_T)brain_B.Resize1[i];
      }

      RunningAutonomousFollowOnePa_oc(brain_B.SFunction_o36,
        brain_B.SFunction_o37, brain_M, &brain_B.RunningAutonomousFollowOnePat_g,
        &brain_DWork.RunningAutonomousFollowOnePat_g);
      brain_B.Strafe =
        brain_B.RunningAutonomousFollowOnePat_g.DataTypeConversion;
      i = (int32_T)brain_B.RunningAutonomousFollowOnePat_g.DataTypeConversion_b;
      sf_ErrorX = brain_B.RunningAutonomousFollowOnePat_g.Subtract1;
      sf_ErrorY = brain_B.RunningAutonomousFollowOnePat_g.Subtract;

      /* Simulink Function 'MaintainDepth': '<S1>:464' */
      brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o33 = (real32_T)brain_B.DesiredDepth;
      brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32, brain_M,
                          &brain_B.MaintainDepth, &brain_DWork.MaintainDepth);
      brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S1>:458' */
      brain_B.SFunction_o19 = brain_B.DesiredHeading;
      brain_B.SFunction_o20 = brain_U.CurrentHeading;
      brain_B.SFunction_o21 = (real_T)i;
      brain_MaintainHeading(brain_B.SFunction_o19, brain_B.SFunction_o20,
                            brain_B.SFunction_o21, brain_M,
                            &brain_B.MaintainHeading,
                            &brain_DWork.MaintainHeading);
      brain_B.Left = brain_B.MaintainHeading.DoubleToint8;
      brain_B.Right = brain_B.MaintainHeading.DoubleToint1;

      /* Embedded MATLAB Function 'CalcError': '<S1>:537' */
      /*  This function calculates the error between the center of the screen and  */
      /*  the centroid of the orange/red blob */
      /* '<S1>:537:5' */
      brain_DWork.Error = fabs(sf_ErrorX - sf_ErrorY);
    }
    break;

   case brain_IN_Done:
    break;

   case brain_IN_GetDirections:
    /* During 'GetDirections': '<S1>:548' */
    if (brain_DWork.countTo >= 4.0) {
      /* Transition: '<S1>:532' */
      /* Exit 'GetDirections': '<S1>:548' */
      brain_ChoosePath_m(&brain_DWork.AvgDesiredHeadingToPath[0],
                         &brain_DWork.AvgDesiredHeadingAlongPath[0], &sf_ErrorX,
                         &brain_B.DesiredHeading);

      /* Entry 'CenterOver': '<S1>:536' */
      brain_DWork.is_OnePath_b = (uint8_T)brain_IN_CenterOver;
      brain_DWork.Error = 500.0;
    } else {
      /* Simulink Function 'MakeHSVImage': '<S1>:573' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o42[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o43[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o44[i] = (real_T)brain_B.Resize2[i];
      }

      RunningAutonomousFollowOnePathM(brain_B.SFunction_o42,
        brain_B.SFunction_o43, brain_B.SFunction_o44,
        &brain_B.RunningAutonomousFollowOnePath1);

      /* Simulink Function 'GetBrightestPixel_VerticalSplit': '<S1>:549' */
      memcpy((void *)&brain_B.SFunction_o38[0], (void *)
             &brain_B.RunningAutonomousFollowOnePath1.HSVImage1[0], 57600U *
             sizeof(real_T));
      RunningAutonomousFollowOnePathO(brain_B.SFunction_o38,
        &brain_B.RunningAutonomousFollowOnePa_m3);

      /* Simulink Function 'GetHeadings': '<S1>:566' */
      for (i = 0; i < 9600; i++) {
        brain_B.SFunction_o39[i] =
          (brain_B.RunningAutonomousFollowOnePa_m3.BWleft[i] != 0);
        brain_B.SFunction_o40[i] =
          (brain_B.RunningAutonomousFollowOnePa_m3.BWright[i] != 0);
      }

      brain_B.SFunction_o41 = brain_U.CurrentHeading;
      RunningAutonomousFollowOnePat_o(brain_B.SFunction_o39,
        brain_B.SFunction_o40, brain_B.SFunction_o41,
        &brain_B.RunningAutonomousFollowOnePat_d);
      brain_GetAvgDesHeading_m
        (&brain_B.RunningAutonomousFollowOnePat_d.ToPathHeading[0],
         &brain_DWork.AvgDesiredHeadingToPath[0], brain_DWork.countTo,
         brain_DWork.outliersTo, sf_AvgDesHeading, &sf_ErrorX, &sf_ErrorY);
      brain_DWork.AvgDesiredHeadingToPath[0] = sf_AvgDesHeading[0];
      brain_DWork.AvgDesiredHeadingToPath[1] = sf_AvgDesHeading[1];
      brain_DWork.countTo = sf_ErrorX;
      brain_DWork.outliersTo = sf_ErrorY;
      brain_GetAvgDesHeading_m
        (&brain_B.RunningAutonomousFollowOnePat_d.AlongPathHeading[0],
         &brain_DWork.AvgDesiredHeadingAlongPath[0], brain_DWork.countAlong,
         brain_DWork.outliersAlong, sf_AvgDesHeading, &sf_ErrorX, &sf_ErrorY);
      brain_DWork.AvgDesiredHeadingAlongPath[0] = sf_AvgDesHeading[0];
      brain_DWork.AvgDesiredHeadingAlongPath[1] = sf_AvgDesHeading[1];
      brain_DWork.countAlong = sf_ErrorX;
      brain_DWork.outliersAlong = sf_ErrorY;

      /* Simulink Function 'MaintainDepth': '<S1>:464' */
      brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
      brain_B.SFunction_o33 = (real32_T)brain_B.DesiredDepth;
      brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32, brain_M,
                          &brain_B.MaintainDepth, &brain_DWork.MaintainDepth);
      brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;
    }
    break;

   default:
    brain_enter_internal_OnePath_m();
    break;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void br_exit_internal_FollowOnePath1(void)
{
  real_T sf_Desired_HeadingTo;
  if (brain_DWork.is_FollowOnePath1 == brain_IN_OnePath) {
    switch (brain_DWork.is_OnePath_b) {
     case brain_IN_CenterOver:
      /* Exit 'CenterOver': '<S1>:536' */
      brain_DWork.is_OnePath_b = (uint8_T)0;
      break;

     case brain_IN_GetDirections:
      /* Exit 'GetDirections': '<S1>:548' */
      brain_ChoosePath_m(&brain_DWork.AvgDesiredHeadingToPath[0],
                         &brain_DWork.AvgDesiredHeadingAlongPath[0],
                         &sf_Desired_HeadingTo, &brain_B.DesiredHeading);
      brain_DWork.is_OnePath_b = (uint8_T)0;
      break;

     default:
      /* Exit 'Done': '<S1>:535' */
      break;
    }

    /* Exit 'OnePath': '<S1>:531' */
    brain_DWork.is_FollowOnePath1 = (uint8_T)0;
  } else {
    /* Exit 'Initialize': '<S1>:572' */
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_FollowOnePath1(void)
{
  int32_T i;

  /* During 'FollowOnePath1': '<S1>:528' */
  if ((brain_U.DesiredState != 5) && (brain_U.DesiredState != 0)) {
    /* Transition: '<S1>:578' */
    br_exit_internal_FollowOnePath1();

    /* Exit 'FollowOnePath1': '<S1>:528' */
    /* Entry 'ChooseState': '<S1>:299' */
    brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
  } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
    /* Transition: '<S1>:580' */
    br_exit_internal_FollowOnePath1();

    /* Exit 'FollowOnePath1': '<S1>:528' */
    /* Entry 'Finish': '<S1>:151' */
    brain_DWork.is_Autonomous = (uint8_T)brain_IN_Finish;
    brain_B.State = 6;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
  } else {
    switch (brain_DWork.is_FollowOnePath1) {
     case brain_IN_Initialize:
      /* During 'Initialize': '<S1>:572' */
      /* Transition: '<S1>:530' */
      /* Exit 'Initialize': '<S1>:572' */
      /* Entry 'OnePath': '<S1>:531' */
      brain_DWork.is_FollowOnePath1 = (uint8_T)brain_IN_OnePath;

      /* Transition: '<S1>:534' */
      /* Entry 'GetDirections': '<S1>:548' */
      brain_DWork.is_OnePath_b = (uint8_T)brain_IN_GetDirections;
      brain_DWork.countTo = 0.0;
      brain_DWork.countAlong = 0.0;
      brain_DWork.outliersTo = 0.0;
      brain_DWork.outliersAlong = 0.0;
      brain_B.Left = 0;
      brain_B.Right = 0;
      break;

     case brain_IN_OnePath:
      brain_OnePath_m();
      break;

     default:
      /* Transition: '<S1>:529' */
      /* Entry 'Initialize': '<S1>:572' */
      brain_DWork.is_FollowOnePath1 = (uint8_T)brain_IN_Initialize;
      brain_B.DesiredDepth = 5.0;
      brain_B.DesiredHeading = 0.0;
      brain_DWork.Done = 0.0;
      brain_B.State = 5;
      brain_B.CameraPosition = 2;

      /* Simulink Function 'MakeHSVImage': '<S1>:573' */
      for (i = 0; i < 19200; i++) {
        brain_B.SFunction_o42[i] = (real_T)brain_B.Resize[i];
        brain_B.SFunction_o43[i] = (real_T)brain_B.Resize1[i];
        brain_B.SFunction_o44[i] = (real_T)brain_B.Resize2[i];
      }

      RunningAutonomousFollowOnePathM(brain_B.SFunction_o42,
        brain_B.SFunction_o43, brain_B.SFunction_o44,
        &brain_B.RunningAutonomousFollowOnePath1);
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static real_T brain_InitialHeadingCount(real_T sf_CurrentHeading1, real_T
  sf_OldHeading1, real_T sf_count1)
{
  /* Embedded MATLAB Function 'InitialHeadingCount': '<S1>:154' */
  /* '<S1>:154:3' */
  if ((sf_CurrentHeading1 > sf_OldHeading1 - 2.0) && (sf_CurrentHeading1 <
       sf_OldHeading1 + 2.0)) {
    /* '<S1>:154:5' */
    /* '<S1>:154:6' */
    sf_count1++;
  } else {
    /* '<S1>:154:8' */
    sf_count1 = 0.0;
  }

  /* '<S1>:154:10' */
  return sf_count1;
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_ValidationGate(void)
{
  /* local block i/o variables */
  real32_T rtb_BlobAnalysis;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BlobAnalysis_NUM_PIX_DW_j;
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  real32_T ys;
  real32_T xys;
  uint32_T k;
  real32_T uyy;
  real32_T majorAxis;
  int32_T i;
  real32_T centroid_idx;
  real32_T centroid_idx_0;
  int64m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;

  /* During 'ValidationGate': '<S1>:1' */
  if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
    /* Transition: '<S1>:302' */
    /* Exit 'ValidationGate': '<S1>:1' */
    /* Entry 'ChooseState': '<S1>:299' */
    brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
  } else if ((brain_DWork.TrackCount > 2.0) && (brain_U.DesiredState == 0)) {
    /* Transition: '<S1>:199' */
    /* Exit 'ValidationGate': '<S1>:1' */
    /* Entry 'FollowOnePath': '<S1>:325' */
    brain_DWork.is_Autonomous = (uint8_T)brain_IN_FollowOnePath;

    /* Transition: '<S1>:326' */
    /* Entry 'Initialize': '<S1>:379' */
    brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_Initialize;
    brain_B.DesiredDepth = 5.0;
    brain_B.DesiredHeading = 0.0;
    brain_DWork.Done = 0.0;
    brain_B.State = 3;
    brain_B.CameraPosition = 2;

    /* Simulink Function 'MakeHSVImage': '<S1>:380' */
    for (i = 0; i < 19200; i++) {
      brain_B.SFunction_o14[i] = (real_T)brain_B.Resize[i];
      brain_B.SFunction_o15[i] = (real_T)brain_B.Resize1[i];
      brain_B.SFunction_o16[i] = (real_T)brain_B.Resize2[i];
    }

    RunningAutonomousFollowOnePathM(brain_B.SFunction_o14, brain_B.SFunction_o15,
      brain_B.SFunction_o16, &brain_B.RunningAutonomousFollowOnePat_i);
  } else {
    /* Simulink Function 'LookforTrack': '<S1>:4' */

    /* DataStoreRead: '<S19>/Data Store Read' */
    brain_B.DataStoreRead = brain_DWork.Image;
    for (i = 0; i < 19200; i++) {
      brain_B.SFunction_o12[i] = (real_T)brain_B.Resize[i];
      brain_B.SFunction_o13[i] = (real_T)brain_B.Resize1[i];

      /* RelationalOperator: '<S84>/Compare' incorporates:
       *  Constant: '<S84>/Constant'
       */
      brain_B.BW_a[i] = (brain_B.SFunction_o12[i] < brain_P.Track_HueLower);

      /* RelationalOperator: '<S83>/Compare' incorporates:
       *  Constant: '<S83>/Constant'
       */
      brain_B.Compare[i] = (brain_B.SFunction_o12[i] > brain_P.Track_HueHigher);

      /* Logic: '<S81>/Logical Operator' */
      brain_B.BW_a[i] = (brain_B.BW_a[i] || brain_B.Compare[i]);

      /* RelationalOperator: '<S86>/Compare' incorporates:
       *  Constant: '<S86>/Constant'
       */
      brain_B.Compare[i] = (brain_B.SFunction_o13[i] > brain_P.Track_Saturation);

      /* Logic: '<S81>/Logical Operator1' */
      brain_B.BW_a[i] = (brain_B.BW_a[i] && brain_B.Compare[i]);
    }

    /* S-Function (svipblob): '<S81>/Blob Analysis' */
    maxNumBlobsReached = false;
    for (i = 0; i < 123; i++) {
      brain_DWork.BlobAnalysis_PAD_DW[i] = 0U;
    }

    currentLabel = 1U;
    i = 0;
    idx = 123;
    for (n = 0; n < 160; n++) {
      for (n_0 = 0; n_0 < 120; n_0++) {
        brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.BW_a[i] ? 255 :
          0);
        i++;
        idx++;
      }

      brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
      idx++;
      brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
      idx++;
    }

    for (i = 0; i < 121; i++) {
      brain_DWork.BlobAnalysis_PAD_DW[i + idx] = 0U;
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
          BlobAnalysis_NUM_PIX_DW_j = 1U;
          brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
          stackIdx++;
          while (stackIdx) {
            stackIdx--;
            numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
            for (i = 0; i < 8; i++) {
              k = numBlobs + (uint32_T)brain_ConstP.pooled21[i];
              if (brain_DWork.BlobAnalysis_PAD_DW[k] == 255) {
                brain_DWork.BlobAnalysis_PAD_DW[k] = currentLabel;
                brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                  ((int16_T)(k / 122U) - 1);
                brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                  122U - 1U);
                pixIdx++;
                BlobAnalysis_NUM_PIX_DW_j = BlobAnalysis_NUM_PIX_DW_j + 1U;
                brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = k;
                stackIdx++;
              }
            }
          }

          if ((BlobAnalysis_NUM_PIX_DW_j < brain_P.Min_Blob_Size) ||
              (BlobAnalysis_NUM_PIX_DW_j > brain_P.Max_Blob_Size)) {
            currentLabel--;
            pixIdx = start_pixIdx;
          }

          if (currentLabel == 1) {
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
    i = 0;
    n = 0;
    for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
      idx = 0;
      ms = 0;
      for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW_j; j++) {
        idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
        ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i];
      }

      centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW_j;
      centroid_idx_0 = (real32_T)idx / (real32_T)BlobAnalysis_NUM_PIX_DW_j;
      rtb_BlobAnalysis = 0.0F;
      ys = 0.0F;
      xys = 0.0F;
      k = 0U;
      while (1) {
        uLong2MultiWord(k, &tmp_0.chunks[0U], 2);
        MultiWordSignedWrap(&tmp_0.chunks[0U], 2, (uint32_T)31, &tmp.chunks[0U]);
        sLong2MultiWord((int32_T)BlobAnalysis_NUM_PIX_DW_j, &tmp_1.chunks[0U], 2);
        MultiWordSignedWrap(&tmp_1.chunks[0U], 2, (uint32_T)31, &tmp_0.chunks[0U]);
        if (!sMultiWordLt(&tmp.chunks[0U], &tmp_0.chunks[0U], 2)) {
          break;
        }

        majorAxis = (real32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + k] -
          centroid_idx_0;
        uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i + k] -
          centroid_idx;
        rtb_BlobAnalysis += majorAxis * majorAxis;
        ys += uyy * uyy;
        xys += majorAxis * (-uyy);
        k++;
      }

      centroid_idx = rtb_BlobAnalysis / (real32_T)BlobAnalysis_NUM_PIX_DW_j +
        8.333333582E-02F;
      uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW_j + 8.333333582E-02F;
      rtb_BlobAnalysis = xys / (real32_T)BlobAnalysis_NUM_PIX_DW_j;
      rtb_BlobAnalysis = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx -
        uyy) + rtb_BlobAnalysis * rtb_BlobAnalysis * 4.0F);
      majorAxis = ((centroid_idx + uyy) + rtb_BlobAnalysis) * 8.0F;
      rtb_BlobAnalysis = (real32_T)sqrt(majorAxis - ((centroid_idx + uyy) -
        rtb_BlobAnalysis) * 8.0F) / (real32_T)sqrt(majorAxis);
      i += (int32_T)BlobAnalysis_NUM_PIX_DW_j;
      n += (int32_T)BlobAnalysis_NUM_PIX_DW_j;
    }

    for (i = (int32_T)numBlobs; i < 1; i = 1) {
      rtb_BlobAnalysis = -1.0F;
    }

    /* If: '<S81>/If' incorporates:
     *  ActionPort: '<S82>/Action Port'
     *  ActionPort: '<S85>/Action Port'
     *  SubSystem: '<S81>/FoundTrack'
     *  SubSystem: '<S81>/NoTrack'
     */
    if (rtb_BlobAnalysis > 8.999999762E-01F) {
      /* DataStoreWrite: '<S82>/Data Store Write' incorporates:
       *  Constant: '<S82>/Constant'
       */
      brain_DWork.Image = 1.0;
    } else {
      /* DataStoreWrite: '<S85>/Data Store Write' incorporates:
       *  Constant: '<S85>/Constant'
       */
      brain_DWork.Image = 0.0;
    }

    maxNumBlobsReached = (brain_B.DataStoreRead != 0.0);
    i = (int32_T)maxNumBlobsReached;

    /* Embedded MATLAB Function 'countimages': '<S1>:15' */
    /*  This function acts to count the number of consecutive times a particular */
    /*  image is recognized by the recognition software */
    if ((i != 0) && (i == brain_DWork.OldObstacle)) {
      /* '<S1>:15:6' */
      /* '<S1>:15:7' */
      brain_DWork.TrackCount = brain_DWork.count + 1.0;
    } else {
      /* '<S1>:15:9' */
      brain_DWork.TrackCount = 0.0;
    }

    /* Simulink Function 'StraightLevelControl': '<S1>:449' */
    brain_B.SFunction_o28 = (real32_T)brain_U.CurrentDepth;
    brain_B.SFunction_o29 = (real32_T)brain_B.DesiredDepth;
    brain_B.SFunction_o30 = brain_B.DesiredHeading;
    brain_B.SFunction_o31 = brain_U.CurrentHeading;
    brain_StraightLevelControl(brain_B.SFunction_o29, brain_B.SFunction_o28,
      brain_B.SFunction_o30, brain_B.SFunction_o31, brain_M,
      &brain_B.StraightLevelControl, &brain_DWork.StraightLevelControl,
      (rtP_StraightLevelControl_brain *) &brain_P.StraightLevelControl);
    brain_B.Vertical = brain_B.StraightLevelControl.DoubleToInt8;
    brain_B.Left = brain_B.StraightLevelControl.DoubleToint8;
    brain_B.Right = brain_B.StraightLevelControl.DoubleToint1;
    brain_DWork.OldObstacle = maxNumBlobsReached;
    brain_DWork.count = brain_DWork.TrackCount;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_exit_internal_Autonomous(void)
{
  switch (brain_DWork.is_Autonomous) {
   case brain_IN_Buoy:
    switch (brain_DWork.is_Buoy) {
     case brain_IN_ApproachBuoy:
      /* Exit 'ApproachBuoy': '<S1>:58' */
      brain_DWork.BuoyDone = 1.0;
      brain_DWork.is_Buoy = (uint8_T)0;
      break;

     case brain_IN_FindBuoy:
      /* Exit 'FindBuoy': '<S1>:239' */
      brain_DWork.is_Buoy = (uint8_T)0;
      break;

     default:
      /* Exit 'BackupAndMoveUp': '<S1>:518' */
      brain_DWork.is_GoAroundBuoy = (uint8_T)0;

      /* Exit 'FinishedwithBuoy': '<S1>:522' */
      /* Exit 'MoveForward': '<S1>:520' */
      /* Exit 'GoAroundBuoy': '<S1>:516' */
      break;
    }

    /* Exit 'Buoy': '<S1>:470' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_FollowOnePath:
    bra_exit_internal_FollowOnePath();

    /* Exit 'FollowOnePath': '<S1>:325' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_FollowOnePath1:
    br_exit_internal_FollowOnePath1();

    /* Exit 'FollowOnePath1': '<S1>:528' */
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_Start:
    /* Exit 'Start': '<S1>:153' */
    brain_B.DesiredHeading = brain_U.CurrentHeading;
    brain_DWork.is_Autonomous = (uint8_T)0;
    break;

   case brain_IN_ValidationGate:
    /* Exit 'ValidationGate': '<S1>:1' */
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
  real_T rtb_BuoyBlobAnalysis_o2[20];
  real_T rtb_XBuoyProportionalGain;
  real_T rtb_TSamp;
  real_T rtb_YBuoyProportionalGain;
  real_T rtb_TSamp_d;
  real_T rtb_Sum;
  real_T rtb_Error;
  real32_T rtb_BlobAnalysis_o1[10];
  real32_T rtb_BlobAnalysis_o2[10];
  int32_T rtb_BuoyBlobAnalysis_o1[10];
  real32_T xs;
  real32_T ys;
  real32_T xys;
  real32_T uyy;
  real32_T majorAxis;
  int32_T ku;
  int32_T i;
  int32_T i_0;
  int32_T n;
  int32_T inIdx;
  int32_T outIdx;
  int32_T padRows;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  int32_T i_1;
  real32_T centroid_idx;
  real32_T centroid_idx_0;
  int8_T rtb_DataTypeConversion_0;
  int64m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;

  /* During 'Autonomous': '<S1>:289' */
  if (brain_U.RC == 1) {
    /* Transition: '<S1>:438' */
    brain_exit_internal_Autonomous();

    /* Exit 'Autonomous': '<S1>:289' */
    /* Entry 'ControlledRC': '<S1>:408' */
    brain_DWork.is_Running = (uint8_T)brain_IN_ControlledRC;
    brain_B.State = -1;
  } else {
    switch (brain_DWork.is_Autonomous) {
     case brain_IN_Buoy:
      /* During 'Buoy': '<S1>:470' */
      if ((brain_U.DesiredState != 4) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:319' */
        switch (brain_DWork.is_Buoy) {
         case brain_IN_ApproachBuoy:
          /* Exit 'ApproachBuoy': '<S1>:58' */
          brain_DWork.BuoyDone = 1.0;
          brain_DWork.is_Buoy = (uint8_T)0;
          break;

         case brain_IN_FindBuoy:
          /* Exit 'FindBuoy': '<S1>:239' */
          brain_DWork.is_Buoy = (uint8_T)0;
          break;

         default:
          /* Exit 'BackupAndMoveUp': '<S1>:518' */
          brain_DWork.is_GoAroundBuoy = (uint8_T)0;

          /* Exit 'FinishedwithBuoy': '<S1>:522' */
          /* Exit 'MoveForward': '<S1>:520' */
          /* Exit 'GoAroundBuoy': '<S1>:516' */
          break;
        }

        /* Exit 'Buoy': '<S1>:470' */
        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else if ((brain_DWork.BuoyDone == 1.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:527' */
        switch (brain_DWork.is_Buoy) {
         case brain_IN_ApproachBuoy:
          /* Exit 'ApproachBuoy': '<S1>:58' */
          brain_DWork.BuoyDone = 1.0;
          brain_DWork.is_Buoy = (uint8_T)0;
          break;

         case brain_IN_FindBuoy:
          /* Exit 'FindBuoy': '<S1>:239' */
          brain_DWork.is_Buoy = (uint8_T)0;
          break;

         default:
          /* Exit 'BackupAndMoveUp': '<S1>:518' */
          brain_DWork.is_GoAroundBuoy = (uint8_T)0;

          /* Exit 'FinishedwithBuoy': '<S1>:522' */
          /* Exit 'MoveForward': '<S1>:520' */
          /* Exit 'GoAroundBuoy': '<S1>:516' */
          break;
        }

        /* Exit 'Buoy': '<S1>:470' */
        /* Entry 'FollowOnePath1': '<S1>:528' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_FollowOnePath1;

        /* Transition: '<S1>:529' */
        /* Entry 'Initialize': '<S1>:572' */
        brain_DWork.is_FollowOnePath1 = (uint8_T)brain_IN_Initialize;
        brain_B.DesiredDepth = 5.0;
        brain_B.DesiredHeading = 0.0;
        brain_DWork.Done = 0.0;
        brain_B.State = 5;
        brain_B.CameraPosition = 2;

        /* Simulink Function 'MakeHSVImage': '<S1>:573' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.SFunction_o42[i_1] = (real_T)brain_B.Resize[i_1];
          brain_B.SFunction_o43[i_1] = (real_T)brain_B.Resize1[i_1];
          brain_B.SFunction_o44[i_1] = (real_T)brain_B.Resize2[i_1];
        }

        RunningAutonomousFollowOnePathM(brain_B.SFunction_o42,
          brain_B.SFunction_o43, brain_B.SFunction_o44,
          &brain_B.RunningAutonomousFollowOnePath1);
      } else {
        switch (brain_DWork.is_Buoy) {
         case brain_IN_ApproachBuoy:
          /* During 'ApproachBuoy': '<S1>:58' */
          if (brain_DWork.countarea > 2.0) {
            /* Transition: '<S1>:517' */
            /* Exit 'ApproachBuoy': '<S1>:58' */
            brain_DWork.BuoyDone = 1.0;

            /* Entry 'GoAroundBuoy': '<S1>:516' */
            brain_DWork.is_Buoy = (uint8_T)brain_IN_GoAroundBuoy;

            /* Transition: '<S1>:581' */
            /* Entry 'BackupAndMoveUp': '<S1>:518' */
            brain_DWork.is_GoAroundBuoy = (uint8_T)brain_IN_BackupAndMoveUp;
            brain_DWork.Error = -3.0;
            brain_B.DesiredDepth = brain_U.CurrentDepth - 3.0;
          } else {
            /* Simulink Function 'Buoy': '<S1>:60' */
            brain_DWork.RunningAutonomousBuoyApproachBu =
              brain_M->Timing.clockTick0 -
              brain_DWork.RunningAutonomousBuoyApproach_d;
            brain_DWork.RunningAutonomousBuoyApproach_d =
              brain_M->Timing.clockTick0;
            for (i_1 = 0; i_1 < 19200; i_1++) {
              brain_B.SFunction_o17[i_1] = (real_T)brain_B.Resize[i_1];
              brain_B.SFunction_o18[i_1] = (real_T)brain_B.Resize1[i_1];

              /* RelationalOperator: '<S27>/Compare' incorporates:
               *  Constant: '<S27>/Constant'
               */
              brain_B.BW[i_1] = (brain_B.SFunction_o17[i_1] >
                                 brain_P.Buoy_HueHigher);

              /* RelationalOperator: '<S28>/Compare' incorporates:
               *  Constant: '<S28>/Constant'
               */
              brain_B.Dilation_p[i_1] = (brain_B.SFunction_o17[i_1] <=
                brain_P.Buoy_HueLower);

              /* Logic: '<S9>/Logical Operator' */
              brain_B.BW[i_1] = (brain_B.BW[i_1] || brain_B.Dilation_p[i_1]);

              /* RelationalOperator: '<S29>/Compare' incorporates:
               *  Constant: '<S29>/Constant'
               */
              brain_B.Dilation_p[i_1] = (brain_B.SFunction_o18[i_1] >=
                brain_P.Buoy_Saturation);

              /* Logic: '<S9>/Logical Operator1' */
              brain_B.BW[i_1] = (brain_B.BW[i_1] && brain_B.Dilation_p[i_1]);
            }

            /* S-Function (svipmorphop): '<S9>/Dilation' */
            i_1 = 0;
            ku = 0;
            for (i_0 = 0; i_0 < 123; i_0++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
            }

            for (i = 0; i < 160; i++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
              memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1], (void *)
                     &brain_B.BW[ku], 120U * sizeof(boolean_T));
              i_1 += 120;
              ku += 120;
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
            }

            for (i = 161; i < 163; i++) {
              for (i_0 = 0; i_0 < 123; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
                i_1++;
              }
            }

            i_1 = 0;
            ku = 0;
            for (i = 0; i < 160; i++) {
              for (i_0 = 0; i_0 < 120; i_0++) {
                brain_B.Dilation_p[ku] = false;
                for (inIdx = 0; inIdx < brain_DWork.Dilation_NUMNONZ_DW_c; inIdx
                     ++) {
                  if (brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1 +
                      brain_DWork.Dilation_DILATE_OFF_DW_h[inIdx]]) {
                    brain_B.Dilation_p[ku] = true;
                    inIdx = brain_DWork.Dilation_NUMNONZ_DW_c;
                  }
                }

                i_1++;
                ku++;
              }

              i_1 += 3;
            }

            /* S-Function (svipmorphop): '<S9>/Erosion' */
            i_1 = 0;
            ku = 0;
            for (i_0 = 0; i_0 < 127; i_0++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
              i_1++;
            }

            for (i = 0; i < 160; i++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
              i_1++;
              memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1], (void *)
                     &brain_B.Dilation_p[ku], 120U * sizeof(boolean_T));
              i_1 += 120;
              ku += 120;
              for (i_0 = 121; i_0 < 127; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
                i_1++;
              }
            }

            for (i = 161; i < 167; i++) {
              for (i_0 = 0; i_0 < 127; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
                i_1++;
              }
            }

            for (i_0 = 0; i_0 < 21209; i_0++) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW[i_0] = true;
            }

            ku = 0;
            for (n = 0; n < 167; n++) {
              for (padRows = 0; padRows < 124; padRows++) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = true;
                for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_f[0]; i_0++)
                {
                  if (!brain_DWork.Erosion_ONE_PAD_IMG_DW[ku +
                      brain_DWork.Erosion_ERODE_OFF_DW_g[i_0]]) {
                    brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = false;
                    i_0 = brain_DWork.Erosion_NUMNONZ_DW_f[0];
                  }
                }

                ku++;
              }

              ku += 3;
            }

            inIdx = 1;
            outIdx = 0;
            for (n = 0; n < 160; n++) {
              for (padRows = 1; padRows < 121; padRows++) {
                brain_B.Erosion[outIdx] = true;
                for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_f[1]; i_0++)
                {
                  if (!brain_DWork.Erosion_TWO_PAD_IMG_DW[brain_DWork.Erosion_ERODE_OFF_DW_g
                      [i_0 + brain_DWork.Erosion_NUMNONZ_DW_f[0]] + inIdx]) {
                    brain_B.Erosion[outIdx] = false;
                    i_0 = brain_DWork.Erosion_NUMNONZ_DW_f[1];
                  }
                }

                inIdx++;
                outIdx++;
              }

              inIdx += 7;
            }

            /* S-Function (svipblob): '<S9>/Buoy Blob Analysis' */
            maxNumBlobsReached = false;
            for (i_1 = 0; i_1 < 123; i_1++) {
              brain_DWork.BlobAnalysis_PAD_DW[i_1] = 0U;
            }

            currentLabel = 1U;
            i_1 = 0;
            i_0 = 123;
            for (ku = 0; ku < 160; ku++) {
              for (i = 0; i < 120; i++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0] = (uint8_T)
                  (brain_B.Erosion[i_1] ? 255 : 0);
                i_1++;
                i_0++;
              }

              brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              i_0++;
              brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              i_0++;
            }

            for (i_1 = 0; i_1 < 121; i_1++) {
              brain_DWork.BlobAnalysis_PAD_DW[i_1 + i_0] = 0U;
            }

            ku = 1;
            stackIdx = 0U;
            pixIdx = 0U;
            for (i = 0; i < 160; i++) {
              i_0 = 1;
              inIdx = ku * 122;
              for (outIdx = 0; outIdx < 120; outIdx++) {
                numBlobs = (uint32_T)(inIdx + i_0);
                start_pixIdx = pixIdx;
                if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
                  brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
                  brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(ku -
                    1);
                  brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(i_0
                    - 1);
                  pixIdx++;
                  BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
                  brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
                  stackIdx++;
                  while (stackIdx) {
                    stackIdx--;
                    numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                    for (n = 0; n < 8; n++) {
                      walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled21[n];
                      if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                        brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                          currentLabel;
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
                    i = 160;
                    outIdx = 120;
                  }

                  if (outIdx < 120) {
                    currentLabel++;
                  }
                }

                i_0++;
              }

              ku++;
            }

            numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel : (uint8_T)
                                  (currentLabel - 1));
            i_1 = 0;
            ku = 0;
            for (i = 0; i < (int32_T)numBlobs; i++) {
              rtb_BuoyBlobAnalysis_o1[i] = (int32_T)
                BuoyBlobAnalysis_NUM_PIX_DW[i];
              i_0 = 0;
              inIdx = 0;
              for (outIdx = 0; outIdx < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
                   outIdx++) {
                i_0 += brain_DWork.BlobAnalysis_N_PIXLIST_DW[outIdx + ku];
                inIdx += brain_DWork.BlobAnalysis_M_PIXLIST_DW[outIdx + i_1];
              }

              rtb_BuoyBlobAnalysis_o2[i << 1] = (real_T)inIdx / (real_T)
                BuoyBlobAnalysis_NUM_PIX_DW[i];
              rtb_BuoyBlobAnalysis_o2[(i << 1) + 1] = (real_T)i_0 / (real_T)
                BuoyBlobAnalysis_NUM_PIX_DW[i];
              i_1 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
              ku += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[i];
            }

            for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
              rtb_BuoyBlobAnalysis_o1[i_1] = -1;
            }

            for (i_1 = (int32_T)numBlobs << 1; i_1 < 20; i_1++) {
              rtb_BuoyBlobAnalysis_o2[i_1] = -1.0;
            }

            /* Embedded MATLAB: '<S9>/Embedded MATLAB Function' */
            /* Embedded MATLAB Function 'Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function': '<S30>:1' */
            /*  This function will choose and return data about the largest blob given a  */
            /*  set of blobs */
            if ((rtb_BuoyBlobAnalysis_o2[0] == -1.0) &&
                (rtb_BuoyBlobAnalysis_o2[1] == -1.0)) {
              /* '<S30>:1:5' */
              /* '<S30>:1:7' */
              brain_B.BlobCentroidX = 80.0;

              /* '<S30>:1:8' */
              brain_B.BlobCentroidY = 60.0;

              /* '<S30>:1:9' */
              brain_B.BlobArea = -1.0;
            } else {
              /* '<S30>:1:11' */
              i_1 = rtb_BuoyBlobAnalysis_o1[0];
              ku = 1;
              i = 1;
              for (i_0 = 2; i_0 < 11; i_0++) {
                i++;
                if (rtb_BuoyBlobAnalysis_o1[i - 1] > i_1) {
                  i_1 = rtb_BuoyBlobAnalysis_o1[i - 1];
                  ku = i_0;
                }
              }

              /* '<S30>:1:11' */
              brain_B.BlobArea = (real_T)i_1;

              /* '<S30>:1:12' */
              brain_B.BlobCentroidX = rtb_BuoyBlobAnalysis_o2[((ku - 1) << 1) +
                1];

              /* '<S30>:1:13' */
              brain_B.BlobCentroidY = rtb_BuoyBlobAnalysis_o2[(ku - 1) << 1];
            }

            /* Embedded MATLAB: '<S9>/Embedded MATLAB Function1' */
            brain_EmbeddedMATLABFunction1(&brain_B.sf_EmbeddedMATLABFunction1);

            /* Sum: '<S32>/Subtract' */
            rtb_Sum = brain_B.sf_EmbeddedMATLABFunction1.XCenter -
              brain_B.BlobCentroidX;

            /* Gain: '<S34>/X-Buoy Proportional Gain' */
            rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Kp *
              rtb_Sum;

            /* Gain: '<S34>/X-Buoy Derivative Gain' */
            rtb_Error = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum;

            /* S-Function (sfix_tsampmath): '<S35>/TSamp' */

            /* Sample Time Math Block: '<S35>/TSamp'
             *
             * y = u * K     where     K = 1 / ( w * Ts )
             *
             * Input0  Data Type:  Floating Point real_T
             * Output0 Data Type:  Floating Point real_T
             * ElapsedTime Data Type:  Floating Point real_T
             */
            rtb_TSamp = rtb_Error /
              (((brain_DWork.RunningAutonomousBuoyApproachBu * 0.2))*(1.0));

            /* DiscreteIntegrator: '<S34>/X-Buoy Discrete-Time Integrator' */
            rtb_Error = brain_DWork.XBuoyDiscreteTimeIntegrator_DST;

            /* Sum: '<S34>/Sum' incorporates:
             *  Sum: '<S35>/Diff'
             *  UnitDelay: '<S35>/UD'
             *
             * Block description for '<S35>/Diff':
             *
             *  Add in CPU
             *
             * Block description for '<S35>/UD':
             *
             *  Store in Global RAM
             */
            rtb_Error += (rtb_TSamp - brain_DWork.UD_DSTATE) +
              rtb_XBuoyProportionalGain;

            /* DataTypeConversion: '<S32>/Data Type Conversion' */
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

            /* Sum: '<S32>/Add' incorporates:
             *  Constant: '<S32>/Vision_Forward_Velocity'
             */
            brain_B.Add = brain_P.Vision_Forward_Velocity + (real_T)
              rtb_DataTypeConversion_0;

            /* Product: '<S32>/Multiply' incorporates:
             *  Constant: '<S32>/Constant'
             */
            rtb_Error = (real_T)rtb_DataTypeConversion_0 * -1.0;

            /* Sum: '<S32>/Add1' incorporates:
             *  Constant: '<S32>/Vision_Forward_Velocity2'
             */
            brain_B.Add1 = rtb_Error + brain_P.Vision_Forward_Velocity;

            /* Gain: '<S34>/X-Buoy Integral Gain' */
            rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Ki *
              rtb_Sum;

            /* Sum: '<S33>/Subtract' */
            rtb_Error = brain_B.BlobCentroidY -
              brain_B.sf_EmbeddedMATLABFunction1.YCenter;

            /* Gain: '<S36>/Y-Buoy Proportional Gain' */
            rtb_YBuoyProportionalGain = brain_P.Cam_Forward_YPosition_Kp *
              rtb_Error;

            /* Gain: '<S36>/Y-Buoy Derivative Gain' */
            rtb_Sum = brain_P.Cam_Forward_YPosition_Kd * rtb_Error;

            /* S-Function (sfix_tsampmath): '<S37>/TSamp' */

            /* Sample Time Math Block: '<S37>/TSamp'
             *
             * y = u * K     where     K = 1 / ( w * Ts )
             *
             * Input0  Data Type:  Floating Point real_T
             * Output0 Data Type:  Floating Point real_T
             * ElapsedTime Data Type:  Floating Point real_T
             */
            rtb_TSamp_d = rtb_Sum /
              (((brain_DWork.RunningAutonomousBuoyApproachBu * 0.2))*(1.0));

            /* DiscreteIntegrator: '<S36>/Y-Buoy Discrete-Time Integrator' */
            rtb_Sum = brain_DWork.YBuoyDiscreteTimeIntegrator_DST;

            /* Sum: '<S36>/Sum' incorporates:
             *  Sum: '<S37>/Diff'
             *  UnitDelay: '<S37>/UD'
             *
             * Block description for '<S37>/Diff':
             *
             *  Add in CPU
             *
             * Block description for '<S37>/UD':
             *
             *  Store in Global RAM
             */
            rtb_Sum += (rtb_TSamp_d - brain_DWork.UD_DSTATE_c) +
              rtb_YBuoyProportionalGain;

            /* DataTypeConversion: '<S33>/Data Type Conversion' */
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

            /* Update for UnitDelay: '<S35>/UD'
             * Block description for '<S35>/UD':
             *
             *  Store in Global RAM
             */
            brain_DWork.UD_DSTATE = rtb_TSamp;

            /* Update for DiscreteIntegrator: '<S34>/X-Buoy Discrete-Time Integrator' */
            brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
              brain_DWork.RunningAutonomousBuoyApproachBu *
              rtb_XBuoyProportionalGain +
              brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
            if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
              brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 15.0;
            } else {
              if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
                brain_DWork.XBuoyDiscreteTimeIntegrator_DST = -15.0;
              }
            }

            /* Update for UnitDelay: '<S37>/UD'
             * Block description for '<S37>/UD':
             *
             *  Store in Global RAM
             */
            brain_DWork.UD_DSTATE_c = rtb_TSamp_d;

            /* Update for DiscreteIntegrator: '<S36>/Y-Buoy Discrete-Time Integrator' incorporates:
             *  Gain: '<S36>/Y-Buoy Integral Gain'
             */
            brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
              brain_DWork.RunningAutonomousBuoyApproachBu *
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

         case brain_IN_FindBuoy:
          /* During 'FindBuoy': '<S1>:239' */
          if (brain_DWork.BuoyCount > 2.0) {
            /* Transition: '<S1>:241' */
            /* Exit 'FindBuoy': '<S1>:239' */
            /* Entry 'ApproachBuoy': '<S1>:58' */
            brain_DWork.is_Buoy = (uint8_T)brain_IN_ApproachBuoy;
            brain_DWork.countarea = 0.0;
          } else {
            /* Simulink Function 'LookforBuoy': '<S1>:250' */
            for (i_1 = 0; i_1 < 19200; i_1++) {
              brain_B.SFunction_o22[i_1] = (real_T)brain_B.Resize[i_1];
              brain_B.SFunction_o23[i_1] = (real_T)brain_B.Resize1[i_1];

              /* RelationalOperator: '<S40>/Compare' incorporates:
               *  Constant: '<S40>/Constant'
               */
              brain_B.Erosion_d[i_1] = (brain_B.SFunction_o22[i_1] <
                brain_P.Buoy_HueLower);

              /* RelationalOperator: '<S39>/Compare' incorporates:
               *  Constant: '<S39>/Constant'
               */
              brain_B.Dilation[i_1] = (brain_B.SFunction_o22[i_1] >
                brain_P.Buoy_HueHigher);

              /* Logic: '<S38>/Logical Operator' */
              brain_B.Erosion_d[i_1] = (brain_B.Erosion_d[i_1] ||
                brain_B.Dilation[i_1]);

              /* RelationalOperator: '<S42>/Compare' incorporates:
               *  Constant: '<S42>/Constant'
               */
              brain_B.Dilation[i_1] = (brain_B.SFunction_o23[i_1] >
                brain_P.Buoy_Saturation);

              /* Logic: '<S38>/Logical Operator1' */
              brain_B.Erosion_d[i_1] = (brain_B.Erosion_d[i_1] &&
                brain_B.Dilation[i_1]);
            }

            /* S-Function (svipmorphop): '<S38>/Dilation' */
            i_1 = 0;
            ku = 0;
            for (i_0 = 0; i_0 < 123; i_0++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
            }

            for (i = 0; i < 160; i++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
              memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1], (void *)
                     &brain_B.Erosion_d[ku], 120U * sizeof(boolean_T));
              i_1 += 120;
              ku += 120;
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
              i_1++;
            }

            for (i = 161; i < 163; i++) {
              for (i_0 = 0; i_0 < 123; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = false;
                i_1++;
              }
            }

            i_1 = 0;
            ku = 0;
            for (i = 0; i < 160; i++) {
              for (i_0 = 0; i_0 < 120; i_0++) {
                brain_B.Dilation[ku] = false;
                for (inIdx = 0; inIdx < brain_DWork.Dilation_NUMNONZ_DW; inIdx++)
                {
                  if (brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1 +
                      brain_DWork.Dilation_DILATE_OFF_DW[inIdx]]) {
                    brain_B.Dilation[ku] = true;
                    inIdx = brain_DWork.Dilation_NUMNONZ_DW;
                  }
                }

                i_1++;
                ku++;
              }

              i_1 += 3;
            }

            /* S-Function (svipmorphop): '<S38>/Erosion' */
            i_1 = 0;
            ku = 0;
            for (i_0 = 0; i_0 < 127; i_0++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
              i_1++;
            }

            for (i = 0; i < 160; i++) {
              brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
              i_1++;
              memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1], (void *)
                     &brain_B.Dilation[ku], 120U * sizeof(boolean_T));
              i_1 += 120;
              ku += 120;
              for (i_0 = 121; i_0 < 127; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
                i_1++;
              }
            }

            for (i = 161; i < 167; i++) {
              for (i_0 = 0; i_0 < 127; i_0++) {
                brain_DWork.Erosion_ONE_PAD_IMG_DW[i_1] = true;
                i_1++;
              }
            }

            for (outIdx = 0; outIdx < 21209; outIdx++) {
              brain_DWork.Erosion_TWO_PAD_IMG_DW[outIdx] = true;
            }

            ku = 0;
            for (n = 0; n < 167; n++) {
              for (padRows = 0; padRows < 124; padRows++) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = true;
                for (outIdx = 0; outIdx < brain_DWork.Erosion_NUMNONZ_DW[0];
                     outIdx++) {
                  if (!brain_DWork.Erosion_ONE_PAD_IMG_DW[ku +
                      brain_DWork.Erosion_ERODE_OFF_DW[outIdx]]) {
                    brain_DWork.Erosion_TWO_PAD_IMG_DW[1 + ku] = false;
                    outIdx = brain_DWork.Erosion_NUMNONZ_DW[0];
                  }
                }

                ku++;
              }

              ku += 3;
            }

            i_0 = 1;
            inIdx = 0;
            for (n = 0; n < 160; n++) {
              for (padRows = 1; padRows < 121; padRows++) {
                brain_B.Erosion_d[inIdx] = true;
                for (outIdx = 0; outIdx < brain_DWork.Erosion_NUMNONZ_DW[1];
                     outIdx++) {
                  if (!brain_DWork.Erosion_TWO_PAD_IMG_DW[brain_DWork.Erosion_ERODE_OFF_DW
                      [outIdx + brain_DWork.Erosion_NUMNONZ_DW[0]] + i_0]) {
                    brain_B.Erosion_d[inIdx] = false;
                    outIdx = brain_DWork.Erosion_NUMNONZ_DW[1];
                  }
                }

                i_0++;
                inIdx++;
              }

              i_0 += 7;
            }

            /* S-Function (svipblob): '<S38>/Blob Analysis' */
            maxNumBlobsReached = false;
            for (i_1 = 0; i_1 < 123; i_1++) {
              brain_DWork.BlobAnalysis_PAD_DW[i_1] = 0U;
            }

            currentLabel = 1U;
            i_1 = 0;
            inIdx = 123;
            for (ku = 0; ku < 160; ku++) {
              for (i = 0; i < 120; i++) {
                brain_DWork.BlobAnalysis_PAD_DW[inIdx] = (uint8_T)
                  (brain_B.Erosion_d[i_1] ? 255 : 0);
                i_1++;
                inIdx++;
              }

              brain_DWork.BlobAnalysis_PAD_DW[inIdx] = 0U;
              inIdx++;
              brain_DWork.BlobAnalysis_PAD_DW[inIdx] = 0U;
              inIdx++;
            }

            for (i_1 = 0; i_1 < 121; i_1++) {
              brain_DWork.BlobAnalysis_PAD_DW[i_1 + inIdx] = 0U;
            }

            ku = 1;
            stackIdx = 0U;
            pixIdx = 0U;
            for (i = 0; i < 160; i++) {
              i_0 = 1;
              inIdx = ku * 122;
              for (outIdx = 0; outIdx < 120; outIdx++) {
                numBlobs = (uint32_T)(inIdx + i_0);
                start_pixIdx = pixIdx;
                if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
                  brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
                  brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(ku -
                    1);
                  brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(i_0
                    - 1);
                  pixIdx++;
                  BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
                  brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
                  stackIdx++;
                  while (stackIdx) {
                    stackIdx--;
                    numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                    for (n = 0; n < 8; n++) {
                      walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled21[n];
                      if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                        brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                          currentLabel;
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
                    i = 160;
                    outIdx = 120;
                  }

                  if (outIdx < 120) {
                    currentLabel++;
                  }
                }

                i_0++;
              }

              ku++;
            }

            numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel : (uint8_T)
                                  (currentLabel - 1));
            outIdx = 0;
            n = 0;
            for (padRows = 0; padRows < (int32_T)numBlobs; padRows++) {
              i_1 = 0;
              ku = 0;
              for (padCols = 0; padCols < (int32_T)
                   BuoyBlobAnalysis_NUM_PIX_DW[padRows]; padCols++) {
                i_1 += brain_DWork.BlobAnalysis_N_PIXLIST_DW[padCols + n];
                ku += brain_DWork.BlobAnalysis_M_PIXLIST_DW[padCols + outIdx];
              }

              centroid_idx = (real32_T)ku / (real32_T)
                BuoyBlobAnalysis_NUM_PIX_DW[padRows];
              centroid_idx_0 = (real32_T)i_1 / (real32_T)
                BuoyBlobAnalysis_NUM_PIX_DW[padRows];
              ku = 160;
              i = 120;
              i_0 = 0;
              inIdx = 0;
              for (padCols = 0; padCols < (int32_T)
                   BuoyBlobAnalysis_NUM_PIX_DW[padRows]; padCols++) {
                i_1 = padCols + n;
                if (brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_1] < ku) {
                  ku = (int32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_1];
                }

                if (brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_1] > i_0) {
                  i_0 = (int32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[i_1];
                }

                i_1 = padCols + outIdx;
                if (brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_1] < i) {
                  i = (int32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_1];
                }

                if (brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_1] > inIdx) {
                  inIdx = (int32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_1];
                }
              }

              xs = 0.0F;
              ys = 0.0F;
              xys = 0.0F;
              walkerIdx = 0U;
              while (1) {
                uLong2MultiWord(walkerIdx, &tmp_0.chunks[0U], 2);
                MultiWordSignedWrap(&tmp_0.chunks[0U], 2, (uint32_T)31,
                                    &tmp.chunks[0U]);
                sLong2MultiWord((int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows],
                                &tmp_1.chunks[0U], 2);
                MultiWordSignedWrap(&tmp_1.chunks[0U], 2, (uint32_T)31,
                                    &tmp_0.chunks[0U]);
                if (!sMultiWordLt(&tmp.chunks[0U], &tmp_0.chunks[0U], 2)) {
                  break;
                }

                majorAxis = (real32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[n +
                  walkerIdx] - centroid_idx_0;
                uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[outIdx +
                  walkerIdx] - centroid_idx;
                xs += majorAxis * majorAxis;
                ys += uyy * uyy;
                xys += majorAxis * (-uyy);
                walkerIdx++;
              }

              centroid_idx = xs / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows]
                + 8.333333582E-02F;
              uyy = ys / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows] +
                8.333333582E-02F;
              xs = xys / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
              xs = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx - uyy) +
                                  xs * xs * 4.0F);
              majorAxis = ((centroid_idx + uyy) + xs) * 8.0F;
              rtb_BlobAnalysis_o1[padRows] = (real32_T)sqrt(majorAxis -
                ((centroid_idx + uyy) - xs) * 8.0F) / (real32_T)sqrt(majorAxis);
              rtb_BlobAnalysis_o2[padRows] = (real32_T)
                BuoyBlobAnalysis_NUM_PIX_DW[padRows] / (real32_T)(((inIdx + 1) -
                i) * ((i_0 + 1) - ku));
              outIdx += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
              n += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
            }

            for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
              rtb_BlobAnalysis_o1[i_1] = -1.0F;
            }

            for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
              rtb_BlobAnalysis_o2[i_1] = -1.0F;
            }

            /* Embedded MATLAB: '<S38>/IF Buoy Conditions' incorporates:
             *  Constant: '<S38>/Constant'
             *  Constant: '<S38>/Constant1'
             *  Constant: '<S38>/Constant2'
             *  Constant: '<S38>/Constant3'
             */
            /* Embedded MATLAB Function 'Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions': '<S41>:1' */
            /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
            /*  if there is a buoy present in the current image */
            /* '<S41>:1:6' */
            brain_B.Image = 0.0;
            for (i_1 = 0; i_1 < 10; i_1++) {
              /* '<S41>:1:8' */
              if (((real_T)rtb_BlobAnalysis_o1[i_1] >
                   brain_P.Buoy_Min_Eccentricity) && ((real_T)
                   rtb_BlobAnalysis_o1[i_1] < brain_P.Buoy_Max_Eccentricity) &&
                  ((real_T)rtb_BlobAnalysis_o2[i_1] > brain_P.Buoy_Min_Extent) &&
                  ((real_T)rtb_BlobAnalysis_o2[i_1] < brain_P.Buoy_Max_Extent))
              {
                /* '<S41>:1:9' */
                /* '<S41>:1:10' */
                brain_B.Image = 1.0;
              }
            }

            maxNumBlobsReached = (brain_B.Image != 0.0);

            /* Embedded MATLAB Function 'countimages': '<S1>:254' */
            /*  This function acts to count the number of consecutive times a particular */
            /*  image is recognized by the recognition software */
            if (maxNumBlobsReached == 1) {
              /* '<S1>:254:6' */
              /* '<S1>:254:7' */
              brain_DWork.BuoyCount = brain_DWork.BuoyCount + 1.0;
            } else {
              /* '<S1>:254:9' */
              brain_DWork.BuoyCount = 0.0;
            }

            /* Simulink Function 'StraightLevelControl': '<S1>:449' */
            brain_B.SFunction_o28 = (real32_T)brain_U.CurrentDepth;
            brain_B.SFunction_o29 = (real32_T)brain_B.DesiredDepth;
            brain_B.SFunction_o30 = brain_B.DesiredHeading;
            brain_B.SFunction_o31 = brain_U.CurrentHeading;
            brain_StraightLevelControl(brain_B.SFunction_o29,
              brain_B.SFunction_o28, brain_B.SFunction_o30,
              brain_B.SFunction_o31, brain_M, &brain_B.StraightLevelControl,
              &brain_DWork.StraightLevelControl, (rtP_StraightLevelControl_brain
              *) &brain_P.StraightLevelControl);
            brain_B.Vertical = brain_B.StraightLevelControl.DoubleToInt8;
            brain_B.Left = brain_B.StraightLevelControl.DoubleToint8;
            brain_B.Right = brain_B.StraightLevelControl.DoubleToint1;
            brain_DWork.OldObstacle = maxNumBlobsReached;
          }
          break;

         case brain_IN_GoAroundBuoy:
          /* During 'GoAroundBuoy': '<S1>:516' */
          switch (brain_DWork.is_GoAroundBuoy) {
           case brain_IN_BackupAndMoveUp:
            /* During 'BackupAndMoveUp': '<S1>:518' */
            if (brain_DWork.Error > -0.5) {
              /* Transition: '<S1>:521' */
              /* Exit 'BackupAndMoveUp': '<S1>:518' */
              /* Entry 'MoveForward': '<S1>:520' */
              brain_DWork.is_GoAroundBuoy = (uint8_T)brain_IN_MoveForward;
              brain_DWork.temporalCounter_i1 = 0U;
            } else {
              /* Simulink Function 'MaintainHeading': '<S1>:458' */
              brain_B.SFunction_o19 = brain_B.DesiredHeading;
              brain_B.SFunction_o20 = brain_U.CurrentHeading;
              brain_B.SFunction_o21 = -10.0;
              brain_MaintainHeading(brain_B.SFunction_o19, brain_B.SFunction_o20,
                                    brain_B.SFunction_o21, brain_M,
                                    &brain_B.MaintainHeading,
                                    &brain_DWork.MaintainHeading);
              brain_B.Left = brain_B.MaintainHeading.DoubleToint8;
              brain_B.Right = brain_B.MaintainHeading.DoubleToint1;

              /* Simulink Function 'MaintainDepth': '<S1>:464' */
              brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
              brain_B.SFunction_o33 = (real32_T)brain_B.DesiredDepth;
              brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32,
                                  brain_M, &brain_B.MaintainDepth,
                                  &brain_DWork.MaintainDepth);
              brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;
              brain_DWork.Error = brain_B.DesiredDepth - brain_U.CurrentDepth;
            }
            break;

           case brain_IN_FinishedwithBuoy:
            break;

           case brain_IN_MoveForward:
            /* During 'MoveForward': '<S1>:520' */
            if ((uint32_T)brain_DWork.temporalCounter_i1 >= 15U) {
              /* Transition: '<S1>:524' */
              /* Exit 'MoveForward': '<S1>:520' */
              /* Entry 'FinishedwithBuoy': '<S1>:522' */
              brain_DWork.is_GoAroundBuoy = (uint8_T)brain_IN_FinishedwithBuoy;
              brain_DWork.BuoyDone = 1.0;
            } else {
              /* Simulink Function 'MaintainHeading': '<S1>:458' */
              brain_B.SFunction_o19 = brain_B.DesiredHeading;
              brain_B.SFunction_o20 = brain_U.CurrentHeading;
              brain_B.SFunction_o21 = 30.0;
              brain_MaintainHeading(brain_B.SFunction_o19, brain_B.SFunction_o20,
                                    brain_B.SFunction_o21, brain_M,
                                    &brain_B.MaintainHeading,
                                    &brain_DWork.MaintainHeading);
              brain_B.Left = brain_B.MaintainHeading.DoubleToint8;
              brain_B.Right = brain_B.MaintainHeading.DoubleToint1;
            }
            break;

           default:
            /* Transition: '<S1>:581' */
            /* Entry 'BackupAndMoveUp': '<S1>:518' */
            brain_DWork.is_GoAroundBuoy = (uint8_T)brain_IN_BackupAndMoveUp;
            brain_DWork.Error = -3.0;
            brain_B.DesiredDepth = brain_U.CurrentDepth - 3.0;
            break;
          }
          break;

         default:
          /* Transition: '<S1>:483' */
          /* Entry 'FindBuoy': '<S1>:239' */
          brain_DWork.is_Buoy = (uint8_T)brain_IN_FindBuoy;
          brain_DWork.OldObstacle = false;
          brain_B.CameraPosition = 0;
          brain_B.State = 4;
          brain_DWork.BuoyCount = 0.0;
          brain_DWork.BuoyDone = 0.0;
          break;
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
        brain_B.State = 1;
      } else if (brain_U.DesiredState == 2) {
        /* Transition: '<S1>:303' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'ValidationGate': '<S1>:1' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ValidationGate;
        brain_DWork.OldObstacle = false;
        brain_DWork.count = 0.0;
        brain_DWork.TrackCount = 0.0;
        brain_B.State = 2;
        brain_B.CameraPosition = 2;
      } else if (brain_U.DesiredState == 4) {
        /* Transition: '<S1>:320' */
        /* Exit 'ChooseState': '<S1>:299' */
        /* Entry 'Buoy': '<S1>:470' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_Buoy;

        /* Transition: '<S1>:483' */
        /* Entry 'FindBuoy': '<S1>:239' */
        brain_DWork.is_Buoy = (uint8_T)brain_IN_FindBuoy;
        brain_DWork.OldObstacle = false;
        brain_B.CameraPosition = 0;
        brain_B.State = 4;
        brain_DWork.BuoyCount = 0.0;
        brain_DWork.BuoyDone = 0.0;
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
        brain_B.State = 3;
        brain_B.CameraPosition = 2;

        /* Simulink Function 'MakeHSVImage': '<S1>:380' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.SFunction_o14[i_1] = (real_T)brain_B.Resize[i_1];
          brain_B.SFunction_o15[i_1] = (real_T)brain_B.Resize1[i_1];
          brain_B.SFunction_o16[i_1] = (real_T)brain_B.Resize2[i_1];
        }

        RunningAutonomousFollowOnePathM(brain_B.SFunction_o14,
          brain_B.SFunction_o15, brain_B.SFunction_o16,
          &brain_B.RunningAutonomousFollowOnePat_i);
      } else {
        if (brain_U.DesiredState == 5) {
          /* Transition: '<S1>:579' */
          /* Exit 'ChooseState': '<S1>:299' */
          /* Entry 'FollowOnePath1': '<S1>:528' */
          brain_DWork.is_Autonomous = (uint8_T)brain_IN_FollowOnePath1;

          /* Transition: '<S1>:529' */
          /* Entry 'Initialize': '<S1>:572' */
          brain_DWork.is_FollowOnePath1 = (uint8_T)brain_IN_Initialize;
          brain_B.DesiredDepth = 5.0;
          brain_B.DesiredHeading = 0.0;
          brain_DWork.Done = 0.0;
          brain_B.State = 5;
          brain_B.CameraPosition = 2;

          /* Simulink Function 'MakeHSVImage': '<S1>:573' */
          for (i_1 = 0; i_1 < 19200; i_1++) {
            brain_B.SFunction_o42[i_1] = (real_T)brain_B.Resize[i_1];
            brain_B.SFunction_o43[i_1] = (real_T)brain_B.Resize1[i_1];
            brain_B.SFunction_o44[i_1] = (real_T)brain_B.Resize2[i_1];
          }

          RunningAutonomousFollowOnePathM(brain_B.SFunction_o42,
            brain_B.SFunction_o43, brain_B.SFunction_o44,
            &brain_B.RunningAutonomousFollowOnePath1);
        }
      }
      break;

     case brain_IN_Finish:
      /* During 'Finish': '<S1>:151' */
      if ((brain_U.DesiredState != 6) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:469' */
        /* Exit 'Finish': '<S1>:151' */
        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      }
      break;

     case brain_IN_FollowOnePath:
      /* During 'FollowOnePath': '<S1>:325' */
      if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
        /* Transition: '<S1>:240' */
        bra_exit_internal_FollowOnePath();

        /* Exit 'FollowOnePath': '<S1>:325' */
        /* Entry 'Buoy': '<S1>:470' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_Buoy;

        /* Transition: '<S1>:483' */
        /* Entry 'FindBuoy': '<S1>:239' */
        brain_DWork.is_Buoy = (uint8_T)brain_IN_FindBuoy;
        brain_DWork.OldObstacle = false;
        brain_B.CameraPosition = 0;
        brain_B.State = 4;
        brain_DWork.BuoyCount = 0.0;
        brain_DWork.BuoyDone = 0.0;
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
          brain_B.State = 3;
          brain_B.CameraPosition = 2;

          /* Simulink Function 'MakeHSVImage': '<S1>:380' */
          for (i_1 = 0; i_1 < 19200; i_1++) {
            brain_B.SFunction_o14[i_1] = (real_T)brain_B.Resize[i_1];
            brain_B.SFunction_o15[i_1] = (real_T)brain_B.Resize1[i_1];
            brain_B.SFunction_o16[i_1] = (real_T)brain_B.Resize2[i_1];
          }

          RunningAutonomousFollowOnePathM(brain_B.SFunction_o14,
            brain_B.SFunction_o15, brain_B.SFunction_o16,
            &brain_B.RunningAutonomousFollowOnePat_i);
          break;
        }
      }
      break;

     case brain_IN_FollowOnePath1:
      brain_FollowOnePath1();
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
        brain_DWork.OldObstacle = false;
        brain_DWork.count = 0.0;
        brain_DWork.TrackCount = 0.0;
        brain_B.State = 2;
        brain_B.CameraPosition = 2;
      } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState != 0)) {
        /* Transition: '<S1>:300' */
        /* Exit 'Start': '<S1>:153' */
        brain_B.DesiredHeading = brain_U.CurrentHeading;

        /* Entry 'ChooseState': '<S1>:299' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_ChooseState;
      } else {
        brain_DWork.DesiredHeadingCount = brain_InitialHeadingCount
          (brain_U.CurrentHeading, brain_DWork.OldHeading,
           brain_DWork.DesiredHeadingCount);
        brain_DWork.OldHeading = brain_U.CurrentHeading;
        brain_B.DesiredDepth = 5.0;
      }
      break;

     case brain_IN_ValidationGate:
      brain_ValidationGate();
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
      brain_B.State = 1;
      break;
    }
  }
}

/* Initial conditions for atomic system: '<Root>/Chart' */
void brain_Chart_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/Chart' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/MaintainDepth'
   *  InitializeConditions for SubSystem: '<S1>/MaintainHeading'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.Buoy.ApproachBuoy.Buoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.Buoy.FindBuoy.LookforBuoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings'
   *  InitializeConditions for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  InitializeConditions for SubSystem: '<S1>/StraightLevelControl'
   */
  brain_DWork.is_Running = 0U;
  brain_DWork.is_Autonomous = 0U;
  brain_DWork.is_Buoy = 0U;
  brain_DWork.is_GoAroundBuoy = 0U;
  brain_DWork.is_FollowOnePath = 0U;
  brain_DWork.is_OnePath = 0U;
  brain_DWork.is_FollowOnePath1 = 0U;
  brain_DWork.is_OnePath_b = 0U;
  brain_DWork.is_active_c1_brain = 0U;
  brain_DWork.is_c1_brain = 0U;
  brain_DWork.count = 0.0;
  brain_DWork.OldObstacle = false;
  brain_DWork.BuoyDone = 0.0;
  brain_DWork.countarea = 0.0;
  brain_DWork.DesiredHeadingCount = 0.0;
  brain_DWork.OldHeading = 0.0;
  brain_DWork.TrackCount = 0.0;
  brain_DWork.BuoyCount = 0.0;
  brain_DWork.AvgDesiredHeadingAlongPath[0] = 0.0;
  brain_DWork.AvgDesiredHeadingToPath[0] = 0.0;
  brain_DWork.AvgDesiredHeadingAlongPath[1] = 0.0;
  brain_DWork.AvgDesiredHeadingToPath[1] = 0.0;
  brain_DWork.countAlong = 0.0;
  brain_DWork.countTo = 0.0;
  brain_DWork.outliersAlong = 0.0;
  brain_DWork.outliersTo = 0.0;
  brain_DWork.Done = 0.0;
  brain_DWork.Error = 0.0;
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
  brain_DWork.presentTicks = 0U;
  brain_DWork.elapsedTicks = 0U;
  brain_DWork.previousTicks = 0U;
  brain_DWork.RunningAutonomousBuoyApproach_d = brain_M->Timing.clockTick0;
  brain_MaintainHeading_Init(brain_M, &brain_DWork.MaintainHeading);
  brain_StraightLevelControl_Init(brain_M, &brain_DWork.StraightLevelControl);
  brain_MaintainDepth_Init(brain_M, &brain_DWork.MaintainDepth);
  RunningAutonomousFollowO_l_Init(brain_M,
    &brain_DWork.RunningAutonomousFollowOneP_oc4);
  RunningAutonomousFollowO_l_Init(brain_M,
    &brain_DWork.RunningAutonomousFollowOnePat_g);
}

/* Enable for atomic system: '<Root>/Chart' */
void brain_Chart_Enable(void)
{
  /* Enable for Stateflow: '<Root>/Chart' incorporates:
   *  Enable for SubSystem: '<S1>/MaintainDepth'
   *  Enable for SubSystem: '<S1>/MaintainHeading'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.Buoy.ApproachBuoy.Buoy'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.Buoy.FindBuoy.LookforBuoy'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings'
   *  Enable for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  Enable for SubSystem: '<S1>/StraightLevelControl'
   */
  brain_StraightLevelControl_Init(brain_M, &brain_DWork.StraightLevelControl);
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
}

/* Disable for atomic system: '<Root>/Chart' */
void brain_Chart_Disable(void)
{
  /* Disable for Stateflow: '<Root>/Chart' incorporates:
   *  Disable for SubSystem: '<S1>/MaintainDepth'
   *  Disable for SubSystem: '<S1>/MaintainHeading'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.Buoy.ApproachBuoy.Buoy'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.Buoy.FindBuoy.LookforBuoy'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings'
   *  Disable for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  Disable for SubSystem: '<S1>/StraightLevelControl'
   */
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.elapsedTicks = brain_DWork.presentTicks -
    brain_DWork.previousTicks;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
  if ((uint32_T)brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks <= 15U)
  {
    brain_DWork.temporalCounter_i1 = (uint8_T)((uint32_T)
      brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks);
  } else {
    brain_DWork.temporalCounter_i1 = 15U;
  }

  brain_MaintainHeading_Disable(&brain_B.MaintainHeading,
    &brain_DWork.MaintainHeading);
  br_StraightLevelControl_Disable(&brain_B.StraightLevelControl,
    &brain_DWork.StraightLevelControl);
}

/* Start for atomic system: '<Root>/Chart' */
void brain_Chart_Start(void)
{
  {
    int32_T idxNHood;
    int32_T idxOffsets;
    int32_T nhIdx;
    int32_T idxNHood_0;
    int32_T idxOffsets_0;
    int32_T nhIdx_0;
    int32_T m;

    /* Start for Stateflow: '<Root>/Chart' incorporates:
     *  Start for SubSystem: '<S1>/MaintainDepth'
     *  Start for SubSystem: '<S1>/MaintainHeading'
     *  Start for SubSystem: '<S1>/Running.Autonomous.Buoy.ApproachBuoy.Buoy'
     *  Start for SubSystem: '<S1>/Running.Autonomous.Buoy.FindBuoy.LookforBuoy'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
     *  Start for SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings'
     *  Start for SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
     *  Start for SubSystem: '<S1>/StraightLevelControl'
     */

    /* Start for S-Function (svipmorphop): '<S9>/Dilation' */
    idxOffsets = 0;
    idxNHood_0 = 0;
    idxNHood = 4;
    for (nhIdx_0 = 0; nhIdx_0 < 2; nhIdx_0++) {
      for (m = 0; m < 2; m++) {
        idxNHood--;
        if (brain_ConstP.pooled24[idxNHood]) {
          brain_DWork.Dilation_DILATE_OFF_DW_h[idxOffsets] = nhIdx_0 * 123 + m;
          idxNHood_0++;
          idxOffsets++;
        }
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW_c = idxNHood_0;

    /* Start for S-Function (svipmorphop): '<S9>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 1; nhIdx_0 = 1) {
      for (nhIdx = 0; nhIdx < 4; nhIdx++) {
        if (brain_ConstP.pooled25[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_g[idxOffsets] = nhIdx;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_f[0] = idxOffsets_0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 4; nhIdx_0++) {
      for (nhIdx = 0; nhIdx < 1; nhIdx = 1) {
        if (brain_ConstP.pooled25[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_g[idxOffsets] = nhIdx_0 * 127;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_f[1] = idxOffsets_0;
    brain_MaintainHeading_Start(brain_M, &brain_DWork.MaintainHeading);

    /* Start for S-Function (svipmorphop): '<S38>/Dilation' */
    idxOffsets_0 = 0;
    idxNHood = 0;
    idxNHood_0 = 4;
    for (nhIdx = 0; nhIdx < 2; nhIdx++) {
      for (m = 0; m < 2; m++) {
        idxNHood_0--;
        if (brain_ConstP.pooled24[idxNHood_0]) {
          brain_DWork.Dilation_DILATE_OFF_DW[idxOffsets_0] = nhIdx * 123 + m;
          idxNHood++;
          idxOffsets_0++;
        }
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW = idxNHood;

    /* Start for S-Function (svipmorphop): '<S38>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 1; nhIdx_0 = 1) {
      for (nhIdx = 0; nhIdx < 4; nhIdx++) {
        if (brain_ConstP.pooled25[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW[idxOffsets] = nhIdx;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW[0] = idxOffsets_0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 4; nhIdx_0++) {
      for (nhIdx = 0; nhIdx < 1; nhIdx = 1) {
        if (brain_ConstP.pooled25[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW[idxOffsets] = nhIdx_0 * 127;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW[1] = idxOffsets_0;
    brai_StraightLevelControl_Start(brain_M, &brain_DWork.StraightLevelControl);
  }
}

/* Output and update for atomic system: '<Root>/Chart' */
void brain_Chart(void)
{
  /* Stateflow: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/CurrentDepth'
   *  Inport: '<Root>/CurrentHeading'
   *  Inport: '<Root>/RC'
   *  Inport: '<Root>/RC_Depth'
   *  Inport: '<Root>/RC_ForwardVelocity'
   *  Inport: '<Root>/RC_Heading'
   *  Inport: '<Root>/RC_Strafe'
   *  Inport: '<Root>/Status'
   *  SubSystem: '<S1>/MaintainDepth'
   *  SubSystem: '<S1>/MaintainHeading'
   *  SubSystem: '<S1>/Running.Autonomous.Buoy.ApproachBuoy.Buoy'
   *  SubSystem: '<S1>/Running.Autonomous.Buoy.FindBuoy.LookforBuoy'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  SubSystem: '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings'
   *  SubSystem: '<S1>/Running.Autonomous.ValidationGate.LookforTrack'
   *  SubSystem: '<S1>/StraightLevelControl'
   */
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.elapsedTicks = brain_DWork.presentTicks -
    brain_DWork.previousTicks;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
  if ((uint32_T)brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks <= 15U)
  {
    brain_DWork.temporalCounter_i1 = (uint8_T)((uint32_T)
      brain_DWork.temporalCounter_i1 + brain_DWork.elapsedTicks);
  } else {
    brain_DWork.temporalCounter_i1 = 15U;
  }

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
    brain_B.State = -2;
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
        brain_B.State = 1;
      }
      break;

     case brain_IN_Running:
      /* During 'Running': '<S1>:435' */
      if (brain_U.Status != 1) {
        /* Transition: '<S1>:292' */
        if (brain_DWork.is_Running == brain_IN_Autonomous) {
          brain_exit_internal_Autonomous();

          /* Exit 'Autonomous': '<S1>:289' */
          brain_DWork.is_Running = (uint8_T)0;
        } else {
          /* Exit 'ControlledRC': '<S1>:408' */
        }

        /* Exit 'Running': '<S1>:435' */
        /* Entry 'NotRunning': '<S1>:291' */
        brain_DWork.is_c1_brain = (uint8_T)brain_IN_NotRunning;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Vertical = 0;
        brain_B.State = -2;
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
            brain_B.State = 1;
          } else {
            /* Simulink Function 'MaintainDepth': '<S1>:464' */
            brain_B.SFunction_o32 = (real32_T)brain_U.CurrentDepth;
            brain_B.SFunction_o33 = (real32_T)brain_U.RC_Depth;
            brain_MaintainDepth(brain_B.SFunction_o33, brain_B.SFunction_o32,
                                brain_M, &brain_B.MaintainDepth,
                                &brain_DWork.MaintainDepth);
            brain_B.Vertical = brain_B.MaintainDepth.DoubleToInt8;

            /* Simulink Function 'MaintainHeading': '<S1>:458' */
            brain_B.SFunction_o19 = brain_U.RC_Heading;
            brain_B.SFunction_o20 = brain_U.CurrentHeading;
            brain_B.SFunction_o21 = brain_U.RC_ForwardVelocity;
            brain_MaintainHeading(brain_B.SFunction_o19, brain_B.SFunction_o20,
                                  brain_B.SFunction_o21, brain_M,
                                  &brain_B.MaintainHeading,
                                  &brain_DWork.MaintainHeading);
            brain_B.Left = brain_B.MaintainHeading.DoubleToint8;
            brain_B.Right = brain_B.MaintainHeading.DoubleToint1;
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
          brain_B.State = 1;
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
      brain_B.State = -2;
      break;
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

    /* S-Function (svipchromresamp): '<S6>/Chroma Resampling' incorporates:
     *  Inport: '<Root>/Cb'
     *  Inport: '<Root>/Cr'
     */
    outStep = 0;
    inStep = 0;
    for (n = 0; n < 320; n++) {
      o = inStep;
      for (m = 0; m < 240; m++) {
        k = m << 1;
        brain_B.ChromaResampling_o1[outStep + k] = brain_U.Cb[o];
        brain_B.ChromaResampling_o1[(outStep + k) + 1] = brain_U.Cb[o];
        k += 480;
        brain_B.ChromaResampling_o1[outStep + k] = brain_U.Cb[o];
        brain_B.ChromaResampling_o1[(outStep + k) + 1] = brain_U.Cb[o];
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
        brain_B.ChromaResampling_o2[outStep + k] = brain_U.Cr[o];
        brain_B.ChromaResampling_o2[(outStep + k) + 1] = brain_U.Cr[o];
        k += 480;
        brain_B.ChromaResampling_o2[outStep + k] = brain_U.Cr[o];
        brain_B.ChromaResampling_o2[(outStep + k) + 1] = brain_U.Cr[o];
        o++;
      }

      inStep += 240;
      outStep += 960;
    }

    /* S-Function (svipcolorconv): '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' incorporates:
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
      /* S-Function (svipscalenconvert): '<S6>/Red Data Type Conversion' */
      brain_B.RGBtoHSVColorSpaceConversion_o1[outStep] = (real32_T)
        brain_B.RGBVid_R[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S6>/Green Data Type Conversion1' */
      brain_B.RGBtoHSVColorSpaceConversion_o2[outStep] = (real32_T)
        brain_B.RGBVid_G[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S6>/Blue Data Type Conversion2' */
      brain_B.RGBtoHSVColorSpaceConversion_o3[outStep] = (real32_T)
        brain_B.RGBVid_B[outStep] / 255.0F;
    }

    /* S-Function (svipcolorconv): '<S6>/RGB to HSV Color Space  Conversion' */
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

    /* Video Processing Blockset 2D Resize (svipresize) - '<S6>/Resize' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o1;
      real32_T *out = brain_B.Resize;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled18[0];
      const real32_T *pW = &brain_ConstP.pooled15[0];
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

      pW = &brain_ConstP.pooled14[0];
      pI = &brain_ConstP.pooled17[0];
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

    /* Video Processing Blockset 2D Resize (svipresize) - '<S6>/Resize1' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o2;
      real32_T *out = brain_B.Resize1;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled18[0];
      const real32_T *pW = &brain_ConstP.pooled15[0];
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

      pW = &brain_ConstP.pooled14[0];
      pI = &brain_ConstP.pooled17[0];
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

    /* Video Processing Blockset 2D Resize (svipresize) - '<S6>/Resize2' */
    {
      const real32_T *in = brain_B.RGBtoHSVColorSpaceConversion_o3;
      real32_T *out = brain_B.Resize2;
      real32_T *intBuf = &brain_DWork.Resize_IntBuffer[0];
      const int_T *pI = &brain_ConstP.pooled18[0];
      const real32_T *pW = &brain_ConstP.pooled15[0];
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

      pW = &brain_ConstP.pooled14[0];
      pI = &brain_ConstP.pooled17[0];
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
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[0] =
      -1.5707963267948966E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[1] =
      -1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[2] =
      -1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[3] =
      -1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[4] =
      -1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[5] =
      -1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[6] =
      -1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[7] =
      -1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[8] =
      -1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[9] =
      -1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[10] =
      -1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[11] =
      -1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[12] =
      -1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[13] =
      -1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[14] =
      -1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[15] =
      -1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[16] =
      -1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[17] =
      -1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[18] =
      -1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[19] =
      -1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[20] =
      -1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[21] =
      -1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[22] =
      -1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[23] =
      -1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[24] =
      -1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[25] =
      -1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[26] =
      -1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[27] =
      -1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[28] =
      -1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[29] =
      -1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[30] =
      -1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[31] =
      -1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[32] =
      -1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[33] =
      -9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[34] =
      -9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[35] =
      -9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[36] =
      -9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[37] =
      -9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[38] =
      -9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[39] =
      -8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[40] =
      -8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[41] =
      -8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[42] =
      -8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[43] =
      -8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[44] =
      -8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[45] =
      -7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[46] =
      -7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[47] =
      -7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[48] =
      -7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[49] =
      -7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[50] =
      -6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[51] =
      -6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[52] =
      -6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[53] =
      -6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[54] =
      -6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[55] =
      -6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[56] =
      -5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[57] =
      -5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[58] =
      -5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[59] =
      -5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[60] =
      -5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[61] =
      -5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[62] =
      -4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[63] =
      -4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[64] =
      -4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[65] =
      -4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[66] =
      -4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[67] =
      -4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[68] =
      -3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[69] =
      -3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[70] =
      -3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[71] =
      -3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[72] =
      -3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[73] =
      -2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[74] =
      -2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[75] =
      -2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[76] =
      -2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[77] =
      -2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[78] =
      -2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[79] =
      -1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[80] =
      -1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[81] =
      -1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[82] =
      -1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[83] =
      -1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[84] =
      -1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[85] =
      -8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[86] =
      -6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[87] =
      -5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[88] =
      -3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[89] =
      -1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[90] = 0.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[91] =
      1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[92] =
      3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[93] =
      5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[94] =
      6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[95] =
      8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[96] =
      1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[97] =
      1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[98] =
      1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[99] =
      1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[100] =
      1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[101] =
      1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[102] =
      2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[103] =
      2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[104] =
      2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[105] =
      2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[106] =
      2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[107] =
      2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[108] =
      3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[109] =
      3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[110] =
      3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[111] =
      3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[112] =
      3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[113] =
      4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[114] =
      4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[115] =
      4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[116] =
      4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[117] =
      4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[118] =
      4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[119] =
      5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[120] =
      5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[121] =
      5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[122] =
      5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[123] =
      5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[124] =
      5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[125] =
      6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[126] =
      6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[127] =
      6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[128] =
      6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[129] =
      6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[130] =
      6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[131] =
      7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[132] =
      7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[133] =
      7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[134] =
      7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[135] =
      7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[136] =
      8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[137] =
      8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[138] =
      8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[139] =
      8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[140] =
      8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[141] =
      8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[142] =
      9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[143] =
      9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[144] =
      9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[145] =
      9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[146] =
      9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[147] =
      9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[148] =
      1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[149] =
      1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[150] =
      1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[151] =
      1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[152] =
      1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[153] =
      1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[154] =
      1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[155] =
      1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[156] =
      1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[157] =
      1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[158] =
      1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[159] =
      1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[160] =
      1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[161] =
      1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[162] =
      1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[163] =
      1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[164] =
      1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[165] =
      1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[166] =
      1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[167] =
      1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[168] =
      1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[169] =
      1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[170] =
      1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[171] =
      1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[172] =
      1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[173] =
      1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[174] =
      1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[175] =
      1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[176] =
      1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[177] =
      1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[178] =
      1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2[179] =
      1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[0] = -143.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[1] = -142.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[2] = -141.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[3] = -140.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[4] = -139.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[5] = -138.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[6] = -137.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[7] = -136.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[8] = -135.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[9] = -134.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[10] = -133.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[11] = -132.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[12] = -131.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[13] = -130.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[14] = -129.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[15] = -128.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[16] = -127.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[17] = -126.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[18] = -125.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[19] = -124.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[20] = -123.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[21] = -122.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[22] = -121.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[23] = -120.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[24] = -119.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[25] = -118.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[26] = -117.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[27] = -116.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[28] = -115.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[29] = -114.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[30] = -113.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[31] = -112.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[32] = -111.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[33] = -110.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[34] = -109.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[35] = -108.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[36] = -107.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[37] = -106.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[38] = -105.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[39] = -104.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[40] = -103.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[41] = -102.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[42] = -101.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[43] = -100.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[44] = -99.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[45] = -98.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[46] = -97.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[47] = -96.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[48] = -95.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[49] = -94.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[50] = -93.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[51] = -92.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[52] = -91.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[53] = -90.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[54] = -89.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[55] = -88.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[56] = -87.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[57] = -86.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[58] = -85.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[59] = -84.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[60] = -83.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[61] = -82.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[62] = -81.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[63] = -80.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[64] = -79.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[65] = -78.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[66] = -77.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[67] = -76.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[68] = -75.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[69] = -74.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[70] = -73.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[71] = -72.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[72] = -71.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[73] = -70.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[74] = -69.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[75] = -68.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[76] = -67.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[77] = -66.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[78] = -65.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[79] = -64.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[80] = -63.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[81] = -62.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[82] = -61.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[83] = -60.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[84] = -59.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[85] = -58.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[86] = -57.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[87] = -56.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[88] = -55.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[89] = -54.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[90] = -53.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[91] = -52.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[92] = -51.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[93] = -50.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[94] = -49.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[95] = -48.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[96] = -47.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[97] = -46.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[98] = -45.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[99] = -44.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[100] = -43.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[101] = -42.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[102] = -41.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[103] = -40.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[104] = -39.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[105] = -38.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[106] = -37.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[107] = -36.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[108] = -35.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[109] = -34.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[110] = -33.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[111] = -32.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[112] = -31.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[113] = -30.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[114] = -29.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[115] = -28.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[116] = -27.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[117] = -26.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[118] = -25.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[119] = -24.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[120] = -23.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[121] = -22.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[122] = -21.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[123] = -20.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[124] = -19.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[125] = -18.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[126] = -17.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[127] = -16.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[128] = -15.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[129] = -14.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[130] = -13.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[131] = -12.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[132] = -11.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[133] = -10.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[134] = -9.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[135] = -8.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[136] = -7.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[137] = -6.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[138] = -5.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[139] = -4.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[140] = -3.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[141] = -2.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[142] = -1.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[143] = 0.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[144] = 1.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[145] = 2.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[146] = 3.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[147] = 4.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[148] = 5.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[149] = 6.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[150] = 7.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[151] = 8.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[152] = 9.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[153] = 10.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[154] = 11.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[155] = 12.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[156] = 13.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[157] = 14.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[158] = 15.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[159] = 16.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[160] = 17.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[161] = 18.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[162] = 19.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[163] = 20.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[164] = 21.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[165] = 22.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[166] = 23.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[167] = 24.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[168] = 25.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[169] = 26.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[170] = 27.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[171] = 28.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[172] = 29.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[173] = 30.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[174] = 31.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[175] = 32.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[176] = 33.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[177] = 34.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[178] = 35.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[179] = 36.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[180] = 37.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[181] = 38.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[182] = 39.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[183] = 40.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[184] = 41.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[185] = 42.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[186] = 43.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[187] = 44.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[188] = 45.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[189] = 46.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[190] = 47.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[191] = 48.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[192] = 49.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[193] = 50.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[194] = 51.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[195] = 52.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[196] = 53.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[197] = 54.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[198] = 55.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[199] = 56.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[200] = 57.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[201] = 58.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[202] = 59.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[203] = 60.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[204] = 61.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[205] = 62.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[206] = 63.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[207] = 64.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[208] = 65.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[209] = 66.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[210] = 67.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[211] = 68.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[212] = 69.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[213] = 70.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[214] = 71.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[215] = 72.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[216] = 73.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[217] = 74.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[218] = 75.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[219] = 76.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[220] = 77.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[221] = 78.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[222] = 79.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[223] = 80.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[224] = 81.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[225] = 82.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[226] = 83.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[227] = 84.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[228] = 85.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[229] = 86.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[230] = 87.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[231] = 88.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[232] = 89.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[233] = 90.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[234] = 91.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[235] = 92.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[236] = 93.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[237] = 94.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[238] = 95.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[239] = 96.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[240] = 97.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[241] = 98.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[242] = 99.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[243] = 100.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[244] = 101.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[245] = 102.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[246] = 103.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[247] = 104.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[248] = 105.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[249] = 106.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[250] = 107.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[251] = 108.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[252] = 109.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[253] = 110.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[254] = 111.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[255] = 112.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[256] = 113.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[257] = 114.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[258] = 115.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[259] = 116.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[260] = 117.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[261] = 118.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[262] = 119.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[263] = 120.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[264] = 121.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[265] = 122.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[266] = 123.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[267] = 124.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[268] = 125.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[269] = 126.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[270] = 127.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[271] = 128.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[272] = 129.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[273] = 130.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[274] = 131.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[275] = 132.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[276] = 133.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[277] = 134.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[278] = 135.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[279] = 136.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[280] = 137.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[281] = 138.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[282] = 139.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[283] = 140.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[284] = 141.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[285] = 142.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3[286] = 143.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[0] =
      -1.5707963267948966E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[1] =
      -1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[2] =
      -1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[3] =
      -1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[4] =
      -1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[5] =
      -1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[6] =
      -1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[7] =
      -1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[8] =
      -1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[9] =
      -1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[10] =
      -1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[11] =
      -1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[12] =
      -1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[13] =
      -1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[14] =
      -1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[15] =
      -1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[16] =
      -1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[17] =
      -1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[18] =
      -1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[19] =
      -1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[20] =
      -1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[21] =
      -1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[22] =
      -1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[23] =
      -1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[24] =
      -1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[25] =
      -1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[26] =
      -1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[27] =
      -1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[28] =
      -1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[29] =
      -1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[30] =
      -1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[31] =
      -1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[32] =
      -1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[33] =
      -9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[34] =
      -9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[35] =
      -9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[36] =
      -9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[37] =
      -9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[38] =
      -9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[39] =
      -8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[40] =
      -8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[41] =
      -8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[42] =
      -8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[43] =
      -8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[44] =
      -8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[45] =
      -7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[46] =
      -7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[47] =
      -7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[48] =
      -7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[49] =
      -7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[50] =
      -6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[51] =
      -6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[52] =
      -6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[53] =
      -6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[54] =
      -6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[55] =
      -6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[56] =
      -5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[57] =
      -5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[58] =
      -5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[59] =
      -5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[60] =
      -5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[61] =
      -5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[62] =
      -4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[63] =
      -4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[64] =
      -4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[65] =
      -4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[66] =
      -4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[67] =
      -4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[68] =
      -3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[69] =
      -3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[70] =
      -3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[71] =
      -3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[72] =
      -3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[73] =
      -2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[74] =
      -2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[75] =
      -2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[76] =
      -2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[77] =
      -2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[78] =
      -2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[79] =
      -1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[80] =
      -1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[81] =
      -1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[82] =
      -1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[83] =
      -1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[84] =
      -1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[85] =
      -8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[86] =
      -6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[87] =
      -5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[88] =
      -3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[89] =
      -1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[90] = 0.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[91] =
      1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[92] =
      3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[93] =
      5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[94] =
      6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[95] =
      8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[96] =
      1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[97] =
      1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[98] =
      1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[99] =
      1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[100] =
      1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[101] =
      1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[102] =
      2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[103] =
      2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[104] =
      2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[105] =
      2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[106] =
      2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[107] =
      2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[108] =
      3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[109] =
      3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[110] =
      3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[111] =
      3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[112] =
      3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[113] =
      4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[114] =
      4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[115] =
      4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[116] =
      4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[117] =
      4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[118] =
      4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[119] =
      5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[120] =
      5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[121] =
      5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[122] =
      5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[123] =
      5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[124] =
      5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[125] =
      6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[126] =
      6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[127] =
      6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[128] =
      6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[129] =
      6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[130] =
      6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[131] =
      7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[132] =
      7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[133] =
      7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[134] =
      7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[135] =
      7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[136] =
      8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[137] =
      8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[138] =
      8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[139] =
      8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[140] =
      8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[141] =
      8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[142] =
      9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[143] =
      9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[144] =
      9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[145] =
      9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[146] =
      9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[147] =
      9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[148] =
      1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[149] =
      1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[150] =
      1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[151] =
      1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[152] =
      1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[153] =
      1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[154] =
      1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[155] =
      1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[156] =
      1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[157] =
      1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[158] =
      1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[159] =
      1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[160] =
      1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[161] =
      1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[162] =
      1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[163] =
      1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[164] =
      1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[165] =
      1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[166] =
      1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[167] =
      1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[168] =
      1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[169] =
      1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[170] =
      1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[171] =
      1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[172] =
      1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[173] =
      1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[174] =
      1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[175] =
      1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[176] =
      1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[177] =
      1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[178] =
      1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o2_m[179] =
      1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[0] = -143.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[1] = -142.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[2] = -141.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[3] = -140.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[4] = -139.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[5] = -138.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[6] = -137.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[7] = -136.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[8] = -135.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[9] = -134.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[10] = -133.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[11] = -132.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[12] = -131.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[13] = -130.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[14] = -129.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[15] = -128.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[16] = -127.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[17] = -126.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[18] = -125.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[19] = -124.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[20] = -123.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[21] = -122.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[22] = -121.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[23] = -120.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[24] = -119.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[25] = -118.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[26] = -117.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[27] = -116.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[28] = -115.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[29] = -114.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[30] = -113.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[31] = -112.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[32] = -111.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[33] = -110.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[34] = -109.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[35] = -108.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[36] = -107.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[37] = -106.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[38] = -105.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[39] = -104.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[40] = -103.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[41] = -102.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[42] = -101.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[43] = -100.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[44] = -99.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[45] = -98.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[46] = -97.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[47] = -96.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[48] = -95.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[49] = -94.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[50] = -93.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[51] = -92.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[52] = -91.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[53] = -90.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[54] = -89.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[55] = -88.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[56] = -87.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[57] = -86.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[58] = -85.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[59] = -84.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[60] = -83.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[61] = -82.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[62] = -81.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[63] = -80.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[64] = -79.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[65] = -78.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[66] = -77.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[67] = -76.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[68] = -75.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[69] = -74.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[70] = -73.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[71] = -72.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[72] = -71.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[73] = -70.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[74] = -69.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[75] = -68.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[76] = -67.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[77] = -66.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[78] = -65.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[79] = -64.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[80] = -63.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[81] = -62.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[82] = -61.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[83] = -60.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[84] = -59.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[85] = -58.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[86] = -57.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[87] = -56.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[88] = -55.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[89] = -54.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[90] = -53.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[91] = -52.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[92] = -51.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[93] = -50.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[94] = -49.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[95] = -48.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[96] = -47.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[97] = -46.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[98] = -45.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[99] = -44.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[100] = -43.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[101] = -42.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[102] = -41.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[103] = -40.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[104] = -39.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[105] = -38.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[106] = -37.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[107] = -36.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[108] = -35.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[109] = -34.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[110] = -33.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[111] = -32.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[112] = -31.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[113] = -30.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[114] = -29.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[115] = -28.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[116] = -27.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[117] = -26.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[118] = -25.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[119] = -24.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[120] = -23.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[121] = -22.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[122] = -21.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[123] = -20.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[124] = -19.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[125] = -18.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[126] = -17.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[127] = -16.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[128] = -15.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[129] = -14.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[130] = -13.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[131] = -12.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[132] = -11.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[133] = -10.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[134] = -9.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[135] = -8.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[136] = -7.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[137] = -6.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[138] = -5.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[139] = -4.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[140] = -3.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[141] = -2.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[142] = -1.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[143] = 0.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[144] = 1.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[145] = 2.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[146] = 3.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[147] = 4.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[148] = 5.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[149] = 6.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[150] = 7.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[151] = 8.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[152] = 9.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[153] = 10.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[154] = 11.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[155] = 12.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[156] = 13.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[157] = 14.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[158] = 15.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[159] = 16.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[160] = 17.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[161] = 18.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[162] = 19.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[163] = 20.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[164] = 21.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[165] = 22.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[166] = 23.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[167] = 24.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[168] = 25.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[169] = 26.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[170] = 27.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[171] = 28.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[172] = 29.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[173] = 30.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[174] = 31.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[175] = 32.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[176] = 33.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[177] = 34.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[178] = 35.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[179] = 36.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[180] = 37.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[181] = 38.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[182] = 39.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[183] = 40.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[184] = 41.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[185] = 42.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[186] = 43.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[187] = 44.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[188] = 45.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[189] = 46.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[190] = 47.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[191] = 48.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[192] = 49.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[193] = 50.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[194] = 51.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[195] = 52.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[196] = 53.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[197] = 54.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[198] = 55.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[199] = 56.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[200] = 57.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[201] = 58.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[202] = 59.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[203] = 60.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[204] = 61.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[205] = 62.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[206] = 63.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[207] = 64.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[208] = 65.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[209] = 66.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[210] = 67.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[211] = 68.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[212] = 69.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[213] = 70.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[214] = 71.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[215] = 72.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[216] = 73.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[217] = 74.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[218] = 75.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[219] = 76.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[220] = 77.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[221] = 78.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[222] = 79.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[223] = 80.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[224] = 81.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[225] = 82.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[226] = 83.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[227] = 84.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[228] = 85.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[229] = 86.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[230] = 87.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[231] = 88.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[232] = 89.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[233] = 90.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[234] = 91.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[235] = 92.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[236] = 93.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[237] = 94.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[238] = 95.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[239] = 96.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[240] = 97.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[241] = 98.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[242] = 99.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[243] = 100.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[244] = 101.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[245] = 102.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[246] = 103.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[247] = 104.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[248] = 105.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[249] = 106.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[250] = 107.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[251] = 108.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[252] = 109.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[253] = 110.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[254] = 111.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[255] = 112.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[256] = 113.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[257] = 114.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[258] = 115.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[259] = 116.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[260] = 117.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[261] = 118.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[262] = 119.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[263] = 120.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[264] = 121.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[265] = 122.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[266] = 123.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[267] = 124.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[268] = 125.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[269] = 126.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[270] = 127.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[271] = 128.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[272] = 129.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[273] = 130.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[274] = 131.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[275] = 132.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[276] = 133.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[277] = 134.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[278] = 135.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[279] = 136.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[280] = 137.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[281] = 138.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[282] = 139.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[283] = 140.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[284] = 141.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[285] = 142.0;
    brain_B.RunningAutonomousFollowOnePat_d.HoughTransform_o3_k[286] = 143.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[0] =
      -1.5707963267948966E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[1] =
      -1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[2] =
      -1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[3] =
      -1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[4] =
      -1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[5] =
      -1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[6] =
      -1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[7] =
      -1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[8] =
      -1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[9] =
      -1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[10] =
      -1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[11] =
      -1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[12] =
      -1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[13] =
      -1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[14] =
      -1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[15] =
      -1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[16] =
      -1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[17] =
      -1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[18] =
      -1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[19] =
      -1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[20] =
      -1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[21] =
      -1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[22] =
      -1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[23] =
      -1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[24] =
      -1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[25] =
      -1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[26] =
      -1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[27] =
      -1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[28] =
      -1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[29] =
      -1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[30] =
      -1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[31] =
      -1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[32] =
      -1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[33] =
      -9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[34] =
      -9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[35] =
      -9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[36] =
      -9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[37] =
      -9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[38] =
      -9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[39] =
      -8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[40] =
      -8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[41] =
      -8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[42] =
      -8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[43] =
      -8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[44] =
      -8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[45] =
      -7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[46] =
      -7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[47] =
      -7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[48] =
      -7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[49] =
      -7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[50] =
      -6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[51] =
      -6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[52] =
      -6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[53] =
      -6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[54] =
      -6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[55] =
      -6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[56] =
      -5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[57] =
      -5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[58] =
      -5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[59] =
      -5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[60] =
      -5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[61] =
      -5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[62] =
      -4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[63] =
      -4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[64] =
      -4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[65] =
      -4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[66] =
      -4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[67] =
      -4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[68] =
      -3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[69] =
      -3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[70] =
      -3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[71] =
      -3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[72] =
      -3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[73] =
      -2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[74] =
      -2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[75] =
      -2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[76] =
      -2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[77] =
      -2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[78] =
      -2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[79] =
      -1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[80] =
      -1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[81] =
      -1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[82] =
      -1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[83] =
      -1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[84] =
      -1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[85] =
      -8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[86] =
      -6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[87] =
      -5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[88] =
      -3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[89] =
      -1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[90] = 0.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[91] =
      1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[92] =
      3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[93] =
      5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[94] =
      6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[95] =
      8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[96] =
      1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[97] =
      1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[98] =
      1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[99] =
      1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[100] =
      1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[101] =
      1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[102] =
      2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[103] =
      2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[104] =
      2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[105] =
      2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[106] =
      2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[107] =
      2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[108] =
      3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[109] =
      3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[110] =
      3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[111] =
      3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[112] =
      3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[113] =
      4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[114] =
      4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[115] =
      4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[116] =
      4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[117] =
      4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[118] =
      4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[119] =
      5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[120] =
      5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[121] =
      5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[122] =
      5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[123] =
      5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[124] =
      5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[125] =
      6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[126] =
      6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[127] =
      6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[128] =
      6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[129] =
      6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[130] =
      6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[131] =
      7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[132] =
      7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[133] =
      7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[134] =
      7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[135] =
      7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[136] =
      8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[137] =
      8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[138] =
      8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[139] =
      8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[140] =
      8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[141] =
      8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[142] =
      9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[143] =
      9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[144] =
      9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[145] =
      9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[146] =
      9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[147] =
      9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[148] =
      1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[149] =
      1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[150] =
      1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[151] =
      1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[152] =
      1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[153] =
      1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[154] =
      1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[155] =
      1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[156] =
      1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[157] =
      1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[158] =
      1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[159] =
      1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[160] =
      1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[161] =
      1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[162] =
      1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[163] =
      1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[164] =
      1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[165] =
      1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[166] =
      1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[167] =
      1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[168] =
      1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[169] =
      1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[170] =
      1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[171] =
      1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[172] =
      1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[173] =
      1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[174] =
      1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[175] =
      1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[176] =
      1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[177] =
      1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[178] =
      1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2[179] =
      1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[0] = -143.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[1] = -142.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[2] = -141.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[3] = -140.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[4] = -139.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[5] = -138.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[6] = -137.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[7] = -136.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[8] = -135.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[9] = -134.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[10] = -133.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[11] = -132.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[12] = -131.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[13] = -130.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[14] = -129.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[15] = -128.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[16] = -127.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[17] = -126.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[18] = -125.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[19] = -124.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[20] = -123.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[21] = -122.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[22] = -121.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[23] = -120.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[24] = -119.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[25] = -118.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[26] = -117.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[27] = -116.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[28] = -115.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[29] = -114.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[30] = -113.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[31] = -112.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[32] = -111.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[33] = -110.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[34] = -109.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[35] = -108.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[36] = -107.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[37] = -106.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[38] = -105.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[39] = -104.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[40] = -103.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[41] = -102.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[42] = -101.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[43] = -100.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[44] = -99.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[45] = -98.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[46] = -97.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[47] = -96.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[48] = -95.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[49] = -94.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[50] = -93.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[51] = -92.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[52] = -91.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[53] = -90.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[54] = -89.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[55] = -88.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[56] = -87.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[57] = -86.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[58] = -85.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[59] = -84.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[60] = -83.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[61] = -82.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[62] = -81.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[63] = -80.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[64] = -79.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[65] = -78.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[66] = -77.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[67] = -76.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[68] = -75.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[69] = -74.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[70] = -73.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[71] = -72.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[72] = -71.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[73] = -70.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[74] = -69.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[75] = -68.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[76] = -67.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[77] = -66.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[78] = -65.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[79] = -64.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[80] = -63.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[81] = -62.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[82] = -61.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[83] = -60.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[84] = -59.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[85] = -58.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[86] = -57.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[87] = -56.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[88] = -55.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[89] = -54.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[90] = -53.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[91] = -52.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[92] = -51.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[93] = -50.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[94] = -49.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[95] = -48.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[96] = -47.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[97] = -46.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[98] = -45.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[99] = -44.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[100] = -43.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[101] = -42.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[102] = -41.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[103] = -40.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[104] = -39.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[105] = -38.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[106] = -37.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[107] = -36.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[108] = -35.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[109] = -34.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[110] = -33.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[111] = -32.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[112] = -31.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[113] = -30.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[114] = -29.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[115] = -28.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[116] = -27.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[117] = -26.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[118] = -25.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[119] = -24.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[120] = -23.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[121] = -22.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[122] = -21.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[123] = -20.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[124] = -19.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[125] = -18.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[126] = -17.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[127] = -16.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[128] = -15.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[129] = -14.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[130] = -13.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[131] = -12.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[132] = -11.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[133] = -10.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[134] = -9.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[135] = -8.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[136] = -7.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[137] = -6.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[138] = -5.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[139] = -4.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[140] = -3.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[141] = -2.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[142] = -1.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[143] = 0.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[144] = 1.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[145] = 2.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[146] = 3.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[147] = 4.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[148] = 5.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[149] = 6.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[150] = 7.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[151] = 8.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[152] = 9.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[153] = 10.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[154] = 11.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[155] = 12.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[156] = 13.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[157] = 14.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[158] = 15.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[159] = 16.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[160] = 17.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[161] = 18.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[162] = 19.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[163] = 20.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[164] = 21.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[165] = 22.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[166] = 23.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[167] = 24.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[168] = 25.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[169] = 26.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[170] = 27.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[171] = 28.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[172] = 29.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[173] = 30.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[174] = 31.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[175] = 32.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[176] = 33.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[177] = 34.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[178] = 35.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[179] = 36.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[180] = 37.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[181] = 38.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[182] = 39.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[183] = 40.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[184] = 41.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[185] = 42.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[186] = 43.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[187] = 44.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[188] = 45.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[189] = 46.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[190] = 47.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[191] = 48.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[192] = 49.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[193] = 50.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[194] = 51.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[195] = 52.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[196] = 53.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[197] = 54.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[198] = 55.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[199] = 56.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[200] = 57.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[201] = 58.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[202] = 59.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[203] = 60.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[204] = 61.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[205] = 62.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[206] = 63.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[207] = 64.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[208] = 65.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[209] = 66.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[210] = 67.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[211] = 68.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[212] = 69.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[213] = 70.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[214] = 71.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[215] = 72.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[216] = 73.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[217] = 74.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[218] = 75.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[219] = 76.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[220] = 77.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[221] = 78.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[222] = 79.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[223] = 80.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[224] = 81.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[225] = 82.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[226] = 83.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[227] = 84.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[228] = 85.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[229] = 86.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[230] = 87.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[231] = 88.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[232] = 89.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[233] = 90.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[234] = 91.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[235] = 92.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[236] = 93.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[237] = 94.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[238] = 95.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[239] = 96.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[240] = 97.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[241] = 98.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[242] = 99.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[243] = 100.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[244] = 101.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[245] = 102.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[246] = 103.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[247] = 104.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[248] = 105.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[249] = 106.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[250] = 107.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[251] = 108.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[252] = 109.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[253] = 110.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[254] = 111.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[255] = 112.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[256] = 113.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[257] = 114.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[258] = 115.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[259] = 116.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[260] = 117.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[261] = 118.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[262] = 119.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[263] = 120.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[264] = 121.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[265] = 122.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[266] = 123.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[267] = 124.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[268] = 125.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[269] = 126.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[270] = 127.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[271] = 128.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[272] = 129.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[273] = 130.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[274] = 131.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[275] = 132.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[276] = 133.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[277] = 134.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[278] = 135.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[279] = 136.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[280] = 137.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[281] = 138.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[282] = 139.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[283] = 140.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[284] = 141.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[285] = 142.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3[286] = 143.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[0] =
      -1.5707963267948966E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[1] =
      -1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[2] =
      -1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[3] =
      -1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[4] =
      -1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[5] =
      -1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[6] =
      -1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[7] =
      -1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[8] =
      -1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[9] =
      -1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[10] =
      -1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[11] =
      -1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[12] =
      -1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[13] =
      -1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[14] =
      -1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[15] =
      -1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[16] =
      -1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[17] =
      -1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[18] =
      -1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[19] =
      -1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[20] =
      -1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[21] =
      -1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[22] =
      -1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[23] =
      -1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[24] =
      -1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[25] =
      -1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[26] =
      -1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[27] =
      -1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[28] =
      -1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[29] =
      -1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[30] =
      -1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[31] =
      -1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[32] =
      -1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[33] =
      -9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[34] =
      -9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[35] =
      -9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[36] =
      -9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[37] =
      -9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[38] =
      -9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[39] =
      -8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[40] =
      -8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[41] =
      -8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[42] =
      -8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[43] =
      -8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[44] =
      -8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[45] =
      -7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[46] =
      -7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[47] =
      -7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[48] =
      -7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[49] =
      -7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[50] =
      -6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[51] =
      -6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[52] =
      -6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[53] =
      -6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[54] =
      -6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[55] =
      -6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[56] =
      -5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[57] =
      -5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[58] =
      -5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[59] =
      -5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[60] =
      -5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[61] =
      -5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[62] =
      -4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[63] =
      -4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[64] =
      -4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[65] =
      -4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[66] =
      -4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[67] =
      -4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[68] =
      -3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[69] =
      -3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[70] =
      -3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[71] =
      -3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[72] =
      -3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[73] =
      -2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[74] =
      -2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[75] =
      -2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[76] =
      -2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[77] =
      -2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[78] =
      -2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[79] =
      -1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[80] =
      -1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[81] =
      -1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[82] =
      -1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[83] =
      -1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[84] =
      -1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[85] =
      -8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[86] =
      -6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[87] =
      -5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[88] =
      -3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[89] =
      -1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[90] = 0.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[91] =
      1.7453292519943295E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[92] =
      3.4906585039886591E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[93] =
      5.2359877559829890E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[94] =
      6.9813170079773182E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[95] =
      8.7266462599716474E-02;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[96] =
      1.0471975511965978E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[97] =
      1.2217304763960307E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[98] =
      1.3962634015954636E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[99] =
      1.5707963267948966E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[100] =
      1.7453292519943295E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[101] =
      1.9198621771937624E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[102] =
      2.0943951023931956E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[103] =
      2.2689280275926285E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[104] =
      2.4434609527920614E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[105] =
      2.6179938779914941E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[106] =
      2.7925268031909273E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[107] =
      2.9670597283903605E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[108] =
      3.1415926535897931E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[109] =
      3.3161255787892263E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[110] =
      3.4906585039886590E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[111] =
      3.6651914291880922E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[112] =
      3.8397243543875248E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[113] =
      4.0142572795869580E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[114] =
      4.1887902047863912E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[115] =
      4.3633231299858238E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[116] =
      4.5378560551852570E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[117] =
      4.7123889803846897E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[118] =
      4.8869219055841229E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[119] =
      5.0614548307835561E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[120] =
      5.2359877559829882E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[121] =
      5.4105206811824214E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[122] =
      5.5850536063818546E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[123] =
      5.7595865315812877E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[124] =
      5.9341194567807209E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[125] =
      6.1086523819801530E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[126] =
      6.2831853071795862E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[127] =
      6.4577182323790194E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[128] =
      6.6322511575784526E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[129] =
      6.8067840827778847E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[130] =
      6.9813170079773179E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[131] =
      7.1558499331767511E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[132] =
      7.3303828583761843E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[133] =
      7.5049157835756175E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[134] =
      7.6794487087750496E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[135] =
      7.8539816339744828E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[136] =
      8.0285145591739160E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[137] =
      8.2030474843733492E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[138] =
      8.3775804095727824E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[139] =
      8.5521133347722145E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[140] =
      8.7266462599716477E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[141] =
      8.9011791851710809E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[142] =
      9.0757121103705141E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[143] =
      9.2502450355699462E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[144] =
      9.4247779607693793E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[145] =
      9.5993108859688125E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[146] =
      9.7738438111682457E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[147] =
      9.9483767363676789E-01;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[148] =
      1.0122909661567112E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[149] =
      1.0297442586766545E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[150] =
      1.0471975511965976E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[151] =
      1.0646508437165410E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[152] =
      1.0821041362364843E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[153] =
      1.0995574287564276E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[154] =
      1.1170107212763709E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[155] =
      1.1344640137963142E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[156] =
      1.1519173063162575E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[157] =
      1.1693705988362009E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[158] =
      1.1868238913561442E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[159] =
      1.2042771838760873E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[160] =
      1.2217304763960306E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[161] =
      1.2391837689159739E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[162] =
      1.2566370614359172E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[163] =
      1.2740903539558606E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[164] =
      1.2915436464758039E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[165] =
      1.3089969389957472E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[166] =
      1.3264502315156905E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[167] =
      1.3439035240356338E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[168] =
      1.3613568165555769E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[169] =
      1.3788101090755203E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[170] =
      1.3962634015954636E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[171] =
      1.4137166941154069E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[172] =
      1.4311699866353502E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[173] =
      1.4486232791552935E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[174] =
      1.4660765716752369E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[175] =
      1.4835298641951802E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[176] =
      1.5009831567151235E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[177] =
      1.5184364492350666E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[178] =
      1.5358897417550099E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o2_m[179] =
      1.5533430342749532E+00;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[0] = -143.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[1] = -142.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[2] = -141.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[3] = -140.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[4] = -139.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[5] = -138.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[6] = -137.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[7] = -136.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[8] = -135.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[9] = -134.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[10] = -133.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[11] = -132.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[12] = -131.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[13] = -130.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[14] = -129.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[15] = -128.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[16] = -127.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[17] = -126.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[18] = -125.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[19] = -124.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[20] = -123.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[21] = -122.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[22] = -121.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[23] = -120.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[24] = -119.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[25] = -118.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[26] = -117.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[27] = -116.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[28] = -115.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[29] = -114.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[30] = -113.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[31] = -112.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[32] = -111.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[33] = -110.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[34] = -109.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[35] = -108.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[36] = -107.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[37] = -106.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[38] = -105.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[39] = -104.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[40] = -103.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[41] = -102.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[42] = -101.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[43] = -100.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[44] = -99.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[45] = -98.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[46] = -97.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[47] = -96.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[48] = -95.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[49] = -94.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[50] = -93.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[51] = -92.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[52] = -91.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[53] = -90.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[54] = -89.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[55] = -88.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[56] = -87.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[57] = -86.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[58] = -85.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[59] = -84.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[60] = -83.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[61] = -82.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[62] = -81.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[63] = -80.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[64] = -79.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[65] = -78.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[66] = -77.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[67] = -76.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[68] = -75.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[69] = -74.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[70] = -73.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[71] = -72.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[72] = -71.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[73] = -70.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[74] = -69.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[75] = -68.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[76] = -67.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[77] = -66.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[78] = -65.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[79] = -64.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[80] = -63.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[81] = -62.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[82] = -61.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[83] = -60.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[84] = -59.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[85] = -58.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[86] = -57.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[87] = -56.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[88] = -55.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[89] = -54.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[90] = -53.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[91] = -52.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[92] = -51.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[93] = -50.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[94] = -49.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[95] = -48.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[96] = -47.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[97] = -46.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[98] = -45.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[99] = -44.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[100] = -43.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[101] = -42.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[102] = -41.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[103] = -40.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[104] = -39.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[105] = -38.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[106] = -37.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[107] = -36.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[108] = -35.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[109] = -34.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[110] = -33.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[111] = -32.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[112] = -31.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[113] = -30.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[114] = -29.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[115] = -28.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[116] = -27.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[117] = -26.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[118] = -25.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[119] = -24.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[120] = -23.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[121] = -22.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[122] = -21.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[123] = -20.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[124] = -19.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[125] = -18.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[126] = -17.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[127] = -16.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[128] = -15.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[129] = -14.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[130] = -13.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[131] = -12.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[132] = -11.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[133] = -10.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[134] = -9.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[135] = -8.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[136] = -7.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[137] = -6.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[138] = -5.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[139] = -4.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[140] = -3.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[141] = -2.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[142] = -1.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[143] = 0.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[144] = 1.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[145] = 2.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[146] = 3.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[147] = 4.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[148] = 5.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[149] = 6.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[150] = 7.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[151] = 8.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[152] = 9.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[153] = 10.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[154] = 11.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[155] = 12.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[156] = 13.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[157] = 14.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[158] = 15.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[159] = 16.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[160] = 17.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[161] = 18.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[162] = 19.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[163] = 20.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[164] = 21.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[165] = 22.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[166] = 23.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[167] = 24.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[168] = 25.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[169] = 26.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[170] = 27.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[171] = 28.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[172] = 29.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[173] = 30.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[174] = 31.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[175] = 32.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[176] = 33.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[177] = 34.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[178] = 35.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[179] = 36.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[180] = 37.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[181] = 38.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[182] = 39.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[183] = 40.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[184] = 41.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[185] = 42.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[186] = 43.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[187] = 44.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[188] = 45.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[189] = 46.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[190] = 47.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[191] = 48.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[192] = 49.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[193] = 50.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[194] = 51.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[195] = 52.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[196] = 53.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[197] = 54.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[198] = 55.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[199] = 56.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[200] = 57.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[201] = 58.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[202] = 59.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[203] = 60.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[204] = 61.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[205] = 62.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[206] = 63.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[207] = 64.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[208] = 65.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[209] = 66.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[210] = 67.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[211] = 68.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[212] = 69.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[213] = 70.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[214] = 71.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[215] = 72.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[216] = 73.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[217] = 74.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[218] = 75.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[219] = 76.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[220] = 77.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[221] = 78.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[222] = 79.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[223] = 80.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[224] = 81.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[225] = 82.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[226] = 83.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[227] = 84.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[228] = 85.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[229] = 86.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[230] = 87.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[231] = 88.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[232] = 89.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[233] = 90.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[234] = 91.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[235] = 92.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[236] = 93.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[237] = 94.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[238] = 95.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[239] = 96.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[240] = 97.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[241] = 98.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[242] = 99.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[243] = 100.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[244] = 101.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[245] = 102.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[246] = 103.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[247] = 104.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[248] = 105.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[249] = 106.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[250] = 107.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[251] = 108.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[252] = 109.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[253] = 110.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[254] = 111.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[255] = 112.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[256] = 113.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[257] = 114.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[258] = 115.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[259] = 116.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[260] = 117.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[261] = 118.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[262] = 119.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[263] = 120.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[264] = 121.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[265] = 122.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[266] = 123.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[267] = 124.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[268] = 125.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[269] = 126.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[270] = 127.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[271] = 128.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[272] = 129.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[273] = 130.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[274] = 131.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[275] = 132.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[276] = 133.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[277] = 134.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[278] = 135.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[279] = 136.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[280] = 137.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[281] = 138.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[282] = 139.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[283] = 140.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[284] = 141.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[285] = 142.0;
    brain_B.RunningAutonomousFollowOnePa_ot.HoughTransform_o3_k[286] = 143.0;
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

  /* Enable for Stateflow: '<Root>/Chart' */
  brain_Chart_Enable();
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
