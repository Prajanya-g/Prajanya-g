% @Title (height vector)
% @Author (Prajanya Gupta)
% @Date (10/03/2021)

% The code read in height at stores the in a vector and display them

% Creating an empty vector
height = [];

% Taking input 
for i = 1:5
   height(i) = input("Please enter height: "); 
end

% displaying the values 
disp (height'); 