#pragma once
#include <iostream>

template <typename T_Data>
class Matrix
{
public:
    Matrix<T_Data>();
    Matrix<T_Data>(const T_Data& value_1_1, const T_Data& value_2_1, const T_Data& value_1_2, const T_Data& value_2_2);
    ~Matrix<T_Data>();

    void print_matrix() const;

    T_Data get_1_1() const;
    T_Data get_2_1() const;
    T_Data get_1_2() const;
    T_Data get_2_2() const;

    void set_1_1(const T_Data& value);
    void set_2_1(const T_Data& value);
    void set_1_2(const T_Data& value);
    void set_2_2(const T_Data& value);

private:
    T_Data m_1_1;
    T_Data m_2_1;
    T_Data m_1_2;
    T_Data m_2_2;
};

template <typename T_Data>
Matrix<T_Data>::Matrix() : m_1_1(0U), m_2_1(0U), m_1_2(0U), m_2_2(0U)
{
}
template <typename T_Data>
Matrix<T_Data>::Matrix(const T_Data& value_1_1,
                       const T_Data& value_2_1,
                       const T_Data& value_1_2,
                       const T_Data& value_2_2)
    : m_1_1(value_1_1), m_2_1(value_2_1), m_1_2(value_1_2), m_2_2(value_2_2)
{
}

template <typename T_Data>
Matrix<T_Data>::~Matrix()
{
}

template <typename T_Data>
void Matrix<T_Data>::print_matrix() const
{
    std::cout << "Matrix \n";
    // std::cout << "Matrixwert [1,1]: " << m_1_1 << "\n";
    // std::cout << "Matrixwert [2,1]: " << m_2_1 << "\n";
    // std::cout << "Matrixwert [1,2]: " << m_1_2 << "\n";
    // std::cout << "Matrixwert [2,2]: " << m_2_2 << "\n";
    // std::cout << "\n";

    std::cout << m_1_1 << "\t" << m_1_2 << "\n";
    std::cout << m_2_1 << "\t" << m_2_2 << "\n";
    std::cout << "\n";
}

template <typename T_Data>
T_Data Matrix<T_Data>::get_1_1() const
{
    return m_1_1;
}

template <typename T_Data>
T_Data Matrix<T_Data>::get_2_1() const
{
    return m_2_1;
}

template <typename T_Data>
T_Data Matrix<T_Data>::get_1_2() const
{
    return m_1_2;
}

template <typename T_Data>
T_Data Matrix<T_Data>::get_2_2() const
{
    return m_2_2;
}


template <typename T_Data>
void Matrix<T_Data>::set_1_1(const T_Data& value)
{
    m_1_1 = value;
}

template <typename T_Data>
void Matrix<T_Data>::set_2_1(const T_Data& value)
{
    m_2_1 = value;
}

template <typename T_Data>
void Matrix<T_Data>::set_1_2(const T_Data& value)
{
    m_1_2 = value;
}

template <typename T_Data>
void Matrix<T_Data>::set_2_2(const T_Data& value)
{
    m_2_2 = value;
}
