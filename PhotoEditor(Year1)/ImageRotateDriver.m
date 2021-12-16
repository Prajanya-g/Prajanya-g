% driver for imageRotate 
% function was also tested by visualization
% sample image input
imageData = imread("sample1.jpg");

% input vector 
input = ["right","left","right","left"];

% expected output for the new first element 
output1 = [217,98,189,74];

%loop over inputs
for i = [1:length(input)]
    % recieved output and declaring its first element
    newImageData = imageRotate(imageData,input(i));
    newElement1 = newImageData(1,1,1);
    % printing 
    fprintf("expected element1 of vector: %d\ngot: %d\n",output1(i), ...
        newElement1);
    % changing imageData for test
    if (i == 2)
        imageData = imread("sample2.jpg");
    end
end

