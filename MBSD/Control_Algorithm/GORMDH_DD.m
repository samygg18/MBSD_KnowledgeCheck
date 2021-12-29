Rocker_Mode_Input = Simulink.Parameter;
Rocker_Mode_Input.Value = 3;
Rocker_Mode_Input.CoderInfo.StorageClass = 'Custom';
Rocker_Mode_Input.CoderInfo.Alias = '';
Rocker_Mode_Input.CoderInfo.Alignment = -1;
Rocker_Mode_Input.CoderInfo.CustomStorageClass = 'Define';
Rocker_Mode_Input.CoderInfo.CustomAttributes.HeaderFile = '';
Rocker_Mode_Input.CoderInfo.CustomAttributes.ConcurrentAccess = false;
Rocker_Mode_Input.Description = '';
Rocker_Mode_Input.DataType = 'uint8';
Rocker_Mode_Input.Min = [];
Rocker_Mode_Input.Max = [];
Rocker_Mode_Input.DocUnits = '';
Rocker_Mode_Input.DocUnits = '';

Transition_Count = Simulink.Parameter;
Transition_Count.Value = 0;
Transition_Count.CoderInfo.StorageClass = 'Custom';
Transition_Count.CoderInfo.Alias = '';
Transition_Count.CoderInfo.Alignment = -1;
Transition_Count.CoderInfo.CustomStorageClass = 'Define';
Transition_Count.CoderInfo.CustomAttributes.HeaderFile = '';
Transition_Count.CoderInfo.CustomAttributes.ConcurrentAccess = false;
Transition_Count.Description = '';
Transition_Count.DataType = 'CntAbsMod';
Transition_Count.Min = [];
Transition_Count.Max = [];
Transition_Count.DocUnits = '';
Transition_Count.DocUnits = '';

Transition_Add = Simulink.Parameter;
Transition_Add.Value = 1;
Transition_Add.CoderInfo.StorageClass = 'Custom';
Transition_Add.CoderInfo.Alias = '';
Transition_Add.CoderInfo.Alignment = -1;
Transition_Add.CoderInfo.CustomStorageClass = 'Define';
Transition_Add.CoderInfo.CustomAttributes.HeaderFile = '';
Transition_Add.CoderInfo.CustomAttributes.ConcurrentAccess = false;
Transition_Add.Description = '';
Transition_Add.DataType = 'CntAbsMod';
Transition_Add.Min = [];
Transition_Add.Max = [];
Transition_Add.DocUnits = '';
Transition_Add.DocUnits = '';

EolDurnRetain = AUTOSAR.Parameter;
EolDurnRetain.Value = 1;
EolDurnRetain.CoderInfo.StorageClass = 'Custom';
EolDurnRetain.CoderInfo.Alias = '';
EolDurnRetain.CoderInfo.Alignment = -1;
EolDurnRetain.CoderInfo.CustomStorageClass = 'InternalCalPrm';
EolDurnRetain.CoderInfo.CustomAttributes.HeaderFile = '';
EolDurnRetain.CoderInfo.CustomAttributes.PerInstanceBehavior = ...
  ['Each instance of the Software Component has its own copy of the par' ...
   'ameter'];
EolDurnRetain.Description = '';
EolDurnRetain.DataType = 'TiInSec';
EolDurnRetain.Min = [];
EolDurnRetain.Max = [];
EolDurnRetain.DocUnits = '';
EolDurnRetain.SwCalibrationAccess = 'ReadWrite';
EolDurnRetain.DisplayFormat = '';

RMI_Error = Simulink.Parameter;
RMI_Error.Value = 3;
RMI_Error.CoderInfo.StorageClass = 'Custom';
RMI_Error.CoderInfo.Alias = '';
RMI_Error.CoderInfo.Alignment = -1;
RMI_Error.CoderInfo.CustomStorageClass = 'Define';
RMI_Error.CoderInfo.CustomAttributes.HeaderFile = '';
RMI_Error.CoderInfo.CustomAttributes.ConcurrentAccess = false;
RMI_Error.Description = '';
RMI_Error.DataType = 'double';
RMI_Error.Min = [];
RMI_Error.Max = [];
RMI_Error.DocUnits = '';
RMI_Error.DocUnits = '';

Transition_Zero = Simulink.Parameter;
Transition_Zero.Value = 0;
Transition_Zero.CoderInfo.StorageClass = 'Custom';
Transition_Zero.CoderInfo.Alias = '';
Transition_Zero.CoderInfo.Alignment = -1;
Transition_Zero.CoderInfo.CustomStorageClass = 'Define';
Transition_Zero.CoderInfo.CustomAttributes.HeaderFile = '';
Transition_Zero.CoderInfo.CustomAttributes.ConcurrentAccess = false;
Transition_Zero.Description = '';
Transition_Zero.DataType = 'CntAbsMod';
Transition_Zero.Min = [];
Transition_Zero.Max = [];
Transition_Zero.DocUnits = '';
Transition_Zero.DocUnits = '';

Selr_Retain = Simulink.Bus;
Selr_Retain.Description = ['A Selector Control represents mechanisms wh' ...
                           'ich select at most one of a set of possible' ...
                           ' values. The mechanism can be a mutually ex' ...
                           'clusive bank of buttons, a selector dial, o' ...
                           'r some sort of multiple position rocker swi' ...
                           'tch. They can be latching or momentary. The' ...
                           ' possible selections are represented as an ' ...
                           'array of Discrete Controls so the consumer ' ...
                           'can distinguish between Off, On, and Held f' ...
                           'or each selectable value. The Selected valu' ...
                           'e is also provided for convenience with zer' ...
                           'o meaning no value is selected (i.e. the ne' ...
                           'utral state which also implies all listed D' ...
                           'iscrete Controls are Off). The number of Tr' ...
                           'ansitions from any selector being not off t' ...
                           'o all selectors being off is also provided.' ...
                           ''];
Selr_Retain.DataScope = 'Auto';
Selr_Retain.HeaderFile = 'Rte_Type.h';
Selr_Retain.Alignment = -1;
saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'Prev_Seln';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = [1 1];
saveVarsTmp{1}.DataType = 'Enum: EnCtrlSeln';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.SampleTime = -1;
saveVarsTmp{1}.DocUnits = '';
saveVarsTmp{1}.Description = ['The index of the selected Discrete Contr' ...
                              'ol with zero meaning no Discrete Control' ...
                              ' is not Off (i.e. the neutral state).'];
saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'Prev_SeldSt';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = [1 1];
saveVarsTmp{1}(2, 1).DataType = 'Enum: EnCtrlDisSt';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).SampleTime = -1;
saveVarsTmp{1}(2, 1).DocUnits = '';
saveVarsTmp{1}(2, 1).Description = '';
saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'Prev_Trans';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = [1 1];
saveVarsTmp{1}(3, 1).DataType = 'CntAbsMod';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).SampleTime = -1;
saveVarsTmp{1}(3, 1).DocUnits = '';
saveVarsTmp{1}(3, 1).Description = ['The count over time of the Transit' ...
                                    'ions from any selectable value bei' ...
                                    'ng not Off to all selectable value' ...
                                    's being Off, or the Selector from ' ...
                                    'not 0 to 0.'];
saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'Prev_Sts';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = [1 1];
saveVarsTmp{1}(4, 1).DataType = 'Enum: EnCtrlSts';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).SampleTime = -1;
saveVarsTmp{1}(4, 1).DocUnits = '';
saveVarsTmp{1}(4, 1).Description = '';
Selr_Retain.Elements = saveVarsTmp{1};
clear saveVarsTmp;
