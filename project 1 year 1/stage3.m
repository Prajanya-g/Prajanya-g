%sample data
imageData = imread("sample4.jpg");
%calaculating the dimension of the image
imageRow = size(imageData,1);
imageCol = size(imageData,2);
imageRGB = size(imageData,3);
newImageData = [];

% stage 3 crop

% displaying the current pixels in the image
fprintf("\nThe image has %dX%d pixels\n",imageRow, imageCol);
fprintf("Please enter the number of pixels you want to remove\n");
% asking user for the number of pixels to remove from the image
topRow = input("pixels from top: ");
fprintf("\n");
bottomRow = input("pixels from bottom: ");
fprintf("\n");
leftCol = input("pixels from left: ");
fprintf("\n");
rightCol = input("pixels from right: ");
fprintf("\n");

% the input should be less than the total rows and columns
% runs only when the input is larger
while (topRow>=imageRow || leftCol>=imageCol || ...
        bottomRow>=imageRow-topRow || rightCol>=imageCol-leftCol ...
        || topRow<0 || bottomRow<0 || leftCol<0 || rightCol<0)
    fprintf("Input exceeds the limits please enter a valid input\n");
    % asking user for the number of pixels to remove from the image again
    topRow = input("pixels from top: ");
    fprintf("\n");% new row
    bottomRow = input("pixels from bottom: ");
    fprintf("\n");% new row
    leftCol = input("pixels from left: ");
    fprintf("\n");% new row
    rightCol = input("pixels from right: ");
    fprintf("\n");
end

%cropping the image
newImageData = imageCrop(imageData,topRow,bottomRow,leftCol,...
    rightCol);

% converting the vector to a image
newImageData = imageConvert(newImageData);