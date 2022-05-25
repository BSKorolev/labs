#include "MathUtils.hpp"

Matrix::Matrix(int n, int m) 
{
    std::cout << "Constructor" << std::endl;
    m_n = n;
    m_m = m;
    m_mat = new double* [m_n];
    for (int i = 0; i < m_n; i++)
        m_mat[i] = new double[m_m];
}
Matrix::~Matrix() 
{
    std::cout << "Destructor" << std::endl;
    for (int i = 0; i < m_n; i++)
        delete[] m_mat[i];
    delete m_mat;
}
Matrix::Matrix(const Matrix& mat) 
{
    std::cout << "Copy constructor" << std::endl;

    m_n = mat.m_n;
    m_m = mat.m_m;

    m_mat = new double* [m_n];
    for (int i = 0; i < m_n; i++)
        m_mat[i] = new double[m_m];

    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            m_mat[i][j] = mat.m_mat[i][j];
}
Matrix& Matrix::operator=(const Matrix& mat) 
{
    std::cout << "Operator =" << std::endl;

    m_n = mat.m_n;
    m_m = mat.m_m;

    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            m_mat[i][j] = mat.m_mat[i][j];

    return *this;
}
Matrix Matrix::operator+(const Matrix& mat) 
{
    std::cout << "operator+" << std::endl;
    Matrix tmp(2, 3);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator+=(const Matrix& mat) 
{
    std::cout << "operator+=" << std::endl;
    Matrix tmp(2, 3);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator*(const Matrix& mat) 
{
    std::cout << "operator*" << std::endl;
    Matrix tmp(m_n, mat.m_m);
    for (int i = 0; i < m_n; i++) 
    {
        for (int j = 0; j < mat.m_m; j++) 
        {
            tmp.m_mat[i][j] = 0;
            for (int k = 0; k < m_m; k++)
                tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
        }
    }
    return tmp;
}
Matrix Matrix::operator-(const Matrix& mat) 
{
    std::cout << "operator-" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator-=(const Matrix& mat) 
{
    std::cout << "operator+=" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
    return tmp;
}
int Matrix::determinant()
{
    std::cout << "determinant" << std::endl;
    int det = 0;
    if (m_n == 2 && m_m == 2) 
    {
        det = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
        return det;
    }
    else if (m_n == 3 && m_m == 3) 
    {
        det = m_mat[0][0] * (m_mat[1][1] * m_mat[2][2] - m_mat[1][2] * m_mat[2][1]) -
            m_mat[0][1] * (m_mat[1][0] * m_mat[2][2] - m_mat[1][2] * m_mat[2][0]) +
            m_mat[0][2] * (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0]);
        return det;
    }
    else {
        std::cout << "Operation not supported" << std::endl;
        return -1;
    }
}
Matrix Matrix::transposition() 
{
    std::cout << "transposition" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[j][i];
    return tmp;
}
Matrix Matrix::inverse() 
{
    std::cout << "inverse" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = 0;
    if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3)) 
    {
        int det = determinant();
        if (det == 0) 
        {
            std::cout << "No inverse matrix, determinant=0" << std::endl;
            return tmp;
        }
        if (m_n == 2) 
        {
            tmp.m_mat[0][0] = m_mat[1][1] / det;
            tmp.m_mat[0][1] = -m_mat[0][1] / det;
            tmp.m_mat[1][0] = -m_mat[1][0] / det;
            tmp.m_mat[1][1] = m_mat[0][0] / det;
        }
        if (m_n == 3) 
        {
            tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / det;
            tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / det;
            tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / det;
            tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / det;
            tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / det;
            tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / det;
            tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / det;
            tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / det;
            tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / det;
        }
    }
    else {
        std::cout << "Operation not supported" << std::endl;
    }
    return tmp;
}

std::istream& operator>>(std::istream& in, Matrix& mat) 
{
    for (int i = 0; i < mat.m_n; i++)
        for (int j = 0; j < mat.m_m; j++)
            in >> mat.m_mat[i][j];
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat) 
{
    out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
    for (int i = 0; i < mat.m_n; i++) 
    {
        for (int j = 0; j < mat.m_m; j++)
            out << mat.m_mat[i][j] << " ";
        out << std::endl;
    }
    return out;
}