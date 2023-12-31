#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <climits>
using namespace std;

double f(double x) {
    return pow(x,3) + 5*pow(x,2) + 1;
}

double CompositeRectange(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;

    for(int i = 0;i < subIntervals;i++) {
        double x_val = lower_limit + i*width;
        double y_val = f(x_val);
        area += y_val*width;
        
    }

    return area;
}

double CompositeMidPoint(double lower_limit, double upper_limit, int subIntervals) {
    double width = (upper_limit-lower_limit)/subIntervals;
    double area = 0;
    double mid_val = 0;
    for(int i = 0;i < subIntervals-1;i++) {
        double x_val = lower_limit + i*width;
        double x_val2 = lower_limit + (i+1)*width;
        mid_val = (x_val2 + x_val)/2;
        double y_val = f(mid_val);
        area += y_val*width;
    }

    area += f(mid_val+width)*width;

    return area;
}

int main() {
    double lower_limit = 1;
    double upper_limit = 5;

    cout << "Composite Rectangle Method" << endl;
    double true_answer = CompositeRectange(lower_limit,upper_limit,500);
    double answerCompositeRectangle1 = CompositeRectange(lower_limit, upper_limit, 5);
    double answerCompositeRectangle2 = CompositeRectange(lower_limit, upper_limit, 10);
    cout << "5 Sub Intervals: " << answerCompositeRectangle1 << ", True Error: " << true_answer-answerCompositeRectangle1 << endl;
    cout << "10 Sub Intervals: " << answerCompositeRectangle2 << ", True Error: " << true_answer-answerCompositeRectangle2 << endl;

    cout << "Composite Mid Point Method" << endl;
    double answerComposite1 = CompositeMidPoint(lower_limit,upper_limit,5);
    double answerComposite2 = CompositeMidPoint(lower_limit,upper_limit,10);
    cout << "5 Sub Intervals: " << answerComposite1 << ", True Error: " << true_answer-answerComposite1 << endl;
    cout << "10 Sub Intervals: " << answerComposite2 << ", True Error: " << true_answer-answerComposite2 << endl;

}