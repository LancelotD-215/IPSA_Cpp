#include <stdio.h>

int main() {
    int cap = 100;
    int *ptr_cap;
    
    ptr_cap = &cap;
    printf("Cap avant correction: %d\n", cap);
    
    *ptr_cap = 120;
    printf("Cap après correction: %d\n", cap);
    
    return 0;
}

void energie(float tension, float courant, float *puissance, float *resistance) {
    *puissance = tension * courant;
    *resistance = tension / courant;
}