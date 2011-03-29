/*
 * File: MotionController_private.h
 *
 * Real-Time Workshop code generated for Simulink model MotionController.
 *
 * Model version                        : 1.78
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Fri Nov 12 17:24:40 2010
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Fri Nov 12 17:24:41 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotionController_private_h_
#define RTW_HEADER_MotionController_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void MotionCont_DownXController_Init(rtDW_DownXController_MotionCont
  *localDW);
extern void MotionCon_DownXController_Start(rtDW_DownXController_MotionCont
  *localDW);
extern void MotionC_DownXController_Disable(real_T *rty_Output,
  rtDW_DownXController_MotionCont *localDW);
extern void MotionControlle_DownXController(real_T rtu_0, real_T rtu_Measured,
  real_T rtu_Setpoint, real_T *rty_Output, rtDW_DownXController_MotionCont
  *localDW, real_T rtp_Kd, real_T rtp_Ki, real_T rtp_Kp);
extern void MotionCo_DownYawController_Init(rtDW_DownYawController_MotionCo
  *localDW);
extern void MotionC_DownYawController_Start(rtDW_DownYawController_MotionCo
  *localDW);
extern void Motio_DownYawController_Disable(real_T *rty_Output,
  rtDW_DownYawController_MotionCo *localDW);
extern void MotionControl_DownYawController(boolean_T rtu_0, real_T rtu_Measured,
  real_T rtu_Setpoint, real_T *rty_Output, rtDW_DownYawController_MotionCo
  *localDW, real_T rtp_Kd, real_T rtp_Ki, real_T rtp_Kp);

#endif                                 /* RTW_HEADER_MotionController_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
