/*
 * File: VisionModel.h
 *
 * Real-Time Workshop code generated for Simulink model VisionModel.
 *
 * Model version                        : 1.1389
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Fri Jul 15 10:08:40 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Fri Jul 15 10:08:41 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VisionModel_h_
#define RTW_HEADER_VisionModel_h_
#ifndef VisionModel_COMMON_INCLUDES_
# define VisionModel_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_pow_snf.h"
#endif                                 /* VisionModel_COMMON_INCLUDES_ */

#include "VisionModel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S3>/validation_gate' */
typedef struct {
  real_T ColorFilter1[7];              /* '<S42>/ColorFilter1' */
  real_T OutputSegmentedImage1;        /* '<S42>/OutputSegmentedImage1' */
} rtB_validation_gate_VisionModel;

/* Block signals for system '<S16>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S16>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_VisionModel;

/* Block signals for system '<S17>/Reference Color Selection' */
typedef struct {
  uint32_T LabelMatrix[4800];
  real_T ref_colors[150];              /* '<S17>/Reference Color Selection' */
  real_T num_colors;                   /* '<S17>/Reference Color Selection' */
} rtB_ReferenceColorSelection_Vis;

/* Block signals for system '<S28>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S28>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_VisionModel_h;

/* Block signals for system '<S57>/Transform Coordinates3' */
typedef struct {
  real_T points[2];                    /* '<S57>/Transform Coordinates3' */
} rtB_TransformCoordinates3_Visio;

/* Block signals for system '<S7>/If Action Subsystem' */
typedef struct {
  real_T DrawTarget_o1[19200];         /* '<S47>/Draw Target' */
  real_T DrawTarget_o2[19200];         /* '<S47>/Draw Target' */
  real_T DrawTarget_o3[19200];         /* '<S47>/Draw Target' */
  rtB_TransformCoordinates3_Visio sf_TransformCoordinates3;/* '<S47>/Transform Coordinates3' */
} rtB_IfActionSubsystem_VisionMod;

