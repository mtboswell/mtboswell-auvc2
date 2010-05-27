/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.364
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu May 27 18:36:36 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu May 27 18:36:36 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives:
 *    1. Debugging
 *    2. Safety precaution
 *    3. Traceability
 *    4. Execution efficiency
 *    5. ROM efficiency
 *    6. RAM efficiency
 * Validation result: Not run
 */

#include "brain_capi.h"
#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/StateFlow Functions' */
#define brain_IN_ApproachBuoy          (1U)
#define brain_IN_Autonomous            (1U)
#define brain_IN_BackupAndMoveUp       (1U)
#define brain_IN_Buoy                  (1U)
#define brain_IN_CenterOver            (1U)
#define brain_IN_ChooseState           (2U)
#define brain_IN_ControlledRC          (2U)
#define brain_IN_Done                  (2U)
#define brain_IN_FindBuoy              (2U)
#define brain_IN_Finish                (3U)
#define brain_IN_FinishedwithBuoy      (2U)
#define brain_IN_FollowOnePath         (4U)
#define brain_IN_FollowOnePath1        (5U)
#define brain_IN_GetDirections         (3U)
#define brain_IN_GetInCorrectState     (5U)
#define brain_IN_GoAroundBuoy          (3U)
#define brain_IN_Initialize            (1U)
#define brain_IN_MoveForward           (3U)
#define brain_IN_NO_ACTIVE_CHILD       (0U)
#define brain_IN_NotRunning            (6U)
#define brain_IN_NotRunning_m          (1U)
#define brain_IN_OnePath               (2U)
#define brain_IN_Running               (2U)
#define brain_IN_Start                 (7U)
#define brain_IN_Start_m               (6U)
#define brain_IN_ValidationGate        (8U)
#define brain_IN_ValidationGate_m      (7U)

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
static void brain_max(const real_T eml_varargin_1[51660], real_T eml_maxval[180],
                      real_T eml_indx[180]);
static void brain_max_l(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);

/* Forward declaration for local functions */
static void brain_max_b(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx);

/* Forward declaration for local functions */
static void brain_enter_internal_Buoy(void);
static real_T brain_countareas(real_T sf_Size, real_T sf_count1);
static real_T brain_countimages(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1);
static void brain_GoAroundBuoy(void);
static void brain_Buoy(void);
static void brain_enter_internal_OnePath(void);
static void brain_refp1_cos(real_T eml_x[19200]);
static void brain_max_lrq(const real_T eml_varargin_1[80], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_max_lr(const real_T eml_varargin_1[120], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c9_brain(void);
static void brain_CombineBWs(const real_T sf_BWleft1[9600], const real_T
  sf_BWright1[9600], real_T sf_BWout1[19200]);
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT);
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong);
static void brain_OnePath(void);
static real_T brain_countimages_m(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1);
static void brain_ValidationGate(void);

/*
 * Output and update for atomic system:
 *    '<S8>/Embedded MATLAB Function1'
 *    '<S12>/Embedded MATLAB Function1'
 */
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB)
{
  /* Embedded MATLAB: '<S8>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1': '<S24>:1' */
  /*  This function finds the center of an image */
  /* '<S24>:1:6' */
  /* '<S24>:1:7' */
  localB->XCenter = 80.0;
  localB->YCenter = 60.0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePath(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_StateFlowFunctionsFollowOne
  *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S11>/PutHSVImageTogether' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S36>:1' */
  /*  This function simply makes an HSV image a single multidimensional */
  /*  signal */
  /* '<S36>:1:7' */
  memset((void *)(&localB->HSVImage1[0]), (int32_T)0.0, 57600U * sizeof(real_T));

  /* '<S36>:1:9' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[120 * i]), (void *)(&rtu_H1[120 * i]),
           120U * sizeof(real_T));
  }

  /* '<S36>:1:10' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[19200 + 120 * i]), (void *)(&rtu_S1[120 *
            i]), 120U * sizeof(real_T));
  }

  /* '<S36>:1:11' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[38400 + 120 * i]), (void *)(&rtu_V1[120 *
            i]), 120U * sizeof(real_T));
  }
}

/* Function for Embedded MATLAB: '<S51>/IsLinePresent' */
static void brain_max(const real_T eml_varargin_1[51660], real_T eml_maxval[180],
                      real_T eml_indx[180])
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
      while (((uint32_T)eml_exitg == 0U) && (eml_k < 288)) {
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

/* Function for Embedded MATLAB: '<S51>/IsLinePresent' */
static void brain_max_l(const real_T eml_varargin_1[180], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S51>/IsLinePresent' */
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
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
  memcpy((void *)&localB->eml_HoughTable[0], (void *)&rtu_HoughTable[0], 51660U *
         sizeof(real_T));

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent': '<S53>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S53>:1:5' */
  /* '<S53>:1:7' */
  /* '<S53>:1:9' */
  /* '<S53>:1:10' */
  /* '<S53>:1:11' */
  /* '<S53>:1:12' */
  /* '<S53>:1:13' */
  localB->Rho[0] = -999.0;
  localB->Theta[0] = -999.0;
  localB->maxVotes[0] = -999.0;
  localB->Rho[1] = -999.0;
  localB->Theta[1] = -999.0;
  localB->maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S53>:1:15' */
  brain_max(&rtu_HoughTable[0], eml_maxValues, eml_RhoIndices);
  brain_max_l(eml_maxValues, &eml_b, &eml_c);

  /* '<S53>:1:18' */
  localB->maxVotes[0] = eml_b;

  /* '<S53>:1:18' */
  eml_ThetaIndex_idx = eml_c;

  /* '<S53>:1:19' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_c - 1];
  if (localB->maxVotes[0] >= 15.0) {
    /* '<S53>:1:21' */
    /* '<S53>:1:22' */
    localB->eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 287 * ((int32_T)
      eml_c - 1)] = 0.0;

    /* '<S53>:1:24' */
    eml_index = 2;

    /* '<S53>:1:25' */
    eml_count = 0;
    while ((eml_index <= 2) && (eml_count < 12)) {
      /* '<S53>:1:26' */
      /* '<S53>:1:27' */
      eml_count++;
      brain_max(&localB->eml_HoughTable[0], eml_maxValues, eml_RhoIndices);
      brain_max_l(eml_maxValues, &eml_b, &eml_c);

      /* '<S53>:1:29' */
      localB->maxVotes[1] = eml_b;

      /* '<S53>:1:29' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S53>:1:30' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S53>:1:32' */
      localB->eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 287 * ((int32_T)
        eml_c - 1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S53>:1:34' */
        /* '<S53>:1:35' */
        eml_index = 3;
      }
    }

    /* '<S53>:1:40' */
    if (localB->maxVotes[0] > 15.0) {
      /* '<S53>:1:41' */
      /* '<S53>:1:42' */
      localB->Theta[0] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx - 1];

      /* '<S53>:1:43' */
      localB->Rho[0] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx - 1];
      if ((localB->Theta[0] > 0.0) && (localB->Rho[0] < 0.0)) {
        /* '<S53>:1:44' */
        /* '<S53>:1:45' */
        localB->Rho[0] = localB->Rho[0] * -1.0;
      }
    }

    /* '<S53>:1:40' */
    if (localB->maxVotes[1] > 15.0) {
      /* '<S53>:1:41' */
      /* '<S53>:1:42' */
      localB->Theta[1] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx_0 - 1];

      /* '<S53>:1:43' */
      localB->Rho[1] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx_0 - 1];
      if ((localB->Theta[1] > 0.0) && (localB->Rho[1] < 0.0)) {
        /* '<S53>:1:44' */
        /* '<S53>:1:45' */
        localB->Rho[1] = localB->Rho[1] * -1.0;
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S51>/IsLinePresent'
 *    '<S52>/IsLinePresent'
 */
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  /* Embedded MATLAB: '<S51>/IsLinePresent' */
  brain_c11_brain(rtu_HoughTable, rtu_ThetaValues, rtu_RhoValues, localB);
}

