#include "matrix.h"

int main()
{

    Matrix m1(1.01, 2.02, 3.03, 4.04);
    Matrix m2(-1.01, -2.02, -3.03, -4.04);

    std::cout << "Matrix m1: \n";
    m1.print_matrix();
    std::cout << "Matrix m2: \n";
    m2.print_matrix();

    auto m3 = m1 + m2;
    std::cout << "Matrix m3: \n";
    m3.print_matrix();
    m1 += m2;
    std::cout << "Matrix m1: \n";
    m1.print_matrix();

    auto m4 = m2 + m2;
    std::cout << "Matrix m4: \n";
    m4.print_matrix();
    m1 -= m4;
    std::cout << "Matrix m1: \n";
    m1.print_matrix();
    auto m5 = m1 - m4;
    std::cout << "Matrix m5: \n";
    m5.print_matrix();


    return 0;
}
