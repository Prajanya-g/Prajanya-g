% test triple in loop
% input vector
input = [-3,-22,23,3,4.43,1,6,8];
%expected output 
output = [-9,-66,69,9,13.29,3,18,24];
%loop over inputs
for i = [1:length(input)]
    fprintf("expected: %0.2f got: %0.2f\n",output(i), triple(input(i)));
end
