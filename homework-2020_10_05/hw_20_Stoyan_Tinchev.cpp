#include<iostream>
using namespace std;
const int N = 50;


void sMult(int A[][N], int number, int m, int n)
{
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			A[i][j] *= number;
		}
	}
}
void sum(int A[][N], int B[][N], int C[][N], int n, int m)
{
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			C[i][j] = A[i][j]+B[i][j];
		}
	}
}
void sub(int A[][N], int B[][N], int C[][N], int m, int n)
{
	sMult(B, -1, m, n);
	sum(A, B, C, m, n);
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
		{12, 64, -34}, 
		{-234, 12, 823},
		{657, 283, -123}
	};
	int B[3][N] = 
	{
		{1, 6, -3}, 
		{-23, 1, 23},
		{67, 28, -12}
	};
	int C[3][N] = {{0}};
	sub(A, B, C, 3, 3);
	print(C, 3, 3);
	return 0;
}
