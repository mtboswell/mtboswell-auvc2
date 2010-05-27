/*
 *  viprotate_rt.h
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.6.1 $ $Date: 2009/11/16 22:38:43 $
 */

#ifndef vipdrawshapes_rt_h
#define vipdrawshapes_rt_h

#include "lexicmp.h"
#ifdef VIPDRAWSHAPES_EXPORTS
#define VIPDRAWSHAPES_EXPORT EXPORT_FCN
#else
#define VIPDRAWSHAPES_EXPORT MWDSP_IDECL 
#endif

/* datatype double */
#ifdef __cplusplus
extern "C" {
#endif

/* Round value to nearest integer
 * following ROUND macro should be replaced with NEAREST
 * in future CGIR upgrade (ref. G430449)
 * #define NEAREST(inVal)   ((int_T)(floor(inVal+0.5)))
 */
#ifndef ROUND
#define ROUND(inVal)                                             \
    ((inVal < 0.0) ? ((int_T)(inVal-0.5)) : ((int_T)(inVal+0.5))) 
#endif

/* OutCode bit masks used for Cohen-Sutherland line clipping */
#define OC_CMIN (unsigned int)1
#define OC_CMAX (unsigned int)2
#define OC_RMIN (unsigned int)4
#define OC_RMAX (unsigned int)8

#define HALF_UINT8_RANGE  128
#define HALF_UINT16_RANGE 32768
#define HALF_UINT32_RANGE 2147483648


#ifndef ABSVALINT
#define ABSVALINT(a) ((a)<(0) ? (-a) : (a))
#endif

#define upscaleFactor     1024
#define upscaleFactorBits 10
#define NUM_TABLE_COLS    8
#define PIXEL_RESOLUTION  16
#define LINE_TABLE_SIZE   25

#define IS_IN_VIEWPORT(pt)                                               \
    (((pt.Row) <= vp.RMax) && ((pt.Col)<= vp.CMax) && ((pt.Row)>=vp.RMin) && ((pt.Col)>=vp.CMin))

#define PLOT_FLTPT_POINT_I(y,offset,I1,diff,nChans,chanWidth,chanIdx) \
    for (chanIdx = 0; chanIdx < nChans; chanIdx++) {    \
        y[offset] = *(I1+chanIdx) + y[offset]*(diff);   \
        offset += chanWidth;                            \
    }

#define PLOT_FLTPT_POINT_RGB(y,yg,yb,offset,I1,IG1,IB1,diff)  \
        y[offset] = I1  + y[offset]*(diff);                   \
        yg[offset] = IG1 + yg[offset]*(diff);                 \
        yb[offset] = IB1 + yb[offset]*(diff);                                      

#define PLOT_FIXPT_POINT_I(y,offset,I1,diff,nChans,chanWidth,chanIdx)  \
    for (chanIdx = 0; chanIdx < nChans; chanIdx++) {                        \
        y[offset] = *(I1+chanIdx) + (DTYPE)(((ACCUM)y[offset]*(diff))>>10); \
        offset += chanWidth;                                                \
    }

#define PLOT_FIXPT_POINT_RGB(y,yg,yb,offset,I1,IG1,IB1,diff)  \
        y[offset]  = I1  + (DTYPE)(((ACCUM)y[offset]*(diff))>>10);       \
        yg[offset] = IG1 + (DTYPE)(((ACCUM)yg[offset]*(diff))>>10);      \
        yb[offset] = IB1 + (DTYPE)(((ACCUM)yb[offset]*(diff))>>10);    

#define CHECK_AND_PLOT_POINT_RGB(plotPt,y,yg,yb,I1,IG1,IB1,diff)            \
    if (IS_IN_VIEWPORT(plotPt))  {                                          \
        int_T offset = plotPt.Row + plotPt.Col*nRowsIn;                     \
        PLOT_POINT(y,yg,yb,offset,I1,IG1,IB1,diff)                          \
    }

#define CHECK_AND_PLOT_POINT_I(plotPt,y,I1,diff,nChans,chanWidth)   \
    if (IS_IN_VIEWPORT(plotPt))  {                                            \
        int_T chanIdx;                                                      \
        int_T offset = plotPt.Row + plotPt.Col*nRowsIn;                     \
        PLOT_POINT(y,offset,I1,diff,nChans,chanWidth,chanIdx)               \
    }

#define PLOT_FLTPT_POINT_OPACITY_R(y,offset,I1,diff,factor)                \
        y[offset] = (I1 + y[offset]*(diff))*factor + y[offset]*(1-factor);    

#define PLOT_FLTPT_POINT_OPACITY_I(y,offset,I1,diff,factor,nChans,chanWidth,chanI) \
    for (chanI = 0; chanI < nChans; chanI++) {                                     \
        y[offset] = (I1[chanI] + y[offset]*(diff))*factor + y[offset]*(1-factor);  \
        offset   += chanWidth;                                                     \
    }

#define PLOT_FLTPT_POINT_OPACITY_RGB(y,yg,yb,offset,I1,IG1,IB1,diff,factor)  \
        PLOT_FLTPT_POINT_OPACITY_R(y,offset,I1,diff,factor)                  \
        PLOT_FLTPT_POINT_OPACITY_R(yg,offset,IG1,diff,factor)                \
        PLOT_FLTPT_POINT_OPACITY_R(yb,offset,IB1,diff,factor)

#define CHECK_AND_PLOT_POINT_OPACITY_FLTPT_I(plotPt,y,I1,diff,factor,nChans,chanWidth) \
    if IS_IN_VIEWPORT(plotPt)  {                                            \
        int_T offset = plotPt.Row + plotPt.Col*nRowsIn,chanI;               \
        PLOT_FLTPT_POINT_OPACITY_I(y,offset,I1,diff,factor,nChans,chanWidth,chanI) \
    }

#define CHECK_AND_PLOT_POINT_OPACITY_FLTPT_RGB(plotPt,y,yg,yb,I1,IG1,IB1,diff,factor)  \
    if IS_IN_VIEWPORT(plotPt)  {                                            \
        int_T offset = plotPt.Row + plotPt.Col*nRowsIn;                     \
        PLOT_FLTPT_POINT_OPACITY_RGB(y,yg,yb,offset,I1,IG1,IB1,diff,factor) \
    }


#define DRAW_VERTICAL_LINE_FLTPT_I(ptA,ptB,out,frameHeight,val,vp,factor,factor1,nChans,chanWidth)  \
    if (MWVIP_ClipLine(&ptA,&ptB, &vp)) {                                    \
        int_T iVL;                                                           \
        int_T offsetVL = ptB.Col*frameHeight+ptA.Row;                        \
        out += offsetVL;                                                     \
        for (iVL = ptA.Row; iVL <= ptB.Row; iVL++) {                         \
            int_T chanI,outIdx = 0;                                        \
            for (chanI=0; chanI<nChans; chanI++) {                           \
                out[outIdx] = out[outIdx]*(factor1) + *(val+chanI)*(factor);\
                outIdx += chanWidth;                                         \
            }                                                                \
            out++;                                                           \
        }                                                                    \
        out -= (offsetVL+(ptB.Row-ptA.Row+1));                               \
    }

#define DRAW_VERTICAL_LINE_FLTPT_RGB(ptA,ptB,outR,outG,outB,frameHeight,val,vp,factor,factor1)  \
    if (MWVIP_ClipLine(&ptA,&ptB, &vp)) {                                    \
        int_T iVL;                                                           \
        int_T offsetVL = ptB.Col*frameHeight + ptA.Row;                      \
        outR += offsetVL;                                                    \
        outG += offsetVL;                                                    \
        outB += offsetVL;                                                    \
        for (iVL = ptA.Row; iVL <= ptB.Row; iVL++) {                         \
            *outR = *outR*(factor1) + *val *(factor);                        \
            *outG = *outG*(factor1) + *(val+1)*(factor);                     \
            *outB = *outB*(factor1) + *(val+2)*(factor);                     \
            outR++;                                                          \
            outG++;                                                          \
            outB++;                                                          \
        }                                                                    \
        offsetVL += (ptB.Row-ptA.Row+1);                                     \
        outR -= offsetVL;outG -= offsetVL;outB -= offsetVL;                  \
    }

#define DRAW_VERTICAL_LINE_FIXPT_I(ptA,ptB,out,frameHeight,val,vp,factor,factor1,upscaleFactorBits,accum,DTYPE,nChans,chanWidth)  \
    if (MWVIP_ClipLine(&ptA,&ptB, &vp)) {                                    \
        int_T iVL;                                                           \
        int_T offsetVL = ptB.Col*frameHeight+ptA.Row;                        \
        out += offsetVL;                                                     \
        for (iVL = ptA.Row; iVL <= ptB.Row; iVL++) {                         \
            int_T chanI,outIdx = 0;                                        \
            for (chanI = 0; chanI < nChans; chanI++) {                       \
                accum  = out[outIdx]*(factor1);                              \
                accum += *(val+chanI)*(factor);                            \
                out[outIdx] = (DTYPE)(accum >> upscaleFactorBits);           \
                outIdx += chanWidth;                                         \
            }                                                                \
            out++;                                                           \
        }                                                                    \
        out -= (offsetVL+(ptB.Row-ptA.Row+1));                               \
    }

#define DRAW_VERTICAL_LINE_FIXPT_RGB(ptA,ptB,outR,outG,outB,frameHeight,val,vp,factor,factor1,upscaleFactorBits,accum,accum1,DTYPE)  \
    if (MWVIP_ClipLine(&ptA,&ptB, &vp)) {                                    \
        int_T iVL;                                                           \
        int_T offsetVL = ptB.Col*frameHeight+ptA.Row;                        \
        outR += offsetVL;                                                    \
        outG += offsetVL;                                                    \
        outB += offsetVL;                                                    \
        for (iVL = ptA.Row; iVL <= ptB.Row; iVL++) {                         \
            accum  = *outR*(factor1);                                        \
            accum1 = *val*(factor);                                          \
            accum += accum1;                                                 \
            *outR  = (DTYPE)(accum >> upscaleFactorBits);                           \
            accum  = *outG*(factor1);                                        \
            accum1 = *(val+1)*(factor);                                      \
            accum += accum1;                                                 \
            *outG  = (DTYPE)(accum >> upscaleFactorBits);                           \
            accum  = *outB*(factor1);                                        \
            accum1 = *(val+2)*(factor);                                      \
            accum += accum1;                                                 \
            *outB  = (DTYPE)(accum >> upscaleFactorBits);                           \
            outR++;outG++;outB++;                                            \
        }                                                                    \
        offsetVL += (ptB.Row-ptA.Row+1);                                     \
        outR -= offsetVL;outG -= offsetVL;outB -= offsetVL;                  \
    }

/* Viewport (framebuffer) limits */
typedef struct {
        int32_T RMin;
        int32_T RMax;
        int32_T CMin;
        int32_T CMax;
} ViewPortStruct;

/* Endpoint (row,col) structure */
typedef struct {
        int32_T Row;
        int32_T Col;
} PointStruct;

VIPDRAWSHAPES_EXPORT void MWVIP_Line_Bresenham(
        PointStruct ptA,
        PointStruct ptB,
        byte_T* frameBuffer,
        const int frameHeight,
        const byte_T *val,
        const int_T bpe,
        ViewPortStruct vp,
        const int_T nChans,
        const int_T chanWidth);

VIPDRAWSHAPES_EXPORT void MWVIP_Line_Bresenham_RGB(
        PointStruct ptA,
        PointStruct ptB,
        byte_T* frameBufferR,
    byte_T* frameBufferG,
        byte_T* frameBufferB,
        const int frameHeight,
        const byte_T* const val,
        const int_T bpe,
        ViewPortStruct vp);

VIPDRAWSHAPES_EXPORT void MWVIP_GetIntCoordinates(
        void  *roiPtr,
        int_T roiDType,
        int_T *intVal,
        int_T count,
        int_T lineNum);

VIPDRAWSHAPES_EXPORT int_T MWVIP_ClipLine(
        PointStruct* const ptA,
        PointStruct* const ptB,
        const ViewPortStruct* const vp);

VIPDRAWSHAPES_EXPORT void MWVIP_Circle_SymOctantPts (
      byte_T *frameBuffer,
      PointStruct Center,
      PointStruct pt,
      ViewPortStruct vp,
      const byte_T *val,
      const int_T bpe,
      const int_T frameHeight,
      const int_T nChans,
      const int_T chanWidth);

VIPDRAWSHAPES_EXPORT void MWVIP_Circle_SymOctantPts_RGB (
      byte_T *frameBufferR,
      byte_T *frameBufferG,
      byte_T *frameBufferB,
      PointStruct Center,
      PointStruct pt,
      ViewPortStruct vp,
      const byte_T* val,
      const int_T bpe,
      const int_T frameHeight);

VIPDRAWSHAPES_EXPORT void MWVIP_SortRows(
    void *allEdges,
    int_T numRows,
    int_T inputDType,
    sort_item *sortItemArray);

/* Create edges table, obtain vertical scanlines from the table
 * alongwith the starting and ending row index for each scanline
 * and call relevant function to calculate each pixel value. 
 */

#define PLOT_AAFILLEDPOLYGON_FLTPT_I(perpDist,table,tableIdx,y,factor,DTYPE,nChans,chanWidth) \
    if (perpDist <=0) {                                                             \
        int_T indxTbl = (int_T)(0.5 + (fabs(perpDist)*16)/1024), chanI,outIdx=0,indxTbl1;\
        if (indxTbl > 16) indxTbl = 16;                                             \
        indxTbl1 = indxTbl+33*tableIdx;                                             \
        for (chanI = 0; chanI < nChans; chanI++) {                                  \
            y[outIdx] = (DTYPE)(table[indxTbl1] + (y[outIdx])*table[indxTbl])*factor + ((y[outIdx])*(1-factor)); \
            outIdx   += chanWidth;indxTbl1 += 33;                                    \
        }                                                                           \
    } else {                                                                        \
        int_T indxTbl = (int_T)(0.5 + (fabs(perpDist)*16)/1024), chanI,outIdx=0,indxTbl1;\
        if (indxTbl > 15) indxTbl = 15;                                             \
        indxTbl1 = indxTbl + 33*tableIdx+17;                                                         \
        for (chanI = 0; chanI < nChans; chanI++) {                                  \
            y[outIdx] = (DTYPE)(table[indxTbl1] + (y[outIdx])*table[indxTbl+17])*factor + ((y[outIdx])*(1-factor)); \
            outIdx   += chanWidth;indxTbl1 += 33;                                    \
        }                                                                           \
    }

#define PLOT_AAFILLEDPOLYGON_FLTPT_RGB(perpDist,table,tableIdx,y,yg,yb,factor,DTYPE)\
    if (perpDist <=0) {                                                             \
        int_T indxTbl = (int_T)(0.5 + (fabs(perpDist)*16)/1024), indxTbl1;          \
        if (indxTbl > 16) indxTbl = 16;                                             \
        indxTbl1 = indxTbl+33*tableIdx;                                              \
        y = (DTYPE)(table[indxTbl1] + (y)*table[indxTbl])*factor + ((y)*(1-factor));    \
        yg = (DTYPE)(table[indxTbl1+33] + (yg)*table[indxTbl])*factor + ((yg)*(1-factor)); \
        yb = (DTYPE)(table[indxTbl1+66] + (yb)*table[indxTbl])*factor + ((yb)*(1-factor)); \
    } else {                                                                        \
        int_T indxTbl = (int_T)(0.5 + (fabs(perpDist)*16)/1024), indxTbl1;          \
        if (indxTbl > 15) indxTbl = 15;                                             \
        indxTbl1 = indxTbl+33*tableIdx+17;                                              \
        y = (DTYPE)(table[indxTbl1] + (y)*table[indxTbl+17])*factor + ((y)*(1-factor)); \
        yg = (DTYPE)(table[indxTbl1+33] + (yg)*table[indxTbl+17])*factor + ((yg)*(1-factor)); \
        yb = (DTYPE)(table[indxTbl1+66] + (yb)*table[indxTbl+17])*factor + ((yb)*(1-factor)); \
    }                                               

#define PLOT_AAFILLEDPOLYGON_FIXPT_I(perpDist,table,tableIdx,y,factor,DTYPE,nChans,chanWidth)\
    if (perpDist <=0) {                                                             \
        int32_T accumFillPolygon,chanI,outIdx = 0,indxTbl1;                         \
        int_T indxTbl = (abs(perpDist)*16)>>10;                                     \
        if (indxTbl > 16) indxTbl = 16;                                             \
        indxTbl1 = indxTbl+33*tableIdx;                                             \
        for (chanI = 0; chanI < nChans; chanI++) {                                  \
            accumFillPolygon = (y[outIdx])*table[indxTbl];                          \
            accumFillPolygon = table[indxTbl1] + (accumFillPolygon>>upscaleFactorBits);\
            accumFillPolygon *= factor;                                                  \
            accumFillPolygon >>= upscaleFactorBits;                                      \
            accumFillPolygon += (((y[outIdx])*(upscaleFactor-factor)) >> upscaleFactorBits);\
            y[outIdx]         = (DTYPE)accumFillPolygon;                            \
            outIdx   += chanWidth;indxTbl1 += 33;                                   \
        }                                                                           \
    } else {                                                                        \
        int32_T accumFillPolygon,chanI,outIdx = 0,indxTbl1;                         \
        int_T indxTbl = (abs(perpDist)*16)>>10;                                     \
        if (indxTbl > 15) indxTbl = 15;                                             \
        indxTbl1 = indxTbl+33*tableIdx+17;                                             \
        for (chanI = 0; chanI < nChans; chanI++) {                                  \
            accumFillPolygon = (y[outIdx])*table[indxTbl+17];                       \
            accumFillPolygon = table[indxTbl1] + (accumFillPolygon>>upscaleFactorBits);\
            accumFillPolygon *= factor;                                                 \
            accumFillPolygon >>= upscaleFactorBits;                                     \
            accumFillPolygon += (((y[outIdx])*(upscaleFactor-factor)) >> upscaleFactorBits); \
            y[outIdx]     = (DTYPE)accumFillPolygon;                                 \
            outIdx   += chanWidth;indxTbl1 += 33;                                    \
        }                                                                            \
    }      

#define PLOT_AAFILLEDPOLYGON_FIXPT_RGB(perpDist,table,tableIdx,y,yg,yb,factor,DTYPE)\
    int32_T accumFillPolygon;                                                       \
    if (perpDist <=0) {                                                             \
        int_T indxTbl = (abs(perpDist)*16)>>10,indxTbl1;                            \
        if (indxTbl > 16) indxTbl = 16;                                             \
        indxTbl1 = indxTbl+33*tableIdx;                                             \
        accumFillPolygon = (y)*table[indxTbl];                                       \
        accumFillPolygon = table[indxTbl1] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((y)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        y     = (DTYPE)accumFillPolygon;                                                  \
        accumFillPolygon = (yg)*table[indxTbl];                                       \
        accumFillPolygon = table[indxTbl1+33] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((yg)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        yg     = (DTYPE)accumFillPolygon;                                                  \
        accumFillPolygon = (yb)*table[indxTbl];                                       \
        accumFillPolygon = table[indxTbl1+66] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((yb)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        yb     = (DTYPE)accumFillPolygon;                                                  \
    } else {                                                                        \
        int_T indxTbl = (abs(perpDist)*16)>>10,indxTbl1;                            \
        if (indxTbl > 15) indxTbl = 15;                                             \
        indxTbl1 = indxTbl+33*tableIdx+17;                                             \
        accumFillPolygon = (y)*table[indxTbl+17];                                    \
        accumFillPolygon = table[indxTbl1] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((y)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        y     = (DTYPE)accumFillPolygon;                                                  \
        accumFillPolygon = (yg)*table[indxTbl+17];                                    \
        accumFillPolygon = table[indxTbl1+33] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((yg)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        yg     = (DTYPE)accumFillPolygon;                                                  \
        accumFillPolygon = (yb)*table[indxTbl+17];                                    \
        accumFillPolygon = table[indxTbl1+66] + (accumFillPolygon>>upscaleFactorBits);\
        accumFillPolygon *= factor;                                                 \
        accumFillPolygon >>= upscaleFactorBits;                                     \
        accumFillPolygon += (((yb)*(upscaleFactor-factor)) >> upscaleFactorBits);     \
        yb     = (DTYPE)accumFillPolygon;                                                  \
    } 


VIPDRAWSHAPES_EXPORT boolean_T MWVIP_DetectIfCornerPixel_FillPoly(int32_T *polygonPts, int_T numPtsPairs, int_T row, int_T col);


VIPDRAWSHAPES_EXPORT void MWVIP_CreateEdgesTable(int32_T *outPts,int_T numVertices,
                      int32_T *allEdges, int32_T *globalEdges,
                      sort_item *sortItemArray, int32_T *offset, boolean_T isAntiAliased);

VIPDRAWSHAPES_EXPORT void MWVIP_CreateEdgesTable_Int(int32_T *outPts,int_T numVertices,
                      int32_T *allEdges, int32_T *globalEdges,
                      sort_item *sortItemArray, int32_T *offset, boolean_T isAntiAliased);

VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_D(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real_T *y, real_T *yg,real_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    real_T *val,const real_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_R(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real32_T *y, real32_T *yg,real32_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    real32_T *val,const real32_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_UI8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint8_T *y, uint8_T *yg,uint8_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    uint8_T *val,const int16_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_I8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int8_T *y, int8_T *yg,int8_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    int8_T *val,const int16_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_UI16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint16_T *y, uint16_T *yg,uint16_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    uint16_T *val,const int16_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_I16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int16_T *y, int16_T *yg,int16_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    int16_T *val,const int16_T *opacityValPtr);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_RGB_Bool(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    boolean_T *y, boolean_T *yg,boolean_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    boolean_T *val,const int16_T *opacityValPtr);

VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_D(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real_T *y, ViewPortStruct vp, int_T nRowsIn,  
    real_T *val,const real_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_R(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real32_T *y, ViewPortStruct vp, int_T nRowsIn,  
    real32_T *val,const real32_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_UI8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint8_T *y, ViewPortStruct vp, int_T nRowsIn,  
    uint8_T *val,const int16_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_I8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int8_T *y, ViewPortStruct vp, int_T nRowsIn,  
    int8_T *val,const int16_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_UI16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint16_T *y, ViewPortStruct vp, int_T nRowsIn,  
    uint16_T *val,const int16_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_I16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int16_T *y, ViewPortStruct vp, int_T nRowsIn,  
    int16_T *val,const int16_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_I_Bool(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    boolean_T *y, ViewPortStruct vp, int_T nRowsIn,  
    boolean_T *val,const int16_T *opacityValPtr,
    const int_T nChans, const int_T chanWidth);


VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_D(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real_T *y, real_T *yg,real_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    real_T *val,const real_T *opacityValPtr,
    real_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_R(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real32_T *y, real32_T *yg,real32_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    real32_T *val,const real32_T *opacityValPtr,
    real32_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_UI8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint8_T *y, uint8_T *yg,uint8_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    uint8_T *val,const int16_T *opacityValPtr,
    int16_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_I8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int8_T *y, int8_T *yg,int8_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    int8_T *val,const int16_T *opacityValPtr,
    int16_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_UI16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint16_T *y, uint16_T *yg,uint16_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    uint16_T *val,const int16_T *opacityValPtr,
    uint16_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_RGB_I16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int16_T *y, int16_T *yg,int16_T *yb,ViewPortStruct vp, 
    int_T nRowsIn,  
    int16_T *val,const int16_T *opacityValPtr,
    int16_T *table,int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_D(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real_T *y, ViewPortStruct vp, int_T nRowsIn,  
    real_T *val,const real_T *opacityValPtr,real_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_R(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    real32_T *y, ViewPortStruct vp, int_T nRowsIn,  
    real32_T *val,const real32_T *opacityValPtr,real32_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_UI8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint8_T *y, ViewPortStruct vp, int_T nRowsIn,  
    uint8_T *val,const int16_T *opacityValPtr,int16_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_I8(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int8_T *y,ViewPortStruct vp, int_T nRowsIn,  
    int8_T *val,const int16_T *opacityValPtr,int16_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_UI16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    uint16_T *y, ViewPortStruct vp, int_T nRowsIn,  
    uint16_T *val,const int16_T *opacityValPtr,uint16_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillOnePolygon_AA_I_I16(
    int32_T *allEdges,int_T numPts,int32_T *outPts,
    sort_item *sortItemArray,
    int16_T *y, ViewPortStruct vp, int_T nRowsIn,  
    int16_T *val,const int16_T *opacityValPtr,int16_T *table,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);


VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_D(real_T *out,real_T *outG,real_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real_T *val,const real_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_R(real32_T *out,real32_T *outG,real32_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real32_T *val,const real32_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_UI8(uint8_T *out,uint8_T *outG,uint8_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint8_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_I8(int8_T *out,int8_T *outG,int8_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int8_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_UI16(uint16_T *out,uint16_T *outG,uint16_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint16_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_I16(int16_T *out,int16_T *outG,int16_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int16_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_RGB_Bool(boolean_T *out,boolean_T *outG,boolean_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    boolean_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset);

VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_D(real_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real_T *val,const real_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_R(real32_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real32_T *val,const real32_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_UI8(uint8_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint8_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_I8(int8_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int8_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_UI16(uint16_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint16_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_I16(int16_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int16_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_I_Bool(boolean_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    boolean_T *val,const int16_T *opacityValPtr,const int_T row2ElemOffset,
    const int_T nChans, const int_T chanWidth);


VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_D
(real_T *out,
 real_T *outG,
 real_T *outB,
 const int_T icurr_col,
 ViewPortStruct vp,
 const int_T nRowsIn,
 const int_T sizeActiveET,
 const int32_T *allEdges,
 real_T *val,
 const real_T *opacityValPtr, /* 10th arg */
 const int32_T *offset,
 real_T *table,
 int_T tableIdx, 
 int32_T *polygonPts,
 int_T numPtsPairs, 
 boolean_T start);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_R(real32_T *out,real32_T *outG,real32_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real32_T *val,const real32_T *opacityValPtr,
     const int32_T *offset, real32_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_UI8(uint8_T *out,uint8_T *outG,uint8_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint8_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_I8(int8_T *out,int8_T *outG,int8_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int8_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_UI16(uint16_T *out,uint16_T *outG,uint16_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint16_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, uint16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_RGB_I16(int16_T *out,int16_T *outG,int16_T *outB,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int16_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start);

VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_D(real_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real_T *val,const real_T *opacityValPtr,
     const int32_T *offset, real_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_R(real32_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    real32_T *val,const real32_T *opacityValPtr,
     const int32_T *offset, real32_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_UI8(uint8_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint8_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_I8(int8_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int8_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_UI16(uint16_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    uint16_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, uint16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillVerticalScanLine_AA_I_I16(int16_T *out,
    const int_T icurr_col,ViewPortStruct vp,const int_T nRowsIn,
    const int_T sizeActiveET,const int32_T *allEdges,
    int16_T *val,const int16_T *opacityValPtr,
     const int32_T *offset, int16_T *table,int_T tableIdx,
    int32_T *polygonPts, int_T numPtsPairs, boolean_T start,
    const int_T nChans, const int_T chanWidth);

VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFlt_RGB_D(
                real_T *y, real_T *val, int_T outIndx, const real_T *opacityValPtr,
                real_T *yg, real_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFlt_RGB_R(
                real32_T *y, real32_T *val, int_T outIndx, const real32_T *opacityValPtr,
                real32_T *yg, real32_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_RGB_I8(
                int8_T *y, int8_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int8_T *yg, int8_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_RGB_UI8(
                uint8_T *y, uint8_T *val, int_T outIndx, const int16_T *opacityValPtr,
                uint8_T *yg, uint8_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_RGB_I16(
                int16_T *y, int16_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int16_T *yg, int16_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_RGB_UI16(
                uint16_T *y, uint16_T *val, int_T outIndx, const int16_T *opacityValPtr,
                uint16_T *yg, uint16_T *yb, 
                int_T startLoop, int_T endLoop);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_RGB_Bool(
                boolean_T *y, boolean_T *val, int_T outIndx, const int16_T *opacityValPtr,
                boolean_T *yg, boolean_T *yb, 
                int_T startLoop, int_T endLoop);

VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFlt_I_D(
                real_T *y, real_T *val, int_T outIndx, const real_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFlt_I_R(
                real32_T *y, real32_T *val, int_T outIndx, const real32_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_I_I8(
                int8_T *y, int8_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_I_UI8(
                uint8_T *y, uint8_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_I_I16(
                int16_T *y, int16_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_I_UI16(
                uint16_T *y, uint16_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_FillPolygon_InterpFix_I_Bool(
                boolean_T *y, boolean_T *val, int_T outIndx, const int16_T *opacityValPtr,
                int_T startLoop, int_T endLoop, const int_T nChans,
                const int_T chanWidth);

/* Drawing anti-aliased circles */
VIPDRAWSHAPES_EXPORT int32_T MWVIP_DrawAACircle_Delta(PointStruct pt,
                 int_T radius, int16_T *table, boolean_T *otherPtIsDown);

VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_D(real_T  *y,real_T  *yg,
                 real_T  *yb,real_T  *val,PointStruct pt,PointStruct Center,
                 ViewPortStruct vp,const int_T nRowsIn,const int_T radius);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_R(real32_T  *y,real32_T  *yg,
                 real32_T  *yb,real32_T  *val,PointStruct pt,PointStruct Center,
                 ViewPortStruct vp,const int_T nRowsIn,const int_T radius);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_I8(int8_T  *y,int8_T  *yg,
                int8_T  *yb,int8_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_UI8(uint8_T  *y,uint8_T  *yg,
                uint8_T  *yb,uint8_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_I16(int16_T  *y,int16_T  *yg,
                int16_T  *yb,int16_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_RGB_UI16(uint16_T  *y,uint16_T  *yg,
                uint16_T  *yb,uint16_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius);

VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_D(real_T  *y,
                 real_T  *val,PointStruct pt,PointStruct Center,
                 ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                 const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_R(real32_T  *y,
                 real32_T  *val,PointStruct pt,PointStruct Center,
                 ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                 const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_I8(int8_T  *y,
                int8_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_UI8(uint8_T  *y,
                uint8_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_I16(int16_T  *y,
                int16_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Circle_I_UI16(uint16_T  *y,
                uint16_T  *val,int16_T *cosToSinTable,
                PointStruct pt,PointStruct Center,ViewPortStruct vp,
                const int_T nRowsIn,const int_T radius,
                const int_T nChans, const int_T chanWidth);

/* Functions to plot 4 symmetric points in case of anti-aliased circle drawing. */
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_D(real_T *y,real_T *yg,
                real_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real_T I,real_T IG,real_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_R(real32_T *y,real32_T *yg,
                real32_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real32_T I,real32_T IG,real32_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_I8(int8_T *y,int8_T *yg,
                int8_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int8_T I,int8_T IG,int8_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_UI8(uint8_T *y,uint8_T *yg,
                uint8_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint8_T I,uint8_T IG,uint8_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_I16(int16_T *y,int16_T *yg,
                int16_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int16_T I,int16_T IG,int16_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_UI16(uint16_T *y,uint16_T *yg,
                uint16_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint16_T I,uint16_T IG,uint16_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_I32(int32_T *y,int32_T *yg,
                int32_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int32_T I,int32_T IG,int32_T IB);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsRGB_UI32(uint32_T *y,uint32_T *yg,
                uint32_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint32_T I,uint32_T IG,uint32_T IB);

VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_D(real_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_R(real32_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real32_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_I8(int8_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int8_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_UI8(uint8_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint8_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_I16(int16_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int16_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_UI16(uint16_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint16_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_I32(int32_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int32_T *I,const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymQuadPtsI_UI32(uint32_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint32_T *I,const int_T nChans, const int_T chanWidth);

/* Functions to plot 8 symmetric points in case of anti-aliased circle drawing. */
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_D(real_T *y,real_T *yg,
                real_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real_T I1,real_T I2,real_T IG1,real_T IG2,
                real_T IB1,real_T IB2,real_T diff,const boolean_T otherPtIsDown);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_R(real32_T *y,real32_T *yg,
                real32_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real32_T I1,real32_T I2,real32_T IG1,real32_T IG2,
                real32_T IB1,real32_T IB2,real32_T diff,const boolean_T otherPtIsDown);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_I8(int8_T *y,int8_T *yg,
                int8_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int8_T I1,int8_T I2,int8_T IG1,int8_T IG2,
                int8_T IB1,int8_T IB2,int32_T diffScaled,const boolean_T otherPtIsDown);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_UI8(uint8_T *y,uint8_T *yg,
                uint8_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint8_T I1,uint8_T I2,uint8_T IG1,uint8_T IG2,
                uint8_T IB1,uint8_T IB2,int32_T diffScaled,const boolean_T otherPtIsDown);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_I16(int16_T *y,int16_T *yg,
                int16_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int16_T I1,int16_T I2,int16_T IG1,int16_T IG2,
                int16_T IB1,int16_T IB2,int32_T diffScaled,const boolean_T otherPtIsDown);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsRGB_UI16(uint16_T *y,uint16_T *yg,
                uint16_T *yb,PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint16_T I1,uint16_T I2,uint16_T IG1,uint16_T IG2,
                uint16_T IB1,uint16_T IB2,int32_T diffScaled,const boolean_T otherPtIsDown);

VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_D(real_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real_T *I1,real_T *I2,
                real_T diff,const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_R(real32_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,real32_T *I1,real32_T *I2,
                real32_T diff,const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_I8(int8_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int8_T *I1,int8_T *I2,
                int32_T diffScaled,const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_UI8(uint8_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint8_T *I1,uint8_T *I2,
                int32_T diffScaled,const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_I16(int16_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,int16_T *I1,int16_T *I2,
                int32_T diffScaled,const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_SymOctantPtsI_UI16(uint16_T *y,
                PointStruct Center,PointStruct pt,ViewPortStruct vp,
                int_T nRowsIn,uint16_T *I1,uint16_T *I2,int32_T diffScaled,
                const boolean_T otherPtIsDown,
                const int_T nChans, const int_T chanWidth);

/* draw FILLED antialiased circle */
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_D(real_T  *y,real_T  *yg,
                real_T  *yb,real_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const real_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_D(real_T  *y,
                real_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const real_T *factor, const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_R(real32_T  *y,real32_T  *yg,
                real32_T  *yb,real32_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const real32_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_R(real32_T  *y,
                real32_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const real32_T *factor, const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_UI8(uint8_T  *y,uint8_T  *yg,
                uint8_T  *yb,uint8_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_UI8(uint8_T  *y,
                uint8_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_I8(int8_T  *y,int8_T  *yg,
                int8_T  *yb,int8_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_I8(int8_T  *y,
                int8_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_UI16(uint16_T  *y,uint16_T  *yg,
                uint16_T  *yb,uint16_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_UI16(uint16_T  *y,
                uint16_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable, 
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_RGB_I16(int16_T  *y,int16_T  *yg,
                int16_T  *yb,int16_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_FilledCircle_I_I16(int16_T  *y,
                int16_T  *val,PointStruct pt,PointStruct Center,
                ViewPortStruct vp,const int_T nRowsIn,const int_T radius,
                const int16_T *factor,int16_T *cosToSinTable, 
                const int_T nChans, const int_T chanWidth);

/* Function used by filledCircle runtime function, to plot 8 points and 2 lines */
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_D(real_T *y,real_T *yg,
                real_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real_T I1,real_T I2,
                real_T IG1,real_T IG2,real_T IB1,real_T IB2,
                real_T diff,const boolean_T otherPtIsDown,
                const real_T *val,const real_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_D(real_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real_T *I1,real_T *I2,                
                real_T diff,const boolean_T otherPtIsDown,
                const real_T *val,const real_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_R(real32_T *y,real32_T *yg,
                real32_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real32_T I1,real32_T I2,
                real32_T IG1,real32_T IG2,real32_T IB1,real32_T IB2,
                real32_T diff,const boolean_T otherPtIsDown,
                const real32_T *val,const real32_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_R(real32_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real32_T *I1,real32_T *I2,
                real32_T diff,const boolean_T otherPtIsDown,
                const real32_T *val,const real32_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_UI8(uint8_T *y,uint8_T *yg,
                uint8_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint8_T I1,uint8_T I2,
                uint8_T IG1,uint8_T IG2,uint8_T IB1,uint8_T IB2,
                int16_T diff,const boolean_T otherPtIsDown,
                const uint8_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_UI8(uint8_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint8_T *I1,uint8_T *I2,
                int16_T diff,const boolean_T otherPtIsDown,
                const uint8_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_I8(int8_T *y,int8_T *yg,
                int8_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int8_T I1,int8_T I2,
                int8_T IG1,int8_T IG2,int8_T IB1,int8_T IB2,
                int16_T diff,const boolean_T otherPtIsDown,
                const int8_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_I8(int8_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int8_T *I1,int8_T *I2,
                int16_T diff,const boolean_T otherPtIsDown,
                const int8_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_UI16(uint16_T *y,uint16_T *yg,
                uint16_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint16_T I1,uint16_T I2,
                uint16_T IG1,uint16_T IG2,uint16_T IB1,uint16_T IB2,
                int16_T diff,const boolean_T otherPtIsDown,
                const uint16_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_UI16(uint16_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint16_T *I1,uint16_T *I2,
                int16_T diff,const boolean_T otherPtIsDown,
                const uint16_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesRGB_I16(int16_T *y,int16_T *yg,
                int16_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int16_T I1,int16_T I2,
                int16_T IG1,int16_T IG2,int16_T IB1,int16_T IB2,
                int16_T diff,const boolean_T otherPtIsDown,
                const int16_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_8PtsLinesI_I16(int16_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int16_T *I1,int16_T *I2,
                int16_T diff,const boolean_T otherPtIsDown,
                const int16_T *val,const int16_T *factor,int_T  *startRow,
                int_T  *endRow,int_T  *col1,int_T  *col2, int_T *centerStartRow,
                const int_T nChans, const int_T chanWidth);



VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_D(real_T *y,real_T *yg,
                real_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real_T I,real_T IG,
                real_T IB,const real_T *val,
                const real_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_D(real_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real_T *I,
                const real_T *val,const real_T *factor,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_R(real32_T *y,real32_T *yg,
                real32_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real32_T I,real32_T IG,
                real32_T IB,const real32_T *val,
                const real32_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_R(real32_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,real32_T *I,
                const real32_T *val,const real32_T *factor,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_UI8(uint8_T *y,uint8_T *yg,
                uint8_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint8_T I,uint8_T IG,
                uint8_T IB,const uint8_T *val,const int16_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_UI8(uint8_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint8_T *I,
                const uint8_T *val,const int16_T *factor,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_I8(int8_T *y,int8_T *yg,
                int8_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int8_T I,int8_T IG,
                int8_T IB,const int8_T *val,const int16_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_I8(int8_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int8_T *I,
                const int8_T *val,const int16_T *factor,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_UI16(uint16_T *y,uint16_T *yg,
                uint16_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint16_T I,uint16_T IG,
                uint16_T IB,const uint16_T *val,const int16_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_UI16(uint16_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,uint16_T *I,
                const uint16_T *val,const int16_T *factor,
                const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesRGB_I16(int16_T *y,int16_T *yg,
                int16_T *yb,PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int16_T I,int16_T IG,
                int16_T IB,const int16_T *val,const int16_T *factor);
VIPDRAWSHAPES_EXPORT void MWVIP_AACircle_4PtsLinesI_I16(int16_T *y,
                PointStruct Center,PointStruct pt,
                ViewPortStruct vp,int_T nRowsIn,int16_T *I,
                const int16_T *val,const int16_T *factor,
                const int_T nChans, const int_T chanWidth);

/* draw antialiased lines */
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_D(
    PointStruct ptA,PointStruct ptB,real_T *out,const int frameHeight,
    ViewPortStruct vp, real_T *tableIntensity,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_R(
    PointStruct ptA,PointStruct ptB,real32_T *out,const int frameHeight,
    ViewPortStruct vp,real32_T *tableIntensity,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_D(
    PointStruct ptA,PointStruct ptB,real_T *out,real_T *outG,real_T *outB,
    const int frameHeight, ViewPortStruct vp, real_T *tableIntensity, int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_R(
    PointStruct ptA,PointStruct ptB,real32_T *out,real32_T *outG,real32_T *outB,
    const int frameHeight, ViewPortStruct vp,real32_T *tableIntensity, int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_UI8(
    PointStruct ptA,PointStruct ptB,uint8_T *out,const int frameHeight,
    ViewPortStruct vp, int16_T *tableIntensity,int_T tableIdx,
    const int_T nChans,const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_UI8(
    PointStruct ptA,PointStruct ptB,uint8_T *out,uint8_T *outG,uint8_T *outB,
    const int frameHeight, ViewPortStruct vp, int16_T *tableIntensity, int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_I8(
    PointStruct ptA,PointStruct ptB,int8_T *out,const int frameHeight,
    ViewPortStruct vp, int16_T *tableIntensity,int_T tableIdx,
    const int_T nChans,const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_UI16(
    PointStruct ptA,PointStruct ptB,uint16_T *out,const int frameHeight,
    ViewPortStruct vp, uint16_T *tableIntensity,int_T tableIdx,
    const int_T nChans,const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_I_I16(
    PointStruct ptA,PointStruct ptB,int16_T *out,const int frameHeight,
    ViewPortStruct vp, int16_T *tableIntensity,int_T tableIdx,
    const int_T nChans, const int_T chanWidth);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_I8(
    PointStruct ptA,PointStruct ptB,int8_T *out,int8_T *outG,int8_T *outB,
    const int frameHeight, ViewPortStruct vp, int16_T *tableIntensity, int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_UI16(
    PointStruct ptA,PointStruct ptB,uint16_T *out,uint16_T *outG,uint16_T *outB,
    const int frameHeight, ViewPortStruct vp, uint16_T *tableIntensity, int_T tableIdx);
VIPDRAWSHAPES_EXPORT void MWVIP_Draw_AA_Line_RGB_I16(
    PointStruct ptA,PointStruct ptB,int16_T *out,int16_T *outG,int16_T *outB,
    const int frameHeight, ViewPortStruct vp, int16_T *tableIntensity, int_T tableIdx);

VIPDRAWSHAPES_EXPORT void plot_aaFilledPolygon_Dbl_RGB(int_T perpDist,real_T *table,int_T tableIdx,real_T *y,real_T *yg,real_T *yb,real_T factor) ;


#ifdef MWDSP_INLINE_DSPRTLIB
#include "vipdrawshapes/clipline_rt.c"
#include "vipdrawshapes/line_bresenham_rt.c"
#include "vipdrawshapes/line_bresenham_rgb_rt.c"
#include "vipdrawshapes/get_int_coordinates_rt.c"
#include "vipdrawshapes/circle_symoctantpts_rt.c"
#include "vipdrawshapes/circle_symoctantpts_rgb_rt.c"
#include "vipdrawshapes/sortrows_rt.c"
#include "vipdrawshapes/createEdgesTable_rt.c"
#include "vipdrawshapes/fillOnePolygon_aa_rt.c"
#include "vipdrawshapes/fillOnePolygon_rt.c"
#include "vipdrawshapes/fillVerticalScanLine_rt.c"
#include "vipdrawshapes/fillVerticalScanLine_aa_rt.c"
#include "vipdrawshapes/fillpolygonInterp_rt.c"
#include "vipdrawshapes/detectIfCornerPixel_fillPoly_rt.c"
#include "vipdrawshapes/draw_aa_circle_delta_rt.c"
#include "vipdrawshapes/draw_aa_circle_rt.c"
#include "vipdrawshapes/aacircle_symquadpts_rt.c"
#include "vipdrawshapes/aacircle_symoctantpts_rt.c"
#include "vipdrawshapes/draw_aa_filledcircle_rt.c"
#include "vipdrawshapes/aacircle_8ptslines_rt.c"
#include "vipdrawshapes/aacircle_4ptslines_rt.c"
#include "vipdrawshapes/draw_aa_line_rt.c"
#endif


#ifdef __cplusplus
} /*  close brace for extern C from above */
#endif

#endif /* vipdrawshapes_rt_h */

/* [EOF] vipdrawshapes_rt.h */
