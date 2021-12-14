% the code prints the even rows of the 2d vector given

% declaring the vector
A = [ 5, 4, 6, 7, 3 ; 1, 2, 3, 4, 5 ; 5, 6, 4, 2, 4 ; 4, 5, 3, 2, 1];

% reading rows and columns nxm
n = size(A,1);
m = size(A,2);

% using nested loop to perform operation on the 2d array
for row = [1:n]
    for col = [1:m]
        % checking for even rows
        if(mod(row,2)==0)
            fprintf("%d", A(row,col));
        end
    end
    % moving to next line after each row is printed
    fprintf("\n");
end