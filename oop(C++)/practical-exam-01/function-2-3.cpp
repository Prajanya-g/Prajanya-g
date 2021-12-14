# include<iostream>

int sum_elements(int integers[], int length){
    if (length < 1){
        return -1;
    }
    int sum = 0;
    for(int index = 0; index < length; index++){
        sum += integers[index];
    }
    return sum;
}

bool is_a_palindrome(int integers[], int length){
    if (length < 1){
        return -1;
    }
    bool check = false;
    if (length%2 == 0){
        int firstHalf[length/2];
        int secondHalf[length/2];
        for(int index = 0; index < length/2; index++){
            firstHalf[index] = integers[index];
        }
        for(int index = length/2; index < length; index++){
            secondHalf[index-(length/2)] = integers[index];
        }
        for(int index = 0; index < length/2; index++){
            if(firstHalf[index] == secondHalf[(length/2) - index - 1]){
                check = true;
            }
            else{
                check = false;
                return check;
            }
        }
    }
    else{
        int firstHalf[(length+1)/2];
        int secondHalf[(length+1)/2];
        for(int index = 0; index < (length+1)/2; index++){
            firstHalf[index] = integers[index];
        }
        for(int index = (length-1)/2; index < length; index++){
            secondHalf[index - (length-1)/2] = integers[index];
        }
        for(int index = 0; index < (length+1)/2; index++){
            if(firstHalf[index] == secondHalf[((length+1)/2) -index-1]){
                check = true;
            }
            else{
                check = false;
                return check;
            }
        }
    }
    return check;
}


int sum_if_a_palindrome(int integers[], int length){
    if (length < 1){
        return -1;
    }
    int number = 0;
    bool check  = is_a_palindrome(integers, length);
    if(check == false){
        return -2;
    }
    else{
    number = sum_elements(integers, length);
    }
    return number;
    
}
