/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slSimTgtLogLoadBlocksSfcnBridge.h"
#include "GDS_sfun.h"
#include "c6_GDS.h"
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
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_ValueStable              ((uint8_T)1U)
#define c6_IN_ValueUnstable            ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_e_debug_family_names[5] = { "nargin", "nargout", "In1",
  "In2", "Out" };

static const char * c6_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_h_debug_family_names[5] = { "nargin", "nargout", "In1",
  "In2", "Out" };

static const char * c6_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_s_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void c6_sdiInitialize(SFc6_GDSInstanceStruct *chartInstance);
static void c6_sdiTerminate(SFc6_GDSInstanceStruct *chartInstance);
static void initialize_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void initialize_params_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void enable_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void disable_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_GDS(SFc6_GDSInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void set_sim_state_c6_GDS(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_st);
static void c6_set_sim_state_side_effects_c6_GDS(SFc6_GDSInstanceStruct
  *chartInstance);
static void finalize_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void sf_gateway_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void mdl_start_c6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void initSimStructsc6_GDS(SFc6_GDSInstanceStruct *chartInstance);
static void c6_ValueUnstable(SFc6_GDSInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_nargout, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_c_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static boolean_T c6_Is_Different(SFc6_GDSInstanceStruct *chartInstance, real_T
  c6_In1, real_T c6_In2);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_b_tp_ValueStable, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint32_T c6_g_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_b_temporalCounter_i1, const char_T *c6_identifier);
static uint32_T c6_h_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_i_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_b_dataWrittenToVector, const char_T *c6_identifier, boolean_T
  c6_y[5]);
static void c6_j_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, boolean_T c6_y[5]);
static const mxArray *c6_k_emlrt_marshallIn(SFc6_GDSInstanceStruct
  *chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier);
static const mxArray *c6_l_emlrt_marshallIn(SFc6_GDSInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc6_GDSInstanceStruct
  *chartInstance, int32_T c6_ssid);
static void c6_init_sf_message_store_memory(SFc6_GDSInstanceStruct
  *chartInstance);
static uint32_T c6__u32_d_(SFc6_GDSInstanceStruct *chartInstance, real_T c6_b,
  uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc);
static uint32_T c6__u32_u64_(SFc6_GDSInstanceStruct *chartInstance, uint64_T
  c6_b, uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T
  c6_length_src_loc);
static void c6_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, void
  *c6_streamedData);
static void c6_b_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, int32_T
  c6_streamedData);
static void c6_c_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, int32_T
  c6_streamedData);
static void c6_d_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, void
  *c6_streamedData);
