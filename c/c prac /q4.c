# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int valid_enrolment(char ** enrolment, int num_enrolled, char * course){
    int valid = 1;
    for(int i  = 0; i < num_enrolled; i++){
        if(strcmp(enrolment[i],course) == 0){
            valid = 0;
            break;
        }
    }
    return valid;
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
        printf("course %d: ", i);
        scanf("%[^'\n']", word);
        scanf("%*c");
        course[i] = word;
        confirm = valid_enrolment(current_enrolment1, 3, course[i]);
        if(confirm == 1){
            printf("Can Enrol\n");
        }
        else{
            printf("Invalid Enrolment!\N");
        }
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



