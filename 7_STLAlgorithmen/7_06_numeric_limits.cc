#include <iostream>
#include <limits>
#include <math.h>
#include <vector>

template <typename T>
void print_min_max()
{
    std::cout << "min: \t" << std::dec << std::numeric_limits<T>::min() << "\tmax: \t" << std::dec
              << std::numeric_limits<T>::max() << "\n";
}

bool equal(double x, double y)
{
    return x == y;
}

bool almost_equal(double x, double y)
{
    return std::abs(x - y) <= std::numeric_limits<double>::epsilon();
}

int main()
{
    print_min_max<short>();
    print_min_max<int>();
    print_min_max<float>();
    print_min_max<double>();

    double d1 = 0.2;
    double d2 = 1 / (std::sqrt(5) * std::sqrt(5));

    std::cout << "d1: \t" << d1 << "\n";
    std::cout << "d2: \t" << d2 << "\n";

    std::cout.precision(17);
    std::cout << "precision d1: \t" << d1 << "\n";
    std::cout << "precision d2: \t" << d2 << "\n";

    std::cout << "d1 == d2? \t" << std::boolalpha << equal(d1, d2) << "\n";
    std::cout << "d1 ~= d2? \t" << std::boolalpha << almost_equal(d1, d2) << "\n";

    return 0;
}
