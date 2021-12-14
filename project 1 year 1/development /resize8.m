% reading image and calulatign adata
imageData = imread("tests.jpg"); 
imageRow = size(imageData,1);
imageCol = size(imageData,2);
increaseRowSize = 100;
increaseColSize = 100;
addRow = fix(imageRow/increaseRowSize);
addCol = fix(imageCol/increaseColSize);
% declaring vector with ones reprenting which elemnt to double 
duplicateRow = ones(1,imageRow);
count =  0;
duplicateCol = ones(1,imageCol);

% using loop to convert elements to two for element we want to double later
for add = 1:addRow:imageRow
    if (count == increaseRowSize)
        break;
    end
    duplicateRow(add)  = duplicateRow(add)*2;
    count = count + 1;
    
end

% using loop to convert elements to two for element we want to double later
count2 = 0;
for add = 1:addCol:imageCol
    duplicateCol(add)  = duplicateCol(add)*2;
    count2 = count2 + 1;
    if (count2 == increaseColSize)
        break;
    end
end

% increasing the size
newImageData = repelem(imageData,duplicateRow,duplicateCol);

% add conditio for 0