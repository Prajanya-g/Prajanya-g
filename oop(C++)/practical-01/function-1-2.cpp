# include<iostream>

// the function calculates the average of the number in the array
// the function return the avergae
// the function has two parameters the array and its length
double average(int array[], int n){
    // declaring a vairable to hold the value and a variable to hold the sum
    double avg = 0.0;
    float sum = 0.0;
    // if the length of hte array is less than 1 return 0
    if (n<1){
        return 0;
    }

    //for loop to itereate throught each element of the array
    for (int index=0; index<n;index++){
        //adding each element to the sum
        sum += array[index];
    }
    // calculating the average
    avg = sum / n;
    return avg;
}