% the code read in five numbers. Stores them in a vector and prints them in
% reverse order skipping each other number.

% total numbers
n = 5;

% using for loop to read numbers
for i = [1:n]
    % storing in vector num by indexing
    num(i) = input("Enter a number: ");
end

% printing the numbers in reverse skipping a number
fprintf("Your numbers reversed skipping every other number are: ");
for i = [n : -2 : 1]
    fprintf("%d ",num(i));
end
fprintf("/n");