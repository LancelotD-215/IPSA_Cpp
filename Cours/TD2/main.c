#include <stdio.h>

struct Bulletin {
    float maths[3];
    float physique[3];
    float informatique[3];
};

struct Etudiant {
    char nom[30];
    char prenom[30];
    int numero_etu;
    struct Bulletin bulletin;
    float moyenne;
};

// déclaration de prototypes
float calculermoyenneTableau(float *tab, int taille);
void traiterNotes(struct Etudiant *e);
void afficherResultats(struct Etudiant *e);

void ajouterEtudiant(struct Etudiant promotion[], int *nbEtudiants);
void afficherPromotion(struct Etudiant promotion[], int nbEtudiants);
void rechercherMajor(struct Etudiant promotion[], int nbEtudiants);
void miseAJourDossier(struct Etudiant promotion[], int nbEtudiants);
void supprimerEtudiant(struct Etudiant promotion[], int *nbEtudiants);

int main() {
    struct Etudiant promotion[500];
    int nbEtudiants = 0;
    int choix;
    
    printf("Veuillez rentrer l'option voulue\n");
    printf("1 - Ajouter un étudiant \n");
    printf("2 - Afficher la promotion \n");
    printf("3 - Rechercher le Major d'une matière \n");
    printf("4 - Mise à jour d'un dossier \n");
    printf("5 - Supprimer un étudiant \n");
    printf("6 - Quitter \n");
    scanf("%d", &choix);
    
    switch (choix) {
        case 1:
            ajouterEtudiant(promotion, &nbEtudiants);
            break;
        
        case 2:
            afficherPromotion(promotion, nbEtudiants);
            break;

        case 3:
            rechercherMajor(promotion, nbEtudiants);
            break;

        case 4:
            miseAJourDossier(promotion, nbEtudiants);
            break;

        case 5:
            supprimerEtudiant(promotion, &nbEtudiants);
            break;

        case 6:
            break;

        default:
            printf("Option inconnue\n");
            break;
    }
    return 0;
}


float calculermoyenneTableau(float *tab, int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme/taille;
}

void traiterNotes(struct Etudiant *e) {
    float somme = 0;
    somme += calculermoyenneTableau(e->bulletin.maths, 3);
    somme += calculermoyenneTableau(e->bulletin.physique, 3);
    somme += calculermoyenneTableau(e->bulletin.informatique, 3);
    e->moyenne = somme/3;  // Stocker la moyenne dans la structure
}

void afficherResultats(struct Etudiant *e) {
    printf("Nom: %s", e->nom);
    printf("Prenom: %s", e->prenom);
    printf("Numero etudiant: %d", e->numero_etu);
    
    printf("Mathematiques: ");
    for (int i = 0; i < 3; i++) {
        printf("%f", e->bulletin.maths[i]);
    }
    printf("(Moyenne maths: %f)", calculermoyenneTableau(e->bulletin.maths, 3));
    
    printf("Physique: ");
    for (int i = 0; i < 3; i++) {
        printf("%f", e->bulletin.physique[i]);
    }
    printf("(Moyenne physique: %f)", calculermoyenneTableau(e->bulletin.physique, 3));
    
    printf("Informatique: ");
    for (int i = 0; i < 3; i++) {
        printf("%f", e->bulletin.informatique[i]);
    }
    printf("(Moyenne informatique : %.2f)", calculermoyenneTableau(e->bulletin.informatique, 3));
    
    printf("Général: ");
    printf("Moyenne generale: %.2f", e->moyenne);
}


void ajouterEtudiant(struct Etudiant promotion[], int *nbEtudiants) {
    int n = 0;

    printf("Veuillez entrer le nombre d'étudiants à ajouter: ");
    scanf("%d", &n);
        
    for (int i = 0; i < n; i++) {
        printf("\nÉtudiant %d/%d\n", i + 1, n);

        printf("Nom: ");
        scanf("%s", promotion[*nbEtudiants].nom);
        
        printf("Prénom: ");
        scanf("%s", promotion[*nbEtudiants].prenom);
        
        printf("Numéro étudiant: ");
        scanf("%d", &promotion[*nbEtudiants].numero_etu);
        
        printf("Notes de mathématiques: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &promotion[*nbEtudiants].bulletin.maths[j]);
        }
        
        printf("Notes de physique: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &promotion[*nbEtudiants].bulletin.physique[j]);
        }
        
        printf("Notes d'informatique: ");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &promotion[*nbEtudiants].bulletin.informatique[j]);
        }
        
        traiterNotes(&promotion[*nbEtudiants]);
        
        (*nbEtudiants)++;
    }
}
