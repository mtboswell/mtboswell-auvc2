/*
 * File: path_detector.h
 *
 * Real-Time Workshop code generated for Simulink model path_detector.
 *
 * Model version                        : 1.365
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Jun 28 18:13:07 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Jun 28 18:13:08 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_path_detector_h_
#define RTW_HEADER_path_detector_h_
#ifndef path_detector_COMMON_INCLUDES_
# define path_detector_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#include "rtw_shared_utils.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_pow_snf.h"
#endif                                 /* path_detector_COMMON_INCLUDES_ */

#include "path_detector_types.h"

/* Block signals for system '<S8>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S8>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_path_detector;

/* Block signals for model 'path_detector' */
typedef struct {
  real_T hough_table[71820];
  real_T ColorSpaceConversion1_o1[19200];/* '<S7>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S7>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S7>/Color Space  Conversion1' */
  real_T bw_image[19200];              /* '<S1>/Filter Image' */
  real_T L[19200];                     /* '<S1>/Filter Image1' */
  real_T a[19200];                     /* '<S1>/Filter Image1' */
  real_T b[19200];                     /* '<S1>/Filter Image1' */
  real_T Resize[4800];                 /* '<S15>/Resize' */
  real_T Resize1[4800];                /* '<S15>/Resize1' */
  real_T Resize2[4800];                /* '<S15>/Resize2' */
  uint32_T LabelMatrix[4800];
  boolean_T LogicMatrix[19200];
  real_T HoughTransform1_o2[180];      /* '<Root>/Hough Transform1' */
  real_T HoughTransform1_o3[399];      /* '<Root>/Hough Transform1' */
  real_T ColorSpaceConversion3_o1[19200];/* '<Root>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o2[19200];/* '<Root>/Color Space  Conversion3' */
  real_T ColorSpaceConversion3_o3[19200];/* '<Root>/Color Space  Conversion3' */
  int32_T HoughLines2[800];            /* '<Root>/Hough Lines2' */
  boolean_T EdgeDetection[19200];      /* '<Root>/Edge Detection' */
  rtB_LowPassFilter_path_detector sf_LowPassFilter2;/* '<S8>/Low Pass Filter2' */
  rtB_LowPassFilter_path_detector sf_LowPassFilter1;/* '<S8>/Low Pass Filter1' */
  rtB_LowPassFilter_path_detector sf_LowPassFilter;/* '<S8>/Low Pass Filter' */
} rtB_mr_path_detector;

/* Block states (auto storage) for model 'path_detector' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S7>/Color Space  Conversion1' */
  real_T ColorSpaceConversion3_DWORK1[19200];/* '<Root>/Color Space  Conversion3' */
  real_T EdgeDetection_GV_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GH_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_GRAD_SUM_DW[19200];/* '<Root>/Edge Detection' */
  real_T EdgeDetection_MEAN_FACTOR_DW; /* '<Root>/Edge Detection' */
  real_T F1_RTP;                       /* '<S1>/Blob Extraction' */
  real_T F3_RTP;                       /* '<S1>/Blob Extraction' */
  real_T F4_RTP;                       /* '<S1>/Blob Extraction' */
  real_T F5_RTP;                       /* '<S1>/Blob Extraction' */
  real_T F6_RTP;                       /* '<S1>/Blob Extraction' */
  real_T F7_RTP;                       /* '<S1>/Blob Extraction' */
  int32_T EdgeDetection_VO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T WALKER_RTP[8];               /* '<S1>/Blob Extraction' */
  int32_T F0_RTP;                      /* '<S1>/Blob Extraction' */
  int32_T F2_RTP;                      /* '<S1>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S1>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S1>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S1>/Blob Extraction' */
  real_T Resize_IntBuffer[9600];       /* '<S15>/Resize' */
  real_T Resize1_IntBuffer[9600];      /* '<S15>/Resize1' */
  real_T Resize2_IntBuffer[9600];      /* '<S15>/Resize2' */
  int16_T N_PIXLIST_DW[19200];         /* '<S1>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S1>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S1>/Blob Extraction' */
} rtDW_mr_path_detector;

/* Real-time Model Data Structure */
struct RT_MODEL_path_detector {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_path_detector rtb;
  rtDW_mr_path_detector rtdw;
  RT_MODEL_path_detector rtm;
} rtMdlrefDWork_mr_path_detector;

/* Exported functions */

/* Exported functions */

/* Model reference registration function */
extern void mr_path_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_path_detector *const path_detector_M, rtB_mr_path_detector *localB,
  rtDW_mr_path_detector *localDW);
extern void path_detector_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_path_detector *localB);
extern void mr_path_detector_Init(rtDW_mr_path_detector *localDW);
extern void mr_path_detector(const real_T rtu_R_in[19200], const real_T
  rtu_G_in[19200], const real_T rtu_B_in[19200], const real_T *rtu_WhichPath,
  real_T *rty_TargetSelect, real_T *rty_TargetFound, real_T *rty_MaintainHeading,
  real_T *rty_TargetX, real_T *rty_TargetY, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, real_T *rty_PathState, real_T rty_R[19200], real_T rty_G
  [19200], real_T rty_B[19200], real_T rty_bw_image[19200], real_T
  rty_edge_image[19200], real_T rty_line_image[19200], real_T rty_hough_table
  [71820], real_T *rty_BlobCount, real_T rty_BlobHues[150], real_T rty_Area[50],
  real_T rty_BBox[200], real_T rty_Centroid[100], real_T rty_Eccentricity[50],
  real_T rty_Extent[50], real_T rty_Orientation[50], real_T rty_path_headings[3],
  real_T rty_MajorAxis[50], real_T rty_MinorAxis[50], real_T rty_ref_colors[150],
  real_T rty_theta[200], real_T rty_rho[200], real_T rty_debug_orientation[50],
  real_T rty_LabelMatrix[19200], real_T *rty_num_colors, rtB_mr_path_detector
  *localB, rtDW_mr_path_detector *localDW);

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
 * '<Root>' : path_detector
 * '<S1>'   : path_detector/Blob Analysis
 * '<S2>'   : path_detector/Identify Path Elements
 * '<S3>'   : path_detector/Identify Path Elements1
 * '<S4>'   : path_detector/Blob Analysis/Blob Extraction
 * '<S5>'   : path_detector/Blob Analysis/Filter Image
 * '<S6>'   : path_detector/Blob Analysis/Filter Image1
 * '<S7>'   : path_detector/Blob Analysis/IterativeSegmentation
 * '<S8>'   : path_detector/Blob Analysis/IterativeSegmentation/Low Pass Filter
 * '<S9>'   : path_detector/Blob Analysis/IterativeSegmentation/Segmentation
 * '<S10>'  : path_detector/Blob Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S11>'  : path_detector/Blob Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S12>'  : path_detector/Blob Analysis/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S13>'  : path_detector/Blob Analysis/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S14>'  : path_detector/Blob Analysis/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S15>'  : path_detector/Blob Analysis/IterativeSegmentation/Segmentation/Resize
 */
#endif                                 /* RTW_HEADER_path_detector_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
