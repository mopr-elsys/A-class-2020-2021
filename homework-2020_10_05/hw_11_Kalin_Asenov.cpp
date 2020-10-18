#include <iostream>
using namespace std;

void print(int A[][50], int n, int m)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

bool equal (int A[][50], int n1, int m1, int B[][50], int n2, int m2)
{
    if (m1 != m2 || n1 != n2)
    {
        return false;
    }

    for(int i=0; i<n1; ++i)
    {
        for(int j=0; j<m1; ++j)
        {
            if(A[i][j] != B[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void sum(int A[][50], int B[][50], int C[][50], int n, int m)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transpose(int A[][50], int B[][50], int n, int m)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
           B[j][i] = A[i][j];
        }
    }
}

void sMult(int A[][50], int B[][50], int n, int m, int s)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
           B[i][j] = A[i][j]*s;
        }
    }
}

void sub(int A[][50], int B[][50], int C[][50], int n, int m)
{
    int D[3][50] = {{0}};
    sMult(B, D, n, m, -1);
    sum(A, D, C, n, m);
}

bool distr(int A[][50], int B[][50], int n, int m, int a)
{
    int C[50][50] = {{0}};
    int D[50][50] = {{0}};
    int E[50][50] = {{0}};
    int F[50][50] = {{0}};
    int G[50][50] = {{0}};


    sMult(A, C, n, m, a);
    sMult(B, D, n, m, a);
    sum(C, D, E, n, m);

    sum(A, B, F, n, m);
    sMult(F, G, n, m, a);

    return equal(E, 50, 50, G, 50, 50);
}

int main()
{
    int A[3][50] = 
    {
        {12, 64, -34},
        {-234, 12, 823},
        {657, 283, -123}
    };
    
    int B[3][50] = 
    {
        {13, 46, 67},
        {81, 19, 34},
        {0, 3, -12}
    };

    int C[3][50] = {{0}};
    

    if(equal(A, 3, 50, B, 3, 50) == true)
    {
        printf("Equal\n");
    }
    else if(equal(A, 3, 50, B, 3, 50) == false)
    {
        printf("Not Equal\n");
    }

    sum(A, B, C, 3, 3);
    print(C, 3, 3);

    transpose(A, C, 3, 50);
    print(C, 3, 3);

    sMult(A, C, 3, 50, 2);
    print(C, 3, 3); 

    sub(A, B, C, 3, 50);
    print(C, 3, 3);

    if(distr(A, B, 3, 50, 2) == true)
    {
        printf("Equal\n");
    }
    else if(distr(A, B, 3, 50, 2) ==  false)
    {
        printf("Not Equal\n");
    }
    
    return 0;
}