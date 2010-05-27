/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.364
 * Real-Time Workshop file version      : 7.5  (R2010a)  25-Jan-2010
 * Real-Time Workshop file generated on : Thu May 27 18:36:36 2010
 * TLC version                          : 7.5 (Jan 19 2010)
 * C/C++ source code generated on       : Thu May 27 18:36:36 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives:
 *    1. Debugging
 *    2. Safety precaution
 *    3. Traceability
 *    4. Execution efficiency
 *    5. ROM efficiency
 *    6. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brain_h_
#define RTW_HEADER_brain_h_
#include "rtw_modelmap.h"
#ifndef brain_COMMON_INCLUDES_
# define brain_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* brain_COMMON_INCLUDES_ */

#include "brain_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals for system '<S8>/Embedded MATLAB Function1' */
typedef struct {
  real_T XCenter;                      /* '<S8>/Embedded MATLAB Function1' */
  real_T YCenter;                      /* '<S8>/Embedded MATLAB Function1' */
} rtB_EmbeddedMATLABFunction1_bra;

/* Block signals for system '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S11>/PutHSVImageTogether' */
} rtB_StateFlowFunctionsFollowOne;

/* Block signals for system '<S51>/IsLinePresent' */
typedef struct {
  real_T eml_HoughTable[51660];
  real_T Theta[2];                     /* '<S51>/IsLinePresent' */
  real_T Rho[2];                       /* '<S51>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S51>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings' */
typedef struct {
  real_T HoughTransform_o1[51660];     /* '<S51>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S51>/Hough Transform' */
  real_T HoughTransform_o3[287];       /* '<S51>/Hough Transform' */
  real_T HoughTransform_o1_p[51660];   /* '<S52>/Hough Transform' */
  real_T HoughTransform_o2_h[180];     /* '<S52>/Hough Transform' */
  real_T HoughTransform_o3_p[287];     /* '<S52>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S14>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S14>/GetHeadingToPath' */
  rtB_IsLinePresent_brain sf_IsLinePresent_m;/* '<S52>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S51>/IsLinePresent' */
} rtB_StateFlowFunctionsFollowO_o;

/* Block signals for system '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
typedef struct {
  real_T Image;                        /* '<S61>/CheckConditions' */
  boolean_T BW[19200];                 /* '<S61>/Logical Operator1' */
} rtB_StateFlowFunctionsValidatio;

/* Block states (auto storage) for system '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
typedef struct {
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S61>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S61>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S61>/Blob Analysis' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S61>/Blob Analysis' */
} rtDW_StateFlowFunctionsValidati;

