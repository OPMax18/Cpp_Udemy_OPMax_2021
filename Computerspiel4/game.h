#pragma once
#ifndef GAME_H
#define GAME_H

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

constexpr unsigned int kLen_X = 5U;
constexpr unsigned int kLen_Y = 5U;
constexpr unsigned int number_obstacles = 3U;

constexpr position_type pos_start = {0U, 0U};
constexpr position_type pos_goal = {kLen_X - 1U, kLen_Y - 1U};

enum class ConsoleInput : unsigned int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

ConsoleInput map_user_input(char user_input);

void update_game_state(const position_type& pos_player,
                       const obstacle_list_type& obstacles,
                       game_state_type& game_state);

void print_game_state(const game_state_type& game_state);

void execute_move(position_type& pos_player, const ConsoleInput& players_move);

bool is_finished(const position_type& pos_player);

position_type random_position();
void create_obstacles(obstacle_list_type& obstacles);
bool is_dead(const position_type& pos_player, const obstacle_list_type& obstacles);

void game();

#endif // GAME_H
