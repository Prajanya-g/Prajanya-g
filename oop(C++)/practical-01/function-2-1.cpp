# include<iostream>

// the functon find the minimum value in the array
// the function returns the minimum value
// there are two parameter the length and the array
int minimum(int array[], int n){
    // declaring the variable
    int min = array[1];
    // creating aloop to iterate through each value
        if(n<1){
        return 0;
    }

    for(int index = 0; index<n;index++){
        //comparing value
        if(array[index] < min){
            min = array[index];
        }
    }
    return min;
}