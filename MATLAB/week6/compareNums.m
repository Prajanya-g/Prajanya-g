% the function compares two numbers and finds the bigger and the smaller
% number 
% there are two parameter the two number we have to compare 
% the function returns the bigger and smaller number 

function [small, big] = compareNums(x,y) 
    % checking if x is greater than y else y id greater
    if(x >= y)
        % transfering the values 
        big = x;
        small = y;
    else
        % transfering the values
        big = y;
        small = x;
    end
end
    

