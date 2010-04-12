/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.267
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Mon Apr 12 17:04:50 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Mon Apr 12 17:04:51 2010
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

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S11>/PutHSVImageTogether' */
} rtB_RunningAutonomousFollowOneP;

/* Block signals for system '<S8>/BigError S1' */
typedef struct {
  real_T Add;                          /* '<S18>/Add' */
  real_T Constant1;                    /* '<S18>/Constant1' */
} rtB_BigErrorS1_brain;

/* Block signals for system '<S8>/BigNegativeError S2' */
typedef struct {
  real_T Add;                          /* '<S19>/Add' */
  real_T Constant1;                    /* '<S19>/Constant1' */
} rtB_BigNegativeErrorS2_brain;

/* Block signals for system '<S43>/IsLinePresent' */
typedef struct {
  real_T Theta[2];                     /* '<S43>/IsLinePresent' */
  real_T Rho[2];                       /* '<S43>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S43>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S1>/StraightLevelControl' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S15>/Double To Int8' */
  int8_T DoubleToint1;                 /* '<S15>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S15>/DoubleToint8' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S15>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S15>/BigError S1' */
} rtB_StraightLevelControl_brain;

/* Block states (auto storage) for system '<S1>/StraightLevelControl' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S57>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S55>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_e;                  /* '<S58>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S56>/Heading Discrete-Time Integrator' */
  uint32_T StraightLevelControl_ELAPS_T;/* '<Root>/Chart' */
  uint32_T StraightLevelControl_PREV_T;/* '<Root>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S15>/If' */
  boolean_T StraightLevelControl_RESET_ELAP;/* '<Root>/Chart' */
} rtDW_StraightLevelControl_brain;

/* Block signals for system '<S1>/MaintainDepth' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S7>/Double To Int8' */
} rtB_MaintainDepth_brain;

/* Block states (auto storage) for system '<S1>/MaintainDepth' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S17>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S16>/Depth Discrete-Time Integrator' */
  uint32_T MaintainDepth_ELAPS_T;      /* '<Root>/Chart' */
  uint32_T MaintainDepth_PREV_T;       /* '<Root>/Chart' */
} rtDW_MaintainDepth_brain;

