#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void print_int_vector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{
    int matrix[2][3]{};

    for (const auto& row : matrix)
    {
        for (const auto& value : row)
        {
            std::cout << value << "\n";
        }
    }

    // Mit C++ 17 hinzugekommen
    struct Data
    {
        int x;
        int y;
    };

    std::vector<Data> vec = {{.x = 1, .y = 2}, {2, 3}, {4, 5}};
    // alter Schreibweise
    for (const auto& data : vec)
    {
        std::cout << "X: " << data.x << "\tY: " << data.y << "\n";
    }
    std::cout << "\n";

    //C++ 17 Schreibweise - structured binding
    for (const auto& [x1, y1] : vec)
    {
        std::cout << "X: " << x1 << "\tY: " << y1 << "\n";
    }
    std::cout << "\n";

    return 0;
}
