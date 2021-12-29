#ifndef __c1_GenOptRockerMomtryDisHndlr_h__
#define __c1_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_SFc1_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc1_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_GenOptRockerMomtryDisHndlr;
  void *c1_fEmlrtCtx;
  boolean_T *c1_signal_1;
  boolean_T *c1_signal_2;
  real_T *c1_Rocker_Mode_Input;
  boolean_T *c1_signal_3;
} SFc1_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc1_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c1_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
