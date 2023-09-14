#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

double f(double x, double y) {
    return log(x + 2*y);
}

int main() {
    double a; // -> y_low
    double h; // -> y_high
    double c; // -> x_low
    double d; // -> x_high

    vector <double> x = {1.40, 1.55, 1.70, 1.85, 2.00};
    vector <double> y = {1.00, 1.25, 1.50};

    double integral = 0;

    // for(int i = 0;i < x.size()-1;i++) {
    //     for(int j = 0;j < y.size()-1;j++) {
    //         a = y[j];
    //         h = y[j+1];
    //         c = x[i];
    //         d = x[i+1];
    //         integral += f(a,c) + 4*f(a, (c+d)/2) + f(a,d);
    //         integral += 4*(f((a+h)/2, c) + 4*f((a+h)/2, (c+d)/2) + f((a+h)/2, d));
    //         integral += f(h,c) + 4*f(h, (c+d)/2) + f(h,d);
    //         integral *= (d-c)/6;
    //     }
    // }
    c = 1.00;
    d = 1.50;
    a = 1.40;
    h = 1.70;
    integral += f(a,c) + 4*f(a, (c+d)/2) + f(a,d);
    integral += 4*(f((a+h)/2, c) + 4*f((a+h)/2, (c+d)/2) + f((a+h)/2, d));
    integral += f(h,c) + 4*f(h, (c+d)/2) + f(h,d);
    
    c = 1.00;
    d = 1.50;
    a = 1.70;
    h = 2.00;
    integral += f(a,c) + 4*f(a, (c+d)/2) + f(a,d);
    integral += 4*(f((a+h)/2, c) + 4*f((a+h)/2, (c+d)/2) + f((a+h)/2, d));
    integral += f(h,c) + 4*f(h, (c+d)/2) + f(h,d);
    integral *= (d-c)/6;
    integral *= (h-a)/6;
    
    cout << integral << endl;
}