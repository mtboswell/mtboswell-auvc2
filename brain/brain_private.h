/*
 * File: brain_private.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.168
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Mon Feb  8 16:28:35 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Mon Feb  8 16:28:35 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_private_h_
#define RTW_HEADER_brain_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (MAX_uint8_T)
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#include "vipmdnfilter_rt.h"           /* Signal Processing Blockset run time support library */
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

void brain_FoundTrack(real_T *rtd_Image_c);
void brain_NoTrack(real_T *rtd_Image_c);
void brain_BigErrorS1_Disable(rtB_BigErrorS1_brain *localB);
void brain_BigErrorS1(real_T rtu_In1, rtB_BigErrorS1_brain *localB);
void brai_BigNegativeErrorS2_Disable(rtB_BigNegativeErrorS2_brain *localB);
void brain_BigNegativeErrorS2(real_T rtu_In1, rtB_BigNegativeErrorS2_brain
  *localB);
void brain_Chart_Init(void);
void brain_Chart_Start(void);
void brain_Chart(void);

#endif                                 /* RTW_HEADER_brain_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
