#pragma once
#include <algorithm>
#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::fill;
using std::sort;
using std::vector;

namespace matrix
{
// Aufgabe 1
using Matrix = std::vector<std::vector<double>>;
void initialize_matrix(matrix::Matrix& matrix, const int& num_rows, const int& num_cols);
void print_double_2d_vector(const std::vector<std::vector<double>>& vec);

// Aufgabe 2
vector<double> max_row_values(Matrix& matrix);

// Aufgabe 3
double sort_and_max(vector<double>& vec);

} //namespace matrix
