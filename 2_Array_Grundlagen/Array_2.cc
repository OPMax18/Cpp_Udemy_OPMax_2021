#include <iostream>

// dType varName[numElements]

int main()
{
    float myVector_1[3U]{};
    float myVector_2[3U]{};

    std::cout << "Enter values for vector_1: \n";
    for (unsigned int i = 0U; i < 3U; i++)
    {
        std::cin >> myVector_1[i];
    }
    std::cout << "Enter values for vector_2: \n";
    for (unsigned int k = 0U; k < 3U; k++)
    {
        std::cin >> myVector_2[k];
    }
    std::cout << "\n";
    for (unsigned int p = 0U; p < 3U; p++)
    {
        std::cout << "Die Summe von myVector_1 und myVector_2 an der Stelle " << p << " ist "
                  << myVector_1[p] + myVector_2[p] << "\n";
    }

    return 0;
}
