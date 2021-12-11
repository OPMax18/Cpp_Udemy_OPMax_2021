#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myVector(3, 0);
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << myVector[i] << "\n";
    }
    std::cout << "\n";

    myVector.push_back(42);
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << myVector[i] << "\n";
    }
    std::cout << "\n";

    myVector.pop_back();
    myVector.pop_back();
    for (std::size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << myVector[i] << "\n";
    }
    std::cout << "\n";

    return 0;
}
