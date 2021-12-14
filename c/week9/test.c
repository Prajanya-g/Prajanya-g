
/*#include<stdio.h>

// main function
int main(void){
    int vals[10];
    int peaks[4];
    int index = 0;
    
    for (int i = 0; i < 10; i++){
        scanf("%d", &vals[i]);
    }
    
    for (int i = 1; i < 9; i++){
        if(vals[i] > vals[i-1] && vals[i] > vals[i+1]){
            peaks[index++]  = vals[i];
        }
    }
    for (int j = 0; j < index; j++){
        printf("%d", peaks[j]);
    }
}
*/





/*
#include <stdio.h>

int main(void)
{
    int positions[] = {7, 8, 2, 3};
    int len = 4;
    int sumdiffs[4];
    
    for (int i = 0; i < len; i++) {
        sumdiffs[i] = 0;
        for (int j = 0; j < len; j++) {
            int diff = positions[i] - positions[j];
            if (diff < 0) {
                diff = -diff;
            }
            sumdiffs[i] = sumdiffs[i] + diff;
        }
    }
    
    printf("sumdiffs: { ");
    for (int i = 0; i < len; i++) {
        printf("%d ", sumdiffs[i]);
    }
    printf("}\n");
    
    return 0;
}
*/

#include <stdio.h>

int main(void)
{
    int numbers[5] = {1,2,3,4,5};
    numbers = numbers + 1;
    for (int i = 0; i < 5; i++) {
      printf("%d",numbers[i]);
    }
    }
