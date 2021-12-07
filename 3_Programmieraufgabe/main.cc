#include "exercise2.h"


using std::cin;
using std::cout;
using std::endl;

int main()
{

    // Aufgabe 1:
    const unsigned int arrayLength = 3U;
    int* ptrArrayInt = new int[arrayLength];
    for (unsigned int i = 0U; i < arrayLength; i++)
    {
        ptrArrayInt[i] = i;
    }

    cout << "Start-values ot the array:\n";
    for (unsigned int k = 0; k < arrayLength; k++)
    {
        cout << ptrArrayInt[k] << "\n";
    }

    // cout << "Let's add a new value to this array!\n";
    // cout << "What's the new integer value: \n";
    int newValue{12};
    // cin >> newValue;
    push_back(ptrArrayInt, arrayLength, newValue);
    cout << "Append value 12 at the end:\n";
    for (unsigned int k = 0; k < (arrayLength + 1); k++)
    {
        cout << ptrArrayInt[k] << "\n";
    }

    pop_back(ptrArrayInt, (arrayLength + 1));
    cout << "Remove the last value:\n";
    for (unsigned int k = 0; k < (arrayLength); k++)
    {
        cout << ptrArrayInt[k] << "\n";
    }

    delete[] ptrArrayInt;
    ptrArrayInt = nullptr;

    return 0;
}
