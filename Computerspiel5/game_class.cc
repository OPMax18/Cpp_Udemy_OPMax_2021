#include "game_class.h"

ConsoleInput Game::map_user_input(char user_input) const
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

void Game::update_game_state()
{
    std::fill(m_game_state.begin(), m_game_state.end(), std::string(len_y, '.'));

    m_game_state[pos_start.first][pos_start.second] = '|';
    m_game_state[m_pos_goal.first][m_pos_goal.second] = '|';
    m_game_state[m_pos_player.first][m_pos_player.second] = 'P';

    for (const auto obstacle : m_obstacles)
    {
        m_game_state[obstacle.first][obstacle.second] = 'X';
    }
}

void Game::print_game_state() const
{
    for (auto row : m_game_state)
    {
        for (auto position : row)
        {
            std::cout << position << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Game::move_player(const ConsoleInput& players_move)
{

    switch (players_move)
    {
    case ConsoleInput::LEFT:
    {
        if (m_pos_player.second > pos_start.second)
        {
            m_pos_player.second--;
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
        if (m_pos_player.second < len_y - 1)
        {
            m_pos_player.second++;
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
        if (m_pos_player.first > pos_start.first)
        {
            m_pos_player.first--;
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
        if (m_pos_player.first < len_x - 1)
        {
            m_pos_player.first++;
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

bool Game::is_finished()
{
    if (m_pos_goal == m_pos_player)
    {
        std::cout << "You won the game! \n";
        return true;
    }
    return false;
}

position_type Game::random_position(const unsigned int lower_x,
                                    const unsigned int upper_x,
                                    const unsigned int lower_y,
                                    const unsigned int upper_y)
{
    std::random_device seed_generator{};
    std::mt19937_64 random_generator(seed_generator());
    std::uniform_int_distribution<unsigned int> random_distribution_x{lower_x, upper_x};
    std::uniform_int_distribution<unsigned int> random_distribution_y{lower_y, upper_y};

    return {random_distribution_x(random_generator), random_distribution_y(random_generator)};
}

void Game::create_obstacles()
{
    for (auto& obstacle : m_obstacles)
    {
        bool already_inserted = false;
        auto pos_obstacle = pos_start;
        while (pos_start == pos_obstacle || m_pos_goal == pos_obstacle || already_inserted)
        {
            pos_obstacle = random_position(0, len_x - 1, 0, len_y - 1);
            for (const auto obstacle : m_obstacles)
            {
                if (pos_obstacle == obstacle)
                {
                    already_inserted = true;
                    break;
                }
            }
        }
        obstacle = pos_obstacle;
    }
}

void Game::move_obstacles()
{
    for (auto& obstacle : m_obstacles)
    {
        auto pos_obstacle = obstacle;
        do
        {
            auto lower_x = obstacle.first > pos_start.first ? obstacle.first - 1U : pos_start.first;
            auto upper_x = obstacle.first < len_x - 1U ? obstacle.first + 1 : len_x - 1U;
            auto lower_y = obstacle.second > pos_start.second ? obstacle.second - 1U : pos_start.second;
            auto upper_y = obstacle.second < len_y - 1U ? obstacle.second + 1U : len_y - 1U;
            pos_obstacle = random_position(lower_x, upper_x, lower_y, upper_y);

        } while (pos_start == pos_obstacle || m_pos_goal == pos_obstacle || m_pos_player == pos_obstacle);
        obstacle = pos_obstacle;
    }
}

position_type Game::generate_goal_position()
{
    auto pos_goal = pos_start;
    while (pos_start == pos_goal)
    {
        pos_goal = random_position(0, len_x - 1, 0, len_y - 1);
    }
    return pos_goal;
}

bool Game::is_dead()
{
    auto result_iterator = std::find_if(m_obstacles.begin(), m_obstacles.end(), [&](const auto obstacle) {
        return obstacle == m_pos_player;
    });
    if (result_iterator != m_obstacles.end())
    {
        std::cout << "You are dead! \n";
        return true;
    }

    return false;
}

void Game::start_game()
{
    char user_input;
    ConsoleInput playersMove = ConsoleInput::INVALID;
    bool finished = false;
    bool dead = false;

    create_obstacles();

    system("clear");
    std::cout << "Please move the player with A to the left and with D to the right : \n";
    std::cout << "Please move the player with W up and with S down : \n";

    while (!finished && !dead)
    {
        move_obstacles();
        update_game_state();
        print_game_state();
        std::cout << "\n";
        std::cin >> user_input;
        playersMove = map_user_input(user_input);
        system("clear");
        move_player(playersMove);
        dead = is_dead();
        finished = is_finished();
    }
}
