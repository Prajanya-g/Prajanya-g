# include<stdio.h>

int main(void){
    int length = 11;
    char dnaSequence[length];
    int g = 0;
    int a = 0;
    int t = 0;
    int c = 0;
    printf("Enter the sequence:  ");
    scanf("%10s", dnaSequence);
    scanf("%[^'\n']");
    scanf("%*c");
    int count = 0;
    while(dnaSequence[count] != '\0'){
        count++;
    }
    length = count;
    for(int index = 0; index < length; index++){
        while(dnaSequence[index] != 'G' && dnaSequence[index] != 'A' && dnaSequence[index] != 'T' && dnaSequence[index] != 'C'){
            printf("wrong input enter element %d again", index);
            scanf("%c%*c", &dnaSequence[index]);
        }
        if(dnaSequence[index] == 'G'){
            g++;
        }
        else if (dnaSequence[index] == 'T') {
            t++;
        }
        else if(dnaSequence[index] == 'C'){
            c++;
        }
        else {
            a++;
        }
    }
    printf("sequence: \n%s \n%d \n%d \n%d \n%d \n",dnaSequence, g,t,c,a);
}


