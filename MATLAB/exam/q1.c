# include<stdio.h>

int main(void){
    
    char firstName[256];
    char lastName[256];
    int age;
    printf("Enter the name and age of the runner: ");
    scanf("%255s %255s %d", firstName, lastName, &age);
    scanf("%*[^'\n']");
    scanf("%*c");
    
    printf("Runner: %s %s %d\n",  firstName, lastName, age);
    
    return 0;
}
