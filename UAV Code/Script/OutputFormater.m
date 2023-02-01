function OutputFormater(nstate)
    load('ScriptOutput.mat');
    file_name = fopen('TextOutput.txt','wt');
    if exist('OF','var')
        fprintf(file_name,'OF: %d row(s), %d column(s)\n',numel(OF),1);
        for row = 1:numel(OF)
            string = char(OF(row,1));
            fprintf(file_name,'OF(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('F','var')
        fprintf(file_name,'F: %d row(s), %d column(s)\n',nstate,nstate);
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
        fprintf(file_name,'OG: %d row(s), %d column(s)\n',numel(OG),1);
        for row = 1:numel(OG)
            string = char(OG(row,1));
            fprintf(file_name,'OG(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('G','var')
        fprintf(file_name,'G: %d row(s), %d column(s)\n',nstate,numel([da;dv]));
        for row = 1:nstate
            for col = 1:numel([da;dv])
                string = char(G(row,col));
                if ~strcmpi(string,'0')
                    fprintf(file_name,'G(%d,%d) = %s;\n',row,col,string);
                end
            end
        end
        fprintf(file_name,'\n');
    end

    if exist('OQ','var')
        fprintf(file_name,'OQ: %d row(s), %d column(s)\n',numel(OQ),1);
        for row = 1:numel(OQ)
            string = char(OQ(row,1));
            fprintf(file_name,'OQ(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    if exist('Q','var')
        fprintf(file_name,'Q: %d row(s), %d column(s)\n',nstate,nstate);
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
        fprintf(file_name,'OPP: %d row(s), %d column(s)\n',numel(OPP),1);
        for row = 1:numel(OPP)
            string = char(OPP(row,1));
            fprintf(file_name,'OPP(%d) = %s;\n',row,string);
        end
        fprintf(file_name,'\n');
    end

    %covariance prediction PP: upper diagonal and lower diagonal are seperated(matrix is symmetric)
    if exist('PP','var')
        fprintf(file_name,'next_P: %d row(s), %d column(s)\n',nstate,nstate);
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
        fprintf(file_name,'H_VP: %d row(s), %d column(s)\n',num_row,num_col);
        for row = 1:num_row
            for col = 1:num_col
                string = char(H_VP(row,col));
                fprintf(file_name,'H_VP(%d,%d) = %s;\n',row,col,string);
            end
        end
        fprintf(file_name,'\n');
    end

    %%----------130
