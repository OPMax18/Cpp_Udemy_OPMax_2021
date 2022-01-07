#include <iostream>
#include <thread>

void print_text_1()
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
}


void print_text_2(int number)
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
    std::cout << "number: \t" << ++number << "\n";
}


void print_text_3(int& number)
{
    std::cout << "Thread is executing! ID: " << std::this_thread::get_id() << "\n";
    std::cout << "number: \t" << ++number << "\n";
}


int main()
{
    // Übergabe der Funktion an den thread
    std::thread t1(print_text_1);

    //Abfrage, ob der thread fertig ist
    if (t1.joinable())
    {
        //warten bis der thread fertig ist
        t1.join();
    }

    int n = 0;
    std::thread t2(print_text_2, n);
    //Abfrage, ob der thread fertig ist
    if (t2.joinable())
    {
        //warten bis der thread fertig ist
        t2.join();
    }

    int m = 5;
    std::thread t3(print_text_3, std::ref(m));
    //Abfrage, ob der thread fertig ist
    if (t3.joinable())
    {
        //warten bis der thread fertig ist
        t3.join();
    }

    return 0;
}
