clear;
clc;

% @Author (Prajanya Gupta)
% @Date (24/03/2021)

% The code uses nested loops to create a plus shaped gradient that 
% goes from black in the center to white on the edges and saves it in the 
% folder in png format.

 % set up an empty array
imageData=[];
% specifing the size of the image
imSize=100;
numRows=imSize;
numCols=imSize;

%populate using a nested loop a 50 x 100 array
for row=[1:numRows/2]
    %empty vector for row
    imageRow=[]; 
    
    % getting data for the first 50 x 50 image (column 0 - 50)
    for col=[1:numCols/2]
        % making a pixel value 0..1
        pixelVal= 1 - (row + col)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    
    % getting data for the second 50 x 50 image (column 50 - 100)
    for col=[1:numCols/2]
        % making a pixel value 0..1
        pixelVal=(50 - row+col)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    % adding row value to the 2d array representing the image 
    imageData=[imageData; imageRow]; 
end

% populate using a nested loop a 50 x 100 array that is the bottom part
for row=[1:numRows/2]
    %empty vector for row
    imageRow=[]; 
    % getting data for the first 50 x 50 image (column 0 - 50)
    
    for col=[1:numCols/2]
        % making a pixel value 0..1
        pixelVal= 1 - (50 - row + col)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    
    % getting data for the second 50 x 50 image (column 50 - 100)
    for col=[1:numCols/2]
        % making a pixel value 0..1
        pixelVal=(row+col)/(imSize);
        %adding value for  pixel to the row
        imageRow=[imageRow pixelVal];  
    end
    
    % adding row value to the 2d array representing the image 
    imageData=[imageData; imageRow]; 
end

% display as an image
imshow(imageData);

% save as an image
imwrite(imageData,'test5.png');

