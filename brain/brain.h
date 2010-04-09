/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.257
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Fri Apr  9 18:55:12 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Fri Apr  9 18:55:12 2010
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

/* Block signals for system '<S16>/BigError S1' */
typedef struct {
  real_T Add;                          /* '<S62>/Add' */
  real_T Constant1;                    /* '<S62>/Constant1' */
} rtB_BigErrorS1_brain;

/* Block signals for system '<S16>/BigNegativeError S2' */
typedef struct {
  real_T Add;                          /* '<S63>/Add' */
  real_T Constant1;                    /* '<S63>/Constant1' */
} rtB_BigNegativeErrorS2_brain;

/* Block signals for system '<S46>/IsLinePresent' */
typedef struct {
  real_T Theta[2];                     /* '<S46>/IsLinePresent' */
  real_T Rho[2];                       /* '<S46>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S46>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S1>/Running.ControlledRC.MaintainDepth' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S17>/Double To Int8' */
} rtB_RunningControlledRCMaintain;

/* Block states (auto storage) for system '<S1>/Running.ControlledRC.MaintainDepth' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S69>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S68>/Depth Discrete-Time Integrator' */
  uint32_T RunningControlledRCMaintainDe_o;/* '<Root>/Chart' */
  uint32_T RunningControlledRCMaintainDe_c;/* '<Root>/Chart' */
} rtDW_RunningControlledRCMaintai;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
typedef struct {
  real_T HSVImage1[57600];             /* '<S10>/PutHSVImageTogether' */
} rtB_RunningAutonomousFollowOneP;

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
  real_T SFunction_o32;                /* '<Root>/Chart' */
  real_T SFunction_o33;                /* '<Root>/Chart' */
  real_T SFunction_o34;                /* '<Root>/Chart' */
  real_T SFunction_o39[19200];         /* '<Root>/Chart' */
  real_T SFunction_o40[19200];         /* '<Root>/Chart' */
  real_T SFunction_o41[19200];         /* '<Root>/Chart' */
  real_T HoughTransform_o1[51660];     /* '<S46>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S46>/Hough Transform' */
  real_T HoughTransform_o3[287];       /* '<S46>/Hough Transform' */
  real_T HoughTransform_o1_d[51660];   /* '<S47>/Hough Transform' */
  real_T HoughTransform_o2_m[180];     /* '<S47>/Hough Transform' */
  real_T HoughTransform_o3_k[287];     /* '<S47>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S12>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S12>/GetHeadingToPath' */
  real_T BWleft[9600];                 /* '<S43>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S43>/Get Brightest Pixel Per Column and Row' */
  real_T Image;                        /* '<S31>/IF Buoy Conditions' */
  real_T Add;                          /* '<S25>/Add' */
  real_T Add1;                         /* '<S25>/Add1' */
  real_T BlobArea;                     /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S7>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S7>/Embedded MATLAB Function' */
  real_T DataStoreRead;                /* '<S15>/Data Store Read' */
  real_T MedianFilterS[19200];         /* '<S24>/Median Filter S' */
  real32_T Resize[19200];              /* '<S6>/Resize' */
  real32_T Resize1[19200];             /* '<S6>/Resize1' */
  real32_T Resize2[19200];             /* '<S6>/Resize2' */
  real32_T SFunction_o14;              /* '<Root>/Chart' */
  real32_T SFunction_o15;              /* '<Root>/Chart' */
  real32_T SFunction_o20;              /* '<Root>/Chart' */
  real32_T SFunction_o21;              /* '<Root>/Chart' */
  real32_T SFunction_o30;              /* '<Root>/Chart' */
  real32_T SFunction_o31;              /* '<Root>/Chart' */
  real32_T SFunction_o35;              /* '<Root>/Chart' */
  real32_T SFunction_o36;              /* '<Root>/Chart' */
  real32_T RGBtoHSVColorSpaceConversion_o1[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o2[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T RGBtoHSVColorSpaceConversion_o3[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  int8_T Left;                         /* '<Root>/Chart' */
  int8_T Right;                        /* '<Root>/Chart' */
  int8_T Strafe;                       /* '<Root>/Chart' */
  int8_T Vertical;                     /* '<Root>/Chart' */
  int8_T CameraPosition;               /* '<Root>/Chart' */
  int8_T State;                        /* '<Root>/Chart' */
  int8_T DoubleToint1_o;               /* '<S18>/DoubleToint1' */
  int8_T DoubleToint8_a;               /* '<S18>/DoubleToint8' */
  int8_T DoubleToInt8;                 /* '<S9>/Double To Int8' */
  int8_T DoubleToint1_l;               /* '<S9>/DoubleToint1' */
  int8_T DoubleToint8_c;               /* '<S9>/DoubleToint8' */
  int8_T DataTypeConversion;           /* '<S26>/Data Type Conversion' */
  int8_T DoubleToInt8_l;               /* '<S16>/Double To Int8' */
  int8_T DoubleToint1_j;               /* '<S16>/DoubleToint1' */
  int8_T DoubleToint8_i;               /* '<S16>/DoubleToint8' */
  uint8_T RGBVid_R[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T ChromaResampling_o1[307200]; /* '<S6>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S6>/Chroma Resampling' */
  boolean_T SFunction_o27[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o28[9600];       /* '<Root>/Chart' */
  boolean_T BWleft_i[9600];            /* '<S43>/Data Type Conversion' */
  boolean_T BWright_e[9600];           /* '<S43>/Data Type Conversion1' */
  boolean_T BW[19200];                 /* '<S7>/Logical Operator1' */
  boolean_T Compare[19200];            /* '<S35>/Compare' */
  boolean_T LogicalOperator[19200];    /* '<S7>/Logical Operator' */
  boolean_T Compare_d[19200];          /* '<S21>/Compare' */
  boolean_T Compare_e[19200];          /* '<S61>/Compare' */
  boolean_T BW_p[19200];               /* '<S31>/Logical Operator1' */
  boolean_T BW_a[19200];               /* '<S56>/Logical Operator1' */
  rtB_RunningAutonomousFollowOneP RunningAutonomousFollowOnePat_i;/* '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_n;/* '<S14>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_m;   /* '<S14>/BigError S1' */
  rtB_RunningControlledRCMaintain RunningAutonomousFollowOnePat_m;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_a;/* '<S18>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_a;   /* '<S18>/BigError S1' */
  rtB_RunningControlledRCMaintain RunningControlledRCMaintainDe_p;/* '<S1>/Running.ControlledRC.MaintainDepth' */
  rtB_IsLinePresent_brain sf_IsLinePresent_j;/* '<S47>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S46>/IsLinePresent' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_h;/* '<S9>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_b;   /* '<S9>/BigError S1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S16>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S16>/BigError S1' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S55>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S54>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_k;                  /* '<S73>/UD' */
  real_T HeadingDiscreteTimeIntegrator_f;/* '<S72>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_g;                  /* '<S40>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S38>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S41>/UD' */
  real_T HeadingDiscreteTimeIntegrator_g;/* '<S39>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_gx;                 /* '<S28>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S27>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S30>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S29>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S66>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_a;/* '<S64>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_kp;                 /* '<S67>/UD' */
  real_T HeadingDiscreteTimeIntegrator_m;/* '<S65>/Heading Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/Chart' */
  real_T OldObstacle;                  /* '<Root>/Chart' */
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
  real_T MedianFilterH_PaddedInput[20336];/* '<S24>/Median Filter H' */
  real_T Image;                        /* '<S15>/Data Store Memory' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T Resize_IntBuffer[76800];    /* '<S6>/Resize' */
  uint32_T RunningAutonomousBuoyBuoy_ELAPS;/* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyBuoy_PREV_;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFindBuoyStraig;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFindBuoyStra_g;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePathO;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePa_m4;/* '<Root>/Chart' */
  uint32_T RunningAutonomousValidationGate;/* '<Root>/Chart' */
  uint32_T RunningAutonomousValidationGa_h;/* '<Root>/Chart' */
  uint32_T RunningControlledRCMaintainHead;/* '<Root>/Chart' */
  uint32_T RunningControlledRCMaintainHe_i;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S31>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S31>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S31>/Blob Analysis' */
  int8_T If_ActiveSubsystem;           /* '<S14>/If' */
  int8_T If_ActiveSubsystem_g;         /* '<S18>/If' */
  int8_T If_ActiveSubsystem_m;         /* '<S9>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S16>/If' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S6>/Chroma Resampling' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_Autonomous;               /* '<Root>/Chart' */
  uint8_T is_FollowOnePath;            /* '<Root>/Chart' */
  uint8_T is_OnePath;                  /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S31>/Blob Analysis' */
  boolean_T RunningAutonomousFindBuoyStr_gx;/* '<Root>/Chart' */
  boolean_T RunningAutonomousValidationGa_n;/* '<Root>/Chart' */
  rtDW_RunningControlledRCMaintai RunningAutonomousFollowOnePat_m;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth' */
  rtDW_RunningControlledRCMaintai RunningControlledRCMaintainDe_p;/* '<S1>/Running.ControlledRC.MaintainDepth' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S46>/Hough Transform'
   * '<S47>/Hough Transform'
   */
  real_T pooled11[91];

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S46>/Hough Transform'
   * '<S47>/Hough Transform'
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
   * '<S7>/Buoy Blob Analysis'
   * '<S31>/Blob Analysis'
   * '<S56>/Blob Analysis'
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

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by blocks:
                                        * '<S19>/Constant'
                                        * '<S32>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S20>/Constant'
                                        * '<S33>/Constant'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * '<S31>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * '<S31>/Constant2'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * '<S31>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * '<S31>/Constant3'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S21>/Constant'
                                        * '<S35>/Constant'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S27>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S27>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S27>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S29>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S29>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S29>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by blocks:
                                        * '<S38>/Depth Derivative Gain'
                                        * '<S50>/Depth Derivative Gain'
                                        * '<S64>/Depth Derivative Gain'
                                        * '<S68>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by blocks:
                                        * '<S38>/Depth Integral Gain'
                                        * '<S50>/Depth Integral Gain'
                                        * '<S64>/Depth Integral Gain'
                                        * '<S68>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by blocks:
                                        * '<S38>/Depth Proportional Gain'
                                        * '<S50>/Depth Proportional Gain'
                                        * '<S64>/Depth Proportional Gain'
                                        * '<S68>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S9>/Heading Forward Velocity'
                                        * '<S9>/Heading Forward Velocity2'
                                        * '<S14>/Heading_Forward_Velocity'
                                        * '<S14>/Heading_Forward_Velocity1'
                                        * '<S16>/Heading_Forward_Velocity'
                                        * '<S16>/Heading_Forward_Velocity1'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by blocks:
                                        * '<S39>/Heading Derivative Gain'
                                        * '<S54>/Heading Derivative Gain'
                                        * '<S65>/Heading Derivative Gain'
                                        * '<S72>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by blocks:
                                        * '<S39>/Heading Integral Gain'
                                        * '<S54>/Heading Integral Gain'
                                        * '<S65>/Heading Integral Gain'
                                        * '<S72>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by blocks:
                                        * '<S39>/Heading Proportional Gain'
                                        * '<S54>/Heading Proportional Gain'
                                        * '<S65>/Heading Proportional Gain'
                                        * '<S72>/Heading Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * '<S58>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * '<S59>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * '<S61>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S25>/Vision_Forward_Velocity'
                                        * '<S25>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S7>/Buoy Blob Analysis'
                                        * '<S31>/Blob Analysis'
                                        * '<S56>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S7>/Buoy Blob Analysis'
                                        * '<S31>/Blob Analysis'
                                        * '<S56>/Blob Analysis'
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
 * '<S15>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack
 * '<S16>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl
 * '<S17>'  : brain/Chart/Running.ControlledRC.MaintainDepth
 * '<S18>'  : brain/Chart/Running.ControlledRC.MaintainHeading
 * '<S19>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueHigher
 * '<S20>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy HueLower
 * '<S21>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Buoy Saturation
 * '<S22>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function
 * '<S23>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Embedded MATLAB Function1
 * '<S24>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Median Filter
 * '<S25>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl
 * '<S26>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl
 * '<S27>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S28>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S29>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S30>'  : brain/Chart/Running.Autonomous.Buoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S31>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis
 * '<S32>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S33>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S34>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions
 * '<S35>'  : brain/Chart/Running.Autonomous.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S36>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/BigError S1
 * '<S37>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/BigNegativeError S2
 * '<S38>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Depth S3
 * '<S39>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Heading S4
 * '<S40>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S41>'  : brain/Chart/Running.Autonomous.FindBuoy.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S42>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S43>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S44>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S45>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S46>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S47>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S48>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S49>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S50>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3
 * '<S51>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S52>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/BigError S1
 * '<S53>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/BigNegativeError S2
 * '<S54>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4
 * '<S55>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S56>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack
 * '<S57>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S58>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S59>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S60>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S61>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S62>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/BigError S1
 * '<S63>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/BigNegativeError S2
 * '<S64>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Depth S3
 * '<S65>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Heading S4
 * '<S66>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S67>'  : brain/Chart/Running.Autonomous.ValidationGate.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S68>'  : brain/Chart/Running.ControlledRC.MaintainDepth/PID Controller Depth S3
 * '<S69>'  : brain/Chart/Running.ControlledRC.MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S70>'  : brain/Chart/Running.ControlledRC.MaintainHeading/BigError S1
 * '<S71>'  : brain/Chart/Running.ControlledRC.MaintainHeading/BigNegativeError S2
 * '<S72>'  : brain/Chart/Running.ControlledRC.MaintainHeading/PID Controller Heading S4
 * '<S73>'  : brain/Chart/Running.ControlledRC.MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 */

/*
 * Requirements for '<Root>' : brain
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
