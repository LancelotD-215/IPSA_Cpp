#include <stdio.h>
#include <string.h>

struct Avion {
        char id[50]; //on réserve 50 place dans la memoire
        int alt;
        float speed;
};

// déclaration de prototypes
void montee(struct Avion *avion, int gain);


int main() {
    struct Avion A320 = {"Airbus-A320", 2000, 300.0};
    montee(&A320, 1000);
    printf("Altitude après montée: %d\n", A320.alt);
    return 0;
}


void montee(struct Avion *avion, int gain) {
    avion -> alt += gain; //-> car c'est un pointeur pas l'objet
}