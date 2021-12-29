/* Include files */

#include "GenOptRockerMomtryDisHndlr_sfun.h"
#include "c2_GenOptRockerMomtryDisHndlr.h"
#include "mwmathutil.h"
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
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_HeldLong                 ((uint8_T)1U)
#define c2_IN_HeldShort                ((uint8_T)2U)
#define c2_IN_On                       ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c2_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c2_sv0[4] = { "EnCtrlDisStIsOff", "EnCtrlDisStIsOn",
  "EnCtrlDisStIsHoldSho", "EnCtrlDisStIsHoldLong" };

static const int32_T c2_iv0[4] = { 0, 1, 2, 3 };

/* Function Declarations */
static void initialize_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initialize_params_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void enable_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void disable_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void set_sim_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void finalize_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void sf_gateway_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void mdl_start_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initSimStructsc2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_b_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_d_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_On, const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static c2_EnCtrlDisSt c2_f_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_State, const char_T *c2_identifier);
static c2_EnCtrlDisSt c2_g_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_h_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_temporalCounter_i1, const char_T *c2_identifier);
static uint32_T c2_i_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_b_dataWrittenToVector, const char_T
  *c2_identifier, boolean_T c2_y[1]);
static void c2_k_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_y[1]);
static const mxArray *c2_l_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_m_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static uint32_T c2__u32_d_(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct
  *chartInstance, real_T c2_b, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc);
