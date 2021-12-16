% driver for imageBright
% function was also tested by visualization
% sample image 
imageData = imread("sample1.jpg");

% input vector 
input = [10,0,55,90];

% expected output for the new first element 
output1 = [127,101,241,255];

%loop over inputs
for i = [1:length(input)]
    % original first element 
    original = imageData(1,1,1);
    % recieved output and declaring its first element
    newImageData = imageBright(imageData,input(i));
    newElement1 = newImageData(1,1,1);
    % printing 
    fprintf("expected element1 of vector: %d\noriginal: %d\ngot: %d\n",...
        output1(i), original, newElement1);
end

