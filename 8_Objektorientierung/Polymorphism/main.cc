#include "animal.h"
#include <iostream>


void poly_favourite_food(Animal& animal)
{
    animal.my_favourite_food();
}

int main()
{
    {
        std::string animal_name = "Tatze";
        Animal animal1(animal_name);
        //animal1.my_favourite_food();
        poly_favourite_food(animal1);
    }

    std::cout << "\n";
    {
        std::string dog_name = "Bello";
        Dog dog1(dog_name);
        //dog1.my_favourite_food();
        poly_favourite_food(dog1);
    }

    return 0;
}
