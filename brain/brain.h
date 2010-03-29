/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.243
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Mar  2 17:24:21 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Mar  2 17:24:21 2010
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

/* Block signals for system '<S18>/BigError S1' */
typedef struct {
  real_T Add;                          /* '<S70>/Add' */
  real_T Constant1;                    /* '<S70>/Constant1' */
} rtB_BigErrorS1_brain;

/* Block signals for system '<S18>/BigNegativeError S2' */
typedef struct {
  real_T Add;                          /* '<S71>/Add' */
  real_T Constant1;                    /* '<S71>/Constant1' */
} rtB_BigNegativeErrorS2_brain;

/* Block signals for system '<S49>/IsLinePresent' */
typedef struct {
  real_T Theta[2];                     /* '<S49>/IsLinePresent' */
  real_T Rho[2];                       /* '<S49>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S49>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S13>/Double To Int8' */
} rtB_RunningAutonomousFollowOneP;

/* Block states (auto storage) for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S54>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S53>/Depth Discrete-Time Integrator' */
  uint32_T RunningAutonomousFollowOnePat_h;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePat_j;/* '<Root>/Chart' */
} rtDW_RunningAutonomousFollowOne;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S10>/PutHSVImageTogether' */
} rtB_RunningAutonomousFollowOn_c;

