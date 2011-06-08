/*
 * File: path_detector_data.cpp
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.215
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:51:10 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:51:10 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "path_detector.h"
#include "path_detector_private.h"

/* Constant parameters (auto storage) */
const ConstParam_path_detector path_detector_ConstP = {
  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { 0.125, 0.25, 0.125, -0.125, -0.25, -0.125 },

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { 0.125, -0.125, 0.25, -0.25, 0.125, -0.125 },

  /* Computed Parameter: HoughTransform1_SINE
   * Referenced by: '<Root>/Hough Transform1'
   */
  { -1.0, -0.99984769515639127, -0.99939082701909576, -0.99862953475457383,
    -0.9975640502598242, -0.99619469809174555, -0.99452189536827329,
    -0.992546151641322, -0.99026806874157036, -0.98768834059513777,
    -0.984807753012208, -0.981627183447664, -0.97814760073380558,
    -0.97437006478523525, -0.97029572627599647, -0.96592582628906831,
    -0.96126169593831889, -0.95630475596303544, -0.95105651629515353,
    -0.94551857559931674, -0.93969262078590832, -0.93358042649720174,
    -0.92718385456678742, -0.92050485345244037, -0.91354545764260087,
    -0.90630778703664994, -0.898794046299167, -0.89100652418836779,
    -0.88294759285892688, -0.87461970713939574, -0.8660254037844386,
    -0.85716730070211233, -0.848048096156426, -0.838670567945424,
    -0.82903757255504174, -0.8191520442889918, -0.80901699437494745,
    -0.79863551004729283, -0.788010753606722, -0.7771459614569709,
    -0.766044443118978, -0.754709580222772, -0.74314482547739424,
    -0.73135370161917046, -0.71933980033865108, -0.70710678118654746,
    -0.69465837045899725, -0.68199836006249848, -0.66913060635885824,
    -0.65605902899050728, -0.64278760968653925, -0.62932039104983739,
    -0.61566147532565829, -0.60181502315204827, -0.58778525229247314,
    -0.573576436351046, -0.5591929034707469, -0.54463903501502708,
    -0.5299192642332049, -0.51503807491005416, -0.49999999999999994,
    -0.48480962024633706, -0.46947156278589081, -0.45399049973954675,
    -0.4383711467890774, -0.42261826174069944, -0.40673664307580021,
    -0.39073112848927377, -0.374606593415912, -0.35836794954530027,
    -0.34202014332566871, -0.3255681544571567, -0.3090169943749474,
    -0.29237170472273677, -0.27563735581699916, -0.25881904510252074,
    -0.24192189559966773, -0.224951054343865, -0.20791169081775934,
    -0.1908089953765448, -0.17364817766693033, -0.15643446504023087,
    -0.13917310096006544, -0.12186934340514748, -0.10452846326765347,
    -0.087155742747658166, -0.0697564737441253, -0.052335956242943835,
    -0.034899496702500969, -0.017452406437283512, 0.0 },

  /* Computed Parameter: HoughTransform1_FIRSTRHO_R
   * Referenced by: '<Root>/Hough Transform1'
   */
  -199.0,

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { -1, -1, -1, 1, 1, 1 },

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { -1, 0, 1, -1, 0, 1 },

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { -1, -1, 0, 0, 1, 1 },

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  { -1, 1, -1, 1, -1, 1 }
};

/* Invariant block signals (auto storage) */
rtC_mr_path_detector path_detector_ConstB = {
  0.0
  ,                                    /* 'synthesized block' */
  0.0
  ,                                    /* 'synthesized block' */
  0.0
  ,                                    /* 'synthesized block' */
  0.0
  /* 'synthesized block' */
};

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
