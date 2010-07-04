/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.544
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Sun Jul  4 13:35:43 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Sun Jul  4 13:35:46 2010
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

/* Block signals for system '<S7>/Embedded MATLAB Function1' */
typedef struct {
  real_T XCenter;                      /* '<S7>/Embedded MATLAB Function1' */
  real_T YCenter;                      /* '<S7>/Embedded MATLAB Function1' */
} rtB_EmbeddedMATLABFunction1_bra;

/* Block signals for system '<S4>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
typedef struct {
  real_T ColorSpaceConversion1_o1;     /* '<S35>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2;     /* '<S35>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3;     /* '<S35>/Color Space  Conversion1' */
  real_T Add;                          /* '<S32>/Add' */
  real_T Add1;                         /* '<S32>/Add1' */
  real_T BlobArea;                     /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S7>/Embedded MATLAB Function' */
  real_T ColorSpaceConversion_o1;      /* '<S35>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2;      /* '<S35>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3;      /* '<S35>/Color Space  Conversion' */
  int8_T DataTypeConversion;           /* '<S33>/Data Type Conversion' */
  boolean_T BW[19200];                 /* '<S31>/Relational Operator' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S7>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsBuoysAppr;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
typedef struct {
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S7>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S7>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S7>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S7>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S37>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S36>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S39>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S38>/Y-Buoy Discrete-Time Integrator' */
  real_T ColorSpaceConversion_DWORK1;  /* '<S35>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1; /* '<S35>/Color Space  Conversion1' */
  uint32_T StateFlowFunctionsBuoysApproa_a;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsBuoysApproa_m;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsBuoysApp;

/* Block signals for system '<S4>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
typedef struct {
  boolean_T eml_LogicMatrix[19200];
  real_T Image;                        /* '<S12>/IF Buoy Conditions' */
  real_T Eccent[50];                   /* '<S12>/Blob Extraction' */
  real_T Extent[50];                   /* '<S12>/Blob Extraction' */
  uint8_T TotalNum;                    /* '<S12>/Blob Extraction' */
} rtB_StateFlowFunctionsBuoysFind;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
typedef struct {
  real_T F0_RTP;                       /* '<S12>/Blob Extraction' */
  real_T F1_RTP;                       /* '<S12>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S12>/Blob Extraction' */
  int32_T WALKER_RTP[8];               /* '<S12>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S12>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S12>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S12>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S12>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S12>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S12>/Blob Extraction' */
  boolean_T hblob;                     /* '<S12>/Blob Extraction' */
} rtDW_StateFlowFunctionsBuoysFin;

/* Block signals for system '<S49>/Low Pass Filter' */
typedef struct {
  real32_T fv0[19200];
  real32_T Iout[19200];                /* '<S49>/Low Pass Filter' */
  real32_T eml_Itemp[18644];
} rtB_LowPassFilter_brain;

/* Block signals for system '<S4>/StateFlowFunctions.Buoys.IterativeSegmentation' */
typedef struct {
  real_T ColorSpaceConversion_o1[19200];/* '<S14>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2[19200];/* '<S14>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3[19200];/* '<S14>/Color Space  Conversion' */
  real_T ref_colors[150];              /* '<S50>/Reference Color Selection' */
  real_T num_colors;                   /* '<S50>/Reference Color Selection' */
  real_T LabelMatrix[19200];           /* '<S50>/LabSegmentation' */
  real32_T ColorSpaceConversion1_o1[19200];/* '<S14>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o2[19200];/* '<S14>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o3[19200];/* '<S14>/Color Space  Conversion1' */
  uint32_T eml_LabelMatrix[4800];
  real32_T Resize[4800];               /* '<S56>/Resize' */
  real32_T Resize1[4800];              /* '<S56>/Resize1' */
  real32_T Resize2[4800];              /* '<S56>/Resize2' */
  rtB_LowPassFilter_brain sf_LowPassFilter2;/* '<S49>/Low Pass Filter2' */
  rtB_LowPassFilter_brain sf_LowPassFilter1;/* '<S49>/Low Pass Filter1' */
  rtB_LowPassFilter_brain sf_LowPassFilter;/* '<S49>/Low Pass Filter' */
} rtB_StateFlowFunctionsBuoysIter;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.Buoys.IterativeSegmentation' */
typedef struct {
  real_T ColorSpaceConversion_DWORK1[19200];/* '<S14>/Color Space  Conversion' */
  real32_T ColorSpaceConversion1_DWORK1[19200];/* '<S14>/Color Space  Conversion1' */
  real32_T Resize_IntBuffer[9600];     /* '<S56>/Resize' */
  real32_T Resize1_IntBuffer[9600];    /* '<S56>/Resize1' */
  real32_T Resize2_IntBuffer[9600];    /* '<S56>/Resize2' */
} rtDW_StateFlowFunctionsBuoysIte;

