/* Include files */

#include "blascompat32.h"
#include "brain_sfun.h"
#include "c1_brain.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "brain_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0)
#define c1_IN_ValidationGate           (7)
#define c1_IN_Buoy                     (1)
#define c1_IN_Start                    (6)
#define c1_IN_Finish                   (4)
#define c1_IN_FollowTrack              (5)
#define c1_IN_Stage1Aim                (1)
#define c1_IN_Stage2Position           (2)
#define c1_IN_FindBuoy                 (3)
#define c1_IN_Stage3ReOrient           (3)
#define c1_IN_Running                  (2)
#define c1_IN_NotRunning               (1)
#define c1_IN_ChooseState              (2)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_brainInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_brain(void);
static void initialize_params_c1_brain(void);
static void enable_c1_brain(void);
static void disable_c1_brain(void);
static void c1_update_debugger_state_c1_brain(void);
static const mxArray *get_sim_state_c1_brain(void);
static void set_sim_state_c1_brain(const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_brain(void);
static void finalize_c1_brain(void);
static void sf_c1_brain(void);
static void c1_enter_atomic_ValidationGate(void);
static void c1_ValidationGate(void);
static void c1_Buoy(void);
static void c1_FollowTrack(void);
static void c1_exit_internal_FollowTrack(void);
static void c1_TrackStage1(real_T c1_CurrentHeading, real32_T c1_DesiredDepth,
  real32_T c1_CurrentDepth, real_T c1_H[307200], real_T c1_S[307200], real_T
  *c1_DesiredHeading, int8_T *c1_ChangetoRight, int8_T *c1_ChangetoLeft, int8_T *
  c1_ChangetoVertical, real_T *c1_b_ErrorX);
static real_T c1_ErrorCounter(real_T c1_ErrorX5, real_T c1_ErrorCountX5);
static void c1_enter_atomic_FindBuoy(void);
static void c1_FindBuoy(void);
static void c1_DirectionalControl(real32_T c1_CurrentDepth, real32_T
  c1_DesiredDepth, real_T c1_DesiredHeading, real_T c1_CurrentHeading, int8_T
  *c1_ChangetoVertical, int8_T *c1_ChangetoLeft, int8_T *c1_ChangetoRight,
  real_T *c1_ErrorHeading1);
static real_T c1_b_ErrorCounter(real_T c1_ErrorX5, real_T c1_ErrorCountX5);
static void c1_Running(void);
static void c1_ChooseState(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_emlrt_marshallOut(int8_T c1_u);
static const mxArray *c1_b_emlrt_marshallOut(uint8_T c1_u);
static real_T c1_emlrt_marshallIn(const mxArray *c1_BuoyCentroidX, char *c1_name);
static real_T c1_b_emlrt_marshallIn(const mxArray *c1_BuoyCentroidY, char
  *c1_name);
static int8_T c1_c_emlrt_marshallIn(const mxArray *c1_CameraPosition, char
  *c1_name);
static real_T c1_d_emlrt_marshallIn(const mxArray *c1_DesiredDepth, char
  *c1_name);
static real_T c1_e_emlrt_marshallIn(const mxArray *c1_DesiredHeading, char
  *c1_name);
static int8_T c1_f_emlrt_marshallIn(const mxArray *c1_Left, char *c1_name);
static int8_T c1_g_emlrt_marshallIn(const mxArray *c1_Right, char *c1_name);
static uint8_T c1_h_emlrt_marshallIn(const mxArray *c1_State, char *c1_name);
static int8_T c1_i_emlrt_marshallIn(const mxArray *c1_Vertical, char *c1_name);
static real_T c1_j_emlrt_marshallIn(const mxArray *c1_b_Area, char *c1_name);
static real_T c1_k_emlrt_marshallIn(const mxArray *c1_b_BuoyCount, char *c1_name);
static real_T c1_l_emlrt_marshallIn(const mxArray *c1_b_BuoyDone, char *c1_name);
static real_T c1_m_emlrt_marshallIn(const mxArray *c1_b_CentroidX, char *c1_name);
static real_T c1_n_emlrt_marshallIn(const mxArray *c1_b_CentroidY, char *c1_name);
static real_T c1_o_emlrt_marshallIn(const mxArray *c1_b_DesiredHeadingCount,
  char *c1_name);
static real_T c1_p_emlrt_marshallIn(const mxArray *c1_b_ErrorCount, char
  *c1_name);
static real_T c1_q_emlrt_marshallIn(const mxArray *c1_b_ErrorCountHeading, char *
  c1_name);
static real_T c1_r_emlrt_marshallIn(const mxArray *c1_b_ErrorCountX, char
  *c1_name);
static real_T c1_s_emlrt_marshallIn(const mxArray *c1_b_ErrorCountY, char
  *c1_name);
static real_T c1_t_emlrt_marshallIn(const mxArray *c1_b_ErrorHeading, char
  *c1_name);
static real_T c1_u_emlrt_marshallIn(const mxArray *c1_b_ErrorX, char *c1_name);
static real_T c1_v_emlrt_marshallIn(const mxArray *c1_b_ErrorY, char *c1_name);
static real_T c1_w_emlrt_marshallIn(const mxArray *c1_b_Flag, char *c1_name);
static real_T c1_x_emlrt_marshallIn(const mxArray *c1_b_Obstacle, char *c1_name);
static real_T c1_y_emlrt_marshallIn(const mxArray *c1_b_OldHeading, char
  *c1_name);
static real_T c1_ab_emlrt_marshallIn(const mxArray *c1_b_OldObstacle, char
  *c1_name);
static real_T c1_bb_emlrt_marshallIn(const mxArray *c1_b_ResetSwitch, char
  *c1_name);
static real_T c1_cb_emlrt_marshallIn(const mxArray *c1_b_TrackCount, char
  *c1_name);
static real_T c1_db_emlrt_marshallIn(const mxArray *c1_b_count, char *c1_name);
static real_T c1_eb_emlrt_marshallIn(const mxArray *c1_b_countarea, char
  *c1_name);
static real_T c1_fb_emlrt_marshallIn(const mxArray *c1_b_track1, char *c1_name);
static uint8_T c1_gb_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_brain,
  char *c1_name);
static uint8_T c1_hb_emlrt_marshallIn(const mxArray *c1_b_is_c1_brain, char
  *c1_name);
static uint8_T c1_ib_emlrt_marshallIn(const mxArray *c1_b_is_FollowTrack, char
  *c1_name);
static uint8_T c1_jb_emlrt_marshallIn(const mxArray *c1_b_is_Running, char
  *c1_name);
static const mxArray *c1_kb_emlrt_marshallIn(const mxArray
  *c1_b_setSimStateSideEffectsInfo, char *c1_name);
static int8_T c1__s8_d_(real_T c1_b);
static void init_test_point_addr_map(void);
static void **get_test_point_address_map(void);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_brain(void)
{
  int8_T *c1_Right;
  int8_T *c1_Left;
  int8_T *c1_Vertical;
  real_T *c1_DesiredDepth;
  real_T *c1_DesiredHeading;
  int8_T *c1_CameraPosition;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  uint8_T *c1_State;
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_doSetSimStateSideEffects = 0U;
  chartInstance.c1_setSimStateSideEffectsInfo = NULL;
  chartInstance.c1_tp_NotRunning = 0U;
  chartInstance.c1_is_Running = 0U;
  chartInstance.c1_tp_Running = 0U;
  chartInstance.c1_tp_Buoy = 0U;
  chartInstance.c1_tp_ChooseState = 0U;
  chartInstance.c1_tp_FindBuoy = 0U;
  chartInstance.c1_tp_Finish = 0U;
  chartInstance.c1_is_FollowTrack = 0U;
  chartInstance.c1_tp_FollowTrack = 0U;
  chartInstance.c1_tp_Stage1Aim = 0U;
  chartInstance.c1_tp_Stage2Position = 0U;
  chartInstance.c1_tp_Stage3ReOrient = 0U;
  chartInstance.c1_tp_Start = 0U;
  chartInstance.c1_tp_ValidationGate = 0U;
  chartInstance.c1_is_active_c1_brain = 0U;
  chartInstance.c1_is_c1_brain = 0U;
  chartInstance.c1_count = 0.0;
  chartInstance.c1_Obstacle = 0.0;
  chartInstance.c1_OldObstacle = 0.0;
  chartInstance.c1_Area = 0.0;
  chartInstance.c1_BuoyDone = 0.0;
  chartInstance.c1_countarea = 0.0;
  chartInstance.c1_ErrorX = 0.0;
  chartInstance.c1_Flag = 0.0;
  chartInstance.c1_track1 = 0.0;
  chartInstance.c1_ErrorY = 0.0;
  chartInstance.c1_DesiredHeadingCount = 0.0;
  chartInstance.c1_OldHeading = 0.0;
  chartInstance.c1_ResetSwitch = 0.0;
  chartInstance.c1_CentroidX = 0.0;
  chartInstance.c1_CentroidY = 0.0;
  chartInstance.c1_TrackCount = 0.0;
  chartInstance.c1_BuoyCount = 0.0;
  chartInstance.c1_ErrorCount = 0.0;
  chartInstance.c1_ErrorCountHeading = 0.0;
  chartInstance.c1_ErrorCountX = 0.0;
  chartInstance.c1_ErrorCountY = 0.0;
  chartInstance.c1_ErrorHeading = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c1_Right = 0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c1_Left = 0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 3) != 0)) {
    *c1_Vertical = 0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 4) != 0)) {
    *c1_DesiredDepth = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 5) != 0)) {
    *c1_DesiredHeading = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 6) != 0)) {
    *c1_CameraPosition = 0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 7) != 0)) {
    *c1_BuoyCentroidX = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 8) != 0)) {
    *c1_BuoyCentroidY = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 9) != 0)) {
    *c1_State = 0U;
  }
}

static void initialize_params_c1_brain(void)
{
}

static void enable_c1_brain(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_brain(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c1_update_debugger_state_c1_brain(void)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (chartInstance.c1_is_active_c1_brain == 1) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
  }

  if (chartInstance.c1_is_Running == c1_IN_ValidationGate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
  }

  if (chartInstance.c1_is_Running == c1_IN_Buoy) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
  }

  if (chartInstance.c1_is_Running == c1_IN_Start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
  }

  if (chartInstance.c1_is_Running == c1_IN_Finish) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
  }

  if (chartInstance.c1_is_Running == c1_IN_FollowTrack) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
  }

  if (chartInstance.c1_is_FollowTrack == c1_IN_Stage1Aim) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
  }

  if (chartInstance.c1_is_FollowTrack == c1_IN_Stage2Position) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
  }

  if (chartInstance.c1_is_Running == c1_IN_FindBuoy) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
  }

  if (chartInstance.c1_is_FollowTrack == c1_IN_Stage3ReOrient) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,19);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,19);
  }

  if (chartInstance.c1_is_c1_brain == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
  }

  if (chartInstance.c1_is_c1_brain == c1_IN_NotRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
  }

  if (chartInstance.c1_is_Running == c1_IN_ChooseState) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_brain(void)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  real_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T c1_p_u;
  const mxArray *c1_q_y = NULL;
  real_T c1_q_u;
  const mxArray *c1_r_y = NULL;
  real_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  real_T c1_s_u;
  const mxArray *c1_t_y = NULL;
  real_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  real_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  real_T c1_v_u;
  const mxArray *c1_w_y = NULL;
  real_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  real_T c1_x_u;
  const mxArray *c1_y_y = NULL;
  real_T c1_y_u;
  const mxArray *c1_ab_y = NULL;
  real_T c1_ab_u;
  const mxArray *c1_bb_y = NULL;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  int8_T *c1_CameraPosition;
  real_T *c1_DesiredDepth;
  real_T *c1_DesiredHeading;
  int8_T *c1_Left;
  int8_T *c1_Right;
  uint8_T *c1_State;
  int8_T *c1_Vertical;
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(35));
  c1_u = *c1_BuoyCentroidX;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = *c1_BuoyCentroidY;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_setcell(c1_y, 2, c1_emlrt_marshallOut(*c1_CameraPosition));
  c1_c_u = *c1_DesiredDepth;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_d_y);
  c1_d_u = *c1_DesiredHeading;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 4, c1_e_y);
  sf_mex_setcell(c1_y, 5, c1_emlrt_marshallOut(*c1_Left));
  sf_mex_setcell(c1_y, 6, c1_emlrt_marshallOut(*c1_Right));
  sf_mex_setcell(c1_y, 7, c1_b_emlrt_marshallOut(*c1_State));
  sf_mex_setcell(c1_y, 8, c1_emlrt_marshallOut(*c1_Vertical));
  c1_e_u = chartInstance.c1_Area;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 9, c1_f_y);
  c1_f_u = chartInstance.c1_BuoyCount;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 10, c1_g_y);
  c1_g_u = chartInstance.c1_BuoyDone;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 11, c1_h_y);
  c1_h_u = chartInstance.c1_CentroidX;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 12, c1_i_y);
  c1_i_u = chartInstance.c1_CentroidY;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 13, c1_j_y);
  c1_j_u = chartInstance.c1_DesiredHeadingCount;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 14, c1_k_y);
  c1_k_u = chartInstance.c1_ErrorCount;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 15, c1_l_y);
  c1_l_u = chartInstance.c1_ErrorCountHeading;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 16, c1_m_y);
  c1_m_u = chartInstance.c1_ErrorCountX;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 17, c1_n_y);
  c1_n_u = chartInstance.c1_ErrorCountY;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 18, c1_o_y);
  c1_o_u = chartInstance.c1_ErrorHeading;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 19, c1_p_y);
  c1_p_u = chartInstance.c1_ErrorX;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_p_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 20, c1_q_y);
  c1_q_u = chartInstance.c1_ErrorY;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_q_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 21, c1_r_y);
  c1_r_u = chartInstance.c1_Flag;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 22, c1_s_y);
  c1_s_u = chartInstance.c1_Obstacle;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_s_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 23, c1_t_y);
  c1_t_u = chartInstance.c1_OldHeading;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 24, c1_u_y);
  c1_u_u = chartInstance.c1_OldObstacle;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_u_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 25, c1_v_y);
  c1_v_u = chartInstance.c1_ResetSwitch;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_v_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 26, c1_w_y);
  c1_w_u = chartInstance.c1_TrackCount;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 27, c1_x_y);
  c1_x_u = chartInstance.c1_count;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_x_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 28, c1_y_y);
  c1_y_u = chartInstance.c1_countarea;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_create("y", &c1_y_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 29, c1_ab_y);
  c1_ab_u = chartInstance.c1_track1;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_ab_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 30, c1_bb_y);
  sf_mex_setcell(c1_y, 31, c1_b_emlrt_marshallOut
                 (chartInstance.c1_is_active_c1_brain));
  sf_mex_setcell(c1_y, 32, c1_b_emlrt_marshallOut(chartInstance.c1_is_c1_brain));
  sf_mex_setcell(c1_y, 33, c1_b_emlrt_marshallOut
                 (chartInstance.c1_is_FollowTrack));
  sf_mex_setcell(c1_y, 34, c1_b_emlrt_marshallOut(chartInstance.c1_is_Running));
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_brain(const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  int8_T *c1_CameraPosition;
  real_T *c1_DesiredDepth;
  real_T *c1_DesiredHeading;
  int8_T *c1_Left;
  int8_T *c1_Right;
  uint8_T *c1_State;
  int8_T *c1_Vertical;
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_u = sf_mex_dup(c1_st);
  *c1_BuoyCentroidX = c1_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "BuoyCentroidX");
  *c1_BuoyCentroidY = c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "BuoyCentroidY");
  *c1_CameraPosition = c1_c_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "CameraPosition");
  *c1_DesiredDepth = c1_d_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "DesiredDepth");
  *c1_DesiredHeading = c1_e_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "DesiredHeading");
  *c1_Left = c1_f_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 5)), "Left");
  *c1_Right = c1_g_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 6)), "Right");
  *c1_State = c1_h_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 7)), "State");
  *c1_Vertical = c1_i_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 8)),
    "Vertical");
  chartInstance.c1_Area = c1_j_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u,
    9)), "Area");
  chartInstance.c1_BuoyCount = c1_k_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 10)), "BuoyCount");
  chartInstance.c1_BuoyDone = c1_l_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 11)), "BuoyDone");
  chartInstance.c1_CentroidX = c1_m_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 12)), "CentroidX");
  chartInstance.c1_CentroidY = c1_n_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 13)), "CentroidY");
  chartInstance.c1_DesiredHeadingCount = c1_o_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 14)), "DesiredHeadingCount");
  chartInstance.c1_ErrorCount = c1_p_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 15)), "ErrorCount");
  chartInstance.c1_ErrorCountHeading = c1_q_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 16)), "ErrorCountHeading");
  chartInstance.c1_ErrorCountX = c1_r_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 17)), "ErrorCountX");
  chartInstance.c1_ErrorCountY = c1_s_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 18)), "ErrorCountY");
  chartInstance.c1_ErrorHeading = c1_t_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 19)), "ErrorHeading");
  chartInstance.c1_ErrorX = c1_u_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u,
    20)), "ErrorX");
  chartInstance.c1_ErrorY = c1_v_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u,
    21)), "ErrorY");
  chartInstance.c1_Flag = c1_w_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u,
    22)), "Flag");
  chartInstance.c1_Obstacle = c1_x_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 23)), "Obstacle");
  chartInstance.c1_OldHeading = c1_y_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 24)), "OldHeading");
  chartInstance.c1_OldObstacle = c1_ab_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 25)), "OldObstacle");
  chartInstance.c1_ResetSwitch = c1_bb_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 26)), "ResetSwitch");
  chartInstance.c1_TrackCount = c1_cb_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 27)), "TrackCount");
  chartInstance.c1_count = c1_db_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u,
    28)), "count");
  chartInstance.c1_countarea = c1_eb_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 29)), "countarea");
  chartInstance.c1_track1 = c1_fb_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 30)), "track1");
  chartInstance.c1_is_active_c1_brain = c1_gb_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 31)), "is_active_c1_brain");
  chartInstance.c1_is_c1_brain = c1_hb_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 32)), "is_c1_brain");
  chartInstance.c1_is_FollowTrack = c1_ib_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 33)), "is_FollowTrack");
  chartInstance.c1_is_Running = c1_jb_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell
    (c1_u, 34)), "is_Running");
  sf_mex_assign(&chartInstance.c1_setSimStateSideEffectsInfo,
                c1_kb_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 35)),
    "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c1_u);
  chartInstance.c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_brain();
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_brain(void)
{
  if (chartInstance.c1_doSetSimStateSideEffects != 0) {
    if (chartInstance.c1_is_c1_brain == c1_IN_NotRunning) {
      chartInstance.c1_tp_NotRunning = 1U;
    } else {
      chartInstance.c1_tp_NotRunning = 0U;
    }

    if (chartInstance.c1_is_c1_brain == c1_IN_Running) {
      chartInstance.c1_tp_Running = 1U;
    } else {
      chartInstance.c1_tp_Running = 0U;
    }

    if (chartInstance.c1_is_Running == c1_IN_Buoy) {
      chartInstance.c1_tp_Buoy = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 2, "Buoy", 0);
      }
    } else {
      chartInstance.c1_tp_Buoy = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 2, "Buoy", 0);
      }
    }

    if (chartInstance.c1_is_Running == c1_IN_ChooseState) {
      chartInstance.c1_tp_ChooseState = 1U;
    } else {
      chartInstance.c1_tp_ChooseState = 0U;
    }

    if (chartInstance.c1_is_Running == c1_IN_FindBuoy) {
      chartInstance.c1_tp_FindBuoy = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 6, "LookforBuoy", 0);
        sf_call_output_fcn_enable(chartInstance.S, 5, "StraightLevelControl", 0);
      }
    } else {
      chartInstance.c1_tp_FindBuoy = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 6) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 6, "LookforBuoy", 0);
        sf_call_output_fcn_disable(chartInstance.S, 5, "StraightLevelControl", 0);
      }
    }

    if (chartInstance.c1_is_Running == c1_IN_Finish) {
      chartInstance.c1_tp_Finish = 1U;
    } else {
      chartInstance.c1_tp_Finish = 0U;
    }

    if (chartInstance.c1_is_Running == c1_IN_FollowTrack) {
      chartInstance.c1_tp_FollowTrack = 1U;
    } else {
      chartInstance.c1_tp_FollowTrack = 0U;
    }

    if (chartInstance.c1_is_FollowTrack == c1_IN_Stage1Aim) {
      chartInstance.c1_tp_Stage1Aim = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 3, "TrackStage1", 0);
      }
    } else {
      chartInstance.c1_tp_Stage1Aim = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 3, "TrackStage1", 0);
      }
    }

    if (chartInstance.c1_is_FollowTrack == c1_IN_Stage2Position) {
      chartInstance.c1_tp_Stage2Position = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 4, "TrackStage2", 0);
      }
    } else {
      chartInstance.c1_tp_Stage2Position = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 10) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 4, "TrackStage2", 0);
      }
    }

    if (chartInstance.c1_is_FollowTrack == c1_IN_Stage3ReOrient) {
      chartInstance.c1_tp_Stage3ReOrient = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 7, "DirectionalControl", 0);
      }
    } else {
      chartInstance.c1_tp_Stage3ReOrient = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 7, "DirectionalControl", 0);
      }
    }

    if (chartInstance.c1_is_Running == c1_IN_Start) {
      chartInstance.c1_tp_Start = 1U;
    } else {
      chartInstance.c1_tp_Start = 0U;
    }

    if (chartInstance.c1_is_Running == c1_IN_ValidationGate) {
      chartInstance.c1_tp_ValidationGate = 1U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) == 0.0) {
        sf_call_output_fcn_enable(chartInstance.S, 0, "LookforTrack", 0);
        sf_call_output_fcn_enable(chartInstance.S, 1, "StraightLevelControl", 0);
      }
    } else {
      chartInstance.c1_tp_ValidationGate = 0U;
      if (sf_mex_sub(chartInstance.c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 13) > 0.0) {
        sf_call_output_fcn_disable(chartInstance.S, 0, "LookforTrack", 0);
        sf_call_output_fcn_disable(chartInstance.S, 1, "StraightLevelControl", 0);
      }
    }

    chartInstance.c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_brain(void)
{
  sf_mex_destroy(&chartInstance.c1_setSimStateSideEffectsInfo);
}

