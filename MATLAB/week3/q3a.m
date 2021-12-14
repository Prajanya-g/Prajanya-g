% @Author (Prajanya Gupta)
% @Date (18/03/2021)

% The code reads the user input and tell whether the number is divisble by
% 4 or not and gives in a output accordingly

% Getting the number
num1 = input("Enter a number: ");

% Using if and else statement to check divisibilty
if(mod(num1,4) == 0)
    % Displaying message if conditions met 
   disp("Divisible by four");
else
    % displaying the message if contions not met 
   disp("Not divisible by four"); 
end


