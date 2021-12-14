a =[];
whileSwitch = 0;
reference = 0;
innercount = 1;
whileSwitch = 0;
innercount = 0; 
    while(whileSwitch == 0)
        out = randi([1 6],[1 2 1]);
        sum = out(1,2) + out(1,1);
        innercount = innercount + 1;
        if(innercount == 1)
            if (sum == 7 || sum == 11)
                a = [a,1];
                whileSwitch = 1;
                printf("win1");
            elseif(sum == 2 || sum == 3 || sum == 12)
                a = [a,0];
                whileSwitch = 1;
                printf("lose1");
            else
                reference = sum;
            end
        else
            if(reference == sum)
                a = [a,1];
                whileSwitch = 1;
                printf("win");
            elseif(sum == 2 || sum == 3 || sum == 12)
                a = [a,0];
                printf("lose");
            end
        end
    end
