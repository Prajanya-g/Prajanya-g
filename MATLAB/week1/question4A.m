% @Title (Total cost of travel)
% @Author (Prajanya Gupta)
% @Date (05/03/2021)

% Asking for the population of the city 
population = input("Please enter the population of a city: ");

% Assigning values to constant variables based on assumptions 
driving_population = population * 90/100;
distance_driven = 10;
cost_fuel_1km = 1.328 / 13;
%calculating total cost
cost_driving = distance_driven * cost_fuel_1km;
%calaculating total cost of travel for the whole city
cost_whole_city = cost_driving * driving_population;

%printing the total cost of travel for the whole city
fprintf("%d\n %.2f\n %.2f\n", driving_population, cost_driving, cost_whole_city);

