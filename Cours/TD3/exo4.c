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

void reverse(struct ListeD *l) {
    if (l->head == NULL) {
        return;
    }
    
    struct Cellule *current = l->head;
    struct Cellule *temp = NULL;
    
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    temp = l->head;
    l->head = l->tail;
    l->tail = temp;
}

void printForward(struct ListeD l) {
    printf("Liste à l'endroit: ");
    for (struct Cellule *c = l.head; c != NULL; c = c->next) {
        printf("%d ", c->val);
    }
    printf("\n");
}

void printBackward(struct ListeD l) {
    printf("Liste à l'envers: ");
    for (struct Cellule *c = l.tail; c != NULL; c = c->prev) {
        printf("%d ", c->val);
    }
    printf("\n");
}

int main() {
    // Initialisation de la liste
    struct ListeD maListe = {NULL, NULL};
    
    printf("Test de la fonction reverse\n\n");
    
    // Ajout d'éléments
    printf("Création de la liste avec les valeurs: 1, 2, 3, 4, 5\n");
    append(&maListe, 1);
    append(&maListe, 2);
    append(&maListe, 3);
    append(&maListe, 4);
    append(&maListe, 5);
    
    printf("Liste initiale:\n");
    printForward(maListe);
    printBackward(maListe);
    printf("Head: %d, Tail: %d\n\n", head(&maListe), tail(&maListe));
    
    // Premier reverse
    printf("Première inversion\n");
    reverse(&maListe);
    printf("Après 1ère inversion:\n");
    printForward(maListe);
    printBackward(maListe);
    printf("Head: %d, Tail: %d\n\n", head(&maListe), tail(&maListe));
    
    // Deuxième reverse
    printf("Deuxième inversion\n");
    reverse(&maListe);
    printf("Après 2ème inversion:\n");
    printForward(maListe);
    printBackward(maListe);
    printf("Head: %d, Tail: %d\n\n", head(&maListe), tail(&maListe));
    
    // Test avec une liste à un élément
    printf("Test avec une liste à un élément\n");
    struct ListeD listeSingle = {NULL, NULL};
    append(&listeSingle, 42);
    printf("Avant inversion:");
    printForward(listeSingle);
    printBackward(listeSingle);
    reverse(&listeSingle);
    printf("Après inversion:");
    printForward(listeSingle);
    printBackward(listeSingle);
    
    // Test avec une liste vide
    printf("\nTest avec une liste vide\n");
    struct ListeD listeVide = {NULL, NULL};
    printf("Avant inversion:");
    printForward(listeVide);
    printBackward(listeVide);
    reverse(&listeVide);
    printf("Après inversion:");
    printForward(listeVide);
    printBackward(listeVide);
    
    return 0;
}