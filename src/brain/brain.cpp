/*
 * File: brain.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.384
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Wed Jun 23 16:07:43 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Wed Jun 23 16:07:47 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Named constants for Stateflow: '<Root>/StateFlow Functions' */
#define brain_IN_ApproachBuoys         (1U)
#define brain_IN_ApproachFirstBuoy     (1U)
#define brain_IN_ApproachSecondBuoy    (2U)
#define brain_IN_Autonomous            (1U)
#define brain_IN_Buoy                  (1U)
#define brain_IN_Buoys                 (1U)
#define brain_IN_CenterOver            (1U)
#define brain_IN_ChooseState           (2U)
#define brain_IN_ControlledRC          (2U)
#define brain_IN_Done                  (2U)
#define brain_IN_FindBuoys             (2U)
#define brain_IN_FindSecondBuoy        (3U)
#define brain_IN_Finish                (3U)
#define brain_IN_FollowOnePath         (4U)
#define brain_IN_FollowOnePath1        (5U)
#define brain_IN_GetDirections         (3U)
#define brain_IN_GetInCorrectState     (5U)
#define brain_IN_Initialize            (1U)
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
static void brain_conv2(const real32_T eml_arg1[19200], const real32_T eml_arg2
  [9], real32_T eml_c[18644]);
static void brain_c27_brain(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB);

/* Forward declaration for local functions */
static void brain_max(const real_T eml_varargin_1[51660], real_T eml_maxval[180],
                      real_T eml_indx[180]);
static void brain_max_b(const real_T eml_varargin_1[180], real_T *eml_maxval,
  real_T *eml_indx);
static void brain_c11_brain(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);

/* Forward declaration for local functions */
static void brain_max_o(const real_T eml_varargin_1[4], real_T *eml_maxval,
  real_T *eml_indx);

/* Forward declaration for local functions */
static void brain_enter_internal_Buoys(void);
static real_T brain_countareas(real_T sf_Size, real_T sf_count1);
static real_T brain_Turn45Degrees(real_T sf_CHeading, real_T sf_TurnD);
static void brain_ApproachBuoys(void);
static void brain_Outputs(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3);
static void brain_c3_brain(void);
static real_T brain_countimages_m(real_T sf_Image1, real_T sf_OldImage, real_T
  sf_count1);
static void brain_Outputs_f(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3);
static void brain_c5_brain(void);
static void brain_min(const real_T eml_varargin_1[3], real_T *eml_minval, real_T
                      *eml_indx);
static void brain_exit_internal_Buoys(void);
static void brain_ControlledRC(void);
static void brain_enter_internal_OnePath(void);
static void brain_refp1_cos(real_T eml_x[19200]);
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
static void brain_FollowOnePath(void);
static void brain_GetInCorrectState(void);
static void brain_Start(void);
static real_T brain_countimages(real_T sf_Image, real_T sf_OldImage, real_T
  sf_count1);
