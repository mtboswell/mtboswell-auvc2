/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.642
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu Jul 15 21:24:39 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu Jul 15 21:24:43 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_h_
#define RTW_HEADER_brain_h_
#ifndef brain_COMMON_INCLUDES_
# define brain_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_pow32_snf.h"
#include "rt_pow_snf.h"
#endif                                 /* brain_COMMON_INCLUDES_ */

#include "brain_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals for system '<S10>/Embedded MATLAB Function1' */
typedef struct {
  real_T XCenter;                      /* '<S10>/Embedded MATLAB Function1' */
  real_T YCenter;                      /* '<S10>/Embedded MATLAB Function1' */
} rtB_EmbeddedMATLABFunction1_bra;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
typedef struct {
  real_T ColorSpaceConversion1_o1;     /* '<S50>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2;     /* '<S50>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3;     /* '<S50>/Color Space  Conversion1' */
  real_T DrawMarkers[19200];           /* '<S10>/Draw Markers' */
  real_T Add;                          /* '<S47>/Add' */
  real_T Add1;                         /* '<S47>/Add1' */
  real_T BlobArea;                     /* '<S10>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S10>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S10>/Embedded MATLAB Function' */
  real_T ColorSpaceConversion_o1;      /* '<S50>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2;      /* '<S50>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3;      /* '<S50>/Color Space  Conversion' */
  real_T ImageDataTypeConversion[19200];/* '<S10>/Image Data Type Conversion' */
  int8_T DataTypeConversion;           /* '<S48>/Data Type Conversion' */
  boolean_T BW[19200];                 /* '<S46>/Relational Operator' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S10>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsBuoysAppr;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
typedef struct {
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S10>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S52>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S51>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S54>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S53>/Y-Buoy Discrete-Time Integrator' */
  real_T ColorSpaceConversion_DWORK1;  /* '<S50>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1; /* '<S50>/Color Space  Conversion1' */
  uint32_T StateFlowFunctionsBuoysApproa_a;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsBuoysApproa_m;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsBuoysApp;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
typedef struct {
  real_T DrawMarkers[57600];           /* '<S15>/Draw Markers' */
  boolean_T eml_LogicMatrix[19200];
  real_T Image;                        /* '<S15>/IF Buoy Conditions' */
  real_T Eccent[50];                   /* '<S15>/Blob Extraction' */
  real_T Extent[50];                   /* '<S15>/Blob Extraction' */
  real_T Centroid[100];                /* '<S15>/Blob Extraction' */
  uint8_T TotalNum;                    /* '<S15>/Blob Extraction' */
} rtB_StateFlowFunctionsBuoysFind;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
typedef struct {
  real_T F0_RTP;                       /* '<S15>/Blob Extraction' */
  real_T F1_RTP;                       /* '<S15>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S15>/Blob Extraction' */
  int32_T WALKER_RTP[8];               /* '<S15>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S15>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S15>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S15>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S15>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S15>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S15>/Blob Extraction' */
  boolean_T hblob;                     /* '<S15>/Blob Extraction' */
} rtDW_StateFlowFunctionsBuoysFin;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage' */
typedef struct {
  real_T L[19200];                     /* '<S18>/Embedded MATLAB Function' */
  real_T a[19200];                     /* '<S18>/Embedded MATLAB Function' */
  real_T b[19200];                     /* '<S18>/Embedded MATLAB Function' */
  real_T ColorSpaceConversion_o1[19200];/* '<S18>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2[19200];/* '<S18>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3[19200];/* '<S18>/Color Space  Conversion' */
  real_T RGB[57600];                   /* '<S18>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsBuoysShow;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage' */
typedef struct {
  real_T ColorSpaceConversion_DWORK1[19200];/* '<S18>/Color Space  Conversion' */
} rtDW_StateFlowFunctionsBuoysSho;

/* Block signals for system '<S64>/Low Pass Filter' */
typedef struct {
  real32_T fv0[19200];
  real32_T Iout[19200];                /* '<S64>/Low Pass Filter' */
  real32_T eml_Itemp[18644];
} rtB_LowPassFilter_brain;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation' */
typedef struct {
  real_T ColorSpaceConversion_o1[19200];/* '<S17>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2[19200];/* '<S17>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3[19200];/* '<S17>/Color Space  Conversion' */
  real_T ref_colors[150];              /* '<S65>/Reference Color Selection' */
  real_T num_colors;                   /* '<S65>/Reference Color Selection' */
  real_T LabelMatrix[19200];           /* '<S65>/LabSegmentation' */
  real32_T ColorSpaceConversion1_o1[19200];/* '<S17>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o2[19200];/* '<S17>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o3[19200];/* '<S17>/Color Space  Conversion1' */
  uint32_T eml_LabelMatrix[4800];
  real32_T Resize[4800];               /* '<S71>/Resize' */
  real32_T Resize1[4800];              /* '<S71>/Resize1' */
  real32_T Resize2[4800];              /* '<S71>/Resize2' */
  rtB_LowPassFilter_brain sf_LowPassFilter2;/* '<S64>/Low Pass Filter2' */
  rtB_LowPassFilter_brain sf_LowPassFilter1;/* '<S64>/Low Pass Filter1' */
  rtB_LowPassFilter_brain sf_LowPassFilter;/* '<S64>/Low Pass Filter' */
} rtB_StateFlowFunctionsBuoysIter;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation' */
typedef struct {
  real_T ColorSpaceConversion_DWORK1[19200];/* '<S17>/Color Space  Conversion' */
  real32_T ColorSpaceConversion1_DWORK1[19200];/* '<S17>/Color Space  Conversion1' */
  real32_T Resize_IntBuffer[9600];     /* '<S71>/Resize' */
  real32_T Resize1_IntBuffer[9600];    /* '<S71>/Resize1' */
  real32_T Resize2_IntBuffer[9600];    /* '<S71>/Resize2' */
} rtDW_StateFlowFunctionsBuoysIte;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors' */
typedef struct {
  boolean_T eml_LogicMatrix[19200];
  real_T blobs[200];                   /* '<S14>/Say Which Buoy Is Which' */
  real_T count;                        /* '<S14>/IF Buoy Conditions' */
  real_T Eccent[50];                   /* '<S14>/Blob Extraction' */
  real_T Extent[50];                   /* '<S14>/Blob Extraction' */
  real_T Centroid[100];                /* '<S14>/Blob Extraction' */
  real_T Area[50];                     /* '<S14>/Blob Extraction' */
  uint8_T TotalNum;                    /* '<S14>/Blob Extraction' */
} rtB_StateFlowFunctionsBuoysFi_d;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors' */
typedef struct {
  real_T F1_RTP;                       /* '<S14>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S14>/Blob Extraction' */
  real_T F3_RTP;                       /* '<S14>/Blob Extraction' */
  int32_T WALKER_RTP[8];               /* '<S14>/Blob Extraction' */
  int32_T F0_RTP;                      /* '<S14>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S14>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S14>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S14>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S14>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S14>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S14>/Blob Extraction' */
  boolean_T hblob;                     /* '<S14>/Blob Extraction' */
} rtDW_StateFlowFunctionsBuoysF_e;

/* Block signals for system '<S7>/StateFlowFunctions.MaintainHeading' */
typedef struct {
  real_T Add;                          /* '<S125>/Add' */
  real_T Constant1;                    /* '<S125>/Constant1' */
  real_T Add_o;                        /* '<S124>/Add' */
  real_T Constant1_e;                  /* '<S124>/Constant1' */
  int8_T DoubleToint1;                 /* '<S37>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S37>/DoubleToint8' */
} rtB_StateFlowFunctionsMaintainH;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.MaintainHeading' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S127>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S126>/Heading Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsMaintainHea_e;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainHea_m;/* '<Root>/StateFlow Functions' */
  int8_T If_ActiveSubsystem;           /* '<S37>/If' */
} rtDW_StateFlowFunctionsMaintain;

/* Block signals for system '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats' */
typedef struct {
  real_T Constant;                     /* '<S11>/Constant' */
  real_T Constant2;                    /* '<S11>/Constant2' */
  real_T Constant1;                    /* '<S11>/Constant1' */
} rtB_StateFlowFunctionsBuoysAp_b;

/* Block signals for system '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
typedef struct {
  real_T Image;                        /* '<S128>/CheckConditions' */
  boolean_T BW[19200];                 /* '<S128>/Logical Operator1' */
} rtB_StateFlowFunctionsValidatio;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
typedef struct {
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S128>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S128>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S128>/Blob Analysis' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S128>/Blob Analysis' */
} rtDW_StateFlowFunctionsValidati;

