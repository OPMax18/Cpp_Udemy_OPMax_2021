#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using tuple_user_type = std::tuple<int, std::string, bool>;
using pair_user_type = std::pair<int, std::string>;

void print_pair(const pair_user_type& pair)
{
    std::cout << "Pair: \n";
    std::cout << pair.first << "\t";
    std::cout << pair.second << "\t";
    std::cout << "\n";
}

void print_tuple(const tuple_user_type& tuple)
{
    std::cout << "Tuple: \n";
    std::cout << std::get<0>(tuple) << "\t";
    std::cout << std::get<1>(tuple) << "\t";
    std::cout << std::boolalpha << std::get<2>(tuple) << "\t";
    std::cout << "\n";
}

void print_students(std::vector<tuple_user_type>& students)
{
    for (auto& student : students)
    {
        print_tuple(student);
    }
}

int main()
{


    tuple_user_type myTuple1(23, "Jan", true);
    print_tuple(myTuple1);

    tuple_user_type myTuple2 = std::make_tuple(25, "Donald", false);
    print_tuple(myTuple2);

    std::vector<tuple_user_type> students;
    students.push_back(myTuple1);
    students.push_back(myTuple2);
    print_students(students);

    pair_user_type myPair1(23, "Jan");
    print_pair(myPair1);

    pair_user_type myPair2 = std::make_pair(25, "Dennis");
    print_pair(myPair2);

    return 0;
}
