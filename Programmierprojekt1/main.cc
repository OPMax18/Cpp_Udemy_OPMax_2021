#include "AlgoArray.h"
#include "DynArray.h"

int main()
{
    // Aufgabe 1:
    // DynamicArray dynamicArray = {.m_data = nullptr, .m_length = 0};
    double fillValue = 1.0;
    std::size_t fillLength = 7;
    DynamicArray myArray = create_dynamic_arry(fillValue, fillLength);

    for (std::size_t k = 0; k < fillLength; k++)
    {
        if (k < 4)
        {
            myArray.m_data[k] = 1.5;
        }
        else
        {
            myArray.m_data[k] = k * 2.5;
        }
    }

    for (std::size_t k = 0; k < fillLength; k++)
    {
        cout << myArray.m_data[k] << "\n";
    }

    double myMean = mean(myArray);
    cout << "myMean: " << myMean << "\n";
    double myMedian = median(myArray);
    cout << "myMedian: " << myMedian << "\n";

    double myVariance = variance(myArray);
    cout << "myVariance: " << myVariance << "\n";
    double myStdDev = stddev(myArray);
    cout << "myStdDev: " << myStdDev << "\n";


    // dynamicArray.m_length = 3U;
    // for (std::size_t i = 0U; i < dynamicArray.m_length; i++)
    // {
    //     dynamicArray.m_data[i] = i * 1.0;
    // }

    // cout << "Start-values ot the array:\n";
    // for (std::size_t k = 0; k < dynamicArray.m_length; k++)
    // {
    //     cout << dynamicArray.m_data[k] << "\n";
    // }

    // // cout << "Let's add a new value to this array!\n";
    // // cout << "What's the new integer value: \n";
    // double newValue{12.0};
    // // cin >> newValue;
    // push_back(dynamicArray, newValue);
    // cout << "Append value 12 at the end:\n";
    // for (std::size_t k = 0; k < (dynamicArray.m_length + 1); k++)
    // {
    //     cout << dynamicArray.m_data[k] << "\n";
    // }

    // pop_back(dynamicArray);
    // cout << "Remove the last value:\n";
    // for (std::size_t k = 0; k < dynamicArray.m_length; k++)
    // {
    //     cout << dynamicArray.m_data[k] << "\n";
    // }

    return 0;
}