/* Block signals for system '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
typedef struct {
  int8_T DoubleToInt1;                 /* '<S20>/Double To Int1' */
  int8_T DoubleToInt8;                 /* '<S20>/Double To Int8' */
} rtB_StateFlowFunctionsFollowOne;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S77>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S76>/Depth Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsFollowOnePa_j;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOneP_iz;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsFollowOn;

/* Block signals for system '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
typedef struct {
  real_T DrawMarkers[19200];           /* '<S22>/Draw Markers' */
  real_T Subtract;                     /* '<S22>/Subtract' */
  real_T Subtract1;                    /* '<S22>/Subtract1' */
  int8_T DataTypeConversion;           /* '<S83>/Data Type Conversion' */
  int8_T DataTypeConversion_f;         /* '<S84>/Data Type Conversion' */
  boolean_T ImageDataTypeConversion[19200];/* '<S22>/Image Data Type Conversion' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S22>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsFollowO_k;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
typedef struct {
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S22>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S22>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S22>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S22>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S86>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S85>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S88>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S87>/Y-Buoy Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsFollowOnePa_g;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOnePa_l;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsFollow_g;

/* Block signals for system '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation' */
typedef struct {
  real_T ColorSpaceConversion1_o1;     /* '<S110>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2;     /* '<S110>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3;     /* '<S110>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_o1;      /* '<S110>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2;      /* '<S110>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3;      /* '<S110>/Color Space  Conversion' */
  boolean_T BW[19200];                 /* '<S108>/Relational Operator' */
} rtB_StateFlowFunctionsJumpHedge;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation' */
typedef struct {
  real_T ColorSpaceConversion_DWORK1;  /* '<S110>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1; /* '<S110>/Color Space  Conversion1' */
} rtDW_StateFlowFunctionsJumpHedg;

