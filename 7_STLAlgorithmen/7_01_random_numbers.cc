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

    for (std::size_t i = 0; i < num_elements; ++i)
    {
        my_vector[i] = random_distribution(random_generator);
    }

    std::cout << "My radom vector: \t";
    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << my_vector[i] << "\t";
    }

    // dies muss die CPU unterstützen, dann werden "zufällige" seed
    // übergeben
    std::random_device seed_generator{};
    std::mt19937_64 random_generator2(seed_generator());

    my_vector.clear();
    for (std::size_t i = 0; i < num_elements; ++i)
    {
        my_vector[i] = random_distribution(random_generator2);
    }

    std::cout << "\nMy radom vector: \t";
    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << my_vector[i] << "\t";
    }


    return 0;
}
