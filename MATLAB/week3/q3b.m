% @Author (Prajanya Gupta)
% @Date (18/03/2021)

% The code reads the given years and determine if they are a leap year by
% checking divisibilty by 4 and stores those years in a new vector 

% Declaring a vector with years 
years = [2142 112 201 204 3126];
% Declaring an empty vector to store leap years
leapYears = [];

% Using a loop to check all the year
for i = 1 : length(years)
    % Checking if the year is divisible by 4 
    if(mod(years(i),4) == 0)
        % Apending in the new vector if conditions met 
        leapYears = [leapYears, years(i)]; 
    end
end

% displaying the output 
disp(leapYears)
