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

    // remove_if, erase
    std::cout << "remove_if and erase: \n";

    std::vector<int> my_result_1(my_vector.begin(), my_vector.end());
    my_result_1.erase(std::remove_if(my_result_1.begin(),
                                     my_result_1.end(),
                                     [](const auto val) {
                                         if (val > 5)
                                         {
                                             return true;
                                         }
                                         else
                                         {
                                             return false;
                                         }
                                     }),
                      my_result_1.end());
    print_vector(my_result_1);

    // remove_if, erase: capture variable
    int upper_bound = 3U;
    std::cout << "remove_if and erase with capture variable: \n";
    std::vector<int> my_result_2(my_vector.begin(), my_vector.end());
    my_result_2.erase(std::remove_if(my_result_2.begin(),
                                     my_result_2.end(),
                                     [&upper_bound](const auto val) {
                                         if (val > upper_bound)
                                         {
                                             return true;
                                         }
                                         else
                                         {
                                             return false;
                                         }
                                     }),
                      my_result_2.end());
    print_vector(my_result_2);

    return 0;
}
