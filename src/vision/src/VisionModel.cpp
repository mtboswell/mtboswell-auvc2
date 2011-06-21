/*
 * File: VisionModel.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.381
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Mon Jun 20 21:35:26 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Mon Jun 20 21:35:26 2011
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
  /* local block i/o variables */
  real_T rtb_torpedomdl_o4;
  real_T rtb_torpedomdl_o5;
  real_T rtb_torpedomdl_o6;
  real_T rtb_torpedomdl_o7;
  real_T rtb_torpedomdl_o8;
  real_T rtb_buoy_detectormdl;
  real_T cc;
  real_T cc_0;
  real_T cc_1;
  uint32_T k;
  real_T t;
  real_T n;
  real_T h;
  int32_T i;
  for (i = 0; i < 19200; i++) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Inport: '<Root>/R_forward_in'
     */
    VisionModel_B.Gain5[i] = VisionModel_P.Gain_Gain *
      VisionModel_U.R_forward_in[i];

    /* Gain: '<S4>/Gain1' incorporates:
     *  Inport: '<Root>/G_forward_in'
     */
    VisionModel_B.Gain4[i] = VisionModel_P.Gain1_Gain *
      VisionModel_U.G_forward_in[i];

    /* Gain: '<S4>/Gain2' incorporates:
     *  Inport: '<Root>/B_forward_in'
     */
    VisionModel_B.Gain3[i] = VisionModel_P.Gain2_Gain *
      VisionModel_U.B_forward_in[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion1' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (VisionModel_B.Gain5[i] > VisionModel_B.Gain4[i]) {
      if (VisionModel_B.Gain4[i] < VisionModel_B.Gain3[i]) {
        h = VisionModel_B.Gain4[i];
      } else {
        h = VisionModel_B.Gain3[i];
      }

      if (VisionModel_B.Gain5[i] > VisionModel_B.Gain3[i]) {
        t = VisionModel_B.Gain5[i];
      } else {
        t = VisionModel_B.Gain3[i];
      }
    } else {
      if (VisionModel_B.Gain5[i] < VisionModel_B.Gain3[i]) {
        h = VisionModel_B.Gain5[i];
      } else {
        h = VisionModel_B.Gain3[i];
      }

      if (VisionModel_B.Gain4[i] > VisionModel_B.Gain3[i]) {
        t = VisionModel_B.Gain4[i];
      } else {
        t = VisionModel_B.Gain3[i];
      }
    }

    h = t - h;
    if (t != 0.0) {
      cc_0 = h / t;
    } else {
      cc_0 = 0.0;
    }

    if (h != 0.0) {
      if (VisionModel_B.Gain5[i] == t) {
        cc = (VisionModel_B.Gain4[i] - VisionModel_B.Gain3[i]) / h;
      } else if (VisionModel_B.Gain4[i] == t) {
        cc = (VisionModel_B.Gain3[i] - VisionModel_B.Gain5[i]) / h + 2.0;
      } else {
        cc = (VisionModel_B.Gain5[i] - VisionModel_B.Gain4[i]) / h + 4.0;
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
    VisionModel_B.Gain3[i] = VisionModel_P.Gain3_Gain *
      VisionModel_B.ColorSpaceConversion1_o1[i];

    /* Gain: '<S4>/Gain4' */
    VisionModel_B.Gain4[i] = VisionModel_P.Gain4_Gain *
      VisionModel_B.ColorSpaceConversion1_o2[i];

    /* Gain: '<S4>/Gain5' */
    VisionModel_B.Gain5[i] = VisionModel_P.Gain5_Gain *
      VisionModel_B.ColorSpaceConversion1_o3[i];
  }

  /* S-Function (svipcolorconv): '<S4>/Color Space  Conversion2' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    h = 6.0 * VisionModel_B.Gain3[i];
    k = (uint32_T)(h - 1.3322676295501878E-15);
    h -= (real_T)k;
    t = 1.0 - VisionModel_B.Gain4[i];
    n = 1.0 - VisionModel_B.Gain4[i] * h;
    h = VisionModel_B.Gain4[i] * h + t;
    if (k == 0U) {
      cc = 1.0;
      cc_0 = h;
      cc_1 = t;
    } else if (k == 1U) {
      cc = n;
      cc_0 = 1.0;
      cc_1 = t;
    } else if (k == 2U) {
      cc = t;
      cc_0 = 1.0;
      cc_1 = h;
    } else if (k == 3U) {
      cc = t;
      cc_0 = n;
      cc_1 = 1.0;
    } else if (k == 4U) {
      cc = h;
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

    h = VisionModel_B.Gain5[i] / t;

    /* assign the results */
    VisionModel_B.ColorSpaceConversion2_o1[i] = h * cc;
    VisionModel_B.ColorSpaceConversion2_o2[i] = h * cc_0;
    VisionModel_B.ColorSpaceConversion2_o3[i] = h * cc_1;
  }

  for (i = 0; i < 19200; i++) {
    /* Gain: '<S2>/Gain6' incorporates:
     *  Inport: '<Root>/R_down_in'
     */
    VisionModel_B.Gain5[i] = VisionModel_P.Gain6_Gain *
      VisionModel_U.R_down_in[i];

    /* Gain: '<S2>/Gain7' incorporates:
     *  Inport: '<Root>/G_down_in'
     */
    VisionModel_B.Gain4[i] = VisionModel_P.Gain7_Gain *
      VisionModel_U.G_down_in[i];

    /* Gain: '<S2>/Gain8' incorporates:
     *  Inport: '<Root>/B_down_in'
     */
    VisionModel_B.Gain3[i] = VisionModel_P.Gain8_Gain *
      VisionModel_U.B_down_in[i];
  }

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion3' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 19200; i++) {
    /* First get the min and max of the RGB triplet */
    if (VisionModel_B.Gain5[i] > VisionModel_B.Gain4[i]) {
      if (VisionModel_B.Gain4[i] < VisionModel_B.Gain3[i]) {
        h = VisionModel_B.Gain4[i];
      } else {
        h = VisionModel_B.Gain3[i];
      }

      if (VisionModel_B.Gain5[i] > VisionModel_B.Gain3[i]) {
        t = VisionModel_B.Gain5[i];
      } else {
        t = VisionModel_B.Gain3[i];
      }
    } else {
      if (VisionModel_B.Gain5[i] < VisionModel_B.Gain3[i]) {
        h = VisionModel_B.Gain5[i];
      } else {
        h = VisionModel_B.Gain3[i];
      }

      if (VisionModel_B.Gain4[i] > VisionModel_B.Gain3[i]) {
        t = VisionModel_B.Gain4[i];
      } else {
        t = VisionModel_B.Gain3[i];
      }
    }

    h = t - h;
    if (t != 0.0) {
      cc_0 = h / t;
    } else {
      cc_0 = 0.0;
    }

    if (h != 0.0) {
      if (VisionModel_B.Gain5[i] == t) {
        cc = (VisionModel_B.Gain4[i] - VisionModel_B.Gain3[i]) / h;
      } else if (VisionModel_B.Gain4[i] == t) {
        cc = (VisionModel_B.Gain3[i] - VisionModel_B.Gain5[i]) / h + 2.0;
      } else {
        cc = (VisionModel_B.Gain5[i] - VisionModel_B.Gain4[i]) / h + 4.0;
      }

      cc /= 6.0;
      if (cc < 0.0) {
        cc++;
      }
    } else {
      cc = 0.0;
    }

    /* assign the results */
    VisionModel_B.ColorSpaceConversion3_o1[i] = cc;
    VisionModel_B.ColorSpaceConversion3_o2[i] = cc_0;
    VisionModel_B.ColorSpaceConversion3_o3[i] = t;
  }

  for (i = 0; i < 19200; i++) {
    /* Gain: '<S2>/Gain9' */
    VisionModel_B.Gain3[i] = VisionModel_P.Gain9_Gain *
      VisionModel_B.ColorSpaceConversion3_o1[i];

    /* Gain: '<S2>/Gain10' */
    VisionModel_B.Gain4[i] = VisionModel_P.Gain10_Gain *
      VisionModel_B.ColorSpaceConversion3_o2[i];

    /* Gain: '<S2>/Gain11' */
    VisionModel_B.Gain5[i] = VisionModel_P.Gain11_Gain *
      VisionModel_B.ColorSpaceConversion3_o3[i];
  }

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion4' */
  /* temporary variables for in-place operation */
  cc = 0.0;
  cc_0 = 0.0;
  cc_1 = 0.0;
  for (i = 0; i < 19200; i++) {
    h = 6.0 * VisionModel_B.Gain3[i];
    k = (uint32_T)(h - 1.3322676295501878E-15);
    h -= (real_T)k;
    t = 1.0 - VisionModel_B.Gain4[i];
    n = 1.0 - VisionModel_B.Gain4[i] * h;
    h = VisionModel_B.Gain4[i] * h + t;
    if (k == 0U) {
      cc = 1.0;
      cc_0 = h;
      cc_1 = t;
    } else if (k == 1U) {
      cc = n;
      cc_0 = 1.0;
      cc_1 = t;
    } else if (k == 2U) {
      cc = t;
      cc_0 = 1.0;
      cc_1 = h;
    } else if (k == 3U) {
      cc = t;
      cc_0 = n;
      cc_1 = 1.0;
    } else if (k == 4U) {
      cc = h;
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

    h = VisionModel_B.Gain5[i] / t;

    /* assign the results */
    VisionModel_B.ColorSpaceConversion4_o1[i] = h * cc;
    VisionModel_B.ColorSpaceConversion4_o2[i] = h * cc_0;
    VisionModel_B.ColorSpaceConversion4_o3[i] = h * cc_1;
  }

  /* If: '<Root>/If' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S3>/Action Port'
   *  ActionPort: '<S5>/Action Port'
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
    /* ModelReference: '<S8>/validation_gate.mdl' */
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
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));
  } else if (VisionModel_U.ModeSelect == 2.0) {
    /* ModelReference: '<S6>/path_detector.mdl' */
    mr_path_detector(VisionModel_B.ColorSpaceConversion4_o1,
                     VisionModel_B.ColorSpaceConversion4_o2,
                     VisionModel_B.ColorSpaceConversion4_o3,
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));
  } else if (VisionModel_U.ModeSelect == 3.0) {
    /* ModelReference: '<S1>/buoy_detector.mdl' */
    mr_buoy_detector(VisionModel_B.ColorSpaceConversion2_o1,
                     VisionModel_B.ColorSpaceConversion2_o2,
                     VisionModel_B.ColorSpaceConversion2_o3,
                     &rtb_buoy_detectormdl,
                     &(VisionModel_DWork.buoy_detectormdl_DWORK1.rtb),
                     &(VisionModel_DWork.buoy_detectormdl_DWORK1.rtdw));
  } else {
    if (VisionModel_U.ModeSelect == 4.0) {
      for (i = 0; i < 19200; i++) {
        /* SignalConversion: '<S7>/TmpSignal ConversionAttorpedo.mdlInport1' */
        VisionModel_B.TmpSignalConversionAttorped[i] = 0.0;

        /* SignalConversion: '<S7>/TmpSignal ConversionAttorpedo.mdlInport2' */
        VisionModel_B.TmpSignalConversionAttorp_b[i] = 0.0;

        /* SignalConversion: '<S7>/TmpSignal ConversionAttorpedo.mdlInport3' */
        VisionModel_B.TmpSignalConversionAttorp_d[i] = 0.0;
      }

      /* ModelReference: '<S7>/torpedo.mdl' */
      mr_torpedo(VisionModel_B.TmpSignalConversionAttorped,
                 VisionModel_B.TmpSignalConversionAttorp_b,
                 VisionModel_B.TmpSignalConversionAttorp_d, &rtb_torpedomdl_o4,
                 &rtb_torpedomdl_o5, &rtb_torpedomdl_o6, &rtb_torpedomdl_o7,
                 &rtb_torpedomdl_o8, &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                 &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));
    }
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
}

