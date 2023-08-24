#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return x - cos(x);
}

double secantMethod(double approx1, double approx2, double TOL, int N) {
    int i = 2;
    double q0 = f(approx1);
    double q1= f(approx2);
    double p;

    while(i <= N) {
        p = approx2 - q1*(approx2 - approx1)/(q1-q0);
        if( abs(p-approx1) < TOL) {
            cout << i << endl;
            return p;
        }
        i++;
        approx1 = approx2;
        q0 = q1;
        approx2 = p;
        q1 = f(p);

    }

    return -1;
}

int main() {
    double approx1 = 0.1;
    double approx2 = 0.5;
    double TOL = pow(10,-4);
    int N = 30;

    double secant = secantMethod(approx1,approx2,TOL,N);

    if(secant == -1) {
        cout << "Method Failed" << endl;
    }
    cout << setprecision(5) << secant << endl;
}