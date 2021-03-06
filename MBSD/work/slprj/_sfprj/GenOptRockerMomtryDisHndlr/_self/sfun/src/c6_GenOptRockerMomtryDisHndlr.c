/* Include files */

#include "GenOptRockerMomtryDisHndlr_sfun.h"
#include "c6_GenOptRockerMomtryDisHndlr.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "GenOptRockerMomtryDisHndlr_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_Transition_Increments    ((uint8_T)1U)
#define c6_IN_Transition_Increments1   ((uint8_T)2U)
#define c6_IN_Transition_Same          ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initialize_params_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void enable_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void disable_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void set_sim_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_st);
static void c6_set_sim_state_side_effects_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void finalize_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void sf_gateway_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void mdl_start_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c6_chartstep_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initSimStructsc6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c6_enter_atomic_Transition_Same
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_b_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_c_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint8_T c6_d_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_tp_Transition_Increments, const char_T *c6_identifier);
static uint8_T c6_e_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint16_T c6_f_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_Trans, const char_T *c6_identifier);
static uint16_T c6_g_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_h_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[2]);
static void c6_i_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[2]);
static const mxArray *c6_j_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier);
static const mxArray *c6_k_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c6_ssid);
static void c6_init_sf_message_store_memory
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance);
static void init_simulink_io_address
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  real_T c6_d0;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_GenOptRockerMomtryDisHndlr(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_tp_Transition_Increments = 0U;
  chartInstance->c6_tp_Transition_Increments1 = 0U;
  chartInstance->c6_tp_Transition_Same = 0U;
  chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr = 0U;
  chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr = c6_IN_NO_ACTIVE_CHILD;
  sf_mex_import_named("counter", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c6_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_counter = (uint16_T)c6_d0;
  _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c6_counter, 0U, 0.0,
    255.0, 0U, 0, 0);
}

static void initialize_params_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
      c6_IN_Transition_Increments) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
      c6_IN_Transition_Same) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
      c6_IN_Transition_Increments1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  }

  _SFD_SET_ANIMATION(c6_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  uint16_T c6_hoistedGlobal;
  const mxArray *c6_b_y = NULL;
  uint16_T c6_b_hoistedGlobal;
  const mxArray *c6_c_y = NULL;
  uint16_T c6_c_hoistedGlobal;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_hoistedGlobal;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(6, 1), false);
  c6_hoistedGlobal = *chartInstance->c6_Internal_counter;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_hoistedGlobal, 5, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *chartInstance->c6_Trans;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = chartInstance->c6_counter;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y",
    chartInstance->c6_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  boolean_T c6_bv0[2];
  int32_T c6_i0;
  c6_u = sf_mex_dup(c6_st);
  *chartInstance->c6_Internal_counter = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 0)), "Internal_counter");
  *chartInstance->c6_Trans = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "Trans");
  chartInstance->c6_counter = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 2)), "counter");
  chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr =
    c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
    "is_active_c6_GenOptRockerMomtryDisHndlr");
  chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr = c6_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 4)),
     "is_c6_GenOptRockerMomtryDisHndlr");
  c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 5)),
                        "dataWrittenToVector", c6_bv0);
  for (c6_i0 = 0; c6_i0 < 2; c6_i0++) {
    chartInstance->c6_dataWrittenToVector[c6_i0] = c6_bv0[c6_i0];
  }

  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_debugger_state_c6_GenOptRockerMomtryDisHndlr(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    chartInstance->c6_tp_Transition_Increments = (uint8_T)
      (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
       c6_IN_Transition_Increments);
    chartInstance->c6_tp_Transition_Increments1 = (uint8_T)
      (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
       c6_IN_Transition_Increments1);
    chartInstance->c6_tp_Transition_Same = (uint8_T)
      (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr ==
       c6_IN_Transition_Same);
    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
}

