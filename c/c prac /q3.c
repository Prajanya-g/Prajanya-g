# include<stdio.h>
# include<stdlib.h>
# include<string.h>

int main(void){
    int numberCourse = 0;
    printf("how many course do you want to enrol in?");
    scanf("%d", &numberCourse);
    scanf("%*c");
    char** courses = malloc(sizeof(char*)*numberCourse);
    int check[numberCourse];
    for(int i = 0; i < numberCourse; i++){
        printf("Course %d", i);
        char* courseName = malloc(sizeof(char)*10);
        scanf("%[^'\n']", courseName);
        scanf("%*c");
        courses[i] = courseName;
        if(strcmp(courseName,"ENG 1002") == 0||strcmp(courseName,"ENG 1003") == 0){
               check[i] = 1;
        }
        else{
            check[i] = 0;
        }
    }
    for(int i = 0; i < numberCourse; i++){
        printf("%s", courses[i]);
        if(check[i] == 0){
            printf("not enrolled");
        }
        else{
            printf("Awesome! You are enrolled in programming.");
        }
    }
}

