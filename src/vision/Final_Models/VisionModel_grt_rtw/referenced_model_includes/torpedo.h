/*
 * Real-Time Workshop code generation for Simulink model 'torpedo'
 * For more details, see corresponding source file torpedo.c
 *
 */
#ifndef RTW_HEADER_torpedo_h_
#define RTW_HEADER_torpedo_h_
#ifndef torpedo_COMMON_INCLUDES_
# define torpedo_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rtw_shared_utils.h"
#include "rt_nonfinite.h"
#include "rt_pow_snf.h"
#endif                                 /* torpedo_COMMON_INCLUDES_ */

#include "torpedo_types.h"

/* Block signals for system '<S4>/Low Pass Filter' */
typedef struct {
  real_T Iout[19200];                  /* '<S4>/Low Pass Filter' */
  real_T Itemp[18644];
} rtB_LowPassFilter_torpedo;

/* Block signals for model 'torpedo' */
typedef struct {
  real_T ColorSpaceConversion1_o1[19200];/* '<S2>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o2[19200];/* '<S2>/Color Space  Conversion1' */
  real_T ColorSpaceConversion1_o3[19200];/* '<S2>/Color Space  Conversion1' */
  real_T Resize[4800];                 /* '<S11>/Resize' */
  real_T Resize1[4800];                /* '<S11>/Resize1' */
  real_T Resize2[4800];                /* '<S11>/Resize2' */
  uint32_T LabelMatrix_m[4800];
  boolean_T LogicMatrix[19200];
  real_T blob_count;                   /* '<S3>/Blob Extraction' */
  real_T blob_hues[150];               /* '<S3>/Blob Extraction' */
  real_T blob_centroids[100];          /* '<S3>/Blob Extraction' */
  real_T blob_eccentricity[50];        /* '<S3>/Blob Extraction' */
  real_T blob_extent[50];              /* '<S3>/Blob Extraction' */
  real_T ref_colors[150];              /* '<S5>/Reference Color Selection' */
  real_T num_colors;                   /* '<S5>/Reference Color Selection' */
  real_T LabelMatrix[19200];           /* '<S5>/LabSegmentation' */
  rtB_LowPassFilter_torpedo sf_LowPassFilter2;/* '<S4>/Low Pass Filter2' */
  rtB_LowPassFilter_torpedo sf_LowPassFilter1;/* '<S4>/Low Pass Filter1' */
  rtB_LowPassFilter_torpedo sf_LowPassFilter;/* '<S4>/Low Pass Filter' */
} rtB_mr_torpedo;

/* Block states (auto storage) for model 'torpedo' */
typedef struct {
  real_T ColorSpaceConversion1_DWORK1[19200];/* '<S2>/Color Space  Conversion1' */
  real_T Resize_IntBuffer[9600];       /* '<S11>/Resize' */
  real_T Resize1_IntBuffer[9600];      /* '<S11>/Resize1' */
  real_T Resize2_IntBuffer[9600];      /* '<S11>/Resize2' */
  real_T F0_RTP;                       /* '<S3>/Blob Extraction' */
  real_T F1_RTP;                       /* '<S3>/Blob Extraction' */
  real_T F2_RTP;                       /* '<S3>/Blob Extraction' */
  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S3>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S3>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace3_PWORK;                /* '<S3>/To Workspace3' */

  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<S3>/To Workspace4' */

  int32_T WALKER_RTP[8];               /* '<S3>/Blob Extraction' */
  uint32_T MINAREA_RTP;                /* '<S3>/Blob Extraction' */
  uint32_T NUM_PIX_DW[50];             /* '<S3>/Blob Extraction' */
  uint32_T STACK_DW[19200];            /* '<S3>/Blob Extraction' */
  int16_T N_PIXLIST_DW[19200];         /* '<S3>/Blob Extraction' */
  int16_T M_PIXLIST_DW[19200];         /* '<S3>/Blob Extraction' */
  uint8_T PAD_DW[19764];               /* '<S3>/Blob Extraction' */
} rtDW_mr_torpedo;

/* Invariant block signals for model 'torpedo' */
typedef const struct tag_rtC_mr_torpedo {
  real_T TmpSignalConversionAtTarget;
  real_T TmpSignalConversionAtTarg_i;
  real_T TmpSignalConversionAtMainta;
} rtC_mr_torpedo;

/* Real-time Model Data Structure */
struct RT_MODEL_torpedo {
  const char_T **errorStatus;
};

typedef struct {
  rtB_mr_torpedo rtb;
  rtDW_mr_torpedo rtdw;
  RT_MODEL_torpedo rtm;
} rtMdlrefDWork_mr_torpedo;

/* Exported functions */

/* Exported functions */

/* Model reference registration function */
extern void mr_torpedo_initialize(boolean_T firstTime, const char_T
  **rt_errorStatus, RT_MODEL_torpedo *const torpedo_M, rtB_mr_torpedo *localB,
  rtDW_mr_torpedo *localDW);
extern void torpedo_LowPassFilter(const real_T rtu_I[19200],
  rtB_LowPassFilter_torpedo *localB);
extern void mr_torpedo_Init(rtDW_mr_torpedo *localDW);
extern void mr_torpedo(const real_T rtu_R_forward_in[19200], const real_T
  rtu_G_forward_in[19200], const real_T rtu_B_forward_in[19200], real_T
  *rty_TargetY, real_T *rty_TargetZ, real_T *rty_TargetYaw, real_T
  *rty_TargetDetected, real_T *rty_FireAuthorization, rtB_mr_torpedo *localB,
  rtDW_mr_torpedo *localDW);

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
 * '<Root>' : torpedo
 * '<S1>'   : torpedo/Decide which target to follow
 * '<S2>'   : torpedo/IterativeSegmentation
 * '<S3>'   : torpedo/Look for Targets
 * '<S4>'   : torpedo/IterativeSegmentation/Low Pass Filter
 * '<S5>'   : torpedo/IterativeSegmentation/Segmentation
 * '<S6>'   : torpedo/IterativeSegmentation/Low Pass Filter/Low Pass Filter
 * '<S7>'   : torpedo/IterativeSegmentation/Low Pass Filter/Low Pass Filter1
 * '<S8>'   : torpedo/IterativeSegmentation/Low Pass Filter/Low Pass Filter2
 * '<S9>'   : torpedo/IterativeSegmentation/Segmentation/LabSegmentation
 * '<S10>'  : torpedo/IterativeSegmentation/Segmentation/Reference Color Selection
 * '<S11>'  : torpedo/IterativeSegmentation/Segmentation/Resize
 * '<S12>'  : torpedo/Look for Targets/Analyze LabelMatrix for Targets
 * '<S13>'  : torpedo/Look for Targets/Blob Extraction
 */
#endif                                 /* RTW_HEADER_torpedo_h_ */
