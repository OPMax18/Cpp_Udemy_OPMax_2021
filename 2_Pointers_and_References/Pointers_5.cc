#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

int main()
{

    // Heap allocation
    //int *ptrNumber = new int{4};
    int *ptrNumber = new int;
    *ptrNumber = 4;

    // The memory address of the heap variable, where the pointer points to
    std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";
    // The value of the heap variable, where the pointer points to
    std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n\n";
    // Memeory address of the pointer itself
    std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n\n\n";

    // Heap de-allocation
    delete ptrNumber;
    // The address is still there and available, but it's not reserved for our code anymore
    std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";
    if(ptrNumber != nullptr)
    {
        // The value might be already changed be another program => false values even errors can occure
        std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n\n";
        // The address of the pointer is still valid
        std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n\n\n";
    }

    ptrNumber = nullptr;

    // The address is still there and available, but it's not reserved for our code anymore
    std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";

    if(ptrNumber != nullptr)
    {
        // The value might be already changed be another program => false values even errors can occure
        std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n\n";
        // The address of the pointer is still valid
        std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n\n\n";
    }

    return 0;
}
