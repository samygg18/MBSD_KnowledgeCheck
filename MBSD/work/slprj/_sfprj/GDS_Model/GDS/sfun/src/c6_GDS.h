#ifndef __c6_GDS_h__
#define __c6_GDS_h__
#include "sf_runtime/sfc_sdi.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc6_GDSInstanceStruct
#define typedef_SFc6_GDSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  uint8_T c6_tp_ValueStable;
  uint8_T c6_tp_ValueUnstable;
  uint8_T c6_is_active_c6_GDS;
  uint8_T c6_is_c6_GDS;
  real_T c6_ValueStable;
  real_T c6_DurationStable;
  real_T c6_IsDifferentThreshold;
  real_T c6_IsEquivalentThreshold;
  real_T c6_ValueUnStable;
  uint32_T c6_temporalCounter_i1;
  boolean_T c6_dataWrittenToVector[5];
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  void *c6_dataSetLogObjVector[2];
  uint8_T c6_sdiLoggedStatesBuffer[3];
  uint8_T c6_sdiLoggedDataBuffer[14];
  sdiBlockID_t c6_sdiBlockInfo;
  SignalExportStruct c6_SignalExportProp;
  SignalExportStruct c6_b_SignalExportProp;
  void *c6_ValueOutput_dataStream;
  SignalExportStruct c6_c_SignalExportProp;
  void *c6_ValueStable_dataStream;
  SignalExportStruct c6_d_SignalExportProp;
  void *c6_ValueUnStable_dataStream;
  SignalExportStruct c6_e_SignalExportProp;
  rtwCAPI_ModelMappingInfo c6_testPointMappingInfo;
  void *c6_testPointAddrMap[2];
  void *c6_fEmlrtCtx;
  real_T *c6_ValueInput;
  real_T *c6_ValueOutput;
  real_T *c6_ValueInitial;
} SFc6_GDSInstanceStruct;

#endif                                 /*typedef_SFc6_GDSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_GDS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_GDS_get_check_sum(mxArray *plhs[]);
extern void c6_GDS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