/* Block signals (auto storage) */
typedef struct {
  real_T DesiredDepth;                 /* '<Root>/Chart' */
  real_T DesiredHeading;               /* '<Root>/Chart' */
  real_T BuoyCentroidX;                /* '<Root>/Chart' */
  real_T BuoyCentroidY;                /* '<Root>/Chart' */
  real_T SFunction_o12[19200];         /* '<Root>/Chart' */
  real_T SFunction_o13[19200];         /* '<Root>/Chart' */
  real_T SFunction_o14[19200];         /* '<Root>/Chart' */
  real_T SFunction_o15[19200];         /* '<Root>/Chart' */
  real_T SFunction_o16[19200];         /* '<Root>/Chart' */
  real_T SFunction_o17[19200];         /* '<Root>/Chart' */
  real_T SFunction_o18[19200];         /* '<Root>/Chart' */
  real_T SFunction_o19;                /* '<Root>/Chart' */
  real_T SFunction_o20;                /* '<Root>/Chart' */
  real_T SFunction_o21;                /* '<Root>/Chart' */
  real_T SFunction_o22[19200];         /* '<Root>/Chart' */
  real_T SFunction_o23[19200];         /* '<Root>/Chart' */
  real_T SFunction_o24[57600];         /* '<Root>/Chart' */
  real_T SFunction_o27;                /* '<Root>/Chart' */
  real_T SFunction_o30;                /* '<Root>/Chart' */
  real_T SFunction_o31;                /* '<Root>/Chart' */
  real_T HoughTransform_o1[51660];     /* '<S43>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S43>/Hough Transform' */
  real_T HoughTransform_o3[287];       /* '<S43>/Hough Transform' */
  real_T HoughTransform_o1_d[51660];   /* '<S44>/Hough Transform' */
  real_T HoughTransform_o2_m[180];     /* '<S44>/Hough Transform' */
  real_T HoughTransform_o3_k[287];     /* '<S44>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S13>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S13>/GetHeadingToPath' */
  real_T BWleft[9600];                 /* '<S40>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S40>/Get Brightest Pixel Per Column and Row' */
  real_T Image;                        /* '<S34>/IF Buoy Conditions' */
  real_T Add;                          /* '<S28>/Add' */
  real_T Add1;                         /* '<S28>/Add1' */
  real_T BlobArea;                     /* '<S9>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S9>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S9>/Embedded MATLAB Function' */
  real_T DataStoreRead;                /* '<S14>/Data Store Read' */
  real_T MedianFilterS[19200];         /* '<S27>/Median Filter S' */
  real32_T Resize[19200];              /* '<S6>/Resize' */
  real32_T Resize1[19200];             /* '<S6>/Resize1' */
  real32_T Resize2[19200];             /* '<S6>/Resize2' */
  real32_T SFunction_o28;              /* '<Root>/Chart' */
  real32_T SFunction_o29;              /* '<Root>/Chart' */
  real32_T SFunction_o32;              /* '<Root>/Chart' */
  real32_T SFunction_o33;              /* '<Root>/Chart' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  int8_T Left;                         /* '<Root>/Chart' */
  int8_T Right;                        /* '<Root>/Chart' */
  int8_T Strafe;                       /* '<Root>/Chart' */
  int8_T Vertical;                     /* '<Root>/Chart' */
  int8_T CameraPosition;               /* '<Root>/Chart' */
  int8_T State;                        /* '<Root>/Chart' */
  int8_T DoubleToint1;                 /* '<S8>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S8>/DoubleToint8' */
  int8_T DataTypeConversion;           /* '<S29>/Data Type Conversion' */
  uint8_T RGBVid_R[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T ChromaResampling_o1[307200]; /* '<S6>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S6>/Chroma Resampling' */
  boolean_T SFunction_o25[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o26[9600];       /* '<Root>/Chart' */
  boolean_T BWleft_i[9600];            /* '<S40>/Data Type Conversion' */
  boolean_T BWright_e[9600];           /* '<S40>/Data Type Conversion1' */
  boolean_T BW[19200];                 /* '<S9>/Logical Operator1' */
  boolean_T Compare[19200];            /* '<S38>/Compare' */
  boolean_T LogicalOperator[19200];    /* '<S9>/Logical Operator' */
  boolean_T Compare_d[19200];          /* '<S24>/Compare' */
  boolean_T Compare_e[19200];          /* '<S52>/Compare' */
  boolean_T BW_p[19200];               /* '<S34>/Logical Operator1' */
  boolean_T BW_a[19200];               /* '<S47>/Logical Operator1' */
  rtB_MaintainDepth_brain MaintainDepth;/* '<S1>/MaintainDepth' */
  rtB_StraightLevelControl_brain StraightLevelControl;/* '<S1>/StraightLevelControl' */
  rtB_IsLinePresent_brain sf_IsLinePresent_j;/* '<S44>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S43>/IsLinePresent' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S8>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S8>/BigError S1' */
  rtB_RunningAutonomousFollowOneP RunningAutonomousFollowOnePat_i;/* '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S21>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S20>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_g;                  /* '<S31>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S30>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S33>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S32>/Y-Buoy Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/Chart' */
  real_T countarea;                    /* '<Root>/Chart' */
  real_T DesiredHeadingCount;          /* '<Root>/Chart' */
  real_T OldHeading;                   /* '<Root>/Chart' */
  real_T TrackCount;                   /* '<Root>/Chart' */
  real_T BuoyCount;                    /* '<Root>/Chart' */
  real_T AvgDesiredHeadingAlongPath[2];/* '<Root>/Chart' */
  real_T AvgDesiredHeadingToPath[2];   /* '<Root>/Chart' */
  real_T countAlong;                   /* '<Root>/Chart' */
  real_T countTo;                      /* '<Root>/Chart' */
  real_T outliersAlong;                /* '<Root>/Chart' */
  real_T outliersTo;                   /* '<Root>/Chart' */
  real_T Done;                         /* '<Root>/Chart' */
  real_T MedianFilterH_PaddedInput[20336];/* '<S27>/Median Filter H' */
  real_T Image;                        /* '<S14>/Data Store Memory' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T Resize_IntBuffer[76800];    /* '<S6>/Resize' */
  uint32_T MaintainHeading_ELAPS_T;    /* '<Root>/Chart' */
  uint32_T MaintainHeading_PREV_T;     /* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyBuoy_ELAPS;/* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyBuoy_PREV_;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S34>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S34>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S34>/Blob Analysis' */
  int8_T If_ActiveSubsystem;           /* '<S8>/If' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S6>/Chroma Resampling' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_Autonomous;               /* '<Root>/Chart' */
  uint8_T is_FollowOnePath;            /* '<Root>/Chart' */
  uint8_T is_OnePath;                  /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S34>/Blob Analysis' */
  boolean_T OldObstacle;               /* '<Root>/Chart' */
  rtDW_MaintainDepth_brain MaintainDepth;/* '<S1>/MaintainDepth' */
  rtDW_StraightLevelControl_brain StraightLevelControl;/* '<S1>/StraightLevelControl' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S43>/Hough Transform'
   * '<S44>/Hough Transform'
   */
  real_T pooled11[91];

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S43>/Hough Transform'
   * '<S44>/Hough Transform'
   */
  real_T pooled12;

  /* Computed Parameter: Yweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  real32_T pooled13[960];

  /* Computed Parameter: Xweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  real32_T pooled14[1280];

  /* Computed Parameter: Yindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  int32_T pooled16[960];

  /* Computed Parameter: Xindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  int32_T pooled17[1280];

  /* Computed Parameter: WALKER_RTP
   * Referenced by blocks:
   * '<S9>/Buoy Blob Analysis'
   * '<S34>/Blob Analysis'
   * '<S47>/Blob Analysis'
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
  int8_T Thrusters[4];                 /* '<Root>/Thrusters' */
  int8_T State;                        /* '<Root>/State' */
  real_T DesiredDepth;                 /* '<Root>/DesiredDepth' */
  real_T DesiredHeading;               /* '<Root>/DesiredHeading' */
} ExternalOutputs_brain;

/* Parameters for system: '<S1>/StraightLevelControl' */
struct rtP_StraightLevelControl_brain_ {
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by blocks:
                                        * '<S16>/Depth Derivative Gain'
                                        * '<S55>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by blocks:
                                        * '<S16>/Depth Integral Gain'
                                        * '<S55>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by blocks:
                                        * '<S16>/Depth Proportional Gain'
                                        * '<S55>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S15>/Heading_Forward_Velocity'
                                        * '<S15>/Heading_Forward_Velocity1'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by blocks:
                                        * '<S22>/Constant'
                                        * '<S35>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S23>/Constant'
                                        * '<S36>/Constant'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * '<S34>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * '<S34>/Constant3'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * '<S34>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * '<S34>/Constant2'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S24>/Constant'
                                        * '<S38>/Constant'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S30>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S30>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S30>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S32>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S32>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S32>/Y-Buoy Proportional Gain'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by blocks:
                                        * '<S20>/Heading Derivative Gain'
                                        * '<S56>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by blocks:
                                        * '<S20>/Heading Integral Gain'
                                        * '<S56>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by blocks:
                                        * '<S20>/Heading Proportional Gain'
                                        * '<S56>/Heading Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * '<S49>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * '<S50>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * '<S52>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S28>/Vision_Forward_Velocity'
                                        * '<S28>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S9>/Buoy Blob Analysis'
                                        * '<S34>/Blob Analysis'
                                        * '<S47>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S9>/Buoy Blob Analysis'
                                        * '<S34>/Blob Analysis'
                                        * '<S47>/Blob Analysis'
                                        */
  rtP_StraightLevelControl_brain StraightLevelControl;/* '<S1>/StraightLevelControl' */
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

  extern RT_MODEL_brain *brain_M;

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
 * '<S1>'   : brain/Chart
 * '<S2>'   : brain/Environment Controller
 * '<S3>'   : brain/Environment Controller1
 * '<S4>'   : brain/Environment Controller2
 * '<S5>'   : brain/Environment Controller3
 * '<S6>'   : brain/GetVideo1
 * '<S7>'   : brain/Chart/MaintainDepth
 * '<S8>'   : brain/Chart/MaintainHeading
 * '<S9>'   : brain/Chart/Running.Autonomous.Buoy.Buoy
 * '<S10>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy
 * '<S11>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage
 * '<S12>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S13>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings
 * '<S14>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack
 * '<S15>'  : brain/Chart/StraightLevelControl
 * '<S16>'  : brain/Chart/MaintainDepth/PID Controller Depth S3
 * '<S17>'  : brain/Chart/MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S18>'  : brain/Chart/MaintainHeading/BigError S1
 * '<S19>'  : brain/Chart/MaintainHeading/BigNegativeError S2
 * '<S20>'  : brain/Chart/MaintainHeading/PID Controller Heading S4
 * '<S21>'  : brain/Chart/MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S22>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueHigher
 * '<S23>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueLower
 * '<S24>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy Saturation
 * '<S25>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function
 * '<S26>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function1
 * '<S27>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Median Filter
 * '<S28>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl
 * '<S29>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl
 * '<S30>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S31>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S32>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S33>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S34>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis
 * '<S35>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S36>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S37>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions
 * '<S38>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S39>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S40>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S41>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S42>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S43>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S44>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S45>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S46>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S47>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack
 * '<S48>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S49>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S50>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S51>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S52>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S53>'  : brain/Chart/StraightLevelControl/BigError S1
 * '<S54>'  : brain/Chart/StraightLevelControl/BigNegativeError S2
 * '<S55>'  : brain/Chart/StraightLevelControl/PID Controller Depth S3
 * '<S56>'  : brain/Chart/StraightLevelControl/PID Controller Heading S4
 * '<S57>'  : brain/Chart/StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S58>'  : brain/Chart/StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 */

/*
 * Requirements for '<Root>' : brain
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