static void brain_ValidationGate(void);
static void brain_StateFlowFunctions(void);

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApproach(const real_T rtu_L_B[3], const real_T
  rtu_M_B[3], const real_T rtu_R_B[3], rtB_StateFlowFunctionsBuoysAppr *localB)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T Xf;
  real_T eml_min_dist;
  real_T eml_min_dist_0;
  real_T eml_dist;

  /* S-Function (svipcolorconv): '<S30>/Color Space  Conversion' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant2'
   */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_dist = 6.0 * brain_P.Buoy1_Hue;
  Xf = (real_T)(uint32_T)(eml_dist - 1.3322676295501878E-15);
  eml_dist -= Xf;
  eml_min_dist = 1.0 - brain_P.Buoy1_Saturation;
  eml_min_dist_0 = 1.0 - brain_P.Buoy1_Saturation * eml_dist;
  eml_dist = brain_P.Buoy1_Saturation * eml_dist + eml_min_dist;
  if (Xf == 0.0) {
    cc = 1.0;
    cc_0 = eml_dist;
    cc_1 = eml_min_dist;
  } else if (Xf == 1.0) {
    cc = eml_min_dist_0;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (Xf == 2.0) {
    cc = eml_min_dist;
    cc_0 = 1.0;
    cc_1 = eml_dist;
  } else if (Xf == 3.0) {
    cc = eml_min_dist;
    cc_0 = eml_min_dist_0;
    cc_1 = 1.0;
  } else if (Xf == 4.0) {
    cc = eml_dist;
    cc_0 = eml_min_dist;
    cc_1 = 1.0;
  } else {
    if (Xf == 5.0) {
      cc = 1.0;
      cc_0 = eml_min_dist;
      cc_1 = eml_min_dist_0;
    }
  }

  if (cc > cc_0) {
    eml_dist = cc;
  } else {
    eml_dist = cc_0;
  }

  if (!(eml_dist > cc_1)) {
    eml_dist = cc_1;
  }

  eml_dist = brain_P.Buoy1_Value / eml_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o3 = eml_dist * cc;
  localB->ColorSpaceConversion_o2 = eml_dist * cc_0;
  localB->ColorSpaceConversion_o1 = eml_dist * cc_1;

  /* S-Function (svipcolorconv): '<S30>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-02) {
    eml_dist = localB->ColorSpaceConversion_o3 / 1.2923054468333255E+01;
  } else {
    eml_dist = rt_pow_snf((localB->ColorSpaceConversion_o3 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-02) {
    eml_min_dist = localB->ColorSpaceConversion_o2 / 1.2923054468333255E+01;
  } else {
    eml_min_dist = rt_pow_snf((localB->ColorSpaceConversion_o2 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-02) {
    eml_min_dist_0 = localB->ColorSpaceConversion_o1 / 1.2923054468333255E+01;
  } else {
    eml_min_dist_0 = rt_pow_snf((localB->ColorSpaceConversion_o1 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  Xf = (4.1239079926596001E-01 * eml_dist + 3.5758433938388001E-01 *
        eml_min_dist) + 1.8048078840182999E-01 * eml_min_dist_0;
  cc = (2.1263900587151000E-01 * eml_dist + 7.1516867876776002E-01 *
        eml_min_dist) + 7.2192315360729994E-02 * eml_min_dist_0;
  eml_dist = (1.9330818715590000E-02 * eml_dist + 1.1919477979463000E-01 *
              eml_min_dist) + 9.5053215224966003E-01 * eml_min_dist_0;

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

  if (eml_dist > 1.0) {
    eml_dist = 1.0;
  } else {
    if (eml_dist < 0.0) {
      eml_dist = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = Xf;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = eml_dist;

  /* Convert from XYZ to L*a*b* */
  eml_dist = localB->ColorSpaceConversion1_o1 / 9.6419865576090003E-01;
  eml_min_dist_0 = localB->ColorSpaceConversion1_o3 / 8.2511648322104003E-01;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_dist > 8.8564516790356311E-03) {
    Xf = rt_pow_snf(eml_dist, 3.3333333333333331E-01);
  } else {
    Xf = 7.7870370370370372E+00 * eml_dist + 1.3793103448275862E-01;
  }

  if (localB->ColorSpaceConversion1_o2 > 8.8564516790356311E-03) {
    eml_min_dist = rt_pow_snf(localB->ColorSpaceConversion1_o2,
      3.3333333333333331E-01);
  } else {
    eml_min_dist = 7.7870370370370372E+00 * localB->ColorSpaceConversion1_o2 +
      1.3793103448275862E-01;
  }

  if (eml_min_dist_0 > 8.8564516790356311E-03) {
    eml_dist = rt_pow_snf(eml_min_dist_0, 3.3333333333333331E-01);
  } else {
    eml_dist = 7.7870370370370372E+00 * eml_min_dist_0 + 1.3793103448275862E-01;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * eml_min_dist - 16.0;
  localB->ColorSpaceConversion1_o2 = (Xf - eml_min_dist) * 500.0;
  localB->ColorSpaceConversion1_o3 = (eml_min_dist - eml_dist) * 200.0;

  /* S-Function (svipcolorconv): '<S32>/Color Space  Conversion' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant2'
   */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_dist = 6.0 * brain_P.Buoy2_Hue;
  Xf = (real_T)(uint32_T)(eml_dist - 1.3322676295501878E-15);
  eml_dist -= Xf;
  eml_min_dist = 1.0 - brain_P.Buoy2_Saturation;
  eml_min_dist_0 = 1.0 - brain_P.Buoy2_Saturation * eml_dist;
  eml_dist = brain_P.Buoy2_Saturation * eml_dist + eml_min_dist;
  if (Xf == 0.0) {
    cc = 1.0;
    cc_0 = eml_dist;
    cc_1 = eml_min_dist;
  } else if (Xf == 1.0) {
    cc = eml_min_dist_0;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (Xf == 2.0) {
    cc = eml_min_dist;
    cc_0 = 1.0;
    cc_1 = eml_dist;
  } else if (Xf == 3.0) {
    cc = eml_min_dist;
    cc_0 = eml_min_dist_0;
    cc_1 = 1.0;
  } else if (Xf == 4.0) {
    cc = eml_dist;
    cc_0 = eml_min_dist;
    cc_1 = 1.0;
  } else {
    if (Xf == 5.0) {
      cc = 1.0;
      cc_0 = eml_min_dist;
      cc_1 = eml_min_dist_0;
    }
  }

  if (cc > cc_0) {
    eml_dist = cc;
  } else {
    eml_dist = cc_0;
  }

  if (!(eml_dist > cc_1)) {
    eml_dist = cc_1;
  }

  eml_dist = brain_P.Buoy2_Value / eml_dist;

  /* assign the results */
  localB->ColorSpaceConversion_o1 = eml_dist * cc;
  localB->ColorSpaceConversion_o2 = eml_dist * cc_0;
  localB->ColorSpaceConversion_o3 = eml_dist * cc_1;

  /* S-Function (svipcolorconv): '<S32>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-02) {
    eml_dist = localB->ColorSpaceConversion_o1 / 1.2923054468333255E+01;
  } else {
    eml_dist = rt_pow_snf((localB->ColorSpaceConversion_o1 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-02) {
    eml_min_dist = localB->ColorSpaceConversion_o2 / 1.2923054468333255E+01;
  } else {
    eml_min_dist = rt_pow_snf((localB->ColorSpaceConversion_o2 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-02) {
    eml_min_dist_0 = localB->ColorSpaceConversion_o3 / 1.2923054468333255E+01;
  } else {
    eml_min_dist_0 = rt_pow_snf((localB->ColorSpaceConversion_o3 +
      5.5000519817226347E-02) / 1.0550005198172263E+00, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  Xf = (4.1239079926596001E-01 * eml_dist + 3.5758433938388001E-01 *
        eml_min_dist) + 1.8048078840182999E-01 * eml_min_dist_0;
  cc = (2.1263900587151000E-01 * eml_dist + 7.1516867876776002E-01 *
        eml_min_dist) + 7.2192315360729994E-02 * eml_min_dist_0;
  eml_dist = (1.9330818715590000E-02 * eml_dist + 1.1919477979463000E-01 *
              eml_min_dist) + 9.5053215224966003E-01 * eml_min_dist_0;

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

  if (eml_dist > 1.0) {
    eml_dist = 1.0;
  } else {
    if (eml_dist < 0.0) {
      eml_dist = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1_n = Xf;
  localB->ColorSpaceConversion1_o2_i = cc;
  localB->ColorSpaceConversion1_o3_m = eml_dist;

  /* Convert from XYZ to L*a*b* */
  eml_dist = localB->ColorSpaceConversion1_o1_n / 9.6419865576090003E-01;
  eml_min_dist_0 = localB->ColorSpaceConversion1_o3_m / 8.2511648322104003E-01;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_dist > 8.8564516790356311E-03) {
    Xf = rt_pow_snf(eml_dist, 3.3333333333333331E-01);
  } else {
    Xf = 7.7870370370370372E+00 * eml_dist + 1.3793103448275862E-01;
  }

  if (localB->ColorSpaceConversion1_o2_i > 8.8564516790356311E-03) {
    eml_min_dist = rt_pow_snf(localB->ColorSpaceConversion1_o2_i,
      3.3333333333333331E-01);
  } else {
    eml_min_dist = 7.7870370370370372E+00 * localB->ColorSpaceConversion1_o2_i +
      1.3793103448275862E-01;
  }

  if (eml_min_dist_0 > 8.8564516790356311E-03) {
    eml_dist = rt_pow_snf(eml_min_dist_0, 3.3333333333333331E-01);
  } else {
    eml_dist = 7.7870370370370372E+00 * eml_min_dist_0 + 1.3793103448275862E-01;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1_n = 116.0 * eml_min_dist - 16.0;
  localB->ColorSpaceConversion1_o2_i = (Xf - eml_min_dist) * 500.0;
  localB->ColorSpaceConversion1_o3_m = (eml_min_dist - eml_dist) * 200.0;

  /* Embedded MATLAB: '<S9>/GetBestColorMatch' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch': '<S31>:1' */
  /*  This function determines which buoys are the best match for the desired colors */
  /* '<S31>:1:5' */
  /* '<S31>:1:6' */
  eml_min_dist = 1000.0;

  /* '<S31>:1:7' */
  eml_min_dist_0 = 1000.0;

  /* '<S31>:1:8' */
  localB->FirstD = 2.0;

  /* '<S31>:1:9' */
  localB->SecondD = 2.0;

  /* '<S31>:1:11' */
  /* '<S31>:1:12' */
  eml_dist = sqrt((rt_pow_snf(rtu_L_B[0] - localB->ColorSpaceConversion1_o1, 2.0)
                   + rt_pow_snf(rtu_L_B[1] - localB->ColorSpaceConversion1_o2,
    2.0)) + rt_pow_snf(rtu_L_B[2] - localB->ColorSpaceConversion1_o3, 2.0));
  if (eml_dist < 1000.0) {
    /* '<S31>:1:13' */
    /* '<S31>:1:14' */
    eml_min_dist = eml_dist;

    /* '<S31>:1:15' */
    localB->FirstD = 1.0;
  }

  /* '<S31>:1:17' */
  eml_dist = sqrt((rt_pow_snf(rtu_L_B[0] - localB->ColorSpaceConversion1_o1_n,
    2.0) + rt_pow_snf(rtu_L_B[1] - localB->ColorSpaceConversion1_o2_i, 2.0)) +
                  rt_pow_snf(rtu_L_B[2] - localB->ColorSpaceConversion1_o3_m,
    2.0));
  if (eml_dist < 1000.0) {
    /* '<S31>:1:18' */
    /* '<S31>:1:19' */
    eml_min_dist_0 = eml_dist;

    /* '<S31>:1:20' */
    localB->SecondD = 1.0;
  }

  /* '<S31>:1:11' */
  /* '<S31>:1:12' */
  eml_dist = sqrt((rt_pow_snf(rtu_M_B[0] - localB->ColorSpaceConversion1_o1, 2.0)
                   + rt_pow_snf(rtu_M_B[1] - localB->ColorSpaceConversion1_o2,
    2.0)) + rt_pow_snf(rtu_M_B[2] - localB->ColorSpaceConversion1_o3, 2.0));
  if (eml_dist < eml_min_dist) {
    /* '<S31>:1:13' */
    /* '<S31>:1:14' */
    eml_min_dist = eml_dist;

    /* '<S31>:1:15' */
    localB->FirstD = 2.0;
  }

  /* '<S31>:1:17' */
  eml_dist = sqrt((rt_pow_snf(rtu_M_B[0] - localB->ColorSpaceConversion1_o1_n,
    2.0) + rt_pow_snf(rtu_M_B[1] - localB->ColorSpaceConversion1_o2_i, 2.0)) +
                  rt_pow_snf(rtu_M_B[2] - localB->ColorSpaceConversion1_o3_m,
    2.0));
  if (eml_dist < eml_min_dist_0) {
    /* '<S31>:1:18' */
    /* '<S31>:1:19' */
    eml_min_dist_0 = eml_dist;

    /* '<S31>:1:20' */
    localB->SecondD = 2.0;
  }

  /* '<S31>:1:11' */
  /* '<S31>:1:12' */
  if (sqrt((rt_pow_snf(rtu_R_B[0] - localB->ColorSpaceConversion1_o1, 2.0) +
            rt_pow_snf(rtu_R_B[1] - localB->ColorSpaceConversion1_o2, 2.0)) +
           rt_pow_snf(rtu_R_B[2] - localB->ColorSpaceConversion1_o3, 2.0)) <
      eml_min_dist) {
    /* '<S31>:1:13' */
    /* '<S31>:1:14' */
    /* '<S31>:1:15' */
    localB->FirstD = 3.0;
  }

  /* '<S31>:1:17' */
  if (sqrt((rt_pow_snf(rtu_R_B[0] - localB->ColorSpaceConversion1_o1_n, 2.0) +
            rt_pow_snf(rtu_R_B[1] - localB->ColorSpaceConversion1_o2_i, 2.0)) +
           rt_pow_snf(rtu_R_B[2] - localB->ColorSpaceConversion1_o3_m, 2.0)) <
      eml_min_dist_0) {
    /* '<S31>:1:18' */
    /* '<S31>:1:19' */
    /* '<S31>:1:20' */
    localB->SecondD = 3.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S10>/Embedded MATLAB Function1'
 *    '<S22>/Embedded MATLAB Function1'
 */
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB)
{
  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function1': '<S34>:1' */
  /*  This function finds the center of an image */
  /* '<S34>:1:6' */
  /* '<S34>:1:7' */
  localB->XCenter = 80.0;
  localB->YCenter = 60.0;
}

/* Initial conditions for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysA_k_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysA_a *localDW)
{
  localDW->StateFlowFunctionsBuoysAppro_my = brain_M->Timing.clockTick0;
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApproa_l(real_T rtu_B_Hue, real_T rtu_B_Sat, real_T
  rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T rtu_Ref_Colors
  [150], real_T rtu_Num_Colors, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsBuoysAp_p *localB, rtDW_StateFlowFunctionsBuoysA_a
  *localDW)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T eml_min_dist;
  real_T eml_i;
  real_T eml_Dist[10];
  boolean_T eml_searchingForNonNaN;
  boolean_T eml_exitg;
  int8_T rtb_index;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  int32_T idx;
  int32_T n;
  uint32_T stackIdx;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  int32_T n_0;
  uint32_T BuoyBlobAnalysis_NUM_PIX_DW[10];
  uint32_T numBlobs;
  int32_T ms;
  int32_T j;
  uint32_T k;
  real_T rtb_Error_o;
  real_T rtb_TSamp_c;
  int32_T rtb_BuoyBlobAnalysis_o1_m[10];
  real_T rtb_BuoyBlobAnalysis_o2_a[20];
  real_T rtb_BuoyBlobAnalysis_o3[10];
  int32_T i;
  localDW->StateFlowFunctionsBuoysApproa_a = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsBuoysAppro_my;
  localDW->StateFlowFunctionsBuoysAppro_my = brain_M->Timing.clockTick0;

  /* S-Function (svipcolorconv): '<S39>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_min_dist = 6.0 * rtu_B_Hue;
  rtb_TSamp_c = (real_T)(uint32_T)(eml_min_dist - 1.3322676295501878E-15);
  eml_min_dist -= rtb_TSamp_c;
  eml_i = 1.0 - rtu_B_Sat;
  rtb_Error_o = 1.0 - rtu_B_Sat * eml_min_dist;
  eml_min_dist = rtu_B_Sat * eml_min_dist + eml_i;
  if (rtb_TSamp_c == 0.0) {
    cc = 1.0;
    cc_0 = eml_min_dist;
    cc_1 = eml_i;
  } else if (rtb_TSamp_c == 1.0) {
    cc = rtb_Error_o;
    cc_0 = 1.0;
    cc_1 = eml_i;
  } else if (rtb_TSamp_c == 2.0) {
    cc = eml_i;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (rtb_TSamp_c == 3.0) {
    cc = eml_i;
    cc_0 = rtb_Error_o;
    cc_1 = 1.0;
  } else if (rtb_TSamp_c == 4.0) {
    cc = eml_min_dist;
    cc_0 = eml_i;
    cc_1 = 1.0;
  } else {
    if (rtb_TSamp_c == 5.0) {
      cc = 1.0;
      cc_0 = eml_i;
      cc_1 = rtb_Error_o;
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

  /* S-Function (svipcolorconv): '<S39>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-02) {
    eml_min_dist = localB->ColorSpaceConversion_o1 / 1.2923054468333255E+01;
  } else {
    eml_min_dist = (localB->ColorSpaceConversion_o1 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    eml_min_dist = rt_pow_snf(eml_min_dist, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-02) {
    eml_i = localB->ColorSpaceConversion_o2 / 1.2923054468333255E+01;
  } else {
    eml_i = (localB->ColorSpaceConversion_o2 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    eml_i = rt_pow_snf(eml_i, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-02) {
    rtb_Error_o = localB->ColorSpaceConversion_o3 / 1.2923054468333255E+01;
  } else {
    rtb_Error_o = (localB->ColorSpaceConversion_o3 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    rtb_Error_o = rt_pow_snf(rtb_Error_o, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  rtb_TSamp_c = (4.1239079926596001E-01 * eml_min_dist + 3.5758433938388001E-01 *
                 eml_i) + 1.8048078840182999E-01 * rtb_Error_o;
  cc = (2.1263900587151000E-01 * eml_min_dist + 7.1516867876776002E-01 * eml_i)
    + 7.2192315360729994E-02 * rtb_Error_o;
  eml_min_dist = (1.9330818715590000E-02 * eml_min_dist + 1.1919477979463000E-01
                  * eml_i) + 9.5053215224966003E-01 * rtb_Error_o;

  /* Make sure that the output is in [0..1] range; clip if necessary */
  if (rtb_TSamp_c > 1.0) {
    rtb_TSamp_c = 1.0;
  } else {
    if (rtb_TSamp_c < 0.0) {
      rtb_TSamp_c = 0.0;
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
  localB->ColorSpaceConversion1_o1 = rtb_TSamp_c;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = eml_min_dist;

  /* Convert from XYZ to L*a*b* */
  eml_min_dist = localB->ColorSpaceConversion1_o1 / 9.6419865576090003E-01;
  rtb_Error_o = localB->ColorSpaceConversion1_o3 / 8.2511648322104003E-01;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_min_dist > 8.8564516790356311E-03) {
    rtb_TSamp_c = rt_pow_snf(eml_min_dist, 3.3333333333333331E-01);
  } else {
    rtb_TSamp_c = 7.7870370370370372E+00 * eml_min_dist + 1.3793103448275862E-01;
  }

  if (localB->ColorSpaceConversion1_o2 > 8.8564516790356311E-03) {
    eml_i = rt_pow_snf(localB->ColorSpaceConversion1_o2, 3.3333333333333331E-01);
  } else {
    eml_i = 7.7870370370370372E+00 * localB->ColorSpaceConversion1_o2 +
      1.3793103448275862E-01;
  }

  if (rtb_Error_o > 8.8564516790356311E-03) {
    eml_min_dist = rt_pow_snf(rtb_Error_o, 3.3333333333333331E-01);
  } else {
    eml_min_dist = 7.7870370370370372E+00 * rtb_Error_o + 1.3793103448275862E-01;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * eml_i - 16.0;
  localB->ColorSpaceConversion1_o2 = (rtb_TSamp_c - eml_i) * 500.0;
  localB->ColorSpaceConversion1_o3 = (eml_i - eml_min_dist) * 200.0;

  /* Embedded MATLAB: '<S35>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Choose Closest Color': '<S38>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S38>:1:5' */
  eml_min_dist = 1000.0;

  /* '<S38>:1:6' */
  rtb_index = 1;

  /* '<S38>:1:7' */
  for (eml_i = 1.0; eml_i <= rtu_Num_Colors; eml_i++) {
    /* '<S38>:1:7' */
    /* '<S38>:1:8' */
    rtb_Error_o = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o1 -
      rtu_Ref_Colors[(int32_T)eml_i - 1], 2.0) * 2.0 + rt_pow_snf
                        (localB->ColorSpaceConversion1_o2 - rtu_Ref_Colors
                         [(int32_T)eml_i + 49], 2.0)) + rt_pow_snf
                       (localB->ColorSpaceConversion1_o3 - rtu_Ref_Colors
                        [(int32_T)eml_i + 99], 2.0));
    if (rtb_Error_o < eml_min_dist) {
      /* '<S38>:1:9' */
      /* '<S38>:1:10' */
      eml_min_dist = rtb_Error_o;

      /* '<S38>:1:11' */
      cc_0 = floor(eml_i + 0.5);
      if (cc_0 < 128.0) {
        rtb_index = (int8_T)cc_0;
      } else {
        rtb_index = MAX_int8_T;
      }
    }
  }

  /* RelationalOperator: '<S35>/Relational Operator' */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (rtu_LabMatrix[i] == (real_T)rtb_index);
  }

  /* S-Function (svipblob): '<S10>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 : 0);
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
            k = numBlobs + (uint32_T)brain_ConstP.pooled20[i];
            if (localDW->BuoyBlobAnalysis_PAD_DW[k] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[k] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(k / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
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
  for (n = 0; n < (int32_T)numBlobs; n++) {
    rtb_BuoyBlobAnalysis_o1_m[n] = (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
    idx = 0;
    ms = 0;
    for (j = 0; j < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n]; j++) {
      idx += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[j + n_0];
      ms += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[j + i];
    }

    cc_0 = (real_T)ms / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
    cc_1 = (real_T)idx / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
    rtb_BuoyBlobAnalysis_o2_a[n << 1] = cc_0;
    rtb_BuoyBlobAnalysis_o2_a[(n << 1) + 1] = cc_1;
    eml_min_dist = 0.0;
    rtb_TSamp_c = 0.0;
    cc = 0.0;
    for (k = 0U; k < (uint32_T)(int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n]; k++) {
      eml_i = (real_T)localDW->BuoyBlobAnalysis_N_PIXLIST_DW[n_0 + k] - cc_1;
      rtb_Error_o = (real_T)localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i + k] - cc_0;
      eml_min_dist += eml_i * eml_i;
      rtb_TSamp_c += rtb_Error_o * rtb_Error_o;
      cc += eml_i * (-rtb_Error_o);
    }

    cc_0 = eml_min_dist / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n] +
      8.3333333333333329E-02;
    rtb_Error_o = rtb_TSamp_c / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n] +
      8.3333333333333329E-02;
    eml_min_dist = cc / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
    eml_min_dist = sqrt((cc_0 - rtb_Error_o) * (cc_0 - rtb_Error_o) +
                        eml_min_dist * eml_min_dist * 4.0);
    eml_i = ((cc_0 + rtb_Error_o) + eml_min_dist) * 8.0;
    rtb_BuoyBlobAnalysis_o3[n] = sqrt(eml_i - ((cc_0 + rtb_Error_o) -
      eml_min_dist) * 8.0) / sqrt(eml_i);
    i += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
    n_0 += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[n];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_m[i] = -1;
  }

  for (i = (int32_T)numBlobs << 1; i < 20; i++) {
    rtb_BuoyBlobAnalysis_o2_a[i] = -1.0;
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o3[i] = -1.0;
  }

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function': '<S33>:1' */
  /*  This function will choose and return data about the blob most similar to */
  /*  the desired set of characteristics given a set of blobs */
  /*  Determine closest blob to desired Eccentricity */
  /* '<S33>:1:8' */
  for (i = 0; i < 10; i++) {
    eml_Dist[i] = fabs(rtb_BuoyBlobAnalysis_o3[i] -
                       brain_P.Buoy_Min_Eccentricity);
  }

  if ((rtb_BuoyBlobAnalysis_o2_a[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2_a[1] ==
       -1.0)) {
    /* '<S33>:1:10' */
    /* '<S33>:1:12' */
    eml_min_dist = 80.0;

    /* '<S33>:1:13' */
    eml_i = 60.0;

    /* '<S33>:1:14' */
    localB->BlobArea = -1.0;
  } else {
    eml_min_dist = eml_Dist[0];
    n = 1;
    n_0 = 1;
    maxNumBlobsReached = FALSE;
    if (rtIsNaN(eml_Dist[0])) {
      eml_searchingForNonNaN = TRUE;
      i = 2;
      eml_exitg = FALSE;
      while (((uint32_T)eml_exitg == 0U) && (i < 11)) {
        n_0++;
        if (!rtIsNaN(eml_Dist[n_0 - 1])) {
          eml_min_dist = eml_Dist[n_0 - 1];
          n = i;
          eml_searchingForNonNaN = FALSE;
          eml_exitg = TRUE;
        } else {
          i++;
        }
      }

      if (!eml_searchingForNonNaN) {
        maxNumBlobsReached = TRUE;
      }
    } else {
      maxNumBlobsReached = TRUE;
    }

    if (maxNumBlobsReached) {
      for (i = n + 1; i < 11; i++) {
        n_0++;
        if (eml_Dist[n_0 - 1] < eml_min_dist) {
          eml_min_dist = eml_Dist[n_0 - 1];
          n = i;
        }
      }
    }

    /* '<S33>:1:17' */
    eml_min_dist = rtb_BuoyBlobAnalysis_o2_a[((n - 1) << 1) + 1];

    /* '<S33>:1:18' */
    eml_i = rtb_BuoyBlobAnalysis_o2_a[(n - 1) << 1];

    /* '<S33>:1:19' */
    localB->BlobArea = (real_T)rtb_BuoyBlobAnalysis_o1_m[n - 1];
  }

  localB->BlobCentroidX = eml_min_dist;
  localB->BlobCentroidY = eml_i;

  /* Embedded MATLAB: '<S10>/Embedded MATLAB Function1' */
  brain_EmbeddedMATLABFunction1(&localB->sf_EmbeddedMATLABFunction1);

  /* Sum: '<S36>/Subtract' */
  eml_min_dist = localB->sf_EmbeddedMATLABFunction1.XCenter -
    localB->BlobCentroidX;

  /* SampleTimeMath: '<S41>/TSamp' incorporates:
   *  Gain: '<S40>/X-Buoy Derivative Gain'
   *
   * About '<S41>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  eml_i = brain_P.Cam_Forward_XPosition_Kd * eml_min_dist / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S36>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S40>/X-Buoy Discrete-Time Integrator'
   *  Gain: '<S40>/X-Buoy Proportional Gain'
   *  Sum: '<S40>/Sum'
   *  Sum: '<S41>/Diff'
   *  UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  cc_0 = floor((brain_P.Cam_Forward_XPosition_Kp * eml_min_dist + (eml_i -
    localDW->UD_DSTATE)) + localDW->XBuoyDiscreteTimeIntegrator_DST);
  if (cc_0 < 128.0) {
    if (cc_0 >= -128.0) {
      rtb_index = (int8_T)cc_0;
    } else {
      rtb_index = MIN_int8_T;
    }
  } else if (cc_0 >= 128.0) {
    rtb_index = MAX_int8_T;
  } else {
    rtb_index = 0;
  }

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Vision_Forward_Velocity'
   */
  localB->Add = brain_P.Vision_Forward_Velocity + (real_T)rtb_index;

  /* Sum: '<S36>/Add1' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Vision_Forward_Velocity2'
   *  Product: '<S36>/Multiply'
   */
  localB->Add1 = (real_T)rtb_index * -1.0 + brain_P.Vision_Forward_Velocity;

  /* Sum: '<S37>/Subtract' */
  rtb_Error_o = localB->BlobCentroidY -
    localB->sf_EmbeddedMATLABFunction1.YCenter;

  /* SampleTimeMath: '<S43>/TSamp' incorporates:
   *  Gain: '<S42>/Y-Buoy Derivative Gain'
   *
   * About '<S43>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_c = brain_P.Cam_Forward_YPosition_Kd * rtb_Error_o / ((real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * 0.2);

  /* DataTypeConversion: '<S37>/Data Type Conversion' incorporates:
   *  DiscreteIntegrator: '<S42>/Y-Buoy Discrete-Time Integrator'
   *  Gain: '<S42>/Y-Buoy Proportional Gain'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S43>/Diff'
   *  UnitDelay: '<S43>/UD'
   *
   * Block description for '<S43>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  cc_0 = floor((brain_P.Cam_Forward_YPosition_Kp * rtb_Error_o + (rtb_TSamp_c -
    localDW->UD_DSTATE_n)) + localDW->YBuoyDiscreteTimeIntegrator_DST);
  if (cc_0 < 128.0) {
    if (cc_0 >= -128.0) {
      localB->DataTypeConversion = (int8_T)cc_0;
    } else {
      localB->DataTypeConversion = MIN_int8_T;
    }
  } else if (cc_0 >= 128.0) {
    localB->DataTypeConversion = MAX_int8_T;
  } else {
    localB->DataTypeConversion = 0;
  }

  /* Update for UnitDelay: '<S41>/UD'
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = eml_i;

  /* Update for DiscreteIntegrator: '<S40>/X-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S40>/X-Buoy Integral Gain'
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

  /* Update for UnitDelay: '<S43>/UD'
   * Block description for '<S43>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_n = rtb_TSamp_c;

  /* Update for DiscreteIntegrator: '<S42>/Y-Buoy Discrete-Time Integrator' incorporates:
   *  Gain: '<S42>/Y-Buoy Integral Gain'
   */
  localDW->YBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysApproa_a * (brain_P.Cam_Forward_YPosition_Ki
    * rtb_Error_o) + localDW->YBuoyDiscreteTimeIntegrator_DST;
  if (localDW->YBuoyDiscreteTimeIntegrator_DST >= 15.0) {
    localDW->YBuoyDiscreteTimeIntegrator_DST = 15.0;
  } else {
    if (localDW->YBuoyDiscreteTimeIntegrator_DST <= -15.0) {
      localDW->YBuoyDiscreteTimeIntegrator_DST = -15.0;
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysShowSegm(const real_T rtu_LabMatrix[19200], const
  real_T rtu_Ref_Colors[150], rtB_StateFlowFunctionsBuoysShow *localB)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  int32_T eml_i;
  int32_T eml_j;

  /* Embedded MATLAB: '<S20>/Embedded MATLAB Function' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function': '<S67>:1' */
  /*  This function puts together the segmented imaged such that it can be shown */
  /* '<S67>:1:5' */
  /* '<S67>:1:6' */
  /* '<S67>:1:7' */
  /* '<S67>:1:9' */
  for (eml_i = 0; eml_i < 120; eml_i++) {
    /* '<S67>:1:9' */
    /* '<S67>:1:10' */
    for (eml_j = 0; eml_j < 160; eml_j++) {
      /* '<S67>:1:10' */
      /* '<S67>:1:11' */
      localB->L[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] - 1];

      /* '<S67>:1:12' */
      localB->a[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] + 49];

      /* '<S67>:1:13' */
      localB->b[eml_i + 120 * eml_j] = rtu_Ref_Colors[(int32_T)rtu_LabMatrix[120
        * eml_j + eml_i] + 99];
    }
  }

  /* S-Function (svipcolorconv): '<S20>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  /* First convert to XYZ */
  for (eml_i = 0; eml_i < 19200; eml_i++) {
    cc = (localB->L[eml_i] + 16.0) / 116.0;
    cc_0 = localB->a[eml_i] / 500.0 + cc;
    cc_1 = localB->b[eml_i] / -200.0 + cc;
    if (cc_0 <= 2.0689655172413793E-01) {
      cc_0 -= 1.3793103448275862E-01;
      cc_0 /= 7.7870370370370372E+00;
    } else {
      cc_0 = rt_pow_snf(cc_0, 3.0);
    }

    if (cc <= 2.0689655172413793E-01) {
      cc -= 1.3793103448275862E-01;
      cc /= 7.7870370370370372E+00;
    } else {
      cc = rt_pow_snf(cc, 3.0);
    }

    if (cc_1 <= 2.0689655172413793E-01) {
      cc_1 -= 1.3793103448275862E-01;
      cc_1 /= 7.7870370370370372E+00;
    } else {
      cc_1 = rt_pow_snf(cc_1, 3.0);
    }

    cc_0 *= 9.6419865576090003E-01;
    cc_1 *= 8.2511648322104003E-01;

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
    cc = (3.2409699419045102E+00 * localB->ColorSpaceConversion_o1[eml_i] +
          -1.5373831775700899E+00 * localB->ColorSpaceConversion_o2[eml_i]) +
      -4.9861076029299001E-01 * localB->ColorSpaceConversion_o3[eml_i];
    cc_0 = (-9.6924363628086996E-01 * localB->ColorSpaceConversion_o1[eml_i] +
            1.8759675015077100E+00 * localB->ColorSpaceConversion_o2[eml_i]) +
      4.1555057407179997E-02 * localB->ColorSpaceConversion_o3[eml_i];
    cc_1 = (5.5630079696999998E-02 * localB->ColorSpaceConversion_o1[eml_i] +
            -2.0397695888899001E-01 * localB->ColorSpaceConversion_o2[eml_i]) +
      1.0569715142428799E+00 * localB->ColorSpaceConversion_o3[eml_i];

    /* Apply gamma correction to get R'G'B' */
    if (cc <= 0.00304) {
      cc *= 1.2923054468333255E+01;
    } else {
      cc = 1.0550005198172263E+00 * rt_pow_snf(cc, 4.1666666666666669E-01) -
        5.5000519817226347E-02;
    }

    if (cc_0 <= 0.00304) {
      cc_0 *= 1.2923054468333255E+01;
    } else {
      cc_0 = 1.0550005198172263E+00 * rt_pow_snf(cc_0, 4.1666666666666669E-01) -
        5.5000519817226347E-02;
    }

    if (cc_1 <= 0.00304) {
      cc_1 *= 1.2923054468333255E+01;
    } else {
      cc_1 = 1.0550005198172263E+00 * rt_pow_snf(cc_1, 4.1666666666666669E-01) -
        5.5000519817226347E-02;
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

  /* Embedded MATLAB: '<S20>/Embedded MATLAB Function1' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function1': '<S68>:1' */
  /*  This function combines the separate color signals into a single 3-D signal */
  /* '<S68>:1:6' */
  memset((void *)(&localB->RGB[0]), (int32_T)0.0, 57600U * sizeof(real_T));

  /* '<S68>:1:8' */
  for (eml_i = 0; eml_i < 120; eml_i++) {
    /* '<S68>:1:8' */
    /* '<S68>:1:9' */
    for (eml_j = 0; eml_j < 160; eml_j++) {
      /* '<S68>:1:9' */
      /* '<S68>:1:10' */
      localB->RGB[eml_i + 120 * eml_j] = localB->ColorSpaceConversion_o1[120 *
        eml_j + eml_i];

      /* '<S68>:1:11' */
      localB->RGB[19200 + (eml_i + 120 * eml_j)] =
        localB->ColorSpaceConversion_o2[120 * eml_j + eml_i];

      /* '<S68>:1:12' */
      localB->RGB[38400 + (eml_i + 120 * eml_j)] =
        localB->ColorSpaceConversion_o3[120 * eml_j + eml_i];
    }
  }
}

/* Function for Embedded MATLAB: '<S53>/Low Pass Filter' */
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

/* Function for Embedded MATLAB: '<S53>/Low Pass Filter' */
static void brain_c27_brain(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB)
{
  real_T eml_G[9];
  real_T eml_Gsum;
  int32_T eml_i;
  real32_T eml_G_0[9];

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter': '<S55>:1' */
  /*  This function calculates the gaussian blur of an intensity image */
  /*  Gaussian matrix rows */
  /*  Gaussian matrix columns */
  /* '<S55>:1:11' */
  memset((void *)&localB->Iout[0], (int32_T)0.0F, 19200U * sizeof(real32_T));

  /* '<S55>:1:17' */
  memset((void *)&eml_G[0], (int32_T)0.0, 9U * sizeof(real_T));

  /* '<S55>:1:19' */
  /* '<S55>:1:21' */
  /* '<S55>:1:23' */
  eml_Gsum = 0.0;

  /* '<S55>:1:24' */
  for (eml_i = -1; eml_i < 2; eml_i++) {
    /* '<S55>:1:24' */
    /* '<S55>:1:25' */
    /* '<S55>:1:26' */
    eml_G[eml_i + 1] = exp((-((real_T)(eml_i * eml_i) + 1.0)) /
      4.0000000000000009E+00);

    /* '<S55>:1:27' */
    eml_Gsum += eml_G[eml_i + 1];

    /* '<S55>:1:25' */
    /* '<S55>:1:26' */
    eml_G[eml_i + 4] = exp((real_T)(-(eml_i * eml_i)) / 4.0000000000000009E+00);

    /* '<S55>:1:27' */
    eml_Gsum += eml_G[eml_i + 4];

    /* '<S55>:1:25' */
    /* '<S55>:1:26' */
    eml_G[eml_i + 7] = exp((-((real_T)(eml_i * eml_i) + 1.0)) /
      4.0000000000000009E+00);

    /* '<S55>:1:27' */
    eml_Gsum += eml_G[eml_i + 7];
  }

  /* '<S55>:1:31' */
  for (eml_i = 0; eml_i < 9; eml_i++) {
    eml_G[eml_i] /= eml_Gsum;
  }

  /* '<S55>:1:33' */
  for (eml_i = 0; eml_i < 19200; eml_i++) {
    localB->fv0[eml_i] = (real32_T)rtu_I[eml_i];
  }

  for (eml_i = 0; eml_i < 9; eml_i++) {
    eml_G_0[eml_i] = (real32_T)eml_G[eml_i];
  }

  brain_conv2(&localB->fv0[0], eml_G_0, &localB->eml_Itemp[0]);

  /*  reflect boundaries to keep image the same size */
  /*  top */
  /* '<S55>:1:37' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    localB->Iout[120 * (1 + eml_i)] = localB->eml_Itemp[118 * eml_i];
  }

  /*  bottom */
  /* '<S55>:1:39' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    localB->Iout[119 + 120 * (1 + eml_i)] = localB->eml_Itemp[118 * eml_i + 117];
  }

  /*  left */
  /* '<S55>:1:41' */
  memcpy((void *)&localB->Iout[1], (void *)&localB->eml_Itemp[0], 118U * sizeof
         (real32_T));

  /*  right */
  /* '<S55>:1:43' */
  memcpy((void *)&localB->Iout[19081], (void *)&localB->eml_Itemp[18526], 118U *
         sizeof(real32_T));

  /*  center */
  /* '<S55>:1:45' */
  for (eml_i = 0; eml_i < 158; eml_i++) {
    memcpy((void *)&localB->Iout[1 + 120 * (1 + eml_i)], (void *)
           &localB->eml_Itemp[118 * eml_i], 118U * sizeof(real32_T));
  }

  /*  top left corner */
  /* '<S55>:1:47' */
  localB->Iout[0] = localB->eml_Itemp[0];

  /*  top right corner */
  /* '<S55>:1:49' */
  localB->Iout[18960] = localB->eml_Itemp[18408];
  localB->Iout[19080] = localB->eml_Itemp[18526];

  /*  bottom left corner */
  /* '<S55>:1:51' */
  localB->Iout[118] = localB->eml_Itemp[116];
  localB->Iout[119] = localB->eml_Itemp[117];

  /*  bottom right corner */
  /* '<S55>:1:53' */
  localB->Iout[19078] = localB->eml_Itemp[18524];
  localB->Iout[19079] = localB->eml_Itemp[18525];
  localB->Iout[19198] = localB->eml_Itemp[18642];
  localB->Iout[19199] = localB->eml_Itemp[18643];
}

/*
 * Output and update for atomic system:
 *    '<S53>/Low Pass Filter'
 *    '<S53>/Low Pass Filter1'
 *    '<S53>/Low Pass Filter2'
 */
void brain_LowPassFilter(const real_T rtu_I[19200], rtB_LowPassFilter_brain
  *localB)
{
  /* Embedded MATLAB: '<S53>/Low Pass Filter' */
  brain_c27_brain(rtu_I, localB);
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
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
  int32_T indx;
  int32_T eml_flag;
  int32_T eml_i;
  int32_T eml_j;
  real_T eml_min_dist;
  real_T eml_index;
  real32_T eml_dist;
  real_T eml_k;
  real32_T Resize2_LineBuffer[120];

  /* S-Function (svipcolorconv): '<S17>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    eml_min_dist = 6.0 * rtu_H[i];
    k = (uint32_T)(eml_min_dist - 1.3322676295501878E-15);
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

  /* Embedded MATLAB: '<S53>/Low Pass Filter' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o1, &localB->sf_LowPassFilter);

  /* Embedded MATLAB: '<S53>/Low Pass Filter1' */
  brain_LowPassFilter(localB->ColorSpaceConversion_o2,
                      &localB->sf_LowPassFilter1);

  /* Embedded MATLAB: '<S53>/Low Pass Filter2' */
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
    if (localB->sf_LowPassFilter.Iout[i] <= 3.928608447E-02F) {
      Zr = localB->sf_LowPassFilter.Iout[i] / 1.292305470E+01F;
    } else {
      Zr = rt_pow32_snf((localB->sf_LowPassFilter.Iout[i] + 5.500052124E-02F) /
                        1.055000544E+00F, 2.400000095E+00F);
    }

    if (localB->sf_LowPassFilter1.Iout[i] <= 3.928608447E-02F) {
      eml_dist = localB->sf_LowPassFilter1.Iout[i] / 1.292305470E+01F;
    } else {
      eml_dist = rt_pow32_snf((localB->sf_LowPassFilter1.Iout[i] +
        5.500052124E-02F) / 1.055000544E+00F, 2.400000095E+00F);
    }

    if (localB->sf_LowPassFilter2.Iout[i] <= 3.928608447E-02F) {
      Yr = localB->sf_LowPassFilter2.Iout[i] / 1.292305470E+01F;
    } else {
      Yr = rt_pow32_snf((localB->sf_LowPassFilter2.Iout[i] + 5.500052124E-02F) /
                        1.055000544E+00F, 2.400000095E+00F);
    }

    /* The coefficients for this conversion were derived from ITU-R */
    /* BT.709 reference primaries for sRGB and CIE standard illuminant */
    /* D65, 2 degree observer */
    Xf = (4.123907983E-01F * Zr + 3.575843275E-01F * eml_dist) +
      1.804807931E-01F * Yr;
    cc_2 = (2.126390040E-01F * Zr + 7.151686549E-01F * eml_dist) +
      7.219231874E-02F * Yr;
    eml_dist = (1.933081821E-02F * Zr + 1.191947833E-01F * eml_dist) +
      9.505321383E-01F * Yr;

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
    eml_dist = localB->ColorSpaceConversion1_o1[i] / 9.641986489E-01F;
    Zr = localB->ColorSpaceConversion1_o3[i] / 8.251164556E-01F;

    /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
    if (eml_dist > 8.856452070E-03F) {
      Xf = rt_pow32_snf(eml_dist, 3.333333433E-01F);
    } else {
      Xf = 7.787036896E+00F * eml_dist + 1.379310340E-01F;
    }

    if (localB->ColorSpaceConversion1_o2[i] > 8.856452070E-03F) {
      Yr = rt_pow32_snf(localB->ColorSpaceConversion1_o2[i], 3.333333433E-01F);
    } else {
      Yr = 7.787036896E+00F * localB->ColorSpaceConversion1_o2[i] +
        1.379310340E-01F;
    }

    if (Zr > 8.856452070E-03F) {
      eml_dist = rt_pow32_snf(Zr, 3.333333433E-01F);
    } else {
      eml_dist = 7.787036896E+00F * Zr + 1.379310340E-01F;
    }

    /* assign the results */
    localB->ColorSpaceConversion1_o1[i] = 116.0F * Yr - 16.0F;
    localB->ColorSpaceConversion1_o2[i] = (Xf - Yr) * 500.0F;
    localB->ColorSpaceConversion1_o3[i] = (Yr - eml_dist) * 200.0F;
  }

  /* S-Function (svipresize): '<S60>/Resize' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_flag = 0;
  for (eml_i = 0; eml_i < 120; eml_i++) {
    indx = eml_i;
    for (eml_j = 0; eml_j < 80; eml_j++) {
      i = eml_j + 80;
      eml_dist = localB->ColorSpaceConversion1_o1[brain_ConstP.pooled23[eml_j] *
        120 + eml_i] * brain_ConstP.pooled17[eml_j] +
        localB->ColorSpaceConversion1_o1[brain_ConstP.pooled23[i] * 120 + eml_i]
        * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o1[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      localDW->Resize_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (eml_j = 0; eml_j < 80; eml_j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize_IntBuffer[eml_j * 120]), 120U * sizeof(real32_T));
    for (eml_i = 0; eml_i < 60; eml_i++) {
      i = eml_i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled22[eml_i]] *
        brain_ConstP.pooled16[eml_i] +
        Resize2_LineBuffer[brain_ConstP.pooled22[i]] * brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      localB->Resize[eml_flag] = eml_dist;
      eml_flag++;
    }
  }

  /* S-Function (svipresize): '<S60>/Resize1' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_flag = 0;
  for (eml_i = 0; eml_i < 120; eml_i++) {
    indx = eml_i;
    for (eml_j = 0; eml_j < 80; eml_j++) {
      i = eml_j + 80;
      eml_dist = localB->ColorSpaceConversion1_o2[brain_ConstP.pooled23[eml_j] *
        120 + eml_i] * brain_ConstP.pooled17[eml_j] +
        localB->ColorSpaceConversion1_o2[brain_ConstP.pooled23[i] * 120 + eml_i]
        * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o2[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      localDW->Resize1_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (eml_j = 0; eml_j < 80; eml_j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize1_IntBuffer[eml_j * 120]), 120U * sizeof(real32_T));
    for (eml_i = 0; eml_i < 60; eml_i++) {
      i = eml_i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled22[eml_i]] *
        brain_ConstP.pooled16[eml_i] +
        Resize2_LineBuffer[brain_ConstP.pooled22[i]] * brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      localB->Resize1[eml_flag] = eml_dist;
      eml_flag++;
    }
  }

  /* S-Function (svipresize): '<S60>/Resize2' */
  /* use pre-computed weights and index table to perform interpolation */
  eml_flag = 0;
  for (eml_i = 0; eml_i < 120; eml_i++) {
    indx = eml_i;
    for (eml_j = 0; eml_j < 80; eml_j++) {
      i = eml_j + 80;
      eml_dist = localB->ColorSpaceConversion1_o3[brain_ConstP.pooled23[eml_j] *
        120 + eml_i] * brain_ConstP.pooled17[eml_j] +
        localB->ColorSpaceConversion1_o3[brain_ConstP.pooled23[i] * 120 + eml_i]
        * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      i += 80;
      eml_dist += localB->ColorSpaceConversion1_o3[brain_ConstP.pooled23[i] *
        120 + eml_i] * brain_ConstP.pooled17[i];
      localDW->Resize2_IntBuffer[indx] = eml_dist;
      indx += 120;
    }
  }

  for (eml_j = 0; eml_j < 80; eml_j++) {
    memcpy((void *)&Resize2_LineBuffer[0], (void *)(&localDW->
            Resize2_IntBuffer[eml_j * 120]), 120U * sizeof(real32_T));
    for (eml_i = 0; eml_i < 60; eml_i++) {
      i = eml_i + 60;
      eml_dist = Resize2_LineBuffer[brain_ConstP.pooled22[eml_i]] *
        brain_ConstP.pooled16[eml_i] +
        Resize2_LineBuffer[brain_ConstP.pooled22[i]] * brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      i += 60;
      eml_dist += Resize2_LineBuffer[brain_ConstP.pooled22[i]] *
        brain_ConstP.pooled16[i];
      localB->Resize2[eml_flag] = eml_dist;
      eml_flag++;
    }
  }

  /* Embedded MATLAB: '<S54>/Reference Color Selection' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Reference Color Selection': '<S59>:1' */
  /*  This function tries segmentation by adding new reference colors everytime */
  /*  a pixel is found with a distance greater than a certain amount from */
  /*  every other reference color */
  /* '<S59>:1:6' */
  /* '<S59>:1:8' */
  /*  L = 0 to 100, a = -100 to 100, b = -100 to 100 */
  /*  max dist = 300 -> 60/300 is 20% */
  /* '<S59>:1:11' */
  /* '<S59>:1:12' */
  memset((void *)(&localB->ref_colors[0]), (int32_T)0.0, 150U * sizeof(real_T));

  /*  At most 50 different reference colors */
  /* '<S59>:1:14' */
  i = 1;

  /* '<S59>:1:19' */
  localB->ref_colors[0] = localB->Resize[2369];
  localB->ref_colors[50] = localB->Resize1[2369];
  localB->ref_colors[100] = localB->Resize2[2369];

  /* '<S59>:1:21' */
  eml_flag = 0;

  /* '<S59>:1:22' */
  eml_i = 1;

  /* '<S59>:1:23' */
  eml_j = 1;
  while (eml_i <= 60) {
    /* '<S59>:1:24' */
    while ((eml_i <= 60) && (eml_flag == 0)) {
      /* '<S59>:1:25' */
      while ((eml_j <= 80) && (eml_flag == 0)) {
        /* '<S59>:1:26' */
        /* '<S59>:1:27' */
        eml_min_dist = 1.0;

        /* '<S59>:1:28' */
        eml_index = 1000.0;
        while ((uint32_T)eml_min_dist <= (uint32_T)i) {
          /* '<S59>:1:30' */
          /* '<S59>:1:31' */
          eml_dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->ref_colors
            [(int32_T)eml_min_dist - 1] - localB->Resize[(eml_j - 1) * 60 +
            (eml_i - 1)], 2.0F) + rt_pow32_snf((real32_T)localB->ref_colors
            [(int32_T)eml_min_dist + 49] - localB->Resize1[(eml_j - 1) * 60 +
            (eml_i - 1)], 2.0F)) + rt_pow32_snf((real32_T)localB->ref_colors
            [(int32_T)eml_min_dist + 99] - localB->Resize2[(eml_j - 1) * 60 +
            (eml_i - 1)], 2.0F));
          if (eml_index > (real_T)eml_dist) {
            /* '<S59>:1:32' */
            /* '<S59>:1:33' */
            eml_index = eml_dist;
          }

          /* '<S59>:1:36' */
          eml_min_dist++;
        }

        if ((eml_index > 60.0) && (i < 50)) {
          /* '<S59>:1:41' */
          /* '<S59>:1:42' */
          localB->ref_colors[i] = localB->Resize[(eml_j - 1) * 60 + (eml_i - 1)];
          localB->ref_colors[i + 50] = localB->Resize1[(eml_j - 1) * 60 + (eml_i
            - 1)];
          localB->ref_colors[i + 100] = localB->Resize2[(eml_j - 1) * 60 +
            (eml_i - 1)];

          /* '<S59>:1:43' */
          i++;

          /* '<S59>:1:44' */
          eml_flag = 1;

          /* '<S59>:1:45' */
          eml_i = 0;

          /* '<S59>:1:46' */
          eml_j = 0;
        }

        /* '<S59>:1:50' */
        eml_j++;
      }

      /* '<S59>:1:52' */
      eml_j = 1;

      /* '<S59>:1:53' */
      eml_i++;
    }

    /* '<S59>:1:55' */
    eml_flag = 0;
  }

  localB->num_colors = (real_T)i;

  /* Embedded MATLAB: '<S54>/LabSegmentation' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/LabSegmentation': '<S58>:1' */
  /*  This function generates the label matrix */
  /* '<S58>:1:10' */
  memset((void *)(&localB->LabelMatrix[0]), (int32_T)0.0, 19200U * sizeof(real_T));

  /* '<S58>:1:12' */
  for (i = 0; i < 120; i++) {
    /* '<S58>:1:12' */
    /* '<S58>:1:13' */
    for (eml_flag = 0; eml_flag < 160; eml_flag++) {
      /* '<S58>:1:13' */
      /* '<S58>:1:14' */
      eml_min_dist = 1000.0;

      /* '<S58>:1:15' */
      eml_index = 1.0;

      /* '<S58>:1:16' */
      for (eml_k = 1.0; eml_k <= localB->num_colors; eml_k++) {
        /* '<S58>:1:16' */
        /* '<S58>:1:17' */
        eml_dist = (real32_T)sqrt((rt_pow32_snf((real32_T)localB->ref_colors
          [(int32_T)eml_k - 1] - localB->ColorSpaceConversion1_o1[120 * eml_flag
          + i], 2.0F) + rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)eml_k
          + 49] - localB->ColorSpaceConversion1_o2[120 * eml_flag + i], 2.0F)) +
          rt_pow32_snf((real32_T)localB->ref_colors[(int32_T)eml_k + 99] -
                       localB->ColorSpaceConversion1_o3[120 * eml_flag + i],
                       2.0F));
        if ((real_T)eml_dist < eml_min_dist) {
          /* '<S58>:1:18' */
          /* '<S58>:1:19' */
          eml_min_dist = eml_dist;

          /* '<S58>:1:20' */
          eml_index = eml_k;
        }
      }

      /* '<S58>:1:23' */
      localB->LabelMatrix[i + 120 * eml_flag] = eml_index;
    }
  }

  /* '<S58>:1:27' */
}

