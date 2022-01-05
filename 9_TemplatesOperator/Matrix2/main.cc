#include "matrix.h"

int main()
{

    Matrix m1(1.01, 2.02, 3.03, 4.04);
    Matrix<double> m2;

    m1.print_matrix();
    m2.print_matrix();

    Matrix<double> m3 = m1 + m2;
    m1 += m2;

    return 0;
}
