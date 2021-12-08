#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


// call is possible with every kind of LValue and RValue
void foo(int v)
{
    cout << v << "\n";
}

// // call is possible only with non const LValue
// void foo(int& v)
// {
//     cout << v << "\n";
// }

// // call is possible with every kind of LValue and RValue (=special case)
// void foo(const int& v)
// {
//     cout << v << "\n";
// }

int main()
{

    int a = 3;        // LValue
    const int b = 3;  // const LValue
    int& c = a;       // LValue reference
    const int& d = a; // const LValue reference

    // Call-by-Value
    foo(a);
    foo(b);
    foo(c);
    foo(d);
    foo(3);


    return 0;
}