static void sf_c1_brain(void)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  uint8_T c1_previousEvent;
  real_T *c1_CurrentDepth;
  real_T *c1_CurrentHeading;
  int8_T *c1_Right;
  int8_T *c1_Left;
  int8_T *c1_Vertical;
  real_T *c1_DesiredDepth;
  real_T *c1_DesiredHeading;
  int8_T *c1_CameraPosition;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  uint8_T *c1_State;
  int8_T *c1_Status;
  int8_T *c1_DesiredState;
  real32_T (*c1_V)[307200];
  real32_T (*c1_S)[307200];
  real32_T (*c1_H)[307200];
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_V = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 4);
  c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  c1_CurrentDepth = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_Status = (int8_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_set_sim_state_side_effects_c1_brain();
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c1_CurrentDepth, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_CurrentHeading, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_DesiredDepth, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_count, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Obstacle, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldObstacle, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_DesiredHeading, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Area, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyDone, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_countarea, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorX, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Flag, 14U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_track1, 15U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorY, 16U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_CameraPosition, 17U);
  for (c1_i0 = 0; c1_i0 < 307200; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_H)[c1_i0], 18U);
  }

  for (c1_i1 = 0; c1_i1 < 307200; c1_i1 = c1_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_S)[c1_i1], 19U);
  }

  for (c1_i2 = 0; c1_i2 < 307200; c1_i2 = c1_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_V)[c1_i2], 20U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidX, 21U);
  _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidY, 22U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_DesiredHeadingCount, 23U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldHeading, 24U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ResetSwitch, 25U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_CentroidX, 26U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_CentroidY, 27U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_TrackCount, 28U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyCount, 29U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCount, 30U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountHeading, 31U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountX, 32U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountY, 33U);
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorHeading, 34U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_Status, 36U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_DesiredState, 37U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  if (chartInstance.c1_is_active_c1_brain == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG,0);
    chartInstance.c1_is_active_c1_brain = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,0);
    chartInstance.c1_is_c1_brain = (uint8_T)c1_IN_NotRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c1_tp_NotRunning = 1U;
    *c1_Left = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
    *c1_Right = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
    *c1_Vertical = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
  } else {
    switch (chartInstance.c1_is_c1_brain) {
     case c1_IN_NotRunning:
      CV_CHART_EVAL(0,0,1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,0);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,1);
      if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1,0,((*c1_Status == 1)!=
             0))) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,1);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,0);
        chartInstance.c1_tp_NotRunning = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
        chartInstance.c1_is_c1_brain = (uint8_T)c1_IN_Running;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,1);
        chartInstance.c1_tp_Running = 1U;
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,3);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,3);
        chartInstance.c1_is_Running = (uint8_T)c1_IN_Start;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
        chartInstance.c1_tp_Start = 1U;
        chartInstance.c1_OldHeading = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldHeading, 24U);
        chartInstance.c1_DesiredHeadingCount = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_DesiredHeadingCount, 23U);
        *c1_BuoyCentroidX = 0.0;
        _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidX, 21U);
        *c1_BuoyCentroidY = 0.0;
        _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidY, 22U);
        *c1_CameraPosition = 2;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_CameraPosition, 17U);
        *c1_State = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
      break;

     case c1_IN_Running:
      CV_CHART_EVAL(0,0,2);
      c1_Running();
      break;

     default:
      CV_CHART_EVAL(0,0,0);
      chartInstance.c1_is_c1_brain = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_brainMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void c1_enter_atomic_ValidationGate(void)
{
  uint8_T *c1_State;
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  chartInstance.c1_is_Running = (uint8_T)c1_IN_ValidationGate;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,24);
  chartInstance.c1_tp_ValidationGate = 1U;
  sf_call_output_fcn_enable(chartInstance.S, 0, "LookforTrack", 0);
  sf_call_output_fcn_enable(chartInstance.S, 1, "StraightLevelControl", 0);
  chartInstance.c1_Obstacle = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Obstacle, 7U);
  chartInstance.c1_OldObstacle = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldObstacle, 8U);
  chartInstance.c1_count = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_count, 6U);
  chartInstance.c1_TrackCount = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_TrackCount, 28U);
  chartInstance.c1_Flag = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Flag, 14U);
  *c1_State = 2U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
}

static void c1_ValidationGate(void)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  int32_T c1_i3;
  static real_T c1_H[307200];
  int32_T c1_i4;
  static real_T c1_S[307200];
  real_T c1_Image;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T c1_b_Image;
  real_T c1_OldImage;
  real_T c1_count1;
  real_T c1_count2;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 3.0;
  real32_T c1_CurrentDepth;
  real32_T c1_DesiredDepth;
  real_T c1_DesiredHeading;
  real_T c1_CurrentHeading;
  int8_T c1_ChangetoRight;
  int8_T c1_ChangetoLeft;
  int8_T c1_ChangetoVertical;
  int8_T *c1_DesiredState;
  real_T *c1_b_CurrentDepth;
  real_T *c1_b_DesiredDepth;
  real_T *c1_b_DesiredHeading;
  real_T *c1_b_CurrentHeading;
  uint8_T *c1_State;
  int8_T *c1_Right;
  int8_T *c1_Left;
  int8_T *c1_Vertical;
  real32_T *c1_c_CurrentDepth;
  real32_T *c1_c_DesiredDepth;
  real_T *c1_c_DesiredHeading;
  real_T *c1_c_CurrentHeading;
  int8_T *c1_b_ChangetoVertical;
  int8_T *c1_b_ChangetoLeft;
  int8_T *c1_b_ChangetoRight;
  real_T *c1_c_Image;
  real_T (*c1_b_H)[307200];
  real_T (*c1_b_S)[307200];
  real32_T (*c1_c_S)[307200];
  real32_T (*c1_c_H)[307200];
  c1_c_DesiredDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 13);
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_c_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_b_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_b_ChangetoLeft = (int8_T *)ssGetInputPortSignal(chartInstance.S, 9);
  c1_c_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 14);
  c1_c_CurrentDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 12);
  c1_b_H = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 10);
  c1_b_S = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 11);
  c1_c_CurrentHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 15);
  c1_c_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
  c1_b_ChangetoVertical = (int8_T *)ssGetInputPortSignal(chartInstance.S, 8);
  c1_b_ChangetoRight = (int8_T *)ssGetInputPortSignal(chartInstance.S, 10);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_c_Image = (real_T *)ssGetInputPortSignal(chartInstance.S, 7);
  c1_b_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_CurrentDepth = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,24);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,20);
  c1_temp = (_SFD_CCP_CALL(20,0,((chartInstance.c1_TrackCount > 2.0)!=0)) != 0);
  if (c1_temp) {
    c1_temp = (_SFD_CCP_CALL(20,1,((*c1_DesiredState == 0)!=0)) != 0);
  }

  if (CV_TRANSITION_EVAL(20U, (int32_T)c1_temp) != 0) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions= 1;
      transitionList[0] = 20;
      sf_debug_transition_conflict_check_begin();
      if ((*c1_DesiredState != 2) && (*c1_DesiredState != 0)) {
        transitionList[numTransitions] = 21;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,20);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,24);
    chartInstance.c1_tp_ValidationGate = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 0, "LookforTrack", 0);
    sf_call_output_fcn_disable(chartInstance.S, 1, "StraightLevelControl", 0);
    _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
    chartInstance.c1_is_Running = (uint8_T)c1_IN_FollowTrack;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
    chartInstance.c1_tp_FollowTrack = 1U;
    chartInstance.c1_ErrorCountHeading = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountHeading, 31U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,15);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
    chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_Stage1Aim;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
    chartInstance.c1_tp_Stage1Aim = 1U;
    sf_call_output_fcn_enable(chartInstance.S, 3, "TrackStage1", 0);
    chartInstance.c1_ErrorCountX = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountX, 32U);
    *c1_State = 3U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,21);
    c1_b_temp = (_SFD_CCP_CALL(21,0,((*c1_DesiredState != 2)!=0)) != 0);
    if (c1_b_temp) {
      c1_b_temp = (_SFD_CCP_CALL(21,1,((*c1_DesiredState != 0)!=0)) != 0);
    }

    if (CV_TRANSITION_EVAL(21U, (int32_T)c1_b_temp) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,21);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,24);
      chartInstance.c1_tp_ValidationGate = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 0, "LookforTrack", 0);
      sf_call_output_fcn_disable(chartInstance.S, 1, "StraightLevelControl", 0);
      _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_ChooseState;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c1_tp_ChooseState = 1U;
    } else {
      for (c1_i3 = 0; c1_i3 < 307200; c1_i3 = c1_i3 + 1) {
        c1_H[c1_i3] = (real_T)(*c1_c_H)[c1_i3];
      }

      for (c1_i4 = 0; c1_i4 < 307200; c1_i4 = c1_i4 + 1) {
        c1_S[c1_i4] = (real_T)(*c1_c_S)[c1_i4];
      }

      sf_debug_symbol_scope_push(3U, 0U);
      sf_debug_symbol_scope_add_verbose("Image", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 0, 0, &c1_Image);
      sf_debug_symbol_scope_add_verbose("S", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_S);
      sf_debug_symbol_scope_add_verbose("H", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_H);
      _SFD_SET_DATA_VALUE_PTR(49U, &c1_Image);
      _SFD_SET_DATA_VALUE_PTR(51U, &c1_S);
      _SFD_SET_DATA_VALUE_PTR(50U, &c1_H);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,25);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,25);
      for (c1_i5 = 0; c1_i5 < 307200; c1_i5 = c1_i5 + 1) {
        (*c1_b_H)[c1_i5] = c1_H[c1_i5];
      }

      for (c1_i6 = 0; c1_i6 < 307200; c1_i6 = c1_i6 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i6], 50U);
      }

      for (c1_i7 = 0; c1_i7 < 307200; c1_i7 = c1_i7 + 1) {
        (*c1_b_S)[c1_i7] = c1_S[c1_i7];
      }

      for (c1_i8 = 0; c1_i8 < 307200; c1_i8 = c1_i8 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_S)[c1_i8], 51U);
      }

      sf_call_output_fcn_call(chartInstance.S, 0, "LookforTrack", 0);
      c1_Image = *c1_c_Image;
      _SFD_DATA_RANGE_CHECK(c1_Image, 49U);
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,25);
      _SFD_UNSET_DATA_VALUE_PTR(49U);
      _SFD_UNSET_DATA_VALUE_PTR(51U);
      _SFD_UNSET_DATA_VALUE_PTR(50U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,25);
      sf_debug_symbol_scope_pop();
      chartInstance.c1_Obstacle = c1_Image;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Obstacle, 7U);
      c1_b_Image = chartInstance.c1_Obstacle;
      c1_OldImage = chartInstance.c1_OldObstacle;
      c1_count1 = chartInstance.c1_count;
      _SFD_SET_DATA_VALUE_PTR(55U, &c1_count2);
      _SFD_SET_DATA_VALUE_PTR(54U, &c1_count1);
      _SFD_SET_DATA_VALUE_PTR(53U, &c1_OldImage);
      _SFD_SET_DATA_VALUE_PTR(52U, &c1_b_Image);
      sf_debug_symbol_scope_push(6U, 0U);
      sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
      sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
      sf_debug_symbol_scope_add("count2", &c1_count2, c1_sf_marshall);
      sf_debug_symbol_scope_add("count1", &c1_count1, c1_sf_marshall);
      sf_debug_symbol_scope_add("OldImage", &c1_OldImage, c1_sf_marshall);
      sf_debug_symbol_scope_add("Image", &c1_b_Image, c1_sf_marshall);
      CV_EML_FCN(27, 0);

      /*  This function acts to count the number of consecutive times a particular */
      /*  image is recognized by the recognition software */
      _SFD_EML_CALL(27,5);
      c1_count2 = c1_count1;
      _SFD_EML_CALL(27,6);
      if (CV_EML_COND(27, 0, c1_b_Image != 0.0)) {
        if (CV_EML_COND(27, 1, c1_b_Image == c1_OldImage)) {
          CV_EML_MCDC(27, 0, true);
          CV_EML_IF(27, 0, true);
          _SFD_EML_CALL(27,7);
          c1_count2 = c1_count2 + 1.0;
          goto label_1;
        }
      }

      CV_EML_MCDC(27, 0, false);
      CV_EML_IF(27, 0, false);
      _SFD_EML_CALL(27,9);
      c1_count2 = 0.0;
     label_1:
      ;
      _SFD_EML_CALL(27,-9);
      sf_debug_symbol_scope_pop();
      _SFD_UNSET_DATA_VALUE_PTR(55U);
      _SFD_UNSET_DATA_VALUE_PTR(54U);
      _SFD_UNSET_DATA_VALUE_PTR(53U);
      _SFD_UNSET_DATA_VALUE_PTR(52U);
      chartInstance.c1_TrackCount = c1_count2;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_TrackCount, 28U);
      c1_CurrentDepth = (real32_T)*c1_b_CurrentDepth;
      c1_DesiredDepth = (real32_T)*c1_b_DesiredDepth;
      c1_DesiredHeading = *c1_b_DesiredHeading;
      c1_CurrentHeading = *c1_b_CurrentHeading;
      sf_debug_symbol_scope_push(7U, 0U);
      sf_debug_symbol_scope_add_verbose("ChangetoRight", 2, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoRight);
      sf_debug_symbol_scope_add_verbose("ChangetoLeft", 2, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoLeft);
      sf_debug_symbol_scope_add_verbose("ChangetoVertical", 2, 0U, 0U, 0U, 0U,
        1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoVertical);
      sf_debug_symbol_scope_add_verbose("CurrentHeading", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentHeading);
      sf_debug_symbol_scope_add_verbose("DesiredHeading", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_DesiredHeading);
      sf_debug_symbol_scope_add_verbose("DesiredDepth", 1, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_DesiredDepth);
      sf_debug_symbol_scope_add_verbose("CurrentDepth", 1, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentDepth);
      _SFD_SET_DATA_VALUE_PTR(48U, &c1_ChangetoRight);
      _SFD_SET_DATA_VALUE_PTR(47U, &c1_ChangetoLeft);
      _SFD_SET_DATA_VALUE_PTR(46U, &c1_ChangetoVertical);
      _SFD_SET_DATA_VALUE_PTR(45U, &c1_CurrentHeading);
      _SFD_SET_DATA_VALUE_PTR(44U, &c1_DesiredHeading);
      _SFD_SET_DATA_VALUE_PTR(43U, &c1_DesiredDepth);
      _SFD_SET_DATA_VALUE_PTR(42U, &c1_CurrentDepth);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,26);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,26);
      *c1_c_CurrentDepth = c1_CurrentDepth;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_CurrentDepth, 42U);
      *c1_c_DesiredDepth = c1_DesiredDepth;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_DesiredDepth, 43U);
      *c1_c_DesiredHeading = c1_DesiredHeading;
      _SFD_DATA_RANGE_CHECK(*c1_c_DesiredHeading, 44U);
      *c1_c_CurrentHeading = c1_CurrentHeading;
      _SFD_DATA_RANGE_CHECK(*c1_c_CurrentHeading, 45U);
      sf_call_output_fcn_call(chartInstance.S, 1, "StraightLevelControl", 0);
      c1_ChangetoVertical = *c1_b_ChangetoVertical;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoVertical, 46U);
      c1_ChangetoLeft = *c1_b_ChangetoLeft;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoLeft, 47U);
      c1_ChangetoRight = *c1_b_ChangetoRight;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoRight, 48U);
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,26);
      _SFD_UNSET_DATA_VALUE_PTR(48U);
      _SFD_UNSET_DATA_VALUE_PTR(47U);
      _SFD_UNSET_DATA_VALUE_PTR(46U);
      _SFD_UNSET_DATA_VALUE_PTR(45U);
      _SFD_UNSET_DATA_VALUE_PTR(44U);
      _SFD_UNSET_DATA_VALUE_PTR(43U);
      _SFD_UNSET_DATA_VALUE_PTR(42U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,26);
      sf_debug_symbol_scope_pop();
      *c1_Vertical = c1_ChangetoVertical;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
      *c1_Left = c1_ChangetoLeft;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
      *c1_Right = c1_ChangetoRight;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
      chartInstance.c1_OldObstacle = chartInstance.c1_Obstacle;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldObstacle, 8U);
      chartInstance.c1_count = chartInstance.c1_TrackCount;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_count, 6U);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
}

