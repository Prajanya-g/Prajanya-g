% stage 01 reading image 
clear;
clc;
% @Title: (Photo editing)
% @Author: (Prajanya Gupta)
% @version: 2.0 (03/04/2021)
% The code is a simple photo editting tool. It provied the options to crop,
% flip both horizontally and vertically, rotate, resize and increase or 
% decrease the brightness of the image and display out to the user

% welcome message
fprintf("Welcome photo editor\n\n");
fprintf("You can edit the image in the following ways:\n");
fprintf("\n ->Crop\n ->Flip\n ->Resize\n ->Rotate\n");
fprintf(" ->Adjust the brightness\n\n");
% asking the user for an image name and reading it
fprintf("Please enter the image name ");
fprintf("(it should be in the same folder as the code)");
imagename = input("\n->", 's');
imageData = imread(imagename);
