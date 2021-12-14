imageData = imread("tests.jpg"); 

% declaring new row and column length
    newRedImg = size(imageData,1)-topRow-bottomRow;
    newGreenImg = size(imageData,2)-leftCol-rightCol;
    newBlueImg = size(imageData,3);

    % creating a vector with the with new row and column length
    newImageData = ones(newRedImg,newGreenImg,newBlueImg);

    % going throught each row and column using nested loop
    for red = [1 :newRedImg]
        for green = [1 : newGreenImg]
            for blue = [1: newBlueImg] 
            % multipling the pixels to the new array
            newImageData(red,green,blue) = newImageData(red,green,blue)*...
                imageData(topRow+red,Leftcol+green, blue);
            end
        end
    end

    % converting the pixel to a range of 0.1 and 1 by dividing by 255 which
    % is the maximum in these image 
    newImageData = newImageData/255;