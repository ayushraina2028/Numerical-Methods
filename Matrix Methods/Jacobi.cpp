#include <iostream>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;

vector<double> iterativeJacobi(vector<vector<double>> A, vector<double> B, vector<double> initial_vector) {
    vector<double> approximate_vector = initial_vector;
    vector<double> temp_vector = initial_vector;
    int k = 0;
    while(k < 10){

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
        for(int i = 0;i < A.size(); i++) {
            if(abs(temp_vector[i] - approximate_vector[i]) < pow(10,-3)) {
                return temp_vector;
            }
        }
        for(int i = 0;i < A.size(); i++) {
            approximate_vector[i] = temp_vector[i];
        }
    }

    return approximate_vector;
}

int main() {
    
    // Taking n as input
    cout << "Enter n: Number of Equations: " << endl;
    int n;
    cin >> n;

    // Initializing n cross n matrix with 0 initially
    vector<vector<double>> A;
    A.resize(n, vector<double> (n,0));

    for(int i = 0;i < A.size(); i++) {
        for(int j = 0;j < A[0].size(); j++) {
            double element;
            
            cin >> element;
            A[i][j] = element;
        }
    }

    // check the entered Vector
    cout << "Here is your entered matrix A: " << endl;
    for(auto vect : A) {
        for(auto ele : vect) {
            cout << ele << "    ";
        }
        cout << endl;
        cout << endl;
    }

    cout << "Enter matrix B: " << endl;
    vector<double> B;
    B.resize(n,0);

    for(int i = 0;i < n; i++) {
        double element;
        cin >> element;
        B[i] = element;
    }

    // check the entered vector B
    cout << endl;
    for(auto ele : B) {
        cout << ele << endl;
    }


    cout << "Enter Initial approximation vector: ";
    vector<double> initial_approximation = {0,0,0,0};

    
    // check the entered initial approximation
    for(auto element : initial_approximation) {
        cout << element << endl;
    }

    vector<double> final_approximation = iterativeJacobi(A, B, initial_approximation);
}



/*
A matrix
4
10
-1
2
0
-1
11
-1
3
2
-1
10
-1
0
3
-1
8

B matrix
6
25
-11
15
*/