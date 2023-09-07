#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

double f(double x) {
    return pow(cos(x),2);
}

double integrateUsingSimpson(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/2;
    double area = 0;
    
    area += f(upper_limit) + f(lower_limit) + 4*f((lower_limit+upper_limit)/2);
    area *= width/3;

    return area;
}


int main() {
    double lower_limit = 0;
    double upper_limit = 2*acos(0);
    upper_limit = upper_limit/3;
    int subIntervals = 1;

    
    double answer_trapezoid = integrateUsingSimpson(lower_limit, upper_limit, subIntervals);
    cout << "SimpSon method: " << answer_trapezoid << endl;
   
}