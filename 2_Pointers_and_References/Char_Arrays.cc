#include <iostream>

// &:   Memory Address               => Reference
// *p:  value at that memory adress  => Dereference

// int* intput_array <=> int input_array[] - both equivalent, but first is prefered
// int array_maximum(int input_array[], unsigned int arraySize)
int array_maximum(int* input_array, unsigned int arraySize)
{
    int maximum = input_array[0U];
    for (unsigned int i = 0U; i < arraySize; i++)
    {
        //if(input_array[i] > maximum) maximum = input_array[i] ;
        maximum = input_array[i] > maximum ? input_array[i] : maximum;
    }
    return maximum;
}

void print_name(char* name)
{
    std::cout << name << "\n";

    // the function get's only the pointer to the first element in the array!!
    // so in principle it works like the following code:
    // while (*name != '\0')
    // {
    //     std::cout << *name;
    //     name++;
    // }
}


int main()
{

    // Heap allocation
    int* ptrNumber = new int{4};

    unsigned int arraySize = 10U;

    int* ptrArray = new int[arraySize];

    // Size of the pointer itself in Bytes
    std::cout << "Sizeof(ptrArray) = " << sizeof(ptrArray) << "\n";
    // Size of the first array element, that the pointer points to in Bytes
    std::cout << "Sizeof(*ptrArray) = " << sizeof(*ptrArray) << "\n";

    for (unsigned int i = 0U; i < arraySize; i++)
    {
        ptrArray[i] = -1 * (i + 5U);
    }

    for (unsigned int i = 0U; i < arraySize; i++)
    {
        std::cout << "ptrArray@" << i << " = " << ptrArray[i] << "\n";
    }

    // address of the array - normally not necessary
    for (unsigned int i = 0U; i < arraySize; i++)
    {
        std::cout << "Address of ptrArray@" << i << " = " << &ptrArray[i] << "\n";
    }

    int maximum = array_maximum(ptrArray, arraySize);
    std::cout << "Maximum in ptrArray = " << maximum << "\n";

    // Heap de-allocation
    delete ptrNumber;
    ptrNumber = nullptr;

    delete[] ptrArray;
    ptrArray = nullptr;

    // works also for "normal" arrays
    int myArray[]{3, 4, 5, 6, 7};
    std::cout << "Maximum in myArray = " << array_maximum(myArray, 5) << "\n";

    // char array
    char name[]{"Prename Surname"};
    print_name(name);

    return 0;
}
