% @Title (sum of absolute numbers)
% @Author (Prajanya Gupta)
% @Date (10/03/2021)

% The code reads five number find the absolute values of those numbers and
% displays sum of those numbers together 

% Taking the input and converting to absolute value
num1 = abs(input("Enter first number: "));
num2 = abs(input("Enter second number: ")); 
num3 = abs(input("Enter third number: ")); 
num4 = abs(input("Enter forth number: ")); 
num5 = abs(input("Enter five number: "));

% Calculating the sum 
absSum = num1 + num2 + num3 + num4 + num5;

% Printing the value 
fprintf("The sum of absolute values is %.1f\n", absSum);
