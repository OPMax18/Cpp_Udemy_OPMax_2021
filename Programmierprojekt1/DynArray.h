#pragma once

#include <cstddef>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief DynamicArray Structure.
 *
 * @param m_data Pointer to the data array
 * @param m_length Length of the Array
 */
struct DynamicArray
{
    double* m_data;
    std::size_t m_length;
};

/**
 * @brief Create a dynamic arry object
 *
 * @param value  The fill value for the array
 * @param length The length of the dynamic array
 * @return DynamicArray Array which was created
 */
DynamicArray create_dynamic_arry(const double& value, const std::size_t& length);

/**
 * @brief Pushs back the *value* at the end of the array
 *
 * @param dynamicArray  The input pointer to a struct with a double array
 * @param value         The value to append to the array
 */
void push_back(DynamicArray& dynamicArray, const int& value);

/**
 * @brief Pops back the *value* at the end of the arry
 *
 * @param dynamicArray  The input pointer to a struct with a double array
 */
void pop_back(DynamicArray& dynamicArray);
