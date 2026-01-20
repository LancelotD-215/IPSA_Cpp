#include <iostream> // inclusion de la bibliothèque standard d'entrée/sortie
#include <string> // inclusion de la bibliothèque standard de gestion des chaînes de caractères

int main() {
    // Déclaration des variables
    int age;
    bool Majeur_Mineur;

    age = -1; // Initialisation de l'âge pour entrer dans la boucle

    while (age < 0 || age > 100) {
        std::cout << "Entrez votre age :" << std::endl; // << permet de mettre le texte dans cout
        std::cin >> age; // >> permet de lire les données de cin

        if (age < 0 || age > 100)
        {
            std::cout << "Veuillez entrer un age entre 0 et 100." << std::endl;
        }
        
    }

    // Vérification si l'utilisateur est majeur ou mineur
    if (age >= 18) {
        Majeur_Mineur = true;
    } else {
        Majeur_Mineur = false;
    }

    // Affichage du résultat
    std::cout << "Vous avez : " << age << " ans vous êtes ";
    if (Majeur_Mineur) {
        std::cout << "majeur" << std::endl; // std::endl permet de passer à la ligne et d'afficher directement
    } else {
        std::cout << "mineur" << std::endl;
    }

    return 0;
}