/* Block signals (auto storage) */
typedef struct {
  real_T hough_table[71820];
  real_T ColorSpaceConversion2_o1[19200];/* '<S5>/Color Space  Conversion2' */
  real_T ColorSpaceConversion2_o2[19200];/* '<S5>/Color Space  Conversion2' */
  real_T ColorSpaceConversion2_o3[19200];/* '<S5>/Color Space  Conversion2' */
  real_T ColorSpaceConversion4_o1[19200];/* '<S4>/Color Space  Conversion4' */
  real_T ColorSpaceConversion4_o2[19200];/* '<S4>/Color Space  Conversion4' */
  real_T ColorSpaceConversion4_o3[19200];/* '<S4>/Color Space  Conversion4' */
  real_T Divide4[19200];               /* '<S5>/Divide4' */
  real_T Divide3[19200];               /* '<S5>/Divide3' */
  real_T a_range[14];                  /* '<Root>/make_color_range' */
  real_T b_range[14];                  /* '<Root>/make_color_range' */
  real_T HoughTransform2_o1[71820];    /* '<S6>/Hough Transform2' */
  real_T HoughTransform2_o2[180];      /* '<S6>/Hough Transform2' */
  real_T HoughTransform2_o3[399];      /* '<S6>/Hough Transform2' */
  real_T target_select;                /* '<S6>/Identify L-Obstacle' */
  real_T maintain_heading;             /* '<S6>/Identify L-Obstacle' */
  real_T target_y;                     /* '<S6>/Identify L-Obstacle' */
  real_T target_z;                     /* '<S6>/Identify L-Obstacle' */
  real_T target_yaw;                   /* '<S6>/Identify L-Obstacle' */
  real_T target_detected;              /* '<S6>/Identify L-Obstacle' */
  real_T target_select_j;              /* '<S11>/Decide which target to follow' */
  real_T maintain_heading_i;           /* '<S11>/Decide which target to follow' */
  real_T target_y_m;                   /* '<S11>/Decide which target to follow' */
  real_T target_z_d;                   /* '<S11>/Decide which target to follow' */
  real_T target_yaw_k;                 /* '<S11>/Decide which target to follow' */
  real_T target_detected_e;            /* '<S11>/Decide which target to follow' */
  real_T fire_authorization;           /* '<S11>/Decide which target to follow' */
  real_T buoy_centroids[100];          /* '<S7>/Shape_Analysis' */
  real_T target_select_f;              /* '<S7>/Choose_Buoy' */
  real_T maintain_heading_n;           /* '<S7>/Choose_Buoy' */
  real_T targetY;                      /* '<S7>/Choose_Buoy' */
  real_T targetZ;                      /* '<S7>/Choose_Buoy' */
  real_T targetYaw;                    /* '<S7>/Choose_Buoy' */
  real_T target_detected_d;            /* '<S7>/Choose_Buoy' */
  real_T ColorFilter1;                 /* '<S10>/ColorFilter1' */
  real_T ColorFilter3;                 /* '<S10>/ColorFilter3' */
  real_T HoughTransform1_o1[1260];     /* '<S10>/Hough Transform1' */
  real_T HoughTransform1_o2[180];      /* '<S10>/Hough Transform1' */
  real_T Add18;                        /* '<S10>/Add18' */
  real_T target_x;                     /* '<S10>/Identify Path Elements1' */
  real_T target_y_i;                   /* '<S10>/Identify Path Elements1' */
  real_T path_state;                   /* '<S10>/Identify Path Elements1' */
  real_T path_found;                   /* '<S10>/Identify Path Elements' */
  real_T HoughTransform1_o1_b[71820];  /* '<S12>/Hough Transform1' */
  real_T HoughTransform1_o2_i[180];    /* '<S12>/Hough Transform1' */
  real_T HoughTransform1_o3_i[399];    /* '<S12>/Hough Transform1' */
  real_T Constant3;                    /* '<S12>/Constant3' */
  real_T Constant4;                    /* '<S12>/Constant4' */
  real_T DrawShapes_o1[19200];         /* '<S57>/Draw Shapes' */
  real_T DrawShapes_o2[19200];         /* '<S57>/Draw Shapes' */
  real_T DrawShapes_o3[19200];         /* '<S57>/Draw Shapes' */
  real_T target_y_c;                   /* '<S12>/Identify Validation Gate' */
  real_T target_z_o;                   /* '<S12>/Identify Validation Gate' */
  real_T target_yaw_o;                 /* '<S12>/Identify Validation Gate' */
  real_T gate_found;                   /* '<S12>/Identify Validation Gate' */
  real_T ColorSpaceConversion1_o1[19200];/* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S26>/Color Space  Conversion1' */
  real_T Resize[4800];                 /* '<S35>/Resize' */
  real_T Resize1[4800];                /* '<S35>/Resize1' */
  real_T Resize2[4800];                /* '<S35>/Resize2' */
  real_T LabelMatrix[19200];           /* '<S29>/LabSegmentation' */
  real_T blob_hues[150];               /* '<S2>/Blob Extraction' */
  real_T blob_area[50];                /* '<S2>/Blob Extraction' */
  real_T blob_centroids[100];          /* '<S2>/Blob Extraction' */
  real_T blob_bbox[200];               /* '<S2>/Blob Extraction' */
  real_T blob_major_axis[50];          /* '<S2>/Blob Extraction' */
  real_T blob_minor_axis[50];          /* '<S2>/Blob Extraction' */
  real_T blob_orientation[50];         /* '<S2>/Blob Extraction' */
  real_T blob_eccentricity[50];        /* '<S2>/Blob Extraction' */
  real_T blob_extent[50];              /* '<S2>/Blob Extraction' */
  real_T blob_count;                   /* '<S2>/Blob Extraction' */
  real_T blob_color[50];               /* '<S2>/Blob Extraction' */
  real_T bw_image[9];                  /* '<S2>/Blob Extraction' */
  real_T ColorSpaceConversion1_o1_i[19200];/* '<S14>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_g[19200];/* '<S14>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_j[19200];/* '<S14>/Color Space  Conversion1' */
  real_T Resize_e[4800];               /* '<S23>/Resize' */
  real_T Resize1_l[4800];              /* '<S23>/Resize1' */
  real_T Resize2_l[4800];              /* '<S23>/Resize2' */
  real_T LabelMatrix_n[19200];         /* '<S17>/LabSegmentation' */
  real_T ColorSpaceConversion_o1_m[19200];/* '<S15>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o2_a[19200];/* '<S15>/Color Space  Conversion' */
  real_T ColorSpaceConversion_o3_p[19200];/* '<S15>/Color Space  Conversion' */
  real_T blob_hues_g[150];             /* '<S1>/Blob Extraction' */
  real_T blob_area_p[50];              /* '<S1>/Blob Extraction' */
  real_T blob_centroids_m[100];        /* '<S1>/Blob Extraction' */
  real_T blob_bbox_o[200];             /* '<S1>/Blob Extraction' */
  real_T blob_major_axis_e[50];        /* '<S1>/Blob Extraction' */
  real_T blob_minor_axis_i[50];        /* '<S1>/Blob Extraction' */
  real_T blob_orientation_g[50];       /* '<S1>/Blob Extraction' */
  real_T blob_eccentricity_h[50];      /* '<S1>/Blob Extraction' */
  real_T blob_extent_k[50];            /* '<S1>/Blob Extraction' */
  real_T blob_count_c;                 /* '<S1>/Blob Extraction' */
  real_T blob_color_i[50];             /* '<S1>/Blob Extraction' */
  real_T bw_image_e[19200];            /* '<S1>/Blob Extraction' */
  real_T Add22[7];                     /* '<S3>/Add22' */
  real_T ColorSpaceConversion1_o1_m[19200];/* '<S5>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2_e[19200];/* '<S5>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3_jm[19200];/* '<S5>/Color Space  Conversion1' */
  real_T ColorSpaceConversion3_o1[19200];/* '<S4>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o2[19200];/* '<S4>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o3[19200];/* '<S4>/Color Space  Conversion3' */
  real_T Divide5[19200];               /* '<S5>/Divide5' */
  int8_T bw_image_m[19200];
  boolean_T LogicMatrix[19200];
  real_T hough_table_c[1260];
  int32_T HoughLines[12];              /* '<S57>/Hough Lines' */
  boolean_T EdgeDetection1[19200];     /* '<S6>/Edge Detection1' */
  boolean_T EdgeDetection[9];          /* '<S10>/Edge Detection' */
  boolean_T EdgeDetection_k[19200];    /* '<S12>/Edge Detection' */
  rtB_IfActionSubsystem_VisionMod IfActionSubsystem_m;/* '<S6>/If Action Subsystem' */
  rtB_IfActionSubsystem_VisionMod IfActionSubsystem_l;/* '<S11>/If Action Subsystem' */
  rtB_IfActionSubsystem_VisionMod IfActionSubsystem_h;/* '<S7>/If Action Subsystem' */
  rtB_TransformCoordinates3_Visio sf_TransformCoordinates3;/* '<S57>/Transform Coordinates3' */
  rtB_ReferenceColorSelection_Vis sf_ReferenceColorSelection_e;/* '<S29>/Reference Color Selection' */
  rtB_LowPassFilter_VisionModel_h sf_LowPassFilter2_n;/* '<S28>/Low Pass Filter2' */
  rtB_LowPassFilter_VisionModel_h sf_LowPassFilter1_e;/* '<S28>/Low Pass Filter1' */
  rtB_LowPassFilter_VisionModel_h sf_LowPassFilter_f;/* '<S28>/Low Pass Filter' */
  rtB_ReferenceColorSelection_Vis sf_ReferenceColorSelection;/* '<S17>/Reference Color Selection' */
  rtB_LowPassFilter_VisionModel sf_LowPassFilter2;/* '<S16>/Low Pass Filter2' */
  rtB_LowPassFilter_VisionModel sf_LowPassFilter1;/* '<S16>/Low Pass Filter1' */
  rtB_LowPassFilter_VisionModel sf_LowPassFilter;/* '<S16>/Low Pass Filter' */
  rtB_validation_gate_VisionModel drop_mech_b;/* '<S3>/drop_mech' */
  rtB_validation_gate_VisionModel L_detector_i;/* '<S3>/L_detector' */
  rtB_validation_gate_VisionModel torpedo_l;/* '<S3>/torpedo' */
  rtB_validation_gate_VisionModel buoy_detector_h;/* '<S3>/buoy_detector' */
  rtB_validation_gate_VisionModel path_detector_c;/* '<S3>/path_detector' */
  rtB_validation_gate_VisionModel validation_gate_p;/* '<S3>/validation_gate' */
} BlockIO_VisionModel;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S5>/Color Space  Conversion1' */
  real_T ColorSpaceConversion2_DWORK1[19200];/* '<S5>/Color Space  Conversion2' */
  real_T ColorSpaceConversion3_DWORK1[19200];/* '<S4>/Color Space  Conversion3' */
  real_T ColorSpaceConversion4_DWORK1[19200];/* '<S4>/Color Space  Conversion4' */
  real_T EdgeDetection1_GV_SQUARED_DW[19200];/* '<S6>/Edge Detection1' */
  real_T EdgeDetection1_GH_SQUARED_DW[19200];/* '<S6>/Edge Detection1' */
  real_T EdgeDetection1_GRAD_SUM_DW[19200];/* '<S6>/Edge Detection1' */
  real_T Resize_IntBuffer_l[12800];    /* '<S23>/Resize' */
  real_T Resize1_IntBuffer_j[12800];   /* '<S23>/Resize1' */
  real_T Resize2_IntBuffer_p[12800];   /* '<S23>/Resize2' */
  real_T Resize_IntBuffer[9600];       /* '<S35>/Resize' */
  real_T Resize1_IntBuffer[9600];      /* '<S35>/Resize1' */
  real_T Resize2_IntBuffer[9600];      /* '<S35>/Resize2' */
  real_T EdgeDetection1_MEAN_FACTOR_DW;/* '<S6>/Edge Detection1' */
  real_T EdgeDetection_MEAN_FACTOR_DW; /* '<S10>/Edge Detection' */
  real_T EdgeDetection_MEAN_FACTOR_DW_j;/* '<S12>/Edge Detection' */
  real_T ColorSpaceConversion1_DWORK1_c[19200];/* '<S26>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1[19200];/* '<S27>/Color Space  Conversion' */
  real_T F1_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F3_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F4_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F5_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F6_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F7_RTP;                       /* '<S2>/Blob Extraction' */
  real_T ColorSpaceConversion1_DWORK1_b[19200];/* '<S14>/Color Space  Conversion1' */
  real_T ColorSpaceConversion_DWORK1_p[19200];/* '<S15>/Color Space  Conversion' */
  real_T F1_RTP_m;                     /* '<S1>/Blob Extraction' */
  real_T F3_RTP_k;                     /* '<S1>/Blob Extraction' */
  real_T F4_RTP_j;                     /* '<S1>/Blob Extraction' */
  real_T F5_RTP_p;                     /* '<S1>/Blob Extraction' */
  real_T F6_RTP_k;                     /* '<S1>/Blob Extraction' */
  real_T F7_RTP_j;                     /* '<S1>/Blob Extraction' */
  int32_T EdgeDetection1_VO_DW[6];     /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HO_DW[6];     /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOU_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOD_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOL_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOR_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOU_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOD_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOL_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOR_DW[6];    /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOUL_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOLL_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOUR_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_VOLR_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOUL_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOLL_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOUR_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection1_HOLR_DW[6];   /* '<S6>/Edge Detection1' */
  int32_T EdgeDetection_VO_DW[6];      /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<S10>/Edge Detection' */
  int32_T EdgeDetection_VO_DW_l[6];    /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HO_DW_p[6];    /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW_l[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW_p[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW_k[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW_f[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW_k[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW_i[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW_g[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW_b[6];   /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW_k[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW_j[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW_b[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW_b[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW_k[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW_f[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW_a[6];  /* '<S12>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW_a[6];  /* '<S12>/Edge Detection' */
  int32_T WALKER_RTP[8];               /* '<S2>/Blob Extraction' */
  int32_T F0_RTP;                      /* '<S2>/Blob Extraction' */
  int32_T F2_RTP;                      /* '<S2>/Blob Extraction' */
  int32_T WALKER_RTP_f[8];             /* '<S1>/Blob Extraction' */
  int32_T F0_RTP_a;                    /* '<S1>/Blob Extraction' */
  int32_T F2_RTP_m;                    /* '<S1>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S2>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S2>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S2>/Blob Extraction' */
  uint32_T MINAREA_RTP_h;              /* '<S1>/Blob Extraction' */
  uint32_T NUM_PIX_DW_f[50];           /* '<S1>/Blob Extraction' */
  uint32_T STACK_DW_a[19200];          /* '<S1>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S2>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S2>/Blob Extraction' */
  int16_T N_PIXLIST_DW_l[19200];       /* '<S1>/Blob Extraction' */
  int16_T M_PIXLIST_DW_i[19200];       /* '<S1>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S2>/Blob Extraction' */
  uint8_T PAD_DW_m[19764];             /* '<S1>/Blob Extraction' */
} D_Work_VisionModel;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S23>/Resize'
   *   '<S23>/Resize1'
   *   '<S23>/Resize2'
   */
  real_T pooled5[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S23>/Resize'
   *   '<S23>/Resize1'
   *   '<S23>/Resize2'
   */
  real_T pooled6[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S35>/Resize'
   *   '<S35>/Resize1'
   *   '<S35>/Resize2'
   */
  real_T pooled7[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S35>/Resize'
   *   '<S35>/Resize1'
   *   '<S35>/Resize2'
   */
  real_T pooled8[320];

  /* Computed Parameter: DrawShapes_RTP_FILLCO
   * Referenced by: '<S57>/Draw Shapes'
   */
  real_T DrawShapes_RTP_FILLCO[3];

  /* Computed Parameter: HoughTransform1_FIRSTRHO_R
   * Referenced by: '<S10>/Hough Transform1'
   */
  real_T HoughTransform1_FIRSTRHO_R;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  real_T pooled9[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  real_T pooled10[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Hough Transform2'
   *   '<S10>/Hough Transform1'
   *   '<S12>/Hough Transform1'
   */
  real_T pooled11[91];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Hough Transform2'
   *   '<S12>/Hough Transform1'
   */
  real_T pooled12;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S23>/Resize'
   *   '<S23>/Resize1'
   *   '<S23>/Resize2'
   */
  int32_T pooled13[360];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S23>/Resize'
   *   '<S23>/Resize1'
   *   '<S23>/Resize2'
   */
  int32_T pooled14[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S35>/Resize'
   *   '<S35>/Resize1'
   *   '<S35>/Resize2'
   */
  int32_T pooled15[240];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S35>/Resize'
   *   '<S35>/Resize1'
   *   '<S35>/Resize2'
   */
  int32_T pooled16[320];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  int32_T pooled17[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  int32_T pooled18[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  int32_T pooled19[6];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Edge Detection1'
   *   '<S10>/Edge Detection'
   *   '<S12>/Edge Detection'
   */
  int32_T pooled20[6];
} ConstParam_VisionModel;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T R_forward_in[19200];          /* '<Root>/R_forward_in' */
  real_T G_forward_in[19200];          /* '<Root>/G_forward_in' */
  real_T B_forward_in[19200];          /* '<Root>/B_forward_in' */
  real_T R_down_in[19200];             /* '<Root>/R_down_in' */
  real_T G_down_in[19200];             /* '<Root>/G_down_in' */
  real_T B_down_in[19200];             /* '<Root>/B_down_in' */
  real_T ModeSelect;                   /* '<Root>/ModeSelect' */
  real_T OutputImage;                  /* '<Root>/OutputImage' */
  real_T DesiredPathDirection;         /* '<Root>/DesiredPathDirection' */
  real_T DesiredBuoyColor;             /* '<Root>/DesiredBuoyColor' */
  real_T DesiredTorpedoColor;          /* '<Root>/DesiredTorpedoColor' */
  real_T white_al;                     /* '<Root>/white_al' */
  real_T white_au;                     /* '<Root>/white_au' */
  real_T white_bl;                     /* '<Root>/white_bl' */
  real_T white_bu;                     /* '<Root>/white_bu' */
  real_T black_al;                     /* '<Root>/black_al' */
  real_T black_au;                     /* '<Root>/black_au' */
  real_T black_bl;                     /* '<Root>/black_bl' */
  real_T black_bu;                     /* '<Root>/black_bu' */
  real_T blue_al;                      /* '<Root>/blue_al' */
  real_T blue_au;                      /* '<Root>/blue_au' */
  real_T blue_bl;                      /* '<Root>/blue_bl' */
  real_T blue_bu;                      /* '<Root>/blue_bu' */
  real_T red_al;                       /* '<Root>/red_al' */
  real_T red_au;                       /* '<Root>/red_au' */
  real_T red_bl;                       /* '<Root>/red_bl' */
  real_T red_bu;                       /* '<Root>/red_bu' */
  real_T orange_al;                    /* '<Root>/orange_al' */
  real_T orange_au;                    /* '<Root>/orange_au' */
  real_T orange_bl;                    /* '<Root>/orange_bl' */
  real_T orange_bu;                    /* '<Root>/orange_bu' */
  real_T yellow_al;                    /* '<Root>/yellow_al' */
  real_T yellow_au;                    /* '<Root>/yellow_au' */
  real_T yellow_bl;                    /* '<Root>/yellow_bl' */
  real_T yellow_bu;                    /* '<Root>/yellow_bu' */
  real_T green_al;                     /* '<Root>/green_al' */
  real_T green_au;                     /* '<Root>/green_au' */
  real_T green_bl;                     /* '<Root>/green_bl' */
  real_T green_bu;                     /* '<Root>/green_bu' */
  real_T black_override;               /* '<Root>/black_override' */
  real_T white_override;               /* '<Root>/white_override' */
  real_T blue_override;                /* '<Root>/blue_override' */
  real_T red_override;                 /* '<Root>/red_override' */
  real_T orange_override;              /* '<Root>/orange_override' */
  real_T yellow_override;              /* '<Root>/yellow_override' */
  real_T green_override;               /* '<Root>/green_override' */
  real_T Scale_Forward_R;              /* '<Root>/Scale_Forward_R' */
  real_T Scale_Forward_G;              /* '<Root>/Scale_Forward_G' */
  real_T Scale_Forward_B;              /* '<Root>/Scale_Forward_B' */
  real_T Scale_Forward_H;              /* '<Root>/Scale_Forward_H' */
  real_T Scale_Forward_S;              /* '<Root>/Scale_Forward_S' */
  real_T Scale_Forward_V;              /* '<Root>/Scale_Forward_V' */
  real_T Scale_Down_R;                 /* '<Root>/Scale_Down_R' */
  real_T Scale_Down_G;                 /* '<Root>/Scale_Down_G' */
  real_T Scale_Down_B;                 /* '<Root>/Scale_Down_B' */
  real_T Scale_Down_H;                 /* '<Root>/Scale_Down_H' */
  real_T Scale_Down_S;                 /* '<Root>/Scale_Down_S' */
  real_T Scale_Down_V;                 /* '<Root>/Scale_Down_V' */
  real_T MeasuredYaw;                  /* '<Root>/MeasuredYaw' */
} ExternalInputs_VisionModel;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T R_forward_out[19200];         /* '<Root>/R_forward_out' */
  real_T G_forward_out[19200];         /* '<Root>/G_forward_out' */
  real_T B_forward_out[19200];         /* '<Root>/B_forward_out' */
  real_T R_down_out[19200];            /* '<Root>/R_down_out' */
  real_T G_down_out[19200];            /* '<Root>/G_down_out' */
  real_T B_down_out[19200];            /* '<Root>/B_down_out' */
  real_T TargetSelect;                 /* '<Root>/TargetSelect' */
  real_T MaintainHeading;              /* '<Root>/MaintainHeading' */
  real_T TargetX;                      /* '<Root>/TargetX' */
  real_T TargetY;                      /* '<Root>/TargetY' */
  real_T TargetZ;                      /* '<Root>/TargetZ' */
  real_T TargetYaw;                    /* '<Root>/TargetYaw' */
  real_T DesiredTargetX;               /* '<Root>/DesiredTargetX' */
  real_T DesiredTargetY;               /* '<Root>/DesiredTargetY' */
  real_T DesiredTargetZ;               /* '<Root>/DesiredTargetZ' */
  real_T DesiredTargetYaw;             /* '<Root>/DesiredTargetYaw' */
  real_T TargetDetected;               /* '<Root>/TargetDetected' */
  real_T PathState;                    /* '<Root>/PathState' */
  real_T BuoyColors[100];              /* '<Root>/BuoyColors' */
  real_T FireAuthorization;            /* '<Root>/FireAuthorization' */
  real_T TargetType;                   /* '<Root>/TargetType' */
  real_T TargetSize[9];                /* '<Root>/TargetSize' */
} ExternalOutputs_VisionModel;

/* Parameters for system: '<S3>/validation_gate' */
struct rtP_validation_gate_VisionModel_ {
  real_T ColorFilter1_Value[7];        /* Expression: [0 1 0 0 1 0 0]
                                        * Referenced by: '<S42>/ColorFilter1'
                                        */
  real_T OutputSegmentedImage1_Value;  /* Expression: 1
                                        * Referenced by: '<S42>/OutputSegmentedImage1'
                                        */
};

/* Parameters for system: '<S7>/If Action Subsystem' */
struct rtP_IfActionSubsystem_VisionMod_ {
  real_T DrawTarget_RTP_FILLCOLOR[3];  /* Expression: color
                                        * Referenced by: '<S47>/Draw Target'
                                        */
  real_T DrawTarget_RTP_SIZE;          /* Expression: size
                                        * Referenced by: '<S47>/Draw Target'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_VisionModel_ {
  real_T DesiredBuoyColor1_Value;      /* Expression: 35
                                        * Referenced by: '<S17>/DesiredBuoyColor1'
                                        */
  real_T DesiredBuoyColor13_Value;     /* Expression: 35
                                        * Referenced by: '<S29>/DesiredBuoyColor13'
                                        */
  real_T DrawTarget_RTP_FILLCOLOR[3];  /* Expression: color
                                        * Referenced by: '<S57>/Draw Target'
                                        */
  real_T DrawTarget_RTP_SIZE;          /* Expression: size
                                        * Referenced by: '<S57>/Draw Target'
                                        */
  real_T Constant1_Value;              /* Expression: .6
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: .47
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T EdgeDetection_THRESH_TUNING_RTP;/* Expression: thresholdTuning
                                          * Referenced by: '<S12>/Edge Detection'
                                          */
  real_T Forward_Camera_Dimensions_Value[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S12>/Forward_Camera_Dimensions'
                                             */
  real_T Forward_Camera_Dimensions1_Valu[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S12>/Forward_Camera_Dimensions1'
                                             */
  real_T Forward_Fov_Value;            /* Expression: Forward_Fov
                                        * Referenced by: '<S12>/Forward_Fov'
                                        */
  real_T which_camera_Value;           /* Expression: 0
                                        * Referenced by: '<S12>/which_camera'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T ColorFilter1_Value;           /* Expression: 2
                                        * Referenced by: '<S10>/ColorFilter1'
                                        */
  real_T ColorFilter3_Value;           /* Expression: 1
                                        * Referenced by: '<S10>/ColorFilter3'
                                        */
  real_T EdgeDetection_THRESH_TUNING_R_h;/* Expression: thresholdTuning
                                          * Referenced by: '<S10>/Edge Detection'
                                          */
  real_T Forward_Camera_Dimensions_Val_i[2];/* Expression: Down_Camera_Dimensions
                                             * Referenced by: '<S10>/Forward_Camera_Dimensions'
                                             */
  real_T Constant_Value;               /* Expression: Buoy_Min_Eccentricity
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: Buoy_Max_Eccentricity
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: Buoy_Min_Extent
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: Buoy_Max_Extent
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Forward_Camera_Dimensions1_Va_f[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S7>/Forward_Camera_Dimensions1'
                                             */
  real_T Forward_Camera_Dimensions3_Valu;/* Expression: Forward_Fov
                                          * Referenced by: '<S7>/Forward_Camera_Dimensions3'
                                          */
  real_T Forward_Camera_Dimensions2_Valu[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S7>/Forward_Camera_Dimensions2'
                                             */
  real_T which_camera_Value_k;         /* Expression: 0
                                        * Referenced by: '<S7>/which_camera'
                                        */
  real_T Constant_Value_l;             /* Expression: Buoy_Min_Eccentricity
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: Buoy_Max_Eccentricity
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: Buoy_Min_Extent
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: Buoy_Max_Extent
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Forward_Camera_Dimensions2_Va_d[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S11>/Forward_Camera_Dimensions2'
                                             */
  real_T which_camera_Value_j;         /* Expression: 0
                                        * Referenced by: '<S11>/which_camera'
                                        */
  real_T Constant1_Value_i;            /* Expression: .3
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: Forward_Fov
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant5_Value;              /* Expression: .3
                                        * Referenced by: '<S6>/Constant5'
                                        */
  real_T EdgeDetection1_THRESH_TUNING_RT;/* Expression: thresholdTuning
                                          * Referenced by: '<S6>/Edge Detection1'
                                          */
  real_T Forward_Camera_Dimensions_Val_h[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S6>/Forward_Camera_Dimensions'
                                             */
  real_T Forward_Camera_Dimensions2_Va_e[2];/* Expression: Forward_Camera_Dimensions
                                             * Referenced by: '<S6>/Forward_Camera_Dimensions2'
                                             */
  real_T which_camera_Value_h;         /* Expression: 0
                                        * Referenced by: '<S6>/which_camera'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value_fh;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value_iy;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  rtP_IfActionSubsystem_VisionMod IfActionSubsystem_m;/* '<S6>/If Action Subsystem' */
  rtP_IfActionSubsystem_VisionMod IfActionSubsystem_l;/* '<S11>/If Action Subsystem' */
  rtP_IfActionSubsystem_VisionMod IfActionSubsystem_h;/* '<S7>/If Action Subsystem' */
  rtP_validation_gate_VisionModel drop_mech_b;/* '<S3>/drop_mech' */
  rtP_validation_gate_VisionModel L_detector_i;/* '<S3>/L_detector' */
  rtP_validation_gate_VisionModel torpedo_l;/* '<S3>/torpedo' */
  rtP_validation_gate_VisionModel buoy_detector_h;/* '<S3>/buoy_detector' */
  rtP_validation_gate_VisionModel path_detector_c;/* '<S3>/path_detector' */
  rtP_validation_gate_VisionModel validation_gate_p;/* '<S3>/validation_gate' */
};

/* Real-time Model Data Structure */
struct RT_MODEL_VisionModel {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_VisionModel VisionModel_P;

/* Block signals (auto storage) */
extern BlockIO_VisionModel VisionModel_B;

/* Block states (auto storage) */
extern D_Work_VisionModel VisionModel_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_VisionModel VisionModel_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_VisionModel VisionModel_Y;

/* Constant parameters (auto storage) */
extern const ConstParam_VisionModel VisionModel_ConstP;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void VisionModel_initialize(void);
  extern void VisionModel_step(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_VisionModel *VisionModel_M;

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
 * '<Root>' : VisionModel
 * '<S1>'   : VisionModel/Blob_Analysis
 * '<S2>'   : VisionModel/Blob_Analysis1
 * '<S3>'   : VisionModel/ColorSelect
 * '<S4>'   : VisionModel/Down Filter
 * '<S5>'   : VisionModel/Forward Filter
 * '<S6>'   : VisionModel/L_detector
 * '<S7>'   : VisionModel/buoy_detector
 * '<S8>'   : VisionModel/drop_mech
 * '<S9>'   : VisionModel/make_color_range
 * '<S10>'  : VisionModel/path_detector
 * '<S11>'  : VisionModel/torpedo
 * '<S12>'  : VisionModel/validation_gate
 * '<S13>'  : VisionModel/Blob_Analysis/Blob Extraction
 * '<S14>'  : VisionModel/Blob_Analysis/IterativeSegmentation
 * '<S15>'  : VisionModel/Blob_Analysis/Segmented Image
 * '<S16>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Low Pass Filter
 * '<S17>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Segmentation
 * '<S18>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S19>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S20>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S21>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S22>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S23>'  : VisionModel/Blob_Analysis/IterativeSegmentation/Segmentation/Resize
 * '<S24>'  : VisionModel/Blob_Analysis/Segmented Image/Display Image
 * '<S25>'  : VisionModel/Blob_Analysis1/Blob Extraction
 * '<S26>'  : VisionModel/Blob_Analysis1/IterativeSegmentation
 * '<S27>'  : VisionModel/Blob_Analysis1/Segmented Image
 * '<S28>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Low Pass Filter
 * '<S29>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Segmentation
 * '<S30>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S31>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S32>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S33>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S34>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S35>'  : VisionModel/Blob_Analysis1/IterativeSegmentation/Segmentation/Resize
 * '<S36>'  : VisionModel/Blob_Analysis1/Segmented Image/Display Image
 * '<S37>'  : VisionModel/ColorSelect/L_detector
 * '<S38>'  : VisionModel/ColorSelect/buoy_detector
 * '<S39>'  : VisionModel/ColorSelect/drop_mech
 * '<S40>'  : VisionModel/ColorSelect/path_detector
 * '<S41>'  : VisionModel/ColorSelect/torpedo
 * '<S42>'  : VisionModel/ColorSelect/validation_gate
 * '<S43>'  : VisionModel/L_detector/Identify L-Obstacle
 * '<S44>'  : VisionModel/L_detector/If Action Subsystem
 * '<S45>'  : VisionModel/L_detector/If Action Subsystem/Transform Coordinates3
 * '<S46>'  : VisionModel/buoy_detector/Choose_Buoy
 * '<S47>'  : VisionModel/buoy_detector/If Action Subsystem
 * '<S48>'  : VisionModel/buoy_detector/Shape_Analysis
 * '<S49>'  : VisionModel/buoy_detector/If Action Subsystem/Transform Coordinates3
 * '<S50>'  : VisionModel/path_detector/Identify Path Elements
 * '<S51>'  : VisionModel/path_detector/Identify Path Elements1
 * '<S52>'  : VisionModel/torpedo/Analyze LabelMatrix for Targets
 * '<S53>'  : VisionModel/torpedo/Decide which target to follow
 * '<S54>'  : VisionModel/torpedo/If Action Subsystem
 * '<S55>'  : VisionModel/torpedo/If Action Subsystem/Transform Coordinates3
 * '<S56>'  : VisionModel/validation_gate/Identify Validation Gate
 * '<S57>'  : VisionModel/validation_gate/If Action Subsystem
 * '<S58>'  : VisionModel/validation_gate/If Action Subsystem/Transform Coordinates3
 */
#endif                                 /* RTW_HEADER_VisionModel_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
