/* $Revision: 1.31.4.15 $
 * Copyright 1994-2008 The MathWorks, Inc.
 *
 * File: ert_main.c
 *
 * Abstract:
 *
 *   An embedded real-time main that runs the generated Real-Time
 *   Workshop code under most operating systems.  Based on the value
 *   of NUMST and definition of MULTITAKING a single rate/single task, 
 *   multirate/single task or multirate/multitask step function is 
 *   employed.
 *
 *   This file is a useful starting point when targeting a custom
 *   floating point processor or integer microcontroller.
 *
 *   Alternatively, you can generate a sample ert_main.c file with the
 *   generated code by selecting the "Generate a sample main program"
 *   option.  In this case, ert_main.c is precisely customized to the
 *   model requirements.  Demo models for deploying the generated code
 *   on a bare board target (i.e., no operating system) for the various
 *   scenarios are:
 *
 *     ecsample1 (single rate)
 *     ecsample2 (multirate/singletasking)
 *     ecsample3 (multirate/multitaksing)
 *
 *   Demo models for deploying the generated code on a real-time
 *   operating system for the various scenarios are:
 *
 *     ecsample3 (single rate)
 *     ecsample4 (multirate/singletasking)
 *     ecsample5 (multirate/multitaksing)
 *
 * Required Defines:
 *
 *   MODEL - Model name
 *   NUMST - Number of sample times
 *
 */

/*==================*
 * Required defines *
 *==================*/

#ifndef MODEL
# error Must specify a model name.  Define MODEL=name.
#else
/* create generic marcros that work with any model */
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL           CONCAT(MODEL,_M)
#endif

#ifndef NUMST
# error Must specify the number of sample times.  Define NUMST=number.
#endif

#if ONESTEPFCN==0
#error Separate output and update functions are not supported by ert_main.c. \
You must update ert_main.c to suit your application needs, or select \
the 'Single output/update function' option.
#endif

#if TERMFCN==0
#error The terminate function is required by ert_main.c. \
You must update ert_main.c to suit your application needs, or select \
the 'Terminate function required' option.
#endif

#if MULTI_INSTANCE_CODE==1
#error The static version of ert_main.c does not support reusable \
code generation.  Either deselect ERT option 'Generate reusable code', \
select option 'Generate an example main program', or modify ert_main.c for \
your application needs.
#endif

#ifdef EXT_MODE
#error External Mode is only available when checking the \
'Generate an example main program' box under 'ERT code generation options'.
#endif

/*==========*
 * Includes *
 *==========*/

#include "simstruc_types.h"
#include "rtwtypes.h"
#if !defined(INTEGER_CODE) || INTEGER_CODE == 0
# include <stdio.h>    /* optional for printf */
#else
  extern int printf(const char *, ...); 
  extern int fflush(void *);
#endif
#include <string.h>    /* optional for strcmp */
#include "autobuild.h" /* optional for automated builds */

#ifdef MODEL_STEP_FCN_CONTROL_USED
#error The static version of ert_main.c does not support model step function prototype control.
#endif

/* moved from simstruc_types.h as only ert_main.c needs it */
/*========================* 
 * Setup for multitasking * 
 *========================*/

/* 
 * Let MT be synonym for MULTITASKING (to shorten command line for DOS) 
 */
#if defined(MT)
# if MT == 0
# undef MT
# else
# define MULTITASKING 1
# endif
#endif

#if defined(TID01EQ) && TID01EQ == 1 && NCSTATES==0
#define DISC_NUMST (NUMST - 1)
#else 
#define DISC_NUMST NUMST
#endif

#if defined(TID01EQ) && TID01EQ == 1
#define FIRST_TID 1
#else 
#define FIRST_TID 0
#endif

/*====================*
 * External functions *
 *====================*/

#if defined(INCLUDE_FIRST_TIME_ARG) && INCLUDE_FIRST_TIME_ARG==0
extern void MODEL_INITIALIZE(void);
#else
extern void MODEL_INITIALIZE(boolean_T firstTime);
#endif
extern void MODEL_TERMINATE(void);

#if DISC_NUMST == 1
 extern void MODEL_STEP(void);       /* single rate step function */
#else
 extern void MODEL_STEP(int_T tid);  /* multirate step function */
