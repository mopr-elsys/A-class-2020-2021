#include <iostream>

const int N = 50;

void print_matrix(int arr[][N], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << arr[i][j] << " ";
    }

    std::cout << std::endl;
  }
}

bool if_equal(int arr1[][N], int arr2[][N], int m1, int n1, int m2, int n2)
{
  if(m1 != m2 || n1 != n2)
  {
    return 0;
  }
  
  for (int i = 0; i < m1; i++)
  {
    for (int j = 0;j < n1; j++)
    {
      if(!(arr1[i][j] == arr2[i][j]))
      {
        return 0;
      }
    }
  }
  return 1;
}

void sum_matrix(int arr1[][N], int arr2[][N], int tmp[][N], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      tmp[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
}

void transponse(int arr1[][N], int arr2[][N], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr2[i][j] = arr1[j][i];
    }
  }
}

void multiply_matrix(int arr1[][N], int arr2[][N], int m, int n, int num)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr2[i][j] = arr1[i][j] * num;
    }
  }
}

void sub(int a[][N], int b[][N], int c[][N], int m, int n)
{
  int tmp[m][N];
  multiply_matrix(b, tmp, m, n, -1);

  sum_matrix(a, tmp, c, m, n);
}

int main()
{
  int arr[3][N] = {
	  	    {1, 2, 3},
		      {4, 5, 6},
		      {7, 8, 9}
  		  };

  int arr2[3][N] = {
	  	     {1, 2, 3},
		       {4, 5, 6},
		       {7, 8, 9}
  		   };

  int third[3][N];

  sum_matrix(arr, arr2, third, 3, 3);

  int transponned_third[3][N];

  multiply_matrix(third, transponned_third, 3, 3, 2);

  print_matrix(transponned_third, 3, 3);
  return 0;
}
