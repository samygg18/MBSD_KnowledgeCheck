/* Include files */

#include "GDS_sfun.h"
#include "c4_GDS.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GDS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_ValueRetained            ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_b_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_c_debug_family_names[5] = { "nargin", "nargout", "In1",
  "In2", "Out" };

static const char * c4_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_f_debug_family_names[5] = { "nargin", "nargout", "In1",
  "In2", "Out" };

static const char * c4_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_h_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void initialize_params_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void enable_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void disable_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_GDS(SFc4_GDSInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void set_sim_state_c4_GDS(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_GDS(SFc4_GDSInstanceStruct
  *chartInstance);
static void finalize_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void sf_gateway_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void mdl_start_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void c4_chartstep_c4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void initSimStructsc4_GDS(SFc4_GDSInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_nargout, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_c_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_b_tp_ValueRetained, const char_T *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint32_T c4_g_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_b_temporalCounter_i1, const char_T *c4_identifier);
static uint32_T c4_h_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_i_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_b_dataWrittenToVector, const char_T *c4_identifier, boolean_T
  c4_y[4]);
static void c4_j_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T c4_y[4]);
static const mxArray *c4_k_emlrt_marshallIn(SFc4_GDSInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_l_emlrt_marshallIn(SFc4_GDSInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc4_GDSInstanceStruct
  *chartInstance, int32_T c4_ssid);
static void c4_init_sf_message_store_memory(SFc4_GDSInstanceStruct
  *chartInstance);
static uint32_T c4__u32_d_(SFc4_GDSInstanceStruct *chartInstance, real_T c4_b,
  uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc);
static uint32_T c4__u32_u64_(SFc4_GDSInstanceStruct *chartInstance, uint64_T
  c4_b, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T
  c4_length_src_loc);
static void init_dsm_address_info(SFc4_GDSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_GDSInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_GDS(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_ValueRetained = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_is_active_c4_GDS = 0U;
  chartInstance->c4_is_c4_GDS = c4_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  real_T c4_d0;
  real_T c4_d1;
  real_T c4_d2;
  sf_mex_import_named("DurationStable", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c4_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_DurationStable = c4_d0;
  sf_mex_import_named("IsDifferentThreshold", sf_mex_get_sfun_param
                      (chartInstance->S, 1, 0), &c4_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_IsDifferentThreshold = c4_d1;
  sf_mex_import_named("IsEquivalentThreshold", sf_mex_get_sfun_param
                      (chartInstance->S, 2, 0), &c4_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_IsEquivalentThreshold = c4_d2;
}

static void enable_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_GDS(SFc4_GDSInstanceStruct
  *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_GDS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_GDS == c4_IN_ValueRetained) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint32_T c4_e_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  const mxArray *c4_g_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(6, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_ValueOutput;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_ValueStable;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_GDS;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_is_c4_GDS;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y",
    chartInstance->c4_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_GDS(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_st)
{
  const mxArray *c4_u;
  boolean_T c4_bv0[4];
  int32_T c4_i0;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_ValueOutput = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "ValueOutput");
  chartInstance->c4_ValueStable = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "ValueStable");
  chartInstance->c4_is_active_c4_GDS = c4_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 2)), "is_active_c4_GDS");
  chartInstance->c4_is_c4_GDS = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "is_c4_GDS");
  chartInstance->c4_temporalCounter_i1 = c4_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 4)), "temporalCounter_i1");
  c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
                        "dataWrittenToVector", c4_bv0);
  for (c4_i0 = 0; c4_i0 < 4; c4_i0++) {
    chartInstance->c4_dataWrittenToVector[c4_i0] = c4_bv0[c4_i0];
  }

  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_GDS(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_GDS(SFc4_GDSInstanceStruct
  *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_GDS == c4_IN_ValueRetained) {
      chartInstance->c4_tp_ValueRetained = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_ValueRetained = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  c4_set_sim_state_side_effects_c4_GDS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c4_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c4_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_ValueInitial, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_ValueInput, 1U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_GDS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GDSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  c4_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c4_chartstep_c4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_nargout = 1.0;
  uint32_T c4_b_debug_family_var_map[2];
  boolean_T c4_out;
  real_T c4_b_nargin = 0.0;
  real_T c4_b_nargout = 0.0;
  real_T c4_In1;
  real_T c4_In2;
  uint32_T c4_c_debug_family_var_map[5];
  real_T c4_c_nargin = 2.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_Out;
  real_T c4_d_nargin = 0.0;
  real_T c4_e_nargin = 0.0;
  real_T c4_d_nargout = 1.0;
  real_T c4_e_nargout = 1.0;
  boolean_T c4_b_out;
  boolean_T c4_c_out;
  real_T c4_b_In1;
  real_T c4_b_In2;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T c4_g_nargin = 2.0;
  real_T c4_g_nargout = 1.0;
  boolean_T c4_b_Out;
  real_T c4_h_nargin = 0.0;
  real_T c4_h_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
  if (chartInstance->c4_is_active_c4_GDS == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
    chartInstance->c4_is_active_c4_GDS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_debug_family_names,
      c4_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    chartInstance->c4_ValueStable = *chartInstance->c4_ValueInitial;
    chartInstance->c4_dataWrittenToVector[1U] = true;
    chartInstance->c4_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_ValueStable, 0U);
    if (!chartInstance->c4_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c4_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    *chartInstance->c4_ValueOutput = chartInstance->c4_ValueStable;
    chartInstance->c4_dataWrittenToVector[0U] = true;
    chartInstance->c4_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c4_ValueOutput, 3U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c4_is_c4_GDS = c4_IN_ValueRetained;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
    chartInstance->c4_temporalCounter_i1 = 0U;
    chartInstance->c4_tp_ValueRetained = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c4_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_b_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    if (!chartInstance->c4_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c4_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    c4_In1 = *chartInstance->c4_ValueInput;
    c4_In2 = chartInstance->c4_ValueStable;
    _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_c_debug_family_names,
      c4_c_debug_family_var_map);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_In1, 2U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_In2, 3U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Out, 4U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c4_sfEvent);
    c4_Out = (c4_In1 == c4_In2);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
    c4_out = CV_EML_IF(3, 0, 0, c4_Out);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = false;
    guard2 = false;
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_d_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      c4_b_out = CV_EML_IF(1, 0, 0, c4__u32_u64_(chartInstance, (uint64_T)
        chartInstance->c4_temporalCounter_i1 * 10ULL, 81U, 1U, 27U) >=
                           c4__u32_d_(chartInstance, muDoubleScalarCeil
        (chartInstance->c4_DurationStable), 81U, 1U, 27U));
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_h_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        if (!chartInstance->c4_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        if (!chartInstance->c4_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        *chartInstance->c4_ValueOutput = chartInstance->c4_ValueStable;
        chartInstance->c4_dataWrittenToVector[0U] = true;
        chartInstance->c4_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c4_ValueOutput, 3U);
        _SFD_SYMBOL_SCOPE_POP();
        guard1 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c4_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_e_debug_family_names,
        c4_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      if (!chartInstance->c4_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      if (!chartInstance->c4_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      c4_b_In1 = *chartInstance->c4_ValueInput;
      c4_b_In2 = chartInstance->c4_ValueStable;
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_f_debug_family_names,
        c4_c_debug_family_var_map);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_In1, 2U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_In2, 3U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Out, 4U, c4_b_sf_marshallOut,
        c4_b_sf_marshallIn);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c4_sfEvent);
      c4_b_Out = (c4_b_In1 != c4_b_In2);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
      c4_c_out = CV_EML_IF(4, 0, 0, c4_b_Out);
      _SFD_SYMBOL_SCOPE_POP();
      if (c4_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c4_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_g_debug_family_names,
          c4_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargin, 0U, c4_sf_marshallOut,
          c4_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_h_nargout, 1U,
          c4_sf_marshallOut, c4_sf_marshallIn);
        chartInstance->c4_ValueStable = *chartInstance->c4_ValueInput;
        chartInstance->c4_dataWrittenToVector[1U] = true;
        chartInstance->c4_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_ValueStable, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        guard1 = true;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c4_sfEvent);
      }
    }

    if (guard1) {
      chartInstance->c4_tp_ValueRetained = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_GDS = c4_IN_ValueRetained;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_ValueRetained = 1U;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_GDS(SFc4_GDSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_nargout, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d3, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d3;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_c_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_sf_internal_predicateOutput;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_sf_internal_predicateOutput = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_sf_internal_predicateOutput), &c4_thisId);
  sf_mex_destroy(&c4_sf_internal_predicateOutput);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_GDS_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_b_tp_ValueRetained, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_ValueRetained),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_ValueRetained);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_ValueRetained;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)chartInstanceVoid;
  c4_b_tp_ValueRetained = sf_mex_dup(c4_mxArrayInData);
  c4_thisId.fIdentifier = (const char *)c4_varName;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_ValueRetained),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_ValueRetained);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint32_T c4_g_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_b_temporalCounter_i1, const char_T *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_temporalCounter_i1),
    &c4_thisId);
  sf_mex_destroy(&c4_b_temporalCounter_i1);
  return c4_y;
}

