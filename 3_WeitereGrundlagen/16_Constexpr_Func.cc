#include <iostream>

//#define NUM_VEHICLES 3
constexpr int kDefaultVehicleId = -1;
constexpr unsigned kNumVehicles = 3;

using std::cin;
using std::cout;
using std::endl;

// Auftrag an den Compiler, wenn du das Ergebnis der Function schon zur Compiletime
// bestimmen kannst (z.B. bei faculty(3)), dann mach das bitte, ansonsten wird das
// Ergebnis der Funktion erst zur Runtime berechnet => man könnte eigentlich nur gewinnen ;-)
constexpr int faculty(int n)
{
    if (n > 1)
    {
        return n * faculty(n - 1);
    }
    else
    {
        return 1;
    }
}


int main()
{

    int i = faculty(3);

    return 0;
}
