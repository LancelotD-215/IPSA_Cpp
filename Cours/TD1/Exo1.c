#include <stdio.h>

//Exo 1

int main() {
    printf("entre ce que tu veux :\n");
    int nbr;
    nbr = -1;
    while (nbr < 0) {
        scanf("%d", &nbr);
        if (nbr < 0) {
            printf("entrer un nombre valide");
        }
    }
    return 0;
}


int max2(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}