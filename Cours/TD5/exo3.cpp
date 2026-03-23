#include <string>
#include <iostream>
using namespace std;

void afficherTableau(int tableau[]) {
    int i = 0;
    while (tableau[i] != -1)  {
        cout << "|" << tableau[i];
        i++;
    }
    cout << "|" << endl;
}

int* nombreVersTableau(int nb) {
    int compt = 0;
    int temp = nb;
    while (temp != 0) {
        temp /= 10;
        compt++;
    }
    int *newTab = new int[compt +1];
    for (int i=0; i<compt; i++) {
        newTab[i] = nb % 10;
        nb /= 10;
    }
    newTab[compt] = -1;
    return newTab;
}

int estPalindrome(int nb) {
    int *tab = nombreVersTableau(nb);
    int longueur = 0;
    while (tab[longueur] != -1) {
        longueur++;
    }
    
    for (int i = 0; i < longueur / 2; i++) {
        if (tab[i] != tab[longueur - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int* additionerTableaux(int nb1[], int nb2[]) {
    int longueur1 = 0, longueur2 = 0;
    while (nb1[longueur1] != -1) longueur1++;
    while (nb2[longueur2] != -1) longueur2++;
    int maxLong = (longueur1 > longueur2) ? longueur1 : longueur2;
    int *resultat = new int[maxLong + 2];
    
    int retenue = 0;
    int i = 0;
    
    while (i < maxLong || retenue > 0) {
        int chiffre1 = (i < longueur1) ? nb1[i] : 0;
        int chiffre2 = (i < longueur2) ? nb2[i] : 0;
        
        int somme = chiffre1 + chiffre2 + retenue;
        resultat[i] = somme % 10;
        retenue = somme / 10;
        i++;
    }
    resultat[i] = -1;
    return resultat;
}

int main() {
    int *tab = nombreVersTableau(509480);
    afficherTableau(tab);
    delete[] tab;
    return 0;
}

