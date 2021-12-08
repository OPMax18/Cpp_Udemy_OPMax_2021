#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1a. C++: static_cast<> - converts object from one type to another
// 1b. C:   (newDType)(varName)
// - Easier to read
// - compiler throws errors
// - less prone to errors

int main()
{
    double number1 = 3.14;
    cout << "number1: " << std::setprecision(20) << number1 << "\n";
    int number2 = number1;
    cout << "number2: " << std::setprecision(20) << number2 << "\n";

    // C-casting
    // (newDType)(varName)
    float number3 = (float)(number1);
    cout << "number3: " << std::setprecision(20) << number3 << "\n";

    // C++ -casting
    // static_cast<>
    float number4 = static_cast<float>(number1);
    cout << "number4: " << std::setprecision(20) << number4 << "\n";

    int number5 = 133700;
    char number6 = static_cast<char>(number5);
    cout << "number5: " << std::setprecision(20) << number5 << "\n";
    // // direct cout not possible, as it's interpreted as character
    // cout << "number6: " << std::setprecision(20) << number6 << "\n";
    cout << "number6: " << std::setprecision(20) << static_cast<int>(number6) << "\n";

    return 0;
}
