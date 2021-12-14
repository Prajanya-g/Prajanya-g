% The code prints a vector a the fence form using nested loops

% declaring the vector
A=[5,4,6,7,3;1,2,3,4,5;5,6,4,2,4;4,5,3,2,1];

for row = [1:size(A,1)]
    % printing first row
    if (row == 1)
        fprintf("%d",A(row,:));
        fprintf("\n");
    % printing last row
    elseif (row == size(A,1))
        fprintf("%d",A(row,:));
        fprintf("\n");
    % printing middle row
    else
        % printing first character of vector
        fprintf("%d",A(row,1));
        % printing spaces
        for empty = [1:size(A,2)-2]
            fprintf(' ');
        end
        % printing last character of vector
        fprintf("%d\n",A(row,size(A,2)));
    end
end