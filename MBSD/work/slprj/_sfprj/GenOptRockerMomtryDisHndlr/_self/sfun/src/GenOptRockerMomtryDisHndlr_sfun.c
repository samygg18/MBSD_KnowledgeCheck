/* Include files */

#include "GenOptRockerMomtryDisHndlr_sfun.h"
#include "GenOptRockerMomtryDisHndlr_sfun_debug_macros.h"
#include "c1_GenOptRockerMomtryDisHndlr.h"
#include "c2_GenOptRockerMomtryDisHndlr.h"
#include "c4_GenOptRockerMomtryDisHndlr.h"
#include "c5_GenOptRockerMomtryDisHndlr.h"
#include "c6_GenOptRockerMomtryDisHndlr.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _GenOptRockerMomtryDisHndlrMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void GenOptRockerMomtryDisHndlr_initializer(void)
{
}

void GenOptRockerMomtryDisHndlr_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_GenOptRockerMomtryDisHndlr_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_GenOptRockerMomtryDisHndlr_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_GenOptRockerMomtryDisHndlr_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_GenOptRockerMomtryDisHndlr_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_GenOptRockerMomtryDisHndlr_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_GenOptRockerMomtryDisHndlr_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_GenOptRockerMomtryDisHndlr_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3820514791U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(158899857U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3842829172U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(701540863U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray
            *plhs[]);
          sf_c1_GenOptRockerMomtryDisHndlr_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray
            *plhs[]);
          sf_c2_GenOptRockerMomtryDisHndlr_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray
            *plhs[]);
          sf_c4_GenOptRockerMomtryDisHndlr_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray
            *plhs[]);
          sf_c5_GenOptRockerMomtryDisHndlr_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_GenOptRockerMomtryDisHndlr_get_check_sum(mxArray
            *plhs[]);
          sf_c6_GenOptRockerMomtryDisHndlr_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(118045901U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1467797778U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2709376854U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(980050690U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3101350607U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1522873900U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(388999541U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3718201864U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GenOptRockerMomtryDisHndlr_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "MaznIPwIwV7tkbvAAwL0GG") == 0) {
          extern mxArray
            *sf_c1_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void);
          plhs[0] = sf_c1_GenOptRockerMomtryDisHndlr_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "up31ONLvotL98Z3u7zAuiF") == 0) {
          extern mxArray
            *sf_c2_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void);
          plhs[0] = sf_c2_GenOptRockerMomtryDisHndlr_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "d5A35ruv1Ya51oayINWn9D") == 0) {
          extern mxArray
            *sf_c4_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void);
          plhs[0] = sf_c4_GenOptRockerMomtryDisHndlr_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "up31ONLvotL98Z3u7zAuiF") == 0) {
          extern mxArray
            *sf_c5_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void);
          plhs[0] = sf_c5_GenOptRockerMomtryDisHndlr_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "uZ3ueZF5QBAqyVeZuR7RHG") == 0) {
          extern mxArray
            *sf_c6_GenOptRockerMomtryDisHndlr_get_autoinheritance_info(void);
          plhs[0] = sf_c6_GenOptRockerMomtryDisHndlr_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(instanceChksum, "sf7aiPuXf43ZtnCSObrvncG") == 0) {
          extern const mxArray
            *sf_c1_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c1_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 2:
      {
        if (strcmp(instanceChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern const mxArray
            *sf_c2_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 4:
      {
        if (strcmp(instanceChksum, "srKRtcc7tFGldac3hfCjQ5") == 0) {
          extern const mxArray
            *sf_c4_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c4_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 5:
      {
        if (strcmp(instanceChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern const mxArray
            *sf_c5_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c5_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 6:
      {
        if (strcmp(instanceChksum, "spCu5NVzbDcKZaXTqtFkIlB") == 0) {
          extern const mxArray
            *sf_c6_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info
            (void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c6_GenOptRockerMomtryDisHndlr_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GenOptRockerMomtryDisHndlr_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sf7aiPuXf43ZtnCSObrvncG") == 0) {
          extern mxArray *sf_c1_GenOptRockerMomtryDisHndlr_third_party_uses_info
            (void);
          plhs[0] = sf_c1_GenOptRockerMomtryDisHndlr_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray *sf_c2_GenOptRockerMomtryDisHndlr_third_party_uses_info
            (void);
          plhs[0] = sf_c2_GenOptRockerMomtryDisHndlr_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "srKRtcc7tFGldac3hfCjQ5") == 0) {
          extern mxArray *sf_c4_GenOptRockerMomtryDisHndlr_third_party_uses_info
            (void);
          plhs[0] = sf_c4_GenOptRockerMomtryDisHndlr_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray *sf_c5_GenOptRockerMomtryDisHndlr_third_party_uses_info
            (void);
          plhs[0] = sf_c5_GenOptRockerMomtryDisHndlr_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "spCu5NVzbDcKZaXTqtFkIlB") == 0) {
          extern mxArray *sf_c6_GenOptRockerMomtryDisHndlr_third_party_uses_info
            (void);
          plhs[0] = sf_c6_GenOptRockerMomtryDisHndlr_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GenOptRockerMomtryDisHndlr_jit_fallback_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sf7aiPuXf43ZtnCSObrvncG") == 0) {
          extern mxArray *sf_c1_GenOptRockerMomtryDisHndlr_jit_fallback_info
            (void);
          plhs[0] = sf_c1_GenOptRockerMomtryDisHndlr_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray *sf_c2_GenOptRockerMomtryDisHndlr_jit_fallback_info
            (void);
          plhs[0] = sf_c2_GenOptRockerMomtryDisHndlr_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "srKRtcc7tFGldac3hfCjQ5") == 0) {
          extern mxArray *sf_c4_GenOptRockerMomtryDisHndlr_jit_fallback_info
            (void);
          plhs[0] = sf_c4_GenOptRockerMomtryDisHndlr_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray *sf_c5_GenOptRockerMomtryDisHndlr_jit_fallback_info
            (void);
          plhs[0] = sf_c5_GenOptRockerMomtryDisHndlr_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "spCu5NVzbDcKZaXTqtFkIlB") == 0) {
          extern mxArray *sf_c6_GenOptRockerMomtryDisHndlr_jit_fallback_info
            (void);
          plhs[0] = sf_c6_GenOptRockerMomtryDisHndlr_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sf7aiPuXf43ZtnCSObrvncG") == 0) {
          extern mxArray
            *sf_c1_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray
            *sf_c2_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "srKRtcc7tFGldac3hfCjQ5") == 0) {
          extern mxArray
            *sf_c4_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "sfwfKKMim79HPb8BDCB1UN") == 0) {
          extern mxArray
            *sf_c5_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "spCu5NVzbDcKZaXTqtFkIlB") == 0) {
          extern mxArray
            *sf_c6_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_GenOptRockerMomtryDisHndlr_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void GenOptRockerMomtryDisHndlr_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _GenOptRockerMomtryDisHndlrMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"GenOptRockerMomtryDisHndlr","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _GenOptRockerMomtryDisHndlrMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _GenOptRockerMomtryDisHndlrMachineNumber_,0);
}

void GenOptRockerMomtryDisHndlr_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_GenOptRockerMomtryDisHndlr_optimization_info(void);
mxArray* load_GenOptRockerMomtryDisHndlr_optimization_info(boolean_T isRtwGen,
  boolean_T isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_GenOptRockerMomtryDisHndlr_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "GenOptRockerMomtryDisHndlr", "GenOptRockerMomtryDisHndlr");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_GenOptRockerMomtryDisHndlr_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
