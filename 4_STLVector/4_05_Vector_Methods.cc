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


    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << myVector[i] << "\n";
    }
    std::cout << "\n";

    myVector.clear();
    std::cout << "Cleared \n";
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    std::cout << "\n";
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << myVector[i] << "\n";
    }

    myVector.shrink_to_fit();
    std::cout << "Shrinked \n";
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    std::cout << "\n";


    myVector.resize(3);
    std::cout << "Resizied \n";
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << myVector[i] << "\n";
    }
    std::cout << "\n";

    // reserve - changes the capacity
    myVector.reserve(15);
    std::cout << "Resizied \n";
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << myVector[i] << "\n";
    }
    std::cout << "\n";
    myVector.push_back(4);
    std::cout << "Size = \t\t" << myVector.size() << "\n";
    std::cout << "Capacity = \t" << myVector.capacity() << "\n";
    std::cout << "\n";

    return 0;
}
