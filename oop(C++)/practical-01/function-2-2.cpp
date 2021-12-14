# include<iostream>

// the functon find the maximum value in the array
// the function returns the maximum value
// there are two parameter the length and the array
int maximum(int array[], int n){
    // declaring the variable
    int max = array[1];
    // creating aloop to iterate through each value
        if(n<1){
        return 0;
    }

    for(int index = 0; index<n;index++){
        //comparing value
        if(array[index] > max){
            max = array[index];
        }
    }
    return max;
}