/*
 *  viphough_rt.h
 *
 *  Copyright 1995-2004 The MathWorks, Inc.
 *  $Revision: 1.1.12.3 $ $Date: 2009/11/16 22:38:41 $
 */

#ifndef viphough_rt_h
#define viphough_rt_h

#include "dsp_rt.h"

#ifdef VIPHOUGH_EXPORTS
#define VIPHOUGH_EXPORT EXPORT_FCN
#else
#define VIPHOUGH_EXPORT MWSP_IDECL
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
 * MWVIP_Hough_I<DataType> 
 * 
 *    1) MWVIP_ is a prefix used with all Mathworks DSP runtime library 
 *       functions. 
 *    2) The second field indicates that this function is implementing the 
 *       Hough Transform
 *    4) The last field enumerates the data type of the output ports
 * 
 *    Examples: 
 *       MWVIP_Hough_D is the Hough Transform for double precision outputs. 
 */ 

/* datatype double */
#ifdef __cplusplus
extern "C" {
#endif

VIPHOUGH_EXPORT void MWVIP_Hough_D(
                                const boolean_T  *uBW,
                                real_T           *yH,
                                const real_T     *sineTablePtr, 
                                const real_T     *rho,
                                int_T inRows,
                                int_T inCols,
                                int_T rhoLen,
                                int_T Ceil90ByThResPlus1
                                );

VIPHOUGH_EXPORT void MWVIP_Hough_R(
                                    const boolean_T  *uBW,
                                    real32_T           *yH,
                                    const real32_T     *sineTablePtr, 
                                    const real32_T     *rho,
                                    int_T inRows,
                                    int_T inCols,
                                    int_T rhoLen,
                                    int_T Ceil90ByThResPlus1
                                   );


#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* viphough_rt_h */

/* [EOF] viphough_rt.h */
