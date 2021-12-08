#include "Lib.h"

// 1.) global static variable
// 2.) static variable in a function
// (3.) static function)


int main()
{
    function();
    function();

    // funktioniert so nicht, da nur in der Compilierungseinheit deklariert
    //data[0] = 2;
    return 0;
}
