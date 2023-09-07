#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

double f(double x) {
    return pow(x,3);
}

double integrateUsingSimpson(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;
    
    area = (f(lower_limit) + f(upper_limit));
    for(int i = 1;i<subIntervals;i++) {
        if(i%2==0) {
            area += 2*(f(lower_limit + i*width));
        }
        else {
            area += 4*(f(lower_limit + i*width));
        }
    }

    area *= width/3;
    return area;
}


int main() {
    double lower_limit = 1;
    double upper_limit = 2;
    int subIntervals = 8;

    
    double answer_simpson = integrateUsingSimpson(lower_limit, upper_limit, subIntervals);
    cout << "SimpSon method: " << answer_simpson << endl;
   
}