#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string birthday;

    std::cout << "Please enter your birthday (DD.MM.YYYY): ";
    std::cin >> birthday;
    std::cout << "Your birthday is: " << birthday << "\n";

    std::stringstream birthday_ss(birthday);
    unsigned int day, month, year;
    char c;

    birthday_ss >> day >> c >> month >> c >> year;
    std::cout << "Your birthday is: " << day << "." << month << "." << year << "\n";


    return 0;
}