static void init_dsm_address_info(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance);
static void init_simulink_io_address
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_GenOptRockerMomtryDisHndlr(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_HeldLong = 0U;
  chartInstance->c2_tp_HeldShort = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_On = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr = 0U;
  chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_HeldShort) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_HeldLong) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  c2_EnCtrlDisSt c2_hoistedGlobal;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_u;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_m0 = NULL;
  uint8_T c2_b_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  uint32_T c2_d_hoistedGlobal;
  const mxArray *c2_f_y = NULL;
  const mxArray *c2_g_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_State;
  c2_b_y = NULL;
  sf_mex_check_enum("EnCtrlDisSt", 4, c2_sv0, c2_iv0);
  c2_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_m0, c2_c_y, false);
  sf_mex_assign(&c2_b_y, sf_mex_create_enum("EnCtrlDisSt", c2_m0), false);
  sf_mex_destroy(&c2_m0);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 1, c2_d_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 2, c2_e_y);
  c2_d_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 3, c2_f_y);
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y",
    chartInstance->c2_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 1), false);
  sf_mex_setcell(c2_y, 4, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  boolean_T c2_bv0[1];
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_State = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "State");
  chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_GenOptRockerMomtryDisHndlr");
  chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_c2_GenOptRockerMomtryDisHndlr");
  chartInstance->c2_temporalCounter_i1 = c2_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "temporalCounter_i1");
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                        "dataWrittenToVector", c2_bv0);
  chartInstance->c2_dataWrittenToVector[0] = c2_bv0[0];
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_GenOptRockerMomtryDisHndlr(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_tp_HeldLong = (uint8_T)
      (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_HeldLong);
    if (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_HeldShort) {
      chartInstance->c2_tp_HeldShort = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_HeldShort = 0U;
    }

    if (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr == c2_IN_On) {
      chartInstance->c2_tp_On = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_On = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c2_debug_family_var_map[2];
  uint32_T c2_b_debug_family_var_map[3];
  real_T c2_nargin = 0.0;
  real_T c2_b_nargin = 0.0;
  real_T c2_c_nargin = 0.0;
  real_T c2_nargout = 0.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_out;
  boolean_T c2_b_out;
  real_T c2_d_nargin = 0.0;
  real_T c2_e_nargin = 0.0;
  real_T c2_d_nargout = 0.0;
  real_T c2_e_nargout = 0.0;
  c2_set_sim_state_side_effects_c2_GenOptRockerMomtryDisHndlr(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c2_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c2_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EolDurnSho, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_EolDurnLong, 0U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_GenOptRockerMomtryDisHndlr = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_IN_On;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_On = 1U;
  } else {
    switch (chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr) {
     case c2_IN_HeldLong:
      CV_CHART_EVAL(1, 0, c2_IN_HeldLong);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_c_debug_family_names,
        c2_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      *chartInstance->c2_State = c2_EnCtrlDisSt_EnCtrlDisStIsHoldLong;
      chartInstance->c2_dataWrittenToVector[0U] = true;
      chartInstance->c2_dataWrittenToVector[0U] = true;
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_HeldShort:
      CV_CHART_EVAL(1, 0, c2_IN_HeldShort);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_e_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_out, 2U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      c2_out = CV_EML_IF(2, 0, 0, chartInstance->c2_temporalCounter_i1 >=
                         c2__u32_d_(chartInstance, muDoubleScalarCeil
        (*chartInstance->c2_EolDurnLong * 100.0), 6U, 1U, 23U));
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_HeldShort = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_IN_HeldLong;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_HeldLong = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_b_debug_family_names,
          c2_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        *chartInstance->c2_State = c2_EnCtrlDisSt_EnCtrlDisStIsHoldSho;
        chartInstance->c2_dataWrittenToVector[0U] = true;
        chartInstance->c2_dataWrittenToVector[0U] = true;
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_On:
      CV_CHART_EVAL(1, 0, c2_IN_On);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c2_d_debug_family_names,
        c2_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_out, 2U, c2_b_sf_marshallOut,
        c2_b_sf_marshallIn);
      c2_b_out = CV_EML_IF(1, 0, 0, chartInstance->c2_temporalCounter_i1 >=
                           c2__u32_d_(chartInstance, muDoubleScalarCeil
        (*chartInstance->c2_EolDurnSho * 100.0), 5U, 1U, 22U));
      _SFD_SYMBOL_SCOPE_POP();
      if (c2_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_On = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_IN_HeldShort;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_HeldShort = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c2_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c2_debug_family_names,
          c2_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
          c2_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U,
          c2_sf_marshallOut, c2_sf_marshallIn);
        *chartInstance->c2_State = c2_EnCtrlDisSt_EnCtrlDisStIsOn;
        chartInstance->c2_dataWrittenToVector[0U] = true;
        chartInstance->c2_dataWrittenToVector[0U] = true;
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c2_is_c2_GenOptRockerMomtryDisHndlr = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GenOptRockerMomtryDisHndlrMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  c2_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc2_GenOptRockerMomtryDisHndlr
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_b_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sf_internal_predicateOutput;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_sf_internal_predicateOutput = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_sf_internal_predicateOutput), &c2_thisId);
  sf_mex_destroy(&c2_sf_internal_predicateOutput);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  const char * c2_data[4] = {
    "789c6360f4f465646060e0036226205ec0c60006bc108a41004a3331a0027479461c340cb032b0a0e883c9cf81d2c9f97925a91525104e4e665eaa5f696e526a"
    "11909397989b0a3726253f37332f31af24a4b22095a128b5383fa72c35052c939699931a92999bea938fc4f1c8047272dd90a4e01c901488ed9c919a9c1d5c9a",
    "cb5094518c706e0e328701297c1270f89f8540f8a003f4f0415747c83e3602f6118a0f4e060e24de077b987d0538cc23e43f98f9dc38ec13409377cd732e29ca"
    "71c92c0e86c4f94085ef0a32ed8399ef4ac03e987cb45facb3957e485162665e665ebabe775e7e794e6a4a7aaa0238fde9bbfb07f9ba78e8fb3a05bbe8bbe695",
    "e6a616259664e6e715eb2385935e2e033dd345c3cca939371ce99b0ee99dee07cebe0a1ce6119beec470d82780269fe69aecea96919c6d1e5554506c12169c12"
    "561c6cea82704700017b08b98301079fd6e603005d9a5cf3", "" };

  c2_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c2_data, 1720U, &c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_d_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_tp_On, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_On), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_On);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_On;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_b_tp_On = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_On), &c2_thisId);
  sf_mex_destroy(&c2_b_tp_On);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_EnCtrlDisSt c2_u;
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_m1 = NULL;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_EnCtrlDisSt *)c2_inData;
  c2_y = NULL;
  sf_mex_check_enum("EnCtrlDisSt", 4, c2_sv0, c2_iv0);
  c2_b_u = c2_u;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_m1, c2_b_y, false);
  sf_mex_assign(&c2_y, sf_mex_create_enum("EnCtrlDisSt", c2_m1), false);
  sf_mex_destroy(&c2_m1);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static c2_EnCtrlDisSt c2_f_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_State, const char_T *c2_identifier)
{
  c2_EnCtrlDisSt c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_State), &c2_thisId);
  sf_mex_destroy(&c2_b_State);
  return c2_y;
}

