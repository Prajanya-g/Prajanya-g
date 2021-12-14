function[returnArray] = makeLayered(n)
returnArray = [1];
for i = 1:n
    arrayRow = n*2;
    arrayCol = n*2;
    if(n == 1)
        arrayRow = n;
        arrayCol = n;
    elseif(n==2)
        arrayRow = n+2;
        arrayCol = n+2;
    end
    surroundArray = ones(arrayRow,arrayCol);
    for row = 1:arrayRow
        for col = 1:arrayCol
            if (row == 1 || col == 1 || row == arrayRow || ...
                    col == arrayCol)
                surroundArray(row,col)= surroundArray(row,col) * n;
            else
                surroundArray(row,col)=returnArray(row-1,col-1);
            end
        end
    end
    returnArray = surroundArray
end
end