function Shutdown
    %SHUTDOWN - Enterprise project template shutdown function
    % Closes a project gracefully
    p = simulinkproject;
    prjRoot = p.RootFolder;
    
    %   Determine if this is a master project or a referenced project
    try
        if p.Information.TopLevel
            isMasterProject=true;
        else
            isMasterProject=false;
        end
    catch
        % capture workspace and error information and save to structure in base workspace
        isMasterProject=true;
    end
    
    %   Only process if this is a master project
    if isMasterProject
        %   When closing the project, update the dependencies
        JD_FindProjectDependencies;
        
        %  Close project models
        if exist('JD_CloseProjectModels','file')
            JD_CloseProjectModels;
        end
        
        %  Find paths of interest
        [~,toolfolder]=define_project_path(prjRoot);
        
        %--------------------------------------------------------------------------
        %   Remove local tools folders
        %   * Add code below to remove local tools from Matlab path
        %--------------------------------------------------------------------------
        
        %--------------------------------------------------------------------------
        %   Remove Enterprise Tools and clean up
        %--------------------------------------------------------------------------
        
        if exist('JD_RemoveToolsFromProject','file')
            JD_RemoveToolsFromProject(toolfolder,'all');
        end
        
        %  Reset Matlab Cache Folder - for generated files
        Simulink.fileGenControl('reset', 'keepPreviousPath', true);
        
        %   Refresh Simulink customizations for libraries
        warning('off','dastudio:studio:DuplicateFcnHandle')
        sl_refresh_customizations
        warning('on','dastudio:studio:DuplicateFcnHandle')
    end
end