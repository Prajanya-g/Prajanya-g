% @Title (Volume of a rectangle container)
% @Author (Prajanya Gupta)
% @Date (03/03/2021)

% The code uses user's inputs for height, depth and length of a cardboard
% container to calculate the volume of the container and provides output

% Asking for the dimensions
height = input("Please enter the height of the container: ");
depth = input("Please enter the depth of the container: ");
length = input("Please enter the length of the container: ");

% Calculating the volume 
volume = height * depth * length;

% Printing the volume 
fprintf("The volume of the container with height %d, depth %d and length %d is %d\n", height, depth, length, volume);
