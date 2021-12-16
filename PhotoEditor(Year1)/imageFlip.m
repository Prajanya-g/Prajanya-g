% This function flip the image according to the parameters by tranfering
% of the old vector a new vector.
% the function has two parameters the image data and the fliptype
% the function returns the new image vector

function[newImageData] = imageFlip(imageData,flipType)
    % calucating the image dimensions and declaring an empty vector
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = [];
    
    % nested loop to move through rows and columns three times
    for row=[1:imageRow]
        for col=[1:imageCol]
            for rgb = [1:imageRGB]
                % checking which way user wants to flip image
                if (flipType == "vertical")
                    % the top row of new vector is the last of old
                    newImageData(row,col,rgb) = ...
                        imageData(imageRow+1-row,col,rgb);
                else
                    % the left most column of the new image is the right
                    % most column of old 
                    newImageData(row,col,rgb) = ...
                        imageData(row,imageCol+1-col,rgb);
                end
            end
        end
    end
end

