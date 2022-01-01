#include "game.h"

void initialize_game_state(game_state_type& gameState)
{
    gameState.clear();
    std::vector<char> row{};
    for (unsigned int i = 0; i < kCol; ++i)
    {
        for (unsigned int i = 0; i < kRow; ++i)
        {
            row.push_back('.');
        }
        gameState.push_back(row);
        row.clear();
    }

    gameState[0][0] = '|';
    gameState[kRow - 1][kCol - 1] = '|';
}

void print_game_state(const game_state_type& gameState)
{
    for (auto row : gameState)
    {
        for (auto position : row)
        {
            std::cout << position;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void set_player_position(game_state_type& gameState, const position_type posPlayer)
{
    gameState[posPlayer[0]][posPlayer[1]] = 'P';
}

position_type execute_move(position_type posPlayer, char playersMove)
{

    switch (playersMove)
    {
    case kLeft:
        if (posPlayer[1] > PosStart[1])
        {
            posPlayer[1]--;
            std::cout << "You moved to the left! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    case kRight:
        if (posPlayer[1] < PosGoal[1])
        {
            posPlayer[1]++;
            std::cout << "You moved to the right! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    case kUp:
        if (posPlayer[0] > PosStart[0])
        {
            posPlayer[0]--;
            std::cout << "You moved up! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    case kDown:
        if (posPlayer[0] < PosGoal[0])
        {
            posPlayer[0]++;
            std::cout << "You moved down! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    default:
        std::cout << "Unrecognized moved! \n";
        break;
    }

    return posPlayer;
}

bool is_finished(position_type posPlayer)
{
    if ((posPlayer[0] == PosGoal[0]) && (posPlayer[1] == PosGoal[1]))
    {
        std::cout << "You won the game! \n";
        return true;
    }
    return false;
}

void game()
{
    position_type posPlayer = {0U, 0U};
    char playersMove = 'X';
    bool finished = false;
    game_state_type gameState{};

    system("clear");
    std::cout << "Please move the player with A to the left and with D to the right : \n";
    std::cout << "Please move the player with W up and with S down : \n";
    initialize_game_state(gameState);

    while (!finished)
    {
        initialize_game_state(gameState);
        set_player_position(gameState, posPlayer);
        print_game_state(gameState);
        std::cout << "\n";
        std::cin >> playersMove;
        system("clear");
        posPlayer = execute_move(posPlayer, playersMove);
        finished = is_finished(posPlayer);
    }
}
