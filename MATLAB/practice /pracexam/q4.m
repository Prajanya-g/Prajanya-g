% The code asks the user for the size of the 2d array and the filles it based
% on the user input. Then displays the sum of all the even columns in the array

% asking for size
sizeRow = input("How many rows?: ");
sizeCol = input("How many columns?: ");
%sum is initially 0
sum  = 0;

% nested loop for row and and columns
for row = [1 : sizeRow]
    for col = [1 : sizeCol]
        % getting input
        fprintf ("Enter the values for row %d, column %d", row , col);
        A(row,col) = input(": ");
        % adding the values of even columns
        if (mod(col,2)==0)
            sum = sum + A(row,col);
        end
    end
end

%printing the final value
fprintf("The sum of all the elements of the even columns is: %0.1f\n",sum);