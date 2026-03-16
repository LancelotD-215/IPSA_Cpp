#include <string>
#include <iostream>
using namespace std;

int syracuse(int val, int &maxatteint) {
    maxatteint = val;
    int nb = 0;
    while (val != 1) {
        if (val%2 == 0) {
            val /= 2;
        } else {
            val *= 3;
            val += 1;
        }
        if (maxatteint < val) {
            maxatteint = val;
        }
        nb++;
    }
    return nb;
}

int main() {
    int valeur;
    int maxatteint;
    
    cout << "Entrez une valeur : ";
    cin >> valeur;
    
    int val_origin = valeur;
    
    int nombre_etapes = syracuse(valeur, maxatteint);
    
    cout << "Nombre d'étapes : " << nombre_etapes << endl;
    cout << "Maximum atteint : " << maxatteint << endl;

    return 0;
}

