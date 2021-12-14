clear;
clc;

% @Author (Prajanya Gupta)
% @Date (24/03/2021)

% The code uses nested loops to create a verticle gradient that 
% goes from white to black and saves it in the folder in png format.

% set up an empty array
imageData=[];

% specifing the size of the image
imSize=100;
numRows=imSize;
numCols=imSize;

%populate using a nested loop
for row=[1:numRows]
    %empty vector for row
    imageRow=[]; 
    for col=[1:numCols]
        % making a pixel value that decreases with the row from 1 - 0
        pixelVal=(100 - row)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    % adding row value to the 2d array representing the image 
    imageData=[imageData; imageRow]; 
end

% display as an image
imshow(imageData);

% save as an image
imwrite(imageData,'test2.png');

