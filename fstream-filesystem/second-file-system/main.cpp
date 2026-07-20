#include <iostream>
#include <fstream>
#include <string>

void textForFile(std::string& text);
void fileWrite(const std::string& text);
void fileRead();

int main() {
    std::string text{};

    textForFile(text);
    fileWrite(text);
    fileRead();
    return 0;
}

void textForFile(std::string& text) {
    std::cout << "Enter text:\n> ";
    std::getline(std::cin, text);
}

void fileWrite(const std::string& text) {
    std::ofstream outFile("text.txt");

    if (outFile.is_open()) {
        outFile << text;
        std::cout << "Successfuly writen to file";
    } else {
        std::cerr << "Error";
    }
}

void fileRead() {
    std::ifstream inFile("text.txt");
    std::string line{};

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
    }
}