/* Block signals for system '<S4>/StateFlowFunctions.MaintainHeading' */
typedef struct {
  real_T Add;                          /* '<S81>/Add' */
  real_T Constant1;                    /* '<S81>/Constant1' */
  real_T Add_o;                        /* '<S80>/Add' */
  real_T Constant1_e;                  /* '<S80>/Constant1' */
  int8_T DoubleToint1;                 /* '<S23>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S23>/DoubleToint8' */
} rtB_StateFlowFunctionsMaintainH;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.MaintainHeading' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S83>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S82>/Heading Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsMaintainHea_e;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainHea_m;/* '<Root>/StateFlow Functions' */
  int8_T If_ActiveSubsystem;           /* '<S23>/If' */
} rtDW_StateFlowFunctionsMaintain;

/* Block signals for system '<S4>/StateFlowFunctions.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S16>/PutHSVImageTogether' */
} rtB_StateFlowFunctionsFollowOne;

/* Block signals for system '<S4>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
typedef struct {
  real_T Subtract;                     /* '<S19>/Subtract' */
  real_T Subtract1;                    /* '<S19>/Subtract1' */
  int8_T DataTypeConversion;           /* '<S68>/Data Type Conversion' */
  int8_T DataTypeConversion_f;         /* '<S69>/Data Type Conversion' */
  boolean_T ImageDataTypeConversion[19200];/* '<S19>/Image Data Type Conversion' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S19>/Embedded MATLAB Function1' */
} rtB_StateFlowFunctionsFollowO_k;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
typedef struct {
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S19>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S19>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S19>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S19>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S71>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S70>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S73>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S72>/Y-Buoy Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsFollowOnePa_g;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOnePa_l;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsFollow_g;

/* Block signals for system '<S4>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
typedef struct {
  int8_T DoubleToInt1;                 /* '<S17>/Double To Int1' */
  int8_T DoubleToInt8;                 /* '<S17>/Double To Int8' */
} rtB_StateFlowFunctionsFollowO_p;

/* Block states (auto storage) for system '<S4>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S62>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S61>/Depth Discrete-Time Integrator' */
  uint32_T StateFlowFunctionsFollowOnePa_j;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOneP_iz;/* '<Root>/StateFlow Functions' */
} rtDW_StateFlowFunctionsFollow_b;

