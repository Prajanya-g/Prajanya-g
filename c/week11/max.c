# include<stdio.h>
# include<stdlib.h>

double maximum(double* nums, int length){
    double max = nums[0];
    for (int index=0; index<length; index++){
        if (max < nums[index]){
            max = nums[index];
        }
    }
    return max;
}

int main(void){
    int length = 10;
    double* nums = malloc(sizeof(double)*length);
    if(nums == NULL){
        printf("error memory allocation");
        return -1;
    }
    for(int index=0; index<length; index++){
        printf("Please enter the %dth number: ",index);
        scanf("%lf", &nums[index]);
    }
    double max = maximum(nums, length);
    printf("Maximum is %.2lf\n",max);
    free(nums);
    return 0;
}
