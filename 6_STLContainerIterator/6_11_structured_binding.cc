#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

// Nicht so optimale Art Werte an die aufrufende Funktion zurückgeben
void get_data_old(int& a, std::string& b, double& c)
{
    a = 1337;
    b = "data";
    c = 1337.0;
}

// Besser Werte auf diese Art und Weise an die aufrufende Funktion zurückgeben
std::tuple<int, std::string, double> get_data()
{
    return std::make_tuple(1337, "data", 1337.0);
}


int main()
{

    int a;
    std::string b;
    double c;

    get_data_old(a, b, c);
    std::cout << "a: \t" << a << "\n";
    std::cout << "b: \t" << b << "\n";
    std::cout << "c: \t" << c << "\n";

    // frühere ungünstige Variante der Rückgabe mit tuple
    const auto ret = get_data();
    std::cout << "ret 1: \t" << std::get<0>(ret) << "\n";
    std::cout << "ret 2: \t" << std::get<1>(ret) << "\n";
    std::cout << "ret 3: \t" << std::get<2>(ret) << "\n";

    // Ab C++17 => structured binding
    const auto [id, name, score] = get_data();
    std::cout << "id: \t" << id << "\n";
    std::cout << "name: \t" << name << "\n";
    std::cout << "score: \t" << score << "\n";


    return 0;
}
