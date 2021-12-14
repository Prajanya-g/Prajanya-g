# include<stdio.h>
# include<stdlib.h>

int values_under_100(int* values, int size){
    int count = 0;
    for(int index=0; index<size; index++){
        if (values[index] < 100){
            count++;
        }
    }
    return count;
}



int main(void) {

    int values[6]={-1,200,4,5,-3,600};
    int size=6;

    // call the function
    int count = values_under_100(values, size);
    
    printf("There are %d values under 100\n", count);

    return 0;
}

/*
 #include <stdio.h>
 #include <stdlib.h>

 int values_under_100(int* array, int len, int** under_100)
 {
     int counter = 0;
     for (int i = 0; i < len; i++) {
         if (array[i] < 100) {
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
 int main(void)
 {

     // looking for a sentinel value
     int limit = 5, size = 0;
     int* values = malloc(sizeof(int) * limit);
     
     printf("Enter a number or enter -1 to stop: ");
     scanf("%d", &values[size]);
     
     while (values[size] != -1) {
         size++;
         if (size == limit) {
             limit = limit * 2;
             int* tmp = malloc(sizeof(int) * limit);
             for (int i = 0; i < size; i++) {
                 tmp[i] = values[i];
             }
             free(values);
             values = tmp;
         }
         printf("Enter a number or enter -1 to stop: ");
         scanf("%d", &values[size]);
     }

     // asking for the number of values
         int size;
         printf("How many values do you want to enter: ");
         scanf("%d", &size);
         
         int* values = malloc(sizeof(int) * size);
         if (values == NULL) {
             printf("Memory Allocation Error\n");
             return -1;
         }
         
         for (int i = 0; i < size; i++) {
             printf("Enter a number: ");
             scanf("%d", &values[i]);
         }
         
         printf("values = { ");
         for (int i = 0; i < size; i++) {
             printf("%d ", values[i]);
         }
         printf("}\n");
         
         // call the function
         int* under_100_array;
         int count = values_under_100(values, size, &under_100_array);
         
         printf("There are %d values under 100\n", count);
         
         printf("The values less than 100 were: ");
         for (int i = 0; i < count; i++) {
             printf("%d ", under_100_array[i]);
         }
         printf("\n");
         
         free(values);
         free(under_100_array);
         
         return 0;
     }

*/