/* Block signals for system '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw' */
typedef struct {
  real_T DrawMarkers[19200];           /* '<S27>/Draw Markers' */
  real_T Add;                          /* '<S101>/Add' */
  real_T Add1;                         /* '<S101>/Add1' */
  real_T ImageDataTypeConversion1[19200];/* '<S27>/Image Data Type Conversion1' */
  int8_T DataTypeConversion;           /* '<S102>/Data Type Conversion' */
  boolean_T Erosion[19200];            /* '<S27>/Erosion' */
  boolean_T ImageDataTypeConversion[19200];/* '<S27>/Image Data Type Conversion' */
  boolean_T Dilation[19200];           /* '<S27>/Dilation' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S27>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsJumpHed_b;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw' */
typedef struct {
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S27>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S27>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S27>/Buoy Blob Analysis' */
  boolean_T Erosion_ONE_PAD_IMG_DW[21209];/* '<S27>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW[21209];/* '<S27>/Erosion' */
  boolean_T Dilation_ONE_PAD_IMG_DW[20049];/* '<S27>/Dilation' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S27>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S104>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S103>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_a;                  /* '<S106>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S105>/Y-Buoy Discrete-Time Integrator' */
  int32_T Dilation_NUMNONZ_DW;         /* '<S27>/Dilation' */
  int32_T Dilation_STREL_DW;           /* '<S27>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW[4];   /* '<S27>/Dilation' */
  int32_T Erosion_NUMNONZ_DW[2];       /* '<S27>/Erosion' */
  int32_T Erosion_STREL_DW[2];         /* '<S27>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[8];     /* '<S27>/Erosion' */
  uint32_T StateFlowFunctionsJumpHedgeCa_c;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsJumpHedgeCa_l;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsJumpHe_e;

/* Block signals for system '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio' */
typedef struct {
  real_T AxisRatio;                    /* '<S28>/Embedded MATLAB Function' */
  boolean_T ImageDataTypeConversion[19200];/* '<S28>/Image Data Type Conversion' */
} rtB_StateFlowFunctionsJumpHed_m;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio' */
typedef struct {
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S28>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S28>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S28>/Blob Analysis' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S28>/Blob Analysis' */
} rtDW_StateFlowFunctionsJumpHe_j;

/* Block signals for system '<S7>/StateManagement.Running.Autonomous.Perform' */
typedef struct {
  real_T Done1;                        /* '<S40>/Checking to see if state will be performed' */
} rtB_StateManagementRunningAuton;

/* Block signals (auto storage) */
typedef struct {
  real_T eml_HoughTable[71820];
  real_T DesiredDepth;                 /* '<Root>/StateFlow Functions' */
  real_T DesiredHeading;               /* '<Root>/StateFlow Functions' */
  real_T BuoyCentroidX;                /* '<Root>/StateFlow Functions' */
  real_T BuoyCentroidY;                /* '<Root>/StateFlow Functions' */
  real_T BWout[19200];                 /* '<Root>/StateFlow Functions' */
  real_T RGBout[57600];                /* '<Root>/StateFlow Functions' */
  real_T LabMatrix[19200];             /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors[150];              /* '<Root>/StateFlow Functions' */
  real_T Num_Colors;                   /* '<Root>/StateFlow Functions' */
  real_T B_Hue;                        /* '<Root>/StateFlow Functions' */
  real_T B_Sat;                        /* '<Root>/StateFlow Functions' */
  real_T B_Value;                      /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_b[19200];           /* '<Root>/StateFlow Functions' */
  real_T num_colors;                   /* '<Root>/StateFlow Functions' */
  real_T RGBin[57600];                 /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_d[19200];           /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_b[150];            /* '<Root>/StateFlow Functions' */
  real_T H[19200];                     /* '<Root>/StateFlow Functions' */
  real_T S[19200];                     /* '<Root>/StateFlow Functions' */
  real_T V[19200];                     /* '<Root>/StateFlow Functions' */
  real_T LabelMatrix[19200];           /* '<Root>/StateFlow Functions' */
  real_T ref_colors[150];              /* '<Root>/StateFlow Functions' */
  real_T num_colors_e;                 /* '<Root>/StateFlow Functions' */
  real_T DesiredHeading1;              /* '<Root>/StateFlow Functions' */
  real_T CurrentHeading1;              /* '<Root>/StateFlow Functions' */
  real_T ForwardVelocity1;             /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_b3[19200];          /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_a[150];            /* '<Root>/StateFlow Functions' */
  real_T Num_Colors_b;                 /* '<Root>/StateFlow Functions' */
  real_T B_Hue_c;                      /* '<Root>/StateFlow Functions' */
  real_T B_Sat_k;                      /* '<Root>/StateFlow Functions' */
  real_T B_Value_c;                    /* '<Root>/StateFlow Functions' */
  real_T buoys[200];                   /* '<Root>/StateFlow Functions' */
  real_T num_blobs;                    /* '<Root>/StateFlow Functions' */
  real_T H_c[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_n[19200];                   /* '<Root>/StateFlow Functions' */
  real_T HeadingAlong;                 /* '<Root>/StateFlow Functions' */
  real_T Forward1;                     /* '<Root>/StateFlow Functions' */
  real_T BW[19200];                    /* '<Root>/StateFlow Functions' */
  real_T H_e[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_o[19200];                   /* '<Root>/StateFlow Functions' */
  real_T BW_p[19200];                  /* '<Root>/StateFlow Functions' */
  real_T H_f[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_h[19200];                   /* '<Root>/StateFlow Functions' */
  real_T H1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T S1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T V1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T BW_l[19200];                  /* '<Root>/StateFlow Functions' */
  real_T BW_n[19200];                  /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_p[19200];           /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_i[150];            /* '<Root>/StateFlow Functions' */
  real_T Num_Colors_a;                 /* '<Root>/StateFlow Functions' */
  real_T B_Hue_b;                      /* '<Root>/StateFlow Functions' */
  real_T B_Sat_j;                      /* '<Root>/StateFlow Functions' */
  real_T B_Value_k;                    /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_c[19200];           /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_f[150];            /* '<Root>/StateFlow Functions' */
  real_T H_fu[19200];                  /* '<Root>/StateFlow Functions' */
  real_T S_a[19200];                   /* '<Root>/StateFlow Functions' */
  real_T V_p[19200];                   /* '<Root>/StateFlow Functions' */
  real_T BW_p3[19200];                 /* '<Root>/StateFlow Functions' */
  real_T ForwardVelocity;              /* '<Root>/StateFlow Functions' */
  real_T BW_g[19200];                  /* '<Root>/StateFlow Functions' */
  real_T State1;                       /* '<Root>/StateFlow Functions' */
  real_T HeadingForwardVelocity;       /* '<S29>/Heading Forward Velocity' */
  real_T HedgeHue;                     /* '<S32>/Hedge Hue' */
  real_T HedgeSaturation;              /* '<S32>/Hedge Saturation' */
  real_T HedgeValue;                   /* '<S32>/Hedge Value' */
  real_T HoughTransform_o1[71820];     /* '<S33>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S33>/Hough Transform' */
  real_T HoughTransform_o3[399];       /* '<S33>/Hough Transform' */
  real_T DrawShapes[19200];            /* '<S33>/Draw Shapes' */
  real_T Image;                        /* '<S33>/Are 3 Lines Present' */
  real_T BlobArea;                     /* '<S26>/Embedded MATLAB Function' */
  real_T HSVImage1[57600];             /* '<S19>/PutHSVImageTogether' */
  real_T HoughTransform_o1_n[71820];   /* '<S79>/Hough Transform' */
  real_T HoughTransform_o2_e[180];     /* '<S79>/Hough Transform' */
  real_T HoughTransform_o3_n[399];     /* '<S79>/Hough Transform' */
  real_T DrawShapes_m[19200];          /* '<S21>/Draw Shapes' */
  real_T Theta[2];                     /* '<S79>/IsLinePresent' */
  real_T Rho[2];                       /* '<S79>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S79>/IsLinePresent' */
  real_T AlongPathHeading;             /* '<S21>/GetHeadingToPath' */
  real_T Constant;                     /* '<S25>/Constant' */
  real_T HeadingForwardVelocity_o;     /* '<S38>/Heading Forward Velocity' */
  real_T Constant_p;                   /* '<S12>/Constant' */
  real_T ColorSpaceConversion1_o1;     /* '<S41>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2;     /* '<S41>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3;     /* '<S41>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o1_n;   /* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_i;   /* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_m;   /* '<S43>/Color Space  Conversion1' */
  real_T Direction1;                   /* '<S9>/GetBestColorMatch' */
  real_T Direction2;                   /* '<S9>/GetBestColorMatch' */
  real_T Constant_l;                   /* '<S16>/Constant' */
  real_T ColorSpaceConversion1_o1_d;   /* '<S58>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_k;   /* '<S58>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_e;   /* '<S58>/Color Space  Conversion1' */
  real_T DrawMarkers[19200];           /* '<S13>/Draw Markers' */
  real_T Image_g;                      /* '<S13>/IF Buoy Conditions' */
  real_T Constant_k;                   /* '<S8>/Constant' */
  real_T Constant2;                    /* '<S8>/Constant2' */
  real_T Constant1;                    /* '<S8>/Constant1' */
  real_T ColorSpaceConversion_o1;      /* '<S58>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2;      /* '<S58>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3;      /* '<S58>/Color Space  Conversion' */
  real_T ImageDataTypeConversion[19200];/* '<S13>/Image Data Type Conversion' */
  real_T ColorSpaceConversion_o3_c;    /* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2_o;    /* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o1_g;    /* '<S43>/Color Space  Conversion' */
  real32_T Resize[19200];              /* '<S5>/Resize' */
  real32_T Resize1[19200];             /* '<S5>/Resize1' */
  real32_T Resize2[19200];             /* '<S5>/Resize2' */
  real32_T CurrentDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T DesiredDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  int32_T HoughLines[12];              /* '<S33>/Hough Lines' */
  int32_T HoughLines_a[8];             /* '<S21>/Hough Lines' */
  int8_T Left;                         /* '<Root>/StateFlow Functions' */
  int8_T Right;                        /* '<Root>/StateFlow Functions' */
  int8_T Strafe;                       /* '<Root>/StateFlow Functions' */
  int8_T Vertical;                     /* '<Root>/StateFlow Functions' */
  int8_T CameraPosition;               /* '<Root>/StateFlow Functions' */
  int8_T State;                        /* '<Root>/StateFlow Functions' */
  int8_T DoubleToInt8;                 /* '<S36>/Double To Int8' */
  uint8_T RGBVid_R[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T ChromaResampling_o1[307200]; /* '<S5>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S5>/Chroma Resampling' */
  boolean_T BW_m[19200];               /* '<S89>/Logical Operator1' */
  boolean_T Erosion[19200];            /* '<S26>/Erosion' */
  boolean_T DataTypeConversion[19200]; /* '<S89>/Data Type Conversion' */
  boolean_T ImageDataTypeConversion_e[19200];/* '<S33>/Image Data Type Conversion' */
  boolean_T Erosion_g[19200];          /* '<S33>/Erosion' */
  boolean_T ImageDataTypeConversion_d[19200];/* '<S26>/Image Data Type Conversion' */
  boolean_T Dilation[19200];           /* '<S26>/Dilation' */
  boolean_T Erosion_m[19200];          /* '<S89>/Erosion' */
  boolean_T ImageDataTypeConversion_p[19200];/* '<S21>/Image Data Type Conversion' */
  boolean_T BW_f[19200];               /* '<S56>/Relational Operator' */
  rtB_StateManagementRunningAuton StateManagementRunningAutonom_j;/* '<S7>/StateManagement.Running.Autonomous.Perform' */
  rtB_StateFlowFunctionsJumpHed_m StateFlowFunctionsJumpHedgeGe_k;/* '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio' */
  rtB_StateFlowFunctionsJumpHed_b StateFlowFunctionsJumpHedgeCa_p;/* '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw' */
  rtB_StateFlowFunctionsBuoysIter StateFlowFunctionsJumpHedgeIter;/* '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation' */
  rtB_StateFlowFunctionsBuoysShow StateFlowFunctionsJumpHedgeShow;/* '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage' */
  rtB_StateFlowFunctionsJumpHedge StateFlowFunctionsJumpHedgeIn_m;/* '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation' */
  rtB_StateFlowFunctionsValidatio StateFlowFunctionsFollowOnePa_l;/* '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack' */
  rtB_StateFlowFunctionsFollowO_k StateFlowFunctionsFollowOneP_iq;/* '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
  rtB_StateFlowFunctionsFollowOne StateFlowFunctionsFollowOnePa_k;/* '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
  rtB_StateFlowFunctionsValidatio StateFlowFunctionsValidationG_a;/* '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
  rtB_StateFlowFunctionsBuoysAp_b StateFlowFunctionsBuoysAppro_hj;/* '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats' */
  rtB_StateFlowFunctionsMaintainH StateFlowFunctionsMaintainHea_d;/* '<S7>/StateFlowFunctions.MaintainHeading' */
  rtB_StateFlowFunctionsBuoysFi_d StateFlowFunctionsBuoysFindB_ls;/* '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors' */
  rtB_StateFlowFunctionsBuoysIter StateFlowFunctionsBuoysIterat_g;/* '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation' */
  rtB_StateFlowFunctionsBuoysShow StateFlowFunctionsBuoysShowSe_o;/* '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage' */
  rtB_StateFlowFunctionsBuoysFind StateFlowFunctionsBuoysFindB_ln;/* '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
  rtB_StateFlowFunctionsBuoysAppr StateFlowFunctionsBuoysApproa_l;/* '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Resize_IntBuffer[76800];    /* '<S5>/Resize' */
  real32_T Resize1_IntBuffer[76800];   /* '<S5>/Resize1' */
  real32_T Resize2_IntBuffer[76800];   /* '<S5>/Resize2' */
  uint32_T BuoyBlobAnalysis_STACK_DW_g[19200];/* '<S13>/Buoy Blob Analysis' */
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S26>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW_k[19200];/* '<S13>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW_m[19200];/* '<S13>/Buoy Blob Analysis' */
  boolean_T Erosion_ONE_PAD_IMG_DW_k[21209];/* '<S89>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW_h[21209];/* '<S89>/Erosion' */
  boolean_T Erosion_ONE_PAD_IMG_DW_a[21209];/* '<S26>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW[21209];/* '<S26>/Erosion' */
  boolean_T Erosion_ONE_PAD_IMG_DW[20295];/* '<S33>/Erosion' */
  boolean_T Dilation_ONE_PAD_IMG_DW[20049];/* '<S26>/Dilation' */
  uint8_T BuoyBlobAnalysis_PAD_DW_h[19764];/* '<S13>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S26>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S123>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S122>/Depth Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/StateFlow Functions' */
  real_T countarea;                    /* '<Root>/StateFlow Functions' */
  real_T DesiredHeadingCount;          /* '<Root>/StateFlow Functions' */
  real_T OldHeading;                   /* '<Root>/StateFlow Functions' */
  real_T TrackCount;                   /* '<Root>/StateFlow Functions' */
  real_T BuoyCount;                    /* '<Root>/StateFlow Functions' */
  real_T HeadingAlongPath;             /* '<Root>/StateFlow Functions' */
  real_T Done;                         /* '<Root>/StateFlow Functions' */
  real_T Error;                        /* '<Root>/StateFlow Functions' */
  real_T Forward;                      /* '<Root>/StateFlow Functions' */
  real_T BuoyHue;                      /* '<Root>/StateFlow Functions' */
  real_T BuoySaturation;               /* '<Root>/StateFlow Functions' */
  real_T BuoyValue;                    /* '<Root>/StateFlow Functions' */
  real_T FirstDir;                     /* '<Root>/StateFlow Functions' */
  real_T Image;                        /* '<Root>/StateFlow Functions' */
  real_T LabelMatrix[19200];           /* '<Root>/StateFlow Functions' */
  real_T SecondDir;                    /* '<Root>/StateFlow Functions' */
  real_T TurnDirection;                /* '<Root>/StateFlow Functions' */
  real_T count2ndarea;                 /* '<Root>/StateFlow Functions' */
  real_T num_colors;                   /* '<Root>/StateFlow Functions' */
  real_T ref_colors[150];              /* '<Root>/StateFlow Functions' */
  real_T num_blobs;                    /* '<Root>/StateFlow Functions' */
  real_T BuoyBlobs[200];               /* '<Root>/StateFlow Functions' */
  real_T H_Hue;                        /* '<Root>/StateFlow Functions' */
  real_T H_Sat;                        /* '<Root>/StateFlow Functions' */
  real_T H_Value;                      /* '<Root>/StateFlow Functions' */
  real_T MoveOn;                       /* '<Root>/StateFlow Functions' */
  real_T NewAxisRatio;                 /* '<Root>/StateFlow Functions' */
  real_T OldAxisRatio;                 /* '<Root>/StateFlow Functions' */
  real_T StrafeDir;                    /* '<Root>/StateFlow Functions' */
  real_T Heading1;                     /* '<Root>/StateFlow Functions' */
  real_T Heading2;                     /* '<Root>/StateFlow Functions' */
  real_T Heading3;                     /* '<Root>/StateFlow Functions' */
  real_T Heading4;                     /* '<Root>/StateFlow Functions' */
  real_T OldDesiredHeading;            /* '<Root>/StateFlow Functions' */
  real_T ColorSpaceConversion_DWORK1;  /* '<S41>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1; /* '<S41>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_g;/* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1_e;/* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_b;/* '<S58>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1_l;/* '<S58>/Color Space  Conversion1' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  int32_T Area;                        /* '<Root>/StateFlow Functions' */
  int32_T Erosion_NUMNONZ_DW;          /* '<S33>/Erosion' */
  int32_T Erosion_STREL_DW;            /* '<S33>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[6];     /* '<S33>/Erosion' */
  int32_T Dilation_NUMNONZ_DW;         /* '<S26>/Dilation' */
  int32_T Dilation_STREL_DW;           /* '<S26>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW[4];   /* '<S26>/Dilation' */
  int32_T Erosion_NUMNONZ_DW_j[2];     /* '<S26>/Erosion' */
  int32_T Erosion_STREL_DW_g[2];       /* '<S26>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW_i[8];   /* '<S26>/Erosion' */
  int32_T Erosion_NUMNONZ_DW_f[2];     /* '<S89>/Erosion' */
  int32_T Erosion_STREL_DW_a[2];       /* '<S89>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW_l[8];   /* '<S89>/Erosion' */
  uint32_T presentTicks;               /* '<Root>/StateFlow Functions' */
  uint32_T elapsedTicks;               /* '<Root>/StateFlow Functions' */
  uint32_T previousTicks;              /* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainDepth;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainDep_k;/* '<Root>/StateFlow Functions' */
  int8_T OperationalState;             /* '<Root>/StateFlow Functions' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateFlowFunctions;/* '<Root>/StateFlow Functions' */
  uint8_T is_StateFlowFunctions;       /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateManagement;   /* '<Root>/StateFlow Functions' */
  uint8_T is_StateManagement;          /* '<Root>/StateFlow Functions' */
  uint8_T is_Buoys;                    /* '<Root>/StateFlow Functions' */
  uint8_T is_ApproachBuoys;            /* '<Root>/StateFlow Functions' */
  uint8_T is_ValidationGate;           /* '<Root>/StateFlow Functions' */
  uint8_T is_Autonomous;               /* '<Root>/StateFlow Functions' */
  uint8_T was_Autonomous;              /* '<Root>/StateFlow Functions' */
  uint8_T is_Running;                  /* '<Root>/StateFlow Functions' */
  uint8_T is_Start;                    /* '<Root>/StateFlow Functions' */
  uint8_T is_FollowOnePath;            /* '<Root>/StateFlow Functions' */
  uint8_T is_OnePath;                  /* '<Root>/StateFlow Functions' */
  uint8_T is_RecognizePath;            /* '<Root>/StateFlow Functions' */
  uint8_T is_JumpHedge;                /* '<Root>/StateFlow Functions' */
  uint8_T is_IncreaseAxisRatio;        /* '<Root>/StateFlow Functions' */
  uint8_T is_GetInitialDirection;      /* '<Root>/StateFlow Functions' */
  uint8_T is_LocatePinger;             /* '<Root>/StateFlow Functions' */
  uint8_T is_Breach;                   /* '<Root>/StateFlow Functions' */
  uint8_T is_GetPingerHeading;         /* '<Root>/StateFlow Functions' */
  uint8_T temporalCounter_i1;          /* '<Root>/StateFlow Functions' */
  boolean_T Obstacle;                  /* '<Root>/StateFlow Functions' */
  boolean_T OldObstacle;               /* '<Root>/StateFlow Functions' */
  rtDW_StateFlowFunctionsJumpHe_j StateFlowFunctionsJumpHedgeGe_k;/* '<S7>/StateFlowFunctions.JumpHedge.GetAxisRatio' */
  rtDW_StateFlowFunctionsJumpHe_e StateFlowFunctionsJumpHedgeCa_p;/* '<S7>/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw' */
  rtDW_StateFlowFunctionsBuoysIte StateFlowFunctionsJumpHedgeIter;/* '<S7>/StateFlowFunctions.JumpHedge.IterativeSegmentation' */
  rtDW_StateFlowFunctionsBuoysSho StateFlowFunctionsJumpHedgeShow;/* '<S7>/StateFlowFunctions.JumpHedge.ShowSegmentedImage' */
  rtDW_StateFlowFunctionsJumpHedg StateFlowFunctionsJumpHedgeIn_m;/* '<S7>/StateFlowFunctions.JumpHedge.IndividualSegmentation' */
  rtDW_StateFlowFunctionsValidati StateFlowFunctionsFollowOnePa_l;/* '<S7>/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack' */
  rtDW_StateFlowFunctionsFollow_g StateFlowFunctionsFollowOneP_iq;/* '<S7>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
  rtDW_StateFlowFunctionsFollowOn StateFlowFunctionsFollowOnePa_k;/* '<S7>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
  rtDW_StateFlowFunctionsValidati StateFlowFunctionsValidationG_a;/* '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
  rtDW_StateFlowFunctionsMaintain StateFlowFunctionsMaintainHea_d;/* '<S7>/StateFlowFunctions.MaintainHeading' */
  rtDW_StateFlowFunctionsBuoysF_e StateFlowFunctionsBuoysFindB_ls;/* '<S7>/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors' */
  rtDW_StateFlowFunctionsBuoysIte StateFlowFunctionsBuoysIterat_g;/* '<S7>/StateFlowFunctions.Buoys.IterativeSegmentation' */
  rtDW_StateFlowFunctionsBuoysSho StateFlowFunctionsBuoysShowSe_o;/* '<S7>/StateFlowFunctions.Buoys.ShowSegmentedImage' */
  rtDW_StateFlowFunctionsBuoysFin StateFlowFunctionsBuoysFindB_ln;/* '<S7>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
  rtDW_StateFlowFunctionsBuoysApp StateFlowFunctionsBuoysApproa_l;/* '<S7>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/Hough Transform'
   *   '<S79>/Hough Transform'
   */
  real_T pooled18[91];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/Hough Transform'
   *   '<S79>/Hough Transform'
   */
  real_T pooled19;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/Resize'
   *   '<S71>/Resize1'
   *   '<S71>/Resize2'
   *   '<S118>/Resize'
   *   '<S118>/Resize1'
   *   '<S118>/Resize2'
   */
  real32_T pooled22[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/Resize'
   *   '<S71>/Resize1'
   *   '<S71>/Resize2'
   *   '<S118>/Resize'
   *   '<S118>/Resize1'
   *   '<S118>/Resize2'
   */
  real32_T pooled23[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  real32_T pooled25[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  real32_T pooled26[1280];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/Buoy Blob Analysis'
   *   '<S13>/Buoy Blob Analysis'
   *   '<S22>/Buoy Blob Analysis'
   *   '<S26>/Buoy Blob Analysis'
   *   '<S27>/Buoy Blob Analysis'
   *   '<S28>/Blob Analysis'
   *   '<S93>/Blob Analysis'
   *   '<S128>/Blob Analysis'
   */
  int32_T pooled27[8];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/Resize'
   *   '<S71>/Resize1'
   *   '<S71>/Resize2'
   *   '<S118>/Resize'
   *   '<S118>/Resize1'
   *   '<S118>/Resize2'
   */
  int32_T pooled29[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/Resize'
   *   '<S71>/Resize1'
   *   '<S71>/Resize2'
   *   '<S118>/Resize'
   *   '<S118>/Resize1'
   *   '<S118>/Resize2'
   */
  int32_T pooled30[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  int32_T pooled33[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  int32_T pooled34[1280];

  /* Pooled Parameter (Expression: nhood)
   * Referenced by:
   *   '<S26>/Erosion'
   *   '<S27>/Erosion'
   *   '<S89>/Erosion'
   */
  boolean_T pooled35[8];

  /* Pooled Parameter (Expression: nhood)
   * Referenced by:
   *   '<S26>/Dilation'
   *   '<S27>/Dilation'
   */
  boolean_T pooled36[4];

  /* Expression: nhood
   * Referenced by: '<S33>/Erosion'
   */
  boolean_T Erosion_NHOOD_RTP[6];
} ConstParam_brain;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T CurrentDepth;                 /* '<Root>/CurrentDepth' */
  real_T CurrentHeading;               /* '<Root>/CurrentHeading' */
  uint8_T Y[307200];                   /* '<Root>/Y' */
  uint8_T Cb[76800];                   /* '<Root>/Cb' */
  uint8_T Cr[76800];                   /* '<Root>/Cr' */
  int8_T Status;                       /* '<Root>/Status' */
  int8_T DesiredState;                 /* '<Root>/DesiredState' */
  real_T RC_Heading;                   /* '<Root>/RC_Heading' */
  real_T RC_ForwardVelocity;           /* '<Root>/RC_ForwardVelocity' */
  real_T RC_Strafe;                    /* '<Root>/RC_Strafe' */
  real_T RC_Depth;                     /* '<Root>/RC_Depth' */
  boolean_T RC;                        /* '<Root>/RC' */
} ExternalInputs_brain;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int8_T CameraPosition;               /* '<Root>/CameraPosition' */
  real_T BuoyCentroidX;                /* '<Root>/BuoyCentroidX' */
  real_T BuoyCentroidY;                /* '<Root>/BuoyCentroidY' */
  real_T Thrusters[4];                 /* '<Root>/Thrusters' */
  int8_T State;                        /* '<Root>/State' */
  real_T DesiredDepth;                 /* '<Root>/DesiredDepth' */
  real_T DesiredHeading;               /* '<Root>/DesiredHeading' */
  real_T BWout[19200];                 /* '<Root>/BWout' */
  real_T RGBout[57600];                /* '<Root>/RGBout' */
} ExternalOutputs_brain;

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy1_Hue;                    /* Variable: Buoy1_Hue
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S41>/Constant'
                                        */
  real_T Buoy1_Saturation;             /* Variable: Buoy1_Saturation
                                        * Referenced by:
                                        *   '<S8>/Constant2'
                                        *   '<S41>/Constant2'
                                        */
  real_T Buoy1_Value;                  /* Variable: Buoy1_Value
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S41>/Constant1'
                                        */
  real_T Buoy2_Hue;                    /* Variable: Buoy2_Hue
                                        * Referenced by:
                                        *   '<S11>/Constant'
                                        *   '<S43>/Constant'
                                        */
  real_T Buoy2_Saturation;             /* Variable: Buoy2_Saturation
                                        * Referenced by:
                                        *   '<S11>/Constant2'
                                        *   '<S43>/Constant2'
                                        */
  real_T Buoy2_Value;                  /* Variable: Buoy2_Value
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S43>/Constant1'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * Referenced by:
                                        *   '<S13>/Constant2'
                                        *   '<S14>/Constant1'
                                        *   '<S15>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * Referenced by:
                                        *   '<S13>/Constant4'
                                        *   '<S14>/Constant3'
                                        *   '<S15>/Constant3'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S14>/Constant'
                                        *   '<S15>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * Referenced by:
                                        *   '<S13>/Constant3'
                                        *   '<S14>/Constant2'
                                        *   '<S15>/Constant2'
                                        */
  real_T Buoy_Strafe;                  /* Variable: Buoy_Strafe
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Cam_Down_Strafe_XPos_Kd;      /* Variable: Cam_Down_Strafe_XPos_Kd
                                        * Referenced by: '<S85>/CamDown Strafe XPos Derivative Gain'
                                        */
  real_T Cam_Down_Strafe_XPos_Ki;      /* Variable: Cam_Down_Strafe_XPos_Ki
                                        * Referenced by: '<S85>/CamDown Strafe XPos Integral Gain'
                                        */
  real_T Cam_Down_Strafe_XPos_Kp;      /* Variable: Cam_Down_Strafe_XPos_Kp
                                        * Referenced by: '<S85>/CamDown Strafe XPos Proportional Gain'
                                        */
  real_T Cam_Down_YPos_Kd;             /* Variable: Cam_Down_YPos_Kd
                                        * Referenced by: '<S87>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_YPos_Ki;             /* Variable: Cam_Down_YPos_Ki
                                        * Referenced by: '<S87>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Down_YPos_Kp;             /* Variable: Cam_Down_YPos_Kp
                                        * Referenced by: '<S87>/Y-Buoy Proportional Gain'
                                        */
  real_T Cam_Down_Yaw_XPos_Kd;         /* Variable: Cam_Down_Yaw_XPos_Kd
                                        * Referenced by: '<S76>/CamDownYaw-X Derivative Gain'
                                        */
  real_T Cam_Down_Yaw_XPos_Ki;         /* Variable: Cam_Down_Yaw_XPos_Ki
                                        * Referenced by: '<S76>/CamDownYaw-X Integral Gain'
                                        */
  real_T Cam_Down_Yaw_XPos_Kp;         /* Variable: Cam_Down_Yaw_XPos_Kp
                                        * Referenced by: '<S76>/CamDownYaw-X Proportional Gain'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * Referenced by:
                                        *   '<S51>/X-Buoy Derivative Gain'
                                        *   '<S103>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * Referenced by:
                                        *   '<S51>/X-Buoy Integral Gain'
                                        *   '<S103>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * Referenced by:
                                        *   '<S51>/X-Buoy Proportional Gain'
                                        *   '<S103>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * Referenced by:
                                        *   '<S53>/Y-Buoy Derivative Gain'
                                        *   '<S105>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * Referenced by:
                                        *   '<S53>/Y-Buoy Integral Gain'
                                        *   '<S105>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * Referenced by:
                                        *   '<S53>/Y-Buoy Proportional Gain'
                                        *   '<S105>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by: '<S122>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by: '<S122>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by: '<S122>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by:
                                        *   '<S16>/Constant'
                                        *   '<S38>/Heading Forward Velocity'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by: '<S126>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by: '<S126>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by: '<S126>/Heading Proportional Gain'
                                        */
  real_T Hedge_Hue;                    /* Variable: Hedge_Hue
                                        * Referenced by: '<S32>/Hedge Hue'
                                        */
  real_T Hedge_Saturation;             /* Variable: Hedge_Saturation
                                        * Referenced by: '<S32>/Hedge Saturation'
                                        */
  real_T Hedge_Value;                  /* Variable: Hedge_Value
                                        * Referenced by: '<S32>/Hedge Value'
                                        */
  real_T Iter_Segment_Thresh;          /* Variable: Iter_Segment_Thresh
                                        * Referenced by:
                                        *   '<S65>/Dist_Thresh'
                                        *   '<S112>/Dist_Thresh'
                                        */
  real_T MissionPlan[20];              /* Variable: MissionPlan
                                        * Referenced by: '<S40>/Mission Plan'
                                        */
  real_T Track_Desired_Depth;          /* Variable: Track_Desired_Depth
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * Referenced by:
                                        *   '<S90>/Constant'
                                        *   '<S95>/Constant'
                                        *   '<S130>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * Referenced by:
                                        *   '<S91>/Constant'
                                        *   '<S96>/Constant'
                                        *   '<S131>/Constant'
                                        */
  real_T Track_Min_Eccentricity;       /* Variable: Track_Min_Eccentricity
                                        * Referenced by:
                                        *   '<S93>/Constant'
                                        *   '<S128>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * Referenced by:
                                        *   '<S92>/Constant'
                                        *   '<S97>/Constant'
                                        *   '<S132>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by:
                                        *   '<S29>/Heading Forward Velocity'
                                        *   '<S47>/Vision_Forward_Velocity'
                                        *   '<S47>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by:
                                        *   '<S10>/Buoy Blob Analysis'
                                        *   '<S13>/Buoy Blob Analysis'
                                        *   '<S22>/Buoy Blob Analysis'
                                        *   '<S26>/Buoy Blob Analysis'
                                        *   '<S27>/Buoy Blob Analysis'
                                        *   '<S93>/Blob Analysis'
                                        *   '<S128>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by:
                                        *   '<S10>/Buoy Blob Analysis'
                                        *   '<S13>/Buoy Blob Analysis'
                                        *   '<S22>/Buoy Blob Analysis'
                                        *   '<S26>/Buoy Blob Analysis'
                                        *   '<S27>/Buoy Blob Analysis'
                                        *   '<S93>/Blob Analysis'
                                        *   '<S128>/Blob Analysis'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_brain {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_brain brain_P;

/* Block signals (auto storage) */
extern BlockIO_brain brain_B;

/* Block states (auto storage) */
extern D_Work_brain brain_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_brain brain_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_brain brain_Y;

/* Constant parameters (auto storage) */
extern const ConstParam_brain brain_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void brain_initialize(void);
  extern void brain_step(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_brain *brain_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : brain
 * '<S1>'   : brain/Environment Controller
 * '<S2>'   : brain/Environment Controller1
 * '<S3>'   : brain/Environment Controller2
 * '<S4>'   : brain/Environment Controller3
 * '<S5>'   : brain/GetVideo1
 * '<S6>'   : brain/Normalize Thrusters to 1
 * '<S7>'   : brain/StateFlow Functions
 * '<S8>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats
 * '<S9>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach
 * '<S10>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy
 * '<S11>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats
 * '<S12>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe
 * '<S13>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy
 * '<S14>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors
 * '<S15>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys
 * '<S16>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.GetBuoyForwardVelocity
 * '<S17>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation
 * '<S18>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage
 * '<S19>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage
 * '<S20>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align
 * '<S21>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings
 * '<S22>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe
 * '<S23>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation
 * '<S24>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack
 * '<S25>'  : brain/StateFlow Functions/StateFlowFunctions.GetDesiredDepth
 * '<S26>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea
 * '<S27>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw
 * '<S28>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.GetAxisRatio
 * '<S29>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.GetForwardVelocity
 * '<S30>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation
 * '<S31>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation
 * '<S32>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.RecognizeHedge.GetHedgeValues
 * '<S33>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge
 * '<S34>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.ShowSegmentedImage
 * '<S35>'  : brain/StateFlow Functions/StateFlowFunctions.LocatePinger.GetPingerHeading.GetHeadings
 * '<S36>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth
 * '<S37>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading
 * '<S38>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity
 * '<S39>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack
 * '<S40>'  : brain/StateFlow Functions/StateManagement.Running.Autonomous.Perform
 * '<S41>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/FirstBuoy Info
 * '<S42>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch
 * '<S43>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/Second Buoy Info
 * '<S44>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function
 * '<S45>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function1
 * '<S46>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image
 * '<S47>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl
 * '<S48>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl
 * '<S49>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Choose Closest Color
 * '<S50>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Get Desired Color
 * '<S51>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl/PID Controller X Position
 * '<S52>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S53>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S54>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S55>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/IF Buoy Conditions
 * '<S56>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image
 * '<S57>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Choose Closest Color
 * '<S58>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Get Desired Color
 * '<S59>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Blob Extraction
 * '<S60>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions
 * '<S61>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which
 * '<S62>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/Blob Extraction
 * '<S63>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/IF Buoy Conditions
 * '<S64>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter
 * '<S65>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation
 * '<S66>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S67>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S68>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S69>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/LabSegmentation
 * '<S70>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S71>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Resize
 * '<S72>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function
 * '<S73>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function1
 * '<S74>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S75>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/Embedded MATLAB Function
 * '<S76>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/PID Controller Relative Heading
 * '<S77>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/PID Controller Relative Heading/Depth Discrete Derivative
 * '<S78>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/GetHeadingToPath
 * '<S79>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff
 * '<S80>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff/IsLinePresent
 * '<S81>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function
 * '<S82>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function1
 * '<S83>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control
 * '<S84>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control
 * '<S85>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control/PID Controller X Position
 * '<S86>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S87>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control/PID Controller Y Axis
 * '<S88>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control/PID Controller Y Axis/Y-Buoy Discrete Derivative
 * '<S89>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation
 * '<S90>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Hue Higher Comparison
 * '<S91>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Hue Lower Comparison
 * '<S92>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Saturation Comparison
 * '<S93>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack/LookforTrack
 * '<S94>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack/LookforTrack/CheckConditions
 * '<S95>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S96>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S97>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.RecognizePath.LookforTrack/LookforTrack/Saturation Comparison
 * '<S98>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.ApproachHedge.GetArea/Embedded MATLAB Function
 * '<S99>'  : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Embedded MATLAB Function
 * '<S100>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Embedded MATLAB Function1
 * '<S101>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/X-HeadingControl
 * '<S102>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Y-DepthControl
 * '<S103>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/X-HeadingControl/PID Controller X Position
 * '<S104>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S105>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Y-DepthControl/PID Controller Y Position
 * '<S106>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.CameraForward_CenterOnBlobYaw/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S107>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.GetAxisRatio/Embedded MATLAB Function
 * '<S108>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation/Threshold The Image
 * '<S109>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation/Threshold The Image/Choose Closest Color
 * '<S110>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IndividualSegmentation/Threshold The Image/Get Desired Color
 * '<S111>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Low Pass Filter
 * '<S112>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Segmentation
 * '<S113>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S114>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S115>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S116>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Segmentation/LabSegmentation
 * '<S117>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S118>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.IterativeSegmentation/Segmentation/Resize
 * '<S119>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.RecognizeHedge.LookForHedge/Are 3 Lines Present
 * '<S120>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.ShowSegmentedImage/Embedded MATLAB Function
 * '<S121>' : brain/StateFlow Functions/StateFlowFunctions.JumpHedge.ShowSegmentedImage/Embedded MATLAB Function1
 * '<S122>' : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3
 * '<S123>' : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S124>' : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1
 * '<S125>' : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2
 * '<S126>' : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4
 * '<S127>' : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S128>' : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack
 * '<S129>' : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions
 * '<S130>' : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S131>' : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S132>' : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S133>' : brain/StateFlow Functions/StateManagement.Running.Autonomous.Perform/Checking to see if state will be performed
 */

/*-
 * Requirements for '<Root>': brain
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
