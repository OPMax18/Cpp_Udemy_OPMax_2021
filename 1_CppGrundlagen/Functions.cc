#include <iostream>
#include <stdlib.h>

// ReturnTyp Functionsname(Parameterliste - optional
// {
//     Function code
// }

int user_input()
{
    int number{};
    std::cout << "Please enter a number: \n";
    std::cin >> number;
    return number;
}

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
    int yourNumber = user_input();
    std::cout << "That's your number: " << yourNumber << "\n";

    bool check = is_even(yourNumber);
    std::cout << "and your number is even: " << std::boolalpha << check << "\n";

    return 0;
}
