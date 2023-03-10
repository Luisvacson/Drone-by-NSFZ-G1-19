function OutputFormater(nstate)
    load('ScriptOutput.mat');
    file_name = fopen('TextOutput.txt','wt');
    if exist('OF','var')
        fprintf(file_name,'OF = zeros(%d,%d);\n',numel(OF),1);
        for row = 1:numel(OF)
            string = char(OF(row,1));
            fprintf(file_name,'OF(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('F','var')
        fprintf(file_name,'F = zeros(%d,%d);\n',nstate,nstate);
        for row = 1:nstate
            for col = 1:nstate
                string = char(F(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'F(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OG','var')
        fprintf(file_name,'OG = zeros(%d,%d);\n',numel(OG),1);
        for row = 1:numel(OG)
            string = char(OG(row,1));
            fprintf(file_name,'OG(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('G','var')
        [num_row,num_col] = size(G);
        fprintf(file_name,'G = zeros(%d,%d);\n',num_row,num_col);
        for row = 1:num_row
            for col = 1:num_col
                string = char(G(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'G(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OQ','var')
        fprintf(file_name,'OQ = zeros(%d,%d);\n',numel(OQ),1);
        for row = 1:numel(OQ)
            string = char(OQ(row,1));
            fprintf(file_name,'OQ(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('Q','var')
        fprintf(file_name,'Q = zeros(%d,%d);\n',nstate,nstate);
        for row = 1:nstate
            for col = 1:nstate
                string = char(Q(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'Q(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OPP','var')
        fprintf(file_name,'OPP = zeros(%d,%d);\n',numel(OPP),1);
        for row = 1:numel(OPP)
            string = char(OPP(row,1));
            fprintf(file_name,'OPP(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    %covariance prediction PP: upper diagonal and lower diagonal are seperated(matrix is symmetric)
    if exist('PP','var')
        fprintf(file_name,'next_P = zeros(%d,%d);\n',nstate,nstate);
        for col = 1:nstate
            for row = 1:col
                string = char(PP(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'next_P(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('H_VP','var')
        [num_row,num_col] = size(H_VP);
        fprintf(file_name,'H_VP = zeros(%d,%d);\n',num_row,num_col);
        for row = 1:num_row
            for col = 1:num_col
                string = char(H_VP(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'H_VP(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OK_VP','var')
        fprintf(file_name,'OK_VP = zeros(%d,%d);\n',numel(OK_VP),1);
        for row = 1:numel(OK_VP)
            string = char(OK_VP(row,1));
            fprintf(file_name,'OK_VP(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_VP','var')
        [num_row,num_col] = size(K_VP);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',num_row,num_col);
        for row = 1:num_row
            for col = 1:num_col
                string = char(K_VP(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'K_gain(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OH_MAG','var')
        fprintf(file_name,'OH_MAG = zeros(%d,%d);\n',numel(OH_MAG),1);
        for row = 1:numel(OH_MAG)
            string = char(OH_MAG(row,1));
            fprintf(file_name,'OH_MAG(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    %%mag X
    if exist('H_MAG','var')
        [~,num_col] = size(H_MAG);
        fprintf(file_name,'H_MAG = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_MAG(1,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_MAG(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end
    
    if exist('OK_MX','var')
        fprintf(file_name,'OK_MX = zeros(%d,%d);\n',numel(OK_MX),1);
        for row = 1:numel(OK_MX)
            string = char(OK_MX(row,1));
            fprintf(file_name,'OK_MX(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_MX','var')
        [num_row,~] = size(K_MX);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',numel(K_MX),1);
        for row = 1:num_row
            string = char(K_MX(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    %%mag Y
    if exist('H_MAG','var')
        [~,num_col] = size(H_MAG);
        fprintf(file_name,'H_MAG = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_MAG(2,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_MAG(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end
    
    if exist('OK_MY','var')
        fprintf(file_name,'OK_MY = zeros(%d,%d);\n',numel(OK_MY),1);
        for row = 1:numel(OK_MY)
            string = char(OK_MY(row,1));
            fprintf(file_name,'OK_MY(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_MY','var')
        [num_row,~] = size(K_MY);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',numel(K_MY),1);
        for row = 1:num_row
            string = char(K_MY(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    %%mag Z
    if exist('H_MAG','var')
        [~,num_col] = size(H_MAG);
        fprintf(file_name,'H_MAG = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_MAG(3,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_MAG(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end
    
    if exist('OK_MZ','var')
        fprintf(file_name,'OK_MZ = zeros(%d,%d);\n',numel(OK_MZ),1);
        for row = 1:numel(OK_MZ)
            string = char(OK_MZ(row,1));
            fprintf(file_name,'OK_MZ(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_MZ','var')
        [num_row,~] = size(K_MZ);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',numel(K_MZ),1);
        for row = 1:num_row
            string = char(K_MZ(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    %%mag declination
    if exist('OH_DEC','var')
        fprintf(file_name,'OH_DEC = zeros(%d,%d);\n',numel(OH_DEC),1);
        for row = 1:numel(OH_DEC)
            string = char(OH_DEC(row,1));
            fprintf(file_name,'OH_DEC(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('H_DEC','var')
        [~,num_col] = size(H_DEC);
        fprintf(file_name,'H_DEC = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_DEC(1,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_DEC(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OK_DEC','var')
        fprintf(file_name,'OK_DEC = zeros(%d,%d);\n',numel(OK_DEC),1);
        for row = 1:numel(OK_DEC)
            string = char(OK_DEC(row,1));
            fprintf(file_name,'OK_DEC(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_DEC','var')
        [num_row,~] = size(K_DEC);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',num_row,1);
        for row = 1:num_row
            string = char(K_DEC(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('H_YAW321','var')
        [~,num_col] = size(H_YAW321);
        fprintf(file_name,'H_YAW321 = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_YAW321(1,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_YAW321(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('K_YAW321','var')
        [num_row,~] = size(K_YAW321);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',num_row,1);
        for row = 1:num_row
            string = char(K_YAW321(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('H_YAW312','var')
        [~,num_col] = size(H_YAW312);
        fprintf(file_name,'H_YAW312 = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_YAW312(1,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_YAW312(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('K_YAW312','var')
        [num_row,~] = size(K_YAW312);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',num_row,1);
        for row = 1:num_row
            string = char(K_YAW312(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    %%baro
    if exist('H_BARO','var')
        [~,num_col] = size(H_BARO);
        fprintf(file_name,'H_BARO = zeros(%d,%d);\n',1,num_col);
        for col = 1:num_col
            string = char(H_BARO(1,col));
            if ~strcmpi(string,'0')
                fprintf(file_name,'H_BARO(%d) = %s;\n',col,string);
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OK_BARO','var')
        fprintf(file_name,'OK_BARO = zeros(%d,%d);\n',numel(OK_BARO),1);
        for row = 1:numel(OK_BARO)
            string = char(OK_BARO(row,1));
            fprintf(file_name,'OK_BARO(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('K_BARO','var')
        [num_row,~] = size(K_BARO);
        fprintf(file_name,'K_gain = zeros(%d,%d);\n',num_row,1);
        for row = 1:num_row
            string = char(K_BARO(row,1));
            if ~strcmpi(string,'0')
                fprintf(file_name,'K_gain(%d) = %s;\n',row,string);
            end
        end
        fprintf(file_name,'\n');
    end

    fclose(file_name);
















