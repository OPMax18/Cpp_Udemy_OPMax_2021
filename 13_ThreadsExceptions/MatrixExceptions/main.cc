#include <iostream>

#include "matrix.h"

int main()
//int your_main()
{
    cppmath::Matrix<double> m1(2, 2, -1.3);
    std::cout << "M1: " << &m1 << std::endl;
    m1.print_matrix();

    cppmath::Matrix<double> m2(3, 2, -1.3);
    std::cout << "M2: " << &m2 << std::endl;
    m2.print_matrix();


    // // Copy Constructor
    // cppmath::Matrix<double> m2(m1);
    // std::cout << "M2 (copy from M1): " << &m2 << std::endl;
    // m2.print_matrix();

    // // Copy Assignment
    // cppmath::Matrix<double> m3(2, 2);
    // m3 = m1;
    // std::cout << "M3 (copy from M1): " << &m3 << std::endl;
    // m3.print_matrix();

    // Some operations
    try
    {
        cppmath::Matrix<double> m3 = m2 + m1;
        std::cout << "M3: " << &m3 << std::endl;
        m3.print_matrix();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        cppmath::Matrix<double> m4 = m2 / 0.0;
        std::cout << "M4: " << &m4 << std::endl;
        m4.print_matrix();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
