% the function calculates the sum of two vectors 
% there are two parameters the vectors whose sum we have to calculate
% the function return a number 

function [sum] = sumVectors(v1, v2)
    % sum is zero
    sum = 0;
    % adding first vector to sum 
    for i = 1:length(v1)
        sum = sum + v1(i);
    end
    % adding second vector to sum that has sum of vector 1
    for j = 1:length(v2)
        sum = sum + v2(j);
    end
end