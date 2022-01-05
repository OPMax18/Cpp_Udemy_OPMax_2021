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

int check_even(const int val)
{
    if (val % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    //transform: element-wise operations
    std::cout << "transform: \n";
    std::vector<int> my_result(10, 0); // muss bei transform gleich groß sein
    //std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), check_even);
    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), [](auto val) {
        if (val % 2 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    });

    print_vector(my_result);

    // copy_if
    std::cout << "copy_if: \n";
    std::vector<int> my_result_2;

    // hier muss der backinserter verwendet werden, da my_result_2 erst mal
    // keine Länge, sprich auch keinen begin() iterator hat.
    std::copy_if(my_vector.begin(), my_vector.end(), std::back_inserter(my_result_2), [](const auto val) {
        if (val % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    print_vector(my_result_2);

    return 0;
}
