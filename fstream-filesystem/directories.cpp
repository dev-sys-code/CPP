#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    fs::path targetDir{"."};

    for (const auto& entry : fs::directory_iterator(targetDir)) {
        std::cout << entry.path().filename() << "(Size: "
                  << (entry.is_regular_file() ? std::to_string(entry.file_size()) : "N/A")
                  << " bytes)";
    }
}