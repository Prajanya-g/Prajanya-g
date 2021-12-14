# include<stdio.h>

int main(void){

char firstName[256];
    char lastName[256];
char studentId[10];
int year = 0;

printf("Enter the student first name: ");
scanf("%255s %255s", firstName, lastName);
scanf("%*[^'\n']");
scanf("%*c");
printf("Enter the id for %s: ", firstName);
scanf("%s9", studentId);
scanf("%*[^'\n']");
scanf("%*c");
printf("Enter the year of study for %s: ", firstName);
scanf("%d", &year);
scanf("%*[^'\n']");
scanf("%*c");

    printf("Student info for year %d:\n", year);
    printf("name: %s %s\n", firstName, lastName);
    printf("id: %s\n", studentId);
}
