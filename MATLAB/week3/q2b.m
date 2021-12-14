% @Author (Prajanya Gupta)
% @Date (18/03/2021)

% The code uses for-loop to combine two vectors with one in reverse order
% at the end of other and display the new combined vector

% Declaring vector to combine
A = [1:10];
B = [11:20];

% Using loop to combine the vectors the loop decrease to add elements in
% reverse
for i = length(B) : -1 : 1
   % Appending the value of B to the end of A 
   A = [A, B(i)]; 
end

% Displaying the new vector
disp(A);