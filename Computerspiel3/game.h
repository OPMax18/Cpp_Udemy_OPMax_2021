#pragma once
#ifndef GAME_H
#define GAME_H

#include <array>
#include <iostream>
#include <stdlib.h>
#include <vector>

using position_type = std::array<unsigned int, 2>;
using game_state_type = std::vector<std::vector<char>>;
constexpr unsigned int kRow = 10U;
constexpr unsigned int kCol = 10U;
constexpr position_type PosStart = {0U, 0U};
constexpr position_type PosGoal = {kRow - 1U, kCol - 1U};
constexpr char kLeft = 'a';
constexpr char kRight = 'd';
constexpr char kUp = 'w';
constexpr char kDown = 's';

void game();

void print_game_state(const game_state_type& gameState);

void set_player_position(game_state_type& gameState, const position_type posPlayer);

unsigned int execute_move(unsigned int posPlayer, char move);

bool is_finished(unsigned int posPlayer);

#endif // GAME_H