/* Block signals (auto storage) */
typedef struct {
  real_T b[19200];                     /* '<S15>/Embedded MATLAB Function' */
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
  real_T LabMatrix_i[19200];           /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_j[150];            /* '<Root>/StateFlow Functions' */
  real_T H[19200];                     /* '<Root>/StateFlow Functions' */
  real_T S[19200];                     /* '<Root>/StateFlow Functions' */
  real_T V[19200];                     /* '<Root>/StateFlow Functions' */
  real_T DesiredHeading1;              /* '<Root>/StateFlow Functions' */
  real_T CurrentHeading1;              /* '<Root>/StateFlow Functions' */
  real_T ForwardVelocity1;             /* '<Root>/StateFlow Functions' */
  real_T H1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T S1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T V1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T LabMatrix_b3[19200];          /* '<Root>/StateFlow Functions' */
  real_T Ref_Colors_a[150];            /* '<Root>/StateFlow Functions' */
  real_T Num_Colors_b;                 /* '<Root>/StateFlow Functions' */
  real_T B_Hue_c;                      /* '<Root>/StateFlow Functions' */
  real_T B_Sat_k;                      /* '<Root>/StateFlow Functions' */
  real_T B_Value_c;                    /* '<Root>/StateFlow Functions' */
  real_T H_f[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_a[19200];                   /* '<Root>/StateFlow Functions' */
  real_T BW[19200];                    /* '<Root>/StateFlow Functions' */
  real_T H_k[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_n[19200];                   /* '<Root>/StateFlow Functions' */
  real_T buoys[200];                   /* '<Root>/StateFlow Functions' */
  real_T num_blobs;                    /* '<Root>/StateFlow Functions' */
  real_T HeadingAlong;                 /* '<Root>/StateFlow Functions' */
  real_T Forward1;                     /* '<Root>/StateFlow Functions' */
  real_T LabelMatrix[19200];           /* '<Root>/StateFlow Functions' */
  real_T ref_colors[150];              /* '<Root>/StateFlow Functions' */
  real_T num_colors_m;                 /* '<Root>/StateFlow Functions' */
  real_T blobs[200];                   /* '<S11>/Say Which Buoy Is Which' */
  real_T count;                        /* '<S11>/IF Buoy Conditions' */
  real_T Eccent[50];                   /* '<S11>/Blob Extraction' */
  real_T Extent[50];                   /* '<S11>/Blob Extraction' */
  real_T Centroid[100];                /* '<S11>/Blob Extraction' */
  real_T Area[50];                     /* '<S11>/Blob Extraction' */
  real_T ColorSpaceConversion1_o1;     /* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2;     /* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3;     /* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o1_n;   /* '<S28>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_i;   /* '<S28>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_m;   /* '<S28>/Color Space  Conversion1' */
  real_T Direction1;                   /* '<S6>/GetBestColorMatch' */
  real_T Direction2;                   /* '<S6>/GetBestColorMatch' */
  real_T Constant;                     /* '<S13>/Constant' */
  real_T Constant_f;                   /* '<S21>/Constant' */
  real_T HeadingForwardVelocity;       /* '<S24>/Heading Forward Velocity' */
  real_T Image;                        /* '<S84>/CheckConditions' */
  real_T Constant_p;                   /* '<S9>/Constant' */
  real_T ColorSpaceConversion1_o1_d;   /* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_k;   /* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_e;   /* '<S43>/Color Space  Conversion1' */
  real_T Image_g;                      /* '<S10>/IF Buoy Conditions' */
  real_T Constant_g;                   /* '<S8>/Constant' */
  real_T Constant2;                    /* '<S8>/Constant2' */
  real_T Constant1;                    /* '<S8>/Constant1' */
  real_T HoughTransform_o1[71820];     /* '<S64>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S64>/Hough Transform' */
  real_T HoughTransform_o3[399];       /* '<S64>/Hough Transform' */
  real_T Theta[2];                     /* '<S64>/IsLinePresent' */
  real_T Rho[2];                       /* '<S64>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S64>/IsLinePresent' */
  real_T AlongPathHeading;             /* '<S18>/GetHeadingToPath' */
  real_T ColorSpaceConversion_o1[19200];/* '<S15>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2[19200];/* '<S15>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3[19200];/* '<S15>/Color Space  Conversion' */
  real_T RGB[57600];                   /* '<S15>/Embedded MATLAB Function1' */
  real_T Constant_k;                   /* '<S5>/Constant' */
  real_T Constant2_i;                  /* '<S5>/Constant2' */
  real_T Constant1_o;                  /* '<S5>/Constant1' */
  real_T ColorSpaceConversion_o1_h;    /* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2_i;    /* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3_d;    /* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3_c;    /* '<S28>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2_o;    /* '<S28>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o1_g;    /* '<S28>/Color Space  Conversion' */
  real32_T Resize[19200];              /* '<S2>/Resize' */
  real32_T Resize1[19200];             /* '<S2>/Resize1' */
  real32_T Resize2[19200];             /* '<S2>/Resize2' */
  real32_T CurrentDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T DesiredDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real_T eml_HoughTable[71820];
  real_T L[19200];                     /* '<S15>/Embedded MATLAB Function' */
  real_T a[19200];                     /* '<S15>/Embedded MATLAB Function' */
  real_T b_m[19200];                   /* '<S15>/Embedded MATLAB Function' */
  real_T L_c[19200];                   /* '<S15>/Embedded MATLAB Function' */
  real_T a_k[19200];                   /* '<S15>/Embedded MATLAB Function' */
  real_T b_c[19200];                   /* '<S15>/Embedded MATLAB Function' */
  real_T L_b[19200];                   /* '<S15>/Embedded MATLAB Function' */
  real_T a_p[19200];                   /* '<S15>/Embedded MATLAB Function' */
  boolean_T eml_LogicMatrix[19200];
  boolean_T BW_c[19200];               /* '<S74>/Logical Operator1' */
  int8_T Left;                         /* '<Root>/StateFlow Functions' */
  int8_T Right;                        /* '<Root>/StateFlow Functions' */
  int8_T Strafe;                       /* '<Root>/StateFlow Functions' */
  int8_T Vertical;                     /* '<Root>/StateFlow Functions' */
  int8_T CameraPosition;               /* '<Root>/StateFlow Functions' */
  int8_T State;                        /* '<Root>/StateFlow Functions' */
  int8_T DoubleToInt8;                 /* '<S22>/Double To Int8' */
  uint8_T TotalNum;                    /* '<S11>/Blob Extraction' */
  boolean_T BW_g[19200];               /* '<Root>/StateFlow Functions' */
  boolean_T BW_d[19200];               /* '<S84>/Logical Operator1' */
  boolean_T DataTypeConversion[19200]; /* '<S74>/Data Type Conversion' */
  boolean_T BW_f[19200];               /* '<S41>/Relational Operator' */
  boolean_T Erosion[19200];            /* '<S74>/Erosion' */
  rtB_StateFlowFunctionsFollowO_p StateFlowFunctionsFollowOneP_kn;/* '<S4>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
  rtB_StateFlowFunctionsFollowO_k StateFlowFunctionsFollowOneP_iq;/* '<S4>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
  rtB_StateFlowFunctionsFollowOne StateFlowFunctionsFollowOnePa_g;/* '<S4>/StateFlowFunctions.FollowOnePath.MakeHSVImage' */
  rtB_StateFlowFunctionsMaintainH StateFlowFunctionsMaintainHea_d;/* '<S4>/StateFlowFunctions.MaintainHeading' */
  rtB_StateFlowFunctionsBuoysIter StateFlowFunctionsBuoysIterat_g;/* '<S4>/StateFlowFunctions.Buoys.IterativeSegmentation' */
  rtB_StateFlowFunctionsBuoysFind StateFlowFunctionsBuoysFindB_ln;/* '<S4>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
  rtB_StateFlowFunctionsBuoysAppr StateFlowFunctionsBuoysApproa_l;/* '<S4>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Resize_IntBuffer[76800];    /* '<S2>/Resize' */
  real32_T Resize1_IntBuffer[76800];   /* '<S2>/Resize1' */
  real32_T Resize2_IntBuffer[76800];   /* '<S2>/Resize2' */
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S84>/Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S10>/Buoy Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S84>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S84>/Blob Analysis' */
  boolean_T Erosion_ONE_PAD_IMG_DW[21209];/* '<S74>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW[21209];/* '<S74>/Erosion' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S10>/Buoy Blob Analysis' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S84>/Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S79>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S78>/Depth Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/StateFlow Functions' */
  real_T countarea;                    /* '<Root>/StateFlow Functions' */
  real_T DesiredHeadingCount;          /* '<Root>/StateFlow Functions' */
  real_T OldHeading;                   /* '<Root>/StateFlow Functions' */
  real_T TrackCount;                   /* '<Root>/StateFlow Functions' */
  real_T BuoyCount;                    /* '<Root>/StateFlow Functions' */
  real_T HeadingAlongPath;             /* '<Root>/StateFlow Functions' */
  real_T Done;                         /* '<Root>/StateFlow Functions' */
  real_T Error;                        /* '<Root>/StateFlow Functions' */
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
  real_T F1_RTP;                       /* '<S11>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S11>/Blob Extraction' */
  real_T F3_RTP;                       /* '<S11>/Blob Extraction' */
  real_T ColorSpaceConversion_DWORK1;  /* '<S26>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1; /* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_g;/* '<S28>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1_e;/* '<S28>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_b;/* '<S43>/Color Space  Conversion' */
  real_T ColorSpaceConversion1_DWORK1_l;/* '<S43>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_g1[19200];/* '<S15>/Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  int32_T WALKER_RTP[8];               /* '<S11>/Blob Extraction' */
  int32_T F0_RTP;                      /* '<S11>/Blob Extraction' */
  int32_T Erosion_NUMNONZ_DW[2];       /* '<S74>/Erosion' */
  int32_T Erosion_STREL_DW[2];         /* '<S74>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[8];     /* '<S74>/Erosion' */
  uint32_T StateFlowFunctionsMaintainDepth;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainDep_k;/* '<Root>/StateFlow Functions' */
  uint32_T MINAREA_RTP;                /* '<S11>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S11>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S11>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S11>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S11>/Blob Extraction' */
  int8_T OperationalState;             /* '<Root>/StateFlow Functions' */
  uint8_T is_active_c1_brain;          /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateFlowFunctions;/* '<Root>/StateFlow Functions' */
  uint8_T is_StateFlowFunctions;       /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateManagement;   /* '<Root>/StateFlow Functions' */
  uint8_T is_StateManagement;          /* '<Root>/StateFlow Functions' */
  uint8_T is_OnePath;                  /* '<Root>/StateFlow Functions' */
  uint8_T is_FollowOnePath;            /* '<Root>/StateFlow Functions' */
  uint8_T is_ValidationGate;           /* '<Root>/StateFlow Functions' */
  uint8_T is_Autonomous;               /* '<Root>/StateFlow Functions' */
  uint8_T was_Autonomous;              /* '<Root>/StateFlow Functions' */
  uint8_T is_Running;                  /* '<Root>/StateFlow Functions' */
  uint8_T is_Start;                    /* '<Root>/StateFlow Functions' */
  uint8_T is_Buoys;                    /* '<Root>/StateFlow Functions' */
  uint8_T is_ApproachBuoys;            /* '<Root>/StateFlow Functions' */
  uint8_T PAD_DW[19764];               /* '<S11>/Blob Extraction' */
  boolean_T OldObstacle;               /* '<Root>/StateFlow Functions' */
  boolean_T hblob;                     /* '<S11>/Blob Extraction' */
  rtDW_StateFlowFunctionsFollow_b StateFlowFunctionsFollowOneP_kn;/* '<S4>/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align' */
  rtDW_StateFlowFunctionsFollow_g StateFlowFunctionsFollowOneP_iq;/* '<S4>/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe' */
  rtDW_StateFlowFunctionsMaintain StateFlowFunctionsMaintainHea_d;/* '<S4>/StateFlowFunctions.MaintainHeading' */
  rtDW_StateFlowFunctionsBuoysIte StateFlowFunctionsBuoysIterat_g;/* '<S4>/StateFlowFunctions.Buoys.IterativeSegmentation' */
  rtDW_StateFlowFunctionsBuoysFin StateFlowFunctionsBuoysFindB_ln;/* '<S4>/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys' */
  rtDW_StateFlowFunctionsBuoysApp StateFlowFunctionsBuoysApproa_l;/* '<S4>/StateFlowFunctions.Buoys.ApproachBuoys.Buoy' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: HoughTransform_SINE_
   * Referenced by: '<S64>/Hough Transform'
   */
  real_T HoughTransform_SINE_[91];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RT
   * Referenced by: '<S64>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RT;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S56>/Resize'
   *   '<S56>/Resize1'
   *   '<S56>/Resize2'
   */
  real32_T pooled13[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S56>/Resize'
   *   '<S56>/Resize1'
   *   '<S56>/Resize2'
   */
  real32_T pooled14[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Resize'
   *   '<S2>/Resize1'
   *   '<S2>/Resize2'
   */
  real32_T pooled15[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Resize'
   *   '<S2>/Resize1'
   *   '<S2>/Resize2'
   */
  real32_T pooled16[1280];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S7>/Buoy Blob Analysis'
   *   '<S10>/Buoy Blob Analysis'
   *   '<S19>/Buoy Blob Analysis'
   *   '<S84>/Blob Analysis'
   */
  int32_T pooled17[8];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S56>/Resize'
   *   '<S56>/Resize1'
   *   '<S56>/Resize2'
   */
  int32_T pooled19[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S56>/Resize'
   *   '<S56>/Resize1'
   *   '<S56>/Resize2'
   */
  int32_T pooled20[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Resize'
   *   '<S2>/Resize1'
   *   '<S2>/Resize2'
   */
  int32_T pooled21[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S2>/Resize'
   *   '<S2>/Resize1'
   *   '<S2>/Resize2'
   */
  int32_T pooled22[1280];

  /* Expression: nhood
   * Referenced by: '<S74>/Erosion'
   */
  boolean_T Erosion_NHOOD_RTP[8];
} ConstParam_brain;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T CurrentDepth;                 /* '<Root>/CurrentDepth' */
  real_T CurrentHeading;               /* '<Root>/CurrentHeading' */
  uint8_T R[307200];                   /* '<Root>/R' */
  uint8_T G[307200];                   /* '<Root>/G' */
  uint8_T B[307200];                   /* '<Root>/B' */
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
                                        *   '<S5>/Constant'
                                        *   '<S26>/Constant'
                                        */
  real_T Buoy1_Saturation;             /* Variable: Buoy1_Saturation
                                        * Referenced by:
                                        *   '<S5>/Constant2'
                                        *   '<S26>/Constant2'
                                        */
  real_T Buoy1_Value;                  /* Variable: Buoy1_Value
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S26>/Constant1'
                                        */
  real_T Buoy2_Hue;                    /* Variable: Buoy2_Hue
                                        * Referenced by:
                                        *   '<S8>/Constant'
                                        *   '<S28>/Constant'
                                        */
  real_T Buoy2_Saturation;             /* Variable: Buoy2_Saturation
                                        * Referenced by:
                                        *   '<S8>/Constant2'
                                        *   '<S28>/Constant2'
                                        */
  real_T Buoy2_Value;                  /* Variable: Buoy2_Value
                                        * Referenced by:
                                        *   '<S8>/Constant1'
                                        *   '<S28>/Constant1'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * Referenced by:
                                        *   '<S10>/Constant2'
                                        *   '<S11>/Constant1'
                                        *   '<S12>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * Referenced by:
                                        *   '<S10>/Constant4'
                                        *   '<S11>/Constant3'
                                        *   '<S12>/Constant3'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S10>/Constant1'
                                        *   '<S11>/Constant'
                                        *   '<S12>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * Referenced by:
                                        *   '<S10>/Constant3'
                                        *   '<S11>/Constant2'
                                        *   '<S12>/Constant2'
                                        */
  real_T Buoy_Strafe;                  /* Variable: Buoy_Strafe
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Cam_Down_XPos_Kd;             /* Variable: Cam_Down_XPos_Kd
                                        * Referenced by:
                                        *   '<S61>/CamDown-X Derivative Gain'
                                        *   '<S70>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_XPos_Ki;             /* Variable: Cam_Down_XPos_Ki
                                        * Referenced by:
                                        *   '<S61>/CamDown-X Integral Gain'
                                        *   '<S61>/CamDown-X Proportional Gain'
                                        *   '<S70>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Down_XPos_Kp;             /* Variable: Cam_Down_XPos_Kp
                                        * Referenced by: '<S70>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Down_YPos_Kd;             /* Variable: Cam_Down_YPos_Kd
                                        * Referenced by: '<S72>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_YPos_Ki;             /* Variable: Cam_Down_YPos_Ki
                                        * Referenced by: '<S72>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Down_YPos_Kp;             /* Variable: Cam_Down_YPos_Kp
                                        * Referenced by: '<S72>/Y-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * Referenced by: '<S36>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * Referenced by: '<S36>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * Referenced by: '<S36>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * Referenced by: '<S38>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * Referenced by: '<S38>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * Referenced by: '<S38>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by: '<S78>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by: '<S78>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by: '<S78>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by:
                                        *   '<S13>/Constant'
                                        *   '<S24>/Heading Forward Velocity'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by: '<S82>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by: '<S82>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by: '<S82>/Heading Proportional Gain'
                                        */
  real_T Iter_Segment_Thresh;          /* Variable: Iter_Segment_Thresh
                                        * Referenced by: '<S50>/Dist_Thresh'
                                        */
  real_T Track_Desired_Depth;          /* Variable: Track_Desired_Depth
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * Referenced by:
                                        *   '<S75>/Constant'
                                        *   '<S86>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * Referenced by:
                                        *   '<S76>/Constant'
                                        *   '<S87>/Constant'
                                        */
  real_T Track_Min_Eccentricity;       /* Variable: Track_Min_Eccentricity
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * Referenced by:
                                        *   '<S77>/Constant'
                                        *   '<S88>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by:
                                        *   '<S32>/Vision_Forward_Velocity'
                                        *   '<S32>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by:
                                        *   '<S7>/Buoy Blob Analysis'
                                        *   '<S10>/Buoy Blob Analysis'
                                        *   '<S19>/Buoy Blob Analysis'
                                        *   '<S84>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by:
                                        *   '<S7>/Buoy Blob Analysis'
                                        *   '<S10>/Buoy Blob Analysis'
                                        *   '<S19>/Buoy Blob Analysis'
                                        *   '<S84>/Blob Analysis'
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
 * '<S1>'   : brain/Environment Controller3
 * '<S2>'   : brain/GetVideo1
 * '<S3>'   : brain/Normalize Thrusters to 1
 * '<S4>'   : brain/StateFlow Functions
 * '<S5>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.GetFirstBuoyStats
 * '<S6>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach
 * '<S7>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy
 * '<S8>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetSecondBuoyStats
 * '<S9>'   : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.GetStrafe
 * '<S10>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy
 * '<S11>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors
 * '<S12>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys
 * '<S13>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.GetBuoyForwardVelocity
 * '<S14>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation
 * '<S15>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage
 * '<S16>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage
 * '<S17>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align
 * '<S18>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings
 * '<S19>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe
 * '<S20>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation
 * '<S21>'  : brain/StateFlow Functions/StateFlowFunctions.GetDesiredDepth
 * '<S22>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth
 * '<S23>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading
 * '<S24>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity
 * '<S25>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack
 * '<S26>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/FirstBuoy Info
 * '<S27>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/GetBestColorMatch
 * '<S28>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.ApproachFirstBuoy.WhichBuoysToApproach/Second Buoy Info
 * '<S29>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function
 * '<S30>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Embedded MATLAB Function1
 * '<S31>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image
 * '<S32>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl
 * '<S33>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl
 * '<S34>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Choose Closest Color
 * '<S35>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Threshold The Image/Get Desired Color
 * '<S36>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl/PID Controller X Position
 * '<S37>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S38>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S39>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S40>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/IF Buoy Conditions
 * '<S41>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image
 * '<S42>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Choose Closest Color
 * '<S43>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ApproachBuoys.FindSecondBuoy.SecondBuoy/Threshold The Image/Get Desired Color
 * '<S44>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Blob Extraction
 * '<S45>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/IF Buoy Conditions
 * '<S46>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.GetBuoyColors/Say Which Buoy Is Which
 * '<S47>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/Blob Extraction
 * '<S48>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.FindBuoys.LookforBuoys/IF Buoy Conditions
 * '<S49>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter
 * '<S50>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation
 * '<S51>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S52>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S53>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S54>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/LabSegmentation
 * '<S55>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S56>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.IterativeSegmentation/Segmentation/Resize
 * '<S57>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function
 * '<S58>'  : brain/StateFlow Functions/StateFlowFunctions.Buoys.ShowSegmentedImage/Embedded MATLAB Function1
 * '<S59>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S60>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/Embedded MATLAB Function
 * '<S61>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/PID Controller Relative Heading
 * '<S62>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.Align/PID Controller Relative Heading/Depth Discrete Derivative
 * '<S63>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/GetHeadingToPath
 * '<S64>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff
 * '<S65>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.AlignWithPath.GetHeadings/Hough Transform Stuff/IsLinePresent
 * '<S66>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function
 * '<S67>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Embedded MATLAB Function1
 * '<S68>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control
 * '<S69>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control
 * '<S70>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control/PID Controller X Position
 * '<S71>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/X-Axis Control/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S72>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control/PID Controller Y Axis
 * '<S73>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver_Strafe/Y-Axis Control/PID Controller Y Axis/Y-Buoy Discrete Derivative
 * '<S74>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation
 * '<S75>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Hue Higher Comparison
 * '<S76>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Hue Lower Comparison
 * '<S77>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.HSVSegmentation/Segmentation/Saturation Comparison
 * '<S78>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3
 * '<S79>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S80>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1
 * '<S81>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2
 * '<S82>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4
 * '<S83>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S84>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack
 * '<S85>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions
 * '<S86>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S87>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S88>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
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
