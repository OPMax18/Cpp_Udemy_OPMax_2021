#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

// void print_int_pointer(int* ptrInt)
// {

//     std::cout << "Deref: " << *ptrInt << "\t Ref: " << ptrInt << "\t Pointer Address: " << &ptrInt << "\n";
// }

// void print_doubble_pointer(double* ptrDouble)
// {

//     std::cout << "Deref: " << *ptrDouble << "\t Ref: " << ptrDouble << "\t Pointer Address: " << &ptrDouble << "\n";
// }


void print_int_pointer(int* &ptrInt)
{

    std::cout << "Deref: " << *ptrInt << "\t Ref: " << ptrInt << "\t Pointer Address: " << &ptrInt << "\n";
}

void print_doubble_pointer(double* &ptrDouble)
{

    std::cout << "Deref: " << *ptrDouble << "\t Ref: " << ptrDouble << "\t Pointer Address: " << &ptrDouble << "\n";
}


int main()
{

    int a = 1337;
    double b = -13.37;

    int* ptrC = &a;
    print_int_pointer(ptrC);

    *ptrC -= 10;
    print_int_pointer(ptrC);

    int* ptrD = &a;
    print_int_pointer(ptrD);

    *ptrC += 100;
    print_int_pointer(ptrD);

    return 0;
}
