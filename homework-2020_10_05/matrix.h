

#ifndef MBP_WORK_MATRIX_H
#define MBP_WORK_MATRIX_H

#include <iostream>
#include <vector>
#include <ctime>

namespace Matrices {
    template<typename T>
    class Matrix {
    private:
        std::vector <std::vector<T>> matrix;
        unsigned rows{};
        unsigned cols{};


    public:
        Matrix() = default;
        Matrix(unsigned rows, unsigned cols, T initial);
        Matrix(const Matrix<T> &rhs);
        ~Matrix() = default;

        Matrix<T> &operator=(const Matrix<T> &rhs);
        Matrix<T> operator+(const Matrix<T> &rhs);
        Matrix<T> &operator+=(const Matrix<T> &rhs);
        Matrix<T> operator-(const Matrix<T> &rhs);
        Matrix<T> &operator-=(const Matrix<T> &rhs);
        Matrix<T> operator*(const Matrix<T> &rhs);
        Matrix<T> &operator*=(const Matrix<T> &rhs);

        Matrix<T> operator+(const T &rhs);
//        Matrix<T> operator+=(const T &rhs);
        Matrix<T> operator-(const T &rhs);
//        Matrix<T> operator-=(const T &rhs);
        Matrix<T> operator*(const T &rhs);
//        Matrix<T> operator*=(const T &rhs);
        Matrix<T> operator/(const T &rhs);
//        Matrix<T> operator/=(const T &rhs);

        Matrix<T> &create_random_matrix(int max_num);
        Matrix<T> transpose();
        std::vector <T> identity_matrix();

        T &operator()(const unsigned &row, const unsigned &col);
        const T &operator()(const unsigned &row, const unsigned &col) const;

        unsigned get_rows() const;
        unsigned get_cols() const;

        template<T>
        friend std::ostream &operator<<(std::ostream &, const Matrix &);

    };

    void init() {
        srand(time(nullptr));
    }

    template<typename T>
    Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const T initial) : rows(rows), cols(cols) {
        matrix.resize(rows);
        for (unsigned i = 0; i < matrix.size(); ++i) {
            matrix[i].resize(cols, initial);
        }
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix<T> &rhs) {
        matrix = rhs.matrix;
        rows = rhs.rows;
        cols = rhs.cols;
    }

    template<typename T>
    Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs) {
        if (&rhs == this) return *this;

        unsigned new_rows = rhs.get_rows();
        unsigned new_cols = rhs.get_cols();
        matrix.resize(new_rows);

        for (unsigned i = 0; i < matrix.size(); ++i) {
            matrix[i].resize(new_cols);
        }

        for (unsigned i = 0; i < new_rows; ++i) {
            for (unsigned j = 0; j < new_cols; ++j) {
                matrix[i] = rhs(i, j);
            }
        }

        rows = new_rows;
        cols = new_cols;

        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] + rhs(i, j);
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs) {
        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                this->matrix[i][j] += rhs(i, j);
            }
        }

        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] - rhs(i, j);
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs) {
        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                this->matrix[i][j] -= rhs(i, j);
            }
        }

        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) {
//        if (this->cols != rhs.get_rows()) throw OperationNotDefinedError;
        unsigned rows = this->rows;
        unsigned cols = rhs.get_cols();
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                for (unsigned k = 0; k <= rows; ++k) {
                    result(i, j) += this->matrix[i][k] * rhs(k, j);
                }
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs) {
        Matrix result = (*this) * rhs;
        (*this) = rhs;
        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator+(const T &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] + rhs;
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator-(const T &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] - rhs;
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator*(const T &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] * rhs;
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator/(const T &rhs) {
        Matrix result(rows, cols, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = this->matrix[i][j] / rhs;
            }
        }

        return result;
    }

    template<typename T>
    Matrix<T> &Matrix<T>::create_random_matrix(int max_num) {
        matrix.resize(rows);
        for (unsigned i = 0; i < rows; ++i) {
            matrix[i].resize(cols);
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = rand() % max_num;
            }
        }
        return *this;

    }

    template<typename T>
    Matrix<T> Matrix<T>::transpose() {
        Matrix result(cols, rows, 0);

        for (unsigned i = 0; i < rows; ++i) {
            for (unsigned j = 0; j < cols; ++j) {
                result(i, j) = matrix[j][i];
            }
        }

        return result;
    }

    template<typename T>
    std::vector<T> Matrix<T>::identity_matrix() {
        std::vector<T> result(rows, 0);

        for (int i = 0; i < rows; ++i) {
            result[i][i] = 1;
        }

        return result;
    }

    template<typename T>
    T &Matrix<T>::operator()(const unsigned int &row, const unsigned int &col) {
        return this->matrix[row][col];
    }


    template<typename T>
    const T &Matrix<T>::operator()(const unsigned int &row, const unsigned int &col) const {
        return this->matrix[row][col];
    }

    template<typename T>
    unsigned Matrix<T>::get_rows() const {
        return this->rows;
    }

    template<typename T>
    unsigned Matrix<T>::get_cols() const {
        return this->cols;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &ostream, const Matrix<T> &m) {
        for (unsigned i = 0; i < m.get_rows(); ++i) {
            for (unsigned j = 0; j < m.get_cols(); ++j) {
                ostream << m(i, j) << " ";
            }
            ostream << "\n";
        }

        ostream << "\n\n";

        return ostream;
    }

}

#endif //MBP_WORK_MATRIX_H
