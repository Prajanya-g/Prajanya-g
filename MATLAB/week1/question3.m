% @Title (Total daily water use in Adelaide)
% @Author (Prajanya Gupta)
% @Date (04/03/2021)

% The code use data like mean household size, daily water usage and the 
% population provided by the user to calculate the total water consumption 
% for Adelaide in kiloliters and then compares it with the capacity of the
% desalination plant's daily capacity and provides output as a percentage  

% Asking for the population
population = input("Please enter the population of adelaide: ");

% Assigning value 
daily_cap = 300000;
avg_water_usage = 1.135;
avg_household_size = 3.1;

% Calculating the total daily water usage 
total_water_usage = population / avg_household_size * avg_water_usage;

% Calculating desalination can cover of the daily water consumption.
demand_covered = daily_cap / total_water_usage * 100;

% Printing the desalination covered by the plant
fprintf("Adelaide consumes %.2f kiloliters ", total_water_usage);
fprintf("of water daily. However, the plant can ");
fprintf("cover %.2f%% of the total daily water usage.\n", demand_covered);