#endif


/*==================================*
 * Global data local to this module *
 *==================================*/
#ifndef MULTITASKING
static boolean_T OverrunFlags[1];    /* ISR overrun flags */
static boolean_T eventFlags[1];      /* necessary for overlapping preemption */
#else
static boolean_T OverrunFlags[NUMST];
static boolean_T eventFlags[NUMST]; 
#endif

/*===================*
 * Visible functions *
 *===================*/

#if DISC_NUMST == 1 && !defined(MULTITASKING) /* single rate - single task */

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 */
void rt_OneStep(void)
{
    /* Disable interrupts here */

    /***********************************************
     * Check and see if base step time is too fast *
     ***********************************************/
    if (OverrunFlags[0]++) {
        rtmSetErrorStatus(RT_MDL, "Overrun");
    }

    /*************************************************
     * Check and see if an error status has been set *
     * by an overrun or by the generated code.       *
     *************************************************/
    if (rtmGetErrorStatus(RT_MDL) != NULL) {
        return;
    }

    /* Save FPU context here (if necessary) */
    /* Re-enable interrupts here */
    /* Set model inputs here */

    /**************
     * Step model *
     **************/
    MODEL_STEP();

    /* Get model outputs here */

    /**************************
     * Decrement overrun flag *
     **************************/
    OverrunFlags[0]--;

    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Re-enable interrupts here */

    return;
} /* rtOneStep */


#elif DISC_NUMST > 1 && !defined(MULTITASKING) /* multirate - single task */
/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 *
 *   This routine is designed for a single tasking real-time environment.
 *
 *   Note that error checking is only neccessary when this routine is
 *   attached to an interrupt.
 *
 *   Also, you may wish to unroll any or all of for and while loops to
 *   improve the real-time performace of this function.
 */
void rt_OneStep(void)
{
     /* Disable interrupts here */

    /***********************************************
     * Check and see if base step time is too fast *
     ***********************************************/
    if (OverrunFlags[0]++) {
        rtmSetErrorStatus(RT_MDL, "Overrun");
    }

    /*************************************************
     * Check and see if an error status has been set *
     * by an overrun or by the generated code.       *
     *************************************************/
    if (rtmGetErrorStatus(RT_MDL) != NULL) {
        return;
    }

    /* Save FPU context here (if necessary) */
    /* Re-enable interrupts here */
    /* Set model inputs here */

    /******************/
    /* Step the model */
    /******************/
    MODEL_STEP(0); /* tid index is always zero for singletasking */

    /* Get model outputs here */

    /************************************************************************
     * Model step complete for base sample time, now it is okay to          *
     * re-interrupt this ISR.                                               *
     ************************************************************************/            
    OverrunFlags[0]--;

    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Re-enable interrupts here */

    return;
} /* rtOneStep */

#elif DISC_NUMST > 1 && defined(MULTITASKING) /* multirate - multitask */

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 *
 *   Note that error checking is only neccessary when this routine is
 *   attached to an interrupt.
 *
 *   Also, you may wish to unroll any or all of for and while loops to
 *   improve the real-time performace of this function.
 */
