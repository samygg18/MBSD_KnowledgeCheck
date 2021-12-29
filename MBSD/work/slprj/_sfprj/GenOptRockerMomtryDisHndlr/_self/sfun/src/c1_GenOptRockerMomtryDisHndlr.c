/* Include files */

#include "GenOptRockerMomtryDisHndlr_sfun.h"
#include "c1_GenOptRockerMomtryDisHndlr.h"
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

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[9] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "signal_1", "signal_2", "signal_3", "Rocker_Mode_Input" };

/* Function Declarations */
static void initialize_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initialize_params_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void enable_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void disable_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void set_sim_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void sf_gateway_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void mdl_start_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void c1_chartstep_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void initSimStructsc1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c1_b_Rocker_Mode_Input, const char_T
  *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_GenOptRockerMomtryDisHndlr, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance);
static void init_simulink_io_address
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_GenOptRockerMomtryDisHndlr(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_GenOptRockerMomtryDisHndlr = 0U;
}

static void initialize_params_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_Rocker_Mode_Input;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_GenOptRockerMomtryDisHndlr;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_Rocker_Mode_Input = c1_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Rocker_Mode_Input");
  chartInstance->c1_is_active_c1_GenOptRockerMomtryDisHndlr =
    c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_GenOptRockerMomtryDisHndlr");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_GenOptRockerMomtryDisHndlr(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_signal_3, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_signal_2, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c1_signal_1, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_GenOptRockerMomtryDisHndlr(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GenOptRockerMomtryDisHndlrMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_Rocker_Mode_Input, 3U);
}

