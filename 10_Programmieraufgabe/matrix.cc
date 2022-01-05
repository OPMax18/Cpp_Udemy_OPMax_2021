#include "matrix.h"


Matrix::Matrix() : m_1_1(0U), m_2_1(0U), m_1_2(0U), m_2_2(0U)
{
}

Matrix::Matrix(const double& value_1_1, const double& value_2_1, const double& value_1_2, const double& value_2_2)
    : m_1_1(value_1_1), m_2_1(value_2_1), m_1_2(value_1_2), m_2_2(value_2_2)
{
}

Matrix::~Matrix()
{
}

Matrix Matrix::operator+(const Matrix& rhs_matrix)
{
    Matrix matrix;
    matrix.set_1_1(this->get_1_1() + rhs_matrix.get_1_1());
    matrix.set_2_1(this->get_2_1() + rhs_matrix.get_2_1());
    matrix.set_1_2(this->get_1_2() + rhs_matrix.get_1_2());
    matrix.set_2_2(this->get_2_2() + rhs_matrix.get_2_2());
    return matrix;
}

Matrix& Matrix::operator+=(const Matrix& rhs_matrix)
{
    this->set_1_1(this->get_1_1() + rhs_matrix.get_1_1());
    this->set_2_1(this->get_2_1() + rhs_matrix.get_2_1());
    this->set_1_2(this->get_1_2() + rhs_matrix.get_1_2());
    this->set_2_2(this->get_2_2() + rhs_matrix.get_2_2());
    return *this;
}

Matrix Matrix::operator-(const Matrix& rhs_matrix)
{
    Matrix matrix;
    matrix.set_1_1(this->get_1_1() - rhs_matrix.get_1_1());
    matrix.set_2_1(this->get_2_1() - rhs_matrix.get_2_1());
    matrix.set_1_2(this->get_1_2() - rhs_matrix.get_1_2());
    matrix.set_2_2(this->get_2_2() - rhs_matrix.get_2_2());
    return matrix;
}

Matrix& Matrix::operator-=(const Matrix& rhs_matrix)
{
    this->set_1_1(this->get_1_1() - rhs_matrix.get_1_1());
    this->set_2_1(this->get_2_1() - rhs_matrix.get_2_1());
    this->set_1_2(this->get_1_2() - rhs_matrix.get_1_2());
    this->set_2_2(this->get_2_2() - rhs_matrix.get_2_2());
    return *this;
}


Matrix Matrix::operator*(const double& scalar)
{
    Matrix matrix;
    matrix.set_1_1(get_1_1() * scalar);
    matrix.set_2_1(get_2_1() * scalar);
    matrix.set_1_2(get_1_2() * scalar);
    matrix.set_2_2(get_2_2() * scalar);
    return matrix;
}

Matrix& Matrix::operator*=(const double& scalar)
{
    set_1_1(get_1_1() * scalar);
    set_2_1(get_2_1() * scalar);
    set_1_2(get_1_2() * scalar);
    set_2_2(get_2_2() * scalar);
    return *this;
}

Matrix Matrix::operator/(const double& scalar)
{
    Matrix matrix;
    matrix.set_1_1(get_1_1() / scalar);
    matrix.set_2_1(get_2_1() / scalar);
    matrix.set_1_2(get_1_2() / scalar);
    matrix.set_2_2(get_2_2() / scalar);
    return matrix;
}

Matrix& Matrix::operator/=(const double& scalar)
{
    set_1_1(get_1_1() / scalar);
    set_2_1(get_2_1() / scalar);
    set_1_2(get_1_2() / scalar);
    set_2_2(get_2_2() / scalar);
    return *this;
}

Matrix Matrix::operator*(const Matrix& rhs_matrix)
{
    Matrix matrix;
    matrix.set_1_1(get_1_1() * rhs_matrix.get_1_1() + get_1_2() * rhs_matrix.get_2_1());
    matrix.set_2_1(get_2_1() * rhs_matrix.get_1_1() + get_2_2() * rhs_matrix.get_2_1());
    matrix.set_1_2(get_1_1() * rhs_matrix.get_1_2() + get_1_2() * rhs_matrix.get_2_2());
    matrix.set_2_2(get_2_1() * rhs_matrix.get_1_2() + get_2_2() * rhs_matrix.get_2_2());
    return matrix;
}

Matrix& Matrix::operator*=(const Matrix& rhs_matrix)
{
    Matrix matrix;
    matrix.set_1_1(get_1_1() * rhs_matrix.get_1_1() + get_1_2() * rhs_matrix.get_2_1());
    matrix.set_2_1(get_2_1() * rhs_matrix.get_1_1() + get_2_2() * rhs_matrix.get_2_1());
    matrix.set_1_2(get_1_1() * rhs_matrix.get_1_2() + get_1_2() * rhs_matrix.get_2_2());
    matrix.set_2_2(get_2_1() * rhs_matrix.get_1_2() + get_2_2() * rhs_matrix.get_2_2());
    *this = matrix;

    // Oder schneller:
    // *this = (*this) * rhs_matrix;

    return *this;
}


void Matrix::print_matrix() const
{
    std::cout << "Matrix \n";
    std::cout << m_1_1 << "\t" << m_1_2 << "\n";
    std::cout << m_2_1 << "\t" << m_2_2 << "\n";
    std::cout << "\n";
}

double Matrix::get_1_1() const
{
    return m_1_1;
}

double Matrix::get_2_1() const
{
    return m_2_1;
}
double Matrix::get_1_2() const
{
    return m_1_2;
}

double Matrix::get_2_2() const
{
    return m_2_2;
}

void Matrix::set_1_1(const double& value)
{
    m_1_1 = value;
}

void Matrix::set_2_1(const double& value)
{
    m_2_1 = value;
}

void Matrix::set_1_2(const double& value)
{
    m_1_2 = value;
}

void Matrix::set_2_2(const double& value)
{
    m_2_2 = value;
}
