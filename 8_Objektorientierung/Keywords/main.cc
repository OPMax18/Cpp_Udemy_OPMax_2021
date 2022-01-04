#include "animal.h"
#include <iostream>


void poly_favourite_fool(Animal& animal)
{
    animal.my_favourite_food();
}

int main()
{
    {
        std::string animal_name = "Tatze";
        Animal* animal1 = new Animal(animal_name);
        //animal1.my_favourite_food();
        poly_favourite_fool(*animal1);
        delete animal1;
    }

    std::cout << "\n";
    {
        std::string dog_name = "Bello";
        //Dog* dog1 = new Dog(dog_name);
        Animal* dog1 = new Dog(dog_name);
        //dog1.my_favourite_food();
        poly_favourite_fool(*dog1);
        delete dog1;
    }

    return 0;
}
