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

    // Operations:
    //     clear
    //     append
    //     compare
    //     replace
    //     substr

    std::string text_copy = text;
    std::cout << "text_copy: \n" << text_copy << "\n\n";
    text_copy.clear();
    std::cout << "text_copy: \n" << text_copy << "\n\n";

    std::string text_append = text + "vier\n";
    std::cout << "text_append: \n" << text_append << "\n\n";
    text_append.append("fünf\n");
    std::cout << "text_append: \n" << text_append << "\n\n";

    // welcher string ist größer und an welcher Stelle der Ascii Tabelle stehen die entsprechenden char
    // 0 bedeutet, dass beide Strings identisch sind
    auto text_compare = text_append.compare(text);
    std::cout << "text_compare: \n" << text_compare << "\n\n";
    text_copy = text_append;
    text_compare = text_append.compare(text_copy);
    std::cout << "text_compare: \n" << text_compare << "\n\n";

    std::string s1 = "Jann";
    std::cout << "s1: \n" << s1 << "\n\n";
    std::string search_string = "nn";
    auto idx = s1.find(search_string);
    s1.replace(idx, search_string.size(), "n");
    std::cout << "s1: \n" << s1 << "\n\n";

    std::string sub_str = s1.substr();
    std::cout << "sub_str: \n" << sub_str << "\n\n";
    sub_str = s1.substr(0, 2);
    std::cout << "sub_str: \n" << sub_str << "\n\n";

    return 0;
}
