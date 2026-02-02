#include <stdio.h>
#include <stdlib.h>

float calculerMoyenne(float *tab, int N) {
    float somme = 0;
    for (int i = 0; i < N; i++) {
        somme += tab[i];
    }
    return somme / N;
}

int main() {
    int N;
    
    printf("Veuillez rentrer le nombre de mesures effectuées pendant le vol: ");
    scanf("%d", &N);

    float *pressions = malloc(N * sizeof(float));
    if (pressions == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Veuillez rentrer la valeur %d: ", i + 1);
        scanf("%f", &pressions[i]);
    }

    float moy = calculerMoyenne(pressions, N);
    printf("La pression moyenne du vol est: %.2f\n", moy);

    free(pressions);
    return 0;
}