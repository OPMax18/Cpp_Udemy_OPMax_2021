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

bool replace_even(const int a)
{
    return (a % 2 == 0);
}

int main()
{
    std::vector<int> my_vector_1(10, 0);
    std::vector<int> my_vector_2(10, 0);
    std::vector<int> my_vector_3(10, 0);

    std::iota(my_vector_1.begin(), my_vector_1.end(), 1);

    std::cout << "My my_vector_1: \n";
    print_int_vector(my_vector_1);

    // replace
    std::replace(my_vector_1.begin(), my_vector_1.end(), 2, 17);
    std::cout << "My my_vector_1 result of replace : \n";
    print_int_vector(my_vector_1);

    std::replace_if(my_vector_1.begin(), my_vector_1.end(), replace_even, -1);
    std::cout << "My my_vector_1 result of replace if : \n";
    print_int_vector(my_vector_1);

    // shuffle
    std::random_device seed_generator{};
    std::mt19937_64 random_generator(seed_generator());
    std::shuffle(my_vector_1.begin(), my_vector_1.end(), random_generator);
    print_int_vector(my_vector_1);

    return 0;
}