static void init_test_point_addr_map(SFc6_GDSInstanceStruct *chartInstance);
static void **get_test_point_address_map(SFc6_GDSInstanceStruct *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc6_GDSInstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector(SFc6_GDSInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc6_GDSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_GDSInstanceStruct *chartInstance);

/* Function Definitions */
static void c6_sdiInitialize(SFc6_GDSInstanceStruct *chartInstance)
{
  uint32_T c6_b[3] = { 0U, 159U, 209U };

  uint32_T c6_c[14] = { 7U, 11U, 12U, 26U, 9U, 128U, 129U, 230U, 94U, 95U, 96U,
    104U, 105U, 106U };

  const char * c6_d[3] = { "None", "ValueStable", "ValueUnstable" };

  int32_T c6_e[3] = { 0, 1, 2 };

  const char * c6_f[3] = { "None", "ValueStable", "ValueUnstable" };

  int32_T c6_g[3] = { 0, 1, 2 };

  int32_T c6_h[1] = { 1 };

  int32_T c6_i[1] = { 1 };

  int32_T c6_j[1] = { 1 };

  chartInstance->c6_sdiBlockInfo.mdlRefFullPath = "";
  chartInstance->c6_sdiBlockInfo.SimStruct = (void *)chartInstance->S;
  chartInstance->c6_sdiBlockInfo.blkPath = "";
  chartInstance->c6_sdiBlockInfo.blkSID = "GDS_Model:1:627";
  chartInstance->c6_sdiBlockInfo.sharedSCMPath = "";
  chartInstance->c6_sdiBlockInfo.sdiRuntime = NULL;
  sdi_database_initialize(&chartInstance->c6_sdiBlockInfo, c6_b, (uint8_T *)
    &chartInstance->c6_sdiLoggedStatesBuffer[0U], 3, c6_c, (uint8_T *)
    &chartInstance->c6_sdiLoggedDataBuffer[0U], 14);
  if (chartInstance->c6_sdiLoggedStatesBuffer[0U] & (uint8_T)1U) {
    sdi_register_child_activity_signal(&chartInstance->c6_sdiBlockInfo,
      "GenericDebouncerSampling/Standard/GenericDebouncerSampling", "", 3, c6_d,
      c6_e, sizeof(uint8_T), 1, 0U);
  }

  if (chartInstance->c6_sdiLoggedStatesBuffer[0U] & (uint8_T)2U) {
    sdi_register_leaf_activity_signal(&chartInstance->c6_sdiBlockInfo,
      "GenericDebouncerSampling/Standard/GenericDebouncerSampling", "", 3, c6_f,
      c6_g, sizeof(int32_T), 1, 0U);
  }

  chartInstance->c6_SignalExportProp.logName = "";
  chartInstance->c6_SignalExportProp.signalName = "ValueStable";
  chartInstance->c6_SignalExportProp.useCustomName = 0;
  chartInstance->c6_SignalExportProp.limitDataPoints = 0;
  chartInstance->c6_SignalExportProp.decimate = 0;
  chartInstance->c6_SignalExportProp.maxPoints = 5000U;
  chartInstance->c6_SignalExportProp.decimation = 2U;
  if (chartInstance->c6_sdiLoggedStatesBuffer[1U] & (uint8_T)4U) {
    sdi_register_self_activity_signal(&chartInstance->c6_sdiBlockInfo,
      "ValueStable", "ValueStable", 1, &chartInstance->c6_SignalExportProp, 159U);
  }

  chartInstance->c6_b_SignalExportProp.logName = "";
  chartInstance->c6_b_SignalExportProp.signalName = "ValueUnstable";
  chartInstance->c6_b_SignalExportProp.useCustomName = 0;
  chartInstance->c6_b_SignalExportProp.limitDataPoints = 0;
  chartInstance->c6_b_SignalExportProp.decimate = 0;
  chartInstance->c6_b_SignalExportProp.maxPoints = 5000U;
  chartInstance->c6_b_SignalExportProp.decimation = 2U;
  if (chartInstance->c6_sdiLoggedStatesBuffer[2U] & (uint8_T)4U) {
    sdi_register_self_activity_signal(&chartInstance->c6_sdiBlockInfo,
      "ValueUnstable", "ValueUnstable", 1, &chartInstance->c6_b_SignalExportProp,
      209U);
  }

  chartInstance->c6_c_SignalExportProp.logName = "";
  chartInstance->c6_c_SignalExportProp.signalName = "ValueOutput";
  chartInstance->c6_c_SignalExportProp.useCustomName = 0;
  chartInstance->c6_c_SignalExportProp.limitDataPoints = 0;
  chartInstance->c6_c_SignalExportProp.decimate = 0;
  chartInstance->c6_c_SignalExportProp.maxPoints = 5000U;
  chartInstance->c6_c_SignalExportProp.decimation = 1U;
  if (chartInstance->c6_sdiLoggedDataBuffer[1U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c6_sdiBlockInfo,
      "ValueOutput", "", 1, c6_h, 1, 0, 0, 0,
      &chartInstance->c6_c_SignalExportProp, "", 11U);
  }

  chartInstance->c6_d_SignalExportProp.logName = "";
  chartInstance->c6_d_SignalExportProp.signalName = "ValueStable";
  chartInstance->c6_d_SignalExportProp.useCustomName = 0;
  chartInstance->c6_d_SignalExportProp.limitDataPoints = 0;
  chartInstance->c6_d_SignalExportProp.decimate = 0;
  chartInstance->c6_d_SignalExportProp.maxPoints = 5000U;
  chartInstance->c6_d_SignalExportProp.decimation = 1U;
  if (chartInstance->c6_sdiLoggedDataBuffer[2U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c6_sdiBlockInfo,
      "ValueStable", "", 1, c6_i, 1, 0, 0, 0,
      &chartInstance->c6_d_SignalExportProp, "", 12U);
  }

  chartInstance->c6_e_SignalExportProp.logName = "";
  chartInstance->c6_e_SignalExportProp.signalName = "ValueUnStable";
  chartInstance->c6_e_SignalExportProp.useCustomName = 0;
  chartInstance->c6_e_SignalExportProp.limitDataPoints = 0;
  chartInstance->c6_e_SignalExportProp.decimate = 0;
  chartInstance->c6_e_SignalExportProp.maxPoints = 5000U;
  chartInstance->c6_e_SignalExportProp.decimation = 1U;
  if (chartInstance->c6_sdiLoggedDataBuffer[7U]) {
    sdi_register_builtin_data_type_signal(&chartInstance->c6_sdiBlockInfo,
      "ValueUnStable", "", 1, c6_j, 1, 0, 0, 0,
      &chartInstance->c6_e_SignalExportProp, "", 230U);
  }
}

static void c6_sdiTerminate(SFc6_GDSInstanceStruct *chartInstance)
{
  sdi_database_terminate(&chartInstance->c6_sdiBlockInfo);
}

static void initialize_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_GDS(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_tp_ValueStable = 0U;
  chartInstance->c6_tp_ValueUnstable = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_is_active_c6_GDS = 0U;
  chartInstance->c6_is_c6_GDS = c6_IN_NO_ACTIVE_CHILD;
  c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
    &chartInstance->c6_is_c6_GDS);
  c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
    (chartInstance->c6_is_c6_GDS == 1U));
  c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
    (chartInstance->c6_is_c6_GDS == 2U));
  c6_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 0);
}

