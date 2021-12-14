clear;
clc;

% The code takes in the width and height of a rectangle and calculate the
% area

width = input("Please enter width: ");
height = input("Please enter height: ");
% calculating area and perimeter
areaRect = width * height;
perimerterRect = width + height;

% Printing output 
fprintf("The area is %.2f\n", areaRect);
fprintf("The perimeter is %.2f\n", perimeterRect);


% The code reads the latitude and longitude of a turbine along with its
% name of the wind farm and prints out the information to the user

% Asking for user input
latitude = input("Enter the latitude of the turbine: ");
longitude = input("Enter the longitude of the turbine: ");
windFarm = input("Enter the farm name of the turbine: ",'s');

% print the inpformation 
fprintf("Farm name %s, %.4f : %.4f\n", windFarm, latitude, longitude);


% The code takes in user input and calcuate how long his money will last

% Asking for user input
balance = input("Enter your balance: ");
expenditure = input("Enter your weekly expenditure: ");
% calculating
weeksLeft = balance / expenditure;

% print the inpformation 
fprintf("You have %.1f weeks left before your money runs out.\n", weeksLeft);


% The code read a type of animal, its name and some action. prints it out

% asking for user input 
animal = input("Enter a type of animal: ",'s');
animalName = input("Enter a name: ",'s');
action = input("Enter an activity: ",'s');

% pirnting output
fprintf("I saw your %s, %s, %s\n", animal, animalName, action);