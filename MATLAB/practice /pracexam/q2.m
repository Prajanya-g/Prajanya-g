% the code finds the largest number in the given vector of n numbers

% declaring vector
A = [5, 4, 6, 7, 3];

% number of elements
n = length(A);

% declaring max value as the first number
max = A(1);

% using for loop to compare all the numbers
% loop starts from 2 becuse the first element is max
for i = [2:n]
    % checking if the element it greater than current max
    if  max < A(i)
        max = A(i);
    end
end

%printing the largest value
fprintf("The largest number is %d \n",max);