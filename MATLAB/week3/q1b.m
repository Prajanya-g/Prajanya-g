% @Author (Prajanya Gupta)
% @Date (17/03/2021)

% The code calculates the 2 raised to the power of each element in A and
% stores it in another vector C

% Creating a vector A
A = [-10 : 0.5 : 10];

% Creating an empty vector 
C = [];

% vector appending 
for i = 1 : length(A)
    C = [C, pow2(A(i))];
end

% Diplaying the vector
disp(C);