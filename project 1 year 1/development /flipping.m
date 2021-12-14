% displaying the current image in the image
imshow(imageData);
% asking user for the which way he/she wants to flip
fprintf("You can flip the image in the following ways\n");
fprintf(" -> Enter {VERTICAL} to flip image vertically ");
fprintf(" -> Enter {HORIZONTAL} to flip image horizontally ");
flipType = input("\n-> ",'s');

% validating the input
% runs only when the input is larger
while (flipType ~= "VERICAL" || flipType ~= "HORIZONTAL")
    fprintf("Please enter a valid input\n");
    % asking for new input
    fprintf(" -> Enter {VERTICAL} to flip image vertically ");
    fprintf(" -> Enter {HORIZONTAL} to flip image horizontally ");
    flipType = input("\n-> ",'s');
end
%nested loop
for row=[1:imageRow]
    for col=[1:imageCol]
        % if condition 
        if (flipType = "vertical")
            % adding last row to the new vector fist 
            newImageData(row,col) = imageData(imageRow+1-row,col);
        else
            % adding the last columns 
            newImageData(row,col) = imageData(row,imageCol+1-col);
        end
    end
end