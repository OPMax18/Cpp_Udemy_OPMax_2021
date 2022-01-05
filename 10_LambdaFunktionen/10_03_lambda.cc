#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{

    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    // replace_if
    std::cout << "replace_if: \n";
    const int replace_value = 42U;
    const int check_value = 2U;
    std::vector<int> my_result_1(my_vector.begin(), my_vector.end());
    std::replace_if(
        my_result_1.begin(),
        my_result_1.end(),
        [&check_value](const auto val) { return val == check_value; },
        replace_value);
    print_vector(my_result_1);

    // sort:
    std::cout << "sort: \n";
    std::vector<int> my_result_2(my_vector.begin(), my_vector.end());
    std::sort(my_result_2.begin(), my_result_2.end(), [](const auto val1, const auto val2) { return val1 > val2; });

    print_vector(my_result_2);

    // sort - auslagern an eine variable:
    std::cout << "sort - sorting ausgelagert an variable: \n";
    std::vector<int> my_result_3(my_vector.begin(), my_vector.end());
    auto sorting = [](const auto val1, const auto val2) { return val1 > val2; };
    std::sort(my_result_3.begin(), my_result_3.end(), sorting);
    print_vector(my_result_3);

    // sort - generic lambda => Verwendung von auto in der Lambda Funktion
    // (schon passiert):
    std::cout << "sort - generic lambda: \n";

    auto sorting_2 = [](const auto val1, const auto val2) { return val1 < val2; };
    std::sort(my_result_3.begin(), my_result_3.end(), sorting_2);
    print_vector(my_result_3);

    return 0;
}
