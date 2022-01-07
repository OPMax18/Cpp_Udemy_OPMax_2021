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

    std::shared_ptr<ScopeTest> m_partner;

private:
    int m_val;
};

void f1()
{
    std::shared_ptr<ScopeTest> t = std::make_shared<ScopeTest>(10);
    t->test();

    std::cout << "Count before: " << t.use_count() << "\n";
    {
        std::shared_ptr<ScopeTest> t2 = t;
        t2->test();
        std::cout << "Count in: " << t.use_count() << "\n";
    }
    std::cout << "Count after: " << t.use_count() << "\n";
}

void f2()
{
    ScopeTest* t3 = new ScopeTest(10);
    t3->test();
    delete t3;
}

void f3()
{
    auto t4 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t4: " << t4.use_count() << "\n";
    auto t5 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t5: " << t5.use_count() << "\n";

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << "\n";
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << "\n";
}

int main()
{
    std::cout << "shared pointer now "
              << "\n";
    f1();
    std::cout << "raw pointer now "
              << "\n";
    f2();
    std::cout << "cycled shared pointer now "
              << "\n";
    f3();
    return 0;
}
