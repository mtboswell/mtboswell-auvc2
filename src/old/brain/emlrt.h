/*
 * @(#)emlrt.h    generated by: makeheader 5.1.5  Mon Jun 28 17:19:56 2010
 *
 *		built from:	../../../src/include/copyright.h
 *				../../../src/include/pragma_interface.h
 *				AAContext.cpp
 *				Alias.cpp
 *				AllocCheck.cpp
 *				Assign.cpp
 *				BoundsCheck.cpp
 *				Create.cpp
 *				CreateArray.cpp
 *				Destroy.cpp
 *				DoubleCheck.cpp
 *				ExternalMode.cpp
 *				Gateway.cpp
 *				HeapMemoryCheck.cpp
 *				HeapReferenceStack.cpp
 *				InitArray.cpp
 *				MultipleEntryPoints.cpp
 *				RefCount.cpp
 *				RunTimeErrors.cpp
 *				RunTimeStack.cpp
 *				Serialize.cpp
 *				Signals.cpp
 *				SizeEqCheck.cpp
 *				TypeCheck.cpp
 *				VSArray.cpp
 */

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

#ifndef emlrt_h
#define emlrt_h


/*
 * Copyright 1984-2003 The MathWorks, Inc.
 * All Rights Reserved.
 */



/* Copyright 2003-2006 The MathWorks, Inc. */

/* Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C extern
#endif

#endif


/*
 * MATLAB INTERNAL USE ONLY :: MEX Version
 */
#define EMLRT_VERSION_R2010B 0x2010B
#define EMLRT_VERSION_INFO  EMLRT_VERSION_R2010B

/*
 * MATLAB INTERNAL USE ONLY :: MEX error function
 */
typedef void (*EmlrtErrorFunction)(const char *aIdentifier, const char *aMessage);

/*
 * MATLAB INTERNAL USE ONLY :: Prototype of free functions. 
 */
typedef void (*EmlrtHeapReferenceFreeFcn)(void *, boolean_T);

/*
 * MATLAB INTERNAL USE ONLY :: Runtime stack info
 */
typedef struct emlrtRSInfo {
    int32_T     lineNo;
    const char *fcnName;
    const char *pathName;
} emlrtRSInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Runtime call stack
 */
typedef struct emlrtCallStack {
    uint32_T    fRTStackPointer;
    uint32_T    fRTStackSize;
    const emlrtRSInfo** fRTStackInfo;
    struct emlrtContext *fRTContext;
} emlrtCallStack;

/*
 * MATLAB INTERNAL USE ONLY :: MEX Context
 */
typedef struct emlrtContext {
    boolean_T   bFirstTime;
    boolean_T   bInitialized;
    unsigned int fVersionInfo;
    EmlrtErrorFunction fErrorFunction;
    const char *fFunctionName;
    struct emlrtCallStack* fRTCallStack;
    boolean_T   bDebugMode;
} emlrtContext;

/*
 * MATLAB INTERNAL USE ONLY :: External Mode Simulation
 */
typedef struct emlrtExternalSim {
    void        *fESim;
    uint8_T     *fIOBuffer;
    uint8_T     *fIOBufHead;
    size_t       fIOBufSize;
} emlrtExternalSim;

/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check parameters
 */
typedef struct emlrtBCInfo {
    int32_T     iFirst;
    int32_T     iLast;
    int32_T     lineNo;
    int32_T     colNo;
    const char *aName;
    const char *fName;
    const char *pName;
    int32_T     checkKind; /* see src/cg_ir/classic/cg_node.hpp::CG_BoundsCheckKindEnum */
}   emlrtBCInfo;


/*
 * MATLAB INTERNAL USE ONLY :: Equality check parameters
 */
typedef struct emlrtECInfo {
    int32_T     nDims;
    int32_T     lineNo;
    int32_T     colNo;
    const char *fName;
    const char *pName;
}   emlrtECInfo;

/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check parameters
 */
typedef struct {
    int32_T     lineNo;
    int32_T     colNo;
    const char *fName;
    const char *pName;
}   emlrtRTEInfo;

typedef emlrtRTEInfo emlrtMCInfo;

/* MATLAB INTERNAL USE ONLY :: Reference to global runtime context */
extern emlrtContext emlrtContextGlobal;


