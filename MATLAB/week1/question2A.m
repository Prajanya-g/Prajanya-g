% @Title (Total daily water use in city)
% @Author (Prajanya Gupta)
% @Date (04/03/2021)

% The code use data about mean household size and their daily water usage
% along with the population size of a city provided by the user to
% calculate the total water consumption of the city in kiloliters and
% prints the out for the user.

% Asking for the population of the city
population = input("Please enter the population of a city");

% Assigning values to constant variables based on data collect from the
% internet about the mean household size and their daily water usage.
avg_daily_water_usage = 1.135;
avg_household_size = 3.1;

% Calculating the total daily water usage by the city
total_water_usage_in_city = population / avg_household_size * avg_daily_water_usage;

% Printing the total daily water usage by the city
fprintf(" %d\n  %d\n", population, total_water_usage_in_city);
