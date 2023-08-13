#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double g(double x) {
    double a = 10-(double)pow(x,3);
    a = (double)pow(a,0.5);
    a = a/2;
    
    return a;
}

double findFixedPoint(double approx, double TOL, int N) {
    int i = 0;
    double p;
    while(i < N) {
        p = g(approx);

        if( abs(p-approx) < TOL ) {
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
    double approx = 1.5;
    double TOL = pow(10,-4);
    int N = 40;
    int precision = 10;

    

    double fixedPoint = findFixedPoint(approx, TOL, N);
    cout << setprecision(precision) << fixedPoint << endl;
}