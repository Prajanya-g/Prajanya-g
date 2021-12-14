#include <stdio.h>
#include <stdlib.h>

// top and bottom part of the rocket are the exactly same the triangles
void printTriangle(int height){
    for(int index=0; index<height*2; index++){
        for(int spaces=0; spaces < (height*2)-1-index;spaces++){
            printf(" ");
        }
        for(int bash=0; bash<index+1; bash++){
            printf("/");
        }
        printf("**");
        for(int bash=0; bash<index+1; bash++){
            printf("\\");
        }
        printf("\n");
    }
}
// the line seperating the two parts
void printLine(int height){
    printf("+");
    for(int index=0; index<height*2; index++){
        printf("=*");
    }
    printf("+\n");
}

// the body can be divided into two halves the function contains the top body
void printTopBody(int height){
    for(int index=height; index>0; index--){
        printf("|");
        for(int dot=0; dot<index-1; dot++){
            printf(".");
        }
        for(int arrow=0; arrow<height+1-index; arrow++){
        printf("/\\");
        }
        for(int dot=0; dot<index-1; dot++){
            printf(".");
        }
        for(int dot=0; dot<index-1; dot++){
            printf(".");
        }
        for(int arrow=0; arrow<height+1-index; arrow++){
        printf("/\\");
        }
        for(int dot=0; dot<index-1; dot++){
            printf(".");
        }
        printf("|\n");
    }
}

// the body can be divided into two halves the function contains the top body
void printBottomBody(int height){
    for(int index=0; index<height; index++){
        printf("|");
        for(int dot=0; dot<index; dot++){
            printf(".");
        }
        for(int arrow=0; arrow<height-index; arrow++){
        printf("\\/");
        }
        for(int dot=0; dot<index; dot++){
            printf(".");
        }
        for(int dot=0; dot<index; dot++){
            printf(".");
        }
        for(int arrow=0; arrow<height-index; arrow++){
        printf("\\/");
        }
        for(int dot=0; dot<index; dot++){
            printf(".");
        }
        printf("|\n");
    }
}


int main(void){
    // decalring the height variable and scanning user input
    int height = 0;
    printf("Please enter the height of the rocket: ");
    scanf("%d", &height);
    // printing the rocket of required height using the functions 
    printTriangle(height);
    printLine(height);
    printTopBody(height);
    printBottomBody(height);
    printLine(height);
    printBottomBody(height);
    printTopBody(height);
    printLine(height);
    printTriangle(height);
    return 0;
}