/* Model initialize function */
void VisionModel_initialize(void)
{
  /* Registration code */

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

  /* Model Initialize fcn for ModelReference Block: '<S1>/buoy_detector.mdl' */
  mr_buoy_detector_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.buoy_detectormdl_DWORK1.rtm),
    &(VisionModel_DWork.buoy_detectormdl_DWORK1.rtb),
    &(VisionModel_DWork.buoy_detectormdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S3>/drop_mech.mdl' */
  mr_drop_mech_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.drop_mechmdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S5>/L_detector.mdl' */
  mr_drop_mech_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.L_detectormdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S6>/path_detector.mdl' */
  mr_path_detector_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtm),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S7>/torpedo.mdl' */
  mr_torpedo_initialize(rtmGetErrorStatusPointer(VisionModel_M),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtm),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S8>/validation_gate.mdl' */
  mr_validation_gate_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtm),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* Start for ifaction SubSystem: '<Root>/Validation Gate' */
  /* InitializeConditions for ModelReference: '<S8>/validation_gate.mdl' */
  mr_validation_gate_Init(&(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Validation Gate' */

  /* Start for ifaction SubSystem: '<Root>/Buoy Detection' */
  /* InitializeConditions for ModelReference: '<S1>/buoy_detector.mdl' */
  mr_buoy_detector_Init(&(VisionModel_DWork.buoy_detectormdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Buoy Detection' */

  /* Start for ifaction SubSystem: '<Root>/Path Following' */
  /* InitializeConditions for ModelReference: '<S6>/path_detector.mdl' */
  mr_path_detector_Init(&(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Path Following' */

  /* Start for ifaction SubSystem: '<Root>/Torpedo Target Detection' */
  /* InitializeConditions for ModelReference: '<S7>/torpedo.mdl' */
  mr_torpedo_Init(&(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Torpedo Target Detection' */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
