#ifndef __c1_brain_h__
#define __c1_brain_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c1_ResolvedFunctionInfo;

typedef struct {
  real_T c1_Area;
  real_T c1_BuoyCount;
  real_T c1_BuoyDone;
  real_T c1_CentroidX;
  real_T c1_CentroidY;
  real_T c1_DesiredHeadingCount;
  real_T c1_ErrorCount;
  real_T c1_ErrorCountHeading;
  real_T c1_ErrorCountX;
  real_T c1_ErrorCountY;
  real_T c1_ErrorHeading;
  real_T c1_ErrorX;
  real_T c1_ErrorY;
  real_T c1_Flag;
  real_T c1_Obstacle;
  real_T c1_OldHeading;
  real_T c1_OldObstacle;
  real_T c1_ResetSwitch;
  real_T c1_TrackCount;
  real_T c1_count;
  real_T c1_countarea;
  real_T c1_track1;
  SimStruct *S;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_testPointAddrMap[34];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_FollowTrack;
  uint8_T c1_is_Running;
  uint8_T c1_is_active_c1_brain;
  uint8_T c1_is_c1_brain;
  uint8_T c1_tp_Buoy;
  uint8_T c1_tp_ChooseState;
  uint8_T c1_tp_FindBuoy;
  uint8_T c1_tp_Finish;
  uint8_T c1_tp_FollowTrack;
  uint8_T c1_tp_NotRunning;
  uint8_T c1_tp_Running;
  uint8_T c1_tp_Stage1Aim;
  uint8_T c1_tp_Stage2Position;
  uint8_T c1_tp_Stage3ReOrient;
  uint8_T c1_tp_Start;
  uint8_T c1_tp_ValidationGate;
  ChartInfoStruct chartInfo;
  rtwCAPI_ModelMappingInfo c1_testPointMappingInfo;
} SFc1_brainInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c1_brain_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_brain_get_check_sum(mxArray *plhs[]);
extern void c1_brain_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
