#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Point {
public:
    double x;
    double y;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

};

double f(double t, double y) {
    return y-pow(t,2)+1;
}

int main() {

    Point* y_initial = new Point(0,0.5);
    cout << "y(" << y_initial->x << ") = " << y_initial->y << endl; 
    int N = 10;
    double h = 0.25;
    Point* next = new Point(y_initial->x, y_initial->y);

    for(int i = 1;i <= N; i++) {
        
        double y_next = y_initial->y + h*f(y_initial->x, y_initial->y);
        cout << "y(" << y_initial->x + h << ") = " <<  y_next << endl;

        y_initial->x += h;
        y_initial->y = y_next;
        
    }
}