/*
 * Initial conditions for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysMai_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysMai *localDW)
{
  localDW->StateFlowFunctionsBuoysMainta_a = brain_M->Timing.clockTick0;
}

/*
 * Output and update for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysMaintain(real32_T rtu_DesiredDepth1, real32_T
  rtu_CurrentDepth1, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsBuoysMain *localB, rtDW_StateFlowFunctionsBuoysMai
  *localDW)
{
  real_T rtb_Add;
  real_T rtb_TSamp_h;
  real_T tmp;
  localDW->StateFlowFunctionsBuoysMainta_k = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsBuoysMainta_a;
  localDW->StateFlowFunctionsBuoysMainta_a = brain_M->Timing.clockTick0;

  /* Sum: '<S18>/Add' */
  rtb_Add = (real_T)rtu_DesiredDepth1 - (real_T)rtu_CurrentDepth1;

  /* SampleTimeMath: '<S62>/TSamp' incorporates:
   *  Gain: '<S61>/Depth Derivative Gain'
   *
   * About '<S62>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_h = brain_P.Depth_Kd * rtb_Add / ((real_T)
    localDW->StateFlowFunctionsBuoysMainta_k * 0.2);

  /* DataTypeConversion: '<S18>/Double To Int8' incorporates:
   *  DiscreteIntegrator: '<S61>/Depth Discrete-Time Integrator'
   *  Gain: '<S61>/Depth Proportional Gain'
   *  Sum: '<S61>/Sum'
   *  Sum: '<S62>/Diff'
   *  UnitDelay: '<S62>/UD'
   *
   * Block description for '<S62>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S62>/UD':
   *
   *  Store in Global RAM
   */
  tmp = (brain_P.Depth_Kp * rtb_Add + (rtb_TSamp_h - localDW->UD_DSTATE)) +
    localDW->DepthDiscreteTimeIntegrator_DST;
  tmp = floor(tmp);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DoubleToInt8 = (int8_T)tmp;
    } else {
      localB->DoubleToInt8 = MIN_int8_T;
    }
  } else if (tmp >= 128.0) {
    localB->DoubleToInt8 = MAX_int8_T;
  } else {
    localB->DoubleToInt8 = 0;
  }

  /* Update for UnitDelay: '<S62>/UD'
   * Block description for '<S62>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_h;

  /* Update for DiscreteIntegrator: '<S61>/Depth Discrete-Time Integrator' incorporates:
   *  Gain: '<S61>/Depth Integral Gain'
   */
  localDW->DepthDiscreteTimeIntegrator_DST = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysMainta_k * (brain_P.Depth_Ki * rtb_Add) +
    localDW->DepthDiscreteTimeIntegrator_DST;
  if (localDW->DepthDiscreteTimeIntegrator_DST >= 10.0) {
    localDW->DepthDiscreteTimeIntegrator_DST = 10.0;
  } else {
    if (localDW->DepthDiscreteTimeIntegrator_DST <= -10.0) {
      localDW->DepthDiscreteTimeIntegrator_DST = -10.0;
    }
  }
}

/*
 * Initial conditions for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysM_i_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysM_k *localDW)
{
  localDW->StateFlowFunctionsBuoysMainta_d = brain_M->Timing.clockTick0;
}

/*
 * Disable for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoys_Disable(rtB_StateFlowFunctionsBuoysMa_a *localB,
  rtDW_StateFlowFunctionsBuoysM_k *localDW)
{
  /* Disable for If: '<S19>/If' */
  localDW->If_ActiveSubsystem = -1;

  /* Disable for ifaction SubSystem: '<S19>/BigError S1' */

  /* Disable for Outport: '<S63>/Out2' */
  localB->Constant1_c = 0.0;

  /* end of Disable for SubSystem: '<S19>/BigError S1' */

  /* Disable for ifaction SubSystem: '<S19>/BigNegativeError S2' */

  /* Disable for Outport: '<S64>/Out2' */
  localB->Constant1 = 0.0;

  /* end of Disable for SubSystem: '<S19>/BigNegativeError S2' */
}

/*
 * Start for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoys_b_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysM_k *localDW)
{
  /* Start for If: '<S19>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/*
 * Output and update for function-call system:
 *    '<Root>/StateFlow Functions'
 *    '<Root>/StateFlow Functions'
 */
void StateFlowFunctionsBuoysMainta_h(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *const
  brain_M, rtB_StateFlowFunctionsBuoysMa_a *localB,
  rtDW_StateFlowFunctionsBuoysM_k *localDW)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  real_T rtb_Add1;
  real_T rtb_Add4;
  real_T rtb_TSamp_b;
  real_T tmp;
  localDW->StateFlowFunctionsBuoysMainta_m = brain_M->Timing.clockTick0 -
    localDW->StateFlowFunctionsBuoysMainta_d;
  localDW->StateFlowFunctionsBuoysMainta_d = brain_M->Timing.clockTick0;

  /* Sum: '<S19>/Add1' */
  rtb_Add1 = rtu_DesiredHeading1 - rtu_CurrentHeading1;

  /* If: '<S19>/If' incorporates:
   *  ActionPort: '<S63>/Action Port'
   *  ActionPort: '<S64>/Action Port'
   *  SubSystem: '<S19>/BigError S1'
   *  SubSystem: '<S19>/BigNegativeError S2'
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
      /* Disable for Outport: '<S63>/Out2' */
      localB->Constant1_c = 0.0;
      break;

     case 1:
      /* Disable for Outport: '<S64>/Out2' */
      localB->Constant1 = 0.0;
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Sum: '<S63>/Add' incorporates:
     *  Constant: '<S63>/Constant'
     */
    localB->Add_c = rtb_Add1 - 360.0;

    /* Constant: '<S63>/Constant1' */
    localB->Constant1_c = 1.0;
    break;

   case 1:
    /* Sum: '<S64>/Add' incorporates:
     *  Constant: '<S64>/Constant'
     */
    localB->Add = rtb_Add1 + 360.0;

    /* Constant: '<S64>/Constant1' */
    localB->Constant1 = 2.0;
    break;
  }

  /* MultiPortSwitch: '<S19>/Multiport Switch' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Sum: '<S19>/Add2'
   */
  switch ((int32_T)((1.0 + localB->Constant1_c) + localB->Constant1)) {
   case 1:
    break;

   case 2:
    rtb_Add1 = localB->Add_c;
    break;

   default:
    rtb_Add1 = localB->Add;
    break;
  }

  /* SampleTimeMath: '<S66>/TSamp' incorporates:
   *  Gain: '<S65>/Heading Derivative Gain'
   *
   * About '<S66>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_b = brain_P.Heading_Kd * rtb_Add1 / ((real_T)
    localDW->StateFlowFunctionsBuoysMainta_m * 0.2);

  /* Sum: '<S65>/Sum' incorporates:
   *  DiscreteIntegrator: '<S65>/Heading Discrete-Time Integrator'
   *  Gain: '<S65>/Heading Proportional Gain'
   *  Sum: '<S66>/Diff'
   *  UnitDelay: '<S66>/UD'
   *
   * Block description for '<S66>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S66>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add4 = (brain_P.Heading_Kp * rtb_Add1 + (rtb_TSamp_b - localDW->UD_DSTATE))
    + localDW->HeadingDiscreteTimeIntegrator_D;

  /* Product: '<S19>/Multiply' incorporates:
   *  Constant: '<S19>/Constant'
   */
  tmp = -rtb_Add4;
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(floor(tmp), 256.0);
  }

  /* Sum: '<S19>/Add4' */
  rtb_Add4 += rtu_ForwardVelocity1;

  /* DataTypeConversion: '<S19>/DoubleToint1' incorporates:
   *  Sum: '<S19>/Add3'
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
  } else if (tmp >= 128.0) {
    localB->DoubleToint1 = MAX_int8_T;
  } else {
    localB->DoubleToint1 = 0;
  }

  /* DataTypeConversion: '<S19>/DoubleToint8' */
  tmp = floor(rtb_Add4);
  if (tmp < 128.0) {
    if (tmp >= -128.0) {
      localB->DoubleToint8 = (int8_T)tmp;
    } else {
      localB->DoubleToint8 = MIN_int8_T;
    }
  } else if (tmp >= 128.0) {
    localB->DoubleToint8 = MAX_int8_T;
  } else {
    localB->DoubleToint8 = 0;
  }

  /* Update for UnitDelay: '<S66>/UD'
   * Block description for '<S66>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = rtb_TSamp_b;

  /* Update for DiscreteIntegrator: '<S65>/Heading Discrete-Time Integrator' incorporates:
   *  Gain: '<S65>/Heading Integral Gain'
   */
  localDW->HeadingDiscreteTimeIntegrator_D = 0.2 * (real_T)
    localDW->StateFlowFunctionsBuoysMainta_m * (brain_P.Heading_Ki * rtb_Add1) +
    localDW->HeadingDiscreteTimeIntegrator_D;
  if (localDW->HeadingDiscreteTimeIntegrator_D >= 15.0) {
    localDW->HeadingDiscreteTimeIntegrator_D = 15.0;
  } else {
    if (localDW->HeadingDiscreteTimeIntegrator_D <= -15.0) {
      localDW->HeadingDiscreteTimeIntegrator_D = -15.0;
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsFollowOnePath(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_StateFlowFunctionsFollowOne
  *localB)
{
  int32_T i;

  /* Embedded MATLAB: '<S21>/PutHSVImageTogether' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether': '<S69>:1' */
  /*  This function simply makes an HSV image a single multidimensional */
  /*  signal */
  /* '<S69>:1:7' */
  memset((void *)(&localB->HSVImage1[0]), (int32_T)0.0, 57600U * sizeof(real_T));

  /* '<S69>:1:9' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[120 * i]), (void *)(&rtu_H1[120 * i]),
           120U * sizeof(real_T));
  }

  /* '<S69>:1:10' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[19200 + 120 * i]), (void *)(&rtu_S1[120 *
            i]), 120U * sizeof(real_T));
  }

  /* '<S69>:1:11' */
  for (i = 0; i < 160; i++) {
    memcpy((void *)(&localB->HSVImage1[38400 + 120 * i]), (void *)(&rtu_V1[120 *
            i]), 120U * sizeof(real_T));
  }
}

/* Function for Embedded MATLAB: '<S82>/IsLinePresent' */
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

/* Function for Embedded MATLAB: '<S82>/IsLinePresent' */
static void brain_max_b(const real_T eml_varargin_1[180], real_T *eml_maxval,
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

/* Function for Embedded MATLAB: '<S82>/IsLinePresent' */
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

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent': '<S84>:1' */
  /*  This function takes a Hough/hash table as input and  determines if a line */
  /*  is present and if so what its Rho and Theta are. */
  /* '<S84>:1:5' */
  /* '<S84>:1:7' */
  /* '<S84>:1:9' */
  /* '<S84>:1:10' */
  /* '<S84>:1:11' */
  /* '<S84>:1:12' */
  /* '<S84>:1:13' */
  localB->Rho[0] = -999.0;
  localB->Theta[0] = -999.0;
  localB->maxVotes[0] = -999.0;
  localB->Rho[1] = -999.0;
  localB->Theta[1] = -999.0;
  localB->maxVotes[1] = -999.0;
  eml_ThetaIndex_idx_0 = -999.0;
  eml_RhoIndex_idx_0 = -999.0;

  /* '<S84>:1:15' */
  brain_max(&rtu_HoughTable[0], eml_maxValues, eml_RhoIndices);
  brain_max_b(eml_maxValues, &eml_b, &eml_c);

  /* '<S84>:1:18' */
  localB->maxVotes[0] = eml_b;

  /* '<S84>:1:18' */
  eml_ThetaIndex_idx = eml_c;

  /* '<S84>:1:19' */
  eml_RhoIndex_idx = eml_RhoIndices[(int32_T)eml_c - 1];
  if (localB->maxVotes[0] >= 15.0) {
    /* '<S84>:1:21' */
    /* '<S84>:1:22' */
    localB->eml_HoughTable[((int32_T)eml_RhoIndex_idx - 1) + 287 * ((int32_T)
      eml_c - 1)] = 0.0;

    /* '<S84>:1:24' */
    eml_index = 2;

    /* '<S84>:1:25' */
    eml_count = 0;
    while ((eml_index <= 2) && (eml_count < 12)) {
      /* '<S84>:1:26' */
      /* '<S84>:1:27' */
      eml_count++;
      brain_max(&localB->eml_HoughTable[0], eml_maxValues, eml_RhoIndices);
      brain_max_b(eml_maxValues, &eml_b, &eml_c);

      /* '<S84>:1:29' */
      localB->maxVotes[1] = eml_b;

      /* '<S84>:1:29' */
      eml_ThetaIndex_idx_0 = eml_c;

      /* '<S84>:1:30' */
      eml_RhoIndex_idx_0 = eml_RhoIndices[(int32_T)eml_c - 1];

      /* '<S84>:1:32' */
      localB->eml_HoughTable[((int32_T)eml_RhoIndex_idx_0 - 1) + 287 * ((int32_T)
        eml_c - 1)] = 0.0;
      if ((fabs(eml_RhoIndex_idx_0 - eml_RhoIndex_idx) > 20.0) || (fabs(eml_c -
            eml_ThetaIndex_idx) > 30.0)) {
        /* '<S84>:1:34' */
        /* '<S84>:1:35' */
        eml_index = 3;
      }
    }

    /* '<S84>:1:40' */
    if (localB->maxVotes[0] > 15.0) {
      /* '<S84>:1:41' */
      /* '<S84>:1:42' */
      localB->Theta[0] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx - 1];

      /* '<S84>:1:43' */
      localB->Rho[0] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx - 1];
      if ((localB->Theta[0] > 0.0) && (localB->Rho[0] < 0.0)) {
        /* '<S84>:1:44' */
        /* '<S84>:1:45' */
        localB->Rho[0] = localB->Rho[0] * -1.0;
      }
    }

    /* '<S84>:1:40' */
    if (localB->maxVotes[1] > 15.0) {
      /* '<S84>:1:41' */
      /* '<S84>:1:42' */
      localB->Theta[1] = rtu_ThetaValues[(int32_T)eml_ThetaIndex_idx_0 - 1];

      /* '<S84>:1:43' */
      localB->Rho[1] = rtu_RhoValues[(int32_T)eml_RhoIndex_idx_0 - 1];
      if ((localB->Theta[1] > 0.0) && (localB->Rho[1] < 0.0)) {
        /* '<S84>:1:44' */
        /* '<S84>:1:45' */
        localB->Rho[1] = localB->Rho[1] * -1.0;
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S82>/IsLinePresent'
 *    '<S83>/IsLinePresent'
 */
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB)
{
  /* Embedded MATLAB: '<S82>/IsLinePresent' */
  brain_c11_brain(rtu_HoughTable, rtu_ThetaValues, rtu_RhoValues, localB);
}

/* Function for Embedded MATLAB: '<S23>/GetHeadingToPath' */
static void brain_max_o(const real_T eml_varargin_1[4], real_T *eml_maxval,
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

  /* S-Function (sviphough): '<S82>/Hough Transform' */
  MWVIP_Hough_D(&rtu_BWleft1[0], &localB->HoughTransform_o1[0],
                &brain_ConstP.pooled14[0], &brain_ConstP.pooled15, 120, 80, 287,
                91);

  /* Embedded MATLAB: '<S82>/IsLinePresent' */
  brain_IsLinePresent(localB->HoughTransform_o1, localB->HoughTransform_o2,
                      localB->HoughTransform_o3, &localB->sf_IsLinePresent);

  /* S-Function (sviphough): '<S83>/Hough Transform' */
  MWVIP_Hough_D(&rtu_BWright1[0], &localB->HoughTransform_o1_p[0],
                &brain_ConstP.pooled14[0], &brain_ConstP.pooled15, 120, 80, 287,
                91);

  /* Embedded MATLAB: '<S83>/IsLinePresent' */
  brain_IsLinePresent(localB->HoughTransform_o1_p, localB->HoughTransform_o2_h,
                      localB->HoughTransform_o3_p, &localB->sf_IsLinePresent_m);

  /* SignalConversion: '<S81>/TmpSignal ConversionAt SFunction Inport1' */
  rtb_TmpSignalConversionAtSFun_o[0] = localB->sf_IsLinePresent.Theta[0];
  rtb_TmpSignalConversionAtSFun_o[1] = localB->sf_IsLinePresent.Theta[1];

  /* SignalConversion: '<S81>/TmpSignal ConversionAt SFunction Inport3' */
  rtb_TmpSignalConversionAtSFun_o[2] = localB->sf_IsLinePresent_m.Theta[0];
  rtb_TmpSignalConversionAtSFun_j[0] = localB->sf_IsLinePresent.maxVotes[0];
  rtb_TmpSignalConversionAtSFun_o[3] = localB->sf_IsLinePresent_m.Theta[1];
  rtb_TmpSignalConversionAtSFun_j[1] = localB->sf_IsLinePresent.maxVotes[1];
  rtb_TmpSignalConversionAtSFun_j[2] = localB->sf_IsLinePresent_m.maxVotes[0];
  rtb_TmpSignalConversionAtSFun_j[3] = localB->sf_IsLinePresent_m.maxVotes[1];

  /* Embedded MATLAB: '<S23>/GetHeadingToPath' */
  eml_Votes[0] = rtb_TmpSignalConversionAtSFun_j[0];
  eml_Votes[1] = rtb_TmpSignalConversionAtSFun_j[1];
  eml_Votes[2] = rtb_TmpSignalConversionAtSFun_j[2];
  eml_Votes[3] = rtb_TmpSignalConversionAtSFun_j[3];

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath': '<S81>:1' */
  /*  This function calculates the heading to the path from Theta and Rho */
  /* '<S81>:1:4' */
  /* '<S81>:1:6' */
  /* '<S81>:1:7' */
  /* '<S81>:1:8' */
  localB->ToPathHeading[0] = -999.0;
  localB->AlongPathHeading[0] = -999.0;
  localB->ToPathHeading[1] = -999.0;
  localB->AlongPathHeading[1] = -999.0;
  brain_max_o(rtb_TmpSignalConversionAtSFun_j, &eml_b, &eml_c);

  /* '<S81>:1:11' */
  eml_maxIndex_idx = eml_c;

  /* '<S81>:1:12' */
  eml_Votes[(int32_T)eml_c - 1] = 0.0;

  /* '<S81>:1:13' */
  /* '<S81>:1:15' */
  /* '<S81>:1:16' */
  brain_max_o(eml_Votes, &eml_b, &eml_c);

  /* '<S81>:1:17' */
  /* '<S81>:1:18' */
  /* '<S81>:1:21' */
  /* '<S81>:1:35' */
  /* '<S81>:1:21' */
  if (eml_maxIndex_idx <= 2.0) {
    /* '<S81>:1:22' */
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_maxIndex_idx - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
      /* '<S81>:1:23' */
      /* '<S81>:1:24' */
      localB->ToPathHeading[0] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1) - 90.0;

      /* '<S81>:1:25' */
      localB->AlongPathHeading[0] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1;
    }
  } else {
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_maxIndex_idx - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_maxIndex_idx - 1] < 1.5707963267948966E+00)) {
      /* '<S81>:1:28' */
      /* '<S81>:1:29' */
      localB->ToPathHeading[0] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1) + 90.0;

      /* '<S81>:1:30' */
      localB->AlongPathHeading[0] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_maxIndex_idx - 1] * 180.0 / 3.1415926535897931E+00 +
        rtu_CurrentHeading1;
    }
  }

  /* '<S81>:1:35' */
  if (localB->ToPathHeading[0] != -999.0) {
    /* '<S81>:1:36' */
    if (localB->ToPathHeading[0] < 0.0) {
      /* '<S81>:1:37' */
      /* '<S81>:1:38' */
      localB->ToPathHeading[0] = localB->ToPathHeading[0] + 360.0;
    } else {
      if (localB->ToPathHeading[0] > 360.0) {
        /* '<S81>:1:39' */
        /* '<S81>:1:40' */
        localB->ToPathHeading[0] = localB->ToPathHeading[0] - 360.0;
      }
    }

    if (localB->AlongPathHeading[0] < 0.0) {
      /* '<S81>:1:43' */
      /* '<S81>:1:44' */
      localB->AlongPathHeading[0] = localB->AlongPathHeading[0] + 360.0;
    } else {
      if (localB->AlongPathHeading[0] > 360.0) {
        /* '<S81>:1:45' */
        /* '<S81>:1:46' */
        localB->AlongPathHeading[0] = localB->AlongPathHeading[0] - 360.0;
      }
    }
  }

  /* '<S81>:1:21' */
  if (eml_c <= 2.0) {
    /* '<S81>:1:22' */
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_c - 1] < 1.5707963267948966E+00)) {
      /* '<S81>:1:23' */
      /* '<S81>:1:24' */
      localB->ToPathHeading[1] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c
        - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) - 90.0;

      /* '<S81>:1:25' */
      localB->AlongPathHeading[1] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
    }
  } else {
    if ((rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c - 1] >
         -1.5707963267948966E+00) && (rtb_TmpSignalConversionAtSFun_o[(int32_T)
         eml_c - 1] < 1.5707963267948966E+00)) {
      /* '<S81>:1:28' */
      /* '<S81>:1:29' */
      localB->ToPathHeading[1] = (rtb_TmpSignalConversionAtSFun_o[(int32_T)eml_c
        - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1) + 90.0;

      /* '<S81>:1:30' */
      localB->AlongPathHeading[1] = rtb_TmpSignalConversionAtSFun_o[(int32_T)
        eml_c - 1] * 180.0 / 3.1415926535897931E+00 + rtu_CurrentHeading1;
    }
  }

  /* '<S81>:1:35' */
  if (localB->ToPathHeading[1] != -999.0) {
    /* '<S81>:1:36' */
    if (localB->ToPathHeading[1] < 0.0) {
      /* '<S81>:1:37' */
      /* '<S81>:1:38' */
      localB->ToPathHeading[1] = localB->ToPathHeading[1] + 360.0;
    } else {
      if (localB->ToPathHeading[1] > 360.0) {
        /* '<S81>:1:39' */
        /* '<S81>:1:40' */
        localB->ToPathHeading[1] = localB->ToPathHeading[1] - 360.0;
      }
    }

    if (localB->AlongPathHeading[1] < 0.0) {
      /* '<S81>:1:43' */
      /* '<S81>:1:44' */
      localB->AlongPathHeading[1] = localB->AlongPathHeading[1] + 360.0;
    } else {
      if (localB->AlongPathHeading[1] > 360.0) {
        /* '<S81>:1:45' */
        /* '<S81>:1:46' */
        localB->AlongPathHeading[1] = localB->AlongPathHeading[1] - 360.0;
      }
    }
  }
}

