%reading and calculating 
imageData = imread("kand.png"); 
imageRow = size(imageData,1);
imageCol = size(imageData,2);

%empty vector
newImageData = [];

% nested loop
for row=[1:imageRow]
    for col=[1:imageCol]
        % transferign the rows frist to all the last rows
% left      newImageData(imageCol+1-col,row)=imageData(row,col);
% transfering the last rows 
%  right     newImageData(col,row)=imageData(imageRow+1-row,col);
    end
end

% converting to a scale of 0-1
newImageData = newImageData/255;