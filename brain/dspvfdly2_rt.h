/*
 *  DSPVFDLY2_RT Runtime helper functions for DSP Blockset Vaiable Fractional Delay block.
 *
 *  Copyright 1995-2005 The MathWorks, Inc.
 *  $Revision: 1.3.4.6 $ $Date: 2005/12/22 18:02:54 $
 */

#ifndef dspvfdly2_rt_h
#define dspvfdly2_rt_h

#include "dsp_rt.h"

#ifdef DSPVFDLY_EXPORTS
#define DSPVFDLY_EXPORT EXPORT_FCN
#else
#define DSPVFDLY_EXPORT extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * List of individual interpolation functions:-
 */
/*
 * Function naming glossary
 * ---------------------------
 *
 * MWDSP = MathWorks DSP Blockset
 *
 * Data types - (describe inputs to functions, not outputs)
 * R = real single-precision
 * C = complex single-precision
 * D = real double-precision
 * Z = complex double-precision
 */

/* Function naming convention
 * --------------------------
 *
 *    1) MWDSP_Vfdly is the common prefix for the set of functions
 *       used by the variable fractional delay algorithm.
 *    2) The next field indicates the method used for fractional delay,
 *       two possible options are:
 *       Lin - Linear interpolation method is used for fractional delay.
 *       FIR - FIR interpolation mehtod is used for fractional delay.
 *    3) The last field enumerates the data type from the above list.
 *       Single/double precision and complexity are denoted by a single letter.
 *       The data types of the input and output are the same.
 *
 *    Examples:
 *       MWDSP_Vfdly_Lin_D is the Variable Fractional delay run time function
 *       using linear interpolation for double precision inputs.
 */
DSPVFDLY_EXPORT void MWDSP_Vfdly_Lin_D(const real_T * const buffptr,
                                       const int_T          buflen,
                                       real_T             **yptr,
                                       int_T                ti,
                                       const int_T          buffstart,
                                       const real_T         frac);

DSPVFDLY_EXPORT void MWDSP_Vfdly_Lin_R(const real32_T * const buffptr,
                                       const int_T            buflen,
                                       real32_T             **yptr,
                                       int_T                  ti,
                                       const int_T            buffstart,
                                       const real32_T         frac);

DSPVFDLY_EXPORT void MWDSP_Vfdly_FIR_D(const real_T * const filtptr,
                                       const int_T          filtlen,
                                       const int_T          nphases,
                                       const real_T * const buffptr,
                                       const int_T          buflen,
                                       real_T             **yptr,
                                       int_T                ti,
                                       const int_T          buffstart,
                                       const real_T         frac);

DSPVFDLY_EXPORT void MWDSP_Vfdly_FIR_R(const real32_T * const filtptr,
                                       const int_T            filtlen,
                                       const int_T            nphases,
                                       const real32_T * const buffptr,
                                       const int_T            buflen,
                                       real32_T             **yptr,
                                       int_T                  ti,
                                       const int_T            buffstart,
                                       const real32_T         frac);

#ifdef CREAL_T
DSPVFDLY_EXPORT void MWDSP_Vfdly_Lin_Z(const creal_T * const buffptr,
                                       const int_T           buflen,
                                       creal_T             **yptr,
                                       int_T                 ti,
                                       const int_T           buffstart,
                                       const real_T          frac);
#endif /* CREAL_T */
#ifdef CREAL_T
DSPVFDLY_EXPORT void MWDSP_Vfdly_Lin_C(const creal32_T * const buffptr,
                                       const int_T             buflen,
                                       creal32_T             **yptr,
                                       int_T                   ti,
                                       const int_T             buffstart,
                                       const real32_T          frac);
#endif /* CREAL_T */
#ifdef CREAL_T
DSPVFDLY_EXPORT void MWDSP_Vfdly_FIR_Z(const real_T * const  filtptr,
                                       const int_T           filtlen,
                                       const int_T           nphases,
                                       const creal_T * const buffptr,
                                       const int_T           buflen,
                                       creal_T             **yptr,
                                       int_T                 ti,
                                       const int_T           buffstart,
                                       const real_T          frac);
#endif /* CREAL_T */
#ifdef CREAL_T
DSPVFDLY_EXPORT void MWDSP_Vfdly_FIR_C(const real32_T * const  filtptr,
                                       const int_T             filtlen,
                                       const int_T             nphases,
                                       const creal32_T * const buffptr,
                                       const int_T             buflen,
                                       creal32_T             **yptr,
                                       int_T                   ti,
                                       const int_T             buffstart,
                                       const real32_T          frac);
#endif /* CREAL_T */

#ifdef __cplusplus
}
#endif

#endif /* dspvfdly2_rt_h */
