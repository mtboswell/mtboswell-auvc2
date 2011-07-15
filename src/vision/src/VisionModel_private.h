/*
 * File: VisionModel_private.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.1389
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Fri Jul 15 10:08:40 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Fri Jul 15 10:08:41 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VisionModel_private_h_
#define RTW_HEADER_VisionModel_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
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

extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void VisionModel_validation_gate(rtB_validation_gate_VisionModel *localB,
  rtP_validation_gate_VisionModel *localP);
extern void VisionModel_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_VisionModel *localB);
extern void VisionM_ReferenceColorSelection(const real_T rtu_L[4800], const
  real_T rtu_a[4800], const real_T rtu_b[4800], real_T rtu_Dist_Thresh,
  rtB_ReferenceColorSelection_Vis *localB);
extern void VisionModel_LowPassFilter_f(const real_T rtu_I[19200],
  rtB_LowPassFilter_VisionModel_h *localB);
extern void VisionMod_TransformCoordinates3(real_T rtu_which_camera, real_T
  rtu_x_in, real_T rtu_y_in, real_T rtu_z_in, const real_T
  rtu_Camera_Dimensions[2], rtB_TransformCoordinates3_Visio *localB);
extern void VisionModel_IfActionSubsystem(const real_T rtu_R_in[19200], real_T
  rtu_which_camera, real_T rtu_x_in, real_T rtu_y_in, real_T rtu_z_in, const
  real_T rtu_Camera_Dimensions[2], rtB_IfActionSubsystem_VisionMod *localB,
  rtP_IfActionSubsystem_VisionMod *localP);

#endif                                 /* RTW_HEADER_VisionModel_private_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
