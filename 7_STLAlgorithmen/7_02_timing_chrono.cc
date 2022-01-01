#include <chrono>
#include <iostream>
#include <random>
#include <vector>

constexpr std::size_t num_elements = 1'000'000;

int main()
{
    std::vector<int> my_vector(num_elements, 0);

    // hier kommt immer die gleiche Verteilung raus, wegen des seed von 42 startet
    // diese mit 5, 3, 5, -8 ....
    std::mt19937_64 random_generator(42);
    std::uniform_int_distribution<int> random_distribution{-10, 10};

    auto start_time = std::chrono::steady_clock::now();

    for (std::size_t i = 0; i < num_elements; ++i)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    std::cout << "My radom vector: \t";
    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << my_vector[i] << "\t";
    }

    std::cout << "\n";
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    auto elapsed_time_us = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    auto elapsed_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    std::cout << "Elapsed_time ms: \t" << elapsed_time_ms << "\n";
    std::cout << "Elapsed_time us: \t" << elapsed_time_us << "\n";
    std::cout << "Elapsed_time ns: \t" << elapsed_time_ns << "\n";

    return 0;
}
