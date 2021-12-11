#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

void print_int_vector(const std::vector<int>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << "\n";
    }
    std::cout << "\n";
}

int main()
{
    auto i = 3.5;
    auto j = static_cast<int>(i);

    auto k = double{0.0f};
    auto l{0.0f};
    auto m{0};
    auto n{0U};
    auto o{0L};

    // Hier gibt's eine Compiler Warnung und es kann kein
    // impliziter type cast erfolgen wie bei:
    // double b = 2.0;
    // int c = b;
    // auto p = int{1.2};
    // int q{1.2};

    std::cout << i << "\n" << j << "\n" << k << "\n" << l << "\n" << m << "\n" << n << "\n" << o << "\n";
    //   << p << "\n"
    //   << q << "\n";

    return 0;
}
