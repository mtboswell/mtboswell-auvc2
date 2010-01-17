/*
 * File: brain.h
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.157
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Mon Dec 14 18:36:17 2009
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Mon Dec 14 18:36:18 2009
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

/* Block signals for system '<S10>/BigError S1' */
typedef struct {
  real_T Add;                          /* '<S68>/Add' */
  real_T Constant1;                    /* '<S68>/Constant1' */
} rtB_BigErrorS1_brain;

/* Block signals for system '<S10>/BigNegativeError S2' */
typedef struct {
  real_T Add;                          /* '<S69>/Add' */
  real_T Constant1;                    /* '<S69>/Constant1' */
} rtB_BigNegativeErrorS2_brain;

/* Block signals (auto storage) */
typedef struct {
  real_T DesiredDepth;                 /* '<Root>/Chart' */
  real_T DesiredHeading;               /* '<Root>/Chart' */
  real_T BuoyCentroidX;                /* '<Root>/Chart' */
  real_T BuoyCentroidY;                /* '<Root>/Chart' */
  real_T SFunction_o11[307200];        /* '<Root>/Chart' */
  real_T SFunction_o12[307200];        /* '<Root>/Chart' */
  real_T SFunction_o15;                /* '<Root>/Chart' */
  real_T SFunction_o16;                /* '<Root>/Chart' */
  real_T SFunction_o17[307200];        /* '<Root>/Chart' */
  real_T SFunction_o18[307200];        /* '<Root>/Chart' */
  real_T SFunction_o19;                /* '<Root>/Chart' */
  real_T SFunction_o22[307200];        /* '<Root>/Chart' */
  real_T SFunction_o23[307200];        /* '<Root>/Chart' */
  real_T SFunction_o24;                /* '<Root>/Chart' */
  real_T SFunction_o27[307200];        /* '<Root>/Chart' */
  real_T SFunction_o28[307200];        /* '<Root>/Chart' */
  real_T SFunction_o31;                /* '<Root>/Chart' */
  real_T SFunction_o32;                /* '<Root>/Chart' */
  real_T SFunction_o33[307200];        /* '<Root>/Chart' */
  real_T SFunction_o34[307200];        /* '<Root>/Chart' */
  real_T SFunction_o37;                /* '<Root>/Chart' */
  real_T SFunction_o38;                /* '<Root>/Chart' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T DataStoreRead;                /* '<S4>/Data Store Read' */
  real_T Add1_i;                       /* '<S7>/Add1' */
  real_T Add;                          /* '<S45>/Add' */
  real_T Add_d;                        /* '<S6>/Add' */
  real_T Add_l;                        /* '<S36>/Add' */
  real_T Add_g;                        /* '<S17>/Add' */
  real_T Add1_h;                       /* '<S17>/Add1' */
  real_T BlobCentroidX;                /* '<S3>/Embedded MATLAB Function' */
  real_T BlobCentroidY;                /* '<S3>/Embedded MATLAB Function' */
  real_T DataStoreRead_l;              /* '<S9>/Data Store Read' */
  real_T MedianFilterGreen[10800];     /* '<S15>/Median Filter Green' */
  real32_T ColorSpaceConversion1_o1[307200];/* '<S2>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o2[307200];/* '<S2>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o3[307200];/* '<S2>/Color Space  Conversion1' */
  real32_T SFunction_o13;              /* '<Root>/Chart' */
  real32_T SFunction_o14;              /* '<Root>/Chart' */
  real32_T SFunction_o20;              /* '<Root>/Chart' */
  real32_T SFunction_o21;              /* '<Root>/Chart' */
  real32_T SFunction_o25;              /* '<Root>/Chart' */
  real32_T SFunction_o26;              /* '<Root>/Chart' */
  real32_T SFunction_o29;              /* '<Root>/Chart' */
  real32_T SFunction_o30;              /* '<Root>/Chart' */
  real32_T SFunction_o35;              /* '<Root>/Chart' */
  real32_T SFunction_o36;              /* '<Root>/Chart' */
  real32_T RedDataTypeConversion[307200];/* '<S2>/Red Data Type Conversion' */
  real32_T GreenDataTypeConversion1[307200];/* '<S2>/Green Data Type Conversion1' */
  real32_T BlueDataTypeConversion2[307200];/* '<S2>/Blue Data Type Conversion2' */
  int32_T BlobArea;                    /* '<S3>/Embedded MATLAB Function' */
  int8_T Right;                        /* '<Root>/Chart' */
  int8_T Left;                         /* '<Root>/Chart' */
  int8_T Vertical;                     /* '<Root>/Chart' */
  int8_T CameraPosition;               /* '<Root>/Chart' */
  int8_T DoubleToInt8;                 /* '<S8>/Double To Int8' */
  int8_T DoubleToint1;                 /* '<S8>/DoubleToint1' */
  int8_T DoubleToint8;                 /* '<S8>/DoubleToint8' */
  int8_T DoubleToInt8_g;               /* '<S5>/Double To Int8' */
  int8_T DoubleToint1_j;               /* '<S5>/DoubleToint1' */
  int8_T DoubleToint8_p;               /* '<S5>/DoubleToint8' */
  int8_T AddLeft;                      /* '<S7>/AddLeft' */
  int8_T AddRight;                     /* '<S7>/AddRight' */
  int8_T DoubleToInt8_m;               /* '<S44>/Double To Int8' */
  int8_T DoubleToint1_k;               /* '<S35>/DoubleToint1' */
  int8_T Multiply1;                    /* '<S35>/Multiply1' */
  int8_T DoubleToInt8_p;               /* '<S35>/Double To Int8' */
  int8_T DataTypeConversion;           /* '<S18>/Data Type Conversion' */
  int8_T DoubleToInt8_c;               /* '<S10>/Double To Int8' */
  int8_T DoubleToint1_c;               /* '<S10>/DoubleToint1' */
  int8_T DoubleToint8_b;               /* '<S10>/DoubleToint8' */
  uint8_T State;                       /* '<Root>/Chart' */
  uint8_T ColorSpaceConversion_o3[307200];/* '<S2>/Color Space  Conversion' */
  uint8_T ColorSpaceConversion_o1[307200];/* '<S2>/Color Space  Conversion' */
  uint8_T ColorSpaceConversion_o2[307200];/* '<S2>/Color Space  Conversion' */
  boolean_T Compare[307200];           /* '<S28>/Compare' */
  boolean_T Compare_o[307200];         /* '<S49>/Compare' */
  boolean_T Compare_a[307200];         /* '<S39>/Compare' */
  boolean_T Compare_e[10800];          /* '<S13>/Compare' */
  boolean_T Compare_c[307200];         /* '<S67>/Compare' */
  boolean_T LogicalOperator1[307200];  /* '<S23>/Logical Operator1' */
  boolean_T LogicalOperator1_a[307200];/* '<S7>/Logical Operator1' */
  boolean_T LogicalOperator1_f[307200];/* '<S6>/Logical Operator1' */
  boolean_T LogicalOperator1_l[10800]; /* '<S3>/Logical Operator1' */
  boolean_T LogicalOperator1_e[307200];/* '<S62>/Logical Operator1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_c;/* '<S8>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_l;   /* '<S8>/BigError S1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2_h;/* '<S5>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1_f;   /* '<S5>/BigError S1' */
  rtB_BigNegativeErrorS2_brain BigNegativeErrorS2;/* '<S10>/BigNegativeError S2' */
  rtB_BigErrorS1_brain BigErrorS1;     /* '<S10>/BigError S1' */
} BlockIO_brain;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S60>/UD' */
  real_T DepthDiscreteTimeIntegrator_DST;/* '<S58>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_k;                  /* '<S61>/UD' */
  real_T HeadingDiscreteTimeIntegrator_D;/* '<S59>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_e;                  /* '<S33>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_k;/* '<S31>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S34>/UD' */
  real_T HeadingDiscreteTimeIntegrator_d;/* '<S32>/Heading Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S53>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_p;/* '<S51>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_d;                  /* '<S55>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_DST;/* '<S54>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_db;                 /* '<S52>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_d;/* '<S50>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_ea;                 /* '<S43>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_l;/* '<S41>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_ej;                 /* '<S42>/UD' */
  real_T DepthDiscreteTimeIntegrator__d2;/* '<S40>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S20>/UD' */
  real_T XBuoyDiscreteTimeIntegrator_DST;/* '<S19>/X-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_de;                 /* '<S22>/UD' */
  real_T YBuoyDiscreteTimeIntegrator_D_n;/* '<S21>/Y-Buoy Discrete-Time Integrator' */
  real_T UD_DSTATE_nh;                 /* '<S72>/UD' */
  real_T DepthDiscreteTimeIntegrator_D_e;/* '<S70>/Depth Discrete-Time Integrator' */
  real_T UD_DSTATE_b;                  /* '<S73>/UD' */
  real_T HeadingDiscreteTimeIntegrato_dv;/* '<S71>/Heading Discrete-Time Integrator' */
  real_T count;                        /* '<Root>/Chart' */
  real_T OldObstacle;                  /* '<Root>/Chart' */
  real_T countarea;                    /* '<Root>/Chart' */
  real_T DesiredHeadingCount;          /* '<Root>/Chart' */
  real_T OldHeading;                   /* '<Root>/Chart' */
  real_T TrackCount;                   /* '<Root>/Chart' */
  real_T BuoyCount;                    /* '<Root>/Chart' */
  real_T ErrorCountHeading;            /* '<Root>/Chart' */
  real_T ErrorCountX;                  /* '<Root>/Chart' */
  real_T ErrorCountY;                  /* '<Root>/Chart' */
  real_T Image;                        /* '<S4>/Found' */
  real_T ResizeH_IntBuffer[57600];     /* '<S16>/ResizeH' */
  real_T Image_c;                      /* '<S9>/Data Store Memory' */
  real32_T ColorSpaceConversion1_DWORK1[307200];/* '<S2>/Color Space  Conversion1' */
  uint32_T RunningBuoyBuoy_ELAPS_T;    /* '<Root>/Chart' */
  uint32_T RunningBuoyBuoy_PREV_T;     /* '<Root>/Chart' */
  uint32_T RunningFindBuoyStraightLevelCon;/* '<Root>/Chart' */
  uint32_T RunningFindBuoyStraightLevelC_j;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage1AimTrac;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage1AimTr_d;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage2Positio;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage2Posit_a;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage3ReOrien;/* '<Root>/Chart' */
  uint32_T RunningFollowTrackStage3ReOri_a;/* '<Root>/Chart' */
  uint32_T RunningValidationGateStraightLe;/* '<Root>/Chart' */
  uint32_T RunningValidationGateStraight_g;/* '<Root>/Chart' */
  uint32_T BlobAnalysis_STACK_DW[307200];/* '<S23>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[307200];/* '<S23>/Blob Analysis' */
  int16_T BlobAnalysis_M_PIXLIST_DW[307200];/* '<S23>/Blob Analysis' */
  int8_T If_ActiveSubsystem;           /* '<S8>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S5>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S10>/If' */
  uint8_T ChromaResampling_FIRST_PASS_DW[153600];/* '<S2>/Chroma Resampling' */
  uint8_T ColorSpaceConversion_DWORK1[307200];/* '<S2>/Color Space  Conversion' */
  uint8_T is_active_c1_brain;          /* '<Root>/Chart' */
  uint8_T is_c1_brain;                 /* '<Root>/Chart' */
  uint8_T is_FollowTrack;              /* '<Root>/Chart' */
  uint8_T is_Running;                  /* '<Root>/Chart' */
  uint8_T BlobAnalysis_PAD_DW[309444]; /* '<S23>/Blob Analysis' */
  boolean_T RunningFindBuoyStraightLevelC_n;/* '<Root>/Chart' */
  boolean_T RunningFollowTrackStage3ReOri_b;/* '<Root>/Chart' */
  boolean_T RunningValidationGateStraight_n;/* '<Root>/Chart' */
} D_Work_brain;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Yweights
   * Referenced by blocks:
   * '<S16>/ResizeH'
   * '<S16>/ResizeS'
   */
  real_T pooled1[990];

  /* Computed Parameter: Xweights
   * Referenced by blocks:
   * '<S16>/ResizeH'
   * '<S16>/ResizeS'
   */
  real_T pooled2[1320];

  /* Computed Parameter: Yindex
   * Referenced by blocks:
   * '<S16>/ResizeH'
   * '<S16>/ResizeS'
   */
  int32_T pooled19[990];

  /* Computed Parameter: Xindex
   * Referenced by blocks:
   * '<S16>/ResizeH'
   * '<S16>/ResizeS'
   */
  int32_T pooled20[1320];

  /* Computed Parameter: WALKER_RTP
   * '<S3>/Buoy Blob Analysis'
   */
  int32_T BuoyBlobAnalysis_WALK[8];

  /* Computed Parameter: WALKER_RTP
   * Referenced by blocks:
   * '<S23>/Blob Analysis'
   * '<S36>/Blob Analysis'
   * '<S45>/Blob Analysis'
   * '<S62>/Blob Analysis'
   */
  int32_T pooled21[8];
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
                                        * '<S11>/Constant'
                                        * '<S24>/Constant'
                                        */
  real_T Buoy_HueLower;                /* Variable: Buoy_HueLower
                                        * Referenced by blocks:
                                        * '<S12>/Constant'
                                        * '<S25>/Constant'
                                        */
  real_T Buoy_Saturation;              /* Variable: Buoy_Saturation
                                        * Referenced by blocks:
                                        * '<S13>/Constant'
                                        * '<S28>/Constant'
                                        */
  real_T Cam_Down_XPos_Kd;             /* Variable: Cam_Down_XPos_Kd
                                        * Referenced by blocks:
                                        * '<S41>/XPosition Derivative Gain'
                                        * '<S51>/XPosition Derivative Gain'
                                        */
  real_T Cam_Down_XPos_Ki;             /* Variable: Cam_Down_XPos_Ki
                                        * Referenced by blocks:
                                        * '<S41>/XPosition Integral Gain'
                                        * '<S51>/XPosition Integral Gain'
                                        */
  real_T Cam_Down_XPos_Kp;             /* Variable: Cam_Down_XPos_Kp
                                        * Referenced by blocks:
                                        * '<S41>/XPosition Proportional Gain'
                                        * '<S51>/XPosition Proportional Gain'
                                        */
  real_T Cam_Down_YPos_Kd;             /* Variable: Cam_Down_YPos_Kd
                                        * '<S54>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Down_YPos_Ki;             /* Variable: Cam_Down_YPos_Ki
                                        * '<S54>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Down_YPos_Kp;             /* Variable: Cam_Down_YPos_Kp
                                        * '<S54>/Y-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_XPosition_Kd;     /* Variable: Cam_Forward_XPosition_Kd
                                        * '<S19>/X-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_XPosition_Ki;     /* Variable: Cam_Forward_XPosition_Ki
                                        * '<S19>/X-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_XPosition_Kp;     /* Variable: Cam_Forward_XPosition_Kp
                                        * '<S19>/X-Buoy Proportional Gain'
                                        */
  real_T Cam_Forward_YPosition_Kd;     /* Variable: Cam_Forward_YPosition_Kd
                                        * '<S21>/Y-Buoy Derivative Gain'
                                        */
  real_T Cam_Forward_YPosition_Ki;     /* Variable: Cam_Forward_YPosition_Ki
                                        * '<S21>/Y-Buoy Integral Gain'
                                        */
  real_T Cam_Forward_YPosition_Kp;     /* Variable: Cam_Forward_YPosition_Kp
                                        * '<S21>/Y-Buoy Proportional Gain'
                                        */
  real_T Depth_Kd;                     /* Variable: Depth_Kd
                                        * Referenced by blocks:
                                        * '<S31>/Depth Derivative Gain'
                                        * '<S58>/Depth Derivative Gain'
                                        * '<S70>/Depth Derivative Gain'
                                        * '<S40>/Depth Derivative Gain'
                                        * '<S50>/Depth Derivative Gain'
                                        */
  real_T Depth_Ki;                     /* Variable: Depth_Ki
                                        * Referenced by blocks:
                                        * '<S31>/Depth Integral Gain'
                                        * '<S58>/Depth Integral Gain'
                                        * '<S70>/Depth Integral Gain'
                                        * '<S40>/Depth Integral Gain'
                                        * '<S50>/Depth Integral Gain'
                                        */
  real_T Depth_Kp;                     /* Variable: Depth_Kp
                                        * Referenced by blocks:
                                        * '<S31>/Depth Proportional Gain'
                                        * '<S58>/Depth Proportional Gain'
                                        * '<S70>/Depth Proportional Gain'
                                        * '<S40>/Depth Proportional Gain'
                                        * '<S50>/Depth Proportional Gain'
                                        */
  real_T Heading_Forward_Velocity;     /* Variable: Heading_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S5>/Heading Forward Velocity'
                                        * '<S5>/Heading Forward Velocity2'
                                        * '<S10>/Heading_Forward_Velocity'
                                        * '<S10>/Heading_Forward_Velocity1'
                                        */
  real_T Heading_Kd;                   /* Variable: Heading_Kd
                                        * Referenced by blocks:
                                        * '<S32>/Heading Derivative Gain'
                                        * '<S59>/Heading Derivative Gain'
                                        * '<S71>/Heading Derivative Gain'
                                        */
  real_T Heading_Ki;                   /* Variable: Heading_Ki
                                        * Referenced by blocks:
                                        * '<S32>/Heading Integral Gain'
                                        * '<S59>/Heading Integral Gain'
                                        * '<S71>/Heading Integral Gain'
                                        */
  real_T Heading_Kp;                   /* Variable: Heading_Kp
                                        * Referenced by blocks:
                                        * '<S32>/Heading Proportional Gain'
                                        * '<S59>/Heading Proportional Gain'
                                        * '<S71>/Heading Proportional Gain'
                                        */
  real_T Track_HueHigher;              /* Variable: Track_HueHigher
                                        * Referenced by blocks:
                                        * '<S37>/Constant'
                                        * '<S47>/Constant'
                                        * '<S64>/Constant'
                                        */
  real_T Track_HueLower;               /* Variable: Track_HueLower
                                        * Referenced by blocks:
                                        * '<S38>/Constant'
                                        * '<S48>/Constant'
                                        * '<S65>/Constant'
                                        */
  real_T Track_Saturation;             /* Variable: Track_Saturation
                                        * Referenced by blocks:
                                        * '<S39>/Constant'
                                        * '<S49>/Constant'
                                        * '<S67>/Constant'
                                        */
  real_T Vision_Forward_Velocity;      /* Variable: Vision_Forward_Velocity
                                        * Referenced by blocks:
                                        * '<S17>/Vision_Forward_Velocity'
                                        * '<S17>/Vision_Forward_Velocity2'
                                        */
  uint32_T Max_Blob_Size;              /* Variable: Max_Blob_Size
                                        * Referenced by blocks:
                                        * '<S3>/Buoy Blob Analysis'
                                        * '<S23>/Blob Analysis'
                                        * '<S36>/Blob Analysis'
                                        * '<S45>/Blob Analysis'
                                        * '<S62>/Blob Analysis'
                                        */
  uint32_T Min_Blob_Size;              /* Variable: Min_Blob_Size
                                        * Referenced by blocks:
                                        * '<S3>/Buoy Blob Analysis'
                                        * '<S23>/Blob Analysis'
                                        * '<S36>/Blob Analysis'
                                        * '<S45>/Blob Analysis'
                                        * '<S62>/Blob Analysis'
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
  extern void brain_terminate(void);

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
 * '<S2>'   : brain/GetVideo1
 * '<S3>'   : brain/Chart/Running.Buoy.Buoy
 * '<S4>'   : brain/Chart/Running.FindBuoy.LookforBuoy
 * '<S5>'   : brain/Chart/Running.FindBuoy.StraightLevelControl
 * '<S6>'   : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1
 * '<S7>'   : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2
 * '<S8>'   : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl
 * '<S9>'   : brain/Chart/Running.ValidationGate.LookforTrack
 * '<S10>'  : brain/Chart/Running.ValidationGate.StraightLevelControl
 * '<S11>'  : brain/Chart/Running.Buoy.Buoy/Buoy HueHigher
 * '<S12>'  : brain/Chart/Running.Buoy.Buoy/Buoy HueLower
 * '<S13>'  : brain/Chart/Running.Buoy.Buoy/Buoy Saturation
 * '<S14>'  : brain/Chart/Running.Buoy.Buoy/Embedded MATLAB Function
 * '<S15>'  : brain/Chart/Running.Buoy.Buoy/Median Filter
 * '<S16>'  : brain/Chart/Running.Buoy.Buoy/Resize
 * '<S17>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl
 * '<S18>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl
 * '<S19>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl/PID Controller X Position
 * '<S20>'  : brain/Chart/Running.Buoy.Buoy/X-HeadingControl/PID Controller X Position/X-Buoy Discrete Derivative
 * '<S21>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl/PID Controller Y Position
 * '<S22>'  : brain/Chart/Running.Buoy.Buoy/Y-DepthControl/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S23>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis
 * '<S24>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Buoy_HueHigher
 * '<S25>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Buoy_HueLower
 * '<S26>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/FoundBuoy
 * '<S27>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/NoBuoy
 * '<S28>'  : brain/Chart/Running.FindBuoy.LookforBuoy/Analysis/Saturation Comparison
 * '<S29>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/BigError S1
 * '<S30>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/BigNegativeError S2
 * '<S31>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Depth S3
 * '<S32>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Heading S4
 * '<S33>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S34>'  : brain/Chart/Running.FindBuoy.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S35>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/AimAtTrack
 * '<S36>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/FindDesiredHeading
 * '<S37>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/Track Hue Higher
 * '<S38>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/Track Hue Lower
 * '<S39>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/Track Saturation
 * '<S40>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/AimAtTrack/PID Controller Depth S3
 * '<S41>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/AimAtTrack/PID Controller XPosition
 * '<S42>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/AimAtTrack/PID Controller Depth S3/Depth Discrete Derivative
 * '<S43>'  : brain/Chart/Running.FollowTrack.Stage1Aim.TrackStage1/AimAtTrack/PID Controller XPosition/Depth Discrete Derivative
 * '<S44>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/AimAtTrack
 * '<S45>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/FindDesiredHeading
 * '<S46>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/PositionOverCentroid
 * '<S47>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/Track Hue Higher
 * '<S48>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/Track Hue Lower
 * '<S49>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/Track Saturation
 * '<S50>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/AimAtTrack/PID Controller Depth S3
 * '<S51>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/AimAtTrack/PID Controller XPosition
 * '<S52>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/AimAtTrack/PID Controller Depth S3/Depth Discrete Derivative
 * '<S53>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/AimAtTrack/PID Controller XPosition/Depth Discrete Derivative
 * '<S54>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/PositionOverCentroid/PID Controller Y Position
 * '<S55>'  : brain/Chart/Running.FollowTrack.Stage2Position.TrackStage2/PositionOverCentroid/PID Controller Y Position/Y-Buoy Discrete Derivative
 * '<S56>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/BigError S1
 * '<S57>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/BigNegativeError S2
 * '<S58>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/PID Controller Depth S3
 * '<S59>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/PID Controller Heading S4
 * '<S60>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S61>'  : brain/Chart/Running.FollowTrack.Stage3ReOrient.DirectionalControl/PID Controller Heading S4/Heading Discrete Derivative
 * '<S62>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack
 * '<S63>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/FoundTrack
 * '<S64>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Hue Higher Comparison
 * '<S65>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Hue Lower Comparison
 * '<S66>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/NoTrack
 * '<S67>'  : brain/Chart/Running.ValidationGate.LookforTrack/LookforTrack/Saturation Comparison
 * '<S68>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/BigError S1
 * '<S69>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/BigNegativeError S2
 * '<S70>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Depth S3
 * '<S71>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Heading S4
 * '<S72>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Depth S3/Depth Discrete Derivative
 * '<S73>'  : brain/Chart/Running.ValidationGate.StraightLevelControl/PID Controller Heading S4/Heading Discrete Derivative
 */
#endif                                 /* RTW_HEADER_brain_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
