# include<iostream>

// the function counts the number of even number between the 1 and the giern number
// the function returns the total count
// the function has one parameter the last number
int count_even(int number){
    // declaring the count variable
    int count = 0;
        if(number<1){
        return 0;
    }

    for(int n = 0; n < number; n++){
     if(n%2 == 0){
             count++;
         }
     }
     return count;
}
