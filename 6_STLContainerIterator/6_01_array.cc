#include <array>
#include <iostream>
#include <vector>

int main()
{
    const int l = 10;

    std::vector<int> myVector(10U, 0U);

    // Array braucht auf jeden Fall eine feste Länge zur Compilezeit!!
    std::array<int, l> myArray;

    for (unsigned int i = 0U; i < 10U; ++i)
    {
        myArray[i] = i;
        myVector[i] = i;
    }

    for (unsigned int i = 0U; i < 10U; ++i)
    {
        std::cout << "MyArray: " << myArray[i] << "\n";
    }

    myVector.push_back(19U);
    for (unsigned int i = 0U; i < myVector.size(); ++i)
    {
        std::cout << "MyVector: " << myVector[i] << "\n";
    }

    return 0;
}
