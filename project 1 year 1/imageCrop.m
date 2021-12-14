% the function crops the image by transfering the value of the reduced rows
% and columns to a new vector
% the function has five parameters the image data and the new dimensions
% the function returns the new image vector

function[newImageData] = imageCrop(imageData,topRow,bottomRow,leftCol,...
    rightCol)
    % calucating the image dimensions and declaring an empty vector
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = [];
    
    % calculating new rows and columns length
    newImageRow = imageRow-topRow-bottomRow;
    newImageCol = imageCol-leftCol-rightCol;

    % creating a vector with the with new lengths filled with one 
    newImageData = ones(newImageRow,newImageCol,imageRGB);

    % nested loop to move through rows and columns three times
    for row = [1 :newImageRow]
        for col = [1 : newImageCol]
            for rgb = [1: imageRGB]
                % multipling the pixels to the new array to transfer value
                newImageData(row,col,rgb) = newImageData...
                    (row,col,rgb)*imageData...
                    (topRow+row,leftCol+col,rgb);
            end
        end
    end
end

