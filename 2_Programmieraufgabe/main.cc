#include "exercise_2.h"


using std::cin;
using std::cout;
using std::endl;

int main()
{

    // Aufgabe 1:
    const unsigned int array_length = 100U;
    double pArraySum;
    double* ptrArrayDouble;
    ptrArrayDouble = new double[array_length];
    for (unsigned int i = 0U; i < array_length; i++)
    {
        ptrArrayDouble[i] = i;
    }
    pArraySum = array_sum(ptrArrayDouble, array_length);
    cout << endl << endl << "pArraySum: " << pArraySum << "\n\n";
    delete[] ptrArrayDouble;
    ptrArrayDouble = nullptr;

    // Aufgabe 2:
    int* ptrArrayInt;
    unsigned int lengthArray{0};
    unsigned int valueArray{0};
    cout << "Let's construct an array!\n";
    cout << "Please fill in the length: \n";
    cin >> lengthArray;
    cout << "With which integer value for filling the array: \n";
    cin >> valueArray;
    ptrArrayInt = array_constructor(valueArray, lengthArray);
    for (unsigned int k = 0; k < lengthArray; k++)
    {
        cout << "ptrArrayInt@" << k << " = " << ptrArrayInt[k] << "\n";
    }
    delete[] ptrArrayInt;
    ptrArrayInt = nullptr;

    return 0;
}
