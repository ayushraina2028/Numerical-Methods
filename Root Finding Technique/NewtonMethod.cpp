#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return x-cos(x);
}

double newtonRaphson(double approx, double TOL, int N) {
    double derivative = (f(approx+pow(10,-3))-f(approx))/pow(10,-3);
    double p;
    int i = 0;

    while(i < N) {
        p = approx - f(approx)/derivative;

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
    double approx = 0.1;
    int N = 30;
    double TOL = pow(10,-4);

    double newton = newtonRaphson(approx, TOL, N);
    if(newton == -1) {
        cout << "Method failed after " << N << " iterations." << endl;
    }
    else {
        cout << setprecision(5) << newton << endl;
    }
    

}