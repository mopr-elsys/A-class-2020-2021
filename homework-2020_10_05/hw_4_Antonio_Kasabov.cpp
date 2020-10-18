#include <iostream>

const int N = 50;
void print(int A[][N], int m, int n)
{
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void sum(int A[][N], int B[][N], int C[][N], int m, int n)
{
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void sMult(int A[][N], int m, int n, int num)
{
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      A[i][j] *= num;
    }
  }
}

void sub(int A[][N], int B[][N], int C[][N], int m, int n)
{
  sMult(B, m, n, -1);
  sum(A, B, C, m, n);
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
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1},
  };

  int C[3][N];

  sMult(A, 3, 3, 2);
  sub(A, B, C, 3, 3);
  print(C, 3, 3);


  return 0;
}
