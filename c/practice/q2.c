# include<stdio.h>

int main(void){
    int length = 10;
    char dnaSequence[length];
    int guanine = 0;
    int adenine = 0;
    int cytosine = 0;
    int thymine = 0;
    for(int index = 0; index < length; index++){
        printf("Please enter the input: ");
        scanf("%c%*c", &dnaSequence[index]);
        while(dnaSequence[index] != 'G' && dnaSequence[index] != 'A' && dnaSequence[index] != 'T' && dnaSequence[index] != 'C' ){
            printf("Please enter a correct input: ");
            scanf("%c%*c", &dnaSequence[index]);
        }
        if(dnaSequence[index] == 'G'){
            guanine++;
        }
        else if(dnaSequence[index] == 'A'){
            adenine++;
        }
        else if(dnaSequence[index] == 'T'){
            thymine++;
        }
        else{
            cytosine++;
        }
    }
    printf("Sequence \n");
    for (int index=0; index < length; index++) {
        printf("%c", dnaSequence[index]);
    }
    printf("\n");
    printf("%d guanine\n", guanine);
    printf("%d adenine\n",adenine);
    printf("%d cytosine\n", cytosine);
    printf("%d thymine\n", thymine);
}

