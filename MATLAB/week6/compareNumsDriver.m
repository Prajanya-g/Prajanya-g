% test compareNumDriver in loop
% input vector
input1 = [-3,-22,23,3,4,1.32,24,8];
input2 = [0,-20,2,3,3,-10,24.32,43];
% expected output 
output1 = [0,-20,23,3,4,1.32,24.32,43];
output2 = [-3,-22,2,3,3,-10,24,8];
%loop over inputs
for i = [1:length(input1)]
    % recieved output
    [small,big] = compareNums(input1(i),input2(i));
    fprintf("expected big: %0.2f \ngot: %0.2f\n",output1(i), big);
    fprintf("expected small: %0.2f \ngot: %0.2f\n\n",output2(i), small);
end

