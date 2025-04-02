#include "quotes.h"

int nb_quotes = MAX_QUOTES;

int main() {
    char *quotes[] = {
        "Programmer - An organism that turns caffeine into code",
        "Why do programmers prefer dark mode? Because light attracts bugs.",
        "If debugging is the process of removing software bugs, then programming must be the process of putting them in.",
        "I don't always test my code, but when I do, I do it in production.",
        "Why do programmers always mix up Christmas and Halloween? Because Oct 31 == Dec 25!",
        "Why did the programmer quit his job? Because he didn't get arrays.",
        "Why do programmers prefer iOS development? Because the Swift.",
        "Why do programmers prefer dogs over cats? Because dogs have fetch and cats have catch.",
        "Why do programmers hate nature? It has too many bugs.",
        "There are only 10 types of people in the world: Those who understand binary and those who don't."
    };
    char **dynamic_quotes = NULL;
    create_tab(&dynamic_quotes,quotes);
    int running = 1;
    int num;
    while(running) {
        printf("\n1. Afficher toutes les citations\n"
               "2. Afficher une citation\n"
               "3. Afficher une citation au hasard\n"
               "4. Ajouter une citation\n"
               "5. Enlever une citation\n"
               "6. Fermer le programme\n"
               "Saisissez le numero de l'action souhaitee\n");
        scanf(" %d", &num);
        while (getchar() != '\n');
        switch(num) {
            case 1:
                print_all_quotes(&dynamic_quotes, &nb_quotes);
                break;
            case 2:
                int index;
                printf("Saisir le numero de citation a afficher");
                scanf("%d", &index);
                print_quote(dynamic_quotes,index);
                break;
            case 3:
                print_random_quote(dynamic_quotes);
                break;
            case 4:
                add_quotes(&dynamic_quotes, &nb_quotes);
                break;
            case 5:
                remove_quotes(&dynamic_quotes, &nb_quotes);
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Numero invalide.");

        }
    }
}