/*
 * File: brain_private.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.349
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Apr 13 17:34:15 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Apr 13 17:34:16 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_private_h_
#define RTW_HEADER_brain_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (MAX_uint8_T)
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
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

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n);
int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
void MultiWordSignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[]);
void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n);
void RunningAutonomousFollowOnePathM(const real_T rtu_H1[19200], const real_T
  rtu_S1[19200], const real_T rtu_V1[19200], rtB_RunningAutonomousFollowOneP
  *localB);
void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra *localB);
void brain_MaintainHeading_Init(RT_MODEL_brain *rtm, rtDW_MaintainHeading_brain *
  localDW);
void brain_MaintainHeading_Start(RT_MODEL_brain *rtm, rtDW_MaintainHeading_brain
  *localDW);
void brain_MaintainHeading_Disable(rtB_MaintainHeading_brain *localB,
  rtDW_MaintainHeading_brain *localDW);
void brain_MaintainHeading(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *rtm,
  rtB_MaintainHeading_brain *localB, rtDW_MaintainHeading_brain *localDW,
  rtP_MaintainHeading_brain *localP);
void GetBrightestPixelPerColumnandRo(const real_T rtu_HSVImage[57600],
  rtB_GetBrightestPixelPerColumna *localB);
void RunningAutonomousFollowOnePathO(const real_T rtu_HSV1[57600],
  rtB_RunningAutonomousFollowOn_b *localB);
void brain_IsLinePresent(const real_T rtu_HoughTable[51660], const real_T
  rtu_ThetaValues[180], const real_T rtu_RhoValues[287], rtB_IsLinePresent_brain
  *localB);
void RunningAutonomousFollowOnePat_o(const boolean_T rtu_BWleft1[9600], const
  boolean_T rtu_BWright1[9600], real_T rtu_CurrentHeading1,
  rtB_RunningAutonomousFollowOn_o *localB);
void brain_MaintainDepth_Init(RT_MODEL_brain *rtm, rtDW_MaintainDepth_brain
  *localDW);
void brain_MaintainDepth(real32_T rtu_DesiredDepth1, real32_T rtu_CurrentDepth1,
  RT_MODEL_brain *rtm, rtB_MaintainDepth_brain *localB, rtDW_MaintainDepth_brain
  *localDW, rtP_MaintainDepth_brain *localP);
void RunningAutonomousFollowO_l_Init(RT_MODEL_brain *rtm,
  rtDW_RunningAutonomousFollowO_p *localDW);
void RunningAutonomousFollowOnePa_oc(const real_T rtu_H[19200], const real_T
  rtu_S[19200], RT_MODEL_brain *rtm, rtB_RunningAutonomousFollowO_bx *localB,
  rtDW_RunningAutonomousFollowO_p *localDW);
void brain_GetForwardVelocity(real_T rtu_State1, rtB_GetForwardVelocity_brain
  *localB, rtP_GetForwardVelocity_brain *localP);
void brain_Chart_Init(void);
void brain_Chart_Enable(void);
void brain_Chart_Start(void);
void brain_Chart_Disable(void);
void brain_Chart(void);

#endif                                 /* RTW_HEADER_brain_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
