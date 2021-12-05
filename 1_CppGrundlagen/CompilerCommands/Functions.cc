#include <iostream>
#include <stdlib.h>

bool is_even(int myNumber)
{
    if (myNumber % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int yourNumber = 3;
    std::cout << "That's your number: " << yourNumber << "\n";

    bool check = is_even(yourNumber);
    std::cout << "and your number is even: " << std::boolalpha << check << "\n";

    return 0;
}
