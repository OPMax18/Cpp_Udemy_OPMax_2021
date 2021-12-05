#include <iostream>

int main()
{
    double sideLength = 0.0;
    double perimeter = 0.0;
    double area = 0.0;

    std::cout << "Please enter the side length of a square: ";
    std::cin >> sideLength;

    perimeter = 4.0 * sideLength;
    area = sideLength * sideLength;
    std::cout << "Perimeter = " << perimeter << "\n";
    std::cout << "Area = " << area << "\n";

    return 0;
}
