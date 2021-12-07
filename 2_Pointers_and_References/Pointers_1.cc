#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

int main()
{

    int number = 5;
    std::cout << "Value of number: " << number << "\n";
    std::cout << "Address of number: " << &number << "\n";

    int *ptrNumber = &number;
    std::cout << "Value of ptrNumber: " << ptrNumber << "\n";
    std::cout << "Value of the memory address that ptrNumber point to: " << *ptrNumber << "\n";
    std::cout << "Address of ptrNumber: " << &ptrNumber << "\n";

    return 0;
}
