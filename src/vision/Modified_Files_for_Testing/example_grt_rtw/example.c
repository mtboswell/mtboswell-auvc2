/*
 * example.c
 *
 * Real-Time Workshop code generation for Simulink model "example.mdl".
 *
 * Model version              : 1.1
 * Real-Time Workshop version : 7.6  (R2010b)  03-Aug-2010
 * C source code generated on : Tue Jun  7 19:19:07 2011
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "example.h"
#include "example_private.h"

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_example example_Y;

/* Real-time model */
RT_MODEL_example example_M_;
RT_MODEL_example *example_M = &example_M_;

/* Model output function */
static void example_output(int_T tid)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sin: '<Root>/Sine Wave'
   */
  example_Y.Out1 = (sin(example_P.SineWave_Freq * example_M->Timing.t[0] +
                        example_P.SineWave_Phase) * example_P.SineWave_Amp +
                    example_P.SineWave_Bias) * example_P.Gain_Gain;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void example_update(int_T tid)
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
  if (!(++example_M->Timing.clockTick0)) {
    ++example_M->Timing.clockTickH0;
  }

  example_M->Timing.t[0] = example_M->Timing.clockTick0 *
    example_M->Timing.stepSize0 + example_M->Timing.clockTickH0 *
    example_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void example_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)example_M, 0,
                sizeof(RT_MODEL_example));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&example_M->solverInfo, &example_M->Timing.simTimeStep);
    rtsiSetTPtr(&example_M->solverInfo, &rtmGetTPtr(example_M));
    rtsiSetStepSizePtr(&example_M->solverInfo, &example_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&example_M->solverInfo, (&rtmGetErrorStatus(example_M)));
    rtsiSetRTModelPtr(&example_M->solverInfo, example_M);
  }

  rtsiSetSimTimeStep(&example_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&example_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = example_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    example_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    example_M->Timing.sampleTimes = (&example_M->Timing.sampleTimesArray[0]);
    example_M->Timing.offsetTimes = (&example_M->Timing.offsetTimesArray[0]);

    /* task periods */
    example_M->Timing.sampleTimes[0] = (0.0);

    /* task offsets */
    example_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(example_M, &example_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = example_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    example_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(example_M, 0.0);
  example_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    example_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(example_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(example_M->rtwLogInfo, (NULL));
    rtliSetLogT(example_M->rtwLogInfo, "tout");
    rtliSetLogX(example_M->rtwLogInfo, "");
    rtliSetLogXFinal(example_M->rtwLogInfo, "");
    rtliSetSigLog(example_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(example_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(example_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(example_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(example_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &example_Y.Out1
      };

      rtliSetLogYSignalPtrs(example_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "example/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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

      rtliSetLogYSignalInfo(example_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(example_M->rtwLogInfo, "yout");
  }

  example_M->solverInfoPtr = (&example_M->solverInfo);
  example_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&example_M->solverInfo, 0.2);
  rtsiSetSolverMode(&example_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  example_M->ModelData.defaultParam = ((real_T *)&example_P);

  /* external outputs */
  example_M->ModelData.outputs = (&example_Y);
  example_Y.Out1 = 0.0;
}

/* Model terminate function */
void example_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  example_output(tid);
}

void MdlUpdate(int_T tid)
{
  example_update(tid);
}

void MdlInitializeSizes(void)
{
  example_M->Sizes.numContStates = (0);/* Number of continuous states */
  example_M->Sizes.numY = (1);         /* Number of model outputs */
  example_M->Sizes.numU = (0);         /* Number of model inputs */
  example_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  example_M->Sizes.numSampTimes = (1); /* Number of sample times */
  example_M->Sizes.numBlocks = (3);    /* Number of blocks */
  example_M->Sizes.numBlockIO = (0);   /* Number of block outputs */
  example_M->Sizes.numBlockPrms = (5); /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  example_terminate();
}

RT_MODEL_example *example(void)
{
  example_initialize(1);
  return example_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
