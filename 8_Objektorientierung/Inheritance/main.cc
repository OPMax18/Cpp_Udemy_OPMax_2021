#include "animal.h"
#include <iostream>


int main()
{
    {
        std::string animal_name = "Tatze";
        Animal animal1(animal_name);
    }

    std::cout << "\n";
    {
        std::string dog_name = "Bello";
        Dog dog1(dog_name);
    }

    return 0;
}