static void sf_gateway_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  c6_set_sim_state_side_effects_c6_GenOptRockerMomtryDisHndlr(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_P_ROM, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Transition_Zero, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Transition_Add, 1U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_GenOptRockerMomtryDisHndlr(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GenOptRockerMomtryDisHndlrMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  c6_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void c6_chartstep_c6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_b_nargin = 0.0;
  real_T c6_c_nargin = 0.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_nargout = 1.0;
  real_T c6_c_nargout = 1.0;
  boolean_T c6_out;
  boolean_T c6_b_out;
  boolean_T c6_c_out;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_d_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 0.0;
  uint32_T c6_u0;
  uint32_T c6_u1;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 0.0;
  uint32_T c6_u2;
  uint32_T c6_u3;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  if (chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_active_c6_GenOptRockerMomtryDisHndlr = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr = c6_IN_Transition_Same;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_Transition_Same = 1U;
    c6_enter_atomic_Transition_Same(chartInstance);
  } else {
    switch (chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr) {
     case c6_IN_Transition_Increments:
      CV_CHART_EVAL(4, 0, c6_IN_Transition_Increments);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_e_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
            *chartInstance->c6_P_ROM, 0.0, -1, 0U, *chartInstance->c6_P_ROM ==
            0.0)) || CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
            *chartInstance->c6_P_ROM, 3.0, -1, 0U, *chartInstance->c6_P_ROM ==
            3.0))) {
        CV_EML_MCDC(4, 0, 0, true);
        CV_EML_IF(4, 0, 0, true);
        c6_out = true;
      } else {
        CV_EML_MCDC(4, 0, 0, false);
        CV_EML_IF(4, 0, 0, false);
        c6_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c6_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Increments = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr =
          c6_IN_Transition_Same;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Same = 1U;
        c6_enter_atomic_Transition_Same(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_Transition_Increments1:
      CV_CHART_EVAL(4, 0, c6_IN_Transition_Increments1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_f_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c6_P_ROM, 0.0, -1, 0U, *chartInstance->c6_P_ROM ==
            0.0)) || CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
            *chartInstance->c6_P_ROM, 3.0, -1, 0U, *chartInstance->c6_P_ROM ==
            3.0))) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c6_b_out = true;
      } else {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c6_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c6_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Increments1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr =
          c6_IN_Transition_Same;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Same = 1U;
        c6_enter_atomic_Transition_Same(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_Transition_Same:
      CV_CHART_EVAL(4, 0, c6_IN_Transition_Same);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_g_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        *chartInstance->c6_P_ROM, 2.0, -1, 0U, *chartInstance->c6_P_ROM == 2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Same = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr =
          c6_IN_Transition_Increments1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Transition_Increments1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_c_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        c6_u0 = (uint32_T)chartInstance->c6_counter + (uint32_T)
          *chartInstance->c6_Transition_Add;
        if (CV_SATURATION_EVAL(4, 1, 0, 0, c6_u0 > 65535U)) {
          c6_u0 = 65535U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 20U, 39U, 24U);
        }

        c6_u1 = (uint32_T)(uint16_T)c6_u0 + (uint32_T)
          *chartInstance->c6_Transition_Zero;
        if (CV_SATURATION_EVAL(4, 1, 1, 0, c6_u1 > 65535U)) {
          c6_u1 = 65535U;
          _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 20U, 39U, 41U);
        }

        chartInstance->c6_counter = (uint16_T)c6_u1;
        _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c6_counter, 0U, 0.0,
          255.0, 20U, 30, 50);
        *chartInstance->c6_Trans = chartInstance->c6_counter;
        chartInstance->c6_dataWrittenToVector[0U] = true;
        chartInstance->c6_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Trans, 4U);
        *chartInstance->c6_Internal_counter = chartInstance->c6_counter;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Internal_counter, 5U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_d_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_d_out = CV_EML_IF(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
          *chartInstance->c6_P_ROM, 1.0, -1, 0U, *chartInstance->c6_P_ROM == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_Transition_Same = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr =
            c6_IN_Transition_Increments;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_Transition_Increments = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          c6_u2 = (uint32_T)chartInstance->c6_counter + (uint32_T)
            *chartInstance->c6_Transition_Add;
          if (CV_SATURATION_EVAL(4, 0, 0, 0, c6_u2 > 65535U)) {
            c6_u2 = 65535U;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 10U, 38U, 24U);
          }

          c6_u3 = (uint32_T)(uint16_T)c6_u2 + (uint32_T)
            *chartInstance->c6_Transition_Zero;
          if (CV_SATURATION_EVAL(4, 0, 1, 0, c6_u3 > 65535U)) {
            c6_u3 = 65535U;
            _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 10U, 38U, 41U);
          }

          chartInstance->c6_counter = (uint16_T)c6_u3;
          _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c6_counter, 0U,
            0.0, 255.0, 10U, 29, 50);
          *chartInstance->c6_Trans = chartInstance->c6_counter;
          chartInstance->c6_dataWrittenToVector[0U] = true;
          chartInstance->c6_dataWrittenToVector[0U] = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Trans, 4U);
          *chartInstance->c6_Internal_counter = chartInstance->c6_counter;
          chartInstance->c6_dataWrittenToVector[1U] = true;
          chartInstance->c6_dataWrittenToVector[1U] = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Internal_counter, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c6_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
      break;

     default:
      CV_CHART_EVAL(4, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c6_is_c6_GenOptRockerMomtryDisHndlr = c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_GenOptRockerMomtryDisHndlr
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_enter_atomic_Transition_Same
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[2];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 0.0;
  uint32_T c6_u4;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  c6_u4 = (uint32_T)*chartInstance->c6_Transition_Zero + (uint32_T)
    chartInstance->c6_counter;
  if (CV_SATURATION_EVAL(4, 2, 0, 0, c6_u4 > 65535U)) {
    c6_u4 = 65535U;
    _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 32U, 25U);
  }

  chartInstance->c6_counter = (uint16_T)c6_u4;
  _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c6_counter, 0U, 0.0,
    255.0, 1U, 23, 34);
  *chartInstance->c6_Trans = chartInstance->c6_counter;
  chartInstance->c6_dataWrittenToVector[0U] = true;
  chartInstance->c6_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Trans, 4U);
  *chartInstance->c6_Internal_counter = chartInstance->c6_counter;
  chartInstance->c6_dataWrittenToVector[1U] = true;
  chartInstance->c6_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c6_Internal_counter, 5U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)(c6_machineNumber);
  (void)(c6_chartNumber);
  (void)(c6_instanceNumber);
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d1;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d1, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_b_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  boolean_T c6_y;
  boolean_T c6_b0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b0, 1, 11, 0U, 0, 0U, 0);
  c6_y = c6_b0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_sf_internal_predicateOutput;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_sf_internal_predicateOutput = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_sf_internal_predicateOutput), &c6_thisId);
  sf_mex_destroy(&c6_sf_internal_predicateOutput);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_c_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i1;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i1, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  uint8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint8_T c6_d_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_tp_Transition_Increments, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_tp_Transition_Increments), &c6_thisId);
  sf_mex_destroy(&c6_b_tp_Transition_Increments);
  return c6_y;
}

