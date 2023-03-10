function [SymExpOut,SubExpArray] = OptimiseAlgebra(SymExpIn,SubExpName)
    syms SubExpIn SubExpArray;
    SubExpArray(1,1) = 'invalid';
    index = 0;
    f_complete = 0;
    disp(['Optimise ',SubExpName]);
    while f_complete == 0
        index = index + 1;
        SubExpIn = [SubExpName,'_lp_',num2str(index),'_rp_'];
        [SymExpOut,SubExpOut] = subexpr(SymExpIn,SubExpIn);
        if isempty(SubExpOut)
            disp('Break');
            break;
        end
        SubExpArray(index,1) = SubExpOut;
        SymExpIn = SymExpOut;
        disp([' Find ',num2str(index),' item(s)']);
    end

%%old version
%function [SymExpOut,SubExpArray] = OptimiseAlgebra(SymExpIn,SubExpName)
%    
%    syms SubExpIn SubExpArray ;
%    
%    SubExpArray(1,1) = 'invalid';
%    index = 0;
%    f_complete = 0;
%    while f_complete==0
%        index = index + 1;
%        SubExpIn = [SubExpName,'(',num2str(index),')'];
%        SubExpInStore{index} = SubExpIn;
%        [SymExpOut,SubExpOut]=subexpr(SymExpIn,SubExpIn);
%            for k = 1:index
%                if SubExpOut == SubExpInStore{k}
%                    f_complete = 1;
%                end
%            end
%        if f_complete || index > 100
%            SymExpOut = SymExpIn;
%        else
%            SubExpArray(index,1) = SubExpOut;
%            SymExpIn = SymExpOut;
%        end
%    end
    