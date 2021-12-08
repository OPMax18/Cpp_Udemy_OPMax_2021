#include "Lib.h"

// static vars werden schon zur Compiletime in den Speicher geschrieben
// und nicht erst bei Runtime => effizienter besonders beim fertigen Programm, da nicht erst
// die Variable geschrieben werden muss
static int data1[10]{};

void function()
{
    helper();
}

static void helper()
{
    // std::cout << "Hello World" << std::endl;
    // data1[0] = 1;
    // std::cout << data1[0] << "\n";

    static int data2[10]{};
    int data3[10]{};

    std::cout << "data1: " << data1[0] << "\n";
    std::cout << "data2: " << data2[0] << "\n";
    std::cout << "data3: " << data3[0] << "\n";

    data1[0] = -1;
    data2[0] = -1;
    data3[0] = -1;
}
