#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return x - cos(x);
}

double falsePositionMethod(double p0, double p1, double TOL, int N) {
    int i = 2;
    double q0 = f(p0);
    double q1 = f(p1);
    double p;
    double q;

    while(i <= N) {
        p = p1 - q1*(p1-p0)/(q1-q0);
        if( abs(p - p1) < TOL) {
            cout << i << endl;
            return p;
        }

        i++;
        q = f(p);

        if(q*q1 < 0) {
            p0 = p1;
            q0 = q1;
        }

        p1 = p;
        q1 = q;

    }

    return -1;
}

int main() {
    double p0 = 0.2;
    double p1 = 0.5;
    double TOL = pow(10,-4);
    int N = 30;

    double falseroot = falsePositionMethod(p0,p1,TOL,N);
    if(falseroot == -1) {
        cout << "Method Failed";
    }
    else {
        cout << setprecision(5) << falseroot << endl;
    }
}