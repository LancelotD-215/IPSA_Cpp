#include <stdio.h>
#include <stdlib.h>

struct Cellule {
    int val;
    struct Cellule *suivant;
};

struct Liste {
    struct Cellule *head;
};


int isEmpty(struct Liste l) {
    return l.head == NULL;
}

int length(struct Liste l) {
    int taille = 0;
    for (struct Cellule *c = l.head; c != NULL; c = c->suivant) {
        taille++;
    }
    return taille;
}

void clear(struct Liste *l) {
    struct Cellule *curr = l->head;
    while (curr != NULL) {
        struct Cellule *temp = curr;
        curr = curr->suivant; // On libère l'ancienne cellule
        free(temp);
    }
    l->head = NULL;
}