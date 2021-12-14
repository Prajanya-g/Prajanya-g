# include<iostream>

// the function checks whether the given array is a fan array or not
// the function return true and afalse based on the check
// there are two parameter the array and it length
bool fanarray(int array[], int n){
    //declaring variable
    bool fan = false;
    // false if the sequence has less than 1 n
    if(n<1){
    return false;
}
    // checkign if there are odd number of element or even number of elements in the array
    if(n%2 == 0){
        for(int index = 0; index<(n/2)-1; index++){
            // checking if half the sequence is ascending
            if(array[index]<=array[index+1]){
                fan = true;
            }
            else{
                fan = false;
                return fan;
            }
        }
        // checking if half the sequence is descending
        for(int index = n/2; index<n-1; index++){
            if(array[index]>=array[index+1]){
                fan = true;
            }
            else{
                fan = false;
                return fan;
            }
        }
        // the middle two number should match
        if(array[n/2] != array[(n/2)-1]){
            fan = false;
            return fan;
        }
    }
    else{
        for(int index = 0; index < (n-1)/2; index++){
            // checking if half the sequence is ascending
            if(array[index]<=array[index+1]){
                fan = true;
            }
            else{
                fan = false;
                return fan;
            }
        }
        // checking if half the sequence is descending
        for(int index = (n-1)/2; index<n-1; index++){
            if(array[index]>=array[index+1]){
                fan = true;
            }
            else{
                fan = false;
                return fan;
            }
        }
    }
  

    return fan;
}
