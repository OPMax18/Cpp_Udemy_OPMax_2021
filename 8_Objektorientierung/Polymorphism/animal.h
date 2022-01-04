#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const std::string& name) : m_name(name)
    {
        std::cout << "Animal Constructor!\n";
    }
    ~Animal()
    {
        std::cout << "Animal Destructor!\n";
    }
    virtual void my_favourite_food()
    {
        std::cout << "Salad!\n";
    }

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
    void my_favourite_food() override
    {
        std::cout << "Meat!\n";
    }
};
