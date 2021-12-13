#include "5_07_exercise.h"

// Aufgabe 1
uchar hex_xor(const uchar& hex1, const uchar& hex2)
{
    return (hex1 ^ hex2);
}

// Aufgabe 2
ByteArray hex_vector_xor(const ByteArray& vec1, const ByteArray& vec2)
{
    ByteArray xOrEd{};
    auto i = 0U;
    auto k = 0U;
    while ((i < vec1.size()) || (k < vec2.size()))
    {
        xOrEd.push_back(hex_xor(vec1[i], vec2[k]));
        ++i;
        ++k;
    }
    return xOrEd;
}
