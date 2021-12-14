% the function find the minimum and the maximum value in two vectors.
% there are two parameters the two vector containing numbers 
% the function returns the min and the max from the vectors

function[min,max] = minMaxVectors(v1,v2)
    % declaring the first value of the vector1 as max and min 
    if (length(v1))
    min = v1(1);
    max = v1(1);
    
    % finding min and max in first vector 
    for i = 2:length(v1)
        % comparing current min and max  with each value 
        if (min > v1(i))
            % if smaller change the new min 
            min = v1(i);
        elseif (max < v1(i))
            % if greater change the new min
            max = v1(i);
        end
    end
    % finding min and max in second vector 
    for i = 1:length(v2)
        % comparing current min and max  with each value 
        if (min > v2(i))
            % if smaller change the new min 
            min = v2(i);
        elseif (max < v2(i))
            % if greater change the new min
            max = v2(i);
        end
    end
end