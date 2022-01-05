#include "matrix.h"

int main()
//int your_main()
{
    Matrix m1(1.0, 2.0, 2.0, 1.0);
    std::cout << "Matrix m1: \n";
    m1.print_matrix();

    Matrix m2(1.0, 0.0, 0.0, 1.0);
    std::cout << "Matrix m2: \n";
    m2.print_matrix();

    Matrix m3 = m1 + m2;
    std::cout << "Matrix m3 = m1 + m2: \n";
    m3.print_matrix();

    m3 -= m2;
    std::cout << "Matrix m3 -=m2: \n";
    m3.print_matrix();

    m3 *= 3.0;
    std::cout << "Matrix m3 *= 3.0: \n";
    m3.print_matrix();

    m3 /= 3.0;
    std::cout << "Matrix m3 /= 3.0: \n";
    m3.print_matrix();

    m3 *= m2;
    std::cout << "Matrix m3 *= m2: \n";
    m3.print_matrix();

    return 0;
}
