#include "matrix.hpp"
#include <stdexcept>

MatrixProxy::MatrixProxy(int* const &matrix, int row, int MaxColumns) {
    ProxyMatrix_ = matrix;
    CurrentRow_ = row;
    MaxColumns_ = MaxColumns;
}

int& MatrixProxy::operator[](const int column) {
    if (column >= MaxColumns_) {
        throw std::out_of_range("");
    }
    CurrentCol_ = column;
    return ProxyMatrix_[CurrentRow_ * MaxColumns_ + column];
}

MatrixProxy Matrix::operator[](const int row) {
    if (row >= MatrixRows_) {
        throw std::out_of_range("");
    }
    MatrixProxy proxy(MatrixPtr_, row, MatrixColumns_);
    return proxy;
}

MatrixProxy::~MatrixProxy() {}

Matrix::Matrix(const int rows, const int columns) {
    MatrixPtr_ = new int[rows * columns];
    MatrixRows_ = rows;
    MatrixColumns_ = columns;
    for(int i = 0; i < MatrixRows_ * MatrixColumns_; i++) {
        MatrixPtr_[i] = 0;
    }
}

Matrix::~Matrix() {
    delete[] MatrixPtr_;
    MatrixPtr_ = nullptr;
}

int Matrix::getRows() const{
    return MatrixRows_;
}

int Matrix::getColumns() const{
    return MatrixColumns_;
}

Matrix& Matrix::operator*=(const int other) {
    for (int i = 0; i < MatrixRows_ * MatrixColumns_; i++) {
        this->MatrixPtr_[i] = this->MatrixPtr_[i] * other;
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) {
    if ((MatrixRows_ != other.getRows()) || (MatrixColumns_ != other.getColumns())) {
        throw std::invalid_argument("Unmatching dimensions");
    }
    Matrix tmp(MatrixRows_, MatrixColumns_);
    for (int i = 0; i < MatrixRows_; i++)
        for (int j = 0; j < MatrixColumns_; j++)
            tmp.MatrixPtr_[i * MatrixColumns_ + j] = this->MatrixPtr_[i * MatrixColumns_ + j] + other.MatrixPtr_[i * MatrixColumns_ + j];
    return tmp;
}

bool Matrix::operator==(const Matrix &other) {
    if ((MatrixRows_ != other.getRows()) || (MatrixColumns_ != other.getColumns())) {
        throw std::invalid_argument("Unmatching dimensions");
    }
    bool flag = true;
    for (int i = 0; i < MatrixRows_; i++)
        for (int j = 0; j < MatrixColumns_; j++)
            if (MatrixPtr_[i * MatrixColumns_ + j] != other.MatrixPtr_[i * MatrixColumns_ + j]) flag = false;
    return flag;
}

bool Matrix::operator!=(const Matrix &other) {
    return !((*this) == other);
}

std::ostream& operator<<(std::ostream& ostream, const Matrix& matrix) {
    for (int i = 0; i < matrix.MatrixRows_; i++) {
        for (int j = 0; j < matrix.MatrixColumns_; j++) {
            ostream << matrix.MatrixPtr_[i * matrix.MatrixColumns_ + j] << " ";
        }
        ostream << "\n";
    }
    return ostream;
}
