#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** prepend(char **, char *, int);

int main(void) {

/* Prompts the user for a number of strings to enter */
    int string_count;
    printf("How many strings do you want to enter? ");
    scanf("%d", &string_count);

/* Prompts for the strings.
stores the string as an array of characters
Each string of no more than 256 characters. */

    char ** words = malloc(string_count * sizeof(char *));

    char next_word[257];
    for (int r=0; r<string_count; r++) {
        printf("Enter next string: ");
        scanf("%256s%*[^\n]",next_word);
        words[r] = malloc((strlen(next_word)+1) * sizeof(char));
        strcpy(words[r], next_word);
    }

/* asks the user for a prefix string */
    printf("Enter the prefix string: ");
    char prefix[257];
    scanf("%256s%*[^\n]", prefix);

/* Calls a function (to be written) which takes the array of strings, words, and a second string, prefix,
creates a new array that holds a copy of the original strings with prefix pre-pended (ie added at the front) of the strings in the words array.
returns this new array */

    char ** pre_pended_array = prepend(words, prefix, string_count);

    for(int r=0; r<string_count; r++) {
    /* for(c=0; pre_pended_array[r][c] != '\0'; c++) {
        printf("%c ",pre_pended_array[r][c]);
    } */
        printf("%s\n", pre_pended_array[r]);
    }

    // free pre_pended_array memory
    for (int r=0; r<string_count; r++) {
        free(pre_pended_array[r]);
    }
    free(pre_pended_array);

    return 0;
}

char ** prepend(char ** old_strings, char * prefix, int number_of_strings) {
    char ** new_strings = malloc(number_of_strings * sizeof(char *));
    for (int r=0; r<number_of_strings; r++) {
        // *    helloworld
        char * prepended_string = malloc ((strlen(old_strings[r])+strlen(prefix)+1) * sizeof(char));
        strcpy(prepended_string, prefix);
        strcat(prepended_string, old_strings[r]);
        new_strings[r] = prepended_string;
    }

    return new_strings;
}
