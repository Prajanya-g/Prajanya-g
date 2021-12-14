% readign image and calulating data 
imageData = imread("kand.png"); 
imageRow = size(imageData,1);
newRowSize = 100;%reduced size
halfRow = round(imageRow/2);
count = 0;
% how many rows to skip to get a even image 
skipRow = fix(halfRow/newRowsize)

% loop that skip elemnt according to calculations 
for row = [1:skipRow:halfRow]
    % empting row and counting 
    imageData(row,:) = [];
    count = count + 1;
    % breaks once the target achieved
    if (count == newRowSize)
        break;
    end
end

% displaying image 

 imshow(imageData);