static uint32_T c4_h_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u1, 1, 7, 0U, 0, 0U, 0);
  c4_y = c4_u1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_i_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_b_dataWrittenToVector, const char_T *c4_identifier, boolean_T
  c4_y[4])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_dataWrittenToVector),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_dataWrittenToVector);
}

static void c4_j_emlrt_marshallIn(SFc4_GDSInstanceStruct *chartInstance, const
  mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T c4_y[4])
{
  boolean_T c4_bv1[4];
  int32_T c4_i2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c4_i2 = 0; c4_i2 < 4; c4_i2++) {
    c4_y[c4_i2] = c4_bv1[c4_i2];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_k_emlrt_marshallIn(SFc4_GDSInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  sf_mex_assign(&c4_y, c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_l_emlrt_marshallIn(SFc4_GDSInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc4_GDSInstanceStruct
  *chartInstance, int32_T c4_ssid)
{
  (void)chartInstance;
  (void)c4_ssid;
  return NULL;
}

static void c4_init_sf_message_store_memory(SFc4_GDSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static uint32_T c4__u32_d_(SFc4_GDSInstanceStruct *chartInstance, real_T c4_b,
  uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T c4_length_src_loc)
{
  uint32_T c4_a;
  (void)chartInstance;
  c4_a = (uint32_T)c4_b;
  if ((c4_b < 0.0) || ((real_T)c4_a != muDoubleScalarFloor(c4_b))) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
  }

  return c4_a;
}

static uint32_T c4__u32_u64_(SFc4_GDSInstanceStruct *chartInstance, uint64_T
  c4_b, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc, int32_T
  c4_length_src_loc)
{
  uint32_T c4_a;
  (void)chartInstance;
  c4_a = (uint32_T)c4_b;
  if ((uint64_T)c4_a != c4_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c4_ssid_src_loc, c4_offset_src_loc,
      c4_length_src_loc);
  }

  return c4_a;
}

static void init_dsm_address_info(SFc4_GDSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_GDSInstanceStruct *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_ValueInput = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_ValueOutput = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_ValueInitial = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_GDS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4058345732U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1770768811U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3532214338U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1830678286U);
}

mxArray* sf_c4_GDS_get_post_codegen_info(void);
mxArray *sf_c4_GDS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nXCwXrHdcSYGHwzZh2JqvG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_GDS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_GDS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_GDS_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("needsCoverage");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_GDS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_GDS_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_GDS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[11],T\"ValueOutput\",},{M[3],M[12],T\"ValueStable\",},{M[8],M[0],T\"is_active_c4_GDS\",},{M[9],M[0],T\"is_c4_GDS\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[42],M[1]}}},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_GDS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc4_GDSInstanceStruct *) chartInstance,
    msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GDSInstanceStruct *chartInstance = (SFc4_GDSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GDSMachineNumber_,
           4,
           3,
           9,
           0,
           13,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_GDSMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_GDSMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _GDSMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"ValueStable");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ValueInput");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ValueInitial");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ValueOutput");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,9,0,0,"");
          _SFD_SET_DATA_PROPS(9,9,0,0,"");
          _SFD_SET_DATA_PROPS(10,10,0,0,"DurationStable");
          _SFD_SET_DATA_PROPS(11,10,0,0,"IsDifferentThreshold");
          _SFD_SET_DATA_PROPS(12,10,0,0,"IsEquivalentThreshold");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,39,1,39);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,38,1,38);
        _SFD_CV_INIT_EML(2,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _GDSMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_GDSInstanceStruct *chartInstance = (SFc4_GDSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_ValueInput);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_ValueOutput);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c4_ValueStable);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_ValueInitial);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)&chartInstance->c4_DurationStable);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)
          &chartInstance->c4_IsDifferentThreshold);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)
          &chartInstance->c4_IsEquivalentThreshold);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sqgk7mgoGy8xweQSI4kO8hG";
}

