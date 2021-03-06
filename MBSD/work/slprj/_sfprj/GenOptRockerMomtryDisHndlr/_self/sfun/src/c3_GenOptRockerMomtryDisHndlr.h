#ifndef __c3_GenOptRockerMomtryDisHndlr_h__
#define __c3_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_SFc3_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc3_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_GenOptRockerMomtryDisHndlr;
  uint16_T c3_counter;
  boolean_T c3_dataWrittenToVector[2];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T *c3_P_ROM;
  uint16_T *c3_Transition_Add;
  uint16_T *c3_Transition_Zero;
  uint16_T *c3_Internal_counter;
  uint16_T *c3_Trans;
} SFc3_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc3_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c3_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
