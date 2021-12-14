# include<iostream>

int max_integer(int integers[], int length){
    int max = 0;
    if (length < 1){
        return -1;
    }
    for(int index = 0; index < length; index++){
        if(integers[index] > max){
            max = integers[index];
        }
    }
    return max;
}

int min_integer(int integers[], int length){
    int min = integers[0];
    if (length < 1){
        return -1;
    }
    for(int index = 0; index < length; index++){
        if(integers[index] < min){
            min = integers[index];
        }
    }
    return min;
}

int sum_min_and_max(int integers[], int length){
    if (length < 1){
        return -1;
    }
    int max = max_integer(integers,length);
    int min = min_integer(integers,length);
    int sum = max + min;
    return sum;
}
