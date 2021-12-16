% The function converts the double data to a range of 0 - 0.1 which
% is used to display an image.
% The function has one parameters the image data.
% The function returns the converted image data.

function [imageVector] =  imageConvert(imageData)
    % Getting the maximum value 
    maxNum = max(imageData,[],'all');
    
    % the image is generally a uint8 data type which has 255 max value but 
    % it is not necessary the vector has the max value. 
    % Also it can already in the range so we divide by 1. 
    if (maxNum >1  && maxNum <= 255)
        maxNum = 255; 
    elseif (maxNum > 0 && maxNum <= 1)
        maxNum = 1;
    end
    
    % converting to the range of 0-1
    imageVector = imageData/maxNum;
end

