/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.349
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Tue Apr 13 17:34:15 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Tue Apr 13 17:34:16 2010
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
  real_T HSVImage1[57600];             /* '<S12>/PutHSVImageTogether' */
} rtB_RunningAutonomousFollowOneP;

/* Block signals for system '<S10>/Embedded MATLAB Function1' */
typedef struct {
  real_T XCenter;                      /* '<S10>/Embedded MATLAB Function1' */
  real_T YCenter;                      /* '<S10>/Embedded MATLAB Function1' */
} rtB_EmbeddedMATLABFunction1_bra;

/* Block signals for system '<S1>/MaintainHeading' */
typedef struct {
  real_T Add;                          /* '<S24>/Add' */
  real_T Constant1;                    /* '<S24>/Constant1' */
  real_T Add_d;                        /* '<S23>/Add' */
  real_T Constant1_k;                  /* '<S23>/Constant1' */
  int8_T DoubleToint1;                 /* '<S9>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S9>/DoubleToint8' */
} rtB_MaintainHeading_brain;

/* Block states (auto storage) for system '<S1>/MaintainHeading' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S26>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S25>/Heading Discrete-Time Integrator' */
  uint32_T MaintainHeading_ELAPS_T;    /* '<Root>/Chart' */
  uint32_T MaintainHeading_PREV_T;     /* '<Root>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S9>/If' */
} rtDW_MaintainHeading_brain;

/* Block signals for system '<S55>/Get Brightest Pixel Per Column and Row' */
typedef struct {
  real_T BWleft[9600];                 /* '<S55>/Get Brightest Pixel Per Column and Row' */
  real_T BWright[9600];                /* '<S55>/Get Brightest Pixel Per Column and Row' */
} rtB_GetBrightestPixelPerColumna;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit' */
typedef struct {
  boolean_T BWleft[9600];              /* '<S55>/Data Type Conversion' */
  boolean_T BWright[9600];             /* '<S55>/Data Type Conversion1' */
  rtB_GetBrightestPixelPerColumna sf_GetBrightestPixelPerColumnan;/* '<S55>/Get Brightest Pixel Per Column and Row' */
} rtB_RunningAutonomousFollowOn_b;

/* Block signals for system '<S58>/IsLinePresent' */
typedef struct {
  real_T Theta[2];                     /* '<S58>/IsLinePresent' */
  real_T Rho[2];                       /* '<S58>/IsLinePresent' */
  real_T maxVotes[2];                  /* '<S58>/IsLinePresent' */
} rtB_IsLinePresent_brain;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings' */
typedef struct {
  real_T HoughTransform_o1[51660];     /* '<S58>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S58>/Hough Transform' */
  real_T HoughTransform_o3[287];       /* '<S58>/Hough Transform' */
  real_T HoughTransform_o1_d[51660];   /* '<S59>/Hough Transform' */
  real_T HoughTransform_o2_m[180];     /* '<S59>/Hough Transform' */
  real_T HoughTransform_o3_k[287];     /* '<S59>/Hough Transform' */
  real_T ToPathHeading[2];             /* '<S15>/GetHeadingToPath' */
  real_T AlongPathHeading[2];          /* '<S15>/GetHeadingToPath' */
  rtB_IsLinePresent_brain sf_IsLinePresent_j;/* '<S59>/IsLinePresent' */
  rtB_IsLinePresent_brain sf_IsLinePresent;/* '<S58>/IsLinePresent' */
} rtB_RunningAutonomousFollowOn_o;

/* Block signals for system '<S1>/MaintainDepth' */
typedef struct {
  int8_T DoubleToInt8;                 /* '<S8>/Double To Int8' */
} rtB_MaintainDepth_brain;

/* Block states (auto storage) for system '<S1>/MaintainDepth' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S22>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S21>/Depth Discrete-Time Integrator' */
  uint32_T MaintainDepth_ELAPS_T;      /* '<Root>/Chart' */
  uint32_T MaintainDepth_PREV_T;       /* '<Root>/Chart' */
} rtDW_MaintainDepth_brain;