static void c1_Buoy(void)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  int32_T c1_i9;
  static real_T c1_H[307200];
  int32_T c1_i10;
  static real_T c1_S[307200];
  real_T c1_b_CentroidX;
  real_T c1_b_CentroidY;
  int8_T c1_ChangetoVert;
  real_T c1_ChangetoLeft;
  real_T c1_ChangetoRight;
  int32_T c1_BuoyArea;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  real_T c1_d0;
  real_T c1_d1;
  real_T c1_Size;
  real_T c1_count1;
  real_T c1_count2;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 2.0;
  real_T c1_CentroidX1;
  real_T c1_CentroidY1;
  real_T c1_ChangetoRight2;
  real_T c1_ChangetoLeft2;
  real_T c1_ChangetoVertical2;
  real_T c1_ChangetoVertical1;
  real_T c1_ChangetoLeft1;
  real_T c1_ChangetoRight1;
  real_T c1_b_nargout = 3.0;
  real_T c1_b_nargin = 5.0;
  real_T c1_d2;
  real_T c1_d3;
  real_T c1_d4;
  int8_T *c1_DesiredState;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  int8_T *c1_Right;
  int8_T *c1_Left;
  int8_T *c1_Vertical;
  uint8_T *c1_State;
  int32_T *c1_b_BuoyArea;
  real_T *c1_b_ChangetoRight;
  real_T *c1_b_ChangetoLeft;
  int8_T *c1_b_ChangetoVert;
  real_T *c1_c_CentroidY;
  real_T *c1_c_CentroidX;
  real_T (*c1_b_H)[307200];
  real_T (*c1_b_S)[307200];
  real32_T (*c1_c_S)[307200];
  real32_T (*c1_c_H)[307200];
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_c_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_ChangetoRight = (real_T *)ssGetInputPortSignal(chartInstance.S, 12);
  c1_b_H = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 16);
  c1_c_CentroidX = (real_T *)ssGetInputPortSignal(chartInstance.S, 16);
  c1_b_ChangetoVert = (int8_T *)ssGetInputPortSignal(chartInstance.S, 14);
  c1_b_S = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 17);
  c1_c_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
  c1_c_CentroidY = (real_T *)ssGetInputPortSignal(chartInstance.S, 15);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_b_ChangetoLeft = (real_T *)ssGetInputPortSignal(chartInstance.S, 13);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  c1_b_BuoyArea = (int32_T *)ssGetInputPortSignal(chartInstance.S, 11);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,2);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,4);
  c1_temp = (_SFD_CCP_CALL(4,0,((chartInstance.c1_countarea > 2.0)!=0)) != 0);
  if (c1_temp) {
    c1_temp = (_SFD_CCP_CALL(4,1,((*c1_DesiredState == 0)!=0)) != 0);
  }

  if (CV_TRANSITION_EVAL(4U, (int32_T)c1_temp) != 0) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions= 1;
      transitionList[0] = 4;
      sf_debug_transition_conflict_check_begin();
      if ((*c1_DesiredState != 5) && (*c1_DesiredState != 0)) {
        transitionList[numTransitions] = 5;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,4);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
    chartInstance.c1_BuoyDone = 1.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyDone, 11U);
    chartInstance.c1_tp_Buoy = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 2, "Buoy", 0);
    _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
    chartInstance.c1_is_Running = (uint8_T)c1_IN_Finish;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,11);
    chartInstance.c1_tp_Finish = 1U;
    *c1_State = 6U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
    *c1_Left = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
    *c1_Right = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
    *c1_Vertical = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,5);
    c1_b_temp = (_SFD_CCP_CALL(5,0,((*c1_DesiredState != 5)!=0)) != 0);
    if (c1_b_temp) {
      c1_b_temp = (_SFD_CCP_CALL(5,1,((*c1_DesiredState != 0)!=0)) != 0);
    }

    if (CV_TRANSITION_EVAL(5U, (int32_T)c1_b_temp) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,5);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
      chartInstance.c1_BuoyDone = 1.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyDone, 11U);
      chartInstance.c1_tp_Buoy = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 2, "Buoy", 0);
      _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_ChooseState;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c1_tp_ChooseState = 1U;
    } else {
      for (c1_i9 = 0; c1_i9 < 307200; c1_i9 = c1_i9 + 1) {
        c1_H[c1_i9] = (real_T)(*c1_c_H)[c1_i9];
      }

      for (c1_i10 = 0; c1_i10 < 307200; c1_i10 = c1_i10 + 1) {
        c1_S[c1_i10] = (real_T)(*c1_c_S)[c1_i10];
      }

      sf_debug_symbol_scope_push(8U, 0U);
      sf_debug_symbol_scope_add_verbose("CentroidX", 0, 0U, 0U, 0U, 0U, 1.0, 0,
        0.0, 0U, 0, 0U, 0, 0, &c1_b_CentroidX);
      sf_debug_symbol_scope_add_verbose("CentroidY", 0, 0U, 0U, 0U, 0U, 1.0, 0,
        0.0, 0U, 0, 0U, 0, 0, &c1_b_CentroidY);
      sf_debug_symbol_scope_add_verbose("ChangetoVert", 2, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoVert);
      sf_debug_symbol_scope_add_verbose("ChangetoLeft", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoLeft);
      sf_debug_symbol_scope_add_verbose("ChangetoRight", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoRight);
      sf_debug_symbol_scope_add_verbose("BuoyArea", 6, 0U, 0U, 0U, 0U, 1.0, 0,
        0.0, 0U, 0, 0U, 0, 0, &c1_BuoyArea);
      sf_debug_symbol_scope_add_verbose("S", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_S);
      sf_debug_symbol_scope_add_verbose("H", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_H);
      _SFD_SET_DATA_VALUE_PTR(74U, &c1_b_CentroidX);
      _SFD_SET_DATA_VALUE_PTR(73U, &c1_b_CentroidY);
      _SFD_SET_DATA_VALUE_PTR(72U, &c1_ChangetoVert);
      _SFD_SET_DATA_VALUE_PTR(71U, &c1_ChangetoLeft);
      _SFD_SET_DATA_VALUE_PTR(70U, &c1_ChangetoRight);
      _SFD_SET_DATA_VALUE_PTR(69U, &c1_BuoyArea);
      _SFD_SET_DATA_VALUE_PTR(68U, &c1_S);
      _SFD_SET_DATA_VALUE_PTR(67U, &c1_H);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,3);
      for (c1_i11 = 0; c1_i11 < 307200; c1_i11 = c1_i11 + 1) {
        (*c1_b_H)[c1_i11] = c1_H[c1_i11];
      }

      for (c1_i12 = 0; c1_i12 < 307200; c1_i12 = c1_i12 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i12], 67U);
      }

      for (c1_i13 = 0; c1_i13 < 307200; c1_i13 = c1_i13 + 1) {
        (*c1_b_S)[c1_i13] = c1_S[c1_i13];
      }

      for (c1_i14 = 0; c1_i14 < 307200; c1_i14 = c1_i14 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_S)[c1_i14], 68U);
      }

      sf_call_output_fcn_call(chartInstance.S, 2, "Buoy", 0);
      c1_BuoyArea = *c1_b_BuoyArea;
      _SFD_DATA_RANGE_CHECK((real_T)c1_BuoyArea, 69U);
      c1_ChangetoRight = *c1_b_ChangetoRight;
      _SFD_DATA_RANGE_CHECK(c1_ChangetoRight, 70U);
      c1_ChangetoLeft = *c1_b_ChangetoLeft;
      _SFD_DATA_RANGE_CHECK(c1_ChangetoLeft, 71U);
      c1_ChangetoVert = *c1_b_ChangetoVert;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoVert, 72U);
      c1_b_CentroidY = *c1_c_CentroidY;
      _SFD_DATA_RANGE_CHECK(c1_b_CentroidY, 73U);
      c1_b_CentroidX = *c1_c_CentroidX;
      _SFD_DATA_RANGE_CHECK(c1_b_CentroidX, 74U);
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,3);
      _SFD_UNSET_DATA_VALUE_PTR(74U);
      _SFD_UNSET_DATA_VALUE_PTR(73U);
      _SFD_UNSET_DATA_VALUE_PTR(72U);
      _SFD_UNSET_DATA_VALUE_PTR(71U);
      _SFD_UNSET_DATA_VALUE_PTR(70U);
      _SFD_UNSET_DATA_VALUE_PTR(69U);
      _SFD_UNSET_DATA_VALUE_PTR(68U);
      _SFD_UNSET_DATA_VALUE_PTR(67U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
      sf_debug_symbol_scope_pop();
      chartInstance.c1_Area = (real_T)c1_BuoyArea;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Area, 10U);
      c1_d0 = c1_ChangetoRight;
      *c1_Right = c1__s8_d_(c1_d0);
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
      c1_d1 = c1_ChangetoLeft;
      *c1_Left = c1__s8_d_(c1_d1);
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
      *c1_Vertical = c1_ChangetoVert;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
      *c1_BuoyCentroidX = c1_b_CentroidY;
      _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidX, 21U);
      *c1_BuoyCentroidY = c1_b_CentroidX;
      _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidY, 22U);
      c1_Size = chartInstance.c1_Area;
      c1_count1 = chartInstance.c1_countarea;
      _SFD_SET_DATA_VALUE_PTR(66U, &c1_count2);
      _SFD_SET_DATA_VALUE_PTR(65U, &c1_count1);
      _SFD_SET_DATA_VALUE_PTR(64U, &c1_Size);
      sf_debug_symbol_scope_push(5U, 0U);
      sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
      sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
      sf_debug_symbol_scope_add("count2", &c1_count2, c1_sf_marshall);
      sf_debug_symbol_scope_add("count1", &c1_count1, c1_sf_marshall);
      sf_debug_symbol_scope_add("Size", &c1_Size, c1_sf_marshall);
      CV_EML_FCN(4, 0);

      /*  This function acts to count the number of consecutive times a particular */
      /*  area is recognized by the recognition software */
      _SFD_EML_CALL(4,5);
      c1_count2 = c1_count1;
      _SFD_EML_CALL(4,6);
      if (CV_EML_IF(4, 0, c1_Size > 8000.0)) {
        _SFD_EML_CALL(4,7);
        c1_count2 = c1_count2 + 1.0;
      } else {
        _SFD_EML_CALL(4,9);
        c1_count2 = 0.0;
      }

      _SFD_EML_CALL(4,-9);
      sf_debug_symbol_scope_pop();
      _SFD_UNSET_DATA_VALUE_PTR(66U);
      _SFD_UNSET_DATA_VALUE_PTR(65U);
      _SFD_UNSET_DATA_VALUE_PTR(64U);
      chartInstance.c1_countarea = c1_count2;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_countarea, 12U);
      c1_CentroidX1 = *c1_BuoyCentroidX;
      c1_CentroidY1 = *c1_BuoyCentroidY;
      c1_ChangetoRight2 = (real_T)*c1_Right;
      c1_ChangetoLeft2 = (real_T)*c1_Left;
      c1_ChangetoVertical2 = (real_T)*c1_Vertical;
      _SFD_SET_DATA_VALUE_PTR(63U, &c1_ChangetoVertical1);
      _SFD_SET_DATA_VALUE_PTR(62U, &c1_ChangetoLeft1);
      _SFD_SET_DATA_VALUE_PTR(61U, &c1_ChangetoRight1);
      _SFD_SET_DATA_VALUE_PTR(60U, &c1_ChangetoVertical2);
      _SFD_SET_DATA_VALUE_PTR(59U, &c1_ChangetoLeft2);
      _SFD_SET_DATA_VALUE_PTR(58U, &c1_ChangetoRight2);
      _SFD_SET_DATA_VALUE_PTR(57U, &c1_CentroidY1);
      _SFD_SET_DATA_VALUE_PTR(56U, &c1_CentroidX1);
      sf_debug_symbol_scope_push(10U, 0U);
      sf_debug_symbol_scope_add("nargout", &c1_b_nargout, c1_sf_marshall);
      sf_debug_symbol_scope_add("nargin", &c1_b_nargin, c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoVertical1", &c1_ChangetoVertical1,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoLeft1", &c1_ChangetoLeft1,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoRight1", &c1_ChangetoRight1,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoVertical2", &c1_ChangetoVertical2,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoLeft2", &c1_ChangetoLeft2,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("ChangetoRight2", &c1_ChangetoRight2,
        c1_sf_marshall);
      sf_debug_symbol_scope_add("CentroidY1", &c1_CentroidY1, c1_sf_marshall);
      sf_debug_symbol_scope_add("CentroidX1", &c1_CentroidX1, c1_sf_marshall);
      CV_EML_FCN(5, 0);
      _SFD_EML_CALL(5,4);
      if (CV_EML_COND(5, 0, c1_CentroidX1 == -1.0)) {
      } else if (CV_EML_COND(5, 1, c1_CentroidY1 == -1.0)) {
      } else {
        CV_EML_MCDC(5, 0, false);
        CV_EML_IF(5, 0, false);
        _SFD_EML_CALL(5,9);
        c1_ChangetoRight1 = c1_ChangetoRight2;
        _SFD_EML_CALL(5,10);
        c1_ChangetoLeft1 = c1_ChangetoLeft2;
        _SFD_EML_CALL(5,11);
        c1_ChangetoVertical1 = c1_ChangetoVertical2;
        goto label_1;
      }

      CV_EML_MCDC(5, 0, true);
      CV_EML_IF(5, 0, true);
      _SFD_EML_CALL(5,5);
      c1_ChangetoRight1 = 10.0;
      _SFD_EML_CALL(5,6);
      c1_ChangetoLeft1 = 10.0;
      _SFD_EML_CALL(5,7);
      c1_ChangetoVertical1 = -100.0;
     label_1:
      ;
      _SFD_EML_CALL(5,-11);
      sf_debug_symbol_scope_pop();
      _SFD_UNSET_DATA_VALUE_PTR(63U);
      _SFD_UNSET_DATA_VALUE_PTR(62U);
      _SFD_UNSET_DATA_VALUE_PTR(61U);
      _SFD_UNSET_DATA_VALUE_PTR(60U);
      _SFD_UNSET_DATA_VALUE_PTR(59U);
      _SFD_UNSET_DATA_VALUE_PTR(58U);
      _SFD_UNSET_DATA_VALUE_PTR(57U);
      _SFD_UNSET_DATA_VALUE_PTR(56U);
      c1_d2 = c1_ChangetoRight1;
      *c1_Right = c1__s8_d_(c1_d2);
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
      c1_d3 = c1_ChangetoLeft1;
      *c1_Left = c1__s8_d_(c1_d3);
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
      c1_d4 = c1_ChangetoVertical1;
      *c1_Vertical = c1__s8_d_(c1_d4);
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
}