static void mdl_start_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c1_chartstep_c1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  boolean_T c1_b_signal_1;
  boolean_T c1_b_signal_2;
  boolean_T c1_b_signal_3;
  uint32_T c1_debug_family_var_map[9];
  boolean_T c1_aVarTruthTableCondition_1;
  boolean_T c1_aVarTruthTableCondition_2;
  boolean_T c1_aVarTruthTableCondition_3;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_b_Rocker_Mode_Input;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_b_signal_1 = *chartInstance->c1_signal_1;
  c1_b_signal_2 = *chartInstance->c1_signal_2;
  c1_b_signal_3 = *chartInstance->c1_signal_3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_1, 0U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_2, 1U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_aVarTruthTableCondition_3, 2U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_signal_1, 5U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_signal_2, 6U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_signal_3, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_Rocker_Mode_Input, 8U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_aVarTruthTableCondition_1 = c1_b_signal_1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_aVarTruthTableCondition_2 = c1_b_signal_2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_aVarTruthTableCondition_3 = c1_b_signal_3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  if ((!CV_EML_COND(0, 1, 0, c1_aVarTruthTableCondition_1)) && (!CV_EML_COND(0,
        1, 1, c1_aVarTruthTableCondition_2)) && (!CV_EML_COND(0, 1, 2,
        c1_aVarTruthTableCondition_3))) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
    CV_EML_FCN(0, 4);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
    c1_b_Rocker_Mode_Input = 3.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -60);
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
    if ((!CV_EML_COND(0, 1, 3, c1_aVarTruthTableCondition_1)) && (!CV_EML_COND(0,
          1, 4, c1_aVarTruthTableCondition_2)) && CV_EML_COND(0, 1, 5,
         c1_aVarTruthTableCondition_3)) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
      c1_b_Rocker_Mode_Input = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -42);
    } else {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 1, false);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      if ((!CV_EML_COND(0, 1, 6, c1_aVarTruthTableCondition_1)) && CV_EML_COND(0,
           1, 7, c1_aVarTruthTableCondition_2) && (!CV_EML_COND(0, 1, 8,
            c1_aVarTruthTableCondition_3))) {
        CV_EML_MCDC(0, 1, 2, true);
        CV_EML_IF(0, 1, 2, true);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
        CV_EML_FCN(0, 4);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
        c1_b_Rocker_Mode_Input = 3.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -60);
      } else {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 2, false);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
        if ((!CV_EML_COND(0, 1, 9, c1_aVarTruthTableCondition_1)) && CV_EML_COND
            (0, 1, 10, c1_aVarTruthTableCondition_2) && CV_EML_COND(0, 1, 11,
             c1_aVarTruthTableCondition_3)) {
          CV_EML_MCDC(0, 1, 3, true);
          CV_EML_IF(0, 1, 3, true);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
          CV_EML_FCN(0, 4);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
          c1_b_Rocker_Mode_Input = 3.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -60);
        } else {
          CV_EML_MCDC(0, 1, 3, false);
          CV_EML_IF(0, 1, 3, false);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
          if (CV_EML_COND(0, 1, 12, c1_aVarTruthTableCondition_1) &&
              (!CV_EML_COND(0, 1, 13, c1_aVarTruthTableCondition_2)) &&
              (!CV_EML_COND(0, 1, 14, c1_aVarTruthTableCondition_3))) {
            CV_EML_MCDC(0, 1, 4, true);
            CV_EML_IF(0, 1, 4, true);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
            CV_EML_FCN(0, 3);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
            c1_b_Rocker_Mode_Input = 2.0;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -54);
          } else {
            CV_EML_MCDC(0, 1, 4, false);
            CV_EML_IF(0, 1, 4, false);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
            if (CV_EML_COND(0, 1, 15, c1_aVarTruthTableCondition_1) &&
                (!CV_EML_COND(0, 1, 16, c1_aVarTruthTableCondition_2)) &&
                CV_EML_COND(0, 1, 17, c1_aVarTruthTableCondition_3)) {
              CV_EML_MCDC(0, 1, 5, true);
              CV_EML_IF(0, 1, 5, true);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
              CV_EML_FCN(0, 4);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
              c1_b_Rocker_Mode_Input = 3.0;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -60);
            } else {
              CV_EML_MCDC(0, 1, 5, false);
              CV_EML_IF(0, 1, 5, false);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
              if (CV_EML_COND(0, 1, 18, c1_aVarTruthTableCondition_1) &&
                  CV_EML_COND(0, 1, 19, c1_aVarTruthTableCondition_2) &&
                  (!CV_EML_COND(0, 1, 20, c1_aVarTruthTableCondition_3))) {
                CV_EML_MCDC(0, 1, 6, true);
                CV_EML_IF(0, 1, 6, true);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
                CV_EML_FCN(0, 4);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
                c1_b_Rocker_Mode_Input = 3.0;
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -60);
              } else {
                CV_EML_MCDC(0, 1, 6, false);
                CV_EML_IF(0, 1, 6, false);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
                CV_EML_FCN(0, 2);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
                c1_b_Rocker_Mode_Input = 1.0;
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -48);
              }
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c1_Rocker_Mode_Input = c1_b_Rocker_Mode_Input;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_GenOptRockerMomtryDisHndlr
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance, const mxArray *c1_b_Rocker_Mode_Input, const char_T
  *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Rocker_Mode_Input),
    &c1_thisId);
  sf_mex_destroy(&c1_b_Rocker_Mode_Input);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Rocker_Mode_Input;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_b_Rocker_Mode_Input = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Rocker_Mode_Input),
    &c1_thisId);
  sf_mex_destroy(&c1_b_Rocker_Mode_Input);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_aVarTruthTableCondition_3;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_aVarTruthTableCondition_3 = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_aVarTruthTableCondition_3), &c1_thisId);
  sf_mex_destroy(&c1_aVarTruthTableCondition_3);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_thisId.fIdentifier = (const char *)c1_varName;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_GenOptRockerMomtryDisHndlr, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_GenOptRockerMomtryDisHndlr), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_GenOptRockerMomtryDisHndlr);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_signal_1 = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_signal_2 = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_Rocker_Mode_Input = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_signal_3 = (boolean_T *)ssGetInputPortSignal_wrapper
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

void sf_c1_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1587618963U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2961334882U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(903738110U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4056513464U);
}

mxArray* sf_c1_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void);
mxArray *sf_c1_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("MaznIPwIwV7tkbvAAwL0GG");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_GenOptRockerMomtryDisHndlr_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_GenOptRockerMomtryDisHndlr_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_GenOptRockerMomtryDisHndlr_jit_fallback_info(void)
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

