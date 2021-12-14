# include<iostream>

// the function checks if the array is in a ascending order
// the function return true if the array is in asscending order and false if not
// there are two parameter the array and its length
bool ascending(int array[], int n){
    // declaring vairable
    bool a = false;
    if(n<1){
        return false;
    }
    // using a for loop to iterate through each array
    for(int index = 0; index < n-1; index++){
        if(array[index] <= array[index+1]){
            a = true;
        }
        else{
            a = false;
            break;
        }
    }
    return a;
}