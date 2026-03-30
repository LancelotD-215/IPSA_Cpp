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

int main() {
    Point P1(0, 0);
    Point P2(3, 4);
    double dist = P1.distance(P2);
    cout << "Distance: " << dist << endl;
    
    Point pointMilieu = P1.milieu(P2);
    cout << "Point milieu: ";
    pointMilieu.afficher();
    
    return 0;
}