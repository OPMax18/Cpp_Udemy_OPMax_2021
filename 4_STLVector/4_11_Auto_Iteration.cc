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
    // auto deduziert nur den Datentypen, keine Referenz, kein const oder volatile
    // 1: auto val :vec         => int val :vec
    // 2: auto& val :vec        => int& val :vec
    // 3: const auto val :vec   => const int val :vec
    // 4: const auto& val :vec  => const int& val :vec

    std::vector<int> myVector(10U, 5U);

    std::iota(myVector.begin(), myVector.end(), 1U);
    print_int_vector(myVector);

    std::vector<int>::const_iterator it = myVector.begin();
    auto it2 = myVector.begin();

    for (auto it3 = myVector.begin(); it3 != myVector.end(); ++it3)
    {
        std::cout << *it3 << "\n";
    }

    //For-each based loop
    for (const int& val : myVector)
    {
        std::cout << val << "\n";
    }

    return 0;
}