static void initialize_params_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  real_T c6_d0;
  real_T c6_d1;
  real_T c6_d2;
  sf_mex_import_named("DurationStable", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c6_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_DurationStable = c6_d0;
  sf_mex_import_named("IsDifferentThreshold", sf_mex_get_sfun_param
                      (chartInstance->S, 1, 0), &c6_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_IsDifferentThreshold = c6_d1;
  sf_mex_import_named("IsEquivalentThreshold", sf_mex_get_sfun_param
                      (chartInstance->S, 2, 0), &c6_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_IsEquivalentThreshold = c6_d2;
}

static void enable_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_GDS(SFc6_GDSInstanceStruct
  *chartInstance)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c6_is_active_c6_GDS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_GDS == c6_IN_ValueStable) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_GDS == c6_IN_ValueUnstable) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  }

  _SFD_SET_ANIMATION(c6_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  const mxArray *c6_c_y = NULL;
  real_T c6_c_hoistedGlobal;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_hoistedGlobal;
  const mxArray *c6_f_y = NULL;
  uint32_T c6_f_hoistedGlobal;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(7, 1), false);
  c6_hoistedGlobal = *chartInstance->c6_ValueOutput;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_ValueStable;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = chartInstance->c6_ValueUnStable;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_active_c6_GDS;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = chartInstance->c6_is_c6_GDS;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_f_hoistedGlobal = chartInstance->c6_temporalCounter_i1;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_f_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y",
    chartInstance->c6_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 5), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_GDS(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_st)
{
  const mxArray *c6_u;
  boolean_T c6_bv0[5];
  int32_T c6_i0;
  c6_u = sf_mex_dup(c6_st);
  *chartInstance->c6_ValueOutput = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "ValueOutput");
  c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 11U, (void *)
    chartInstance->c6_ValueOutput);
  chartInstance->c6_ValueStable = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "ValueStable");
  c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
    &chartInstance->c6_ValueStable);
  chartInstance->c6_ValueUnStable = c6_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 2)), "ValueUnStable");
  c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 7, 230U, (void *)
    &chartInstance->c6_ValueUnStable);
  chartInstance->c6_is_active_c6_GDS = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 3)), "is_active_c6_GDS");
  chartInstance->c6_is_c6_GDS = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 4)), "is_c6_GDS");
  c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
    &chartInstance->c6_is_c6_GDS);
  c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
    (chartInstance->c6_is_c6_GDS == 1U));
  c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
    (chartInstance->c6_is_c6_GDS == 2U));
  chartInstance->c6_temporalCounter_i1 = c6_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 5)), "temporalCounter_i1");
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 6)),
                        "dataWrittenToVector", c6_bv0);
  for (c6_i0 = 0; c6_i0 < 5; c6_i0++) {
    chartInstance->c6_dataWrittenToVector[c6_i0] = c6_bv0[c6_i0];
  }

  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_debugger_state_c6_GDS(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_GDS(SFc6_GDSInstanceStruct
  *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    chartInstance->c6_tp_ValueStable = (uint8_T)(chartInstance->c6_is_c6_GDS ==
      c6_IN_ValueStable);
    if (chartInstance->c6_is_c6_GDS == c6_IN_ValueUnstable) {
      chartInstance->c6_tp_ValueUnstable = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_ValueUnstable = 0U;
    }

    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  c6_sdiTerminate(chartInstance);
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
}

static void sf_gateway_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_nargout = 1.0;
  real_T c6_b_nargin = 0.0;
  boolean_T c6_out;
  real_T c6_b_nargout = 0.0;
  real_T c6_In1;
  real_T c6_In2;
  uint32_T c6_c_debug_family_var_map[5];
  real_T c6_c_nargin = 2.0;
  real_T c6_c_nargout = 1.0;
  boolean_T c6_Out;
  real_T c6_x;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 0.0;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 1.0;
  boolean_T c6_b_out;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 0.0;
  boolean_T guard1 = false;
  c6_set_sim_state_side_effects_c6_GDS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  if (chartInstance->c6_temporalCounter_i1 < MAX_uint32_T) {
    chartInstance->c6_temporalCounter_i1++;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_ValueInitial, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c6_ValueInput, 2U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  if (chartInstance->c6_is_active_c6_GDS == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_active_c6_GDS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_c_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    chartInstance->c6_ValueStable = *chartInstance->c6_ValueInitial;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
      &chartInstance->c6_ValueStable);
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    *chartInstance->c6_ValueOutput = chartInstance->c6_ValueStable;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 11U, (void *)
      chartInstance->c6_ValueOutput);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c6_ValueOutput, 4U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c6_is_c6_GDS = c6_IN_ValueStable;
    c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
      &chartInstance->c6_is_c6_GDS);
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 1U));
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 2U));
    c6_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_ValueStable = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    *chartInstance->c6_ValueOutput = chartInstance->c6_ValueStable;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 11U, (void *)
      chartInstance->c6_ValueOutput);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c6_ValueOutput, 4U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c6_is_c6_GDS) {
     case c6_IN_ValueStable:
      CV_CHART_EVAL(0, 0, c6_IN_ValueStable);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_d_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      c6_In1 = *chartInstance->c6_ValueInput;
      c6_In2 = chartInstance->c6_ValueStable;
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_e_debug_family_names,
        c6_c_debug_family_var_map);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In1, 2U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In2, 3U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Out, 4U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      c6_x = c6_In1 - c6_In2;
      c6_Out = (muDoubleScalarAbs(c6_x) <=
                chartInstance->c6_IsEquivalentThreshold);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      c6_out = CV_EML_IF(13, 0, 0, c6_Out);
      _SFD_SYMBOL_SCOPE_POP();
      guard1 = false;
      if (c6_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
        guard1 = true;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_i_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        if (!chartInstance->c6_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
        }

        if (!chartInstance->c6_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
        }

        c6_b_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
          *chartInstance->c6_ValueInput, *chartInstance->c6_ValueOutput, -1, 1U,
          *chartInstance->c6_ValueInput != *chartInstance->c6_ValueOutput));
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
          guard1 = true;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c6_sfEvent);
        }
      }

      if (guard1) {
        chartInstance->c6_tp_ValueStable = 0U;
        chartInstance->c6_is_c6_GDS = c6_IN_NO_ACTIVE_CHILD;
        c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
          (chartInstance->c6_is_c6_GDS == 1U));
        c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
          (chartInstance->c6_is_c6_GDS == 2U));
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_c6_GDS = c6_IN_ValueUnstable;
        c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
          &chartInstance->c6_is_c6_GDS);
        c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
          (chartInstance->c6_is_c6_GDS == 1U));
        c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
          (chartInstance->c6_is_c6_GDS == 2U));
        c6_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 2);
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_ValueUnstable = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        chartInstance->c6_ValueUnStable = chartInstance->c6_ValueStable;
        chartInstance->c6_dataWrittenToVector[2U] = true;
        chartInstance->c6_dataWrittenToVector[2U] = true;
        c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 7, 230U, (void *)
          &chartInstance->c6_ValueUnStable);
        _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueUnStable, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_ValueUnstable:
      CV_CHART_EVAL(0, 0, c6_IN_ValueUnstable);
      c6_ValueUnstable(chartInstance);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c6_is_c6_GDS = c6_IN_NO_ACTIVE_CHILD;
      c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
        (chartInstance->c6_is_c6_GDS == 1U));
      c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
        (chartInstance->c6_is_c6_GDS == 2U));
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_GDSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  c6_init_sf_message_store_memory(chartInstance);
  c6_sdiInitialize(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc6_GDS(SFc6_GDSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_ValueUnstable(SFc6_GDSInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  real_T c6_b_nargin = 0.0;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_b_nargout = 1.0;
  real_T c6_c_nargin = 0.0;
  boolean_T c6_b_out;
  real_T c6_c_nargout = 0.0;
  real_T c6_d_nargin = 0.0;
  real_T c6_e_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  real_T c6_e_nargout = 1.0;
  boolean_T c6_c_out;
  boolean_T c6_d_out;
  real_T c6_f_nargin = 0.0;
  real_T c6_In1;
  real_T c6_f_nargout = 0.0;
  real_T c6_In2;
  uint32_T c6_c_debug_family_var_map[5];
  real_T c6_g_nargin = 2.0;
  real_T c6_g_nargout = 1.0;
  boolean_T c6_Out;
  real_T c6_h_nargin = 0.0;
  real_T c6_i_nargin = 0.0;
  real_T c6_h_nargout = 1.0;
  real_T c6_i_nargout = 1.0;
  real_T c6_x;
  boolean_T c6_e_out;
  boolean_T c6_f_out;
  real_T c6_b_In1;
  real_T c6_c_In1;
  real_T c6_b_In2;
  real_T c6_c_In2;
  real_T c6_j_nargin = 2.0;
  real_T c6_k_nargin = 2.0;
  real_T c6_j_nargout = 1.0;
  real_T c6_k_nargout = 1.0;
  boolean_T c6_b_Out;
  real_T c6_l_nargin = 0.0;
  boolean_T c6_c_Out;
  real_T c6_l_nargout = 0.0;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_m_nargin = 0.0;
  real_T c6_m_nargout = 1.0;
  boolean_T c6_g_out;
  real_T c6_n_nargin = 0.0;
  real_T c6_n_nargout = 0.0;
  real_T c6_o_nargin = 0.0;
  real_T c6_o_nargout = 0.0;
  real_T c6_p_nargin = 0.0;
  real_T c6_p_nargout = 0.0;
  real_T c6_q_nargin = 0.0;
  real_T c6_q_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_g_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  if (!chartInstance->c6_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
  }

  if (!chartInstance->c6_dataWrittenToVector[0U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
  }

  c6_out = CV_EML_IF(22, 0, 0, c6_Is_Different(chartInstance,
    *chartInstance->c6_ValueInput, *chartInstance->c6_ValueOutput));
  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (c6_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_f_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    chartInstance->c6_ValueStable = *chartInstance->c6_ValueInput;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    chartInstance->c6_dataWrittenToVector[1U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
      &chartInstance->c6_ValueStable);
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_n_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
    }

    c6_b_out = CV_EML_IF(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
      chartInstance->c6_ValueStable, *chartInstance->c6_ValueOutput, -1, 0U,
      chartInstance->c6_ValueStable == *chartInstance->c6_ValueOutput));
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_l_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      if (!chartInstance->c6_dataWrittenToVector[0U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
      }

      if (!chartInstance->c6_dataWrittenToVector[0U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
      }

      c6_In1 = *chartInstance->c6_ValueInput;
      c6_In2 = *chartInstance->c6_ValueOutput;
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_e_debug_family_names,
        c6_c_debug_family_var_map);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In1, 2U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In2, 3U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Out, 4U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      c6_x = c6_In1 - c6_In2;
      c6_Out = (muDoubleScalarAbs(c6_x) <=
                chartInstance->c6_IsEquivalentThreshold);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      guard5 = false;
      if (!CV_EML_COND(11, 0, 0, c6_Out)) {
        if (!CV_EML_COND(11, 0, 1, c6_Is_Different(chartInstance,
              *chartInstance->c6_ValueInput, *chartInstance->c6_ValueOutput))) {
          CV_EML_MCDC(11, 0, 0, true);
          CV_EML_IF(11, 0, 0, true);
          c6_d_out = true;
        } else {
          guard5 = true;
        }
      } else {
        if (!chartInstance->c6_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
        }

        if (!chartInstance->c6_dataWrittenToVector[0U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
        }

        guard5 = true;
      }

      if (guard5) {
        CV_EML_MCDC(11, 0, 0, false);
        CV_EML_IF(11, 0, 0, false);
        c6_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c6_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_m_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        chartInstance->c6_ValueStable = *chartInstance->c6_ValueInput;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
          &chartInstance->c6_ValueStable);
        _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c6_sfEvent);
        guard2 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }
  }

  if (guard4) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_q_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[0U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U);
    }

    c6_c_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0,
      chartInstance->c6_ValueStable, *chartInstance->c6_ValueOutput, -1, 1U,
      chartInstance->c6_ValueStable != *chartInstance->c6_ValueOutput));
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_o_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      c6_b_In1 = *chartInstance->c6_ValueInput;
      c6_b_In2 = chartInstance->c6_ValueStable;
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_e_debug_family_names,
        c6_c_debug_family_var_map);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_In1, 2U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_In2, 3U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_Out, 4U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      c6_b_x = c6_b_In1 - c6_b_In2;
      c6_b_Out = (muDoubleScalarAbs(c6_b_x) <=
                  chartInstance->c6_IsEquivalentThreshold);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      guard5 = false;
      if (!CV_EML_COND(9, 0, 0, c6_b_Out)) {
        if (!CV_EML_COND(9, 0, 1, c6_Is_Different(chartInstance,
              *chartInstance->c6_ValueInput, chartInstance->c6_ValueStable))) {
          CV_EML_MCDC(9, 0, 0, true);
          CV_EML_IF(9, 0, 0, true);
          c6_f_out = true;
        } else {
          guard5 = true;
        }
      } else {
        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        if (!chartInstance->c6_dataWrittenToVector[1U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
        }

        guard5 = true;
      }

      if (guard5) {
        CV_EML_MCDC(9, 0, 0, false);
        CV_EML_IF(9, 0, 0, false);
        c6_f_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c6_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_p_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_p_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_p_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        chartInstance->c6_ValueStable = *chartInstance->c6_ValueInput;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
          &chartInstance->c6_ValueStable);
        _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c6_sfEvent);
        guard2 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }

  if (guard3) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_k_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U);
    }

    if (!chartInstance->c6_dataWrittenToVector[2U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U);
    }

    guard5 = false;
    if (CV_EML_COND(15, 0, 0, CV_RELATIONAL_EVAL(5U, 15U, 0,
          chartInstance->c6_ValueUnStable, *chartInstance->c6_ValueInput, -1, 1U,
          chartInstance->c6_ValueUnStable != *chartInstance->c6_ValueInput))) {
      c6_c_In1 = *chartInstance->c6_ValueInput;
      c6_c_In2 = chartInstance->c6_ValueStable;
      _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_e_debug_family_names,
        c6_c_debug_family_var_map);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_In1, 2U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_In2, 3U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_Out, 4U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      c6_c_x = c6_c_In1 - c6_c_In2;
      c6_c_Out = (muDoubleScalarAbs(c6_c_x) <=
                  chartInstance->c6_IsEquivalentThreshold);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      if (CV_EML_COND(15, 0, 1, c6_c_Out)) {
        CV_EML_MCDC(15, 0, 0, true);
        CV_EML_IF(15, 0, 0, true);
        c6_e_out = true;
      } else {
        guard5 = true;
      }
    } else {
      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      if (!chartInstance->c6_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
      }

      guard5 = true;
    }

    if (guard5) {
      CV_EML_MCDC(15, 0, 0, false);
      CV_EML_IF(15, 0, 0, false);
      c6_e_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c6_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_j_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_n_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_n_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      chartInstance->c6_ValueStable = *chartInstance->c6_ValueInput;
      chartInstance->c6_dataWrittenToVector[1U] = true;
      chartInstance->c6_dataWrittenToVector[1U] = true;
      c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
        &chartInstance->c6_ValueStable);
      _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
      _SFD_SYMBOL_SCOPE_POP();
      guard2 = true;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_m_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_m_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_g_out = CV_EML_IF(8, 0, 0, c6__u32_u64_(chartInstance, (uint64_T)
        chartInstance->c6_temporalCounter_i1 * 10ULL, 156U, 1U, 27U) >=
                           c6__u32_d_(chartInstance, muDoubleScalarCeil
        (chartInstance->c6_DurationStable), 156U, 1U, 27U));
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_s_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_o_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_o_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        if (!chartInstance->c6_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U);
        }

        if (!chartInstance->c6_dataWrittenToVector[2U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U);
        }

        chartInstance->c6_ValueStable = chartInstance->c6_ValueUnStable;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        chartInstance->c6_dataWrittenToVector[1U] = true;
        c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 2, 12U, (void *)
          &chartInstance->c6_ValueStable);
        _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueStable, 0U);
        _SFD_SYMBOL_SCOPE_POP();
        guard1 = true;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c6_sfEvent);
      }
    }
  }

  if (guard2) {
    chartInstance->c6_tp_ValueUnstable = 0U;
    chartInstance->c6_is_c6_GDS = c6_IN_NO_ACTIVE_CHILD;
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 1U));
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 2U));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_c6_GDS = c6_IN_ValueUnstable;
    c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
      &chartInstance->c6_is_c6_GDS);
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 1U));
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 2U));
    c6_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 2);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    chartInstance->c6_temporalCounter_i1 = 0U;
    chartInstance->c6_tp_ValueUnstable = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_q_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_q_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    chartInstance->c6_ValueUnStable = chartInstance->c6_ValueStable;
    chartInstance->c6_dataWrittenToVector[2U] = true;
    chartInstance->c6_dataWrittenToVector[2U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 7, 230U, (void *)
      &chartInstance->c6_ValueUnStable);
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_ValueUnStable, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  if (guard1) {
    chartInstance->c6_tp_ValueUnstable = 0U;
    chartInstance->c6_is_c6_GDS = c6_IN_NO_ACTIVE_CHILD;
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 1U));
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 2U));
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_c6_GDS = c6_IN_ValueStable;
    c6_sdiStreamingWrapperFcn(chartInstance, 1, 0, 0U, (void *)
      &chartInstance->c6_is_c6_GDS);
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 1, 159U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 1U));
    c6_b_sdiStreamingWrapperFcn(chartInstance, 4, 2, 209U, (int32_T)
      (chartInstance->c6_is_c6_GDS == 2U));
    c6_c_sdiStreamingWrapperFcn(chartInstance, 2, 0, 0U, 1);
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_ValueStable = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    if (!chartInstance->c6_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U);
    }

    *chartInstance->c6_ValueOutput = chartInstance->c6_ValueStable;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    chartInstance->c6_dataWrittenToVector[0U] = true;
    c6_d_sdiStreamingWrapperFcn(chartInstance, 0, 1, 11U, (void *)
      chartInstance->c6_ValueOutput);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c6_ValueOutput, 4U);
    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
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
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_nargout, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d3;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d3, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d3;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
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
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_c_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
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
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_sf_internal_predicateOutput = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_sf_internal_predicateOutput), &c6_thisId);
  sf_mex_destroy(&c6_sf_internal_predicateOutput);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_GDS_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static boolean_T c6_Is_Different(SFc6_GDSInstanceStruct *chartInstance, real_T
  c6_In1, real_T c6_In2)
{
  boolean_T c6_Out;
  uint32_T c6_debug_family_var_map[5];
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_sf_internal_predicateOutput;
  real_T c6_x;
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c6_h_debug_family_names,
    c6_debug_family_var_map);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In1, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_In2, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_Out, 4U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c6_sfEvent);
  c6_sf_internal_predicateOutput = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U,
    0, chartInstance->c6_IsDifferentThreshold, 0.0, -1, 0U,
    chartInstance->c6_IsDifferentThreshold == 0.0));
  if (c6_sf_internal_predicateOutput) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
    c6_Out = false;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    c6_x = c6_In1 - c6_In2;
    c6_Out = (muDoubleScalarAbs(c6_x) > chartInstance->c6_IsDifferentThreshold);
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  return c6_Out;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
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
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
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
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_b_tp_ValueStable, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_ValueStable),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_ValueStable);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_tp_ValueStable;
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)chartInstanceVoid;
  c6_b_tp_ValueStable = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_ValueStable),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_ValueStable);
  *(uint8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint32_T c6_g_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_b_temporalCounter_i1, const char_T *c6_identifier)
{
  uint32_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_temporalCounter_i1),
    &c6_thisId);
  sf_mex_destroy(&c6_b_temporalCounter_i1);
  return c6_y;
}

