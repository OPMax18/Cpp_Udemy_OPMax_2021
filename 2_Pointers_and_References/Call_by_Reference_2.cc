#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

// Call by Value (=> local copy)
void f1(int number)
{
    number++;
}

// Call by Reference
void f2(int& number)
{
    number++;
}

// Call by Value (=> local copy)
int f3(int number)
{
    // number++;
    return ++number;
}

int main()
{
    int number = 0;
    std::cout << "(MAIN) number: " << number << "\n";

    f1(number);
    std::cout << "(MAIN_f1) number: " << number << "\n";

    f2(number);
    std::cout << "(MAIN_f2) number: " << number << "\n";

    number = f3(number);
    std::cout << "(MAIN_f3) number: " << number << "\n";

    return 0;
}
