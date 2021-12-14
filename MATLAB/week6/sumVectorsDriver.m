% test sum of vector 
% Normal test case1 inputs
input1 = [-1 0 3 31 21];
input2 = [2 21 -213 321];
% expected output
output1 = 185;
% printing result and expected output
fprintf("expected: %0.2f got: %0.2f\n",output1, sumVectors(input1,input2));

% test case2 decimal 
input1 = [-1.23 2.31];
input2 = [2.21 -2.13];
% expected output
output1 = 1.16;
% printing result and expected output
fprintf("expected: %0.2f got: %0.2f\n",output1, sumVectors(input1,input2));

% test case3 empty vector inputs
input1 = [];
input2 = [];
% expected output
output1 = 0;
% printing result and expected output
fprintf("expected: %0.2f got: %0.2f\n",output1, sumVectors(input1,input2));