static uint32_T c6_h_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_y;
  uint32_T c6_u1;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u1, 1, 7, 0U, 0, 0U, 0);
  c6_y = c6_u1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_i_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_b_dataWrittenToVector, const char_T *c6_identifier, boolean_T
  c6_y[5])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_dataWrittenToVector),
                        &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_dataWrittenToVector);
}

static void c6_j_emlrt_marshallIn(SFc6_GDSInstanceStruct *chartInstance, const
  mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, boolean_T c6_y[5])
{
  boolean_T c6_bv1[5];
  int32_T c6_i2;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_bv1, 1, 11, 0U, 1, 0U, 1, 5);
  for (c6_i2 = 0; c6_i2 < 5; c6_i2++) {
    c6_y[c6_i2] = c6_bv1[c6_i2];
  }

  sf_mex_destroy(&c6_u);
}

static const mxArray *c6_k_emlrt_marshallIn(SFc6_GDSInstanceStruct
  *chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier)
{
  const mxArray *c6_y = NULL;
  emlrtMsgIdentifier c6_thisId;
  c6_y = NULL;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  sf_mex_assign(&c6_y, c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), false);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_l_emlrt_marshallIn(SFc6_GDSInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), false);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc6_GDSInstanceStruct
  *chartInstance, int32_T c6_ssid)
{
  (void)chartInstance;
  (void)c6_ssid;
  return NULL;
}

