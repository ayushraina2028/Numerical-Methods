#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

class Point{
public:
    double x;
    double y;

    // constructor
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

vector<double> iterativeJacobi(vector<vector<double>> A, vector<double> B, vector<double> initial_vector) {
    vector<double> approximate_vector = initial_vector;
    vector<double> temp_vector = initial_vector;
    int k = 0;
    while(k < 10000){

        // cout << "Approximation " << k << ": " << endl;
        // for(double ele : approximate_vector) {
        //     cout << ele << " ";
        // }
        // cout << endl;

        for(int i = 0;i < A.size(); i++) {

            double summation = 0;
            for(int j = 0;j < A.size(); j++) {
                if(j == i) continue;  
                summation -= A[i][j]*approximate_vector[j];
            }
            summation += B[i];
            summation /= A[i][i];
        
            temp_vector[i] = summation;
        
        }
        
        k++;
        bool flag = true;
        for(int i = 0;i < A.size(); i++) {
            if(abs(temp_vector[i] - approximate_vector[i]) > pow(10,-10)) {
                flag = false;
            }
        }

        if(flag) {
            cout << "Iterations Taken; " << k << endl;
            return temp_vector;
        }

        for(int i = 0;i < A.size(); i++) {
            approximate_vector[i] = temp_vector[i];
        }
    }

    cout << "Iterations Taken; " << k << endl;
    return approximate_vector;
}

void display(vector<vector<double>> v) {
    for(auto vect : v) {
        for(auto ele : vect) {
            cout << ele << "     ";
        }
        cout << endl << endl;
    }
}

void display(vector<double> v) {
    for(auto element : v) {
        cout << element << endl;
    }
    cout << endl;
}

// change f(x), q(x) and r(x) accordingly

double f(double x) {
    double element = -64*(12*pow(x,2) - 12*x +2) + (1+pow(x,2))*64*pow(x-pow(x,2),2);
    return element;
}

double q(double x, double a, double b) {
    return (b/a)*(1+pow(x,2));
}

double r(double x, double a, double b) {
    return -1*f(x)*(1/a);
}

vector<double> trueSoln(double h, double a, int N) {
    vector<double> trues;
    for(int i = 1;i <= N; i++) {
        double x = i*h;
        cout << 64*pow(x,2)*pow(1-x,2) << " ";
        trues.push_back(64*pow(x,2)*pow(1-x,2));
    }
    cout << endl;
    return trues;
}

int main() {
    
    // Initial Conditions
    Point* a = new Point(0,0);
    Point* b = new Point(1,0);

    int N;
    double h;
    double a1;
    double b1;
    cout << "Enter N: " << endl;
    cin >> N;

    cout << "Enter a and b: " << endl;
    cin >> a1 >>b1;



    // calculation of h
    h = (b->x - a->x)/(N+1);
    cout << h << endl << endl;

    // Initializing N cross N matrix with zeroes
    vector<vector<double>> A;
    A.resize(N, vector<double> (N,0.0));

    // Initializing Matrix B of size N
    vector<double> B;
    B.resize(N,0.0);

    // Initializing Omega Vector
    vector<double> W;
    W.resize(N,0.0);

    // Filling Matrix A
    
    // diagonal values
    for(int i = 0; i < N; i++) {
        A[i][i] = 2 + h*h*q(a->x + (i+1)*h,a1,b1);
    }

    for(int i = 0;i < N-1; i++) {
        A[i][i+1] = -1;
    }

    for(int i = 0;i < N-1; i++) {
        A[i+1][i] = -1;
    }

    cout << "Here is your matrix A: " << endl;
    display(A);

    // Filling Matrix B
    for(int i = 0;i <= N; i++) {
        B[i] = (-1)*h*h*r(a->x + (i+1)*h,a1,b1);
    }

    // Filling Extra terms of 1st and last term
    

    cout << endl;

    cout << "Here is your matrix B: " << endl;
    display(B);
    
    // W is already filled with 0 as our initial approximation.

    cout << "Here is your matrix W: " << endl;
    display(W);

    cout << endl;
    cout << "Here are the approximations: " << endl;

    vector<double> final = iterativeJacobi(A,B,W);
    for(auto ele : final) {
        cout << ele << " ";
    }
    cout << endl << endl;

    
    vector<double> trues = trueSoln(h,a->x,N);

    double maxError = 0;
    for(int i = 0;i < trues.size(); i++) {
        maxError = max(maxError, abs(final[i]-trues[i]));
    }

    cout << "Max Error is: " << maxError << endl;
}
/*
Example 1 from 11.3 section book is used in above code

*/