#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>


int main()
{

    std::vector<int> myVector = {1U, 2U};

    for (std::size_t i = 0U; i < myVector.size(); ++i)
    {
        std::cout << "MyVector: " << &myVector[i] << "\n";
    }
    std::cout << "\n";

    std::list<int> myList = {1U, 2U, 3U};

    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << "myList: " << *it << " " << &*it << "\n";
    }
    std::cout << "\n";

    myList.push_front(0);
    myList.push_back(4);
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        std::cout << "myList: " << *it << " " << &*it << "\n";
    }
    std::cout << "\n";


    return 0;
}
