/*
 * File: drop_mech.h
 *
 * Real-Time Workshop code generated for Simulink model drop_mech.
 *
 * Model version                        : 1.5
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun  7 22:50:59 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun  7 22:50:59 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_drop_mech_h_
#define RTW_HEADER_drop_mech_h_
#ifndef drop_mech_COMMON_INCLUDES_
# define drop_mech_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* drop_mech_COMMON_INCLUDES_ */

#include "drop_mech_types.h"

/* Real-time Model Data Structure */
struct RT_MODEL_drop_mech {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_drop_mech rtm;
} rtMdlrefDWork_mr_drop_mech;

/* Model reference registration function */
extern void mr_drop_mech_initialize(const char_T **rt_errorStatus,
  RT_MODEL_drop_mech *const drop_mech_M);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : drop_mech
 */
#endif                                 /* RTW_HEADER_drop_mech_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
