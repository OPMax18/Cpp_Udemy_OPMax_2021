#include <iostream>

// dType varName[numElements]

int main()
{

    char myName[] = {'T', 'e', 's', 't', '\0'};

    std::cout << myName << "\n";

    char myLastName[] = "Schaffranek";

    std::cout << myLastName << "\n";

    for (unsigned int i = 0; i < 12; i++)
    {
        std::cout << "myLastName[" << i << "] = " << myLastName[i] << "\n";
    }

    return 0;
}
