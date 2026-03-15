#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>


struct CelluleD {
    char *intitule;
    int priorite;
    struct CelluleD *next;
    struct CelluleD *prev;
};

struct FAP {
    struct CelluleD *head;
    struct CelluleD *tail;
};


void enfiler(struct FAP *p, char *intitule, int priorite) {
    struct CelluleD *newCel = malloc(sizeof(struct CelluleD));
    newCel->intitule = intitule;
    newCel->priorite = priorite;
    if (p->head == NULL) {
        newCel->prev = NULL;
        newCel->next = NULL;
        p->head = newCel;
        p->tail = newCel;
    } else {
        struct CelluleD *current = p->head;
        
        while (current != NULL && current->priorite <= priorite) {
            current = current->next;
        }
        
        if (current == NULL) {
            newCel->prev = p->tail;
            newCel->next = NULL;
            p->tail->next = newCel;
            p->tail = newCel;
        } else if (current->prev == NULL) {
            newCel->prev = NULL;
            newCel->next = p->head;
            p->head->prev = newCel;
            p->head = newCel;
        } else {
            newCel->prev = current->prev;
            newCel->next = current;
            current->prev->next = newCel;
            current->prev = newCel;
        }
    }
}

struct CelluleD* defiler(struct FAP *p) {
    if (p->head == NULL) {
        return NULL;
    }

    struct CelluleD *oldCel = p->head;
    
    if (p->head == p->tail) {
        p->head = NULL;
        p->tail = NULL;
    } else {
        p->head = p->head->next;
        p->head->prev = NULL;
    }

    oldCel->next = NULL;
    oldCel->prev = NULL;
    return oldCel;
}

struct FAP creerFAP() {
    struct FAP f = {NULL, NULL};
    return f;
}

int estFAPVide(struct FAP f) {
    return f.head == NULL;
}

struct CelluleD* head(struct FAP f) {
    if (estFAPVide(f)) return NULL;
    return f.head;
}

void clearFAP(struct FAP *f) {
    while (!estFAPVide(*f)) {
        struct CelluleD *cellule = defiler(f);
        if (cellule != NULL) {
            free(cellule);
        }
    }
}

void traiterAlertes(struct FAP *p) {
    while (!estFAPVide(*p)) {
        struct CelluleD *current = defiler(p);
        if (current != NULL) {
            printf("%s\n", current->intitule);
            free(current);
        }
    }
}

int main() {
    struct FAP f = creerFAP();
    
    enfiler(&f, "B : Mise à jour météo disponible", 5);
    enfiler(&f, "C : Température moteur élevée", 2);
    enfiler(&f, "A : Niveau de carburant bas", 1);
        
    traiterAlertes(&f);
        
    enfiler(&f, "Test alerte 1", 2);
    enfiler(&f, "Test alerte 2", 2);
    
    traiterAlertes(&f);
    
    return 0;
}