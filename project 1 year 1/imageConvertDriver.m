% driver for ImageConvert

% sample image and calculating dimensions 
imageData = imread("sample1.jpg");
input = double(imageData);

% expected output for the new first four elements 
output = [0.4,0.41,0.38,0.41];

%loop over inputs
for i = [1:length(output)]
    % recieved output and declaring its first element
    newImageData = imageConvert(input);
    newElement1 = newImageData(1,i,1);
    % printing 
    fprintf("expected element%d of vector: %0.2f\ngot: %0.2f\n",i, output(i), ...
        newElement1);
end
