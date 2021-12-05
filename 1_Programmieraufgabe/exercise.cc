// Hier die benötigten Includes und using Befehle
#include "exercise.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

// Hier die Definition der Funktion
void evaluation(int i, int j)
{
    string res;
    if ((i + j) % 2 == 1)
        res = "Ungerade";
    else
        res = "Gerade";
    cout << endl << "Die Summe von i: " << i << " und j: " << j << " ist " << res << endl;
}

void mod_cross_sum(int I, int J)
{
    for (int k = 0; k < I; k++)
    {
        for (int m = 0; m < J; m++)
        {
            evaluation(k, m);
        }
    }
}
