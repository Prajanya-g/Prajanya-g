%sample data
imageData = imread("sample1.jpg");
%calaculating the dimension of the image
imageRow = size(imageData,1);
imageCol = size(imageData,2);
imageRGB = size(imageData,3);
newImageData = [];

%stage5 rotate

% displaying the current image in the image
imshow(imageData);
% asking user for the which way he/she wants to rotate
fprintf("\nHere is a preview of the image\n");
fprintf("You can rotate the image in the following ways\n");
fprintf(" -> Enter {right} to rotate image clockwise");
fprintf("\n");
fprintf(" -> Enter {left} to rotate image anti-clockwise ");
rotateType = input("\n -> ",'s');
fprintf("\n");
% coverting uppercase input to lower
rotateType = lower(rotateType);

% validating the input
% runs only when the input is larger
while (rotateType ~= "right" && rotateType ~= "left")
    fprintf("Please enter a valid input\n");
    % asking for new input
    fprintf(" -> Enter {right} to rotate image clockwise");
    fprintf("\n");
    fprintf(" -> Enter {left} to rotate image anti-clockwise ");
    rotateType = input("\n -> ",'s');
    fprintf("\n");
end

% rotating the image
newImageData = imageRotate(imageData, rotateType);

% converting the vector to a image
newImageData = imageConvert(newImageData);
            