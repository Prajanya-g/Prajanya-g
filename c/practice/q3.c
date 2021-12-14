# include<stdio.h>
# include<stdlib.h>
char  * remove_nucleotide(char * dna_sequence, char nucleotide, int sequence_length){
    int lengthCount = 0;
    for (int index = 0; index < sequence_length; index++) {
        if(dna_sequence[index] != nucleotide){
            lengthCount++;
        }
    }
    char *tempSequence = malloc(sizeof(char)*lengthCount);
    int count = 0;
    for (int index = 0; index < sequence_length; index++) {
        if(dna_sequence[index] != nucleotide){
            tempSequence[count] = dna_sequence[index];
            count ++;
        }
    }
    return tempSequence;
}

int main(void){
    int length = 10;
    char nucleotide;
    char* dnaSequence = malloc(sizeof(char)*length);
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
    
    printf("Which nucleotide do you want to remove: ");
    scanf("%c%*c", &nucleotide);
    while(nucleotide != 'G' && nucleotide != 'A' && nucleotide != 'T' && nucleotide != 'C' ){
        printf("Please enter a correct input: ");
        scanf("%c%*c", &nucleotide);
    }
    
    dnaSequence = remove_nucleotide(dnaSequence, nucleotide, length);
    
    if(nucleotide == 'G'){
        length = length - guanine;
        guanine = 0;
    }
    else if(nucleotide == 'A'){
        length = length - adenine;
        adenine = 0;
    }
    else if(nucleotide == 'T'){
        length = length  - thymine;
        thymine = 0;
    }
    else{
        length = length - cytosine;
        cytosine = 0;
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
    free(dnaSequence);
}


