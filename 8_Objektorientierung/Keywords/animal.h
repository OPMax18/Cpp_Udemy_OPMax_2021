#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    //Animal() = default;
    //Animal() = delete;

    Animal(const std::string& name) : m_name(name)
    {
        std::cout << "Animal Constructor!\n";
    }
    virtual ~Animal()
    {
        std::cout << "Animal Destructor!\n";
    }
    virtual void my_favourite_food()
    {
        std::cout << "Salad!\n";
    }

    //virtual void make_a_sound() = 0;

private:
    const std::string m_name;
};

class Dog : public Animal
{
public:
    Dog(const std::string& name) : Animal(name)
    {
        std::cout << "Dog Constructor!\n";
    }
    ~Dog()
    {
        std::cout << "Dog Destructor!\n";
    }
    void my_favourite_food() final
    {
        std::cout << "Meat!\n";
    }
};