static uint8_T c6_e_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u5;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u5, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u5;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_tp_Transition_Increments;
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_b_tp_Transition_Increments = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_tp_Transition_Increments), &c6_thisId);
  sf_mex_destroy(&c6_b_tp_Transition_Increments);
  *(uint8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  uint16_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint16_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint16_T c6_f_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_Trans, const char_T *c6_identifier)
{
  uint16_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Trans), &c6_thisId);
  sf_mex_destroy(&c6_b_Trans);
  return c6_y;
}

static uint16_T c6_g_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint16_T c6_y;
  uint16_T c6_u6;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u6, 1, 5, 0U, 0, 0U, 0);
  c6_y = c6_u6;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_Trans;
  emlrtMsgIdentifier c6_thisId;
  uint16_T c6_y;
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c6_b_Trans = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_Trans), &c6_thisId);
  sf_mex_destroy(&c6_b_Trans);
  *(uint16_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_h_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_b_dataWrittenToVector, const char_T
  *c6_identifier, boolean_T c6_y[2])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_dataWrittenToVector),
                        &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_dataWrittenToVector);
}

static void c6_i_emlrt_marshallIn(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_y[2])
{
  boolean_T c6_bv1[2];
  int32_T c6_i2;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv1, 1, 11, 0U, 1, 0U, 1, 2);
  for (c6_i2 = 0; c6_i2 < 2; c6_i2++) {
    c6_y[c6_i2] = c6_bv1[c6_i2];
  }

  sf_mex_destroy(&c6_u);
}

