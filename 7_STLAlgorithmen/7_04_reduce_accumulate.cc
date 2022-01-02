#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

void print_int_vector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
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

    std::iota(my_vector_1.begin(), my_vector_1.end(), 1);

    std::cout << "My my_vector_1: \n";
    print_int_vector(my_vector_1);

    // reduce
    auto result_1 = std::reduce(my_vector_1.begin(), my_vector_1.end());
    std::cout << "My my_vector_1 result of reduce : \t" << result_1 << "\n";

    // accumulate
    auto result_2 = std::accumulate(my_vector_1.begin(), my_vector_1.end(), 0U);
    std::cout << "My my_vector_1 result of accumulate 1 : \t" << result_2 << "\n";

    auto result_3 = std::accumulate(my_vector_1.begin(), my_vector_1.end(), 1U, multiply);
    std::cout << "My my_vector_1 result of accumulate 2 : \t" << result_3 << "\n";

    return 0;
}