static void c6_init_sf_message_store_memory(SFc6_GDSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static uint32_T c6__u32_d_(SFc6_GDSInstanceStruct *chartInstance, real_T c6_b,
  uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc)
{
  uint32_T c6_a;
  (void)chartInstance;
  c6_a = (uint32_T)c6_b;
  if ((c6_b < 0.0) || ((real_T)c6_a != muDoubleScalarFloor(c6_b))) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c6_ssid_src_loc, c6_offset_src_loc,
      c6_length_src_loc);
  }

  return c6_a;
}

static uint32_T c6__u32_u64_(SFc6_GDSInstanceStruct *chartInstance, uint64_T
  c6_b, uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T
  c6_length_src_loc)
{
  uint32_T c6_a;
  (void)chartInstance;
  c6_a = (uint32_T)c6_b;
  if ((uint64_T)c6_a != c6_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c6_ssid_src_loc, c6_offset_src_loc,
      c6_length_src_loc);
  }

  return c6_a;
}

static void c6_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, void
  *c6_streamedData)
{
  if (chartInstance->c6_sdiLoggedStatesBuffer[c6_ssidIdx] & (uint8_T)c6_modeFlag)
  {
    sdi_stream_child_activity_signal(&chartInstance->c6_sdiBlockInfo, c6_ssid,
      c6_streamedData);
  }
}

