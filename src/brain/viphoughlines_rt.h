/*
 *  viphoughlines_rt.h
 *
 *  Copyright 1995-2005 The MathWorks, Inc.
 *  $Revision: 1.1.6.3 $ $Date: 2005/06/30 17:39:55 $
 */

#ifndef viphoughlines_rt_h
#define viphoughlines_rt_h

#include "dsp_rt.h"

#ifdef VIPHOUGHLINES_EXPORTS
#define VIPHOUGHLINES_EXPORT EXPORT_FCN
#else
#define VIPHOUGHLINES_EXPORT MWDSP_IDECL
#endif


/* 
 * Function naming glossary 
 * --------------------------- 
 * 
 * MWVIP = MathWorks VIP Blockset 
 * 
 * Data types - (describe inputs to functions, not outputs) 
 * R = real single-precision 
 * D = real double-precision 
 */ 
 
/* Function naming convention 
 * -------------------------- 
 * 
 * MWVIP_HoughLines_I<DataType> 
 * 
 *    1) MWVIP_ is a prefix used with all Mathworks DSP runtime library 
 *       functions. 
 *    2) The second field indicates that this function is implementing the 
 *       HoughLines Transform
 *    4) The last field enumerates the data type of the output ports
 * 
 *    Examples: 
 *       MWVIP_HoughLines_D is the HoughLines Transform for double precision outputs. 
 */ 

/* datatype double */
#ifdef __cplusplus
extern "C" {
#endif

VIPHOUGHLINES_EXPORT void MWVIP_HoughLines_D(const real_T *uTheta, 
                                             const real_T *uRho, 
                                                  int32_T *outRC,
                                                    int_T  NumRhoOrTheta,
                                                    int_T  RowsIn,
                                                    int_T  ColsIn);

VIPHOUGHLINES_EXPORT void MWVIP_HoughLines_R(const real32_T *uTheta, 
                                            const real32_T *uRho, 
                                                   int32_T *outRC,
                                                     int_T  NumRhoOrTheta,
                                                     int_T  RowsIn,
                                                     int_T  ColsIn);

VIPHOUGHLINES_EXPORT void MWVIP_HoughLines_DO(const real_T *uTheta, 
                                             const real_T *uRho, 
                                                   real_T *outRC,
                                                    int_T  NumRhoOrTheta,
                                                    int_T  RowsIn,
                                                    int_T  ColsIn);

VIPHOUGHLINES_EXPORT void MWVIP_HoughLines_RO(const real32_T *uTheta, 
                                            const real32_T *uRho, 
                                                  real32_T *outRC,
                                                     int_T  NumRhoOrTheta,
                                                     int_T  RowsIn,
                                                     int_T  ColsIn);

#ifdef MWDSP_INLINE_DSPRTLIB
#include "viphoughlines/houghlines_d_rt.c"
#include "viphoughlines/houghlines_r_rt.c"
#include "viphoughlines/houghlines_do_rt.c"
#include "viphoughlines/houghlines_ro_rt.c"
#endif

#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* viphoughlines_rt_h */

/* [EOF] viphoughlines_rt.h */
