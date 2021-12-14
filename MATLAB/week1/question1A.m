% @Title (Volume of a rectangle container)
% @Author (Prajanya Gupta)
% @Date (03/03/2021)

% The code uses user's inputs for height, depth and length of a rectangular cardboard
% container to calculate the volume of the container and print is as a
% output for the user. 

% Asking for the dimensions of the container
height = input("Please enter the height");
depth = input("Please enter the depth");
length = input("Please enter the length");

% Calculating the volume of the container 
volume = height * depth * length;

% Printing the volume 
fprintf("The volume is %d\n", volume);
