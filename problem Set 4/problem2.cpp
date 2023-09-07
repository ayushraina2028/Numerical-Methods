#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

double f(double x) {
    return sqrt(1+pow(x,2));
}

double integrateUsingTrapezoid(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit);
    double area = 0;
    area += (f(lower_limit)+f(upper_limit))/2;
    area *= width/2;

    return area;
}


int main() {
    double lower_limit = 1;
    double upper_limit = 5;
    int subIntervals = 100;

    
    double answer_trapezoid = integrateUsingTrapezoid(lower_limit, upper_limit, subIntervals);
    cout << "Trapezoid method: " << answer_trapezoid << endl;
   
}