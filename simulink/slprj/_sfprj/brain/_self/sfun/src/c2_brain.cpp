/* Include files */

#include "blascompat32.h"
#include "brain_sfun.h"
#include "c2_brain.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "brain_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_brainInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_brain(void);
static void initialize_params_c2_brain(void);
static void enable_c2_brain(void);
static void disable_c2_brain(void);
static void c2_update_debugger_state_c2_brain(void);
static const mxArray *get_sim_state_c2_brain(void);
static void set_sim_state_c2_brain(const mxArray *c2_st);
static void finalize_c2_brain(void);
static void sf_c2_brain(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31]);
static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u);
static int32_T c2_emlrt_marshallIn(const mxArray *c2_BlobArea, char *c2_name);
static real_T c2_b_emlrt_marshallIn(const mxArray *c2_BlobCentroidX, char
  *c2_name);
static real_T c2_c_emlrt_marshallIn(const mxArray *c2_BlobCentroidY, char
  *c2_name);
static uint8_T c2_d_emlrt_marshallIn(const mxArray *c2_b_is_active_c2_brain,
  char *c2_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_brain(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_brain = 0U;
}

static void initialize_params_c2_brain(void)
{
}

static void enable_c2_brain(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_brain(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_brain(void)
{
}

static const mxArray *get_sim_state_c2_brain(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  int32_T *c2_BlobArea;
  real_T *c2_BlobCentroidX;
  real_T *c2_BlobCentroidY;
  c2_BlobCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_BlobArea = (int32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_BlobCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4));
  c2_u = *c2_BlobArea;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = *c2_BlobCentroidX;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_u = *c2_BlobCentroidY;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_setcell(c2_y, 3, c2_emlrt_marshallOut
                 (chartInstance.c2_is_active_c2_brain));
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_brain(const mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T *c2_BlobArea;
  real_T *c2_BlobCentroidX;
  real_T *c2_BlobCentroidY;
  c2_BlobCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_BlobArea = (int32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_BlobCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  chartInstance.c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_BlobArea = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "BlobArea");
  *c2_BlobCentroidX = c2_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "BlobCentroidX");
  *c2_BlobCentroidY = c2_c_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "BlobCentroidY");
  chartInstance.c2_is_active_c2_brain = c2_d_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "is_active_c2_brain");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_brain();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_brain(void)
{
}

static void sf_c2_brain(void)
{
  int32_T c2_i0;
  int32_T c2_i1;
  uint8_T c2_previousEvent;
  int32_T c2_i2;
  int32_T c2_Area1[10];
  int32_T c2_i3;
  real_T c2_Centroid1[20];
  real_T c2_nargout = 3.0;
  real_T c2_nargin = 2.0;
  real_T c2_index;
  real_T c2_BlobCentroidY;
  real_T c2_BlobCentroidX;
  int32_T c2_BlobArea;
  int32_T c2_i4;
  int32_T c2_varargin_1[10];
  int32_T c2_i5;
  int32_T c2_x[10];
  int32_T c2_i6;
  int32_T c2_b_x[10];
  int32_T c2_mtmp;
  int32_T c2_itmp;
  int32_T c2_ix;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_a;
  int32_T c2_b_mtmp;
  int32_T c2_b_itmp;
  int32_T c2_maxval;
  real_T c2_indx;
  int32_T c2_b_BlobArea;
  real_T c2_b_index;
  int32_T *c2_c_BlobArea;
  real_T *c2_b_BlobCentroidX;
  real_T *c2_b_BlobCentroidY;
  real_T (*c2_b_Centroid1)[20];
  int32_T (*c2_b_Area1)[10];
  c2_b_Area1 = (int32_T (*)[10])ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_BlobCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_c_BlobArea = (int32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_Centroid1 = (real_T (*)[20])ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_BlobCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  for (c2_i0 = 0; c2_i0 < 10; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_Area1)[c2_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c2_c_BlobArea, 1U);
  for (c2_i1 = 0; c2_i1 < 20; c2_i1 = c2_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_b_Centroid1)[c2_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_BlobCentroidX, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_BlobCentroidY, 4U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for (c2_i2 = 0; c2_i2 < 10; c2_i2 = c2_i2 + 1) {
    c2_Area1[c2_i2] = (*c2_b_Area1)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 20; c2_i3 = c2_i3 + 1) {
    c2_Centroid1[c2_i3] = (*c2_b_Centroid1)[c2_i3];
  }

  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("index", &c2_index, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("BlobCentroidY", &c2_BlobCentroidY, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("BlobCentroidX", &c2_BlobCentroidX, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("BlobArea", &c2_BlobArea, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("Centroid1", &c2_Centroid1, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("Area1", &c2_Area1, c2_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  This function will choose and return data about the largest blob given a  */
  /*  set of blobs */
  _SFD_EML_CALL(0,5);
  for (c2_i4 = 0; c2_i4 < 10; c2_i4 = c2_i4 + 1) {
    c2_varargin_1[c2_i4] = c2_Area1[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 10; c2_i5 = c2_i5 + 1) {
    c2_x[c2_i5] = c2_varargin_1[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 10; c2_i6 = c2_i6 + 1) {
    c2_b_x[c2_i6] = c2_x[c2_i6];
  }

  c2_mtmp = c2_b_x[0];
  c2_itmp = 1;
  c2_ix = 1;
  for (c2_k = 2; c2_k < 11; c2_k = c2_k + 1) {
    c2_b_k = c2_k;
    c2_a = c2_ix;
    c2_ix = c2_a + 1;
    if (c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix", (real_T)
          c2_ix), 1, 10, 1, 0) - 1] > c2_mtmp) {
      c2_mtmp = c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", _SFD_INTEGER_CHECK("ix",
        (real_T)c2_ix), 1, 10, 1, 0) - 1];
      c2_itmp = c2_b_k;
    }
  }

  c2_b_mtmp = c2_mtmp;
  c2_b_itmp = c2_itmp;
  c2_maxval = c2_b_mtmp;
  c2_indx = (real_T)c2_b_itmp;
  c2_b_BlobArea = c2_maxval;
  c2_b_index = c2_indx;
  c2_BlobArea = c2_b_BlobArea;
  c2_index = c2_b_index;
  _SFD_EML_CALL(0,6);
  c2_BlobCentroidX = c2_Centroid1[_SFD_EML_ARRAY_BOUNDS_CHECK("Centroid1",
    (int32_T)_SFD_INTEGER_CHECK("index", c2_index), 1, 2, 1, 0)
    + 1];
  _SFD_EML_CALL(0,7);
  c2_BlobCentroidY = c2_Centroid1[_SFD_EML_ARRAY_BOUNDS_CHECK("Centroid1",
    (int32_T)_SFD_INTEGER_CHECK("index", c2_index), 1, 2, 1, 0)
    - 1];
  _SFD_EML_CALL(0,-7);
  sf_debug_symbol_scope_pop();
  *c2_c_BlobArea = c2_BlobArea;
  *c2_b_BlobCentroidX = c2_BlobCentroidX;
  *c2_b_BlobCentroidY = c2_BlobCentroidY;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_brainMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i7;
  int32_T c2_b_u[10];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i7 = 0; c2_i7 < 10; c2_i7 = c2_i7 + 1) {
    c2_b_u[c2_i7] = (*((int32_T (*)[10])c2_u))[c2_i7];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 1U, 0U, 2, 1, 10));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T c2_b_u[20];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_i8 = 0;
  for (c2_i9 = 0; c2_i9 < 10; c2_i9 = c2_i9 + 1) {
    for (c2_i10 = 0; c2_i10 < 2; c2_i10 = c2_i10 + 1) {
      c2_b_u[c2_i10 + c2_i8] = (*((real_T (*)[20])c2_u))[c2_i10 + c2_i8];
    }

    c2_i8 = c2_i8 + 2;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 2, 10));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((int32_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_brain_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[31];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i11;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c2_i11 = 0; c2_i11 < 31; c2_i11 = c2_i11 + 1) {
    c2_r0 = &c2_info[c2_i11];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i11);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i11
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i11
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31])
{
  c2_info[0].context = "";
  c2_info[0].name = "max";
  c2_info[0].dominantType = "int32";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[0].fileLength = 308U;
  c2_info[0].fileTime1 = 1192488230U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[1].name = "nargin";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]nargin";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[2].name = "gt";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]gt";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[3].name = "nargout";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargout";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[4].name = "le";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]le";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[5].name = "eml_min_or_max";
  c2_info[5].dominantType = "int32";
  c2_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[5].fileLength = 8839U;
  c2_info[5].fileTime1 = 1227634988U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[6].name = "ischar";
  c2_info[6].dominantType = "char";
  c2_info[6].resolved = "[B]ischar";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[7].name = "strcmp";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved = "[B]strcmp";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[8].name = "isnumeric";
  c2_info[8].dominantType = "int32";
  c2_info[8].resolved = "[B]isnumeric";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[9].name = "isreal";
  c2_info[9].dominantType = "int32";
  c2_info[9].resolved = "[B]isreal";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[10].name = "eq";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]eq";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[11].name = "eml_nonsingleton_dim";
  c2_info[11].dominantType = "int32";
  c2_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[11].fileLength = 420U;
  c2_info[11].fileTime1 = 1227634989U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[12].name = "size";
  c2_info[12].dominantType = "int32";
  c2_info[12].resolved = "[B]size";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[13].name = "ndims";
  c2_info[13].dominantType = "int32";
  c2_info[13].resolved = "[B]ndims";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c2_info[14].name = "ne";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]ne";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[15].name = "isempty";
  c2_info[15].dominantType = "int32";
  c2_info[15].resolved = "[B]isempty";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "int32";
  c2_info[16].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileLength = 3524U;
  c2_info[16].fileTime1 = 1227634993U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c2_info[17].name = "false";
  c2_info[17].dominantType = "";
  c2_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[17].fileLength = 238U;
  c2_info[17].fileTime1 = 1192488320U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[18].name = "logical";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]logical";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[19].name = "isstruct";
  c2_info[19].dominantType = "int32";
  c2_info[19].resolved = "[B]isstruct";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[20].name = "isa";
  c2_info[20].dominantType = "int32";
  c2_info[20].resolved = "[B]isa";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[21].name = "class";
  c2_info[21].dominantType = "int32";
  c2_info[21].resolved = "[B]class";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[22].name = "cast";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[22].fileLength = 889U;
  c2_info[22].fileTime1 = 1226011042U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[23].name = "ge";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]ge";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[24].name = "int32";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]int32";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[25].name = "ones";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved = "[B]ones";
  c2_info[25].fileLength = 0U;
  c2_info[25].fileTime1 = 0U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[26].name = "eml_index_class";
  c2_info[26].dominantType = "";
  c2_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[26].fileLength = 909U;
  c2_info[26].fileTime1 = 1192488382U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c2_info[27].name = "lt";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]lt";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c2_info[28].name = "isnan";
  c2_info[28].dominantType = "int32";
  c2_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[28].fileLength = 506U;
  c2_info[28].fileTime1 = 1227634988U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c2_info[29].name = "eml_index_plus";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[29].fileLength = 272U;
  c2_info[29].fileTime1 = 1192488385U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[30].name = "double";
  c2_info[30].dominantType = "int32";
  c2_info[30].resolved = "[B]double";
  c2_info[30].fileLength = 0U;
  c2_info[30].fileTime1 = 0U;
  c2_info[30].fileTime2 = 0U;
}

