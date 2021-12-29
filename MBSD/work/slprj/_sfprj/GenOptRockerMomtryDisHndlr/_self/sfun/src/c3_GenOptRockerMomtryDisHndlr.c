/* Include files */

#include "GenOptRockerMomtryDisHndlr_sfun.h"
#include "c3_GenOptRockerMomtryDisHndlr.h"
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
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initialize_params_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void enable_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void disable_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void set_sim_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void c3_set_sim_state_side_effects_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void finalize_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void sf_gateway_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void mdl_start_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initSimStructsc3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_b_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint16_T c3_d_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_Internal_counter, const char_T *c3_identifier);
static uint16_T c3_e_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_GenOptRockerMomtryDisHndlr, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[2]);
static void c3_i_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[2]);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance);
static void init_simulink_io_address
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_GenOptRockerMomtryDisHndlr(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_is_active_c3_GenOptRockerMomtryDisHndlr = 0U;
  chartInstance->c3_counter = 0U;
  _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c3_counter, 0U, 0.0,
    255.0, 0U, 0, 0);
}

static void initialize_params_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint16_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  uint16_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  uint16_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  const mxArray *c3_f_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(5, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_Internal_counter;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 5, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_Trans;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_counter;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_is_active_c3_GenOptRockerMomtryDisHndlr;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[2];
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_Internal_counter = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 0)), "Internal_counter");
  *chartInstance->c3_Trans = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "Trans");
  chartInstance->c3_counter = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "counter");
  chartInstance->c3_is_active_c3_GenOptRockerMomtryDisHndlr =
    c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "is_active_c3_GenOptRockerMomtryDisHndlr");
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
                        "dataWrittenToVector", c3_bv0);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    chartInstance->c3_dataWrittenToVector[c3_i0] = c3_bv0[c3_i0];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_GenOptRockerMomtryDisHndlr(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  uint32_T c3_u0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_u1;
  uint32_T c3_u2;
  c3_set_sim_state_side_effects_c3_GenOptRockerMomtryDisHndlr(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Transition_Zero, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Transition_Add, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_P_ROM, 1U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
        *chartInstance->c3_P_ROM, 1.0, -1, 0U, *chartInstance->c3_P_ROM == 1.0))
      || CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
        *chartInstance->c3_P_ROM, 2.0, -1, 0U, *chartInstance->c3_P_ROM == 2.0)))
  {
    CV_EML_MCDC(1, 0, 0, true);
    CV_EML_IF(1, 0, 0, true);
    c3_out = true;
  } else {
    CV_EML_MCDC(1, 0, 0, false);
    CV_EML_IF(1, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_u1 = (uint32_T)*chartInstance->c3_Transition_Zero + (uint32_T)
      chartInstance->c3_counter;
    if (CV_SATURATION_EVAL(5, 3, 0, 0, c3_u1 > 65535U)) {
      c3_u1 = 65535U;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 41U, 10U, 25U);
    }

    c3_u2 = (uint32_T)(uint16_T)c3_u1 + (uint32_T)
      *chartInstance->c3_Transition_Add;
    if (CV_SATURATION_EVAL(5, 3, 1, 0, c3_u2 > 65535U)) {
      c3_u2 = 65535U;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 41U, 10U, 42U);
    }

    chartInstance->c3_counter = (uint16_T)c3_u2;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c3_counter, 0U, 0.0,
      255.0, 41U, 1, 51);
    *chartInstance->c3_Trans = chartInstance->c3_counter;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Trans, 5U);
    *chartInstance->c3_Internal_counter = chartInstance->c3_counter;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Internal_counter, 4U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    c3_u0 = (uint32_T)*chartInstance->c3_Transition_Zero + (uint32_T)
      chartInstance->c3_counter;
    if (CV_SATURATION_EVAL(5, 2, 0, 0, c3_u0 > 65535U)) {
      c3_u0 = 65535U;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 40U, 10U, 25U);
    }

    chartInstance->c3_counter = (uint16_T)c3_u0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)chartInstance->c3_counter, 0U, 0.0,
      255.0, 40U, 1, 34);
    *chartInstance->c3_Trans = chartInstance->c3_counter;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Trans, 5U);
    *chartInstance->c3_Internal_counter = chartInstance->c3_counter;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    chartInstance->c3_dataWrittenToVector[0U] = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_Internal_counter, 4U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GenOptRockerMomtryDisHndlrMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_GenOptRockerMomtryDisHndlr
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_b_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint16_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint16_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint16_T c3_d_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_Internal_counter, const char_T *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Internal_counter),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Internal_counter);
  return c3_y;
}

