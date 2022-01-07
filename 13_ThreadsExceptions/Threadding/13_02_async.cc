#include <future>
#include <iostream>
#include <thread>

int print_text_1()
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
    return 10;
}


int print_text_2(int number)
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
    std::cout << "number: \t" << ++number << "\n";
    return 20;
}


int print_text_3(int& number)
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
    std::cout << "number: \t" << ++number << "\n";
    return 30;
}


int main()
{
    // Übergabe der Funktion an den thread
    auto handle_1 = std::async(std::launch::async, print_text_1);
    std::cout << "handle_1 result: \t" << handle_1.get() << "\n";

    int n = 0;
    auto handle_2 = std::async(std::launch::async, print_text_2, n);
    std::cout << "handle_2 result: \t" << handle_2.get() << "\n";

    int m = 5;
    auto handle_3 = std::async(std::launch::async, print_text_3, std::ref(m));
    std::cout << "handle_3 result: \t" << handle_3.get() << "\n";

    return 0;
}
