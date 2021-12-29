%GenerateCode.m - Find Target Label and query User for Target to use.
%function GenerateCode.m
%   Shortcut within the Project to select target for code generation. The
%   user is queried to select among the possible targets for code
%   generation and the script will run. Inputs:
%             None
%
%   Outputs:
%             None
%   Side Effects
%           Calls JD_SimulinkProjectCodeGen for the selected target. 
%
%   Examples
%       Double click on the project Shortcut: "GenerateCode" and select the
%       target code for the build from the drop down menu that appears. 
%
%   For more details, see <a href="matlab:JD_DisplaySharepointHelp('help_GenerateCode.m')">GenerateCode.m</a>.
%   See also JD_SimulinkProjectCodeGen, JD_CopyProjectCode.

%   RESTRICTIONS:
%   Copyright (c) Deere & Company, as an unpublished work.
%   THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
%   ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
%   DEERE & COMPANY IS PROHIBITED.
function GenerateCode
    try
        prj = simulinkproject;
        pCN={prj.Categories.Name};
        % get the category named Target
        [~,Catn,~] = intersect(pCN,'Target');
        labn={prj.Categories(Catn).LabelDefinitions.Name};
        [TList,SelOK] = listdlg('liststring',labn,'SelectionMode','single' );
        % Handle case where user canceled out of selection 
        if SelOK > 0
            Target = labn{TList};
            
            % Set up the code gen cofiguration for selected target
            JD_SimulinkProjectCodeGen(Target);
                        
        else
            % Esit without error if user does not select a Target 
            warning ('No Target was selected operation terminated.')
        end
        
    catch e
        % capture workspace and error information and save to structure in base workspace
        functionworkspace=tosavedworkspace;
        assignin('base','fws',functionworkspace);
        %   Display error information
        rethrow(e);
    end
end
