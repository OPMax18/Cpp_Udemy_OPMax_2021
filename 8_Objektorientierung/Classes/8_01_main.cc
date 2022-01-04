#include "8_01_image.h"
#include <iostream>

int main()
{
    Image my_image(400, 400);
    my_image.save_image("image.bmp");


    std::cout << "Height: " << my_image.get_height() << "\n";
    my_image.set_height(200);
    std::cout << "Height: " << my_image.get_height() << "\n";

    return 0;
}
