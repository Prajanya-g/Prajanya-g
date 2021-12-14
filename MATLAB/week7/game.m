% declaring variables including vector to store data
reference = 0;
win = [];
iterations = 1000000;
rolls = [];
% running the code several number of times
for i =[1:iterations]
    % creating a switch for the while loop and a counter to count rolls
    whileSwitch = 0;
    count = 0; 
    % using while loop to run till the game ends 
    while(whileSwitch == 0)
        % creating 2 unbiased dice that randomly gives a number
        out = randi([1 6],[1 2 1]);
        % calculating the sum and countign the roll
        sumOfRoll = out(1,2) + out(1,1);
        count = count + 1;
        % the condition in first roll is different than other rolls
        if(count == 1)
            % adding 1 to win or 0 or reference point according to the conditions
            if(sumOfRoll == 7 || sumOfRoll == 11)
                win = [win,1];
                whileSwitch = 1;
            elseif(sumOfRoll == 2 || sumOfRoll == 3 || sumOfRoll == 12)
                win = [win,0];
                whileSwitch = 1;
            else
                reference = sumOfRoll;
            end
        else
            % adding 1 to win or 0 according to the conditions
            if(reference == sumOfRoll)
                win = [win,1];
                whileSwitch = 1;
            elseif(sumOfRoll == 7)
                win = [win,0];
                whileSwitch = 1;
            end
        end
    end
    % adding number of rolls taken 
    rolls = [rolls, count];
end
% calulating average or the probability
average = sum(rolls)/length(rolls);
prob = sum(win)/iterations;
fprintf("The probabilty of a win: %f",prob);
fprintf("The average rolls taken: %f",average);