static void c1_FollowTrack(void)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  int32_T c1_i15;
  static real_T c1_dv0[307200];
  int32_T c1_i16;
  static real_T c1_dv1[307200];
  real_T c1_b_ErrorX;
  int8_T c1_ChangetoVertical;
  int8_T c1_ChangetoLeft;
  int8_T c1_ChangetoRight;
  real_T c1_DesiredHeading;
  real_T c1_CurrentHeading;
  real32_T c1_DesiredDepth;
  real32_T c1_CurrentDepth;
  int32_T c1_i17;
  static real_T c1_H[307200];
  int32_T c1_i18;
  static real_T c1_S[307200];
  real_T c1_b_ErrorY;
  int8_T c1_b_ChangetoVertical;
  int8_T c1_b_ChangetoLeft;
  int8_T c1_b_ChangetoRight;
  real_T c1_b_DesiredHeading;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_ErrorX5;
  real_T c1_ErrorCountX5;
  real_T c1_ErrorCountX1;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 2.0;
  real_T c1_ErrorHeading1;
  int8_T c1_c_ChangetoRight;
  int8_T c1_c_ChangetoLeft;
  int8_T c1_c_ChangetoVertical;
  int8_T *c1_DesiredState;
  real_T *c1_b_CurrentHeading;
  real_T *c1_b_DesiredDepth;
  real_T *c1_b_CurrentDepth;
  real_T *c1_c_DesiredHeading;
  int8_T *c1_Vertical;
  int8_T *c1_Left;
  int8_T *c1_Right;
  real_T *c1_c_CurrentHeading;
  real32_T *c1_c_DesiredDepth;
  real32_T *c1_c_CurrentDepth;
  real_T *c1_d_DesiredHeading;
  int8_T *c1_d_ChangetoRight;
  int8_T *c1_d_ChangetoLeft;
  int8_T *c1_d_ChangetoVertical;
  real_T *c1_c_ErrorY;
  real_T (*c1_b_H)[307200];
  real_T (*c1_b_S)[307200];
  real32_T (*c1_c_S)[307200];
  real32_T (*c1_c_H)[307200];
  c1_c_DesiredDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 24);
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_d_ChangetoRight = (int8_T *)ssGetInputPortSignal(chartInstance.S, 23);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_c_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
  c1_c_CurrentHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 23);
  c1_b_H = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 26);
  c1_b_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_b_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_d_DesiredHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 22);
  c1_c_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
  c1_c_ErrorY = (real_T *)ssGetInputPortSignal(chartInstance.S, 26);
  c1_c_CurrentDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 25);
  c1_c_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_d_ChangetoVertical = (int8_T *)ssGetInputPortSignal(chartInstance.S, 25);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_CurrentDepth = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_b_S = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 27);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_d_ChangetoLeft = (int8_T *)ssGetInputPortSignal(chartInstance.S, 24);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,12);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,13);
  c1_temp = (_SFD_CCP_CALL(13,0,((chartInstance.c1_ErrorCountHeading > 3.0)!=0))
             != 0);
  if (c1_temp) {
    c1_temp = (_SFD_CCP_CALL(13,1,((*c1_DesiredState == 0)!=0)) != 0);
  }

  if (CV_TRANSITION_EVAL(13U, (int32_T)c1_temp) != 0) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions= 1;
      transitionList[0] = 13;
      sf_debug_transition_conflict_check_begin();
      if ((*c1_DesiredState != 3) && (*c1_DesiredState != 0)) {
        transitionList[numTransitions] = 14;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,13);
    c1_exit_internal_FollowTrack();
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
    chartInstance.c1_tp_FollowTrack = 0U;
    chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
    c1_enter_atomic_FindBuoy();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,14);
    c1_b_temp = (_SFD_CCP_CALL(14,0,((*c1_DesiredState != 3)!=0)) != 0);
    if (c1_b_temp) {
      c1_b_temp = (_SFD_CCP_CALL(14,1,((*c1_DesiredState != 0)!=0)) != 0);
    }

    if (CV_TRANSITION_EVAL(14U, (int32_T)c1_b_temp) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,14);
      c1_exit_internal_FollowTrack();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
      chartInstance.c1_tp_FollowTrack = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_ChooseState;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c1_tp_ChooseState = 1U;
    } else {
      switch (chartInstance.c1_is_FollowTrack) {
       case c1_IN_Stage1Aim:
        CV_STATE_EVAL(12,0,1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,13);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,16);
        if (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16,0,
              ((chartInstance.c1_ErrorCountX > 3.0)!=0))) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,16);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
          chartInstance.c1_tp_Stage1Aim = 0U;
          sf_call_output_fcn_disable(chartInstance.S, 3, "TrackStage1", 0);
          _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
          chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_Stage2Position;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,16);
          chartInstance.c1_tp_Stage2Position = 1U;
          sf_call_output_fcn_enable(chartInstance.S, 4, "TrackStage2", 0);
          chartInstance.c1_ErrorCountY = 0.0;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountY, 33U);
        } else {
          for (c1_i15 = 0; c1_i15 < 307200; c1_i15 = c1_i15 + 1) {
            c1_dv0[c1_i15] = (real_T)(*c1_c_H)[c1_i15];
          }

          for (c1_i16 = 0; c1_i16 < 307200; c1_i16 = c1_i16 + 1) {
            c1_dv1[c1_i16] = (real_T)(*c1_c_S)[c1_i16];
          }

          c1_TrackStage1(*c1_b_CurrentHeading, (real32_T)*c1_b_DesiredDepth,
                         (real32_T)*c1_b_CurrentDepth, c1_dv0, c1_dv1,
                         &c1_DesiredHeading
                         , &c1_ChangetoRight, &c1_ChangetoLeft,
                         &c1_ChangetoVertical, &c1_b_ErrorX);
          *c1_c_DesiredHeading = c1_DesiredHeading;
          _SFD_DATA_RANGE_CHECK(*c1_c_DesiredHeading, 9U);
          *c1_Right = c1_ChangetoRight;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
          *c1_Left = c1_ChangetoLeft;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
          *c1_Vertical = c1_ChangetoVertical;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
          chartInstance.c1_ErrorX = c1_b_ErrorX;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorX, 13U);
          chartInstance.c1_ErrorCountX = c1_ErrorCounter(chartInstance.c1_ErrorX,
            chartInstance.c1_ErrorCountX);
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountX, 32U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
        break;

       case c1_IN_Stage2Position:
        CV_STATE_EVAL(12,0,2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,16);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,17);
        if (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17,0,
              ((chartInstance.c1_ErrorCountY > 3.0)!=0))) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,17);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,16);
          chartInstance.c1_tp_Stage2Position = 0U;
          sf_call_output_fcn_disable(chartInstance.S, 4, "TrackStage2", 0);
          _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
          chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_Stage3ReOrient;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,19);
          chartInstance.c1_tp_Stage3ReOrient = 1U;
          sf_call_output_fcn_enable(chartInstance.S, 7, "DirectionalControl", 0);
        } else {
          c1_CurrentHeading = *c1_b_CurrentHeading;
          c1_DesiredDepth = (real32_T)*c1_b_DesiredDepth;
          c1_CurrentDepth = (real32_T)*c1_b_CurrentDepth;
          for (c1_i17 = 0; c1_i17 < 307200; c1_i17 = c1_i17 + 1) {
            c1_H[c1_i17] = (real_T)(*c1_c_H)[c1_i17];
          }

          for (c1_i18 = 0; c1_i18 < 307200; c1_i18 = c1_i18 + 1) {
            c1_S[c1_i18] = (real_T)(*c1_c_S)[c1_i18];
          }

          sf_debug_symbol_scope_push(10U, 0U);
          sf_debug_symbol_scope_add_verbose("ErrorY", 0, 0U, 0U, 0U, 0U, 1.0, 0,
            0.0, 0U, 0, 0U, 0, 0, &c1_b_ErrorY);
          sf_debug_symbol_scope_add_verbose("ChangetoVertical", 2, 0U, 0U, 0U,
            0U, 1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_b_ChangetoVertical);
          sf_debug_symbol_scope_add_verbose("ChangetoLeft", 2, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_b_ChangetoLeft);
          sf_debug_symbol_scope_add_verbose("ChangetoRight", 2, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_b_ChangetoRight);
          sf_debug_symbol_scope_add_verbose("DesiredHeading", 0, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_b_DesiredHeading);
          sf_debug_symbol_scope_add_verbose("S", 0, 2U, 480U, 640U, 0U, 1.0, 0,
            0.0, 0U, 0, 0U, 1, 0, &c1_S);
          sf_debug_symbol_scope_add_verbose("H", 0, 2U, 480U, 640U, 0U, 1.0, 0,
            0.0, 0U, 0, 0U, 1, 0, &c1_H);
          sf_debug_symbol_scope_add_verbose("CurrentDepth", 1, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentDepth);
          sf_debug_symbol_scope_add_verbose("DesiredDepth", 1, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_DesiredDepth);
          sf_debug_symbol_scope_add_verbose("CurrentHeading", 0, 0U, 0U, 0U, 0U,
            1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentHeading);
          _SFD_SET_DATA_VALUE_PTR(113U, &c1_b_ErrorY);
          _SFD_SET_DATA_VALUE_PTR(111U, &c1_b_ChangetoVertical);
          _SFD_SET_DATA_VALUE_PTR(110U, &c1_b_ChangetoLeft);
          _SFD_SET_DATA_VALUE_PTR(109U, &c1_b_ChangetoRight);
          _SFD_SET_DATA_VALUE_PTR(108U, &c1_b_DesiredHeading);
          _SFD_SET_DATA_VALUE_PTR(114U, &c1_S);
          _SFD_SET_DATA_VALUE_PTR(112U, &c1_H);
          _SFD_SET_DATA_VALUE_PTR(107U, &c1_CurrentDepth);
          _SFD_SET_DATA_VALUE_PTR(106U, &c1_DesiredDepth);
          _SFD_SET_DATA_VALUE_PTR(105U, &c1_CurrentHeading);
          _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,18);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,18);
          *c1_c_CurrentHeading = c1_CurrentHeading;
          _SFD_DATA_RANGE_CHECK(*c1_c_CurrentHeading, 105U);
          *c1_c_DesiredDepth = c1_DesiredDepth;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_c_DesiredDepth, 106U);
          *c1_c_CurrentDepth = c1_CurrentDepth;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_c_CurrentDepth, 107U);
          for (c1_i19 = 0; c1_i19 < 307200; c1_i19 = c1_i19 + 1) {
            (*c1_b_H)[c1_i19] = c1_H[c1_i19];
          }

          for (c1_i20 = 0; c1_i20 < 307200; c1_i20 = c1_i20 + 1) {
            _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i20], 112U);
          }

          for (c1_i21 = 0; c1_i21 < 307200; c1_i21 = c1_i21 + 1) {
            (*c1_b_S)[c1_i21] = c1_S[c1_i21];
          }

          for (c1_i22 = 0; c1_i22 < 307200; c1_i22 = c1_i22 + 1) {
            _SFD_DATA_RANGE_CHECK((*c1_b_S)[c1_i22], 114U);
          }

          sf_call_output_fcn_call(chartInstance.S, 4, "TrackStage2", 0);
          c1_b_DesiredHeading = *c1_d_DesiredHeading;
          _SFD_DATA_RANGE_CHECK(c1_b_DesiredHeading, 108U);
          c1_b_ChangetoRight = *c1_d_ChangetoRight;
          _SFD_DATA_RANGE_CHECK((real_T)c1_b_ChangetoRight, 109U);
          c1_b_ChangetoLeft = *c1_d_ChangetoLeft;
          _SFD_DATA_RANGE_CHECK((real_T)c1_b_ChangetoLeft, 110U);
          c1_b_ChangetoVertical = *c1_d_ChangetoVertical;
          _SFD_DATA_RANGE_CHECK((real_T)c1_b_ChangetoVertical, 111U);
          c1_b_ErrorY = *c1_c_ErrorY;
          _SFD_DATA_RANGE_CHECK(c1_b_ErrorY, 113U);
          _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,18);
          _SFD_UNSET_DATA_VALUE_PTR(113U);
          _SFD_UNSET_DATA_VALUE_PTR(111U);
          _SFD_UNSET_DATA_VALUE_PTR(110U);
          _SFD_UNSET_DATA_VALUE_PTR(109U);
          _SFD_UNSET_DATA_VALUE_PTR(108U);
          _SFD_UNSET_DATA_VALUE_PTR(114U);
          _SFD_UNSET_DATA_VALUE_PTR(112U);
          _SFD_UNSET_DATA_VALUE_PTR(107U);
          _SFD_UNSET_DATA_VALUE_PTR(106U);
          _SFD_UNSET_DATA_VALUE_PTR(105U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,18);
          sf_debug_symbol_scope_pop();
          *c1_c_DesiredHeading = c1_b_DesiredHeading;
          _SFD_DATA_RANGE_CHECK(*c1_c_DesiredHeading, 9U);
          *c1_Right = c1_b_ChangetoRight;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
          *c1_Left = c1_b_ChangetoLeft;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
          *c1_Vertical = c1_b_ChangetoVertical;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
          chartInstance.c1_ErrorY = c1_b_ErrorY;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorY, 16U);
          c1_ErrorX5 = chartInstance.c1_ErrorY;
          c1_ErrorCountX5 = chartInstance.c1_ErrorCountY;
          _SFD_SET_DATA_VALUE_PTR(104U, &c1_ErrorCountX1);
          _SFD_SET_DATA_VALUE_PTR(103U, &c1_ErrorCountX5);
          _SFD_SET_DATA_VALUE_PTR(102U, &c1_ErrorX5);
          sf_debug_symbol_scope_push(5U, 0U);
          sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
          sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
          sf_debug_symbol_scope_add("ErrorCountX1", &c1_ErrorCountX1,
            c1_sf_marshall);
          sf_debug_symbol_scope_add("ErrorCountX5", &c1_ErrorCountX5,
            c1_sf_marshall);
          sf_debug_symbol_scope_add("ErrorX5", &c1_ErrorX5, c1_sf_marshall);
          CV_EML_FCN(17, 0);
          _SFD_EML_CALL(17,4);
          if (CV_EML_COND(17, 0, c1_ErrorX5 < 5.0)) {
            if (CV_EML_COND(17, 1, c1_ErrorX5 > -5.0)) {
              CV_EML_MCDC(17, 0, true);
              CV_EML_IF(17, 0, true);
              _SFD_EML_CALL(17,5);
              c1_ErrorCountX1 = c1_ErrorCountX5 + 1.0;
              goto label_1;
            }
          }

          CV_EML_MCDC(17, 0, false);
          CV_EML_IF(17, 0, false);
          _SFD_EML_CALL(17,7);
          c1_ErrorCountX1 = 0.0;
         label_1:
          ;
          _SFD_EML_CALL(17,-7);
          sf_debug_symbol_scope_pop();
          _SFD_UNSET_DATA_VALUE_PTR(104U);
          _SFD_UNSET_DATA_VALUE_PTR(103U);
          _SFD_UNSET_DATA_VALUE_PTR(102U);
          chartInstance.c1_ErrorCountY = c1_ErrorCountX1;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountY, 33U);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
        break;

       case c1_IN_Stage3ReOrient:
        CV_STATE_EVAL(12,0,3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,19);
        c1_DirectionalControl((real32_T)*c1_b_CurrentDepth, (real32_T)
                              *c1_b_DesiredDepth, *c1_c_DesiredHeading,
                              *c1_b_CurrentHeading, &
                              c1_c_ChangetoVertical, &c1_c_ChangetoLeft,
                              &c1_c_ChangetoRight, &c1_ErrorHeading1);
        *c1_Vertical = c1_c_ChangetoVertical;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
        *c1_Left = c1_c_ChangetoLeft;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
        *c1_Right = c1_c_ChangetoRight;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
        chartInstance.c1_ErrorHeading = c1_ErrorHeading1;
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorHeading, 34U);
        chartInstance.c1_ErrorCountHeading = c1_b_ErrorCounter
          (chartInstance.c1_ErrorHeading, chartInstance.c1_ErrorCountHeading);
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountHeading, 31U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
        break;

       default:
        CV_STATE_EVAL(12,0,0);
        chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
        break;
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
}

static void c1_exit_internal_FollowTrack(void)
{
  switch (chartInstance.c1_is_FollowTrack) {
   case c1_IN_Stage1Aim:
    CV_STATE_EVAL(12,1,1);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,13);
    chartInstance.c1_tp_Stage1Aim = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 3, "TrackStage1", 0);
    chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
    break;

   case c1_IN_Stage2Position:
    CV_STATE_EVAL(12,1,2);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,16);
    chartInstance.c1_tp_Stage2Position = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 4, "TrackStage2", 0);
    chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,16);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
    break;

   case c1_IN_Stage3ReOrient:
    CV_STATE_EVAL(12,1,3);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,19);
    chartInstance.c1_tp_Stage3ReOrient = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 7, "DirectionalControl", 0);
    chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,19);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,19);
    break;

   default:
    CV_STATE_EVAL(12,1,0);
    chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,13);
    break;
  }
}

static void c1_TrackStage1(real_T c1_CurrentHeading, real32_T c1_DesiredDepth,
  real32_T c1_CurrentDepth, real_T c1_H[307200], real_T
  c1_S[307200], real_T *c1_DesiredHeading, int8_T *c1_ChangetoRight, int8_T
  *c1_ChangetoLeft, int8_T *c1_ChangetoVertical, real_T *
  c1_b_ErrorX)
{
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  real_T *c1_b_CurrentHeading;
  real32_T *c1_b_DesiredDepth;
  real32_T *c1_b_CurrentDepth;
  real_T *c1_b_DesiredHeading;
  int8_T *c1_b_ChangetoRight;
  int8_T *c1_b_ChangetoLeft;
  int8_T *c1_b_ChangetoVertical;
  real_T *c1_c_ErrorX;
  real_T (*c1_b_H)[307200];
  real_T (*c1_b_S)[307200];
  c1_b_CurrentDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 20);
  c1_b_ChangetoRight = (int8_T *)ssGetInputPortSignal(chartInstance.S, 18);
  c1_c_ErrorX = (real_T *)ssGetInputPortSignal(chartInstance.S, 21);
  c1_b_ChangetoVertical = (int8_T *)ssGetInputPortSignal(chartInstance.S, 20);
  c1_b_DesiredHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 17);
  c1_b_S = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 22);
  c1_b_CurrentHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 18);
  c1_b_DesiredDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 19);
  c1_b_H = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 21);
  c1_b_ChangetoLeft = (int8_T *)ssGetInputPortSignal(chartInstance.S, 19);
  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add_verbose("ErrorX", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 0, 0, c1_b_ErrorX);
  sf_debug_symbol_scope_add_verbose("ChangetoVertical", 2, 0U, 0U, 0U, 0U, 1.0,
    0, 0.0, 0U, 0, 0U, 0, 0, c1_ChangetoVertical);
  sf_debug_symbol_scope_add_verbose("ChangetoLeft", 2, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_ChangetoLeft);
  sf_debug_symbol_scope_add_verbose("ChangetoRight", 2, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_ChangetoRight);
  sf_debug_symbol_scope_add_verbose("DesiredHeading", 0, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_DesiredHeading);
  sf_debug_symbol_scope_add_verbose("S", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 1, 0, c1_S);
  sf_debug_symbol_scope_add_verbose("H", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0, 0U,
    0, 0U, 1, 0, c1_H);
  sf_debug_symbol_scope_add_verbose("CurrentDepth", 1, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_CurrentDepth);
  sf_debug_symbol_scope_add_verbose("DesiredDepth", 1, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_DesiredDepth);
  sf_debug_symbol_scope_add_verbose("CurrentHeading", 0, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_CurrentHeading);
  _SFD_SET_DATA_VALUE_PTR(99U, c1_b_ErrorX);
  _SFD_SET_DATA_VALUE_PTR(98U, c1_ChangetoVertical);
  _SFD_SET_DATA_VALUE_PTR(97U, c1_ChangetoLeft);
  _SFD_SET_DATA_VALUE_PTR(96U, c1_ChangetoRight);
  _SFD_SET_DATA_VALUE_PTR(95U, c1_DesiredHeading);
  _SFD_SET_DATA_VALUE_PTR(101U, c1_S);
  _SFD_SET_DATA_VALUE_PTR(100U, c1_H);
  _SFD_SET_DATA_VALUE_PTR(94U, &c1_CurrentDepth);
  _SFD_SET_DATA_VALUE_PTR(93U, &c1_DesiredDepth);
  _SFD_SET_DATA_VALUE_PTR(92U, &c1_CurrentHeading);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,15);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,15);
  *c1_b_CurrentHeading = c1_CurrentHeading;
  _SFD_DATA_RANGE_CHECK(*c1_b_CurrentHeading, 92U);
  *c1_b_DesiredDepth = c1_DesiredDepth;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_DesiredDepth, 93U);
  *c1_b_CurrentDepth = c1_CurrentDepth;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_CurrentDepth, 94U);
  for (c1_i23 = 0; c1_i23 < 307200; c1_i23 = c1_i23 + 1) {
    (*c1_b_H)[c1_i23] = c1_H[c1_i23];
  }

  for (c1_i24 = 0; c1_i24 < 307200; c1_i24 = c1_i24 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i24], 100U);
  }

  for (c1_i25 = 0; c1_i25 < 307200; c1_i25 = c1_i25 + 1) {
    (*c1_b_S)[c1_i25] = c1_S[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 307200; c1_i26 = c1_i26 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_S)[c1_i26], 101U);
  }

  sf_call_output_fcn_call(chartInstance.S, 3, "TrackStage1", 0);
  *c1_DesiredHeading = *c1_b_DesiredHeading;
  _SFD_DATA_RANGE_CHECK(*c1_DesiredHeading, 95U);
  *c1_ChangetoRight = *c1_b_ChangetoRight;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoRight, 96U);
  *c1_ChangetoLeft = *c1_b_ChangetoLeft;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoLeft, 97U);
  *c1_ChangetoVertical = *c1_b_ChangetoVertical;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoVertical, 98U);
  *c1_b_ErrorX = *c1_c_ErrorX;
  _SFD_DATA_RANGE_CHECK(*c1_b_ErrorX, 99U);
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,15);
  _SFD_UNSET_DATA_VALUE_PTR(99U);
  _SFD_UNSET_DATA_VALUE_PTR(98U);
  _SFD_UNSET_DATA_VALUE_PTR(97U);
  _SFD_UNSET_DATA_VALUE_PTR(96U);
  _SFD_UNSET_DATA_VALUE_PTR(95U);
  _SFD_UNSET_DATA_VALUE_PTR(101U);
  _SFD_UNSET_DATA_VALUE_PTR(100U);
  _SFD_UNSET_DATA_VALUE_PTR(94U);
  _SFD_UNSET_DATA_VALUE_PTR(93U);
  _SFD_UNSET_DATA_VALUE_PTR(92U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
  sf_debug_symbol_scope_pop();
}

