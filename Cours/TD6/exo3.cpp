#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Client {
    private :
        string nom, prenom;
        int id;
        static int compteur;
    public :
        Client(string prenom, string nom) {
            this->nom = nom;
            this->prenom = prenom;
            id = compteur;
            compteur++;
        }
        Client() {
            this->nom = "default";
            this->prenom = "default";
            id = -1;
        }
        void afficher() {
            cout << prenom << " " << nom << " ID=" << id << endl;
        }
        int getId() {
            return id;
        }
};
int Client::compteur = 0;

class FileDAttente {
    private :
        Client *tab;
        int tailleCourante;
        int capacite;
    public :
        FileDAttente(int capacite) {
            this->capacite = capacite;
            this->tailleCourante = 0;
            this->tab = new Client[capacite];
        }
        ~FileDAttente() {
            delete[] tab;
        }
        void ajouter(Client &c) {
            if (tailleCourante < capacite) {
                tab[tailleCourante] = c;
                tailleCourante++;
            } else {
                int newCapacite = capacite * 2;
                Client *newTab = new Client[newCapacite];
                
                for(int i = 0; i < tailleCourante; i++) {
                    newTab[i] = tab[i];
                }

                delete[] tab;
                
                this->tab = newTab;
                this->capacite = newCapacite;
                
                tab[tailleCourante] = c;
                tailleCourante++;
            }
        }
        void suivant() {
            if (tailleCourante > 0) {
                for(int i=0; i<tailleCourante-1; i++) {
                    tab[i] = tab[i+1];
                }
                tailleCourante--;
            }
        }
        void passeDevant(int idRecherche) {
            int index = -1;
            for(int i = 0; i < tailleCourante; i++) {
                if(tab[i].getId() == idRecherche) {
                    index = i;
                    break;
                }
            }
            
            if(index > 0) {
                // Swap
                Client temp = tab[index];
                tab[index] = tab[index-1];
                tab[index-1] = temp;
            }
        }
        int getCapacite() {
            return capacite;
        }
        void afficher() {
            for(int i = 0; i < tailleCourante; i++) {
                tab[i].afficher();
            }
        }
};

int main() {
    FileDAttente f(2);
    cout << "capacite après création : " << f.getCapacite() << endl;

    
    Client c1("Lancelot", "Danesse");
    Client c2("Sacha", "Delobel");
    Client c3("Martin", "Deligne");
    
    f.ajouter(c1);
    f.ajouter(c2);
    cout << "capacite après 2 clients : " << f.getCapacite() << endl;
    f.ajouter(c3);
    cout << "capacite après 3 clients (donc dépassement) : " << f.getCapacite() << endl;

    cout << "\nordre avant suivant : " << endl;
    f.afficher();
    f.suivant();
    cout << "\nordre après suivant : " << endl;
    f.afficher();

    f.passeDevant(c3.getId());
    cout << "\nordre après passeDevant : " << endl;
    f.afficher();
    
    return 0;
}