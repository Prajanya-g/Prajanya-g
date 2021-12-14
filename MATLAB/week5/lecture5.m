a = [6 ,4, 8, 7, 3]
i = length(a);
index = 0;
while(i >= 1)
    if mod(a(i),3)==0
        index = i;
    end
    i = i - 1;
end

