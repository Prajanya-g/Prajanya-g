clear;
clc;

% Taking user input for numbers
num1 = input("Enter a number: ");
num2 = input("Enter another number: ");

% Printing the sum of two number
fprintf("The sum is %d\n ", num1 + num2);

% Asking user for a text input 
name = input("Please enter your name: ",'s');

%Printing the users name 
fprintf("Hello there %s\n", name);

% Asking for the user's height 
height = input("Please enter your height in feet: ");

% Printing the user's name and height 
fprintf("%s your height is %d\n", name, height)

% Taking input for three age 
age_1 = input("please enter age of a person: ");
age_2 = input("please enter age of another person: ");
age_3 = input("please enter age of another person: ");

% Printing the sum of the ages
fprintf("The sum of the ages is %d\n", age_1 + age_2 + age_3);

% Asking for user input 
noun = input("Please enter a noun (a naming word): ",'s');

% Printing the noun 
fprintf("you have left your %s at the restaurant.\n ", noun)