/*
 *  vip_filewrite_sim.h - Write binary video file
 *
 *  Copyright 1995-2006 The MathWorks, Inc.
 *  $Revision: 1.1.6.5 $  $Date: 2008/03/17 23:28:34 $
 */

#ifndef vip_filewrite_sim_h
#define vip_filewrite_sim_h

#include <stdio.h>
#include <vip_sim.h>
#include "vip_fourcclist_sim.h"

typedef void (*fileWriteFcn)(SimStruct *S);
typedef void (*byteSwapFcn)(const byte_T *data, byte_T *out);

/* only for scaled double */
#define   REALXX  real_T                
#define   UINT08  uint8_T               
#define   UINT16  uint16_T              
#define   UINT32  uint32_T 
#define   SINT08  int8_T               
#define   SINT16  int16_T              
#define   SINT32  int32_T 

typedef void (*castDoubleToFix)    (const real_T *uin, void   *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_U08)(const real_T *uin, UINT08 *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_U16)(const real_T *uin, UINT16 *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_U32)(const real_T *uin, UINT32 *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_S08)(const real_T *uin, SINT08 *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_S16)(const real_T *uin, SINT16 *dworkPtr, const int_T inWidth);
typedef void (*castDoubleToFix_S32)(const real_T *uin, SINT32 *dworkPtr, const int_T inWidth);

typedef struct {
    FILE *fptr;
    int_T numInputs;
    const byte_T **portAddr;
	const real_T   **uinAddrSD;/* For scaled double */
	void     **dworkAddrSD;    /* For scaled double */
    const byte_T **compPortAddr;
    const byte_T **portAddrVar;  /* used as temporary space */
	void *dworkPtr; /* For scaled double */ 
	void *dworkPtr0; /* For scaled double */ 
	void *dworkPtr1; /* For scaled double */ 
	void *dworkPtr2; /* For scaled double */ 
	void *dworkPtr3; /* For scaled double */ 

	const real_T *uin;
	const real_T *uin0;
	const real_T *uin1;
	const real_T *uin2;
	const real_T *uin3;

    int_T  *compOrder;           /* points to component order parameter */
    int_T  *bpe;                 /* bytes per element in each component */
    int_T  *bpein;               /* bytes per element in each port */
    int_T  numCompPerPack;
    int_T  *frameSizes;          /* Size of the frame for each port */
    int_T  *packSize;            /* Size of the frame in terms of packs */
    int_T  *portCount;           /* How manytimes a compoenent repeats for a port
                                   eg YUYV => 2 1 1 */
    int_T  *portCountInc;        /* Incremental count of component order
                                   eg if comporder = [1 2 1 3 1 1]
                                   portcountinc = [1 1 2 1 3 4] */
    fileWriteFcn fcn;            /* Output function pointer */
    byteSwapFcn byteSwapFcnPtr[5]; /* byte swap function one per number of bytes */
	castDoubleToFix castDoubleToFixFcnPtr[5];/* one for each port */
	boolean_T isScaledDouble;
} SFcnCache;

extern void AYUV_TLF_Write(SimStruct *S);
extern void AYUV_BLF_Write(SimStruct *S);
extern void UYVY_TLF_Write(SimStruct *S);
extern void UYVY_BLF_Write(SimStruct *S);
extern void IUYV_TLF_Write(SimStruct *S);
extern void IUYV_BLF_Write(SimStruct *S);
extern void YUY2_TLF_Write(SimStruct *S);
extern void YUY2_BLF_Write(SimStruct *S);
extern void YVYU_TLF_Write(SimStruct *S);
extern void YVYU_BLF_Write(SimStruct *S);
extern void Y41P_TLF_Write(SimStruct *S);
extern void Y41P_BLF_Write(SimStruct *S);
extern void IY41_TLF_Write(SimStruct *S);
extern void IY41_BLF_Write(SimStruct *S);
extern void Y41T_TLF_Write(SimStruct *S);
extern void Y41T_BLF_Write(SimStruct *S);
extern void Y42T_TLF_Write(SimStruct *S);
extern void Y42T_BLF_Write(SimStruct *S);
extern void CLJR_TLF_Write(SimStruct *S);
extern void CLJR_BLF_Write(SimStruct *S);
extern void IYU1_TLF_Write(SimStruct *S);
extern void IYU1_BLF_Write(SimStruct *S);
extern void IYU2_TLF_Write(SimStruct *S);
extern void IYU2_BLF_Write(SimStruct *S);
extern void V210_TLF_Write(SimStruct *S);
extern void V210_BLF_Write(SimStruct *S);
extern void NV12_NV21_TLF_Write(SimStruct *S);
extern void NV12_NV21_BLF_Write(SimStruct *S);
extern void IMC1_IMC3_TLF_Write(SimStruct *S);
extern void IMC1_IMC3_BLF_Write(SimStruct *S);
extern void IMC2_IMC4_TLF_Write(SimStruct *S);
extern void IMC2_IMC4_BLF_Write(SimStruct *S);
extern void fullByteWrite_PLANAR_NI_TLF(SimStruct *S);
extern void fullByteWrite_PLANAR_NI_TLF_BS(SimStruct *S);
extern void fullByteWrite_PLANAR_I_TLF(SimStruct *S);
extern void fullByteWrite_PLANAR_I_TLF_BS(SimStruct *S);
extern void fullByteWrite_PLANAR_NI_BLF(SimStruct *S);
extern void fullByteWrite_PLANAR_NI_BLF_BS(SimStruct *S);
extern void fullByteWrite_PLANAR_I_BLF(SimStruct *S);
extern void fullByteWrite_PLANAR_I_BLF_BS(SimStruct *S);
extern void fullByteWrite_PACKED_NI_TLF(SimStruct *S);
extern void fullByteWrite_PACKED_NI_TLF_BS(SimStruct *S);
extern void fullByteWrite_PACKED_I_TLF(SimStruct *S);
extern void fullByteWrite_PACKED_I_TLF_BS(SimStruct *S);
extern void fullByteWrite_PACKED_NI_BLF(SimStruct *S);
extern void fullByteWrite_PACKED_NI_BLF_BS(SimStruct *S);
extern void fullByteWrite_PACKED_I_BLF(SimStruct *S);
extern void fullByteWrite_PACKED_I_BLF_BS(SimStruct *S);

extern void byteSwap1_Write(const byte_T *data, byte_T *out);
extern void byteSwap2_Write(const byte_T *data, byte_T *out);
extern void byteSwap3_Write(const byte_T *data, byte_T *out);
extern void byteSwap4_Write(const byte_T *data, byte_T *out);

#endif /* vip_filewrite_sim_h */

/* [EOF] vip_filewrite_sim.h */

