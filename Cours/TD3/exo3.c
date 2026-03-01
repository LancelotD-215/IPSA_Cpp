#include <stdio.h> // librairie standard d'entrée/sortie
#include <stdlib.h> // librairie standard de gestion de la mémoire

struct Cellule {
    int val;
    struct Cellule *next;
    struct Cellule *prev;
};

struct ListeD {
    struct Cellule *head;
    struct Cellule *tail;
};

int isEmpty(struct ListeD l) {
    return l.head == NULL;
}

int length(struct ListeD l) {
    int taille = 0;
    for (struct Cellule *c = l.head; c != NULL; c = c->next) {
        taille++;
    }
    return taille;
}

void cons(struct ListeD *l, int val) {
    if (isEmpty(*l)) {
        struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
        nouvelleCellule->val = val;
        nouvelleCellule->next = NULL;
        nouvelleCellule->prev = NULL;
        l->head = nouvelleCellule;
        l->tail = nouvelleCellule;
    } else {
        struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
        nouvelleCellule->val = val;
        nouvelleCellule->next = l->head;
        nouvelleCellule->prev = NULL;
        l->head->prev = nouvelleCellule;
        l->head = nouvelleCellule;
    }
}

int head(struct ListeD *l) {
    if (l->head == NULL) {
        return -1;
    }
    return l->head->val;
}

int tail(struct ListeD *l) {
    if (l->tail == NULL) {
        return -1;
    }
    return l->tail->val;
}

void append(struct ListeD *l, int val) {
    if (l->head == NULL) {
        cons(l, val);
        return;
    }
    
    struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
    nouvelleCellule->val = val;
    nouvelleCellule->next = NULL;
    nouvelleCellule->prev = l->tail;
    l->tail->next = nouvelleCellule;
    l->tail = nouvelleCellule;
}

void insertSorted(struct ListeD *l, int val) {
    if (l->head == NULL) {
        cons(l, val);
        return;
    }
    for (struct Cellule *c = l->head; c != NULL; c = c->next) {
        if (c->val >= val) {
            struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
            nouvelleCellule->val = val;
            nouvelleCellule->next = c;
            nouvelleCellule->prev = c->prev;
            if (c->prev != NULL) {
                c->prev->next = nouvelleCellule;
            } else {
                l->head = nouvelleCellule;
            }
            c->prev = nouvelleCellule;
            return;
        }
    }
    append(l, val);
}

struct ListeD merge(struct ListeD l1, struct ListeD l2) {
    struct ListeD nouvelle = {NULL, NULL};
    
    for (struct Cellule *c = l1.head; c != NULL; c = c->next) {
        insertSorted(&nouvelle, c->val);
    }
    
    for (struct Cellule *c = l2.head; c != NULL; c = c->next) {
        insertSorted(&nouvelle, c->val);
    }
    
    return nouvelle;
}

void printList(struct ListeD l) {
    printf("Liste: ");
    if (isEmpty(l)) {
        printf("(vide)");
    } else {
        for (struct Cellule *c = l.head; c != NULL; c = c->next) {
            printf("%d", c->val);
            if (c->next != NULL) {
                printf(" -> ");
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Test de insertSorted\n");
    struct ListeD liste = {NULL, NULL}; // Initialisation liste vide
    
    printList(liste);
    
    printf("\nInsertion des valeurs: 50, 10, 30, 70, 20, 5, 100\n");
    insertSorted(&liste, 50);    
    insertSorted(&liste, 10);
    insertSorted(&liste, 30);
    insertSorted(&liste, 70);
    insertSorted(&liste, 20);
    insertSorted(&liste, 5);
    insertSorted(&liste, 100);
    
    printf("Liste 1 triée: ");
    printList(liste);
    printf("Taille de la liste 1: %d\n", length(liste));
    
    printf("\nTest de merge\n");
    // Création d'une deuxième liste triée
    struct ListeD liste2 = {NULL, NULL};
    
    printf("Création de la liste 2 avec: 15, 25, 60, 5, 90\n");
    insertSorted(&liste2, 15);
    insertSorted(&liste2, 25);
    insertSorted(&liste2, 60);
    insertSorted(&liste2, 80);
    insertSorted(&liste2, 90);
    
    printf("Liste 2 triée: ");
    printList(liste2);
    printf("Taille de la liste 2: %d\n", length(liste2));
    
    // Fusion des deux listes
    struct ListeD listeFusionnee = merge(liste, liste2);
    
    printf("Liste fusionnée: ");
    printList(listeFusionnee);
    printf("Taille de la liste fusionnée: %d\n", length(listeFusionnee));
    
    return 0;
}
