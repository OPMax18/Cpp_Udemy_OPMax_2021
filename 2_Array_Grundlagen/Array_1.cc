#include <iostream>

// dType varName[numElements]

int main()
{
    int myArray[5U] = {1U, 2U, 3U, 4U, 5U};

    for (unsigned int i = 0U; i < 5U; i++)
    {
        std::cout << "Der Eintrag in myArray an der Stelle: " << i << " ist " << myArray[i] << "\n";
    }
    std::cout << "\n";

    int myArray2[] = {20U, 21U, 32U, 43U, 54U};

    for (unsigned int k = 0U; k < 5U; k++)
    {
        std::cout << "Der Eintrag in myArray2 an der Stelle: " << k << " ist " << myArray2[k] << "\n";
    }
    return 0;
}
