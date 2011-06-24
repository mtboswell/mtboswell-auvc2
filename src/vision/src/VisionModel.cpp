/*
 * File: VisionModel.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.418
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Wed Jun 22 20:43:47 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Wed Jun 22 20:43:48 2011
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

/* Model step function */
void VisionModel_step(void)
{
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  uint32_T k;
  real_T t;
  real_T n;
  real_T normalizeValue;
  real_T maxval[120];
  int32_T ix;
  int32_T iy;
  int32_T b_ix;
  int32_T b_itmp;
  boolean_T b_searchingForNonNaN;
  int32_T c_k;
  boolean_T guard;
  boolean_T exitg;
  int32_T i;

  /* Embedded MATLAB: '<Root>/Transform Coordinates1' incorporates:
   *  Inport: '<Root>/B_forward_in'
   *  Inport: '<Root>/G_forward_in'
   *  Inport: '<Root>/R_forward_in'
   */
  /* Embedded MATLAB Function 'Transform Coordinates1': '<S9>:1' */
  /*  Ensure the image components are between 0 and newMax */
  /* '<S9>:1:6' */
  /* '<S9>:1:7' */
  /* '<S9>:1:8' */
  for (i = 0; i < 19200; i++) {
    VisionModel_B.R_out[i] = VisionModel_U.R_forward_in[i];
    VisionModel_B.G_out[i] = VisionModel_U.G_forward_in[i];
    VisionModel_B.B_out[i] = VisionModel_U.B_forward_in[i];
  }

  /* '<S9>:1:10' */
  ix = 0;
  iy = 0;
  for (i = 0; i < 120; i++) {
    ix++;
    normalizeValue = VisionModel_U.R_forward_in[ix - 1];
    b_itmp = 1;
    b_ix = ix;
    guard = FALSE;
    if (rtIsNaN(VisionModel_U.R_forward_in[ix - 1])) {
      b_searchingForNonNaN = TRUE;
      c_k = 2;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (c_k < 161)) {
        b_ix++;
        if (!rtIsNaN(VisionModel_U.R_forward_in[b_ix - 1])) {
          normalizeValue = VisionModel_U.R_forward_in[b_ix - 1];
          b_itmp = c_k;
          b_searchingForNonNaN = FALSE;
          exitg = TRUE;
        } else {
          c_k++;
        }
      }

      if (!b_searchingForNonNaN) {
        guard = TRUE;
      }
    } else {
      guard = TRUE;
    }

    if (guard) {
      for (b_itmp++; b_itmp < 161; b_itmp++) {
        b_ix++;
        if (VisionModel_U.R_forward_in[b_ix - 1] > normalizeValue) {
          normalizeValue = VisionModel_U.R_forward_in[b_ix - 1];
        }
      }
    }

    iy++;
    maxval[iy - 1] = normalizeValue;
    ix += 159;
  }

  normalizeValue = maxval[0];
  b_itmp = 1;
  ix = 1;
  guard = FALSE;
  if (rtIsNaN(maxval[0])) {
    b_searchingForNonNaN = TRUE;
    c_k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (c_k < 121)) {
      ix++;
      if (!rtIsNaN(maxval[ix - 1])) {
        normalizeValue = maxval[ix - 1];
        b_itmp = c_k;
        b_searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        c_k++;
      }
    }

    if (!b_searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    for (b_itmp++; b_itmp < 121; b_itmp++) {
      ix++;
      if (maxval[ix - 1] > normalizeValue) {
        normalizeValue = maxval[ix - 1];
      }
    }
  }

  if (normalizeValue <= 1.0) {
    /* '<S9>:1:11' */
    /* '<S9>:1:12' */
    normalizeValue = 1.0;
  } else {
    /* '<S9>:1:14' */
    normalizeValue = 255.0;
  }

  /* '<S9>:1:20' */
  for (b_itmp = 0; b_itmp < 160; b_itmp++) {
    /* '<S9>:1:20' */
    /* '<S9>:1:21' */
    for (c_k = 0; c_k < 120; c_k++) {
      /* '<S9>:1:21' */
      if (VisionModel_U.R_forward_in[160 * c_k + b_itmp] == 0.0) {
        /* '<S9>:1:23' */
        /* '<S9>:1:24' */
        VisionModel_B.R_out[b_itmp + 160 * c_k] = 0.0;
      } else {
        /* '<S9>:1:26' */
        VisionModel_B.R_out[b_itmp + 160 * c_k] = VisionModel_U.R_forward_in[160
          * c_k + b_itmp] / normalizeValue;
      }

      if (VisionModel_U.G_forward_in[160 * c_k + b_itmp] == 0.0) {
        /* '<S9>:1:28' */
        /* '<S9>:1:29' */
        VisionModel_B.G_out[b_itmp + 160 * c_k] = 0.0;
      } else {
        /* '<S9>:1:31' */
        VisionModel_B.G_out[b_itmp + 160 * c_k] = VisionModel_U.G_forward_in[160
          * c_k + b_itmp] / normalizeValue;
      }

      if (VisionModel_U.B_forward_in[160 * c_k + b_itmp] == 0.0) {
        /* '<S9>:1:33' */
        /* '<S9>:1:34' */
        VisionModel_B.B_out[b_itmp + 160 * c_k] = 0.0;
      } else {
        /* '<S9>:1:36' */
        VisionModel_B.B_out[b_itmp + 160 * c_k] = VisionModel_U.B_forward_in[160
          * c_k + b_itmp] / normalizeValue;
      }
    }
  }

  for (i = 0; i < 19200; i++) {
    VisionModel_B.R_out[i] = VisionModel_P.Gain_Gain * VisionModel_B.R_out[i];
    VisionModel_B.G_out[i] = VisionModel_P.Gain1_Gain * VisionModel_B.G_out[i];
    VisionModel_B.B_out[i] = VisionModel_P.Gain2_Gain * VisionModel_B.B_out[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (VisionModel_B.R_out[i] > VisionModel_B.G_out[i]) {
      if (VisionModel_B.G_out[i] < VisionModel_B.B_out[i]) {
        normalizeValue = VisionModel_B.G_out[i];
      } else {
        normalizeValue = VisionModel_B.B_out[i];
      }

      if (VisionModel_B.R_out[i] > VisionModel_B.B_out[i]) {
        t = VisionModel_B.R_out[i];
      } else {
        t = VisionModel_B.B_out[i];
      }
    } else {
      if (VisionModel_B.R_out[i] < VisionModel_B.B_out[i]) {
        normalizeValue = VisionModel_B.R_out[i];
      } else {
        normalizeValue = VisionModel_B.B_out[i];
      }

      if (VisionModel_B.G_out[i] > VisionModel_B.B_out[i]) {
        t = VisionModel_B.G_out[i];
      } else {
        t = VisionModel_B.B_out[i];
      }
    }

    normalizeValue = t - normalizeValue;
    if (t != 0.0) {
      cc_0 = normalizeValue / t;
    } else {
      cc_0 = 0.0;
    }

    if (normalizeValue != 0.0) {
      if (VisionModel_B.R_out[i] == t) {
        cc = (VisionModel_B.G_out[i] - VisionModel_B.B_out[i]) / normalizeValue;
      } else if (VisionModel_B.G_out[i] == t) {
        cc = (VisionModel_B.B_out[i] - VisionModel_B.R_out[i]) / normalizeValue
          + 2.0;
      } else {
        cc = (VisionModel_B.R_out[i] - VisionModel_B.G_out[i]) / normalizeValue
          + 4.0;
      }

      cc /= 6.0;
      if (cc < 0.0) {
        cc++;
      }
    } else {
      cc = 0.0;
    }

    /* assign the results */
    VisionModel_B.ColorSpaceConversion1_o1[i] = cc;
    VisionModel_B.ColorSpaceConversion1_o2[i] = cc_0;
    VisionModel_B.ColorSpaceConversion1_o3[i] = t;
  }

  for (i = 0; i < 19200; i++) {
    /* Gain: '<S4>/Gain3' */
    VisionModel_B.B_out[i] = VisionModel_P.Gain3_Gain *
      VisionModel_B.ColorSpaceConversion1_o1[i];

    /* Gain: '<S4>/Gain4' */
    VisionModel_B.G_out[i] = VisionModel_P.Gain4_Gain *
      VisionModel_B.ColorSpaceConversion1_o2[i];

    /* Gain: '<S4>/Gain5' */
    VisionModel_B.R_out[i] = VisionModel_P.Gain5_Gain *
      VisionModel_B.ColorSpaceConversion1_o3[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    normalizeValue = 6.0 * VisionModel_B.B_out[i];
    k = (uint32_T)(normalizeValue - 1.3322676295501878E-15);
    normalizeValue -= (real_T)k;
    t = 1.0 - VisionModel_B.G_out[i];
    n = 1.0 - VisionModel_B.G_out[i] * normalizeValue;
    normalizeValue = VisionModel_B.G_out[i] * normalizeValue + t;
    if (k == 0U) {
      cc = 1.0;
      cc_0 = normalizeValue;
      cc_1 = t;
    } else if (k == 1U) {
      cc = n;
      cc_0 = 1.0;
      cc_1 = t;
    } else if (k == 2U) {
      cc = t;
      cc_0 = 1.0;
      cc_1 = normalizeValue;
    } else if (k == 3U) {
      cc = t;
      cc_0 = n;
      cc_1 = 1.0;
    } else if (k == 4U) {
      cc = normalizeValue;
      cc_0 = t;
      cc_1 = 1.0;
    } else {
      if (k == 5U) {
        cc = 1.0;
        cc_0 = t;
        cc_1 = n;
      }
    }

    if (cc > cc_0) {
      t = cc;
    } else {
      t = cc_0;
    }

    if (!(t > cc_1)) {
      t = cc_1;
    }

    normalizeValue = VisionModel_B.R_out[i] / t;

    /* assign the results */
    VisionModel_B.ColorSpaceConversion2_o1[i] = normalizeValue * cc;
    VisionModel_B.ColorSpaceConversion2_o2[i] = normalizeValue * cc_0;
    VisionModel_B.ColorSpaceConversion2_o3[i] = normalizeValue * cc_1;
  }

  /* If: '<Root>/If' incorporates:
   *  ActionPort: '<S10>/Action Port'
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S3>/Action Port'
   *  ActionPort: '<S6>/Action Port'
   *  ActionPort: '<S7>/Action Port'
   *  ActionPort: '<S8>/Action Port'
   *  Inport: '<Root>/ModeSelect'
   *  SubSystem: '<Root>/Buoy Detection'
   *  SubSystem: '<Root>/Drop Mechanism Target'
   *  SubSystem: '<Root>/L-Obstacle Detection'
   *  SubSystem: '<Root>/Path Following'
   *  SubSystem: '<Root>/Torpedo Target Detection'
   *  SubSystem: '<Root>/Validation Gate'
   */
  if (VisionModel_U.ModeSelect == 1.0) {
    /* ModelReference: '<S10>/validation_gate.mdl' */
    mr_validation_gate(VisionModel_B.ColorSpaceConversion2_o1,
                       VisionModel_B.ColorSpaceConversion2_o2,
                       VisionModel_B.ColorSpaceConversion2_o3,
                       &VisionModel_B.validation_gatemdl_o1,
                       &VisionModel_B.validation_gatemdl_o2,
                       &VisionModel_B.validation_gatemdl_o3,
                       &VisionModel_B.validation_gatemdl_o4,
                       &VisionModel_B.validation_gatemdl_o5,
                       &VisionModel_B.validation_gatemdl_o6,
                       &VisionModel_B.validation_gatemdl_o7,
                       VisionModel_B.validation_gatemdl_o8,
                       VisionModel_B.validation_gatemdl_o9,
                       VisionModel_B.validation_gatemdl_o10,
                       &VisionModel_Y.theta[0], &VisionModel_Y.LabelMatrix[0],
                       &VisionModel_Y.num_colors, &VisionModel_Y.ref_colors[0],
                       &VisionModel_Y.bw_image[0], &VisionModel_Y.edge_image[0],
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));
  }

  /* Outport: '<Root>/TargetSelect' incorporates:
   *  Sum: '<Root>/Add'
   */
  VisionModel_Y.TargetSelect = ((((VisionModel_B.validation_gatemdl_o1 + 0.0) +
    0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetFound' incorporates:
   *  Sum: '<Root>/Add1'
   */
  VisionModel_Y.TargetFound = ((((VisionModel_B.validation_gatemdl_o2 + 0.0) +
    0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MaintainHeading' incorporates:
   *  Sum: '<Root>/Add2'
   */
  VisionModel_Y.MaintainHeading = ((((VisionModel_B.validation_gatemdl_o3 + 0.0)
    + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetY' incorporates:
   *  Sum: '<Root>/Add4'
   */
  VisionModel_Y.TargetY = ((((VisionModel_B.validation_gatemdl_o4 + 0.0) + 0.0)
    + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetZ' incorporates:
   *  Sum: '<Root>/Add5'
   */
  VisionModel_Y.TargetZ = ((((VisionModel_B.validation_gatemdl_o5 + 0.0) + 0.0)
    + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetYaw' incorporates:
   *  Sum: '<Root>/Add6'
   */
  VisionModel_Y.TargetYaw = ((((VisionModel_B.validation_gatemdl_o6 + 0.0) + 0.0)
    + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetDetected' incorporates:
   *  Sum: '<Root>/Add18'
   */
  VisionModel_Y.TargetDetected = ((((VisionModel_B.validation_gatemdl_o7 + 0.0)
    + 0.0) + 0.0) + 0.0) + 0.0;

  /* Embedded MATLAB: '<Root>/Identify Validation Gate' */
  /* Embedded MATLAB Function 'Identify Validation Gate': '<S5>:1' */
  /* '<S5>:1:5' */
  /* debugging_output = max(max(max(g))); */

  /* Outport: '<Root>/DummieVariable' */
  VisionModel_Y.DummieVariable = sqrt((rt_pow_snf
    (VisionModel_B.ColorSpaceConversion2_o1[7889], 2.0) + rt_pow_snf
    (VisionModel_B.ColorSpaceConversion2_o2[7889], 2.0)) + rt_pow_snf
    (VisionModel_B.ColorSpaceConversion2_o3[7889], 2.0));
  for (i = 0; i < 19200; i++) {
    /* Outport: '<Root>/R' incorporates:
     *  Sum: '<Root>/Add22'
     */
    VisionModel_Y.R[i] = ((((VisionModel_B.validation_gatemdl_o8[i] + 0.0) + 0.0)
      + 0.0) + 0.0) + 0.0;

    /* Outport: '<Root>/G' incorporates:
     *  Sum: '<Root>/Add23'
     */
    VisionModel_Y.G[i] = ((((VisionModel_B.validation_gatemdl_o9[i] + 0.0) + 0.0)
      + 0.0) + 0.0) + 0.0;

    /* Outport: '<Root>/B' incorporates:
     *  Sum: '<Root>/Add24'
     */
    VisionModel_Y.B[i] = ((((VisionModel_B.validation_gatemdl_o10[i] + 0.0) +
      0.0) + 0.0) + 0.0) + 0.0;
  }

  /* Outport: '<Root>/TargetX' incorporates:
   *  Sum: '<Root>/Add3'
   */
  VisionModel_Y.TargetX = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredTargetX' incorporates:
   *  Sum: '<Root>/Add7'
   */
  VisionModel_Y.DesiredTargetX = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredTargetY' incorporates:
   *  Sum: '<Root>/Add8'
   */
  VisionModel_Y.DesiredTargetY = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredTargetZ' incorporates:
   *  Sum: '<Root>/Add9'
   */
  VisionModel_Y.DesiredTargetZ = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredTargetYaw' incorporates:
   *  Sum: '<Root>/Add10'
   */
  VisionModel_Y.DesiredTargetYaw = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MeasuredZ' incorporates:
   *  Sum: '<Root>/Add11'
   */
  VisionModel_Y.MeasuredZ = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MeasuredYAccel' incorporates:
   *  Sum: '<Root>/Add12'
   */
  VisionModel_Y.MeasuredYAccel = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MeasuredYaw' incorporates:
   *  Sum: '<Root>/Add13'
   */
  VisionModel_Y.MeasuredYaw = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MeasuredYawRate' incorporates:
   *  Sum: '<Root>/Add14'
   */
  VisionModel_Y.MeasuredYawRate = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredZ' incorporates:
   *  Sum: '<Root>/Add15'
   */
  VisionModel_Y.DesiredZ = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredXVelocity' incorporates:
   *  Sum: '<Root>/Add16'
   */
  VisionModel_Y.DesiredXVelocity = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/DesiredYaw' incorporates:
   *  Sum: '<Root>/Add17'
   */
  VisionModel_Y.DesiredYaw = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/PathState' */
  VisionModel_Y.PathState = 0.0;

  /* Outport: '<Root>/BuoyColors' */
  VisionModel_Y.BuoyColors = 0.0;

  /* Outport: '<Root>/FireAuthorization' */
  VisionModel_Y.FireAuthorization = 0.0;

  /* Outport: '<Root>/Iter_Segment_Thresh' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  VisionModel_Y.Iter_Segment_Thresh = VisionModel_P.Constant2_Value;
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

  /* Model Initialize fcn for ModelReference Block: '<S10>/validation_gate.mdl' */
  mr_validation_gate_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtm),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* Start for ifaction SubSystem: '<Root>/Validation Gate' */
  /* InitializeConditions for ModelReference: '<S10>/validation_gate.mdl' */
  mr_validation_gate_Init(&(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Validation Gate' */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
