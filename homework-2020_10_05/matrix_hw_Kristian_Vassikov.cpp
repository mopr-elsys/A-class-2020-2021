#include<iostream>
using namespace std;

const int N = 50;

int print_matrix(int A[][N], int m ,int n)
{
	for(int i = 0; i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*
int main()
{
int A[3][N] = {
	{12,64,-34},
	{-234, 12,823},
	{657, 283,-123}
};

print_matrix(A,3,3);
return 0;
}*/



bool equal(int A[][N], int m, int n, int B[][N], int m1, int n1)
{
	if(m!=m1 or n!=n1)
	{
		return false;
	}

	for(int i = 0; i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(A[i][j] != B[i][j])
				{
					return false;
				}			
			}
			
		}
	return true;
}
/*
int main()
{
int A[50][N];
int B[50][N];

int m,n,m1,n1;
cin>>m>>n;

	for(int i = 0; i<m;++i)
		{
			for(int j=0;j<n;++j)
			{				
					cin>>A[i][j];							
			}
			
		}

cin>>m1>>n1;

	for(int i = 0; i<m1;++i)
		{
			for(int j=0;j<n1;++j)
			{
					cin>>B[i][j];						
			}
			
		}
cout<<((equal(A,m,n,B,m1,n1)) ? "Equal": "Not Equal")<<endl;

}*/

// Sum matrix



/*int main()
{
int A[3][N] = {
	{12,64,-34},
	{-234, 12,823},
	{657, 283,-123}
};

int B[3][N] = {
	{13,46,67},
	{81, 19,34},
	{0, 3,-12}
};

int C[3][N] = {{0}}; // Prazna matrica

sum (A,B,C,3,3);

print_matrix(C,3,3);
}*/

int sum(int A[][N], int B[][N], int C[][N], int m, int n)
{
	for(int i = 0; i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
		
	}
}

void transpose(int A[][N], int B[][N], int m, int n)
{
	for(int i = 0; i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			B[i][j] = A[j][i];
		}
		
	}
}


void sMult(int A[][N], int B[][N], int m, int n, int s)
{
	for(int i = 0; i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			B[i][j] = s*A[i][j];
		}
		
	}
}

void sub(int A[][N], int B[][N], int C[][N], int m, int n)
{
	int currB[3][N] = {{0}};
	sMult(B,currB,m,n,-1);
	sum(A,currB,C,m,n);
	print_matrix(C,m,n);
}

int main()
{
int m,n;
m=n=3;
int A[3][N] = {
	{12,64,-34},
	{-234, 12,823},
	{657, 283,-123}};

int B[][N] = {
	{13,46,67},
	{81, 19,34},
	{0, 3,-12}};

int C[][N] = {{0}};
sub(A,B,C,m,n);

}
