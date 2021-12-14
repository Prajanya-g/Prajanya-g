imageData = imread("sample1.jpg");
newImageData = imageData;
% showing the image to the user
imshow(newImageData);

% Asking user if he wants to make the change
imageChange = input...
    ("Do u want to make the change in the image{yes/no}\n->  ",'s');

% coverting uppercase input to lower
imageChange = lower(imageChange);

% validating the input
while (imageChange ~= "yes" && imageChange ~= "no" )
    fprintf("Please check the input\n");
    imageChange = input...
        ("Do u want to make the change in the image{yes/no}\n->  ",'s');
end

% using switch case
switch imageChange
    case 'yes'
        imageData = newImageData;
    case 'no'
        % displaying message
        newImageData = [];
        fprintf("The image was discarded\n\n");
end

% asking for saving the image
imageSave = input("Do u want to save the image{yes/no}\n->  ",'s');

% coverting uppercase input to lower
imageSave = lower(imageSave);

% validating the input
while (imageSave ~= "yes" && imageSave ~= "no" )
    fprintf("Please check the input\n");
    imageSave = input...
        ("Do u want to save the image{yes/no}\n->  ",'s');
end

% using switch case
switch imageSave
    case 'yes'
        % asking user for file name
        fileName = input("Please enter the image name and the format: ",'s');
        imwrite(imageData,fileName);
    case 'no'
        % displaying message
        fprintf("The image was not saved\n\n");
end