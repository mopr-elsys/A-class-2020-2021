#include <iostream>
#include <stdlib.h>

using namespace std;

void print (int A[][50], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << endl;
}

bool isEqual (int A[][50], int m1, int n1, int B[][50], int m2, int n2)
{
    if (m1 != m2 || n1 != n2)
    {
        cout << "Not equal\n\n";
        return false;
    }

    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<n1; j++)
        {
            if(A[i][j] != B[i][j])
            {
                cout << "Not equal\n\n";
                return false;
            }
        }
    }
    cout << "Equal\n\n";
    return true;
}

void sum(int A[][50], int B[][50], int C[][50], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transpose(int A[][50], int B[][50], int n, int m)
{
	for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            B[j][i] = A[i][j];
        }
    }
}

void sMult(int A[][50], int B[][50], int n, int m, int s)
{
	for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            B[i][j] = A[i][j] * s;
        }
    }
}

void sub(int A[][50], int B[][50], int C[][50], int n, int m)
{
	int D[50][50];
    sMult(B, D, n, m, -1);
    sum(A, D, C, n, m);
}

bool distr(int A[][50], int B[][50], int n, int m, int a)
{
	int D[50][50] = {{0}};
	int E[50][50] = {{0}};
	int F[50][50] = {{0}};
	int G[50][50] = {{0}};
	int H[50][50] = {{0}};

    sMult(A, D, n, m, a);
    sMult(B, E, n, m, a);
	sum(D, E, F, n, m);
	
	sum(A, B, G, n, m);
	sMult(F, H, n, m, a);

    return isEqual(F, 50, 50, H, 50, 50);
}

int main()
{
    int A[50][50] = 
    {
        {13, 45, 48},
        {-252, 10, 623},
        {384, -217, -123}
    };

    int B[50][50] = 
    {
        {12, 64, -34},
        {-234, 12, 823},
        {657, 283, -123}
    };
    
    int C[50][50] = {{0}};
    
    print(A, 3, 3);
    
    isEqual(A, 3, 3, B, 3, 3);
    
    sum(A, B, C, 3, 3);
    
    print(C, 3, 3);
    
    transpose(A, C, 3, 3);
    
    print(C, 3, 3);
    
    sMult(A, C, 3, 3, 5);
    
    print(C, 3, 3);
    
    sub(A, B, C, 3, 3);
    
    print(C, 3, 3);

	distr(A, B, 3, 3, 5);
    
    return 0;
}
