#include <fstream>
#include <iostream>
#include <string>

int main()
{

    std::string str;
    std::string text;

    std::ifstream iffile;
    iffile.open("/mnt/d/001_Know_How/008c_Cpp_Udemy_2021/Cpp_Udemy_OPMax_2021/5_STLString/text.txt");
    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + '\n';
        }
    }
    iffile.close();

    std::cout << "Text.txt: \n\n" << text << "\n";

    return 0;
}
