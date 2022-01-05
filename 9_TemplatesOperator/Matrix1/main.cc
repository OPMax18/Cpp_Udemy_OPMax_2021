#include "matrix.h"

int main()
{

    Matrix<double> m1(1.01, 2.02, 3.03, 4.04);
    Matrix<double> m2_;
    Matrix<double> m2(-1.01, -2.02, -3.03, -4.04);

    std::cout << "Matrix m1 \n";
    m1.print_matrix();
    std::cout << "Matrix m2_ \n";
    m2_.print_matrix();

    return 0;
}