/* Block signals (auto storage) */
typedef struct {
  real_T DesiredDepth;                 /* '<Root>/Chart' */
  real_T DesiredHeading;               /* '<Root>/Chart' */
  real_T BuoyCentroidX;                /* '<Root>/Chart' */
  real_T BuoyCentroidY;                /* '<Root>/Chart' */
  real_T SFunction_o12[19200];         /* '<Root>/Chart' */
  real_T SFunction_o13[19200];         /* '<Root>/Chart' */
  real_T SFunction_o16;                /* '<Root>/Chart' */
  real_T SFunction_o17;                /* '<Root>/Chart' */
  real_T SFunction_o18[19200];         /* '<Root>/Chart' */
  real_T SFunction_o19[19200];         /* '<Root>/Chart' */
  real_T SFunction_o22;                /* '<Root>/Chart' */
  real_T SFunction_o23;                /* '<Root>/Chart' */
  real_T SFunction_o24[19200];         /* '<Root>/Chart' */
  real_T SFunction_o25[19200];         /* '<Root>/Chart' */
  real_T SFunction_o26[57600];         /* '<Root>/Chart' */
  real_T SFunction_o29;                /* '<Root>/Chart' */
  real_T SFunction_o30[57600];         /* '<Root>/Chart' */
  real_T SFunction_o32;                /* '<Root>/Chart' */
  real_T SFunction_o33;                /* '<Root>/Chart' */
  real_T SFunction_o36;                /* '<Root>/Chart' */
  real_T SFunction_o37;                /* '<Root>/Chart' */
  real_T SFunction_o38[19200];         /* '<Root>/Chart' */
  real_T SFunction_o39[19200];         /* '<Root>/Chart' */
  real_T SFunction_o40[19200];         /* '<Root>/Chart' */
  real_T SFunction_o41;                /* '<Root>/Chart' */
  real_T SFunction_o42;                /* '<Root>/Chart' */
  real_T SFunction_o43;                /* '<Root>/Chart' */
  real_T HoughTransform_o1[71820];     /* '<S61>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S61>/Hough Transform' */
  real_T HoughTransform_o3[399];       /* '<S61>/Hough Transform' */
  real_T Close;                        /* '<S16>/IsLineNearCenter' */
  real_T BooleanImage[19200];          /* '<S59>/Get Brightest Pixel Per Column and Row' */
  real_T HoughTransform_o1_i[51660];   /* '<S49>/Hough Transform' */
  real_T HoughTransform_o2_e[180];     /* '<S49>/Hough Transform' */
  real_T HoughTransform_o3_n[287];     /* '<S49>/Hough Transform' */
  real_T HoughTransform_o1_d[51660];   /* '<S50>/Hough Transform' */
  real_T HoughTransform_o2_m[180];     /* '<S50>/Hough Transform' */
  real_T HoughTransform_o3_k[287];     /* '<S50>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S12>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S12>/GetHeadingToPath' */
  real_T BWleft[9600];                 /* '<S46>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S46>/Get Brightest Pixel Per Column and Row' */
  real_T DataStoreRead;                /* '<S8>/Data Store Read' */
  real_T Add;                          /* '<S27>/Add' */
  real_T Add1;                         /* '<S27>/Add1' */
  real_T BlobArea;                     /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S7>/Embedded MATLAB Function' */
  real_T DataStoreRead_b;              /* '<S17>/Data Store Read' */
  real_T MedianFilterS[19200];         /* '<S26>/Median Filter S' */
  real32_T Resize[19200];              /* '<S6>/Resize' */
  real32_T Resize1[19200];             /* '<S6>/Resize1' */
  real32_T Resize2[19200];             /* '<S6>/Resize2' */
  real32_T SFunction_o14;              /* '<Root>/Chart' */
  real32_T SFunction_o15;              /* '<Root>/Chart' */
  real32_T SFunction_o20;              /* '<Root>/Chart' */
  real32_T SFunction_o21;              /* '<Root>/Chart' */
  real32_T SFunction_o34;              /* '<Root>/Chart' */
  real32_T SFunction_o35;              /* '<Root>/Chart' */
  real32_T SFunction_o44;              /* '<Root>/Chart' */
  real32_T SFunction_o45;              /* '<Root>/Chart' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  int32_T HoughLines[8];               /* '<S16>/Hough Lines' */
  int8_T Left;                         /* '<Root>/Chart' */
  int8_T Right;                        /* '<Root>/Chart' */
  int8_T Strafe;                       /* '<Root>/Chart' */
  int8_T Vertical;                     /* '<Root>/Chart' */
  int8_T CameraPosition;               /* '<Root>/Chart' */
  int8_T DoubleToint1;                 /* '<S20>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S20>/DoubleToint8' */
  int8_T DoubleToint1_c;               /* '<S14>/DoubleToint1' */
  int8_T DoubleToint8_l;               /* '<S14>/DoubleToint8' */
  int8_T DoubleToInt8;                 /* '<S9>/Double To Int8' */
  int8_T DoubleToint1_l;               /* '<S9>/DoubleToint1' */
  int8_T DoubleToint8_c;               /* '<S9>/DoubleToint8' */
  int8_T DataTypeConversion;           /* '<S28>/Data Type Conversion' */
  int8_T DoubleToInt8_l;               /* '<S18>/Double To Int8' */
  int8_T DoubleToint1_j;               /* '<S18>/DoubleToint1' */
  int8_T DoubleToint8_i;               /* '<S18>/DoubleToint8' */
  uint8_T RGBVid_R[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T State;                       /* '<Root>/Chart' */
  uint8_T ChromaResampling_o1[307200]; /* '<S6>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S6>/Chroma Resampling' */
  boolean_T SFunction_o27[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o28[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o31[19200];      /* '<Root>/Chart' */
  boolean_T DataTypeConversion_h[19200];/* '<S59>/Data Type Conversion' */
  boolean_T BWleft_i[9600];            /* '<S46>/Data Type Conversion' */
  boolean_T BWright_e[9600];           /* '<S46>/Data Type Conversion1' */
  boolean_T BW[19200];                 /* '<S7>/Logical Operator1' */
  boolean_T Compare[19200];            /* '<S38>/Compare' */
  boolean_T LogicalOperator[19200];    /* '<S7>/Logical Operator' */
  boolean_T Compare_d[19200];          /* '<S23>/Compare' */
  boolean_T Compare_e[19200];          /* '<S69>/Compare' */
  boolean_T BW_p[19200];               /* '<S33>/Logical Operator1' */
  boolean_T BW_a[19200];               /* '<S64>/Logical Operator1' */
  rtB_RunningAutonomousFollowOneP RunningControlledRCMaintainDept;/* '<S1>/Running.ControlledRC.MaintainDepth' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_a;/* '<S20>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_a;   /* '<S20>/BigError S1' */
  rtB_RunningAutonomousFollowOn_c RunningAutonomousFollowOnePat_i;/* '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_n;/* '<S14>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_m;   /* '<S14>/BigError S1' */
  rtB_RunningAutonomousFollowOneP RunningAutonomousFollowOnePa_mg;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
  rtB_IsLinePresent_brain sf_IsLinePresent_j;/* '<S50>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S49>/IsLinePresent' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_h;/* '<S9>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_b;   /* '<S9>/BigError S1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S18>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S18>/BigError S1' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S81>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S80>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_f;                  /* '<S58>/UD' */
  real_T HeadingDiscreteTimeIntegrator_h;/* '<S57>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_g;                  /* '<S43>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S41>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S44>/UD' */
  real_T HeadingDiscreteTimeIntegrator_g;/* '<S42>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_gx;                 /* '<S30>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S29>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S32>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S31>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S74>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_a;/* '<S72>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_k;                  /* '<S75>/UD' */
  real_T HeadingDiscreteTimeIntegrator_m;/* '<S73>/Heading Discrete-Time Integrator' */
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
  real_T Image;                        /* '<S8>/Found' */
  real_T MedianFilterH_PaddedInput[20336];/* '<S26>/Median Filter H' */
  real_T Image_d;                      /* '<S17>/Data Store Memory' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T Resize_IntBuffer[76800];    /* '<S6>/Resize' */
  uint32_T RunningAutonomousBuoyBuoy_ELAPS;/* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyBuoy_PREV_;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFindBuoyStraig;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFindBuoyStra_g;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePat_a;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePat_m;/* '<Root>/Chart' */
  uint32_T RunningAutonomousValidationGate;/* '<Root>/Chart' */
  uint32_T RunningAutonomousValidationGa_h;/* '<Root>/Chart' */
  uint32_T RunningControlledRCMaintainHead;/* '<Root>/Chart' */
  uint32_T RunningControlledRCMaintainHe_i;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S33>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S33>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S33>/Blob Analysis' */
  int8_T If_ActiveSubsystem;           /* '<S20>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S14>/If' */
  int8_T If_ActiveSubsystem_m;         /* '<S9>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S18>/If' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S6>/Chroma Resampling' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_Autonomous;               /* '<Root>/Chart' */
  uint8_T is_FollowOnePath;            /* '<Root>/Chart' */
  uint8_T is_OnePath;                  /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S33>/Blob Analysis' */
  boolean_T RunningAutonomousFindBuoyStr_gx;/* '<Root>/Chart' */
  boolean_T RunningAutonomousValidationGa_n;/* '<Root>/Chart' */
  rtDW_RunningAutonomousFollowOne RunningControlledRCMaintainDept;/* '<S1>/Running.ControlledRC.MaintainDepth' */
  rtDW_RunningAutonomousFollowOne RunningAutonomousFollowOnePa_mg;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S49>/Hough Transform'
   * '<S50>/Hough Transform'
   * '<S61>/Hough Transform'
   */
  real_T pooled11[91];

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S49>/Hough Transform'
   * '<S50>/Hough Transform'
   */
  real_T pooled12;

  /* Computed Parameter: FIRSTRHO_RTP
   * '<S61>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RT;

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
   * '<S7>/Buoy Blob Analysis'
   * '<S33>/Blob Analysis'
   * '<S64>/Blob Analysis'
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
  uint8_T State;                       /* '<Root>/State' */
  real_T DesiredDepth;                 /* '<Root>/DesiredDepth' */
  real_T DesiredHeading;               /* '<Root>/DesiredHeading' */
} ExternalOutputs_brain;

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by blocks:
                                        * '<S21>/Constant'
                                        * '<S34>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S22>/Constant'
                                        * '<S35>/Constant'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S23>/Constant'
                                        * '<S38>/Constant'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S29>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S29>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S29>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S31>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S31>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S31>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by blocks:
                                        * '<S41>/Depth Derivative Gain'
                                        * '<S53>/Depth Derivative Gain'
                                        * '<S72>/Depth Derivative Gain'
                                        * '<S76>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by blocks:
                                        * '<S41>/Depth Integral Gain'
                                        * '<S53>/Depth Integral Gain'
                                        * '<S72>/Depth Integral Gain'
                                        * '<S76>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by blocks:
                                        * '<S41>/Depth Proportional Gain'
                                        * '<S53>/Depth Proportional Gain'
                                        * '<S72>/Depth Proportional Gain'
                                        * '<S76>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S9>/Heading Forward Velocity'
                                        * '<S9>/Heading Forward Velocity2'
                                        * '<S14>/Heading_Forward_Velocity'
                                        * '<S14>/Heading_Forward_Velocity1'
                                        * '<S18>/Heading_Forward_Velocity'
                                        * '<S18>/Heading_Forward_Velocity1'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by blocks:
                                        * '<S42>/Heading Derivative Gain'
                                        * '<S57>/Heading Derivative Gain'
                                        * '<S73>/Heading Derivative Gain'
                                        * '<S80>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by blocks:
                                        * '<S42>/Heading Integral Gain'
                                        * '<S57>/Heading Integral Gain'
                                        * '<S73>/Heading Integral Gain'
                                        * '<S80>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by blocks:
                                        * '<S42>/Heading Proportional Gain'
                                        * '<S57>/Heading Proportional Gain'
                                        * '<S73>/Heading Proportional Gain'
                                        * '<S80>/Heading Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * '<S66>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * '<S67>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * '<S69>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S27>/Vision_Forward_Velocity'
                                        * '<S27>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S7>/Buoy Blob Analysis'
                                        * '<S33>/Blob Analysis'
                                        * '<S64>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S7>/Buoy Blob Analysis'
                                        * '<S33>/Blob Analysis'
                                        * '<S64>/Blob Analysis'
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
 * '<S7>'   : brain/Chart/Running.Autonomous.Buoy.Buoy
 * '<S8>'   : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy
 * '<S9>'   : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl
 * '<S10>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage
 * '<S11>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S12>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings
 * '<S13>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth
 * '<S14>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading
 * '<S15>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel
 * '<S16>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine
 * '<S17>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack
 * '<S18>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl
 * '<S19>'  : brain/Chart/Running.ControlledRC.MaintainDepth
 * '<S20>'  : brain/Chart/Running.ControlledRC.MaintainHeading
 * '<S21>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueHigher
 * '<S22>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueLower
 * '<S23>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy Saturation
 * '<S24>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function
 * '<S25>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function1
 * '<S26>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Median Filter
 * '<S27>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl
 * '<S28>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl
 * '<S29>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S30>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S31>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S32>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S33>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis
 * '<S34>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S35>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S36>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/FoundBuoy
 * '<S37>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/NoBuoy
 * '<S38>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S39>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/BigError S1
 * '<S40>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/BigNegativeError S2
 * '<S41>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Depth S3
 * '<S42>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Heading S4
 * '<S43>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S44>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S45>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S46>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S47>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S48>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S49>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S50>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S51>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S52>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S53>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3
 * '<S54>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S55>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/BigError S1
 * '<S56>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/BigNegativeError S2
 * '<S57>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4
 * '<S58>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S59>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel
 * '<S60>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.GetBrightestPixel/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S61>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff
 * '<S62>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/IsLineNearCenter
 * '<S63>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MoveOverPath.IsAUVonPathLine/Hough Transform Stuff/IsLinePresent
 * '<S64>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack
 * '<S65>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S66>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S67>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S68>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S69>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S70>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/BigError S1
 * '<S71>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/BigNegativeError S2
 * '<S72>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Depth S3
 * '<S73>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Heading S4
 * '<S74>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S75>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S76>'  : brain/Chart/Running.ControlledRC.MaintainDepth/PID Controller Depth S3
 * '<S77>'  : brain/Chart/Running.ControlledRC.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S78>'  : brain/Chart/Running.ControlledRC.MaintainHeading/BigError S1
 * '<S79>'  : brain/Chart/Running.ControlledRC.MaintainHeading/BigNegativeError S2
 * '<S80>'  : brain/Chart/Running.ControlledRC.MaintainHeading/PID Controller Heading S4
 * '<S81>'  : brain/Chart/Running.ControlledRC.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 */

/*
 * Requirements for '<Root>' : brain
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
