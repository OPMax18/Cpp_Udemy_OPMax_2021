#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

// Call by Value (=> local copy)
void f(int* ptrMyNumber)
{
    std::cout << "(FUNC_F) Address of heap = value of pointer: " << ptrMyNumber
              << "\t (FUNC_F) Value of heap = deref of pointer: " << *ptrMyNumber << "\n";
    std::cout << "(FUNC_F) Address of pointer itself: " << &ptrMyNumber << "\n\n";
}

int main()
{
    int* ptrNumber = new int{4};
    std::cout << "(MAIN) Address of heap = value of pointer: " << ptrNumber
              << "\t (MAIN) Value of heap = deref of pointer: " << *ptrNumber << "\n";
    std::cout << "(MAIN) Address of pointer itself: " << &ptrNumber << "\n\n";

    f(ptrNumber);

    return 0;
}
