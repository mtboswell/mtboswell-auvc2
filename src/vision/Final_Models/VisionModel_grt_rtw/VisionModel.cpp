/*
 * VisionModel.cpp
 *
 * Real-Time Workshop code generation for Simulink model "VisionModel.mdl".
 *
 * Model version              : 1.353
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C++ source code generated on : Tue Jun  7 20:16:42 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
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

/* Model output function */
static void VisionModel_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_torpedomdl_o4;
  real_T rtb_torpedomdl_o5;
  real_T rtb_torpedomdl_o6;
  real_T rtb_torpedomdl_o7;
  real_T rtb_torpedomdl_o8;
  real_T rtb_validation_gatemdl_o7;
  int32_T i;

  /* Outport: '<Root>/TargetSelect' incorporates:
   *  Sum: '<Root>/Add'
   */
  VisionModel_Y.TargetSelect = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetFound' incorporates:
   *  Sum: '<Root>/Add1'
   */
  VisionModel_Y.TargetFound = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/MaintainHeading' incorporates:
   *  Sum: '<Root>/Add2'
   */
  VisionModel_Y.MaintainHeading = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetX' incorporates:
   *  Sum: '<Root>/Add3'
   */
  VisionModel_Y.TargetX = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetY' incorporates:
   *  Sum: '<Root>/Add4'
   */
  VisionModel_Y.TargetY = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetZ' incorporates:
   *  Sum: '<Root>/Add5'
   */
  VisionModel_Y.TargetZ = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

  /* Outport: '<Root>/TargetYaw' incorporates:
   *  Sum: '<Root>/Add6'
   */
  VisionModel_Y.TargetYaw = ((((0.0 + 0.0) + 0.0) + 0.0) + 0.0) + 0.0;

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
    mr_validation_gate(&VisionModel_U.R_forward_in[0],
                       &VisionModel_U.G_forward_in[0],
                       &VisionModel_U.B_forward_in[0],
                       &rtb_validation_gatemdl_o7,
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
                       &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));
  } else if (VisionModel_U.ModeSelect == 2.0) {
    /* ModelReference: '<S5>/path_detector.mdl' */
    mr_path_detector(&VisionModel_U.R_down_in[0], &VisionModel_U.G_down_in[0],
                     &VisionModel_U.B_down_in[0],
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
                     &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));
  } else {
    if ((!(VisionModel_U.ModeSelect == 3.0)) && (VisionModel_U.ModeSelect == 4.0))
    {
      for (i = 0; i < 19200; i++) {
        /* SignalConversion: '<S6>/TmpSignal ConversionAttorpedo.mdlInport1' */
        VisionModel_B.TmpSignalConversionAttorped[i] = 0.0;

        /* SignalConversion: '<S6>/TmpSignal ConversionAttorpedo.mdlInport2' */
        VisionModel_B.TmpSignalConversionAttorp_b[i] = 0.0;

        /* SignalConversion: '<S6>/TmpSignal ConversionAttorpedo.mdlInport3' */
        VisionModel_B.TmpSignalConversionAttorp_d[i] = 0.0;
      }

      /* ModelReference: '<S6>/torpedo.mdl' */
      mr_torpedo(VisionModel_B.TmpSignalConversionAttorped,
                 VisionModel_B.TmpSignalConversionAttorp_b,
                 VisionModel_B.TmpSignalConversionAttorp_d, &rtb_torpedomdl_o4,
                 &rtb_torpedomdl_o5, &rtb_torpedomdl_o6, &rtb_torpedomdl_o7,
                 &rtb_torpedomdl_o8, &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                 &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));
    }
  }

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

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void VisionModel_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++VisionModel_M->Timing.clockTick0)) {
    ++VisionModel_M->Timing.clockTickH0;
  }

  VisionModel_M->Timing.t[0] = VisionModel_M->Timing.clockTick0 *
    VisionModel_M->Timing.stepSize0 + VisionModel_M->Timing.clockTickH0 *
    VisionModel_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void VisionModel_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)VisionModel_M, 0,
                sizeof(RT_MODEL_VisionModel));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = VisionModel_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    VisionModel_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    VisionModel_M->Timing.sampleTimes = (&VisionModel_M->
      Timing.sampleTimesArray[0]);
    VisionModel_M->Timing.offsetTimes = (&VisionModel_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    VisionModel_M->Timing.sampleTimes[0] = (0.033333333333333333);

    /* task offsets */
    VisionModel_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(VisionModel_M, &VisionModel_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = VisionModel_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    VisionModel_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(VisionModel_M, 0.0);
  VisionModel_M->Timing.stepSize0 = 0.033333333333333333;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    VisionModel_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(VisionModel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(VisionModel_M->rtwLogInfo, (NULL));
    rtliSetLogT(VisionModel_M->rtwLogInfo, "tout");
    rtliSetLogX(VisionModel_M->rtwLogInfo, "");
    rtliSetLogXFinal(VisionModel_M->rtwLogInfo, "");
    rtliSetSigLog(VisionModel_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(VisionModel_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(VisionModel_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(VisionModel_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(VisionModel_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &VisionModel_Y.TargetSelect,
        &VisionModel_Y.TargetFound,
        &VisionModel_Y.MaintainHeading,
        &VisionModel_Y.TargetX,
        &VisionModel_Y.TargetY,
        &VisionModel_Y.TargetZ,
        &VisionModel_Y.TargetYaw,
        &VisionModel_Y.DesiredTargetX,
        &VisionModel_Y.DesiredTargetY,
        &VisionModel_Y.DesiredTargetZ,
        &VisionModel_Y.DesiredTargetYaw,
        &VisionModel_Y.MeasuredZ,
        &VisionModel_Y.MeasuredYAccel,
        &VisionModel_Y.MeasuredYaw,
        &VisionModel_Y.MeasuredYawRate,
        &VisionModel_Y.DesiredZ,
        &VisionModel_Y.DesiredXVelocity,
        &VisionModel_Y.DesiredYaw
      };

      rtliSetLogYSignalPtrs(VisionModel_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "VisionModel/TargetSelect",
        "VisionModel/TargetFound",
        "VisionModel/MaintainHeading",
        "VisionModel/TargetX",
        "VisionModel/TargetY",
        "VisionModel/TargetZ",
        "VisionModel/TargetYaw",
        "VisionModel/DesiredTargetX",
        "VisionModel/DesiredTargetY",
        "VisionModel/DesiredTargetZ",
        "VisionModel/DesiredTargetYaw",
        "VisionModel/MeasuredZ",
        "VisionModel/MeasuredYAccel",
        "VisionModel/MeasuredYaw",
        "VisionModel/MeasuredYawRate",
        "VisionModel/DesiredZ",
        "VisionModel/DesiredXVelocity",
        "VisionModel/DesiredYaw" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          18,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(VisionModel_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[7];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[8];
      rt_LoggedCurrentSignalDimensions[9] = &rt_LoggedOutputWidths[9];
      rt_LoggedCurrentSignalDimensions[10] = &rt_LoggedOutputWidths[10];
      rt_LoggedCurrentSignalDimensions[11] = &rt_LoggedOutputWidths[11];
      rt_LoggedCurrentSignalDimensions[12] = &rt_LoggedOutputWidths[12];
      rt_LoggedCurrentSignalDimensions[13] = &rt_LoggedOutputWidths[13];
      rt_LoggedCurrentSignalDimensions[14] = &rt_LoggedOutputWidths[14];
      rt_LoggedCurrentSignalDimensions[15] = &rt_LoggedOutputWidths[15];
      rt_LoggedCurrentSignalDimensions[16] = &rt_LoggedOutputWidths[16];
      rt_LoggedCurrentSignalDimensions[17] = &rt_LoggedOutputWidths[17];
    }

    rtliSetLogY(VisionModel_M->rtwLogInfo, "yout");
  }

  VisionModel_M->solverInfoPtr = (&VisionModel_M->solverInfo);
  VisionModel_M->Timing.stepSize = (0.033333333333333333);
  rtsiSetFixedStepSize(&VisionModel_M->solverInfo, 0.033333333333333333);
  rtsiSetSolverMode(&VisionModel_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  VisionModel_M->ModelData.blockIO = ((void *) &VisionModel_B);

  /* parameters */
  VisionModel_M->ModelData.defaultParam = ((real_T *)&VisionModel_P);

  /* states (dwork) */
  VisionModel_M->Work.dwork = ((void *) &VisionModel_DWork);
  (void) memset((void *)&VisionModel_DWork, 0,
                sizeof(D_Work_VisionModel));

  /* external inputs */
  VisionModel_M->ModelData.inputs = (((void*)&VisionModel_U));
  (void) memset((void *)&VisionModel_U, 0,
                sizeof(ExternalInputs_VisionModel));

  /* external outputs */
  VisionModel_M->ModelData.outputs = (&VisionModel_Y);
  (void) memset((void *)&VisionModel_Y, 0,
                sizeof(ExternalOutputs_VisionModel));

  /* Model Initialize fcn for ModelReference Block: '<S2>/drop_mech.mdl' */
  mr_drop_mech_initialize(1, rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.drop_mechmdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S3>/L_detector.mdl' */
  mr_drop_mech_initialize(1, rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.L_detectormdl_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<S5>/path_detector.mdl' */
  mr_path_detector_initialize(1, rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtm),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtb),
    &(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S6>/torpedo.mdl' */
  mr_torpedo_initialize(1, rtmGetErrorStatusPointer(VisionModel_M),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtm),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtb),
                        &(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<S7>/validation_gate.mdl' */
  mr_validation_gate_initialize(1, rtmGetErrorStatusPointer(VisionModel_M),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtm),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtb),
    &(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));
}

/* Model terminate function */
void VisionModel_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
extern "C" void MdlOutputs(int_T tid)
{
  VisionModel_output(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  VisionModel_update(tid);
}

extern "C" void MdlInitializeSizes(void)
{
  VisionModel_M->Sizes.numContStates = (0);/* Number of continuous states */
  VisionModel_M->Sizes.numY = (18);    /* Number of model outputs */
  VisionModel_M->Sizes.numU = (115207);/* Number of model inputs */
  VisionModel_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  VisionModel_M->Sizes.numSampTimes = (1);/* Number of sample times */
  VisionModel_M->Sizes.numBlocks = (54);/* Number of blocks */
  VisionModel_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  VisionModel_M->Sizes.numBlockPrms = (1);/* Sum of parameter "widths" */
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
}

extern "C" void MdlStart(void)
{
  /* Start for ifaction SubSystem: '<Root>/Path Following' */
  /* InitializeConditions for ModelReference: '<S5>/path_detector.mdl' */
  mr_path_detector_Init(&(VisionModel_DWork.path_detectormdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Path Following' */

  /* Start for ifaction SubSystem: '<Root>/Torpedo Target Detection' */
  /* InitializeConditions for ModelReference: '<S6>/torpedo.mdl' */
  mr_torpedo_Init(&(VisionModel_DWork.torpedomdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Torpedo Target Detection' */

  /* Start for ifaction SubSystem: '<Root>/Validation Gate' */
  /* InitializeConditions for ModelReference: '<S7>/validation_gate.mdl' */
  mr_validation_gate_Init(&(VisionModel_DWork.validation_gatemdl_DWORK1.rtdw));

  /* end of Start for SubSystem: '<Root>/Validation Gate' */
  MdlInitialize();
}

extern "C" void MdlTerminate(void)
{
  VisionModel_terminate();
}

extern "C" RT_MODEL_VisionModel *VisionModel(void)
{
  VisionModel_initialize(1);
  return VisionModel_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
