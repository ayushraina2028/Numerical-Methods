#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void approximate(vector <double> coefficients, int degree, double input, vector <double> x_vals) {
    vector <double> l_coeff;
    
    for(int i = 0;i < degree;i++) {
        static double x = 1;
        x *= (input-x_vals[i]);
        l_coeff.push_back(x);
    }

    for(int i = 0;i < l_coeff.size();i++) {
        cout << l_coeff[i] << " ";
    }
    cout << endl;

    double answer = 0;
    for(int i = 0;i < l_coeff.size();i++) {
        answer += l_coeff[i]*coefficients[i+1];
    }
    answer += 200;
    cout << setprecision(6) << answer << endl;
}

void newtonDividedDifference(vector <double> x, vector <double> y,vector <double>& answer) {

    vector <vector <double>> allDifferences;
    vector <double> differences1;
    vector <double> differences2;
    vector <double> differences3;
    vector <double> differences4;
    vector <double> differences5;

    int i = 0;
    int j = 1;
    while (j!=y.size()) {
        differences1.push_back((double)(y[j]-y[i])/(x[j]-x[i]));
        j++,i++;
    }
    

    i = 0;
    j = 1;
    while (j!=differences1.size()) {
        differences2.push_back((double)(differences1[j]-differences1[i])/(x[j+1]-x[i]));
        j++,i++;
    }   
    
    i = 0;
    j = 1;
    while(j != differences2.size()) {
        differences3.push_back((double)(differences2[j]-differences2[i])/(x[j+2]-x[i]));
        j++,i++;
    }

    i = 0;
    j = 1;
    while(j != differences3.size()) {
        differences4.push_back((double)(differences3[j]-differences3[i])/(x[j+3]-x[i]));
        j++,i++;
    }

    i = 0;
    j = 1;
    while(j != differences4.size()) {
        differences5.push_back((double)(differences4[j]-differences4[i])/(x[j+4]-x[i]));
        j++,i++;
    }
    
    allDifferences.push_back(differences1);
    allDifferences.push_back(differences2);
    allDifferences.push_back(differences3);
    allDifferences.push_back(differences4);
    allDifferences.push_back(differences5);

    for(int i = 0;i < allDifferences.size();i++) {
        answer.push_back(allDifferences[i][0]);
    }


}


int main() {

    vector <double> x_vals = {0,0.2,0.4,0.6,0.8,1};
    vector <double> y_vals = {200,200.006,200.41,204.66,226.21,300};
    for(int i = 0;i < x_vals.size();i++) {
        static double s = 1;
        s *= (0.3-x_vals[i]);
        cout << s << endl;
    }
    double input = 0.3;
    // cout << setprecision(5) << input << endl;
    // cout << y_vals[1]-y_vals[0] << endl;
    // cout << x_vals[3]-x_vals[0] << endl;

    int degree = 5;

    vector <double> coefficients;
    coefficients.push_back(1);
    newtonDividedDifference(x_vals,y_vals,coefficients);

    for(int i = 0; i < coefficients.size();i++) {
        cout << coefficients[i] << " ";
    }
    cout << endl;

    approximate(coefficients,degree,input,x_vals);
}