static c2_EnCtrlDisSt c2_g_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_EnCtrlDisSt c2_y;
  (void)chartInstance;
  sf_mex_check_enum("EnCtrlDisSt", 4, c2_sv0, c2_iv0);
  sf_mex_check_builtin(c2_parentId, c2_u, "EnCtrlDisSt", 0, 0U, NULL);
  c2_y = (c2_EnCtrlDisSt)sf_mex_get_enum_element(c2_u, 0);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_State;
  emlrtMsgIdentifier c2_thisId;
  c2_EnCtrlDisSt c2_y;
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c2_b_State = sf_mex_dup(c2_mxArrayInData);
  c2_thisId.fIdentifier = (const char *)c2_varName;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_State), &c2_thisId);
  sf_mex_destroy(&c2_b_State);
  *(c2_EnCtrlDisSt *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_h_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_temporalCounter_i1, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_temporalCounter_i1),
    &c2_thisId);
  sf_mex_destroy(&c2_b_temporalCounter_i1);
  return c2_y;
}

static uint32_T c2_i_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u1;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 7, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_b_dataWrittenToVector, const char_T
  *c2_identifier, boolean_T c2_y[1])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_dataWrittenToVector),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_dataWrittenToVector);
}

static void c2_k_emlrt_marshallIn(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_y[1])
{
  boolean_T c2_bv1[1];
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_bv1, 1, 11, 0U, 1, 0U, 1, 1);
  c2_y[0] = c2_bv1[0];
  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_l_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_m_emlrt_marshallIn
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c2_ssid)
{
  (void)chartInstance;
  (void)c2_ssid;
  return NULL;
}

static void c2_init_sf_message_store_memory
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static uint32_T c2__u32_d_(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct
  *chartInstance, real_T c2_b, uint32_T c2_ssid_src_loc, int32_T
  c2_offset_src_loc, int32_T c2_length_src_loc)
{
  uint32_T c2_a;
  (void)chartInstance;
  c2_a = (uint32_T)c2_b;
  if ((c2_b < 0.0) || ((real_T)c2_a != muDoubleScalarFloor(c2_b))) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c2_ssid_src_loc, c2_offset_src_loc,
      c2_length_src_loc);
  }

  return c2_a;
}

static void init_dsm_address_info(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_State = (c2_EnCtrlDisSt *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_EolDurnLong = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_EolDurnSho = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c2_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2910438865U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(646050850U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3892400819U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2851998012U);
}

mxArray* sf_c2_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void);
mxArray *sf_c2_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("up31ONLvotL98Z3u7zAuiF");
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_GenOptRockerMomtryDisHndlr_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_GenOptRockerMomtryDisHndlr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_GenOptRockerMomtryDisHndlr_jit_fallback_info(void)
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

mxArray *sf_c2_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_GenOptRockerMomtryDisHndlr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"State\",},{M[8],M[0],T\"is_active_c2_GenOptRockerMomtryDisHndlr\",},{M[9],M[0],T\"is_c2_GenOptRockerMomtryDisHndlr\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[1 4],M[1]}}},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_GenOptRockerMomtryDisHndlr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg
    ( (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *) chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GenOptRockerMomtryDisHndlrMachineNumber_,
           2,
           3,
           3,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"EolDurnLong");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EolDurnSho");
          _SFD_SET_DATA_PROPS(2,2,0,1,"State");
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,24,1,24);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)c2_e_sf_marshallIn);
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
    SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_State);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_EolDurnLong);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_EolDurnSho);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sfwfKKMim79HPb8BDCB1UN";
}

static void sf_opaque_initialize_c2_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
  initialize_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  enable_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  disable_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  sf_gateway_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_GenOptRockerMomtryDisHndlr
  (SimStruct* S)
{
  return get_sim_state_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_GenOptRockerMomtryDisHndlr(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c2_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GenOptRockerMomtryDisHndlr_optimization_info();
    }

    finalize_c2_GenOptRockerMomtryDisHndlr
      ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_GenOptRockerMomtryDisHndlr
    ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_GenOptRockerMomtryDisHndlr
      ((SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr
       (S));
  }
}

static void mdlSetWorkWidths_c2_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GenOptRockerMomtryDisHndlr_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1885366620U));
  ssSetChecksum1(S,(1038256679U));
  ssSetChecksum2(S,(910208350U));
  ssSetChecksum3(S,(1796375339U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc2_GenOptRockerMomtryDisHndlrInstanceStruct *)utMalloc
    (sizeof(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_GenOptRockerMomtryDisHndlrInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_GenOptRockerMomtryDisHndlr;
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
  mdl_start_c2_GenOptRockerMomtryDisHndlr(chartInstance);
}

void c2_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_GenOptRockerMomtryDisHndlr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_GenOptRockerMomtryDisHndlr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
