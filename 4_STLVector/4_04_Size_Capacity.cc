#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> myVector;


    for (std::size_t i = 0; i < 9; ++i)
    {

        myVector.push_back(i * 3 + i + 3);
    }
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    std::cout << "\n";

    // for (std::size_t i = 0; i < myVector.size(); ++i)
    // {
    //     for (std::size_t j = 0; j < myVector[0].size(); ++j)
    //     {
    //         std::cout << "Vec[" << i << "][" << j << "] =" << myVector[i][j] << "\n";
    //     }
    // }
    // std::cout << "\n";
    return 0;
}
