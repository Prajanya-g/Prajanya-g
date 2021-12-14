# include<stdio.h>

int main(void){
    int length = 10;
    char dnaSequence[length];
    for(int index = 0; index < length; index++){
        printf("Please enter the input: ");
        scanf("%c%*c", &dnaSequence[index]);
        while(dnaSequence[index] != 'G' && dnaSequence[index] != 'A' && dnaSequence[index] != 'T' && dnaSequence[index] != 'C' ){
            printf("Please enter a correct input: ");
            scanf("%c%*c", &dnaSequence[index]);
        }
    }
    printf("Sequence \n");
    for (int index=0; index < length; index++) {
        printf("%c", dnaSequence[index]);
    }
    printf("\n");
}
