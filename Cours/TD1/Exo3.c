#include <stdio.h> // inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h> // inclusion de la bibliothèque pour le rand
#include <time.h>

int main() {
    srand(time(NULL));
    int nbr_rand = (rand() % 100) +1;
    int tentative = 0;
    int nbr_test;
    do {
        printf("Devinez le nombre : \n");
        scanf("%d", &nbr_test);
        if (nbr_test == nbr_rand) {
            printf("Bravo vous avez réussi, le nombre était : %d", nbr_test);
        }
        if (nbr_test > nbr_rand) {
            printf("Inférieur \n");
        }
        if (nbr_test < nbr_rand) {
            printf("Supérieur \n");
        }
        tentative++;
    } while (nbr_test != nbr_rand);
    return 0;
}