static void c6_b_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, int32_T
  c6_streamedData)
{
  if (chartInstance->c6_sdiLoggedStatesBuffer[c6_ssidIdx] & (uint8_T)c6_modeFlag)
  {
    sdi_update_self_activity_signal(&chartInstance->c6_sdiBlockInfo, c6_ssid,
      c6_streamedData);
  }
}

static void c6_c_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, int32_T
  c6_streamedData)
{
  if (chartInstance->c6_sdiLoggedStatesBuffer[c6_ssidIdx] & (uint8_T)c6_modeFlag)
  {
    sdi_update_leaf_activity_signal(&chartInstance->c6_sdiBlockInfo, c6_ssid,
      c6_streamedData);
  }
}

static void c6_d_sdiStreamingWrapperFcn(SFc6_GDSInstanceStruct *chartInstance,
  int32_T c6_modeFlag, int32_T c6_ssidIdx, uint32_T c6_ssid, void
  *c6_streamedData)
{
  (void)c6_modeFlag;
  if (chartInstance->c6_sdiLoggedDataBuffer[c6_ssidIdx]) {
    sdi_stream_data_signal(&chartInstance->c6_sdiBlockInfo, c6_ssid,
      c6_streamedData);
  }
}

static void init_test_point_addr_map(SFc6_GDSInstanceStruct *chartInstance)
{
  chartInstance->c6_testPointAddrMap[0] = &chartInstance->c6_ValueStable;
  chartInstance->c6_testPointAddrMap[1] = &chartInstance->c6_ValueUnStable;
}