static void sf_opaque_initialize_c4_GDS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_GDSInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
  initialize_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_GDS(void *chartInstanceVar)
{
  enable_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_GDS(void *chartInstanceVar)
{
  disable_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_GDS(void *chartInstanceVar)
{
  sf_gateway_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_GDS(SimStruct* S)
{
  return get_sim_state_c4_GDS((SFc4_GDSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_GDS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_GDS((SFc4_GDSInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_GDS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_GDSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GDS_optimization_info();
    }

    finalize_c4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_GDS((SFc4_GDSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_GDS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_GDS((SFc4_GDSInstanceStruct*)sf_get_chart_instance_ptr
      (S));
  }
}

static void mdlSetWorkWidths_c4_GDS(SimStruct *S)
{
  /* Actual parameters from chart:
     DurationStable IsDifferentThreshold IsEquivalentThreshold
   */
  const char_T *rtParamNames[] = { "DurationStable", "IsDifferentThreshold",
    "IsEquivalentThreshold" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for DurationStable*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for IsDifferentThreshold*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for IsEquivalentThreshold*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GDS_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(458032374U));
  ssSetChecksum1(S,(1912706398U));
  ssSetChecksum2(S,(1056465889U));
  ssSetChecksum3(S,(3202657335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_GDS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_GDS(SimStruct *S)
{
  SFc4_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc4_GDSInstanceStruct *)utMalloc(sizeof
    (SFc4_GDSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_GDSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_GDS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_GDS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_GDS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_GDS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_GDS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_GDS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_GDS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_GDS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_GDS;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_GDS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_GDS;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_GDS(chartInstance);
}

void c4_GDS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_GDS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_GDS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_GDS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_GDS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
