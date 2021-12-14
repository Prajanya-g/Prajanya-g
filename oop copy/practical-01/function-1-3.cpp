# include<iostream>

// the function counts the number of element similar to the number provided
// the function return the number of matches
// the function has three parameter the array the length of array and the number
int count(int array[], int n, int number){
    // declairng the count variable
    int count = 0.0;
    // if the length of hte array is less than 1 return 0
    if(n<1){
        return 0;
    }

    //for loop to itereate throught each element of the array
    for (int index=0; index<n;index++){
        if(array[index] == number){
            count++;
        }
    }
    return count;
}