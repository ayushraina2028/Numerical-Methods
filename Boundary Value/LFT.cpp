#include <iostream>
#include <vector>
#include <math.h>

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
    while(k < 300){

        cout << "Approximation " << k << ": " << endl;
        for(double ele : approximate_vector) {
            cout << ele << " ";
        }
        cout << endl;

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
            if(abs(temp_vector[i] - approximate_vector[i]) > pow(10,-3)) {
                flag = false;
            }
        }

        if(flag) {
            return temp_vector;
        }

        for(int i = 0;i < A.size(); i++) {
            approximate_vector[i] = temp_vector[i];
        }
    }

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

// change p(x), q(x) and r(x) accordingly
double p(double x) {
    return -(2/x);
}

double q(double x) {
    return (2/x*x);
}

double r(double x) {
    return sin(log(x))/(x*x);
}

int main() {
    
    // Initial Conditions
    Point* a = new Point(1,1);
    Point* b = new Point(2,2);

    int N;
    double h;

    cout << "Enter N: " << endl;
    cin >> N;

    // calculation of h
    h = (b->x - a->x)/(N+1);
    cout << h << endl << endl;

    // Initializing N cross N matrix with zeroes
    vector<vector<double>> A;
    A.resize(N, vector<double> (N,0.0));
    display(A);

    // Initializing Matrix B of size N
    vector<double> B;
    B.resize(N,0.0);

    // Initializing Omega Vector
    vector<double> W;
    W.resize(N,0.0);

    // Filling Matrix A
    
    // diagonal values
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            if(i == j) {
                A[i][j] = 2 + h*h*q(a->x + (i)*h);
            }

            else if(j == i+1) {
                A[i][j] = -1 + (h/2)*p(a->x + i*h);
            }

            else if(j == i-1) {
                A[i][j] = -1 - (h/2)*p(a->x + (i+1)*h);
            }

        }
    }

    cout << "Here is your matrix A: " << endl;
    display(A);

    // Filling Matrix B
    for(int i = 1;i < N; i++) {
        B[i] = (-1)*h*h*r(a->x + (i)*h);
    }

    // Filling Extra terms of 1st and last term
    B[0] += (1 + (h/2)*p(a->x + h))*(a->y);
    B[N-1] += (1 - (h/2)*p(b->x - h))*(b->y);

    cout << endl;

    cout << "Here is your matrix B: " << endl;
    display(B);
    
    // W is already filled with 0 as our initial approximation.

    cout << "Here is your matrix W: " << endl;
    display(W);

    cout << endl;
    cout << "Here are the approximations: " << endl;

    vector<double> final = iterativeJacobi(A,B,W);
}
/*
Example 1 from 11.3 section book is used in above code

*/