/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.197
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Wed Feb 17 18:15:29 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Wed Feb 17 18:15:30 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
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
#include "viphough_rt.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
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

/* Block signals for system '<S14>/BigError S1' */
typedef struct {
  real_T Add;                          /* '<S64>/Add' */
  real_T Constant1;                    /* '<S64>/Constant1' */
} rtB_BigErrorS1_brain;

/* Block signals for system '<S14>/BigNegativeError S2' */
typedef struct {
  real_T Add;                          /* '<S65>/Add' */
  real_T Constant1;                    /* '<S65>/Constant1' */
} rtB_BigNegativeErrorS2_brain;

/* Block signals for system '<S43>/IsLinePresent' */
typedef struct {
  real_T Theta[2];                     /* '<S43>/IsLinePresent' */
  real_T Rho[2];                       /* '<S43>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S43>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S1>/Running.FollowOnePath.OnePath.MaintainDepth' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S9>/Double To Int8' */
} rtB_RunningFollowOnePathOnePath;

/* Block states (auto storage) for system '<S1>/Running.FollowOnePath.OnePath.MaintainDepth' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S48>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S47>/Depth Discrete-Time Integrator' */
  uint32_T RunningFollowOnePathOnePathMa_k;/* '<Root>/Chart' */
  uint32_T RunningFollowOnePathOnePathMa_c;/* '<Root>/Chart' */
} rtDW_RunningFollowOnePathOnePat;

/* Block signals for system '<S1>/Running.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S6>/PutHSVImageTogether' */
} rtB_RunningFollowOnePathMakeHSV;

