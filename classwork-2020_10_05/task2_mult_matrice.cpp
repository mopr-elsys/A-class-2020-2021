#include<iostream>

using namespace std;

const int N=50;


void transpose(int A[][N], int m, int n)
{
	int B[n][m] = {{0}};
	for (int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			B[i][j] = A[j][i];
		}
	}
	for (int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			A[i][j] = B[i][j];
		}
	}
}
void Mult_matrix(int A[][N], int B[][N], int C[][N], int m1, int n1, int m2, int n2)
{
	transpose(B, m2, n2);
	for(int i=0; i<m1; i++)
	{
		for(int j=0; j<n2; j++)
		{
			for(int k=0; k<n2; k++)
			{
				C[i][j]+=A[i][k]*B[j][k];
			}
		}
	}
}

void print(int A[][N], int m, int n)
{
        for(int i = 0; i < m; ++i)
        {
                for(int j = 0; j < n; ++j)
                {
                        cout<<A[i][j]<<" ";
                }
                cout<<endl;
        }
}

int main()
{
	int A[3][N] = 
    {
            {1, -1}, 
            {3, 2},
            {6, 7}
    };
    int B[2][N] = 
    {
            {1, 4}, 
            {2, 3},
    };
    int C[3][N] = {{0}};
    Mult_matrix(A, B, C, 3, 2, 2, 2);
        
	print(C, 3, 2);


	return 0;
}










/*int vectorMult(int A[], int B[], int n1, int n2)
{
	int res=0;
	for(int i=0; i<n1; i++)
	{
		res += A[i]*B[i];
	}
	return res;
}

int main()
{
	int A[3] = {1, 2, 3};
	int B[3] = {1, 2, 3};
	cout<<vectorMult(A, B, 3, 3);


	return 0;
}*/



/*void vectorMatrixMult(int A[], int B[][N], int C[], int c1, int r2, int c2)
{
	for(int i=0; i<c2; ++i)
	{
		//C[i]=0;
		for(int j=0; j<r2; ++j)
		{
			C[i] = C[i] + (A[j] * B[j][i]);

			cout<<"A["<<j<<"]: "<<A[0]<<endl;
			cout<<"B["<<j<<"]["<<i<<"]:"<<B[j][i]<<" "<<endl;
			cout<<"A["<<j<<"] * B["<<j<<"]["<<i<<"] = "<<A[j] * B[j][i]<<endl;
			cout<<"C["<<i<<"]: "<<C[i]<<endl<<endl;
		}
		cout<<"A["<<"0"<<"]: "<<A[0]<<endl;
		cout<<endl<<endl<<endl;
	}
	
}

int main()
{
	int A[] = {1, 2, 3, 4};
    int B[4][N] = 
    {
            {5, 6}, 
            {7, 8},
			{9, 10},
			{11, 12}
    };
    int C[2] = {0};  //if i write int C[] = {0}; it doesnt work, why?
    vectorMatrixMult(A, B, C, 4, 4, 2);
        


	return 0;
}*/
