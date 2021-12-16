% driver for imageResize
% function was also tested by visualization
% sample image 
imageData = imread("sample1.jpg");

% input vector 
input1 = [300,10,600,1000];
input2 = [400,20,1000,500];

% expected output which should be the same as input
output1 = input1;
output2 = input2;

%loop over inputs
for i = [1:length(input)]
    % recieved output and calulating it dimension to compare
    newImageData = imageResize(imageData,input1(i),input2(i));
    newRow = size(newImageData,1);
    newCol = size(newImageData,2);
    % printing 
    fprintf("expected row: %d\ngot: %d\n",output1(i), newRow);
    fprintf("expected column: %d\ngot: %d\n",output2(i), newCol);
end

