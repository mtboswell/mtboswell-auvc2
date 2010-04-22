/*
 *  vip_fileread_sim.h - Read binary video file
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.6.5 $  $Date: 2008/03/17 23:28:33 $
 */

#ifndef vip_fileread_sim_h
#define vip_fileread_sim_h

#include <stdio.h>
#include <vip_sim.h>
#include "vip_fourcclist_sim.h"

#define MAXCOMPONENTS 4

typedef void (*fileReadFcn)(SimStruct *S);
typedef void (*byteSwapFcn)(byte_T *data);
typedef void (*set4thBytefor24BitsFcn)(byte_T *y, int_T N, boolean_T signedData,
                                       int_T inc);
typedef void (*castInt2FloatFcn)(void *, void *, int_T , int_T );


typedef struct {
    FILE    *fptr;
    boolean_T eofflag;
    boolean_T outputeof;
    int32_T  numOutputs;
    byte_T **portAddr;
    byte_T **compPortAddr;
    byte_T **portAddrVar;       /* used as temporary space */
    int32_T *compOrder;         /* points to component order parameter */
    int32_T *bpe;               /* bytes per element in each component */
    int32_T *bpeout;            /* bytes per element in each port */
    int32_T *bitspe;            /* bytes per element in each port */
    int32_T  numCompPerPack;
    int32_T *frameSizes;        /* Size of the frame for each port */
    real_T   packSize[2];       /* Size of the frame in terms of packs */
    int32_T *portCount;         /* How manytimes a compoenent repeats for a port
                                   eg YUYV => 2 1 1 */
    int32_T *portCountInc;      /* Incremental count of component order
                                   eg if comporder = [1 2 1 3 1 1]
                                   portcountinc = [1 1 2 1 3 4] */
    byte_T   currentChar;       /* Last byte read from file */
    int32_T  leftoverBits;      /* Bits left in currentchar */
    fileReadFcn fcn;            /* Output function pointer */
    boolean_T Loop;             /* loop or not */
    int32_T   numLoops;         /* Number of times to loop */
    boolean_T *threeByteData;   /* Whether any of the components are 24 bits. */
    int_T overRideInc[MAXCOMPONENTS]; /* Pointer increment while casting to double */
    castInt2FloatFcn castInt2FloatFcnPtr[MAXCOMPONENTS];
    byteSwapFcn byteSwapFcnPtr[5]; /* byte swap function one per number of bytes */
    set4thBytefor24BitsFcn set4thBytefor24BitsFcnPtr;
} SFcnCache;


extern void AYUV_TLF(SimStruct *S);
extern void AYUV_BLF(SimStruct *S);
extern void UYVY_TLF(SimStruct *S);
extern void UYVY_BLF(SimStruct *S);
extern void IUYV_TLF(SimStruct *S);
extern void IUYV_BLF(SimStruct *S);
extern void YUY2_TLF(SimStruct *S);
extern void YUY2_BLF(SimStruct *S);
extern void YVYU_TLF(SimStruct *S);
extern void YVYU_BLF(SimStruct *S);

extern void Y41P_TLF(SimStruct *S);
extern void Y41P_BLF(SimStruct *S);
extern void IY41_TLF(SimStruct *S);
extern void IY41_BLF(SimStruct *S);
extern void Y41T_TLF(SimStruct *S);
extern void Y41T_BLF(SimStruct *S);
extern void Y42T_TLF(SimStruct *S);
extern void Y42T_BLF(SimStruct *S);
extern void CLJR_TLF(SimStruct *S);
extern void CLJR_BLF(SimStruct *S);
extern void IYU1_TLF(SimStruct *S);
extern void IYU1_BLF(SimStruct *S);
extern void IYU2_TLF(SimStruct *S);
extern void IYU2_BLF(SimStruct *S);
extern void V210_TLF(SimStruct *S);
extern void V210_BLF(SimStruct *S);
extern void NV12_NV21_TLF(SimStruct *S);
extern void NV12_NV21_BLF(SimStruct *S);
extern void IMC1_IMC3_TLF(SimStruct *S);
extern void IMC1_IMC3_BLF(SimStruct *S);
extern void IMC2_IMC4_TLF(SimStruct *S);
extern void IMC2_IMC4_BLF(SimStruct *S);
extern void fullByteRead_PLANAR_NI_TLF(SimStruct *S);
extern void fullByteRead_PLANAR_I_TLF(SimStruct *S);
extern void fullByteRead_PLANAR_NI_BLF(SimStruct *S);
extern void fullByteRead_PLANAR_I_BLF(SimStruct *S);
extern void fullByteRead_PLANAR_NI_TLF_BS(SimStruct *S);
extern void fullByteRead_PLANAR_I_TLF_BS(SimStruct *S);
extern void fullByteRead_PLANAR_NI_BLF_BS(SimStruct *S);
extern void fullByteRead_PLANAR_I_BLF_BS(SimStruct *S);
extern void fullByteRead_PACKED_NI_TLF(SimStruct *S);
extern void fullByteRead_PACKED_I_TLF(SimStruct *S);
extern void fullByteRead_PACKED_NI_BLF(SimStruct *S);
extern void fullByteRead_PACKED_I_BLF(SimStruct *S);
extern void fullByteRead_PACKED_NI_TLF_BS(SimStruct *S);
extern void fullByteRead_PACKED_I_TLF_BS(SimStruct *S);
extern void fullByteRead_PACKED_NI_BLF_BS(SimStruct *S);
extern void fullByteRead_PACKED_I_BLF_BS(SimStruct *S);
extern void bitsRead_PACKED_NI_TLF(SimStruct *S);
extern void bitsRead_PACKED_NI_BLF(SimStruct *S);
extern void bitsRead_PACKED_I_TLF(SimStruct *S);
extern void bitsRead_PACKED_I_BLF(SimStruct *S);

extern void byteSwap1(byte_T *data);
extern void byteSwap2(byte_T *data);
extern void byteSwap3(byte_T *data);
extern void byteSwap4(byte_T *data);

extern void set4thBytefor24Bits_LE(byte_T *y, int_T N, boolean_T signedData,
                                   int_T inc);
extern void set4thBytefor24Bits_BE(byte_T *y, int_T N, boolean_T signedData,
                                   int_T inc);

#endif /* vip_fileread_sim_h */

/* [EOF] vip_fileread_sim.h */

