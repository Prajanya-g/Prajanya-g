function handicaps = get_all_handicaps(times)
    handicaps = zeros(size(times,1),size(times,2))
    fastestTime = [];
    for i = 1:size(times,1)
        fastestTime(i) = times(i,1);
    end
    
    for row = 1:size(times,1)
        for col = 1:size(times,2)
            if(times(row,col) < fastestTime(row))
                fastestTime(row) = times(row,col);
            end
        end
    end
    
    for row = 1:size(times,1)
        
        for col = 1:size(times,2)
            temp(row,col) = times(row,col) - fastestTime(row);
        end
       
    end
   
   end