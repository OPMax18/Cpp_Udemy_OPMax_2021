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


int main()
{
    std::vector<double> myVector(10, 5);
    print_double_vector(myVector);

    std::fill(myVector.begin(), myVector.end(), 1.0);
    print_double_vector(myVector);

    std::iota(myVector.begin() + 2, myVector.end(), 3.5);
    print_double_vector(myVector);

    std::vector<double>::iterator it = myVector.begin();
    std::cout << *it << "\n";
    // // direkte Abfrage von it geht nicht!
    // std::cout << it << "\n";
    ++it;
    *it = -(*it);
    std::cout << *it << "\n";

    return 0;
}
