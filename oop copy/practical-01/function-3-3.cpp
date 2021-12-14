# include<iostream>

// the function calculates the weighted average
// the functoin returns the average
// there are two parameter the array and the length
double weightedaverage(int array[], int n){
    // decalring variable
    double avg = 0;
    // using double loops to calculate
    for (int i = 0; i < n; i++){
        double count = 0;
        for (int j = 0; j < n; j++){
            if(array[i] == array[j]){
                count++;
            }
        }
        avg = avg + array[i] * (count/n);
    }
    return avg;
}
