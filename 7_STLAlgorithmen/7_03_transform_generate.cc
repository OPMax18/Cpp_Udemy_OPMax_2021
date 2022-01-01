#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

int increment(int i)
{
    return ++i;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    std::vector<int> my_vector_1(10, 0);
    std::vector<int> my_vector_2(10, 0);
    std::vector<int> my_vector_3(10, 0);

    std::iota(my_vector_1.begin(), my_vector_1.end(), 0);

    std::transform(my_vector_1.begin(), my_vector_1.end(), my_vector_2.begin(), increment);

    std::cout << "My my_vector_1: \t";
    for (std::size_t i = 0; i < my_vector_1.size(); ++i)
    {
        std::cout << my_vector_1[i] << "\t";
    }

    std::cout << "\nMy my_vector_2: \t";
    for (std::size_t i = 0; i < my_vector_2.size(); ++i)
    {
        std::cout << my_vector_2[i] << "\t";
    }

    std::transform(my_vector_1.begin(), my_vector_1.end(), my_vector_2.begin(), my_vector_3.begin(), multiply);

    std::cout << "\nMy my_vector_3: \t";
    for (std::size_t i = 0; i < my_vector_3.size(); ++i)
    {
        std::cout << my_vector_3[i] << "\t";
    }

    return 0;
}
