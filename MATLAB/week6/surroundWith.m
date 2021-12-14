function [surroundArray] = surroundWith(array,num)
    
    arrayRow = size(array,1)+2;
    arrayCol = size(array,2)+2;
    surroundArray = ones(arrayRow,arrayCol);
    for row = 1:arrayRow
        for col = 1:arrayCol
            if (row == 1 || col == 1 || row == arrayRow || ...
                    col == arrayCol)
                surroundArray(row,col)= surroundArray(row,col) * num;
            else
                surroundArray(row,col)=array(row-1,col-1);
            end   
        end
    end
end
