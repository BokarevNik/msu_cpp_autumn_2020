#include <iostream>
#pragma once

class MatrixProxy
{
private:
    int* ProxyMatrix_ = nullptr;;
    int CurrentRow_ = 0;
    int CurrentCol_ = 0;
    int MaxColumns_ = 0;
public:
    MatrixProxy(int* const &matrix, int row, int MaxColumns);
    int& operator[](const int i);
    ~MatrixProxy();
};

class Matrix
{
    friend std::ostream& operator<<(std::ostream& ostream, const Matrix &matrix);
private:
    int* MatrixPtr_ = nullptr;
    int MatrixColumns_ = 0;
    int MatrixRows_ = 0;
public:
    Matrix(const int rows, const int columns);
    int getRows() const;
    int getColumns() const;
    Matrix& operator*=(const int other);
    int& operator=(const int num);
    Matrix operator+(const Matrix &other);
    MatrixProxy operator[](int row);
    bool operator==(const Matrix &other);
    bool operator!=(const Matrix &other);
    ~Matrix();
};

std::ostream& operator<<(std::ostream& ostream, const Matrix &matrix);