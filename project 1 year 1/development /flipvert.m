% reading image and calculating
imageData = imread("kand.png");
imageRow = size(imageData,1);
imageCol = size(imageData,2);
% empty vectoe
newImageData = [];

%nested loop
for row=[1:imageRow]
    for col=[1:imageCol]
        %last row first
        newImageData(row,col) = imageData(imageRow+1-row,col);
    end
end
% scale of 0-1
newImageData = newImageData/255;