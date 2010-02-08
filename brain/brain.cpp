/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.168
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Mon Feb  8 16:28:35 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Mon Feb  8 16:28:35 2010
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
#define brain_IN_FindBuoy              (3)
#define brain_IN_Finish                (4)
#define brain_IN_FollowTrack           (5)
#define brain_IN_NotRunning            (1)
#define brain_IN_Running               (2)
#define brain_IN_Stage1Aim             (1)
#define brain_IN_Stage2Position        (2)
#define brain_IN_Stage3ReOrient        (3)
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
static void brain_ifbuoynotvisible(real_T sf_CentroidX1, real_T sf_CentroidY1,
  real_T sf_ChangetoRight2, real_T sf_ChangetoLeft2, real_T sf_ChangetoVertical2,
  real_T *sf_ChangetoRight1, real_T *sf_ChangetoLeft1, real_T
  *sf_ChangetoVertical1);
static void brain_Start(void);
static void brain_ValidationGate(void);
static void brain_exit_internal_Running(void);

/* Output and update for action system:
 *   '<S62>/FoundTrack'
 *   '<S23>/FoundBuoy'
 */
void brain_FoundTrack(real_T *rtd_Image_c)
{
  /* DataStoreWrite: '<S63>/Data Store Write' incorporates:
   *  Constant: '<S63>/Constant'
   */
  (*rtd_Image_c) = 1.0;
}

/* Output and update for action system:
 *   '<S62>/NoTrack'
 *   '<S23>/NoBuoy'
 */
void brain_NoTrack(real_T *rtd_Image_c)
{
  /* DataStoreWrite: '<S66>/Data Store Write' incorporates:
   *  Constant: '<S66>/Constant'
   */
  (*rtd_Image_c) = 0.0;
}

/* Disable for action system:
 *   '<S10>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S8>/BigError S1'
 */
