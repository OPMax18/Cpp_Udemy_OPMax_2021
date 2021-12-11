#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void print_double_vector(const std::vector<double>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

void print_double_2d_vector(const std::vector<std::vector<double>>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        for (std::size_t j = 0; j < vec[0].size(); ++j)
        {
            std::cout << "Vec[" << i << "][" << j << "] = " << vec[i][j] << "\n";
        }
    }
    std::cout << "\n";
}


int main()
{
    const size_t num_rows = 5;
    const size_t num_cols = 4;

    std::vector<std::vector<double>> myVector(num_rows, std::vector<double>(num_cols, 5));
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        for (std::size_t j = 0; j < myVector[0].size(); ++j)
        {
            myVector[i][j] = i * j + (i + j);
        }
    }
    print_double_2d_vector(myVector);

    return 0;
}
