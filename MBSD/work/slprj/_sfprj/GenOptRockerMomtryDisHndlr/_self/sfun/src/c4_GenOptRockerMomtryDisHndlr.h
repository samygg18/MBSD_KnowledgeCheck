#ifndef __c4_GenOptRockerMomtryDisHndlr_h__
#define __c4_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_SFc4_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc4_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_Error_Until_Reported;
  uint8_T c4_tp_Error_After_Reported;
  uint8_T c4_is_active_c4_GenOptRockerMomtryDisHndlr;
  uint8_T c4_is_c4_GenOptRockerMomtryDisHndlr;
  uint32_T c4_temporalCounter_i1;
  boolean_T c4_dataWrittenToVector[1];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  real_T *c4_EolDurnRetain;
  real_T *c4_dur;
} SFc4_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc4_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c4_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
