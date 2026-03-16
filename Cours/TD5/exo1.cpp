#include <string>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void swap(string &a, string &b) {
    string temp = b;
    b = a;
    a = temp;
}

int main() {
    int a;
    int b;

    cout << "rentrez une valeure pour a" << endl;
    cin >> a;
    cout << "rentrez une valeure pour b" << endl;
    cin >> b;

    cout << "vos valeurs : " << a << "    " << b << endl;

    swap(a, b);
    cout << "vos valeurs après swap : " << a << "    " << b << endl;

    string nom1, nom2;
    
    cout << "Entrez le premier nom : ";
    cin >> nom1;
    cout << "Entrez le deuxième nom : ";
    cin >> nom2;
    
    cout << "vos noms : " << nom1 << "    " << nom2 << endl;
    
    swap(nom1, nom2);
    cout << "vos noms après swap : " << nom1 << "    " << nom2 << endl;

    return 0;
}