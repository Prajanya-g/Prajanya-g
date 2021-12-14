newImageData = imread("test3.jpg"); 
imageRow = size(newImageData,1);
reduceRowSize = 300; % reduce size
halfRow = round(imageRow/2);
count = 0;
skipRow = fix(halfRow/reduceRowSize);
loopNum = 1;

if (reduceRowSize>halfRow)
    skipRow = 1;
    tempSize = reduceRowSize;
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

   newReduceRowSize  = reduceRowSize;
for i = 1 : loopNum;
    rowCount = 0;
for row = [1:skipRow:halfRow]
    newImageData(row,:,:) = [];
    count = count + 1;
    rowCount = rowCount + 1;
    if (count == reduceRowSize)
        break;
    end
end
newImageRow = size(newImageData,1);
halfRow = round(newImageRow/2);
newReduceRowSize = newReduceRowSize - rowCount;
if(loopNum - i == 1)
skipRow = fix(halfRow/newReduceRowSize);
end
end
    
imshow(newImageData);