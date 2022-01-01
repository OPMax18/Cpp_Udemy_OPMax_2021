#include "game.h"


ConsolInput map_user_input(char user_input)
{
    switch (user_input)
    {
    case 'a':
        return ConsolInput::LEFT;
        break;
    case 'd':
        return ConsolInput::RIGHT;
        break;
    case 'w':
        return ConsolInput::UP;
        break;
    case 's':
        return ConsolInput::DOWN;
        break;
    default:
        return ConsolInput::INVALID;
        break;
    }
}


void print_game_state(const position_type& pos_player)
{
    game_state_type game_state(kLen_X, std::string(kLen_Y, '.'));
    game_state[pos_start.first][pos_start.second] = '|';
    game_state[pos_goal.first][pos_goal.second] = '|';
    game_state[pos_player.first][pos_player.second] = 'P';

    for (auto row : game_state)
    {
        for (auto position : row)
        {
            std::cout << position << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

position_type execute_move(position_type pos_player, const ConsolInput& players_move)
{

    switch (players_move)
    {
    case ConsolInput::LEFT:
    {
        if (pos_player.second > pos_start.second)
        {
            pos_player.second--;
            std::cout << "You moved to the left! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    }
    case ConsolInput::RIGHT:
    {
        if (pos_player.second < pos_goal.second)
        {
            pos_player.second++;
            std::cout << "You moved to the right! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    }
    case ConsolInput::UP:
    {
        if (pos_player.first > pos_start.first)
        {
            pos_player.first--;
            std::cout << "You moved upwards! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    }
    case ConsolInput::DOWN:
    {
        if (pos_player.first < pos_goal.first)
        {
            pos_player.first++;
            std::cout << "You moved downwards! \n";
        }
        else
        {
            std::cout << "You bounced! \n";
        }
        break;
    }
    case ConsolInput::INVALID:
    default:
    {
        std::cout << "Unrecognized moved! \n";
        break;
    }
    }

    return pos_player;
}

bool is_finished(const position_type& pos_player)
{
    if (pos_goal == pos_player)
    {
        std::cout << "You won the game! \n";
        return true;
    }
    return false;
}

void game()
{
    position_type posPlayer = {0U, 0U};
    char user_input;
    ConsolInput playersMove = ConsolInput::INVALID;
    bool finished = false;


    system("clear");
    std::cout << "Please move the player with A to the left and with D to the right : \n";
    std::cout << "Please move the player with W up and with S down : \n";

    while (!finished)
    {

        print_game_state(posPlayer);
        std::cout << "\n";
        std::cin >> user_input;
        playersMove = map_user_input(user_input);
        system("clear");
        posPlayer = execute_move(posPlayer, playersMove);
        finished = is_finished(posPlayer);
    }
}