mxArray *sf_c1_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_GenOptRockerMomtryDisHndlr_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_GenOptRockerMomtryDisHndlr(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rocker_Mode_Input\",},{M[8],M[0],T\"is_active_c1_GenOptRockerMomtryDisHndlr\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_GenOptRockerMomtryDisHndlr_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GenOptRockerMomtryDisHndlrMachineNumber_,
           1,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"signal_1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"signal_2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"signal_3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Rocker_Mode_Input");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,5,0,7,0,0,0,0,0,21,7);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,1285);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",1285,-1,1355);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",1355,-1,1425);
        _SFD_CV_INIT_EML_FCN(0,3,"aFcnTruthTableAction_3",1425,-1,1496);
        _SFD_CV_INIT_EML_FCN(0,4,"aFcnTruthTableAction_4",1496,-1,1563);
        _SFD_CV_INIT_EML_IF(0,1,0,366,457,488,1283);
        _SFD_CV_INIT_EML_IF(0,1,1,488,582,613,1283);
        _SFD_CV_INIT_EML_IF(0,1,2,613,707,738,1283);
        _SFD_CV_INIT_EML_IF(0,1,3,738,831,862,1283);
        _SFD_CV_INIT_EML_IF(0,1,4,862,956,987,1283);
        _SFD_CV_INIT_EML_IF(0,1,5,987,1080,1111,1283);
        _SFD_CV_INIT_EML_IF(0,1,6,1111,1204,1235,1283);

        {
          static int condStart[] = { 371, 401, 431 };

          static int condEnd[] = { 396, 426, 456 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,370,456,3,0,&(condStart[0]),&(condEnd[0]),
                                8,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 497, 527, 556 };

          static int condEnd[] = { 522, 552, 581 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,496,581,3,3,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 622, 651, 681 };

          static int condEnd[] = { 647, 676, 706 };

          static int pfixExpr[] = { 0, -1, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,621,706,3,6,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 747, 776, 805 };

          static int condEnd[] = { 772, 801, 830 };

          static int pfixExpr[] = { 0, -1, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,746,830,3,9,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 870, 900, 930 };

          static int condEnd[] = { 895, 925, 955 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,870,955,3,12,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 995, 1025, 1054 };

          static int condEnd[] = { 1020, 1050, 1079 };

          static int pfixExpr[] = { 0, 1, -1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,5,995,1079,3,15,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1119, 1148, 1178 };

          static int condEnd[] = { 1144, 1173, 1203 };

          static int pfixExpr[] = { 0, 1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,6,1119,1203,3,18,&(condStart[0]),&(condEnd[0]),
                                6,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
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
    SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance =
      (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
      (S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_signal_1);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_signal_2);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_Rocker_Mode_Input);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_signal_3);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sf7aiPuXf43ZtnCSObrvncG";
}

static void sf_opaque_initialize_c1_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
  initialize_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  enable_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  disable_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  sf_gateway_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_GenOptRockerMomtryDisHndlr
  (SimStruct* S)
{
  return get_sim_state_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)sf_get_chart_instance_ptr
     (S));                             /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_GenOptRockerMomtryDisHndlr(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c1_GenOptRockerMomtryDisHndlr(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GenOptRockerMomtryDisHndlr_optimization_info();
    }

    finalize_c1_GenOptRockerMomtryDisHndlr
      ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_GenOptRockerMomtryDisHndlr
    ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_GenOptRockerMomtryDisHndlr
      ((SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*)sf_get_chart_instance_ptr
       (S));
  }
}

static void mdlSetWorkWidths_c1_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_GenOptRockerMomtryDisHndlr_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1084981851U));
  ssSetChecksum1(S,(3204066490U));
  ssSetChecksum2(S,(1440493286U));
  ssSetChecksum3(S,(1939933120U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c1_GenOptRockerMomtryDisHndlr(SimStruct *S)
{
  SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *chartInstance;
  chartInstance = (SFc1_GenOptRockerMomtryDisHndlrInstanceStruct *)utMalloc
    (sizeof(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_GenOptRockerMomtryDisHndlrInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_GenOptRockerMomtryDisHndlr;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
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
  mdl_start_c1_GenOptRockerMomtryDisHndlr(chartInstance);
}

void c1_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_GenOptRockerMomtryDisHndlr(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_GenOptRockerMomtryDisHndlr(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_GenOptRockerMomtryDisHndlr_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
