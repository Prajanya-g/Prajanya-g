% @Title (BMI calculator)
% @Author (Prajanya Gupta)
% @Date (10/03/2021)

% The code takes user input for weight and height of a person to calculate
% the BMI and display it 

% Asking for user input 
weight = input("Enter your weight in kgs: ");
height = input("Enter your height in m: ");

% Calculating the BMI 
BMI = weight/(height^2);

% Printing BMI
fprintf("Your BMI is: %.2f\n", BMI);
