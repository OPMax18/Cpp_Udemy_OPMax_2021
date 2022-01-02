#include "game.h"


ConsoleInput map_user_input(char user_input)
{
    switch (user_input)
    {
    case 'a':
        return ConsoleInput::LEFT;
        break;
    case 'd':
        return ConsoleInput::RIGHT;
        break;
    case 'w':
        return ConsoleInput::UP;
        break;
    case 's':
        return ConsoleInput::DOWN;
        break;
    default:
        return ConsoleInput::INVALID;
        break;
    }
}


game_state_type update_game_state(const position_type& pos_player, const obstacle_list_type& obstacles)
{
    game_state_type game_state(kLen_X, std::string(kLen_Y, '.'));
    game_state[pos_start.first][pos_start.second] = '|';
    game_state[pos_goal.first][pos_goal.second] = '|';
    game_state[pos_player.first][pos_player.second] = 'P';

    for (const auto obstacle : obstacles)
    {
        game_state[obstacle.first][obstacle.second] = 'X';
    }
    return game_state;
}

void print_game_state(const game_state_type& game_state)
{
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

void execute_move(position_type& pos_player, const ConsoleInput& players_move)
{

    switch (players_move)
    {
    case ConsoleInput::LEFT:
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
    case ConsoleInput::RIGHT:
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
    case ConsoleInput::UP:
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
    case ConsoleInput::DOWN:
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
    case ConsoleInput::INVALID:
    default:
    {
        std::cout << "Unrecognized moved! \n";
        break;
    }
    }
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

position_type random_position()
{
    std::random_device seed_generator{};
    std::mt19937_64 random_generator(seed_generator());
    std::uniform_int_distribution<unsigned int> random_distribution_x{0, kLen_X - 1};
    std::uniform_int_distribution<unsigned int> random_distribution_y{0, kLen_Y - 1};

    return {random_distribution_x(random_generator), random_distribution_y(random_generator)};
}

void create_obstacles(obstacle_list_type& obstacles)
{
    for (unsigned int i = 0; i < number_obstacles; ++i)
    {
        bool already_inserted = false;
        auto pos_obstacle = pos_start;
        while (pos_start == pos_obstacle || pos_goal == pos_obstacle || already_inserted)
        {
            pos_obstacle = random_position();
            for (const auto obstacle : obstacles)
            {
                if (pos_obstacle == obstacle)
                {
                    already_inserted = true;
                    break;
                }
            }
        }
        obstacles.push_back(pos_obstacle);
    }
}

bool is_dead(const position_type& pos_player, const obstacle_list_type& obstacles)
{
    auto result_iterator =
        std::find_if(obstacles.begin(), obstacles.end(), [&](const auto obstacle) { return obstacle == pos_player; });
    if (result_iterator != obstacles.end())
    {
        std::cout << "You are dead! \n";
        return true;
    }

    return false;
}

void game()
{
    position_type posPlayer = {0U, 0U};
    char user_input;
    ConsoleInput playersMove = ConsoleInput::INVALID;
    bool finished = false;
    bool dead = false;
    obstacle_list_type obstacles{};
    create_obstacles(obstacles);

    system("clear");
    std::cout << "Please move the player with A to the left and with D to the right : \n";
    std::cout << "Please move the player with W up and with S down : \n";

    while (!finished && !dead)
    {
        print_game_state(update_game_state(posPlayer, obstacles));
        std::cout << "\n";
        std::cin >> user_input;
        playersMove = map_user_input(user_input);
        system("clear");
        execute_move(posPlayer, playersMove);
        dead = is_dead(posPlayer, obstacles);
        finished = is_finished(posPlayer);
    }
}
