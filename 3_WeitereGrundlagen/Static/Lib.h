#pragma once
#include <cstdlib>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void function();

// static functionen können nur innerhalb der eigenen
// Compilierungseinheit aufgerufen werden
static void helper();
