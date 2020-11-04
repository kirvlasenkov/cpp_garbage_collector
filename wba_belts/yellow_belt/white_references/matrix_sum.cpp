#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>


// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:

    Matrix() {
        num_cols = 0;
        num_rows = 0;
    }

    Matrix(int new_rows, int new_cols) { // +
        if (new_cols < 0 || new_rows < 0) {
            throw std::out_of_range("matrix size mustn't be negative!!!");
        }

        Reset(new_rows, new_cols);

    }

    void Reset(int new_rows, int new_cols) { // +
        if (new_cols < 0 || new_rows < 0) {
            throw std::out_of_range("matrix size mustn't be negative!!!");
        }
        if (new_cols == 0 || new_rows == 0)
            new_rows = new_cols = 0;
        
        num_rows = new_rows;
        num_cols = new_cols;
        MATRIX.assign(new_rows, std::vector<int>(new_cols));
    }

    int At(int row_coord, int col_coord) const { // +
        if (row_coord > num_rows || col_coord > num_cols) {
            throw std::out_of_range("Wrong coordinate");
        }
        return MATRIX.at(row_coord).at(col_coord); // FIXIT
    }

    int &At(int row_coord, int col_coord) { // +
        if (row_coord > num_rows || col_coord > num_cols) {
            throw std::out_of_range("Wrong coordinate");
        }
        return MATRIX.at(row_coord).at(col_coord);
    }

    // getter block
    int GetNumRows() const { // +
        return num_rows;
    }

    int GetNumColumns() const { // +
        return num_cols;
    }


private:
    int num_rows;
    int num_cols;
    std::vector<std::vector<int>> MATRIX;
};

std::istream &operator>>(std::istream &stream, Matrix &matrix) {
    if (stream) {
        int num_rows, num_cols;
        stream >> num_rows >> num_cols;
        matrix.Reset(num_rows, num_cols);

        for (int i = 0; i < matrix.GetNumRows(); ++i) {
            for (int j = 0; j < matrix.GetNumColumns(); ++j) {
                stream >> matrix.At(i, j);
            }
        }
    }

    return stream;
}

bool operator==(const Matrix &lhs, const Matrix &rhs) {
    bool flag = true;

    if ((lhs.GetNumColumns() == 0 || lhs.GetNumRows() == 0) &&
        (rhs.GetNumRows() == 0 || rhs.GetNumColumns() == 0)) {
        return true;
    }

    if (lhs.GetNumColumns() == rhs.GetNumColumns() &&
        lhs.GetNumRows() == rhs.GetNumRows()) {

        for (int i = 0; i < lhs.GetNumRows(); ++i) {
            for (int j = 0; j < rhs.GetNumColumns(); ++j) {
                if (lhs.At(i, j) != rhs.At(i, j)) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }

    return true;
}


std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;

    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream << matrix.At(i, j) << " ";
        }
        stream << std::endl;
    }

    return stream;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns() &&
        lhs.GetNumRows() != rhs.GetNumRows()) {
            throw std::invalid_argument("Wrong matrices's sizes");
        }


    Matrix answer(lhs.GetNumRows(), lhs.GetNumColumns());


    for (int i = 0; i < answer.GetNumRows(); ++i) {
        for (int j = 0; j < answer.GetNumColumns(); ++j) {
            answer.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return answer;
}

int main() {
    try {
        Matrix one;
        Matrix two;

        std::cin >> one >> two;
        std::cout << (one == two) << std::endl;
    } catch (std:: exception &ex) {
        std::cout << ex.what();
    }
    return 0;
}
