#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

int main()
{
    fs::path currentPath = fs::current_path();
    fs::path currentFilePath = fs::current_path();
    currentFilePath /= "5_11_filesystem.cc";
    std::cout << "currentFilePath: \t" << currentFilePath << "\n\n";

    for (auto it = fs::directory_iterator(currentPath); it != fs::directory_iterator{}; ++it)
    {
        std::cout << "Inhalt Loop: \t" << *it << "\n";
    }

    fs::path newDirectoryPath;
    newDirectoryPath /= fs::current_path();
    newDirectoryPath /= "test";

    if (!fs::exists(newDirectoryPath))
    {
        fs::create_directory(newDirectoryPath);
    }

    fs::path newFilePath;
    newFilePath /= newDirectoryPath;
    newFilePath /= "FileSystemCopy.cc";

    if (!fs::exists(newFilePath))
    {
        fs::copy_file(currentFilePath, newFilePath);
    }

    return 0;
}
