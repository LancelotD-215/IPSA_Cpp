#include <stdio.h> // librairie standard d'entrée/sortie
#include <stdlib.h> // librairie standard de gestion de la mémoire

struct Cellule {
    int val;
    struct Cellule *next;
};

struct Liste {
    struct Cellule *head;
};

int isEmpty(struct Liste l) {
    return l.head == NULL;
}

int length(struct Liste l) {
    int taille = 0;
    for (struct Cellule *c = l.head; c != NULL; c = c->next) {
        taille++;
    }
    return taille;
}

void cons(struct Liste *l, int val) {
    struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
    nouvelleCellule->val = val;
    nouvelleCellule->next = l->head;
    l->head = nouvelleCellule;
}

int head(struct Liste *l) {
    if (l->head == NULL) {
        return -1;
    }
    return l->head->val;
}

void append(struct Liste *l, int val) {
    if (l->head == NULL) {
        return -1;
    }
    
    struct Cellule *last = l->head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
    nouvelleCellule->val = val;
    nouvelleCellule->next = NULL;  // C'est la dernière !
    
    last->next = nouvelleCellule;
}