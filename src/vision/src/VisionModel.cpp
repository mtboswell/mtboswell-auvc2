/*
 * File: VisionModel.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.405
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Thu Jun  9 20:27:42 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Thu Jun  9 20:27:42 2011
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

  /* If: '<Root>/If' incorporates:
   *  ActionPort: '<S1>/Action Port'
   *  ActionPort: '<S2>/Action Port'
   *  ActionPort: '<S3>/Action Port'
   *  ActionPort: '<S5>/Action Port'
   *  ActionPort: '<S6>/Action Port'
   *  ActionPort: '<S7>/Action Port'
   *  Inport: '<Root>/ModeSelect'
   *  SubSystem: '<Root>/Buoy Detection'
   *  SubSystem: '<Root>/Drop Mechanism Target'
   *  SubSystem: '<Root>/L-Obstacle Detection'
   *  SubSystem: '<Root>/Path Following'
   *  SubSystem: '<Root>/Torpedo Target Detection'
   *  SubSystem: '<Root>/Validation Gate'
   */
  if (VisionModel_U.ModeSelect == 1.0) {
    /* ModelReference: '<S7>/validation_gate.mdl' */
    mr_validation_gate_v4(&VisionModel_U.R_forward_in[0],
                          &VisionModel_U.G_forward_in[0],
                          &VisionModel_U.B_forward_in[0],
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
    /* ModelReference: '<S5>/path_detector.mdl' */
    mr_path_detector(&VisionModel_U.R_down_in[0], &VisionModel_U.G_down_in[0],
                     &VisionModel_U.B_down_in[0],
                     &(VisionModel_DWork.path_detectormdl_DWORK1_p.rtb),
                     &(VisionModel_DWork.path_detectormdl_DWORK1_p.rtdw));
  } else if (VisionModel_U.ModeSelect == 3.0) {
    /* ModelReference: '<S1>/path_detector.mdl' */
    mr_buoy_detector(&VisionModel_U.R_forward_in[0],
                     &VisionModel_U.G_forward_in[0],
                     &VisionModel_U.B_forward_in[0],
                     &VisionModel_U.DesiredBuoyColor,
                     &VisionModel_B.path_detectormdl_o1,
                     &VisionModel_B.path_detectormdl_o2,
                     &VisionModel_B.path_detectormdl_o3,
                     &VisionModel_B.path_detectormdl_o4,
                     &VisionModel_B.path_detectormdl_o5,
                     &VisionModel_B.path_detectormdl_o6,
                     &VisionModel_B.path_detectormdl_o7,
                     &VisionModel_Y.BuoyColors[0],
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));
  } else {
    if (VisionModel_U.ModeSelect == 4.0) {
      /* ModelReference: '<S6>/torpedo.mdl' */
      mr_torpedo(&VisionModel_U.R_forward_in[0], &VisionModel_U.G_forward_in[0],
                 &VisionModel_U.B_forward_in[0], &rtb_torpedomdl_o4,
                 &rtb_torpedomdl_o5, &rtb_torpedomdl_o6, &rtb_torpedomdl_o7,
                 &rtb_torpedomdl_o8, &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                 &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));
    }
  }

  /* Outport: '<Root>/TargetSelect' incorporates:
   *  Sum: '<Root>/Add'
   */
  VisionModel_Y.TargetSelect = ((((VisionModel_B.validation_gatemdl_o1 + 0.0) +
    VisionModel_B.path_detectormdl_o1) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetFound' incorporates:
   *  Sum: '<Root>/Add1'
   */
  VisionModel_Y.TargetFound = ((((VisionModel_B.validation_gatemdl_o2 + 0.0) +
    VisionModel_B.path_detectormdl_o2) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MaintainHeading' incorporates:
   *  Sum: '<Root>/Add2'
   */
  VisionModel_Y.MaintainHeading = ((((VisionModel_B.validation_gatemdl_o3 + 0.0)
    + VisionModel_B.path_detectormdl_o3) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetX' incorporates:
   *  Sum: '<Root>/Add3'
   */
  VisionModel_Y.TargetX = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetY' incorporates:
   *  Sum: '<Root>/Add4'
   */
  VisionModel_Y.TargetY = ((((VisionModel_B.validation_gatemdl_o4 + 0.0) +
    VisionModel_B.path_detectormdl_o4) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetZ' incorporates:
   *  Sum: '<Root>/Add5'
   */
  VisionModel_Y.TargetZ = ((((VisionModel_B.validation_gatemdl_o5 +
    VisionModel_B.path_detectormdl_o5) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetYaw' incorporates:
   *  Sum: '<Root>/Add6'
   */
  VisionModel_Y.TargetYaw = ((((VisionModel_B.validation_gatemdl_o6 + 0.0) +
    VisionModel_B.path_detectormdl_o6) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetDetected' incorporates:
   *  Sum: '<Root>/Add18'
   */
  VisionModel_Y.TargetDetected = ((((VisionModel_B.validation_gatemdl_o7 + 0.0)
    + VisionModel_B.path_detectormdl_o7) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/PathState' */
  VisionModel_Y.PathState = 0.0;

  /* Outport: '<Root>/FireAuthorization' incorporates:
   *  Sum: '<Root>/Add19'
   */
  VisionModel_Y.FireAuthorization = 0.0 + 0.0;

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

  /* Embedded MATLAB: '<Root>/No longer needed function' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* Embedded MATLAB Function 'No longer needed function': '<S4>:1' */
  /*  This function rotates an image in 90 degree increments */
  /*  */
  /*  Input */
  /*    c1_in = input image component 1 data */
  /*                    Note: Must be a 2-D (single color component) or 3-D */
  /*                      (RGB or similar) array; first two dimensions */
  /*                      specify image height and width, respectively */
  /*    c2_in = input image component 2 data */
  /*    c3_in = input image component 3 data */
  /*  */
  /*  Output */
  /*    c1_out = output image component 1 data */
  /*    c1_out = output image component 2 data */
  /*    c1_out = output image component 3 data */
  /*  Determine loop indices */
  /*  Initialize output */
  /* '<S4>:1:24' */
  /* '<S4>:1:25' */
  /* '<S4>:1:26' */
  /*  Loop */
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

  /* Model Initialize fcn for ModelReference Block: '<S1>/path_detector.mdl' */
  mr_buoy_detector_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtm),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S2>/drop_mech.mdl' */
  mr_drop_mech_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.drop_mechmdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S3>/L_detector.mdl' */
  mr_drop_mech_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.L_detectormdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S5>/path_detector.mdl' */
  mr_path_detector_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.path_detectormdl_DWORK1_p.rtm),
    &(VisionModel_DWork.path_detectormdl_DWORK1_p.rtb),
    &(VisionModel_DWork.path_detectormdl_DWORK1_p.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S6>/torpedo.mdl' */
  mr_torpedo_initialize(rtmGetErrorStatusPointer(VisionModel_M),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtm),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S7>/validation_gate.mdl' */
  mr_validation_gate_v_initialize(rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtm),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* Start for ifaction SubSystem: '<Root>/Validation Gate' */
  /* InitializeConditions for ModelReference: '<S7>/validation_gate.mdl' */
  mr_validation_gate_v4_Init(&(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Validation Gate' */

  /* Start for ifaction SubSystem: '<Root>/Path Following' */
  /* InitializeConditions for ModelReference: '<S5>/path_detector.mdl' */
  mr_path_detector_Init(&(VisionModel_DWork.path_detectormdl_DWORK1_p.rtdw));

  /* end of Start for SubSystem: '<Root>/Path Following' */

  /* Start for ifaction SubSystem: '<Root>/Buoy Detection' */
  /* InitializeConditions for ModelReference: '<S1>/path_detector.mdl' */
  mr_buoy_detector_Init(&(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Buoy Detection' */

  /* Start for ifaction SubSystem: '<Root>/Torpedo Target Detection' */
  /* InitializeConditions for ModelReference: '<S6>/torpedo.mdl' */
  mr_torpedo_Init(&(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Torpedo Target Detection' */
}

/* Model terminate function */
void VisionModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
