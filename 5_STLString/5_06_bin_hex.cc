#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

int main()
{

    std::bitset<8> myByte(std::string("00011101"));
    std::bitset<8> myByte_2(std::string("10010101"));

    std::cout << "myByte :\t" << myByte << "\n";
    std::cout << "myByte_2 :\t" << myByte_2 << "\n\n";

    std::cout << "AND \t\t myByte & myByte_2 :\t" << (myByte & myByte_2) << "\n";
    std::cout << "OR \t\t myByte | myByte_2 :\t" << (myByte | myByte_2) << "\n";
    std::cout << "XOR \t\t myByte ^ myByte_2 :\t" << (myByte ^ myByte_2) << "\n";
    std::cout << "NEGATION \t\t ~myByte:\t " << (~myByte) << "\n\n\n";

    // Hexa
    // unsigned char => auch 8 bit groß
    unsigned char hex1 = 0x01; // 0000 0001
    unsigned char hex2 = 0xff; // 1111 1111

    std::cout << "AND \t\t hex1 & hex2 :\t" << (int)(hex1 & hex2) << "\n";
    std::cout << "OR \t\t hex1 | hex2 :\t" << (int)(hex1 | hex2) << "\n";
    std::cout << "XOR \t\t hex1 ^ hex2 :\t" << (int)(hex1 ^ hex2) << "\n";
    std::cout << "NEGATION \t\t ~hex1:\t " << (int)(~hex1) << "\n";

    return 0;
}
