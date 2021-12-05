#include <iostream>
#include <math.h>

int main()
{

    int myYear = 0;
    std::cout << "Please enter a year: ";
    std::cin >> myYear;

    bool schaltjahr = false;

    if ((myYear % 4 == 0 && myYear % 100 != 0) || myYear % 400 == 0)
    {
        schaltjahr = true;
    }

    std::cout << "Das Jahr: " << myYear << " ist ein Schaltjahr: " << std::boolalpha << schaltjahr << "\n";

    return 0;
}
