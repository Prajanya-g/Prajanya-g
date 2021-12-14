% The function rotates the image by making the rows of the old columns of
% new vector and columns rows
% there are two parameter the image data and the way the user wants to
% rotate the image i.e. right or left 
% the function returns the new image vector

function[newImageData] = imageRotate(imageData, rotateType)
    % calucating the image dimensions and declaring an empty vector
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = [];

    % using nested loop to iterate through rows and columns three times
    for row = [1:imageRow]
        for col = [1:imageCol]
            for rbg = [1:imageRGB]
                % condition based on which way the user wants to rotate
                if (rotateType == "left")
                    % transfering the columns to the last rows of the new 
                    % image vector i.e. column becomes rows 
                    newImageData(imageCol+1-col,row,rbg)=...
                        imageData(row,col,rbg);
                else
                    % transfering the last row of image to the new vector
                    newImageData(col,row,rbg)=...
                        imageData(imageRow+1-row,col,rbg);
                end
            end
        end
    end
end

