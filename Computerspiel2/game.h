#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>

constexpr unsigned int kLenX = 10U;
constexpr unsigned int kPosStart = 0U;
constexpr unsigned int kPosGoal = kLenX - 1U;
constexpr char kLeft = 'a';
constexpr char kRight = 'd';

void game();

void print_game_state(unsigned int posPlayer);

unsigned int execute_move(unsigned int posPlayer, char move);

bool is_finished(unsigned int posPlayer);

#endif // GAME_H
