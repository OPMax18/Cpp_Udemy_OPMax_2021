#include "base.h"
#include <iostream>


int main()
{
    B my_b_class;
    my_b_class.foo();
    my_b_class.x;

    C my_c_class;
    my_c_class.foo();
    // my_c_class.x; => geht hier nicht mehr

    return 0;
}
