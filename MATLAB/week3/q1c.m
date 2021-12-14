% @Author (Prajanya Gupta)
% @Date (17/03/2021)

% The code performs calculation on vector A and store in a new vector B and
% C and plot the graph for both

% Creating a vector A
A = [-10 : 0.5 : 10];
% Creating an empty vector 
B = [];
C = [];

% vector appending 
for i = 1 : length(A)
    B = [B, A(i)^3];
end

% vector appending 
for i = 1 : length(A)
    C = [C, pow2(A(i))];
end

 % display plots on the same window for now
hold on;
% plotting the graph with A as value to x axis 
plot(A,B);
plot(A,C);


