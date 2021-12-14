% test min and max of vector 
% Normal test case1 inputs
input1 = [-1 0 3 31 21];
input2 = [2 21 -213 321];
% expected output
output1 =  -213;
output2 = 312;
% using function for result
[min,max] =  minMaxVectors(input1,input2);
% printing result and expected output
fprintf("expected max: %0.2f \ngot: %0.2f\n",output2, max);
fprintf("expected min: %0.2f \ngot: %0.2f\n\n",output1, min);

% test case2 decimal and not equal vector inputs
input1 = [-1.23 2.31];
input2 = [2.21 -2.13];
% expected output
output1 = -2.13;
output2 = 2.31;
% using function for result
[min,max] =  minMaxVectors(input1,input2);
% printing result and expected output
fprintf("expected max: %0.2f \ngot: %0.2f\n",output2, max);
fprintf("expected min: %0.2f \ngot: %0.2f\n\n",output1, min);

% test case3 same inputs
input1 = [12 12 13 2 2];
input2 = [12 12 13 2 2];
% expected output
output1 = 2;
output2 = 13;
% using function for result
[min,max] =  minMaxVectors(input1,input2);
% printing result and expected output
fprintf("expected max: %0.2f \ngot: %0.2f\n",output2, max);
fprintf("expected min: %0.2f \ngot: %0.2f\n",output1, min);