#include <algorithm>
#include <iostream>
#include <iterator>
#include <math.h>
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

double magnitude(std::vector<double>& vec)
{
    // 1.) square all values
    std::transform(vec.begin(), vec.end(), vec.begin(), [](const double val) { return std::pow(val, 2.0); });

    // 2.) Reduce
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);

    // 3.) Sqrt
    const double root = std::pow(sum, 0.5);

    return root;
}

int main()
{

    std::vector<double> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    // map_reduce_idiom
    std::cout << "map_reduce_idiom: \n";
    std::cout << magnitude(my_vector) << "\n";


    return 0;
}
