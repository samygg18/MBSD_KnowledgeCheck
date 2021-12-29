#ifndef __c4_GDS_h__
#define __c4_GDS_h__

/* Type Definitions */
#ifndef typedef_SFc4_GDSInstanceStruct
#define typedef_SFc4_GDSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_ValueRetained;
  uint8_T c4_is_active_c4_GDS;
  uint8_T c4_is_c4_GDS;
  real_T c4_ValueStable;
  real_T c4_DurationStable;
  real_T c4_IsDifferentThreshold;
  real_T c4_IsEquivalentThreshold;
  uint32_T c4_temporalCounter_i1;
  boolean_T c4_dataWrittenToVector[4];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  real_T *c4_ValueInput;
  real_T *c4_ValueOutput;
  real_T *c4_ValueInitial;
} SFc4_GDSInstanceStruct;

#endif                                 /*typedef_SFc4_GDSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_GDS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_GDS_get_check_sum(mxArray *plhs[]);
extern void c4_GDS_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