static real_T c1_ErrorCounter(real_T c1_ErrorX5, real_T c1_ErrorCountX5)
{
  real_T c1_ErrorCountX1;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 2.0;
  _SFD_SET_DATA_VALUE_PTR(91U, &c1_ErrorCountX1);
  _SFD_SET_DATA_VALUE_PTR(90U, &c1_ErrorCountX5);
  _SFD_SET_DATA_VALUE_PTR(89U, &c1_ErrorX5);
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorCountX1", &c1_ErrorCountX1, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorCountX5", &c1_ErrorCountX5, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorX5", &c1_ErrorX5, c1_sf_marshall);
  CV_EML_FCN(14, 0);
  _SFD_EML_CALL(14,4);
  if (CV_EML_COND(14, 0, c1_ErrorX5 < 10.0)) {
    if (CV_EML_COND(14, 1, c1_ErrorX5 > -10.0)) {
      CV_EML_MCDC(14, 0, true);
      CV_EML_IF(14, 0, true);
      _SFD_EML_CALL(14,5);
      c1_ErrorCountX1 = c1_ErrorCountX5 + 1.0;
      goto label_1;
    }
  }

  CV_EML_MCDC(14, 0, false);
  CV_EML_IF(14, 0, false);
  _SFD_EML_CALL(14,7);
  c1_ErrorCountX1 = 0.0;
 label_1:
  ;
  _SFD_EML_CALL(14,-7);
  sf_debug_symbol_scope_pop();
  _SFD_UNSET_DATA_VALUE_PTR(91U);
  _SFD_UNSET_DATA_VALUE_PTR(90U);
  _SFD_UNSET_DATA_VALUE_PTR(89U);
  return c1_ErrorCountX1;
}

static void c1_enter_atomic_FindBuoy(void)
{
  int8_T *c1_CameraPosition;
  uint8_T *c1_State;
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  chartInstance.c1_is_Running = (uint8_T)c1_IN_FindBuoy;
  _SFD_CS_CALL(STATE_ACTIVE_TAG,7);
  chartInstance.c1_tp_FindBuoy = 1U;
  sf_call_output_fcn_enable(chartInstance.S, 6, "LookforBuoy", 0);
  sf_call_output_fcn_enable(chartInstance.S, 5, "StraightLevelControl", 0);
  chartInstance.c1_Obstacle = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Obstacle, 7U);
  chartInstance.c1_OldObstacle = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldObstacle, 8U);
  chartInstance.c1_count = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_count, 6U);
  chartInstance.c1_Flag = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_Flag, 14U);
  *c1_CameraPosition = 0;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_CameraPosition, 17U);
  *c1_State = 4U;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
  chartInstance.c1_BuoyCount = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyCount, 29U);
}

static void c1_FindBuoy(void)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  int32_T c1_i27;
  static real_T c1_H[307200];
  int32_T c1_i28;
  static real_T c1_S[307200];
  real_T c1_Image;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_Image;
  real_T c1_OldImage;
  real_T c1_count1;
  real_T c1_count2;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 3.0;
  real32_T c1_CurrentDepth;
  real32_T c1_DesiredDepth;
  real_T c1_DesiredHeading;
  real_T c1_CurrentHeading;
  int8_T c1_ChangetoRight;
  int8_T c1_ChangetoLeft;
  int8_T c1_ChangetoVertical;
  int8_T *c1_DesiredState;
  real_T *c1_b_CurrentDepth;
  real_T *c1_b_DesiredDepth;
  real_T *c1_b_DesiredHeading;
  real_T *c1_b_CurrentHeading;
  uint8_T *c1_State;
  int8_T *c1_Right;
  int8_T *c1_Left;
  int8_T *c1_Vertical;
  real32_T *c1_c_CurrentDepth;
  real32_T *c1_c_DesiredDepth;
  real_T *c1_c_DesiredHeading;
  real_T *c1_c_CurrentHeading;
  int8_T *c1_b_ChangetoVertical;
  int8_T *c1_b_ChangetoLeft;
  int8_T *c1_b_ChangetoRight;
  real_T *c1_c_Image;
  real_T (*c1_b_H)[307200];
  real_T (*c1_b_S)[307200];
  real32_T (*c1_c_S)[307200];
  real32_T (*c1_c_H)[307200];
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_c_Image = (real_T *)ssGetInputPortSignal(chartInstance.S, 30);
  c1_c_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_c_CurrentDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 28);
  c1_b_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_b_ChangetoVertical = (int8_T *)ssGetInputPortSignal(chartInstance.S, 27);
  c1_b_ChangetoLeft = (int8_T *)ssGetInputPortSignal(chartInstance.S, 28);
  c1_c_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
  c1_b_H = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 32);
  c1_b_ChangetoRight = (int8_T *)ssGetInputPortSignal(chartInstance.S, 29);
  c1_b_S = (real_T (*)[307200])ssGetOutputPortSignal(chartInstance.S, 33);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_c_DesiredDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 29);
  c1_b_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_c_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 30);
  c1_b_CurrentDepth = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_c_CurrentHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 31);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,7);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,11);
  c1_temp = (_SFD_CCP_CALL(11,0,((chartInstance.c1_BuoyCount > 2.0)!=0)) != 0);
  if (c1_temp) {
    c1_temp = (_SFD_CCP_CALL(11,1,((*c1_DesiredState == 0)!=0)) != 0);
  }

  if (CV_TRANSITION_EVAL(11U, (int32_T)c1_temp) != 0) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[2];
      unsigned int numTransitions= 1;
      transitionList[0] = 11;
      sf_debug_transition_conflict_check_begin();
      if ((*c1_DesiredState != 4) && (*c1_DesiredState != 0)) {
        transitionList[numTransitions] = 12;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,11);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
    chartInstance.c1_tp_FindBuoy = 0U;
    sf_call_output_fcn_disable(chartInstance.S, 6, "LookforBuoy", 0);
    sf_call_output_fcn_disable(chartInstance.S, 5, "StraightLevelControl", 0);
    _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
    chartInstance.c1_is_Running = (uint8_T)c1_IN_Buoy;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
    chartInstance.c1_tp_Buoy = 1U;
    sf_call_output_fcn_enable(chartInstance.S, 2, "Buoy", 0);
    chartInstance.c1_countarea = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_countarea, 12U);
    *c1_State = 5U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,12);
    c1_b_temp = (_SFD_CCP_CALL(12,0,((*c1_DesiredState != 4)!=0)) != 0);
    if (c1_b_temp) {
      c1_b_temp = (_SFD_CCP_CALL(12,1,((*c1_DesiredState != 0)!=0)) != 0);
    }

    if (CV_TRANSITION_EVAL(12U, (int32_T)c1_b_temp) != 0) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,12);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
      chartInstance.c1_tp_FindBuoy = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 6, "LookforBuoy", 0);
      sf_call_output_fcn_disable(chartInstance.S, 5, "StraightLevelControl", 0);
      _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_ChooseState;
      _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
      chartInstance.c1_tp_ChooseState = 1U;
    } else {
      for (c1_i27 = 0; c1_i27 < 307200; c1_i27 = c1_i27 + 1) {
        c1_H[c1_i27] = (real_T)(*c1_c_H)[c1_i27];
      }

      for (c1_i28 = 0; c1_i28 < 307200; c1_i28 = c1_i28 + 1) {
        c1_S[c1_i28] = (real_T)(*c1_c_S)[c1_i28];
      }

      sf_debug_symbol_scope_push(3U, 0U);
      sf_debug_symbol_scope_add_verbose("Image", 0, 0U, 0U, 0U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 0, 0, &c1_Image);
      sf_debug_symbol_scope_add_verbose("S", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_S);
      sf_debug_symbol_scope_add_verbose("H", 0, 2U, 480U, 640U, 0U, 1.0, 0, 0.0,
        0U, 0, 0U, 1, 0, &c1_H);
      _SFD_SET_DATA_VALUE_PTR(79U, &c1_Image);
      _SFD_SET_DATA_VALUE_PTR(81U, &c1_S);
      _SFD_SET_DATA_VALUE_PTR(80U, &c1_H);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,8);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,8);
      for (c1_i29 = 0; c1_i29 < 307200; c1_i29 = c1_i29 + 1) {
        (*c1_b_H)[c1_i29] = c1_H[c1_i29];
      }

      for (c1_i30 = 0; c1_i30 < 307200; c1_i30 = c1_i30 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_H)[c1_i30], 80U);
      }

      for (c1_i31 = 0; c1_i31 < 307200; c1_i31 = c1_i31 + 1) {
        (*c1_b_S)[c1_i31] = c1_S[c1_i31];
      }

      for (c1_i32 = 0; c1_i32 < 307200; c1_i32 = c1_i32 + 1) {
        _SFD_DATA_RANGE_CHECK((*c1_b_S)[c1_i32], 81U);
      }

      sf_call_output_fcn_call(chartInstance.S, 6, "LookforBuoy", 0);
      c1_Image = *c1_c_Image;
      _SFD_DATA_RANGE_CHECK(c1_Image, 79U);
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,8);
      _SFD_UNSET_DATA_VALUE_PTR(79U);
      _SFD_UNSET_DATA_VALUE_PTR(81U);
      _SFD_UNSET_DATA_VALUE_PTR(80U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
      sf_debug_symbol_scope_pop();
      chartInstance.c1_Obstacle = c1_Image;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_Obstacle, 7U);
      c1_b_Image = chartInstance.c1_Obstacle;
      c1_OldImage = chartInstance.c1_OldObstacle;
      c1_count1 = chartInstance.c1_count;
      _SFD_SET_DATA_VALUE_PTR(78U, &c1_count2);
      _SFD_SET_DATA_VALUE_PTR(77U, &c1_count1);
      _SFD_SET_DATA_VALUE_PTR(76U, &c1_OldImage);
      _SFD_SET_DATA_VALUE_PTR(75U, &c1_b_Image);
      sf_debug_symbol_scope_push(6U, 0U);
      sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
      sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
      sf_debug_symbol_scope_add("count2", &c1_count2, c1_sf_marshall);
      sf_debug_symbol_scope_add("count1", &c1_count1, c1_sf_marshall);
      sf_debug_symbol_scope_add("OldImage", &c1_OldImage, c1_sf_marshall);
      sf_debug_symbol_scope_add("Image", &c1_b_Image, c1_sf_marshall);
      CV_EML_FCN(10, 0);

      /*  This function acts to count the number of consecutive times a particular */
      /*  image is recognized by the recognition software */
      _SFD_EML_CALL(10,5);
      c1_count2 = c1_count1;
      _SFD_EML_CALL(10,6);
      if (CV_EML_COND(10, 0, c1_b_Image != 0.0)) {
        if (CV_EML_COND(10, 1, c1_b_Image == c1_OldImage)) {
          CV_EML_MCDC(10, 0, true);
          CV_EML_IF(10, 0, true);
          _SFD_EML_CALL(10,7);
          c1_count2 = c1_count2 + 1.0;
          goto label_1;
        }
      }

      CV_EML_MCDC(10, 0, false);
      CV_EML_IF(10, 0, false);
      _SFD_EML_CALL(10,9);
      c1_count2 = 0.0;
     label_1:
      ;
      _SFD_EML_CALL(10,-9);
      sf_debug_symbol_scope_pop();
      _SFD_UNSET_DATA_VALUE_PTR(78U);
      _SFD_UNSET_DATA_VALUE_PTR(77U);
      _SFD_UNSET_DATA_VALUE_PTR(76U);
      _SFD_UNSET_DATA_VALUE_PTR(75U);
      chartInstance.c1_BuoyCount = c1_count2;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyCount, 29U);
      c1_CurrentDepth = (real32_T)*c1_b_CurrentDepth;
      c1_DesiredDepth = (real32_T)*c1_b_DesiredDepth;
      c1_DesiredHeading = *c1_b_DesiredHeading;
      c1_CurrentHeading = *c1_b_CurrentHeading;
      sf_debug_symbol_scope_push(7U, 0U);
      sf_debug_symbol_scope_add_verbose("ChangetoRight", 2, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoRight);
      sf_debug_symbol_scope_add_verbose("ChangetoLeft", 2, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoLeft);
      sf_debug_symbol_scope_add_verbose("ChangetoVertical", 2, 0U, 0U, 0U, 0U,
        1.0, 0, 0.0, 0U, 0, 0U, 0, 0, &c1_ChangetoVertical);
      sf_debug_symbol_scope_add_verbose("CurrentHeading", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentHeading);
      sf_debug_symbol_scope_add_verbose("DesiredHeading", 0, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_DesiredHeading);
      sf_debug_symbol_scope_add_verbose("DesiredDepth", 1, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_DesiredDepth);
      sf_debug_symbol_scope_add_verbose("CurrentDepth", 1, 0U, 0U, 0U, 0U, 1.0,
        0, 0.0, 0U, 0, 0U, 0, 0, &c1_CurrentDepth);
      _SFD_SET_DATA_VALUE_PTR(88U, &c1_ChangetoRight);
      _SFD_SET_DATA_VALUE_PTR(87U, &c1_ChangetoLeft);
      _SFD_SET_DATA_VALUE_PTR(86U, &c1_ChangetoVertical);
      _SFD_SET_DATA_VALUE_PTR(85U, &c1_CurrentHeading);
      _SFD_SET_DATA_VALUE_PTR(84U, &c1_DesiredHeading);
      _SFD_SET_DATA_VALUE_PTR(83U, &c1_DesiredDepth);
      _SFD_SET_DATA_VALUE_PTR(82U, &c1_CurrentDepth);
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,9);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,9);
      *c1_c_CurrentDepth = c1_CurrentDepth;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_CurrentDepth, 82U);
      *c1_c_DesiredDepth = c1_DesiredDepth;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_DesiredDepth, 83U);
      *c1_c_DesiredHeading = c1_DesiredHeading;
      _SFD_DATA_RANGE_CHECK(*c1_c_DesiredHeading, 84U);
      *c1_c_CurrentHeading = c1_CurrentHeading;
      _SFD_DATA_RANGE_CHECK(*c1_c_CurrentHeading, 85U);
      sf_call_output_fcn_call(chartInstance.S, 5, "StraightLevelControl", 0);
      c1_ChangetoVertical = *c1_b_ChangetoVertical;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoVertical, 86U);
      c1_ChangetoLeft = *c1_b_ChangetoLeft;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoLeft, 87U);
      c1_ChangetoRight = *c1_b_ChangetoRight;
      _SFD_DATA_RANGE_CHECK((real_T)c1_ChangetoRight, 88U);
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,9);
      _SFD_UNSET_DATA_VALUE_PTR(88U);
      _SFD_UNSET_DATA_VALUE_PTR(87U);
      _SFD_UNSET_DATA_VALUE_PTR(86U);
      _SFD_UNSET_DATA_VALUE_PTR(85U);
      _SFD_UNSET_DATA_VALUE_PTR(84U);
      _SFD_UNSET_DATA_VALUE_PTR(83U);
      _SFD_UNSET_DATA_VALUE_PTR(82U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
      sf_debug_symbol_scope_pop();
      *c1_Vertical = c1_ChangetoVertical;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
      *c1_Left = c1_ChangetoLeft;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
      *c1_Right = c1_ChangetoRight;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
      chartInstance.c1_OldObstacle = chartInstance.c1_Obstacle;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldObstacle, 8U);
      chartInstance.c1_count = chartInstance.c1_BuoyCount;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_count, 6U);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
}

