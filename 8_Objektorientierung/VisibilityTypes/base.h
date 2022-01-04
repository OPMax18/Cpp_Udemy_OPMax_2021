#pragma once

#include <iostream>

class A
{
public: // in base class, in derived class and outside of the classes
    int x;

protected: // in base class and in derived class, not outside of the classes
    int y;

private: // only in base class, not in derived class, not outside of the classes
    int z;
};

// ##################### public inheritage
class B : public A // visibility remains
{
    // x is public
    // y is protected
    // z is private - is not accessible from B
public:
    void foo()
    {
        std::cout << x << "\n";
        std::cout << y << "\n";
        //std::cout << z << "\n"; => inaccessible
    }
};

// ##################### protected inheritage
class C : protected A // visibility changes from public to protected
{
    // x is protected
    // y is protected
    // z is not accessible from C
public:
    void foo()
    {
        std::cout << x << "\n";
        std::cout << y << "\n";
        //std::cout << z << "\n"; => inaccessible
    }
};

class C_derived : public C
{
    // x is protected
    // y is protected
    // z is not accessible from C
public:
    void foo()
    {
        std::cout << x << "\n";
        std::cout << y << "\n";
        //std::cout << z << "\n"; => inaccessible
    }
};


// ##################### private inheritage
class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from C
public:
    void foo()
    {
        std::cout << x << "\n";
        std::cout << y << "\n";
        //std::cout << z << "\n"; => inaccessible
    }
};

class D_derived : public D
{
    // x is protected
    // y is protected
    // z is not accessible from C
public:
    void foo()
    {
        //std::cout << x << "\n"; => inaccessible
        //std::cout << y << "\n"; => inaccessible
        //std::cout << z << "\n"; => inaccessible
    }
};
