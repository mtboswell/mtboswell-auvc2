/*
 *  vipprojective_rt.h
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.8.7 $ $Date: 2009/11/16 22:38:44 $
 */

#ifndef vipprojective_rt_h  
#define vipprojective_rt_h

#include "dsp_rt.h"
#include "vipprojective.h"

#ifdef VIPPROJECTIVE_EXPORTS
#define VIPPROJECTIVE_EXPORT EXPORT_FCN
#else
#define VIPPROJECTIVE_EXPORT MWSP_IDECL
#endif

#define NUM_QUAD_VERTICES   8
#define NUM_RECT_VERTICES    4
#define TRANSFORM_MATRIX_ELEMENTS 9

typedef enum {
    RECTANGLE_T0_QUAD = 1,
    QUAD_TO_RECTANGLE,
	QUAD_TO_QUAD
} MODE ;

typedef enum {
	NEAREST_NBOR = 1,
	BILINEAR,
	BICUBIC
} INTERPMETHOD;

#ifdef __cplusplus
extern "C" {
#endif


/* Double precision */
/* Check if 3 points are collinear from 4 points. */
VIPPROJECTIVE_EXPORT boolean_T MWVIP_Are3PtsCollinear(int32_T *pts);

/* Calculate transformation matrix for rectangle to quadrilateral
 * conversion. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_CalculateXformMtrx_D(int_T *outPts,
                     int_T *rectPts,int_T rectRows, int_T rectCols,MODE mode,
                     int_T numSubDivs,boolean_T isInRectSizeUserDef,
                     real_T *Aptr);

/* Using inverse mapping, compute input image co-ordinates based on 
 * inverse transformation matrix and given output image co-ordinates. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_GetInPtsFrmOutPts_D(int_T r, int_T c,
                     real_T *A,real_T *u, real_T *v, real_T *w);

/* Perform nearest neighbor interpolation on a point [u,v] which is 
 * not integer-valued in an image I. 
 */
VIPPROJECTIVE_EXPORT  void MWVIP_NN_Interp_D(real_T *I, real_T u, real_T v,
                      int_T nRowsIn, real_T *y, int_T outIdx, 
                      int_T nChans, int_T inChanWidth, int_T outChanWidth);


/* Perform bilinear interpolation on a point [u,v] which is 
 * not integer-valued in an image I. Only handles non-negative
 * u and v values. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_PosVal_BL_Interp_D(real_T *I, real_T u,
                              real_T v, int_T rows,int_T cols,real_T *y,
                              int_T outIdx, int_T nChans, int_T inChanWidth,
                              int_T outChanWidth);

/* Perform bicubic interpolation on a point [u,v] which is 
 * not integer-valued in an image I. Only handles non-negative
 * co-ordinate values. 
 */

VIPPROJECTIVE_EXPORT void MWVIP_PosVal_BC_Interp_D(real_T *I, real_T u, 
                              real_T v, int_T nRows,int_T nCols,real_T *y,
                              int_T outIdx, int_T nChans, int_T inChanWidth,
                              int_T outChanWidth);

/* Fill an RGB image with a constant value */
VIPPROJECTIVE_EXPORT void MWVIP_FillBackgroundValues_D(real_T *fillValPtr, 
                              real_T *yr,real_T *yg,real_T *yb,int_T nRowsOut, 
                              int_T nColsOut,boolean_T isInputRGB,
                              boolean_T isScalarFillVal, int_T nChans);

/* Compute transformation matrix for quadrilateral to quadrilateral 
 * conversion. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_CalculateQ2QXformMtrx_D(int_T *inPtsValid,
                     int_T nRowsIn, int_T nColsIn,
                     real_T *Af, int_T *outPts, boolean_T useSubdivision);


/* Divide input rectangle into subdivisions and convert each subdivision
 * into quadrilateral
 */
VIPPROJECTIVE_EXPORT void MWVIP_DivideRectXform_D(
            int32_T *allEdges, int_T *inRectPts,
            sort_item *sortItemArray, real_T *y, real_T *yg,real_T *yb,
            ViewPortStruct vp, int_T nRowsIn, boolean_T isInputRGB,real_T *A,
            real_T *inR,real_T *inG,real_T *inB,boolean_T isExactSoln,
            int_T nRowsOut, int_T nColsOut,int_T nColsIn,
            INTERPMETHOD interpMethod,int_T inStartRowIdx,int_T inStartColIdx,
            int_T numSubDivs,boolean_T isInRectSizeUserDef, int_T nChans);

/* Divide quadrilateral into subdivisions and transform each subdivision into
 * a quadrilateral/rectangle.
 */
VIPPROJECTIVE_EXPORT void MWVIP_DivideQuadXform_D(int32_T *allEdges,
        int32_T *inPts,sort_item *sortItemArray,
        real_T *y, real_T *yg,real_T *yb,ViewPortStruct vp, int_T nRowsIn, boolean_T isInputRGB,
        real_T *A, real_T *inR, real_T *inG,real_T *inB, boolean_T isExactSoln,
        int_T nRowsOut, int_T nColsOut,int_T nColsIn, INTERPMETHOD interpMethod, int_T numSubDivs,
        int_T nChans);

VIPPROJECTIVE_EXPORT void MWVIP_ProjComputeOutPixel_D(
            real_T *y,real_T *yg, real_T *yb,int_T icurr_col,ViewPortStruct vp,
            int_T r0, int_T r2,int_T nRowsIn, boolean_T isInputRGB,
            real_T *inR, real_T *inG, real_T *inB,
            real_T *A,int_T nColsIn,int_T nRowsOut,int_T nColsOut,
            INTERPMETHOD interpMethod,boolean_T isExactSoln,
            int_T inStartRowIdx, int_T inStartColIdx, int_T nChans);


/* Single precision */
/* Calculate transformation matrix for rectangle to quadrilateral
 * conversion. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_CalculateXformMtrx_R(int_T *outPts,
                     int_T *rectPts,int_T rectRows, int_T rectCols,MODE mode,
                     int_T numSubDivs,boolean_T isInRectSizeUserDef,
                     real32_T *Aptr);

/* Using inverse mapping, compute input image co-ordinates based on 
 * inverse transformation matrix and given output image co-ordinates. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_GetInPtsFrmOutPts_R(int_T r, int_T c,
                     real32_T *A,real32_T *u, real32_T *v, real32_T *w);

/* Perform nearest neighbor interpolation on a point [u,v] which is 
 * not integer-valued in an image I. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_NN_Interp_R(real32_T *I, real32_T u, real32_T v,
                              int_T nRowsIn, real32_T *y, int_T outIdx, int_T nChans,
                              int_T inChanWidth, int_T outChanWidth);

/* Perform bilinear interpolation on a point [u,v] which is 
 * not integer-valued in an image I. Only handles non-negative
 * u and v values. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_PosVal_BL_Interp_R(real32_T *I, real32_T u,
                              real32_T v, int_T rows,int_T cols, real32_T *y,
                              int_T outIdx, int_T nChans,int_T inChanWidth,
                              int_T outChanWidth);

/* Perform bicubic interpolation on a point [u,v] which is 
 * not integer-valued in an image I. Only handles non-negative
 * co-ordinate values. 
 */

VIPPROJECTIVE_EXPORT void MWVIP_PosVal_BC_Interp_R(real32_T *I, real32_T u, 
                              real32_T v, int_T nRows,int_T nCols, real32_T *y,
                              int_T outIdx, int_T nChans,int_T inChanWidth,
                              int_T outChanWidth);

/* Fill an RGB image with a constant value */
VIPPROJECTIVE_EXPORT void MWVIP_FillBackgroundValues_R(real32_T *fillValPtr, 
                              real32_T *yr,real32_T *yg,real32_T *yb,int_T nRowsOut, 
                              int_T nColsOut,boolean_T isInputRGB,
                              boolean_T isScalarFillVal, int_T nChans);

/* Compute transformation matrix for quadrilateral to quadrilateral 
 * conversion. 
 */
VIPPROJECTIVE_EXPORT void MWVIP_CalculateQ2QXformMtrx_R(int_T *inPtsValid,
                     int_T nRowsIn, int_T nColsIn,
                     real32_T *Af, int_T *outPts, boolean_T useSubdivision);


/* Divide input rectangle into subdivisions and convert each subdivision
 * into quadrilateral
 */
VIPPROJECTIVE_EXPORT void MWVIP_DivideRectXform_R(
            int32_T *allEdges, int_T *inRectPts,
            sort_item *sortItemArray, real32_T *y, real32_T *yg,real32_T *yb,
            ViewPortStruct vp, int_T nRowsIn, boolean_T isInputRGB,real32_T *A,
            real32_T *inR,real32_T *inG,real32_T *inB,boolean_T isExactSoln,
            int_T nRowsOut, int_T nColsOut,int_T nColsIn,
            INTERPMETHOD interpMethod,int_T inStartRowIdx,int_T inStartColIdx,
            int_T numSubDivs,boolean_T isInRectSizeUserDef, int_T nChans);

/* Divide quadrilateral into subdivisions and transform each subdivision into
 * a quadrilateral/rectangle.
 */
VIPPROJECTIVE_EXPORT void MWVIP_DivideQuadXform_R(int32_T *allEdges,
        int32_T *inPts,sort_item *sortItemArray,
        real32_T *y, real32_T *yg,real32_T *yb,ViewPortStruct vp, int_T nRowsIn, boolean_T isInputRGB,
        real32_T *A, real32_T *inR, real32_T *inG,real32_T *inB, boolean_T isExactSoln,
        int_T nRowsOut, int_T nColsOut,int_T nColsIn, INTERPMETHOD interpMethod,int_T numSubDivs, int_T nChans);

VIPPROJECTIVE_EXPORT void MWVIP_ProjComputeOutPixel_R(
            real32_T *y,real32_T *yg, real32_T *yb,int_T icurr_col,ViewPortStruct vp,
            int_T r0, int_T r2,int_T nRowsIn, boolean_T isInputRGB,
            real32_T *inR, real32_T *inG, real32_T *inB,
            real32_T *A,int_T nColsIn,int_T nRowsOut,int_T nColsOut,
            INTERPMETHOD interpMethod,boolean_T isExactSoln,
            int_T inStartRowIdx, int_T inStartColIdx, int_T nChans);

VIPPROJECTIVE_EXPORT void MWVIP_XformOneSubdivision_D(
                     int32_T *allEdges,int_T numPts,int32_T *outPts,
                     sort_item *sortItemArray,real_T *y,
                     real_T *yg,real_T *yb,ViewPortStruct vp, int_T nRowsIn,
                     boolean_T isInputRGB, 
                    real_T *A,real_T *inR,real_T *inG,real_T *inB,
                    boolean_T isExactSoln, int_T nRowsOut, int_T nColsOut,
                    int_T nColsIn,INTERPMETHOD interpMethod,int_T inStartRowIdx,
                    int_T inStartColIdx, int_T nChans);

VIPPROJECTIVE_EXPORT void MWVIP_XformOneSubdivision_R(
                     int32_T *allEdges,int_T numPts,int32_T *outPts,
                     sort_item *sortItemArray,real32_T *y,
                     real32_T *yg,real32_T *yb,ViewPortStruct vp, int_T nRowsIn,
                     boolean_T isInputRGB, 
                    real32_T *A,real32_T *inR,real32_T *inG,real32_T *inB,
                    boolean_T isExactSoln, int_T nRowsOut, int_T nColsOut,
                    int_T nColsIn,INTERPMETHOD interpMethod,int_T inStartRowIdx,
                    int_T inStartColIdx, int_T nChans);


#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* vipprojective_rt_h */

/* [EOF] vipprojective_rt.h */
