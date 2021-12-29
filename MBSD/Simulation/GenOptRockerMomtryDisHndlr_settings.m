function [varargout] = GenOptRockerMomtryDisHndlr_settings(varargin)

    MdlFile = 'GenOptRockerMomtryDisHndlr_harness.slx';
    ValScript = 'validate_GenOptRockerMomtryDisHndlr_harness.m';
    ReportFile = '';
    UseOverlay = false;
    ExecutedTests = [1];
    if(~nargin)

        testObj = JD_ModelTester(strrep(MdlFile,'.slx',''));

        if(isempty(testObj.ErrorInfo) || (~testObj.ErrorInfo.Status))
             try
                testObj.AttachTestScript(ValScript);
                testObj.UseOverlay=UseOverlay;
                testObj.ExecuteSelectedTests(ExecutedTests);
                testObj.Report(ReportFile);
             catch e
                % capture workspace and error information and save to structure in base workspace
                functionworkspace=tosavedworkspace;
                assignin('base','fws',functionworkspace);
                save fws
                
                %   Display error information
                disp('FAILURE: Exception found')
                disp(getReport(e,'extended'))
                rethrow(e);
             end
        else
            disp(testObj.ErrorInfo.Message);
        end
        varargout = {};

    else
        AdditionalOutputs.ExecutedTests=ExecutedTests;
        AdditionalOutputs.UseOverlay=UseOverlay;
        varargout = { MdlFile, ValScript, ReportFile, AdditionalOutputs};
    end

end
