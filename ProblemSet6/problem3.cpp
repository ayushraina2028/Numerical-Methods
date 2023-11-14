#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <climits>

using namespace std;

double f(double x, double y) {
    // return (y*log(y))/x;
    return y-x;
}

double eulersMethod(double h, double x, double y, double final) {

    if(x-final < h) return f(x,y);

    double y1 = y + h*(f(x,y)-x);
    cout << y1 << endl;
    eulersMethod(h,x+h,y1,final);

    return
}

int main() {
    double initial_x = 0;
    double initial_y = 0.5;
    double h = 0.1;
    double required_x = 1;

    cout << setprecision(5) << eulersMethod(h,initial_x,initial_y,required_x) << endl;
}