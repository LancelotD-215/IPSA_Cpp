#include <stdio.h> // inclusion de la bibliothèque standard d'entrée/sortie
#define MAX 100 // définition d'une constante : souvent en MAJ

int main() {
    char lettre = 'A';
    int entier = 42;
    short petit = 10;
    long grand = 1234567890L;
    float pi = 3.14159f;

    int test;
    printf("entrez un nombre");
    scanf("%d", &test);
    printf("Vous avez entré : %d\n", test);

    return 0;
}