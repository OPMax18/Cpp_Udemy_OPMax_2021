#include <iostream>

unsigned long long factorial(unsigned int n)
{
    if (n == 1U)
    {
        return 1U;
    }
    else
    {
        return n * factorial(n - 1U);
    }
}


int main()
{
    unsigned int n = 65U;
    unsigned long long nFac = factorial(n);

    std::cout << "n! = " << nFac << "\n";
    return 0;
}
