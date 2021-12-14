# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int valid_enrolment(char ** enrolment, int num_enrolled, char * course){
    
}

int main(void){
    int numberCourses = 0;
    char * current_enrolment1[3] = {"ENG 1002", "MATHS 1", "PHYSICS 2"};
    printf("How many courses do you want to enrol in? ");
    scanf("%d", &numberCourses);
    scanf("%*c");
    int check[numberCourses];
    char ** course = malloc(sizeof(char*)*numberCourses);
    for (int i =0; i < numberCourses; i++){
        int confirm = 0;
        char * word = malloc(sizeof(char)*10);
        printf("course %d(WITHOUT SPACE): ", i);
        scanf("%10s", word);
        scanf("%*[^'\n']");
        scanf("%*c");
        course[i] = word;
        confirm = valid_enrolment(*current_enrolment1, numberCourses, course)
        if(confirm = 1){
            printf("Can Enrol");
        }
        else{
            printf("Invalid Enrolment!");
        }
        if(strcmp(word,"ENG1002") == 0||strcmp(word,"ENG1003") == 0){
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


