#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

double f(double x) {
    return pow(x,2)+cos(x);
}


double integrateUsingMidPoint(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;

    for(int i = 0;i < subIntervals;i++) {
        double x_val = lower_limit + i*width;
        double y_val = f(x_val);
        double mid_val = (x_val+y_val)/2;
        area += mid_val*width;
        
    }

    return area;
}


int main() {
    double lower_limit = 0;
    double upper_limit = 4;
    int subIntervals = 10; // Change it accordingly

    
    double answer_midPoint = integrateUsingMidPoint(lower_limit, upper_limit, subIntervals);
    cout << "MidPoint method: " << answer_midPoint << endl;
    
   
}