% @Author (Prajanya Gupta)
% @Date (17/03/2021)

% The code calculates the cube of all the number in the vector A and
% stores it in another vector B

% Creating a vector A
A = [-10 : 0.5 : 10];

% Creating an empty vector 
B = [];

% vector appending 
for i = 1 : length(A)
    B = [B, A(i)^3];
end

% Diplaying the vector
disp(B);