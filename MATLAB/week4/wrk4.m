clear;
clc;

% declaring the vector 
x = [ 1 2 3 4] ;
leng = length(x);

% adding 
y(1) = x(1) + x(2);
y(leng) = x(leng - 1) + x(leng);
for p = 2 : length(x)-1
    y(p) = 0; 
    sums = 0;
    for k = p-1 : p+1
        sums = sums + x(k);
    end
    y(p) = sums;
end
