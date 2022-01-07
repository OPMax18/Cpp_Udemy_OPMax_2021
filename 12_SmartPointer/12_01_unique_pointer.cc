#include <iostream>
#include <memory>

class ScopeTest
{
public:
    ScopeTest(int val) : m_val(val)
    {
        std::cout << "Constructor " << m_val << "\n";
    }
    ~ScopeTest()
    {
        std::cout << "Destructor"
                  << "\n";
    }

    void test()
    {
        std::cout << "Test"
                  << "\n";
    }

private:
    int m_val;
};


void f3(std::unique_ptr<ScopeTest> p)
{
}

void f4(std::unique_ptr<ScopeTest>& p)
{
    p->test();
}

void f1()
{
    std::unique_ptr<ScopeTest> t = std::make_unique<ScopeTest>(10);
    t->test();
    //f3(t); // => das funktioniert hier so nicht, da der copy constructor für unique_ptr gelöscht ist => sonst würden zwei Werte auf den pointer zeigen
    f4(t);
}


void f2()
{
    ScopeTest* t2 = new ScopeTest(10);
    t2->test();

    delete t2;
}

int main()
{
    std::cout << "unique pointer now "
              << "\n";
    f1();
    std::cout << "raw pointer now "
              << "\n";
    f2();
    return 0;
}
