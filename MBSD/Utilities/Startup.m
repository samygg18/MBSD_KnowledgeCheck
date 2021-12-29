function Startup
    %function Startup - Project Startup function to finish configuration
    %
    
    %  Find root folder
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
        % If project doesn't support this capability, treat it as top-level
        isMasterProject=true;
    end
    
    % Remaining processing is only done for top level projects
    if isMasterProject
        % Set the location of slprj to be the "work" folder of the current project:
        myCacheFolder = fullfile(prjRoot, 'MBSD','work');
        if ~exist(myCacheFolder, 'dir')
            mkdir(myCacheFolder)
        end
        Simulink.fileGenControl('set', 'CacheFolder', myCacheFolder, ...
            'CodeGenFolder', myCacheFolder);
        
        %  Set up tools
        %--------------------------------------------------------------------------
        %   Set up Enterprise Tools
        %       Add the toolset root folder to the Matlab path
        %       * Uncomment line below and ensure relative path is correct
        %--------------------------------------------------------------------------
        %  Add project folders to path
        [~,toolfolder]=define_project_path(prjRoot);
        
        %   Only set up tools for master project
        if exist(toolfolder,'dir')
            addpath(toolfolder);
            %	Set up Enterprise Tools
            JD_ConfigureToolsForProject;
        else
            warndlg('Specified tool folder is not present. Modify the define_project_path file or ensure tool folder is present.','Tool Path Warning','modal');
        end
        
        %--------------------------------------------------------------------------
        %   Set up local tools
        %       Add the local tools to the path without saving path changes
        %       * Add code below to ensure local tools are accessible
        %--------------------------------------------------------------------------
        
        % Sets up to Ignore the work folder
        if exist('sourcecontrol','file')
            sourcecontrol('ignore',fullfile(prjRoot,'MBSD','work'));
        end
        
        %  Load data dictionaries labeled for Startup
        if exist('findProjectFiles','file')
            RunProjectDD;
        end
        
        %   Refresh customizations for any library references and model advisor settings
        warning('off','dastudio:studio:DuplicateFcnHandle')
        %   Refresh library browser
        sl_refresh_customizations
        %   Refresh model advisor settings
        %   Try/Catch used due to changes between R2015b and R2016b
        try
            Advisor.Manager.refresh_customizations
        catch
            %   This is already handled by sl_refresh_customizations above
        end
        warning('on','dastudio:studio:DuplicateFcnHandle')
        
        %  Check Simulink Project Status for updates
        if exist('JD_CheckSimulinkProjectStatus','file')
            JD_CheckSimulinkProjectStatus;
        end
    end
end