#include "matrix.hpp"
#include <cassert>
#include <string>
#include <sstream> 

void RowsColsTest() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m(rows, cols);
    assert((m.getRows() == 5) && (m.getColumns() == 3));
}

void AccessToElementTest() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m(rows, cols);
    assert(0 == m[2][2]);
}

void SetElemTest() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m(rows, cols);
    m[0][2] = 5;
    assert(m[0][2] == 5);
}

void CatchOutofRangeTest() {
    const size_t rows = 5;
    const size_t cols = 3;
    Matrix m(rows, cols);
    bool flag = false;
    try{
        m[5][5] = 5;
    }
    catch(std::out_of_range) {
        flag = true;
    }
    assert(flag == true);
}

void ScalarMultTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            m[i][j] = 3;
    m *= 2;
    assert(m[2][2] == 6);
}

void MatrixSumTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            m1[i][j] = 3;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            m2[i][j] = 10;
    Matrix res = m1 + m2;
    bool flag = true;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if (res[i][j] != 13) flag = false;
    assert(flag == true);
}

void IsEqualTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    assert(m1 == m2);
}

void IsNonEqualTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    m2[4][4] = 3;
    assert(m1 != m2);
}

void StreamTest() {
    const size_t rows = 5;
    const size_t cols = 5;
    Matrix m1(rows, cols);
    std::stringstream PrintStream;
    PrintStream << m1 << std::endl;
    int ZeroCnt = 0;
    std::string PrintedMatrix = PrintStream.str();
    for (char& c : PrintedMatrix) {
        if (c == '0') {
            ZeroCnt++;
        }
    }
    assert(ZeroCnt == rows * cols);
}

int main() {
    RowsColsTest();
    AccessToElementTest();
    SetElemTest();
    CatchOutofRangeTest();
    ScalarMultTest();
    MatrixSumTest();
    IsEqualTest();
    IsNonEqualTest();
    StreamTest();
    
    std::cout << "Success!\n";
}