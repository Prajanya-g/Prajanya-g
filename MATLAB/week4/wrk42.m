clear; 
clc;

a = [ 1 2 3 4];


for i = 1 : length(a)
    for j = 1 : length(a)
        b(i,j) = abs(a(i)-a(j));
    end
end
    
disp (b);