static uint16_T c3_e_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Internal_counter;
  emlrtMsgIdentifier c3_thisId;
  uint16_T c3_y;
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c3_b_Internal_counter = sf_mex_dup(c3_mxArrayInData);
  c3_thisId.fIdentifier = (const char *)c3_varName;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Internal_counter),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Internal_counter);
  *(uint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_GenOptRockerMomtryDisHndlr, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_GenOptRockerMomtryDisHndlr), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_GenOptRockerMomtryDisHndlr);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u4;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u4, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u4;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_i_emlrt_marshallIn(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[2])
{
  boolean_T c3_bv1[2];
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 2);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_y[c3_i2] = c3_bv1[c3_i2];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, int32_T c3_ssid)
{
  (void)chartInstance;
  (void)c3_ssid;
  return NULL;
}

static void c3_init_sf_message_store_memory
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_P_ROM = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_Transition_Add = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_Transition_Zero = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_Internal_counter = (uint16_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_Trans = (uint16_T *)ssGetOutputPortSignal_wrapper
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

void sf_c3_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3071030676U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(896047021U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3487477270U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1711204195U);
}

mxArray* sf_c3_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void);
mxArray *sf_c3_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oCKhp5qHOTC815PLBVS9JH");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      sf_c3_GenOptRockerMomtryDisHndlr_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_GenOptRockerMomtryDisHndlr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_GenOptRockerMomtryDisHndlr_jit_fallback_info(void)
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

mxArray *sf_c3_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_GenOptRockerMomtryDisHndlr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[51],T\"Internal_counter\",},{M[1],M[52],T\"Trans\",},{M[3],M[53],T\"counter\",},{M[8],M[0],T\"is_active_c3_GenOptRockerMomtryDisHndlr\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_GenOptRockerMomtryDisHndlr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg
    ( (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *) chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GenOptRockerMomtryDisHndlrMachineNumber_,
           3,
           0,
           6,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"P_ROM");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Transition_Add");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Transition_Zero");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Internal_counter");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Trans");
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,0,0,0,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(3,0,0,10,-1,35);
        _SFD_CV_INIT_EML_SATURATION(3,0,1,10,-1,52);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 14 };

          static int condEnd[] = { 10, 22 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,10,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,14,22,-1,0);
        _SFD_CV_INIT_EML(2,0,0,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_SATURATION(2,0,0,10,-1,35);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
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
    SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_P_ROM);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_Transition_Add);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_Transition_Zero);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c3_Internal_counter);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c3_Trans);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c3_counter);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sWfqQtPWFP9TSaQLBPkWO1E";
}

static void sf_opaque_initialize_c3_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
  initialize_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  enable_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  disable_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  sf_gateway_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_GenOptRockerMomtryDisHndlr
  (SimStruct* S)
{
  return get_sim_state_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_GenOptRockerMomtryDisHndlr(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c3_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GenOptRockerMomtryDisHndlr_optimization_info();
    }

    finalize_c3_GenOptRockerMomtryDisHndlr
      ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_GenOptRockerMomtryDisHndlr
    ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_GenOptRockerMomtryDisHndlr
      ((SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr
       (S));
  }
}

static void mdlSetWorkWidths_c3_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4126583670U));
  ssSetChecksum1(S,(374018318U));
  ssSetChecksum2(S,(3268817173U));
  ssSetChecksum3(S,(3851152388U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc3_GenOptRockerMomtryDisHndlrInstanceStruct *)utMalloc
    (sizeof(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_GenOptRockerMomtryDisHndlrInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_GenOptRockerMomtryDisHndlr;
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
  mdl_start_c3_GenOptRockerMomtryDisHndlr(chartInstance);
}

void c3_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_GenOptRockerMomtryDisHndlr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_GenOptRockerMomtryDisHndlr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
