#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x) {
    return (double)pow(x,3) - x - 1;
}

double bisection(double a, double b, double TOL, int N) {
    double low = a;
    double high = b;
    double mid;
    int i = 0;

    while(i <= N) {
        mid = low + (high-low)/2;

        if(f(mid)==0 || (high-low)/2 < TOL) {
            return mid;
        }
        else if(f(mid) < 0) {
            low = mid;
        }
        else {
            high = mid;
        }

        i++;
    }

    return -1;
}

int main() {
    double a=1;
    double b=2;
    double TOL = pow(10,-4);
    int N = 30;
    int precision = 5;

    double root = bisection(a,b,TOL,N);
    cout << setprecision(precision) << root << endl;
}