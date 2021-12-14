# include<stdio.h>
# include<stdlib.h>

int main(void){
    //delcaring length and asking user for the input
    int len = 0;
    printf("How many grades to be entered: ");
    scanf("%d", &len);
    
    // allocating memory to grades based on user input
    int* grades = malloc(sizeof(int)*len);
    // checking for any memory allocation errors
    if(grades == NULL){
        printf("error memory allocation");
        return -1;
    }
    // asking user for grades
    for(int index = 0; index < len; index++){
        printf("Enter a grade: ");
        scanf("%d", &grades[index]);
        // unless the value is 100 or less than 100 a new input is asked
        while(grades[index]>100){
            printf("Invalid grade enter\n");
            printf("Enter a grade: ");
            scanf("%d", &grades[index]);
        }
    }
    // declaring a new size varibale and a null pointer
    int size = 0;
    int* passing = NULL;
    // iterating to every value and checking for passing criteria
    for(int index = 0; index < len; index++){
        if(grades[index] >= 50){
            // adding 1 to size and allocating memory to a temp pointer
            size = size + 1;
            int* temp = malloc(sizeof(int)*size);
            // checking for any memory allocation errors
            if(temp == NULL){
                printf("error memory allocation");
                return -1;
            }
            // interating throught pass and tranfering previous values to temp
            for(int i = 0; i < size-1; i++){
                temp[i] = passing[i];
            }
            // freein the memory in pass
            free(passing);
            // adding the new value to temp
            temp[size-1] = grades[index];
            // tranfering the new address to the passing pointer
            passing = temp;
        }
    }
    
    // printing values
    printf("You entered the grades: ");
    for(int index = 0; index < len; index++){
        printf("%d ",grades[index]);
    }
    printf("\n");
    printf("The passing marks are: ");
    for(int index = 0; index < size; index++){
        printf("%d ",passing[index]);
    }
    printf("\n");
    
    // freeing memory
    free(grades);
    free(passing);
    return 0;
}
