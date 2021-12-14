% driver for imageCrop 

% sample image 
imageData = imread("sample1.jpg");

% input vector 
input1 = [100,10,120,300,0];
input2 = [100,50,140,0,120];
input3 = [300,50,220,400,0];
input4 = [100,203,30,21,0];

% expected output 
output1 = [184,324,124,84,264];
output2 = [112,259,262,91,512];

%loop over inputs
for i = [1:length(input1)]
    % recieved output and calulating it dimension to compare
    newImageData = imageCrop(imageData,input1(i),input2(i),input3(i),...
        input4(i));
    newRow = size(newImageData,1);
    newCol = size(newImageData,2);
    % printing 
    fprintf("expected row: %d\ngot: %d\n",output1(i), newRow);
    fprintf("expected column: %d\ngot: %d\n",output2(i), newCol);
end
