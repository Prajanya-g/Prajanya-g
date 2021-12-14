% the code has displays the index of the first number divisible by 3

% declaring the vector 
A = [5, 4, 6, 7, 3];

for i =[1:length(A)]
    % checking for divisibility by 3
    if ( mod(A(i),3) == 0)
        % printing 
        fprintf("The index first number divisible by 3 is: %d\n", i);
        % ends the loop after first index 
        break;
    end
end

