# include<iostream>

bool is_a_palindrome(int integers[], int length){
    bool check = false;
    if (length < 1){
        check = false;
        return check;
    }
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

int sum_elements(int integers[], int length){
    int sum = 0;
    if (length < 1){
        return -1;
    }
    for(int index = 0; index < length; index++){
        sum += integers[index];
    }
    return sum;
}

int sum_if_a_palindrome(int integers[], int length){
    bool check  = is_a_palindrome(integers, length);
    if (length < 1){
        return -1;
    }
    if(check == false){
        return -2;
    }
    int sum = sum_elements(integers, length);
    return sum;
    
}
