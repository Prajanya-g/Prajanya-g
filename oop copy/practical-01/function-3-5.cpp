# include<iostream>

// the function calculate the sum of the number on een places
// the function returns the sum
// there are two parameter array and its length

double sumeven(double array[], int n){
    //declaring the variable
    double sum;
    //
    if(n<1){
    return 0;
}
    for(int index = 0; index < n; index++){
        sum += array[index];
        // adding one to index to jump two spaces to the next even number
        index++;
    }
    return sum;
}
