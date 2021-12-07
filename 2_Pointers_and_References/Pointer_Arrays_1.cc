#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

int main()
{

    // Heap allocation
    int* ptrNumber = new int{4};

    unsigned int arraySize = 10U;

    int* ptrArray = new int[arraySize];

    for (unsigned int i = 0U; i < arraySize; i++)
    {
        ptrArray[i] = i;
    }

    for (unsigned int i = 0U; i < arraySize; i++)
    {
        std::cout << "ptrArray@" << i << " = " << ptrArray[i] << "\n";
        ;
    }

    // address of the array - normally not necessary
    for (unsigned int i = 0U; i < arraySize; i++)
    {
        std::cout << "Address of ptrArray@" << i << " = " << &ptrArray[i] << "\n";
        ;
    }

    // Heap de-allocation
    delete ptrNumber;
    ptrNumber = nullptr;

    delete[] ptrArray;
    ptrArray = nullptr;

    return 0;
}
