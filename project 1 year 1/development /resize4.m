% reading the image and caluculating data
imageData = imread("test1.jpg");
newImageData = imageData;
imageRow = size(newImageData,1);
imageRGB = size(newImageData,3);
reduceSize = 400; % reduce size
halfRow = round(imageRow/2);
count = 0;
skipRow = fix(halfRow/reduceSize);
loopNum = 1;

% calculating number of loops needed as we cant resize image in a single
% loop and we might need multiple iteration based on image row size and the
% reduced size
if (reduceSize>halfRow)
    skipRow = 1;
    tempSize = reduceSize;
    tempRow = halfRow;
    loopSwitch = 1;
    while (loopSwitch ~= 0)
        tempSize = tempSize - tempRow;
        tempRow = round(tempRow/2);
        if (tempSize < tempRow)
            loopNum = loopNum + 1;
            loopSwitch = 0;
        else
            loopNum = loopNum + 1;
        end
    end
end

% using loop to empty vector in a single loop we can only reduce half the
% size so updatign data at the end 
newReduceSize  = reduceSize;
for i = 1 : loopNum;
    rowCount = 0;
    for row = [1:skipRow:halfRow]
        
        newImageData(row,:,:) = [];
        count = count + 1;
        rowCount = rowCount + 1;
        if (count == reduceSize)
            break;
        end

    end
    % updating data 
    newImageRow = size(newImageData,1);
    halfRow = round(newImageRow/2);
    newReduceSize = newReduceSize - rowCount;
    if(loopNum - i == 1)
        skipRow = fix(halfRow/newReduceSize);
    end
end

imshow(newImageData);