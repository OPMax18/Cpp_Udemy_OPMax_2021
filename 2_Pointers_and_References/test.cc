#include <iostream>

//void foo(int& b)
void foo(int* b)
{
    std::cout << "(FOO) &b: " << &b << "\n";
    std::cout << "(FOO) *b: " << *b << "\n";
    std::cout << "(FOO) b: " << b << "\n";
}

int main()
{
    int a;
    a = 5;
    std::cout << "(MAIN) &a: " << &a << "\n";
    //std::cout << "(MAIN) *a: " << *a << "\n";
    std::cout << "(MAIN) a: " << a << "\n";
    foo(&a);
    return 0;
}
