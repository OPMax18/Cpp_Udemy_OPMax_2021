#include <iostream>

int main()
{
    int mySum = 10;

    // while (mySum < 10)
    // {
    //     int input;
    //     std::cout << "mySum: " << mySum << "\n";
    //     std::cout << "Please enter an integer value: ";
    //     std::cin >> input;
    //     mySum += input;
    // }


    do
    {
        int input;
        std::cout << "mySum: " << mySum << "\n";
        std::cout << "Please enter an integer value: ";
        std::cin >> input;
        mySum += input;
    } while (mySum < 10);
    return 0;
}
