% The code read n numbers fromt the user and stores it in a vector and 
% displays in numbers from the ends inwards form 

% asking for the total number of inputs 
totalNum = input("How many numbers will you enter?: ");

% taking inputs and storing 
for i = [1 : totalNum]
    num(i) = input("Enter a number: ");
end

% printing in inwards form 
% printing if even numbers 
if (mod(totalNum,2) == 0) 
    for i = [1 : totalNum/2]
        disp(num(totalNum+1-i)); 
        disp(num(i));
    end
% printing if odd numbers 
else
    for i = [1 : totalNum/2]
        disp(num(totalNum+1-i)); 
        disp(num(i));
    end
    disp(num((totalNum+1)/2));
end

    

    