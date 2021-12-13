#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t count)
{
    std::cout << "allocating \n";
    return malloc(count);
}

void do_something1(const std::string& s)
{
    std::cout << "s " << s << "\n";
}

void do_something2(std::string_view sv)
{
    std::cout << "sv " << sv << "\n";
}
int main()
{
    std::string s("Hi, my name is Jan and i am your instructor. ");

    std::string subS(s.substr(4, 32));
    do_something1(subS);

    do_something1("Hi, my name is Jan and i am your instructor. ");
    do_something2("Hi, my name is Jan and i am your instructor. ");

    return 0;
}