/* Block signals for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver' */
typedef struct {
  real_T Subtract;                     /* '<S13>/Subtract' */
  real_T Subtract1;                    /* '<S13>/Subtract1' */
  int8_T DataTypeConversion;           /* '<S49>/Data Type Conversion' */
  int8_T DataTypeConversion_b;         /* '<S50>/Data Type Conversion' */
  boolean_T BW[19200];                 /* '<S13>/Logical Operator1' */
  boolean_T LogicalOperator[19200];    /* '<S13>/Logical Operator' */
  boolean_T Compare[19200];            /* '<S46>/Compare' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S13>/Embedded MATLAB Function1' */
} rtB_RunningAutonomousFollowO_bx;

/* Block states (auto storage) for system '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S52>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S51>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_b;                  /* '<S54>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S53>/Y-Buoy Discrete-Time Integrator' */
  uint32_T RunningAutonomousFollowOnePat_a;/* '<Root>/Chart' */
  uint32_T RunningAutonomousFollowOnePat_e;/* '<Root>/Chart' */
  uint32_T BuoyBlobAnalysis_STACK_DW[19200];/* '<S13>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_N_PIXLIST_DW[19200];/* '<S13>/Buoy Blob Analysis' */
  int16_T BuoyBlobAnalysis_M_PIXLIST_DW[19200];/* '<S13>/Buoy Blob Analysis' */
  uint8_T BuoyBlobAnalysis_PAD_DW[19764];/* '<S13>/Buoy Blob Analysis' */
} rtDW_RunningAutonomousFollowO_p;

/* Block signals for system '<S1>/GetForwardVelocity' */
typedef struct {
  real_T MultiportSwitch;              /* '<S7>/Multiport Switch' */
} rtB_GetForwardVelocity_brain;

