#include<iostream>

using namespace std;

const int N = 50;

/*void print(int A[][N], int m, int n)
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
	print(A, 3, 3);
	return 0;
}*/





/*bool equal(int A[][N], int m1, int n1, int B[][N], int m2, int n2)
{
	if(m1!=m2 || n1!=n2)
	{
		return false;
	}
	for(int i = 0; i<n1; ++i)
	{
		for(int j = 0; j<m1; ++j)
		{
			if(A[i][j]!=B[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int A[50][N];
	int B[50][N];
	
	int m1, n1, m2, n2;
	cin>>m1>>n1;
	for(int i = 0; i<n1; ++i)
	{
		for(int j = 0; j<m1; ++j)
		{
			cin>>A[i][j];
		}
	}

	cin>>m2>>n2;
	for(int i = 0; i<n2; ++i)
	{
		for(int j = 0; j<m2; ++j)
		{
			cin>>B[i][j];
		}
	}
	
	cout<<(equal(A, m1, n1, B, m2, n2) ? "Equal" : "Not Equal")<<endl;
	return 0;
}*/






/*void sum(int A[][N], int B[][N], int C[][N], int n, int m)
{
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			C[i][j] = A[i][j]+B[i][j];
		}
	}
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			cout<<C[i][j]<<" ";
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
		{12, 64, -34}, 
		{-234, 12, 823},
		{657, 283, -123}
	};
	int C[3][N] = {{0}};
	sum(A, B, C, 3, 3);
	return 0;
}*/




/*void transpose(int A[][N], int B[][N], int m, int n)
{
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			B[i][j] = A[j][i];
		}
	}
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			cout<<B[i][j]<<" ";
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
	int B[3][N] = {{0}};
	transpose(A, B, 3, 3);
	return 0;
}*/






void sMult(int A[][N], int number, int m, int n)
{
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
		{
			A[i][j] *= number;
		}
	}
	for(int i = 0; i<n; ++i)
	{
		for(int j = 0; j<m; ++j)
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
	int number=2;
	sMult(A, number, 3, 3);
	return 0;
}
