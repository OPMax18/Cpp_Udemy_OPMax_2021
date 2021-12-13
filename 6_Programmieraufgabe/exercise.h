#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

typedef unsigned char uchar;
typedef vector<unsigned char> ByteArray;

// Aufgabe 1
uchar hex_xor(const uchar& hex1, const uchar& hex2);

// Aufgabe 2
ByteArray hex_vector_xor(const ByteArray& vec1, const ByteArray& vec2);
