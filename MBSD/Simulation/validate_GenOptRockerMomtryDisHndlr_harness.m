%validate_GenOptRockerMomtryDisHndlr_harness.m - Execute tests for GenOptRockerMomtryDisHndlr_harness Model
%function testobj=validate_GenOptRockerMomtryDisHndlr_harness(testobj,test_mode,testcase,testlog,simout,sslog)
%   Performs validate on model GenOptRockerMomtryDisHndlr_harness
%   Test callback used with JD_ModelTester object
%
%   Inputs:
%           testobj = JD_ModelTester Object
%         test_mode = 'initialize' (load general data dictionary), 'setup' (test-specific data dictionary) or 'test' (execute test)
%          testcase = Name or index of signal builder group being executed
%           testlog = Simulation log
%            simout = Complete simulation results object
%             sslog = Simscape log (optional - only provided when Simscape logging is enabled)
%
%   Outputs:
%           testobj = JD_ModelTester object with updated test results
%

%   RESTRICTIONS:
%   Copyright (c) Deere & Company, as an unpublished work.
%   THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
%   ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
%   DEERE & COMPANY IS PROHIBITED.
function testobj=validate_GenOptRockerMomtryDisHndlr_harness(testobj,test_mode,testcase,testlog,simout,sslog)
    try
        %----------------------------------------------------
        % - INITIALIZE -
        % Load data dictionary and perform other tasks to enable diagram update
        % Examples:
        %  - testobj.LoadDataDictionary({'DD_1','DD_2'});
        %  - testobj.LoadDataDictionary({'DD_1'});
        %  - testobj.LoadDataDictionary({});
        %----------------------------------------------------
        %  Ignore common warnings
        warning('off','Simulink:Signals:SigAttribPropErr5');
        warning('off','Stateflow:cdr:UnusedDataOrEvent');
        warning('off','Simulink:modelReference:SigAttribPropErr5ForInport');
        warning('off','Simulink:Data:Param_ConvertToRealWorldValue');

        if strcmpi(test_mode,'initialize')
            % Default is to use base data dictionary. Modify as needed
            ddfiles=findProjectFiles('DataDictionary','Startup');
            testobj.LoadDataDictionary(ddfiles);

        %----------------------------------------------------
        % - SETUP -
        % Load testcase-specific data dictionary
        % Examples:
        %  - testobj.LoadDataDictionary({'DD_1','DD_2'});
        %  - testobj.LoadDataDictionary({'DD_1'});
        %  - testobj.LoadDataDictionary({});
        %----------------------------------------------------
        elseif strcmpi(test_mode,'setup')
            % Advanced Use Case: Complex models and/or variants may require clearing base workspace between
            % tests. Line below can be uncommented to accomplish this.
            % evalin('base','clear');

            % Default is to use base data dictionary. Additional data dictionaries can be added as needed
            ddfiles=findProjectFiles('DataDictionary','Startup');
            testobj.LoadDataDictionary(ddfiles);

            % Specify data that may change between tests
            switch testcase
                case 'TP0'
                    %testobj.LoadDataDictionary({'<your DD 1_1>','<your DD 1_2>'});

                case 'TP1'
                    %testobj.LoadDataDictionary({'<your DD 2_1>','<your DD 2_2>'});

                case 'TP2'
                    %testobj.LoadDataDictionary({'<your DD 3_1>','<your DD 3_2>'});

                case 'TP3'
                    %testobj.LoadDataDictionary({'<your DD 4_1>','<your DD 4_2>'});

                case 'TP4'
                    %testobj.LoadDataDictionary({'<your DD 5_1>','<your DD 5_2>'});

                case 'TP5'
                    %testobj.LoadDataDictionary({'<your DD 6_1>','<your DD 6_2>'});

                case 'TP6'
                    %testobj.LoadDataDictionary({'<your DD 7_1>','<your DD 7_2>'});

                otherwise
                    % Throw an error that no setup specified for this test case
                    error(['No setup specified for test case' testcase]);
            end
            
            % Apply overlay if specified in test
            if testobj.UseOverlay
                %testobj.LoadDataDictionary({'<Your Overlay DD 1>','<Your Overlay DD 2>'});
            end
        %----------------------------------------------------
        % - TEST -
        % Testcase-specific scripting for performing checks and capturing results
        %----------------------------------------------------
        elseif strcmpi(test_mode,'test')
            try
                %   Try to get sample time from test harness model
                ts = testobj.SampleTime;

            catch %#ok<*CTCH>
                %   Assume continuous time
                ts = 0;

            end

        %----------------------------------------------------
        % WORKSPACE PARAMETER OR CONSTANT READ                              
        % Provide Parameter or Constant Data for Test Cases  -
        %                                                                 
        % Parameters or Constants in the workspace can be used for each of the  
        % test cases using the following Command: 
        %                                                                 
        % ValueRead = testobj.GetParamValue(Value);                         
        %                                                                 
        % where:                                                           
        %        ValueRead is the read Simulink Parameter for test case usage  
        %        Value is the Simulink Parameter or Constant in the workspace  
        %                              via loading the proper data dictionary     
        %                                                                 
        %----------------------------------------------------------------------

            DDFiles = testobj.DataDictionaryFiles(testobj.TestIndex,:);
            DDFiles = DDFiles(~cellfun('isempty',DDFiles));
            cellfun(@eval,DDFiles);
        %----------------------------------------------------------------------

            warning('off','backtrace');

            switch testcase
                case 'TP0'
                    fprintf('\nTest Procedure ''TP0'': \n');

                    %No Objective entered
                    %init
                    %default
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckEqual(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', 0, 0, 0, 0.1);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP1'
                    fprintf('\nTest Procedure ''TP1'': \n');

                    %No Objective entered
                    %init
                    %Rocker_Mode_Output is Neutral
                    %Signals are invalid and Rocker_Mode_Output is Error
                    %Rocker_Mode_Output is Forward
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1]);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSeldStMonr_Val', [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1], [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1]);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2], [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1]);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1]);
                    testobj.CheckEqual(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', 0, 0, 0, 1);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP2'
                    fprintf('\nTest Procedure ''TP2'': \n');

                    %No Objective entered
                    %init
                    %Set Rocker_Mode_Input to Forward
                    %Then to Neutral 
                    %Then to Neutral 
                    %Then to Neutral 
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSeldStMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', [0, 0, 1, 1, 1], [0, 0.1, 0.2, 0.3, 0.4]);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP3'
                    fprintf('\nTest Procedure ''TP3'': \n');

                    %No Objective entered
                    %init
                    %Set Rocker_Mode_Output to Forward for more than EolDurnSho (0.06)
                    %Set Rocker_Mode_Output to Forward for up to EolDurnLong (0.15)
                    %Set Rocker_Mode_Output to Forward for more than EolDurnLong (0.15)
                    %Set Rocker_Mode_Output to Neutral
                    %Set Rocker_Mode_Output to Rearward for more than EolDurnSho (0.06)
                    %Set Rocker_Mode_Output to Rearward for up to EolDurnLong (0.15)
                    %Set Rocker_Mode_Output to Rearward for more than Duration_long (0.15)
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4, 3.5]);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP4'
                    fprintf('\nTest Procedure ''TP4'': \n');

                    %No Objective entered
                    %init
                    %Rocker_Mode_output is Neutral
                    %Rocker_Mode_output is Foraward
                    %Rocker_Mode_output is Rearward
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckEqual(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', 0, 0, 0, 0.3);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP5'
                    fprintf('\nTest Procedure ''TP5'': \n');

                    %No Objective entered
                    %init
                    %Rocker_Mode_Output is Neutral
                    %Rocker_Mode_output is Error 
                    %Rocker_Mode_output is Error for more than EolDurnRetain
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckEqual(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', 0, 0, 0, 1.3);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                case 'TP6'
                    fprintf('\nTest Procedure ''TP6'': \n');

                    %No Objective entered
                    %init
                    %Is_Installed is False
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHIsInstldMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqSelnMonr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHPosnReqStsMonr_Val', 5, 0);
                    testobj.CheckEqual(testlog, 'DataServicesGORMDHPosnReqTransMonr_Val', 0, 0, 0, 0.8);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig1Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig2Monr_Val', 0, 0);
                    testobj.CheckValueAtTime(testlog, 'DataServicesGORMDHSig3Monr_Val', 0, 0);

                otherwise
                    %===================================
                    %   Test Case Default
                    %===================================
                    testResult=['No Test Defined for ' testcase];
                    warning(['No Test Defined for Test Case: ' testcase]);
            end

             warning('on','backtrace');
             % Reactivate common warnings
             warning('on','Simulink:Signals:SigAttribPropErr5');
             warning('on','Stateflow:cdr:UnusedDataOrEvent');
             warning('on','Simulink:modelReference:SigAttribPropErr5ForInport');
             warning('on','Simulink:Data:Param_ConvertToRealWorldValue');
        end
    catch e
        % capture workspace and error information and save to structure in base workspace
        functionworkspace=tosavedworkspace;
        assignin('base','fws',functionworkspace);
        %   Display error information
        rethrow(e);
    end
