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
};

class Rectangle {
    private :
        Point hautGauche;
        int longueur, largeur;
        static int nbRectangle;
        Rectangle(Point &p1, Point &p2) {
            longueur
        }
    public :
        Rectangle() {
            longueur, largeur = 0;
            hautGauche = Point(0, 0);
            nbRectangle++;
        }
        ~Rectangle
};
int Rectangle::nbRectangle = 0;