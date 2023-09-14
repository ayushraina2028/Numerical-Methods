#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

double f(double x) {
    double pi = 3.14;
    double a = (pi*x + pi)*pi/16;
    double b = sin((pi*x + pi)/4);
    return a*b;
}

int main() {
    // problem 3 solved by hand
    // for problem 4 we will do here

    unordered_map <int, unordered_map<double, double>> values;

    pair <double, double> p1;
    p1.first = 1;
    p1.second = 0.5773502692;

    pair <double, double> p2;
    p2.first = 1.000000000000001;
    p2.second = -0.5773502692;

    values[2].insert(p1);
    values[2].insert(p2);

    cout << values[2].size()<< endl;

    double integral = 0;

    for(auto ele : values) {
        for(auto x : ele.second) {
            integral += x.first*f(x.second);
        }
    }

    cout << integral << endl;


}