void rt_OneStep(void)
{
    int_T i;

    /* Disable interrupts here */

    /***********************************************
     * Check and see if base step time is too fast *
     ***********************************************/
    if (OverrunFlags[0]++) {
        rtmSetErrorStatus(RT_MDL, "Overrun");
    }

    /*************************************************
     * Check and see if an error status has been set *
     * by an overrun or by the generated code.       *
     *************************************************/
    if (rtmGetErrorStatus(RT_MDL) != NULL) {
        return;
    }

    /* Save FPU context here (if necessary) */
    /* Re-enable interrupts here */
    
    /*************************************************
     * Update EventFalgs and check subrate overrun   *
     *************************************************/
    for (i = FIRST_TID+1; i < NUMST; i++) {
        if (rtmStepTask(RT_MDL,i) && eventFlags[i]++) {
            OverrunFlags[0]--;
            OverrunFlags[i]++;
            /* Sampling too fast */
            rtmSetErrorStatus(RT_MDL, "Overrun");
            return;
        }
        if (++rtmTaskCounter(RT_MDL,i) == rtmCounterLimit(RT_MDL,i))
            rtmTaskCounter(RT_MDL, i) = 0;
    }

    /* Set model inputs associated with base rate here */

    /*******************************************
     * Step the model for the base sample time *
     *******************************************/
    MODEL_STEP(0);

    /* Get model outputs associated with base rate here */

    /************************************************************************
     * Model step complete for base sample time, now it is okay to          *
     * re-interrupt this ISR.                                               *
     ************************************************************************/
    OverrunFlags[0]--;

    /*********************************************************
     * Step the model for any other sample times (sub-rates) *
     *********************************************************/
    for (i = FIRST_TID+1; i < NUMST; i++) {
        /*************************************************************
         * If task "i" is running, don't run any lower priority task *
         *************************************************************/
        if (OverrunFlags[i]) return; 

        if (eventFlags[i]) {
            OverrunFlags[i]++;

            /* Set model inputs associated with subrate here */

            /******************************************
             * Step the model for for sample time "i" *
             ******************************************/
            MODEL_STEP(i);

            /* Get model outputs associated with subrate here */
            
            /**********************************************
             * Indicate task complete for sample time "i" *
             **********************************************/
            OverrunFlags[i]--;
            eventFlags[i]--;
        }
    }

    /* Disable interrupts here */
    /* Restore FPU context here (if necessary) */
    /* Enable interrupts here */

    return;
} /* rtOneStep */

#else /* illegal state : single rate - multitask */
# error "A single rate model can't have multiple tasks" 
#endif 

/* Function: rt_InitModel ====================================================
 * 
 * Abstract: 
 *   Initialized the model and the overrun-flags
 *
 */
void rt_InitModel(void)
{
#if defined(MULTITASKING)
    int i;
    for(i=0; i < NUMST; i++) {
        OverrunFlags[i] = 0;
        eventFlags[i] = 0;
    }
#else
    OverrunFlags[0] = 0;
    eventFlags[0] = 0;
#endif

    /************************
     * Initialize the model *
     ************************/
#if defined(INCLUDE_FIRST_TIME_ARG) && INCLUDE_FIRST_TIME_ARG==0
    MODEL_INITIALIZE();
#else
    MODEL_INITIALIZE(1);
#endif
}

/* Function: rt_TermModel ====================================================
 * 
 * Abstract:
 *   Terminates the model an prints the error-status
 *
 */
int_T rt_TermModel(void)
{
    MODEL_TERMINATE();
    
    {
        const char_T *errStatus = rtmGetErrorStatus(RT_MDL);
        int_T i;
        
        if (errStatus != NULL && strcmp(errStatus, "Simulation finished")) {
            (void)printf("%s\n", rtmGetErrorStatus(RT_MDL));
            for (i = 0; i < NUMST; i++) {
                if (OverrunFlags[i]) {
                    (void)printf("ISR overrun - sampling rate too"
                                 "fast for sample time index %d.\n", i);
                }
            }
            return(1);
        }
    }
    
    return(0);
}

/* Function: main =============================================================
 *
 * Abstract:
 *   Execute model on a generic target such as a workstation.
 */
int_T main(int_T argc, const char_T *argv[])
{
    UNUSED_PARAMETER(argc);
    UNUSED_PARAMETER(argv);

    /*******************************************
     * warn if the model will run indefinitely *
     *******************************************/
#if MAT_FILE==0 && !defined(NO_MAT_FILE)
    printf("warning: the simulation will run with no stop time; "
           "to change this behavior select the 'MAT-file logging' option\n");
    fflush(NULL);
#endif

    /************************
     * initialize the model *
     ************************/
    rt_InitModel();

    /***********************************************************************
     * Execute (step) the model.  You may also attach rtOneStep to an ISR, *
     * in which case replace the call to rtOneStep with a call to a        *
     * background task.  Note that the generated code sets error status    *
     * to "Simulation finished" when MatFileLogging is specified in TLC.   *
     ***********************************************************************/
    while (rtmGetErrorStatus(RT_MDL) == NULL &&
           !rtmGetStopRequested(RT_MDL)) {
        rt_OneStep();
    }

    /*******************************
     * Cleanup and exit (optional) *
     *******************************/
    return rt_TermModel();
}

/* [EOF] ert_main.c */
