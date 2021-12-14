% @Title (Total cost of travel)
% @Author (Prajanya Gupta)
% @Date (05/03/2021)

% The code uses data like avg distance driven by an individual and the
% cost of fuel(assuming it is the only cost involved and a vehicle travels 13km 
% in a liter)and population to calculate the total cost of travel for the 
% poupulation and provides output

% Asking for the population
population = input("Please enter the population of a city: ");

% Assigning values to constant variables
avg_distance_driven = 40;
cost_fuel_1km = 1.328 / 13;
% Assuming that there are people under 18 and old citizens
driving_population = population * 90/100;

% Calculating the cost of driving for a single peson 
cost_driving_pp = avg_distance_driven * cost_fuel_1km;

% Calculating the total cost of travel daily
cost_whole_city = cost_driving_pp * driving_population;

% Printing the values 
fprintf("A person pays $%.2f at an average daily for travel.\n", cost_driving_pp);
fprintf("Then, in a city with driving population of %d ",driving_population);
fprintf("the total cost of travel for the whole city is %.2f\n", cost_whole_city);

