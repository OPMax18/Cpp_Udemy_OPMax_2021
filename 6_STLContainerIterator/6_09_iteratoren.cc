#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> myVector(5U, 0U);
    std::iota(myVector.begin(), myVector.end(), 10U);


    std::list<int> myList(5, 0);
    std::iota(myList.begin(), myList.end(), 10U);

    // Forward Iterator
    auto listIt1 = myList.begin();
    // geht in der List so nicht:
    // listIt1 += 2;
    std::advance(listIt1, 2);

    std::cout << "myVector: [2] " << myVector[2] << "\t"
              << "myList: advance(2) " << *listIt1 << "\n";


    auto dist = std::distance(listIt1, myList.end());
    std::cout << "myList => distance: " << dist << "\n";

    auto prev = std::prev(listIt1);
    auto next = std::next(listIt1);
    std::cout << "myList => prev: " << *prev << "\n";
    std::cout << "myList => next: " << *next << "\n";

    std::cout << "\n";


    return 0;
}
