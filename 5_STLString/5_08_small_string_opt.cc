#include <cstdlib>
#include <iostream>
#include <string>


int main()
{
    // Empty String
    {
        auto str = std::string();
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof : \t" << size << "\n";
        std::cout << "capacity : \t" << capacity << "\n";
    }

    // Before Threshold String
    {
        auto str = std::string(15, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof : \t" << size << "\n";
        std::cout << "capacity : \t" << capacity << "\n";
    }

    // After Threshold String
    {
        auto str = std::string(16, '*');
        auto size = sizeof(str);
        auto capacity = str.capacity();
        std::cout << "sizeof : \t" << size << "\n";
        std::cout << "capacity : \t" << capacity << "\n";
    }

    return 0;
}