/* Block signals (auto storage) */
typedef struct {
  real_T DesiredDepth;                 /* '<Root>/Chart' */
  real_T DesiredHeading;               /* '<Root>/Chart' */
  real_T BuoyCentroidX;                /* '<Root>/Chart' */
  real_T BuoyCentroidY;                /* '<Root>/Chart' */
  real_T SFunction_o11[19200];         /* '<Root>/Chart' */
  real_T SFunction_o12[19200];         /* '<Root>/Chart' */
  real_T SFunction_o15;                /* '<Root>/Chart' */
  real_T SFunction_o16;                /* '<Root>/Chart' */
  real_T SFunction_o17[19200];         /* '<Root>/Chart' */
  real_T SFunction_o18[19200];         /* '<Root>/Chart' */
  real_T SFunction_o21;                /* '<Root>/Chart' */
  real_T SFunction_o22;                /* '<Root>/Chart' */
  real_T SFunction_o23[19200];         /* '<Root>/Chart' */
  real_T SFunction_o24[19200];         /* '<Root>/Chart' */
  real_T SFunction_o25[57600];         /* '<Root>/Chart' */
  real_T SFunction_o28;                /* '<Root>/Chart' */
  real_T SFunction_o29[57600];         /* '<Root>/Chart' */
  real_T SFunction_o31;                /* '<Root>/Chart' */
  real_T SFunction_o32;                /* '<Root>/Chart' */
  real_T SFunction_o35;                /* '<Root>/Chart' */
  real_T SFunction_o36;                /* '<Root>/Chart' */
  real_T SFunction_o37[19200];         /* '<Root>/Chart' */
  real_T SFunction_o38[19200];         /* '<Root>/Chart' */
  real_T SFunction_o39[19200];         /* '<Root>/Chart' */
  real_T HoughTransform_o1[71820];     /* '<S55>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S55>/Hough Transform' */
  real_T HoughTransform_o3[399];       /* '<S55>/Hough Transform' */
  real_T Close;                        /* '<S12>/IsLineNearCenter' */
  real_T BooleanImage[19200];          /* '<S53>/Get Brightest Pixel Per Column and Row' */
  real_T HoughTransform_o1_d[51660];   /* '<S43>/Hough Transform' */
  real_T HoughTransform_o2_j[180];     /* '<S43>/Hough Transform' */
  real_T HoughTransform_o3_d[287];     /* '<S43>/Hough Transform' */
  real_T HoughTransform_o1_dv[51660];  /* '<S44>/Hough Transform' */
  real_T HoughTransform_o2_h[180];     /* '<S44>/Hough Transform' */
  real_T HoughTransform_o3_j[287];     /* '<S44>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S8>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S8>/GetHeadingToPath' */
  real_T BWleft[9600];                 /* '<S40>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S40>/Get Brightest Pixel Per Column and Row' */
  real_T DataStoreRead;                /* '<S4>/Data Store Read' */
  real_T Add;                          /* '<S21>/Add' */
  real_T Add1;                         /* '<S21>/Add1' */
  real_T BlobArea;                     /* '<S3>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S3>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S3>/Embedded MATLAB Function' */
  real_T DataStoreRead_l;              /* '<S13>/Data Store Read' */
  real_T MedianFilterGreen[19200];     /* '<S20>/Median Filter Green' */
  real32_T Resize[19200];              /* '<S2>/Resize' */
  real32_T Resize1[19200];             /* '<S2>/Resize1' */
  real32_T Resize2[19200];             /* '<S2>/Resize2' */
  real32_T SFunction_o13;              /* '<Root>/Chart' */
  real32_T SFunction_o14;              /* '<Root>/Chart' */
  real32_T SFunction_o19;              /* '<Root>/Chart' */
  real32_T SFunction_o20;              /* '<Root>/Chart' */
  real32_T SFunction_o33;              /* '<Root>/Chart' */
  real32_T SFunction_o34;              /* '<Root>/Chart' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  int32_T HoughLines[8];               /* '<S12>/Hough Lines' */
  int8_T Right;                        /* '<Root>/Chart' */
  int8_T Left;                         /* '<Root>/Chart' */
  int8_T Vertical;                     /* '<Root>/Chart' */
  int8_T CameraPosition;               /* '<Root>/Chart' */
  int8_T DoubleToint1;                 /* '<S10>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S10>/DoubleToint8' */
  int8_T DoubleToInt8;                 /* '<S5>/Double To Int8' */
  int8_T DoubleToint1_j;               /* '<S5>/DoubleToint1' */
  int8_T DoubleToint8_p;               /* '<S5>/DoubleToint8' */
  int8_T DataTypeConversion;           /* '<S22>/Data Type Conversion' */
  int8_T DoubleToInt8_c;               /* '<S14>/Double To Int8' */
  int8_T DoubleToint1_c;               /* '<S14>/DoubleToint1' */
  int8_T DoubleToint8_b;               /* '<S14>/DoubleToint8' */
  uint8_T State;                       /* '<Root>/Chart' */
  uint8_T vidB[307200];                /* '<S2>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T vidR[307200];                /* '<S2>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T vidG[307200];                /* '<S2>/Y-Cb-Cr to RGB Color Space  Conversion' */
  boolean_T SFunction_o26[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o27[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o30[19200];      /* '<Root>/Chart' */
  boolean_T DataTypeConversion_a[19200];/* '<S53>/Data Type Conversion' */
  boolean_T DataTypeConversion_f[9600];/* '<S40>/Data Type Conversion' */
  boolean_T DataTypeConversion1[9600]; /* '<S40>/Data Type Conversion1' */
  boolean_T LogicalOperator1[19200];   /* '<S3>/Logical Operator1' */
  boolean_T Compare[19200];            /* '<S32>/Compare' */
  boolean_T LogicalOperator[19200];    /* '<S3>/Logical Operator' */
  boolean_T Compare_e[19200];          /* '<S17>/Compare' */
  boolean_T Compare_c[19200];          /* '<S63>/Compare' */
  boolean_T LogicalOperator1_k[19200]; /* '<S27>/Logical Operator1' */
  boolean_T LogicalOperator1_e[19200]; /* '<S58>/Logical Operator1' */
  rtB_RunningFollowOnePathMakeHSV RunningFollowOnePathMakeHSVIm_f;/* '<S1>/Running.FollowOnePath.MakeHSVImage' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_a;/* '<S10>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_e;   /* '<S10>/BigError S1' */
  rtB_RunningFollowOnePathOnePath RunningFollowOnePathOnePathMa_m;/* '<S1>/Running.FollowOnePath.OnePath.MaintainDepth' */
  rtB_IsLinePresent_brain sf_IsLinePresent_l;/* '<S44>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S43>/IsLinePresent' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_h;/* '<S5>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_f;   /* '<S5>/BigError S1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S14>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S14>/BigError S1' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S52>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S51>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_e;                  /* '<S37>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S35>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S38>/UD' */
  real_T HeadingDiscreteTimeIntegrator_d;/* '<S36>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S24>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S23>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_d;                  /* '<S26>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S25>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S68>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_e;/* '<S66>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_b;                  /* '<S69>/UD' */
  real_T HeadingDiscreteTimeIntegrato_dv;/* '<S67>/Heading Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/Chart' */
  real_T OldObstacle;                  /* '<Root>/Chart' */
  real_T countarea;                    /* '<Root>/Chart' */
  real_T DesiredHeadingCount;          /* '<Root>/Chart' */
  real_T OldHeading;                   /* '<Root>/Chart' */
  real_T TrackCount;                   /* '<Root>/Chart' */
  real_T BuoyCount;                    /* '<Root>/Chart' */
  real_T AvgDesiredHeadingAlongPath[2];/* '<Root>/Chart' */
  real_T AvgDesiredHeadingToPath[2];   /* '<Root>/Chart' */
  real_T HeadingAlongPath;             /* '<Root>/Chart' */
  real_T countAlong;                   /* '<Root>/Chart' */
  real_T countTo;                      /* '<Root>/Chart' */
  real_T outliersAlong;                /* '<Root>/Chart' */
  real_T outliersTo;                   /* '<Root>/Chart' */
  real_T Done;                         /* '<Root>/Chart' */
  real_T Image;                        /* '<S4>/Found' */
  real_T MedianFilterRed_PaddedInput[20336];/* '<S20>/Median Filter Red' */
  real_T Image_c;                      /* '<S13>/Data Store Memory' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S2>/RGB to HSV Color Space  Conversion' */
  real32_T Resize_IntBuffer[76800];    /* '<S2>/Resize' */
  uint32_T RunningBuoyBuoy_ELAPS_T;    /* '<Root>/Chart' */
  uint32_T RunningBuoyBuoy_PREV_T;     /* '<Root>/Chart' */
  uint32_T RunningFindBuoyStraightLevelCon;/* '<Root>/Chart' */
  uint32_T RunningFindBuoyStraightLevelC_j;/* '<Root>/Chart' */
  uint32_T RunningFollowOnePathOnePathMa_b;/* '<Root>/Chart' */
  uint32_T RunningFollowOnePathOnePathMa_e;/* '<Root>/Chart' */
  uint32_T RunningValidationGateStraightLe;/* '<Root>/Chart' */
  uint32_T RunningValidationGateStraight_g;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S27>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S27>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S27>/Blob Analysis' */
  int8_T If_ActiveSubsystem;           /* '<S10>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S5>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S14>/If' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S2>/Chroma Resampling' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S2>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T is_FollowOnePath;            /* '<Root>/Chart' */
  uint8_T is_OnePath;                  /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S27>/Blob Analysis' */
  boolean_T RunningFindBuoyStraightLevelC_n;/* '<Root>/Chart' */
  boolean_T RunningValidationGateStraight_n;/* '<Root>/Chart' */
  rtDW_RunningFollowOnePathOnePat RunningFollowOnePathOnePathMa_m;/* '<S1>/Running.FollowOnePath.OnePath.MaintainDepth' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S43>/Hough Transform'
   * '<S44>/Hough Transform'
   * '<S55>/Hough Transform'
   */
  real_T pooled11[91];

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S43>/Hough Transform'
   * '<S44>/Hough Transform'
   */
  real_T pooled12;

  /* Computed Parameter: FIRSTRHO_RTP
   * '<S55>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RT;

  /* Computed Parameter: Yweights
   * Referenced by blocks:
   * '<S2>/Resize'
   * '<S2>/Resize1'
   * '<S2>/Resize2'
   */
  real32_T pooled13[960];

  /* Computed Parameter: Xweights
   * Referenced by blocks:
   * '<S2>/Resize'
   * '<S2>/Resize1'
   * '<S2>/Resize2'
   */
  real32_T pooled14[1280];

  /* Computed Parameter: Yindex
   * Referenced by blocks:
   * '<S2>/Resize'
   * '<S2>/Resize1'
   * '<S2>/Resize2'
   */
  int32_T pooled16[960];

  /* Computed Parameter: Xindex
   * Referenced by blocks:
   * '<S2>/Resize'
   * '<S2>/Resize1'
   * '<S2>/Resize2'
   */
  int32_T pooled17[1280];

  /* Computed Parameter: WALKER_RTP
   * Referenced by blocks:
   * '<S3>/Buoy Blob Analysis'
   * '<S27>/Blob Analysis'
   * '<S58>/Blob Analysis'
   */
  int32_T pooled18[8];
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
} ExternalInputs_brain;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int8_T CameraPosition;               /* '<Root>/CameraPosition' */
  real_T BuoyCentroidX;                /* '<Root>/BuoyCentroidX' */
  real_T BuoyCentroidY;                /* '<Root>/BuoyCentroidY' */
  int8_T Thrusters[3];                 /* '<Root>/Thrusters' */
  uint8_T State;                       /* '<Root>/State' */
  real_T DesiredDepth;                 /* '<Root>/DesiredDepth' */
  real_T DesiredHeading;               /* '<Root>/DesiredHeading' */
} ExternalOutputs_brain;

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by blocks:
                                        * '<S15>/Constant'
                                        * '<S28>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S16>/Constant'
                                        * '<S29>/Constant'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S17>/Constant'
                                        * '<S32>/Constant'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S23>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S23>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S23>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S25>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S25>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S25>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by blocks:
                                        * '<S35>/Depth Derivative Gain'
                                        * '<S47>/Depth Derivative Gain'
                                        * '<S66>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by blocks:
                                        * '<S35>/Depth Integral Gain'
                                        * '<S47>/Depth Integral Gain'
                                        * '<S66>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by blocks:
                                        * '<S35>/Depth Proportional Gain'
                                        * '<S47>/Depth Proportional Gain'
                                        * '<S66>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S5>/Heading Forward Velocity'
                                        * '<S5>/Heading Forward Velocity2'
                                        * '<S10>/Heading_Forward_Velocity'
                                        * '<S10>/Heading_Forward_Velocity1'
                                        * '<S14>/Heading_Forward_Velocity'
                                        * '<S14>/Heading_Forward_Velocity1'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by blocks:
                                        * '<S36>/Heading Derivative Gain'
                                        * '<S51>/Heading Derivative Gain'
                                        * '<S67>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by blocks:
                                        * '<S36>/Heading Integral Gain'
                                        * '<S51>/Heading Integral Gain'
                                        * '<S67>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by blocks:
                                        * '<S36>/Heading Proportional Gain'
                                        * '<S51>/Heading Proportional Gain'
                                        * '<S67>/Heading Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * '<S60>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * '<S61>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * '<S63>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S21>/Vision_Forward_Velocity'
                                        * '<S21>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S3>/Buoy Blob Analysis'
                                        * '<S27>/Blob Analysis'
                                        * '<S58>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S3>/Buoy Blob Analysis'
                                        * '<S27>/Blob Analysis'
                                        * '<S58>/Blob Analysis'
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

/* Model entry point functions */
extern void brain_initialize(void);
extern void brain_step(void);
extern void brain_terminate(void);

/* Real-time Model object */
extern RT_MODEL_brain *brain_M;

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
 * '<S1>'   : brain/Chart
 * '<S2>'   : brain/GetVideo1
 * '<S3>'   : brain/Chart/Running.Buoy.Buoy
 * '<S4>'   : brain/Chart/Running.FindBuoy.LookforBuoy
 * '<S5>'   : brain/Chart/Running.FindBuoy.StraightLevelControl
 * '<S6>'   : brain/Chart/Running.FollowOnePath.MakeHSVImage
 * '<S7>'   : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S8>'   : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings
 * '<S9>'   : brain/Chart/Running.FollowOnePath.OnePath.MaintainDepth
 * '<S10>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainHeading
 * '<S11>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel
 * '<S12>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine
 * '<S13>'  : brain/Chart/Running.ValidationGate.LookforTrack
 * '<S14>'  : brain/Chart/Running.ValidationGate.StraightLevelControl
 * '<S15>'  : brain/Chart/Running.Buoy.Buoy/Buoy HueHigher
 * '<S16>'  : brain/Chart/Running.Buoy.Buoy/Buoy HueLower
 * '<S17>'  : brain/Chart/Running.Buoy.Buoy/Buoy Saturation
 * '<S18>'  : brain/Chart/Running.Buoy.Buoy/Embedded MATLAB Function
 * '<S19>'  : brain/Chart/Running.Buoy.Buoy/Embedded MATLAB Function1
 * '<S20>'  : brain/Chart/Running.Buoy.Buoy/Median Filter
 * '<S21>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl
 * '<S22>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl
 * '<S23>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S24>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S25>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S26>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S27>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis
 * '<S28>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S29>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S30>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/FoundBuoy
 * '<S31>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/NoBuoy
 * '<S32>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S33>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/BigError S1
 * '<S34>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/BigNegativeError S2
 * '<S35>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Depth S3
 * '<S36>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Heading S4
 * '<S37>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S38>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S39>'  : brain/Chart/Running.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S40>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S41>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S42>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S43>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S44>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S45>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S46>'  : brain/Chart/Running.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S47>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3
 * '<S48>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S49>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainHeading/BigError S1
 * '<S50>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainHeading/BigNegativeError S2
 * '<S51>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4
 * '<S52>'  : brain/Chart/Running.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S53>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel
 * '<S54>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S55>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff
 * '<S56>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/IsLineNearCenter
 * '<S57>'  : brain/Chart/Running.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff/IsLinePresent
 * '<S58>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack
 * '<S59>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S60>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S61>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S62>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S63>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S64>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/BigError S1
 * '<S65>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/BigNegativeError S2
 * '<S66>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Depth S3
 * '<S67>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Heading S4
 * '<S68>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S69>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
