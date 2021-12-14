% READING IMAGE AND CALULATING 
imageData = imread("kand.png"); 
imageRow = size(imageData,1);
imageCol = size(imageData,2);
% EMPTY VECTOR 
newImageData = [];

% nested loop
for row=[1:imageRow]
    for col=[1:imageCol]
        % transfering the last columns 
        newImageData(row,col) = imageData(row,imageCol+1-col);
    end
end

%converting to 0-1
newImageData = newImageData/255;