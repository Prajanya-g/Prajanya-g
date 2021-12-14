

# include<stdio.h>
# include<stdlib.h>

int main(void){
    int totalRunner = 0;
    printf("How many runners competed? ");
    scanf("%d", &totalRunner);
    scanf("%*c");
    float* time = malloc(sizeof(float)*totalRunner);
    
    for(int index = 0; index < totalRunner; index++){
        printf("Enter the time for runner %d ", index+1);
        scanf("%f", &time[index]);
        scanf("%*c");
    }
    float fastestTime = time[1];
    int fastestRunner = 1;
    float slowestTime = 0;
    int slowestRunner = 0;
    
    for (int index = 0; index < totalRunner; index++){
        if(time[index] < fastestTime){
            fastestTime = time[index];
            fastestRunner = index+1;
        }
        if(time[index] > slowestTime){
            slowestTime = time[index];
            slowestRunner = index+1;
        }
    }

    
    printf("The fastest runner was runner %d with a time of %.2f\n",fastestRunner,fastestTime);
    printf("The slowest runner was runner %d with a time of %.2f\n",slowestRunner, slowestTime);
    
    printf("The race times were:  ");
    for(int index = 0; index < totalRunner; index++){
        printf("%.2f ",time[index]);
    }
    printf("\n");
    
    free(time);
    return 0;
}

