# include<stdio.h>
# include<stdlib.h>

int main(void){
    // declaring length and allocating memory
    double len = 5;
    double* numbers = malloc(sizeof(double)*len);
    if(numbers == NULL){
        printf("error memory allocation");
        return -1;
    }
    double sum = 0;
    // for loop to take input
    for (int index = 0; index < len; index++){
        printf("Enter the %dth number: ", index);
        scanf("%lf", &numbers[index]);
        // adding all the values to calculate average
        sum = sum + numbers[index];
    }
    // calculating avergae and printing value
    double average = sum / len;
    printf("average: %.2lf\n", average);
    free(numbers);
    return 0;
}
