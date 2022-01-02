#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// In eurem Programm bitte:
// your_main zu main ändern
int main()
{
    // Aufgabe 1
    BinaryArray target(20, 0);

    std::random_device seed_generator{};
    std::mt19937_64 random_generator(seed_generator());
    std::bernoulli_distribution distribution(0.5);

    std::generate(target.begin(), target.end(), [&] { return distribution(random_generator); });
    print_bool_vector(target);

    BinaryArray input(target.begin(), target.end());
    std::shuffle(input.begin(), input.end(), random_generator);
    print_bool_vector(input);
    BinaryArray temp(input.begin(), input.end());

    // Aufgabe 2
    std::cout << "Starting exercise 2: \n";
    auto start_time = std::chrono::steady_clock::now();
    auto result = shuffle_till_equal(target, input);
    std::cout << "\n";
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Elapsed_time exercise 2 ms: \t" << elapsed_time_ms << "\n\n";
    std::cout << "target vector: \t";
    print_vector(target);
    std::cout << "input vector: \t";
    print_vector(input);
    std::cout << "result vector: \t";
    print_vector(result);

    // Aufgabe 3
    std::copy(temp.begin(), temp.end(), input.begin());
    std::cout << "\n\n";
    print_bool_vector(input);
    std::cout << "Starting exercise 3: \n";
    auto start_time_3 = std::chrono::steady_clock::now();
    auto result_3 = smart_shuffle_till_equal(target, input);
    //auto result_3 = shuffle_till_equal(target, input);
    std::cout << "\n";
    auto end_time_3 = std::chrono::steady_clock::now();
    auto elapsed_time_us_3 = std::chrono::duration_cast<std::chrono::microseconds>(end_time_3 - start_time_3).count();
    std::cout << "Elapsed_time exercise 3 us: \t" << elapsed_time_us_3 << "\n";
    std::cout << "target vector: \t";
    print_vector(target);
    std::cout << "input vector: \t";
    print_vector(input);
    std::cout << "result vector: \t";
    print_vector(result_3);

    cin.get();
    getchar();
    return 0;
}
