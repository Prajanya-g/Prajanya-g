totalRunner = input("How many runners competed? ");
time = [totalRunner];

for i = 1:totalRunner
    fprintf("Enter the time for runner %d",i)
    time(i) = input(" : ");
end
fastestTime = time(1);
fastestRunner = 1;
slowestTime = 0;
slowestRunner = 1;
for i = 1:totalRunner
    if(time(i) < fastestTime)
        fastestTime = time(i);
        fastestRunner = i;
    end
     if(time(i) > slowestTime)
        slowestTime = time(i);
        slowestRunner = i;
    end
end

fprintf("The fastest runner was runner %d with a time of %.2f\n",fastestRunner,fastestTime);
fprintf("The slowest runner was runner %d with a time of %.2f\n",slowestRunner, slowestTime);

fprintf("The race times were:  ");
for i = 1:totalRunner
    fprintf("%.2f ", time(i));
end

fprintf("\nThe handicaps are: ");
    fprintf("%.2f ",get_handicaps(time));