# include<stdio.h>
# include<stdlib.h>

int main(void){
    int totalRaces = 0;
    printf("How many races were held? ");
    scanf("%d",&totalRaces);
    scanf("%*c");
    int* totalRunners = malloc(sizeof(int)*totalRaces);
    float** time = malloc(sizeof(float*)*totalRaces);
    for(int row = 0; row < totalRaces; row++){
        printf("How many runners competed in race %d? ", row+1);
        scanf("%d", &totalRunners[row]);
        scanf("%*c");
        float* temp = malloc(sizeof(int)*totalRunners[row]);
        for(int col = 0; col < totalRunners[row]; col++){
            printf("Enter the time for runner %d ", col+1);
            scanf("%f", &temp[col]);
            scanf("%*c");
        }
        time[row] = temp;
    }
        float* fastestTime = malloc(sizeof(float)*totalRaces);
        int* fastestRunner = malloc(sizeof(int)*totalRaces);
        float* slowestTime = malloc(sizeof(float)*totalRaces);
        int* slowestRunner = malloc(sizeof(int)*totalRaces);
        
        for(int i = 0; i< totalRaces; i++){
            fastestTime[i] = time[i][1];
            slowestTime[i] = 0;
            fastestRunner[i] = 1;
            slowestRunner[i] = 1;
        }
        
        for(int row = 0; row < totalRaces; row++){
            for (int col = 0; col < totalRunners[row]; col++){
                if(time[row][col] < fastestTime[row]){
                    fastestTime[row] = time[row][col];
                    fastestRunner[row] = col+1;
                }
                if(time[row][col] > slowestTime[row]){
                    slowestTime[row] = time[row][col];
                    slowestRunner[row] = col+1;
                }
            }
        }
        for(int row = 0; row < totalRaces; row++){
                printf("The fastest runner for race %d was runner %d with a time of %.2f\n",row+1,fastestRunner[row],fastestTime[row]);
                printf("The slowest runner for race %d was runner %d with a time of %.2f\n",row+1,fastestRunner[row],slowestTime[row]);
        }
        
    for(int row = 0; row < totalRaces; row++){
        printf("The race times for race %d were ", row+1);
        for (int col = 0; col < totalRunners[row]; col++){
            printf("%.2f ",time[row][col]);
        }
        printf("\n");
    }
    
    free(time);
    free(fastestRunner);
    free(fastestTime);
    free(slowestTime);
    free(slowestRunner);
    return 0;
    
}
