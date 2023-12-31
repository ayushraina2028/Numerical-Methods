#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

double f(double x) {
    return sqrt(1+pow(x,2));
}

double integrateUsingRectangle(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;

    for(int i = 0;i < subIntervals;i++) {
        double x_val = lower_limit + i*width;
        double y_val = f(x_val);
        area += y_val*width;
        
    }

    return area;
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

double integrateUsingTrapezoid(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;
    if(subIntervals ==1) {
        area = (width/2)*(f(lower_limit) + f(upper_limit));
    }
    else {
        area = (f(lower_limit) + f(upper_limit));
        for(int i = 1;i<subIntervals;i++) {
            area += 2*f(lower_limit + i*width);
        }

        area *= width/2;
    }

    return area;
}


int main() {
    double lower_limit = 1;
    double upper_limit = 5;
    int subIntervals = 100;

    double answer_rectangle = integrateUsingRectangle(lower_limit, upper_limit, subIntervals);
    double answer_midPoint = integrateUsingMidPoint(lower_limit, upper_limit, subIntervals);
    double answer_trapezoid = integrateUsingTrapezoid(lower_limit, upper_limit, subIntervals);
    cout << "Rectangle method: " << answer_rectangle << endl;
    cout << "MidPoint method: " << answer_midPoint << endl;
    cout << "Trapezoid method: " << answer_trapezoid << endl;
   
}