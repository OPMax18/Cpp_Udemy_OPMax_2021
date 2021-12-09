#pragma once

#include "DynArray.h"
#include <math.h>

/**
 * @brief Calculates the mean of an dyanmic array
 *
 * @param dynamicArray
 * @return mean value
 */
double mean(DynamicArray& dynamicArray);

/**
 * @brief Calculates the median of an dyanmic array
 *
 * @param dynamicArray
 * @return median value
 */
double median(DynamicArray& dynamicArray);

/**
 * @brief Calculates the sum of an dyanmic array
 *
 * @param dynamicArray
 * @return sum value
 */
double sum(DynamicArray& dynamicArray);

/**
 * @brief Calculates the variance of an dyanmic array
 *
 * @param dynamicArray
 * @return variance
 */
double variance(DynamicArray& dynamicArray);

/**
 * @brief Calculates the standard deviation of an dyanmic array
 *
 * @param dynamicArray
 * @return standard deviation
 */
double stddev(DynamicArray& dynamicArray);
