# include<iostream>

// The function calucaltes the the sum of all the elements in the array
// the function returns the total sum of each element
// the function has two parameter the array and the length of the array
int sum_array(int array[], int n){
    // decalring the sum variable to hold the total value
    int sum = 0;
    // if the length of hte array is less than 1 return 0
    if(n<1){
        return 0;
    }

    //for loop to itereate throught each element of the array
    for (int index=0; index<n;index++){
        //adding each element to the sum
        sum += array[index];
    }
    return sum;
}