 // quotes.c
#include "quotes.h"

void print_quote(char ** quotes, int index) {
    printf("%s\n", quotes[index-1]);
}

void print_random_quote(char ** quotes) {
    srand(time(NULL));
    int index = rand() % MAX_QUOTES;
    print_quote(quotes, index);
}


void create_tab(char *** tab, char **tab2) {
    *tab = (char**) malloc(MAX_QUOTES * sizeof(char*));
    if (*tab == NULL) {
        printf("Echec allocation de memoir.\n");
        exit(1);
    }
    for (int i = 0; i < MAX_QUOTES; i++) {
        int length = strlen(tab2[i]);
        (*tab)[i] = (char*) malloc((length+1)*sizeof(char));
        if ((*tab)[i] == NULL) {
            printf("Echec allocation de memoir.\n");
            exit(1);
        }
        strcpy((*tab)[i], tab2[i]);
    }
}

void add_quotes(char *** tab, int * nb_quotes) {
    char quote[100];
    *tab = (char**) realloc(*tab, (*nb_quotes + 1) * sizeof(char*));
    printf("Saisir une nouvelle citation :\n");
    fgets(quote, 100, stdin);
    if (strlen(quote) > 0 && quote[strlen(quote) - 1] == '\n') {
        quote[strlen(quote) - 1] = '\0';
    }
    (*tab)[*nb_quotes] = (char*) malloc((strlen(quote)+1) * sizeof(char));
    strcpy((*tab)[*nb_quotes],quote);
    (*nb_quotes) ++;
}

void remove_quotes(char *** tab, int * nb_quotes) {
    int index;
    for (int i = 0; i < *nb_quotes; i++) {
        printf("%d. %s\n", i+1,(*tab)[i]);
    }
    printf("Quelle citation voulez-vous supprimer? Saisissez son numero :\n");
    scanf("%d", &index);
    for (int i = index-1; i < *nb_quotes-1; i++) {
        strcpy((*tab)[i], (*tab)[i+1]);
    }
    free((*tab)[*nb_quotes-1]);
    *tab =  (char**) realloc(*tab, (*nb_quotes-1) * sizeof(char*));
    (*nb_quotes) --;
}

void print_all_quotes(char *** tab, int * nb_quotes) {
    for (int i = 0; i < *nb_quotes; i++) {
        printf("%s\n", (*tab)[i]);
    }
}