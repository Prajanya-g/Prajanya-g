# include<iostream>

int maximum_sum(int *nums,int length){
    int max = *nums;
    for (int i = 0; i < length; i++) {
        int subLen = 1;
        for (int j = i ; j < length; j++) {
            int storage[subLen];
            int sum = 0;
            for (int k = 0; k < subLen; k++) {
                storage[k] = *(nums+i+k);
                sum += storage[k];
            }
            if(sum > max){
                max = sum;
            }
            subLen++;
        }
    }
    if(max < 0){
        return 0;
    }
    return max;
}


)
