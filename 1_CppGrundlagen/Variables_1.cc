#include <iostream>

int main()
{
    // 1. ################################
    // double myVar = 13.37;
    // myVar = 24.02;

    // 2. ################################
    // double number1 = 10.0;
    // double number2 = 2.0;
    // double result = 0.0;

    // result = number1 * number2;
    // std::cout << "number1 * number2 = " << result << "\n";

    // result = number1 + number2;
    // std::cout << "number1 + number2 = " << result << "\n";

    // result = number1 - number2;
    // std::cout << "number1 - number2 = " << result << "\n";

    // result = number1 / number2;
    // std::cout << "number1 / number2 = " << result << "\n";

    // 3. ################################
    // char myValue1 = 10;        // 1 byte =  8bit = 2^8
    // short myValue2 = 42;       // 2 byte = 16bit = 2^16
    // int myValue3 = 13;         // 4 byte = 32bit = 2^32
    // long long myValue4 = 4200; // 8 byte = 64bit = 2^64

    // float myValue5 = 42.00f;  // 4 byte = 32bit = 2^32
    // double myValue6 = 42.456; // 8 byte = 64bit = 2^64

    // 17. ASCI Tabelle
    // Singel Character
    // Okay: ''
    // Forbidden: ""
    // char my_character = 'A';

    // 20 Einlesen aus der Konsole
    double number1;
    double number2;
    double result = 0.0;

    std::cout << "Please enter a number: ";
    std::cin >> number1;

    std::cout << "Please enter an other number: ";
    std::cin >> number2;

    result = number1 * number2;
    std::cout << "number1 * number2 = " << result << "\n";

    result = number1 + number2;
    std::cout << "number1 + number2 = " << result << "\n";

    result = number1 - number2;
    std::cout << "number1 - number2 = " << result << "\n";

    result = number1 / number2;
    std::cout << "number1 / number2 = " << result << "\n";


    return 0;
}
