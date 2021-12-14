# include<iostream>

// the function calcualtes the sum of two arrays of the sam size
// the function returns the sum
// the function has three parameter the two array and the length
int sumtwo(int array[], int secondarray[], int n){
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
        sum += secondarray[index];
    }
    return sum;
}