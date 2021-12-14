% The function count the number of loops needed to change the size of 
% the image by simulating the change in loops
% The function has three the change in size, the max change that can take 
% place in loop and the resize type i.e. decreasing or increasing.
% the function return the number of loops

function[loopNum] = loopCounter(changeSize, maxChange, resizeType)
    % default loopNum is 1
    loopNum = 1;
    
    % The loopNum will be 1 if the size to change is less than limit but is
    % it is greater than multiple loop will be there
    if (changeSize > maxChange)
        % declaring a variable that works as a switch to close loop
        loopSwitch = 1;
        
        while (loopSwitch ~= 0)
            % in a loop we can only change limited size so calucating the 
            % new changesize after subtracting limit
            changeSize = changeSize - maxChange;
            % checking if the size is increase of decrease
            if(resizeType == "increase")
                maxChange = maxChange*2;
            elseif(resizeType == "decrease")
                % half changes as the size decreases
                maxChange = round(maxChange/2);
            end
            % checking if the amount is less than max change size then close
            % loop
            
            if (changeSize < maxChange)
                % counting the loops needed
                loopNum = loopNum + 1;
                loopSwitch = 0;
            else
                % counting the loops needed
                loopNum = loopNum + 1;
            end
        end
    end
end