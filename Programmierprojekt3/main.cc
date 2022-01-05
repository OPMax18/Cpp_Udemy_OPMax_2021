#include "matrix.h"

int main()
{

    cppmath::Matrix<double> m1(2U, 2U, -1.0);
    m1.print_matrix();
    cppmath::Matrix<double> m2(2U, 2U, 1.0);
    m2.print_matrix();

    // Addition / Subtraction
    std::cout << "addition\n";
    cppmath::Matrix<double> m3 = m1 + m2;
    m3.print_matrix();
    std::cout << "subtraction\n";
    cppmath::Matrix<double> m4 = m1 - m2;
    m4.print_matrix();

    cppmath::Matrix<double> m5 = m2 * 2.0;
    std::cout << "scalar multiplication\n";
    m5.print_matrix();
    m5 = m2 / 2.0;
    std::cout << "scalar division\n";
    m5.print_matrix();

    cppmath::Matrix<double> m6 = m1 * m5;
    std::cout << "matrix multiplication\n";
    m6.print_matrix();
    m6 *= m2;
    std::cout << "matrix multiplication\n";
    m6.print_matrix();

    return 0;
}
