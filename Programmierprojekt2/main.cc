#include "AlgoArray.h"
#include "DynArray.h"

int main()
{
    // Aufgabe 1:
    // DynamicArray dynamicArray = {.m_data = nullptr, .m_length = 0};
    double fillValue = 1.0;
    std::size_t fillLength = 0;
    DynamicArray<double> myArray(fillValue, fillLength);

    myArray.push_back(0.0);
    myArray.push_back(1.0);
    myArray.push_back(2.0);
    myArray.push_back(3.0);
    myArray.push_back(4.0);

    cout << "Pushback: \n";
    for (std::size_t k = 0; k < myArray.get_length(); ++k)
    {
        cout << myArray[k] << "\n";
    }

    myArray.pop_back();
    myArray.pop_back();
    cout << "Popback: \n";
    for (std::size_t k = 0; k < myArray.get_length(); ++k)
    {
        cout << myArray[k] << "\n";
    }


    cout << "myMean: " << mean(myArray) << "\n";
    cout << "myMedian: " << median(myArray) << "\n";
    cout << "myVariance: " << variance(myArray) << "\n";
    cout << "myStdDev: " << stddev(myArray) << "\n";


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
