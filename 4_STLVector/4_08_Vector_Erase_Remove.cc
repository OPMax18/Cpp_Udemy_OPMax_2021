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

bool is_odd(const int& value)
{
    return (value % 2U);
}

int main()
{
    std::vector<int> myVector(10U, 5U);

    std::iota(myVector.begin(), myVector.end(), 1U);
    print_int_vector(myVector);

    // remove verschiebt die zu löschenden Einträge nur ans Ende
    // und gibt einen Iterator auf den ersten zu löschenden Wert aus
    std::vector<int>::iterator start_erasing_it = std::remove(myVector.begin(), myVector.end(), 2U);
    myVector.erase(start_erasing_it, myVector.end());
    print_int_vector(myVector);

    std::vector<int>::iterator start_remove_if_it = std::remove_if(myVector.begin(), myVector.end(), is_odd);
    myVector.erase(start_remove_if_it, myVector.end());
    print_int_vector(myVector);

    // better
    std::iota(myVector.begin(), myVector.end(), 1U);
    myVector.erase(std::remove_if(myVector.begin(), myVector.end(), is_odd), myVector.end());
    print_int_vector(myVector);

    return 0;
}
