#include <fstream>
#include <iostream>
#include <string>

std::string read_text(const std::string& path)
{
    std::string str;
    std::string text;

    std::ifstream iffile;
    iffile.open(path);

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + '\n';
        }
    }
    iffile.close();
    return text;
}

void write_text(const std::string& path, const std::string& text)
{

    std::ofstream offile;
    offile.open(path);

    if (offile.is_open())
    {
        offile << text;
    }
    offile.close();
}

int main()
{

    std::string text = read_text("Text.txt");
    std::cout << "Text.txt: \n\n" << text << "\n";

    std::string search_str = "drei";
    auto idx = text.find(search_str);
    std::cout << "idx: " << idx << "\n";

    search_str = "vier";
    idx = text.find(search_str);
    std::cout << "idx: " << idx << "\n";

    if (idx == std::string::npos)
    {
        std::cout << "String not found!"
                  << "\n\n";
    }

    std::string text2 = "bababcab";
    std::string search_string2 = "ab";
    auto idx2 = text2.find(search_string2);
    std::cout << "find Idx2: " << idx2 << "\n";

    auto idx3 = text2.rfind(search_string2);
    std::cout << "rfind idx3: " << idx3 << "\n";

    // Suche nach dem ersten Vorkommen eines char, der nicht Inhalt vom search_string sind (nicht (a oder b))
    auto idx4 = text2.find_first_not_of(search_string2);
    std::cout << "find_first_not_of idx4: " << idx4 << "\n";

    // Suche nach dem letzten Vorkommen eines char, der nicht Inhalt vom search_string sind (nicht (a oder b))
    auto idx5 = text2.find_last_not_of(search_string2);
    std::cout << "find_last_not_of idx5: " << idx5 << "\n";

    // Hier wird nach dem ersten Vorkommen eines der char aus dem search_string gesucht (a oder b)
    auto idx6 = text2.find_first_of(search_string2);
    std::cout << "find_first_of idx6: " << idx6 << "\n";

    // Hier wird nach dem letzten Vorkommen eines der char aus dem search_string gesucht (a oder b)
    auto idx7 = text2.find_last_of(search_string2);
    std::cout << "find_last_of idx7: " << idx7 << "\n";

    return 0;
}
