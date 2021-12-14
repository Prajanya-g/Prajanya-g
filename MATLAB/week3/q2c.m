    % @Author (Prajanya Gupta)
% @Date (18/03/2021)

% The code uses for-loop to combine two vectors with one element of both
% one after other and stores it in a new vector

% Declaring vector to combine
A = [1:10];
B = [11:20];
% Declaring an empty vector to store the combination
C = [];

% Using loop to combine the vectors
for i = 1 : length(A)
   % Adding the elements to C one by one
   C = [C, A(i)];
   C = [C, B(i)];
end

% Displaying the new vector
disp(C);