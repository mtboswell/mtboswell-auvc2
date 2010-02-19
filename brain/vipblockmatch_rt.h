/*
 *  vipblockmatch_rt.h
 *
 *  Copyright 1995-2005 The MathWorks, Inc.
 *  $Revision: 1.1.10.2 $ $Date: 2005/12/22 19:12:23 $
 */

#ifndef vipblockmatch_rt_h
#define vipblockmatch_rt_h

#include "dsp_rt.h"

#ifdef VIPBLOCKMATCH_EXPORTS
#define VIPBLOCKMATCH_EXPORT EXPORT_FCN
#else
#define VIPBLOCKMATCH_EXPORT MWDSP_IDECL
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
 * MWVIP_BlockMatching_<SearchMethod>_<MatchingCriteria>_<DataType> 
 * 
 *    1) MWVIP_ is a prefix used with all Mathworks DSP runtime library 
 *       functions. 
 *    2) The second field indicates that this function is implementing the 
 *       Block Matching algorithm
 *    3) The third field indicates the searching method (exhaustive, 3-step etc)
 *    4) The fourth field indicates the matching criteria (MSE, MAD etc)
 *    4) The last field enumerates the data type of the output ports
 * 
 *    Examples: 
 *       MWVIP_BlockMatching_Full_MSE_D is the Block Matching function for double precision 
 *       inputs and it uses full (i.e. exhaustive) search method and MSE as searching criteria
 */ 

/* datatype double */
#ifdef __cplusplus
extern "C" {
#endif
/* double */
VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MSE_D(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                real_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);


VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MAD_D(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                real_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MSE_D(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                real_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MAD_D(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                real_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

/* single */
VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MSE_R(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                real32_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);


VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MAD_R(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                real32_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MSE_R(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                real32_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MAD_R(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                real32_T *yMVsqmag,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

/* double complex output */
VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MSE_Z(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                creal_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);


VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MAD_Z(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                creal_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MSE_Z(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                creal_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MAD_Z(
                                const real_T *uImgCurr,
                                const real_T *uImgPrev,
                                real_T *paddedImgC,
                                real_T *paddedImgP,
                                creal_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

/* single complex output */
VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MSE_C(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                creal32_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);


VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_Full_MAD_C(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                creal32_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MSE_C(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                creal32_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);

VIPBLOCKMATCH_EXPORT void MWVIP_BlockMatching_3Step_MAD_C(
                                const real32_T *uImgCurr,
                                const real32_T *uImgPrev,
                                real32_T *paddedImgC,
                                real32_T *paddedImgP,
                                creal32_T *yMVcplx,
                                int32_T *blockSize,
                                int32_T *overlapSize,
                                int32_T *maxDisplSize,
                                const int_T inRows,
                                const int_T inCols,
                                const int_T rowsPadImgC,
                                const int_T colsPadImgC,
                                const int_T rowsPadImgP,
                                const int_T colsPadImgP);


VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_Full_MSE_D(const real_T *blkCS, const real_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_Full_MAD_D(const real_T *blkCS, const real_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_3Step_MSE_D(const real_T *blkCS, const real_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_3Step_MAD_D(const real_T *blkCS, const real_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_Full_MSE_R(const real32_T *blkCS, const real32_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_Full_MAD_R(const real32_T *blkCS, const real32_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_3Step_MSE_R(const real32_T *blkCS, const real32_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

VIPBLOCKMATCH_EXPORT void MWVIP_SearchMethod_3Step_MAD_R(const real32_T *blkCS, const real32_T *blkPB,
                                             int_T rowsImgCS,   int_T rowsImgPB,  
                                             int_T blkCSWidthX, int_T blkCSHeightY,  
                                             int_T blkPBWidthX, int_T blkPBHeightY,  
                                             int_T *xIdx,         int_T *yIdx);

#ifdef MWDSP_INLINE_DSPRTLIB
//
#include "vipblockmatch/blockmatch_full_mse_d_rt.c" 
#include "vipblockmatch/blockmatch_full_mad_d_rt.c"
#include "vipblockmatch/blockmatch_3step_mse_d_rt.c" 
#include "vipblockmatch/blockmatch_3step_mad_d_rt.c"
#include "vipblockmatch/blockmatch_full_mse_r_rt.c" 
#include "vipblockmatch/blockmatch_full_mad_r_rt.c"
#include "vipblockmatch/blockmatch_3step_mse_r_rt.c" 
#include "vipblockmatch/blockmatch_3step_mad_r_rt.c"
#include "vipblockmatch/blockmatch_full_mse_z_rt.c" 
#include "vipblockmatch/blockmatch_full_mad_z_rt.c"
#include "vipblockmatch/blockmatch_3step_mse_z_rt.c" 
#include "vipblockmatch/blockmatch_3step_mad_z_rt.c"
#include "vipblockmatch/blockmatch_full_mse_c_rt.c" 
#include "vipblockmatch/blockmatch_full_mad_c_rt.c"
#include "vipblockmatch/blockmatch_3step_mse_c_rt.c" 
#include "vipblockmatch/blockmatch_3step_mad_c_rt.c"
//
#include "vipblockmatch/searchmethod_full_mse_d_rt.c"
#include "vipblockmatch/searchmethod_full_mad_d_rt.c"
#include "vipblockmatch/searchmethod_3step_mse_d_rt.c"
#include "vipblockmatch/searchmethod_3step_mad_d_rt.c"
#include "vipblockmatch/searchmethod_full_mse_r_rt.c"
#include "vipblockmatch/searchmethod_full_mad_r_rt.c"
#include "vipblockmatch/searchmethod_3step_mse_r_rt.c"
#include "vipblockmatch/searchmethod_3step_mad_r_rt.c"
//
#endif

#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* vipblockmatch_rt_h */

/* [EOF] vipblockmatch_rt.h */