static void **get_test_point_address_map(SFc6_GDSInstanceStruct *chartInstance)
{
  return &chartInstance->c6_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc6_GDSInstanceStruct *chartInstance)
{
  return &chartInstance->c6_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector(SFc6_GDSInstanceStruct
  *chartInstance)
{
  return &chartInstance->c6_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc6_GDSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_GDSInstanceStruct *chartInstance)
{
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_ValueInput = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_ValueOutput = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_ValueInitial = (real_T *)ssGetInputPortSignal_wrapper
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

static void init_test_point_mapping_info(SimStruct *S);
void sf_c6_GDS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(892082151U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1203287763U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3086980500U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2792450123U);
}

mxArray* sf_c6_GDS_get_post_codegen_info(void);
mxArray *sf_c6_GDS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4eoUmcBJj8ouGwms4K6lEG");
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c6_GDS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_GDS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_GDS_jit_fallback_info(void)
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

mxArray *sf_c6_GDS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_GDS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_GDS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[11],T\"ValueOutput\",},{M[3],M[12],T\"ValueStable\",},{M[3],M[230],T\"ValueUnStable\",},{M[8],M[0],T\"is_active_c6_GDS\",},{M[9],M[0],T\"is_c6_GDS\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[209],M[1]}}},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_GDS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc6_GDSInstanceStruct *) chartInstance,
    msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_GDSInstanceStruct *chartInstance = (SFc6_GDSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _GDSMachineNumber_,
           6,
           4,
           23,
           0,
           14,
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
          _SFD_SET_DATA_PROPS(1,0,0,0,"ValueUnStable");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ValueInput");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ValueInitial");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ValueOutput");
          _SFD_SET_DATA_PROPS(5,8,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_SET_DATA_PROPS(7,8,0,0,"");
          _SFD_SET_DATA_PROPS(8,8,0,0,"");
          _SFD_SET_DATA_PROPS(9,9,0,0,"");
          _SFD_SET_DATA_PROPS(10,9,0,0,"");
          _SFD_SET_DATA_PROPS(11,10,0,0,"DurationStable");
          _SFD_SET_DATA_PROPS(12,10,0,0,"IsDifferentThreshold");
          _SFD_SET_DATA_PROPS(13,10,0,0,"IsEquivalentThreshold");
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(0,0,2);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,2);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(2,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,39,1,39);
        _SFD_CV_INIT_EML(14,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,37,1,37);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,24,1,24);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,24,-1,1);
        _SFD_CV_INIT_EML(17,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(15,0,0,1,72,1,48);

        {
          static int condStart[] = { 2, 33 };

          static int condEnd[] = { 27, 71 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(15,0,0,1,72,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(15,0,0,2,27,-1,1);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(11,0,0,1,85,1,48);

        {
          static int condStart[] = { 4, 48 };

          static int condEnd[] = { 41, 84 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(11,0,0,2,85,2,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(12,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,27,1,27);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,27,-1,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,85,1,48);

        {
          static int condStart[] = { 4, 48 };

          static int condEnd[] = { 41, 84 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,2,85,2,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,27,1,27);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,27,-1,1);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,1,28,1,28);
        _SFD_CV_INIT_EML(6,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

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

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(7,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(8,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(9,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(10,(void *)(NULL));
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
    SFc6_GDSInstanceStruct *chartInstance = (SFc6_GDSInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c6_ValueInput);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c6_ValueOutput);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c6_ValueStable);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c6_ValueInitial);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)&chartInstance->c6_DurationStable);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)
          &chartInstance->c6_IsDifferentThreshold);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)
          &chartInstance->c6_IsEquivalentThreshold);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c6_ValueUnStable);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVQeTWVREwH7Gu283DGXN6B";
}

