#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using position_type = std::pair<unsigned int, unsigned int>;
using game_state_type = std::vector<std::string>;
using obstacle_list_type = std::vector<position_type>;

constexpr unsigned int len_x = 5U;
constexpr unsigned int len_y = 5U;
constexpr unsigned int number_obstacles = 3U;

constexpr position_type pos_start = {0U, 0U};

enum class ConsoleInput : unsigned int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

class Game
{
public:
    Game()
        : m_pos_player(position_type(0U, 0U)), m_pos_goal(generate_goal_position()),
          m_obstacles(obstacle_list_type(number_obstacles, position_type(0U, 0U))),
          m_game_state(len_x, std::string(len_y, '.')){};
    ~Game(){};

    void start_game();

private:
    ConsoleInput map_user_input(char user_input) const;
    position_type generate_goal_position();

    void update_game_state();

    void print_game_state() const;

    void execute_move();
    void move_player(const ConsoleInput& move);

    position_type random_position(const unsigned int lower_x,
                                  const unsigned int upper_x,
                                  const unsigned int lower_y,
                                  const unsigned int upper_y);


    void create_obstacles();
    void move_obstacles();
    bool is_dead();

    bool is_finished();

    position_type m_pos_player{};
    position_type m_pos_goal{};
    obstacle_list_type m_obstacles{};
    game_state_type m_game_state{};
};
