#include <iostream>
#include <math.h>

int main()
{

    // int myYear = 0;
    // std::cout << "Please enter a year: ";
    // std::cin >> myYear;

    // bool schaltjahr = false;

    for (int i = 0; i < 4; i += 1)
    {
        std::cout << "i: " << i << "\n";
    }
    std::cout << "nächste Zeile: "
              << "\n";
    for (int i = 2; i < 10; i += 2)
    {
        std::cout << "i: " << i << "\n";
    }
    std::cout << "nächste Zeile: "
              << "\n";
    for (int i = 10; i > 1; i--)
    {
        std::cout << "i: " << i << "\n";
    }


    return 0;
}
