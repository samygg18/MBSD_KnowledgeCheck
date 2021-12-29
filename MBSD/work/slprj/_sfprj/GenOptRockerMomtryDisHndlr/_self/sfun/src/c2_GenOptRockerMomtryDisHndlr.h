#ifndef __c2_GenOptRockerMomtryDisHndlr_h__
#define __c2_GenOptRockerMomtryDisHndlr_h__

/* Type Definitions */
#ifndef typedef_c2_EnCtrlDisSt
#define typedef_c2_EnCtrlDisSt

typedef uint8_T c2_EnCtrlDisSt;

#endif                                 /*typedef_c2_EnCtrlDisSt*/

#ifndef EnCtrlDisSt_constants
#define EnCtrlDisSt_constants

/* enum EnCtrlDisSt */
#define c2_EnCtrlDisSt_EnCtrlDisStIsOff ((c2_EnCtrlDisSt)0U)
#define c2_EnCtrlDisSt_EnCtrlDisStIsOn ((c2_EnCtrlDisSt)1U)
#define c2_EnCtrlDisSt_EnCtrlDisStIsHoldSho ((c2_EnCtrlDisSt)2U)
#define c2_EnCtrlDisSt_EnCtrlDisStIsHoldLong ((c2_EnCtrlDisSt)3U)
#endif                                 /*EnCtrlDisSt_constants*/

#ifndef typedef_SFc2_GenOptRockerMomtryDisHndlrInstanceStruct
#define typedef_SFc2_GenOptRockerMomtryDisHndlrInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_On;
  uint8_T c2_tp_HeldShort;
  uint8_T c2_tp_HeldLong;
  uint8_T c2_is_active_c2_GenOptRockerMomtryDisHndlr;
  uint8_T c2_is_c2_GenOptRockerMomtryDisHndlr;
  uint32_T c2_temporalCounter_i1;
  boolean_T c2_dataWrittenToVector[1];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_fEmlrtCtx;
  c2_EnCtrlDisSt *c2_State;
  real_T *c2_EolDurnLong;
  real_T *c2_EolDurnSho;
} SFc2_GenOptRockerMomtryDisHndlrInstanceStruct;

#endif                                 /*typedef_SFc2_GenOptRockerMomtryDisHndlrInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray *plhs[]);
extern void c2_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