static void c1_DirectionalControl(real32_T c1_CurrentDepth, real32_T
  c1_DesiredDepth, real_T c1_DesiredHeading, real_T
  c1_CurrentHeading, int8_T *c1_ChangetoVertical, int8_T *c1_ChangetoLeft,
  int8_T *c1_ChangetoRight, real_T *c1_ErrorHeading1)
{
  real32_T *c1_b_CurrentDepth;
  real32_T *c1_b_DesiredDepth;
  real_T *c1_b_DesiredHeading;
  real_T *c1_b_CurrentHeading;
  int8_T *c1_b_ChangetoVertical;
  int8_T *c1_b_ChangetoLeft;
  int8_T *c1_b_ChangetoRight;
  real_T *c1_b_ErrorHeading1;
  c1_b_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 36);
  c1_b_CurrentHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 37);
  c1_b_ChangetoRight = (int8_T *)ssGetInputPortSignal(chartInstance.S, 33);
  c1_b_DesiredDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 35);
  c1_b_ChangetoVertical = (int8_T *)ssGetInputPortSignal(chartInstance.S, 31);
  c1_b_CurrentDepth = (real32_T *)ssGetOutputPortSignal(chartInstance.S, 34);
  c1_b_ErrorHeading1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 34);
  c1_b_ChangetoLeft = (int8_T *)ssGetInputPortSignal(chartInstance.S, 32);
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add_verbose("ErrorHeading1", 0, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_ErrorHeading1);
  sf_debug_symbol_scope_add_verbose("ChangetoRight", 2, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_ChangetoRight);
  sf_debug_symbol_scope_add_verbose("ChangetoLeft", 2, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, c1_ChangetoLeft);
  sf_debug_symbol_scope_add_verbose("ChangetoVertical", 2, 0U, 0U, 0U, 0U, 1.0,
    0, 0.0, 0U, 0, 0U, 0, 0, c1_ChangetoVertical);
  sf_debug_symbol_scope_add_verbose("CurrentHeading", 0, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_CurrentHeading);
  sf_debug_symbol_scope_add_verbose("DesiredHeading", 0, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_DesiredHeading);
  sf_debug_symbol_scope_add_verbose("DesiredDepth", 1, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_DesiredDepth);
  sf_debug_symbol_scope_add_verbose("CurrentDepth", 1, 0U, 0U, 0U, 0U, 1.0, 0,
    0.0, 0U, 0, 0U, 0, 0, &c1_CurrentDepth);
  _SFD_SET_DATA_VALUE_PTR(125U, c1_ErrorHeading1);
  _SFD_SET_DATA_VALUE_PTR(124U, c1_ChangetoRight);
  _SFD_SET_DATA_VALUE_PTR(123U, c1_ChangetoLeft);
  _SFD_SET_DATA_VALUE_PTR(122U, c1_ChangetoVertical);
  _SFD_SET_DATA_VALUE_PTR(121U, &c1_CurrentHeading);
  _SFD_SET_DATA_VALUE_PTR(120U, &c1_DesiredHeading);
  _SFD_SET_DATA_VALUE_PTR(119U, &c1_DesiredDepth);
  _SFD_SET_DATA_VALUE_PTR(118U, &c1_CurrentDepth);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG,20);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,20);
  *c1_b_CurrentDepth = c1_CurrentDepth;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_CurrentDepth, 118U);
  *c1_b_DesiredDepth = c1_DesiredDepth;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_DesiredDepth, 119U);
  *c1_b_DesiredHeading = c1_DesiredHeading;
  _SFD_DATA_RANGE_CHECK(*c1_b_DesiredHeading, 120U);
  *c1_b_CurrentHeading = c1_CurrentHeading;
  _SFD_DATA_RANGE_CHECK(*c1_b_CurrentHeading, 121U);
  sf_call_output_fcn_call(chartInstance.S, 7, "DirectionalControl", 0);
  *c1_ChangetoVertical = *c1_b_ChangetoVertical;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoVertical, 122U);
  *c1_ChangetoLeft = *c1_b_ChangetoLeft;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoLeft, 123U);
  *c1_ChangetoRight = *c1_b_ChangetoRight;
  _SFD_DATA_RANGE_CHECK((real_T)*c1_ChangetoRight, 124U);
  *c1_ErrorHeading1 = *c1_b_ErrorHeading1;
  _SFD_DATA_RANGE_CHECK(*c1_ErrorHeading1, 125U);
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG,20);
  _SFD_UNSET_DATA_VALUE_PTR(125U);
  _SFD_UNSET_DATA_VALUE_PTR(124U);
  _SFD_UNSET_DATA_VALUE_PTR(123U);
  _SFD_UNSET_DATA_VALUE_PTR(122U);
  _SFD_UNSET_DATA_VALUE_PTR(121U);
  _SFD_UNSET_DATA_VALUE_PTR(120U);
  _SFD_UNSET_DATA_VALUE_PTR(119U);
  _SFD_UNSET_DATA_VALUE_PTR(118U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,20);
  sf_debug_symbol_scope_pop();
}

static real_T c1_b_ErrorCounter(real_T c1_ErrorX5, real_T c1_ErrorCountX5)
{
  real_T c1_ErrorCountX1;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 2.0;
  _SFD_SET_DATA_VALUE_PTR(117U, &c1_ErrorCountX1);
  _SFD_SET_DATA_VALUE_PTR(116U, &c1_ErrorCountX5);
  _SFD_SET_DATA_VALUE_PTR(115U, &c1_ErrorX5);
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorCountX1", &c1_ErrorCountX1, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorCountX5", &c1_ErrorCountX5, c1_sf_marshall);
  sf_debug_symbol_scope_add("ErrorX5", &c1_ErrorX5, c1_sf_marshall);
  CV_EML_FCN(21, 0);
  _SFD_EML_CALL(21,4);
  if (CV_EML_COND(21, 0, c1_ErrorX5 < 5.0)) {
    if (CV_EML_COND(21, 1, c1_ErrorX5 > -5.0)) {
      CV_EML_MCDC(21, 0, true);
      CV_EML_IF(21, 0, true);
      _SFD_EML_CALL(21,5);
      c1_ErrorCountX1 = c1_ErrorCountX5 + 1.0;
      goto label_1;
    }
  }

  CV_EML_MCDC(21, 0, false);
  CV_EML_IF(21, 0, false);
  _SFD_EML_CALL(21,7);
  c1_ErrorCountX1 = 0.0;
 label_1:
  ;
  _SFD_EML_CALL(21,-7);
  sf_debug_symbol_scope_pop();
  _SFD_UNSET_DATA_VALUE_PTR(117U);
  _SFD_UNSET_DATA_VALUE_PTR(116U);
  _SFD_UNSET_DATA_VALUE_PTR(115U);
  return c1_ErrorCountX1;
}

static void c1_Running(void)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  real_T c1_CurrentHeading1;
  real_T c1_OldHeading1;
  real_T c1_count1;
  real_T c1_DesiredHeadingCount1;
  real_T c1_nargout = 1.0;
  real_T c1_nargin = 3.0;
  real_T c1_tolerance;
  int8_T *c1_Status;
  int8_T *c1_DesiredState;
  real_T *c1_CurrentHeading;
  real_T *c1_DesiredDepth;
  real_T *c1_DesiredHeading;
  int8_T *c1_Left;
  int8_T *c1_Right;
  int8_T *c1_Vertical;
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c1_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_Status = (int8_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,2);
  if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2,0,((*c1_Status != 1)!=0)))
      != 0) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,2);
    switch (chartInstance.c1_is_Running) {
     case c1_IN_Buoy:
      CV_STATE_EVAL(1,1,1);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,2);
      chartInstance.c1_BuoyDone = 1.0;
      _SFD_DATA_RANGE_CHECK(chartInstance.c1_BuoyDone, 11U);
      chartInstance.c1_tp_Buoy = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 2, "Buoy", 0);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
      break;

     case c1_IN_ChooseState:
      CV_STATE_EVAL(1,1,2);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
      chartInstance.c1_tp_ChooseState = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
      break;

     case c1_IN_FindBuoy:
      CV_STATE_EVAL(1,1,3);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,7);
      chartInstance.c1_tp_FindBuoy = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 6, "LookforBuoy", 0);
      sf_call_output_fcn_disable(chartInstance.S, 5, "StraightLevelControl", 0);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,7);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,7);
      break;

     case c1_IN_Finish:
      CV_STATE_EVAL(1,1,4);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,11);
      chartInstance.c1_tp_Finish = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,11);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
      break;

     case c1_IN_FollowTrack:
      CV_STATE_EVAL(1,1,5);
      c1_exit_internal_FollowTrack();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,12);
      chartInstance.c1_tp_FollowTrack = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,12);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
      break;

     case c1_IN_Start:
      CV_STATE_EVAL(1,1,6);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,22);
      *c1_DesiredHeading = *c1_CurrentHeading;
      _SFD_DATA_RANGE_CHECK(*c1_DesiredHeading, 9U);
      chartInstance.c1_tp_Start = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
      break;

     case c1_IN_ValidationGate:
      CV_STATE_EVAL(1,1,7);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,24);
      chartInstance.c1_tp_ValidationGate = 0U;
      sf_call_output_fcn_disable(chartInstance.S, 0, "LookforTrack", 0);
      sf_call_output_fcn_disable(chartInstance.S, 1, "StraightLevelControl", 0);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,24);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,24);
      break;

     default:
      CV_STATE_EVAL(1,1,0);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
      break;
    }

    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,1);
    chartInstance.c1_tp_Running = 0U;
    chartInstance.c1_is_c1_brain = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,1);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
    chartInstance.c1_is_c1_brain = (uint8_T)c1_IN_NotRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,0);
    chartInstance.c1_tp_NotRunning = 1U;
    *c1_Left = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Left, 3U);
    *c1_Right = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Right, 2U);
    *c1_Vertical = 0;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_Vertical, 4U);
  } else {
    switch (chartInstance.c1_is_Running) {
     case c1_IN_Buoy:
      CV_STATE_EVAL(1,0,1);
      c1_Buoy();
      break;

     case c1_IN_ChooseState:
      CV_STATE_EVAL(1,0,2);
      c1_ChooseState();
      break;

     case c1_IN_FindBuoy:
      CV_STATE_EVAL(1,0,3);
      c1_FindBuoy();
      break;

     case c1_IN_Finish:
      CV_STATE_EVAL(1,0,4);
      break;

     case c1_IN_FollowTrack:
      CV_STATE_EVAL(1,0,5);
      c1_FollowTrack();
      break;

     case c1_IN_Start:
      CV_STATE_EVAL(1,0,6);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,22);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,18);
      c1_temp = (_SFD_CCP_CALL(18,0,((chartInstance.c1_DesiredHeadingCount >=
        3.0)!=0)) != 0);
      if (c1_temp) {
        c1_temp = (_SFD_CCP_CALL(18,1,((*c1_DesiredState == 0)!=0)) != 0);
      }

      if (CV_TRANSITION_EVAL(18U, (int32_T)c1_temp) != 0) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions= 1;
          transitionList[0] = 18;
          sf_debug_transition_conflict_check_begin();
          if ((*c1_DesiredState != 1) && (*c1_DesiredState != 0)) {
            transitionList[numTransitions] = 19;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,18);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,22);
        *c1_DesiredHeading = *c1_CurrentHeading;
        _SFD_DATA_RANGE_CHECK(*c1_DesiredHeading, 9U);
        chartInstance.c1_tp_Start = 0U;
        chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
        c1_enter_atomic_ValidationGate();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,19);
        c1_b_temp = (_SFD_CCP_CALL(19,0,((*c1_DesiredState != 1)!=0)) != 0);
        if (c1_b_temp) {
          c1_b_temp = (_SFD_CCP_CALL(19,1,((*c1_DesiredState != 0)!=0)) != 0);
        }

        if (CV_TRANSITION_EVAL(19U, (int32_T)c1_b_temp) != 0) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,19);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,22);
          *c1_DesiredHeading = *c1_CurrentHeading;
          _SFD_DATA_RANGE_CHECK(*c1_DesiredHeading, 9U);
          chartInstance.c1_tp_Start = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,22);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
          chartInstance.c1_is_Running = (uint8_T)c1_IN_ChooseState;
          _SFD_CS_CALL(STATE_ACTIVE_TAG,6);
          chartInstance.c1_tp_ChooseState = 1U;
        } else {
          c1_CurrentHeading1 = *c1_CurrentHeading;
          c1_OldHeading1 = chartInstance.c1_OldHeading;
          c1_count1 = chartInstance.c1_DesiredHeadingCount;
          _SFD_SET_DATA_VALUE_PTR(39U, &c1_DesiredHeadingCount1);
          _SFD_SET_DATA_VALUE_PTR(41U, &c1_count1);
          _SFD_SET_DATA_VALUE_PTR(40U, &c1_OldHeading1);
          _SFD_SET_DATA_VALUE_PTR(38U, &c1_CurrentHeading1);
          sf_debug_symbol_scope_push(7U, 0U);
          sf_debug_symbol_scope_add("nargout", &c1_nargout, c1_sf_marshall);
          sf_debug_symbol_scope_add("nargin", &c1_nargin, c1_sf_marshall);
          sf_debug_symbol_scope_add("tolerance", &c1_tolerance, c1_sf_marshall);
          sf_debug_symbol_scope_add("DesiredHeadingCount1",
            &c1_DesiredHeadingCount1, c1_sf_marshall);
          sf_debug_symbol_scope_add("count1", &c1_count1, c1_sf_marshall);
          sf_debug_symbol_scope_add("OldHeading1", &c1_OldHeading1,
            c1_sf_marshall);
          sf_debug_symbol_scope_add("CurrentHeading1", &c1_CurrentHeading1,
            c1_sf_marshall);
          CV_EML_FCN(23, 0);
          _SFD_EML_CALL(23,3);
          c1_tolerance = 2.0;
          _SFD_EML_CALL(23,5);
          if (CV_EML_COND(23, 0, c1_CurrentHeading1 > c1_OldHeading1 -
                          c1_tolerance)) {
            if (CV_EML_COND(23, 1, c1_CurrentHeading1 < c1_OldHeading1 +
                            c1_tolerance)) {
              CV_EML_MCDC(23, 0, true);
              CV_EML_IF(23, 0, true);
              _SFD_EML_CALL(23,6);
              c1_count1 = c1_count1 + 1.0;
              goto label_1;
            }
          }

          CV_EML_MCDC(23, 0, false);
          CV_EML_IF(23, 0, false);
          _SFD_EML_CALL(23,8);
          c1_count1 = 0.0;
         label_1:
          ;
          _SFD_EML_CALL(23,10);
          c1_DesiredHeadingCount1 = c1_count1;
          _SFD_EML_CALL(23,-10);
          sf_debug_symbol_scope_pop();
          _SFD_UNSET_DATA_VALUE_PTR(39U);
          _SFD_UNSET_DATA_VALUE_PTR(41U);
          _SFD_UNSET_DATA_VALUE_PTR(40U);
          _SFD_UNSET_DATA_VALUE_PTR(38U);
          chartInstance.c1_DesiredHeadingCount = c1_DesiredHeadingCount1;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_DesiredHeadingCount, 23U);
          chartInstance.c1_OldHeading = *c1_CurrentHeading;
          _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldHeading, 24U);
          *c1_DesiredDepth = 5.0;
          _SFD_DATA_RANGE_CHECK(*c1_DesiredDepth, 5U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,22);
      break;

     case c1_IN_ValidationGate:
      CV_STATE_EVAL(1,0,7);
      c1_ValidationGate();
      break;

     default:
      CV_STATE_EVAL(1,0,0);
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,2);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void c1_ChooseState(void)
{
  boolean_T c1_temp;
  int8_T *c1_DesiredState;
  uint8_T *c1_State;
  real_T *c1_BuoyCentroidX;
  real_T *c1_BuoyCentroidY;
  int8_T *c1_CameraPosition;
  c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
  c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
  c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG,6);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,6);
  c1_temp = (_SFD_CCP_CALL(6,0,((*c1_DesiredState == 1)!=0)) != 0);
  if (!c1_temp) {
    c1_temp = (_SFD_CCP_CALL(6,1,((*c1_DesiredState == 0)!=0)) != 0);
  }

  if (CV_TRANSITION_EVAL(6U, (int32_T)c1_temp) != 0) {
    if (sf_debug_transition_conflict_check_enabled()) {
      unsigned int transitionList[5];
      unsigned int numTransitions= 1;
      transitionList[0] = 6;
      sf_debug_transition_conflict_check_begin();
      if (*c1_DesiredState == 2) {
        transitionList[numTransitions] = 7;
        numTransitions++;
      }

      if (*c1_DesiredState == 3) {
        transitionList[numTransitions] = 8;
        numTransitions++;
      }

      if (*c1_DesiredState == 4) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }

      if (*c1_DesiredState == 5) {
        transitionList[numTransitions] = 10;
        numTransitions++;
      }

      sf_debug_transition_conflict_check_end();
      if (numTransitions>1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,6);
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
    chartInstance.c1_tp_ChooseState = 0U;
    chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
    chartInstance.c1_is_Running = (uint8_T)c1_IN_Start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG,22);
    chartInstance.c1_tp_Start = 1U;
    chartInstance.c1_OldHeading = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_OldHeading, 24U);
    chartInstance.c1_DesiredHeadingCount = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance.c1_DesiredHeadingCount, 23U);
    *c1_BuoyCentroidX = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidX, 21U);
    *c1_BuoyCentroidY = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_BuoyCentroidY, 22U);
    *c1_CameraPosition = 2;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_CameraPosition, 17U);
    *c1_State = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,7);
    if (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7,0,((*c1_DesiredState ==
            2)!=0))) != 0) {
      if (sf_debug_transition_conflict_check_enabled()) {
        unsigned int transitionList[4];
        unsigned int numTransitions= 1;
        transitionList[0] = 7;
        sf_debug_transition_conflict_check_begin();
        if (*c1_DesiredState == 3) {
          transitionList[numTransitions] = 8;
          numTransitions++;
        }

        if (*c1_DesiredState == 4) {
          transitionList[numTransitions] = 9;
          numTransitions++;
        }

        if (*c1_DesiredState == 5) {
          transitionList[numTransitions] = 10;
          numTransitions++;
        }

        sf_debug_transition_conflict_check_end();
        if (numTransitions>1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,7);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
      chartInstance.c1_tp_ChooseState = 0U;
      chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
      c1_enter_atomic_ValidationGate();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,8);
      if (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8,0,((*c1_DesiredState ==
              3)!=0))) != 0) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[3];
          unsigned int numTransitions= 1;
          transitionList[0] = 8;
          sf_debug_transition_conflict_check_begin();
          if (*c1_DesiredState == 4) {
            transitionList[numTransitions] = 9;
            numTransitions++;
          }

          if (*c1_DesiredState == 5) {
            transitionList[numTransitions] = 10;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions>1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,8);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
        chartInstance.c1_tp_ChooseState = 0U;
        chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
        chartInstance.c1_is_Running = (uint8_T)c1_IN_FollowTrack;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,12);
        chartInstance.c1_tp_FollowTrack = 1U;
        chartInstance.c1_ErrorCountHeading = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountHeading, 31U);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,15);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,15);
        chartInstance.c1_is_FollowTrack = (uint8_T)c1_IN_Stage1Aim;
        _SFD_CS_CALL(STATE_ACTIVE_TAG,13);
        chartInstance.c1_tp_Stage1Aim = 1U;
        sf_call_output_fcn_enable(chartInstance.S, 3, "TrackStage1", 0);
        chartInstance.c1_ErrorCountX = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance.c1_ErrorCountX, 32U);
        *c1_State = 3U;
        _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,9);
        if (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9,0,((*c1_DesiredState
                == 4)!=0))) != 0) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions= 1;
            transitionList[0] = 9;
            sf_debug_transition_conflict_check_begin();
            if (*c1_DesiredState == 5) {
              transitionList[numTransitions] = 10;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions>1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,9);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
          chartInstance.c1_tp_ChooseState = 0U;
          chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
          c1_enter_atomic_FindBuoy();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG,10);
          if (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10,0,
                ((*c1_DesiredState == 5)!=0))) != 0) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG,10);
            _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG,6);
            chartInstance.c1_tp_ChooseState = 0U;
            chartInstance.c1_is_Running = (uint8_T)c1_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG,6);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
            chartInstance.c1_is_Running = (uint8_T)c1_IN_Buoy;
            _SFD_CS_CALL(STATE_ACTIVE_TAG,2);
            chartInstance.c1_tp_Buoy = 1U;
            sf_call_output_fcn_enable(chartInstance.S, 2, "Buoy", 0);
            chartInstance.c1_countarea = 0.0;
            _SFD_DATA_RANGE_CHECK(chartInstance.c1_countarea, 12U);
            *c1_State = 5U;
            _SFD_DATA_RANGE_CHECK((real_T)*c1_State, 35U);
          } else {
            goto label_1;
          }
        }
      }
    }
  }

 label_1:
  ;
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_brain_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[7];
  c1_ResolvedFunctionInfo (*c1_b_info)[7];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i33;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[7])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "uminus";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved = "[B]uminus";
  (*c1_b_info)[0].fileLength = 0U;
  (*c1_b_info)[0].fileTime1 = 0U;
  (*c1_b_info)[0].fileTime2 = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "eq";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved = "[B]eq";
  (*c1_b_info)[1].fileLength = 0U;
  (*c1_b_info)[1].fileTime1 = 0U;
  (*c1_b_info)[1].fileTime2 = 0U;
  (*c1_b_info)[2].context = "";
  (*c1_b_info)[2].name = "minus";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved = "[B]minus";
  (*c1_b_info)[2].fileLength = 0U;
  (*c1_b_info)[2].fileTime1 = 0U;
  (*c1_b_info)[2].fileTime2 = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "gt";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved = "[B]gt";
  (*c1_b_info)[3].fileLength = 0U;
  (*c1_b_info)[3].fileTime1 = 0U;
  (*c1_b_info)[3].fileTime2 = 0U;
  (*c1_b_info)[4].context = "";
  (*c1_b_info)[4].name = "plus";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved = "[B]plus";
  (*c1_b_info)[4].fileLength = 0U;
  (*c1_b_info)[4].fileTime1 = 0U;
  (*c1_b_info)[4].fileTime2 = 0U;
  (*c1_b_info)[5].context = "";
  (*c1_b_info)[5].name = "lt";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved = "[B]lt";
  (*c1_b_info)[5].fileLength = 0U;
  (*c1_b_info)[5].fileTime1 = 0U;
  (*c1_b_info)[5].fileTime2 = 0U;
  (*c1_b_info)[6].context = "";
  (*c1_b_info)[6].name = "ne";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved = "[B]ne";
  (*c1_b_info)[6].fileLength = 0U;
  (*c1_b_info)[6].fileTime1 = 0U;
  (*c1_b_info)[6].fileTime2 = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7));
  for (c1_i33 = 0; c1_i33 < 7; c1_i33 = c1_i33 + 1) {
    c1_r0 = &c1_info[c1_i33];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i33);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i33
                    );
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i33
                    );
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_emlrt_marshallOut(int8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0));
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  return c1_y;
}

