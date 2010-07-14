/*
 *  viprotate_rt.h
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.8.10 $ $Date: 2009/11/16 22:38:45 $
 */

#ifndef viprotate_rt_h
#define viprotate_rt_h

#include "dsp_rt.h"
#include "vipprojective_rt.h"  

#ifdef VIPROTATE_EXPORTS
#define VIPROTATE_EXPORT EXPORT_FCN
#else
#define VIPROTATE_EXPORT MWSP_IDECL
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
 * MWVIP_Skew_INTERPmethod_<DataType> 
 * 
 *    1) MWVIP_ is a prefix used with all Mathworks DSP runtime library 
 *       functions. 
 *    2) The second field indicates that this function is implementing the 
 *       Skewing operation on a matrix
 *    3) The third field indicates interpolation method: nearest neighbor,
 *       bilinear or bicubic (to be implemented)
 *    4) The last field enumerates the data type from the above list. 
 *       Single/double precision are specified within a single letter. 
 *       The data types of the input and output are the same. 
 * 
 *    Examples: 
 *       MWVIP_Skew_BLI_D is the Skewing run time function with bilinear
 *       interpolation for double precision inputs. 
 */ 
/* Description of the arguments taken by the following functions:-
 * src = pointer to the vector which needs to be skewed (offseted) 
 * len = length of vector pointed to by 'src' (input) pointer. 
 * nlen = length of vector where the resultant skewed vector will be placed
 * strt = offset for the input vector resulting in skewing. 
 * offsetSrc = increment step to move to the next data point of the input 'src' vector
 * offsetDst = increment step to move to the next data point of the skewed output vector
 * dst = pointer to the output produced as result of skewing (offseting) input vector 'src'
 * colStartIdx = starting index for the dst vector (if we dont't want to output the destination
 * vector right from the first sample, but from the colStartIdx'th sample)
 */

/* datatype double */
#ifdef __cplusplus
extern "C" {
#endif

 /* Function pointer pointing to appropriate skew function
 * Nearest neighbor, bilinear or bicubic. 
 */
typedef void (*SkewFcnD)(const real_T *src,const int_T len, const int_T nlen,
                    const real_T strt,const int_T offsetSrc,
                    const int_T offsetDst,real_T *dst,const int_T colStartIdx,
                    const real_T *fillValPtr);
typedef void (*SkewFcnR)(const real32_T *src,const int_T len, const int_T nlen,
                    const real32_T strt,const int_T offsetSrc,
                    const int_T offsetDst,real32_T *dst,const int_T colStartIdx,
                    const real32_T *fillValPtr);

VIPROTATE_EXPORT void MWVIP_Skew_NNI_D(const real_T *src,const int_T len, const int_T nlen, const real_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real_T *dst,
                                 const int_T colStartIdx, const real_T *fillValPtr);

/* datatype single */
VIPROTATE_EXPORT void MWVIP_Skew_NNI_R(const real32_T *src,const int_T len, const int_T nlen, const real32_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real32_T *dst,
                                 const int_T colStartIdx,const real32_T *fillValPtr );

VIPROTATE_EXPORT void MWVIP_Skew_BLI_D(const real_T *src,const int_T len, const int_T nlen, const real_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real_T *dst,
                                 const int_T colStartIdx, const real_T *fillValPtr);

/* datatype single */
VIPROTATE_EXPORT void MWVIP_Skew_BLI_R(const real32_T *src,const int_T len, const int_T nlen, const real32_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real32_T *dst,
                                 const int_T colStartIdx, const real32_T *fillValPtr);

VIPROTATE_EXPORT void MWVIP_Skew_BCI_D(const real_T *src,const int_T len, const int_T nlen, const real_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real_T *dst,
                                 const int_T colStartIdx,const real_T *fillValPtr);

/* datatype single */
VIPROTATE_EXPORT void MWVIP_Skew_BCI_R(const real32_T *src,const int_T len, const int_T nlen, const real32_T strt,
				 const int_T offsetSrc, const int_T offsetDst,real32_T *dst,
                                 const int_T colStartIdx, const real32_T *fillValPtr);

#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* viprotate_rt_h */

/* [EOF] viprotate_rt.h */