/* Output and update for function-call system: '<Root>/StateFlow Functions' */
void StateFlowFunctionsBuoysApproa_m(real_T rtu_B_Hue, real_T rtu_B_Sat, real_T
  rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T rtu_Ref_Colors
  [150], real_T rtu_Num_Colors, rtB_StateFlowFunctionsBuoysAp_m *localB,
  rtDW_StateFlowFunctionsBuoysA_e *localDW)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  real_T eml_min_dist;
  real_T eml_i;
  uint8_T eml_i_0;
  int8_T rtb_index_o;
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
  uint32_T numBlobs;
  int32_T pixListMinc;
  int32_T pixListNinc;
  int32_T maxr;
  real_T ys;
  uint32_T k;
  real_T uyy;
  real_T rtb_BuoyBlobAnalysis_o1_j[10];
  real_T rtb_BuoyBlobAnalysis_o2_n[10];
  int32_T i;

  /* S-Function (svipcolorconv): '<S47>/Color Space  Conversion' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  eml_min_dist = 6.0 * rtu_B_Hue;
  uyy = (real_T)(uint32_T)(eml_min_dist - 1.3322676295501878E-15);
  eml_min_dist -= uyy;
  eml_i = 1.0 - rtu_B_Sat;
  ys = 1.0 - rtu_B_Sat * eml_min_dist;
  eml_min_dist = rtu_B_Sat * eml_min_dist + eml_i;
  if (uyy == 0.0) {
    cc = 1.0;
    cc_0 = eml_min_dist;
    cc_1 = eml_i;
  } else if (uyy == 1.0) {
    cc = ys;
    cc_0 = 1.0;
    cc_1 = eml_i;
  } else if (uyy == 2.0) {
    cc = eml_i;
    cc_0 = 1.0;
    cc_1 = eml_min_dist;
  } else if (uyy == 3.0) {
    cc = eml_i;
    cc_0 = ys;
    cc_1 = 1.0;
  } else if (uyy == 4.0) {
    cc = eml_min_dist;
    cc_0 = eml_i;
    cc_1 = 1.0;
  } else {
    if (uyy == 5.0) {
      cc = 1.0;
      cc_0 = eml_i;
      cc_1 = ys;
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

  /* S-Function (svipcolorconv): '<S47>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  /* Convert to XYZ */
  /* temporary variables for in-place operation */
  /* First, linearize (de-gamma) the RGB values; the operation is */
  /* equivalent to running the gamma correction block with break */
  /* point of 0.00304 and gamma of 2.4; it's built into this */
  /* conversion for convenience */
  if (localB->ColorSpaceConversion_o1 <= 3.9286085583733095E-02) {
    eml_min_dist = localB->ColorSpaceConversion_o1 / 1.2923054468333255E+01;
  } else {
    eml_min_dist = (localB->ColorSpaceConversion_o1 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    eml_min_dist = rt_pow_snf(eml_min_dist, 2.4);
  }

  if (localB->ColorSpaceConversion_o2 <= 3.9286085583733095E-02) {
    eml_i = localB->ColorSpaceConversion_o2 / 1.2923054468333255E+01;
  } else {
    eml_i = (localB->ColorSpaceConversion_o2 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    eml_i = rt_pow_snf(eml_i, 2.4);
  }

  if (localB->ColorSpaceConversion_o3 <= 3.9286085583733095E-02) {
    uyy = localB->ColorSpaceConversion_o3 / 1.2923054468333255E+01;
  } else {
    uyy = (localB->ColorSpaceConversion_o3 + 5.5000519817226347E-02) /
      1.0550005198172263E+00;
    uyy = rt_pow_snf(uyy, 2.4);
  }

  /* The coefficients for this conversion were derived from ITU-R */
  /* BT.709 reference primaries for sRGB and CIE standard illuminant */
  /* D65, 2 degree observer */
  ys = (4.1239079926596001E-01 * eml_min_dist + 3.5758433938388001E-01 * eml_i)
    + 1.8048078840182999E-01 * uyy;
  cc = (2.1263900587151000E-01 * eml_min_dist + 7.1516867876776002E-01 * eml_i)
    + 7.2192315360729994E-02 * uyy;
  eml_min_dist = (1.9330818715590000E-02 * eml_min_dist + 1.1919477979463000E-01
                  * eml_i) + 9.5053215224966003E-01 * uyy;

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

  if (eml_min_dist > 1.0) {
    eml_min_dist = 1.0;
  } else {
    if (eml_min_dist < 0.0) {
      eml_min_dist = 0.0;
    }
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = ys;
  localB->ColorSpaceConversion1_o2 = cc;
  localB->ColorSpaceConversion1_o3 = eml_min_dist;

  /* Convert from XYZ to L*a*b* */
  eml_min_dist = localB->ColorSpaceConversion1_o1 / 9.6419865576090003E-01;
  uyy = localB->ColorSpaceConversion1_o3 / 8.2511648322104003E-01;

  /* Prepare Xf, Yf, and Zf for computation of a* and b* components */
  if (eml_min_dist > 8.8564516790356311E-03) {
    ys = rt_pow_snf(eml_min_dist, 3.3333333333333331E-01);
  } else {
    ys = 7.7870370370370372E+00 * eml_min_dist + 1.3793103448275862E-01;
  }

  if (localB->ColorSpaceConversion1_o2 > 8.8564516790356311E-03) {
    eml_i = rt_pow_snf(localB->ColorSpaceConversion1_o2, 3.3333333333333331E-01);
  } else {
    eml_i = 7.7870370370370372E+00 * localB->ColorSpaceConversion1_o2 +
      1.3793103448275862E-01;
  }

  if (uyy > 8.8564516790356311E-03) {
    eml_min_dist = rt_pow_snf(uyy, 3.3333333333333331E-01);
  } else {
    eml_min_dist = 7.7870370370370372E+00 * uyy + 1.3793103448275862E-01;
  }

  /* assign the results */
  localB->ColorSpaceConversion1_o1 = 116.0 * eml_i - 16.0;
  localB->ColorSpaceConversion1_o2 = (ys - eml_i) * 500.0;
  localB->ColorSpaceConversion1_o3 = (eml_i - eml_min_dist) * 200.0;

  /* Embedded MATLAB: '<S45>/Choose Closest Color' */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Choose Closest Color': '<S46>:1' */
  /*  This function chooses the appropriate color option from the reference colors */
  /*  and set of desired L,a,b values */
  /* '<S46>:1:5' */
  /* '<S46>:1:7' */
  eml_min_dist = 1000.0;

  /* '<S46>:1:8' */
  cc_0 = rtu_Num_Colors + 1.0;
  cc_0 = cc_0 < 0.0 ? ceil(cc_0 - 0.5) : floor(cc_0 + 0.5);
  if (cc_0 < 128.0) {
    if (cc_0 >= -128.0) {
      rtb_index_o = (int8_T)cc_0;
    } else {
      rtb_index_o = MIN_int8_T;
    }
  } else if (cc_0 >= 128.0) {
    rtb_index_o = MAX_int8_T;
  } else {
    rtb_index_o = 0;
  }

  /* '<S46>:1:11' */
  for (eml_i = 1.0; eml_i <= rtu_Num_Colors; eml_i++) {
    /* '<S46>:1:11' */
    /* '<S46>:1:12' */
    uyy = sqrt((rt_pow_snf(localB->ColorSpaceConversion1_o1 - rtu_Ref_Colors
      [(int32_T)eml_i - 1], 2.0) * 2.0 + rt_pow_snf
                (localB->ColorSpaceConversion1_o2 - rtu_Ref_Colors[(int32_T)
                 eml_i + 49], 2.0)) + rt_pow_snf
               (localB->ColorSpaceConversion1_o3 - rtu_Ref_Colors[(int32_T)eml_i
                + 99], 2.0));
    if ((uyy < eml_min_dist) && (uyy < 70.0)) {
      /* '<S46>:1:13' */
      /*  L: 0 - 100,a: -100 - 100 , b: -100 - 100 */
      /* '<S46>:1:14' */
      eml_min_dist = uyy;

      /*  max min_dist = 346 if L dist is doubled */
      /* '<S46>:1:15' */
      cc_0 = floor(eml_i + 0.5);
      if (cc_0 < 128.0) {
        rtb_index_o = (int8_T)cc_0;
      } else {
        rtb_index_o = MAX_int8_T;
      }

      /*  max min_dist = 300 if L dist is not doubled */
    }
  }

  /* RelationalOperator: '<S45>/Relational Operator' */
  for (i = 0; i < 19200; i++) {
    localB->BW[i] = (rtu_LabMatrix[i] == (real_T)rtb_index_o);
  }

  /* S-Function (svipblob): '<S13>/Buoy Blob Analysis' */
  maxNumBlobsReached = FALSE;
  for (i = 0; i < 123; i++) {
    localDW->BuoyBlobAnalysis_PAD_DW[i] = 0U;
  }

  currentLabel = 1U;
  i = 0;
  idx = 123;
  for (n = 0; n < 160; n++) {
    for (n_0 = 0; n_0 < 120; n_0++) {
      localDW->BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(localB->BW[i] ? 255 : 0);
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
    idx = 1;
    maxr = n * 122;
    for (pixListMinc = 0; pixListMinc < 120; pixListMinc++) {
      numBlobs = (uint32_T)(maxr + idx);
      start_pixIdx = pixIdx;
      if (localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] == 255) {
        localDW->BuoyBlobAnalysis_PAD_DW[numBlobs] = currentLabel;
        localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)(n - 1);
        localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(idx - 1);
        pixIdx++;
        BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        localDW->BuoyBlobAnalysis_STACK_DW[stackIdx] = numBlobs;
        stackIdx++;
        while (stackIdx) {
          stackIdx--;
          numBlobs = localDW->BuoyBlobAnalysis_STACK_DW[stackIdx];
          for (pixListNinc = 0; pixListNinc < 8; pixListNinc++) {
            k = numBlobs + (uint32_T)brain_ConstP.pooled20[pixListNinc];
            if (localDW->BuoyBlobAnalysis_PAD_DW[k] == 255) {
              localDW->BuoyBlobAnalysis_PAD_DW[k] = currentLabel;
              localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(k / 122U) - 1);
              localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                122U - 1U);
              pixIdx++;
              BuoyBlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
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
          n_0 = 160;
          pixListMinc = 120;
        }

        if (pixListMinc < 120) {
          currentLabel++;
        }
      }

      idx++;
    }

    n++;
  }

  numBlobs = maxNumBlobsReached ? currentLabel : (uint8_T)(currentLabel - 1);
  currentLabel = (uint8_T)numBlobs;
  pixListMinc = 0;
  pixListNinc = 0;
  for (padRows = 0; padRows < (int32_T)numBlobs; padRows++) {
    i = 0;
    n = 0;
    for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
         padCols++) {
      i += localDW->BuoyBlobAnalysis_N_PIXLIST_DW[padCols + pixListNinc];
      n += localDW->BuoyBlobAnalysis_M_PIXLIST_DW[padCols + pixListMinc];
    }

    cc_0 = (real_T)n / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
    cc_1 = (real_T)i / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
    n = 160;
    idx = 120;
    n_0 = 0;
    maxr = 0;
    for (padCols = 0; padCols < (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
         padCols++) {
      i = padCols + pixListNinc;
      if (localDW->BuoyBlobAnalysis_N_PIXLIST_DW[i] < n) {
        n = localDW->BuoyBlobAnalysis_N_PIXLIST_DW[i];
      }

      if (localDW->BuoyBlobAnalysis_N_PIXLIST_DW[i] > n_0) {
        n_0 = localDW->BuoyBlobAnalysis_N_PIXLIST_DW[i];
      }

      i = padCols + pixListMinc;
      if (localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i] < idx) {
        idx = localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i];
      }

      if (localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i] > maxr) {
        maxr = localDW->BuoyBlobAnalysis_M_PIXLIST_DW[i];
      }
    }

    eml_min_dist = 0.0;
    ys = 0.0;
    cc = 0.0;
    for (k = 0U; k < (uint32_T)(int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows]; k
         ++) {
      eml_i = (real_T)localDW->BuoyBlobAnalysis_N_PIXLIST_DW[pixListNinc + k] -
        cc_1;
      uyy = (real_T)localDW->BuoyBlobAnalysis_M_PIXLIST_DW[pixListMinc + k] -
        cc_0;
      eml_min_dist += eml_i * eml_i;
      ys += uyy * uyy;
      cc += eml_i * (-uyy);
    }

    cc_0 = eml_min_dist / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows] +
      8.3333333333333329E-02;
    uyy = ys / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows] +
      8.3333333333333329E-02;
    eml_min_dist = cc / (real_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
    eml_min_dist = sqrt((cc_0 - uyy) * (cc_0 - uyy) + eml_min_dist *
                        eml_min_dist * 4.0);
    eml_i = ((cc_0 + uyy) + eml_min_dist) * 8.0;
    rtb_BuoyBlobAnalysis_o1_j[padRows] = sqrt(eml_i - ((cc_0 + uyy) -
      eml_min_dist) * 8.0) / sqrt(eml_i);
    rtb_BuoyBlobAnalysis_o2_n[padRows] = (real_T)
      BuoyBlobAnalysis_NUM_PIX_DW[padRows] / (real_T)(((maxr + 1) - idx) * ((n_0
      + 1) - n));
    pixListMinc += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
    pixListNinc += (int32_T)BuoyBlobAnalysis_NUM_PIX_DW[padRows];
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o1_j[i] = -1.0;
  }

  for (i = (int32_T)numBlobs; i < 10; i++) {
    rtb_BuoyBlobAnalysis_o2_n[i] = -1.0;
  }

  /* Embedded MATLAB: '<S13>/IF Buoy Conditions' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   *  Constant: '<S13>/Constant3'
   *  Constant: '<S13>/Constant4'
   */
  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/IF Buoy Conditions': '<S44>:1' */
  /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
  /*  if there is a buoy present in the current image */
  /* '<S44>:1:5' */
  localB->Image = 0.0;

  /* '<S44>:1:8' */
  for (eml_i_0 = 1U; eml_i_0 <= currentLabel; eml_i_0 = (uint8_T)(uint32_T)
       (eml_i_0 + 1)) {
    /* '<S44>:1:8' */
    if ((rtb_BuoyBlobAnalysis_o1_j[eml_i_0 - 1] > brain_P.Buoy_Min_Eccentricity)
        && (rtb_BuoyBlobAnalysis_o1_j[eml_i_0 - 1] <
            brain_P.Buoy_Max_Eccentricity) && (rtb_BuoyBlobAnalysis_o2_n[eml_i_0
         - 1] > brain_P.Buoy_Min_Extent) && (rtb_BuoyBlobAnalysis_o2_n[eml_i_0 -
         1] < brain_P.Buoy_Max_Extent)) {
      /* '<S44>:1:9' */
      /* '<S44>:1:10' */
      localB->Image = 1.0;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_enter_internal_Buoys(void)
{
  /* Transition: '<S7>:1291' */
  /* Entry 'FindBuoys': '<S7>:1295' */
  brain_DWork.is_Buoys = brain_IN_FindBuoys;
  brain_DWork.OldObstacle = FALSE;
  brain_B.CameraPosition = 0;
  brain_B.State = 4;
  brain_DWork.BuoyCount = 0.0;
  brain_B.DesiredDepth = 5.0;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countareas(real_T sf_Size, real_T sf_count1)
{
  /* Embedded MATLAB Function 'countareas': '<S7>:1366' */
  /*  This function acts to count the number of consecutive times a particular */
  /*  area is recognized by the recognition software */
  if (sf_Size > 8500.0) {
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
static void brain_ApproachBuoys(void)
{
  int32_T i;

  /* During 'ApproachBuoys': '<S7>:1312' */
  switch (brain_DWork.is_ApproachBuoys) {
   case brain_IN_ApproachFirstBuoy:
    /* During 'ApproachFirstBuoy': '<S7>:1341' */
    if (brain_DWork.countarea > 2.0) {
      /* Transition: '<S7>:1314' */
      /* Exit 'ApproachFirstBuoy': '<S7>:1341' */
      /* Entry 'FindSecondBuoy': '<S7>:1317' */
      brain_DWork.is_ApproachBuoys = brain_IN_FindSecondBuoy;

      /* Embedded MATLAB Function 'GetDirectionToLook': '<S7>:1337' */
      /*  Determine which direction the AUV needs to turn to see the next buoy */
      /*  -1 is left, 1 is right */
      /*  FirstD, SecondD are 1,2,3 - left,middle,right */
      /* '<S7>:1337:6' */
      brain_DWork.TurnDirection = brain_DWork.SecondDir - brain_DWork.FirstDir;

      /* '<S7>:1337:8' */
      brain_DWork.TurnDirection = brain_DWork.TurnDirection / fabs
        (brain_DWork.TurnDirection);
      brain_B.DesiredHeading = brain_Turn45Degrees(brain_U.CurrentHeading,
        brain_DWork.TurnDirection);
      brain_B.DesiredDepth = brain_U.CurrentDepth;

      /* Simulink Function 'GetSecondBuoyStats': '<S7>:1327' */

      /* Constant: '<S11>/Constant' */
      brain_B.Constant = brain_P.Buoy2_Hue;

      /* Constant: '<S11>/Constant2' */
      brain_B.Constant2 = brain_P.Buoy2_Saturation;

      /* Constant: '<S11>/Constant1' */
      brain_B.Constant1 = brain_P.Buoy2_Value;
      brain_DWork.BuoyHue = brain_B.Constant;
      brain_DWork.BuoySaturation = brain_B.Constant2;
      brain_DWork.BuoyValue = brain_B.Constant1;
      brain_DWork.Image = 0.0;
    } else {
      /* Simulink Function 'IterativeSegmentation': '<S7>:1374' */
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

      /* Simulink Function 'Buoy': '<S7>:1352' */
      memcpy((void *)&brain_B.LabMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
             19200U * sizeof(real_T));
      memcpy((void *)&brain_B.Ref_Colors[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      brain_B.Num_Colors = brain_DWork.num_colors;
      brain_B.B_Hue = brain_DWork.BuoyHue;
      brain_B.B_Sat = brain_DWork.BuoySaturation;
      brain_B.B_Value = brain_DWork.BuoyValue;
      StateFlowFunctionsBuoysApproa_l(brain_B.B_Hue, brain_B.B_Sat,
        brain_B.B_Value, brain_B.LabMatrix, brain_B.Ref_Colors,
        brain_B.Num_Colors, brain_M, &brain_B.StateFlowFunctionsBuoysAppro_lp,
        &brain_DWork.StateFlowFunctionsBuoysAppro_lp);
      brain_B.Right = (int8_T)brain_B.StateFlowFunctionsBuoysAppro_lp.Add;
      brain_B.Left = (int8_T)brain_B.StateFlowFunctionsBuoysAppro_lp.Add1;
      brain_B.Vertical =
        brain_B.StateFlowFunctionsBuoysAppro_lp.DataTypeConversion;
      brain_B.BuoyCentroidX =
        brain_B.StateFlowFunctionsBuoysAppro_lp.BlobCentroidY;
      brain_B.BuoyCentroidY =
        brain_B.StateFlowFunctionsBuoysAppro_lp.BlobCentroidX;
      brain_DWork.countarea = brain_countareas((real_T)(int32_T)
        brain_B.StateFlowFunctionsBuoysAppro_lp.BlobArea, brain_DWork.countarea);

      /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsBuoysAppro_lp.BW[i];
        brain_B.LabMatrix_d[i] = brain_DWork.LabelMatrix[i];
      }

      memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d, brain_B.Ref_Colors_b,
        &brain_B.StateFlowFunctionsBuoysShowSe_o);
      memcpy((void *)&brain_B.RGBout[0], (void *)
             &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
             (real_T));
    }
    break;

   case brain_IN_ApproachSecondBuoy:
    /* During 'ApproachSecondBuoy': '<S7>:1316' */
    /* Simulink Function 'IterativeSegmentation': '<S7>:1374' */
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
    brain_DWork.num_colors = brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
    memcpy((void *)&brain_DWork.ref_colors[0], (void *)
           &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U * sizeof
           (real_T));

    /* Simulink Function 'Buoy': '<S7>:1352' */
    memcpy((void *)&brain_B.LabMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.Ref_Colors[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.Num_Colors = brain_DWork.num_colors;
    brain_B.B_Hue = brain_DWork.BuoyHue;
    brain_B.B_Sat = brain_DWork.BuoySaturation;
    brain_B.B_Value = brain_DWork.BuoyValue;
    StateFlowFunctionsBuoysApproa_l(brain_B.B_Hue, brain_B.B_Sat,
      brain_B.B_Value, brain_B.LabMatrix, brain_B.Ref_Colors, brain_B.Num_Colors,
      brain_M, &brain_B.StateFlowFunctionsBuoysAppro_lp,
      &brain_DWork.StateFlowFunctionsBuoysAppro_lp);
    brain_B.Right = (int8_T)brain_B.StateFlowFunctionsBuoysAppro_lp.Add;
    brain_B.Left = (int8_T)brain_B.StateFlowFunctionsBuoysAppro_lp.Add1;
    brain_B.Vertical =
      brain_B.StateFlowFunctionsBuoysAppro_lp.DataTypeConversion;
    brain_B.BuoyCentroidX =
      brain_B.StateFlowFunctionsBuoysAppro_lp.BlobCentroidY;
    brain_B.BuoyCentroidY =
      brain_B.StateFlowFunctionsBuoysAppro_lp.BlobCentroidX;
    brain_DWork.count2ndarea = brain_countareas((real_T)(int32_T)
      brain_B.StateFlowFunctionsBuoysAppro_lp.BlobArea, brain_DWork.count2ndarea);

    /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsBuoysAppro_lp.BW[i];
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
    /* During 'FindSecondBuoy': '<S7>:1317' */
    if (brain_DWork.Image == 1.0) {
      /* Transition: '<S7>:1315' */
      /* Exit 'FindSecondBuoy': '<S7>:1317' */
      /* Entry 'ApproachSecondBuoy': '<S7>:1316' */
      brain_DWork.is_ApproachBuoys = brain_IN_ApproachSecondBuoy;
      brain_DWork.count2ndarea = 0.0;
    } else {
      /* Simulink Function 'MaintainHeading': '<S7>:1385' */
      brain_B.DesiredHeading1 = brain_B.DesiredHeading;
      brain_B.CurrentHeading1 = brain_U.CurrentHeading;
      brain_B.ForwardVelocity1 = 0.0;
      StateFlowFunctionsBuoysMainta_h(brain_B.DesiredHeading1,
        brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
        &brain_B.StateFlowFunctionsBuoysMaint_hr,
        &brain_DWork.StateFlowFunctionsBuoysMaint_hr);
      brain_B.Left = brain_B.StateFlowFunctionsBuoysMaint_hr.DoubleToint8;
      brain_B.Right = brain_B.StateFlowFunctionsBuoysMaint_hr.DoubleToint1;

      /* Simulink Function 'MaintainDepth': '<S7>:1381' */
      brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
      StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1,
        brain_B.CurrentDepth1, brain_M, &brain_B.StateFlowFunctionsBuoysMainta_c,
        &brain_DWork.StateFlowFunctionsBuoysMainta_c);
      brain_B.Vertical = brain_B.StateFlowFunctionsBuoysMainta_c.DoubleToInt8;

      /* Simulink Function 'GetStrafe': '<S7>:1331' */

      /* Constant: '<S12>/Constant' */
      brain_B.Constant_p = brain_P.Buoy_Strafe;
      brain_B.Strafe = (int8_T)brain_B.Constant_p;
      brain_B.Strafe = (int8_T)(brain_DWork.TurnDirection * (real_T)
        brain_B.Strafe);

      /* Simulink Function 'IterativeSegmentation': '<S7>:1374' */
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

      /* Simulink Function 'SecondBuoy': '<S7>:1318' */
      memcpy((void *)&brain_B.LabMatrix_h[0], (void *)&brain_DWork.LabelMatrix[0],
             19200U * sizeof(real_T));
      memcpy((void *)&brain_B.Ref_Colors_h[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      brain_B.Num_Colors_j = brain_DWork.num_colors;
      brain_B.B_Hue_h = brain_DWork.BuoyHue;
      brain_B.B_Sat_h = brain_DWork.BuoySaturation;
      brain_B.B_Value_p = brain_DWork.BuoyValue;
      StateFlowFunctionsBuoysApproa_m(brain_B.B_Hue_h, brain_B.B_Sat_h,
        brain_B.B_Value_p, brain_B.LabMatrix_h, brain_B.Ref_Colors_h,
        brain_B.Num_Colors_j, &brain_B.StateFlowFunctionsBuoysAppro_mn,
        &brain_DWork.StateFlowFunctionsBuoysAppro_mn);
      brain_DWork.Image = brain_B.StateFlowFunctionsBuoysAppro_mn.Image;

      /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.StateFlowFunctionsBuoysAppro_mn.BW[i];
        brain_B.LabMatrix_d[i] = brain_DWork.LabelMatrix[i];
      }

      memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)&brain_DWork.ref_colors[0],
             150U * sizeof(real_T));
      StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d, brain_B.Ref_Colors_b,
        &brain_B.StateFlowFunctionsBuoysShowSe_o);
      memcpy((void *)&brain_B.RGBout[0], (void *)
             &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U * sizeof
             (real_T));
    }
    break;

   default:
    /* Transition: '<S7>:1313' */
    /* Entry 'ApproachFirstBuoy': '<S7>:1341' */
    brain_DWork.is_ApproachBuoys = brain_IN_ApproachFirstBuoy;
    brain_DWork.countarea = 0.0;

    /* Simulink Function 'GetFirstBuoyStats': '<S7>:1342' */

    /* Constant: '<S8>/Constant' */
    brain_B.Constant_k = brain_P.Buoy1_Hue;

    /* Constant: '<S8>/Constant2' */
    brain_B.Constant2_i = brain_P.Buoy1_Saturation;

    /* Constant: '<S8>/Constant1' */
    brain_B.Constant1_o = brain_P.Buoy1_Value;
    brain_DWork.BuoyHue = brain_B.Constant_k;
    brain_DWork.BuoySaturation = brain_B.Constant2_i;
    brain_DWork.BuoyValue = brain_B.Constant1_o;

    /* Simulink Function 'WhichBuoysToApproach': '<S7>:1346' */
    brain_B.L_B[0] = brain_DWork.LeftBuoy[0];
    brain_B.M_B[0] = brain_DWork.MiddleBuoy[0];
    brain_B.R_B[0] = brain_DWork.RightBuoy[0];
    brain_B.L_B[1] = brain_DWork.LeftBuoy[1];
    brain_B.M_B[1] = brain_DWork.MiddleBuoy[1];
    brain_B.R_B[1] = brain_DWork.RightBuoy[1];
    brain_B.L_B[2] = brain_DWork.LeftBuoy[2];
    brain_B.M_B[2] = brain_DWork.MiddleBuoy[2];
    brain_B.R_B[2] = brain_DWork.RightBuoy[2];
    StateFlowFunctionsBuoysApproach(brain_B.L_B, brain_B.M_B, brain_B.R_B,
      &brain_B.StateFlowFunctionsBuoysApproa_f);
    brain_DWork.FirstDir = brain_B.StateFlowFunctionsBuoysApproa_f.FirstD;
    brain_DWork.SecondDir = brain_B.StateFlowFunctionsBuoysApproa_f.SecondD;
    break;
  }
}

/* Function for Embedded MATLAB: '<S15>/Blob Extraction' */
static void brain_Outputs(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3)
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
  memset((void *)&brain_DWork.PAD_DW_i[0], (int32_T)0U, 123U * sizeof(uint8_T));
  eml_currentLabel = 1U;
  eml_loop = 0;
  eml_idx = 123;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    for (eml_maxc = 0; eml_maxc < 120; eml_maxc++) {
      brain_DWork.PAD_DW_i[eml_idx] = (uint8_T)(eml_U0[eml_loop] ? 255 : 0);
      eml_loop++;
      eml_idx++;
    }

    brain_DWork.PAD_DW_i[eml_idx] = 0U;
    eml_idx++;
    brain_DWork.PAD_DW_i[eml_idx] = 0U;
    eml_idx++;
  }

  memset((void *)&brain_DWork.PAD_DW_i[eml_idx], (int32_T)0U, 121U * sizeof
         (uint8_T));
  eml_loop = 1;
  eml_stackIdx = 0U;
  eml_pixIdx = 0U;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    eml_maxc = 1;
    eml_idx = eml_loop * 122;
    for (eml_maxr = 0; eml_maxr < 120; eml_maxr++) {
      eml_k = (uint32_T)(eml_idx + eml_maxc);
      eml_start_pixIdx = eml_pixIdx;
      if (brain_DWork.PAD_DW_i[eml_k] == 255) {
        brain_DWork.PAD_DW_i[eml_k] = eml_currentLabel;
        brain_DWork.N_PIXLIST_DW_l[eml_pixIdx] = (int16_T)(eml_loop - 1);
        brain_DWork.M_PIXLIST_DW_b[eml_pixIdx] = (int16_T)(eml_maxc - 1);
        eml_pixIdx++;
        brain_DWork.NUM_PIX_DW_k[eml_currentLabel - 1] = 1U;
        brain_DWork.STACK_DW_g[eml_stackIdx] = eml_k;
        eml_stackIdx++;
        while (eml_stackIdx) {
          eml_stackIdx--;
          eml_k = brain_DWork.STACK_DW_g[eml_stackIdx];
          for (eml_pixListMinc = 0; eml_pixListMinc < 8; eml_pixListMinc++) {
            eml_walkerIdx = eml_k + (uint32_T)
              brain_DWork.WALKER_RTP_e[eml_pixListMinc];
            if (brain_DWork.PAD_DW_i[eml_walkerIdx] == 255) {
              brain_DWork.PAD_DW_i[eml_walkerIdx] = eml_currentLabel;
              brain_DWork.N_PIXLIST_DW_l[eml_pixIdx] = (int16_T)((int16_T)
                (eml_walkerIdx / 122U) - 1);
              brain_DWork.M_PIXLIST_DW_b[eml_pixIdx] = (int16_T)(eml_walkerIdx %
                122U - 1U);
              eml_pixIdx++;
              brain_DWork.NUM_PIX_DW_k[eml_currentLabel - 1] =
                brain_DWork.NUM_PIX_DW_k[eml_currentLabel - 1] + 1U;
              brain_DWork.STACK_DW_g[eml_stackIdx] = eml_walkerIdx;
              eml_stackIdx++;
            }
          }
        }

        if (brain_DWork.NUM_PIX_DW_k[eml_currentLabel - 1] <
            brain_DWork.MINAREA_RTP_l) {
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
    for (eml_j = 0; eml_j < (int32_T)brain_DWork.NUM_PIX_DW_k[eml_c_i]; eml_j++)
    {
      eml_loop += brain_DWork.N_PIXLIST_DW_l[eml_j + eml_pixListNinc];
      eml_n += brain_DWork.M_PIXLIST_DW_b[eml_j + eml_pixListMinc];
    }

    eml_centroid_idx = (real_T)eml_n / (real_T)brain_DWork.NUM_PIX_DW_k[eml_c_i];
    eml_centroid_idx_0 = (real_T)eml_loop / (real_T)
      brain_DWork.NUM_PIX_DW_k[eml_c_i];
    eml_Y0[eml_c_i << 1] = eml_centroid_idx;
    eml_Y0[(eml_c_i << 1) + 1] = eml_centroid_idx_0;
    eml_n = 160;
    eml_idx = 120;
    eml_maxc = 0;
    eml_maxr = 0;
    for (eml_j = 0; eml_j < (int32_T)brain_DWork.NUM_PIX_DW_k[eml_c_i]; eml_j++)
    {
      eml_loop = eml_j + eml_pixListNinc;
      if (brain_DWork.N_PIXLIST_DW_l[eml_loop] < eml_n) {
        eml_n = brain_DWork.N_PIXLIST_DW_l[eml_loop];
      }

      if (brain_DWork.N_PIXLIST_DW_l[eml_loop] > eml_maxc) {
        eml_maxc = brain_DWork.N_PIXLIST_DW_l[eml_loop];
      }

      eml_loop = eml_j + eml_pixListMinc;
      if (brain_DWork.M_PIXLIST_DW_b[eml_loop] < eml_idx) {
        eml_idx = brain_DWork.M_PIXLIST_DW_b[eml_loop];
      }

      if (brain_DWork.M_PIXLIST_DW_b[eml_loop] > eml_maxr) {
        eml_maxr = brain_DWork.M_PIXLIST_DW_b[eml_loop];
      }
    }

    eml_xs = 0.0;
    eml_ys = 0.0;
    eml_xys = 0.0;
    for (eml_k = 0U; eml_k < (uint32_T)(int32_T)brain_DWork.NUM_PIX_DW_k[eml_c_i];
         eml_k++) {
      eml_majorAxis = (real_T)brain_DWork.N_PIXLIST_DW_l[eml_pixListNinc + eml_k]
        - eml_centroid_idx_0;
      eml_uyy = (real_T)brain_DWork.M_PIXLIST_DW_b[eml_pixListMinc + eml_k] -
        eml_centroid_idx;
      eml_xs += eml_majorAxis * eml_majorAxis;
      eml_ys += eml_uyy * eml_uyy;
      eml_xys += eml_majorAxis * (-eml_uyy);
    }

    eml_centroid_idx = eml_xs / (real_T)brain_DWork.NUM_PIX_DW_k[eml_c_i] +
      8.3333333333333329E-02;
    eml_uyy = eml_ys / (real_T)brain_DWork.NUM_PIX_DW_k[eml_c_i] +
      8.3333333333333329E-02;
    eml_xs = eml_xys / (real_T)brain_DWork.NUM_PIX_DW_k[eml_c_i];
    eml_xs = sqrt((eml_centroid_idx - eml_uyy) * (eml_centroid_idx - eml_uyy) +
                  eml_xs * eml_xs * 4.0);
    eml_majorAxis = ((eml_centroid_idx + eml_uyy) + eml_xs) * 8.0;
    eml_Y1[eml_c_i] = sqrt(eml_majorAxis - ((eml_centroid_idx + eml_uyy) -
      eml_xs) * 8.0) / sqrt(eml_majorAxis);
    eml_Y2[eml_c_i] = (real_T)brain_DWork.NUM_PIX_DW_k[eml_c_i] / (real_T)
      (((eml_maxr + 1) - eml_idx) * ((eml_maxc + 1) - eml_n));
    eml_pixListMinc += (int32_T)brain_DWork.NUM_PIX_DW_k[eml_c_i];
    eml_pixListNinc += (int32_T)brain_DWork.NUM_PIX_DW_k[eml_c_i];
  }

  for (eml_loop = eml_numBlobs << 1; eml_loop < 100; eml_loop++) {
    eml_Y0[eml_loop] = brain_DWork.F0_RTP_n;
  }

  for (eml_loop = eml_numBlobs; eml_loop < 50; eml_loop++) {
    eml_Y1[eml_loop] = brain_DWork.F1_RTP_b;
  }

  while (eml_numBlobs < 50) {
    eml_Y2[eml_numBlobs] = brain_DWork.F2_RTP_f;
    eml_numBlobs++;
  }
}

/* Function for Embedded MATLAB: '<S15>/Blob Extraction' */
static void brain_c3_brain(void)
{
  real_T eml_num_colors;
  uint8_T eml_TotalNum;
  real_T eml_k;
  int32_T eml_j;
  uint8_T eml_b_i;
  real_T eml_b[100];
  real_T eml_TEccent[50];
  real_T eml_TExtent[50];
  uint8_T eml_TNumBlobs;
  int32_T i;
  uint8_T tmp;
  eml_num_colors = brain_B.num_colors;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/Blob Extraction': '<S51>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S51>:1:7' */
  for (i = 0; i < 19200; i++) {
    brain_B.eml_LogicMatrix[i] = FALSE;
  }

  /* '<S51>:1:9' */
  /* '<S51>:1:13' */
  /* '<S51>:1:14' */
  for (i = 0; i < 50; i++) {
    brain_B.Eccent_j[i] = 0.0;
    brain_B.Extent_f[i] = 0.0;
  }

  /* '<S51>:1:16' */
  eml_TotalNum = 0U;

  /* '<S51>:1:26' */
  for (eml_k = 1.0; eml_k <= eml_num_colors; eml_k++) {
    /* '<S51>:1:26' */
    /* '<S51>:1:27' */
    for (i = 0; i < 120; i++) {
      /* '<S51>:1:27' */
      /* '<S51>:1:28' */
      for (eml_j = 0; eml_j < 160; eml_j++) {
        /* '<S51>:1:28' */
        if (brain_B.LabMatrix_b[120 * eml_j + i] != eml_k) {
          /* '<S51>:1:29' */
          /* '<S51>:1:30' */
          brain_B.eml_LogicMatrix[i + 120 * eml_j] = FALSE;
        } else {
          /* '<S51>:1:32' */
          brain_B.eml_LogicMatrix[i + 120 * eml_j] = TRUE;
        }
      }
    }

    brain_Outputs(&brain_B.eml_LogicMatrix[0], eml_b, eml_TEccent, eml_TExtent,
                  &eml_TNumBlobs);
    i = eml_TotalNum + eml_TNumBlobs;
    if ((uint32_T)i > 255U) {
      tmp = MAX_uint8_T;
    } else {
      tmp = (uint8_T)i;
    }

    if (tmp < 50) {
      /* '<S51>:1:38' */
      /* '<S51>:1:39' */
      for (eml_b_i = 1U; eml_b_i <= eml_TNumBlobs; eml_b_i = (uint8_T)(uint32_T)
           (eml_b_i + 1)) {
        /* '<S51>:1:39' */
        /* '<S51>:1:42' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Eccent_j[tmp - 1] = eml_TEccent[eml_b_i - 1];

        /* '<S51>:1:43' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Extent_f[tmp - 1] = eml_TExtent[eml_b_i - 1];
      }

      /* '<S51>:1:45' */
      i = eml_TotalNum + eml_TNumBlobs;
      if ((uint32_T)i > 255U) {
        eml_TotalNum = MAX_uint8_T;
      } else {
        eml_TotalNum = (uint8_T)i;
      }
    }
  }

  brain_B.TotalNum_f = eml_TotalNum;
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages_m(real_T sf_Image1, real_T sf_OldImage, real_T
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

/* Function for Embedded MATLAB: '<S14>/Blob Extraction' */
static void brain_Outputs_f(const boolean_T eml_U0[19200], real_T eml_Y0[100],
  real_T eml_Y1[50], real_T eml_Y2[50], uint8_T *eml_Y3)
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
  memset((void *)&brain_DWork.PAD_DW[0], (int32_T)0U, 123U * sizeof(uint8_T));
  eml_currentLabel = 1U;
  eml_loop = 0;
  eml_idx = 123;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    for (eml_maxc = 0; eml_maxc < 120; eml_maxc++) {
      brain_DWork.PAD_DW[eml_idx] = (uint8_T)(eml_U0[eml_loop] ? 255 : 0);
      eml_loop++;
      eml_idx++;
    }

    brain_DWork.PAD_DW[eml_idx] = 0U;
    eml_idx++;
    brain_DWork.PAD_DW[eml_idx] = 0U;
    eml_idx++;
  }

  memset((void *)&brain_DWork.PAD_DW[eml_idx], (int32_T)0U, 121U * sizeof
         (uint8_T));
  eml_loop = 1;
  eml_stackIdx = 0U;
  eml_pixIdx = 0U;
  for (eml_n = 0; eml_n < 160; eml_n++) {
    eml_maxc = 1;
    eml_idx = eml_loop * 122;
    for (eml_maxr = 0; eml_maxr < 120; eml_maxr++) {
      eml_k = (uint32_T)(eml_idx + eml_maxc);
      eml_start_pixIdx = eml_pixIdx;
      if (brain_DWork.PAD_DW[eml_k] == 255) {
        brain_DWork.PAD_DW[eml_k] = eml_currentLabel;
        brain_DWork.N_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_loop - 1);
        brain_DWork.M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_maxc - 1);
        eml_pixIdx++;
        brain_DWork.NUM_PIX_DW[eml_currentLabel - 1] = 1U;
        brain_DWork.STACK_DW[eml_stackIdx] = eml_k;
        eml_stackIdx++;
        while (eml_stackIdx) {
          eml_stackIdx--;
          eml_k = brain_DWork.STACK_DW[eml_stackIdx];
          for (eml_pixListMinc = 0; eml_pixListMinc < 8; eml_pixListMinc++) {
            eml_walkerIdx = eml_k + (uint32_T)
              brain_DWork.WALKER_RTP[eml_pixListMinc];
            if (brain_DWork.PAD_DW[eml_walkerIdx] == 255) {
              brain_DWork.PAD_DW[eml_walkerIdx] = eml_currentLabel;
              brain_DWork.N_PIXLIST_DW[eml_pixIdx] = (int16_T)((int16_T)
                (eml_walkerIdx / 122U) - 1);
              brain_DWork.M_PIXLIST_DW[eml_pixIdx] = (int16_T)(eml_walkerIdx %
                122U - 1U);
              eml_pixIdx++;
              brain_DWork.NUM_PIX_DW[eml_currentLabel - 1] =
                brain_DWork.NUM_PIX_DW[eml_currentLabel - 1] + 1U;
              brain_DWork.STACK_DW[eml_stackIdx] = eml_walkerIdx;
              eml_stackIdx++;
            }
          }
        }

        if (brain_DWork.NUM_PIX_DW[eml_currentLabel - 1] <
            brain_DWork.MINAREA_RTP) {
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
    for (eml_j = 0; eml_j < (int32_T)brain_DWork.NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop += brain_DWork.N_PIXLIST_DW[eml_j + eml_pixListNinc];
      eml_n += brain_DWork.M_PIXLIST_DW[eml_j + eml_pixListMinc];
    }

    eml_centroid_idx = (real_T)eml_n / (real_T)brain_DWork.NUM_PIX_DW[eml_c_i];
    eml_centroid_idx_0 = (real_T)eml_loop / (real_T)
      brain_DWork.NUM_PIX_DW[eml_c_i];
    eml_Y0[eml_c_i << 1] = eml_centroid_idx;
    eml_Y0[(eml_c_i << 1) + 1] = eml_centroid_idx_0;
    eml_n = 160;
    eml_idx = 120;
    eml_maxc = 0;
    eml_maxr = 0;
    for (eml_j = 0; eml_j < (int32_T)brain_DWork.NUM_PIX_DW[eml_c_i]; eml_j++) {
      eml_loop = eml_j + eml_pixListNinc;
      if (brain_DWork.N_PIXLIST_DW[eml_loop] < eml_n) {
        eml_n = brain_DWork.N_PIXLIST_DW[eml_loop];
      }

      if (brain_DWork.N_PIXLIST_DW[eml_loop] > eml_maxc) {
        eml_maxc = brain_DWork.N_PIXLIST_DW[eml_loop];
      }

      eml_loop = eml_j + eml_pixListMinc;
      if (brain_DWork.M_PIXLIST_DW[eml_loop] < eml_idx) {
        eml_idx = brain_DWork.M_PIXLIST_DW[eml_loop];
      }

      if (brain_DWork.M_PIXLIST_DW[eml_loop] > eml_maxr) {
        eml_maxr = brain_DWork.M_PIXLIST_DW[eml_loop];
      }
    }

    eml_xs = 0.0;
    eml_ys = 0.0;
    eml_xys = 0.0;
    for (eml_k = 0U; eml_k < (uint32_T)(int32_T)brain_DWork.NUM_PIX_DW[eml_c_i];
         eml_k++) {
      eml_majorAxis = (real_T)brain_DWork.N_PIXLIST_DW[eml_pixListNinc + eml_k]
        - eml_centroid_idx_0;
      eml_uyy = (real_T)brain_DWork.M_PIXLIST_DW[eml_pixListMinc + eml_k] -
        eml_centroid_idx;
      eml_xs += eml_majorAxis * eml_majorAxis;
      eml_ys += eml_uyy * eml_uyy;
      eml_xys += eml_majorAxis * (-eml_uyy);
    }

    eml_centroid_idx = eml_xs / (real_T)brain_DWork.NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-02;
    eml_uyy = eml_ys / (real_T)brain_DWork.NUM_PIX_DW[eml_c_i] +
      8.3333333333333329E-02;
    eml_xs = eml_xys / (real_T)brain_DWork.NUM_PIX_DW[eml_c_i];
    eml_xs = sqrt((eml_centroid_idx - eml_uyy) * (eml_centroid_idx - eml_uyy) +
                  eml_xs * eml_xs * 4.0);
    eml_majorAxis = ((eml_centroid_idx + eml_uyy) + eml_xs) * 8.0;
    eml_Y1[eml_c_i] = sqrt(eml_majorAxis - ((eml_centroid_idx + eml_uyy) -
      eml_xs) * 8.0) / sqrt(eml_majorAxis);
    eml_Y2[eml_c_i] = (real_T)brain_DWork.NUM_PIX_DW[eml_c_i] / (real_T)
      (((eml_maxr + 1) - eml_idx) * ((eml_maxc + 1) - eml_n));
    eml_pixListMinc += (int32_T)brain_DWork.NUM_PIX_DW[eml_c_i];
    eml_pixListNinc += (int32_T)brain_DWork.NUM_PIX_DW[eml_c_i];
  }

  for (eml_loop = eml_numBlobs << 1; eml_loop < 100; eml_loop++) {
    eml_Y0[eml_loop] = brain_DWork.F0_RTP;
  }

  for (eml_loop = eml_numBlobs; eml_loop < 50; eml_loop++) {
    eml_Y1[eml_loop] = brain_DWork.F1_RTP;
  }

  while (eml_numBlobs < 50) {
    eml_Y2[eml_numBlobs] = brain_DWork.F2_RTP;
    eml_numBlobs++;
  }
}

/* Function for Embedded MATLAB: '<S14>/Blob Extraction' */
static void brain_c5_brain(void)
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
  eml_num_colors = brain_B.num_colors_e;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Blob Extraction': '<S48>:1' */
  /*  This function will determine the characteristics of the blobs in an image */
  /*  given a label matrix defining the different binary images contained in a */
  /*  that label matrix */
  /* '<S48>:1:7' */
  for (i = 0; i < 19200; i++) {
    brain_B.eml_LogicMatrix_m[i] = FALSE;
  }

  /* '<S48>:1:9' */
  /* '<S48>:1:12' */
  memset((void *)&brain_B.Centroid[0], (int32_T)0.0, 100U * sizeof(real_T));

  /* '<S48>:1:13' */
  /* '<S48>:1:14' */
  for (i = 0; i < 50; i++) {
    brain_B.Eccent[i] = 0.0;
    brain_B.Extent[i] = 0.0;
  }

  /* '<S48>:1:16' */
  eml_TotalNum = 0U;

  /* '<S48>:1:26' */
  for (eml_k = 1.0; eml_k <= eml_num_colors; eml_k++) {
    /* '<S48>:1:26' */
    /* '<S48>:1:27' */
    for (i = 0; i < 120; i++) {
      /* '<S48>:1:27' */
      /* '<S48>:1:28' */
      for (eml_j = 0; eml_j < 160; eml_j++) {
        /* '<S48>:1:28' */
        if (brain_B.LabelMatrix[120 * eml_j + i] != eml_k) {
          /* '<S48>:1:29' */
          /* '<S48>:1:30' */
          brain_B.eml_LogicMatrix_m[i + 120 * eml_j] = FALSE;
        } else {
          /* '<S48>:1:32' */
          brain_B.eml_LogicMatrix_m[i + 120 * eml_j] = TRUE;
        }
      }
    }

    brain_Outputs_f(&brain_B.eml_LogicMatrix_m[0], eml_TCentroid, eml_TEccent,
                    eml_TExtent, &eml_TNumBlobs);
    i = eml_TNumBlobs + eml_TotalNum;
    if ((uint32_T)i > 255U) {
      tmp = MAX_uint8_T;
    } else {
      tmp = (uint8_T)i;
    }

    if (tmp < 50) {
      /* '<S48>:1:38' */
      /* '<S48>:1:39' */
      for (eml_b_i = 1U; eml_b_i <= eml_TNumBlobs; eml_b_i = (uint8_T)(uint32_T)
           (eml_b_i + 1)) {
        /* '<S48>:1:39' */
        /* '<S48>:1:40' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Centroid[tmp - 1] = eml_TCentroid[(eml_b_i - 1) << 1];

        /* '<S48>:1:41' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Centroid[tmp + 49] = eml_TCentroid[((eml_b_i - 1) << 1) + 1];

        /* '<S48>:1:42' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Eccent[tmp - 1] = eml_TEccent[eml_b_i - 1];

        /* '<S48>:1:43' */
        i = eml_TotalNum + eml_b_i;
        if ((uint32_T)i > 255U) {
          tmp = MAX_uint8_T;
        } else {
          tmp = (uint8_T)i;
        }

        brain_B.Extent[tmp - 1] = eml_TExtent[eml_b_i - 1];
      }

      /* '<S48>:1:45' */
      i = eml_TotalNum + eml_TNumBlobs;
      if ((uint32_T)i > 255U) {
        eml_TotalNum = MAX_uint8_T;
      } else {
        eml_TotalNum = (uint8_T)i;
      }
    }
  }

  brain_B.TotalNum = eml_TotalNum;
}

/* Function for Embedded MATLAB: '<S14>/Say Which Buoy Is Which' */
static void brain_min(const real_T eml_varargin_1[3], real_T *eml_minval, real_T
                      *eml_indx)
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
    while (((uint32_T)eml_exitg == 0U) && (eml_k < 4)) {
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
    for (eml_k = eml_itmp + 1; eml_k < 4; eml_k++) {
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

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_exit_internal_Buoys(void)
{
  real_T eml_count;
  uint8_T eml_i;
  real_T eml_colors[9];
  real_T eml_centX[3];
  real_T eml_right_ref;
  real_T rtb_Centroid_Out[100];
  int32_T i;
  int32_T eml_mid_ref;
  int32_T eml_left_ref;
  real_T eml_centY;
  real_T eml_centX_0;
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
    /* Simulink Function 'GetBuoyColors': '<S7>:1305' */
    memcpy((void *)&brain_B.LabelMatrix[0], (void *)&brain_DWork.LabelMatrix[0],
           19200U * sizeof(real_T));
    memcpy((void *)&brain_B.ref_colors[0], (void *)&brain_DWork.ref_colors[0],
           150U * sizeof(real_T));
    brain_B.num_colors_e = brain_DWork.num_colors;

    /* Embedded MATLAB: '<S14>/Blob Extraction' */
    brain_c5_brain();

    /* Embedded MATLAB: '<S14>/IF Buoy Conditions' incorporates:
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S14>/Constant2'
     *  Constant: '<S14>/Constant3'
     */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions': '<S49>:1' */
    /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
    /*  the cenroids of the most circular objects in the image */
    /* '<S49>:1:5' */
    eml_count = 0.0;

    /* '<S49>:1:6' */
    memset((void *)&rtb_Centroid_Out[0], (int32_T)0.0, 100U * sizeof(real_T));

    /* '<S49>:1:9' */
    for (eml_i = 1U; eml_i <= brain_B.TotalNum; eml_i = (uint8_T)(uint32_T)
         (eml_i + 1)) {
      /* '<S49>:1:9' */
      if ((brain_B.Eccent[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
          (brain_B.Eccent[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
          (brain_B.Extent[eml_i - 1] > brain_P.Buoy_Min_Extent) &&
          (brain_B.Extent[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
        /* '<S49>:1:10' */
        /* '<S49>:1:11' */
        eml_count++;

        /* '<S49>:1:12' */
        rtb_Centroid_Out[(int32_T)eml_count - 1] = brain_B.Centroid[eml_i - 1];

        /* '<S49>:1:13' */
        rtb_Centroid_Out[(int32_T)eml_count + 49] = brain_B.Centroid[eml_i + 49];
      }
    }

    /* Embedded MATLAB: '<S14>/Say Which Buoy Is Which' */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which': '<S50>:1' */
    /*  This function determines which buoy is in which location, left, middle, */
    /*  or right. */
    /* '<S50>:1:5' */
    memset((void *)&eml_colors[0], (int32_T)0.0, 9U * sizeof(real_T));

    /* '<S50>:1:6' */
    /* '<S50>:1:7' */
    eml_centX[0] = 0.0;
    eml_centX[1] = 0.0;
    eml_centX[2] = 0.0;

    /* '<S50>:1:10' */
    /* '<S50>:1:11' */
    eml_centX_0 = floor(rtb_Centroid_Out[50]);

    /* '<S50>:1:12' */
    eml_centY = floor(rtb_Centroid_Out[0]);
    if (eml_centX_0 < 1.0) {
      /* '<S50>:1:13' */
      /* '<S50>:1:14' */
      eml_centX_0 = 1.0;
    }

    if (eml_centY < 1.0) {
      /* '<S50>:1:16' */
      /* '<S50>:1:17' */
      eml_centY = 1.0;
    }

    /* '<S50>:1:20' */
    eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 + ((int32_T)
      eml_centY - 1)];

    /* '<S50>:1:22' */
    eml_colors[0] = brain_B.ref_colors[(int32_T)eml_count - 1];
    eml_colors[3] = brain_B.ref_colors[(int32_T)eml_count + 49];
    eml_colors[6] = brain_B.ref_colors[(int32_T)eml_count + 99];
    eml_centX[0] = eml_centX_0;

    /* '<S50>:1:10' */
    /* '<S50>:1:11' */
    eml_centX_0 = floor(rtb_Centroid_Out[51]);

    /* '<S50>:1:12' */
    eml_centY = floor(rtb_Centroid_Out[1]);
    if (eml_centX_0 < 1.0) {
      /* '<S50>:1:13' */
      /* '<S50>:1:14' */
      eml_centX_0 = 1.0;
    }

    if (eml_centY < 1.0) {
      /* '<S50>:1:16' */
      /* '<S50>:1:17' */
      eml_centY = 1.0;
    }

    /* '<S50>:1:20' */
    eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 + ((int32_T)
      eml_centY - 1)];

    /* '<S50>:1:22' */
    eml_colors[1] = brain_B.ref_colors[(int32_T)eml_count - 1];
    eml_colors[4] = brain_B.ref_colors[(int32_T)eml_count + 49];
    eml_colors[7] = brain_B.ref_colors[(int32_T)eml_count + 99];
    eml_centX[1] = eml_centX_0;

    /* '<S50>:1:10' */
    /* '<S50>:1:11' */
    eml_centX_0 = floor(rtb_Centroid_Out[52]);

    /* '<S50>:1:12' */
    eml_centY = floor(rtb_Centroid_Out[2]);
    if (eml_centX_0 < 1.0) {
      /* '<S50>:1:13' */
      /* '<S50>:1:14' */
      eml_centX_0 = 1.0;
    }

    if (eml_centY < 1.0) {
      /* '<S50>:1:16' */
      /* '<S50>:1:17' */
      eml_centY = 1.0;
    }

    /* '<S50>:1:20' */
    eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 + ((int32_T)
      eml_centY - 1)];

    /* '<S50>:1:22' */
    eml_colors[2] = brain_B.ref_colors[(int32_T)eml_count - 1];
    eml_colors[5] = brain_B.ref_colors[(int32_T)eml_count + 49];
    eml_colors[8] = brain_B.ref_colors[(int32_T)eml_count + 99];
    eml_centX[2] = eml_centX_0;
    brain_min(eml_centX, &eml_count, &eml_centY);

    /* '<S50>:1:26' */
    eml_centX[(int32_T)eml_centY - 1] = 1000.0;
    brain_min(eml_centX, &eml_count, &eml_centX_0);

    /* '<S50>:1:28' */
    eml_centX[(int32_T)eml_centX_0 - 1] = 1000.0;
    brain_min(eml_centX, &eml_count, &eml_right_ref);

    /* '<S50>:1:31' */
    i = (int32_T)eml_right_ref - 1;

    /* '<S50>:1:32' */
    eml_mid_ref = (int32_T)eml_centX_0 - 1;

    /* '<S50>:1:33' */
    eml_left_ref = (int32_T)eml_centY - 1;
    brain_B.right[0] = eml_colors[i];
    brain_B.mid[0] = eml_colors[eml_mid_ref];
    brain_B.left[0] = eml_colors[eml_left_ref];
    brain_DWork.LeftBuoy[0] = brain_B.left[0];
    brain_DWork.MiddleBuoy[0] = brain_B.mid[0];
    brain_DWork.RightBuoy[0] = brain_B.right[0];
    brain_B.right[1] = eml_colors[i + 3];
    brain_B.mid[1] = eml_colors[eml_mid_ref + 3];
    brain_B.left[1] = eml_colors[eml_left_ref + 3];
    brain_DWork.LeftBuoy[1] = brain_B.left[1];
    brain_DWork.MiddleBuoy[1] = brain_B.mid[1];
    brain_DWork.RightBuoy[1] = brain_B.right[1];
    brain_B.right[2] = eml_colors[i + 6];
    brain_B.mid[2] = eml_colors[eml_mid_ref + 6];
    brain_B.left[2] = eml_colors[eml_left_ref + 6];
    brain_DWork.LeftBuoy[2] = brain_B.left[2];
    brain_DWork.MiddleBuoy[2] = brain_B.mid[2];
    brain_DWork.RightBuoy[2] = brain_B.right[2];
    brain_DWork.is_Buoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;

   default:
    brain_DWork.is_Buoys = (uint8_T)brain_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_ControlledRC(void)
{
  /* During 'ControlledRC': '<S7>:1260' */
  if (brain_DWork.OperationalState != 1) {
    /* Transition: '<S7>:1268' */
    /* Exit 'ControlledRC': '<S7>:1260' */
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Strafe = 0;

    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    /* Simulink Function 'MaintainDepth': '<S7>:926' */
    brain_B.CurrentDepth1_g = (real32_T)brain_U.CurrentDepth;
    brain_B.DesiredDepth1_e = (real32_T)brain_U.RC_Depth;
    StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1_e,
      brain_B.CurrentDepth1_g, brain_M, &brain_B.StateFlowFunctionsMaintainDepth,
      &brain_DWork.StateFlowFunctionsMaintainDepth);
    brain_B.Vertical = brain_B.StateFlowFunctionsMaintainDepth.DoubleToInt8;

    /* Simulink Function 'MaintainHeading': '<S7>:918' */
    brain_B.DesiredHeading1_j = brain_U.RC_Heading;
    brain_B.CurrentHeading1_n = brain_U.CurrentHeading;
    brain_B.ForwardVelocity1_o = brain_U.RC_ForwardVelocity;
    StateFlowFunctionsBuoysMainta_h(brain_B.DesiredHeading1_j,
      brain_B.CurrentHeading1_n, brain_B.ForwardVelocity1_o, brain_M,
      &brain_B.StateFlowFunctionsMaintainHeadi,
      &brain_DWork.StateFlowFunctionsMaintainHeadi);
    brain_B.Left = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint8;
    brain_B.Right = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint1;
    brain_B.Strafe = (int8_T)brain_U.RC_Strafe;
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

/* Function for Embedded MATLAB: '<S86>/HSV Threshold Segmentation' */
static void brain_refp1_cos(real_T eml_x[19200])
{
  int32_T eml_k;
  for (eml_k = 0; eml_k < 19200; eml_k++) {
    eml_x[eml_k] = cos(eml_x[eml_k]);
  }
}

/* Function for Embedded MATLAB: '<S86>/HSV Threshold Segmentation' */
static void brain_c9_brain(void)
{
  real_T eml_SaturationThreshold;
  int32_T eml_x;
  int32_T eml_b_y;
  real_T eml_c_y;
  eml_SaturationThreshold = brain_P.Track_Saturation;

  /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.HSVSegmentation_VerticalSplit/Finding Brightest Pixel/HSV Threshold Segmentation': '<S87>:1' */
  /*  This function takes a HSV image as input and determines whether or not */
  /*  each pixel meets the criteria defined by the end user according to */
  /*  saturation and hue requirements. If the pixel does, then the location is */
  /*  given a value of 1, otherwise, a value of 0. */
  /* '<S87>:1:9' */
  /* '<S87>:1:11' */
  /* '<S87>:1:12' */
  for (eml_x = 0; eml_x < 9600; eml_x++) {
    brain_B.eml_BWleft[eml_x] = 0;
    brain_B.eml_BWright[eml_x] = 0;
  }

  /* '<S87>:1:14' */
  eml_c_y = 6.2831853071795862E+00 * brain_B.DesiredH1;
  for (eml_x = 0; eml_x < 160; eml_x++) {
    for (eml_b_y = 0; eml_b_y < 120; eml_b_y++) {
      brain_B.eml_hoistedExpr[eml_b_y + 120 * eml_x] = brain_B.HSV1[120 * eml_x
        + eml_b_y] * 6.2831853071795862E+00 - eml_c_y;
    }
  }

  brain_refp1_cos(&brain_B.eml_hoistedExpr[0]);
  for (eml_x = 0; eml_x < 19200; eml_x++) {
    brain_B.eml_hoistedExpr[eml_x] = (brain_B.eml_hoistedExpr[eml_x] + 1.0) /
      2.0;
  }

  /*  Left half */
  /* '<S87>:1:17' */
  for (eml_x = 0; eml_x < 80; eml_x++) {
    /* '<S87>:1:17' */
    /* '<S87>:1:18' */
    for (eml_b_y = 0; eml_b_y < 120; eml_b_y++) {
      /* '<S87>:1:18' */
      if ((brain_B.eml_hoistedExpr[120 * eml_x + eml_b_y] > 0.85) &&
          (brain_B.HSV1[(120 * eml_x + eml_b_y) + 19200] >
           eml_SaturationThreshold)) {
        /* '<S87>:1:19' */
        /* '<S87>:1:20' */
        brain_B.eml_BWleft[eml_b_y + 120 * eml_x] = 1;
      }
    }
  }

  /*  Right half */
  /* '<S87>:1:26' */
  for (eml_x = 81; eml_x < 161; eml_x++) {
    /* '<S87>:1:26' */
    /* '<S87>:1:27' */
    for (eml_b_y = 0; eml_b_y < 120; eml_b_y++) {
      /* '<S87>:1:27' */
      if ((brain_B.eml_hoistedExpr[(eml_x - 1) * 120 + eml_b_y] > 0.85) &&
          (brain_B.HSV1[((eml_x - 1) * 120 + eml_b_y) + 19200] >
           eml_SaturationThreshold)) {
        /* '<S87>:1:28' */
        /* '<S87>:1:29' */
        brain_B.eml_BWright[eml_b_y + 120 * (eml_x - 81)] = 1;
      }
    }
  }

  for (eml_x = 0; eml_x < 9600; eml_x++) {
    brain_B.BWleft[eml_x] = (real_T)brain_B.eml_BWleft[eml_x];
    brain_B.BWright[eml_x] = (real_T)brain_B.eml_BWright[eml_x];
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
  real_T rtb_Sum;
  real_T rtb_TSamp;
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
      brain_B.DesiredHeading = brain_DWork.HeadingAlongPath;
      brain_DWork.Done = 1.0;
    } else {
      /* Simulink Function 'CenterOver': '<S7>:1177' */
      for (i = 0; i < 19200; i++) {
        brain_B.H_k[i] = brain_B.Resize[i];
        brain_B.S_a[i] = brain_B.Resize1[i];
      }

      brain_DWork.StateFlowFunctionsFollowOnePa_m = brain_M->Timing.clockTick0 -
        brain_DWork.StateFlowFunctionsFollowOnePa_e;
      brain_DWork.StateFlowFunctionsFollowOnePa_e = brain_M->Timing.clockTick0;

      /* Logic: '<S22>/Logical Operator1' incorporates:
       *  Constant: '<S70>/Constant'
       *  Constant: '<S71>/Constant'
       *  Constant: '<S72>/Constant'
       *  Logic: '<S22>/Logical Operator'
       *  RelationalOperator: '<S70>/Compare'
       *  RelationalOperator: '<S71>/Compare'
       *  RelationalOperator: '<S72>/Compare'
       */
      for (i = 0; i < 19200; i++) {
        brain_B.BW_k[i] = (((brain_B.H_k[i] > brain_P.Track_HueHigher) ||
                            (brain_B.H_k[i] <= brain_P.Track_HueLower)) &&
                           (brain_B.S_a[i] > brain_P.Track_Saturation));
      }

      /* S-Function (svipblob): '<S22>/Buoy Blob Analysis' */
      maxNumBlobsReached = FALSE;
      for (loop = 0; loop < 123; loop++) {
        brain_DWork.BuoyBlobAnalysis_PAD_DW[loop] = 0U;
      }

      currentLabel = 1U;
      loop = 0;
      idx = 123;
      for (n = 0; n < 160; n++) {
        for (n_0 = 0; n_0 < 120; n_0++) {
          brain_DWork.BuoyBlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.BW_k[loop]
            ? 255 : 0);
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
                walkerIdx = numBlobs + (uint32_T)brain_ConstP.pooled20[i];
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

      /* Embedded MATLAB: '<S22>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function': '<S73>:1' */
      /*  This function will choose and return data about the largest blob given a  */
      /*  set of blobs */
      if ((rtb_BuoyBlobAnalysis_o2[0] == -1.0) && (rtb_BuoyBlobAnalysis_o2[1] ==
           -1.0)) {
        /* '<S73>:1:5' */
        /* '<S73>:1:7' */
        eml_BlobCentroidX = 80.0;

        /* '<S73>:1:8' */
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

        /* '<S73>:1:12' */
        eml_BlobCentroidX = rtb_BuoyBlobAnalysis_o2[((n - 1) << 1) + 1];

        /* '<S73>:1:13' */
        eml_BlobCentroidY = rtb_BuoyBlobAnalysis_o2[(n - 1) << 1];
      }

      /* Embedded MATLAB: '<S22>/Embedded MATLAB Function1' */
      brain_EmbeddedMATLABFunction1(&brain_B.sf_EmbeddedMATLABFunction1);

      /* Sum: '<S22>/Subtract' */
      brain_B.Subtract = eml_BlobCentroidX -
        brain_B.sf_EmbeddedMATLABFunction1.XCenter;

      /* Sum: '<S22>/Subtract1' */
      brain_B.Subtract1 = eml_BlobCentroidY -
        brain_B.sf_EmbeddedMATLABFunction1.YCenter;

      /* Sum: '<S75>/Subtract' */
      rtb_Sum = eml_BlobCentroidX - brain_B.sf_EmbeddedMATLABFunction1.XCenter;

      /* SampleTimeMath: '<S78>/TSamp' incorporates:
       *  Gain: '<S77>/X-Buoy Derivative Gain'
       *
       * About '<S78>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      rtb_TSamp = brain_P.Cam_Down_XPos_Kd * rtb_Sum / ((real_T)
        brain_DWork.StateFlowFunctionsFollowOnePa_m * 0.2);

      /* DataTypeConversion: '<S75>/Data Type Conversion' incorporates:
       *  DiscreteIntegrator: '<S77>/X-Buoy Discrete-Time Integrator'
       *  Gain: '<S77>/X-Buoy Proportional Gain'
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
      tmp_1 = (brain_P.Cam_Down_XPos_Kp * rtb_Sum + (rtb_TSamp -
                brain_DWork.UD_DSTATE)) +
        brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
      tmp_1 = floor(tmp_1);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DataTypeConversion = (int8_T)tmp_1;
        } else {
          brain_B.DataTypeConversion = MIN_int8_T;
        }
      } else if (tmp_1 >= 128.0) {
        brain_B.DataTypeConversion = MAX_int8_T;
      } else {
        brain_B.DataTypeConversion = 0;
      }

      /* Sum: '<S76>/Subtract' */
      eml_BlobCentroidX = brain_B.sf_EmbeddedMATLABFunction1.YCenter -
        eml_BlobCentroidY;

      /* SampleTimeMath: '<S80>/TSamp' incorporates:
       *  Gain: '<S79>/Y-Buoy Derivative Gain'
       *
       * About '<S80>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      eml_BlobCentroidY = brain_P.Cam_Down_YPos_Kd * eml_BlobCentroidX /
        ((real_T)brain_DWork.StateFlowFunctionsFollowOnePa_m * 0.2);

      /* DataTypeConversion: '<S76>/Data Type Conversion' incorporates:
       *  DiscreteIntegrator: '<S79>/Y-Buoy Discrete-Time Integrator'
       *  Gain: '<S79>/Y-Buoy Proportional Gain'
       *  Sum: '<S79>/Sum'
       *  Sum: '<S80>/Diff'
       *  UnitDelay: '<S80>/UD'
       *
       * Block description for '<S80>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S80>/UD':
       *
       *  Store in Global RAM
       */
      tmp_1 = (brain_P.Cam_Down_YPos_Kp * eml_BlobCentroidX + (eml_BlobCentroidY
                - brain_DWork.UD_DSTATE_k)) +
        brain_DWork.YBuoyDiscreteTimeIntegrator_DST;
      tmp_1 = floor(tmp_1);
      if (tmp_1 < 128.0) {
        if (tmp_1 >= -128.0) {
          brain_B.DataTypeConversion_h = (int8_T)tmp_1;
        } else {
          brain_B.DataTypeConversion_h = MIN_int8_T;
        }
      } else if (tmp_1 >= 128.0) {
        brain_B.DataTypeConversion_h = MAX_int8_T;
      } else {
        brain_B.DataTypeConversion_h = 0;
      }

      /* Update for UnitDelay: '<S78>/UD'
       * Block description for '<S78>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE = rtb_TSamp;

      /* Update for DiscreteIntegrator: '<S77>/X-Buoy Discrete-Time Integrator' incorporates:
       *  Gain: '<S77>/X-Buoy Integral Gain'
       */
      brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 0.2 * (real_T)
        brain_DWork.StateFlowFunctionsFollowOnePa_m * (brain_P.Cam_Down_XPos_Ki *
        rtb_Sum) + brain_DWork.XBuoyDiscreteTimeIntegrator_DST;
      if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST >= 15.0) {
        brain_DWork.XBuoyDiscreteTimeIntegrator_DST = 15.0;
      } else {
        if (brain_DWork.XBuoyDiscreteTimeIntegrator_DST <= -15.0) {
          brain_DWork.XBuoyDiscreteTimeIntegrator_DST = -15.0;
        }
      }

      /* Update for UnitDelay: '<S80>/UD'
       * Block description for '<S80>/UD':
       *
       *  Store in Global RAM
       */
      brain_DWork.UD_DSTATE_k = eml_BlobCentroidY;

      /* Update for DiscreteIntegrator: '<S79>/Y-Buoy Discrete-Time Integrator' incorporates:
       *  Gain: '<S79>/Y-Buoy Integral Gain'
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
      eml_BlobCentroidX = brain_B.Subtract1;
      eml_BlobCentroidY = brain_B.Subtract;
      for (i = 0; i < 19200; i++) {
        brain_B.BWout[i] = (real_T)brain_B.BW_k[i];
      }

      /* Simulink Function 'MaintainDepth': '<S7>:926' */
      brain_B.CurrentDepth1_g = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1_e = (real32_T)brain_B.DesiredDepth;
      StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1_e,
        brain_B.CurrentDepth1_g, brain_M,
        &brain_B.StateFlowFunctionsMaintainDepth,
        &brain_DWork.StateFlowFunctionsMaintainDepth);
      brain_B.Vertical = brain_B.StateFlowFunctionsMaintainDepth.DoubleToInt8;

      /* Simulink Function 'MaintainHeading': '<S7>:918' */
      brain_B.DesiredHeading1_j = brain_B.DesiredHeading;
      brain_B.CurrentHeading1_n = brain_U.CurrentHeading;
      brain_B.ForwardVelocity1_o = (real_T)loop;
      StateFlowFunctionsBuoysMainta_h(brain_B.DesiredHeading1_j,
        brain_B.CurrentHeading1_n, brain_B.ForwardVelocity1_o, brain_M,
        &brain_B.StateFlowFunctionsMaintainHeadi,
        &brain_DWork.StateFlowFunctionsMaintainHeadi);
      brain_B.Left = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint8;
      brain_B.Right = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint1;

      /* Embedded MATLAB Function 'CalcError': '<S7>:1173' */
      /*  This function calculates the error between the center of the screen and  */
      /*  the centroid of the orange/red blob */
      /* '<S7>:1173:5' */
      brain_DWork.Error = fabs(eml_BlobCentroidX - eml_BlobCentroidY);
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
      brain_DWork.HeadingAlongPath = eml_BlobCentroidY;

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

      /* Simulink Function 'HSVSegmentation_VerticalSplit': '<S7>:1186' */
      memcpy((void *)&brain_B.HSV1[0], (void *)
             &brain_B.StateFlowFunctionsFollowOnePa_g.HSVImage1[0], 57600U *
             sizeof(real_T));
      brain_B.DesiredH1 = 0.05;

      /* Embedded MATLAB: '<S86>/HSV Threshold Segmentation' */
      brain_c9_brain();
      for (i = 0; i < 9600; i++) {
        /* DataTypeConversion: '<S86>/Data Type Conversion' */
        brain_B.BWleft_d[i] = (brain_B.BWleft[i] != 0.0);

        /* DataTypeConversion: '<S86>/Data Type Conversion1' */
        brain_B.BWright_c[i] = (brain_B.BWright[i] != 0.0);
        loop = brain_B.BWleft_d[i];
        idx = brain_B.BWright_c[i];
        brain_B.BWleft1[i] = (loop != 0);
        brain_B.BWright1[i] = (idx != 0);
        brain_B.sf_BWright[i] = (real_T)idx;
        brain_B.sf_BWleft[i] = (real_T)loop;
      }

      brain_CombineBWs(&brain_B.sf_BWleft[0], &brain_B.sf_BWright[0],
                       &brain_B.BWout[0]);

      /* Simulink Function 'GetHeadings': '<S7>:1208' */
      brain_B.CurrentHeading1_ny = brain_U.CurrentHeading;
      StateFlowFunctionsFollowOnePa_h(brain_B.BWleft1, brain_B.BWright1,
        brain_B.CurrentHeading1_ny, &brain_B.StateFlowFunctionsFollowOneP_ht);
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
      brain_B.CurrentDepth1_g = (real32_T)brain_U.CurrentDepth;
      brain_B.DesiredDepth1_e = (real32_T)brain_B.DesiredDepth;
      StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1_e,
        brain_B.CurrentDepth1_g, brain_M,
        &brain_B.StateFlowFunctionsMaintainDepth,
        &brain_DWork.StateFlowFunctionsMaintainDepth);
      brain_B.Vertical = brain_B.StateFlowFunctionsMaintainDepth.DoubleToInt8;
    }
    break;

   default:
    brain_enter_internal_OnePath();
    break;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_FollowOnePath(void)
{
  real_T sf_Desired_HeadingAlong;
  real_T sf_Desired_HeadingTo;
  int32_T i;

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
        brain_DWork.HeadingAlongPath = sf_Desired_HeadingAlong;
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

      /* Constant: '<S25>/Constant' */
      brain_B.Constant_f = brain_P.Track_Desired_Depth;
      brain_B.DesiredDepth = brain_B.Constant_f;
      brain_B.DesiredHeading = brain_U.CurrentHeading;
      brain_DWork.Done = 0.0;
      brain_B.State = 3;
      brain_B.CameraPosition = 2;

      /* Simulink Function 'MakeHSVImage': '<S7>:1215' */
      for (i = 0; i < 19200; i++) {
        brain_B.H1[i] = brain_B.Resize[i];
        brain_B.S1[i] = brain_B.Resize1[i];
        brain_B.V1[i] = brain_B.Resize2[i];
      }

      StateFlowFunctionsFollowOnePath(brain_B.H1, brain_B.S1, brain_B.V1,
        &brain_B.StateFlowFunctionsFollowOnePa_g);
      break;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_GetInCorrectState(void)
{
  int32_T i;

  /* During 'GetInCorrectState': '<S7>:1263' */
  if (brain_DWork.OperationalState == 0) {
    /* Transition: '<S7>:1266' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'NotRunning': '<S7>:727' */
    brain_DWork.is_StateFlowFunctions = brain_IN_NotRunning;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
    brain_B.Strafe = 0;
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

    /* Constant: '<S25>/Constant' */
    brain_B.Constant_f = brain_P.Track_Desired_Depth;
    brain_B.DesiredDepth = brain_B.Constant_f;
    brain_B.DesiredHeading = brain_U.CurrentHeading;
    brain_DWork.Done = 0.0;
    brain_B.State = 3;
    brain_B.CameraPosition = 2;

    /* Simulink Function 'MakeHSVImage': '<S7>:1215' */
    for (i = 0; i < 19200; i++) {
      brain_B.H1[i] = brain_B.Resize[i];
      brain_B.S1[i] = brain_B.Resize1[i];
      brain_B.V1[i] = brain_B.Resize2[i];
    }

    StateFlowFunctionsFollowOnePath(brain_B.H1, brain_B.S1, brain_B.V1,
      &brain_B.StateFlowFunctionsFollowOnePa_g);
  } else if (brain_DWork.OperationalState == 7) {
    /* Transition: '<S7>:1281' */
    /* Exit 'GetInCorrectState': '<S7>:1263' */
    /* Entry 'Finish': '<S7>:1259' */
    brain_DWork.is_StateFlowFunctions = brain_IN_Finish;
    brain_B.State = 6;
    brain_B.Left = 0;
    brain_B.Right = 0;
    brain_B.Vertical = 0;
    brain_B.Strafe = 0;
  } else {
    if (brain_DWork.OperationalState == 6) {
      /* Transition: '<S7>:1280' */
      /* Exit 'GetInCorrectState': '<S7>:1263' */
      /* Entry 'Buoys': '<S7>:1290' */
      brain_DWork.is_StateFlowFunctions = brain_IN_Buoys;

      /* Transition: '<S7>:1291' */
      /* Entry 'FindBuoys': '<S7>:1295' */
      brain_DWork.is_Buoys = brain_IN_FindBuoys;
      brain_DWork.OldObstacle = FALSE;
      brain_B.CameraPosition = 0;
      brain_B.State = 4;
      brain_DWork.BuoyCount = 0.0;
      brain_B.DesiredDepth = 5.0;
    }
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_Start(void)
{
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
      brain_DWork.DesiredHeadingCount = brain_DWork.DesiredHeadingCount + 1.0;
    } else {
      /* '<S7>:1146:8' */
      brain_DWork.DesiredHeadingCount = 0.0;
    }

    /* '<S7>:1146:10' */
    brain_DWork.OldHeading = brain_U.CurrentHeading;

    /* Simulink Function 'GetDesiredDepth': '<S7>:1286' */

    /* Constant: '<S25>/Constant' */
    brain_B.Constant_f = brain_P.Track_Desired_Depth;
    brain_B.DesiredDepth = brain_B.Constant_f;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static real_T brain_countimages(real_T sf_Image, real_T sf_OldImage, real_T
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

  /* During 'ValidationGate': '<S7>:1151' */
  if (brain_DWork.OperationalState != 4) {
    /* Transition: '<S7>:1275' */
    /* Exit 'ValidationGate': '<S7>:1151' */
    /* Entry 'GetInCorrectState': '<S7>:1263' */
    brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
  } else {
    /* Simulink Function 'LookforTrack': '<S7>:1154' */
    for (i = 0; i < 19200; i++) {
      brain_B.H_a[i] = brain_B.Resize[i];
      brain_B.S_i[i] = brain_B.Resize1[i];

      /* Logic: '<S94>/Logical Operator1' incorporates:
       *  Constant: '<S96>/Constant'
       *  Constant: '<S97>/Constant'
       *  Constant: '<S98>/Constant'
       *  Logic: '<S94>/Logical Operator'
       *  RelationalOperator: '<S96>/Compare'
       *  RelationalOperator: '<S97>/Compare'
       *  RelationalOperator: '<S98>/Compare'
       */
      brain_B.BW[i] = (((brain_B.H_a[i] < brain_P.Track_HueLower) ||
                        (brain_B.H_a[i] > brain_P.Track_HueHigher)) &&
                       (brain_B.S_i[i] > brain_P.Track_Saturation));
    }

    /* S-Function (svipblob): '<S94>/Blob Analysis' */
    maxNumBlobsReached = FALSE;
    for (i = 0; i < 123; i++) {
      brain_DWork.BlobAnalysis_PAD_DW[i] = 0U;
    }

    currentLabel = 1U;
    i = 0;
    idx = 123;
    for (n = 0; n < 160; n++) {
      for (n_0 = 0; n_0 < 120; n_0++) {
        brain_DWork.BlobAnalysis_PAD_DW[idx] = (uint8_T)(brain_B.BW[i] ? 255 : 0);
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
          BlobAnalysis_NUM_PIX_DW = 1U;
          brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = numBlobs;
          stackIdx++;
          while (stackIdx) {
            stackIdx--;
            numBlobs = brain_DWork.BlobAnalysis_STACK_DW[stackIdx];
            for (i = 0; i < 8; i++) {
              k = numBlobs + (uint32_T)brain_ConstP.pooled20[i];
              if (brain_DWork.BlobAnalysis_PAD_DW[k] == 255) {
                brain_DWork.BlobAnalysis_PAD_DW[k] = currentLabel;
                brain_DWork.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                  ((int16_T)(k / 122U) - 1);
                brain_DWork.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)(k %
                  122U - 1U);
                pixIdx++;
                BlobAnalysis_NUM_PIX_DW++;
                brain_DWork.BlobAnalysis_STACK_DW[stackIdx] = k;
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
        idx += brain_DWork.BlobAnalysis_N_PIXLIST_DW[j + n];
        ms += brain_DWork.BlobAnalysis_M_PIXLIST_DW[j + i];
      }

      centroid_idx = (real32_T)ms / (real32_T)BlobAnalysis_NUM_PIX_DW;
      centroid_idx_0 = (real32_T)idx / (real32_T)BlobAnalysis_NUM_PIX_DW;
      rtb_BlobAnalysis = 0.0F;
      ys = 0.0F;
      xys = 0.0F;
      for (k = 0U; k < (uint32_T)(int32_T)BlobAnalysis_NUM_PIX_DW; k++) {
        majorAxis = (real32_T)brain_DWork.BlobAnalysis_N_PIXLIST_DW[n + k] -
          centroid_idx_0;
        uyy = (real32_T)brain_DWork.BlobAnalysis_M_PIXLIST_DW[i + k] -
          centroid_idx;
        rtb_BlobAnalysis += majorAxis * majorAxis;
        ys += uyy * uyy;
        xys += majorAxis * (-uyy);
      }

      centroid_idx = rtb_BlobAnalysis / (real32_T)BlobAnalysis_NUM_PIX_DW +
        8.333333582E-02F;
      uyy = ys / (real32_T)BlobAnalysis_NUM_PIX_DW + 8.333333582E-02F;
      rtb_BlobAnalysis = xys / (real32_T)BlobAnalysis_NUM_PIX_DW;
      rtb_BlobAnalysis = (real32_T)sqrt((centroid_idx - uyy) * (centroid_idx -
        uyy) + rtb_BlobAnalysis * rtb_BlobAnalysis * 4.0F);
      majorAxis = ((centroid_idx + uyy) + rtb_BlobAnalysis) * 8.0F;
      rtb_BlobAnalysis = (real32_T)sqrt(majorAxis - ((centroid_idx + uyy) -
        rtb_BlobAnalysis) * 8.0F) / (real32_T)sqrt(majorAxis);
      i += (int32_T)BlobAnalysis_NUM_PIX_DW;
      n += (int32_T)BlobAnalysis_NUM_PIX_DW;
    }

    for (i = (int32_T)numBlobs; i < 1; i = 1) {
      rtb_BlobAnalysis = -1.0F;
    }

    /* Embedded MATLAB: '<S94>/CheckConditions' incorporates:
     *  Constant: '<S94>/Constant'
     */
    /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions': '<S95>:1' */
    /*  This function checks the conditions to decide if a track is present */
    if ((real_T)rtb_BlobAnalysis > brain_P.Track_Min_Eccentricity) {
      /* '<S95>:1:4' */
      /* '<S95>:1:5' */
      brain_B.Image_m = 1.0;
    } else {
      /* '<S95>:1:7' */
      brain_B.Image_m = 0.0;
    }

    maxNumBlobsReached = (brain_B.Image_m != 0.0);
    for (i = 0; i < 19200; i++) {
      brain_B.BWout[i] = (real_T)brain_B.BW[i];
    }

    brain_DWork.TrackCount = brain_countimages((real_T)maxNumBlobsReached,
      (real_T)brain_DWork.OldObstacle, brain_DWork.count);

    /* Simulink Function 'GetValidationGateForwardVelocity': '<S7>:1152' */

    /* Constant: '<S28>/Heading Forward Velocity' */
    brain_B.HeadingForwardVelocity = brain_P.Heading_Forward_Velocity;

    /* Simulink Function 'MaintainHeading': '<S7>:918' */
    brain_B.DesiredHeading1_j = brain_B.DesiredHeading;
    brain_B.CurrentHeading1_n = brain_U.CurrentHeading;
    brain_B.ForwardVelocity1_o = brain_B.HeadingForwardVelocity;
    StateFlowFunctionsBuoysMainta_h(brain_B.DesiredHeading1_j,
      brain_B.CurrentHeading1_n, brain_B.ForwardVelocity1_o, brain_M,
      &brain_B.StateFlowFunctionsMaintainHeadi,
      &brain_DWork.StateFlowFunctionsMaintainHeadi);
    brain_B.Left = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint8;
    brain_B.Right = brain_B.StateFlowFunctionsMaintainHeadi.DoubleToint1;

    /* Simulink Function 'MaintainDepth': '<S7>:926' */
    brain_B.CurrentDepth1_g = (real32_T)brain_U.CurrentDepth;
    brain_B.DesiredDepth1_e = (real32_T)brain_B.DesiredDepth;
    StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1_e,
      brain_B.CurrentDepth1_g, brain_M, &brain_B.StateFlowFunctionsMaintainDepth,
      &brain_DWork.StateFlowFunctionsMaintainDepth);
    brain_B.Vertical = brain_B.StateFlowFunctionsMaintainDepth.DoubleToInt8;
    brain_DWork.OldObstacle = maxNumBlobsReached;
    brain_DWork.count = brain_DWork.TrackCount;
  }
}

/* Function for Stateflow: '<Root>/StateFlow Functions' */
static void brain_StateFlowFunctions(void)
{
  boolean_T sf_Obstacle;
  real_T eml_count;
  uint8_T eml_i;
  real_T eml_colors[9];
  real_T eml_centX[3];
  real_T eml_right_ref;
  real_T rtb_Centroid_Out[100];
  int32_T i;
  int32_T eml_mid_ref;
  int32_T eml_left_ref;
  real_T eml_centY;
  real_T eml_centX_0;

  /* During 'StateFlowFunctions': '<S7>:726' */
  switch (brain_DWork.is_StateFlowFunctions) {
   case brain_IN_Buoys:
    /* During 'Buoys': '<S7>:1290' */
    if (brain_DWork.OperationalState != 6) {
      /* Transition: '<S7>:1279' */
      brain_exit_internal_Buoys();

      /* Exit 'Buoys': '<S7>:1290' */
      StateFlowFunctionsBuoys_Disable(&brain_B.StateFlowFunctionsBuoysMaint_hr,
        &brain_DWork.StateFlowFunctionsBuoysMaint_hr);

      /* Entry 'GetInCorrectState': '<S7>:1263' */
      brain_DWork.is_StateFlowFunctions = brain_IN_GetInCorrectState;
    } else {
      switch (brain_DWork.is_Buoys) {
       case brain_IN_ApproachBuoys:
        brain_ApproachBuoys();
        break;

       case brain_IN_FindBuoys:
        /* During 'FindBuoys': '<S7>:1295' */
        if (brain_DWork.BuoyCount > 2.0) {
          /* Transition: '<S7>:1292' */
          /* Exit 'FindBuoys': '<S7>:1295' */
          /* Simulink Function 'GetBuoyColors': '<S7>:1305' */
          memcpy((void *)&brain_B.LabelMatrix[0], (void *)
                 &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
          memcpy((void *)&brain_B.ref_colors[0], (void *)
                 &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
          brain_B.num_colors_e = brain_DWork.num_colors;

          /* Embedded MATLAB: '<S14>/Blob Extraction' */
          brain_c5_brain();

          /* Embedded MATLAB: '<S14>/IF Buoy Conditions' incorporates:
           *  Constant: '<S14>/Constant'
           *  Constant: '<S14>/Constant1'
           *  Constant: '<S14>/Constant2'
           *  Constant: '<S14>/Constant3'
           */
          /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions': '<S49>:1' */
          /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
          /*  the cenroids of the most circular objects in the image */
          /* '<S49>:1:5' */
          eml_count = 0.0;

          /* '<S49>:1:6' */
          memset((void *)&rtb_Centroid_Out[0], (int32_T)0.0, 100U * sizeof
                 (real_T));

          /* '<S49>:1:9' */
          for (eml_i = 1U; eml_i <= brain_B.TotalNum; eml_i = (uint8_T)(uint32_T)
               (eml_i + 1)) {
            /* '<S49>:1:9' */
            if ((brain_B.Eccent[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
                (brain_B.Eccent[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
                (brain_B.Extent[eml_i - 1] > brain_P.Buoy_Min_Extent) &&
                (brain_B.Extent[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
              /* '<S49>:1:10' */
              /* '<S49>:1:11' */
              eml_count++;

              /* '<S49>:1:12' */
              rtb_Centroid_Out[(int32_T)eml_count - 1] = brain_B.Centroid[eml_i
                - 1];

              /* '<S49>:1:13' */
              rtb_Centroid_Out[(int32_T)eml_count + 49] = brain_B.Centroid[eml_i
                + 49];
            }
          }

          /* Embedded MATLAB: '<S14>/Say Which Buoy Is Which' */
          /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which': '<S50>:1' */
          /*  This function determines which buoy is in which location, left, middle, */
          /*  or right. */
          /* '<S50>:1:5' */
          memset((void *)&eml_colors[0], (int32_T)0.0, 9U * sizeof(real_T));

          /* '<S50>:1:6' */
          /* '<S50>:1:7' */
          eml_centX[0] = 0.0;
          eml_centX[1] = 0.0;
          eml_centX[2] = 0.0;

          /* '<S50>:1:10' */
          /* '<S50>:1:11' */
          eml_centX_0 = floor(rtb_Centroid_Out[50]);

          /* '<S50>:1:12' */
          eml_centY = floor(rtb_Centroid_Out[0]);
          if (eml_centX_0 < 1.0) {
            /* '<S50>:1:13' */
            /* '<S50>:1:14' */
            eml_centX_0 = 1.0;
          }

          if (eml_centY < 1.0) {
            /* '<S50>:1:16' */
            /* '<S50>:1:17' */
            eml_centY = 1.0;
          }

          /* '<S50>:1:20' */
          eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 +
            ((int32_T)eml_centY - 1)];

          /* '<S50>:1:22' */
          eml_colors[0] = brain_B.ref_colors[(int32_T)eml_count - 1];
          eml_colors[3] = brain_B.ref_colors[(int32_T)eml_count + 49];
          eml_colors[6] = brain_B.ref_colors[(int32_T)eml_count + 99];
          eml_centX[0] = eml_centX_0;

          /* '<S50>:1:10' */
          /* '<S50>:1:11' */
          eml_centX_0 = floor(rtb_Centroid_Out[51]);

          /* '<S50>:1:12' */
          eml_centY = floor(rtb_Centroid_Out[1]);
          if (eml_centX_0 < 1.0) {
            /* '<S50>:1:13' */
            /* '<S50>:1:14' */
            eml_centX_0 = 1.0;
          }

          if (eml_centY < 1.0) {
            /* '<S50>:1:16' */
            /* '<S50>:1:17' */
            eml_centY = 1.0;
          }

          /* '<S50>:1:20' */
          eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 +
            ((int32_T)eml_centY - 1)];

          /* '<S50>:1:22' */
          eml_colors[1] = brain_B.ref_colors[(int32_T)eml_count - 1];
          eml_colors[4] = brain_B.ref_colors[(int32_T)eml_count + 49];
          eml_colors[7] = brain_B.ref_colors[(int32_T)eml_count + 99];
          eml_centX[1] = eml_centX_0;

          /* '<S50>:1:10' */
          /* '<S50>:1:11' */
          eml_centX_0 = floor(rtb_Centroid_Out[52]);

          /* '<S50>:1:12' */
          eml_centY = floor(rtb_Centroid_Out[2]);
          if (eml_centX_0 < 1.0) {
            /* '<S50>:1:13' */
            /* '<S50>:1:14' */
            eml_centX_0 = 1.0;
          }

          if (eml_centY < 1.0) {
            /* '<S50>:1:16' */
            /* '<S50>:1:17' */
            eml_centY = 1.0;
          }

          /* '<S50>:1:20' */
          eml_count = brain_B.LabelMatrix[((int32_T)eml_centX_0 - 1) * 120 +
            ((int32_T)eml_centY - 1)];

          /* '<S50>:1:22' */
          eml_colors[2] = brain_B.ref_colors[(int32_T)eml_count - 1];
          eml_colors[5] = brain_B.ref_colors[(int32_T)eml_count + 49];
          eml_colors[8] = brain_B.ref_colors[(int32_T)eml_count + 99];
          eml_centX[2] = eml_centX_0;
          brain_min(eml_centX, &eml_count, &eml_centY);

          /* '<S50>:1:26' */
          eml_centX[(int32_T)eml_centY - 1] = 1000.0;
          brain_min(eml_centX, &eml_count, &eml_centX_0);

          /* '<S50>:1:28' */
          eml_centX[(int32_T)eml_centX_0 - 1] = 1000.0;
          brain_min(eml_centX, &eml_count, &eml_right_ref);

          /* '<S50>:1:31' */
          i = (int32_T)eml_right_ref - 1;

          /* '<S50>:1:32' */
          eml_mid_ref = (int32_T)eml_centX_0 - 1;

          /* '<S50>:1:33' */
          eml_left_ref = (int32_T)eml_centY - 1;

          /* Entry 'ApproachBuoys': '<S7>:1312' */
          brain_DWork.is_Buoys = brain_IN_ApproachBuoys;

          /* Transition: '<S7>:1313' */
          /* Entry 'ApproachFirstBuoy': '<S7>:1341' */
          brain_DWork.is_ApproachBuoys = brain_IN_ApproachFirstBuoy;
          brain_DWork.countarea = 0.0;

          /* Simulink Function 'GetFirstBuoyStats': '<S7>:1342' */

          /* Constant: '<S8>/Constant' */
          brain_B.Constant_k = brain_P.Buoy1_Hue;

          /* Constant: '<S8>/Constant2' */
          brain_B.Constant2_i = brain_P.Buoy1_Saturation;

          /* Constant: '<S8>/Constant1' */
          brain_B.Constant1_o = brain_P.Buoy1_Value;
          brain_DWork.BuoyHue = brain_B.Constant_k;
          brain_DWork.BuoySaturation = brain_B.Constant2_i;
          brain_DWork.BuoyValue = brain_B.Constant1_o;

          /* Simulink Function 'WhichBuoysToApproach': '<S7>:1346' */
          brain_B.right[0] = eml_colors[i];
          brain_B.mid[0] = eml_colors[eml_mid_ref];
          brain_B.left[0] = eml_colors[eml_left_ref];
          brain_DWork.LeftBuoy[0] = brain_B.left[0];
          brain_DWork.MiddleBuoy[0] = brain_B.mid[0];
          brain_DWork.RightBuoy[0] = brain_B.right[0];
          brain_B.L_B[0] = brain_DWork.LeftBuoy[0];
          brain_B.M_B[0] = brain_DWork.MiddleBuoy[0];
          brain_B.R_B[0] = brain_DWork.RightBuoy[0];
          brain_B.right[1] = eml_colors[i + 3];
          brain_B.mid[1] = eml_colors[eml_mid_ref + 3];
          brain_B.left[1] = eml_colors[eml_left_ref + 3];
          brain_DWork.LeftBuoy[1] = brain_B.left[1];
          brain_DWork.MiddleBuoy[1] = brain_B.mid[1];
          brain_DWork.RightBuoy[1] = brain_B.right[1];
          brain_B.L_B[1] = brain_DWork.LeftBuoy[1];
          brain_B.M_B[1] = brain_DWork.MiddleBuoy[1];
          brain_B.R_B[1] = brain_DWork.RightBuoy[1];
          brain_B.right[2] = eml_colors[i + 6];
          brain_B.mid[2] = eml_colors[eml_mid_ref + 6];
          brain_B.left[2] = eml_colors[eml_left_ref + 6];
          brain_DWork.LeftBuoy[2] = brain_B.left[2];
          brain_DWork.MiddleBuoy[2] = brain_B.mid[2];
          brain_DWork.RightBuoy[2] = brain_B.right[2];
          brain_B.L_B[2] = brain_DWork.LeftBuoy[2];
          brain_B.M_B[2] = brain_DWork.MiddleBuoy[2];
          brain_B.R_B[2] = brain_DWork.RightBuoy[2];
          StateFlowFunctionsBuoysApproach(brain_B.L_B, brain_B.M_B, brain_B.R_B,
            &brain_B.StateFlowFunctionsBuoysApproa_f);
          brain_DWork.FirstDir = brain_B.StateFlowFunctionsBuoysApproa_f.FirstD;
          brain_DWork.SecondDir =
            brain_B.StateFlowFunctionsBuoysApproa_f.SecondD;
        } else {
          /* Simulink Function 'IterativeSegmentation': '<S7>:1374' */
          for (i = 0; i < 19200; i++) {
            brain_B.H[i] = brain_B.Resize[i];
            brain_B.S[i] = brain_B.Resize1[i];
            brain_B.V[i] = brain_B.Resize2[i];
          }

          StateFlowFunctionsBuoysIterativ(brain_B.H, brain_B.S, brain_B.V,
            &brain_B.StateFlowFunctionsBuoysIterat_g,
            &brain_DWork.StateFlowFunctionsBuoysIterat_g);
          memcpy((void *)&brain_DWork.LabelMatrix[0], (void *)
                 &brain_B.StateFlowFunctionsBuoysIterat_g.LabelMatrix[0], 19200U
                 * sizeof(real_T));
          brain_DWork.num_colors =
            brain_B.StateFlowFunctionsBuoysIterat_g.num_colors;
          memcpy((void *)&brain_DWork.ref_colors[0], (void *)
                 &brain_B.StateFlowFunctionsBuoysIterat_g.ref_colors[0], 150U *
                 sizeof(real_T));

          /* Simulink Function 'LookforBuoys': '<S7>:1296' */
          memcpy((void *)&brain_B.LabMatrix_b[0], (void *)
                 &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
          brain_B.num_colors = brain_DWork.num_colors;

          /* Embedded MATLAB: '<S15>/Blob Extraction' */
          brain_c3_brain();

          /* Embedded MATLAB: '<S15>/IF Buoy Conditions' incorporates:
           *  Constant: '<S15>/Constant'
           *  Constant: '<S15>/Constant1'
           *  Constant: '<S15>/Constant2'
           *  Constant: '<S15>/Constant3'
           */
          /* Embedded MATLAB Function 'StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/IF Buoy Conditions': '<S52>:1' */
          /*  This function will take in 2 1x10 vectors, eccent and extent to determine */
          /*  if there is a buoy present in the current image */
          /* '<S52>:1:5' */
          brain_B.Image = 0.0;

          /* '<S52>:1:6' */
          eml_count = 0.0;

          /* '<S52>:1:8' */
          for (eml_i = 1U; eml_i <= brain_B.TotalNum_f; eml_i = (uint8_T)
               (uint32_T)(eml_i + 1)) {
            /* '<S52>:1:8' */
            if ((brain_B.Eccent_j[eml_i - 1] > brain_P.Buoy_Min_Eccentricity) &&
                (brain_B.Eccent_j[eml_i - 1] < brain_P.Buoy_Max_Eccentricity) &&
                (brain_B.Extent_f[eml_i - 1] > brain_P.Buoy_Min_Extent) &&
                (brain_B.Extent_f[eml_i - 1] < brain_P.Buoy_Max_Extent)) {
              /* '<S52>:1:9' */
              /* '<S52>:1:10' */
              eml_count++;
            }
          }

          if (eml_count >= 3.0) {
            /* '<S52>:1:14' */
            /* '<S52>:1:15' */
            brain_B.Image = 1.0;
          }

          sf_Obstacle = (brain_B.Image != 0.0);
          brain_DWork.BuoyCount = brain_countimages_m((real_T)sf_Obstacle,
            (real_T)brain_DWork.OldObstacle, brain_DWork.BuoyCount);

          /* Simulink Function 'GetBuoyForwardVelocity': '<S7>:1293' */

          /* Constant: '<S16>/Constant' */
          brain_B.Constant_l = brain_P.Heading_Forward_Velocity;

          /* Simulink Function 'MaintainHeading': '<S7>:1385' */
          brain_B.DesiredHeading1 = brain_B.DesiredHeading;
          brain_B.CurrentHeading1 = brain_U.CurrentHeading;
          brain_B.ForwardVelocity1 = brain_B.Constant_l;
          StateFlowFunctionsBuoysMainta_h(brain_B.DesiredHeading1,
            brain_B.CurrentHeading1, brain_B.ForwardVelocity1, brain_M,
            &brain_B.StateFlowFunctionsBuoysMaint_hr,
            &brain_DWork.StateFlowFunctionsBuoysMaint_hr);
          brain_B.Left = brain_B.StateFlowFunctionsBuoysMaint_hr.DoubleToint8;
          brain_B.Right = brain_B.StateFlowFunctionsBuoysMaint_hr.DoubleToint1;

          /* Simulink Function 'MaintainDepth': '<S7>:1381' */
          brain_B.CurrentDepth1 = (real32_T)brain_U.CurrentDepth;
          brain_B.DesiredDepth1 = (real32_T)brain_B.DesiredDepth;
          StateFlowFunctionsBuoysMaintain(brain_B.DesiredDepth1,
            brain_B.CurrentDepth1, brain_M,
            &brain_B.StateFlowFunctionsBuoysMainta_c,
            &brain_DWork.StateFlowFunctionsBuoysMainta_c);
          brain_B.Vertical =
            brain_B.StateFlowFunctionsBuoysMainta_c.DoubleToInt8;
          brain_DWork.OldObstacle = sf_Obstacle;

          /* Simulink Function 'ShowSegmentedImage': '<S7>:1370' */
          memcpy((void *)&brain_B.LabMatrix_d[0], (void *)
                 &brain_DWork.LabelMatrix[0], 19200U * sizeof(real_T));
          memcpy((void *)&brain_B.Ref_Colors_b[0], (void *)
                 &brain_DWork.ref_colors[0], 150U * sizeof(real_T));
          StateFlowFunctionsBuoysShowSegm(brain_B.LabMatrix_d,
            brain_B.Ref_Colors_b, &brain_B.StateFlowFunctionsBuoysShowSe_o);
          memcpy((void *)&brain_B.RGBout[0], (void *)
                 &brain_B.StateFlowFunctionsBuoysShowSe_o.RGB[0], 57600U *
                 sizeof(real_T));
        }
        break;

       default:
        brain_enter_internal_Buoys();
        break;
      }
    }
    break;

   case brain_IN_ControlledRC:
    brain_ControlledRC();
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
    brain_FollowOnePath();
    break;

   case brain_IN_GetInCorrectState:
    brain_GetInCorrectState();
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
    brain_Start();
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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o1[brain_ConstP.pooled25[n_0]
          * 480 + n] * brain_ConstP.pooled19[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled24[n_0]] *
          brain_ConstP.pooled18[n_0];
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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o2[brain_ConstP.pooled25[n_0]
          * 480 + n] * brain_ConstP.pooled19[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled24[n_0]] *
          brain_ConstP.pooled18[n_0];
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
        sum += brain_B.RGBtoHSVColorSpaceConversion_o3[brain_ConstP.pooled25[n_0]
          * 480 + n] * brain_ConstP.pooled19[n_0];
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
        sum += Resize2_LineBuffer[brain_ConstP.pooled24[n_0]] *
          brain_ConstP.pooled18[n_0];
        n_0 += 120;
      }

      brain_B.Resize2[inStep] = sum;
      inStep++;
    }
  }

  /* Stateflow: '<Root>/StateFlow Functions' incorporates:
   *  Inport: '<Root>/DesiredState'
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
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainHeading'
   *  SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.HSVSegmentation_VerticalSplit'
   *  SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   */
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

        /* Transition: '<S7>:941' */
        /* Entry 'Autonomous': '<S7>:945' */
        brain_DWork.is_Running = brain_IN_Autonomous;

        /* Transition: '<S7>:946' */
        /* Entry 'Start': '<S7>:1019' */
        brain_DWork.is_Autonomous = brain_IN_Start_m;
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
              if ((brain_DWork.count2ndarea > 2.0) && (brain_U.DesiredState == 0))
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
   *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainDepth'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainHeading'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.HSVSegmentation_VerticalSplit'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
   *  Start for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
   */

  /* Start for Constant: '<S8>/Constant' */
  brain_B.Constant_k = brain_P.Buoy1_Hue;

  /* Start for Constant: '<S8>/Constant2' */
  brain_B.Constant2_i = brain_P.Buoy1_Saturation;

  /* Start for Constant: '<S8>/Constant1' */
  brain_B.Constant1_o = brain_P.Buoy1_Value;
  StateFlowFunctionsBuoys_b_Start(brain_M,
    &brain_DWork.StateFlowFunctionsBuoysMaint_hr);
  StateFlowFunctionsBuoys_b_Start(brain_M,
    &brain_DWork.StateFlowFunctionsMaintainHeadi);

  /* Start for Constant: '<S12>/Constant' */
  brain_B.Constant_p = brain_P.Buoy_Strafe;

  /* Start for Constant: '<S28>/Heading Forward Velocity' */
  brain_B.HeadingForwardVelocity = brain_P.Heading_Forward_Velocity;

  /* Start for Constant: '<S25>/Constant' */
  brain_B.Constant_f = brain_P.Track_Desired_Depth;

  /* Start for Constant: '<S16>/Constant' */
  brain_B.Constant_l = brain_P.Heading_Forward_Velocity;

  /* Start for Constant: '<S11>/Constant' */
  brain_B.Constant = brain_P.Buoy2_Hue;

  /* Start for Constant: '<S11>/Constant2' */
  brain_B.Constant2 = brain_P.Buoy2_Saturation;

  /* Start for Constant: '<S11>/Constant1' */
  brain_B.Constant1 = brain_P.Buoy2_Value;

  {
    int32_T i;
    static int8_T tmp[8] = { -1, 121, 122, 123, 1, -121, -122, -123 };

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
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainDepth'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.MaintainHeading'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.HSVSegmentation_VerticalSplit'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.GetDesiredDepth'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainDepth'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.MaintainHeading'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity'
     *  InitializeConditions for SubSystem: '<S7>/StateFlowFunctions.ValidationGate.LookforTrack'
     */
    brain_DWork.is_active_StateFlowFunctions = 0U;
    brain_DWork.is_StateFlowFunctions = 0U;
    brain_DWork.is_Buoys = 0U;
    brain_DWork.is_ApproachBuoys = 0U;
    brain_DWork.is_FollowOnePath = 0U;
    brain_DWork.is_OnePath = 0U;
    brain_DWork.is_active_StateManagement = 0U;
    brain_DWork.is_StateManagement = 0U;
    brain_DWork.is_Running = 0U;
    brain_DWork.is_Autonomous = 0U;
    brain_DWork.is_active_c1_brain = 0U;
    brain_DWork.count = 0.0;
    brain_DWork.OldObstacle = FALSE;
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
    brain_DWork.Error = 0.0;
    brain_DWork.OperationalState = 0;
    brain_DWork.BuoyHue = 0.0;
    brain_DWork.BuoySaturation = 0.0;
    brain_DWork.BuoyValue = 0.0;
    brain_DWork.FirstDir = 0.0;
    brain_DWork.Image = 0.0;
    memset((void *)(&brain_DWork.LabelMatrix[0]), (int32_T)0.0, 19200U * sizeof
           (real_T));
    brain_DWork.LeftBuoy[0] = 0.0;
    brain_DWork.MiddleBuoy[0] = 0.0;
    brain_DWork.RightBuoy[0] = 0.0;
    brain_DWork.LeftBuoy[1] = 0.0;
    brain_DWork.MiddleBuoy[1] = 0.0;
    brain_DWork.RightBuoy[1] = 0.0;
    brain_DWork.LeftBuoy[2] = 0.0;
    brain_DWork.MiddleBuoy[2] = 0.0;
    brain_DWork.RightBuoy[2] = 0.0;
    brain_DWork.SecondDir = 0.0;
    brain_DWork.TurnDirection = 0.0;
    brain_DWork.count2ndarea = 0.0;
    brain_DWork.num_colors = 0.0;
    memset((void *)(&brain_DWork.ref_colors[0]), (int32_T)0.0, 150U * sizeof
           (real_T));
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
    StateFlowFunctionsBuoysA_k_Init(brain_M,
      &brain_DWork.StateFlowFunctionsBuoysAppro_lp);
    StateFlowFunctionsBuoysMai_Init(brain_M,
      &brain_DWork.StateFlowFunctionsBuoysMainta_c);
    StateFlowFunctionsBuoysM_i_Init(brain_M,
      &brain_DWork.StateFlowFunctionsBuoysMaint_hr);
    StateFlowFunctionsBuoysM_i_Init(brain_M,
      &brain_DWork.StateFlowFunctionsMaintainHeadi);
    brain_DWork.StateFlowFunctionsFollowOnePa_e = brain_M->Timing.clockTick0;
    StateFlowFunctionsBuoysMai_Init(brain_M,
      &brain_DWork.StateFlowFunctionsMaintainDepth);

    /* InitializeConditions for Embedded MATLAB: '<S15>/Blob Extraction' */
    brain_DWork.F0_RTP_n = -1.0;
    brain_DWork.F1_RTP_b = -1.0;
    brain_DWork.F2_RTP_f = -1.0;
    brain_DWork.MINAREA_RTP_l = 5U;
    brain_DWork.hblob_n = TRUE;

    /* InitializeConditions for Embedded MATLAB: '<S14>/Blob Extraction' */
    for (i = 0; i < 8; i++) {
      brain_DWork.WALKER_RTP_e[i] = tmp[i];
      brain_DWork.WALKER_RTP[i] = tmp[i];
    }

    brain_DWork.F0_RTP = -1.0;
    brain_DWork.F1_RTP = -1.0;
    brain_DWork.F2_RTP = -1.0;
    brain_DWork.MINAREA_RTP = 5U;
    brain_DWork.hblob = TRUE;
  }
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
