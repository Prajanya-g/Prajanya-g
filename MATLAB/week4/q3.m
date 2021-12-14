clear;
clc;

% @Author (Prajanya Gupta)
% @Date (24/03/2021)

% The code uses nested loops to create a horizontal left to right gradient 
% that goes from black to white and saves it in the folder in png format.

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
        % making a pixel value that increases with each element in the column
        % from 0 - 1  
        pixelVal=(col)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    % adding row value to the 2d array representing the image 
    imageData=[imageData; imageRow]; 
end

% display as an image
imshow(imageData);

% save as an image
imwrite(imageData,'test3.png');

