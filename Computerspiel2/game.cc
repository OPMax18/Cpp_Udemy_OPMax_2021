#include "game.h"


void print_game_state(unsigned int posPlayer)
{
    // char gameState[kLenX];

    // for (unsigned int i = 0U; i < kLenX; ++i)
    // {
    //     gameState[i] = '.';
    // }
    // gameState[kPosStart] = '|';
    // gameState[kPosGoal] = '|';
    // gameState[posPlayer] = 'P';

    // for (unsigned int i = 0U; i < kLenX; ++i)
    // {
    //     std::cout << gameState[i];
    // }
    char gameState[kLenX + 1];

    for (unsigned int i = 0U; i < kLenX; ++i)
    {
        gameState[i] = '.';
    }
    gameState[kPosStart] = '|';
    gameState[kPosGoal] = '|';
    gameState[posPlayer] = 'P';
    gameState[kLenX] = '\0';

    std::cout << gameState;
}

unsigned int execute_move(unsigned int posPlayer, char playersMove)
{
    if (kLeft == playersMove)
    {
        if (posPlayer > kPosStart)
        {
            posPlayer--;
            std::cout << "You moved to the left! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
    }
    else if (kRight == playersMove)
    {
        if (posPlayer < kPosGoal)
        {
            posPlayer++;
            std::cout << "You moved to the right! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
    }
    else
    {
        std::cout << "Unrecognized moved! \n";
    }
    return posPlayer;
}

bool is_finished(unsigned int posPlayer)
{
    if (posPlayer == kPosGoal)
    {
        std::cout << "You won the game! \n";
        return true;
    }
    return false;
}

void game()
{
    unsigned int posPlayer = 0U;
    char playersMove = 'X';
    bool finished = false;

    system("clear");
    std::cout << "Please move the player with A to the left and with D to the right : \n";

    while (!finished)
    {
        print_game_state(posPlayer);
        std::cout << "\n";
        std::cin >> playersMove;
        system("clear");
        posPlayer = execute_move(posPlayer, playersMove);
        finished = is_finished(posPlayer);
    }
}
