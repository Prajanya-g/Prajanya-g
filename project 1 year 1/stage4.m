%sample data
imageData = imread("sample2.jpg");
%calaculating the dimension of the image
imageRow = size(imageData,1);
imageCol = size(imageData,2);
imageRGB = size(imageData,3);
newImageData = [];

% stage 4 flip

% displaying the current image in the image
imshow(imageData);

% asking user for the which way he/she wants to flip
fprintf("\nHere is a preview of the image\n");
fprintf("You can flip the image in the following ways\n");
fprintf(" -> Enter {vertical} to flip image vertically");
fprintf("\n");
fprintf(" -> Enter {horizontal} to flip image horizontally ");
flipType = input("\n -> ",'s');
fprintf("\n");

% coverting uppercase input to lower. if lowercase it remains same.
flipType = lower(flipType);
            
% validating the input
% runs only when the input is wrong
while (flipType ~= "vertical" && flipType ~= "horizontal")
    fprintf("Please enter a valid input\n");
    % asking for new input
    fprintf(" -> Enter {vertical} to flip image vertically ");
    fprintf("\n");
    fprintf(" -> Enter {horizontal} to flip image horizontally ");
    flipType = input("\n-> ",'s');
    fprintf("\n");
end

% flipping the image
newImageData = imageFlip(imageData, flipType);

% converting the vector to a image
newImageData = imageConvert(newImageData);