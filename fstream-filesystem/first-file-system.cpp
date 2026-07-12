#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main()
{   
    fs::path Path{"data.txt"};
    using std::cout;

    if (fs::exists(Path)) {
        cout << "File found";
        std::ifstream file(Path);
        std::string line{};

        while (std::getline(file, line)) {
            cout << line << "\n";
        }
    } else {
        cout << "File doesn't exist sorry.";
    }
    return 0;
}
