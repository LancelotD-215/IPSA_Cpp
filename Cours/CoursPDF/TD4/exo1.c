#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

struct Cellule {
    int val;
    struct Cellule *next;
};

struct Pile {
    struct Cellule *sommet;
};


void empiler();
int depiler();
struct Pile creerPile();
int estPileVide();
int sommet();
void clearPile();


void empiler(struct Pile *p, int val) {
    struct Cellule *nouvelleCellule = malloc(sizeof(struct Cellule));
    nouvelleCellule->val = val;
    nouvelleCellule->next = p->sommet;
    p->sommet = nouvelleCellule;
}

int depiler(struct Pile *p) {
    if (estPileVide(*p)) {
        return -1;
    } else {
        struct Cellule *ancienneCellule = p->sommet;
        p->sommet = p->sommet->next;
        int valReturn = ancienneCellule->val;
        free(ancienneCellule);
        return valReturn;
    }
}

struct Pile creerPile() {
    struct Pile p = {NULL};
    return p;
}


int estPileVide(struct Pile p) {
    return p.sommet == NULL;
}

int sommet(struct Pile p) {
    if (estPileVide(p)) return -1;
    return p.sommet->val;
}

void clearPile(struct Pile *p) {
    while (p->sommet != NULL) {
        depiler(p);
    }
}

void annulerMouvement(struct Pile *p, int n) {
    for (int i = 0; i < n; i++) {
        if (estPileVide(*p)) return;
        int valeur = depiler(p);
        printf("%d\n", valeur);
    }
}

int main() {    
    struct Pile maPile = creerPile();
    
    empiler(&maPile, 90);
    empiler(&maPile, 180);
    empiler(&maPile, 45);
    empiler(&maPile, 270);
    
    annulerMouvement(&maPile, 2);
    
    annulerMouvement(&maPile, 5);
    
    annulerMouvement(&maPile, 1);
    
    return 0;
}