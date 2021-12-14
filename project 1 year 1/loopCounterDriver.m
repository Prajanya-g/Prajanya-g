% driver for loopCounter 

% input vector
input1 = [500,400,400,390];
input2 = [100,300,400,200];
input3 = ["increase","decrease","increase","decrease"];

% expected output
output = [3,2,1,6];

%loop over inputs
for i = [1:length(input1)]
    % recieved output
    loopNum = loopCounter(input1(i), input2(i), input3(i));
    fprintf("expected loops: %d\n got: %d\n",output(i), loopNum);
end

