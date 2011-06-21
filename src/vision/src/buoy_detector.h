/*
 * File: buoy_detector.h
 *
 * Real-Time Workshop code generated for Simulink model buoy_detector.
 *
 * Model version                        : 1.650
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Mon Jun 20 21:17:26 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Mon Jun 20 21:17:26 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_buoy_detector_h_
#define RTW_HEADER_buoy_detector_h_
#ifndef buoy_detector_COMMON_INCLUDES_
# define buoy_detector_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_shared_utils.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_pow_snf.h"
#endif                                 /* buoy_detector_COMMON_INCLUDES_ */

#include "buoy_detector_types.h"

/* Block signals for system '<S4>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S4>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_buoy_detector;

/* Block signals for model 'buoy_detector' */
typedef struct {
  real_T ColorSpaceConversion1_o1[19200];/* '<S1>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S1>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S1>/Color Space  Conversion1' */
  real_T Resize[4800];                 /* '<S11>/Resize' */
  real_T Resize1[4800];                /* '<S11>/Resize1' */
  real_T Resize2[4800];                /* '<S11>/Resize2' */
  uint32_T LabelMatrix_m[4800];
  boolean_T LogicMatrix[19200];
  real_T blob_count;                   /* '<S2>/Blob Extraction' */
  real_T blob_hues[150];               /* '<S2>/Blob Extraction' */
  real_T blob_centroids[100];          /* '<S2>/Blob Extraction' */
  real_T blob_eccentricity[50];        /* '<S2>/Blob Extraction' */
  real_T blob_extent[50];              /* '<S2>/Blob Extraction' */
  real_T ref_colors[150];              /* '<S5>/Reference Color Selection' */
  real_T num_colors;                   /* '<S5>/Reference Color Selection' */
  real_T LabelMatrix[19200];           /* '<S5>/LabSegmentation' */
  rtB_LowPassFilter_buoy_detector sf_LowPassFilter2;/* '<S4>/Low Pass Filter2' */
  rtB_LowPassFilter_buoy_detector sf_LowPassFilter1;/* '<S4>/Low Pass Filter1' */
  rtB_LowPassFilter_buoy_detector sf_LowPassFilter;/* '<S4>/Low Pass Filter' */
} rtB_mr_buoy_detector;

/* Block states (auto storage) for model 'buoy_detector' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S1>/Color Space  Conversion1' */
  real_T Resize_IntBuffer[12800];      /* '<S11>/Resize' */
  real_T Resize1_IntBuffer[12800];     /* '<S11>/Resize1' */
  real_T Resize2_IntBuffer[12800];     /* '<S11>/Resize2' */
  real_T SuccessiveValidImageCount_Previ;/* '<Root>/Successive Valid Image Count' */
  real_T F0_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F1_RTP;                       /* '<S2>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S2>/Blob Extraction' */
  int32_T WALKER_RTP[8];               /* '<S2>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S2>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S2>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S2>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S2>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S2>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S2>/Blob Extraction' */
} rtDW_mr_buoy_detector;

/* Real-time Model Data Structure */
struct RT_MODEL_buoy_detector {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_buoy_detector rtb;
  rtDW_mr_buoy_detector rtdw;
  RT_MODEL_buoy_detector rtm;
} rtMdlrefDWork_mr_buoy_detector;

/* Exported functions */

/* Exported functions */

/* Model reference registration function */
extern void mr_buoy_detector_initialize(const char_T **rt_errorStatus,
  RT_MODEL_buoy_detector *const buoy_detector_M, rtB_mr_buoy_detector *localB,
  rtDW_mr_buoy_detector *localDW);
extern void buoy_detector_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_buoy_detector *localB);
extern void mr_buoy_detector_Init(rtDW_mr_buoy_detector *localDW);
extern void mr_buoy_detector(const real_T rtu_R_forward_in[19200], const real_T
  rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_NumberofBuoys, rtB_mr_buoy_detector *localB, rtDW_mr_buoy_detector
  *localDW);

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
 * '<Root>' : buoy_detector
 * '<S1>'   : buoy_detector/IterativeSegmentation
 * '<S2>'   : buoy_detector/Look for Buoys
 * '<S3>'   : buoy_detector/IterativeSegmentation/Embedded MATLAB Function1
 * '<S4>'   : buoy_detector/IterativeSegmentation/Low Pass Filter
 * '<S5>'   : buoy_detector/IterativeSegmentation/Segmentation
 * '<S6>'   : buoy_detector/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S7>'   : buoy_detector/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S8>'   : buoy_detector/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S9>'   : buoy_detector/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S10>'  : buoy_detector/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S11>'  : buoy_detector/IterativeSegmentation/Segmentation/Resize
 * '<S12>'  : buoy_detector/Look for Buoys/Analyze LabelMatrix for Buoys
 * '<S13>'  : buoy_detector/Look for Buoys/Blob Extraction
 */
#endif                                 /* RTW_HEADER_buoy_detector_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
