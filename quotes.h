// quotes.h
#ifndef QUOTES_H
#define QUOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUOTES 10

void print_quote(char ** quotes, int index);
void print_random_quote(char ** quotes);
void create_tab(char *** tab, char **tab2);
void add_quotes(char *** tab, int * nb_quotes);
void remove_quotes(char *** tab, int * nb_quotes);
#endif