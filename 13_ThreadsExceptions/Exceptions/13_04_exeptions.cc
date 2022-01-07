#include <iostream>

double div(double a, double b)
{
    if (b == 0.0)
    {
        // 1. throw
        throw "Division by zero!";
    }
    return a / b;
}

int main()
{
    double x = 10.0;
    double y = 0.0;
    // 2. try
    try
    {
        double z = div(x, y);

        std::cout << "z: \t" << z << "\n";
    }
    // 3. catch
    catch (const char* msg)
    {
        std::cerr << msg << "\n";
        // oder auch alternative bieten
        // z = 0.0;
    }

    return 0;
}