static const mxArray *c6_j_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_b_setSimStateSideEffectsInfo, const char_T *c6_identifier)
{
  const mxArray *c6_y = NULL;
  emlrtMsgIdentifier c6_thisId;
  c6_y = NULL;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  sf_mex_assign(&c6_y, c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), false);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_k_emlrt_marshallIn
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), false);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c6_ssid)
{
  (void)chartInstance;
  (void)c6_ssid;
  return NULL;
}

static void c6_init_sf_message_store_memory
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_Trans = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_Transition_Add = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_Transition_Zero = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_P_ROM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c6_Internal_counter = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c6_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2486482941U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(243095940U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3509977421U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(73302094U);
}

mxArray* sf_c6_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void);
mxArray *sf_c6_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uZ3ueZF5QBAqyVeZuR7RHG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c6_GenOptRockerMomtryDisHndlr_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_GenOptRockerMomtryDisHndlr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_GenOptRockerMomtryDisHndlr_jit_fallback_info(void)
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

mxArray *sf_c6_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_GenOptRockerMomtryDisHndlr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[14],T\"Internal_counter\",},{M[1],M[3],T\"Trans\",},{M[3],M[4],T\"counter\",},{M[8],M[0],T\"is_active_c6_GenOptRockerMomtryDisHndlr\",},{M[9],M[0],T\"is_c6_GenOptRockerMomtryDisHndlr\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_GenOptRockerMomtryDisHndlr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg
    ( (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *) chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GenOptRockerMomtryDisHndlrMachineNumber_,
           6,
           3,
           5,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_GenOptRockerMomtryDisHndlrMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _GenOptRockerMomtryDisHndlrMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _GenOptRockerMomtryDisHndlrMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"counter");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Transition_Add");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Transition_Zero");
          _SFD_SET_DATA_PROPS(3,1,1,0,"P_ROM");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Trans");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Internal_counter");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,38,-1,62);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,38,-1,79);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(2,1,0,32,-1,57);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(1,1,0,39,-1,63);
        _SFD_CV_INIT_EML_SATURATION(1,1,1,39,-1,80);
        _SFD_CV_INIT_EML(0,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 9, 22 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,1,13,22,-1,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 9, 22 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,9,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,13,22,-1,0);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,9,1,9);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,9,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)c6_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)c6_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)c6_e_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _GenOptRockerMomtryDisHndlrMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c6_Trans);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c6_counter);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c6_Transition_Add);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c6_Transition_Zero);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c6_P_ROM);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c6_Internal_counter);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "spCu5NVzbDcKZaXTqtFkIlB";
}

static void sf_opaque_initialize_c6_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
  initialize_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  enable_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  disable_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  sf_gateway_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_GenOptRockerMomtryDisHndlr
  (SimStruct* S)
{
  return get_sim_state_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_GenOptRockerMomtryDisHndlr(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c6_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GenOptRockerMomtryDisHndlr_optimization_info();
    }

    finalize_c6_GenOptRockerMomtryDisHndlr
      ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_GenOptRockerMomtryDisHndlr
    ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_GenOptRockerMomtryDisHndlr
      ((SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr
       (S));
  }
}

static void mdlSetWorkWidths_c6_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  /* Actual parameters from chart:
     Transition_Add
   */
  const char_T *rtParamNames[] = { "counter" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Transition_Add*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT16);
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GenOptRockerMomtryDisHndlr_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 6);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1589388231U));
  ssSetChecksum1(S,(2399872872U));
  ssSetChecksum2(S,(1906629133U));
  ssSetChecksum3(S,(1105928523U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc6_GenOptRockerMomtryDisHndlrInstanceStruct *)utMalloc
    (sizeof(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_GenOptRockerMomtryDisHndlrInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_GenOptRockerMomtryDisHndlr;
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
  mdl_start_c6_GenOptRockerMomtryDisHndlr(chartInstance);
}

void c6_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_GenOptRockerMomtryDisHndlr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_GenOptRockerMomtryDisHndlr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
