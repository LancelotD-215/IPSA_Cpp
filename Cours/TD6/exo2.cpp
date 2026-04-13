#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private :
        int x, y;
    public :
        Point (int valx, int valy) {
            x = valx;
            y = valy;
        }
        double distance(Point &autre) {
            int x2 = pow(autre.x - this->x, 2);
            int y2 = pow(autre.y - this->y, 2);
            return sqrt(x2+y2);
        }
        Point milieu(Point &autre) {
            int newx = (this->x + autre.x) /2;
            int newy = (this->y + autre.y) /2;
            return Point (newx, newy);
        }
        void afficher() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
        // Getters
        int getX() const { return x; }
        int getY() const { return y; }
};

class Rectangle {
    private :
        Point hautGauche;
        int longueur, largeur;
        static int nbRectangle;
        Rectangle(Point &p1, Point &p2) : hautGauche(p1) {
            longueur = abs(p2.getX() - p1.getX());
            largeur = abs(p2.getY() - p1.getY());
            nbRectangle++;
        }
    public :
        Rectangle() : hautGauche(0, 0) {
            longueur = 0;
            largeur = 0;
            nbRectangle++;
        }
        Rectangle(int x, int y, int l, int h) : hautGauche(x, y) {
            longueur = l;
            largeur = h;
            nbRectangle++;
        }
        ~Rectangle() {
            nbRectangle--;
        }
        int aire() {
            return longueur * largeur;
        }
        int perimetre() {
            return 2 * (longueur + largeur);
        }
        void afficher() {
            cout << "Rectangle - Coin haut-gauche: ";
            hautGauche.afficher();
            cout << "Longueur: " << longueur << ", Largeur: " << largeur << endl;
            cout << "Aire: " << aire() << ", Perimetre: " << perimetre() << endl;
        }
        static int getNbRectangle() {
            return nbRectangle;
        }
};
int Rectangle::nbRectangle = 0;

int main() {
    // Test de la classe Point
    Point p1(1, 2);
    Point p2(4, 6);
    
    cout << "Point 1: ";
    p1.afficher();
    cout << "Point 2: ";
    p2.afficher();
    
    cout << "Distance entre p1 et p2: " << p1.distance(p2) << endl;
    
    Point milieu = p1.milieu(p2);
    cout << "Point milieu: ";
    milieu.afficher();
    
    // Test de la classe Rectangle
    cout << "\n--- Test des Rectangles ---" << endl;
    cout << "Nombre de rectangles au début: " << Rectangle::getNbRectangle() << endl;
    
    Rectangle r1;
    cout << "Rectangle par défaut: ";
    r1.afficher();
    
    Rectangle r2(3, 5, 10, 8);
    cout << "\nRectangle personnalisé: ";
    r2.afficher();
    
    cout << "\nNombre total de rectangles: " << Rectangle::getNbRectangle() << endl;
    
    return 0;
}