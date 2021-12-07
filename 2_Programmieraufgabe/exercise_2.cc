#include "exercise_2.h"


double array_sum(double* ptrArray, const unsigned int& length)
{
    double arraySum = 0.0;

    for (unsigned int i = 0U; i < length; i++)
    {
        arraySum += ptrArray[i];
    }
    return arraySum;
}

int* array_constructor(const int& value, const unsigned int& length)
{
    int* ptrArrayInt = new int[length];
    for (unsigned int i = 0; i < length; i++)
    {
        ptrArrayInt[i] = value;
    }

    return ptrArrayInt;
}
