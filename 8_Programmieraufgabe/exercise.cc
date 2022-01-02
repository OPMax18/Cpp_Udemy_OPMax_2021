#include "exercise.h"

// Aufgabe 2

bool is_vector_equal(const BinaryArray& target, const BinaryArray& input)
{
    for (std::size_t i = 0; i < target.size(); ++i)
    {
        if (target[i] != input[i])
        {
            return false;
            break;
        }
    }
    return true;
}

vector<bool> shuffle_till_equal_recursive(const BinaryArray& target, BinaryArray& input)
{
    if (is_vector_equal(target, input))
    {
        return input;
    }
    else
    {
        std::random_device seed_generator{};
        std::mt19937_64 random_generator(seed_generator());
        std::shuffle(input.begin(), input.end(), random_generator);
        return shuffle_till_equal_recursive(target, input);
    }
}

vector<bool> shuffle_till_equal(const BinaryArray& target, BinaryArray input)
{
    bool equal = false;
    int iteration = 1;
    while (!equal)
    {
        if (iteration % 25'000 == 0)
        {
            std::cout << std::endl << "iteration: \t" << iteration;
        }
        ++iteration;

        std::random_device seed_generator{};
        std::mt19937_64 random_generator(seed_generator());
        std::shuffle(input.begin(), input.end(), random_generator);
        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            equal = true;
        }
    }
    return input;
}

// Aufgabe 3

bool is_vector_equal_smart(const BinaryArray& target, const BinaryArray& input, std::size_t& index)
{
    index = 0;
    for (std::size_t i = 0; i < target.size(); ++i)
    {
        if (target[i] != input[i])
        {
            index = i;
            return false;
        }
    }
    return true;
}

vector<bool> smart_shuffle_till_equal_recursive(const BinaryArray& target, BinaryArray& input)
{
    std::size_t index = 0;
    if (is_vector_equal_smart(target, input, index))
    {
        return input;
    }
    else
    {
        std::random_device seed_generator{};
        std::mt19937_64 random_generator(seed_generator());
        auto start_iterator = input.begin();
        std::advance(start_iterator, index);
        std::shuffle(start_iterator, input.end(), random_generator);
        return smart_shuffle_till_equal_recursive(target, input);
    }
}

vector<bool> smart_shuffle_till_equal(const BinaryArray& target, BinaryArray input)
{
    bool equal = false;
    int iteration = 1;
    while (!equal)
    {
        if (iteration % 25'000 == 0)
        {
            std::cout << std::endl << "iteration: \t" << iteration;
        }
        ++iteration;

        std::random_device seed_generator{};
        std::mt19937_64 random_generator(seed_generator());
        auto start_iterator = std::mismatch(target.begin(), target.end(), input.begin(), input.end()).second;
        std::shuffle(start_iterator, input.end(), random_generator);
        if (std::equal(input.begin(), input.end(), target.begin()))
        {
            equal = true;
        }
    }
    return input;
}

void print_bool_vector(const std::vector<bool>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}
