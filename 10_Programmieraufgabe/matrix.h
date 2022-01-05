#pragma once
#include <iostream>

class Matrix
{
public:
    Matrix();
    Matrix(const double& value_1_1, const double& value_2_1, const double& value_1_2, const double& value_2_2);
    ~Matrix();

    Matrix operator+(const Matrix& rhs_matrix);
    Matrix& operator+=(const Matrix& rhs_matrix);
    Matrix operator-(const Matrix& rhs_matrix);
    Matrix& operator-=(const Matrix& rhs_matrix);

    Matrix operator*(const double& scalar);
    Matrix& operator*=(const double& scalar);
    Matrix operator/(const double& scalar);
    Matrix& operator/=(const double& scalar);

    Matrix operator*(const Matrix& rhs_matrix);
    Matrix& operator*=(const Matrix& rhs_matrix);

    void print_matrix() const;

    double get_1_1() const;
    double get_2_1() const;
    double get_1_2() const;
    double get_2_2() const;

    void set_1_1(const double& value);
    void set_2_1(const double& value);
    void set_1_2(const double& value);
    void set_2_2(const double& value);

private:
    double m_1_1;
    double m_2_1;
    double m_1_2;
    double m_2_2;
};
