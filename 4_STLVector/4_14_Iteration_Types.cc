#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void print_int_vector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{

    std::vector<int> myVector(4, 1U);
    std::iota(myVector.begin(), myVector.end(), 1U);
    print_int_vector(myVector);

    for (auto& value : myVector)
    {
        value *= -1U;
    }

    for (auto it = myVector.begin(); it != myVector.end(); ++it)
    {
        std::cout << "Vector: " << *it << "\n";
    }

    return 0;
}
