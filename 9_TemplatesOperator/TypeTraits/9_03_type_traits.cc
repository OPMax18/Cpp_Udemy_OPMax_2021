#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

typedef std::map<int, std::vector<double>> UserData;

template <typename T_Data>
using UserData_2 = std::map<int, std::vector<T_Data>>;

template <typename T>
struct is_numeric : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
{
};

template <typename T, typename U>
T max(T value_1, U value_2)
{
    // 1. Möglichkeit
    // static_assert(std::disjunction<std::is_integral<T>, std::is_floating_point<T>>::value, "failed ...");
    // 2. Möglichkeit
    // static_assert(is_numeric<T>::value, "failed ...");
    // 2. Möglichkeit mit mehreren types
    static_assert(std::conjunction<is_numeric<T>, is_numeric<U>>::value, "failed ...");

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

    // Hier schlägt der static_assert beim Compilen an!!
    // struct A
    // {
    // };

    // A a1;
    // A a2;

    // max(a1, a2);

    return 0;
}
