#include "AlgoArray.h"
#include "DynArray.h"
#include <vector>

template <typename T_Data>
DynamicArray<T_Data> foo()
{
    return DynamicArray<T_Data>(1.0, 3);
}


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

    DynamicArray<double> array_1(1.0, 3U);
    DynamicArray<double> array_2(-1.0, 4U);

    std::cout << "Now the part of Copy constructor/ assignment operator! \n";
    array_1 = array_2; // coyp assignment operator

    DynamicArray<double> array_3(array_1);    // copy constructor
    DynamicArray<double> array_4 = array_1;   // copy constructor
    DynamicArray<double> array_5{array_1};    // copy constructor
    DynamicArray<double> array_6 = {array_1}; // copy constructor

    // Vereinfachtes Beispiel
    std::cout << "\nNow the part of Move constructor/ assignment operator! \n";
    DynamicArray<double> array_7 =
        foo<double>(); // move constructor, wird vom Compiler schon durchgeführt - funktioniert so nicht
    DynamicArray<double> array_8 = std::move(array_6); // move constructor
    array_7 = std::move(array_5);                      // move assignment operator

    std::vector<int> v1 = std::vector<int>(
        1,
        2); // => hier wird der move constructor genutzt um den rvalue sofort in das linke objekt zu überführen

    return 0;
}
