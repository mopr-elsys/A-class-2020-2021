#include <iostream>
#include <vector>

namespace matrix {
    class Matrix {
    public:
        Matrix() {
            for (int i = 0; i < Matrix::N * Matrix::N; ++i) {
                data.push_back(0);
            }
            dimensions = {0, 0};
        }

        Matrix(int *data_ptr) {
//            data
//            dimensions
        }

        ~Matrix() {

        }

        int same_dimensions_as(const Matrix &other) {
            if (this->dimensions.first == other.dimensions.first &&
                this->dimensions.second == other.dimensions.second) {
                return 1;
            }
            return 0;
        }

        Matrix &transposed() const {
            Matrix *t = new Matrix;
            t->set_dimensions(this->y_dim(), this->x_dim());
            int val;
            for (int y = 0; y < this->dimensions.second; ++y) {
                for (int x = 0; x < this->dimensions.first; ++x) {
                    val = this->at(x, y);
                    t->store_at(y, x, val);
                }
            }
            return *t;
        }

        int index(int x, int y) const {
            int idx = y * dimensions.first + x;
            return idx;
        }

        int at(int x, int y) const {
            int idx = index(x, y);
            return this->data[idx];
        }

        void store_at(int x, int y, int val) {
            int idx = index(x, y);
            this->data[idx] = val;
        }

        int x_dim() const {
            return this->dimensions.first;
        }

        int y_dim() const {
            return this->dimensions.second;
        }

        void set_dimensions(int x, int y) {
            this->dimensions = {x, y};
        }

        std::vector<int> get_data() const {
            return this->data;
        }

        static const unsigned N = 50;

        friend int operator==(matrix::Matrix &This, matrix::Matrix &other);

        friend std::ostream &operator<<(std::ostream &l, const Matrix &m);

        friend void operator>>(std::istream &l, Matrix &m);

        friend matrix::Matrix &operator*(matrix::Matrix &This, int other);

        friend Matrix &operator+(Matrix &This, Matrix &other);

        friend Matrix &operator-(Matrix &This, Matrix &other);

    private:
        std::vector<int> data;
        std::pair<int, int> dimensions;
    };

    Matrix MZero;
    Matrix MOne;

    Matrix &operator-(Matrix &This, Matrix &other) {
        if (!This.same_dimensions_as(other))
            return MZero;

        Matrix *diff = new Matrix;
        diff->set_dimensions(This.x_dim(), This.y_dim());

        other = other * -1;
        *diff = This + other;
        other = other * -1;
    }

    Matrix &operator+(Matrix &This, Matrix &other) {
        if (!This.same_dimensions_as(other))
            return MZero;

        Matrix *sum = new Matrix;
        sum->set_dimensions(This.x_dim(), This.y_dim());
        int val;
        for (int y = 0; y < This.y_dim(); ++y) {
            for (int x = 0; x < This.x_dim(); ++x) {
                val = This.at(x, y) + other.at(x, y);
                sum->store_at(x, y, val);
            }
        }

        return *sum;
    }

    std::ostream &operator<<(std::ostream &l, const Matrix &m) {
        for (int y = 0; y < m.dimensions.second; ++y) {
            for (int x = 0; x < m.dimensions.first; ++x) {
                l << m.at(x, y) << ' ';
            }
            l << '\n';
        }
        return l;
    }

    void operator>>(std::istream &l, Matrix &m) {
        int _y, _x;
        l >> _y >> _x;

        m.set_dimensions(_x, _y);
        int curr_val;

        for (int i = 0; i < _y; ++i) {
            for (int j = 0; j < _x; ++j) {
                l >> curr_val;
                m.store_at(j, i, curr_val);
            }
        }
    }

    int operator==(matrix::Matrix &This, matrix::Matrix &other) {
        if (This.same_dimensions_as(other)) {
            for (int y = 0; y < This.dimensions.first; ++y) {
                for (int x = 0; x < other.dimensions.second; ++x) {
                    int This_value = This.index(x, y);
                    int other_value = other.index(x, y);
                    if (This_value != other_value)
                        return 0;
                }
            }
            return 1;
        }
        return 0;
    }

    matrix::Matrix &operator*(matrix::Matrix &This, int other) {
        int val;
        for (int y = 0; y < This.y_dim(); ++y) {
            for (int x = 0; x < This.x_dim(); ++x) {
                val = This.at(x, y) * other;
                This.store_at(x, y, val);
            }
        }
        return This;
    }
}

namespace hw_problems {
    void equal_matrix() {
        matrix::Matrix m1, m2;
        std::cin >> m1;
        std::cin >> m2;

        if (m1 == m2) {
            std::cout << "Equal" << '\n';
        } else {
            std::cout << "Not equal" << '\n';
        }
    }

    void sum_matrix() {
        matrix::Matrix a, b, c;
        std::cin >> a;
        std::cin >> b;

        c = a + b;
        std::cout << c;
    }

    void transpose_matrix() {
        matrix::Matrix a, b;
        std::cin >> a;
        b = a.transposed();
        std::cout << b;
    }

    void subtract_matrix() {
        matrix::Matrix a, b, c;
        std::cin >> a;
        std::cin >> b;

        c = a - b;
        std::cout << c;
    }

    void mult_matrix_int() {
        matrix::Matrix a, b;
        int i;
        std::cin >> a;
        std::cin >> i;

        b = a * i;
        std::cout << b;
    }

    void distr_matrix() {
        matrix::Matrix a, b, c, d;
        int i;
        std::cin >> a;
        std::cin >> b;
        std::cin >> i;

        c = (a + b) * i;
        d = a * i + b * i;
        if (c == d)
            std::cout << "Correct.";
        else
            std::cout << "Incorrect.";
    }
}

int main() {
    //    hw_problems::equal_matrix();
    //    hw_problems::sum_matrix();
    hw_problems::transpose_matrix();
    return 0;
}
