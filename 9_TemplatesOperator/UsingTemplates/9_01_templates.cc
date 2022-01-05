#include <iostream>
#include <map>
#include <vector>

typedef std::map<int, std::vector<double>> UserData;

template <typename T_Data>
// Das funktioniert nicht mit typedef
//typedef std::map<int, std::vector<T_Data>> UserData_2;
// aber mit using
using UserData_2 = std::map<int, std::vector<T_Data>>;

template <typename T>
T max(T value_1, T value_2)
{
    if (value_1 < value_2)
    {
        return value_2;
    }
    else
    {
        return value_1;
    }
}


int main()
{
    int a = 1;
    int b = 9;
    std::cout << "Result int: " << max(a, b) << "\n";

    float c = 11.0f;
    float d = 13.0f;
    std::cout << "Result float: " << max(c, d) << "\n";

    double e = 11.7;
    double f = 13.9;
    std::cout << "Result double: " << max(e, f) << "\n";

    UserData_2<double> my_double_data;
    UserData_2<float> my_float_data;
    UserData_2<int> my_int_data;

    return 0;
}