/* Function for Embedded MATLAB: '<S14>/GetHeadingToPath' */
static void brain_max_b(const real_T eml_varargin_1[4], real_T *eml_maxval,
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
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 5)) {
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
    for (eml_k = eml_itmp + 1; eml_k < 5; eml_k++) {
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

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePa_h(const boolean_T rtu_BWleft1[9600], const
  boolean_T rtu_BWright1[9600], real_T rtu_CurrentHeading1,
  rtB_StateFlowFunctionsFollowO_o *localB)
{
  real_T eml_Votes[4];
  real_T eml_b;
  real_T eml_c;
  real_T rtb_TmpSignalConversionAtSFun_o[4];
  real_T rtb_TmpSignalConversionAtSFun_j[4];
  real_T eml_maxIndex_idx;

  /* S-Function (sviphough): '<S51>/Hough Transform' */
  MWVIP_Hough_D(&rtu_BWleft1[0], &localB->HoughTransform_o1[0],
                &brain_ConstP.pooled9[0], &brain_ConstP.pooled10, 120, 80, 287,
                91);

  /* Embedded MATLAB: '<S51>/IsLinePresent' */
  brain_IsLinePresent(localB->HoughTransform_o1, localB->HoughTransform_o2,
                      localB->HoughTransform_o3, &localB->sf_IsLinePresent);

  /* S-Function (sviphough): '<S52>/Hough Transform' */
  MWVIP_Hough_D(&rtu_BWright1[0], &localB->HoughTransform_o1_p[0],
                &brain_ConstP.pooled9[0], &brain_ConstP.pooled10, 120, 80, 287,
                91);

  /* Embedded MATLAB: '<S52>/IsLinePresent' */
  brain_IsLinePresent(localB->HoughTransform_o1_p, localB->HoughTransform_o2_h,
                      localB->HoughTransform_o3_p, &localB->sf_IsLinePresent_m);

  /* SignalConversion: '<S50>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_TmpSignalConversionAtSFun_o[0] = localB->sf_IsLinePresent.Theta[0];
  rtb_TmpSignalConversionAtSFun_o[1] = localB->sf_IsLinePresent.Theta[1];

  /* SignalConversion: '<S50>/TmpSignal ConversionAt SFunction Inport3' */
  rtb_TmpSignalConversionAtSFun_o[2] = localB->sf_IsLinePresent_m.Theta[0];
  rtb_TmpSignalConversionAtSFun_j[0] = localB->sf_IsLinePresent.maxVotes[0];
  rtb_TmpSignalConversionAtSFun_o[3] = localB->sf_IsLinePresent_m.Theta[1];
  rtb_TmpSignalConversionAtSFun_j[1] = localB->sf_IsLinePresent.maxVotes[1];
  rtb_TmpSignalConversionAtSFun_j[2] = localB->sf_IsLinePresent_m.maxVotes[0];
  rtb_TmpSignalConversionAtSFun_j[3] = localB->sf_IsLinePresent_m.maxVotes[1];

  /* Embedded MATLAB: '<S14>/GetHeadingToPath' */
  eml_Votes[0] = rtb_TmpSignalConversionAtSFun_j[0];
  eml_Votes[1] = rtb_TmpSignalConversionAtSFun_j[1];
  eml_Votes[2] = rtb_TmpSignalConversionAtSFun_j[2];
  eml_Votes[3] = rtb_TmpSignalConversionAtSFun_j[3];

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath': '<S50>:1' */
  /*  This function calculates the heading to the path from Theta and Rho */
  /* '<S50>:1:4' */
  /* '<S50>:1:6' */
  /* '<S50>:1:7' */
  /* '<S50>:1:8' */
  localB->ToPathHeading[0] = -999.0;
  localB->AlongPathHeading[0] = -999.0;
  localB->ToPathHeading[1] = -999.0;
  localB->AlongPathHeading[1] = -999.0;
  brain_max_b(rtb_TmpSignalConversionAtSFun_j, &eml_b, &eml_c);

  /* '<S50>:1:11' */
  eml_maxIndex_idx = eml_c;

  /* '<S50>:1:12' */
  eml_Votes[(int32_T)eml_c - 1] = 0.0;

  /* '<S50>:1:13' */
  /* '<S50>:1:15' */
  /* '<S50>:1:16' */
  brain_max_b(eml_Votes, &eml_b, &eml_c);

  /* '<S50>:1:17' */
  /* '<S50>:1:18' */
  /* '<S50>:1:21' */
  /* '<S50>:1:35' */
  /* '<S50>:1:21' */
  if (eml_maxIndex_idx <= 2.0) {
    /* '<S50>:1:22' */
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_maxIndex_idx - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
      /* '<S50>:1:23' */
      /* '<S50>:1:24' */
      localB->ToPathHeading[0] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1) - 90.0;

      /* '<S50>:1:25' */
      localB->AlongPathHeading[0] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1;
    }
  } else {
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_maxIndex_idx - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
      /* '<S50>:1:28' */
      /* '<S50>:1:29' */
      localB->ToPathHeading[0] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1) + 90.0;

      /* '<S50>:1:30' */
      localB->AlongPathHeading[0] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1;
    }
  }

  /* '<S50>:1:35' */
  if (localB->ToPathHeading[0] != -999.0) {
    /* '<S50>:1:36' */
    if (localB->ToPathHeading[0] < 0.0) {
      /* '<S50>:1:37' */
      /* '<S50>:1:38' */
      localB->ToPathHeading[0] = localB->ToPathHeading[0] + 360.0;
    } else {
      if (localB->ToPathHeading[0] > 360.0) {
        /* '<S50>:1:39' */
        /* '<S50>:1:40' */
        localB->ToPathHeading[0] = localB->ToPathHeading[0] - 360.0;
      }
    }

    if (localB->AlongPathHeading[0] < 0.0) {
      /* '<S50>:1:43' */
      /* '<S50>:1:44' */
      localB->AlongPathHeading[0] = localB->AlongPathHeading[0] + 360.0;
    } else {
      if (localB->AlongPathHeading[0] > 360.0) {
        /* '<S50>:1:45' */
        /* '<S50>:1:46' */
        localB->AlongPathHeading[0] = localB->AlongPathHeading[0] - 360.0;
      }
    }
  }

  /* '<S50>:1:21' */
  if (eml_c <= 2.0) {
    /* '<S50>:1:22' */
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_c - 1] < 1.5707963267948966E+00)) {
      /* '<S50>:1:23' */
      /* '<S50>:1:24' */
      localB->ToPathHeading[1] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c
        - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) - 90.0;

      /* '<S50>:1:25' */
      localB->AlongPathHeading[1] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
    }
  } else {
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_c - 1] < 1.5707963267948966E+00)) {
      /* '<S50>:1:28' */
      /* '<S50>:1:29' */
      localB->ToPathHeading[1] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c
        - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) + 90.0;

      /* '<S50>:1:30' */
      localB->AlongPathHeading[1] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
    }
  }

  /* '<S50>:1:35' */
  if (localB->ToPathHeading[1] != -999.0) {
    /* '<S50>:1:36' */
    if (localB->ToPathHeading[1] < 0.0) {
      /* '<S50>:1:37' */
      /* '<S50>:1:38' */
      localB->ToPathHeading[1] = localB->ToPathHeading[1] + 360.0;
    } else {
      if (localB->ToPathHeading[1] > 360.0) {
        /* '<S50>:1:39' */
        /* '<S50>:1:40' */
        localB->ToPathHeading[1] = localB->ToPathHeading[1] - 360.0;
      }
    }

    if (localB->AlongPathHeading[1] < 0.0) {
      /* '<S50>:1:43' */
      /* '<S50>:1:44' */
      localB->AlongPathHeading[1] = localB->AlongPathHeading[1] + 360.0;
    } else {
      if (localB->AlongPathHeading[1] > 360.0) {
        /* '<S50>:1:45' */
        /* '<S50>:1:46' */
        localB->AlongPathHeading[1] = localB->AlongPathHeading[1] - 360.0;
      }
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
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

  /* Logic: '<S61>/Logical Operator1' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Logic: '<S61>/Logical Operator'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (((rtu_H[i] < brain_P.Track_HueLower) || (rtu_H[i] >
      brain_P.Track_HueHigher)) && (rtu_S[i] > brain_P.Track_Saturation));
  }

  /* S-Function (svipblob): '<S61>/Blob Analysis' */
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
            k = numBlobs + (uint32_T)brain_ConstP.pooled16[i];
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
      8.333333582E-02F;
    uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
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

  /* Embedded MATLAB: '<S61>/CheckConditions' incorporates:
   *  Constant: '<S61>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions': '<S62>:1' */
  /*  This function checks the conditions to decide if a track is present */
  if ((real_T)rtb_BlobAnalysis > brain_P.Track_Min_Eccentricity) {
    /* '<S62>:1:4' */
    /* '<S62>:1:5' */
    localB->Image = 1.0;
  } else {
    /* '<S62>:1:7' */
    localB->Image = 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_Buoy(void)
{
  /* Transition: '<S7>:1221' */
  /* Entry 'FindBuoy': '<S7>:1224' */
  brain_DWork.is_Buoy = brain_IN_FindBuoy;
  brain_DWork.OldObstacle = FALSE;
  brain_B.CameraPosition = 0;
  brain_B.State = 4;
  brain_DWork.BuoyCount = 0.0;
  brain_DWork.BuoyDone = 0.0;
  brain_B.DesiredDepth = 5.0;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countareas(real_T sf_Size, real_T sf_count1)
{
  /* Embedded MATLAB Function 'countareas': '<S7>:1243' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  area is recognized by the recognition software */
  if (sf_Size > 8500.0) {
    /* '<S7>:1243:6' */
    /* '<S7>:1243:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S7>:1243:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1)
{
  UNUSED_PARAMETER(sf_OldImage);

  /* Embedded MATLAB Function 'countimages': '<S7>:1225' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  image is recognized by the recognition software */
  if (sf_Image == 1.0) {
    /* '<S7>:1225:6' */
    /* '<S7>:1225:7' */
    return sf_count1 + 1.0;
  } else {
    /* '<S7>:1225:9' */
    return 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_GoAroundBuoy(void)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Add1;
  real_T rtb_Add4;
  real_T rtb_TSamp_j;
  real_T tmp;

  /* During 'GoAroundBuoy': '<S7>:1235' */
  switch (brain_DWork.is_GoAroundBuoy) {
   case brain_IN_BackupAndMoveUp:
    /* During 'BackupAndMoveUp': '<S7>:1239' */
    if (brain_DWork.Error > -0.5) {
      /* Transition: '<S7>:1238' */
      /* Exit 'BackupAndMoveUp': '<S7>:1239' */
      /* Entry 'MoveForward': '<S7>:1240' */
      brain_DWork.is_GoAroundBuoy = brain_IN_MoveForward;
      brain_DWork.temporalCounter_i1 = 0U;
      brain_B.DesiredDepth = 8.0;
    } else {
      /* Simulink Function 'MaintainHeading': '<S7>:918' */
      brain_B.DesiredHeading1 = brain_B.DesiredHeading;
      brain_B.CurrentHeading1 = brain_U.CurrentHeading;
      brain_B.ForwardVelocity1 = -10.0;
      brain_DWork.StateFlowFunctionsMaintainHeadi = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainHea_m;
      brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

      /* Sum: '<S17>/Add1' */
      rtb_Add1 = brain_B.DesiredHeading1 - brain_B.CurrentHeading1;

      /* If: '<S17>/If' incorporates:
       *  ActionPort: '<S57>/Action Port'
       *  ActionPort: '<S58>/Action Port'
       *  SubSystem: '<S17>/BigError S1'
       *  SubSystem: '<S17>/BigNegativeError S2'
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
          /* Disable for Outport: '<S57>/Out2' */
          brain_B.Constant1_e = 0.0;
          break;

         case 1:
          /* Disable for Outport: '<S58>/Out2' */
          brain_B.Constant1 = 0.0;
          break;
        }
      }

      switch (rtAction) {
       case 0:
        /* Sum: '<S57>/Add' incorporates:
         *  Constant: '<S57>/Constant'
         */
        brain_B.Add_o = rtb_Add1 - 360.0;

        /* Constant: '<S57>/Constant1' */
        brain_B.Constant1_e = 1.0;
        break;

       case 1:
        /* Sum: '<S58>/Add' incorporates:
         *  Constant: '<S58>/Constant'
         */
        brain_B.Add = rtb_Add1 + 360.0;

        /* Constant: '<S58>/Constant1' */
        brain_B.Constant1 = 2.0;
        break;
      }

      /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       *  Sum: '<S17>/Add2'
       */
      switch ((int32_T)((1.0 + brain_B.Constant1_e) + brain_B.Constant1)) {
       case 1:
        break;

       case 2:
        rtb_Add1 = brain_B.Add_o;
        break;

       default:
        rtb_Add1 = brain_B.Add;
        break;
      }

      /* SampleTimeMath: '<S60>/TSamp' incorporates:
       *  Gain: '<S59>/Heading Derivative Gain'
       *
       * About '<S60>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_j = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * 0.2);

      /* Sum: '<S59>/Sum' incorporates:
       *  DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator'
       *  Gain: '<S59>/Heading Proportional Gain'
       *  Sum: '<S60>/Diff'
       *  UnitDelay: '<S60>/UD'
       *
       * Block description for '<S60>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_j -
        brain_DWork.UD_DSTATE_p)) + brain_DWork.HeadingDiscreteTimeIntegrator_D;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S17>/Constant'
       */
      tmp = -rtb_Add4;
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(floor(tmp), 256.0);
      }

      /* Sum: '<S17>/Add4' */
      rtb_Add4 += brain_B.ForwardVelocity1;

      /* DataTypeConversion: '<S17>/DoubleToint1' incorporates:
       *  Sum: '<S17>/Add3'
       */
      tmp = floor((real_T)(int8_T)(tmp < 0.0 ? (int32_T)(int8_T)(-((int8_T)
        (uint8_T)(-tmp))) : (int32_T)(int8_T)(uint8_T)tmp) +
                  brain_B.ForwardVelocity1);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToint1 = (int8_T)tmp;
        } else {
          brain_B.DoubleToint1 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint1 = MAX_int8_T;
      }

      /* DataTypeConversion: '<S17>/DoubleToint8' */
      tmp = floor(rtb_Add4);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToint8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToint8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S60>/UD'
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_p = rtb_TSamp_j;

      /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
       *  Gain: '<S59>/Heading Integral Gain'
       */
      brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * (brain_P.Heading_Ki *
        rtb_Add1) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
      if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
      } else {
        if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
        }
      }

      brain_B.Left = brain_B.DoubleToint8;
      brain_B.Right = brain_B.DoubleToint1;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S16>/Add' */
      rtb_Add1 = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S56>/TSamp' incorporates:
       *  Gain: '<S55>/Depth Derivative Gain'
       *
       * About '<S56>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_j = brain_P.Depth_Kd * rtb_Add1 / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
       *  Gain: '<S55>/Depth Proportional Gain'
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
      tmp = floor((brain_P.Depth_Kp * rtb_Add1 + (rtb_TSamp_j -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S56>/UD'
       * Block description for '<S56>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = rtb_TSamp_j;

      /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S55>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        rtb_Add1) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
      } else {
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
        }
      }

      brain_B.Vertical = brain_B.DoubleToInt8;
      brain_DWork.Error = brain_B.DesiredDepth - brain_U.CurrentDepth;
    }
    break;

   case brain_IN_FinishedwithBuoy:
    break;

   case brain_IN_MoveForward:
    /* During 'MoveForward': '<S7>:1240' */
    if ((uint32_T)brain_DWork.temporalCounter_i1 >= 15U) {
      /* Transition: '<S7>:1237' */
      /* Exit 'MoveForward': '<S7>:1240' */
      /* Entry 'FinishedwithBuoy': '<S7>:1241' */
      brain_DWork.is_GoAroundBuoy = brain_IN_FinishedwithBuoy;
      brain_DWork.BuoyDone = 1.0;
    } else {
      /* Simulink Function 'GetBuoyForwardVelocity': '<S7>:1257' */

      /* Constant: '<S10>/Constant' */
      brain_B.Constant_i = brain_P.Heading_Forward_Velocity;

      /* Simulink Function 'MaintainHeading': '<S7>:918' */
      brain_B.DesiredHeading1 = brain_B.DesiredHeading;
      brain_B.CurrentHeading1 = brain_U.CurrentHeading;
      brain_B.ForwardVelocity1 = brain_B.Constant_i;
      brain_DWork.StateFlowFunctionsMaintainHeadi = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainHea_m;
      brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

      /* Sum: '<S17>/Add1' */
      rtb_Add1 = brain_B.DesiredHeading1 - brain_B.CurrentHeading1;

      /* If: '<S17>/If' incorporates:
       *  ActionPort: '<S57>/Action Port'
       *  ActionPort: '<S58>/Action Port'
       *  SubSystem: '<S17>/BigError S1'
       *  SubSystem: '<S17>/BigNegativeError S2'
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
          /* Disable for Outport: '<S57>/Out2' */
          brain_B.Constant1_e = 0.0;
          break;

         case 1:
          /* Disable for Outport: '<S58>/Out2' */
          brain_B.Constant1 = 0.0;
          break;
        }
      }

      switch (rtAction) {
       case 0:
        /* Sum: '<S57>/Add' incorporates:
         *  Constant: '<S57>/Constant'
         */
        brain_B.Add_o = rtb_Add1 - 360.0;

        /* Constant: '<S57>/Constant1' */
        brain_B.Constant1_e = 1.0;
        break;

       case 1:
        /* Sum: '<S58>/Add' incorporates:
         *  Constant: '<S58>/Constant'
         */
        brain_B.Add = rtb_Add1 + 360.0;

        /* Constant: '<S58>/Constant1' */
        brain_B.Constant1 = 2.0;
        break;
      }

      /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       *  Sum: '<S17>/Add2'
       */
      switch ((int32_T)((1.0 + brain_B.Constant1_e) + brain_B.Constant1)) {
       case 1:
        break;

       case 2:
        rtb_Add1 = brain_B.Add_o;
        break;

       default:
        rtb_Add1 = brain_B.Add;
        break;
      }

      /* SampleTimeMath: '<S60>/TSamp' incorporates:
       *  Gain: '<S59>/Heading Derivative Gain'
       *
       * About '<S60>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_j = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * 0.2);

      /* Sum: '<S59>/Sum' incorporates:
       *  DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator'
       *  Gain: '<S59>/Heading Proportional Gain'
       *  Sum: '<S60>/Diff'
       *  UnitDelay: '<S60>/UD'
       *
       * Block description for '<S60>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_j -
        brain_DWork.UD_DSTATE_p)) + brain_DWork.HeadingDiscreteTimeIntegrator_D;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S17>/Constant'
       */
      tmp = -rtb_Add4;
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(floor(tmp), 256.0);
      }

      /* Sum: '<S17>/Add4' */
      rtb_Add4 += brain_B.ForwardVelocity1;

      /* DataTypeConversion: '<S17>/DoubleToint1' incorporates:
       *  Sum: '<S17>/Add3'
       */
      tmp = floor((real_T)(int8_T)(tmp < 0.0 ? (int32_T)(int8_T)(-((int8_T)
        (uint8_T)(-tmp))) : (int32_T)(int8_T)(uint8_T)tmp) +
                  brain_B.ForwardVelocity1);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToint1 = (int8_T)tmp;
        } else {
          brain_B.DoubleToint1 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint1 = MAX_int8_T;
      }

      /* DataTypeConversion: '<S17>/DoubleToint8' */
      tmp = floor(rtb_Add4);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToint8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToint8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S60>/UD'
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_p = rtb_TSamp_j;

      /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
       *  Gain: '<S59>/Heading Integral Gain'
       */
      brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * (brain_P.Heading_Ki *
        rtb_Add1) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
      if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
      } else {
        if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
        }
      }

      brain_B.Left = brain_B.DoubleToint8;
      brain_B.Right = brain_B.DoubleToint1;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S16>/Add' */
      rtb_Add1 = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S56>/TSamp' incorporates:
       *  Gain: '<S55>/Depth Derivative Gain'
       *
       * About '<S56>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_j = brain_P.Depth_Kd * rtb_Add1 / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
       *  Gain: '<S55>/Depth Proportional Gain'
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
      tmp = floor((brain_P.Depth_Kp * rtb_Add1 + (rtb_TSamp_j -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST);
      if (tmp < 128.0) {
        if (tmp >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S56>/UD'
       * Block description for '<S56>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = rtb_TSamp_j;

      /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S55>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        rtb_Add1) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
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
    /* Transition: '<S7>:1236' */
    /* Entry 'BackupAndMoveUp': '<S7>:1239' */
    brain_DWork.is_GoAroundBuoy = brain_IN_BackupAndMoveUp;
    brain_DWork.Error = -3.0;
    brain_B.DesiredDepth = brain_U.CurrentDepth - 3.0;
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_Buoy(void)
{
  real_T eml_BlobCentroidX;
  real_T eml_BlobCentroidY;
  int32_T ku;
  int32_T i;
  int32_T n;
  int32_T i_0;
  int32_T idxAdj;
  int32_T n_0;
  int32_T outIdx;
  int32_T padCols;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW_l[10];
  uint32_T walkerIdx;
  uint32_T numBlobs;
  real_T rtb_Error_d;
  real_T rtb_TSamp_dm;
  real32_T xs;
  real32_T ys;
  real32_T xys;
  real32_T uyy;
  real32_T majorAxis;
  int8_T rtAction;
  int32_T rtb_BuoyBlobAnalysis_o1_j[10];
  real_T rtb_BuoyBlobAnalysis_o2_e[20];
  real32_T rtb_BlobAnalysis_o1[10];
  real32_T rtb_BlobAnalysis_o2[10];
  int32_T i_1;
  real32_T centroid_idx;
  real32_T centroid_idx_0;
  int8_T rtb_DataTypeConversion_0;
  real_T tmp;

  /* During 'Buoy': '<S7>:1220' */
  if (brain_DWork.OperationalState != 6) {
    /* Transition: '<S7>:1279' */
    switch (brain_DWork.is_Buoy) {
     case brain_IN_ApproachBuoy:
      /* Exit 'ApproachBuoy': '<S7>:1242' */
      brain_DWork.BuoyDone = 1.0;
      brain_DWork.is_Buoy = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     case brain_IN_FindBuoy:
      /* Exit 'FindBuoy': '<S7>:1224' */
      brain_DWork.is_Buoy = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
      break;

     default:
      brain_DWork.is_Buoy = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'BackupAndMoveUp': '<S7>:1239' */
      brain_DWork.is_GoAroundBuoy = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

      /* Exit 'FinishedwithBuoy': '<S7>:1241' */
      /* Exit 'MoveForward': '<S7>:1240' */
      /* Exit 'GoAroundBuoy': '<S7>:1235' */
      break;
    }

    /* Exit 'Buoy': '<S7>:1220' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    switch (brain_DWork.is_Buoy) {
     case brain_IN_ApproachBuoy:
      /* During 'ApproachBuoy': '<S7>:1242' */
      if (brain_DWork.countarea > 2.0) {
        /* Transition: '<S7>:1223' */
        /* Exit 'ApproachBuoy': '<S7>:1242' */
        brain_DWork.BuoyDone = 1.0;

        /* Entry 'GoAroundBuoy': '<S7>:1235' */
        brain_DWork.is_Buoy = brain_IN_GoAroundBuoy;

        /* Transition: '<S7>:1236' */
        /* Entry 'BackupAndMoveUp': '<S7>:1239' */
        brain_DWork.is_GoAroundBuoy = brain_IN_BackupAndMoveUp;
        brain_DWork.Error = -3.0;
        brain_B.DesiredDepth = brain_U.CurrentDepth - 3.0;
      } else {
        /* Simulink Function 'Buoy': '<S7>:1247' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.H[i_1] = brain_B.Resize[i_1];
          brain_B.S[i_1] = brain_B.Resize1[i_1];
        }

        brain_DWork.StateFlowFunctionsBuoyApproachB = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsBuoyApproac_l;
        brain_DWork.StateFlowFunctionsBuoyApproac_l = brain_M->Timing.clockTick0;

        /* Logic: '<S8>/Logical Operator1' incorporates:
         *  Constant: '<S20>/Constant'
         *  Constant: '<S21>/Constant'
         *  Constant: '<S22>/Constant'
         *  Logic: '<S8>/Logical Operator'
         *  RelationalOperator: '<S20>/Compare'
         *  RelationalOperator: '<S21>/Compare'
         *  RelationalOperator: '<S22>/Compare'
         */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BW_m[i_1] = (((brain_B.H[i_1] > brain_P.Buoy_HueHigher) ||
                                (brain_B.H[i_1] <= brain_P.Buoy_HueLower)) &&
                               (brain_B.S[i_1] >= brain_P.Buoy_Saturation));
        }

        /* S-Function (svipmorphop): '<S8>/Dilation' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 123; n++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
          memcpy((void *)&brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1], (void *)
                 &brain_B.BW_m[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
        }

        for (i = 161; i < 163; i++) {
          for (n = 0; n < 123; n++) {
            brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
            i_1++;
          }
        }

        i_1 = 0;
        ku = 0;
        for (n = 0; n < 160; n++) {
          for (outIdx = 0; outIdx < 120; outIdx++) {
            brain_B.Dilation_e[ku] = FALSE;
            for (i_0 = 0; i_0 < brain_DWork.Dilation_NUMNONZ_DW_m; i_0++) {
              if (brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1 +
                  brain_DWork.Dilation_DILATE_OFF_DW_h[i_0]]) {
                brain_B.Dilation_e[ku] = TRUE;
                i_0 = brain_DWork.Dilation_NUMNONZ_DW_m;
              }
            }

            i_1++;
            ku++;
          }

          i_1 += 3;
        }

        /* S-Function (svipmorphop): '<S8>/Erosion' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 127; n++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
          i_1++;
          memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1], (void *)
                 &brain_B.Dilation_e[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          for (n = 121; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
            i_1++;
          }
        }

        for (i = 161; i < 167; i++) {
          for (n = 0; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
            i_1++;
          }
        }

        for (i_0 = 0; i_0 < 21209; i_0++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_j[i_0] = TRUE;
        }

        ku = 0;
        for (n_0 = 0; n_0 < 167; n_0++) {
          for (padCols = 0; padCols < 124; padCols++) {
            brain_DWork.Erosion_TWO_PAD_IMG_DW_j[1 + ku] = TRUE;
            for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_e[0]; i_0++) {
              if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_i[ku +
                  brain_DWork.Erosion_ERODE_OFF_DW_p[i_0]]) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW_j[1 + ku] = FALSE;
                i_0 = brain_DWork.Erosion_NUMNONZ_DW_e[0];
              }
            }

            ku++;
          }

          ku += 3;
        }

        n = 1;
        outIdx = 0;
        for (n_0 = 0; n_0 < 160; n_0++) {
          for (padCols = 1; padCols < 121; padCols++) {
            brain_B.Erosion[outIdx] = TRUE;
            for (i_0 = 0; i_0 < brain_DWork.Erosion_NUMNONZ_DW_e[1]; i_0++) {
              if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_j[brain_DWork.Erosion_ERODE_OFF_DW_p
                  [i_0 + brain_DWork.Erosion_NUMNONZ_DW_e[0]] + n]) {
                brain_B.Erosion[outIdx] = FALSE;
                i_0 = brain_DWork.Erosion_NUMNONZ_DW_e[1];
              }
            }

            n++;
            outIdx++;
          }

          n += 7;
        }

        /* S-Function (svipblob): '<S8>/Buoy Blob Analysis' */
        maxNumBlobsReached = FALSE;
        for (i_1 = 0; i_1 < 123; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[i_1] = 0U;
        }

        currentLabel = 1U;
        i_1 = 0;
        n = 123;
        for (ku = 0; ku < 160; ku++) {
          for (i = 0; i < 120; i++) {
            brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = (uint8_T)
              (brain_B.Erosion[i_1] ? 255 : 0);
            i_1++;
            n++;
          }

          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = 0U;
          n++;
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = 0U;
          n++;
        }

        for (i_1 = 0; i_1 < 121; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[i_1 + n] = 0U;
        }

        ku = 1;
        stackIdx = 0U;
        pixIdx = 0U;
        for (i = 0; i < 160; i++) {
          n = 1;
          i_0 = ku * 122;
          for (outIdx = 0; outIdx < 120; outIdx++) {
            numBlobs = (uint32_T)(i_0 + n);
            start_pixIdx = pixIdx;
            if (brain_DWork.BuoyBlobAnalysis_PAD_DW_i[numBlobs] == 255) {
              brain_DWork.BuoyBlobAnalysis_PAD_DW_i[numBlobs] = currentLabel;
              brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[pixIdx] = (int16_T)(ku
                - 1);
              brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[pixIdx] = (int16_T)(n
                - 1);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] = 1U;
              brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx];
                for (idxAdj = 0; idxAdj < 8; idxAdj++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled16[idxAdj];
                  if (brain_DWork.BuoyBlobAnalysis_PAD_DW_i[walkerIdx] == 255) {
                    brain_DWork.BuoyBlobAnalysis_PAD_DW_i[walkerIdx] =
                      currentLabel;
                    brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[pixIdx] =
                      (int16_T)((int16_T)(walkerIdx / 122U) - 1);
                    brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[pixIdx] =
                      (int16_T)(walkerIdx % 122U - 1U);
                    pixIdx++;
                    BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1]++;
                    brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx] =
                      walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] <
                   brain_P.Min_Blob_Size) ||
                  (BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] >
                   brain_P.Max_Blob_Size)) {
                currentLabel--;
                pixIdx = start_pixIdx;
              }

              if (currentLabel == 10) {
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
        i_1 = 0;
        ku = 0;
        for (i = 0; i < (int32_T)numBlobs; i++) {
          rtb_BuoyBlobAnalysis_o1_j[i] = (int32_T)
            BuoyBlobAnalysis_NUM_PIX_DW_l[i];
          n = 0;
          outIdx = 0;
          for (i_0 = 0; i_0 < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[i]; i_0++)
          {
            n += brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[i_0 + ku];
            outIdx += brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[i_0 + i_1];
          }

          rtb_BuoyBlobAnalysis_o2_e[i << 1] = (real_T)outIdx / (real_T)
            BuoyBlobAnalysis_NUM_PIX_DW_l[i];
          rtb_BuoyBlobAnalysis_o2_e[(i << 1) + 1] = (real_T)n / (real_T)
            BuoyBlobAnalysis_NUM_PIX_DW_l[i];
          i_1 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[i];
          ku += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[i];
        }

        for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
          rtb_BuoyBlobAnalysis_o1_j[i_1] = -1;
        }

        for (i_1 = (int32_T)numBlobs << 1; i_1 < 20; i_1++) {
          rtb_BuoyBlobAnalysis_o2_e[i_1] = -1.0;
        }

        /* Embedded MATLAB: '<S8>/Embedded MATLAB Function' */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function': '<S23>:1' */
        /*  This function will choose and return data about the largest blob given a  */
        /*  set of blobs */
        if ((rtb_BuoyBlobAnalysis_o2_e[0] == -1.0) &&
            (rtb_BuoyBlobAnalysis_o2_e[1] == -1.0)) {
          /* '<S23>:1:5' */
          /* '<S23>:1:7' */
          eml_BlobCentroidX = 80.0;

          /* '<S23>:1:8' */
          eml_BlobCentroidY = 60.0;

          /* '<S23>:1:9' */
          brain_B.BlobArea = -1.0;
        } else {
          i_1 = rtb_BuoyBlobAnalysis_o1_j[0];
          ku = 1;
          i = 1;
          for (n = 2; n < 11; n++) {
            i++;
            if (rtb_BuoyBlobAnalysis_o1_j[i - 1] > i_1) {
              i_1 = rtb_BuoyBlobAnalysis_o1_j[i - 1];
              ku = n;
            }
          }

          /* '<S23>:1:11' */
          brain_B.BlobArea = (real_T)i_1;

          /* '<S23>:1:12' */
          eml_BlobCentroidX = rtb_BuoyBlobAnalysis_o2_e[((ku - 1) << 1) + 1];

          /* '<S23>:1:13' */
          eml_BlobCentroidY = rtb_BuoyBlobAnalysis_o2_e[(ku - 1) << 1];
        }

        brain_B.BlobCentroidX = eml_BlobCentroidX;
        brain_B.BlobCentroidY = eml_BlobCentroidY;

        /* Embedded MATLAB: '<S8>/Embedded MATLAB Function1' */
        brain_EmbeddedMATLABFunction1(&brain_B.sf_EmbeddedMATLABFunction1);

        /* Sum: '<S25>/Subtract' */
        eml_BlobCentroidX = brain_B.sf_EmbeddedMATLABFunction1.XCenter -
          brain_B.BlobCentroidX;

        /* SampleTimeMath: '<S28>/TSamp' incorporates:
         *  Gain: '<S27>/X-Buoy Derivative Gain'
         *
         * About '<S28>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        eml_BlobCentroidY = brain_P.Cam_Forward_XPosition_Kd * eml_BlobCentroidX
          / ((real_T)brain_DWork.StateFlowFunctionsBuoyApproachB * 0.2);

        /* DataTypeConversion: '<S25>/Data Type Conversion' incorporates:
         *  DiscreteIntegrator: '<S27>/X-Buoy Discrete-Time Integrator'
         *  Gain: '<S27>/X-Buoy Proportional Gain'
         *  Sum: '<S27>/Sum'
         *  Sum: '<S28>/Diff'
         *  UnitDelay: '<S28>/UD'
         *
         * Block description for '<S28>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S28>/UD':
         *
         *  Store in Global RAM
         */
        rtb_TSamp_dm = floor((brain_P.Cam_Forward_XPosition_Kp *
                              eml_BlobCentroidX + (eml_BlobCentroidY -
          brain_DWork.UD_DSTATE_f)) +
                             brain_DWork.XBuoyDiscreteTimeIntegrator_D_k);
        if (rtb_TSamp_dm < 128.0) {
          if (rtb_TSamp_dm >= -128.0) {
            rtb_DataTypeConversion_0 = (int8_T)rtb_TSamp_dm;
          } else {
            rtb_DataTypeConversion_0 = MIN_int8_T;
          }
        } else {
          rtb_DataTypeConversion_0 = MAX_int8_T;
        }

        /* Sum: '<S25>/Add' incorporates:
         *  Constant: '<S25>/Vision_Forward_Velocity'
         */
        brain_B.Add_h = brain_P.Vision_Forward_Velocity + (real_T)
          rtb_DataTypeConversion_0;

        /* Sum: '<S25>/Add1' incorporates:
         *  Constant: '<S25>/Constant'
         *  Constant: '<S25>/Vision_Forward_Velocity2'
         *  Product: '<S25>/Multiply'
         */
        brain_B.Add1 = (real_T)rtb_DataTypeConversion_0 * -1.0 +
          brain_P.Vision_Forward_Velocity;

        /* Sum: '<S26>/Subtract' */
        rtb_Error_d = brain_B.BlobCentroidY -
          brain_B.sf_EmbeddedMATLABFunction1.YCenter;

        /* SampleTimeMath: '<S30>/TSamp' incorporates:
         *  Gain: '<S29>/Y-Buoy Derivative Gain'
         *
         * About '<S30>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        rtb_TSamp_dm = brain_P.Cam_Forward_YPosition_Kd * rtb_Error_d / ((real_T)
          brain_DWork.StateFlowFunctionsBuoyApproachB * 0.2);

        /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
         *  DiscreteIntegrator: '<S29>/Y-Buoy Discrete-Time Integrator'
         *  Gain: '<S29>/Y-Buoy Proportional Gain'
         *  Sum: '<S29>/Sum'
         *  Sum: '<S30>/Diff'
         *  UnitDelay: '<S30>/UD'
         *
         * Block description for '<S30>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S30>/UD':
         *
         *  Store in Global RAM
         */
        tmp = floor((brain_P.Cam_Forward_YPosition_Kp * rtb_Error_d +
                     (rtb_TSamp_dm - brain_DWork.UD_DSTATE_m)) +
                    brain_DWork.YBuoyDiscreteTimeIntegrator_D_a);
        if (tmp < 128.0) {
          if (tmp >= -128.0) {
            brain_B.DataTypeConversion_e = (int8_T)tmp;
          } else {
            brain_B.DataTypeConversion_e = MIN_int8_T;
          }
        } else {
          brain_B.DataTypeConversion_e = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S28>/UD'
         * Block description for '<S28>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE_f = eml_BlobCentroidY;

        /* Update for DiscreteIntegrator: '<S27>/X-Buoy Discrete-Time Integrator' incorporates:
         *  Gain: '<S27>/X-Buoy Integral Gain'
         */
        brain_DWork.XBuoyDiscreteTimeIntegrator_D_k = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsBuoyApproachB *
          (brain_P.Cam_Forward_XPosition_Ki * eml_BlobCentroidX) +
          brain_DWork.XBuoyDiscreteTimeIntegrator_D_k;
        if (brain_DWork.XBuoyDiscreteTimeIntegrator_D_k >= 15.0) {
          brain_DWork.XBuoyDiscreteTimeIntegrator_D_k = 15.0;
        } else {
          if (brain_DWork.XBuoyDiscreteTimeIntegrator_D_k <= -15.0) {
            brain_DWork.XBuoyDiscreteTimeIntegrator_D_k = -15.0;
          }
        }

        /* Update for UnitDelay: '<S30>/UD'
         * Block description for '<S30>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE_m = rtb_TSamp_dm;

        /* Update for DiscreteIntegrator: '<S29>/Y-Buoy Discrete-Time Integrator' incorporates:
         *  Gain: '<S29>/Y-Buoy Integral Gain'
         */
        brain_DWork.YBuoyDiscreteTimeIntegrator_D_a = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsBuoyApproachB *
          (brain_P.Cam_Forward_YPosition_Ki * rtb_Error_d) +
          brain_DWork.YBuoyDiscreteTimeIntegrator_D_a;
        if (brain_DWork.YBuoyDiscreteTimeIntegrator_D_a >= 15.0) {
          brain_DWork.YBuoyDiscreteTimeIntegrator_D_a = 15.0;
        } else {
          if (brain_DWork.YBuoyDiscreteTimeIntegrator_D_a <= -15.0) {
            brain_DWork.YBuoyDiscreteTimeIntegrator_D_a = -15.0;
          }
        }

        brain_B.Right = (int8_T)brain_B.Add_h;
        brain_B.Left = (int8_T)brain_B.Add1;
        brain_B.Vertical = brain_B.DataTypeConversion_e;
        brain_B.BuoyCentroidX = brain_B.BlobCentroidY;
        brain_B.BuoyCentroidY = brain_B.BlobCentroidX;
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BWout[i_1] = (real_T)brain_B.Erosion[i_1];
        }

        brain_DWork.countarea = brain_countareas((real_T)(int32_T)
          brain_B.BlobArea, brain_DWork.countarea);
      }
      break;

     case brain_IN_FindBuoy:
      /* During 'FindBuoy': '<S7>:1224' */
      if (brain_DWork.BuoyCount > 2.0) {
        /* Transition: '<S7>:1222' */
        /* Exit 'FindBuoy': '<S7>:1224' */
        /* Entry 'ApproachBuoy': '<S7>:1242' */
        brain_DWork.is_Buoy = brain_IN_ApproachBuoy;
        brain_DWork.countarea = 0.0;
      } else {
        /* Simulink Function 'LookforBuoy': '<S7>:1230' */
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.H_k[i_1] = brain_B.Resize[i_1];
          brain_B.S_o[i_1] = brain_B.Resize1[i_1];

          /* Logic: '<S31>/Logical Operator1' incorporates:
           *  Constant: '<S32>/Constant'
           *  Constant: '<S33>/Constant'
           *  Constant: '<S35>/Constant'
           *  Logic: '<S31>/Logical Operator'
           *  RelationalOperator: '<S32>/Compare'
           *  RelationalOperator: '<S33>/Compare'
           *  RelationalOperator: '<S35>/Compare'
           */
          brain_B.BW_g[i_1] = (((brain_B.H_k[i_1] < brain_P.Buoy_HueLower) ||
                                (brain_B.H_k[i_1] > brain_P.Buoy_HueHigher)) &&
                               (brain_B.S_o[i_1] > brain_P.Buoy_Saturation));
        }

        /* S-Function (svipmorphop): '<S31>/Dilation' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 123; n++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
          memcpy((void *)&brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1], (void *)
                 &brain_B.BW_g[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
          brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
          i_1++;
        }

        for (i = 161; i < 163; i++) {
          for (n = 0; n < 123; n++) {
            brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1] = FALSE;
            i_1++;
          }
        }

        i_1 = 0;
        ku = 0;
        for (n = 0; n < 160; n++) {
          for (outIdx = 0; outIdx < 120; outIdx++) {
            brain_B.Dilation[ku] = FALSE;
            for (i_0 = 0; i_0 < brain_DWork.Dilation_NUMNONZ_DW; i_0++) {
              if (brain_DWork.Dilation_ONE_PAD_IMG_DW_n[i_1 +
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

        /* S-Function (svipmorphop): '<S31>/Erosion' */
        i_1 = 0;
        ku = 0;
        for (n = 0; n < 127; n++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
          i_1++;
        }

        for (i = 0; i < 160; i++) {
          brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
          i_1++;
          memcpy((void *)&brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1], (void *)
                 &brain_B.Dilation[ku], 120U * sizeof(boolean_T));
          i_1 += 120;
          ku += 120;
          for (n = 121; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
            i_1++;
          }
        }

        for (i = 161; i < 167; i++) {
          for (n = 0; n < 127; n++) {
            brain_DWork.Erosion_ONE_PAD_IMG_DW_i[i_1] = TRUE;
            i_1++;
          }
        }

        for (outIdx = 0; outIdx < 21209; outIdx++) {
          brain_DWork.Erosion_TWO_PAD_IMG_DW_j[outIdx] = TRUE;
        }

        ku = 0;
        for (n_0 = 0; n_0 < 167; n_0++) {
          for (padCols = 0; padCols < 124; padCols++) {
            brain_DWork.Erosion_TWO_PAD_IMG_DW_j[1 + ku] = TRUE;
            for (outIdx = 0; outIdx < brain_DWork.Erosion_NUMNONZ_DW[0]; outIdx
                 ++) {
              if (!brain_DWork.Erosion_ONE_PAD_IMG_DW_i[ku +
                  brain_DWork.Erosion_ERODE_OFF_DW[outIdx]]) {
                brain_DWork.Erosion_TWO_PAD_IMG_DW_j[1 + ku] = FALSE;
                outIdx = brain_DWork.Erosion_NUMNONZ_DW[0];
              }
            }

            ku++;
          }

          ku += 3;
        }

        n = 1;
        i_0 = 0;
        for (n_0 = 0; n_0 < 160; n_0++) {
          for (padCols = 1; padCols < 121; padCols++) {
            brain_B.Erosion_l[i_0] = TRUE;
            for (outIdx = 0; outIdx < brain_DWork.Erosion_NUMNONZ_DW[1]; outIdx
                 ++) {
              if (!brain_DWork.Erosion_TWO_PAD_IMG_DW_j[brain_DWork.Erosion_ERODE_OFF_DW
                  [outIdx + brain_DWork.Erosion_NUMNONZ_DW[0]] + n]) {
                brain_B.Erosion_l[i_0] = FALSE;
                outIdx = brain_DWork.Erosion_NUMNONZ_DW[1];
              }
            }

            n++;
            i_0++;
          }

          n += 7;
        }

        /* S-Function (svipblob): '<S31>/Blob Analysis' */
        maxNumBlobsReached = FALSE;
        for (i_1 = 0; i_1 < 123; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[i_1] = 0U;
        }

        currentLabel = 1U;
        i_1 = 0;
        n = 123;
        for (ku = 0; ku < 160; ku++) {
          for (i = 0; i < 120; i++) {
            brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = (uint8_T)
              (brain_B.Erosion_l[i_1] ? 255 : 0);
            i_1++;
            n++;
          }

          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = 0U;
          n++;
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[n] = 0U;
          n++;
        }

        for (i_1 = 0; i_1 < 121; i_1++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW_i[i_1 + n] = 0U;
        }

        ku = 1;
        stackIdx = 0U;
        pixIdx = 0U;
        for (i = 0; i < 160; i++) {
          n = 1;
          i_0 = ku * 122;
          for (outIdx = 0; outIdx < 120; outIdx++) {
            numBlobs = (uint32_T)(i_0 + n);
            start_pixIdx = pixIdx;
            if (brain_DWork.BuoyBlobAnalysis_PAD_DW_i[numBlobs] == 255) {
              brain_DWork.BuoyBlobAnalysis_PAD_DW_i[numBlobs] = currentLabel;
              brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[pixIdx] = (int16_T)(ku
                - 1);
              brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[pixIdx] = (int16_T)(n
                - 1);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] = 1U;
              brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx] = numBlobs;
              stackIdx++;
              while (stackIdx) {
                stackIdx--;
                numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx];
                for (idxAdj = 0; idxAdj < 8; idxAdj++) {
                  walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled16[idxAdj];
                  if (brain_DWork.BuoyBlobAnalysis_PAD_DW_i[walkerIdx] == 255) {
                    brain_DWork.BuoyBlobAnalysis_PAD_DW_i[walkerIdx] =
                      currentLabel;
                    brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[pixIdx] =
                      (int16_T)((int16_T)(walkerIdx / 122U) - 1);
                    brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[pixIdx] =
                      (int16_T)(walkerIdx % 122U - 1U);
                    pixIdx++;
                    BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1]++;
                    brain_DWork.BuoyBlobAnalysis_STACK_DW_o[stackIdx] =
                      walkerIdx;
                    stackIdx++;
                  }
                }
              }

              if ((BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] <
                   brain_P.Min_Blob_Size) ||
                  (BuoyBlobAnalysis_NUM_PIX_DW_l[currentLabel - 1] >
                   brain_P.Max_Blob_Size)) {
                currentLabel--;
                pixIdx = start_pixIdx;
              }

              if (currentLabel == 10) {
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
        outIdx = 0;
        idxAdj = 0;
        for (n_0 = 0; n_0 < (int32_T)numBlobs; n_0++) {
          i_1 = 0;
          ku = 0;
          for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
               padCols++) {
            i_1 += brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[padCols + idxAdj];
            ku += brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[padCols + outIdx];
          }

          centroid_idx = (real32_T)ku / (real32_T)
            BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
          centroid_idx_0 = (real32_T)i_1 / (real32_T)
            BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
          ku = 160;
          i = 120;
          n = 0;
          i_0 = 0;
          for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
               padCols++) {
            i_1 = padCols + idxAdj;
            if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[i_1] < ku) {
              ku = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[i_1];
            }

            if (brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[i_1] > n) {
              n = brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[i_1];
            }

            i_1 = padCols + outIdx;
            if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[i_1] < i) {
              i = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[i_1];
            }

            if (brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[i_1] > i_0) {
              i_0 = brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[i_1];
            }
          }

          xs = 0.0F;
          ys = 0.0F;
          xys = 0.0F;
          for (walkerIdx = 0U; walkerIdx < (uint32_T)(int32_T)
               BuoyBlobAnalysis_NUM_PIX_DW_l[n_0]; walkerIdx++) {
            majorAxis = (real32_T)
              brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW_g[idxAdj + walkerIdx] -
              centroid_idx_0;
            uyy = (real32_T)brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW_n[outIdx +
              walkerIdx] - centroid_idx;
            xs += majorAxis * majorAxis;
            ys += uyy * uyy;
            xys += majorAxis * (-uyy);
          }

          centroid_idx = xs / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0] +
            8.333333582E-02F;
          uyy = ys / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0] +
            8.333333582E-02F;
          xs = xys / (real32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
          xs = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx - uyy) + xs *
                              xs * 4.0F);
          majorAxis = ((centroid_idx + uyy) + xs) * 8.0F;
          rtb_BlobAnalysis_o1[n_0] = (real32_T)sqrt(majorAxis - ((centroid_idx +
            uyy) - xs) * 8.0F) / (real32_T)sqrt(majorAxis);
          rtb_BlobAnalysis_o2[n_0] = (real32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0]
            / (real32_T)(((i_0 + 1) - i) * ((n + 1) - ku));
          outIdx += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
          idxAdj += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW_l[n_0];
        }

        for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
          rtb_BlobAnalysis_o1[i_1] = -1.0F;
        }

        for (i_1 = (int32_T)numBlobs; i_1 < 10; i_1++) {
          rtb_BlobAnalysis_o2[i_1] = -1.0F;
        }

        /* Embedded MATLAB: '<S31>/IF Buoy Conditions' incorporates:
         *  Constant: '<S31>/Constant'
         *  Constant: '<S31>/Constant1'
         *  Constant: '<S31>/Constant2'
         *  Constant: '<S31>/Constant3'
         */
        /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions': '<S34>:1' */
        /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
        /*  if there is a buoy present in the current image */
        /* '<S34>:1:6' */
        brain_B.Image = 0.0;

        /* '<S34>:1:8' */
        for (i_1 = 0; i_1 < 10; i_1++) {
          /* '<S34>:1:8' */
          if (((real_T)rtb_BlobAnalysis_o1[i_1] > brain_P.Buoy_Min_Eccentricity)
              && ((real_T)rtb_BlobAnalysis_o1[i_1] <
                  brain_P.Buoy_Max_Eccentricity) && ((real_T)
               rtb_BlobAnalysis_o2[i_1] > brain_P.Buoy_Min_Extent) && ((real_T)
               rtb_BlobAnalysis_o2[i_1] < brain_P.Buoy_Max_Extent)) {
            /* '<S34>:1:9' */
            /* '<S34>:1:10' */
            brain_B.Image = 1.0;
          }
        }

        maxNumBlobsReached = (brain_B.Image != 0.0);
        for (i_1 = 0; i_1 < 19200; i_1++) {
          brain_B.BWout[i_1] = (real_T)brain_B.BW_g[i_1];
        }

        brain_DWork.BuoyCount = brain_countimages((real_T)maxNumBlobsReached,
          (real_T)brain_DWork.OldObstacle, brain_DWork.BuoyCount);

        /* Simulink Function 'GetBuoyForwardVelocity': '<S7>:1257' */

        /* Constant: '<S10>/Constant' */
        brain_B.Constant_i = brain_P.Heading_Forward_Velocity;

        /* Simulink Function 'MaintainHeading': '<S7>:918' */
        brain_B.DesiredHeading1 = brain_B.DesiredHeading;
        brain_B.CurrentHeading1 = brain_U.CurrentHeading;
        brain_B.ForwardVelocity1 = brain_B.Constant_i;
        brain_DWork.StateFlowFunctionsMaintainHeadi = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainHea_m;
        brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

        /* Sum: '<S17>/Add1' */
        eml_BlobCentroidX = brain_B.DesiredHeading1 - brain_B.CurrentHeading1;

        /* If: '<S17>/If' incorporates:
         *  ActionPort: '<S57>/Action Port'
         *  ActionPort: '<S58>/Action Port'
         *  SubSystem: '<S17>/BigError S1'
         *  SubSystem: '<S17>/BigNegativeError S2'
         */
        rtb_DataTypeConversion_0 = brain_DWork.If_ActiveSubsystem;
        rtAction = -1;
        if (eml_BlobCentroidX > 180.0) {
          rtAction = 0;
        } else {
          if (eml_BlobCentroidX < -180.0) {
            rtAction = 1;
          }
        }

        brain_DWork.If_ActiveSubsystem = rtAction;
        if (rtb_DataTypeConversion_0 != rtAction) {
          switch (rtb_DataTypeConversion_0) {
           case 0:
            /* Disable for Outport: '<S57>/Out2' */
            brain_B.Constant1_e = 0.0;
            break;

           case 1:
            /* Disable for Outport: '<S58>/Out2' */
            brain_B.Constant1 = 0.0;
            break;
          }
        }

        switch (rtAction) {
         case 0:
          /* Sum: '<S57>/Add' incorporates:
           *  Constant: '<S57>/Constant'
           */
          brain_B.Add_o = eml_BlobCentroidX - 360.0;

          /* Constant: '<S57>/Constant1' */
          brain_B.Constant1_e = 1.0;
          break;

         case 1:
          /* Sum: '<S58>/Add' incorporates:
           *  Constant: '<S58>/Constant'
           */
          brain_B.Add = eml_BlobCentroidX + 360.0;

          /* Constant: '<S58>/Constant1' */
          brain_B.Constant1 = 2.0;
          break;
        }

        /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
         *  Constant: '<S17>/Constant1'
         *  Sum: '<S17>/Add2'
         */
        switch ((int32_T)((1.0 + brain_B.Constant1_e) + brain_B.Constant1)) {
         case 1:
          break;

         case 2:
          eml_BlobCentroidX = brain_B.Add_o;
          break;

         default:
          eml_BlobCentroidX = brain_B.Add;
          break;
        }

        /* SampleTimeMath: '<S60>/TSamp' incorporates:
         *  Gain: '<S59>/Heading Derivative Gain'
         *
         * About '<S60>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        eml_BlobCentroidY = brain_P.Heading_Kd * eml_BlobCentroidX / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainHeadi * 0.2);

        /* Sum: '<S59>/Sum' incorporates:
         *  DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator'
         *  Gain: '<S59>/Heading Proportional Gain'
         *  Sum: '<S60>/Diff'
         *  UnitDelay: '<S60>/UD'
         *
         * Block description for '<S60>/Diff':
         *
         *  Add in CPU
         *
         * Block description for '<S60>/UD':
         *
         *  Store in Global RAM
         */
        rtb_Error_d = (brain_P.Heading_Kp * eml_BlobCentroidX +
                       (eml_BlobCentroidY - brain_DWork.UD_DSTATE_p)) +
          brain_DWork.HeadingDiscreteTimeIntegrator_D;

        /* Product: '<S17>/Multiply' incorporates:
         *  Constant: '<S17>/Constant'
         */
        rtb_TSamp_dm = -rtb_Error_d;
        if (rtIsNaN(rtb_TSamp_dm) || rtIsInf(rtb_TSamp_dm)) {
          rtb_TSamp_dm = 0.0;
        } else {
          rtb_TSamp_dm = fmod(floor(rtb_TSamp_dm), 256.0);
        }

        /* Sum: '<S17>/Add4' */
        rtb_Error_d += brain_B.ForwardVelocity1;

        /* DataTypeConversion: '<S17>/DoubleToint1' incorporates:
         *  Sum: '<S17>/Add3'
         */
        rtb_TSamp_dm = floor((real_T)(int8_T)(rtb_TSamp_dm < 0.0 ? (int32_T)
          (int8_T)(-((int8_T)(uint8_T)(-rtb_TSamp_dm))) : (int32_T)(int8_T)
          (uint8_T)rtb_TSamp_dm) + brain_B.ForwardVelocity1);
        if (rtb_TSamp_dm < 128.0) {
          if (rtb_TSamp_dm >= -128.0) {
            brain_B.DoubleToint1 = (int8_T)rtb_TSamp_dm;
          } else {
            brain_B.DoubleToint1 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToint1 = MAX_int8_T;
        }

        /* DataTypeConversion: '<S17>/DoubleToint8' */
        rtb_TSamp_dm = floor(rtb_Error_d);
        if (rtb_TSamp_dm < 128.0) {
          if (rtb_TSamp_dm >= -128.0) {
            brain_B.DoubleToint8 = (int8_T)rtb_TSamp_dm;
          } else {
            brain_B.DoubleToint8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToint8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S60>/UD'
         * Block description for '<S60>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE_p = eml_BlobCentroidY;

        /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
         *  Gain: '<S59>/Heading Integral Gain'
         */
        brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainHeadi * (brain_P.Heading_Ki *
          eml_BlobCentroidX) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
        if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
        } else {
          if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
            brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
          }
        }

        brain_B.Left = brain_B.DoubleToint8;
        brain_B.Right = brain_B.DoubleToint1;

        /* Simulink Function 'MaintainDepth': '<S7>:926' */
        brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
        brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
        brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0
          - brain_DWork.StateFlowFunctionsMaintainDep_k;
        brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

        /* Sum: '<S16>/Add' */
        eml_BlobCentroidX = (real_T)brain_B.DesiredDepth1 - (real_T)
          brain_B.CurrentDepth1;

        /* SampleTimeMath: '<S56>/TSamp' incorporates:
         *  Gain: '<S55>/Depth Derivative Gain'
         *
         * About '<S56>/TSamp':
         *  y = u * K where K = 1 / ( w * Ts )
         */
        eml_BlobCentroidY = brain_P.Depth_Kd * eml_BlobCentroidX / ((real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

        /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
         *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
         *  Gain: '<S55>/Depth Proportional Gain'
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
        rtb_TSamp_dm = floor((brain_P.Depth_Kp * eml_BlobCentroidX +
                              (eml_BlobCentroidY - brain_DWork.UD_DSTATE)) +
                             brain_DWork.DepthDiscreteTimeIntegrator_DST);
        if (rtb_TSamp_dm < 128.0) {
          if (rtb_TSamp_dm >= -128.0) {
            brain_B.DoubleToInt8 = (int8_T)rtb_TSamp_dm;
          } else {
            brain_B.DoubleToInt8 = MIN_int8_T;
          }
        } else {
          brain_B.DoubleToInt8 = MAX_int8_T;
        }

        /* Update for UnitDelay: '<S56>/UD'
         * Block description for '<S56>/UD':
         *
         *  Store in Global RAM
         */
        brain_DWork.UD_DSTATE = eml_BlobCentroidY;

        /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
         *  Gain: '<S55>/Depth Integral Gain'
         */
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
          brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
          eml_BlobCentroidX) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
        } else {
          if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
            brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
          }
        }

        brain_B.Vertical = brain_B.DoubleToInt8;
        brain_DWork.OldObstacle = maxNumBlobsReached;
      }
      break;

     case brain_IN_GoAroundBuoy:
      brain_GoAroundBuoy();
      break;

     default:
      brain_enter_internal_Buoy();
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_OnePath(void)
{
  /* Transition: '<S7>:1170' */
  /* Entry 'GetDirections': '<S7>:1185' */
  brain_DWork.is_OnePath = brain_IN_GetDirections;
  brain_DWork.countTo = 0.0;
  brain_DWork.countAlong = 0.0;
  brain_DWork.outliersTo = 0.0;
  brain_DWork.outliersAlong = 0.0;
  brain_B.Left = 0;
  brain_B.Right = 0;
}