/*
 * MATLAB INTERNAL USE ONLY :: Initialize run-time context
 */
EXTERN_C void
emlrtInitContext(struct emlrtContext *ctx);


/*
 * MATLAB INTERNAL USE ONLY :: Query first-time sentinal
 */
EXTERN_C boolean_T
emlrtFirstTime(struct emlrtContext *aMAInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray alias
 */
EXTERN_C const mxArray *
emlrtAlias(const mxArray *in);


/*
 * MATLAB INTERNAL USE ONLY :: Create a persistent mxArray alias
 */
EXTERN_C const mxArray *
emlrtAliasP(const mxArray *in);


/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray vector alias
 */
EXTERN_C void 
emlrtAliases(int32_T nlhs, const mxArray **plhs, const mxArray **prhs);


/*
 * MATLAB INTERNAL USE ONLY :: Return an mxArray to MATLAB
 */
EXTERN_C mxArray *
emlrtReturnArrayR2009a(const mxArray *pa);


/*
 * MATLAB INTERNAL USE ONLY :: Simulation hysteresis suppression
 */
EXTERN_C void
emlrtShs(const void *a, const int b);


/*
 * MATLAB INTERNAL USE ONLY :: Verify default fimath
 */
EXTERN_C void
emlrtCheckDefaultFimathR2008b(const mxArray **ctFimath);


/*
 * MATLAB INTERNAL USE ONLY :: Clear mxArray allocation count
 */
EXTERN_C void
emlrtClearAllocCount(struct emlrtContext *aMAInfo, boolean_T bM, uint32_T iL, const char* ctDTO);


/*
 * MATLAB INTERNAL USE ONLY :: Update mxArray allocation count
 */
EXTERN_C void
emlrtUpdateAllocCount(int32_T delta);


/*
 * MATLAB INTERNAL USE ONLY :: Update persistent mxArray allocation count
 */
EXTERN_C void
emlrtUpdateAllocCountP(int32_T delta);


/*
 * MATLAB INTERNAL USE ONLY :: Check mxArray allocation count
 */
EXTERN_C void
emlrtCheckAllocCount(void);


/*
 * MATLAB INTERNAL USE ONLY :: Assign to an mxArray
 */
EXTERN_C void 
emlrtAssign(const mxArray **lhs, const mxArray *rhs);


/*
 * MATLAB INTERNAL USE ONLY :: Assign to a persistent mxArray
 */
EXTERN_C void 
emlrtAssignP(const mxArray **lhs, const mxArray *rhs);


/*
 * MATLAB INTERNAL USE ONLY :: Assign to a vector of mxArrays
 */
EXTERN_C void 
emlrtAssigns(int32_T nlhs, const mxArray **plhs, const mxArray **prhs);


/*
 * MATLAB INTERNAL USE ONLY :: Array bounds check
 */
EXTERN_C int32_T 
emlrtBoundsCheck(int32_T indexValue, emlrtBCInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Dynamic array bounds check
 */
EXTERN_C int32_T 
emlrtDynamicBoundsCheck(int32_T indexValue, int32_T loBound, int32_T hiBound, emlrtBCInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Perform integer multiplication, raise runtime error
 *                             if the operation overflows.
 */
EXTERN_C size_t emlrtSizeMul(size_t s1, size_t s2, const emlrtRTEInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray string from a C string
 */
EXTERN_C const mxArray *
emlrtCreateString(const char *in);


/*
 * MATLAB INTERNAL USE ONLY :: Create an mxArray string from a single char
 */
EXTERN_C const mxArray *
emlrtCreateString1(char c);


/*
 * MATLAB INTERNAL USE ONLY :: Create a struct matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateStructMatrix(int32_T m, int32_T n, int32_T nfields, const char **field_names);


/*
 * MATLAB INTERNAL USE ONLY :: Create a struct matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateStructArray(int32_T ndim, const int32_T *pdim, int32_T nfields, const char **field_names);


/*
 * MATLAB INTERNAL USE ONLY :: Create an enum
 */
EXTERN_C const mxArray *
emlrtCreateEnumR2010a(struct emlrtContext *ctx, const char *name, const mxArray *data);


/*
 * MATLAB INTERNAL USE ONLY :: Create an enum
 */
EXTERN_C const mxArray *
emlrtCreateEnumR2009a(const char *name, const mxArray *data);


/*
 * MATLAB INTERNAL USE ONLY :: Add a field to a struct matrix mxArray
 */
EXTERN_C const mxArray *
emlrtAddField(const mxArray *mxStruct, const mxArray *mxField, const char *fldName, int index);


/*
 * MATLAB INTERNAL USE ONLY :: Get a field from a struct matrix mxArray
 */
EXTERN_C const mxArray *
emlrtGetField(const mxArray *mxStruct, int aIndex, const char *fldName);


/*
 * MATLAB INTERNAL USE ONLY :: Create a numeric matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateNumericMatrix(int32_T m, int32_T n, int32_T classID, int32_T nComplexFlag);


/*
 * MATLAB INTERNAL USE ONLY :: Create a numeric matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateNumericArray(int32_T ndim, const void *pdim, int32_T classID, int32_T nComplexFlag);


/*
 * MATLAB INTERNAL USE ONLY :: Create a scaled numeric matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateScaledNumericArrayR2008b(int32_T ndim, const void *pdim, int32_T classID, int32_T nComplexFlag, int32_T aScale);


/*
 * MATLAB INTERNAL USE ONLY :: Create a double scalar mxArray
 */
EXTERN_C const mxArray *
emlrtCreateDoubleScalar(real_T in);


/*
 * MATLAB INTERNAL USE ONLY :: Create a logical matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateLogicalMatrix(int32_T m, int32_T n);


/*
 * MATLAB INTERNAL USE ONLY :: Create a logical matrix mxArray
 */
EXTERN_C const mxArray *
emlrtCreateLogicalArray(int32_T ndim, const int32_T *dims);


/*
 * MATLAB INTERNAL USE ONLY :: Create a logical scalar mxArray
 */
EXTERN_C const mxArray *
emlrtCreateLogicalScalar(boolean_T in);


/*
 * MATLAB INTERNAL USE ONLY :: Create a character array mxArray
 */
EXTERN_C const mxArray *
emlrtCreateCharArray(int32_T ndim, const int32_T *dims);


/*
 * MATLAB INTERNAL USE ONLY :: Create a 2-D character array mxArray
 */
EXTERN_C const mxArray *
emlrtCreateCharArray2(int32_T m, int32_T n);


/*
 * MATLAB INTERNAL USE ONLY :: Create a numerictype mxArray
 */
EXTERN_C const mxArray *
 emlrtCreateNumericType(boolean_T issigned, int32_T wordlength, real_T bias, real_T slope, int32_T fixedexponent);


/*
 * MATLAB INTERNAL USE ONLY :: Create a FI mxArray from a value mxArray
 */
EXTERN_C const mxArray *emlrtCreateFI(const mxArray *fimath, const mxArray *ntype, const char *fitype, const mxArray *fival);


/*
 * MATLAB INTERNAL USE ONLY :: Create a FI mxArray from a value mxArray
 */
EXTERN_C const mxArray *emlrtCreateFIR2009a(const mxArray *fimath, const mxArray *ntype, const char *fitype, const mxArray *fival, const bool fmIsLocal);


/*
 * MATLAB INTERNAL USE ONLY :: Get the intarray from a FI mxArray
 */
EXTERN_C const mxArray *emlrtImportFiIntArrayR2008b(const mxArray *aFiMx);


/*
 * MATLAB INTERNAL USE ONLY :: Get the enum int from an MCOS enumeration mxArray.
 */
EXTERN_C const int32_T emlrtGetEnumElementR2009a(const mxArray *aEnum, int aIndex);


/*
 * MATLAB INTERNAL USE ONLY :: Get the enum int from an MCOS enumeration mxArray.
 */
EXTERN_C const mxArray * emlrtGetEnumUnderlyingArrayR2009a(const mxArray *aEnum);


/*
 * MATLAB INTERNAL USE ONLY :: Create an array of mxArrays
 */
EXTERN_C const mxArray * 
emlrtCreateArray(const mxArray **ppa, int_T am, int_T an);


/*
 * MATLAB INTERNAL USE ONLY :: Destroy an mxArray
 */
EXTERN_C void
emlrtDestroyArray(const mxArray **pa);


/*
 * MATLAB INTERNAL USE ONLY :: Destroy a vector of mxArrays
 */
EXTERN_C void
emlrtDestroyArrays(int32_T narrays, const mxArray **parrays);

 
/*
 * MATLAB INTERNAL USE ONLY :: Double check parameters
 */
typedef struct {
    int32_T     lineNo;
    int32_T     colNo;
    const char *fName;
    const char *pName;
    int32_T     checkKind; /* see src/cg_ir/classic/cg_node.hpp::CG_Node_CheckEnum */
}   emlrtDCInfo;


/*
 * MATLAB INTERNAL USE ONLY :: Check that d can be safely cast to int.
 */
EXTERN_C real_T 
emlrtIntegerCheckR2009b(real_T d, emlrtDCInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Check that d is not NaN.
 */
EXTERN_C real_T 
emlrtNotNanCheckR2009b(real_T d, emlrtDCInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Check that d >= 0.
 */
EXTERN_C real_T 
emlrtNonNegativeCheckR2009b(real_T d, emlrtDCInfo *aInfo);


#ifdef __WATCOMC__
#pragma aux emlrtIntegerCheckR2009b value [8087];
#pragma aux emlrtNotNanCheckR2009b value [8087];
#pragma aux emlrtNonNegativeCheckR2009b value [8087];
#endif


/*
 * MATLAB INTERNAL USE ONLY :: Terminate external-mode serialization
 */
EXTERN_C void
emlrtExtSerializeEnd(struct emlrtExternalSim *aExternalSim);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a byte
 */
EXTERN_C uint8_T
emlrtExtDeserializeByte(struct emlrtExternalSim *aExternalSim);


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a byte
 */
EXTERN_C void
emlrtExtSerializeByte(struct emlrtExternalSim *aExternalSim, uint8_T b);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a single
 */
EXTERN_C real32_T
emlrtExtDeserializeSingle(struct emlrtExternalSim *aExternalSim);


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a single
 */
EXTERN_C void
emlrtExtSerializeSingle(struct emlrtExternalSim *aExternalSim, real32_T s);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a double
 */
EXTERN_C real64_T
emlrtExtDeserializeDouble(struct emlrtExternalSim *aExternalSim);


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a double
 */
EXTERN_C void
emlrtExtSerializeDouble(struct emlrtExternalSim *aExternalSim, real64_T d);


/*
* MATLAB INTERNAL USE ONLY :: connect to external target 
*/
EXTERN_C void 
emlrtExtConnect(struct emlrtExternalSim *aExternalSim, const uint32_T aChecksum[4], const char *aMexArgs, const char *aMethod);


/*
* MATLAB INTERNAL USE ONLY :: disconnect from external target 
*/
EXTERN_C void 
emlrtExtDisconnect(struct emlrtExternalSim *aExternalSim);


#ifdef __WATCOMC__
#pragma aux emlrtExtDeserializeDouble value [8087];
#endif


/*
* MATLAB INTERNAL USE ONLY :: fetch a global variable 
*/
EXTERN_C void 
emlrtPutGlobalVariable(const char *name, const mxArray *parray);


/*
* MATLAB INTERNAL USE ONLY :: fetch a global variable 
*/
EXTERN_C const mxArray *
emlrtGetGlobalVariable(const char *name);


/*
 * MATLAB INTERNAL USE ONLY :: Call out to MATLAB
 */
EXTERN_C const mxArray *
emlrtCallMATLAB(int32_T nlhs, const mxArray **plhs, int32_T nrhs, const mxArray **prhs, const char *cmd, boolean_T tmp, emlrtMCInfo* aLoc);


/*
 * MATLAB INTERNAL USE ONLY :: Maintain heap memory check information upon entering a mex function.
 */
EXTERN_C void emlrtHeapMemCheckInitialize(struct emlrtContext *aMexContext, int aMaxHeapSize);


/*
 * MATLAB INTERNAL USE ONLY :: Maintain heap memory check information upon leaving a mex function.
 */
EXTERN_C void emlrtHeapMemCheckTerminate(void);


/*
 * MATLAB INTERNAL USE ONLY :: Register the mex function to be unloaded.
 */
EXTERN_C void emlrtHeapMemCheckPrepareUnload(emlrtContext *aMexContext);


/*
 * MATLAB INTERNAL USE ONLY :: Maintain heap memory check information upon unload a mex function.
 *                             Memory leak check is performed at this moment no matter for normal or error exit.
 */
EXTERN_C void emlrtHeapMemCheckUnloadMex(struct emlrtContext *aMexContext);


/*
 * MATLAB INTERNAL USE ONLY :: malloc with memory integrity check
 */
EXTERN_C void* emlrtMalloc(size_t aSize);


/*
 * MATLAB INTERNAL USE ONLY :: calloc with memory integrity check
 */
EXTERN_C void* emlrtCalloc(size_t aNum, size_t aSize);


/*
 * MATLAB INTERNAL USE ONLY :: free with memory integrity check
 */
EXTERN_C void emlrtFree(void *aPtr);


/*
 * MATLAB INTERNAL USE ONLY :: Enter a new function of a MEX call.
 */
EXTERN_C void emlrtHeapReferenceStackEnterFcn(void);


/*
 * MATLAB INTERNAL USE ONLY :: Enter a new function of a MEX call.
 */
EXTERN_C void emlrtHeapReferenceStackLeaveFcn(void);


/*
 * MATLAB INTERNAL USE ONLY :: Push a new entry to the heap reference stack.
 */
EXTERN_C void emlrtPushHeapReferenceStack(void *aHeapReference, EmlrtHeapReferenceFreeFcn aFreeFcn);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize a character mxArray
 */
EXTERN_C void 
emlrtInitCharArray(int32_T n, const mxArray *a, const char *s);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize a logical mxArray
 */
EXTERN_C void 
emlrtInitLogicalArray(int32_T n, const mxArray *a, const boolean_T *b);


/*
 * MATLAB INTERNAL USE ONLY :: Export a numeric mxArray
 */
EXTERN_C void
emlrtExportNumericArrayR2008b(const mxArray *aOut, const void *aInData, int32_T aElementSize);

 
/*
 * MATLAB INTERNAL USE ONLY :: Auto-generated mexFunction
 */
typedef void (*emlrtMexFunction)(int, mxArray*[], int, const mxArray*[]);
/*
 * MATLAB INTERNAL USE ONLY :: Auto-generated entry-point
 */
typedef struct emlrtEntryPoint {
    const char *fName;
    emlrtMexFunction fMethod;
} emlrtEntryPoint;


/*
 * MATLAB INTERNAL USE ONLY :: Lookup an entry point
 */
EXTERN_C emlrtMexFunction 
emlrtGetMethod(int nrhs, const mxArray *prhs[], struct emlrtEntryPoint *aEntryPoints, int aNumEntryPoints);


/*
 * MATLAB INTERNAL USE ONLY :: Create a shallow copy of an mxArray
 */
EXTERN_C const mxArray *
emlrtCreateReference(const mxArray *pa);


/*
 * MATLAB INTERNAL USE ONLY :: Division by zero error
 */
EXTERN_C void 
emlrtDivisionByZeroError(void);


/*
 * MATLAB INTERNAL USE ONLY :: Division by zero error
 */
EXTERN_C void 
emlrtDivisionByZeroErrorR2008a(const emlrtRTEInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Integer overflow error
 */
EXTERN_C void 
emlrtIntegerOverflowErrorR2008a(const emlrtRTEInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Raise C heap allocation failure
 */
EXTERN_C void emlrtHeapAllocationError(const emlrtRTEInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize a runtime stack
 */
EXTERN_C void emlrtEnterRtStack(struct emlrtContext *aContext);


/*
 * MATLAB INTERNAL USE ONLY :: Terminate a runtime stack
 */
EXTERN_C void emlrtLeaveRtStack(struct emlrtContext *aContext);


#define EMLRTPUSHRTSTACK(aRSInfo) { \
    if (emlrtContextGlobal.fRTCallStack->fRTStackPointer < emlrtContextGlobal.fRTCallStack->fRTStackSize) \
        (emlrtContextGlobal.fRTCallStack->fRTStackInfo[emlrtContextGlobal.fRTCallStack->fRTStackPointer++] = aRSInfo); \
    else emlrtPushRtStack(aRSInfo); }


/*
 * MATLAB INTERNAL USE ONLY :: Push to runtime stack
 */
EXTERN_C void emlrtPushRtStack(const struct emlrtRSInfo *aRSInfo);


#define EMLRTPOPRTSTACK(aRSInfo) { \
    if (emlrtContextGlobal.fRTCallStack->fRTStackPointer != 0) \
        (emlrtContextGlobal.fRTCallStack->fRTStackPointer--); \
    else emlrtPopRtStack(aRSInfo); }


/*
 * MATLAB INTERNAL USE ONLY :: Pop from runtime stack
 */
EXTERN_C void emlrtPopRtStack(const struct emlrtRSInfo *aRSInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a byte
 */
EXTERN_C void
emlrtSerializeByte(uint8_T b);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a byte
 */
EXTERN_C uint8_T
emlrtDeserializeByte(void);


/*
 * MATLAB INTERNAL USE ONLY :: Terminate serializing
 */
EXTERN_C void
emlrtSerializeTerminate(void);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a double
 */
EXTERN_C real64_T
emlrtDeserializeDouble();


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a double
 */
EXTERN_C void
emlrtSerializeDouble(real64_T d);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a single
 */
EXTERN_C real32_T
emlrtDeserializeSingle();


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a single
 */
EXTERN_C void
emlrtSerializeSingle(real32_T d);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a char
 */
EXTERN_C char
emlrtDeserializeChar();


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a char
 */
EXTERN_C void
emlrtSerializeChar(char c);


/*
 * MATLAB INTERNAL USE ONLY :: Deserialize a logical
 */
EXTERN_C boolean_T
emlrtDeserializeLogical();


/*
 * MATLAB INTERNAL USE ONLY :: Serialize a logical
 */
EXTERN_C void
emlrtSerializeLogical(boolean_T b);


/*
 * MATLAB INTERNAL USE ONLY :: Initialize serializing
 */
EXTERN_C void
emlrtSerializeInitialize(boolean_T isDeserialize, boolean_T isVerification, const char *projectName, uint32_T aCheckSumLen, const uint32_T *aChecksum);


#ifdef __WATCOMC__
#pragma aux emlrtDeserializeDouble value [8087];
#pragma aux emlrtDeserializeSingle value [8087];
#endif


/*
 * MATLAB INTERNAL USE ONLY :: Check for Ctrl+C (break)
 */
EXTERN_C void
emlrtBreakCheck(void);


/*
 * MATLAB INTERNAL USE ONLY :: Equality check for 1-D sizes
 */
EXTERN_C void 
emlrtSizeEqCheck1D(int32_T dim1, int32_T dim2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Equality check for size vectors
 */
EXTERN_C void 
emlrtSizeEqCheckND(const int32_T* dims1, const int32_T* dims2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: equality check 
 */
EXTERN_C void 
emlrtDimSizeEqCheck(int32_T dim1, int32_T dim2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: greater than or euqal to check 
 */
EXTERN_C void 
emlrtDimSizeGeqCheck(int32_T dim1, int32_T dim2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Check size compatibility for A(I1,..IN) = B assignment in MATLAB.
 */
EXTERN_C void 
emlrtSubAssignSizeCheck(const int32_T* dims1, int32_T nDims1, const int32_T* dims2, int32_T nDims2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Check that at least one of the two given size vectors describe a proper
 * matrix (not a vector).
 */
EXTERN_C void emlrtMatrixMatrixIndexCheck(const int32_T* dims1, int32_T nDims1, const int32_T* dims2, int32_T nDims2, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Check that at least one of the two given size vectors describe a proper
 * matrix (not a vector).
 */
EXTERN_C void emlrtVectorVectorIndexCheck(int32_T sizeL_0, int32_T sizeL_1, int32_T sizeR_0, int32_T sizeR_1, emlrtECInfo *aInfo);


/*
 * MATLAB INTERNAL USE ONLY :: Return true if this is an MCOS enumeration.
 */
EXTERN_C bool
emlrtIsEnumR2009a(const mxArray *mx);


/*
 * MATLAB INTERNAL USE ONLY :: Check the class of an mxArray
 */
EXTERN_C void 
emlrtCheckClass(const char *msgName, const mxArray *pa, const char *className);


/*
 * MATLAB INTERNAL USE ONLY :: Check the sparseness of an mxArray
 */
EXTERN_C void 
emlrtCheckSparse(const char *msgName, const mxArray *pa, boolean_T sparse);


/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of an mxArray
 */
EXTERN_C void 
emlrtCheckBuiltIn(const char *msgName, const mxArray *pa, 
                  const char *className, boolean_T complex, uint32_T nDims, const void *pDims);


/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of an mxArray
 */
EXTERN_C void 
emlrtCheckBuiltInR2009a(struct emlrtContext *aCtx,
                        const char *msgName, const mxArray *pa, 
                        const char *className, boolean_T complex, uint32_T nDims, const void *pDims);


/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of a variable-size mxArray
 */
EXTERN_C void 
emlrtCheckVsBuiltInR2008b(const char *msgName, const mxArray *pa, 
                    const char *className, boolean_T complex, uint32_T nDims, const void *pDims, 
                    const boolean_T *aDynamic, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Check the size, class and complexness of a variable-size mxArray
 */
EXTERN_C void 
emlrtCheckVsBuiltInR2009a(emlrtContext *aCtx,
                          const char *msgName, const mxArray *pa, 
                          const char *className, boolean_T complex, uint32_T nDims, const void *pDims, 
                          const boolean_T *aDynamic, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a FI mxArray
 */
EXTERN_C void 
emlrtCheckFI(const char *aMsgName, const mxArray *aFi, boolean_T aComplex, uint32_T aNDims, const void *aVDims, 
             const mxArray *aFimath, const mxArray *aNumericType);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-size FI mxArray
 */
EXTERN_C void 
emlrtCheckVsFiR2008b(const char *aMsgName, const mxArray *aFi, boolean_T aComplex, uint32_T aNDims, const void *aVDims, 
                     const boolean_T *aDynamic, int32_T *aOutSizes,
                     const mxArray *aFimath, const mxArray *aNumericType);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-size FI mxArray
 */
EXTERN_C void 
emlrtCheckVsFiR2010b(const char *aMsgName, const mxArray *aFi, boolean_T aComplex, uint32_T aNDims, const void *aVDims, 
                     const boolean_T *aDynamic, const mxArray *aFimath, const mxArray *aNumericType);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a static-size struct mxArray
 */
EXTERN_C void 
emlrtCheckStruct(const char *msgName, const mxArray *s, int32_T nFields, const char **fldNames,
                 uint32_T nDims, const void *pDims);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a variable-size struct mxArray
 */
EXTERN_C void
emlrtCheckVsStructR2008b(const char *msgName, const mxArray *s, int32_T nFields, const char **fldNames,
                   uint32_T nDims, const void *pDims, 
                   const boolean_T *aDynamic, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of a static-size struct mxArray
 */
EXTERN_C void 
emlrtCheckEnumR2009a(emlrtContext *aCtx, const char *enumName, int32_T nEnumElements, const char **enumNames, const int32_T *enumValues);


/*
 * MATLAB INTERNAL USE ONLY :: Check the type of an unused input
 */
EXTERN_C void 
emlrtCheckUnusedR2009b(void *aUnused, size_t aSize);


/*
 * MATLAB INTERNAL USE ONLY :: Set the actual size of a variable-size array
 */
extern void 
emlrtSetVsSizesR2008b(const mxArray *pa, uint32_T nDimsMax, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Import an mxArray
 */
EXTERN_C void
emlrtImportArrayR2008b(const mxArray *aIn, void *aOutData, int32_T aElementSize);


/*
 * MATLAB INTERNAL USE ONLY :: Import an mxArray
 */
EXTERN_C void
emlrtImportVsArrayR2008b(const mxArray *aIn, void *aOutData, int32_T aElementSize, uint32_T nDimsMax, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Import a FI mxArray
 */
EXTERN_C void
emlrtImportVsFiArrayR2009b(const mxArray *aFiMx, const mxArray *aIntMx, void *aOutData, int32_T aElementSize, uint32_T nDimsMax, int32_T *aOutSizes);


/*
 * MATLAB INTERNAL USE ONLY :: Set the actual sizes of a dynamic FI array
 */
EXTERN_C void 
emlrtSetVsFiSizes(const mxArray *aFi, uint32_T nDimsExpected, int32_T *aOutSizes);

#endif /* emlrt_h */
