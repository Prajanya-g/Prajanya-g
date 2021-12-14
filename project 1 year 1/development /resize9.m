% reading image and calulating data
imageData = imread("Kand.png");
newImageData = imageData;
imageRow = size(imageData,1);
increaseRowSize = 5000;
skipRow = fix(imageRow/increaseRowSize);
duplicateRow = ones(1,imageRow);
loopNum = 1;

% countign loop needed as in a loop we can only double the sizeof the image
% so we need to calculate loops for larger chnages 
if (increaseRowSize > imageRow)
    skipRow = 1;
    tempSize = increaseRowSize;
    tempRow = imageRow;
    loopSwitch = 1;
    while (loopSwitch ~= 0)
        tempSize = tempSize - tempRow;
        tempRow = tempRow*2;
        if (tempSize < tempRow)
            loopNum = loopNum + 1;
            loopSwitch = 0;
        else
            loopNum = loopNum + 1;
        end
    end
end


% using loop to make a new vector and change the image 
count = 0;
newReduceSize = increaseRowSize;
for i = 1 : loopNum
    % updating variables
    newImageRow = size(newImageData,1);
    duplicateRow = ones(1, newImageRow);
    rowCount = 0;
    for add = [1:skipRow: newImageRow]
        if (count == increaseRowSize);
            break;
        end
        % changing the vector
        duplicateRow(add)  = duplicateRow(add)*2;
        count = count+1;
        rowCount = rowCount + 1;
    end
    % updating variables
   newReduceSize = newReduceSize - rowCount;
   newImageData = repelem(newImageData,duplicateRow,1);
   newImageRow = size(newImageData,1);
  if(loopNum - i == 1)
        skipRow = fix(newImageRow/newReduceSize);
    end
end