static real_T c1_emlrt_marshallIn(const mxArray *c1_BuoyCentroidX, char *c1_name)
{
  real_T c1_y;
  real_T c1_d5;
  sf_mex_import(c1_name, sf_mex_dup(c1_BuoyCentroidX), &c1_d5, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d5;
  sf_mex_destroy(&c1_BuoyCentroidX);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(const mxArray *c1_BuoyCentroidY, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d6;
  sf_mex_import(c1_name, sf_mex_dup(c1_BuoyCentroidY), &c1_d6, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d6;
  sf_mex_destroy(&c1_BuoyCentroidY);
  return c1_y;
}

static int8_T c1_c_emlrt_marshallIn(const mxArray *c1_CameraPosition, char
  *c1_name)
{
  int8_T c1_y;
  int8_T c1_i34;
  sf_mex_import(c1_name, sf_mex_dup(c1_CameraPosition), &c1_i34, 1, 2, 0U, 0, 0U,
                0);
  c1_y = c1_i34;
  sf_mex_destroy(&c1_CameraPosition);
  return c1_y;
}

static real_T c1_d_emlrt_marshallIn(const mxArray *c1_DesiredDepth, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d7;
  sf_mex_import(c1_name, sf_mex_dup(c1_DesiredDepth), &c1_d7, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d7;
  sf_mex_destroy(&c1_DesiredDepth);
  return c1_y;
}

static real_T c1_e_emlrt_marshallIn(const mxArray *c1_DesiredHeading, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d8;
  sf_mex_import(c1_name, sf_mex_dup(c1_DesiredHeading), &c1_d8, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d8;
  sf_mex_destroy(&c1_DesiredHeading);
  return c1_y;
}

static int8_T c1_f_emlrt_marshallIn(const mxArray *c1_Left, char *c1_name)
{
  int8_T c1_y;
  int8_T c1_i35;
  sf_mex_import(c1_name, sf_mex_dup(c1_Left), &c1_i35, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i35;
  sf_mex_destroy(&c1_Left);
  return c1_y;
}

static int8_T c1_g_emlrt_marshallIn(const mxArray *c1_Right, char *c1_name)
{
  int8_T c1_y;
  int8_T c1_i36;
  sf_mex_import(c1_name, sf_mex_dup(c1_Right), &c1_i36, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i36;
  sf_mex_destroy(&c1_Right);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(const mxArray *c1_State, char *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_State), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_State);
  return c1_y;
}

static int8_T c1_i_emlrt_marshallIn(const mxArray *c1_Vertical, char *c1_name)
{
  int8_T c1_y;
  int8_T c1_i37;
  sf_mex_import(c1_name, sf_mex_dup(c1_Vertical), &c1_i37, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i37;
  sf_mex_destroy(&c1_Vertical);
  return c1_y;
}

static real_T c1_j_emlrt_marshallIn(const mxArray *c1_b_Area, char *c1_name)
{
  real_T c1_y;
  real_T c1_d9;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_Area), &c1_d9, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d9;
  sf_mex_destroy(&c1_b_Area);
  return c1_y;
}

static real_T c1_k_emlrt_marshallIn(const mxArray *c1_b_BuoyCount, char *c1_name)
{
  real_T c1_y;
  real_T c1_d10;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_BuoyCount), &c1_d10, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d10;
  sf_mex_destroy(&c1_b_BuoyCount);
  return c1_y;
}

static real_T c1_l_emlrt_marshallIn(const mxArray *c1_b_BuoyDone, char *c1_name)
{
  real_T c1_y;
  real_T c1_d11;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_BuoyDone), &c1_d11, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d11;
  sf_mex_destroy(&c1_b_BuoyDone);
  return c1_y;
}

static real_T c1_m_emlrt_marshallIn(const mxArray *c1_b_CentroidX, char *c1_name)
{
  real_T c1_y;
  real_T c1_d12;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_CentroidX), &c1_d12, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d12;
  sf_mex_destroy(&c1_b_CentroidX);
  return c1_y;
}

static real_T c1_n_emlrt_marshallIn(const mxArray *c1_b_CentroidY, char *c1_name)
{
  real_T c1_y;
  real_T c1_d13;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_CentroidY), &c1_d13, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d13;
  sf_mex_destroy(&c1_b_CentroidY);
  return c1_y;
}

static real_T c1_o_emlrt_marshallIn(const mxArray *c1_b_DesiredHeadingCount,
  char *c1_name)
{
  real_T c1_y;
  real_T c1_d14;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_DesiredHeadingCount), &c1_d14, 1, 0, 0U,
                0, 0U, 0);
  c1_y = c1_d14;
  sf_mex_destroy(&c1_b_DesiredHeadingCount);
  return c1_y;
}

static real_T c1_p_emlrt_marshallIn(const mxArray *c1_b_ErrorCount, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d15;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorCount), &c1_d15, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d15;
  sf_mex_destroy(&c1_b_ErrorCount);
  return c1_y;
}

static real_T c1_q_emlrt_marshallIn(const mxArray *c1_b_ErrorCountHeading, char *
  c1_name)
{
  real_T c1_y;
  real_T c1_d16;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorCountHeading), &c1_d16, 1, 0, 0U,
                0, 0U, 0);
  c1_y = c1_d16;
  sf_mex_destroy(&c1_b_ErrorCountHeading);
  return c1_y;
}

static real_T c1_r_emlrt_marshallIn(const mxArray *c1_b_ErrorCountX, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d17;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorCountX), &c1_d17, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d17;
  sf_mex_destroy(&c1_b_ErrorCountX);
  return c1_y;
}

static real_T c1_s_emlrt_marshallIn(const mxArray *c1_b_ErrorCountY, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d18;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorCountY), &c1_d18, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d18;
  sf_mex_destroy(&c1_b_ErrorCountY);
  return c1_y;
}

static real_T c1_t_emlrt_marshallIn(const mxArray *c1_b_ErrorHeading, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d19;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorHeading), &c1_d19, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d19;
  sf_mex_destroy(&c1_b_ErrorHeading);
  return c1_y;
}

static real_T c1_u_emlrt_marshallIn(const mxArray *c1_b_ErrorX, char *c1_name)
{
  real_T c1_y;
  real_T c1_d20;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorX), &c1_d20, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d20;
  sf_mex_destroy(&c1_b_ErrorX);
  return c1_y;
}

static real_T c1_v_emlrt_marshallIn(const mxArray *c1_b_ErrorY, char *c1_name)
{
  real_T c1_y;
  real_T c1_d21;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ErrorY), &c1_d21, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d21;
  sf_mex_destroy(&c1_b_ErrorY);
  return c1_y;
}

static real_T c1_w_emlrt_marshallIn(const mxArray *c1_b_Flag, char *c1_name)
{
  real_T c1_y;
  real_T c1_d22;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_Flag), &c1_d22, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d22;
  sf_mex_destroy(&c1_b_Flag);
  return c1_y;
}

static real_T c1_x_emlrt_marshallIn(const mxArray *c1_b_Obstacle, char *c1_name)
{
  real_T c1_y;
  real_T c1_d23;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_Obstacle), &c1_d23, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d23;
  sf_mex_destroy(&c1_b_Obstacle);
  return c1_y;
}

static real_T c1_y_emlrt_marshallIn(const mxArray *c1_b_OldHeading, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d24;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_OldHeading), &c1_d24, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d24;
  sf_mex_destroy(&c1_b_OldHeading);
  return c1_y;
}

static real_T c1_ab_emlrt_marshallIn(const mxArray *c1_b_OldObstacle, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d25;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_OldObstacle), &c1_d25, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d25;
  sf_mex_destroy(&c1_b_OldObstacle);
  return c1_y;
}

static real_T c1_bb_emlrt_marshallIn(const mxArray *c1_b_ResetSwitch, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d26;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_ResetSwitch), &c1_d26, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d26;
  sf_mex_destroy(&c1_b_ResetSwitch);
  return c1_y;
}

static real_T c1_cb_emlrt_marshallIn(const mxArray *c1_b_TrackCount, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d27;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_TrackCount), &c1_d27, 1, 0, 0U, 0, 0U,
                0);
  c1_y = c1_d27;
  sf_mex_destroy(&c1_b_TrackCount);
  return c1_y;
}

static real_T c1_db_emlrt_marshallIn(const mxArray *c1_b_count, char *c1_name)
{
  real_T c1_y;
  real_T c1_d28;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_count), &c1_d28, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d28;
  sf_mex_destroy(&c1_b_count);
  return c1_y;
}

static real_T c1_eb_emlrt_marshallIn(const mxArray *c1_b_countarea, char
  *c1_name)
{
  real_T c1_y;
  real_T c1_d29;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_countarea), &c1_d29, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d29;
  sf_mex_destroy(&c1_b_countarea);
  return c1_y;
}

static real_T c1_fb_emlrt_marshallIn(const mxArray *c1_b_track1, char *c1_name)
{
  real_T c1_y;
  real_T c1_d30;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_track1), &c1_d30, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d30;
  sf_mex_destroy(&c1_b_track1);
  return c1_y;
}

static uint8_T c1_gb_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_brain,
  char *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_brain), &c1_u1, 1, 3, 0U,
                0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_b_is_active_c1_brain);
  return c1_y;
}

static uint8_T c1_hb_emlrt_marshallIn(const mxArray *c1_b_is_c1_brain, char
  *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u2;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_c1_brain), &c1_u2, 1, 3, 0U, 0, 0U,
                0);
  c1_y = c1_u2;
  sf_mex_destroy(&c1_b_is_c1_brain);
  return c1_y;
}

static uint8_T c1_ib_emlrt_marshallIn(const mxArray *c1_b_is_FollowTrack, char
  *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u3;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_FollowTrack), &c1_u3, 1, 3, 0U, 0,
                0U, 0);
  c1_y = c1_u3;
  sf_mex_destroy(&c1_b_is_FollowTrack);
  return c1_y;
}

static uint8_T c1_jb_emlrt_marshallIn(const mxArray *c1_b_is_Running, char
  *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u4;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_Running), &c1_u4, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u4;
  sf_mex_destroy(&c1_b_is_Running);
  return c1_y;
}

