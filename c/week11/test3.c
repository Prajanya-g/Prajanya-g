# include<stdio.h>
# include<stdlib.h>


int main(void){
    int nums = 5;
    int* num = &nums;
    printf("%d\n",nums);
    printf("%d\n",*num);
    printf("%p\n",num);
    printf("%p\n",&nums);
   
    int stat[] = {11,2,23,4,521,612,7};
    int* point = &stat[0];
    for(int i =0; i<7;i++){
        scanf("%d", point + i );
        printf("stat: %d\n",stat[i]);
        printf("point: %d\n",*point + i);
        printf("%p\n",point + i );
        printf("%p\n",&stat[i]);
    }
}


