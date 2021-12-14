# include<stdio.h>
# include<stdlib.h>

int count_values_between_2_5(int *values, int size){
    // declaring count variable
    int count = 0;
    // using loop to iterate throught each value
    for(int index = 0; index < size; index++){
        // if conditions are met count increase by 1
        if(values[index]>=2 && values[index]<=5){
            count++;
        }
    }
    // returning the value
    return count;
}

int main(void) {

    int values[6]={1,2,4,5,3,6};
    int size=6;

    printf("There are %d values between 2 and 5 (inclusive)\n", count_values_between_2_5(values, size));
}
