% This function resizes the image by removing rows and columns or adding
% them depending on the length provided in the parameter.
% There are three parameter the image data and the new row and column
% lengths
% The function returns the resized image data.

function[newImageData] = imageResize(imageData,newRowSize,newColSize)
    % calucating the image dimensions and declaring an duplicate vector
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = imageData;

    % Checking if the new row length is greater or smaller than previous
    if (newRowSize > imageRow)
        % calculating increase
        increaseRowSize = newRowSize - imageRow;
        % calculating loops needed
        loopNum = loopCounter(increaseRowSize, imageRow, "increase");
        
        % if loop number is 1 then skip row is one
        if (loopNum > 1)
            skipRow = 1;
        else
            skipRow = fix(imageRow/increaseRowSize);
        end
        
        % counting variable
        count = 0;
        % creating a dublicate variable to perform calculations
        newIncreaseSize = increaseRowSize;
        for i = 1 : loopNum
            % updating variable
            newImageRow = size(newImageData,1);
            % creating a duplicate vector
            duplicateRow = ones(1, newImageRow);
            % counting variable
            rowCount = 0;
            for add = [1:skipRow: newImageRow]
                % breaking is size increased
                if (count == increaseRowSize);
                    break;
                end
                % adding variable
                duplicateRow(add) = duplicateRow(add)*2;
                % increasing value
                count = count+1;
                rowCount = rowCount + 1;
            end
            % updating  variable
            newIncreaseSize = newIncreaseSize - rowCount;
            newImageData = repelem(newImageData,duplicateRow,1);
            newImageRow = size(newImageData,1);
            % if it is the last loop then the skip row changes
            if(loopNum - i == 1)
                skipRow = fix(newImageRow/newIncreaseSize);
            end
        end
        
    elseif(newRowSize < imageRow)
        % calaulating the rows to decrease, half of actually row size
        reduceSize = imageRow-newRowSize;
        halfSize = round(imageRow/2);
        % calculating loops needed
        loopNum = loopCounter(reduceSize, halfSize, "decrease");

        % if loop number is 1 then skip row is one
        if (loopNum > 1)
            skipRow = 1;
        else
            skipRow = fix(halfSize/reduceSize);
        end

        
        % counting variable
        count = 0;
        % creating a dublicate variable to perform calculations
        newReduceRowSize  = reduceSize;
        for i = 1 : loopNum;
            % counter variable
            rowCount = 0;
            for row = [1:skipRow:halfSize]
                % empting the row
                newImageData(row,:,:) = [];
                % increasing counter
                count = count + 1;
                rowCount = rowCount + 1;
                % breaks if the size is reduced
                if (count == reduceSize)
                    break;
                end
            end
            % updating the variables
            newImageRow = size(newImageData,1);
            halfSize = round(newImageRow/2);
            newReduceRowSize = newReduceRowSize - rowCount;

            % if it is the last loop then the skip row changes
            if(loopNum - i == 1)
                skipRow = fix(halfSize/newReduceRowSize);
            end
        end
    end

    % Checking if the new column length is greater or smaller than previous
    if(newColSize > imageCol)
        % calculating increase
        increaseColSize = newColSize - imageCol;
        % calculating loops needed
        loopNum = loopCounter(increaseColSize, imageCol, "increase");

        % if loop number is 1 then skip col is one
        if (loopNum > 1)
            skipCol = 1;
        else
            skipCol = fix(imageCol/increaseColSize);
        end

        % counting variable
        count = 0;
        % creating a dublicate variable to perform calculations
        newIncreaseSize = increaseColSize;
        for i = 1 : loopNum
            % updating variable
            newImageCol = size(newImageData,2);
            % creating a duplicate vector
            duplicateCol = ones(1, newImageCol);
            % counting variable
            colCount = 0;
            for add = [1:skipCol: newImageCol]
                % breaking is size increased
                if (count == increaseColSize);
                    break;
                end
                % adding variable
                duplicateCol(add)  = duplicateCol(add)*2;
                % increasing value
                count = count+1;
                colCount = colCount + 1;
            end
            % updating  variable
            newIncreaseSize = newIncreaseSize - colCount;
            newImageData = repelem(newImageData,1,duplicateCol);
            newImageCol = size(newImageData,2);
            % if it is the last loop then the skip col changes
            if(loopNum - i == 1)
                skipCol = fix(newImageCol/newIncreaseSize);
            end
        end

    elseif(newColSize < imageCol)
        % calaulating the cols to decrease, half of actually col size
        reduceSize = imageCol - newColSize;
        halfSize = round(imageCol/2);
        % calculating loops needed
        loopNum = loopCounter(reduceSize, halfSize, "decrease");

        if (loopNum > 1)
            skipCol = 1;
        else
            skipCol = fix(halfSize/reduceSize);
        end

        % counting variable
        count = 0;
        % creating a dublicate variable to perform calculations
        newReduceColSize  = reduceSize;
        for i = 1 : loopNum;
            % counter variable
            colCount = 0;
            for col = [1:skipCol:halfSize]
                % empting the column
                newImageData(:,col,:) = [];
                % increasing counter
                count = count + 1;
                colCount = colCount + 1;
                % breaks if the size is reduced
                if (count == reduceSize)
                    break;
                end
            end
            % updating the variables
            newImageCol = size(newImageData,2);
            halfSize = round(newImageCol/2);
            newReduceColSize = newReduceColSize - colCount;

            % if it is the last loop then the skip col changes
            if(loopNum - i == 1)
                skipCol = fix(halfSize/newReduceColSize);
            end
        end
    end
end