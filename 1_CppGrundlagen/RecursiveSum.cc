#include <iostream>

unsigned int sum(unsigned int n)
{
    if (n == 1U)
    {
        return 1U;
    }
    else
    {
        return n + sum(n - 1U);
    }
}

int main()
{
    unsigned int n = 5U;
    unsigned int nSum = sum(n);

    std::cout << "sum from 1 to n = " << nSum << "\n";
    return 0;
}
