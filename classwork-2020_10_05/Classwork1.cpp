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

bool compare(int A[][N], int m, int n, int B[][N], int m1, int n1)
{
  if (m != m1 || n != n1)
    return false;
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if (A[i][j] != B[i][j])
        return false;
    }
  }
  return true;
}

int **sum(int A[][N], int m, int n, int B[][N], int m1, int n1)
{
  int C[m][N];
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
    return (int**)C;
  }
}

int **sMult(int A[][N], int m, int n, int num)
{
  int C[m][N];
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      C[i][j] = A[i][j] * num;
    }
  }
}

int main()
{
  int A[3][N] = {
              {12, 64, -34},
              {-34, 42, -34},
              {12, 64, -34}
            };
  int B[3][N] = {
              {89, 64, -34},
              {-34, 57, -34},
              {98, 64, -32}
            };

  int C[3][N] = sum(A, 3, 3, B, 3, 3);
  std::cout << (compare(A, 3, 3, B, 3, 3)) << std::endl;
  return 0;
}
