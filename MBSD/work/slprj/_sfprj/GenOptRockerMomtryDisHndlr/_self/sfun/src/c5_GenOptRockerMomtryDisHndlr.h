#ifndef __c5_GenOptRockerMomtryDisHndlr_h__
#define __c5_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_c5_EnCtrlDisSt
#define typedef_c5_EnCtrlDisSt

typedef uint8_T c5_EnCtrlDisSt;

#endif                                 /*typedef_c5_EnCtrlDisSt*/

#ifndef EnCtrlDisSt_constants
#define EnCtrlDisSt_constants

/* enum EnCtrlDisSt */
#define c5_EnCtrlDisSt_EnCtrlDisStIsOff ((c5_EnCtrlDisSt)0U)
#define c5_EnCtrlDisSt_EnCtrlDisStIsOn ((c5_EnCtrlDisSt)1U)
#define c5_EnCtrlDisSt_EnCtrlDisStIsHoldSho ((c5_EnCtrlDisSt)2U)
#define c5_EnCtrlDisSt_EnCtrlDisStIsHoldLong ((c5_EnCtrlDisSt)3U)
#endif                                 /*EnCtrlDisSt_constants*/

#ifndef typedef_SFc5_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc5_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_On;
  uint8_T c5_tp_HeldShort;
  uint8_T c5_tp_HeldLong;
  uint8_T c5_is_active_c5_GenOptRockerMomtryDisHndlr;
  uint8_T c5_is_c5_GenOptRockerMomtryDisHndlr;
  uint32_T c5_temporalCounter_i1;
  boolean_T c5_dataWrittenToVector[1];
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  void *c5_fEmlrtCtx;
  c5_EnCtrlDisSt *c5_State;
  real_T *c5_EolDurnLong;
  real_T *c5_EolDurnSho;
} SFc5_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc5_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c5_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
