#include <iostream>
#include <string>

void print_result(const std::size_t& index)
{
    if (index != std::string::npos)
    {
        std::cout << "Substring found @index = " << index << "\n\n";
    }
    else
    {
        std::cout << "Substring not found!"
                  << "\n"
                  << "Index = " << index << "\n"
                  << "\n";
        ;
    }
}

int main()
{

    std::string s = "Hallo das ist ein Text";

    std::size_t index = s.find("Hello");
    // Rückgabe npos (max von size_t) wenn nicht gefunden
    print_result(index);

    index = s.find("Hallo");
    // Nun gefunden
    print_result(index);

    index = s.find("ll");
    print_result(index);

    index = s.find('x');
    print_result(index);

    return 0;
}
