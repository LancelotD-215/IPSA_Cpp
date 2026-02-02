#include <stdio.h>

int len(char *message) {
    int longueur = 0;
    while (message[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

char* cpy(char *source, char *destination) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

int palindrome(char *sequence) {
    int i = 0;
    int longueur = len(sequence);
    while (i < longueur/2) {
        if (sequence[i] != sequence[longueur-1-i]) {
            return 0;
        }
        i++;
    }
    return 1;
}