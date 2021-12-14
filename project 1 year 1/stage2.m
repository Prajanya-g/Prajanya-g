% stage2 different functionality and dimension calculation
% looping till user wants to end
imgEnd = " ";
while (imgEnd ~= "end")
    imageData = imread("sample3.jpg");
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
            fprintf("CROP");
        case 'flip'
            fprintf("FLIP");
        case 'rotate'
            fprintf("ROTATE");
        case 'resize'
            fprintf("RESIZE");
        case 'bright'
            fprintf("BRIGHT");
        otherwise
            fprintf("Please check the input\n");
    end
    imageEnd = "end";
end