clear;
clc;

% @Author (Prajanya Gupta)
% @Date (24/03/2021)

% The code uses nested loops to create an image of the same size but 
% flipped both horizontally and vertically

% load an image
imageData = imread('Kand.png');

% Declaring an empty 2d array for the new image 
newImageData = []; 

% dimension of the image 
sizeRow = size(imageData,1);
sizeCol = size(imageData,2);

% using nested loop to itterate throught the array
for row = [1:sizeRow]
    % declaring an empty variable 
    imageRow = [];
    
    for col = [1:sizeCol]
        % rotating both vertically and horizontally by calling the last row
        % and column first
         pixelVal = imageData(sizeRow + 1 - row, sizeCol + 1 - col);
         imageRow=[imageRow pixelVal];   
    end
     % adding rows value to the 2d array representing the image 
    newImageData=[newImageData; imageRow]; 
end

% display as an image
imshow(newImageData);

% save as an image
imwrite(imageData,'test6.png');