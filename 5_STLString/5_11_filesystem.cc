#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

int main()
{
    fs::path workspacePath = "/mnt/d/001_Know_How/008c_Cpp_Udemy_2021/Cpp_Udemy_OPMax_2021";
    fs::path chapterPath;
    chapterPath = workspacePath;
    chapterPath /= "5_STLString";

    std::cout << "workspacePath: \t\t" << workspacePath << "\n";
    std::cout << "chapterPath: \t\t" << chapterPath << "\n";

    fs::path currentFilePath = fs::current_path();
    currentFilePath /= "5_11_filesystem.cc";
    std::cout << "currentFilePath: \t" << currentFilePath << "\n\n";

    std::cout << "relative_path: \t\t" << currentFilePath.relative_path() << "\n";
    std::cout << "parent_path: \t\t" << currentFilePath.parent_path() << "\n";
    std::cout << "filename: \t\t" << currentFilePath.filename() << "\n";
    std::cout << "stem: \t\t\t" << currentFilePath.stem() << "\n";
    std::cout << "extension : \t\t" << currentFilePath.extension() << "\n\n";

    std::cout << "exists: \t\t" << std::boolalpha << fs::exists(currentFilePath) << "\n";
    std::cout << "is_regular_file: \t" << std::boolalpha << fs::is_regular_file(currentFilePath) << "\n";
    std::cout << "is_directory: \t\t" << std::boolalpha << fs::is_directory(currentFilePath) << "\n";

    return 0;
}