void brain_BigErrorS1_Disable(rtB_BigErrorS1_brain *localB)
{
  /* Disable for Outport: '<S68>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S10>/BigError S1'
 *   '<S5>/BigError S1'
 *   '<S8>/BigError S1'
 */
void brain_BigErrorS1(real_T rtu_In1, rtB_BigErrorS1_brain *localB)
{
  /* Sum: '<S68>/Add' incorporates:
   *  Constant: '<S68>/Constant'
   */
  localB->Add = rtu_In1 - 360.0;

  /* Constant: '<S68>/Constant1' */
  localB->Constant1 = 1.0;
}

/* Disable for action system:
 *   '<S10>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S8>/BigNegativeError S2'
 */
void brai_BigNegativeErrorS2_Disable(rtB_BigNegativeErrorS2_brain *localB)
{
  /* Disable for Outport: '<S69>/Out2' */
  localB->Constant1 = 0.0;
}

/* Output and update for action system:
 *   '<S10>/BigNegativeError S2'
 *   '<S5>/BigNegativeError S2'
 *   '<S8>/BigNegativeError S2'
 */
void brain_BigNegativeErrorS2(real_T rtu_In1, rtB_BigNegativeErrorS2_brain
  *localB)
{
  /* Sum: '<S69>/Add' incorporates:
   *  Constant: '<S69>/Constant'
   */
  localB->Add = rtu_In1 + 360.0;

  /* Constant: '<S69>/Constant1' */
  localB->Constant1 = 2.0;
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_ifbuoynotvisible(real_T sf_CentroidX1, real_T sf_CentroidY1,
  real_T sf_ChangetoRight2, real_T sf_ChangetoLeft2, real_T sf_ChangetoVertical2,
  real_T *sf_ChangetoRight1, real_T *sf_ChangetoLeft1, real_T
  *sf_ChangetoVertical1)
{
  /* Embedded MATLAB Function 'ifbuoynotvisible': '<S1>:186' */
  if ((sf_CentroidX1 == -1.0) || (sf_CentroidY1 == -1.0)) {
    /* '<S1>:186:4' */
    /* '<S1>:186:5' */
    *sf_ChangetoRight1 = 10.0;

    /* '<S1>:186:6' */
    *sf_ChangetoLeft1 = 10.0;

    /* '<S1>:186:7' */
    *sf_ChangetoVertical1 = -100.0;
  } else {
    /* '<S1>:186:9' */
    *sf_ChangetoRight1 = sf_ChangetoRight2;

    /* '<S1>:186:10' */
    *sf_ChangetoLeft1 = sf_ChangetoLeft2;

    /* '<S1>:186:11' */
    *sf_ChangetoVertical1 = sf_ChangetoVertical2;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_Start(void)
{
  /* During 'Start': '<S1>:153' */
  if ((brain_DWork.DesiredHeadingCount >= 3.0) && (brain_U.DesiredState == 0)) {
    /* Transition: '<S1>:162' */
    /* Exit 'Start': '<S1>:153' */
    brain_B.DesiredHeading = brain_U.CurrentHeading;

    /* Entry 'ValidationGate': '<S1>:1' */
    brain_DWork.is_Running = (uint8_T)brain_IN_ValidationGate;
    brain_DWork.RunningValidationGateStraight_g = brain_M->Timing.clockTick0;

    /* InitializeConditions for UnitDelay: '<S72>/UD' */
    brain_DWork.UD_DSTATE_nh = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S70>/Depth Discrete-Time Integrator' */
    brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

    /* InitializeConditions for UnitDelay: '<S73>/UD' */
    brain_DWork.UD_DSTATE_b = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S71>/Heading Discrete-Time Integrator' */
    brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
    brain_DWork.OldObstacle = 0.0;
    brain_DWork.count = 0.0;
    brain_DWork.TrackCount = 0.0;
    brain_B.State = 2U;
  } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState != 0)) {
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
      brain_DWork.DesiredHeadingCount = brain_DWork.DesiredHeadingCount + 1.0;
    } else {
      /* '<S1>:154:8' */
      brain_DWork.DesiredHeadingCount = 0.0;
    }

    /* '<S1>:154:10' */
    brain_DWork.OldHeading = brain_U.CurrentHeading;
    brain_B.DesiredDepth = 5.0;
  }
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_ValidationGate(void)
{
  /* local block i/o variables */
  real_T rtb_DepthProportionalGain_k;
  real_T rtb_TSamp_no;
  real_T rtb_Add1_m;
  real_T rtb_HeadingProportionalGain_j;
  real_T rtb_TSamp_c;
  real_T rtb_MultiportSwitch_o;
  real_T rtb_Add4_g;
  real32_T rtb_BlobAnalysis;
  real_T sf_Obstacle;
  int8_T rtPrevAction;
  int8_T rtAction;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BlobAnalysis_NUM_PIX_DW_o;
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

  /* During 'ValidationGate': '<S1>:1' */
  if ((brain_DWork.TrackCount > 2.0) && (brain_U.DesiredState == 0)) {
    /* Transition: '<S1>:199' */
    /* Exit 'ValidationGate': '<S1>:1' */

    /* Disable for If: '<S10>/If' */
    brain_DWork.If_ActiveSubsystem_o = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */

    /* Entry 'FollowTrack': '<S1>:198' */
    brain_DWork.is_Running = (uint8_T)brain_IN_FollowTrack;
    brain_DWork.ErrorCountHeading = 0.0;

    /* Transition: '<S1>:219' */
    /* Entry 'Stage1Aim': '<S1>:213' */
    brain_DWork.is_FollowTrack = (uint8_T)brain_IN_Stage1Aim;
    brain_DWork.ErrorCountX = 0.0;
    brain_B.State = 3U;
  } else if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
    /* Transition: '<S1>:302' */
    /* Exit 'ValidationGate': '<S1>:1' */

    /* Disable for If: '<S10>/If' */
    brain_DWork.If_ActiveSubsystem_o = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */

    /* Entry 'ChooseState': '<S1>:299' */
    brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
  } else {
    /* Simulink Function 'LookforTrack': '<S1>:4' */

    /* DataStoreRead: '<S9>/Data Store Read' */
    brain_B.DataStoreRead_l = brain_DWork.Image_c;
    for (i = 0; i < 307200; i++) {
      brain_B.SFunction_o11[i] = (real_T)brain_B.ColorSpaceConversion1_o1[i];
      brain_B.SFunction_o12[i] = (real_T)brain_B.ColorSpaceConversion1_o2[i];

      /* RelationalOperator: '<S65>/Compare' incorporates:
       *  Constant: '<S65>/Constant'
       */
      brain_B.track1Bitmap[i] = (brain_B.SFunction_o11[i] <
        brain_P.Track_HueLower);

      /* RelationalOperator: '<S64>/Compare' incorporates:
       *  Constant: '<S64>/Constant'
       */
      brain_B.Compare_c[i] = (brain_B.SFunction_o11[i] > brain_P.Track_HueHigher);

      /* Logic: '<S62>/Logical Operator' */
      brain_B.track1Bitmap[i] = (brain_B.track1Bitmap[i] || brain_B.Compare_c[i]);

      /* RelationalOperator: '<S67>/Compare' incorporates:
       *  Constant: '<S67>/Constant'
       */
      brain_B.Compare_c[i] = (brain_B.SFunction_o12[i] >
        brain_P.Track_Saturation);

      /* Logic: '<S62>/Logical Operator1' */
      brain_B.track1Bitmap[i] = (brain_B.track1Bitmap[i] && brain_B.Compare_c[i]);
    }

    /* S-Function (svipblob): '<S62>/Blob Analysis' */
    maxNumBlobsReached = false;
    for (i = 0; i < 483; i++) {
      brain_DWork.BlobAnalysis_PAD_DW[i] = 0U;
    }

    currentLabel = 1U;
    i = 0;
    idx = 483;
    for (n = 0; n < 640; n++) {
      for (n_0 = 0; n_0 < 480; n_0++) {
        brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.track1Bitmap[i]
          ? 255 : 0);
        i++;
        idx++;
      }

      brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
      idx++;
      brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
      idx++;
    }

    for (i = 0; i < 481; i++) {
      brain_DWork.BlobAnalysis_PAD_DW[i + idx] = 0U;
    }

    n = 1;
    stackIdx = 0U;
    pixIdx = 0U;
    for (n_0 = 0; n_0 < 640; n_0++) {
      ms = 1;
      j = n * 482;
      for (idx = 0; idx < 480; idx++) {
        numBlobs = (uint32_T)(j + ms);
        start_pixIdx = pixIdx;
        if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
          brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
          pixIdx++;
          BlobAnalysis_NUM_PIX_DW_o = 1U;
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
                  ((int16_T)(k / 482U) - 1);
                brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                  482U - 1U);
                pixIdx++;
                BlobAnalysis_NUM_PIX_DW_o = BlobAnalysis_NUM_PIX_DW_o + 1U;
                brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = k;
                stackIdx++;
              }
            }
          }

          if ((BlobAnalysis_NUM_PIX_DW_o < brain_P.Min_Blob_Size) ||
              (BlobAnalysis_NUM_PIX_DW_o > brain_P.Max_Blob_Size)) {
            currentLabel--;
            pixIdx = start_pixIdx;
          }

          if (currentLabel == 1) {
            maxNumBlobsReached = true;
            n_0 = 640;
            idx = 480;
          }

          if (idx < 480) {
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
      for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW_o; j++) {
        idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
        ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i];
      }

      centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW_o;
      centroid_idx_0 = (real32_T)idx / (real32_T)BlobAnalysis_NUM_PIX_DW_o;
      rtb_BlobAnalysis = 0.0F;
      ys = 0.0F;
      xys = 0.0F;
      for (k = 0U; k < (uint32_T)(int32_T)BlobAnalysis_NUM_PIX_DW_o; k++) {
        majorAxis = (real32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + k] -
          centroid_idx_0;
        uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i + k] -
          centroid_idx;
        rtb_BlobAnalysis += majorAxis * majorAxis;
        ys += uyy * uyy;
        xys += majorAxis * (-uyy);
      }

      centroid_idx = rtb_BlobAnalysis / (real32_T)BlobAnalysis_NUM_PIX_DW_o +
        8.333333582E-02F;
      uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW_o + 8.333333582E-02F;
      rtb_BlobAnalysis = xys / (real32_T)BlobAnalysis_NUM_PIX_DW_o;
      rtb_BlobAnalysis = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx -
        uyy) + rtb_BlobAnalysis * rtb_BlobAnalysis * 4.0F);
      majorAxis = ((centroid_idx + uyy) + rtb_BlobAnalysis) * 8.0F;
      rtb_BlobAnalysis = (real32_T)sqrt(majorAxis - ((centroid_idx + uyy) -
        rtb_BlobAnalysis) * 8.0F) / (real32_T)sqrt(majorAxis);
      i += (int32_T)BlobAnalysis_NUM_PIX_DW_o;
      n += (int32_T)BlobAnalysis_NUM_PIX_DW_o;
    }

    for (i = (int32_T)numBlobs; i < 1; i = 1) {
      rtb_BlobAnalysis = -1.0F;
    }

    /* If: '<S62>/If' incorporates:
     *  ActionPort: '<S63>/Action Port'
     *  ActionPort: '<S66>/Action Port'
     *  SubSystem: '<S62>/FoundTrack'
     *  SubSystem: '<S62>/NoTrack'
     */
    if (rtb_BlobAnalysis > 8.999999762E-01F) {
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
      brain_DWork.RunningValidationGateStraightLe = brain_M->Timing.clockTick0 -
        brain_DWork.RunningValidationGateStraight_g;
    }

    brain_DWork.RunningValidationGateStraight_g = brain_M->Timing.clockTick0;

    /* Sum: '<S10>/Add' */
    rtb_Add4_g = (real_T)brain_B.SFunction_o14 - (real_T)brain_B.SFunction_o13;

    /* Gain: '<S70>/Depth Proportional Gain' */
    rtb_DepthProportionalGain_k = brain_P.Depth_Kp * rtb_Add4_g;

    /* Gain: '<S70>/Depth Derivative Gain' */
    rtb_MultiportSwitch_o = brain_P.Depth_Kd * rtb_Add4_g;

    /* S-Function (sfix_tsampmath): '<S72>/TSamp' */

    /* Sample Time Math Block: '<S72>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_no = rtb_MultiportSwitch_o /
      (((brain_DWork.RunningValidationGateStraightLe * 0.02))*(1.0));

    /* DiscreteIntegrator: '<S70>/Depth Discrete-Time Integrator' */
    rtb_MultiportSwitch_o = brain_DWork.DepthDiscreteTimeIntegrator_D_e;

    /* Sum: '<S70>/Sum' incorporates:
     *  Sum: '<S72>/Diff'
     *  UnitDelay: '<S72>/UD'
     */
    rtb_MultiportSwitch_o += (rtb_TSamp_no - brain_DWork.UD_DSTATE_nh) +
      rtb_DepthProportionalGain_k;

    /* DataTypeConversion: '<S10>/Double To Int8' */
    rtb_HeadingProportionalGain_j = floor(rtb_MultiportSwitch_o);
    if (rtb_HeadingProportionalGain_j < 128.0) {
      if (rtb_HeadingProportionalGain_j >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_j;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    brain_B.DoubleToInt8_c = rtPrevAction;

    /* Gain: '<S70>/Depth Integral Gain' */
    rtb_DepthProportionalGain_k = brain_P.Depth_Ki * rtb_Add4_g;

    /* Sum: '<S10>/Add1' */
    rtb_Add1_m = brain_B.SFunction_o15 - brain_B.SFunction_o16;

    /* If: '<S10>/If' incorporates:
     *  ActionPort: '<S68>/Action Port'
     *  ActionPort: '<S69>/Action Port'
     *  SubSystem: '<S10>/BigError S1'
     *  SubSystem: '<S10>/BigNegativeError S2'
     */
    rtPrevAction = brain_DWork.If_ActiveSubsystem_o;
    rtAction = -1;
    if (rtb_Add1_m > 180.0) {
      rtAction = 0;
    } else {
      if (rtb_Add1_m < -180.0) {
        rtAction = 1;
      }
    }

    brain_DWork.If_ActiveSubsystem_o = rtAction;
    if (rtPrevAction != rtAction) {
      switch (rtPrevAction) {
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

    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Sum: '<S10>/Add2'
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

    /* Gain: '<S71>/Heading Proportional Gain' */
    rtb_HeadingProportionalGain_j = brain_P.Heading_Kp * rtb_MultiportSwitch_o;

    /* Gain: '<S71>/Heading Derivative Gain' */
    rtb_Add4_g = brain_P.Heading_Kd * rtb_MultiportSwitch_o;

    /* S-Function (sfix_tsampmath): '<S73>/TSamp' */

    /* Sample Time Math Block: '<S73>/TSamp'
     *
     * y = u * K     where     K = 1 / ( w * Ts )
     *
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * ElapsedTime Data Type:  Floating Point real_T
     */
    rtb_TSamp_c = rtb_Add4_g / (((brain_DWork.RunningValidationGateStraightLe *
      0.02))*(1.0));

    /* DiscreteIntegrator: '<S71>/Heading Discrete-Time Integrator' */
    rtb_Add4_g = brain_DWork.HeadingDiscreteTimeIntegrato_dv;

    /* Sum: '<S71>/Sum' incorporates:
     *  Sum: '<S73>/Diff'
     *  UnitDelay: '<S73>/UD'
     */
    rtb_Add4_g += (rtb_TSamp_c - brain_DWork.UD_DSTATE_b) +
      rtb_HeadingProportionalGain_j;

    /* Product: '<S10>/Multiply' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_HeadingProportionalGain_j = -rtb_Add4_g;
    if (rtIsNaN(rtb_HeadingProportionalGain_j) || rtIsInf
        (rtb_HeadingProportionalGain_j)) {
      rtb_HeadingProportionalGain_j = 0.0;
    } else {
      rtb_HeadingProportionalGain_j = fmod(floor(rtb_HeadingProportionalGain_j),
        256.0);
    }

    /* Sum: '<S10>/Add4' incorporates:
     *  Constant: '<S10>/Heading_Forward_Velocity'
     */
    rtb_Add4_g += brain_P.Heading_Forward_Velocity;

    /* DataTypeConversion: '<S10>/DoubleToint1' incorporates:
     *  Constant: '<S10>/Heading_Forward_Velocity1'
     *  Sum: '<S10>/Add3'
     */
    rtb_HeadingProportionalGain_j = floor((real_T)(rtb_HeadingProportionalGain_j
      < 0.0 ? (int8_T)(-((int8_T)(uint8_T)(-rtb_HeadingProportionalGain_j))) :
      (int8_T)(uint8_T)rtb_HeadingProportionalGain_j) +
      brain_P.Heading_Forward_Velocity);
    if (rtb_HeadingProportionalGain_j < 128.0) {
      if (rtb_HeadingProportionalGain_j >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_j;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    brain_B.DoubleToint1_c = rtPrevAction;

    /* DataTypeConversion: '<S10>/DoubleToint8' */
    rtb_HeadingProportionalGain_j = floor(rtb_Add4_g);
    if (rtb_HeadingProportionalGain_j < 128.0) {
      if (rtb_HeadingProportionalGain_j >= -128.0) {
        rtPrevAction = (int8_T)rtb_HeadingProportionalGain_j;
      } else {
        rtPrevAction = MIN_int8_T;
      }
    } else {
      rtPrevAction = MAX_int8_T;
    }

    brain_B.DoubleToint8_b = rtPrevAction;

    /* Update for UnitDelay: '<S72>/UD' */
    brain_DWork.UD_DSTATE_nh = rtb_TSamp_no;

    /* Update for DiscreteIntegrator: '<S70>/Depth Discrete-Time Integrator' */
    brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.02 * (real_T)
      brain_DWork.RunningValidationGateStraightLe * rtb_DepthProportionalGain_k
      + brain_DWork.DepthDiscreteTimeIntegrator_D_e;
    if (brain_DWork.DepthDiscreteTimeIntegrator_D_e >= 10.0) {
      brain_DWork.DepthDiscreteTimeIntegrator_D_e = 10.0;
    } else {
      if (brain_DWork.DepthDiscreteTimeIntegrator_D_e <= -10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_D_e = -10.0;
      }
    }

    /* Update for UnitDelay: '<S73>/UD' */
    brain_DWork.UD_DSTATE_b = rtb_TSamp_c;

    /* Update for DiscreteIntegrator: '<S71>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S71>/Heading Integral Gain'
     */
    brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.02 * (real_T)
      brain_DWork.RunningValidationGateStraightLe * (brain_P.Heading_Ki *
      rtb_MultiportSwitch_o) + brain_DWork.HeadingDiscreteTimeIntegrato_dv;
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
}

/* Function for Stateflow: '<Root>/Chart' */
static void brain_exit_internal_Running(void)
{
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

   case brain_IN_FollowTrack:
    switch (brain_DWork.is_FollowTrack) {
     case brain_IN_Stage1Aim:
      /* Exit 'Stage1Aim': '<S1>:213' */
      brain_DWork.is_FollowTrack = (uint8_T)0;
      break;

     case brain_IN_Stage2Position:
      /* Exit 'Stage2Position': '<S1>:214' */
      brain_DWork.is_FollowTrack = (uint8_T)0;
      break;

     case brain_IN_Stage3ReOrient:
      /* Exit 'Stage3ReOrient': '<S1>:259' */

      /* Disable for If: '<S8>/If' */
      brain_DWork.If_ActiveSubsystem = -1;
      brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);
      brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

      /* Disable for ifaction SubSystem: '<S8>/BigError S1' */
      brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);

      /* end of Disable for SubSystem: '<S8>/BigError S1' */

      /* Disable for ifaction SubSystem: '<S8>/BigNegativeError S2' */
      brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

      /* end of Disable for SubSystem: '<S8>/BigNegativeError S2' */
      brain_DWork.is_FollowTrack = (uint8_T)0;
      break;

     default:
      brain_DWork.is_FollowTrack = (uint8_T)0;
      break;
    }

    /* Exit 'FollowTrack': '<S1>:198' */
    brain_DWork.is_Running = (uint8_T)0;
    break;

   case brain_IN_Start:
    /* Exit 'Start': '<S1>:153' */
    brain_B.DesiredHeading = brain_U.CurrentHeading;
    brain_DWork.is_Running = (uint8_T)0;
    break;

   case brain_IN_ValidationGate:
    /* Exit 'ValidationGate': '<S1>:1' */

    /* Disable for If: '<S10>/If' */
    brain_DWork.If_ActiveSubsystem_o = -1;
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* Disable for ifaction SubSystem: '<S10>/BigError S1' */
    brain_BigErrorS1_Disable(&brain_B.BigErrorS1);

    /* end of Disable for SubSystem: '<S10>/BigError S1' */

    /* Disable for ifaction SubSystem: '<S10>/BigNegativeError S2' */
    brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2);

    /* end of Disable for SubSystem: '<S10>/BigNegativeError S2' */
    brain_DWork.is_Running = (uint8_T)0;
    break;

   default:
    /* Exit 'ChooseState': '<S1>:299' */
    /* Exit 'Finish': '<S1>:151' */
    break;
  }
}

/* Initial conditions for atomic system: '<Root>/Chart' */
void brain_Chart_Init(void)
{
  /* InitializeConditions for Stateflow: '<Root>/Chart' incorporates:
   *  InitializeConditions for SubSystem: '<S1>/Running.Buoy.Buoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
   *  InitializeConditions for SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowTrack.Stage1Aim.TrackStage1'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowTrack.Stage2Position.TrackStage2'
   *  InitializeConditions for SubSystem: '<S1>/Running.FollowTrack.Stage3ReOrient.DirectionalControl'
   *  InitializeConditions for SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
   *  InitializeConditions for SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
   */
  brain_DWork.is_Running = 0U;
  brain_DWork.is_FollowTrack = 0U;
  brain_DWork.is_active_c1_brain = 0U;
  brain_DWork.is_c1_brain = 0U;
  brain_DWork.count = 0.0;
  brain_DWork.OldObstacle = 0.0;
  brain_DWork.countarea = 0.0;
  brain_DWork.DesiredHeadingCount = 0.0;
  brain_DWork.OldHeading = 0.0;
  brain_DWork.TrackCount = 0.0;
  brain_DWork.BuoyCount = 0.0;
  brain_DWork.ErrorCountHeading = 0.0;
  brain_DWork.ErrorCountX = 0.0;
  brain_DWork.ErrorCountY = 0.0;
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

  /* InitializeConditions for UnitDelay: '<S72>/UD' */
  brain_DWork.UD_DSTATE_nh = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

  /* InitializeConditions for UnitDelay: '<S73>/UD' */
  brain_DWork.UD_DSTATE_b = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
  brain_DWork.RunningBuoyBuoy_PREV_T = brain_M->Timing.clockTick0;
  brain_DWork.RunningFollowTrackStage1AimTr_d = brain_M->Timing.clockTick0;
  brain_DWork.RunningFollowTrackStage2Posit_a = brain_M->Timing.clockTick0;
  brain_DWork.RunningFindBuoyStraightLevelC_j = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S33>/UD' */
  brain_DWork.UD_DSTATE_e = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S31>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_D_k = 0.0;

  /* InitializeConditions for UnitDelay: '<S34>/UD' */
  brain_DWork.UD_DSTATE_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
  brain_DWork.RunningFollowTrackStage3ReOri_a = brain_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S60>/UD' */
  brain_DWork.UD_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Depth Discrete-Time Integrator' */
  brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

  /* InitializeConditions for UnitDelay: '<S61>/UD' */
  brain_DWork.UD_DSTATE_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' */
  brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.0;
}

/* Start for atomic system: '<Root>/Chart' */
void brain_Chart_Start(void)
{
  /* Start for Stateflow: '<Root>/Chart' incorporates:
   *  Start for SubSystem: '<S1>/Running.Buoy.Buoy'
   *  Start for SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
   *  Start for SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
   *  Start for SubSystem: '<S1>/Running.FollowTrack.Stage1Aim.TrackStage1'
   *  Start for SubSystem: '<S1>/Running.FollowTrack.Stage2Position.TrackStage2'
   *  Start for SubSystem: '<S1>/Running.FollowTrack.Stage3ReOrient.DirectionalControl'
   *  Start for SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
   *  Start for SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
   */

  /* Start for If: '<S10>/If' */
  brain_DWork.If_ActiveSubsystem_o = -1;

  /* Start for If: '<S5>/If' */
  brain_DWork.If_ActiveSubsystem_h = -1;

  /* Start for If: '<S8>/If' */
  brain_DWork.If_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<Root>/Chart' */
void brain_Chart(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_TSamp_j;
  real_T rtb_TSamp_e;
  real_T rtb_Add1;
  real_T rtb_TSamp_i;
  real_T rtb_TSamp_jp;
  real_T rtb_TSamp_m;
  real_T rtb_TSamp_b;
  real_T rtb_TSamp_g;
  real_T rtb_TSamp_n;
  real_T rtb_TSamp_gz;
  real_T rtb_TSamp_iq;
  real_T rtb_Sum;
  real_T rtb_MultiportSwitch;
  real_T rtb_MultiportSwitch_k;
  real_T rtb_Sum_c;
  real_T rtb_Add;
  real_T rtb_Add_e;
  real_T rtb_Sum_l;
  real_T rtb_Add_k;
  real_T rtb_Sum_p;
  real_T rtb_Add4;
  real_T rtb_Error;

  /* local scratch DWork variables */
  real_T ResizeH_LineBuffer[480];
  real_T MedianFilterRed_WorkVector[27];
  real_T ResizeS_LineBuffer[480];
  real_T MedianFilterGreen_WorkVector[27];

  {
    real_T sf_ChangetoRight;
    int8_T rtAction;
    uint32_T BlobAnalysis_NUM_PIX_DW;
    real32_T ys;
    real32_T xys;
    real32_T uyy;
    real32_T rtb_BlobAnalysis_o1_i;
    real32_T rtb_BlobAnalysis_o2_j;
    real_T ys_0;
    real_T xys_0;
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
    real_T centroid[2];
    real_T rtb_XBuoyProportionalGain;
    real_T rtb_YBuoyProportionalGain_n;
    int32_T rtb_BuoyBlobAnalysis_o1[10];
    real_T rtb_BuoyBlobAnalysis_o2[20];
    int32_T i_0;
    real32_T centroid_idx;
    real32_T centroid_idx_0;
    real_T centroid_idx_1;
    real_T centroid_idx_2;
    int8_T rtb_DataTypeConversion_0;

    /* Stateflow: '<Root>/Chart' incorporates:
     *  Inport: '<Root>/CurrentDepth'
     *  Inport: '<Root>/CurrentHeading'
     *  Inport: '<Root>/DesiredState'
     *  Inport: '<Root>/Status'
     *  SubSystem: '<S1>/Running.Buoy.Buoy'
     *  SubSystem: '<S1>/Running.FindBuoy.LookforBuoy'
     *  SubSystem: '<S1>/Running.FindBuoy.StraightLevelControl'
     *  SubSystem: '<S1>/Running.FollowTrack.Stage1Aim.TrackStage1'
     *  SubSystem: '<S1>/Running.FollowTrack.Stage2Position.TrackStage2'
     *  SubSystem: '<S1>/Running.FollowTrack.Stage3ReOrient.DirectionalControl'
     *  SubSystem: '<S1>/Running.ValidationGate.LookforTrack'
     *  SubSystem: '<S1>/Running.ValidationGate.StraightLevelControl'
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
        break;

       case brain_IN_Running:
        /* During 'Running': '<S1>:289' */
        if (brain_U.Status != 1) {
          /* Transition: '<S1>:292' */
          brain_exit_internal_Running();

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
              for (i_0 = 0; i_0 < 307200; i_0++) {
                brain_B.SFunction_o17[i_0] = (real_T)
                  brain_B.ColorSpaceConversion1_o1[i_0];
                brain_B.SFunction_o18[i_0] = (real_T)
                  brain_B.ColorSpaceConversion1_o2[i_0];
              }

              brain_DWork.RunningBuoyBuoy_ELAPS_T = brain_M->Timing.clockTick0 -
                brain_DWork.RunningBuoyBuoy_PREV_T;
              brain_DWork.RunningBuoyBuoy_PREV_T = brain_M->Timing.clockTick0;

              /* Video Processing Blockset 2D Resize (svipresize) - '<S16>/ResizeH' */
              {
                const real_T *in = brain_B.SFunction_o17;
                real_T *out = brain_B.MedianFilterGreen;
                real_T *intBuf = &brain_DWork.ResizeH_IntBuffer[0];
                const int_T *pI = &brain_ConstP.pooled20[0];
                const real_T *pW = &brain_ConstP.pooled2[0];
                int_T row, col, k, ctr = 0;
                for (row = 0; row < 480; row++) {
                  int_T indx = row;
                  for (col = 0; col < 120; col++) {
                    int_T ictr = col;
                    real_T sum = 0.0;
                    for (k = 0; k < 11; k++) {
                      int_T offset = pI[ictr];
                      sum += in[row+offset*480] * pW[ictr];
                      ictr += 120;
                    }

                    intBuf[indx] = sum;
                    indx += 480;
                  }
                }

                pW = &brain_ConstP.pooled1[0];
                pI = &brain_ConstP.pooled19[0];
                for (col = 0; col < 120; col++) {
                  real_T *inB = intBuf + col*480;
                  real_T *lineBuf = &ResizeH_LineBuffer[0];
                  memcpy(lineBuf, inB, 480*sizeof(real_T));
                  for (row = 0; row < 90; row++) {
                    real_T sum = 0.0;
                    int_T ictr = row;
                    for (k = 0; k < 11; k++) {
                      int_T offset = pI[ictr];
                      sum += lineBuf[offset] * pW[ictr];
                      ictr += 90;
                    }

                    out[ctr++] = sum;
                  }
                }
              }

              /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S15>/Median Filter Red' */
              {
                /* Do appropriate padding of input matrix with a constant value */
                int_T i,j;
                const byte_T *u = (const byte_T *)brain_B.MedianFilterGreen;
                const int_T bytesPerInpCol = sizeof(real_T)* 90;
                real_T *y = (real_T *)&brain_DWork.ResizeH_IntBuffer[0];
                real_T padValue = 0.0;

                /* Pad at the top-left, left and bottom-left part of the input matrix */
                for (i = 0; i < 2; i++) {
                  for (j = 0; j < 94; j++) {
                    *y++ = padValue;
                  }
                }

                for (i = 2; i<122; i++) {
                  /* Pad at the top of the input matrix */
                  for (j = 0; j < 2; j++) {
                    *y++ = padValue;
                  }

                  /* Copy input matrix in the output buffer */
                  {
                    byte_T *y1 = (byte_T *)y;
                    memcpy(y1,u,bytesPerInpCol);
                    y += 90;
                    u += bytesPerInpCol;
                  }

                  /* Pad at the bottom of the input matrix */
                  for (j = 92; j < 94; j++) {
                    *y++ = padValue;
                  }
                }

                /* Pad at the top-right, right and bottom-right part of the input matrix */
                for (i = 122; i< 124; i++) {
                  for (j = 0; j < 94; j++) {
                    *y++ = padValue;
                  }
                }
              }

              {
                const real_T *inputA = &brain_DWork.ResizeH_IntBuffer[0];
                real_T *y = brain_B.MedianFilterGreen;
                real_T *inAC = &MedianFilterRed_WorkVector[0];
                int_T i,j,m,n;
                for (i = 0; i < 120; i++) {
                  int_T rowOffset = 94*(4+i);
                  for (j = 0; j < 90; j++) {
                    int_T indxA = rowOffset + j;
                    int_T ctr = 0;
                    for (m = 0; m < 5; m++) {
                      for (n = 0; n < 5; n++) {
                        inAC[ctr++] = inputA[indxA++];
                      }

                      indxA -= 99;
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

              for (i_0 = 0; i_0 < 10800; i_0++) {
                /* RelationalOperator: '<S11>/Compare' incorporates:
                 *  Constant: '<S11>/Constant'
                 */
                brain_B.buoy2Bitmap[i_0] = (brain_B.MedianFilterGreen[i_0] >
                  brain_P.Buoy_HueHigher);

                /* RelationalOperator: '<S12>/Compare' incorporates:
                 *  Constant: '<S12>/Constant'
                 */
                brain_B.Compare_e[i_0] = (brain_B.MedianFilterGreen[i_0] <=
                  brain_P.Buoy_HueLower);

                /* Logic: '<S3>/Logical Operator' */
                brain_B.buoy2Bitmap[i_0] = (brain_B.buoy2Bitmap[i_0] ||
                  brain_B.Compare_e[i_0]);
              }

              /* Video Processing Blockset 2D Resize (svipresize) - '<S16>/ResizeS' */
              {
                const real_T *in = brain_B.SFunction_o18;
                real_T *out = brain_B.MedianFilterGreen;
                real_T *intBuf = &brain_DWork.ResizeH_IntBuffer[0];
                const int_T *pI = &brain_ConstP.pooled20[0];
                const real_T *pW = &brain_ConstP.pooled2[0];
                int_T row, col, k, ctr = 0;
                for (row = 0; row < 480; row++) {
                  int_T indx = row;
                  for (col = 0; col < 120; col++) {
                    int_T ictr = col;
                    real_T sum = 0.0;
                    for (k = 0; k < 11; k++) {
                      int_T offset = pI[ictr];
                      sum += in[row+offset*480] * pW[ictr];
                      ictr += 120;
                    }

                    intBuf[indx] = sum;
                    indx += 480;
                  }
                }

                pW = &brain_ConstP.pooled1[0];
                pI = &brain_ConstP.pooled19[0];
                for (col = 0; col < 120; col++) {
                  real_T *inB = intBuf + col*480;
                  real_T *lineBuf = &ResizeS_LineBuffer[0];
                  memcpy(lineBuf, inB, 480*sizeof(real_T));
                  for (row = 0; row < 90; row++) {
                    real_T sum = 0.0;
                    int_T ictr = row;
                    for (k = 0; k < 11; k++) {
                      int_T offset = pI[ictr];
                      sum += lineBuf[offset] * pW[ictr];
                      ictr += 90;
                    }

                    out[ctr++] = sum;
                  }
                }
              }

              /* Video Processing Blockset 2D Median Filter (svipmdnfilter) - '<S15>/Median Filter Green' */
              {
                /* Do appropriate padding of input matrix with a constant value */
                int_T i,j;
                const byte_T *u = (const byte_T *)brain_B.MedianFilterGreen;
                const int_T bytesPerInpCol = sizeof(real_T)* 90;
                real_T *y = (real_T *)&brain_DWork.ResizeH_IntBuffer[0];
                real_T padValue = 0.0;

                /* Pad at the top-left, left and bottom-left part of the input matrix */
                for (i = 0; i < 2; i++) {
                  for (j = 0; j < 94; j++) {
                    *y++ = padValue;
                  }
                }

                for (i = 2; i<122; i++) {
                  /* Pad at the top of the input matrix */
                  for (j = 0; j < 2; j++) {
                    *y++ = padValue;
                  }

                  /* Copy input matrix in the output buffer */
                  {
                    byte_T *y1 = (byte_T *)y;
                    memcpy(y1,u,bytesPerInpCol);
                    y += 90;
                    u += bytesPerInpCol;
                  }

                  /* Pad at the bottom of the input matrix */
                  for (j = 92; j < 94; j++) {
                    *y++ = padValue;
                  }
                }

                /* Pad at the top-right, right and bottom-right part of the input matrix */
                for (i = 122; i< 124; i++) {
                  for (j = 0; j < 94; j++) {
                    *y++ = padValue;
                  }
                }
              }

              {
                const real_T *inputA = &brain_DWork.ResizeH_IntBuffer[0];
                real_T *y = brain_B.MedianFilterGreen;
                real_T *inAC = &MedianFilterGreen_WorkVector[0];
                int_T i,j,m,n;
                for (i = 0; i < 120; i++) {
                  int_T rowOffset = 94*(4+i);
                  for (j = 0; j < 90; j++) {
                    int_T indxA = rowOffset + j;
                    int_T ctr = 0;
                    for (m = 0; m < 5; m++) {
                      for (n = 0; n < 5; n++) {
                        inAC[ctr++] = inputA[indxA++];
                      }

                      indxA -= 99;
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

              for (i_0 = 0; i_0 < 10800; i_0++) {
                /* RelationalOperator: '<S13>/Compare' incorporates:
                 *  Constant: '<S13>/Constant'
                 */
                brain_B.Compare_e[i_0] = (brain_B.MedianFilterGreen[i_0] >=
                  brain_P.Buoy_Saturation);

                /* Logic: '<S3>/Logical Operator1' */
                brain_B.buoy2Bitmap[i_0] = (brain_B.buoy2Bitmap[i_0] &&
                  brain_B.Compare_e[i_0]);
              }

              /* S-Function (svipblob): '<S3>/Buoy Blob Analysis' */
              maxNumBlobsReached = false;
              for (i_0 = 0; i_0 < 93; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              }

              currentLabel = 1U;
              i_0 = 0;
              idx = 93;
              for (n = 0; n < 120; n++) {
                for (n_0 = 0; n_0 < 90; n_0++) {
                  brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)
                    (brain_B.buoy2Bitmap[i_0] ? 255 : 0);
                  i_0++;
                  idx++;
                }

                brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
                idx++;
                brain_DWork.BlobAnalysis_PAD_DW[idx] = 0U;
                idx++;
              }

              for (i_0 = 0; i_0 < 91; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0 + idx] = 0U;
              }

              n = 1;
              stackIdx = 0U;
              pixIdx = 0U;
              for (n_0 = 0; n_0 < 120; n_0++) {
                ms = 1;
                j = n * 92;
                for (idx = 0; idx < 90; idx++) {
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
                        walkerIdx = numBlobs + (uint32_T)
                          brain_ConstP.BuoyBlobAnalysis_WALK[i];
                        if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                          brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                            currentLabel;
                          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                            (int16_T)((int16_T)(walkerIdx / 92U) - 1);
                          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                            (int16_T)(walkerIdx % 92U - 1U);
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
                      n_0 = 120;
                      idx = 90;
                    }

                    if (idx < 90) {
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
              for (n = 0; n < (int32_T)numBlobs; n++) {
                rtb_BuoyBlobAnalysis_o1[n] = (int32_T)
                  BuoyBlobAnalysis_NUM_PIX_DW[n];
                idx = 0;
                ms = 0;
                for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n]; j++) {
                  idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n_0];
                  ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i_0];
                }

                centroid[0] = (real_T)ms / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
                centroid[1] = (real_T)idx / (real_T)
                  BuoyBlobAnalysis_NUM_PIX_DW[n];
                rtb_BuoyBlobAnalysis_o2[n << 1] = centroid[0];
                rtb_BuoyBlobAnalysis_o2[(n << 1) + 1] = centroid[1];
                i_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
                n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 10; i_0++) {
                rtb_BuoyBlobAnalysis_o1[i_0] = -1;
              }

              for (i_0 = (int32_T)numBlobs << 1; i_0 < 20; i_0++) {
                rtb_BuoyBlobAnalysis_o2[i_0] = -1.0;
              }

              /* Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
              /* Embedded MATLAB Function 'Chart/Running.Buoy.Buoy/Embedded MATLAB Function': '<S14>:1' */
              /*  This function will choose and return data about the largest blob given a  */
              /*  set of blobs */
              /* '<S14>:1:5' */
              brain_B.BlobArea = rtb_BuoyBlobAnalysis_o1[0];
              i_0 = 1;
              n = 1;
              for (n_0 = 2; n_0 < 11; n_0++) {
                n++;
                if (rtb_BuoyBlobAnalysis_o1[n - 1] > brain_B.BlobArea) {
                  brain_B.BlobArea = rtb_BuoyBlobAnalysis_o1[n - 1];
                  i_0 = n_0;
                }
              }

              /* '<S14>:1:5' */
              /* '<S14>:1:6' */
              brain_B.BlobCentroidX = rtb_BuoyBlobAnalysis_o2[i_0 + 1];

              /* '<S14>:1:7' */
              brain_B.BlobCentroidY = rtb_BuoyBlobAnalysis_o2[i_0 - 1];

              /* Sum: '<S17>/Subtract' incorporates:
               *  Constant: '<S17>/CenterX'
               */
              rtb_Sum_p = 60.0 - brain_B.BlobCentroidX;

              /* Gain: '<S19>/X-Buoy Proportional Gain' */
              rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Kp *
                rtb_Sum_p;

              /* Gain: '<S19>/X-Buoy Derivative Gain' */
              rtb_Error = brain_P.Cam_Forward_XPosition_Kd * rtb_Sum_p;

              /* S-Function (sfix_tsampmath): '<S20>/TSamp' */

              /* Sample Time Math Block: '<S20>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_gz = rtb_Error / (((brain_DWork.RunningBuoyBuoy_ELAPS_T *
                0.02))*(1.0));

              /* DiscreteIntegrator: '<S19>/X-Buoy Discrete-Time Integrator' */
              rtb_Error = brain_DWork.XBuoyDiscreteTimeIntegrator_DST;

              /* Sum: '<S19>/Sum' incorporates:
               *  Sum: '<S20>/Diff'
               *  UnitDelay: '<S20>/UD'
               */
              rtb_Error += (rtb_TSamp_gz - brain_DWork.UD_DSTATE_h) +
                rtb_XBuoyProportionalGain;

              /* DataTypeConversion: '<S17>/Data Type Conversion' */
              centroid_idx_1 = floor(rtb_Error);
              if (centroid_idx_1 < 128.0) {
                if (centroid_idx_1 >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              /* Sum: '<S17>/Add' incorporates:
               *  Constant: '<S17>/Vision_Forward_Velocity'
               */
              brain_B.Add_g = brain_P.Vision_Forward_Velocity + (real_T)
                rtb_DataTypeConversion_0;

              /* Product: '<S17>/Multiply' incorporates:
               *  Constant: '<S17>/Constant'
               */
              rtb_Error = (real_T)rtb_DataTypeConversion_0 * -1.0;

              /* Sum: '<S17>/Add1' incorporates:
               *  Constant: '<S17>/Vision_Forward_Velocity2'
               */
              brain_B.Add1_h = rtb_Error + brain_P.Vision_Forward_Velocity;

              /* Gain: '<S19>/X-Buoy Integral Gain' */
              rtb_XBuoyProportionalGain = brain_P.Cam_Forward_XPosition_Ki *
                rtb_Sum_p;

              /* Sum: '<S18>/Subtract' incorporates:
               *  Constant: '<S18>/CenterY'
               */
              rtb_Error = 45.0 - brain_B.BlobCentroidY;

              /* Gain: '<S21>/Y-Buoy Proportional Gain' */
              rtb_YBuoyProportionalGain_n = brain_P.Cam_Forward_YPosition_Kp *
                rtb_Error;

              /* Gain: '<S21>/Y-Buoy Derivative Gain' */
              rtb_Sum_p = brain_P.Cam_Forward_YPosition_Kd * rtb_Error;

              /* S-Function (sfix_tsampmath): '<S22>/TSamp' */

              /* Sample Time Math Block: '<S22>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_iq = rtb_Sum_p / (((brain_DWork.RunningBuoyBuoy_ELAPS_T *
                0.02))*(1.0));

              /* DiscreteIntegrator: '<S21>/Y-Buoy Discrete-Time Integrator' */
              rtb_Sum_p = brain_DWork.YBuoyDiscreteTimeIntegrator_D_n;

              /* Sum: '<S21>/Sum' incorporates:
               *  Sum: '<S22>/Diff'
               *  UnitDelay: '<S22>/UD'
               */
              rtb_Sum_p += (rtb_TSamp_iq - brain_DWork.UD_DSTATE_de) +
                rtb_YBuoyProportionalGain_n;

              /* DataTypeConversion: '<S18>/Data Type Conversion' */
              centroid_idx_1 = floor(rtb_Sum_p);
              if (centroid_idx_1 < 128.0) {
                if (centroid_idx_1 >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DataTypeConversion = rtb_DataTypeConversion_0;

              /* Update for UnitDelay: '<S20>/UD' */
              brain_DWork.UD_DSTATE_h = rtb_TSamp_gz;

              /* Update for DiscreteIntegrator: '<S19>/X-Buoy Discrete-Time Integrator' */
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

              /* Update for UnitDelay: '<S22>/UD' */
              brain_DWork.UD_DSTATE_de = rtb_TSamp_iq;

              /* Update for DiscreteIntegrator: '<S21>/Y-Buoy Discrete-Time Integrator' incorporates:
               *  Gain: '<S21>/Y-Buoy Integral Gain'
               */
              brain_DWork.YBuoyDiscreteTimeIntegrator_D_n = 0.02 * (real_T)
                brain_DWork.RunningBuoyBuoy_ELAPS_T
                * (brain_P.Cam_Forward_YPosition_Ki * rtb_Error) +
                brain_DWork.YBuoyDiscreteTimeIntegrator_D_n;
              if (brain_DWork.YBuoyDiscreteTimeIntegrator_D_n >= 15.0) {
                brain_DWork.YBuoyDiscreteTimeIntegrator_D_n = 15.0;
              } else {
                if (brain_DWork.YBuoyDiscreteTimeIntegrator_D_n <= -15.0) {
                  brain_DWork.YBuoyDiscreteTimeIntegrator_D_n = -15.0;
                }
              }

              brain_B.Right = (int8_T)brain_B.Add_g;
              brain_B.Left = (int8_T)brain_B.Add1_h;
              brain_B.Vertical = brain_B.DataTypeConversion;
              brain_B.BuoyCentroidX = brain_B.BlobCentroidY;
              brain_B.BuoyCentroidY = brain_B.BlobCentroidX;

              /* Embedded MATLAB Function 'countareas': '<S1>:83' */
              /*  This function acts to count the number of consecutive times a particular */
              /*  area is recognized by the recognition software */
              if (brain_B.BlobArea > 8000) {
                /* '<S1>:83:6' */
                /* '<S1>:83:7' */
                brain_DWork.countarea = brain_DWork.countarea + 1.0;
              } else {
                /* '<S1>:83:9' */
                brain_DWork.countarea = 0.0;
              }

              brain_ifbuoynotvisible(brain_B.BuoyCentroidX,
                brain_B.BuoyCentroidY, (real_T)brain_B.Right, (real_T)
                brain_B.Left, (real_T)brain_B.Vertical, &sf_ChangetoRight,
                &rtb_XBuoyProportionalGain, &rtb_YBuoyProportionalGain_n);
              brain_B.Right = (int8_T)sf_ChangetoRight;
              brain_B.Left = (int8_T)rtb_XBuoyProportionalGain;
              brain_B.Vertical = (int8_T)rtb_YBuoyProportionalGain_n;
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

              /* InitializeConditions for UnitDelay: '<S72>/UD' */
              brain_DWork.UD_DSTATE_nh = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S70>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_e = 0.0;

              /* InitializeConditions for UnitDelay: '<S73>/UD' */
              brain_DWork.UD_DSTATE_b = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S71>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrato_dv = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_DWork.TrackCount = 0.0;
              brain_B.State = 2U;
            } else if (brain_U.DesiredState == 3) {
              /* Transition: '<S1>:318' */
              /* Exit 'ChooseState': '<S1>:299' */
              /* Entry 'FollowTrack': '<S1>:198' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FollowTrack;
              brain_DWork.ErrorCountHeading = 0.0;

              /* Transition: '<S1>:219' */
              /* Entry 'Stage1Aim': '<S1>:213' */
              brain_DWork.is_FollowTrack = (uint8_T)brain_IN_Stage1Aim;
              brain_DWork.ErrorCountX = 0.0;
              brain_B.State = 3U;
            } else if (brain_U.DesiredState == 4) {
              /* Transition: '<S1>:320' */
              /* Exit 'ChooseState': '<S1>:299' */
              /* Entry 'FindBuoy': '<S1>:239' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FindBuoy;
              brain_DWork.RunningFindBuoyStraightLevelC_j =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S33>/UD' */
              brain_DWork.UD_DSTATE_e = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S31>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_k = 0.0;

              /* InitializeConditions for UnitDelay: '<S34>/UD' */
              brain_DWork.UD_DSTATE_l = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S32>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_B.CameraPosition = 0;
              brain_B.State = 4U;
              brain_DWork.BuoyCount = 0.0;
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
              for (i_0 = 0; i_0 < 307200; i_0++) {
                brain_B.SFunction_o33[i_0] = (real_T)
                  brain_B.ColorSpaceConversion1_o1[i_0];
                brain_B.SFunction_o34[i_0] = (real_T)
                  brain_B.ColorSpaceConversion1_o2[i_0];

                /* RelationalOperator: '<S25>/Compare' incorporates:
                 *  Constant: '<S25>/Constant'
                 */
                brain_B.buoy1Bitmap[i_0] = (brain_B.SFunction_o33[i_0] <
                  brain_P.Buoy_HueLower);

                /* RelationalOperator: '<S24>/Compare' incorporates:
                 *  Constant: '<S24>/Constant'
                 */
                brain_B.Compare[i_0] = (brain_B.SFunction_o33[i_0] >
                  brain_P.Buoy_HueHigher);

                /* Logic: '<S23>/Logical Operator' */
                brain_B.buoy1Bitmap[i_0] = (brain_B.buoy1Bitmap[i_0] ||
                  brain_B.Compare[i_0]);

                /* RelationalOperator: '<S28>/Compare' incorporates:
                 *  Constant: '<S28>/Constant'
                 */
                brain_B.Compare[i_0] = (brain_B.SFunction_o34[i_0] >
                  brain_P.Buoy_Saturation);

                /* Logic: '<S23>/Logical Operator1' */
                brain_B.buoy1Bitmap[i_0] = (brain_B.buoy1Bitmap[i_0] &&
                  brain_B.Compare[i_0]);
              }

              /* S-Function (svipblob): '<S23>/Blob Analysis' */
              maxNumBlobsReached = false;
              for (i_0 = 0; i_0 < 483; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
              }

              currentLabel = 1U;
              i_0 = 0;
              ms = 483;
              for (n = 0; n < 640; n++) {
                for (n_0 = 0; n_0 < 480; n_0++) {
                  brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)
                    (brain_B.buoy1Bitmap[i_0] ? 255 : 0);
                  i_0++;
                  ms++;
                }

                brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                ms++;
                brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                ms++;
              }

              for (i_0 = 0; i_0 < 481; i_0++) {
                brain_DWork.BlobAnalysis_PAD_DW[i_0 + ms] = 0U;
              }

              n = 1;
              stackIdx = 0U;
              pixIdx = 0U;
              for (ms = 0; ms < 640; ms++) {
                j = 1;
                idx = n * 482;
                for (n_0 = 0; n_0 < 480; n_0++) {
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
                        walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled21[i];
                        if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
                          brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                            currentLabel;
                          brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                            (int16_T)((int16_T)(walkerIdx / 482U) - 1);
                          brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                            (int16_T)(walkerIdx % 482U - 1U);
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
                      ms = 640;
                      n_0 = 480;
                    }

                    if (n_0 < 480) {
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
                n = 640;
                ms = 480;
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

                rtb_BlobAnalysis_o1_i = 0.0F;
                ys = 0.0F;
                xys = 0.0F;
                for (walkerIdx = 0U; walkerIdx < (uint32_T)(int32_T)
                     BlobAnalysis_NUM_PIX_DW; walkerIdx++) {
                  rtb_BlobAnalysis_o2_j = (real32_T)
                    brain_DWork.BlobAnalysis_N_PIXLIST_DW[i + walkerIdx] -
                    centroid_idx_0;
                  uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[n_0 +
                    walkerIdx] - centroid_idx;
                  rtb_BlobAnalysis_o1_i += rtb_BlobAnalysis_o2_j *
                    rtb_BlobAnalysis_o2_j;
                  ys += uyy * uyy;
                  xys += rtb_BlobAnalysis_o2_j * (-uyy);
                }

                centroid_idx = rtb_BlobAnalysis_o1_i / (real32_T)
                  BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
                uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
                rtb_BlobAnalysis_o1_i = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
                rtb_BlobAnalysis_o1_i = (real32_T)sqrt((centroid_idx - uyy) *
                  (centroid_idx - uyy) + rtb_BlobAnalysis_o1_i *
                  rtb_BlobAnalysis_o1_i * 4.0F);
                rtb_BlobAnalysis_o2_j = ((centroid_idx + uyy) +
                  rtb_BlobAnalysis_o1_i) * 8.0F;
                rtb_BlobAnalysis_o1_i = (real32_T)sqrt(rtb_BlobAnalysis_o2_j -
                  ((centroid_idx + uyy) - rtb_BlobAnalysis_o1_i) * 8.0F) /
                  (real32_T)sqrt(rtb_BlobAnalysis_o2_j);
                rtb_BlobAnalysis_o2_j = (real32_T)BlobAnalysis_NUM_PIX_DW /
                  (real32_T)(((idx + 1) - ms) * ((j + 1) - n));
                n_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
                i += (int32_T)BlobAnalysis_NUM_PIX_DW;
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                rtb_BlobAnalysis_o1_i = -1.0F;
              }

              for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                rtb_BlobAnalysis_o2_j = -1.0F;
              }

              /* If: '<S23>/If' incorporates:
               *  ActionPort: '<S26>/Action Port'
               *  ActionPort: '<S27>/Action Port'
               *  SubSystem: '<S23>/FoundBuoy'
               *  SubSystem: '<S23>/NoBuoy'
               */
              if ((rtb_BlobAnalysis_o1_i > 0.0F) && (rtb_BlobAnalysis_o1_i <
                   6.499999762E-01F) && (rtb_BlobAnalysis_o2_j >
                   6.999999881E-01F) && (rtb_BlobAnalysis_o2_j <
                   8.999999762E-01F)) {
                brain_FoundTrack(&brain_DWork.Image);
              } else {
                brain_NoTrack(&brain_DWork.Image);
              }

              sf_ChangetoRight = brain_B.DataStoreRead;

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
              brain_B.SFunction_o29 = (real32_T)brain_U.CurrentDepth;
              brain_B.SFunction_o30 = (real32_T)brain_B.DesiredDepth;
              brain_B.SFunction_o31 = brain_B.DesiredHeading;
              brain_B.SFunction_o32 = brain_U.CurrentHeading;
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
              rtb_Add4 = (real_T)brain_B.SFunction_o30 - (real_T)
                brain_B.SFunction_o29;

              /* Gain: '<S31>/Depth Proportional Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Add4;

              /* Gain: '<S31>/Depth Derivative Gain' */
              rtb_MultiportSwitch_k = brain_P.Depth_Kd * rtb_Add4;

              /* S-Function (sfix_tsampmath): '<S33>/TSamp' */

              /* Sample Time Math Block: '<S33>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_e = rtb_MultiportSwitch_k /
                (((brain_DWork.RunningFindBuoyStraightLevelCon * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S31>/Depth Discrete-Time Integrator' */
              rtb_MultiportSwitch_k =
                brain_DWork.DepthDiscreteTimeIntegrator_D_k;

              /* Sum: '<S31>/Sum' incorporates:
               *  Sum: '<S33>/Diff'
               *  UnitDelay: '<S33>/UD'
               */
              rtb_MultiportSwitch_k += (rtb_TSamp_e - brain_DWork.UD_DSTATE_e) +
                rtb_XBuoyProportionalGain;

              /* DataTypeConversion: '<S5>/Double To Int8' */
              centroid_idx_1 = floor(rtb_MultiportSwitch_k);
              if (centroid_idx_1 < 128.0) {
                if (centroid_idx_1 >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DoubleToInt8_g = rtb_DataTypeConversion_0;

              /* Gain: '<S31>/Depth Integral Gain' */
              rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Add4;

              /* Sum: '<S5>/Add1' */
              rtb_Add1 = brain_B.SFunction_o31 - brain_B.SFunction_o32;

              /* If: '<S5>/If' incorporates:
               *  ActionPort: '<S29>/Action Port'
               *  ActionPort: '<S30>/Action Port'
               *  SubSystem: '<S5>/BigError S1'
               *  SubSystem: '<S5>/BigNegativeError S2'
               */
              rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem_h;
              rtAction = -1;
              if (rtb_Add1 > 180.0) {
                rtAction = 0;
              } else {
                if (rtb_Add1 < -180.0) {
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
                brain_BigErrorS1(rtb_Add1, &brain_B.BigErrorS1_f);
                break;

               case 1:
                brain_BigNegativeErrorS2(rtb_Add1, &brain_B.BigNegativeErrorS2_h);
                break;
              }

              /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
               *  Constant: '<S5>/Constant1'
               *  Sum: '<S5>/Add2'
               */
              switch ((int32_T)((1.0 + brain_B.BigErrorS1_f.Constant1) +
                                brain_B.BigNegativeErrorS2_h.Constant1)) {
               case 1:
                rtb_MultiportSwitch_k = rtb_Add1;
                break;

               case 2:
                rtb_MultiportSwitch_k = brain_B.BigErrorS1_f.Add;
                break;

               default:
                rtb_MultiportSwitch_k = brain_B.BigNegativeErrorS2_h.Add;
                break;
              }

              /* Gain: '<S32>/Heading Proportional Gain' */
              rtb_YBuoyProportionalGain_n = brain_P.Heading_Kp *
                rtb_MultiportSwitch_k;

              /* Gain: '<S32>/Heading Derivative Gain' */
              rtb_Add4 = brain_P.Heading_Kd * rtb_MultiportSwitch_k;

              /* S-Function (sfix_tsampmath): '<S34>/TSamp' */

              /* Sample Time Math Block: '<S34>/TSamp'
               *
               * y = u * K     where     K = 1 / ( w * Ts )
               *
               * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
               * ElapsedTime Data Type:  Floating Point real_T
               */
              rtb_TSamp_i = rtb_Add4 /
                (((brain_DWork.RunningFindBuoyStraightLevelCon * 0.02))*(1.0));

              /* DiscreteIntegrator: '<S32>/Heading Discrete-Time Integrator' */
              rtb_Add4 = brain_DWork.HeadingDiscreteTimeIntegrator_d;

              /* Sum: '<S32>/Sum' incorporates:
               *  Sum: '<S34>/Diff'
               *  UnitDelay: '<S34>/UD'
               */
              rtb_Add4 += (rtb_TSamp_i - brain_DWork.UD_DSTATE_l) +
                rtb_YBuoyProportionalGain_n;

              /* Product: '<S5>/Multiply' incorporates:
               *  Constant: '<S5>/Constant'
               */
              centroid_idx_1 = -rtb_Add4;
              if (rtIsNaN(centroid_idx_1) || rtIsInf(centroid_idx_1)) {
                centroid_idx_1 = 0.0;
              } else {
                centroid_idx_1 = fmod(floor(centroid_idx_1), 256.0);
              }

              /* Sum: '<S5>/Add4' incorporates:
               *  Constant: '<S5>/Heading Forward Velocity'
               */
              rtb_Add4 += brain_P.Heading_Forward_Velocity;

              /* DataTypeConversion: '<S5>/DoubleToint1' incorporates:
               *  Constant: '<S5>/Heading Forward Velocity2'
               *  Sum: '<S5>/Add3'
               */
              centroid_idx_1 = floor((real_T)(centroid_idx_1 < 0.0 ? (int8_T)
                                      (-((int8_T)(uint8_T)(-centroid_idx_1))) :
                                      (int8_T)(uint8_T)centroid_idx_1) +
                brain_P.Heading_Forward_Velocity);
              if (centroid_idx_1 < 128.0) {
                if (centroid_idx_1 >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DoubleToint1_j = rtb_DataTypeConversion_0;

              /* DataTypeConversion: '<S5>/DoubleToint8' */
              centroid_idx_1 = floor(rtb_Add4);
              if (centroid_idx_1 < 128.0) {
                if (centroid_idx_1 >= -128.0) {
                  rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                } else {
                  rtb_DataTypeConversion_0 = MIN_int8_T;
                }
              } else {
                rtb_DataTypeConversion_0 = MAX_int8_T;
              }

              brain_B.DoubleToint8_p = rtb_DataTypeConversion_0;

              /* Update for UnitDelay: '<S33>/UD' */
              brain_DWork.UD_DSTATE_e = rtb_TSamp_e;

              /* Update for DiscreteIntegrator: '<S31>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_k = 0.02 * (real_T)
                brain_DWork.RunningFindBuoyStraightLevelCon *
                rtb_XBuoyProportionalGain +
                brain_DWork.DepthDiscreteTimeIntegrator_D_k;
              if (brain_DWork.DepthDiscreteTimeIntegrator_D_k >= 10.0) {
                brain_DWork.DepthDiscreteTimeIntegrator_D_k = 10.0;
              } else {
                if (brain_DWork.DepthDiscreteTimeIntegrator_D_k <= -10.0) {
                  brain_DWork.DepthDiscreteTimeIntegrator_D_k = -10.0;
                }
              }

              /* Update for UnitDelay: '<S34>/UD' */
              brain_DWork.UD_DSTATE_l = rtb_TSamp_i;

              /* Update for DiscreteIntegrator: '<S32>/Heading Discrete-Time Integrator' incorporates:
               *  Gain: '<S32>/Heading Integral Gain'
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

              brain_B.Vertical = brain_B.DoubleToInt8_g;
              brain_B.Left = brain_B.DoubleToint8_p;
              brain_B.Right = brain_B.DoubleToint1_j;
              brain_DWork.OldObstacle = sf_ChangetoRight;
              brain_DWork.count = brain_DWork.BuoyCount;
            }
            break;

           case brain_IN_Finish:
            break;

           case brain_IN_FollowTrack:
            /* During 'FollowTrack': '<S1>:198' */
            if ((brain_DWork.ErrorCountHeading > 3.0) && (brain_U.DesiredState ==
                 0)) {
              /* Transition: '<S1>:240' */
              switch (brain_DWork.is_FollowTrack) {
               case brain_IN_Stage1Aim:
                /* Exit 'Stage1Aim': '<S1>:213' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               case brain_IN_Stage2Position:
                /* Exit 'Stage2Position': '<S1>:214' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               case brain_IN_Stage3ReOrient:
                /* Exit 'Stage3ReOrient': '<S1>:259' */

                /* Disable for If: '<S8>/If' */
                brain_DWork.If_ActiveSubsystem = -1;
                brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);
                brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

                /* Disable for ifaction SubSystem: '<S8>/BigError S1' */
                brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);

                /* end of Disable for SubSystem: '<S8>/BigError S1' */

                /* Disable for ifaction SubSystem: '<S8>/BigNegativeError S2' */
                brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

                /* end of Disable for SubSystem: '<S8>/BigNegativeError S2' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               default:
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;
              }

              /* Exit 'FollowTrack': '<S1>:198' */
              /* Entry 'FindBuoy': '<S1>:239' */
              brain_DWork.is_Running = (uint8_T)brain_IN_FindBuoy;
              brain_DWork.RunningFindBuoyStraightLevelC_j =
                brain_M->Timing.clockTick0;

              /* InitializeConditions for UnitDelay: '<S33>/UD' */
              brain_DWork.UD_DSTATE_e = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S31>/Depth Discrete-Time Integrator' */
              brain_DWork.DepthDiscreteTimeIntegrator_D_k = 0.0;

              /* InitializeConditions for UnitDelay: '<S34>/UD' */
              brain_DWork.UD_DSTATE_l = 0.0;

              /* InitializeConditions for DiscreteIntegrator: '<S32>/Heading Discrete-Time Integrator' */
              brain_DWork.HeadingDiscreteTimeIntegrator_d = 0.0;
              brain_DWork.OldObstacle = 0.0;
              brain_DWork.count = 0.0;
              brain_B.CameraPosition = 0;
              brain_B.State = 4U;
              brain_DWork.BuoyCount = 0.0;
            } else if ((brain_U.DesiredState != 3) && (brain_U.DesiredState != 0))
            {
              /* Transition: '<S1>:304' */
              switch (brain_DWork.is_FollowTrack) {
               case brain_IN_Stage1Aim:
                /* Exit 'Stage1Aim': '<S1>:213' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               case brain_IN_Stage2Position:
                /* Exit 'Stage2Position': '<S1>:214' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               case brain_IN_Stage3ReOrient:
                /* Exit 'Stage3ReOrient': '<S1>:259' */

                /* Disable for If: '<S8>/If' */
                brain_DWork.If_ActiveSubsystem = -1;
                brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);
                brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

                /* Disable for ifaction SubSystem: '<S8>/BigError S1' */
                brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);

                /* end of Disable for SubSystem: '<S8>/BigError S1' */

                /* Disable for ifaction SubSystem: '<S8>/BigNegativeError S2' */
                brai_BigNegativeErrorS2_Disable(&brain_B.BigNegativeErrorS2_c);

                /* end of Disable for SubSystem: '<S8>/BigNegativeError S2' */
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;

               default:
                brain_DWork.is_FollowTrack = (uint8_T)0;
                break;
              }

              /* Exit 'FollowTrack': '<S1>:198' */
              /* Entry 'ChooseState': '<S1>:299' */
              brain_DWork.is_Running = (uint8_T)brain_IN_ChooseState;
            } else {
              switch (brain_DWork.is_FollowTrack) {
               case brain_IN_Stage1Aim:
                /* During 'Stage1Aim': '<S1>:213' */
                if (brain_DWork.ErrorCountX > 3.0) {
                  /* Transition: '<S1>:215' */
                  /* Exit 'Stage1Aim': '<S1>:213' */
                  /* Entry 'Stage2Position': '<S1>:214' */
                  brain_DWork.is_FollowTrack = (uint8_T)brain_IN_Stage2Position;
                  brain_DWork.ErrorCountY = 0.0;
                } else {
                  /* Simulink Function 'TrackStage1': '<S1>:202' */
                  brain_B.SFunction_o19 = brain_U.CurrentHeading;
                  brain_B.SFunction_o20 = (real32_T)brain_B.DesiredDepth;
                  brain_B.SFunction_o21 = (real32_T)brain_U.CurrentDepth;
                  brain_DWork.RunningFollowTrackStage1AimTrac =
                    brain_M->Timing.clockTick0 -
                    brain_DWork.RunningFollowTrackStage1AimTr_d;
                  brain_DWork.RunningFollowTrackStage1AimTr_d =
                    brain_M->Timing.clockTick0;
                  for (i_0 = 0; i_0 < 307200; i_0++) {
                    brain_B.SFunction_o22[i_0] = (real_T)
                      brain_B.ColorSpaceConversion1_o1[i_0];
                    brain_B.SFunction_o23[i_0] = (real_T)
                      brain_B.ColorSpaceConversion1_o2[i_0];

                    /* RelationalOperator: '<S37>/Compare' incorporates:
                     *  Constant: '<S37>/Constant'
                     */
                    brain_B.track2Bitmap[i_0] = (brain_B.SFunction_o22[i_0] >
                      brain_P.Track_HueHigher);

                    /* RelationalOperator: '<S38>/Compare' incorporates:
                     *  Constant: '<S38>/Constant'
                     */
                    brain_B.Compare_a[i_0] = (brain_B.SFunction_o22[i_0] <
                      brain_P.Track_HueLower);

                    /* Logic: '<S6>/Logical Operator' */
                    brain_B.track2Bitmap[i_0] = (brain_B.track2Bitmap[i_0] ||
                      brain_B.Compare_a[i_0]);

                    /* RelationalOperator: '<S39>/Compare' incorporates:
                     *  Constant: '<S39>/Constant'
                     */
                    brain_B.Compare_a[i_0] = (brain_B.SFunction_o23[i_0] >
                      brain_P.Track_Saturation);

                    /* Logic: '<S6>/Logical Operator1' */
                    brain_B.track2Bitmap[i_0] = (brain_B.track2Bitmap[i_0] &&
                      brain_B.Compare_a[i_0]);
                  }

                  /* S-Function (svipblob): '<S36>/Blob Analysis' */
                  maxNumBlobsReached = false;
                  for (i_0 = 0; i_0 < 483; i_0++) {
                    brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
                  }

                  currentLabel = 1U;
                  i_0 = 0;
                  ms = 483;
                  for (n = 0; n < 640; n++) {
                    for (n_0 = 0; n_0 < 480; n_0++) {
                      brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)
                        (brain_B.track2Bitmap[i_0] ? 255 : 0);
                      i_0++;
                      ms++;
                    }

                    brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                    ms++;
                    brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                    ms++;
                  }

                  for (i_0 = 0; i_0 < 481; i_0++) {
                    brain_DWork.BlobAnalysis_PAD_DW[i_0 + ms] = 0U;
                  }

                  n = 1;
                  stackIdx = 0U;
                  pixIdx = 0U;
                  for (ms = 0; ms < 640; ms++) {
                    j = 1;
                    idx = n * 482;
                    for (n_0 = 0; n_0 < 480; n_0++) {
                      numBlobs = (uint32_T)(idx + j);
                      start_pixIdx = pixIdx;
                      if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
                        brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
                        brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                          (n - 1);
                        brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                          (j - 1);
                        pixIdx++;
                        BlobAnalysis_NUM_PIX_DW = 1U;
                        brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
                        stackIdx++;
                        while (stackIdx) {
                          stackIdx--;
                          numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                          for (i = 0; i < 8; i++) {
                            walkerIdx = numBlobs + (uint32_T)
                              brain_ConstP.pooled21[i];
                            if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] ==
                                255) {
                              brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                                currentLabel;
                              brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                                (int16_T)((int16_T)(walkerIdx / 482U) - 1);
                              brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                                (int16_T)(walkerIdx % 482U - 1U);
                              pixIdx++;
                              BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW
                                + 1U;
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
                          ms = 640;
                          n_0 = 480;
                        }

                        if (n_0 < 480) {
                          currentLabel++;
                        }
                      }

                      j++;
                    }

                    n++;
                  }

                  numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel :
                                        (uint8_T)(currentLabel - 1));
                  i_0 = 0;
                  n = 0;
                  for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
                    idx = 0;
                    ms = 0;
                    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
                      idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
                      ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i_0];
                    }

                    centroid_idx_1 = (real_T)ms / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    centroid_idx_2 = (real_T)idx / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    centroid[n_0 << 1] = centroid_idx_1;
                    centroid[(n_0 << 1) + 1] = centroid_idx_2;
                    rtb_XBuoyProportionalGain = 0.0;
                    ys_0 = 0.0;
                    xys_0 = 0.0;
                    for (walkerIdx = 0U; walkerIdx < (uint32_T)(int32_T)
                         BlobAnalysis_NUM_PIX_DW; walkerIdx++) {
                      rtb_YBuoyProportionalGain_n = (real_T)
                        brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + walkerIdx] -
                        centroid_idx_2;
                      sf_ChangetoRight = (real_T)
                        brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0 + walkerIdx] -
                        centroid_idx_1;
                      rtb_XBuoyProportionalGain += rtb_YBuoyProportionalGain_n *
                        rtb_YBuoyProportionalGain_n;
                      ys_0 += sf_ChangetoRight * sf_ChangetoRight;
                      xys_0 += rtb_YBuoyProportionalGain_n * (-sf_ChangetoRight);
                    }

                    centroid_idx_1 = rtb_XBuoyProportionalGain / (real_T)
                      BlobAnalysis_NUM_PIX_DW + 8.3333333333333329E-02;
                    sf_ChangetoRight = ys_0 / (real_T)BlobAnalysis_NUM_PIX_DW +
                      8.3333333333333329E-02;
                    rtb_XBuoyProportionalGain = xys_0 / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    rtb_YBuoyProportionalGain_n = sqrt((centroid_idx_1 -
                      sf_ChangetoRight) * (centroid_idx_1 - sf_ChangetoRight) +
                      rtb_XBuoyProportionalGain * rtb_XBuoyProportionalGain *
                      4.0);
                    if (sf_ChangetoRight > centroid_idx_1) {
                      ys_0 = (sf_ChangetoRight - centroid_idx_1) +
                        rtb_YBuoyProportionalGain_n;
                      rtb_XBuoyProportionalGain *= 2.0;
                    } else {
                      ys_0 = 2.0 * rtb_XBuoyProportionalGain;
                      rtb_XBuoyProportionalGain = (centroid_idx_1 -
                        sf_ChangetoRight) + rtb_YBuoyProportionalGain_n;
                    }

                    sf_ChangetoRight = atan(ys_0 / (rtb_XBuoyProportionalGain +
                      2.2204460492503131E-16));
                    i_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
                    n += (int32_T)BlobAnalysis_NUM_PIX_DW;
                  }

                  for (i_0 = (int32_T)numBlobs << 1; i_0 < 2; i_0++) {
                    centroid[i_0] = -1.0;
                  }

                  for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                    sf_ChangetoRight = -1.0;
                  }

                  /* Sum: '<S6>/Add' incorporates:
                   *  Constant: '<S6>/CenterX'
                   */
                  brain_B.Add_d = 240.0 - centroid[0];

                  /* Sum: '<S35>/XError' incorporates:
                   *  Constant: '<S35>/ScreenCenterX'
                   */
                  rtb_Sum_l = 240.0 - centroid[0];

                  /* Gain: '<S41>/XPosition Proportional Gain' */
                  rtb_XBuoyProportionalGain = brain_P.Cam_Down_XPos_Kp *
                    rtb_Sum_l;

                  /* Gain: '<S41>/XPosition Derivative Gain' */
                  rtb_Add_k = brain_P.Cam_Down_XPos_Kd * rtb_Sum_l;

                  /* S-Function (sfix_tsampmath): '<S43>/TSamp' */

                  /* Sample Time Math Block: '<S43>/TSamp'
                   *
                   * y = u * K     where     K = 1 / ( w * Ts )
                   *
                   * Input0  Data Type:  Floating Point real_T
                   * Output0 Data Type:  Floating Point real_T
                   * ElapsedTime Data Type:  Floating Point real_T
                   */
                  rtb_TSamp_g = rtb_Add_k /
                    (((brain_DWork.RunningFollowTrackStage1AimTrac * 0.02))*(1.0));

                  /* DiscreteIntegrator: '<S41>/Depth Discrete-Time Integrator' */
                  rtb_Add_k = brain_DWork.DepthDiscreteTimeIntegrator_D_l;

                  /* Sum: '<S41>/Sum' incorporates:
                   *  Sum: '<S43>/Diff'
                   *  UnitDelay: '<S43>/UD'
                   */
                  rtb_Add_k += (rtb_TSamp_g - brain_DWork.UD_DSTATE_ea) +
                    rtb_XBuoyProportionalGain;

                  /* DataTypeConversion: '<S35>/DoubleToint1' */
                  centroid_idx_1 = floor(rtb_Add_k);
                  if (centroid_idx_1 < 128.0) {
                    if (centroid_idx_1 >= -128.0) {
                      rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                    } else {
                      rtb_DataTypeConversion_0 = MIN_int8_T;
                    }
                  } else {
                    rtb_DataTypeConversion_0 = MAX_int8_T;
                  }

                  brain_B.DoubleToint1_k = rtb_DataTypeConversion_0;

                  /* Product: '<S35>/Multiply1' incorporates:
                   *  Constant: '<S35>/Constant2'
                   */
                  brain_B.Multiply1 = (int8_T)(-brain_B.DoubleToint1_k);

                  /* Gain: '<S41>/XPosition Integral Gain' */
                  rtb_XBuoyProportionalGain = brain_P.Cam_Down_XPos_Ki *
                    rtb_Sum_l;

                  /* Sum: '<S35>/Add' */
                  rtb_Add_k = (real_T)brain_B.SFunction_o20 - (real_T)
                    brain_B.SFunction_o21;

                  /* Gain: '<S40>/Depth Proportional Gain' */
                  rtb_YBuoyProportionalGain_n = brain_P.Depth_Kp * rtb_Add_k;

                  /* Gain: '<S40>/Depth Derivative Gain' */
                  rtb_Sum_l = brain_P.Depth_Kd * rtb_Add_k;

                  /* S-Function (sfix_tsampmath): '<S42>/TSamp' */

                  /* Sample Time Math Block: '<S42>/TSamp'
                   *
                   * y = u * K     where     K = 1 / ( w * Ts )
                   *
                   * Input0  Data Type:  Floating Point real_T
                   * Output0 Data Type:  Floating Point real_T
                   * ElapsedTime Data Type:  Floating Point real_T
                   */
                  rtb_TSamp_n = rtb_Sum_l /
                    (((brain_DWork.RunningFollowTrackStage1AimTrac * 0.02))*(1.0));

                  /* DiscreteIntegrator: '<S40>/Depth Discrete-Time Integrator' */
                  rtb_Sum_l = brain_DWork.DepthDiscreteTimeIntegrator__d2;

                  /* Sum: '<S40>/Sum' incorporates:
                   *  Sum: '<S42>/Diff'
                   *  UnitDelay: '<S42>/UD'
                   */
                  rtb_Sum_l += (rtb_TSamp_n - brain_DWork.UD_DSTATE_ej) +
                    rtb_YBuoyProportionalGain_n;

                  /* DataTypeConversion: '<S35>/Double To Int8' */
                  centroid_idx_1 = floor(rtb_Sum_l);
                  if (centroid_idx_1 < 128.0) {
                    if (centroid_idx_1 >= -128.0) {
                      rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                    } else {
                      rtb_DataTypeConversion_0 = MIN_int8_T;
                    }
                  } else {
                    rtb_DataTypeConversion_0 = MAX_int8_T;
                  }

                  brain_B.DoubleToInt8_p = rtb_DataTypeConversion_0;

                  /* Sum: '<S36>/Add' incorporates:
                   *  Constant: '<S36>/Axis Correction'
                   *  Constant: '<S36>/Conv to Deg'
                   *  Product: '<S36>/Product'
                   */
                  brain_B.Add_l = (brain_B.SFunction_o19 - sf_ChangetoRight *
                                   5.7295827908797776E+01) + 90.0;

                  /* Update for UnitDelay: '<S43>/UD' */
                  brain_DWork.UD_DSTATE_ea = rtb_TSamp_g;

                  /* Update for DiscreteIntegrator: '<S41>/Depth Discrete-Time Integrator' */
                  brain_DWork.DepthDiscreteTimeIntegrator_D_l = 0.02 * (real_T)
                    brain_DWork.RunningFollowTrackStage1AimTrac *
                    rtb_XBuoyProportionalGain +
                    brain_DWork.DepthDiscreteTimeIntegrator_D_l;
                  if (brain_DWork.DepthDiscreteTimeIntegrator_D_l >= 10.0) {
                    brain_DWork.DepthDiscreteTimeIntegrator_D_l = 10.0;
                  } else {
                    if (brain_DWork.DepthDiscreteTimeIntegrator_D_l <= -10.0) {
                      brain_DWork.DepthDiscreteTimeIntegrator_D_l = -10.0;
                    }
                  }

                  /* Update for UnitDelay: '<S42>/UD' */
                  brain_DWork.UD_DSTATE_ej = rtb_TSamp_n;

                  /* Update for DiscreteIntegrator: '<S40>/Depth Discrete-Time Integrator' incorporates:
                   *  Gain: '<S40>/Depth Integral Gain'
                   */
                  brain_DWork.DepthDiscreteTimeIntegrator__d2 = 0.02 * (real_T)
                    brain_DWork.RunningFollowTrackStage1AimTrac *
                    (brain_P.Depth_Ki * rtb_Add_k) +
                    brain_DWork.DepthDiscreteTimeIntegrator__d2;
                  if (brain_DWork.DepthDiscreteTimeIntegrator__d2 >= 10.0) {
                    brain_DWork.DepthDiscreteTimeIntegrator__d2 = 10.0;
                  } else {
                    if (brain_DWork.DepthDiscreteTimeIntegrator__d2 <= -10.0) {
                      brain_DWork.DepthDiscreteTimeIntegrator__d2 = -10.0;
                    }
                  }

                  brain_B.DesiredHeading = brain_B.Add_l;
                  brain_B.Right = brain_B.Multiply1;
                  brain_B.Left = brain_B.DoubleToint1_k;
                  brain_B.Vertical = brain_B.DoubleToInt8_p;

                  /* Embedded MATLAB Function 'ErrorCounter': '<S1>:216' */
                  if ((brain_B.Add_d < 10.0) && (brain_B.Add_d > -10.0)) {
                    /* '<S1>:216:4' */
                    /* '<S1>:216:5' */
                    brain_DWork.ErrorCountX = brain_DWork.ErrorCountX + 1.0;
                  } else {
                    /* '<S1>:216:7' */
                    brain_DWork.ErrorCountX = 0.0;
                  }
                }
                break;

               case brain_IN_Stage2Position:
                /* During 'Stage2Position': '<S1>:214' */
                if (brain_DWork.ErrorCountY > 3.0) {
                  /* Transition: '<S1>:260' */
                  /* Exit 'Stage2Position': '<S1>:214' */
                  /* Entry 'Stage3ReOrient': '<S1>:259' */
                  brain_DWork.is_FollowTrack = (uint8_T)brain_IN_Stage3ReOrient;
                  brain_DWork.RunningFollowTrackStage3ReOri_a =
                    brain_M->Timing.clockTick0;

                  /* InitializeConditions for UnitDelay: '<S60>/UD' */
                  brain_DWork.UD_DSTATE = 0.0;

                  /* InitializeConditions for DiscreteIntegrator: '<S58>/Depth Discrete-Time Integrator' */
                  brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.0;

                  /* InitializeConditions for UnitDelay: '<S61>/UD' */
                  brain_DWork.UD_DSTATE_k = 0.0;

                  /* InitializeConditions for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' */
                  brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.0;
                } else {
                  /* Simulink Function 'TrackStage2': '<S1>:221' */
                  brain_B.SFunction_o24 = brain_U.CurrentHeading;
                  brain_B.SFunction_o25 = (real32_T)brain_B.DesiredDepth;
                  brain_B.SFunction_o26 = (real32_T)brain_U.CurrentDepth;
                  brain_DWork.RunningFollowTrackStage2Positio =
                    brain_M->Timing.clockTick0 -
                    brain_DWork.RunningFollowTrackStage2Posit_a;
                  brain_DWork.RunningFollowTrackStage2Posit_a =
                    brain_M->Timing.clockTick0;
                  for (i_0 = 0; i_0 < 307200; i_0++) {
                    brain_B.SFunction_o27[i_0] = (real_T)
                      brain_B.ColorSpaceConversion1_o1[i_0];
                    brain_B.SFunction_o28[i_0] = (real_T)
                      brain_B.ColorSpaceConversion1_o2[i_0];

                    /* RelationalOperator: '<S47>/Compare' incorporates:
                     *  Constant: '<S47>/Constant'
                     */
                    brain_B.track3Bitmap[i_0] = (brain_B.SFunction_o27[i_0] >
                      brain_P.Track_HueHigher);

                    /* RelationalOperator: '<S48>/Compare' incorporates:
                     *  Constant: '<S48>/Constant'
                     */
                    brain_B.Compare_o[i_0] = (brain_B.SFunction_o27[i_0] <
                      brain_P.Track_HueLower);

                    /* Logic: '<S7>/Logical Operator' */
                    brain_B.track3Bitmap[i_0] = (brain_B.track3Bitmap[i_0] ||
                      brain_B.Compare_o[i_0]);

                    /* RelationalOperator: '<S49>/Compare' incorporates:
                     *  Constant: '<S49>/Constant'
                     */
                    brain_B.Compare_o[i_0] = (brain_B.SFunction_o28[i_0] >
                      brain_P.Track_Saturation);

                    /* Logic: '<S7>/Logical Operator1' */
                    brain_B.track3Bitmap[i_0] = (brain_B.track3Bitmap[i_0] &&
                      brain_B.Compare_o[i_0]);
                  }

                  /* S-Function (svipblob): '<S45>/Blob Analysis' */
                  maxNumBlobsReached = false;
                  for (i_0 = 0; i_0 < 483; i_0++) {
                    brain_DWork.BlobAnalysis_PAD_DW[i_0] = 0U;
                  }

                  currentLabel = 1U;
                  i_0 = 0;
                  ms = 483;
                  for (n = 0; n < 640; n++) {
                    for (n_0 = 0; n_0 < 480; n_0++) {
                      brain_DWork.BlobAnalysis_PAD_DW[ms] = (uint8_T)
                        (brain_B.track3Bitmap[i_0] ? 255 : 0);
                      i_0++;
                      ms++;
                    }

                    brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                    ms++;
                    brain_DWork.BlobAnalysis_PAD_DW[ms] = 0U;
                    ms++;
                  }

                  for (i_0 = 0; i_0 < 481; i_0++) {
                    brain_DWork.BlobAnalysis_PAD_DW[i_0 + ms] = 0U;
                  }

                  n = 1;
                  stackIdx = 0U;
                  pixIdx = 0U;
                  for (ms = 0; ms < 640; ms++) {
                    j = 1;
                    idx = n * 482;
                    for (n_0 = 0; n_0 < 480; n_0++) {
                      numBlobs = (uint32_T)(idx + j);
                      start_pixIdx = pixIdx;
                      if (brain_DWork.BlobAnalysis_PAD_DW[numBlobs] == 255) {
                        brain_DWork.BlobAnalysis_PAD_DW[numBlobs] = currentLabel;
                        brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                          (n - 1);
                        brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                          (j - 1);
                        pixIdx++;
                        BlobAnalysis_NUM_PIX_DW = 1U;
                        brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
                        stackIdx++;
                        while (stackIdx) {
                          stackIdx--;
                          numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
                          for (i = 0; i < 8; i++) {
                            walkerIdx = numBlobs + (uint32_T)
                              brain_ConstP.pooled21[i];
                            if (brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] ==
                                255) {
                              brain_DWork.BlobAnalysis_PAD_DW[walkerIdx] =
                                currentLabel;
                              brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] =
                                (int16_T)((int16_T)(walkerIdx / 482U) - 1);
                              brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] =
                                (int16_T)(walkerIdx % 482U - 1U);
                              pixIdx++;
                              BlobAnalysis_NUM_PIX_DW = BlobAnalysis_NUM_PIX_DW
                                + 1U;
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
                          ms = 640;
                          n_0 = 480;
                        }

                        if (n_0 < 480) {
                          currentLabel++;
                        }
                      }

                      j++;
                    }

                    n++;
                  }

                  numBlobs = (uint32_T)(maxNumBlobsReached ? currentLabel :
                                        (uint8_T)(currentLabel - 1));
                  i_0 = 0;
                  n = 0;
                  for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
                    idx = 0;
                    ms = 0;
                    for (j = 0; j < (int32_T)BlobAnalysis_NUM_PIX_DW; j++) {
                      idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
                      ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i_0];
                    }

                    centroid_idx_1 = (real_T)ms / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    centroid_idx_2 = (real_T)idx / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    centroid[n_0 << 1] = centroid_idx_1;
                    centroid[(n_0 << 1) + 1] = centroid_idx_2;
                    rtb_XBuoyProportionalGain = 0.0;
                    ys_0 = 0.0;
                    xys_0 = 0.0;
                    for (walkerIdx = 0U; walkerIdx < (uint32_T)(int32_T)
                         BlobAnalysis_NUM_PIX_DW; walkerIdx++) {
                      rtb_YBuoyProportionalGain_n = (real_T)
                        brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + walkerIdx] -
                        centroid_idx_2;
                      sf_ChangetoRight = (real_T)
                        brain_DWork.BlobAnalysis_M_PIXLIST_DW[i_0 + walkerIdx] -
                        centroid_idx_1;
                      rtb_XBuoyProportionalGain += rtb_YBuoyProportionalGain_n *
                        rtb_YBuoyProportionalGain_n;
                      ys_0 += sf_ChangetoRight * sf_ChangetoRight;
                      xys_0 += rtb_YBuoyProportionalGain_n * (-sf_ChangetoRight);
                    }

                    centroid_idx_1 = rtb_XBuoyProportionalGain / (real_T)
                      BlobAnalysis_NUM_PIX_DW + 8.3333333333333329E-02;
                    sf_ChangetoRight = ys_0 / (real_T)BlobAnalysis_NUM_PIX_DW +
                      8.3333333333333329E-02;
                    rtb_XBuoyProportionalGain = xys_0 / (real_T)
                      BlobAnalysis_NUM_PIX_DW;
                    rtb_YBuoyProportionalGain_n = sqrt((centroid_idx_1 -
                      sf_ChangetoRight) * (centroid_idx_1 - sf_ChangetoRight) +
                      rtb_XBuoyProportionalGain * rtb_XBuoyProportionalGain *
                      4.0);
                    if (sf_ChangetoRight > centroid_idx_1) {
                      ys_0 = (sf_ChangetoRight - centroid_idx_1) +
                        rtb_YBuoyProportionalGain_n;
                      rtb_XBuoyProportionalGain *= 2.0;
                    } else {
                      ys_0 = 2.0 * rtb_XBuoyProportionalGain;
                      rtb_XBuoyProportionalGain = (centroid_idx_1 -
                        sf_ChangetoRight) + rtb_YBuoyProportionalGain_n;
                    }

                    sf_ChangetoRight = atan(ys_0 / (rtb_XBuoyProportionalGain +
                      2.2204460492503131E-16));
                    i_0 += (int32_T)BlobAnalysis_NUM_PIX_DW;
                    n += (int32_T)BlobAnalysis_NUM_PIX_DW;
                  }

                  for (i_0 = (int32_T)numBlobs << 1; i_0 < 2; i_0++) {
                    centroid[i_0] = -1.0;
                  }

                  for (i_0 = (int32_T)numBlobs; i_0 < 1; i_0 = 1) {
                    sf_ChangetoRight = -1.0;
                  }

                  /* Sum: '<S7>/Add1' incorporates:
                   *  Constant: '<S7>/Constant'
                   */
                  brain_B.Add1_i = 320.0 - centroid[0];

                  /* Sum: '<S44>/XError' incorporates:
                   *  Constant: '<S44>/ScreenCenterX'
                   */
                  rtb_Sum_c = 240.0 - centroid[1];

                  /* Gain: '<S51>/XPosition Proportional Gain' */
                  rtb_XBuoyProportionalGain = brain_P.Cam_Down_XPos_Kp *
                    rtb_Sum_c;

                  /* Gain: '<S51>/XPosition Derivative Gain' */
                  rtb_Add = brain_P.Cam_Down_XPos_Kd * rtb_Sum_c;

                  /* S-Function (sfix_tsampmath): '<S53>/TSamp' */

                  /* Sample Time Math Block: '<S53>/TSamp'
                   *
                   * y = u * K     where     K = 1 / ( w * Ts )
                   *
                   * Input0  Data Type:  Floating Point real_T
                   * Output0 Data Type:  Floating Point real_T
                   * ElapsedTime Data Type:  Floating Point real_T
                   */
                  rtb_TSamp_jp = rtb_Add /
                    (((brain_DWork.RunningFollowTrackStage2Positio * 0.02))*(1.0));

                  /* DiscreteIntegrator: '<S51>/Depth Discrete-Time Integrator' */
                  rtb_Add = brain_DWork.DepthDiscreteTimeIntegrator_D_p;

                  /* Sum: '<S51>/Sum' incorporates:
                   *  Sum: '<S53>/Diff'
                   *  UnitDelay: '<S53>/UD'
                   */
                  rtb_Add += (rtb_TSamp_jp - brain_DWork.UD_DSTATE_n) +
                    rtb_XBuoyProportionalGain;

                  /* DataTypeConversion: '<S44>/DoubleToint1' */
                  centroid_idx_1 = floor(rtb_Add);
                  if (centroid_idx_1 < 128.0) {
                    if (centroid_idx_1 >= -128.0) {
                      rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                    } else {
                      rtb_DataTypeConversion_0 = MIN_int8_T;
                    }
                  } else {
                    rtb_DataTypeConversion_0 = MAX_int8_T;
                  }

                  /* Sum: '<S46>/Add' incorporates:
                   *  Constant: '<S46>/ScreenCenterY'
                   */
                  rtb_Add = 320.0 - centroid[0];

                  /* Gain: '<S54>/Y-Buoy Proportional Gain' */
                  rtb_XBuoyProportionalGain = brain_P.Cam_Down_YPos_Kp * rtb_Add;

                  /* Gain: '<S54>/Y-Buoy Derivative Gain' */
                  rtb_Add_e = brain_P.Cam_Down_YPos_Kd * rtb_Add;

                  /* S-Function (sfix_tsampmath): '<S55>/TSamp' */

                  /* Sample Time Math Block: '<S55>/TSamp'
                   *
                   * y = u * K     where     K = 1 / ( w * Ts )
                   *
                   * Input0  Data Type:  Floating Point real_T
                   * Output0 Data Type:  Floating Point real_T
                   * ElapsedTime Data Type:  Floating Point real_T
                   */
                  rtb_TSamp_m = rtb_Add_e /
                    (((brain_DWork.RunningFollowTrackStage2Positio * 0.02))*(1.0));

                  /* DiscreteIntegrator: '<S54>/Y-Buoy Discrete-Time Integrator' */
                  rtb_Add_e = brain_DWork.YBuoyDiscreteTimeIntegrator_DST;

                  /* Sum: '<S54>/Sum' incorporates:
                   *  Sum: '<S55>/Diff'
                   *  UnitDelay: '<S55>/UD'
                   */
                  rtb_Add_e += (rtb_TSamp_m - brain_DWork.UD_DSTATE_d) +
                    rtb_XBuoyProportionalGain;

                  /* DataTypeConversion: '<S46>/Double To Int8' */
                  centroid_idx_1 = floor(rtb_Add_e);
                  if (centroid_idx_1 < 128.0) {
                    if (centroid_idx_1 >= -128.0) {
                      rtAction = (int8_T)centroid_idx_1;
                    } else {
                      rtAction = MIN_int8_T;
                    }
                  } else {
                    rtAction = MAX_int8_T;
                  }

                  /* Sum: '<S7>/AddLeft' */
                  brain_B.AddLeft = (int8_T)(rtb_DataTypeConversion_0 + rtAction);

                  /* Sum: '<S7>/AddRight' incorporates:
                   *  Constant: '<S44>/Constant2'
                   *  Product: '<S44>/Multiply1'
                   */
                  brain_B.AddRight = (int8_T)((int8_T)(-rtb_DataTypeConversion_0)
                    + rtAction);

                  /* Gain: '<S51>/XPosition Integral Gain' */
                  rtb_XBuoyProportionalGain = brain_P.Cam_Down_XPos_Ki *
                    rtb_Sum_c;

                  /* Sum: '<S44>/Add' */
                  rtb_Add_e = (real_T)brain_B.SFunction_o25 - (real_T)
                    brain_B.SFunction_o26;

                  /* Gain: '<S50>/Depth Proportional Gain' */
                  rtb_YBuoyProportionalGain_n = brain_P.Depth_Kp * rtb_Add_e;

                  /* Gain: '<S50>/Depth Derivative Gain' */
                  rtb_Sum_c = brain_P.Depth_Kd * rtb_Add_e;

                  /* S-Function (sfix_tsampmath): '<S52>/TSamp' */

                  /* Sample Time Math Block: '<S52>/TSamp'
                   *
                   * y = u * K     where     K = 1 / ( w * Ts )
                   *
                   * Input0  Data Type:  Floating Point real_T
                   * Output0 Data Type:  Floating Point real_T
                   * ElapsedTime Data Type:  Floating Point real_T
                   */
                  rtb_TSamp_b = rtb_Sum_c /
                    (((brain_DWork.RunningFollowTrackStage2Positio * 0.02))*(1.0));

                  /* DiscreteIntegrator: '<S50>/Depth Discrete-Time Integrator' */
                  rtb_Sum_c = brain_DWork.DepthDiscreteTimeIntegrator_D_d;

                  /* Sum: '<S50>/Sum' incorporates:
                   *  Sum: '<S52>/Diff'
                   *  UnitDelay: '<S52>/UD'
                   */
                  rtb_Sum_c += (rtb_TSamp_b - brain_DWork.UD_DSTATE_db) +
                    rtb_YBuoyProportionalGain_n;

                  /* DataTypeConversion: '<S44>/Double To Int8' */
                  centroid_idx_1 = floor(rtb_Sum_c);
                  if (centroid_idx_1 < 128.0) {
                    if (centroid_idx_1 >= -128.0) {
                      rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                    } else {
                      rtb_DataTypeConversion_0 = MIN_int8_T;
                    }
                  } else {
                    rtb_DataTypeConversion_0 = MAX_int8_T;
                  }

                  brain_B.DoubleToInt8_m = rtb_DataTypeConversion_0;

                  /* Sum: '<S45>/Add' incorporates:
                   *  Constant: '<S45>/Axis Correction'
                   *  Constant: '<S45>/Conv to Deg'
                   *  Product: '<S45>/Product'
                   */
                  brain_B.Add = (brain_B.SFunction_o24 - sf_ChangetoRight *
                                 5.7295827908797776E+01) + 90.0;

                  /* Update for UnitDelay: '<S53>/UD' */
                  brain_DWork.UD_DSTATE_n = rtb_TSamp_jp;

                  /* Update for DiscreteIntegrator: '<S51>/Depth Discrete-Time Integrator' */
                  brain_DWork.DepthDiscreteTimeIntegrator_D_p = 0.02 * (real_T)
                    brain_DWork.RunningFollowTrackStage2Positio *
                    rtb_XBuoyProportionalGain +
                    brain_DWork.DepthDiscreteTimeIntegrator_D_p;
                  if (brain_DWork.DepthDiscreteTimeIntegrator_D_p >= 10.0) {
                    brain_DWork.DepthDiscreteTimeIntegrator_D_p = 10.0;
                  } else {
                    if (brain_DWork.DepthDiscreteTimeIntegrator_D_p <= -10.0) {
                      brain_DWork.DepthDiscreteTimeIntegrator_D_p = -10.0;
                    }
                  }

                  /* Update for UnitDelay: '<S55>/UD' */
                  brain_DWork.UD_DSTATE_d = rtb_TSamp_m;

                  /* Update for DiscreteIntegrator: '<S54>/Y-Buoy Discrete-Time Integrator' incorporates:
                   *  Gain: '<S54>/Y-Buoy Integral Gain'
                   */
                  brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 0.02 * (real_T)
                    brain_DWork.RunningFollowTrackStage2Positio *
                    (brain_P.Cam_Down_YPos_Ki * rtb_Add) +
                    brain_DWork.YBuoyDiscreteTimeIntegrator_DST;
                  if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
                    brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 15.0;
                  } else {
                    if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
                      brain_DWork.YBuoyDiscreteTimeIntegrator_DST = -15.0;
                    }
                  }

                  /* Update for UnitDelay: '<S52>/UD' */
                  brain_DWork.UD_DSTATE_db = rtb_TSamp_b;

                  /* Update for DiscreteIntegrator: '<S50>/Depth Discrete-Time Integrator' incorporates:
                   *  Gain: '<S50>/Depth Integral Gain'
                   */
                  brain_DWork.DepthDiscreteTimeIntegrator_D_d = 0.02 * (real_T)
                    brain_DWork.RunningFollowTrackStage2Positio *
                    (brain_P.Depth_Ki * rtb_Add_e) +
                    brain_DWork.DepthDiscreteTimeIntegrator_D_d;
                  if (brain_DWork.DepthDiscreteTimeIntegrator_D_d >= 10.0) {
                    brain_DWork.DepthDiscreteTimeIntegrator_D_d = 10.0;
                  } else {
                    if (brain_DWork.DepthDiscreteTimeIntegrator_D_d <= -10.0) {
                      brain_DWork.DepthDiscreteTimeIntegrator_D_d = -10.0;
                    }
                  }

                  brain_B.DesiredHeading = brain_B.Add;
                  brain_B.Right = brain_B.AddRight;
                  brain_B.Left = brain_B.AddLeft;
                  brain_B.Vertical = brain_B.DoubleToInt8_m;

                  /* Embedded MATLAB Function 'ErrorCounter': '<S1>:234' */
                  if ((brain_B.Add1_i < 5.0) && (brain_B.Add1_i > -5.0)) {
                    /* '<S1>:234:4' */
                    /* '<S1>:234:5' */
                    brain_DWork.ErrorCountY = brain_DWork.ErrorCountY + 1.0;
                  } else {
                    /* '<S1>:234:7' */
                    brain_DWork.ErrorCountY = 0.0;
                  }
                }
                break;

               case brain_IN_Stage3ReOrient:
                /* During 'Stage3ReOrient': '<S1>:259' */
                /* Simulink Function 'DirectionalControl': '<S1>:261' */
                brain_B.SFunction_o35 = (real32_T)brain_U.CurrentDepth;
                brain_B.SFunction_o36 = (real32_T)brain_B.DesiredDepth;
                brain_B.SFunction_o37 = brain_B.DesiredHeading;
                brain_B.SFunction_o38 = brain_U.CurrentHeading;
                if (brain_DWork.RunningFollowTrackStage3ReOri_b) {
                  brain_DWork.RunningFollowTrackStage3ReOrien = 0U;
                  brain_DWork.RunningFollowTrackStage3ReOri_b = false;
                } else {
                  brain_DWork.RunningFollowTrackStage3ReOrien =
                    brain_M->Timing.clockTick0 -
                    brain_DWork.RunningFollowTrackStage3ReOri_a;
                }

                brain_DWork.RunningFollowTrackStage3ReOri_a =
                  brain_M->Timing.clockTick0;

                /* Sum: '<S8>/Add' */
                rtb_Sum = (real_T)brain_B.SFunction_o36 - (real_T)
                  brain_B.SFunction_o35;

                /* Gain: '<S58>/Depth Proportional Gain' */
                rtb_XBuoyProportionalGain = brain_P.Depth_Kp * rtb_Sum;

                /* Gain: '<S58>/Depth Derivative Gain' */
                rtb_MultiportSwitch = brain_P.Depth_Kd * rtb_Sum;

                /* S-Function (sfix_tsampmath): '<S60>/TSamp' */

                /* Sample Time Math Block: '<S60>/TSamp'
                 *
                 * y = u * K     where     K = 1 / ( w * Ts )
                 *
                 * Input0  Data Type:  Floating Point real_T
                 * Output0 Data Type:  Floating Point real_T
                 * ElapsedTime Data Type:  Floating Point real_T
                 */
                rtb_TSamp = rtb_MultiportSwitch /
                  (((brain_DWork.RunningFollowTrackStage3ReOrien * 0.02))*(1.0));

                /* DiscreteIntegrator: '<S58>/Depth Discrete-Time Integrator' */
                rtb_MultiportSwitch =
                  brain_DWork.DepthDiscreteTimeIntegrator_DST;

                /* Sum: '<S58>/Sum' incorporates:
                 *  Sum: '<S60>/Diff'
                 *  UnitDelay: '<S60>/UD'
                 */
                rtb_MultiportSwitch += (rtb_TSamp - brain_DWork.UD_DSTATE) +
                  rtb_XBuoyProportionalGain;

                /* DataTypeConversion: '<S8>/Double To Int8' */
                centroid_idx_1 = floor(rtb_MultiportSwitch);
                if (centroid_idx_1 < 128.0) {
                  if (centroid_idx_1 >= -128.0) {
                    rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                  } else {
                    rtb_DataTypeConversion_0 = MIN_int8_T;
                  }
                } else {
                  rtb_DataTypeConversion_0 = MAX_int8_T;
                }

                brain_B.DoubleToInt8 = rtb_DataTypeConversion_0;

                /* Gain: '<S58>/Depth Integral Gain' */
                rtb_XBuoyProportionalGain = brain_P.Depth_Ki * rtb_Sum;

                /* Sum: '<S8>/Add1' */
                brain_B.Add1 = brain_B.SFunction_o37 - brain_B.SFunction_o38;

                /* If: '<S8>/If' incorporates:
                 *  ActionPort: '<S56>/Action Port'
                 *  ActionPort: '<S57>/Action Port'
                 *  SubSystem: '<S8>/BigError S1'
                 *  SubSystem: '<S8>/BigNegativeError S2'
                 */
                rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem;
                rtAction = -1;
                if (brain_B.Add1 > 180.0) {
                  rtAction = 0;
                } else {
                  if (brain_B.Add1 < -180.0) {
                    rtAction = 1;
                  }
                }

                brain_DWork.If_ActiveSubsystem = rtAction;
                if (rtb_DataTypeConversion_0 != rtAction) {
                  switch (rtb_DataTypeConversion_0) {
                   case 0:
                    brain_BigErrorS1_Disable(&brain_B.BigErrorS1_l);
                    break;

                   case 1:
                    brai_BigNegativeErrorS2_Disable
                      (&brain_B.BigNegativeErrorS2_c);
                    break;
                  }
                }

                switch (rtAction) {
                 case 0:
                  brain_BigErrorS1(brain_B.Add1, &brain_B.BigErrorS1_l);
                  break;

                 case 1:
                  brain_BigNegativeErrorS2(brain_B.Add1,
                    &brain_B.BigNegativeErrorS2_c);
                  break;
                }

                /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
                 *  Constant: '<S8>/Constant1'
                 *  Sum: '<S8>/Add2'
                 */
                switch ((int32_T)((1.0 + brain_B.BigErrorS1_l.Constant1) +
                                  brain_B.BigNegativeErrorS2_c.Constant1)) {
                 case 1:
                  rtb_MultiportSwitch = brain_B.Add1;
                  break;

                 case 2:
                  rtb_MultiportSwitch = brain_B.BigErrorS1_l.Add;
                  break;

                 default:
                  rtb_MultiportSwitch = brain_B.BigNegativeErrorS2_c.Add;
                  break;
                }

                /* Gain: '<S59>/Heading Proportional Gain' */
                rtb_YBuoyProportionalGain_n = brain_P.Heading_Kp *
                  rtb_MultiportSwitch;

                /* Gain: '<S59>/Heading Derivative Gain' */
                rtb_Sum = brain_P.Heading_Kd * rtb_MultiportSwitch;

                /* S-Function (sfix_tsampmath): '<S61>/TSamp' */

                /* Sample Time Math Block: '<S61>/TSamp'
                 *
                 * y = u * K     where     K = 1 / ( w * Ts )
                 *
                 * Input0  Data Type:  Floating Point real_T
                 * Output0 Data Type:  Floating Point real_T
                 * ElapsedTime Data Type:  Floating Point real_T
                 */
                rtb_TSamp_j = rtb_Sum /
                  (((brain_DWork.RunningFollowTrackStage3ReOrien * 0.02))*(1.0));

                /* DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' */
                rtb_Sum = brain_DWork.HeadingDiscreteTimeIntegrator_D;

                /* Sum: '<S59>/Sum' incorporates:
                 *  Sum: '<S61>/Diff'
                 *  UnitDelay: '<S61>/UD'
                 */
                rtb_Sum += (rtb_TSamp_j - brain_DWork.UD_DSTATE_k) +
                  rtb_YBuoyProportionalGain_n;

                /* DataTypeConversion: '<S8>/DoubleToint1' incorporates:
                 *  Constant: '<S8>/Constant'
                 *  Product: '<S8>/Multiply'
                 */
                centroid_idx_1 = -rtb_Sum;
                if (rtIsNaN(centroid_idx_1) || rtIsInf(centroid_idx_1)) {
                  centroid_idx_1 = 0.0;
                } else {
                  centroid_idx_1 = fmod(floor(centroid_idx_1), 256.0);
                }

                brain_B.DoubleToint1 = centroid_idx_1 < 0.0 ? (int8_T)(-((int8_T)
                  (uint8_T)(-centroid_idx_1))) : (int8_T)(uint8_T)centroid_idx_1;

                /* DataTypeConversion: '<S8>/DoubleToint8' */
                centroid_idx_1 = floor(rtb_Sum);
                if (centroid_idx_1 < 128.0) {
                  if (centroid_idx_1 >= -128.0) {
                    rtb_DataTypeConversion_0 = (int8_T)centroid_idx_1;
                  } else {
                    rtb_DataTypeConversion_0 = MIN_int8_T;
                  }
                } else {
                  rtb_DataTypeConversion_0 = MAX_int8_T;
                }

                brain_B.DoubleToint8 = rtb_DataTypeConversion_0;

                /* Update for UnitDelay: '<S60>/UD' */
                brain_DWork.UD_DSTATE = rtb_TSamp;

                /* Update for DiscreteIntegrator: '<S58>/Depth Discrete-Time Integrator' */
                brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.02 * (real_T)
                  brain_DWork.RunningFollowTrackStage3ReOrien *
                  rtb_XBuoyProportionalGain +
                  brain_DWork.DepthDiscreteTimeIntegrator_DST;
                if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
                  brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
                } else {
                  if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
                    brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
                  }
                }

                /* Update for UnitDelay: '<S61>/UD' */
                brain_DWork.UD_DSTATE_k = rtb_TSamp_j;

                /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
                 *  Gain: '<S59>/Heading Integral Gain'
                 */
                brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.02 * (real_T)
                  brain_DWork.RunningFollowTrackStage3ReOrien *
                  (brain_P.Heading_Ki * rtb_MultiportSwitch) +
                  brain_DWork.HeadingDiscreteTimeIntegrator_D;
                if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
                  brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
                } else {
                  if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
                    brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
                  }
                }

                brain_B.Vertical = brain_B.DoubleToInt8;
                brain_B.Left = brain_B.DoubleToint8;
                brain_B.Right = brain_B.DoubleToint1;

                /* Embedded MATLAB Function 'ErrorCounter': '<S1>:269' */
                if ((brain_B.Add1 < 5.0) && (brain_B.Add1 > -5.0)) {
                  /* '<S1>:269:4' */
                  /* '<S1>:269:5' */
                  brain_DWork.ErrorCountHeading = brain_DWork.ErrorCountHeading
                    + 1.0;
                } else {
                  /* '<S1>:269:7' */
                  brain_DWork.ErrorCountHeading = 0.0;
                }
                break;

               default:
                /* Transition: '<S1>:219' */
                /* Entry 'Stage1Aim': '<S1>:213' */
                brain_DWork.is_FollowTrack = (uint8_T)brain_IN_Stage1Aim;
                brain_DWork.ErrorCountX = 0.0;
                brain_B.State = 3U;
                break;
              }
            }
            break;

           case brain_IN_Start:
            brain_Start();
            break;

           case brain_IN_ValidationGate:
            brain_ValidationGate();
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

    /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion' incorporates:
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
      brain_B.viddR[outStep] = (real32_T)brain_B.vidR[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Green Data Type Conversion1' */
      brain_B.viddG[outStep] = (real32_T)brain_B.vidG[outStep] / 255.0F;

      /* S-Function (svipscalenconvert): '<S2>/Blue Data Type Conversion2' */
      brain_B.viddB[outStep] = (real32_T)brain_B.vidB[outStep] / 255.0F;
    }

    /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion1' */
    /* temporary variables for in-place operation */
    for (outStep = 0; outStep < 307200; outStep++) {
      /* First get the min and max of the RGB triplet */
      if (brain_B.viddR[outStep] > brain_B.viddG[outStep]) {
        if (brain_B.viddG[outStep] < brain_B.viddB[outStep]) {
          min = brain_B.viddG[outStep];
        } else {
          min = brain_B.viddB[outStep];
        }

        if (brain_B.viddR[outStep] > brain_B.viddB[outStep]) {
          max = brain_B.viddR[outStep];
        } else {
          max = brain_B.viddB[outStep];
        }
      } else {
        if (brain_B.viddR[outStep] < brain_B.viddB[outStep]) {
          min = brain_B.viddR[outStep];
        } else {
          min = brain_B.viddB[outStep];
        }

        if (brain_B.viddG[outStep] > brain_B.viddB[outStep]) {
          max = brain_B.viddG[outStep];
        } else {
          max = brain_B.viddB[outStep];
        }
      }

      min = max - min;
      if (max != 0.0F) {
        cc_1 = min / max;
      } else {
        cc_1 = 0.0F;
      }

      if (min != 0.0F) {
        if (brain_B.viddR[outStep] == max) {
          min = (brain_B.viddG[outStep] - brain_B.viddB[outStep]) / min;
        } else if (brain_B.viddG[outStep] == max) {
          min = (brain_B.viddB[outStep] - brain_B.viddR[outStep]) / min + 2.0F;
        } else {
          min = (brain_B.viddR[outStep] - brain_B.viddG[outStep]) / min + 4.0F;
        }

        min /= 6.0F;
        if (min < 0.0F) {
          min++;
        }
      } else {
        min = 0.0F;
      }

      /* assign the results */
      brain_B.ColorSpaceConversion1_o1[outStep] = min;
      brain_B.ColorSpaceConversion1_o2[outStep] = cc_1;
      brain_B.ColorSpaceConversion1_o3[outStep] = max;
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
