#pragma once

#include "DynArray.h"
#include <math.h>

/**
 * @brief Calculates the mean of an dyanmic array
 *
 * @param dynamicArray
 * @return mean value
 */
template <typename T_Dat>
double mean(DynamicArray<T_Dat>& dynamicArray)
{
    return sum(dynamicArray) / dynamicArray.get_length();
}

/**
 * @brief Calculates the median of an dyanmic array
 *
 * @param dynamicArray
 * @return median value
 */
template <typename T_Dat>
double median(DynamicArray<T_Dat>& dynamicArray)
{
    double median = 0.0;

    bool has_odd_length = dynamicArray.get_length() % 2U;
    std::size_t position = std::floor(dynamicArray.get_length() / 2U);
    // even
    if (!has_odd_length)
    {
        median = (dynamicArray[position] + dynamicArray[position - 1]) / 2.0;
    }
    // odd
    else
    {
        median = dynamicArray[position];
    }
    return median;
}

/**
 * @brief Calculates the sum of an dyanmic array
 *
 * @param dynamicArray
 * @return sum value
 */
template <typename T_Dat>
T_Dat sum(DynamicArray<T_Dat>& dynamicArray)
{
    T_Dat sum = 0.0;
    for (std::size_t k = 0; k < dynamicArray.get_length(); k++)
    {
        sum += dynamicArray[k];
    }
    return sum;
}


/**
 * @brief Calculates the variance of an dyanmic array
 *
 * @param dynamicArray
 * @return variance
 */
template <typename T_Dat>
double variance(DynamicArray<T_Dat>& dynamicArray)
{
    double mean_value = mean(dynamicArray);
    double probability = 1.0 / dynamicArray.get_length();

    double sum_squared_value = 0.0;
    for (std::size_t k = 0; k < dynamicArray.get_length(); k++)
    {
        sum_squared_value += (dynamicArray[k] * dynamicArray[k]);
    }

    return (sum_squared_value * probability) - (mean_value * mean_value);
}

/**
 * @brief Calculates the standard deviation of an dyanmic array
 *
 * @param dynamicArray
 * @return standard deviation
 */
template <typename T_Dat>
double stddev(DynamicArray<T_Dat>& dynamicArray)
{
    return std::sqrt(variance(dynamicArray));
}
