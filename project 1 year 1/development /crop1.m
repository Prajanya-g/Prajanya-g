%calaculating the dimension of the image 
    imageRow = size(imageData,1);
    imageCol = size(imageData,2);

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
    while (topRow>imageRow || leftCol>imageCol || ...
            bottomRow>imageRow-topRow || rightCol>imageCol-leftCol)
        
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

    % declaring new row and column length
    newTotalRow = imageRow-bottomRow-topRow;
    newTotalCol = imageCol-rightCol-leftCol;

    % creating a vector with the with new row and column length
    newImageData = ones(newTotalRow,newTotalCol);

    % going throught each row and column using nested loop
    for row = [1 :newTotalRow]
        for col = [1 : newTotalCol]
            % multipling the pixels to the new array
            newImageData(row,col) = newImageData(row,col)*...
                imageData(topRow+row,leftCol+col);
        end
    end

    % converting the pixel to a range of 0.1 and 1 by dividing by 255 which
    % is the maximum in these image 
    newImageData = newImageData/255;