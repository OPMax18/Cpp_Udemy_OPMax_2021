#include <iostream>
#include <map>
#include <string>

void print_map(std::map<std::string, int>& map)
{
    std::cout << "Map: "
              << "\n";
    for (const auto& value : map)
    {
        std::cout << "First: " << value.first << "\tSeconde: " << value.second << "\n";
    }
}

int main()
{

    std::map<std::string, int> myMap1;
    myMap1["Jan"] = 25;
    myMap1["Dennis"] = 27;
    myMap1["Donald"] = 31;
    myMap1["Jan"] = 28;

    print_map(myMap1);

    auto searchStr = "Jann";
    auto it = myMap1.find(searchStr);

    bool is_in = it != myMap1.end();
    std::cout << searchStr << " found? " << std::boolalpha << is_in << "\n";

    return 0;
}
