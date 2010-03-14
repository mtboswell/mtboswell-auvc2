/*
 *  HOUGHLINES_D_RT Helper function for HoughLines block.
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.6.2 $  $Date: 2006/06/27 23:21:49 $
 */
/*  Co-ordinate system
 *
 *      (0,0)     Top Horiz
 *        |--------------------|--->x
 *        |                    |
 *        |                    |
 *        |                    |
 *        |Left                | Right Vertical
 *        |Vertical            |
 *        |                    |
 *        |                    |
 *        |--------------------|
 *        |      Bottom Horiz
 *        |
 *        |
 *        y
*/

#include "viphoughlines_rt.h"  

EXPORT_FCN void MWVIP_HoughLines_D(const real_T *uTheta, 
                                   const real_T *uRho, 
                                        int32_T *outRC,
                                        int_T    NumRhoOrTheta,
                                        int_T    RowsIn,
                                        int_T    ColsIn)
{
    int_T RowsIn_mi1 = RowsIn-1;
    int_T ColsIn_mi1 = ColsIn-1;
    int_T i;
    real_T tmpRound;
    for (i=0;i<NumRhoOrTheta;i++)
    {
        int_T count=0;
        int_T colIdx = i*4;
        /* INFO: for x,y we follow Matrix indexing (see doc for the interpretation of rho, theta,x,y) */
        /*       i.e., origin is at upper-left corner */
        real_T x1 = ((uRho[i]+DBL_EPSILON)/ ( cos(uTheta[i]) + DBL_EPSILON) );
		real_T y2 = ((uRho[i]+DBL_EPSILON)/ ( sin(uTheta[i]) + DBL_EPSILON) );

        /* part-1: top horizontal axis */
        tmpRound = floor(x1+0.5);  /* convert from Fractional to signed_no_fractional */
        if (tmpRound>=0 && tmpRound<=ColsIn_mi1)  
        {
            /* y1=0 */
            outRC[colIdx] = 0; outRC[colIdx+1] = (int32_T)tmpRound;  /* count=0 */
            count++;
        }

        /* part-2: left vertical axis */
        tmpRound = floor(y2+0.5); /* convert from Fractional to signed_no_fractional */
        if ((tmpRound>=0) && (tmpRound<=RowsIn_mi1)) 
        {
            /* x2=0 */
            outRC[colIdx+2*count] = (int32_T)tmpRound; outRC[colIdx+1+2*count] = 0;
            count++;
        }

        /* part-3: Right vertical axis */
        if (count<2) 
        {   
            real_T yc=(x1-(real_T)ColsIn_mi1)*(y2/x1); /* note: here we are using x1,y2 with fractional */

            tmpRound = floor(yc+0.5);  /* convert from Fractional to signed_no_fractional */

            if ((tmpRound>=0) && (tmpRound<=RowsIn_mi1))  
            {
                /* xc=ColsIn_mi1 */
                outRC[colIdx+2*count] = (int32_T)tmpRound; outRC[colIdx+1+2*count] = ColsIn_mi1;
                count++;
            }  
        }
        /* part-4: bottom horizontal axis */
        if (count<2)
        {
            real_T xr=x1-(x1/y2)*RowsIn_mi1;/* note: here we are using x1,y2 with fractional */

            tmpRound = floor(xr+0.5);  /* convert from Fractional to signed_no_fractional */

            if ((tmpRound>=0) && (tmpRound<=ColsIn_mi1))  
            {
                /* yr=RowsIn_mi1 */
                outRC[colIdx+2*count] = RowsIn_mi1; outRC[colIdx+1+2*count] = (int32_T)tmpRound;
                count++;
            }                              
        }
        /* Format: X1,Y1,X2,Y2: each COLUMN in output outRC corresponds to a line */
        if (count<2) 
        {   /* if you don't get two points, fill the whole column with -1;          */
            /* so no line will be drawn when coords are fed to 'Draw Shapes' block  */
            outRC[colIdx] = -1; outRC[colIdx+1] = -1; outRC[colIdx+2] = -1; outRC[colIdx+3] = -1;
        }
    } /* end for */
}

/* [EOF] houghlines_d_rt.c */
