%CleanUpWorkFolder - Clears mex files and deletes contents of project Work folder
%function CleanUpWorkFolder
%   This function is used within the context of a Simulink project. It will
%   remove compiled mex files from Matlab to allow them to be deleted, then delete
%   the entire contents of the Work folder. This is often useful when unusual 
%   problems - especially crashing Matlab - arise. However, it will also require
%   rebuilding/recompiling any code or MEX files used in simulation (Stateflow charts
%   and Accelerator mode model references are typical examples).
%
%   Inputs:
%               None
%
%   Outputs:
%               None
%
%   Side Effects:
%               Removes MEX files from Matlab memory
%               Deletes contents of the project Work folder
%               Requires rebuild of any needed MEX or code files but can resolve
%               some difficult to troubleshoot issues


%   RESTRICTIONS:
%   Copyright (c) Deere & Company, as an unpublished work.
%   THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
%   ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
%   DEERE & COMPANY IS PROHIBITED.
function CleanUpWorkFolder
    try
        %   Be sure user understands potential downside as well as benefits
        question={'Clearing the workspace will delete all contents of the project work folder',...
            ' - This can help to resolve difficult issues in running simulations or generating code.',...
            ' - This will also impact the next code build and simulation because Simulink must rebuild everything.',...
            ' ',...
            'Do you wish to continue?'};
        
        proceed=questdlg(question,'Confirm Project Clean Up');
            
        if strcmpi(proceed,'yes')
            %   Clear mex files to allow them to be deleted
            clear mex
            %   Find project Work folder
            p=simulinkproject;
            prjRoot=p.RootFolder;
            %   Find work folder
            workFolder=fullfile(prjRoot,'MBSD','work');
            %   Remember current folder
            curFolder=pwd;
            %   Change to work folder
            cd(workFolder);
            %   Delete all files in this folder. DON'T ASK - That's already been done
            !del *.* /q
            %   Now clean up folders
            fldlist=dir;
            for i=1:length(fldlist)
                if fldlist(i).isdir && fldlist(i).name(1) ~= '.'
                    fldr=fullfile(workFolder,fldlist(i).name);
                    rmdir(fldr,'s');
                end
            end
            %   Change back to original folder
            try
                cd(curFolder);
            catch err %#ok<NASGU>
                %   Most likely were already in the work folder hierarchy
                %   So change to project folder
                cd(prjRoot);
            end
            %   Indicate success
            disp('The work folder has been successfully cleaned up');
        end
    catch e
        % capture workspace and error information and save to structure in base workspace
        functionworkspace=tosavedworkspace;
        assignin('base','fws',functionworkspace);
        %   Display error information
        rethrow(e);
    end
end
