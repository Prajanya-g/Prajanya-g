# include<iostream>

// the function sorts the array and find the median
// the function returns the median for the array
// there are two parameters the array and the length

int median(int array[], int n){
    // declaring median variable
    int median = 0;
    if(n<1 || n%2 == 0){
    return 0;
}
    // using sequence sort to sort the array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(array[i] > array[j]){
                // switch values if a element is smaller than the current
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return array[n/2];
}
