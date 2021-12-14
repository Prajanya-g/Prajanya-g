# include<stdio.h>

int main(void){
    int length = 11;
    char dnaSequence[length];
    scanf("%10s%*[^'\n']", dnaSequence);
    scanf("%*c");

    printf("%s  \n",dnaSequence);
}
