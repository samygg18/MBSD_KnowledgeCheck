#ifndef __c6_GenOptRockerMomtryDisHndlr_h__
#define __c6_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_SFc6_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc6_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  uint8_T c6_tp_Transition_Increments;
  uint8_T c6_tp_Transition_Same;
  uint8_T c6_tp_Transition_Increments1;
  uint8_T c6_is_active_c6_GenOptRockerMomtryDisHndlr;
  uint8_T c6_is_c6_GenOptRockerMomtryDisHndlr;
  uint16_T c6_counter;
  boolean_T c6_dataWrittenToVector[2];
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  void *c6_fEmlrtCtx;
  uint16_T *c6_Trans;
  uint16_T *c6_Transition_Add;
  uint16_T *c6_Transition_Zero;
  real_T *c6_P_ROM;
  uint16_T *c6_Internal_counter;
} SFc6_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc6_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c6_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