static const mxArray *c1_kb_emlrt_marshallIn(const mxArray
  *c1_b_setSimStateSideEffectsInfo, char *c1_name)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe
                (&c1_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static int8_T c1__s8_d_(real_T c1_b)
{
  int8_T c1_a;
  c1_a = (int8_T)c1_b;
  if ((real_T)c1_a != (c1_b < 0.0 ? muDoubleScalarCeil((real_T)c1_b) :
                       muDoubleScalarFloor((real_T)c1_b))) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c1_a;
}

static void init_test_point_addr_map(void)
{
  chartInstance.c1_testPointAddrMap[0] = &chartInstance.c1_count;
  chartInstance.c1_testPointAddrMap[1] = &chartInstance.c1_Obstacle;
  chartInstance.c1_testPointAddrMap[2] = &chartInstance.c1_OldObstacle;
  chartInstance.c1_testPointAddrMap[3] = &chartInstance.c1_Area;
  chartInstance.c1_testPointAddrMap[4] = &chartInstance.c1_BuoyDone;
  chartInstance.c1_testPointAddrMap[5] = &chartInstance.c1_countarea;
  chartInstance.c1_testPointAddrMap[6] = &chartInstance.c1_ErrorX;
  chartInstance.c1_testPointAddrMap[7] = &chartInstance.c1_Flag;
  chartInstance.c1_testPointAddrMap[8] = &chartInstance.c1_track1;
  chartInstance.c1_testPointAddrMap[9] = &chartInstance.c1_ErrorY;
  chartInstance.c1_testPointAddrMap[10] = &chartInstance.c1_DesiredHeadingCount;
  chartInstance.c1_testPointAddrMap[11] = &chartInstance.c1_OldHeading;
  chartInstance.c1_testPointAddrMap[12] = &chartInstance.c1_ResetSwitch;
  chartInstance.c1_testPointAddrMap[13] = &chartInstance.c1_CentroidX;
  chartInstance.c1_testPointAddrMap[14] = &chartInstance.c1_CentroidY;
  chartInstance.c1_testPointAddrMap[15] = &chartInstance.c1_TrackCount;
  chartInstance.c1_testPointAddrMap[16] = &chartInstance.c1_BuoyCount;
  chartInstance.c1_testPointAddrMap[17] = &chartInstance.c1_ErrorCount;
  chartInstance.c1_testPointAddrMap[18] = &chartInstance.c1_ErrorCountHeading;
  chartInstance.c1_testPointAddrMap[19] = &chartInstance.c1_ErrorCountX;
  chartInstance.c1_testPointAddrMap[20] = &chartInstance.c1_ErrorCountY;
  chartInstance.c1_testPointAddrMap[21] = &chartInstance.c1_ErrorHeading;
  chartInstance.c1_testPointAddrMap[22] = &chartInstance.c1_tp_NotRunning;
  chartInstance.c1_testPointAddrMap[23] = &chartInstance.c1_tp_Running;
  chartInstance.c1_testPointAddrMap[24] = &chartInstance.c1_tp_Buoy;
  chartInstance.c1_testPointAddrMap[25] = &chartInstance.c1_tp_ChooseState;
  chartInstance.c1_testPointAddrMap[26] = &chartInstance.c1_tp_FindBuoy;
  chartInstance.c1_testPointAddrMap[27] = &chartInstance.c1_tp_Finish;
  chartInstance.c1_testPointAddrMap[28] = &chartInstance.c1_tp_FollowTrack;
  chartInstance.c1_testPointAddrMap[29] = &chartInstance.c1_tp_Stage1Aim;
  chartInstance.c1_testPointAddrMap[30] = &chartInstance.c1_tp_Stage2Position;
  chartInstance.c1_testPointAddrMap[31] = &chartInstance.c1_tp_Stage3ReOrient;
  chartInstance.c1_testPointAddrMap[32] = &chartInstance.c1_tp_Start;
  chartInstance.c1_testPointAddrMap[33] = &chartInstance.c1_tp_ValidationGate;
}

static void **get_test_point_address_map(void)
{
  return &chartInstance.c1_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info(void)
{
  return &chartInstance.c1_testPointMappingInfo;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c1_brain_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3235829550U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1992210294U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(361021299U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(940771437U);
}

mxArray *sf_c1_brain_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2517506722U);
    pr[1] = (double)(1136624174U);
    pr[2] = (double)(1378363654U);
    pr[3] = (double)(2494288873U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_brain(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[164],T\"BuoyCentroidX\",},{M[1],M[165],T\"BuoyCentroidY\",},{M[1],M[130],T\"CameraPosition\",},{M[1],M[22],T\"DesiredDepth\",},{M[1],M[57],T\"DesiredHeading\",},{M[1],M[12],T\"Left\",},{M[1],M[11],T\"Right\",},{M[1],M[287],T\"State\",},{M[1],M[13],T\"Vertical\",},{M[3],M[75],T\"Area\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[277],T\"BuoyCount\",},{M[3],M[76],T\"BuoyDone\",},{M[3],M[169],T\"CentroidX\",},{M[3],M[170],T\"CentroidY\",},{M[3],M[166],T\"DesiredHeadingCount\",},{M[3],M[278],T\"ErrorCount\",},{M[3],M[279],T\"ErrorCountHeading\",},{M[3],M[280],T\"ErrorCountX\",},{M[3],M[281],T\"ErrorCountY\",},{M[3],M[282],T\"ErrorHeading\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[124],T\"ErrorX\",},{M[3],M[127],T\"ErrorY\",},{M[3],M[125],T\"Flag\",},{M[3],M[26],T\"Obstacle\",},{M[3],M[167],T\"OldHeading\",},{M[3],M[27],T\"OldObstacle\",},{M[3],M[168],T\"ResetSwitch\",},{M[3],M[201],T\"TrackCount\",},{M[3],M[25],T\"count\",},{M[3],M[88],T\"countarea\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[3],M[126],T\"track1\",},{M[8],M[0],T\"is_active_c1_brain\",},{M[9],M[0],T\"is_c1_brain\",},{M[9],M[198],T\"is_FollowTrack\",},{M[9],M[289],T\"is_Running\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 35, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_brain_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_brainMachineNumber_,
          1,
          28,
          22,
          126,
          0,
          0,
          0,
          0,
          0,
          &(chartInstance.chartNumber),
          &(chartInstance.instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_brainMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_brainMachineNumber_,
            chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_brainMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "CurrentDepth",0,NULL);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "CurrentHeading",0,NULL);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"Right",0,
                              NULL);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"Left",0,
                              NULL);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"Vertical",
                              0,NULL);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "DesiredDepth",0,NULL);
          _SFD_SET_DATA_PROPS(6,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"count",0,
                              NULL);
          _SFD_SET_DATA_PROPS(7,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "Obstacle",0,NULL);
          _SFD_SET_DATA_PROPS(8,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "OldObstacle",0,NULL);
          _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "DesiredHeading",0,NULL);
          _SFD_SET_DATA_PROPS(10,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Area",0,
                              NULL);
          _SFD_SET_DATA_PROPS(11,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BuoyDone",0,NULL);
          _SFD_SET_DATA_PROPS(12,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "countarea",0,NULL);
          _SFD_SET_DATA_PROPS(13,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ErrorX",
                              0,NULL);
          _SFD_SET_DATA_PROPS(14,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Flag",0,
                              NULL);
          _SFD_SET_DATA_PROPS(15,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"track1",
                              0,NULL);
          _SFD_SET_DATA_PROPS(16,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ErrorY",
                              0,NULL);
          _SFD_SET_DATA_PROPS(17,2,0,1,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,
                              "CameraPosition",0,NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(18,1,1,0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"H",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(19,1,1,0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"S",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(20,1,1,0,SF_SINGLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"V",0,NULL);
          }

          _SFD_SET_DATA_PROPS(21,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BuoyCentroidX",0,NULL);
          _SFD_SET_DATA_PROPS(22,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BuoyCentroidY",0,NULL);
          _SFD_SET_DATA_PROPS(23,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "DesiredHeadingCount",0,NULL);
          _SFD_SET_DATA_PROPS(24,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "OldHeading",0,NULL);
          _SFD_SET_DATA_PROPS(25,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ResetSwitch",0,NULL);
          _SFD_SET_DATA_PROPS(26,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "CentroidX",0,NULL);
          _SFD_SET_DATA_PROPS(27,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "CentroidY",0,NULL);
          _SFD_SET_DATA_PROPS(28,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "TrackCount",0,NULL);
          _SFD_SET_DATA_PROPS(29,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BuoyCount",0,NULL);
          _SFD_SET_DATA_PROPS(30,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ErrorCount",0,NULL);
          _SFD_SET_DATA_PROPS(31,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ErrorCountHeading",0,NULL);
          _SFD_SET_DATA_PROPS(32,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ErrorCountX",0,NULL);
          _SFD_SET_DATA_PROPS(33,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ErrorCountY",0,NULL);
          _SFD_SET_DATA_PROPS(34,0,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "ErrorHeading",0,NULL);
          _SFD_SET_DATA_PROPS(35,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"State",0,
                              NULL);
          _SFD_SET_DATA_PROPS(36,1,1,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"Status",0,
                              NULL);
          _SFD_SET_DATA_PROPS(37,1,1,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,
                              "DesiredState",0,NULL);
          _SFD_SET_DATA_PROPS(38,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(39,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(40,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(41,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(42,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(43,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(44,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(45,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(46,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(47,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(48,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(49,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(50,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(51,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(52,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(53,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(54,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(55,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(56,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              c1_sf_marshall);
          _SFD_SET_DATA_PROPS(57,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(58,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(59,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(60,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(61,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(62,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(63,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(64,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(65,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(66,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(67,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(68,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(69,9,0,0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(70,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(71,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(72,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(73,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(74,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(75,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(76,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(77,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(78,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(79,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(80,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(81,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(82,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(83,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(84,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(85,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(86,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(87,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(88,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(89,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(90,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(91,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(92,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(93,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(94,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(95,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(96,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(97,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(98,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(99,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(100,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(101,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(102,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(103,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(104,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(105,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(106,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(107,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(108,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(109,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(110,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(111,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(112,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(113,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);

          {
            unsigned int dimVector[2];
            dimVector[0]= 480;
            dimVector[1]= 640;
            _SFD_SET_DATA_PROPS(114,8,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"",0,NULL);
          }

          _SFD_SET_DATA_PROPS(115,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(116,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(117,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(118,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(119,8,0,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(120,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(121,8,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_SET_DATA_PROPS(122,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(123,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(124,9,0,0,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,"",0,NULL);
          _SFD_SET_DATA_PROPS(125,9,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"",0,
                              NULL);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(3,0,2);
          _SFD_STATE_INFO(4,0,2);
          _SFD_STATE_INFO(5,0,2);
          _SFD_STATE_INFO(8,0,2);
          _SFD_STATE_INFO(9,0,2);
          _SFD_STATE_INFO(10,0,2);
          _SFD_STATE_INFO(14,0,2);
          _SFD_STATE_INFO(15,0,2);
          _SFD_STATE_INFO(17,0,2);
          _SFD_STATE_INFO(18,0,2);
          _SFD_STATE_INFO(20,0,2);
          _SFD_STATE_INFO(21,0,2);
          _SFD_STATE_INFO(23,0,2);
          _SFD_STATE_INFO(25,0,2);
          _SFD_STATE_INFO(26,0,2);
          _SFD_STATE_INFO(27,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,7);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,6);
          _SFD_ST_SUBSTATE_INDEX(1,2,7);
          _SFD_ST_SUBSTATE_INDEX(1,3,11);
          _SFD_ST_SUBSTATE_INDEX(1,4,12);
          _SFD_ST_SUBSTATE_INDEX(1,5,22);
          _SFD_ST_SUBSTATE_INDEX(1,6,24);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,3);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,16);
          _SFD_ST_SUBSTATE_INDEX(12,2,19);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,7,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 16 };

          static unsigned int sEndGuardMap[] = { 12, 33 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 29 };

          static unsigned int sEndGuardMap[] = { 25, 46 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(18,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 19 };

          static unsigned int sEndGuardMap[] = { 15, 36 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(20,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 26 };

          static unsigned int sEndGuardMap[] = { 22, 43 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(13,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 18 };

          static unsigned int sEndGuardMap[] = { 14, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(11,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(19,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(6,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(21,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(14,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(12,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(5,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(5,0,"ifbuoynotvisible",0,-1,398);
        _SFD_CV_INIT_EML_IF(5,0,154,195,275,398);

        {
          static int condStart[] = { 158, 178 };

          static int condEnd[] = { 174, 194 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(5,0,158,194,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(23,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(23,0,"InitialHeadingCount",0,-1,276);
        _SFD_CV_INIT_EML_IF(23,0,105,195,221,245);

        {
          static int condStart[] = { 108, 153 };

          static int condEnd[] = { 149, 194 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(23,0,108,194,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"countareas",0,-1,250);
        _SFD_CV_INIT_EML_IF(4,0,185,200,226,250);
        _SFD_CV_INIT_EML(27,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(27,0,"countimages",0,-1,283);
        _SFD_CV_INIT_EML_IF(27,0,198,233,259,283);

        {
          static int condStart[] = { 201, 215 };

          static int condEnd[] = { 211, 232 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(27,0,201,232,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(14,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(14,0,"ErrorCounter",0,-1,162);
        _SFD_CV_INIT_EML_IF(14,0,61,94,132,162);

        {
          static int condStart[] = { 64, 80 };

          static int condEnd[] = { 76, 93 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(14,0,64,93,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(17,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(17,0,"ErrorCounter",0,-1,161);
        _SFD_CV_INIT_EML_IF(17,0,62,93,131,161);

        {
          static int condStart[] = { 65, 80 };

          static int condEnd[] = { 76, 92 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(17,0,65,92,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(10,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(10,0,"countimages",0,-1,283);
        _SFD_CV_INIT_EML_IF(10,0,198,233,259,283);

        {
          static int condStart[] = { 201, 215 };

          static int condEnd[] = { 211, 232 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(10,0,201,232,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(21,1,1,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(21,0,"ErrorCounter",0,-1,161);
        _SFD_CV_INIT_EML_IF(21,0,62,93,131,161);

        {
          static int condStart[] = { 65, 80 };

          static int condEnd[] = { 76, 92 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(21,0,65,92,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(4,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 16 };

          static unsigned int sEndGuardMap[] = { 12, 33 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(18,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 29 };

          static unsigned int sEndGuardMap[] = { 25, 46 };

          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 19 };

          static unsigned int sEndGuardMap[] = { 15, 36 };

          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 26 };

          static unsigned int sEndGuardMap[] = { 22, 43 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 18 };

          static unsigned int sEndGuardMap[] = { 14, 35 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 22 };

          static unsigned int sEndGuardMap[] = { 18, 39 };

          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(38,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(39,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(40,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(41,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(42,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(46,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(47,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(48,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(49,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(50,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(51,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(52,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(53,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(54,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(55,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(56,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(57,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(58,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(59,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(60,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(61,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(62,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(63,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(64,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(65,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(66,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(67,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(68,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(69,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(70,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(71,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(72,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(73,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(74,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(75,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(76,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(77,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(78,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(79,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(80,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(81,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(82,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(83,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(84,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(85,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(86,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(87,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(88,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(89,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(90,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(91,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(92,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(93,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(94,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(95,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(96,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(97,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(98,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(99,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(100,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(101,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(102,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(103,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(104,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(105,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(106,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(107,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(108,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(109,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(110,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(111,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(112,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(113,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(114,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(115,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(116,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(117,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(118,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(119,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(120,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(121,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(122,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(123,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(124,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(125,(void *)(NULL));

        {
          real_T *c1_CurrentDepth;
          real_T *c1_CurrentHeading;
          int8_T *c1_Right;
          int8_T *c1_Left;
          int8_T *c1_Vertical;
          real_T *c1_DesiredDepth;
          real_T *c1_DesiredHeading;
          int8_T *c1_CameraPosition;
          real32_T (*c1_H)[307200];
          real32_T (*c1_S)[307200];
          real32_T (*c1_V)[307200];
          real_T *c1_BuoyCentroidX;
          real_T *c1_BuoyCentroidY;
          uint8_T *c1_State;
          int8_T *c1_Status;
          int8_T *c1_DesiredState;
          c1_DesiredState = (int8_T *)ssGetInputPortSignal(chartInstance.S, 6);
          c1_Vertical = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c1_H = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 2);
          c1_CameraPosition = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 6);
          c1_DesiredDepth = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c1_CurrentHeading = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c1_S = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 3);
          c1_State = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 9);
          c1_V = (real32_T (*)[307200])ssGetInputPortSignal(chartInstance.S, 4);
          c1_DesiredHeading = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
          c1_BuoyCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 7);
          c1_Right = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c1_BuoyCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 8);
          c1_CurrentDepth = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c1_Status = (int8_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c1_Left = (int8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_CurrentDepth);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_CurrentHeading);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Right);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Left);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_Vertical);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_DesiredDepth);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance.c1_count);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance.c1_Obstacle);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance.c1_OldObstacle);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_DesiredHeading);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance.c1_Area);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance.c1_BuoyDone);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance.c1_countarea);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance.c1_ErrorX);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance.c1_Flag);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance.c1_track1);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance.c1_ErrorY);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_CameraPosition);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_H);
          _SFD_SET_DATA_VALUE_PTR(19U, c1_S);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_V);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_BuoyCentroidX);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_BuoyCentroidY);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance.c1_DesiredHeadingCount);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance.c1_OldHeading);
          _SFD_SET_DATA_VALUE_PTR(25U, &chartInstance.c1_ResetSwitch);
          _SFD_SET_DATA_VALUE_PTR(26U, &chartInstance.c1_CentroidX);
          _SFD_SET_DATA_VALUE_PTR(27U, &chartInstance.c1_CentroidY);
          _SFD_SET_DATA_VALUE_PTR(28U, &chartInstance.c1_TrackCount);
          _SFD_SET_DATA_VALUE_PTR(29U, &chartInstance.c1_BuoyCount);
          _SFD_SET_DATA_VALUE_PTR(30U, &chartInstance.c1_ErrorCount);
          _SFD_SET_DATA_VALUE_PTR(31U, &chartInstance.c1_ErrorCountHeading);
          _SFD_SET_DATA_VALUE_PTR(32U, &chartInstance.c1_ErrorCountX);
          _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance.c1_ErrorCountY);
          _SFD_SET_DATA_VALUE_PTR(34U, &chartInstance.c1_ErrorHeading);
          _SFD_SET_DATA_VALUE_PTR(35U, c1_State);
          _SFD_SET_DATA_VALUE_PTR(36U, c1_Status);
          _SFD_SET_DATA_VALUE_PTR(37U, c1_DesiredState);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_brainMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_brain(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_brain();
  initialize_c1_brain();
}

static void sf_opaque_enable_c1_brain(void *chartInstanceVar)
{
  enable_c1_brain();
}

static void sf_opaque_disable_c1_brain(void *chartInstanceVar)
{
  disable_c1_brain();
}

static void sf_opaque_gateway_c1_brain(void *chartInstanceVar)
{
  sf_c1_brain();
}

static mxArray* sf_opaque_get_sim_state_c1_brain(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c1_brain();
  return st;
}

static void sf_opaque_set_sim_state_c1_brain(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c1_brain(sf_mex_dup(st));
}

static void sf_opaque_terminate_c1_brain(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_brain();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_brain(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_brain();
  }
}

static void mdlSetWorkWidths_c1_brain(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("brain","brain",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("brain","brain",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("brain","brain",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_mark_output_events_with_multiple_callers(S,"brain","brain",1,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 23, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 24, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 25, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 26, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 27, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 28, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 29, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 30, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 31, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 32, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 33, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 34, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"brain","brain",1,7);
      sf_mark_chart_reusable_outputs(S,"brain","brain",1,37);
    }

    sf_set_rtw_dwork_info(S,"brain","brain",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2250891434U));
  ssSetChecksum1(S,(1839881468U));
  ssSetChecksum2(S,(662743844U));
  ssSetChecksum3(S,(215486231U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_brain(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "brain", "brain",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_brain(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_brain;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_brain;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_brain;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_brain;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_brain;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c1_brain;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c1_brain;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_brain;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_brain;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_brain;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_brain;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c1_brain_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_brain(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_brain(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_brain(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_brain_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/count", "count", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/Obstacle", "Obstacle", 0, 0, 0, 0, 0 },

  { 2, 0, "StateflowChart/OldObstacle", "OldObstacle", 0, 0, 0, 0, 0 },

  { 3, 0, "StateflowChart/Area", "Area", 0, 0, 0, 0, 0 },

  { 4, 0, "StateflowChart/BuoyDone", "BuoyDone", 0, 0, 0, 0, 0 },

  { 5, 0, "StateflowChart/countarea", "countarea", 0, 0, 0, 0, 0 },

  { 6, 0, "StateflowChart/ErrorX", "ErrorX", 0, 0, 0, 0, 0 },

  { 7, 0, "StateflowChart/Flag", "Flag", 0, 0, 0, 0, 0 },

  { 8, 0, "StateflowChart/track1", "track1", 0, 0, 0, 0, 0 },

  { 9, 0, "StateflowChart/ErrorY", "ErrorY", 0, 0, 0, 0, 0 },

  { 10, 0, "StateflowChart/DesiredHeadingCount", "DesiredHeadingCount", 0, 0, 0,
    0, 0 },

  { 11, 0, "StateflowChart/OldHeading", "OldHeading", 0, 0, 0, 0, 0 },

  { 12, 0, "StateflowChart/ResetSwitch", "ResetSwitch", 0, 0, 0, 0, 0 },

  { 13, 0, "StateflowChart/CentroidX", "CentroidX", 0, 0, 0, 0, 0 },

  { 14, 0, "StateflowChart/CentroidY", "CentroidY", 0, 0, 0, 0, 0 },

  { 15, 0, "StateflowChart/TrackCount", "TrackCount", 0, 0, 0, 0, 0 },

  { 16, 0, "StateflowChart/BuoyCount", "BuoyCount", 0, 0, 0, 0, 0 },

  { 17, 0, "StateflowChart/ErrorCount", "ErrorCount", 0, 0, 0, 0, 0 },

  { 18, 0, "StateflowChart/ErrorCountHeading", "ErrorCountHeading", 0, 0, 0, 0,
    0 },

  { 19, 0, "StateflowChart/ErrorCountX", "ErrorCountX", 0, 0, 0, 0, 0 },

  { 20, 0, "StateflowChart/ErrorCountY", "ErrorCountY", 0, 0, 0, 0, 0 },

  { 21, 0, "StateflowChart/ErrorHeading", "ErrorHeading", 0, 0, 0, 0, 0 },

  { 22, 0, "StateflowChart/NotRunning", "NotRunning", 0, 1, 0, 0, 0 },

  { 23, 0, "StateflowChart/Running", "Running", 0, 1, 0, 0, 0 },

  { 24, 0, "StateflowChart/Running.Buoy", "Buoy", 0, 1, 0, 0, 0 },

  { 25, 0, "StateflowChart/Running.ChooseState", "ChooseState", 0, 1, 0, 0, 0 },

  { 26, 0, "StateflowChart/Running.FindBuoy", "FindBuoy", 0, 1, 0, 0, 0 },

  { 27, 0, "StateflowChart/Running.Finish", "Finish", 0, 1, 0, 0, 0 },

  { 28, 0, "StateflowChart/Running.FollowTrack", "FollowTrack", 0, 1, 0, 0, 0 },

  { 29, 0, "StateflowChart/Running.FollowTrack.Stage1Aim", "Stage1Aim", 0, 1, 0,
    0, 0 },

  { 30, 0, "StateflowChart/Running.FollowTrack.Stage2Position", "Stage2Position",
    0, 1, 0, 0, 0 },

  { 31, 0, "StateflowChart/Running.FollowTrack.Stage3ReOrient", "Stage3ReOrient",
    0, 1, 0, 0, 0 },

  { 32, 0, "StateflowChart/Running.Start", "Start", 0, 1, 0, 0, 0 },

  { 33, 0, "StateflowChart/Running.ValidationGate", "ValidationGate", 0, 1, 0, 0,
    0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    34                                 /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  init_test_point_addr_map();
  testPointMappingInfo = get_test_point_mapping_info();
  testPointAddrMap = get_test_point_address_map();
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
