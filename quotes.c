 // quotes.c
#include "quotes.h"

void print_quote(char ** quotes, int index) {
    printf("%s\n", quotes[index]);
}

void print_random_quote(char ** quotes) {
    int index = rand() % MAX_QUOTES;
    print_quote(quotes, index);
}


void create_tab(char *** tab, char **tab2) {
    *tab = (char**) malloc(MAX_QUOTES * sizeof(char*));
    if (*tab == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < MAX_QUOTES; i++) {
        int length = strlen(tab2[i]);
        (*tab)[i] = (char*) malloc((length+1)*sizeof(char));
        if ((*tab)[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        strcpy((*tab)[i], tab2[i]);
    }
}
