#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

int main()
{

    // Heap allocation
    //int *ptrNumber = new int{4};
    int *ptrNumber = new int;
    *ptrNumber = 4;

    std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";
    std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n";
    std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n";

    *ptrNumber = 1337;

    std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";
    std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n";
    std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n";

    // Heap de-allocation
    delete ptrNumber;

    // std::cout << "Value of ptrNumber (address heap): " << ptrNumber << "\n";
    // std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n";
    // std::cout << "Address (stack) of ptrNumber: " << &ptrNumber << "\n";

    return 0;
}