static void sf_opaque_initialize_c6_GDS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_GDSInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
  initialize_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_GDS(void *chartInstanceVar)
{
  enable_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_GDS(void *chartInstanceVar)
{
  disable_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_GDS(void *chartInstanceVar)
{
  sf_gateway_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_GDS(SimStruct* S)
{
  return get_sim_state_c6_GDS((SFc6_GDSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_GDS(SimStruct* S, const mxArray *st)
{
  set_sim_state_c6_GDS((SFc6_GDSInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c6_GDS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_GDSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_GDS_optimization_info();
    }

    finalize_c6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_GDS((SFc6_GDSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_GDS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_GDS((SFc6_GDSInstanceStruct*)sf_get_chart_instance_ptr
      (S));
  }
}

static void mdlSetWorkWidths_c6_GDS(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 6);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3196017429U));
  ssSetChecksum1(S,(2024577065U));
  ssSetChecksum2(S,(2534590013U));
  ssSetChecksum3(S,(1053391658U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_GDS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_GDS(SimStruct *S)
{
  SFc6_GDSInstanceStruct *chartInstance;
  chartInstance = (SFc6_GDSInstanceStruct *)utMalloc(sizeof
    (SFc6_GDSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_GDSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_GDS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_GDS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_GDS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_GDS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_GDS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_GDS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_GDS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_GDS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_GDS;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_GDS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_GDS;
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
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
  mdl_start_c6_GDS(chartInstance);
}

void c6_GDS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_GDS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_GDS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_GDS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_GDS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/ValueStable", "ValueStable", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/ValueUnStable", "ValueUnStable", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    2,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
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
  "float",

  {
    3196017429U,
    2024577065U,
    2534590013U,
    1053391658U
  }
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc6_GDSInstanceStruct *chartInstance = (SFc6_GDSInstanceStruct *)
    sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
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
