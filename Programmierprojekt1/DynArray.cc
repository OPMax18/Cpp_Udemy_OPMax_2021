#include "DynArray.h"

DynamicArray create_dynamic_arry(const double& value, const std::size_t& length)
{
    double* temp = nullptr;
    temp = new double[length];

    for (std::size_t i = 0; i < length; i++)
    {
        temp[i] = value;
    }
    DynamicArray newArray{temp, length};
    return newArray;
}


void push_back(DynamicArray& dynamicArray, const int& value)
{
    double* temp = nullptr;
    temp = new double[dynamicArray.m_length + 1];

    for (std::size_t i = 0; i < dynamicArray.m_length; i++)
    {
        temp[i] = dynamicArray.m_data[i];
    }

    temp[dynamicArray.m_length] = value;

    delete[] dynamicArray.m_data;
    dynamicArray.m_data = temp;
    dynamicArray.m_length++;
}

void pop_back(DynamicArray& dynamicArray)
{
    double* temp = nullptr;
    temp = new double[dynamicArray.m_length - 1];

    for (std::size_t i = 0; i < dynamicArray.m_length - 1; i++)
    {
        temp[i] = dynamicArray.m_data[i];
    }

    delete[] dynamicArray.m_data;
    dynamicArray.m_data = temp;
    dynamicArray.m_length--;
}
