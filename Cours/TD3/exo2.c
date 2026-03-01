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

void printBackward(struct ListeD l) {
    printf("Liste à l'envers: ");
    for (struct Cellule *c = l.tail; c != NULL; c = c->prev) {
        printf("%d ", c->val);
    }
    printf("\n");
}

int main() {
    // Créer une liste doublement chaînée vide
    struct ListeD maListeD = {NULL, NULL};
        
    // Test liste vide
    printf("Liste vide - isEmpty: %d, length: %d, head: %d, tail: %d\n", 
           isEmpty(maListeD), length(maListeD), head(&maListeD), tail(&maListeD));
    
    // Test cons (ajout au début)
    cons(&maListeD, 10);
    printf("Après cons(10) - length: %d, head: %d, tail: %d\n", 
           length(maListeD), head(&maListeD), tail(&maListeD));
    
    cons(&maListeD, 20);
    printf("Après cons(20) - length: %d, head: %d, tail: %d\n", 
           length(maListeD), head(&maListeD), tail(&maListeD));
    
    // Test append (ajout à la fin)
    append(&maListeD, 5);
    printf("Après append(5) - length: %d, head: %d, tail: %d\n", 
           length(maListeD), head(&maListeD), tail(&maListeD));
    
    append(&maListeD, 30);
    printf("Après append(30) - length: %d, head: %d, tail: %d\n", 
           length(maListeD), head(&maListeD), tail(&maListeD));
    
    // Test printBackward
    printf("Liste du début à la fin (parcours normal): ");
    for (struct Cellule *c = maListeD.head; c != NULL; c = c->next) {
        printf("%d ", c->val);
    }
    printf("\n");
    
    printBackward(maListeD);
        
    return 0;
}