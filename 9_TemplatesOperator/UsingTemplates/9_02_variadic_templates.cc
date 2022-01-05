#include <iostream>
#include <map>
#include <string>
#include <vector>

// Vor C++17
// template <typename T>
// T concat(T first)
// {
//     return first;
// }

// template <typename T, typename... Args>
// T concat(T first, Args... args)
// {
//     return first + concat(args...);
// }

// Mit C++17
template <typename T, typename... Args>
T concat(Args... args)
{
    return (args + ...);
}


int main()
{
    std::string s1 = "Ha";
    std::string s2 = "ll";
    std::string s3 = "o";

    // first=s1, ...args=[s2,s3]
    // first=s2, ...args=[s3]
    // first=s3, ...args=[]
    // Vor C++17
    //std::cout << "string: " << concat(s1, s2, s3) << "\n";
    //std::cout << "string: " << concat(2, 3, 4) << "\n";

    // Mit C++17
    std::cout << "string: " << concat<std::string>(s1, s2, s3) << "\n";
    std::cout << "string: " << concat<int>(2, 3, 4) << "\n";

    return 0;
}