static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  return c2_y;
}

static int32_T c2_emlrt_marshallIn(const mxArray *c2_BlobArea, char *c2_name)
{
  int32_T c2_y;
  int32_T c2_i12;
  sf_mex_import(c2_name, sf_mex_dup(c2_BlobArea), &c2_i12, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i12;
  sf_mex_destroy(&c2_BlobArea);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(const mxArray *c2_BlobCentroidX, char
  *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_BlobCentroidX), &c2_d0, 1, 0, 0U, 0, 0U,
                0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_BlobCentroidX);
  return c2_y;
}

static real_T c2_c_emlrt_marshallIn(const mxArray *c2_BlobCentroidY, char
  *c2_name)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_name, sf_mex_dup(c2_BlobCentroidY), &c2_d1, 1, 0, 0U, 0, 0U,
                0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_BlobCentroidY);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(const mxArray *c2_b_is_active_c2_brain,
  char *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_brain), &c2_u0, 1, 3, 0U,
                0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_brain);
  return c2_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_brain_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3343641370U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3595530841U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2098838103U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3487222603U);
}

mxArray *sf_c2_brain_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1719701585U);
    pr[1] = (double)(918101037U);
    pr[2] = (double)(3479671270U);
    pr[3] = (double)(1555287611U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(10);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(10);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_brain(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"BlobArea\",},{M[1],M[7],T\"BlobCentroidX\",},{M[1],M[8],T\"BlobCentroidY\",},{M[8],M[0],T\"is_active_c2_brain\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_brain_get_check_sum(&mxChecksum);
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
          2,
          1,
          1,
          5,
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

          {
            unsigned int dimVector[2];
            dimVector[0]= 1;
            dimVector[1]= 10;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,1.0,
                                0,"Area1",0,c2_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,"BlobArea",
                              0,c2_c_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 2;
            dimVector[1]= 10;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"Centroid1",0,c2_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BlobCentroidX",0,c2_d_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "BlobCentroidY",0,NULL);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,281);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          int32_T (*c2_Area1)[10];
          int32_T *c2_BlobArea;
          real_T (*c2_Centroid1)[20];
          real_T *c2_BlobCentroidX;
          real_T *c2_BlobCentroidY;
          c2_Area1 = (int32_T (*)[10])ssGetInputPortSignal(chartInstance.S, 0);
          c2_BlobCentroidX = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_BlobArea = (int32_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_Centroid1 = (real_T (*)[20])ssGetInputPortSignal(chartInstance.S, 1);
          c2_BlobCentroidY = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Area1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_BlobArea);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Centroid1);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_BlobCentroidX);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_BlobCentroidY);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_brainMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_brain(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_brain();
  initialize_c2_brain();
}

