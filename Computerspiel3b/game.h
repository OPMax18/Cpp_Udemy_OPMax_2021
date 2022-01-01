#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using position_type = std::pair<unsigned int, unsigned int>;
using game_state_type = std::vector<std::string>;
constexpr unsigned int kLen_X = 5U;
constexpr unsigned int kLen_Y = 5U;

constexpr position_type pos_start = {0U, 0U};
constexpr position_type pos_goal = {kLen_X - 1U, kLen_Y - 1U};

enum class ConsolInput : unsigned int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

ConsolInput map_user_input(char user_input);

void print_game_state(const position_type& pos_player);

position_type execute_move(position_type pos_player, const ConsolInput& players_move);

bool is_finished(const position_type& pos_player);

void game();

#endif // GAME_H
