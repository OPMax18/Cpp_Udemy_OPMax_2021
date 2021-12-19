#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> myVector(5U, 0U);
    std::iota(myVector.begin(), myVector.end(), 0U);

    std::vector<int> myVector2(5U, 0U);
    std::iota(myVector2.begin(), myVector2.end(), 5U);

    std::vector<int> myVector3;

    // Inserter (Container needs the insert method)
    std::copy(myVector.begin(), myVector.end(), std::inserter(myVector3, myVector3.end()));
    std::copy(myVector2.begin(), myVector2.end(), std::inserter(myVector3, myVector3.begin() + 2));


    std::cout << "Inserter: \n";
    std::cout << "myVector3: \t";
    for (const auto& value : myVector3)
    {
        std::cout << value << "\t";
    }
    std::cout << "\n";

    std::vector<int> myVector4;

    // Backinserter (Container needs the push_back method)
    std::copy(myVector.begin(), myVector.end(), std::back_inserter(myVector4));
    std::copy(myVector2.begin(), myVector2.end(), std::back_inserter(myVector4));

    std::cout << "Back Inserter: \n";
    std::cout << "myVector4: \t";
    for (const auto& value : myVector4)
    {
        std::cout << value << "\t";
    }
    std::cout << "\n";

    // Front Inserter (Container needs the push_front method) => kein vector sonder list

    std::list<int> myList1(5, 0);
    std::iota(myList1.begin(), myList1.end(), 10U);

    std::list<int> myList2(5, 0);
    std::iota(myList2.begin(), myList2.end(), 15U);

    std::list<int> myList3;

    std::copy(myList1.begin(), myList1.end(), std::front_inserter(myList3));
    std::copy(myList2.begin(), myList2.end(), std::front_inserter(myList3));

    std::cout << "Back Inserter: \n";
    std::cout << "myList3: \t";
    for (const auto& value : myList3)
    {
        std::cout << value << "\t";
    }
    std::cout << "\n";

    return 0;
}
