#include <iostream>

int main()
{

    int myNumber = 0;
    std::cout << "Please enter an integer value: ";
    std::cin >> myNumber;

    bool check3 = (myNumber >= 0 && myNumber <= 10);
    std::cout << "Check 3: " << std::boolalpha << check3 << "\n";


    bool check2 = !(myNumber >= 0 && myNumber <= 10);
    std::cout << "Check 3 Negation: " << std::boolalpha << check2 << "\n";

    return 0;
}
