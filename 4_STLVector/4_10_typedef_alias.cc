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

// Sofern man keine Templates verwendet, ist beides gleich
//      Type                Alias_Name => kommt aus C
typedef std::vector<double> double_vector_type;
typedef std::vector<std::vector<double>> DoubleMatrix;

// using Alias_Name = Type;  => seit C++ 11 - für Alles verwendbar!!
using IntVector = std::vector<int>;

int main()
{
    const size_t num_rows = 5;
    const size_t num_cols = 4;

    std::vector<double_vector_type> myVector(num_rows, double_vector_type(num_cols, 5));
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        for (std::size_t j = 0; j < myVector[0].size(); ++j)
        {
            myVector[i][j] = i * j + (i + j);
        }
    }
    print_double_2d_vector(myVector);

    DoubleMatrix myMatrix;


    return 0;
}
