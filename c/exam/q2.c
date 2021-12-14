# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int main(void){
    int numberCourses = 0;
    int check =0;
    printf("How many courses do you want to enrol in? ");
    scanf("%d", &numberCourses);
    scanf("%*c");
    char ** course = malloc(sizeof(char*)*numberCourses);
    for (int i =0; i < numberCourses; i++){
        char * word = malloc(sizeof(char)*10);
        printf("course %d: ", i);
        scanf("%[^'\n']", word);
        scanf("%*c");
        course[i] = word;
        printf("%s", word);
        if(strcmp(word,"ENG 1002") == 0||strcmp(word,"ENG 1003") == 0){
            check = 1;
        }
    }
    if(check == 1){
        printf("Awesome! You are enrolled in programming. \n");
    }
    else{
        printf("Awwww, no programming for you. \n");
    }
}
