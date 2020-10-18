#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 50;

bool equal(int A[][N], int m1, int n1, int B[][N], int m2, int n2){
    if (m1 != m2 || n1 != n2){
        return false;
    }

    for(int i = 0; i < m1; ++i){
        for(int j = 0; j < n1; ++j){
            if(A[i][j] != B[i][j]){
                return false;
            }
        }
    }

    return true;
}

void sum(int A[][N], int B[][N], int C[][N], int m, int n){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transpose(int A[][N], int B[][N], int m, int n){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            B[j][i] = A[i][j];
        }
    }
}

void sMult(int A[][N], int B[][N], int m, int n, int s){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            B[i][j] = A[i][j] * s;
        }
    }
}

void sub(int A[][N], int B[][N], int C[][N], int m, int n){
    int D[][N] = {{0}};
    sMult(B, D, m, n, -1);
    sum(A, B, C, m, n);
}

bool distr(int A[][N], int B[][N], int m, int n, int a){
    int aA[][N] = {{0}};
    int aB[][N] = {{0}};
    int aAaB[][N] = {{0}};
    int D[][N] = {{0}};
    int E[][N] = {{0}};
    
    sMult(A, aA, n, m, a);
    sMult(B, aB, n, m, a);
    sum(aA, aB, aAaB, m, n);
    sum(A, B, D, m, n);
    sMult(D, E, m, n, a);

    return equal(aAaB, N, N, E, N, N);
}

void print (int A[][N], int m, int n){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int A[3][N] = 
    {
        {4, 89, -1},
        {-25, 56, 9},
        {23, 100, -13}
    };

    int B[3][N] = 
    {
        {190, 76, 90},
        {81, 14, 3},
        {0, 8, -5}
    };

    int C[3][N] = {{0}};

    bool eq = equal(A, 3, N, B, 3, N);
    if(eq){
        cout << "Equal" << endl;
    }
    else{
        cout << "Not Equal" << endl;
    }

    sum(A, B, C, 3, N);
    cout << "Sum of A and B is:" << endl;
    print(C, 3, 3);

    transpose(A, C, 3, N);
    cout << "Transposed of A is:" << endl;
    print(C, 3, 3);

    transpose(B, C, 3, N);
    cout << "Transposed B is:" << endl;
    print(C, 3, 3);

    sMult(A, C, 3, N, 2);
    cout << "Elements of A multiplied by 2:" << endl;
    print(C, 3, 3);

    sub(A, B, C, 3, N);
    cout << "B subtracted from A is:" << endl;
    print(C, 3, 3);

    return 0;
}