#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

double g(double x) {
    // double a = x;
    // a = x + 25*pow(x,-2);
    // a = a/2;

    return 2*exp(-x);
}

double findFixedPoint(double approx, double TOL, int N) {
    int i = 0;
    double p;
    while(i < N) {
        p = g(approx);
        
        if( abs(p-approx) < TOL ) {
            cout << i << endl;
            return p;
        }

        else {
            approx = p;
        }

        i++;

    }

    return -1;
}

int main() {
    double approx = 0.5;
    double TOL = pow(10,-3);
    int N = 500;
    int precision = 5;

    

    double fixedPoint = findFixedPoint(approx, TOL, N);
    cout << setprecision(precision) << fixedPoint << endl;
}