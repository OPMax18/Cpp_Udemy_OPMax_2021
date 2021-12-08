#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int max(const int& a, const int& b)
{
    return a > b ? a : b;
}

double max(const double& a, const double& b)
{
    return a > b ? a : b;
}

int main()
{
    int num1 = 4;
    int num2 = 0;

    double num3 = 10.0;
    double num4 = 10.5;

    cout << "max int: " << max(num1, num2) << "\n";
    cout << "max int: " << max(num3, num4) << "\n";

    return 0;
}
