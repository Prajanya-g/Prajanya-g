/*
#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int length){
    for (int index = 0; index < length; index++){
        printf("%d ", array[index]);
    }
}

int main(void)
{
    int array[] = {1, 2, 3, 4};
    int length = 4;
    print_array(array, length);
    return 0;

}
*/

#include <stdio.h>
#include <stdlib.h>
int* make_zeros(int rows){
    int* zeroArray = malloc(sizeof(int)*rows);
    for(int index = 0; index < rows; index++){
        zeroArray[index] = 0;
    }
    return zeroArray;
}
int main(void){
    int rows = 0;
    scanf("%d",&rows);
    int* zeroArray;
    zeroArray = make_zeros(rows);
    if(zeroArray == NULL){
        printf("couldn't copy array\n");
        return 1;
    }
    // test
      for(int i=0;i<rows;i++){
        printf("%d\n", zeroArray[i]);
      }
    return 0;
    free(zeroArray);
    
}


