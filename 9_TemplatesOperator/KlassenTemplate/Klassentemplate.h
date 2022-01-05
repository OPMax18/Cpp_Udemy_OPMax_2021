#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T_Data>
class Statistic
{
public:
    Statistic<T_Data>();
    ~Statistic<T_Data>();

    T_Data get_min() const;
    T_Data get_max() const;

    double get_mean() const;
    void push_next_sample(T_Data value);
    void print_data() const;

private:
    T_Data m_min;
    T_Data m_max;
    double m_mean;
    int m_num_samples;
    std::vector<T_Data> m_samples;
};

template <typename T_Data>
Statistic<T_Data>::Statistic() : m_min(0U), m_max(0U), m_mean(0.0), m_num_samples(0U), m_samples(0U, 0U)
{
}

template <typename T_Data>
Statistic<T_Data>::~Statistic()
{
}

template <typename T_Data>
T_Data Statistic<T_Data>::get_min() const
{
    return m_min;
}

template <typename T_Data>
T_Data Statistic<T_Data>::get_max() const
{
    return m_max;
}

template <typename T_Data>
double Statistic<T_Data>::get_mean() const
{
    return m_mean;
}

template <typename T_Data>
void Statistic<T_Data>::push_next_sample(T_Data value)
{
    m_num_samples++;
    m_samples.push_back(value);
    if (m_num_samples == 1)
    {
        m_min = value;
        m_max = value;
        m_mean = value;
    }
    else
    {

        if (value < m_min)
        {
            m_min = value;
        }
        if (value > m_max)
        {
            m_max = value;
        }
        m_mean = (((m_num_samples - 1) * m_mean + value) / (m_num_samples));
    }
}

template <typename T_Data>
void Statistic<T_Data>::print_data() const
{
    std::cout << "Max: " << m_max << "\n";
    std::cout << "Min: " << m_min << "\n";
    std::cout << "Mean: " << m_mean << "\n";
    std::cout << "------------------------------------------------" << std::endl;
}