/* Function for Embedded MATLAB: '<S48>/Get Brightest Pixel Per Column and Row' */
static void brain_refp1_cos(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S48>/Get Brightest Pixel Per Column and Row' */
static void brain_max_lrq(const real_T eml_varargin_1[80], real_T *eml_maxval,
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
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 81)) {
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
    for (eml_k = eml_itmp + 1; eml_k < 81; eml_k++) {
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

/* Function for Embedded MATLAB: '<S48>/Get Brightest Pixel Per Column and Row' */
static void brain_max_lr(const real_T eml_varargin_1[120], real_T *eml_maxval,
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
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 121)) {
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
    for (eml_k = eml_itmp + 1; eml_k < 121; eml_k++) {
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

/* Function for Embedded MATLAB: '<S48>/Get Brightest Pixel Per Column and Row' */
static void brain_c9_brain(void)
{
  real_T eml_SaturationThreshold;
  real_T eml_indexH;
  int32_T eml_x;
  real_T eml_c_y;
  real_T eml_hoistedExpr[80];
  real_T eml_hoistedExpr_0[80];
  int32_T tmp;
  eml_SaturationThreshold = brain_P.Track_Saturation;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row': '<S49>:1' */
  /*  This function takes a HSV image as input and determines the  */
  /*  highest intensity pixel in each row and column. From these highest */
  /*  intensity pixels a new boolean image is created and reported */
  /* '<S49>:1:8' */
  /* '<S49>:1:10' */
  /* '<S49>:1:11' */
  for (tmp = 0; tmp < 9600; tmp++) {
    brain_B.eml_BWleft[tmp] = 0;
    brain_B.eml_BWright[tmp] = 0;
  }

  /* '<S49>:1:13' */
  eml_c_y = 6.2831853071795862E+00 * brain_B.DesiredH1;
  for (tmp = 0; tmp < 160; tmp++) {
    for (eml_x = 0; eml_x < 120; eml_x++) {
      brain_B.eml_hoistedExpr[eml_x + 120 * tmp] = brain_B.HSV1[120 * tmp +
        eml_x] * 6.2831853071795862E+00 - eml_c_y;
    }
  }

  brain_refp1_cos(&brain_B.eml_hoistedExpr[0]);
  for (tmp = 0; tmp < 19200; tmp++) {
    brain_B.eml_hoistedExpr[tmp] = (brain_B.eml_hoistedExpr[tmp] + 1.0) / 2.0;
  }

  /*  Left half */
  /* '<S49>:1:16' */
  for (eml_x = 0; eml_x < 80; eml_x++) {
    /* '<S49>:1:16' */
    brain_max_lr(*((real_T (*)[120])&brain_B.eml_hoistedExpr[120 * eml_x]),
                 &eml_c_y, &eml_indexH);
    if ((eml_c_y > 0.5) && (brain_B.HSV1[(((int32_T)eml_indexH - 1) + 120 *
          eml_x) + 19200] > eml_SaturationThreshold)) {
      /* '<S49>:1:18' */
      /* '<S49>:1:19' */
      brain_B.eml_BWleft[((int32_T)eml_indexH - 1) + 120 * eml_x] = 1;
    }
  }

  /* '<S49>:1:23' */
  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S49>:1:23' */
    for (tmp = 0; tmp < 80; tmp++) {
      eml_hoistedExpr[tmp] = brain_B.eml_hoistedExpr[120 * tmp + eml_x];
    }

    brain_max_lrq(eml_hoistedExpr, &eml_c_y, &eml_indexH);
    if ((eml_c_y > 0.5) && (brain_B.HSV1[(((int32_T)eml_indexH - 1) * 120 +
          eml_x) + 19200] > eml_SaturationThreshold)) {
      /* '<S49>:1:25' */
      /* '<S49>:1:26' */
      brain_B.eml_BWleft[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  /*  Right half */
  /* '<S49>:1:31' */
  for (eml_x = 81; eml_x < 161; eml_x++) {
    /* '<S49>:1:31' */
    brain_max_lr(*((real_T (*)[120])&brain_B.eml_hoistedExpr[120 * (eml_x - 1)]),
                 &eml_c_y, &eml_indexH);
    if ((eml_c_y > 0.5) && (brain_B.HSV1[((eml_x - 1) * 120 + ((int32_T)
           eml_indexH - 1)) + 19200] > eml_SaturationThreshold)) {
      /* '<S49>:1:33' */
      /* '<S49>:1:34' */
      brain_B.eml_BWright[((int32_T)eml_indexH - 1) + 120 * (eml_x - 81)] = 1;
    }
  }

  /* '<S49>:1:38' */
  for (eml_x = 0; eml_x < 120; eml_x++) {
    /* '<S49>:1:38' */
    for (tmp = 0; tmp < 80; tmp++) {
      eml_hoistedExpr_0[tmp] = brain_B.eml_hoistedExpr[(80 + tmp) * 120 + eml_x];
    }

    brain_max_lrq(eml_hoistedExpr_0, &eml_c_y, &eml_indexH);
    if ((eml_c_y > 0.5) && (brain_B.HSV1[(((int32_T)eml_indexH - 1) * 120 +
          eml_x) + 19200] > eml_SaturationThreshold)) {
      /* '<S49>:1:40' */
      /* '<S49>:1:41' */
      brain_B.eml_BWright[eml_x + 120 * ((int32_T)eml_indexH - 1)] = 1;
    }
  }

  for (tmp = 0; tmp < 9600; tmp++) {
    brain_B.BWleft[tmp] = (real_T)brain_B.eml_BWleft[tmp];
    brain_B.BWright[tmp] = (real_T)brain_B.eml_BWright[tmp];
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_CombineBWs(const real_T sf_BWleft1[9600], const real_T
  sf_BWright1[9600], real_T sf_BWout1[19200])
{
  int32_T sf_i;
  int32_T sf_j;

  /* Embedded MATLAB Function 'CombineBWs': '<S7>:1204' */
  /*  Combine the left and right portions of the processed image into a single */
  /*  image to be sent to the dashboard */
  /* '<S7>:1204:5' */
  /* '<S7>:1204:6' */
  memset((void *)&sf_BWout1[0], (int32_T)0.0, 19200U * sizeof(real_T));

  /* '<S7>:1204:8' */
  for (sf_i = 0; sf_i < 120; sf_i++) {
    /* '<S7>:1204:8' */
    /* '<S7>:1204:9' */
    for (sf_j = 0; sf_j < 80; sf_j++) {
      /* '<S7>:1204:9' */
      /* '<S7>:1204:10' */
      sf_BWout1[sf_i + 120 * sf_j] = sf_BWleft1[120 * sf_j + sf_i];

      /* '<S7>:1204:11' */
      sf_BWout1[sf_i + 120 * (sf_j + 80)] = sf_BWright1[120 * sf_j + sf_i];
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_GetAvgDesHeading(const real_T sf_DesiredHeading1[2], const
  real_T sf_AvgDHeading[2], real_T sf_CountIn, real_T sf_OutliersIN, real_T
  sf_AvgDesHeading[2], real_T *sf_CountOut, real_T *sf_OutliersOUT)
{
  /* Embedded MATLAB Function 'GetAvgDesHeading': '<S7>:1196' */
  /*  This function calculates the average desired heading determined by the */
  /*  path software */
  /* '<S7>:1196:7' */
  sf_AvgDesHeading[0] = 0.0;
  sf_AvgDesHeading[1] = 0.0;

  /* '<S7>:1196:8' */
  *sf_OutliersOUT = sf_OutliersIN;
  if ((sf_CountIn == 0.0) && (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S7>:1196:10' */
    /* '<S7>:1196:11' */
    sf_AvgDesHeading[0] = sf_DesiredHeading1[0];
    sf_AvgDesHeading[1] = sf_DesiredHeading1[1];

    /* '<S7>:1196:12' */
    *sf_CountOut = 1.0;
  } else if ((fabs(sf_DesiredHeading1[0] - sf_AvgDHeading[0]) < 5.0) &&
             (sf_DesiredHeading1[0] != -999.0)) {
    /* '<S7>:1196:13' */
    /* '<S7>:1196:14' */
    *sf_CountOut = sf_CountIn + 1.0;

    /* '<S7>:1196:15' */
    sf_AvgDesHeading[0] = (sf_CountIn * sf_AvgDHeading[0] + sf_DesiredHeading1[0])
      / *sf_CountOut;
  } else {
    /* '<S7>:1196:17' */
    *sf_OutliersOUT = sf_OutliersIN + 1.0;

    /* '<S7>:1196:18' */
    sf_AvgDesHeading[0] = sf_AvgDHeading[0];

    /* '<S7>:1196:19' */
    *sf_CountOut = sf_CountIn;
  }

  if (sf_AvgDHeading[1] != -999.0) {
    /* '<S7>:1196:24' */
    if ((fabs(sf_DesiredHeading1[1] - sf_AvgDHeading[1]) < 5.0) &&
        (sf_DesiredHeading1[1] != -999.0)) {
      /* '<S7>:1196:25' */
      /* '<S7>:1196:26' */
      sf_AvgDesHeading[1] = (sf_CountIn * sf_AvgDHeading[1] +
        sf_DesiredHeading1[1]) / *sf_CountOut;
    } else {
      /* '<S7>:1196:28' */
      sf_AvgDesHeading[1] = sf_AvgDHeading[1];
    }

    if (*sf_OutliersOUT > 5.0) {
      /* '<S7>:1196:31' */
      /* '<S7>:1196:32' */
      sf_AvgDesHeading[1] = 0.0;
    }
  }

  if (*sf_OutliersOUT > 5.0) {
    /* '<S7>:1196:38' */
    /* '<S7>:1196:39' */
    sf_AvgDesHeading[0] = 0.0;
    sf_AvgDesHeading[1] = 0.0;

    /* '<S7>:1196:40' */
    *sf_CountOut = 0.0;

    /* '<S7>:1196:41' */
    *sf_OutliersOUT = 0.0;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ChoosePath(const real_T sf_AvgDesHeadingToPath[2], const
  real_T sf_AvgDesHeadingAlongPath[2], real_T *sf_Desired_HeadingTo, real_T
  *sf_Desired_HeadingAlong)
{
  real_T sf_DeltaTheta;
  int32_T sf_RightPathIndex;

  /* Embedded MATLAB Function 'ChoosePath': '<S7>:1191' */
  /*  This function will determine which of the two found paths are pointing */
  /*  right and which is pointing left. This function will then return the  */
  /*  headings associated with the path to the right (There should only be one */
  /*  path and therefore that one will be returned) */
  if (sf_AvgDesHeadingAlongPath[1] != -999.0) {
    /* '<S7>:1191:15' */
    /* '<S7>:1191:16' */
    sf_DeltaTheta = sf_AvgDesHeadingAlongPath[1] - sf_AvgDesHeadingAlongPath[0];
    if (sf_DeltaTheta > 180.0) {
      /* '<S7>:1191:18' */
      /* '<S7>:1191:19' */
      sf_DeltaTheta -= 360.0;
    } else {
      if (sf_DeltaTheta < -180.0) {
        /* '<S7>:1191:20' */
        /* '<S7>:1191:21' */
        sf_DeltaTheta += 360.0;
      }
    }

    if (sf_DeltaTheta > 0.0) {
      /* '<S7>:1191:24' */
      /* '<S7>:1191:25' */
      sf_RightPathIndex = 2;
    } else {
      /* '<S7>:1191:29' */
      sf_RightPathIndex = 1;
    }

    /*  Choose the RightPath */
    /* '<S7>:1191:33' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[sf_RightPathIndex - 1];

    /* '<S7>:1191:34' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[sf_RightPathIndex - 1];
  } else {
    /* '<S7>:1191:38' */
    *sf_Desired_HeadingTo = sf_AvgDesHeadingToPath[0];

    /* '<S7>:1191:39' */
    *sf_Desired_HeadingAlong = sf_AvgDesHeadingAlongPath[0];
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_OnePath(void)
{
  real_T sf_ErrorY;
  real_T eml_BlobCentroidX;
  real_T eml_BlobCentroidY;
  boolean_T maxNumBlobsReached;
  int32_T loop;
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
  real_T rtb_Sum_k;
  real_T rtb_TSamp_d;
  int8_T rtPrevAction;
  int8_T rtAction;
  int32_T rtb_BuoyBlobAnalysis_o1[10];
  real_T rtb_BuoyBlobAnalysis_o2[20];
  int32_T i;
  real_T tmp[2];
  real_T tmp_0[2];
  real_T tmp_1;

  /* During 'OnePath': '<S7>:1167' */
  switch (brain_DWork.is_OnePath) {
   case brain_IN_CenterOver:
    /* During 'CenterOver': '<S7>:1172' */
    if (brain_DWork.Error < 10.0) {
      /* Transition: '<S7>:1169' */
      /* Exit 'CenterOver': '<S7>:1172' */
      /* Entry 'Done': '<S7>:1171' */
      brain_DWork.is_OnePath = brain_IN_Done;
      brain_B.Left = 0;
      brain_B.Right = 0;
      brain_B.Strafe = 0;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'CenterOver': '<S7>:1177' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_m[i] = brain_B.Resize[i];
        brain_B.S_h[i] = brain_B.Resize1[i];
      }

      brain_DWork.StateFlowFunctionsFollowOnePa_m = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsFollowOnePa_e;
      brain_DWork.StateFlowFunctionsFollowOnePa_e = brain_M->Timing.clockTick0;

      /* Logic: '<S12>/Logical Operator1' incorporates:
       *  Constant: '<S37>/Constant'
       *  Constant: '<S38>/Constant'
       *  Constant: '<S39>/Constant'
       *  Logic: '<S12>/Logical Operator'
       *  RelationalOperator: '<S37>/Compare'
       *  RelationalOperator: '<S38>/Compare'
       *  RelationalOperator: '<S39>/Compare'
       */
      for (i = 0; i < 19200; i++) {
        brain_B.BW[i] = (((brain_B.H_m[i] > brain_P.Track_HueHigher) ||
                          (brain_B.H_m[i] <= brain_P.Track_HueLower)) &&
                         (brain_B.S_h[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipblob): '<S12>/Buoy Blob Analysis' */
      maxNumBlobsReached = FALSE;
      for (loop = 0; loop < 123; loop++) {
        brain_DWork.BuoyBlobAnalysis_PAD_DW[loop] = 0U;
      }

      currentLabel = 1U;
      loop = 0;
      idx = 123;
      for (n = 0; n < 160; n++) {
        for (n_0 = 0; n_0 < 120; n_0++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.BW[loop] ?
            255 : 0);
          loop++;
          idx++;
        }

        brain_DWork.BuoyBlobAnalysis_PAD_DW[idx] = 0U;
        idx++;
        brain_DWork.BuoyBlobAnalysis_PAD_DW[idx] = 0U;
        idx++;
      }

      for (loop = 0; loop < 121; loop++) {
        brain_DWork.BuoyBlobAnalysis_PAD_DW[loop + idx] = 0U;
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
          if (brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
            brain_DWork.BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
            brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
            brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(ms - 1);
            pixIdx++;
            BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
            brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
            stackIdx++;
            while (stackIdx) {
              stackIdx--;
              numBlobs = brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx];
              for (i = 0; i < 8; i++) {
                walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled16[i];
                if (brain_DWork.BuoyBlobAnalysis_PAD_DW[walkerIdx] == 255) {
                  brain_DWork.BuoyBlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
                  brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                    ((int16_T)(walkerIdx / 122U) - 1);
                  brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                    (walkerIdx % 122U - 1U);
                  pixIdx++;
                  BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
                  brain_DWork.BuoyBlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
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
      loop = 0;
      n_0 = 0;
      for (idx = 0; idx < (int32_T)numBlobs; idx++) {
        rtb_BuoyBlobAnalysis_o1[idx] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
        n = 0;
        ms = 0;
        for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx]; j++) {
          n += brain_DWork.BuoyBlobAnalysis_N_PIXLIST_DW[j + n_0];
          ms += brain_DWork.BuoyBlobAnalysis_M_PIXLIST_DW[j + loop];
        }

        rtb_BuoyBlobAnalysis_o2[idx << 1] = (real_T)ms / (real_T)
          BuoyBlobAnalysis_NUM_PIX_DW[idx];
        rtb_BuoyBlobAnalysis_o2[(idx << 1) + 1] = (real_T)n / (real_T)
          BuoyBlobAnalysis_NUM_PIX_DW[idx];
        loop += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
        n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[idx];
      }

      for (loop = (int32_T)numBlobs; loop < 10; loop++) {
        rtb_BuoyBlobAnalysis_o1[loop] = -1;
      }

      for (loop = (int32_T)numBlobs << 1; loop < 20; loop++) {
        rtb_BuoyBlobAnalysis_o2[loop] = -1.0;
      }

      /* Embedded MATLAB: '<S12>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function': '<S40>:1' */
      /*  This function will choose and return data about the largest blob given a  */
      /*  set of blobs */
      if ((rtb_BuoyBlobAnalysis_o2[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2[1] ==
           -1.0)) {
        /* '<S40>:1:5' */
        /* '<S40>:1:7' */
        eml_BlobCentroidX = 80.0;

        /* '<S40>:1:8' */
        eml_BlobCentroidY = 60.0;
      } else {
        loop = rtb_BuoyBlobAnalysis_o1[0];
        n = 1;
        n_0 = 1;
        for (idx = 2; idx < 11; idx++) {
          n_0++;
          if (rtb_BuoyBlobAnalysis_o1[n_0 - 1] > loop) {
            loop = rtb_BuoyBlobAnalysis_o1[n_0 - 1];
            n = idx;
          }
        }

        /* '<S40>:1:12' */
        eml_BlobCentroidX = rtb_BuoyBlobAnalysis_o2[((n - 1) << 1) + 1];

        /* '<S40>:1:13' */
        eml_BlobCentroidY = rtb_BuoyBlobAnalysis_o2[(n - 1) << 1];
      }

      /* Embedded MATLAB: '<S12>/Embedded MATLAB Function1' */
      brain_EmbeddedMATLABFunction1(&brain_B.sf_EmbeddedMATLABFunction1_d);

      /* Sum: '<S12>/Subtract' */
      brain_B.Subtract = eml_BlobCentroidX -
        brain_B.sf_EmbeddedMATLABFunction1_d.XCenter;

      /* Sum: '<S12>/Subtract1' */
      brain_B.Subtract1 = eml_BlobCentroidY -
        brain_B.sf_EmbeddedMATLABFunction1_d.YCenter;

      /* Sum: '<S42>/Subtract' */
      rtb_Sum_k = eml_BlobCentroidX -
        brain_B.sf_EmbeddedMATLABFunction1_d.XCenter;

      /* SampleTimeMath: '<S45>/TSamp' incorporates:
       *  Gain: '<S44>/X-Buoy Derivative Gain'
       *
       * About '<S45>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp_d = brain_P.Cam_Down_XPos_Kd * rtb_Sum_k / ((real_T)
        brain_DWork.StateFlowFunctionsFollowOnePa_m * 0.2);

      /* DataTypeConversion: '<S42>/Data Type Conversion' incorporates:
       *  DiscreteIntegrator: '<S44>/X-Buoy Discrete-Time Integrator'
       *  Gain: '<S44>/X-Buoy Proportional Gain'
       *  Sum: '<S44>/Sum'
       *  Sum: '<S45>/Diff'
       *  UnitDelay: '<S45>/UD'
       *
       * Block description for '<S45>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S45>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = floor((brain_P.Cam_Down_XPos_Kp * rtb_Sum_k + (rtb_TSamp_d -
        brain_DWork.UD_DSTATE_k)) + brain_DWork.XBuoyDiscreteTimeIntegrator_DST);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DataTypeConversion = (int8_T)tmp_1;
        } else {
          brain_B.DataTypeConversion = MIN_int8_T;
        }
      } else {
        brain_B.DataTypeConversion = MAX_int8_T;
      }

      /* Sum: '<S43>/Subtract' */
      eml_BlobCentroidX = brain_B.sf_EmbeddedMATLABFunction1_d.YCenter -
        eml_BlobCentroidY;

      /* SampleTimeMath: '<S47>/TSamp' incorporates:
       *  Gain: '<S46>/Y-Buoy Derivative Gain'
       *
       * About '<S47>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_BlobCentroidY = brain_P.Cam_Down_YPos_Kd * eml_BlobCentroidX /
        ((real_T)brain_DWork.StateFlowFunctionsFollowOnePa_m * 0.2);

      /* DataTypeConversion: '<S43>/Data Type Conversion' incorporates:
       *  DiscreteIntegrator: '<S46>/Y-Buoy Discrete-Time Integrator'
       *  Gain: '<S46>/Y-Buoy Proportional Gain'
       *  Sum: '<S46>/Sum'
       *  Sum: '<S47>/Diff'
       *  UnitDelay: '<S47>/UD'
       *
       * Block description for '<S47>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S47>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = floor((brain_P.Cam_Down_YPos_Kp * eml_BlobCentroidX +
                     (eml_BlobCentroidY - brain_DWork.UD_DSTATE_ko)) +
                    brain_DWork.YBuoyDiscreteTimeIntegrator_DST);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DataTypeConversion_h = (int8_T)tmp_1;
        } else {
          brain_B.DataTypeConversion_h = MIN_int8_T;
        }
      } else {
        brain_B.DataTypeConversion_h = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S45>/UD'
       * Block description for '<S45>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_k = rtb_TSamp_d;

      /* Update for DiscreteIntegrator: '<S44>/X-Buoy Discrete-Time Integrator' incorporates:
       *  Gain: '<S44>/X-Buoy Integral Gain'
       */
      brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsFollowOnePa_m * (brain_P.Cam_Down_XPos_Ki *
        rtb_Sum_k) + brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
      if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
        brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 15.0;
      } else {
        if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
          brain_DWork.XBuoyDiscreteTimeIntegrator_DST = -15.0;
        }
      }

      /* Update for UnitDelay: '<S47>/UD'
       * Block description for '<S47>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_ko = eml_BlobCentroidY;

      /* Update for DiscreteIntegrator: '<S46>/Y-Buoy Discrete-Time Integrator' incorporates:
       *  Gain: '<S46>/Y-Buoy Integral Gain'
       */
      brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsFollowOnePa_m * (brain_P.Cam_Down_YPos_Ki *
        eml_BlobCentroidX) + brain_DWork.YBuoyDiscreteTimeIntegrator_DST;
      if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
        brain_DWork.YBuoyDiscreteTimeIntegrator_DST = 15.0;
      } else {
        if (brain_DWork.YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
          brain_DWork.YBuoyDiscreteTimeIntegrator_DST = -15.0;
        }
      }

      brain_B.Strafe = brain_B.DataTypeConversion;
      loop = brain_B.DataTypeConversion_h;
      rtb_TSamp_d = brain_B.Subtract1;
      sf_ErrorY = brain_B.Subtract;
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.BW[i];
      }

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S16>/Add' */
      eml_BlobCentroidX = (real_T)brain_B.DesiredDepth1 - (real_T)
        brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S56>/TSamp' incorporates:
       *  Gain: '<S55>/Depth Derivative Gain'
       *
       * About '<S56>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_BlobCentroidY = brain_P.Depth_Kd * eml_BlobCentroidX / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
       *  Gain: '<S55>/Depth Proportional Gain'
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
      tmp_1 = floor((brain_P.Depth_Kp * eml_BlobCentroidX + (eml_BlobCentroidY -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp_1;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S56>/UD'
       * Block description for '<S56>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = eml_BlobCentroidY;

      /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S55>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        eml_BlobCentroidX) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
      } else {
        if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
          brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
        }
      }

      brain_B.Vertical = brain_B.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S7>:918' */
      brain_B.DesiredHeading1 = brain_B.DesiredHeading;
      brain_B.CurrentHeading1 = brain_U.CurrentHeading;
      brain_B.ForwardVelocity1 = (real_T)loop;
      brain_DWork.StateFlowFunctionsMaintainHeadi = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainHea_m;
      brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

      /* Sum: '<S17>/Add1' */
      eml_BlobCentroidX = brain_B.DesiredHeading1 - brain_B.CurrentHeading1;

      /* If: '<S17>/If' incorporates:
       *  ActionPort: '<S57>/Action Port'
       *  ActionPort: '<S58>/Action Port'
       *  SubSystem: '<S17>/BigError S1'
       *  SubSystem: '<S17>/BigNegativeError S2'
       */
      rtPrevAction = brain_DWork.If_ActiveSubsystem;
      rtAction = -1;
      if (eml_BlobCentroidX > 180.0) {
        rtAction = 0;
      } else {
        if (eml_BlobCentroidX < -180.0) {
          rtAction = 1;
        }
      }

      brain_DWork.If_ActiveSubsystem = rtAction;
      if (rtPrevAction != rtAction) {
        switch (rtPrevAction) {
         case 0:
          /* Disable for Outport: '<S57>/Out2' */
          brain_B.Constant1_e = 0.0;
          break;

         case 1:
          /* Disable for Outport: '<S58>/Out2' */
          brain_B.Constant1 = 0.0;
          break;
        }
      }

      switch (rtAction) {
       case 0:
        /* Sum: '<S57>/Add' incorporates:
         *  Constant: '<S57>/Constant'
         */
        brain_B.Add_o = eml_BlobCentroidX - 360.0;

        /* Constant: '<S57>/Constant1' */
        brain_B.Constant1_e = 1.0;
        break;

       case 1:
        /* Sum: '<S58>/Add' incorporates:
         *  Constant: '<S58>/Constant'
         */
        brain_B.Add = eml_BlobCentroidX + 360.0;

        /* Constant: '<S58>/Constant1' */
        brain_B.Constant1 = 2.0;
        break;
      }

      /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       *  Sum: '<S17>/Add2'
       */
      switch ((int32_T)((1.0 + brain_B.Constant1_e) + brain_B.Constant1)) {
       case 1:
        break;

       case 2:
        eml_BlobCentroidX = brain_B.Add_o;
        break;

       default:
        eml_BlobCentroidX = brain_B.Add;
        break;
      }

      /* SampleTimeMath: '<S60>/TSamp' incorporates:
       *  Gain: '<S59>/Heading Derivative Gain'
       *
       * About '<S60>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_BlobCentroidY = brain_P.Heading_Kd * eml_BlobCentroidX / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * 0.2);

      /* Sum: '<S59>/Sum' incorporates:
       *  DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator'
       *  Gain: '<S59>/Heading Proportional Gain'
       *  Sum: '<S60>/Diff'
       *  UnitDelay: '<S60>/UD'
       *
       * Block description for '<S60>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      rtb_Sum_k = (brain_P.Heading_Kp * eml_BlobCentroidX + (eml_BlobCentroidY -
        brain_DWork.UD_DSTATE_p)) + brain_DWork.HeadingDiscreteTimeIntegrator_D;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S17>/Constant'
       */
      tmp_1 = -rtb_Sum_k;
      if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
        tmp_1 = 0.0;
      } else {
        tmp_1 = fmod(floor(tmp_1), 256.0);
      }

      /* Sum: '<S17>/Add4' */
      rtb_Sum_k += brain_B.ForwardVelocity1;

      /* DataTypeConversion: '<S17>/DoubleToint1' incorporates:
       *  Sum: '<S17>/Add3'
       */
      tmp_1 = floor((real_T)(int8_T)(tmp_1 < 0.0 ? (int32_T)(int8_T)(-((int8_T)
        (uint8_T)(-tmp_1))) : (int32_T)(int8_T)(uint8_T)tmp_1) +
                    brain_B.ForwardVelocity1);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DoubleToint1 = (int8_T)tmp_1;
        } else {
          brain_B.DoubleToint1 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint1 = MAX_int8_T;
      }

      /* DataTypeConversion: '<S17>/DoubleToint8' */
      tmp_1 = floor(rtb_Sum_k);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DoubleToint8 = (int8_T)tmp_1;
        } else {
          brain_B.DoubleToint8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToint8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S60>/UD'
       * Block description for '<S60>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_p = eml_BlobCentroidY;

      /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
       *  Gain: '<S59>/Heading Integral Gain'
       */
      brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainHeadi * (brain_P.Heading_Ki *
        eml_BlobCentroidX) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
      if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
      } else {
        if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
          brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
        }
      }

      brain_B.Left = brain_B.DoubleToint8;
      brain_B.Right = brain_B.DoubleToint1;

      /* Embedded MATLAB Function 'CalcError': '<S7>:1173' */
      /*  This function calculates the error between the center of the screen and  */
      /*  the centroid of the orange/red blob */
      /* '<S7>:1173:5' */
      brain_DWork.Error = fabs(rtb_TSamp_d - sf_ErrorY);
    }
    break;

   case brain_IN_Done:
    break;

   case brain_IN_GetDirections:
    /* During 'GetDirections': '<S7>:1185' */
    if (brain_DWork.countTo >= 4.0) {
      /* Transition: '<S7>:1168' */
      /* Exit 'GetDirections': '<S7>:1185' */
      brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                       &brain_DWork.AvgDesiredHeadingAlongPath[0],
                       &eml_BlobCentroidX, &eml_BlobCentroidY);
      brain_B.DesiredHeading = eml_BlobCentroidY;

      /* Entry 'CenterOver': '<S7>:1172' */
      brain_DWork.is_OnePath = brain_IN_CenterOver;
      brain_DWork.Error = 500.0;
    } else {
      /* Simulink Function 'MakeHSVImage': '<S7>:1215' */
      for (i = 0; i < 19200; i++) {
        brain_B.H1[i] = brain_B.Resize[i];
        brain_B.S1[i] = brain_B.Resize1[i];
        brain_B.V1[i] = brain_B.Resize2[i];
      }

      StateFlowFunctionsFollowOnePath(brain_B.H1, brain_B.S1, brain_B.V1,
        &brain_B.StateFlowFunctionsFollowOnePa_g);

      /* Simulink Function 'GetBrightestPixel_VerticalSplit': '<S7>:1186' */
      memcpy((void *)&brain_B.HSV1[0], (void *)
             &brain_B.StateFlowFunctionsFollowOnePa_g.HSVImage1[0], 57600U *
             sizeof(real_T));
      brain_B.DesiredH1 = 0.05;

      /* Embedded MATLAB: '<S48>/Get Brightest Pixel Per Column and Row' */
      brain_c9_brain();
      for (i = 0; i < 9600; i++) {
        /* DataTypeConversion: '<S48>/Data Type Conversion' */
        brain_B.BWleft_k[i] = (brain_B.BWleft[i] != 0.0);

        /* DataTypeConversion: '<S48>/Data Type Conversion1' */
        brain_B.BWright_e[i] = (brain_B.BWright[i] != 0.0);
        loop = brain_B.BWleft_k[i];
        idx = brain_B.BWright_e[i];
        brain_B.BWleft1[i] = (loop != 0);
        brain_B.BWright1[i] = (idx != 0);
        brain_B.sf_BWright[i] = (real_T)idx;
        brain_B.sf_BWleft[i] = (real_T)loop;
      }

      brain_CombineBWs(&brain_B.sf_BWleft[0], &brain_B.sf_BWright[0],
                       &brain_B.BWout[0]);

      /* Simulink Function 'GetHeadings': '<S7>:1208' */
      brain_B.CurrentHeading1_b = brain_U.CurrentHeading;
      StateFlowFunctionsFollowOnePa_h(brain_B.BWleft1, brain_B.BWright1,
        brain_B.CurrentHeading1_b, &brain_B.StateFlowFunctionsFollowOneP_ht);
      tmp_0[0] = brain_DWork.AvgDesiredHeadingToPath[0];
      tmp[0] = brain_DWork.AvgDesiredHeadingAlongPath[0];
      tmp_0[1] = brain_DWork.AvgDesiredHeadingToPath[1];
      tmp[1] = brain_DWork.AvgDesiredHeadingAlongPath[1];
      brain_GetAvgDesHeading
        (&brain_B.StateFlowFunctionsFollowOneP_ht.ToPathHeading[0], tmp_0,
         brain_DWork.countTo, brain_DWork.outliersTo,
         &brain_DWork.AvgDesiredHeadingToPath[0], &eml_BlobCentroidX,
         &eml_BlobCentroidY);
      brain_DWork.countTo = eml_BlobCentroidX;
      brain_DWork.outliersTo = eml_BlobCentroidY;
      brain_GetAvgDesHeading
        (&brain_B.StateFlowFunctionsFollowOneP_ht.AlongPathHeading[0], tmp,
         brain_DWork.countAlong, brain_DWork.outliersAlong,
         &brain_DWork.AvgDesiredHeadingAlongPath[0], &eml_BlobCentroidX,
         &eml_BlobCentroidY);
      brain_DWork.countAlong = eml_BlobCentroidX;
      brain_DWork.outliersAlong = eml_BlobCentroidY;

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsMaintainDep_k;
      brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

      /* Sum: '<S16>/Add' */
      eml_BlobCentroidX = (real_T)brain_B.DesiredDepth1 - (real_T)
        brain_B.CurrentDepth1;

      /* SampleTimeMath: '<S56>/TSamp' incorporates:
       *  Gain: '<S55>/Depth Derivative Gain'
       *
       * About '<S56>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_BlobCentroidY = brain_P.Depth_Kd * eml_BlobCentroidX / ((real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

      /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
       *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
       *  Gain: '<S55>/Depth Proportional Gain'
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
      tmp_1 = floor((brain_P.Depth_Kp * eml_BlobCentroidX + (eml_BlobCentroidY -
        brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DoubleToInt8 = (int8_T)tmp_1;
        } else {
          brain_B.DoubleToInt8 = MIN_int8_T;
        }
      } else {
        brain_B.DoubleToInt8 = MAX_int8_T;
      }

      /* Update for UnitDelay: '<S56>/UD'
       * Block description for '<S56>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = eml_BlobCentroidY;

      /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
       *  Gain: '<S55>/Depth Integral Gain'
       */
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki *
        eml_BlobCentroidX) + brain_DWork.DepthDiscreteTimeIntegrator_DST;
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
    brain_enter_internal_OnePath();
    break;
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
  boolean_T sf_Obstacle;
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Add1;
  real_T rtb_Add4;
  real_T rtb_TSamp_j;
  int32_T i;
  real_T tmp;

  /* During 'ValidationGate': '<S7>:1151' */
  if (brain_DWork.OperationalState != 4) {
    /* Transition: '<S7>:1275' */
    /* Exit 'ValidationGate': '<S7>:1151' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    /* Simulink Function 'LookforTrack': '<S7>:1154' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_n[i] = brain_B.Resize[i];
      brain_B.S_j[i] = brain_B.Resize1[i];
    }

    StateFlowFunctionsValidationGat(brain_B.H_n, brain_B.S_j,
      &brain_B.StateFlowFunctionsValidationG_a,
      &brain_DWork.StateFlowFunctionsValidationG_a);
    sf_Obstacle = (brain_B.StateFlowFunctionsValidationG_a.Image != 0.0);
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsValidationG_a.BW[i];
    }

    brain_DWork.TrackCount = brain_countimages_m((real_T)sf_Obstacle, (real_T)
      brain_DWork.OldObstacle, brain_DWork.count);

    /* Simulink Function 'GetValidationGateForwardVelocity': '<S7>:1152' */

    /* Constant: '<S18>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Heading_Forward_Velocity;

    /* Simulink Function 'MaintainHeading': '<S7>:918' */
    brain_B.DesiredHeading1 = brain_B.DesiredHeading;
    brain_B.CurrentHeading1 = brain_U.CurrentHeading;
    brain_B.ForwardVelocity1 = brain_B.HeadingForwardVelocity;
    brain_DWork.StateFlowFunctionsMaintainHeadi = brain_M->Timing.clockTick0 -
      brain_DWork.StateFlowFunctionsMaintainHea_m;
    brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;

    /* Sum: '<S17>/Add1' */
    rtb_Add1 = brain_B.DesiredHeading1 - brain_B.CurrentHeading1;

    /* If: '<S17>/If' incorporates:
     *  ActionPort: '<S57>/Action Port'
     *  ActionPort: '<S58>/Action Port'
     *  SubSystem: '<S17>/BigError S1'
     *  SubSystem: '<S17>/BigNegativeError S2'
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
        /* Disable for Outport: '<S57>/Out2' */
        brain_B.Constant1_e = 0.0;
        break;

       case 1:
        /* Disable for Outport: '<S58>/Out2' */
        brain_B.Constant1 = 0.0;
        break;
      }
    }

    switch (rtAction) {
     case 0:
      /* Sum: '<S57>/Add' incorporates:
       *  Constant: '<S57>/Constant'
       */
      brain_B.Add_o = rtb_Add1 - 360.0;

      /* Constant: '<S57>/Constant1' */
      brain_B.Constant1_e = 1.0;
      break;

     case 1:
      /* Sum: '<S58>/Add' incorporates:
       *  Constant: '<S58>/Constant'
       */
      brain_B.Add = rtb_Add1 + 360.0;

      /* Constant: '<S58>/Constant1' */
      brain_B.Constant1 = 2.0;
      break;
    }

    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Sum: '<S17>/Add2'
     */
    switch ((int32_T)((1.0 + brain_B.Constant1_e) + brain_B.Constant1)) {
     case 1:
      break;

     case 2:
      rtb_Add1 = brain_B.Add_o;
      break;

     default:
      rtb_Add1 = brain_B.Add;
      break;
    }

    /* SampleTimeMath: '<S60>/TSamp' incorporates:
     *  Gain: '<S59>/Heading Derivative Gain'
     *
     * About '<S60>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_j = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainHeadi * 0.2);

    /* Sum: '<S59>/Sum' incorporates:
     *  DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator'
     *  Gain: '<S59>/Heading Proportional Gain'
     *  Sum: '<S60>/Diff'
     *  UnitDelay: '<S60>/UD'
     *
     * Block description for '<S60>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S60>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_j -
      brain_DWork.UD_DSTATE_p)) + brain_DWork.HeadingDiscreteTimeIntegrator_D;

    /* Product: '<S17>/Multiply' incorporates:
     *  Constant: '<S17>/Constant'
     */
    tmp = -rtb_Add4;
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(floor(tmp), 256.0);
    }

    /* Sum: '<S17>/Add4' */
    rtb_Add4 += brain_B.ForwardVelocity1;

    /* DataTypeConversion: '<S17>/DoubleToint1' incorporates:
     *  Sum: '<S17>/Add3'
     */
    tmp = floor((real_T)(int8_T)(tmp < 0.0 ? (int32_T)(int8_T)(-((int8_T)
      (uint8_T)(-tmp))) : (int32_T)(int8_T)(uint8_T)tmp) +
                brain_B.ForwardVelocity1);
    if (tmp < 128.0) {
      if (tmp >= -128.0) {
        brain_B.DoubleToint1 = (int8_T)tmp;
      } else {
        brain_B.DoubleToint1 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToint1 = MAX_int8_T;
    }

    /* DataTypeConversion: '<S17>/DoubleToint8' */
    tmp = floor(rtb_Add4);
    if (tmp < 128.0) {
      if (tmp >= -128.0) {
        brain_B.DoubleToint8 = (int8_T)tmp;
      } else {
        brain_B.DoubleToint8 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToint8 = MAX_int8_T;
    }

    /* Update for UnitDelay: '<S60>/UD'
     * Block description for '<S60>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE_p = rtb_TSamp_j;

    /* Update for DiscreteIntegrator: '<S59>/Heading Discrete-Time Integrator' incorporates:
     *  Gain: '<S59>/Heading Integral Gain'
     */
    brain_DWork.HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
      brain_DWork.StateFlowFunctionsMaintainHeadi * (brain_P.Heading_Ki *
      rtb_Add1) + brain_DWork.HeadingDiscreteTimeIntegrator_D;
    if (brain_DWork.HeadingDiscreteTimeIntegrator_D >= 15.0) {
      brain_DWork.HeadingDiscreteTimeIntegrator_D = 15.0;
    } else {
      if (brain_DWork.HeadingDiscreteTimeIntegrator_D <= -15.0) {
        brain_DWork.HeadingDiscreteTimeIntegrator_D = -15.0;
      }
    }

    brain_B.Left = brain_B.DoubleToint8;
    brain_B.Right = brain_B.DoubleToint1;

    /* Simulink Function 'MaintainDepth': '<S7>:926' */
    brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
    brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
    brain_DWork.StateFlowFunctionsMaintainDepth = brain_M->Timing.clockTick0 -
      brain_DWork.StateFlowFunctionsMaintainDep_k;
    brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

    /* Sum: '<S16>/Add' */
    rtb_Add1 = (real_T)brain_B.DesiredDepth1 - (real_T)brain_B.CurrentDepth1;

    /* SampleTimeMath: '<S56>/TSamp' incorporates:
     *  Gain: '<S55>/Depth Derivative Gain'
     *
     * About '<S56>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_j = brain_P.Depth_Kd * rtb_Add1 / ((real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * 0.2);

    /* DataTypeConversion: '<S16>/Double To Int8' incorporates:
     *  DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator'
     *  Gain: '<S55>/Depth Proportional Gain'
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
    tmp = floor((brain_P.Depth_Kp * rtb_Add1 + (rtb_TSamp_j -
      brain_DWork.UD_DSTATE)) + brain_DWork.DepthDiscreteTimeIntegrator_DST);
    if (tmp < 128.0) {
      if (tmp >= -128.0) {
        brain_B.DoubleToInt8 = (int8_T)tmp;
      } else {
        brain_B.DoubleToInt8 = MIN_int8_T;
      }
    } else {
      brain_B.DoubleToInt8 = MAX_int8_T;
    }

    /* Update for UnitDelay: '<S56>/UD'
     * Block description for '<S56>/UD':
     *
     *  Store in Global RAM
     */
    brain_DWork.UD_DSTATE = rtb_TSamp_j;

    /* Update for DiscreteIntegrator: '<S55>/Depth Discrete-Time Integrator' incorporates:
     *  Gain: '<S55>/Depth Integral Gain'
     */
    brain_DWork.DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
      brain_DWork.StateFlowFunctionsMaintainDepth * (brain_P.Depth_Ki * rtb_Add1)
      + brain_DWork.DepthDiscreteTimeIntegrator_DST;
    if (brain_DWork.DepthDiscreteTimeIntegrator_DST >= 10.0) {
      brain_DWork.DepthDiscreteTimeIntegrator_DST = 10.0;
    } else {
      if (brain_DWork.DepthDiscreteTimeIntegrator_DST <= -10.0) {
        brain_DWork.DepthDiscreteTimeIntegrator_DST = -10.0;
      }
    }

    brain_B.Vertical = brain_B.DoubleToInt8;
    brain_DWork.OldObstacle = sf_Obstacle;
    brain_DWork.count = brain_DWork.TrackCount;
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
  real_T sf_Desired_HeadingAlong;
  real_T sf_Desired_HeadingTo;
  int32_T outStep;
  int32_T inStep;
  int32_T n;
  int32_T outStep_0;
  int32_T inStep_0;
  int32_T n_0;
  real32_T Resize2_LineBuffer[480];

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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o1[brain_ConstP.pooled19[n_0]
          * 480 + n] * brain_ConstP.pooled13[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled18[n_0]] *
          brain_ConstP.pooled12[n_0];
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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o2[brain_ConstP.pooled19[n_0]
          * 480 + n] * brain_ConstP.pooled13[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled18[n_0]] *
          brain_ConstP.pooled12[n_0];
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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o3[brain_ConstP.pooled19[n_0]
          * 480 + n] * brain_ConstP.pooled13[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled18[n_0]] *
          brain_ConstP.pooled12[n_0];
        n_0 += 120;
      }

      brain_B.Resize2[inStep] = sum;
      inStep++;
    }
  }

  /* Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Inport: '<Root>/CurrentHeading'
   *  Inport: '<Root>/DesiredState'
   *  Inport: '<Root>/RC'
   *  Inport: '<Root>/Status'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoy.ApproachBuoy.Buoy'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoy.GetBuoyForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
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

        /* Entry 'ControlledRC': '<S7>:944' */
        brain_DWork.is_Running = brain_IN_ControlledRC;
      } else {
        brain_DWork.OperationalState = 0;
      }
      break;

     case brain_IN_Running:
      /* During 'Running': '<S7>:940' */
      if (brain_U.Status != 1) {
        /* Transition: '<S7>:1137' */
        /* Exit 'Buoy': '<S7>:1025' */
        brain_DWork.is_Autonomous = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

        /* Exit 'ChooseState': '<S7>:1134' */
        /* Exit 'Finish': '<S7>:1064' */
        /* Exit 'FollowOnePath': '<S7>:1065' */
        /* Exit 'FollowOnePath1': '<S7>:1142' */
        /* Exit 'Start': '<S7>:1019' */
        /* Exit 'ValidationGate': '<S7>:1121' */
        /* Exit 'Autonomous': '<S7>:945' */
        brain_DWork.is_Running = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

        /* Exit 'ControlledRC': '<S7>:944' */
        /* Exit 'Running': '<S7>:940' */
        /* Entry 'NotRunning': '<S7>:1135' */
        brain_DWork.is_StateManagement = brain_IN_NotRunning_m;
      } else {
        switch (brain_DWork.is_Running) {
         case brain_IN_Autonomous:
          /* During 'Autonomous': '<S7>:945' */
          if ((int32_T)brain_U.RC == 1) {
            /* Transition: '<S7>:942' */
            /* Exit 'Buoy': '<S7>:1025' */
            brain_DWork.is_Autonomous = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

            /* Exit 'ChooseState': '<S7>:1134' */
            /* Exit 'Finish': '<S7>:1064' */
            /* Exit 'FollowOnePath': '<S7>:1065' */
            /* Exit 'FollowOnePath1': '<S7>:1142' */
            /* Exit 'Start': '<S7>:1019' */
            /* Exit 'ValidationGate': '<S7>:1121' */
            /* Exit 'Autonomous': '<S7>:945' */
            /* Entry 'ControlledRC': '<S7>:944' */
            brain_DWork.is_Running = brain_IN_ControlledRC;
          } else {
            switch (brain_DWork.is_Autonomous) {
             case brain_IN_Buoy:
              /* During 'Buoy': '<S7>:1025' */
              if ((brain_DWork.BuoyDone == 1.0) && (brain_U.DesiredState == 0))
              {
                /* Transition: '<S7>:950' */
                /* Exit 'Buoy': '<S7>:1025' */
                /* Entry 'FollowOnePath1': '<S7>:1142' */
                brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
              } else if ((brain_U.DesiredState != 4) && (brain_U.DesiredState !=
                          0)) {
                /* Transition: '<S7>:959' */
                /* Exit 'Buoy': '<S7>:1025' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else {
                brain_DWork.OperationalState = 6;
              }
              break;

             case brain_IN_ChooseState:
              /* During 'ChooseState': '<S7>:1134' */
              if ((brain_U.DesiredState == 1) || (brain_U.DesiredState == 0)) {
                /* Transition: '<S7>:960' */
                /* Exit 'ChooseState': '<S7>:1134' */
                /* Entry 'Start': '<S7>:1019' */
                brain_DWork.is_Autonomous = brain_IN_Start_m;
              } else if (brain_U.DesiredState == 2) {
                /* Transition: '<S7>:954' */
                /* Exit 'ChooseState': '<S7>:1134' */
                /* Entry 'ValidationGate': '<S7>:1121' */
                brain_DWork.is_Autonomous = brain_IN_ValidationGate_m;
              } else if (brain_U.DesiredState == 4) {
                /* Transition: '<S7>:958' */
                /* Exit 'ChooseState': '<S7>:1134' */
                /* Entry 'Buoy': '<S7>:1025' */
                brain_DWork.is_Autonomous = brain_IN_Buoy;
              } else if (brain_U.DesiredState == 3) {
                /* Transition: '<S7>:956' */
                /* Exit 'ChooseState': '<S7>:1134' */
                /* Entry 'FollowOnePath': '<S7>:1065' */
                brain_DWork.is_Autonomous = brain_IN_FollowOnePath;
              } else {
                if (brain_U.DesiredState == 5) {
                  /* Transition: '<S7>:952' */
                  /* Exit 'ChooseState': '<S7>:1134' */
                  /* Entry 'FollowOnePath1': '<S7>:1142' */
                  brain_DWork.is_Autonomous = brain_IN_FollowOnePath1;
                }
              }
              break;

             case brain_IN_Finish:
              /* During 'Finish': '<S7>:1064' */
              if ((brain_U.DesiredState != 6) && (brain_U.DesiredState != 0)) {
                /* Transition: '<S7>:962' */
                /* Exit 'Finish': '<S7>:1064' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else {
                brain_DWork.OperationalState = 7;
              }
              break;

             case brain_IN_FollowOnePath:
              /* During 'FollowOnePath': '<S7>:1065' */
              if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0)) {
                /* Transition: '<S7>:951' */
                /* Exit 'FollowOnePath': '<S7>:1065' */
                /* Entry 'Buoy': '<S7>:1025' */
                brain_DWork.is_Autonomous = brain_IN_Buoy;
              } else if ((brain_U.DesiredState != 3) && (brain_U.DesiredState !=
                          0)) {
                /* Transition: '<S7>:957' */
                /* Exit 'FollowOnePath': '<S7>:1065' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else {
                brain_DWork.OperationalState = 5;
              }
              break;

             case brain_IN_FollowOnePath1:
              /* During 'FollowOnePath1': '<S7>:1142' */
              if ((brain_U.DesiredState != 5) && (brain_U.DesiredState != 0)) {
                /* Transition: '<S7>:953' */
                /* Exit 'FollowOnePath1': '<S7>:1142' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else if ((brain_DWork.Done != 0.0) && (brain_U.DesiredState == 0))
              {
                /* Transition: '<S7>:949' */
                /* Exit 'FollowOnePath1': '<S7>:1142' */
                /* Entry 'Finish': '<S7>:1064' */
                brain_DWork.is_Autonomous = brain_IN_Finish;
              } else {
                brain_DWork.OperationalState = 5;
              }
              break;

             case brain_IN_Start_m:
              /* During 'Start': '<S7>:1019' */
              if ((brain_DWork.DesiredHeadingCount >= 3.0) &&
                  (brain_U.DesiredState == 0)) {
                /* Transition: '<S7>:948' */
                /* Exit 'Start': '<S7>:1019' */
                /* Entry 'ValidationGate': '<S7>:1121' */
                brain_DWork.is_Autonomous = brain_IN_ValidationGate_m;
              } else if ((brain_U.DesiredState != 1) && (brain_U.DesiredState !=
                          0)) {
                /* Transition: '<S7>:961' */
                /* Exit 'Start': '<S7>:1019' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else {
                brain_DWork.OperationalState = 3;
              }
              break;

             case brain_IN_ValidationGate_m:
              /* During 'ValidationGate': '<S7>:1121' */
              if ((brain_U.DesiredState != 2) && (brain_U.DesiredState != 0)) {
                /* Transition: '<S7>:955' */
                /* Exit 'ValidationGate': '<S7>:1121' */
                /* Entry 'ChooseState': '<S7>:1134' */
                brain_DWork.is_Autonomous = brain_IN_ChooseState;
              } else if ((brain_DWork.TrackCount > 2.0) && (brain_U.DesiredState
                          == 0)) {
                /* Transition: '<S7>:947' */
                /* Exit 'ValidationGate': '<S7>:1121' */
                /* Entry 'FollowOnePath': '<S7>:1065' */
                brain_DWork.is_Autonomous = brain_IN_FollowOnePath;
              } else {
                brain_DWork.OperationalState = 4;
              }
              break;

             default:
              /* Transition: '<S7>:946' */
              /* Entry 'Start': '<S7>:1019' */
              brain_DWork.is_Autonomous = brain_IN_Start_m;
              break;
            }
          }
          break;

         case brain_IN_ControlledRC:
          /* During 'ControlledRC': '<S7>:944' */
          if ((int32_T)brain_U.RC == 0) {
            /* Transition: '<S7>:943' */
            /* Exit 'ControlledRC': '<S7>:944' */
            /* Entry 'Autonomous': '<S7>:945' */
            brain_DWork.is_Running = brain_IN_Autonomous;

            /* Transition: '<S7>:946' */
            /* Entry 'Start': '<S7>:1019' */
            brain_DWork.is_Autonomous = brain_IN_Start_m;
          } else {
            brain_DWork.OperationalState = 1;
          }
          break;

         default:
          /* Transition: '<S7>:941' */
          /* Entry 'Autonomous': '<S7>:945' */
          brain_DWork.is_Running = brain_IN_Autonomous;

          /* Transition: '<S7>:946' */
          /* Entry 'Start': '<S7>:1019' */
          brain_DWork.is_Autonomous = brain_IN_Start_m;
          break;
        }
      }
      break;

     default:
      /* Transition: '<S7>:1138' */
      /* Entry 'NotRunning': '<S7>:1135' */
      brain_DWork.is_StateManagement = brain_IN_NotRunning_m;
      break;
    }

    /* During 'StateFlowFunctions': '<S7>:726' */
    switch (brain_DWork.is_StateFlowFunctions) {
     case brain_IN_Buoy:
      brain_Buoy();
      break;

     case brain_IN_ControlledRC:
      /* During 'ControlledRC': '<S7>:1260' */
      /* Transition: '<S7>:1268' */
      /* Exit 'ControlledRC': '<S7>:1260' */
      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      break;

     case brain_IN_Finish:
      /* During 'Finish': '<S7>:1259' */
      if (brain_DWork.OperationalState != 7) {
        /* Transition: '<S7>:1282' */
        /* Exit 'Finish': '<S7>:1259' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      }
      break;

     case brain_IN_FollowOnePath:
      /* During 'FollowOnePath': '<S7>:1164' */
      if (brain_DWork.OperationalState != 5) {
        /* Transition: '<S7>:1276' */
        if (brain_DWork.is_FollowOnePath == brain_IN_OnePath) {
          switch (brain_DWork.is_OnePath) {
           case brain_IN_CenterOver:
            /* Exit 'CenterOver': '<S7>:1172' */
            brain_DWork.is_OnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
            break;

           case brain_IN_GetDirections:
            /* Exit 'GetDirections': '<S7>:1185' */
            brain_ChoosePath(&brain_DWork.AvgDesiredHeadingToPath[0],
                             &brain_DWork.AvgDesiredHeadingAlongPath[0],
                             &sf_Desired_HeadingTo, &sf_Desired_HeadingAlong);
            brain_B.DesiredHeading = sf_Desired_HeadingAlong;
            brain_DWork.is_OnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
            break;

           default:
            brain_DWork.is_OnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

            /* Exit 'Done': '<S7>:1171' */
            break;
          }

          /* Exit 'OnePath': '<S7>:1167' */
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
        } else {
          brain_DWork.is_FollowOnePath = (uint8_T)brain_IN_NO_ACTIVE_CHILD;

          /* Exit 'Initialize': '<S7>:1214' */
        }

        /* Exit 'FollowOnePath': '<S7>:1164' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      } else {
        switch (brain_DWork.is_FollowOnePath) {
         case brain_IN_Initialize:
          /* During 'Initialize': '<S7>:1214' */
          /* Transition: '<S7>:1166' */
          /* Exit 'Initialize': '<S7>:1214' */
          /* Entry 'OnePath': '<S7>:1167' */
          brain_DWork.is_FollowOnePath = brain_IN_OnePath;

          /* Transition: '<S7>:1170' */
          /* Entry 'GetDirections': '<S7>:1185' */
          brain_DWork.is_OnePath = brain_IN_GetDirections;
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
          /* Transition: '<S7>:1165' */
          /* Entry 'Initialize': '<S7>:1214' */
          brain_DWork.is_FollowOnePath = brain_IN_Initialize;

          /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

          /* Constant: '<S15>/Constant' */
          brain_B.Constant = brain_P.Track_Desired_Depth;
          brain_B.DesiredDepth = brain_B.Constant;
          brain_B.DesiredHeading = 0.0;
          brain_DWork.Done = 0.0;
          brain_B.State = 3;
          brain_B.CameraPosition = 2;

          /* Simulink Function 'MakeHSVImage': '<S7>:1215' */
          for (outStep = 0; outStep < 19200; outStep++) {
            brain_B.H1[outStep] = brain_B.Resize[outStep];
            brain_B.S1[outStep] = brain_B.Resize1[outStep];
            brain_B.V1[outStep] = brain_B.Resize2[outStep];
          }

          StateFlowFunctionsFollowOnePath(brain_B.H1, brain_B.S1, brain_B.V1,
            &brain_B.StateFlowFunctionsFollowOnePa_g);
          break;
        }
      }
      break;

     case brain_IN_GetInCorrectState:
      /* During 'GetInCorrectState': '<S7>:1263' */
      if (brain_DWork.OperationalState == 0) {
        /* Transition: '<S7>:1266' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'NotRunning': '<S7>:727' */
        brain_DWork.is_StateFlowFunctions = brain_IN_NotRunning;
        brain_B.Left = 0;
        brain_B.Right = 0;
        brain_B.Vertical = 0;
        brain_B.State = -2;
      } else if (brain_DWork.OperationalState == 1) {
        /* Transition: '<S7>:1267' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'ControlledRC': '<S7>:1260' */
        brain_DWork.is_StateFlowFunctions = brain_IN_ControlledRC;
        brain_B.State = -1;
      } else if (brain_DWork.OperationalState == 3) {
        /* Transition: '<S7>:1271' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'Start': '<S7>:1145' */
        brain_DWork.is_StateFlowFunctions = brain_IN_Start;
        brain_DWork.OldHeading = 0.0;
        brain_DWork.DesiredHeadingCount = 0.0;
        brain_B.BuoyCentroidX = 0.0;
        brain_B.BuoyCentroidY = 0.0;
        brain_B.CameraPosition = 2;
        brain_B.State = 1;
      } else if (brain_DWork.OperationalState == 4) {
        /* Transition: '<S7>:1274' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'ValidationGate': '<S7>:1151' */
        brain_DWork.is_StateFlowFunctions = brain_IN_ValidationGate;
        brain_DWork.OldObstacle = FALSE;
        brain_DWork.count = 0.0;
        brain_DWork.TrackCount = 0.0;
        brain_B.State = 2;
        brain_B.CameraPosition = 2;
      } else if (brain_DWork.OperationalState == 5) {
        /* Transition: '<S7>:1277' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'FollowOnePath': '<S7>:1164' */
        brain_DWork.is_StateFlowFunctions = brain_IN_FollowOnePath;

        /* Transition: '<S7>:1165' */
        /* Entry 'Initialize': '<S7>:1214' */
        brain_DWork.is_FollowOnePath = brain_IN_Initialize;

        /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

        /* Constant: '<S15>/Constant' */
        brain_B.Constant = brain_P.Track_Desired_Depth;
        brain_B.DesiredDepth = brain_B.Constant;
        brain_B.DesiredHeading = 0.0;
        brain_DWork.Done = 0.0;
        brain_B.State = 3;
        brain_B.CameraPosition = 2;

        /* Simulink Function 'MakeHSVImage': '<S7>:1215' */
        for (outStep = 0; outStep < 19200; outStep++) {
          brain_B.H1[outStep] = brain_B.Resize[outStep];
          brain_B.S1[outStep] = brain_B.Resize1[outStep];
          brain_B.V1[outStep] = brain_B.Resize2[outStep];
        }

        StateFlowFunctionsFollowOnePath(brain_B.H1, brain_B.S1, brain_B.V1,
          &brain_B.StateFlowFunctionsFollowOnePa_g);
      } else if (brain_DWork.OperationalState == 6) {
        /* Transition: '<S7>:1280' */
        /* Exit 'GetInCorrectState': '<S7>:1263' */
        /* Entry 'Buoy': '<S7>:1220' */
        brain_DWork.is_StateFlowFunctions = brain_IN_Buoy;

        /* Transition: '<S7>:1221' */
        /* Entry 'FindBuoy': '<S7>:1224' */
        brain_DWork.is_Buoy = brain_IN_FindBuoy;
        brain_DWork.OldObstacle = FALSE;
        brain_B.CameraPosition = 0;
        brain_B.State = 4;
        brain_DWork.BuoyCount = 0.0;
        brain_DWork.BuoyDone = 0.0;
        brain_B.DesiredDepth = 5.0;
      } else {
        if (brain_DWork.OperationalState == 7) {
          /* Transition: '<S7>:1281' */
          /* Exit 'GetInCorrectState': '<S7>:1263' */
          /* Entry 'Finish': '<S7>:1259' */
          brain_DWork.is_StateFlowFunctions = brain_IN_Finish;
          brain_B.State = 6;
          brain_B.Left = 0;
          brain_B.Right = 0;
          brain_B.Vertical = 0;
        }
      }
      break;

     case brain_IN_NotRunning:
      /* During 'NotRunning': '<S7>:727' */
      if (brain_DWork.OperationalState != 0) {
        /* Transition: '<S7>:1265' */
        /* Exit 'NotRunning': '<S7>:727' */
        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
      }
      break;

     case brain_IN_Start:
      /* During 'Start': '<S7>:1145' */
      if (brain_DWork.OperationalState != 3) {
        /* Transition: '<S7>:1270' */
        /* Exit 'Start': '<S7>:1145' */
        brain_B.DesiredHeading = brain_U.CurrentHeading;

        /* Entry 'GetInCorrectState': '<S7>:1263' */
        brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
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

        /* Constant: '<S15>/Constant' */
        brain_B.Constant = brain_P.Track_Desired_Depth;
        brain_B.DesiredDepth = brain_B.Constant;
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
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[0] =
      -1.5707963267948966E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[1] =
      -1.5533430342749532E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[2] =
      -1.5358897417550099E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[3] =
      -1.5184364492350666E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[4] =
      -1.5009831567151235E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[5] =
      -1.4835298641951802E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[6] =
      -1.4660765716752369E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[7] =
      -1.4486232791552935E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[8] =
      -1.4311699866353502E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[9] =
      -1.4137166941154069E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[10] =
      -1.3962634015954636E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[11] =
      -1.3788101090755203E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[12] =
      -1.3613568165555769E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[13] =
      -1.3439035240356338E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[14] =
      -1.3264502315156905E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[15] =
      -1.3089969389957472E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[16] =
      -1.2915436464758039E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[17] =
      -1.2740903539558606E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[18] =
      -1.2566370614359172E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[19] =
      -1.2391837689159739E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[20] =
      -1.2217304763960306E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[21] =
      -1.2042771838760873E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[22] =
      -1.1868238913561442E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[23] =
      -1.1693705988362009E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[24] =
      -1.1519173063162575E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[25] =
      -1.1344640137963142E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[26] =
      -1.1170107212763709E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[27] =
      -1.0995574287564276E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[28] =
      -1.0821041362364843E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[29] =
      -1.0646508437165410E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[30] =
      -1.0471975511965976E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[31] =
      -1.0297442586766545E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[32] =
      -1.0122909661567112E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[33] =
      -9.9483767363676789E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[34] =
      -9.7738438111682457E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[35] =
      -9.5993108859688125E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[36] =
      -9.4247779607693793E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[37] =
      -9.2502450355699462E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[38] =
      -9.0757121103705141E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[39] =
      -8.9011791851710809E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[40] =
      -8.7266462599716477E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[41] =
      -8.5521133347722145E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[42] =
      -8.3775804095727824E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[43] =
      -8.2030474843733492E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[44] =
      -8.0285145591739160E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[45] =
      -7.8539816339744828E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[46] =
      -7.6794487087750496E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[47] =
      -7.5049157835756175E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[48] =
      -7.3303828583761843E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[49] =
      -7.1558499331767511E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[50] =
      -6.9813170079773179E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[51] =
      -6.8067840827778847E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[52] =
      -6.6322511575784526E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[53] =
      -6.4577182323790194E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[54] =
      -6.2831853071795862E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[55] =
      -6.1086523819801530E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[56] =
      -5.9341194567807209E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[57] =
      -5.7595865315812877E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[58] =
      -5.5850536063818546E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[59] =
      -5.4105206811824214E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[60] =
      -5.2359877559829882E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[61] =
      -5.0614548307835561E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[62] =
      -4.8869219055841229E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[63] =
      -4.7123889803846897E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[64] =
      -4.5378560551852570E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[65] =
      -4.3633231299858238E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[66] =
      -4.1887902047863912E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[67] =
      -4.0142572795869580E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[68] =
      -3.8397243543875248E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[69] =
      -3.6651914291880922E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[70] =
      -3.4906585039886590E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[71] =
      -3.3161255787892263E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[72] =
      -3.1415926535897931E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[73] =
      -2.9670597283903605E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[74] =
      -2.7925268031909273E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[75] =
      -2.6179938779914941E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[76] =
      -2.4434609527920614E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[77] =
      -2.2689280275926285E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[78] =
      -2.0943951023931956E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[79] =
      -1.9198621771937624E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[80] =
      -1.7453292519943295E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[81] =
      -1.5707963267948966E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[82] =
      -1.3962634015954636E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[83] =
      -1.2217304763960307E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[84] =
      -1.0471975511965978E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[85] =
      -8.7266462599716474E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[86] =
      -6.9813170079773182E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[87] =
      -5.2359877559829890E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[88] =
      -3.4906585039886591E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[89] =
      -1.7453292519943295E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[90] = 0.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[91] =
      1.7453292519943295E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[92] =
      3.4906585039886591E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[93] =
      5.2359877559829890E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[94] =
      6.9813170079773182E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[95] =
      8.7266462599716474E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[96] =
      1.0471975511965978E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[97] =
      1.2217304763960307E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[98] =
      1.3962634015954636E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[99] =
      1.5707963267948966E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[100] =
      1.7453292519943295E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[101] =
      1.9198621771937624E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[102] =
      2.0943951023931956E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[103] =
      2.2689280275926285E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[104] =
      2.4434609527920614E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[105] =
      2.6179938779914941E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[106] =
      2.7925268031909273E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[107] =
      2.9670597283903605E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[108] =
      3.1415926535897931E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[109] =
      3.3161255787892263E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[110] =
      3.4906585039886590E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[111] =
      3.6651914291880922E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[112] =
      3.8397243543875248E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[113] =
      4.0142572795869580E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[114] =
      4.1887902047863912E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[115] =
      4.3633231299858238E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[116] =
      4.5378560551852570E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[117] =
      4.7123889803846897E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[118] =
      4.8869219055841229E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[119] =
      5.0614548307835561E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[120] =
      5.2359877559829882E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[121] =
      5.4105206811824214E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[122] =
      5.5850536063818546E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[123] =
      5.7595865315812877E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[124] =
      5.9341194567807209E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[125] =
      6.1086523819801530E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[126] =
      6.2831853071795862E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[127] =
      6.4577182323790194E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[128] =
      6.6322511575784526E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[129] =
      6.8067840827778847E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[130] =
      6.9813170079773179E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[131] =
      7.1558499331767511E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[132] =
      7.3303828583761843E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[133] =
      7.5049157835756175E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[134] =
      7.6794487087750496E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[135] =
      7.8539816339744828E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[136] =
      8.0285145591739160E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[137] =
      8.2030474843733492E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[138] =
      8.3775804095727824E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[139] =
      8.5521133347722145E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[140] =
      8.7266462599716477E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[141] =
      8.9011791851710809E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[142] =
      9.0757121103705141E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[143] =
      9.2502450355699462E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[144] =
      9.4247779607693793E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[145] =
      9.5993108859688125E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[146] =
      9.7738438111682457E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[147] =
      9.9483767363676789E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[148] =
      1.0122909661567112E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[149] =
      1.0297442586766545E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[150] =
      1.0471975511965976E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[151] =
      1.0646508437165410E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[152] =
      1.0821041362364843E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[153] =
      1.0995574287564276E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[154] =
      1.1170107212763709E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[155] =
      1.1344640137963142E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[156] =
      1.1519173063162575E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[157] =
      1.1693705988362009E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[158] =
      1.1868238913561442E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[159] =
      1.2042771838760873E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[160] =
      1.2217304763960306E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[161] =
      1.2391837689159739E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[162] =
      1.2566370614359172E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[163] =
      1.2740903539558606E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[164] =
      1.2915436464758039E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[165] =
      1.3089969389957472E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[166] =
      1.3264502315156905E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[167] =
      1.3439035240356338E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[168] =
      1.3613568165555769E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[169] =
      1.3788101090755203E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[170] =
      1.3962634015954636E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[171] =
      1.4137166941154069E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[172] =
      1.4311699866353502E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[173] =
      1.4486232791552935E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[174] =
      1.4660765716752369E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[175] =
      1.4835298641951802E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[176] =
      1.5009831567151235E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[177] =
      1.5184364492350666E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[178] =
      1.5358897417550099E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2[179] =
      1.5533430342749532E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[0] = -143.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[1] = -142.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[2] = -141.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[3] = -140.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[4] = -139.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[5] = -138.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[6] = -137.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[7] = -136.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[8] = -135.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[9] = -134.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[10] = -133.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[11] = -132.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[12] = -131.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[13] = -130.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[14] = -129.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[15] = -128.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[16] = -127.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[17] = -126.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[18] = -125.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[19] = -124.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[20] = -123.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[21] = -122.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[22] = -121.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[23] = -120.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[24] = -119.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[25] = -118.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[26] = -117.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[27] = -116.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[28] = -115.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[29] = -114.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[30] = -113.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[31] = -112.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[32] = -111.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[33] = -110.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[34] = -109.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[35] = -108.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[36] = -107.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[37] = -106.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[38] = -105.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[39] = -104.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[40] = -103.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[41] = -102.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[42] = -101.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[43] = -100.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[44] = -99.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[45] = -98.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[46] = -97.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[47] = -96.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[48] = -95.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[49] = -94.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[50] = -93.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[51] = -92.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[52] = -91.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[53] = -90.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[54] = -89.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[55] = -88.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[56] = -87.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[57] = -86.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[58] = -85.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[59] = -84.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[60] = -83.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[61] = -82.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[62] = -81.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[63] = -80.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[64] = -79.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[65] = -78.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[66] = -77.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[67] = -76.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[68] = -75.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[69] = -74.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[70] = -73.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[71] = -72.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[72] = -71.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[73] = -70.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[74] = -69.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[75] = -68.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[76] = -67.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[77] = -66.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[78] = -65.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[79] = -64.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[80] = -63.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[81] = -62.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[82] = -61.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[83] = -60.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[84] = -59.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[85] = -58.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[86] = -57.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[87] = -56.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[88] = -55.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[89] = -54.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[90] = -53.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[91] = -52.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[92] = -51.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[93] = -50.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[94] = -49.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[95] = -48.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[96] = -47.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[97] = -46.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[98] = -45.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[99] = -44.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[100] = -43.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[101] = -42.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[102] = -41.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[103] = -40.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[104] = -39.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[105] = -38.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[106] = -37.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[107] = -36.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[108] = -35.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[109] = -34.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[110] = -33.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[111] = -32.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[112] = -31.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[113] = -30.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[114] = -29.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[115] = -28.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[116] = -27.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[117] = -26.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[118] = -25.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[119] = -24.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[120] = -23.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[121] = -22.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[122] = -21.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[123] = -20.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[124] = -19.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[125] = -18.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[126] = -17.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[127] = -16.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[128] = -15.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[129] = -14.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[130] = -13.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[131] = -12.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[132] = -11.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[133] = -10.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[134] = -9.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[135] = -8.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[136] = -7.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[137] = -6.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[138] = -5.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[139] = -4.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[140] = -3.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[141] = -2.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[142] = -1.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[143] = 0.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[144] = 1.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[145] = 2.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[146] = 3.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[147] = 4.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[148] = 5.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[149] = 6.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[150] = 7.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[151] = 8.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[152] = 9.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[153] = 10.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[154] = 11.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[155] = 12.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[156] = 13.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[157] = 14.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[158] = 15.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[159] = 16.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[160] = 17.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[161] = 18.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[162] = 19.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[163] = 20.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[164] = 21.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[165] = 22.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[166] = 23.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[167] = 24.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[168] = 25.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[169] = 26.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[170] = 27.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[171] = 28.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[172] = 29.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[173] = 30.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[174] = 31.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[175] = 32.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[176] = 33.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[177] = 34.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[178] = 35.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[179] = 36.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[180] = 37.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[181] = 38.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[182] = 39.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[183] = 40.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[184] = 41.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[185] = 42.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[186] = 43.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[187] = 44.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[188] = 45.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[189] = 46.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[190] = 47.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[191] = 48.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[192] = 49.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[193] = 50.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[194] = 51.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[195] = 52.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[196] = 53.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[197] = 54.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[198] = 55.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[199] = 56.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[200] = 57.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[201] = 58.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[202] = 59.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[203] = 60.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[204] = 61.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[205] = 62.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[206] = 63.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[207] = 64.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[208] = 65.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[209] = 66.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[210] = 67.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[211] = 68.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[212] = 69.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[213] = 70.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[214] = 71.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[215] = 72.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[216] = 73.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[217] = 74.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[218] = 75.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[219] = 76.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[220] = 77.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[221] = 78.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[222] = 79.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[223] = 80.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[224] = 81.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[225] = 82.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[226] = 83.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[227] = 84.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[228] = 85.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[229] = 86.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[230] = 87.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[231] = 88.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[232] = 89.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[233] = 90.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[234] = 91.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[235] = 92.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[236] = 93.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[237] = 94.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[238] = 95.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[239] = 96.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[240] = 97.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[241] = 98.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[242] = 99.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[243] = 100.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[244] = 101.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[245] = 102.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[246] = 103.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[247] = 104.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[248] = 105.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[249] = 106.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[250] = 107.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[251] = 108.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[252] = 109.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[253] = 110.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[254] = 111.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[255] = 112.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[256] = 113.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[257] = 114.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[258] = 115.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[259] = 116.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[260] = 117.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[261] = 118.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[262] = 119.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[263] = 120.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[264] = 121.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[265] = 122.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[266] = 123.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[267] = 124.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[268] = 125.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[269] = 126.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[270] = 127.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[271] = 128.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[272] = 129.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[273] = 130.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[274] = 131.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[275] = 132.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[276] = 133.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[277] = 134.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[278] = 135.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[279] = 136.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[280] = 137.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[281] = 138.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[282] = 139.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[283] = 140.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[284] = 141.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[285] = 142.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3[286] = 143.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[0] =
      -1.5707963267948966E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[1] =
      -1.5533430342749532E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[2] =
      -1.5358897417550099E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[3] =
      -1.5184364492350666E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[4] =
      -1.5009831567151235E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[5] =
      -1.4835298641951802E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[6] =
      -1.4660765716752369E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[7] =
      -1.4486232791552935E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[8] =
      -1.4311699866353502E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[9] =
      -1.4137166941154069E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[10] =
      -1.3962634015954636E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[11] =
      -1.3788101090755203E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[12] =
      -1.3613568165555769E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[13] =
      -1.3439035240356338E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[14] =
      -1.3264502315156905E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[15] =
      -1.3089969389957472E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[16] =
      -1.2915436464758039E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[17] =
      -1.2740903539558606E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[18] =
      -1.2566370614359172E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[19] =
      -1.2391837689159739E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[20] =
      -1.2217304763960306E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[21] =
      -1.2042771838760873E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[22] =
      -1.1868238913561442E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[23] =
      -1.1693705988362009E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[24] =
      -1.1519173063162575E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[25] =
      -1.1344640137963142E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[26] =
      -1.1170107212763709E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[27] =
      -1.0995574287564276E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[28] =
      -1.0821041362364843E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[29] =
      -1.0646508437165410E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[30] =
      -1.0471975511965976E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[31] =
      -1.0297442586766545E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[32] =
      -1.0122909661567112E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[33] =
      -9.9483767363676789E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[34] =
      -9.7738438111682457E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[35] =
      -9.5993108859688125E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[36] =
      -9.4247779607693793E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[37] =
      -9.2502450355699462E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[38] =
      -9.0757121103705141E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[39] =
      -8.9011791851710809E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[40] =
      -8.7266462599716477E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[41] =
      -8.5521133347722145E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[42] =
      -8.3775804095727824E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[43] =
      -8.2030474843733492E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[44] =
      -8.0285145591739160E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[45] =
      -7.8539816339744828E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[46] =
      -7.6794487087750496E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[47] =
      -7.5049157835756175E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[48] =
      -7.3303828583761843E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[49] =
      -7.1558499331767511E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[50] =
      -6.9813170079773179E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[51] =
      -6.8067840827778847E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[52] =
      -6.6322511575784526E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[53] =
      -6.4577182323790194E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[54] =
      -6.2831853071795862E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[55] =
      -6.1086523819801530E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[56] =
      -5.9341194567807209E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[57] =
      -5.7595865315812877E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[58] =
      -5.5850536063818546E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[59] =
      -5.4105206811824214E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[60] =
      -5.2359877559829882E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[61] =
      -5.0614548307835561E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[62] =
      -4.8869219055841229E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[63] =
      -4.7123889803846897E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[64] =
      -4.5378560551852570E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[65] =
      -4.3633231299858238E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[66] =
      -4.1887902047863912E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[67] =
      -4.0142572795869580E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[68] =
      -3.8397243543875248E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[69] =
      -3.6651914291880922E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[70] =
      -3.4906585039886590E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[71] =
      -3.3161255787892263E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[72] =
      -3.1415926535897931E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[73] =
      -2.9670597283903605E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[74] =
      -2.7925268031909273E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[75] =
      -2.6179938779914941E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[76] =
      -2.4434609527920614E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[77] =
      -2.2689280275926285E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[78] =
      -2.0943951023931956E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[79] =
      -1.9198621771937624E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[80] =
      -1.7453292519943295E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[81] =
      -1.5707963267948966E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[82] =
      -1.3962634015954636E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[83] =
      -1.2217304763960307E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[84] =
      -1.0471975511965978E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[85] =
      -8.7266462599716474E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[86] =
      -6.9813170079773182E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[87] =
      -5.2359877559829890E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[88] =
      -3.4906585039886591E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[89] =
      -1.7453292519943295E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[90] = 0.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[91] =
      1.7453292519943295E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[92] =
      3.4906585039886591E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[93] =
      5.2359877559829890E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[94] =
      6.9813170079773182E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[95] =
      8.7266462599716474E-02;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[96] =
      1.0471975511965978E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[97] =
      1.2217304763960307E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[98] =
      1.3962634015954636E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[99] =
      1.5707963267948966E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[100] =
      1.7453292519943295E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[101] =
      1.9198621771937624E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[102] =
      2.0943951023931956E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[103] =
      2.2689280275926285E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[104] =
      2.4434609527920614E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[105] =
      2.6179938779914941E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[106] =
      2.7925268031909273E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[107] =
      2.9670597283903605E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[108] =
      3.1415926535897931E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[109] =
      3.3161255787892263E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[110] =
      3.4906585039886590E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[111] =
      3.6651914291880922E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[112] =
      3.8397243543875248E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[113] =
      4.0142572795869580E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[114] =
      4.1887902047863912E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[115] =
      4.3633231299858238E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[116] =
      4.5378560551852570E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[117] =
      4.7123889803846897E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[118] =
      4.8869219055841229E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[119] =
      5.0614548307835561E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[120] =
      5.2359877559829882E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[121] =
      5.4105206811824214E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[122] =
      5.5850536063818546E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[123] =
      5.7595865315812877E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[124] =
      5.9341194567807209E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[125] =
      6.1086523819801530E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[126] =
      6.2831853071795862E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[127] =
      6.4577182323790194E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[128] =
      6.6322511575784526E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[129] =
      6.8067840827778847E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[130] =
      6.9813170079773179E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[131] =
      7.1558499331767511E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[132] =
      7.3303828583761843E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[133] =
      7.5049157835756175E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[134] =
      7.6794487087750496E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[135] =
      7.8539816339744828E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[136] =
      8.0285145591739160E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[137] =
      8.2030474843733492E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[138] =
      8.3775804095727824E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[139] =
      8.5521133347722145E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[140] =
      8.7266462599716477E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[141] =
      8.9011791851710809E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[142] =
      9.0757121103705141E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[143] =
      9.2502450355699462E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[144] =
      9.4247779607693793E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[145] =
      9.5993108859688125E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[146] =
      9.7738438111682457E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[147] =
      9.9483767363676789E-01;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[148] =
      1.0122909661567112E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[149] =
      1.0297442586766545E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[150] =
      1.0471975511965976E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[151] =
      1.0646508437165410E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[152] =
      1.0821041362364843E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[153] =
      1.0995574287564276E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[154] =
      1.1170107212763709E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[155] =
      1.1344640137963142E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[156] =
      1.1519173063162575E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[157] =
      1.1693705988362009E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[158] =
      1.1868238913561442E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[159] =
      1.2042771838760873E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[160] =
      1.2217304763960306E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[161] =
      1.2391837689159739E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[162] =
      1.2566370614359172E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[163] =
      1.2740903539558606E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[164] =
      1.2915436464758039E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[165] =
      1.3089969389957472E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[166] =
      1.3264502315156905E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[167] =
      1.3439035240356338E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[168] =
      1.3613568165555769E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[169] =
      1.3788101090755203E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[170] =
      1.3962634015954636E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[171] =
      1.4137166941154069E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[172] =
      1.4311699866353502E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[173] =
      1.4486232791552935E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[174] =
      1.4660765716752369E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[175] =
      1.4835298641951802E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[176] =
      1.5009831567151235E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[177] =
      1.5184364492350666E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[178] =
      1.5358897417550099E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o2_h[179] =
      1.5533430342749532E+00;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[0] = -143.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[1] = -142.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[2] = -141.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[3] = -140.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[4] = -139.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[5] = -138.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[6] = -137.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[7] = -136.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[8] = -135.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[9] = -134.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[10] = -133.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[11] = -132.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[12] = -131.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[13] = -130.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[14] = -129.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[15] = -128.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[16] = -127.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[17] = -126.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[18] = -125.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[19] = -124.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[20] = -123.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[21] = -122.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[22] = -121.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[23] = -120.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[24] = -119.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[25] = -118.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[26] = -117.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[27] = -116.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[28] = -115.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[29] = -114.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[30] = -113.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[31] = -112.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[32] = -111.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[33] = -110.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[34] = -109.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[35] = -108.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[36] = -107.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[37] = -106.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[38] = -105.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[39] = -104.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[40] = -103.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[41] = -102.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[42] = -101.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[43] = -100.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[44] = -99.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[45] = -98.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[46] = -97.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[47] = -96.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[48] = -95.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[49] = -94.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[50] = -93.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[51] = -92.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[52] = -91.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[53] = -90.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[54] = -89.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[55] = -88.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[56] = -87.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[57] = -86.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[58] = -85.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[59] = -84.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[60] = -83.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[61] = -82.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[62] = -81.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[63] = -80.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[64] = -79.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[65] = -78.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[66] = -77.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[67] = -76.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[68] = -75.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[69] = -74.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[70] = -73.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[71] = -72.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[72] = -71.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[73] = -70.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[74] = -69.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[75] = -68.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[76] = -67.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[77] = -66.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[78] = -65.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[79] = -64.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[80] = -63.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[81] = -62.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[82] = -61.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[83] = -60.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[84] = -59.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[85] = -58.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[86] = -57.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[87] = -56.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[88] = -55.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[89] = -54.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[90] = -53.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[91] = -52.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[92] = -51.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[93] = -50.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[94] = -49.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[95] = -48.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[96] = -47.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[97] = -46.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[98] = -45.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[99] = -44.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[100] = -43.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[101] = -42.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[102] = -41.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[103] = -40.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[104] = -39.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[105] = -38.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[106] = -37.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[107] = -36.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[108] = -35.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[109] = -34.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[110] = -33.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[111] = -32.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[112] = -31.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[113] = -30.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[114] = -29.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[115] = -28.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[116] = -27.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[117] = -26.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[118] = -25.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[119] = -24.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[120] = -23.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[121] = -22.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[122] = -21.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[123] = -20.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[124] = -19.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[125] = -18.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[126] = -17.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[127] = -16.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[128] = -15.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[129] = -14.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[130] = -13.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[131] = -12.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[132] = -11.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[133] = -10.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[134] = -9.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[135] = -8.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[136] = -7.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[137] = -6.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[138] = -5.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[139] = -4.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[140] = -3.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[141] = -2.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[142] = -1.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[143] = 0.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[144] = 1.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[145] = 2.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[146] = 3.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[147] = 4.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[148] = 5.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[149] = 6.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[150] = 7.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[151] = 8.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[152] = 9.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[153] = 10.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[154] = 11.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[155] = 12.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[156] = 13.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[157] = 14.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[158] = 15.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[159] = 16.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[160] = 17.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[161] = 18.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[162] = 19.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[163] = 20.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[164] = 21.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[165] = 22.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[166] = 23.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[167] = 24.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[168] = 25.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[169] = 26.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[170] = 27.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[171] = 28.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[172] = 29.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[173] = 30.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[174] = 31.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[175] = 32.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[176] = 33.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[177] = 34.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[178] = 35.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[179] = 36.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[180] = 37.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[181] = 38.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[182] = 39.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[183] = 40.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[184] = 41.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[185] = 42.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[186] = 43.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[187] = 44.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[188] = 45.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[189] = 46.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[190] = 47.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[191] = 48.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[192] = 49.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[193] = 50.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[194] = 51.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[195] = 52.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[196] = 53.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[197] = 54.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[198] = 55.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[199] = 56.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[200] = 57.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[201] = 58.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[202] = 59.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[203] = 60.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[204] = 61.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[205] = 62.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[206] = 63.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[207] = 64.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[208] = 65.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[209] = 66.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[210] = 67.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[211] = 68.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[212] = 69.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[213] = 70.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[214] = 71.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[215] = 72.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[216] = 73.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[217] = 74.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[218] = 75.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[219] = 76.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[220] = 77.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[221] = 78.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[222] = 79.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[223] = 80.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[224] = 81.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[225] = 82.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[226] = 83.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[227] = 84.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[228] = 85.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[229] = 86.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[230] = 87.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[231] = 88.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[232] = 89.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[233] = 90.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[234] = 91.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[235] = 92.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[236] = 93.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[237] = 94.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[238] = 95.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[239] = 96.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[240] = 97.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[241] = 98.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[242] = 99.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[243] = 100.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[244] = 101.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[245] = 102.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[246] = 103.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[247] = 104.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[248] = 105.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[249] = 106.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[250] = 107.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[251] = 108.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[252] = 109.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[253] = 110.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[254] = 111.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[255] = 112.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[256] = 113.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[257] = 114.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[258] = 115.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[259] = 116.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[260] = 117.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[261] = 118.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[262] = 119.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[263] = 120.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[264] = 121.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[265] = 122.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[266] = 123.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[267] = 124.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[268] = 125.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[269] = 126.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[270] = 127.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[271] = 128.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[272] = 129.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[273] = 130.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[274] = 131.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[275] = 132.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[276] = 133.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[277] = 134.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[278] = 135.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[279] = 136.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[280] = 137.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[281] = 138.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[282] = 139.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[283] = 140.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[284] = 141.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[285] = 142.0;
    brain_B.StateFlowFunctionsFollowOneP_ht.HoughTransform_o3_p[286] = 143.0;
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

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  brain_InitializeDataMapInfo(brain_M);

  {
    int32_T idxNHood;
    int32_T idxOffsets;
    int32_T nhIdx;
    int32_T idxNHood_0;
    int32_T idxOffsets_0;
    int32_T nhIdx_0;
    int32_T m;

    /* Start for Stateflow: '<Root>/StateFlow Functions' incorporates:
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoy.ApproachBuoy.Buoy'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoy.GetBuoyForwardVelocity'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
     *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
     */

    /* Start for S-Function (svipmorphop): '<S8>/Dilation' */
    idxOffsets = 0;
    idxNHood_0 = 0;
    idxNHood = 4;
    for (nhIdx_0 = 0; nhIdx_0 < 2; nhIdx_0++) {
      for (m = 0; m < 2; m++) {
        idxNHood--;
        if (brain_ConstP.pooled20[idxNHood]) {
          brain_DWork.Dilation_DILATE_OFF_DW_h[idxOffsets] = nhIdx_0 * 123 + m;
          idxNHood_0++;
          idxOffsets++;
        }
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW_m = idxNHood_0;

    /* Start for S-Function (svipmorphop): '<S8>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 1; nhIdx_0 = 1) {
      for (nhIdx = 0; nhIdx < 4; nhIdx++) {
        if (brain_ConstP.pooled21[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_p[idxOffsets] = nhIdx;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_e[0] = idxOffsets_0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 4; nhIdx_0++) {
      for (nhIdx = 0; nhIdx < 1; nhIdx = 1) {
        if (brain_ConstP.pooled21[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW_p[idxOffsets] = nhIdx_0 * 127;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW_e[1] = idxOffsets_0;

    /* Start for S-Function (svipmorphop): '<S31>/Dilation' */
    idxOffsets_0 = 0;
    idxNHood = 0;
    idxNHood_0 = 4;
    for (nhIdx = 0; nhIdx < 2; nhIdx++) {
      for (m = 0; m < 2; m++) {
        idxNHood_0--;
        if (brain_ConstP.pooled20[idxNHood_0]) {
          brain_DWork.Dilation_DILATE_OFF_DW[idxOffsets_0] = nhIdx * 123 + m;
          idxNHood++;
          idxOffsets_0++;
        }
      }
    }

    brain_DWork.Dilation_NUMNONZ_DW = idxNHood;

    /* Start for S-Function (svipmorphop): '<S31>/Erosion' */
    idxNHood = 0;
    idxOffsets = 0;
    idxOffsets_0 = 0;
    for (nhIdx_0 = 0; nhIdx_0 < 1; nhIdx_0 = 1) {
      for (nhIdx = 0; nhIdx < 4; nhIdx++) {
        if (brain_ConstP.pooled21[idxNHood]) {
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
        if (brain_ConstP.pooled21[idxNHood]) {
          brain_DWork.Erosion_ERODE_OFF_DW[idxOffsets] = nhIdx_0 * 127;
          idxOffsets_0++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    brain_DWork.Erosion_NUMNONZ_DW[1] = idxOffsets_0;

    /* Start for If: '<S17>/If' */
    brain_DWork.If_ActiveSubsystem = -1;

    /* Start for Constant: '<S10>/Constant' */
    brain_B.Constant_i = brain_P.Heading_Forward_Velocity;

    /* Start for Constant: '<S18>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Heading_Forward_Velocity;

    /* Start for Constant: '<S15>/Constant' */
    brain_B.Constant = brain_P.Track_Desired_Depth;
  }

  /* InitializeConditions for Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoy.ApproachBuoy.Buoy'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoy.GetBuoyForwardVelocity'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   */
  brain_DWork.is_active_StateFlowFunctions = 0U;
  brain_DWork.is_StateFlowFunctions = 0U;
  brain_DWork.is_Buoy = 0U;
  brain_DWork.is_GoAroundBuoy = 0U;
  brain_DWork.is_FollowOnePath = 0U;
  brain_DWork.is_OnePath = 0U;
  brain_DWork.is_active_StateManagement = 0U;
  brain_DWork.is_StateManagement = 0U;
  brain_DWork.is_Running = 0U;
  brain_DWork.is_Autonomous = 0U;
  brain_DWork.is_active_c1_brain = 0U;
  brain_DWork.count = 0.0;
  brain_DWork.OldObstacle = FALSE;
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
  brain_DWork.OperationalState = 0;
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
  brain_DWork.presentTicks = 0U;
  brain_DWork.elapsedTicks = 0U;
  brain_DWork.previousTicks = 0U;
  brain_DWork.StateFlowFunctionsBuoyApproac_l = brain_M->Timing.clockTick0;
  brain_DWork.StateFlowFunctionsMaintainHea_m = brain_M->Timing.clockTick0;
  brain_DWork.StateFlowFunctionsFollowOnePa_e = brain_M->Timing.clockTick0;
  brain_DWork.StateFlowFunctionsMaintainDep_k = brain_M->Timing.clockTick0;

  /* Enable for Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoy.ApproachBuoy.Buoy'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.Buoy.GetBuoyForwardVelocity'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  Enable for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   */
  brain_DWork.presentTicks = brain_M->Timing.clockTick0;
  brain_DWork.previousTicks = brain_DWork.presentTicks;
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
