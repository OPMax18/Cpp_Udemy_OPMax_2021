#include "AlgoArray.h"


double sum(DynamicArray& dynamicArray)
{
    double sum = 0.0;
    for (std::size_t k = 0; k < dynamicArray.m_length; k++)
    {
        sum += dynamicArray.m_data[k];
    }
    return sum;
}

double mean(DynamicArray& dynamicArray)
{
    return sum(dynamicArray) / dynamicArray.m_length;
}


// only for sorted list!!
double median(DynamicArray& dynamicArray)
{
    double median = 0.0;

    bool has_odd_length = dynamicArray.m_length % 2U;
    std::size_t position = std::floor(dynamicArray.m_length / 2U);
    // even
    if (!has_odd_length)
    {
        median = (dynamicArray.m_data[position] + dynamicArray.m_data[position - 1]) / 2.0;
    }
    // odd
    else
    {
        median = dynamicArray.m_data[position];
    }
    return median;
}

double variance(DynamicArray& dynamicArray)
{
    double mean_value = mean(dynamicArray);
    double probability = 1.0 / dynamicArray.m_length;

    double sum_squared_value = 0.0;
    for (std::size_t k = 0; k < dynamicArray.m_length; k++)
    {
        sum_squared_value += (dynamicArray.m_data[k] * dynamicArray.m_data[k]);
    }

    return (sum_squared_value * probability) - (mean_value * mean_value);
}

double stddev(DynamicArray& dynamicArray)
{
    return std::sqrt(variance(dynamicArray));
}
