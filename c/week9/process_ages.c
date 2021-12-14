//
//  process_ages.c
//  The code takes in 10 ages from user between 0 to 150 and calucates the maximum, minmum and average of the ages. If user wants to enter less number -1 can be used to mark the end
//
//  Created by Prajanya Gupta on 013/05/21.
//

# include<stdio.h>

int main(void){
    // declaring variables
    int ages[10];
    int max = 0;
    int min = 150;
    float sum = 0;
    int index = 0;
    // using for loop to take input an process data
    for(int i = 0; i < 10; i++){
        printf("Please enter %dth number: ", i);
        scanf("%d", &ages[i]);
        // askign for input if negative or greater than 150
        while(ages[i] > 150 || ages[i] < -1){
            printf("Wrong input.Please enter %dth number: ", i);
            scanf("%d", &ages[i]);
        }
        // ending if the user enter -1
        if (ages[i] == -1){
            break;
        }
        
        // checking if the number entered is greater than current max
        if(max < ages[i]){
            max = ages[i];
        }
        // checking if the number entered is less then current min
        if(min > ages[i]){
            min = ages[i];
        }
        // calculating sum
        sum = sum + ages[i];
        index++;
    }
    
    // computing average
    float avg = sum/index;
    
    // print values. if no number enter seprate message is displayed
    if(ages[0] == -1){
        printf("no number entered so no maximum, no minmum and no average\n");
    }else{
        printf("maximum: %d\n", max);
        printf("minimum: %d\n",min);
        printf("average: %.2f\n", avg);
    }
}
