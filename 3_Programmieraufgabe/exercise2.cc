#include "exercise2.h"

void push_back(int*& inputArray, const unsigned int& size, const int& value)
{
    unsigned int newSize = size + 1U;
    int* temp = new int[newSize]{};
    for (unsigned int i = 0; i < size; i++)
    {
        temp[i] = inputArray[i];
    }

    temp[size] = value;

    delete[] inputArray;
    inputArray = temp;
}

void pop_back(int*& inputArray, const unsigned int& size)
{
    int* temp = new int[size - 1];
    for (unsigned int i = 0; i < size - 1; i++)
    {
        temp[i] = inputArray[i];
    }

    delete[] inputArray;
    inputArray = temp;
}
