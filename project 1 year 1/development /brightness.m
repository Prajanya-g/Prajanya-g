%getting the image and calculating data
imageData = imread("tests.jpg"); 
imageRow = size(imageData,1);
imageCol = size(imageData,2);

% declaring change brightness 
brightnessAdjust = 30 ;
% calulating the change in brightness
brightnessChange = 255*brightnessAdjust/100;
% declaring the value 
newImageData = [];

% nested loop
for row=[1:imageRow]
    for col=[1:imageCol]
        % adding the amount to each element 
        newImageData(row,col) = imageData(row,col)+brightnessChange;
    end
end

% converting double image to 0-1 scale 
newImageData = newImageData/255;