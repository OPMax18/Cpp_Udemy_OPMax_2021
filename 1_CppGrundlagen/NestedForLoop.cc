#include <iostream>

int main()
{
    int myNumber = 0;

    std::cout << "Please enter an integer value you want to test for beeing a prime number: ";
    std::cin >> myNumber;

    bool isPrimeNumber = true;
    for (int i = 2; i < myNumber / 2; i++)
    {
        if (myNumber % i == 0)
        {
            isPrimeNumber = false;
            break;
        }
    }
    std::cout << "Prime Number: " << std::boolalpha << isPrimeNumber << "\n";
    return 0;
}
