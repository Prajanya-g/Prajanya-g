#include <stdio.h>
#include <stdlib.h>

int values_under_100(int* array, int len, int** under_100){
    int counter = 0;
    for(int index=0; index<len; index++){
        if (array[index] < 100){
            counter++;
        }
    }
    int* tmp = malloc(sizeof(int) * counter);
    
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] < 100) {
            tmp[index] = array[i];
            index++;
        }
    }
    
    *under_100 = tmp;
    
    return counter;
}

int main(void){
    int size = 1;
    int* values = malloc(sizeof(int)*size);
    
    int count = 0;
    printf("please enter the numbers. To stop entering please enter -1\n");
    printf("Enter a number: ");
    scanf("%d", &values[count]);
    while(values[count] != -1){
        size++;
        int* temp = malloc(sizeof(int)*size);
        for(int index = 0; index < size; index++){
            temp[index] = values[index];
        }
        printf("Enter a number: ");
        scanf("%d", &temp[count+1]);
        count++;
        free(values);
        values = temp;
    }
    printf("values = { ");
    for(int index = 0; index < size-1; index++){
        printf("%d ",values[index]);
    }
    printf("}\n");
    
    // call the function
    int * under_100_array;
    int counter = values_under_100(values, size-1, &under_100_array);
    
    printf("There are %d values under 100\n", counter);
    
    printf("The values less than 100 were: ");
    for (int i = 0; i < counter; i++) {
        printf("%d ", under_100_array[i]);
    }
    printf("\n");
    
    free(values);
    free(under_100_array);
    
    return 0;
}
