#include <iostream>

int main()
{
    int myNumber = 0;
    int myMainWinner = 4;
    int myWoddenSpoon = 2; // Trostpreis im Englischen

    std::cout << "Please enter an integer value between 0 and 10: ";
    std::cin >> myNumber;

    if (myNumber >= 0 && myNumber <= 10)
    {
        if (myNumber == myMainWinner)
        {
            std::cout << "You won!"
                      << "\n";
        }
        else if (myNumber % myWoddenSpoon == 0)
        {
            std::cout << "You won the wodden spoon!"
                      << "\n";
        }
        else
        {
            std::cout << "Sorry, you lost!"
                      << "\n";
        }
    }
    else
    {
        std::cout << "Please enter an valid integer value between [0, 10]: \n";
    }

    return 0;
}
