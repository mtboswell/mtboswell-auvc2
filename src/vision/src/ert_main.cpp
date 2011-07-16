/*
 * File: ert_main.cpp
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.1591
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sat Jul 16 10:14:56 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sat Jul 16 10:14:57 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "VisionModel.h"               /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = 0;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(VisionModel_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  VisionModel_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = FALSE;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustates how you do this relative to initializing the model.
 */
//int_T main(int_T argc, const char_T *argv[]);
//int_T main(int_T argc, const char_T *argv[])
//{
//  /* Initialize model */
//  VisionModel_initialize();

//  /* Attach rt_OneStep to a timer or interrupt service routine with
//   * period 0.033333333333333333 seconds (the model's base sample time) here.  The
//   * call syntax for rt_OneStep is
//   *
//   *  rt_OneStep();
//   */
//  printf("Warning: The simulation will run forever. "
//         "Generated ERT main won't simulate model step behavior. "
//         "To change this behavior select the 'MAT-file logging' option.\n");
//  fflush((NULL));
//  while (rtmGetErrorStatus(VisionModel_M) == (NULL)) {
//    /*  Perform other application tasks here */
//  }

//  /* Disable rt_OneStep() here */
//  return 0;
//}

///*
// * File trailer for Real-Time Workshop generated code.
// *
// * [EOF]
// */
