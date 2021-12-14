% sample data
imageData = imread("sample1.jpg");
%calaculating the dimension of the image
imageRow = size(imageData,1);
imageCol = size(imageData,2);
imageRGB = size(imageData,3);
newImageData = [];

% stage 6 resize

% display message and taking input
fprintf("\nPlease enter the new dimensions of the image\n");
newRowSize = input("Enter the number of rows you want\n-> ");
newColSize = input("Enter the number of columns you want\n-> ");

%validating should not be 0
while(newRowSize <= 0 || newColSize <= 0)
    fprintf("Please enter a valid input\n");
    % asking for new input
    newRowSize = input("Enter the number of rows you want\n-> ");
    newColSize = input("Enter the number of columns you want\n-> ");
end

% resizing
newImageData = imageResize(imageData,newRowSize,newColSize);

