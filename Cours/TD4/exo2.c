#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>



struct CelluleD {
    int val;
    struct CelluleD *next;
    struct CelluleD *prev;
};

struct File {
    struct CelluleD *head;
    struct CelluleD *tail;
};



void enfiler(struct File *f, int val);
int defiler(struct File *f);
struct File creerFile();
int estFileVide(struct File f);
int head(struct File f);
void clearFile(struct File *f);
int compter(struct File f);
float moyenne(struct File f);



int main() {
    struct File f = creerFile();
    int mesure;
    
    printf("Saisissez des mesures (entiers positifs)\n");
    printf("Saisissez -1 pour arrêter le programme\n\n");
    
    while (1) {
        printf("Entrez une mesure : ");
        scanf("%d", &mesure);
        
        if (mesure == -1) {
            printf("Arrêt du programme\n");
            break;
        }
        
        if (mesure < 0) {
            printf("Veuillez saisir un entier positif\n");
            continue;
        }
        
        int nbElements = compter(f);
        
        if (nbElements >= 5) {
            defiler(&f);
        }
        
        enfiler(&f, mesure);
        
        nbElements = compter(f);
        float moyenne = calculerMoyenne(f);
        
        printf("Mesure %d ajoutee - File: %d elements - Moyenne: %.2f\n\n", mesure, nbElements, moyenne);
    }
    
    clearFile(&f);
    return 0;
}



void enfiler(struct File *f, int val) {
    struct CelluleD *newCel = malloc(sizeof(struct CelluleD));
    newCel->val = val; 
    if (f->head == NULL) {
        newCel->prev = NULL;
        newCel->next = NULL;
        f->head = newCel;
        f->tail = newCel;
    } else {
        newCel->prev = f->tail;
        newCel->next = NULL;
        f->tail->next = newCel;
        f->tail = newCel;
    }
}

int defiler(struct File *f) {
    if (f->head == NULL) {
        return -1;
    }

    int val = f->head->val;
    struct CelluleD *oldCel = f->head;
    
    if (f->head == f->tail) {
        f->head = NULL;
        f->tail = NULL;
    } else {
        f->head = f->head->next;
        f->head->prev = NULL;
    }

    free(oldCel);
    return val;
}

struct File creerFile() {
    struct File f = {NULL, NULL};
    return f;
}

int estFileVide(struct File f) {
    return f.head == NULL;
}

int head(struct File f) {
    if (estFileVide(f)) return -1;
    return f.head->val;
}

void clearFile(struct File *f) {
    while (!estFileVide(*f)) {
        defiler(f);
    }
}

int compter(struct File f) {
    int nb = 0;
    struct CelluleD *current = f.head;
    
    while (current != NULL) {
        nb++;
        current = current->next;
    }
    
    return nb;
}

float moyenne(struct File f) {
    if (estFileVide(f)) return 0.0;
    
    float somme = 0.0;
    int nb = 0;
    struct CelluleD *current = f.head;
    
    while (current != NULL) {
        somme += current->val;
        nb++;
        current = current->next;
    }
    
    return somme / nb;
}