# include<stdio.h>
# include<stdlib.h>

char ** remove_nucleotides(char ** sequences, char * nucleotides, int number_of_sequences, int DNA_length){
    int newLength[number_of_sequences];
    for(int row = 0; row < number_of_sequences; row++){
        for(int col = 0; col < DNA_length; col++){
          
        }
    }
}


int main(void){
    int length = 10;
    int guanine = 0;
    int adenine = 0;
    int cytosine = 0;
    int thymine = 0;
    int totalSequences;
    printf("how many sequences do you want to enter: ");
    scanf("%d%*c", &totalSequences);
    char** dnaSequence = malloc(sizeof(char*)*totalSequences);
    
    for(int row = 0; row < totalSequences; row++){
        dnaSequence[row] = malloc(sizeof(char)*length);
        for(int col = 0; col < length; col++){
            printf("Please enter the input for %d %d: ", row, col);
            scanf("%c%*c", &dnaSequence[row][col]);
            while(dnaSequence[row][col] != 'G' && dnaSequence[row][col] != 'A' && dnaSequence[row][col] != 'T' && dnaSequence[row][col] != 'C' ){
                printf("Please enter a correct input: ");
                scanf("%c%*c", &dnaSequence[row][col]);
            }
            if(dnaSequence[row][col] == 'G'){
                guanine++;
            }
            else if(dnaSequence[row][col] == 'A'){
                adenine++;
            }
            else if(dnaSequence[row][col] == 'T'){
                thymine++;
            }
            else{
                cytosine++;
            }
        }
    }
    

    
    
    printf("Sequence \n");
    for(int row = 0; row < totalSequences; row++){
        for(int col = 0; col < length; col++){
        printf("%c", dnaSequence[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%d guanine\n", guanine);
    printf("%d adenine\n",adenine);
    printf("%d cytosine\n", cytosine);
    printf("%d thymine\n", thymine);
}



