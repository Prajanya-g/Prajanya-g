clear;
clc;
% @Title: (Photo editing)
% @Author: (Prajanya Gupta)
% @version: 2.5 (24/04/2021)
% The code is a simple photo editting tool. It provied the options to crop,
% flip both horizontally and vertically, rotate, resize and increase or
% decrease the brightness of the image and display out to the user

% welcome message
fprintf("Welcome photo editor\n\n");
fprintf("You can edit the image in the following ways:\n");
fprintf("\n ->Crop\n ->Flip\n ->Resize\n ->Rotate\n");
fprintf(" ->Adjust the brightness\n\n");
% asking the user for an image name and reading it
fprintf("Please enter the image name ");
fprintf("(it should be in the same folder as the code)");
imagename = input("\n-> ", 's');
imageData = imread(imagename);

% looping till user wants to end
imgEnd = " ";
while (imgEnd ~= "end")
    
    %calaculating the dimension of the image
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);
    imageRGB = size(imageData,3);
    newImageData = [];
    
    % Asking user for what function to perform on the image
    fprintf("\nPlease enter the following for the function you want to perform:\n");
    fprintf("  -> Enter {crop} to crop the image\n");
    fprintf("  -> Enter {resize} to resize the image\n");
    fprintf("  -> Enter {rotate} to rotate the image\n");
    fprintf("  -> Enter {flip} to flip the image\n");
    fprintf("  -> Enter {bright} to adjust brightness\n");
    imageFunc = input("Please enter the function:\n-> ", 's');
    
    % coverting uppercase input to lower
    imageFunc = lower(imageFunc);
    
    % using a switch to consider the cases
    switch imageFunc
        case 'crop'
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
            % runs only when the input is smaller than original and greater
            % than 0
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
            
            
        case 'flip'
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
            
            % coverting uppercase input to lower
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
            
            
        case 'rotate'
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
            
            
        case 'resize'
            % displaying the current pixels in the image
            fprintf("\nThe image has %dX%d pixels\n",imageRow, imageCol);
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

            
        case 'bright'
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
                fprintf("If the number is greater the image gets brighter\n");
                brightnessAdjust = input("-> ");
            end
            
            % increasing the brightness
            newImageData = imageBright(imageData, brightnessAdjust);
            
            % converting the vector to a image
            newImageData = imageConvert(newImageData);
            
            
        otherwise
            fprintf("Please check the input\n");  
    end
    
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
    while (imageSave ~= "yes" && imageSave ~= "no")
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
    imgEnd = input...
        ("Please Enter {end} to end or press {ENTER KEY} to continue\n-> ",'s');
end
