/*# include<stdio.h>
# include<stdlib.h>
int main(void){
    int length = 10;
    char characters[length];
    char spaces;
    for(int i = 0; i < length; i++){
        scanf("%c", &characters[i]);
        scanf("%c", &spaces);
        if(!(characters[i] >= 'a' && characters[i] <= 'z') && !(characters[i] >= 'A' && characters[i] <= 'Z')){
            length = i;
            break;
        }
    }
    for(int i = 0; i < length; i++){
        printf("%c", characters[i]);
    }
}*/
# include<stdio.h>
# include<stdlib.h>
int main(void){
    int length = 5;
    char characters[length];
    for(int i = 0; i < length; i++){
        printf("Please enter char ");
        scanf("%c%*c", &characters[i]);
       
        if(!(characters[i] >= 'a' && characters[i] <= 'z') && !(characters[i] >= 'A' && characters[i] <= 'Z')){
            length = i;
            break;
        }
    }
    for(int i = length; i >= 0; i--){
        printf("%c", characters[i]);
    }
}



