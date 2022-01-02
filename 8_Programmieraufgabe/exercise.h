#pragma once

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef vector<bool> BinaryArray;

// Aufgabe 2
vector<bool> shuffle_till_equal_recursive(const BinaryArray& target, BinaryArray& input);
vector<bool> shuffle_till_equal(const BinaryArray& target, BinaryArray input);

// Aufgabe 3
vector<bool> smart_shuffle_till_equal_recursive(const BinaryArray& target, BinaryArray& input);
vector<bool> smart_shuffle_till_equal(const BinaryArray& target, BinaryArray input);

void print_bool_vector(const std::vector<bool>& vec);

template <typename T>
void print_vector(T vec)
{
    std::cout << "vector: \t";
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << "\t";
    }
    std::cout << "\n";
}
