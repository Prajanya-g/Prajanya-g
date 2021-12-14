% sample data
imageData = imread("sample1.jpg");
%calaculating the dimension of the image
imageRow = size(imageData,1);
imageCol = size(imageData,2);
imageRGB = size(imageData,3);
newImageData = [];

% stage 7 brightness adjust

% displaying the current image in the image
imshow(imageData);
% asking user for the which way he/she wants to rotate
fprintf("\nHere is a preview of the image\n");
fprintf("please enter a number from -100 - 100\n");
fprintf("If the number is negative the image will get darker\n");
fprintf("If the number is greater the image gets brighter\n");
brightnessAdjust = input("-> ");

% validating the input and asking is invalid
while (brightnessAdjust < -100 || brightnessAdjust > 100)
    fprintf("Please enter a valid input\n");
    % asking for new input
    fprintf("please enter a number from -100 - 100\n");
    fprintf("If the number is negative the image will get darker\n");
    fprintf("If the number is greater the image gets brighter");
    brightnessAdjust = input("\n -> ");
end

% increasing the brightness
newImageData = imageBright(imageData, brightnessAdjust);

% converting the vector to a image
newImageData = imageConvert(newImageData);
