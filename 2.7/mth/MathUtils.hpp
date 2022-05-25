#pragma once
#include <iostream>

class Matrix {
public:
    Matrix(int n, int m);
    Matrix(const Matrix& mat);
    Matrix& operator=(const Matrix& mat);
    Matrix operator+(const Matrix& mat);
    Matrix operator+=(const Matrix& mat);
    Matrix operator*(const Matrix& mat);
    Matrix operator-(const Matrix& mat);
    Matrix operator-=(const Matrix& mat); 
    int determinant();
    Matrix transposition();
    Matrix inverse();
    ~Matrix();

    friend std::istream& operator>>(std::istream& os, Matrix& mat);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

private:
    int m_n, m_m;
    double** m_mat;
};
