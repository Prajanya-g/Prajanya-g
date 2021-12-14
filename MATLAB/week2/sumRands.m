% @Title (sum of random numbers)
% @Author (Prajanya Gupta)
% @Date (10/03/2021)

% The code generated 5 random numbers between 1 to 10 and display their sum

randNum = 0;
sumNum = 0; 

% generating 5 random numbers and adding them 
for i = [1:5]
  randNum = round(rand()*9.0)+1; 
  fprintf("%d", randNum);
  sumNum = sumNum + randNum;
end

% Printing sum
fprintf("Sum of 5 random intergers between 1 to 10 is %d\n", sumNum)