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
    const unsigned int num_rows = 3;
    const unsigned int num_cols = 2;
    std::vector<std::vector<double>> myVector(num_rows, std::vector<double>(num_cols, 1.0));

    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        for (std::size_t j = 0; j < myVector[0].size(); ++j)
        {
            myVector[i][j] = i * j + i + j;
        }
    }
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        for (std::size_t j = 0; j < myVector[0].size(); ++j)
        {
            std::cout << "Vec[" << i << "][" << j << "] =" << myVector[i][j] << "\n";
        }
    }
    std::cout << "\n";


    std::vector<double> myVector2(6, 4.0);
    print_double_vector(myVector2);

    fill_double_vector(myVector2);
    print_double_vector(myVector2);

    exp_double_vector(myVector2);
    print_double_vector(myVector2);

    log_double_vector(myVector2);
    print_double_vector(myVector2);

    return 0;
}
