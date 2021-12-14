totalRaces  = input("How many races were held?  ");
totalRunner = input("How many runners competed in each race? ");
time = [totalRaces,totalRunner];

for row =1 : totalRaces
    fprintf("Entering the times for race %d\n", row)
    for col = 1:totalRunner
        fprintf("Enter the time for runner %d",col)
        time(row,col) = input(": ");
    end
end

fastestTime = zeros(totalRaces,1);
fastestRunner = zeros(totalRaces,1);
slowestTime = zeros(totalRaces,1);
SlowestRunner = zeros(totalRaces,1);
for i = 1:totalRaces
    fastestTime(i,1) = time(i,1);
    slowestTime(i,1) = time(i,1);
    fastestRunner(i,1) = 1;
    slowestRunner(i,1) = 1;
end

for row =1 : totalRaces
    for col = 1:totalRunner
        if(time(row,col) < fastestTime(row,1))
        fastestTime(row,1) = time(row,col);
        fastestRunner(row,1) = col;
    end
     if(time(row,col) > slowestTime(row,1))
        slowestTime(row,1) = time(row,col);
        slowestRunner(row,1) = col;
    end
    end
end

for i = 1:totalRaces
   fprintf("The fastest runner for race %d was runner %d with a time of %.2f\n",i,fastestRunner(i,1),fastestTime(i,1));
   fprintf("The slowest runner for race %d was runner %d with a time of %.2f\n",i,slowestRunner(i,1), slowestTime(i,1)); 
end

for row = 1: totalRaces
fprintf("The race times for race %d were ", row);
for col = 1:totalRunner
    fprintf("%.2f ", time(row,col));
end
fprintf("\n")
end

handicaps = get_all_handicaps(time)
for row = 1: totalRaces
fprintf("\nThe handicaps for race %d are: ", row);
for col = 1:totalRunner
    fprintf("%.2f ",handicaps(row,col));
end
end