#include <iostream>
#include <math.h>

int main()
{

    int myNumber = 0;
    std::cout << "Please enter an integer value: ";
    std::cin >> myNumber;

    auto absNumber = std::abs(myNumber);
    std::cout << "Absolut Number of " << myNumber << " is: " << absNumber << "\n";

    if (myNumber < 0)
    {
        std::cout << "Absolut Number of " << myNumber << " is: " << -1 * myNumber << "\n";
    }
    else
    {
        std::cout << "Absolut Number of " << myNumber << " is: " << myNumber << "\n";
    }

    return 0;
}
