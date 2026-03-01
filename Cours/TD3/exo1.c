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
        cons(l, val);
        return;
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

int search(struct Liste l, int val_search) {
    int val_return = -1;
    for (struct Cellule *c = l.head; c != NULL; c = c->next) {
        if (c->val == val_search) {
            return c->val;
        }
    }
    return -1;
}

void removeL(struct Liste *l, int val_remove) {
    struct Cellule *adresse_prev = NULL;
    for (struct Cellule *c = l->head; c != NULL; c = c->next) {
        if (c->val == val_remove) {
            if (c == l->head) {
                l->head = l->head->next;
            } else {
                adresse_prev->next = c->next;
            }
            free(c);
            return;
        }
        adresse_prev = c;
    }
}

int main() {
    // Créer une liste vide
    struct Liste maListe = {NULL};
    
    printf("Liste vide - isEmpty: %d, length: %d\n", isEmpty(maListe), length(maListe));
    
    // Ajouter des éléments
    cons(&maListe, 10);
    cons(&maListe, 20);
    append(&maListe, 5);
    
    printf("Après ajouts - length: %d, head: %d\n", length(maListe), head(&maListe));
    
    // Test search
    printf("search(20): %d, search(99): %d\n", search(maListe, 20), search(maListe, 99));
    
    // Test remove
    removeL(&maListe, 20);
    printf("Après remove(20) - length: %d, head: %d\n", length(maListe), head(&maListe));
    
    return 0;
}

