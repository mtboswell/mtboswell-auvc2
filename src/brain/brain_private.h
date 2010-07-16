/*
 * File: brain_private.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.658
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Fri Jul 16 12:40:52 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Fri Jul 16 12:40:53 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_private_h_
#define RTW_HEADER_brain_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

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

extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void brain_EmbeddedMATLABFunction1(rtB_EmbeddedMATLABFunction1_bra
  *localB);
extern void StateFlowFunctionsBuoysApp_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsBuoysApp *localDW);
extern void StateFlowFunctionsBuoysApproach(real_T rtu_B_Hue, real_T rtu_B_Sat,
  real_T rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T
  rtu_Ref_Colors[150], real_T rtu_Num_Colors, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsBuoysAppr *localB, rtDW_StateFlowFunctionsBuoysApp
  *localDW);
extern void StateFlowFunctionsBuoysFin_Init(rtDW_StateFlowFunctionsBuoysFin
  *localDW);
extern void StateFlowFunctionsBuoysFindBuoy(const real_T rtu_RGBin[57600], const
  real_T rtu_LabMatrix[19200], real_T rtu_num_colors,
  rtB_StateFlowFunctionsBuoysFind *localB, rtDW_StateFlowFunctionsBuoysFin
  *localDW);
extern void StateFlowFunctionsBuoysShowSegm(const real_T rtu_LabMatrix[19200],
  const real_T rtu_Ref_Colors[150], rtB_StateFlowFunctionsBuoysShow *localB);
extern void brain_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_brain *localB);
extern void StateFlowFunctionsBuoysIterativ(const real_T rtu_H[19200], const
  real_T rtu_S[19200], const real_T rtu_V[19200],
  rtB_StateFlowFunctionsBuoysIter *localB, rtDW_StateFlowFunctionsBuoysIte
  *localDW);
extern void StateFlowFunctionsBuoysF_e_Init(rtDW_StateFlowFunctionsBuoysF_e
  *localDW);
extern void StateFlowFunctionsBuoysFindBu_l(const real_T rtu_LabelMatrix[19200],
  real_T rtu_num_colors, const real_T rtu_ref_colors[150],
  rtB_StateFlowFunctionsBuoysFi_d *localB, rtDW_StateFlowFunctionsBuoysF_e
  *localDW);
extern void StateFlowFunctionsMaintain_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaintai_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaint_Disable(rtB_StateFlowFunctionsMaintainH
  *localB, rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsMaintainHeadi(real_T rtu_DesiredHeading1, real_T
  rtu_CurrentHeading1, real_T rtu_ForwardVelocity1, RT_MODEL_brain *const
  brain_M, rtB_StateFlowFunctionsMaintainH *localB,
  rtDW_StateFlowFunctionsMaintain *localDW);
extern void StateFlowFunctionsBuoys_b_Start(rtB_StateFlowFunctionsBuoysAp_b
  *localB);
extern void StateFlowFunctionsBuoysApproa_h(rtB_StateFlowFunctionsBuoysAp_b
  *localB);
extern void StateFlowFunctionsValidationGat(const real_T rtu_H[19200], const
  real_T rtu_S[19200], rtB_StateFlowFunctionsValidatio *localB,
  rtDW_StateFlowFunctionsValidati *localDW);
extern void StateFlowFunctionsFollowOn_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollowOn *localDW);
extern void StateFlowFunctionsFollowOnePath(real_T rtu_HeadingAlong,
  RT_MODEL_brain *const brain_M, rtB_StateFlowFunctionsFollowOne *localB,
  rtDW_StateFlowFunctionsFollowOn *localDW);
extern void StateFlowFunctionsFollow_h_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollow_g *localDW);
extern void StateFlowFunctionsFollowOnePa_i(const real_T rtu_BW[19200],
  RT_MODEL_brain *const brain_M, rtB_StateFlowFunctionsFollowO_k *localB,
  rtDW_StateFlowFunctionsFollow_g *localDW);
extern void StateFlowFunctionsJumpHedgeIndi(real_T rtu_B_Hue, real_T rtu_B_Sat,
  real_T rtu_B_Value, const real_T rtu_LabMatrix[19200], const real_T
  rtu_Ref_Colors[150], real_T rtu_Num_Colors, rtB_StateFlowFunctionsJumpHedge
  *localB);
extern void StateFlowFunctionsJumpHe_k_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsJumpHe_e *localDW);
extern void StateFlowFunctionsJumpH_a_Start(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsJumpHe_e *localDW);
extern void StateFlowFunctionsJumpHedgeCame(const real_T rtu_BW[19200], real_T
  rtu_ForwardVelocity, RT_MODEL_brain *const brain_M,
  rtB_StateFlowFunctionsJumpHed_b *localB, rtDW_StateFlowFunctionsJumpHe_e
  *localDW);
extern void StateFlowFunctionsJumpHedgeGetA(const real_T rtu_BW[19200],
  rtB_StateFlowFunctionsJumpHed_m *localB, rtDW_StateFlowFunctionsJumpHe_j
  *localDW);
extern void StateManagementRunningAutonomou(real_T rtu_State1,
  rtB_StateManagementRunningAuton *localB);
extern void StateFlowFunctionsFollow_i_Init(RT_MODEL_brain *const brain_M,
  rtDW_StateFlowFunctionsFollo_gn *localDW);
extern void StateFlowFunctionsFollowOnePa_e(const real_T rtu_BW[19200],
  RT_MODEL_brain *const brain_M, rtB_StateFlowFunctionsFollowO_f *localB,
  rtDW_StateFlowFunctionsFollo_gn *localDW);

#endif                                 /* RTW_HEADER_brain_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
