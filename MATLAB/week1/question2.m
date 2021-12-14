% @Title (Total daily water use in city)
% @Author (Prajanya Gupta)
% @Date (04/03/2021)

% The code use data like mean household size, daily water usage and the 
% population provided by the user to calculate the total water consumption 
% for the city in kiloliters and provides output

% Asking for the population
population = input("Please enter the population of a city: ");

% Assigning values to constant variables based on data collect
avg_water_usage = 1.135;
avg_household_size = 3.1;

% Calculating the total daily water usage
total_water_usage = population / avg_household_size * avg_water_usage;

% Printing the total daily water usage 
fprintf("A city with %d population consumes ", population);
fprintf("%.2f kiloliter of water daily\n", total_water_usage);
