//#include "Game.h"
#include <iostream>

int user_input()
{
    int number{};
    std::cin >> number;
    return number;
}

void game_evaluation(int userNumber)
{
    int myMainWinner = 4;
    int myWoddenSpoon = 2; // Trostpreis im Englischen

    if (userNumber >= 0 && userNumber <= 10)
    {
        if (userNumber == myMainWinner)
        {
            std::cout << "You won!"
                      << "\n";
        }
        else if (userNumber % myWoddenSpoon == 0)
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
}

void game()
{
    int numberAttemps = 0U;
    std::cout << "Welcome to my Guessing-Game!\n";
    std::cout << "Enter the number of attemps: \n";
    numberAttemps = user_input();

    for (int i = 0; i < numberAttemps; i++)
    {
        int myNumber = 0;


        std::cout << "Please enter an integer value between 0 and 10: ";
        myNumber = user_input();
        game_evaluation(myNumber);
    }
}
