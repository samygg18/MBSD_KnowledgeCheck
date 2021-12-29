function ChangeToProjectFolder
    %ChangeToProjectFolder Changes active folder to root folder of project
    %   Detailed explanation goes here
    
    p=simulinkproject;
    cd(p.RootFolder);
    
end

