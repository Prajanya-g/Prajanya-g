% The function manipualte the brightness of the image based on the
% parameters by adding the Equivalent amount to each element in the vector 
% There are two parameter the image data and the amount of change in brightness
% The function returns the new image vector

function[newImageData] = imageBright(imageData, brightnessAdjust)
    % calucating the image dimensions and declaring an empty vector
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = [];

    %checking if the vector had uint 8 or 0-1 double elements and
    %calculating change in brightness accordingly 
    % Getting the maximum value 
    maxNum = max(imageData,[],'all');
    
    % the image is generally a uint8 data type which has 255 max value but 
    % it is not necessary the vector has the max value. 
    % Also it can already in the range so we divide by 1. 
    if (maxNum >1  && maxNum <= 255)
        brightnessChange = 255*brightnessAdjust/100;
    elseif (maxNum > 0 && maxNum <= 1)
        brightnessChange = 1*brightnessAdjust/100;
    end
   
    % nested loop to go throught columns and rows three times
    for row=[1:imageRow]
        for col=[1:imageCol]
            for rbg = [1:imageRGB]
                % adding the changed brightness to all the elements in
                % the new vector
                newImageData(row,col,rbg) = imageData(row,col,rbg)+ ...
                    brightnessChange;
            end
        end
    end
end