/* Block signals (auto storage) */
typedef struct {
  real_T eml_hoistedExpr[19200];
  real_T sf_BWleft[9600];
  real_T sf_BWright[9600];
  boolean_T BW_m[19200];               /* '<S8>/Logical Operator1' */
  int8_T eml_BWright[9600];
  real_T DesiredDepth;                 /* '<Root>/StateFlow Functions' */
  real_T DesiredHeading;               /* '<Root>/StateFlow Functions' */
  real_T BuoyCentroidX;                /* '<Root>/StateFlow Functions' */
  real_T BuoyCentroidY;                /* '<Root>/StateFlow Functions' */
  real_T BWout[19200];                 /* '<Root>/StateFlow Functions' */
  real_T H[19200];                     /* '<Root>/StateFlow Functions' */
  real_T S[19200];                     /* '<Root>/StateFlow Functions' */
  real_T H_k[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_o[19200];                   /* '<Root>/StateFlow Functions' */
  real_T DesiredHeading1;              /* '<Root>/StateFlow Functions' */
  real_T CurrentHeading1;              /* '<Root>/StateFlow Functions' */
  real_T ForwardVelocity1;             /* '<Root>/StateFlow Functions' */
  real_T H1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T S1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T V1[19200];                    /* '<Root>/StateFlow Functions' */
  real_T CurrentHeading1_b;            /* '<Root>/StateFlow Functions' */
  real_T HSV1[57600];                  /* '<Root>/StateFlow Functions' */
  real_T DesiredH1;                    /* '<Root>/StateFlow Functions' */
  real_T H_m[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_h[19200];                   /* '<Root>/StateFlow Functions' */
  real_T H_n[19200];                   /* '<Root>/StateFlow Functions' */
  real_T S_j[19200];                   /* '<Root>/StateFlow Functions' */
  real_T Constant;                     /* '<S15>/Constant' */
  real_T HeadingForwardVelocity;       /* '<S18>/Heading Forward Velocity' */
  real_T Constant_i;                   /* '<S10>/Constant' */
  real_T Subtract;                     /* '<S12>/Subtract' */
  real_T Subtract1;                    /* '<S12>/Subtract1' */
  real_T BWleft[9600];                 /* '<S48>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S48>/Get Brightest Pixel Per Column and Row' */
  real_T Add;                          /* '<S58>/Add' */
  real_T Constant1;                    /* '<S58>/Constant1' */
  real_T Add_o;                        /* '<S57>/Add' */
  real_T Constant1_e;                  /* '<S57>/Constant1' */
  real_T Image;                        /* '<S31>/IF Buoy Conditions' */
  real_T Add_h;                        /* '<S25>/Add' */
  real_T Add1;                         /* '<S25>/Add1' */
  real_T BlobArea;                     /* '<S8>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S8>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S8>/Embedded MATLAB Function' */
  real32_T Resize[19200];              /* '<S5>/Resize' */
  real32_T Resize1[19200];             /* '<S5>/Resize1' */
  real32_T Resize2[19200];             /* '<S5>/Resize2' */
  real32_T CurrentDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T DesiredDepth1;              /* '<Root>/StateFlow Functions' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  int8_T Left;                         /* '<Root>/StateFlow Functions' */
  int8_T Right;                        /* '<Root>/StateFlow Functions' */
  int8_T Strafe;                       /* '<Root>/StateFlow Functions' */
  int8_T Vertical;                     /* '<Root>/StateFlow Functions' */
  int8_T CameraPosition;               /* '<Root>/StateFlow Functions' */
  int8_T State;                        /* '<Root>/StateFlow Functions' */
  int8_T DoubleToInt8;                 /* '<S16>/Double To Int8' */
  int8_T DataTypeConversion;           /* '<S42>/Data Type Conversion' */
  int8_T DataTypeConversion_h;         /* '<S43>/Data Type Conversion' */
  int8_T DoubleToint1;                 /* '<S17>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S17>/DoubleToint8' */
  int8_T DataTypeConversion_e;         /* '<S26>/Data Type Conversion' */
  uint8_T RGBVid_R[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T ChromaResampling_o1[307200]; /* '<S5>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S5>/Chroma Resampling' */
  boolean_T BWleft1[9600];             /* '<Root>/StateFlow Functions' */
  boolean_T BWright1[9600];            /* '<Root>/StateFlow Functions' */
  boolean_T BW[19200];                 /* '<S12>/Logical Operator1' */
  boolean_T BWleft_k[9600];            /* '<S48>/Data Type Conversion' */
  boolean_T BWright_e[9600];           /* '<S48>/Data Type Conversion1' */
  boolean_T BW_g[19200];               /* '<S31>/Logical Operator1' */
  boolean_T Erosion[19200];            /* '<S8>/Erosion' */
  boolean_T Dilation[19200];           /* '<S31>/Dilation' */
  boolean_T Erosion_l[19200];          /* '<S31>/Erosion' */
  boolean_T Dilation_e[19200];         /* '<S8>/Dilation' */
  int8_T eml_BWleft[9600];
  rtB_StateFlowFunctionsValidatio StateFlowFunctionsValidationG_a;/* '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1_d;/* '<S12>/Embedded MATLAB Function1' */
  rtB_StateFlowFunctionsFollowO_o StateFlowFunctionsFollowOneP_ht;/* '<S7>/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings' */
  rtB_StateFlowFunctionsFollowOne StateFlowFunctionsFollowOnePa_g;/* '<S7>/StateFlowFunctions.FollowOnePath.MakeHSVImage' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S8>/Embedded MATLAB Function1' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Resize_IntBuffer[76800];    /* '<S5>/Resize' */
  real32_T Resize1_IntBuffer[76800];   /* '<S5>/Resize1' */
  real32_T Resize2_IntBuffer[76800];   /* '<S5>/Resize2' */
  uint32_T BuoyBlobAnalysis_STACK_DW_o[19200];/* '<S8>/Buoy Blob Analysis' */
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S12>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW_g[19200];/* '<S8>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW_n[19200];/* '<S8>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S12>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S12>/Buoy Blob Analysis' */
  boolean_T Erosion_ONE_PAD_IMG_DW_i[21209];/* '<S8>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW_j[21209];/* '<S8>/Erosion' */
  boolean_T Dilation_ONE_PAD_IMG_DW_n[20049];/* '<S8>/Dilation' */
  uint8_T BuoyBlobAnalysis_PAD_DW_i[19764];/* '<S8>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S12>/Buoy Blob Analysis' */
  real_T UD_DSTATE;                    /* '<S56>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S55>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_k;                  /* '<S45>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S44>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_ko;                 /* '<S47>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S46>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S60>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S59>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_f;                  /* '<S28>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_D_k;/* '<S27>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_m;                  /* '<S30>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_D_a;/* '<S29>/Y-Buoy Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/StateFlow Functions' */
  real_T BuoyDone;                     /* '<Root>/StateFlow Functions' */
  real_T countarea;                    /* '<Root>/StateFlow Functions' */
  real_T DesiredHeadingCount;          /* '<Root>/StateFlow Functions' */
  real_T OldHeading;                   /* '<Root>/StateFlow Functions' */
  real_T TrackCount;                   /* '<Root>/StateFlow Functions' */
  real_T BuoyCount;                    /* '<Root>/StateFlow Functions' */
  real_T AvgDesiredHeadingAlongPath[2];/* '<Root>/StateFlow Functions' */
  real_T AvgDesiredHeadingToPath[2];   /* '<Root>/StateFlow Functions' */
  real_T countAlong;                   /* '<Root>/StateFlow Functions' */
  real_T countTo;                      /* '<Root>/StateFlow Functions' */
  real_T outliersAlong;                /* '<Root>/StateFlow Functions' */
  real_T outliersTo;                   /* '<Root>/StateFlow Functions' */
  real_T Done;                         /* '<Root>/StateFlow Functions' */
  real_T Error;                        /* '<Root>/StateFlow Functions' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S5>/RGB to HSV Color Space  Conversion' */
  int32_T Dilation_NUMNONZ_DW;         /* '<S31>/Dilation' */
  int32_T Dilation_STREL_DW;           /* '<S31>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW[4];   /* '<S31>/Dilation' */
  int32_T Erosion_NUMNONZ_DW[2];       /* '<S31>/Erosion' */
  int32_T Erosion_STREL_DW[2];         /* '<S31>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[8];     /* '<S31>/Erosion' */
  int32_T Dilation_NUMNONZ_DW_m;       /* '<S8>/Dilation' */
  int32_T Dilation_STREL_DW_g;         /* '<S8>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW_h[4]; /* '<S8>/Dilation' */
  int32_T Erosion_NUMNONZ_DW_e[2];     /* '<S8>/Erosion' */
  int32_T Erosion_STREL_DW_d[2];       /* '<S8>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW_p[8];   /* '<S8>/Erosion' */
  uint32_T presentTicks;               /* '<Root>/StateFlow Functions' */
  uint32_T elapsedTicks;               /* '<Root>/StateFlow Functions' */
  uint32_T previousTicks;              /* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsBuoyApproachB;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsBuoyApproac_l;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOnePa_m;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsFollowOnePa_e;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainDepth;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainDep_k;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainHeadi;/* '<Root>/StateFlow Functions' */
  uint32_T StateFlowFunctionsMaintainHea_m;/* '<Root>/StateFlow Functions' */
  int8_T OperationalState;             /* '<Root>/StateFlow Functions' */
  int8_T If_ActiveSubsystem;           /* '<S17>/If' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S5>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateFlowFunctions;/* '<Root>/StateFlow Functions' */
  uint8_T is_StateFlowFunctions;       /* '<Root>/StateFlow Functions' */
  uint8_T is_active_StateManagement;   /* '<Root>/StateFlow Functions' */
  uint8_T is_StateManagement;          /* '<Root>/StateFlow Functions' */
  uint8_T is_GoAroundBuoy;             /* '<Root>/StateFlow Functions' */
  uint8_T is_Buoy;                     /* '<Root>/StateFlow Functions' */
  uint8_T is_OnePath;                  /* '<Root>/StateFlow Functions' */
  uint8_T is_FollowOnePath;            /* '<Root>/StateFlow Functions' */
  uint8_T is_Autonomous;               /* '<Root>/StateFlow Functions' */
  uint8_T is_Running;                  /* '<Root>/StateFlow Functions' */
  uint8_T temporalCounter_i1;          /* '<Root>/StateFlow Functions' */
  boolean_T OldObstacle;               /* '<Root>/StateFlow Functions' */
  rtDW_StateFlowFunctionsValidati StateFlowFunctionsValidationG_a;/* '<S7>/StateFlowFunctions.ValidationGate.LookforTrack' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S51>/Hough Transform'
   *   '<S52>/Hough Transform'
   */
  real_T pooled9[91];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S51>/Hough Transform'
   *   '<S52>/Hough Transform'
   */
  real_T pooled10;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  real32_T pooled12[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  real32_T pooled13[1280];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/Buoy Blob Analysis'
   *   '<S12>/Buoy Blob Analysis'
   *   '<S31>/Blob Analysis'
   *   '<S61>/Blob Analysis'
   */
  int32_T pooled16[8];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  int32_T pooled18[960];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S5>/Resize'
   *   '<S5>/Resize1'
   *   '<S5>/Resize2'
   */
  int32_T pooled19[1280];

  /* Pooled Parameter (Expression: nhood)
   * Referenced by:
   *   '<S8>/Dilation'
   *   '<S31>/Dilation'
   */
  boolean_T pooled20[4];

  /* Pooled Parameter (Expression: nhood)
   * Referenced by:
   *   '<S8>/Erosion'
   *   '<S31>/Erosion'
   */
  boolean_T pooled21[8];
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
} ExternalOutputs_brain;

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by:
                                        *   '<S20>/Constant'
                                        *   '<S32>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by:
                                        *   '<S21>/Constant'
                                        *   '<S33>/Constant'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by:
                                        *   '<S22>/Constant'
                                        *   '<S35>/Constant'
                                        */
  real_T Cam_Down_XPos_Kd;             /* Variable: Cam_Down_XPos_Kd
                                        * Referenced by: '<S44>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_XPos_Ki;             /* Variable: Cam_Down_XPos_Ki
                                        * Referenced by: '<S44>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Down_XPos_Kp;             /* Variable: Cam_Down_XPos_Kp
                                        * Referenced by: '<S44>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Down_YPos_Kd;             /* Variable: Cam_Down_YPos_Kd
                                        * Referenced by: '<S46>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_YPos_Ki;             /* Variable: Cam_Down_YPos_Ki
                                        * Referenced by: '<S46>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Down_YPos_Kp;             /* Variable: Cam_Down_YPos_Kp
                                        * Referenced by: '<S46>/Y-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * Referenced by: '<S27>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * Referenced by: '<S27>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * Referenced by: '<S27>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * Referenced by: '<S29>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * Referenced by: '<S29>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * Referenced by: '<S29>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by: '<S55>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by: '<S55>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by: '<S55>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by:
                                        *   '<S10>/Constant'
                                        *   '<S18>/Heading Forward Velocity'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by: '<S59>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by: '<S59>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by: '<S59>/Heading Proportional Gain'
                                        */
  real_T Track_Desired_Depth;          /* Variable: Track_Desired_Depth
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * Referenced by:
                                        *   '<S37>/Constant'
                                        *   '<S63>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * Referenced by:
                                        *   '<S38>/Constant'
                                        *   '<S64>/Constant'
                                        */
  real_T Track_Min_Eccentricity;       /* Variable: Track_Min_Eccentricity
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * Referenced by:
                                        *   '<S39>/Constant'
                                        *   '<S48>/Track Saturation'
                                        *   '<S65>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by:
                                        *   '<S25>/Vision_Forward_Velocity'
                                        *   '<S25>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by:
                                        *   '<S8>/Buoy Blob Analysis'
                                        *   '<S12>/Buoy Blob Analysis'
                                        *   '<S31>/Blob Analysis'
                                        *   '<S61>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by:
                                        *   '<S8>/Buoy Blob Analysis'
                                        *   '<S12>/Buoy Blob Analysis'
                                        *   '<S31>/Blob Analysis'
                                        *   '<S61>/Blob Analysis'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_brain {
  const char_T *errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

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
 * '<S8>'   : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy
 * '<S9>'   : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy
 * '<S10>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.GetBuoyForwardVelocity
 * '<S11>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage
 * '<S12>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver
 * '<S13>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S14>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings
 * '<S15>'  : brain/StateFlow Functions/StateFlowFunctions.GetDesiredDepth
 * '<S16>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth
 * '<S17>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading
 * '<S18>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.GetValidationGateForwardVelocity
 * '<S19>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack
 * '<S20>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Buoy HueHigher
 * '<S21>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Buoy HueLower
 * '<S22>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Buoy Saturation
 * '<S23>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function
 * '<S24>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1
 * '<S25>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl
 * '<S26>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl
 * '<S27>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S28>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S29>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S30>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S31>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis
 * '<S32>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S33>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S34>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions
 * '<S35>'  : brain/StateFlow Functions/StateFlowFunctions.Buoy.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S36>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S37>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy HueHigher
 * '<S38>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy HueLower
 * '<S39>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy Saturation
 * '<S40>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function
 * '<S41>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function1
 * '<S42>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control
 * '<S43>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control
 * '<S44>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position
 * '<S45>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S46>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis
 * '<S47>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis/Y-Buoy Discrete Derivative
 * '<S48>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S49>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S50>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S51>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S52>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S53>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S54>'  : brain/StateFlow Functions/StateFlowFunctions.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S55>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3
 * '<S56>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S57>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigError S1
 * '<S58>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/BigNegativeError S2
 * '<S59>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4
 * '<S60>'  : brain/StateFlow Functions/StateFlowFunctions.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S61>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack
 * '<S62>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/CheckConditions
 * '<S63>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S64>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S65>'  : brain/StateFlow Functions/StateFlowFunctions.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
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
