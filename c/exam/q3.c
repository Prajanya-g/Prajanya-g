# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int main(void){
    int numberCourses = 0;
    printf("How many courses do you want to enrol in? ");
    scanf("%d", &numberCourses);
    scanf("%*c");
    int check[numberCourses];
    char ** course = malloc(sizeof(char*)*numberCourses);
    for (int i =0; i < numberCourses; i++){
        char * word = malloc(sizeof(char)*10);
        printf("course %d(WITHOUT SPACE): ", i);
        scanf("%[^\n]", word);
        scanf("%*c");
        course[i] = word;
        if(strcmp(word,"ENG 1002") == 0||strcmp(word,"ENG 1003") == 0){
            check[i] = 1;
        }
        else{
            check[i]=0;
        }
    }
    for (int i = 0; i < numberCourses; i++){
        printf("course %d: ", i);
    if(check[i] == 1){
        printf("programming\n");
    }
    else{
        printf("not programming\n");
    }
    }
    
}

