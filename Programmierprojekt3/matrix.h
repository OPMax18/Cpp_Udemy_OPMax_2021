#pragma once
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace cppmath
{

template <typename T_Data>
class Matrix
{
public:
    using matrix_data_type = std::vector<std::vector<T_Data>>;

    Matrix() = delete;
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, const T_Data& value);
    ~Matrix();

    Matrix<T_Data> operator+(const Matrix<T_Data>& rhs_matrix);
    Matrix<T_Data>& operator+=(const Matrix<T_Data>& rhs_matrix);
    Matrix<T_Data> operator-(const Matrix<T_Data>& rhs_matrix);
    Matrix<T_Data>& operator-=(const Matrix<T_Data>& rhs_matrix);

    Matrix<T_Data> operator*(const T_Data& scalar);
    Matrix<T_Data>& operator*=(const T_Data& scalar);
    Matrix<T_Data> operator/(const T_Data& scalar);
    Matrix<T_Data>& operator/=(const T_Data& scalar);

    Matrix<T_Data> operator*(const Matrix<T_Data>& rhs_matrix);
    Matrix<T_Data>& operator*=(const Matrix<T_Data>& rhs_matrix);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    matrix_data_type m_data;
};

template <typename T_Data>
Matrix<T_Data>::Matrix(std::size_t rows, std::size_t cols)
    : m_rows(rows), m_cols(cols), m_data(m_rows, std::vector<T_Data>(m_cols, T_Data()))
{
}

template <typename T_Data>
Matrix<T_Data>::Matrix(std::size_t rows, std::size_t cols, const T_Data& value)
    : m_rows(rows), m_cols(cols), m_data(rows, std::vector(cols, value))
{
}

template <typename T_Data>
Matrix<T_Data>::~Matrix()
{
}

template <typename T_Data>
Matrix<T_Data> Matrix<T_Data>::operator+(const Matrix<T_Data>& rhs_matrix)
{
    Matrix<T_Data> matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs_matrix.m_data[i].begin(),
                       matrix.m_data[i].begin(),
                       std::plus<T_Data>());
    }
    return matrix;
}

template <typename T_Data>
Matrix<T_Data>& Matrix<T_Data>::operator+=(const Matrix<T_Data>& rhs_matrix)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs_matrix.m_data[i].begin(),
                       m_data[i].begin(),
                       std::plus<T_Data>());
    }
    return *this;
}

template <typename T_Data>
Matrix<T_Data> Matrix<T_Data>::operator-(const Matrix<T_Data>& rhs_matrix)
{
    Matrix<T_Data> matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs_matrix.m_data[i].begin(),
                       matrix.m_data[i].begin(),
                       std::minus<T_Data>());
    }
    return matrix;
}

template <typename T_Data>
Matrix<T_Data>& Matrix<T_Data>::operator-=(const Matrix<T_Data>& rhs_matrix)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs_matrix.m_data[i].begin(),
                       m_data[i].begin(),
                       std::minus<T_Data>());
    }
    return *this;
}

template <typename T_Data>
Matrix<T_Data> Matrix<T_Data>::operator*(const T_Data& scalar)
{
    Matrix<T_Data> matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), matrix.m_data[i].begin(), [&scalar](const T_Data val) {
            return val * scalar;
        });
    }
    return matrix;
}

template <typename T_Data>
Matrix<T_Data>& Matrix<T_Data>::operator*=(const T_Data& scalar)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), m_data[i].begin(), [&scalar](const T_Data val) {
            return val * scalar;
        });
    }
    return *this;
}

template <typename T_Data>
Matrix<T_Data> Matrix<T_Data>::operator/(const T_Data& scalar)
{
    Matrix<T_Data> matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), matrix.m_data[i].begin(), [&scalar](const T_Data val) {
            return val / scalar;
        });
    }
    return matrix;
}

template <typename T_Data>
Matrix<T_Data>& Matrix<T_Data>::operator/=(const T_Data& scalar)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), m_data[i].begin(), [&scalar](const T_Data val) {
            return val / scalar;
        });
    }
    return *this;
}

template <typename T_Data>
Matrix<T_Data> Matrix<T_Data>::operator*(const Matrix<T_Data>& rhs_matrix)
{
    Matrix<T_Data> matrix(m_rows, rhs_matrix.m_cols);

    for (std::size_t i = 0; i != m_rows; ++i)
    {
        for (std::size_t j = 0; j != rhs_matrix.m_cols; ++j)
        {
            for (std::size_t k = 0; k != rhs_matrix.m_rows; ++k)
            {
                matrix.m_data[i][j] = matrix.m_data[i][j] + m_data[i][k] * rhs_matrix.m_data[k][j];
            }
        }
    }

    return matrix;
}

template <typename T_Data>
Matrix<T_Data>& Matrix<T_Data>::operator*=(const Matrix<T_Data>& rhs_matrix)
{

    *this = (*this) * rhs_matrix;

    return *this;
}


template <typename T_Data>
void Matrix<T_Data>::print_matrix() const
{
    std::cout << "Matrix \n";
    for (auto row : m_data)
    {
        for (auto value : row)
        {
            std::cout << value << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

template <typename T_Data>
std::size_t Matrix<T_Data>::num_rows() const
{
    return m_rows;
}

template <typename T_Data>
std::size_t Matrix<T_Data>::num_cols() const
{
    return m_cols;
}

} // namespace cppmath
