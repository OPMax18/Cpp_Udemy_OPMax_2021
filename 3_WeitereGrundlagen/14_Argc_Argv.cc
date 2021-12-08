#include <cstdlib>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Argc: Argument Count
// Argv: Argument Values
int main(int argc, char** argv)
{
    // argv could be handled like a 2D char array
    for (int i = 0; i < argc; ++i)
    {
        cout << "argv: " << i << " = " << argv[i] << "\n";
    }

    if (argc > 1)
    {
        const char* arg1 = argv[1];
        cout << "arg1: " << arg1 << "\n";

        const char* arg2 = argv[2];
        cout << "arg2: " << arg2 << "\n";

        const char* arg3 = argv[3];
        cout << "arg3: " << arg3 << "\n";

        int arg4 = std::atoi(argv[4]);
        cout << "arg4: " << arg4 << "\n";
    }

    return 0;
}