/* Block signals (auto storage) */
typedef struct {
  real_T DesiredDepth;                 /* '<Root>/Chart' */
  real_T DesiredHeading;               /* '<Root>/Chart' */
  real_T BuoyCentroidX;                /* '<Root>/Chart' */
  real_T BuoyCentroidY;                /* '<Root>/Chart' */
  real_T BWout[19200];                 /* '<Root>/Chart' */
  real_T SFunction_o13[19200];         /* '<Root>/Chart' */
  real_T SFunction_o14[19200];         /* '<Root>/Chart' */
  real_T SFunction_o15[19200];         /* '<Root>/Chart' */
  real_T SFunction_o16[19200];         /* '<Root>/Chart' */
  real_T SFunction_o17[19200];         /* '<Root>/Chart' */
  real_T SFunction_o18[19200];         /* '<Root>/Chart' */
  real_T SFunction_o19[19200];         /* '<Root>/Chart' */
  real_T SFunction_o20;                /* '<Root>/Chart' */
  real_T SFunction_o21;                /* '<Root>/Chart' */
  real_T SFunction_o22;                /* '<Root>/Chart' */
  real_T SFunction_o23[19200];         /* '<Root>/Chart' */
  real_T SFunction_o24[19200];         /* '<Root>/Chart' */
  real_T SFunction_o25[57600];         /* '<Root>/Chart' */
  real_T SFunction_o28;                /* '<Root>/Chart' */
  real_T SFunction_o29[19200];         /* '<Root>/Chart' */
  real_T SFunction_o30[19200];         /* '<Root>/Chart' */
  real_T SFunction_o31[19200];         /* '<Root>/Chart' */
  real_T SFunction_o34[19200];         /* '<Root>/Chart' */
  real_T SFunction_o35[19200];         /* '<Root>/Chart' */
  real_T SFunction_o36;                /* '<Root>/Chart' */
  real_T SFunction_o37[19200];         /* '<Root>/Chart' */
  real_T SFunction_o38[19200];         /* '<Root>/Chart' */
  real_T SFunction_o39[57600];         /* '<Root>/Chart' */
  real_T SFunction_o42;                /* '<Root>/Chart' */
  real_T Image;                        /* '<S38>/IF Buoy Conditions' */
  real_T Add;                          /* '<S32>/Add' */
  real_T Add1;                         /* '<S32>/Add1' */
  real_T BlobArea;                     /* '<S10>/Embedded MATLAB Function' */
  real_T BlobCentroidX;                /* '<S10>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S10>/Embedded MATLAB Function' */
  real_T DataStoreRead;                /* '<S20>/Data Store Read' */
  real32_T Resize[19200];              /* '<S6>/Resize' */
  real32_T Resize1[19200];             /* '<S6>/Resize1' */
  real32_T Resize2[19200];             /* '<S6>/Resize2' */
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
  int8_T DataTypeConversion;           /* '<S33>/Data Type Conversion' */
  uint8_T RGBVid_R[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_G[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T RGBVid_B[307200];            /* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T ChromaResampling_o1[307200]; /* '<S6>/Chroma Resampling' */
  uint8_T ChromaResampling_o2[307200]; /* '<S6>/Chroma Resampling' */
  boolean_T SFunction_o26[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o27[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o40[9600];       /* '<Root>/Chart' */
  boolean_T SFunction_o41[9600];       /* '<Root>/Chart' */
  boolean_T BW[19200];                 /* '<S38>/Logical Operator1' */
  boolean_T Erosion[19200];            /* '<S10>/Erosion' */
  boolean_T BW_a[19200];               /* '<S81>/Logical Operator1' */
  boolean_T LogicalOperator[19200];    /* '<S81>/Logical Operator' */
  boolean_T Compare[19200];            /* '<S86>/Compare' */
  boolean_T Erosion_d[19200];          /* '<S38>/Erosion' */
  boolean_T Dilation[19200];           /* '<S38>/Dilation' */
  boolean_T BW_j[19200];               /* '<S10>/Logical Operator1' */
  boolean_T Dilation_p[19200];         /* '<S10>/Dilation' */
  rtB_RunningAutonomousFollowOn_o RunningAutonomousFollowOnePat_d;/* '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings' */
  rtB_RunningAutonomousFollowOn_b RunningAutonomousFollowOnePa_m3;/* '<S1>/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit' */
  rtB_RunningAutonomousFollowO_bx RunningAutonomousFollowOnePat_g;/* '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver' */
  rtB_GetForwardVelocity_brain GetForwardVelocity;/* '<S1>/GetForwardVelocity' */
  rtB_RunningAutonomousFollowO_bx RunningAutonomousFollowOneP_oc4;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver' */
  rtB_MaintainDepth_brain MaintainDepth;/* '<S1>/MaintainDepth' */
  rtB_RunningAutonomousFollowOneP RunningAutonomousFollowOnePath1;/* '<S1>/Running.Autonomous.FollowOnePath1.MakeHSVImage' */
  rtB_RunningAutonomousFollowOn_o RunningAutonomousFollowOnePa_ot;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings' */
  rtB_RunningAutonomousFollowOn_b RunningAutonomousFollowOnePat_m;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit' */
  rtB_MaintainHeading_brain MaintainHeading;/* '<S1>/MaintainHeading' */
  rtB_EmbeddedMATLABFunction1_bra sf_EmbeddedMATLABFunction1;/* '<S10>/Embedded MATLAB Function1' */
  rtB_RunningAutonomousFollowOneP RunningAutonomousFollowOnePat_i;/* '<S1>/Running.Autonomous.FollowOnePath.MakeHSVImage' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S35>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S34>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S37>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S36>/Y-Buoy Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/Chart' */
  real_T BuoyDone;                     /* '<Root>/Chart' */
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
  real_T Error;                        /* '<Root>/Chart' */
  real_T Image;                        /* '<S20>/Data Store Memory' */
  real32_T RGBtoHSVColorSpaceConversion_DW[307200];/* '<S6>/RGB to HSV Color Space  Conversion' */
  real32_T Resize_IntBuffer[76800];    /* '<S6>/Resize' */
  int32_T Dilation_NUMNONZ_DW;         /* '<S38>/Dilation' */
  int32_T Dilation_STREL_DW;           /* '<S38>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW[4];   /* '<S38>/Dilation' */
  int32_T Erosion_NUMNONZ_DW[2];       /* '<S38>/Erosion' */
  int32_T Erosion_STREL_DW[2];         /* '<S38>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[8];     /* '<S38>/Erosion' */
  int32_T Dilation_NUMNONZ_DW_c;       /* '<S10>/Dilation' */
  int32_T Dilation_STREL_DW_k;         /* '<S10>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW_h[4]; /* '<S10>/Dilation' */
  int32_T Erosion_NUMNONZ_DW_f[2];     /* '<S10>/Erosion' */
  int32_T Erosion_STREL_DW_a[2];       /* '<S10>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW_g[8];   /* '<S10>/Erosion' */
  uint32_T presentTicks;               /* '<Root>/Chart' */
  uint32_T elapsedTicks;               /* '<Root>/Chart' */
  uint32_T previousTicks;              /* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyApproachBu;/* '<Root>/Chart' */
  uint32_T RunningAutonomousBuoyApproach_d;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[19200];/* '<S38>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[19200];/* '<S38>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[19200];/* '<S38>/Blob Analysis' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S6>/Chroma Resampling' */
  uint8_T YCbCrtoRGBColorSpaceConversion_[307200];/* '<S6>/Y-Cb-Cr to RGB Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_Autonomous;               /* '<Root>/Chart' */
  uint8_T is_FollowOnePath;            /* '<Root>/Chart' */
  uint8_T is_OnePath;                  /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T is_Buoy;                     /* '<Root>/Chart' */
  uint8_T is_GoAroundBuoy;             /* '<Root>/Chart' */
  uint8_T is_FollowOnePath1;           /* '<Root>/Chart' */
  uint8_T is_OnePath_b;                /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[19764];  /* '<S38>/Blob Analysis' */
  boolean_T OldObstacle;               /* '<Root>/Chart' */
  boolean_T Erosion_ONE_PAD_IMG_DW[21209];/* '<S38>/Erosion' */
  boolean_T Erosion_TWO_PAD_IMG_DW[21209];/* '<S38>/Erosion' */
  rtDW_RunningAutonomousFollowO_p RunningAutonomousFollowOnePat_g;/* '<S1>/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver' */
  rtDW_RunningAutonomousFollowO_p RunningAutonomousFollowOneP_oc4;/* '<S1>/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver' */
  rtDW_MaintainDepth_brain MaintainDepth;/* '<S1>/MaintainDepth' */
  rtDW_MaintainHeading_brain MaintainHeading;/* '<S1>/MaintainHeading' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S58>/Hough Transform'
   * '<S59>/Hough Transform'
   * '<S77>/Hough Transform'
   * '<S78>/Hough Transform'
   */
  real_T pooled9[91];

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S58>/Hough Transform'
   * '<S59>/Hough Transform'
   * '<S77>/Hough Transform'
   * '<S78>/Hough Transform'
   */
  real_T pooled10;

  /* Computed Parameter: Yweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  real32_T pooled11[960];

  /* Computed Parameter: Xweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  real32_T pooled12[1280];

  /* Computed Parameter: Yindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  int32_T pooled14[960];

  /* Computed Parameter: Xindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  int32_T pooled15[1280];

  /* Computed Parameter: WALKER_RTP
   * Referenced by blocks:
   * '<S10>/Buoy Blob Analysis'
   * '<S13>/Buoy Blob Analysis'
   * '<S17>/Buoy Blob Analysis'
   * '<S38>/Blob Analysis'
   * '<S81>/Blob Analysis'
   */
  int32_T pooled18[8];

  /* Expression: nhood
   * Referenced by blocks:
   * '<S10>/Dilation'
   * '<S38>/Dilation'
   */
  boolean_T pooled20[4];

  /* Expression: nhood
   * Referenced by blocks:
   * '<S10>/Erosion'
   * '<S38>/Erosion'
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
  int8_T Thrusters[4];                 /* '<Root>/Thrusters' */
  int8_T State;                        /* '<Root>/State' */
  real_T DesiredDepth;                 /* '<Root>/DesiredDepth' */
  real_T DesiredHeading;               /* '<Root>/DesiredHeading' */
  real_T BWout[19200];                 /* '<Root>/BWout' */
} ExternalOutputs_brain;

/* Parameters for system: '<S1>/MaintainHeading' */
struct rtP_MaintainHeading_brain_ {
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * '<S25>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * '<S25>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * '<S25>/Heading Proportional Gain'
                                        */
};

/* Parameters for system: '<S1>/MaintainDepth' */
struct rtP_MaintainDepth_brain_ {
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * '<S21>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * '<S21>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * '<S21>/Depth Proportional Gain'
                                        */
};

/* Parameters for system: '<S1>/GetForwardVelocity' */
struct rtP_GetForwardVelocity_brain_ {
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * '<S7>/Heading Forward Velocity'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_brain_ {
  real_T Buoy_HueHigher;               /* Variable: Buoy_HueHigher
                                        * Referenced by blocks:
                                        * '<S27>/Constant'
                                        * '<S39>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S28>/Constant'
                                        * '<S40>/Constant'
                                        */
  real_T Buoy_Max_Eccentricity;        /* Variable: Buoy_Max_Eccentricity
                                        * '<S38>/Constant1'
                                        */
  real_T Buoy_Max_Extent;              /* Variable: Buoy_Max_Extent
                                        * '<S38>/Constant3'
                                        */
  real_T Buoy_Min_Eccentricity;        /* Variable: Buoy_Min_Eccentricity
                                        * '<S38>/Constant'
                                        */
  real_T Buoy_Min_Extent;              /* Variable: Buoy_Min_Extent
                                        * '<S38>/Constant2'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S29>/Constant'
                                        * '<S42>/Constant'
                                        */
  real_T Cam_Down_XPos_Kd;             /* Variable: Cam_Down_XPos_Kd
                                        * Referenced by blocks:
                                        * '<S51>/X-Buoy Derivative Gain'
                                        * '<S70>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_XPos_Ki;             /* Variable: Cam_Down_XPos_Ki
                                        * Referenced by blocks:
                                        * '<S51>/X-Buoy Integral Gain'
                                        * '<S70>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Down_XPos_Kp;             /* Variable: Cam_Down_XPos_Kp
                                        * Referenced by blocks:
                                        * '<S51>/X-Buoy Proportional Gain'
                                        * '<S70>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Down_YPos_Kd;             /* Variable: Cam_Down_YPos_Kd
                                        * Referenced by blocks:
                                        * '<S53>/Y-Buoy Derivative Gain'
                                        * '<S72>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_YPos_Ki;             /* Variable: Cam_Down_YPos_Ki
                                        * Referenced by blocks:
                                        * '<S53>/Y-Buoy Integral Gain'
                                        * '<S72>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Down_YPos_Kp;             /* Variable: Cam_Down_YPos_Kp
                                        * Referenced by blocks:
                                        * '<S53>/Y-Buoy Proportional Gain'
                                        * '<S72>/Y-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S34>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S34>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S34>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S36>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S36>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S36>/Y-Buoy Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * Referenced by blocks:
                                        * '<S44>/Constant'
                                        * '<S63>/Constant'
                                        * '<S83>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * Referenced by blocks:
                                        * '<S45>/Constant'
                                        * '<S64>/Constant'
                                        * '<S84>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * Referenced by blocks:
                                        * '<S46>/Constant'
                                        * '<S65>/Constant'
                                        * '<S86>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S32>/Vision_Forward_Velocity'
                                        * '<S32>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S10>/Buoy Blob Analysis'
                                        * '<S13>/Buoy Blob Analysis'
                                        * '<S17>/Buoy Blob Analysis'
                                        * '<S38>/Blob Analysis'
                                        * '<S81>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S10>/Buoy Blob Analysis'
                                        * '<S13>/Buoy Blob Analysis'
                                        * '<S17>/Buoy Blob Analysis'
                                        * '<S38>/Blob Analysis'
                                        * '<S81>/Blob Analysis'
                                        */
  rtP_GetForwardVelocity_brain GetForwardVelocity;/* '<S1>/GetForwardVelocity' */
  rtP_MaintainDepth_brain MaintainDepth;/* '<S1>/MaintainDepth' */
  rtP_MaintainHeading_brain MaintainHeading;/* '<S1>/MaintainHeading' */
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
 * '<S7>'   : brain/Chart/GetForwardVelocity
 * '<S8>'   : brain/Chart/MaintainDepth
 * '<S9>'   : brain/Chart/MaintainHeading
 * '<S10>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy
 * '<S11>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy
 * '<S12>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage
 * '<S13>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver
 * '<S14>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S15>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings
 * '<S16>'  : brain/Chart/Running.Autonomous.FollowOnePath1.MakeHSVImage
 * '<S17>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver
 * '<S18>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit
 * '<S19>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings
 * '<S20>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack
 * '<S21>'  : brain/Chart/MaintainDepth/PID Controller Depth S3
 * '<S22>'  : brain/Chart/MaintainDepth/PID Controller Depth S3/Depth Discrete Derivative
 * '<S23>'  : brain/Chart/MaintainHeading/BigError S1
 * '<S24>'  : brain/Chart/MaintainHeading/BigNegativeError S2
 * '<S25>'  : brain/Chart/MaintainHeading/PID Controller Heading S4
 * '<S26>'  : brain/Chart/MaintainHeading/PID Controller Heading S4/Heading Discrete Derivative
 * '<S27>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Buoy HueHigher
 * '<S28>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Buoy HueLower
 * '<S29>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Buoy Saturation
 * '<S30>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function
 * '<S31>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Embedded MATLAB Function1
 * '<S32>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/X-HeadingControl
 * '<S33>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Y-DepthControl
 * '<S34>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S35>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S36>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S37>'  : brain/Chart/Running.Autonomous.Buoy.ApproachBuoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S38>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis
 * '<S39>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S40>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S41>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis/IF Buoy Conditions
 * '<S42>'  : brain/Chart/Running.Autonomous.Buoy.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S43>'  : brain/Chart/Running.Autonomous.FollowOnePath.MakeHSVImage/PutHSVImageTogether
 * '<S44>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy HueHigher
 * '<S45>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy HueLower
 * '<S46>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Buoy Saturation
 * '<S47>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function
 * '<S48>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Embedded MATLAB Function1
 * '<S49>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control
 * '<S50>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control
 * '<S51>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position
 * '<S52>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S53>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis
 * '<S54>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis/Y-Buoy Discrete Derivative
 * '<S55>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S56>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S57>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S58>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S59>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S60>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S61>'  : brain/Chart/Running.Autonomous.FollowOnePath.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S62>'  : brain/Chart/Running.Autonomous.FollowOnePath1.MakeHSVImage/PutHSVImageTogether
 * '<S63>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Buoy HueHigher
 * '<S64>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Buoy HueLower
 * '<S65>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Buoy Saturation
 * '<S66>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Embedded MATLAB Function
 * '<S67>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Embedded MATLAB Function1
 * '<S68>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/X-Axis Control
 * '<S69>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Y-Axis Control
 * '<S70>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position
 * '<S71>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/X-Axis Control/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S72>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis
 * '<S73>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.CenterOver.CenterOver/Y-Axis Control/PID Controller Y Axis/Y-Buoy Discrete Derivative
 * '<S74>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel
 * '<S75>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetBrightestPixel_VerticalSplit/Finding Brightest Pixel/Get Brightest Pixel Per Column and Row
 * '<S76>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings/GetHeadingToPath
 * '<S77>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left
 * '<S78>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right
 * '<S79>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Left/IsLinePresent
 * '<S80>'  : brain/Chart/Running.Autonomous.FollowOnePath1.OnePath.GetDirections.GetHeadings/Hough Transform Stuff Right/IsLinePresent
 * '<S81>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack
 * '<S82>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S83>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S84>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S85>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S86>'  : brain/Chart/Running.Autonomous.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 */

/*
 * Requirements for '<Root>' : brain
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
