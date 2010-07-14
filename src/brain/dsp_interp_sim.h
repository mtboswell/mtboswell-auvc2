/*
 *  DSP Blockset Interpolation block support file
 *
 *  Copyright 1995-2008 The MathWorks, Inc.
 *  $Revision: 1.3.4.4 $ $Date: 2008/05/19 22:48:37 $
 */
#ifndef DSP_INTERP_SIM_H
#define DSP_INTERP_SIM_H

#include "dsp_sim.h"

typedef enum {
    ERR_NONE,
    ERR_WARNING,
    ERR_ERROR
} InterpErrMode;
 
/*
 * Argument and function pointer caches:
 */
typedef struct {
    void       *y;   /* Output data pointer */
    const void *u;   /* Input data pointer  */
    const void *iptr;/* Interpolation index pointer */
    int_T nSamps;    /* # of rows           */
    int_T nChans;    /* # of channels/cols  */
    int_T nSampsI;   /* # of samples per channel for interpolation indices vector */
    int_T nChansI;   /* # of channels for interpolation indices vector */
    /* The  members of the structure below apply only to FIR interpolation mode
     * So when the block works in Linear mode, we copy only the members of this structure
     * upto this point, and not the members of the sub-structure below. So be careful not to 
     * change the ordering of elements in this structure, b'coz that will impact run-time functions.
     */
    struct  {
        const void  *filt;     /* Index to filter coeff          */
        int_T filtlen;         /* For FIR interp mode            */
        int_T nphases;         /* # phases in FIR interp filter  */
    } filterCache;

} InterpArgsCache;  

typedef void (*InterpErrFcn)(SimStruct *S, InterpArgsCache *args, InterpErrMode errMode);

typedef struct {
    InterpArgsCache Args;
    InterpErrMode   errMode;    /* Handling of invalid index */
    InterpErrFcn InterpErrFcnPtr; /* Pointer to error handler function */
} SFcnCache;


extern void InterpErrFcn_D(SimStruct *S, InterpArgsCache *args, InterpErrMode errMode);
extern void InterpErrFcn_R(SimStruct *S, InterpArgsCache *args, InterpErrMode errMode);
extern void InterpErrFcn_NOP(SimStruct *S, InterpArgsCache *args, InterpErrMode errMode);


#endif /* DSP_INTERP_SIM_H */

/* [EOF] dsp_interp_sim.h */