static void sf_opaque_enable_c2_brain(void *chartInstanceVar)
{
  enable_c2_brain();
}

static void sf_opaque_disable_c2_brain(void *chartInstanceVar)
{
  disable_c2_brain();
}

static void sf_opaque_gateway_c2_brain(void *chartInstanceVar)
{
  sf_c2_brain();
}

static mxArray* sf_opaque_get_sim_state_c2_brain(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_brain();
  return st;
}

static void sf_opaque_set_sim_state_c2_brain(void *chartInstanceVar, const
  mxArray *st)
{
  set_sim_state_c2_brain(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_brain(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_brain();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_brain(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_brain();
  }
}

static void mdlSetWorkWidths_c2_brain(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("brain","brain",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("brain","brain",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("brain","brain",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"brain","brain",2,2);
      sf_mark_chart_reusable_outputs(S,"brain","brain",2,3);
    }

    sf_set_rtw_dwork_info(S,"brain","brain",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(938297390U));
  ssSetChecksum1(S,(795028588U));
  ssSetChecksum2(S,(97250884U));
  ssSetChecksum3(S,(4194032673U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_brain(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "brain", "brain",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_brain(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_brain;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_brain;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_brain;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_brain;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_brain;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c2_brain;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c2_brain;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_brain;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_brain;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_brain;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_brain;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c2_brain_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_brain(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_brain(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_brain(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_brain_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
