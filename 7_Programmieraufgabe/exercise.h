#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::tuple;
using std::vector;


// Aufgabe 1
//typedef map<string, pair<int, int>> Friends;
using pair_age_weight = std::pair<int, int>;
using friends_type = map<string, pair_age_weight>;

// Aufgabe  2
string get_oldest_friend(const friends_type& friends);

string get_heaviest_friend(const friends_type& friends);
