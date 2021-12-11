#include <cmath>
#include <iostream>
#include <vector>

void fill_double_vector(std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = i * 1.0;
    }
}

void print_double_vector(const std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

void exp_double_vector(std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::exp(vec[i]);
    }
}

void log_double_vector(std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] = std::log(vec[i]);
    }
}

int main()
{
    std::vector<double> myVector(6, 4.0);
    print_double_vector(myVector);

    fill_double_vector(myVector);
    print_double_vector(myVector);

    exp_double_vector(myVector);
    print_double_vector(myVector);

    log_double_vector(myVector);
    print_double_vector(myVector);

    return 0;
}
