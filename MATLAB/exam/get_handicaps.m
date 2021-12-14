function handicaps = get_handicaps(times_array)
    handicaps = [];
    fastestTime = times_array(1);
    
    for i = 1:length(times_array)
        if(times_array(i) < fastestTime)
            fastestTime = times_array(i);
        end
    end
    
    for i = 1:length(times_array)
        handicaps(i) = times_array(i) - fastestTime;
    end
end