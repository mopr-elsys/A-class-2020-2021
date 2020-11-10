#include <iostream>
#include <vector>
#include <ctime>
#include "matrix.h"

int main() {
    const unsigned rows = 2;
    const unsigned cols = 3;
    Matrices::Matrix<int> a(rows, cols, 0);

    a.create_random_matrix(10);
    std::cout << "Matrix A:\n" << a;
    std::cout << "Matrix A + 2:\n" << a + 2;
    std::cout << "Matrix A * 2:\n" << a * 2;

    Matrices::Matrix<int> c(cols, rows, 0);
    c.create_random_matrix(10);
    std::cout << "Matrix C:\n" << c;
    std::cout << "Matrix A * C:\n" << a * c;

    Matrices::Matrix<int> b(rows, cols, 0);
    b.create_random_matrix(10);
    std::cout << "Matrix B:\n" << b;

    std::cout << "Matrix A + B:\n" << a + b;
    std::cout << "Matrix A - B:\n" << a - b;
    std::cout << "Matrix A * B:\n" << a * b;

    std::cout << "Matrix A + 2:\n" << a + 2;


    return 0;
}



//class MatricesErrors{
//    OperationNotDefinedError
//};