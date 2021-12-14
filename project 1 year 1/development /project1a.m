clear;
clc;
% @Title: (Photo editing)
% @Author: (Prajanya Gupta)
% @version: 1.0 (03/04/2021)
% The code is a simple photo editting tool. It provied the options to crop,
% flip both horizontally and vertically and increase or decrease the
% brightness of the image and display out to the user

% welcome message
fprintf("\nWelcome photo editor \n\n");
fprintf("You can \n ->crop \n ->flip \n");
fprintf(" ->adjust the brightness of \nthe image.\n\n");

% asking the user for an image name and reading it
fprintf("Please enter the image name ");
fprintf("(it should be in the same folder as the code in png format)");
imagename = input(": ", 's');
imageData = imread(imagename);
%calaculating the dimension of the image 
imageRow = size(imageData,1);
imageCol = size(imageData,2);

% looping till user wants to end
imgEnd = " ";
while (imgEnd ~= "END")
    % Asking user for what function to use
    fprintf("\nPlease enter the following for the function you want to perform:\n");
    fprintf("  -> Enter {CROP} to crop the image\n");
    fprintf("  -> Enter {FLIP} to flip the image\n");
    fprintf("  -> Enter {BRIGHT} to adjust brightness\n");
    fprintf("NOTE: Remeber all the inputs should be in capital letters only\n\n");
    imageFunc = input("Please enter the function: ", 's');
    
    % using a switch to consider the cases
    switch imageFunc
        
        case 'CROP'
            % displaying the current pixels in the image
            fprintf("The image has %dX%d pixels\n",imageRow, imageCol);
            fprintf("Please enter the number of pixels you want to remove\n");
            % calling the crop function
            newImageData = imageCrop(imageData);
            
        case 'FLIP'
            %calling image flip function 
            newImageData  = imageFlip(imgaedata);
            
        case 'BRIGHT'
            fprintf("BRIGHT");
            %calling image brightness function 
            newImageData  = imageBright(imgaedata);

        otherwise
            fprintf("Please check the input\n");
    end
    
    
    % showing the image to the user
    imshow(newImageData);
    % asking for saving the image
    imageSave = input("Do u want to save the image{Y/N}: ",'s');
    % validating the input
    while (imageSave ~= 'Y' && imageSave ~= 'N' )
        fprintf("Please check the input\n");
        imageSave = input("Do u want to save the image{Y/N}: ",'s');
    end
    
    % using switch case
    switch imageSave
        case 'Y'
            % changing the imagedata
            imageData = newImageData;
            % asking user for file name
            fileName = input("Please enter the image name: ",'s');
            imwrite(imageData,fileName);
        case 'N'
            % displaying message
            fprintf("The image was not saved\n");
    end
    imgEnd = input("Please Enter {END} to end or press {ENTER} to continue:",'s');
end
