#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void print_double_vector(const std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

bool sort_descending(const double& i, const double& j)
{
    return i > j;
}

bool sort_ascending(const double& i, const double& j)
{
    return i < j;
}

int main()
{
    std::vector<double> myVector(10, 5);

    std::iota(myVector.begin(), myVector.end(), 3.5);
    print_double_vector(myVector);

    std::sort(myVector.begin(), myVector.end(), sort_descending);
    print_double_vector(myVector);

    std::sort(myVector.begin(), myVector.end(), sort_ascending);
    print_double_vector(myVector);

    // Ascending is default
    std::sort(myVector.begin(), myVector.end());
    print_double_vector(myVector);

    return 0;
}
