#include <stdio.h>

// Exo 2

float calculerMoyenne () {
    float a, b, c;
    printf("Donner le premier entier");
    scanf("%f", &a);
    printf("Donner le deuxieme entier");
    scanf("%f", &b);
    printf("Donner le troisieme entier");
    scanf("%f", &c);
    float moy = (a + b + c) / 3;
    return moy;
}

int puissance (int base, int expo) {
    int resultat = 1;
        if (expo < 0) {
        return 0;
    }
        for (int i = 0; i < expo; i++) { // boucle pour multiplier la base par elle-même expo fois
        resultat *= base;
    }
    
    return resultat;
}

float addition () {
    float a, b; 
    printf("Saisissez le premier nombre : \n");
    scanf("%f", &a);
    printf("Saisissez le deuxième nombre : \n");
    scanf("%f", &b);

    float result = a + b;
    return result;
}

float soustraction () {
    float a, b; 
    printf("Saisissez le premier nombre : \n");
    scanf("%f", &a);
    printf("Saisissez le deuxième nombre : \n");
    scanf("%f", &b);

    float result = a - b;
    return result;
}

float multiplication () {
    float a, b; 
    printf("Saisissez le premier nombre : \n");
    scanf("%f", &a);
    printf("Saisissez le deuxième nombre : \n");
    scanf("%f", &b);

    float result = a * b;
    return result;
}

float division () {
    float a, b; 
    printf("Saisissez le premier nombre : \n");
    scanf("%f", &a);
    printf("Saisissez le deuxième nombre : \n");
    scanf("%f", &b);

    if (b == 0) {
        printf("Erreur : Division par zéro n'est pas permise.\n");
        return 0;
    }

    float result = a / b;
    return result;
}

int main() {
    int operation;
    float result;
    printf("Veuillez rentrer l'opération voulue\n");
    printf("1 - Addition \n");
    printf("2 - Soustraction \n");
    printf("3 - Multiplication \n");
    printf("4 - Division \n");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            result = addition();
            break;
        
        case 2:
            result = soustraction();
            break;

        case 3:
            result = multiplication();
            break;

        case 4:
            result = division();
            break;

        default:
            printf("Operation inconnue !\n");
            return 0;
    }
    printf("Le resultat est : %.2f\n", result);
    return 0;
}

